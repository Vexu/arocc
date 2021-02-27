const std = @import("std");
const Type = @import("Type.zig");
const Token = @import("Tokenizer.zig").Token;
const Compilation = @import("Compilation.zig");

const Tree = @This();

pub const TokenIndex = u32;
pub const NodeIndex = u32;

comp: *Compilation,
arena: std.heap.ArenaAllocator,
generated: []const u8,
tokens: []const Token,
nodes: Node.List.Slice,
data: []const NodeIndex,
root_decls: []const NodeIndex,

pub fn deinit(tree: *Tree) void {
    tree.comp.gpa.free(tree.root_decls);
    tree.comp.gpa.free(tree.data);
    tree.nodes.deinit(tree.comp.gpa);
    tree.arena.deinit();
}

/// A generic struct capable of represening all Decl, Stmt and Expr.
pub const Node = struct {
    tag: Tag,
    ty: Type,
    first: NodeIndex = 0,
    second: NodeIndex = 0,

    pub const List = std.MultiArrayList(Node);
};

pub fn tokSlice(tree: Tree, tok_i: TokenIndex) []const u8 {
    const token = tree.tokens[tok_i];
    if (token.id.lexeme()) |some| return some;
    if (token.source.isGenerated()) {
        return tree.generated[token.loc.start..token.loc.end];
    } else {
        const source = tree.comp.getSource(token.source);
        return source.buf[token.loc.start..token.loc.end];
    }
}

