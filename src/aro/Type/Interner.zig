const std = @import("std");
const Allocator = std.mem.Allocator;
const assert = std.debug.assert;
const Hash = std.hash.Wyhash;
const Attribute = @import("../Attribute.zig");
const Compilation = @import("../Compilation.zig");
const StringInterner = @import("../StringInterner.zig");
const StringId = StringInterner.StringId;
const Tree = @import("../Tree.zig");
const TokenIndex = Tree.TokenIndex;
const NodeIndex = Tree.NodeIndex;
const Type = @import("../Type.zig");
const target_util = @import("../target.zig");

const Interner = @This();

map: std.AutoArrayHashMapUnmanaged(void, void) = .{},
items: std.MultiArrayList(struct {
    tag: Tag,
    data: u32,
}) = .{},
extra: std.ArrayListUnmanaged(u32) = .{},
named: struct {
    wchar: Type = Type.invalid,
    uint_least16_t: Type = Type.invalid,
    uint_least32_t: Type = Type.invalid,
    ptrdiff: Type = Type.invalid,
    size: Type = Type.invalid,
    va_list: Type = Type.invalid,
    pid_t: Type = Type.invalid,
    ns_constant_string: Type = Type.invalid,
    file: Type = Type.invalid,
    jmp_buf: Type = Type.invalid,
    sigjmp_buf: Type = Type.invalid,
    ucontext_t: Type = Type.invalid,
    intmax: Type = Type.invalid,
    intptr: Type = Type.invalid,
    int16: Type = Type.invalid,
    int64: Type = Type.invalid,
} = .{},
target_specific: struct {
    char_sign: std.builtin.Signedness = .signed,
    short_bits: u16 = 16,
    int_bits: u16 = 32,
    long_bits: u16 = 64,
    long_long_bits: u16 = 64,
    float_bits: u16 = 32,
    double_bits: u16 = 64,
    long_double_bits: u16 = 128,
} = .{},

const KeyAdapter = struct {
    interner: *const Interner,

    pub fn eql(adapter: KeyAdapter, a: Key, b_void: void, b_map_index: usize) bool {
        _ = b_void;
        return adapter.interner.get(@as(Ref, @enumFromInt(b_map_index))).eql(a);
    }

    pub fn hash(adapter: KeyAdapter, a: Key) u32 {
        _ = adapter;
        return a.hash();
    }
};

