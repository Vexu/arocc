const Target = @import("../Target.zig");
const Toolchain = @import("../Toolchain.zig");

const std = @import("std");
const builtin = @import("builtin");

const Darwin = @This();

sdk: Sdk,
sdk_path: ?[]const u8 = null,

pub fn discover(darwin: *Darwin, tc: *Toolchain) !void {
    if (tc.driver.sysroot) |sysroot| {
        darwin.sdk_path = sysroot;
    } else if (builtin.target.os.tag.isDarwin()) {
        try tc.driver.diagnostics.add(.{ .kind = .note, .text = "--sysroot may be required when cross-compiling to Darwin targets", .location = null });
    } else {
        darwin.sdk_path = try darwin.sdk.xcrun(tc, "--show-sdk-path");
    }
}

// clang args (via --verbose):
// -resource-dir <toolchain-path>/usr/lib/clang/21
// -isysroot <sdk-path>
// -I/usr/local/include
// -internal-isystem <sdk-path>/usr/local/include
// -internal-isystem <toolchain-path>/usr/lib/clang/21/include
// -internal-externc-isystem <sdk-path>/usr/include
// -internal-externc-isystem <toolchain-path>/usr/include
// -internal-iframework <sdk-path>/System/Library/Frameworks
// -internal-iframework <sdk-path>/System/Library/SubFrameworks
// -internal-iframework <sdk-path>/Library/Frameworks
//
// clang messages (via -E):
// ignoring nonexistent directory "/usr/local/include"
// ignoring nonexistent directory "<sdk-path>/usr/local/include"
// ignoring nonexistent directory "<sdk-path>/Library/Frameworks"
// #include "..." search starts here:
// #include <...> search starts here:
//  <toolchain-path>/usr/lib/clang/21/include
//  <sdk-path>/usr/include
//  <toolchain-path>/usr/include
//  <sdk-path>/System/Library/Frameworks (framework directory)
//  <sdk-path>/System/Library/SubFrameworks (framework directory)
pub fn defineSystemIncludes(self: *Darwin, tc: *Toolchain) !void {
    if (tc.driver.nostdinc) return;

    var effective = self.*;
    if (tc.driver.nostdlibinc) {
        effective = .{ .sdk = self.sdk };
    } else {
        // -I/usr/local/include
        try tc.addPathIfExists(&.{ "usr", "local", "include" }, .file);
    }

    // -internal-isystem <sdk-path>/usr/local/include
    if (effective.sdk_path) |sdk| try tc.addPathIfExists(&.{ sdk, "usr", "local", "include" }, .file);
    // -internal-isystem <toolchain-path>/usr/lib/clang/21/include but aro
    if (!tc.driver.nobuiltininc) try tc.addBuiltinIncludeDir();

    // -internal-externc-isystem <sdk-path>/usr/include
    if (effective.sdk_path) |sdk| try tc.addPathIfExists(&.{ sdk, "usr", "include" }, .file);
    // <toolchain-path>/usr/include is unnecessary - it's FlexLexer.h, libcodedirectory.h, and swift bridging
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
};
