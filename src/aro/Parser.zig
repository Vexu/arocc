const std = @import("std");
const mem = std.mem;
const Allocator = mem.Allocator;
const assert = std.debug.assert;
const big = std.math.big;

const Attribute = @import("Attribute.zig");
const Builtins = @import("Builtins.zig");
const Builtin = Builtins.Builtin;
const evalBuiltin = @import("Builtins/eval.zig").eval;
const char_info = @import("char_info.zig");
const Compilation = @import("Compilation.zig");
const Diagnostics = @import("Diagnostics.zig");
const InitList = @import("InitList.zig");
const Preprocessor = @import("Preprocessor.zig");
const record_layout = @import("record_layout.zig");
const Source = @import("Source.zig");
const StrInt = @import("StringInterner.zig");
const StringId = StrInt.StringId;
const SymbolStack = @import("SymbolStack.zig");
const Symbol = SymbolStack.Symbol;
const target_util = @import("target.zig");
const text_literal = @import("text_literal.zig");
const Tokenizer = @import("Tokenizer.zig");
const Tree = @import("Tree.zig");
const Token = Tree.Token;
const NumberPrefix = Token.NumberPrefix;
const NumberSuffix = Token.NumberSuffix;
const TokenIndex = Tree.TokenIndex;
const Node = Tree.Node;
const Type = @import("Type.zig");
const Value = @import("Value.zig");

const NodeList = std.ArrayList(Node.Index);
const Switch = struct {
    default: ?TokenIndex = null,
    ranges: std.ArrayList(Range),
    ty: Type,
    comp: *Compilation,

    const Range = struct {
        first: Value,
        last: Value,
        tok: TokenIndex,
    };

    fn add(self: *Switch, first: Value, last: Value, tok: TokenIndex) !?Range {
        for (self.ranges.items) |range| {
            if (last.compare(.gte, range.first, self.comp) and first.compare(.lte, range.last, self.comp)) {
                return range; // They overlap.
            }
        }
        try self.ranges.append(.{
            .first = first,
            .last = last,
            .tok = tok,
        });
        return null;
    }
};

const Label = union(enum) {
    unresolved_goto: TokenIndex,
    label: TokenIndex,
};

const InitContext = enum {
    /// inits do not need to be compile-time constants
    runtime,
    /// constexpr variable, could be any scope but inits must be compile-time constants
    constexpr,
    /// static and global variables, inits must be compile-time constants
    static,
};

pub const Error = Compilation.Error || error{ParsingFailed};

/// An attribute that has been parsed but not yet validated in its context
const TentativeAttribute = struct {
    attr: Attribute,
    tok: TokenIndex,
};

/// How the parser handles const int decl references when it is expecting an integer
/// constant expression.
const ConstDeclFoldingMode = enum {
    /// fold const decls as if they were literals
    fold_const_decls,
    /// fold const decls as if they were literals and issue GNU extension diagnostic
    gnu_folding_extension,
    /// fold const decls as if they were literals and issue VLA diagnostic
    gnu_vla_folding_extension,
    /// folding const decls is prohibited; return an unavailable value
    no_const_decl_folding,
};

const Parser = @This();

// values from preprocessor
pp: *Preprocessor,
comp: *Compilation,
gpa: mem.Allocator,
tok_ids: []const Token.Id,
tok_i: TokenIndex = 0,

tree: Tree,
// references tree.arena
arena: Allocator,

// buffers used during compilation
syms: SymbolStack = .{},
strings: std.ArrayListAligned(u8, 4),
labels: std.ArrayList(Label),
list_buf: NodeList,
decl_buf: NodeList,
param_buf: std.ArrayList(Type.Func.Param),
enum_buf: std.ArrayList(Type.Enum.Field),
record_buf: std.ArrayList(Type.Record.Field),
attr_buf: std.MultiArrayList(TentativeAttribute) = .{},
attr_application_buf: std.ArrayListUnmanaged(Attribute) = .{},
field_attr_buf: std.ArrayList([]const Attribute),
/// type name -> variable name location for tentative definitions (top-level defs with thus-far-incomplete types)
/// e.g. `struct Foo bar;` where `struct Foo` is not defined yet.
/// The key is the StringId of `Foo` and the value is the TokenIndex of `bar`
/// Items are removed if the type is subsequently completed with a definition.
/// We only store the first tentative definition that uses a given type because this map is only used
/// for issuing an error message, and correcting the first error for a type will fix all of them for that type.
tentative_defs: std.AutoHashMapUnmanaged(StringId, TokenIndex) = .{},

// configuration and miscellaneous info
no_eval: bool = false,
in_macro: bool = false,
extension_suppressed: bool = false,
contains_address_of_label: bool = false,
label_count: u32 = 0,
const_decl_folding: ConstDeclFoldingMode = .fold_const_decls,
/// location of first computed goto in function currently being parsed
/// if a computed goto is used, the function must contain an
/// address-of-label expression (tracked with contains_address_of_label)
computed_goto_tok: ?TokenIndex = null,

/// __auto_type may only be used with a single declarator. Keep track of the name
/// so that it is not used in its own initializer.
auto_type_decl_name: StringId = .empty,

init_context: InitContext = .runtime,

/// Various variables that are different for each function.
func: struct {
    /// null if not in function, will always be plain func, var_args_func or old_style_func
    ty: ?Type = null,
    name: TokenIndex = 0,
    ident: ?Result = null,
    pretty_ident: ?Result = null,
} = .{},
/// Various variables that are different for each record.
record: struct {
    // invalid means we're not parsing a record
    kind: Token.Id = .invalid,
    flexible_field: ?TokenIndex = null,
    start: usize = 0,
    field_attr_start: usize = 0,

    fn addField(r: @This(), p: *Parser, name: StringId, tok: TokenIndex) Error!void {
        var i = p.record_members.items.len;
        while (i > r.start) {
            i -= 1;
            if (p.record_members.items[i].name == name) {
                try p.errStr(.duplicate_member, tok, p.tokSlice(tok));
                try p.errTok(.previous_definition, p.record_members.items[i].tok);
                break;
            }
        }
        try p.record_members.append(p.gpa, .{ .name = name, .tok = tok });
    }

    fn addFieldsFromAnonymous(r: @This(), p: *Parser, ty: Type) Error!void {
        for (ty.getRecord().?.fields) |f| {
            if (f.isAnonymousRecord()) {
                try r.addFieldsFromAnonymous(p, f.ty.canonicalize(.standard));
            } else if (f.name_tok != 0) {
                try r.addField(p, f.name, f.name_tok);
            }
        }
    }
} = .{},
record_members: std.ArrayListUnmanaged(struct { tok: TokenIndex, name: StringId }) = .{},
@"switch": ?*Switch = null,
in_loop: bool = false,
pragma_pack: ?u8 = null,
string_ids: struct {
    declspec_id: StringId,
    main_id: StringId,
    file: StringId,
    jmp_buf: StringId,
    sigjmp_buf: StringId,
    ucontext_t: StringId,
},

/// Checks codepoint for various pedantic warnings
/// Returns true if diagnostic issued
fn checkIdentifierCodepointWarnings(comp: *Compilation, codepoint: u21, loc: Source.Location) Compilation.Error!bool {
    assert(codepoint >= 0x80);

    const err_start = comp.diagnostics.list.items.len;

    if (!char_info.isC99IdChar(codepoint)) {
        try comp.addDiagnostic(.{
            .tag = .c99_compat,
            .loc = loc,
        }, &.{});
    }
    if (char_info.isInvisible(codepoint)) {
        try comp.addDiagnostic(.{
            .tag = .unicode_zero_width,
            .loc = loc,
            .extra = .{ .actual_codepoint = codepoint },
        }, &.{});
    }
    if (char_info.homoglyph(codepoint)) |resembles| {
        try comp.addDiagnostic(.{
            .tag = .unicode_homoglyph,
            .loc = loc,
            .extra = .{ .codepoints = .{ .actual = codepoint, .resembles = resembles } },
        }, &.{});
    }
    return comp.diagnostics.list.items.len != err_start;
}

/// Issues diagnostics for the current extended identifier token
/// Return value indicates whether the token should be considered an identifier
/// true means consider the token to actually be an identifier
/// false means it is not
fn validateExtendedIdentifier(p: *Parser) !bool {
    assert(p.tok_ids[p.tok_i] == .extended_identifier);

    const slice = p.tokSlice(p.tok_i);
    const view = std.unicode.Utf8View.init(slice) catch {
        try p.errTok(.invalid_utf8, p.tok_i);
        return error.FatalError;
    };
    var it = view.iterator();

    var valid_identifier = true;
    var warned = false;
    var len: usize = 0;
    var invalid_char: u21 = undefined;
    var loc = p.pp.tokens.items(.loc)[p.tok_i];

    var normalized = true;
    var last_canonical_class: char_info.CanonicalCombiningClass = .not_reordered;
    const standard = p.comp.langopts.standard;
    while (it.nextCodepoint()) |codepoint| {
        defer {
            len += 1;
            loc.byte_offset += std.unicode.utf8CodepointSequenceLength(codepoint) catch unreachable;
        }
        if (codepoint == '$') {
            warned = true;
            if (p.comp.langopts.dollars_in_identifiers) try p.comp.addDiagnostic(.{
                .tag = .dollar_in_identifier_extension,
                .loc = loc,
            }, &.{});
        }

        if (codepoint <= 0x7F) continue;
        if (!valid_identifier) continue;

        const allowed = standard.codepointAllowedInIdentifier(codepoint, len == 0);
        if (!allowed) {
            invalid_char = codepoint;
            valid_identifier = false;
            continue;
        }

        if (!warned) {
            warned = try checkIdentifierCodepointWarnings(p.comp, codepoint, loc);
        }

        // Check NFC normalization.
        if (!normalized) continue;
        const canonical_class = char_info.getCanonicalClass(codepoint);
        if (@intFromEnum(last_canonical_class) > @intFromEnum(canonical_class) and
            canonical_class != .not_reordered)
        {
            normalized = false;
            try p.errStr(.identifier_not_normalized, p.tok_i, slice);
            continue;
        }
        if (char_info.isNormalized(codepoint) != .yes) {
            normalized = false;
            try p.errExtra(.identifier_not_normalized, p.tok_i, .{ .normalized = slice });
        }
        last_canonical_class = canonical_class;
    }

    if (!valid_identifier) {
        if (len == 1) {
            try p.errExtra(.unexpected_character, p.tok_i, .{ .actual_codepoint = invalid_char });
            return false;
        } else {
            try p.errExtra(.invalid_identifier_start_char, p.tok_i, .{ .actual_codepoint = invalid_char });
        }
    }

    return true;
}

fn eatIdentifier(p: *Parser) !?TokenIndex {
    switch (p.tok_ids[p.tok_i]) {
        .identifier => {},
        .extended_identifier => {
            if (!try p.validateExtendedIdentifier()) {
                p.tok_i += 1;
                return null;
            }
        },
        else => return null,
    }
    p.tok_i += 1;

    // Handle illegal '$' characters in identifiers
    if (!p.comp.langopts.dollars_in_identifiers) {
        if (p.tok_ids[p.tok_i] == .invalid and p.tokSlice(p.tok_i)[0] == '$') {
            try p.err(.dollars_in_identifiers);
            p.tok_i += 1;
            return error.ParsingFailed;
        }
    }

    return p.tok_i - 1;
}

fn expectIdentifier(p: *Parser) Error!TokenIndex {
    const actual = p.tok_ids[p.tok_i];
    if (actual != .identifier and actual != .extended_identifier) {
        return p.errExpectedToken(.identifier, actual);
    }

    return (try p.eatIdentifier()) orelse error.ParsingFailed;
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
    if (actual != expected) return p.errExpectedToken(expected, actual);
    defer p.tok_i += 1;
    return p.tok_i;
}

pub fn tokSlice(p: *Parser, tok: TokenIndex) []const u8 {
    if (p.tok_ids[tok].lexeme()) |some| return some;
    const loc = p.pp.tokens.items(.loc)[tok];
    var tmp_tokenizer = Tokenizer{
        .buf = p.comp.getSource(loc.id).buf,
        .langopts = p.comp.langopts,
        .index = loc.byte_offset,
        .source = .generated,
    };
    const res = tmp_tokenizer.next();
    return tmp_tokenizer.buf[res.start..res.end];
}

fn expectClosing(p: *Parser, opening: TokenIndex, id: Token.Id) Error!void {
    _ = p.expectToken(id) catch |e| {
        if (e == error.ParsingFailed) {
            try p.errTok(switch (id) {
                .r_paren => .to_match_paren,
                .r_brace => .to_match_brace,
                .r_bracket => .to_match_brace,
                else => unreachable,
            }, opening);
        }
        return e;
    };
}

fn errOverflow(p: *Parser, op_tok: TokenIndex, res: Result) !void {
    try p.errStr(.overflow, op_tok, try res.str(p));
}

fn errArrayOverflow(p: *Parser, op_tok: TokenIndex, res: Result) !void {
    const strings_top = p.strings.items.len;
    defer p.strings.items.len = strings_top;

    const w = p.strings.writer();
    const format =
        \\The pointer incremented by {s} refers past the last possible element in {d}-bit address space containing {d}-bit ({d}-byte) elements (max possible {d} elements)
    ;
    const increment = try res.str(p);
    const ptr_bits = p.comp.types.intptr.bitSizeof(p.comp).?;
    const element_size = res.ty.elemType().sizeof(p.comp) orelse 1;
    const max_elems = p.comp.maxArrayBytes() / element_size;

    try w.print(format, .{ increment, ptr_bits, element_size * 8, element_size, max_elems });
    const duped = try p.comp.diagnostics.arena.allocator().dupe(u8, p.strings.items[strings_top..]);
    return p.errStr(.array_overflow, op_tok, duped);
}

fn errExpectedToken(p: *Parser, expected: Token.Id, actual: Token.Id) Error {
    switch (actual) {
        .invalid => try p.errExtra(.expected_invalid, p.tok_i, .{ .tok_id_expected = expected }),
        .eof => try p.errExtra(.expected_eof, p.tok_i, .{ .tok_id_expected = expected }),
        else => try p.errExtra(.expected_token, p.tok_i, .{ .tok_id = .{
            .expected = expected,
            .actual = actual,
        } }),
    }
    return error.ParsingFailed;
}

pub fn errStr(p: *Parser, tag: Diagnostics.Tag, tok_i: TokenIndex, str: []const u8) Compilation.Error!void {
    @branchHint(.cold);
    return p.errExtra(tag, tok_i, .{ .str = str });
}

pub fn errExtra(p: *Parser, tag: Diagnostics.Tag, tok_i: TokenIndex, extra: Diagnostics.Message.Extra) Compilation.Error!void {
    @branchHint(.cold);
    const tok = p.pp.tokens.get(tok_i);
    var loc = tok.loc;
    if (tok_i != 0 and tok.id == .eof) {
        // if the token is EOF, point at the end of the previous token instead
        const prev = p.pp.tokens.get(tok_i - 1);
        loc = prev.loc;
        loc.byte_offset += @intCast(p.tokSlice(tok_i - 1).len);
    }
    try p.comp.addDiagnostic(.{
        .tag = tag,
        .loc = loc,
        .extra = extra,
    }, p.pp.expansionSlice(tok_i));
}

pub fn errTok(p: *Parser, tag: Diagnostics.Tag, tok_i: TokenIndex) Compilation.Error!void {
    @branchHint(.cold);
    return p.errExtra(tag, tok_i, .{ .none = {} });
}

pub fn err(p: *Parser, tag: Diagnostics.Tag) Compilation.Error!void {
    @branchHint(.cold);
    return p.errExtra(tag, p.tok_i, .{ .none = {} });
}

pub fn todo(p: *Parser, msg: []const u8) Error {
    try p.errStr(.todo, p.tok_i, msg);
    return error.ParsingFailed;
}

pub fn removeNull(p: *Parser, str: Value) !Value {
    const strings_top = p.strings.items.len;
    defer p.strings.items.len = strings_top;
    {
        const bytes = p.comp.interner.get(str.ref()).bytes;
        try p.strings.appendSlice(bytes[0 .. bytes.len - 1]);
    }
    return Value.intern(p.comp, .{ .bytes = p.strings.items[strings_top..] });
}

pub fn typeStr(p: *Parser, ty: Type) ![]const u8 {
    if (@import("builtin").mode != .Debug) {
        if (ty.is(.invalid)) {
            return "Tried to render invalid type - this is an aro bug.";
        }
    }
    if (Type.Builder.fromType(ty).str(p.comp.langopts)) |str| return str;
    const strings_top = p.strings.items.len;
    defer p.strings.items.len = strings_top;

    const mapper = p.comp.string_interner.getSlowTypeMapper();
    try ty.print(mapper, p.comp.langopts, p.strings.writer());
    return try p.comp.diagnostics.arena.allocator().dupe(u8, p.strings.items[strings_top..]);
}

pub fn typePairStr(p: *Parser, a: Type, b: Type) ![]const u8 {
    return p.typePairStrExtra(a, " and ", b);
}

pub fn typePairStrExtra(p: *Parser, a: Type, msg: []const u8, b: Type) ![]const u8 {
    if (@import("builtin").mode != .Debug) {
        if (a.is(.invalid) or b.is(.invalid)) {
            return "Tried to render invalid type - this is an aro bug.";
        }
    }
    const strings_top = p.strings.items.len;
    defer p.strings.items.len = strings_top;

    try p.strings.append('\'');
    const mapper = p.comp.string_interner.getSlowTypeMapper();
    try a.print(mapper, p.comp.langopts, p.strings.writer());
    try p.strings.append('\'');
    try p.strings.appendSlice(msg);
    try p.strings.append('\'');
    try b.print(mapper, p.comp.langopts, p.strings.writer());
    try p.strings.append('\'');
    return try p.comp.diagnostics.arena.allocator().dupe(u8, p.strings.items[strings_top..]);
}

pub fn valueChangedStr(p: *Parser, res: *Result, old_value: Value, int_ty: Type) ![]const u8 {
    const strings_top = p.strings.items.len;
    defer p.strings.items.len = strings_top;

    var w = p.strings.writer();
    const type_pair_str = try p.typePairStrExtra(res.ty, " to ", int_ty);
    try w.writeAll(type_pair_str);

    try w.writeAll(" changes ");
    if (res.val.isZero(p.comp)) try w.writeAll("non-zero ");
    try w.writeAll("value from ");
    if (try old_value.print(res.ty, p.comp, w)) |nested| switch (nested) {
        .pointer => unreachable,
    };
    try w.writeAll(" to ");
    if (try res.val.print(int_ty, p.comp, w)) |nested| switch (nested) {
        .pointer => unreachable,
    };

    return try p.comp.diagnostics.arena.allocator().dupe(u8, p.strings.items[strings_top..]);
}

fn checkDeprecatedUnavailable(p: *Parser, ty: Type, usage_tok: TokenIndex, decl_tok: TokenIndex) !void {
    if (ty.getAttribute(.@"error")) |@"error"| {
        const strings_top = p.strings.items.len;
        defer p.strings.items.len = strings_top;

        const w = p.strings.writer();
        const msg_str = p.comp.interner.get(@"error".msg.ref()).bytes;
        try w.print("call to '{s}' declared with attribute error: {}", .{
            p.tokSlice(@"error".__name_tok), std.zig.fmtEscapes(msg_str),
        });
        const str = try p.comp.diagnostics.arena.allocator().dupe(u8, p.strings.items[strings_top..]);
        try p.errStr(.error_attribute, usage_tok, str);
    }
    if (ty.getAttribute(.warning)) |warning| {
        const strings_top = p.strings.items.len;
        defer p.strings.items.len = strings_top;

        const w = p.strings.writer();
        const msg_str = p.comp.interner.get(warning.msg.ref()).bytes;
        try w.print("call to '{s}' declared with attribute warning: {}", .{
            p.tokSlice(warning.__name_tok), std.zig.fmtEscapes(msg_str),
        });
        const str = try p.comp.diagnostics.arena.allocator().dupe(u8, p.strings.items[strings_top..]);
        try p.errStr(.warning_attribute, usage_tok, str);
    }
    if (ty.getAttribute(.unavailable)) |unavailable| {
        try p.errDeprecated(.unavailable, usage_tok, unavailable.msg);
        try p.errStr(.unavailable_note, unavailable.__name_tok, p.tokSlice(decl_tok));
        return error.ParsingFailed;
    } else if (ty.getAttribute(.deprecated)) |deprecated| {
        try p.errDeprecated(.deprecated_declarations, usage_tok, deprecated.msg);
        try p.errStr(.deprecated_note, deprecated.__name_tok, p.tokSlice(decl_tok));
    }
}

fn errDeprecated(p: *Parser, tag: Diagnostics.Tag, tok_i: TokenIndex, msg: ?Value) Compilation.Error!void {
    const strings_top = p.strings.items.len;
    defer p.strings.items.len = strings_top;

    const w = p.strings.writer();
    try w.print("'{s}' is ", .{p.tokSlice(tok_i)});
    const reason: []const u8 = switch (tag) {
        .unavailable => "unavailable",
        .deprecated_declarations => "deprecated",
        else => unreachable,
    };
    try w.writeAll(reason);
    if (msg) |m| {
        const str = p.comp.interner.get(m.ref()).bytes;
        try w.print(": {}", .{std.zig.fmtEscapes(str)});
    }
    const str = try p.comp.diagnostics.arena.allocator().dupe(u8, p.strings.items[strings_top..]);
    return p.errStr(tag, tok_i, str);
}

fn addNode(p: *Parser, node: Tree.Node) Allocator.Error!Node.Index {
    if (p.in_macro) return undefined;
    return p.tree.addNode(node);
}

fn addList(p: *Parser, nodes: []const Node.Index) Allocator.Error!Tree.Node.Range {
    if (p.in_macro) return Tree.Node.Range{ .start = 0, .end = 0 };
    const start: u32 = @intCast(p.data.items.len);
    try p.data.appendSlice(nodes);
    const end: u32 = @intCast(p.data.items.len);
    return Tree.Node.Range{ .start = start, .end = end };
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

fn nodeIs(p: *Parser, node: Node.Index, comptime tag: std.meta.Tag(Tree.Node)) bool {
    return p.getNode(node, tag) != null;
}

pub fn getDecayedStringLiteral(p: *Parser, node: Node.Index) ?Value {
    const cast = p.getNode(node, .implicit_cast) orelse return null;
    if (cast.kind != .array_to_pointer) return null;

    var cur = cast.operand;
    while (true) {
        switch (cur.get(&p.tree)) {
            .paren_expr => |un| cur = un.operand,
            .string_literal_expr => return p.tree.value_map.get(cur),
            else => return null,
        }
    }
}

fn getNode(p: *Parser, node: Node.Index, comptime tag: std.meta.Tag(Tree.Node)) ?@FieldType(Node, @tagName(tag)) {
    var cur = node;
    while (true) {
        switch (cur.get(&p.tree)) {
            .paren_expr => |un| cur = un.operand,
            tag => |data| return data,
            else => return null,
        }
    }
}

fn pragma(p: *Parser) Compilation.Error!bool {
    var found_pragma = false;
    while (p.eatToken(.keyword_pragma)) |_| {
        found_pragma = true;

        const name_tok = p.tok_i;
        const name = p.tokSlice(name_tok);

        const end_idx = mem.indexOfScalarPos(Token.Id, p.tok_ids, p.tok_i, .nl).?;
        const pragma_len = @as(TokenIndex, @intCast(end_idx)) - p.tok_i;
        defer p.tok_i += pragma_len + 1; // skip past .nl as well
        if (p.comp.getPragma(name)) |prag| {
            try prag.parserCB(p, p.tok_i);
        }
    }
    return found_pragma;
}

/// Issue errors for top-level definitions whose type was never completed.
fn diagnoseIncompleteDefinitions(p: *Parser) !void {
    @branchHint(.cold);

    for (p.decl_buf.items) |decl_index| {
        const node = decl_index.get(&p.tree);
        const forward = switch (node) {
            .struct_forward_decl, .union_forward_decl, .enum_forward_decl => |forward| forward,
            else => continue,
        };

        const decl_type_name = if (forward.container_type.getRecord()) |rec|
            rec.name
        else if (forward.container_type.get(.@"enum")) |en|
            en.data.@"enum".name
        else
            unreachable;

        const tentative_def_tok = p.tentative_defs.get(decl_type_name) orelse continue;
        const type_str = try p.typeStr(forward.container_type);
        try p.errStr(.tentative_definition_incomplete, tentative_def_tok, type_str);
        try p.errStr(.forward_declaration_here, forward.name_or_kind_tok, type_str);
    }
}

/// root : (decl | assembly ';' | staticAssert)*
pub fn parse(pp: *Preprocessor) Compilation.Error!Tree {
    assert(pp.linemarkers == .none);
    pp.comp.pragmaEvent(.before_parse);

    var arena = std.heap.ArenaAllocator.init(pp.comp.gpa);
    errdefer arena.deinit();
    var p: Parser = .{
        .pp = pp,
        .comp = pp.comp,
        .gpa = pp.comp.gpa,
        .tree = .{
            .comp = pp.comp,
            .generated = pp.comp.generated_buf.items,
            .tokens = pp.tokens.slice(),
            .arena = .init(pp.comp.gpa),
        },
        .arena = undefined, // set later
        .tok_ids = pp.tokens.items(.id),
        .strings = std.ArrayListAligned(u8, 4).init(pp.comp.gpa),
        .labels = std.ArrayList(Label).init(pp.comp.gpa),
        .list_buf = NodeList.init(pp.comp.gpa),
        .decl_buf = NodeList.init(pp.comp.gpa),
        .param_buf = std.ArrayList(Type.Func.Param).init(pp.comp.gpa),
        .enum_buf = std.ArrayList(Type.Enum.Field).init(pp.comp.gpa),
        .record_buf = std.ArrayList(Type.Record.Field).init(pp.comp.gpa),
        .field_attr_buf = std.ArrayList([]const Attribute).init(pp.comp.gpa),
        .string_ids = .{
            .declspec_id = try StrInt.intern(pp.comp, "__declspec"),
            .main_id = try StrInt.intern(pp.comp, "main"),
            .file = try StrInt.intern(pp.comp, "FILE"),
            .jmp_buf = try StrInt.intern(pp.comp, "jmp_buf"),
            .sigjmp_buf = try StrInt.intern(pp.comp, "sigjmp_buf"),
            .ucontext_t = try StrInt.intern(pp.comp, "ucontext_t"),
        },
    };
    p.arena = p.tree.arena.allocator();
    errdefer p.tree.deinit();
    defer {
        p.labels.deinit();
        p.strings.deinit();
        p.syms.deinit(pp.comp.gpa);
        p.list_buf.deinit();
        p.decl_buf.deinit();
        p.param_buf.deinit();
        p.enum_buf.deinit();
        p.record_buf.deinit();
        p.record_members.deinit(pp.comp.gpa);
        p.attr_buf.deinit(pp.comp.gpa);
        p.attr_application_buf.deinit(pp.comp.gpa);
        p.tentative_defs.deinit(pp.comp.gpa);
        assert(p.field_attr_buf.items.len == 0);
        p.field_attr_buf.deinit();
    }

    try p.syms.pushScope(&p);
    defer p.syms.popScope();

    {
        if (p.comp.langopts.hasChar8_T()) {
            try p.syms.defineTypedef(&p, try StrInt.intern(p.comp, "char8_t"), .{ .specifier = .uchar }, 0, null);
        }
        try p.syms.defineTypedef(&p, try StrInt.intern(p.comp, "__int128_t"), .{ .specifier = .int128 }, 0, null);
        try p.syms.defineTypedef(&p, try StrInt.intern(p.comp, "__uint128_t"), .{ .specifier = .uint128 }, 0, null);

        const elem_ty = try p.arena.create(Type);
        elem_ty.* = .{ .specifier = .char };
        try p.syms.defineTypedef(&p, try StrInt.intern(p.comp, "__builtin_ms_va_list"), .{
            .specifier = .pointer,
            .data = .{ .sub_type = elem_ty },
        }, 0, null);

        const ty = &pp.comp.types.va_list;
        try p.syms.defineTypedef(&p, try StrInt.intern(p.comp, "__builtin_va_list"), ty.*, 0, null);

        if (ty.isArray()) ty.decayArray();

        try p.syms.defineTypedef(&p, try StrInt.intern(p.comp, "__NSConstantString"), pp.comp.types.ns_constant_string.ty, 0, null);

        if (p.comp.float80Type()) |float80_ty| {
            try p.syms.defineTypedef(&p, try StrInt.intern(p.comp, "__float80"), float80_ty, 0, null);
        }
    }

    while (p.eatToken(.eof) == null) {
        if (try p.pragma()) continue;
        if (try p.parseOrNextDecl(staticAssert)) continue;
        if (try p.parseOrNextDecl(decl)) continue;
        if (p.eatToken(.keyword_extension)) |_| {
            const saved_extension = p.extension_suppressed;
            defer p.extension_suppressed = saved_extension;
            p.extension_suppressed = true;

            if (try p.parseOrNextDecl(decl)) continue;
            switch (p.tok_ids[p.tok_i]) {
                .semicolon => p.tok_i += 1,
                .keyword_static_assert,
                .keyword_c23_static_assert,
                .keyword_pragma,
                .keyword_extension,
                .keyword_asm,
                .keyword_asm1,
                .keyword_asm2,
                => {},
                else => try p.err(.expected_external_decl),
            }
            continue;
        }
        if (p.assembly(.global) catch |er| switch (er) {
            error.ParsingFailed => {
                p.nextExternDecl();
                continue;
            },
            else => |e| return e,
        }) |node| {
            try p.decl_buf.append(node);
            continue;
        }
        if (p.eatToken(.semicolon)) |tok| {
            try p.errTok(.extra_semi, tok);
            continue;
        }
        try p.err(.expected_external_decl);
        p.tok_i += 1;
    }
    if (p.tentative_defs.count() > 0) {
        try p.diagnoseIncompleteDefinitions();
    }

    p.tree.root_decls = p.decl_buf.moveToUnmanaged();
    if (p.tree.root_decls.items.len == 0) {
        try p.errTok(.empty_translation_unit, p.tok_i - 1);
    }
    pp.comp.pragmaEvent(.after_parse);

    return p.tree;
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

fn parseOrNextDecl(p: *Parser, comptime func: fn (*Parser) Error!bool) Compilation.Error!bool {
    return func(p) catch |er| switch (er) {
        error.ParsingFailed => {
            p.nextExternDecl();
            return true;
        },
        else => |e| return e,
    };
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
            .keyword_c23_thread_local,
            .keyword_inline,
            .keyword_inline1,
            .keyword_inline2,
            .keyword_noreturn,
            .keyword_void,
            .keyword_bool,
            .keyword_c23_bool,
            .keyword_char,
            .keyword_short,
            .keyword_int,
            .keyword_long,
            .keyword_signed,
            .keyword_signed1,
            .keyword_signed2,
            .keyword_unsigned,
            .keyword_float,
            .keyword_double,
            .keyword_complex,
            .keyword_atomic,
            .keyword_enum,
            .keyword_struct,
            .keyword_union,
            .keyword_alignas,
            .keyword_c23_alignas,
            .identifier,
            .extended_identifier,
            .keyword_typeof,
            .keyword_typeof1,
            .keyword_typeof2,
            .keyword_typeof_unqual,
            .keyword_extension,
            .keyword_bit_int,
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

/// Called after a typedef is defined
fn typedefDefined(p: *Parser, name: StringId, ty: Type) void {
    if (name == p.string_ids.file) {
        p.comp.types.file = ty;
    } else if (name == p.string_ids.jmp_buf) {
        p.comp.types.jmp_buf = ty;
    } else if (name == p.string_ids.sigjmp_buf) {
        p.comp.types.sigjmp_buf = ty;
    } else if (name == p.string_ids.ucontext_t) {
        p.comp.types.ucontext_t = ty;
    }
}

// ====== declarations ======

/// decl
///  : declSpec (initDeclarator ( ',' initDeclarator)*)? ';'
///  | declSpec declarator decl* compoundStmt
fn decl(p: *Parser) Error!bool {
    _ = try p.pragma();
    const first_tok = p.tok_i;
    const attr_buf_top = p.attr_buf.len;
    defer p.attr_buf.len = attr_buf_top;

    try p.attributeSpecifier();

    var decl_spec = if (try p.declSpec()) |some| some else blk: {
        if (p.func.ty != null) {
            p.tok_i = first_tok;
            return false;
        }
        switch (p.tok_ids[first_tok]) {
            .asterisk, .l_paren, .identifier, .extended_identifier => {},
            else => if (p.tok_i != first_tok) {
                try p.err(.expected_ident_or_l_paren);
                return error.ParsingFailed;
            } else return false,
        }
        var spec: Type.Builder = .{};
        break :blk DeclSpec{ .ty = try spec.finish(p) };
    };
    if (decl_spec.noreturn) |tok| {
        const attr = Attribute{ .tag = .noreturn, .args = .{ .noreturn = .{} }, .syntax = .keyword };
        try p.attr_buf.append(p.gpa, .{ .attr = attr, .tok = tok });
    }
    var init_d = (try p.initDeclarator(&decl_spec, attr_buf_top)) orelse {
        _ = try p.expectToken(.semicolon);
        if (decl_spec.ty.is(.@"enum") or
            (decl_spec.ty.isRecord() and !decl_spec.ty.isAnonymousRecord(p.comp) and
            !decl_spec.ty.isTypeof())) // we follow GCC and clang's behavior here
        {
            const specifier = decl_spec.ty.canonicalize(.standard).specifier;
            const attrs = p.attr_buf.items(.attr)[attr_buf_top..];
            const toks = p.attr_buf.items(.tok)[attr_buf_top..];
            for (attrs, toks) |attr, tok| {
                try p.errExtra(.ignored_record_attr, tok, .{
                    .ignored_record_attr = .{ .tag = attr.tag, .specifier = switch (specifier) {
                        .@"enum" => .@"enum",
                        .@"struct" => .@"struct",
                        .@"union" => .@"union",
                        else => unreachable,
                    } },
                });
            }
            return true;
        }

        try p.errTok(.missing_declaration, first_tok);
        return true;
    };

    // Check for function definition.
    if (init_d.d.func_declarator != null and init_d.initializer == null and init_d.d.ty.isFunc()) fn_def: {
        if (decl_spec.auto_type) |tok_i| {
            try p.errStr(.auto_type_not_allowed, tok_i, "function return type");
            return error.ParsingFailed;
        }

        switch (p.tok_ids[p.tok_i]) {
            .comma, .semicolon => break :fn_def,
            .l_brace => {},
            else => if (init_d.d.old_style_func == null) {
                try p.err(.expected_fn_body);
                return true;
            },
        }
        if (p.func.ty != null) try p.err(.func_not_in_root);

        const reserved_index = try p.tree.nodes.addOne(p.gpa); // reserve space
        const node: Node.Index = @enumFromInt(reserved_index);

        const interned_declarator_name = try StrInt.intern(p.comp, p.tokSlice(init_d.d.name));
        try p.syms.defineSymbol(p, interned_declarator_name, init_d.d.ty, init_d.d.name, node, .{}, false);

        const func = p.func;
        p.func = .{
            .ty = init_d.d.ty,
            .name = init_d.d.name,
        };
        if (interned_declarator_name == p.string_ids.main_id and !init_d.d.ty.returnType().is(.int)) {
            try p.errTok(.main_return_type, init_d.d.name);
        }
        defer p.func = func;

        try p.syms.pushScope(p);
        defer p.syms.popScope();

        // Collect old style parameter declarations.
        if (init_d.d.old_style_func != null) {
            var base_ty = init_d.d.ty.base();
            base_ty.specifier = .func;

            const param_buf_top = p.param_buf.items.len;
            defer p.param_buf.items.len = param_buf_top;

            param_loop: while (true) {
                const param_decl_spec = (try p.declSpec()) orelse break;
                if (p.eatToken(.semicolon)) |semi| {
                    try p.errTok(.missing_declaration, semi);
                    continue :param_loop;
                }

                while (true) {
                    const attr_buf_top_declarator = p.attr_buf.len;
                    defer p.attr_buf.len = attr_buf_top_declarator;

                    var d = (try p.declarator(param_decl_spec.ty, .param)) orelse {
                        try p.errTok(.missing_declaration, first_tok);
                        _ = try p.expectToken(.semicolon);
                        continue :param_loop;
                    };
                    try p.attributeSpecifier();

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
                    const interned_name = try StrInt.intern(p.comp, name_str);
                    for (init_d.d.ty.params()) |*param| {
                        if (param.name == interned_name) {
                            param.ty = d.ty;
                            break;
                        }
                    } else {
                        try p.errStr(.parameter_missing, d.name, name_str);
                    }
                    d.ty = try Attribute.applyParameterAttributes(p, d.ty, attr_buf_top_declarator, .alignas_on_param);

                    // bypass redefinition check to avoid duplicate errors
                    try p.syms.define(p.gpa, .{
                        .kind = .def,
                        .name = interned_name,
                        .tok = d.name,
                        .ty = d.ty,
                        .val = .{},
                    });
                    if (p.eatToken(.comma) == null) break;
                }
                _ = try p.expectToken(.semicolon);
            }
        } else {
            for (init_d.d.ty.params()) |param| {
                if (param.ty.hasUnboundVLA()) try p.errTok(.unbound_vla, param.name_tok);
                if (param.ty.hasIncompleteSize() and !param.ty.is(.void) and param.ty.specifier != .invalid) {
                    try p.errStr(.parameter_incomplete_ty, param.name_tok, try p.typeStr(param.ty));
                }

                if (param.name == .empty) {
                    try p.errTok(.omitting_parameter_name, param.name_tok);
                    continue;
                }

                // bypass redefinition check to avoid duplicate errors
                try p.syms.define(p.gpa, .{
                    .kind = .def,
                    .name = param.name,
                    .tok = param.name_tok,
                    .ty = param.ty,
                    .val = .{},
                });
            }
        }

        const body = (try p.compoundStmt(true, null)) orelse {
            assert(init_d.d.old_style_func != null);
            try p.err(.expected_fn_body);
            return true;
        };

        try decl_spec.validateFnDef(p);
        try p.tree.addNodeExtra(.{ .fn_def = .{
            .name_tok = init_d.d.name,
            .@"inline" = decl_spec.@"inline" != null,
            .static = decl_spec.storage_class == .static,
            .type = init_d.d.ty,
            .body = body,
        } }, reserved_index);

        try p.decl_buf.append(node);

        // check gotos
        if (func.ty == null) {
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
    var warned_auto = false;
    while (true) {
        if (init_d.d.old_style_func) |tok_i| try p.errTok(.invalid_old_style_params, tok_i);
        try decl_spec.validate(p, &init_d.d.ty);

        const node = if (init_d.d.ty.isFunc()) try p.addNode(.{
            .fn_proto = .{
                .name_tok = init_d.d.name,
                .type = init_d.d.ty,
                .static = decl_spec.storage_class == .static,
                .@"inline" = decl_spec.@"inline" != null,
                .definition = null,
            },
        }) else try p.addNode(.{
            .variable = .{
                .name_tok = init_d.d.name,
                .type = init_d.d.ty,
                .@"extern" = decl_spec.storage_class == .@"extern" and init_d.initializer == null,
                .static = decl_spec.storage_class == .static,
                .thread_local = decl_spec.thread_local != null,
                .implicit = false,
                .initializer = if (init_d.initializer) |some| some.node else null,
            },
        });
        try p.decl_buf.append(node);

        const interned_name = try StrInt.intern(p.comp, p.tokSlice(init_d.d.name));
        if (decl_spec.storage_class == .typedef) {
            try p.syms.defineTypedef(p, interned_name, init_d.d.ty, init_d.d.name, node);
            p.typedefDefined(interned_name, init_d.d.ty);
        } else if (init_d.initializer) |init| {
            // TODO validate global variable/constexpr initializer comptime known
            try p.syms.defineSymbol(
                p,
                interned_name,
                init_d.d.ty,
                init_d.d.name,
                node,
                if (init_d.d.ty.isConst() or decl_spec.constexpr != null) init.val else .{},
                decl_spec.constexpr != null,
            );
        } else if (p.func.ty != null and decl_spec.storage_class != .@"extern") {
            try p.syms.defineSymbol(p, interned_name, init_d.d.ty, init_d.d.name, node, .{}, false);
        } else {
            try p.syms.declareSymbol(p, interned_name, init_d.d.ty, init_d.d.name, node);
        }

        if (p.eatToken(.comma) == null) break;

        if (!warned_auto) {
            if (decl_spec.auto_type) |tok_i| {
                try p.errTok(.auto_type_requires_single_declarator, tok_i);
                warned_auto = true;
            }
            if (p.comp.langopts.standard.atLeast(.c23) and decl_spec.storage_class == .auto) {
                try p.errTok(.c23_auto_single_declarator, decl_spec.storage_class.auto);
                warned_auto = true;
            }
        }

        init_d = (try p.initDeclarator(&decl_spec, attr_buf_top)) orelse {
            try p.err(.expected_ident_or_l_paren);
            continue;
        };
    }

    _ = try p.expectToken(.semicolon);
    return true;
}

fn staticAssertMessage(p: *Parser, cond_node: Node.Index, maybe_message: ?Result) !?[]const u8 {
    var buf = std.ArrayList(u8).init(p.gpa);
    defer buf.deinit();

    const cond = cond_node.get(&p.tree);
    if (cond == .builtin_types_compatible_p) {
        const mapper = p.comp.string_interner.getSlowTypeMapper();

        try buf.appendSlice("'__builtin_types_compatible_p(");

        const lhs_ty = cond.builtin_types_compatible_p.lhs;
        try lhs_ty.print(mapper, p.comp.langopts, buf.writer());
        try buf.appendSlice(", ");

        const rhs_ty = cond.builtin_types_compatible_p.rhs;
        try rhs_ty.print(mapper, p.comp.langopts, buf.writer());

        try buf.appendSlice(")'");
    } else if (maybe_message == null) return null;

    if (maybe_message) |message| {
        assert(message.node.get(&p.tree) == .string_literal_expr);
        if (buf.items.len > 0) {
            try buf.append(' ');
        }
        const bytes = p.comp.interner.get(message.val.ref()).bytes;
        try buf.ensureUnusedCapacity(bytes.len);
        try Value.printString(bytes, message.ty, p.comp, buf.writer());
    }
    return try p.comp.diagnostics.arena.allocator().dupe(u8, buf.items);
}

/// staticAssert
///    : keyword_static_assert '(' integerConstExpr (',' STRING_LITERAL)? ')' ';'
///    | keyword_c23_static_assert '(' integerConstExpr (',' STRING_LITERAL)? ')' ';'
fn staticAssert(p: *Parser) Error!bool {
    const static_assert = p.eatToken(.keyword_static_assert) orelse p.eatToken(.keyword_c23_static_assert) orelse return false;
    const l_paren = try p.expectToken(.l_paren);
    const res_token = p.tok_i;
    var res = try p.constExpr(.gnu_folding_extension);
    const res_node = res.node;
    const str = if (p.eatToken(.comma) != null)
        switch (p.tok_ids[p.tok_i]) {
            .string_literal,
            .string_literal_utf_16,
            .string_literal_utf_8,
            .string_literal_utf_32,
            .string_literal_wide,
            .unterminated_string_literal,
            => try p.stringLiteral(),
            else => {
                try p.err(.expected_str_literal);
                return error.ParsingFailed;
            },
        }
    else
        null;
    try p.expectClosing(l_paren, .r_paren);
    _ = try p.expectToken(.semicolon);
    if (str == null) {
        try p.errTok(.static_assert_missing_message, static_assert);
        try p.errStr(.pre_c23_compat, static_assert, "'_Static_assert' with no message");
    }

    const is_int_expr = res.ty.isInt();
    try res.boolCast(p, .{ .specifier = .bool }, res_token);
    if (!is_int_expr) {
        res.val = .{};
    }
    if (res.val.opt_ref == .none) {
        if (res.ty.specifier != .invalid) {
            try p.errTok(.static_assert_not_constant, res_token);
        }
    } else {
        if (!res.val.toBool(p.comp)) {
            if (try p.staticAssertMessage(res_node, str)) |message| {
                try p.errStr(.static_assert_failure_message, static_assert, message);
            } else {
                try p.errTok(.static_assert_failure, static_assert);
            }
        }
    }

    const node = try p.addNode(.{
        .static_assert = .{
            .assert_tok = static_assert,
            .cond = res.node,
            .message = if (str) |some| some.node else null,
        },
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
    constexpr: ?TokenIndex = null,
    @"inline": ?TokenIndex = null,
    noreturn: ?TokenIndex = null,
    auto_type: ?TokenIndex = null,
    ty: Type,

    fn validateParam(d: DeclSpec, p: *Parser, ty: *Type) Error!void {
        switch (d.storage_class) {
            .none => {},
            .register => ty.qual.register = true,
            .auto, .@"extern", .static, .typedef => |tok_i| try p.errTok(.invalid_storage_on_param, tok_i),
        }
        if (d.thread_local) |tok_i| try p.errTok(.threadlocal_non_var, tok_i);
        if (d.@"inline") |tok_i| try p.errStr(.func_spec_non_func, tok_i, "inline");
        if (d.noreturn) |tok_i| try p.errStr(.func_spec_non_func, tok_i, "_Noreturn");
        if (d.constexpr) |tok_i| try p.errTok(.invalid_storage_on_param, tok_i);
        if (d.auto_type) |tok_i| {
            try p.errStr(.auto_type_not_allowed, tok_i, "function prototype");
            ty.* = Type.invalid;
        }
    }

    fn validateFnDef(d: DeclSpec, p: *Parser) Error!void {
        switch (d.storage_class) {
            .none, .@"extern", .static => {},
            .auto, .register, .typedef => |tok_i| try p.errTok(.illegal_storage_on_func, tok_i),
        }
        if (d.thread_local) |tok_i| try p.errTok(.threadlocal_non_var, tok_i);
        if (d.constexpr) |tok_i| try p.errTok(.illegal_storage_on_func, tok_i);
    }

    fn validate(d: DeclSpec, p: *Parser, ty: *Type) Error!void {
        if (ty.isFunc() and d.storage_class != .typedef) {
            switch (d.storage_class) {
                .none, .@"extern" => {},
                .static => |tok_i| if (p.func.ty != null) try p.errTok(.static_func_not_global, tok_i),
                .typedef => unreachable,
                .auto, .register => |tok_i| try p.errTok(.illegal_storage_on_func, tok_i),
            }
            if (d.thread_local) |tok_i| try p.errTok(.threadlocal_non_var, tok_i);
            if (d.constexpr) |tok_i| try p.errTok(.illegal_storage_on_func, tok_i);
        } else {
            if (d.@"inline") |tok_i| try p.errStr(.func_spec_non_func, tok_i, "inline");
            // TODO move to attribute validation
            if (d.noreturn) |tok_i| try p.errStr(.func_spec_non_func, tok_i, "_Noreturn");
            switch (d.storage_class) {
                .auto => if (p.func.ty == null and !p.comp.langopts.standard.atLeast(.c23)) {
                    try p.err(.illegal_storage_on_global);
                },
                .register => if (p.func.ty == null) try p.err(.illegal_storage_on_global),
                else => {},
            }
            ty.qual.register = d.storage_class == .register;
        }
    }

    fn initContext(d: DeclSpec, p: *Parser) InitContext {
        if (d.constexpr != null) return .constexpr;
        if (p.func.ty == null or d.storage_class == .static) return .static;
        return .runtime;
    }
};

/// typeof
///   : keyword_typeof '(' typeName ')'
///   | keyword_typeof '(' expr ')'
fn typeof(p: *Parser) Error!?Type {
    var unqual = false;
    switch (p.tok_ids[p.tok_i]) {
        .keyword_typeof, .keyword_typeof1, .keyword_typeof2 => p.tok_i += 1,
        .keyword_typeof_unqual => {
            p.tok_i += 1;
            unqual = true;
        },
        else => return null,
    }
    const l_paren = try p.expectToken(.l_paren);
    if (try p.typeName()) |ty| {
        try p.expectClosing(l_paren, .r_paren);
        if (ty.is(.invalid)) return null;

        const typeof_ty = try p.arena.create(Type);
        typeof_ty.* = .{
            .data = ty.data,
            .qual = if (unqual) .{} else ty.qual.inheritFromTypeof(),
            .specifier = ty.specifier,
        };

        return Type{
            .data = .{ .sub_type = typeof_ty },
            .specifier = .typeof_type,
        };
    }
    const typeof_expr = try p.parseNoEval(expr);
    try p.expectClosing(l_paren, .r_paren);
    // Special case nullptr_t since it's defined as typeof(nullptr)
    if (typeof_expr.ty.is(.nullptr_t)) {
        return Type{
            .specifier = .nullptr_t,
            .qual = if (unqual) .{} else typeof_expr.ty.qual.inheritFromTypeof(),
        };
    } else if (typeof_expr.ty.is(.invalid)) {
        return null;
    }

    const inner = try p.arena.create(Type.Expr);
    inner.* = .{
        .node = typeof_expr.node,
        .ty = .{
            .data = typeof_expr.ty.data,
            .qual = if (unqual) .{} else typeof_expr.ty.qual.inheritFromTypeof(),
            .specifier = typeof_expr.ty.specifier,
            .decayed = typeof_expr.ty.decayed,
        },
    };

    return Type{
        .data = .{ .expr = inner },
        .specifier = .typeof_expr,
        .decayed = typeof_expr.ty.decayed,
    };
}

/// declSpec: (storageClassSpec | typeSpec | typeQual | funcSpec | alignSpec)+
/// funcSpec : keyword_inline | keyword_noreturn
fn declSpec(p: *Parser) Error!?DeclSpec {
    var d: DeclSpec = .{ .ty = .{ .specifier = undefined } };
    var spec: Type.Builder = .{};

    var combined_auto = !p.comp.langopts.standard.atLeast(.c23);
    const start = p.tok_i;
    while (true) {
        if (!combined_auto and d.storage_class == .auto) {
            try spec.combine(p, .c23_auto, d.storage_class.auto);
            combined_auto = true;
        }
        if (try p.storageClassSpec(&d)) continue;
        if (try p.typeSpec(&spec)) continue;
        const id = p.tok_ids[p.tok_i];
        switch (id) {
            .keyword_inline, .keyword_inline1, .keyword_inline2 => {
                if (d.@"inline" != null) {
                    try p.errStr(.duplicate_decl_spec, p.tok_i, "inline");
                }
                d.@"inline" = p.tok_i;
            },
            .keyword_noreturn => {
                if (d.noreturn != null) {
                    try p.errStr(.duplicate_decl_spec, p.tok_i, "_Noreturn");
                }
                d.noreturn = p.tok_i;
            },
            else => break,
        }
        p.tok_i += 1;
    }

    if (p.tok_i == start) return null;

    d.ty = try spec.finish(p);
    d.auto_type = spec.auto_type_tok;
    return d;
}

/// storageClassSpec:
///  : keyword_typedef
///  | keyword_extern
///  | keyword_static
///  | keyword_threadlocal
///  | keyword_auto
///  | keyword_register
fn storageClassSpec(p: *Parser, d: *DeclSpec) Error!bool {
    const start = p.tok_i;
    while (true) {
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
                        .keyword_extern, .keyword_static => {},
                        else => try p.errStr(.cannot_combine_spec, p.tok_i, id.lexeme().?),
                    }
                    if (d.constexpr) |tok| try p.errStr(.cannot_combine_spec, p.tok_i, p.tok_ids[tok].lexeme().?);
                }
                if (d.constexpr != null) {
                    switch (id) {
                        .keyword_auto, .keyword_register, .keyword_static => {},
                        else => try p.errStr(.cannot_combine_spec, p.tok_i, id.lexeme().?),
                    }
                    if (d.thread_local) |tok| try p.errStr(.cannot_combine_spec, p.tok_i, p.tok_ids[tok].lexeme().?);
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
            .keyword_thread_local,
            .keyword_c23_thread_local,
            => {
                if (d.thread_local != null) {
                    try p.errStr(.duplicate_decl_spec, p.tok_i, id.lexeme().?);
                }
                if (d.constexpr) |tok| try p.errStr(.cannot_combine_spec, p.tok_i, p.tok_ids[tok].lexeme().?);
                switch (d.storage_class) {
                    .@"extern", .none, .static => {},
                    else => try p.errStr(.cannot_combine_spec, p.tok_i, @tagName(d.storage_class)),
                }
                d.thread_local = p.tok_i;
            },
            .keyword_constexpr => {
                if (d.constexpr != null) {
                    try p.errStr(.duplicate_decl_spec, p.tok_i, id.lexeme().?);
                }
                if (d.thread_local) |tok| try p.errStr(.cannot_combine_spec, p.tok_i, p.tok_ids[tok].lexeme().?);
                switch (d.storage_class) {
                    .auto, .register, .none, .static => {},
                    else => try p.errStr(.cannot_combine_spec, p.tok_i, @tagName(d.storage_class)),
                }
                d.constexpr = p.tok_i;
            },
            else => break,
        }
        p.tok_i += 1;
    }
    return p.tok_i != start;
}

const InitDeclarator = struct { d: Declarator, initializer: ?Result = null };

/// attribute
///  : attrIdentifier
///  | attrIdentifier '(' identifier ')'
///  | attrIdentifier '(' identifier (',' expr)+ ')'
///  | attrIdentifier '(' (expr (',' expr)*)? ')'
fn attribute(p: *Parser, kind: Attribute.Kind, namespace: ?[]const u8) Error!?TentativeAttribute {
    const name_tok = p.tok_i;
    switch (p.tok_ids[p.tok_i]) {
        .keyword_const, .keyword_const1, .keyword_const2 => p.tok_i += 1,
        else => _ = try p.expectIdentifier(),
    }
    const name = p.tokSlice(name_tok);

    const attr = Attribute.fromString(kind, namespace, name) orelse {
        const tag: Diagnostics.Tag = if (kind == .declspec) .declspec_attr_not_supported else .unknown_attribute;
        try p.errStr(tag, name_tok, name);
        if (p.eatToken(.l_paren)) |_| p.skipTo(.r_paren);
        return null;
    };

    const required_count = Attribute.requiredArgCount(attr);
    var arguments = Attribute.initArguments(attr, name_tok);
    var arg_idx: u32 = 0;

    switch (p.tok_ids[p.tok_i]) {
        .comma, .r_paren => {}, // will be consumed in attributeList
        .l_paren => blk: {
            p.tok_i += 1;
            if (p.eatToken(.r_paren)) |_| break :blk;

            if (Attribute.wantsIdentEnum(attr)) {
                if (try p.eatIdentifier()) |ident| {
                    if (Attribute.diagnoseIdent(attr, &arguments, p.tokSlice(ident))) |msg| {
                        try p.errExtra(msg.tag, ident, msg.extra);
                        p.skipTo(.r_paren);
                        return error.ParsingFailed;
                    }
                } else {
                    try p.errExtra(.attribute_requires_identifier, name_tok, .{ .str = name });
                    return error.ParsingFailed;
                }
            } else {
                const arg_start = p.tok_i;
                const first_expr = try p.expect(assignExpr);
                if (try p.diagnose(attr, &arguments, arg_idx, first_expr)) |msg| {
                    try p.errExtra(msg.tag, arg_start, msg.extra);
                    p.skipTo(.r_paren);
                    return error.ParsingFailed;
                }
            }
            arg_idx += 1;
            while (p.eatToken(.r_paren) == null) : (arg_idx += 1) {
                _ = try p.expectToken(.comma);

                const arg_start = p.tok_i;
                const arg_expr = try p.expect(assignExpr);
                if (try p.diagnose(attr, &arguments, arg_idx, arg_expr)) |msg| {
                    try p.errExtra(msg.tag, arg_start, msg.extra);
                    p.skipTo(.r_paren);
                    return error.ParsingFailed;
                }
            }
        },
        else => {},
    }
    if (arg_idx < required_count) {
        try p.errExtra(.attribute_not_enough_args, name_tok, .{ .attr_arg_count = .{ .attribute = attr, .expected = required_count } });
        return error.ParsingFailed;
    }
    return TentativeAttribute{ .attr = .{ .tag = attr, .args = arguments, .syntax = kind.toSyntax() }, .tok = name_tok };
}

fn diagnose(p: *Parser, attr: Attribute.Tag, arguments: *Attribute.Arguments, arg_idx: u32, res: Result) !?Diagnostics.Message {
    if (Attribute.wantsAlignment(attr, arg_idx)) {
        return Attribute.diagnoseAlignment(attr, arguments, arg_idx, res, p);
    }
    return Attribute.diagnose(attr, arguments, arg_idx, res, res.node.get(&p.tree), p);
}

/// attributeList : (attribute (',' attribute)*)?
fn gnuAttributeList(p: *Parser) Error!void {
    if (p.tok_ids[p.tok_i] == .r_paren) return;

    if (try p.attribute(.gnu, null)) |attr| try p.attr_buf.append(p.gpa, attr);
    while (p.tok_ids[p.tok_i] != .r_paren) {
        _ = try p.expectToken(.comma);
        if (try p.attribute(.gnu, null)) |attr| try p.attr_buf.append(p.gpa, attr);
    }
}

fn c23AttributeList(p: *Parser) Error!void {
    while (p.tok_ids[p.tok_i] != .r_bracket) {
        const namespace_tok = try p.expectIdentifier();
        var namespace: ?[]const u8 = null;
        if (p.eatToken(.colon_colon)) |_| {
            namespace = p.tokSlice(namespace_tok);
        } else {
            p.tok_i -= 1;
        }
        if (try p.attribute(.c23, namespace)) |attr| try p.attr_buf.append(p.gpa, attr);
        _ = p.eatToken(.comma);
    }
}

fn msvcAttributeList(p: *Parser) Error!void {
    while (p.tok_ids[p.tok_i] != .r_paren) {
        if (try p.attribute(.declspec, null)) |attr| try p.attr_buf.append(p.gpa, attr);
        _ = p.eatToken(.comma);
    }
}

fn c23Attribute(p: *Parser) !bool {
    if (!p.comp.langopts.standard.atLeast(.c23)) return false;
    const bracket1 = p.eatToken(.l_bracket) orelse return false;
    const bracket2 = p.eatToken(.l_bracket) orelse {
        p.tok_i -= 1;
        return false;
    };

    try p.c23AttributeList();

    _ = try p.expectClosing(bracket2, .r_bracket);
    _ = try p.expectClosing(bracket1, .r_bracket);

    return true;
}

fn msvcAttribute(p: *Parser) !bool {
    _ = p.eatToken(.keyword_declspec) orelse return false;
    const l_paren = try p.expectToken(.l_paren);
    try p.msvcAttributeList();
    _ = try p.expectClosing(l_paren, .r_paren);

    return true;
}

fn gnuAttribute(p: *Parser) !bool {
    switch (p.tok_ids[p.tok_i]) {
        .keyword_attribute1, .keyword_attribute2 => p.tok_i += 1,
        else => return false,
    }
    const paren1 = try p.expectToken(.l_paren);
    const paren2 = try p.expectToken(.l_paren);

    try p.gnuAttributeList();

    _ = try p.expectClosing(paren2, .r_paren);
    _ = try p.expectClosing(paren1, .r_paren);
    return true;
}

fn attributeSpecifier(p: *Parser) Error!void {
    return attributeSpecifierExtra(p, null);
}

/// attributeSpecifier : (keyword_attribute '( '(' attributeList ')' ')')*
fn attributeSpecifierExtra(p: *Parser, declarator_name: ?TokenIndex) Error!void {
    while (true) {
        if (try p.gnuAttribute()) continue;
        if (try p.c23Attribute()) continue;
        const maybe_declspec_tok = p.tok_i;
        const attr_buf_top = p.attr_buf.len;
        if (try p.msvcAttribute()) {
            if (declarator_name) |name_tok| {
                try p.errTok(.declspec_not_allowed_after_declarator, maybe_declspec_tok);
                try p.errTok(.declarator_name_tok, name_tok);
                p.attr_buf.len = attr_buf_top;
            }
            continue;
        }
        break;
    }
}

/// initDeclarator : declarator assembly? attributeSpecifier? ('=' initializer)?
fn initDeclarator(p: *Parser, decl_spec: *DeclSpec, attr_buf_top: usize) Error!?InitDeclarator {
    const this_attr_buf_top = p.attr_buf.len;
    defer p.attr_buf.len = this_attr_buf_top;

    var init_d = InitDeclarator{
        .d = (try p.declarator(decl_spec.ty, .normal)) orelse return null,
    };

    if (decl_spec.ty.is(.c23_auto) and !init_d.d.ty.is(.c23_auto)) {
        try p.errTok(.c23_auto_plain_declarator, decl_spec.storage_class.auto);
        return error.ParsingFailed;
    }

    try p.attributeSpecifierExtra(init_d.d.name);
    _ = try p.assembly(.decl_label);
    try p.attributeSpecifierExtra(init_d.d.name);

    var apply_var_attributes = false;
    if (decl_spec.storage_class == .typedef) {
        if (decl_spec.auto_type) |tok_i| {
            try p.errStr(.auto_type_not_allowed, tok_i, "typedef");
            return error.ParsingFailed;
        }
        init_d.d.ty = try Attribute.applyTypeAttributes(p, init_d.d.ty, attr_buf_top, null);
    } else if (init_d.d.ty.isFunc()) {
        init_d.d.ty = try Attribute.applyFunctionAttributes(p, init_d.d.ty, attr_buf_top);
    } else {
        apply_var_attributes = true;
    }
    const c23_auto = init_d.d.ty.is(.c23_auto);
    const auto_type = init_d.d.ty.is(.auto_type);

    if (p.eatToken(.equal)) |eq| init: {
        if (decl_spec.storage_class == .typedef or
            (init_d.d.func_declarator != null and init_d.d.ty.isFunc()))
        {
            try p.errTok(.illegal_initializer, eq);
        } else if (init_d.d.ty.is(.variable_len_array)) {
            try p.errTok(.vla_init, eq);
        } else if (decl_spec.storage_class == .@"extern") {
            try p.err(.extern_initializer);
            decl_spec.storage_class = .none;
        }

        if (init_d.d.ty.hasIncompleteSize() and !init_d.d.ty.is(.incomplete_array)) {
            try p.errStr(.variable_incomplete_ty, init_d.d.name, try p.typeStr(init_d.d.ty));
            return error.ParsingFailed;
        }
        if (p.tok_ids[p.tok_i] == .l_brace and init_d.d.ty.is(.c23_auto)) {
            try p.errTok(.c23_auto_scalar_init, decl_spec.storage_class.auto);
            return error.ParsingFailed;
        }

        try p.syms.pushScope(p);
        defer p.syms.popScope();

        const interned_name = try StrInt.intern(p.comp, p.tokSlice(init_d.d.name));
        try p.syms.declareSymbol(p, interned_name, init_d.d.ty, init_d.d.name, null);
        if (c23_auto or auto_type) {
            p.auto_type_decl_name = interned_name;
        }
        defer p.auto_type_decl_name = .empty;

        const init_context = p.init_context;
        defer p.init_context = init_context;
        p.init_context = decl_spec.initContext(p);
        var init_list_expr = try p.initializer(init_d.d.ty);
        init_d.initializer = init_list_expr;
        if (!init_list_expr.ty.isArray()) break :init;
        if (init_d.d.ty.is(.incomplete_array)) {
            init_d.d.ty.setIncompleteArrayLen(init_list_expr.ty.arrayLen() orelse break :init);
        }
    }

    const name = init_d.d.name;
    if (auto_type or c23_auto) {
        if (init_d.initializer) |some| {
            init_d.d.ty.specifier = some.ty.specifier;
            init_d.d.ty.data = some.ty.data;
            init_d.d.ty.decayed = some.ty.decayed;
        } else {
            init_d.d.ty = Type.invalid;
            if (c23_auto) {
                try p.errStr(.c32_auto_requires_initializer, decl_spec.storage_class.auto, p.tokSlice(name));
            } else {
                try p.errStr(.auto_type_requires_initializer, name, p.tokSlice(name));
            }
            return init_d;
        }
    }
    if (apply_var_attributes) {
        init_d.d.ty = try Attribute.applyVariableAttributes(p, init_d.d.ty, attr_buf_top, null);
    }
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
        if (init_d.initializer != null) break :incomplete;

        if (p.func.ty == null) {
            if (specifier == .incomplete_array) {
                // TODO properly check this after finishing parsing
                try p.errStr(.tentative_array, name, try p.typeStr(init_d.d.ty));
                break :incomplete;
            } else if (init_d.d.ty.getRecord()) |record| {
                _ = try p.tentative_defs.getOrPutValue(p.gpa, record.name, init_d.d.name);
                break :incomplete;
            } else if (init_d.d.ty.get(.@"enum")) |en| {
                _ = try p.tentative_defs.getOrPutValue(p.gpa, en.data.@"enum".name, init_d.d.name);
                break :incomplete;
            }
        }
        try p.errStr(.variable_incomplete_ty, name, try p.typeStr(init_d.d.ty));
    }
    return init_d;
}

/// typeSpec
///  : keyword_void
///  | keyword_auto_type
///  | keyword_char
///  | keyword_short
///  | keyword_int
///  | keyword_long
///  | keyword_float
///  | keyword_double
///  | keyword_signed
///  | keyword_signed1
///  | keyword_signed2
///  | keyword_unsigned
///  | keyword_bool
///  | keyword_c23_bool
///  | keyword_complex
///  | atomicTypeSpec
///  | recordSpec
///  | enumSpec
///  | typedef  // IDENTIFIER
///  | typeof
///  | keyword_bit_int '(' integerConstExpr ')'
/// atomicTypeSpec : keyword_atomic '(' typeName ')'
/// alignSpec
///   : keyword_alignas '(' typeName ')'
///   | keyword_alignas '(' integerConstExpr ')'
///   | keyword_c23_alignas '(' typeName ')'
///   | keyword_c23_alignas '(' integerConstExpr ')'
fn typeSpec(p: *Parser, ty: *Type.Builder) Error!bool {
    const start = p.tok_i;
    while (true) {
        try p.attributeSpecifier();

        if (try p.typeof()) |inner_ty| {
            try ty.combineFromTypeof(p, inner_ty, start);
            continue;
        }
        if (try p.typeQual(&ty.qual)) continue;
        switch (p.tok_ids[p.tok_i]) {
            .keyword_void => try ty.combine(p, .void, p.tok_i),
            .keyword_auto_type => {
                try p.errTok(.auto_type_extension, p.tok_i);
                try ty.combine(p, .auto_type, p.tok_i);
            },
            .keyword_bool, .keyword_c23_bool => try ty.combine(p, .bool, p.tok_i),
            .keyword_int8, .keyword_int8_2, .keyword_char => try ty.combine(p, .char, p.tok_i),
            .keyword_int16, .keyword_int16_2, .keyword_short => try ty.combine(p, .short, p.tok_i),
            .keyword_int32, .keyword_int32_2, .keyword_int => try ty.combine(p, .int, p.tok_i),
            .keyword_long => try ty.combine(p, .long, p.tok_i),
            .keyword_int64, .keyword_int64_2 => try ty.combine(p, .long_long, p.tok_i),
            .keyword_int128 => try ty.combine(p, .int128, p.tok_i),
            .keyword_signed, .keyword_signed1, .keyword_signed2 => try ty.combine(p, .signed, p.tok_i),
            .keyword_unsigned => try ty.combine(p, .unsigned, p.tok_i),
            .keyword_fp16 => try ty.combine(p, .fp16, p.tok_i),
            .keyword_float16 => try ty.combine(p, .float16, p.tok_i),
            .keyword_float => try ty.combine(p, .float, p.tok_i),
            .keyword_double => try ty.combine(p, .double, p.tok_i),
            .keyword_complex => try ty.combine(p, .complex, p.tok_i),
            .keyword_float128_1, .keyword_float128_2 => {
                if (!p.comp.hasFloat128()) {
                    try p.errStr(.type_not_supported_on_target, p.tok_i, p.tok_ids[p.tok_i].lexeme().?);
                }
                try ty.combine(p, .float128, p.tok_i);
            },
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
            .keyword_alignas,
            .keyword_c23_alignas,
            => {
                const align_tok = p.tok_i;
                p.tok_i += 1;
                const l_paren = try p.expectToken(.l_paren);
                const typename_start = p.tok_i;
                if (try p.typeName()) |inner_ty| {
                    if (!inner_ty.alignable()) {
                        try p.errStr(.invalid_alignof, typename_start, try p.typeStr(inner_ty));
                    }
                    const alignment = Attribute.Alignment{ .requested = inner_ty.alignof(p.comp) };
                    try p.attr_buf.append(p.gpa, .{
                        .attr = .{ .tag = .aligned, .args = .{
                            .aligned = .{ .alignment = alignment, .__name_tok = align_tok },
                        }, .syntax = .keyword },
                        .tok = align_tok,
                    });
                } else {
                    const arg_start = p.tok_i;
                    const res = try p.integerConstExpr(.no_const_decl_folding);
                    if (!res.val.isZero(p.comp)) {
                        var args = Attribute.initArguments(.aligned, align_tok);
                        if (try p.diagnose(.aligned, &args, 0, res)) |msg| {
                            try p.errExtra(msg.tag, arg_start, msg.extra);
                            p.skipTo(.r_paren);
                            return error.ParsingFailed;
                        }
                        // TODO this looks unused?
                        // args.aligned.alignment.?.node = res.node;
                        try p.attr_buf.append(p.gpa, .{
                            .attr = .{ .tag = .aligned, .args = args, .syntax = .keyword },
                            .tok = align_tok,
                        });
                    }
                }
                try p.expectClosing(l_paren, .r_paren);
                continue;
            },
            .keyword_stdcall,
            .keyword_stdcall2,
            .keyword_thiscall,
            .keyword_thiscall2,
            .keyword_vectorcall,
            .keyword_vectorcall2,
            => try p.attr_buf.append(p.gpa, .{
                .attr = .{ .tag = .calling_convention, .args = .{
                    .calling_convention = .{ .cc = switch (p.tok_ids[p.tok_i]) {
                        .keyword_stdcall,
                        .keyword_stdcall2,
                        => .stdcall,
                        .keyword_thiscall,
                        .keyword_thiscall2,
                        => .thiscall,
                        .keyword_vectorcall,
                        .keyword_vectorcall2,
                        => .vectorcall,
                        else => unreachable,
                    } },
                }, .syntax = .keyword },
                .tok = p.tok_i,
            }),
            .keyword_struct, .keyword_union => {
                const tag_tok = p.tok_i;
                const record_ty = try p.recordSpec();
                try ty.combine(p, Type.Builder.fromType(record_ty), tag_tok);
                continue;
            },
            .keyword_enum => {
                const tag_tok = p.tok_i;
                const enum_ty = try p.enumSpec();
                try ty.combine(p, Type.Builder.fromType(enum_ty), tag_tok);
                continue;
            },
            .identifier, .extended_identifier => {
                var interned_name = try StrInt.intern(p.comp, p.tokSlice(p.tok_i));
                var declspec_found = false;

                if (interned_name == p.string_ids.declspec_id) {
                    try p.errTok(.declspec_not_enabled, p.tok_i);
                    p.tok_i += 1;
                    if (p.eatToken(.l_paren)) |_| {
                        p.skipTo(.r_paren);
                        continue;
                    }
                    declspec_found = true;
                }
                if (ty.typedef != null) break;
                if (declspec_found) {
                    interned_name = try StrInt.intern(p.comp, p.tokSlice(p.tok_i));
                }
                const typedef = (try p.syms.findTypedef(p, interned_name, p.tok_i, ty.specifier != .none)) orelse break;
                if (!ty.combineTypedef(p, typedef.ty, typedef.tok)) break;
            },
            .keyword_bit_int => {
                try p.err(.bit_int);
                const bit_int_tok = p.tok_i;
                p.tok_i += 1;
                const l_paren = try p.expectToken(.l_paren);
                const res = try p.integerConstExpr(.gnu_folding_extension);
                try p.expectClosing(l_paren, .r_paren);

                var bits: u64 = undefined;
                if (res.val.opt_ref == .none) {
                    try p.errTok(.expected_integer_constant_expr, bit_int_tok);
                    return error.ParsingFailed;
                } else if (res.val.compare(.lte, Value.zero, p.comp)) {
                    bits = 0;
                } else {
                    bits = res.val.toInt(u64, p.comp) orelse std.math.maxInt(u64);
                }

                try ty.combine(p, .{ .bit_int = bits }, bit_int_tok);
                continue;
            },
            else => break,
        }
        // consume single token specifiers here
        p.tok_i += 1;
    }
    return p.tok_i != start;
}

fn getAnonymousName(p: *Parser, kind_tok: TokenIndex) !StringId {
    const loc = p.pp.tokens.items(.loc)[kind_tok];
    const source = p.comp.getSource(loc.id);
    const line_col = source.lineCol(loc);

    const kind_str = switch (p.tok_ids[kind_tok]) {
        .keyword_struct, .keyword_union, .keyword_enum => p.tokSlice(kind_tok),
        else => "record field",
    };

    const str = try std.fmt.allocPrint(
        p.arena,
        "(anonymous {s} at {s}:{d}:{d})",
        .{ kind_str, source.path, line_col.line_no, line_col.col },
    );
    return StrInt.intern(p.comp, str);
}

/// recordSpec
///  : (keyword_struct | keyword_union) IDENTIFIER? { recordDecl* }
///  | (keyword_struct | keyword_union) IDENTIFIER
fn recordSpec(p: *Parser) Error!Type {
    const starting_pragma_pack = p.pragma_pack;
    const kind_tok = p.tok_i;
    const is_struct = p.tok_ids[kind_tok] == .keyword_struct;
    p.tok_i += 1;
    const attr_buf_top = p.attr_buf.len;
    defer p.attr_buf.len = attr_buf_top;
    try p.attributeSpecifier();

    const maybe_ident = try p.eatIdentifier();
    const l_brace = p.eatToken(.l_brace) orelse {
        const ident = maybe_ident orelse {
            try p.err(.ident_or_l_brace);
            return error.ParsingFailed;
        };
        // check if this is a reference to a previous type
        const interned_name = try StrInt.intern(p.comp, p.tokSlice(ident));
        if (try p.syms.findTag(p, interned_name, p.tok_ids[kind_tok], ident, p.tok_ids[p.tok_i])) |prev| {
            return prev.ty;
        } else {
            // this is a forward declaration, create a new record Type.
            const record_ty = try Type.Record.create(p.arena, interned_name);
            const ty = try Attribute.applyTypeAttributes(p, .{
                .specifier = if (is_struct) .@"struct" else .@"union",
                .data = .{ .record = record_ty },
            }, attr_buf_top, null);
            try p.syms.define(p.gpa, .{
                .kind = if (is_struct) .@"struct" else .@"union",
                .name = interned_name,
                .tok = ident,
                .ty = ty,
                .val = .{},
            });

            const fw: Node.ContainerForwardDecl = .{
                .name_or_kind_tok = ident,
                .container_type = ty,
                .definition = null,
            };
            try p.decl_buf.append(try p.addNode(if (is_struct)
                .{ .struct_forward_decl = fw }
            else
                .{ .union_forward_decl = fw }));
            return ty;
        }
    };

    var done = false;
    errdefer if (!done) p.skipTo(.r_brace);

    // Get forward declared type or create a new one
    var defined = false;
    const record_ty: *Type.Record = if (maybe_ident) |ident| record_ty: {
        const ident_str = p.tokSlice(ident);
        const interned_name = try StrInt.intern(p.comp, ident_str);
        if (try p.syms.defineTag(p, interned_name, p.tok_ids[kind_tok], ident)) |prev| {
            if (!prev.ty.hasIncompleteSize()) {
                // if the record isn't incomplete, this is a redefinition
                try p.errStr(.redefinition, ident, ident_str);
                try p.errTok(.previous_definition, prev.tok);
            } else {
                defined = true;
                break :record_ty prev.ty.get(if (is_struct) .@"struct" else .@"union").?.data.record;
            }
        }
        break :record_ty try Type.Record.create(p.arena, interned_name);
    } else try Type.Record.create(p.arena, try p.getAnonymousName(kind_tok));

    // Initially create ty as a regular non-attributed type, since attributes for a record
    // can be specified after the closing rbrace, which we haven't encountered yet.
    var ty = Type{
        .specifier = if (is_struct) .@"struct" else .@"union",
        .data = .{ .record = record_ty },
    };

    // declare a symbol for the type
    // We need to replace the symbol's type if it has attributes
    if (maybe_ident != null and !defined) {
        try p.syms.define(p.gpa, .{
            .kind = if (is_struct) .@"struct" else .@"union",
            .name = record_ty.name,
            .tok = maybe_ident.?,
            .ty = ty,
            .val = .{},
        });
    }

    // reserve space for this record
    try p.decl_buf.append(undefined);
    const decl_buf_top = p.decl_buf.items.len;
    const record_buf_top = p.record_buf.items.len;
    errdefer p.decl_buf.items.len = decl_buf_top - 1;
    defer {
        p.decl_buf.items.len = decl_buf_top;
        p.record_buf.items.len = record_buf_top;
    }

    const old_record = p.record;
    const old_members = p.record_members.items.len;
    const old_field_attr_start = p.field_attr_buf.items.len;
    p.record = .{
        .kind = p.tok_ids[kind_tok],
        .start = p.record_members.items.len,
        .field_attr_start = p.field_attr_buf.items.len,
    };
    defer p.record = old_record;
    defer p.record_members.items.len = old_members;
    defer p.field_attr_buf.items.len = old_field_attr_start;

    try p.recordDecls();

    if (p.record.flexible_field) |some| {
        if (p.record_buf.items[record_buf_top..].len == 1 and is_struct) {
            try p.errTok(.flexible_in_empty, some);
        }
    }

    for (p.record_buf.items[record_buf_top..]) |field| {
        if (field.ty.hasIncompleteSize() and !field.ty.is(.incomplete_array)) break;
    } else {
        record_ty.fields = try p.arena.dupe(Type.Record.Field, p.record_buf.items[record_buf_top..]);
    }
    const attr_count = p.field_attr_buf.items.len - old_field_attr_start;
    const record_decls = p.decl_buf.items[decl_buf_top..];
    if (attr_count > 0) {
        if (attr_count != record_decls.len) {
            // A mismatch here means that non-field decls were parsed. This can happen if there were
            // parse errors during attribute parsing. Bail here because if there are any field attributes,
            // there must be exactly one per field.
            return error.ParsingFailed;
        }
        const field_attr_slice = p.field_attr_buf.items[old_field_attr_start..];
        const duped = try p.arena.dupe([]const Attribute, field_attr_slice);
        record_ty.field_attributes = duped.ptr;
    }

    if (p.record_buf.items.len == record_buf_top) {
        try p.errStr(.empty_record, kind_tok, p.tokSlice(kind_tok));
        try p.errStr(.empty_record_size, kind_tok, p.tokSlice(kind_tok));
    }
    try p.expectClosing(l_brace, .r_brace);
    done = true;
    try p.attributeSpecifier();

    ty = try Attribute.applyTypeAttributes(p, .{
        .specifier = if (is_struct) .@"struct" else .@"union",
        .data = .{ .record = record_ty },
    }, attr_buf_top, null);
    if (ty.specifier == .attributed and maybe_ident != null) {
        const ident_str = p.tokSlice(maybe_ident.?);
        const interned_name = try StrInt.intern(p.comp, ident_str);
        const ptr = p.syms.getPtr(interned_name, .tags);
        ptr.ty = ty;
    }

    if (!ty.hasIncompleteSize()) {
        const pragma_pack_value = switch (p.comp.langopts.emulate) {
            .clang => starting_pragma_pack,
            .gcc => p.pragma_pack,
            // TODO: msvc considers `#pragma pack` on a per-field basis
            .msvc => p.pragma_pack,
        };
        record_layout.compute(record_ty, ty, p.comp, pragma_pack_value) catch |er| switch (er) {
            error.Overflow => try p.errStr(.record_too_large, maybe_ident orelse kind_tok, try p.typeStr(ty)),
        };
    }

    // finish by creating a node
    const node: Node = if (is_struct) .{ .struct_decl = .{
        .name_or_kind_tok = maybe_ident orelse kind_tok,
        .container_type = ty,
        .fields = record_decls,
    } } else .{ .union_decl = .{
        .name_or_kind_tok = maybe_ident orelse kind_tok,
        .container_type = ty,
        .fields = record_decls,
    } };
    p.decl_buf.items[decl_buf_top - 1] = try p.addNode(node);
    if (p.func.ty == null) {
        _ = p.tentative_defs.remove(record_ty.name);
    }
    return ty;
}

/// recordDecl
///  : specQual (recordDeclarator (',' recordDeclarator)*)? ;
///  | staticAssert
fn recordDecls(p: *Parser) Error!void {
    while (true) {
        if (try p.pragma()) continue;
        if (try p.parseOrNextDecl(staticAssert)) continue;
        if (p.eatToken(.keyword_extension)) |_| {
            const saved_extension = p.extension_suppressed;
            defer p.extension_suppressed = saved_extension;
            p.extension_suppressed = true;

            if (try p.parseOrNextDecl(recordDeclarator)) continue;
            try p.err(.expected_type);
            p.nextExternDecl();
            continue;
        }
        if (try p.parseOrNextDecl(recordDeclarator)) continue;
        break;
    }
}

/// recordDeclarator : keyword_extension? declarator (':' integerConstExpr)?
fn recordDeclarator(p: *Parser) Error!bool {
    const attr_buf_top = p.attr_buf.len;
    defer p.attr_buf.len = attr_buf_top;
    const base_ty = (try p.specQual()) orelse return false;

    try p.attributeSpecifier(); // .record
    while (true) {
        const this_decl_top = p.attr_buf.len;
        defer p.attr_buf.len = this_decl_top;

        try p.attributeSpecifier();

        // 0 means unnamed
        var name_tok: TokenIndex = 0;
        var ty = base_ty;
        if (ty.is(.auto_type)) {
            try p.errStr(.auto_type_not_allowed, p.tok_i, if (p.record.kind == .keyword_struct) "struct member" else "union member");
            ty = Type.invalid;
        }
        var bits_node: ?Node.Index = null;
        var bits: ?u32 = null;
        const first_tok = p.tok_i;
        if (try p.declarator(ty, .record)) |d| {
            name_tok = d.name;
            ty = d.ty;
        }

        if (p.eatToken(.colon)) |_| bits: {
            const bits_tok = p.tok_i;
            const res = try p.integerConstExpr(.gnu_folding_extension);
            if (!ty.isInt()) {
                try p.errStr(.non_int_bitfield, first_tok, try p.typeStr(ty));
                break :bits;
            }

            if (res.val.opt_ref == .none) {
                try p.errTok(.expected_integer_constant_expr, bits_tok);
                break :bits;
            } else if (res.val.compare(.lt, Value.zero, p.comp)) {
                try p.errStr(.negative_bitwidth, first_tok, try res.str(p));
                break :bits;
            }

            // incomplete size error is reported later
            const bit_size = ty.bitSizeof(p.comp) orelse break :bits;
            const bits_unchecked = res.val.toInt(u32, p.comp) orelse std.math.maxInt(u32);
            if (bits_unchecked > bit_size) {
                try p.errTok(.bitfield_too_big, name_tok);
                break :bits;
            } else if (bits_unchecked == 0 and name_tok != 0) {
                try p.errTok(.zero_width_named_field, name_tok);
                break :bits;
            }

            bits = bits_unchecked;
            bits_node = res.node;
        }

        try p.attributeSpecifier(); // .record
        const to_append = try Attribute.applyFieldAttributes(p, &ty, attr_buf_top);

        const any_fields_have_attrs = p.field_attr_buf.items.len > p.record.field_attr_start;

        if (any_fields_have_attrs) {
            try p.field_attr_buf.append(to_append);
        } else {
            if (to_append.len > 0) {
                const preceding = p.record_members.items.len - p.record.start;
                if (preceding > 0) {
                    try p.field_attr_buf.appendNTimes(&.{}, preceding);
                }
                try p.field_attr_buf.append(to_append);
            }
        }

        if (name_tok == 0 and bits == null) unnamed: {
            if (ty.is(.@"enum") or ty.hasIncompleteSize()) break :unnamed;
            if (ty.isAnonymousRecord(p.comp)) {
                // An anonymous record appears as indirect fields on the parent
                try p.record_buf.append(.{
                    .name = try p.getAnonymousName(first_tok),
                    .ty = ty,
                });

                const node = try p.addNode(.{
                    .record_field = .{
                        .name_or_first_tok = name_tok,
                        .type = ty,
                        .bit_width = null,
                    },
                });
                try p.decl_buf.append(node);
                try p.record.addFieldsFromAnonymous(p, ty);
                break; // must be followed by a semicolon
            }
            try p.err(.missing_declaration);
        } else {
            const interned_name = if (name_tok != 0) try StrInt.intern(p.comp, p.tokSlice(name_tok)) else try p.getAnonymousName(first_tok);
            try p.record_buf.append(.{
                .name = interned_name,
                .ty = ty,
                .name_tok = name_tok,
                .bit_width = bits,
            });
            if (name_tok != 0) try p.record.addField(p, interned_name, name_tok);
            const node = try p.addNode(.{
                .record_field = .{
                    .name_or_first_tok = name_tok,
                    .type = ty,
                    .bit_width = bits_node,
                },
            });
            try p.decl_buf.append(node);
        }

        if (ty.isFunc()) {
            try p.errTok(.func_field, first_tok);
        } else if (ty.is(.variable_len_array)) {
            try p.errTok(.vla_field, first_tok);
        } else if (ty.is(.incomplete_array)) {
            if (p.record.kind == .keyword_union) {
                try p.errTok(.flexible_in_union, first_tok);
            }
            if (p.record.flexible_field) |some| {
                if (p.record.kind == .keyword_struct) {
                    try p.errTok(.flexible_non_final, some);
                }
            }
            p.record.flexible_field = first_tok;
        } else if (ty.specifier != .invalid and ty.hasIncompleteSize()) {
            try p.errStr(.field_incomplete_ty, first_tok, try p.typeStr(ty));
        } else if (p.record.flexible_field) |some| {
            if (some != first_tok and p.record.kind == .keyword_struct) try p.errTok(.flexible_non_final, some);
        }
        if (p.eatToken(.comma) == null) break;
    }

    if (p.eatToken(.semicolon) == null) {
        const tok_id = p.tok_ids[p.tok_i];
        if (tok_id == .r_brace) {
            try p.err(.missing_semicolon);
        } else {
            return p.errExpectedToken(.semicolon, tok_id);
        }
    }

    return true;
}

/// specQual : (typeSpec | typeQual | alignSpec)+
fn specQual(p: *Parser) Error!?Type {
    var spec: Type.Builder = .{};
    if (try p.typeSpec(&spec)) {
        return try spec.finish(p);
    }
    return null;
}

/// enumSpec
///  : keyword_enum IDENTIFIER? (: typeName)? { enumerator (',' enumerator)? ',') }
///  | keyword_enum IDENTIFIER (: typeName)?
fn enumSpec(p: *Parser) Error!Type {
    const enum_tok = p.tok_i;
    p.tok_i += 1;
    const attr_buf_top = p.attr_buf.len;
    defer p.attr_buf.len = attr_buf_top;
    try p.attributeSpecifier();

    const maybe_ident = try p.eatIdentifier();
    const fixed_ty = if (p.eatToken(.colon)) |colon| fixed: {
        const ty_start = p.tok_i;
        const fixed = (try p.specQual()) orelse {
            if (p.record.kind != .invalid) {
                // This is a bit field.
                p.tok_i -= 1;
                break :fixed null;
            }
            try p.err(.expected_type);
            try p.errTok(.enum_fixed, colon);
            break :fixed null;
        };

        if (!fixed.isInt() or fixed.is(.@"enum")) {
            try p.errStr(.invalid_type_underlying_enum, ty_start, try p.typeStr(fixed));
            break :fixed Type.int;
        }

        try p.errTok(.enum_fixed, colon);
        break :fixed fixed;
    } else null;

    const l_brace = p.eatToken(.l_brace) orelse {
        const ident = maybe_ident orelse {
            try p.err(.ident_or_l_brace);
            return error.ParsingFailed;
        };
        // check if this is a reference to a previous type
        const interned_name = try StrInt.intern(p.comp, p.tokSlice(ident));
        if (try p.syms.findTag(p, interned_name, .keyword_enum, ident, p.tok_ids[p.tok_i])) |prev| {
            // only check fixed underlying type in forward declarations and not in references.
            if (p.tok_ids[p.tok_i] == .semicolon)
                try p.checkEnumFixedTy(fixed_ty, ident, prev);
            return prev.ty;
        } else {
            // this is a forward declaration, create a new enum Type.
            const enum_ty = try Type.Enum.create(p.arena, interned_name, fixed_ty);
            const ty = try Attribute.applyTypeAttributes(p, .{
                .specifier = .@"enum",
                .data = .{ .@"enum" = enum_ty },
            }, attr_buf_top, null);
            try p.syms.define(p.gpa, .{
                .kind = .@"enum",
                .name = interned_name,
                .tok = ident,
                .ty = ty,
                .val = .{},
            });

            try p.decl_buf.append(try p.addNode(.{ .enum_forward_decl = .{
                .name_or_kind_tok = ident,
                .container_type = ty,
                .definition = null,
            } }));
            return ty;
        }
    };

    var done = false;
    errdefer if (!done) p.skipTo(.r_brace);

    // Get forward declared type or create a new one
    var defined = false;
    const enum_ty: *Type.Enum = if (maybe_ident) |ident| enum_ty: {
        const ident_str = p.tokSlice(ident);
        const interned_name = try StrInt.intern(p.comp, ident_str);
        if (try p.syms.defineTag(p, interned_name, .keyword_enum, ident)) |prev| {
            const enum_ty = prev.ty.get(.@"enum").?.data.@"enum";
            if (!enum_ty.isIncomplete() and !enum_ty.fixed) {
                // if the enum isn't incomplete, this is a redefinition
                try p.errStr(.redefinition, ident, ident_str);
                try p.errTok(.previous_definition, prev.tok);
            } else {
                try p.checkEnumFixedTy(fixed_ty, ident, prev);
                defined = true;
                break :enum_ty enum_ty;
            }
        }
        break :enum_ty try Type.Enum.create(p.arena, interned_name, fixed_ty);
    } else try Type.Enum.create(p.arena, try p.getAnonymousName(enum_tok), fixed_ty);

    // reserve space for this enum
    try p.decl_buf.append(undefined);
    const decl_buf_top = p.decl_buf.items.len;
    const list_buf_top = p.list_buf.items.len;
    const enum_buf_top = p.enum_buf.items.len;
    errdefer p.decl_buf.items.len = decl_buf_top - 1;
    defer {
        p.decl_buf.items.len = decl_buf_top;
        p.list_buf.items.len = list_buf_top;
        p.enum_buf.items.len = enum_buf_top;
    }

    var e = Enumerator.init(fixed_ty);
    while (try p.enumerator(&e)) |field_and_node| {
        try p.enum_buf.append(field_and_node.field);
        try p.list_buf.append(field_and_node.node);
        if (p.eatToken(.comma) == null) break;
    }

    if (p.enum_buf.items.len == enum_buf_top) try p.err(.empty_enum);
    try p.expectClosing(l_brace, .r_brace);
    done = true;
    try p.attributeSpecifier();

    const ty = try Attribute.applyTypeAttributes(p, .{
        .specifier = .@"enum",
        .data = .{ .@"enum" = enum_ty },
    }, attr_buf_top, null);
    if (!enum_ty.fixed) {
        const tag_specifier = try e.getTypeSpecifier(p, ty.enumIsPacked(p.comp), maybe_ident orelse enum_tok);
        enum_ty.tag_ty = .{ .specifier = tag_specifier };
    }

    const enum_fields = p.enum_buf.items[enum_buf_top..];
    const field_nodes = p.list_buf.items[list_buf_top..];

    if (fixed_ty == null) {
        for (enum_fields, field_nodes) |*field, field_node| {
            if (field.ty.eql(Type.int, p.comp, false)) continue;

            const sym = p.syms.get(field.name, .vars) orelse continue;
            if (sym.kind != .enumeration) continue; // already an error

            var res: Result = .{ .node = undefined, .ty = field.ty, .val = sym.val };
            const dest_ty = if (p.comp.fixedEnumTagSpecifier()) |some|
                Type{ .specifier = some }
            else if (try res.intFitsInType(p, Type.int))
                Type.int
            else if (!res.ty.eql(enum_ty.tag_ty, p.comp, false))
                enum_ty.tag_ty
            else
                continue;

            const symbol = p.syms.getPtr(field.name, .vars);
            _ = try symbol.val.intCast(dest_ty, p.comp);

            symbol.ty = dest_ty;
            field.ty = dest_ty;
            res.ty = dest_ty;

            // Create a new enum_field node with the correct type.
            var new_field_node = field_node.get(&p.tree);
            new_field_node.enum_field.type = dest_ty;

            if (field.init.unpack()) |some| {
                res.node = some;
                try res.implicitCast(p, .int_cast, some.tok(&p.tree));
                field.init = .pack(res.node);
                new_field_node.enum_field.init = res.node;
            }

            try p.tree.addNodeExtra(new_field_node, @intFromEnum(field_node));
        }
    }

    enum_ty.fields = try p.arena.dupe(Type.Enum.Field, enum_fields);

    // declare a symbol for the type
    if (maybe_ident != null and !defined) {
        try p.syms.define(p.gpa, .{
            .kind = .@"enum",
            .name = enum_ty.name,
            .ty = ty,
            .tok = maybe_ident.?,
            .val = .{},
        });
    }

    // finish by creating a node
    const node = try p.addNode(.{ .enum_decl = .{
        .name_or_kind_tok = maybe_ident orelse enum_tok,
        .container_type = ty,
        .fields = field_nodes,
    } });
    p.decl_buf.items[decl_buf_top - 1] = node;
    if (p.func.ty == null) {
        _ = p.tentative_defs.remove(enum_ty.name);
    }
    return ty;
}

fn checkEnumFixedTy(p: *Parser, fixed_ty: ?Type, ident_tok: TokenIndex, prev: Symbol) !void {
    const enum_ty = prev.ty.get(.@"enum").?.data.@"enum";
    if (fixed_ty) |some| {
        if (!enum_ty.fixed) {
            try p.errTok(.enum_prev_nonfixed, ident_tok);
            try p.errTok(.previous_definition, prev.tok);
            return error.ParsingFailed;
        }

        if (!enum_ty.tag_ty.eql(some, p.comp, false)) {
            const str = try p.typePairStrExtra(some, " (was ", enum_ty.tag_ty);
            try p.errStr(.enum_different_explicit_ty, ident_tok, str);
            try p.errTok(.previous_definition, prev.tok);
            return error.ParsingFailed;
        }
    } else if (enum_ty.fixed) {
        try p.errTok(.enum_prev_fixed, ident_tok);
        try p.errTok(.previous_definition, prev.tok);
        return error.ParsingFailed;
    }
}

const Enumerator = struct {
    val: Value = .{},
    ty: Type,
    num_positive_bits: usize = 0,
    num_negative_bits: usize = 0,
    fixed: bool,

    fn init(fixed_ty: ?Type) Enumerator {
        return .{
            .ty = fixed_ty orelse Type.int,
            .fixed = fixed_ty != null,
        };
    }

    /// Increment enumerator value adjusting type if needed.
    fn incr(e: *Enumerator, p: *Parser, tok: TokenIndex) !void {
        const old_val = e.val;
        if (old_val.opt_ref == .none) {
            // First enumerator, set to 0 fits in all types.
            e.val = Value.zero;
            return;
        }
        if (try e.val.add(e.val, Value.one, e.ty, p.comp)) {
            if (e.fixed) {
                try p.errStr(.enum_not_representable_fixed, tok, try p.typeStr(e.ty));
                return;
            }
            const new_ty = if (p.comp.nextLargestIntSameSign(e.ty)) |larger| blk: {
                try p.errTok(.enumerator_overflow, tok);
                break :blk larger;
            } else blk: {
                const signed = !e.ty.isUnsignedInt(p.comp);
                const bit_size: u8 = @intCast(e.ty.bitSizeof(p.comp).? - @intFromBool(signed));
                try p.errExtra(.enum_not_representable, tok, .{ .pow_2_as_string = bit_size });
                break :blk Type{ .specifier = .ulong_long };
            };
            e.ty = new_ty;
            _ = try e.val.add(old_val, Value.one, e.ty, p.comp);
        }
    }

    /// Set enumerator value to specified value.
    fn set(e: *Enumerator, p: *Parser, res: *Result, tok: TokenIndex) !void {
        if (res.ty.specifier == .invalid) return;
        if (e.fixed and !res.ty.eql(e.ty, p.comp, false)) {
            if (!try res.intFitsInType(p, e.ty)) {
                try p.errStr(.enum_not_representable_fixed, tok, try p.typeStr(e.ty));
                return error.ParsingFailed;
            }
            res.ty = e.ty;
            try res.implicitCast(p, .int_cast, tok);
            e.val = res.val;
        } else {
            try res.intCast(p, res.ty.integerPromotion(p.comp), tok);
            e.ty = res.ty;
            e.val = res.val;
        }
    }

    fn getTypeSpecifier(e: *const Enumerator, p: *Parser, is_packed: bool, tok: TokenIndex) !Type.Specifier {
        if (p.comp.fixedEnumTagSpecifier()) |tag_specifier| return tag_specifier;

        const char_width = (Type{ .specifier = .schar }).sizeof(p.comp).? * 8;
        const short_width = (Type{ .specifier = .short }).sizeof(p.comp).? * 8;
        const int_width = (Type{ .specifier = .int }).sizeof(p.comp).? * 8;
        if (e.num_negative_bits > 0) {
            if (is_packed and e.num_negative_bits <= char_width and e.num_positive_bits < char_width) {
                return .schar;
            } else if (is_packed and e.num_negative_bits <= short_width and e.num_positive_bits < short_width) {
                return .short;
            } else if (e.num_negative_bits <= int_width and e.num_positive_bits < int_width) {
                return .int;
            }
            const long_width = (Type{ .specifier = .long }).sizeof(p.comp).? * 8;
            if (e.num_negative_bits <= long_width and e.num_positive_bits < long_width) {
                return .long;
            }
            const long_long_width = (Type{ .specifier = .long_long }).sizeof(p.comp).? * 8;
            if (e.num_negative_bits > long_long_width or e.num_positive_bits >= long_long_width) {
                try p.errTok(.enum_too_large, tok);
            }
            return .long_long;
        }
        if (is_packed and e.num_positive_bits <= char_width) {
            return .uchar;
        } else if (is_packed and e.num_positive_bits <= short_width) {
            return .ushort;
        } else if (e.num_positive_bits <= int_width) {
            return .uint;
        } else if (e.num_positive_bits <= (Type{ .specifier = .long }).sizeof(p.comp).? * 8) {
            return .ulong;
        }
        return .ulong_long;
    }

    fn str(e: *const Enumerator, p: *Parser) ![]const u8 {
        return (Result{
            .node = undefined, // Result.str does not use the node
            .ty = e.ty,
            .val = e.val,
        }).str(p);
    }
};

const EnumFieldAndNode = struct { field: Type.Enum.Field, node: Node.Index };

/// enumerator : IDENTIFIER ('=' integerConstExpr)
fn enumerator(p: *Parser, e: *Enumerator) Error!?EnumFieldAndNode {
    _ = try p.pragma();
    const name_tok = (try p.eatIdentifier()) orelse {
        if (p.tok_ids[p.tok_i] == .r_brace) return null;
        try p.err(.expected_identifier);
        p.skipTo(.r_brace);
        return error.ParsingFailed;
    };
    const attr_buf_top = p.attr_buf.len;
    defer p.attr_buf.len = attr_buf_top;
    try p.attributeSpecifier();

    const err_start = p.comp.diagnostics.list.items.len;
    const field_init = if (p.eatToken(.equal)) |_| blk: {
        var specified = try p.integerConstExpr(.gnu_folding_extension);
        if (specified.val.opt_ref == .none) {
            try p.errTok(.enum_val_unavailable, name_tok + 2);
            try e.incr(p, name_tok);
            break :blk null;
        } else {
            try e.set(p, &specified, name_tok);
            break :blk specified.node;
        }
    } else blk: {
        try e.incr(p, name_tok);
        break :blk null;
    };

    const attr_ty = try Attribute.applyEnumeratorAttributes(p, e.ty, attr_buf_top);

    if (attr_ty.isUnsignedInt(p.comp) or e.val.compare(.gte, Value.zero, p.comp)) {
        e.num_positive_bits = @max(e.num_positive_bits, e.val.minUnsignedBits(p.comp));
    } else {
        e.num_negative_bits = @max(e.num_negative_bits, e.val.minSignedBits(p.comp));
    }

    if (err_start == p.comp.diagnostics.list.items.len) {
        // only do these warnings if we didn't already warn about overflow or non-representable values
        if (e.val.compare(.lt, Value.zero, p.comp)) {
            const min_val = try Value.minInt(Type.int, p.comp);
            if (e.val.compare(.lt, min_val, p.comp)) {
                try p.errStr(.enumerator_too_small, name_tok, try e.str(p));
            }
        } else {
            const max_val = try Value.maxInt(Type.int, p.comp);
            if (e.val.compare(.gt, max_val, p.comp)) {
                try p.errStr(.enumerator_too_large, name_tok, try e.str(p));
            }
        }
    }

    const interned_name = try StrInt.intern(p.comp, p.tokSlice(name_tok));
    try p.syms.defineEnumeration(p, interned_name, attr_ty, name_tok, e.val);

    const node = try p.addNode(.{
        .enum_field = .{
            .name_tok = name_tok,
            .type = attr_ty,
            .init = field_init,
        },
    });
    try p.tree.value_map.put(p.gpa, node, e.val);
    return .{ .field = .{
        .name = interned_name,
        .ty = attr_ty,
        .name_tok = name_tok,
        .init = .packOpt(field_init),
    }, .node = node };
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
    if (base_type.is(.auto_type) and !d.ty.is(.auto_type)) {
        try p.errTok(.auto_type_requires_plain_declarator, start);
        return error.ParsingFailed;
    }

    const maybe_ident = p.tok_i;
    if (kind != .abstract and (try p.eatIdentifier()) != null) {
        d.name = maybe_ident;
        const combine_tok = p.tok_i;
        d.ty = try p.directDeclarator(d.ty, &d, kind);
        try d.ty.validateCombinedType(p, combine_tok);
        return d;
    } else if (p.eatToken(.l_paren)) |l_paren| blk: {
        var res = (try p.declarator(.{ .specifier = .void }, kind)) orelse {
            p.tok_i = l_paren;
            break :blk;
        };
        try p.expectClosing(l_paren, .r_paren);
        const suffix_start = p.tok_i;
        const outer = try p.directDeclarator(d.ty, &d, kind);
        try res.ty.combine(outer);
        try res.ty.validateCombinedType(p, suffix_start);
        res.old_style_func = d.old_style_func;
        if (d.func_declarator) |some| res.func_declarator = some;
        return res;
    }

    const expected_ident = p.tok_i;

    d.ty = try p.directDeclarator(d.ty, &d, kind);

    if (kind == .normal and !d.ty.isEnumOrRecord()) {
        try p.errTok(.expected_ident_or_l_paren, expected_ident);
        return error.ParsingFailed;
    }
    try d.ty.validateCombinedType(p, expected_ident);
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
        if (p.tok_ids[p.tok_i] == .l_bracket) {
            switch (kind) {
                .normal, .record => if (p.comp.langopts.standard.atLeast(.c23)) {
                    p.tok_i -= 1;
                    return base_type;
                },
                .param, .abstract => {},
            }
            try p.err(.expected_expr);
            return error.ParsingFailed;
        }
        var res_ty = Type{
            // so that we can get any restrict type that might be present
            .specifier = .pointer,
        };
        var quals = Type.Qualifiers.Builder{};

        var got_quals = try p.typeQual(&quals);
        var static = p.eatToken(.keyword_static);
        if (static != null and !got_quals) got_quals = try p.typeQual(&quals);
        var star = p.eatToken(.asterisk);
        const size_tok = p.tok_i;

        const const_decl_folding = p.const_decl_folding;
        p.const_decl_folding = .gnu_vla_folding_extension;
        const opt_size = if (star) |_| null else try p.assignExpr();
        p.const_decl_folding = const_decl_folding;

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
        if (static) |_| _ = try p.expectResult(opt_size);

        if (base_type.is(.auto_type)) {
            try p.errStr(.array_of_auto_type, d.name, p.tokSlice(d.name));
            return error.ParsingFailed;
        }

        const outer = try p.directDeclarator(base_type, d, kind);

        if (opt_size != null and !opt_size.?.ty.isInt()) {
            try p.errStr(.array_size_non_int, size_tok, try p.typeStr(opt_size.?.ty));
            return error.ParsingFailed;
        }
        if (base_type.is(.c23_auto) or outer.is(.invalid)) {
            // issue error later
            return Type.invalid;
        }

        if (opt_size) |size| {
            if (size.val.opt_ref == .none) {
                try p.errTok(.vla, size_tok);
                if (p.func.ty == null and kind != .param and p.record.kind == .invalid) {
                    try p.errTok(.variable_len_array_file_scope, d.name);
                }
                const expr_ty = try p.arena.create(Type.Expr);
                expr_ty.ty = .{ .specifier = .void };
                expr_ty.node = size.node;
                res_ty.data = .{ .expr = expr_ty };
                res_ty.specifier = .variable_len_array;

                if (static) |some| try p.errTok(.useless_static, some);
            } else {
                // `outer` is validated later so it may be invalid here
                const outer_size = outer.sizeof(p.comp);
                const max_elems = p.comp.maxArrayBytes() / @max(1, outer_size orelse 1);

                if (size.val.isZero(p.comp)) {
                    try p.errTok(.zero_length_array, l_bracket);
                } else if (size.val.compare(.lt, Value.zero, p.comp)) {
                    try p.errTok(.negative_array_size, l_bracket);
                    return error.ParsingFailed;
                }
                const arr_ty = try p.arena.create(Type.Array);
                arr_ty.elem = .{ .specifier = .void };
                arr_ty.len = size.val.toInt(u64, p.comp) orelse std.math.maxInt(u64);
                if (arr_ty.len > max_elems) {
                    try p.errTok(.array_too_large, l_bracket);
                    arr_ty.len = max_elems;
                }
                res_ty.data = .{ .array = arr_ty };
                res_ty.specifier = if (static != null) .static_array else .array;
            }
        } else if (star) |_| {
            const elem_ty = try p.arena.create(Type);
            elem_ty.* = .{ .specifier = .void };
            res_ty.data = .{ .sub_type = elem_ty };
            res_ty.specifier = .unspecified_variable_len_array;
        } else {
            const arr_ty = try p.arena.create(Type.Array);
            arr_ty.* = .{
                .elem = .{ .specifier = .void },
                .len = 0,
            };
            res_ty.data = .{ .array = arr_ty };
            res_ty.specifier = .incomplete_array;
        }

        try res_ty.combine(outer);
        return res_ty;
    } else if (p.eatToken(.l_paren)) |l_paren| {
        d.func_declarator = l_paren;

        const func_ty = try p.arena.create(Type.Func);
        func_ty.params = &.{};
        func_ty.return_type.specifier = .void;
        var specifier: Type.Specifier = .func;

        if (p.eatToken(.ellipsis)) |_| {
            try p.err(.param_before_var_args);
            try p.expectClosing(l_paren, .r_paren);
            var res_ty = Type{ .specifier = .func, .data = .{ .func = func_ty } };

            const outer = try p.directDeclarator(base_type, d, kind);
            try res_ty.combine(outer);
            return res_ty;
        }

        if (try p.paramDecls(d)) |params| {
            func_ty.params = params;
            if (p.eatToken(.ellipsis)) |_| specifier = .var_args_func;
        } else if (p.tok_ids[p.tok_i] == .r_paren) {
            specifier = if (p.comp.langopts.standard.atLeast(.c23))
                .func
            else
                .old_style_func;
        } else if (p.tok_ids[p.tok_i] == .identifier or p.tok_ids[p.tok_i] == .extended_identifier) {
            d.old_style_func = p.tok_i;
            const param_buf_top = p.param_buf.items.len;
            try p.syms.pushScope(p);
            defer {
                p.param_buf.items.len = param_buf_top;
                p.syms.popScope();
            }

            specifier = .old_style_func;
            while (true) {
                const name_tok = try p.expectIdentifier();
                const interned_name = try StrInt.intern(p.comp, p.tokSlice(name_tok));
                try p.syms.defineParam(p, interned_name, undefined, name_tok);
                try p.param_buf.append(.{
                    .name = interned_name,
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
        try res_ty.combine(outer);
        return res_ty;
    } else return base_type;
}

/// pointer : '*' typeQual* pointer?
fn pointer(p: *Parser, base_ty: Type) Error!Type {
    var ty = base_ty;
    while (p.eatToken(.asterisk)) |_| {
        if (!ty.is(.invalid)) {
            const elem_ty = try p.arena.create(Type);
            elem_ty.* = ty;
            ty = Type{
                .specifier = .pointer,
                .data = .{ .sub_type = elem_ty },
            };
        }
        var quals = Type.Qualifiers.Builder{};
        _ = try p.typeQual(&quals);
        try quals.finish(p, &ty);
    }
    return ty;
}

/// paramDecls : paramDecl (',' paramDecl)* (',' '...')
/// paramDecl : declSpec (declarator | abstractDeclarator)
fn paramDecls(p: *Parser, d: *Declarator) Error!?[]Type.Func.Param {
    // TODO warn about visibility of types declared here
    const param_buf_top = p.param_buf.items.len;
    defer p.param_buf.items.len = param_buf_top;
    try p.syms.pushScope(p);
    defer p.syms.popScope();

    while (true) {
        const attr_buf_top = p.attr_buf.len;
        defer p.attr_buf.len = attr_buf_top;
        const param_decl_spec = if (try p.declSpec()) |some|
            some
        else if (p.comp.langopts.standard.atLeast(.c23) and
            (p.tok_ids[p.tok_i] == .identifier or p.tok_ids[p.tok_i] == .extended_identifier))
        {
            // handle deprecated K&R style parameters
            const identifier = try p.expectIdentifier();
            try p.errStr(.unknown_type_name, identifier, p.tokSlice(identifier));
            if (d.old_style_func == null) d.old_style_func = identifier;

            try p.param_buf.append(.{
                .name = try StrInt.intern(p.comp, p.tokSlice(identifier)),
                .name_tok = identifier,
                .ty = .{ .specifier = .int },
            });

            if (p.eatToken(.comma) == null) break;
            if (p.tok_ids[p.tok_i] == .ellipsis) break;
            continue;
        } else if (p.param_buf.items.len == param_buf_top) {
            return null;
        } else blk: {
            var spec: Type.Builder = .{};
            break :blk DeclSpec{ .ty = try spec.finish(p) };
        };

        var name_tok: TokenIndex = 0;
        const first_tok = p.tok_i;
        var param_ty = param_decl_spec.ty;
        if (try p.declarator(param_decl_spec.ty, .param)) |some| {
            if (some.old_style_func) |tok_i| try p.errTok(.invalid_old_style_params, tok_i);
            try p.attributeSpecifier();

            name_tok = some.name;
            param_ty = some.ty;
            if (some.name != 0) {
                const interned_name = try StrInt.intern(p.comp, p.tokSlice(name_tok));
                try p.syms.defineParam(p, interned_name, param_ty, name_tok);
            }
        }
        param_ty = try Attribute.applyParameterAttributes(p, param_ty, attr_buf_top, .alignas_on_param);

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
            .name = if (name_tok == 0) .empty else try StrInt.intern(p.comp, p.tokSlice(name_tok)),
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
    const attr_buf_top = p.attr_buf.len;
    defer p.attr_buf.len = attr_buf_top;
    const ty = (try p.specQual()) orelse return null;
    if (try p.declarator(ty, .abstract)) |some| {
        if (some.old_style_func) |tok_i| try p.errTok(.invalid_old_style_params, tok_i);
        return try Attribute.applyTypeAttributes(p, some.ty, attr_buf_top, .align_ignored);
    }
    return try Attribute.applyTypeAttributes(p, ty, attr_buf_top, .align_ignored);
}

fn complexInitializer(p: *Parser, init_ty: Type) Error!Result {
    assert(p.tok_ids[p.tok_i] == .l_brace);
    assert(init_ty.isComplex());

    const real_ty = init_ty.makeReal();
    if (real_ty.isInt()) {
        return p.todo("Complex integer initializers");
    }
    const l_brace = p.tok_i;
    p.tok_i += 1;
    try p.errTok(.complex_component_init, l_brace);

    const first_tok = p.tok_i;
    var first = try p.expect(assignExpr);
    try p.coerceInit(&first, first_tok, real_ty);

    const second = if (p.eatToken(.comma)) |_| second: {
        const second_tok = p.tok_i;
        var second = (try p.assignExpr()) orelse break :second null;
        try p.coerceInit(&second, second_tok, real_ty);
        break :second second;
    } else null;

    // Eat excess initializers
    var extra_tok: ?TokenIndex = null;
    while (p.eatToken(.comma)) |_| {
        if (p.tok_ids[p.tok_i] == .r_brace) break;
        extra_tok = p.tok_i;
        if ((try p.assignExpr()) == null) {
            try p.errTok(.expected_expr, p.tok_i);
            p.skipTo(.r_brace);
            return error.ParsingFailed;
        }
    }
    try p.expectClosing(l_brace, .r_brace);
    if (extra_tok) |tok| {
        try p.errTok(.excess_scalar_init, tok);
    }

    var res: Result = .{
        .node = try p.addNode(.{ .array_init_expr = .{
            .container_type = init_ty,
            .items = if (second) |some|
                &.{ first.node, some.node }
            else
                &.{first.node},
            .l_brace_tok = l_brace,
        } }),
        .ty = init_ty,
    };

    const first_val = p.tree.value_map.get(first.node) orelse return res;
    const second_val = if (second) |some| p.tree.value_map.get(some.node) orelse return res else Value.zero;
    res.val = try Value.intern(p.comp, switch (real_ty.bitSizeof(p.comp).?) {
        32 => .{ .complex = .{ .cf32 = .{ first_val.toFloat(f32, p.comp), second_val.toFloat(f32, p.comp) } } },
        64 => .{ .complex = .{ .cf64 = .{ first_val.toFloat(f64, p.comp), second_val.toFloat(f64, p.comp) } } },
        80 => .{ .complex = .{ .cf80 = .{ first_val.toFloat(f80, p.comp), second_val.toFloat(f80, p.comp) } } },
        128 => .{ .complex = .{ .cf128 = .{ first_val.toFloat(f128, p.comp), second_val.toFloat(f128, p.comp) } } },
        else => unreachable,
    });
    try res.putValue(p);
    return res;
}

/// initializer
///  : assignExpr
///  | '{' initializerItems '}'
fn initializer(p: *Parser, init_ty: Type) Error!Result {
    // fast path for non-braced initializers
    if (p.tok_ids[p.tok_i] != .l_brace) {
        const tok = p.tok_i;
        var res = try p.expect(assignExpr);
        if (try p.coerceArrayInit(&res, tok, init_ty)) return res;
        try p.coerceInit(&res, tok, init_ty);
        return res;
    }
    if (init_ty.is(.auto_type)) {
        try p.err(.auto_type_with_init_list);
        return error.ParsingFailed;
    }

    if (init_ty.isComplex()) {
        return p.complexInitializer(init_ty);
    }
    var il: InitList = .{};
    defer il.deinit(p.gpa);

    _ = try p.initializerItem(&il, init_ty);

    const res = try p.convertInitList(il, init_ty);
    var res_ty = res.type(&p.tree);
    res_ty.qual = init_ty.qual;
    return .{ .ty = res_ty, .node = res };
}

/// initializerItems : designation? initializer (',' designation? initializer)* ','?
/// designation : designator+ '='
/// designator
///  : '[' integerConstExpr ']'
///  | '.' identifier
fn initializerItem(p: *Parser, il: *InitList, init_ty: Type) Error!bool {
    const l_brace = p.eatToken(.l_brace) orelse {
        const tok = p.tok_i;
        var res = (try p.assignExpr()) orelse return false;

        const arr = try p.coerceArrayInit(&res, tok, init_ty);
        if (!arr) try p.coerceInit(&res, tok, init_ty);
        if (il.tok != 0) {
            try p.errTok(.initializer_overrides, tok);
            try p.errTok(.previous_initializer, il.tok);
        }
        il.node = .pack(res.node);
        il.tok = tok;
        return true;
    };

    const is_scalar = init_ty.isScalar();
    const is_complex = init_ty.isComplex();
    const scalar_inits_needed: usize = if (is_complex) 2 else 1;
    if (p.eatToken(.r_brace)) |_| {
        if (is_scalar) try p.errTok(.empty_scalar_init, l_brace);
        if (il.tok != 0) {
            try p.errTok(.initializer_overrides, l_brace);
            try p.errTok(.previous_initializer, il.tok);
        }
        il.node = .null;
        il.tok = l_brace;
        return true;
    }

    var count: u64 = 0;
    var warned_excess = false;
    var is_str_init = false;
    var index_hint: ?u64 = null;
    while (true) : (count += 1) {
        errdefer p.skipTo(.r_brace);

        var first_tok = p.tok_i;
        var cur_ty = init_ty;
        var cur_il = il;
        var designation = false;
        var cur_index_hint: ?u64 = null;
        while (true) {
            if (p.eatToken(.l_bracket)) |l_bracket| {
                if (!cur_ty.isArray()) {
                    try p.errStr(.invalid_array_designator, l_bracket, try p.typeStr(cur_ty));
                    return error.ParsingFailed;
                }
                const expr_tok = p.tok_i;
                const index_res = try p.integerConstExpr(.gnu_folding_extension);
                try p.expectClosing(l_bracket, .r_bracket);

                if (index_res.val.opt_ref == .none) {
                    try p.errTok(.expected_integer_constant_expr, expr_tok);
                    return error.ParsingFailed;
                } else if (index_res.val.compare(.lt, Value.zero, p.comp)) {
                    try p.errStr(.negative_array_designator, l_bracket + 1, try index_res.str(p));
                    return error.ParsingFailed;
                }

                const max_len = cur_ty.arrayLen() orelse std.math.maxInt(usize);
                const index_int = index_res.val.toInt(u64, p.comp) orelse std.math.maxInt(u64);
                if (index_int >= max_len) {
                    try p.errStr(.oob_array_designator, l_bracket + 1, try index_res.str(p));
                    return error.ParsingFailed;
                }
                cur_index_hint = cur_index_hint orelse index_int;

                cur_il = try cur_il.find(p.gpa, index_int);
                cur_ty = cur_ty.elemType();
                designation = true;
            } else if (p.eatToken(.period)) |period| {
                const field_tok = try p.expectIdentifier();
                const field_str = p.tokSlice(field_tok);
                const field_name = try StrInt.intern(p.comp, field_str);
                cur_ty = cur_ty.canonicalize(.standard);
                if (!cur_ty.isRecord()) {
                    try p.errStr(.invalid_field_designator, period, try p.typeStr(cur_ty));
                    return error.ParsingFailed;
                } else if (!cur_ty.hasField(field_name)) {
                    try p.errStr(.no_such_field_designator, period, field_str);
                    return error.ParsingFailed;
                }

                // TODO check if union already has field set
                outer: while (true) {
                    for (cur_ty.data.record.fields, 0..) |f, i| {
                        if (f.isAnonymousRecord()) {
                            // Recurse into anonymous field if it has a field by the name.
                            if (!f.ty.hasField(field_name)) continue;
                            cur_ty = f.ty.canonicalize(.standard);
                            cur_il = try il.find(p.gpa, i);
                            cur_index_hint = cur_index_hint orelse i;
                            continue :outer;
                        }
                        if (field_name == f.name) {
                            cur_il = try cur_il.find(p.gpa, i);
                            cur_ty = f.ty;
                            cur_index_hint = cur_index_hint orelse i;
                            break :outer;
                        }
                    }
                    unreachable; // we already checked that the starting type has this field
                }
                designation = true;
            } else break;
        }
        if (designation) index_hint = null;
        defer index_hint = cur_index_hint orelse null;

        if (designation) _ = try p.expectToken(.equal);

        if (!designation and cur_ty.hasAttribute(.designated_init)) {
            try p.err(.designated_init_needed);
        }

        var saw = false;
        if (is_str_init and p.isStringInit(init_ty)) {
            // discard further strings
            var tmp_il: InitList = .{};
            defer tmp_il.deinit(p.gpa);
            saw = try p.initializerItem(&tmp_il, .{ .specifier = .void });
        } else if (count == 0 and p.isStringInit(init_ty)) {
            is_str_init = true;
            saw = try p.initializerItem(il, init_ty);
        } else if (is_scalar and count >= scalar_inits_needed) {
            // discard further scalars
            var tmp_il: InitList = .{};
            defer tmp_il.deinit(p.gpa);
            saw = try p.initializerItem(&tmp_il, .{ .specifier = .void });
        } else if (p.tok_ids[p.tok_i] == .l_brace) {
            if (designation) {
                // designation overrides previous value, let existing mechanism handle it
                saw = try p.initializerItem(cur_il, cur_ty);
            } else if (try p.findAggregateInitializer(&cur_il, &cur_ty, &index_hint)) {
                saw = try p.initializerItem(cur_il, cur_ty);
            } else {
                // discard further values
                var tmp_il: InitList = .{};
                defer tmp_il.deinit(p.gpa);
                saw = try p.initializerItem(&tmp_il, .{ .specifier = .void });
                if (!warned_excess) try p.errTok(if (init_ty.isArray()) .excess_array_init else .excess_struct_init, first_tok);
                warned_excess = true;
            }
        } else single_item: {
            first_tok = p.tok_i;
            var res = (try p.assignExpr()) orelse {
                saw = false;
                break :single_item;
            };
            saw = true;

            excess: {
                if (index_hint) |*hint| {
                    if (try p.findScalarInitializerAt(&cur_il, &cur_ty, &res, first_tok, hint)) break :excess;
                } else if (try p.findScalarInitializer(&cur_il, &cur_ty, &res, first_tok)) break :excess;

                if (designation) break :excess;
                if (!warned_excess) try p.errTok(if (init_ty.isArray()) .excess_array_init else .excess_struct_init, first_tok);
                warned_excess = true;

                break :single_item;
            }

            const arr = try p.coerceArrayInit(&res, first_tok, cur_ty);
            if (!arr) try p.coerceInit(&res, first_tok, cur_ty);
            if (cur_il.tok != 0) {
                try p.errTok(.initializer_overrides, first_tok);
                try p.errTok(.previous_initializer, cur_il.tok);
            }
            cur_il.node = .pack(res.node);
            cur_il.tok = first_tok;
        }

        if (!saw) {
            if (designation) {
                try p.err(.expected_expr);
                return error.ParsingFailed;
            }
            break;
        } else if (count == 1) {
            if (is_str_init) try p.errTok(.excess_str_init, first_tok);
            if (is_scalar and !is_complex) try p.errTok(.excess_scalar_init, first_tok);
        } else if (count == 2) {
            if (is_scalar and is_complex) try p.errTok(.excess_scalar_init, first_tok);
        }

        if (p.eatToken(.comma) == null) break;
    }
    try p.expectClosing(l_brace, .r_brace);

    if (is_complex and count == 1) { // count of 1 means we saw exactly 2 items in the initializer list
        try p.errTok(.complex_component_init, l_brace);
    }
    if (is_scalar or is_str_init) return true;
    if (il.tok != 0) {
        try p.errTok(.initializer_overrides, l_brace);
        try p.errTok(.previous_initializer, il.tok);
    }
    il.node = .null;
    il.tok = l_brace;
    return true;
}

/// Returns true if the value is unused.
fn findScalarInitializerAt(p: *Parser, il: **InitList, ty: *Type, res: *Result, first_tok: TokenIndex, start_index: *u64) Error!bool {
    if (ty.isArray()) {
        if (il.*.node != .null) return false;
        start_index.* += 1;

        const arr_ty = ty.*;
        const elem_count = arr_ty.arrayLen() orelse std.math.maxInt(u64);
        if (elem_count == 0) {
            try p.errTok(.empty_aggregate_init_braces, first_tok);
            return error.ParsingFailed;
        }
        const elem_ty = arr_ty.elemType();
        const arr_il = il.*;
        if (start_index.* < elem_count) {
            ty.* = elem_ty;
            il.* = try arr_il.find(p.gpa, start_index.*);
            _ = try p.findScalarInitializer(il, ty, res, first_tok);
            return true;
        }
        return false;
    } else if (ty.get(.@"struct")) |struct_ty| {
        if (il.*.node != .null) return false;
        start_index.* += 1;

        const fields = struct_ty.data.record.fields;
        if (fields.len == 0) {
            try p.errTok(.empty_aggregate_init_braces, first_tok);
            return error.ParsingFailed;
        }
        const struct_il = il.*;
        if (start_index.* < fields.len) {
            const field = fields[@intCast(start_index.*)];
            ty.* = field.ty;
            il.* = try struct_il.find(p.gpa, start_index.*);
            _ = try p.findScalarInitializer(il, ty, res, first_tok);
            return true;
        }
        return false;
    } else if (ty.get(.@"union")) |_| {
        return false;
    }
    return il.*.node == .null;
}

/// Returns true if the value is unused.
fn findScalarInitializer(p: *Parser, il: **InitList, ty: *Type, res: *Result, first_tok: TokenIndex) Error!bool {
    const actual_ty = res.ty;
    if (ty.isArray() or ty.isComplex()) {
        if (il.*.node != .null) return false;
        if (try p.coerceArrayInitExtra(res, first_tok, ty.*, false)) return true;
        const start_index = il.*.list.items.len;
        var index = if (start_index != 0) il.*.list.items[start_index - 1].index else start_index;

        const arr_ty = ty.*;
        const elem_count: u64 = arr_ty.expectedInitListSize() orelse std.math.maxInt(u64);
        if (elem_count == 0) {
            try p.errTok(.empty_aggregate_init_braces, first_tok);
            return error.ParsingFailed;
        }
        const elem_ty = arr_ty.elemType();
        const arr_il = il.*;
        while (index < elem_count) : (index += 1) {
            ty.* = elem_ty;
            il.* = try arr_il.find(p.gpa, index);
            if (il.*.node == .null and actual_ty.eql(elem_ty, p.comp, false)) return true;
            if (try p.findScalarInitializer(il, ty, res, first_tok)) return true;
        }
        return false;
    } else if (ty.get(.@"struct")) |struct_ty| {
        if (il.*.node != .null) return false;
        if (actual_ty.eql(ty.*, p.comp, false)) return true;
        const start_index = il.*.list.items.len;
        var index = if (start_index != 0) il.*.list.items[start_index - 1].index + 1 else start_index;

        const fields = struct_ty.data.record.fields;
        if (fields.len == 0) {
            try p.errTok(.empty_aggregate_init_braces, first_tok);
            return error.ParsingFailed;
        }
        const struct_il = il.*;
        while (index < fields.len) : (index += 1) {
            const field = fields[@intCast(index)];
            ty.* = field.ty;
            il.* = try struct_il.find(p.gpa, index);
            if (il.*.node == .null and actual_ty.eql(field.ty, p.comp, false)) return true;
            if (il.*.node == .null and try p.coerceArrayInitExtra(res, first_tok, ty.*, false)) return true;
            if (try p.findScalarInitializer(il, ty, res, first_tok)) return true;
        }
        return false;
    } else if (ty.get(.@"union")) |union_ty| {
        if (il.*.node != .null) return false;
        if (actual_ty.eql(ty.*, p.comp, false)) return true;
        if (union_ty.data.record.fields.len == 0) {
            try p.errTok(.empty_aggregate_init_braces, first_tok);
            return error.ParsingFailed;
        }
        ty.* = union_ty.data.record.fields[0].ty;
        il.* = try il.*.find(p.gpa, 0);
        // if (il.*.node == null and actual_ty.eql(ty, p.comp, false)) return true;
        if (try p.coerceArrayInitExtra(res, first_tok, ty.*, false)) return true;
        if (try p.findScalarInitializer(il, ty, res, first_tok)) return true;
        return false;
    }
    return il.*.node == .null;
}

fn findAggregateInitializer(p: *Parser, il: **InitList, ty: *Type, start_index: *?u64) Error!bool {
    if (ty.isArray()) {
        if (il.*.node != .null) return false;
        const list_index = il.*.list.items.len;
        const index = if (start_index.*) |*some| blk: {
            some.* += 1;
            break :blk some.*;
        } else if (list_index != 0)
            il.*.list.items[list_index - 1].index + 1
        else
            list_index;

        const arr_ty = ty.*;
        const elem_count = arr_ty.arrayLen() orelse std.math.maxInt(u64);
        const elem_ty = arr_ty.elemType();
        if (index < elem_count) {
            ty.* = elem_ty;
            il.* = try il.*.find(p.gpa, index);
            return true;
        }
        return false;
    } else if (ty.get(.@"struct")) |struct_ty| {
        if (il.*.node != .null) return false;
        const list_index = il.*.list.items.len;
        const index = if (start_index.*) |*some| blk: {
            some.* += 1;
            break :blk some.*;
        } else if (list_index != 0)
            il.*.list.items[list_index - 1].index + 1
        else
            list_index;

        const field_count = struct_ty.data.record.fields.len;
        if (index < field_count) {
            ty.* = struct_ty.data.record.fields[@intCast(index)].ty;
            il.* = try il.*.find(p.gpa, index);
            return true;
        }
        return false;
    } else if (ty.get(.@"union")) |union_ty| {
        if (il.*.node != .null) return false;
        if (start_index.*) |_| return false; // overrides
        if (union_ty.data.record.fields.len == 0) return false;

        ty.* = union_ty.data.record.fields[0].ty;
        il.* = try il.*.find(p.gpa, 0);
        return true;
    } else {
        try p.err(.too_many_scalar_init_braces);
        return il.*.node == .null;
    }
}

fn coerceArrayInit(p: *Parser, item: *Result, tok: TokenIndex, target: Type) !bool {
    return p.coerceArrayInitExtra(item, tok, target, true);
}

fn coerceArrayInitExtra(p: *Parser, item: *Result, tok: TokenIndex, target: Type, report_err: bool) !bool {
    if (!target.isArray()) return false;

    const is_str_lit = p.nodeIs(item.node, .string_literal_expr);
    if (!is_str_lit and !p.nodeIs(item.node, .compound_literal_expr) or !item.ty.isArray()) {
        if (!report_err) return false;
        try p.errTok(.array_init_str, tok);
        return true; // do not do further coercion
    }

    const target_spec = target.elemType().canonicalize(.standard).specifier;
    const item_spec = item.ty.elemType().canonicalize(.standard).specifier;

    const compatible = target.elemType().eql(item.ty.elemType(), p.comp, false) or
        (is_str_lit and item_spec == .char and (target_spec == .uchar or target_spec == .schar)) or
        (is_str_lit and item_spec == .uchar and (target_spec == .uchar or target_spec == .schar or target_spec == .char));
    if (!compatible) {
        if (!report_err) return false;
        const e_msg = " with array of type ";
        try p.errStr(.incompatible_array_init, tok, try p.typePairStrExtra(target, e_msg, item.ty));
        return true; // do not do further coercion
    }

    if (target.get(.array)) |arr_ty| {
        assert(item.ty.specifier == .array);
        const len = item.ty.arrayLen().?;
        const array_len = arr_ty.arrayLen().?;
        if (is_str_lit) {
            // the null byte of a string can be dropped
            if (len - 1 > array_len and report_err) {
                try p.errTok(.str_init_too_long, tok);
            }
        } else if (len > array_len and report_err) {
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

    const node = item.node;
    try item.lvalConversion(p, tok);
    if (target.is(.auto_type)) {
        if (p.getNode(node, .member_access_expr) orelse p.getNode(node, .member_access_ptr_expr)) |access| {
            if (access.isBitFieldWidth(&p.tree) != null) try p.errTok(.auto_type_from_bitfield, tok);
        }
        return;
    } else if (target.is(.c23_auto)) {
        return;
    }

    try item.coerce(p, target, tok, .init);
    if (item.val.opt_ref == .none) runtime: {
        const tag: Diagnostics.Tag = switch (p.init_context) {
            .runtime => break :runtime,
            .constexpr => .constexpr_requires_const,
            .static => break :runtime, // TODO: set this to .non_constant_initializer once we are capable of saving all valid values
        };
        p.init_context = .runtime; // Suppress further "non-constant initializer" errors
        try p.errTok(tag, tok);
    }
    if (target.isConst() or p.init_context == .constexpr) {
        var copy = item.*;
        return copy.saveValue(p);
    }
    return item.saveValue(p);
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
fn convertInitList(p: *Parser, il: InitList, init_ty: Type) Error!Node.Index {
    const is_complex = init_ty.isComplex();
    if (init_ty.isScalar() and !is_complex) {
        return il.node.unpack() orelse
            try p.addNode(.{ .default_init_expr = .{
            .last_tok = il.tok,
            .type = init_ty,
        } });
    } else if (init_ty.is(.variable_len_array)) {
        return error.ParsingFailed; // vla invalid, reported earlier
    } else if (init_ty.isArray() or is_complex) {
        if (il.node.unpack()) |some| return some;

        const list_buf_top = p.list_buf.items.len;
        defer p.list_buf.items.len = list_buf_top;

        const elem_ty = init_ty.elemType();

        const max_items: u64 = init_ty.expectedInitListSize() orelse std.math.maxInt(usize);
        var start: u64 = 0;
        for (il.list.items) |*init| {
            if (init.index > start) {
                const elem = try p.addNode(.{
                    .array_filler_expr = .{
                        .last_tok = p.tok_i - 1,
                        .count = init.index - start,
                        .type = elem_ty,
                    },
                });
                try p.list_buf.append(elem);
            }
            start = init.index + 1;

            const elem = try p.convertInitList(init.list, elem_ty);
            try p.list_buf.append(elem);
        }

        const max_elems = p.comp.maxArrayBytes() / (@max(1, elem_ty.sizeof(p.comp) orelse 1));
        if (start > max_elems) {
            try p.errTok(.array_too_large, il.tok);
            start = max_elems;
        }

        var arr_init_ty = init_ty;
        if (init_ty.specifier == .incomplete_array) {
            arr_init_ty.specifier = .array;
            arr_init_ty.data.array.len = start;
        } else if (init_ty.is(.incomplete_array)) {
            const arr_ty = try p.arena.create(Type.Array);
            arr_ty.* = .{ .elem = init_ty.elemType(), .len = start };
            arr_init_ty = .{
                .specifier = .array,
                .data = .{ .array = arr_ty },
            };
        } else if (start < max_items) {
            const elem = try p.addNode(.{
                .array_filler_expr = .{
                    .last_tok = p.tok_i - 1,
                    .count = max_items - start,
                    .type = elem_ty,
                },
            });
            try p.list_buf.append(elem);
        }

        return p.addNode(.{ .array_init_expr = .{
            .l_brace_tok = il.tok,
            .container_type = arr_init_ty,
            .items = p.list_buf.items[list_buf_top..],
        } });
    } else if (init_ty.get(.@"struct")) |struct_ty| {
        assert(!struct_ty.hasIncompleteSize());
        if (il.node.unpack()) |some| return some;

        const list_buf_top = p.list_buf.items.len;
        defer p.list_buf.items.len = list_buf_top;

        var init_index: usize = 0;
        for (struct_ty.data.record.fields, 0..) |f, i| {
            if (init_index < il.list.items.len and il.list.items[init_index].index == i) {
                const item = try p.convertInitList(il.list.items[init_index].list, f.ty);
                try p.list_buf.append(item);
                init_index += 1;
            } else {
                const item = try p.addNode(.{
                    .default_init_expr = .{
                        .last_tok = il.tok, // TODO could be better
                        .type = f.ty,
                    },
                });
                try p.list_buf.append(item);
            }
        }

        return p.addNode(.{ .struct_init_expr = .{
            .l_brace_tok = il.tok,
            .container_type = init_ty,
            .items = p.list_buf.items[list_buf_top..],
        } });
    } else if (init_ty.get(.@"union")) |union_ty| {
        if (il.node.unpack()) |some| return some;

        const init_node, const index = if (union_ty.data.record.fields.len == 0)
            // do nothing for empty unions
            .{ null, 0 }
        else if (il.list.items.len == 0)
            .{ try p.addNode(.{ .default_init_expr = .{
                .last_tok = p.tok_i - 1,
                .type = init_ty,
            } }), 0 }
        else blk: {
            const init = il.list.items[0];
            const index: u32 = @truncate(init.index);
            const field_ty = union_ty.data.record.fields[index].ty;

            break :blk .{ try p.convertInitList(init.list, field_ty), index };
        };
        return p.addNode(.{ .union_init_expr = .{
            .field_index = index,
            .initializer = init_node,
            .l_brace_tok = il.tok,
            .union_type = init_ty,
        } });
    } else {
        return error.ParsingFailed; // initializer target is invalid, reported earlier
    }
}

fn msvcAsmStmt(p: *Parser) Error!?Node.Index {
    return p.todo("MSVC assembly statements");
}

/// asmOperand : ('[' IDENTIFIER ']')? asmStr '(' expr ')'
fn asmOperand(p: *Parser, names: *std.ArrayList(?TokenIndex), constraints: *NodeList, exprs: *NodeList) Error!void {
    if (p.eatToken(.l_bracket)) |l_bracket| {
        const ident = (try p.eatIdentifier()) orelse {
            try p.err(.expected_identifier);
            return error.ParsingFailed;
        };
        try names.append(ident);
        try p.expectClosing(l_bracket, .r_bracket);
    } else {
        try names.append(null);
    }
    const constraint = try p.asmStr();
    try constraints.append(constraint.node);

    const l_paren = p.eatToken(.l_paren) orelse {
        try p.errExtra(.expected_token, p.tok_i, .{ .tok_id = .{ .actual = p.tok_ids[p.tok_i], .expected = .l_paren } });
        return error.ParsingFailed;
    };
    const maybe_res = try p.expr();
    try p.expectClosing(l_paren, .r_paren);
    const res = try p.expectResult(maybe_res);
    try exprs.append(res.node);
}

/// gnuAsmStmt
///  : asmStr
///  | asmStr ':' asmOperand*
///  | asmStr ':' asmOperand* ':' asmOperand*
///  | asmStr ':' asmOperand* ':' asmOperand* : asmStr? (',' asmStr)*
///  | asmStr ':' asmOperand* ':' asmOperand* : asmStr? (',' asmStr)* : IDENTIFIER (',' IDENTIFIER)*
fn gnuAsmStmt(p: *Parser, quals: Tree.GNUAssemblyQualifiers, asm_tok: TokenIndex, l_paren: TokenIndex) Error!Node.Index {
    const asm_str = try p.asmStr();
    try p.checkAsmStr(asm_str.val, l_paren);

    if (p.tok_ids[p.tok_i] == .r_paren) {
        return try p.addNode(.{
            .gnu_asm_simple = .{
                .asm_str = asm_str.node,
                .asm_tok = asm_tok,
            },
        });
    }

    const expected_items = 8; // arbitrarily chosen, most assembly will have fewer than 8 inputs/outputs/constraints/names
    const bytes_needed = expected_items * @sizeOf(?TokenIndex) + expected_items * 3 * @sizeOf(Node.Index);

    var stack_fallback = std.heap.stackFallback(bytes_needed, p.gpa);
    const allocator = stack_fallback.get();

    // TODO: Consider using a TokenIndex of 0 instead of null if we need to store the names in the tree
    var names = std.ArrayList(?TokenIndex).initCapacity(allocator, expected_items) catch unreachable; // stack allocation already succeeded
    defer names.deinit();
    var constraints = NodeList.initCapacity(allocator, expected_items) catch unreachable; // stack allocation already succeeded
    defer constraints.deinit();
    var exprs = NodeList.initCapacity(allocator, expected_items) catch unreachable; //stack allocation already succeeded
    defer exprs.deinit();
    var clobbers = NodeList.initCapacity(allocator, expected_items) catch unreachable; //stack allocation already succeeded
    defer clobbers.deinit();

    // Outputs
    var ate_extra_colon = false;
    if (p.eatToken(.colon) orelse p.eatToken(.colon_colon)) |tok_i| {
        ate_extra_colon = p.tok_ids[tok_i] == .colon_colon;
        if (!ate_extra_colon) {
            if (p.tok_ids[p.tok_i].isStringLiteral() or p.tok_ids[p.tok_i] == .l_bracket) {
                while (true) {
                    try p.asmOperand(&names, &constraints, &exprs);
                    if (p.eatToken(.comma) == null) break;
                }
            }
        }
    }

    const num_outputs = names.items.len;

    // Inputs
    if (ate_extra_colon or p.tok_ids[p.tok_i] == .colon or p.tok_ids[p.tok_i] == .colon_colon) {
        if (ate_extra_colon) {
            ate_extra_colon = false;
        } else {
            ate_extra_colon = p.tok_ids[p.tok_i] == .colon_colon;
            p.tok_i += 1;
        }
        if (!ate_extra_colon) {
            if (p.tok_ids[p.tok_i].isStringLiteral() or p.tok_ids[p.tok_i] == .l_bracket) {
                while (true) {
                    try p.asmOperand(&names, &constraints, &exprs);
                    if (p.eatToken(.comma) == null) break;
                }
            }
        }
    }
    std.debug.assert(names.items.len == constraints.items.len and constraints.items.len == exprs.items.len);
    const num_inputs = names.items.len - num_outputs;
    _ = num_inputs;

    // Clobbers
    if (ate_extra_colon or p.tok_ids[p.tok_i] == .colon or p.tok_ids[p.tok_i] == .colon_colon) {
        if (ate_extra_colon) {
            ate_extra_colon = false;
        } else {
            ate_extra_colon = p.tok_ids[p.tok_i] == .colon_colon;
            p.tok_i += 1;
        }
        if (!ate_extra_colon and p.tok_ids[p.tok_i].isStringLiteral()) {
            while (true) {
                const clobber = try p.asmStr();
                try clobbers.append(clobber.node);
                if (p.eatToken(.comma) == null) break;
            }
        }
    }

    if (!quals.goto and (p.tok_ids[p.tok_i] != .r_paren or ate_extra_colon)) {
        try p.errExtra(.expected_token, p.tok_i, .{ .tok_id = .{ .actual = p.tok_ids[p.tok_i], .expected = .r_paren } });
        return error.ParsingFailed;
    }

    // Goto labels
    var num_labels: u32 = 0;
    if (ate_extra_colon or p.tok_ids[p.tok_i] == .colon) {
        if (!ate_extra_colon) {
            p.tok_i += 1;
        }
        while (true) {
            const ident = (try p.eatIdentifier()) orelse {
                try p.err(.expected_identifier);
                return error.ParsingFailed;
            };
            const ident_str = p.tokSlice(ident);
            const label = p.findLabel(ident_str) orelse blk: {
                try p.labels.append(.{ .unresolved_goto = ident });
                break :blk ident;
            };
            try names.append(ident);

            const elem_ty = try p.arena.create(Type);
            elem_ty.* = .{ .specifier = .void };

            const label_addr_node = try p.addNode(.{
                .addr_of_label = .{
                    .label_tok = label,
                    .type = .{ .specifier = .pointer, .data = .{ .sub_type = elem_ty } },
                },
            });
            try exprs.append(label_addr_node);

            num_labels += 1;
            if (p.eatToken(.comma) == null) break;
        }
    } else if (quals.goto) {
        try p.errExtra(.expected_token, p.tok_i, .{ .tok_id = .{ .actual = p.tok_ids[p.tok_i], .expected = .colon } });
        return error.ParsingFailed;
    }

    // TODO: validate and insert into AST
    return p.addNode(.{ .null_stmt = .{
        .semicolon_or_r_brace_tok = asm_tok,
        .type = .{ .specifier = .void },
    } });
}

fn checkAsmStr(p: *Parser, asm_str: Value, tok: TokenIndex) !void {
    if (!p.comp.langopts.gnu_asm) {
        const str = p.comp.interner.get(asm_str.ref()).bytes;
        if (str.len > 1) {
            // Empty string (just a NUL byte) is ok because it does not emit any assembly
            try p.errTok(.gnu_asm_disabled, tok);
        }
    }
}

/// assembly
///  : keyword_asm asmQual* '(' asmStr ')'
///  | keyword_asm asmQual* '(' gnuAsmStmt ')'
///  | keyword_asm msvcAsmStmt
fn assembly(p: *Parser, kind: enum { global, decl_label, stmt }) Error!?Node.Index {
    const asm_tok = p.tok_i;
    switch (p.tok_ids[p.tok_i]) {
        .keyword_asm => {
            try p.err(.extension_token_used);
            p.tok_i += 1;
        },
        .keyword_asm1, .keyword_asm2 => p.tok_i += 1,
        else => return null,
    }

    if (!p.tok_ids[p.tok_i].canOpenGCCAsmStmt()) {
        return p.msvcAsmStmt();
    }

    var quals: Tree.GNUAssemblyQualifiers = .{};
    while (true) : (p.tok_i += 1) switch (p.tok_ids[p.tok_i]) {
        .keyword_volatile, .keyword_volatile1, .keyword_volatile2 => {
            if (kind != .stmt) try p.errStr(.meaningless_asm_qual, p.tok_i, "volatile");
            if (quals.@"volatile") try p.errStr(.duplicate_asm_qual, p.tok_i, "volatile");
            quals.@"volatile" = true;
        },
        .keyword_inline, .keyword_inline1, .keyword_inline2 => {
            if (kind != .stmt) try p.errStr(.meaningless_asm_qual, p.tok_i, "inline");
            if (quals.@"inline") try p.errStr(.duplicate_asm_qual, p.tok_i, "inline");
            quals.@"inline" = true;
        },
        .keyword_goto => {
            if (kind != .stmt) try p.errStr(.meaningless_asm_qual, p.tok_i, "goto");
            if (quals.goto) try p.errStr(.duplicate_asm_qual, p.tok_i, "goto");
            quals.goto = true;
        },
        else => break,
    };

    const l_paren = try p.expectToken(.l_paren);
    var result_node: ?Node.Index = null;
    switch (kind) {
        .decl_label => {
            const asm_str = try p.asmStr();
            const str = try p.removeNull(asm_str.val);

            const attr = Attribute{ .tag = .asm_label, .args = .{ .asm_label = .{ .name = str } }, .syntax = .keyword };
            try p.attr_buf.append(p.gpa, .{ .attr = attr, .tok = asm_tok });
        },
        .global => {
            const asm_str = try p.asmStr();
            try p.checkAsmStr(asm_str.val, l_paren);
            result_node = try p.addNode(.{
                .global_asm = .{
                    .asm_tok = asm_tok,
                    .asm_str = asm_str.node,
                },
            });
        },
        .stmt => result_node = try p.gnuAsmStmt(quals, asm_tok, l_paren),
    }
    try p.expectClosing(l_paren, .r_paren);

    if (kind != .decl_label) _ = try p.expectToken(.semicolon);
    return result_node;
}

/// Same as stringLiteral but errors on unicode and wide string literals
fn asmStr(p: *Parser) Error!Result {
    var i = p.tok_i;
    while (true) : (i += 1) switch (p.tok_ids[i]) {
        .string_literal, .unterminated_string_literal => {},
        .string_literal_utf_16, .string_literal_utf_8, .string_literal_utf_32 => {
            try p.errStr(.invalid_asm_str, p.tok_i, "unicode");
            return error.ParsingFailed;
        },
        .string_literal_wide => {
            try p.errStr(.invalid_asm_str, p.tok_i, "wide");
            return error.ParsingFailed;
        },
        else => {
            if (i == p.tok_i) {
                try p.errStr(.expected_str_literal_in, p.tok_i, "asm");
                return error.ParsingFailed;
            }
            break;
        },
    };
    return p.stringLiteral();
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
fn stmt(p: *Parser) Error!Node.Index {
    if (try p.labeledStmt()) |some| return some;
    if (try p.compoundStmt(false, null)) |some| return some;
    if (p.eatToken(.keyword_if)) |kw_if| {
        const l_paren = try p.expectToken(.l_paren);

        const cond_tok = p.tok_i;
        var cond = try p.expect(expr);
        try cond.lvalConversion(p, cond_tok);
        try cond.usualUnaryConversion(p, cond_tok);
        if (!cond.ty.isScalar())
            try p.errStr(.statement_scalar, l_paren + 1, try p.typeStr(cond.ty));
        try cond.saveValue(p);

        try p.expectClosing(l_paren, .r_paren);

        const then_body = try p.stmt();
        const else_body = if (p.eatToken(.keyword_else)) |_| try p.stmt() else null;

        return p.addNode(.{ .if_stmt = .{
            .if_tok = kw_if,
            .cond = cond.node,
            .then_body = then_body,
            .else_body = else_body,
        } });
    }
    if (p.eatToken(.keyword_switch)) |kw_switch| {
        const l_paren = try p.expectToken(.l_paren);
        const cond_tok = p.tok_i;
        var cond = try p.expect(expr);
        try cond.lvalConversion(p, cond_tok);
        try cond.usualUnaryConversion(p, cond_tok);

        if (!cond.ty.isInt())
            try p.errStr(.statement_int, l_paren + 1, try p.typeStr(cond.ty));
        try cond.saveValue(p);
        try p.expectClosing(l_paren, .r_paren);

        const old_switch = p.@"switch";
        var @"switch" = Switch{
            .ranges = std.ArrayList(Switch.Range).init(p.gpa),
            .ty = cond.ty,
            .comp = p.comp,
        };
        p.@"switch" = &@"switch";
        defer {
            @"switch".ranges.deinit();
            p.@"switch" = old_switch;
        }

        const body = try p.stmt();

        return p.addNode(.{ .switch_stmt = .{
            .switch_tok = kw_switch,
            .cond = cond.node,
            .body = body,
        } });
    }
    if (p.eatToken(.keyword_while)) |kw_while| {
        const l_paren = try p.expectToken(.l_paren);

        const cond_tok = p.tok_i;
        var cond = try p.expect(expr);
        try cond.lvalConversion(p, cond_tok);
        try cond.usualUnaryConversion(p, cond_tok);
        if (!cond.ty.isScalar())
            try p.errStr(.statement_scalar, l_paren + 1, try p.typeStr(cond.ty));
        try cond.saveValue(p);

        try p.expectClosing(l_paren, .r_paren);

        const body = body: {
            const old_loop = p.in_loop;
            p.in_loop = true;
            defer p.in_loop = old_loop;
            break :body try p.stmt();
        };

        return p.addNode(.{ .while_stmt = .{
            .while_tok = kw_while,
            .cond = cond.node,
            .body = body,
        } });
    }
    if (p.eatToken(.keyword_do)) |kw_do| {
        const body = body: {
            const old_loop = p.in_loop;
            p.in_loop = true;
            defer p.in_loop = old_loop;
            break :body try p.stmt();
        };

        _ = try p.expectToken(.keyword_while);
        const l_paren = try p.expectToken(.l_paren);

        const cond_tok = p.tok_i;
        var cond = try p.expect(expr);
        try cond.lvalConversion(p, cond_tok);
        try cond.usualUnaryConversion(p, cond_tok);

        if (!cond.ty.isScalar())
            try p.errStr(.statement_scalar, l_paren + 1, try p.typeStr(cond.ty));
        try cond.saveValue(p);
        try p.expectClosing(l_paren, .r_paren);

        _ = try p.expectToken(.semicolon);

        return p.addNode(.{ .do_while_stmt = .{
            .do_tok = kw_do,
            .cond = cond.node,
            .body = body,
        } });
    }
    if (p.eatToken(.keyword_for)) |kw_for| {
        try p.syms.pushScope(p);
        defer p.syms.popScope();
        const decl_buf_top = p.decl_buf.items.len;
        defer p.decl_buf.items.len = decl_buf_top;

        const l_paren = try p.expectToken(.l_paren);
        const got_decl = try p.decl();

        // for (init
        const init_start = p.tok_i;
        var err_start = p.comp.diagnostics.list.items.len;
        const init = init: {
            if (got_decl) break :init null;
            var init = (try p.expr()) orelse break :init null;

            try init.saveValue(p);
            try init.maybeWarnUnused(p, init_start, err_start);
            break :init init.node;
        };
        if (!got_decl) _ = try p.expectToken(.semicolon);

        // for (init; cond
        const cond = cond: {
            if (got_decl) break :cond null;
            const cond_tok = p.tok_i;
            var cond = (try p.expr()) orelse break :cond null;

            try cond.lvalConversion(p, cond_tok);
            try cond.usualUnaryConversion(p, cond_tok);
            if (!cond.ty.isScalar())
                try p.errStr(.statement_scalar, l_paren + 1, try p.typeStr(cond.ty));
            try cond.saveValue(p);
            break :cond cond.node;
        };
        _ = try p.expectToken(.semicolon);

        // for (init; cond; incr
        const incr_start = p.tok_i;
        err_start = p.comp.diagnostics.list.items.len;
        const incr = incr: {
            var incr = (try p.expr()) orelse break :incr null;

            try incr.maybeWarnUnused(p, incr_start, err_start);
            try incr.saveValue(p);
            break :incr incr.node;
        };
        try p.expectClosing(l_paren, .r_paren);

        const body = body: {
            const old_loop = p.in_loop;
            p.in_loop = true;
            defer p.in_loop = old_loop;
            break :body try p.stmt();
        };

        return p.addNode(.{ .for_stmt = .{
            .for_tok = kw_for,
            .init = if (init) |some|
                .{ .expr = some }
            else
                .{ .decls = p.decl_buf.items[decl_buf_top..] },
            .cond = cond,
            .incr = incr,
            .body = body,
        } });
    }
    if (p.eatToken(.keyword_goto)) |goto_tok| {
        if (p.eatToken(.asterisk)) |_| {
            const expr_tok = p.tok_i;
            var goto_expr = try p.expect(expr);
            try goto_expr.lvalConversion(p, expr_tok);
            p.computed_goto_tok = p.computed_goto_tok orelse goto_tok;
            if (!goto_expr.ty.isPtr()) {
                const elem_ty = try p.arena.create(Type);
                elem_ty.* = .{ .specifier = .void, .qual = .{ .@"const" = true } };
                const result_ty = Type{
                    .specifier = .pointer,
                    .data = .{ .sub_type = elem_ty },
                };
                if (!goto_expr.ty.isInt()) {
                    try p.errStr(.incompatible_arg, expr_tok, try p.typePairStrExtra(goto_expr.ty, " to parameter of incompatible type ", result_ty));
                    return error.ParsingFailed;
                }
                if (goto_expr.val.isZero(p.comp)) {
                    try goto_expr.nullCast(p, result_ty, expr_tok);
                } else {
                    try p.errStr(.implicit_int_to_ptr, expr_tok, try p.typePairStrExtra(goto_expr.ty, " to ", result_ty));
                    try goto_expr.ptrCast(p, result_ty, expr_tok);
                }
            }

            return p.addNode(.{ .computed_goto_stmt = .{ .goto_tok = goto_tok, .expr = goto_expr.node } });
        }
        const name_tok = try p.expectIdentifier();
        const str = p.tokSlice(name_tok);
        if (p.findLabel(str) == null) {
            try p.labels.append(.{ .unresolved_goto = name_tok });
        }
        _ = try p.expectToken(.semicolon);
        return p.addNode(.{ .goto_stmt = .{ .label_tok = name_tok } });
    }
    if (p.eatToken(.keyword_continue)) |cont| {
        if (!p.in_loop) try p.errTok(.continue_not_in_loop, cont);
        _ = try p.expectToken(.semicolon);
        return p.addNode(.{ .continue_stmt = .{ .continue_tok = cont } });
    }
    if (p.eatToken(.keyword_break)) |br| {
        if (!p.in_loop and p.@"switch" == null) try p.errTok(.break_not_in_loop_or_switch, br);
        _ = try p.expectToken(.semicolon);
        return p.addNode(.{ .break_stmt = .{ .break_tok = br } });
    }
    if (try p.returnStmt()) |some| return some;
    if (try p.assembly(.stmt)) |some| return some;

    const expr_start = p.tok_i;
    const err_start = p.comp.diagnostics.list.items.len;

    if (try p.expr()) |some| {
        _ = try p.expectToken(.semicolon);
        try some.maybeWarnUnused(p, expr_start, err_start);
        return some.node;
    }

    const attr_buf_top = p.attr_buf.len;
    defer p.attr_buf.len = attr_buf_top;
    try p.attributeSpecifier();

    if (p.eatToken(.semicolon)) |semicolon| {
        return p.addNode(.{ .null_stmt = .{
            .semicolon_or_r_brace_tok = semicolon,
            .type = try Attribute.applyStatementAttributes(p, expr_start, attr_buf_top),
        } });
    }

    try p.err(.expected_stmt);
    return error.ParsingFailed;
}

/// labeledStmt
/// : IDENTIFIER ':' stmt
/// | keyword_case integerConstExpr ':' stmt
/// | keyword_default ':' stmt
fn labeledStmt(p: *Parser) Error!?Node.Index {
    if ((p.tok_ids[p.tok_i] == .identifier or p.tok_ids[p.tok_i] == .extended_identifier) and p.tok_ids[p.tok_i + 1] == .colon) {
        const name_tok = try p.expectIdentifier();
        const str = p.tokSlice(name_tok);
        if (p.findLabel(str)) |some| {
            try p.errStr(.duplicate_label, name_tok, str);
            try p.errStr(.previous_label, some, str);
        } else {
            p.label_count += 1;
            try p.labels.append(.{ .label = name_tok });
            var i: usize = 0;
            while (i < p.labels.items.len) {
                if (p.labels.items[i] == .unresolved_goto and
                    mem.eql(u8, p.tokSlice(p.labels.items[i].unresolved_goto), str))
                {
                    _ = p.labels.swapRemove(i);
                } else i += 1;
            }
        }

        p.tok_i += 1;
        const attr_buf_top = p.attr_buf.len;
        defer p.attr_buf.len = attr_buf_top;
        try p.attributeSpecifier();

        return try p.addNode(.{ .labeled_stmt = .{
            .type = try Attribute.applyLabelAttributes(p, attr_buf_top),
            .body = try p.labelableStmt(),
            .label_tok = name_tok,
        } });
    } else if (p.eatToken(.keyword_case)) |case| {
        const first_item = try p.integerConstExpr(.gnu_folding_extension);
        const ellipsis = p.tok_i;
        const second_item = if (p.eatToken(.ellipsis) != null) blk: {
            try p.errTok(.gnu_switch_range, ellipsis);
            break :blk try p.integerConstExpr(.gnu_folding_extension);
        } else null;
        _ = try p.expectToken(.colon);

        if (p.@"switch") |some| check: {
            if (some.ty.hasIncompleteSize()) break :check; // error already reported for incomplete size

            const first = first_item.val;
            const last = if (second_item) |second| second.val else first;
            if (first.opt_ref == .none) {
                try p.errTok(.case_val_unavailable, case + 1);
                break :check;
            } else if (last.opt_ref == .none) {
                try p.errTok(.case_val_unavailable, ellipsis + 1);
                break :check;
            } else if (last.compare(.lt, first, p.comp)) {
                try p.errTok(.empty_case_range, case + 1);
                break :check;
            }

            // TODO cast to target type
            const prev = (try some.add(first, last, case + 1)) orelse break :check;

            // TODO check which value was already handled
            try p.errStr(.duplicate_switch_case, case + 1, try first_item.str(p));
            try p.errTok(.previous_case, prev.tok);
        } else {
            try p.errStr(.case_not_in_switch, case, "case");
        }

        return try p.addNode(.{ .case_stmt = .{
            .case_tok = case,
            .start = first_item.node,
            .end = if (second_item) |some| some.node else null,
            .body = try p.labelableStmt(),
        } });
    } else if (p.eatToken(.keyword_default)) |default| {
        _ = try p.expectToken(.colon);
        const node = try p.addNode(.{ .default_stmt = .{
            .default_tok = default,
            .body = try p.labelableStmt(),
        } });

        const @"switch" = p.@"switch" orelse {
            try p.errStr(.case_not_in_switch, default, "default");
            return node;
        };
        if (@"switch".default) |previous| {
            try p.errTok(.multiple_default, default);
            try p.errTok(.previous_case, previous);
        } else {
            @"switch".default = default;
        }
        return node;
    } else return null;
}

fn labelableStmt(p: *Parser) Error!Node.Index {
    if (p.tok_ids[p.tok_i] == .r_brace) {
        try p.err(.label_compound_end);
        return p.addNode(.{ .null_stmt = .{
            .semicolon_or_r_brace_tok = p.tok_i,
            .type = .{ .specifier = .void },
        } });
    }
    return p.stmt();
}

const StmtExprState = struct {
    last_expr_tok: TokenIndex = 0,
    last_expr_type: Type = .{ .specifier = .void },
};

/// compoundStmt : '{' ( decl | keyword_extension decl | staticAssert | stmt)* '}'
fn compoundStmt(p: *Parser, is_fn_body: bool, stmt_expr_state: ?*StmtExprState) Error!?Node.Index {
    const l_brace = p.eatToken(.l_brace) orelse return null;

    const decl_buf_top = p.decl_buf.items.len;
    defer p.decl_buf.items.len = decl_buf_top;

    // the parameters of a function are in the same scope as the body
    if (!is_fn_body) try p.syms.pushScope(p);
    defer if (!is_fn_body) p.syms.popScope();

    var noreturn_index: ?TokenIndex = null;
    var noreturn_label_count: u32 = 0;

    while (p.eatToken(.r_brace) == null) : (_ = try p.pragma()) {
        if (stmt_expr_state) |state| state.* = .{};
        if (try p.parseOrNextStmt(staticAssert, l_brace)) continue;
        if (try p.parseOrNextStmt(decl, l_brace)) continue;
        if (p.eatToken(.keyword_extension)) |ext| {
            const saved_extension = p.extension_suppressed;
            defer p.extension_suppressed = saved_extension;
            p.extension_suppressed = true;

            if (try p.parseOrNextStmt(decl, l_brace)) continue;
            p.tok_i = ext;
        }
        const stmt_tok = p.tok_i;
        const s = p.stmt() catch |er| switch (er) {
            error.ParsingFailed => {
                try p.nextStmt(l_brace);
                continue;
            },
            else => |e| return e,
        };
        if (stmt_expr_state) |state| {
            state.* = .{
                .last_expr_tok = stmt_tok,
                .last_expr_type = s.type(&p.tree),
            };
        }
        try p.decl_buf.append(s);

        if (noreturn_index == null and p.nodeIsNoreturn(s) == .yes) {
            noreturn_index = p.tok_i;
            noreturn_label_count = p.label_count;
        }
        switch (s.get(&p.tree)) {
            .case_stmt, .default_stmt, .labeled_stmt => noreturn_index = null,
            else => {},
        }
    }
    const r_brace = p.tok_i - 1;

    if (noreturn_index) |some| {
        // if new labels were defined we cannot be certain that the code is unreachable
        if (some != p.tok_i - 1 and noreturn_label_count == p.label_count) try p.errTok(.unreachable_code, some);
    }
    if (is_fn_body) {
        const last_noreturn = if (p.decl_buf.items.len == decl_buf_top)
            .no
        else
            p.nodeIsNoreturn(p.decl_buf.items[p.decl_buf.items.len - 1]);

        if (last_noreturn != .yes) {
            const ret_ty = p.func.ty.?.returnType();
            var return_zero = false;
            if (last_noreturn == .no and !ret_ty.is(.void) and !ret_ty.isFunc() and !ret_ty.isArray()) {
                const func_name = p.tokSlice(p.func.name);
                const interned_name = try StrInt.intern(p.comp, func_name);
                if (interned_name == p.string_ids.main_id and ret_ty.is(.int)) {
                    return_zero = true;
                } else {
                    try p.errStr(.func_does_not_return, p.tok_i - 1, func_name);
                }
            }
            const implicit_ret = try p.addNode(.{ .implicit_return = .{
                .r_brace_tok = r_brace,
                .return_type = ret_ty,
                .zero = return_zero,
            } });
            try p.decl_buf.append(implicit_ret);
        }
        if (p.func.ident) |some| try p.decl_buf.insert(decl_buf_top, some.node);
        if (p.func.pretty_ident) |some| try p.decl_buf.insert(decl_buf_top, some.node);
    }

    return try p.addNode(.{ .compound_stmt = .{
        .body = p.decl_buf.items[decl_buf_top..],
        .l_brace_tok = l_brace,
    } });
}

fn pointerValue(p: *Parser, node: Node.Index, offset: Value) !Value {
    switch (node.get(&p.tree)) {
        .decl_ref_expr => |decl_ref| {
            const var_name = try p.comp.internString(p.tokSlice(decl_ref.name_tok));
            const sym = p.syms.findSymbol(var_name) orelse return .{};
            const sym_node = sym.node.unpack() orelse return .{};
            return Value.pointer(.{ .node = @intFromEnum(sym_node), .offset = offset.ref() }, p.comp);
        },
        .string_literal_expr => return p.tree.value_map.get(node).?,
        else => return .{},
    }
}

const NoreturnKind = enum { no, yes, complex };

fn nodeIsNoreturn(p: *Parser, node: Node.Index) NoreturnKind {
    switch (node.get(&p.tree)) {
        .break_stmt, .continue_stmt, .return_stmt => return .yes,
        .if_stmt => |@"if"| {
            const else_type = p.nodeIsNoreturn(@"if".else_body orelse return .no);
            const then_type = p.nodeIsNoreturn(@"if".then_body);
            if (then_type == .complex or else_type == .complex) return .complex;
            if (then_type == .yes and else_type == .yes) return .yes;
            return .no;
        },
        .compound_stmt => |compound| {
            for (compound.body) |body_stmt| {
                const kind = p.nodeIsNoreturn(body_stmt);
                if (kind != .no) return kind;
            }
            return .no;
        },
        .labeled_stmt => |labeled| {
            return p.nodeIsNoreturn(labeled.body);
        },
        .default_stmt => |default| {
            return p.nodeIsNoreturn(default.body);
        },
        .while_stmt, .do_while_stmt, .for_stmt, .switch_stmt => return .complex,
        else => return .no,
    }
}

fn parseOrNextStmt(p: *Parser, comptime func: fn (*Parser) Error!bool, l_brace: TokenIndex) !bool {
    return func(p) catch |er| switch (er) {
        error.ParsingFailed => {
            try p.nextStmt(l_brace);
            return true;
        },
        else => |e| return e,
    };
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
            .semicolon => if (parens == 0) {
                p.tok_i += 1;
                return;
            },
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
            .keyword_c23_thread_local,
            .keyword_inline,
            .keyword_inline1,
            .keyword_inline2,
            .keyword_noreturn,
            .keyword_void,
            .keyword_bool,
            .keyword_c23_bool,
            .keyword_char,
            .keyword_short,
            .keyword_int,
            .keyword_long,
            .keyword_signed,
            .keyword_signed1,
            .keyword_signed2,
            .keyword_unsigned,
            .keyword_float,
            .keyword_double,
            .keyword_complex,
            .keyword_atomic,
            .keyword_enum,
            .keyword_struct,
            .keyword_union,
            .keyword_alignas,
            .keyword_c23_alignas,
            .keyword_typeof,
            .keyword_typeof1,
            .keyword_typeof2,
            .keyword_typeof_unqual,
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

fn returnStmt(p: *Parser) Error!?Node.Index {
    const ret_tok = p.eatToken(.keyword_return) orelse return null;

    const e_tok = p.tok_i;
    var ret_expr = try p.expr();
    _ = try p.expectToken(.semicolon);
    const ret_ty = p.func.ty.?.returnType();

    if (p.func.ty.?.hasAttribute(.noreturn)) {
        try p.errStr(.invalid_noreturn, e_tok, p.tokSlice(p.func.name));
    }

    if (ret_expr) |*some| {
        if (ret_ty.is(.void)) {
            try p.errStr(.void_func_returns_value, e_tok, p.tokSlice(p.func.name));
        } else {
            try some.lvalConversion(p, e_tok);
            try some.coerce(p, ret_ty, e_tok, .ret);

            try some.saveValue(p);
        }
    } else if (!ret_ty.is(.void)) {
        try p.errStr(.func_should_return, ret_tok, p.tokSlice(p.func.name));
    }

    return try p.addNode(.{ .return_stmt = .{
        .return_tok = ret_tok,
        .expr = if (ret_expr) |some| some.node else null,
        .return_type = ret_ty,
    } });
}

// ====== expressions ======

pub fn macroExpr(p: *Parser) Compilation.Error!bool {
    const res = p.expect(condExpr) catch |e| switch (e) {
        error.OutOfMemory => return error.OutOfMemory,
        error.FatalError => return error.FatalError,
        error.ParsingFailed => return false,
    };
    return res.val.toBool(p.comp);
}

const CallExpr = union(enum) {
    standard: Node.Index,
    builtin: struct {
        builtin_tok: TokenIndex,
        tag: Builtin.Tag,
    },

    fn init(p: *Parser, call_node: Node.Index, func_node: Node.Index) CallExpr {
        if (p.getNode(call_node, .decl_ref_expr)) |decl_ref| {
            const name = p.tokSlice(decl_ref.name_tok);
            // If this is a builtin then primaryExpr() already created it.
            if (p.comp.builtins.getOrCreate(p.comp, name, p.arena) catch unreachable) |expanded| {
                return .{ .builtin = .{ .builtin_tok = decl_ref.name_tok, .tag = expanded.builtin.tag } };
            }
        }
        return .{ .standard = func_node };
    }

    fn shouldPerformLvalConversion(self: CallExpr, arg_idx: u32) bool {
        return switch (self) {
            .standard => true,
            .builtin => |builtin| switch (builtin.tag) {
                Builtin.tagFromName("__builtin_va_start").?,
                Builtin.tagFromName("__va_start").?,
                Builtin.tagFromName("va_start").?,
                => arg_idx != 1,
                else => true,
            },
        };
    }

    fn shouldPromoteVarArg(self: CallExpr, arg_idx: u32) bool {
        return switch (self) {
            .standard => true,
            .builtin => |builtin| switch (builtin.tag) {
                Builtin.tagFromName("__builtin_va_start").?,
                Builtin.tagFromName("__va_start").?,
                Builtin.tagFromName("va_start").?,
                => arg_idx != 1,
                Builtin.tagFromName("__builtin_add_overflow").?,
                Builtin.tagFromName("__builtin_complex").?,
                Builtin.tagFromName("__builtin_isinf").?,
                Builtin.tagFromName("__builtin_isinf_sign").?,
                Builtin.tagFromName("__builtin_mul_overflow").?,
                Builtin.tagFromName("__builtin_isnan").?,
                Builtin.tagFromName("__builtin_sub_overflow").?,
                => false,
                else => true,
            },
        };
    }

    fn shouldCoerceArg(self: CallExpr, arg_idx: u32) bool {
        _ = self;
        _ = arg_idx;
        return true;
    }

    fn checkVarArg(self: CallExpr, p: *Parser, first_after: TokenIndex, param_tok: TokenIndex, arg: *Result, arg_idx: u32) !void {
        if (self == .standard) return;

        const builtin_tok = self.builtin.builtin_tok;
        switch (self.builtin.tag) {
            Builtin.tagFromName("__builtin_va_start").?,
            Builtin.tagFromName("__va_start").?,
            Builtin.tagFromName("va_start").?,
            => return p.checkVaStartArg(builtin_tok, first_after, param_tok, arg, arg_idx),
            Builtin.tagFromName("__builtin_complex").? => return p.checkComplexArg(builtin_tok, first_after, param_tok, arg, arg_idx),
            Builtin.tagFromName("__builtin_add_overflow").?,
            Builtin.tagFromName("__builtin_sub_overflow").?,
            Builtin.tagFromName("__builtin_mul_overflow").?,
            => return p.checkArithOverflowArg(builtin_tok, first_after, param_tok, arg, arg_idx),

            else => {},
        }
    }

    /// Some functions cannot be expressed as standard C prototypes. For example `__builtin_complex` requires
    /// two arguments of the same real floating point type (e.g. two doubles or two floats). These functions are
    /// encoded as varargs functions with custom typechecking. Since varargs functions do not have a fixed number
    /// of arguments, `paramCountOverride` is used to tell us how many arguments we should actually expect to see for
    /// these custom-typechecked functions.
    fn paramCountOverride(self: CallExpr) ?u32 {
        return switch (self) {
            .standard => null,
            .builtin => |builtin| switch (builtin.tag) {
                Builtin.tagFromName("__c11_atomic_thread_fence").?,
                Builtin.tagFromName("__c11_atomic_signal_fence").?,
                Builtin.tagFromName("__c11_atomic_is_lock_free").?,
                Builtin.tagFromName("__builtin_isinf").?,
                Builtin.tagFromName("__builtin_isinf_sign").?,
                Builtin.tagFromName("__builtin_isnan").?,
                => 1,

                Builtin.tagFromName("__builtin_complex").?,
                Builtin.tagFromName("__c11_atomic_load").?,
                Builtin.tagFromName("__c11_atomic_init").?,
                => 2,

                Builtin.tagFromName("__c11_atomic_store").?,
                Builtin.tagFromName("__c11_atomic_exchange").?,
                Builtin.tagFromName("__c11_atomic_fetch_add").?,
                Builtin.tagFromName("__c11_atomic_fetch_sub").?,
                Builtin.tagFromName("__c11_atomic_fetch_or").?,
                Builtin.tagFromName("__c11_atomic_fetch_xor").?,
                Builtin.tagFromName("__c11_atomic_fetch_and").?,
                Builtin.tagFromName("__atomic_fetch_add").?,
                Builtin.tagFromName("__atomic_fetch_sub").?,
                Builtin.tagFromName("__atomic_fetch_and").?,
                Builtin.tagFromName("__atomic_fetch_xor").?,
                Builtin.tagFromName("__atomic_fetch_or").?,
                Builtin.tagFromName("__atomic_fetch_nand").?,
                Builtin.tagFromName("__atomic_add_fetch").?,
                Builtin.tagFromName("__atomic_sub_fetch").?,
                Builtin.tagFromName("__atomic_and_fetch").?,
                Builtin.tagFromName("__atomic_xor_fetch").?,
                Builtin.tagFromName("__atomic_or_fetch").?,
                Builtin.tagFromName("__atomic_nand_fetch").?,
                Builtin.tagFromName("__builtin_add_overflow").?,
                Builtin.tagFromName("__builtin_sub_overflow").?,
                Builtin.tagFromName("__builtin_mul_overflow").?,
                => 3,

                Builtin.tagFromName("__c11_atomic_compare_exchange_strong").?,
                Builtin.tagFromName("__c11_atomic_compare_exchange_weak").?,
                => 5,

                Builtin.tagFromName("__atomic_compare_exchange").?,
                Builtin.tagFromName("__atomic_compare_exchange_n").?,
                => 6,
                else => null,
            },
        };
    }

    fn returnType(self: CallExpr, p: *Parser, callable_ty: Type) Type {
        return switch (self) {
            .standard => callable_ty.returnType(),
            .builtin => |builtin| switch (builtin.tag) {
                Builtin.tagFromName("__c11_atomic_exchange").? => {
                    if (p.list_buf.items.len != 4) return Type.invalid; // wrong number of arguments; already an error
                    const second_param = p.list_buf.items[2];
                    return second_param.type(&p.tree);
                },
                Builtin.tagFromName("__c11_atomic_load").? => {
                    if (p.list_buf.items.len != 3) return Type.invalid; // wrong number of arguments; already an error
                    const first_param = p.list_buf.items[1];
                    const ty = first_param.type(&p.tree);
                    if (!ty.isPtr()) return Type.invalid;
                    return ty.elemType();
                },

                Builtin.tagFromName("__atomic_fetch_add").?,
                Builtin.tagFromName("__atomic_add_fetch").?,
                Builtin.tagFromName("__c11_atomic_fetch_add").?,

                Builtin.tagFromName("__atomic_fetch_sub").?,
                Builtin.tagFromName("__atomic_sub_fetch").?,
                Builtin.tagFromName("__c11_atomic_fetch_sub").?,

                Builtin.tagFromName("__atomic_fetch_and").?,
                Builtin.tagFromName("__atomic_and_fetch").?,
                Builtin.tagFromName("__c11_atomic_fetch_and").?,

                Builtin.tagFromName("__atomic_fetch_xor").?,
                Builtin.tagFromName("__atomic_xor_fetch").?,
                Builtin.tagFromName("__c11_atomic_fetch_xor").?,

                Builtin.tagFromName("__atomic_fetch_or").?,
                Builtin.tagFromName("__atomic_or_fetch").?,
                Builtin.tagFromName("__c11_atomic_fetch_or").?,

                Builtin.tagFromName("__atomic_fetch_nand").?,
                Builtin.tagFromName("__atomic_nand_fetch").?,
                Builtin.tagFromName("__c11_atomic_fetch_nand").?,
                => {
                    if (p.list_buf.items.len != 3) return Type.invalid; // wrong number of arguments; already an error
                    const second_param = p.list_buf.items[2];
                    return second_param.type(&p.tree);
                },
                Builtin.tagFromName("__builtin_complex").? => {
                    if (p.list_buf.items.len < 1) return Type.invalid; // not enough arguments; already an error
                    const last_param = p.list_buf.items[p.list_buf.items.len - 1];
                    return last_param.type(&p.tree).makeComplex();
                },
                Builtin.tagFromName("__atomic_compare_exchange").?,
                Builtin.tagFromName("__atomic_compare_exchange_n").?,
                Builtin.tagFromName("__c11_atomic_is_lock_free").?,
                => .{ .specifier = .bool },
                else => callable_ty.returnType(),

                Builtin.tagFromName("__c11_atomic_compare_exchange_strong").?,
                Builtin.tagFromName("__c11_atomic_compare_exchange_weak").?,
                => {
                    if (p.list_buf.items.len != 6) return Type.invalid; // wrong number of arguments
                    const third_param = p.list_buf.items[3];
                    return third_param.type(&p.tree);
                },
            },
        };
    }

    fn finish(self: CallExpr, p: *Parser, ty: Type, list_buf_top: usize, l_paren: TokenIndex) Error!?Result {
        const ret_ty = self.returnType(p, ty);
        const args = p.list_buf.items[list_buf_top..];
        switch (self) {
            .standard => |func_node| return .{
                .ty = ret_ty,
                .node = try p.addNode(.{ .call_expr = .{
                    .l_paren_tok = l_paren,
                    .type = ret_ty,
                    .callee = func_node,
                    .args = args,
                } }),
            },
            .builtin => |builtin| return .{
                .val = try evalBuiltin(builtin.tag, p, args),
                .ty = ret_ty,
                .node = try p.addNode(.{ .builtin_call_expr = .{
                    .builtin_tok = builtin.builtin_tok,
                    .type = ret_ty,
                    .args = args,
                } }),
            },
        }
    }
};

pub const Result = struct {
    /// TokenIndex when p.in_macro == true
    node: Node.Index,
    ty: Type = .{ .specifier = .int },
    val: Value = .{},

    pub fn str(res: Result, p: *Parser) ![]const u8 {
        switch (res.val.opt_ref) {
            .none => return "(none)",
            .null => return "nullptr_t",
            else => {},
        }
        const strings_top = p.strings.items.len;
        defer p.strings.items.len = strings_top;

        if (try res.val.print(res.ty, p.comp, p.strings.writer())) |nested| switch (nested) {
            .pointer => |ptr| {
                const ptr_node: Node.Index = @enumFromInt(ptr.node);
                const decl_name = p.tree.tokSlice(ptr_node.tok(&p.tree));
                try ptr.offset.printPointer(decl_name, p.comp, p.strings.writer());
            },
        };

        return try p.comp.diagnostics.arena.allocator().dupe(u8, p.strings.items[strings_top..]);
    }

    fn maybeWarnUnused(res: Result, p: *Parser, expr_start: TokenIndex, err_start: usize) Error!void {
        if (res.ty.is(.void)) return;
        // don't warn about unused result if the expression contained errors besides other unused results
        for (p.comp.diagnostics.list.items[err_start..]) |err_item| {
            if (err_item.tag != .unused_value) return;
        }
        var cur_node = res.node;
        while (true) switch (cur_node.get(&p.tree)) {
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
            .pre_inc_expr,
            .pre_dec_expr,
            .post_inc_expr,
            .post_dec_expr,
            => return,
            .call_expr => |call| {
                const call_info = p.tree.callableResultUsage(call.callee) orelse return;
                if (call_info.nodiscard) try p.errStr(.nodiscard_unused, expr_start, p.tokSlice(call_info.tok));
                if (call_info.warn_unused_result) try p.errStr(.warn_unused_result, expr_start, p.tokSlice(call_info.tok));
                return;
            },
            .builtin_call_expr => |call| {
                const expanded = p.comp.builtins.lookup(p.tokSlice(call.builtin_tok));
                const attributes = expanded.builtin.properties.attributes;
                if (attributes.pure) try p.errStr(.builtin_unused, call.builtin_tok, "pure");
                if (attributes.@"const") try p.errStr(.builtin_unused, call.builtin_tok, "const");
                return;
            },
            .stmt_expr => |stmt_expr| {
                const compound = stmt_expr.operand.get(&p.tree).compound_stmt;
                cur_node = compound.body[compound.body.len - 1];
            },
            .comma_expr => |comma| cur_node = comma.rhs,
            .paren_expr => |grouped| cur_node = grouped.operand,
            else => break,
        };
        try p.errTok(.unused_value, expr_start);
    }

    fn boolRes(lhs: *Result, p: *Parser, tag: std.meta.Tag(Node), rhs: Result, tok_i: TokenIndex) !void {
        if (lhs.val.opt_ref == .null) {
            lhs.val = Value.zero;
        }
        if (lhs.ty.specifier != .invalid) {
            lhs.ty = Type.int;
        }
        return lhs.bin(p, tag, rhs, tok_i);
    }

    fn bin(lhs: *Result, p: *Parser, rt_tag: std.meta.Tag(Node), rhs: Result, tok_i: TokenIndex) !void {
        const bin_data: Node.BinaryExpr = .{
            .op_tok = tok_i,
            .lhs = lhs.node,
            .rhs = rhs.node,
            .type = lhs.ty,
        };
        switch (rt_tag) {
            // zig fmt: off
            inline .comma_expr, .assign_expr, .mul_assign_expr, .div_assign_expr,
            .mod_assign_expr, .add_assign_expr, .sub_assign_expr, .shl_assign_expr,
            .shr_assign_expr, .bit_and_assign_expr, .bit_xor_assign_expr,
            .bit_or_assign_expr, .bool_or_expr, .bool_and_expr, .bit_or_expr,
            .bit_xor_expr, .bit_and_expr, .equal_expr, .not_equal_expr,
            .less_than_expr, .less_than_equal_expr, .greater_than_expr,
            .greater_than_equal_expr, .shl_expr, .shr_expr, .add_expr,
            .sub_expr, .mul_expr, .div_expr, .mod_expr,
            // zig fmt: on
            => |tag| lhs.node = try p.addNode(@unionInit(Node, @tagName(tag), bin_data)),
            else => unreachable,
        }
    }

    fn un(operand: *Result, p: *Parser, rt_tag: std.meta.Tag(Node), tok_i: TokenIndex) Error!void {
        const un_data: Node.UnaryExpr = .{
            .op_tok = tok_i,
            .operand = operand.node,
            .type = operand.ty,
        };
        switch (rt_tag) {
            // zig fmt: off
            inline .addr_of_expr, .deref_expr, .plus_expr, .negate_expr,
            .bit_not_expr, .bool_not_expr, .pre_inc_expr, .pre_dec_expr,
            .imag_expr, .real_expr, .post_inc_expr,.post_dec_expr,
            .paren_expr, .stmt_expr, .imaginary_literal,
            // zig fmt: on
            => |tag| operand.node = try p.addNode(@unionInit(Node, @tagName(tag), un_data)),
            else => unreachable,
        }
    }

    fn implicitCast(operand: *Result, p: *Parser, kind: Node.Cast.Kind, tok: TokenIndex) Error!void {
        operand.node = try p.addNode(.{
            .implicit_cast = .{
                .l_paren = tok,
                .kind = kind,
                .operand = operand.node,
                .type = operand.ty,
            },
        });
    }

    fn adjustCondExprPtrs(a: *Result, tok: TokenIndex, b: *Result, p: *Parser) !bool {
        assert(a.ty.isPtr() and b.ty.isPtr());

        const a_elem = a.ty.elemType();
        const b_elem = b.ty.elemType();
        if (a_elem.eql(b_elem, p.comp, true)) return true;

        var adjusted_elem_ty = try p.arena.create(Type);
        adjusted_elem_ty.* = a_elem;

        const has_void_star_branch = a.ty.isVoidStar() or b.ty.isVoidStar();
        const only_quals_differ = a_elem.eql(b_elem, p.comp, false);
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
        if (!adjusted_elem_ty.eql(a_elem, p.comp, true)) {
            a.ty = .{
                .data = .{ .sub_type = adjusted_elem_ty },
                .specifier = .pointer,
            };
            try a.implicitCast(p, .bitcast, tok);
        }
        if (!adjusted_elem_ty.eql(b_elem, p.comp, true)) {
            b.ty = .{
                .data = .{ .sub_type = adjusted_elem_ty },
                .specifier = .pointer,
            };
            try b.implicitCast(p, .bitcast, tok);
        }
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
        if (b.ty.specifier == .invalid) {
            try a.saveValue(p);
            a.ty = Type.invalid;
        }
        if (a.ty.specifier == .invalid) {
            return false;
        }
        try a.lvalConversion(p, tok);
        try b.lvalConversion(p, tok);

        const a_vec = a.ty.is(.vector);
        const b_vec = b.ty.is(.vector);
        if (a_vec and b_vec) {
            if (a.ty.eql(b.ty, p.comp, false)) {
                return a.shouldEval(b, p);
            }
            return a.invalidBinTy(tok, b, p);
        } else if (a_vec) {
            if (b.coerceExtra(p, a.ty.elemType(), tok, .test_coerce)) {
                try b.saveValue(p);
                try b.implicitCast(p, .vector_splat, tok);
                return a.shouldEval(b, p);
            } else |er| switch (er) {
                error.CoercionFailed => return a.invalidBinTy(tok, b, p),
                else => |e| return e,
            }
        } else if (b_vec) {
            if (a.coerceExtra(p, b.ty.elemType(), tok, .test_coerce)) {
                try a.saveValue(p);
                try a.implicitCast(p, .vector_splat, tok);
                return a.shouldEval(b, p);
            } else |er| switch (er) {
                error.CoercionFailed => return a.invalidBinTy(tok, b, p),
                else => |e| return e,
            }
        }

        const a_int = a.ty.isInt();
        const b_int = b.ty.isInt();
        if (a_int and b_int) {
            try a.usualArithmeticConversion(b, p, tok);
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

            try a.usualArithmeticConversion(b, p, tok);
            return a.shouldEval(b, p);
        }
        if (kind == .arithmetic) return a.invalidBinTy(tok, b, p);

        const a_nullptr = a.ty.is(.nullptr_t);
        const b_nullptr = b.ty.is(.nullptr_t);
        const a_ptr = a.ty.isPtr();
        const b_ptr = b.ty.isPtr();
        const a_scalar = a_arithmetic or a_ptr;
        const b_scalar = b_arithmetic or b_ptr;
        switch (kind) {
            .boolean_logic => {
                if (!(a_scalar or a_nullptr) or !(b_scalar or b_nullptr)) return a.invalidBinTy(tok, b, p);

                // Do integer promotions but nothing else
                if (a_int) try a.intCast(p, a.ty.integerPromotion(p.comp), tok);
                if (b_int) try b.intCast(p, b.ty.integerPromotion(p.comp), tok);
                return a.shouldEval(b, p);
            },
            .relational, .equality => {
                if (kind == .equality and (a_nullptr or b_nullptr)) {
                    if (a_nullptr and b_nullptr) return a.shouldEval(b, p);
                    const nullptr_res = if (a_nullptr) a else b;
                    const other_res = if (a_nullptr) b else a;
                    if (other_res.ty.isPtr()) {
                        try nullptr_res.nullCast(p, other_res.ty, tok);
                        return other_res.shouldEval(nullptr_res, p);
                    } else if (other_res.val.isZero(p.comp)) {
                        other_res.val = Value.null;
                        try other_res.nullCast(p, nullptr_res.ty, tok);
                        return other_res.shouldEval(nullptr_res, p);
                    }
                    return a.invalidBinTy(tok, b, p);
                }
                // comparisons between floats and pointes not allowed
                if (!a_scalar or !b_scalar or (a_float and b_ptr) or (b_float and a_ptr))
                    return a.invalidBinTy(tok, b, p);

                if ((a_int or b_int) and !(a.val.isZero(p.comp) or b.val.isZero(p.comp))) {
                    try p.errStr(.comparison_ptr_int, tok, try p.typePairStr(a.ty, b.ty));
                } else if (a_ptr and b_ptr) {
                    if (!a.ty.isVoidStar() and !b.ty.isVoidStar() and !a.ty.eql(b.ty, p.comp, false))
                        try p.errStr(.comparison_distinct_ptr, tok, try p.typePairStr(a.ty, b.ty));
                } else if (a_ptr) {
                    try b.ptrCast(p, a.ty, tok);
                } else {
                    assert(b_ptr);
                    try a.ptrCast(p, b.ty, tok);
                }

                return a.shouldEval(b, p);
            },
            .conditional => {
                // doesn't matter what we return here, as the result is ignored
                if (a.ty.is(.void) or b.ty.is(.void)) {
                    try a.toVoid(p, tok);
                    try b.toVoid(p, tok);
                    return true;
                }
                if (a_nullptr and b_nullptr) return true;
                if ((a_ptr and b_int) or (a_int and b_ptr)) {
                    if (a.val.isZero(p.comp) or b.val.isZero(p.comp)) {
                        try a.nullCast(p, b.ty, tok);
                        try b.nullCast(p, a.ty, tok);
                        return true;
                    }
                    const int_ty = if (a_int) a else b;
                    const ptr_ty = if (a_ptr) a else b;
                    try p.errStr(.implicit_int_to_ptr, tok, try p.typePairStrExtra(int_ty.ty, " to ", ptr_ty.ty));
                    try int_ty.ptrCast(p, ptr_ty.ty, tok);

                    return true;
                }
                if (a_ptr and b_ptr) return a.adjustCondExprPtrs(tok, b, p);
                if ((a_ptr and b_nullptr) or (a_nullptr and b_ptr)) {
                    const nullptr_res = if (a_nullptr) a else b;
                    const ptr_res = if (a_nullptr) b else a;
                    try nullptr_res.nullCast(p, ptr_res.ty, tok);
                    return true;
                }
                if (a.ty.isRecord() and b.ty.isRecord() and a.ty.eql(b.ty, p.comp, false)) {
                    return true;
                }
                return a.invalidBinTy(tok, b, p);
            },
            .add => {
                // if both aren't arithmetic one should be pointer and the other an integer
                if (a_ptr == b_ptr or a_int == b_int) return a.invalidBinTy(tok, b, p);

                if (a.ty.isVoidStar() or b.ty.isVoidStar())
                    try p.errTok(.gnu_pointer_arith, tok);

                // Do integer promotions but nothing else
                if (a_int) try a.intCast(p, a.ty.integerPromotion(p.comp), tok);
                if (b_int) try b.intCast(p, b.ty.integerPromotion(p.comp), tok);

                // The result type is the type of the pointer operand
                if (a_int) a.ty = b.ty else b.ty = a.ty;
                return a.shouldEval(b, p);
            },
            .sub => {
                // if both aren't arithmetic then either both should be pointers or just a
                if (!a_ptr or !(b_ptr or b_int)) return a.invalidBinTy(tok, b, p);

                if (a.ty.isVoidStar())
                    try p.errTok(.gnu_pointer_arith, tok);

                if (a_ptr and b_ptr) {
                    if (!a.ty.eql(b.ty, p.comp, false)) try p.errStr(.incompatible_pointers, tok, try p.typePairStr(a.ty, b.ty));
                    if (a.ty.elemType().sizeof(p.comp) orelse 1 == 0) try p.errStr(.subtract_pointers_zero_elem_size, tok, try p.typeStr(a.ty.elemType()));
                    a.ty = p.comp.types.ptrdiff;
                }

                // Do integer promotion on b if needed
                if (b_int) try b.intCast(p, b.ty.integerPromotion(p.comp), tok);
                return a.shouldEval(b, p);
            },
            else => return a.invalidBinTy(tok, b, p),
        }
    }

    fn lvalConversion(res: *Result, p: *Parser, tok: TokenIndex) Error!void {
        if (res.ty.isFunc()) {
            if (res.ty.isInvalidFunc()) {
                res.ty = .{ .specifier = .invalid };
            } else {
                const elem_ty = try p.arena.create(Type);
                elem_ty.* = res.ty;
                res.ty.specifier = .pointer;
                res.ty.data = .{ .sub_type = elem_ty };
            }
            res.val = try p.pointerValue(res.node, .zero);
            try res.implicitCast(p, .function_to_pointer, tok);
        } else if (res.ty.isArray()) {
            res.val = try p.pointerValue(res.node, .zero);
            res.ty.decayArray();
            try res.implicitCast(p, .array_to_pointer, tok);
        } else if (!p.in_macro and p.tree.isLval(res.node)) {
            res.ty.qual = .{};
            try res.implicitCast(p, .lval_to_rval, tok);
        }
    }

    fn boolCast(res: *Result, p: *Parser, bool_ty: Type, tok: TokenIndex) Error!void {
        if (res.ty.isArray()) {
            if (res.val.is(.bytes, p.comp)) {
                try p.errStr(.string_literal_to_bool, tok, try p.typePairStrExtra(res.ty, " to ", bool_ty));
            } else {
                try p.errStr(.array_address_to_bool, tok, p.tokSlice(tok));
            }
            try res.lvalConversion(p, tok);
            res.val = Value.one;
            res.ty = bool_ty;
            try res.implicitCast(p, .pointer_to_bool, tok);
        } else if (res.ty.isPtr()) {
            res.val.boolCast(p.comp);
            res.ty = bool_ty;
            try res.implicitCast(p, .pointer_to_bool, tok);
        } else if (res.ty.isInt() and !res.ty.is(.bool)) {
            res.val.boolCast(p.comp);
            res.ty = bool_ty;
            try res.implicitCast(p, .int_to_bool, tok);
        } else if (res.ty.isFloat()) {
            const old_value = res.val;
            const value_change_kind = try res.val.floatToInt(bool_ty, p.comp);
            try res.floatToIntWarning(p, bool_ty, old_value, value_change_kind, tok);
            if (!res.ty.isReal()) {
                res.ty = res.ty.makeReal();
                try res.implicitCast(p, .complex_float_to_real, tok);
            }
            res.ty = bool_ty;
            try res.implicitCast(p, .float_to_bool, tok);
        }
    }

    fn intCast(res: *Result, p: *Parser, int_ty: Type, tok: TokenIndex) Error!void {
        if (int_ty.hasIncompleteSize()) return error.ParsingFailed; // Diagnostic already issued
        if (res.ty.is(.bool)) {
            res.ty = int_ty.makeReal();
            try res.implicitCast(p, .bool_to_int, tok);
            if (!int_ty.isReal()) {
                res.ty = int_ty;
                try res.implicitCast(p, .real_to_complex_int, tok);
            }
        } else if (res.ty.isPtr()) {
            res.val = .{};
            res.ty = int_ty.makeReal();
            try res.implicitCast(p, .pointer_to_int, tok);
            if (!int_ty.isReal()) {
                res.ty = int_ty;
                try res.implicitCast(p, .real_to_complex_int, tok);
            }
        } else if (res.ty.isFloat()) {
            const old_value = res.val;
            const value_change_kind = try res.val.floatToInt(int_ty, p.comp);
            try res.floatToIntWarning(p, int_ty, old_value, value_change_kind, tok);
            const old_real = res.ty.isReal();
            const new_real = int_ty.isReal();
            if (old_real and new_real) {
                res.ty = int_ty;
                try res.implicitCast(p, .float_to_int, tok);
            } else if (old_real) {
                res.ty = int_ty.makeReal();
                try res.implicitCast(p, .float_to_int, tok);
                res.ty = int_ty;
                try res.implicitCast(p, .real_to_complex_int, tok);
            } else if (new_real) {
                res.ty = res.ty.makeReal();
                try res.implicitCast(p, .complex_float_to_real, tok);
                res.ty = int_ty;
                try res.implicitCast(p, .float_to_int, tok);
            } else {
                res.ty = int_ty;
                try res.implicitCast(p, .complex_float_to_complex_int, tok);
            }
        } else if (!res.ty.eql(int_ty, p.comp, true)) {
            const old_val = res.val;
            const value_change_kind = try res.val.intCast(int_ty, p.comp);
            switch (value_change_kind) {
                .none => {},
                .truncated => try p.errStr(.int_value_changed, tok, try p.valueChangedStr(res, old_val, int_ty)),
                .sign_changed => try p.errStr(.sign_conversion, tok, try p.typePairStrExtra(res.ty, " to ", int_ty)),
            }

            const old_real = res.ty.isReal();
            const new_real = int_ty.isReal();
            if (old_real and new_real) {
                res.ty = int_ty;
                try res.implicitCast(p, .int_cast, tok);
            } else if (old_real) {
                const real_int_ty = int_ty.makeReal();
                if (!res.ty.eql(real_int_ty, p.comp, false)) {
                    res.ty = real_int_ty;
                    try res.implicitCast(p, .int_cast, tok);
                }
                res.ty = int_ty;
                try res.implicitCast(p, .real_to_complex_int, tok);
            } else if (new_real) {
                res.ty = res.ty.makeReal();
                try res.implicitCast(p, .complex_int_to_real, tok);
                res.ty = int_ty;
                try res.implicitCast(p, .int_cast, tok);
            } else {
                res.ty = int_ty;
                try res.implicitCast(p, .complex_int_cast, tok);
            }
        }
    }

    fn floatToIntWarning(
        res: *Result,
        p: *Parser,
        int_ty: Type,
        old_value: Value,
        change_kind: Value.FloatToIntChangeKind,
        tok: TokenIndex,
    ) !void {
        switch (change_kind) {
            .none => return p.errStr(.float_to_int, tok, try p.typePairStrExtra(res.ty, " to ", int_ty)),
            .out_of_range => return p.errStr(.float_out_of_range, tok, try p.typePairStrExtra(res.ty, " to ", int_ty)),
            .overflow => return p.errStr(.float_overflow_conversion, tok, try p.typePairStrExtra(res.ty, " to ", int_ty)),
            .nonzero_to_zero => return p.errStr(.float_zero_conversion, tok, try p.valueChangedStr(res, old_value, int_ty)),
            .value_changed => return p.errStr(.float_value_changed, tok, try p.valueChangedStr(res, old_value, int_ty)),
        }
    }

    fn floatCast(res: *Result, p: *Parser, float_ty: Type, tok: TokenIndex) Error!void {
        if (res.ty.is(.bool)) {
            try res.val.intToFloat(float_ty, p.comp);
            res.ty = float_ty.makeReal();
            try res.implicitCast(p, .bool_to_float, tok);
            if (!float_ty.isReal()) {
                res.ty = float_ty;
                try res.implicitCast(p, .real_to_complex_float, tok);
            }
        } else if (res.ty.isInt()) {
            try res.val.intToFloat(float_ty, p.comp);
            const old_real = res.ty.isReal();
            const new_real = float_ty.isReal();
            if (old_real and new_real) {
                res.ty = float_ty;
                try res.implicitCast(p, .int_to_float, tok);
            } else if (old_real) {
                res.ty = float_ty.makeReal();
                try res.implicitCast(p, .int_to_float, tok);
                res.ty = float_ty;
                try res.implicitCast(p, .real_to_complex_float, tok);
            } else if (new_real) {
                res.ty = res.ty.makeReal();
                try res.implicitCast(p, .complex_int_to_real, tok);
                res.ty = float_ty;
                try res.implicitCast(p, .int_to_float, tok);
            } else {
                res.ty = float_ty;
                try res.implicitCast(p, .complex_int_to_complex_float, tok);
            }
        } else if (!res.ty.eql(float_ty, p.comp, true)) {
            try res.val.floatCast(float_ty, p.comp);
            const old_real = res.ty.isReal();
            const new_real = float_ty.isReal();
            if (old_real and new_real) {
                res.ty = float_ty;
                try res.implicitCast(p, .float_cast, tok);
            } else if (old_real) {
                if (res.ty.floatRank() != float_ty.floatRank()) {
                    res.ty = float_ty.makeReal();
                    try res.implicitCast(p, .float_cast, tok);
                }
                res.ty = float_ty;
                try res.implicitCast(p, .real_to_complex_float, tok);
            } else if (new_real) {
                res.ty = res.ty.makeReal();
                try res.implicitCast(p, .complex_float_to_real, tok);
                if (res.ty.floatRank() != float_ty.floatRank()) {
                    res.ty = float_ty;
                    try res.implicitCast(p, .float_cast, tok);
                }
            } else {
                res.ty = float_ty;
                try res.implicitCast(p, .complex_float_cast, tok);
            }
        }
    }

    /// Converts a bool or integer to a pointer
    fn ptrCast(res: *Result, p: *Parser, ptr_ty: Type, tok: TokenIndex) Error!void {
        if (res.ty.is(.bool)) {
            res.ty = ptr_ty;
            try res.implicitCast(p, .bool_to_pointer, tok);
        } else if (res.ty.isInt()) {
            _ = try res.val.intCast(ptr_ty, p.comp);
            res.ty = ptr_ty;
            try res.implicitCast(p, .int_to_pointer, tok);
        }
    }

    /// Convert pointer to one with a different child type
    fn ptrChildTypeCast(res: *Result, p: *Parser, ptr_ty: Type, tok: TokenIndex) Error!void {
        res.ty = ptr_ty;
        return res.implicitCast(p, .bitcast, tok);
    }

    fn toVoid(res: *Result, p: *Parser, tok: TokenIndex) Error!void {
        if (!res.ty.is(.void)) {
            res.ty = .{ .specifier = .void };
            try res.implicitCast(p, .to_void, tok);
        }
    }

    fn nullCast(res: *Result, p: *Parser, ptr_ty: Type, tok: TokenIndex) Error!void {
        if (!res.ty.is(.nullptr_t) and !res.val.isZero(p.comp)) return;
        res.ty = ptr_ty;
        try res.implicitCast(p, .null_to_pointer, tok);
    }

    fn usualUnaryConversion(res: *Result, p: *Parser, tok: TokenIndex) Error!void {
        if (res.ty.isFloat()) fp_eval: {
            const eval_method = p.comp.langopts.fp_eval_method orelse break :fp_eval;
            switch (eval_method) {
                .source => {},
                .indeterminate => unreachable,
                .double => {
                    if (res.ty.floatRank() < (Type{ .specifier = .double }).floatRank()) {
                        const spec: Type.Specifier = if (res.ty.isReal()) .double else .complex_double;
                        return res.floatCast(p, .{ .specifier = spec }, tok);
                    }
                },
                .extended => {
                    if (res.ty.floatRank() < (Type{ .specifier = .long_double }).floatRank()) {
                        const spec: Type.Specifier = if (res.ty.isReal()) .long_double else .complex_long_double;
                        return res.floatCast(p, .{ .specifier = spec }, tok);
                    }
                },
            }
        }

        if (res.ty.is(.fp16) and !p.comp.langopts.use_native_half_type) {
            return res.floatCast(p, .{ .specifier = .float }, tok);
        }
        if (res.ty.isInt() and !p.in_macro) {
            if (p.tree.bitfieldWidth(res.node, true)) |width| {
                if (res.ty.bitfieldPromotion(p.comp, width)) |promotion_ty| {
                    return res.intCast(p, promotion_ty, tok);
                }
            }
            return res.intCast(p, res.ty.integerPromotion(p.comp), tok);
        }
    }

    fn usualArithmeticConversion(a: *Result, b: *Result, p: *Parser, tok: TokenIndex) Error!void {
        try a.usualUnaryConversion(p, tok);
        try b.usualUnaryConversion(p, tok);

        // if either is a float cast to that type
        if (a.ty.isFloat() or b.ty.isFloat()) {
            const float_types = [6][2]Type.Specifier{
                .{ .complex_float128, .float128 },
                .{ .complex_long_double, .long_double },
                .{ .complex_double, .double },
                .{ .complex_float, .float },
                // No `_Complex __fp16` type
                .{ .invalid, .fp16 },
                .{ .complex_float16, .float16 },
            };
            const a_spec = a.ty.canonicalize(.standard).specifier;
            const b_spec = b.ty.canonicalize(.standard).specifier;
            for (float_types) |ft| {
                if (try a.floatConversion(b, a_spec, b_spec, p, ft, tok)) return;
            }
            unreachable;
        }

        if (a.ty.eql(b.ty, p.comp, true)) {
            // cast to promoted type
            try a.intCast(p, a.ty, tok);
            try b.intCast(p, b.ty, tok);
            return;
        }

        const target = a.ty.integerConversion(b.ty, p.comp);
        if (!target.isReal()) {
            try a.saveValue(p);
            try b.saveValue(p);
        }
        try a.intCast(p, target, tok);
        try b.intCast(p, target, tok);
    }

    fn floatConversion(
        a: *Result,
        b: *Result,
        a_spec: Type.Specifier,
        b_spec: Type.Specifier,
        p: *Parser,
        pair: [2]Type.Specifier,
        tok: TokenIndex,
    ) !bool {
        if (a_spec == pair[0] or a_spec == pair[1] or
            b_spec == pair[0] or b_spec == pair[1])
        {
            const both_real = a.ty.isReal() and b.ty.isReal();
            const res_spec = pair[@intFromBool(both_real)];
            const ty = Type{ .specifier = res_spec };
            try a.floatCast(p, ty, tok);
            try b.floatCast(p, ty, tok);
            return true;
        }
        return false;
    }

    fn invalidBinTy(a: *Result, tok: TokenIndex, b: *Result, p: *Parser) Error!bool {
        try p.errStr(.invalid_bin_types, tok, try p.typePairStr(a.ty, b.ty));
        a.val = .{};
        b.val = .{};
        a.ty = Type.invalid;
        return false;
    }

    fn shouldEval(a: *Result, b: *Result, p: *Parser) Error!bool {
        if (p.no_eval) return false;
        if (a.val.opt_ref != .none and b.val.opt_ref != .none)
            return true;

        try a.saveValue(p);
        try b.saveValue(p);
        return p.no_eval;
    }

    /// Saves value and replaces it with `.unavailable`.
    fn saveValue(res: *Result, p: *Parser) !void {
        assert(!p.in_macro);
        if (res.val.opt_ref == .none or res.val.opt_ref == .null) return;
        if (!p.in_macro) try p.tree.value_map.put(p.gpa, res.node, res.val);
        res.val = .{};
    }

    /// Saves value without altering the result.
    fn putValue(res: *const Result, p: *Parser) !void {
        if (res.val.opt_ref == .none or res.val.opt_ref == .null) return;
        if (!p.in_macro) try p.tree.value_map.put(p.gpa, res.node, res.val);
    }

    fn castType(res: *Result, p: *Parser, to: Type, operand_tok: TokenIndex, l_paren: TokenIndex) !void {
        var cast_kind: Node.Cast.Kind = undefined;

        if (to.is(.void)) {
            // everything can cast to void
            cast_kind = .to_void;
            res.val = .{};
        } else if (to.is(.nullptr_t)) {
            if (res.ty.is(.nullptr_t)) {
                cast_kind = .no_op;
            } else {
                try p.errStr(.invalid_object_cast, l_paren, try p.typePairStrExtra(res.ty, " to ", to));
                return error.ParsingFailed;
            }
        } else if (res.ty.is(.nullptr_t)) {
            if (to.is(.bool)) {
                try res.nullCast(p, res.ty, l_paren);
                res.val.boolCast(p.comp);
                res.ty = .{ .specifier = .bool };
                try res.implicitCast(p, .pointer_to_bool, l_paren);
                try res.saveValue(p);
            } else if (to.isPtr()) {
                try res.nullCast(p, to, l_paren);
            } else {
                try p.errStr(.invalid_object_cast, l_paren, try p.typePairStrExtra(res.ty, " to ", to));
                return error.ParsingFailed;
            }
            cast_kind = .no_op;
        } else if (res.val.isZero(p.comp) and to.isPtr()) {
            cast_kind = .null_to_pointer;
        } else if (to.isScalar()) cast: {
            const old_float = res.ty.isFloat();
            const new_float = to.isFloat();

            if (new_float and res.ty.isPtr()) {
                try p.errStr(.invalid_cast_to_float, l_paren, try p.typeStr(to));
                return error.ParsingFailed;
            } else if (old_float and to.isPtr()) {
                try p.errStr(.invalid_cast_to_pointer, l_paren, try p.typeStr(res.ty));
                return error.ParsingFailed;
            }
            const old_real = res.ty.isReal();
            const new_real = to.isReal();

            if (to.eql(res.ty, p.comp, false)) {
                cast_kind = .no_op;
            } else if (to.is(.bool)) {
                if (res.ty.isPtr()) {
                    cast_kind = .pointer_to_bool;
                } else if (res.ty.isInt()) {
                    if (!old_real) {
                        res.ty = res.ty.makeReal();
                        try res.implicitCast(p, .complex_int_to_real, l_paren);
                    }
                    cast_kind = .int_to_bool;
                } else if (old_float) {
                    if (!old_real) {
                        res.ty = res.ty.makeReal();
                        try res.implicitCast(p, .complex_float_to_real, l_paren);
                    }
                    cast_kind = .float_to_bool;
                }
            } else if (to.isInt()) {
                if (res.ty.is(.bool)) {
                    if (!new_real) {
                        res.ty = to.makeReal();
                        try res.implicitCast(p, .bool_to_int, l_paren);
                        cast_kind = .real_to_complex_int;
                    } else {
                        cast_kind = .bool_to_int;
                    }
                } else if (res.ty.isInt()) {
                    if (old_real and new_real) {
                        cast_kind = .int_cast;
                    } else if (old_real) {
                        res.ty = to.makeReal();
                        try res.implicitCast(p, .int_cast, l_paren);
                        cast_kind = .real_to_complex_int;
                    } else if (new_real) {
                        res.ty = res.ty.makeReal();
                        try res.implicitCast(p, .complex_int_to_real, l_paren);
                        cast_kind = .int_cast;
                    } else {
                        cast_kind = .complex_int_cast;
                    }
                } else if (res.ty.isPtr()) {
                    if (!new_real) {
                        res.ty = to.makeReal();
                        try res.implicitCast(p, .pointer_to_int, l_paren);
                        cast_kind = .real_to_complex_int;
                    } else {
                        cast_kind = .pointer_to_int;
                        res.val = .{};
                    }
                } else if (old_real and new_real) {
                    cast_kind = .float_to_int;
                } else if (old_real) {
                    res.ty = to.makeReal();
                    try res.implicitCast(p, .float_to_int, l_paren);
                    cast_kind = .real_to_complex_int;
                } else if (new_real) {
                    res.ty = res.ty.makeReal();
                    try res.implicitCast(p, .complex_float_to_real, l_paren);
                    cast_kind = .float_to_int;
                } else {
                    cast_kind = .complex_float_to_complex_int;
                }
            } else if (to.isPtr()) {
                if (res.ty.isArray())
                    cast_kind = .array_to_pointer
                else if (res.ty.isPtr())
                    cast_kind = .bitcast
                else if (res.ty.isFunc())
                    cast_kind = .function_to_pointer
                else if (res.ty.is(.bool))
                    cast_kind = .bool_to_pointer
                else if (res.ty.isInt()) {
                    if (!old_real) {
                        res.ty = res.ty.makeReal();
                        try res.implicitCast(p, .complex_int_to_real, l_paren);
                    }
                    cast_kind = .int_to_pointer;
                } else {
                    try p.errStr(.cond_expr_type, operand_tok, try p.typeStr(res.ty));
                    return error.ParsingFailed;
                }
            } else if (new_float) {
                if (res.ty.is(.bool)) {
                    if (!new_real) {
                        res.ty = to.makeReal();
                        try res.implicitCast(p, .bool_to_float, l_paren);
                        cast_kind = .real_to_complex_float;
                    } else {
                        cast_kind = .bool_to_float;
                    }
                } else if (res.ty.isInt()) {
                    if (old_real and new_real) {
                        cast_kind = .int_to_float;
                    } else if (old_real) {
                        res.ty = to.makeReal();
                        try res.implicitCast(p, .int_to_float, l_paren);
                        cast_kind = .real_to_complex_float;
                    } else if (new_real) {
                        res.ty = res.ty.makeReal();
                        try res.implicitCast(p, .complex_int_to_real, l_paren);
                        cast_kind = .int_to_float;
                    } else {
                        cast_kind = .complex_int_to_complex_float;
                    }
                } else if (old_real and new_real) {
                    cast_kind = .float_cast;
                } else if (old_real) {
                    res.ty = to.makeReal();
                    try res.implicitCast(p, .float_cast, l_paren);
                    cast_kind = .real_to_complex_float;
                } else if (new_real) {
                    res.ty = res.ty.makeReal();
                    try res.implicitCast(p, .complex_float_to_real, l_paren);
                    cast_kind = .float_cast;
                } else {
                    cast_kind = .complex_float_cast;
                }
            }
            if (res.val.opt_ref == .none) break :cast;

            const old_int = res.ty.isInt() or res.ty.isPtr();
            const new_int = to.isInt() or to.isPtr();
            if (to.is(.bool)) {
                res.val.boolCast(p.comp);
            } else if (old_float and new_int) {
                if (to.hasIncompleteSize()) {
                    try p.errStr(.cast_to_incomplete_type, l_paren, try p.typeStr(to));
                    return error.ParsingFailed;
                }
                // Explicit cast, no conversion warning
                _ = try res.val.floatToInt(to, p.comp);
            } else if (new_float and old_int) {
                try res.val.intToFloat(to, p.comp);
            } else if (new_float and old_float) {
                try res.val.floatCast(to, p.comp);
            } else if (old_int and new_int) {
                if (to.hasIncompleteSize()) {
                    try p.errStr(.cast_to_incomplete_type, l_paren, try p.typeStr(to));
                    return error.ParsingFailed;
                }
                _ = try res.val.intCast(to, p.comp);
            }
        } else if (to.get(.@"union")) |union_ty| {
            if (union_ty.data.record.hasFieldOfType(res.ty, p.comp)) {
                cast_kind = .union_cast;
                try p.errTok(.gnu_union_cast, l_paren);
            } else {
                if (union_ty.data.record.isIncomplete()) {
                    try p.errStr(.cast_to_incomplete_type, l_paren, try p.typeStr(to));
                } else {
                    try p.errStr(.invalid_union_cast, l_paren, try p.typeStr(res.ty));
                }
                return error.ParsingFailed;
            }
        } else {
            if (to.is(.auto_type)) {
                try p.errTok(.invalid_cast_to_auto_type, l_paren);
            } else {
                try p.errStr(.invalid_cast_type, l_paren, try p.typeStr(to));
            }
            return error.ParsingFailed;
        }
        if (to.anyQual()) try p.errStr(.qual_cast, l_paren, try p.typeStr(to));
        if (to.isInt() and res.ty.isPtr() and to.sizeCompare(res.ty, p.comp) == .lt) {
            try p.errStr(.cast_to_smaller_int, l_paren, try p.typePairStrExtra(to, " from ", res.ty));
        }
        res.ty = to;
        res.ty.qual = .{};
        res.node = try p.addNode(.{
            .explicit_cast = .{
                .l_paren = l_paren,
                .type = res.ty,
                .operand = res.node,
                .kind = cast_kind,
            },
        });
    }

    fn intFitsInType(res: Result, p: *Parser, ty: Type) !bool {
        const max_int = try Value.maxInt(ty, p.comp);
        const min_int = try Value.minInt(ty, p.comp);
        return res.val.compare(.lte, max_int, p.comp) and
            (res.ty.isUnsignedInt(p.comp) or res.val.compare(.gte, min_int, p.comp));
    }

    const CoerceContext = union(enum) {
        assign,
        init,
        ret,
        arg: TokenIndex,
        test_coerce,

        fn note(c: CoerceContext, p: *Parser) !void {
            switch (c) {
                .arg => |tok| try p.errTok(.parameter_here, tok),
                .test_coerce => unreachable,
                else => {},
            }
        }

        fn typePairStr(c: CoerceContext, p: *Parser, dest_ty: Type, src_ty: Type) ![]const u8 {
            switch (c) {
                .assign, .init => return p.typePairStrExtra(dest_ty, " from incompatible type ", src_ty),
                .ret => return p.typePairStrExtra(src_ty, " from a function with incompatible result type ", dest_ty),
                .arg => return p.typePairStrExtra(src_ty, " to parameter of incompatible type ", dest_ty),
                .test_coerce => unreachable,
            }
        }
    };

    /// Perform assignment-like coercion to `dest_ty`.
    fn coerce(res: *Result, p: *Parser, dest_ty: Type, tok: TokenIndex, c: CoerceContext) Error!void {
        if (res.ty.specifier == .invalid or dest_ty.specifier == .invalid) {
            res.ty = Type.invalid;
            return;
        }
        return res.coerceExtra(p, dest_ty, tok, c) catch |er| switch (er) {
            error.CoercionFailed => unreachable,
            else => |e| return e,
        };
    }

    fn coerceExtra(
        res: *Result,
        p: *Parser,
        dest_ty: Type,
        tok: TokenIndex,
        c: CoerceContext,
    ) (Error || error{CoercionFailed})!void {
        // Subject of the coercion does not need to be qualified.
        var unqual_ty = dest_ty.canonicalize(.standard);
        unqual_ty.qual = .{};
        if (unqual_ty.is(.nullptr_t)) {
            if (res.ty.is(.nullptr_t)) return;
        } else if (unqual_ty.is(.bool)) {
            if (res.ty.isScalar() and !res.ty.is(.nullptr_t)) {
                // this is ridiculous but it's what clang does
                try res.boolCast(p, unqual_ty, tok);
                return;
            }
        } else if (unqual_ty.isInt()) {
            if (res.ty.isInt() or res.ty.isFloat()) {
                try res.intCast(p, unqual_ty, tok);
                return;
            } else if (res.ty.isPtr()) {
                if (c == .test_coerce) return error.CoercionFailed;
                try p.errStr(.implicit_ptr_to_int, tok, try p.typePairStrExtra(res.ty, " to ", dest_ty));
                try c.note(p);
                try res.intCast(p, unqual_ty, tok);
                return;
            }
        } else if (unqual_ty.isFloat()) {
            if (res.ty.isInt() or res.ty.isFloat()) {
                try res.floatCast(p, unqual_ty, tok);
                return;
            }
        } else if (unqual_ty.isPtr()) {
            if (res.ty.is(.nullptr_t) or res.val.isZero(p.comp)) {
                try res.nullCast(p, dest_ty, tok);
                return;
            } else if (res.ty.isInt() and res.ty.isReal()) {
                if (c == .test_coerce) return error.CoercionFailed;
                try p.errStr(.implicit_int_to_ptr, tok, try p.typePairStrExtra(res.ty, " to ", dest_ty));
                try c.note(p);
                try res.ptrCast(p, unqual_ty, tok);
                return;
            } else if (res.ty.isVoidStar() or unqual_ty.eql(res.ty, p.comp, true)) {
                return; // ok
            } else if (unqual_ty.isVoidStar() and res.ty.isPtr() or (res.ty.isInt() and res.ty.isReal())) {
                return; // ok
            } else if (unqual_ty.eql(res.ty, p.comp, false)) {
                if (!unqual_ty.elemType().qual.hasQuals(res.ty.elemType().qual)) {
                    try p.errStr(switch (c) {
                        .assign => .ptr_assign_discards_quals,
                        .init => .ptr_init_discards_quals,
                        .ret => .ptr_ret_discards_quals,
                        .arg => .ptr_arg_discards_quals,
                        .test_coerce => return error.CoercionFailed,
                    }, tok, try c.typePairStr(p, dest_ty, res.ty));
                }
                try res.ptrCast(p, unqual_ty, tok);
                return;
            } else if (res.ty.isPtr()) {
                const different_sign_only = unqual_ty.elemType().sameRankDifferentSign(res.ty.elemType(), p.comp);
                try p.errStr(switch (c) {
                    .assign => ([2]Diagnostics.Tag{ .incompatible_ptr_assign, .incompatible_ptr_assign_sign })[@intFromBool(different_sign_only)],
                    .init => ([2]Diagnostics.Tag{ .incompatible_ptr_init, .incompatible_ptr_init_sign })[@intFromBool(different_sign_only)],
                    .ret => ([2]Diagnostics.Tag{ .incompatible_return, .incompatible_return_sign })[@intFromBool(different_sign_only)],
                    .arg => ([2]Diagnostics.Tag{ .incompatible_ptr_arg, .incompatible_ptr_arg_sign })[@intFromBool(different_sign_only)],
                    .test_coerce => return error.CoercionFailed,
                }, tok, try c.typePairStr(p, dest_ty, res.ty));
                try c.note(p);
                try res.ptrChildTypeCast(p, unqual_ty, tok);
                return;
            }
        } else if (unqual_ty.isRecord()) {
            if (unqual_ty.eql(res.ty, p.comp, false)) {
                return; // ok
            }

            if (c == .arg) if (unqual_ty.get(.@"union")) |union_ty| {
                if (dest_ty.hasAttribute(.transparent_union)) transparent_union: {
                    res.coerceExtra(p, union_ty.data.record.fields[0].ty, tok, .test_coerce) catch |er| switch (er) {
                        error.CoercionFailed => break :transparent_union,
                        else => |e| return e,
                    };
                    res.node = try p.addNode(.{ .union_init_expr = .{
                        .field_index = 0,
                        .initializer = res.node,
                        .l_brace_tok = tok,
                        .union_type = dest_ty,
                    } });
                    res.ty = dest_ty;
                    return;
                }
            };
        } else if (unqual_ty.is(.vector)) {
            if (unqual_ty.eql(res.ty, p.comp, false)) {
                return; // ok
            }
        } else {
            if (c == .assign and (unqual_ty.isArray() or unqual_ty.isFunc())) {
                try p.errTok(.not_assignable, tok);
                return;
            } else if (c == .test_coerce) {
                return error.CoercionFailed;
            }
            // This case should not be possible and an error should have already been emitted but we
            // might still have attempted to parse further so return error.ParsingFailed here to stop.
            return error.ParsingFailed;
        }

        try p.errStr(switch (c) {
            .assign => .incompatible_assign,
            .init => .incompatible_init,
            .ret => .incompatible_return,
            .arg => .incompatible_arg,
            .test_coerce => return error.CoercionFailed,
        }, tok, try c.typePairStr(p, dest_ty, res.ty));
        try c.note(p);
    }
};

fn expect(p: *Parser, comptime func: fn (*Parser) Error!?Result) Error!Result {
    return p.expectResult(try func(p));
}

fn expectResult(p: *Parser, res: ?Result) Error!Result {
    return res orelse {
        try p.errTok(.expected_expr, p.tok_i);
        return error.ParsingFailed;
    };
}

/// expr : assignExpr (',' assignExpr)*
fn expr(p: *Parser) Error!?Result {
    var expr_start = p.tok_i;
    var err_start = p.comp.diagnostics.list.items.len;
    var lhs = (try p.assignExpr()) orelse {
        if (p.tok_ids[p.tok_i] == .comma) _ = try p.expectResult(null);
        return null;
    };
    while (p.eatToken(.comma)) |comma| {
        try lhs.maybeWarnUnused(p, expr_start, err_start);
        expr_start = p.tok_i;
        err_start = p.comp.diagnostics.list.items.len;

        var rhs = try p.expect(assignExpr);
        try rhs.lvalConversion(p, expr_start);
        lhs.val = rhs.val;
        lhs.ty = rhs.ty;
        try lhs.bin(p, .comma_expr, rhs, comma);
    }
    return lhs;
}

fn eatTag(p: *Parser, id: Token.Id) ?std.meta.Tag(Node) {
    if (p.eatToken(id)) |_| return switch (id) {
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
    } else return null;
}

/// assignExpr
///  : condExpr
///  | unExpr ('=' | '*=' | '/=' | '%=' | '+=' | '-=' | '<<=' | '>>=' | '&=' | '^=' | '|=') assignExpr
fn assignExpr(p: *Parser) Error!?Result {
    var lhs = (try p.condExpr()) orelse return null;

    const tok = p.tok_i;
    const tag = p.eatTag(.equal) orelse
        p.eatTag(.asterisk_equal) orelse
        p.eatTag(.slash_equal) orelse
        p.eatTag(.percent_equal) orelse
        p.eatTag(.plus_equal) orelse
        p.eatTag(.minus_equal) orelse
        p.eatTag(.angle_bracket_angle_bracket_left_equal) orelse
        p.eatTag(.angle_bracket_angle_bracket_right_equal) orelse
        p.eatTag(.ampersand_equal) orelse
        p.eatTag(.caret_equal) orelse
        p.eatTag(.pipe_equal) orelse return lhs;

    var rhs = try p.expect(assignExpr);
    try rhs.lvalConversion(p, tok);

    var is_const: bool = undefined;
    if (!p.tree.isLvalExtra(lhs.node, &is_const) or is_const) {
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
            if (rhs.val.isZero(p.comp) and lhs.ty.isInt() and rhs.ty.isInt()) {
                switch (tag) {
                    .div_assign_expr => try p.errStr(.division_by_zero, tok, "division"),
                    .mod_assign_expr => try p.errStr(.division_by_zero, tok, "remainder"),
                    else => {},
                }
            }
            _ = try lhs_copy.adjustTypes(tok, &rhs, p, if (tag == .mod_assign_expr) .integer else .arithmetic);
            try lhs.bin(p, tag, rhs, tok);
            return lhs;
        },
        .sub_assign_expr,
        .add_assign_expr,
        => {
            if (lhs.ty.isPtr() and rhs.ty.isInt()) {
                try rhs.ptrCast(p, lhs.ty, tok);
            } else {
                _ = try lhs_copy.adjustTypes(tok, &rhs, p, .arithmetic);
            }
            try lhs.bin(p, tag, rhs, tok);
            return lhs;
        },
        .shl_assign_expr,
        .shr_assign_expr,
        .bit_and_assign_expr,
        .bit_xor_assign_expr,
        .bit_or_assign_expr,
        => {
            _ = try lhs_copy.adjustTypes(tok, &rhs, p, .integer);
            try lhs.bin(p, tag, rhs, tok);
            return lhs;
        },
        else => unreachable,
    }

    try rhs.coerce(p, lhs.ty, tok, .assign);

    try lhs.bin(p, tag, rhs, tok);
    return lhs;
}

/// Returns a parse error if the expression is not an integer constant
/// integerConstExpr : constExpr
fn integerConstExpr(p: *Parser, decl_folding: ConstDeclFoldingMode) Error!Result {
    const start = p.tok_i;
    const res = try p.constExpr(decl_folding);
    if (!res.ty.isInt() and res.ty.specifier != .invalid) {
        try p.errTok(.expected_integer_constant_expr, start);
        return error.ParsingFailed;
    }
    return res;
}

/// Caller is responsible for issuing a diagnostic if result is invalid/unavailable
/// constExpr : condExpr
fn constExpr(p: *Parser, decl_folding: ConstDeclFoldingMode) Error!Result {
    const const_decl_folding = p.const_decl_folding;
    defer p.const_decl_folding = const_decl_folding;
    p.const_decl_folding = decl_folding;

    const res = try p.expect(condExpr);

    if (res.ty.specifier == .invalid or res.val.opt_ref == .none) return res;

    // saveValue sets val to unavailable
    var copy = res;
    try copy.saveValue(p);
    return res;
}

/// condExpr : lorExpr ('?' expression? ':' condExpr)?
fn condExpr(p: *Parser) Error!?Result {
    const cond_tok = p.tok_i;
    var cond = (try p.lorExpr()) orelse return null;
    if (p.eatToken(.question_mark) == null) return cond;
    try cond.lvalConversion(p, cond_tok);
    const saved_eval = p.no_eval;

    if (!cond.ty.isScalar()) {
        try p.errStr(.cond_expr_type, cond_tok, try p.typeStr(cond.ty));
        return error.ParsingFailed;
    }

    // Prepare for possible binary conditional expression.
    const maybe_colon = p.eatToken(.colon);

    // Depending on the value of the condition, avoid evaluating unreachable branches.
    var then_expr = blk: {
        defer p.no_eval = saved_eval;
        if (cond.val.opt_ref != .none and !cond.val.toBool(p.comp)) p.no_eval = true;
        break :blk try p.expect(expr);
    };

    // If we saw a colon then this is a binary conditional expression.
    if (maybe_colon) |colon| {
        var cond_then = cond;
        cond_then.node = try p.addNode(.{
            .cond_dummy_expr = .{
                .op_tok = colon,
                .operand = cond.node,
                .type = cond.ty,
            },
        });
        _ = try cond_then.adjustTypes(colon, &then_expr, p, .conditional);
        cond.ty = then_expr.ty;
        cond.node = try p.addNode(.{
            .binary_cond_expr = .{
                .cond_tok = cond_tok,
                .cond = cond.node,
                .then_expr = cond_then.node,
                .else_expr = then_expr.node,
                .type = cond.ty,
            },
        });
        return cond;
    }

    const colon = try p.expectToken(.colon);
    var else_expr = blk: {
        defer p.no_eval = saved_eval;
        if (cond.val.opt_ref != .none and cond.val.toBool(p.comp)) p.no_eval = true;
        break :blk try p.expect(condExpr);
    };

    _ = try then_expr.adjustTypes(colon, &else_expr, p, .conditional);

    if (cond.val.opt_ref != .none) {
        cond.val = if (cond.val.toBool(p.comp)) then_expr.val else else_expr.val;
    } else {
        try then_expr.saveValue(p);
        try else_expr.saveValue(p);
    }
    cond.ty = then_expr.ty;
    cond.node = try p.addNode(.{
        .cond_expr = .{
            .cond_tok = cond_tok,
            .type = cond.ty,
            .cond = cond.node,
            .then_expr = then_expr.node,
            .else_expr = else_expr.node,
        },
    });
    return cond;
}

/// lorExpr : landExpr ('||' landExpr)*
fn lorExpr(p: *Parser) Error!?Result {
    var lhs = (try p.landExpr()) orelse return null;
    const saved_eval = p.no_eval;
    defer p.no_eval = saved_eval;

    while (p.eatToken(.pipe_pipe)) |tok| {
        if (lhs.val.opt_ref != .none and lhs.val.toBool(p.comp)) p.no_eval = true;
        var rhs = try p.expect(landExpr);

        if (try lhs.adjustTypes(tok, &rhs, p, .boolean_logic)) {
            const res = lhs.val.toBool(p.comp) or rhs.val.toBool(p.comp);
            lhs.val = Value.fromBool(res);
        } else {
            lhs.val.boolCast(p.comp);
        }
        try lhs.boolRes(p, .bool_or_expr, rhs, tok);
    }
    return lhs;
}

/// landExpr : orExpr ('&&' orExpr)*
fn landExpr(p: *Parser) Error!?Result {
    var lhs = (try p.orExpr()) orelse return null;
    const saved_eval = p.no_eval;
    defer p.no_eval = saved_eval;

    while (p.eatToken(.ampersand_ampersand)) |tok| {
        if (lhs.val.opt_ref != .none and !lhs.val.toBool(p.comp)) p.no_eval = true;
        var rhs = try p.expect(orExpr);

        if (try lhs.adjustTypes(tok, &rhs, p, .boolean_logic)) {
            const res = lhs.val.toBool(p.comp) and rhs.val.toBool(p.comp);
            lhs.val = Value.fromBool(res);
        } else {
            lhs.val.boolCast(p.comp);
        }
        try lhs.boolRes(p, .bool_and_expr, rhs, tok);
    }
    return lhs;
}

/// orExpr : xorExpr ('|' xorExpr)*
fn orExpr(p: *Parser) Error!?Result {
    var lhs = (try p.xorExpr()) orelse return null;
    while (p.eatToken(.pipe)) |tok| {
        var rhs = try p.expect(xorExpr);

        if (try lhs.adjustTypes(tok, &rhs, p, .integer)) {
            lhs.val = try lhs.val.bitOr(rhs.val, p.comp);
        }
        try lhs.bin(p, .bit_or_expr, rhs, tok);
    }
    return lhs;
}

/// xorExpr : andExpr ('^' andExpr)*
fn xorExpr(p: *Parser) Error!?Result {
    var lhs = (try p.andExpr()) orelse return null;
    while (p.eatToken(.caret)) |tok| {
        var rhs = try p.expect(andExpr);

        if (try lhs.adjustTypes(tok, &rhs, p, .integer)) {
            lhs.val = try lhs.val.bitXor(rhs.val, p.comp);
        }
        try lhs.bin(p, .bit_xor_expr, rhs, tok);
    }
    return lhs;
}

/// andExpr : eqExpr ('&' eqExpr)*
fn andExpr(p: *Parser) Error!?Result {
    var lhs = (try p.eqExpr()) orelse return null;
    while (p.eatToken(.ampersand)) |tok| {
        var rhs = try p.expect(eqExpr);

        if (try lhs.adjustTypes(tok, &rhs, p, .integer)) {
            lhs.val = try lhs.val.bitAnd(rhs.val, p.comp);
        }
        try lhs.bin(p, .bit_and_expr, rhs, tok);
    }
    return lhs;
}

/// eqExpr : compExpr (('==' | '!=') compExpr)*
fn eqExpr(p: *Parser) Error!?Result {
    var lhs = (try p.compExpr()) orelse return null;
    while (true) {
        const tok = p.tok_i;
        const tag = p.eatTag(.equal_equal) orelse
            p.eatTag(.bang_equal) orelse break;
        var rhs = try p.expect(compExpr);

        if (try lhs.adjustTypes(tok, &rhs, p, .equality)) {
            const op: std.math.CompareOperator = if (tag == .equal_expr) .eq else .neq;
            const res: ?bool = if (lhs.ty.isPtr() or rhs.ty.isPtr())
                lhs.val.comparePointers(op, rhs.val, p.comp)
            else
                lhs.val.compare(op, rhs.val, p.comp);

            lhs.val = if (res) |val| Value.fromBool(val) else .{};
        } else {
            lhs.val.boolCast(p.comp);
        }
        try lhs.boolRes(p, tag, rhs, tok);
    }
    return lhs;
}

/// compExpr : shiftExpr (('<' | '<=' | '>' | '>=') shiftExpr)*
fn compExpr(p: *Parser) Error!?Result {
    var lhs = (try p.shiftExpr()) orelse return null;
    while (true) {
        const tok = p.tok_i;
        const tag = p.eatTag(.angle_bracket_left) orelse
            p.eatTag(.angle_bracket_left_equal) orelse
            p.eatTag(.angle_bracket_right) orelse
            p.eatTag(.angle_bracket_right_equal) orelse break;
        var rhs = try p.expect(shiftExpr);

        if (try lhs.adjustTypes(tok, &rhs, p, .relational)) {
            const op: std.math.CompareOperator = switch (tag) {
                .less_than_expr => .lt,
                .less_than_equal_expr => .lte,
                .greater_than_expr => .gt,
                .greater_than_equal_expr => .gte,
                else => unreachable,
            };
            const res: ?bool = if (lhs.ty.isPtr() or rhs.ty.isPtr())
                lhs.val.comparePointers(op, rhs.val, p.comp)
            else
                lhs.val.compare(op, rhs.val, p.comp);
            lhs.val = if (res) |val| Value.fromBool(val) else .{};
        } else {
            lhs.val.boolCast(p.comp);
        }
        try lhs.boolRes(p, tag, rhs, tok);
    }
    return lhs;
}

/// shiftExpr : addExpr (('<<' | '>>') addExpr)*
fn shiftExpr(p: *Parser) Error!?Result {
    var lhs = (try p.addExpr()) orelse return null;
    while (true) {
        const tok = p.tok_i;
        const tag = p.eatTag(.angle_bracket_angle_bracket_left) orelse
            p.eatTag(.angle_bracket_angle_bracket_right) orelse break;
        var rhs = try p.expect(addExpr);

        if (try lhs.adjustTypes(tok, &rhs, p, .integer)) {
            if (rhs.val.compare(.lt, Value.zero, p.comp)) {
                try p.errStr(.negative_shift_count, tok, try rhs.str(p));
            }
            if (rhs.val.compare(.gte, try Value.int(lhs.ty.bitSizeof(p.comp).?, p.comp), p.comp)) {
                try p.errStr(.too_big_shift_count, tok, try rhs.str(p));
            }
            if (tag == .shl_expr) {
                if (try lhs.val.shl(lhs.val, rhs.val, lhs.ty, p.comp) and
                    lhs.ty.signedness(p.comp) != .unsigned) try p.errOverflow(tok, lhs);
            } else {
                lhs.val = try lhs.val.shr(rhs.val, lhs.ty, p.comp);
            }
        }
        try lhs.bin(p, tag, rhs, tok);
    }
    return lhs;
}

/// addExpr : mulExpr (('+' | '-') mulExpr)*
fn addExpr(p: *Parser) Error!?Result {
    var lhs = (try p.mulExpr()) orelse return null;
    while (true) {
        const tok = p.tok_i;
        const tag = p.eatTag(.plus) orelse
            p.eatTag(.minus) orelse break;
        var rhs = try p.expect(mulExpr);

        const lhs_ty = lhs.ty;
        if (try lhs.adjustTypes(tok, &rhs, p, if (tag == .add_expr) .add else .sub)) {
            if (tag == .add_expr) {
                if (try lhs.val.add(lhs.val, rhs.val, lhs.ty, p.comp)) {
                    if (lhs.ty.isPtr()) {
                        try p.errArrayOverflow(tok, lhs);
                    } else if (lhs.ty.signedness(p.comp) != .unsigned) {
                        try p.errOverflow(tok, lhs);
                    }
                }
            } else {
                const elem_size = if (lhs_ty.isPtr()) lhs_ty.elemType().sizeof(p.comp) orelse 1 else 1;
                if (elem_size == 0 and rhs.ty.isPtr()) {
                    lhs.val = .{};
                } else {
                    if (try lhs.val.sub(lhs.val, rhs.val, lhs.ty, elem_size, p.comp) and
                        lhs.ty.signedness(p.comp) != .unsigned) try p.errOverflow(tok, lhs);
                }
            }
        }
        if (lhs.ty.specifier != .invalid and lhs_ty.isPtr() and !lhs_ty.isVoidStar() and lhs_ty.elemType().hasIncompleteSize()) {
            try p.errStr(.ptr_arithmetic_incomplete, tok, try p.typeStr(lhs_ty.elemType()));
            lhs.ty = Type.invalid;
        }
        try lhs.bin(p, tag, rhs, tok);
    }
    return lhs;
}

/// mulExpr : castExpr (('*' | '/' | '%') castExpr)*´
fn mulExpr(p: *Parser) Error!?Result {
    var lhs = (try p.castExpr()) orelse return null;
    while (true) {
        const tok = p.tok_i;
        const tag = p.eatTag(.asterisk) orelse
            p.eatTag(.slash) orelse
            p.eatTag(.percent) orelse break;
        var rhs = try p.expect(castExpr);

        if (rhs.val.isZero(p.comp) and tag != .mul_expr and !p.no_eval and lhs.ty.isInt() and rhs.ty.isInt()) {
            const err_tag: Diagnostics.Tag = if (p.in_macro) .division_by_zero_macro else .division_by_zero;
            lhs.val = .{};
            if (tag == .div_expr) {
                try p.errStr(err_tag, tok, "division");
            } else {
                try p.errStr(err_tag, tok, "remainder");
            }
            if (p.in_macro) return error.ParsingFailed;
        }

        if (try lhs.adjustTypes(tok, &rhs, p, if (tag == .mod_expr) .integer else .arithmetic)) {
            switch (tag) {
                .mul_expr => if (try lhs.val.mul(lhs.val, rhs.val, lhs.ty, p.comp) and
                    lhs.ty.signedness(p.comp) != .unsigned) try p.errOverflow(tok, lhs),
                .div_expr => if (try lhs.val.div(lhs.val, rhs.val, lhs.ty, p.comp) and
                    lhs.ty.signedness(p.comp) != .unsigned) try p.errOverflow(tok, lhs),
                .mod_expr => {
                    var res = try Value.rem(lhs.val, rhs.val, lhs.ty, p.comp);
                    if (res.opt_ref == .none) {
                        if (p.in_macro) {
                            // match clang behavior by defining invalid remainder to be zero in macros
                            res = Value.zero;
                        } else {
                            try lhs.saveValue(p);
                            try rhs.saveValue(p);
                        }
                    }
                    lhs.val = res;
                },
                else => unreachable,
            }
        }

        try lhs.bin(p, tag, rhs, tok);
    }
    return lhs;
}

/// This will always be the last message, if present
fn removeUnusedWarningForTok(p: *Parser, last_expr_tok: TokenIndex) void {
    if (last_expr_tok == 0) return;
    if (p.comp.diagnostics.list.items.len == 0) return;

    const last_expr_loc = p.pp.tokens.items(.loc)[last_expr_tok];
    const last_msg = p.comp.diagnostics.list.items[p.comp.diagnostics.list.items.len - 1];

    if (last_msg.tag == .unused_value and last_msg.loc.eql(last_expr_loc)) {
        p.comp.diagnostics.list.items.len = p.comp.diagnostics.list.items.len - 1;
    }
}

/// castExpr
///  :  '(' compoundStmt ')' suffixExpr*
///  |  '(' typeName ')' castExpr
///  | '(' typeName ')' '{' initializerItems '}'
///  | __builtin_choose_expr '(' integerConstExpr ',' assignExpr ',' assignExpr ')'
///  | __builtin_va_arg '(' assignExpr ',' typeName ')'
///  | __builtin_offsetof '(' typeName ',' offsetofMemberDesignator ')'
///  | __builtin_bitoffsetof '(' typeName ',' offsetofMemberDesignator ')'
///  | unExpr
fn castExpr(p: *Parser) Error!?Result {
    if (p.eatToken(.l_paren)) |l_paren| cast_expr: {
        if (p.tok_ids[p.tok_i] == .l_brace) {
            const tok = p.tok_i;
            try p.err(.gnu_statement_expression);
            if (p.func.ty == null) {
                try p.err(.stmt_expr_not_allowed_file_scope);
                return error.ParsingFailed;
            }
            var stmt_expr_state: StmtExprState = .{};
            const body_node = (try p.compoundStmt(false, &stmt_expr_state)).?; // compoundStmt only returns null if .l_brace isn't the first token
            p.removeUnusedWarningForTok(stmt_expr_state.last_expr_tok);

            var res = Result{
                .node = body_node,
                .ty = stmt_expr_state.last_expr_type,
            };
            try p.expectClosing(l_paren, .r_paren);
            try res.un(p, .stmt_expr, tok);
            while (try p.suffixExpr(res)) |suffix| {
                res = suffix;
            }
            return res;
        }
        const ty = (try p.typeName()) orelse {
            p.tok_i -= 1;
            break :cast_expr;
        };
        try p.expectClosing(l_paren, .r_paren);

        if (p.tok_ids[p.tok_i] == .l_brace) {
            // Compound literal; handled in unExpr
            p.tok_i = l_paren;
            break :cast_expr;
        }

        const operand_tok = p.tok_i;
        var operand = try p.expect(castExpr);
        try operand.lvalConversion(p, operand_tok);
        try operand.castType(p, ty, operand_tok, l_paren);
        return operand;
    }
    switch (p.tok_ids[p.tok_i]) {
        .builtin_choose_expr => return try p.builtinChooseExpr(),
        .builtin_va_arg => return try p.builtinVaArg(),
        .builtin_offsetof => return try p.builtinOffsetof(.bytes),
        .builtin_bitoffsetof => return try p.builtinOffsetof(.bits),
        .builtin_types_compatible_p => return try p.typesCompatible(),
        // TODO: other special-cased builtins
        else => {},
    }
    return p.unExpr();
}

fn typesCompatible(p: *Parser) Error!Result {
    const builtin_tok = p.tok_i;
    p.tok_i += 1;
    const l_paren = try p.expectToken(.l_paren);

    const lhs = (try p.typeName()) orelse {
        try p.err(.expected_type);
        p.skipTo(.r_paren);
        return error.ParsingFailed;
    };
    _ = try p.expectToken(.comma);

    const rhs = (try p.typeName()) orelse {
        try p.err(.expected_type);
        p.skipTo(.r_paren);
        return error.ParsingFailed;
    };

    try p.expectClosing(l_paren, .r_paren);

    var first_unqual = lhs.canonicalize(.standard);
    first_unqual.qual.@"const" = false;
    first_unqual.qual.@"volatile" = false;
    var second_unqual = rhs.canonicalize(.standard);
    second_unqual.qual.@"const" = false;
    second_unqual.qual.@"volatile" = false;

    const compatible = first_unqual.eql(second_unqual, p.comp, true);

    const res: Result = .{
        .val = Value.fromBool(compatible),
        .ty = Type.int,
        .node = try p.addNode(.{
            .builtin_types_compatible_p = .{
                .builtin_tok = builtin_tok,
                .lhs = lhs,
                .rhs = rhs,
            },
        }),
    };
    try res.putValue(p);
    return res;
}

fn builtinChooseExpr(p: *Parser) Error!Result {
    p.tok_i += 1;
    const l_paren = try p.expectToken(.l_paren);
    const cond_tok = p.tok_i;
    var cond = try p.integerConstExpr(.no_const_decl_folding);
    if (cond.val.opt_ref == .none) {
        try p.errTok(.builtin_choose_cond, cond_tok);
        return error.ParsingFailed;
    }

    _ = try p.expectToken(.comma);

    const then_expr = if (cond.val.toBool(p.comp))
        try p.expect(assignExpr)
    else
        try p.parseNoEval(assignExpr);

    _ = try p.expectToken(.comma);

    const else_expr = if (!cond.val.toBool(p.comp))
        try p.expect(assignExpr)
    else
        try p.parseNoEval(assignExpr);

    try p.expectClosing(l_paren, .r_paren);

    if (cond.val.toBool(p.comp)) {
        cond.val = then_expr.val;
        cond.ty = then_expr.ty;
    } else {
        cond.val = else_expr.val;
        cond.ty = else_expr.ty;
    }
    cond.node = try p.addNode(.{
        .builtin_choose_expr = .{
            .cond_tok = cond_tok,
            .type = cond.ty,
            .cond = cond.node,
            .then_expr = then_expr.node,
            .else_expr = else_expr.node,
        },
    });
    return cond;
}

fn builtinVaArg(p: *Parser) Error!Result {
    const builtin_tok = p.tok_i;
    p.tok_i += 1;

    const l_paren = try p.expectToken(.l_paren);
    const va_list_tok = p.tok_i;
    var va_list = try p.expect(assignExpr);
    try va_list.lvalConversion(p, va_list_tok);

    _ = try p.expectToken(.comma);

    const ty = (try p.typeName()) orelse {
        try p.err(.expected_type);
        return error.ParsingFailed;
    };
    try p.expectClosing(l_paren, .r_paren);

    if (!va_list.ty.eql(p.comp.types.va_list, p.comp, true)) {
        try p.errStr(.incompatible_va_arg, va_list_tok, try p.typeStr(va_list.ty));
        return error.ParsingFailed;
    }

    return .{
        .ty = ty,
        .node = try p.addNode(.{
            .builtin_call_expr = .{
                .builtin_tok = builtin_tok,
                .type = ty,
                .args = &.{va_list.node},
            },
        }),
    };
}

const OffsetKind = enum { bits, bytes };

fn builtinOffsetof(p: *Parser, offset_kind: OffsetKind) Error!Result {
    const builtin_tok = p.tok_i;
    p.tok_i += 1;

    const l_paren = try p.expectToken(.l_paren);
    const ty_tok = p.tok_i;

    const ty = (try p.typeName()) orelse {
        try p.err(.expected_type);
        p.skipTo(.r_paren);
        return error.ParsingFailed;
    };

    if (!ty.isRecord()) {
        try p.errStr(.offsetof_ty, ty_tok, try p.typeStr(ty));
        p.skipTo(.r_paren);
        return error.ParsingFailed;
    } else if (ty.hasIncompleteSize()) {
        try p.errStr(.offsetof_incomplete, ty_tok, try p.typeStr(ty));
        p.skipTo(.r_paren);
        return error.ParsingFailed;
    }

    _ = try p.expectToken(.comma);

    const offsetof_expr = try p.offsetofMemberDesignator(ty, offset_kind, builtin_tok);

    try p.expectClosing(l_paren, .r_paren);

    return .{
        .ty = p.comp.types.size,
        .val = offsetof_expr.val,
        .node = try p.addNode(.{
            .builtin_call_expr = .{
                .builtin_tok = builtin_tok,
                .type = p.comp.types.size,
                .args = &.{offsetof_expr.node},
            },
        }),
    };
}

/// offsetofMemberDesignator: IDENTIFIER ('.' IDENTIFIER | '[' expr ']' )*
fn offsetofMemberDesignator(p: *Parser, base_ty: Type, offset_kind: OffsetKind, access_tok: TokenIndex) Error!Result {
    errdefer p.skipTo(.r_paren);
    const base_field_name_tok = try p.expectIdentifier();
    const base_field_name = try StrInt.intern(p.comp, p.tokSlice(base_field_name_tok));
    const base_record_ty = base_ty.getRecord().?;
    try p.validateFieldAccess(base_record_ty, base_ty, base_field_name_tok, base_field_name);
    const base_node = try p.addNode(.{ .default_init_expr = .{
        .last_tok = p.tok_i,
        .type = base_ty,
    } });

    var cur_offset: u64 = 0;
    var lhs = try p.fieldAccessExtra(base_node, base_record_ty, base_field_name, false, access_tok, &cur_offset);

    var total_offset = cur_offset;
    while (true) switch (p.tok_ids[p.tok_i]) {
        .period => {
            p.tok_i += 1;
            const field_name_tok = try p.expectIdentifier();
            const field_name = try StrInt.intern(p.comp, p.tokSlice(field_name_tok));

            const lhs_record_ty = lhs.ty.getRecord() orelse {
                try p.errStr(.offsetof_ty, field_name_tok, try p.typeStr(lhs.ty));
                return error.ParsingFailed;
            };
            try p.validateFieldAccess(lhs_record_ty, lhs.ty, field_name_tok, field_name);
            lhs = try p.fieldAccessExtra(lhs.node, lhs_record_ty, field_name, false, access_tok, &cur_offset);
            total_offset += cur_offset;
        },
        .l_bracket => {
            const l_bracket_tok = p.tok_i;
            p.tok_i += 1;
            var index = try p.expect(expr);
            _ = try p.expectClosing(l_bracket_tok, .r_bracket);

            if (!lhs.ty.isArray()) {
                try p.errStr(.offsetof_array, l_bracket_tok, try p.typeStr(lhs.ty));
                return error.ParsingFailed;
            }
            var ptr = lhs;
            try ptr.lvalConversion(p, l_bracket_tok);
            try index.lvalConversion(p, l_bracket_tok);

            if (index.ty.isInt()) {
                try p.checkArrayBounds(index, lhs, l_bracket_tok);
            } else {
                try p.errTok(.invalid_index, l_bracket_tok);
            }

            try index.saveValue(p);
            try ptr.bin(p, .array_access_expr, index, l_bracket_tok);
            lhs = ptr;
        },
        else => break,
    };
    const val = try Value.int(if (offset_kind == .bits) total_offset else total_offset / 8, p.comp);
    return .{ .ty = base_ty, .val = val, .node = lhs.node };
}

fn computeOffsetExtra(p: *Parser, node: Node.Index, offset_so_far: *Value) !Value {
    switch (node.get(&p.tree)) {
        .implicit_cast => |cast| {
            return switch (cast.kind) {
                .array_to_pointer => p.computeOffsetExtra(cast.operand, offset_so_far),
                .lval_to_rval => .{},
                else => unreachable,
            };
        },
        .paren_expr => |un| return p.computeOffsetExtra(un.operand, offset_so_far),
        .decl_ref_expr => return p.pointerValue(node, offset_so_far.*),
        .array_access_expr => |access| {
            const index_val = p.tree.value_map.get(access.index) orelse return .{};
            var size = try Value.int(access.type.sizeof(p.comp).?, p.comp);
            const mul_overflow = try size.mul(size, index_val, p.comp.types.ptrdiff, p.comp);

            const add_overflow = try offset_so_far.add(size, offset_so_far.*, p.comp.types.ptrdiff, p.comp);
            _ = mul_overflow;
            _ = add_overflow;
            return p.computeOffsetExtra(access.base, offset_so_far);
        },
        .member_access_expr, .member_access_ptr_expr => |access| {
            var ty = access.base.type(&p.tree);
            if (ty.isPtr()) ty = ty.elemType();
            const record = ty.getRecord().?;
            const field_offset = try Value.int(@divExact(record.fields[access.member_index].layout.offset_bits, 8), p.comp);
            _ = try offset_so_far.add(field_offset, offset_so_far.*, p.comp.types.ptrdiff, p.comp);
            return p.computeOffsetExtra(access.base, offset_so_far);
        },
        else => return .{},
    }
}

/// Compute the offset (in bytes) of an expression from a base pointer.
fn computeOffset(p: *Parser, res: Result) !Value {
    var val: Value = if (res.val.opt_ref == .none) .zero else res.val;
    return p.computeOffsetExtra(res.node, &val);
}

fn packedMemberAccessStr(p: *Parser, record: StringId, member: StringId) ![]const u8 {
    const strings_top = p.strings.items.len;
    defer p.strings.items.len = strings_top;

    var w = p.strings.writer();
    const mapper = p.comp.string_interner.getSlowTypeMapper();

    try w.writeAll(mapper.lookup(member));
    try w.writeAll("' of class or structure '");
    try w.writeAll(mapper.lookup(record));
    try w.writeAll("' may result in an unaligned pointer value");

    return try p.comp.diagnostics.arena.allocator().dupe(u8, p.strings.items[strings_top..]);
}

/// unExpr
///  : (compoundLiteral | primaryExpr) suffixExpr*
///  | '&&' IDENTIFIER
///  | ('&' | '*' | '+' | '-' | '~' | '!' | '++' | '--' | keyword_extension | keyword_imag | keyword_real) castExpr
///  | keyword_sizeof unExpr
///  | keyword_sizeof '(' typeName ')'
///  | keyword_alignof '(' typeName ')'
///  | keyword_c23_alignof '(' typeName ')'
fn unExpr(p: *Parser) Error!?Result {
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
                    .addr_of_label = .{
                        .label_tok = name_tok,
                        .type = result_ty,
                    },
                }),
                .ty = result_ty,
            };
        },
        .ampersand => {
            if (p.in_macro) {
                try p.err(.invalid_preproc_operator);
                return error.ParsingFailed;
            }
            const orig_tok_i = p.tok_i;
            p.tok_i += 1;
            var operand = try p.expect(castExpr);
            var addr_val: Value = .{};

            if (p.getNode(operand.node, .member_access_expr) orelse
                p.getNode(operand.node, .member_access_ptr_expr)) |access|
            {
                if (access.isBitFieldWidth(&p.tree) != null) try p.errTok(.addr_of_bitfield, tok);
                const lhs_ty = access.base.type(&p.tree);
                if (lhs_ty.hasAttribute(.@"packed")) {
                    const record = lhs_ty.getRecord().?;
                    try p.errStr(.packed_member_address, orig_tok_i, try p.packedMemberAccessStr(record.name, record.fields[access.member_index].name));
                }
            }
            const operand_ty_valid = !operand.ty.is(.invalid);
            if (!p.tree.isLval(operand.node) and operand_ty_valid) {
                try p.errTok(.addr_of_rvalue, tok);
            } else if (operand_ty_valid) {
                addr_val = try p.computeOffset(operand);
            }
            if (operand.ty.qual.register) try p.errTok(.addr_of_register, tok);

            if (operand_ty_valid) {
                const elem_ty = try p.arena.create(Type);
                elem_ty.* = operand.ty;
                operand.ty = Type{
                    .specifier = .pointer,
                    .data = .{ .sub_type = elem_ty },
                };
            }
            try operand.saveValue(p);
            try operand.un(p, .addr_of_expr, tok);
            operand.val = addr_val;
            return operand;
        },
        .asterisk => {
            p.tok_i += 1;
            var operand = try p.expect(castExpr);

            if (operand.ty.isArray() or operand.ty.isPtr() or operand.ty.isFunc()) {
                try operand.lvalConversion(p, tok);
                operand.ty = operand.ty.elemType();
                operand.val = .{};
            } else {
                try p.errTok(.indirection_ptr, tok);
            }
            if (operand.ty.hasIncompleteSize() and !operand.ty.is(.void)) {
                try p.errStr(.deref_incomplete_ty_ptr, tok, try p.typeStr(operand.ty));
            }
            operand.ty.qual = .{};
            try operand.un(p, .deref_expr, tok);
            return operand;
        },
        .plus => {
            p.tok_i += 1;

            var operand = try p.expect(castExpr);
            try operand.lvalConversion(p, tok);
            if (!operand.ty.isInt() and !operand.ty.isFloat())
                try p.errStr(.invalid_argument_un, tok, try p.typeStr(operand.ty));

            try operand.usualUnaryConversion(p, tok);

            return operand;
        },
        .minus => {
            p.tok_i += 1;

            var operand = try p.expect(castExpr);
            try operand.lvalConversion(p, tok);
            if (!operand.ty.isInt() and !operand.ty.isFloat())
                try p.errStr(.invalid_argument_un, tok, try p.typeStr(operand.ty));

            try operand.usualUnaryConversion(p, tok);
            if (operand.val.isArithmetic(p.comp)) {
                _ = try operand.val.negate(operand.val, operand.ty, p.comp);
            } else {
                operand.val = .{};
            }
            try operand.un(p, .negate_expr, tok);
            return operand;
        },
        .plus_plus => {
            p.tok_i += 1;

            var operand = try p.expect(castExpr);
            if (operand.ty.isVoidStar())
                try p.errTok(.gnu_pointer_arith, tok);
            if (!operand.ty.isScalar())
                try p.errStr(.invalid_argument_un, tok, try p.typeStr(operand.ty));
            if (operand.ty.isComplex())
                try p.errStr(.complex_prefix_postfix_op, p.tok_i, try p.typeStr(operand.ty));

            if (!p.tree.isLval(operand.node) or operand.ty.isConst()) {
                try p.errTok(.not_assignable, tok);
                return error.ParsingFailed;
            }
            try operand.usualUnaryConversion(p, tok);

            if (operand.val.is(.int, p.comp) or operand.val.is(.int, p.comp)) {
                if (try operand.val.add(operand.val, Value.one, operand.ty, p.comp))
                    try p.errOverflow(tok, operand);
            } else {
                operand.val = .{};
            }

            try operand.un(p, .pre_inc_expr, tok);
            return operand;
        },
        .minus_minus => {
            p.tok_i += 1;

            var operand = try p.expect(castExpr);
            if (operand.ty.isVoidStar())
                try p.errTok(.gnu_pointer_arith, tok);
            if (!operand.ty.isScalar())
                try p.errStr(.invalid_argument_un, tok, try p.typeStr(operand.ty));
            if (operand.ty.isComplex())
                try p.errStr(.complex_prefix_postfix_op, p.tok_i, try p.typeStr(operand.ty));

            if (!p.tree.isLval(operand.node) or operand.ty.isConst()) {
                try p.errTok(.not_assignable, tok);
                return error.ParsingFailed;
            }
            try operand.usualUnaryConversion(p, tok);

            if (operand.val.is(.int, p.comp) or operand.val.is(.int, p.comp)) {
                if (try operand.val.decrement(operand.val, operand.ty, p.comp))
                    try p.errOverflow(tok, operand);
            } else {
                operand.val = .{};
            }

            try operand.un(p, .pre_dec_expr, tok);
            return operand;
        },
        .tilde => {
            p.tok_i += 1;

            var operand = try p.expect(castExpr);
            try operand.lvalConversion(p, tok);
            try operand.usualUnaryConversion(p, tok);
            if (operand.ty.isInt()) {
                if (operand.val.is(.int, p.comp)) {
                    operand.val = try operand.val.bitNot(operand.ty, p.comp);
                }
            } else if (operand.ty.isComplex()) {
                try p.errStr(.complex_conj, tok, try p.typeStr(operand.ty));
                if (operand.val.is(.complex, p.comp)) {
                    operand.val = try operand.val.complexConj(operand.ty, p.comp);
                }
            } else {
                try p.errStr(.invalid_argument_un, tok, try p.typeStr(operand.ty));
                operand.val = .{};
            }
            try operand.un(p, .bit_not_expr, tok);
            return operand;
        },
        .bang => {
            p.tok_i += 1;

            var operand = try p.expect(castExpr);
            try operand.lvalConversion(p, tok);
            if (!operand.ty.isScalar())
                try p.errStr(.invalid_argument_un, tok, try p.typeStr(operand.ty));

            try operand.usualUnaryConversion(p, tok);
            if (operand.val.is(.int, p.comp)) {
                operand.val = Value.fromBool(!operand.val.toBool(p.comp));
            } else if (operand.val.opt_ref == .null) {
                operand.val = Value.one;
            } else {
                if (operand.ty.isDecayed()) {
                    operand.val = Value.zero;
                } else {
                    operand.val = .{};
                }
            }
            operand.ty = .{ .specifier = .int };
            try operand.un(p, .bool_not_expr, tok);
            return operand;
        },
        .keyword_sizeof => {
            p.tok_i += 1;
            const expected_paren = p.tok_i;

            var has_expr = false;
            var res: Result = .{
                .node = undefined, // check has_expr
            };
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
                    has_expr = true;
                }
            } else {
                res = try p.parseNoEval(unExpr);
                has_expr = true;
            }

            if (res.ty.is(.void)) {
                try p.errStr(.pointer_arith_void, tok, "sizeof");
            } else if (res.ty.isDecayed()) {
                const array_ty = res.ty.originalTypeOfDecayedArray();
                const err_str = try p.typePairStrExtra(res.ty, " instead of ", array_ty);
                try p.errStr(.sizeof_array_arg, tok, err_str);
            }

            if (res.ty.sizeof(p.comp)) |size| {
                if (size == 0) {
                    try p.errTok(.sizeof_returns_zero, tok);
                }
                res.val = try Value.int(size, p.comp);
                res.ty = p.comp.types.size;
            } else {
                res.val = .{};
                if (res.ty.hasIncompleteSize()) {
                    try p.errStr(.invalid_sizeof, expected_paren - 1, try p.typeStr(res.ty));
                    res.ty = Type.invalid;
                } else {
                    res.ty = p.comp.types.size;
                }
            }

            res.node = try p.addNode(.{ .sizeof_expr = .{
                .op_tok = tok,
                .type = res.ty,
                .expr = if (has_expr) res.node else null,
            } });
            return res;
        },
        .keyword_alignof,
        .keyword_alignof1,
        .keyword_alignof2,
        .keyword_c23_alignof,
        => {
            p.tok_i += 1;
            const expected_paren = p.tok_i;

            var has_expr = false;
            var res: Result = .{
                .node = undefined, // check has_expr
            };
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
                    has_expr = true;

                    try p.errTok(.alignof_expr, expected_paren);
                }
            } else {
                res = try p.parseNoEval(unExpr);
                has_expr = true;

                try p.errTok(.alignof_expr, expected_paren);
            }

            if (res.ty.is(.void)) {
                try p.errStr(.pointer_arith_void, tok, "alignof");
            }

            if (res.ty.alignable()) {
                res.val = try Value.int(res.ty.alignof(p.comp), p.comp);
                res.ty = p.comp.types.size;
            } else {
                try p.errStr(.invalid_alignof, expected_paren, try p.typeStr(res.ty));
                res.ty = Type.invalid;
            }

            res.node = try p.addNode(.{ .alignof_expr = .{
                .op_tok = tok,
                .type = res.ty,
                .expr = if (has_expr) res.node else null,
            } });
            return res;
        },
        .keyword_extension => {
            p.tok_i += 1;
            const saved_extension = p.extension_suppressed;
            defer p.extension_suppressed = saved_extension;
            p.extension_suppressed = true;

            return try p.expect(castExpr);
        },
        .keyword_imag1, .keyword_imag2 => {
            const imag_tok = p.tok_i;
            p.tok_i += 1;

            var operand = try p.expect(castExpr);
            try operand.lvalConversion(p, tok);
            if (operand.ty.is(.invalid)) return operand;
            if (!operand.ty.isInt() and !operand.ty.isFloat()) {
                try p.errStr(.invalid_imag, imag_tok, try p.typeStr(operand.ty));
            }
            if (operand.ty.isComplex()) {
                operand.val = try operand.val.imaginaryPart(p.comp);
            } else if (operand.ty.isReal()) {
                switch (p.comp.langopts.emulate) {
                    .msvc => {}, // Doesn't support `_Complex` or `__imag` in the first place
                    .gcc => operand.val = Value.zero,
                    .clang => {
                        if (operand.val.is(.int, p.comp) or operand.val.is(.float, p.comp)) {
                            operand.val = Value.zero;
                        } else {
                            operand.val = .{};
                        }
                    },
                }
            }
            // convert _Complex T to T
            operand.ty = operand.ty.makeReal();
            try operand.un(p, .imag_expr, tok);
            return operand;
        },
        .keyword_real1, .keyword_real2 => {
            const real_tok = p.tok_i;
            p.tok_i += 1;

            var operand = try p.expect(castExpr);
            try operand.lvalConversion(p, tok);
            if (operand.ty.is(.invalid)) return operand;
            if (!operand.ty.isInt() and !operand.ty.isFloat()) {
                try p.errStr(.invalid_real, real_tok, try p.typeStr(operand.ty));
            }
            // convert _Complex T to T
            operand.ty = operand.ty.makeReal();
            operand.val = try operand.val.realPart(p.comp);
            try operand.un(p, .real_expr, tok);
            return operand;
        },
        else => {
            var lhs = (try p.compoundLiteral()) orelse
                (try p.primaryExpr()) orelse
                return null;

            while (try p.suffixExpr(lhs)) |suffix| {
                lhs = suffix;
            }
            return lhs;
        },
    }
}

/// compoundLiteral
///  : '(' storageClassSpec* type_name ')' '{' initializer_list '}'
///  | '(' storageClassSpec* type_name ')' '{' initializer_list ',' '}'
fn compoundLiteral(p: *Parser) Error!?Result {
    const l_paren = p.eatToken(.l_paren) orelse return null;

    var d: DeclSpec = .{ .ty = .{ .specifier = undefined } };
    const any = if (p.comp.langopts.standard.atLeast(.c23))
        try p.storageClassSpec(&d)
    else
        false;

    switch (d.storage_class) {
        .auto, .@"extern", .typedef => |tok| {
            try p.errStr(.invalid_compound_literal_storage_class, tok, @tagName(d.storage_class));
            d.storage_class = .none;
        },
        else => {},
    }

    var ty = (try p.typeName()) orelse {
        p.tok_i = l_paren;
        if (any) {
            try p.err(.expected_type);
            return error.ParsingFailed;
        }
        return null;
    };
    if (d.storage_class == .register) ty.qual.register = true;
    try p.expectClosing(l_paren, .r_paren);

    if (ty.isFunc()) {
        try p.err(.func_init);
    } else if (ty.is(.variable_len_array)) {
        try p.err(.vla_init);
    } else if (ty.hasIncompleteSize() and !ty.is(.incomplete_array)) {
        try p.errStr(.variable_incomplete_ty, p.tok_i, try p.typeStr(ty));
        return error.ParsingFailed;
    }

    const init_context = p.init_context;
    defer p.init_context = init_context;
    p.init_context = d.initContext(p);
    var init_list_expr = try p.initializer(ty);
    if (d.constexpr) |_| {
        // TODO error if not constexpr
    }

    init_list_expr.node = try p.addNode(.{ .compound_literal_expr = .{
        .l_paren_tok = l_paren,
        .static = d.storage_class == .static,
        .thread_local = d.thread_local != null,
        .initializer = init_list_expr.node,
        .type = init_list_expr.ty,
    } });
    return init_list_expr;
}

/// suffixExpr
///  : '[' expr ']'
///  | '(' argumentExprList? ')'
///  | '.' IDENTIFIER
///  | '->' IDENTIFIER
///  | '++'
///  | '--'
/// argumentExprList : assignExpr (',' assignExpr)*
fn suffixExpr(p: *Parser, lhs: Result) Error!?Result {
    switch (p.tok_ids[p.tok_i]) {
        .l_paren => return p.callExpr(lhs),
        .plus_plus => {
            defer p.tok_i += 1;

            var operand = lhs;
            if (operand.ty.isVoidStar())
                try p.errTok(.gnu_pointer_arith, p.tok_i);
            if (!operand.ty.isScalar())
                try p.errStr(.invalid_argument_un, p.tok_i, try p.typeStr(operand.ty));
            if (operand.ty.isComplex())
                try p.errStr(.complex_prefix_postfix_op, p.tok_i, try p.typeStr(operand.ty));

            if (!p.tree.isLval(operand.node) or operand.ty.isConst()) {
                try p.err(.not_assignable);
                return error.ParsingFailed;
            }
            try operand.usualUnaryConversion(p, p.tok_i);

            try operand.un(p, .post_inc_expr, p.tok_i);
            return operand;
        },
        .minus_minus => {
            defer p.tok_i += 1;

            var operand = lhs;
            if (operand.ty.isVoidStar())
                try p.errTok(.gnu_pointer_arith, p.tok_i);
            if (!operand.ty.isScalar())
                try p.errStr(.invalid_argument_un, p.tok_i, try p.typeStr(operand.ty));
            if (operand.ty.isComplex())
                try p.errStr(.complex_prefix_postfix_op, p.tok_i, try p.typeStr(operand.ty));

            if (!p.tree.isLval(operand.node) or operand.ty.isConst()) {
                try p.err(.not_assignable);
                return error.ParsingFailed;
            }
            try operand.usualUnaryConversion(p, p.tok_i);

            try operand.un(p, .post_dec_expr, p.tok_i);
            return operand;
        },
        .l_bracket => {
            const l_bracket = p.tok_i;
            p.tok_i += 1;
            var index = try p.expect(expr);
            try p.expectClosing(l_bracket, .r_bracket);

            const array_before_conversion = lhs;
            const index_before_conversion = index;
            var ptr = lhs;
            try ptr.lvalConversion(p, l_bracket);
            try index.lvalConversion(p, l_bracket);
            if (ptr.ty.isPtr()) {
                ptr.ty = ptr.ty.elemType();
                if (index.ty.isInt()) {
                    try p.checkArrayBounds(index_before_conversion, array_before_conversion, l_bracket);
                } else {
                    try p.errTok(.invalid_index, l_bracket);
                }
            } else if (index.ty.isPtr()) {
                index.ty = index.ty.elemType();
                if (ptr.ty.isInt()) {
                    try p.checkArrayBounds(array_before_conversion, index_before_conversion, l_bracket);
                } else {
                    try p.errTok(.invalid_index, l_bracket);
                }
                std.mem.swap(Result, &ptr, &index);
            } else {
                try p.errTok(.invalid_subscript, l_bracket);
            }

            try ptr.saveValue(p);
            try index.saveValue(p);
            ptr.node = try p.addNode(.{ .array_access_expr = .{
                .l_bracket_tok = l_bracket,
                .base = ptr.node,
                .index = index.node,
                .type = ptr.ty,
            } });
            return ptr;
        },
        .period => {
            const period = p.tok_i;
            p.tok_i += 1;
            const name = try p.expectIdentifier();
            return try p.fieldAccess(lhs, name, false, period);
        },
        .arrow => {
            const arrow = p.tok_i;
            p.tok_i += 1;
            const name = try p.expectIdentifier();
            if (lhs.ty.isArray()) {
                var copy = lhs;
                copy.ty.decayArray();
                try copy.implicitCast(p, .array_to_pointer, arrow);
                return try p.fieldAccess(copy, name, true, arrow);
            }
            return try p.fieldAccess(lhs, name, true, arrow);
        },
        else => return null,
    }
}

fn fieldAccess(
    p: *Parser,
    lhs: Result,
    field_name_tok: TokenIndex,
    is_arrow: bool,
    access_tok: TokenIndex,
) !Result {
    const expr_ty = lhs.ty;
    const is_ptr = expr_ty.isPtr();
    const expr_base_ty = if (is_ptr) expr_ty.elemType() else expr_ty;
    const record_ty = expr_base_ty.getRecord() orelse {
        try p.errStr(.expected_record_ty, field_name_tok, try p.typeStr(expr_ty));
        return error.ParsingFailed;
    };

    if (record_ty.isIncomplete()) {
        try p.errStr(.deref_incomplete_ty_ptr, field_name_tok - 2, try p.typeStr(expr_base_ty));
        return error.ParsingFailed;
    }
    if (is_arrow and !is_ptr) try p.errStr(.member_expr_not_ptr, field_name_tok, try p.typeStr(expr_ty));
    if (!is_arrow and is_ptr) try p.errStr(.member_expr_ptr, field_name_tok, try p.typeStr(expr_ty));

    const field_name = try StrInt.intern(p.comp, p.tokSlice(field_name_tok));
    try p.validateFieldAccess(record_ty, expr_ty, field_name_tok, field_name);
    var discard: u64 = 0;
    return p.fieldAccessExtra(lhs.node, record_ty, field_name, is_arrow, access_tok, &discard);
}

fn validateFieldAccess(p: *Parser, record_ty: *const Type.Record, expr_ty: Type, field_name_tok: TokenIndex, field_name: StringId) Error!void {
    if (record_ty.hasField(field_name)) return;

    p.strings.items.len = 0;

    try p.strings.writer().print("'{s}' in '", .{p.tokSlice(field_name_tok)});
    const mapper = p.comp.string_interner.getSlowTypeMapper();
    try expr_ty.print(mapper, p.comp.langopts, p.strings.writer());
    try p.strings.append('\'');

    const duped = try p.comp.diagnostics.arena.allocator().dupe(u8, p.strings.items);
    try p.errStr(.no_such_member, field_name_tok, duped);
    return error.ParsingFailed;
}

fn fieldAccessExtra(
    p: *Parser,
    base: Node.Index,
    record_ty: *const Type.Record,
    field_name: StringId,
    is_arrow: bool,
    access_tok: TokenIndex,
    offset_bits: *u64,
) Error!Result {
    for (record_ty.fields, 0..) |f, i| {
        if (f.isAnonymousRecord()) {
            if (!f.ty.hasField(field_name)) continue;

            const access: Node.MemberAccess = .{
                .access_tok = access_tok,
                .type = f.ty,
                .base = base,
                .member_index = @intCast(i),
            };
            const inner = try p.addNode(if (is_arrow)
                .{ .member_access_ptr_expr = access }
            else
                .{ .member_access_expr = access });

            const ret = p.fieldAccessExtra(inner, f.ty.getRecord().?, field_name, false, access_tok, offset_bits);
            offset_bits.* = f.layout.offset_bits;
            return ret;
        }
        if (field_name == f.name) {
            offset_bits.* = f.layout.offset_bits;

            const access: Node.MemberAccess = .{
                .access_tok = access_tok,
                .type = f.ty,
                .base = base,
                .member_index = @intCast(i),
            };
            return .{ .ty = f.ty, .node = try p.addNode(if (is_arrow)
                .{ .member_access_ptr_expr = access }
            else
                .{ .member_access_expr = access }) };
        }
    }
    // We already checked that this container has a field by the name.
    unreachable;
}

fn checkVaStartArg(p: *Parser, builtin_tok: TokenIndex, first_after: TokenIndex, param_tok: TokenIndex, arg: *Result, idx: u32) !void {
    assert(idx != 0);
    if (idx > 1) {
        try p.errTok(.closing_paren, first_after);
        return error.ParsingFailed;
    }

    var func_ty = p.func.ty orelse {
        try p.errTok(.va_start_not_in_func, builtin_tok);
        return;
    };
    const func_params = func_ty.params();
    if (func_ty.specifier != .var_args_func or func_params.len == 0) {
        return p.errTok(.va_start_fixed_args, builtin_tok);
    }
    const last_param_name = func_params[func_params.len - 1].name;
    const decl_ref = p.getNode(arg.node, .decl_ref_expr);
    if (decl_ref == null or last_param_name != try StrInt.intern(p.comp, p.tokSlice(decl_ref.?.name_tok))) {
        try p.errTok(.va_start_not_last_param, param_tok);
    }
}

fn checkArithOverflowArg(p: *Parser, builtin_tok: TokenIndex, first_after: TokenIndex, param_tok: TokenIndex, arg: *Result, idx: u32) !void {
    _ = builtin_tok;
    _ = first_after;
    if (idx <= 1) {
        if (!arg.ty.isInt()) {
            return p.errStr(.overflow_builtin_requires_int, param_tok, try p.typeStr(arg.ty));
        }
    } else if (idx == 2) {
        if (!arg.ty.isPtr()) return p.errStr(.overflow_result_requires_ptr, param_tok, try p.typeStr(arg.ty));
        const child = arg.ty.elemType();
        if (!child.isInt() or child.is(.bool) or child.is(.@"enum") or child.qual.@"const") return p.errStr(.overflow_result_requires_ptr, param_tok, try p.typeStr(arg.ty));
    }
}

fn checkComplexArg(p: *Parser, builtin_tok: TokenIndex, first_after: TokenIndex, param_tok: TokenIndex, arg: *Result, idx: u32) !void {
    _ = builtin_tok;
    _ = first_after;
    if (idx <= 1 and !arg.ty.isFloat()) {
        try p.errStr(.not_floating_type, param_tok, try p.typeStr(arg.ty));
    } else if (idx == 1) {
        const prev_idx = p.list_buf.items[p.list_buf.items.len - 1];
        const prev_ty = prev_idx.type(&p.tree);
        if (!prev_ty.eql(arg.ty, p.comp, false)) {
            try p.errStr(.argument_types_differ, param_tok, try p.typePairStrExtra(prev_ty, " vs ", arg.ty));
        }
    }
}

fn callExpr(p: *Parser, lhs: Result) Error!?Result {
    const l_paren = p.tok_i;
    p.tok_i += 1;
    const ty = lhs.ty.isCallable() orelse {
        try p.errStr(.not_callable, l_paren, try p.typeStr(lhs.ty));
        return error.ParsingFailed;
    };
    const params = ty.params();
    var func = lhs;
    try func.lvalConversion(p, l_paren);

    const list_buf_top = p.list_buf.items.len;
    defer p.list_buf.items.len = list_buf_top;
    var arg_count: u32 = 0;
    var first_after = l_paren;

    const call_expr = CallExpr.init(p, lhs.node, func.node);

    while (p.eatToken(.r_paren) == null) {
        const param_tok = p.tok_i;
        if (arg_count == params.len) first_after = p.tok_i;
        var arg = try p.expect(assignExpr);

        if (call_expr.shouldPerformLvalConversion(arg_count)) {
            try arg.lvalConversion(p, param_tok);
        }
        if (arg.ty.hasIncompleteSize() and !arg.ty.is(.void)) return error.ParsingFailed;

        if (arg_count >= params.len) {
            if (call_expr.shouldPromoteVarArg(arg_count)) {
                if (arg.ty.isInt()) try arg.intCast(p, arg.ty.integerPromotion(p.comp), param_tok);
                if (arg.ty.is(.float)) try arg.floatCast(p, .{ .specifier = .double }, param_tok);
            }
            try call_expr.checkVarArg(p, first_after, param_tok, &arg, arg_count);
            try arg.saveValue(p);
            try p.list_buf.append(arg.node);
            arg_count += 1;

            _ = p.eatToken(.comma) orelse {
                try p.expectClosing(l_paren, .r_paren);
                break;
            };
            continue;
        }
        const p_ty = params[arg_count].ty;
        if (p_ty.specifier == .static_array) {
            const arg_array_len: u64 = arg.ty.arrayLen() orelse std.math.maxInt(u64);
            const param_array_len: u64 = p_ty.arrayLen().?;
            if (arg_array_len < param_array_len) {
                const extra = Diagnostics.Message.Extra{ .arguments = .{
                    .expected = @intCast(arg_array_len),
                    .actual = @intCast(param_array_len),
                } };
                try p.errExtra(.array_argument_too_small, param_tok, extra);
                try p.errTok(.callee_with_static_array, params[arg_count].name_tok);
            }
            if (arg.val.isZero(p.comp)) {
                try p.errTok(.non_null_argument, param_tok);
                try p.errTok(.callee_with_static_array, params[arg_count].name_tok);
            }
        }

        if (call_expr.shouldCoerceArg(arg_count)) {
            try arg.coerce(p, p_ty, param_tok, .{ .arg = params[arg_count].name_tok });
        }
        try arg.saveValue(p);
        try p.list_buf.append(arg.node);
        arg_count += 1;

        _ = p.eatToken(.comma) orelse {
            try p.expectClosing(l_paren, .r_paren);
            break;
        };
    }

    const actual: u32 = @intCast(arg_count);
    const extra = Diagnostics.Message.Extra{ .arguments = .{
        .expected = @intCast(params.len),
        .actual = actual,
    } };
    if (call_expr.paramCountOverride()) |expected| {
        if (expected != actual) {
            try p.errExtra(.expected_arguments, first_after, .{ .arguments = .{ .expected = expected, .actual = actual } });
        }
    } else if (ty.is(.func) and params.len != arg_count) {
        try p.errExtra(.expected_arguments, first_after, extra);
    } else if (ty.is(.old_style_func) and params.len != arg_count) {
        if (params.len == 0)
            try p.errTok(.passing_args_to_kr, first_after)
        else
            try p.errExtra(.expected_arguments_old, first_after, extra);
    } else if (ty.is(.var_args_func) and arg_count < params.len) {
        try p.errExtra(.expected_at_least_arguments, first_after, extra);
    }

    return call_expr.finish(p, ty, list_buf_top, l_paren);
}

fn checkArrayBounds(p: *Parser, index: Result, array: Result, tok: TokenIndex) !void {
    if (index.val.opt_ref == .none) return;

    const array_len = array.ty.arrayLen() orelse return;
    if (array_len == 0) return;

    if (array_len == 1) {
        if (p.getNode(array.node, .member_access_expr) orelse p.getNode(array.node, .member_access_ptr_expr)) |access| {
            var base_ty = access.base.type(&p.tree);
            if (base_ty.get(.pointer)) |ptr| {
                base_ty = ptr.data.sub_type.*;
            }
            if (base_ty.is(.@"struct")) {
                const record = base_ty.getRecord().?;
                if (access.member_index + 1 == record.fields.len) {
                    if (!index.val.isZero(p.comp)) {
                        try p.errStr(.old_style_flexible_struct, tok, try index.str(p));
                    }
                    return;
                }
            }
        }
    }
    const index_int = index.val.toInt(u64, p.comp) orelse std.math.maxInt(u64);
    if (index.ty.isUnsignedInt(p.comp)) {
        if (index_int >= array_len) {
            try p.errStr(.array_after, tok, try index.str(p));
        }
    } else {
        if (index.val.compare(.lt, Value.zero, p.comp)) {
            try p.errStr(.array_before, tok, try index.str(p));
        } else if (index_int >= array_len) {
            try p.errStr(.array_after, tok, try index.str(p));
        }
    }
}

/// primaryExpr
///  : IDENTIFIER
///  | keyword_true
///  | keyword_false
///  | keyword_nullptr
///  | INTEGER_LITERAL
///  | FLOAT_LITERAL
///  | IMAGINARY_LITERAL
///  | CHAR_LITERAL
///  | STRING_LITERAL
///  | '(' expr ')'
///  | genericSelection
fn primaryExpr(p: *Parser) Error!?Result {
    if (p.eatToken(.l_paren)) |l_paren| {
        var grouped_expr = try p.expect(expr);
        try p.expectClosing(l_paren, .r_paren);
        try grouped_expr.un(p, .paren_expr, l_paren);
        return grouped_expr;
    }

    switch (p.tok_ids[p.tok_i]) {
        .identifier, .extended_identifier => {
            const name_tok = try p.expectIdentifier();
            const name = p.tokSlice(name_tok);
            const interned_name = try StrInt.intern(p.comp, name);
            if (interned_name == p.auto_type_decl_name) {
                try p.errStr(.auto_type_self_initialized, name_tok, name);
                return error.ParsingFailed;
            }

            if (p.syms.findSymbol(interned_name)) |sym| {
                try p.checkDeprecatedUnavailable(sym.ty, name_tok, sym.tok);
                if (sym.kind == .constexpr) {
                    return .{
                        .val = sym.val,
                        .ty = sym.ty,
                        .node = try p.addNode(.{
                            .decl_ref_expr = .{
                                .name_tok = name_tok,
                                .type = sym.ty,
                            },
                        }),
                    };
                }
                if (sym.val.is(.int, p.comp)) {
                    switch (p.const_decl_folding) {
                        .gnu_folding_extension => try p.errTok(.const_decl_folded, name_tok),
                        .gnu_vla_folding_extension => try p.errTok(.const_decl_folded_vla, name_tok),
                        else => {},
                    }
                }

                const dr: Node.DeclRef = .{
                    .name_tok = name_tok,
                    .type = sym.ty,
                };
                return .{
                    .val = if (p.const_decl_folding == .no_const_decl_folding and sym.kind != .enumeration) Value{} else sym.val,
                    .ty = sym.ty,
                    .node = try p.addNode(if (sym.kind == .enumeration)
                        .{ .enumeration_ref = dr }
                    else
                        .{ .decl_ref_expr = dr }),
                };
            }

            // Check if this is a builtin call.
            if (try p.comp.builtins.getOrCreate(p.comp, name, p.arena)) |some| {
                for (p.tok_ids[p.tok_i..]) |id| switch (id) {
                    .r_paren => {}, // closing grouped expr
                    .l_paren => break, // beginning of a call
                    else => {
                        try p.errTok(.builtin_must_be_called, name_tok);
                        return error.ParsingFailed;
                    },
                };
                if (some.builtin.properties.header != .none) {
                    try p.errStr(.implicit_builtin, name_tok, name);
                    try p.errExtra(.implicit_builtin_header_note, name_tok, .{ .builtin_with_header = .{
                        .builtin = some.builtin.tag,
                        .header = some.builtin.properties.header,
                    } });
                }

                return .{
                    .ty = some.ty,
                    .node = try p.addNode(.{
                        .decl_ref_expr = .{
                            .name_tok = name_tok,
                            .type = some.ty,
                        },
                    }),
                };
            }

            // Check for unknown builtin or implicit function declaration.
            if (p.tok_ids[p.tok_i] == .l_paren and !p.comp.langopts.standard.atLeast(.c23)) {
                // allow implicitly declaring functions before C99 like `puts("foo")`
                if (mem.startsWith(u8, name, "__builtin_"))
                    try p.errStr(.unknown_builtin, name_tok, name)
                else
                    try p.errStr(.implicit_func_decl, name_tok, name);

                const func_ty = try p.arena.create(Type.Func);
                func_ty.* = .{ .return_type = .{ .specifier = .int }, .params = &.{} };
                const ty: Type = .{ .specifier = .old_style_func, .data = .{ .func = func_ty } };
                const node = try p.addNode(.{
                    .fn_proto = .{
                        .name_tok = name_tok,
                        .type = ty,
                        .static = false,
                        .@"inline" = false,
                        .definition = null,
                    },
                });

                try p.decl_buf.append(node);
                try p.syms.declareSymbol(p, interned_name, ty, name_tok, node);

                return .{
                    .ty = ty,
                    .node = try p.addNode(.{
                        .decl_ref_expr = .{
                            .name_tok = name_tok,
                            .type = ty,
                        },
                    }),
                };
            }

            try p.errStr(.undeclared_identifier, name_tok, p.tokSlice(name_tok));
            return error.ParsingFailed;
        },
        .keyword_true, .keyword_false => |id| {
            const tok_i = p.tok_i;
            p.tok_i += 1;
            const res: Result = .{
                .val = Value.fromBool(id == .keyword_true),
                .ty = .{ .specifier = .bool },
                .node = try p.addNode(.{
                    .bool_literal = .{
                        .type = .{ .specifier = .bool },
                        .literal_tok = tok_i,
                    },
                }),
            };
            std.debug.assert(!p.in_macro); // Should have been replaced with .one / .zero
            try res.putValue(p);
            return res;
        },
        .keyword_nullptr => {
            defer p.tok_i += 1;
            try p.errStr(.pre_c23_compat, p.tok_i, "'nullptr'");
            return Result{
                .val = Value.null,
                .ty = .{ .specifier = .nullptr_t },
                .node = try p.addNode(.{
                    .nullptr_literal = .{
                        .type = .{ .specifier = .nullptr_t },
                        .literal_tok = p.tok_i,
                    },
                }),
            };
        },
        .macro_func, .macro_function => {
            defer p.tok_i += 1;
            var ty: Type = undefined;
            var tok = p.tok_i;

            if (p.func.ident) |some| {
                ty = some.ty;
                tok = some.node.get(&p.tree).variable.name_tok;
            } else if (p.func.ty) |_| {
                const strings_top = p.strings.items.len;
                defer p.strings.items.len = strings_top;

                try p.strings.appendSlice(p.tokSlice(p.func.name));
                try p.strings.append(0);
                const predef = try p.makePredefinedIdentifier(strings_top);
                ty = predef.ty;
                p.func.ident = predef;
            } else {
                const strings_top = p.strings.items.len;
                defer p.strings.items.len = strings_top;

                try p.strings.append(0);
                const predef = try p.makePredefinedIdentifier(strings_top);
                ty = predef.ty;
                p.func.ident = predef;
                try p.decl_buf.append(predef.node);
            }
            if (p.func.ty == null) try p.err(.predefined_top_level);

            return .{
                .ty = ty,
                .node = try p.addNode(.{
                    .decl_ref_expr = .{
                        .name_tok = tok,
                        .type = ty,
                    },
                }),
            };
        },
        .macro_pretty_func => {
            defer p.tok_i += 1;
            var ty: Type = undefined;
            if (p.func.pretty_ident) |some| {
                ty = some.ty;
            } else if (p.func.ty) |func_ty| {
                const strings_top = p.strings.items.len;
                defer p.strings.items.len = strings_top;

                const mapper = p.comp.string_interner.getSlowTypeMapper();
                try Type.printNamed(func_ty, p.tokSlice(p.func.name), mapper, p.comp.langopts, p.strings.writer());
                try p.strings.append(0);
                const predef = try p.makePredefinedIdentifier(strings_top);
                ty = predef.ty;
                p.func.pretty_ident = predef;
            } else {
                const strings_top = p.strings.items.len;
                defer p.strings.items.len = strings_top;

                try p.strings.appendSlice("top level\x00");
                const predef = try p.makePredefinedIdentifier(strings_top);
                ty = predef.ty;
                p.func.pretty_ident = predef;
                try p.decl_buf.append(predef.node);
            }
            if (p.func.ty == null) try p.err(.predefined_top_level);
            return .{
                .ty = ty,
                .node = try p.addNode(.{
                    .decl_ref_expr = .{
                        .name_tok = p.tok_i,
                        .type = ty,
                    },
                }),
            };
        },
        .string_literal,
        .string_literal_utf_16,
        .string_literal_utf_8,
        .string_literal_utf_32,
        .string_literal_wide,
        .unterminated_string_literal,
        => return try p.stringLiteral(),
        .char_literal,
        .char_literal_utf_8,
        .char_literal_utf_16,
        .char_literal_utf_32,
        .char_literal_wide,
        .empty_char_literal,
        .unterminated_char_literal,
        => return try p.charLiteral(),
        .zero => {
            defer p.tok_i += 1;
            const int_ty = if (p.in_macro) p.comp.types.intmax else Type.int;
            const res: Result = .{
                .val = Value.zero,
                .ty = int_ty,
                .node = try p.addNode(.{ .int_literal = .{ .type = int_ty, .literal_tok = p.tok_i } }),
            };
            try res.putValue(p);
            return res;
        },
        .one => {
            defer p.tok_i += 1;
            const int_ty = if (p.in_macro) p.comp.types.intmax else Type.int;
            const res: Result = .{
                .val = Value.one,
                .ty = int_ty,
                .node = try p.addNode(.{ .int_literal = .{ .type = int_ty, .literal_tok = p.tok_i } }),
            };
            try res.putValue(p);
            return res;
        },
        .pp_num => return try p.ppNum(),
        .embed_byte => {
            assert(!p.in_macro);
            const loc = p.pp.tokens.items(.loc)[p.tok_i];
            defer p.tok_i += 1;
            const buf = p.comp.getSource(.generated).buf[loc.byte_offset..];
            var byte: u8 = buf[0] - '0';
            for (buf[1..]) |c| {
                if (!std.ascii.isDigit(c)) break;
                byte *= 10;
                byte += c - '0';
            }
            const int_ty = Type.int;
            const res: Result = .{
                .val = try Value.int(byte, p.comp),
                .ty = int_ty,
                .node = try p.addNode(.{ .int_literal = .{ .type = int_ty, .literal_tok = p.tok_i } }),
            };
            try res.putValue(p);
            return res;
        },
        .keyword_generic => return p.genericSelection(),
        else => return null,
    }
}

fn makePredefinedIdentifier(p: *Parser, strings_top: usize) !Result {
    const end: u32 = @intCast(p.strings.items.len);
    const elem_ty: Type = .{ .specifier = .char, .qual = .{ .@"const" = true } };
    const arr_ty = try p.arena.create(Type.Array);
    arr_ty.* = .{ .elem = elem_ty, .len = end - strings_top };
    const ty: Type = .{ .specifier = .array, .data = .{ .array = arr_ty } };

    const slice = p.strings.items[strings_top..];
    const val = try Value.intern(p.comp, .{ .bytes = slice });

    const str_lit = try p.addNode(.{ .string_literal_expr = .{ .type = ty, .literal_tok = p.tok_i } });
    if (!p.in_macro) try p.tree.value_map.put(p.gpa, str_lit, val);

    return .{ .ty = ty, .node = try p.addNode(.{
        .variable = .{
            .name_tok = p.tok_i,
            .type = ty,
            .@"extern" = false,
            .static = true,
            .thread_local = false,
            .implicit = true,
            .initializer = str_lit,
        },
    }) };
}

fn stringLiteral(p: *Parser) Error!Result {
    const string_start = p.tok_i;
    var string_end = p.tok_i;
    var string_kind: text_literal.Kind = .char;
    while (text_literal.Kind.classify(p.tok_ids[string_end], .string_literal)) |next| : (string_end += 1) {
        string_kind = string_kind.concat(next) catch {
            try p.errTok(.unsupported_str_cat, string_end);
            while (p.tok_ids[p.tok_i].isStringLiteral()) : (p.tok_i += 1) {}
            return error.ParsingFailed;
        };
        if (string_kind == .unterminated) {
            try p.errTok(.unterminated_string_literal_error, string_end);
            p.tok_i = string_end + 1;
            return error.ParsingFailed;
        }
    }
    const count = string_end - p.tok_i;
    assert(count > 0);

    const char_width = string_kind.charUnitSize(p.comp);

    const strings_top = p.strings.items.len;
    defer p.strings.items.len = strings_top;

    const literal_start = mem.alignForward(usize, strings_top, @intFromEnum(char_width));
    try p.strings.resize(literal_start);

    while (p.tok_i < string_end) : (p.tok_i += 1) {
        const this_kind = text_literal.Kind.classify(p.tok_ids[p.tok_i], .string_literal).?;
        const slice = this_kind.contentSlice(p.tokSlice(p.tok_i));
        var char_literal_parser = text_literal.Parser.init(slice, this_kind, 0x10ffff, p.comp);

        try p.strings.ensureUnusedCapacity((slice.len + 1) * @intFromEnum(char_width)); // +1 for null terminator
        while (char_literal_parser.next()) |item| switch (item) {
            .value => |v| {
                switch (char_width) {
                    .@"1" => p.strings.appendAssumeCapacity(@intCast(v)),
                    .@"2" => {
                        const word: u16 = @intCast(v);
                        p.strings.appendSliceAssumeCapacity(mem.asBytes(&word));
                    },
                    .@"4" => p.strings.appendSliceAssumeCapacity(mem.asBytes(&v)),
                }
            },
            .codepoint => |c| {
                switch (char_width) {
                    .@"1" => {
                        var buf: [4]u8 = undefined;
                        const written = std.unicode.utf8Encode(c, &buf) catch unreachable;
                        const encoded = buf[0..written];
                        p.strings.appendSliceAssumeCapacity(encoded);
                    },
                    .@"2" => {
                        var utf16_buf: [2]u16 = undefined;
                        var utf8_buf: [4]u8 = undefined;
                        const utf8_written = std.unicode.utf8Encode(c, &utf8_buf) catch unreachable;
                        const utf16_written = std.unicode.utf8ToUtf16Le(&utf16_buf, utf8_buf[0..utf8_written]) catch unreachable;
                        const bytes = std.mem.sliceAsBytes(utf16_buf[0..utf16_written]);
                        p.strings.appendSliceAssumeCapacity(bytes);
                    },
                    .@"4" => {
                        const val: u32 = c;
                        p.strings.appendSliceAssumeCapacity(mem.asBytes(&val));
                    },
                }
            },
            .improperly_encoded => |bytes| {
                if (count > 1) {
                    try p.errTok(.illegal_char_encoding_error, p.tok_i);
                    return error.ParsingFailed;
                }
                p.strings.appendSliceAssumeCapacity(bytes);
            },
            .utf8_text => |view| {
                switch (char_width) {
                    .@"1" => p.strings.appendSliceAssumeCapacity(view.bytes),
                    .@"2" => {
                        const capacity_slice: []align(@alignOf(u16)) u8 = @alignCast(p.strings.allocatedSlice()[literal_start..]);
                        const dest_len = std.mem.alignBackward(usize, capacity_slice.len, 2);
                        const dest = std.mem.bytesAsSlice(u16, capacity_slice[0..dest_len]);
                        const words_written = std.unicode.utf8ToUtf16Le(dest, view.bytes) catch unreachable;
                        p.strings.resize(p.strings.items.len + words_written * 2) catch unreachable;
                    },
                    .@"4" => {
                        var it = view.iterator();
                        while (it.nextCodepoint()) |codepoint| {
                            const val: u32 = codepoint;
                            p.strings.appendSliceAssumeCapacity(mem.asBytes(&val));
                        }
                    },
                }
            },
        };
        for (char_literal_parser.errors()) |item| {
            try p.errExtra(item.tag, p.tok_i, item.extra);
        }
    }
    p.strings.appendNTimesAssumeCapacity(0, @intFromEnum(char_width));
    const slice = p.strings.items[literal_start..];

    // TODO this won't do anything if there is a cache hit
    const interned_align = mem.alignForward(
        usize,
        p.comp.interner.strings.items.len,
        string_kind.internalStorageAlignment(p.comp),
    );
    try p.comp.interner.strings.resize(p.gpa, interned_align);

    const val = try Value.intern(p.comp, .{ .bytes = slice });

    const array_ty: Type = ty: {
        const arr_data = try p.arena.create(Type.Array);
        arr_data.* = .{ .elem = string_kind.elementType(p.comp), .len = @divExact(slice.len, @intFromEnum(char_width)) };
        break :ty .{ .specifier = .array, .data = .{ .array = arr_data } };
    };
    const res: Result = .{
        .ty = array_ty,
        .val = val,
        .node = try p.addNode(.{ .string_literal_expr = .{
            .literal_tok = string_start,
            .type = array_ty,
        } }),
    };
    try res.putValue(p);
    return res;
}

fn charLiteral(p: *Parser) Error!?Result {
    defer p.tok_i += 1;
    const tok_id = p.tok_ids[p.tok_i];
    const char_kind = text_literal.Kind.classify(tok_id, .char_literal) orelse {
        if (tok_id == .empty_char_literal) {
            try p.err(.empty_char_literal_error);
        } else if (tok_id == .unterminated_char_literal) {
            try p.err(.unterminated_char_literal_error);
        } else unreachable;
        return .{
            .ty = Type.int,
            .val = Value.zero,
            .node = try p.addNode(.{ .char_literal = .{ .type = Type.int, .literal_tok = p.tok_i } }),
        };
    };
    if (char_kind == .utf_8) try p.err(.u8_char_lit);
    var val: u32 = 0;

    const slice = char_kind.contentSlice(p.tokSlice(p.tok_i));

    var is_multichar = false;
    if (slice.len == 1 and std.ascii.isASCII(slice[0])) {
        // fast path: single unescaped ASCII char
        val = slice[0];
    } else {
        const max_codepoint = char_kind.maxCodepoint(p.comp);
        var char_literal_parser = text_literal.Parser.init(slice, char_kind, max_codepoint, p.comp);

        const max_chars_expected = 4;
        var stack_fallback = std.heap.stackFallback(max_chars_expected * @sizeOf(u32), p.comp.gpa);
        var chars = std.ArrayList(u32).initCapacity(stack_fallback.get(), max_chars_expected) catch unreachable; // stack allocation already succeeded
        defer chars.deinit();

        while (char_literal_parser.next()) |item| switch (item) {
            .value => |v| try chars.append(v),
            .codepoint => |c| try chars.append(c),
            .improperly_encoded => |s| {
                try chars.ensureUnusedCapacity(s.len);
                for (s) |c| chars.appendAssumeCapacity(c);
            },
            .utf8_text => |view| {
                var it = view.iterator();
                var max_codepoint_seen: u21 = 0;
                try chars.ensureUnusedCapacity(view.bytes.len);
                while (it.nextCodepoint()) |c| {
                    max_codepoint_seen = @max(max_codepoint_seen, c);
                    chars.appendAssumeCapacity(c);
                }
                if (max_codepoint_seen > max_codepoint) {
                    char_literal_parser.err(.char_too_large, .{ .none = {} });
                }
            },
        };

        is_multichar = chars.items.len > 1;
        if (is_multichar) {
            if (char_kind == .char and chars.items.len == 4) {
                char_literal_parser.warn(.four_char_char_literal, .{ .none = {} });
            } else if (char_kind == .char) {
                char_literal_parser.warn(.multichar_literal_warning, .{ .none = {} });
            } else {
                const kind = switch (char_kind) {
                    .wide => "wide",
                    .utf_8, .utf_16, .utf_32 => "Unicode",
                    else => unreachable,
                };
                char_literal_parser.err(.invalid_multichar_literal, .{ .str = kind });
            }
        }

        var multichar_overflow = false;
        if (char_kind == .char and is_multichar) {
            for (chars.items) |item| {
                val, const overflowed = @shlWithOverflow(val, 8);
                multichar_overflow = multichar_overflow or overflowed != 0;
                val += @as(u8, @truncate(item));
            }
        } else if (chars.items.len > 0) {
            val = chars.items[chars.items.len - 1];
        }

        if (multichar_overflow) {
            char_literal_parser.err(.char_lit_too_wide, .{ .none = {} });
        }

        for (char_literal_parser.errors()) |item| {
            try p.errExtra(item.tag, p.tok_i, item.extra);
        }
    }

    const ty = char_kind.charLiteralType(p.comp);
    // This is the type the literal will have if we're in a macro; macros always operate on intmax_t/uintmax_t values
    const macro_ty = if (ty.isUnsignedInt(p.comp) or (char_kind == .char and p.comp.getCharSignedness() == .unsigned))
        p.comp.types.intmax.makeIntegerUnsigned()
    else
        p.comp.types.intmax;

    var value = try Value.int(val, p.comp);
    // C99 6.4.4.4.10
    // > If an integer character constant contains a single character or escape sequence,
    // > its value is the one that results when an object with type char whose value is
    // > that of the single character or escape sequence is converted to type int.
    // This conversion only matters if `char` is signed and has a high-order bit of `1`
    if (char_kind == .char and !is_multichar and val > 0x7F and p.comp.getCharSignedness() == .signed) {
        _ = try value.intCast(.{ .specifier = .char }, p.comp);
    }

    const res = Result{
        .ty = if (p.in_macro) macro_ty else ty,
        .val = value,
        .node = try p.addNode(.{ .char_literal = .{ .type = ty, .literal_tok = p.tok_i } }),
    };
    if (!p.in_macro) try p.tree.value_map.put(p.gpa, res.node, res.val);
    return res;
}

fn parseFloat(p: *Parser, buf: []const u8, suffix: NumberSuffix, tok_i: TokenIndex) !Result {
    const ty = Type{ .specifier = switch (suffix) {
        .None, .I => .double,
        .F, .IF => .float,
        .F16, .IF16 => .float16,
        .L, .IL => .long_double,
        .W, .IW => p.comp.float80Type().?.specifier,
        .Q, .IQ, .F128, .IF128 => .float128,
        else => unreachable,
    } };
    const val = try Value.intern(p.comp, key: {
        try p.strings.ensureUnusedCapacity(buf.len);

        const strings_top = p.strings.items.len;
        defer p.strings.items.len = strings_top;
        for (buf) |c| {
            if (c != '\'') p.strings.appendAssumeCapacity(c);
        }

        const float = std.fmt.parseFloat(f128, p.strings.items[strings_top..]) catch unreachable;
        const bits = ty.bitSizeof(p.comp).?;
        break :key switch (bits) {
            16 => .{ .float = .{ .f16 = @floatCast(float) } },
            32 => .{ .float = .{ .f32 = @floatCast(float) } },
            64 => .{ .float = .{ .f64 = @floatCast(float) } },
            80 => .{ .float = .{ .f80 = @floatCast(float) } },
            128 => .{ .float = .{ .f128 = @floatCast(float) } },
            else => unreachable,
        };
    });
    var res = Result{
        .ty = ty,
        .node = try p.addNode(.{ .float_literal = .{ .type = ty, .literal_tok = tok_i } }),
        .val = val,
    };
    if (suffix.isImaginary()) {
        try p.err(.gnu_imaginary_constant);
        res.ty = .{ .specifier = switch (suffix) {
            .I => .complex_double,
            .IF16 => .complex_float16,
            .IF => .complex_float,
            .IL => .complex_long_double,
            .IW => p.comp.float80Type().?.makeComplex().specifier,
            .IQ, .IF128 => .complex_float128,
            else => unreachable,
        } };
        res.val = try Value.intern(p.comp, switch (res.ty.bitSizeof(p.comp).?) {
            32 => .{ .complex = .{ .cf16 = .{ 0.0, val.toFloat(f16, p.comp) } } },
            64 => .{ .complex = .{ .cf32 = .{ 0.0, val.toFloat(f32, p.comp) } } },
            128 => .{ .complex = .{ .cf64 = .{ 0.0, val.toFloat(f64, p.comp) } } },
            160 => .{ .complex = .{ .cf80 = .{ 0.0, val.toFloat(f80, p.comp) } } },
            256 => .{ .complex = .{ .cf128 = .{ 0.0, val.toFloat(f128, p.comp) } } },
            else => unreachable,
        });
        try res.un(p, .imaginary_literal, tok_i);
    }
    return res;
}

fn getIntegerPart(p: *Parser, buf: []const u8, prefix: NumberPrefix, tok_i: TokenIndex) ![]const u8 {
    if (buf[0] == '.') return "";

    if (!prefix.digitAllowed(buf[0])) {
        switch (prefix) {
            .binary => try p.errExtra(.invalid_binary_digit, tok_i, .{ .ascii = @intCast(buf[0]) }),
            .octal => try p.errExtra(.invalid_octal_digit, tok_i, .{ .ascii = @intCast(buf[0]) }),
            .hex => try p.errStr(.invalid_int_suffix, tok_i, buf),
            .decimal => unreachable,
        }
        return error.ParsingFailed;
    }

    for (buf, 0..) |c, idx| {
        if (idx == 0) continue;
        switch (c) {
            '.' => return buf[0..idx],
            'p', 'P' => return if (prefix == .hex) buf[0..idx] else {
                try p.errStr(.invalid_int_suffix, tok_i, buf[idx..]);
                return error.ParsingFailed;
            },
            'e', 'E' => {
                switch (prefix) {
                    .hex => continue,
                    .decimal => return buf[0..idx],
                    .binary => try p.errExtra(.invalid_binary_digit, tok_i, .{ .ascii = @intCast(c) }),
                    .octal => try p.errExtra(.invalid_octal_digit, tok_i, .{ .ascii = @intCast(c) }),
                }
                return error.ParsingFailed;
            },
            '0'...'9', 'a'...'d', 'A'...'D', 'f', 'F' => {
                if (!prefix.digitAllowed(c)) {
                    switch (prefix) {
                        .binary => try p.errExtra(.invalid_binary_digit, tok_i, .{ .ascii = @intCast(c) }),
                        .octal => try p.errExtra(.invalid_octal_digit, tok_i, .{ .ascii = @intCast(c) }),
                        .decimal, .hex => try p.errStr(.invalid_int_suffix, tok_i, buf[idx..]),
                    }
                    return error.ParsingFailed;
                }
            },
            '\'' => {},
            else => return buf[0..idx],
        }
    }
    return buf;
}

fn fixedSizeInt(p: *Parser, base: u8, buf: []const u8, suffix: NumberSuffix, tok_i: TokenIndex) !Result {
    var val: u64 = 0;
    var overflow = false;
    for (buf) |c| {
        const digit: u64 = switch (c) {
            '0'...'9' => c - '0',
            'A'...'Z' => c - 'A' + 10,
            'a'...'z' => c - 'a' + 10,
            '\'' => continue,
            else => unreachable,
        };

        if (val != 0) {
            const product, const overflowed = @mulWithOverflow(val, base);
            if (overflowed != 0) {
                overflow = true;
            }
            val = product;
        }
        const sum, const overflowed = @addWithOverflow(val, digit);
        if (overflowed != 0) overflow = true;
        val = sum;
    }
    var res: Result = .{
        .val = try Value.int(val, p.comp),
        .node = undefined, // set later
    };
    if (overflow) {
        try p.errTok(.int_literal_too_big, tok_i);
        res.ty = .{ .specifier = .ulong_long };
        res.node = try p.addNode(.{ .int_literal = .{ .type = res.ty, .literal_tok = tok_i } });
        try res.putValue(p);
        return res;
    }
    const interned_val = try Value.int(val, p.comp);
    if (suffix.isSignedInteger() and base == 10) {
        const max_int = try Value.maxInt(p.comp.types.intmax, p.comp);
        if (interned_val.compare(.gt, max_int, p.comp)) {
            try p.errTok(.implicitly_unsigned_literal, tok_i);
        }
    }

    const signed_specs = .{ .int, .long, .long_long };
    const unsigned_specs = .{ .uint, .ulong, .ulong_long };
    const signed_oct_hex_specs = .{ .int, .uint, .long, .ulong, .long_long, .ulong_long };
    const specs: []const Type.Specifier = if (suffix.signedness() == .unsigned)
        &unsigned_specs
    else if (base == 10)
        &signed_specs
    else
        &signed_oct_hex_specs;

    const suffix_ty: Type = .{ .specifier = switch (suffix) {
        .None, .I => .int,
        .U, .IU => .uint,
        .UL, .IUL => .ulong,
        .ULL, .IULL => .ulong_long,
        .L, .IL => .long,
        .LL, .ILL => .long_long,
        else => unreachable,
    } };

    for (specs) |spec| {
        res.ty = Type{ .specifier = spec };
        if (res.ty.compareIntegerRanks(suffix_ty, p.comp).compare(.lt)) continue;
        const max_int = try Value.maxInt(res.ty, p.comp);
        if (interned_val.compare(.lte, max_int, p.comp)) break;
    } else {
        res.ty = .{ .specifier = spec: {
            if (p.comp.langopts.emulate == .gcc) {
                if (target_util.hasInt128(p.comp.target)) {
                    break :spec .int128;
                } else {
                    break :spec .long_long;
                }
            } else {
                break :spec .ulong_long;
            }
        } };
    }

    res.node = try p.addNode(.{ .int_literal = .{ .type = res.ty, .literal_tok = tok_i } });
    try res.putValue(p);
    return res;
}

fn parseInt(p: *Parser, prefix: NumberPrefix, buf: []const u8, suffix: NumberSuffix, tok_i: TokenIndex) !Result {
    if (prefix == .binary) {
        try p.errTok(.binary_integer_literal, tok_i);
    }
    const base = @intFromEnum(prefix);
    var res = if (suffix.isBitInt())
        try p.bitInt(base, buf, suffix, tok_i)
    else
        try p.fixedSizeInt(base, buf, suffix, tok_i);

    if (suffix.isImaginary()) {
        try p.errTok(.gnu_imaginary_constant, tok_i);
        res.ty = res.ty.makeComplex();
        res.val = .{};
        try res.un(p, .imaginary_literal, tok_i);
    }
    return res;
}

fn bitInt(p: *Parser, base: u8, buf: []const u8, suffix: NumberSuffix, tok_i: TokenIndex) Error!Result {
    try p.errStr(.pre_c23_compat, tok_i, "'_BitInt' suffix for literals");
    try p.errTok(.bitint_suffix, tok_i);

    var managed = try big.int.Managed.init(p.gpa);
    defer managed.deinit();

    {
        try p.strings.ensureUnusedCapacity(buf.len);

        const strings_top = p.strings.items.len;
        defer p.strings.items.len = strings_top;
        for (buf) |c| {
            if (c != '\'') p.strings.appendAssumeCapacity(c);
        }

        managed.setString(base, p.strings.items[strings_top..]) catch |e| switch (e) {
            error.InvalidBase => unreachable, // `base` is one of 2, 8, 10, 16
            error.InvalidCharacter => unreachable, // digits validated by Tokenizer
            else => |er| return er,
        };
    }
    const c = managed.toConst();
    const bits_needed: std.math.IntFittingRange(0, Compilation.bit_int_max_bits) = blk: {
        // Literal `0` requires at least 1 bit
        const count = @max(1, c.bitCountTwosComp());
        // The wb suffix results in a _BitInt that includes space for the sign bit even if the
        // value of the constant is positive or was specified in hexadecimal or octal notation.
        const sign_bits = @intFromBool(suffix.isSignedInteger());
        const bits_needed = count + sign_bits;
        break :blk @intCast(bits_needed);
    };

    const int_ty: Type = .{
        .specifier = .bit_int,
        .data = .{ .int = .{ .bits = bits_needed, .signedness = suffix.signedness() } },
    };
    const res: Result = .{
        .val = try Value.intern(p.comp, .{ .int = .{ .big_int = c } }),
        .ty = int_ty,
        .node = try p.addNode(.{ .int_literal = .{ .type = int_ty, .literal_tok = tok_i } }),
    };
    try res.putValue(p);
    return res;
}

fn getFracPart(p: *Parser, buf: []const u8, prefix: NumberPrefix, tok_i: TokenIndex) ![]const u8 {
    if (buf.len == 0 or buf[0] != '.') return "";
    assert(prefix != .octal);
    if (prefix == .binary) {
        try p.errStr(.invalid_int_suffix, tok_i, buf);
        return error.ParsingFailed;
    }
    for (buf, 0..) |c, idx| {
        if (idx == 0) continue;
        if (c == '\'') continue;
        if (!prefix.digitAllowed(c)) return buf[0..idx];
    }
    return buf;
}

fn getExponent(p: *Parser, buf: []const u8, prefix: NumberPrefix, tok_i: TokenIndex) ![]const u8 {
    if (buf.len == 0) return "";

    switch (buf[0]) {
        'e', 'E' => assert(prefix == .decimal),
        'p', 'P' => if (prefix != .hex) {
            try p.errStr(.invalid_float_suffix, tok_i, buf);
            return error.ParsingFailed;
        },
        else => return "",
    }
    const end = for (buf, 0..) |c, idx| {
        if (idx == 0) continue;
        if (idx == 1 and (c == '+' or c == '-')) continue;
        switch (c) {
            '0'...'9' => {},
            '\'' => continue,
            else => break idx,
        }
    } else buf.len;
    const exponent = buf[0..end];
    if (std.mem.indexOfAny(u8, exponent, "0123456789") == null) {
        try p.errTok(.exponent_has_no_digits, tok_i);
        return error.ParsingFailed;
    }
    return exponent;
}

/// Using an explicit `tok_i` parameter instead of `p.tok_i` makes it easier
/// to parse numbers in pragma handlers.
pub fn parseNumberToken(p: *Parser, tok_i: TokenIndex) !Result {
    const buf = p.tokSlice(tok_i);
    const prefix = NumberPrefix.fromString(buf);
    const after_prefix = buf[prefix.stringLen()..];

    const int_part = try p.getIntegerPart(after_prefix, prefix, tok_i);

    const after_int = after_prefix[int_part.len..];

    const frac = try p.getFracPart(after_int, prefix, tok_i);
    const after_frac = after_int[frac.len..];

    const exponent = try p.getExponent(after_frac, prefix, tok_i);
    const suffix_str = after_frac[exponent.len..];
    const is_float = (exponent.len > 0 or frac.len > 0);
    const suffix = NumberSuffix.fromString(suffix_str, if (is_float) .float else .int) orelse {
        if (is_float) {
            try p.errStr(.invalid_float_suffix, tok_i, suffix_str);
        } else {
            try p.errStr(.invalid_int_suffix, tok_i, suffix_str);
        }
        return error.ParsingFailed;
    };
    if (suffix.isFloat80() and p.comp.float80Type() == null) {
        try p.errStr(.invalid_float_suffix, tok_i, suffix_str);
        return error.ParsingFailed;
    }

    if (is_float) {
        assert(prefix == .hex or prefix == .decimal);
        if (prefix == .hex and exponent.len == 0) {
            try p.errTok(.hex_floating_constant_requires_exponent, tok_i);
            return error.ParsingFailed;
        }
        const number = buf[0 .. buf.len - suffix_str.len];
        return p.parseFloat(number, suffix, tok_i);
    } else {
        return p.parseInt(prefix, int_part, suffix, tok_i);
    }
}

fn ppNum(p: *Parser) Error!Result {
    defer p.tok_i += 1;
    var res = try p.parseNumberToken(p.tok_i);
    if (p.in_macro) {
        if (res.ty.isFloat() or !res.ty.isReal()) {
            try p.errTok(.float_literal_in_pp_expr, p.tok_i);
            return error.ParsingFailed;
        }
        res.ty = if (res.ty.isUnsignedInt(p.comp)) p.comp.types.intmax.makeIntegerUnsigned() else p.comp.types.intmax;
    } else if (res.val.opt_ref != .none) {
        try res.putValue(p);
    }
    return res;
}

/// Run a parser function but do not evaluate the result
fn parseNoEval(p: *Parser, comptime func: fn (*Parser) Error!?Result) Error!Result {
    const no_eval = p.no_eval;
    defer p.no_eval = no_eval;
    p.no_eval = true;

    const parsed = try func(p);
    return p.expectResult(parsed);
}

/// genericSelection : keyword_generic '(' assignExpr ',' genericAssoc (',' genericAssoc)* ')'
/// genericAssoc
///  : typeName ':' assignExpr
///  | keyword_default ':' assignExpr
fn genericSelection(p: *Parser) Error!?Result {
    const kw_generic = p.tok_i;
    p.tok_i += 1;
    const l_paren = try p.expectToken(.l_paren);
    const controlling_tok = p.tok_i;

    const controlling = try p.parseNoEval(assignExpr);
    var controlling_ty = controlling.ty;
    if (controlling_ty.isArray()) controlling_ty.decayArray();
    _ = try p.expectToken(.comma);

    const list_buf_top = p.list_buf.items.len;
    defer p.list_buf.items.len = list_buf_top;

    // Use param_buf to store the token indexes of previous cases
    const param_buf_top = p.param_buf.items.len;
    defer p.param_buf.items.len = param_buf_top;

    var default_tok: ?TokenIndex = null;
    var default: Result = undefined;
    var chosen_tok: ?TokenIndex = null;
    var chosen: Result = undefined;

    while (true) {
        const start = p.tok_i;
        if (try p.typeName()) |ty| blk: {
            if (ty.isArray()) {
                try p.errTok(.generic_array_type, start);
            } else if (ty.isFunc()) {
                try p.errTok(.generic_func_type, start);
            } else if (ty.anyQual()) {
                try p.errTok(.generic_qual_type, start);
            }

            const colon = try p.expectToken(.colon);
            var res = try p.expect(assignExpr);
            res.node = try p.addNode(.{
                .generic_association_expr = .{
                    .colon_tok = colon,
                    .association_type = ty,
                    .expr = res.node,
                },
            });
            try p.list_buf.append(res.node);
            try p.param_buf.append(.{ .name = undefined, .ty = ty, .name_tok = start });

            if (ty.eql(controlling_ty, p.comp, false)) {
                if (chosen_tok == null) {
                    chosen = res;
                    chosen_tok = start;
                    break :blk;
                }
            }

            const previous_items = p.param_buf.items[0 .. p.param_buf.items.len - 1][param_buf_top..];
            for (previous_items) |prev_item| {
                if (prev_item.ty.eql(ty, p.comp, true)) {
                    try p.errStr(.generic_duplicate, start, try p.typeStr(ty));
                    try p.errStr(.generic_duplicate_here, prev_item.name_tok, try p.typeStr(ty));
                }
            }
        } else if (p.eatToken(.keyword_default)) |tok| {
            _ = try p.expectToken(.colon);
            var res = try p.expect(assignExpr);
            res.node = try p.addNode(.{
                .generic_default_expr = .{
                    .default_tok = tok,
                    .expr = res.node,
                },
            });

            if (default_tok) |prev| {
                try p.errTok(.generic_duplicate_default, tok);
                try p.errTok(.previous_case, prev);
            }
            default = res;
            default_tok = tok;
        } else {
            if (p.list_buf.items.len == list_buf_top) {
                try p.err(.expected_type);
                return error.ParsingFailed;
            }
            break;
        }
        if (p.eatToken(.comma) == null) break;
    }
    try p.expectClosing(l_paren, .r_paren);

    if (chosen_tok == null) {
        if (default_tok != null) {
            chosen = default;
        } else {
            try p.errStr(.generic_no_match, controlling_tok, try p.typeStr(controlling_ty));
            return error.ParsingFailed;
        }
    } else if (default_tok != null) {
        try p.list_buf.append(default.node);
    }

    for (p.list_buf.items[list_buf_top..], list_buf_top..) |item, i| {
        if (item == chosen.node) {
            _ = p.list_buf.orderedRemove(i);
            break;
        }
    }

    return .{
        .ty = chosen.ty,
        .val = chosen.val,
        .node = try p.addNode(.{
            .generic_expr = .{
                .generic_tok = kw_generic,
                .controlling = controlling.node,
                .chosen = chosen.node,
                .type = chosen.ty,
                .rest = p.list_buf.items[list_buf_top..],
            },
        }),
    };
}

test "Node locations" {
    var comp = Compilation.init(std.testing.allocator, std.fs.cwd());
    defer comp.deinit();

    const file = try comp.addSourceFromBuffer("file.c",
        \\int foo = 5;
        \\int bar = 10;
        \\int main(void) {}
        \\
    );

    const builtin_macros = try comp.generateBuiltinMacros(.no_system_defines, null);

    var pp = Preprocessor.init(&comp);
    defer pp.deinit();
    try pp.addBuiltinMacros();

    _ = try pp.preprocess(builtin_macros);

    const eof = try pp.preprocess(file);
    try pp.addToken(eof);

    var tree = try Parser.parse(&pp);
    defer tree.deinit();

    try std.testing.expectEqual(0, comp.diagnostics.list.items.len);
    for (tree.root_decls.items, 0..) |node, i| {
        const slice = tree.tokSlice(node.tok(&tree));
        const expected = switch (i) {
            0 => "foo",
            1 => "bar",
            2 => "main",
            else => unreachable,
        };
        try std.testing.expectEqualStrings(expected, slice);
    }
}
