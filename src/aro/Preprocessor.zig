const std = @import("std");
const mem = std.mem;
const Allocator = mem.Allocator;
const assert = std.debug.assert;
const Compilation = @import("Compilation.zig");
const Error = Compilation.Error;
const Source = @import("Source.zig");
const Tokenizer = @import("Tokenizer.zig");
const RawToken = Tokenizer.Token;
const Parser = @import("Parser.zig");
const Diagnostics = @import("Diagnostics.zig");
const Tree = @import("Tree.zig");
const Token = Tree.Token;
const TokenWithExpansionLocs = Tree.TokenWithExpansionLocs;
const Attribute = @import("Attribute.zig");
const features = @import("features.zig");
const OldPreprocessor = @import("Preprocessor.zig");
const Treap = @import("Treap.zig");

const ParamMap = std.StringHashMapUnmanaged(PreprocessorToken);
const DefineMap = std.StringHashMapUnmanaged(Macro);

const TokenList = std.ArrayListUnmanaged(PreprocessorToken);
const max_include_depth = 200;

/// Errors that can be returned when expanding a macro.
/// error.UnknownPragma can occur within Preprocessor.pragma() but
/// it is handled there and doesn't escape that function
const MacroError = Error || error{StopPreprocessing};

const PreprocessingError = Error || error{PreprocessingFailed};

const SpecialMacroFn = fn (*Preprocessor, PreprocessorToken) Error!void;

fn Range(comptime T: type) type {
    return struct {
        const Self = @This();
        const Item = T;

        start: u32,
        end: u32,
        const empty: Self = .{ .start = 0, .end = 0 };

        fn len(self: Self) u32 {
            return self.end - self.start;
        }

        fn slice(self: Self, items: []const Item) []const Item {
            return items[self.start..self.end];
        }
    };
}

/// Each macro argument is a list of tokens (represented as a range of Preprocessor.macro_arg_tokens)
const MacroArg = Range(PreprocessorToken);

/// List of MacroArg's for a macro invocation (represented as a range of Preprocessor.macro_args)
const MacroArgList = Range(MacroArg);

const PreprocessorToken = TokenWithExpansionLocs;

const Macro = struct {
    /// Tokens constituting the macro body
    tokens: []const PreprocessorToken,

    /// Number of arguments for function-like macros
    nargs: usize,

    /// If the function type macro has variable number of arguments
    var_args: bool,

    /// Location of macro in the source
    loc: Source.Location,

    kind: Kind,

    const Kind = union(enum) {
        object,
        func,
        special: *const SpecialMacroFn,
    };

    fn eql(a: Macro, b: Macro, pp: *Preprocessor) bool {
        if ((a.kind == .object and b.kind != .object) or (a.kind == .func and b.kind != .func)) return false;
        if (!std.meta.eql(a.kind, b.kind)) return false;
        if (a.tokens.len != b.tokens.len) return false;
        for (a.tokens, b.tokens) |a_tok, b_tok| if (!tokEql(pp, a_tok, b_tok)) return false;

        if (a.kind == .func) {
            if (a.var_args != b.var_args) return false;
        }

        return true;
    }

    fn tokEql(pp: *Preprocessor, a: PreprocessorToken, b: PreprocessorToken) bool {
        return mem.eql(u8, pp.tokSlice(a), pp.tokSlice(b));
    }
};

const Preprocessor = @This();

const ExpansionEntry = struct {
    idx: Tree.TokenIndex,
    locs: [*]Source.Location,
};

const TokenState = struct {
    tokens_len: usize,
    expansion_entries_len: usize,
};

comp: *Compilation,
gpa: mem.Allocator,
arena: std.heap.ArenaAllocator,

tokens: std.MultiArrayList(Token) = .{},
/// Do not directly mutate this; must be kept in sync with `tokens`
expansion_entries: std.MultiArrayList(ExpansionEntry) = .{},

/// Map from Source.Id to macro name in the `#ifndef` condition which guards the source, if any
include_guards: std.AutoHashMapUnmanaged(Source.Id, []const u8) = .{},

char_buf: std.ArrayListUnmanaged(u8) = .{},

/// Dump current state to stderr.
verbose: bool = false,
preserve_whitespace: bool = false,

/// linemarker tokens. Must be .none unless in -E mode (parser does not handle linemarkers)
linemarkers: Linemarkers = .none,

tokenizers: std.ArrayListUnmanaged(Tokenizer) = .{},

expansion_bufs: std.ArrayListUnmanaged(TokenList) = .{},

defines: DefineMap = .{},

generated_line: u32 = 1,

counter: u32 = 0,

if_level: u8 = 0,

preprocess_count: u32 = 0,

poisoned_identifiers: std.StringHashMap(void),

if_kind: std.PackedIntArray(u2, 256) = blk: {
    @setEvalBranchQuota(2000);
    break :blk std.PackedIntArray(u2, 256).initAllTo(0);
},

guard_stack: std.ArrayListUnmanaged(?[]const u8) = .{},

macro_arg_tokens: std.ArrayListUnmanaged(MacroArg.Item) = .{},
macro_args: std.ArrayListUnmanaged(MacroArgList.Item) = .{},

safe_strings: std.StringHashMapUnmanaged(void) = .{},

treap: Treap,

pub const parse = Parser.parse;

pub const Linemarkers = enum {
    /// No linemarker tokens. Required setting if parser will run
    none,
    /// #line <num> "filename"
    line_directives,
    /// # <num> "filename" flags
    numeric_directives,
};

pub fn init(comp: *Compilation) Preprocessor {
    const pp = Preprocessor{
        .comp = comp,
        .gpa = comp.gpa,
        .arena = std.heap.ArenaAllocator.init(comp.gpa),
        .poisoned_identifiers = std.StringHashMap(void).init(comp.gpa),
        .treap = Treap.init(comp.gpa),
    };
    comp.pragmaEvent(.before_preprocess);
    return pp;
}

fn addBuiltinMacro(pp: *Preprocessor, name: []const u8, func: *const SpecialMacroFn) !void {
    try pp.defines.putNoClobber(pp.gpa, name, .{
        .tokens = &.{},
        .var_args = false,
        .loc = .{ .id = .generated },
        .kind = .{ .special = func },
        .nargs = 0,
    });
}

fn handleLineMacro(pp: *Preprocessor, tok: PreprocessorToken) Error!void {
    const start = pp.comp.generated_buf.items.len;
    const source = pp.comp.getSource(tok.loc.id);
    const w = pp.comp.generated_buf.writer(pp.gpa);
    try w.print("{d}\n", .{source.physicalLine(tok.loc)});
    const pasted_tok = try pp.makeGeneratedToken(start, .pp_num, tok);
    return pp.ungetToken(pasted_tok);
}

fn handleFileMacro(pp: *Preprocessor, tok: PreprocessorToken) Error!void {
    const start = pp.comp.generated_buf.items.len;
    const source = pp.comp.getSource(tok.loc.id);
    const w = pp.comp.generated_buf.writer(pp.gpa);
    try w.print("\"{s}\"\n", .{source.path});
    const pasted_tok = try pp.makeGeneratedToken(start, .string_literal, tok);
    return pp.ungetToken(pasted_tok);
}

fn handleCounterMacro(pp: *Preprocessor, tok: PreprocessorToken) Error!void {
    defer pp.counter += 1;
    const start = pp.comp.generated_buf.items.len;
    const w = pp.comp.generated_buf.writer(pp.gpa);
    try w.print("{d}\n", .{pp.counter});
    const pasted_tok = try pp.makeGeneratedToken(start, .pp_num, tok);
    return pp.ungetToken(pasted_tok);
}

fn makeGeneratedToken(pp: *Preprocessor, start: usize, id: Token.Id, source: PreprocessorToken) !PreprocessorToken {
    const pasted_token = PreprocessorToken{ .id = id, .flags = source.flags, .loc = .{
        .id = .generated,
        .byte_offset = @intCast(start),
        .line = pp.generated_line,
    } };
    pp.generated_line += 1;
    // try pasted_token.addExpansionLocation(pp.gpa, &.{source.loc});
    // try pasted_token.addExpansionLocation(pp.gpa, source.expansionSlice());
    return pasted_token;
}

fn errStr(pp: *Preprocessor, tok: PreprocessorToken, tag: Diagnostics.Tag, str: []const u8) !void {
    try pp.comp.addDiagnostic(.{
        .tag = tag,
        .loc = tok.loc,
        .extra = .{ .str = str },
    }, &.{}); // todo expansion slice
}

fn errTok(pp: *Preprocessor, tok: PreprocessorToken, tag: Diagnostics.Tag) !void {
    try pp.comp.addDiagnostic(.{
        .tag = tag,
        .loc = tok.loc,
        .extra = .{ .none = {} },
    }, &.{}); // todo expansion slice
}

fn expectClosing(pp: *Preprocessor, opening: PreprocessorToken, id: Token.Id) !void {
    // todo: fix expect
    const item = try pp.expect(id, .closing_paren);
    if (item.id != id) {
        try pp.errTok(opening, .to_match_paren);
    }
}

fn tokFromBool(b: bool) PreprocessorToken {
    return if (b) PreprocessorToken.one else PreprocessorToken.zero;
}

fn handleHasAttribute(pp: *Preprocessor, ident_tok: PreprocessorToken) Error!void {
    const l_paren = try pp.expectLParen(ident_tok);
    const attr_name = try pp.readToken();
    try pp.expectClosing(l_paren, .r_paren);

    const has_attr = Attribute.fromString(.gnu, null, pp.tokSlice(attr_name)) != null;
    return pp.ungetToken(tokFromBool(has_attr));
}

fn handleHasCAttribute(pp: *Preprocessor, ident_tok: PreprocessorToken) Error!void {
    const l_paren = try pp.expectLParen(ident_tok);
    var r: TokenList = .{};
    defer r.deinit(pp.gpa);

    var tok: PreprocessorToken = undefined;
    while (true) {
        tok = try pp.readToken();
        if (tok.id == .comment) continue;
        if (tok.id.isDirectiveEnd() or tok.id == .r_paren) break;
        try r.append(pp.gpa, tok);
    }
    try pp.expectClosing(l_paren, .r_paren);
}

