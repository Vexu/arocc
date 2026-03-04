const Toolchain = @import("../Toolchain.zig");

const std = @import("std");
const path = std.Io.Dir.path;

const Sdk = enum {
    driverkit,
    iphoneos,
    iphonesimulator,
    macosx,
    appletvos,
    appletvsimulator,
    xros,
    xrsimulator,
    watchos,
    watchsimulator,
};

const Darwin = @This();

sdk: Sdk,
sdk_path: ?[]const u8,

pub fn discover(tc: *Toolchain) !Darwin {
    const gpa = tc.driver.comp.gpa;
    const arena = tc.driver.comp.arena;
    const target = tc.driver.comp.target;

    const sdk: Sdk = switch (target.os.tag) {
        .driverkit => .driverkit,
        .ios => if (target.abi == .simulator) .iphonesimulator else .iphoneos,
        .maccatalyst => unreachable, // TODO
        .macos => .macosx,
        .tvos => if (target.abi == .simulator) .appletvsimulator else .appletvos,
        .watchos => if (target.abi == .simulator) .watchsimulator else .watchos,
        else => {
            std.debug.assert(!target.os.tag.isDarwin());
            unreachable;
        },
    };

    const sdk_path: ?[]const u8 = xcrunShowSdkPath(gpa, tc.driver.comp.io, sdk) catch |err| sdk_path: {
        try tc.driver.warn("unable to get {} SDK path from `xcrun`: {}", .{
            @tagName(sdk), @errorName(err),
        });
        break :sdk_path null;
    };

    if (sdk_path) |p| {
        try tc.addPathIfExists(&.{ p, "usr", "lib" }, .file);
        try tc.addSystemIncludeDir(try path.join(arena, &.{ p, "usr", "include" }));
    }

    return .{
        .sdk = sdk,
        .sdk_path = sdk_path,
    };
}

fn xcrunShowSdkPath(gpa: std.mem.Allocator, io: std.Io, sdk: Sdk) ![]const u8 {
    var child = try std.process.spawn(io, .{
        .argv = &.{ "xcrun", "--sdk", @tagName(sdk), "--show-sdk-path" },
        .stdout = .pipe,
    });
    defer child.kill(io);

    var stack_fallback = std.heap.stackFallback(128, gpa);
    const sfa = stack_fallback.get();

    var stdout_reader = child.stdout.?.readerStreaming(io, &.{});
    const stdout = try stdout_reader.interface.allocRemaining(gpa, .unlimited);
    defer sfa.free(stdout);

    const term = try child.wait(io);
    if (term != .exited or term.exited != 0) return error.XcrunFailed;

    const sdk_path: []const u8 = std.mem.sliceTo(stdout, '\n');

    const cwd = std.Io.Dir.cwd();
    try cwd.access(io, sdk_path, .{});

    return gpa.dupe(u8, sdk_path);
}

pub fn deinit(self: *Darwin, gpa: std.mem.Allocator) void {
    _ = .{ self, gpa };
}

pub fn defineSystemIncludes(self: *Darwin, tc: *Toolchain) !void {
    _ = .{ self, tc };
}
