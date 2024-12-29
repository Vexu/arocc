pub const std = @import("std");

const Attribute = @import("Attribute.zig");
const Compilation = @import("Compilation.zig");
const StringInterner = @import("StringInterner.zig");
const StringId = StringInterner.StringId;
const Tree = @import("Tree.zig");
const Node = Tree.Node;
const TokenIndex = Tree.TokenIndex;

const Repr = struct {
    tag: Tag,
    /// If a Type has a child type it is stored in data[0].
    data: [2]u32,

    pub const Tag = enum(u8) {
        complex,
        bit_int,
        atomic,
        func,
        func_variadic,
        func_old_style,
        func_zero,
        func_variadic_zero,
        func_old_style_zero,
        func_one,
        func_variadic_one,
        func_old_style_one,
        pointer,
        pointer_decayed,
        array_incomplete,
        array_fixed,
        array_static,
        array_variable,
        array_unspecified_variable,
        vector,
        @"struct",
        struct_incomplete,
        @"union",
        union_incomplete,
        @"enum",
        enum_fixed,
        enum_incomplete,
        typeof,
        typeof_expr,
        typedef,
        attributed,
        attributed_one,
    };
};

const Index = enum(u29) {
    /// A NaN-like poison value
    invalid = std.math.maxInt(u29) - 0,
    /// GNU auto type
    /// This is a placeholder specifier - it must be replaced by the actual type specifier (determined by the initializer)
    auto_type = std.math.maxInt(u29) - 1,
    /// C23 auto, behaves like auto_type
    c23_auto = std.math.maxInt(u29) - 2,
    void = std.math.maxInt(u29) - 3,
    bool = std.math.maxInt(u29) - 4,
    nullptr_t = std.math.maxInt(u29) - 5,
    int_char = std.math.maxInt(u29) - 6,
    int_schar = std.math.maxInt(u29) - 7,
    int_uchar = std.math.maxInt(u29) - 8,
    int_short = std.math.maxInt(u29) - 9,
    int_ushort = std.math.maxInt(u29) - 10,
    int_int = std.math.maxInt(u29) - 11,
    int_uint = std.math.maxInt(u29) - 12,
    int_long = std.math.maxInt(u29) - 13,
    int_ulong = std.math.maxInt(u29) - 14,
    int_long_long = std.math.maxInt(u29) - 15,
    int_ulong_long = std.math.maxInt(u29) - 16,
    int_int128 = std.math.maxInt(u29) - 17,
    int_uint128 = std.math.maxInt(u29) - 18,
    float_fp16 = std.math.maxInt(u29) - 19,
    float_float16 = std.math.maxInt(u29) - 20,
    float_float = std.math.maxInt(u29) - 21,
    float_double = std.math.maxInt(u29) - 22,
    float_long_double = std.math.maxInt(u29) - 23,
    float_float128 = std.math.maxInt(u29) - 24,
    _,
};

const TypeStore = @This();