fn handleHasDeclSpecAttribute(pp: *Preprocessor, ident_tok: PreprocessorToken) Error!void {
    const l_paren = try pp.expectLParen(ident_tok);
    const attr_name = try pp.readToken();
    try pp.expectClosing(l_paren, .r_paren);

    const ident_str = pp.tokSlice(attr_name);
    const has_attr = if (pp.comp.langopts.declspec_attrs) Attribute.fromString(.declspec, null, ident_str) != null else false;
    return pp.ungetToken(tokFromBool(has_attr));
}

fn handleHasFeature(pp: *Preprocessor, ident_tok: PreprocessorToken) Error!void {
    const l_paren = try pp.expectLParen(ident_tok);
    const attr_name = try pp.readToken();
    try pp.expectClosing(l_paren, .r_paren);

    const ident_str = pp.tokSlice(attr_name);
    const has_feature = features.hasFeature(pp.comp, ident_str);
    return pp.ungetToken(tokFromBool(has_feature));
}

fn handleHasExtension(pp: *Preprocessor, ident_tok: PreprocessorToken) Error!void {
    const l_paren = try pp.expectLParen(ident_tok);
    const attr_name = try pp.readToken();
    try pp.expectClosing(l_paren, .r_paren);

    const ident_str = pp.tokSlice(attr_name);
    const has_extension = features.hasExtension(pp.comp, ident_str);
    return pp.ungetToken(tokFromBool(has_extension));
}

fn handleHasBuiltin(pp: *Preprocessor, ident_tok: PreprocessorToken) Error!void {
    const l_paren = try pp.expectLParen(ident_tok);
    const attr_name = try pp.readToken();
    try pp.expectClosing(l_paren, .r_paren);

    const ident_str = pp.tokSlice(attr_name);
    const has_builtin = pp.comp.hasBuiltin(ident_str);
    return pp.ungetToken(tokFromBool(has_builtin));
}

fn handleHasWarning(pp: *Preprocessor, macro_tok: PreprocessorToken) Error!void {
    const l_paren = try pp.expectLParen(macro_tok);
    const start = pp.char_buf.items.len;
    defer pp.char_buf.items.len = start;

    while (true) {
        const tok = try pp.readExpandNewline();
        switch (tok.id) {
            .nl, .eof => {
                try pp.errTok(tok, .unterminated_macro_arg_list);
                return pp.ungetToken(PreprocessorToken.zero);
            },
            .r_paren => break,
            .string_literal => {
                const string = pp.tokSlice(tok);
                try pp.char_buf.appendSlice(pp.gpa, string[1 .. string.len - 1]);
            },
            else => {
                pp.skipToNl();
                try pp.errTok(tok, .missing_paren_param_list);
                try pp.errTok(l_paren, .to_match_paren);
                return pp.ungetToken(PreprocessorToken.zero);
            },
        }
    }
    const actual_param = pp.char_buf.items[start..];
    if (actual_param.len == 0) {
        try pp.comp.addDiagnostic(.{
            .tag = .expected_arguments,
            .loc = macro_tok.loc,
            .extra = .{ .arguments = .{ .expected = 1, .actual = 0 } },
        }, &.{}); // todo expansion slice
        return pp.ungetToken(PreprocessorToken.zero);
    }
    if (!mem.startsWith(u8, actual_param, "-W")) {
        try pp.errStr(l_paren, .malformed_warning_check, "__has_warning");
        return pp.ungetToken(PreprocessorToken.zero);
    }
    const warning_name = actual_param[2..];
    const exists = Diagnostics.warningExists(warning_name);
    return pp.ungetToken(tokFromBool(exists));
}

fn handleHasInclude(pp: *Preprocessor, macro_tok: PreprocessorToken) Error!void {
    return pp.handleHasIncludeExtra(macro_tok, .first);
}

fn handleHasIncludeNext(pp: *Preprocessor, macro_tok: PreprocessorToken) Error!void {
    return pp.handleHasIncludeExtra(macro_tok, .next);
}

fn handleHasIncludeExtra(pp: *Preprocessor, macro_tok: PreprocessorToken, which: Compilation.WhichInclude) Error!void {
    const l_paren = pp.getToken();
    if (l_paren.id != .l_paren) {
        pp.skipToNl();
        return;
    }

    var is_std: bool = undefined;
    const include_str = pp.readHeaderName(&is_std) catch |err| switch (err) {
        error.InvalidInclude => return pp.ungetToken(PreprocessorToken.zero),
        else => |e| return e,
    };
    try pp.expectClosing(l_paren, .r_paren);

    const filename = include_str[1 .. include_str.len - 1];
    const include_type: Compilation.IncludeType = switch (include_str[0]) {
        '"' => .quotes,
        '<' => .angle_brackets,
        else => unreachable,
    };

    if (which == .first or pp.includeDepth() == 0) {
        if (which == .next) {
            try pp.comp.addDiagnostic(.{
                .tag = .include_next_outside_header,
                .loc = macro_tok.loc,
            }, &.{});
        }
        const has = try pp.comp.hasInclude(filename, macro_tok.loc.id, include_type, .first);
        return pp.ungetToken(tokFromBool(has));
    }
    const has = try pp.comp.hasInclude(filename, macro_tok.loc.id, include_type, .next);
    return pp.ungetToken(tokFromBool(has));
}

fn includeDepth(pp: *Preprocessor) usize {
    return pp.tokenizers.items.len - 1;
}

fn hasEmbedValue(contents_arg: ?[]const u8) []const u8 {
    const contents = contents_arg orelse return "0\n";
    if (contents.len == 0) return "2\n";
    return "1\n";
}

/// TODO: handle limit/prefix/suffix/etc
fn handleHasEmbed(pp: *Preprocessor, macro_tok: PreprocessorToken) Error!void {
    const l_paren = pp.getToken();
    if (l_paren.id != .l_paren) {
        pp.skipToNl();
        return;
    }

    var is_std: bool = undefined;
    const include_str = pp.readHeaderName(&is_std) catch |err| switch (err) {
        error.InvalidInclude => return,
        else => |e| return e,
    };
    try pp.expectClosing(l_paren, .r_paren);

    const filename = include_str[1 .. include_str.len - 1];
    const include_type: Compilation.IncludeType = switch (include_str[0]) {
        '"' => .quotes,
        '<' => .angle_brackets,
        else => unreachable,
    };

    const contents = try pp.comp.findEmbed(filename, macro_tok.loc.id, include_type, 1);
    const result = hasEmbedValue(contents);
    const start = pp.comp.generated_buf.items.len;
    try pp.comp.generated_buf.appendSlice(pp.comp.gpa, result);
    const pasted_tok = try pp.makeGeneratedToken(start, .pp_num, macro_tok);
    return pp.ungetToken(pasted_tok);
}

// Skip until newline, ignore other tokens.
fn skipToNl(pp: *Preprocessor) void {
    while (true) {
        const tok = pp.getToken();
        if (tok.id.isDirectiveEnd()) return;
    }
}

fn readOneIdentifierArgument(pp: *Preprocessor, macro_tok: PreprocessorToken) !?PreprocessorToken {
    const l_paren = try pp.expect(.l_paren, .missing_lparen_after_builtin);
    _ = l_paren;
    var invalid: ?PreprocessorToken = null;
    var identifier: ?PreprocessorToken = null;
    while (true) {
        var tok = pp.getToken();
        tok.id.simplifyMacroKeywordExtra(true);

        switch (tok.id) {
            .r_paren, .eof => break,
            else => {
                if (identifier) |_| invalid = tok else identifier = tok;
            },
        }
    }
    if (invalid) |some| {
        try pp.comp.addDiagnostic(.{
            .tag = .missing_tok_builtin,
            .loc = some.loc,
            .extra = .{ .tok_id_expected = .r_paren },
        }, &.{}); // TODO: expansion slice
        return null;
    }
    if (identifier) |ident| {
        if (ident.id == .identifier or ident.id == .extended_identifier) return ident;
    } else {
        const extra: Diagnostics.Message.Extra = .{ .arguments = .{ .expected = 1, .actual = 0 } };
        try pp.comp.addDiagnostic(.{ .tag = .expected_arguments, .loc = macro_tok.loc, .extra = extra }, &.{});
    }
    return null;
}

fn handleIsIdentifier(pp: *Preprocessor, macro_tok: PreprocessorToken) Error!void {
    if (try pp.readOneIdentifierArgument(macro_tok)) |_| {
        return pp.ungetToken(PreprocessorToken.one);
    } else {
        return pp.ungetToken(PreprocessorToken.zero);
    }
}

fn handlePragmaOperator(pp: *Preprocessor, macro_tok: PreprocessorToken) Error!void {
    _ = pp;
    _ = macro_tok;
    // TODO
}

pub fn addBuiltinMacros(pp: *Preprocessor) !void {
    try pp.addBuiltinMacro("__has_attribute", handleHasAttribute);
    try pp.addBuiltinMacro("__has_c_attribute", handleHasCAttribute);
    try pp.addBuiltinMacro("__has_declspec_attribute", handleHasDeclSpecAttribute);
    try pp.addBuiltinMacro("__has_feature", handleHasFeature);
    try pp.addBuiltinMacro("__has_extension", handleHasExtension);
    try pp.addBuiltinMacro("__has_builtin", handleHasBuiltin);
    try pp.addBuiltinMacro("__has_warning", handleHasWarning);
    try pp.addBuiltinMacro("__has_include", handleHasInclude);
    try pp.addBuiltinMacro("__has_include_next", handleHasIncludeNext);
    try pp.addBuiltinMacro("__has_embed", handleHasEmbed);

    try pp.addBuiltinMacro("__is_identifier", handleIsIdentifier);

    try pp.addBuiltinMacro("__FILE__", handleFileMacro);
    try pp.addBuiltinMacro("__LINE__", handleLineMacro);
    try pp.addBuiltinMacro("__COUNTER__", handleCounterMacro);
    try pp.addBuiltinMacro("_Pragma", handlePragmaOperator);
}

/// Initialize Preprocessor with builtin macros.
pub fn initDefault(comp: *Compilation) !Preprocessor {
    var pp = init(comp);
    errdefer pp.deinit();
    try pp.addBuiltinMacros();
    return pp;
}

