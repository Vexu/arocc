const std = @import("std");

const Interner = @import("backend").Interner;

const Attribute = @import("Attribute.zig");
const CodeGen = @import("CodeGen.zig");
const Compilation = @import("Compilation.zig");
const number_affixes = @import("Tree/number_affixes.zig");
const Source = @import("Source.zig");
const StringInterner = @import("StringInterner.zig");
const Tokenizer = @import("Tokenizer.zig");
const Type = @import("Type.zig");
const Value = @import("Value.zig");

pub const Token = struct {
    id: Id,
    loc: Source.Location,

    pub const List = std.MultiArrayList(Token);
    pub const Id = Tokenizer.Token.Id;
    pub const NumberPrefix = number_affixes.Prefix;
    pub const NumberSuffix = number_affixes.Suffix;
};

pub const TokenWithExpansionLocs = struct {
    id: Token.Id,
    flags: packed struct {
        expansion_disabled: bool = false,
        is_macro_arg: bool = false,
    } = .{},
    /// This location contains the actual token slice which might be generated.
    /// If it is generated then there is guaranteed to be at least one
    /// expansion location.
    loc: Source.Location,
    expansion_locs: ?[*]Source.Location = null,

    pub fn expansionSlice(tok: TokenWithExpansionLocs) []const Source.Location {
        const locs = tok.expansion_locs orelse return &[0]Source.Location{};
        var i: usize = 0;
        while (locs[i].id != .unused) : (i += 1) {}
        return locs[0..i];
    }

    pub fn addExpansionLocation(tok: *TokenWithExpansionLocs, gpa: std.mem.Allocator, new: []const Source.Location) !void {
        if (new.len == 0 or tok.id == .whitespace or tok.id == .macro_ws or tok.id == .placemarker) return;
        var list = std.ArrayList(Source.Location).init(gpa);
        defer {
            @memset(list.items.ptr[list.items.len..list.capacity], .{});
            // Add a sentinel to indicate the end of the list since
            // the ArrayList's capacity isn't guaranteed to be exactly
            // what we ask for.
            if (list.capacity > 0) {
                list.items.ptr[list.capacity - 1].byte_offset = 1;
            }
            tok.expansion_locs = list.items.ptr;
        }

        if (tok.expansion_locs) |locs| {
            var i: usize = 0;
            while (locs[i].id != .unused) : (i += 1) {}
            list.items = locs[0..i];
            while (locs[i].byte_offset != 1) : (i += 1) {}
            list.capacity = i + 1;
        }

        const min_len = @max(list.items.len + new.len + 1, 4);
        const wanted_len = std.math.ceilPowerOfTwo(usize, min_len) catch
            return error.OutOfMemory;
        try list.ensureTotalCapacity(wanted_len);

        for (new) |new_loc| {
            if (new_loc.id == .generated) continue;
            list.appendAssumeCapacity(new_loc);
        }
    }

    pub fn free(expansion_locs: ?[*]Source.Location, gpa: std.mem.Allocator) void {
        const locs = expansion_locs orelse return;
        var i: usize = 0;
        while (locs[i].id != .unused) : (i += 1) {}
        while (locs[i].byte_offset != 1) : (i += 1) {}
        gpa.free(locs[0 .. i + 1]);
    }

    pub fn dupe(tok: TokenWithExpansionLocs, gpa: std.mem.Allocator) !TokenWithExpansionLocs {
        var copy = tok;
        copy.expansion_locs = null;
        try copy.addExpansionLocation(gpa, tok.expansionSlice());
        return copy;
    }

    pub fn checkMsEof(tok: TokenWithExpansionLocs, source: Source, comp: *Compilation) !void {
        std.debug.assert(tok.id == .eof);
        if (source.buf.len > tok.loc.byte_offset and source.buf[tok.loc.byte_offset] == 0x1A) {
            try comp.addDiagnostic(.{
                .tag = .ctrl_z_eof,
                .loc = .{
                    .id = source.id,
                    .byte_offset = tok.loc.byte_offset,
                    .line = tok.loc.line,
                },
            }, &.{});
        }
    }
};

pub const TokenIndex = u32;
pub const ValueMap = std.AutoHashMapUnmanaged(Node.Index, Value);

pub const TypeHashContext = struct {
    pub fn hash(_: TypeHashContext, ty: Type) u32 {
        var hasher = std.hash.Wyhash.init(0);

        std.hash.autoHash(&hasher, ty.specifier);
        std.hash.autoHash(&hasher, @as(u4, @bitCast(ty.qual)));
        std.hash.autoHash(&hasher, ty.decayed);
        std.hash.autoHash(&hasher, ty.name);

        switch (ty.specifier) {
            .bit_int, .complex_bit_int => std.hash.autoHash(&hasher, ty.data.int),
            .pointer,
            .unspecified_variable_len_array,
            .typeof_type,
            => std.hash.autoHash(&hasher, @intFromPtr(ty.data.sub_type)),
            .func,
            .var_args_func,
            .old_style_func,
            => std.hash.autoHash(&hasher, @intFromPtr(ty.data.func)),
            .array,
            .static_array,
            .incomplete_array,
            .vector,
            => std.hash.autoHash(&hasher, @intFromPtr(ty.data.array)),
            .variable_len_array,
            .typeof_expr,
            => std.hash.autoHash(&hasher, @intFromPtr(ty.data.expr)),
            .@"struct",
            .@"union",
            => std.hash.autoHash(&hasher, @intFromPtr(ty.data.record)),
            .@"enum",
            => std.hash.autoHash(&hasher, @intFromPtr(ty.data.@"enum")),
            .attributed,
            => std.hash.autoHash(&hasher, @intFromPtr(ty.data.attributed)),
            else => {},
        }

        return @as(u32, @truncate(hasher.final()));
    }

    pub fn eql(_: TypeHashContext, a: Type, b: Type, _: usize) bool {
        if (a.specifier != b.specifier) return false;
        if (a.qual != b.qual) return false;
        if (a.decayed != b.decayed) return false;
        if (a.name != b.name) return false;

        switch (a.specifier) {
            .bit_int, .complex_bit_int => {
                if (a.data.int.bits != b.data.int.bits) return false;
                if (a.data.int.signedness != b.data.int.signedness) return false;
            },
            .pointer,
            .unspecified_variable_len_array,
            .typeof_type,
            => if (a.data.sub_type != b.data.sub_type) return false,
            .func,
            .var_args_func,
            .old_style_func,
            => if (a.data.func != b.data.func) return false,
            .array,
            .static_array,
            .incomplete_array,
            .vector,
            => if (a.data.array != b.data.array) return false,
            .variable_len_array,
            .typeof_expr,
            => if (a.data.expr != b.data.expr) return false,
            .@"struct",
            .@"union",
            => if (a.data.record != b.data.record) return false,
            .@"enum",
            => if (a.data.@"enum" != b.data.@"enum") return false,
            .attributed,
            => if (a.data.attributed != b.data.attributed) return false,
            else => {},
        }
        return true;
    }
};

const Tree = @This();

comp: *Compilation,

// Values from Preprocessor.
generated: []const u8,
tokens: Token.List.Slice,

// Values owned by this Tree
nodes: std.MultiArrayList(Node.Repr) = .empty,
extra: std.ArrayListUnmanaged(u32) = .empty,
root_decls: std.ArrayListUnmanaged(Node.Index) = .empty,
value_map: ValueMap = .empty,
type_map: std.ArrayHashMapUnmanaged(Type, void, TypeHashContext, false) = .empty,

/// Arena allocator used for types.
arena: std.heap.ArenaAllocator,

pub const genIr = CodeGen.genIr;

pub fn deinit(tree: *Tree) void {
    tree.nodes.deinit(tree.comp.gpa);
    tree.extra.deinit(tree.comp.gpa);
    tree.root_decls.deinit(tree.comp.gpa);
    tree.value_map.deinit(tree.comp.gpa);
    tree.type_map.deinit(tree.comp.gpa);
    tree.arena.deinit();
    tree.* = undefined;
}

pub const GNUAssemblyQualifiers = struct {
    @"volatile": bool = false,
    @"inline": bool = false,
    goto: bool = false,
};

