const std = @import("std");
const Build = std.Build;
const GenerateDef = @import("build/GenerateDef.zig");

fn addFuzzStep(b: *Build, target: std.zig.CrossTarget) !void {
    const fuzz_lib = b.addStaticLibrary(.{
        .name = "fuzz-lib",
        .target = target,
        .optimize = .Debug,
        .root_source_file = .{ .path = "test/fuzz/fuzz_lib.zig" },
    });
    fuzz_lib.addAnonymousModule("aro", .{ .source_file = .{ .path = "src/lib.zig" } });
    fuzz_lib.want_lto = true;
    fuzz_lib.bundle_compiler_rt = true;

    const fuzz_executable_name = "fuzz";
    const fuzz_exe_path = try b.cache_root.join(b.allocator, &.{fuzz_executable_name});

    // We want `afl-clang-lto -o path/to/output test/fuzz/main.c path/to/library`
    const fuzz_compile = b.addSystemCommand(&.{ "afl-clang-lto", "-o", fuzz_exe_path, "test/fuzz/main.c" });
    // Add the path to the library file to afl-clang-lto's args
    fuzz_compile.addArtifactArg(fuzz_lib);

    // Install the cached output to the install 'bin' path
    const fuzz_install = b.addInstallBinFile(.{ .path = fuzz_exe_path }, fuzz_executable_name);

    // Add a top-level step that compiles and installs the fuzz executable
    const fuzz_compile_run = b.step("fuzz", "Build executable for fuzz testing using afl-clang-lto");
    fuzz_compile_run.dependOn(&fuzz_compile.step);
    fuzz_compile_run.dependOn(&fuzz_install.step);
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

    const default_path_sep: u8 = if (target.isWindows()) ';' else ':';

    const enable_linker_build_id = b.option(bool, "enable-linker-build-id", "pass --build-id to linker") orelse false;
    const default_linker = b.option([]const u8, "default-linker", "Default linker aro will use if none is supplied via -fuse-ld") orelse "ld";
    const default_sysroot = b.option([]const u8, "default-sysroot", "Default <path> to all compiler invocations for --sysroot=<path>.") orelse "";
    const gcc_install_prefix = b.option([]const u8, "gcc-install-prefix", "Directory where gcc is installed.") orelse "";
    const default_rtlib = b.option([]const u8, "default-rtlib", "Default compiler runtime library if --rtlib is not specified") orelse "";
    const default_unwindlib = b.option([]const u8, "default-unwindlib", "Default unwind library to use (\"none\" \"libgcc\" or \"libunwind\", empty to match runtime library.)") orelse
        if (std.mem.eql(u8, default_rtlib, "libgcc")) "libgcc" else "";
    const test_all_allocation_failures = b.option(bool, "test-all-allocation-failures", "Test all allocation failures") orelse false;
    const link_libc = b.option(bool, "link-libc", "Force self-hosted compiler to link libc") orelse (mode != .Debug);
    const path_sep = b.option(u8, "path-sep", "Path separator in PATH environment variable") orelse default_path_sep;
    const tracy = b.option([]const u8, "tracy", "Enable Tracy integration. Supply path to Tracy source");
    const tracy_callstack = b.option(bool, "tracy-callstack", "Include callstack information with Tracy data. Does nothing if -Dtracy is not provided") orelse false;
    const tracy_allocation = b.option(bool, "tracy-allocation", "Include allocation information with Tracy data. Does nothing if -Dtracy is not provided") orelse false;
    const skip_record_tests = b.option(bool, "skip-record-tests", "Skip record layout tests") orelse false;
    const skip_integration_tests = b.option(bool, "skip-integration-tests", "Skip integration tests") orelse false;

    const system_defaults = b.addOptions();
    system_defaults.addOption(bool, "enable_linker_build_id", enable_linker_build_id);
    system_defaults.addOption([]const u8, "linker", default_linker);
    system_defaults.addOption(u8, "path_sep", path_sep);
    system_defaults.addOption([]const u8, "sysroot", default_sysroot);
    system_defaults.addOption([]const u8, "gcc_install_prefix", gcc_install_prefix);
    system_defaults.addOption([]const u8, "rtlib", default_rtlib);
    system_defaults.addOption([]const u8, "unwindlib", default_unwindlib);

    const zig_module = b.createModule(.{
        .source_file = .{ .path = "deps/zig/lib.zig" },
    });
    const aro_module = b.addModule("aro", .{
        .source_file = .{ .path = "src/lib.zig" },
        .dependencies = &.{ .{
            .name = "zig",
            .module = zig_module,
        }, .{
            .name = "system_defaults",
            .module = system_defaults.createModule(),
        } },
    });
    GenerateDef.add(b, .{
        .name = "Builtins/Builtin.def",
        .aro_module = aro_module,
    });
    GenerateDef.add(b, .{
        .name = "Attribute/names.def",
        .aro_module = aro_module,
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
    });
    exe.addModule("aro", aro_module);
    exe.addOptions("system_defaults", system_defaults);

    // tracy integration
    const exe_options = b.addOptions();
    exe.addOptions("build_options", exe_options);
    exe_options.addOption(bool, "enable_tracy", tracy != null);
    exe_options.addOption(bool, "enable_tracy_callstack", tracy_callstack);
    exe_options.addOption(bool, "enable_tracy_allocation", tracy_allocation);
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
    exe.addModule("zig", zig_module);
    if (link_libc) {
        exe.linkLibC();
    }
    b.installArtifact(exe);

    const tests_step = b.step("test", "Run all tests");

    var unit_tests = b.addTest(.{ .root_source_file = .{ .path = "src/lib.zig" } });
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

    try addFuzzStep(b, target);
}