pub fn deinit(pp: *Preprocessor) void {
    pp.arena.deinit();
    pp.include_guards.deinit(pp.gpa);
    pp.tokens.deinit(pp.gpa);
    pp.tokenizers.deinit(pp.gpa);
    for (pp.expansion_bufs.items) |*toklist| {
        toklist.deinit(pp.gpa);
    }
    pp.expansion_bufs.deinit(pp.gpa);
    pp.defines.deinit(pp.gpa);
    pp.char_buf.deinit(pp.gpa);
    for (pp.expansion_entries.items(.locs)) |locs| PreprocessorToken.free(locs, pp.gpa);
    pp.expansion_entries.deinit(pp.gpa);
    pp.guard_stack.deinit(pp.gpa);
    pp.macro_arg_tokens.deinit(pp.gpa);
    pp.macro_args.deinit(pp.gpa);
    pp.safe_strings.deinit(pp.gpa);
    pp.treap.deinit();
    pp.poisoned_identifiers.deinit();
}

/// Preprocess a compilation unit of sources into a parsable list of tokens.
pub fn preprocessSources(pp: *Preprocessor, sources: []const Source) Error!void {
    assert(sources.len > 1);
    const first = sources[0];

    for (sources[1..]) |header| {
        _ = try pp.preprocess(header);
    }
    const eof = try pp.preprocess(first);
    try pp.addToken(eof);
}

fn propagateSpace(pp: *Preprocessor, tokens: []PreprocessorToken, template: PreprocessorToken) void {
    if (tokens.len > 0) {
        tokens[0].flags = template.flags;
    } else {
        pp.injectSpace();
    }
}

fn ungetAll(pp: *Preprocessor, tokens: []const PreprocessorToken) !void {
    if (tokens.len == 0) return;
    const start = pp.expansion_bufs.items[pp.expansion_bufs.items.len - 1].items.len;
    try pp.expansion_bufs.items[pp.expansion_bufs.items.len - 1].appendSlice(pp.gpa, tokens);
    std.mem.reverse(PreprocessorToken, pp.expansion_bufs.items[pp.expansion_bufs.items.len - 1].items[start..]);
}

fn addHideSet(pp: *Preprocessor, toks: []PreprocessorToken, hideset: Treap.Node) !void {
    for (toks) |*tok| {
        switch (tok.id) {
            // non-identifiers are not expanded, so we don't need to track their hidesets.
            // Track r_paren hideset since it is used for computing the hideset of function-like macro expansions
            .identifier, .extended_identifier, .r_paren => {
                tok.hideset = try pp.treap.@"union"(tok.hideset, hideset);
            },
            else => {},
        }
    }
}

fn stringize(pp: *Preprocessor, tmpl: PreprocessorToken, args_range: MacroArg) !PreprocessorToken {
    const char_buf_top = pp.char_buf.items.len;
    defer pp.char_buf.items.len = char_buf_top;

    const start = pp.comp.generated_buf.items.len;
    try pp.char_buf.append(pp.gpa, '"');
    const args = args_range.slice(pp.macro_arg_tokens.items);
    for (args) |tok| {
        if (tok.flags.space and pp.char_buf.items.len - 1 > char_buf_top) {
            try pp.char_buf.append(pp.gpa, ' ');
        }
        // backslashes not inside strings are not escaped
        const is_str = switch (tok.id) {
            .string_literal,
            .string_literal_utf_16,
            .string_literal_utf_8,
            .string_literal_utf_32,
            .string_literal_wide,
            .char_literal,
            .char_literal_utf_16,
            .char_literal_utf_32,
            .char_literal_wide,
            => true,
            else => false,
        };

        for (pp.tokSlice(tok)) |c| {
            if (c == '"')
                try pp.char_buf.appendSlice(pp.gpa, "\\\"")
            else if (c == '\\' and is_str)
                try pp.char_buf.appendSlice(pp.gpa, "\\\\")
            else
                try pp.char_buf.append(pp.gpa, c);
        }
    }
    try pp.char_buf.ensureUnusedCapacity(pp.gpa, 2);
    if (pp.char_buf.items[pp.char_buf.items.len - 1] != '\\') {
        pp.char_buf.appendSliceAssumeCapacity("\"\n");
    } else {
        pp.char_buf.appendAssumeCapacity('"');
        var tokenizer: Tokenizer = .{
            .buf = pp.char_buf.items,
            .index = 0,
            .source = .generated,
            .langopts = pp.comp.langopts,
            .line = 0,
        };
        const item = tokenizer.next();
        if (item.id == .unterminated_string_literal) {
            const tok = args[args.len - 1];
            try pp.comp.addDiagnostic(.{
                .tag = .invalid_pp_stringify_escape,
                .loc = tok.loc,
            }, tok.expansionSlice());
            pp.char_buf.items.len -= 2; // erase unpaired backslash and appended end quote
            pp.char_buf.appendAssumeCapacity('"');
        }
        pp.char_buf.appendAssumeCapacity('\n');
    }

    try pp.comp.generated_buf.appendSlice(pp.gpa, pp.char_buf.items[char_buf_top..]);

    var tok = tmpl;
    tok.id = .string_literal;
    tok.loc = .{
        .id = .generated,
        .byte_offset = @intCast(start),
        .line = pp.generated_line,
    };
    pp.generated_line += 1;
    return tok;
}

fn subst(pp: *Preprocessor, macro: *const Macro, macro_tok: PreprocessorToken, args: MacroArgList, hideset_arg: Treap.Node) ![]PreprocessorToken {
    _ = macro_tok;
    var hideset = hideset_arg;
    var r: TokenList = .{};
    defer r.deinit(pp.gpa);
    var i: usize = 0;
    while (i < macro.tokens.len) : (i += 1) {
        const t0 = macro.tokens[i];
        const t1: ?PreprocessorToken = if (i == macro.tokens.len - 1) null else macro.tokens[i + 1];

        const t0_param = t0.id == .macro_param;
        const t1_param = if (t1) |tok| tok.id == .macro_param else false;

        if (t0.id == .hash and t1_param) {
            const arg = args.slice(pp.macro_args.items)[t1.?.argPosition()];
            const stringized = try pp.stringize(t0, arg);
            try r.append(pp.gpa, stringized);
            i += 1;
            continue;
        }
        if (t0.id == .hash_hash and t1_param) {
            const arg = args.slice(pp.macro_args.items)[t1.?.argPosition()];
            if (t1.?.isVarArg() and r.items.len > 0 and r.items[r.items.len - 1].id == .comma) {
                if (arg.len() == 0) {
                    _ = r.pop();
                } else {
                    try r.appendSlice(pp.gpa, arg.slice(pp.macro_arg_tokens.items));
                }
            } else if (arg.len() > 0) {
                try pp.pasteAndPush(&r, arg.slice(pp.macro_arg_tokens.items)[0]);
                try r.appendSlice(pp.gpa, arg.slice(pp.macro_arg_tokens.items)[1..]);
            }
            i += 1;
            continue;
        }
        if (t0.id == .hash_hash and t1 != null) {
            hideset = t1.?.hideset;
            try pp.pasteAndPush(&r, t1.?);
            i += 1;
            continue;
        }
        if (t0_param and t1 != null and t1.?.id == .hash_hash) {
            hideset = t1.?.hideset;
            const arg = args.slice(pp.macro_args.items)[t0.argPosition()];
            if (arg.len() == 0) {
                i += 1;
            } else {
                try r.appendSlice(pp.gpa, arg.slice(pp.macro_arg_tokens.items));
            }
            continue;
        }
        if (t0_param) {
            const arg = args.slice(pp.macro_args.items)[t0.argPosition()];
            const expanded = try pp.expandAll(arg.slice(pp.macro_arg_tokens.items), t0);
            defer pp.gpa.free(expanded);
            try r.appendSlice(pp.gpa, expanded);
            continue;
        }
        try r.append(pp.gpa, t0);
    }
    try pp.addHideSet(r.items, hideset);
    return r.toOwnedSlice(pp.gpa);
}

fn pasteTokens(pp: *Preprocessor, lhs: PreprocessorToken, rhs: PreprocessorToken) !PreprocessorToken {
    const start = pp.comp.generated_buf.items.len;
    const end = start + pp.tokSlice(lhs).len + pp.tokSlice(rhs).len;
    try pp.comp.generated_buf.ensureTotalCapacity(pp.gpa, end + 1); // +1 for a newline

    // We cannot use the same slices here since they might be invalidated by `ensureCapacity`
    pp.comp.generated_buf.appendSliceAssumeCapacity(pp.tokSlice(lhs));
    pp.comp.generated_buf.appendSliceAssumeCapacity(pp.tokSlice(rhs));
    pp.comp.generated_buf.appendAssumeCapacity('\n');

    // Try to tokenize the result.
    var tmp_tokenizer = Tokenizer{
        .buf = pp.comp.generated_buf.items,
        .langopts = pp.comp.langopts,
        .index = @intCast(start),
        .source = .generated,
    };
    const pasted_token = tmp_tokenizer.nextNoWSComments();
    const next_tok = tmp_tokenizer.next();
    if (next_tok.id != .nl) {
        try pp.errStr(
            lhs,
            .pasting_formed_invalid,
            try pp.comp.diagnostics.arena.allocator().dupe(u8, pp.comp.generated_buf.items[start..end]),
        );
    }
    return pp.makeGeneratedToken(start, pasted_token.id, lhs);
}

/// Paste `tok` onto the last token in `tokens`
fn pasteAndPush(pp: *Preprocessor, tokens: *TokenList, tok: PreprocessorToken) !void {
    const last = tokens.pop();
    const pasted = try pp.pasteTokens(last, tok);
    return tokens.append(pp.gpa, pasted);
}

fn tokenBufferStashReverse(pp: *Preprocessor, tokens: []const PreprocessorToken) !void {
    try pp.expansion_bufs.append(pp.gpa, .{});
    try pp.expansion_bufs.items[pp.expansion_bufs.items.len - 1].appendSlice(pp.gpa, tokens);
    std.mem.reverse(PreprocessorToken, pp.expansion_bufs.items[pp.expansion_bufs.items.len - 1].items);
}

