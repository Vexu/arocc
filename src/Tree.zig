const std = @import("std");
const Type = @import("Type.zig");
const Tokenizer = @import("Tokenizer.zig");
const Compilation = @import("Compilation.zig");
const Source = @import("Source.zig");

const Tree = @This();

pub const Token = struct {
    id: Id,
    /// This location contains the actual token slice which might be generated.
    /// If it is generated then the next location will be the location of the concatenation.
    /// Any subsequent locations mark where the token was expanded from. 
    loc: Source.Location,

    pub const List = std.MultiArrayList(Token);
    pub const Id = Tokenizer.Token.Id;
};

pub const TokenIndex = u32;
pub const NodeIndex = u32;

comp: *Compilation,
arena: std.heap.ArenaAllocator,
generated: []const u8,
tokens: Token.List.Slice,
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
    ty: Type = .{ .specifier = .void },
    first: NodeIndex = 0,
    second: NodeIndex = 0,

    pub const List = std.MultiArrayList(Node);
};

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
    /// if (first) data[second] else data[second+1];
    if_then_else_stmt,
    /// if (first); else second;
    if_else_stmt,
    /// if (first) second; second may be null
    if_then_stmt,
    /// switch (first) second
    switch_stmt,
    /// case first: second
    case_stmt,
    /// default: first
    default_stmt,
    /// while (first) second
    while_stmt,
    /// do second while(first);
    do_while_stmt,
    /// for (data[..]; data[len-3]; data[len-2]) data[len-1]
    for_decl_stmt,
    /// for (;;;) first
    forever_stmt,
    /// for (data[first]; data[first+1]; data[first+2]) second
    for_stmt,
    /// goto first;
    goto_stmt,
    // continue; first and second unused
    continue_stmt,
    // break; first and second unused
    break_stmt,
    /// return first; first may be null
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
    /// integer literal with 32 or fewer bits, stored in first, check node.ty for signedness and bit count
    int_32_literal,
    /// integer literal with 64 bits, split in first and second, check node.ty for signedness
    int_64_literal,
    /// f32 literal stored in first
    float_literal,
    /// f64 literal split in first and second
    double_literal,
    /// data[first][0..second]
    string_literal_expr,
    /// TODO
    compound_literal_expr,

    // ====== Implicit casts ======

    /// convert T[] to T *
    array_to_pointer,
    /// same as deref
    lval_to_rval,

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

pub fn tokSlice(tree: Tree, tok_i: TokenIndex) []const u8 {
    if (tree.tokens.items(.id)[tok_i].lexeme()) |some| return some;
    const loc = tree.tokens.items(.loc)[tok_i];
    var tmp_tokenizer = Tokenizer{
        .buf = if (loc.id == .generated)
            tree.generated
        else
            tree.comp.getSource(loc.id).buf,
        .index = loc.byte_offset,
        .source = .generated,
    };
    const tok = tmp_tokenizer.next();
    return tmp_tokenizer.buf[tok.start..tok.end];
}

pub fn dump(tree: Tree, writer: anytype) @TypeOf(writer).Error!void {
    for (tree.root_decls) |i| {
        try tree.dumpNode(i, 0, writer);
        try writer.writeByte('\n');
    }
}

