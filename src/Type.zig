const std = @import("std");
const Tree = @import("Tree.zig");
const TokenIndex = Tree.TokenIndex;
const NodeIndex = Tree.NodeIndex;
const Parser = @import("Parser.zig");
const Compilation = @import("Compilation.zig");

const Type = @This();

pub const Qualifiers = packed struct {
    @"const": bool = false,
    atomic: bool = false,
    @"volatile": bool = false,

    // for function parameters only, stored here since it fits in the padding
    register: bool = false,
    restrict: bool = false,

    pub fn any(quals: Qualifiers) bool {
        return quals.@"const" or quals.restrict or quals.@"volatile" or quals.atomic;
    }

    pub fn dump(quals: Qualifiers, w: anytype) !void {
        if (quals.@"const") try w.writeAll("const ");
        if (quals.atomic) try w.writeAll("_Atomic ");
        if (quals.@"volatile") try w.writeAll("volatile ");
        if (quals.restrict) try w.writeAll("restrict ");
        if (quals.register) try w.writeAll("register ");
    }

    /// Merge the const/volatile qualifiers
    pub fn mergeCV(a: Qualifiers, b: Qualifiers) Qualifiers {
        return .{
            .@"const" = a.@"const" or b.@"const",
            .@"volatile" = a.@"volatile" or b.@"volatile",
        };
    }

    pub const Builder = struct {
        @"const": ?TokenIndex = null,
        atomic: ?TokenIndex = null,
        @"volatile": ?TokenIndex = null,
        restrict: ?TokenIndex = null,

        pub fn finish(b: Qualifiers.Builder, p: *Parser, ty: *Type) !void {
            if (ty.specifier != .pointer and b.restrict != null) {
                try p.errStr(.restrict_non_pointer, b.restrict.?, try p.typeStr(ty.*));
            }
            if (b.atomic) |some| {
                if (ty.isArray()) try p.errStr(.atomic_array, some, try p.typeStr(ty.*));
                if (ty.isFunc()) try p.errStr(.atomic_func, some, try p.typeStr(ty.*));
                if (ty.hasIncompleteSize()) try p.errStr(.atomic_incomplete, some, try p.typeStr(ty.*));
            }

            ty.qual = .{
                .@"const" = b.@"const" != null,
                .atomic = b.atomic != null,
                .@"volatile" = b.@"volatile" != null,
                .restrict = b.restrict != null,
            };
        }
    };
};

// TODO improve memory usage
pub const Func = struct {
    return_type: Type,
    params: []Param,

    pub const Param = struct {
        name: []const u8,
        ty: Type,
        name_tok: TokenIndex,
    };
};

pub const Array = struct {
    len: u64,
    elem: Type,
};

pub const VLA = struct {
    expr: NodeIndex,
    elem: Type,
};

// TODO improve memory usage
pub const Enum = struct {
    name: []const u8,
    tag_ty: Type,
    fields: []Field,

    pub const Field = struct {
        name: []const u8,
        ty: Type,
        value: u64,
    };

    pub fn isIncomplete(e: Enum) bool {
        return e.fields.len == std.math.maxInt(usize);
    }

    pub fn create(allocator: *std.mem.Allocator, name: []const u8) !*Enum {
        var e = try allocator.create(Enum);
        e.name = name;
        e.fields.len = std.math.maxInt(usize);
        return e;
    }
};

// TODO improve memory usage
pub const Record = struct {
    name: []const u8,
    fields: []Field,
    size: u32,
    alignment: u32,

    pub const Field = struct {
        name: []const u8,
        ty: Type,
        bit_width: u32,
    };

    pub fn isIncomplete(r: Record) bool {
        return r.fields.len == std.math.maxInt(usize);
    }

    pub fn create(allocator: *std.mem.Allocator, name: []const u8) !*Record {
        var r = try allocator.create(Record);
        r.name = name;
        r.fields.len = std.math.maxInt(usize);
        return r;
    }
};

pub const Specifier = enum {
    void,
    bool,

    // integers
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

    // floating point numbers
    float,
    double,
    long_double,
    complex_float,
    complex_double,
    complex_long_double,

    // data.sub_type
    pointer,
    unspecified_variable_len_array,
    decayed_unspecified_variable_len_array,
    // data.func
    /// int foo(int bar, char baz) and int (void)
    func,
    /// int foo(int bar, char baz, ...)
    var_args_func,
    /// int foo(bar, baz) and int foo()
    /// is also var args, but we can give warnings about incorrect amounts of parameters
    old_style_func,

    // data.array
    array,
    decayed_array,
    static_array,
    decayed_static_array,
    incomplete_array,
    decayed_incomplete_array,
    // data.vla
    variable_len_array,
    decayed_variable_len_array,

    // data.record
    @"struct",
    @"union",

    // data.enum
    @"enum",
};