pub const Key = union(enum) {
    /// GNU auto type
    /// This is a placeholder specifier - it must be replaced by the actual type specifier (determined by the initializer)
    auto_type: Type.Qualifiers,
    /// C23 auto, behaves like auto_type
    c23_auto: Type.Qualifiers,

    /// C23 nullptr_t
    nullptr_t: Type.Qualifiers,

    /// _Bool / bool
    bool: Type.Qualifiers,

    void: Type.Qualifiers,

    int: Int,
    complex_int: Int,
    imaginary_int: Int,

    float: Float,
    complex_float: Float,
    imaginary_float: Float,

    /// int foo(int bar, char baz) and int (void)
    func: Func,
    /// int foo(int bar, char baz, ...)
    var_args_func: Func,
    /// int foo(bar, baz) and int foo()
    /// is also var args, but we can give warnings about incorrect amounts of parameters
    old_style_func: Func,

    pointer: Pointer,
    unspecified_variable_len_array: Pointer,

    array: Array,
    static_array: Array,
    incomplete_array: Array,
    vector: Array,
    variable_len_array: Expr,

    @"struct": Record,
    @"union": Record,

    @"enum": Enum,

    /// typeof(type-name)
    typeof_type: struct {
        qual: Type.Qualifiers,
        ty: Type,
    },
    /// typeof(expression)
    typeof_expr: Expr,

    typedef: struct {
        qual: Type.Qualifiers,
        ty: Type,
        name: StringId,
    },

    decayed: struct {
        qual: Type.Qualifiers,
        ty: Type,
    },

    attributed: struct {
        qual: Type.Qualifiers,
        ty: Type,
        attributes: []const Attribute,
    },

    pub const Int = struct {
        qual: Type.Qualifiers,
        signedness: Type.Signedness,
        bits: u16,
        name: Name,

        pub const Name = enum {
            char,
            short,
            int,
            long,
            long_long,
            int128,
            bit_int,
        };
    };

    pub const Float = struct {
        qual: Type.Qualifiers,
        bits: u16,
        name: Name,
        
        pub const Name = enum {
            fp16,
            float16,
            float,
            double,
            long_double,
            float80,
            float128,
        };
    };

    pub const Func = struct {
        return_type: Type,
        params: []const Param,

        pub const Param = struct {
            ty: Type,
            name: StringId,
            name_tok: TokenIndex,
        };
    };

    pub const Pointer = struct {
        qual: Type.Qualifiers,
        ty: Type,
    };

    pub const Array = struct {
        qual: Type.Qualifiers,
        elem: Type,
        len: u64,
    };

    pub const Expr = struct {
        qual: Type.Qualifiers,
        ty: Type,
        node: NodeIndex,
    };

    pub const Record = struct {
        fields: []Field,
        type_layout: Type.TypeLayout,
        field_attributes: []const []const Attribute,
        name: StringId,

        pub const Field = struct {
            ty: Type,
            name: StringId,
            /// zero for anonymous fields
            name_tok: TokenIndex = 0,
            bit_width: ?u32 = null,
            layout: Type.FieldLayout = .{
                .offset_bits = 0,
                .size_bits = 0,
            },

            pub fn isNamed(f: *const Field) bool {
                return f.name_tok != 0;
            }

            pub fn isAnonymousRecord(f: Field) bool {
                return !f.isNamed() and f.ty.isRecord();
            }

            /// false for bitfields
            pub fn isRegularField(f: *const Field) bool {
                return f.bit_width == null;
            }

            /// bit width as specified in the C source. Asserts that `f` is a bitfield.
            pub fn specifiedBitWidth(f: *const Field) u32 {
                return f.bit_width.?;
            }
        };

        pub fn isIncomplete(r: Record) bool {
            return r.fields.len == std.math.maxInt(usize);
        }

        pub fn hasFieldOfType(self: *const Record, ty: Type, comp: *const Compilation) bool {
            if (self.isIncomplete()) return false;
            for (self.fields) |f| {
                if (ty.eql(f.ty, comp, false)) return true;
            }
            return false;
        }
    };

    pub const Enum = struct {
        fields: []Field,
        tag_ty: Type,
        name: StringId,
        fixed: bool,

        pub const Field = struct {
            ty: Type,
            name: StringId,
            name_tok: TokenIndex,
            node: NodeIndex,
        };

        pub fn isIncomplete(e: Enum) bool {
            return e.fields.len == std.math.maxInt(usize);
        }
    };

    pub fn hash(key: Key) u32 {
        var hasher = Hash.init(0);
        const tag = std.meta.activeTag(key);
        std.hash.autoHash(&hasher, tag);
        switch (key) {
            inline else => |info| {
                std.hash.autoHash(&hasher, info);
            },
        }
        return @truncate(hasher.final());
    }

    pub fn eql(a: Key, b: Key) bool {
        const KeyTag = std.meta.Tag(Key);
        const a_tag: KeyTag = a;
        const b_tag: KeyTag = b;
        if (a_tag != b_tag) return false;
        switch (a) {
            inline else => |a_info, tag| {
                const b_info = @field(b, @tagName(tag));
                return std.meta.eql(a_info, b_info);
            },
        }
    }

    fn toRef(key: Key) ?Ref {
        switch (key) {
            else => {},
        }
        return null;
    }
};

pub const Ref = enum(u32) {
    /// A NaN-like poison value
    invalid = std.math.maxInt(u32),
    _,
};

