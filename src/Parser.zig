const std = @import("std");
const mem = std.mem;
const Allocator = mem.Allocator;
const assert = std.debug.assert;
const Compilation = @import("Compilation.zig");
const Source = @import("Source.zig");
const Tokenizer = @import("Tokenizer.zig");
const Token = Tokenizer.Token;
const Preprocessor = @import("Preprocessor.zig");
const Tree = @import("Tree.zig");
const TagIndex = Tree.TagIndex;
const Type = @import("Type.zig");

const Parser = @This();

pub const Result = union(enum) {
    none,
    bool: bool,
    u8: u8,
    i8: i8,
    u16: u16,
    i16: i16,
    u32: u32,
    i32: i32,
    u64: u64,
    i64: i64,
    expr: TagIndex,

    pub fn getBool(res: Result) bool {
        return switch (res) {
            .bool => |v| v,
            .u8 => |v| v != 0,
            .i8 => |v| v != 0,
            .u16 => |v| v != 0,
            .i16 => |v| v != 0,
            .u32 => |v| v != 0,
            .i32 => |v| v != 0,
            .u64 => |v| v != 0,
            .i64 => |v| v != 0,
            .none, .node => unreachable,
        };
    }
};

const Error = Allocator.Error || error{ParsingFailed};

pp: *Preprocessor,
tokens: []const Token,
tok_i: u32 = 0,
want_const: bool = false,

fn eatToken(p: *Parser, id: Token.Id) bool {
    if (p.tokens[p.tok_i].id == id) {
        p.tok_i += 1;
        return true;
    } else return false;
}

fn expectToken(p: *Parser, id: Token.Id) Error!void {
    const cur_id = p.tokens[p.tok_i].id;
    if (cur_id != id) {
        switch (cur_id) {
            .invalid => return p.failFmt("expected '{s}', found invalid bytes", .{@tagName(id)}),
            else => return p.failFmt("expected '{s}', found '{s}'", .{ @tagName(id), @tagName(cur_id) }),
        }
    }
    p.tok_i += 1;
}

fn failFmt(p: *Parser, comptime fmt: []const u8, args: anytype) Error {
    const tok = p.tokens[p.tok_i];
    const source = p.pp.comp.getSource(tok.source);
    const lcs = source.lineColString(tok.loc);
    p.pp.comp.printErrStart(source.path, lcs);
    std.debug.print(fmt, args);
    p.pp.comp.printErrEnd(lcs);
    return error.ParsingFailed;
}

fn fail(p: *Parser, msg: []const u8) Error {
    return p.failFmt("{s}", .{msg});
}

pub fn parse(p: *Parser) Error!Tree {

}

// ====== declarations ======

/// decl 
///  : declSpec+ (initDeclarator ( ',' initDeclarator)*)? ';'
///  | declSpec+ declarator declarator* compoundStmt
///  | staticAssert

/// staticAssert : keyword_static_assert '(' constExpr ',' STRING_LITERAL ')' ';'

/// declSpec: storageClassSpec | typeSpec | typeQual | funcSpec | alignSpec

/// initDeclarator : declarator ('=' initializer)?

/// storageClassSpec:
///  : keyword_typedef
///  | keyword_extern
///  | keyword_static
///  | keyword_threadlocal
///  | keyword_auto
///  | keyword_register

/// typeSpec
///  : keyword_void
///  | keyword_char
///  | keyword_short
///  | keyword_int
///  | keyword_long
///  | keyword_float
///  | keyword_double
///  | keyword_signed
///  | keyword_unsigned
///  | keyword_bool
///  | keyword_complex
///  | atomic-type-specifier
///  | recordSpec
///  | enumSpec
///  | typedef  // IDENTIFIER

/// recordSpec
///  : (keyword_struct | keyword_union) IDENTIFIER? { recordDecl* }
///  | (keyword_struct | keyword_union) IDENTIFIER

/// recordDecl
///  : specQual+ (recordDeclarator (',' recordDeclarator)*)? ;
///  | staticAssert

/// recordDeclarator : declarator (':' constExpr)?

// specQual : typeSpec | typeQual | alignSpec

/// enumSpec
///  : keyword_enum IDENTIFIER? { enumerator (',' enumerator)? ',') }
///  | keyword_enum IDENTIFIER

/// enumerator : IDENTIFIER ('=' constExpr)

/// atomicTypeSpec : keyword_atomic '(' typeName ')'

/// typeQual : keyword_const | keyword_restrict | keyword_volatile | keyword_atomic

/// funcSpec : keyword_inline | keyword_noreturn

/// alignSpec : keyword_alignas '(' typeName ')'

