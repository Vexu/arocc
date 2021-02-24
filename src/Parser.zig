const std = @import("std");
const mem = std.mem;
const Allocator = mem.Allocator;
const assert = std.debug.assert;
const Compilation = @import("Compilation.zig");
const Source = @import("Source.zig");
const Token = @import("Tokenizer.zig").Token;
const Preprocessor = @import("Preprocessor.zig");
const Tree = @import("Tree.zig");
const TokenIndex = Tree.TokenIndex;
const TagIndex = Tree.TagIndex;
const Type = @import("Type.zig");
const Qualifiers = Type.Qualifiers;
const Diagnostics = @import("Diagnostics.zig");

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
    // expr: TagIndex, TODO
    node,

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

const Error = Compilation.Error || error{ParsingFailed};

pp: *Preprocessor,
tokens: []const Token,
tok_i: TokenIndex = 0,
want_const: bool = false,

fn eatToken(p: *Parser, id: Token.Id) bool {
    if (p.tokens[p.tok_i].id == id) {
        p.tok_i += 1;
        return true;
    } else return false;
}

fn expectToken(p: *Parser, id: Token.Id) Error!void {
    const tok = p.tokens[p.tok_i];
    if (tok.id != id) {
        try p.pp.comp.diag.add(.{
            .tag = switch (tok.id) {
                .invalid => .expected_invalid,
                else => .expected_token,
            },
            .source_id = tok.source,
            .loc_start = tok.loc.start,
            .extra = .{
                .tok_id = .{
                    .expected = id,
                    .actual = tok.id,
                },
            },
        });
        return error.ParsingFailed;
    }
    p.tok_i += 1;
}

fn err(p: *Parser, tag: Diagnostics.Tag) Error!void {
    const tok = p.tokens[p.tok_i];
    try p.pp.comp.diag.add(.{
        .tag = tag,
        .source_id = tok.source,
        .loc_start = tok.loc.start,
    });
}

fn todo(p: *Parser, msg: []const u8) Error {
    const tok = p.tokens[p.tok_i];
    try p.pp.comp.diag.add(.{
        .tag = .todo,
        .source_id = tok.source,
        .loc_start = tok.loc.start,
        .extra = .{ .str = msg },
    });
    return error.ParsingFailed;
}

pub fn parse(p: *Parser) Error!void {
    _ = try p.declSpec();
}

// ====== declarations ======

/// decl
///  : declSpec (initDeclarator ( ',' initDeclarator)*)? ';'
///  | declSpec declarator declarator* compoundStmt
///  | staticAssert
fn decl(p: *Parser) Error!TagIndex {
    return p.todo("decl");
}

/// staticAssert : keyword_static_assert '(' constExpr ',' STRING_LITERAL ')' ';'
fn staticAssert(p: *Parser) Error!bool {
    const static_assert = p.tokens[p.tok_i];
    if (!p.eatToken(.keyword_static_assert)) return false;
    try p.expectToken(.l_paren);
    const start = p.tok_i;
    const res = try p.constExpr();
    const end = p.tok_i;
    try p.expectToken(.comma);
    const str = p.tokens[p.tok_i]; // TODO resolve string literal
    try p.expectToken(.string_literal);
    try p.expectToken(.r_paren);

    if (!res.getBool()) {
        var msg = std.ArrayList(u8).init(p.pp.comp.gpa);
        defer msg.deinit();

        try msg.append('\'');
        for (p.tokens[start..end]) |tok, i| {
            if (i != 0) try msg.append(' ');
            try msg.appendSlice(p.pp.tokSlice(tok));
        }
        try msg.appendSlice("' ");
        try msg.appendSlice(p.pp.tokSlice(str));
        try p.pp.comp.diag.add(.{
            .tag = .static_assert_failure,
            .source_id = static_assert.source,
            .loc_start = static_assert.loc.start,
            .extra = .{ .str = try p.pp.arena.allocator.dupe(u8, msg.items) },
        });
    }
    return true;
}

