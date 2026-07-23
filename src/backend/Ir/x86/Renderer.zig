const std = @import("std");
const Allocator = std.mem.Allocator;
const assert = std.debug.assert;
const Interner = @import("../../Interner.zig");
const Ir = @import("../../Ir.zig");
const BaseRenderer = Ir.Renderer;

const Renderer = @This();

base: *BaseRenderer,
interner: *Interner,

pub fn render(base: *BaseRenderer) !void {
    var renderer: Renderer = .{
        .base = base,
        .interner = base.ir.interner,
    };

    for (renderer.base.ir.decls.keys(), renderer.base.ir.decls.values()) |name, decl| {
        renderer.renderFn(name, decl) catch |e| switch (e) {
            error.OutOfMemory => return e,
            error.LowerFail => continue,
        };
    }
    if (renderer.base.errors.entries.len != 0) return error.LowerFail;
}

fn renderFn(r: *Renderer, name: []const u8, decl: Ir.Decl) !void {
    _ = decl;
    return r.base.fail(name, "TODO implement lowering functions", .{});
}
