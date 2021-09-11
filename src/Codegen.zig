const std = @import("std");
const Compilation = @import("Compilation.zig");
const Source = @import("Source.zig");
const Tree = @import("Tree.zig");
const NodeIndex = Tree.NodeIndex;
const x86_64 = @import("codegen/x86_64.zig");

const Codegen = @This();

comp: *Compilation,
text: std.ArrayList(u8),
rodata: std.ArrayList(u8),

pub const Error = Compilation.Error || error{CodegenFailed};

pub fn generateTree(comp: *Compilation, tree: Tree) Compilation.Error!void {
    var c = Codegen{
        .comp = comp,
        .text = std.ArrayList(u8).init(comp.gpa),
        .rodata = std.ArrayList(u8).init(comp.gpa),
    };
    defer {
        c.text.deinit();
        c.rodata.deinit();
    }

    const node_tags = tree.nodes.items(.tag);
    for (tree.root_decls) |decl| {
        switch (node_tags[@enumToInt(decl)]) {
            // these produce no code
            .static_assert, .typedef => {},

            // no work needed
            .fn_proto,
            .static_fn_proto,
            .inline_fn_proto,
            .inline_static_fn_proto,
            .noreturn_fn_proto,
            .noreturn_static_fn_proto,
            .noreturn_inline_fn_proto,
            .noreturn_inline_static_fn_proto,
            .extern_var,
            .threadlocal_extern_var,
            => {},

            // function definition
            .fn_def,
            .static_fn_def,
            .inline_fn_def,
            .inline_static_fn_def,
            .noreturn_fn_def,
            .noreturn_static_fn_def,
            .noreturn_inline_fn_def,
            .noreturn_inline_static_fn_def,
            => c.genFn() catch |err| switch (err) {
                error.FatalError => return error.FatalError,
                error.OutOfMemory => return error.OutOfMemory,
                error.CodegenFailed => continue,
            },

            .@"var",
            .static_var,
            .threadlocal_var,
            .threadlocal_static_var,
            => c.genVar() catch |err| switch (err) {
                error.FatalError => return error.FatalError,
                error.OutOfMemory => return error.OutOfMemory,
                error.CodegenFailed => continue,
            },

            else => unreachable,
        }
    }
}

fn genFn(c: *Codegen) Error!void {
    switch (c.comp.target.cpu.arch) {
        .x86_64 => try x86_64.genFn(c),
        else => return c.comp.diag.fatalNoSrc("implement genFn for target {}\n", .{c.comp.target.cpu.arch}),
    }
}

fn genVar(c: *Codegen) Error!void {
    switch (c.comp.target.cpu.arch) {
        .x86_64 => try x86_64.genVar(c),
        else => return c.comp.diag.fatalNoSrc("implement genVar for target {}\n", .{c.comp.target.cpu.arch}),
    }
}