pub const DeclSpec = struct {
    storage_class: union(enum) {
        auto,
        @"extern",
        register,
        static,
        typedef,
        none,
    } = .none,
    thread_local: bool = false,
    @"inline": bool = false,
    @"noreturn": bool = false,
    type: Type = .{},
};

/// declSpec: (storageClassSpec | typeSpec | typeQual | funcSpec | alignSpec)+
/// storageClassSpec:
///  : keyword_typedef
///  | keyword_extern
///  | keyword_static
///  | keyword_threadlocal
///  | keyword_auto
///  | keyword_register
/// funcSpec : keyword_inline | keyword_noreturn
fn declSpec(p: *Parser) Error!?DeclSpec {
    var d = DeclSpec{};

    var any: bool = false;
    while (true) {
        if (try p.typeSpec(&d.type)) {
            any = true;
            continue;
        }
        const tok = p.tokens[p.tok_i];
        switch (tok.id) {
            .keyword_typedef,
            .keyword_extern,
            .keyword_static,
            .keyword_auto,
            .keyword_register,
            => {
                if (d.storage_class != .none) {
                    try p.pp.comp.diag.add(.{
                        .tag = .multiple_storage_class,
                        .source_id = tok.source,
                        .loc_start = tok.loc.start,
                        .extra = .{ .str = @tagName(d.storage_class) },
                    });
                    return error.ParsingFailed;
                }
                switch (tok.id) {
                    .keyword_typedef => d.storage_class = .typedef,
                    .keyword_extern => d.storage_class = .@"extern",
                    .keyword_static => d.storage_class = .static,
                    .keyword_auto => d.storage_class = .auto,
                    .keyword_register => d.storage_class = .register,
                    else => unreachable,
                }
            },
            .keyword_thread_local => {
                if (d.thread_local) {
                    try p.err(.duplicate_decl_spec);
                }
                d.thread_local = true;
            },
            .keyword_inline => {
                if (d.@"inline") {
                    try p.err(.duplicate_decl_spec);
                }
                d.@"inline" = true;
            },
            .keyword_noreturn => {
                if (d.@"noreturn") {
                    try p.err(.duplicate_decl_spec);
                }
                d.@"noreturn" = true;
            },
            else => break,
        }
        p.tok_i += 1;
        any = true;
    }

    if (!any) return null;
    try p.defaultTypeSpec(&d.type);
    return d;
}

