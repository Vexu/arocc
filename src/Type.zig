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
    restrict: bool = false,

    pub fn any(quals: Qualifiers) bool {
        return quals.@"const" or quals.restrict or quals.@"volatile" or quals.atomic;
    }

    pub fn dump(quals: Qualifiers, w: anytype) !void {
        if (quals.@"const") try w.writeAll("const ");
        if (quals.atomic) try w.writeAll("_Atomic ");
        if (quals.@"volatile") try w.writeAll("volatile ");
        if (quals.restrict) try w.writeAll("restrict ");
    }
};

pub const Func = struct {
    return_type: Type,
    param_types: []NodeIndex,
};

pub const Array = struct {
    len: u64,
    elem: Type,
};

pub const VLA = struct {
    expr: NodeIndex,
    elem: Type,
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
    atomic,
    unspecified_variable_len_array,
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
    static_array,
    incomplete_array,
    // data.vla
    variable_len_array,

    // data.node
    @"struct",
    @"union",
    @"enum",
};

data: union {
    sub_type: *Type,
    func: *Func,
    array: *Array,
    vla: *VLA,
    node: NodeIndex,
    none: void,
} = .{ .none = {} },
alignment: u32 = 0,
specifier: Specifier,
qual: Qualifiers = .{},

pub fn isCallable(ty: Type) ?Type {
    return switch (ty.specifier) {
        .func, .var_args_func, .old_style_func => ty,
        .pointer => ty.data.sub_type.isCallable(),
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

pub fn isUnsignedInt(ty: Type, comp: *Compilation) bool {
    return switch (ty.specifier) {
        .char => return false, // TODO check comp for char signedness
        .uchar, .ushort, .uint, .ulong, .ulong_long => return true,
        else => false,
    };
}

pub fn wideChar(p: *Parser) Type {
    // TODO get target from compilation
    return .{ .specifier = .int };
}

pub fn hasIncompleteSize(ty: Type) bool {
    return switch (ty.specifier) {
        .void, .incomplete_array => true,
        else => false,
    };
}

/// Size of type as reported by sizeof
pub fn sizeof(ty: Type, comp: *Compilation) u64 {
    // TODO get target from compilation
    return switch (ty.specifier) {
        .variable_len_array, .unspecified_variable_len_array, .incomplete_array => unreachable, // TODO special case
        .func, .var_args_func, .old_style_func, .void, .bool => 1,
        .char, .schar, .uchar => 1,
        .short, .ushort => 2,
        .int, .uint => 4,
        .long, .ulong, .long_long, .ulong_long => 8,
        .float => 4,
        .double => 8,
        .long_double => 16,
        .complex_float => 8,
        .complex_double => 16,
        .complex_long_double => 32,
        .pointer => 8,
        .atomic => return ty.data.sub_type.sizeof(comp),
        .array, .static_array => return ty.data.sub_type.sizeof(comp) * ty.data.array.len,
        .@"struct" => @panic("TODO"),
        .@"union" => @panic("TODO"),
        .@"enum" => @panic("TODO"),
    };
}

pub fn combine(inner: *Type, outer: Type, p: *Parser, source_tok: TokenIndex) Parser.Error!void {
    switch (inner.specifier) {
        .pointer => return inner.data.sub_type.combine(outer, p, source_tok),
        .variable_len_array, .unspecified_variable_len_array => return p.todo("combine array"),
        .array, .static_array, .incomplete_array => {
            try inner.data.array.elem.combine(outer, p, source_tok);

            if (inner.data.array.elem.hasIncompleteSize()) return p.errTok(.array_incomplete_elem, source_tok);
            if (inner.data.array.elem.isFunc()) return p.errTok(.array_func_elem, source_tok);
            if (inner.data.array.elem.specifier == .static_array and inner.isArray()) return p.errTok(.static_non_outernmost_array, source_tok);
            if (inner.data.array.elem.qual.any() and inner.isArray()) return p.errTok(.qualifier_non_outernmost_array, source_tok);
        },
        .func, .var_args_func, .old_style_func => {
            try inner.data.func.return_type.combine(outer, p, source_tok);
            if (inner.data.func.return_type.isArray()) return p.errTok(.func_cannot_return_array, source_tok);
            if (inner.data.func.return_type.isFunc()) return p.errTok(.func_cannot_return_func, source_tok);
        },
        else => inner.* = outer,
    }
}

/// An unfinished Type
pub const Builder = struct {
    typedef: ?struct {
        tok: TokenIndex,
        spec: []const u8,
    } = null,
    kind: Kind = .none,

    pub const Kind = union(enum) {
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
        atomic: *Type,
        unspecified_variable_len_array: *Type,
        func: *Func,
        var_args_func: *Func,
        old_style_func: *Func,
        array: *Array,
        static_array: *Array,
        incomplete_array: *Array,
        variable_len_array: *VLA,
        @"struct": NodeIndex,
        @"union": NodeIndex,
        @"enum": NodeIndex,

        pub fn str(spec: Kind) []const u8 {
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

                // TODO make these more specific?
                .pointer => "pointer",
                .atomic => "atomic",
                .func, .var_args_func, .old_style_func => "function",
                .array, .static_array, .unspecified_variable_len_array, .variable_len_array, .incomplete_array => "array",
                .@"struct" => "struct",
                .@"union" => "union",
                .@"enum" => "enum",
            };
        }
    };

    pub fn finish(spec: Builder, p: *Parser, ty: *Type) Parser.Error!void {
        ty.specifier = switch (spec.kind) {
            .none => {
                ty.specifier = .int;
                return p.err(.missing_type_specifier);
            },
            .void => .void,
            .bool => .bool,
            .char => .char,
            .schar => .schar,
            .uchar => .uchar,

            .unsigned => .uint,
            .signed => .int,
            .short_int, .sshort_int, .short, .sshort => .short,
            .ushort, .ushort_int => .ushort,
            .int, .sint => .int,
            .uint => .uint,
            .long, .slong, .long_int, .slong_int => .long,
            .ulong, .ulong_int => .ulong,
            .long_long, .slong_long, .long_long_int, .slong_long_int => .long_long,
            .ulong_long, .ulong_long_int => .ulong_long,

            .float => .float,
            .double => .double,
            .long_double => .long_double,
            .complex_float => .complex_float,
            .complex_double => .complex_double,
            .complex_long_double => .complex_long_double,
            .complex, .complex_long => {
                try p.errExtra(.type_is_invalid, p.tok_i, .{ .str = spec.kind.str() });
                return error.ParsingFailed;
            },

            .atomic => |data| {
                ty.specifier = .atomic;
                ty.data = .{ .sub_type = data };
                return;
            },
            .pointer => |data| {
                ty.specifier = .pointer;
                ty.data = .{ .sub_type = data };
                return;
            },
            .unspecified_variable_len_array => |data| {
                ty.specifier = .unspecified_variable_len_array;
                ty.data = .{ .sub_type = data };
                return;
            },
            .func => |data| {
                ty.specifier = .func;
                ty.data = .{ .func = data };
                return;
            },
            .var_args_func => |data| {
                ty.specifier = .var_args_func;
                ty.data = .{ .func = data };
                return;
            },
            .old_style_func => |data| {
                ty.specifier = .old_style_func;
                ty.data = .{ .func = data };
                return;
            },
            .array => |data| {
                ty.specifier = .array;
                ty.data = .{ .array = data };
                return;
            },
            .static_array => |data| {
                ty.specifier = .static_array;
                ty.data = .{ .array = data };
                return;
            },
            .incomplete_array => |data| {
                ty.specifier = .incomplete_array;
                ty.data = .{ .array = data };
                return;
            },
            .variable_len_array => |data| {
                ty.specifier = .variable_len_array;
                ty.data = .{ .vla = data };
                return;
            },
            .@"struct" => |data| {
                ty.specifier = .@"struct";
                ty.data = .{ .node = data };
                return;
            },
            .@"union" => |data| {
                ty.specifier = .@"union";
                ty.data = .{ .node = data };
                return;
            },
            .@"enum" => |data| {
                ty.specifier = .@"enum";
                ty.data = .{ .node = data };
                return;
            },
        };
    }

    pub fn cannotCombine(spec: Builder, p: *Parser) Parser.Error {
        try p.errExtra(.cannot_combine_spec, p.tok_i, .{ .str = spec.kind.str() });
        if (spec.typedef) |some| try p.errStr(.sepc_from_typedef, some.tok, some.spec);
        return error.ParsingFailed;
    }

    pub fn combine(spec: *Builder, p: *Parser, new: Kind) Parser.Error!void {
        switch (new) {
            .void, .bool, .@"enum", .@"struct", .@"union", .pointer, .array, .static_array, .func, .var_args_func, .old_style_func => switch (spec.kind) {
                .none => spec.kind = new,
                else => return spec.cannotCombine(p),
            },
            .atomic => return p.todo("atomic types"),
            .signed => spec.kind = switch (spec.kind) {
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
                else => return spec.cannotCombine(p),
            },
            .unsigned => spec.kind = switch (spec.kind) {
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
                else => return spec.cannotCombine(p),
            },
            .char => spec.kind = switch (spec.kind) {
                .none => .char,
                .unsigned => .uchar,
                .signed => .schar,
                .char, .schar, .uchar => return p.errStr(.duplicate_decl_spec, p.tok_i, "float"),
                else => return spec.cannotCombine(p),
            },
            .short => spec.kind = switch (spec.kind) {
                .none => .short,
                .unsigned => .ushort,
                .signed => .sshort,
                else => return spec.cannotCombine(p),
            },
            .int => spec.kind = switch (spec.kind) {
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
                else => return spec.cannotCombine(p),
            },
            .long => spec.kind = switch (spec.kind) {
                .none => .long,
                .long => .long_long,
                .unsigned => .ulong,
                .signed => .long,
                .int => .long_int,
                .sint => .slong_int,
                .ulong => .ulong_long,
                .long_long, .ulong_long => return p.errStr(.duplicate_decl_spec, p.tok_i, "long"),
                else => return spec.cannotCombine(p),
            },
            .float => spec.kind = switch (spec.kind) {
                .none => .float,
                .complex => .complex_float,
                .complex_float, .float => return p.errStr(.duplicate_decl_spec, p.tok_i, "float"),
                else => return spec.cannotCombine(p),
            },
            .double => spec.kind = switch (spec.kind) {
                .none => .double,
                .long => .long_double,
                .complex_long => .complex_long_double,
                .complex => .complex_double,
                .long_double,
                .complex_long_double,
                .complex_double,
                .double,
                => return p.errStr(.duplicate_decl_spec, p.tok_i, "double"),
                else => return spec.cannotCombine(p),
            },
            .complex => spec.kind = switch (spec.kind) {
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
                else => return spec.cannotCombine(p),
            },
            else => unreachable,
        }
    }

    pub fn fromType(ty: Type) Kind {
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
            .atomic => .{ .atomic = ty.data.sub_type },
            .unspecified_variable_len_array => .{ .unspecified_variable_len_array = ty.data.sub_type },
            .func => .{ .func = ty.data.func },
            .var_args_func => .{ .var_args_func = ty.data.func },
            .old_style_func => .{ .old_style_func = ty.data.func },
            .array => .{ .array = ty.data.array },
            .static_array => .{ .static_array = ty.data.array },
            .incomplete_array => .{ .incomplete_array = ty.data.array },
            .variable_len_array => .{ .variable_len_array = ty.data.vla },
            .@"struct" => .{ .@"struct" = ty.data.node },
            .@"union" => .{ .@"union" = ty.data.node },
            .@"enum" => .{ .@"enum" = ty.data.node },
        };
    }
};

