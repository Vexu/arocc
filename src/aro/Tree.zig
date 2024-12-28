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
    pub const Index = enum(u32) { _ };
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

pub const ValueMap = std.AutoHashMapUnmanaged(Node.Index, Value);

pub const TypeHashContext = struct {
    pub fn hash(_: TypeHashContext, ty: Type) u32 {
        var hasher = std.hash.Wyhash.init(0);

        std.hash.autoHash(&hasher, ty.specifier);
        std.hash.autoHash(&hasher, @as(u5, @bitCast(ty.qual)));
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
type_map: std.ArrayHashMapUnmanaged(Type, void, struct {}, false) = .empty,

/// Arena allocator used for types.
arena: std.heap.ArenaAllocator,

pub const genIr = CodeGen.genIr;

pub fn deinit(tree: *Tree) void {
    tree.nodes.deinit(tree.gpa);
    tree.extra.deinit(tree.gpa);
    tree.root_decls.deinit(tree.gpa);
    tree.value_map.deinit(tree.gpa);
    tree.type_map.deinit(tree.gpa);
    tree.arena.deinit();
    tree.* = undefined;
}

pub const GNUAssemblyQualifiers = struct {
    @"volatile": bool = false,
    @"inline": bool = false,
    goto: bool = false,
};

pub const Node = union(enum) {
    fn_proto: struct {
        name_tok: Token.Index,
        type: Type,
        static: bool,
        @"inline": bool,
        /// The definition for this prototype if one exists.
        definition: ?Node.Index,
    },
    fn_def: struct {
        name_tok: Token.Index,
        type: Type,
        static: bool,
        @"inline": bool,
        body: Node.Index,
    },
    variable: struct {
        name_tok: Token.Index,
        type: Type,
        @"extern": bool,
        static: bool,
        thread_local: bool,
        /// From predefined macro  __func__, __FUNCTION__ or __PRETTY_FUNCTION__.
        /// Implies `static == true`.
        implicit: bool,
        initializer: ?Node.Index,
    },
    typedef: struct {
        name_tok: Token.Index,
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
        name_tok: Token.Index,
        type: Type,
    },
    record_field: struct {
        name_tok: Token.Index,
        type: Type,
        bit_width: ?Node.Index,
    },
    labeled_stmt: struct {
        label_tok: Token.Index,
        stmt: ?Node.Index,
    },
    compound_stmt: struct {
        l_brace_tok: Token.Index,
        body: []const Node.Index,
    },

    if_stmt: struct {
        if_tok: Token.Index,
        cond: Node.Index,
        then_body: Node.Index,
        else_body: ?Node.Index,
    },
    switch_stmt: struct {
        switch_tok: Token.Index,
        cond: Node.Index,
        body: Node.Index,
    },
    case_stmt: struct {
        case_tok: Token.Index,
        items: []const Node.Index,
        body: Node.Index,
    },
    default_stmt: struct {
        case_tok: Token.Index,
        items: []const Node.Index,
    },
    while_stmt: struct {
        while_tok: Token.Index,
        cond: Node.Index,
        body: Node.Index,
    },
    do_while_stmt: struct {
        do_tok: Token.Index,
        cond: Node.Index,
        body: Node.Index,
    },
    for_stmt: struct {
        do_tok: Token.Index,
        /// If decls.len != 0 then init == null.
        decls: []const Node.Index,
        /// If init != null then decls.len == 0.
        init: ?Node.Index,
        cond: ?Node.Index,
        incr: ?Node.Index,
        body: Node.Index,
    },
    goto_stmt: struct {
        label_tok: Token.Index,
    },
    computed_goto_stmt: struct {
        goto_tok: Token.Index,
        expr: Node.Index,
    },
    continue_stmt: struct {
        continue_tok: Token.Index,
    },
    break_stmt: struct {
        break_tok: Token.Index,
    },
    null_stmt: struct {
        semicolon_tok: Token.Index,
    },
    return_stmt: struct {
        return_tok: Token.Index,
        return_type: Type,
        expr: ?Node.Index,
    },
    /// Inserted at the end of a function body if no return stmt is found.
    /// ty is the functions return type
    /// data is return_zero which is true if the function is called "main" and ty is compatible with int
    /// loc is token index of closing r_brace of function
    implicit_return: struct {
        return_tok: Token.Index,
        return_type: Type,
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
        label_tok: Token.Index,
        type: Type,
    },

    array_access_expr: struct {
        l_bracket_tok: Token.Index,
        type: Type,
        index: Node.Index,
        base: Node.Index,
    },
    call_expr: struct {
        l_paren_tok: Token.Index,
        callee: Node.Index,
        args: []const Node.Index,
    },
    builtin_call_expr: struct {
        builtin_tok: Token.Index,
        type: Type,
        args: []const Node.Index,
    },
    member_access_expr: MemberAccess,
    member_access_ptr_expr: MemberAccess,
    decl_ref_expr: DeclRef,
    enumeration_ref: DeclRef,

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
        generic_tok: Token.Index,
        type: Type,
        controlling: Node.Index,
        chosen: Node.Index,
        rest: []const Node.Index,
    },
    generic_association_expr: struct {
        colon_tok: Token.Index,
        association_type: Type,
        expr: Node.Index,
    },
    generic_default_expr: struct {
        default_tok: Token.Index,
        expr: Node.Index,
    },

    binary_cond_expr: Conditional,
    /// Used as the base for casts of the lhs in `binary_cond_expr`.
    cond_dummy_expr: UnaryExpr,
    cond_expr: Conditional,
    builtin_choose_expr: Conditional,
    builtin_types_compatible_p: struct {
        builtin_tok: Token.Index,
        lhs: Type,
        rhs: Type,
    },

    array_init_expr: ContainerInit,
    struct_init_expr: ContainerInit,
    union_init_expr: struct {
        l_brace_tok: Token.Index,
        union_type: Type,
        field_index: u32,
        initializer: Node.Index,
    },
    /// Inserted in array_init_expr to represent unspecified elements.
    /// data.int contains the amount of elements.
    array_filler_expr: struct {
        last_tok: Token.Index,
        type: Type,
        count: u64,
    },
    /// Inserted in record and scalar initializers for unspecified elements.
    default_init_expr: struct {
        last_tok: Token.Index,
        type: Type,
    },

    compound_literal_expr: struct {
        ty: Type,
        l_paren_tok: Token.Index,
        static: bool,
        thread_local: bool,
        initializer: Node.Index,
    },

    pub const SimpleAsm = struct {
        asm_tok: Token.Index,
        asm_str: Node.Index,
    };

    pub const ContainerDecl = struct {
        container_type: Type,
        name_or_kind_tok: Token.Index,
        fields: []const Node.Index,
    };

    pub const ContainerForwardDecl = struct {
        name_or_kind_tok: Token.Index,
        /// The definition for this forward declaration if one exists.
        definition: ?Node.Index,
    };

    pub const BinaryExpr = struct {
        type: Type,
        lhs: Node.Index,
        op_tok: Token.Index,
        rhs: Node.Index,
    };

    pub const Cast = struct {
        type: Type,
        l_paren: Token.Index,
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
        op_tok: Token.Index,
        operand: Node.Index,
    };

    pub const MemberAccess = struct {
        type: Type,
        base: Node.Index,
        access_tok: Token.Index,
        member_index: u32,
    };

    pub const DeclRef = struct {
        type: Type,
        name_tok: Token.Index,
    };

    pub const Conditional = struct {
        cond_tok: Token.Index,
        type: Type,
        condition: Node.Index,
        then_expr: Node.Index,
        else_expr: Node.Index,
    };

    pub const ContainerInit = struct {
        l_brace_tok: Token.Index,
        union_type: Type,
        items: []const Node.Index,
    };

    pub const Literal = struct {
        literal_tok: Token.Index,
    };

    pub const TypeInfo = struct {
        type: Type,
        operator_tok: Token.Index,
        expr: ?Node.Index,
    };

    pub const Index = enum(u32) {
        _,

        pub fn get(index: Index, tree: *const Tree) Node {
            const repr = tree.nodes.get(@intFromEnum(index));
            return switch (repr.tag) {
                // TODO unpack
            };
        }

        pub fn tok(index: Index, tree: *const Tree) Token.Index {
            return tree.nodes.items(.tok)[@intFromEnum(index)];
        }

        pub fn loc(index: Index, tree: *const Tree) ?Source.Location {
            const tok_i = index.tok(tree);
            return tree.tokens.items(.loc)[@intFromEnum(tok_i)];
        }

        pub fn @"type"(index: Index, tree: *const Tree) Type {
            if (std.debug.runtime_safety) {
                std.debug.assert(tree.nodes.items(.tag)[@intFromEnum(index)].istTyped());
            }
            // If a node is typed the type is stored in data[0];
            const type_index = tree.nodes.items(.data)[@intFromEnum(index)][0];
            return tree.type_map.values()[type_index];
        }
    };

    pub const Repr = struct {
        tag: Tag,
        data: [3]u32,
        tok: Token.Index,

        pub const Tag = enum(u8) {
            pub fn isTyped(tag: Tag) bool {
                return switch (tag) {
                    // TODO stmts etc..
                    // => false,
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

pub fn isBitfield(tree: *const Tree, node: Node.Index) bool {
    return tree.bitfieldWidth(node, false) != null;
}

/// Returns null if node is not a bitfield. If inspect_lval is true, this function will
/// recurse into implicit lval_to_rval casts (useful for arithmetic conversions)
pub fn bitfieldWidth(tree: *const Tree, node: Node.Index, inspect_lval: bool) ?u32 {
    if (node == .none) return null;
    switch (node.get(tree)) {
        .member_access_expr, .member_access_ptr_expr => |access| {
            var ty = access.base.type();
            if (ty.isPtr()) ty = ty.elemType();
            const record_ty = ty.get(.@"struct") orelse ty.get(.@"union") orelse return null;
            const field = record_ty.data.record.fields[access.member_index];
            return field.bit_width;
        },
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
    tok: Token.Index,
    /// true if `nodiscard` attribute present
    nodiscard: bool,
    /// true if `warn_unused_result` attribute present
    warn_unused_result: bool,
};

pub fn callableResultUsage(tree: *const Tree, node: Node.Index) ?CallableResultUsage {
    const data = tree.nodes.items(.data);

    var cur_node = node;
    while (true) switch (cur_node.get(tree)) {
        .decl_ref_expr => |decl_ref| {
            const fn_ty = decl_ref.type.elemType();
            return .{
                .tok = decl_ref.name_tok,
                .nodiscard = fn_ty.hasAttribute(.nodiscard),
                .warn_unused_result = fn_ty.hasAttribute(.warn_unused_result),
            };
        },

        .paren_expr, .addr_of_expr, .deref_expr => |un| cur_node = un.operand,
        .comma_expr => |bin| cur_node = bin.rhs,
        .explicit_cast, .implicit_cast => |cast| cur_node = cast.operand,
        .call_expr => |call| cur_node = call.callee,
        .member_access_expr, .member_access_ptr_expr => |access| {
            const member = data[@intFromEnum(cur_node)].member;
            var ty = access.base.type(tree);
            if (ty.isPtr()) ty = ty.elemType();
            const record = ty.getRecord().?;
            const field = record.fields[member.index];
            const attributes = if (record.field_attributes) |attrs| attrs[member.index] else &.{};
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
        .decl_ref_expr => {
            const decl_ty = tree.nodes.items(.ty)[@intFromEnum(node)];
            is_const.* = decl_ty.isConst();
            return true;
        },
        .deref_expr => {
            const data = tree.nodes.items(.data)[@intFromEnum(node)];
            const operand_ty = tree.nodes.items(.ty)[@intFromEnum(data.un)];
            if (operand_ty.isFunc()) return false;
            if (operand_ty.isPtr() or operand_ty.isArray()) is_const.* = operand_ty.elemType().isConst();
            return true;
        },
        .member_access_expr => {
            const data = tree.nodes.items(.data)[@intFromEnum(node)];
            return tree.isLvalExtra(data.member.lhs, is_const);
        },
        .paren_expr => {
            const data = tree.nodes.items(.data)[@intFromEnum(node)];
            return tree.isLvalExtra(data.un, is_const);
        },
        .builtin_choose_expr => {
            const data = tree.nodes.items(.data)[@intFromEnum(node)];

            if (tree.value_map.get(data.if3.cond)) |val| {
                const offset = @intFromBool(val.isZero(tree.comp));
                return tree.isLvalExtra(tree.data[data.if3.body + offset], is_const);
            }
            return false;
        },
        else => return false,
    }
}

pub fn tokSlice(tree: *const Tree, tok_i: Token.Index) []const u8 {
    if (tree.tokens.items(.id)[tok_i].lexeme()) |some| return some;
    const loc = tree.tokens.items(.loc)[tok_i];
    return tree.comp.locSlice(loc);
}

pub fn dump(tree: *const Tree, config: std.io.tty.Config, writer: anytype) !void {
    const mapper = tree.comp.string_interner.getFastTypeMapper(tree.comp.gpa) catch tree.comp.string_interner.getSlowTypeMapper();
    defer mapper.deinit(tree.comp.gpa);

    for (tree.root_decls) |i| {
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
    node: Node.Index,
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
    std.debug.assert(node != .none);

    const tag = tree.nodes.items(.tag)[@intFromEnum(node)];
    const data = tree.nodes.items(.data)[@intFromEnum(node)];
    const ty = tree.nodes.items(.ty)[@intFromEnum(node)];
    try w.writeByteNTimes(' ', level);

    try config.setColor(w, if (tag.isImplicit()) IMPLICIT else TAG);
    try w.print("{s}: ", .{@tagName(tag)});
    if (tag == .implicit_cast or tag == .explicit_cast) {
        try config.setColor(w, .white);
        try w.print("({s}) ", .{@tagName(data.cast.kind)});
    }
    try config.setColor(w, TYPE);
    try w.writeByte('\'');
    const name = ty.getName();
    if (name != .empty) {
        try w.print("{s}': '", .{mapper.lookup(name)});
    }
    try ty.dump(mapper, tree.comp.langopts, w);
    try w.writeByte('\'');

    if (tree.isLval(node)) {
        try config.setColor(w, ATTRIBUTE);
        try w.writeAll(" lvalue");
    }
    if (tree.isBitfield(node)) {
        try config.setColor(w, ATTRIBUTE);
        try w.writeAll(" bitfield");
    }
    if (tree.value_map.get(node)) |val| {
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
                        const decl = tree.nodes.items(.data)[ptr.node].decl;
                        const decl_name = tree.tokSlice(decl.name);
                        try ptr.offset.printPointer(decl_name, tree.comp, w);
                    },
                }
            },
        };
        try w.writeByte(')');
    }
    if (tag == .implicit_return and data.return_zero) {
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

    switch (tag) {
        .invalid => unreachable,
        .file_scope_asm => {
            try w.writeByteNTimes(' ', level + 1);
            try tree.dumpNode(data.decl.node, level + delta, mapper, config, w);
        },
        .gnu_asm_simple => {
            try w.writeByteNTimes(' ', level);
            try tree.dumpNode(data.un, level, mapper, config, w);
        },
        .static_assert => {
            try w.writeByteNTimes(' ', level + 1);
            try w.writeAll("condition:\n");
            try tree.dumpNode(data.bin.lhs, level + delta, mapper, config, w);
            if (data.bin.rhs != .none) {
                try w.writeByteNTimes(' ', level + 1);
                try w.writeAll("diagnostic:\n");
                try tree.dumpNode(data.bin.rhs, level + delta, mapper, config, w);
            }
        },
        .fn_proto,
        .static_fn_proto,
        .inline_fn_proto,
        .inline_static_fn_proto,
        => {
            try w.writeByteNTimes(' ', level + half);
            try w.writeAll("name: ");
            try config.setColor(w, NAME);
            try w.print("{s}\n", .{tree.tokSlice(data.decl.name)});
            try config.setColor(w, .reset);
        },
        .fn_def,
        .static_fn_def,
        .inline_fn_def,
        .inline_static_fn_def,
        => {
            try w.writeByteNTimes(' ', level + half);
            try w.writeAll("name: ");
            try config.setColor(w, NAME);
            try w.print("{s}\n", .{tree.tokSlice(data.decl.name)});
            try config.setColor(w, .reset);
            try w.writeByteNTimes(' ', level + half);
            try w.writeAll("body:\n");
            try tree.dumpNode(data.decl.node, level + delta, mapper, config, w);
        },
        .typedef,
        .@"var",
        .extern_var,
        .static_var,
        .implicit_static_var,
        .threadlocal_var,
        .threadlocal_extern_var,
        .threadlocal_static_var,
        => {
            try w.writeByteNTimes(' ', level + half);
            try w.writeAll("name: ");
            try config.setColor(w, NAME);
            try w.print("{s}\n", .{tree.tokSlice(data.decl.name)});
            try config.setColor(w, .reset);
            if (data.decl.node != .none) {
                try w.writeByteNTimes(' ', level + half);
                try w.writeAll("init:\n");
                try tree.dumpNode(data.decl.node, level + delta, mapper, config, w);
            }
        },
        .enum_field_decl => {
            try w.writeByteNTimes(' ', level + half);
            try w.writeAll("name: ");
            try config.setColor(w, NAME);
            try w.print("{s}\n", .{tree.tokSlice(data.decl.name)});
            try config.setColor(w, .reset);
            if (data.decl.node != .none) {
                try w.writeByteNTimes(' ', level + half);
                try w.writeAll("value:\n");
                try tree.dumpNode(data.decl.node, level + delta, mapper, config, w);
            }
        },
        .record_field_decl => {
            if (data.decl.name != 0) {
                try w.writeByteNTimes(' ', level + half);
                try w.writeAll("name: ");
                try config.setColor(w, NAME);
                try w.print("{s}\n", .{tree.tokSlice(data.decl.name)});
                try config.setColor(w, .reset);
            }
            if (data.decl.node != .none) {
                try w.writeByteNTimes(' ', level + half);
                try w.writeAll("bits:\n");
                try tree.dumpNode(data.decl.node, level + delta, mapper, config, w);
            }
        },
        .indirect_record_field_decl => {},
        .compound_stmt,
        .array_init_expr,
        .struct_init_expr,
        .enum_decl,
        .struct_decl,
        .union_decl,
        .compound_stmt_two,
        .array_init_expr_two,
        .struct_init_expr_two,
        .enum_decl_two,
        .struct_decl_two,
        .union_decl_two,
        => {
            const child_nodes = tree.childNodes(node);
            const maybe_field_attributes = if (ty.getRecord()) |record| record.field_attributes else null;
            for (child_nodes, 0..) |stmt, i| {
                if (i != 0) try w.writeByte('\n');
                try tree.dumpNode(stmt, level + delta, mapper, config, w);
                if (maybe_field_attributes) |field_attributes| {
                    if (field_attributes[i].len == 0) continue;

                    try config.setColor(w, ATTRIBUTE);
                    try tree.dumpFieldAttributes(field_attributes[i], level + delta + half, w);
                    try config.setColor(w, .reset);
                }
            }
        },
        .union_init_expr => {
            try w.writeByteNTimes(' ', level + half);
            try w.writeAll("field index: ");
            try config.setColor(w, LITERAL);
            try w.print("{d}\n", .{data.union_init.field_index});
            try config.setColor(w, .reset);
            if (data.union_init.node != .none) {
                try tree.dumpNode(data.union_init.node, level + delta, mapper, config, w);
            }
        },
        .compound_literal_expr,
        .static_compound_literal_expr,
        .thread_local_compound_literal_expr,
        .static_thread_local_compound_literal_expr,
        => {
            try tree.dumpNode(data.un, level + half, mapper, config, w);
        },
        .labeled_stmt => {
            try w.writeByteNTimes(' ', level + half);
            try w.writeAll("label: ");
            try config.setColor(w, LITERAL);
            try w.print("{s}\n", .{tree.tokSlice(data.decl.name)});
            try config.setColor(w, .reset);
            if (data.decl.node != .none) {
                try w.writeByteNTimes(' ', level + half);
                try w.writeAll("stmt:\n");
                try tree.dumpNode(data.decl.node, level + delta, mapper, config, w);
            }
        },
        .case_stmt => {
            try w.writeByteNTimes(' ', level + half);
            try w.writeAll("value:\n");
            try tree.dumpNode(data.bin.lhs, level + delta, mapper, config, w);
            if (data.bin.rhs != .none) {
                try w.writeByteNTimes(' ', level + half);
                try w.writeAll("stmt:\n");
                try tree.dumpNode(data.bin.rhs, level + delta, mapper, config, w);
            }
        },
        .case_range_stmt => {
            try w.writeByteNTimes(' ', level + half);
            try w.writeAll("range start:\n");
            try tree.dumpNode(tree.data[data.if3.body], level + delta, mapper, config, w);

            try w.writeByteNTimes(' ', level + half);
            try w.writeAll("range end:\n");
            try tree.dumpNode(tree.data[data.if3.body + 1], level + delta, mapper, config, w);

            if (data.if3.cond != .none) {
                try w.writeByteNTimes(' ', level + half);
                try w.writeAll("stmt:\n");
                try tree.dumpNode(data.if3.cond, level + delta, mapper, config, w);
            }
        },
        .default_stmt => {
            if (data.un != .none) {
                try w.writeByteNTimes(' ', level + half);
                try w.writeAll("stmt:\n");
                try tree.dumpNode(data.un, level + delta, mapper, config, w);
            }
        },
        .binary_cond_expr, .cond_expr, .if_then_else_stmt, .builtin_choose_expr => {
            try w.writeByteNTimes(' ', level + half);
            try w.writeAll("cond:\n");
            try tree.dumpNode(data.if3.cond, level + delta, mapper, config, w);

            try w.writeByteNTimes(' ', level + half);
            try w.writeAll("then:\n");
            try tree.dumpNode(tree.data[data.if3.body], level + delta, mapper, config, w);

            try w.writeByteNTimes(' ', level + half);
            try w.writeAll("else:\n");
            try tree.dumpNode(tree.data[data.if3.body + 1], level + delta, mapper, config, w);
        },
        .builtin_types_compatible_p => {
            std.debug.assert(tree.nodes.items(.tag)[@intFromEnum(data.bin.lhs)] == .invalid);
            std.debug.assert(tree.nodes.items(.tag)[@intFromEnum(data.bin.rhs)] == .invalid);

            try w.writeByteNTimes(' ', level + half);
            try w.writeAll("lhs: ");

            const lhs_ty = tree.nodes.items(.ty)[@intFromEnum(data.bin.lhs)];
            try config.setColor(w, TYPE);
            try lhs_ty.dump(mapper, tree.comp.langopts, w);
            try config.setColor(w, .reset);
            try w.writeByte('\n');

            try w.writeByteNTimes(' ', level + half);
            try w.writeAll("rhs: ");

            const rhs_ty = tree.nodes.items(.ty)[@intFromEnum(data.bin.rhs)];
            try config.setColor(w, TYPE);
            try rhs_ty.dump(mapper, tree.comp.langopts, w);
            try config.setColor(w, .reset);
            try w.writeByte('\n');
        },
        .if_then_stmt => {
            try w.writeByteNTimes(' ', level + half);
            try w.writeAll("cond:\n");
            try tree.dumpNode(data.bin.lhs, level + delta, mapper, config, w);

            if (data.bin.rhs != .none) {
                try w.writeByteNTimes(' ', level + half);
                try w.writeAll("then:\n");
                try tree.dumpNode(data.bin.rhs, level + delta, mapper, config, w);
            }
        },
        .switch_stmt, .while_stmt, .do_while_stmt => {
            try w.writeByteNTimes(' ', level + half);
            try w.writeAll("cond:\n");
            try tree.dumpNode(data.bin.lhs, level + delta, mapper, config, w);

            if (data.bin.rhs != .none) {
                try w.writeByteNTimes(' ', level + half);
                try w.writeAll("body:\n");
                try tree.dumpNode(data.bin.rhs, level + delta, mapper, config, w);
            }
        },
        .for_decl_stmt => {
            const for_decl = data.forDecl(tree.data);

            try w.writeByteNTimes(' ', level + half);
            try w.writeAll("decl:\n");
            for (for_decl.decls) |decl| {
                try tree.dumpNode(decl, level + delta, mapper, config, w);
                try w.writeByte('\n');
            }
            if (for_decl.cond != .none) {
                try w.writeByteNTimes(' ', level + half);
                try w.writeAll("cond:\n");
                try tree.dumpNode(for_decl.cond, level + delta, mapper, config, w);
            }
            if (for_decl.incr != .none) {
                try w.writeByteNTimes(' ', level + half);
                try w.writeAll("incr:\n");
                try tree.dumpNode(for_decl.incr, level + delta, mapper, config, w);
            }
            if (for_decl.body != .none) {
                try w.writeByteNTimes(' ', level + half);
                try w.writeAll("body:\n");
                try tree.dumpNode(for_decl.body, level + delta, mapper, config, w);
            }
        },
        .forever_stmt => {
            if (data.un != .none) {
                try w.writeByteNTimes(' ', level + half);
                try w.writeAll("body:\n");
                try tree.dumpNode(data.un, level + delta, mapper, config, w);
            }
        },
        .for_stmt => {
            const for_stmt = data.forStmt(tree.data);

            if (for_stmt.init != .none) {
                try w.writeByteNTimes(' ', level + half);
                try w.writeAll("init:\n");
                try tree.dumpNode(for_stmt.init, level + delta, mapper, config, w);
            }
            if (for_stmt.cond != .none) {
                try w.writeByteNTimes(' ', level + half);
                try w.writeAll("cond:\n");
                try tree.dumpNode(for_stmt.cond, level + delta, mapper, config, w);
            }
            if (for_stmt.incr != .none) {
                try w.writeByteNTimes(' ', level + half);
                try w.writeAll("incr:\n");
                try tree.dumpNode(for_stmt.incr, level + delta, mapper, config, w);
            }
            if (for_stmt.body != .none) {
                try w.writeByteNTimes(' ', level + half);
                try w.writeAll("body:\n");
                try tree.dumpNode(for_stmt.body, level + delta, mapper, config, w);
            }
        },
        .goto_stmt, .addr_of_label => {
            try w.writeByteNTimes(' ', level + half);
            try w.writeAll("label: ");
            try config.setColor(w, LITERAL);
            try w.print("{s}\n", .{tree.tokSlice(data.decl_ref)});
            try config.setColor(w, .reset);
        },
        .continue_stmt, .break_stmt, .implicit_return, .null_stmt => {},
        .return_stmt => {
            if (data.un != .none) {
                try w.writeByteNTimes(' ', level + half);
                try w.writeAll("expr:\n");
                try tree.dumpNode(data.un, level + delta, mapper, config, w);
            }
        },
        .call_expr, .call_expr_one => {
            const child_nodes = tree.childNodes(node);
            const fn_ptr = child_nodes[0];
            const args = child_nodes[1..];

            try w.writeByteNTimes(' ', level + half);
            try w.writeAll("lhs:\n");
            try tree.dumpNode(fn_ptr, level + delta, mapper, config, w);

            if (args.len > 0) {
                try w.writeByteNTimes(' ', level + half);
                try w.writeAll("args:\n");
                for (args) |arg| {
                    try tree.dumpNode(arg, level + delta, mapper, config, w);
                }
            }
        },
        .builtin_call_expr => {
            try w.writeByteNTimes(' ', level + half);
            try w.writeAll("name: ");
            try config.setColor(w, NAME);
            try w.print("{s}\n", .{tree.tokSlice(@intFromEnum(tree.data[data.range.start]))});
            try config.setColor(w, .reset);

            try w.writeByteNTimes(' ', level + half);
            try w.writeAll("args:\n");
            const child_nodes = tree.childNodes(node);
            for (child_nodes) |arg| {
                try tree.dumpNode(arg, level + delta, mapper, config, w);
            }
        },
        .builtin_call_expr_one => {
            try w.writeByteNTimes(' ', level + half);
            try w.writeAll("name: ");
            try config.setColor(w, NAME);
            try w.print("{s}\n", .{tree.tokSlice(data.decl.name)});
            try config.setColor(w, .reset);
            const child_nodes = tree.childNodes(node);
            for (child_nodes) |arg| {
                try w.writeByteNTimes(' ', level + half);
                try w.writeAll("arg:\n");
                try tree.dumpNode(arg, level + delta, mapper, config, w);
            }
        },
        .special_builtin_call_one => {
            try w.writeByteNTimes(' ', level + half);
            try w.writeAll("name: ");
            try config.setColor(w, NAME);
            try w.print("{s}\n", .{tree.tokSlice(data.decl.name)});
            try config.setColor(w, .reset);
            if (data.decl.node != .none) {
                try w.writeByteNTimes(' ', level + half);
                try w.writeAll("arg:\n");
                try tree.dumpNode(data.decl.node, level + delta, mapper, config, w);
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
        => {
            try w.writeByteNTimes(' ', level + 1);
            try w.writeAll("lhs:\n");
            try tree.dumpNode(data.bin.lhs, level + delta, mapper, config, w);
            try w.writeByteNTimes(' ', level + 1);
            try w.writeAll("rhs:\n");
            try tree.dumpNode(data.bin.rhs, level + delta, mapper, config, w);
        },
        .explicit_cast, .implicit_cast => try tree.dumpNode(data.cast.operand, level + delta, mapper, config, w),
        .addr_of_expr,
        .computed_goto_stmt,
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
        => {
            try w.writeByteNTimes(' ', level + 1);
            try w.writeAll("operand:\n");
            try tree.dumpNode(data.un, level + delta, mapper, config, w);
        },
        .decl_ref_expr => {
            try w.writeByteNTimes(' ', level + 1);
            try w.writeAll("name: ");
            try config.setColor(w, NAME);
            try w.print("{s}\n", .{tree.tokSlice(data.decl_ref)});
            try config.setColor(w, .reset);
        },
        .enumeration_ref => {
            try w.writeByteNTimes(' ', level + 1);
            try w.writeAll("name: ");
            try config.setColor(w, NAME);
            try w.print("{s}\n", .{tree.tokSlice(data.decl_ref)});
            try config.setColor(w, .reset);
        },
        .bool_literal,
        .nullptr_literal,
        .int_literal,
        .char_literal,
        .float_literal,
        .string_literal_expr,
        => {},
        .member_access_expr, .member_access_ptr_expr => {
            try w.writeByteNTimes(' ', level + 1);
            try w.writeAll("lhs:\n");
            try tree.dumpNode(data.member.lhs, level + delta, mapper, config, w);

            var lhs_ty = tree.nodes.items(.ty)[@intFromEnum(data.member.lhs)];
            if (lhs_ty.isPtr()) lhs_ty = lhs_ty.elemType();
            lhs_ty = lhs_ty.canonicalize(.standard);

            try w.writeByteNTimes(' ', level + 1);
            try w.writeAll("name: ");
            try config.setColor(w, NAME);
            try w.print("{s}\n", .{mapper.lookup(lhs_ty.data.record.fields[data.member.index].name)});
            try config.setColor(w, .reset);
        },
        .array_access_expr => {
            if (data.bin.lhs != .none) {
                try w.writeByteNTimes(' ', level + 1);
                try w.writeAll("lhs:\n");
                try tree.dumpNode(data.bin.lhs, level + delta, mapper, config, w);
            }
            try w.writeByteNTimes(' ', level + 1);
            try w.writeAll("index:\n");
            try tree.dumpNode(data.bin.rhs, level + delta, mapper, config, w);
        },
        .sizeof_expr, .alignof_expr => {
            if (data.un != .none) {
                try w.writeByteNTimes(' ', level + 1);
                try w.writeAll("expr:\n");
                try tree.dumpNode(data.un, level + delta, mapper, config, w);
            }
        },
        .generic_expr, .generic_expr_one => {
            const child_nodes = tree.childNodes(node);
            const controlling = child_nodes[0];
            const chosen = child_nodes[1];
            const rest = child_nodes[2..];

            try w.writeByteNTimes(' ', level + 1);
            try w.writeAll("controlling:\n");
            try tree.dumpNode(controlling, level + delta, mapper, config, w);
            try w.writeByteNTimes(' ', level + 1);
            try w.writeAll("chosen:\n");
            try tree.dumpNode(chosen, level + delta, mapper, config, w);

            if (rest.len > 0) {
                try w.writeByteNTimes(' ', level + 1);
                try w.writeAll("rest:\n");
                for (rest) |expr| {
                    try tree.dumpNode(expr, level + delta, mapper, config, w);
                }
            }
        },
        .generic_association_expr, .generic_default_expr, .stmt_expr, .imaginary_literal => {
            try tree.dumpNode(data.un, level + delta, mapper, config, w);
        },
        .array_filler_expr => {
            try w.writeByteNTimes(' ', level + 1);
            try w.writeAll("count: ");
            try config.setColor(w, LITERAL);
            try w.print("{d}\n", .{data.int});
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