/// initDeclarator : declarator ('=' initializer)?
fn initDeclarator(p: *Parser) Error!TagIndex {
    return p.todo("initDeclarator");
}

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
///  | atomicTypeSpec
///  | recordSpec
///  | enumSpec
///  | typedef  // IDENTIFIER
/// atomicTypeSpec : keyword_atomic '(' typeName ')'
/// alignSpec : keyword_alignas '(' typeName ')'
fn typeSpec(p: *Parser, ty: *Type) Error!bool {
    var any = false;
    while (true) {
        if (try p.typeQual(ty)) {
            any = true;
            continue;
        }
        const tok = p.tokens[p.tok_i];
        switch (tok.id) {
            .keyword_void => {
                if (ty.specifier != .none) {
                    return p.cannotCombineSpec(ty.specifier);
                }
                ty.specifier = .void;
            },
            .keyword_bool => {
                if (ty.specifier != .none) {
                    return p.cannotCombineSpec(ty.specifier);
                }
                ty.specifier = .bool;
            },
            .keyword_char => switch (ty.specifier) {
                .none => ty.specifier = .char,
                .unsigned => ty.specifier = .uchar,
                .signed => ty.specifier = .schar,
                else => return p.cannotCombineSpec(ty.specifier),
            },
            .keyword_short => switch (ty.specifier) {
                .none => ty.specifier = .short,
                .signed => ty.specifier = .short,
                .unsigned => ty.specifier = .ushort,
                .ushort, .short => try p.duplicateSpecifier("short"),
                else => return p.cannotCombineSpec(ty.specifier),
            },
            .keyword_int => switch (ty.specifier) {
                .none => ty.specifier = .int,
                .signed => ty.specifier = .int,
                .unsigned => ty.specifier = .uint,
                .ushort,
                .long,
                .ulong,
                .long_long,
                .ulong_long,
                => {}, // TODO warn duplicate int specifier
                .int, .uint => try p.duplicateSpecifier("int"),
                else => return p.cannotCombineSpec(ty.specifier),
            },
            .keyword_long => switch (ty.specifier) {
                .none => ty.specifier = .long,
                .long => ty.specifier = .long_long,
                .unsigned => ty.specifier = .ulong,
                .signed => ty.specifier = .long,
                .ulong => ty.specifier = .ulong_long,
                .long_long, .ulong_long => try p.duplicateSpecifier("long"),
                else => return p.cannotCombineSpec(ty.specifier),
            },
            .keyword_signed => switch (ty.specifier) {
                .none => ty.specifier = .signed,
                .char => ty.specifier = .schar,
                .int,
                .short,
                .long,
                .long_long,
                => {}, // TODO warn duplicate signed specifier
                .schar, .signed => try p.duplicateSpecifier("signed"),
                else => return p.cannotCombineSpec(ty.specifier),
            },
            .keyword_unsigned => switch (ty.specifier) {
                .none => ty.specifier = .unsigned,
                .char => ty.specifier = .uchar,
                .uint,
                .ushort,
                .ulong,
                .ulong_long,
                => {}, // TODO warn duplicate unsigned specifier
                .uchar, .unsigned => try p.duplicateSpecifier("unsigned"),
                else => return p.cannotCombineSpec(ty.specifier),
            },
            .keyword_float => switch (ty.specifier) {
                .long_double,
                .complex_long_double,
                .complex_long,
                .complex_double,
                .double,
                => {}, // TODO warn duplicate float
                .long => ty.specifier = .long_double, // TODO long float is invalid
                .none => ty.specifier = .float,
                .complex => ty.specifier = .complex_float,
                .complex_float, .float => try p.duplicateSpecifier("float"),
                else => return p.cannotCombineSpec(ty.specifier),
            },
            .keyword_double => switch (ty.specifier) {
                .long => ty.specifier = .long_double,
                .complex_long => ty.specifier = .complex_long_double,
                .complex_float, .complex => ty.specifier = .complex_double,
                .float, .none => ty.specifier = .double,
                .long_double,
                .complex_long_double,
                .complex_double,
                .double,
                => try p.duplicateSpecifier("double"),
                else => return p.cannotCombineSpec(ty.specifier),
            },
            .keyword_complex => switch (ty.specifier) {
                .long => ty.specifier = .complex_long,
                .float => ty.specifier = .complex_float,
                .double => ty.specifier = .complex_double,
                .long_double => ty.specifier = .complex_long_double,
                .none => ty.specifier = .complex,
                .complex_long,
                .complex,
                .complex_float,
                .complex_double,
                .complex_long_double,
                => try p.duplicateSpecifier("_Complex"),
                else => return p.cannotCombineSpec(ty.specifier),
            },
            .keyword_atomic => return p.todo("atomic types"),
            .keyword_enum => return p.todo("enum types"),
            .keyword_struct => return p.todo("struct types"),
            .keyword_union => return p.todo("union types"),
            .keyword_alignas => {
                if (ty.alignment != 0) try p.duplicateSpecifier("alignment");
                try p.expectToken(.l_paren);
                const other_type = try p.typeName();
                try p.expectToken(.r_paren);
                ty.alignment = other_type.alignment;
            },
            else => break,
        }
        p.tok_i += 1;
        any = true;
    }
    return any;
}

fn cannotCombineSpec(p: *Parser, spec: Type.Specifier) Error {
    const tok = p.tokens[p.tok_i];
    try p.pp.comp.diag.add(.{
        .tag = .cannot_combine_spec,
        .source_id = tok.source,
        .loc_start = tok.loc.start,
        .extra = .{ .str = spec.str() },
    });
    return error.ParsingFailed;
}

