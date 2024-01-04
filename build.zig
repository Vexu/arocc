const std = @import("std");
const Build = std.Build;
const GenerateDef = @import("build/GenerateDef.zig");
const ZigLibDirStep = @import("build/ZigLibDir.zig");

const aro_version = std.SemanticVersion{
    .major = 0,
    .minor = 0,
    .patch = 0,
};

fn addFuzzStep(b: *Build, target: std.zig.CrossTarget, afl_clang_lto_path: []const u8, aro_module: *std.Build.Module) !void {
    const fuzz_step = b.step("fuzz", "Build executable for fuzz testing.");
    var fuzz_target = target;
    fuzz_target.ofmt = .c;

    const lib_dir_step = try ZigLibDirStep.create(b);

    const compiler_rt = b.createModule(.{
        .source_file = lib_dir_step.getCompilerRTPath(),
    });
    const fuzz_lib = b.addStaticLibrary(.{
        .name = "fuzz-lib",
        .root_source_file = .{ .path = "test/fuzz/fuzz_lib.zig" },
        .optimize = .Debug,
        .target = fuzz_target,
        .single_threaded = true,
    });
    fuzz_lib.addModule("compiler_rt", compiler_rt);

    fuzz_lib.addModule("aro", aro_module);
    const fuzz_compile = b.addSystemCommand(&.{
        afl_clang_lto_path,
        "-Wno-incompatible-pointer-types",
        "-nostdinc",
        "-isystem",
    });
    fuzz_compile.addDirectoryArg(lib_dir_step.getIncludePath());
    fuzz_compile.addArgs(&.{
        "-isystem",
        "/usr/include",
        "-isystem",
        "/usr/local/include",
        "-std=c99",
    });
    fuzz_compile.addFileArg(.{ .path = "test/fuzz/main.c" });
    fuzz_compile.addArg("-I");
    fuzz_compile.addDirectoryArg(lib_dir_step.getLibPath());
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
    const test_all_allocation_failures = b.option(bool, "test-all-allocation-failures", "Test all allocation failures") orelse false;
    const link_libc = b.option(bool, "link-libc", "Force self-hosted compiler to link libc") orelse (mode != .Debug);
    const tracy = b.option([]const u8, "tracy", "Enable Tracy integration. Supply path to Tracy source");
    const tracy_callstack = b.option(bool, "tracy-callstack", "Include callstack information with Tracy data. Does nothing if -Dtracy is not provided") orelse false;
    const tracy_allocation = b.option(bool, "tracy-allocation", "Include allocation information with Tracy data. Does nothing if -Dtracy is not provided") orelse false;
    const skip_record_tests = b.option(bool, "skip-record-tests", "Skip record layout tests") orelse false;
    const skip_integration_tests = b.option(bool, "skip-integration-tests", "Skip integration tests") orelse false;

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

    const version_str = v: {
        const version_string = b.fmt("{d}.{d}.{d}", .{ aro_version.major, aro_version.minor, aro_version.patch });

        var code: u8 = undefined;
        const git_describe_untrimmed = b.runAllowFail(&[_][]const u8{
            "git", "-C", b.build_root.path orelse ".", "describe", "--match", "*.*.*", "--tags",
        }, &code, .Ignore) catch version_string;
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
                    std.debug.print("Aro version '{}' must be greater than tagged ancestor '{}'\n", .{ aro_version, ancestor_ver });
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
        .source_file = .{ .path = "deps/zig/lib.zig" },
    });
    const aro_backend = b.addModule("aro_backend", .{
        .source_file = .{ .path = "src/backend.zig" },
        .dependencies = &.{
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
        .source_file = .{ .path = "src/aro.zig" },
        .dependencies = &.{
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
            GenerateDef.create(b, .{ .name = "Builtins/Builtin.def", .needs_large_dafsa_node = true }),
            GenerateDef.create(b, .{ .name = "Attribute/names.def" }),
            GenerateDef.create(b, .{ .name = "Diagnostics/messages.def", .kind = .named }),
        },
    });

    b.installDirectory(.{
        .source_dir = .{ .path = "include" },
        .install_dir = .prefix,
        .install_subdir = "include",
    });

    const exe = b.addExecutable(.{
        .name = "arocc",
        .root_source_file = .{ .path = "src/main.zig" },
        .optimize = mode,
        .target = target,
        .single_threaded = true,
    });
    exe.addModule("aro", aro_module);

    // tracy integration
    if (tracy) |tracy_path| {
        const client_cpp = std.fs.path.join(
            b.allocator,
            &[_][]const u8{ tracy_path, "TracyClient.cpp" },
        ) catch unreachable;

        // On mingw, we need to opt into windows 7+ to get some features required by tracy.
        const tracy_c_flags: []const []const u8 = if (target.isWindows() and target.getAbi() == .gnu)
            &[_][]const u8{ "-DTRACY_ENABLE=1", "-fno-sanitize=undefined", "-D_WIN32_WINNT=0x601" }
        else
            &[_][]const u8{ "-DTRACY_ENABLE=1", "-fno-sanitize=undefined" };

        exe.addIncludePath(.{ .path = tracy_path });
        exe.addCSourceFile(.{ .file = .{ .path = client_cpp }, .flags = tracy_c_flags });
        exe.linkLibCpp();
        exe.linkLibC();

        if (target.isWindows()) {
            exe.linkSystemLibrary("dbghelp");
            exe.linkSystemLibrary("ws2_32");
        }
    }
    if (link_libc) {
        exe.linkLibC();
    }
    b.installArtifact(exe);

    const tests_step = b.step("test", "Run all tests");

    var unit_tests = b.addTest(.{ .root_source_file = .{ .path = "src/aro.zig" } });
    for (aro_module.dependencies.keys(), aro_module.dependencies.values()) |name, module| {
        unit_tests.addModule(name, module);
    }
    const run_test = b.addRunArtifact(unit_tests);
    tests_step.dependOn(&run_test.step);

    const integration_tests = b.addExecutable(.{
        .name = "test-runner",
        .root_source_file = .{ .path = "test/runner.zig" },
        .optimize = mode,
    });
    integration_tests.addModule("aro", aro_module);
    const test_runner_options = b.addOptions();
    integration_tests.addOptions("build_options", test_runner_options);
    test_runner_options.addOption(bool, "test_all_allocation_failures", test_all_allocation_failures);

    const integration_test_runner = b.addRunArtifact(integration_tests);
    integration_test_runner.addArg(b.pathFromRoot("test/cases"));
    integration_test_runner.addArg(b.zig_exe);

    const record_tests = b.addExecutable(.{
        .name = "record-runner",
        .root_source_file = .{ .path = "test/record_runner.zig" },
        .optimize = mode,
    });
    record_tests.addModule("aro", aro_module);
    const record_tests_runner = b.addRunArtifact(record_tests);
    record_tests_runner.addArg(b.pathFromRoot("test/records"));

    if (!skip_integration_tests) tests_step.dependOn(&integration_test_runner.step);
    if (!skip_record_tests) tests_step.dependOn(&record_tests_runner.step);

    try addFuzzStep(b, target, afl_clang_lto_path, aro_module);
}
