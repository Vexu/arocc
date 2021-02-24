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
in_function: bool = false,

fn eatToken(p: *Parser, id: Token.Id) ?Token {
    const tok = p.tokens[p.tok_i];
    if (tok.id == id) {
        p.tok_i += 1;
        return tok;
    } else return null;
}

fn expectToken(p: *Parser, id: Token.Id) Error!Token {
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
    return tok;
}

fn expectClosing(p: *Parser, opening: Token, id: Token.Id) Error!void {
    _ = p.expectToken(id) catch |e| {
        if (e == error.ParsingFailed) {
            try p.pp.comp.diag.add(.{
                .tag = switch (id) {
                    .r_paren => .to_match_paren,
                    .r_brace => .to_match_brace,
                    .r_bracket => .to_match_brace,
                    else => unreachable,
                },
                .source_id = opening.source,
                .loc_start = opening.loc.start,
            });
        }
        return e;
    };
}

fn err(p: *Parser, tag: Diagnostics.Tag) Compilation.Error!void {
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

/// root : (decl | staticAssert)*
pub fn parse(p: *Parser) Compilation.Error!void {
    while (p.eatToken(.eof) == null) {
        if (p.staticAssert() catch |er| switch (er) {
            error.ParsingFailed => {
                p.nextExternDecl();
                continue;
            },
            else => |e| return e,
        }) continue;
        if (p.decl() catch |er| switch (er) {
            error.ParsingFailed => {
                p.nextExternDecl();
                continue;
            },
            else => |e| return e,
        }) continue;

        try p.err(.expected_external_decl);
        p.tok_i += 1;
    }
}

fn nextExternDecl(p: *Parser) void {
    var parens: u32 = 0;
    while (p.tok_i < p.tokens.len) : (p.tok_i += 1) {
        switch (p.tokens[p.tok_i].id) {
            .l_paren, .l_brace, .l_bracket => parens += 1,
            .r_paren, .r_brace, .r_bracket => if (parens != 0) {
                parens -= 1;
            },
            .keyword_typedef,
            .keyword_extern,
            .keyword_static,
            .keyword_auto,
            .keyword_register,
            .keyword_thread_local,
            .keyword_inline,
            .keyword_noreturn,
            .keyword_void,
            .keyword_bool,
            .keyword_char,
            .keyword_short,
            .keyword_int,
            .keyword_long,
            .keyword_signed,
            .keyword_unsigned,
            .keyword_float,
            .keyword_double,
            .keyword_complex,
            .keyword_atomic,
            .keyword_enum,
            .keyword_struct,
            .keyword_union,
            .keyword_alignas,
            .identifier,
            => if (parens == 0) return,
            else => {},
        }
    }
    p.tok_i -= 1; // so that we can consume the eof token elsewhere
}

// ====== declarations ======

/// decl
///  : declSpec (initDeclarator ( ',' initDeclarator)*)? ';'
///  | declSpec declarator declarator* compoundStmt
fn decl(p: *Parser) Error!bool {
    const first_tok = p.tokens[p.tok_i];
    const decl_spec_raw = try p.declSpec();
    if (decl_spec_raw == null) {
        if (p.in_function) return false;
        switch (first_tok.id) {
            .asterisk, .l_paren, .identifier => {},
            else => return false,
        }
    }
    const decl_spec = decl_spec_raw orelse  blk: {
        var d = DeclSpec{};
        try p.defaultTypeSpec(&d.type);
        break :blk d;
    };
    const first = (try p.initDeclarator(decl_spec.type)) orelse {
        // TODO return if enum struct or union
        try p.pp.comp.diag.add(.{
            .tag = .missing_declaration,
            .source_id = first_tok.source,
            .loc_start = first_tok.loc.start,
        });
        _ = try p.expectToken(.semicolon);
        return true;
    };

    // Check for function definition.
    if (first.d.ty.specifier == .function and first.initializer == null and
        (p.tokens[p.tok_i].id == .l_brace or first.k_r_function))
    {
        if (!p.in_function) {
            try p.err(.func_not_in_root);
        }
        const in_function = p.in_function;
        p.in_function = true;
        defer p.in_function = in_function;

        const body = try p.compoundStmt();
        // TODO
        return true;
    }

    while (p.eatToken(.comma)) |_| {
        _ = (try p.initDeclarator(decl_spec.type)) orelse {
            try p.err(.expected_ident_or_l_paren);
        };
    }
    _ = try p.expectToken(.semicolon);
    return true;
}

/// staticAssert : keyword_static_assert '(' constExpr ',' STRING_LITERAL ')' ';'
fn staticAssert(p: *Parser) Error!bool {
    const static_assert = p.tokens[p.tok_i];
    if (p.eatToken(.keyword_static_assert) == null) return false;
    const l_paren = try p.expectToken(.l_paren);
    const start = p.tok_i;
    const res = try p.constExpr();
    const end = p.tok_i;
    _ = try p.expectToken(.comma);
    const str = try p.expectToken(.string_literal); // TODO resolve string literal
    try p.expectClosing(l_paren, .r_paren);

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

const InitDeclarator = struct { d: Declarator, initializer: ?TagIndex, k_r_function: bool = false };

/// initDeclarator : declarator ('=' initializer)?
fn initDeclarator(p: *Parser, base_type: Type) Error!?InitDeclarator {
    // var res: InitDeclarator
    const d = (try p.declarator(base_type)) orelse return null;
    if (p.eatToken(.equal)) |_| {
        return p.todo("initializer");
    }
    return InitDeclarator{ .d = d, .initializer = null };
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
                const l_paren = try p.expectToken(.l_paren);
                const other_type = try p.typeName();
                try p.expectClosing(l_paren, .r_paren);
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

const Declarator = struct { name: []const u8, ty: Type };

/// declarator : pointer? (IDENTIFIER | '(' declarator ')') directDeclarator*
fn declarator(p: *Parser, base_type: Type) Error!?Declarator {
    var ty = base_type;
    const saw_ptr = try p.pointer(&ty);

    if (p.eatToken(.identifier)) |some| {
        const name = p.pp.tokSlice(some);
        try p.directDeclarator(&ty, false);
        return Declarator{ .name = name, .ty = ty };
    } else if (p.eatToken(.l_paren)) |l_paren| {
        const res = try p.declarator(ty);
        try p.expectClosing(l_paren, .r_paren);
        var unwrapped = res orelse return null;
        try p.directDeclarator(&unwrapped.ty, false);
        return unwrapped;
    }

    if (!saw_ptr) {
        return null;
    } else {
        try p.err(.expected_ident_or_l_paren);
        return null;
    }
}

/// directDeclarator
///  : '[' typeQual* assignExpr? ']'
///  | '[' keyword_static typeQual* assignExpr ']'
///  | '[' typeQual+ keyword_static assignExpr ']'
///  | '[' typeQual* '*' ']'
///  | '(' paramDecls ')'
///  | '(' (IDENTIFIER (',' IDENTIFIER))? ')'
/// directAbstractDeclarator
///  : '[' typeQual* assignExpr? ']'
///  | '[' keyword_static typeQual* assignExpr ']'
///  | '[' typeQual+ keyword_static assignExpr ']'
///  | '[' '*' ']'
///  | '(' paramDecls? ')'
fn directDeclarator(p: *Parser, ty: *Type, is_abstract: bool) Error!void {
    while (true) {
        if (p.eatToken(.l_bracket)) |l_bracket| {
            return p.todo("array type");
        } else if (p.eatToken(.l_paren)) |l_paren| {
            return p.todo("function type");
        } else return;
    }
}

/// pointer : '*' typeQual* pointer?
fn pointer(p: *Parser, ty: *Type) Error!bool {
    if (p.eatToken(.asterisk) == null) return false;
    return p.todo("pointer");
}

/// paramDecls : paramDecl (',' paramDecl)* (',' '...')
/// paramDecl : declSpec (declarator | abstractDeclarator)
fn paramDecls(p: *Parser) Error!TagIndex {
    return p.todo("paramDecls");
}

/// typeName : specQual abstractDeclarator
fn typeName(p: *Parser) Error!Type {
    const ty = try p.specQual();
    return p.todo("typeName");
}

/// abstractDeclarator
/// : pointer? ('(' abstractDeclarator ')')? directAbstractDeclarator*
fn abstractDeclarator(p: *Parser) Error!TagIndex {
    return p.todo("abstractDeclarator");
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

/// compoundStmt : '{' ( decl| staticAssert | stmt)* '}'
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
    if (p.eatToken(.question_mark) == null) return cond;
    const then_expr = try p.expr();
    _ = try p.expectToken(.colon);
    const else_expr = try p.condExpr();

    if (p.want_const or cond != .node) {
        return if (cond.getBool()) then_expr else else_expr;
    }
    return p.todo("ast");
}

/// lorExpr : landExpr ('||' landExpr)*
fn lorExpr(p: *Parser) Error!Result {
    var lhs = try p.landExpr();
    while (p.eatToken(.pipe_pipe)) |_| {
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
    while (p.eatToken(.ampersand_ampersand)) |_| {
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
    while (p.eatToken(.pipe)) |_| {
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
    while (p.eatToken(.caret)) |_| {
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
    while (p.eatToken(.ampersand)) |_| {
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
        const ne = eq orelse p.eatToken(.bang_equal);
        if (ne == null) break;
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
        const le = lt orelse p.eatToken(.angle_bracket_left_equal);
        const gt = le orelse p.eatToken(.angle_bracket_right);
        const ge = gt orelse p.eatToken(.angle_bracket_right_equal);
        if (ge == null) break;
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
        const shr = shl orelse p.eatToken(.angle_bracket_angle_bracket_right);
        if (shr == null) break;
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
        const minus = plus orelse p.eatToken(.minus);
        if (minus == null) break;
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
        const div = mul orelse p.eatToken(.slash);
        const percent = div orelse p.eatToken(.percent);
        if (percent == null) break;
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
    while (p.eatToken(.l_paren)) |l_paren| {
        const ty = try p.typeName();
        try p.expectClosing(l_paren, .r_paren);
        return p.todo("cast");
    }
    return p.unExpr();
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
    if (p.eatToken(.l_paren)) |l_paren| {
        const e = try p.expr();
        try p.expectClosing(l_paren, .r_paren);
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