fn duplicateSpecifier(p: *Parser, spec: []const u8) Error!void {
    const tok = p.tokens[p.tok_i];
    try p.pp.comp.diag.add(.{
        .tag = .duplicate_decl_spec,
        .source_id = tok.source,
        .loc_start = tok.loc.start,
        .extra = .{ .str = spec },
    });
}

fn defaultTypeSpec(p: *Parser, ty: *Type) Error!void {
    switch (ty.specifier) {
        .none => {
            ty.specifier = .int;
            try p.err(.missing_type_specifier);
        },
        .unsigned => ty.specifier = .uint,
        .signed => ty.specifier = .int,
        .complex_long => ty.specifier = .complex_long_double,
        .complex => ty.specifier = .complex_double,
        else => {},
    }
}
/// recordSpec
///  : (keyword_struct | keyword_union) IDENTIFIER? { recordDecl* }
///  | (keyword_struct | keyword_union) IDENTIFIER
fn recordSpec(p: *Parser) Error!TagIndex {
    return p.todo("recordSpec");
}

/// recordDecl
///  : specQual (recordDeclarator (',' recordDeclarator)*)? ;
///  | staticAssert
fn recordDecl(p: *Parser) Error!TagIndex {
    return p.todo("recordDecl");
}

/// recordDeclarator : declarator (':' constExpr)?
fn recordDeclarator(p: *Parser) Error!TagIndex {
    return p.todo("recordDeclarator");
}

/// specQual : (typeSpec | typeQual | alignSpec)+
fn specQual(p: *Parser) Error!Type {
    var ty = Type{};
    if (try p.typeSpec(&ty)) {
        try p.defaultTypeSpec(&ty);
        return ty;
    }
    try p.err(.expected_a_type);
    return error.ParsingFailed;
}

/// enumSpec
///  : keyword_enum IDENTIFIER? { enumerator (',' enumerator)? ',') }
///  | keyword_enum IDENTIFIER
fn enumSpec(p: *Parser) Error!TagIndex {
    return p.todo("enumSpec");
}

/// enumerator : IDENTIFIER ('=' constExpr)
fn enumerator(p: *Parser) Error!TagIndex {
    return p.todo("enumerator");
}

/// typeQual : keyword_const | keyword_restrict | keyword_volatile | keyword_atomic
fn typeQual(p: *Parser, ty: *Type) Error!bool {
    var any = false;
    while (true) {
        const tok = p.tokens[p.tok_i];
        switch (tok.id) {
            .keyword_restrict => {
                if (ty.specifier != .pointer)
                    try p.pp.comp.diag.add(.{
                        .tag = .restrict_non_pointer,
                        .source_id = tok.source,
                        .loc_start = tok.loc.start,
                        .extra = .{ .str = ty.specifier.str() },
                    })
                else if (ty.qual.restrict)
                    try p.duplicateSpecifier("restrict")
                else
                    ty.qual.restrict = true;
            },
            .keyword_const => {
                if (ty.qual.@"const")
                    try p.duplicateSpecifier("const")
                else
                    ty.qual.@"const" = true;
            },
            .keyword_volatile => {
                if (ty.qual.@"volatile")
                    try p.duplicateSpecifier("volatile")
                else
                    ty.qual.@"volatile" = true;
            },
            .keyword_atomic => {
                if (ty.qual.atomic)
                    try p.duplicateSpecifier("atomic")
                else
                    ty.qual.atomic = true;
            },
            else => break,
        }
        p.tok_i += 1;
        any = true;
    }
    return any;
}

/// declarator: pointer? directDeclarator
fn declarator(p: *Parser) Error!TagIndex {
    return p.todo("declarator");
}

