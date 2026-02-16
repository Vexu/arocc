const std = @import("std");
const Build = std.Build;

const aro_version = std.SemanticVersion.parse(@import("build.zig.zon").version) catch unreachable;

fn generateDef(b: *Build, input_name: []const u8) Build.Module.Import {
    const cache = struct {
        var exe: ?*Build.Step.Compile = null;
    };
    const exe = cache.exe orelse b.addExecutable(.{
        .name = "generate-def",
        .root_module = b.createModule(.{
            .root_source_file = b.path("build/generate_def.zig"),
            .target = b.graph.host,
            .single_threaded = true,
        }),
    });
    cache.exe = exe;

    const input_path = b.pathJoin(&.{ "src/aro", input_name });
    const output_name = b.fmt("{s}.zig", .{std.fs.path.stem(input_name)});

    const run_step = b.addRunArtifact(exe);
    run_step.addFileArg(b.path(input_path));
    const output_file = run_step.addOutputFileArg(output_name);

    return .{
        .module = b.createModule(.{
            .root_source_file = output_file,
        }),
        .name = input_name,
    };
}

fn addFuzzStep(b: *Build, target: std.Build.ResolvedTarget, afl_clang_lto_path: []const u8, aro_module: *std.Build.Module) !void {
    const fuzz_step = b.step("fuzz", "Build executable for fuzz testing.");
    const fuzz_lib = b.addLibrary(.{
        .name = "fuzz-lib",
        .root_module = b.createModule(.{
            .root_source_file = b.path("test/fuzz/fuzz_lib.zig"),
            .optimize = .Debug,
            .target = target,
            .single_threaded = true,
        }),
        .use_llvm = true,
        .use_lld = true,
    });
    fuzz_lib.lto = .full;
    fuzz_lib.bundle_compiler_rt = true;
    fuzz_lib.pie = true;

    fuzz_lib.root_module.addImport("aro", aro_module);
    const fuzz_compile = b.addSystemCommand(&.{afl_clang_lto_path});
    fuzz_compile.addFileArg(b.path("test/fuzz/main.c"));
    fuzz_compile.addArg("-o");
    const fuzz_exe = fuzz_compile.addOutputFileArg("arofuzz");
    const fuzz_install = b.addInstallBinFile(fuzz_exe, "arofuzz");

    fuzz_compile.addArtifactArg(fuzz_lib);
    fuzz_step.dependOn(&fuzz_install.step);
}