pub const Node = union(enum) {
    static_assert: struct {
        assert_tok: TokenIndex,
        cond: Node.Index,
        message: ?Node.Index,
    },
    fn_proto: struct {
        name_tok: TokenIndex,
        type: Type,
        static: bool,
        @"inline": bool,
        /// The definition for this prototype if one exists.
        definition: ?Node.Index,
    },
    fn_def: FnDef,
    param: Param,
    variable: Variable,
    typedef: struct {
        name_tok: TokenIndex,
        type: Type,
    },
    global_asm: SimpleAsm,

    struct_decl: ContainerDecl,
    union_decl: ContainerDecl,
    enum_decl: ContainerDecl,
    struct_forward_decl: ContainerForwardDecl,
    union_forward_decl: ContainerForwardDecl,
    enum_forward_decl: ContainerForwardDecl,

    enum_field: struct {
        name_tok: TokenIndex,
        type: Type,
        init: ?Node.Index,
    },
    record_field: struct {
        name_or_first_tok: TokenIndex,
        type: Type,
        bit_width: ?Node.Index,
    },

    labeled_stmt: struct {
        label_tok: TokenIndex,
        body: Node.Index,
        type: Type,
    },
    compound_stmt: struct {
        l_brace_tok: TokenIndex,
        body: []const Node.Index,
    },
    if_stmt: struct {
        if_tok: TokenIndex,
        cond: Node.Index,
        then_body: Node.Index,
        else_body: ?Node.Index,
    },
    switch_stmt: struct {
        switch_tok: TokenIndex,
        cond: Node.Index,
        body: Node.Index,
    },
    case_stmt: struct {
        case_tok: TokenIndex,
        start: Node.Index,
        end: ?Node.Index,
        body: Node.Index,
    },
    default_stmt: struct {
        default_tok: TokenIndex,
        body: Node.Index,
    },
    while_stmt: struct {
        while_tok: TokenIndex,
        cond: Node.Index,
        body: Node.Index,
    },
    do_while_stmt: struct {
        do_tok: TokenIndex,
        cond: Node.Index,
        body: Node.Index,
    },
    for_stmt: struct {
        for_tok: TokenIndex,
        init: union(enum) {
            decls: []const Node.Index,
            expr: ?Node.Index,
        },
        cond: ?Node.Index,
        incr: ?Node.Index,
        body: Node.Index,
    },
    goto_stmt: struct {
        label_tok: TokenIndex,
    },
    computed_goto_stmt: struct {
        goto_tok: TokenIndex,
        expr: Node.Index,
    },
    continue_stmt: struct {
        continue_tok: TokenIndex,
    },
    break_stmt: struct {
        break_tok: TokenIndex,
    },
    null_stmt: struct {
        semicolon_or_r_brace_tok: TokenIndex,
        type: Type,
    },
    return_stmt: struct {
        return_tok: TokenIndex,
        return_type: Type,
        expr: ?Node.Index,
    },
    /// Inserted at the end of a function body if no return stmt is found.
    implicit_return: struct {
        r_brace_tok: TokenIndex,
        return_type: Type,
        /// True if the function is called "main" and return_type is compatible with int
        zero: bool,
    },
    gnu_asm_simple: SimpleAsm,

    comma_expr: BinaryExpr,
    assign_expr: BinaryExpr,
    mul_assign_expr: BinaryExpr,
    div_assign_expr: BinaryExpr,
    mod_assign_expr: BinaryExpr,
    add_assign_expr: BinaryExpr,
    sub_assign_expr: BinaryExpr,
    shl_assign_expr: BinaryExpr,
    shr_assign_expr: BinaryExpr,
    bit_and_assign_expr: BinaryExpr,
    bit_xor_assign_expr: BinaryExpr,
    bit_or_assign_expr: BinaryExpr,
    bool_or_expr: BinaryExpr,
    bool_and_expr: BinaryExpr,
    bit_or_expr: BinaryExpr,
    bit_xor_expr: BinaryExpr,
    bit_and_expr: BinaryExpr,
    equal_expr: BinaryExpr,
    not_equal_expr: BinaryExpr,
    less_than_expr: BinaryExpr,
    less_than_equal_expr: BinaryExpr,
    greater_than_expr: BinaryExpr,
    greater_than_equal_expr: BinaryExpr,
    shl_expr: BinaryExpr,
    shr_expr: BinaryExpr,
    add_expr: BinaryExpr,
    sub_expr: BinaryExpr,
    mul_expr: BinaryExpr,
    div_expr: BinaryExpr,
    mod_expr: BinaryExpr,

    explicit_cast: Cast,
    implicit_cast: Cast,

    addr_of_expr: UnaryExpr,
    deref_expr: UnaryExpr,
    plus_expr: UnaryExpr,
    negate_expr: UnaryExpr,
    bit_not_expr: UnaryExpr,
    bool_not_expr: UnaryExpr,
    pre_inc_expr: UnaryExpr,
    pre_dec_expr: UnaryExpr,
    imag_expr: UnaryExpr,
    real_expr: UnaryExpr,
    post_inc_expr: UnaryExpr,
    post_dec_expr: UnaryExpr,
    paren_expr: UnaryExpr,
    stmt_expr: UnaryExpr,

    addr_of_label: struct {
        label_tok: TokenIndex,
        type: Type,
    },

    array_access_expr: struct {
        l_bracket_tok: TokenIndex,
        type: Type,
        base: Node.Index,
        index: Node.Index,
    },
    call_expr: Call,
    builtin_call_expr: struct {
        builtin_tok: TokenIndex,
        type: Type,
        args: []const Node.Index,
    },
    member_access_expr: MemberAccess,
    member_access_ptr_expr: MemberAccess,
    decl_ref_expr: DeclRef,
    enumeration_ref: NoDeclRef,
    builtin_ref: NoDeclRef,

    /// C23 bool literal `true` / `false`
    bool_literal: Literal,
    /// C23 nullptr literal
    nullptr_literal: Literal,
    /// integer literal, always unsigned
    int_literal: Literal,
    /// Same as int_literal, but originates from a char literal
    char_literal: Literal,
    /// a floating point literal
    float_literal: Literal,
    string_literal_expr: Literal,
    /// wraps a float or double literal: un
    imaginary_literal: UnaryExpr,

    sizeof_expr: TypeInfo,
    alignof_expr: TypeInfo,

    generic_expr: struct {
        generic_tok: TokenIndex,
        type: Type,
        controlling: Node.Index,
        chosen: Node.Index,
        rest: []const Node.Index,
    },
    generic_association_expr: struct {
        colon_tok: TokenIndex,
        association_type: Type,
        expr: Node.Index,
    },
    generic_default_expr: struct {
        default_tok: TokenIndex,
        expr: Node.Index,
    },

    binary_cond_expr: Conditional,
    /// Used as the base for casts of the lhs in `binary_cond_expr`.
    cond_dummy_expr: UnaryExpr,
    cond_expr: Conditional,
    builtin_choose_expr: Conditional,
    builtin_types_compatible_p: struct {
        builtin_tok: TokenIndex,
        lhs: Type,
        rhs: Type,
    },

    array_init_expr: ContainerInit,
    struct_init_expr: ContainerInit,
    union_init_expr: struct {
        l_brace_tok: TokenIndex,
        union_type: Type,
        field_index: u32,
        initializer: ?Node.Index,
    },
    /// Inserted in array_init_expr to represent unspecified elements.
    /// data.int contains the amount of elements.
    array_filler_expr: struct {
        last_tok: TokenIndex,
        type: Type,
        count: u64,
    },
    /// Inserted in record and scalar initializers for unspecified elements.
    default_init_expr: struct {
        last_tok: TokenIndex,
        type: Type,
    },

    compound_literal_expr: struct {
        l_paren_tok: TokenIndex,
        type: Type,
        thread_local: bool,
        storage_class: enum {
            auto,
            static,
            register,
        },
        initializer: Node.Index,
    },

    pub const FnDef = struct {
        name_tok: TokenIndex,
        type: Type,
        static: bool,
        @"inline": bool,
        body: Node.Index,
    };

    pub const Param = struct {
        name_tok: TokenIndex,
        type: Type,
        storage_class: enum {
            auto,
            register,
        },
    };

    pub const Variable = struct {
        name_tok: TokenIndex,
        type: Type,
        storage_class: enum {
            auto,
            static,
            @"extern",
            register,
        },
        thread_local: bool,
        /// From predefined macro  __func__, __FUNCTION__ or __PRETTY_FUNCTION__.
        /// Implies `static == true`.
        implicit: bool,
        initializer: ?Node.Index,
    };

    pub const SimpleAsm = struct {
        asm_tok: TokenIndex,
        asm_str: Node.Index,
    };

    pub const ContainerDecl = struct {
        name_or_kind_tok: TokenIndex,
        container_type: Type,
        fields: []const Node.Index,
    };

    pub const ContainerForwardDecl = struct {
        name_or_kind_tok: TokenIndex,
        container_type: Type,
        /// The definition for this forward declaration if one exists.
        definition: ?Node.Index,
    };

    pub const BinaryExpr = struct {
        type: Type,
        lhs: Node.Index,
        op_tok: TokenIndex,
        rhs: Node.Index,
    };

    pub const Cast = struct {
        type: Type,
        l_paren: TokenIndex,
        kind: Kind,
        operand: Node.Index,

        pub const Kind = enum {
            /// Does nothing except possibly add qualifiers
            no_op,
            /// Interpret one bit pattern as another. Used for operands which have the same
            /// size and unrelated types, e.g. casting one pointer type to another
            bitcast,
            /// Convert T[] to T *
            array_to_pointer,
            /// Converts an lvalue to an rvalue
            lval_to_rval,
            /// Convert a function type to a pointer to a function
            function_to_pointer,
            /// Convert a pointer type to a _Bool
            pointer_to_bool,
            /// Convert a pointer type to an integer type
            pointer_to_int,
            /// Convert _Bool to an integer type
            bool_to_int,
            /// Convert _Bool to a floating type
            bool_to_float,
            /// Convert a _Bool to a pointer; will cause a  warning
            bool_to_pointer,
            /// Convert an integer type to _Bool
            int_to_bool,
            /// Convert an integer to a floating type
            int_to_float,
            /// Convert a complex integer to a complex floating type
            complex_int_to_complex_float,
            /// Convert an integer type to a pointer type
            int_to_pointer,
            /// Convert a floating type to a _Bool
            float_to_bool,
            /// Convert a floating type to an integer
            float_to_int,
            /// Convert a complex floating type to a complex integer
            complex_float_to_complex_int,
            /// Convert one integer type to another
            int_cast,
            /// Convert one complex integer type to another
            complex_int_cast,
            /// Convert real part of complex integer to a integer
            complex_int_to_real,
            /// Create a complex integer type using operand as the real part
            real_to_complex_int,
            /// Convert one floating type to another
            float_cast,
            /// Convert one complex floating type to another
            complex_float_cast,
            /// Convert real part of complex float to a float
            complex_float_to_real,
            /// Create a complex floating type using operand as the real part
            real_to_complex_float,
            /// Convert type to void
            to_void,
            /// Convert a literal 0 to a null pointer
            null_to_pointer,
            /// GNU cast-to-union extension
            union_cast,
            /// Create vector where each value is same as the input scalar.
            vector_splat,
        };
    };

    pub const UnaryExpr = struct {
        type: Type,
        op_tok: TokenIndex,
        operand: Node.Index,
    };

    pub const Call = struct {
        l_paren_tok: TokenIndex,
        type: Type,
        callee: Node.Index,
        args: []const Node.Index,
    };

    pub const MemberAccess = struct {
        type: Type,
        base: Node.Index,
        access_tok: TokenIndex,
        member_index: u32,

        pub fn isBitFieldWidth(access: MemberAccess, tree: *const Tree) ?u32 {
            var ty = access.base.type(tree);
            if (ty.isPtr()) ty = ty.elemType();
            const record_ty = ty.get(.@"struct") orelse ty.get(.@"union") orelse return null;
            const field = record_ty.data.record.fields[access.member_index];
            return field.bit_width;
        }
    };

    pub const DeclRef = struct {
        name_tok: TokenIndex,
        type: Type,
        decl: Node.Index,
    };

    pub const NoDeclRef = struct {
        name_tok: TokenIndex,
        type: Type,
    };

    pub const Conditional = struct {
        cond_tok: TokenIndex,
        type: Type,
        cond: Node.Index,
        then_expr: Node.Index,
        else_expr: Node.Index,
    };

    pub const ContainerInit = struct {
        l_brace_tok: TokenIndex,
        container_type: Type,
        items: []const Node.Index,
    };

    pub const Literal = struct {
        literal_tok: TokenIndex,
        type: Type,
    };

    pub const TypeInfo = struct {
        type: Type,
        op_tok: TokenIndex,
        expr: ?Node.Index,
    };

    pub const Index = enum(u32) {
        _,

        pub fn get(index: Index, tree: *const Tree) Node {
            const node_tok = tree.nodes.items(.tok)[@intFromEnum(index)];
            const node_data = &tree.nodes.items(.data)[@intFromEnum(index)];
            return switch (tree.nodes.items(.tag)[@intFromEnum(index)]) {
                .static_assert => .{
                    .static_assert = .{
                        .assert_tok = node_tok,
                        .cond = @enumFromInt(node_data[0]),
                        .message = unpackOptIndex(node_data[1]),
                    },
                },
                .fn_proto => {
                    const attr: Node.Repr.DeclAttr = @bitCast(node_data[1]);
                    return .{
                        .fn_proto = .{
                            .name_tok = node_tok,
                            .type = tree.type_map.keys()[node_data[0]],
                            .static = attr.static,
                            .@"inline" = attr.@"inline",
                            // TODO decide how to handle definition
                            .definition = null,
                        },
                    };
                },
                .fn_def => {
                    const attr: Node.Repr.DeclAttr = @bitCast(node_data[1]);
                    return .{
                        .fn_def = .{
                            .name_tok = node_tok,
                            .type = tree.type_map.keys()[node_data[0]],
                            .static = attr.static,
                            .@"inline" = attr.@"inline",
                            .body = @enumFromInt(node_data[2]),
                        },
                    };
                },
                .param => {
                    const attr: Node.Repr.DeclAttr = @bitCast(node_data[1]);
                    return .{
                        .param = .{
                            .name_tok = node_tok,
                            .type = tree.type_map.keys()[node_data[0]],
                            .storage_class = if (attr.register)
                                .register
                            else
                                .auto,
                        },
                    };
                },
                .variable => {
                    const attr: Node.Repr.DeclAttr = @bitCast(node_data[1]);
                    return .{
                        .variable = .{
                            .name_tok = node_tok,
                            .type = tree.type_map.keys()[node_data[0]],
                            .storage_class = if (attr.static)
                                .static
                            else if (attr.@"extern")
                                .@"extern"
                            else if (attr.register)
                                .register
                            else
                                .auto,
                            .thread_local = attr.thread_local,
                            .implicit = attr.implicit,
                            .initializer = unpackOptIndex(node_data[2]),
                        },
                    };
                },
                .typedef => .{
                    .typedef = .{
                        .name_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                    },
                },
                .global_asm => .{
                    .global_asm = .{
                        .asm_tok = node_tok,
                        .asm_str = @enumFromInt(node_data[0]),
                    },
                },
                .struct_decl => .{
                    .struct_decl = .{
                        .name_or_kind_tok = node_tok,
                        .container_type = tree.type_map.keys()[node_data[0]],
                        .fields = @ptrCast(tree.extra.items[node_data[1]..][0..node_data[2]]),
                    },
                },
                .struct_decl_two => .{
                    .struct_decl = .{
                        .name_or_kind_tok = node_tok,
                        .container_type = tree.type_map.keys()[node_data[0]],
                        .fields = unPackElems(node_data[1..]),
                    },
                },
                .union_decl => .{
                    .union_decl = .{
                        .name_or_kind_tok = node_tok,
                        .container_type = tree.type_map.keys()[node_data[0]],
                        .fields = @ptrCast(tree.extra.items[node_data[1]..][0..node_data[2]]),
                    },
                },
                .union_decl_two => .{
                    .union_decl = .{
                        .name_or_kind_tok = node_tok,
                        .container_type = tree.type_map.keys()[node_data[0]],
                        .fields = unPackElems(node_data[1..]),
                    },
                },
                .enum_decl => .{
                    .enum_decl = .{
                        .name_or_kind_tok = node_tok,
                        .container_type = tree.type_map.keys()[node_data[0]],
                        .fields = @ptrCast(tree.extra.items[node_data[1]..][0..node_data[2]]),
                    },
                },
                .enum_decl_two => .{
                    .enum_decl = .{
                        .name_or_kind_tok = node_tok,
                        .container_type = tree.type_map.keys()[node_data[0]],
                        .fields = unPackElems(node_data[1..]),
                    },
                },
                .struct_forward_decl => .{
                    .struct_forward_decl = .{
                        .name_or_kind_tok = node_tok,
                        .container_type = tree.type_map.keys()[node_data[0]],
                        .definition = null,
                    },
                },
                .union_forward_decl => .{
                    .union_forward_decl = .{
                        .name_or_kind_tok = node_tok,
                        .container_type = tree.type_map.keys()[node_data[0]],
                        .definition = null,
                    },
                },
                .enum_forward_decl => .{
                    .enum_forward_decl = .{
                        .name_or_kind_tok = node_tok,
                        .container_type = tree.type_map.keys()[node_data[0]],
                        .definition = null,
                    },
                },
                .enum_field => .{
                    .enum_field = .{
                        .name_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                        .init = unpackOptIndex(node_data[1]),
                    },
                },
                .record_field => .{
                    .record_field = .{
                        .name_or_first_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                        .bit_width = unpackOptIndex(node_data[1]),
                    },
                },
                .labeled_stmt => .{
                    .labeled_stmt = .{
                        .label_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                        .body = @enumFromInt(node_data[1]),
                    },
                },
                .compound_stmt => .{
                    .compound_stmt = .{
                        .l_brace_tok = node_tok,
                        .body = @ptrCast(tree.extra.items[node_data[0]..][0..node_data[1]]),
                    },
                },
                .compound_stmt_three => .{
                    .compound_stmt = .{
                        .l_brace_tok = node_tok,
                        .body = unPackElems(node_data),
                    },
                },
                .if_stmt => .{
                    .if_stmt = .{
                        .if_tok = node_tok,
                        .cond = @enumFromInt(node_data[0]),
                        .then_body = @enumFromInt(node_data[1]),
                        .else_body = unpackOptIndex(node_data[2]),
                    },
                },
                .switch_stmt => .{
                    .switch_stmt = .{
                        .switch_tok = node_tok,
                        .cond = @enumFromInt(node_data[0]),
                        .body = @enumFromInt(node_data[1]),
                    },
                },
                .case_stmt => .{
                    .case_stmt = .{
                        .case_tok = node_tok,
                        .start = @enumFromInt(node_data[0]),
                        .end = unpackOptIndex(node_data[1]),
                        .body = @enumFromInt(node_data[2]),
                    },
                },
                .default_stmt => .{
                    .default_stmt = .{
                        .default_tok = node_tok,
                        .body = @enumFromInt(node_data[0]),
                    },
                },
                .while_stmt => .{
                    .while_stmt = .{
                        .while_tok = node_tok,
                        .cond = @enumFromInt(node_data[0]),
                        .body = @enumFromInt(node_data[1]),
                    },
                },
                .do_while_stmt => .{
                    .do_while_stmt = .{
                        .do_tok = node_tok,
                        .cond = @enumFromInt(node_data[0]),
                        .body = @enumFromInt(node_data[1]),
                    },
                },
                .for_decl => .{
                    .for_stmt = .{
                        .for_tok = node_tok,
                        .init = .{ .decls = @ptrCast(tree.extra.items[node_data[0]..][0 .. node_data[1] - 2]) },
                        .cond = unpackOptIndex(tree.extra.items[node_data[0] + node_data[1] - 2]),
                        .incr = unpackOptIndex(tree.extra.items[node_data[0] + node_data[1] - 1]),
                        .body = @enumFromInt(node_data[2]),
                    },
                },
                .for_expr => .{
                    .for_stmt = .{
                        .for_tok = node_tok,
                        .init = .{ .expr = unpackOptIndex(node_data[0]) },
                        .cond = unpackOptIndex(tree.extra.items[node_data[1]]),
                        .incr = unpackOptIndex(tree.extra.items[node_data[1] + 1]),
                        .body = @enumFromInt(node_data[2]),
                    },
                },
                .goto_stmt => .{
                    .goto_stmt = .{
                        .label_tok = node_tok,
                    },
                },
                .computed_goto_stmt => .{
                    .computed_goto_stmt = .{
                        .goto_tok = node_tok,
                        .expr = @enumFromInt(node_data[0]),
                    },
                },
                .continue_stmt => .{
                    .continue_stmt = .{
                        .continue_tok = node_tok,
                    },
                },
                .break_stmt => .{
                    .break_stmt = .{
                        .break_tok = node_tok,
                    },
                },
                .null_stmt => .{
                    .null_stmt = .{
                        .semicolon_or_r_brace_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                    },
                },
                .return_stmt => .{
                    .return_stmt = .{
                        .return_tok = node_tok,
                        .return_type = tree.type_map.keys()[node_data[0]],
                        .expr = unpackOptIndex(node_data[1]),
                    },
                },
                .implicit_return => .{
                    .implicit_return = .{
                        .r_brace_tok = node_tok,
                        .return_type = tree.type_map.keys()[node_data[0]],
                        .zero = node_data[1] != 0,
                    },
                },
                .gnu_asm_simple => .{
                    .gnu_asm_simple = .{
                        .asm_tok = node_tok,
                        .asm_str = @enumFromInt(node_data[0]),
                    },
                },
                .comma_expr => .{
                    .comma_expr = .{
                        .op_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                        .lhs = @enumFromInt(node_data[1]),
                        .rhs = @enumFromInt(node_data[2]),
                    },
                },
                .assign_expr => .{
                    .assign_expr = .{
                        .op_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                        .lhs = @enumFromInt(node_data[1]),
                        .rhs = @enumFromInt(node_data[2]),
                    },
                },
                .mul_assign_expr => .{
                    .mul_assign_expr = .{
                        .op_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                        .lhs = @enumFromInt(node_data[1]),
                        .rhs = @enumFromInt(node_data[2]),
                    },
                },
                .div_assign_expr => .{
                    .div_assign_expr = .{
                        .op_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                        .lhs = @enumFromInt(node_data[1]),
                        .rhs = @enumFromInt(node_data[2]),
                    },
                },
                .mod_assign_expr => .{
                    .mod_assign_expr = .{
                        .op_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                        .lhs = @enumFromInt(node_data[1]),
                        .rhs = @enumFromInt(node_data[2]),
                    },
                },
                .add_assign_expr => .{
                    .add_assign_expr = .{
                        .op_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                        .lhs = @enumFromInt(node_data[1]),
                        .rhs = @enumFromInt(node_data[2]),
                    },
                },
                .sub_assign_expr => .{
                    .sub_assign_expr = .{
                        .op_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                        .lhs = @enumFromInt(node_data[1]),
                        .rhs = @enumFromInt(node_data[2]),
                    },
                },
                .shl_assign_expr => .{
                    .shl_assign_expr = .{
                        .op_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                        .lhs = @enumFromInt(node_data[1]),
                        .rhs = @enumFromInt(node_data[2]),
                    },
                },
                .shr_assign_expr => .{
                    .shr_assign_expr = .{
                        .op_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                        .lhs = @enumFromInt(node_data[1]),
                        .rhs = @enumFromInt(node_data[2]),
                    },
                },
                .bit_and_assign_expr => .{
                    .bit_and_assign_expr = .{
                        .op_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                        .lhs = @enumFromInt(node_data[1]),
                        .rhs = @enumFromInt(node_data[2]),
                    },
                },
                .bit_xor_assign_expr => .{
                    .bit_xor_assign_expr = .{
                        .op_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                        .lhs = @enumFromInt(node_data[1]),
                        .rhs = @enumFromInt(node_data[2]),
                    },
                },
                .bit_or_assign_expr => .{
                    .bit_or_assign_expr = .{
                        .op_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                        .lhs = @enumFromInt(node_data[1]),
                        .rhs = @enumFromInt(node_data[2]),
                    },
                },
                .bool_or_expr => .{
                    .bool_or_expr = .{
                        .op_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                        .lhs = @enumFromInt(node_data[1]),
                        .rhs = @enumFromInt(node_data[2]),
                    },
                },
                .bool_and_expr => .{
                    .bool_and_expr = .{
                        .op_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                        .lhs = @enumFromInt(node_data[1]),
                        .rhs = @enumFromInt(node_data[2]),
                    },
                },
                .bit_or_expr => .{
                    .bit_or_expr = .{
                        .op_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                        .lhs = @enumFromInt(node_data[1]),
                        .rhs = @enumFromInt(node_data[2]),
                    },
                },
                .bit_xor_expr => .{
                    .bit_xor_expr = .{
                        .op_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                        .lhs = @enumFromInt(node_data[1]),
                        .rhs = @enumFromInt(node_data[2]),
                    },
                },
                .bit_and_expr => .{
                    .bit_and_expr = .{
                        .op_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                        .lhs = @enumFromInt(node_data[1]),
                        .rhs = @enumFromInt(node_data[2]),
                    },
                },
                .equal_expr => .{
                    .equal_expr = .{
                        .op_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                        .lhs = @enumFromInt(node_data[1]),
                        .rhs = @enumFromInt(node_data[2]),
                    },
                },
                .not_equal_expr => .{
                    .not_equal_expr = .{
                        .op_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                        .lhs = @enumFromInt(node_data[1]),
                        .rhs = @enumFromInt(node_data[2]),
                    },
                },
                .less_than_expr => .{
                    .less_than_expr = .{
                        .op_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                        .lhs = @enumFromInt(node_data[1]),
                        .rhs = @enumFromInt(node_data[2]),
                    },
                },
                .less_than_equal_expr => .{
                    .less_than_equal_expr = .{
                        .op_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                        .lhs = @enumFromInt(node_data[1]),
                        .rhs = @enumFromInt(node_data[2]),
                    },
                },
                .greater_than_expr => .{
                    .greater_than_expr = .{
                        .op_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                        .lhs = @enumFromInt(node_data[1]),
                        .rhs = @enumFromInt(node_data[2]),
                    },
                },
                .greater_than_equal_expr => .{
                    .greater_than_equal_expr = .{
                        .op_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                        .lhs = @enumFromInt(node_data[1]),
                        .rhs = @enumFromInt(node_data[2]),
                    },
                },
                .shl_expr => .{
                    .shl_expr = .{
                        .op_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                        .lhs = @enumFromInt(node_data[1]),
                        .rhs = @enumFromInt(node_data[2]),
                    },
                },
                .shr_expr => .{
                    .shr_expr = .{
                        .op_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                        .lhs = @enumFromInt(node_data[1]),
                        .rhs = @enumFromInt(node_data[2]),
                    },
                },
                .add_expr => .{
                    .add_expr = .{
                        .op_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                        .lhs = @enumFromInt(node_data[1]),
                        .rhs = @enumFromInt(node_data[2]),
                    },
                },
                .sub_expr => .{
                    .sub_expr = .{
                        .op_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                        .lhs = @enumFromInt(node_data[1]),
                        .rhs = @enumFromInt(node_data[2]),
                    },
                },
                .mul_expr => .{
                    .mul_expr = .{
                        .op_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                        .lhs = @enumFromInt(node_data[1]),
                        .rhs = @enumFromInt(node_data[2]),
                    },
                },
                .div_expr => .{
                    .div_expr = .{
                        .op_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                        .lhs = @enumFromInt(node_data[1]),
                        .rhs = @enumFromInt(node_data[2]),
                    },
                },
                .mod_expr => .{
                    .mod_expr = .{
                        .op_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                        .lhs = @enumFromInt(node_data[1]),
                        .rhs = @enumFromInt(node_data[2]),
                    },
                },
                .explicit_cast => .{
                    .explicit_cast = .{
                        .l_paren = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                        .kind = @enumFromInt(node_data[1]),
                        .operand = @enumFromInt(node_data[2]),
                    },
                },
                .implicit_cast => .{
                    .implicit_cast = .{
                        .l_paren = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                        .kind = @enumFromInt(node_data[1]),
                        .operand = @enumFromInt(node_data[2]),
                    },
                },
                .addr_of_expr => .{
                    .addr_of_expr = .{
                        .op_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                        .operand = @enumFromInt(node_data[1]),
                    },
                },
                .deref_expr => .{
                    .deref_expr = .{
                        .op_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                        .operand = @enumFromInt(node_data[1]),
                    },
                },
                .plus_expr => .{
                    .plus_expr = .{
                        .op_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                        .operand = @enumFromInt(node_data[1]),
                    },
                },
                .negate_expr => .{
                    .negate_expr = .{
                        .op_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                        .operand = @enumFromInt(node_data[1]),
                    },
                },
                .bit_not_expr => .{
                    .bit_not_expr = .{
                        .op_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                        .operand = @enumFromInt(node_data[1]),
                    },
                },
                .bool_not_expr => .{
                    .bool_not_expr = .{
                        .op_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                        .operand = @enumFromInt(node_data[1]),
                    },
                },
                .pre_inc_expr => .{
                    .pre_inc_expr = .{
                        .op_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                        .operand = @enumFromInt(node_data[1]),
                    },
                },
                .pre_dec_expr => .{
                    .pre_dec_expr = .{
                        .op_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                        .operand = @enumFromInt(node_data[1]),
                    },
                },
                .imag_expr => .{
                    .imag_expr = .{
                        .op_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                        .operand = @enumFromInt(node_data[1]),
                    },
                },
                .real_expr => .{
                    .real_expr = .{
                        .op_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                        .operand = @enumFromInt(node_data[1]),
                    },
                },
                .post_inc_expr => .{
                    .post_inc_expr = .{
                        .op_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                        .operand = @enumFromInt(node_data[1]),
                    },
                },
                .post_dec_expr => .{
                    .post_dec_expr = .{
                        .op_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                        .operand = @enumFromInt(node_data[1]),
                    },
                },
                .paren_expr => .{
                    .paren_expr = .{
                        .op_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                        .operand = @enumFromInt(node_data[1]),
                    },
                },
                .stmt_expr => .{
                    .stmt_expr = .{
                        .op_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                        .operand = @enumFromInt(node_data[1]),
                    },
                },
                .cond_dummy_expr => .{
                    .cond_dummy_expr = .{
                        .op_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                        .operand = @enumFromInt(node_data[1]),
                    },
                },
                .addr_of_label => .{
                    .addr_of_label = .{
                        .label_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                    },
                },
                .array_access_expr => .{
                    .array_access_expr = .{
                        .l_bracket_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                        .base = @enumFromInt(node_data[1]),
                        .index = @enumFromInt(node_data[2]),
                    },
                },
                .call_expr => .{
                    .call_expr = .{
                        .l_paren_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                        .callee = @enumFromInt(tree.extra.items[node_data[1]]),
                        .args = @ptrCast(tree.extra.items[node_data[1] + 1 ..][0 .. node_data[2] - 1]),
                    },
                },
                .call_expr_one => .{
                    .call_expr = .{
                        .l_paren_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                        .callee = @enumFromInt(node_data[1]),
                        .args = @ptrCast(node_data[2..2]),
                    },
                },
                .builtin_call_expr => .{
                    .builtin_call_expr = .{
                        .builtin_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                        .args = @ptrCast(tree.extra.items[node_data[1]..][0..node_data[2]]),
                    },
                },
                .builtin_call_expr_two => .{
                    .builtin_call_expr = .{
                        .builtin_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                        .args = unPackElems(node_data[1..]),
                    },
                },
                .member_access_expr => .{
                    .member_access_expr = .{
                        .access_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                        .base = @enumFromInt(node_data[1]),
                        .member_index = node_data[2],
                    },
                },
                .member_access_ptr_expr => .{
                    .member_access_ptr_expr = .{
                        .access_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                        .base = @enumFromInt(node_data[1]),
                        .member_index = node_data[2],
                    },
                },
                .decl_ref_expr => .{
                    .decl_ref_expr = .{
                        .name_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                        .decl = @enumFromInt(node_data[1]),
                    },
                },
                .enumeration_ref => .{
                    .enumeration_ref = .{
                        .name_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                    },
                },
                .builtin_ref => .{
                    .builtin_ref = .{
                        .name_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                    },
                },
                .bool_literal => .{
                    .bool_literal = .{
                        .literal_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                    },
                },
                .nullptr_literal => .{
                    .nullptr_literal = .{
                        .literal_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                    },
                },
                .int_literal => .{
                    .int_literal = .{
                        .literal_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                    },
                },
                .char_literal => .{
                    .char_literal = .{
                        .literal_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                    },
                },
                .float_literal => .{
                    .float_literal = .{
                        .literal_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                    },
                },
                .string_literal_expr => .{
                    .string_literal_expr = .{
                        .literal_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                    },
                },
                .imaginary_literal => .{
                    .imaginary_literal = .{
                        .op_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                        .operand = @enumFromInt(node_data[1]),
                    },
                },
                .sizeof_expr => .{
                    .sizeof_expr = .{
                        .op_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                        .expr = unpackOptIndex(node_data[1]),
                    },
                },
                .alignof_expr => .{
                    .alignof_expr = .{
                        .op_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                        .expr = unpackOptIndex(node_data[1]),
                    },
                },

                .generic_expr_zero => .{
                    .generic_expr = .{
                        .generic_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                        .controlling = @enumFromInt(node_data[1]),
                        .chosen = @enumFromInt(node_data[2]),
                        .rest = &.{},
                    },
                },
                .generic_expr => .{
                    .generic_expr = .{
                        .generic_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                        .controlling = @enumFromInt(tree.extra.items[node_data[1]]),
                        .chosen = @enumFromInt(tree.extra.items[node_data[1] + 1]),
                        .rest = @ptrCast(tree.extra.items[node_data[1] + 2 ..][0 .. node_data[2] - 2]),
                    },
                },
                .generic_association_expr => .{
                    .generic_association_expr = .{
                        .colon_tok = node_tok,
                        .association_type = tree.type_map.keys()[node_data[0]],
                        .expr = @enumFromInt(node_data[1]),
                    },
                },
                .generic_default_expr => .{
                    .generic_default_expr = .{
                        .default_tok = node_tok,
                        .expr = @enumFromInt(node_data[0]),
                    },
                },
                .binary_cond_expr => .{
                    .binary_cond_expr = .{
                        .cond_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                        .cond = @enumFromInt(node_data[1]),
                        .then_expr = @enumFromInt(tree.extra.items[node_data[2]]),
                        .else_expr = @enumFromInt(tree.extra.items[node_data[2] + 1]),
                    },
                },
                .cond_expr => .{
                    .cond_expr = .{
                        .cond_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                        .cond = @enumFromInt(node_data[1]),
                        .then_expr = @enumFromInt(tree.extra.items[node_data[2]]),
                        .else_expr = @enumFromInt(tree.extra.items[node_data[2] + 1]),
                    },
                },
                .builtin_choose_expr => .{
                    .builtin_choose_expr = .{
                        .cond_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                        .cond = @enumFromInt(node_data[1]),
                        .then_expr = @enumFromInt(tree.extra.items[node_data[2]]),
                        .else_expr = @enumFromInt(tree.extra.items[node_data[2] + 1]),
                    },
                },
                .builtin_types_compatible_p => .{
                    .builtin_types_compatible_p = .{
                        .builtin_tok = node_tok,
                        .lhs = tree.type_map.keys()[node_data[0]],
                        .rhs = tree.type_map.keys()[node_data[1]],
                    },
                },
                .array_init_expr_two => .{
                    .array_init_expr = .{
                        .l_brace_tok = node_tok,
                        .container_type = tree.type_map.keys()[node_data[0]],
                        .items = unPackElems(node_data[1..]),
                    },
                },
                .array_init_expr => .{
                    .array_init_expr = .{
                        .l_brace_tok = node_tok,
                        .container_type = tree.type_map.keys()[node_data[0]],
                        .items = @ptrCast(tree.extra.items[node_data[1]..][0..node_data[2]]),
                    },
                },
                .struct_init_expr_two => .{
                    .struct_init_expr = .{
                        .l_brace_tok = node_tok,
                        .container_type = tree.type_map.keys()[node_data[0]],
                        .items = unPackElems(node_data[1..]),
                    },
                },
                .struct_init_expr => .{
                    .struct_init_expr = .{
                        .l_brace_tok = node_tok,
                        .container_type = tree.type_map.keys()[node_data[0]],
                        .items = @ptrCast(tree.extra.items[node_data[1]..][0..node_data[2]]),
                    },
                },
                .union_init_expr => .{
                    .union_init_expr = .{
                        .l_brace_tok = node_tok,
                        .union_type = tree.type_map.keys()[node_data[0]],
                        .field_index = node_data[1],
                        .initializer = unpackOptIndex(node_data[2]),
                    },
                },
                .array_filler_expr => .{
                    .array_filler_expr = .{
                        .last_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                        .count = @bitCast(node_data[1..].*),
                    },
                },
                .default_init_expr => .{
                    .default_init_expr = .{
                        .last_tok = node_tok,
                        .type = tree.type_map.keys()[node_data[0]],
                    },
                },
                .compound_literal_expr => {
                    const attr: Node.Repr.DeclAttr = @bitCast(node_data[1]);
                    return .{
                        .compound_literal_expr = .{
                            .l_paren_tok = node_tok,
                            .type = tree.type_map.keys()[node_data[0]],
                            .storage_class = if (attr.static)
                                .static
                            else if (attr.register)
                                .register
                            else
                                .auto,
                            .thread_local = attr.thread_local,
                            .initializer = @enumFromInt(node_data[2]),
                        },
                    };
                },
            };
        }

        pub fn tok(index: Index, tree: *const Tree) TokenIndex {
            return tree.nodes.items(.tok)[@intFromEnum(index)];
        }

        pub fn loc(index: Index, tree: *const Tree) ?Source.Location {
            const tok_i = index.tok(tree);
            return tree.tokens.items(.loc)[@intFromEnum(tok_i)];
        }

        pub fn @"type"(index: Index, tree: *const Tree) Type {
            if (!tree.nodes.items(.tag)[@intFromEnum(index)].isTyped()) {
                return .{ .specifier = .void };
            }
            // If a node is typed the type is stored in data[0].
            const type_index = tree.nodes.items(.data)[@intFromEnum(index)][0];
            return tree.type_map.keys()[type_index];
        }
    };

    pub const OptIndex = enum(u32) {
        null = std.math.maxInt(u32),
        _,

        pub fn unpack(opt: OptIndex) ?Index {
            return if (opt == .null) null else @enumFromInt(@intFromEnum(opt));
        }

        pub fn pack(index: Index) OptIndex {
            return @enumFromInt(@intFromEnum(index));
        }

        pub fn packOpt(optional: ?Index) OptIndex {
            return if (optional) |some| @enumFromInt(@intFromEnum(some)) else .null;
        }
    };

    pub const Repr = struct {
        tag: Tag,
        /// If a node is typed the type is stored in data[0]
        data: [3]u32,
        tok: TokenIndex,

        pub const DeclAttr = packed struct(u32) {
            @"extern": bool = false,
            static: bool = false,
            @"inline": bool = false,
            thread_local: bool = false,
            implicit: bool = false,
            register: bool = false,
            _: u26 = 0,
        };

        pub const Tag = enum(u8) {
            static_assert,
            fn_proto,
            fn_def,
            param,
            variable,
            typedef,
            global_asm,
            struct_decl,
            union_decl,
            enum_decl,
            struct_decl_two,
            union_decl_two,
            enum_decl_two,
            struct_forward_decl,
            union_forward_decl,
            enum_forward_decl,
            enum_field,
            record_field,
            labeled_stmt,
            compound_stmt,
            compound_stmt_three,
            if_stmt,
            switch_stmt,
            case_stmt,
            default_stmt,
            while_stmt,
            do_while_stmt,
            for_expr,
            for_decl,
            goto_stmt,
            computed_goto_stmt,
            continue_stmt,
            break_stmt,
            null_stmt,
            return_stmt,
            implicit_return,
            gnu_asm_simple,
            comma_expr,
            assign_expr,
            mul_assign_expr,
            div_assign_expr,
            mod_assign_expr,
            add_assign_expr,
            sub_assign_expr,
            shl_assign_expr,
            shr_assign_expr,
            bit_and_assign_expr,
            bit_xor_assign_expr,
            bit_or_assign_expr,
            bool_or_expr,
            bool_and_expr,
            bit_or_expr,
            bit_xor_expr,
            bit_and_expr,
            equal_expr,
            not_equal_expr,
            less_than_expr,
            less_than_equal_expr,
            greater_than_expr,
            greater_than_equal_expr,
            shl_expr,
            shr_expr,
            add_expr,
            sub_expr,
            mul_expr,
            div_expr,
            mod_expr,
            explicit_cast,
            implicit_cast,
            addr_of_expr,
            deref_expr,
            plus_expr,
            negate_expr,
            bit_not_expr,
            bool_not_expr,
            pre_inc_expr,
            pre_dec_expr,
            imag_expr,
            real_expr,
            post_inc_expr,
            post_dec_expr,
            paren_expr,
            stmt_expr,
            addr_of_label,
            array_access_expr,
            call_expr_one,
            call_expr,
            builtin_call_expr,
            builtin_call_expr_two,
            member_access_expr,
            member_access_ptr_expr,
            decl_ref_expr,
            enumeration_ref,
            builtin_ref,
            bool_literal,
            nullptr_literal,
            int_literal,
            char_literal,
            float_literal,
            string_literal_expr,
            imaginary_literal,
            sizeof_expr,
            alignof_expr,
            generic_expr,
            generic_expr_zero,
            generic_association_expr,
            generic_default_expr,
            binary_cond_expr,
            cond_dummy_expr,
            cond_expr,
            builtin_choose_expr,
            builtin_types_compatible_p,
            array_init_expr,
            array_init_expr_two,
            struct_init_expr,
            struct_init_expr_two,
            union_init_expr,
            array_filler_expr,
            default_init_expr,
            compound_literal_expr,

            pub fn isTyped(tag: Tag) bool {
                return switch (tag) {
                    .static_assert,
                    .compound_stmt,
                    .compound_stmt_three,
                    .if_stmt,
                    .switch_stmt,
                    .case_stmt,
                    .default_stmt,
                    .while_stmt,
                    .do_while_stmt,
                    .for_decl,
                    .for_expr,
                    .goto_stmt,
                    .computed_goto_stmt,
                    .continue_stmt,
                    .break_stmt,
                    .gnu_asm_simple,
                    .global_asm,
                    .generic_association_expr,
                    .generic_default_expr,
                    => false,
                    else => true,
                };
            }
        };
    };

    pub fn isImplicit(node: Node) bool {
        return switch (node) {
            .implicit_cast,
            .implicit_return,
            .array_filler_expr,
            .default_init_expr,
            .cond_dummy_expr,
            => true,
            .variable => |info| info.implicit,
            else => false,
        };
    }
};