/// All fields of Type except data may be mutated
data: union {
    sub_type: *Type,
    func: *Func,
    array: *Array,
    vla: *VLA,
    @"enum": *Enum,
    record: *Record,
    none: void,
} = .{ .none = {} },
/// user requested alignment, to get type alignment use `alignof`
alignment: u32 = 0,
specifier: Specifier,
qual: Qualifiers = .{},

pub fn isCallable(ty: Type) ?Type {
    return switch (ty.specifier) {
        .func, .var_args_func, .old_style_func => ty,
        .pointer => if (ty.data.sub_type.isFunc()) ty.data.sub_type.* else null,
        else => null,
    };
}

pub fn isFunc(ty: Type) bool {
    return switch (ty.specifier) {
        .func, .var_args_func, .old_style_func => true,
        else => false,
    };
}

pub fn isArray(ty: Type) bool {
    return switch (ty.specifier) {
        .array, .static_array, .incomplete_array, .variable_len_array, .unspecified_variable_len_array => true,
        else => false,
    };
}

pub fn isPtr(ty: Type) bool {
    return switch (ty.specifier) {
        .pointer, .decayed_array, .decayed_static_array, .decayed_incomplete_array, .decayed_variable_len_array, .decayed_unspecified_variable_len_array => true,
        else => false,
    };
}

pub fn isInt(ty: Type) bool {
    return switch (ty.specifier) {
        .@"enum", .bool, .char, .schar, .uchar, .short, .ushort, .int, .uint, .long, .ulong, .long_long, .ulong_long => true,
        else => false,
    };
}

pub fn isFloat(ty: Type) bool {
    return switch (ty.specifier) {
        .float, .double, .long_double, .complex_float, .complex_double, .complex_long_double => true,
        else => false,
    };
}

pub fn isReal(ty: Type) bool {
    return switch (ty.specifier) {
        .complex_float, .complex_double, .complex_long_double => false,
        else => true,
    };
}

pub fn isVoidStar(ty: Type) bool {
    return switch (ty.specifier) {
        .pointer => ty.data.sub_type.specifier == .void,
        else => false,
    };
}

pub fn isUnsignedInt(ty: Type, comp: *Compilation) bool {
    _ = comp;
    return switch (ty.specifier) {
        .char => return false, // TODO check comp for char signedness
        .uchar, .ushort, .uint, .ulong, .ulong_long => return true,
        else => false,
    };
}

pub fn isEnumOrRecord(ty: Type) bool {
    return switch (ty.specifier) {
        .@"enum", .@"struct", .@"union" => true,
        else => false,
    };
}

pub fn elemType(ty: Type) Type {
    return switch (ty.specifier) {
        .pointer, .unspecified_variable_len_array, .decayed_unspecified_variable_len_array => ty.data.sub_type.*,
        .array, .static_array, .incomplete_array, .decayed_array, .decayed_static_array, .decayed_incomplete_array => ty.data.array.elem,
        .variable_len_array, .decayed_variable_len_array => ty.data.vla.elem,
        else => unreachable,
    };
}

pub fn eitherLongDouble(a: Type, b: Type) ?Type {
    if (a.specifier == .long_double or a.specifier == .complex_long_double) return a;
    if (b.specifier == .long_double or b.specifier == .complex_long_double) return b;
    return null;
}

pub fn eitherDouble(a: Type, b: Type) ?Type {
    if (a.specifier == .double or a.specifier == .complex_double) return a;
    if (b.specifier == .double or b.specifier == .complex_double) return b;
    return null;
}

pub fn eitherFloat(a: Type, b: Type) ?Type {
    if (a.specifier == .float or a.specifier == .complex_float) return a;
    if (b.specifier == .float or b.specifier == .complex_float) return b;
    return null;
}

pub fn integerPromotion(ty: Type, comp: *Compilation) Type {
    return .{
        .specifier = switch (ty.specifier) {
            .bool, .char, .schar, .uchar, .short => .int,
            .ushort => if (ty.sizeof(comp).? == sizeof(.{ .specifier = .int }, comp)) Specifier.uint else .int,
            .int => .int,
            .uint => .uint,
            .long => .long,
            .ulong => .ulong,
            .long_long => .long_long,
            .ulong_long => .ulong_long,
            else => unreachable, // not an integer type
        },
    };
}

pub fn wideChar(comp: *Compilation) Type {
    _ = comp;
    // TODO get target from compilation
    return .{ .specifier = .int };
}

pub fn ptrDiffT(comp: *Compilation) Type {
    _ = comp;
    // TODO get target from compilation
    return .{ .specifier = .long };
}

pub fn sizeT(comp: *Compilation) Type {
    _ = comp;
    // TODO get target from compilation
    return .{ .specifier = .ulong };
}

