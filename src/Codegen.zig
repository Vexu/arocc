const std = @import("std");
const Compilation = @import("Compilation.zig");
const Tree = @import("Tree.zig");
const NodeIndex = Tree.NodeIndex;
const Object = @import("Object.zig");
const x86_64 = @import("codegen/x86_64.zig");

const Codegen = @This();

comp: *Compilation,
tree: Tree,
obj: *Object,
node_tag: []const Tree.Tag,
node_data: []const Tree.Node.Data,

pub const Error = Compilation.Error || error{CodegenFailed};

pub fn generateTree(comp: *Compilation, tree: Tree) Compilation.Error!void {
    var c = Codegen{
        .comp = comp,
        .tree = tree,
        .obj = try Object.create(comp),
        .node_tag = tree.nodes.items(.tag),
        .node_data = tree.nodes.items(.data),
    };
    defer c.obj.deinit();

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
            => c.genFn(decl) catch |err| switch (err) {
                error.FatalError => return error.FatalError,
                error.OutOfMemory => return error.OutOfMemory,
                error.CodegenFailed => continue,
            },

            .@"var",
            .static_var,
            .threadlocal_var,
            .threadlocal_static_var,
            => c.genVar(decl) catch |err| switch (err) {
                error.FatalError => return error.FatalError,
                error.OutOfMemory => return error.OutOfMemory,
                error.CodegenFailed => continue,
            },

            else => unreachable,
        }
    }
}

fn genFn(c: *Codegen, decl: NodeIndex) Error!void {
    const section: []const u8 = "text";
    const name = c.tree.tokSlice(c.node_data[@enumToInt(decl)].decl.name);
    const data = try c.obj.declareSymbol(section, name);
    switch (c.comp.target.cpu.arch) {
        .x86_64 => try x86_64.genFn(c, decl, data),
        else => return c.comp.diag.fatalNoSrc("implement genFn for target {}\n", .{c.comp.target.cpu.arch}),
    }
}

fn genVar(c: *Codegen, decl: NodeIndex) Error!void {
    switch (c.comp.target.cpu.arch) {
        .x86_64 => try x86_64.genVar(c, decl),
        else => return c.comp.diag.fatalNoSrc("implement genVar for target {}\n", .{c.comp.target.cpu.arch}),
    }
}