/// declarator: pointer? directDeclarator

/// directDeclarator
///  : IDENTIFIER
///  | '(' declarator ')'
///  | directDeclarator '[' typeQual* assignExpr? ']'
///  | directDeclarator '[' keyword_static typeQual* assignExpr ']'
///  | directDeclarator '[' typeQual* keyword_static assignExpr ']'
///  | directDeclarator '[' typeQual* '*' ']'
///  | directDeclarator '(' paramDecls ')'
///  | directDeclarator '(' (IDENTIFIER (',' IDENTIFIER))? ')'

/// pointer : '*' typeQual* pointer?

/// paramDecls : paramDecl (',' paramDecl)* (',' '...')

/// paramDecl : declSpec+ (declarator | abstractDeclarator?)

/// typeName : specQual+ abstractDeclarator?

/// abstractDeclarator
/// : pointer
/// | pointer? directAbstractDeclarator

/// directAbstractDeclarator
///  : '(' abstractDeclarator ')'
///  | directAbstractDeclarator? '[' typeQual* assignExpr? ']'
///  | directAbstractDeclarator? '[' keyword_static typeQual* assignExpr ']'
///  | directAbstractDeclarator? '[' typeQual+ keyword_static assignExpr ']'
///  | directAbstractDeclarator? '[' '*' ']'
///  | directAbstractDeclarator? '(' paramDecls? ')'

/// initializer
///  : assignExpr
///  | '{' initializerItems '}'

/// initializerItems : designation? initializer  (',' designation? initializer)? ','?

/// designation : designator+ '='

/// designator
///  : '[' constExpr ']'
///  | '.' identifier


// ====== statements ======

/// stmt
///  : labeledStmt
///  | compoundStmt
///  | keyword_if '(' expr ')' stmt (keyword_else stmt)?
///  | keyword_switch '(' expr ')' stmt
///  | keyword_while '(' expr ')' stmt
///  | keyword_do stmt while '(' expr ')' ';'
///  | keyword_for '(' (decl | expr? ';') expr? ';' expr? ')' stmt
///  | keyword_goto IDENTIFIER ';'
///  | keyword_continue ';'
///  | keyword_break ';'
///  | keyword_return expr? ';'
///  | expr? ';'
fn stmt(p: *Parser) Error!TagIndex {
    return p.fail("TODO stmt");
}

/// labeledStmt
/// : IDENTIFIER ':' stmt
/// | keyword_case constExpr ':' stmt
/// | keyword_default ':' stmt
fn labeledStmt(p: *Parser) Error!TagIndex {
    return p.fail("TODO labeledStmt");
}

/// compoundStmt : '{' ( decl | stmt)* '}'
fn compoundStmt(p: *Parser) Error!TagIndex {
    return p.fail("TODO compoundStmt");
}

// ====== expressions ======

/// expr : assignExpr (',' assignExpr)*
fn expr(p: *Parser) Error!Result {
    return p.fail("TODO expr");
}

/// assignExpr
///  : condExpr
///  | unExpr ('=' | '*=' | '/=' | '%=' | '+=' | '-=' | '<<=' | '>>=' | '&=' | '^=' | '|=') assignExpr
fn assignExpr(p: *Parser) Error!Result {}

/// constExpr : condExpr
pub fn constExpr(p: *Parser) Error!Result {
    const saved_const = p.want_const;
    defer p.want_const = saved_const;
    p.want_const = true;
    return p.condExpr();
}

/// condExpr : lorExpr ('?' expression? ':' condExpr)?
fn condExpr(p: *Parser) Error!Result {
    const cond = try p.lorExpr();
    if (!p.eatToken(.question_mark)) return cond;
    const then_expr = try p.expr();
    try p.expectToken(.colon);
    const else_expr = try p.condExpr();

    if (p.want_const or cond != .node) {
        return if (cond.getBool()) then_expr else else_expr;
    }
    return p.fail("TODO ast");
}

/// lorExpr : landExpr ('||' landExpr)*
fn lorExpr(p: *Parser) Error!Result {
    var lhs = try p.landExpr();
    while (p.eatToken(.pipe_pipe)) {
        const rhs = try p.landExpr();

        if (p.want_const or (lhs != .node and rhs != .node)) {
            lhs = Result{ .bool = lhs.getBool() or rhs.getBool() };
        } else return p.fail("TODO ast");
    }
    return lhs;
}

