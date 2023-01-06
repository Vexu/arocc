const std = @import("std");
const mem = std.mem;
const Allocator = mem.Allocator;
const process = std.process;
const Compilation = @import("Compilation.zig");
const Driver = @import("Driver.zig");
const target = @import("target.zig");

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

    var comp = Compilation.init(gpa);
    defer comp.deinit();

    comp.addDefaultPragmaHandlers() catch |er| switch (er) {
        error.OutOfMemory => {
            std.debug.print("out of memory\n", .{});
            if (fast_exit) std.process.exit(1);
            return 1;
        },
    };
    comp.langopts.setEmulatedCompiler(target.systemCompiler(comp.target));

    var driver: Driver = .{ .comp = &comp };
    defer driver.deinit();

    driver.main(args) catch |er| switch (er) {
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
    };
    if (fast_exit) std.process.exit(@boolToInt(comp.diag.errors != 0));
    return @boolToInt(comp.diag.errors != 0);
}

test {
    _ = @import("Builtins.zig");
    _ = @import("Codegen_legacy.zig");
    _ = @import("Compilation.zig");
    _ = @import("Diagnostics.zig");
    _ = @import("InitList.zig");
    _ = @import("LangOpts.zig");
    _ = @import("Parser.zig");
    _ = @import("Pragma.zig");
    _ = @import("Preprocessor.zig");
    _ = @import("Source.zig");
    _ = @import("Tokenizer.zig");
    _ = @import("Tree.zig");
    _ = @import("Type.zig");
    _ = @import("target.zig");
}