pub fn addNode(tree: *Tree, node: Node) !Node.Index {
    const index = try tree.nodes.addOne(tree.comp.gpa);
    try tree.setNode(node, index);
    return @enumFromInt(index);
}

pub fn setNode(tree: *Tree, node: Node, index: usize) !void {
    var repr: Node.Repr = undefined;
    switch (node) {
        .static_assert => |assert| {
            repr.tag = .static_assert;
            repr.data[0] = @intFromEnum(assert.cond);
            repr.data[1] = packOptIndex(assert.message);
            repr.tok = assert.assert_tok;
        },
        .fn_proto => |proto| {
            repr.tag = .fn_proto;
            repr.data[0] = try tree.addType(proto.type);
            repr.data[1] = @bitCast(Node.Repr.DeclAttr{
                .static = proto.static,
                .@"inline" = proto.@"inline",
            });
            // TODO decide how to handle definition
            // repr.data[2] = proto.definition;
            repr.tok = proto.name_tok;
        },
        .fn_def => |def| {
            repr.tag = .fn_def;
            repr.data[0] = try tree.addType(def.type);
            repr.data[1] = @bitCast(Node.Repr.DeclAttr{
                .static = def.static,
                .@"inline" = def.@"inline",
            });
            repr.data[2] = @intFromEnum(def.body);
            repr.tok = def.name_tok;
        },
        .param => |param| {
            repr.tag = .param;
            repr.data[0] = try tree.addType(param.type);
            repr.data[1] = @bitCast(Node.Repr.DeclAttr{
                .register = param.storage_class == .register,
            });
            repr.tok = param.name_tok;
        },
        .variable => |variable| {
            repr.tag = .variable;
            repr.data[0] = try tree.addType(variable.type);
            repr.data[1] = @bitCast(Node.Repr.DeclAttr{
                .@"extern" = variable.storage_class == .@"extern",
                .static = variable.storage_class == .static,
                .thread_local = variable.thread_local,
                .implicit = variable.implicit,
                .register = variable.storage_class == .register,
            });
            repr.data[2] = packOptIndex(variable.initializer);
            repr.tok = variable.name_tok;
        },
        .typedef => |typedef| {
            repr.tag = .typedef;
            repr.data[0] = try tree.addType(typedef.type);
            repr.tok = typedef.name_tok;
        },
        .global_asm => |global_asm| {
            repr.tag = .global_asm;
            repr.data[0] = @intFromEnum(global_asm.asm_str);
            repr.tok = global_asm.asm_tok;
        },
        .struct_decl => |decl| {
            repr.data[0] = try tree.addType(decl.container_type);
            if (decl.fields.len > 2) {
                repr.tag = .struct_decl;
                repr.data[1], repr.data[2] = try tree.addExtra(decl.fields);
            } else {
                repr.tag = .struct_decl_two;
                repr.data[1] = packElem(decl.fields, 0);
                repr.data[2] = packElem(decl.fields, 1);
            }
            repr.tok = decl.name_or_kind_tok;
        },
        .union_decl => |decl| {
            repr.data[0] = try tree.addType(decl.container_type);
            if (decl.fields.len > 2) {
                repr.tag = .union_decl;
                repr.data[1], repr.data[2] = try tree.addExtra(decl.fields);
            } else {
                repr.tag = .union_decl_two;
                repr.data[1] = packElem(decl.fields, 0);
                repr.data[2] = packElem(decl.fields, 1);
            }
            repr.tok = decl.name_or_kind_tok;
        },
        .enum_decl => |decl| {
            repr.data[0] = try tree.addType(decl.container_type);
            if (decl.fields.len > 2) {
                repr.tag = .enum_decl;
                repr.data[1], repr.data[2] = try tree.addExtra(decl.fields);
            } else {
                repr.tag = .enum_decl_two;
                repr.data[1] = packElem(decl.fields, 0);
                repr.data[2] = packElem(decl.fields, 1);
            }
            repr.tok = decl.name_or_kind_tok;
        },
        .struct_forward_decl => |decl| {
            repr.tag = .struct_forward_decl;
            repr.data[0] = try tree.addType(decl.container_type);
            // TODO decide how to handle definition
            // repr.data[1] = decl.definition;
            repr.tok = decl.name_or_kind_tok;
        },
        .union_forward_decl => |decl| {
            repr.tag = .union_forward_decl;
            repr.data[0] = try tree.addType(decl.container_type);
            // TODO decide how to handle definition
            // repr.data[1] = decl.definition;
            repr.tok = decl.name_or_kind_tok;
        },
        .enum_forward_decl => |decl| {
            repr.tag = .enum_forward_decl;
            repr.data[0] = try tree.addType(decl.container_type);
            // TODO decide how to handle definition
            // repr.data[1] = decl.definition;
            repr.tok = decl.name_or_kind_tok;
        },
        .enum_field => |field| {
            repr.tag = .enum_field;
            repr.data[0] = try tree.addType(field.type);
            repr.data[1] = packOptIndex(field.init);
            repr.tok = field.name_tok;
        },
        .record_field => |field| {
            repr.tag = .record_field;
            repr.data[0] = try tree.addType(field.type);
            repr.data[1] = packOptIndex(field.bit_width);
            repr.tok = field.name_or_first_tok;
        },
        .labeled_stmt => |labeled| {
            repr.tag = .labeled_stmt;
            repr.data[0] = try tree.addType(labeled.type);
            repr.data[1] = @intFromEnum(labeled.body);
            repr.tok = labeled.label_tok;
        },
        .compound_stmt => |compound| {
            if (compound.body.len > 3) {
                repr.tag = .compound_stmt;
                repr.data[0], repr.data[1] = try tree.addExtra(compound.body);
            } else {
                repr.tag = .compound_stmt_three;
                for (&repr.data, 0..) |*data, idx|
                    data.* = packElem(compound.body, idx);
            }
            repr.tok = compound.l_brace_tok;
        },
        .if_stmt => |@"if"| {
            repr.tag = .if_stmt;
            repr.data[0] = @intFromEnum(@"if".cond);
            repr.data[1] = @intFromEnum(@"if".then_body);
            repr.data[2] = packOptIndex(@"if".else_body);
            repr.tok = @"if".if_tok;
        },
        .switch_stmt => |@"switch"| {
            repr.tag = .switch_stmt;
            repr.data[0] = @intFromEnum(@"switch".cond);
            repr.data[1] = @intFromEnum(@"switch".body);
            repr.tok = @"switch".switch_tok;
        },
        .case_stmt => |case| {
            repr.tag = .case_stmt;
            repr.data[0] = @intFromEnum(case.start);
            repr.data[1] = packOptIndex(case.end);
            repr.data[2] = packOptIndex(case.body);
            repr.tok = case.case_tok;
        },
        .default_stmt => |default| {
            repr.tag = .default_stmt;
            repr.data[0] = @intFromEnum(default.body);
            repr.tok = default.default_tok;
        },
        .while_stmt => |@"while"| {
            repr.tag = .while_stmt;
            repr.data[0] = @intFromEnum(@"while".cond);
            repr.data[1] = @intFromEnum(@"while".body);
            repr.tok = @"while".while_tok;
        },
        .do_while_stmt => |do_while| {
            repr.tag = .do_while_stmt;
            repr.data[0] = @intFromEnum(do_while.cond);
            repr.data[1] = @intFromEnum(do_while.body);
            repr.tok = do_while.do_tok;
        },
        .for_stmt => |@"for"| {
            switch (@"for".init) {
                .decls => |decls| {
                    repr.tag = .for_decl;
                    repr.data[0] = @intCast(tree.extra.items.len);
                    const len: u32 = @intCast(decls.len + 2);
                    try tree.extra.ensureUnusedCapacity(tree.comp.gpa, len);
                    repr.data[1] = len;
                    tree.extra.appendSliceAssumeCapacity(@ptrCast(decls));
                    tree.extra.appendAssumeCapacity(packOptIndex(@"for".cond));
                    tree.extra.appendAssumeCapacity(packOptIndex(@"for".incr));
                },
                .expr => |expr| {
                    repr.tag = .for_expr;
                    repr.data[0] = packOptIndex(expr);
                    repr.data[1] = @intCast(tree.extra.items.len);
                    try tree.extra.ensureUnusedCapacity(tree.comp.gpa, 2);
                    tree.extra.appendAssumeCapacity(packOptIndex(@"for".cond));
                    tree.extra.appendAssumeCapacity(packOptIndex(@"for".incr));
                },
            }
            repr.data[2] = @intFromEnum(@"for".body);
            repr.tok = @"for".for_tok;
        },
        .goto_stmt => |goto| {
            repr.tag = .goto_stmt;
            repr.tok = goto.label_tok;
        },
        .computed_goto_stmt => |computed_goto| {
            repr.tag = .computed_goto_stmt;
            repr.data[0] = @intFromEnum(computed_goto.expr);
            repr.tok = computed_goto.goto_tok;
        },
        .continue_stmt => |@"continue"| {
            repr.tag = .continue_stmt;
            repr.tok = @"continue".continue_tok;
        },
        .break_stmt => |@"break"| {
            repr.tag = .break_stmt;
            repr.tok = @"break".break_tok;
        },
        .null_stmt => |@"null"| {
            repr.tag = .null_stmt;
            repr.data[0] = try tree.addType(@"null".type);
            repr.tok = @"null".semicolon_or_r_brace_tok;
        },
        .return_stmt => |@"return"| {
            repr.tag = .return_stmt;
            repr.data[0] = try tree.addType(@"return".return_type);
            repr.data[1] = packOptIndex(@"return".expr);
            repr.tok = @"return".return_tok;
        },
        .implicit_return => |implicit_return| {
            repr.tag = .implicit_return;
            repr.data[0] = try tree.addType(implicit_return.return_type);
            repr.data[1] = @intFromBool(implicit_return.zero);
            repr.tok = implicit_return.r_brace_tok;
        },
        .gnu_asm_simple => |gnu_asm_simple| {
            repr.tag = .gnu_asm_simple;
            repr.data[0] = @intFromEnum(gnu_asm_simple.asm_str);
            repr.tok = gnu_asm_simple.asm_tok;
        },
        .comma_expr => |bin| {
            repr.tag = .comma_expr;
            repr.data[0] = try tree.addType(bin.type);
            repr.data[1] = @intFromEnum(bin.lhs);
            repr.data[2] = @intFromEnum(bin.rhs);
            repr.tok = bin.op_tok;
        },
        .assign_expr => |bin| {
            repr.tag = .assign_expr;
            repr.data[0] = try tree.addType(bin.type);
            repr.data[1] = @intFromEnum(bin.lhs);
            repr.data[2] = @intFromEnum(bin.rhs);
            repr.tok = bin.op_tok;
        },
        .mul_assign_expr => |bin| {
            repr.tag = .mul_assign_expr;
            repr.data[0] = try tree.addType(bin.type);
            repr.data[1] = @intFromEnum(bin.lhs);
            repr.data[2] = @intFromEnum(bin.rhs);
            repr.tok = bin.op_tok;
        },
        .div_assign_expr => |bin| {
            repr.tag = .div_assign_expr;
            repr.data[0] = try tree.addType(bin.type);
            repr.data[1] = @intFromEnum(bin.lhs);
            repr.data[2] = @intFromEnum(bin.rhs);
            repr.tok = bin.op_tok;
        },
        .mod_assign_expr => |bin| {
            repr.tag = .mod_assign_expr;
            repr.data[0] = try tree.addType(bin.type);
            repr.data[1] = @intFromEnum(bin.lhs);
            repr.data[2] = @intFromEnum(bin.rhs);
            repr.tok = bin.op_tok;
        },
        .add_assign_expr => |bin| {
            repr.tag = .add_assign_expr;
            repr.data[0] = try tree.addType(bin.type);
            repr.data[1] = @intFromEnum(bin.lhs);
            repr.data[2] = @intFromEnum(bin.rhs);
            repr.tok = bin.op_tok;
        },
        .sub_assign_expr => |bin| {
            repr.tag = .sub_assign_expr;
            repr.data[0] = try tree.addType(bin.type);
            repr.data[1] = @intFromEnum(bin.lhs);
            repr.data[2] = @intFromEnum(bin.rhs);
            repr.tok = bin.op_tok;
        },
        .shl_assign_expr => |bin| {
            repr.tag = .shl_assign_expr;
            repr.data[0] = try tree.addType(bin.type);
            repr.data[1] = @intFromEnum(bin.lhs);
            repr.data[2] = @intFromEnum(bin.rhs);
            repr.tok = bin.op_tok;
        },
        .shr_assign_expr => |bin| {
            repr.tag = .shr_assign_expr;
            repr.data[0] = try tree.addType(bin.type);
            repr.data[1] = @intFromEnum(bin.lhs);
            repr.data[2] = @intFromEnum(bin.rhs);
            repr.tok = bin.op_tok;
        },
        .bit_and_assign_expr => |bin| {
            repr.tag = .bit_and_assign_expr;
            repr.data[0] = try tree.addType(bin.type);
            repr.data[1] = @intFromEnum(bin.lhs);
            repr.data[2] = @intFromEnum(bin.rhs);
            repr.tok = bin.op_tok;
        },
        .bit_xor_assign_expr => |bin| {
            repr.tag = .bit_xor_assign_expr;
            repr.data[0] = try tree.addType(bin.type);
            repr.data[1] = @intFromEnum(bin.lhs);
            repr.data[2] = @intFromEnum(bin.rhs);
            repr.tok = bin.op_tok;
        },
        .bit_or_assign_expr => |bin| {
            repr.tag = .bit_or_assign_expr;
            repr.data[0] = try tree.addType(bin.type);
            repr.data[1] = @intFromEnum(bin.lhs);
            repr.data[2] = @intFromEnum(bin.rhs);
            repr.tok = bin.op_tok;
        },
        .bool_or_expr => |bin| {
            repr.tag = .bool_or_expr;
            repr.data[0] = try tree.addType(bin.type);
            repr.data[1] = @intFromEnum(bin.lhs);
            repr.data[2] = @intFromEnum(bin.rhs);
            repr.tok = bin.op_tok;
        },
        .bool_and_expr => |bin| {
            repr.tag = .bool_and_expr;
            repr.data[0] = try tree.addType(bin.type);
            repr.data[1] = @intFromEnum(bin.lhs);
            repr.data[2] = @intFromEnum(bin.rhs);
            repr.tok = bin.op_tok;
        },
        .bit_or_expr => |bin| {
            repr.tag = .bit_or_expr;
            repr.data[0] = try tree.addType(bin.type);
            repr.data[1] = @intFromEnum(bin.lhs);
            repr.data[2] = @intFromEnum(bin.rhs);
            repr.tok = bin.op_tok;
        },
        .bit_xor_expr => |bin| {
            repr.tag = .bit_xor_expr;
            repr.data[0] = try tree.addType(bin.type);
            repr.data[1] = @intFromEnum(bin.lhs);
            repr.data[2] = @intFromEnum(bin.rhs);
            repr.tok = bin.op_tok;
        },
        .bit_and_expr => |bin| {
            repr.tag = .bit_and_expr;
            repr.data[0] = try tree.addType(bin.type);
            repr.data[1] = @intFromEnum(bin.lhs);
            repr.data[2] = @intFromEnum(bin.rhs);
            repr.tok = bin.op_tok;
        },
        .equal_expr => |bin| {
            repr.tag = .equal_expr;
            repr.data[0] = try tree.addType(bin.type);
            repr.data[1] = @intFromEnum(bin.lhs);
            repr.data[2] = @intFromEnum(bin.rhs);
            repr.tok = bin.op_tok;
        },
        .not_equal_expr => |bin| {
            repr.tag = .not_equal_expr;
            repr.data[0] = try tree.addType(bin.type);
            repr.data[1] = @intFromEnum(bin.lhs);
            repr.data[2] = @intFromEnum(bin.rhs);
            repr.tok = bin.op_tok;
        },
        .less_than_expr => |bin| {
            repr.tag = .less_than_expr;
            repr.data[0] = try tree.addType(bin.type);
            repr.data[1] = @intFromEnum(bin.lhs);
            repr.data[2] = @intFromEnum(bin.rhs);
            repr.tok = bin.op_tok;
        },
        .less_than_equal_expr => |bin| {
            repr.tag = .less_than_equal_expr;
            repr.data[0] = try tree.addType(bin.type);
            repr.data[1] = @intFromEnum(bin.lhs);
            repr.data[2] = @intFromEnum(bin.rhs);
            repr.tok = bin.op_tok;
        },
        .greater_than_expr => |bin| {
            repr.tag = .greater_than_expr;
            repr.data[0] = try tree.addType(bin.type);
            repr.data[1] = @intFromEnum(bin.lhs);
            repr.data[2] = @intFromEnum(bin.rhs);
            repr.tok = bin.op_tok;
        },
        .greater_than_equal_expr => |bin| {
            repr.tag = .greater_than_equal_expr;
            repr.data[0] = try tree.addType(bin.type);
            repr.data[1] = @intFromEnum(bin.lhs);
            repr.data[2] = @intFromEnum(bin.rhs);
            repr.tok = bin.op_tok;
        },
        .shl_expr => |bin| {
            repr.tag = .shl_expr;
            repr.data[0] = try tree.addType(bin.type);
            repr.data[1] = @intFromEnum(bin.lhs);
            repr.data[2] = @intFromEnum(bin.rhs);
            repr.tok = bin.op_tok;
        },
        .shr_expr => |bin| {
            repr.tag = .shr_expr;
            repr.data[0] = try tree.addType(bin.type);
            repr.data[1] = @intFromEnum(bin.lhs);
            repr.data[2] = @intFromEnum(bin.rhs);
            repr.tok = bin.op_tok;
        },
        .add_expr => |bin| {
            repr.tag = .add_expr;
            repr.data[0] = try tree.addType(bin.type);
            repr.data[1] = @intFromEnum(bin.lhs);
            repr.data[2] = @intFromEnum(bin.rhs);
            repr.tok = bin.op_tok;
        },
        .sub_expr => |bin| {
            repr.tag = .sub_expr;
            repr.data[0] = try tree.addType(bin.type);
            repr.data[1] = @intFromEnum(bin.lhs);
            repr.data[2] = @intFromEnum(bin.rhs);
            repr.tok = bin.op_tok;
        },
        .mul_expr => |bin| {
            repr.tag = .mul_expr;
            repr.data[0] = try tree.addType(bin.type);
            repr.data[1] = @intFromEnum(bin.lhs);
            repr.data[2] = @intFromEnum(bin.rhs);
            repr.tok = bin.op_tok;
        },
        .div_expr => |bin| {
            repr.tag = .div_expr;
            repr.data[0] = try tree.addType(bin.type);
            repr.data[1] = @intFromEnum(bin.lhs);
            repr.data[2] = @intFromEnum(bin.rhs);
            repr.tok = bin.op_tok;
        },
        .mod_expr => |bin| {
            repr.tag = .mod_expr;
            repr.data[0] = try tree.addType(bin.type);
            repr.data[1] = @intFromEnum(bin.lhs);
            repr.data[2] = @intFromEnum(bin.rhs);
            repr.tok = bin.op_tok;
        },
        .explicit_cast => |cast| {
            repr.tag = .explicit_cast;
            repr.data[0] = try tree.addType(cast.type);
            repr.data[1] = @intFromEnum(cast.kind);
            repr.data[2] = @intFromEnum(cast.operand);
            repr.tok = cast.l_paren;
        },
        .implicit_cast => |cast| {
            repr.tag = .implicit_cast;
            repr.data[0] = try tree.addType(cast.type);
            repr.data[1] = @intFromEnum(cast.kind);
            repr.data[2] = @intFromEnum(cast.operand);
            repr.tok = cast.l_paren;
        },
        .addr_of_expr => |un| {
            repr.tag = .addr_of_expr;
            repr.data[0] = try tree.addType(un.type);
            repr.data[1] = @intFromEnum(un.operand);
            repr.tok = un.op_tok;
        },
        .deref_expr => |un| {
            repr.tag = .deref_expr;
            repr.data[0] = try tree.addType(un.type);
            repr.data[1] = @intFromEnum(un.operand);
            repr.tok = un.op_tok;
        },
        .plus_expr => |un| {
            repr.tag = .plus_expr;
            repr.data[0] = try tree.addType(un.type);
            repr.data[1] = @intFromEnum(un.operand);
            repr.tok = un.op_tok;
        },
        .negate_expr => |un| {
            repr.tag = .negate_expr;
            repr.data[0] = try tree.addType(un.type);
            repr.data[1] = @intFromEnum(un.operand);
            repr.tok = un.op_tok;
        },
        .bit_not_expr => |un| {
            repr.tag = .bit_not_expr;
            repr.data[0] = try tree.addType(un.type);
            repr.data[1] = @intFromEnum(un.operand);
            repr.tok = un.op_tok;
        },
        .bool_not_expr => |un| {
            repr.tag = .bool_not_expr;
            repr.data[0] = try tree.addType(un.type);
            repr.data[1] = @intFromEnum(un.operand);
            repr.tok = un.op_tok;
        },
        .pre_inc_expr => |un| {
            repr.tag = .pre_inc_expr;
            repr.data[0] = try tree.addType(un.type);
            repr.data[1] = @intFromEnum(un.operand);
            repr.tok = un.op_tok;
        },
        .pre_dec_expr => |un| {
            repr.tag = .pre_dec_expr;
            repr.data[0] = try tree.addType(un.type);
            repr.data[1] = @intFromEnum(un.operand);
            repr.tok = un.op_tok;
        },
        .imag_expr => |un| {
            repr.tag = .imag_expr;
            repr.data[0] = try tree.addType(un.type);
            repr.data[1] = @intFromEnum(un.operand);
            repr.tok = un.op_tok;
        },
        .real_expr => |un| {
            repr.tag = .real_expr;
            repr.data[0] = try tree.addType(un.type);
            repr.data[1] = @intFromEnum(un.operand);
            repr.tok = un.op_tok;
        },
        .post_inc_expr => |un| {
            repr.tag = .post_inc_expr;
            repr.data[0] = try tree.addType(un.type);
            repr.data[1] = @intFromEnum(un.operand);
            repr.tok = un.op_tok;
        },
        .post_dec_expr => |un| {
            repr.tag = .post_dec_expr;
            repr.data[0] = try tree.addType(un.type);
            repr.data[1] = @intFromEnum(un.operand);
            repr.tok = un.op_tok;
        },
        .paren_expr => |un| {
            repr.tag = .paren_expr;
            repr.data[0] = try tree.addType(un.type);
            repr.data[1] = @intFromEnum(un.operand);
            repr.tok = un.op_tok;
        },
        .stmt_expr => |un| {
            repr.tag = .stmt_expr;
            repr.data[0] = try tree.addType(un.type);
            repr.data[1] = @intFromEnum(un.operand);
            repr.tok = un.op_tok;
        },
        .cond_dummy_expr => |un| {
            repr.tag = .cond_dummy_expr;
            repr.data[0] = try tree.addType(un.type);
            repr.data[1] = @intFromEnum(un.operand);
            repr.tok = un.op_tok;
        },
        .addr_of_label => |addr_of| {
            repr.tag = .addr_of_label;
            repr.data[0] = try tree.addType(addr_of.type);
            repr.tok = addr_of.label_tok;
        },
        .array_access_expr => |access| {
            repr.tag = .array_access_expr;
            repr.data[0] = try tree.addType(access.type);
            repr.data[1] = @intFromEnum(access.base);
            repr.data[2] = @intFromEnum(access.index);
            repr.tok = access.l_bracket_tok;
        },
        .call_expr => |call| {
            repr.data[0] = try tree.addType(call.type);
            if (call.args.len > 1) {
                repr.tag = .call_expr;
                repr.data[1] = @intCast(tree.extra.items.len);
                const len: u32 = @intCast(call.args.len + 1);
                repr.data[2] = len;
                try tree.extra.ensureUnusedCapacity(tree.comp.gpa, len);
                tree.extra.appendAssumeCapacity(@intFromEnum(call.callee));
                tree.extra.appendSliceAssumeCapacity(@ptrCast(call.args));
            } else {
                repr.tag = .call_expr_one;
                repr.data[1] = @intFromEnum(call.callee);
                repr.data[2] = packElem(call.args, 0);
            }
            repr.tok = call.l_paren_tok;
        },
        .builtin_call_expr => |call| {
            repr.data[0] = try tree.addType(call.type);
            if (call.args.len > 2) {
                repr.tag = .builtin_call_expr;
                repr.data[1], repr.data[2] = try tree.addExtra(call.args);
            } else {
                repr.tag = .builtin_call_expr_two;
                repr.data[1] = packElem(call.args, 0);
                repr.data[2] = packElem(call.args, 1);
            }
            repr.tok = call.builtin_tok;
        },
        .member_access_expr => |access| {
            repr.tag = .member_access_expr;
            repr.data[0] = try tree.addType(access.type);
            repr.data[1] = @intFromEnum(access.base);
            repr.data[2] = access.member_index;
            repr.tok = access.access_tok;
        },
        .member_access_ptr_expr => |access| {
            repr.tag = .member_access_ptr_expr;
            repr.data[0] = try tree.addType(access.type);
            repr.data[1] = @intFromEnum(access.base);
            repr.data[2] = access.member_index;
            repr.tok = access.access_tok;
        },
        .decl_ref_expr => |decl_ref| {
            repr.tag = .decl_ref_expr;
            repr.data[0] = try tree.addType(decl_ref.type);
            repr.data[1] = @intFromEnum(decl_ref.decl);
            repr.tok = decl_ref.name_tok;
        },
        .enumeration_ref => |enumeration_ref| {
            repr.tag = .enumeration_ref;
            repr.data[0] = try tree.addType(enumeration_ref.type);
            repr.tok = enumeration_ref.name_tok;
        },
        .builtin_ref => |builtin_ref| {
            repr.tag = .builtin_ref;
            repr.data[0] = try tree.addType(builtin_ref.type);
            repr.tok = builtin_ref.name_tok;
        },
        .bool_literal => |literal| {
            repr.tag = .bool_literal;
            repr.data[0] = try tree.addType(literal.type);
            repr.tok = literal.literal_tok;
        },
        .nullptr_literal => |literal| {
            repr.tag = .nullptr_literal;
            repr.data[0] = try tree.addType(literal.type);
            repr.tok = literal.literal_tok;
        },
        .int_literal => |literal| {
            repr.tag = .int_literal;
            repr.data[0] = try tree.addType(literal.type);
            repr.tok = literal.literal_tok;
        },
        .char_literal => |literal| {
            repr.tag = .char_literal;
            repr.data[0] = try tree.addType(literal.type);
            repr.tok = literal.literal_tok;
        },
        .float_literal => |literal| {
            repr.tag = .float_literal;
            repr.data[0] = try tree.addType(literal.type);
            repr.tok = literal.literal_tok;
        },
        .string_literal_expr => |literal| {
            repr.tag = .string_literal_expr;
            repr.data[0] = try tree.addType(literal.type);
            repr.tok = literal.literal_tok;
        },
        .imaginary_literal => |un| {
            repr.tag = .imaginary_literal;
            repr.data[0] = try tree.addType(un.type);
            repr.data[1] = @intFromEnum(un.operand);
            repr.tok = un.op_tok;
        },
        .sizeof_expr => |type_info| {
            repr.tag = .sizeof_expr;
            repr.data[0] = try tree.addType(type_info.type);
            repr.data[1] = packOptIndex(type_info.expr);
            repr.tok = type_info.op_tok;
        },
        .alignof_expr => |type_info| {
            repr.tag = .alignof_expr;
            repr.data[0] = try tree.addType(type_info.type);
            repr.data[1] = packOptIndex(type_info.expr);
            repr.tok = type_info.op_tok;
        },
        .generic_expr => |generic| {
            repr.data[0] = try tree.addType(generic.type);
            if (generic.rest.len > 0) {
                repr.tag = .generic_expr;
                repr.data[1] = @intCast(tree.extra.items.len);
                const len: u32 = @intCast(generic.rest.len + 2);
                repr.data[2] = len;
                try tree.extra.ensureUnusedCapacity(tree.comp.gpa, len);
                tree.extra.appendAssumeCapacity(@intFromEnum(generic.controlling));
                tree.extra.appendAssumeCapacity(@intFromEnum(generic.chosen));
                tree.extra.appendSliceAssumeCapacity(@ptrCast(generic.rest));
            } else {
                repr.tag = .generic_expr_zero;
                repr.data[1] = @intFromEnum(generic.controlling);
                repr.data[2] = @intFromEnum(generic.chosen);
            }
            repr.tok = generic.generic_tok;
        },
        .generic_association_expr => |association| {
            repr.tag = .generic_association_expr;
            repr.data[0] = try tree.addType(association.association_type);
            repr.data[1] = @intFromEnum(association.expr);
            repr.tok = association.colon_tok;
        },
        .generic_default_expr => |default| {
            repr.tag = .generic_default_expr;
            repr.data[0] = @intFromEnum(default.expr);
            repr.tok = default.default_tok;
        },
        .binary_cond_expr => |cond| {
            repr.tag = .binary_cond_expr;
            repr.data[0] = try tree.addType(cond.type);
            repr.data[1] = @intFromEnum(cond.cond);
            repr.data[2], _ = try tree.addExtra(&.{ cond.then_expr, cond.else_expr });
            repr.tok = cond.cond_tok;
        },
        .cond_expr => |cond| {
            repr.tag = .cond_expr;
            repr.data[0] = try tree.addType(cond.type);
            repr.data[1] = @intFromEnum(cond.cond);
            repr.data[2], _ = try tree.addExtra(&.{ cond.then_expr, cond.else_expr });
            repr.tok = cond.cond_tok;
        },
        .builtin_choose_expr => |cond| {
            repr.tag = .builtin_choose_expr;
            repr.data[0] = try tree.addType(cond.type);
            repr.data[1] = @intFromEnum(cond.cond);
            repr.data[2], _ = try tree.addExtra(&.{ cond.then_expr, cond.else_expr });
            repr.tok = cond.cond_tok;
        },
        .builtin_types_compatible_p => |builtin| {
            repr.tag = .builtin_types_compatible_p;
            repr.data[0] = try tree.addType(builtin.lhs);
            repr.data[1] = try tree.addType(builtin.rhs);
            repr.tok = builtin.builtin_tok;
        },
        .array_init_expr => |init| {
            repr.data[0] = try tree.addType(init.container_type);
            if (init.items.len > 2) {
                repr.tag = .array_init_expr;
                repr.data[1], repr.data[2] = try tree.addExtra(init.items);
            } else {
                repr.tag = .array_init_expr_two;
                repr.data[1] = packElem(init.items, 0);
                repr.data[2] = packElem(init.items, 1);
            }
            repr.tok = init.l_brace_tok;
        },
        .struct_init_expr => |init| {
            repr.data[0] = try tree.addType(init.container_type);
            if (init.items.len > 2) {
                repr.tag = .struct_init_expr;
                repr.data[1], repr.data[2] = try tree.addExtra(init.items);
            } else {
                repr.tag = .struct_init_expr_two;
                repr.data[1] = packElem(init.items, 0);
                repr.data[2] = packElem(init.items, 1);
            }
            repr.tok = init.l_brace_tok;
        },
        .union_init_expr => |init| {
            repr.tag = .union_init_expr;
            repr.data[0] = try tree.addType(init.union_type);
            repr.data[1] = init.field_index;
            repr.data[2] = packOptIndex(init.initializer);
            repr.tok = init.l_brace_tok;
        },
        .array_filler_expr => |filler| {
            repr.tag = .array_filler_expr;
            repr.data[0] = try tree.addType(filler.type);
            repr.data[1], repr.data[2] = @as([2]u32, @bitCast(filler.count));
            repr.tok = filler.last_tok;
        },
        .default_init_expr => |default| {
            repr.tag = .default_init_expr;
            repr.data[0] = try tree.addType(default.type);
            repr.tok = default.last_tok;
        },
        .compound_literal_expr => |literal| {
            repr.tag = .compound_literal_expr;
            repr.data[0] = try tree.addType(literal.type);
            repr.data[1] = @bitCast(Node.Repr.DeclAttr{
                .static = literal.storage_class == .static,
                .register = literal.storage_class == .register,
                .thread_local = literal.thread_local,
            });
            repr.data[2] = @intFromEnum(literal.initializer);
            repr.tok = literal.l_paren_tok;
        },
    }
    tree.nodes.set(index, repr);
}