pub fn hasIncompleteSize(ty: Type) bool {
    return switch (ty.specifier) {
        .void, .incomplete_array => true,
        .@"enum" => ty.data.@"enum".isIncomplete(),
        .@"struct", .@"union" => ty.data.record.isIncomplete(),
        else => false,
    };
}

/// Size of type as reported by sizeof
pub fn sizeof(ty: Type, comp: *Compilation) ?u32 {
    // TODO get target from compilation
    return switch (ty.specifier) {
        .variable_len_array, .unspecified_variable_len_array, .incomplete_array => return null,
        .func, .var_args_func, .old_style_func, .void, .bool => 1,
        .char, .schar, .uchar => 1,
        .short, .ushort => 2,
        .int, .uint => 4,
        .long, .ulong => switch (comp.target.os.tag) {
            .linux,
            .macos,
            .freebsd,
            .netbsd,
            .dragonfly,
            .openbsd,
            .wasi,
            .emscripten,
            => comp.target.cpu.arch.ptrBitWidth() >> 3,
            .windows, .uefi => 4,
            else => 4,
        },
        .long_long, .ulong_long => 8,
        .float => 4,
        .double => 8,
        .long_double => 16,
        .complex_float => 8,
        .complex_double => 16,
        .complex_long_double => 32,
        .pointer,
        .decayed_array,
        .decayed_static_array,
        .decayed_incomplete_array,
        .decayed_variable_len_array,
        .decayed_unspecified_variable_len_array,
        .static_array,
        => comp.target.cpu.arch.ptrBitWidth() >> 3,
        .array => ty.data.array.elem.sizeof(comp).? * @intCast(u32, ty.data.array.len),
        .@"struct", .@"union" => if (ty.data.record.isIncomplete()) null else ty.data.record.size,
        .@"enum" => if (ty.data.@"enum".isIncomplete()) null else ty.data.@"enum".tag_ty.sizeof(comp),
    };
}

/// Get the alignment of a type
pub fn alignof(ty: Type, comp: *Compilation) u32 {
    if (ty.alignment != 0) return ty.alignment;
    // TODO get target from compilation
    return switch (ty.specifier) {
        .unspecified_variable_len_array => unreachable, // must be bound in function definition
        .variable_len_array, .incomplete_array => ty.elemType().alignof(comp),
        .func, .var_args_func, .old_style_func => 4, // TODO check target
        .char, .schar, .uchar, .void, .bool => 1,
        .short, .ushort => 2,
        .int, .uint => 4,
        .long, .ulong => switch (comp.target.os.tag) {
            .linux,
            .macos,
            .freebsd,
            .netbsd,
            .dragonfly,
            .openbsd,
            .wasi,
            .emscripten,
            => comp.target.cpu.arch.ptrBitWidth() >> 3,
            .windows, .uefi => 4,
            else => 4,
        },
        .long_long, .ulong_long => 8,
        .float, .complex_float => 4,
        .double, .complex_double => 8,
        .long_double, .complex_long_double => 16,
        .pointer,
        .decayed_array,
        .decayed_static_array,
        .decayed_incomplete_array,
        .decayed_variable_len_array,
        .decayed_unspecified_variable_len_array,
        .static_array,
        => comp.target.cpu.arch.ptrBitWidth() >> 3,
        .array => ty.data.array.elem.alignof(comp),
        .@"struct", .@"union" => if (ty.data.record.isIncomplete()) 0 else ty.data.record.alignment,
        .@"enum" => if (ty.data.@"enum".isIncomplete()) 0 else ty.data.@"enum".tag_ty.alignof(comp),
    };
}

pub fn eql(a: Type, b: Type, check_qualifiers: bool) bool {
    if (a.alignment != b.alignment) return false;
    if (a.specifier != b.specifier) return false;

    if (a.qual.atomic != b.qual.atomic) return false;
    if (check_qualifiers) {
        if (a.qual.@"const" != b.qual.@"const") return false;
        if (a.qual.@"volatile" != b.qual.@"volatile") return false;
    }

    switch (a.specifier) {
        .pointer,
        .decayed_array,
        .decayed_static_array,
        .decayed_incomplete_array,
        .decayed_variable_len_array,
        .decayed_unspecified_variable_len_array,
        => if (!a.elemType().eql(b.elemType(), check_qualifiers)) return false,

        .func,
        .var_args_func,
        .old_style_func,
        => {
            // TODO validate this
            if (a.data.func.params.len != b.data.func.params.len) return false;
            if (!a.data.func.return_type.eql(b.data.func.return_type, check_qualifiers)) return false;
            for (a.data.func.params) |param, i| {
                if (!param.ty.eql(b.data.func.params[i].ty, check_qualifiers)) return false;
            }
        },

        .array,
        .static_array,
        .incomplete_array,
        => {
            if (a.data.array.len != b.data.array.len) return false;
            if (!a.data.array.elem.eql(b.data.array.elem, check_qualifiers)) return false;
        },
        .variable_len_array => if (!a.data.vla.elem.eql(b.data.vla.elem, check_qualifiers)) return false,

        .@"struct", .@"union" => if (a.data.record != b.data.record) return false,
        .@"enum" => if (a.data.@"enum" != b.data.@"enum") return false,

        else => {},
    }
    return true;
}