fn tokenBufferUnstash(pp: *Preprocessor) void {
    var buf = pp.expansion_bufs.pop();
    buf.deinit(pp.gpa);
}

fn expandAll(pp: *Preprocessor, tokens: []const PreprocessorToken, tmpl: PreprocessorToken) ![]const PreprocessorToken {
    try pp.tokenBufferStashReverse(tokens);
    defer pp.tokenBufferUnstash();
    var r: TokenList = .{};
    defer r.deinit(pp.gpa);
    while (true) {
        const tok = try pp.readExpand();
        if (tok.id == .eof) break;
        try r.append(pp.gpa, tok);
    }
    pp.propagateSpace(r.items, tmpl);
    return r.toOwnedSlice(pp.gpa);
}

fn peekToken(pp: *Preprocessor) !PreprocessorToken {
    const tok = try pp.readToken();
    try pp.ungetToken(tok);
    return tok;
}

/// Return a string with the same contents as `name` and whose lifetime is the same as the preprocessor's lifetime
/// If `tok` is not from the generated source, this is just `name`.
/// If `tok` is from the generated source, pointers are invalidated when the underlying ArrayList is resized. Therefore,
/// duplicate the string and store it (so we aren't repeatedly copying the same string)
fn getSafeString(pp: *Preprocessor, tok: PreprocessorToken, name: []const u8) ![]const u8 {
    if (tok.loc.id != .generated) return name;
    const gop = try pp.safe_strings.getOrPut(pp.gpa, name);
    if (!gop.found_existing) {
        const copy = try pp.arena.allocator().dupe(u8, name);
        gop.key_ptr.* = copy;
    }
    return gop.key_ptr.*;
}

fn injectSpace(pp: *Preprocessor) void {
    var i = pp.expansion_bufs.items.len;
    while (i > 0) : (i -= 1) {
        var j = pp.expansion_bufs.items[i - 1].items.len;
        while (j > 0) : (j -= 1) {
            pp.expansion_bufs.items[i - 1].items[j - 1].flags.space = true;
            return;
        }
    }
}

fn readExpandNewline(pp: *Preprocessor) Error!PreprocessorToken {
    const tok = pp.getToken();
    if (!tok.id.isMacroIdentifier()) return tok;
    const name = pp.tokSlice(tok);
    const macro = pp.defines.getPtr(name) orelse return tok;

    const macro_hideset = tok.hideset;
    if (pp.treap.contains(macro_hideset, name)) return tok;

    switch (macro.kind) {
        .object => {
            const safe_name = try pp.getSafeString(tok, name);
            const new_hideset = try pp.treap.addNodeTo(tok.hideset, safe_name);

            const tokens = try pp.subst(macro, tok, MacroArgList.empty, new_hideset);
            defer pp.gpa.free(tokens);
            pp.propagateSpace(tokens, tok);
            try pp.ungetAll(tokens);
            return pp.readExpand();
        },
        .func => {
            if (!try pp.next(.l_paren)) return tok;
            const arg_tokens_start = pp.macro_arg_tokens.items.len;
            defer pp.macro_arg_tokens.items.len = arg_tokens_start;
            const macro_args_start = pp.macro_args.items.len;
            defer pp.macro_args.items.len = macro_args_start;

            const args = pp.readArgs(tok, macro) catch |err| switch (err) {
                error.IncorrectArgumentCount => return PreprocessorToken.zero,
                error.UnterminatedMacroArgumentList => {
                    try pp.errTok(tok, .unterminated_macro_arg_list);
                    return PreprocessorToken.zero;
                },
                else => |e| return e,
            };
            const r_paren = pp.getToken();
            std.debug.assert(r_paren.id == .r_paren);
            const safe_name = try pp.getSafeString(tok, name);

            const intersection = try pp.treap.intersection(macro_hideset, r_paren.hideset);
            const hideset = try pp.treap.addNodeTo(intersection, safe_name);
            const tokens = try pp.subst(macro, tok, args, hideset);
            defer pp.gpa.free(tokens);
            pp.propagateSpace(tokens, tok);
            try pp.ungetAll(tokens);
            return pp.readExpand();
        },
        .special => |func| {
            try func(pp, tok);
            return pp.readExpand();
        },
    }
}

fn readMacroArg(pp: *Preprocessor, end: *bool, readall: bool) !MacroArg {
    var level: i32 = 0;
    const start: u32 = @intCast(pp.macro_arg_tokens.items.len);
    while (true) {
        var tok = pp.getToken();
        if (tok.id == .eof) {
            return error.UnterminatedMacroArgumentList;
        }
        if (tok.id == .nl) continue;
        if (tok.flags.is_bol and tok.id == .hash) {
            try pp.readDirective();
            continue;
        }
        if (level == 0 and tok.id == .r_paren) {
            try pp.ungetToken(tok);
            end.* = true;
            break;
        }
        if (level == 0 and tok.id == .comma and !readall) {
            break;
        }
        if (tok.id == .l_paren) {
            level += 1;
        }
        if (tok.id == .r_paren) {
            level -= 1;
        }
        if (tok.flags.is_bol) {
            tok.flags = .{ .is_bol = false, .space = true };
        }
        try pp.macro_arg_tokens.append(pp.gpa, tok);
    }
    return .{ .start = start, .end = @intCast(pp.macro_arg_tokens.items.len) };
}

fn doReadArgs(pp: *Preprocessor, macro: *const Macro) !MacroArgList {
    const start: u32 = @intCast(pp.macro_args.items.len);
    var end = false;
    while (!end) {
        const in_ellipsis = macro.var_args and (pp.macro_args.items.len - start) + 1 == macro.nargs;
        const arg_range = try pp.readMacroArg(&end, in_ellipsis);
        try pp.macro_args.append(pp.gpa, arg_range);
    }
    if (macro.var_args and (pp.macro_args.items.len - start) + 1 == macro.nargs) {
        try pp.macro_args.append(pp.gpa, MacroArg.empty);
    }
    return .{ .start = start, .end = @intCast(pp.macro_args.items.len) };
}

fn readArgs(pp: *Preprocessor, ident: PreprocessorToken, macro: *const Macro) !MacroArgList {
    if (macro.nargs == 0 and (try pp.peekToken()).id == .r_paren) {
        return MacroArgList.empty;
    }
    const args = try pp.doReadArgs(macro);
    if (args.len() != macro.nargs) {
        const extra = Diagnostics.Message.Extra{
            .arguments = .{ .expected = @intCast(macro.nargs), .actual = @intCast(args.len()) },
        };
        try pp.comp.addDiagnostic(
            .{ .tag = .expected_arguments, .loc = ident.loc, .extra = extra },
            &.{}, // TODO: expansion slice
        );
        return error.IncorrectArgumentCount;
    }
    return args;
}

fn readExpand(pp: *Preprocessor) Error!PreprocessorToken {
    while (true) {
        const tok = try pp.readExpandNewline();
        if (tok.id != .nl) return tok;
    }
}

/// # number "file" flags
/// TODO: validate that the pp_num token is solely digits
/// if not, emit `GNU line marker directive requires a simple digit sequence`
fn readLinemarker(pp: *Preprocessor) !void {
    const name = pp.getToken();
    if (name.id.isDirectiveEnd()) return;
    if (name.id != .string_literal) try pp.errTok(name, .line_invalid_filename);

    const flag_1 = pp.getToken();
    if (flag_1.id.isDirectiveEnd()) return;
    const flag_2 = pp.getToken();
    if (flag_2.id.isDirectiveEnd()) return;
    const flag_3 = pp.getToken();
    if (flag_3.id.isDirectiveEnd()) return;
    const flag_4 = pp.getToken();
    if (flag_4.id.isDirectiveEnd()) return;
    try pp.expectNewline();
}

fn readIdent(pp: *Preprocessor) !?PreprocessorToken {
    const tok = pp.getToken();
    if (!tok.id.isMacroIdentifier()) {
        try pp.errTok(tok, .macro_name_must_be_identifier);
        return null;
    }
    return tok;
}

fn ungetToken(pp: *Preprocessor, tok: PreprocessorToken) !void {
    if (tok.id == .eof) return;
    if (pp.isBufferEmpty()) {
        try pp.expansion_bufs.append(pp.gpa, .{});
    }
    try pp.expansion_bufs.items[pp.expansion_bufs.items.len - 1].append(pp.gpa, tok);
}

fn hashHashCheck(pp: *Preprocessor, toks: []const PreprocessorToken) !void {
    if (toks.len == 0) return;
    if (toks[0].id == .hash_hash) {
        return pp.errTok(toks[0], .hash_hash_at_start);
    }
    if (toks[toks.len - 1].id == .hash_hash) {
        return pp.errTok(toks[toks.len - 1], .hash_hash_at_end);
    }
}

fn readObjMacro(pp: *Preprocessor, name: PreprocessorToken) !void {
    var body: TokenList = .{};
    errdefer body.deinit(pp.gpa);

    while (true) {
        const tok = pp.getToken();
        if (tok.id.isDirectiveEnd()) break;
        switch (tok.id) {
            .unterminated_comment => try pp.errTok(tok, .unterminated_comment),
            else => try body.append(pp.gpa, tok),
        }
    }
    try pp.hashHashCheck(body.items);
    const macro: Macro = .{
        .tokens = body.items,
        .var_args = false,
        .loc = name.loc,
        .kind = .object,
        .nargs = undefined,
    };
    try pp.defineMacro(name, macro);
}

/// Defines a new macro and warns if it is a duplicate
fn defineMacro(pp: *Preprocessor, name_tok: PreprocessorToken, macro: Macro) Error!void {
    const name_str = pp.tokSlice(name_tok);
    const gop = try pp.defines.getOrPut(pp.gpa, name_str);
    if (gop.found_existing and !gop.value_ptr.eql(macro, pp)) {
        const tag: Diagnostics.Tag = if (gop.value_ptr.kind == .special) .builtin_macro_redefined else .macro_redefined;
        const start = pp.comp.diagnostics.list.items.len;
        try pp.comp.addDiagnostic(.{
            .tag = tag,
            .loc = name_tok.loc,
            .extra = .{ .str = name_str },
        }, &.{});
        if (gop.value_ptr.kind != .special and pp.comp.diagnostics.list.items.len != start) {
            try pp.comp.addDiagnostic(.{
                .tag = .previous_definition,
                .loc = gop.value_ptr.loc,
            }, &.{});
        }
    }
    gop.value_ptr.* = macro;
}

