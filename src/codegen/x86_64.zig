const std = @import("std");
const Codegen = @import("../Codegen.zig");
const Tree = @import("../Tree.zig");
const NodeIndex = Tree.NodeIndex;
const x86_64 = @import("zig").codegen.x86_64;
const Register = x86_64.Register;
const RegisterManager = @import("zig").RegisterManager;

const Fn = @This();

const Value = union(enum) {
    symbol: []const u8,
    immediate: u64,
    register: Register,
    none,
};

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
    try func.data.appendSlice(func.gpa, &.{
        0x55, // push rbp
        0x48, 0x89, 0xe5, // mov rbp,rsp
    });
    _ = try func.genNode(c.node_data[@enumToInt(decl)].decl.node);
    // all functions are guaranteed to end in a return statement so no extra work required here
}

pub fn spillInst(f: *Fn, reg: Register, inst: u32) !void {
    _ = inst;
    _ = reg;
    _ = f;
}

fn genNode(func: *Fn, node: NodeIndex) Codegen.Error!Value {
    if (func.c.tree.value_map.get(node)) |some| return Value{ .immediate = some };

    const data = func.c.node_data[@enumToInt(node)];
    switch (func.c.node_tag[@enumToInt(node)]) {
        .compound_stmt_two => {
            if (data.bin.lhs != .none) _ = try func.genNode(data.bin.lhs);
            if (data.bin.rhs != .none) _ = try func.genNode(data.bin.rhs);
            return Value{ .none = {} };
        },
        .compound_stmt => {
            for (func.c.tree.data[data.range.start..data.range.end]) |stmt| {
                _ = try func.genNode(stmt);
            }
            return Value{ .none = {} };
        },
        .call_expr_one => if (data.bin.rhs != .none)
            return func.genCall(data.bin.lhs, &.{data.bin.rhs})
        else
            return func.genCall(data.bin.lhs, &.{}),
        .call_expr => return func.genCall(func.c.tree.data[data.range.start], func.c.tree.data[data.range.start + 1 .. data.range.end]),
        .function_to_pointer => return func.genNode(data.un), // no-op
        .array_to_pointer => return func.genNode(data.un), // no-op
        .decl_ref_expr => {
            // TODO locals and arguments
            return Value{ .symbol = func.c.tree.tokSlice(data.decl_ref) };
        },
        .return_stmt => {
            // TODO gen return value
            try func.data.appendSlice(func.gpa, &.{ 0x31, 0xc0 }); // xor eax
            try func.data.appendSlice(func.gpa, &.{
                0x5d, // pop rbp
                0xc3, // ret
            });
            return Value{ .none = {} };
        },
        .int_literal => return Value{ .immediate = data.int },
        .string_literal_expr => {
            const str_bytes = func.c.tree.strings[data.str.index..][0..data.str.len];
            const section = try func.c.obj.getSection(.strings);
            const start = section.items.len;
            try section.appendSlice(func.gpa, str_bytes);
            const symbol_name = try func.c.obj.declareSymbol(.strings, null, .Internal, .variable, start, str_bytes.len);
            return Value{ .symbol = symbol_name };
        },
        else => return func.c.comp.diag.fatalNoSrc("TODO x86_64 genNode {}\n", .{func.c.node_tag[@enumToInt(node)]}),
    }
}

fn genCall(func: *Fn, lhs: NodeIndex, args: []const NodeIndex) Codegen.Error!Value {
    _ = try func.genNode(lhs);
    for (args) |arg| {
        _ = try func.genNode(arg);
    }
    return Value{ .none = {} };
}

pub fn genVar(c: *Codegen, decl: NodeIndex) Codegen.Error!void {
    _ = c;
    _ = decl;
}