pub const QualType = packed struct(u32) {
    @"const": bool = false,
    @"volatile": bool = false,
    restrict: bool = false,

    _index: Index,

    pub const @"void": QualType = .{ ._index = .void };
    pub const int: QualType = .{ ._index = .int_int };
    pub const invalid: QualType = .{ ._index = .invalid };

    pub fn @"type"(qt: QualType, ts: *const TypeStore) Type {
        switch (qt._index) {
            .invalid => unreachable,
            .auto_type => unreachable,
            .c23_auto => unreachable,
            .void => return .void,
            .bool => return .bool,
            .nullptr_t => return .nullptr_t,
            .int_char => return .{ .int = .char },
            .int_schar => return .{ .int = .schar },
            .int_uchar => return .{ .int = .uchar },
            .int_short => return .{ .int = .short },
            .int_ushort => return .{ .int = .ushort },
            .int_int => return .{ .int = .int },
            .int_uint => return .{ .int = .uint },
            .int_long => return .{ .int = .long },
            .int_ulong => return .{ .int = .ulong },
            .int_long_long => return .{ .int = .long_long },
            .int_ulong_long => return .{ .int = .ulong_long },
            .int_int128 => return .{ .int = .int128 },
            .int_uint128 => return .{ .int = .uint128 },
            .float_fp16 => return .{ .float = .fp16 },
            .float_float16 => return .{ .float = .float16 },
            .float_float => return .{ .float = .float },
            .float_double => return .{ .float = .double },
            .float_long_double => return .{ .float = .long_double },
            .float_float128 => return .{ .float = .float128 },
            else => {},
        }

        const repr = ts.types.get(@intFromEnum(qt._index));
        return switch (repr.tag) {
            .complex => .{ .complex = @bitCast(repr.data[0]) },
            .atomic => .{ .atomic = @bitCast(repr.data[0]) },
            .bit_int => .{ .bit_int = .{
                .bits = @intCast(repr.data[0]),
                .signedness = @enumFromInt(repr.data[1]),
            } },
            .func,
            .func_variadic,
            .func_old_style,
            .func_zero,
            .func_variadic_zero,
            .func_old_style_zero,
            .func_one,
            .func_variadic_one,
            .func_old_style_one,
            => @panic("TODO"),
            .pointer => .{ .pointer = .{
                .child = @bitCast(repr.data[0]),
                .decayed = null,
            } },
            .pointer_decayed => .{ .pointer = .{
                .child = @bitCast(repr.data[0]),
                .decayed = @bitCast(repr.data[1]),
            } },
            .array_incomplete => .{ .array = .{
                .elem = @bitCast(repr.data[0]),
                .len = .incomplete,
            } },
            .array_fixed => .{ .array = .{
                .elem = @bitCast(repr.data[0]),
                .len = .{ .fixed = @bitCast(ts.extra.items[repr.data[1]..][0..2].*) },
            } },
            .array_static => .{ .array = .{
                .elem = @bitCast(repr.data[0]),
                .len = .{ .static = @bitCast(ts.extra.items[repr.data[1]..][0..2].*) },
            } },
            .array_variable => .{ .array = .{
                .elem = @bitCast(repr.data[0]),
                .len = .{ .variable = @enumFromInt(repr.data[1]) },
            } },
            .array_unspecified_variable => .{ .array = .{
                .elem = @bitCast(repr.data[0]),
                .len = .unspecified_variable,
            } },
            .vector => .{ .vector = .{
                .elem = @bitCast(repr.data[0]),
                .len = @bitCast(ts.extra.items[repr.data[1]..][0..2].*),
            } },
            .@"struct", .@"union" => {
                const layout_size = 6;
                const layout = @as(*Type.Record.Layout, @alignCast(@ptrCast(ts.extra.items[repr.data[1]..][0..layout_size]))).*;
                const fields_len = ts.extra.items[repr.data[1] + layout_size];
                const fields = ts.extra.items[repr.data[1] + layout_size + 1 ..][0..fields_len];

                const record: Type.Record = .{
                    .name = @enumFromInt(repr.data[0]),
                    .layout = layout,
                    .fields = std.mem.bytesAsSlice(Type.Record.Field, std.mem.sliceAsBytes(fields)),
                };
                return switch (repr.tag) {
                    .@"struct" => .{ .@"struct" = record },
                    .@"union" => .{ .@"union" = record },
                    else => unreachable,
                };
            },
            .struct_incomplete => .{ .@"struct" = .{
                .name = @enumFromInt(repr.data[0]),
                .layout = null,
                .fields = &.{},
            } },
            .union_incomplete => .{ .@"union" = .{
                .name = @enumFromInt(repr.data[0]),
                .layout = null,
                .fields = &.{},
            } },
            .@"enum", .enum_fixed => .{ .@"enum" = .{
                .name = @enumFromInt(ts.extra.items[repr.data[1]]),
                .tag = @bitCast(repr.data[0]),
                .fixed = repr.tag == .enum_fixed,
                .fields = std.mem.bytesAsSlice(Type.Enum.Field, std.mem.sliceAsBytes(ts.extra.items[repr.data[1] + 1 ..][0 .. repr.data[1] + 2])),
            } },
            .enum_incomplete => .{ .@"enum" = .{
                .name = @enumFromInt(repr.data[0]),
                .tag = null,
                .fixed = false,
                .fields = &.{},
            } },
            .typeof => .{ .typeof = .{
                .base = @bitCast(repr.data[0]),
                .expr = null,
            } },
            .typeof_expr => .{ .typeof = .{
                .base = @bitCast(repr.data[0]),
                .expr = @enumFromInt(repr.data[1]),
            } },
            .typedef => .{ .typedef = .{
                .base = @bitCast(repr.data[0]),
                .name = @enumFromInt(repr.data[1]),
            } },
            .attributed => .{ .attributed = .{
                .base = @bitCast(repr.data[0]),
                .attributes = ts.attributes.items[ts.extra.items[repr.data[1]]..][0..ts.extra.items[repr.data[1] + 1]],
            } },
            .attributed_one => .{ .attributed = .{
                .base = @bitCast(repr.data[0]),
                .attributes = ts.attributes.items[repr.data[1]..][0..1],
            } },
        };
    }

    pub fn baseType(qt: QualType, ts: *const TypeStore) Type {
        var cur = qt;
        while (true) switch (cur.get(ts)) {
            .typeof => |typeof| cur = typeof.child,
            .typedef => |typedef| cur = typedef.child,
            .attributed => |attributed| cur = attributed.child,
            else => |ty| return ty,
        };
    }
};

