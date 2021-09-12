const std = @import("std");
const Codegen = @import("../Codegen.zig");
const Tree = @import("../Tree.zig");
const NodeIndex = Tree.NodeIndex;
const x86_64 = @import("zig").codegen.x86_64;
const Register = x86_64.Register;
const RegisterManager = @import("zig").RegisterManager;

const Fn = @This();

register_manager: RegisterManager(Fn, Register, &x86_64.callee_preserved_regs) = .{},
data: *std.ArrayListUnmanaged(u8),
gpa: *std.mem.Allocator,
c: *Codegen,

pub fn deinit(func: *Fn) void {
    func.* = undefined;
}

pub fn genFn(c: *Codegen, decl: NodeIndex, data: *std.ArrayListUnmanaged(u8)) Codegen.Error!void {
    var func = Fn{
        .data = data,
        .gpa = c.comp.gpa,
        .c = c,
    };
    defer func.deinit();

    // function prologue
    try func.data.appendSlice(func.gpa, &.{ 0x55, 0x48, 0x89, 0xe5 });
    try func.genNode(c.node_data[@enumToInt(decl)].decl.node);
    // all functions are guaranteed to end in a return statement so no extra work required here
}

pub fn spillInst(f: *Fn, reg: Register, inst: u32) !void {
    _ = inst;
    _ = reg;
    _ = f;
}

fn genNode(func: *Fn, node: NodeIndex) Codegen.Error!void {
    const data = func.c.node_data[@enumToInt(node)];
    switch (func.c.node_tag[@enumToInt(node)]) {
        .compound_stmt_two => {
            if (data.bin.lhs != .none) try func.genNode(data.bin.lhs);
            if (data.bin.rhs != .none) try func.genNode(data.bin.rhs);
        },
        .compound_stmt => for (func.c.tree.data[data.range.start..data.range.end]) |stmt| {
            try func.genNode(stmt);
        },
        .call_expr_one => if (data.bin.rhs != .none)
            try func.genCall(data.bin.lhs, &.{data.bin.rhs})
        else
            try func.genCall(data.bin.lhs, &.{}),
        .call_expr => try func.genCall(func.c.tree.data[data.range.start], func.c.tree.data[data.range.start + 1 .. data.range.end]),
        .function_to_pointer => try func.genNode(data.un), // no-op
        .array_to_pointer => try func.genNode(data.un), // no-op
        .decl_ref_expr => {},
        .return_stmt => {},
        .int_literal => {},
        .string_literal_expr => {},
        else => return func.c.comp.diag.fatalNoSrc("TODO x86_64 genNode {}\n", .{func.c.node_tag[@enumToInt(node)]}),
    }
}

fn genCall(func: *Fn, lhs: NodeIndex, args: []const NodeIndex) Codegen.Error!void {
    _ = args;
    _ = lhs;
    _ = func;
}

pub fn genVar(c: *Codegen, decl: NodeIndex) Codegen.Error!void {
    _ = c;
    _ = decl;
}
