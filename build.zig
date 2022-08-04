const std = @import("std");
const Builder = std.build.Builder;

fn addFuzzStep(b: *Builder, target: std.zig.CrossTarget) !void {
    const fuzz_lib = b.addStaticLibrary("fuzz-lib", "test/fuzz/fuzz_lib.zig");
    fuzz_lib.addPackagePath("aro", "src/lib.zig");
    fuzz_lib.setTarget(target);
    fuzz_lib.setBuildMode(.Debug);
    fuzz_lib.want_lto = true;
    fuzz_lib.bundle_compiler_rt = true;

    const fuzz_executable_name = "fuzz";
    const fuzz_exe_path = try std.fs.path.join(b.allocator, &.{ b.cache_root, fuzz_executable_name });

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

pub fn build(b: *Builder) !void {
    // Standard target options allows the person running `zig build` to choose
    // what target to build for. Here we do not override the defaults, which
    // means any target is allowed, and the default is native. Other options
    // for restricting supported target set are available.
    const target = b.standardTargetOptions(.{});

    // Standard release options allow the person running `zig build` to select
    // between Debug, ReleaseSafe, ReleaseFast, and ReleaseSmall.
    const mode = b.standardReleaseOptions();

    const test_all_allocation_failures = b.option(bool, "test-all-allocation-failures", "Test all allocation failures") orelse false;
    const link_libc = b.option(bool, "link-libc", "Force self-hosted compiler to link libc") orelse (mode != .Debug);
    const tracy = b.option([]const u8, "tracy", "Enable Tracy integration. Supply path to Tracy source");
    const tracy_callstack = b.option(bool, "tracy-callstack", "Include callstack information with Tracy data. Does nothing if -Dtracy is not provided") orelse false;
    const tracy_allocation = b.option(bool, "tracy-allocation", "Include allocation information with Tracy data. Does nothing if -Dtracy is not provided") orelse false;

    const zig_pkg = std.build.Pkg{
        .name = "zig",
        .source = .{ .path = "deps/zig/lib.zig" },
    };

    const exe = b.addExecutable("arocc", "src/main.zig");
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

        exe.addIncludePath(tracy_path);
        exe.addCSourceFile(client_cpp, tracy_c_flags);
        exe.linkLibCpp();
        exe.linkLibC();

        if (target.isWindows()) {
            exe.linkSystemLibrary("dbghelp");
            exe.linkSystemLibrary("ws2_32");
        }
    }
    exe.setTarget(target);
    exe.setBuildMode(mode);
    exe.addPackage(zig_pkg);
    if (link_libc) {
        exe.linkLibC();
    }
    exe.install();

    const run_cmd = exe.run();
    run_cmd.expected_exit_code = null;
    run_cmd.step.dependOn(b.getInstallStep());
    if (b.args) |args| {
        run_cmd.addArgs(args);
    }

    const run_step = b.step("run", "Run the app");
    run_step.dependOn(&run_cmd.step);

    const tests_step = b.step("test", "Run all tests");
    tests_step.dependOn(&exe.step);

    var unit_tests = b.addTest("src/main.zig");
    unit_tests.addPackage(zig_pkg);
    tests_step.dependOn(&unit_tests.step);

    const integration_tests = b.addExecutable("arocc", "test/runner.zig");
    integration_tests.addPackage(.{
        .name = "aro",
        .source = .{ .path = "src/lib.zig" },
        .dependencies = &.{zig_pkg},
    });
    const test_runner_options = b.addOptions();
    integration_tests.addOptions("build_options", test_runner_options);
    test_runner_options.addOption(bool, "test_all_allocation_failures", test_all_allocation_failures);

    const integration_test_runner = integration_tests.run();
    integration_test_runner.addArg(b.pathFromRoot("test/cases"));
    integration_test_runner.addArg(b.zig_exe);

    const record_tests = b.addExecutable("arocc", "test/record_runner.zig");
    record_tests.addPackage(.{
        .name = "aro",
        .source = .{ .path = "src/lib.zig" },
        .dependencies = &.{zig_pkg},
    });
    const record_tests_runner = record_tests.run();
    record_tests_runner.addArg(b.pathFromRoot("test/records"));
    record_tests_runner.addArg(b.zig_exe);

    tests_step.dependOn(&integration_test_runner.step);
    tests_step.dependOn(&record_tests_runner.step);

    try addFuzzStep(b, target);
}
