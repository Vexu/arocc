const std = @import("std");
const mem = std.mem;
const Allocator = mem.Allocator;
const assert = std.debug.assert;
const Compilation = @import("Compilation.zig");
const Source = @import("Source.zig");
const Tokenizer = @import("Tokenizer.zig");
const Preprocessor = @import("Preprocessor.zig");
const Tree = @import("Tree.zig");
const Token = Tree.Token;
const TokenIndex = Tree.TokenIndex;
const NodeIndex = Tree.NodeIndex;
const Type = @import("Type.zig");
const Diagnostics = @import("Diagnostics.zig");
const NodeList = std.ArrayList(NodeIndex);

const Parser = @This();

const Scope = union(enum) {
    typedef: Symbol,
    @"struct": Symbol,
    @"union": Symbol,
    @"enum": Symbol,
    symbol: Symbol,
    enumeration: Enumeration,
    loop,
    @"switch": *Switch,

    const Symbol = struct {
        name: []const u8,
        ty: Type,
        name_tok: TokenIndex,
    };

    const Enumeration = struct {
        name: []const u8,
        value: Result,
    };

    const Switch = struct {
        cases: CaseMap,
        default: ?Case = null,

        const ResultContext = struct {
            pub fn eql(_: ResultContext, a: Result, b: Result) bool {
                return a.eql(b);
            }
            pub fn hash(_: ResultContext, a: Result) u64 {
                return a.hash();
            }
        };
        const CaseMap = std.HashMap(Result, Case, ResultContext, std.hash_map.default_max_load_percentage);
        const Case = struct {
            node: NodeIndex,
            tok: TokenIndex,
        };
    };
};

const Label = union(enum) {
    unresolved_goto: TokenIndex,
    label: TokenIndex,
};

pub const Error = Compilation.Error || error{ParsingFailed};

pp: *Preprocessor,
arena: *Allocator,
nodes: Tree.Node.List = .{},
data: NodeList,
scopes: std.ArrayList(Scope),
tok_ids: []const Token.Id,
tok_i: TokenIndex = 0,
no_eval: bool = false,
in_macro: bool = false,
in_function: bool = false,
cur_decl_list: *NodeList,
labels: std.ArrayList(Label),
label_count: u32 = 0,
strings: std.ArrayList(u8),
value_map: Tree.ValueMap,

fn eatToken(p: *Parser, id: Token.Id) ?TokenIndex {
    if (p.tok_ids[p.tok_i] == id) {
        defer p.tok_i += 1;
        return p.tok_i;
    } else return null;
}

fn expectToken(p: *Parser, expected: Token.Id) Error!TokenIndex {
    const actual = p.tok_ids[p.tok_i];
    if (actual != expected) {
        try p.errExtra(
            switch (actual) {
                .invalid => .expected_invalid,
                else => .expected_token,
            },
            p.tok_i,
            .{ .tok_id = .{
                .expected = expected,
                .actual = actual,
            } },
        );
        return error.ParsingFailed;
    }
    defer p.tok_i += 1;
    return p.tok_i;
}

fn tokSlice(p: *Parser, tok: TokenIndex) []const u8 {
    if (p.tok_ids[tok].lexeme()) |some| return some;
    const loc = p.pp.tokens.items(.loc)[tok];
    var tmp_tokenizer = Tokenizer{
        .buf = if (loc.id == .generated)
            p.pp.generated.items
        else
            p.pp.comp.getSource(loc.id).buf,
        .index = loc.byte_offset,
        .source = .generated,
    };
    const res = tmp_tokenizer.next();
    return tmp_tokenizer.buf[res.start..res.end];
}

fn expectClosing(p: *Parser, opening: TokenIndex, id: Token.Id) Error!void {
    _ = p.expectToken(id) catch |e| {
        if (e == error.ParsingFailed) {
            try p.pp.comp.diag.add(.{
                .tag = switch (id) {
                    .r_paren => .to_match_paren,
                    .r_brace => .to_match_brace,
                    .r_bracket => .to_match_brace,
                    else => unreachable,
                },
                .loc = p.pp.tokens.items(.loc)[opening],
            });
        }
        return e;
    };
}

pub fn errStr(p: *Parser, tag: Diagnostics.Tag, tok_i: TokenIndex, str: []const u8) Compilation.Error!void {
    @setCold(true);
    return p.errExtra(tag, tok_i, .{ .str = str });
}

pub fn errExtra(p: *Parser, tag: Diagnostics.Tag, tok_i: TokenIndex, extra: Diagnostics.Message.Extra) Compilation.Error!void {
    @setCold(true);
    try p.pp.comp.diag.add(.{
        .tag = tag,
        .loc = p.pp.tokens.items(.loc)[tok_i],
        .extra = extra,
    });
}

pub fn errTok(p: *Parser, tag: Diagnostics.Tag, tok_i: TokenIndex) Compilation.Error!void {
    @setCold(true);
    try p.pp.comp.diag.add(.{
        .tag = tag,
        .loc = p.pp.tokens.items(.loc)[tok_i],
    });
}

pub fn err(p: *Parser, tag: Diagnostics.Tag) Compilation.Error!void {
    @setCold(true);
    return p.errTok(tag, p.tok_i);
}

pub fn todo(p: *Parser, msg: []const u8) Error {
    try p.errStr(.todo, p.tok_i, msg);
    return error.ParsingFailed;
}

fn addNode(p: *Parser, node: Tree.Node) Allocator.Error!NodeIndex {
    if (p.in_macro) return .none;
    const res = p.nodes.len;
    try p.nodes.append(p.pp.comp.gpa, node);
    return @intToEnum(NodeIndex, @intCast(u32, res));
}

fn addList(p: *Parser, nodes: []const NodeIndex) Allocator.Error!Tree.Node.Range {
    const start = @intCast(u32, p.data.items.len);
    try p.data.appendSlice(nodes);
    const end = @intCast(u32, p.data.items.len);
    return Tree.Node.Range{ .start = start, .end = end };
}

fn findTypedef(p: *Parser, name: []const u8) ?Scope.Symbol {
    var i = p.scopes.items.len;
    while (i > 0) {
        i -= 1;
        switch (p.scopes.items[i]) {
            .typedef => |t| if (mem.eql(u8, t.name, name)) return t,
            else => {},
        }
    }
    return null;
}

fn findSymbol(p: *Parser, name_tok: TokenIndex) ?Scope {
    const name = p.tokSlice(name_tok);
    var i = p.scopes.items.len;
    while (i > 0) {
        i -= 1;
        const sym = p.scopes.items[i];
        switch (sym) {
            .symbol => |s| if (mem.eql(u8, s.name, name)) return sym,
            .enumeration => |e| if (mem.eql(u8, e.name, name)) return sym,
            else => {},
        }
    }
    return null;
}

fn findTag(p: *Parser, kind: Token.Id, name_tok: TokenIndex) !?Scope.Symbol {
    const name = p.tokSlice(name_tok);
    var i = p.scopes.items.len;
    while (i > 0) {
        i -= 1;
        const sym = p.scopes.items[i];
        switch (sym) {
            .@"enum" => |e| if (mem.eql(u8, e.name, name)) {
                if (kind == .keyword_enum) return e;
                try p.errStr(.wrong_tag, name_tok, name);
                try p.errTok(.previous_definition, e.name_tok);
                return null;
            },
            .@"struct" => |s| if (mem.eql(u8, s.name, name)) {
                if (kind == .keyword_struct) return s;
                try p.errStr(.wrong_tag, name_tok, name);
                try p.errTok(.previous_definition, s.name_tok);
                return null;
            },
            .@"union" => |u| if (mem.eql(u8, u.name, name)) {
                if (kind == .keyword_union) return u;
                try p.errStr(.wrong_tag, name_tok, name);
                try p.errTok(.previous_definition, u.name_tok);
                return null;
            },
            else => {},
        }
    }
    return null;
}

fn inLoop(p: *Parser) bool {
    var i = p.scopes.items.len;
    while (i > 0) {
        i -= 1;
        switch (p.scopes.items[i]) {
            .loop => return true,
            else => {},
        }
    }
    return false;
}

fn inLoopOrSwitch(p: *Parser) bool {
    var i = p.scopes.items.len;
    while (i > 0) {
        i -= 1;
        switch (p.scopes.items[i]) {
            .loop, .@"switch" => return true,
            else => {},
        }
    }
    return false;
}

fn findLabel(p: *Parser, name: []const u8) ?TokenIndex {
    for (p.labels.items) |item| {
        switch (item) {
            .label => |l| if (mem.eql(u8, p.tokSlice(l), name)) return l,
            .unresolved_goto => {},
        }
    }
    return null;
}

fn findSwitch(p: *Parser) ?*Scope.Switch {
    var i = p.scopes.items.len;
    while (i > 0) {
        i -= 1;
        switch (p.scopes.items[i]) {
            .@"switch" => |s| return s,
            else => {},
        }
    }
    return null;
}

/// root : (decl | staticAssert)*
pub fn parse(pp: *Preprocessor) Compilation.Error!Tree {
    var root_decls = NodeList.init(pp.comp.gpa);
    defer root_decls.deinit();
    var arena = std.heap.ArenaAllocator.init(pp.comp.gpa);
    errdefer arena.deinit();
    var p = Parser{
        .pp = pp,
        .arena = &arena.allocator,
        .tok_ids = pp.tokens.items(.id),
        .cur_decl_list = &root_decls,
        .scopes = std.ArrayList(Scope).init(pp.comp.gpa),
        .data = NodeList.init(pp.comp.gpa),
        .labels = std.ArrayList(Label).init(pp.comp.gpa),
        .strings = std.ArrayList(u8).init(pp.comp.gpa),
        .value_map = Tree.ValueMap.init(pp.comp.gpa),
    };
    defer p.scopes.deinit();
    defer p.data.deinit();
    defer p.labels.deinit();
    errdefer p.nodes.deinit(pp.comp.gpa);
    errdefer p.strings.deinit();
    errdefer p.value_map.deinit();

    // NodeIndex 0 must be invalid
    _ = try p.addNode(.{ .tag = .invalid, .ty = undefined, .data = undefined });

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
    return Tree{
        .comp = pp.comp,
        .tokens = pp.tokens.slice(),
        .arena = arena,
        .generated = pp.generated.items,
        .nodes = p.nodes.toOwnedSlice(),
        .data = p.data.toOwnedSlice(),
        .root_decls = root_decls.toOwnedSlice(),
        .strings = p.strings.toOwnedSlice(),
        .value_map = p.value_map,
    };
}