fn packOptIndex(opt: ?Node.Index) u32 {
    return @intFromEnum(Node.OptIndex.packOpt(opt));
}

fn unpackOptIndex(idx: u32) ?Node.Index {
    return @as(Node.OptIndex, @enumFromInt(idx)).unpack();
}

fn packElem(nodes: []const Node.Index, index: usize) u32 {
    return if (nodes.len > index) @intFromEnum(nodes[index]) else @intFromEnum(Node.OptIndex.null);
}

fn unPackElems(data: []const u32) []const Node.Index {
    const sentinel = @intFromEnum(Node.OptIndex.null);
    for (data, 0..) |item, i| {
        if (item == sentinel) return @ptrCast(data[0..i]);
    }
    return @ptrCast(data);
}

fn addType(tree: *Tree, ty: Type) !u32 {
    const gop = try tree.type_map.getOrPut(tree.comp.gpa, ty);
    return @intCast(gop.index);
}

/// Returns index to `tree.extra` and length of data
fn addExtra(tree: *Tree, data: []const Node.Index) !struct { u32, u32 } {
    const index: u32 = @intCast(tree.extra.items.len);
    try tree.extra.appendSlice(tree.comp.gpa, @ptrCast(data));
    return .{ index, @intCast(data.len) };
}

pub fn isBitfield(tree: *const Tree, node: Node.Index) bool {
    return tree.bitfieldWidth(node, false) != null;
}