pub const Type = union(enum) {
    void,
    bool,
    /// C23 nullptr_t
    nullptr_t,

    int: Int,
    float: Float,
    complex: QualType,
    bit_int: BitInt,
    atomic: QualType,

    func: Func,
    pointer: Pointer,
    array: Array,
    vector: Vector,

    @"struct": Record,
    @"union": Record,
    @"enum": Enum,

    typeof: TypeOf,
    typedef: TypeDef,
    attributed: Attributed,

    pub const Int = enum {
        char,
        schar,
        uchar,
        short,
        ushort,
        int,
        uint,
        long,
        ulong,
        long_long,
        ulong_long,
        int128,
        uint128,
    };

    pub const Float = enum {
        fp16,
        float16,
        float,
        double,
        long_double,
        float128,
    };

    pub const BitInt = struct {
        /// Must be >= 1 if unsigned and >= 2 if signed
        bits: u16,
        signedness: std.builtin.Signedness,
    };

    pub const Func = struct {
        return_type: QualType,
        kind: enum {
            /// int foo(int bar, char baz) and int (void)
            normal,
            /// int foo(int bar, char baz, ...)
            variadic,
            /// int foo(bar, baz) and int foo()
            /// is also var args, but we can give warnings about incorrect amounts of parameters
            old_style,
        },
        params: []const Param,

        pub const Param = extern struct {
            type: QualType,
            name: StringId,
            name_tok: TokenIndex,
        };
    };

    pub const Pointer = struct {
        child: QualType,
        decayed: ?QualType,
    };

    pub const Array = struct {
        elem: QualType,
        len: union(enum) {
            incomplete,
            fixed: u64,
            static: u64,
            variable: Node.Index,
            unspecified_variable,
        },
    };

    pub const Vector = struct {
        elem: QualType,
        len: u64,
    };

    pub const Record = struct {
        name: StringId,
        layout: ?Layout,
        fields: []const Field,

        pub const Field = extern struct {
            type: QualType,
            name: StringId,
            /// zero for anonymous fields
            name_tok: TokenIndex = 0,
            bit_width: enum(u32) {
                null = std.math.maxInt(u32),
                _,
            } = .null,
            layout: Field.Layout = .{
                .offset_bits = 0,
                .size_bits = 0,
            },
            _attr_index: u32 = 0,
            _attr_len: u32 = 0,

            pub fn attributes(field: Field, ts: *const TypeStore) []const Attribute {
                return ts.attributes.items[field._attr_index..][0..field._attr_len];
            }

            pub const Layout = extern struct {
                /// `offset_bits` and `size_bits` should both be INVALID if and only if the field
                /// is an unnamed bitfield. There is no way to reference an unnamed bitfield in C, so
                /// there should be no way to observe these values. If it is used, this value will
                /// maximize the chance that a safety-checked overflow will occur.
                const INVALID = std.math.maxInt(u64);

                /// The offset of the field, in bits, from the start of the struct.
                offset_bits: u64 align(4) = INVALID,
                /// The size, in bits, of the field.
                ///
                /// For bit-fields, this is the width of the field.
                size_bits: u64 align(4) = INVALID,

                pub fn isUnnamed(self: Field.Layout) bool {
                    return self.offset_bits == INVALID and self.size_bits == INVALID;
                }
            };
        };

        pub const Layout = extern struct {
            /// The size of the type in bits.
            ///
            /// This is the value returned by `sizeof` in C
            /// (but in bits instead of bytes). This is a multiple of `pointer_alignment_bits`.
            size_bits: u64 align(4),
            /// The alignment of the type, in bits, when used as a field in a record.
            ///
            /// This is usually the value returned by `_Alignof` in C, but there are some edge
            /// cases in GCC where `_Alignof` returns a smaller value.
            field_alignment_bits: u32,
            /// The alignment, in bits, of valid pointers to this type.
            /// `size_bits` is a multiple of this value.
            pointer_alignment_bits: u32,
            /// The required alignment of the type in bits.
            ///
            /// This value is only used by MSVC targets. It is 8 on all other
            /// targets. On MSVC targets, this value restricts the effects of `#pragma pack` except
            /// in some cases involving bit-fields.
            required_alignment_bits: u32,
        };
    };

    pub const Enum = struct {
        tag: ?QualType,
        fixed: bool,
        name: StringId,
        fields: []const Field,

        pub const Field = extern struct {
            type: QualType,
            name: StringId,
            name_tok: TokenIndex,
            node: Node.Index,
        };
    };

    pub const TypeOf = struct {
        base: QualType,
        expr: ?Node.Index,
    };

    pub const TypeDef = struct {
        base: QualType,
        name: StringId,
    };

    pub const Attributed = struct {
        base: QualType,
        attributes: []const Attribute,
    };
};