/// landExpr : orExpr ('&&' orExpr)*
fn landExpr(p: *Parser) Error!Result {
    var lhs = try p.orExpr();
    while (p.eatToken(.ampersand_ampersand)) {
        const rhs = try p.orExpr();

        if (p.want_const or (lhs != .node and rhs != .node)) {
            lhs = Result{ .bool = lhs.getBool() and rhs.getBool() };
        } else return p.fail("TODO ast");
    }
    return lhs;
}

/// orExpr : xorExpr ('|' xorExpr)*
fn orExpr(p: *Parser) Error!Result {
    var lhs = try p.xorExpr();
    while (p.eatToken(.pipe)) {
        const rhs = try p.xorExpr();

        if (p.want_const or (lhs != .node and rhs != .node)) {
            return p.fail("TODO or constExpr");
        } else return p.fail("TODO ast");
    }
    return lhs;
}

/// xorExpr : andExpr ('^' andExpr)*
fn xorExpr(p: *Parser) Error!Result {
    var lhs = try p.andExpr();
    while (p.eatToken(.caret)) {
        const rhs = try p.andExpr();

        if (p.want_const or (lhs != .node and rhs != .node)) {
            return p.fail("TODO xor constExpr");
        } else return p.fail("TODO ast");
    }
    return lhs;
}

/// andExpr : eqExpr ('&' eqExpr)*
fn andExpr(p: *Parser) Error!Result {
    var lhs = try p.eqExpr();
    while (p.eatToken(.ampersand)) {
        const rhs = try p.eqExpr();

        if (p.want_const or (lhs != .node and rhs != .node)) {
            return p.fail("TODO and constExpr");
        } else return p.fail("TODO ast");
    }
    return lhs;
}

/// eqExpr : compExpr (('==' | '!=') compExpr)*
fn eqExpr(p: *Parser) Error!Result {
    var lhs = try p.compExpr();
    while (true) {
        const eq = p.eatToken(.equal_equal);
        if (!eq and !p.eatToken(.bang_equal)) break;
        const rhs = try p.compExpr();

        if (p.want_const or (lhs != .node and rhs != .node)) {
            return p.fail("TODO equality constExpr");
        }
        return p.fail("TODO ast");
    }
    return lhs;
}

/// compExpr : shiftExpr (('<' | '<=' | '>' | '>=') shiftExpr)*
fn compExpr(p: *Parser) Error!Result {
    const lhs = try p.shiftExpr();
    while (true) {
        const lt = p.eatToken(.angle_bracket_left);
        const le = lt or p.eatToken(.angle_bracket_left_equal);
        const gt = le or p.eatToken(.angle_bracket_right);
        const ge = gt or p.eatToken(.angle_bracket_right_equal);
        if (!ge) break;
        const rhs = try p.shiftExpr();

        if (p.want_const or (lhs != .node and rhs != .node)) {
            return p.fail("TODO comp constExpr");
        }
        return p.fail("TODO ast");
    }
    return lhs;
}

/// shiftExpr : addExpr (('<<' | '>>') addExpr)*
fn shiftExpr(p: *Parser) Error!Result {
    const lhs = try p.addExpr();
    while (true) {
        const shl = p.eatToken(.angle_bracket_angle_bracket_left);
        const shr = shl or p.eatToken(.angle_bracket_angle_bracket_right);
        if (!shr) break;
        const rhs = try p.addExpr();

        if (p.want_const or (lhs != .node and rhs != .node)) {
            return p.fail("TODO shift constExpr");
        }
        return p.fail("TODO ast");
    }
    return lhs;
}

/// addExpr : mulExpr (('+' | '-') mulExpr)*
fn addExpr(p: *Parser) Error!Result {
    const lhs = try p.mulExpr();
    while (true) {
        const plus = p.eatToken(.plus);
        const minus = plus or p.eatToken(.minus);
        if (!minus) break;
        const rhs = try p.mulExpr();

        if (p.want_const or (lhs != .node and rhs != .node)) {
            return p.fail("TODO shift constExpr");
        }
        return p.fail("TODO ast");
    }
    return lhs;
}

/// mulExpr : castExpr (('*' | '/' | '%') castExpr)*´
fn mulExpr(p: *Parser) Error!Result {
    const lhs = try p.castExpr();
    while (true) {
        const mul = p.eatToken(.plus);
        const div = mul or p.eatToken(.slash);
        const percent = div or p.eatToken(.percent);
        if (!percent) break;
        const rhs = try p.castExpr();

        if (p.want_const or (lhs != .node and rhs != .node)) {
            return p.fail("TODO mul constExpr");
        }
        return p.fail("TODO ast");
    }
    return lhs;
}

