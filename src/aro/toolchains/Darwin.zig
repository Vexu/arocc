const Target = @import("../Target.zig");
const Toolchain = @import("../Toolchain.zig");

const std = @import("std");
const builtin = @import("builtin");

const Darwin = @This();

sdk: Sdk,
sdk_path: ?[]const u8 = null,

pub fn defineSystemIncludes(self: *Darwin, tc: *Toolchain) !void {
    if (tc.driver.nostdinc) return;

    if (!tc.driver.nostdlibinc) {
        if (tc.driver.sysroot) |sysroot| {
            self.sdk_path = sysroot;
        } else if (builtin.target.os.tag.isDarwin()) {
            self.sdk_path = try self.sdk.xcrun(tc, "--show-sdk-path");
        } else {
            std.debug.assert(tc.getTarget().os.tag.isDarwin());
            try tc.driver.diagnostics.add(.{ .kind = .note, .text = "--sysroot may be required when cross-compiling to Darwin targets", .location = null });
        }

        try tc.addSystemIncludeDirJoined(&.{ "usr", "local", "include" });
    }

    if (self.sdk_path) |sdk| try tc.addSystemIncludeDirJoined(&.{ sdk, "usr", "local", "include" });
    if (!tc.driver.nobuiltininc) try tc.addBuiltinIncludeDir();

    if (self.sdk_path) |sdk| try tc.addSystemIncludeDirJoined(&.{ sdk, "usr", "include" });
}

const Sdk = union(enum) {
    driverkit,
    iphoneos,
    iphonesimulator,
    macosx: packed struct { catalyst: bool },
    appletvos,
    appletvsimulator,
    xros,
    xrsimulator,
    watchos,
    watchsimulator,

    pub fn fromTarget(target: Target) Sdk {
        return switch (target.os.tag) {
            .driverkit => .driverkit,
            .ios => if (target.abi == .simulator) .iphonesimulator else .iphoneos,
            .maccatalyst => .{ .macosx = .{ .catalyst = true } },
            .macos => .{ .macosx = .{ .catalyst = false } },
            .tvos => if (target.abi == .simulator) .appletvsimulator else .appletvos,
            .watchos => if (target.abi == .simulator) .watchsimulator else .watchos,
            else => {
                std.debug.assert(!target.os.tag.isDarwin());
                unreachable;
            },
        };
    }

    fn xcrun(sdk: Sdk, tc: *Toolchain, arg: []const u8) !?[]const u8 {
        const arena = tc.driver.comp.arena;
        const gpa = tc.driver.comp.gpa;

        var pretty_cmd_buf: [128]u8 = undefined;
        var pretty_cmd_writer = std.Io.Writer.fixed(&pretty_cmd_buf);
        pretty_cmd_writer.print("`xcrun --sdk {t} {s}`", .{ sdk, arg }) catch unreachable;
        const pretty_cmd = pretty_cmd_writer.buffered();

        const result = std.process.run(tc.driver.comp.gpa, tc.driver.comp.io, .{
            .argv = &.{ "xcrun", "--sdk", @tagName(sdk), arg },
        }) catch |err| {
            try tc.driver.err("{s} failed to run: {s}", .{ pretty_cmd, @errorName(err) });
            return null;
        };
        defer gpa.free(result.stderr);
        defer gpa.free(result.stdout);

        if (result.term != .exited) {
            var aw = std.Io.Writer.Allocating.init(gpa);
            defer aw.deinit();
            aw.writer.print("{any}", .{result.term}) catch return error.OutOfMemory;
            try tc.driver.err("{s} stopped unexpectedly: {}\n{s}", .{ pretty_cmd, aw.writer.buffered(), result.stderr });
            return null;
        } else if (result.term.exited != 0) {
            var aw = std.Io.Writer.Allocating.init(gpa);
            defer aw.deinit();
            aw.writer.print("{any}", .{result.term.exited}) catch return error.OutOfMemory;
            try tc.driver.err("{s} exited with exit code {d}\n{s}", .{ pretty_cmd, aw.writer.buffered(), result.stderr });
            return null;
        } else if (result.stderr.len > 0) {
            try tc.driver.err("{s} stderr:\n{s}", .{ pretty_cmd, result.stderr });
        }

        const nl = std.mem.indexOfScalar(u8, result.stdout, '\n');
        if (nl == null or nl.? == 0) {
            try tc.driver.err("{s} had no output", .{pretty_cmd});
            return null;
        }

        if (result.stdout[nl.? + 1 ..].len > 0) {
            try tc.driver.err("{s} had unexpected output:\n{s}", .{ pretty_cmd, result.stdout });
            return null;
        }

        const path = result.stdout[0..nl.?];

        if (!tc.exists(path)) {
            try tc.driver.err("{s} returned non-existent path '{s}'", .{ pretty_cmd, path });
        }

        return try arena.dupe(u8, path);
    }
};