comp: *Compilation,
types: std.MultiArrayList(Repr) = .empty,
extra: std.ArrayListUnmanaged(u32) = .empty,
attributes: std.ArrayListUnmanaged(Attribute) = .empty,

pub fn deinit(ts: *TypeStore) void {
    ts.types.deinit(ts.comp.gpa);
    ts.extra.deinit(ts.comp.gpa);
    ts.attributes.deinit(ts.comp.gpa);
    ts.* = undefined;
}

pub fn put(ts: *TypeStore, ty: Type) !Index {
    switch (ty) {
        .auto_type => return .auto_type,
        .c23_auto => return .c23_auto,
        .void => return .void,
        .bool => return .bool,
        .nullptr_t => return .nullptr_t,
        .int => |int| switch (int) {
            .char => return .int_char,
            .schar => return .int_schar,
            .uchar => return .int_uchar,
            .short => return .int_short,
            .ushort => return .int_ushort,
            .int => return .int_int,
            .uint => return .int_uint,
            .long => return .int_long,
            .ulong => return .int_ulong,
            .long_long => return .int_long_long,
            .ulong_long => return .int_ulong_long,
            .int128 => return .int_int128,
            .uint128 => return .int_uint128,
        },
        .float => |float| switch (float) {
            .fp16 => return .float_fp16,
            .float16 => return .float_float16,
            .float => return .float_float,
            .double => return .float_double,
            .long_double => return .float_long_double,
            .float128 => return .float_float128,
        },
        else => {},
    }
    const index = try ts.types.addOne(ts.comp.gpa);
    try ts.set(ty, index);
    return @enumFromInt(index);
}

