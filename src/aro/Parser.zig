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
const StringId = @import("StringInterner.zig").StringId;
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
const TypeStore = @import("TypeStore.zig");
const Type = TypeStore.Type;
const QualType = TypeStore.QualType;
const Value = @import("Value.zig");

const NodeList = std.ArrayList(Node.Index);
const Switch = struct {
    default: ?TokenIndex = null,
    ranges: std.ArrayList(Range),
    qt: QualType,
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

/// The AST being constructed.
tree: Tree,

// buffers used during compilation
syms: SymbolStack = .{},
strings: std.ArrayListAligned(u8, 4),
labels: std.ArrayList(Label),
list_buf: NodeList,
decl_buf: NodeList,
/// Function type parameters, also used for generic selection association
/// duplicate checking.
param_buf: std.ArrayList(Type.Func.Param),
/// Enum type fields.
enum_buf: std.ArrayList(Type.Enum.Field),
/// Record type fields.
record_buf: std.ArrayList(Type.Record.Field),
/// Attributes that have been parsed but not yet validated or applied.
attr_buf: std.MultiArrayList(TentativeAttribute) = .{},
/// Used to store validated attributes before they are applied to types.
attr_application_buf: std.ArrayListUnmanaged(Attribute) = .{},
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
    /// null if not in function, will always be plain func
    qt: ?QualType = null,
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

    fn addFieldsFromAnonymous(r: @This(), p: *Parser, record_ty: Type.Record) Error!void {
        for (record_ty.fields) |f| {
            if (f.name == .empty) {
                if (f.qt.getRecord(p.comp)) |field_record_ty| {
                    try r.addFieldsFromAnonymous(p, field_record_ty);
                }
            } else {
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
    const ptr_bits = p.comp.type_store.intptr.bitSizeof(p.comp);
    const element_size = res.qt.childType(p.comp).sizeofOrNull(p.comp) orelse 1;
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

pub fn typeStr(p: *Parser, qt: QualType) ![]const u8 {
    if (@import("builtin").mode != .Debug) {
        if (qt.isInvalid()) {
            return "Tried to render invalid type - this is an aro bug.";
        }
    }
    if (TypeStore.Builder.fromType(p.comp, qt).str(p.comp.langopts)) |str| return str;
    const strings_top = p.strings.items.len;
    defer p.strings.items.len = strings_top;

    try qt.print(p.comp, p.strings.writer());
    return try p.comp.diagnostics.arena.allocator().dupe(u8, p.strings.items[strings_top..]);
}

pub fn typePairStr(p: *Parser, a: QualType, b: QualType) ![]const u8 {
    return p.typePairStrExtra(a, " and ", b);
}

pub fn typePairStrExtra(p: *Parser, a: QualType, msg: []const u8, b: QualType) ![]const u8 {
    if (@import("builtin").mode != .Debug) {
        if (a.isInvalid() or b.isInvalid()) {
            return "Tried to render invalid type - this is an aro bug.";
        }
    }
    const strings_top = p.strings.items.len;
    defer p.strings.items.len = strings_top;

    try p.strings.append('\'');
    try a.print(p.comp, p.strings.writer());
    try p.strings.append('\'');
    try p.strings.appendSlice(msg);
    try p.strings.append('\'');
    try b.print(p.comp, p.strings.writer());
    try p.strings.append('\'');
    return try p.comp.diagnostics.arena.allocator().dupe(u8, p.strings.items[strings_top..]);
}

pub fn valueChangedStr(p: *Parser, res: *Result, old_value: Value, int_ty: QualType) ![]const u8 {
    const strings_top = p.strings.items.len;
    defer p.strings.items.len = strings_top;

    var w = p.strings.writer();
    const type_pair_str = try p.typePairStrExtra(res.qt, " to ", int_ty);
    try w.writeAll(type_pair_str);

    try w.writeAll(" changes ");
    if (res.val.isZero(p.comp)) try w.writeAll("non-zero ");
    try w.writeAll("value from ");
    if (try old_value.print(res.qt, p.comp, w)) |nested| switch (nested) {
        .pointer => unreachable,
    };
    try w.writeAll(" to ");
    if (try res.val.print(int_ty, p.comp, w)) |nested| switch (nested) {
        .pointer => unreachable,
    };

    return try p.comp.diagnostics.arena.allocator().dupe(u8, p.strings.items[strings_top..]);
}

fn checkDeprecatedUnavailable(p: *Parser, ty: QualType, usage_tok: TokenIndex, decl_tok: TokenIndex) !void {
    if (ty.getAttribute(p.comp, .@"error")) |@"error"| {
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
    if (ty.getAttribute(p.comp, .warning)) |warning| {
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
    if (ty.getAttribute(p.comp, .unavailable)) |unavailable| {
        try p.errDeprecated(.unavailable, usage_tok, unavailable.msg);
        try p.errStr(.unavailable_note, unavailable.__name_tok, p.tokSlice(decl_tok));
        return error.ParsingFailed;
    }
    if (ty.getAttribute(p.comp, .deprecated)) |deprecated| {
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
    const cast = p.getNode(node, .cast) orelse return null;
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

        const decl_type_name = switch (forward.container_qt.base(p.comp).type) {
            .@"struct", .@"union" => |record_ty| record_ty.name,
            .@"enum" => |enum_ty| enum_ty.name,
            else => unreachable,
        };

        const tentative_def_tok = p.tentative_defs.get(decl_type_name) orelse continue;
        const type_str = try p.typeStr(forward.container_qt);
        try p.errStr(.tentative_definition_incomplete, tentative_def_tok, type_str);
        try p.errStr(.forward_declaration_here, forward.name_or_kind_tok, type_str);
    }
}

/// root : (decl | assembly ';' | staticAssert)*
pub fn parse(pp: *Preprocessor) Compilation.Error!Tree {
    assert(pp.linemarkers == .none);
    pp.comp.pragmaEvent(.before_parse);

    var p: Parser = .{
        .pp = pp,
        .comp = pp.comp,
        .gpa = pp.comp.gpa,
        .tree = .{
            .comp = pp.comp,
            .tokens = pp.tokens.slice(),
        },
        .tok_ids = pp.tokens.items(.id),
        .strings = .init(pp.comp.gpa),
        .labels = .init(pp.comp.gpa),
        .list_buf = .init(pp.comp.gpa),
        .decl_buf = .init(pp.comp.gpa),
        .param_buf = .init(pp.comp.gpa),
        .enum_buf = .init(pp.comp.gpa),
        .record_buf = .init(pp.comp.gpa),
        .string_ids = .{
            .declspec_id = try pp.comp.internString("__declspec"),
            .main_id = try pp.comp.internString("main"),
            .file = try pp.comp.internString("FILE"),
            .jmp_buf = try pp.comp.internString("jmp_buf"),
            .sigjmp_buf = try pp.comp.internString("sigjmp_buf"),
            .ucontext_t = try pp.comp.internString("ucontext_t"),
        },
    };
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
    }

    try p.syms.pushScope(&p);
    defer p.syms.popScope();

    {
        if (p.comp.langopts.hasChar8_T()) {
            try p.addImplicitTypedef("char8_t", .uchar);
        }
        try p.addImplicitTypedef("__int128_t", .int128);
        try p.addImplicitTypedef("__uint128_t", .uint128);

        try p.addImplicitTypedef("__builtin_ms_va_list", .char_pointer);

        const va_list_qt = pp.comp.type_store.va_list;
        try p.addImplicitTypedef("__builtin_va_list", va_list_qt);
        pp.comp.type_store.va_list = try va_list_qt.decay(pp.comp);

        try p.addImplicitTypedef("__NSConstantString", pp.comp.type_store.ns_constant_string);

        if (p.comp.float80Type()) |float80_ty| {
            try p.addImplicitTypedef("__float80", float80_ty);
        }
    }
    const implicit_typedef_count = p.decl_buf.items.len;

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
            const empty = try p.tree.addNode(.{ .empty_decl = .{
                .semicolon = tok,
            } });
            try p.decl_buf.append(empty);
            continue;
        }
        try p.err(.expected_external_decl);
        p.tok_i += 1;
    }
    if (p.tentative_defs.count() > 0) {
        try p.diagnoseIncompleteDefinitions();
    }

    p.tree.root_decls = p.decl_buf.moveToUnmanaged();
    if (p.tree.root_decls.items.len == implicit_typedef_count) {
        try p.errTok(.empty_translation_unit, p.tok_i - 1);
    }
    pp.comp.pragmaEvent(.after_parse);

    return p.tree;
}

fn addImplicitTypedef(p: *Parser, name: []const u8, qt: QualType) !void {
    const start = p.comp.generated_buf.items.len;
    try p.comp.generated_buf.appendSlice(p.comp.gpa, name);
    try p.comp.generated_buf.append(p.comp.gpa, '\n');

    const name_tok: u32 = @intCast(p.pp.tokens.len);
    try p.pp.tokens.append(p.gpa, .{ .id = .identifier, .loc = .{
        .id = .generated,
        .byte_offset = @intCast(start),
        .line = p.pp.generated_line,
    } });
    p.pp.generated_line += 1;

    // Reset in case there was an allocation.
    p.tree.tokens = p.pp.tokens.slice();

    const node = try p.addNode(.{
        .typedef = .{
            .name_tok = name_tok,
            .qt = qt,
            .implicit = true,
        },
    });

    const interned_name = try p.comp.internString(name);
    const typedef_qt = (try p.comp.type_store.put(p.gpa, .{ .typedef = .{
        .base = qt,
        .name = interned_name,
    } })).withQualifiers(qt);
    try p.syms.defineTypedef(p, interned_name, typedef_qt, name_tok, node);
    try p.decl_buf.append(node);
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
fn typedefDefined(p: *Parser, name: StringId, ty: QualType) void {
    if (name == p.string_ids.file) {
        p.comp.type_store.file = ty;
    } else if (name == p.string_ids.jmp_buf) {
        p.comp.type_store.jmp_buf = ty;
    } else if (name == p.string_ids.sigjmp_buf) {
        p.comp.type_store.sigjmp_buf = ty;
    } else if (name == p.string_ids.ucontext_t) {
        p.comp.type_store.ucontext_t = ty;
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

    var decl_spec = (try p.declSpec()) orelse blk: {
        if (p.func.qt != null) {
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
        var builder: TypeStore.Builder = .{ .parser = p };
        break :blk DeclSpec{ .qt = try builder.finish() };
    };
    if (decl_spec.noreturn) |tok| {
        const attr = Attribute{ .tag = .noreturn, .args = .{ .noreturn = .{} }, .syntax = .keyword };
        try p.attr_buf.append(p.gpa, .{ .attr = attr, .tok = tok });
    }

    var decl_node = try p.tree.addNode(.{ .empty_decl = .{
        .semicolon = first_tok,
    } });
    var init_d = (try p.initDeclarator(&decl_spec, attr_buf_top, decl_node)) orelse {
        _ = try p.expectToken(.semicolon);

        missing_decl: {
            if (decl_spec.qt.type(p.comp) == .typeof) {
                break :missing_decl; // we follow GCC and clang's behavior here
            }
            switch (decl_spec.qt.base(p.comp).type) {
                .@"enum" => break :missing_decl,
                .@"struct", .@"union" => |record_ty| if (!record_ty.isAnonymous(p.comp)) break :missing_decl,
                else => {},
            }

            try p.errTok(.missing_declaration, first_tok);
            return true;
        }

        const attrs = p.attr_buf.items(.attr)[attr_buf_top..];
        const toks = p.attr_buf.items(.tok)[attr_buf_top..];
        for (attrs, toks) |attr, tok| {
            try p.errExtra(.ignored_record_attr, tok, .{
                .ignored_record_attr = .{ .tag = attr.tag, .tag_kind = switch (decl_spec.qt.base(p.comp).type) {
                    .@"enum" => .@"enum",
                    .@"struct" => .@"struct",
                    .@"union" => .@"union",
                    else => unreachable,
                } },
            });
        }
        return true;
    };

    // Check for function definition.
    if (init_d.d.declarator_type == .func and init_d.initializer == null) fn_def: {
        switch (p.tok_ids[p.tok_i]) {
            .comma, .semicolon => break :fn_def,
            .l_brace => {},
            else => if (init_d.d.old_style_func == null) {
                try p.err(.expected_fn_body);
                return true;
            },
        }
        if (p.func.qt != null) try p.err(.func_not_in_root);

        const interned_declarator_name = try p.comp.internString(p.tokSlice(init_d.d.name));
        try p.syms.defineSymbol(p, interned_declarator_name, init_d.d.qt, init_d.d.name, decl_node, .{}, false);
        const func = p.func;
        p.func = .{
            .qt = init_d.d.qt,
            .name = init_d.d.name,
        };
        defer p.func = func;

        // Check return type of 'main' function.
        if (interned_declarator_name == p.string_ids.main_id) {
            const func_ty = init_d.d.qt.get(p.comp, .func).?;
            if (func_ty.return_type.get(p.comp, .int)) |int_ty| {
                if (int_ty != .int) {
                    try p.errTok(.main_return_type, init_d.d.name);
                }
            }
        }

        try p.syms.pushScope(p);
        defer p.syms.popScope();

        // Collect old style parameter declarations.
        if (init_d.d.old_style_func != null) {
            const param_buf_top = p.param_buf.items.len;
            defer p.param_buf.items.len = param_buf_top;

            // We cannot refer to the function type here because the pointer to
            // type_store.extra might get invalidated while parsing the param decls.
            const func_qt = init_d.d.qt.base(p.comp).qt;
            const params_len = func_qt.get(p.comp, .func).?.params.len;

            const new_params = try p.param_buf.addManyAsSlice(params_len);
            for (new_params) |*new_param| {
                new_param.name = .empty;
            }

            param_loop: while (true) {
                const param_decl_spec = (try p.declSpec()) orelse break;
                if (p.eatToken(.semicolon)) |semi| {
                    try p.errTok(.missing_declaration, semi);
                    continue :param_loop;
                }

                while (true) {
                    const attr_buf_top_declarator = p.attr_buf.len;
                    defer p.attr_buf.len = attr_buf_top_declarator;

                    var param_d = (try p.declarator(param_decl_spec.qt, .param)) orelse {
                        try p.errTok(.missing_declaration, first_tok);
                        _ = try p.expectToken(.semicolon);
                        continue :param_loop;
                    };
                    try p.attributeSpecifier();

                    if (param_d.qt.sizeofOrNull(p.comp) == null) {
                        if (param_d.qt.is(p.comp, .void)) {
                            try p.errTok(.invalid_void_param, param_d.name);
                        } else {
                            try p.errStr(.parameter_incomplete_ty, param_d.name, try p.typeStr(param_d.qt));
                        }
                    } else {
                        // Decay params declared as functions or arrays to pointer.
                        param_d.qt = try param_d.qt.decay(p.comp);
                    }

                    const attributed_qt = try Attribute.applyParameterAttributes(p, param_d.qt, attr_buf_top_declarator, .alignas_on_param);

                    try param_decl_spec.validateParam(p);
                    const param_node = try p.addNode(.{
                        .param = .{
                            .name_tok = param_d.name,
                            .qt = attributed_qt,
                            .storage_class = switch (param_decl_spec.storage_class) {
                                .none => .auto,
                                .register => .register,
                                else => .auto, // Error reported in `validateParam`
                            },
                        },
                    });

                    const name_str = p.tokSlice(param_d.name);
                    const interned_name = try p.comp.internString(name_str);
                    try p.syms.defineParam(p, interned_name, attributed_qt, param_d.name, param_node);

                    // find and correct parameter types
                    for (func_qt.get(p.comp, .func).?.params, new_params) |param, *new_param| {
                        if (param.name == interned_name) {
                            new_param.* = .{
                                .qt = attributed_qt,
                                .name = param.name,
                                .node = .pack(param_node),
                                .name_tok = param.name_tok,
                            };
                            break;
                        }
                    } else {
                        try p.errStr(.parameter_missing, param_d.name, name_str);
                    }

                    if (p.eatToken(.comma) == null) break;
                }
                _ = try p.expectToken(.semicolon);
            }

            const func_ty = func_qt.get(p.comp, .func).?;
            for (func_ty.params, new_params) |param, *new_param| {
                if (new_param.name == .empty) {
                    try p.errStr(.param_not_declared, param.name_tok, param.name.lookup(p.comp));
                    new_param.* = .{
                        .name = param.name,
                        .name_tok = param.name_tok,
                        .node = param.node,
                        .qt = .int,
                    };
                }
            }
            // Set the
            p.func.qt = try p.comp.type_store.put(p.gpa, .{ .func = .{
                .kind = .normal,
                .params = new_params,
                .return_type = func_ty.return_type,
            } });
        } else if (init_d.d.qt.get(p.comp, .func)) |func_ty| {
            for (func_ty.params) |param| {
                if (param.name == .empty) {
                    try p.errTok(.omitting_parameter_name, param.name_tok);
                    continue;
                }

                // bypass redefinition check to avoid duplicate errors
                try p.syms.define(p.gpa, .{
                    .kind = .def,
                    .name = param.name,
                    .tok = param.name_tok,
                    .qt = param.qt,
                    .val = .{},
                    .node = param.node,
                });
                if (param.qt.isInvalid()) continue;

                if (param.qt.get(p.comp, .pointer)) |pointer_ty| {
                    if (pointer_ty.decayed) |decayed_qt| {
                        if (decayed_qt.get(p.comp, .array)) |array_ty| {
                            if (array_ty.len == .unspecified_variable) {
                                try p.errTok(.unbound_vla, param.name_tok);
                            }
                        }
                    }
                }
                if (param.qt.sizeofOrNull(p.comp) == null and !param.qt.is(p.comp, .void)) {
                    try p.errStr(.parameter_incomplete_ty, param.name_tok, try p.typeStr(param.qt));
                }
            }
        }

        const body = (try p.compoundStmt(true, null)) orelse {
            assert(init_d.d.old_style_func != null);
            try p.err(.expected_fn_body);
            return true;
        };

        try decl_spec.validateFnDef(p);
        try p.tree.setNode(.{ .fn_def = .{
            .name_tok = init_d.d.name,
            .@"inline" = decl_spec.@"inline" != null,
            .static = decl_spec.storage_class == .static,
            .qt = p.func.qt.?,
            .body = body,
        } }, @intFromEnum(decl_node));

        try p.decl_buf.append(decl_node);

        // check gotos
        if (func.qt == null) {
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
        try decl_spec.validate(p, init_d.d.qt);

        if (decl_spec.storage_class == .typedef) {
            try p.tree.setNode(.{ .typedef = .{
                .name_tok = init_d.d.name,
                .qt = init_d.d.qt,
                .implicit = false,
            } }, @intFromEnum(decl_node));
        } else if (init_d.d.declarator_type == .func or init_d.d.qt.is(p.comp, .func)) {
            try p.tree.setNode(.{ .fn_proto = .{
                .name_tok = init_d.d.name,
                .qt = init_d.d.qt,
                .static = decl_spec.storage_class == .static,
                .@"inline" = decl_spec.@"inline" != null,
                .definition = null,
            } }, @intFromEnum(decl_node));
        } else {
            var node_qt = init_d.d.qt;
            if (p.func.qt == null) {
                if (node_qt.get(p.comp, .array)) |array_ty| {
                    if (array_ty.len == .incomplete) {
                        // Create tentative array node with fixed type.
                        node_qt = try p.comp.type_store.put(p.gpa, .{ .array = .{
                            .elem = array_ty.elem,
                            .len = .{ .fixed = 1 },
                        } });
                    }
                }
            }

            try p.tree.setNode(.{
                .variable = .{
                    .name_tok = init_d.d.name,
                    .qt = node_qt,
                    .thread_local = decl_spec.thread_local != null,
                    .implicit = false,
                    .storage_class = switch (decl_spec.storage_class) {
                        .auto => .auto,
                        .register => .register,
                        .static => .static,
                        .@"extern" => if (init_d.initializer == null) .@"extern" else .auto,
                        else => .auto, // Error reported in `validate`
                    },
                    .initializer = if (init_d.initializer) |some| some.node else null,
                },
            }, @intFromEnum(decl_node));
        }
        try p.decl_buf.append(decl_node);

        const interned_name = try p.comp.internString(p.tokSlice(init_d.d.name));
        if (decl_spec.storage_class == .typedef) {
            const typedef_qt = (try p.comp.type_store.put(p.gpa, .{ .typedef = .{
                .base = init_d.d.qt,
                .name = interned_name,
            } })).withQualifiers(init_d.d.qt);
            try p.syms.defineTypedef(p, interned_name, typedef_qt, init_d.d.name, decl_node);
            p.typedefDefined(interned_name, typedef_qt);
        } else if (init_d.initializer) |init| {
            // TODO validate global variable/constexpr initializer comptime known
            try p.syms.defineSymbol(
                p,
                interned_name,
                init_d.d.qt,
                init_d.d.name,
                decl_node,
                if (init_d.d.qt.@"const" or decl_spec.constexpr != null) init.val else .{},
                decl_spec.constexpr != null,
            );
        } else if (p.func.qt != null and decl_spec.storage_class != .@"extern") {
            try p.syms.defineSymbol(p, interned_name, init_d.d.qt, init_d.d.name, decl_node, .{}, false);
        } else {
            try p.syms.declareSymbol(p, interned_name, init_d.d.qt, init_d.d.name, decl_node);
        }

        if (p.eatToken(.comma) == null) break;

        if (!warned_auto) {
            // TODO these are warnings in clang
            if (decl_spec.auto_type) |tok_i| {
                try p.errTok(.auto_type_requires_single_declarator, tok_i);
                warned_auto = true;
            }
            if (decl_spec.c23_auto) |tok_i| {
                try p.errTok(.c23_auto_single_declarator, tok_i);
                warned_auto = true;
            }
        }

        decl_node = try p.tree.addNode(.{ .empty_decl = .{
            .semicolon = p.tok_i - 1,
        } });
        init_d = (try p.initDeclarator(&decl_spec, attr_buf_top, decl_node)) orelse {
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
        try buf.appendSlice("'__builtin_types_compatible_p(");

        const lhs_ty = cond.builtin_types_compatible_p.lhs;
        try lhs_ty.print(p.comp, buf.writer());
        try buf.appendSlice(", ");

        const rhs_ty = cond.builtin_types_compatible_p.rhs;
        try rhs_ty.print(p.comp, buf.writer());

        try buf.appendSlice(")'");
    } else if (maybe_message == null) return null;

    if (maybe_message) |message| {
        assert(message.node.get(&p.tree) == .string_literal_expr);
        if (buf.items.len > 0) {
            try buf.append(' ');
        }
        const bytes = p.comp.interner.get(message.val.ref()).bytes;
        try buf.ensureUnusedCapacity(bytes.len);
        try Value.printString(bytes, message.qt, p.comp, buf.writer());
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

    try res.castToBool(p, .bool, res_token);
    if (!res.qt.is(p.comp, .bool)) {
        res.val = .{};
    }
    if (res.val.opt_ref == .none) {
        if (!res.qt.isInvalid()) {
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
    c23_auto: ?TokenIndex = null,
    qt: QualType,

    fn validateParam(d: DeclSpec, p: *Parser) Error!void {
        switch (d.storage_class) {
            .none, .register => {},
            .auto, .@"extern", .static, .typedef => |tok_i| try p.errTok(.invalid_storage_on_param, tok_i),
        }
        if (d.thread_local) |tok_i| try p.errTok(.threadlocal_non_var, tok_i);
        if (d.@"inline") |tok_i| try p.errStr(.func_spec_non_func, tok_i, "inline");
        if (d.noreturn) |tok_i| try p.errStr(.func_spec_non_func, tok_i, "_Noreturn");
        if (d.constexpr) |tok_i| try p.errTok(.invalid_storage_on_param, tok_i);
    }

    fn validateFnDef(d: DeclSpec, p: *Parser) Error!void {
        switch (d.storage_class) {
            .none, .@"extern", .static => {},
            .auto, .register, .typedef => |tok_i| try p.errTok(.illegal_storage_on_func, tok_i),
        }
        if (d.thread_local) |tok_i| try p.errTok(.threadlocal_non_var, tok_i);
        if (d.constexpr) |tok_i| try p.errTok(.illegal_storage_on_func, tok_i);
    }

    fn validate(d: DeclSpec, p: *Parser, final_qt: QualType) Error!void {
        if (final_qt.is(p.comp, .func) and d.storage_class != .typedef) {
            switch (d.storage_class) {
                .none, .@"extern" => {},
                .static => |tok_i| if (p.func.qt != null) try p.errTok(.static_func_not_global, tok_i),
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
                .auto => if (p.func.qt == null and !p.comp.langopts.standard.atLeast(.c23)) {
                    try p.err(.illegal_storage_on_global);
                },
                .register => if (p.func.qt == null) try p.err(.illegal_storage_on_global),
                else => {},
            }
        }
    }

    fn initContext(d: DeclSpec, p: *Parser) InitContext {
        if (d.constexpr != null) return .constexpr;
        if (p.func.qt == null or d.storage_class == .static) return .static;
        return .runtime;
    }
};

/// typeof
///   : keyword_typeof '(' typeName ')'
///   | keyword_typeof '(' expr ')'
fn typeof(p: *Parser) Error!?QualType {
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
    if (try p.typeName()) |qt| {
        try p.expectClosing(l_paren, .r_paren);
        if (qt.isInvalid()) return null;

        return (try p.comp.type_store.put(p.gpa, .{ .typeof = .{
            .base = qt,
            .expr = null,
        } })).withQualifiers(qt);
    }
    const typeof_expr = try p.parseNoEval(expr);
    try p.expectClosing(l_paren, .r_paren);
    if (typeof_expr.qt.isInvalid()) return null;

    const typeof_qt = try p.comp.type_store.put(p.gpa, .{ .typeof = .{
        .base = typeof_expr.qt,
        .expr = typeof_expr.node,
    } });
    if (unqual) return typeof_qt;
    return typeof_qt.withQualifiers(typeof_expr.qt);
}

/// declSpec: (storageClassSpec | typeSpec | funcSpec | autoTypeSpec)+
/// funcSpec : keyword_inline | keyword_noreturn
/// autoTypeSpec : keyword_auto_type
fn declSpec(p: *Parser) Error!?DeclSpec {
    var d: DeclSpec = .{ .qt = .invalid };
    var builder: TypeStore.Builder = .{ .parser = p };

    const start = p.tok_i;
    while (true) {
        const id = p.tok_ids[p.tok_i];
        switch (id) {
            .keyword_inline, .keyword_inline1, .keyword_inline2 => {
                if (d.@"inline" != null) {
                    try p.errStr(.duplicate_decl_spec, p.tok_i, "inline");
                }
                d.@"inline" = p.tok_i;
                p.tok_i += 1;
                continue;
            },
            .keyword_noreturn => {
                if (d.noreturn != null) {
                    try p.errStr(.duplicate_decl_spec, p.tok_i, "_Noreturn");
                }
                d.noreturn = p.tok_i;
                p.tok_i += 1;
                continue;
            },
            .keyword_auto_type => {
                try p.errTok(.auto_type_extension, p.tok_i);
                try builder.combine(.auto_type, p.tok_i);
                if (builder.type == .auto_type) d.auto_type = p.tok_i;
                p.tok_i += 1;
                continue;
            },
            .keyword_auto => if (p.comp.langopts.standard.atLeast(.c23)) {
                try builder.combine(.c23_auto, p.tok_i);
                if (builder.type == .c23_auto) d.c23_auto = p.tok_i;
                p.tok_i += 1;
                continue;
            },
            else => {},
        }

        if (try p.storageClassSpec(&d)) continue;
        if (try p.typeSpec(&builder)) continue;
        if (p.tok_i == start) return null;

        d.qt = try builder.finish();
        return d;
    }
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
fn initDeclarator(p: *Parser, decl_spec: *DeclSpec, attr_buf_top: usize, decl_node: Node.Index) Error!?InitDeclarator {
    const this_attr_buf_top = p.attr_buf.len;
    defer p.attr_buf.len = this_attr_buf_top;

    var init_d = InitDeclarator{
        .d = (try p.declarator(decl_spec.qt, .normal)) orelse return null,
    };

    try p.attributeSpecifierExtra(init_d.d.name);
    _ = try p.assembly(.decl_label);
    try p.attributeSpecifierExtra(init_d.d.name);

    var apply_var_attributes = false;
    if (decl_spec.storage_class == .typedef) {
        if (decl_spec.auto_type) |tok_i| {
            try p.errStr(.auto_type_not_allowed, tok_i, "typedef");
            init_d.d.qt = .invalid;
        } else if (decl_spec.c23_auto) |tok_i| {
            try p.errStr(.c23_auto_not_allowed, tok_i, "typedef");
            init_d.d.qt = .invalid;
        } else {
            init_d.d.qt = try Attribute.applyTypeAttributes(p, init_d.d.qt, attr_buf_top, null);
        }
    } else if (init_d.d.qt.is(p.comp, .func)) {
        if (decl_spec.auto_type) |tok_i| {
            try p.errStr(.auto_type_not_allowed, tok_i, "function return type");
            init_d.d.qt = .invalid;
        } else if (decl_spec.c23_auto) |tok_i| {
            try p.errStr(.c23_auto_not_allowed, tok_i, "function return type");
            init_d.d.qt = .invalid;
        } else {
            init_d.d.qt = try Attribute.applyFunctionAttributes(p, init_d.d.qt, attr_buf_top);
        }
    } else {
        if (init_d.d.qt.is(p.comp, .array)) {
            if (decl_spec.auto_type) |tok_i| {
                try p.errStr(.auto_type_array, tok_i, p.tokSlice(init_d.d.name));
                init_d.d.qt = .invalid;
            } else if (decl_spec.c23_auto) |tok_i| {
                try p.errStr(.c23_auto_array, tok_i, p.tokSlice(init_d.d.name));
                init_d.d.qt = .invalid;
            }
        } else if (init_d.d.qt.is(p.comp, .pointer)) {
            if (decl_spec.auto_type != null or decl_spec.c23_auto != null) {
                // TODO this is not a hard error in clang
                try p.errTok(.auto_type_requires_plain_declarator, p.tok_i);
                init_d.d.qt = .invalid;
            }
        }
        apply_var_attributes = true;
    }

    if (p.eatToken(.equal)) |eq| {
        if (decl_spec.storage_class == .typedef or
            (init_d.d.declarator_type == .func and init_d.d.qt.is(p.comp, .func)))
        {
            try p.errTok(.illegal_initializer, eq);
        } else if (init_d.d.qt.get(p.comp, .array)) |array_ty| {
            if (array_ty.len == .variable) try p.errTok(.vla_init, eq);
        } else if (decl_spec.storage_class == .@"extern") {
            try p.err(.extern_initializer);
            decl_spec.storage_class = .none;
        }

        incomplete: {
            if (init_d.d.qt.isInvalid()) break :incomplete;
            if (init_d.d.qt.isC23Auto()) break :incomplete;
            if (init_d.d.qt.isAutoType()) break :incomplete;
            if (init_d.d.qt.sizeofOrNull(p.comp) != null) break :incomplete;
            if (init_d.d.qt.get(p.comp, .array)) |array_ty| {
                if (array_ty.len == .incomplete) break :incomplete;
            }
            try p.errStr(.variable_incomplete_ty, init_d.d.name, try p.typeStr(init_d.d.qt));
            return error.ParsingFailed;
        }

        try p.syms.pushScope(p);
        defer p.syms.popScope();

        const interned_name = try p.comp.internString(p.tokSlice(init_d.d.name));
        try p.syms.declareSymbol(p, interned_name, init_d.d.qt, init_d.d.name, decl_node);

        // TODO this should be a stack of auto type names because of statement expressions.
        if (init_d.d.qt.isAutoType() or init_d.d.qt.isC23Auto()) {
            p.auto_type_decl_name = interned_name;
        }
        defer p.auto_type_decl_name = .empty;

        const init_context = p.init_context;
        defer p.init_context = init_context;
        p.init_context = decl_spec.initContext(p);
        var init_list_expr = try p.initializer(init_d.d.qt);
        init_d.initializer = init_list_expr;

        // Set incomplete array length if possible.
        if (init_d.d.qt.get(p.comp, .array)) |base_array_ty| {
            if (base_array_ty.len == .incomplete) if (init_list_expr.qt.get(p.comp, .array)) |init_array_ty| {
                switch (init_array_ty.len) {
                    .fixed, .static => |len| {
                        init_d.d.qt = (try p.comp.type_store.put(p.gpa, .{ .array = .{
                            .elem = base_array_ty.elem,
                            .len = .{ .fixed = len },
                        } })).withQualifiers(init_d.d.qt);
                    },
                    else => {},
                }
            };
        }
    }

    const name = init_d.d.name;
    if (init_d.d.qt.isAutoType() or init_d.d.qt.isC23Auto()) {
        if (init_d.initializer) |some| {
            init_d.d.qt = some.qt;
        } else {
            if (init_d.d.qt.isC23Auto()) {
                try p.errStr(.c32_auto_requires_initializer, name, p.tokSlice(name));
            } else {
                try p.errStr(.auto_type_requires_initializer, name, p.tokSlice(name));
            }
            init_d.d.qt = .invalid;
            return init_d;
        }
    }
    if (apply_var_attributes) {
        init_d.d.qt = try Attribute.applyVariableAttributes(p, init_d.d.qt, attr_buf_top, null);
    }

    incomplete: {
        if (decl_spec.storage_class == .typedef) break :incomplete;
        if (init_d.d.qt.isInvalid()) break :incomplete;
        if (init_d.d.qt.sizeofOrNull(p.comp)) |_| break :incomplete;

        const init_type = init_d.d.qt.base(p.comp).type;
        if (decl_spec.storage_class == .@"extern") switch (init_type) {
            .@"struct", .@"union", .@"enum" => break :incomplete,
            .array => |array_ty| if (array_ty.len == .incomplete) break :incomplete,
            else => {},
        };
        // if there was an initializer expression it must have contained an error
        if (init_d.initializer != null) break :incomplete;

        if (p.func.qt == null) {
            switch (init_type) {
                .array => |array_ty| if (array_ty.len == .incomplete) {
                    // TODO properly check this after finishing parsing
                    try p.errStr(.tentative_array, name, try p.typeStr(init_d.d.qt));
                    break :incomplete;
                },
                .@"struct", .@"union" => |record_ty| {
                    _ = try p.tentative_defs.getOrPutValue(p.gpa, record_ty.name, init_d.d.name);
                    break :incomplete;
                },
                .@"enum" => |enum_ty| {
                    _ = try p.tentative_defs.getOrPutValue(p.gpa, enum_ty.name, init_d.d.name);
                    break :incomplete;
                },
                else => {},
            }
        }
        try p.errStr(.variable_incomplete_ty, name, try p.typeStr(init_d.d.qt));
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
///  | keyword_signed1
///  | keyword_signed2
///  | keyword_unsigned
///  | keyword_bool
///  | keyword_c23_bool
///  | keyword_complex
///  | keyword_atomic '(' typeName ')'
///  | recordSpec
///  | enumSpec
///  | typedef  // IDENTIFIER
///  | typeof
///  | keyword_bit_int '(' integerConstExpr ')'
///  | typeQual
///  | keyword_alignas '(' typeName ')'
///  | keyword_alignas '(' integerConstExpr ')'
///  | keyword_c23_alignas '(' typeName ')'
///  | keyword_c23_alignas '(' integerConstExpr ')'
fn typeSpec(p: *Parser, builder: *TypeStore.Builder) Error!bool {
    const start = p.tok_i;
    while (true) {
        try p.attributeSpecifier();

        if (try p.typeof()) |typeof_qt| {
            try builder.combineFromTypeof(typeof_qt, start);
            continue;
        }
        if (try p.typeQual(builder)) continue;
        switch (p.tok_ids[p.tok_i]) {
            .keyword_void => try builder.combine(.void, p.tok_i),
            .keyword_bool, .keyword_c23_bool => try builder.combine(.bool, p.tok_i),
            .keyword_int8, .keyword_int8_2, .keyword_char => try builder.combine(.char, p.tok_i),
            .keyword_int16, .keyword_int16_2, .keyword_short => try builder.combine(.short, p.tok_i),
            .keyword_int32, .keyword_int32_2, .keyword_int => try builder.combine(.int, p.tok_i),
            .keyword_long => try builder.combine(.long, p.tok_i),
            .keyword_int64, .keyword_int64_2 => try builder.combine(.long_long, p.tok_i),
            .keyword_int128 => try builder.combine(.int128, p.tok_i),
            .keyword_signed, .keyword_signed1, .keyword_signed2 => try builder.combine(.signed, p.tok_i),
            .keyword_unsigned => try builder.combine(.unsigned, p.tok_i),
            .keyword_fp16 => try builder.combine(.fp16, p.tok_i),
            .keyword_float16 => try builder.combine(.float16, p.tok_i),
            .keyword_float => try builder.combine(.float, p.tok_i),
            .keyword_double => try builder.combine(.double, p.tok_i),
            .keyword_complex => try builder.combine(.complex, p.tok_i),
            .keyword_float128_1, .keyword_float128_2 => {
                if (!p.comp.hasFloat128()) {
                    try p.errStr(.type_not_supported_on_target, p.tok_i, p.tok_ids[p.tok_i].lexeme().?);
                }
                try builder.combine(.float128, p.tok_i);
            },
            .keyword_atomic => {
                const atomic_tok = p.tok_i;
                p.tok_i += 1;
                const l_paren = p.eatToken(.l_paren) orelse {
                    // _Atomic qualifier not _Atomic(typeName)
                    p.tok_i = atomic_tok;
                    break;
                };
                const base_qt = (try p.typeName()) orelse {
                    try p.err(.expected_type);
                    return error.ParsingFailed;
                };
                try p.expectClosing(l_paren, .r_paren);

                const new_spec = TypeStore.Builder.fromType(p.comp, base_qt);
                try builder.combine(new_spec, atomic_tok);

                if (builder.atomic != null)
                    try p.errStr(.duplicate_decl_spec, atomic_tok, "_Atomic")
                else
                    builder.atomic = atomic_tok;
                continue;
            },
            .keyword_alignas,
            .keyword_c23_alignas,
            => {
                const align_tok = p.tok_i;
                p.tok_i += 1;
                const l_paren = try p.expectToken(.l_paren);
                const typename_start = p.tok_i;
                if (try p.typeName()) |inner_qt| {
                    if (!inner_qt.alignable(p.comp)) {
                        try p.errStr(.invalid_alignof, typename_start, try p.typeStr(inner_qt));
                    }
                    const alignment = Attribute.Alignment{ .requested = inner_qt.alignof(p.comp) };
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
                        args.aligned.alignment.?.node = .pack(res.node);
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
                try builder.combine(TypeStore.Builder.fromType(p.comp, record_ty), tag_tok);
                continue;
            },
            .keyword_enum => {
                const tag_tok = p.tok_i;
                const enum_ty = try p.enumSpec();
                try builder.combine(TypeStore.Builder.fromType(p.comp, enum_ty), tag_tok);
                continue;
            },
            .identifier, .extended_identifier => {
                var interned_name = try p.comp.internString(p.tokSlice(p.tok_i));
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
                if (declspec_found) {
                    interned_name = try p.comp.internString(p.tokSlice(p.tok_i));
                }
                const typedef = (try p.syms.findTypedef(p, interned_name, p.tok_i, builder.type == .none)) orelse break;
                if (!builder.combineTypedef(typedef.qt)) break;
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
                } else if (res.val.compare(.lte, .zero, p.comp)) {
                    bits = 0;
                } else {
                    bits = res.val.toInt(u64, p.comp) orelse std.math.maxInt(u64);
                }

                try builder.combine(.{ .bit_int = bits }, bit_int_tok);
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

    const str = std.fmt.allocPrint(
        p.comp.diagnostics.arena.allocator(), // TODO horrible
        "(anonymous {s} at {s}:{d}:{d})",
        .{ kind_str, source.path, line_col.line_no, line_col.col },
    ) catch unreachable;
    return p.comp.internString(str);
}

/// recordSpec
///  : (keyword_struct | keyword_union) IDENTIFIER? { recordDecls }
///  | (keyword_struct | keyword_union) IDENTIFIER
fn recordSpec(p: *Parser) Error!QualType {
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
        const interned_name = try p.comp.internString(p.tokSlice(ident));
        if (try p.syms.findTag(p, interned_name, p.tok_ids[kind_tok], ident, p.tok_ids[p.tok_i])) |prev| {
            return prev.qt;
        } else {
            // this is a forward declaration, create a new record type.
            const record_ty: Type.Record = .{
                .name = interned_name,
                .layout = null,
                .fields = &.{},
            };
            const record_qt = try p.comp.type_store.put(p.gpa, if (is_struct)
                .{ .@"struct" = record_ty }
            else
                .{ .@"union" = record_ty });

            const attributed_qt = try Attribute.applyTypeAttributes(p, record_qt, attr_buf_top, null);
            try p.syms.define(p.gpa, .{
                .kind = if (is_struct) .@"struct" else .@"union",
                .name = interned_name,
                .tok = ident,
                .qt = attributed_qt,
                .val = .{},
            });

            const fw: Node.ContainerForwardDecl = .{
                .name_or_kind_tok = ident,
                .container_qt = attributed_qt,
                .definition = null,
            };
            try p.decl_buf.append(try p.addNode(if (is_struct)
                .{ .struct_forward_decl = fw }
            else
                .{ .union_forward_decl = fw }));
            return attributed_qt;
        }
    };

    var done = false;
    errdefer if (!done) p.skipTo(.r_brace);

    // Get forward declared type or create a new one
    var record_ty: Type.Record, const qt: QualType = blk: {
        const interned_name = if (maybe_ident) |ident| interned: {
            const ident_str = p.tokSlice(ident);
            const interned_name = try p.comp.internString(ident_str);
            if (try p.syms.defineTag(p, interned_name, p.tok_ids[kind_tok], ident)) |prev| {
                const record_ty = prev.qt.getRecord(p.comp).?;
                if (record_ty.layout != null) {
                    // if the record isn't incomplete, this is a redefinition
                    try p.errStr(.redefinition, ident, ident_str);
                    try p.errTok(.previous_definition, prev.tok);
                } else {
                    break :blk .{ record_ty, prev.qt };
                }
            }
            break :interned interned_name;
        } else try p.getAnonymousName(kind_tok);

        // Initially create ty as a regular non-attributed type, since attributes for a record
        // can be specified after the closing rbrace, which we haven't encountered yet.
        const record_ty: Type.Record = .{
            .name = interned_name,
            .layout = null,
            .fields = &.{},
        };
        const record_qt = try p.comp.type_store.put(p.gpa, if (is_struct)
            .{ .@"struct" = record_ty }
        else
            .{ .@"union" = record_ty });

        // declare a symbol for the type
        // We need to replace the symbol's type if it has attributes
        if (maybe_ident != null) {
            try p.syms.define(p.gpa, .{
                .kind = if (is_struct) .@"struct" else .@"union",
                .name = record_ty.name,
                .tok = maybe_ident.?,
                .qt = record_qt,
                .val = .{},
            });
        }

        break :blk .{ record_ty, record_qt };
    };

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
    p.record = .{
        .kind = p.tok_ids[kind_tok],
        .start = p.record_members.items.len,
    };
    defer p.record = old_record;
    defer p.record_members.items.len = old_members;

    try p.recordDecls();

    const fields = p.record_buf.items[record_buf_top..];

    if (p.record.flexible_field) |some| {
        if (fields.len == 1 and is_struct) {
            try p.errTok(.flexible_in_empty, some);
        }
    }

    if (p.record_buf.items.len == record_buf_top) {
        try p.errStr(.empty_record, kind_tok, p.tokSlice(kind_tok));
        try p.errStr(.empty_record_size, kind_tok, p.tokSlice(kind_tok));
    }
    try p.expectClosing(l_brace, .r_brace);
    done = true;
    try p.attributeSpecifier();

    const attributed_qt = try Attribute.applyTypeAttributes(p, qt, attr_buf_top, null);
    // TODO what?
    // if (ty.specifier == .attributed and maybe_ident != null) {
    //     const ident_str = p.tokSlice(maybe_ident.?);
    //     const interned_name = try p.comp.internString(ident_str);
    //     const ptr = p.syms.getPtr(interned_name, .tags);
    //     ptr.qt = ty;
    // }

    for (fields) |field| {
        if (field.qt.sizeofOrNull(p.comp) == null and !field.qt.is(p.comp, .array)) break;
    } else {
        const pragma_pack_value = switch (p.comp.langopts.emulate) {
            .clang => starting_pragma_pack,
            .gcc => p.pragma_pack,
            // TODO: msvc considers `#pragma pack` on a per-field basis
            .msvc => p.pragma_pack,
        };
        if (record_layout.compute(fields, attributed_qt, p.comp, pragma_pack_value)) |layout| {
            record_ty.fields = fields;
            record_ty.layout = layout;
        } else |er| switch (er) {
            error.Overflow => try p.errStr(.record_too_large, maybe_ident orelse kind_tok, try p.typeStr(qt)),
        }

        // Override previous incomplete type.
        const base_type = attributed_qt.base(p.comp);
        if (is_struct) {
            std.debug.assert(base_type.type.@"struct".name == record_ty.name);
            try p.comp.type_store.set(p.gpa, .{ .@"struct" = record_ty }, @intFromEnum(base_type.qt._index));
        } else {
            std.debug.assert(base_type.type.@"union".name == record_ty.name);
            try p.comp.type_store.set(p.gpa, .{ .@"union" = record_ty }, @intFromEnum(base_type.qt._index));
        }
    }

    // finish by creating a node
    const cd: Node.ContainerDecl = .{
        .name_or_kind_tok = maybe_ident orelse kind_tok,
        .container_qt = attributed_qt,
        .fields = p.decl_buf.items[decl_buf_top..],
    };
    p.decl_buf.items[decl_buf_top - 1] = try p.addNode(if (is_struct) .{ .struct_decl = cd } else .{ .union_decl = cd });
    if (p.func.qt == null) {
        _ = p.tentative_defs.remove(record_ty.name);
    }
    return attributed_qt;
}

/// recordDecls : (keyword_extension? recordDecl | staticAssert)*
fn recordDecls(p: *Parser) Error!void {
    while (true) {
        if (try p.pragma()) continue;
        if (try p.parseOrNextDecl(staticAssert)) continue;
        if (p.eatToken(.keyword_extension)) |_| {
            const saved_extension = p.extension_suppressed;
            defer p.extension_suppressed = saved_extension;
            p.extension_suppressed = true;

            if (try p.parseOrNextDecl(recordDecl)) continue;
            try p.err(.expected_type);
            p.nextExternDecl();
            continue;
        }
        if (try p.parseOrNextDecl(recordDecl)) continue;
        break;
    }
}

/// recordDecl : typeSpec+ (recordDeclarator (',' recordDeclarator)*)?
/// recordDeclarator : declarator (':' integerConstExpr)?
fn recordDecl(p: *Parser) Error!bool {
    const attr_buf_top = p.attr_buf.len;
    defer p.attr_buf.len = attr_buf_top;

    const base_qt: QualType = blk: {
        const start = p.tok_i;
        var builder: TypeStore.Builder = .{ .parser = p };
        while (true) {
            if (try p.typeSpec(&builder)) continue;
            const id = p.tok_ids[p.tok_i];
            switch (id) {
                .keyword_auto => {
                    if (!p.comp.langopts.standard.atLeast(.c23)) break;

                    try p.errStr(.c23_auto_not_allowed, p.tok_i, if (p.record.kind == .keyword_struct) "struct member" else "union member");
                    try builder.combine(.c23_auto, p.tok_i);
                },
                .keyword_auto_type => {
                    try p.errTok(.auto_type_extension, p.tok_i);
                    try p.errStr(.auto_type_not_allowed, p.tok_i, if (p.record.kind == .keyword_struct) "struct member" else "union member");
                    try builder.combine(.auto_type, p.tok_i);
                },
                else => break,
            }
            p.tok_i += 1;
            break;
        }
        if (p.tok_i == start) return false;
        break :blk switch (builder.type) {
            .auto_type, .c23_auto => .invalid,
            else => try builder.finish(),
        };
    };

    try p.attributeSpecifier(); // .record
    while (true) {
        const this_decl_top = p.attr_buf.len;
        defer p.attr_buf.len = this_decl_top;

        try p.attributeSpecifier();

        // 0 means unnamed
        var name_tok: TokenIndex = 0;
        var qt = base_qt;
        var bits_node: ?Node.Index = null;
        var bits: ?u32 = null;
        const first_tok = p.tok_i;
        if (try p.declarator(qt, .record)) |d| {
            name_tok = d.name;
            qt = d.qt;
        }

        if (p.eatToken(.colon)) |_| bits: {
            const bits_tok = p.tok_i;
            const res = try p.integerConstExpr(.gnu_folding_extension);
            if (!qt.isInt(p.comp)) {
                try p.errStr(.non_int_bitfield, first_tok, try p.typeStr(qt));
                break :bits;
            }

            if (res.val.opt_ref == .none) {
                try p.errTok(.expected_integer_constant_expr, bits_tok);
                break :bits;
            } else if (res.val.compare(.lt, .zero, p.comp)) {
                try p.errStr(.negative_bitwidth, first_tok, try res.str(p));
                break :bits;
            }

            // incomplete size error is reported later
            const bit_size = qt.bitSizeofOrNull(p.comp) orelse break :bits;
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

        const to_append = try Attribute.applyFieldAttributes(p, &qt, attr_buf_top);

        const attr_index: u32 = @intCast(p.comp.type_store.attributes.items.len);
        const attr_len: u32 = @intCast(to_append.len);
        try p.comp.type_store.attributes.appendSlice(p.gpa, to_append);

        if (name_tok == 0 and bits == null) unnamed: {
            if (qt.sizeofOrNull(p.comp) == null) break :unnamed;
            switch (qt.base(p.comp).type) {
                .@"enum" => break :unnamed,
                .@"struct", .@"union" => |record_ty| if (record_ty.isAnonymous(p.comp)) {
                    // An anonymous record appears as indirect fields on the parent
                    try p.record_buf.append(.{
                        .name = try p.getAnonymousName(first_tok),
                        .qt = qt,
                        ._attr_index = attr_index,
                        ._attr_len = attr_len,
                    });

                    const node = try p.addNode(.{
                        .record_field = .{
                            .name_or_first_tok = name_tok,
                            .qt = qt,
                            .bit_width = null,
                        },
                    });
                    try p.decl_buf.append(node);
                    try p.record.addFieldsFromAnonymous(p, record_ty);
                    break; // must be followed by a semicolon
                } else break :unnamed,
                else => {},
            }
            try p.err(.missing_declaration);
        } else {
            const interned_name = if (name_tok != 0) try p.comp.internString(p.tokSlice(name_tok)) else try p.getAnonymousName(first_tok);
            try p.record_buf.append(.{
                .name = interned_name,
                .qt = qt,
                .name_tok = name_tok,
                .bit_width = if (bits) |some| @enumFromInt(some) else .null,
                ._attr_index = attr_index,
                ._attr_len = attr_len,
            });
            if (name_tok != 0) try p.record.addField(p, interned_name, name_tok);
            const node = try p.addNode(.{
                .record_field = .{
                    .name_or_first_tok = name_tok,
                    .qt = qt,
                    .bit_width = bits_node,
                },
            });
            try p.decl_buf.append(node);
        }

        if (!qt.isInvalid()) {
            const field_type = qt.base(p.comp);
            switch (field_type.type) {
                .func => {
                    try p.errTok(.func_field, first_tok);
                    qt = .invalid;
                },
                .array => |array_ty| switch (array_ty.len) {
                    .static, .unspecified_variable => unreachable,
                    .variable => {
                        try p.errTok(.vla_field, first_tok);
                        qt = .invalid;
                    },
                    .fixed => {},
                    .incomplete => {
                        if (p.record.kind == .keyword_union) {
                            try p.errTok(.flexible_in_union, first_tok);
                            qt = .invalid;
                        }
                        if (p.record.flexible_field) |some| {
                            if (p.record.kind == .keyword_struct) {
                                try p.errTok(.flexible_non_final, some);
                            }
                        }
                        p.record.flexible_field = first_tok;
                    },
                },
                else => if (field_type.qt.sizeofOrNull(p.comp) == null) {
                    try p.errStr(.field_incomplete_ty, first_tok, try p.typeStr(qt));
                } else if (p.record.flexible_field) |some| {
                    std.debug.assert(some != first_tok);
                    if (p.record.kind == .keyword_struct) try p.errTok(.flexible_non_final, some);
                },
            }
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

/// specQual : typeSpec+
fn specQual(p: *Parser) Error!?QualType {
    var builder: TypeStore.Builder = .{ .parser = p };
    if (try p.typeSpec(&builder)) {
        return try builder.finish();
    }
    return null;
}

/// enumSpec
///  : keyword_enum IDENTIFIER? (: typeName)? { enumerator (',' enumerator)? ',') }
///  | keyword_enum IDENTIFIER (: typeName)?
fn enumSpec(p: *Parser) Error!QualType {
    const enum_tok = p.tok_i;
    p.tok_i += 1;
    const attr_buf_top = p.attr_buf.len;
    defer p.attr_buf.len = attr_buf_top;
    try p.attributeSpecifier();

    const maybe_ident = try p.eatIdentifier();
    const fixed_qt = if (p.eatToken(.colon)) |colon| fixed: {
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

        const fixed_sk = fixed.scalarKind(p.comp);
        if (fixed_sk == .@"enum" or !fixed_sk.isInt()) {
            try p.errStr(.invalid_type_underlying_enum, ty_start, try p.typeStr(fixed));
            break :fixed null;
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
        const interned_name = try p.comp.internString(p.tokSlice(ident));
        if (try p.syms.findTag(p, interned_name, p.tok_ids[enum_tok], ident, p.tok_ids[p.tok_i])) |prev| {
            return prev.qt;
        } else {
            const enum_qt = try p.comp.type_store.put(p.gpa, .{ .@"enum" = .{
                .name = interned_name,
                .tag = fixed_qt orelse .int,
                .fixed = fixed_qt != null,
                .incomplete = true,
                .fields = &.{},
            } });

            const attributed_qt = try Attribute.applyTypeAttributes(p, enum_qt, attr_buf_top, null);
            try p.syms.define(p.gpa, .{
                .kind = .@"enum",
                .name = interned_name,
                .tok = ident,
                .qt = attributed_qt,
                .val = .{},
            });

            try p.decl_buf.append(try p.addNode(.{ .enum_forward_decl = .{
                .name_or_kind_tok = ident,
                .container_qt = attributed_qt,
                .definition = null,
            } }));
            return attributed_qt;
        }
    };

    var done = false;
    errdefer if (!done) p.skipTo(.r_brace);

    // Get forward declared type or create a new one
    var defined = false;
    var enum_ty: Type.Enum, const qt: QualType = blk: {
        const interned_name = if (maybe_ident) |ident| interned: {
            const ident_str = p.tokSlice(ident);
            const interned_name = try p.comp.internString(ident_str);
            if (try p.syms.defineTag(p, interned_name, p.tok_ids[enum_tok], ident)) |prev| {
                const enum_ty = prev.qt.get(p.comp, .@"enum").?;
                if (!enum_ty.incomplete) {
                    // if the record isn't incomplete, this is a redefinition
                    try p.errStr(.redefinition, ident, ident_str);
                    try p.errTok(.previous_definition, prev.tok);
                } else {
                    defined = true;
                    break :blk .{ enum_ty, prev.qt };
                }
            }
            break :interned interned_name;
        } else try p.getAnonymousName(enum_tok);

        // Initially create ty as a regular non-attributed type, since attributes for a record
        // can be specified after the closing rbrace, which we haven't encountered yet.
        const enum_ty: Type.Enum = .{
            .name = interned_name,
            .tag = fixed_qt orelse .int,
            .incomplete = true,
            .fixed = fixed_qt != null,
            .fields = &.{},
        };
        const enum_qt = try p.comp.type_store.put(p.gpa, .{ .@"enum" = enum_ty });
        break :blk .{ enum_ty, enum_qt };
    };

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

    var e = Enumerator.init(fixed_qt);
    while (try p.enumerator(&e)) |field_and_node| {
        try p.enum_buf.append(field_and_node.field);
        try p.list_buf.append(field_and_node.node);
        if (p.eatToken(.comma) == null) break;
    }

    if (p.enum_buf.items.len == enum_buf_top) try p.err(.empty_enum);
    try p.expectClosing(l_brace, .r_brace);
    done = true;
    try p.attributeSpecifier();

    const attributed_qt = try Attribute.applyTypeAttributes(p, qt, attr_buf_top, null);
    if (!enum_ty.fixed) {
        enum_ty.tag = try e.getTypeSpecifier(p, attributed_qt.enumIsPacked(p.comp), maybe_ident orelse enum_tok);
    }

    const enum_fields = p.enum_buf.items[enum_buf_top..];
    const field_nodes = p.list_buf.items[list_buf_top..];

    if (fixed_qt == null) {
        // Coerce all fields to final type.
        for (enum_fields, field_nodes) |*field, field_node| {
            if (field.qt.eql(.int, p.comp)) continue;

            const sym = p.syms.get(field.name, .vars) orelse continue;
            if (sym.kind != .enumeration) continue; // already an error

            var res: Result = .{ .node = undefined, .qt = field.qt, .val = sym.val };
            const dest_ty: QualType = if (p.comp.fixedEnumTagType()) |some|
                some
            else if (try res.intFitsInType(p, .int))
                .int
            else if (!res.qt.eql(enum_ty.tag, p.comp))
                enum_ty.tag
            else
                continue;

            const symbol = p.syms.getPtr(field.name, .vars);
            _ = try symbol.val.intCast(dest_ty, p.comp);

            symbol.qt = dest_ty;
            field.qt = dest_ty;
            res.qt = dest_ty;

            // Create a new enum_field node with the correct type.
            var new_field_node = field_node.get(&p.tree);
            new_field_node.enum_field.qt = dest_ty;

            if (field.init.unpack()) |some| {
                res.node = some;
                try res.implicitCast(p, .int_cast, some.tok(&p.tree));
                field.init = .pack(res.node);
                new_field_node.enum_field.init = res.node;
            }

            try p.tree.setNode(new_field_node, @intFromEnum(field_node));
        }
    }

    { // Override previous incomplete type
        enum_ty.fields = enum_fields;
        enum_ty.incomplete = false;
        const base_type = attributed_qt.base(p.comp);
        std.debug.assert(base_type.type.@"enum".name == enum_ty.name);
        try p.comp.type_store.set(p.gpa, .{ .@"enum" = enum_ty }, @intFromEnum(base_type.qt._index));
    }

    // declare a symbol for the type
    if (maybe_ident != null and !defined) {
        try p.syms.define(p.gpa, .{
            .kind = .@"enum",
            .name = enum_ty.name,
            .qt = attributed_qt,
            .tok = maybe_ident.?,
            .val = .{},
        });
    }

    // finish by creating a node
    const node = try p.addNode(.{ .enum_decl = .{
        .name_or_kind_tok = maybe_ident orelse enum_tok,
        .container_qt = attributed_qt,
        .fields = field_nodes,
    } });
    p.decl_buf.items[decl_buf_top - 1] = node;

    if (p.func.qt == null) {
        _ = p.tentative_defs.remove(enum_ty.name);
    }
    return attributed_qt;
}

fn checkEnumFixedTy(p: *Parser, fixed_ty: ?QualType, ident_tok: TokenIndex, prev: Symbol) !void {
    const enum_ty = prev.qt.get(p.comp, .@"enum").?;
    if (fixed_ty) |some| {
        if (!enum_ty.fixed) {
            try p.errTok(.enum_prev_nonfixed, ident_tok);
            try p.errTok(.previous_definition, prev.tok);
            return error.ParsingFailed;
        }

        if (!enum_ty.tag.?.eql(some, p.comp)) {
            const str = try p.typePairStrExtra(some, " (was ", enum_ty.tag.?);
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
    qt: QualType,
    num_positive_bits: usize = 0,
    num_negative_bits: usize = 0,
    fixed: bool,

    fn init(fixed_ty: ?QualType) Enumerator {
        return .{
            .qt = fixed_ty orelse .int,
            .fixed = fixed_ty != null,
        };
    }

    /// Increment enumerator value adjusting type if needed.
    fn incr(e: *Enumerator, p: *Parser, tok: TokenIndex) !void {
        const old_val = e.val;
        if (old_val.opt_ref == .none) {
            // First enumerator, set to 0 fits in all types.
            e.val = .zero;
            return;
        }
        if (try e.val.add(e.val, .one, e.qt, p.comp)) {
            if (e.fixed) {
                try p.errStr(.enum_not_representable_fixed, tok, try p.typeStr(e.qt));
                return;
            }
            if (p.comp.nextLargestIntSameSign(e.qt)) |larger| {
                try p.errTok(.enumerator_overflow, tok);
                e.qt = larger;
            } else {
                const signed = e.qt.signedness(p.comp) == .signed;
                const bit_size: u8 = @intCast(e.qt.bitSizeof(p.comp) - @intFromBool(signed));
                try p.errExtra(.enum_not_representable, tok, .{ .pow_2_as_string = bit_size });
                e.qt = .ulong_long;
            }
            _ = try e.val.add(old_val, .one, e.qt, p.comp);
        }
    }

    /// Set enumerator value to specified value.
    fn set(e: *Enumerator, p: *Parser, res: *Result, tok: TokenIndex) !void {
        if (res.qt.isInvalid()) return;
        if (e.fixed and !res.qt.eql(e.qt, p.comp)) {
            if (!try res.intFitsInType(p, e.qt)) {
                try p.errStr(.enum_not_representable_fixed, tok, try p.typeStr(e.qt));
                return error.ParsingFailed;
            }
            res.qt = e.qt;
            try res.implicitCast(p, .int_cast, tok);
            e.val = res.val;
        } else {
            try res.castToInt(p, res.qt.promoteInt(p.comp), tok);
            e.qt = res.qt;
            e.val = res.val;
        }
    }

    fn getTypeSpecifier(e: *const Enumerator, p: *Parser, is_packed: bool, tok: TokenIndex) !QualType {
        if (p.comp.fixedEnumTagType()) |tag_specifier| return tag_specifier;

        const char_width = Type.Int.schar.bits(p.comp);
        const short_width = Type.Int.short.bits(p.comp);
        const int_width = Type.Int.int.bits(p.comp);
        if (e.num_negative_bits > 0) {
            if (is_packed and e.num_negative_bits <= char_width and e.num_positive_bits < char_width) {
                return .schar;
            } else if (is_packed and e.num_negative_bits <= short_width and e.num_positive_bits < short_width) {
                return .short;
            } else if (e.num_negative_bits <= int_width and e.num_positive_bits < int_width) {
                return .int;
            }
            const long_width = Type.Int.long.bits(p.comp);
            if (e.num_negative_bits <= long_width and e.num_positive_bits < long_width) {
                return .long;
            }
            const long_long_width = Type.Int.long_long.bits(p.comp);
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
        } else if (e.num_positive_bits <= Type.Int.long.bits(p.comp)) {
            return .ulong;
        }
        return .ulong_long;
    }

    fn str(e: *const Enumerator, p: *Parser) ![]const u8 {
        return (Result{
            .node = undefined, // Result.str does not use the node
            .qt = e.qt,
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

    if (e.qt.signedness(p.comp) == .unsigned or e.val.compare(.gte, .zero, p.comp)) {
        e.num_positive_bits = @max(e.num_positive_bits, e.val.minUnsignedBits(p.comp));
    } else {
        e.num_negative_bits = @max(e.num_negative_bits, e.val.minSignedBits(p.comp));
    }

    if (err_start == p.comp.diagnostics.list.items.len) {
        // only do these warnings if we didn't already warn about overflow or non-representable values
        if (e.val.compare(.lt, .zero, p.comp)) {
            const min_val = try Value.minInt(.int, p.comp);
            if (e.val.compare(.lt, min_val, p.comp)) {
                try p.errStr(.enumerator_too_small, name_tok, try e.str(p));
            }
        } else {
            const max_val = try Value.maxInt(.int, p.comp);
            if (e.val.compare(.gt, max_val, p.comp)) {
                try p.errStr(.enumerator_too_large, name_tok, try e.str(p));
            }
        }
    }

    const attributed_qt = try Attribute.applyEnumeratorAttributes(p, e.qt, attr_buf_top);
    const node = try p.addNode(.{
        .enum_field = .{
            .name_tok = name_tok,
            .qt = attributed_qt,
            .init = field_init,
        },
    });
    try p.tree.value_map.put(p.gpa, node, e.val);

    const interned_name = try p.comp.internString(p.tokSlice(name_tok));
    try p.syms.defineEnumeration(p, interned_name, attributed_qt, name_tok, e.val, node);

    return .{ .field = .{
        .name = interned_name,
        .qt = attributed_qt,
        .name_tok = name_tok,
        .init = .packOpt(field_init),
    }, .node = node };
}

/// typeQual : keyword_const | keyword_restrict | keyword_volatile | keyword_atomic
fn typeQual(p: *Parser, b: *TypeStore.Builder) Error!bool {
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
    qt: QualType,
    old_style_func: ?TokenIndex = null,

    /// What kind of a type did this declarator declare?
    /// Used redundantly with `qt` in case it was set to `.invalid` by `validate`.
    declarator_type: enum { other, func, array, pointer } = .other,

    const Kind = enum { normal, abstract, param, record };

    fn validate(d: *Declarator, p: *Parser, source_tok: TokenIndex) Parser.Error!void {
        if (!try validateExtra(p, d.qt, source_tok)) return;
        if (d.declarator_type == .func) return;
        if (d.qt.isAutoType() or d.qt.isC23Auto()) return;
        d.qt = .invalid;
    }

    // Returns true if the type contained invalid or auto types.
    fn validateExtra(p: *Parser, cur: QualType, source_tok: TokenIndex) Parser.Error!bool {
        if (cur.isInvalid()) return true;
        if (cur.isAutoType()) return true;
        if (cur.isC23Auto()) return true;

        switch (cur.type(p.comp)) {
            .pointer => |pointer_ty| {
                return validateExtra(p, pointer_ty.child, source_tok);
            },
            .array => |array_ty| {
                const elem_qt = array_ty.elem;
                if (try validateExtra(p, elem_qt, source_tok)) return true;

                if (elem_qt.sizeofOrNull(p.comp) == null) {
                    try p.errStr(.array_incomplete_elem, source_tok, try p.typeStr(elem_qt));
                    return true;
                }
                if (elem_qt.is(p.comp, .func)) {
                    try p.errTok(.array_func_elem, source_tok);
                    return true;
                }
                if (array_ty.len == .static and elem_qt.is(p.comp, .array)) {
                    try p.errTok(.static_non_outermost_array, source_tok);
                }
                if (cur.isQualified() and elem_qt.is(p.comp, .array)) {
                    try p.errTok(.qualifier_non_outermost_array, source_tok);
                }
                return false;
            },
            .func => |func_ty| {
                const ret_qt = func_ty.return_type;
                if (try validateExtra(p, ret_qt, source_tok)) return true;

                if (ret_qt.is(p.comp, .array)) try p.errTok(.func_cannot_return_array, source_tok);
                if (ret_qt.is(p.comp, .func)) try p.errTok(.func_cannot_return_func, source_tok);
                if (ret_qt.@"const") {
                    try p.errStr(.qual_on_ret_type, source_tok, "const");
                }
                if (ret_qt.@"volatile") {
                    try p.errStr(.qual_on_ret_type, source_tok, "volatile");
                }
                if (ret_qt.get(p.comp, .float)) |float| {
                    if (float == .fp16 and !p.comp.hasHalfPrecisionFloatABI()) {
                        try p.errStr(.suggest_pointer_for_invalid_fp16, source_tok, "function return value");
                    }
                }
                return false;
            },
            else => return false,
        }
    }
};

/// declarator : pointer? (IDENTIFIER | '(' declarator ')') directDeclarator*
/// abstractDeclarator
/// : pointer? ('(' abstractDeclarator ')')? directAbstractDeclarator*
/// pointer : '*' typeQual* pointer?
fn declarator(
    p: *Parser,
    base_qt: QualType,
    kind: Declarator.Kind,
) Error!?Declarator {
    const start = p.tok_i;
    var d = Declarator{ .name = 0, .qt = base_qt };

    // Parse potential pointer declarators first.
    while (p.eatToken(.asterisk)) |_| {
        d.declarator_type = .pointer;
        var builder: TypeStore.Builder = .{ .parser = p };
        _ = try p.typeQual(&builder);

        const pointer_qt = try p.comp.type_store.put(p.gpa, .{ .pointer = .{
            .child = d.qt,
            .decayed = null,
        } });
        d.qt = try builder.finishQuals(pointer_qt);
    }

    const maybe_ident = p.tok_i;
    if (kind != .abstract and (try p.eatIdentifier()) != null) {
        d.name = maybe_ident;
        const combine_tok = p.tok_i;
        d.qt = try p.directDeclarator(&d, kind);
        try d.validate(p, combine_tok);
        return d;
    } else if (p.eatToken(.l_paren)) |l_paren| blk: {
        var res = (try p.declarator(.invalid, kind)) orelse {
            p.tok_i = l_paren;
            break :blk;
        };
        try p.expectClosing(l_paren, .r_paren);
        const suffix_start = p.tok_i;
        const outer = try p.directDeclarator(&d, kind);

        // Correct the base type now that it is known.
        // If outer is invalid there was no pointer, array or function type.
        if (outer.isInvalid() or res.qt.isInvalid()) {
            res.qt = outer;
        } else {
            var cur = res.qt;
            while (true) {
                switch (cur.type(p.comp)) {
                    .pointer => |pointer_ty| if (!pointer_ty.child.isInvalid()) {
                        cur = pointer_ty.child;
                        continue;
                    },
                    .array => |array_ty| if (!array_ty.elem.isInvalid()) {
                        cur = array_ty.elem;
                        continue;
                    },
                    .func => |func_ty| if (!func_ty.return_type.isInvalid()) {
                        cur = func_ty.return_type;
                        continue;
                    },
                    else => unreachable,
                }
                // Child type is always stored in repr.data[0]
                p.comp.type_store.types.items(.data)[@intFromEnum(cur._index)][0] = @bitCast(outer);
                break;
            }
        }

        try res.validate(p, suffix_start);
        return res;
    }

    const expected_ident = p.tok_i;

    d.qt = try p.directDeclarator(&d, kind);

    if (kind == .normal and !d.qt.isInvalid()) {
        switch (d.qt.base(p.comp).type) {
            .@"enum", .@"struct", .@"union" => {},
            else => {
                try p.errTok(.expected_ident_or_l_paren, expected_ident);
                return error.ParsingFailed;
            },
        }
    }
    try d.validate(p, expected_ident);
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
fn directDeclarator(
    p: *Parser,
    base_declarator: *Declarator,
    kind: Declarator.Kind,
) Error!QualType {
    if (p.eatToken(.l_bracket)) |l_bracket| {
        // Check for C23 attribute
        if (p.tok_ids[p.tok_i] == .l_bracket) {
            switch (kind) {
                .normal, .record => if (p.comp.langopts.standard.atLeast(.c23)) {
                    p.tok_i -= 1;
                    return base_declarator.qt;
                },
                .param, .abstract => {},
            }
            try p.err(.expected_expr);
            return error.ParsingFailed;
        }

        var builder: TypeStore.Builder = .{ .parser = p };

        var got_quals = try p.typeQual(&builder);
        var static = p.eatToken(.keyword_static);
        if (static != null and !got_quals) got_quals = try p.typeQual(&builder);
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
            builder = .{ .parser = p };
            star = null;
        }
        if (static) |_| _ = try p.expectResult(opt_size);

        const outer = try p.directDeclarator(base_declarator, kind);

        // Set after call to `directDeclarator` since we will return an
        // array type from here.
        base_declarator.declarator_type = .array;

        if (opt_size != null and !opt_size.?.qt.isInt(p.comp)) {
            try p.errStr(.array_size_non_int, size_tok, try p.typeStr(opt_size.?.qt));
            return error.ParsingFailed;
        }

        if (opt_size) |size| {
            if (size.val.opt_ref == .none) {
                try p.errTok(.vla, size_tok);
                if (p.func.qt == null and kind != .param and p.record.kind == .invalid) {
                    try p.errTok(.variable_len_array_file_scope, base_declarator.name);
                }

                const array_qt = try p.comp.type_store.put(p.gpa, .{ .array = .{
                    .elem = outer,
                    .len = .{ .variable = size.node },
                } });

                if (static) |some| try p.errTok(.useless_static, some);
                return builder.finishQuals(array_qt);
            } else {
                if (size.val.isZero(p.comp)) {
                    try p.errTok(.zero_length_array, l_bracket);
                } else if (size.val.compare(.lt, .zero, p.comp)) {
                    try p.errTok(.negative_array_size, l_bracket);
                    return error.ParsingFailed;
                }

                var len = size.val.toInt(u64, p.comp) orelse std.math.maxInt(u64);

                // `outer` is validated later so it may be invalid here
                if (!outer.isInvalid() and !outer.isAutoType() and !outer.isC23Auto()) {
                    const outer_size = outer.sizeofOrNull(p.comp) orelse 1;
                    const max_elems = p.comp.maxArrayBytes() / @max(1, outer_size);
                    if (len > max_elems) {
                        try p.errTok(.array_too_large, l_bracket);
                        len = max_elems;
                    }
                }

                const array_qt = try p.comp.type_store.put(p.gpa, .{ .array = .{
                    .elem = outer,
                    .len = if (static != null)
                        .{ .static = len }
                    else
                        .{ .fixed = len },
                } });
                return builder.finishQuals(array_qt);
            }
        } else if (star) |_| {
            const array_qt = try p.comp.type_store.put(p.gpa, .{ .array = .{
                .elem = outer,
                .len = .unspecified_variable,
            } });
            return builder.finishQuals(array_qt);
        } else {
            const array_qt = try p.comp.type_store.put(p.gpa, .{ .array = .{
                .elem = outer,
                .len = .incomplete,
            } });
            return builder.finishQuals(array_qt);
        }
    } else if (p.eatToken(.l_paren)) |l_paren| {
        var func_ty: Type.Func = .{
            .kind = undefined,
            .return_type = undefined,
            .params = &.{},
        };

        if (p.eatToken(.ellipsis)) |_| {
            try p.err(.param_before_var_args);
            try p.expectClosing(l_paren, .r_paren);
            func_ty.kind = if (p.comp.langopts.standard.atLeast(.c23)) .variadic else .normal;

            func_ty.return_type = try p.directDeclarator(base_declarator, kind);
            return p.comp.type_store.put(p.gpa, .{ .func = func_ty });
        }

        // Set here so the call to directDeclarator for the return type
        // doesn't clobber this function type's parameters.
        const param_buf_top = p.param_buf.items.len;
        defer p.param_buf.items.len = param_buf_top;

        if (try p.paramDecls(base_declarator)) |params| {
            func_ty.kind = .normal;
            func_ty.params = params;
            if (p.eatToken(.ellipsis)) |_| func_ty.kind = .variadic;
        } else if (p.tok_ids[p.tok_i] == .r_paren) {
            func_ty.kind = if (p.comp.langopts.standard.atLeast(.c23))
                .normal
            else
                .old_style;
        } else if (p.tok_ids[p.tok_i] == .identifier or p.tok_ids[p.tok_i] == .extended_identifier) {
            base_declarator.old_style_func = p.tok_i;
            try p.syms.pushScope(p);
            defer p.syms.popScope();

            func_ty.kind = .old_style;
            while (true) {
                const name_tok = try p.expectIdentifier();
                const interned_name = try p.comp.internString(p.tokSlice(name_tok));
                try p.syms.defineParam(p, interned_name, undefined, name_tok, null);
                try p.param_buf.append(.{
                    .name = interned_name,
                    .name_tok = name_tok,
                    .qt = .int,
                    .node = .null,
                });
                if (p.eatToken(.comma) == null) break;
            }
            func_ty.params = p.param_buf.items[param_buf_top..];
        } else {
            try p.err(.expected_param_decl);
        }

        try p.expectClosing(l_paren, .r_paren);
        func_ty.return_type = try p.directDeclarator(base_declarator, kind);

        // Set after call to `directDeclarator` since we will return
        // a function type from here.
        base_declarator.declarator_type = .func;

        return p.comp.type_store.put(p.gpa, .{ .func = func_ty });
    } else return base_declarator.qt;
}

/// paramDecls : paramDecl (',' paramDecl)* (',' '...')
/// paramDecl : declSpec (declarator | abstractDeclarator)
fn paramDecls(p: *Parser, d: *Declarator) Error!?[]Type.Func.Param {
    // TODO warn about visibility of types declared here
    try p.syms.pushScope(p);
    defer p.syms.popScope();

    // Clearing the param buf is handled in directDeclarator.
    const param_buf_top = p.param_buf.items.len;

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
                .name = try p.comp.internString(p.tokSlice(identifier)),
                .name_tok = identifier,
                .qt = .int,
                .node = .null,
            });

            if (p.eatToken(.comma) == null) break;
            if (p.tok_ids[p.tok_i] == .ellipsis) break;
            continue;
        } else if (p.param_buf.items.len == param_buf_top) {
            return null;
        } else blk: {
            try p.err(.missing_type_specifier);
            break :blk DeclSpec{ .qt = .int };
        };

        var name_tok: TokenIndex = 0;
        var interned_name: StringId = .empty;
        const first_tok = p.tok_i;
        var param_qt = param_decl_spec.qt;
        if (param_decl_spec.auto_type) |tok_i| {
            try p.errStr(.auto_type_not_allowed, tok_i, "function prototype");
            param_qt = .invalid;
        }
        if (param_decl_spec.c23_auto) |tok_i| {
            try p.errStr(.c23_auto_not_allowed, tok_i, "function prototype");
            param_qt = .invalid;
        }

        if (try p.declarator(param_qt, .param)) |some| {
            if (some.old_style_func) |tok_i| try p.errTok(.invalid_old_style_params, tok_i);
            try p.attributeSpecifier();
            name_tok = some.name;
            param_qt = some.qt;
        }

        if (param_qt.is(p.comp, .void)) {
            // validate void parameters
            if (p.param_buf.items.len == param_buf_top) {
                if (p.tok_ids[p.tok_i] != .r_paren) {
                    try p.err(.void_only_param);
                    if (param_qt.isQualified()) try p.err(.void_param_qualified);
                    return error.ParsingFailed;
                }
                return &.{};
            }
            try p.err(.void_must_be_first_param);
            return error.ParsingFailed;
        } else {
            // Decay params declared as functions or arrays to pointer.
            param_qt = try param_qt.decay(p.comp);
        }
        try param_decl_spec.validateParam(p);
        param_qt = try Attribute.applyParameterAttributes(p, param_qt, attr_buf_top, .alignas_on_param);

        if (param_qt.get(p.comp, .float)) |float| {
            if (float == .fp16 and !p.comp.hasHalfPrecisionFloatABI()) {
                try p.errStr(.suggest_pointer_for_invalid_fp16, first_tok, "parameters");
            }
        }

        var param_node: Node.OptIndex = .null;
        if (name_tok != 0) {
            const node = try p.addNode(.{
                .param = .{
                    .name_tok = name_tok,
                    .qt = param_qt,
                    .storage_class = switch (param_decl_spec.storage_class) {
                        .none => .auto,
                        .register => .register,
                        else => .auto, // Error reported in `validateParam`
                    },
                },
            });
            param_node = .pack(node);
            interned_name = try p.comp.internString(p.tokSlice(name_tok));
            try p.syms.defineParam(p, interned_name, param_qt, name_tok, node);
        }

        try p.param_buf.append(.{
            .name = interned_name,
            .name_tok = if (name_tok == 0) first_tok else name_tok,
            .qt = param_qt,
            .node = param_node,
        });

        if (p.eatToken(.comma) == null) break;
        if (p.tok_ids[p.tok_i] == .ellipsis) break;
    }
    return p.param_buf.items[param_buf_top..];
}

/// typeName : specQual abstractDeclarator
fn typeName(p: *Parser) Error!?QualType {
    const attr_buf_top = p.attr_buf.len;
    defer p.attr_buf.len = attr_buf_top;
    const ty = (try p.specQual()) orelse return null;
    if (try p.declarator(ty, .abstract)) |some| {
        if (some.old_style_func) |tok_i| try p.errTok(.invalid_old_style_params, tok_i);
        return try Attribute.applyTypeAttributes(p, some.qt, attr_buf_top, .align_ignored);
    }
    return try Attribute.applyTypeAttributes(p, ty, attr_buf_top, .align_ignored);
}

fn complexInitializer(p: *Parser, init_ty: QualType) Error!Result {
    assert(p.tok_ids[p.tok_i] == .l_brace);
    assert(init_ty.is(p.comp, .complex));

    const real_ty = init_ty.toReal(p.comp);
    if (real_ty.isInt(p.comp)) {
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
            .container_qt = init_ty,
            .items = if (second) |some|
                &.{ first.node, some.node }
            else
                &.{first.node},
            .l_brace_tok = l_brace,
        } }),
        .qt = init_ty,
    };

    const first_val = p.tree.value_map.get(first.node) orelse return res;
    const second_val = if (second) |some| p.tree.value_map.get(some.node) orelse return res else Value.zero;
    res.val = try Value.intern(p.comp, switch (real_ty.bitSizeof(p.comp)) {
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
fn initializer(p: *Parser, init_qt: QualType) Error!Result {
    // fast path for non-braced initializers
    if (p.tok_ids[p.tok_i] != .l_brace) {
        const tok = p.tok_i;
        var res = try p.expect(assignExpr);
        if (try p.coerceArrayInit(&res, tok, init_qt)) return res;
        try p.coerceInit(&res, tok, init_qt);
        return res;
    }

    // We want to parse the initializer even if the target is
    // invalidly inferred.
    var final_init_qt = init_qt;
    if (init_qt.isAutoType()) {
        try p.err(.auto_type_with_init_list);
        final_init_qt = .invalid;
    } else if (init_qt.isC23Auto()) {
        try p.err(.c23_auto_with_init_list);
        final_init_qt = .invalid;
    }

    if (final_init_qt.is(p.comp, .complex)) {
        return p.complexInitializer(final_init_qt);
    }
    var il: InitList = .{};
    defer il.deinit(p.gpa);

    _ = try p.initializerItem(&il, final_init_qt);

    const res = try p.convertInitList(il, final_init_qt);
    return .{ .qt = res.qt(&p.tree).withQualifiers(final_init_qt), .node = res };
}

/// initializerItems : designation? initializer (',' designation? initializer)* ','?
/// designation : designator+ '='
/// designator
///  : '[' integerConstExpr ']'
///  | '.' identifier
fn initializerItem(p: *Parser, il: *InitList, init_ty: QualType) Error!bool {
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

    const is_scalar, const is_complex = blk: {
        if (init_ty.isInvalid()) break :blk .{ false, false };
        const scalar_kind = init_ty.scalarKind(p.comp);
        break :blk .{ scalar_kind != .none, !scalar_kind.isReal() };
    };

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
        var cur_qt = init_ty;
        var cur_il = il;
        var designation = false;
        var cur_index_hint: ?u64 = null;
        while (true) {
            if (p.eatToken(.l_bracket)) |l_bracket| {
                const array_ty = cur_qt.get(p.comp, .array) orelse {
                    try p.errStr(.invalid_array_designator, l_bracket, try p.typeStr(cur_qt));
                    return error.ParsingFailed;
                };
                const expr_tok = p.tok_i;
                const index_res = try p.integerConstExpr(.gnu_folding_extension);
                try p.expectClosing(l_bracket, .r_bracket);

                if (index_res.val.opt_ref == .none) {
                    try p.errTok(.expected_integer_constant_expr, expr_tok);
                    return error.ParsingFailed;
                } else if (index_res.val.compare(.lt, .zero, p.comp)) {
                    try p.errStr(.negative_array_designator, l_bracket + 1, try index_res.str(p));
                    return error.ParsingFailed;
                }

                const max_len = switch (array_ty.len) {
                    .fixed, .static => |len| len,
                    else => std.math.maxInt(u64),
                };
                const index_int = index_res.val.toInt(u64, p.comp) orelse std.math.maxInt(u64);
                if (index_int >= max_len) {
                    try p.errStr(.oob_array_designator, l_bracket + 1, try index_res.str(p));
                    return error.ParsingFailed;
                }
                cur_index_hint = cur_index_hint orelse index_int;

                cur_il = try cur_il.find(p.gpa, index_int);
                cur_qt = array_ty.elem;
                designation = true;
            } else if (p.eatToken(.period)) |period| {
                const field_tok = try p.expectIdentifier();
                const field_str = p.tokSlice(field_tok);
                const field_name = try p.comp.internString(field_str);
                const record_ty = cur_qt.getRecord(p.comp) orelse {
                    try p.errStr(.invalid_field_designator, period, try p.typeStr(cur_qt));
                    return error.ParsingFailed;
                };
                if (!record_ty.hasField(p.comp, field_name)) {
                    try p.errStr(.no_such_field_designator, period, field_str);
                    return error.ParsingFailed;
                }

                // TODO check if union already has field set
                outer: while (true) {
                    for (record_ty.fields, 0..) |field, i| {
                        if (field.name == .empty) if (field.qt.getRecord(p.comp)) |field_record_ty| {
                            // Recurse into anonymous field if it has a field by the name.
                            if (!field_record_ty.hasField(p.comp, field_name)) continue;
                            cur_qt = field.qt;
                            cur_il = try il.find(p.gpa, i);
                            cur_index_hint = cur_index_hint orelse i;
                            continue :outer;
                        };
                        if (field_name == field.name) {
                            cur_il = try cur_il.find(p.gpa, i);
                            cur_qt = field.qt;
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

        if (!designation and cur_qt.hasAttribute(p.comp, .designated_init)) {
            try p.err(.designated_init_needed);
        }

        var saw = false;
        if (is_str_init and p.isStringInit()) {
            // discard further strings
            var tmp_il: InitList = .{};
            defer tmp_il.deinit(p.gpa);
            saw = try p.initializerItem(&tmp_il, .void);
        } else if (count == 0 and p.isStringInit()) {
            is_str_init = true;
            saw = try p.initializerItem(il, init_ty);
        } else if (is_scalar and count >= scalar_inits_needed) {
            // discard further scalars
            var tmp_il: InitList = .{};
            defer tmp_il.deinit(p.gpa);
            saw = try p.initializerItem(&tmp_il, .void);
        } else if (p.tok_ids[p.tok_i] == .l_brace) {
            if (designation) {
                // designation overrides previous value, let existing mechanism handle it
                saw = try p.initializerItem(cur_il, cur_qt);
            } else if (try p.findAggregateInitializer(&cur_il, &cur_qt, &index_hint)) {
                saw = try p.initializerItem(cur_il, cur_qt);
            } else {
                // discard further values
                var tmp_il: InitList = .{};
                defer tmp_il.deinit(p.gpa);
                saw = try p.initializerItem(&tmp_il, .void);
                if (!warned_excess) try p.errTok(if (init_ty.is(p.comp, .array)) .excess_array_init else .excess_struct_init, first_tok);
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
                    if (try p.findScalarInitializerAt(&cur_il, &cur_qt, &res, first_tok, hint)) break :excess;
                } else if (try p.findScalarInitializer(&cur_il, &cur_qt, &res, first_tok)) break :excess;

                if (designation) break :excess;
                if (!warned_excess) try p.errTok(if (init_ty.is(p.comp, .array)) .excess_array_init else .excess_struct_init, first_tok);
                warned_excess = true;

                break :single_item;
            }

            const arr = try p.coerceArrayInit(&res, first_tok, cur_qt);
            if (!arr) try p.coerceInit(&res, first_tok, cur_qt);
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
            if (is_scalar and !is_complex) try p.errTok(.excess_scalar_init, first_tok);
        }

        if (p.eatToken(.comma) == null) break;
    }
    try p.expectClosing(l_brace, .r_brace);

    if (is_scalar and is_complex and count == 1) { // count of 1 means we saw exactly 2 items in the initializer list
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
fn findScalarInitializerAt(p: *Parser, il: **InitList, qt: *QualType, res: *Result, first_tok: TokenIndex, start_index: *u64) Error!bool {
    switch (qt.base(p.comp).type) {
        .array => |array_ty| {
            if (il.*.node != .null) return false;
            start_index.* += 1;

            const max_len = switch (array_ty.len) {
                .fixed, .static => |len| len,
                else => std.math.maxInt(u64),
            };
            if (max_len == 0) {
                try p.errTok(.empty_aggregate_init_braces, first_tok);
                return error.ParsingFailed;
            }

            const arr_il = il.*;
            if (start_index.* < max_len) {
                qt.* = array_ty.elem;
                il.* = try arr_il.find(p.gpa, start_index.*);
                _ = try p.findScalarInitializer(il, qt, res, first_tok);
                return true;
            }
            return false;
        },
        .@"struct" => |struct_ty| {
            if (il.*.node != .null) return false;
            start_index.* += 1;

            if (struct_ty.fields.len == 0) {
                try p.errTok(.empty_aggregate_init_braces, first_tok);
                return error.ParsingFailed;
            }
            const struct_il = il.*;
            if (start_index.* < struct_ty.fields.len) {
                qt.* = struct_ty.fields[@intCast(start_index.*)].qt;
                il.* = try struct_il.find(p.gpa, start_index.*);
                _ = try p.findScalarInitializer(il, qt, res, first_tok);
                return true;
            }
            return false;
        },
        .@"union" => {
            return false;
        },
        else => return il.*.node == .null,
    }
}

/// Returns true if the value is unused.
fn findScalarInitializer(p: *Parser, il: **InitList, qt: *QualType, res: *Result, first_tok: TokenIndex) Error!bool {
    const actual_qt = res.qt;
    if (qt.isInvalid()) return il.*.node == .null;
    switch (qt.base(p.comp).type) {
        // .complex  TODO
        .array => |array_ty| {
            if (il.*.node != .null) return false;
            if (try p.coerceArrayInitExtra(res, first_tok, qt.*, false)) return true;

            const start_index = il.*.list.items.len;
            var index = if (start_index != 0) il.*.list.items[start_index - 1].index else start_index;

            const max_len = switch (array_ty.len) {
                .fixed, .static => |len| len,
                else => std.math.maxInt(u64),
            };
            if (max_len == 0) {
                try p.errTok(.empty_aggregate_init_braces, first_tok);
                return error.ParsingFailed;
            }

            const arr_il = il.*;
            while (index < max_len) : (index += 1) {
                qt.* = array_ty.elem;
                il.* = try arr_il.find(p.gpa, index);

                if (il.*.node == .null and actual_qt.eql(array_ty.elem, p.comp)) return true;
                if (try p.findScalarInitializer(il, qt, res, first_tok)) return true;
            }
            return false;
        },
        .@"struct" => |struct_ty| {
            if (il.*.node != .null) return false;
            if (actual_qt.eql(qt.*, p.comp)) return true;
            const start_index = il.*.list.items.len;
            var index = if (start_index != 0) il.*.list.items[start_index - 1].index + 1 else start_index;

            if (struct_ty.fields.len == 0) {
                try p.errTok(.empty_aggregate_init_braces, first_tok);
                return error.ParsingFailed;
            }
            const struct_il = il.*;
            while (index < struct_ty.fields.len) : (index += 1) {
                const field = struct_ty.fields[@intCast(index)];
                qt.* = field.qt;
                il.* = try struct_il.find(p.gpa, index);

                if (il.*.node == .null and actual_qt.eql(field.qt, p.comp)) return true;
                if (il.*.node == .null and try p.coerceArrayInitExtra(res, first_tok, qt.*, false)) return true;
                if (try p.findScalarInitializer(il, qt, res, first_tok)) return true;
            }
            return false;
        },
        .@"union" => |union_ty| {
            if (il.*.node != .null) return false;
            if (actual_qt.eql(qt.*, p.comp)) return true;
            if (union_ty.fields.len == 0) {
                try p.errTok(.empty_aggregate_init_braces, first_tok);
                return error.ParsingFailed;
            }

            qt.* = union_ty.fields[0].qt;
            il.* = try il.*.find(p.gpa, 0);

            // if (il.*.node == null and actual_ty.eql(ty, p.comp, false)) return true;
            if (try p.coerceArrayInitExtra(res, first_tok, qt.*, false)) return true;
            if (try p.findScalarInitializer(il, qt, res, first_tok)) return true;
            return false;
        },
        else => return il.*.node == .null,
    }
}

fn findAggregateInitializer(p: *Parser, il: **InitList, qt: *QualType, start_index: *?u64) Error!bool {
    if (qt.isInvalid()) return il.*.node == .null;
    switch (qt.base(p.comp).type) {
        .array => |array_ty| {
            if (il.*.node != .null) return false;
            const list_index = il.*.list.items.len;
            const index = if (start_index.*) |*some| blk: {
                some.* += 1;
                break :blk some.*;
            } else if (list_index != 0)
                il.*.list.items[list_index - 1].index + 1
            else
                list_index;

            const max_len = switch (array_ty.len) {
                .fixed, .static => |len| len,
                else => std.math.maxInt(u64),
            };
            if (index < max_len) {
                qt.* = array_ty.elem;
                il.* = try il.*.find(p.gpa, index);
                return true;
            }
            return false;
        },
        .@"struct" => |struct_ty| {
            if (il.*.node != .null) return false;
            const list_index = il.*.list.items.len;
            const index = if (start_index.*) |*some| blk: {
                some.* += 1;
                break :blk some.*;
            } else if (list_index != 0)
                il.*.list.items[list_index - 1].index + 1
            else
                list_index;

            const field_count = struct_ty.fields.len;
            if (index < field_count) {
                qt.* = struct_ty.fields[@intCast(index)].qt;
                il.* = try il.*.find(p.gpa, index);
                return true;
            }
            return false;
        },
        .@"union" => |union_ty| {
            if (il.*.node != .null) return false;
            if (start_index.*) |_| return false; // overrides
            if (union_ty.fields.len == 0) return false;

            qt.* = union_ty.fields[0].qt;
            il.* = try il.*.find(p.gpa, 0);
            return true;
        },
        else => {
            try p.err(.too_many_scalar_init_braces);
            return il.*.node == .null;
        },
    }
}

fn coerceArrayInit(p: *Parser, item: *Result, tok: TokenIndex, target: QualType) !bool {
    return p.coerceArrayInitExtra(item, tok, target, true);
}

fn coerceArrayInitExtra(p: *Parser, item: *Result, tok: TokenIndex, target: QualType, report_err: bool) !bool {
    if (target.isInvalid()) return false;
    const target_array_ty = target.get(p.comp, .array) orelse return false;

    const is_str_lit = p.nodeIs(item.node, .string_literal_expr);
    const maybe_item_array_ty = item.qt.get(p.comp, .array);
    if (!is_str_lit and (!p.nodeIs(item.node, .compound_literal_expr) or maybe_item_array_ty == null)) {
        if (!report_err) return false;
        try p.errTok(.array_init_str, tok);
        return true; // do not do further coercion
    }

    const target_elem = target_array_ty.elem;
    const item_elem = maybe_item_array_ty.?.elem;

    const target_int = target_elem.get(p.comp, .int);
    const item_int = item_elem.get(p.comp, .int);

    const compatible = target_elem.eql(item_elem, p.comp) or
        (is_str_lit and item_int.? == .char and (target_int.? == .uchar or target_int.? == .schar)) or
        (is_str_lit and item_int.? == .uchar and (target_int.? == .uchar or target_int.? == .schar or target_int.? == .char));
    if (!compatible) {
        if (!report_err) return false;
        const e_msg = " with array of type ";
        try p.errStr(.incompatible_array_init, tok, try p.typePairStrExtra(target, e_msg, item.qt));
        return true; // do not do further coercion
    }

    if (target_array_ty.len == .fixed) {
        const target_len = target_array_ty.len.fixed;
        const item_len = switch (maybe_item_array_ty.?.len) {
            .fixed, .static => |len| len,
            else => unreachable,
        };

        if (is_str_lit) {
            // the null byte of a string can be dropped
            if (item_len - 1 > target_len and report_err) {
                try p.errTok(.str_init_too_long, tok);
            }
        } else if (item_len > target_len and report_err) {
            try p.errStr(
                .arr_init_too_long,
                tok,
                try p.typePairStrExtra(target, " with array of type ", item.qt),
            );
        }
    }
    return true;
}

fn coerceInit(p: *Parser, item: *Result, tok: TokenIndex, target: QualType) !void {
    if (target.is(p.comp, .void)) return; // Do not do type coercion on excess items

    const node = item.node;
    try item.lvalConversion(p, tok);
    if (target.isAutoType() or target.isC23Auto()) {
        if (p.getNode(node, .member_access_expr) orelse p.getNode(node, .member_access_ptr_expr)) |access| {
            if (access.isBitFieldWidth(&p.tree) != null) try p.errTok(.auto_type_from_bitfield, tok);
        }
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
    if (target.@"const" or p.init_context == .constexpr) {
        var copy = item.*;
        return copy.saveValue(p);
    }
    return item.saveValue(p);
}

fn isStringInit(p: *Parser) bool {
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
fn convertInitList(p: *Parser, il: InitList, init_qt: QualType) Error!Node.Index {
    if (init_qt.isInvalid()) {
        return try p.addNode(.{ .default_init_expr = .{
            .last_tok = p.tok_i,
            .qt = init_qt,
        } });
    }

    const scalar_kind = init_qt.scalarKind(p.comp);
    if (scalar_kind != .none and scalar_kind.isReal()) {
        return il.node.unpack() orelse
            try p.addNode(.{ .default_init_expr = .{
            .last_tok = il.tok,
            .qt = init_qt,
        } });
    }

    switch (init_qt.base(p.comp).type) {
        // .complex => TODO
        .array => |array_ty| {
            if (il.node.unpack()) |some| return some;

            const list_buf_top = p.list_buf.items.len;
            defer p.list_buf.items.len = list_buf_top;

            const elem_ty = init_qt.childType(p.comp);

            const max_len = switch (array_ty.len) {
                .fixed, .static => |len| len,
                // vla invalid, reported earlier
                .variable => return try p.addNode(.{ .default_init_expr = .{
                    .last_tok = p.tok_i,
                    .qt = init_qt,
                } }),
                else => std.math.maxInt(u64),
            };
            var start: u64 = 0;
            for (il.list.items) |*init| {
                if (init.index > start) {
                    const elem = try p.addNode(.{
                        .array_filler_expr = .{
                            .last_tok = p.tok_i - 1,
                            .count = init.index - start,
                            .qt = elem_ty,
                        },
                    });
                    try p.list_buf.append(elem);
                }
                start = init.index + 1;

                const elem = try p.convertInitList(init.list, elem_ty);
                try p.list_buf.append(elem);
            }

            const max_elems = p.comp.maxArrayBytes() / (@max(1, elem_ty.sizeofOrNull(p.comp) orelse 1));
            if (start > max_elems) {
                try p.errTok(.array_too_large, il.tok);
                start = max_elems;
            }

            var arr_init_qt = init_qt;
            if (array_ty.len == .incomplete) {
                arr_init_qt = try p.comp.type_store.put(p.gpa, .{ .array = .{
                    .elem = array_ty.elem,
                    .len = .{ .fixed = start },
                } });
            } else if (start < max_len) {
                const elem = try p.addNode(.{
                    .array_filler_expr = .{
                        .last_tok = p.tok_i - 1,
                        .count = max_len - start,
                        .qt = elem_ty,
                    },
                });
                try p.list_buf.append(elem);
            }

            return p.addNode(.{ .array_init_expr = .{
                .l_brace_tok = il.tok,
                .container_qt = arr_init_qt,
                .items = p.list_buf.items[list_buf_top..],
            } });
        },
        .@"struct" => |struct_ty| {
            assert(struct_ty.layout != null);
            if (il.node.unpack()) |some| return some;

            const list_buf_top = p.list_buf.items.len;
            defer p.list_buf.items.len = list_buf_top;

            var init_index: usize = 0;
            for (struct_ty.fields, 0..) |field, i| {
                if (init_index < il.list.items.len and il.list.items[init_index].index == i) {
                    const item = try p.convertInitList(il.list.items[init_index].list, field.qt);
                    try p.list_buf.append(item);
                    init_index += 1;
                } else {
                    const item = try p.addNode(.{
                        .default_init_expr = .{
                            .last_tok = il.tok,
                            .qt = field.qt,
                        },
                    });
                    try p.list_buf.append(item);
                }
            }

            return p.addNode(.{ .struct_init_expr = .{
                .l_brace_tok = il.tok,
                .container_qt = init_qt,
                .items = p.list_buf.items[list_buf_top..],
            } });
        },
        .@"union" => |union_ty| {
            if (il.node.unpack()) |some| return some;

            const init_node, const index = if (union_ty.fields.len == 0)
                // do nothing for empty unions
                .{ null, 0 }
            else if (il.list.items.len == 0)
                .{ try p.addNode(.{ .default_init_expr = .{
                    .last_tok = p.tok_i - 1,
                    .qt = init_qt,
                } }), 0 }
            else blk: {
                const init = il.list.items[0];
                const index: u32 = @truncate(init.index);
                const field_qt = union_ty.fields[index].qt;

                break :blk .{ try p.convertInitList(init.list, field_qt), index };
            };
            return p.addNode(.{ .union_init_expr = .{
                .field_index = index,
                .initializer = init_node,
                .l_brace_tok = il.tok,
                .union_qt = init_qt,
            } });
        },
        // initializer target is invalid, reported earlier
        else => return try p.addNode(.{ .default_init_expr = .{
            .last_tok = p.tok_i,
            .qt = init_qt,
        } }),
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

            const label_addr_node = try p.addNode(.{
                .addr_of_label = .{
                    .label_tok = label,
                    .qt = .void_pointer,
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
        .qt = .void,
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
        if (cond.qt.scalarKind(p.comp) == .none)
            try p.errStr(.statement_scalar, l_paren + 1, try p.typeStr(cond.qt));
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

        if (!cond.qt.isInt(p.comp))
            try p.errStr(.statement_int, l_paren + 1, try p.typeStr(cond.qt));
        try cond.saveValue(p);
        try p.expectClosing(l_paren, .r_paren);

        const old_switch = p.@"switch";
        var @"switch" = Switch{
            .ranges = std.ArrayList(Switch.Range).init(p.gpa),
            .qt = cond.qt,
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
        if (cond.qt.scalarKind(p.comp) == .none)
            try p.errStr(.statement_scalar, l_paren + 1, try p.typeStr(cond.qt));
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

        if (cond.qt.scalarKind(p.comp) == .none)
            try p.errStr(.statement_scalar, l_paren + 1, try p.typeStr(cond.qt));
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
            if (cond.qt.scalarKind(p.comp) == .none)
                try p.errStr(.statement_scalar, l_paren + 1, try p.typeStr(cond.qt));
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

            const scalar_kind = goto_expr.qt.scalarKind(p.comp);
            if (!scalar_kind.isPointer()) {
                const result_qt: QualType = .{ .@"const" = true, ._index = .void_pointer };
                if (!scalar_kind.isInt()) {
                    try p.errStr(.incompatible_arg, expr_tok, try p.typePairStrExtra(goto_expr.qt, " to parameter of incompatible type ", result_qt));
                    return error.ParsingFailed;
                }
                if (goto_expr.val.isZero(p.comp)) {
                    try goto_expr.nullToPointer(p, result_qt, expr_tok);
                } else {
                    try p.errStr(.implicit_int_to_ptr, expr_tok, try p.typePairStrExtra(goto_expr.qt, " to ", result_qt));
                    try goto_expr.castToPointer(p, result_qt, expr_tok);
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
            .qt = try Attribute.applyStatementAttributes(p, expr_start, attr_buf_top),
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
            .qt = try Attribute.applyLabelAttributes(p, attr_buf_top),
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
            if (some.qt.sizeofOrNull(p.comp) == null) break :check; // error already reported for incomplete size

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
            .qt = .void,
        } });
    }
    return p.stmt();
}

const StmtExprState = struct {
    last_expr_tok: TokenIndex = 0,
    last_expr_qt: QualType = .void,
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
                .last_expr_qt = s.qt(&p.tree),
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

        const ret_qt: QualType = if (p.func.qt.?.get(p.comp, .func)) |func_ty| func_ty.return_type else .invalid;
        if (last_noreturn != .yes and !ret_qt.isInvalid()) {
            var return_zero = false;
            if (last_noreturn == .no) switch (ret_qt.base(p.comp).type) {
                .void => {},
                .func, .array => {}, // Invalid, error reported elsewhere
                else => {
                    const func_name = p.tokSlice(p.func.name);
                    const interned_name = try p.comp.internString(func_name);

                    if (interned_name == p.string_ids.main_id) {
                        if (ret_qt.get(p.comp, .int)) |int_ty| {
                            if (int_ty == .int) return_zero = true;
                        }
                    }

                    if (!return_zero) {
                        try p.errStr(.func_does_not_return, p.tok_i - 1, func_name);
                    }
                },
            };

            const implicit_ret = try p.addNode(.{ .return_stmt = .{
                .return_tok = r_brace,
                .return_qt = ret_qt,
                .operand = .{ .implicit = return_zero },
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

    const func_qt = p.func.qt.?; // `return` cannot be parsed outside of a function.
    const ret_qt: QualType = if (func_qt.get(p.comp, .func)) |func_ty| func_ty.return_type else .invalid;
    const ret_void = !ret_qt.isInvalid() and ret_qt.is(p.comp, .void);

    if (func_qt.hasAttribute(p.comp, .noreturn)) {
        try p.errStr(.invalid_noreturn, e_tok, p.tokSlice(p.func.name));
    }

    if (ret_expr) |*some| {
        if (ret_void) {
            try p.errStr(.void_func_returns_value, e_tok, p.tokSlice(p.func.name));
        } else {
            try some.lvalConversion(p, e_tok);
            try some.coerce(p, ret_qt, e_tok, .ret);

            try some.saveValue(p);
        }
    } else if (!ret_void) {
        try p.errStr(.func_should_return, ret_tok, p.tokSlice(p.func.name));
    }

    return try p.addNode(.{ .return_stmt = .{
        .return_tok = ret_tok,
        .operand = if (ret_expr) |some| .{ .expr = some.node } else .none,
        .return_qt = ret_qt,
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
        if (p.getNode(call_node, .builtin_ref)) |builtin_ref| {
            const name = p.tokSlice(builtin_ref.name_tok);
            const expanded = p.comp.builtins.lookup(name);
            return .{ .builtin = .{ .builtin_tok = builtin_ref.name_tok, .tag = expanded.builtin.tag } };
        }
        return .{ .standard = func_node };
    }

    fn shouldPerformLvalConversion(self: CallExpr, arg_idx: u32) bool {
        return switch (self) {
            .standard => true,
            .builtin => |builtin| switch (builtin.tag) {
                .__builtin_va_start,
                .__va_start,
                .va_start,
                => arg_idx != 1,
                else => true,
            },
        };
    }

    fn shouldPromoteVarArg(self: CallExpr, arg_idx: u32) bool {
        return switch (self) {
            .standard => true,
            .builtin => |builtin| switch (builtin.tag) {
                .__builtin_va_start,
                .__va_start,
                .va_start,
                => arg_idx != 1,
                .__builtin_add_overflow,
                .__builtin_complex,
                .__builtin_isinf,
                .__builtin_isinf_sign,
                .__builtin_mul_overflow,
                .__builtin_isnan,
                .__builtin_sub_overflow,
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
            .__builtin_va_start,
            .__va_start,
            .va_start,
            => return p.checkVaStartArg(builtin_tok, first_after, param_tok, arg, arg_idx),
            .__builtin_complex => return p.checkComplexArg(builtin_tok, first_after, param_tok, arg, arg_idx),
            .__builtin_add_overflow,
            .__builtin_sub_overflow,
            .__builtin_mul_overflow,
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
                .__c11_atomic_thread_fence,
                .__c11_atomic_signal_fence,
                .__c11_atomic_is_lock_free,
                .__builtin_isinf,
                .__builtin_isinf_sign,
                .__builtin_isnan,
                => 1,

                .__builtin_complex,
                .__c11_atomic_load,
                .__c11_atomic_init,
                => 2,

                .__c11_atomic_store,
                .__c11_atomic_exchange,
                .__c11_atomic_fetch_add,
                .__c11_atomic_fetch_sub,
                .__c11_atomic_fetch_or,
                .__c11_atomic_fetch_xor,
                .__c11_atomic_fetch_and,
                .__atomic_fetch_add,
                .__atomic_fetch_sub,
                .__atomic_fetch_and,
                .__atomic_fetch_xor,
                .__atomic_fetch_or,
                .__atomic_fetch_nand,
                .__atomic_add_fetch,
                .__atomic_sub_fetch,
                .__atomic_and_fetch,
                .__atomic_xor_fetch,
                .__atomic_or_fetch,
                .__atomic_nand_fetch,
                .__builtin_add_overflow,
                .__builtin_sub_overflow,
                .__builtin_mul_overflow,
                => 3,

                .__c11_atomic_compare_exchange_strong,
                .__c11_atomic_compare_exchange_weak,
                => 5,

                .__atomic_compare_exchange,
                .__atomic_compare_exchange_n,
                => 6,
                else => null,
            },
        };
    }

    fn returnType(self: CallExpr, p: *Parser, func_qt: QualType) !QualType {
        if (self == .standard) {
            return if (func_qt.get(p.comp, .func)) |func_ty| func_ty.return_type else .invalid;
        }
        const builtin = self.builtin;
        const func_ty = func_qt.get(p.comp, .func).?;
        return switch (builtin.tag) {
            .__c11_atomic_exchange => {
                if (p.list_buf.items.len != 4) return .invalid; // wrong number of arguments; already an error
                const second_param = p.list_buf.items[2];
                return second_param.qt(&p.tree);
            },
            .__c11_atomic_load => {
                if (p.list_buf.items.len != 3) return .invalid; // wrong number of arguments; already an error
                const first_param = p.list_buf.items[1];
                const qt = first_param.qt(&p.tree);
                if (!qt.scalarKind(p.comp).isPointer()) return .invalid;
                return qt.childType(p.comp);
            },

            .__atomic_fetch_add,
            .__atomic_add_fetch,
            .__c11_atomic_fetch_add,

            .__atomic_fetch_sub,
            .__atomic_sub_fetch,
            .__c11_atomic_fetch_sub,

            .__atomic_fetch_and,
            .__atomic_and_fetch,
            .__c11_atomic_fetch_and,

            .__atomic_fetch_xor,
            .__atomic_xor_fetch,
            .__c11_atomic_fetch_xor,

            .__atomic_fetch_or,
            .__atomic_or_fetch,
            .__c11_atomic_fetch_or,

            .__atomic_fetch_nand,
            .__atomic_nand_fetch,
            .__c11_atomic_fetch_nand,
            => {
                if (p.list_buf.items.len != 3) return .invalid; // wrong number of arguments; already an error
                const second_param = p.list_buf.items[2];
                return second_param.qt(&p.tree);
            },
            .__builtin_complex => {
                if (p.list_buf.items.len < 1) return .invalid; // not enough arguments; already an error
                const last_param = p.list_buf.items[p.list_buf.items.len - 1];
                return try last_param.qt(&p.tree).toComplex(p.comp);
            },
            .__atomic_compare_exchange,
            .__atomic_compare_exchange_n,
            .__c11_atomic_is_lock_free,
            => .bool,
            else => func_ty.return_type,

            .__c11_atomic_compare_exchange_strong,
            .__c11_atomic_compare_exchange_weak,
            => {
                if (p.list_buf.items.len != 6) return .invalid; // wrong number of arguments
                const third_param = p.list_buf.items[3];
                return third_param.qt(&p.tree);
            },
        };
    }

    fn finish(self: CallExpr, p: *Parser, func_qt: QualType, list_buf_top: usize, l_paren: TokenIndex) Error!Result {
        const args = p.list_buf.items[list_buf_top..];
        const return_qt = try self.returnType(p, func_qt);
        switch (self) {
            .standard => |func_node| return .{
                .qt = return_qt,
                .node = try p.addNode(.{ .call_expr = .{
                    .l_paren_tok = l_paren,
                    .qt = return_qt.unqualified(),
                    .callee = func_node,
                    .args = args,
                } }),
            },
            .builtin => |builtin| return .{
                .val = try evalBuiltin(builtin.tag, p, args),
                .qt = return_qt,
                .node = try p.addNode(.{ .builtin_call_expr = .{
                    .builtin_tok = builtin.builtin_tok,
                    .qt = return_qt,
                    .args = args,
                } }),
            },
        }
    }
};

pub const Result = struct {
    node: Node.Index,
    qt: QualType = .int,
    val: Value = .{},

    pub fn str(res: Result, p: *Parser) ![]const u8 {
        switch (res.val.opt_ref) {
            .none => return "(none)",
            .null => return "nullptr_t",
            else => {},
        }
        const strings_top = p.strings.items.len;
        defer p.strings.items.len = strings_top;

        if (try res.val.print(res.qt, p.comp, p.strings.writer())) |nested| switch (nested) {
            .pointer => |ptr| {
                const ptr_node: Node.Index = @enumFromInt(ptr.node);
                const decl_name = p.tree.tokSlice(ptr_node.tok(&p.tree));
                try ptr.offset.printPointer(decl_name, p.comp, p.strings.writer());
            },
        };

        return try p.comp.diagnostics.arena.allocator().dupe(u8, p.strings.items[strings_top..]);
    }

    fn maybeWarnUnused(res: Result, p: *Parser, expr_start: TokenIndex, err_start: usize) Error!void {
        if (res.qt.is(p.comp, .void)) return;
        if (res.qt.isInvalid()) return;
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
            lhs.val = .zero;
        }
        if (!lhs.qt.isInvalid()) {
            lhs.qt = .int;
        }
        return lhs.bin(p, tag, rhs, tok_i);
    }

    fn bin(lhs: *Result, p: *Parser, rt_tag: std.meta.Tag(Node), rhs: Result, tok_i: TokenIndex) !void {
        const bin_data: Node.Binary = .{
            .op_tok = tok_i,
            .lhs = lhs.node,
            .rhs = rhs.node,
            .qt = lhs.qt,
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
        const un_data: Node.Unary = .{
            .op_tok = tok_i,
            .operand = operand.node,
            .qt = operand.qt,
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
            .cast = .{
                .l_paren = tok,
                .kind = kind,
                .operand = operand.node,
                .qt = operand.qt,
                .implicit = true,
            },
        });
    }

    fn adjustCondExprPtrs(a: *Result, tok: TokenIndex, b: *Result, p: *Parser) !bool {
        assert(a.qt.isPointer(p.comp) and b.qt.isPointer(p.comp));

        const a_elem = a.qt.childType(p.comp);
        const b_elem = b.qt.childType(p.comp);
        if (a_elem.eqlQualified(b_elem, p.comp)) return true;

        const has_void_pointer_branch = a.qt.scalarKind(p.comp) == .void_pointer or
            b.qt.scalarKind(p.comp) == .void_pointer;

        const only_quals_differ = a_elem.eql(b_elem, p.comp);
        const pointers_compatible = only_quals_differ or has_void_pointer_branch;

        var adjusted_elem_qt = a_elem;
        if (!pointers_compatible or has_void_pointer_branch) {
            if (!pointers_compatible) {
                try p.errStr(.pointer_mismatch, tok, try p.typePairStrExtra(a.qt, " and ", b.qt));
            }
            adjusted_elem_qt = .void;
        }

        if (pointers_compatible) {
            adjusted_elem_qt.@"const" = a_elem.@"const" or b_elem.@"const";
            adjusted_elem_qt.@"volatile" = a_elem.@"volatile" or b_elem.@"volatile";
            // TODO restrict?
        }

        if (!adjusted_elem_qt.eqlQualified(a_elem, p.comp)) {
            a.qt = try p.comp.type_store.put(p.gpa, .{ .pointer = .{
                .child = adjusted_elem_qt,
                .decayed = null,
            } });
            try a.implicitCast(p, .bitcast, tok);
        }
        if (!adjusted_elem_qt.eqlQualified(b_elem, p.comp)) {
            b.qt = try p.comp.type_store.put(p.gpa, .{ .pointer = .{
                .child = adjusted_elem_qt,
                .decayed = null,
            } });
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
        if (b.qt.isInvalid()) {
            try a.saveValue(p);
            a.qt = .invalid;
        }
        if (a.qt.isInvalid()) {
            return false;
        }
        try a.lvalConversion(p, tok);
        try b.lvalConversion(p, tok);

        const a_vec = a.qt.is(p.comp, .vector);
        const b_vec = b.qt.is(p.comp, .vector);
        if (a_vec and b_vec) {
            if (a.qt.eql(b.qt, p.comp)) {
                return a.shouldEval(b, p);
            }
            return a.invalidBinTy(tok, b, p);
        } else if (a_vec) {
            if (b.coerceExtra(p, a.qt.childType(p.comp), tok, .test_coerce)) {
                try b.saveValue(p);
                try b.implicitCast(p, .vector_splat, tok);
                return a.shouldEval(b, p);
            } else |er| switch (er) {
                error.CoercionFailed => return a.invalidBinTy(tok, b, p),
                else => |e| return e,
            }
        } else if (b_vec) {
            if (a.coerceExtra(p, b.qt.childType(p.comp), tok, .test_coerce)) {
                try a.saveValue(p);
                try a.implicitCast(p, .vector_splat, tok);
                return a.shouldEval(b, p);
            } else |er| switch (er) {
                error.CoercionFailed => return a.invalidBinTy(tok, b, p),
                else => |e| return e,
            }
        }

        const a_sk = a.qt.scalarKind(p.comp);
        const b_sk = b.qt.scalarKind(p.comp);

        if (a_sk.isInt() and b_sk.isInt()) {
            try a.usualArithmeticConversion(b, p, tok);
            return a.shouldEval(b, p);
        }
        if (kind == .integer) return a.invalidBinTy(tok, b, p);

        if (a_sk.isArithmetic() and b_sk.isArithmetic()) {
            // <, <=, >, >= only work on real types
            if (kind == .relational and (!a_sk.isReal() or !b_sk.isReal()))
                return a.invalidBinTy(tok, b, p);

            try a.usualArithmeticConversion(b, p, tok);
            return a.shouldEval(b, p);
        }
        if (kind == .arithmetic) return a.invalidBinTy(tok, b, p);

        switch (kind) {
            .boolean_logic => {
                if (!(a_sk != .none or a_sk == .nullptr_t) or
                    !(b_sk != .none or b_sk == .nullptr_t))
                {
                    return a.invalidBinTy(tok, b, p);
                }

                // Do integer promotions but nothing else
                if (a_sk.isInt()) try a.castToInt(p, a.qt.promoteInt(p.comp), tok);
                if (b_sk.isInt()) try b.castToInt(p, b.qt.promoteInt(p.comp), tok);
                return a.shouldEval(b, p);
            },
            .relational, .equality => {
                if (kind == .equality and (a_sk == .nullptr_t or b_sk == .nullptr_t)) {
                    if (a_sk == .nullptr_t and b_sk == .nullptr_t) return a.shouldEval(b, p);

                    const nullptr_res = if (a_sk == .nullptr_t) a else b;
                    const other_res = if (a_sk == .nullptr_t) b else a;

                    if (other_res.qt.isPointer(p.comp)) {
                        try nullptr_res.nullToPointer(p, other_res.qt, tok);
                        return other_res.shouldEval(nullptr_res, p);
                    } else if (other_res.val.isZero(p.comp)) {
                        other_res.val = .null;
                        try other_res.nullToPointer(p, nullptr_res.qt, tok);
                        return other_res.shouldEval(nullptr_res, p);
                    }
                    return a.invalidBinTy(tok, b, p);
                }

                // comparisons between floats and pointes not allowed
                if (a_sk == .none or b_sk == .none or (a_sk.isFloat() and b_sk.isPointer()) or (b_sk.isFloat() and a_sk.isPointer()))
                    return a.invalidBinTy(tok, b, p);

                if ((a_sk.isInt() or b_sk.isInt()) and !(a.val.isZero(p.comp) or b.val.isZero(p.comp))) {
                    try p.errStr(.comparison_ptr_int, tok, try p.typePairStr(a.qt, b.qt));
                } else if (a_sk.isPointer() and b_sk.isPointer()) {
                    if (a_sk != .void_pointer and b_sk != .void_pointer and !a.qt.eql(b.qt, p.comp))
                        try p.errStr(.comparison_distinct_ptr, tok, try p.typePairStr(a.qt, b.qt));
                } else if (a_sk.isPointer()) {
                    try b.castToPointer(p, a.qt, tok);
                } else {
                    assert(b_sk.isPointer());
                    try a.castToPointer(p, b.qt, tok);
                }

                return a.shouldEval(b, p);
            },
            .conditional => {
                // doesn't matter what we return here, as the result is ignored
                if (a.qt.is(p.comp, .void) or b.qt.is(p.comp, .void)) {
                    try a.castToVoid(p, tok);
                    try b.castToVoid(p, tok);
                    return true;
                }

                if (a_sk == .nullptr_t and b_sk == .nullptr_t) return true;

                if ((a_sk.isPointer() and b_sk.isInt()) or (a_sk.isInt() and b_sk.isPointer())) {
                    if (a.val.isZero(p.comp) or b.val.isZero(p.comp)) {
                        try a.nullToPointer(p, b.qt, tok);
                        try b.nullToPointer(p, a.qt, tok);
                        return true;
                    }
                    const int_ty = if (a_sk.isInt()) a else b;
                    const ptr_ty = if (a_sk.isPointer()) a else b;
                    try p.errStr(.implicit_int_to_ptr, tok, try p.typePairStrExtra(int_ty.qt, " to ", ptr_ty.qt));
                    try int_ty.castToPointer(p, ptr_ty.qt, tok);

                    return true;
                }
                if ((a_sk.isPointer() and b_sk == .nullptr_t) or (a_sk == .nullptr_t and b_sk.isPointer())) {
                    const nullptr_res = if (a_sk == .nullptr_t) a else b;
                    const ptr_res = if (a_sk == .nullptr_t) b else a;
                    try nullptr_res.nullToPointer(p, ptr_res.qt, tok);
                    return true;
                }
                if (a_sk.isPointer() and b_sk.isPointer()) return a.adjustCondExprPtrs(tok, b, p);

                if (a.qt.getRecord(p.comp) != null and b.qt.getRecord(p.comp) != null and a.qt.eql(b.qt, p.comp)) {
                    return true;
                }
                return a.invalidBinTy(tok, b, p);
            },
            .add => {
                // if both aren't arithmetic one should be pointer and the other an integer
                if (a_sk.isPointer() == b_sk.isPointer() or a_sk.isInt() == b_sk.isInt()) return a.invalidBinTy(tok, b, p);

                if (a_sk == .void_pointer or b_sk == .void_pointer)
                    try p.errTok(.gnu_pointer_arith, tok);

                if (a_sk == .nullptr_t) try a.nullToPointer(p, .void_pointer, tok);
                if (b_sk == .nullptr_t) try b.nullToPointer(p, .void_pointer, tok);

                // Do integer promotions but nothing else
                if (a_sk.isInt()) try a.castToInt(p, a.qt.promoteInt(p.comp), tok);
                if (b_sk.isInt()) try b.castToInt(p, b.qt.promoteInt(p.comp), tok);

                // The result type is the type of the pointer operand
                if (a_sk.isInt()) a.qt = b.qt else b.qt = a.qt;
                return a.shouldEval(b, p);
            },
            .sub => {
                // if both aren't arithmetic then either both should be pointers or just the lelft one.
                if (!a_sk.isPointer() or !(b_sk.isPointer() or b_sk.isInt())) return a.invalidBinTy(tok, b, p);

                if (a_sk == .void_pointer)
                    try p.errTok(.gnu_pointer_arith, tok);

                if (a_sk == .nullptr_t) try a.nullToPointer(p, .void_pointer, tok);
                if (b_sk == .nullptr_t) try b.nullToPointer(p, .void_pointer, tok);

                if (a_sk.isPointer() and b_sk.isPointer()) {
                    if (!a.qt.eql(b.qt, p.comp)) try p.errStr(.incompatible_pointers, tok, try p.typePairStr(a.qt, b.qt));
                    if (a.qt.childType(p.comp).sizeofOrNull(p.comp) orelse 1 == 0) try p.errStr(.subtract_pointers_zero_elem_size, tok, try p.typeStr(a.qt.childType(p.comp)));
                    a.qt = p.comp.type_store.ptrdiff;
                }

                // Do integer promotion on b if needed
                if (b_sk.isInt()) try b.castToInt(p, b.qt.promoteInt(p.comp), tok);
                return a.shouldEval(b, p);
            },
            else => return a.invalidBinTy(tok, b, p),
        }
    }

    fn lvalConversion(res: *Result, p: *Parser, tok: TokenIndex) Error!void {
        if (res.qt.is(p.comp, .func)) {
            res.val = try p.pointerValue(res.node, .zero);

            res.qt = try res.qt.decay(p.comp);
            try res.implicitCast(p, .function_to_pointer, tok);
        } else if (res.qt.is(p.comp, .array)) {
            res.val = try p.pointerValue(res.node, .zero);

            res.qt = try res.qt.decay(p.comp);
            try res.implicitCast(p, .array_to_pointer, tok);
        } else if (!p.in_macro and p.tree.isLval(res.node)) {
            res.qt = res.qt.unqualified();
            try res.implicitCast(p, .lval_to_rval, tok);
        }
    }

    fn castToBool(res: *Result, p: *Parser, bool_qt: QualType, tok: TokenIndex) Error!void {
        if (res.qt.isInvalid()) return;
        std.debug.assert(!bool_qt.isInvalid());

        const src_sk = res.qt.scalarKind(p.comp);
        if (src_sk.isPointer()) {
            res.val.boolCast(p.comp);
            res.qt = bool_qt;
            try res.implicitCast(p, .pointer_to_bool, tok);
        } else if (src_sk.isInt() and src_sk != .bool) {
            res.val.boolCast(p.comp);
            if (!src_sk.isReal()) {
                res.qt = res.qt.toReal(p.comp);
                try res.implicitCast(p, .complex_int_to_real, tok);
            }
            res.qt = bool_qt;
            try res.implicitCast(p, .int_to_bool, tok);
        } else if (src_sk.isFloat()) {
            const old_value = res.val;
            const value_change_kind = try res.val.floatToInt(bool_qt, p.comp);
            try res.floatToIntWarning(p, bool_qt, old_value, value_change_kind, tok);
            if (!src_sk.isReal()) {
                res.qt = res.qt.toReal(p.comp);
                try res.implicitCast(p, .complex_float_to_real, tok);
            }
            res.qt = bool_qt;
            try res.implicitCast(p, .float_to_bool, tok);
        }
    }

    fn castToInt(res: *Result, p: *Parser, int_qt: QualType, tok: TokenIndex) Error!void {
        if (res.qt.isInvalid()) return;
        std.debug.assert(!int_qt.isInvalid());
        if (int_qt.sizeofOrNull(p.comp) == null) {
            return error.ParsingFailed; // Cast to incomplete enum, diagnostic already issued
        }

        const src_sk = res.qt.scalarKind(p.comp);
        const dest_sk = int_qt.scalarKind(p.comp);

        if (src_sk == .bool) {
            res.qt = int_qt.toReal(p.comp);
            try res.implicitCast(p, .bool_to_int, tok);
            if (!dest_sk.isReal()) {
                res.qt = int_qt;
                try res.implicitCast(p, .real_to_complex_int, tok);
            }
        } else if (src_sk.isPointer()) {
            res.val = .{};
            res.qt = int_qt.toReal(p.comp);
            try res.implicitCast(p, .pointer_to_int, tok);
            if (!dest_sk.isReal()) {
                res.qt = int_qt;
                try res.implicitCast(p, .real_to_complex_int, tok);
            }
        } else if (res.qt.isFloat(p.comp)) {
            const old_value = res.val;
            const value_change_kind = try res.val.floatToInt(int_qt, p.comp);
            try res.floatToIntWarning(p, int_qt, old_value, value_change_kind, tok);
            if (src_sk.isReal() and dest_sk.isReal()) {
                res.qt = int_qt;
                try res.implicitCast(p, .float_to_int, tok);
            } else if (src_sk.isReal()) {
                res.qt = int_qt.toReal(p.comp);
                try res.implicitCast(p, .float_to_int, tok);
                res.qt = int_qt;
                try res.implicitCast(p, .real_to_complex_int, tok);
            } else if (dest_sk.isReal()) {
                res.qt = res.qt.toReal(p.comp);
                try res.implicitCast(p, .complex_float_to_real, tok);
                res.qt = int_qt;
                try res.implicitCast(p, .float_to_int, tok);
            } else {
                res.qt = int_qt;
                try res.implicitCast(p, .complex_float_to_complex_int, tok);
            }
        } else if (!res.qt.eql(int_qt, p.comp)) {
            const old_val = res.val;
            const value_change_kind = try res.val.intCast(int_qt, p.comp);
            switch (value_change_kind) {
                .none => {},
                .truncated => try p.errStr(.int_value_changed, tok, try p.valueChangedStr(res, old_val, int_qt)),
                .sign_changed => try p.errStr(.sign_conversion, tok, try p.typePairStrExtra(res.qt, " to ", int_qt)),
            }

            if (src_sk.isReal() and dest_sk.isReal()) {
                res.qt = int_qt;
                try res.implicitCast(p, .int_cast, tok);
            } else if (src_sk.isReal()) {
                const real_int_qt = int_qt.toReal(p.comp);
                if (!res.qt.eql(real_int_qt, p.comp)) {
                    res.qt = real_int_qt;
                    try res.implicitCast(p, .int_cast, tok);
                }
                res.qt = int_qt;
                try res.implicitCast(p, .real_to_complex_int, tok);
            } else if (dest_sk.isReal()) {
                res.qt = res.qt.toReal(p.comp);
                try res.implicitCast(p, .complex_int_to_real, tok);
                res.qt = int_qt;
                try res.implicitCast(p, .int_cast, tok);
            } else {
                res.qt = int_qt;
                try res.implicitCast(p, .complex_int_cast, tok);
            }
        }
    }

    fn floatToIntWarning(
        res: *Result,
        p: *Parser,
        int_qt: QualType,
        old_value: Value,
        change_kind: Value.FloatToIntChangeKind,
        tok: TokenIndex,
    ) !void {
        switch (change_kind) {
            .none => return p.errStr(.float_to_int, tok, try p.typePairStrExtra(res.qt, " to ", int_qt)),
            .out_of_range => return p.errStr(.float_out_of_range, tok, try p.typePairStrExtra(res.qt, " to ", int_qt)),
            .overflow => return p.errStr(.float_overflow_conversion, tok, try p.typePairStrExtra(res.qt, " to ", int_qt)),
            .nonzero_to_zero => return p.errStr(.float_zero_conversion, tok, try p.valueChangedStr(res, old_value, int_qt)),
            .value_changed => return p.errStr(.float_value_changed, tok, try p.valueChangedStr(res, old_value, int_qt)),
        }
    }

    fn castToFloat(res: *Result, p: *Parser, float_qt: QualType, tok: TokenIndex) Error!void {
        const src_sk = res.qt.scalarKind(p.comp);
        const dest_sk = float_qt.scalarKind(p.comp);

        if (src_sk == .bool) {
            try res.val.intToFloat(float_qt, p.comp);
            res.qt = float_qt.toReal(p.comp);
            try res.implicitCast(p, .bool_to_float, tok);
            if (!dest_sk.isReal()) {
                res.qt = float_qt;
                try res.implicitCast(p, .real_to_complex_float, tok);
            }
        } else if (src_sk.isInt()) {
            try res.val.intToFloat(float_qt, p.comp);
            if (src_sk.isReal() and dest_sk.isReal()) {
                res.qt = float_qt;
                try res.implicitCast(p, .int_to_float, tok);
            } else if (src_sk.isReal()) {
                res.qt = float_qt.toReal(p.comp);
                try res.implicitCast(p, .int_to_float, tok);
                res.qt = float_qt;
                try res.implicitCast(p, .real_to_complex_float, tok);
            } else if (dest_sk.isReal()) {
                res.qt = res.qt.toReal(p.comp);
                try res.implicitCast(p, .complex_int_to_real, tok);
                res.qt = float_qt;
                try res.implicitCast(p, .int_to_float, tok);
            } else {
                res.qt = float_qt;
                try res.implicitCast(p, .complex_int_to_complex_float, tok);
            }
        } else if (!res.qt.eql(float_qt, p.comp)) {
            try res.val.floatCast(float_qt, p.comp);
            if (src_sk.isReal() and dest_sk.isReal()) {
                res.qt = float_qt;
                try res.implicitCast(p, .float_cast, tok);
            } else if (src_sk.isReal()) {
                if (res.qt.floatRank(p.comp) != float_qt.floatRank(p.comp)) {
                    res.qt = float_qt.toReal(p.comp);
                    try res.implicitCast(p, .float_cast, tok);
                }
                res.qt = float_qt;
                try res.implicitCast(p, .real_to_complex_float, tok);
            } else if (dest_sk.isReal()) {
                res.qt = res.qt.toReal(p.comp);
                try res.implicitCast(p, .complex_float_to_real, tok);
                if (res.qt.floatRank(p.comp) != float_qt.floatRank(p.comp)) {
                    res.qt = float_qt;
                    try res.implicitCast(p, .float_cast, tok);
                }
            } else {
                res.qt = float_qt;
                try res.implicitCast(p, .complex_float_cast, tok);
            }
        }
    }

    /// Converts a bool or integer to a pointer
    fn castToPointer(res: *Result, p: *Parser, ptr_qt: QualType, tok: TokenIndex) Error!void {
        const src_sk = res.qt.scalarKind(p.comp);
        if (src_sk == .bool) {
            res.qt = ptr_qt;
            try res.implicitCast(p, .bool_to_pointer, tok);
        } else if (src_sk.isInt()) {
            _ = try res.val.intCast(ptr_qt, p.comp);
            res.qt = ptr_qt;
            try res.implicitCast(p, .int_to_pointer, tok);
        }
    }

    fn castToVoid(res: *Result, p: *Parser, tok: TokenIndex) Error!void {
        if (!res.qt.is(p.comp, .void)) {
            res.qt = .void;
            try res.implicitCast(p, .to_void, tok);
        }
    }

    fn nullToPointer(res: *Result, p: *Parser, ptr_ty: QualType, tok: TokenIndex) Error!void {
        if (!res.qt.is(p.comp, .nullptr_t) and !res.val.isZero(p.comp)) return;
        res.val = .{};
        res.qt = ptr_ty;
        try res.implicitCast(p, .null_to_pointer, tok);
    }

    fn usualUnaryConversion(res: *Result, p: *Parser, tok: TokenIndex) Error!void {
        if (res.qt.isFloat(p.comp)) fp_eval: {
            const eval_method = p.comp.langopts.fp_eval_method orelse break :fp_eval;
            switch (eval_method) {
                .source => {},
                .indeterminate => unreachable,
                .double => {
                    if (res.qt.floatRank(p.comp) < QualType.double.floatRank(p.comp)) {
                        var res_qt: QualType = .double;
                        if (res.qt.is(p.comp, .complex)) res_qt = try res_qt.toComplex(p.comp);
                        return res.castToFloat(p, res_qt, tok);
                    }
                },
                .extended => {
                    if (res.qt.floatRank(p.comp) < QualType.long_double.floatRank(p.comp)) {
                        var res_qt: QualType = .long_double;
                        if (res.qt.is(p.comp, .complex)) res_qt = try res_qt.toComplex(p.comp);
                        return res.castToFloat(p, res_qt, tok);
                    }
                },
            }
        }

        if (!p.comp.langopts.use_native_half_type) {
            if (res.qt.get(p.comp, .float)) |float_ty| {
                if (float_ty == .fp16) {
                    return res.castToFloat(p, .float, tok);
                }
            }
        }

        if (res.qt.isInt(p.comp) and !p.in_macro) {
            if (p.tree.bitfieldWidth(res.node, true)) |width| {
                if (res.qt.promoteBitfield(p.comp, width)) |promotion_ty| {
                    return res.castToInt(p, promotion_ty, tok);
                }
            }
            return res.castToInt(p, res.qt.promoteInt(p.comp), tok);
        }
    }

    fn usualArithmeticConversion(a: *Result, b: *Result, p: *Parser, tok: TokenIndex) Error!void {
        try a.usualUnaryConversion(p, tok);
        try b.usualUnaryConversion(p, tok);

        // if either is a float cast to that type
        const a_float = a.qt.isFloat(p.comp);
        const b_float = b.qt.isFloat(p.comp);
        if (a_float and b_float) {
            const a_complex = a.qt.is(p.comp, .complex);
            const b_complex = b.qt.is(p.comp, .complex);

            const res_qt = if (a.qt.floatRank(p.comp) > b.qt.floatRank(p.comp))
                (if (!a_complex and b_complex)
                    try a.qt.toComplex(p.comp)
                else
                    a.qt)
            else
                (if (!b_complex and a_complex)
                    try b.qt.toComplex(p.comp)
                else
                    b.qt);

            try a.castToFloat(p, res_qt, tok);
            try b.castToFloat(p, res_qt, tok);
            return;
        } else if (a_float) {
            try b.castToFloat(p, a.qt, tok);
            return;
        } else if (b_float) {
            try a.castToFloat(p, b.qt, tok);
            return;
        }

        if (a.qt.eql(b.qt, p.comp)) {
            // cast to promoted type
            try a.castToInt(p, a.qt, tok);
            try b.castToInt(p, b.qt, tok);
            return;
        }

        const a_real = a.qt.toReal(p.comp);
        const b_real = b.qt.toReal(p.comp);

        const type_order = a.qt.intRankOrder(b.qt, p.comp);
        const a_signed = a.qt.signedness(p.comp) == .unsigned;
        const b_signed = b.qt.signedness(p.comp) == .unsigned;

        var target_qt: QualType = .invalid;
        if (a_signed == b_signed) {
            // If both have the same sign, use higher-rank type.
            target_qt = switch (type_order) {
                .lt => b.qt,
                .eq, .gt => a_real,
            };
        } else if (type_order != if (a_signed) std.math.Order.gt else std.math.Order.lt) {
            // Only one is signed; and the unsigned type has rank >= the signed type
            // Use the unsigned type
            target_qt = if (b_signed) a_real else b_real;
        } else if (a_real.bitSizeof(p.comp) != b_real.bitSizeof(p.comp)) {
            // Signed type is higher rank and sizes are not equal
            // Use the signed type
            target_qt = if (a_signed) a_real else b_real;
        } else {
            // Signed type is higher rank but same size as unsigned type
            // e.g. `long` and `unsigned` on x86-linux-gnu
            // Use unsigned version of the signed type
            target_qt = if (a_signed) try a_real.makeIntUnsigned(p.comp) else try b_real.makeIntUnsigned(p.comp);
        }

        if (a.qt.is(p.comp, .complex) or b.qt.is(p.comp, .complex)) {
            target_qt = try target_qt.toComplex(p.comp);
        }

        if (target_qt.is(p.comp, .complex)) {
            // TODO implement complex int values
            try a.saveValue(p);
            try b.saveValue(p);
        }
        try a.castToInt(p, target_qt, tok);
        try b.castToInt(p, target_qt, tok);
    }

    fn invalidBinTy(a: *Result, tok: TokenIndex, b: *Result, p: *Parser) Error!bool {
        try p.errStr(.invalid_bin_types, tok, try p.typePairStr(a.qt, b.qt));
        a.val = .{};
        b.val = .{};
        a.qt = .invalid;
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

    fn castType(res: *Result, p: *Parser, dest_qt: QualType, operand_tok: TokenIndex, l_paren: TokenIndex) !void {
        if (res.qt.isInvalid()) {
            res.val = .{};
            return;
        } else if (dest_qt.isInvalid()) {
            res.val = .{};
            res.qt = .invalid;
            return;
        }
        var cast_kind: Node.Cast.Kind = undefined;

        const dest_sk = dest_qt.scalarKind(p.comp);
        const src_sk = res.qt.scalarKind(p.comp);

        if (dest_qt.is(p.comp, .void)) {
            // everything can cast to void
            cast_kind = .to_void;
            res.val = .{};
        } else if (dest_sk == .nullptr_t) {
            res.val = .{};
            if (src_sk == .nullptr_t) {
                cast_kind = .no_op;
            } else {
                try p.errStr(.invalid_object_cast, l_paren, try p.typePairStrExtra(res.qt, " to ", dest_qt));
                return error.ParsingFailed;
            }
        } else if (src_sk == .nullptr_t) {
            if (dest_sk == .bool) {
                try res.nullToPointer(p, res.qt, l_paren);
                res.val.boolCast(p.comp);
                res.qt = .bool;
                try res.implicitCast(p, .pointer_to_bool, l_paren);
                try res.saveValue(p);
            } else if (dest_sk.isPointer()) {
                try res.nullToPointer(p, dest_qt, l_paren);
            } else {
                try p.errStr(.invalid_object_cast, l_paren, try p.typePairStrExtra(res.qt, " to ", dest_qt));
                return error.ParsingFailed;
            }
            cast_kind = .no_op;
        } else if (res.val.isZero(p.comp) and dest_sk.isPointer()) {
            cast_kind = .null_to_pointer;
        } else if (dest_sk != .none) cast: {
            if (dest_sk.isFloat() and src_sk.isPointer()) {
                try p.errStr(.invalid_cast_to_float, l_paren, try p.typeStr(dest_qt));
                return error.ParsingFailed;
            } else if (src_sk.isFloat() and dest_sk.isPointer()) {
                try p.errStr(.invalid_cast_to_pointer, l_paren, try p.typeStr(res.qt));
                return error.ParsingFailed;
            }

            if (dest_qt.eql(res.qt, p.comp)) {
                cast_kind = .no_op;
            } else if (dest_sk == .bool) {
                if (src_sk.isPointer()) {
                    cast_kind = .pointer_to_bool;
                } else if (src_sk.isInt()) {
                    if (!src_sk.isReal()) {
                        res.qt = res.qt.toReal(p.comp);
                        try res.implicitCast(p, .complex_int_to_real, l_paren);
                    }
                    cast_kind = .int_to_bool;
                } else if (src_sk.isFloat()) {
                    if (!src_sk.isReal()) {
                        res.qt = res.qt.toReal(p.comp);
                        try res.implicitCast(p, .complex_float_to_real, l_paren);
                    }
                    cast_kind = .float_to_bool;
                }
            } else if (dest_sk.isInt()) {
                if (src_sk == .bool) {
                    if (!dest_sk.isReal()) {
                        res.qt = dest_qt.toReal(p.comp);
                        try res.implicitCast(p, .bool_to_int, l_paren);
                        cast_kind = .real_to_complex_int;
                    } else {
                        cast_kind = .bool_to_int;
                    }
                } else if (src_sk.isInt()) {
                    if (src_sk.isReal() and dest_sk.isReal()) {
                        cast_kind = .int_cast;
                    } else if (src_sk.isReal()) {
                        res.qt = dest_qt.toReal(p.comp);
                        try res.implicitCast(p, .int_cast, l_paren);
                        cast_kind = .real_to_complex_int;
                    } else if (dest_sk.isReal()) {
                        res.qt = res.qt.toReal(p.comp);
                        try res.implicitCast(p, .complex_int_to_real, l_paren);
                        cast_kind = .int_cast;
                    } else {
                        cast_kind = .complex_int_cast;
                    }
                } else if (src_sk.isPointer()) {
                    res.val = .{};
                    if (!dest_sk.isReal()) {
                        res.qt = dest_qt.toReal(p.comp);
                        try res.implicitCast(p, .pointer_to_int, l_paren);
                        cast_kind = .real_to_complex_int;
                    } else {
                        cast_kind = .pointer_to_int;
                    }
                } else if (src_sk.isReal() and dest_sk.isReal()) {
                    cast_kind = .float_to_int;
                } else if (src_sk.isReal()) {
                    res.qt = dest_qt.toReal(p.comp);
                    try res.implicitCast(p, .float_to_int, l_paren);
                    cast_kind = .real_to_complex_int;
                } else if (dest_sk.isReal()) {
                    res.qt = res.qt.toReal(p.comp);
                    try res.implicitCast(p, .complex_float_to_real, l_paren);
                    cast_kind = .float_to_int;
                } else {
                    cast_kind = .complex_float_to_complex_int;
                }
            } else if (dest_sk.isPointer()) {
                if (src_sk.isPointer()) {
                    cast_kind = .bitcast;
                } else if (src_sk.isInt()) {
                    if (!src_sk.isReal()) {
                        res.qt = res.qt.toReal(p.comp);
                        try res.implicitCast(p, .complex_int_to_real, l_paren);
                    }
                    cast_kind = .int_to_pointer;
                } else if (src_sk == .bool) {
                    cast_kind = .bool_to_pointer;
                } else if (res.qt.is(p.comp, .array)) {
                    cast_kind = .array_to_pointer;
                } else if (res.qt.is(p.comp, .func)) {
                    cast_kind = .function_to_pointer;
                } else {
                    try p.errStr(.cond_expr_type, operand_tok, try p.typeStr(res.qt));
                    return error.ParsingFailed;
                }
            } else if (dest_sk.isFloat()) {
                if (src_sk == .bool) {
                    if (!dest_sk.isReal()) {
                        res.qt = dest_qt.toReal(p.comp);
                        try res.implicitCast(p, .bool_to_float, l_paren);
                        cast_kind = .real_to_complex_float;
                    } else {
                        cast_kind = .bool_to_float;
                    }
                } else if (src_sk.isInt()) {
                    if (src_sk.isReal() and dest_sk.isReal()) {
                        cast_kind = .int_to_float;
                    } else if (src_sk.isReal()) {
                        res.qt = dest_qt.toReal(p.comp);
                        try res.implicitCast(p, .int_to_float, l_paren);
                        cast_kind = .real_to_complex_float;
                    } else if (dest_sk.isReal()) {
                        res.qt = res.qt.toReal(p.comp);
                        try res.implicitCast(p, .complex_int_to_real, l_paren);
                        cast_kind = .int_to_float;
                    } else {
                        cast_kind = .complex_int_to_complex_float;
                    }
                } else if (src_sk.isReal() and dest_sk.isReal()) {
                    cast_kind = .float_cast;
                } else if (src_sk.isReal()) {
                    res.qt = dest_qt.toReal(p.comp);
                    try res.implicitCast(p, .float_cast, l_paren);
                    cast_kind = .real_to_complex_float;
                } else if (dest_sk.isReal()) {
                    res.qt = res.qt.toReal(p.comp);
                    try res.implicitCast(p, .complex_float_to_real, l_paren);
                    cast_kind = .float_cast;
                } else {
                    cast_kind = .complex_float_cast;
                }
            }
            if (res.val.opt_ref == .none) break :cast;

            const src_int = src_sk.isInt() or src_sk.isPointer();
            const dest_int = dest_sk.isInt() or dest_sk.isPointer();
            if (dest_sk == .bool) {
                res.val.boolCast(p.comp);
            } else if (src_sk.isFloat() and dest_int) {
                if (dest_qt.sizeofOrNull(p.comp) == null) {
                    try p.errStr(.cast_to_incomplete_type, l_paren, try p.typeStr(dest_qt));
                    return error.ParsingFailed;
                }
                // Explicit cast, no conversion warning
                _ = try res.val.floatToInt(dest_qt, p.comp);
            } else if (dest_sk.isFloat() and src_int) {
                try res.val.intToFloat(dest_qt, p.comp);
            } else if (dest_sk.isFloat() and src_sk.isFloat()) {
                try res.val.floatCast(dest_qt, p.comp);
            } else if (src_int and dest_int) {
                if (dest_qt.sizeofOrNull(p.comp) == null) {
                    try p.errStr(.cast_to_incomplete_type, l_paren, try p.typeStr(dest_qt));
                    return error.ParsingFailed;
                }
                _ = try res.val.intCast(dest_qt, p.comp);
            }
        } else if (dest_qt.get(p.comp, .@"union")) |union_ty| {
            if (union_ty.layout == null) {
                try p.errStr(.cast_to_incomplete_type, l_paren, try p.typeStr(dest_qt));
                return error.ParsingFailed;
            }

            for (union_ty.fields) |field| {
                if (field.qt.eql(res.qt, p.comp)) {
                    cast_kind = .union_cast;
                    try p.errTok(.gnu_union_cast, l_paren);
                    break;
                }
            } else {
                try p.errStr(.invalid_union_cast, l_paren, try p.typeStr(res.qt));
                return error.ParsingFailed;
            }
        } else {
            try p.errStr(.invalid_cast_type, l_paren, try p.typeStr(dest_qt));
            return error.ParsingFailed;
        }

        if (dest_qt.isQualified()) try p.errStr(.qual_cast, l_paren, try p.typeStr(dest_qt));
        if (dest_sk.isInt() and src_sk.isPointer() and dest_qt.sizeCompare(res.qt, p.comp) == .lt) {
            try p.errStr(.cast_to_smaller_int, l_paren, try p.typePairStrExtra(dest_qt, " from ", res.qt));
        }

        res.qt = dest_qt.unqualified();
        res.node = try p.addNode(.{
            .cast = .{
                .l_paren = l_paren,
                .qt = res.qt,
                .operand = res.node,
                .kind = cast_kind,
                .implicit = false,
            },
        });
    }

    fn intFitsInType(res: Result, p: *Parser, ty: QualType) !bool {
        const max_int = try Value.maxInt(ty, p.comp);
        const min_int = try Value.minInt(ty, p.comp);
        return res.val.compare(.lte, max_int, p.comp) and
            (res.qt.signedness(p.comp) == .unsigned or res.val.compare(.gte, min_int, p.comp));
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

        fn typePairStr(c: CoerceContext, p: *Parser, dest_ty: QualType, src_ty: QualType) ![]const u8 {
            switch (c) {
                .assign, .init => return p.typePairStrExtra(dest_ty, " from incompatible type ", src_ty),
                .ret => return p.typePairStrExtra(src_ty, " from a function with incompatible result type ", dest_ty),
                .arg => return p.typePairStrExtra(src_ty, " to parameter of incompatible type ", dest_ty),
                .test_coerce => unreachable,
            }
        }
    };

    /// Perform assignment-like coercion to `dest_ty`.
    fn coerce(res: *Result, p: *Parser, dest_ty: QualType, tok: TokenIndex, c: CoerceContext) Error!void {
        if (res.qt.isInvalid() or dest_ty.isInvalid()) {
            res.qt = .invalid;
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
        dest_qt: QualType,
        tok: TokenIndex,
        c: CoerceContext,
    ) (Error || error{CoercionFailed})!void {
        const dest_sk = dest_qt.scalarKind(p.comp);
        const src_sk = res.qt.scalarKind(p.comp);

        if (dest_sk == .nullptr_t) {
            if (src_sk == .nullptr_t) return;
        } else if (dest_sk == .bool) {
            if (src_sk != .none and src_sk != .nullptr_t) {
                // this is ridiculous but it's what clang does
                try res.castToBool(p, dest_qt, tok);
                return;
            }
        } else if (dest_sk.isInt()) {
            if (res.qt.isInt(p.comp) or res.qt.isFloat(p.comp)) {
                try res.castToInt(p, dest_qt, tok);
                return;
            } else if (src_sk.isPointer()) {
                if (c == .test_coerce) return error.CoercionFailed;
                try p.errStr(.implicit_ptr_to_int, tok, try p.typePairStrExtra(res.qt, " to ", dest_qt));
                try c.note(p);
                try res.castToInt(p, dest_qt, tok);
                return;
            }
        } else if (dest_sk.isFloat()) {
            if (res.qt.isInt(p.comp) or res.qt.isFloat(p.comp)) {
                try res.castToFloat(p, dest_qt, tok);
                return;
            }
        } else if (dest_sk.isPointer()) {
            if (src_sk == .nullptr_t or res.val.isZero(p.comp)) {
                try res.nullToPointer(p, dest_qt, tok);
                return;
            } else if (src_sk.isInt() and src_sk.isReal()) {
                if (c == .test_coerce) return error.CoercionFailed;
                try p.errStr(.implicit_int_to_ptr, tok, try p.typePairStrExtra(res.qt, " to ", dest_qt));
                try c.note(p);
                try res.castToPointer(p, dest_qt, tok);
                return;
            } else if (src_sk == .void_pointer or dest_qt.eql(res.qt, p.comp)) {
                return; // ok
            } else if (dest_sk == .void_pointer and src_sk.isPointer() or (res.qt.isInt(p.comp) and src_sk.isReal())) {
                return; // ok
            } else if (src_sk.isPointer()) {
                const src_child = res.qt.childType(p.comp);
                const dest_child = dest_qt.childType(p.comp);
                if (src_child.eql(dest_child, p.comp)) {
                    if ((src_child.@"const" and !dest_child.@"const") or
                        (src_child.@"volatile" and !dest_child.@"volatile") or
                        (src_child.restrict and !dest_child.restrict))
                    {
                        try p.errStr(switch (c) {
                            .assign => .ptr_assign_discards_quals,
                            .init => .ptr_init_discards_quals,
                            .ret => .ptr_ret_discards_quals,
                            .arg => .ptr_arg_discards_quals,
                            .test_coerce => return error.CoercionFailed,
                        }, tok, try c.typePairStr(p, dest_qt, res.qt));
                    }
                    try res.castToPointer(p, dest_qt, tok);
                    return;
                }

                const different_sign_only = src_child.sameRankDifferentSign(dest_child, p.comp);
                try p.errStr(switch (c) {
                    .assign => if (different_sign_only) .incompatible_ptr_assign_sign else .incompatible_ptr_assign,
                    .init => if (different_sign_only) .incompatible_ptr_init_sign else .incompatible_ptr_init,
                    .ret => if (different_sign_only) .incompatible_return_sign else .incompatible_return,
                    .arg => if (different_sign_only) .incompatible_ptr_arg_sign else .incompatible_ptr_arg,
                    .test_coerce => return error.CoercionFailed,
                }, tok, try c.typePairStr(p, dest_qt, res.qt));
                try c.note(p);

                res.qt = dest_qt;
                return res.implicitCast(p, .bitcast, tok);
            }
        } else if (dest_qt.getRecord(p.comp) != null) {
            if (dest_qt.eql(res.qt, p.comp)) {
                return; // ok
            }

            if (c == .arg) if (dest_qt.get(p.comp, .@"union")) |union_ty| {
                if (dest_qt.hasAttribute(p.comp, .transparent_union)) transparent_union: {
                    res.coerceExtra(p, union_ty.fields[0].qt, tok, .test_coerce) catch |er| switch (er) {
                        error.CoercionFailed => break :transparent_union,
                        else => |e| return e,
                    };
                    res.node = try p.addNode(.{ .union_init_expr = .{
                        .field_index = 0,
                        .initializer = res.node,
                        .l_brace_tok = tok,
                        .union_qt = dest_qt,
                    } });
                    res.qt = dest_qt;
                    return;
                }
            };
        } else if (dest_qt.is(p.comp, .vector)) {
            if (dest_qt.eql(res.qt, p.comp)) {
                return; // ok
            }
        } else {
            if (c == .assign and (dest_qt.is(p.comp, .array) or dest_qt.is(p.comp, .func))) {
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
        }, tok, try c.typePairStr(p, dest_qt, res.qt));
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
        lhs.qt = rhs.qt;
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
            if (rhs.val.isZero(p.comp) and lhs.qt.isInt(p.comp) and rhs.qt.isInt(p.comp)) {
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
            if (lhs.qt.isPointer(p.comp) and rhs.qt.isInt(p.comp)) {
                try rhs.castToPointer(p, lhs.qt, tok);
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

    try rhs.coerce(p, lhs.qt, tok, .assign);

    try lhs.bin(p, tag, rhs, tok);
    return lhs;
}

/// Returns a parse error if the expression is not an integer constant
/// integerConstExpr : constExpr
fn integerConstExpr(p: *Parser, decl_folding: ConstDeclFoldingMode) Error!Result {
    const start = p.tok_i;
    const res = try p.constExpr(decl_folding);
    if (!res.qt.isInvalid() and !res.qt.isInt(p.comp)) {
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

    if (res.qt.isInvalid() or res.val.opt_ref == .none) return res;

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

    if (cond.qt.scalarKind(p.comp) == .none) {
        try p.errStr(.cond_expr_type, cond_tok, try p.typeStr(cond.qt));
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
                .qt = cond.qt,
            },
        });
        _ = try cond_then.adjustTypes(colon, &then_expr, p, .conditional);
        cond.qt = then_expr.qt;
        cond.node = try p.addNode(.{
            .binary_cond_expr = .{
                .cond_tok = cond_tok,
                .cond = cond.node,
                .then_expr = cond_then.node,
                .else_expr = then_expr.node,
                .qt = cond.qt,
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
    cond.qt = then_expr.qt;
    cond.node = try p.addNode(.{
        .cond_expr = .{
            .cond_tok = cond_tok,
            .qt = cond.qt,
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

            const res: ?bool = if (lhs.qt.isPointer(p.comp) or rhs.qt.isPointer(p.comp))
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

            const res: ?bool = if (lhs.qt.isPointer(p.comp) or rhs.qt.isPointer(p.comp))
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
            if (rhs.val.compare(.lt, .zero, p.comp)) {
                try p.errStr(.negative_shift_count, tok, try rhs.str(p));
            }
            if (rhs.val.compare(.gte, try Value.int(lhs.qt.bitSizeof(p.comp), p.comp), p.comp)) {
                try p.errStr(.too_big_shift_count, tok, try rhs.str(p));
            }
            if (tag == .shl_expr) {
                if (try lhs.val.shl(lhs.val, rhs.val, lhs.qt, p.comp) and
                    lhs.qt.signedness(p.comp) != .unsigned) try p.errOverflow(tok, lhs);
            } else {
                lhs.val = try lhs.val.shr(rhs.val, lhs.qt, p.comp);
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

        if (try lhs.adjustTypes(tok, &rhs, p, if (tag == .add_expr) .add else .sub)) {
            const lhs_sk = lhs.qt.scalarKind(p.comp);
            if (tag == .add_expr) {
                if (try lhs.val.add(lhs.val, rhs.val, lhs.qt, p.comp)) {
                    if (lhs_sk.isPointer()) {
                        try p.errArrayOverflow(tok, lhs);
                    } else if (lhs.qt.signedness(p.comp) != .unsigned) {
                        try p.errOverflow(tok, lhs);
                    }
                }
            } else {
                const elem_size = if (lhs_sk.isPointer()) lhs.qt.childType(p.comp).sizeofOrNull(p.comp) orelse 1 else 1;
                if (elem_size == 0 and rhs.qt.isPointer(p.comp)) {
                    lhs.val = .{};
                } else {
                    if (try lhs.val.sub(lhs.val, rhs.val, lhs.qt, elem_size, p.comp) and
                        lhs.qt.signedness(p.comp) != .unsigned) try p.errOverflow(tok, lhs);
                }
            }
        } else if (!lhs.qt.isInvalid()) {
            const lhs_sk = lhs.qt.scalarKind(p.comp);
            if (lhs_sk == .pointer and lhs.qt.childType(p.comp).sizeofOrNull(p.comp) == null) {
                try p.errStr(.ptr_arithmetic_incomplete, tok, try p.typeStr(lhs.qt.childType(p.comp)));
                lhs.qt = .invalid;
            }
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

        if (rhs.val.isZero(p.comp) and tag != .mul_expr and !p.no_eval and lhs.qt.isInt(p.comp) and rhs.qt.isInt(p.comp)) {
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
                .mul_expr => if (try lhs.val.mul(lhs.val, rhs.val, lhs.qt, p.comp) and
                    lhs.qt.signedness(p.comp) != .unsigned) try p.errOverflow(tok, lhs),
                .div_expr => if (try lhs.val.div(lhs.val, rhs.val, lhs.qt, p.comp) and
                    lhs.qt.signedness(p.comp) != .unsigned) try p.errOverflow(tok, lhs),
                .mod_expr => {
                    var res = try Value.rem(lhs.val, rhs.val, lhs.qt, p.comp);
                    if (res.opt_ref == .none) {
                        if (p.in_macro) {
                            // match clang behavior by defining invalid remainder to be zero in macros
                            res = .zero;
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
            if (p.func.qt == null) {
                try p.err(.stmt_expr_not_allowed_file_scope);
                return error.ParsingFailed;
            }
            var stmt_expr_state: StmtExprState = .{};
            const body_node = (try p.compoundStmt(false, &stmt_expr_state)).?; // compoundStmt only returns null if .l_brace isn't the first token
            p.removeUnusedWarningForTok(stmt_expr_state.last_expr_tok);

            var res = Result{
                .node = body_node,
                .qt = stmt_expr_state.last_expr_qt,
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

    const compatible = lhs.eql(rhs, p.comp);
    const res: Result = .{
        .val = Value.fromBool(compatible),
        .qt = .int,
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
        cond.qt = then_expr.qt;
    } else {
        cond.val = else_expr.val;
        cond.qt = else_expr.qt;
    }
    cond.node = try p.addNode(.{
        .builtin_choose_expr = .{
            .cond_tok = cond_tok,
            .qt = cond.qt,
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

    if (!va_list.qt.eql(p.comp.type_store.va_list, p.comp)) {
        try p.errStr(.incompatible_va_arg, va_list_tok, try p.typeStr(va_list.qt));
        return error.ParsingFailed;
    }

    return .{
        .qt = ty,
        .node = try p.addNode(.{
            .builtin_call_expr = .{
                .builtin_tok = builtin_tok,
                .qt = ty,
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

    const operand_qt = (try p.typeName()) orelse {
        try p.err(.expected_type);
        p.skipTo(.r_paren);
        return error.ParsingFailed;
    };

    const record_ty = operand_qt.getRecord(p.comp) orelse {
        try p.errStr(.offsetof_ty, ty_tok, try p.typeStr(operand_qt));
        p.skipTo(.r_paren);
        return error.ParsingFailed;
    };

    if (record_ty.layout == null) {
        try p.errStr(.offsetof_incomplete, ty_tok, try p.typeStr(operand_qt));
        p.skipTo(.r_paren);
        return error.ParsingFailed;
    }

    _ = try p.expectToken(.comma);

    const offsetof_expr = try p.offsetofMemberDesignator(record_ty, operand_qt, offset_kind, builtin_tok);

    try p.expectClosing(l_paren, .r_paren);

    return .{
        .qt = p.comp.type_store.size,
        .val = offsetof_expr.val,
        .node = try p.addNode(.{
            .builtin_call_expr = .{
                .builtin_tok = builtin_tok,
                .qt = p.comp.type_store.size,
                .args = &.{offsetof_expr.node},
            },
        }),
    };
}

/// offsetofMemberDesignator: IDENTIFIER ('.' IDENTIFIER | '[' expr ']' )*
fn offsetofMemberDesignator(
    p: *Parser,
    base_record_ty: Type.Record,
    base_qt: QualType,
    offset_kind: OffsetKind,
    access_tok: TokenIndex,
) Error!Result {
    errdefer p.skipTo(.r_paren);
    const base_field_name_tok = try p.expectIdentifier();
    const base_field_name = try p.comp.internString(p.tokSlice(base_field_name_tok));

    try p.validateFieldAccess(base_record_ty, base_qt, base_field_name_tok, base_field_name);
    const base_node = try p.addNode(.{ .default_init_expr = .{
        .last_tok = p.tok_i,
        .qt = base_qt,
    } });

    var cur_offset: u64 = 0;
    var lhs = try p.fieldAccessExtra(base_node, base_record_ty, base_field_name, false, access_tok, &cur_offset);

    var total_offset = cur_offset;
    while (true) switch (p.tok_ids[p.tok_i]) {
        .period => {
            p.tok_i += 1;
            const field_name_tok = try p.expectIdentifier();
            const field_name = try p.comp.internString(p.tokSlice(field_name_tok));

            const lhs_record_ty = lhs.qt.getRecord(p.comp) orelse {
                try p.errStr(.offsetof_ty, field_name_tok, try p.typeStr(lhs.qt));
                return error.ParsingFailed;
            };
            try p.validateFieldAccess(lhs_record_ty, lhs.qt, field_name_tok, field_name);
            lhs = try p.fieldAccessExtra(lhs.node, lhs_record_ty, field_name, false, access_tok, &cur_offset);
            total_offset += cur_offset;
        },
        .l_bracket => {
            const l_bracket_tok = p.tok_i;
            p.tok_i += 1;
            var index = try p.expect(expr);
            _ = try p.expectClosing(l_bracket_tok, .r_bracket);

            if (!lhs.qt.is(p.comp, .array)) {
                try p.errStr(.offsetof_array, l_bracket_tok, try p.typeStr(lhs.qt));
                return error.ParsingFailed;
            }
            var ptr = lhs;
            try ptr.lvalConversion(p, l_bracket_tok);
            try index.lvalConversion(p, l_bracket_tok);

            if (index.qt.isInt(p.comp)) {
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
    return .{ .qt = base_qt, .val = val, .node = lhs.node };
}

fn computeOffsetExtra(p: *Parser, node: Node.Index, offset_so_far: *Value) !Value {
    switch (node.get(&p.tree)) {
        .cast => |cast| {
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
            var size = try Value.int(access.qt.sizeof(p.comp), p.comp);
            const mul_overflow = try size.mul(size, index_val, p.comp.type_store.ptrdiff, p.comp);

            const add_overflow = try offset_so_far.add(size, offset_so_far.*, p.comp.type_store.ptrdiff, p.comp);
            _ = mul_overflow;
            _ = add_overflow;
            return p.computeOffsetExtra(access.base, offset_so_far);
        },
        .member_access_expr, .member_access_ptr_expr => |access| {
            var ty = access.base.qt(&p.tree);
            if (ty.isPointer(p.comp)) ty = ty.childType(p.comp);
            const record_ty = ty.getRecord(p.comp).?;

            const field_offset = try Value.int(@divExact(record_ty.fields[access.member_index].layout.offset_bits, 8), p.comp);
            _ = try offset_so_far.add(field_offset, offset_so_far.*, p.comp.type_store.ptrdiff, p.comp);
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
    try w.writeAll(member.lookup(p.comp));
    try w.writeAll("' of class or structure '");
    try w.writeAll(record.lookup(p.comp));
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

            return .{
                .node = try p.addNode(.{
                    .addr_of_label = .{
                        .label_tok = name_tok,
                        .qt = .void_pointer,
                    },
                }),
                .qt = .void_pointer,
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
                const lhs_qt = access.base.qt(&p.tree);
                if (lhs_qt.hasAttribute(p.comp, .@"packed")) {
                    const record_ty = lhs_qt.getRecord(p.comp).?;
                    try p.errStr(.packed_member_address, orig_tok_i, try p.packedMemberAccessStr(record_ty.name, record_ty.fields[access.member_index].name));
                }
            }
            if (!operand.qt.isInvalid()) {
                if (!p.tree.isLval(operand.node)) {
                    try p.errTok(.addr_of_rvalue, tok);
                }
                addr_val = try p.computeOffset(operand);

                operand.qt = try p.comp.type_store.put(p.gpa, .{ .pointer = .{
                    .child = operand.qt,
                    .decayed = null,
                } });
            }
            if (p.getNode(operand.node, .decl_ref_expr)) |decl_ref| {
                switch (decl_ref.decl.get(&p.tree)) {
                    .variable => |variable| {
                        if (variable.storage_class == .register) try p.errTok(.addr_of_register, tok);
                    },
                    else => {},
                }
            } else if (p.getNode(operand.node, .compound_literal_expr)) |literal| {
                switch (literal.storage_class) {
                    .register => try p.errTok(.addr_of_register, tok),
                    else => {},
                }
            }

            try operand.saveValue(p);
            try operand.un(p, .addr_of_expr, tok);
            operand.val = addr_val;
            return operand;
        },
        .asterisk => {
            p.tok_i += 1;
            var operand = try p.expect(castExpr);

            switch (operand.qt.base(p.comp).type) {
                .array, .func, .pointer => {
                    try operand.lvalConversion(p, tok);
                    operand.qt = operand.qt.childType(p.comp);
                    operand.val = .{};
                },
                else => {
                    try p.errTok(.indirection_ptr, tok);
                },
            }

            if (operand.qt.sizeofOrNull(p.comp) == null and !operand.qt.is(p.comp, .void)) {
                try p.errStr(.deref_incomplete_ty_ptr, tok, try p.typeStr(operand.qt));
            }

            operand.qt = operand.qt.unqualified();
            try operand.un(p, .deref_expr, tok);
            return operand;
        },
        .plus => {
            p.tok_i += 1;

            var operand = try p.expect(castExpr);
            try operand.lvalConversion(p, tok);
            if (!operand.qt.isInt(p.comp) and !operand.qt.isFloat(p.comp))
                try p.errStr(.invalid_argument_un, tok, try p.typeStr(operand.qt));

            try operand.usualUnaryConversion(p, tok);

            return operand;
        },
        .minus => {
            p.tok_i += 1;

            var operand = try p.expect(castExpr);
            try operand.lvalConversion(p, tok);
            if (!operand.qt.isInt(p.comp) and !operand.qt.isFloat(p.comp))
                try p.errStr(.invalid_argument_un, tok, try p.typeStr(operand.qt));

            try operand.usualUnaryConversion(p, tok);
            if (operand.val.isArithmetic(p.comp)) {
                _ = try operand.val.negate(operand.val, operand.qt, p.comp);
            } else {
                operand.val = .{};
            }
            try operand.un(p, .negate_expr, tok);
            return operand;
        },
        .plus_plus => {
            p.tok_i += 1;

            var operand = try p.expect(castExpr);
            const scalar_kind = operand.qt.scalarKind(p.comp);
            if (scalar_kind == .void_pointer)
                try p.errTok(.gnu_pointer_arith, tok);
            if (scalar_kind == .none)
                try p.errStr(.invalid_argument_un, tok, try p.typeStr(operand.qt));
            if (!scalar_kind.isReal())
                try p.errStr(.complex_prefix_postfix_op, p.tok_i, try p.typeStr(operand.qt));

            if (!p.tree.isLval(operand.node) or operand.qt.@"const") {
                try p.errTok(.not_assignable, tok);
                return error.ParsingFailed;
            }
            try operand.usualUnaryConversion(p, tok);

            if (operand.val.is(.int, p.comp) or operand.val.is(.int, p.comp)) {
                if (try operand.val.add(operand.val, .one, operand.qt, p.comp))
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
            const scalar_kind = operand.qt.scalarKind(p.comp);
            if (scalar_kind == .void_pointer)
                try p.errTok(.gnu_pointer_arith, tok);
            if (scalar_kind == .none)
                try p.errStr(.invalid_argument_un, tok, try p.typeStr(operand.qt));
            if (!scalar_kind.isReal())
                try p.errStr(.complex_prefix_postfix_op, p.tok_i, try p.typeStr(operand.qt));

            if (!p.tree.isLval(operand.node) or operand.qt.@"const") {
                try p.errTok(.not_assignable, tok);
                return error.ParsingFailed;
            }
            try operand.usualUnaryConversion(p, tok);

            if (operand.val.is(.int, p.comp) or operand.val.is(.int, p.comp)) {
                if (try operand.val.decrement(operand.val, operand.qt, p.comp))
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
            const scalar_kind = operand.qt.scalarKind(p.comp);
            if (scalar_kind.isInt()) {
                if (operand.val.is(.int, p.comp)) {
                    operand.val = try operand.val.bitNot(operand.qt, p.comp);
                }
            } else if (!scalar_kind.isReal()) {
                try p.errStr(.complex_conj, tok, try p.typeStr(operand.qt));
                if (operand.val.is(.complex, p.comp)) {
                    operand.val = try operand.val.complexConj(operand.qt, p.comp);
                }
            } else {
                try p.errStr(.invalid_argument_un, tok, try p.typeStr(operand.qt));
                operand.val = .{};
            }
            try operand.un(p, .bit_not_expr, tok);
            return operand;
        },
        .bang => {
            p.tok_i += 1;

            var operand = try p.expect(castExpr);
            try operand.lvalConversion(p, tok);
            if (operand.qt.scalarKind(p.comp) == .none)
                try p.errStr(.invalid_argument_un, tok, try p.typeStr(operand.qt));

            try operand.usualUnaryConversion(p, tok);
            if (operand.val.is(.int, p.comp)) {
                operand.val = Value.fromBool(!operand.val.toBool(p.comp));
            } else if (operand.val.opt_ref == .null) {
                operand.val = .one;
            } else {
                operand.val = .{};
                if (operand.qt.get(p.comp, .pointer)) |pointer_ty| {
                    if (pointer_ty.decayed != null) operand.val = .zero;
                }
            }
            operand.qt = .int;
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
            if (try p.typeName()) |qt| {
                res.qt = qt;
                try p.errTok(.expected_parens_around_typename, expected_paren);
            } else if (p.eatToken(.l_paren)) |l_paren| {
                if (try p.typeName()) |ty| {
                    res.qt = ty;
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
            const operand_qt = res.qt;

            if (res.qt.isInvalid()) {
                res.val = .{};
            } else {
                const base_type = res.qt.base(p.comp);
                switch (base_type.type) {
                    .void => try p.errStr(.pointer_arith_void, tok, "sizeof"),
                    .pointer => |pointer_ty| if (pointer_ty.decayed) |decayed_qt| {
                        const err_str = try p.typePairStrExtra(res.qt, " instead of ", decayed_qt);
                        try p.errStr(.sizeof_array_arg, tok, err_str);
                    },
                    else => {},
                }

                if (base_type.qt.sizeofOrNull(p.comp)) |size| {
                    if (size == 0) {
                        try p.errTok(.sizeof_returns_zero, tok);
                    }
                    res.val = try Value.int(size, p.comp);
                    res.qt = p.comp.type_store.size;
                } else {
                    res.val = .{};
                    try p.errStr(.invalid_sizeof, expected_paren - 1, try p.typeStr(res.qt));
                    res.qt = .invalid;
                }
            }

            res.node = try p.addNode(.{ .sizeof_expr = .{
                .op_tok = tok,
                .qt = res.qt,
                .expr = if (has_expr) res.node else null,
                .operand_qt = operand_qt,
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
            if (try p.typeName()) |qt| {
                res.qt = qt;
                try p.errTok(.expected_parens_around_typename, expected_paren);
            } else if (p.eatToken(.l_paren)) |l_paren| {
                if (try p.typeName()) |qt| {
                    res.qt = qt;
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
            const operand_qt = res.qt;

            if (res.qt.is(p.comp, .void)) {
                try p.errStr(.pointer_arith_void, tok, "alignof");
            }

            if (res.qt.sizeofOrNull(p.comp) != null) {
                res.val = try Value.int(res.qt.alignof(p.comp), p.comp);
                res.qt = p.comp.type_store.size;
            } else if (!res.qt.isInvalid()) {
                try p.errStr(.invalid_alignof, expected_paren, try p.typeStr(res.qt));
                res.qt = .invalid;
            }

            res.node = try p.addNode(.{ .alignof_expr = .{
                .op_tok = tok,
                .qt = res.qt,
                .expr = if (has_expr) res.node else null,
                .operand_qt = operand_qt,
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
            if (operand.qt.isInvalid()) return operand;

            const scalar_kind = operand.qt.scalarKind(p.comp);
            if (!scalar_kind.isArithmetic()) {
                try p.errStr(.invalid_imag, imag_tok, try p.typeStr(operand.qt));
            }
            if (!scalar_kind.isReal()) {
                operand.val = try operand.val.imaginaryPart(p.comp);
            } else switch (p.comp.langopts.emulate) {
                .msvc => {}, // Doesn't support `_Complex` or `__imag` in the first place
                .gcc => operand.val = .zero,
                .clang => {
                    if (operand.val.is(.int, p.comp) or operand.val.is(.float, p.comp)) {
                        operand.val = .zero;
                    } else {
                        operand.val = .{};
                    }
                },
            }
            // convert _Complex T to T
            operand.qt = operand.qt.toReal(p.comp);
            try operand.un(p, .imag_expr, tok);
            return operand;
        },
        .keyword_real1, .keyword_real2 => {
            const real_tok = p.tok_i;
            p.tok_i += 1;

            var operand = try p.expect(castExpr);
            try operand.lvalConversion(p, tok);
            if (operand.qt.isInvalid()) return operand;
            if (!operand.qt.isInt(p.comp) and !operand.qt.isFloat(p.comp)) {
                try p.errStr(.invalid_real, real_tok, try p.typeStr(operand.qt));
            }
            // convert _Complex T to T
            operand.qt = operand.qt.toReal(p.comp);
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

    var d: DeclSpec = .{ .qt = .invalid };
    const any = if (p.comp.langopts.standard.atLeast(.c23))
        try p.storageClassSpec(&d)
    else
        false;

    switch (d.storage_class) {
        .auto, .@"extern", .typedef => |tok| {
            try p.errStr(.invalid_compound_literal_storage_class, tok, @tagName(d.storage_class));
            d.storage_class = .none;
        },
        .register => if (p.func.qt == null) try p.err(.illegal_storage_on_global),
        else => {},
    }

    var qt = (try p.typeName()) orelse {
        p.tok_i = l_paren;
        if (any) {
            try p.err(.expected_type);
            return error.ParsingFailed;
        }
        return null;
    };
    try p.expectClosing(l_paren, .r_paren);

    switch (qt.base(p.comp).type) {
        .func => try p.err(.func_init),
        .array => |array_ty| if (array_ty.len == .variable) {
            try p.err(.vla_init);
        },
        else => if (qt.sizeofOrNull(p.comp) == null) {
            try p.errStr(.variable_incomplete_ty, p.tok_i, try p.typeStr(qt));
            return error.ParsingFailed;
        },
    }

    const init_context = p.init_context;
    defer p.init_context = init_context;
    p.init_context = d.initContext(p);
    var init_list_expr = try p.initializer(qt);
    if (d.constexpr) |_| {
        // TODO error if not constexpr
    }

    init_list_expr.node = try p.addNode(.{ .compound_literal_expr = .{
        .l_paren_tok = l_paren,
        .storage_class = switch (d.storage_class) {
            .register => .register,
            .static => .static,
            else => .auto,
        },
        .thread_local = d.thread_local != null,
        .initializer = init_list_expr.node,
        .qt = init_list_expr.qt,
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
        .l_paren => return try p.callExpr(lhs),
        .plus_plus => {
            defer p.tok_i += 1;

            var operand = lhs;
            const scalar_kind = operand.qt.scalarKind(p.comp);
            if (scalar_kind == .void_pointer)
                try p.errTok(.gnu_pointer_arith, p.tok_i);
            if (scalar_kind == .none)
                try p.errStr(.invalid_argument_un, p.tok_i, try p.typeStr(operand.qt));
            if (!scalar_kind.isReal())
                try p.errStr(.complex_prefix_postfix_op, p.tok_i, try p.typeStr(operand.qt));

            if (!p.tree.isLval(operand.node) or operand.qt.@"const") {
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
            const scalar_kind = operand.qt.scalarKind(p.comp);
            if (scalar_kind == .void_pointer)
                try p.errTok(.gnu_pointer_arith, p.tok_i);
            if (scalar_kind == .none)
                try p.errStr(.invalid_argument_un, p.tok_i, try p.typeStr(operand.qt));
            if (!scalar_kind.isReal())
                try p.errStr(.complex_prefix_postfix_op, p.tok_i, try p.typeStr(operand.qt));

            if (!p.tree.isLval(operand.node) or operand.qt.@"const") {
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
            if (ptr.qt.get(p.comp, .pointer)) |pointer_ty| {
                ptr.qt = pointer_ty.child;
                if (index.qt.isInt(p.comp)) {
                    try p.checkArrayBounds(index_before_conversion, array_before_conversion, l_bracket);
                } else {
                    try p.errTok(.invalid_index, l_bracket);
                }
            } else if (index.qt.get(p.comp, .pointer)) |pointer_ty| {
                index.qt = pointer_ty.child;
                if (ptr.qt.isInt(p.comp)) {
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
                .qt = ptr.qt,
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
            if (lhs.qt.is(p.comp, .array)) {
                var copy = lhs;
                copy.qt = try copy.qt.decay(p.comp);
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
    const expr_qt = lhs.qt;
    const is_ptr = expr_qt.isPointer(p.comp);
    const expr_base_qt = if (is_ptr) expr_qt.childType(p.comp) else expr_qt;
    const record_ty = expr_base_qt.getRecord(p.comp) orelse {
        try p.errStr(.expected_record_ty, field_name_tok, try p.typeStr(expr_qt));
        return error.ParsingFailed;
    };

    if (record_ty.layout == null) {
        try p.errStr(.deref_incomplete_ty_ptr, field_name_tok - 2, try p.typeStr(expr_base_qt));
        return error.ParsingFailed;
    }
    if (is_arrow and !is_ptr) try p.errStr(.member_expr_not_ptr, field_name_tok, try p.typeStr(expr_qt));
    if (!is_arrow and is_ptr) try p.errStr(.member_expr_ptr, field_name_tok, try p.typeStr(expr_qt));

    const field_name = try p.comp.internString(p.tokSlice(field_name_tok));
    try p.validateFieldAccess(record_ty, expr_qt, field_name_tok, field_name);
    var discard: u64 = 0;
    return p.fieldAccessExtra(lhs.node, record_ty, field_name, is_arrow, access_tok, &discard);
}

fn validateFieldAccess(p: *Parser, record_ty: Type.Record, expr_ty: QualType, field_name_tok: TokenIndex, field_name: StringId) Error!void {
    if (record_ty.hasField(p.comp, field_name)) return;

    p.strings.items.len = 0;

    try p.strings.writer().print("'{s}' in '", .{p.tokSlice(field_name_tok)});
    try expr_ty.print(p.comp, p.strings.writer());
    try p.strings.append('\'');

    const duped = try p.comp.diagnostics.arena.allocator().dupe(u8, p.strings.items);
    try p.errStr(.no_such_member, field_name_tok, duped);
    return error.ParsingFailed;
}

fn fieldAccessExtra(
    p: *Parser,
    base: Node.Index,
    record_ty: Type.Record,
    target_name: StringId,
    is_arrow: bool,
    access_tok: TokenIndex,
    offset_bits: *u64,
) Error!Result {
    for (record_ty.fields, 0..) |field, field_index| {
        if (field.name == .empty) if (field.qt.getRecord(p.comp)) |field_record_ty| {
            if (!field_record_ty.hasField(p.comp, target_name)) continue;

            const access: Node.MemberAccess = .{
                .access_tok = access_tok,
                .qt = field.qt,
                .base = base,
                .member_index = @intCast(field_index),
            };
            const inner = try p.addNode(if (is_arrow)
                .{ .member_access_ptr_expr = access }
            else
                .{ .member_access_expr = access });

            const ret = p.fieldAccessExtra(inner, field_record_ty, target_name, false, access_tok, offset_bits);
            offset_bits.* = field.layout.offset_bits;
            return ret;
        };
        if (target_name == field.name) {
            offset_bits.* = field.layout.offset_bits;

            const access: Node.MemberAccess = .{
                .access_tok = access_tok,
                .qt = field.qt,
                .base = base,
                .member_index = @intCast(field_index),
            };
            return .{ .qt = field.qt, .node = try p.addNode(if (is_arrow)
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

    const func_qt = p.func.qt orelse {
        try p.errTok(.va_start_not_in_func, builtin_tok);
        return;
    };
    const func_ty = func_qt.get(p.comp, .func) orelse return;
    if (func_ty.kind != .variadic or func_ty.params.len == 0) {
        return p.errTok(.va_start_fixed_args, builtin_tok);
    }
    const last_param_name = func_ty.params[func_ty.params.len - 1].name;
    const decl_ref = p.getNode(arg.node, .decl_ref_expr);
    if (decl_ref == null or last_param_name != try p.comp.internString(p.tokSlice(decl_ref.?.name_tok))) {
        try p.errTok(.va_start_not_last_param, param_tok);
    }
}

fn checkArithOverflowArg(p: *Parser, builtin_tok: TokenIndex, first_after: TokenIndex, param_tok: TokenIndex, arg: *Result, idx: u32) !void {
    _ = builtin_tok;
    _ = first_after;
    if (idx <= 1) {
        if (!arg.qt.isInt(p.comp)) {
            return p.errStr(.overflow_builtin_requires_int, param_tok, try p.typeStr(arg.qt));
        }
    } else if (idx == 2) {
        if (!arg.qt.isPointer(p.comp)) return p.errStr(.overflow_result_requires_ptr, param_tok, try p.typeStr(arg.qt));
        const child = arg.qt.childType(p.comp);
        if (!child.isInt(p.comp) or child.@"const") return p.errStr(.overflow_result_requires_ptr, param_tok, try p.typeStr(arg.qt));
    }
}

fn checkComplexArg(p: *Parser, builtin_tok: TokenIndex, first_after: TokenIndex, param_tok: TokenIndex, arg: *Result, idx: u32) !void {
    _ = builtin_tok;
    _ = first_after;
    if (idx <= 1 and !arg.qt.isFloat(p.comp)) {
        try p.errStr(.not_floating_type, param_tok, try p.typeStr(arg.qt));
    } else if (idx == 1) {
        const prev_idx = p.list_buf.items[p.list_buf.items.len - 1];
        const prev_qt = prev_idx.qt(&p.tree);
        if (!prev_qt.eql(arg.qt, p.comp)) {
            try p.errStr(.argument_types_differ, param_tok, try p.typePairStrExtra(prev_qt, " vs ", arg.qt));
        }
    }
}

fn callExpr(p: *Parser, lhs: Result) Error!Result {
    const l_paren = p.tok_i;
    p.tok_i += 1;

    // We cannot refer to the function type here because the pointer to
    // type_store.extra might get invalidated while parsing args.
    const func_qt, const params_len, const func_kind = blk: {
        var base_qt = lhs.qt;
        if (base_qt.get(p.comp, .pointer)) |pointer_ty| base_qt = pointer_ty.child;
        if (base_qt.isInvalid()) break :blk .{ base_qt, std.math.maxInt(usize), undefined };

        const func_type_qt = base_qt.base(p.comp);
        if (func_type_qt.type != .func) {
            try p.errStr(.not_callable, l_paren, try p.typeStr(lhs.qt));
            return error.ParsingFailed;
        }
        break :blk .{ func_type_qt.qt, func_type_qt.type.func.params.len, func_type_qt.type.func.kind };
    };

    var func = lhs;
    try func.lvalConversion(p, l_paren);

    const list_buf_top = p.list_buf.items.len;
    defer p.list_buf.items.len = list_buf_top;
    var arg_count: u32 = 0;
    var first_after = l_paren;

    const call_expr = CallExpr.init(p, lhs.node, func.node);

    while (p.eatToken(.r_paren) == null) {
        const param_tok = p.tok_i;
        if (arg_count == params_len) first_after = p.tok_i;
        var arg = try p.expect(assignExpr);

        if (call_expr.shouldPerformLvalConversion(arg_count)) {
            try arg.lvalConversion(p, param_tok);
        }
        if (arg.qt.sizeofOrNull(p.comp) == null and !arg.qt.is(p.comp, .void)) return error.ParsingFailed;

        if (arg_count >= params_len) {
            if (call_expr.shouldPromoteVarArg(arg_count)) switch (arg.qt.base(p.comp).type) {
                .int => |int_ty| if (int_ty == .int) try arg.castToInt(p, arg.qt.promoteInt(p.comp), param_tok),
                .float => |float_ty| if (float_ty == .double) try arg.castToFloat(p, .double, param_tok),
                else => {},
            };

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

        if (func_qt.get(p.comp, .func)) |func_ty| {
            const param = func_ty.params[arg_count];

            if (param.qt.get(p.comp, .array)) |array| static_check: {
                const param_array_len = switch (array.len) {
                    .static => |len| len,
                    else => break :static_check,
                };
                const arg_array_len = arg.qt.arrayLen(p.comp) orelse break :static_check;

                if (arg_array_len < param_array_len) {
                    const extra = Diagnostics.Message.Extra{ .arguments = .{
                        .expected = @intCast(arg_array_len),
                        .actual = @intCast(param_array_len),
                    } };
                    try p.errExtra(.array_argument_too_small, param_tok, extra);
                    try p.errTok(.callee_with_static_array, param.name_tok);
                }
                if (arg.val.isZero(p.comp)) {
                    try p.errTok(.non_null_argument, param_tok);
                    try p.errTok(.callee_with_static_array, param.name_tok);
                }
            }

            if (call_expr.shouldCoerceArg(arg_count)) {
                try arg.coerce(p, param.qt, param_tok, .{ .arg = param.name_tok });
            }
        }
        try arg.saveValue(p);
        try p.list_buf.append(arg.node);
        arg_count += 1;

        _ = p.eatToken(.comma) orelse {
            try p.expectClosing(l_paren, .r_paren);
            break;
        };
    }
    if (func_qt.isInvalid()) {
        // Skip argument count checks.
        return try call_expr.finish(p, func_qt, list_buf_top, l_paren);
    }

    const actual: u32 = @intCast(arg_count);
    const extra = Diagnostics.Message.Extra{ .arguments = .{
        .expected = @intCast(params_len),
        .actual = actual,
    } };
    if (call_expr.paramCountOverride()) |expected| {
        if (expected != actual) {
            try p.errExtra(.expected_arguments, first_after, .{ .arguments = .{ .expected = expected, .actual = actual } });
        }
    } else switch (func_kind) {
        .normal => if (params_len != arg_count) {
            try p.errExtra(.expected_arguments, first_after, extra);
        },
        .variadic => if (arg_count < params_len) {
            try p.errExtra(.expected_at_least_arguments, first_after, extra);
        },
        .old_style => if (params_len != arg_count) {
            if (params_len == 0)
                try p.errTok(.passing_args_to_kr, first_after)
            else
                try p.errExtra(.expected_arguments_old, first_after, extra);
        },
    }

    return try call_expr.finish(p, func_qt, list_buf_top, l_paren);
}

fn checkArrayBounds(p: *Parser, index: Result, array: Result, tok: TokenIndex) !void {
    if (index.val.opt_ref == .none) return;

    const array_len = array.qt.arrayLen(p.comp) orelse return;
    if (array_len == 0) return;

    if (array_len == 1) {
        if (p.getNode(array.node, .member_access_expr) orelse p.getNode(array.node, .member_access_ptr_expr)) |access| {
            var base_ty = access.base.qt(&p.tree);
            if (base_ty.get(p.comp, .pointer)) |pointer_ty| {
                base_ty = pointer_ty.child;
            }
            if (base_ty.getRecord(p.comp)) |record_ty| {
                if (access.member_index + 1 == record_ty.fields.len) {
                    if (!index.val.isZero(p.comp)) {
                        try p.errStr(.old_style_flexible_struct, tok, try index.str(p));
                    }
                    return;
                }
            }
        }
    }
    const index_int = index.val.toInt(u64, p.comp) orelse std.math.maxInt(u64);
    if (index.qt.signedness(p.comp) == .unsigned) {
        if (index_int >= array_len) {
            try p.errStr(.array_after, tok, try index.str(p));
        }
    } else {
        if (index.val.compare(.lt, .zero, p.comp)) {
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
            const interned_name = try p.comp.internString(name);
            if (interned_name == p.auto_type_decl_name) {
                try p.errStr(.auto_type_self_initialized, name_tok, name);
                return error.ParsingFailed;
            }

            if (p.syms.findSymbol(interned_name)) |sym| {
                try p.checkDeprecatedUnavailable(sym.qt, name_tok, sym.tok);
                if (sym.kind == .constexpr) {
                    return .{
                        .val = sym.val,
                        .qt = sym.qt,
                        .node = try p.addNode(.{
                            .decl_ref_expr = .{
                                .name_tok = name_tok,
                                .qt = sym.qt,
                                .decl = sym.node.unpack().?,
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

                const node = try p.addNode(if (sym.kind == .enumeration)
                    .{ .enumeration_ref = .{
                        .name_tok = name_tok,
                        .qt = sym.qt,
                        .decl = sym.node.unpack().?,
                    } }
                else
                    .{ .decl_ref_expr = .{
                        .name_tok = name_tok,
                        .qt = sym.qt,
                        .decl = sym.node.unpack().?,
                    } });
                return .{
                    .val = if (p.const_decl_folding == .no_const_decl_folding and sym.kind != .enumeration) Value{} else sym.val,
                    .qt = sym.qt,
                    .node = node,
                };
            }

            // Check if this is a builtin call.
            if (try p.comp.builtins.getOrCreate(p.comp, name)) |some| {
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
                    .qt = some.qt,
                    .node = try p.addNode(.{
                        .builtin_ref = .{
                            .name_tok = name_tok,
                            .qt = some.qt,
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

                const func_qt = try p.comp.type_store.put(p.gpa, .{ .func = .{
                    .return_type = .int,
                    .kind = .old_style,
                    .params = &.{},
                } });
                const node = try p.addNode(.{
                    .fn_proto = .{
                        .name_tok = name_tok,
                        .qt = func_qt,
                        .static = false,
                        .@"inline" = false,
                        .definition = null,
                    },
                });

                try p.decl_buf.append(node);
                try p.syms.declareSymbol(p, interned_name, func_qt, name_tok, node);

                return .{
                    .qt = func_qt,
                    .node = try p.addNode(.{
                        .decl_ref_expr = .{
                            .name_tok = name_tok,
                            .qt = func_qt,
                            .decl = node,
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
                .val = .fromBool(id == .keyword_true),
                .qt = .bool,
                .node = try p.addNode(.{
                    .bool_literal = .{
                        .qt = .bool,
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
                .val = .null,
                .qt = .nullptr_t,
                .node = try p.addNode(.{
                    .nullptr_literal = .{
                        .qt = .nullptr_t,
                        .literal_tok = p.tok_i,
                    },
                }),
            };
        },
        .macro_func, .macro_function => {
            defer p.tok_i += 1;
            var ty: QualType = undefined;
            var tok = p.tok_i;

            if (p.func.ident) |some| {
                ty = some.qt;
                tok = some.node.get(&p.tree).variable.name_tok;
            } else if (p.func.qt) |_| {
                const strings_top = p.strings.items.len;
                defer p.strings.items.len = strings_top;

                try p.strings.appendSlice(p.tokSlice(p.func.name));
                try p.strings.append(0);
                const predef = try p.makePredefinedIdentifier(strings_top);
                ty = predef.qt;
                p.func.ident = predef;
            } else {
                const strings_top = p.strings.items.len;
                defer p.strings.items.len = strings_top;

                try p.strings.append(0);
                const predef = try p.makePredefinedIdentifier(strings_top);
                ty = predef.qt;
                p.func.ident = predef;
                try p.decl_buf.append(predef.node);
            }
            if (p.func.qt == null) try p.err(.predefined_top_level);

            return .{
                .qt = ty,
                .node = try p.addNode(.{
                    .decl_ref_expr = .{
                        .name_tok = tok,
                        .qt = ty,
                        .decl = p.func.ident.?.node,
                    },
                }),
            };
        },
        .macro_pretty_func => {
            defer p.tok_i += 1;
            var qt: QualType = undefined;
            if (p.func.pretty_ident) |some| {
                qt = some.qt;
            } else if (p.func.qt) |func_qt| {
                const strings_top = p.strings.items.len;
                defer p.strings.items.len = strings_top;

                try func_qt.printNamed(p.tokSlice(p.func.name), p.comp, p.strings.writer());
                try p.strings.append(0);
                const predef = try p.makePredefinedIdentifier(strings_top);
                qt = predef.qt;
                p.func.pretty_ident = predef;
            } else {
                const strings_top = p.strings.items.len;
                defer p.strings.items.len = strings_top;

                try p.strings.appendSlice("top level\x00");
                const predef = try p.makePredefinedIdentifier(strings_top);
                qt = predef.qt;
                p.func.pretty_ident = predef;
                try p.decl_buf.append(predef.node);
            }
            if (p.func.qt == null) try p.err(.predefined_top_level);
            return .{
                .qt = qt,
                .node = try p.addNode(.{
                    .decl_ref_expr = .{
                        .name_tok = p.tok_i,
                        .qt = qt,
                        .decl = undefined, // TODO
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
            const int_qt: QualType = if (p.in_macro) p.comp.type_store.intmax else .int;
            const res: Result = .{
                .val = .zero,
                .qt = int_qt,
                .node = try p.addNode(.{ .int_literal = .{ .qt = int_qt, .literal_tok = p.tok_i } }),
            };
            try res.putValue(p);
            return res;
        },
        .one => {
            defer p.tok_i += 1;
            const int_qt: QualType = if (p.in_macro) p.comp.type_store.intmax else .int;
            const res: Result = .{
                .val = .one,
                .qt = int_qt,
                .node = try p.addNode(.{ .int_literal = .{ .qt = int_qt, .literal_tok = p.tok_i } }),
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
            const res: Result = .{
                .val = try Value.int(byte, p.comp),
                .qt = .int,
                .node = try p.addNode(.{ .int_literal = .{ .qt = .int, .literal_tok = p.tok_i } }),
            };
            try res.putValue(p);
            return res;
        },
        .keyword_generic => return p.genericSelection(),
        else => return null,
    }
}

fn makePredefinedIdentifier(p: *Parser, strings_top: usize) !Result {
    const array_qt = try p.comp.type_store.put(p.gpa, .{ .array = .{
        .elem = .{ .@"const" = true, ._index = .int_char },
        .len = .{ .fixed = p.strings.items.len - strings_top },
    } });

    const slice = p.strings.items[strings_top..];
    const val = try Value.intern(p.comp, .{ .bytes = slice });

    const str_lit = try p.addNode(.{ .string_literal_expr = .{ .qt = array_qt, .literal_tok = p.tok_i } });
    if (!p.in_macro) try p.tree.value_map.put(p.gpa, str_lit, val);

    return .{ .qt = array_qt, .node = try p.addNode(.{
        .variable = .{
            .name_tok = p.tok_i,
            .qt = array_qt,
            .storage_class = .static,
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

    const array_qt = try p.comp.type_store.put(p.gpa, .{ .array = .{
        .elem = string_kind.elementType(p.comp),
        .len = .{ .fixed = @divExact(slice.len, @intFromEnum(char_width)) },
    } });
    const res: Result = .{
        .qt = array_qt,
        .val = val,
        .node = try p.addNode(.{ .string_literal_expr = .{
            .literal_tok = string_start,
            .qt = array_qt,
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
            .qt = .int,
            .val = .zero,
            .node = try p.addNode(.{ .char_literal = .{ .qt = .int, .literal_tok = p.tok_i } }),
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

    const char_literal_qt = char_kind.charLiteralType(p.comp);
    // This is the type the literal will have if we're in a macro; macros always operate on intmax_t/uintmax_t values
    const macro_qt = if (char_literal_qt.signedness(p.comp) == .unsigned or
        (char_kind == .char and p.comp.getCharSignedness() == .unsigned))
        try p.comp.type_store.intmax.makeIntUnsigned(p.comp)
    else
        p.comp.type_store.intmax;

    var value = try Value.int(val, p.comp);
    // C99 6.4.4.4.10
    // > If an integer character constant contains a single character or escape sequence,
    // > its value is the one that results when an object with type char whose value is
    // > that of the single character or escape sequence is converted to type int.
    // This conversion only matters if `char` is signed and has a high-order bit of `1`
    if (char_kind == .char and !is_multichar and val > 0x7F and p.comp.getCharSignedness() == .signed) {
        _ = try value.intCast(.char, p.comp);
    }

    const res = Result{
        .qt = if (p.in_macro) macro_qt else char_literal_qt,
        .val = value,
        .node = try p.addNode(.{ .char_literal = .{ .qt = char_literal_qt, .literal_tok = p.tok_i } }),
    };
    if (!p.in_macro) try p.tree.value_map.put(p.gpa, res.node, res.val);
    return res;
}

fn parseFloat(p: *Parser, buf: []const u8, suffix: NumberSuffix, tok_i: TokenIndex) !Result {
    const qt: QualType = switch (suffix) {
        .None, .I => .double,
        .F, .IF => .float,
        .F16, .IF16 => .float16,
        .L, .IL => .long_double,
        .W, .IW => p.comp.float80Type().?,
        .Q, .IQ, .F128, .IF128 => .float128,
        else => unreachable,
    };
    const val = try Value.intern(p.comp, key: {
        try p.strings.ensureUnusedCapacity(buf.len);

        const strings_top = p.strings.items.len;
        defer p.strings.items.len = strings_top;
        for (buf) |c| {
            if (c != '\'') p.strings.appendAssumeCapacity(c);
        }

        const float = std.fmt.parseFloat(f128, p.strings.items[strings_top..]) catch unreachable;
        break :key switch (qt.bitSizeof(p.comp)) {
            16 => .{ .float = .{ .f16 = @floatCast(float) } },
            32 => .{ .float = .{ .f32 = @floatCast(float) } },
            64 => .{ .float = .{ .f64 = @floatCast(float) } },
            80 => .{ .float = .{ .f80 = @floatCast(float) } },
            128 => .{ .float = .{ .f128 = @floatCast(float) } },
            else => unreachable,
        };
    });
    var res = Result{
        .qt = qt,
        .node = try p.addNode(.{ .float_literal = .{ .qt = qt, .literal_tok = tok_i } }),
        .val = val,
    };
    if (suffix.isImaginary()) {
        try p.err(.gnu_imaginary_constant);
        res.qt = try qt.toComplex(p.comp);

        res.val = try Value.intern(p.comp, switch (res.qt.bitSizeof(p.comp)) {
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
        res.qt = .ulong_long;
        res.node = try p.addNode(.{ .int_literal = .{ .qt = res.qt, .literal_tok = tok_i } });
        try res.putValue(p);
        return res;
    }
    const interned_val = try Value.int(val, p.comp);
    if (suffix.isSignedInteger() and base == 10) {
        const max_int = try Value.maxInt(p.comp.type_store.intmax, p.comp);
        if (interned_val.compare(.gt, max_int, p.comp)) {
            try p.errTok(.implicitly_unsigned_literal, tok_i);
        }
    }

    const qts: []const QualType = if (suffix.signedness() == .unsigned)
        &.{ .uint, .ulong, .ulong_long }
    else if (base == 10)
        &.{ .int, .long, .long_long }
    else
        &.{ .int, .uint, .long, .ulong, .long_long, .ulong_long };

    const suffix_qt: QualType = switch (suffix) {
        .None, .I => .int,
        .U, .IU => .uint,
        .UL, .IUL => .ulong,
        .ULL, .IULL => .ulong_long,
        .L, .IL => .long,
        .LL, .ILL => .long_long,
        else => unreachable,
    };

    for (qts) |qt| {
        res.qt = qt;
        if (res.qt.intRankOrder(suffix_qt, p.comp).compare(.lt)) continue;
        const max_int = try Value.maxInt(res.qt, p.comp);
        if (interned_val.compare(.lte, max_int, p.comp)) break;
    } else {
        if (p.comp.langopts.emulate == .gcc) {
            if (target_util.hasInt128(p.comp.target)) {
                res.qt = .int128;
            } else {
                res.qt = .long_long;
            }
        } else {
            res.qt = .ulong_long;
        }
    }

    res.node = try p.addNode(.{ .int_literal = .{ .qt = res.qt, .literal_tok = tok_i } });
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
        res.qt = try res.qt.toComplex(p.comp);
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

    const int_qt = try p.comp.type_store.put(p.gpa, .{ .bit_int = .{
        .bits = bits_needed,
        .signedness = suffix.signedness(),
    } });
    const res: Result = .{
        .val = try Value.intern(p.comp, .{ .int = .{ .big_int = c } }),
        .qt = int_qt,
        .node = try p.addNode(.{ .int_literal = .{ .qt = int_qt, .literal_tok = tok_i } }),
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
        const res_sk = res.qt.scalarKind(p.comp);
        if (res_sk.isFloat() or !res_sk.isReal()) {
            try p.errTok(.float_literal_in_pp_expr, p.tok_i);
            return error.ParsingFailed;
        }
        res.qt = if (res.qt.signedness(p.comp) == .unsigned)
            try p.comp.type_store.intmax.makeIntUnsigned(p.comp)
        else
            p.comp.type_store.intmax;
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
    var controlling_qt = controlling.qt;
    if (controlling_qt.is(p.comp, .array)) {
        controlling_qt = try controlling_qt.decay(p.comp);
    }
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
        if (try p.typeName()) |qt| blk: {
            switch (qt.base(p.comp).type) {
                .array => try p.errTok(.generic_array_type, start),
                .func => try p.errTok(.generic_func_type, start),
                else => if (qt.isQualified()) {
                    try p.errTok(.generic_qual_type, start);
                },
            }

            const colon = try p.expectToken(.colon);
            var res = try p.expect(assignExpr);
            res.node = try p.addNode(.{
                .generic_association_expr = .{
                    .colon_tok = colon,
                    .association_qt = qt,
                    .expr = res.node,
                },
            });
            try p.list_buf.append(res.node);
            try p.param_buf.append(.{ .name = undefined, .qt = qt, .name_tok = start, .node = .null });

            if (qt.eql(controlling_qt, p.comp)) {
                if (chosen_tok == null) {
                    chosen = res;
                    chosen_tok = start;
                    break :blk;
                }
            }

            const previous_items = p.param_buf.items[0 .. p.param_buf.items.len - 1][param_buf_top..];
            for (previous_items) |prev_item| {
                if (prev_item.qt.eql(qt, p.comp)) {
                    try p.errStr(.generic_duplicate, start, try p.typeStr(qt));
                    try p.errStr(.generic_duplicate_here, prev_item.name_tok, try p.typeStr(qt));
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
            try p.errStr(.generic_no_match, controlling_tok, try p.typeStr(controlling_qt));
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
        .qt = chosen.qt,
        .val = chosen.val,
        .node = try p.addNode(.{
            .generic_expr = .{
                .generic_tok = kw_generic,
                .controlling = controlling.node,
                .chosen = chosen.node,
                .qt = chosen.qt,
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
    for (tree.root_decls.items[tree.root_decls.items.len - 3 ..], 0..) |node, i| {
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