pub const Tag = enum(u8) {
    /// Only appears at index 0 and reaching it is always a result of a bug.
    invalid,

    // ====== Decl ======

    // function prototype
    fn_proto,
    static_fn_proto,
    inline_fn_proto,
    inline_static_fn_proto,
    noreturn_fn_proto,
    noreturn_static_fn_proto,
    noreturn_inline_fn_proto,
    noreturn_inline_static_fn_proto,

    // function definition
    fn_def,
    static_fn_def,
    inline_fn_def,
    inline_static_fn_def,
    noreturn_fn_def,
    noreturn_static_fn_def,
    noreturn_inline_fn_def,
    noreturn_inline_static_fn_def,

    // a parameter
    param_decl,
    register_param_decl,

    // variable declaration
    @"var",
    extern_var,
    static_var,
    register_var,
    threadlocal_var,
    threadlocal_extern_var,
    threadlocal_static_var,

    // typedef declaration
    typedef,

    // container type forward declarations
    struct_forward,
    union_forward,
    enum_forawrd,

    // container type definitions
    struct_def,
    union_def,
    enum_def,

    // ====== Stmt ======

    labeled_stmt,
    /// { first; second; } first and second may be null
    compound_stmt_two,
    /// { data }
    compound_stmt,
    if_stmt,
    switch_stmt,
    while_stmt,
    do_while_stmt,
    for_stmt,
    goto_stmt,
    continue_stmt,
    break_stmt,
    return_stmt,

    // ====== Expr ======

    /// lhs , rhs
    comma_expr,
    /// lhs ?: rhs
    binary_cond_expr,
    /// lhs ? data[0] : data[1]
    cond_expr,
    /// lhs = rhs
    assign_expr,
    /// lhs *= rhs
    mul_assign_expr,
    /// lhs /= rhs
    div_assign_expr,
    /// lhs %= rhs
    mod_assign_expr,
    /// lhs += rhs
    add_assign_expr,
    /// lhs -= rhs
    sub_assign_expr,
    /// lhs <<= rhs
    shl_assign_expr,
    /// lhs >>= rhs
    shr_assign_expr,
    /// lhs &= rhs
    and_assign_expr,
    /// lhs ^= rhs
    xor_assign_expr,
    /// lhs |= rhs
    or_assign_expr,
    /// lhs || rhs
    bool_or_expr,
    /// lhs && rhs
    bool_and_expr,
    /// lhs | rhs
    bit_or_expr,
    /// lhs ^ rhs
    bit_xor_expr,
    /// lhs & rhs
    bit_and_expr,
    /// lhs == rhs
    equal_expr,
    /// lhs != rhs
    not_equal_expr,
    /// lhs < rhs
    less_than_expr,
    /// lhs <= rhs
    less_than_equal_expr,
    /// lhs > rhs
    greater_than_expr,
    /// lhs >= rhs
    greater_than_equal_expr,
    /// lhs << rhs
    shl_expr,
    /// lhs >> rhs
    shr_expr,
    /// lhs + rhs
    add_expr,
    /// lhs - rhs
    sub_expr,
    /// lhs * rhs
    mul_expr,
    /// lhs / rhs
    div_expr,
    /// lhs % rhs
    mod_expr,
    /// Explicit (type)lhs
    cast_expr,
    /// &lhs
    addr_of_expr,
    /// *lhs
    deref_expr,
    /// +lhs
    plus_expr,
    /// -lhs
    negate_expr,
    /// ~lhs
    bit_not_expr,
    /// !lhs
    bool_not_expr,
    /// ++lhs
    pre_inc_expr,
    /// --lhs
    pre_dec_expr,
    /// lhs[rhs]  lhs is pointer/array type, rhs is integer type
    array_access_expr,
    /// first(second) second may be 0
    call_expr_one,
    /// data[0](data[1..])
    call_expr,
    /// lhs.rhs rhs is a TokenIndex of the identifier
    member_access_expr,
    /// lhs->rhs rhs is a TokenIndex of the identifier
    member_access_ptr_expr,
    /// lhs++
    post_inc_expr,
    /// lhs--
    post_dec_expr,
    /// lhs is a TokenIndex of the identifier
    decl_ref_expr,
    /// TODO
    integer_literal_expr,
    /// TODO
    float_literal_expr,
    /// TODO
    char_literal_expr,
    /// TODO
    string_literal_expr,
    /// TODO
    compound_literal_expr,

    /// Asserts that the tag is an expression.
    pub fn isLval(tag: Tag) bool {
        return switch (tag) {
            .comma_expr,
            .binary_cond_expr,
            .cond_expr,
            .assign_expr,
            .mul_assign_expr,
            .div_assign_expr,
            .mod_assign_expr,
            .add_assign_expr,
            .sub_assign_expr,
            .shl_assign_expr,
            .shr_assign_expr,
            .and_assign_expr,
            .xor_assign_expr,
            .or_assign_expr,
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
            .cast_expr,
            .addr_of_expr,
            .deref_expr,
            .plus_expr,
            .negate_expr,
            .bit_not_expr,
            .bool_not_expr,
            .pre_inc_expr,
            .pre_dec_expr,
            .array_access_expr,
            .call_expr,
            .call_expr_one,
            => false,
            .decl_ref_expr,
            .string_literal_expr,
            .compound_literal_expr,
            // .member_access_expr, if lhs.isLval()
            .member_access_ptr_expr,
            .deref,
            .array_access_expr,
            => true,
            else => unreachable,
        };
    }

    pub fn Type(comptime tag: Tag) ?type {
        return switch (tag) {
            .invalid => unreachable,

            .fn_proto,
            .extern_fn_proto,
            .static_fn_proto,
            .inline_fn_proto,
            .inline_extern_fn_proto,
            .inline_static_fn_proto,
            => Decl.FnProto,
            .fn_def,
            .extern_fn_def,
            .static_fn_def,
            .inline_fn_def,
            .inline_extern_fn_def,
            .inline_static_fn_def,
            => Decl.FnDef,

            .param_decl, .register_param_decl => Decl.Param,

            .@"var",
            .auto_var,
            .extern_var,
            .static_var,
            .register_var,
            .threadlocal_var,
            .threadlocal_auto_var,
            .threadlocal_extern_var,
            .threadlocal_static_var,
            .threadlocal_register_var,
            => Decl.Var,

            .typdef => Decl.Typedef,

            .struct_forward, .union_forward => Decl.RecordForward,
            .enum_forawrd => Decl.EnumForward,

            .struct_def, .union_def => Decl.Record,
            .enum_def => Decl.Enum,

            .field_decl => Decl.Field,

            .labeled_stmt => Stmt.Labeled,
            .compound_stmt => Stmt.Compound,
            .if_stmt => Stmt.If,
            .switch_stmt => Stmt.Switch,
            .do_while_stmt, .while_stmt => Stmt.While,

            .for_stmt => Stmt.For,
            .goto_stmt => Stmt.Goto,
            .continue_stmt, .break_stmt => null,
            .return_stmt => Stmt.Return,

            .cond_expr => Expr.Conditional,

            .comma_expr,
            .binary_cond_expr,
            .assign_expr,
            .mul_assign_expr,
            .div_assign_expr,
            .mod_assign_expr,
            .add_assign_expr,
            .sub_assign_expr,
            .shl_assign_expr,
            .shr_assign_expr,
            .and_assign_expr,
            .xor_assign_expr,
            .or_assign_expr,
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
            => Expr.BinOp,
            else => @panic("TODO Tag.Type()"),
        };
    }
};

