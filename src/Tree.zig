const std = @import("std");
const Type = @import("Type.zig");

const Tree = @This();

pub const TokenIndex = u32;
pub const TagIndex = u32;

tokens: []const Token,
tags: []const Tag,
stmts: []const Stmt,
exprs: []const Expr,
root_decls: []const Tag,

pub const Tag = enum(u8) {

    // ====== Stmt ======

    labeled_stmt,
    compound_stmt,
    if_stmt,
    if_else_stmt,
    switch_stmt,
    while_stmt,
    do_while_stmt,
    for_stmt,
    goto_stmt,
    continue_stmt,
    break_stmt,
    return_stmt,
    expr_stmt,

    // ====== Expr ======

    /// lhs , rhs
    comma_expr,
    /// lhs ?: rhs
    binary_cond_expr,
    /// TODO
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
    /// TODO
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
};

pub const Decl = struct {

};

pub const Stmt = struct {
};

pub const Expr = struct {
    type: Type,
    lhs: ExprIndex,
    lhs: ExprIndex,
};
