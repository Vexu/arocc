const std = @import("std");
const Allocator = std.mem.Allocator;
const assert = std.debug.assert;

const aro = @import("aro");
const Assembly = aro.Assembly;
const Compilation = aro.Compilation;
const NodeIndex = Tree.NodeIndex;
const Source = aro.Source;
const StrInt = aro.StringInterner;
const StringId = StrInt.StringId;
const Tree = aro.Tree;
const Type = aro.Type;
const Value = aro.Value;

const AsmCodeGen = @This();
const Error = @import("../assembly_backend.zig").Error;
const Writer = std.ArrayListUnmanaged(u8).Writer;

tree: Tree,
comp: *Compilation,
node_tag: []const Tree.Tag,
node_data: []const Tree.Node.Data,
node_ty: []const Type,
node_loc: []const Tree.Node.Loc,
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

pub fn todo(c: *AsmCodeGen, msg: []const u8, node: NodeIndex) Error {
    const loc: Source.Location = c.tree.nodeLoc(node) orelse .{};

    try c.comp.addDiagnostic(.{
        .tag = .todo,
        .loc = loc,
        .extra = .{ .str = msg },
    }, &.{});
    return error.CodegenFailed;
}

fn emitAggregate(c: *AsmCodeGen, ty: Type, node: NodeIndex) !void {
    _ = ty;
    return c.todo("Codegen aggregates", node);
}

fn emitSingleValue(c: *AsmCodeGen, ty: Type, node: NodeIndex) !void {
    const value = c.tree.value_map.get(node) orelse return;
    const bit_size = ty.bitSizeof(c.comp).?;
    if (ty.isComplex()) {
        return c.todo("Codegen _Complex values", node);
    } else if (ty.isInt()) {
        const storage_unit = std.meta.intToEnum(StorageUnit, bit_size) catch return c.todo("Codegen _BitInt values", node);
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
        return c.todo("Codegen pointer", node);
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

fn emitValue(c: *AsmCodeGen, ty: Type, node: NodeIndex) !void {
    const tag = c.node_tag[@intFromEnum(node)];
    switch (tag) {
        .array_init_expr,
        .array_init_expr_two,
        .struct_init_expr,
        .struct_init_expr_two,
        .union_init_expr,
        => return c.todo("Codegen multiple inits", node),
        else => return c.emitSingleValue(ty, node),
    }
}

pub fn genAsm(tree: Tree) Error!Assembly {
    var data: std.ArrayListUnmanaged(u8) = .empty;
    defer data.deinit(tree.comp.gpa);

    var text: std.ArrayListUnmanaged(u8) = .empty;
    defer text.deinit(tree.comp.gpa);

    const node_tag = tree.nodes.items(.tag);
    var codegen: AsmCodeGen = .{
        .tree = tree,
        .comp = tree.comp,
        .node_tag = node_tag,
        .node_data = tree.nodes.items(.data),
        .node_ty = tree.nodes.items(.ty),
        .node_loc = tree.nodes.items(.loc),
        .text = text.writer(tree.comp.gpa),
        .data = data.writer(tree.comp.gpa),
    };

    if (tree.comp.code_gen_options.debug) {
        const sources = tree.comp.sources.values();
        for (sources) |source| {
            try codegen.data.print("  .file {d} \"{s}\"\n", .{ @intFromEnum(source.id) - 1, source.path });
        }
    }

    for (codegen.tree.root_decls) |decl| {
        switch (node_tag[@intFromEnum(decl)]) {
            .static_assert,
            .typedef,
            .struct_decl_two,
            .union_decl_two,
            .enum_decl_two,
            .struct_decl,
            .union_decl,
            .enum_decl,
            => {},

            .fn_proto,
            .static_fn_proto,
            .inline_fn_proto,
            .inline_static_fn_proto,
            .extern_var,
            .threadlocal_extern_var,
            => {},

            .fn_def,
            .static_fn_def,
            .inline_fn_def,
            .inline_static_fn_def,
            => try codegen.genFn(decl),

            .@"var",
            .static_var,
            .threadlocal_var,
            .threadlocal_static_var,
            => try codegen.genVar(decl),

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

fn genFn(c: *AsmCodeGen, node: NodeIndex) !void {
    return c.todo("Codegen functions", node);
}

fn genVar(c: *AsmCodeGen, node: NodeIndex) !void {
    const comp = c.comp;
    const ty = c.node_ty[@intFromEnum(node)];
    const tag = c.node_tag[@intFromEnum(node)];
    const decl_data = c.node_data[@intFromEnum(node)].decl;

    const is_threadlocal = tag == .threadlocal_var or tag == .threadlocal_static_var;
    const is_static = tag == .static_var or tag == .threadlocal_static_var;
    const is_tentative = decl_data.node == .none;
    const size = ty.sizeof(comp) orelse blk: {
        // tentative array definition assumed to have one element
        std.debug.assert(is_tentative and ty.isArray());
        break :blk ty.elemType().sizeof(comp).?;
    };

    const name = c.tree.tokSlice(decl_data.name);
    const nat_align = ty.alignof(comp);
    const alignment = if (ty.isArray() and size >= 16) @max(16, nat_align) else nat_align;

    if (is_static) {
        try c.data.print("  .local \"{s}\"\n", .{name});
    } else {
        try c.data.print("  .globl \"{s}\"\n", .{name});
    }

    if (is_tentative and comp.code_gen_options.common) {
        try c.data.print("  .comm \"{s}\", {d}, {d}\n", .{ name, size, alignment });
        return;
    }
    if (!is_tentative) {
        if (is_threadlocal and comp.code_gen_options.data_sections) {
            try c.data.print("  .section .tdata.\"{s}\",\"awT\",@progbits\n", .{name});
        } else if (is_threadlocal) {
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
        try c.emitValue(ty, decl_data.node);
        return;
    }
    if (is_threadlocal and comp.code_gen_options.data_sections) {
        try c.data.print("  .section .tbss.\"{s}\",\"awT\",@nobits\n", .{name});
    } else if (is_threadlocal) {
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