// Print as Zig types since those are actually readable
pub fn dump(ty: Type, tree: Tree, w: anytype) @TypeOf(w).Error!void {
    try ty.qual.dump(w);
    switch (ty.specifier) {
        .pointer => {
            try w.writeAll("*");
            try ty.data.sub_type.dump(tree, w);
        },
        .atomic => {
            try w.writeAll("_Atomic");
            try ty.data.sub_type.dump(tree, w);
            try w.writeAll(")");
        },
        .func, .var_args_func, .old_style_func => {
            try w.writeAll("fn (");
            for (ty.data.func.param_types) |param, i| {
                if (i != 0) try w.writeAll(", ");
                const name_tok = tree.nodes.items(.first)[param];
                if (tree.tokens.items(.id)[name_tok] == .identifier) {
                    try w.print("{s}: ", .{tree.tokSlice(name_tok)});
                }
                try tree.nodes.items(.ty)[param].dump(tree, w);
            }
            if (ty.specifier != .func) {
                if (ty.data.func.param_types.len != 0) try w.writeAll(", ");
                try w.writeAll("...");
            }
            try w.writeAll(") ");
            try ty.data.func.return_type.dump(tree, w);
        },
        .array, .static_array => {
            try w.writeByte('[');
            if (ty.specifier == .static_array) try w.writeAll("static ");
            try w.print("{d}]", .{ty.data.array.len});
            try ty.data.array.elem.dump(tree, w);
        },
        .incomplete_array => {
            try w.writeAll("[]");
            try ty.data.array.elem.dump(tree, w);
        },
        else => try w.writeAll(Builder.fromType(ty).str()),
    }
}