/// Get raw token source string.
/// Returned slice is invalidated when comp.generated_buf is updated.
pub fn tokSlice(pp: *Preprocessor, token: anytype) []const u8 {
    if (token.id.lexeme()) |some| return some;
    const source = pp.comp.getSource(token.loc.id);
    var tmp_tokenizer = Tokenizer{
        .buf = source.buf,
        .langopts = pp.comp.langopts,
        .index = token.loc.byte_offset,
        .source = .generated,
    };
    const tok = tmp_tokenizer.next();
    return tmp_tokenizer.buf[tok.start..tok.end];
}

fn expect(pp: *Preprocessor, expected: Tokenizer.Token.Id, tag: Diagnostics.Tag) !PreprocessorToken {
    const tok = pp.getToken();
    if (tok.id != expected) {
        try pp.comp.addDiagnostic(.{
            .tag = tag,
            .loc = tok.loc,
            .extra = .{ .none = {} },
        }, &.{}); // todo expansion slice
        try pp.errTok(tok, tag);
    }
    return tok;
}

fn expectLParen(pp: *Preprocessor, tok: PreprocessorToken) !PreprocessorToken {
    const l_paren = pp.getToken();
    if (l_paren.id != .l_paren) {
        try pp.comp.addDiagnostic(.{
            .tag = .missing_lparen_after_builtin,
            .loc = tok.loc,
            .extra = .{ .str = pp.tokSlice(tok) },
        }, &.{}); // todo expansion slice
    }
    return l_paren;
}

fn makeMacroToken(position: usize, is_vararg: bool) PreprocessorToken {
    return .{
        .id = .macro_param,
        .hideset = null,
        .loc = .{
            .id = .unused,
            .byte_offset = @intCast(position),
            .line = @intFromBool(is_vararg),
        },
    };
}

fn next(pp: *Preprocessor, id: Tokenizer.Token.Id) !bool {
    const tok = pp.getToken();
    if (tok.id == id) return true;
    try pp.ungetToken(tok);
    return false;
}

/// Returns true for vararg function-like macro, false otherwise
fn readFunclikeMacroParams(pp: *Preprocessor, name: PreprocessorToken, l_paren: PreprocessorToken, params: *ParamMap) !bool {
    _ = name;
    var pos: usize = 0;
    while (true) {
        var tok = pp.getToken();
        switch (tok.id) {
            .r_paren => return false,
            .unterminated_comment => {
                try pp.errTok(tok, .unterminated_comment);
                return false;
            },
            else => {},
        }
        if (pos != 0) {
            if (tok.id != .comma) {
                switch (tok.id) {
                    .nl, .eof => {},
                    else => pp.skipToNl(),
                }
                try pp.errTok(tok, .expected_comma_param_list);
                return error.InvalidMacroDef;
            }
            tok = pp.getToken();
        }
        if (tok.id.isDirectiveEnd()) {
            try pp.errTok(tok, .missing_paren_param_list);
            return false;
        }
        if (tok.id == .ellipsis) {
            try params.put(pp.gpa, "__VA_ARGS__", makeMacroToken(pos, true));
            pos += 1;
            const r_paren = pp.getToken();
            if (r_paren.id != .r_paren) {
                try pp.errTok(r_paren, .missing_paren_param_list);
                try pp.errTok(l_paren, .to_match_paren);
                return error.InvalidMacroDef;
            }
            return true;
        }
        if (!tok.id.isMacroIdentifier()) {
            try pp.errTok(tok, .invalid_token_param_list);
            return error.InvalidMacroDef;
        }
        const arg = pp.tokSlice(tok);
        if (try pp.next(.ellipsis)) {
            const r_paren = pp.getToken();
            if (r_paren.id != .r_paren) {
                try pp.errTok(r_paren, .missing_paren_param_list);
                try pp.errTok(l_paren, .to_match_paren);
                pp.skipToNl();
            }
            try params.put(pp.gpa, arg, makeMacroToken(pos, true));
            pos += 1;
            return true;
        }
        try params.put(pp.gpa, arg, makeMacroToken(pos, false));
        pos += 1;
    }
}

fn readFunclikeMacroBody(pp: *Preprocessor, params: *const ParamMap) ![]const PreprocessorToken {
    var tokens: TokenList = .{};
    errdefer tokens.deinit(pp.gpa);
    while (true) {
        const tok = pp.getToken();
        if (tok.id.isDirectiveEnd()) {
            return tokens.toOwnedSlice(pp.gpa);
        }
        if (tok.id.isMacroIdentifier()) {
            // const subst = params.
            if (params.get(pp.tokSlice(tok))) |sub| {
                var copy = sub;
                copy.flags.space = tok.flags.space;
                try tokens.append(pp.gpa, copy);
                continue;
            }
        }
        try tokens.append(pp.gpa, tok);
    }
}

fn readFuncLikeMacro(pp: *Preprocessor, name: PreprocessorToken, l_paren: PreprocessorToken) Error!void {
    var params: ParamMap = .{};
    defer params.deinit(pp.gpa);
    const is_vararg = pp.readFunclikeMacroParams(name, l_paren, &params) catch |err| switch (err) {
        error.InvalidMacroDef => blk: {
            pp.skipToNl();
            break :blk false;
        },
        else => |e| return e,
    };
    const body = try pp.readFunclikeMacroBody(&params);
    errdefer pp.gpa.free(body);
    try pp.hashHashCheck(body);
    const macro: Macro = .{
        .tokens = body,
        .var_args = is_vararg,
        .loc = name.loc,
        .kind = .func,
        .nargs = params.count(),
    };
    try pp.defineMacro(name, macro);
}

fn readDefine(pp: *Preprocessor) !void {
    const name = try pp.readIdent() orelse {
        pp.skipToNl();
        return;
    };
    const next_tok = pp.getToken();
    if (next_tok.id == .l_paren and !next_tok.flags.space) {
        try pp.readFuncLikeMacro(name, next_tok);
        return;
    }
    try pp.ungetToken(next_tok);
    try pp.readObjMacro(name);
}

fn doSkipSpace(pp: *Preprocessor) bool {
    const saved_tokenizer = pp.tokenizers.items[pp.tokenizers.items.len - 1];
    const tok = pp.tokenizers.items[pp.tokenizers.items.len - 1].next();
    switch (tok.id) {
        .eof => return false,
        .whitespace, .comment => return true,
        else => {
            pp.tokenizers.items[pp.tokenizers.items.len - 1] = saved_tokenizer;
            return false;
        },
    }
}

/// Skips spaces including comments.
/// Returns true if at least one space is skipped.
fn skipSpace(pp: *Preprocessor) bool {
    if (!pp.doSkipSpace()) {
        return false;
    }
    while (pp.doSkipSpace()) {}
    return true;
}

/// Read the next raw token from the tokenizer stack
fn lexToken(pp: *Preprocessor) PreprocessorToken {
    if (pp.skipSpace()) {
        return .{ .id = .whitespace, .loc = undefined };
    }
    const tok = pp.tokenizers.items[pp.tokenizers.items.len - 1].next();
    return .{
        .id = tok.id,
        .flags = .{
            .is_bol = tok.bol,
        },
        .loc = .{
            .id = tok.source,
            .byte_offset = tok.start,
            .line = tok.line,
        },
    };
}

/// Read the next token without expanding it
fn getToken(pp: *Preprocessor) PreprocessorToken {
    if (!pp.isBufferEmpty() and pp.expansion_bufs.items[pp.expansion_bufs.items.len - 1].items.len > 0) {
        return pp.expansion_bufs.items[pp.expansion_bufs.items.len - 1].pop();
    }
    if (pp.expansion_bufs.items.len > 1) {
        return .{ .id = .eof, .loc = undefined };
    }
    const bol = pp.tokenizers.items[pp.tokenizers.items.len - 1].bol;
    var tok = pp.lexToken();
    while (tok.id == .whitespace) {
        tok = pp.lexToken();
        tok.flags.space = true;
    }
    tok.flags.is_bol = bol;
    return tok;
}

fn readDefinedOp(pp: *Preprocessor) !PreprocessorToken {
    var tok = pp.getToken();
    if (tok.id == .l_paren) {
        tok = pp.getToken();
        const r_paren = pp.getToken();
        if (r_paren.id != .r_paren) {
            try pp.errStr(r_paren, .closing_paren_after, "defined");
        }
    }
    if (!tok.id.isMacroIdentifier()) {
        try pp.errTok(tok, .macro_name_must_be_identifier);
    }
    const slice = pp.tokSlice(tok);
    if (pp.defines.contains(slice)) {
        return PreprocessorToken.one;
    }
    return PreprocessorToken.zero;
}

fn readIntExprLine(pp: *Preprocessor) !void {
    while (true) {
        const tok = try pp.readExpandNewline();
        if (tok.id.isDirectiveEnd()) break;
        if (tok.id == .keyword_defined) {
            const result = try pp.readDefinedOp();
            try pp.addToken(result);
        } else if (tok.id.isMacroIdentifier()) {
            try pp.addToken(PreprocessorToken.zero);
        } else {
            try pp.addToken(tok);
        }
    }
    try pp.addToken(.{ .id = .eof, .loc = .{} });
}

fn readConstexpr(pp: *Preprocessor) !bool {
    const start = pp.tokens.len;
    defer pp.tokens.len = start;
    try pp.readIntExprLine();

    var parser = Parser{
        .pp = pp,
        .comp = pp.comp,
        .gpa = pp.gpa,
        .tok_ids = pp.tokens.items(.id),
        .tok_i = @intCast(start),
        .arena = undefined,
        .in_macro = true,
        .strings = std.ArrayListAligned(u8, 4).init(pp.comp.gpa),

        .data = undefined,
        .value_map = undefined,
        .labels = undefined,
        .decl_buf = undefined,
        .list_buf = undefined,
        .param_buf = undefined,
        .enum_buf = undefined,
        .record_buf = undefined,
        .attr_buf = undefined,
        .field_attr_buf = undefined,
        .string_ids = undefined,
    };
    defer parser.strings.deinit();
    return parser.macroExpr();
}

