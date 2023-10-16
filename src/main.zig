const std = @import("std");
const mem = std.mem;
const Allocator = mem.Allocator;
const process = std.process;
const Compilation = @import("Compilation.zig");
const Driver = @import("Driver.zig");
const target_util = @import("target.zig");
const Toolchain = @import("Toolchain.zig");

// for Builtins/Builtin.def
pub const Builtins = @import("Builtins.zig");
// for Attribute/names.def
pub const Attribute = @import("Attribute.zig");

var general_purpose_allocator = std.heap.GeneralPurposeAllocator(.{}){};

pub fn main() u8 {
    const gpa = if (@import("builtin").link_libc)
        std.heap.raw_c_allocator
    else
        general_purpose_allocator.allocator();
    defer if (!@import("builtin").link_libc) {
        _ = general_purpose_allocator.deinit();
    };

    var arena_instance = std.heap.ArenaAllocator.init(gpa);
    defer arena_instance.deinit();
    const arena = arena_instance.allocator();

    const fast_exit = @import("builtin").mode != .Debug;

    const args = process.argsAlloc(arena) catch {
        std.debug.print("out of memory\n", .{});
        if (fast_exit) std.process.exit(1);
        return 1;
    };

    const aro_name = std.fs.selfExePathAlloc(gpa) catch {
        std.debug.print("unable to find Aro executable path\n", .{});
        if (fast_exit) std.process.exit(1);
        return 1;
    };
    defer gpa.free(aro_name);

    var comp = Compilation.init(gpa);
    defer comp.deinit();

    comp.environment.loadAll(gpa) catch |er| switch (er) {
        error.OutOfMemory => {
            std.debug.print("out of memory\n", .{});
            if (fast_exit) std.process.exit(1);
            return 1;
        },
    };
    defer comp.environment.deinit(gpa);

    comp.addDefaultPragmaHandlers() catch |er| switch (er) {
        error.OutOfMemory => {
            std.debug.print("out of memory\n", .{});
            if (fast_exit) std.process.exit(1);
            return 1;
        },
    };
    comp.langopts.setEmulatedCompiler(target_util.systemCompiler(comp.target));

    var driver: Driver = .{ .comp = &comp, .aro_name = aro_name };
    defer driver.deinit();

    var toolchain: Toolchain = .{ .driver = &driver, .arena = arena };
    defer toolchain.deinit();

    driver.main(&toolchain, args) catch |er| switch (er) {
        error.OutOfMemory => {
            std.debug.print("out of memory\n", .{});
            if (fast_exit) std.process.exit(1);
            return 1;
        },
        error.StreamTooLong => {
            std.debug.print("maximum file size exceeded\n", .{});
            if (fast_exit) std.process.exit(1);
            return 1;
        },
        error.FatalError => {
            comp.renderErrors();
            if (fast_exit) std.process.exit(1);
            return 1;
        },
        error.TooManyMultilibs => {
            std.debug.print("found more than one multilib with the same priority\n", .{});
            if (fast_exit) std.process.exit(1);
            return 1;
        },
        else => |err| return err,
    };
    if (fast_exit) std.process.exit(@intFromBool(comp.diag.errors != 0));
    return @intFromBool(comp.diag.errors != 0);
}

test {
    _ = @import("Builtins.zig");
    _ = @import("Codegen_legacy.zig");
    _ = @import("Compilation.zig");
    _ = @import("Diagnostics.zig");
    _ = @import("Driver/Distro.zig");
    _ = @import("Driver/Filesystem.zig");
    _ = @import("InitList.zig");
    _ = @import("LangOpts.zig");
    _ = @import("Parser.zig");
    _ = @import("Pragma.zig");
    _ = @import("Preprocessor.zig");
    _ = @import("Source.zig");
    _ = @import("Tokenizer.zig");
    _ = @import("Driver/GCCVersion.zig");
    _ = @import("toolchains/Linux.zig");
    _ = @import("Tree.zig");
    _ = @import("Type.zig");
    _ = @import("target.zig");
}
