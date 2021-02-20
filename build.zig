const std = @import("std");
const Builder = std.build.Builder;

const version = std.SemanticVersion{
    .major = 0,
    .minor = 0,
    .patch = 0,
    .pre = "dev",
};

pub fn build(b: *Builder) void {
    // Standard target options allows the person running `zig build` to choose
    // what target to build for. Here we do not override the defaults, which
    // means any target is allowed, and the default is native. Other options
    // for restricting supported target set are available.
    const target = b.standardTargetOptions(.{});

    // Standard release options allow the person running `zig build` to select
    // between Debug, ReleaseSafe, ReleaseFast, and ReleaseSmall.
    const mode = b.standardReleaseOptions();

    const exe = b.addExecutable("sfcc", "src/main.zig");
    exe.addBuildOption(std.SemanticVersion, "version", version);
    exe.addBuildOption([]const u8, "version_str", std.fmt.allocPrint(b.allocator, "{}", .{version}) catch unreachable);
    exe.setTarget(target);
    exe.setBuildMode(mode);
    exe.install();

    const run_cmd = exe.run();
    run_cmd.step.dependOn(b.getInstallStep());
    if (b.args) |args| {
        run_cmd.addArgs(args);
    }

    const run_step = b.step("run", "Run the app");
    run_step.dependOn(&run_cmd.step);

    addTests(b, .{
        "src/main.zig",
        "test/preprocessor.zig",
    });
}

fn addTests(b: *Builder, tests: anytype) void {
    const tests_step = b.step("test", "Run all tests");
    inline for (tests) |t| {
        var test_step = b.addTest(t);
        test_step.addPackagePath("sfcc", "src/lib.zig");
        tests_step.dependOn(&test_step.step);
    }
}