/// Decays an array to a pointer
pub fn decayArray(ty: *Type) void {
    // the decayed array type is the current specifier +1
    ty.specifier = @intToEnum(Type.Specifier, @enumToInt(ty.specifier) + 1);
}

pub fn combine(inner: *Type, outer: Type, p: *Parser, source_tok: TokenIndex) Parser.Error!void {
    switch (inner.specifier) {
        .pointer => return inner.data.sub_type.combine(outer, p, source_tok),
        .unspecified_variable_len_array => return p.todo("combine [*] array"),
        .variable_len_array => {
            try inner.data.vla.elem.combine(outer, p, source_tok);

            const elem_ty = inner.data.vla.elem;
            if (elem_ty.hasIncompleteSize()) return p.errStr(.array_incomplete_elem, source_tok, try p.typeStr(elem_ty));
            if (elem_ty.isFunc()) return p.errTok(.array_func_elem, source_tok);
            if (elem_ty.qual.any() and elem_ty.isArray()) return p.errTok(.qualifier_non_outermost_array, source_tok);
        },
        .array, .static_array, .incomplete_array => {
            try inner.data.array.elem.combine(outer, p, source_tok);

            const elem_ty = inner.data.array.elem;
            if (elem_ty.hasIncompleteSize()) return p.errStr(.array_incomplete_elem, source_tok, try p.typeStr(elem_ty));
            if (elem_ty.isFunc()) return p.errTok(.array_func_elem, source_tok);
            if (elem_ty.specifier == .static_array and elem_ty.isArray()) return p.errTok(.static_non_outermost_array, source_tok);
            if (elem_ty.qual.any() and elem_ty.isArray()) return p.errTok(.qualifier_non_outermost_array, source_tok);
        },
        .func, .var_args_func, .old_style_func => {
            try inner.data.func.return_type.combine(outer, p, source_tok);
            if (inner.data.func.return_type.isArray()) return p.errTok(.func_cannot_return_array, source_tok);
            if (inner.data.func.return_type.isFunc()) return p.errTok(.func_cannot_return_func, source_tok);
        },
        .decayed_array,
        .decayed_static_array,
        .decayed_incomplete_array,
        .decayed_variable_len_array,
        .decayed_unspecified_variable_len_array,
        => unreachable, // type should not be able to decay before being combined
        else => inner.* = outer,
    }
}