/// Returns null if node is not a bitfield. If inspect_lval is true, this function will
/// recurse into implicit lval_to_rval casts (useful for arithmetic conversions)
pub fn bitfieldWidth(tree: *const Tree, node: Node.Index, inspect_lval: bool) ?u32 {
    switch (node.get(tree)) {
        .member_access_expr, .member_access_ptr_expr => |access| return access.isBitFieldWidth(tree),
        .implicit_cast => |cast| {
            if (!inspect_lval) return null;

            return switch (cast.kind) {
                .lval_to_rval => tree.bitfieldWidth(cast.operand, false),
                else => null,
            };
        },
        else => return null,
    }
}

const CallableResultUsage = struct {
    /// name token of the thing being called, for diagnostics
    tok: TokenIndex,
    /// true if `nodiscard` attribute present
    nodiscard: bool,
    /// true if `warn_unused_result` attribute present
    warn_unused_result: bool,
};

pub fn callableResultUsage(tree: *const Tree, node: Node.Index) ?CallableResultUsage {
    var cur_node = node;
    while (true) switch (cur_node.get(tree)) {
        .decl_ref_expr => |decl_ref| return .{
            .tok = decl_ref.name_tok,
            .nodiscard = decl_ref.type.hasAttribute(.nodiscard),
            .warn_unused_result = decl_ref.type.hasAttribute(.warn_unused_result),
        },

        .paren_expr, .addr_of_expr, .deref_expr => |un| cur_node = un.operand,
        .comma_expr => |bin| cur_node = bin.rhs,
        .explicit_cast, .implicit_cast => |cast| cur_node = cast.operand,
        .call_expr => |call| cur_node = call.callee,
        .member_access_expr, .member_access_ptr_expr => |access| {
            var ty = access.base.type(tree);
            if (ty.isPtr()) ty = ty.elemType();
            const record = ty.getRecord().?;
            const field = record.fields[access.member_index];
            const attributes = if (record.field_attributes) |attrs| attrs[access.member_index] else &.{};
            return .{
                .tok = field.name_tok,
                .nodiscard = for (attributes) |attr| {
                    if (attr.tag == .nodiscard) break true;
                } else false,
                .warn_unused_result = for (attributes) |attr| {
                    if (attr.tag == .warn_unused_result) break true;
                } else false,
            };
        },
        else => return null,
    };
}