pub fn set(ts: *TypeStore, ty: Type, index: usize) !void {
    var repr: Repr = undefined;
    switch (ty) {
        .auto_type => unreachable,
        .c23_auto => unreachable,
        .void => unreachable,
        .bool => unreachable,
        .nullptr_t => unreachable,
        .int => unreachable,
        .float => unreachable,
        .complex => |complex| {
            repr.tag = .complex;
            repr.data[0] = @bitCast(complex);
        },
        .bit_int => |bit_int| {
            repr.tag = .bit_int;
            repr.data[0] = bit_int.bits;
            repr.data[1] = @intFromEnum(bit_int.signedness);
        },
        .atomic => |atomic| {
            repr.tag = .atomic;
            std.debug.assert(!atomic.@"const" and !atomic.@"volatile");
            repr.data[0] = @bitCast(atomic);
        },
        .func => |func| {
            repr.data[0] = @bitCast(func.return_type);

            const extra_index: u32 = @intCast(ts.extra.items.len);
            repr.data[1] = extra_index;
            if (func.params.len > 1) {
                try ts.extra.append(ts.comp.gpa, @intCast(func.params.len));
            }

            const param_size = 3;
            comptime std.debug.assert(@sizeOf(Type.Func.Param) == @sizeOf(u32) * param_size);

            try ts.extra.ensureUnusedCapacity(ts.comp.gpa, func.params.len * param_size);
            for (func.params) |*param| {
                const casted: *const [param_size]u32 = @ptrCast(param);
                ts.extra.appendSliceAssumeCapacity(casted);
            }

            repr.tag = switch (func.kind) {
                .normal => switch (func.params.len) {
                    0 => .func_zero,
                    1 => .func_one,
                    else => .func,
                },
                .variadic => switch (func.params.len) {
                    0 => .func_variadic_zero,
                    1 => .func_variadic_one,
                    else => .func_variadic,
                },
                .old_style => switch (func.params.len) {
                    0 => .func_variadic_zero,
                    1 => .func_variadic_one,
                    else => .func_variadic,
                },
            };
        },
        .pointer => |pointer| {
            repr.data[0] = @bitCast(pointer.child);
            if (pointer.decayed) |array| {
                repr.tag = .pointer_decayed;
                repr.data[1] = @bitCast(array);
            } else {
                repr.tag = .pointer;
            }
        },
        .array => |array| {
            repr.data[0] = @bitCast(array.elem);

            const extra_index: u32 = @intCast(ts.extra.items.len);
            switch (array.len) {
                .incomplete => {
                    repr.tag = .array_incomplete;
                },
                .fixed => |len| {
                    repr.tag = .array_fixed;
                    repr.data[1] = extra_index;
                    try ts.extra.appendSlice(ts.comp.gpa, &@as([2]u32, @bitCast(len)));
                },
                .static => |len| {
                    repr.tag = .array_static;
                    repr.data[1] = extra_index;
                    try ts.extra.appendSlice(ts.comp.gpa, &@as([2]u32, @bitCast(len)));
                },
                .variable => |expr| {
                    repr.tag = .array_variable;
                    repr.data[1] = @intFromEnum(expr);
                },
                .unspecified_variable => {
                    repr.tag = .array_unspecified_variable;
                },
            }
        },
        .vector => |vector| {
            repr.tag = .vector;
            repr.data[0] = @bitCast(vector.elem);

            const extra_index: u32 = @intCast(ts.extra.items.len);
            repr.data[1] = extra_index;
            try ts.extra.appendSlice(ts.comp.gpa, &@as([2]u32, @bitCast(vector.len)));
        },
        .@"struct", .@"union" => |record| record: {
            repr.data[0] = @intFromEnum(record.name);
            const layout = record.layout orelse {
                std.debug.assert(record.fields.len == 0);
                repr.tag = switch (ty) {
                    .@"struct" => .struct_incomplete,
                    .@"union" => .union_incomplete,
                    else => unreachable,
                };
                break :record;
            };
            repr.tag = switch (ty) {
                .@"struct" => .@"struct",
                .@"union" => .@"union",
                else => unreachable,
            };

            const extra_index: u32 = @intCast(ts.extra.items.len);
            repr.data[1] = extra_index;

            const layout_size = 5;
            comptime std.debug.assert(@sizeOf(Type.Record.Layout) == @sizeOf(u32) * layout_size);
            const field_size = 10;
            comptime std.debug.assert(@sizeOf(Type.Record.Field) == @sizeOf(u32) * field_size);
            try ts.extra.ensureUnusedCapacity(ts.comp.gpa, record.fields.len * field_size + layout_size + 1);

            const casted_layout: *const [layout_size]u32 = @ptrCast(&layout);
            ts.extra.appendSliceAssumeCapacity(casted_layout);
            ts.extra.appendAssumeCapacity(@intCast(record.fields.len));

            for (record.fields) |*field| {
                const casted: *const [field_size]u32 = @ptrCast(field);
                ts.extra.appendSliceAssumeCapacity(casted);
            }
        },
        .@"enum" => |@"enum"| @"enum": {
            const tag_ty = @"enum".tag orelse {
                std.debug.assert(@"enum".fields.len == 0);
                repr.tag = .enum_incomplete;
                repr.data[0] = @intFromEnum(@"enum".name);
                break :@"enum";
            };
            repr.data[0] = @bitCast(tag_ty);
            repr.tag = if (@"enum".fixed) .enum_fixed else .@"enum";

            const extra_index: u32 = @intCast(ts.extra.items.len);
            repr.data[1] = extra_index;

            const field_size = 4;
            comptime std.debug.assert(@sizeOf(Type.Enum.Field) == @sizeOf(u32) * field_size);
            try ts.extra.ensureUnusedCapacity(ts.comp.gpa, @"enum".fields.len * field_size + 1 + 1);

            ts.extra.appendAssumeCapacity(@intFromEnum(@"enum".name));
            ts.extra.appendAssumeCapacity(@intCast(@"enum".fields.len));

            for (@"enum".fields) |*field| {
                const casted: *const [field_size]u32 = @ptrCast(field);
                ts.extra.appendSliceAssumeCapacity(casted);
            }
        },
        .typeof => |typeof| {
            repr.data[0] = @bitCast(typeof.base);
            if (typeof.expr) |some| {
                repr.tag = .typeof_expr;
                repr.data[1] = @intFromEnum(some);
            } else {
                repr.tag = .typeof;
            }
        },
        .typedef => |typedef| {
            repr.tag = .typedef;
            repr.data[0] = @bitCast(typedef.base);
            repr.data[1] = @intFromEnum(typedef.name);
        },
        .attributed => |attributed| {
            repr.data[0] = @bitCast(attributed.base);

            const attr_index: u32 = @intCast(ts.attributes.items.len);
            const attr_count: u32 = @intCast(attributed.attributes.len);
            try ts.attributes.appendSlice(ts.comp.gpa, attributed.attributes);
            if (attr_count > 1) {
                repr.tag = .attributed;
                const extra_index: u32 = @intCast(ts.extra.items.len);
                repr.data[0] = extra_index;
                try ts.extra.appendSlice(ts.comp.gpa, &.{ attr_index, attr_count });
            } else {
                repr.tag = .attributed_one;
                repr.data[0] = attr_index;
            }
        },
    }
    ts.types.set(index, repr);
}