/// An unfinished Type
pub const Builder = struct {
    typedef: ?struct {
        tok: TokenIndex,
        ty: Type,
    } = null,
    specifier: Builder.Specifier = .none,
    qual: Qualifiers.Builder = .{},
    alignment: u32 = 0,
    align_tok: ?TokenIndex = null,

    pub const Specifier = union(enum) {
        none,
        void,
        bool,
        char,
        schar,
        uchar,

        unsigned,
        signed,
        short,
        sshort,
        ushort,
        short_int,
        sshort_int,
        ushort_int,
        int,
        sint,
        uint,
        long,
        slong,
        ulong,
        long_int,
        slong_int,
        ulong_int,
        long_long,
        slong_long,
        ulong_long,
        long_long_int,
        slong_long_int,
        ulong_long_int,

        float,
        double,
        long_double,
        complex,
        complex_long,
        complex_float,
        complex_double,
        complex_long_double,

        pointer: *Type,
        unspecified_variable_len_array: *Type,
        decayed_unspecified_variable_len_array: *Type,
        func: *Func,
        var_args_func: *Func,
        old_style_func: *Func,
        array: *Array,
        decayed_array: *Array,
        static_array: *Array,
        decayed_static_array: *Array,
        incomplete_array: *Array,
        decayed_incomplete_array: *Array,
        variable_len_array: *VLA,
        decayed_variable_len_array: *VLA,
        @"struct": *Record,
        @"union": *Record,
        @"enum": *Enum,

        pub fn str(spec: Builder.Specifier) ?[]const u8 {
            return switch (spec) {
                .none => unreachable,
                .void => "void",
                .bool => "_Bool",
                .char => "char",
                .schar => "signed char",
                .uchar => "unsigned char",
                .unsigned => "unsigned",
                .signed => "signed",
                .short => "short",
                .ushort => "unsigned short",
                .sshort => "signed short",
                .short_int => "short int",
                .sshort_int => "signed short int",
                .ushort_int => "unsigned short int",
                .int => "int",
                .sint => "signed int",
                .uint => "unsigned int",
                .long => "long",
                .slong => "signed long",
                .ulong => "unsigned long",
                .long_int => "long int",
                .slong_int => "signed long int",
                .ulong_int => "unsigned long int",
                .long_long => "long long",
                .slong_long => "signed long long",
                .ulong_long => "unsigned long long",
                .long_long_int => "long long int",
                .slong_long_int => "signed long long int",
                .ulong_long_int => "unsigned long long int",

                .float => "float",
                .double => "double",
                .long_double => "long double",
                .complex => "_Complex",
                .complex_long => "_Complex long",
                .complex_float => "_Complex float",
                .complex_double => "_Complex double",
                .complex_long_double => "_Complex long double",

                else => null,
            };
        }
    };

    pub fn finish(b: Builder, p: *Parser) Parser.Error!Type {
        var ty: Type = .{ .specifier = undefined };
        switch (b.specifier) {
            .none => {
                ty.specifier = .int;
                try p.err(.missing_type_specifier);
            },
            .void => ty.specifier = .void,
            .bool => ty.specifier = .bool,
            .char => ty.specifier = .char,
            .schar => ty.specifier = .schar,
            .uchar => ty.specifier = .uchar,

            .unsigned => ty.specifier = .uint,
            .signed => ty.specifier = .int,
            .short_int, .sshort_int, .short, .sshort => ty.specifier = .short,
            .ushort, .ushort_int => ty.specifier = .ushort,
            .int, .sint => ty.specifier = .int,
            .uint => ty.specifier = .uint,
            .long, .slong, .long_int, .slong_int => ty.specifier = .long,
            .ulong, .ulong_int => ty.specifier = .ulong,
            .long_long, .slong_long, .long_long_int, .slong_long_int => ty.specifier = .long_long,
            .ulong_long, .ulong_long_int => ty.specifier = .ulong_long,

            .float => ty.specifier = .float,
            .double => ty.specifier = .double,
            .long_double => ty.specifier = .long_double,
            .complex_float => ty.specifier = .complex_float,
            .complex_double => ty.specifier = .complex_double,
            .complex_long_double => ty.specifier = .complex_long_double,
            .complex, .complex_long => {
                try p.errExtra(.type_is_invalid, p.tok_i, .{ .str = b.specifier.str().? });
                return error.ParsingFailed;
            },

            .pointer => |data| {
                ty.specifier = .pointer;
                ty.data = .{ .sub_type = data };
            },
            .unspecified_variable_len_array => |data| {
                ty.specifier = .unspecified_variable_len_array;
                ty.data = .{ .sub_type = data };
            },
            .decayed_unspecified_variable_len_array => |data| {
                ty.specifier = .decayed_unspecified_variable_len_array;
                ty.data = .{ .sub_type = data };
            },
            .func => |data| {
                ty.specifier = .func;
                ty.data = .{ .func = data };
            },
            .var_args_func => |data| {
                ty.specifier = .var_args_func;
                ty.data = .{ .func = data };
            },
            .old_style_func => |data| {
                ty.specifier = .old_style_func;
                ty.data = .{ .func = data };
            },
            .array => |data| {
                ty.specifier = .array;
                ty.data = .{ .array = data };
            },
            .decayed_array => |data| {
                ty.specifier = .decayed_array;
                ty.data = .{ .array = data };
            },
            .static_array => |data| {
                ty.specifier = .static_array;
                ty.data = .{ .array = data };
            },
            .decayed_static_array => |data| {
                ty.specifier = .decayed_static_array;
                ty.data = .{ .array = data };
            },
            .incomplete_array => |data| {
                ty.specifier = .incomplete_array;
                ty.data = .{ .array = data };
            },
            .decayed_incomplete_array => |data| {
                ty.specifier = .decayed_incomplete_array;
                ty.data = .{ .array = data };
            },
            .variable_len_array => |data| {
                ty.specifier = .variable_len_array;
                ty.data = .{ .vla = data };
            },
            .decayed_variable_len_array => |data| {
                ty.specifier = .decayed_variable_len_array;
                ty.data = .{ .vla = data };
            },
            .@"struct" => |data| {
                ty.specifier = .@"struct";
                ty.data = .{ .record = data };
            },
            .@"union" => |data| {
                ty.specifier = .@"union";
                ty.data = .{ .record = data };
            },
            .@"enum" => |data| {
                ty.specifier = .@"enum";
                ty.data = .{ .@"enum" = data };
            },
        }
        try b.qual.finish(p, &ty);
        if (b.align_tok) |align_tok| {
            const default = ty.alignof(p.pp.comp);
            if (ty.isFunc()) {
                try p.errTok(.alignas_on_func, align_tok);
            } else if (b.alignment != 0 and b.alignment < default) {
                try p.errExtra(.minimum_alignment, align_tok, .{ .unsigned = default });
            } else {
                ty.alignment = b.alignment;
            }
        }
        return ty;
    }

    pub fn cannotCombine(b: Builder, p: *Parser, source_tok: TokenIndex) Compilation.Error!void {
        const prev_ty = b.finish(p) catch unreachable;
        try p.errExtra(.cannot_combine_spec, source_tok, .{ .str = try p.typeStr(prev_ty) });
        if (b.typedef) |some| try p.errStr(.spec_from_typedef, some.tok, try p.typeStr(some.ty));
    }

    pub fn combine(b: *Builder, p: *Parser, new: Builder.Specifier, source_tok: TokenIndex) Compilation.Error!void {
        switch (new) {
            else => switch (b.specifier) {
                .none => b.specifier = new,
                else => return b.cannotCombine(p, source_tok),
            },
            .signed => b.specifier = switch (b.specifier) {
                .none => .signed,
                .char => .schar,
                .short => .sshort,
                .short_int => .sshort_int,
                .int => .sint,
                .long => .slong,
                .long_int => .slong_int,
                .long_long => .slong_long,
                .long_long_int => .slong_long_int,
                .sshort,
                .sshort_int,
                .sint,
                .slong,
                .slong_int,
                .slong_long,
                .slong_long_int,
                => return p.errStr(.duplicate_decl_spec, p.tok_i, "signed"),
                else => return b.cannotCombine(p, source_tok),
            },
            .unsigned => b.specifier = switch (b.specifier) {
                .none => .unsigned,
                .char => .uchar,
                .short => .ushort,
                .short_int => .ushort_int,
                .int => .uint,
                .long => .ulong,
                .long_int => .ulong_int,
                .long_long => .ulong_long,
                .long_long_int => .ulong_long_int,
                .ushort,
                .ushort_int,
                .uint,
                .ulong,
                .ulong_int,
                .ulong_long,
                .ulong_long_int,
                => return p.errStr(.duplicate_decl_spec, p.tok_i, "unsigned"),
                else => return b.cannotCombine(p, source_tok),
            },
            .char => b.specifier = switch (b.specifier) {
                .none => .char,
                .unsigned => .uchar,
                .signed => .schar,
                .char, .schar, .uchar => return p.errStr(.duplicate_decl_spec, p.tok_i, "char"),
                else => return b.cannotCombine(p, source_tok),
            },
            .short => b.specifier = switch (b.specifier) {
                .none => .short,
                .unsigned => .ushort,
                .signed => .sshort,
                else => return b.cannotCombine(p, source_tok),
            },
            .int => b.specifier = switch (b.specifier) {
                .none => .int,
                .signed => .sint,
                .unsigned => .uint,
                .short => .short_int,
                .sshort => .sshort_int,
                .ushort => .ushort_int,
                .long => .long_int,
                .slong => .slong_int,
                .ulong => .ulong_int,
                .long_long => .long_long_int,
                .slong_long => .slong_long_int,
                .ulong_long => .ulong_long_int,
                .int,
                .sint,
                .uint,
                .short_int,
                .sshort_int,
                .ushort_int,
                .long_int,
                .slong_int,
                .ulong_int,
                .long_long_int,
                .slong_long_int,
                .ulong_long_int,
                => return p.errStr(.duplicate_decl_spec, p.tok_i, "int"),
                else => return b.cannotCombine(p, source_tok),
            },
            .long => b.specifier = switch (b.specifier) {
                .none => .long,
                .long => .long_long,
                .unsigned => .ulong,
                .signed => .long,
                .int => .long_int,
                .sint => .slong_int,
                .ulong => .ulong_long,
                .long_long, .ulong_long => return p.errStr(.duplicate_decl_spec, p.tok_i, "long"),
                else => return b.cannotCombine(p, source_tok),
            },
            .float => b.specifier = switch (b.specifier) {
                .none => .float,
                .complex => .complex_float,
                .complex_float, .float => return p.errStr(.duplicate_decl_spec, p.tok_i, "float"),
                else => return b.cannotCombine(p, source_tok),
            },
            .double => b.specifier = switch (b.specifier) {
                .none => .double,
                .long => .long_double,
                .complex_long => .complex_long_double,
                .complex => .complex_double,
                .long_double,
                .complex_long_double,
                .complex_double,
                .double,
                => return p.errStr(.duplicate_decl_spec, p.tok_i, "double"),
                else => return b.cannotCombine(p, source_tok),
            },
            .complex => b.specifier = switch (b.specifier) {
                .none => .complex,
                .long => .complex_long,
                .float => .complex_float,
                .double => .complex_double,
                .long_double => .complex_long_double,
                .complex,
                .complex_long,
                .complex_float,
                .complex_double,
                .complex_long_double,
                => return p.errStr(.duplicate_decl_spec, p.tok_i, "_Complex"),
                else => return b.cannotCombine(p, source_tok),
            },
        }
    }

    pub fn fromType(ty: Type) Builder.Specifier {
        return switch (ty.specifier) {
            .void => .void,
            .bool => .bool,
            .char => .char,
            .schar => .schar,
            .uchar => .uchar,
            .short => .short,
            .ushort => .ushort,
            .int => .int,
            .uint => .uint,
            .long => .long,
            .ulong => .ulong,
            .long_long => .long_long,
            .ulong_long => .ulong_long,
            .float => .float,
            .double => .double,
            .long_double => .long_double,
            .complex_float => .complex_float,
            .complex_double => .complex_double,
            .complex_long_double => .complex_long_double,

            .pointer => .{ .pointer = ty.data.sub_type },
            .unspecified_variable_len_array => .{ .unspecified_variable_len_array = ty.data.sub_type },
            .decayed_unspecified_variable_len_array => .{ .decayed_unspecified_variable_len_array = ty.data.sub_type },
            .func => .{ .func = ty.data.func },
            .var_args_func => .{ .var_args_func = ty.data.func },
            .old_style_func => .{ .old_style_func = ty.data.func },
            .array => .{ .array = ty.data.array },
            .decayed_array => .{ .decayed_array = ty.data.array },
            .static_array => .{ .static_array = ty.data.array },
            .decayed_static_array => .{ .decayed_static_array = ty.data.array },
            .incomplete_array => .{ .incomplete_array = ty.data.array },
            .decayed_incomplete_array => .{ .decayed_incomplete_array = ty.data.array },
            .variable_len_array => .{ .variable_len_array = ty.data.vla },
            .decayed_variable_len_array => .{ .decayed_variable_len_array = ty.data.vla },
            .@"struct" => .{ .@"struct" = ty.data.record },
            .@"union" => .{ .@"union" = ty.data.record },
            .@"enum" => .{ .@"enum" = ty.data.@"enum" },
        };
    }
};