pub fn isLval(tree: *const Tree, node: Node.Index) bool {
    var is_const: bool = undefined;
    return tree.isLvalExtra(node, &is_const);
}

pub fn isLvalExtra(tree: *const Tree, node: Node.Index, is_const: *bool) bool {
    is_const.* = false;
    var cur_node = node;
    switch (cur_node.get(tree)) {
        .compound_literal_expr => |literal| {
            is_const.* = literal.type.isConst();
            return true;
        },
        .string_literal_expr => return true,
        .member_access_ptr_expr => |access| {
            const ptr_ty = access.base.type(tree);
            if (ptr_ty.isPtr()) is_const.* = ptr_ty.elemType().isConst();
            return true;
        },
        .array_access_expr => |access| {
            const array_ty = access.base.type(tree);
            if (array_ty.isPtr() or array_ty.isArray()) is_const.* = array_ty.elemType().isConst();
            return true;
        },
        .decl_ref_expr => |decl_ref| {
            is_const.* = decl_ref.type.isConst();
            return true;
        },
        .deref_expr => |un| {
            const operand_ty = un.operand.type(tree);
            if (operand_ty.isFunc()) return false;
            if (operand_ty.isPtr() or operand_ty.isArray()) is_const.* = operand_ty.elemType().isConst();
            return true;
        },
        .member_access_expr => |access| {
            return tree.isLvalExtra(access.base, is_const);
        },
        .paren_expr => |un| {
            return tree.isLvalExtra(un.operand, is_const);
        },
        .builtin_choose_expr => |conditional| {
            if (tree.value_map.get(conditional.cond)) |val| {
                if (!val.isZero(tree.comp)) {
                    return tree.isLvalExtra(conditional.then_expr, is_const);
                } else {
                    return tree.isLvalExtra(conditional.else_expr, is_const);
                }
            }
            return false;
        },
        else => return false,
    }
}