/// directDeclarator
///  : IDENTIFIER
///  | '(' declarator ')'
///  | directDeclarator '[' typeQual* assignExpr? ']'
///  | directDeclarator '[' keyword_static typeQual* assignExpr ']'
///  | directDeclarator '[' typeQual* keyword_static assignExpr ']'
///  | directDeclarator '[' typeQual* '*' ']'
///  | directDeclarator '(' paramDecls ')'
///  | directDeclarator '(' (IDENTIFIER (',' IDENTIFIER))? ')'
fn directDeclarator(p: *Parser) Error!TagIndex {
    return p.todo("directDeclarator");
}

/// pointer : '*' typeQual* pointer?
fn pointer(p: *Parser) Error!TagIndex {
    return p.todo("pointer");
}

/// paramDecls : paramDecl (',' paramDecl)* (',' '...')
/// paramDecl : declSpec (declarator | abstractDeclarator?)
fn paramDecls(p: *Parser) Error!TagIndex {
    return p.todo("paramDecls");
}

/// typeName : specQual abstractDeclarator?
fn typeName(p: *Parser) Error!Type {
    const ty = try p.specQual();
    return p.todo("typeName");
}

/// abstractDeclarator
/// : pointer
/// | pointer? directAbstractDeclarator
fn abstractDeclarator(p: *Parser) Error!TagIndex {
    return p.todo("abstractDeclarator");
}

/// directAbstractDeclarator
///  : '(' abstractDeclarator ')'
///  | directAbstractDeclarator? '[' typeQual* assignExpr? ']'
///  | directAbstractDeclarator? '[' keyword_static typeQual* assignExpr ']'
///  | directAbstractDeclarator? '[' typeQual+ keyword_static assignExpr ']'
///  | directAbstractDeclarator? '[' '*' ']'
///  | directAbstractDeclarator? '(' paramDecls? ')'
fn directAbstractDeclarator(p: *Parser) Error!TagIndex {
    return p.todo("directAbstractDeclarator");
}

/// initializer
///  : assignExpr
///  | '{' initializerItems '}'
fn initializer(p: *Parser) Error!TagIndex {
    return p.todo("initializer");
}

/// initializerItems : designation? initializer  (',' designation? initializer)? ','?
fn initializerItems(p: *Parser) Error!TagIndex {
    return p.todo("initializerItems");
}
/// designation : designator+ '='
fn designation(p: *Parser) Error!TagIndex {
    return p.todo("designation");
}

/// designator
///  : '[' constExpr ']'
///  | '.' identifier
fn designator(p: *Parser) Error!TagIndex {
    return p.todo("designator");
}

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
    return p.todo("stmt");
}

/// labeledStmt
/// : IDENTIFIER ':' stmt
/// | keyword_case constExpr ':' stmt
/// | keyword_default ':' stmt
fn labeledStmt(p: *Parser) Error!TagIndex {
    return p.todo("labeledStmt");
}

/// compoundStmt : '{' ( decl | stmt)* '}'
fn compoundStmt(p: *Parser) Error!TagIndex {
    return p.todo("compoundStmt");
}

// ====== expressions ======

/// expr : assignExpr (',' assignExpr)*
fn expr(p: *Parser) Error!Result {
    return p.todo("expr");
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
    return p.todo("ast");
}

/// lorExpr : landExpr ('||' landExpr)*
fn lorExpr(p: *Parser) Error!Result {
    var lhs = try p.landExpr();
    while (p.eatToken(.pipe_pipe)) {
        const rhs = try p.landExpr();

        if (p.want_const or (lhs != .node and rhs != .node)) {
            lhs = Result{ .bool = lhs.getBool() or rhs.getBool() };
        } else return p.todo("ast");
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
        } else return p.todo("ast");
    }
    return lhs;
}

/// orExpr : xorExpr ('|' xorExpr)*
fn orExpr(p: *Parser) Error!Result {
    var lhs = try p.xorExpr();
    while (p.eatToken(.pipe)) {
        const rhs = try p.xorExpr();

        if (p.want_const or (lhs != .node and rhs != .node)) {
            return p.todo("or constExpr");
        } else return p.todo("ast");
    }
    return lhs;
}