/// Print type in C style
pub fn print(ty: Type, w: anytype) @TypeOf(w).Error!void {
    _ = try ty.printPrologue(w);
    try ty.printEpilogue(w);
}

/// return true if `ty` is simple
fn printPrologue(ty: Type, w: anytype) @TypeOf(w).Error!bool {
    if (ty.qual.atomic) {
        var non_atomic_ty = ty;
        non_atomic_ty.qual.atomic = false;
        try w.writeAll("_Atomic(");
        try non_atomic_ty.print(w);
        try w.writeAll(")");
        return true;
    }
    switch (ty.specifier) {
        .pointer,
        .decayed_array,
        .decayed_static_array,
        .decayed_incomplete_array,
        .decayed_variable_len_array,
        .decayed_unspecified_variable_len_array,
        => {
            const elem_ty = ty.elemType();
            const simple = try elem_ty.printPrologue(w);
            if (simple) try w.writeByte(' ');
            if (elem_ty.isFunc() or elem_ty.isArray()) try w.writeByte('(');
            try w.writeByte('*');
            try ty.qual.dump(w);
            if (ty.alignment != 0) try w.print(" _Alignas({d})", .{ty.alignment});
            return false;
        },
        .func, .var_args_func, .old_style_func => {
            const ret_ty = ty.data.func.return_type;
            const simple = try ret_ty.printPrologue(w);
            if (simple) try w.writeByte(' ');
            return false;
        },
        .array, .static_array, .incomplete_array, .unspecified_variable_len_array, .variable_len_array => {
            const elem_ty = ty.elemType();
            const simple = try elem_ty.printPrologue(w);
            if (simple) try w.writeByte(' ');
            return false;
        },
        .@"enum" => try w.print("enum {s}", .{ty.data.@"enum".name}),
        .@"struct" => try w.print("struct {s}", .{ty.data.record.name}),
        .@"union" => try w.print("union {s}", .{ty.data.record.name}),
        else => try w.writeAll(Builder.fromType(ty).str().?),
    }
    try ty.qual.dump(w);
    if (ty.alignment != 0) try w.print(" _Alignas({d})", .{ty.alignment});
    return true;
}