fn nextExternDecl(p: *Parser) void {
    var parens: u32 = 0;
    while (p.tok_i < p.tok_ids.len) : (p.tok_i += 1) {
        switch (p.tok_ids[p.tok_i]) {
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
///  | declSpec declarator decl* compoundStmt
fn decl(p: *Parser) Error!bool {
    const first_tok = p.tok_i;
    var decl_spec = if (try p.declSpec()) |some|
        some
    else blk: {
        if (p.in_function) return false;
        switch (p.tok_ids[first_tok]) {
            .asterisk, .l_paren, .identifier => {},
            else => return false,
        }
        var d: DeclSpec = .{};
        var spec: Type.Builder = .{};
        try spec.finish(p, &d.ty);
        break :blk d;
    };
    var init_d = (try p.initDeclarator(&decl_spec)) orelse {
        _ = try p.expectToken(.semicolon);
        if (decl_spec.ty.specifier == .@"enum") return true;
        if (decl_spec.ty.isEnumOrRecord()) {
            // TODO check that there was a name token
            return true;
        }
        try p.errTok(.missing_declaration, first_tok);
        return true;
    };

    // Check for function definition.
    if (init_d.d.func_declarator != null and init_d.initializer == .none and init_d.d.ty.isFunc()) fn_def: {
        switch (p.tok_ids[p.tok_i]) {
            .comma, .semicolon => break :fn_def,
            .l_brace => {},
            else => if (init_d.d.old_style_func == null) {
                try p.err(.expected_fn_body);
                break :fn_def;
            },
        }

        // Collect old style parameter declarations.
        if (init_d.d.old_style_func != null and !p.in_function) {
            init_d.d.ty.specifier = .func;
            param_loop: while (true) {
                const param_decl_spec = (try p.declSpec()) orelse break;
                if (p.eatToken(.semicolon)) |semi| {
                    try p.errTok(.missing_declaration, semi);
                    continue :param_loop;
                }

                while (true) {
                    var d = (try p.declarator(param_decl_spec.ty, .normal)) orelse {
                        try p.errTok(.missing_declaration, first_tok);
                        _ = try p.expectToken(.semicolon);
                        continue :param_loop;
                    };

                    if (d.ty.isFunc()) {
                        // Params declared as functions are converted to function pointers.
                        const elem_ty = try p.arena.create(Type);
                        elem_ty.* = d.ty;
                        d.ty = Type{
                            .specifier = .pointer,
                            .data = .{ .sub_type = elem_ty },
                        };
                    } else if (d.ty.specifier == .void) {
                        try p.errTok(.invalid_void_param, d.name);
                    }

                    // find and correct parameter types
                    // TODO check for missing declarations and redefinitions
                    const name_str = p.tokSlice(d.name);
                    for (init_d.d.ty.data.func.params) |*param| {
                        if (mem.eql(u8, param.name, name_str)) {
                            param.ty = d.ty;
                            break;
                        }
                    } else {
                        try p.errStr(.parameter_missing, d.name, name_str);
                    }

                    // TODO declare and check that d.name is in init_d.d.ty.data.func.params
                    if (p.eatToken(.comma) == null) break;
                }
                _ = try p.expectToken(.semicolon);
            }
        }

        for (init_d.d.ty.data.func.params) |param| {
            try p.scopes.append(.{
                .symbol = .{
                    .name = param.name,
                    .ty = param.ty,
                    .name_tok = 0, // TODO split Scope.Symbol into Scope.Typedef
                },
            });
        }

        if (p.in_function) try p.err(.func_not_in_root);

        const in_function = p.in_function;
        p.in_function = true;
        defer p.in_function = in_function;

        const node = try p.addNode(.{
            .ty = init_d.d.ty,
            .tag = try decl_spec.validateFnDef(p),
            .data = .{ .decl = .{ .name = init_d.d.name } },
        });
        try p.scopes.append(.{ .symbol = .{
            .name = p.tokSlice(init_d.d.name),
            .ty = init_d.d.ty,
            .name_tok = init_d.d.name,
        } });
        const body = try p.compoundStmt();
        p.nodes.items(.data)[@enumToInt(node)].decl.node = body.?;

        // check gotos
        if (!in_function) {
            for (p.labels.items) |item| {
                if (item == .unresolved_goto)
                    try p.errStr(.undeclared_label, item.unresolved_goto, p.tokSlice(item.unresolved_goto));
            }
            p.labels.items.len = 0;
            p.label_count = 0;
        }

        try p.cur_decl_list.append(node);
        return true;
    }

    // Declare all variable/typedef declarators.
    while (true) {
        if (init_d.d.old_style_func) |tok_i| try p.errTok(.invalid_old_style_params, tok_i);
        const node = try p.addNode(.{
            .ty = init_d.d.ty,
            .tag = try decl_spec.validate(p, init_d.d.ty, init_d.initializer != .none),
            .data = .{ .decl = .{ .name = init_d.d.name, .node = init_d.initializer } },
        });
        try p.cur_decl_list.append(node);
        if (decl_spec.storage_class == .typedef) {
            try p.scopes.append(.{ .typedef = .{
                .name = p.tokSlice(init_d.d.name),
                .ty = init_d.d.ty,
                .name_tok = init_d.d.name,
            } });
        } else {
            try p.scopes.append(.{ .symbol = .{
                .name = p.tokSlice(init_d.d.name),
                .ty = init_d.d.ty,
                .name_tok = init_d.d.name,
            } });
        }

        if (p.eatToken(.comma) == null) break;

        init_d = (try p.initDeclarator(&decl_spec)) orelse {
            try p.err(.expected_ident_or_l_paren);
            continue;
        };
    }
    _ = try p.expectToken(.semicolon);
    return true;
}

/// staticAssert : keyword_static_assert '(' constExpr ',' STRING_LITERAL ')' ';'
fn staticAssert(p: *Parser) Error!bool {
    const static_assert = p.eatToken(.keyword_static_assert) orelse return false;
    const l_paren = try p.expectToken(.l_paren);
    const res = try p.constExpr();
    _ = try p.expectToken(.comma);
    const str = switch (p.tok_ids[p.tok_i]) {
        .string_literal,
        .string_literal_utf_16,
        .string_literal_utf_8,
        .string_literal_utf_32,
        .string_literal_wide,
        => try p.stringLiteral(),
        else => {
            try p.err(.expected_str_literal);
            return error.ParsingFailed;
        },
    };
    try p.expectClosing(l_paren, .r_paren);
    _ = try p.expectToken(.semicolon);

    if (!res.getBool()) {
        var msg = std.ArrayList(u8).init(p.pp.comp.gpa);
        defer msg.deinit();

        const data = p.nodes.items(.data)[@enumToInt(str.node)].str;
        try Tree.dumpStr(
            p.strings.items[data.index..][0..data.len],
            p.nodes.items(.tag)[@enumToInt(str.node)],
            msg.writer(),
        );

        try p.errStr(.static_assert_failure, static_assert, try p.arena.dupe(u8, msg.items));
    }
    const node = try p.addNode(.{
        .tag = .static_assert,
        .data = .{ .bin = .{
            .lhs = res.node,
            .rhs = str.node,
        } },
    });
    try p.cur_decl_list.append(node);
    return true;
}

pub const DeclSpec = struct {
    storage_class: union(enum) {
        auto: TokenIndex,
        @"extern": TokenIndex,
        register: TokenIndex,
        static: TokenIndex,
        typedef: TokenIndex,
        none,
    } = .none,
    thread_local: ?TokenIndex = null,
    @"inline": ?TokenIndex = null,
    @"noreturn": ?TokenIndex = null,
    ty: Type = .{ .specifier = undefined },

    fn validateParam(d: DeclSpec, p: *Parser, ty: Type) Error!void {
        _ = ty;
        switch (d.storage_class) {
            .none, .register => {},
            .auto, .@"extern", .static, .typedef => |tok_i| try p.errTok(.invalid_storage_on_param, tok_i),
        }
        if (d.thread_local) |tok_i| try p.errTok(.threadlocal_non_var, tok_i);
        if (d.@"inline") |tok_i| try p.errStr(.func_spec_non_func, tok_i, "inline");
        if (d.@"noreturn") |tok_i| try p.errStr(.func_spec_non_func, tok_i, "_Noreturn");
    }

    fn validateFnDef(d: DeclSpec, p: *Parser) Error!Tree.Tag {
        switch (d.storage_class) {
            .none, .@"extern", .static => {},
            .auto, .register, .typedef => |tok_i| try p.errTok(.illegal_storage_on_func, tok_i),
        }
        if (d.thread_local) |tok_i| try p.errTok(.threadlocal_non_var, tok_i);

        const is_static = d.storage_class == .static;
        const is_inline = d.@"inline" != null;
        const is_noreturn = d.@"noreturn" != null;
        if (is_static) {
            if (is_inline and is_noreturn) return .noreturn_inline_static_fn_def;
            if (is_inline) return .inline_static_fn_def;
            if (is_noreturn) return .noreturn_static_fn_def;
            return .static_fn_def;
        } else {
            if (is_inline and is_noreturn) return .noreturn_inline_fn_def;
            if (is_inline) return .inline_fn_def;
            if (is_noreturn) return .noreturn_fn_def;
            return .fn_def;
        }
    }

    fn validate(d: DeclSpec, p: *Parser, ty: Type, has_init: bool) Error!Tree.Tag {
        const is_static = d.storage_class == .static;
        if (ty.isFunc() and d.storage_class != .typedef) {
            switch (d.storage_class) {
                .none, .@"extern" => {},
                .static => |tok_i| if (p.in_function) try p.errTok(.static_func_not_global, tok_i),
                .typedef => unreachable,
                .auto, .register => |tok_i| try p.errTok(.illegal_storage_on_func, tok_i),
            }
            if (d.thread_local) |tok_i| try p.errTok(.threadlocal_non_var, tok_i);

            const is_inline = d.@"inline" != null;
            const is_noreturn = d.@"noreturn" != null;
            if (is_static) {
                if (is_inline and is_noreturn) return .noreturn_inline_static_fn_proto;
                if (is_inline) return .inline_static_fn_proto;
                if (is_noreturn) return .noreturn_static_fn_proto;
                return .static_fn_proto;
            } else {
                if (is_inline and is_noreturn) return .noreturn_inline_fn_proto;
                if (is_inline) return .inline_fn_proto;
                if (is_noreturn) return .noreturn_fn_proto;
                return .fn_proto;
            }
        } else {
            if (d.@"inline") |tok_i| try p.errStr(.func_spec_non_func, tok_i, "inline");
            if (d.@"noreturn") |tok_i| try p.errStr(.func_spec_non_func, tok_i, "_Noreturn");
            switch (d.storage_class) {
                .auto, .register => if (!p.in_function) try p.err(.illegal_storage_on_global),
                .typedef => return .typedef,
                else => {},
            }

            const is_extern = d.storage_class == .@"extern" and !has_init;
            if (d.thread_local != null) {
                if (is_static) return .threadlocal_static_var;
                if (is_extern) return .threadlocal_extern_var;
                return .threadlocal_var;
            } else {
                if (is_static) return .static_var;
                if (is_extern) return .extern_var;
                return .@"var";
            }
        }
    }
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
    var d: DeclSpec = .{};
    var spec: Type.Builder = .{};

    const start = p.tok_i;
    while (true) {
        if (try p.typeSpec(&spec, &d.ty)) continue;
        const id = p.tok_ids[p.tok_i];
        switch (id) {
            .keyword_typedef,
            .keyword_extern,
            .keyword_static,
            .keyword_auto,
            .keyword_register,
            => {
                if (d.storage_class != .none) {
                    try p.errStr(.multiple_storage_class, p.tok_i, @tagName(d.storage_class));
                    return error.ParsingFailed;
                }
                if (d.thread_local != null) {
                    switch (id) {
                        .keyword_typedef,
                        .keyword_auto,
                        .keyword_register,
                        => try p.errStr(.cannot_combine_spec, p.tok_i, id.lexeme().?),
                        else => {},
                    }
                }
                switch (id) {
                    .keyword_typedef => d.storage_class = .{ .typedef = p.tok_i },
                    .keyword_extern => d.storage_class = .{ .@"extern" = p.tok_i },
                    .keyword_static => d.storage_class = .{ .static = p.tok_i },
                    .keyword_auto => d.storage_class = .{ .auto = p.tok_i },
                    .keyword_register => d.storage_class = .{ .register = p.tok_i },
                    else => unreachable,
                }
            },
            .keyword_thread_local => {
                if (d.thread_local != null) {
                    try p.errStr(.duplicate_decl_spec, p.tok_i, "_Thread_local");
                }
                switch (d.storage_class) {
                    .@"extern", .none, .static => {},
                    else => try p.errStr(.cannot_combine_spec, p.tok_i, @tagName(d.storage_class)),
                }
                d.thread_local = p.tok_i;
            },
            .keyword_inline => {
                if (d.@"inline" != null) {
                    try p.errStr(.duplicate_decl_spec, p.tok_i, "inline");
                }
                d.@"inline" = p.tok_i;
            },
            .keyword_noreturn => {
                if (d.@"noreturn" != p.tok_i) {
                    try p.errStr(.duplicate_decl_spec, p.tok_i, "_Noreturn");
                }
                d.@"noreturn" = null;
            },
            else => break,
        }
        p.tok_i += 1;
    }

    if (p.tok_i == start) return null;
    try spec.finish(p, &d.ty);
    return d;
}

const InitDeclarator = struct { d: Declarator, initializer: NodeIndex = .none };

/// initDeclarator : declarator ('=' initializer)?
fn initDeclarator(p: *Parser, decl_spec: *DeclSpec) Error!?InitDeclarator {
    var init_d = InitDeclarator{
        .d = (try p.declarator(decl_spec.ty, .normal)) orelse return null,
    };
    if (p.eatToken(.equal)) |_| {
        if (decl_spec.storage_class == .typedef or
            decl_spec.ty.isFunc()) try p.err(.illegal_initializer);
        if (decl_spec.storage_class == .@"extern") {
            try p.err(.extern_initializer);
            decl_spec.storage_class = .none;
        }
        const init = try p.initializer(decl_spec.ty);
        try init.expect(p);
        const casted = try init.coerce(p, init_d.d.ty);
        init_d.initializer = casted.node;
    }
    return init_d;
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
/// alignSpec
///   : keyword_alignas '(' typeName ')'
///   | keyword_alignas '(' constExpr ')'
fn typeSpec(p: *Parser, ty: *Type.Builder, complete_type: *Type) Error!bool {
    const start = p.tok_i;
    while (true) {
        if (try p.typeQual(complete_type)) continue;
        switch (p.tok_ids[p.tok_i]) {
            .keyword_void => try ty.combine(p, .void),
            .keyword_bool => try ty.combine(p, .bool),
            .keyword_char => try ty.combine(p, .char),
            .keyword_short => try ty.combine(p, .short),
            .keyword_int => try ty.combine(p, .int),
            .keyword_long => try ty.combine(p, .long),
            .keyword_signed => try ty.combine(p, .signed),
            .keyword_unsigned => try ty.combine(p, .unsigned),
            .keyword_float => try ty.combine(p, .float),
            .keyword_double => try ty.combine(p, .double),
            .keyword_complex => try ty.combine(p, .complex),
            .keyword_atomic => {
                const atomic_tok = p.tok_i;
                p.tok_i += 1;
                const l_paren = p.eatToken(.l_paren) orelse {
                    // _Atomic qualifier not _Atomic(typeName)
                    p.tok_i = atomic_tok;
                    break;
                };
                const inner_ty = (try p.typeName()) orelse {
                    try p.err(.expected_type);
                    return error.ParsingFailed;
                };
                try p.expectClosing(l_paren, .r_paren);

                const new_spec = Type.Builder.fromType(inner_ty);

                // combine() uses p.tok_i for error reporting
                const cur = p.tok_i;
                defer p.tok_i = cur;
                p.tok_i = atomic_tok;
                try ty.combine(p, new_spec);

                if (complete_type.qual.atomic)
                    try p.errStr(.duplicate_decl_spec, atomic_tok, "atomic")
                else
                    complete_type.qual.atomic = true;

                // TODO check that the type can be atomic
                continue;
            },
            .keyword_struct => {
                try ty.combine(p, .{ .@"struct" = undefined });
                ty.kind.@"struct" = try p.recordSpec();
                continue;
            },
            .keyword_union => {
                try ty.combine(p, .{ .@"union" = undefined });
                ty.kind.@"union" = try p.recordSpec();
                continue;
            },
            .keyword_enum => {
                try ty.combine(p, .{ .@"enum" = undefined });
                ty.kind.@"enum" = try p.enumSpec();
                continue;
            },
            .identifier => {
                const typedef = p.findTypedef(p.tokSlice(p.tok_i)) orelse break;
                const new_spec = Type.Builder.fromType(typedef.ty);

                const err_start = p.pp.comp.diag.list.items.len;
                ty.combine(p, new_spec) catch {
                    // Remove new error messages
                    // TODO improve/make threadsafe?
                    p.pp.comp.diag.list.items.len = err_start;
                    break;
                };
                ty.typedef = .{
                    .tok = typedef.name_tok,
                    .spec = new_spec.str(),
                };
            },
            .keyword_alignas => {
                if (complete_type.alignment != 0) try p.errStr(.duplicate_decl_spec, p.tok_i, "alignment");
                p.tok_i += 1;
                const l_paren = try p.expectToken(.l_paren);
                if (try p.typeName()) |inner_ty| {
                    complete_type.alignment = inner_ty.alignment;
                } else {
                    const res = try p.constExpr();
                    // TODO more validation here
                    complete_type.alignment = @intCast(u32, res.as_u64());
                }
                try p.expectClosing(l_paren, .r_paren);
                continue;
            },
            else => break,
        }
        p.tok_i += 1;
    }
    return p.tok_i != start;
}

fn getAnonymousName(p: *Parser, kind_tok: TokenIndex) ![]const u8 {
    const loc = p.pp.tokens.items(.loc)[kind_tok];
    const source = p.pp.comp.getSource(loc.id);
    const lcs = source.lineColString(loc.byte_offset);

    const kind_str = switch (p.tok_ids[kind_tok]) {
        .keyword_struct, .keyword_union, .keyword_enum => p.tokSlice(kind_tok),
        else => "record field",
    };

    return std.fmt.allocPrint(
        p.arena,
        "(anonymous {s} at {s}:{d}:{d})",
        .{ kind_str, source.path, lcs.line, lcs.col },
    );
}

/// recordSpec
///  : (keyword_struct | keyword_union) IDENTIFIER? { recordDecl* }
///  | (keyword_struct | keyword_union) IDENTIFIER
fn recordSpec(p: *Parser) Error!*Type.Record {
    const kind_tok = p.tok_i;
    const is_struct = p.tok_ids[kind_tok] == .keyword_struct;
    p.tok_i += 1;
    const maybe_ident = p.eatToken(.identifier);
    const l_brace = p.eatToken(.l_brace) orelse {
        const ident = maybe_ident orelse {
            try p.err(.ident_or_l_brace);
            return error.ParsingFailed;
        };
        // check if this is a referense to a previous type
        if (try p.findTag(p.tok_ids[kind_tok], ident)) |prev| {
            return prev.ty.data.record;
        }
        return p.todo("record forward declaration");
    };
    // check if this is a redefinition
    if (maybe_ident) |ident| {
        if (try p.findTag(p.tok_ids[kind_tok], ident)) |prev| {
            try p.errStr(.redefinition, ident, p.tokSlice(ident));
            try p.errTok(.previous_definition, prev.name_tok);
        }
    }

    // create the type
    const record_ty = try p.arena.create(Type.Record);
    record_ty.* = .{
        .name = if (maybe_ident) |ident| p.tokSlice(ident) else try p.getAnonymousName(kind_tok),
        .size = 0, // TODO calculate
        .alignment = 0, // TODO calculate
        .fields = undefined,
    };
    const ty = Type{
        .specifier = if (is_struct) .@"struct" else .@"union",
        .data = .{ .record = record_ty },
    };

    // declare a symbol for the type
    if (maybe_ident) |ident| {
        const sym = Scope.Symbol{
            .name = record_ty.name,
            .ty = ty,
            .name_tok = ident,
        };
        try p.scopes.append(if (is_struct) .{ .@"struct" = sym } else .{ .@"union" = sym });
    }

    var fields = std.ArrayList(Type.Record.Field).init(p.pp.comp.gpa);
    defer fields.deinit();
    var field_nodes = NodeList.init(p.pp.comp.gpa);
    defer field_nodes.deinit();

    {
        // TODO this is kinda janky, look into using a global scratch buffer
        const saved_decls = p.cur_decl_list;
        defer p.cur_decl_list = saved_decls;
        p.cur_decl_list = &field_nodes;

        try p.recordDecls(&fields);
    }

    if (fields.items.len == 0) try p.errStr(.empty_record, kind_tok, p.tokSlice(kind_tok));

    try p.expectClosing(l_brace, .r_brace);
    record_ty.fields = try p.arena.dupe(Type.Record.Field, fields.items);

    // finish by creating a node
    var node: Tree.Node = .{
        .tag = if (is_struct) .struct_decl_two else .union_decl_two,
        .ty = ty,
        .data = .{ .bin = .{ .lhs = .none, .rhs = .none } },
    };
    switch (field_nodes.items.len) {
        0 => {},
        1 => node.data = .{ .bin = .{ .lhs = field_nodes.items[0], .rhs = .none } },
        2 => node.data = .{ .bin = .{ .lhs = field_nodes.items[0], .rhs = field_nodes.items[1] } },
        else => {
            node.tag = if (is_struct) .struct_decl else .union_decl;
            node.data = .{ .range = try p.addList(field_nodes.items) };
        },
    }
    try p.cur_decl_list.append(try p.addNode(node));
    return record_ty;
}

/// recordDecl
///  : specQual (recordDeclarator (',' recordDeclarator)*)? ;
///  | staticAssert
/// recordDeclarator : declarator (':' constExpr)?
fn recordDecls(p: *Parser, fields: *std.ArrayList(Type.Record.Field)) Error!void {
    while (true) {
        if (try p.staticAssert()) continue;
        const base_ty = (try p.specQual()) orelse return;

        while (true) {
            // 0 means unnamed
            var name_tok: TokenIndex = 0;
            var ty = base_ty;
            var bits_node: NodeIndex = .none;
            var bits: u32 = 0;
            const first_tok = p.tok_i;
            if (try p.declarator(ty, .record)) |d| {
                name_tok = d.name;
                ty = d.ty;
            }
            if (p.eatToken(.colon)) |_| {
                const res = try p.constExpr();
                // TODO check using math.cast
                switch (res.val) {
                    .unsigned => |v| bits = @intCast(u32, v),
                    .signed => |v| bits = @intCast(u32, v),
                    .unavailable => unreachable,
                }
                bits_node = res.node;
            }
            if (name_tok == 0 and bits_node == .none) {
                try p.err(.missing_declaration);
            } else {
                try fields.append(.{
                    .name = if (name_tok != 0) p.tokSlice(name_tok) else try p.getAnonymousName(first_tok),
                    .ty = ty,
                    .bit_width = bits,
                });
                const node = try p.addNode(.{
                    .tag = .record_field_decl,
                    .ty = ty,
                    .data = .{ .decl = .{ .name = name_tok, .node = bits_node } },
                });
                try p.cur_decl_list.append(node);
            }
            if (p.eatToken(.comma) == null) break;
        }
        _ = try p.expectToken(.semicolon);
    }
}

/// specQual : (typeSpec | typeQual | alignSpec)+
fn specQual(p: *Parser) Error!?Type {
    var spec: Type.Builder = .{};
    var ty: Type = .{ .specifier = undefined };
    if (try p.typeSpec(&spec, &ty)) {
        try spec.finish(p, &ty);
        return ty;
    }
    return null;
}

/// enumSpec
///  : keyword_enum IDENTIFIER? { enumerator (',' enumerator)? ',') }
///  | keyword_enum IDENTIFIER
fn enumSpec(p: *Parser) Error!*Type.Enum {
    const enum_tok = p.tok_i;
    p.tok_i += 1;
    const maybe_ident = p.eatToken(.identifier);
    const l_brace = p.eatToken(.l_brace) orelse {
        const ident = maybe_ident orelse {
            try p.err(.ident_or_l_brace);
            return error.ParsingFailed;
        };
        // check if this is a referense to a previous type
        if (try p.findTag(.keyword_enum, ident)) |prev| {
            return prev.ty.data.@"enum";
        }
        return p.todo("enum forward declaration");
    };
    // check if this is a redefinition
    if (maybe_ident) |ident| {
        if (try p.findTag(.keyword_enum, ident)) |prev| {
            try p.errStr(.redefinition, ident, p.tokSlice(ident));
            try p.errTok(.previous_definition, prev.name_tok);
        }
    }

    // create the type
    const enum_ty = try p.arena.create(Type.Enum);
    enum_ty.* = .{
        .name = if (maybe_ident) |ident| p.tokSlice(ident) else try p.getAnonymousName(enum_tok),
        .tag_ty = .{ .specifier = .void }, // void means incomplete
        .fields = &.{},
    };
    const ty = Type{
        .specifier = .@"enum",
        .data = .{ .@"enum" = enum_ty },
    };

    // declare a symbol for the type
    if (maybe_ident) |ident| {
        try p.scopes.append(.{ .@"enum" = .{
            .name = enum_ty.name,
            .ty = ty,
            .name_tok = ident,
        } });
    }

    var fields = std.ArrayList(Type.Enum.Field).init(p.pp.comp.gpa);
    defer fields.deinit();
    var field_nodes = NodeList.init(p.pp.comp.gpa);
    defer field_nodes.deinit();

    while (try p.enumerator()) |field_and_node| {
        try fields.append(field_and_node.field);
        try field_nodes.append(field_and_node.node);
        if (p.eatToken(.comma) == null) break;
    }
    if (fields.items.len == 0) try p.err(.empty_enum);

    try p.expectClosing(l_brace, .r_brace);
    enum_ty.fields = try p.arena.dupe(Type.Enum.Field, fields.items);

    // finish by creating a node
    var node: Tree.Node = .{ .tag = .enum_decl_two, .ty = ty, .data = .{
        .bin = .{ .lhs = .none, .rhs = .none },
    } };
    switch (field_nodes.items.len) {
        0 => {},
        1 => node.data = .{ .bin = .{ .lhs = field_nodes.items[0], .rhs = .none } },
        2 => node.data = .{ .bin = .{ .lhs = field_nodes.items[0], .rhs = field_nodes.items[1] } },
        else => {
            node.tag = .enum_decl;
            node.data = .{ .range = try p.addList(field_nodes.items) };
        },
    }
    try p.cur_decl_list.append(try p.addNode(node));
    return enum_ty;
}

const EnumFieldAndNode = struct { field: Type.Enum.Field, node: NodeIndex };

/// enumerator : IDENTIFIER ('=' constExpr)
fn enumerator(p: *Parser) Error!?EnumFieldAndNode {
    const name_tok = p.eatToken(.identifier) orelse {
        if (p.tok_ids[p.tok_i] == .r_brace) return null;
        try p.err(.expected_identifier);
        // TODO skip to }
        return error.ParsingFailed;
    };
    const name = p.tokSlice(name_tok);
    // TODO get from enumSpec
    var res: Result = .{
        .ty = .{ .specifier = .int },
        .val = .{
            .unsigned = 0,
        },
    };
    if (p.eatToken(.equal)) |_| {
        res = try p.constExpr();
    }

    try p.scopes.append(.{ .enumeration = .{
        .name = name,
        .value = res,
    } });
    return EnumFieldAndNode{ .field = .{
        .name = name,
        .ty = res.ty,
        .value = res.as_u64(),
    }, .node = try p.addNode(.{
        .tag = .enum_field_decl,
        .ty = res.ty,
        .data = .{ .decl = .{
            .name = name_tok,
            .node = res.node,
        } },
    }) };
}

/// typeQual : keyword_const | keyword_restrict | keyword_volatile | keyword_atomic
fn typeQual(p: *Parser, ty: *Type) Error!bool {
    var any = false;
    while (true) {
        switch (p.tok_ids[p.tok_i]) {
            .keyword_restrict, .keyword_restrict1, .keyword_restrict2 => {
                if (ty.specifier != .pointer)
                    try p.errExtra(.restrict_non_pointer, p.tok_i, .{ .str = Type.Builder.fromType(ty.*).str() })
                else if (ty.qual.restrict)
                    try p.errStr(.duplicate_decl_spec, p.tok_i, "restrict")
                else
                    ty.qual.restrict = true;
            },
            .keyword_const, .keyword_const1, .keyword_const2 => {
                if (ty.qual.@"const")
                    try p.errStr(.duplicate_decl_spec, p.tok_i, "const")
                else
                    ty.qual.@"const" = true;
            },
            .keyword_volatile, .keyword_volatile1, .keyword_volatile2 => {
                if (ty.qual.@"volatile")
                    try p.errStr(.duplicate_decl_spec, p.tok_i, "volatile")
                else
                    ty.qual.@"volatile" = true;
            },
            .keyword_atomic => {
                // _Atomic(typeName) instead of just _Atomic
                if (p.tok_ids[p.tok_i + 1] == .l_paren) break;
                if (ty.qual.atomic)
                    try p.errStr(.duplicate_decl_spec, p.tok_i, "atomic")
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

const Declarator = struct {
    name: TokenIndex,
    ty: Type,
    func_declarator: ?TokenIndex = null,
    old_style_func: ?TokenIndex = null,
};
const DeclaratorKind = enum { normal, abstract, param, record };

/// declarator : pointer? (IDENTIFIER | '(' declarator ')') directDeclarator*
/// abstractDeclarator
/// : pointer? ('(' abstractDeclarator ')')? directAbstractDeclarator*
fn declarator(
    p: *Parser,
    base_type: Type,
    kind: DeclaratorKind,
) Error!?Declarator {
    const start = p.tok_i;
    var d = Declarator{ .name = 0, .ty = try p.pointer(base_type) };

    if (kind != .abstract and p.tok_ids[p.tok_i] == .identifier) {
        d.name = p.tok_i;
        p.tok_i += 1;
        d.ty = try p.directDeclarator(d.ty, &d, kind);
        return d;
    } else if (p.eatToken(.l_paren)) |l_paren| blk: {
        var res = (try p.declarator(.{ .specifier = .void }, kind)) orelse {
            p.tok_i = l_paren;
            break :blk;
        };
        try p.expectClosing(l_paren, .r_paren);
        const suffix_start = p.tok_i;
        const outer = try p.directDeclarator(d.ty, &d, kind);
        try res.ty.combine(outer, p, res.func_declarator orelse suffix_start);
        res.old_style_func = d.old_style_func;
        return res;
    }

    if (kind == .normal and !base_type.isEnumOrRecord()) {
        try p.err(.expected_ident_or_l_paren);
    }

    d.ty = try p.directDeclarator(d.ty, &d, kind);
    if (start == p.tok_i) return null;
    return d;
}

/// directDeclarator
///  : '[' typeQual* assignExpr? ']' directDeclarator?
///  | '[' keyword_static typeQual* assignExpr ']' directDeclarator?
///  | '[' typeQual+ keyword_static assignExpr ']' directDeclarator?
///  | '[' typeQual* '*' ']' directDeclarator?
///  | '(' paramDecls ')' directDeclarator?
///  | '(' (IDENTIFIER (',' IDENTIFIER))? ')' directDeclarator?
/// directAbstractDeclarator
///  : '[' typeQual* assignExpr? ']'
///  | '[' keyword_static typeQual* assignExpr ']'
///  | '[' typeQual+ keyword_static assignExpr ']'
///  | '[' '*' ']'
///  | '(' paramDecls? ')'
fn directDeclarator(p: *Parser, base_type: Type, d: *Declarator, kind: DeclaratorKind) Error!Type {
    if (p.eatToken(.l_bracket)) |l_bracket| {
        var res_ty = Type{
            // so that we can get any restrict type that might be present
            .specifier = .pointer,
        };

        var got_quals = try p.typeQual(&res_ty);
        var static = p.eatToken(.keyword_static);
        if (static != null and !got_quals) got_quals = try p.typeQual(&res_ty);
        var star = p.eatToken(.asterisk);
        const size = if (star) |_| Result{} else try p.assignExpr();
        try p.expectClosing(l_bracket, .r_bracket);

        if (star != null and static != null) {
            try p.errTok(.invalid_static_star, static.?);
            static = null;
        }
        if (kind != .param) {
            if (static != null)
                try p.errTok(.static_non_param, l_bracket)
            else if (got_quals)
                try p.errTok(.array_qualifiers, l_bracket);
            if (star) |some| try p.errTok(.star_non_param, some);
            static = null;
            res_ty.qual = .{};
            star = null;
        }
        if (static) |_| try size.expect(p);

        switch (size.val) {
            .unavailable => if (size.node != .none) {
                if (!p.in_function and kind != .param) try p.errTok(.variable_len_array_file_scope, l_bracket);
                const vla_ty = try p.arena.create(Type.VLA);
                vla_ty.expr = size.node;
                res_ty.data = .{ .vla = vla_ty };
                res_ty.specifier = .variable_len_array;

                if (static) |some| try p.errTok(.useless_static, some);
            } else if (star) |_| {
                const elem_ty = try p.arena.create(Type);
                res_ty.data = .{ .sub_type = elem_ty };
                res_ty.specifier = .unspecified_variable_len_array;
            } else {
                const arr_ty = try p.arena.create(Type.Array);
                arr_ty.len = 0;
                res_ty.data = .{ .array = arr_ty };
                res_ty.specifier = .incomplete_array;
            },
            .unsigned => |v| {
                const arr_ty = try p.arena.create(Type.Array);
                arr_ty.len = v;
                res_ty.data = .{ .array = arr_ty };
                res_ty.specifier = .array;
            },
            .signed => |v| {
                if (v < 0) try p.errTok(.negative_array_size, l_bracket);
                const arr_ty = try p.arena.create(Type.Array);
                arr_ty.len = @bitCast(u64, v);
                res_ty.data = .{ .array = arr_ty };
                res_ty.specifier = .array;
            },
        }

        const outer = try p.directDeclarator(base_type, d, kind);
        try res_ty.combine(outer, p, l_bracket);
        return res_ty;
    } else if (p.eatToken(.l_paren)) |l_paren| {
        d.func_declarator = l_paren;
        if (p.tok_ids[p.tok_i] == .ellipsis) {
            try p.err(.param_before_var_args);
            p.tok_i += 1;
        }

        const func_ty = try p.arena.create(Type.Func);
        func_ty.params = &.{};
        var specifier: Type.Specifier = .func;

        if (try p.paramDecls()) |params| {
            func_ty.params = params;
            if (p.eatToken(.ellipsis)) |_| specifier = .var_args_func;
        } else if (p.tok_ids[p.tok_i] == .r_paren) {
            specifier = .old_style_func;
        } else if (p.tok_ids[p.tok_i] == .identifier) {
            d.old_style_func = p.tok_i;
            var params = std.ArrayList(Type.Func.Param).init(p.pp.comp.gpa);
            defer params.deinit();

            specifier = .old_style_func;
            while (true) {
                try params.append(.{
                    .name = p.tokSlice(try p.expectToken(.identifier)),
                    .ty = .{ .specifier = .int },
                    .register = false,
                });
                if (p.eatToken(.comma) == null) break;
            }
            func_ty.params = try p.arena.dupe(Type.Func.Param, params.items);
        } else {
            try p.err(.expected_param_decl);
        }

        try p.expectClosing(l_paren, .r_paren);
        var res_ty = Type{
            .specifier = specifier,
            .data = .{ .func = func_ty },
        };

        const outer = try p.directDeclarator(base_type, d, kind);
        try res_ty.combine(outer, p, l_paren);
        return res_ty;
    } else return base_type;
}

/// pointer : '*' typeQual* pointer?
fn pointer(p: *Parser, base_ty: Type) Error!Type {
    var ty = base_ty;
    while (p.eatToken(.asterisk)) |_| {
        const elem_ty = try p.arena.create(Type);
        elem_ty.* = ty;
        ty = Type{
            .specifier = .pointer,
            .data = .{ .sub_type = elem_ty },
        };
        _ = try p.typeQual(&ty);
    }
    return ty;
}

/// paramDecls : paramDecl (',' paramDecl)* (',' '...')
/// paramDecl : declSpec (declarator | abstractDeclarator)
fn paramDecls(p: *Parser) Error!?[]Type.Func.Param {
    var params = std.ArrayList(Type.Func.Param).init(p.pp.comp.gpa);
    defer params.deinit();

    while (true) {
        const param_decl_spec = if (try p.declSpec()) |some|
            some
        else if (params.items.len == 0)
            return null
        else blk: {
            var d: DeclSpec = .{};
            var spec: Type.Builder = .{};
            try spec.finish(p, &d.ty);
            break :blk d;
        };

        var name_tok = p.tok_i;
        var param_ty = param_decl_spec.ty;
        if (try p.declarator(param_decl_spec.ty, .param)) |some| {
            if (some.old_style_func) |tok_i| try p.errTok(.invalid_old_style_params, tok_i);
            // TODO declare();
            name_tok = some.name;
            param_ty = some.ty;
        }

        if (param_ty.isFunc()) {
            // params declared as functions are converted to function pointers
            const elem_ty = try p.arena.create(Type);
            elem_ty.* = param_ty;
            param_ty = Type{
                .specifier = .pointer,
                .data = .{ .sub_type = elem_ty },
            };
        } else if (param_ty.specifier == .void) {
            // validate void parameters
            if (params.items.len == 0) {
                if (p.tok_ids[p.tok_i] != .r_paren) {
                    try p.err(.void_only_param);
                    if (param_ty.qual.any()) try p.err(.void_param_qualified);
                    return error.ParsingFailed;
                }
                return &[0]Type.Func.Param{};
            }
            try p.err(.void_must_be_first_param);
            return error.ParsingFailed;
        } else if (param_ty.isArray()) {
            // TODO convert to pointer
        }

        try param_decl_spec.validateParam(p, param_ty);
        try params.append(.{
            .name = p.tokSlice(name_tok),
            .ty = param_ty,
            .register = param_decl_spec.storage_class == .register,
        });

        if (p.eatToken(.comma) == null) break;
        if (p.tok_ids[p.tok_i] == .ellipsis) break;
    }
    return try p.arena.dupe(Type.Func.Param, params.items);
}

/// typeName : specQual abstractDeclarator
fn typeName(p: *Parser) Error!?Type {
    var ty = (try p.specQual()) orelse return null;
    if (try p.declarator(ty, .abstract)) |some| {
        if (some.old_style_func) |tok_i| try p.errTok(.invalid_old_style_params, tok_i);
        return some.ty;
    } else return ty;
}

/// initializer
///  : assignExpr
///  | '{' initializerItems '}'
fn initializer(p: *Parser, paren_ty: Type) Error!Result {
    if (p.eatToken(.l_brace)) |l_brace| {
        var initializers = NodeList.init(p.pp.comp.gpa);
        defer initializers.deinit();

        while (try p.initializerItem(paren_ty)) |item| {
            try initializers.append(item);
            if (p.eatToken(.comma) == null) break;
        }
        try p.expectClosing(l_brace, .r_brace);

        var node: Tree.Node = .{
            .tag = .compound_initializer_expr_two,
            .ty = paren_ty,
            .data = .{ .bin = .{ .lhs = .none, .rhs = .none } },
        };
        switch (initializers.items.len) {
            0 => {},
            1 => node.data = .{ .bin = .{ .lhs = initializers.items[0], .rhs = .none } },
            2 => node.data = .{ .bin = .{ .lhs = initializers.items[0], .rhs = initializers.items[1] } },
            else => {
                node.tag = .compound_initializer_expr;
                node.data = .{ .range = try p.addList(initializers.items) };
            },
        }
        return Result{ .node = try p.addNode(node), .ty = paren_ty };
    }
    return p.assignExpr();
}

/// initializerItems : designation? initializer (',' designation? initializer)* ','?
/// designation : designator+ '='
/// designator
///  : '[' constExpr ']'
///  | '.' identifier
fn initializerItem(p: *Parser, paren_ty: Type) Error!?NodeIndex {
    var cur_ty = paren_ty;
    var designation: NodeIndex = .none;
    while (true) {
        if (p.eatToken(.l_bracket)) |l_bracket| {
            const res = try p.constExpr();
            try p.expectClosing(l_bracket, .r_bracket);
            designation = try p.addNode(.{
                .tag = .array_designator_expr,
                // TODO do type checking
                .data = .{ .bin = .{
                    .lhs = designation,
                    .rhs = res.node,
                } },
            });
        } else if (p.eatToken(.period)) |_| {
            const identifier = try p.expectToken(.identifier);
            designation = try p.addNode(.{
                .tag = .member_designator_expr,
                .data = .{
                    .member = .{
                        .lhs = designation,
                        // TODO do type checking
                        .name = identifier,
                    },
                },
            });
        } else break;
    }
    if (designation != .none) _ = try p.expectToken(.equal);

    const init_res = try p.initializer(cur_ty);
    if (designation != .none) {
        try init_res.expect(p);
    } else if (init_res.node == .none) {
        return null;
    }
    return try p.addNode(.{
        .tag = .initializer_item_expr,
        // TODO do type checking
        .data = .{ .bin = .{
            .lhs = designation,
            .rhs = init_res.node,
        } },
    });
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
fn stmt(p: *Parser) Error!NodeIndex {
    if (try p.labeledStmt()) |some| return some;
    if (try p.compoundStmt()) |some| return some;
    if (p.eatToken(.keyword_if)) |_| {
        const start_scopes_len = p.scopes.items.len;
        defer p.scopes.items.len = start_scopes_len;

        const l_paren = try p.expectToken(.l_paren);
        const cond = try p.expr();
        // TODO validate type
        try cond.expect(p);
        try p.expectClosing(l_paren, .r_paren);

        const then = try p.stmt();
        const @"else" = if (p.eatToken(.keyword_else)) |_| try p.stmt() else .none;

        if (then != .none and @"else" != .none)
            return try p.addNode(.{
                .tag = .if_then_else_stmt,
                .data = .{ .if3 = .{ .cond = cond.node, .body = (try p.addList(&.{ then, @"else" })).start } },
            })
        else if (then == .none and @"else" != .none)
            return try p.addNode(.{
                .tag = .if_else_stmt,
                .data = .{ .bin = .{ .lhs = cond.node, .rhs = @"else" } },
            })
        else
            return try p.addNode(.{
                .tag = .if_then_stmt,
                .data = .{ .bin = .{ .lhs = cond.node, .rhs = then } },
            });
    }
    if (p.eatToken(.keyword_switch)) |_| {
        const start_scopes_len = p.scopes.items.len;
        defer p.scopes.items.len = start_scopes_len;

        const l_paren = try p.expectToken(.l_paren);
        const cond = try p.expr();
        // TODO validate type
        try cond.expect(p);
        try p.expectClosing(l_paren, .r_paren);

        var switch_scope = Scope.Switch{
            .cases = Scope.Switch.CaseMap.init(p.pp.comp.gpa),
        };
        defer switch_scope.cases.deinit();
        try p.scopes.append(.{ .@"switch" = &switch_scope });
        const body = try p.stmt();

        return try p.addNode(.{
            .tag = .switch_stmt,
            .data = .{ .bin = .{ .rhs = cond.node, .lhs = body } },
        });
    }
    if (p.eatToken(.keyword_while)) |_| {
        const start_scopes_len = p.scopes.items.len;
        defer p.scopes.items.len = start_scopes_len;

        const l_paren = try p.expectToken(.l_paren);
        const cond = try p.expr();
        // TODO validate type
        try cond.expect(p);
        try p.expectClosing(l_paren, .r_paren);

        try p.scopes.append(.loop);
        const body = try p.stmt();

        return try p.addNode(.{
            .tag = .while_stmt,
            .data = .{ .bin = .{ .rhs = cond.node, .lhs = body } },
        });
    }
    if (p.eatToken(.keyword_do)) |_| {
        const start_scopes_len = p.scopes.items.len;
        defer p.scopes.items.len = start_scopes_len;

        try p.scopes.append(.loop);
        const body = try p.stmt();
        p.scopes.items.len = start_scopes_len;

        _ = try p.expectToken(.keyword_while);
        const l_paren = try p.expectToken(.l_paren);
        const cond = try p.expr();
        // TODO validate type
        try cond.expect(p);
        try p.expectClosing(l_paren, .r_paren);

        _ = try p.expectToken(.semicolon);
        return try p.addNode(.{
            .tag = .do_while_stmt,
            .data = .{ .bin = .{ .rhs = cond.node, .lhs = body } },
        });
    }
    if (p.eatToken(.keyword_for)) |_| {
        const start_scopes_len = p.scopes.items.len;
        defer p.scopes.items.len = start_scopes_len;

        var decls = NodeList.init(p.pp.comp.gpa);
        defer decls.deinit();

        const saved_decls = p.cur_decl_list;
        defer p.cur_decl_list = saved_decls;
        p.cur_decl_list = &decls;

        const l_paren = try p.expectToken(.l_paren);
        const got_decl = try p.decl();

        // for (init
        const init_start = p.tok_i;
        const init = if (!got_decl) try p.expr() else Result{};
        try p.maybeWarnUnused(init.node, init_start);
        if (!got_decl) _ = try p.expectToken(.semicolon);

        // for (init; cond
        const cond = try p.expr();
        _ = try p.expectToken(.semicolon);

        // for (init; cond; incr
        const incr_start = p.tok_i;
        const incr = try p.expr();
        try p.maybeWarnUnused(incr.node, incr_start);
        try p.expectClosing(l_paren, .r_paren);

        try p.scopes.append(.loop);
        const body = try p.stmt();

        if (got_decl) {
            const start = (try p.addList(decls.items)).start;
            const end = (try p.addList(&.{ cond.node, incr.node, body })).end;

            return try p.addNode(.{
                .tag = .for_decl_stmt,
                .data = .{ .range = .{ .start = start, .end = end } },
            });
        } else if (init.node == .none and cond.node == .none and incr.node == .none) {
            return try p.addNode(.{
                .tag = .forever_stmt,
                .data = .{ .un = body },
            });
        } else return try p.addNode(.{
            .tag = .for_stmt,
            .data = .{ .range = try p.addList(&.{ init.node, cond.node, incr.node }) },
        });
    }
    if (p.eatToken(.keyword_goto)) |_| {
        const name_tok = try p.expectToken(.identifier);
        const str = p.tokSlice(name_tok);
        if (p.findLabel(str) == null) {
            try p.labels.append(.{ .unresolved_goto = name_tok });
        }
        _ = try p.expectToken(.semicolon);
        return try p.addNode(.{
            .tag = .goto_stmt,
            .data = .{ .decl_ref = name_tok },
        });
    }
    if (p.eatToken(.keyword_continue)) |cont| {
        if (!p.inLoop()) try p.errTok(.continue_not_in_loop, cont);
        _ = try p.expectToken(.semicolon);
        return try p.addNode(.{ .tag = .continue_stmt, .data = undefined });
    }
    if (p.eatToken(.keyword_break)) |br| {
        if (!p.inLoopOrSwitch()) try p.errTok(.break_not_in_loop_or_switch, br);
        _ = try p.expectToken(.semicolon);
        return try p.addNode(.{ .tag = .break_stmt, .data = undefined });
    }
    if (p.eatToken(.keyword_return)) |_| {
        const e = try p.expr();
        _ = try p.expectToken(.semicolon);
        // TODO cast to return type
        return try p.addNode(.{
            .tag = .return_stmt,
            .data = .{ .un = e.node },
        });
    }

    const expr_start = p.tok_i;
    const e = try p.expr();
    if (e.node != .none) {
        _ = try p.expectToken(.semicolon);
        try p.maybeWarnUnused(e.node, expr_start);
        return e.node;
    }
    if (p.eatToken(.semicolon)) |_| return .none;

    try p.err(.expected_stmt);
    return error.ParsingFailed;
}

fn maybeWarnUnused(p: *Parser, node: NodeIndex, expr_start: TokenIndex) Error!void {
    switch (p.nodes.items(.tag)[@enumToInt(node)]) {
        .invalid, // So that we don't need to check for node == 0
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
        .call_expr,
        .call_expr_one,
        => return,
        .cast_expr => if (p.nodes.items(.ty)[@enumToInt(node)].specifier == .void) return,
        else => {},
    }
    try p.errTok(.unused_value, expr_start);
}

/// labeledStmt
/// : IDENTIFIER ':' stmt
/// | keyword_case constExpr ':' stmt
/// | keyword_default ':' stmt
fn labeledStmt(p: *Parser) Error!?NodeIndex {
    if (p.tok_ids[p.tok_i] == .identifier and p.tok_ids[p.tok_i + 1] == .colon) {
        const name_tok = p.tok_i;
        const str = p.tokSlice(name_tok);
        if (p.findLabel(str)) |some| {
            try p.errStr(.duplicate_label, name_tok, str);
            try p.errStr(.previous_label, some, str);
        } else {
            p.label_count += 1;
            try p.labels.append(.{ .label = name_tok });
            var i: usize = 0;
            while (i < p.labels.items.len) : (i += 1) {
                if (p.labels.items[i] == .unresolved_goto and
                    mem.eql(u8, p.tokSlice(p.labels.items[i].unresolved_goto), str))
                {
                    _ = p.labels.swapRemove(i);
                }
            }
        }

        p.tok_i += 2;
        return try p.addNode(.{
            .tag = .labeled_stmt,
            .data = .{ .decl = .{ .name = name_tok, .node = try p.stmt() } },
        });
    } else if (p.eatToken(.keyword_case)) |case| {
        const val = try p.constExpr();
        _ = try p.expectToken(.colon);
        const s = try p.stmt();
        const node = try p.addNode(.{
            .tag = .case_stmt,
            .data = .{ .bin = .{ .lhs = val.node, .rhs = s } },
        });
        if (p.findSwitch()) |some| {
            const gop = try some.cases.getOrPut(val);
            if (gop.found_existing) {
                switch (val.val) {
                    .unsigned => |v| try p.errExtra(.duplicate_switch_case_unsigned, case, .{ .unsigned = v }),
                    .signed => |v| try p.errExtra(.duplicate_switch_case_signed, case, .{ .signed = v }),
                    else => unreachable,
                }
                try p.errTok(.previous_case, gop.value_ptr.tok);
            } else {
                gop.value_ptr.* = .{
                    .tok = case,
                    .node = node,
                };
            }
        } else {
            try p.errStr(.case_not_in_switch, case, "case");
        }
        return node;
    } else if (p.eatToken(.keyword_default)) |default| {
        _ = try p.expectToken(.colon);
        const s = try p.stmt();
        const node = try p.addNode(.{
            .tag = .default_stmt,
            .data = .{ .un = s },
        });
        if (p.findSwitch()) |some| {
            if (some.default) |previous| {
                try p.errTok(.multiple_default, default);
                try p.errTok(.previous_case, previous.tok);
            } else {
                some.default = .{
                    .tok = default,
                    .node = node,
                };
            }
        } else {
            try p.errStr(.case_not_in_switch, default, "default");
        }
        return node;
    } else return null;
}

/// compoundStmt : '{' ( decl| staticAssert | stmt)* '}'
fn compoundStmt(p: *Parser) Error!?NodeIndex {
    const l_brace = p.eatToken(.l_brace) orelse return null;
    var statements = NodeList.init(p.pp.comp.gpa);
    defer statements.deinit();

    const saved_decls = p.cur_decl_list;
    defer p.cur_decl_list = saved_decls;
    p.cur_decl_list = &statements;

    var noreturn_index: ?TokenIndex = null;
    var noreturn_label_count: u32 = 0;

    while (p.eatToken(.r_brace) == null) {
        if (p.staticAssert() catch |er| switch (er) {
            error.ParsingFailed => {
                try p.nextStmt(l_brace);
                continue;
            },
            else => |e| return e,
        }) continue;
        if (p.decl() catch |er| switch (er) {
            error.ParsingFailed => {
                try p.nextStmt(l_brace);
                continue;
            },
            else => |e| return e,
        }) continue;
        const s = p.stmt() catch |er| switch (er) {
            error.ParsingFailed => {
                try p.nextStmt(l_brace);
                continue;
            },
            else => |e| return e,
        };
        if (s == .none) continue;
        try statements.append(s);

        if (noreturn_index == null and p.nodeIsNoreturn(s)) {
            noreturn_index = p.tok_i;
            noreturn_label_count = p.label_count;
        }
    }

    if (noreturn_index) |some| {
        // if new labels were defined we cannot be certain that the code is unreachable
        if (some != p.tok_i - 1 and noreturn_label_count == p.label_count) try p.errTok(.unreachable_code, some);
    }

    var node: Tree.Node = .{
        .tag = .compound_stmt_two,
        .data = .{ .bin = .{ .lhs = .none, .rhs = .none } },
    };
    switch (statements.items.len) {
        0 => {},
        1 => node.data = .{ .bin = .{ .lhs = statements.items[0], .rhs = .none } },
        2 => node.data = .{ .bin = .{ .lhs = statements.items[0], .rhs = statements.items[1] } },
        else => {
            node.tag = .compound_stmt;
            node.data = .{ .range = try p.addList(statements.items) };
        },
    }
    return try p.addNode(node);
}

fn nodeIsNoreturn(p: *Parser, node: NodeIndex) bool {
    switch (p.nodes.items(.tag)[@enumToInt(node)]) {
        .break_stmt, .continue_stmt, .return_stmt => return true,
        .if_then_else_stmt => {
            const data = p.data.items[p.nodes.items(.data)[@enumToInt(node)].if3.body..];
            return p.nodeIsNoreturn(data[0]) and p.nodeIsNoreturn(data[1]);
        },
        else => return false,
    }
}

fn nextStmt(p: *Parser, l_brace: TokenIndex) !void {
    var parens: u32 = 0;
    while (p.tok_i < p.tok_ids.len) : (p.tok_i += 1) {
        switch (p.tok_ids[p.tok_i]) {
            .l_paren, .l_brace, .l_bracket => parens += 1,
            .r_paren, .r_bracket => if (parens != 0) {
                parens -= 1;
            },
            .r_brace => if (parens == 0)
                return
            else {
                parens -= 1;
            },
            .semicolon,
            .keyword_for,
            .keyword_while,
            .keyword_do,
            .keyword_if,
            .keyword_goto,
            .keyword_switch,
            .keyword_case,
            .keyword_default,
            .keyword_continue,
            .keyword_break,
            .keyword_return,
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
            => if (parens == 0) return,
            else => {},
        }
    }
    p.tok_i -= 1; // So we can consume EOF
    try p.expectClosing(l_brace, .r_brace);
    unreachable;
}

// ====== expressions ======

pub fn macroExpr(p: *Parser) Compilation.Error!bool {
    const res = p.condExpr() catch |e| switch (e) {
        error.OutOfMemory => return error.OutOfMemory,
        error.FatalError => return error.FatalError,
        error.ParsingFailed => return false,
    };
    if (res.val == .unavailable) {
        try p.errTok(.expected_expr, p.tok_i);
        return false;
    }
    return res.getBool();
}

pub const Result = struct {
    node: NodeIndex = .none,
    ty: Type = .{ .specifier = .int },
    val: union(enum) {
        unsigned: u64,
        signed: i64,
        unavailable,
    } = .unavailable,

    pub fn getBool(res: Result) bool {
        return switch (res.val) {
            .signed => |v| v != 0,
            .unsigned => |v| v != 0,
            .unavailable => unreachable,
        };
    }

    fn as_u64(res: Result) u64 {
        return switch (res.val) {
            .signed => |v| @bitCast(u64, v),
            .unsigned => |v| v,
            .unavailable => unreachable,
        };
    }

    fn expect(res: Result, p: *Parser) Error!void {
        try res.saveValue(p);
        if (res.node == .none) {
            try p.errTok(.expected_expr, p.tok_i);
            return error.ParsingFailed;
        }
    }

    fn bin(lhs: *Result, p: *Parser, tag: Tree.Tag, rhs: Result) !void {
        lhs.node = try p.addNode(.{
            .tag = tag,
            .ty = lhs.ty,
            .data = .{ .bin = .{ .lhs = lhs.node, .rhs = rhs.node } },
        });
    }

    fn un(operand: *Result, p: *Parser, tag: Tree.Tag) Error!Result {
        operand.node = try p.addNode(.{
            .tag = tag,
            .ty = operand.ty,
            .data = .{ .un = operand.node },
        });
        return operand.*;
    }

    fn coerce(res: Result, p: *Parser, dest_ty: Type) !Result {
        var casted = res;
        _ = dest_ty;
        _ = p;
        // var cur_ty = res.ty;
        // if (casted.data == .lval) {
        //     cur_ty.qual.@"const" = false;
        //     casted = try node(p, .{
        //         .tag = .lval_to_rval,
        //         .ty = cur_ty,
        //         .data = .{ .first = casted.node },
        //     });
        // }
        // if (dest_ty.specifier == .pointer and cur_ty.isArray()) {
        //     const elem_ty = &cur_ty.data.array.elem;
        //     cur_ty.specifier = .pointer;
        //     cur_ty.data = .{ .sub_type = elem_ty };
        //     casted = try node(p, .{
        //         .tag = .array_to_pointer,
        //         .ty = cur_ty,
        //         .data = .{ .first = casted.node },
        //     });
        // }
        return casted;
    }

    /// Adjust types for binary operation, returns true if the result can and should be evaluated.
    fn adjustTypes(a: *Result, b: *Result, p: *Parser) !bool {
        const a_is_unsigned = a.ty.isUnsignedInt(p.pp.comp);
        const b_is_unsigned = b.ty.isUnsignedInt(p.pp.comp);

        if (a_is_unsigned != b_is_unsigned) {}

        if (p.no_eval) return false;
        if (a.val != .unavailable and b.val != .unavailable)
            return true;

        try a.saveValue(p);
        try b.saveValue(p);
        return p.no_eval;
    }

    fn saveValue(res: Result, p: *Parser) !void {
        assert(!p.in_macro);
        if (res.val == .unavailable) return;
        switch (p.nodes.items(.tag)[@enumToInt(res.node)]) {
            .int_literal => return,
            else => {},
        }

        switch (res.val) {
            .unsigned => |v| try p.value_map.put(res.node, v),
            .signed => |v| try p.value_map.put(res.node, @bitCast(u64, v)),
            .unavailable => {},
        }
    }

    fn hash(res: Result) u64 {
        switch (res.val) {
            .unsigned => |v| return std.hash.Wyhash.hash(0, mem.asBytes(&v)),
            .signed => |v| return std.hash.Wyhash.hash(0, mem.asBytes(&v)),
            .unavailable => unreachable,
        }
    }

    fn eql(a: Result, b: Result) bool {
        return a.compare(.eq, b);
    }

    fn compare(a: Result, op: std.math.CompareOperator, b: Result) bool {
        switch (a.val) {
            .unsigned => |val| return std.math.compare(val, op, b.val.unsigned),
            .signed => |val| return std.math.compare(val, op, b.val.signed),
            .unavailable => unreachable,
        }
    }

    fn mul(a: *Result, tok: TokenIndex, b: Result, p: *Parser) !void {
        const size = a.ty.sizeof(p.pp.comp);
        var overflow = false;
        switch (a.val) {
            .unsigned => |*v| {
                switch (size) {
                    1 => unreachable, // upcasted to int
                    2 => unreachable, // upcasted to int
                    4 => {
                        var res: u32 = undefined;
                        overflow = @mulWithOverflow(u32, @truncate(u32, v.*), @truncate(u32, b.val.unsigned), &res);
                        v.* = res;
                    },
                    8 => overflow = @mulWithOverflow(u64, v.*, b.val.unsigned, v),
                    else => unreachable,
                }
                if (overflow) try p.errExtra(.overflow_unsigned, tok, .{ .unsigned = v.* });
            },
            .signed => |*v| {
                switch (size) {
                    1 => unreachable, // upcasted to int
                    2 => unreachable, // upcasted to int
                    4 => {
                        var res: i32 = undefined;
                        overflow = @mulWithOverflow(i32, @truncate(i32, v.*), @truncate(i32, b.val.signed), &res);
                        v.* = res;
                    },
                    8 => overflow = @mulWithOverflow(i64, v.*, b.val.signed, v),
                    else => unreachable,
                }
                if (overflow) try p.errExtra(.overflow_signed, tok, .{ .signed = v.* });
            },
            .unavailable => unreachable,
        }
    }

    fn add(a: *Result, tok: TokenIndex, b: Result, p: *Parser) !void {
        const size = a.ty.sizeof(p.pp.comp);
        var overflow = false;
        switch (a.val) {
            .unsigned => |*v| {
                switch (size) {
                    1 => unreachable, // upcasted to int
                    2 => unreachable, // upcasted to int
                    4 => {
                        var res: u32 = undefined;
                        overflow = @addWithOverflow(u32, @truncate(u32, v.*), @truncate(u32, b.val.unsigned), &res);
                        v.* = res;
                    },
                    8 => overflow = @addWithOverflow(u64, v.*, b.val.unsigned, v),
                    else => unreachable,
                }
                if (overflow) try p.errExtra(.overflow_unsigned, tok, .{ .unsigned = v.* });
            },
            .signed => |*v| {
                switch (size) {
                    1 => unreachable, // upcasted to int
                    2 => unreachable, // upcasted to int
                    4 => {
                        var res: i32 = undefined;
                        overflow = @addWithOverflow(i32, @truncate(i32, v.*), @truncate(i32, b.val.signed), &res);
                        v.* = res;
                    },
                    8 => overflow = @addWithOverflow(i64, v.*, b.val.signed, v),
                    else => unreachable,
                }
                if (overflow) try p.errExtra(.overflow_signed, tok, .{ .signed = v.* });
            },
            .unavailable => unreachable,
        }
    }

    fn sub(a: *Result, tok: TokenIndex, b: Result, p: *Parser) !void {
        const size = a.ty.sizeof(p.pp.comp);
        var overflow = false;
        switch (a.val) {
            .unsigned => |*v| {
                switch (size) {
                    1 => unreachable, // upcasted to int
                    2 => unreachable, // upcasted to int
                    4 => {
                        var res: u32 = undefined;
                        overflow = @subWithOverflow(u32, @truncate(u32, v.*), @truncate(u32, b.val.unsigned), &res);
                        v.* = res;
                    },
                    8 => overflow = @subWithOverflow(u64, v.*, b.val.unsigned, v),
                    else => unreachable,
                }
                if (overflow) try p.errExtra(.overflow_unsigned, tok, .{ .unsigned = v.* });
            },
            .signed => |*v| {
                switch (size) {
                    1 => unreachable, // upcasted to int
                    2 => unreachable, // upcasted to int
                    4 => {
                        var res: i32 = undefined;
                        overflow = @subWithOverflow(i32, @truncate(i32, v.*), @truncate(i32, b.val.signed), &res);
                        v.* = res;
                    },
                    8 => overflow = @subWithOverflow(i64, v.*, b.val.signed, v),
                    else => unreachable,
                }
                if (overflow) try p.errExtra(.overflow_signed, tok, .{ .signed = v.* });
            },
            .unavailable => unreachable,
        }
    }
};

/// expr : assignExpr (',' assignExpr)*
fn expr(p: *Parser) Error!Result {
    var expr_start = p.tok_i;
    var lhs = try p.assignExpr();
    while (p.eatToken(.comma)) |_| {
        try p.maybeWarnUnused(lhs.node, expr_start);
        expr_start = p.tok_i;

        const rhs = try p.assignExpr();
        lhs.val = rhs.val;
        try lhs.bin(p, .comma_expr, rhs);
    }
    return lhs;
}

/// assignExpr
///  : condExpr
///  | unExpr ('=' | '*=' | '/=' | '%=' | '+=' | '-=' | '<<=' | '>>=' | '&=' | '^=' | '|=') assignExpr
fn assignExpr(p: *Parser) Error!Result {
    var lhs = try p.condExpr();

    const tok = p.tok_i;
    const eq = p.eatToken(.equal);
    const mul = eq orelse p.eatToken(.asterisk_equal);
    const div = mul orelse p.eatToken(.slash_equal);
    const mod = div orelse p.eatToken(.percent_equal);
    const add = mod orelse p.eatToken(.plus_equal);
    const sub = add orelse p.eatToken(.minus_equal);
    const shl = sub orelse p.eatToken(.angle_bracket_angle_bracket_left_equal);
    const shr = shl orelse p.eatToken(.angle_bracket_angle_bracket_right_equal);
    const bit_and = shr orelse p.eatToken(.ampersand_equal);
    const bit_xor = bit_and orelse p.eatToken(.caret_equal);
    const bit_or = bit_xor orelse p.eatToken(.pipe_equal);

    if (bit_or == null) return lhs;
    if (!Tree.isLval(p.nodes.slice(), lhs.node)) {
        try p.errTok(.not_assignable, tok);
        return error.ParsingFailed;
    }
    var rhs = try p.assignExpr();

    try lhs.bin(p, if (eq != null)
        .assign_expr
    else if (mul != null)
        Tree.Tag.mul_assign_expr
    else if (div != null)
        Tree.Tag.div_assign_expr
    else if (mod != null)
        Tree.Tag.mod_assign_expr
    else if (add != null)
        Tree.Tag.add_assign_expr
    else if (sub != null)
        Tree.Tag.sub_assign_expr
    else if (shl != null)
        Tree.Tag.shl_assign_expr
    else if (shr != null)
        Tree.Tag.shr_assign_expr
    else if (bit_and != null)
        Tree.Tag.bit_and_assign_expr
    else if (bit_xor != null)
        Tree.Tag.bit_xor_assign_expr
    else
        Tree.Tag.bit_or_assign_expr, rhs);
    return lhs;
}

/// constExpr : condExpr
fn constExpr(p: *Parser) Error!Result {
    const res = try p.condExpr();
    try res.expect(p);
    return res;
}

/// condExpr : lorExpr ('?' expression? ':' condExpr)?
fn condExpr(p: *Parser) Error!Result {
    var cond = try p.lorExpr();
    if (p.eatToken(.question_mark) == null) return cond;
    const saved_eval = p.no_eval;

    // Depending on the value of the condition, avoid evaluating unreachable branches.
    const then_expr = blk: {
        defer p.no_eval = saved_eval;
        if (cond.val != .unavailable and !cond.getBool()) p.no_eval = true;
        break :blk try p.expr();
    };
    _ = try p.expectToken(.colon);
    const else_expr = blk: {
        defer p.no_eval = saved_eval;
        if (cond.val != .unavailable and cond.getBool()) p.no_eval = true;
        break :blk try p.condExpr();
    };

    if (cond.val != .unavailable) {
        cond.val = if (cond.getBool()) then_expr.val else else_expr.val;
    }
    cond.node = try p.addNode(.{
        .tag = .cond_expr,
        .ty = then_expr.ty, // TODO resolve type properly
        .data = .{ .if3 = .{ .cond = cond.node, .body = (try p.addList(&.{ then_expr.node, else_expr.node })).start } },
    });
    return cond;
}

/// lorExpr : landExpr ('||' landExpr)*
fn lorExpr(p: *Parser) Error!Result {
    var lhs = try p.landExpr();
    const saved_eval = p.no_eval;
    defer p.no_eval = saved_eval;

    while (p.eatToken(.pipe_pipe)) |_| {
        if (lhs.val != .unavailable and lhs.getBool()) p.no_eval = true;
        const rhs = try p.landExpr();

        if (lhs.val != .unavailable and rhs.val != .unavailable) {
            lhs.val = .{ .signed = @boolToInt(lhs.getBool() or rhs.getBool()) };
        }
        lhs.ty = .{ .specifier = .int };
        try lhs.bin(p, .bool_or_expr, rhs);
    }
    return lhs;
}

/// landExpr : orExpr ('&&' orExpr)*
fn landExpr(p: *Parser) Error!Result {
    var lhs = try p.orExpr();
    const saved_eval = p.no_eval;
    defer p.no_eval = saved_eval;

    while (p.eatToken(.ampersand_ampersand)) |_| {
        if (lhs.val != .unavailable and lhs.getBool()) p.no_eval = true;
        const rhs = try p.orExpr();

        if (lhs.val != .unavailable and rhs.val != .unavailable) {
            lhs.val = .{ .signed = @boolToInt(lhs.getBool() and rhs.getBool()) };
        }
        lhs.ty = .{ .specifier = .int };
        try lhs.bin(p, .bool_and_expr, rhs);
    }
    return lhs;
}

/// orExpr : xorExpr ('|' xorExpr)*
fn orExpr(p: *Parser) Error!Result {
    var lhs = try p.xorExpr();
    while (p.eatToken(.pipe)) |_| {
        var rhs = try p.xorExpr();

        if (try lhs.adjustTypes(&rhs, p)) {
            lhs.val = switch (lhs.val) {
                .unsigned => |v| .{ .unsigned = v | rhs.val.unsigned },
                .signed => |v| .{ .signed = v | rhs.val.signed },
                else => unreachable,
            };
        }
        try lhs.bin(p, .bit_or_expr, rhs);
    }
    return lhs;
}

/// xorExpr : andExpr ('^' andExpr)*
fn xorExpr(p: *Parser) Error!Result {
    var lhs = try p.andExpr();
    while (p.eatToken(.caret)) |_| {
        var rhs = try p.andExpr();

        if (try lhs.adjustTypes(&rhs, p)) {
            lhs.val = switch (lhs.val) {
                .unsigned => |v| .{ .unsigned = v ^ rhs.val.unsigned },
                .signed => |v| .{ .signed = v ^ rhs.val.signed },
                else => unreachable,
            };
        }
        try lhs.bin(p, .bit_xor_expr, rhs);
    }
    return lhs;
}

/// andExpr : eqExpr ('&' eqExpr)*
fn andExpr(p: *Parser) Error!Result {
    var lhs = try p.eqExpr();
    while (p.eatToken(.ampersand)) |_| {
        var rhs = try p.eqExpr();

        if (try lhs.adjustTypes(&rhs, p)) {
            lhs.val = switch (lhs.val) {
                .unsigned => |v| .{ .unsigned = v & rhs.val.unsigned },
                .signed => |v| .{ .signed = v & rhs.val.signed },
                else => unreachable,
            };
        }
        try lhs.bin(p, .bit_and_expr, rhs);
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
        var rhs = try p.compExpr();

        if (try lhs.adjustTypes(&rhs, p)) {
            const res = if (eq != null)
                lhs.compare(.eq, rhs)
            else
                lhs.compare(.neq, rhs);

            lhs.val = .{ .signed = @boolToInt(res) };
        }
        lhs.ty = .{ .specifier = .int };
        try lhs.bin(p, if (eq != null) .equal_expr else .not_equal_expr, rhs);
    }
    return lhs;
}

/// compExpr : shiftExpr (('<' | '<=' | '>' | '>=') shiftExpr)*
fn compExpr(p: *Parser) Error!Result {
    var lhs = try p.shiftExpr();
    while (true) {
        const lt = p.eatToken(.angle_bracket_left);
        const le = lt orelse p.eatToken(.angle_bracket_left_equal);
        const gt = le orelse p.eatToken(.angle_bracket_right);
        const ge = gt orelse p.eatToken(.angle_bracket_right_equal);
        if (ge == null) break;
        var rhs = try p.shiftExpr();

        if (try lhs.adjustTypes(&rhs, p)) {
            const res = if (lt != null)
                lhs.compare(.lt, rhs)
            else if (le != null)
                lhs.compare(.lte, rhs)
            else if (gt != null)
                lhs.compare(.gt, rhs)
            else
                lhs.compare(.gte, rhs);
            lhs.val = .{ .signed = @boolToInt(res) };
        }
        lhs.ty = .{ .specifier = .int };
        try lhs.bin(p, if (lt != null)
            .less_than_expr
        else if (le != null)
            Tree.Tag.less_than_equal_expr
        else if (gt != null)
            Tree.Tag.greater_than_expr
        else
            Tree.Tag.greater_than_equal_expr, rhs);
    }
    return lhs;
}

/// shiftExpr : addExpr (('<<' | '>>') addExpr)*
fn shiftExpr(p: *Parser) Error!Result {
    var lhs = try p.addExpr();
    while (true) {
        const shl = p.eatToken(.angle_bracket_angle_bracket_left);
        const shr = shl orelse p.eatToken(.angle_bracket_angle_bracket_right);
        if (shr == null) break;
        var rhs = try p.addExpr();

        if (try lhs.adjustTypes(&rhs, p)) {
            // TODO overflow
            if (shl != null) {
                lhs.val = switch (lhs.val) {
                    .unsigned => |v| .{ .unsigned = v << @intCast(u6, rhs.val.unsigned) },
                    .signed => |v| .{ .signed = v << @intCast(u6, rhs.val.signed) },
                    else => unreachable,
                };
            } else {
                lhs.val = switch (lhs.val) {
                    .unsigned => |v| .{ .unsigned = v >> @intCast(u6, rhs.val.unsigned) },
                    .signed => |v| .{ .signed = v >> @intCast(u6, rhs.val.signed) },
                    else => unreachable,
                };
            }
        }
        try lhs.bin(p, if (shl != null) .shl_expr else .shr_expr, rhs);
    }
    return lhs;
}

/// addExpr : mulExpr (('+' | '-') mulExpr)*
fn addExpr(p: *Parser) Error!Result {
    var lhs = try p.mulExpr();
    while (true) {
        const plus = p.eatToken(.plus);
        const minus = plus orelse p.eatToken(.minus);
        if (minus == null) break;
        var rhs = try p.mulExpr();

        if (try lhs.adjustTypes(&rhs, p)) {
            if (plus != null) {
                try lhs.add(plus.?, rhs, p);
            } else {
                try lhs.sub(minus.?, rhs, p);
            }
        }
        try lhs.bin(p, if (plus != null) .add_expr else .sub_expr, rhs);
    }
    return lhs;
}

/// mulExpr : castExpr (('*' | '/' | '%') castExpr)*´
fn mulExpr(p: *Parser) Error!Result {
    var lhs = try p.castExpr();
    while (true) {
        const mul = p.eatToken(.asterisk);
        const div = mul orelse p.eatToken(.slash);
        const percent = div orelse p.eatToken(.percent);
        if (percent == null) break;
        var rhs = try p.castExpr();

        if (try lhs.adjustTypes(&rhs, p)) {
            // TODO divide by zero
            if (mul != null) {
                try lhs.mul(mul.?, rhs, p);
            } else if (div != null) {
                lhs.val = switch (lhs.val) {
                    .unsigned => |v| .{ .unsigned = v / rhs.val.unsigned },
                    .signed => |v| .{ .signed = @divFloor(v, rhs.val.signed) },
                    else => unreachable,
                };
            } else {
                lhs.val = switch (lhs.val) {
                    .unsigned => |v| .{ .unsigned = v % rhs.val.unsigned },
                    .signed => |v| .{ .signed = @rem(v, rhs.val.signed) },
                    else => unreachable,
                };
            }
        }

        try lhs.bin(p, if (mul != null)
            .mul_expr
        else if (div != null)
            Tree.Tag.div_expr
        else
            Tree.Tag.mod_expr, rhs);
    }
    return lhs;
}

/// castExpr
///  :  '(' typeName ')' castExpr
///  | '(' typeName ')' '{' initializerItems '}'
///  | unExpr
fn castExpr(p: *Parser) Error!Result {
    if (p.eatToken(.l_paren)) |l_paren| {
        if (try p.typeName()) |ty| {
            try p.expectClosing(l_paren, .r_paren);
            if (p.eatToken(.l_brace)) |l_brace| {
                var initializers = NodeList.init(p.pp.comp.gpa);
                defer initializers.deinit();

                while (try p.initializerItem(ty)) |item| {
                    try initializers.append(item);
                    if (p.eatToken(.comma) == null) break;
                }
                try p.expectClosing(l_brace, .r_brace);

                var node: Tree.Node = .{
                    .tag = .compound_literal_expr_two,
                    .ty = ty,
                    .data = .{ .bin = .{ .lhs = .none, .rhs = .none } },
                };
                switch (initializers.items.len) {
                    0 => {},
                    1 => node.data = .{ .bin = .{ .lhs = initializers.items[0], .rhs = .none } },
                    2 => node.data = .{ .bin = .{ .lhs = initializers.items[0], .rhs = initializers.items[1] } },
                    else => {
                        node.tag = .compound_literal_expr;
                        node.data = .{ .range = try p.addList(initializers.items) };
                    },
                }
                return Result{ .node = try p.addNode(node), .ty = ty };
            }
            var operand = try p.castExpr();
            operand.ty = ty;
            return operand.un(p, .cast_expr);
        }
        p.tok_i -= 1;
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
    const tok = p.tok_i;
    switch (p.tok_ids[tok]) {
        .ampersand => {
            p.tok_i += 1;
            var operand = try p.castExpr();

            if (!Tree.isLval(p.nodes.slice(), operand.node)) {
                try p.errTok(.addr_of_rvalue, tok);
                return error.ParsingFailed;
            }

            const elem_ty = try p.arena.create(Type);
            elem_ty.* = operand.ty;
            operand.ty = Type{
                .specifier = .pointer,
                .data = .{ .sub_type = elem_ty },
            };
            return operand.un(p, .addr_of_expr);
        },
        .asterisk => {
            p.tok_i += 1;
            var operand = try p.castExpr();

            switch (operand.ty.specifier) {
                .pointer => {
                    operand.ty = operand.ty.data.sub_type.*;
                },
                .array, .static_array => {
                    operand.ty = operand.ty.data.array.elem;
                },
                .func, .var_args_func, .old_style_func => {},
                else => {
                    try p.errTok(.indirection_ptr, tok);
                    return error.ParsingFailed;
                },
            }
            return operand.un(p, .deref_expr);
        },
        .plus => {
            p.tok_i += 1;
            // TODO upcast to int / validate arithmetic type
            return p.castExpr();
        },
        .minus => {
            p.tok_i += 1;
            // TODO upcast to int / validate arithmetic type
            var operand = try p.castExpr();
            const size = operand.ty.sizeof(p.pp.comp);
            switch (operand.val) {
                .unsigned => |*v| switch (size) {
                    1, 2, 4 => v.* = @truncate(u32, 0 -% v.*),
                    8 => v.* = 0 -% v.*,
                    else => unreachable,
                },
                .signed => |*v| switch (size) {
                    1, 2, 4 => v.* = @truncate(i32, 0 -% v.*),
                    8 => v.* = 0 -% v.*,
                    else => unreachable,
                },
                .unavailable => {},
            }
            return operand.un(p, .negate_expr);
        },
        .plus_plus => {
            p.tok_i += 1;
            // TODO upcast to int / validate arithmetic type
            var operand = try p.castExpr();

            if (!Tree.isLval(p.nodes.slice(), operand.node)) {
                try p.errTok(.not_assignable, tok);
                return error.ParsingFailed;
            }

            // TODO overflow
            switch (operand.val) {
                .unsigned => |*v| v.* += 1,
                .signed => |*v| v.* += 1,
                .unavailable => {},
            }

            return operand.un(p, .pre_inc_expr);
        },
        .minus_minus => {
            p.tok_i += 1;
            // TODO upcast to int / validate arithmetic type
            var operand = try p.castExpr();

            if (!Tree.isLval(p.nodes.slice(), operand.node)) {
                try p.errTok(.not_assignable, tok);
                return error.ParsingFailed;
            }

            // TODO overflow
            switch (operand.val) {
                .unsigned => |*v| v.* -= 1,
                .signed => |*v| v.* -= 1,
                .unavailable => {},
            }

            return operand.un(p, .pre_dec_expr);
        },
        .tilde => {
            p.tok_i += 1;
            // TODO upcast to int / validate arithmetic type
            var operand = try p.unExpr();

            switch (operand.val) {
                .unsigned => |*v| v.* = ~v.*,
                .signed => |*v| v.* = ~v.*,
                .unavailable => {},
            }

            return operand.un(p, .bool_not_expr);
        },
        .bang => {
            p.tok_i += 1;
            var operand = try p.unExpr();
            if (operand.val != .unavailable) {
                operand.val = .{ .signed = @boolToInt(!operand.getBool()) };
            }
            operand.ty = .{ .specifier = .int };
            return operand.un(p, .bool_not_expr);
        },
        .keyword_sizeof => {
            p.tok_i += 1;
            const expected_paren = p.tok_i;
            var res = Result{};
            if (try p.typeName()) |ty| {
                res.ty = ty;
                try p.errTok(.expected_parens_around_typename, expected_paren);
            } else if (p.eatToken(.l_paren)) |l_paren| {
                if (try p.typeName()) |ty| {
                    res.ty = ty;
                    try p.expectClosing(l_paren, .r_paren);
                } else {
                    p.tok_i = expected_paren;
                    res = try p.unExpr();
                }
            } else {
                res = try p.unExpr();
            }

            res.val = .{ .unsigned = res.ty.sizeof(p.pp.comp) };
            return res.un(p, .sizeof_expr);
        },
        .keyword_alignof, .keyword_alignof1, .keywrod_alignof2 => {
            p.tok_i += 1;
            const expected_paren = p.tok_i;
            var res = Result{};
            if (try p.typeName()) |ty| {
                res.ty = ty;
                try p.errTok(.expected_parens_around_typename, expected_paren);
            } else if (p.eatToken(.l_paren)) |l_paren| {
                if (try p.typeName()) |ty| {
                    res.ty = ty;
                    try p.expectClosing(l_paren, .r_paren);
                } else {
                    p.tok_i = expected_paren;
                    res = try p.unExpr();
                    try p.errTok(.alignof_expr, expected_paren);
                }
            } else {
                res = try p.unExpr();
                try p.errTok(.alignof_expr, expected_paren);
            }

            res.val = .{ .unsigned = res.ty.alignment };
            return res.un(p, .alignof_expr);
        },
        else => {
            var lhs = try p.primaryExpr();
            while (true) {
                const suffix = try p.suffixExpr(lhs);
                if (suffix.node == .none) break;
                lhs = suffix;
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
/// argumentExprList : assignExpr (',' assignExpr)*
fn suffixExpr(p: *Parser, lhs: Result) Error!Result {
    switch (p.tok_ids[p.tok_i]) {
        .l_paren => {
            const l_paren = p.tok_i;
            p.tok_i += 1;
            const ty = lhs.ty.isCallable() orelse {
                try p.errStr(.not_callable, l_paren, Type.Builder.fromType(lhs.ty).str());
                return error.ParsingFailed;
            };
            const params = ty.data.func.params;

            var args = NodeList.init(p.pp.comp.gpa);
            defer args.deinit();

            var first_after = l_paren;
            if (p.eatToken(.r_paren) == null) {
                while (true) {
                    if (args.items.len == params.len) first_after = p.tok_i;
                    const arg = try p.assignExpr();
                    try arg.expect(p);

                    if (args.items.len < params.len) {
                        const casted = try arg.coerce(p, params[args.items.len].ty);
                        try args.append(casted.node);
                    } else {
                        // TODO coerce to var args passable type
                        try args.append(arg.node);
                    }

                    _ = p.eatToken(.comma) orelse break;
                }
                try p.expectClosing(l_paren, .r_paren);
            }

            const extra = Diagnostics.Message.Extra{ .arguments = .{
                .expected = @intCast(u32, params.len),
                .actual = @intCast(u32, args.items.len),
            } };
            if (ty.specifier == .func and params.len != args.items.len) {
                try p.errExtra(.expected_arguments, first_after, extra);
            }
            if (ty.specifier == .old_style_func and params.len != args.items.len) {
                try p.errExtra(.expected_arguments_old, first_after, extra);
            }
            if (ty.specifier == .var_args_func and args.items.len < params.len) {
                try p.errExtra(.expected_at_least_arguments, first_after, extra);
            }

            var call_node: Tree.Node = .{
                .tag = .call_expr_one,
                .ty = ty.data.func.return_type,
                .data = .{ .bin = .{ .lhs = lhs.node, .rhs = .none } },
            };
            switch (args.items.len) {
                0 => {},
                1 => call_node.data.bin.rhs = args.items[0],
                else => {
                    call_node.tag = .call_expr;
                    try p.data.append(lhs.node);
                    call_node.data = .{ .range = try p.addList(args.items) };
                },
            }
            return Result{ .node = try p.addNode(call_node), .ty = call_node.ty };
        },
        .plus_plus => {
            defer p.tok_i += 1;
            // TODO upcast to int / validate arithmetic type
            var operand = lhs;

            if (!Tree.isLval(p.nodes.slice(), operand.node)) {
                try p.err(.not_assignable);
                return error.ParsingFailed;
            }

            return operand.un(p, .post_dec_expr);
        },
        .minus_minus => {
            defer p.tok_i += 1;
            // TODO upcast to int / validate arithmetic type
            var operand = lhs;

            if (!Tree.isLval(p.nodes.slice(), operand.node)) {
                try p.err(.not_assignable);
                return error.ParsingFailed;
            }

            return operand.un(p, .post_dec_expr);
        },
        .l_bracket => {
            var operand = lhs;

            const l_bracket = p.tok_i;
            p.tok_i += 1;
            const index = try p.expr();
            try p.expectClosing(l_bracket, .r_bracket);

            // TODO validate type
            try operand.bin(p, .array_access_expr, index);
            return operand;
        },
        .period => {
            p.tok_i += 1;
            const name = try p.expectToken(.identifier);
            // TODO validate type
            return Result{
                .ty = lhs.ty,
                .node = try p.addNode(.{
                    .tag = .member_access_expr,
                    .ty = lhs.ty,
                    .data = .{ .member = .{ .lhs = lhs.node, .name = name } },
                }),
            };
        },
        .arrow => {
            p.tok_i += 1;
            const name = try p.expectToken(.identifier);
            // TODO validate type / deref
            return Result{
                .ty = lhs.ty,
                .node = try p.addNode(.{
                    .tag = .member_access_ptr_expr,
                    .ty = lhs.ty,
                    .data = .{ .member = .{ .lhs = lhs.node, .name = name } },
                }),
            };
        },
        else => return Result{},
    }
}

/// primaryExpr
///  : IDENTIFIER
///  | INTEGER_LITERAL
///  | FLOAT_LITERAL
///  | CHAR_LITERAL
///  | STRING_LITERAL
///  | '(' expr ')'
///  | keyword_generic '(' assignExpr ',' genericAssoc (',' genericAssoc)* ')'
///
/// genericAssoc
///  : typeName ':' assignExpr
///  | keyword_default ':' assignExpr
fn primaryExpr(p: *Parser) Error!Result {
    if (p.eatToken(.l_paren)) |l_paren| {
        var e = try p.expr();
        try p.expectClosing(l_paren, .r_paren);
        return e.un(p, .paren_expr);
    }
    switch (p.tok_ids[p.tok_i]) {
        .identifier => {
            const name_tok = p.tok_i;
            p.tok_i += 1;
            const sym = p.findSymbol(name_tok) orelse {
                if (p.tok_ids[p.tok_i] == .l_paren) {
                    // implicitly declare simple functions as like `puts("foo")`;
                    const name = p.tokSlice(name_tok);
                    try p.errStr(.implicit_func_decl, name_tok, name);

                    const func_ty = try p.arena.create(Type.Func);
                    func_ty.* = .{ .return_type = .{ .specifier = .int }, .params = &.{} };
                    const ty: Type = .{ .specifier = .old_style_func, .data = .{ .func = func_ty } };
                    const node = try p.addNode(.{
                        .ty = ty,
                        .tag = .fn_proto,
                        .data = .{ .decl = .{ .name = name_tok } },
                    });

                    try p.cur_decl_list.append(node);
                    try p.scopes.append(.{ .symbol = .{
                        .name = name,
                        .ty = ty,
                        .name_tok = name_tok,
                    } });

                    return Result{
                        .ty = ty,
                        .node = try p.addNode(.{
                            .tag = .decl_ref_expr,
                            .ty = ty,
                            .data = .{ .decl_ref = name_tok },
                        }),
                    };
                }
                try p.errStr(.undeclared_identifier, name_tok, p.tokSlice(name_tok));
                return error.ParsingFailed;
            };
            switch (sym) {
                .enumeration => |e| {
                    // TODO actually check type
                    var res = e.value;
                    res.node = try p.addNode(.{
                        .tag = .enumeration_ref,
                        .ty = res.ty,
                        .data = .{ .decl_ref = name_tok },
                    });
                    return res;
                },
                .symbol => |s| {
                    // TODO actually check type
                    return Result{
                        .ty = s.ty,
                        .node = try p.addNode(.{
                            .tag = .decl_ref_expr,
                            .ty = s.ty,
                            .data = .{ .decl_ref = name_tok },
                        }),
                    };
                },
                else => unreachable,
            }
        },
        .string_literal,
        .string_literal_utf_16,
        .string_literal_utf_8,
        .string_literal_utf_32,
        .string_literal_wide,
        => return p.stringLiteral(),
        .char_literal,
        .char_literal_utf_16,
        .char_literal_utf_32,
        .char_literal_wide,
        => {
            return p.todo("char literals");
        },
        .float_literal,
        .float_literal_f,
        .float_literal_l,
        => {
            return p.todo("float literals");
        },
        .zero => {
            p.tok_i += 1;
            var res: Result = .{ .val = .{ .signed = 0 } };
            res.node = try p.addNode(.{ .tag = .int_literal, .ty = res.ty, .data = .{ .int = 0 } });
            return res;
        },
        .one => {
            p.tok_i += 1;
            var res: Result = .{ .val = .{ .signed = 1 } };
            res.node = try p.addNode(.{ .tag = .int_literal, .ty = res.ty, .data = .{ .int = 1 } });
            return res;
        },
        .integer_literal,
        .integer_literal_u,
        .integer_literal_l,
        .integer_literal_lu,
        .integer_literal_ll,
        .integer_literal_llu,
        => {
            const id = p.tok_ids[p.tok_i];
            var slice = p.tokSlice(p.tok_i);
            defer p.tok_i += 1;
            var base: u8 = 10;
            if (mem.startsWith(u8, slice, "0x") or mem.startsWith(u8, slice, "0X")) {
                slice = slice[2..];
                base = 10;
            } else if (mem.startsWith(u8, slice, "0b") or mem.startsWith(u8, slice, "0B")) {
                slice = slice[2..];
                base = 2;
            } else if (slice[0] == '0') {
                base = 8;
            }
            switch (id) {
                .integer_literal_u, .integer_literal_l => slice = slice[0 .. slice.len - 1],
                .integer_literal_lu, .integer_literal_ll => slice = slice[0 .. slice.len - 2],
                .integer_literal_llu => slice = slice[0 .. slice.len - 3],
                else => {},
            }

            var val: u64 = 0;
            var overflow = false;
            for (slice) |c| {
                const digit: u64 = switch (c) {
                    '0'...'9' => c - '0',
                    'A'...'Z' => c - 'A' + 10,
                    'a'...'z' => c - 'a' + 10,
                    else => unreachable,
                };

                if (val != 0 and @mulWithOverflow(u64, val, base, &val)) overflow = true;
                if (@addWithOverflow(u64, val, digit, &val)) overflow = true;
            }
            if (overflow) {
                try p.err(.int_literal_too_big);
                var res: Result = .{ .ty = .{ .specifier = .ulong_long }, .val = .{ .unsigned = val } };
                res.node = try p.addNode(.{ .tag = .int_literal, .ty = res.ty, .data = .{ .int = val } });
                return res;
            }

            if (base == 10) {
                switch (id) {
                    .integer_literal => return p.castInt(val, &.{ .int, .long, .long_long }),
                    .integer_literal_u => return p.castInt(val, &.{ .uint, .ulong, .ulong_long }),
                    .integer_literal_l => return p.castInt(val, &.{ .long, .long_long }),
                    .integer_literal_lu => return p.castInt(val, &.{ .ulong, .ulong_long }),
                    .integer_literal_ll => return p.castInt(val, &.{.long_long}),
                    .integer_literal_llu => return p.castInt(val, &.{.ulong_long}),
                    else => unreachable,
                }
            } else {
                switch (id) {
                    .integer_literal => return p.castInt(val, &.{ .int, .uint, .long, .ulong, .long_long, .ulong_long }),
                    .integer_literal_u => return p.castInt(val, &.{ .uint, .ulong, .ulong_long }),
                    .integer_literal_l => return p.castInt(val, &.{ .long, .ulong, .long_long, .ulong_long }),
                    .integer_literal_lu => return p.castInt(val, &.{ .ulong, .ulong_long }),
                    .integer_literal_ll => return p.castInt(val, &.{ .long_long, .ulong_long }),
                    .integer_literal_llu => return p.castInt(val, &.{.ulong_long}),
                    else => unreachable,
                }
            }
        },
        .keyword_generic => {
            return p.todo("generic");
        },
        else => return Result{},
    }
}

fn castInt(p: *Parser, val: u64, specs: []const Type.Specifier) Error!Result {
    var res: Result = .{};
    for (specs) |spec| {
        const ty = Type{ .specifier = spec };
        const unsigned = ty.isUnsignedInt(p.pp.comp);
        const size = ty.sizeof(p.pp.comp);
        res.ty = ty;

        if (unsigned) {
            res.val = .{ .unsigned = val };
            switch (size) {
                2 => if (val <= std.math.maxInt(u16)) break,
                4 => if (val <= std.math.maxInt(u32)) break,
                8 => if (val <= std.math.maxInt(u64)) break,
                else => unreachable,
            }
        } else {
            res.val = .{ .signed = @bitCast(i64, val) };
            switch (size) {
                2 => if (val <= std.math.maxInt(i16)) break,
                4 => if (val <= std.math.maxInt(i32)) break,
                8 => if (val <= std.math.maxInt(i64)) break,
                else => unreachable,
            }
        }
    } else {
        res.ty = .{ .specifier = .ulong_long };
    }
    res.node = try p.addNode(.{ .tag = .int_literal, .ty = res.ty, .data = .{ .int = val } });
    return res;
}

fn stringLiteral(p: *Parser) Error!Result {
    var start = p.tok_i;
    // use 1 for wchar_t
    var width: ?u8 = null;
    while (true) {
        switch (p.tok_ids[p.tok_i]) {
            .string_literal => {},
            .string_literal_utf_16 => if (width) |some| {
                if (some != 16) try p.err(.unsupported_str_cat);
            } else {
                width = 16;
            },
            .string_literal_utf_8 => if (width) |some| {
                if (some != 8) try p.err(.unsupported_str_cat);
            } else {
                width = 8;
            },
            .string_literal_utf_32 => if (width) |some| {
                if (some != 32) try p.err(.unsupported_str_cat);
            } else {
                width = 32;
            },
            .string_literal_wide => if (width) |some| {
                if (some != 1) try p.err(.unsupported_str_cat);
            } else {
                width = 1;
            },
            else => break,
        }
        p.tok_i += 1;
    }
    if (width == null) width = 8;
    if (width.? != 8) return p.todo("non-utf8 strings");
    const index = p.strings.items.len;
    while (start < p.tok_i) : (start += 1) {
        var slice = p.tokSlice(start);
        slice = slice[mem.indexOf(u8, slice, "\"").? + 1 .. slice.len - 1];
        var i: u32 = 0;
        try p.strings.ensureUnusedCapacity(slice.len);
        while (i < slice.len) : (i += 1) {
            switch (slice[i]) {
                '\\' => {
                    i += 1;
                    switch (slice[i]) {
                        '\n' => i += 1,
                        '\r' => i += 2,
                        '\'', '\"', '\\', '?' => |c| p.strings.appendAssumeCapacity(c),
                        'n' => p.strings.appendAssumeCapacity('\n'),
                        'r' => p.strings.appendAssumeCapacity('\r'),
                        't' => p.strings.appendAssumeCapacity('\t'),
                        'a' => p.strings.appendAssumeCapacity(0x07),
                        'b' => p.strings.appendAssumeCapacity(0x08),
                        'e' => p.strings.appendAssumeCapacity(0x1B),
                        'f' => p.strings.appendAssumeCapacity(0x0C),
                        'v' => p.strings.appendAssumeCapacity(0x0B),
                        'x' => return p.todo("hex escape"),
                        'u' => return p.todo("u escape"),
                        'U' => return p.todo("U escape"),
                        '0'...'7' => return p.todo("octal escape"),
                        else => unreachable,
                    }
                },
                else => |c| p.strings.appendAssumeCapacity(c),
            }
        }
    }
    try p.strings.append(0);
    const len = p.strings.items.len - index;

    const arr_ty = try p.arena.create(Type.Array);
    arr_ty.* = .{ .elem = .{ .specifier = .char }, .len = len };
    var res: Result = .{
        .ty = .{
            .specifier = .array,
            .data = .{ .array = arr_ty },
        },
    };
    res.node = try p.addNode(.{
        .tag = .string_literal_expr,
        .ty = res.ty,
        .data = .{ .str = .{ .index = @intCast(u32, index), .len = @intCast(u32, len) } },
    });
    return res;
}