pub const Tag = enum(u8) {
    /// `data` is `Type.Qualifiers`
    auto_type,
    /// `data` is `Type.Qualifiers`
    c23_auto,
    /// `data` is `Type.Qualifiers`
    nullptr_t,
    /// `data` is `Type.Qualifiers`
    bool,
    /// `data` is `Type.Qualifiers`
    void,
    /// `data` is `PackedInt`
    int,
    /// `data` is `PackedInt`
    complex_int,
    /// `data` is `PackedInt`
    imaginary_int,
    /// `data` is `PackedFloat`
    float,
    /// `data` is `PackedFloat`
    complex_float,
    /// `data` is `PackedFloat`
    imaginary_float,

    // func,
    // var_args_func,
    // old_style_func,

    // pointer: Pointer,
    // unspecified_variable_len_array: Pointer,

    // array: Array,
    // static_array: Array,
    // incomplete_array: Array,
    // vector: Array,
    // variable_len_array: Expr,

    // @"struct": Record,
    // @"union": Record,

    // @"enum": Enum,

    // /// typeof(type-name)
    // typeof_type: struct {
    //     qual: Type.Qualifiers,
    //     ty: Type,
    // },
    // /// typeof(expression)
    // typeof_expr: Expr,

    // typedef: struct {
    //     qual: Type.Qualifiers,
    //     ty: Type,
    //     name: StringId,
    // },

    // decayed: struct {
    //     qual: Type.Qualifiers,
    //     ty: Type,
    // },

    // attributed: struct {
    //     qual: Type.Qualifiers,
    //     ty: Type,
    //     attributes: []const Attribute,
    // },

    pub const PackedInt = packed struct(u32) {
        qual: Type.Qualifiers,
        signedness: Type.Signedness,
        bits: u16,
        name: Key.Int.Name,
    };

    pub const PackedFloat = packed struct(u32) {
        qual: Type.Qualifiers,
        bits: u16,
        name: Key.Float.Name,
    };
};

pub fn initNamed(i: *Interner, comp: *Compilation) void {
    // Set target specific information.
    i.target_specific.char_sign = comp.getCharSignedness();
    i.short_bits = comp.target.c_type_bit_size(.short);
    i.int_bits = comp.target.c_type_bit_size(.int);
    i.long_bits = comp.target.c_type_bit_size(.long);
    i.long_long_bits = comp.target.c_type_bit_size(.longlong);
    i.float_bits = comp.target.c_type_bit_size(.float);
    i.double_bits = comp.target.c_type_bit_size(.double);
    i.long_double_bits = comp.target.c_type_bit_size(.longdouble);

    // TODO
}

pub fn deinit(i: *Interner, gpa: Allocator) void {
    i.map.deinit(gpa);
    i.items.deinit(gpa);
    i.extra.deinit(gpa);
}

pub fn put(i: *Interner, gpa: Allocator, key: Key) !Ref {
    const adapter: KeyAdapter = .{ .interner = i };
    const gop = try i.map.getOrPutAdapted(gpa, key, adapter);
    if (gop.found_existing) return @enumFromInt(gop.index);
    try i.items.ensureUnusedCapacity(gpa, 1);

    switch (key) {}

    return @enumFromInt(gop.index);
}

fn addExtra(i: *Interner, gpa: Allocator, extra: anytype) Allocator.Error!u32 {
    const fields = @typeInfo(@TypeOf(extra)).Struct.fields;
    try i.extra.ensureUnusedCapacity(gpa, fields.len);
    return i.addExtraAssumeCapacity(extra);
}

fn addExtraAssumeCapacity(i: *Interner, extra: anytype) u32 {
    const result = @as(u32, @intCast(i.extra.items.len));
    inline for (@typeInfo(@TypeOf(extra)).Struct.fields) |field| {
        i.extra.appendAssumeCapacity(switch (field.type) {
            Ref => @intFromEnum(@field(extra, field.name)),
            u32 => @field(extra, field.name),
            else => @compileError("bad field type: " ++ @typeName(field.type)),
        });
    }
    return result;
}

pub fn get(i: *const Interner, ref: Ref) Key {
    return i.getExtra(ref, .deep);
}

pub fn getExtra(i: *const Interner, ref: Ref, search: enum { deep, shallow }) Key {
    _ = search;
    assert(ref != .invalid);
    while (true) {
        const item = i.items.get(@intFromEnum(ref));
        switch (item.tag) {}
    }
}

fn extraData(i: *const Interner, comptime T: type, index: usize) T {
    return i.extraDataTrail(T, index).data;
}

fn extraDataTrail(i: *const Interner, comptime T: type, index: usize) struct { data: T, end: u32 } {
    var result: T = undefined;
    const fields = @typeInfo(T).Struct.fields;
    inline for (fields, 0..) |field, field_i| {
        const int32 = i.extra.items[field_i + index];
        @field(result, field.name) = switch (field.type) {
            Ref => @enumFromInt(int32),
            u32 => int32,
            else => @compileError("bad field type: " ++ @typeName(field.type)),
        };
    }
    return .{
        .data = result,
        .end = @intCast(index + fields.len),
    };
}