fn printEpilogue(ty: Type, w: anytype) @TypeOf(w).Error!void {
    if (ty.qual.atomic) return;
    switch (ty.specifier) {
        .pointer,
        .decayed_array,
        .decayed_static_array,
        .decayed_incomplete_array,
        .decayed_variable_len_array,
        .decayed_unspecified_variable_len_array,
        => {
            const elem_ty = ty.elemType();
            if (elem_ty.isFunc() or elem_ty.isArray()) try w.writeByte(')');
            try elem_ty.printEpilogue(w);
        },
        .func, .var_args_func, .old_style_func => {
            try w.writeByte('(');
            for (ty.data.func.params) |param, i| {
                if (i != 0) try w.writeAll(", ");
                _ = try param.ty.printPrologue(w);
                if (param.name.len != 0) try w.writeAll(param.name);
                try param.ty.printEpilogue(w);
            }
            if (ty.specifier != .func) {
                if (ty.data.func.params.len != 0) try w.writeAll(", ");
                try w.writeAll("...");
            } else if (ty.data.func.params.len == 0) {
                try w.writeAll("void");
            }
            try w.writeByte(')');
            try ty.data.func.return_type.printEpilogue(w);
        },
        .array, .static_array => {
            try w.writeByte('[');
            if (ty.specifier == .static_array) try w.writeAll("static ");
            try ty.qual.dump(w);
            if (ty.alignment != 0) try w.print(" _Alignas({d})", .{ty.alignment});
            try w.print("{d}]", .{ty.data.array.len});
            try ty.data.array.elem.printEpilogue(w);
        },
        .incomplete_array => {
            try w.writeByte('[');
            try ty.qual.dump(w);
            if (ty.alignment != 0) try w.print(" _Alignas({d})", .{ty.alignment});
            try w.writeByte(']');
            try ty.data.array.elem.printEpilogue(w);
        },
        .unspecified_variable_len_array => {
            try w.writeByte('[');
            try ty.qual.dump(w);
            if (ty.alignment != 0) try w.print(" _Alignas({d})", .{ty.alignment});
            try w.writeAll("*]");
            try ty.data.sub_type.printEpilogue(w);
        },
        .variable_len_array => {
            try w.writeByte('[');
            try ty.qual.dump(w);
            if (ty.alignment != 0) try w.print(" _Alignas({d})", .{ty.alignment});
            try w.writeAll("<expr>]");
            try ty.data.vla.elem.printEpilogue(w);
        },
        else => {},
    }
}