pub fn tokSlice(tree: *const Tree, tok_i: TokenIndex) []const u8 {
    if (tree.tokens.items(.id)[tok_i].lexeme()) |some| return some;
    const loc = tree.tokens.items(.loc)[tok_i];
    return tree.comp.locSlice(loc);
}

pub fn dump(tree: *const Tree, config: std.io.tty.Config, writer: anytype) !void {
    const mapper = tree.comp.string_interner.getFastTypeMapper(tree.comp.gpa) catch tree.comp.string_interner.getSlowTypeMapper();
    defer mapper.deinit(tree.comp.gpa);

    for (tree.root_decls.items) |i| {
        try tree.dumpNode(i, 0, mapper, config, writer);
        try writer.writeByte('\n');
    }
}

fn dumpFieldAttributes(tree: *const Tree, attributes: []const Attribute, level: u32, writer: anytype) !void {
    for (attributes) |attr| {
        try writer.writeByteNTimes(' ', level);
        try writer.print("field attr: {s}", .{@tagName(attr.tag)});
        try tree.dumpAttribute(attr, writer);
    }
}

fn dumpAttribute(tree: *const Tree, attr: Attribute, writer: anytype) !void {
    switch (attr.tag) {
        inline else => |tag| {
            const args = @field(attr.args, @tagName(tag));
            const fields = @typeInfo(@TypeOf(args)).@"struct".fields;
            if (fields.len == 0) {
                try writer.writeByte('\n');
                return;
            }
            try writer.writeByte(' ');
            inline for (fields, 0..) |f, i| {
                if (comptime std.mem.eql(u8, f.name, "__name_tok")) continue;
                if (i != 0) {
                    try writer.writeAll(", ");
                }
                try writer.writeAll(f.name);
                try writer.writeAll(": ");
                switch (f.type) {
                    Interner.Ref => try writer.print("\"{s}\"", .{tree.interner.get(@field(args, f.name)).bytes}),
                    ?Interner.Ref => try writer.print("\"{?s}\"", .{if (@field(args, f.name)) |str| tree.interner.get(str).bytes else null}),
                    else => switch (@typeInfo(f.type)) {
                        .@"enum" => try writer.writeAll(@tagName(@field(args, f.name))),
                        else => try writer.print("{any}", .{@field(args, f.name)}),
                    },
                }
            }
            try writer.writeByte('\n');
            return;
        },
    }
}