fn dumpNode(tree: Tree, node: NodeIndex, level: u32, w: anytype) @TypeOf(w).Error!void {
    const delta = 2;
    const half = delta / 2;
    const TYPE = "\x1b[35;1m";
    const TAG = "\x1b[36;1m";
    const NAME = "\x1b[91;1m";
    const LITERAL = "\x1b[32;1m";
    const RESET = "\x1b[0m";

    const tag = tree.nodes.items(.tag)[node];
    try w.writeByteNTimes(' ', level);
    try w.print(TAG ++ "{s}: " ++ TYPE ++ "'", .{@tagName(tag)});
    try tree.nodes.items(.ty)[node].dump(tree, w);
    try w.writeAll("'\n" ++ RESET);
    switch (tag) {
        .invalid => unreachable,
        .fn_proto,
        .static_fn_proto,
        .inline_fn_proto,
        .inline_static_fn_proto,
        .noreturn_fn_proto,
        .noreturn_static_fn_proto,
        .noreturn_inline_fn_proto,
        .noreturn_inline_static_fn_proto,
        => {
            try w.writeByteNTimes(' ', level + half);
            try w.print("name: " ++ NAME ++ "{s}\n" ++ RESET, .{tree.tokSlice(tree.nodes.items(.first)[node])});
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
            try w.writeByteNTimes(' ', level + half);
            try w.print("name: " ++ NAME ++ "{s}\n" ++ RESET, .{tree.tokSlice(tree.nodes.items(.first)[node])});
            try w.writeByteNTimes(' ', level + half);
            try w.writeAll("body:\n");
            try tree.dumpNode(tree.nodes.items(.second)[node], level + delta, w);
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
            try w.writeByteNTimes(' ', level + half);
            try w.print("name: " ++ NAME ++ "{s}\n" ++ RESET, .{tree.tokSlice(tree.nodes.items(.first)[node])});
            const init = tree.nodes.items(.second)[node];
            if (init != 0) {
                try w.writeByteNTimes(' ', level + half);
                try w.writeAll("init:\n");
                try tree.dumpNode(init, level + delta, w);
            }
        },
        .compound_stmt => {
            const start = tree.nodes.items(.first)[node];
            const end = tree.nodes.items(.second)[node];
            for (tree.data[start..end]) |stmt, i| {
                if (i != 0) try w.writeByte('\n');
                try tree.dumpNode(stmt, level + delta, w);
            }
        },
        .compound_stmt_two => {
            const first = tree.nodes.items(.first)[node];
            if (first != 0) try tree.dumpNode(first, level + delta, w);
            const second = tree.nodes.items(.second)[node];
            if (second != 0) try tree.dumpNode(second, level + delta, w);
        },
        .labeled_stmt => {
            try w.writeByteNTimes(' ', level + half);
            try w.print("label: " ++ LITERAL ++ "{s}\n" ++ RESET, .{tree.tokSlice(tree.nodes.items(.first)[node])});
            const stmt = tree.nodes.items(.second)[node];
            if (stmt != 0) {
                try w.writeByteNTimes(' ', level + half);
                try w.writeAll("stmt:\n");
                try tree.dumpNode(stmt, level + delta, w);
            }
        },
        .case_stmt => {
            try w.writeByteNTimes(' ', level + half);
            try w.writeAll("value:\n");
            try tree.dumpNode(tree.nodes.items(.first)[node], level + delta, w);
            const stmt = tree.nodes.items(.second)[node];
            if (stmt != 0) {
                try w.writeByteNTimes(' ', level + half);
                try w.writeAll("stmt:\n");
                try tree.dumpNode(stmt, level + delta, w);
            }
        },
        .default_stmt => {
            const stmt = tree.nodes.items(.first)[node];
            if (stmt != 0) {
                try w.writeByteNTimes(' ', level + half);
                try w.writeAll("stmt:\n");
                try tree.dumpNode(stmt, level + delta, w);
            }
        },
        .if_then_else_stmt => {
            try w.writeByteNTimes(' ', level + half);
            try w.writeAll("cond:\n");
            try tree.dumpNode(tree.nodes.items(.first)[node], level + delta, w);

            const second = tree.nodes.items(.second)[node];
            try w.writeByteNTimes(' ', level + half);
            try w.writeAll("then:\n");
            try tree.dumpNode(tree.data[second], level + delta, w);

            try w.writeByteNTimes(' ', level + half);
            try w.writeAll("else:\n");
            try tree.dumpNode(tree.data[second + 1], level + delta, w);
        },
        .if_else_stmt => {
            try w.writeByteNTimes(' ', level + half);
            try w.writeAll("cond:\n");
            try tree.dumpNode(tree.nodes.items(.first)[node], level + delta, w);

            try w.writeByteNTimes(' ', level + half);
            try w.writeAll("else:\n");
            try tree.dumpNode(tree.nodes.items(.second)[node], level + delta, w);
        },
        .if_then_stmt => {
            try w.writeByteNTimes(' ', level + half);
            try w.writeAll("cond:\n");
            try tree.dumpNode(tree.nodes.items(.first)[node], level + delta, w);

            const then = tree.nodes.items(.second)[node];
            if (then != 0) {
                try w.writeByteNTimes(' ', level + half);
                try w.writeAll("then:\n");
                try tree.dumpNode(then, level + delta, w);
            }
        },
        .switch_stmt, .while_stmt, .do_while_stmt => {
            try w.writeByteNTimes(' ', level + half);
            try w.writeAll("cond:\n");
            try tree.dumpNode(tree.nodes.items(.first)[node], level + delta, w);

            const body = tree.nodes.items(.second)[node];
            if (body != 0) {
                try w.writeByteNTimes(' ', level + half);
                try w.writeAll("body:\n");
                try tree.dumpNode(body, level + delta, w);
            }
        },
        .for_decl_stmt => {
            const start = tree.nodes.items(.first)[node];
            const end = tree.nodes.items(.second)[node];
            const items = tree.data[start..end];
            const decls = items[0 .. items.len - 3];

            try w.writeByteNTimes(' ', level + half);
            try w.writeAll("decl:\n");
            for (decls) |decl| {
                try tree.dumpNode(decl, level + delta, w);
                try w.writeByte('\n');
            }
            const cond = items[items.len - 3];
            if (cond != 0) {
                try w.writeByteNTimes(' ', level + half);
                try w.writeAll("cond:\n");
                try tree.dumpNode(cond, level + delta, w);
            }
            const incr = items[items.len - 2];
            if (incr != 0) {
                try w.writeByteNTimes(' ', level + half);
                try w.writeAll("incr:\n");
                try tree.dumpNode(incr, level + delta, w);
            }
            const body = items[items.len - 1];
            if (body != 0) {
                try w.writeByteNTimes(' ', level + half);
                try w.writeAll("body:\n");
                try tree.dumpNode(body, level + delta, w);
            }
        },
        .forever_stmt => {
            const body = tree.nodes.items(.first)[node];
            if (body != 0) {
                try w.writeByteNTimes(' ', level + half);
                try w.writeAll("body:\n");
                try tree.dumpNode(body, level + delta, w);
            }
        },
        .for_stmt => {
            const start = tree.data[tree.nodes.items(.first)[node]..];
            const init = start[0];
            if (init != 0) {
                try w.writeByteNTimes(' ', level + half);
                try w.writeAll("init:\n");
                try tree.dumpNode(init, level + delta, w);
            }
            const cond = start[1];
            if (cond != 0) {
                try w.writeByteNTimes(' ', level + half);
                try w.writeAll("cond:\n");
                try tree.dumpNode(cond, level + delta, w);
            }
            const incr = start[2];
            if (incr != 0) {
                try w.writeByteNTimes(' ', level + half);
                try w.writeAll("incr:\n");
                try tree.dumpNode(incr, level + delta, w);
            }
            const body = tree.nodes.items(.second)[node];
            if (body != 0) {
                try w.writeByteNTimes(' ', level + half);
                try w.writeAll("body:\n");
                try tree.dumpNode(body, level + delta, w);
            }
        },
        .goto_stmt => {
            try w.writeByteNTimes(' ', level + half);
            try w.print("label: " ++ LITERAL ++ "{s}\n" ++ RESET, .{tree.tokSlice(tree.nodes.items(.first)[node])});
        },
        .continue_stmt, .break_stmt => {},
        .return_stmt => {
            const expr = tree.nodes.items(.first)[node];
            if (expr != 0) {
                try w.writeByteNTimes(' ', level + half);
                try w.writeAll("expr:\n");
                try tree.dumpNode(expr, level + delta, w);
            }
        },
        .string_literal_expr => {
            const start = tree.nodes.items(.first)[node];
            const ptr = @intToPtr([*]const u8, @bitCast(usize, tree.data[start..][0..2].*));
            const len = tree.nodes.items(.second)[node];
            try w.writeByteNTimes(' ', level + half);
            try w.print("data: " ++ LITERAL ++ "\"{s}\"\n" ++ RESET, .{ptr[0 .. len - 1]});
        },
        .call_expr => {
            const start = tree.nodes.items(.first)[node];
            const end = tree.nodes.items(.second)[node];
            try w.writeByteNTimes(' ', level + half);
            try w.writeAll("lhs:\n");
            try tree.dumpNode(tree.data[start], level + delta, w);

            try w.writeByteNTimes(' ', level + half);
            try w.writeAll("args:\n");
            for (tree.data[start + 1 .. end]) |stmt| try tree.dumpNode(stmt, level + delta, w);
        },
        .call_expr_one => {
            try w.writeByteNTimes(' ', level + half);
            try w.writeAll("lhs:\n");
            try tree.dumpNode(tree.nodes.items(.first)[node], level + delta, w);
            const arg = tree.nodes.items(.second)[node];
            if (arg != 0) {
                try w.writeByteNTimes(' ', level + half);
                try w.writeAll("arg:\n");
                try tree.dumpNode(arg, level + delta, w);
            }
        },
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
        => {
            try w.writeByteNTimes(' ', level + 1);
            try w.writeAll("lhs:\n");
            try tree.dumpNode(tree.nodes.items(.first)[node], level + delta, w);
            try w.writeByteNTimes(' ', level + 1);
            try w.writeAll("rhs:\n");
            try tree.dumpNode(tree.nodes.items(.second)[node], level + delta, w);
        },
        .cast_expr,
        .addr_of_expr,
        .deref_expr,
        .plus_expr,
        .negate_expr,
        .bit_not_expr,
        .bool_not_expr,
        .pre_inc_expr,
        .pre_dec_expr,
        .post_inc_expr,
        .post_dec_expr,
        .array_to_pointer,
        .lval_to_rval,
        => {
            try w.writeByteNTimes(' ', level + 1);
            try w.writeAll("operand:\n");
            try tree.dumpNode(tree.nodes.items(.first)[node], level + delta, w);
        },
        .decl_ref_expr => {
            try w.writeByteNTimes(' ', level + 1);
            try w.print("name: " ++ NAME ++ "{s}\n" ++ RESET, .{tree.tokSlice(tree.nodes.items(.first)[node])});
        },
        .int_32_literal => {
            try w.writeByteNTimes(' ', level + 1);
            if (tree.nodes.items(.ty)[node].isUnsignedInt(tree.comp)) {
                try w.print("value: " ++ LITERAL ++ "{d}\n" ++ RESET, .{tree.nodes.items(.first)});
            } else {
                try w.print("value: " ++ LITERAL ++ "{d}\n" ++ RESET, .{@bitCast(i32, tree.nodes.items(.first)[node])});
            }
        },
        .int_64_literal => {
            try w.writeByteNTimes(' ', level + 1);
            const parts: [2]u32 = .{ tree.nodes.items(.first)[node], tree.nodes.items(.second)[node] };
            if (tree.nodes.items(.ty)[node].isUnsignedInt(tree.comp)) {
                try w.print("value: " ++ LITERAL ++ "{d}\n" ++ RESET, .{@bitCast(u64, parts)});
            } else {
                try w.print("value: " ++ LITERAL ++ "{d}\n" ++ RESET, .{@bitCast(i64, parts)});
            }
        },
        .float_literal => {
            try w.writeByteNTimes(' ', level + 1);
            try w.print("value: " ++ LITERAL ++ "{d}\n" ++ RESET, .{@bitCast(f32, tree.nodes.items(.first)[node])});
        },
        .double_literal => {
            try w.writeByteNTimes(' ', level + 1);
            const parts: [2]u32 = .{ tree.nodes.items(.first)[node], tree.nodes.items(.second)[node] };
            try w.print("value: " ++ LITERAL ++ "{d}\n" ++ RESET, .{@bitCast(f64, parts)});
        },
        else => {},
    }
}