/// #line number "file"
/// TODO: validate that the pp_num token is solely digits
fn readLine(pp: *Preprocessor) Error!void {
    const digits = pp.getToken();
    if (digits.id != .pp_num) try pp.errTok(digits, .line_simple_digit);

    if (digits.id.isDirectiveEnd()) return;
    const name = pp.getToken();
    if (name.id.isDirectiveEnd()) return;
    if (name.id != .string_literal) try pp.errTok(name, .line_invalid_filename);
    try pp.expectNewline();
}

fn readPragma(pp: *Preprocessor, pragma_tok: PreprocessorToken) Error!void {
    const name_tok = pp.getToken();
    if (name_tok.id == .nl or name_tok.id == .eof) return;

    try pp.addToken(pragma_tok);

    const pragma_start: u32 = @intCast(pp.tokens.len);
    try pp.addToken(name_tok);

    while (true) {
        const next_tok = pp.getToken();
        if (next_tok.id == .eof) {
            try pp.addToken(.{
                .id = .nl,
                .loc = .{ .id = .generated },
            });
            break;
        }
        try pp.addToken(next_tok);
        if (next_tok.id == .nl) break;
    }
    const name = pp.tokSlice(name_tok);
    if (pp.comp.getPragma(name)) |prag| unknown: {
        return prag.preprocessorCB(pp, pragma_start) catch |er| switch (er) {
            error.UnknownPragma => break :unknown,
            error.StopPreprocessing => {
                _ = pp.tokenizers.pop();
                return;
            },
            else => |e| return e,
        };
    }
    return pp.errTok(name_tok, .unknown_pragma);
}

fn readUndef(pp: *Preprocessor) Error!void {
    const name = try pp.readIdent() orelse {
        pp.skipToNl();
        return;
    };
    try pp.expectNewline();
    _ = pp.defines.remove(pp.tokSlice(name));
}

/// Skip until after a newline, error if extra tokens before it.
fn expectNewline(pp: *Preprocessor) !void {
    var sent_err = false;
    while (true) {
        const tok = pp.getToken();
        if (tok.id.isDirectiveEnd()) return;
        if (tok.id == .whitespace or tok.id == .comment) continue;
        if (!sent_err) {
            sent_err = true;
            try pp.errTok(tok, .extra_tokens_directive_end);
        }
    }
}

/// TODO: pragma once
fn readIncludeExtra(pp: *Preprocessor, include_token: PreprocessorToken, which: Compilation.WhichInclude) Error!void {
    var is_std: bool = undefined;
    const include_str = pp.readHeaderName(&is_std) catch |err| switch (err) {
        error.InvalidInclude => return,
        else => |e| return e,
    };
    try pp.expectNewline();

    const filename = include_str[1 .. include_str.len - 1];
    const include_type: Compilation.IncludeType = switch (include_str[0]) {
        '"' => .quotes,
        '<' => .angle_brackets,
        else => unreachable,
    };
    const tok: RawToken = .{ .id = include_token.id, .source = include_token.loc.id, .start = include_token.loc.byte_offset, .line = include_token.loc.line };
    const source = (try pp.comp.findInclude(filename, tok, include_type, which)) orelse return pp.fatalNotFound(include_token, filename);
    if (pp.include_guards.get(source.id)) |guard| {
        if (pp.defines.contains(guard)) return;
    }
    const guard = pp.findIncludeGuard(source);
    try pp.guard_stack.append(pp.gpa, guard);

    if (pp.tokenizers.items.len > max_include_depth) {
        try pp.comp.addDiagnostic(.{
            .tag = .too_many_includes,
            .loc = include_token.loc,
        }, &.{});
        return error.FatalError;
    }
    pp.preprocess_count += 1;
    try pp.tokenizers.append(pp.gpa, .{
        .buf = source.buf,
        .langopts = pp.comp.langopts,
        .index = 0,
        .source = source.id,
    });
}

/// Read a header name delimited by quotes or angle brackets
fn readHeaderFileName(pp: *Preprocessor, is_std: *bool) !?[]const u8 {
    if (!pp.isBufferEmpty()) return null;
    _ = pp.skipSpace();

    var close: u8 = undefined;
    var tokenizer = pp.tokenizers.items[pp.tokenizers.items.len - 1];
    defer pp.tokenizers.items[pp.tokenizers.items.len - 1] = tokenizer;

    if (tokenizer.buf[tokenizer.index..].len < 2) {
        return null;
    }
    const start = tokenizer.index;
    switch (tokenizer.buf[tokenizer.index..][0]) {
        '"' => {
            is_std.* = false;
            close = '"';
        },
        '<' => {
            is_std.* = true;
            close = '>';
        },
        else => return null,
    }
    tokenizer.index += 1;
    while (tokenizer.index < tokenizer.buf.len and tokenizer.buf[tokenizer.index] != close and tokenizer.buf[tokenizer.index] != '\n') : (tokenizer.index += 1) {}

    if (tokenizer.index == tokenizer.buf.len or tokenizer.buf[tokenizer.index] != close) {
        try pp.errTok(.{ .id = undefined, .loc = .{ .id = tokenizer.source, .byte_offset = tokenizer.index, .line = tokenizer.line } }, .header_str_closing);
        try pp.errTok(.{ .id = undefined, .loc = .{ .id = tokenizer.source, .byte_offset = start, .line = tokenizer.line } }, .header_str_match);
        return error.InvalidInclude;
    }

    tokenizer.index += 1;

    const buf = tokenizer.buf[start..tokenizer.index];
    if (buf.len == 2) {
        try pp.errTok(.{ .id = .nl, .loc = .{ .id = tokenizer.source, .byte_offset = start, .line = tokenizer.line } }, .empty_filename);
        return error.InvalidInclude;
    }
    return buf;
}

fn isBufferEmpty(pp: *const Preprocessor) bool {
    return pp.expansion_bufs.items.len == 0;
}

/// Read a delimited header name, or a macro expanded one
fn readHeaderName(pp: *Preprocessor, is_std: *bool) ![]const u8 {
    if (try pp.readHeaderFileName(is_std)) |path| return path;

    // If a token following #include does not start with < nor ",
    // try to read the token as a regular token. Macro-expanded
    // form may be a valid header file path.
    const tok = try pp.readExpandNewline();
    if (tok.id.isDirectiveEnd()) {
        try pp.errTok(tok, .expected_filename);
        return error.InvalidInclude;
    }
    if (tok.id == .string_literal) {
        is_std.* = false;
        return pp.tokSlice(tok);
    }
    if (tok.id != .angle_bracket_left) {
        try pp.errStr(tok, .expected_left_angle_bracket, pp.tokSlice(tok));
        return error.InvalidInclude;
    }
    const start = pp.char_buf.items.len;
    try pp.char_buf.append(pp.gpa, '<');
    defer pp.char_buf.items.len = start;
    const writer = pp.char_buf.writer(pp.gpa);
    while (true) {
        const path_tok = try pp.readExpandNewline();
        if (path_tok.id == .nl) {
            try pp.errTok(path_tok, .header_str_closing);
            try pp.errTok(tok, .header_str_match);
            return error.InvalidInclude;
        }
        if (path_tok.id == .angle_bracket_right) {
            break;
        }
        try pp.prettyPrintToken(writer, path_tok.toTreeToken());
    }
    is_std.* = true;
    try pp.char_buf.append(pp.gpa, '>');
    return pp.gpa.dupe(u8, pp.char_buf.items[start..]);
}

fn readInclude(pp: *Preprocessor, include_token: PreprocessorToken) Error!void {
    return pp.readIncludeExtra(include_token, .first);
}

fn readIncludeNext(pp: *Preprocessor, include_token: PreprocessorToken) Error!void {
    return pp.readIncludeExtra(include_token, .next);
}

fn readErrorMessage(pp: *Preprocessor, directive_tok: PreprocessorToken, tag: Diagnostics.Tag) !void {
    const char_top = pp.char_buf.items.len;
    defer pp.char_buf.items.len = char_top;
    var i: usize = 0;
    while (true) : (i += 1) {
        const tok = pp.getToken();
        if (tok.id.isDirectiveEnd()) break;
        const slice = pp.tokSlice(tok);
        if (slice.len > 0 and tok.flags.space and i != 0) {
            try pp.char_buf.append(pp.gpa, ' ');
        }
        try pp.char_buf.appendSlice(pp.gpa, slice);
    }
    const slice = pp.char_buf.items[char_top..];
    const duped = try pp.comp.diagnostics.arena.allocator().dupe(u8, slice);
    try pp.comp.addDiagnostic(.{
        .tag = tag,
        .loc = directive_tok.loc,
        .extra = .{ .str = duped },
    }, &.{});
}

fn clearGuard(pp: *Preprocessor) void {
    pp.guard_stack.items[pp.guard_stack.items.len - 1] = null;
}

