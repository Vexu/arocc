const std = @import("std");
const Allocator = std.mem.Allocator;
const assert = std.debug.assert;

const aro = @import("aro");
const Assembly = aro.Assembly;
const Compilation = aro.Compilation;
const Node = Tree.Node;
const Source = aro.Source;
const Tree = aro.Tree;
const Type = aro.Type;
const Value = aro.Value;

const AsmCodeGen = @This();
const Error = aro.Compilation.Error;
const Writer = std.ArrayListUnmanaged(u8).Writer;

tree: *const Tree,
comp: *Compilation,
text: Writer,
data: Writer,

const StorageUnit = enum(u8) {
    byte = 8,
    short = 16,
    long = 32,
    quad = 64,

    fn trunc(self: StorageUnit, val: u64) u64 {
        return switch (self) {
            .byte => @as(u8, @truncate(val)),
            .short => @as(u16, @truncate(val)),
            .long => @as(u32, @truncate(val)),
            .quad => val,
        };
    }
};

fn serializeInt(value: u64, storage_unit: StorageUnit, w: Writer) !void {
    try w.print("  .{s}  0x{x}\n", .{ @tagName(storage_unit), storage_unit.trunc(value) });
}

fn serializeFloat(comptime T: type, value: T, w: Writer) !void {
    switch (T) {
        f128 => {
            const bytes = std.mem.asBytes(&value);
            const first = std.mem.bytesToValue(u64, bytes[0..8]);
            try serializeInt(first, .quad, w);
            const second = std.mem.bytesToValue(u64, bytes[8..16]);
            return serializeInt(second, .quad, w);
        },
        f80 => {
            const bytes = std.mem.asBytes(&value);
            const first = std.mem.bytesToValue(u64, bytes[0..8]);
            try serializeInt(first, .quad, w);
            const second = std.mem.bytesToValue(u16, bytes[8..10]);
            try serializeInt(second, .short, w);
            return w.writeAll("  .zero 6\n");
        },
        else => {
            const size = @bitSizeOf(T);
            const storage_unit = std.meta.intToEnum(StorageUnit, size) catch unreachable;
            const IntTy = @Type(.{ .int = .{ .signedness = .unsigned, .bits = size } });
            const int_val: IntTy = @bitCast(value);
            return serializeInt(int_val, storage_unit, w);
        },
    }
}

pub fn todo(c: *AsmCodeGen, msg: []const u8, tok: Tree.TokenIndex) Error {
    const loc: Source.Location = c.tree.tokens.items(.loc)[tok];

    try c.comp.addDiagnostic(.{
        .tag = .todo,
        .loc = loc,
        .extra = .{ .str = msg },
    }, &.{});
    return error.FatalError;
}

fn emitAggregate(c: *AsmCodeGen, ty: Type, node: Node.Index) !void {
    _ = ty;
    return c.todo("Codegen aggregates", node.tok(c.tree));
}

fn emitSingleValue(c: *AsmCodeGen, ty: Type, node: Node.Index) !void {
    const value = c.tree.value_map.get(node) orelse return;
    const bit_size = ty.bitSizeof(c.comp).?;
    if (ty.isComplex()) {
        return c.todo("Codegen _Complex values", node.tok(c.tree));
    } else if (ty.isInt()) {
        const storage_unit = std.meta.intToEnum(StorageUnit, bit_size) catch return c.todo("Codegen _BitInt values", node.tok(c.tree));
        try c.data.print("  .{s} ", .{@tagName(storage_unit)});
        _ = try value.print(ty, c.comp, c.data);
        try c.data.writeByte('\n');
    } else if (ty.isFloat()) {
        switch (bit_size) {
            16 => return serializeFloat(f16, value.toFloat(f16, c.comp), c.data),
            32 => return serializeFloat(f32, value.toFloat(f32, c.comp), c.data),
            64 => return serializeFloat(f64, value.toFloat(f64, c.comp), c.data),
            80 => return serializeFloat(f80, value.toFloat(f80, c.comp), c.data),
            128 => return serializeFloat(f128, value.toFloat(f128, c.comp), c.data),
            else => unreachable,
        }
    } else if (ty.isPtr()) {
        return c.todo("Codegen pointer", node.tok(c.tree));
    } else if (ty.isArray()) {
        // Todo:
        //  Handle truncated initializers e.g. char x[3] = "hello";
        //  Zero out remaining bytes if initializer is shorter than storage capacity
        //  Handle non-char strings
        const bytes = value.toBytes(c.comp);
        const directive = if (bytes.len > bit_size / 8) "ascii" else "string";
        try c.data.print("  .{s} ", .{directive});
        try Value.printString(bytes, ty, c.comp, c.data);

        try c.data.writeByte('\n');
    } else unreachable;
}

