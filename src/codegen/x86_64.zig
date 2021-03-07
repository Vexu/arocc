const std = @import("std");
const mem = std.mem;
const Tree = @import("../Tree.zig");
const TokenIndex = Tree.TokenIndex;
const NodeIndex = Tree.NodeIndex;
const Compilation = @import("../Compilation.zig");
const Object = @import("../Object.zig");

const CodeGen = struct {
    comp: *Compilation,
    o: *Object,
    node_tag: []const Tree.Tag,
    node_data: []const Tree.Node.Data,
    tree: Tree,
    buf: std.ArrayList(u8),
    cur_stack_size: u32 = 0,
    max_stack_size: u32 = 0,
};

const Error = Compilation.Error || error{CodegenFailed};

pub fn gen(tree: Tree, comp: *Compilation, o: *Object) Compilation.Error!void {
    var g = CodeGen{
        .comp = comp,
        .o = o,
        .node_tag = tree.nodes.items(.tag),
        .node_data = tree.nodes.items(.data),
        .tree = tree,
        .buf = std.ArrayList(u8).init(comp.gpa),
    };
    defer g.buf.deinit();

    for (tree.root_decls) |decl| {
        switch (g.node_tag[decl]) {
            .fn_def,
            .static_fn_def,
            .noreturn_fn_def,
            .noreturn_static_fn_def,
            => genFn(&g, decl) catch |e| switch (e) {
                error.CodegenFailed => continue,
                else => |er| return er,
            },
            .@"var",
            .static_var,
            .threadlocal_var,
            .threadlocal_static_var,
            => genVar(&g, decl) catch |e| switch (e) {
                error.CodegenFailed => continue,
                else => |er| return er,
            },
            else => {}, // ignore externals here
        }
    }
}

fn genFn(g: *CodeGen, node: NodeIndex) Error!void {
    g.buf.items.len = 0;
    g.cur_stack_size = 0;
    g.max_stack_size = 0;
    const data = g.node_data[node];
    const name = g.tree.tokSlice(data.first);
    const body = data.second;
    const ty = g.tree.nodes.items(.ty)[node];
    if (ty.specifier == .var_args_func) return g.comp.diag.fatalNoSrc("TODO var args functions", .{});
    if (ty.data.func.param_types.len != 0) return g.comp.diag.fatalNoSrc("function parameters", .{});

    try genStmt(g, body);

    try g.buf.ensureCapacity(g.buf.items.len + 8 + 2);
    // add epilogue
    // push rbp
    // mov rbp,rsp
    g.buf.insertSlice(0, "\x55\x48\x89\xe5") catch unreachable;
    // TODO check if previous is noreturn
    // add prologue
    // pop rbp
    // ret
    g.buf.appendSliceAssumeCapacity("\x5d\xc3");

    try g.o.declareFn(name, null, g.buf.items);
}

fn genVar(g: *CodeGen, node: NodeIndex) Error!void {
    return g.comp.diag.fatalNoSrc("TODO genVar x86_64", .{});
}

fn genStmt(g: *CodeGen, node: NodeIndex) Error!void {
    switch (g.node_tag[node]) {
        .compound_stmt_two => {
            const data = g.tree.nodes.items(.data)[node];
            if (data.first != 0) _ = try genStmt(g, data.first);
            if (data.second != 0) _ = try genStmt(g, data.second);
        },
        .return_stmt => {
            if (g.node_data[node].first != 0) {
                const operand = try genExpr(g, g.node_data[node].first);
                switch (operand) {
                    .memory => return g.comp.diag.fatalNoSrc("TODO return_stmt memory", .{}),
                    .register => return g.comp.diag.fatalNoSrc("TODO return_stmt register", .{}),
                    .immediate => |v| {
                        if (v < std.math.maxInt(u32)) {
                            const casted = @truncate(u32, v);
                            try g.buf.append(0xb8); // mov eax
                            try g.buf.appendSlice(mem.asBytes(&casted));
                        } else {
                            return g.comp.diag.fatalNoSrc("TODO proper set register", .{});
                        }
                    },
                }
            }
            // leave
            // ret
            g.buf.appendSliceAssumeCapacity("\xc9\xc3");
        },
        .labeled_stmt,
        .compound_stmt,
        .if_then_else_stmt,
        .if_else_stmt,
        .if_then_stmt,
        .switch_stmt,
        .case_stmt,
        .default_stmt,
        .while_stmt,
        .do_while_stmt,
        .for_decl_stmt,
        .forever_stmt,
        .for_stmt,
        .goto_stmt,
        .continue_stmt,
        .break_stmt,
        => return g.comp.diag.fatalNoSrc("TODO genStmt {}", .{g.node_tag[node]}),
        else => _ = try genExpr(g, node),
    }
}

const Value = union(enum) {
    immediate: u64,
    relocated: u32,
    register: void, // TODO
};

fn genExpr(g: *CodeGen, node: NodeIndex) Error!Value {
    switch (g.node_tag[node]) {
        .call_expr_one => {
            const data = g.tree.nodes.items(.data)[node];
            const lhs = try genExpr(g, data.first);
            if (data.second != 0) {
                const arg = try genExpr(g, data.second);
                switch (arg) {
                    .register => return g.comp.diag.fatalNoSrc("TODO call_expr_one arg register", .{}),
                    .immediate => return g.comp.diag.fatalNoSrc("TODO call_expr_one arg immediate", .{}),
                    .memory => |v| {
                        try g.buf.appendSlice("\x48\x8d\x3d"); // lea rip
                        try g.buf.appendSlice(mem.asBytes(&v));
                    },
                }
            }

            switch (lhs) {
                .register => return g.comp.diag.fatalNoSrc("TODO call_expr_one register", .{}),
                .immediate => return g.comp.diag.fatalNoSrc("TODO call_expr_one immediate", .{}),
                .memory => |v| {
                    try g.buf.append(0xe8); // call
                    try g.buf.appendSlice(mem.asBytes(&v));
                },
            }
            // TODO rax
            return Value{ .register = {} };
        },
        .int_literal => {
            return Value{ .immediate = @bitCast(u64, g.node_data[node]) };
        },
        .decl_ref_expr => {
            return Value{ .memory = 0 };
        },
        .array_to_pointer, .lval_to_rval => {
            return genExpr(g, g.node_data[node].first);
        },
        .string_literal_expr => {
            return Value{ .memory = 0 };
        },
        else => return g.comp.diag.fatalNoSrc("TODO genExpr {}", .{g.node_tag[node]}),
        .labeled_stmt,
        .compound_stmt_two,
        .compound_stmt,
        .if_then_else_stmt,
        .if_else_stmt,
        .if_then_stmt,
        .switch_stmt,
        .case_stmt,
        .default_stmt,
        .while_stmt,
        .do_while_stmt,
        .for_decl_stmt,
        .forever_stmt,
        .for_stmt,
        .goto_stmt,
        .continue_stmt,
        .break_stmt,
        .return_stmt,
        => unreachable, // handled in genStmt
    }
}
