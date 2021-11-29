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
const InitList = @import("InitList.zig");
const Attribute = @import("Attribute.zig");
const CharInfo = @import("CharInfo.zig");

const Parser = @This();

const Scope = union(enum) {
    typedef: Symbol,
    @"struct": Symbol,
    @"union": Symbol,
    @"enum": Symbol,
    decl: Symbol,
    def: Symbol,
    param: Symbol,
    enumeration: Enumeration,
    loop,
    @"switch": *Switch,
    block,

    const Symbol = struct {
        name: []const u8,
        ty: Type,
        name_tok: TokenIndex,
    };

    const Enumeration = struct {
        name: []const u8,
        value: Result,
        name_tok: TokenIndex,
    };

    const Switch = struct {
        cases: CaseMap,
        default: ?Case = null,

        const ResultContext = struct {
            pub fn eql(_: ResultContext, a: Result, b: Result) bool {
                return a.as_u64() == b.as_u64();
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

// values from preprocessor
pp: *Preprocessor,
tok_ids: []const Token.Id,
tok_i: TokenIndex = 0,

// values of the incomplete Tree
arena: *Allocator,
nodes: Tree.Node.List = .{},
data: NodeList,
strings: std.ArrayList(u8),
value_map: Tree.ValueMap,

// buffers used during compilation
scopes: std.ArrayList(Scope),
labels: std.ArrayList(Label),
list_buf: NodeList,
decl_buf: NodeList,
param_buf: std.ArrayList(Type.Func.Param),
enum_buf: std.ArrayList(Type.Enum.Field),
record_buf: std.ArrayList(Type.Record.Field),
attr_buf: std.ArrayList(Attribute),

// configuration and miscellaneous info
no_eval: bool = false,
in_macro: bool = false,
extension_suppressed: bool = false,
contains_address_of_label: bool = false,
return_type: ?Type = null,
func_name: TokenIndex = 0,
label_count: u32 = 0,
/// location of first computed goto in function currently being parsed
/// if a computed goto is used, the function must contain an
/// address-of-label expression (tracked with contains_address_of_label)
computed_goto_tok: ?TokenIndex = null,

fn checkIdentifierCodepoint(comp: *Compilation, codepoint: u21, loc: Source.Location) Compilation.Error!bool {
    if (codepoint <= 0x7F) return false;
    var diagnosed = false;
    if (!CharInfo.isC99IdChar(codepoint)) {
        try comp.diag.add(.{
            .tag = .c99_compat,
            .loc = loc,
        });
        diagnosed = true;
    }
    if (CharInfo.isInvisible(codepoint)) {
        try comp.diag.add(.{
            .tag = .unicode_zero_width,
            .loc = loc,
            .extra = .{ .actual_codepoint = codepoint },
        });
        diagnosed = true;
    }
    if (CharInfo.homoglyph(codepoint)) |resembles| {
        try comp.diag.add(.{
            .tag = .unicode_homoglyph,
            .loc = loc,
            .extra = .{ .codepoints = .{ .actual = codepoint, .resembles = resembles } },
        });
        diagnosed = true;
    }
    return diagnosed;
}

fn eatIdentifier(p: *Parser) !?TokenIndex {
    if (p.tok_ids[p.tok_i] == .identifier) {
        defer p.tok_i += 1;
        return p.tok_i;
    } else if (p.tok_ids[p.tok_i] == .extended_identifier) {
        defer p.tok_i += 1;
        const slice = p.tokSlice(p.tok_i);
        var it = std.unicode.Utf8View.initUnchecked(slice).iterator();
        var loc = p.pp.tokens.items(.loc)[p.tok_i];
        while (it.nextCodepoint()) |c| {
            if (try checkIdentifierCodepoint(p.pp.comp, c, loc)) break;
            loc.byte_offset += std.unicode.utf8CodepointSequenceLength(c) catch unreachable;
        }
        return p.tok_i;
    }
    return null;
}

fn expectIdentifier(p: *Parser) Error!TokenIndex {
    if (p.tok_ids[p.tok_i] != .identifier and p.tok_ids[p.tok_i] != .extended_identifier) {
        try p.errExtra(.expected_token, p.tok_i, .{ .tok_id = .{
            .expected = .identifier,
            .actual = p.tok_ids[p.tok_i],
        } });
        return error.ParsingFailed;
    }
    return (try p.eatIdentifier()) orelse unreachable;
}

fn eatToken(p: *Parser, id: Token.Id) ?TokenIndex {
    assert(id != .identifier and id != .extended_identifier); // use eatIdentifier
    if (p.tok_ids[p.tok_i] == id) {
        defer p.tok_i += 1;
        return p.tok_i;
    } else return null;
}

fn expectToken(p: *Parser, expected: Token.Id) Error!TokenIndex {
    assert(expected != .identifier and expected != .extended_identifier); // use expectIdentifier
    const actual = p.tok_ids[p.tok_i];
    if (actual != expected) {
        switch (actual) {
            .invalid => try p.errExtra(.expected_invalid, p.tok_i, .{ .tok_id_expected = expected }),
            else => try p.errExtra(.expected_token, p.tok_i, .{ .tok_id = .{
                .expected = expected,
                .actual = actual,
            } }),
        }
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
        .comp = p.pp.comp,
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

pub fn ignoredAttrStr(p: *Parser, attr: Attribute.Tag, context: Attribute.ParseContext) ![]const u8 {
    const strings_top = p.strings.items.len;
    defer p.strings.items.len = strings_top;

    try p.strings.writer().print("Attribute '{s}' ignored in {s} context", .{ @tagName(attr), @tagName(context) });
    return try p.arena.dupe(u8, p.strings.items[strings_top..]);
}

pub fn typeStr(p: *Parser, ty: Type) ![]const u8 {
    if (Type.Builder.fromType(ty).str()) |str| return str;
    const strings_top = p.strings.items.len;
    defer p.strings.items.len = strings_top;

    try ty.print(p.strings.writer());
    return try p.arena.dupe(u8, p.strings.items[strings_top..]);
}

pub fn typePairStr(p: *Parser, a: Type, b: Type) ![]const u8 {
    return p.typePairStrExtra(a, " and ", b);
}

pub fn typePairStrExtra(p: *Parser, a: Type, msg: []const u8, b: Type) ![]const u8 {
    const strings_top = p.strings.items.len;
    defer p.strings.items.len = strings_top;

    try p.strings.append('\'');
    try a.print(p.strings.writer());
    try p.strings.append('\'');
    try p.strings.appendSlice(msg);
    try p.strings.append('\'');
    try b.print(p.strings.writer());
    try p.strings.append('\'');
    return try p.arena.dupe(u8, p.strings.items[strings_top..]);
}

fn addNode(p: *Parser, node: Tree.Node) Allocator.Error!NodeIndex {
    if (p.in_macro) return .none;
    const res = p.nodes.len;
    try p.nodes.append(p.pp.comp.gpa, node);
    return @intToEnum(NodeIndex, res);
}

fn addList(p: *Parser, nodes: []const NodeIndex) Allocator.Error!Tree.Node.Range {
    if (p.in_macro) return Tree.Node.Range{ .start = 0, .end = 0 };
    const start = @intCast(u32, p.data.items.len);
    try p.data.appendSlice(nodes);
    const end = @intCast(u32, p.data.items.len);
    return Tree.Node.Range{ .start = start, .end = end };
}

fn findTypedef(p: *Parser, name_tok: TokenIndex, no_type_yet: bool) !?Scope.Symbol {
    const name = p.tokSlice(name_tok);
    var i = p.scopes.items.len;
    while (i > 0) {
        i -= 1;
        switch (p.scopes.items[i]) {
            .typedef => |t| if (mem.eql(u8, t.name, name)) return t,
            .@"struct" => |s| if (mem.eql(u8, s.name, name)) {
                if (no_type_yet) return null;
                try p.errStr(.must_use_struct, name_tok, name);
                return s;
            },
            .@"union" => |u| if (mem.eql(u8, u.name, name)) {
                if (no_type_yet) return null;
                try p.errStr(.must_use_union, name_tok, name);
                return u;
            },
            .@"enum" => |e| if (mem.eql(u8, e.name, name)) {
                if (no_type_yet) return null;
                try p.errStr(.must_use_enum, name_tok, name);
                return e;
            },
            .def, .decl => |d| if (mem.eql(u8, d.name, name)) return null,
            else => {},
        }
    }
    return null;
}

fn findSymbol(p: *Parser, name_tok: TokenIndex, ref_kind: enum { reference, definition }) ?Scope {
    const name = p.tokSlice(name_tok);
    var i = p.scopes.items.len;
    while (i > 0) {
        i -= 1;
        const sym = p.scopes.items[i];
        switch (sym) {
            .def, .decl, .param => |s| if (mem.eql(u8, s.name, name)) return sym,
            .enumeration => |e| if (mem.eql(u8, e.name, name)) return sym,
            .block => if (ref_kind == .definition) return null,
            else => {},
        }
    }
    return null;
}

fn findTag(p: *Parser, kind: Token.Id, name_tok: TokenIndex, ref_kind: enum { reference, definition }) !?Scope.Symbol {
    const name = p.tokSlice(name_tok);
    var i = p.scopes.items.len;
    var saw_block = false;
    while (i > 0) {
        i -= 1;
        const sym = p.scopes.items[i];
        switch (sym) {
            .@"enum" => |e| if (mem.eql(u8, e.name, name)) {
                if (kind == .keyword_enum) return e;
                if (saw_block) return null;
                try p.errStr(.wrong_tag, name_tok, name);
                try p.errTok(.previous_definition, e.name_tok);
                return null;
            },
            .@"struct" => |s| if (mem.eql(u8, s.name, name)) {
                if (kind == .keyword_struct) return s;
                if (saw_block) return null;
                try p.errStr(.wrong_tag, name_tok, name);
                try p.errTok(.previous_definition, s.name_tok);
                return null;
            },
            .@"union" => |u| if (mem.eql(u8, u.name, name)) {
                if (kind == .keyword_union) return u;
                if (saw_block) return null;
                try p.errStr(.wrong_tag, name_tok, name);
                try p.errTok(.previous_definition, u.name_tok);
                return null;
            },
            .block => if (ref_kind == .reference) {
                saw_block = true;
            } else return null,
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

fn nodeIs(p: *Parser, node: NodeIndex, tag: Tree.Tag) bool {
    var cur = node;
    const tags = p.nodes.items(.tag);
    const data = p.nodes.items(.data);
    while (true) {
        const cur_tag = tags[@enumToInt(cur)];
        if (cur_tag == .paren_expr) {
            cur = data[@enumToInt(cur)].un;
        } else if (cur_tag == tag) {
            return true;
        } else {
            return false;
        }
    }
}

fn pragma(p: *Parser) !bool {
    var found_pragma = false;
    while (p.eatToken(.keyword_pragma)) |pragma_tok| {
        found_pragma = true;

        const name_tok = p.tok_i;
        const name = p.tokSlice(name_tok);

        const end_idx = mem.indexOfScalarPos(Token.Id, p.tok_ids, p.tok_i, .nl) orelse {
            try p.errTok(.pragma_inside_macro, pragma_tok);
            return error.ParsingFailed;
        };
        const pragma_len = @intCast(TokenIndex, end_idx) - p.tok_i;
        defer p.tok_i += pragma_len + 1; // skip past .nl as well
        if (p.pp.comp.getPragma(name)) |prag| {
            try prag.parserCB(p, p.tok_i);
        }
    }
    return found_pragma;
}

fn defineVaList(p: *Parser) !void {
    const Kind = enum { char_ptr, void_ptr, aarch64_va_list, x86_64_va_list };
    const kind: Kind = switch (p.pp.comp.target.cpu.arch) {
        .aarch64 => switch (p.pp.comp.target.os.tag) {
            .windows => @as(Kind, .char_ptr),
            .ios, .macos, .tvos, .watchos => .char_ptr,
            else => .aarch64_va_list,
        },
        .sparc, .wasm32, .wasm64, .bpfel, .bpfeb, .riscv32, .riscv64, .avr, .spirv32, .spirv64 => .void_ptr,
        .powerpc => switch (p.pp.comp.target.os.tag) {
            .ios, .macos, .tvos, .watchos, .aix => @as(Kind, .char_ptr),
            else => return, // unknown
        },
        .i386 => .char_ptr,
        .x86_64 => switch (p.pp.comp.target.os.tag) {
            .windows => @as(Kind, .char_ptr),
            else => .x86_64_va_list,
        },
        else => return, // unknown
    };

    var ty: Type = undefined;
    switch (kind) {
        .char_ptr => ty = .{ .specifier = .char },
        .void_ptr => ty = .{ .specifier = .void },
        .aarch64_va_list => {
            const record_ty = try p.arena.create(Type.Record);
            record_ty.* = .{
                .name = "__va_list_tag",
                .fields = try p.arena.alloc(Type.Record.Field, 5),
                .size = 32,
                .alignment = 8,
            };
            const void_ty = try p.arena.create(Type);
            void_ty.* = .{ .specifier = .void };
            const void_ptr = Type{ .specifier = .pointer, .data = .{ .sub_type = void_ty } };
            record_ty.fields[0] = .{ .name = "__stack", .ty = void_ptr };
            record_ty.fields[1] = .{ .name = "__gr_top", .ty = void_ptr };
            record_ty.fields[2] = .{ .name = "__vr_top", .ty = void_ptr };
            record_ty.fields[3] = .{ .name = "__gr_offs", .ty = .{ .specifier = .int } };
            record_ty.fields[4] = .{ .name = "__vr_offs", .ty = .{ .specifier = .int } };
            ty = .{ .specifier = .@"struct", .data = .{ .record = record_ty } };
        },
        .x86_64_va_list => {
            const record_ty = try p.arena.create(Type.Record);
            record_ty.* = .{
                .name = "__va_list_tag",
                .fields = try p.arena.alloc(Type.Record.Field, 4),
                .size = 24,
                .alignment = 8,
            };
            const void_ty = try p.arena.create(Type);
            void_ty.* = .{ .specifier = .void };
            const void_ptr = Type{ .specifier = .pointer, .data = .{ .sub_type = void_ty } };
            record_ty.fields[0] = .{ .name = "gp_offset", .ty = .{ .specifier = .uint } };
            record_ty.fields[1] = .{ .name = "fp_offset", .ty = .{ .specifier = .uint } };
            record_ty.fields[2] = .{ .name = "overflow_arg_area", .ty = void_ptr };
            record_ty.fields[3] = .{ .name = "reg_save_area", .ty = void_ptr };
            ty = .{ .specifier = .@"struct", .data = .{ .record = record_ty } };
        },
    }
    if (kind == .char_ptr or kind == .void_ptr) {
        const elem_ty = try p.arena.create(Type);
        elem_ty.* = ty;
        ty = Type{ .specifier = .pointer, .data = .{ .sub_type = elem_ty } };
    } else {
        const arr_ty = try p.arena.create(Type.Array);
        arr_ty.* = .{ .len = 1, .elem = ty };
        ty = Type{ .specifier = .array, .data = .{ .array = arr_ty } };
    }

    const sym = Scope.Symbol{ .name = "__builtin_va_list", .ty = ty, .name_tok = 0 };
    try p.scopes.append(.{ .typedef = sym });
}

/// root : (decl | assembly ';' | staticAssert)*
pub fn parse(pp: *Preprocessor) Compilation.Error!Tree {
    pp.comp.pragmaEvent(.before_parse);

    var arena = std.heap.ArenaAllocator.init(pp.comp.gpa);
    errdefer arena.deinit();
    var p = Parser{
        .pp = pp,
        .arena = &arena.allocator,
        .tok_ids = pp.tokens.items(.id),
        .strings = std.ArrayList(u8).init(pp.comp.gpa),
        .value_map = Tree.ValueMap.init(pp.comp.gpa),
        .data = NodeList.init(pp.comp.gpa),
        .labels = std.ArrayList(Label).init(pp.comp.gpa),
        .scopes = std.ArrayList(Scope).init(pp.comp.gpa),
        .list_buf = NodeList.init(pp.comp.gpa),
        .decl_buf = NodeList.init(pp.comp.gpa),
        .param_buf = std.ArrayList(Type.Func.Param).init(pp.comp.gpa),
        .enum_buf = std.ArrayList(Type.Enum.Field).init(pp.comp.gpa),
        .record_buf = std.ArrayList(Type.Record.Field).init(pp.comp.gpa),
        .attr_buf = std.ArrayList(Attribute).init(pp.comp.gpa),
    };
    errdefer {
        p.nodes.deinit(pp.comp.gpa);
        p.strings.deinit();
        p.value_map.deinit();
    }
    defer {
        p.data.deinit();
        p.labels.deinit();
        p.scopes.deinit();
        p.list_buf.deinit();
        p.decl_buf.deinit();
        p.param_buf.deinit();
        p.enum_buf.deinit();
        p.record_buf.deinit();
        p.attr_buf.deinit();
    }

    // NodeIndex 0 must be invalid
    _ = try p.addNode(.{ .tag = .invalid, .ty = undefined, .data = undefined });
    try p.defineVaList();

    while (p.eatToken(.eof) == null) {
        const found_pragma = p.pragma() catch |err| switch (err) {
            error.ParsingFailed => break,
            else => |e| return e,
        };
        if (found_pragma) continue;
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
        if (p.eatToken(.keyword_extension)) |_| {
            const saved_extension = p.extension_suppressed;
            defer p.extension_suppressed = saved_extension;
            p.extension_suppressed = true;

            if (p.decl() catch |er| switch (er) {
                error.ParsingFailed => {
                    p.nextExternDecl();
                    continue;
                },
                else => |e| return e,
            }) continue;
        }
        if (p.assembly(.global) catch |er| switch (er) {
            error.ParsingFailed => {
                p.nextExternDecl();
                continue;
            },
            else => |e| return e,
        }) |_| continue;
        try p.err(.expected_external_decl);
        p.tok_i += 1;
    }
    const root_decls = p.decl_buf.toOwnedSlice();
    if (root_decls.len == 0) {
        try p.errTok(.empty_translation_unit, p.tok_i - 1);
    }
    pp.comp.pragmaEvent(.after_parse);
    return Tree{
        .comp = pp.comp,
        .tokens = pp.tokens.slice(),
        .arena = arena,
        .generated = pp.generated.items,
        .nodes = p.nodes.toOwnedSlice(),
        .data = p.data.toOwnedSlice(),
        .root_decls = root_decls,
        .strings = p.strings.toOwnedSlice(),
        .value_map = p.value_map,
    };
}

fn skipToPragmaSentinel(p: *Parser) void {
    while (true) : (p.tok_i += 1) {
        if (p.tok_ids[p.tok_i] == .nl) return;
        if (p.tok_ids[p.tok_i] == .eof) {
            p.tok_i -= 1;
            return;
        }
    }
}

fn nextExternDecl(p: *Parser) void {
    var parens: u32 = 0;
    while (true) : (p.tok_i += 1) {
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
            .keyword_inline1,
            .keyword_inline2,
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
            .extended_identifier,
            .keyword_typeof,
            .keyword_typeof1,
            .keyword_typeof2,
            .keyword_extension,
            => if (parens == 0) return,
            .keyword_pragma => p.skipToPragmaSentinel(),
            .eof => return,
            .semicolon => if (parens == 0) {
                p.tok_i += 1;
                return;
            },
            else => {},
        }
    }
}

fn skipTo(p: *Parser, id: Token.Id) void {
    var parens: u32 = 0;
    while (true) : (p.tok_i += 1) {
        if (p.tok_ids[p.tok_i] == id and parens == 0) {
            p.tok_i += 1;
            return;
        }
        switch (p.tok_ids[p.tok_i]) {
            .l_paren, .l_brace, .l_bracket => parens += 1,
            .r_paren, .r_brace, .r_bracket => if (parens != 0) {
                parens -= 1;
            },
            .keyword_pragma => p.skipToPragmaSentinel(),
            .eof => return,
            else => {},
        }
    }
}

// ====== declarations ======

/// decl
///  : declSpec (initDeclarator ( ',' initDeclarator)*)? ';'
///  | declSpec declarator decl* compoundStmt
fn decl(p: *Parser) Error!bool {
    _ = try p.pragma();
    const first_tok = p.tok_i;
    const attr_buf_top = p.attr_buf.items.len;
    defer p.attr_buf.items.len = attr_buf_top;
    // TODO: at this point we don't know what we're trying to parse, so we'll need to check
    // the attributes against what kind of decl was parsed after the fact
    try p.attributeSpecifier(.any);

    var decl_spec = if (try p.declSpec(false)) |some| some else blk: {
        if (p.return_type != null) {
            p.tok_i = first_tok;
            return false;
        }
        switch (p.tok_ids[first_tok]) {
            .asterisk, .l_paren, .identifier, .extended_identifier => {},
            else => return false,
        }
        var spec: Type.Builder = .{};
        break :blk DeclSpec{ .ty = try spec.finish(p) };
    };
    var init_d = (try p.initDeclarator(&decl_spec)) orelse {
        _ = try p.expectToken(.semicolon);
        if (decl_spec.ty.is(.@"enum")) return true;
        if (decl_spec.ty.isRecord() and decl_spec.ty.data.record.name[0] != '(') return true;
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
                return true;
            },
        }
        if (p.return_type != null) try p.err(.func_not_in_root);

        if (p.findSymbol(init_d.d.name, .definition)) |sym| {
            if (sym == .def) {
                try p.errStr(.redefinition, init_d.d.name, p.tokSlice(init_d.d.name));
                try p.errTok(.previous_definition, sym.def.name_tok);
            }
        } else {
            try p.scopes.append(.{ .def = .{
                .name = p.tokSlice(init_d.d.name),
                .ty = init_d.d.ty,
                .name_tok = init_d.d.name,
            } });
        }

        const return_type = p.return_type;
        const func_name = p.func_name;
        p.return_type = init_d.d.ty.data.func.return_type;
        p.func_name = init_d.d.name;
        defer {
            p.return_type = return_type;
            p.func_name = func_name;
        }

        const scopes_top = p.scopes.items.len;
        defer p.scopes.items.len = scopes_top;

        // findSymbol stops the search at .block
        try p.scopes.append(.block);

        // Collect old style parameter declarations.
        if (init_d.d.old_style_func != null) {
            init_d.d.ty.specifier = .func;
            const param_buf_top = p.param_buf.items.len;
            defer p.param_buf.items.len = param_buf_top;

            param_loop: while (true) {
                const param_decl_spec = (try p.declSpec(true)) orelse break;
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
                    if (d.ty.hasIncompleteSize() and !d.ty.is(.void)) try p.errStr(.parameter_incomplete_ty, d.name, try p.typeStr(d.ty));
                    if (d.ty.isFunc()) {
                        // Params declared as functions are converted to function pointers.
                        const elem_ty = try p.arena.create(Type);
                        elem_ty.* = d.ty;
                        d.ty = Type{
                            .specifier = .pointer,
                            .data = .{ .sub_type = elem_ty },
                        };
                    } else if (d.ty.isArray()) {
                        // params declared as arrays are converted to pointers
                        d.ty.decayArray();
                    } else if (d.ty.is(.void)) {
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

                    try p.scopes.append(.{ .param = .{
                        .name = name_str,
                        .name_tok = d.name,
                        .ty = d.ty,
                    } });
                    if (p.eatToken(.comma) == null) break;
                }
                _ = try p.expectToken(.semicolon);
            }
        } else {
            for (init_d.d.ty.data.func.params) |param| {
                if (param.ty.hasUnboundVLA()) try p.errTok(.unbound_vla, param.name_tok);
                if (param.ty.hasIncompleteSize() and !param.ty.is(.void)) try p.errStr(.parameter_incomplete_ty, param.name_tok, try p.typeStr(param.ty));

                if (param.name.len == 0) {
                    try p.errTok(.omitting_parameter_name, param.name_tok);
                    continue;
                }

                try p.scopes.append(.{
                    .param = .{
                        .name = param.name,
                        .ty = param.ty,
                        .name_tok = param.name_tok,
                    },
                });
            }
        }

        const body = (try p.compoundStmt(true)) orelse {
            assert(init_d.d.old_style_func != null);
            try p.err(.expected_fn_body);
            return true;
        };
        const node = try p.addNode(.{
            .ty = init_d.d.ty,
            .tag = try decl_spec.validateFnDef(p),
            .data = .{ .decl = .{ .name = init_d.d.name, .node = body } },
        });
        try p.decl_buf.append(node);

        // check gotos
        if (return_type == null) {
            for (p.labels.items) |item| {
                if (item == .unresolved_goto)
                    try p.errStr(.undeclared_label, item.unresolved_goto, p.tokSlice(item.unresolved_goto));
            }
            if (p.computed_goto_tok) |goto_tok| {
                if (!p.contains_address_of_label) try p.errTok(.invalid_computed_goto, goto_tok);
            }
            p.labels.items.len = 0;
            p.label_count = 0;
            p.contains_address_of_label = false;
            p.computed_goto_tok = null;
        }
        return true;
    }

    // Declare all variable/typedef declarators.
    while (true) {
        if (init_d.d.old_style_func) |tok_i| try p.errTok(.invalid_old_style_params, tok_i);
        const tag = try decl_spec.validate(p, &init_d.d.ty, init_d.initializer != .none);
        const attrs = p.attr_buf.items[attr_buf_top..];
        if (attrs.len > 0) {
            var attributed_type = try p.arena.create(Type.Attributed);
            attributed_type.* = .{
                .attributes = try p.arena.dupe(Attribute, attrs),
                .base = init_d.d.ty,
            };
            init_d.d.ty = .{ .specifier = .attributed, .data = .{ .attributed = attributed_type } };
        }

        const node = try p.addNode(.{ .ty = init_d.d.ty, .tag = tag, .data = .{
            .decl = .{ .name = init_d.d.name, .node = init_d.initializer },
        } });
        try p.decl_buf.append(node);

        const sym = Scope.Symbol{
            .name = p.tokSlice(init_d.d.name),
            .ty = init_d.d.ty,
            .name_tok = init_d.d.name,
        };
        if (decl_spec.storage_class == .typedef) {
            try p.scopes.append(.{ .typedef = sym });
        } else if (init_d.initializer != .none) {
            try p.scopes.append(.{ .def = sym });
        } else {
            try p.scopes.append(.{ .decl = sym });
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
    const res_token = p.tok_i;
    const res = try p.constExpr();
    const str = if (p.eatToken(.comma) != null)
        switch (p.tok_ids[p.tok_i]) {
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
        }
    else
        Result{};
    try p.expectClosing(l_paren, .r_paren);
    _ = try p.expectToken(.semicolon);
    if (str.node == .none) try p.errTok(.static_assert_missing_message, static_assert);

    if (res.val == .unavailable) {
        // an unavailable sizeof expression is already a compile error, so we don't emit
        // another error for an invalid _Static_assert condition. This matches the behavior
        // of gcc/clang
        if (!p.nodeIs(res.node, .sizeof_expr)) try p.errTok(.static_assert_not_constant, res_token);
    } else if (!res.getBool()) {
        if (str.node != .none) {
            var buf = std.ArrayList(u8).init(p.pp.comp.gpa);
            defer buf.deinit();

            const data = p.nodes.items(.data)[@enumToInt(str.node)].str;
            try buf.ensureUnusedCapacity(data.len);
            try Tree.dumpStr(
                p.strings.items[data.index..][0..data.len],
                p.nodes.items(.tag)[@enumToInt(str.node)],
                buf.writer(),
            );
            try p.errStr(
                .static_assert_failure_message,
                static_assert,
                try p.arena.dupe(u8, buf.items),
            );
        } else try p.errTok(.static_assert_failure, static_assert);
    }
    const node = try p.addNode(.{
        .tag = .static_assert,
        .data = .{ .bin = .{
            .lhs = res.node,
            .rhs = str.node,
        } },
    });
    try p.decl_buf.append(node);
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

    fn validateParam(d: DeclSpec, p: *Parser, ty: *Type) Error!void {
        switch (d.storage_class) {
            .none => {},
            .register => ty.qual.register = true,
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

    fn validate(d: DeclSpec, p: *Parser, ty: *Type, has_init: bool) Error!Tree.Tag {
        const is_static = d.storage_class == .static;
        if (ty.isFunc() and d.storage_class != .typedef) {
            switch (d.storage_class) {
                .none, .@"extern" => {},
                .static => |tok_i| if (p.return_type != null) try p.errTok(.static_func_not_global, tok_i),
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
                .auto, .register => if (p.return_type == null) try p.err(.illegal_storage_on_global),
                .typedef => return .typedef,
                else => {},
            }
            ty.qual.register = d.storage_class == .register;

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

/// typeof
///   : keyword_typeof '(' typeName ')'
///   | keyword_typeof '(' expr ')'
fn typeof(p: *Parser) Error!?Type {
    switch (p.tok_ids[p.tok_i]) {
        .keyword_typeof, .keyword_typeof1, .keyword_typeof2 => p.tok_i += 1,
        else => return null,
    }
    const l_paren = try p.expectToken(.l_paren);
    if (try p.typeName()) |ty| {
        try p.expectClosing(l_paren, .r_paren);
        const typeof_ty = try p.arena.create(Type);
        typeof_ty.* = .{
            .data = ty.data,
            .qual = ty.qual.inheritFromTypeof(),
            .specifier = ty.specifier,
        };

        return Type{
            .data = .{ .sub_type = typeof_ty },
            .specifier = .typeof_type,
        };
    }
    const typeof_expr = try p.parseNoEval(expr);
    try typeof_expr.expect(p);
    try p.expectClosing(l_paren, .r_paren);

    const inner = try p.arena.create(Type.Expr);
    inner.* = .{
        .node = typeof_expr.node,
        .ty = .{
            .data = typeof_expr.ty.data,
            .qual = typeof_expr.ty.qual.inheritFromTypeof(),
            .specifier = typeof_expr.ty.specifier,
        },
    };

    return Type{
        .data = .{ .expr = inner },
        .specifier = .typeof_expr,
    };
}

/// declSpec: (storageClassSpec | typeSpec | typeQual | funcSpec | alignSpec)+
/// storageClassSpec:
///  : keyword_typedef
///  | keyword_extern
///  | keyword_static
///  | keyword_threadlocal
///  | keyword_auto
///  | keyword_register
/// funcSpec : keyword_inline | keyword_noreturn
fn declSpec(p: *Parser, is_param: bool) Error!?DeclSpec {
    var d: DeclSpec = .{};
    var spec: Type.Builder = .{};

    const start = p.tok_i;
    while (true) {
        if (try p.typeSpec(&spec)) continue;
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
            .keyword_inline, .keyword_inline1, .keyword_inline2 => {
                if (d.@"inline" != null) {
                    try p.errStr(.duplicate_decl_spec, p.tok_i, "inline");
                }
                d.@"inline" = p.tok_i;
            },
            .keyword_noreturn => {
                if (d.@"noreturn" != null) {
                    try p.errStr(.duplicate_decl_spec, p.tok_i, "_Noreturn");
                }
                d.@"noreturn" = null;
            },
            else => break,
        }
        p.tok_i += 1;
    }

    if (p.tok_i == start) return null;

    if (is_param and spec.align_tok != null) {
        try p.errTok(.alignas_on_param, spec.align_tok.?);
        spec.align_tok = null;
    }
    d.ty = try spec.finish(p);
    return d;
}

const InitDeclarator = struct { d: Declarator, initializer: NodeIndex = .none };

/// attribute
///  : attrIdentifier
///  | attrIdentifier '(' identifier ')'
///  | attrIdentifier '(' identifier (',' expr)+ ')'
///  | attrIdentifier '(' (expr (',' expr)*)? ')'
fn attribute(p: *Parser) Error!Attribute {
    const name_tok = p.tok_i;
    switch (p.tok_ids[p.tok_i]) {
        .identifier, .keyword_const, .keyword_const1, .keyword_const2 => {},
        .extended_identifier => {
            const slice = p.tokSlice(p.tok_i);
            var it = std.unicode.Utf8View.initUnchecked(slice).iterator();
            var loc = p.pp.tokens.items(.loc)[p.tok_i];
            while (it.nextCodepoint()) |c| {
                if (try checkIdentifierCodepoint(p.pp.comp, c, loc)) break;
                loc.byte_offset += std.unicode.utf8CodepointSequenceLength(c) catch unreachable;
            }
        },
        else => {
            try p.errExtra(.expected_token, p.tok_i, .{ .tok_id = .{
                .expected = .identifier,
                .actual = p.tok_ids[p.tok_i],
            } });
            return error.ParsingFailed;
        },
    }
    p.tok_i += 1;
    switch (p.tok_ids[p.tok_i]) {
        .comma, .r_paren => { // will be consumed in attributeList
            return Attribute{ .name = name_tok };
        },
        .l_paren => {
            p.tok_i += 1;
            if (p.eatToken(.r_paren)) |_| return Attribute{ .name = name_tok };

            const maybe_ident = try p.eatIdentifier();
            if (maybe_ident != null and p.eatToken(.r_paren) != null) {
                const arg_node = try p.addNode(.{
                    .tag = .attr_arg_ident,
                    .ty = .{ .specifier = .void },
                    .data = .{ .decl_ref = maybe_ident.? },
                });
                return Attribute{
                    .name = name_tok,
                    .params = arg_node,
                };
            }
            const list_buf_top = p.list_buf.items.len;
            defer p.list_buf.items.len = list_buf_top;

            if (maybe_ident) |ident| {
                const arg_node = try p.addNode(.{
                    .tag = .attr_arg_ident,
                    .ty = .{ .specifier = .void },
                    .data = .{ .decl_ref = ident },
                });
                try p.list_buf.append(arg_node);
            } else {
                var first_expr = try p.assignExpr();
                try first_expr.expect(p);
                try first_expr.saveValue(p);
                try p.list_buf.append(first_expr.node);
            }

            while (p.tok_ids[p.tok_i] != .r_paren) {
                _ = try p.expectToken(.comma);

                var attr_expr = try p.assignExpr();
                try attr_expr.expect(p);
                try attr_expr.saveValue(p);

                try p.list_buf.append(attr_expr.node);
            }
            p.tok_i += 1; // eat closing r_paren

            const items = p.list_buf.items[list_buf_top..];
            assert(items.len > 0);

            var node: Tree.Node = .{ .tag = .attr_params_two, .ty = .{ .specifier = .void }, .data = .{ .bin = .{ .lhs = items[0], .rhs = .none } } };
            switch (items.len) {
                0 => unreachable,
                1 => {},
                2 => node.data.bin.rhs = items[1],
                else => {
                    node.tag = .attr_params;
                    node.data = .{ .range = try p.addList(items) };
                },
            }
            return Attribute{
                .name = name_tok,
                .params = try p.addNode(node),
            };
        },
        else => return error.ParsingFailed,
    }
}

fn validateAttr(p: *Parser, attr: Attribute, context: Attribute.ParseContext) Error!bool {
    const name = p.tokSlice(attr.name);
    if (Attribute.Tag.fromString(name)) |tag| {
        if (tag.allowedInContext(context)) return true;

        if (context == .statement) {
            try p.errTok(.cannot_apply_attribute_to_statement, attr.name);
            return error.ParsingFailed;
        }
        try p.errStr(.ignored_attribute, attr.name, try p.ignoredAttrStr(tag, context));
    } else {
        try p.errStr(.unknown_attribute, attr.name, name);
    }
    return false;
}

/// attributeList : (attribute (',' attribute)*)?
fn attributeList(p: *Parser, context: Attribute.ParseContext) Error!void {
    if (p.tok_ids[p.tok_i] != .r_paren) {
        const attr = try p.attribute();
        if (try p.validateAttr(attr, context)) {
            try p.attr_buf.append(attr);
        }
        while (p.tok_ids[p.tok_i] != .r_paren) {
            _ = try p.expectToken(.comma);
            const next_attr = try p.attribute();
            if (try p.validateAttr(next_attr, context)) {
                try p.attr_buf.append(next_attr);
            }
        }
    }
}

/// attributeSpecifier : (keyword_attribute '( '(' attributeList ')' ')')*
fn attributeSpecifier(p: *Parser, context: Attribute.ParseContext) Error!void {
    while (p.tok_ids[p.tok_i] == .keyword_attribute1 or p.tok_ids[p.tok_i] == .keyword_attribute2) {
        p.tok_i += 1;
        const paren1 = try p.expectToken(.l_paren);
        const paren2 = try p.expectToken(.l_paren);

        try p.attributeList(context);

        _ = try p.expectClosing(paren2, .r_paren);
        _ = try p.expectClosing(paren1, .r_paren);
    }
}

/// initDeclarator : declarator assembly? attributeSpecifier? ('=' initializer)?
fn initDeclarator(p: *Parser, decl_spec: *DeclSpec) Error!?InitDeclarator {
    var init_d = InitDeclarator{
        .d = (try p.declarator(decl_spec.ty, .normal)) orelse return null,
    };
    _ = try p.assembly(.decl); // TODO use somehow
    try p.attributeSpecifier(if (init_d.d.ty.isFunc()) .function else .variable);
    if (p.eatToken(.equal)) |eq| init: {
        if (init_d.d.ty.hasIncompleteSize() and !init_d.d.ty.isArray()) {
            try p.errStr(.variable_incomplete_ty, init_d.d.name, try p.typeStr(init_d.d.ty));
            return error.ParsingFailed;
        }

        if (decl_spec.storage_class == .typedef or init_d.d.func_declarator != null) {
            try p.errTok(.illegal_initializer, eq);
        } else if (init_d.d.ty.is(.variable_len_array)) {
            try p.errTok(.vla_init, eq);
        } else if (decl_spec.storage_class == .@"extern") {
            try p.err(.extern_initializer);
            decl_spec.storage_class = .none;
        }

        var init_list_expr = try p.initializer(init_d.d.ty);
        init_d.initializer = init_list_expr.node;
        if (!init_list_expr.ty.isArray()) break :init;
        if (init_d.d.ty.specifier == .incomplete_array) {
            // Modifying .data is exceptionally allowed for .incomplete_array.
            init_d.d.ty.data.array.len = init_list_expr.ty.data.array.len;
            init_d.d.ty.specifier = .array;
        } else if (init_d.d.ty.is(.incomplete_array)) {
            const arr_ty = try p.arena.create(Type.Array);
            arr_ty.* = .{ .elem = init_d.d.ty.elemType(), .len = init_list_expr.ty.arrayLen().? };
            init_d.d.ty = .{
                .specifier = .array,
                .data = .{ .array = arr_ty },
                .alignment = init_d.d.ty.alignment,
            };
        }
    }
    const name = init_d.d.name;
    if (decl_spec.storage_class != .typedef and init_d.d.ty.hasIncompleteSize()) incomplete: {
        const specifier = init_d.d.ty.canonicalize(.standard).specifier;
        if (decl_spec.storage_class == .@"extern") switch (specifier) {
            .@"struct", .@"union", .@"enum" => break :incomplete,
            .incomplete_array => {
                init_d.d.ty.decayArray();
                break :incomplete;
            },
            else => {},
        };
        // if there was an initializer expression it must have contained an error
        if (init_d.initializer != .none) break :incomplete;
        try p.errStr(.variable_incomplete_ty, name, try p.typeStr(init_d.d.ty));
        return init_d;
    }
    if (p.findSymbol(name, .definition)) |scope| switch (scope) {
        .enumeration => {
            try p.errStr(.redefinition_different_sym, name, p.tokSlice(name));
            try p.errTok(.previous_definition, scope.enumeration.name_tok);
        },
        .decl => |s| if (!s.ty.eql(init_d.d.ty, true)) {
            try p.errStr(.redefinition_incompatible, name, p.tokSlice(name));
            try p.errTok(.previous_definition, s.name_tok);
        },
        .def => |s| if (!s.ty.eql(init_d.d.ty, true)) {
            try p.errStr(.redefinition_incompatible, name, p.tokSlice(name));
            try p.errTok(.previous_definition, s.name_tok);
        } else if (init_d.initializer != .none) {
            try p.errStr(.redefinition, name, p.tokSlice(name));
            try p.errTok(.previous_definition, s.name_tok);
        },
        .param => |s| {
            try p.errStr(.redefinition, name, p.tokSlice(name));
            try p.errTok(.previous_definition, s.name_tok);
        },
        else => unreachable,
    };
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
///  | typeof
/// atomicTypeSpec : keyword_atomic '(' typeName ')'
/// alignSpec
///   : keyword_alignas '(' typeName ')'
///   | keyword_alignas '(' constExpr ')'
fn typeSpec(p: *Parser, ty: *Type.Builder) Error!bool {
    const start = p.tok_i;
    while (true) {
        try p.attributeSpecifier(.typedef);

        if (try p.typeof()) |inner_ty| {
            try ty.combineFromTypeof(p, inner_ty, start);
            continue;
        }
        if (try p.typeQual(&ty.qual)) continue;
        switch (p.tok_ids[p.tok_i]) {
            .keyword_void => try ty.combine(p, .void, p.tok_i),
            .keyword_bool => try ty.combine(p, .bool, p.tok_i),
            .keyword_char => try ty.combine(p, .char, p.tok_i),
            .keyword_short => try ty.combine(p, .short, p.tok_i),
            .keyword_int => try ty.combine(p, .int, p.tok_i),
            .keyword_long => try ty.combine(p, .long, p.tok_i),
            .keyword_signed => try ty.combine(p, .signed, p.tok_i),
            .keyword_unsigned => try ty.combine(p, .unsigned, p.tok_i),
            .keyword_float => try ty.combine(p, .float, p.tok_i),
            .keyword_double => try ty.combine(p, .double, p.tok_i),
            .keyword_complex => try ty.combine(p, .complex, p.tok_i),
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
                try ty.combine(p, new_spec, atomic_tok);

                if (ty.qual.atomic != null)
                    try p.errStr(.duplicate_decl_spec, atomic_tok, "atomic")
                else
                    ty.qual.atomic = atomic_tok;
                continue;
            },
            .keyword_struct => {
                const tag_tok = p.tok_i;
                try ty.combine(p, .{ .@"struct" = try p.recordSpec() }, tag_tok);
                continue;
            },
            .keyword_union => {
                const tag_tok = p.tok_i;
                try ty.combine(p, .{ .@"union" = try p.recordSpec() }, tag_tok);
                continue;
            },
            .keyword_enum => {
                const tag_tok = p.tok_i;
                try ty.combine(p, .{ .@"enum" = try p.enumSpec() }, tag_tok);
                continue;
            },
            .identifier, .extended_identifier => {
                const typedef = (try p.findTypedef(p.tok_i, ty.specifier != .none)) orelse break;
                if (!(try ty.combineTypedef(p, typedef.ty, typedef.name_tok))) break;
            },
            .keyword_alignas => {
                if (ty.align_tok != null) try p.errStr(.duplicate_decl_spec, p.tok_i, "alignment");
                ty.align_tok = p.tok_i;
                p.tok_i += 1;
                const l_paren = try p.expectToken(.l_paren);
                if (try p.typeName()) |inner_ty| {
                    ty.alignment = inner_ty.alignment;
                } else blk: {
                    const res = try p.constExpr();
                    if (res.val == .unavailable) {
                        try p.errTok(.alignas_unavailable, ty.align_tok.?);
                        break :blk;
                    } else if (res.val == .signed and res.val.signed < 0) {
                        try p.errExtra(.negative_alignment, ty.align_tok.?, .{ .signed = res.val.signed });
                        break :blk;
                    }
                    var requested = std.math.cast(u29, res.as_u64()) catch {
                        try p.errExtra(.maximum_alignment, ty.align_tok.?, .{ .unsigned = res.as_u64() });
                        break :blk;
                    };
                    if (requested == 0) {
                        try p.errTok(.zero_align_ignored, ty.align_tok.?);
                    } else if (!std.mem.isValidAlign(requested)) {
                        requested = 0;
                        try p.errTok(.non_pow2_align, ty.align_tok.?);
                    }
                    ty.alignment = requested;
                }
                try p.expectClosing(l_paren, .r_paren);
                continue;
            },
            else => break,
        }
        // consume single token specifiers here
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
    const attr_buf_top = p.attr_buf.items.len;
    defer p.attr_buf.items.len = attr_buf_top;
    try p.attributeSpecifier(.record);

    const maybe_ident = try p.eatIdentifier();
    const l_brace = p.eatToken(.l_brace) orelse {
        const ident = maybe_ident orelse {
            try p.err(.ident_or_l_brace);
            return error.ParsingFailed;
        };
        // check if this is a reference to a previous type
        if (try p.findTag(p.tok_ids[kind_tok], ident, .reference)) |prev| {
            return prev.ty.data.record;
        } else {
            // this is a forward declaration, create a new record Type.
            const record_ty = try Type.Record.create(p.arena, p.tokSlice(ident));
            const ty = Type{
                .specifier = if (is_struct) .@"struct" else .@"union",
                .data = .{ .record = record_ty },
            };
            const sym = Scope.Symbol{ .name = record_ty.name, .ty = ty, .name_tok = ident };
            try p.scopes.append(if (is_struct) .{ .@"struct" = sym } else .{ .@"union" = sym });
            return record_ty;
        }
    };

    // Get forward declared type or create a new one
    var defined = false;
    const record_ty: *Type.Record = if (maybe_ident) |ident| record_ty: {
        if (try p.findTag(p.tok_ids[kind_tok], ident, .definition)) |prev| {
            if (!prev.ty.data.record.isIncomplete()) {
                // if the record isn't incomplete, this is a redefinition
                try p.errStr(.redefinition, ident, p.tokSlice(ident));
                try p.errTok(.previous_definition, prev.name_tok);
            } else {
                defined = true;
                break :record_ty prev.ty.data.record;
            }
        }
        break :record_ty try Type.Record.create(p.arena, p.tokSlice(ident));
    } else try Type.Record.create(p.arena, try p.getAnonymousName(kind_tok));
    const ty = Type{
        .specifier = if (is_struct) .@"struct" else .@"union",
        .data = .{ .record = record_ty },
    };

    // declare a symbol for the type
    if (maybe_ident != null and !defined) {
        const sym = Scope.Symbol{ .name = record_ty.name, .ty = ty, .name_tok = maybe_ident.? };
        try p.scopes.append(if (is_struct) .{ .@"struct" = sym } else .{ .@"union" = sym });
    }

    // reserve space for this record
    try p.decl_buf.append(.none);
    const decl_buf_top = p.decl_buf.items.len;
    const record_buf_top = p.record_buf.items.len;
    errdefer p.decl_buf.items.len = decl_buf_top - 1;
    defer {
        p.decl_buf.items.len = decl_buf_top;
        p.record_buf.items.len = record_buf_top;
    }

    try p.recordDecls();
    record_ty.fields = try p.arena.dupe(Type.Record.Field, p.record_buf.items[record_buf_top..]);
    // TODO actually calculate
    record_ty.size = 1;
    record_ty.alignment = 1;

    if (p.record_buf.items.len == record_buf_top) try p.errStr(.empty_record, kind_tok, p.tokSlice(kind_tok));
    try p.expectClosing(l_brace, .r_brace);
    try p.attributeSpecifier(.record);

    // finish by creating a node
    var node: Tree.Node = .{
        .tag = if (is_struct) .struct_decl_two else .union_decl_two,
        .ty = ty,
        .data = .{ .bin = .{ .lhs = .none, .rhs = .none } },
    };
    const record_decls = p.decl_buf.items[decl_buf_top..];
    switch (record_decls.len) {
        0 => {},
        1 => node.data = .{ .bin = .{ .lhs = record_decls[0], .rhs = .none } },
        2 => node.data = .{ .bin = .{ .lhs = record_decls[0], .rhs = record_decls[1] } },
        else => {
            node.tag = if (is_struct) .struct_decl else .union_decl;
            node.data = .{ .range = try p.addList(record_decls) };
        },
    }
    p.decl_buf.items[decl_buf_top - 1] = try p.addNode(node);
    return record_ty;
}

/// recordDecl
///  : specQual (recordDeclarator (',' recordDeclarator)*)? ;
///  | staticAssert
fn recordDecls(p: *Parser) Error!void {
    while (true) {
        if (try p.pragma()) continue;
        if (try p.staticAssert()) continue;
        if (p.eatToken(.keyword_extension)) |_| {
            const saved_extension = p.extension_suppressed;
            defer p.extension_suppressed = saved_extension;
            p.extension_suppressed = true;

            if (p.recordDeclarator() catch |e| switch (e) {
                error.ParsingFailed => {
                    p.nextExternDecl();
                    continue;
                },
                else => |err| return err,
            }) continue;
            try p.err(.expected_type);
            p.nextExternDecl();
            continue;
        }
        if (p.recordDeclarator() catch |e| switch (e) {
            error.ParsingFailed => {
                p.nextExternDecl();
                continue;
            },
            else => |err| return err,
        }) continue;
        break;
    }
}

/// recordDeclarator : keyword_extension? declarator (':' constExpr)?
fn recordDeclarator(p: *Parser) Error!bool {
    const base_ty = (try p.specQual()) orelse return false;

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
        if (p.eatToken(.colon)) |_| bits: {
            const res = try p.constExpr();
            if (!ty.isInt()) {
                try p.errStr(.non_int_bitfield, first_tok, try p.typeStr(ty));
                break :bits;
            }

            if (res.val == .unavailable) {
                try p.errTok(.expected_integer_constant_expr, first_tok);
                break :bits;
            } else if (res.val == .signed and res.val.signed < 0) {
                try p.errExtra(.negative_bitwidth, first_tok, .{ .signed = res.val.signed });
                break :bits;
            }

            const width = res.as_u64();
            if (width == 0 and name_tok != 0) {
                try p.errTok(.zero_width_named_field, name_tok);
                break :bits;
            } else if (width > ty.bitSizeof(p.pp.comp).?) {
                try p.errTok(.bitfield_too_big, name_tok);
                break :bits;
            }

            bits = @truncate(u32, width);
            bits_node = res.node;
        }
        if (name_tok == 0 and bits_node == .none) unnamed: {
            if (ty.is(.@"enum")) break :unnamed;
            if (ty.isRecord() and ty.data.record.name[0] == '(') {
                // An anonymous record appears as indirect fields on the parent
                try p.record_buf.append(.{
                    .name = try p.getAnonymousName(first_tok),
                    .ty = ty,
                    .bit_width = 0,
                });
                const node = try p.addNode(.{
                    .tag = .indirect_record_field_decl,
                    .ty = ty,
                    .data = undefined,
                });
                try p.decl_buf.append(node);
                break; // must be followed by a semicolon
            }
            try p.err(.missing_declaration);
        } else {
            try p.record_buf.append(.{
                .name = if (name_tok != 0) p.tokSlice(name_tok) else try p.getAnonymousName(first_tok),
                .ty = ty,
                .bit_width = bits,
            });
            const node = try p.addNode(.{
                .tag = .record_field_decl,
                .ty = ty,
                .data = .{ .decl = .{ .name = name_tok, .node = bits_node } },
            });
            try p.decl_buf.append(node);
        }
        if (p.eatToken(.comma) == null) break;
    }
    _ = try p.expectToken(.semicolon);
    return true;
}

/// specQual : (typeSpec | typeQual | alignSpec)+
fn specQual(p: *Parser) Error!?Type {
    var spec: Type.Builder = .{};
    if (try p.typeSpec(&spec)) {
        if (spec.alignment != 0) try p.errTok(.align_ignored, spec.align_tok.?);
        spec.align_tok = null;
        return try spec.finish(p);
    }
    return null;
}

/// enumSpec
///  : keyword_enum IDENTIFIER? { enumerator (',' enumerator)? ',') }
///  | keyword_enum IDENTIFIER
fn enumSpec(p: *Parser) Error!*Type.Enum {
    const enum_tok = p.tok_i;
    p.tok_i += 1;
    const attr_buf_top = p.attr_buf.items.len;
    defer p.attr_buf.items.len = attr_buf_top;
    try p.attributeSpecifier(.record);

    const maybe_ident = try p.eatIdentifier();
    const l_brace = p.eatToken(.l_brace) orelse {
        const ident = maybe_ident orelse {
            try p.err(.ident_or_l_brace);
            return error.ParsingFailed;
        };
        // check if this is a reference to a previous type
        if (try p.findTag(.keyword_enum, ident, .reference)) |prev| {
            return prev.ty.data.@"enum";
        } else {
            // this is a forward declaration, create a new enum Type.
            const enum_ty = try Type.Enum.create(p.arena, p.tokSlice(ident));
            const ty = Type{ .specifier = .@"enum", .data = .{ .@"enum" = enum_ty } };
            const sym = Scope.Symbol{ .name = enum_ty.name, .ty = ty, .name_tok = ident };
            try p.scopes.append(.{ .@"enum" = sym });
            return enum_ty;
        }
    };

    // Get forward declared type or create a new one
    var defined = false;
    const enum_ty: *Type.Enum = if (maybe_ident) |ident| enum_ty: {
        if (try p.findTag(.keyword_enum, ident, .definition)) |prev| {
            if (!prev.ty.data.@"enum".isIncomplete()) {
                // if the enum isn't incomplete, this is a redefinition
                try p.errStr(.redefinition, ident, p.tokSlice(ident));
                try p.errTok(.previous_definition, prev.name_tok);
            } else {
                defined = true;
                break :enum_ty prev.ty.data.@"enum";
            }
        }
        break :enum_ty try Type.Enum.create(p.arena, p.tokSlice(ident));
    } else try Type.Enum.create(p.arena, try p.getAnonymousName(enum_tok));
    const ty = Type{
        .specifier = .@"enum",
        .data = .{ .@"enum" = enum_ty },
    };

    // declare a symbol for the type
    if (maybe_ident != null and !defined) {
        try p.scopes.append(.{ .@"enum" = .{
            .name = enum_ty.name,
            .ty = ty,
            .name_tok = maybe_ident.?,
        } });
    }

    // reserve space for this enum
    try p.decl_buf.append(.none);
    const decl_buf_top = p.decl_buf.items.len;
    const list_buf_top = p.list_buf.items.len;
    const enum_buf_top = p.enum_buf.items.len;
    errdefer p.decl_buf.items.len = decl_buf_top - 1;
    defer {
        p.decl_buf.items.len = decl_buf_top;
        p.list_buf.items.len = list_buf_top;
        p.enum_buf.items.len = enum_buf_top;
    }

    var e = Enumerator.init(p);
    while (try p.enumerator(&e)) |field_and_node| {
        try p.enum_buf.append(field_and_node.field);
        try p.list_buf.append(field_and_node.node);
        if (p.eatToken(.comma) == null) break;
    }
    enum_ty.fields = try p.arena.dupe(Type.Enum.Field, p.enum_buf.items[enum_buf_top..]);
    enum_ty.tag_ty = .{ .specifier = .int }; // TODO actually resolve

    if (p.enum_buf.items.len == enum_buf_top) try p.err(.empty_enum);
    try p.expectClosing(l_brace, .r_brace);
    try p.attributeSpecifier(.record);

    // finish by creating a node
    var node: Tree.Node = .{ .tag = .enum_decl_two, .ty = ty, .data = .{
        .bin = .{ .lhs = .none, .rhs = .none },
    } };
    const field_nodes = p.list_buf.items[list_buf_top..];
    switch (field_nodes.len) {
        0 => {},
        1 => node.data = .{ .bin = .{ .lhs = field_nodes[0], .rhs = .none } },
        2 => node.data = .{ .bin = .{ .lhs = field_nodes[0], .rhs = field_nodes[1] } },
        else => {
            node.tag = .enum_decl;
            node.data = .{ .range = try p.addList(field_nodes) };
        },
    }
    p.decl_buf.items[decl_buf_top - 1] = try p.addNode(node);
    return enum_ty;
}

const Enumerator = struct {
    res: Result,

    fn init(p: *Parser) Enumerator {
        return .{ .res = .{
            .ty = .{ .specifier = if (p.pp.comp.langopts.short_enums) .schar else .int },
            .val = .{ .signed = 0 },
        } };
    }

    /// Increment enumerator value adjusting type if needed.
    fn incr(e: *Enumerator, p: *Parser) !void {
        e.res.node = .none;
        _ = p;
        switch (e.res.val) {
            .unavailable => unreachable,
            .signed => |*v| v.* += 1,
            .unsigned => |*v| v.* += 1,
        }
        // TODO adjust type if value does not fit current
    }

    /// Set enumerator value to specified value, adjusting type if needed.
    fn set(e: *Enumerator, p: *Parser, res: Result) !void {
        _ = p;
        e.res = res;
        // TODO adjust res type to try to fit with the previous type
    }
};

const EnumFieldAndNode = struct { field: Type.Enum.Field, node: NodeIndex };

/// enumerator : IDENTIFIER ('=' constExpr)
fn enumerator(p: *Parser, e: *Enumerator) Error!?EnumFieldAndNode {
    _ = try p.pragma();
    const name_tok = (try p.eatIdentifier()) orelse {
        if (p.tok_ids[p.tok_i] == .r_brace) return null;
        try p.err(.expected_identifier);
        p.skipTo(.r_brace);
        return error.ParsingFailed;
    };
    const name = p.tokSlice(name_tok);
    const attr_buf_top = p.attr_buf.items.len;
    defer p.attr_buf.items.len = attr_buf_top;
    try p.attributeSpecifier(.@"enum");

    if (p.eatToken(.equal)) |_| {
        const specified = try p.constExpr();
        if (specified.val == .unavailable) {
            try p.errTok(.enum_val_unavailable, name_tok + 2);
            try e.incr(p);
        } else {
            try e.set(p, specified);
        }
    } else {
        try e.incr(p);
    }

    if (p.findSymbol(name_tok, .definition)) |scope| switch (scope) {
        .enumeration => |sym| {
            try p.errStr(.redefinition, name_tok, name);
            try p.errTok(.previous_definition, sym.name_tok);
        },
        .decl, .def, .param => |sym| {
            try p.errStr(.redefinition_different_sym, name_tok, name);
            try p.errTok(.previous_definition, sym.name_tok);
        },
        else => unreachable,
    };

    try p.scopes.append(.{ .enumeration = .{
        .name = name,
        .value = e.res,
        .name_tok = name_tok,
    } });
    return EnumFieldAndNode{ .field = .{
        .name = name,
        .ty = e.res.ty,
        .value = e.res.as_u64(),
    }, .node = try p.addNode(.{
        .tag = .enum_field_decl,
        .ty = e.res.ty,
        .data = .{ .decl = .{
            .name = name_tok,
            .node = e.res.node,
        } },
    }) };
}

/// typeQual : keyword_const | keyword_restrict | keyword_volatile | keyword_atomic
fn typeQual(p: *Parser, b: *Type.Qualifiers.Builder) Error!bool {
    var any = false;
    while (true) {
        switch (p.tok_ids[p.tok_i]) {
            .keyword_restrict, .keyword_restrict1, .keyword_restrict2 => {
                if (b.restrict != null)
                    try p.errStr(.duplicate_decl_spec, p.tok_i, "restrict")
                else
                    b.restrict = p.tok_i;
            },
            .keyword_const, .keyword_const1, .keyword_const2 => {
                if (b.@"const" != null)
                    try p.errStr(.duplicate_decl_spec, p.tok_i, "const")
                else
                    b.@"const" = p.tok_i;
            },
            .keyword_volatile, .keyword_volatile1, .keyword_volatile2 => {
                if (b.@"volatile" != null)
                    try p.errStr(.duplicate_decl_spec, p.tok_i, "volatile")
                else
                    b.@"volatile" = p.tok_i;
            },
            .keyword_atomic => {
                // _Atomic(typeName) instead of just _Atomic
                if (p.tok_ids[p.tok_i + 1] == .l_paren) break;
                if (b.atomic != null)
                    try p.errStr(.duplicate_decl_spec, p.tok_i, "atomic")
                else
                    b.atomic = p.tok_i;
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

    const maybe_ident = p.tok_i;
    if (kind != .abstract and (try p.eatIdentifier()) != null) {
        d.name = maybe_ident;
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
    const attr_buf_top = p.attr_buf.items.len;
    defer p.attr_buf.items.len = attr_buf_top;

    if (p.eatToken(.l_bracket)) |l_bracket| {
        var res_ty = Type{
            // so that we can get any restrict type that might be present
            .specifier = .pointer,
        };
        var quals = Type.Qualifiers.Builder{};

        var got_quals = try p.typeQual(&quals);
        var static = p.eatToken(.keyword_static);
        if (static != null and !got_quals) got_quals = try p.typeQual(&quals);
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
            quals = .{};
            star = null;
        } else {
            try quals.finish(p, &res_ty);
        }
        if (static) |_| try size.expect(p);

        const outer = try p.directDeclarator(base_type, d, kind);
        var max_bits = p.pp.comp.target.cpu.arch.ptrBitWidth();
        if (max_bits > 61) max_bits = 61;
        const max_bytes = (@as(u64, 1) << @truncate(u6, max_bits)) - 1;
        const max_elems = max_bytes / std.math.max(1, outer.sizeof(p.pp.comp) orelse 1);

        switch (size.val) {
            .unavailable => if (size.node != .none) {
                if (p.return_type == null and kind != .param) try p.errTok(.variable_len_array_file_scope, l_bracket);
                const expr_ty = try p.arena.create(Type.Expr);
                expr_ty.node = size.node;
                res_ty.data = .{ .expr = expr_ty };
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
                if (arr_ty.len > max_elems) {
                    try p.errTok(.array_too_large, l_bracket);
                    arr_ty.len = max_elems;
                }
                res_ty.data = .{ .array = arr_ty };
                res_ty.specifier = .array;
            },
            .signed => |v| {
                if (v < 0) try p.errTok(.negative_array_size, l_bracket);
                const arr_ty = try p.arena.create(Type.Array);
                arr_ty.len = @bitCast(u64, v);
                if (arr_ty.len > max_elems) {
                    try p.errTok(.array_too_large, l_bracket);
                    arr_ty.len = max_elems;
                }
                res_ty.data = .{ .array = arr_ty };
                res_ty.specifier = .array;
            },
        }

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
        } else if (p.tok_ids[p.tok_i] == .identifier or p.tok_ids[p.tok_i] == .extended_identifier) {
            d.old_style_func = p.tok_i;
            const param_buf_top = p.param_buf.items.len;
            const scopes_top = p.scopes.items.len;
            defer {
                p.param_buf.items.len = param_buf_top;
                p.scopes.items.len = scopes_top;
            }

            // findSymbol stops the search at .block
            try p.scopes.append(.block);

            specifier = .old_style_func;
            while (true) {
                const name_tok = try p.expectIdentifier();
                if (p.findSymbol(name_tok, .definition)) |scope| {
                    try p.errStr(.redefinition_of_parameter, name_tok, p.tokSlice(name_tok));
                    try p.errTok(.previous_definition, scope.param.name_tok);
                }
                try p.scopes.append(.{ .param = .{
                    .name = p.tokSlice(name_tok),
                    .ty = undefined,
                    .name_tok = name_tok,
                } });
                try p.param_buf.append(.{
                    .name = p.tokSlice(name_tok),
                    .name_tok = name_tok,
                    .ty = .{ .specifier = .int },
                });
                if (p.eatToken(.comma) == null) break;
            }
            func_ty.params = try p.arena.dupe(Type.Func.Param, p.param_buf.items[param_buf_top..]);
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
        var quals = Type.Qualifiers.Builder{};
        _ = try p.typeQual(&quals);
        try quals.finish(p, &ty);
    }
    return ty;
}

/// paramDecls : paramDecl (',' paramDecl)* (',' '...')
/// paramDecl : declSpec (declarator | abstractDeclarator)
fn paramDecls(p: *Parser) Error!?[]Type.Func.Param {
    // TODO warn about visibility of types declared here
    const param_buf_top = p.param_buf.items.len;
    const scopes_top = p.scopes.items.len;
    defer {
        p.param_buf.items.len = param_buf_top;
        p.scopes.items.len = scopes_top;
    }

    // findSymbol stops the search at .block
    try p.scopes.append(.block);

    while (true) {
        const param_decl_spec = if (try p.declSpec(true)) |some|
            some
        else if (p.param_buf.items.len == param_buf_top)
            return null
        else blk: {
            var spec: Type.Builder = .{};
            break :blk DeclSpec{ .ty = try spec.finish(p) };
        };

        var name_tok: TokenIndex = 0;
        const first_tok = p.tok_i;
        var param_ty = param_decl_spec.ty;
        if (try p.declarator(param_decl_spec.ty, .param)) |some| {
            if (some.old_style_func) |tok_i| try p.errTok(.invalid_old_style_params, tok_i);
            name_tok = some.name;
            param_ty = some.ty;
            if (some.name != 0) {
                if (p.findSymbol(name_tok, .definition)) |scope| {
                    if (scope == .enumeration) {
                        try p.errStr(.redefinition_of_parameter, name_tok, p.tokSlice(name_tok));
                        try p.errTok(.previous_definition, scope.enumeration.name_tok);
                    } else {
                        try p.errStr(.redefinition_of_parameter, name_tok, p.tokSlice(name_tok));
                        try p.errTok(.previous_definition, scope.param.name_tok);
                    }
                }
                try p.scopes.append(.{ .param = .{
                    .name = p.tokSlice(name_tok),
                    .ty = some.ty,
                    .name_tok = name_tok,
                } });
            }
        }

        if (param_ty.isFunc()) {
            // params declared as functions are converted to function pointers
            const elem_ty = try p.arena.create(Type);
            elem_ty.* = param_ty;
            param_ty = Type{
                .specifier = .pointer,
                .data = .{ .sub_type = elem_ty },
            };
        } else if (param_ty.isArray()) {
            // params declared as arrays are converted to pointers
            param_ty.decayArray();
        } else if (param_ty.is(.void)) {
            // validate void parameters
            if (p.param_buf.items.len == param_buf_top) {
                if (p.tok_ids[p.tok_i] != .r_paren) {
                    try p.err(.void_only_param);
                    if (param_ty.anyQual()) try p.err(.void_param_qualified);
                    return error.ParsingFailed;
                }
                return &[0]Type.Func.Param{};
            }
            try p.err(.void_must_be_first_param);
            return error.ParsingFailed;
        }

        try param_decl_spec.validateParam(p, &param_ty);
        try p.param_buf.append(.{
            .name = if (name_tok == 0) "" else p.tokSlice(name_tok),
            .name_tok = if (name_tok == 0) first_tok else name_tok,
            .ty = param_ty,
        });

        if (p.eatToken(.comma) == null) break;
        if (p.tok_ids[p.tok_i] == .ellipsis) break;
    }
    return try p.arena.dupe(Type.Func.Param, p.param_buf.items[param_buf_top..]);
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
fn initializer(p: *Parser, init_ty: Type) Error!Result {
    // fast path for non-braced initializers
    if (p.tok_ids[p.tok_i] != .l_brace) {
        const tok = p.tok_i;
        var res = try p.assignExpr();
        try res.expect(p);
        if (try p.coerceArrayInit(&res, tok, init_ty)) return res;
        try p.coerceInit(&res, tok, init_ty);
        return res;
    }

    var il: InitList = .{};
    defer il.deinit(p.pp.comp.gpa);

    _ = try p.initializerItem(&il, init_ty);

    const res = try p.convertInitList(il, init_ty);
    var res_ty = p.nodes.items(.ty)[@enumToInt(res)];
    res_ty.qual = init_ty.qual;
    return Result{ .ty = res_ty, .node = res };
}

/// initializerItems : designation? initializer (',' designation? initializer)* ','?
/// designation : designator+ '='
/// designator
///  : '[' constExpr ']'
///  | '.' identifier
fn initializerItem(p: *Parser, il: *InitList, init_ty: Type) Error!bool {
    const l_brace = p.eatToken(.l_brace) orelse {
        const tok = p.tok_i;
        var res = try p.assignExpr();
        if (res.empty(p)) return false;

        const arr = try p.coerceArrayInit(&res, tok, init_ty);
        if (!arr) try p.coerceInit(&res, tok, init_ty);
        if (il.tok != 0) {
            try p.errTok(.initializer_overrides, tok);
            try p.errTok(.previous_initializer, il.tok);
        }
        il.node = res.node;
        il.tok = tok;
        return true;
    };

    const is_scalar = init_ty.isInt() or init_ty.isFloat() or init_ty.isPtr();
    if (p.eatToken(.r_brace)) |_| {
        if (is_scalar) try p.errTok(.empty_scalar_init, l_brace);
        if (il.tok != 0) {
            try p.errTok(.initializer_overrides, l_brace);
            try p.errTok(.previous_initializer, il.tok);
        }
        il.node = .none;
        il.tok = l_brace;
        return true;
    }

    // TODO cleanup here
    var count: u64 = 0;
    var warned_excess = false;
    var is_str_init = false;
    while (true) : (count += 1) {
        errdefer p.skipTo(.r_brace);

        const first_tok = p.tok_i;
        var cur_ty = init_ty;
        var cur_il = il;
        var designation = false;
        while (true) {
            if (p.eatToken(.l_bracket)) |l_bracket| {
                if (!cur_ty.isArray()) {
                    try p.errStr(.invalid_array_designator, l_bracket, try p.typeStr(cur_ty));
                    return error.ParsingFailed;
                }
                const index_res = try p.constExpr();
                try p.expectClosing(l_bracket, .r_bracket);

                const index_unchecked = switch (index_res.val) {
                    .unsigned => |val| val,
                    .signed => |val| if (val < 0) {
                        try p.errExtra(.negative_array_designator, l_bracket + 1, .{ .signed = val });
                        return error.ParsingFailed;
                    } else @intCast(u64, val),
                    .unavailable => unreachable,
                };
                const max_len = cur_ty.arrayLen() orelse std.math.maxInt(usize);
                if (index_unchecked >= max_len) {
                    try p.errExtra(.oob_array_designator, l_bracket + 1, .{ .unsigned = index_unchecked });
                    return error.ParsingFailed;
                }
                const checked = @intCast(usize, index_unchecked);

                cur_il = try cur_il.find(p.pp.comp.gpa, checked);
                cur_ty = cur_ty.elemType();
                designation = true;
            } else if (p.eatToken(.period)) |period| {
                const identifier = try p.expectIdentifier();
                if (!cur_ty.isRecord()) {
                    try p.errStr(.invalid_field_designator, period, try p.typeStr(cur_ty));
                    return error.ParsingFailed;
                }
                const field = cur_ty.getField(p.tokSlice(identifier)) orelse {
                    try p.errStr(.no_such_field_designator, period, p.tokSlice(identifier));
                    return error.ParsingFailed;
                };

                // TODO check if union already has field set
                cur_il = try cur_il.find(p.pp.comp.gpa, field.i);
                cur_ty = field.f.ty;
                designation = true;
            } else break;
        }

        if (designation) _ = try p.expectToken(.equal);

        var saw = false;
        if (is_str_init and p.isStringInit(init_ty)) {
            // discard further strings
            var tmp_il = InitList{};
            defer tmp_il.deinit(p.pp.comp.gpa);
            saw = try p.initializerItem(&tmp_il, .{ .specifier = .void });
        } else if (count == 0 and p.isStringInit(init_ty)) {
            is_str_init = true;
            saw = try p.initializerItem(il, init_ty);
        } else if (is_scalar and count != 0) {
            // discard further scalars
            var tmp_il = InitList{};
            defer tmp_il.deinit(p.pp.comp.gpa);
            saw = try p.initializerItem(&tmp_il, .{ .specifier = .void });
        } else if (p.tok_ids[p.tok_i] == .l_brace) {
            if (cur_ty.isArray()) {
                cur_il = try cur_il.find(p.pp.comp.gpa, count);
                cur_ty = cur_ty.elemType();
                saw = try p.initializerItem(cur_il, cur_ty);
            } else {
                // TODO warn scalar braces
                saw = try p.initializerItem(cur_il, cur_ty);
            }
        } else if (try p.findScalarInitializer(&cur_il, &cur_ty)) {
            saw = try p.initializerItem(cur_il, cur_ty);
        } else if (designation) {
            // designation overrides previous value, let existing mechanism handle it
            saw = try p.initializerItem(cur_il, cur_ty);
        } else {
            // discard further values
            var tmp_il = InitList{};
            defer tmp_il.deinit(p.pp.comp.gpa);
            saw = try p.initializerItem(&tmp_il, .{ .specifier = .void });
            if (!warned_excess) try p.errTok(if (init_ty.isArray()) .excess_array_init else .excess_struct_init, first_tok);
            warned_excess = true;
        }

        if (!saw) {
            if (designation) {
                try p.err(.expected_expr);
                return error.ParsingFailed;
            }
            break;
        } else if (count == 1) {
            if (is_str_init) try p.errTok(.excess_str_init, first_tok);
            if (is_scalar) try p.errTok(.excess_scalar_init, first_tok);
        }

        if (p.eatToken(.comma) == null) break;
    }
    try p.expectClosing(l_brace, .r_brace);

    if (is_scalar or is_str_init) return true;
    if (il.tok != 0) {
        try p.errTok(.initializer_overrides, l_brace);
        try p.errTok(.previous_initializer, il.tok);
    }
    il.node = .none;
    il.tok = l_brace;
    return true;
}

/// Returns true if the value is unused.
fn findScalarInitializer(p: *Parser, il: **InitList, ty: *Type) Error!bool {
    if (ty.isArray()) {
        var index = il.*.list.items.len;
        if (index != 0) index = il.*.list.items[index - 1].index;

        const arr_ty = ty.*;
        const max_elems = arr_ty.arrayLen() orelse std.math.maxInt(usize);
        if (max_elems == 0) {
            if (p.tok_ids[p.tok_i] != .l_brace) {
                try p.err(.empty_aggregate_init_braces);
                return error.ParsingFailed;
            }
            return false;
        }
        const elem_ty = arr_ty.elemType();
        const arr_il = il.*;
        while (index < max_elems) : (index += 1) {
            ty.* = elem_ty;
            il.* = try arr_il.find(p.pp.comp.gpa, index);
            if (try p.findScalarInitializer(il, ty)) return true;
        }
        return false;
    } else if (ty.get(.@"struct")) |struct_ty| {
        var index = il.*.list.items.len;
        if (index != 0) index = il.*.list.items[index - 1].index + 1;

        const max_elems = struct_ty.data.record.fields.len;
        if (max_elems == 0) {
            if (p.tok_ids[p.tok_i] != .l_brace) {
                try p.err(.empty_aggregate_init_braces);
                return error.ParsingFailed;
            }
            return false;
        }
        const struct_il = il.*;
        while (index < max_elems) : (index += 1) {
            const field = struct_ty.data.record.fields[index];
            ty.* = field.ty;
            il.* = try struct_il.find(p.pp.comp.gpa, index);
            if (try p.findScalarInitializer(il, ty)) return true;
        }
        return false;
    } else if (ty.get(.@"union")) |union_ty| {
        if (union_ty.data.record.fields.len == 0) {
            if (p.tok_ids[p.tok_i] != .l_brace) {
                try p.err(.empty_aggregate_init_braces);
                return error.ParsingFailed;
            }
            return false;
        }
        ty.* = union_ty.data.record.fields[0].ty;
        il.* = try il.*.find(p.pp.comp.gpa, 0);
        if (try p.findScalarInitializer(il, ty)) return true;
        return false;
    }
    return il.*.node == .none;
}

fn coerceArrayInit(p: *Parser, item: *Result, tok: TokenIndex, target: Type) !bool {
    if (!target.isArray()) return false;

    if (!item.ty.isArray()) {
        const e_msg = " from incompatible type ";
        try p.errStr(.incompatible_init, tok, try p.typePairStrExtra(target, e_msg, item.ty));
        return true; // do not do further coercion
    }

    if (!target.elemType().eql(item.ty.elemType(), false)) {
        const e_msg = " with array of type ";
        try p.errStr(.incompatible_array_init, tok, try p.typePairStrExtra(target, e_msg, item.ty));
        return true; // do not do further coercion
    }

    if (target.get(.array)) |arr_ty| {
        assert(item.ty.specifier == .array);
        var len = item.ty.arrayLen().?;
        const array_len = arr_ty.arrayLen().?;
        if (p.nodeIs(item.node, .string_literal_expr)) {
            // the null byte of a string can be dropped
            if (len - 1 > array_len)
                try p.errTok(.str_init_too_long, tok);
        } else if (len > array_len) {
            try p.errStr(
                .arr_init_too_long,
                tok,
                try p.typePairStrExtra(target, " with array of type ", item.ty),
            );
        }
    }
    return true;
}

fn coerceInit(p: *Parser, item: *Result, tok: TokenIndex, target: Type) !void {
    if (target.is(.void)) return; // Do not do type coercion on excess items

    // item does not need to be qualified
    var unqual_ty = target.canonicalize(.standard);
    unqual_ty.qual = .{};
    const e_msg = " from incompatible type ";
    try item.lvalConversion(p);
    if (unqual_ty.is(.bool)) {
        // this is ridiculous but it's what clang does
        if (item.ty.isInt() or item.ty.isFloat() or item.ty.isPtr()) {
            try item.boolCast(p, unqual_ty);
        } else {
            try p.errStr(.incompatible_init, tok, try p.typePairStrExtra(target, e_msg, item.ty));
        }
    } else if (unqual_ty.isInt()) {
        if (item.ty.isInt() or item.ty.isFloat()) {
            try item.intCast(p, unqual_ty);
        } else if (item.ty.isPtr()) {
            try p.errStr(.implicit_ptr_to_int, tok, try p.typePairStrExtra(item.ty, " to ", target));
            try item.intCast(p, unqual_ty);
        } else {
            try p.errStr(.incompatible_init, tok, try p.typePairStrExtra(target, e_msg, item.ty));
        }
    } else if (unqual_ty.isFloat()) {
        if (item.ty.isInt() or item.ty.isFloat()) {
            try item.floatCast(p, unqual_ty);
        } else {
            try p.errStr(.incompatible_init, tok, try p.typePairStrExtra(target, e_msg, item.ty));
        }
    } else if (unqual_ty.isPtr()) {
        if (item.isZero()) {
            try item.nullCast(p, target);
        } else if (item.ty.isInt()) {
            try p.errStr(.implicit_int_to_ptr, tok, try p.typePairStrExtra(item.ty, " to ", target));
            try item.ptrCast(p, unqual_ty);
        } else if (item.ty.isPtr()) {
            if (!item.ty.isVoidStar() and !unqual_ty.isVoidStar() and !unqual_ty.eql(item.ty, false)) {
                try p.errStr(.incompatible_ptr_init, tok, try p.typePairStrExtra(target, e_msg, item.ty));
                try item.ptrCast(p, unqual_ty);
            } else if (!unqual_ty.eql(item.ty, true)) {
                if (!unqual_ty.elemType().qual.hasQuals(item.ty.elemType().qual)) {
                    try p.errStr(.ptr_init_discards_quals, tok, try p.typePairStrExtra(target, e_msg, item.ty));
                }
                try item.ptrCast(p, unqual_ty);
            }
        } else {
            try p.errStr(.incompatible_init, tok, try p.typePairStrExtra(target, e_msg, item.ty));
        }
    } else if (unqual_ty.isRecord()) {
        if (!unqual_ty.eql(item.ty, false))
            try p.errStr(.incompatible_init, tok, try p.typePairStrExtra(target, e_msg, item.ty));
    } else if (unqual_ty.isArray() or unqual_ty.isFunc()) {
        // we have already issued an error for this
    } else {
        try p.errStr(.incompatible_init, tok, try p.typePairStrExtra(target, e_msg, item.ty));
    }
}

fn isStringInit(p: *Parser, ty: Type) bool {
    if (!ty.isArray() or !ty.elemType().isInt()) return false;
    var i = p.tok_i;
    while (true) : (i += 1) {
        switch (p.tok_ids[i]) {
            .l_paren => {},
            .string_literal,
            .string_literal_utf_16,
            .string_literal_utf_8,
            .string_literal_utf_32,
            .string_literal_wide,
            => return true,
            else => return false,
        }
    }
}

/// Convert InitList into an AST
fn convertInitList(p: *Parser, il: InitList, init_ty: Type) Error!NodeIndex {
    if (init_ty.isInt() or init_ty.isFloat() or init_ty.isPtr()) {
        if (il.node == .none) {
            return p.addNode(.{ .tag = .default_init_expr, .ty = init_ty, .data = undefined });
        }
        return il.node;
    } else if (init_ty.is(.variable_len_array)) {
        return error.ParsingFailed; // vla invalid, reported earlier
    } else if (init_ty.isArray()) {
        if (init_ty.elemType().hasIncompleteSize()) {
            return error.ParsingFailed; // array element type invalid, reported earlier
        }
        if (il.node != .none) {
            return il.node;
        }
        const list_buf_top = p.list_buf.items.len;
        defer p.list_buf.items.len = list_buf_top;

        const elem_ty = init_ty.elemType();

        const max_items = init_ty.arrayLen() orelse std.math.maxInt(usize);
        var start: u64 = 0;
        for (il.list.items) |*init| {
            if (init.index > start) {
                const elem = try p.addNode(.{
                    .tag = .array_filler_expr,
                    .ty = elem_ty,
                    .data = .{ .int = init.index - start },
                });
                try p.list_buf.append(elem);
            }
            start = init.index + 1;

            const elem = try p.convertInitList(init.list, elem_ty);
            try p.list_buf.append(elem);
        }

        var arr_init_node: Tree.Node = .{
            .tag = .array_init_expr_two,
            .ty = init_ty,
            .data = .{ .bin = .{ .lhs = .none, .rhs = .none } },
        };

        if (init_ty.specifier == .incomplete_array) {
            arr_init_node.ty.specifier = .array;
            arr_init_node.ty.data.array.len = start;
        } else if (init_ty.is(.incomplete_array)) {
            const arr_ty = try p.arena.create(Type.Array);
            arr_ty.* = .{ .elem = init_ty.elemType(), .len = start };
            arr_init_node.ty = .{
                .specifier = .array,
                .data = .{ .array = arr_ty },
                .alignment = init_ty.alignment,
            };
        } else if (start < max_items) {
            const elem = try p.addNode(.{
                .tag = .array_filler_expr,
                .ty = elem_ty,
                .data = .{ .int = max_items - start },
            });
            try p.list_buf.append(elem);
        }

        const items = p.list_buf.items[list_buf_top..];
        switch (items.len) {
            0 => {},
            1 => arr_init_node.data.bin.lhs = items[0],
            2 => arr_init_node.data.bin = .{ .lhs = items[0], .rhs = items[1] },
            else => {
                arr_init_node.tag = .array_init_expr;
                arr_init_node.data = .{ .range = try p.addList(items) };
            },
        }
        return try p.addNode(arr_init_node);
    } else if (init_ty.get(.@"struct")) |struct_ty| {
        assert(!struct_ty.hasIncompleteSize());

        const list_buf_top = p.list_buf.items.len;
        defer p.list_buf.items.len = list_buf_top;

        var init_index: usize = 0;
        for (struct_ty.data.record.fields) |f, i| {
            if (init_index < il.list.items.len and il.list.items[init_index].index == i) {
                const item = try p.convertInitList(il.list.items[init_index].list, f.ty);
                try p.list_buf.append(item);
                init_index += 1;
            } else {
                const item = try p.addNode(.{ .tag = .default_init_expr, .ty = f.ty, .data = undefined });
                try p.list_buf.append(item);
            }
        }

        var struct_init_node: Tree.Node = .{
            .tag = .struct_init_expr_two,
            .ty = init_ty,
            .data = .{ .bin = .{ .lhs = .none, .rhs = .none } },
        };
        const items = p.list_buf.items[list_buf_top..];
        switch (items.len) {
            0 => {},
            1 => struct_init_node.data.bin.lhs = items[0],
            2 => struct_init_node.data.bin = .{ .lhs = items[0], .rhs = items[1] },
            else => {
                struct_init_node.tag = .struct_init_expr;
                struct_init_node.data = .{ .range = try p.addList(items) };
            },
        }
        return try p.addNode(struct_init_node);
    } else if (init_ty.get(.@"union")) |union_ty| {
        var union_init_node: Tree.Node = .{
            .tag = .union_init_expr,
            .ty = init_ty,
            .data = .{ .union_init = .{ .field_index = 0, .node = .none } },
        };
        if (union_ty.data.record.fields.len == 0) {
            // do nothing for empty unions
        } else if (il.list.items.len == 0) {
            union_init_node.data.union_init.node = try p.addNode(.{
                .tag = .default_init_expr,
                .ty = init_ty,
                .data = undefined,
            });
        } else {
            const init = il.list.items[0];
            const field_ty = union_ty.data.record.fields[init.index].ty;
            union_init_node.data.union_init = .{
                .field_index = @truncate(u32, init.index),
                .node = try p.convertInitList(init.list, field_ty),
            };
        }
        return try p.addNode(union_init_node);
    } else if (init_ty.isFunc()) {
        return error.ParsingFailed; // invalid func initializer, reported earlier
    } else {
        unreachable;
    }
}

/// assembly : keyword_asm asmQual* '(' asmStr ')'
fn assembly(p: *Parser, kind: enum { global, decl, stmt }) Error!?NodeIndex {
    switch (p.tok_ids[p.tok_i]) {
        .keyword_asm, .keyword_asm1, .keyword_asm2 => p.tok_i += 1,
        else => return null,
    }

    var @"volatile" = false;
    var @"inline" = false;
    var goto = false;
    while (true) : (p.tok_i += 1) switch (p.tok_ids[p.tok_i]) {
        .keyword_volatile, .keyword_volatile1, .keyword_volatile2 => {
            if (kind != .stmt) try p.errStr(.meaningless_asm_qual, p.tok_i, "volatile");
            if (@"volatile") try p.errStr(.duplicate_asm_qual, p.tok_i, "volatile");
            @"volatile" = true;
        },
        .keyword_inline, .keyword_inline1, .keyword_inline2 => {
            if (kind != .stmt) try p.errStr(.meaningless_asm_qual, p.tok_i, "inline");
            if (@"inline") try p.errStr(.duplicate_asm_qual, p.tok_i, "inline");
            @"inline" = true;
        },
        .keyword_goto => {
            if (kind != .stmt) try p.errStr(.meaningless_asm_qual, p.tok_i, "goto");
            if (goto) try p.errStr(.duplicate_asm_qual, p.tok_i, "goto");
            goto = true;
        },
        else => break,
    };

    const l_paren = try p.expectToken(.l_paren);
    if (kind != .stmt) {
        _ = try p.asmStr();
    } else {
        return p.todo("assembly statements");
    }
    try p.expectClosing(l_paren, .r_paren);

    if (kind != .decl) _ = try p.expectToken(.semicolon);
    return .none;
}

/// Same as stringLiteral but errors on unicode and wide string literals
fn asmStr(p: *Parser) Error!NodeIndex {
    var i = p.tok_i;
    while (true) : (i += 1) switch (p.tok_ids[i]) {
        .string_literal => {},
        .string_literal_utf_16, .string_literal_utf_8, .string_literal_utf_32 => {
            try p.errStr(.invalid_asm_str, p.tok_i, "unicode");
            return error.ParsingFailed;
        },
        .string_literal_wide => {
            try p.errStr(.invalid_asm_str, p.tok_i, "wide");
            return error.ParsingFailed;
        },
        else => break,
    };
    return (try p.stringLiteral()).node;
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
///  | keyword_goto (IDENTIFIER | ('*' expr)) ';'
///  | keyword_continue ';'
///  | keyword_break ';'
///  | keyword_return expr? ';'
///  | assembly ';'
///  | expr? ';'
fn stmt(p: *Parser) Error!NodeIndex {
    if (try p.labeledStmt()) |some| return some;
    if (try p.compoundStmt(false)) |some| return some;
    if (p.eatToken(.keyword_if)) |_| {
        const start_scopes_len = p.scopes.items.len;
        defer p.scopes.items.len = start_scopes_len;

        const l_paren = try p.expectToken(.l_paren);
        var cond = try p.expr();
        try cond.expect(p);
        try cond.lvalConversion(p);
        if (cond.ty.isInt())
            try cond.intCast(p, cond.ty.integerPromotion(p.pp.comp))
        else if (!cond.ty.isFloat() and !cond.ty.isPtr())
            try p.errStr(.statement_scalar, l_paren + 1, try p.typeStr(cond.ty));
        try cond.saveValue(p);
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
        var cond = try p.expr();
        try cond.expect(p);
        try cond.lvalConversion(p);
        if (cond.ty.isInt())
            try cond.intCast(p, cond.ty.integerPromotion(p.pp.comp))
        else
            try p.errStr(.statement_int, l_paren + 1, try p.typeStr(cond.ty));
        try cond.saveValue(p);
        try p.expectClosing(l_paren, .r_paren);

        var switch_scope = Scope.Switch{
            .cases = Scope.Switch.CaseMap.init(p.pp.comp.gpa),
        };
        defer switch_scope.cases.deinit();
        try p.scopes.append(.{ .@"switch" = &switch_scope });
        const body = try p.stmt();

        return try p.addNode(.{
            .tag = .switch_stmt,
            .data = .{ .bin = .{ .lhs = cond.node, .rhs = body } },
        });
    }
    if (p.eatToken(.keyword_while)) |_| {
        const start_scopes_len = p.scopes.items.len;
        defer p.scopes.items.len = start_scopes_len;

        const l_paren = try p.expectToken(.l_paren);
        var cond = try p.expr();
        try cond.expect(p);
        try cond.lvalConversion(p);
        if (cond.ty.isInt())
            try cond.intCast(p, cond.ty.integerPromotion(p.pp.comp))
        else if (!cond.ty.isFloat() and !cond.ty.isPtr())
            try p.errStr(.statement_scalar, l_paren + 1, try p.typeStr(cond.ty));
        try cond.saveValue(p);
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
        var cond = try p.expr();
        try cond.expect(p);
        try cond.lvalConversion(p);
        if (cond.ty.isInt())
            try cond.intCast(p, cond.ty.integerPromotion(p.pp.comp))
        else if (!cond.ty.isFloat() and !cond.ty.isPtr())
            try p.errStr(.statement_scalar, l_paren + 1, try p.typeStr(cond.ty));
        try cond.saveValue(p);
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
        const decl_buf_top = p.decl_buf.items.len;
        defer p.decl_buf.items.len = decl_buf_top;

        const l_paren = try p.expectToken(.l_paren);
        const got_decl = try p.decl();

        // for (init
        const init_start = p.tok_i;
        var err_start = p.pp.comp.diag.list.items.len;
        var init = if (!got_decl) try p.expr() else Result{};
        try init.saveValue(p);
        try init.maybeWarnUnused(p, init_start, err_start);
        if (!got_decl) _ = try p.expectToken(.semicolon);

        // for (init; cond
        var cond = try p.expr();
        if (cond.node != .none) {
            try cond.lvalConversion(p);
            if (cond.ty.isInt())
                try cond.intCast(p, cond.ty.integerPromotion(p.pp.comp))
            else if (!cond.ty.isFloat() and !cond.ty.isPtr())
                try p.errStr(.statement_scalar, l_paren + 1, try p.typeStr(cond.ty));
        }
        try cond.saveValue(p);
        _ = try p.expectToken(.semicolon);

        // for (init; cond; incr
        const incr_start = p.tok_i;
        err_start = p.pp.comp.diag.list.items.len;
        var incr = try p.expr();
        try incr.maybeWarnUnused(p, incr_start, err_start);
        try incr.saveValue(p);
        try p.expectClosing(l_paren, .r_paren);

        try p.scopes.append(.loop);
        const body = try p.stmt();

        if (got_decl) {
            const start = (try p.addList(p.decl_buf.items[decl_buf_top..])).start;
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
        } else return try p.addNode(.{ .tag = .for_stmt, .data = .{ .if3 = .{
            .cond = body,
            .body = (try p.addList(&.{ init.node, cond.node, incr.node })).start,
        } } });
    }
    if (p.eatToken(.keyword_goto)) |goto_tok| {
        if (p.eatToken(.asterisk)) |_| {
            const expr_tok = p.tok_i;
            var e = try p.expr();
            try e.expect(p);
            try e.lvalConversion(p);
            p.computed_goto_tok = goto_tok;
            if (!e.ty.isPtr()) {
                if (!e.ty.isInt()) {
                    try p.errStr(.incompatible_param, expr_tok, try p.typeStr(e.ty));
                    return error.ParsingFailed;
                }
                const elem_ty = try p.arena.create(Type);
                elem_ty.* = .{ .specifier = .void, .qual = .{ .@"const" = true } };
                const result_ty = Type{
                    .specifier = .pointer,
                    .data = .{ .sub_type = elem_ty },
                };
                if (e.isZero()) {
                    try e.nullCast(p, result_ty);
                } else {
                    try p.errStr(.implicit_int_to_ptr, expr_tok, try p.typePairStrExtra(e.ty, " to ", result_ty));
                    try e.ptrCast(p, result_ty);
                }
            }

            try e.un(p, .computed_goto_stmt);
            _ = try p.expectToken(.semicolon);
            return e.node;
        }
        const name_tok = try p.expectIdentifier();
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
    if (try p.returnStmt()) |some| return some;
    if (try p.assembly(.stmt)) |some| return some;

    const expr_start = p.tok_i;
    const err_start = p.pp.comp.diag.list.items.len;

    const e = try p.expr();
    if (e.node != .none) {
        _ = try p.expectToken(.semicolon);
        try e.maybeWarnUnused(p, expr_start, err_start);
        return e.node;
    }

    const attr_buf_top = p.attr_buf.items.len;
    defer p.attr_buf.items.len = attr_buf_top;
    try p.attributeSpecifier(.statement);
    const attrs = p.attr_buf.items[attr_buf_top..];

    if (p.eatToken(.semicolon)) |_| {
        var null_node: Tree.Node = .{ .tag = .null_stmt, .data = undefined };
        if (attrs.len > 0) {
            if (p.tok_ids[p.tok_i] != .keyword_case and p.tok_ids[p.tok_i] != .keyword_default) {
                // TODO: this condition is not completely correct; the last statement of a compound
                // statement is also valid if it precedes a switch label (so intervening '}' are ok,
                // but only if they close a compound statement)
                try p.errTok(.invalid_fallthrough, expr_start);
            }
            var attributed_type = try p.arena.create(Type.Attributed);
            attributed_type.* = .{
                .attributes = try p.arena.dupe(Attribute, attrs),
                .base = null_node.ty,
            };
            null_node.ty = .{ .specifier = .attributed, .data = .{ .attributed = attributed_type } };
        }
        return p.addNode(null_node);
    }

    try p.err(.expected_stmt);
    return error.ParsingFailed;
}

/// labeledStmt
/// : IDENTIFIER ':' stmt
/// | keyword_case constExpr ':' stmt
/// | keyword_default ':' stmt
fn labeledStmt(p: *Parser) Error!?NodeIndex {
    if ((p.tok_ids[p.tok_i] == .identifier or p.tok_ids[p.tok_i] == .extended_identifier) and p.tok_ids[p.tok_i + 1] == .colon) {
        const name_tok = p.expectIdentifier() catch unreachable;
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

        p.tok_i += 1;
        const attr_buf_top = p.attr_buf.items.len;
        defer p.attr_buf.items.len = attr_buf_top;
        try p.attributeSpecifier(.label);

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
            if (val.val == .unavailable) {
                try p.errTok(.case_val_unavailable, case + 1);
                return node;
            }
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

/// compoundStmt : '{' ( decl | keyword_extension decl | staticAssert | stmt)* '}'
fn compoundStmt(p: *Parser, is_fn_body: bool) Error!?NodeIndex {
    const l_brace = p.eatToken(.l_brace) orelse return null;

    const decl_buf_top = p.decl_buf.items.len;
    defer p.decl_buf.items.len = decl_buf_top;

    const scopes_top = p.scopes.items.len;
    defer p.scopes.items.len = scopes_top;
    // the parameters of a function are in the same scope as the body
    if (!is_fn_body) try p.scopes.append(.block);

    var noreturn_index: ?TokenIndex = null;
    var noreturn_label_count: u32 = 0;

    while (p.eatToken(.r_brace) == null) : (_ = try p.pragma()) {
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
        if (p.eatToken(.keyword_extension)) |ext| {
            const saved_extension = p.extension_suppressed;
            defer p.extension_suppressed = saved_extension;
            p.extension_suppressed = true;

            if (p.decl() catch |er| switch (er) {
                error.ParsingFailed => {
                    try p.nextStmt(l_brace);
                    continue;
                },
                else => |e| return e,
            }) continue;
            p.tok_i = ext;
        }
        const s = p.stmt() catch |er| switch (er) {
            error.ParsingFailed => {
                try p.nextStmt(l_brace);
                continue;
            },
            else => |e| return e,
        };
        if (s == .none) continue;
        try p.decl_buf.append(s);

        if (noreturn_index == null and p.nodeIsNoreturn(s)) {
            noreturn_index = p.tok_i;
            noreturn_label_count = p.label_count;
        }
        switch (p.nodes.items(.tag)[@enumToInt(s)]) {
            .case_stmt, .default_stmt, .labeled_stmt => noreturn_index = null,
            else => {},
        }
    }

    if (noreturn_index) |some| {
        // if new labels were defined we cannot be certain that the code is unreachable
        if (some != p.tok_i - 1 and noreturn_label_count == p.label_count) try p.errTok(.unreachable_code, some);
    }
    if (is_fn_body and (p.decl_buf.items.len == decl_buf_top or !p.nodeIsNoreturn(p.decl_buf.items[p.decl_buf.items.len - 1]))) {
        if (!p.return_type.?.is(.void)) try p.errStr(.func_does_not_return, p.tok_i - 1, p.tokSlice(p.func_name));
        try p.decl_buf.append(try p.addNode(.{ .tag = .implicit_return, .ty = p.return_type.?, .data = undefined }));
    }

    var node: Tree.Node = .{
        .tag = .compound_stmt_two,
        .data = .{ .bin = .{ .lhs = .none, .rhs = .none } },
    };
    const statements = p.decl_buf.items[decl_buf_top..];
    switch (statements.len) {
        0 => {},
        1 => node.data = .{ .bin = .{ .lhs = statements[0], .rhs = .none } },
        2 => node.data = .{ .bin = .{ .lhs = statements[0], .rhs = statements[1] } },
        else => {
            node.tag = .compound_stmt;
            node.data = .{ .range = try p.addList(statements) };
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
        .compound_stmt_two => {
            const data = p.nodes.items(.data)[@enumToInt(node)];
            if (data.bin.rhs != .none) return p.nodeIsNoreturn(data.bin.rhs);
            if (data.bin.lhs != .none) return p.nodeIsNoreturn(data.bin.lhs);
            return false;
        },
        .compound_stmt => {
            const data = p.nodes.items(.data)[@enumToInt(node)];
            return p.nodeIsNoreturn(p.data.items[data.range.end - 1]);
        },
        .labeled_stmt => {
            const data = p.nodes.items(.data)[@enumToInt(node)];
            return p.nodeIsNoreturn(data.decl.node);
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
            .keyword_inline1,
            .keyword_inline2,
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
            .keyword_typeof,
            .keyword_typeof1,
            .keyword_typeof2,
            .keyword_extension,
            => if (parens == 0) return,
            .keyword_pragma => p.skipToPragmaSentinel(),
            else => {},
        }
    }
    p.tok_i -= 1; // So we can consume EOF
    try p.expectClosing(l_brace, .r_brace);
    unreachable;
}

fn returnStmt(p: *Parser) Error!?NodeIndex {
    const ret_tok = p.eatToken(.keyword_return) orelse return null;

    const e_tok = p.tok_i;
    var e = try p.expr();
    _ = try p.expectToken(.semicolon);
    const ret_ty = p.return_type.?;

    if (e.node == .none) {
        if (!ret_ty.is(.void)) try p.errStr(.func_should_return, ret_tok, p.tokSlice(p.func_name));
        return try p.addNode(.{ .tag = .return_stmt, .data = .{ .un = e.node } });
    } else if (ret_ty.is(.void)) {
        try p.errStr(.void_func_returns_value, e_tok, p.tokSlice(p.func_name));
        return try p.addNode(.{ .tag = .return_stmt, .data = .{ .un = e.node } });
    }

    try e.lvalConversion(p);
    // Return type conversion is done as if it was assignment
    if (ret_ty.is(.bool)) {
        // this is ridiculous but it's what clang does
        if (e.ty.isInt() or e.ty.isFloat() or e.ty.isPtr()) {
            try e.boolCast(p, ret_ty);
        } else {
            try p.errStr(.incompatible_return, e_tok, try p.typeStr(e.ty));
        }
    } else if (ret_ty.isInt()) {
        if (e.ty.isInt() or e.ty.isFloat()) {
            try e.intCast(p, ret_ty);
        } else if (e.ty.isPtr()) {
            try p.errStr(.implicit_ptr_to_int, e_tok, try p.typePairStrExtra(e.ty, " to ", ret_ty));
            try e.intCast(p, ret_ty);
        } else {
            try p.errStr(.incompatible_return, e_tok, try p.typeStr(e.ty));
        }
    } else if (ret_ty.isFloat()) {
        if (e.ty.isInt() or e.ty.isFloat()) {
            try e.floatCast(p, ret_ty);
        } else {
            try p.errStr(.incompatible_return, e_tok, try p.typeStr(e.ty));
        }
    } else if (ret_ty.isPtr()) {
        if (e.isZero()) {
            try e.nullCast(p, ret_ty);
        } else if (e.ty.isInt()) {
            try p.errStr(.implicit_int_to_ptr, e_tok, try p.typePairStrExtra(e.ty, " to ", ret_ty));
            try e.intCast(p, ret_ty);
        } else if (!e.ty.isVoidStar() and !ret_ty.isVoidStar() and !ret_ty.eql(e.ty, false)) {
            try p.errStr(.incompatible_return, e_tok, try p.typeStr(e.ty));
        }
    } else if (ret_ty.isRecord()) {
        if (!ret_ty.eql(e.ty, false)) {
            try p.errStr(.incompatible_return, e_tok, try p.typeStr(e.ty));
        }
    } else unreachable;

    try e.saveValue(p);
    return try p.addNode(.{ .tag = .return_stmt, .data = .{ .un = e.node } });
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

const Result = struct {
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

    fn isZero(res: Result) bool {
        return switch (res.val) {
            .signed => |v| v == 0,
            .unsigned => |v| v == 0,
            .unavailable => false,
        };
    }

    fn expect(res: Result, p: *Parser) Error!void {
        if (p.in_macro) {
            if (res.val == .unavailable) {
                try p.errTok(.expected_expr, p.tok_i);
                return error.ParsingFailed;
            }
            return;
        }
        if (res.node == .none) {
            try p.errTok(.expected_expr, p.tok_i);
            return error.ParsingFailed;
        }
    }

    fn empty(res: Result, p: *Parser) bool {
        if (p.in_macro) return res.val == .unavailable;
        return res.node == .none;
    }

    fn maybeWarnUnused(res: Result, p: *Parser, expr_start: TokenIndex, err_start: usize) Error!void {
        if (res.ty.is(.void) or res.node == .none) return;
        // don't warn about unused result if the expression contained errors
        if (p.pp.comp.diag.list.items.len > err_start) return;
        var cur_node = res.node;
        while (true) switch (p.nodes.items(.tag)[@enumToInt(cur_node)]) {
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
            .pre_inc_expr,
            .pre_dec_expr,
            .post_inc_expr,
            .post_dec_expr,
            => return,
            .comma_expr => cur_node = p.nodes.items(.data)[@enumToInt(cur_node)].bin.rhs,
            .paren_expr => cur_node = p.nodes.items(.data)[@enumToInt(cur_node)].un,
            else => break,
        };
        try p.errTok(.unused_value, expr_start);
    }

    fn bin(lhs: *Result, p: *Parser, tag: Tree.Tag, rhs: Result) !void {
        lhs.node = try p.addNode(.{
            .tag = tag,
            .ty = lhs.ty,
            .data = .{ .bin = .{ .lhs = lhs.node, .rhs = rhs.node } },
        });
    }

    fn un(operand: *Result, p: *Parser, tag: Tree.Tag) Error!void {
        operand.node = try p.addNode(.{
            .tag = tag,
            .ty = operand.ty,
            .data = .{ .un = operand.node },
        });
    }

    fn qualCast(res: *Result, p: *Parser, elem_ty: *Type) Error!void {
        res.ty = .{
            .data = .{ .sub_type = elem_ty },
            .specifier = .pointer,
        };
        try res.un(p, .qual_cast);
    }

    fn adjustCondExprPtrs(a: *Result, tok: TokenIndex, b: *Result, p: *Parser) !bool {
        assert(a.ty.isPtr() and b.ty.isPtr());

        const a_elem = a.ty.elemType();
        const b_elem = b.ty.elemType();
        if (a_elem.eql(b_elem, true)) return true;

        var adjusted_elem_ty = try p.arena.create(Type);
        adjusted_elem_ty.* = a_elem;

        const has_void_star_branch = a.ty.isVoidStar() or b.ty.isVoidStar();
        const only_quals_differ = a_elem.eql(b_elem, false);
        const pointers_compatible = only_quals_differ or has_void_star_branch;

        if (!pointers_compatible or has_void_star_branch) {
            if (!pointers_compatible) {
                try p.errStr(.pointer_mismatch, tok, try p.typePairStrExtra(a.ty, " and ", b.ty));
            }
            adjusted_elem_ty.* = .{ .specifier = .void };
        }
        if (pointers_compatible) {
            adjusted_elem_ty.qual = a_elem.qual.mergeCV(b_elem.qual);
        }
        if (!adjusted_elem_ty.eql(a_elem, true)) try a.qualCast(p, adjusted_elem_ty);
        if (!adjusted_elem_ty.eql(b_elem, true)) try b.qualCast(p, adjusted_elem_ty);
        return true;
    }

    /// Adjust types for binary operation, returns true if the result can and should be evaluated.
    fn adjustTypes(a: *Result, tok: TokenIndex, b: *Result, p: *Parser, kind: enum {
        integer,
        arithmetic,
        boolean_logic,
        relational,
        equality,
        conditional,
        add,
        sub,
    }) !bool {
        try a.lvalConversion(p);
        try b.lvalConversion(p);

        const a_int = a.ty.isInt();
        const b_int = b.ty.isInt();
        if (a_int and b_int) {
            try a.usualArithmeticConversion(b, p);
            return a.shouldEval(b, p);
        }
        if (kind == .integer) return a.invalidBinTy(tok, b, p);

        const a_float = a.ty.isFloat();
        const b_float = b.ty.isFloat();
        const a_arithmetic = a_int or a_float;
        const b_arithmetic = b_int or b_float;
        if (a_arithmetic and b_arithmetic) {
            // <, <=, >, >= only work on real types
            if (kind == .relational and (!a.ty.isReal() or !b.ty.isReal()))
                return a.invalidBinTy(tok, b, p);

            try a.usualArithmeticConversion(b, p);
            return a.shouldEval(b, p);
        }
        if (kind == .arithmetic) return a.invalidBinTy(tok, b, p);

        const a_ptr = a.ty.isPtr();
        const b_ptr = b.ty.isPtr();
        const a_scalar = a_arithmetic or a_ptr;
        const b_scalar = b_arithmetic or b_ptr;
        switch (kind) {
            .boolean_logic => {
                if (!a_scalar or !b_scalar) return a.invalidBinTy(tok, b, p);

                // Do integer promotions but nothing else
                if (a_int) try a.intCast(p, a.ty.integerPromotion(p.pp.comp));
                if (b_int) try b.intCast(p, b.ty.integerPromotion(p.pp.comp));
                return a.shouldEval(b, p);
            },
            .relational, .equality => {
                // comparisons between floats and pointes not allowed
                if (!a_scalar or !b_scalar or (a_float and b_ptr) or (b_float and a_ptr))
                    return a.invalidBinTy(tok, b, p);

                if ((a_int or b_int) and !(a.isZero() or b.isZero())) {
                    try p.errStr(.comparison_ptr_int, tok, try p.typePairStr(a.ty, b.ty));
                } else if (a_ptr and b_ptr) {
                    if (!a.ty.isVoidStar() and !b.ty.isVoidStar() and !a.ty.eql(b.ty, false))
                        try p.errStr(.comparison_distinct_ptr, tok, try p.typePairStr(a.ty, b.ty));
                } else if (a_ptr) {
                    try b.ptrCast(p, a.ty);
                } else {
                    assert(b_ptr);
                    try a.ptrCast(p, b.ty);
                }

                return a.shouldEval(b, p);
            },
            .conditional => {
                // doesn't matter what we return here, as the result is ignored
                if (a.ty.is(.void) or b.ty.is(.void)) {
                    try a.toVoid(p);
                    try b.toVoid(p);
                    return true;
                }
                if ((a_ptr and b_int) or (a_int and b_ptr)) {
                    if (a.isZero() or b.isZero()) {
                        try a.nullCast(p, b.ty);
                        try b.nullCast(p, a.ty);
                        return true;
                    }
                    const int_ty = if (a_int) a else b;
                    const ptr_ty = if (a_ptr) a else b;
                    try p.errStr(.implicit_int_to_ptr, tok, try p.typePairStrExtra(int_ty.ty, " to ", ptr_ty.ty));
                    try int_ty.ptrCast(p, ptr_ty.ty);

                    return true;
                }
                if (a_ptr and b_ptr) return a.adjustCondExprPtrs(tok, b, p);
                if (a.ty.isRecord() and b.ty.isRecord() and a.ty.eql(b.ty, false)) {
                    return true;
                }
                return a.invalidBinTy(tok, b, p);
            },
            .add => {
                // if both aren't arithmetic one should be pointer and the other an integer
                if (a_ptr == b_ptr or a_int == b_int) return a.invalidBinTy(tok, b, p);

                // Do integer promotions but nothing else
                if (a_int) try a.intCast(p, a.ty.integerPromotion(p.pp.comp));
                if (b_int) try b.intCast(p, b.ty.integerPromotion(p.pp.comp));

                // The result type is the type of the pointer operand
                if (a_int) a.ty = b.ty else b.ty = a.ty;
                return a.shouldEval(b, p);
            },
            .sub => {
                // if both aren't arithmetic then either both should be pointers or just a
                if (!a_ptr or !(b_ptr or b_int)) return a.invalidBinTy(tok, b, p);

                if (a_ptr and b_ptr) {
                    if (!a.ty.eql(b.ty, false)) try p.errStr(.incompatible_pointers, tok, try p.typePairStr(a.ty, b.ty));
                    a.ty = Type.ptrDiffT(p.pp.comp);
                }

                // Do integer promotion on b if needed
                if (b_int) try b.intCast(p, b.ty.integerPromotion(p.pp.comp));
                return a.shouldEval(b, p);
            },
            else => return a.invalidBinTy(tok, b, p),
        }
    }

    fn lvalConversion(res: *Result, p: *Parser) Error!void {
        if (res.ty.isFunc()) {
            var elem_ty = try p.arena.create(Type);
            elem_ty.* = res.ty;
            res.ty.specifier = .pointer;
            res.ty.data = .{ .sub_type = elem_ty };
            res.ty.alignment = 0;
            try res.un(p, .function_to_pointer);
        } else if (res.ty.isArray()) {
            res.ty.decayArray();
            res.ty.alignment = 0;
            try res.un(p, .array_to_pointer);
        } else if (!p.in_macro and Tree.isLval(p.nodes.slice(), p.data.items, p.value_map, res.node)) {
            res.ty.qual = .{};
            res.ty.alignment = 0;
            try res.un(p, .lval_to_rval);
        }
    }

    fn boolCast(res: *Result, p: *Parser, bool_ty: Type) Error!void {
        if (res.ty.isPtr()) {
            res.ty = bool_ty;
            try res.un(p, .pointer_to_bool);
        } else if (res.ty.isInt() and !res.ty.is(.bool)) {
            res.ty = bool_ty;
            try res.un(p, .int_to_bool);
        } else if (res.ty.isFloat()) {
            res.ty = bool_ty;
            try res.un(p, .float_to_bool);
        }
    }

    fn intCast(res: *Result, p: *Parser, int_ty: Type) Error!void {
        if (res.ty.is(.bool)) {
            res.ty = int_ty;
            try res.un(p, .bool_to_int);
        } else if (res.ty.isPtr()) {
            res.ty = int_ty;
            try res.un(p, .pointer_to_int);
        } else if (res.ty.isFloat()) {
            res.ty = int_ty;
            try res.un(p, .float_to_int);
        } else if (!res.ty.eql(int_ty, true)) {
            res.ty = int_ty;
            try res.un(p, .int_cast);
        }

        const is_unsigned = int_ty.isUnsignedInt(p.pp.comp);
        if (is_unsigned and res.val == .signed) {
            const copy = res.val.signed;
            res.val = .{ .unsigned = @bitCast(u64, copy) };
        } else if (!is_unsigned and res.val == .unsigned) {
            const copy = res.val.unsigned;
            res.val = .{ .signed = @bitCast(i64, copy) };
        }
    }

    fn floatCast(res: *Result, p: *Parser, float_ty: Type) Error!void {
        if (res.ty.is(.bool)) {
            res.ty = float_ty;
            try res.un(p, .bool_to_float);
        } else if (res.ty.isInt()) {
            res.ty = float_ty;
            try res.un(p, .int_to_float);
        } else if (!res.ty.eql(float_ty, true)) {
            res.ty = float_ty;
            try res.un(p, .float_cast);
        }
    }

    fn ptrCast(res: *Result, p: *Parser, ptr_ty: Type) Error!void {
        if (res.ty.is(.bool)) {
            res.ty = ptr_ty;
            try res.un(p, .bool_to_pointer);
        } else if (res.ty.isInt()) {
            res.ty = ptr_ty;
            try res.un(p, .int_to_pointer);
        }
    }

    fn toVoid(res: *Result, p: *Parser) Error!void {
        if (!res.ty.is(.void)) {
            res.ty = .{ .specifier = .void };
            res.node = try p.addNode(.{
                .tag = .to_void,
                .ty = res.ty,
                .data = .{ .un = res.node },
            });
        }
    }

    fn nullCast(res: *Result, p: *Parser, ptr_ty: Type) Error!void {
        if (!res.isZero()) return;
        res.ty = ptr_ty;
        try res.un(p, .null_to_pointer);
    }

    fn usualArithmeticConversion(a: *Result, b: *Result, p: *Parser) Error!void {
        // if either is a float cast to that type
        if (Type.eitherLongDouble(a.ty, b.ty)) |ty| {
            try a.floatCast(p, ty);
            try b.floatCast(p, ty);
            return;
        }
        if (Type.eitherDouble(a.ty, b.ty)) |ty| {
            try a.floatCast(p, ty);
            try b.floatCast(p, ty);
            return;
        }
        if (Type.eitherFloat(a.ty, b.ty)) |ty| {
            try a.floatCast(p, ty);
            try b.floatCast(p, ty);
            return;
        }

        // Do integer promotion on both operands
        const a_promoted = a.ty.integerPromotion(p.pp.comp);
        const b_promoted = b.ty.integerPromotion(p.pp.comp);
        if (a_promoted.eql(b_promoted, true)) {
            // cast to promoted type
            try a.intCast(p, a_promoted);
            try b.intCast(p, a_promoted);
            return;
        }

        const a_unsigned = a_promoted.isUnsignedInt(p.pp.comp);
        const b_unsigned = b_promoted.isUnsignedInt(p.pp.comp);
        if (a_unsigned == b_unsigned) {
            // cast to greater signed or unsigned type
            const res_spec = std.math.max(@enumToInt(a_promoted.specifier), @enumToInt(b_promoted.specifier));
            const res_ty = Type{ .specifier = @intToEnum(Type.Specifier, res_spec) };
            try a.intCast(p, res_ty);
            try b.intCast(p, res_ty);
            return;
        }

        // cast to the unsigned type with greater rank
        const a_larger = @enumToInt(a_promoted.specifier) > @enumToInt(b_promoted.specifier);
        const b_larger = @enumToInt(b_promoted.specifier) > @enumToInt(b_promoted.specifier);
        if (a_unsigned) {
            const target = if (a_larger) a_promoted else b_promoted;
            try a.intCast(p, target);
            try b.intCast(p, target);
        } else {
            assert(b_unsigned);
            const target = if (b_larger) b_promoted else a_promoted;
            try a.intCast(p, target);
            try b.intCast(p, target);
        }
    }

    fn invalidBinTy(a: *Result, tok: TokenIndex, b: *Result, p: *Parser) Error!bool {
        try p.errStr(.invalid_bin_types, tok, try p.typePairStr(a.ty, b.ty));
        return false;
    }

    fn shouldEval(a: *Result, b: *Result, p: *Parser) Error!bool {
        if (p.no_eval) return false;
        if (a.val != .unavailable and b.val != .unavailable)
            return true;

        try a.saveValue(p);
        try b.saveValue(p);
        return p.no_eval;
    }

    fn saveValue(res: *Result, p: *Parser) !void {
        assert(!p.in_macro);
        switch (res.val) {
            .unsigned => |v| try p.value_map.put(res.node, v),
            .signed => |v| try p.value_map.put(res.node, @bitCast(u64, v)),
            .unavailable => return,
        }
        res.val = .unavailable;
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
        const size = a.ty.sizeof(p.pp.comp).?;
        var overflow = false;
        switch (a.val) {
            .unsigned => |*v| {
                switch (size) {
                    1 => unreachable, // promoted to int
                    2 => unreachable, // promoted to int
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
                    1 => unreachable, // promoted to int
                    2 => unreachable, // promoted to int
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
        const size = a.ty.sizeof(p.pp.comp).?;
        var overflow = false;
        switch (a.val) {
            .unsigned => |*v| {
                switch (size) {
                    1 => unreachable, // promoted to int
                    2 => unreachable, // promoted to int
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
                    1 => unreachable, // promoted to int
                    2 => unreachable, // promoted to int
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
        const size = a.ty.sizeof(p.pp.comp).?;
        var overflow = false;
        switch (a.val) {
            .unsigned => |*v| {
                switch (size) {
                    1 => unreachable, // promoted to int
                    2 => unreachable, // promoted to int
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
                    1 => unreachable, // promoted to int
                    2 => unreachable, // promoted to int
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
    var err_start = p.pp.comp.diag.list.items.len;
    var lhs = try p.assignExpr();
    if (p.tok_ids[p.tok_i] == .comma) try lhs.expect(p);
    while (p.eatToken(.comma)) |_| {
        try lhs.maybeWarnUnused(p, expr_start, err_start);
        expr_start = p.tok_i;
        err_start = p.pp.comp.diag.list.items.len;

        const rhs = try p.assignExpr();
        try rhs.expect(p);
        lhs.val = rhs.val;
        lhs.ty = rhs.ty;
        try lhs.bin(p, .comma_expr, rhs);
    }
    return lhs;
}

fn tokToTag(p: *Parser, tok: TokenIndex) Tree.Tag {
    return switch (p.tok_ids[tok]) {
        .equal => .assign_expr,
        .asterisk_equal => .mul_assign_expr,
        .slash_equal => .div_assign_expr,
        .percent_equal => .mod_assign_expr,
        .plus_equal => .add_assign_expr,
        .minus_equal => .sub_assign_expr,
        .angle_bracket_angle_bracket_left_equal => .shl_assign_expr,
        .angle_bracket_angle_bracket_right_equal => .shr_assign_expr,
        .ampersand_equal => .bit_and_assign_expr,
        .caret_equal => .bit_xor_assign_expr,
        .pipe_equal => .bit_or_assign_expr,
        .equal_equal => .equal_expr,
        .bang_equal => .not_equal_expr,
        .angle_bracket_left => .less_than_expr,
        .angle_bracket_left_equal => .less_than_equal_expr,
        .angle_bracket_right => .greater_than_expr,
        .angle_bracket_right_equal => .greater_than_equal_expr,
        .angle_bracket_angle_bracket_left => .shl_expr,
        .angle_bracket_angle_bracket_right => .shr_expr,
        .plus => .add_expr,
        .minus => .sub_expr,
        .asterisk => .mul_expr,
        .slash => .div_expr,
        .percent => .mod_expr,
        else => unreachable,
    };
}

/// assignExpr
///  : condExpr
///  | unExpr ('=' | '*=' | '/=' | '%=' | '+=' | '-=' | '<<=' | '>>=' | '&=' | '^=' | '|=') assignExpr
fn assignExpr(p: *Parser) Error!Result {
    var lhs = try p.condExpr();
    if (lhs.empty(p)) return lhs;

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

    const tag = p.tokToTag(bit_or orelse return lhs);
    var rhs = try p.assignExpr();
    try rhs.expect(p);
    try rhs.lvalConversion(p);

    var is_const: bool = undefined;
    if (!Tree.isLvalExtra(p.nodes.slice(), p.data.items, p.value_map, lhs.node, &is_const) or is_const) {
        try p.errTok(.not_assignable, tok);
        return error.ParsingFailed;
    }

    // adjustTypes will do do lvalue conversion but we do not want that
    var lhs_copy = lhs;
    switch (tag) {
        .assign_expr => {}, // handle plain assignment separately
        .mul_assign_expr,
        .div_assign_expr,
        .mod_assign_expr,
        => {
            if (rhs.isZero()) {
                switch (tag) {
                    .div_assign_expr => try p.errStr(.division_by_zero, div.?, "division"),
                    .mod_assign_expr => try p.errStr(.division_by_zero, mod.?, "remainder"),
                    else => {},
                }
            }
            _ = try lhs_copy.adjustTypes(tok, &rhs, p, .arithmetic);
            try lhs.bin(p, tag, rhs);
            return lhs;
        },
        .sub_assign_expr,
        .add_assign_expr,
        => {
            if (lhs.ty.isPtr() and rhs.ty.isInt()) {
                try rhs.ptrCast(p, lhs.ty);
            } else {
                _ = try lhs_copy.adjustTypes(tok, &rhs, p, .arithmetic);
            }
            try lhs.bin(p, tag, rhs);
            return lhs;
        },
        .shl_assign_expr,
        .shr_assign_expr,
        .bit_and_assign_expr,
        .bit_xor_assign_expr,
        .bit_or_assign_expr,
        => {
            _ = try lhs_copy.adjustTypes(tok, &rhs, p, .integer);
            try lhs.bin(p, tag, rhs);
            return lhs;
        },
        else => unreachable,
    }

    // rhs does not need to be qualified
    var unqual_ty = lhs.ty.canonicalize(.standard);
    unqual_ty.qual = .{};
    const e_msg = " from incompatible type ";
    if (lhs.ty.is(.bool)) {
        // this is ridiculous but it's what clang does
        if (rhs.ty.isInt() or rhs.ty.isFloat() or rhs.ty.isPtr()) {
            try rhs.boolCast(p, unqual_ty);
        } else {
            try p.errStr(.incompatible_assign, tok, try p.typePairStrExtra(lhs.ty, e_msg, rhs.ty));
        }
    } else if (unqual_ty.isInt()) {
        if (rhs.ty.isInt() or rhs.ty.isFloat()) {
            try rhs.intCast(p, unqual_ty);
        } else if (rhs.ty.isPtr()) {
            try p.errStr(.implicit_ptr_to_int, tok, try p.typePairStrExtra(rhs.ty, " to ", lhs.ty));
            try rhs.intCast(p, unqual_ty);
        } else {
            try p.errStr(.incompatible_assign, tok, try p.typePairStrExtra(lhs.ty, e_msg, rhs.ty));
        }
    } else if (unqual_ty.isFloat()) {
        if (rhs.ty.isInt() or rhs.ty.isFloat()) {
            try rhs.floatCast(p, unqual_ty);
        } else {
            try p.errStr(.incompatible_assign, tok, try p.typePairStrExtra(lhs.ty, e_msg, rhs.ty));
        }
    } else if (unqual_ty.isPtr()) {
        if (rhs.isZero()) {
            try rhs.nullCast(p, lhs.ty);
        } else if (rhs.ty.isInt()) {
            try p.errStr(.implicit_int_to_ptr, tok, try p.typePairStrExtra(rhs.ty, " to ", lhs.ty));
            try rhs.ptrCast(p, unqual_ty);
        } else if (rhs.ty.isPtr()) {
            if (!unqual_ty.isVoidStar() and !rhs.ty.isVoidStar() and !unqual_ty.eql(rhs.ty, false)) {
                try p.errStr(.incompatible_ptr_assign, tok, try p.typePairStrExtra(lhs.ty, e_msg, rhs.ty));
                try rhs.ptrCast(p, unqual_ty);
            } else if (!unqual_ty.eql(rhs.ty, true)) {
                if (!unqual_ty.elemType().qual.hasQuals(rhs.ty.elemType().qual)) {
                    try p.errStr(.ptr_assign_discards_quals, tok, try p.typePairStrExtra(lhs.ty, e_msg, rhs.ty));
                }
                try rhs.ptrCast(p, unqual_ty);
            }
        } else {
            try p.errStr(.incompatible_assign, tok, try p.typePairStrExtra(lhs.ty, e_msg, rhs.ty));
        }
    } else if (unqual_ty.isRecord()) {
        if (!unqual_ty.eql(rhs.ty, false))
            try p.errStr(.incompatible_assign, tok, try p.typePairStrExtra(lhs.ty, e_msg, rhs.ty));
    } else if (unqual_ty.isArray() or unqual_ty.isFunc()) {
        try p.errTok(.not_assignable, tok);
    } else {
        try p.errStr(.incompatible_assign, tok, try p.typePairStrExtra(lhs.ty, e_msg, rhs.ty));
    }

    try lhs.bin(p, tag, rhs);
    return lhs;
}

/// constExpr : condExpr
fn constExpr(p: *Parser) Error!Result {
    const start = p.tok_i;
    const res = try p.condExpr();
    try res.expect(p);
    if (!res.ty.isInt()) {
        try p.errTok(.expected_integer_constant_expr, start);
        return error.ParsingFailed;
    }
    // saveValue sets val to unavailable
    var copy = res;
    try copy.saveValue(p);
    return res;
}

/// condExpr : lorExpr ('?' expression? ':' condExpr)?
fn condExpr(p: *Parser) Error!Result {
    var cond = try p.lorExpr();
    if (cond.empty(p) or p.eatToken(.question_mark) == null) return cond;
    const saved_eval = p.no_eval;

    // Depending on the value of the condition, avoid evaluating unreachable branches.
    var then_expr = blk: {
        defer p.no_eval = saved_eval;
        if (cond.val != .unavailable and !cond.getBool()) p.no_eval = true;
        break :blk try p.expr();
    };
    try then_expr.expect(p); // TODO binary cond expr
    const colon = try p.expectToken(.colon);
    var else_expr = blk: {
        defer p.no_eval = saved_eval;
        if (cond.val != .unavailable and cond.getBool()) p.no_eval = true;
        break :blk try p.condExpr();
    };
    try else_expr.expect(p);

    _ = try then_expr.adjustTypes(colon, &else_expr, p, .conditional);

    if (cond.val != .unavailable) {
        cond.val = if (cond.getBool()) then_expr.val else else_expr.val;
    } else {
        try then_expr.saveValue(p);
        try else_expr.saveValue(p);
    }
    cond.ty = then_expr.ty;
    cond.node = try p.addNode(.{
        .tag = .cond_expr,
        .ty = cond.ty,
        .data = .{ .if3 = .{ .cond = cond.node, .body = (try p.addList(&.{ then_expr.node, else_expr.node })).start } },
    });
    return cond;
}

/// lorExpr : landExpr ('||' landExpr)*
fn lorExpr(p: *Parser) Error!Result {
    var lhs = try p.landExpr();
    if (lhs.empty(p)) return lhs;
    const saved_eval = p.no_eval;
    defer p.no_eval = saved_eval;

    while (p.eatToken(.pipe_pipe)) |tok| {
        if (lhs.val != .unavailable and lhs.getBool()) p.no_eval = true;
        var rhs = try p.landExpr();
        try rhs.expect(p);

        if (try lhs.adjustTypes(tok, &rhs, p, .boolean_logic)) {
            const res = @boolToInt(lhs.getBool() or rhs.getBool());
            lhs.val = .{ .signed = res };
        }
        lhs.ty = .{ .specifier = .int };
        try lhs.bin(p, .bool_or_expr, rhs);
    }
    return lhs;
}

/// landExpr : orExpr ('&&' orExpr)*
fn landExpr(p: *Parser) Error!Result {
    var lhs = try p.orExpr();
    if (lhs.empty(p)) return lhs;
    const saved_eval = p.no_eval;
    defer p.no_eval = saved_eval;

    while (p.eatToken(.ampersand_ampersand)) |tok| {
        if (lhs.val != .unavailable and !lhs.getBool()) p.no_eval = true;
        var rhs = try p.orExpr();
        try rhs.expect(p);

        if (try lhs.adjustTypes(tok, &rhs, p, .boolean_logic)) {
            const res = @boolToInt(lhs.getBool() and rhs.getBool());
            lhs.val = .{ .signed = res };
        }
        lhs.ty = .{ .specifier = .int };
        try lhs.bin(p, .bool_and_expr, rhs);
    }
    return lhs;
}

/// orExpr : xorExpr ('|' xorExpr)*
fn orExpr(p: *Parser) Error!Result {
    var lhs = try p.xorExpr();
    if (lhs.empty(p)) return lhs;
    while (p.eatToken(.pipe)) |tok| {
        var rhs = try p.xorExpr();
        try rhs.expect(p);

        if (try lhs.adjustTypes(tok, &rhs, p, .integer)) {
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
    if (lhs.empty(p)) return lhs;
    while (p.eatToken(.caret)) |tok| {
        var rhs = try p.andExpr();
        try rhs.expect(p);

        if (try lhs.adjustTypes(tok, &rhs, p, .integer)) {
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
    if (lhs.empty(p)) return lhs;
    while (p.eatToken(.ampersand)) |tok| {
        var rhs = try p.eqExpr();
        try rhs.expect(p);

        if (try lhs.adjustTypes(tok, &rhs, p, .integer)) {
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
    if (lhs.empty(p)) return lhs;
    while (true) {
        const eq = p.eatToken(.equal_equal);
        const ne = eq orelse p.eatToken(.bang_equal);
        const tag = p.tokToTag(ne orelse break);
        var rhs = try p.compExpr();
        try rhs.expect(p);

        if (try lhs.adjustTypes(ne.?, &rhs, p, .equality)) {
            const res = if (tag == .equal_expr)
                lhs.compare(.eq, rhs)
            else
                lhs.compare(.neq, rhs);

            lhs.val = .{ .signed = @boolToInt(res) };
        }
        lhs.ty = .{ .specifier = .int };
        try lhs.bin(p, tag, rhs);
    }
    return lhs;
}

/// compExpr : shiftExpr (('<' | '<=' | '>' | '>=') shiftExpr)*
fn compExpr(p: *Parser) Error!Result {
    var lhs = try p.shiftExpr();
    if (lhs.empty(p)) return lhs;
    while (true) {
        const lt = p.eatToken(.angle_bracket_left);
        const le = lt orelse p.eatToken(.angle_bracket_left_equal);
        const gt = le orelse p.eatToken(.angle_bracket_right);
        const ge = gt orelse p.eatToken(.angle_bracket_right_equal);
        const tag = p.tokToTag(ge orelse break);
        var rhs = try p.shiftExpr();
        try rhs.expect(p);

        if (try lhs.adjustTypes(ge.?, &rhs, p, .relational)) {
            const res = @boolToInt(switch (tag) {
                .less_than_expr => lhs.compare(.lt, rhs),
                .less_than_equal_expr => lhs.compare(.lte, rhs),
                .greater_than_expr => lhs.compare(.gt, rhs),
                .greater_than_equal_expr => lhs.compare(.gte, rhs),
                else => unreachable,
            });
            lhs.val = .{ .signed = res };
        }
        lhs.ty = .{ .specifier = .int };
        try lhs.bin(p, tag, rhs);
    }
    return lhs;
}

/// shiftExpr : addExpr (('<<' | '>>') addExpr)*
fn shiftExpr(p: *Parser) Error!Result {
    var lhs = try p.addExpr();
    if (lhs.empty(p)) return lhs;
    while (true) {
        const shl = p.eatToken(.angle_bracket_angle_bracket_left);
        const shr = shl orelse p.eatToken(.angle_bracket_angle_bracket_right);
        const tag = p.tokToTag(shr orelse break);
        var rhs = try p.addExpr();
        try rhs.expect(p);

        if (try lhs.adjustTypes(shr.?, &rhs, p, .integer)) {
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
        try lhs.bin(p, tag, rhs);
    }
    return lhs;
}

/// addExpr : mulExpr (('+' | '-') mulExpr)*
fn addExpr(p: *Parser) Error!Result {
    var lhs = try p.mulExpr();
    if (lhs.empty(p)) return lhs;
    while (true) {
        const plus = p.eatToken(.plus);
        const minus = plus orelse p.eatToken(.minus);
        const tag = p.tokToTag(minus orelse break);
        var rhs = try p.mulExpr();
        try rhs.expect(p);

        if (try lhs.adjustTypes(minus.?, &rhs, p, if (plus != null) .add else .sub)) {
            if (plus != null) {
                try lhs.add(plus.?, rhs, p);
            } else {
                try lhs.sub(minus.?, rhs, p);
            }
        }
        try lhs.bin(p, tag, rhs);
    }
    return lhs;
}

/// Implements C's % operator for signed integers, for evaluating constant expressions
/// caller guarantees rhs != 0
/// caller guarantees lhs != std.math.minInt(i64) OR rhs != -1
fn signedRemainder(lhs: i64, rhs: i64) i64 {
    if (rhs > 0) return @rem(lhs, rhs);
    return lhs - @divTrunc(lhs, rhs) * rhs;
}

/// mulExpr : castExpr (('*' | '/' | '%') castExpr)*´
fn mulExpr(p: *Parser) Error!Result {
    var lhs = try p.castExpr();
    if (lhs.empty(p)) return lhs;
    while (true) {
        const mul = p.eatToken(.asterisk);
        const div = mul orelse p.eatToken(.slash);
        const percent = div orelse p.eatToken(.percent);
        const tag = p.tokToTag(percent orelse break);
        var rhs = try p.castExpr();
        try rhs.expect(p);

        if (rhs.isZero() and mul == null and !p.no_eval) {
            const err_tag: Diagnostics.Tag = if (p.in_macro) .division_by_zero_macro else .division_by_zero;
            lhs.val = .unavailable;
            if (div != null) {
                try p.errStr(err_tag, div.?, "division");
            } else {
                try p.errStr(err_tag, percent.?, "remainder");
            }
            if (p.in_macro) return error.ParsingFailed;
        }

        if (try lhs.adjustTypes(percent.?, &rhs, p, if (tag == .mod_expr) .integer else .arithmetic)) {
            if (mul != null) {
                try lhs.mul(mul.?, rhs, p);
            } else if (div != null) {
                lhs.val = switch (lhs.val) {
                    .unsigned => |v| .{ .unsigned = v / rhs.val.unsigned },
                    .signed => |v| .{ .signed = @divFloor(v, rhs.val.signed) },
                    else => unreachable,
                };
            } else {
                if (lhs.val == .signed and lhs.val.signed == std.math.minInt(i64) and rhs.val.signed == -1) {
                    lhs.val = if (p.in_macro) .{ .signed = 0 } else .unavailable;
                } else {
                    lhs.val = switch (lhs.val) {
                        .unsigned => |v| .{ .unsigned = v % rhs.val.unsigned },
                        .signed => |v| .{ .signed = signedRemainder(v, rhs.val.signed) },
                        else => unreachable,
                    };
                }
            }
        }

        try lhs.bin(p, tag, rhs);
    }
    return lhs;
}

/// castExpr
///  :  '(' typeName ')' castExpr
///  | '(' typeName ')' '{' initializerItems '}'
///  | __builtin_choose_expr '(' constExpr ',' assignExpr ',' assignExpr ')'
///  | unExpr
fn castExpr(p: *Parser) Error!Result {
    if (p.eatToken(.l_paren)) |l_paren| {
        if (try p.typeName()) |ty| {
            try p.expectClosing(l_paren, .r_paren);
            if (p.tok_ids[p.tok_i] == .l_brace) {
                // compound literal
                if (ty.isFunc()) {
                    try p.err(.func_init);
                } else if (ty.is(.variable_len_array)) {
                    try p.err(.vla_init);
                }
                var init_list_expr = try p.initializer(ty);
                try init_list_expr.un(p, .compound_literal_expr);
                return init_list_expr;
            }
            var operand = try p.castExpr();
            try operand.expect(p);
            if (ty.is(.void)) {
                // everything can cast to void
            } else if (ty.isInt() or ty.isFloat() or ty.isPtr()) {
                if (ty.isFloat() and operand.ty.isPtr())
                    try p.errStr(.invalid_cast_to_float, l_paren, try p.typeStr(operand.ty));
                if (operand.ty.isFloat() and ty.isPtr())
                    try p.errStr(.invalid_cast_to_pointer, l_paren, try p.typeStr(operand.ty));

                const is_unsigned = ty.isUnsignedInt(p.pp.comp);
                if (is_unsigned and operand.val == .signed) {
                    const copy = operand.val.signed;
                    operand.val = .{ .unsigned = @bitCast(u64, copy) };
                } else if (!is_unsigned and operand.val == .unsigned) {
                    const copy = operand.val.unsigned;
                    operand.val = .{ .signed = @bitCast(i64, copy) };
                }
            } else {
                try p.errStr(.invalid_cast_type, l_paren, try p.typeStr(operand.ty));
            }
            if (ty.anyQual()) try p.errStr(.qual_cast, l_paren, try p.typeStr(ty));
            operand.ty = ty;
            operand.ty.qual = .{};
            try operand.un(p, .cast_expr);
            return operand;
        }
        p.tok_i -= 1;
    }
    switch (p.tok_ids[p.tok_i]) {
        .builtin_choose_expr => return p.builtinChooseExpr(),
        // TODO: other special-cased builtins
        else => {},
    }
    return p.unExpr();
}

/// unExpr
///  : primaryExpr suffixExpr*
///  | '&&' IDENTIFIER
///  | ('&' | '*' | '+' | '-' | '~' | '!' | '++' | '--' | keyword_extension) castExpr
///  | keyword_sizeof unExpr
///  | keyword_sizeof '(' typeName ')'
///  | keyword_alignof '(' typeName ')'
fn unExpr(p: *Parser) Error!Result {
    const tok = p.tok_i;
    switch (p.tok_ids[tok]) {
        .ampersand_ampersand => {
            const address_tok = p.tok_i;
            p.tok_i += 1;
            const name_tok = try p.expectIdentifier();
            try p.errTok(.gnu_label_as_value, address_tok);
            p.contains_address_of_label = true;

            const str = p.tokSlice(name_tok);
            if (p.findLabel(str) == null) {
                try p.labels.append(.{ .unresolved_goto = name_tok });
            }
            const elem_ty = try p.arena.create(Type);
            elem_ty.* = .{ .specifier = .void };
            const result_ty = Type{ .specifier = .pointer, .data = .{ .sub_type = elem_ty } };
            return Result{
                .node = try p.addNode(.{
                    .tag = .addr_of_label,
                    .data = .{ .decl_ref = name_tok },
                    .ty = result_ty,
                }),
                .ty = result_ty,
            };
        },
        .ampersand => {
            if (p.in_macro) {
                try p.err(.invalid_preproc_operator);
                return error.ParsingFailed;
            }
            p.tok_i += 1;
            var operand = try p.castExpr();
            try operand.expect(p);

            const slice = p.nodes.slice();
            if (!Tree.isLval(slice, p.data.items, p.value_map, operand.node)) {
                try p.errTok(.addr_of_rvalue, tok);
            }
            if (operand.ty.qual.register) try p.errTok(.addr_of_register, tok);

            const elem_ty = try p.arena.create(Type);
            elem_ty.* = operand.ty;
            operand.ty = Type{
                .specifier = .pointer,
                .data = .{ .sub_type = elem_ty },
            };
            try operand.un(p, .addr_of_expr);
            return operand;
        },
        .asterisk => {
            const asterisk_loc = p.tok_i;
            p.tok_i += 1;
            var operand = try p.castExpr();
            try operand.expect(p);

            if (operand.ty.isArray() or operand.ty.isPtr()) {
                operand.ty = operand.ty.elemType();
            } else if (!operand.ty.isFunc()) {
                try p.errTok(.indirection_ptr, tok);
            }
            if (operand.ty.hasIncompleteSize() and !operand.ty.is(.void)) {
                try p.errStr(.deref_incomplete_ty_ptr, asterisk_loc, try p.typeStr(operand.ty));
            }
            operand.ty.qual = .{};
            try operand.un(p, .deref_expr);
            return operand;
        },
        .plus => {
            p.tok_i += 1;

            var operand = try p.castExpr();
            try operand.expect(p);
            try operand.lvalConversion(p);
            if (!operand.ty.isInt() and !operand.ty.isFloat())
                try p.errStr(.invalid_argument_un, tok, try p.typeStr(operand.ty));

            if (operand.ty.isInt()) try operand.intCast(p, operand.ty.integerPromotion(p.pp.comp));
            return operand;
        },
        .minus => {
            p.tok_i += 1;

            var operand = try p.castExpr();
            try operand.expect(p);
            try operand.lvalConversion(p);
            if (!operand.ty.isInt() and !operand.ty.isFloat())
                try p.errStr(.invalid_argument_un, tok, try p.typeStr(operand.ty));

            if (operand.ty.isInt()) try operand.intCast(p, operand.ty.integerPromotion(p.pp.comp));

            const size = operand.ty.sizeof(p.pp.comp).?;
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
            try operand.un(p, .negate_expr);
            return operand;
        },
        .plus_plus => {
            p.tok_i += 1;

            var operand = try p.castExpr();
            try operand.expect(p);
            if (!operand.ty.isInt() and !operand.ty.isFloat() and !operand.ty.isReal() and !operand.ty.isPtr())
                try p.errStr(.invalid_argument_un, tok, try p.typeStr(operand.ty));

            if (!Tree.isLval(p.nodes.slice(), p.data.items, p.value_map, operand.node) or operand.ty.isConst()) {
                try p.errTok(.not_assignable, tok);
                return error.ParsingFailed;
            }
            if (operand.ty.isInt()) try operand.intCast(p, operand.ty.integerPromotion(p.pp.comp));

            // TODO overflow
            switch (operand.val) {
                .unsigned => |*v| v.* += 1,
                .signed => |*v| v.* += 1,
                .unavailable => {},
            }

            try operand.un(p, .pre_inc_expr);
            return operand;
        },
        .minus_minus => {
            p.tok_i += 1;

            var operand = try p.castExpr();
            try operand.expect(p);
            if (!operand.ty.isInt() and !operand.ty.isFloat() and !operand.ty.isReal() and !operand.ty.isPtr())
                try p.errStr(.invalid_argument_un, tok, try p.typeStr(operand.ty));

            if (!Tree.isLval(p.nodes.slice(), p.data.items, p.value_map, operand.node) or operand.ty.isConst()) {
                try p.errTok(.not_assignable, tok);
                return error.ParsingFailed;
            }
            if (operand.ty.isInt()) try operand.intCast(p, operand.ty.integerPromotion(p.pp.comp));

            // TODO overflow
            switch (operand.val) {
                .unsigned => |*v| v.* -= 1,
                .signed => |*v| v.* -= 1,
                .unavailable => {},
            }

            try operand.un(p, .pre_dec_expr);
            return operand;
        },
        .tilde => {
            p.tok_i += 1;

            var operand = try p.castExpr();
            try operand.expect(p);
            try operand.lvalConversion(p);
            if (!operand.ty.isInt()) try p.errStr(.invalid_argument_un, tok, try p.typeStr(operand.ty));
            if (operand.ty.isInt()) try operand.intCast(p, operand.ty.integerPromotion(p.pp.comp));
            switch (operand.val) {
                .unsigned => |*v| v.* = ~v.*,
                .signed => |*v| v.* = ~v.*,
                .unavailable => {},
            }

            try operand.un(p, .bool_not_expr);
            return operand;
        },
        .bang => {
            p.tok_i += 1;

            var operand = try p.castExpr();
            try operand.expect(p);
            try operand.lvalConversion(p);
            if (!operand.ty.isInt() and !operand.ty.isFloat() and !operand.ty.isPtr())
                try p.errStr(.invalid_argument_un, tok, try p.typeStr(operand.ty));

            if (operand.ty.isInt()) try operand.intCast(p, operand.ty.integerPromotion(p.pp.comp));
            if (operand.val != .unavailable) {
                const res = @boolToInt(!operand.getBool());
                operand.val = .{ .signed = res };
            }
            operand.ty = .{ .specifier = .int };
            try operand.un(p, .bool_not_expr);
            return operand;
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
                    res = try p.parseNoEval(unExpr);
                }
            } else {
                res = try p.parseNoEval(unExpr);
            }

            if (res.ty.sizeof(p.pp.comp)) |size| {
                res.val = .{ .unsigned = size };
            } else {
                res.val = .unavailable;
                try p.errStr(.invalid_sizeof, expected_paren - 1, try p.typeStr(res.ty));
            }
            res.ty = Type.sizeT(p.pp.comp);
            try res.un(p, .sizeof_expr);
            return res;
        },
        .keyword_alignof, .keyword_alignof1, .keyword_alignof2 => {
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
                    res = try p.parseNoEval(unExpr);
                    try p.errTok(.alignof_expr, expected_paren);
                }
            } else {
                res = try p.parseNoEval(unExpr);
                try p.errTok(.alignof_expr, expected_paren);
            }

            res.ty = Type.sizeT(p.pp.comp);
            res.val = .{ .unsigned = res.ty.alignof(p.pp.comp) };
            try res.un(p, .alignof_expr);
            return res;
        },
        .keyword_extension => {
            p.tok_i += 1;
            const saved_extension = p.extension_suppressed;
            defer p.extension_suppressed = saved_extension;
            p.extension_suppressed = true;

            var child = try p.castExpr();
            try child.expect(p);
            return child;
        },
        else => {
            var lhs = try p.primaryExpr();
            if (lhs.empty(p)) return lhs;
            while (true) {
                const suffix = try p.suffixExpr(lhs);
                if (suffix.empty(p)) break;
                lhs = suffix;
            }
            return lhs;
        },
    }
}

fn builtinChooseExpr(p: *Parser) Error!Result {
    p.tok_i += 1;
    const l_paren = try p.expectToken(.l_paren);
    const cond_tok = p.tok_i;
    var cond = try p.constExpr();
    if (cond.val == .unavailable) {
        try p.errTok(.builtin_choose_cond, cond_tok);
        return error.ParsingFailed;
    }

    _ = try p.expectToken(.comma);

    var then_expr = if (cond.getBool()) try p.assignExpr() else try p.parseNoEval(assignExpr);
    try then_expr.expect(p);

    _ = try p.expectToken(.comma);

    var else_expr = if (!cond.getBool()) try p.assignExpr() else try p.parseNoEval(assignExpr);
    try else_expr.expect(p);

    try p.expectClosing(l_paren, .r_paren);

    if (cond.getBool()) {
        cond.val = then_expr.val;
        cond.ty = then_expr.ty;
    } else {
        cond.val = else_expr.val;
        cond.ty = else_expr.ty;
    }
    cond.node = try p.addNode(.{
        .tag = .builtin_choose_expr,
        .ty = cond.ty,
        .data = .{ .if3 = .{ .cond = cond.node, .body = (try p.addList(&.{ then_expr.node, else_expr.node })).start } },
    });
    return cond;
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
    assert(!lhs.empty(p));
    switch (p.tok_ids[p.tok_i]) {
        .l_paren => return p.callExpr(lhs),
        .plus_plus => {
            defer p.tok_i += 1;

            var operand = lhs;
            if (!operand.ty.isInt() and !operand.ty.isFloat() and !operand.ty.isReal() and !operand.ty.isPtr())
                try p.errStr(.invalid_argument_un, p.tok_i, try p.typeStr(operand.ty));

            if (!Tree.isLval(p.nodes.slice(), p.data.items, p.value_map, operand.node) or operand.ty.isConst()) {
                try p.err(.not_assignable);
                return error.ParsingFailed;
            }
            if (operand.ty.isInt()) try operand.intCast(p, operand.ty.integerPromotion(p.pp.comp));

            try operand.un(p, .post_dec_expr);
            return operand;
        },
        .minus_minus => {
            defer p.tok_i += 1;

            var operand = lhs;
            if (!operand.ty.isInt() and !operand.ty.isFloat() and !operand.ty.isReal() and !operand.ty.isPtr())
                try p.errStr(.invalid_argument_un, p.tok_i, try p.typeStr(operand.ty));

            if (!Tree.isLval(p.nodes.slice(), p.data.items, p.value_map, operand.node) or operand.ty.isConst()) {
                try p.err(.not_assignable);
                return error.ParsingFailed;
            }
            if (operand.ty.isInt()) try operand.intCast(p, operand.ty.integerPromotion(p.pp.comp));

            try operand.un(p, .post_dec_expr);
            return operand;
        },
        .l_bracket => {
            const l_bracket = p.tok_i;
            p.tok_i += 1;
            var index = try p.expr();
            try index.expect(p);
            try p.expectClosing(l_bracket, .r_bracket);

            const l_ty = lhs.ty;
            const r_ty = index.ty;
            var ptr = lhs;
            try ptr.lvalConversion(p);
            try index.lvalConversion(p);
            if (ptr.ty.isPtr()) {
                ptr.ty = ptr.ty.elemType();
                if (!index.ty.isInt()) try p.errTok(.invalid_index, l_bracket);
                try p.checkArrayBounds(index, l_ty, l_bracket);
            } else if (index.ty.isPtr()) {
                index.ty = index.ty.elemType();
                if (!ptr.ty.isInt()) try p.errTok(.invalid_index, l_bracket);
                try p.checkArrayBounds(ptr, r_ty, l_bracket);
                std.mem.swap(Result, &ptr, &index);
            } else {
                try p.errTok(.invalid_subscript, l_bracket);
            }

            try ptr.saveValue(p);
            try index.saveValue(p);
            try ptr.bin(p, .array_access_expr, index);
            return ptr;
        },
        .period => {
            p.tok_i += 1;
            const name = try p.expectIdentifier();
            const field_ty = try p.getFieldAccessField(lhs.ty, name, false);
            return Result{
                .ty = field_ty,
                .node = try p.addNode(.{
                    .tag = .member_access_expr,
                    .ty = field_ty,
                    .data = .{ .member = .{ .lhs = lhs.node, .name = name } },
                }),
            };
        },
        .arrow => {
            p.tok_i += 1;
            const name = try p.expectIdentifier();
            const field_ty = try p.getFieldAccessField(lhs.ty, name, true);
            return Result{
                .ty = field_ty,
                .node = try p.addNode(.{
                    .tag = .member_access_ptr_expr,
                    .ty = field_ty,
                    .data = .{ .member = .{ .lhs = lhs.node, .name = name } },
                }),
            };
        },
        else => return Result{},
    }
}

fn getFieldAccessField(
    p: *Parser,
    expr_ty: Type,
    field_name_tok: TokenIndex,
    is_arrow: bool,
) !Type {
    const is_ptr = expr_ty.get(.pointer) != null;
    const expr_base_ty = if (is_ptr) expr_ty.elemType() else expr_ty;
    const record_ty = expr_base_ty.canonicalize(.standard);

    switch (record_ty.specifier) {
        .@"struct", .@"union" => {},
        else => {
            try p.errStr(.expected_record_ty, field_name_tok, try p.typeStr(expr_ty));
            return error.ParsingFailed;
        },
    }
    if (record_ty.hasIncompleteSize()) {
        try p.errStr(.deref_incomplete_ty_ptr, field_name_tok - 2, try p.typeStr(expr_base_ty));
        return error.ParsingFailed;
    }
    if (is_arrow and !is_ptr) try p.errStr(.member_expr_not_ptr, field_name_tok, try p.typeStr(expr_ty));
    if (!is_arrow and is_ptr) try p.errStr(.member_expr_ptr, field_name_tok, try p.typeStr(expr_ty));

    // TODO deal with anonymous structs
    const field_name = p.tokSlice(field_name_tok);
    const field = record_ty.getField(field_name) orelse {
        const strings_top = p.strings.items.len;
        defer p.strings.items.len = strings_top;

        try p.strings.writer().print("'{s}' in '", .{field_name});
        try expr_ty.print(p.strings.writer());
        try p.strings.append('\'');

        try p.errStr(.no_such_member, field_name_tok, try p.arena.dupe(u8, p.strings.items[strings_top..]));
        return error.ParsingFailed;
    };
    return field.f.ty;
}

fn callExpr(p: *Parser, lhs: Result) Error!Result {
    const l_paren = p.tok_i;
    p.tok_i += 1;
    const ty = lhs.ty.isCallable() orelse {
        try p.errStr(.not_callable, l_paren, try p.typeStr(lhs.ty));
        return error.ParsingFailed;
    };
    const params = ty.data.func.params;
    var func = lhs;
    try func.lvalConversion(p);

    const list_buf_top = p.list_buf.items.len;
    defer p.list_buf.items.len = list_buf_top;
    try p.list_buf.append(func.node);
    var arg_count: u32 = 0;

    var first_after = l_paren;
    if (p.eatToken(.r_paren) == null) {
        while (true) {
            const param_tok = p.tok_i;
            if (arg_count == params.len) first_after = p.tok_i;
            var arg = try p.assignExpr();
            try arg.expect(p);
            try arg.lvalConversion(p);
            if (arg.ty.hasIncompleteSize() and !arg.ty.is(.void)) return error.ParsingFailed;

            if (arg_count < params.len) {
                const p_ty = params[arg_count].ty;
                if (p_ty.is(.bool)) {
                    // this is ridiculous but it's what clang does
                    if (arg.ty.isInt() or arg.ty.isFloat() or arg.ty.isPtr()) {
                        try arg.boolCast(p, p_ty);
                    } else {
                        try p.errStr(.incompatible_param, param_tok, try p.typeStr(arg.ty));
                        try p.errTok(.parameter_here, params[arg_count].name_tok);
                    }
                } else if (p_ty.isInt()) {
                    if (arg.ty.isInt() or arg.ty.isFloat()) {
                        try arg.intCast(p, p_ty);
                    } else if (arg.ty.isPtr()) {
                        try p.errStr(
                            .implicit_ptr_to_int,
                            param_tok,
                            try p.typePairStrExtra(arg.ty, " to ", p_ty),
                        );
                        try p.errTok(.parameter_here, params[arg_count].name_tok);
                        try arg.intCast(p, p_ty);
                    } else {
                        try p.errStr(.incompatible_param, param_tok, try p.typeStr(arg.ty));
                        try p.errTok(.parameter_here, params[arg_count].name_tok);
                    }
                } else if (p_ty.isFloat()) {
                    if (arg.ty.isInt() or arg.ty.isFloat()) {
                        try arg.floatCast(p, p_ty);
                    } else {
                        try p.errStr(.incompatible_param, param_tok, try p.typeStr(arg.ty));
                        try p.errTok(.parameter_here, params[arg_count].name_tok);
                    }
                } else if (p_ty.isPtr()) {
                    if (arg.isZero()) {
                        try arg.nullCast(p, p_ty);
                    } else if (arg.ty.isInt()) {
                        try p.errStr(
                            .implicit_int_to_ptr,
                            param_tok,
                            try p.typePairStrExtra(arg.ty, " to ", p_ty),
                        );
                        try p.errTok(.parameter_here, params[arg_count].name_tok);
                        try arg.intCast(p, p_ty);
                    } else if (!arg.ty.isVoidStar() and !p_ty.isVoidStar() and !p_ty.eql(arg.ty, false)) {
                        try p.errStr(.incompatible_param, param_tok, try p.typeStr(arg.ty));
                        try p.errTok(.parameter_here, params[arg_count].name_tok);
                    }
                } else if (p_ty.isRecord()) {
                    if (!p_ty.eql(arg.ty, false)) {
                        try p.errStr(.incompatible_param, param_tok, try p.typeStr(arg.ty));
                        try p.errTok(.parameter_here, params[arg_count].name_tok);
                    }
                } else {
                    // should be unreachable
                    try p.errStr(.incompatible_param, param_tok, try p.typeStr(arg.ty));
                    try p.errTok(.parameter_here, params[arg_count].name_tok);
                }
            } else {
                if (arg.ty.isInt()) try arg.intCast(p, arg.ty.integerPromotion(p.pp.comp));
                if (arg.ty.is(.float)) try arg.floatCast(p, .{ .specifier = .double });
            }
            try arg.saveValue(p);
            try p.list_buf.append(arg.node);
            arg_count += 1;

            _ = p.eatToken(.comma) orelse break;
        }
        try p.expectClosing(l_paren, .r_paren);
    }

    const extra = Diagnostics.Message.Extra{ .arguments = .{
        .expected = @intCast(u32, params.len),
        .actual = @intCast(u32, arg_count),
    } };
    if (ty.is(.func) and params.len != arg_count) {
        try p.errExtra(.expected_arguments, first_after, extra);
    }
    if (ty.is(.old_style_func) and params.len != arg_count) {
        try p.errExtra(.expected_arguments_old, first_after, extra);
    }
    if (ty.is(.var_args_func) and arg_count < params.len) {
        try p.errExtra(.expected_at_least_arguments, first_after, extra);
    }

    var call_node: Tree.Node = .{
        .tag = .call_expr_one,
        .ty = ty.data.func.return_type,
        .data = .{ .bin = .{ .lhs = func.node, .rhs = .none } },
    };
    const args = p.list_buf.items[list_buf_top..];
    switch (arg_count) {
        0 => {},
        1 => call_node.data.bin.rhs = args[1], // args[0] == func.node
        else => {
            call_node.tag = .call_expr;
            call_node.data = .{ .range = try p.addList(args) };
        },
    }
    return Result{ .node = try p.addNode(call_node), .ty = call_node.ty };
}

fn checkArrayBounds(p: *Parser, index: Result, arr_ty: Type, tok: TokenIndex) !void {
    const len = arr_ty.arrayLen() orelse return;

    switch (index.val) {
        .unsigned => |val| if (std.math.compare(val, .gte, len))
            try p.errExtra(.array_after, tok, .{ .unsigned = val }),
        .signed => |val| if (val < 0)
            try p.errExtra(.array_before, tok, .{ .signed = val })
        else if (std.math.compare(val, .gte, len))
            try p.errExtra(.array_after, tok, .{ .unsigned = @intCast(u64, val) }),
        .unavailable => return,
    }
}

/// primaryExpr
///  : IDENTIFIER
///  | INTEGER_LITERAL
///  | FLOAT_LITERAL
///  | CHAR_LITERAL
///  | STRING_LITERAL
///  | '(' expr ')'
///  | genericSelection
fn primaryExpr(p: *Parser) Error!Result {
    if (p.eatToken(.l_paren)) |l_paren| {
        var e = try p.expr();
        try e.expect(p);
        try p.expectClosing(l_paren, .r_paren);
        try e.un(p, .paren_expr);
        return e;
    }
    switch (p.tok_ids[p.tok_i]) {
        .identifier, .extended_identifier => {
            const name_tok = p.expectIdentifier() catch unreachable;
            const sym = p.findSymbol(name_tok, .reference) orelse {
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

                    try p.decl_buf.append(node);
                    try p.scopes.append(.{ .decl = .{
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
                    var res = e.value;
                    res.node = try p.addNode(.{
                        .tag = .enumeration_ref,
                        .ty = res.ty,
                        .data = .{ .decl_ref = name_tok },
                    });
                    return res;
                },
                .def, .decl, .param => |s| return Result{
                    .ty = s.ty,
                    .node = try p.addNode(.{
                        .tag = .decl_ref_expr,
                        .ty = s.ty,
                        .data = .{ .decl_ref = name_tok },
                    }),
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
        => return p.charLiteral(),
        .float_literal => {
            defer p.tok_i += 1;
            const ty = Type{ .specifier = .double };
            return Result{ .ty = ty, .node = try p.addNode(
                .{ .tag = .double_literal, .ty = ty, .data = .{ .double = try p.parseFloat(p.tok_i, f64) } },
            ) };
        },
        .float_literal_f => {
            defer p.tok_i += 1;
            const ty = Type{ .specifier = .float };
            return Result{ .ty = ty, .node = try p.addNode(
                .{ .tag = .float_literal, .ty = ty, .data = .{ .float = try p.parseFloat(p.tok_i, f32) } },
            ) };
        },
        .float_literal_l => return p.todo("long double literals"),
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
        => return p.integerLiteral(),
        .keyword_generic => return p.genericSelection(),
        else => return Result{},
    }
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
    if (width.? != 8) return p.todo("unicode string literals");
    const index = p.strings.items.len;
    while (start < p.tok_i) : (start += 1) {
        var slice = p.tokSlice(start);
        slice = slice[0 .. slice.len - 1];
        var i = mem.indexOf(u8, slice, "\"").? + 1;
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
                        'x' => p.strings.appendAssumeCapacity(try p.parseNumberEscape(start, 16, slice, &i)),
                        '0'...'7' => p.strings.appendAssumeCapacity(try p.parseNumberEscape(start, 8, slice, &i)),
                        'u' => try p.parseUnicodeEscape(start, 4, slice, &i),
                        'U' => try p.parseUnicodeEscape(start, 8, slice, &i),
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

fn parseNumberEscape(p: *Parser, tok: TokenIndex, base: u8, slice: []const u8, i: *usize) !u8 {
    if (base == 16) i.* += 1; // skip x
    var char: u8 = 0;
    var reported = false;
    while (i.* < slice.len) : (i.* += 1) {
        const val = std.fmt.charToDigit(slice[i.*], base) catch break; // validated by Tokenizer
        if (@mulWithOverflow(u8, char, base, &char) and !reported) {
            try p.errExtra(.escape_sequence_overflow, tok, .{ .unsigned = i.* });
            reported = true;
        }
        char += val;
    }
    i.* -= 1;
    return char;
}

fn parseUnicodeEscape(p: *Parser, tok: TokenIndex, count: u8, slice: []const u8, i: *usize) !void {
    const c = std.fmt.parseInt(u21, slice[i.* + 1 ..][0..count], 16) catch 0x110000; // count validated by tokenizer
    i.* += count + 1;
    if (!std.unicode.utf8ValidCodepoint(c) or (c < 0xa0 and c != '$' and c != '@' and c != '`')) {
        try p.errExtra(.invalid_universal_character, tok, .{ .unsigned = i.* - count - 2 });
        return;
    }
    var buf: [4]u8 = undefined;
    const to_write = std.unicode.utf8Encode(c, &buf) catch unreachable; // validated above
    p.strings.appendSliceAssumeCapacity(buf[0..to_write]);
}

fn charLiteral(p: *Parser) Error!Result {
    const lit_tok = p.tok_i;
    const ty: Type = switch (p.tok_ids[p.tok_i]) {
        .char_literal => .{ .specifier = .int },
        else => return p.todo("unicode char literals"),
    };
    p.tok_i += 1;

    var val: u32 = 0;
    var overflow_reported = false;
    var multichar: u8 = 0;
    var slice = p.tokSlice(lit_tok);
    slice = slice[0 .. slice.len - 1];
    var i = mem.indexOf(u8, slice, "\'").? + 1;
    while (i < slice.len) : (i += 1) {
        var c = slice[i];
        switch (c) {
            '\\' => {
                i += 1;
                switch (slice[i]) {
                    '\n' => i += 1,
                    '\r' => i += 2,
                    '\'', '\"', '\\', '?' => c = slice[i],
                    'n' => c = '\n',
                    'r' => c = '\r',
                    't' => c = '\t',
                    'a' => c = 0x07,
                    'b' => c = 0x08,
                    'e' => c = 0x1B,
                    'f' => c = 0x0C,
                    'v' => c = 0x0B,
                    'x' => c = try p.parseNumberEscape(lit_tok, 16, slice, &i),
                    '0'...'7' => c = try p.parseNumberEscape(lit_tok, 8, slice, &i),
                    'u', 'U' => return p.todo("unicode escapes in char literals"),
                    else => unreachable,
                }
            },
            else => {},
        }
        if (@mulWithOverflow(u32, val, 0xff, &val) and !overflow_reported) {
            try p.errExtra(.char_lit_too_wide, lit_tok, .{ .unsigned = i });
            overflow_reported = true;
        }
        val += c;
        switch (multichar) {
            0 => multichar = 1,
            1 => {
                multichar = 2;
                try p.errTok(.multichar_literal, lit_tok);
            },
            else => {},
        }
    }

    return Result{
        .ty = ty,
        .val = .{ .unsigned = val },
        .node = try p.addNode(.{
            .tag = .int_literal,
            .ty = ty,
            .data = .{ .int = val },
        }),
    };
}

fn parseFloat(p: *Parser, tok: TokenIndex, comptime T: type) Error!T {
    var bytes = p.tokSlice(tok);
    if (p.tok_ids[tok] != .float_literal) bytes = bytes[0 .. bytes.len - 1];
    if (bytes.len > 2 and (bytes[1] == 'x' or bytes[1] == 'X')) {
        assert(bytes[0] == '0'); // validated by Tokenizer
        return std.fmt.parseHexFloat(T, bytes) catch |e| switch (e) {
            error.InvalidCharacter => unreachable, // validated by Tokenizer
            error.Overflow => p.todo("what to do with hex floats too big"),
        };
    } else {
        return std.fmt.parseFloat(T, bytes) catch |e| switch (e) {
            error.InvalidCharacter => unreachable, // validated by Tokenizer
        };
    }
}

fn integerLiteral(p: *Parser) Error!Result {
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
    switch (id) {
        .integer_literal, .integer_literal_l, .integer_literal_ll => {
            if (val > std.math.maxInt(i64)) {
                try p.err(.implicitly_unsigned_literal);
            }
        },
        else => {},
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
}

fn castInt(p: *Parser, val: u64, specs: []const Type.Specifier) Error!Result {
    var res: Result = .{};
    for (specs) |spec| {
        const ty = Type{ .specifier = spec };
        const unsigned = ty.isUnsignedInt(p.pp.comp);
        const size = ty.sizeof(p.pp.comp).?;
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

/// Run a parser function but do not evaluate the result
fn parseNoEval(p: *Parser, func: fn (*Parser) Error!Result) Error!Result {
    const no_eval = p.no_eval;
    defer p.no_eval = no_eval;
    p.no_eval = true;
    const parsed = try func(p);
    try parsed.expect(p);
    return parsed;
}

/// genericSelection : keyword_generic '(' assignExpr ',' genericAssoc (',' genericAssoc)* ')'
/// genericAssoc
///  : typeName ':' assignExpr
///  | keyword_default ':' assignExpr
fn genericSelection(p: *Parser) Error!Result {
    p.tok_i += 1;
    const l_paren = try p.expectToken(.l_paren);
    const controlling = try p.parseNoEval(assignExpr);
    _ = try p.expectToken(.comma);

    const list_buf_top = p.list_buf.items.len;
    defer p.list_buf.items.len = list_buf_top;
    try p.list_buf.append(controlling.node);

    var default_tok: ?TokenIndex = null;
    // TODO actually choose
    var chosen: Result = .{};
    while (true) {
        const start = p.tok_i;
        if (try p.typeName()) |ty| {
            if (ty.anyQual()) {
                try p.errTok(.generic_qual_type, start);
            }
            _ = try p.expectToken(.colon);
            chosen = try p.assignExpr();
            try chosen.expect(p);
            try chosen.saveValue(p);
            try p.list_buf.append(try p.addNode(.{
                .tag = .generic_association_expr,
                .ty = ty,
                .data = .{ .un = chosen.node },
            }));
        } else if (p.eatToken(.keyword_default)) |tok| {
            if (default_tok) |prev| {
                try p.errTok(.generic_duplicate_default, tok);
                try p.errTok(.previous_case, prev);
            }
            default_tok = tok;
            _ = try p.expectToken(.colon);
            chosen = try p.assignExpr();
            try chosen.expect(p);
            try chosen.saveValue(p);
            try p.list_buf.append(try p.addNode(.{
                .tag = .generic_default_expr,
                .data = .{ .un = chosen.node },
            }));
        } else {
            if (p.list_buf.items.len == list_buf_top + 1) {
                try p.err(.expected_type);
                return error.ParsingFailed;
            }
            break;
        }
        if (p.eatToken(.comma) == null) break;
    }
    try p.expectClosing(l_paren, .r_paren);

    var generic_node: Tree.Node = .{
        .tag = .generic_expr_one,
        .ty = chosen.ty,
        .data = .{ .bin = .{ .lhs = controlling.node, .rhs = chosen.node } },
    };
    const associations = p.list_buf.items[list_buf_top..];
    if (associations.len > 2) { // associations[0] == controlling.node
        generic_node.tag = .generic_expr;
        generic_node.data = .{ .range = try p.addList(associations) };
    }
    chosen.node = try p.addNode(generic_node);
    return chosen;
}
