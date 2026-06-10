const Target = @import("../Target.zig");
const Toolchain = @import("../Toolchain.zig");

const std = @import("std");
const builtin = @import("builtin");

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

    fn fromTarget(target: Target) Sdk {
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
};

const Darwin = @This();

sdk: Sdk,
sdk_path: ?[]const u8,
// toolchain_path: ?[]const u8,

pub fn discover(tc: *Toolchain) Toolchain.DiscoverError!Darwin {
    const sdk = Sdk.fromTarget(tc.getTarget().*);
    const sdk_path = tc.driver.sysroot orelse sysroot: {
        if (!builtin.target.os.tag.isDarwin()) {
            try tc.driver.diagnostics.add(.{ .kind = .note, .text = "--sysroot may be required when cross-compiling to Darwin targets", .location = null });
            break :sysroot null;
        }

        const sysroot = try xcrun(tc, sdk, "--show-sdk-path");
        tc.driver.sysroot = sysroot;
        break :sysroot sysroot;
    };

    return .{
        .sdk = sdk,
        .sdk_path = sdk_path,
    };
}

fn xcrun(tc: *Toolchain, sdk: Sdk, arg: []const u8) Toolchain.DiscoverError!?[]const u8 {
    const arena = tc.driver.comp.arena;
    const gpa = tc.driver.comp.gpa;

    var message_writer = std.Io.Writer.Allocating.init(gpa);
    defer message_writer.deinit();
    const msg: *std.Io.Writer = &message_writer.writer;

    msg.print("`xcrun --sdk {t} {s}` ", .{ sdk, arg }) catch return error.OutOfMemory;
    const msg_reset = msg.end;

    const result = std.process.run(tc.driver.comp.gpa, tc.driver.comp.io, .{
        .argv = &.{ "xcrun", "--sdk", @tagName(sdk), arg },
    }) catch |err| {
        msg.print("failed to run: {t}", .{err}) catch return error.OutOfMemory;
        return null;
    };
    defer gpa.free(result.stderr);
    defer gpa.free(result.stdout);

    if (result.term != .exited) {
        msg.print("stopped unexpectedly: {}\n{s}", .{ result.term, result.stderr }) catch return error.OutOfMemory;
        try tc.driver.diagnostics.add(.{ .kind = .@"error", .text = try arena.dupe(u8, msg.buffered()), .location = null });
        return null;
    } else if (result.term.exited != 0) {
        msg.print("exited with exit code {d}\n{s}", .{ result.term.exited, result.stderr }) catch return error.OutOfMemory;
        try tc.driver.diagnostics.add(.{ .kind = .@"error", .text = try arena.dupe(u8, msg.buffered()), .location = null });
        return null;
    } else if (result.stderr.len > 0) {
        msg.print("stderr:\n{s}", .{result.stderr}) catch return error.OutOfMemory;
        try tc.driver.diagnostics.add(.{ .kind = .warning, .text = try arena.dupe(u8, msg.buffered()), .location = null });
        msg.end = msg_reset;
    }

    const nl = std.mem.indexOfScalar(u8, result.stdout, '\n');
    if (nl == null or nl.? == 0) {
        msg.writeAll("had no output") catch return error.OutOfMemory;
        try tc.driver.diagnostics.add(.{ .kind = .@"error", .text = "had no output", .location = null });
        return null;
    }

    if (result.stdout[nl.? + 1 ..].len > 0) {
        msg.print("had unexpected output:\n{s}", .{result.stdout}) catch return error.OutOfMemory;
        try tc.driver.diagnostics.add(.{ .kind = .@"error", .text = try arena.dupe(u8, msg.buffered()), .location = null });
        return null;
    }

    const path = result.stdout[0..nl.?];

    if (!tc.exists(path)) {
        msg.print("returned non-existent path '{s}'", .{path}) catch return error.OutOfMemory;
        try tc.driver.diagnostics.add(.{ .kind = .warning, .text = try arena.dupe(u8, msg.buffered()), .location = null });
        msg.end = msg_reset;
    }

    return try arena.dupe(u8, path);
}

pub fn defineSystemIncludes(self: *Darwin, tc: *Toolchain) !void {
    if (tc.driver.nostdinc) return;

    if (!tc.driver.nobuiltininc) {
        try tc.addBuiltinIncludeDir();
    }

    if (tc.driver.nostdlibinc) return;

    if (self.sdk_path) |sdk_path| {
        try tc.addPathIfExists(&.{ sdk_path, "usr", "include" }, .library);
        try tc.addPathIfExists(&.{ sdk_path, "usr", "lib" }, .file);
    }

    // if (self.toolchain_path) |toolchain_path| {
    //     try tc.addPathIfExists(&.{ toolchain_path, "usr", "include" }, .library);
    //     try tc.addPathIfExists(&.{ toolchain_path, "usr", "lib" }, .file);
    // }
}