fn dumpNode(
    tree: *const Tree,
    node_index: Node.Index,
    level: u32,
    mapper: StringInterner.TypeMapper,
    config: std.io.tty.Config,
    w: anytype,
) !void {
    const delta = 2;
    const half = delta / 2;
    const TYPE = std.io.tty.Color.bright_magenta;
    const TAG = std.io.tty.Color.bright_cyan;
    const IMPLICIT = std.io.tty.Color.bright_blue;
    const NAME = std.io.tty.Color.bright_red;
    const LITERAL = std.io.tty.Color.bright_green;
    const ATTRIBUTE = std.io.tty.Color.bright_yellow;

    const node = node_index.get(tree);
    const ty = node_index.type(tree);
    try w.writeByteNTimes(' ', level);

    try config.setColor(w, if (node.isImplicit()) IMPLICIT else TAG);
    try w.print("{s}: ", .{@tagName(node)});
    switch (node) {
        .implicit_cast, .explicit_cast => |cast| {
            try config.setColor(w, .white);
            try w.print("({s}) ", .{@tagName(cast.kind)});
        },
        else => {},
    }

    try config.setColor(w, TYPE);
    try w.writeByte('\'');
    const name = ty.getName();
    if (name != .empty) {
        try w.print("{s}': '", .{mapper.lookup(name)});
    }
    try ty.dump(mapper, tree.comp.langopts, w);
    try w.writeByte('\'');

    if (tree.isLval(node_index)) {
        try config.setColor(w, ATTRIBUTE);
        try w.writeAll(" lvalue");
    }
    if (tree.isBitfield(node_index)) {
        try config.setColor(w, ATTRIBUTE);
        try w.writeAll(" bitfield");
    }

    if (tree.value_map.get(node_index)) |val| {
        try config.setColor(w, LITERAL);
        try w.writeAll(" (value: ");
        if (try val.print(ty, tree.comp, w)) |nested| switch (nested) {
            .pointer => |ptr| {
                switch (tree.nodes.items(.tag)[ptr.node]) {
                    .compound_literal_expr => {
                        try w.writeAll("(compound literal) ");
                        _ = try ptr.offset.print(tree.comp.types.ptrdiff, tree.comp, w);
                    },
                    else => {
                        const ptr_node: Node.Index = @enumFromInt(ptr.node);
                        const decl_name = tree.tokSlice(ptr_node.tok(tree));
                        try ptr.offset.printPointer(decl_name, tree.comp, w);
                    },
                }
            },
        };
        try w.writeByte(')');
    }
    if (node == .implicit_return and node.implicit_return.zero) {
        try config.setColor(w, IMPLICIT);
        try w.writeAll(" (value: 0)");
        try config.setColor(w, .reset);
    }

    try w.writeAll("\n");
    try config.setColor(w, .reset);

    if (ty.specifier == .attributed) {
        try config.setColor(w, ATTRIBUTE);
        var it = Attribute.Iterator.initType(ty);
        while (it.next()) |item| {
            const attr, _ = item;
            try w.writeByteNTimes(' ', level + half);
            try w.print("attr: {s}", .{@tagName(attr.tag)});
            try tree.dumpAttribute(attr, w);
        }
        try config.setColor(w, .reset);
    }

    switch (node) {
        .global_asm, .gnu_asm_simple => |@"asm"| {
            try w.writeByteNTimes(' ', level + 1);
            try tree.dumpNode(@"asm".asm_str, level + delta, mapper, config, w);
        },
        .static_assert => |assert| {
            try w.writeByteNTimes(' ', level + 1);
            try w.writeAll("condition:\n");
            try tree.dumpNode(assert.cond, level + delta, mapper, config, w);
            if (assert.message) |some| {
                try w.writeByteNTimes(' ', level + 1);
                try w.writeAll("diagnostic:\n");
                try tree.dumpNode(some, level + delta, mapper, config, w);
            }
        },
        .fn_proto => |proto| {
            try w.writeByteNTimes(' ', level + half);

            try config.setColor(w, ATTRIBUTE);
            if (proto.static) try w.writeAll("static ");
            if (proto.@"inline") try w.writeAll("inline ");

            try config.setColor(w, .reset);
            try w.writeAll("name: ");
            try config.setColor(w, NAME);
            try w.print("{s}\n", .{tree.tokSlice(proto.name_tok)});
            try config.setColor(w, .reset);
        },
        .fn_def => |def| {
            try w.writeByteNTimes(' ', level + half);

            try config.setColor(w, ATTRIBUTE);
            if (def.static) try w.writeAll("static ");
            if (def.@"inline") try w.writeAll("inline ");

            try config.setColor(w, .reset);
            try w.writeAll("name: ");
            try config.setColor(w, NAME);
            try w.print("{s}\n", .{tree.tokSlice(def.name_tok)});

            try config.setColor(w, .reset);
            try w.writeByteNTimes(' ', level + half);
            try w.writeAll("body:\n");
            try tree.dumpNode(def.body, level + delta, mapper, config, w);
        },
        .typedef => |typedef| {
            try w.writeByteNTimes(' ', level + half);
            try w.writeAll("name: ");
            try config.setColor(w, NAME);
            try w.print("{s}\n", .{tree.tokSlice(typedef.name_tok)});
            try config.setColor(w, .reset);
        },
        .param => |param| {
            try w.writeByteNTimes(' ', level + half);

            switch (param.storage_class) {
                .auto => {},
                .register => {
                    try config.setColor(w, ATTRIBUTE);
                    try w.writeAll("register ");
                    try config.setColor(w, .reset);
                },
            }

            try w.writeAll("name: ");
            try config.setColor(w, NAME);
            try w.print("{s}\n", .{tree.tokSlice(param.name_tok)});
            try config.setColor(w, .reset);
        },
        .variable => |variable| {
            try w.writeByteNTimes(' ', level + half);

            try config.setColor(w, ATTRIBUTE);
            switch (variable.storage_class) {
                .auto => {},
                .static => try w.writeAll("static "),
                .@"extern" => try w.writeAll("extern "),
                .register => try w.writeAll("register "),
            }
            if (variable.thread_local) try w.writeAll("thread_local ");
            if (variable.implicit) try w.writeAll("implicit ");
            try config.setColor(w, .reset);

            try w.writeAll("name: ");
            try config.setColor(w, NAME);
            try w.print("{s}\n", .{tree.tokSlice(variable.name_tok)});
            try config.setColor(w, .reset);

            if (variable.initializer) |some| {
                try config.setColor(w, .reset);
                try w.writeByteNTimes(' ', level + half);
                try w.writeAll("init:\n");
                try tree.dumpNode(some, level + delta, mapper, config, w);
            }
        },
        .enum_field => |field| {
            try w.writeByteNTimes(' ', level + half);
            try w.writeAll("name: ");
            try config.setColor(w, NAME);
            try w.print("{s}\n", .{tree.tokSlice(field.name_tok)});
            try config.setColor(w, .reset);
            if (field.init) |some| {
                try w.writeByteNTimes(' ', level + half);
                try w.writeAll("init:\n");
                try tree.dumpNode(some, level + delta, mapper, config, w);
            }
        },
        .record_field => |field| {
            const name_tok_id = tree.tokens.items(.id)[field.name_or_first_tok];
            if (name_tok_id == .identifier or name_tok_id == .extended_identifier) {
                try w.writeByteNTimes(' ', level + half);
                try w.writeAll("name: ");
                try config.setColor(w, NAME);
                try w.print("{s}\n", .{tree.tokSlice(field.name_or_first_tok)});
                try config.setColor(w, .reset);
            }
            if (field.bit_width) |some| {
                try w.writeByteNTimes(' ', level + half);
                try w.writeAll("bits:\n");
                try tree.dumpNode(some, level + delta, mapper, config, w);
            }
        },
        .compound_stmt => |compound| {
            for (compound.body, 0..) |stmt, i| {
                if (i != 0) try w.writeByte('\n');
                try tree.dumpNode(stmt, level + delta, mapper, config, w);
            }
        },
        .enum_decl => |decl| {
            for (decl.fields, 0..) |field, i| {
                if (i != 0) try w.writeByte('\n');
                try tree.dumpNode(field, level + delta, mapper, config, w);
            }
        },
        .struct_decl, .union_decl => |decl| {
            const maybe_field_attributes = if (ty.getRecord()) |record| record.field_attributes else null;
            for (decl.fields, 0..) |field, i| {
                if (i != 0) try w.writeByte('\n');
                try tree.dumpNode(field, level + delta, mapper, config, w);
                if (maybe_field_attributes) |field_attributes| {
                    if (field_attributes[i].len == 0) continue;

                    try config.setColor(w, ATTRIBUTE);
                    try tree.dumpFieldAttributes(field_attributes[i], level + delta + half, w);
                    try config.setColor(w, .reset);
                }
            }
        },
        .array_init_expr, .struct_init_expr => |init| {
            for (init.items, 0..) |item, i| {
                if (i != 0) try w.writeByte('\n');
                try tree.dumpNode(item, level + delta, mapper, config, w);
            }
        },
        .union_init_expr => |init| {
            try w.writeByteNTimes(' ', level + half);
            try w.writeAll("field index: ");
            try config.setColor(w, LITERAL);
            try w.print("{d}\n", .{init.field_index});
            try config.setColor(w, .reset);
            if (init.initializer) |some| {
                try tree.dumpNode(some, level + delta, mapper, config, w);
            }
        },
        .compound_literal_expr => |literal| {
            if (literal.storage_class != .auto or literal.thread_local) {
                try w.writeByteNTimes(' ', level + half - 1);

                try config.setColor(w, ATTRIBUTE);
                switch (literal.storage_class) {
                    .auto => {},
                    .static => try w.writeAll(" static"),
                    .register => try w.writeAll(" register"),
                }
                if (literal.thread_local) try w.writeAll(" thread_local");
                try w.writeByte('\n');
                try config.setColor(w, .reset);
            }

            try tree.dumpNode(literal.initializer, level + half, mapper, config, w);
        },
        .labeled_stmt => |labeled| {
            try w.writeByteNTimes(' ', level + half);
            try w.writeAll("label: ");
            try config.setColor(w, LITERAL);
            try w.print("{s}\n", .{tree.tokSlice(labeled.label_tok)});

            try config.setColor(w, .reset);
            try w.writeByteNTimes(' ', level + half);
            try w.writeAll("stmt:\n");
            try tree.dumpNode(labeled.body, level + delta, mapper, config, w);
        },
        .case_stmt => |case| {
            try w.writeByteNTimes(' ', level + half);

            if (case.end) |some| {
                try w.writeAll("range start:\n");
                try tree.dumpNode(case.start, level + delta, mapper, config, w);

                try w.writeByteNTimes(' ', level + half);
                try w.writeAll("range end:\n");
                try tree.dumpNode(some, level + delta, mapper, config, w);
            } else {
                try w.writeAll("value:\n");
                try tree.dumpNode(case.start, level + delta, mapper, config, w);
            }

            try w.writeByteNTimes(' ', level + half);
            try w.writeAll("stmt:\n");
            try tree.dumpNode(case.body, level + delta, mapper, config, w);
        },
        .default_stmt => |default| {
            try w.writeByteNTimes(' ', level + half);
            try w.writeAll("stmt:\n");
            try tree.dumpNode(default.body, level + delta, mapper, config, w);
        },
        .binary_cond_expr, .cond_expr, .builtin_choose_expr => |conditional| {
            try w.writeByteNTimes(' ', level + half);
            try w.writeAll("cond:\n");
            try tree.dumpNode(conditional.cond, level + delta, mapper, config, w);

            try w.writeByteNTimes(' ', level + half);
            try w.writeAll("then:\n");
            try tree.dumpNode(conditional.then_expr, level + delta, mapper, config, w);

            try w.writeByteNTimes(' ', level + half);
            try w.writeAll("else:\n");
            try tree.dumpNode(conditional.else_expr, level + delta, mapper, config, w);
        },
        .builtin_types_compatible_p => |call| {
            try w.writeByteNTimes(' ', level + half);
            try w.writeAll("lhs: ");
            try config.setColor(w, TYPE);
            try call.lhs.dump(mapper, tree.comp.langopts, w);
            try w.writeByte('\n');
            try config.setColor(w, .reset);

            try w.writeByteNTimes(' ', level + half);
            try w.writeAll("rhs: ");
            try config.setColor(w, TYPE);
            try call.rhs.dump(mapper, tree.comp.langopts, w);
            try w.writeByte('\n');
            try config.setColor(w, .reset);
        },
        .if_stmt => |@"if"| {
            try w.writeByteNTimes(' ', level + half);
            try w.writeAll("cond:\n");
            try tree.dumpNode(@"if".cond, level + delta, mapper, config, w);

            try w.writeByteNTimes(' ', level + half);
            try w.writeAll("then:\n");
            try tree.dumpNode(@"if".then_body, level + delta, mapper, config, w);

            if (@"if".else_body) |some| {
                try w.writeByteNTimes(' ', level + half);
                try w.writeAll("else:\n");
                try tree.dumpNode(some, level + delta, mapper, config, w);
            }
        },
        .switch_stmt => |@"switch"| {
            try w.writeByteNTimes(' ', level + half);
            try w.writeAll("cond:\n");
            try tree.dumpNode(@"switch".cond, level + delta, mapper, config, w);

            try w.writeByteNTimes(' ', level + half);
            try w.writeAll("body:\n");
            try tree.dumpNode(@"switch".body, level + delta, mapper, config, w);
        },
        .while_stmt => |@"while"| {
            try w.writeByteNTimes(' ', level + half);
            try w.writeAll("cond:\n");
            try tree.dumpNode(@"while".cond, level + delta, mapper, config, w);

            try w.writeByteNTimes(' ', level + half);
            try w.writeAll("body:\n");
            try tree.dumpNode(@"while".body, level + delta, mapper, config, w);
        },
        .do_while_stmt => |do| {
            try w.writeByteNTimes(' ', level + half);
            try w.writeAll("cond:\n");
            try tree.dumpNode(do.cond, level + delta, mapper, config, w);

            try w.writeByteNTimes(' ', level + half);
            try w.writeAll("body:\n");
            try tree.dumpNode(do.body, level + delta, mapper, config, w);
        },
        .for_stmt => |@"for"| {
            switch (@"for".init) {
                .decls => |decls| {
                    try w.writeByteNTimes(' ', level + half);
                    try w.writeAll("decl:\n");
                    for (decls) |decl| {
                        try tree.dumpNode(decl, level + delta, mapper, config, w);
                        try w.writeByte('\n');
                    }
                },
                .expr => |expr| if (expr) |some| {
                    try w.writeByteNTimes(' ', level + half);
                    try w.writeAll("init:\n");
                    try tree.dumpNode(some, level + delta, mapper, config, w);
                },
            }
            if (@"for".cond) |some| {
                try w.writeByteNTimes(' ', level + half);
                try w.writeAll("cond:\n");
                try tree.dumpNode(some, level + delta, mapper, config, w);
            }
            if (@"for".incr) |some| {
                try w.writeByteNTimes(' ', level + half);
                try w.writeAll("incr:\n");
                try tree.dumpNode(some, level + delta, mapper, config, w);
            }
            try w.writeByteNTimes(' ', level + half);
            try w.writeAll("body:\n");
            try tree.dumpNode(@"for".body, level + delta, mapper, config, w);
        },
        .addr_of_label => |addr| {
            try w.writeByteNTimes(' ', level + half);
            try w.writeAll("label: ");
            try config.setColor(w, LITERAL);
            try w.print("{s}\n", .{tree.tokSlice(addr.label_tok)});
            try config.setColor(w, .reset);
        },
        .goto_stmt => |goto| {
            try w.writeByteNTimes(' ', level + half);
            try w.writeAll("label: ");
            try config.setColor(w, LITERAL);
            try w.print("{s}\n", .{tree.tokSlice(goto.label_tok)});
            try config.setColor(w, .reset);
        },
        .computed_goto_stmt => |goto| {
            try w.writeByteNTimes(' ', level + half);
            try w.writeAll("expr:\n");
            try tree.dumpNode(goto.expr, level + delta, mapper, config, w);
        },
        .continue_stmt, .break_stmt, .implicit_return, .null_stmt => {},
        .return_stmt => |ret| {
            if (ret.expr) |some| {
                try w.writeByteNTimes(' ', level + half);
                try w.writeAll("expr:\n");
                try tree.dumpNode(some, level + delta, mapper, config, w);
            }
        },
        .call_expr => |call| {
            try w.writeByteNTimes(' ', level + half);
            try w.writeAll("callee:\n");
            try tree.dumpNode(call.callee, level + delta, mapper, config, w);

            if (call.args.len > 0) {
                try w.writeByteNTimes(' ', level + half);
                try w.writeAll("args:\n");
                for (call.args) |arg| {
                    try tree.dumpNode(arg, level + delta, mapper, config, w);
                }
            }
        },
        .builtin_call_expr => |call| {
            try w.writeByteNTimes(' ', level + half);
            try w.writeAll("name: ");
            try config.setColor(w, NAME);
            try w.print("{s}\n", .{tree.tokSlice(call.builtin_tok)});
            try config.setColor(w, .reset);

            if (call.args.len > 0) {
                try w.writeByteNTimes(' ', level + half);
                try w.writeAll("args:\n");
                for (call.args) |arg| {
                    try tree.dumpNode(arg, level + delta, mapper, config, w);
                }
            }
        },
        .comma_expr,
        .assign_expr,
        .mul_assign_expr,
        .div_assign_expr,
        .mod_assign_expr,
        .add_assign_expr,
        .sub_assign_expr,
        .shl_assign_expr,
        .shr_assign_expr,
        .bit_and_assign_expr,
        .bit_xor_assign_expr,
        .bit_or_assign_expr,
        .bool_or_expr,
        .bool_and_expr,
        .bit_or_expr,
        .bit_xor_expr,
        .bit_and_expr,
        .equal_expr,
        .not_equal_expr,
        .less_than_expr,
        .less_than_equal_expr,
        .greater_than_expr,
        .greater_than_equal_expr,
        .shl_expr,
        .shr_expr,
        .add_expr,
        .sub_expr,
        .mul_expr,
        .div_expr,
        .mod_expr,
        => |bin| {
            try w.writeByteNTimes(' ', level + 1);
            try w.writeAll("lhs:\n");
            try tree.dumpNode(bin.lhs, level + delta, mapper, config, w);

            try w.writeByteNTimes(' ', level + 1);
            try w.writeAll("rhs:\n");
            try tree.dumpNode(bin.rhs, level + delta, mapper, config, w);
        },
        .explicit_cast, .implicit_cast => |cast| try tree.dumpNode(cast.operand, level + delta, mapper, config, w),
        .addr_of_expr,
        .deref_expr,
        .plus_expr,
        .negate_expr,
        .bit_not_expr,
        .bool_not_expr,
        .pre_inc_expr,
        .pre_dec_expr,
        .imag_expr,
        .real_expr,
        .post_inc_expr,
        .post_dec_expr,
        .paren_expr,
        .stmt_expr,
        .imaginary_literal,
        => |un| {
            try w.writeByteNTimes(' ', level + 1);
            try w.writeAll("operand:\n");
            try tree.dumpNode(un.operand, level + delta, mapper, config, w);
        },
        .decl_ref_expr => |dr| {
            try w.writeByteNTimes(' ', level + 1);
            try w.writeAll("name: ");
            try config.setColor(w, NAME);
            try w.print("{s}\n", .{tree.tokSlice(dr.name_tok)});
            try config.setColor(w, .reset);
        },
        .builtin_ref, .enumeration_ref => |dr| {
            try w.writeByteNTimes(' ', level + 1);
            try w.writeAll("name: ");
            try config.setColor(w, NAME);
            try w.print("{s}\n", .{tree.tokSlice(dr.name_tok)});
            try config.setColor(w, .reset);
        },
        .bool_literal,
        .nullptr_literal,
        .int_literal,
        .char_literal,
        .float_literal,
        .string_literal_expr,
        => {},
        .member_access_expr, .member_access_ptr_expr => |access| {
            try w.writeByteNTimes(' ', level + 1);
            try w.writeAll("lhs:\n");
            try tree.dumpNode(access.base, level + delta, mapper, config, w);

            var base_ty = access.base.type(tree);
            if (base_ty.isPtr()) base_ty = base_ty.elemType();
            base_ty = base_ty.canonicalize(.standard);

            try w.writeByteNTimes(' ', level + 1);
            try w.writeAll("name: ");
            try config.setColor(w, NAME);
            try w.print("{s}\n", .{mapper.lookup(base_ty.data.record.fields[access.member_index].name)});
            try config.setColor(w, .reset);
        },
        .array_access_expr => |access| {
            try w.writeByteNTimes(' ', level + 1);
            try w.writeAll("base:\n");
            try tree.dumpNode(access.base, level + delta, mapper, config, w);

            try w.writeByteNTimes(' ', level + 1);
            try w.writeAll("index:\n");
            try tree.dumpNode(access.index, level + delta, mapper, config, w);
        },
        .sizeof_expr, .alignof_expr => |type_info| {
            if (type_info.expr) |some| {
                try w.writeByteNTimes(' ', level + 1);
                try w.writeAll("expr:\n");
                try tree.dumpNode(some, level + delta, mapper, config, w);
            }
        },
        .generic_expr => |generic| {
            try w.writeByteNTimes(' ', level + 1);
            try w.writeAll("controlling:\n");
            try tree.dumpNode(generic.controlling, level + delta, mapper, config, w);
            try w.writeByteNTimes(' ', level + 1);
            try w.writeAll("chosen:\n");
            try tree.dumpNode(generic.chosen, level + delta, mapper, config, w);

            if (generic.rest.len > 0) {
                try w.writeByteNTimes(' ', level + 1);
                try w.writeAll("rest:\n");
                for (generic.rest) |expr| {
                    try tree.dumpNode(expr, level + delta, mapper, config, w);
                }
            }
        },
        .generic_association_expr => |assoc| {
            try tree.dumpNode(assoc.expr, level + delta, mapper, config, w);
        },
        .generic_default_expr => |default| {
            try tree.dumpNode(default.expr, level + delta, mapper, config, w);
        },
        .array_filler_expr => |filler| {
            try w.writeByteNTimes(' ', level + 1);
            try w.writeAll("count: ");
            try config.setColor(w, LITERAL);
            try w.print("{d}\n", .{filler.count});
            try config.setColor(w, .reset);
        },
        .struct_forward_decl,
        .union_forward_decl,
        .enum_forward_decl,
        .default_init_expr,
        .cond_dummy_expr,
        => {},
    }
}