pub fn build(b: *Build) !void {
    // Standard target options allows the person running `zig build` to choose
    // what target to build for. Here we do not override the defaults, which
    // means any target is allowed, and the default is native. Other options
    // for restricting supported target set are available.
    const target = b.standardTargetOptions(.{});

    // Standard release options allow the person running `zig build` to select
    // between Debug, ReleaseSafe, ReleaseFast, and ReleaseSmall.
    const mode = b.standardOptimizeOption(.{});

    const afl_clang_lto_path = b.option([]const u8, "afl-clang-lto-path", "Path to afl-clang-lto") orelse "afl-clang-lto";
    const enable_linker_build_id = b.option(bool, "enable-linker-build-id", "pass --build-id to linker") orelse false;
    const default_linker = b.option([]const u8, "default-linker", "Default linker aro will use if none is supplied via -fuse-ld") orelse "ld";
    const default_sysroot = b.option([]const u8, "default-sysroot", "Default <path> to all compiler invocations for --sysroot=<path>.") orelse "";
    const gcc_install_prefix = b.option([]const u8, "gcc-install-prefix", "Directory where gcc is installed.") orelse "";
    const default_rtlib = b.option([]const u8, "default-rtlib", "Default compiler runtime library if --rtlib is not specified") orelse "";
    const default_unwindlib = b.option([]const u8, "default-unwindlib", "Default unwind library to use (\"none\" \"libgcc\" or \"libunwind\", empty to match runtime library.)") orelse
        if (std.mem.eql(u8, default_rtlib, "libgcc")) "libgcc" else "";
    const link_libc = b.option(bool, "link-libc", "Force self-hosted compiler to link libc") orelse (mode != .Debug);
    const tracy = b.option([]const u8, "tracy", "Enable Tracy integration. Supply path to Tracy source");
    const tracy_callstack = b.option(bool, "tracy-callstack", "Include callstack information with Tracy data. Does nothing if -Dtracy is not provided") orelse false;
    const tracy_allocation = b.option(bool, "tracy-allocation", "Include allocation information with Tracy data. Does nothing if -Dtracy is not provided") orelse false;
    const use_llvm = b.option(bool, "llvm", "Use LLVM backend to generate aro executable");
    const no_bin = b.option(bool, "no-bin", "skip emitting compiler binary") orelse false;
    const test_filter = b.option([]const []const u8, "test-filter", "Test filter for unit tests") orelse &.{};
    const debug_allocations = b.option(bool, "debug-allocations", "Collect detailed debug info for all allocations (slow)") orelse false;

    const system_defaults = b.addOptions();
    system_defaults.addOption(bool, "enable_linker_build_id", enable_linker_build_id);
    system_defaults.addOption([]const u8, "linker", default_linker);
    system_defaults.addOption([]const u8, "sysroot", default_sysroot);
    system_defaults.addOption([]const u8, "gcc_install_prefix", gcc_install_prefix);
    system_defaults.addOption([]const u8, "rtlib", default_rtlib);
    system_defaults.addOption([]const u8, "unwindlib", default_unwindlib);

    const aro_options = b.addOptions();
    aro_options.addOption(bool, "enable_tracy", tracy != null);
    aro_options.addOption(bool, "enable_tracy_callstack", tracy_callstack);
    aro_options.addOption(bool, "enable_tracy_allocation", tracy_allocation);
    aro_options.addOption(bool, "debug_allocations", debug_allocations);

    const version_str = v: {
        const version_string = b.fmt("{d}.{d}.{d}", .{ aro_version.major, aro_version.minor, aro_version.patch });

        // TODO detect when Aro is being used as a dependency.
        // https://github.com/Vexu/arocc/issues/965
        if (true) break :v version_string;

        var code: u8 = undefined;
        const git_describe_untrimmed = b.runAllowFail(&[_][]const u8{
            "git", "-C", b.build_root.path orelse ".", "describe", "--match", "*.*.*", "--tags",
        }, &code, .ignore) catch version_string;
        const git_describe = std.mem.trim(u8, git_describe_untrimmed, " \n\r");

        switch (std.mem.count(u8, git_describe, "-")) {
            0 => {
                // Tagged release version (e.g. 0.10.0).
                if (!std.mem.eql(u8, git_describe, version_string)) {
                    std.debug.print("Aro version '{s}' does not match Git tag '{s}'\n", .{ version_string, git_describe });
                    std.process.exit(1);
                }
                break :v version_string;
            },
            2 => {
                // Untagged development build (e.g. 0.10.0-dev.2025+ecf0050a9).
                var it = std.mem.splitScalar(u8, git_describe, '-');
                const tagged_ancestor = it.first();
                const commit_height = it.next().?;
                const commit_id = it.next().?;

                const ancestor_ver = try std.SemanticVersion.parse(tagged_ancestor);
                if (!aro_version.order(ancestor_ver).compare(.gte)) {
                    std.debug.print("Aro version '{f}' must be greater than tagged ancestor '{f}'\n", .{ aro_version, ancestor_ver });
                    std.process.exit(1);
                }

                // Check that the commit hash is prefixed with a 'g' (a Git convention).
                if (commit_id.len < 1 or commit_id[0] != 'g') {
                    std.debug.print("Unexpected `git describe` output: {s}\n", .{git_describe});
                    break :v version_string;
                }

                // The version is reformatted in accordance with the https://semver.org specification.
                break :v b.fmt("{s}-dev.{s}+{s}", .{ version_string, commit_height, commit_id[1..] });
            },
            else => {
                std.debug.print("Unexpected `git describe` output: {s}\n", .{git_describe});
                break :v version_string;
            },
        }
    };
    aro_options.addOption([]const u8, "version_str", version_str);
    const aro_options_module = aro_options.createModule();

    const zig_module = b.createModule(.{
        .root_source_file = b.path("deps/zig/lib.zig"),
    });
    const aro_backend = b.addModule("aro_backend", .{
        .root_source_file = b.path("src/backend.zig"),
        .imports = &.{
            .{
                .name = "zig",
                .module = zig_module,
            },
            .{
                .name = "build_options",
                .module = aro_options_module,
            },
        },
    });
    const aro_module = b.addModule("aro", .{
        .root_source_file = b.path("src/aro.zig"),
        .imports = &.{
            .{
                .name = "system_defaults",
                .module = system_defaults.createModule(),
            },
            .{
                .name = "build_options",
                .module = aro_options_module,
            },
            .{
                .name = "backend",
                .module = aro_backend,
            },
            generateDef(b, "Builtins/aarch64.def"),
            generateDef(b, "Builtins/amdgcn.def"),
            generateDef(b, "Builtins/arm.def"),
            generateDef(b, "Builtins/bpf.def"),
            generateDef(b, "Builtins/common.def"),
            generateDef(b, "Builtins/hexagon.def"),
            generateDef(b, "Builtins/loongarch.def"),
            generateDef(b, "Builtins/mips.def"),
            generateDef(b, "Builtins/nvptx.def"),
            generateDef(b, "Builtins/powerpc.def"),
            generateDef(b, "Builtins/riscv.def"),
            generateDef(b, "Builtins/s390x.def"),
            generateDef(b, "Builtins/ve.def"),
            generateDef(b, "Builtins/x86_64.def"),
            generateDef(b, "Builtins/x86.def"),
            generateDef(b, "Builtins/xcore.def"),
            generateDef(b, "Attribute/names.def"),
        },
    });
    const assembly_backend = b.addModule("assembly_backend", .{
        .root_source_file = b.path("src/assembly_backend.zig"),
        .imports = &.{
            .{
                .name = "aro",
                .module = aro_module,
            },
        },
    });

    b.installDirectory(.{
        .source_dir = b.path("include"),
        .install_dir = .prefix,
        .install_subdir = "include",
    });

    const exe = b.addExecutable(.{
        .name = "arocc",
        .root_module = b.createModule(.{
            .root_source_file = b.path("src/main.zig"),
            .optimize = mode,
            .target = target,
            .single_threaded = true,
        }),
        .use_llvm = use_llvm,
        .use_lld = use_llvm,
    });
    exe.root_module.addImport("aro", aro_module);
    exe.root_module.addImport("assembly_backend", assembly_backend);
    exe.root_module.addImport("build_options", aro_options_module);

    if (target.result.os.tag == .windows) {
        exe.root_module.linkSystemLibrary("advapi32", .{});
    }

    b.step("run", "Run arocc").dependOn(step: {
        const run_cmd = b.addRunArtifact(exe);
        run_cmd.step.dependOn(b.getInstallStep());
        if (b.args) |args| {
            run_cmd.addArgs(args);
        }
        break :step &run_cmd.step;
    });

    const fmt_dirs: []const []const u8 = &.{ "build", "build.zig", "src", "test" };

    b.step("fmt", "Modify source files in place to have conforming formatting")
        .dependOn(&b.addFmt(.{ .paths = fmt_dirs }).step);

    const test_fmt_step = b.step("test-fmt", "Check source files having conforming formatting");
    test_fmt_step.dependOn(&b.addFmt(.{ .paths = fmt_dirs, .check = true }).step);

    // tracy integration
    if (tracy) |tracy_path| {
        const client_cpp = std.fs.path.join(
            b.allocator,
            &[_][]const u8{ tracy_path, "TracyClient.cpp" },
        ) catch unreachable;

        // On mingw, we need to opt into windows 7+ to get some features required by tracy.
        const tracy_c_flags: []const []const u8 = if (target.result.isMinGW())
            &[_][]const u8{ "-DTRACY_ENABLE=1", "-fno-sanitize=undefined", "-D_WIN32_WINNT=0x601" }
        else
            &[_][]const u8{ "-DTRACY_ENABLE=1", "-fno-sanitize=undefined" };

        exe.root_module.addIncludePath(b.path(tracy_path));
        exe.root_module.addCSourceFile(.{ .file = b.path(client_cpp), .flags = tracy_c_flags });
        exe.root_module.link_libcpp = true;
        exe.root_module.link_libc = true;

        if (target.result.os.tag == .windows) {
            exe.root_module.linkSystemLibrary("dbghelp", .{});
            exe.root_module.linkSystemLibrary("ws2_32", .{});
        }
    }
    if (link_libc) {
        exe.root_module.link_libc = true;
    }

    if (no_bin) {
        b.getInstallStep().dependOn(&exe.step);
    } else {
        b.installArtifact(exe);
    }

    const unit_tests_step = step: {
        var unit_tests = b.addTest(.{
            .root_module = b.createModule(.{
                .target = target,
                .root_source_file = b.path("src/aro.zig"),
            }),
            .filters = test_filter,
        });
        for (aro_module.import_table.keys(), aro_module.import_table.values()) |name, module| {
            unit_tests.root_module.addImport(name, module);
        }
        const run_test = b.addRunArtifact(unit_tests);

        const unit_tests_step = b.step("test-unit", "Run unit tests");
        unit_tests_step.dependOn(&run_test.step);
        break :step unit_tests_step;
    };

    const integration_tests_step = step: {
        const integration_tests = b.addExecutable(.{
            .name = "test-runner",
            .root_module = b.createModule(.{
                .root_source_file = b.path("test/runner.zig"),
                .target = b.graph.host,
            }),
        });
        const integration_test_runner = b.addRunArtifact(integration_tests);
        integration_test_runner.addArtifactArg(exe);
        integration_test_runner.addDirectoryArg(b.path("test/cases"));

        const integration_tests_step = b.step("test-integration", "Run integration tests");
        integration_tests_step.dependOn(&integration_test_runner.step);
        break :step integration_tests_step;
    };

    const record_tests_step = step: {
        const record_tests = b.addExecutable(.{
            .name = "record-runner",
            .root_module = b.createModule(.{
                .root_source_file = b.path("test/record_runner.zig"),
                .target = b.graph.host,
            }),
        });
        record_tests.root_module.addImport("aro", aro_module);
        const record_tests_runner = b.addRunArtifact(record_tests);
        record_tests_runner.addArtifactArg(exe);

        const record_tests_step = b.step("test-record", "Run record layout tests");
        record_tests_step.dependOn(&record_tests_runner.step);
        break :step record_tests_step;
    };

    const tests_step = b.step("test", "Run all tests");
    tests_step.dependOn(test_fmt_step);
    tests_step.dependOn(unit_tests_step);
    tests_step.dependOn(integration_tests_step);
    tests_step.dependOn(record_tests_step);

    try addFuzzStep(b, target, afl_clang_lto_path, aro_module);
}