fn readDirective(pp: *Preprocessor) Error!void {
    const directive = pp.getToken();
    if (directive.id.isDirectiveEnd()) return;
    if (directive.id == .pp_num) {
        return pp.readLinemarker();
    }

    const until_else = 0;
    const until_endif = 1;
    const until_endif_seen_else = 2;

    switch (directive.id) {
        .keyword_define => try pp.readDefine(),
        .keyword_elif => {
            if (pp.if_level == 0) {
                try pp.errTok(directive, .elif_without_if);
                pp.if_level += 1;
                pp.if_kind.set(pp.if_level, until_else);
            } else if (pp.if_level == 1) {
                pp.clearGuard();
            }
            switch (pp.if_kind.get(pp.if_level)) {
                until_else => if (try pp.readConstexpr()) {
                    pp.if_kind.set(pp.if_level, until_endif);
                    if (pp.verbose) {
                        pp.verboseLog(directive, "entering then branch of #elif", .{});
                    }
                } else {
                    try pp.skip(.until_else);
                    if (pp.verbose) {
                        pp.verboseLog(directive, "entering else branch of #elif", .{});
                    }
                },
                until_endif => try pp.skip(.until_endif),
                until_endif_seen_else => {
                    try pp.errTok(directive, .elif_after_else);
                    pp.skipToNl();
                },
                else => unreachable,
            }
        },
        .keyword_else => {
            try pp.expectNewline();
            if (pp.if_level == 0) {
                try pp.errTok(directive, .else_without_if);
                return;
            } else if (pp.if_level == 1) {
                pp.clearGuard();
            }
            switch (pp.if_kind.get(pp.if_level)) {
                until_else => {
                    pp.if_kind.set(pp.if_level, until_endif_seen_else);
                    if (pp.verbose) {
                        pp.verboseLog(directive, "#else branch here", .{});
                    }
                },
                until_endif => try pp.skip(.until_endif_seen_else),
                until_endif_seen_else => {
                    try pp.errTok(directive, .else_after_else);
                    pp.skipToNl();
                },
                else => unreachable,
            }
        },
        .keyword_endif => {
            try pp.expectNewline();
            if (pp.if_level == 0) {
                pp.clearGuard();
                try pp.errTok(directive, .endif_without_if);
                return;
            } else if (pp.if_level == 1) {
                var tokenizer = &pp.tokenizers.items[pp.tokenizers.items.len - 1];
                const saved_tokenizer = tokenizer.*;
                defer tokenizer.* = saved_tokenizer;

                var next_tok = tokenizer.nextNoWS();
                while (next_tok.id == .nl) : (next_tok = tokenizer.nextNoWS()) {}
                if (next_tok.id != .eof) pp.clearGuard();
            }
            pp.if_level -= 1;
        },
        .keyword_error => try pp.readErrorMessage(directive, .error_directive),
        .keyword_if => {
            const sum, const overflowed = @addWithOverflow(pp.if_level, 1);
            if (overflowed != 0)
                return pp.fatal(directive, "too many #if nestings", .{});
            pp.if_level = sum;

            if (try pp.readConstexpr()) {
                pp.if_kind.set(pp.if_level, until_endif);
                if (pp.verbose) {
                    pp.verboseLog(directive, "entering then branch of #if", .{});
                }
            } else {
                pp.if_kind.set(pp.if_level, until_else);
                try pp.skip(.until_else);
                if (pp.verbose) {
                    pp.verboseLog(directive, "entering else branch of #if", .{});
                }
            }
        },
        .keyword_ifdef => {
            const sum, const overflowed = @addWithOverflow(pp.if_level, 1);
            if (overflowed != 0)
                return pp.fatal(directive, "too many #if nestings", .{});
            pp.if_level = sum;

            const macro_name = (try pp.expectMacroName()) orelse return;
            try pp.expectNewline();
            if (pp.defines.get(macro_name) != null) {
                pp.if_kind.set(pp.if_level, until_endif);
                if (pp.verbose) {
                    pp.verboseLog(directive, "entering then branch of #ifdef", .{});
                }
            } else {
                pp.if_kind.set(pp.if_level, until_else);
                try pp.skip(.until_else);
                if (pp.verbose) {
                    pp.verboseLog(directive, "entering else branch of #ifdef", .{});
                }
            }
        },
        .keyword_ifndef => {
            const sum, const overflowed = @addWithOverflow(pp.if_level, 1);
            if (overflowed != 0)
                return pp.fatal(directive, "too many #if nestings", .{});
            pp.if_level = sum;

            const macro_name = (try pp.expectMacroName()) orelse return;
            try pp.expectNewline();
            if (pp.defines.get(macro_name) == null) {
                pp.if_kind.set(pp.if_level, until_endif);
            } else {
                pp.if_kind.set(pp.if_level, until_else);
                try pp.skip(.until_else);
            }
        },
        .keyword_elifdef => {
            if (pp.if_level == 0) {
                try pp.errTok(directive, .elifdef_without_if);
                pp.if_level += 1;
                pp.if_kind.set(pp.if_level, until_else);
            } else if (pp.if_level == 1) {
                pp.clearGuard();
            }
            switch (pp.if_kind.get(pp.if_level)) {
                until_else => {
                    const macro_name = try pp.expectMacroName();
                    if (macro_name == null) {
                        pp.if_kind.set(pp.if_level, until_else);
                        try pp.skip(.until_else);
                        if (pp.verbose) {
                            pp.verboseLog(directive, "entering else branch of #elifdef", .{});
                        }
                    } else {
                        try pp.expectNewline();
                        if (pp.defines.get(macro_name.?) != null) {
                            pp.if_kind.set(pp.if_level, until_endif);
                            if (pp.verbose) {
                                pp.verboseLog(directive, "entering then branch of #elifdef", .{});
                            }
                        } else {
                            pp.if_kind.set(pp.if_level, until_else);
                            try pp.skip(.until_else);
                            if (pp.verbose) {
                                pp.verboseLog(directive, "entering else branch of #elifdef", .{});
                            }
                        }
                    }
                },
                until_endif => try pp.skip(.until_endif),
                until_endif_seen_else => {
                    try pp.errTok(directive, .elifdef_after_else);
                    pp.skipToNl();
                },
                else => unreachable,
            }
        },
        .keyword_elifndef => {
            if (pp.if_level == 0) {
                try pp.errTok(directive, .elifdef_without_if);
                pp.if_level += 1;
                pp.if_kind.set(pp.if_level, until_else);
            } else if (pp.if_level == 1) {
                pp.clearGuard();
            }
            switch (pp.if_kind.get(pp.if_level)) {
                until_else => {
                    const macro_name = try pp.expectMacroName();
                    if (macro_name == null) {
                        pp.if_kind.set(pp.if_level, until_else);
                        try pp.skip(.until_else);
                        if (pp.verbose) {
                            pp.verboseLog(directive, "entering else branch of #elifndef", .{});
                        }
                    } else {
                        try pp.expectNewline();
                        if (pp.defines.get(macro_name.?) == null) {
                            pp.if_kind.set(pp.if_level, until_endif);
                            if (pp.verbose) {
                                pp.verboseLog(directive, "entering then branch of #elifndef", .{});
                            }
                        } else {
                            pp.if_kind.set(pp.if_level, until_else);
                            try pp.skip(.until_else);
                            if (pp.verbose) {
                                pp.verboseLog(directive, "entering else branch of #elifndef", .{});
                            }
                        }
                    }
                },
                until_endif => try pp.skip(.until_endif),
                until_endif_seen_else => {
                    try pp.errTok(directive, .elifdef_after_else);
                    pp.skipToNl();
                },
                else => unreachable,
            }
        },
        .keyword_include => try pp.readInclude(directive),
        .keyword_include_next => try pp.readIncludeNext(directive),
        .keyword_line => try pp.readLine(),
        .keyword_pragma => try pp.readPragma(directive),
        .keyword_undef => try pp.readUndef(),
        .keyword_warning => try pp.readErrorMessage(directive, .warning_directive),
        .keyword_embed => try pp.readEmbed(directive),
        else => try pp.errTok(directive, .invalid_preprocessing_directive),
    }
}

/// TODO: handle limit/prefix/suffix/etc
fn readEmbed(pp: *Preprocessor, directive_tok: PreprocessorToken) Error!void {
    var is_std: bool = undefined;
    const include_str = pp.readHeaderName(&is_std) catch |err| switch (err) {
        error.InvalidInclude => return,
        else => |e| return e,
    };

    const filename = include_str[1 .. include_str.len - 1];
    const include_type: Compilation.IncludeType = switch (include_str[0]) {
        '"' => .quotes,
        '<' => .angle_brackets,
        else => unreachable,
    };

    const limit = std.math.maxInt(u32);
    const embed_bytes = (try pp.comp.findEmbed(filename, directive_tok.loc.id, include_type, limit)) orelse
        return pp.fatalNotFound(directive_tok, filename);
    defer pp.comp.gpa.free(embed_bytes);

    if (embed_bytes.len == 0) return;

    try pp.ensureUnusedTokenCapacity(2 * embed_bytes.len - 1); // N bytes and N-1 commas

    // TODO: We currently only support systems with CHAR_BIT == 8
    // If the target's CHAR_BIT is not 8, we need to write out correctly-sized embed_bytes
    // and correctly account for the target's endianness
    const writer = pp.comp.generated_buf.writer(pp.gpa);

    {
        const byte = embed_bytes[0];
        const start = pp.comp.generated_buf.items.len;
        try writer.print("{d}", .{byte});
        var generated = try pp.makeGeneratedToken(start, .embed_byte, directive_tok);
        generated.flags.is_bol = true;
        pp.addTokenAssumeCapacity(generated);
    }

    for (embed_bytes[1..]) |byte| {
        const start = pp.comp.generated_buf.items.len;
        try writer.print(",{d}", .{byte});
        pp.addTokenAssumeCapacity(.{ .id = .comma, .loc = .{ .id = .generated, .byte_offset = @intCast(start) } });
        pp.addTokenAssumeCapacity(try pp.makeGeneratedToken(start + 1, .embed_byte, directive_tok));
    }
    try pp.comp.generated_buf.append(pp.gpa, '\n');
}

fn readToken(pp: *Preprocessor) Error!PreprocessorToken {
    while (true) {
        const tok = try pp.readExpand();
        if (tok.flags.is_bol and tok.id == .hash and tok.hideset == null) {
            try pp.readDirective();
            continue;
        }
        return tok;
    }
}

pub fn preprocess(pp: *Preprocessor, source: Source) !PreprocessorToken {
    const guard = pp.findIncludeGuard(source);
    try pp.guard_stack.append(pp.gpa, guard);

    pp.preprocess_count += 1;
    try pp.tokenizers.append(pp.gpa, .{
        .buf = source.buf,
        .langopts = pp.comp.langopts,
        .index = 0,
        .source = source.id,
    });
    while (true) {
        const tok = try pp.readToken();
        if (tok.id == .eof) {
            const tokenizer = pp.tokenizers.pop();
            const guard_name = pp.guard_stack.pop();
            if (guard_name) |name| {
                try pp.include_guards.put(pp.gpa, tokenizer.source, name);
            }
            if (pp.tokenizers.items.len == 0) {
                return tok;
            }
        } else {
            switch (tok.id) {
                .unterminated_comment => try pp.errTok(tok, .unterminated_comment),
                else => try pp.addToken(tok),
            }
        }
    }
}