/// castExpr :  ( '(' typeName ')' )* unExpr
fn castExpr(p: *Parser) Error!Result {
    if (!p.eatToken(.l_paren)) {
        return p.unExpr();
    }
    return p.fail("TODO cast");
}

/// unExpr
///  : primaryExpr suffixExpr*
///  | ('&' | '*' | '+' | '-' | '~' | '!' | '++' | '--') castExpr
///  | keyword_sizeof unExpr
///  | keyword_sizeof '(' typeName ')'
///  | keyword_alignof '(' typeName ')'
fn unExpr(p: *Parser) Error!Result {
    switch (p.tokens[p.tok_i].id) {
        .ampersand => return p.fail("TODO unExpr ampersand"),
        .asterisk => return p.fail("TODO unExpr asterisk"),
        .plus => return p.fail("TODO unExpr plus"),
        .minus => return p.fail("TODO unExpr minus"),
        .plus_plus => return p.fail("TODO unary inc"),
        .minus_minus => return p.fail("TODO unary dec"),
        .tilde => return p.fail("TODO unExpr tilde"),
        .bang => {
            p.tok_i += 1;
            const lhs = try p.unExpr();
            if (p.want_const or lhs != .node) {
                return Result{ .bool = !lhs.getBool() };
            }
            return p.fail("TODO ast");
        },
        .keyword_sizeof => return p.fail("TODO unExpr sizeof"),
        else => {
            var lhs = try p.primaryExpr();
            while (true) {
                const suffix = try p.suffixExpr(&lhs);
                if (suffix == .none) break;
            }
            return lhs;
        },
    }
}

/// suffixExpr
///  : '[' expr ']'
///  | '(' argumentExprList? ')'
///  | '.' IDENTIFIER
///  | '->' IDENTIFIER
///  | '++'
///  | '--'
fn suffixExpr(p: *Parser, lhs: *Result) Error!Result {
    switch (p.tokens[p.tok_i].id) {
        .l_bracket => return p.fail("TODO array access"),
        .l_paren => return p.fail("TODO call"),
        .period => return p.fail("TODO member access"),
        .arrow => return p.fail("TODO member access pointer"),
        .plus_plus => return p.fail("TODO post inc"),
        .minus_minus => return p.fail("TODO post dec"),
        else => return Result{ .none = {} },
    }
}

/// argumentExprList : assignExpr (',' assignExpr)*
fn argumentExprList(p: *Parser) Error!Result {}

/// primaryExpr
///  : IDENTIFIER
///  | INTEGER_LITERAL
///  | FLOAT_LITERAL
///  | CHAR_LITERAL
///  | STRING_LITERAL
///  | '(' expr ')'
///  | '(' typeName ')' '{' initializerItems '}'
///  | keyword_generic '(' assignExpr ',' genericAssoc (',' genericAssoc)* ')'
///
/// genericAssoc
///  : typeName ':' assignExpr
///  | keyword_default ':' assignExpr
fn primaryExpr(p: *Parser) Error!Result {
    if (p.eatToken(.l_paren)) {
        const e = try p.expr();
        try p.expectToken(.r_paren);
        return e;
    }
    switch (p.tokens[p.tok_i].id) {
        .identifier => {
            return p.fail("TODO ast");
        },
        .string_literal,
        .string_literal_utf_16,
        .string_literal_utf_8,
        .string_literal_utf_32,
        .string_literal_wide,
        => {
            if (p.want_const) {
                return p.fail("expression is not an integer constant expression");
            }
            return p.fail("TODO ast");
        },
        .char_literal,
        .char_literal_utf_16,
        .char_literal_utf_32,
        .char_literal_wide,
        => {
            if (p.want_const) {
                return p.fail("TODO char literals");
            }
            return p.fail("TODO ast");
        },
        .float_literal,
        .float_literal_f,
        .float_literal_l,
        => {
            if (p.want_const) {
                return p.fail("expression is not an integer constant expression");
            }
            return p.fail("TODO ast");
        },
        .zero => {
            p.tok_i += 1;
            return Result{ .u32 = 0 };
        },
        .one => {
            p.tok_i += 1;
            return Result{ .u32 = 1 };
        },
        .integer_literal,
        .integer_literal_u,
        .integer_literal_l,
        .integer_literal_lu,
        .integer_literal_ll,
        .integer_literal_llu,
        => {
            if (p.want_const) {
                return p.fail("TODO integer literals");
            }
            return p.fail("TODO ast");
        },
        .keyword_generic => {
            return p.fail("TODO generic");
        },
        else => return p.failFmt("expected literal, identifier or grouped expression, found '{s}'", .{@tagName(p.tokens[p.tok_i].id)}),
    }
}