/// Useful for debugging, too noisy to be enabled by default.
const dump_detailed_containers = false;

// Print as Zig types since those are actually readable
pub fn dump(ty: Type, w: anytype) @TypeOf(w).Error!void {
    try ty.qual.dump(w);
    if (ty.alignment != 0) try w.print("_Alignas({d}) ", .{ty.alignment});
    switch (ty.specifier) {
        .pointer => {
            try w.writeAll("*");
            try ty.data.sub_type.dump(w);
        },
        .func, .var_args_func, .old_style_func => {
            try w.writeAll("fn (");
            for (ty.data.func.params) |param, i| {
                if (i != 0) try w.writeAll(", ");
                if (param.name.len != 0) try w.print("{s}: ", .{param.name});
                try param.ty.dump(w);
            }
            if (ty.specifier != .func) {
                if (ty.data.func.params.len != 0) try w.writeAll(", ");
                try w.writeAll("...");
            }
            try w.writeAll(") ");
            try ty.data.func.return_type.dump(w);
        },
        .array, .static_array, .decayed_array, .decayed_static_array => {
            try w.writeByte('[');
            if (ty.specifier == .static_array or ty.specifier == .decayed_static_array) try w.writeAll("static ");
            try w.print("{d}]", .{ty.data.array.len});
            try ty.data.array.elem.dump(w);
        },
        .incomplete_array, .decayed_incomplete_array => {
            try w.writeAll("[]");
            try ty.data.array.elem.dump(w);
        },
        .@"enum" => {
            try w.print("enum {s}", .{ty.data.@"enum".name});
            if (dump_detailed_containers) try dumpEnum(ty.data.@"enum", w);
        },
        .@"struct" => {
            try w.print("struct {s}", .{ty.data.record.name});
            if (dump_detailed_containers) try dumpRecord(ty.data.record, w);
        },
        .@"union" => {
            try w.print("union {s}", .{ty.data.record.name});
            if (dump_detailed_containers) try dumpRecord(ty.data.record, w);
        },
        .unspecified_variable_len_array, .decayed_unspecified_variable_len_array => {
            try w.writeAll("[*]");
            try ty.data.array.elem.dump(w);
        },
        .variable_len_array, .decayed_variable_len_array => {
            try w.writeAll("[<expr>]");
            try ty.data.array.elem.dump(w);
        },
        else => try w.writeAll(Builder.fromType(ty).str().?),
    }
}

fn dumpEnum(@"enum": *Enum, w: anytype) @TypeOf(w).Error!void {
    try w.writeAll(" {");
    for (@"enum".fields) |field| {
        try w.print(" {s} = {d},", .{ field.name, field.value });
    }
    try w.writeAll(" }");
}

fn dumpRecord(record: *Record, w: anytype) @TypeOf(w).Error!void {
    try w.writeAll(" {");
    for (record.fields) |field| {
        try w.writeByte(' ');
        try field.ty.dump(w);
        try w.print(" {s}: {d};", .{ field.name, field.bit_width });
    }
    try w.writeAll(" }");
}