/// xorExpr : andExpr ('^' andExpr)*
fn xorExpr(p: *Parser) Error!Result {
    var lhs = try p.andExpr();
    while (p.eatToken(.caret)) {
        const rhs = try p.andExpr();

        if (p.want_const or (lhs != .node and rhs != .node)) {
            return p.todo("xor constExpr");
        } else return p.todo("ast");
    }
    return lhs;
}

/// andExpr : eqExpr ('&' eqExpr)*
fn andExpr(p: *Parser) Error!Result {
    var lhs = try p.eqExpr();
    while (p.eatToken(.ampersand)) {
        const rhs = try p.eqExpr();

        if (p.want_const or (lhs != .node and rhs != .node)) {
            return p.todo("and constExpr");
        } else return p.todo("ast");
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
            return p.todo("equality constExpr");
        }
        return p.todo("ast");
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
            return p.todo("comp constExpr");
        }
        return p.todo("ast");
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
            return p.todo("shift constExpr");
        }
        return p.todo("ast");
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
            return p.todo("shift constExpr");
        }
        return p.todo("ast");
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
            return p.todo("mul constExpr");
        }
        return p.todo("ast");
    }
    return lhs;
}

/// castExpr :  ( '(' typeName ')' )* unExpr
fn castExpr(p: *Parser) Error!Result {
    if (!p.eatToken(.l_paren)) {
        return p.unExpr();
    }
    return p.todo("cast");
}

/// unExpr
///  : primaryExpr suffixExpr*
///  | ('&' | '*' | '+' | '-' | '~' | '!' | '++' | '--') castExpr
///  | keyword_sizeof unExpr
///  | keyword_sizeof '(' typeName ')'
///  | keyword_alignof '(' typeName ')'
fn unExpr(p: *Parser) Error!Result {
    switch (p.tokens[p.tok_i].id) {
        .ampersand => return p.todo("unExpr ampersand"),
        .asterisk => return p.todo("unExpr asterisk"),
        .plus => return p.todo("unExpr plus"),
        .minus => return p.todo("unExpr minus"),
        .plus_plus => return p.todo("unary inc"),
        .minus_minus => return p.todo("unary dec"),
        .tilde => return p.todo("unExpr tilde"),
        .bang => {
            p.tok_i += 1;
            const lhs = try p.unExpr();
            if (p.want_const or lhs != .node) {
                return Result{ .bool = !lhs.getBool() };
            }
            return p.todo("ast");
        },
        .keyword_sizeof => return p.todo("unExpr sizeof"),
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
        .l_bracket => return p.todo("array access"),
        .l_paren => return p.todo("call"),
        .period => return p.todo("member access"),
        .arrow => return p.todo("member access pointer"),
        .plus_plus => return p.todo("post inc"),
        .minus_minus => return p.todo("post dec"),
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
            return p.todo("ast");
        },
        .string_literal,
        .string_literal_utf_16,
        .string_literal_utf_8,
        .string_literal_utf_32,
        .string_literal_wide,
        => {
            if (p.want_const) {
                try p.err(.expected_integer_constant_expr);
                return error.ParsingFailed;
            }
            return p.todo("ast");
        },
        .char_literal,
        .char_literal_utf_16,
        .char_literal_utf_32,
        .char_literal_wide,
        => {
            if (p.want_const) {
                return p.todo("char literals");
            }
            return p.todo("ast");
        },
        .float_literal,
        .float_literal_f,
        .float_literal_l,
        => {
            if (p.want_const) {
                try p.err(.expected_integer_constant_expr);
                return error.ParsingFailed;
            }
            return p.todo("ast");
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
                return p.todo("integer literals");
            }
            return p.todo("ast");
        },
        .keyword_generic => {
            return p.todo("generic");
        },
        else => {
            try p.err(.expected_expr);
            return error.ParsingFailed;
        },
    }
}