// Represents a declaration expanded from a Node.
pub const Decl = struct {
    pub const FnProto = struct {
        name: []const u8,
        ty: Type,
        is_static: bool,
        is_inline: bool,
        definition: ?*FnDef,
    };

    pub const FnDef = struct {
        name: []const u8,
        ty: Type,
        is_static: bool,
        is_inline: bool,
        body: NodeIndex,
    };

    pub const Param = struct {
        // identifier or first token after declSpec
        name_tok,
        ty: Type,
    };

    pub const Var = struct {
        name: []const u8,
        ty: Type,
        storage_class: enum {
            none,
            static,
            @"extern",
            register,
        },
        is_threadlocal: bool,
        init: ?NodeIndex,
    };

    pub const Typedef = struct {
        name: []const u8,
        ty: Type,
    };

    pub const RecordForward = struct {
        name: []const u8,
        definition: ?*Record,
    };

    pub const Record = struct {
        // identifier or keyword_struct/union if anonymous
        name_tok: TokenIndex,
        fields: []Field,
    };

    pub const Field = struct {
        // identifier or keyword_struct/union if anonymous
        name: TokenIndex,
        ty: Type,
        // TODO bit field stuff
    };

    pub const EnumForward = struct {
        name: []const u8,
        definition: ?*Enum,
    };

    pub const Enum = struct {
        // identifier or keyword_enum if anonymous
        tag_type: Type,
        name_tok: TokenIndex,
    };
};

// Represents a statement expanded from a Node.
pub const Stmt = struct {
    pub const Labeled = struct {
        label: []const u8,
        stmt: NodeIndex,
    };

    pub const Compound = struct {
        stmts: NodeIndex,
    };

    pub const If = struct {
        cond: NodeIndex,
        then: NodeIndex,
        @"else": NodeIndex,
    };

    pub const Switch = struct { cond: NodeIndex, stmt: NodeIndex };

    pub const While = struct {
        cond: NodeIndex,
        stmt: NodeIndex,
    };

    pub const For = struct {
        init: NodeIndex,
        cond: NodeIndex,
        inc: NodeIndex,
        stmt: NodeIndex,
    };

    pub const Goto = struct {
        label: []const u8,
    };

    pub const Return = struct {
        stmt: NodeIndex,
    };
};

// Represents an expression expanded from a Node.
pub const Expr = struct {
    pub const Float = f32;

    pub const Double = f64;

    pub const String = struct {
        tokens: []TokenIndex,
    };

    // pub const Number = struct {
    //     ty: Type,

    // };

    pub const BinOp = struct {
        ty: Type,
        lhs: NodeIndex,
        rhs: NodeIndex,
    };

    pub const UnOp = struct {
        ty: Type,
        operand: NodeIndex,
    };

    pub const Conditional = struct {
        ty: Type,
        cond: NodeIndex,
        then: NodeIndex,
        @"else": NodeIndex,
    };
};

pub fn dump(tree: Tree, writer: anytype) @TypeOf(writer).Error!void {
    for (tree.root_decls) |i| {
        try tree.dumpNode(i, 0, writer);
        try writer.writeByte('\n');
    }
}

