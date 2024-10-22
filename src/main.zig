const std = @import("std");
const Allocator = mem.Allocator;
const mem = std.mem;
const process = std.process;
const aro = @import("aro");
const Compilation = aro.Compilation;
const Driver = aro.Driver;
const Toolchain = aro.Toolchain;

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
        if (fast_exit) process.exit(1);
        return 1;
    };

    const aro_name = std.fs.selfExePathAlloc(gpa) catch {
        std.debug.print("unable to find Aro executable path\n", .{});
        if (fast_exit) process.exit(1);
        return 1;
    };
    defer gpa.free(aro_name);

    var comp = Compilation.initDefault(gpa, std.fs.cwd()) catch |er| switch (er) {
        error.OutOfMemory => {
            std.debug.print("out of memory\n", .{});
            if (fast_exit) process.exit(1);
            return 1;
        },
    };
    defer comp.deinit();

    var driver: Driver = .{ .comp = &comp, .aro_name = aro_name };
    defer driver.deinit();

    var toolchain: Toolchain = .{ .driver = &driver, .arena = arena, .filesystem = .{ .real = comp.cwd } };
    defer toolchain.deinit();

    driver.main(&toolchain, args, fast_exit) catch |er| switch (er) {
        error.OutOfMemory => {
            std.debug.print("out of memory\n", .{});
            if (fast_exit) process.exit(1);
            return 1;
        },
        error.StreamTooLong => {
            std.debug.print("maximum file size exceeded\n", .{});
            if (fast_exit) process.exit(1);
            return 1;
        },
        error.FatalError => {
            driver.renderErrors();
            if (fast_exit) process.exit(1);
            return 1;
        },
        error.TooManyMultilibs => {
            std.debug.print("found more than one multilib with the same priority\n", .{});
            if (fast_exit) process.exit(1);
            return 1;
        },
        else => |err| return err,
    };
    if (fast_exit) process.exit(@intFromBool(comp.diagnostics.errors != 0));
    return @intFromBool(comp.diagnostics.errors != 0);
}