// After how many empty lines are needed to replace them with linemarkers.
const collapse_newlines = 8;

/// Pretty print tokens and try to preserve whitespace.
pub fn prettyPrintTokens(pp: *Preprocessor, w: anytype) !void {
    const tok_ids = pp.tokens.items(.id);
    var i: u32 = 0;
    var last_nl = false;
    while (i < pp.tokens.len) : (i += 1) {
        var cur: Token = pp.tokens.get(i);
        switch (cur.id) {
            .eof => break,
            .keyword_pragma => {
                const pragma_name = pp.tokSlice(pp.tokens.get(i + 1));
                const end_idx = mem.indexOfScalarPos(Token.Id, tok_ids, i, .nl) orelse i + 1;
                const pragma_len = @as(u32, @intCast(end_idx)) - i;

                if (pp.comp.getPragma(pragma_name)) |prag| {
                    if (!prag.shouldPreserveTokens(pp, i + 1)) {
                        try w.writeByte('\n');
                        i += pragma_len;
                        cur = pp.tokens.get(i);
                        continue;
                    }
                }
                try w.writeAll("#pragma");
                i += 1;
                while (true) : (i += 1) {
                    cur = pp.tokens.get(i);
                    if (cur.id == .nl) {
                        try w.writeByte('\n');
                        last_nl = true;
                        break;
                    }
                    try w.writeByte(' ');
                    const slice = pp.tokSlice(cur);
                    try w.writeAll(slice);
                }
            },
            else => try pp.prettyPrintToken(w, cur),
        }
    }
    try w.writeByte('\n');
}

fn prettyPrintToken(pp: *Preprocessor, w: anytype, tok: Token) !void {
    if (tok.flags.is_bol) {
        try w.writeByte('\n');
    }
    if (tok.flags.space) {
        try w.writeByte(' ');
    }
    if (tok.id.lexeme()) |some| {
        try w.writeAll(some);
    } else {
        try w.writeAll(pp.tokSlice(tok));
    }
}

pub fn expansionSlice(pp: *Preprocessor, tok: Tree.TokenIndex) []Source.Location {
    const S = struct {
        fn order_token_index(context: void, lhs: Tree.TokenIndex, rhs: Tree.TokenIndex) std.math.Order {
            _ = context;
            return std.math.order(lhs, rhs);
        }
    };

    const indices = pp.expansion_entries.items(.idx);
    const idx = std.sort.binarySearch(Tree.TokenIndex, tok, indices, {}, S.order_token_index) orelse return &.{};
    const locs = pp.expansion_entries.items(.locs)[idx];
    var i: usize = 0;
    while (locs[i].id != .unused) : (i += 1) {}
    return locs[0..i];
}

pub fn addToken(pp: *Preprocessor, tok: PreprocessorToken) !void {
    if (tok.expansion_locs) |expansion_locs| {
        try pp.expansion_entries.append(pp.gpa, .{ .idx = @intCast(pp.tokens.len), .locs = expansion_locs });
    }
    try pp.tokens.append(pp.gpa, tok.toTreeToken());
}

pub fn addTokenAssumeCapacity(pp: *Preprocessor, tok: PreprocessorToken) void {
    if (tok.expansion_locs) |expansion_locs| {
        pp.expansion_entries.appendAssumeCapacity(.{ .idx = @intCast(pp.tokens.len), .locs = expansion_locs });
    }
    pp.tokens.appendAssumeCapacity(tok.toTreeToken());
}

pub fn ensureTotalTokenCapacity(pp: *Preprocessor, capacity: usize) !void {
    try pp.tokens.ensureTotalCapacity(pp.gpa, capacity);
    try pp.expansion_entries.ensureTotalCapacity(pp.gpa, capacity);
}

pub fn ensureUnusedTokenCapacity(pp: *Preprocessor, capacity: usize) !void {
    try pp.tokens.ensureUnusedCapacity(pp.gpa, capacity);
    try pp.expansion_entries.ensureUnusedCapacity(pp.gpa, capacity);
}

fn skip(
    pp: *Preprocessor,
    cont: enum { until_else, until_endif, until_endif_seen_else },
) Error!void {
    var ifs_seen: u32 = 0;
    var line_start = true;
    var tokenizer = &pp.tokenizers.items[pp.tokenizers.items.len - 1];

    while (tokenizer.index < tokenizer.buf.len) {
        if (line_start) {
            const saved_tokenizer = tokenizer.*;
            const hash = tokenizer.nextNoWS();
            if (hash.id == .nl) continue;
            line_start = false;
            if (hash.id != .hash) continue;
            const directive = tokenizer.nextNoWS();
            switch (directive.id) {
                .keyword_else => {
                    if (ifs_seen != 0) continue;
                    if (cont == .until_endif_seen_else) {
                        // try pp.err(directive, .else_after_else);
                        continue;
                    }
                    tokenizer.* = saved_tokenizer;
                    return;
                },
                .keyword_elif => {
                    if (ifs_seen != 0 or cont == .until_endif) continue;
                    if (cont == .until_endif_seen_else) {
                        // try pp.err(directive, .elif_after_else);
                        continue;
                    }
                    tokenizer.* = saved_tokenizer;
                    return;
                },
                .keyword_elifdef => {
                    if (ifs_seen != 0 or cont == .until_endif) continue;
                    if (cont == .until_endif_seen_else) {
                        // try pp.err(directive, .elifdef_after_else);
                        continue;
                    }
                    tokenizer.* = saved_tokenizer;
                    return;
                },
                .keyword_elifndef => {
                    if (ifs_seen != 0 or cont == .until_endif) continue;
                    if (cont == .until_endif_seen_else) {
                        // try pp.err(directive, .elifndef_after_else);
                        continue;
                    }
                    tokenizer.* = saved_tokenizer;
                    return;
                },
                .keyword_endif => {
                    if (ifs_seen == 0) {
                        tokenizer.* = saved_tokenizer;
                        return;
                    }
                    ifs_seen -= 1;
                },
                .keyword_if, .keyword_ifdef, .keyword_ifndef => ifs_seen += 1,
                else => {},
            }
        } else if (tokenizer.buf[tokenizer.index] == '\n') {
            line_start = true;
            tokenizer.index += 1;
            tokenizer.line += 1;
            tokenizer.bol = true;
            if (pp.preserve_whitespace) {
                try pp.addToken(.{ .id = .nl, .loc = .{
                    .id = tokenizer.source,
                    .line = tokenizer.line,
                } });
            }
        } else {
            line_start = false;
            tokenizer.index += 1;
        }
    } else {
        return pp.errTok(.{ .id = .eof, .loc = .{ .id = tokenizer.source, .byte_offset = tokenizer.index, .line = tokenizer.line } }, .unterminated_conditional_directive);
    }
}

fn verboseLog(pp: *Preprocessor, tok: PreprocessorToken, comptime fmt: []const u8, args: anytype) void {
    const source = pp.comp.getSource(tok.loc.id);
    const line_col = source.lineCol(tok.loc);

    const stderr = std.io.getStdErr().writer();
    var buf_writer = std.io.bufferedWriter(stderr);
    const writer = buf_writer.writer();
    defer buf_writer.flush() catch {};
    writer.print("{s}:{d}:{d}: ", .{ source.path, line_col.line_no, line_col.col }) catch return;
    writer.print(fmt, args) catch return;
    writer.writeByte('\n') catch return;
    writer.writeAll(line_col.line) catch return;
    writer.writeByte('\n') catch return;
}

fn fatal(pp: *Preprocessor, tok: PreprocessorToken, comptime fmt: []const u8, args: anytype) Compilation.Error {
    try pp.comp.diagnostics.list.append(pp.gpa, .{
        .tag = .cli_error,
        .kind = .@"fatal error",
        .extra = .{ .str = try std.fmt.allocPrint(pp.comp.diagnostics.arena.allocator(), fmt, args) },
        .loc = tok.loc,
    });
    return error.FatalError;
}

fn fatalNotFound(pp: *Preprocessor, tok: PreprocessorToken, filename: []const u8) Compilation.Error {
    const old = pp.comp.diagnostics.fatal_errors;
    pp.comp.diagnostics.fatal_errors = true;
    defer pp.comp.diagnostics.fatal_errors = old;

    try pp.comp.diagnostics.addExtra(pp.comp.langopts, .{ .tag = .cli_error, .loc = tok.loc, .extra = .{
        .str = try std.fmt.allocPrint(pp.comp.diagnostics.arena.allocator(), "'{s}' not found", .{filename}),
    } }, tok.expansionSlice(), false);
    unreachable; // addExtra should've returned FatalError
}

/// Consume next token, error if it is not an identifier.
fn expectMacroName(pp: *Preprocessor) Error!?[]const u8 {
    const macro_name = pp.getToken();
    if (!macro_name.id.isMacroIdentifier()) {
        try pp.errTok(macro_name, .macro_name_missing);
        pp.skipToNl();
        return null;
    }
    return pp.tokSlice(macro_name);
}

/// Return the name of the #ifndef guard macro that starts a source, if any.
/// If a source starts with `#ifndef IDENTIFIER`, return `IDENTIFIER`
/// This function does not validate that the entire source is guarded by the
/// initial ifndef, if any
fn findIncludeGuard(pp: *Preprocessor, source: Source) ?[]const u8 {
    var tokenizer = Tokenizer{
        .buf = source.buf,
        .langopts = pp.comp.langopts,
        .source = source.id,
    };
    var hash = tokenizer.nextNoWS();
    while (hash.id == .nl) hash = tokenizer.nextNoWS();
    if (hash.id != .hash) return null;
    const ifndef = tokenizer.nextNoWS();
    if (ifndef.id != .keyword_ifndef) return null;
    const guard = tokenizer.nextNoWS();
    if (guard.id != .identifier) return null;
    return pp.tokSlice(.{ .id = guard.id, .loc = .{ .id = guard.source, .byte_offset = guard.start, .line = guard.line } });
}