fn dumpNode(tree: Tree, node: NodeIndex, level: u32, w: anytype) @TypeOf(w).Error!void {
    const delta = 2;
    const PURPLE = "\x1b[35;1m";
    const CYAN = "\x1b[36;1m";
    const GREEN = "\x1b[32;1m";
    const RESET = "\x1b[0m";

    const tag = tree.nodes.items(.tag)[node];
    try w.writeByteNTimes(' ', level);
    try w.print(CYAN ++ "{s}: " ++ PURPLE ++ "'", .{@tagName(tag)});
    try tree.nodes.items(.ty)[node].dump(tree, w);
    try w.writeAll("'\n" ++ RESET);
    switch (tag) {
        .fn_proto,
        .static_fn_proto,
        .inline_fn_proto,
        .inline_static_fn_proto,
        .noreturn_fn_proto,
        .noreturn_static_fn_proto,
        .noreturn_inline_fn_proto,
        .noreturn_inline_static_fn_proto,
        => {
            try w.writeByteNTimes(' ', level + 1);
            try w.print("name: " ++ GREEN ++ "{s}\n" ++ RESET, .{tree.tokSlice(tree.nodes.items(.first)[node])});
        },
        .fn_def,
        .static_fn_def,
        .inline_fn_def,
        .inline_static_fn_def,
        .noreturn_fn_def,
        .noreturn_static_fn_def,
        .noreturn_inline_fn_def,
        .noreturn_inline_static_fn_def,
        => {
            try w.writeByteNTimes(' ', level + 1);
            try w.print("name: " ++ GREEN ++ "\"{s}\"\n" ++ RESET, .{tree.tokSlice(tree.nodes.items(.first)[node])});
            try w.writeByteNTimes(' ', level + 1);
            try w.writeAll("body:\n");
            try tree.dumpNode(tree.nodes.items(.second)[node], level + delta, w);
        },
        .compound_stmt => {
            const start = tree.nodes.items(.first)[node];
            const end = tree.nodes.items(.second)[node];
            for (tree.data[start..end]) |stmt| try tree.dumpNode(stmt, level + delta, w);
        },
        .compound_stmt_two => {
            const first = tree.nodes.items(.first)[node];
            if (first != 0) try tree.dumpNode(first, level + delta, w);
            const second = tree.nodes.items(.second)[node];
            if (second != 0) try tree.dumpNode(second, level + delta, w);
        },
        .typedef,
        .@"var",
        .extern_var,
        .static_var,
        .register_var,
        .threadlocal_var,
        .threadlocal_extern_var,
        .threadlocal_static_var,
        => {
            try w.writeByteNTimes(' ', level + 1);
            try w.print("name: " ++ GREEN ++ "\"{s}\"\n" ++ RESET, .{tree.tokSlice(tree.nodes.items(.first)[node])});
            const init = tree.nodes.items(.second)[node];
            if (init != 0) {
                try w.writeByteNTimes(' ', level + 1);
                try w.writeAll("init:\n");
                try tree.dumpNode(init, level + delta, w);
            }
        },
        .string_literal_expr => {
            try w.writeByteNTimes(' ', level + 1);
            try w.print("data: " ++ GREEN ++ "{s}\n" ++ RESET, .{tree.tokSlice(tree.nodes.items(.first)[node])});
        },
        .call_expr => {
            const start = tree.nodes.items(.first)[node];
            const end = tree.nodes.items(.second)[node];
            try w.writeByteNTimes(' ', level + 1);
            try w.writeAll("lhs:\n");
            try tree.dumpNode(tree.data[start], level + delta, w);

            try w.writeByteNTimes(' ', level + 1);
            try w.writeAll("args:\n");
            for (tree.data[start + 1 .. end]) |stmt| try tree.dumpNode(stmt, level + delta, w);
        },
        .call_expr_one => {
            try w.writeByteNTimes(' ', level + 1);
            try w.writeAll("lhs:\n");
            try tree.dumpNode(tree.nodes.items(.first)[node], level + delta, w);
            const arg = tree.nodes.items(.second)[node];
            if (arg != 0) {
                try w.writeByteNTimes(' ', level + 1);
                try w.writeAll("arg:\n");
                try tree.dumpNode(arg, level + delta, w);
            }
        },
        else => {},
    }
}