fn emitValue(c: *AsmCodeGen, ty: Type, node: Node.Index) !void {
    switch (node.get(c.tree)) {
        .array_init_expr,
        .struct_init_expr,
        .union_init_expr,
        => return c.todo("Codegen multiple inits", node.tok(c.tree)),
        else => return c.emitSingleValue(ty, node),
    }
}

pub fn genAsm(tree: *const Tree) Error!Assembly {
    var data: std.ArrayListUnmanaged(u8) = .empty;
    defer data.deinit(tree.comp.gpa);

    var text: std.ArrayListUnmanaged(u8) = .empty;
    defer text.deinit(tree.comp.gpa);

    var codegen: AsmCodeGen = .{
        .tree = tree,
        .comp = tree.comp,
        .text = text.writer(tree.comp.gpa),
        .data = data.writer(tree.comp.gpa),
    };

    if (tree.comp.code_gen_options.debug) {
        const sources = tree.comp.sources.values();
        for (sources) |source| {
            try codegen.data.print("  .file {d} \"{s}\"\n", .{ @intFromEnum(source.id) - 1, source.path });
        }
    }

    for (codegen.tree.root_decls.items) |decl| {
        switch (decl.get(codegen.tree)) {
            .static_assert,
            .typedef,
            .struct_decl,
            .union_decl,
            .enum_decl,
            => {},

            .fn_proto => {},

            .fn_def => |def| try codegen.genFn(def),

            .variable => |variable| try codegen.genVar(variable),

            else => unreachable,
        }
    }
    try codegen.text.writeAll("  .section  .note.GNU-stack,\"\",@progbits\n");
    const text_slice = try text.toOwnedSlice(tree.comp.gpa);
    errdefer tree.comp.gpa.free(text_slice);
    const data_slice = try data.toOwnedSlice(tree.comp.gpa);
    return .{
        .text = text_slice,
        .data = data_slice,
    };
}

fn genFn(c: *AsmCodeGen, def: Node.FnDef) !void {
    return c.todo("Codegen functions", def.name_tok);
}

fn genVar(c: *AsmCodeGen, variable: Node.Variable) !void {
    const comp = c.comp;
    const ty = variable.type;

    const is_tentative = variable.initializer == null;
    const size = ty.sizeof(comp) orelse blk: {
        // tentative array definition assumed to have one element
        std.debug.assert(is_tentative and ty.isArray());
        break :blk ty.elemType().sizeof(comp).?;
    };

    const name = c.tree.tokSlice(variable.name_tok);
    const nat_align = ty.alignof(comp);
    const alignment = if (ty.isArray() and size >= 16) @max(16, nat_align) else nat_align;

    if (variable.static) {
        try c.data.print("  .local \"{s}\"\n", .{name});
    } else {
        try c.data.print("  .globl \"{s}\"\n", .{name});
    }

    if (is_tentative and comp.code_gen_options.common) {
        try c.data.print("  .comm \"{s}\", {d}, {d}\n", .{ name, size, alignment });
        return;
    }
    if (variable.initializer) |init| {
        if (variable.thread_local and comp.code_gen_options.data_sections) {
            try c.data.print("  .section .tdata.\"{s}\",\"awT\",@progbits\n", .{name});
        } else if (variable.thread_local) {
            try c.data.writeAll("  .section .tdata,\"awT\",@progbits\n");
        } else if (comp.code_gen_options.data_sections) {
            try c.data.print("  .section .data.\"{s}\",\"aw\",@progbits\n", .{name});
        } else {
            try c.data.writeAll("  .data\n");
        }

        try c.data.print("  .type \"{s}\", @object\n", .{name});
        try c.data.print("  .size \"{s}\", {d}\n", .{ name, size });
        try c.data.print("  .align {d}\n", .{alignment});
        try c.data.print("\"{s}\":\n", .{name});
        try c.emitValue(ty, init);
        return;
    }
    if (variable.thread_local and comp.code_gen_options.data_sections) {
        try c.data.print("  .section .tbss.\"{s}\",\"awT\",@nobits\n", .{name});
    } else if (variable.thread_local) {
        try c.data.writeAll("  .section .tbss,\"awT\",@nobits\n");
    } else if (comp.code_gen_options.data_sections) {
        try c.data.print("  .section .bss.\"{s}\",\"aw\",@nobits\n", .{name});
    } else {
        try c.data.writeAll("  .bss\n");
    }
    try c.data.print("  .align {d}\n", .{alignment});
    try c.data.print("\"{s}\":\n", .{name});
    try c.data.print("  .zero {d}\n", .{size});
}
