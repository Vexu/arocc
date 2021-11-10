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
const Token = @import("Tree.zig").Token;
const AttrTag = @import("Attribute.zig").Tag;

const Preprocessor = @This();
const DefineMap = std.StringHashMap(Macro);
const RawTokenList = std.ArrayList(RawToken);
const max_include_depth = 200;

const Macro = struct {
    /// Parameters of the function type macro
    params: []const []const u8,

    /// Token constituting the macro body
    tokens: []const RawToken,

    /// If the function type macro has variable number of arguments
    var_args: bool,

    /// Is a function type macro
    is_func: bool,

    /// Is a predefined macro
    is_builtin: bool = false,

    /// Location of macro in the source
    loc: Source.Location,

    fn eql(a: Macro, b: Macro, pp: *Preprocessor) bool {
        if (a.tokens.len != b.tokens.len) return false;
        if (a.is_builtin != b.is_builtin) return false;
        for (a.tokens) |t, i| if (!tokEql(pp, t, b.tokens[i])) return false;

        if (a.is_func and b.is_func) {
            if (a.var_args != b.var_args) return false;
            if (a.params.len != b.params.len) return false;
            for (a.params) |p, i| if (!mem.eql(u8, p, b.params[i])) return false;
        }

        return true;
    }

    fn tokEql(pp: *Preprocessor, a: RawToken, b: RawToken) bool {
        return mem.eql(u8, pp.tokSliceSafe(a), pp.tokSliceSafe(b));
    }
};

comp: *Compilation,
arena: std.heap.ArenaAllocator,
defines: DefineMap,
tokens: Token.List = .{},
generated: std.ArrayList(u8),
token_buf: RawTokenList,
char_buf: std.ArrayList(u8),
/// Counter that is incremented each time preprocess() is called
/// Can be used to distinguish multiple preprocessings of the same file
preprocess_count: u32 = 0,
include_depth: u8 = 0,
poisoned_identifiers: std.StringHashMap(void),

pub fn init(comp: *Compilation) Preprocessor {
    const pp = Preprocessor{
        .comp = comp,
        .arena = std.heap.ArenaAllocator.init(comp.gpa),
        .defines = DefineMap.init(comp.gpa),
        .generated = std.ArrayList(u8).init(comp.gpa),
        .token_buf = RawTokenList.init(comp.gpa),
        .char_buf = std.ArrayList(u8).init(comp.gpa),
        .poisoned_identifiers = std.StringHashMap(void).init(comp.gpa),
    };
    comp.pragmaEvent(.before_preprocess);
    return pp;
}

const FeatureCheckMacros = struct {
    const args = [1][]const u8{"X"};

    const has_attribute = [1]RawToken{.{
        .id = .macro_param_has_attribute,
        .source = .generated,
        .start = 0,
        .end = 0,
    }};
    const has_warning = [1]RawToken{.{
        .id = .macro_param_has_warning,
        .source = .generated,
        .start = 0,
        .end = 0,
    }};

    const is_identifier = [1]RawToken{.{
        .id = .macro_param_is_identifier,
        .source = .generated,
        .start = 0,
        .end = 0,
    }};
};

fn addBuiltinMacro(pp: *Preprocessor, name: []const u8, tokens: []const RawToken) !void {
    try pp.defines.put(name, .{
        .params = &FeatureCheckMacros.args,
        .tokens = tokens,
        .var_args = false,
        .is_func = true,
        .loc = .{ .id = .generated },
        .is_builtin = true,
    });
}

pub fn addBuiltinMacros(pp: *Preprocessor) !void {
    try pp.addBuiltinMacro("__has_attribute", &FeatureCheckMacros.has_attribute);
    try pp.addBuiltinMacro("__has_warning", &FeatureCheckMacros.has_warning);
    try pp.addBuiltinMacro("__is_identifier", &FeatureCheckMacros.is_identifier);
}

pub fn deinit(pp: *Preprocessor) void {
    pp.defines.deinit();
    pp.tokens.deinit(pp.comp.gpa);
    pp.arena.deinit();
    pp.generated.deinit();
    pp.token_buf.deinit();
    pp.char_buf.deinit();
    pp.poisoned_identifiers.deinit();
}

/// Preprocess a source file.
pub fn preprocess(pp: *Preprocessor, source: Source) Error!void {
    pp.preprocess_count += 1;
    var tokenizer = Tokenizer{
        .buf = source.buf,
        .comp = pp.comp,
        .source = source.id,
    };
    const TRAILING_WS = " \r\t\x0B\x0C";

    // Estimate how many new tokens this source will contain.
    const estimated_token_count = source.buf.len / 8;
    try pp.tokens.ensureCapacity(pp.comp.gpa, pp.tokens.len + estimated_token_count);

    var if_level: u8 = 0;
    var if_kind = std.PackedIntArray(u2, 256).init([1]u2{0} ** 256);
    const until_else = 0;
    const until_endif = 1;
    const until_endif_seen_else = 2;

    var start_of_line = true;
    while (true) {
        var tok = tokenizer.next();
        switch (tok.id) {
            .hash => if (start_of_line) {
                const directive = tokenizer.next();
                switch (directive.id) {
                    .keyword_error => {
                        // #error tokens..
                        const start = tokenizer.index;
                        while (tokenizer.index < tokenizer.buf.len) : (tokenizer.index += 1) {
                            if (tokenizer.buf[tokenizer.index] == '\n') break;
                        }
                        var slice = tokenizer.buf[start..tokenizer.index];
                        slice = mem.trim(u8, slice, TRAILING_WS);
                        try pp.comp.addDiagnostic(.{
                            .tag = .error_directive,
                            .loc = .{ .id = tok.source, .byte_offset = tok.start },
                            .extra = .{ .str = slice },
                        });
                    },
                    .keyword_if => {
                        if (@addWithOverflow(u8, if_level, 1, &if_level))
                            return pp.comp.fatal(directive, "too many #if nestings", .{});

                        if (try pp.expr(&tokenizer)) {
                            if_kind.set(if_level, until_endif);
                        } else {
                            if_kind.set(if_level, until_else);
                            try pp.skip(&tokenizer, .until_else);
                        }
                    },
                    .keyword_ifdef => {
                        if (@addWithOverflow(u8, if_level, 1, &if_level))
                            return pp.comp.fatal(directive, "too many #if nestings", .{});

                        const macro_name = (try pp.expectMacroName(&tokenizer)) orelse continue;
                        try pp.expectNl(&tokenizer);
                        if (pp.defines.get(macro_name) != null) {
                            if_kind.set(if_level, until_endif);
                        } else {
                            if_kind.set(if_level, until_else);
                            try pp.skip(&tokenizer, .until_else);
                        }
                    },
                    .keyword_ifndef => {
                        if (@addWithOverflow(u8, if_level, 1, &if_level))
                            return pp.comp.fatal(directive, "too many #if nestings", .{});

                        const macro_name = (try pp.expectMacroName(&tokenizer)) orelse continue;
                        try pp.expectNl(&tokenizer);
                        if (pp.defines.get(macro_name) == null) {
                            if_kind.set(if_level, until_endif);
                        } else {
                            if_kind.set(if_level, until_else);
                            try pp.skip(&tokenizer, .until_else);
                        }
                    },
                    .keyword_elif => {
                        if (if_level == 0) {
                            try pp.err(directive, .elif_without_if);
                            if_level += 1;
                            if_kind.set(if_level, until_else);
                        }
                        switch (if_kind.get(if_level)) {
                            until_else => if (try pp.expr(&tokenizer)) {
                                if_kind.set(if_level, until_endif);
                            } else {
                                try pp.skip(&tokenizer, .until_else);
                            },
                            until_endif => try pp.skip(&tokenizer, .until_endif),
                            until_endif_seen_else => {
                                try pp.err(directive, .elif_after_else);
                                skipToNl(&tokenizer);
                            },
                            else => unreachable,
                        }
                    },
                    .keyword_else => {
                        try pp.expectNl(&tokenizer);
                        if (if_level == 0) {
                            try pp.err(directive, .else_without_if);
                            continue;
                        }
                        switch (if_kind.get(if_level)) {
                            until_else => if_kind.set(if_level, until_endif_seen_else),
                            until_endif => try pp.skip(&tokenizer, .until_endif_seen_else),
                            until_endif_seen_else => {
                                try pp.err(directive, .else_after_else);
                                skipToNl(&tokenizer);
                            },
                            else => unreachable,
                        }
                    },
                    .keyword_endif => {
                        try pp.expectNl(&tokenizer);
                        if (if_level == 0) {
                            try pp.err(directive, .endif_without_if);
                            continue;
                        }
                        if_level -= 1;
                    },
                    .keyword_define => try pp.define(&tokenizer),
                    .keyword_undef => {
                        const macro_name = (try pp.expectMacroName(&tokenizer)) orelse continue;

                        _ = pp.defines.remove(macro_name);
                        try pp.expectNl(&tokenizer);
                    },
                    .keyword_include => try pp.include(&tokenizer),
                    .keyword_pragma => pp.pragma(&tokenizer, directive) catch |err| switch (err) {
                        error.StopPreprocessing => return,
                        else => |e| return e,
                    },
                    .keyword_line => {
                        // #line number "file"
                        const digits = tokenizer.next();
                        if (digits.id != .integer_literal) try pp.err(digits, .line_simple_digit);
                        if (digits.id == .eof or digits.id == .nl) continue;
                        const name = tokenizer.next();
                        if (name.id == .eof or name.id == .nl) continue;
                        if (name.id != .string_literal) try pp.err(name, .line_invalid_filename);
                        try pp.expectNl(&tokenizer);
                    },
                    .nl => {},
                    .eof => {
                        if (if_level != 0) try pp.err(tok, .unterminated_conditional_directive);
                        return;
                    },
                    else => {
                        try pp.err(tok, .invalid_preprocessing_directive);
                        try pp.expectNl(&tokenizer);
                    },
                }
            },
            .nl => start_of_line = true,
            .eof => {
                if (if_level != 0) try pp.err(tok, .unterminated_conditional_directive);
                // The following check needs to occur here and not at the top of the function
                // because a pragma may change the level during preprocessing
                if (source.buf.len > 0 and source.buf[source.buf.len - 1] != '\n') {
                    try pp.err(tok, .newline_eof);
                }
                return;
            },
            else => {
                if (tok.id.isMacroIdentifier() and pp.poisoned_identifiers.get(pp.tokSliceSafe(tok)) != null) {
                    try pp.err(tok, .poisoned_identifier);
                }
                // Add the token to the buffer doing any necessary expansions.
                start_of_line = false;
                tok.id.simplifyMacroKeyword();
                try pp.expandMacro(&tokenizer, tok);
            },
        }
    }
}

pub fn tokSliceSafe(pp: *Preprocessor, token: RawToken) []const u8 {
    if (token.id.lexeme()) |some| return some;
    assert(token.source != .generated);
    return pp.comp.getSource(token.source).buf[token.start..token.end];
}

/// Returned slice is invalidated when generated is updated.
fn tokSlice(pp: *Preprocessor, token: RawToken) []const u8 {
    if (token.id.lexeme()) |some| return some;
    if (token.source == .generated) {
        return pp.generated.items[token.start..token.end];
    } else {
        const source = pp.comp.getSource(token.source);
        return source.buf[token.start..token.end];
    }
}

/// Convert a token from the Tokenizer into a token used by the parser.
fn tokFromRaw(raw: RawToken) Token {
    return .{
        .id = raw.id,
        .loc = .{
            .id = raw.source,
            .byte_offset = raw.start,
        },
    };
}

fn err(pp: *Preprocessor, raw: RawToken, tag: Diagnostics.Tag) !void {
    try pp.comp.addDiagnostic(.{
        .tag = tag,
        .loc = .{
            .id = raw.source,
            .byte_offset = raw.start,
        },
    });
}

/// Consume next token, error if it is not an identifier.
fn expectMacroName(pp: *Preprocessor, tokenizer: *Tokenizer) Error!?[]const u8 {
    const macro_name = tokenizer.next();
    if (!macro_name.id.isMacroIdentifier()) {
        try pp.err(macro_name, .macro_name_missing);
        skipToNl(tokenizer);
        return null;
    }
    return pp.tokSliceSafe(macro_name);
}

/// Skip until after a newline, error if extra tokens before it.
fn expectNl(pp: *Preprocessor, tokenizer: *Tokenizer) Error!void {
    var sent_err = false;
    while (true) {
        const tok = tokenizer.next();
        if (tok.id == .nl or tok.id == .eof) return;
        if (!sent_err) {
            sent_err = true;
            try pp.err(tok, .extra_tokens_directive_end);
        }
    }
}

/// Consume all tokens until a newline and parse the result into a boolean.
fn expr(pp: *Preprocessor, tokenizer: *Tokenizer) Error!bool {
    const start = pp.tokens.len;
    defer pp.tokens.len = start;

    while (true) {
        var tok = tokenizer.next();
        if (tok.id == .nl or tok.id == .eof) {
            if (pp.tokens.len == start) {
                try pp.err(tok, .expected_value_in_expr);
                try pp.expectNl(tokenizer);
                return false;
            }
            tok.id = .eof;
            try pp.tokens.append(pp.comp.gpa, tokFromRaw(tok));
            break;
        } else if (tok.id == .keyword_defined) {
            const first = tokenizer.next();
            const macro_tok = if (first.id == .l_paren)
                tokenizer.next()
            else
                first;
            if (!macro_tok.id.isMacroIdentifier()) try pp.err(macro_tok, .macro_name_missing);
            if (first.id == .l_paren) {
                const r_paren = tokenizer.next();
                if (r_paren.id != .r_paren) {
                    try pp.err(r_paren, .closing_paren);
                    try pp.err(first, .to_match_paren);
                }
            }
            if (pp.defines.get(pp.tokSliceSafe(macro_tok)) != null) {
                tok.id = .one;
            } else {
                tok.id = .zero;
            }
        }
        try pp.expandMacro(tokenizer, tok);
    }

    // validate the tokens in the expression
    for (pp.tokens.items(.id)[start..]) |*id, i| {
        switch (id.*) {
            .string_literal,
            .string_literal_utf_16,
            .string_literal_utf_8,
            .string_literal_utf_32,
            .string_literal_wide,
            => {
                try pp.comp.addDiagnostic(.{
                    .tag = .string_literal_in_pp_expr,
                    .loc = pp.tokens.items(.loc)[i],
                });
                return false;
            },
            .float_literal,
            .float_literal_f,
            .float_literal_l,
            => {
                try pp.comp.addDiagnostic(.{
                    .tag = .float_literal_in_pp_expr,
                    .loc = pp.tokens.items(.loc)[i],
                });
                return false;
            },
            else => if (id.isMacroIdentifier()) {
                id.* = .zero; // undefined macro
            },
        }
    }

    // Actually parse it.
    var parser = Parser{
        .pp = pp,
        .tok_ids = pp.tokens.items(.id),
        .tok_i = @intCast(u32, start),
        .arena = &pp.arena.allocator,
        .in_macro = true,
        .data = undefined,
        .strings = undefined,
        .value_map = undefined,
        .scopes = undefined,
        .labels = undefined,
        .decl_buf = undefined,
        .list_buf = undefined,
        .param_buf = undefined,
        .enum_buf = undefined,
        .record_buf = undefined,
        .attr_buf = undefined,
    };
    return parser.macroExpr();
}

/// Skip until #else #elif #endif, return last directive token id.
/// Also skips nested #if ... #endifs.
fn skip(
    pp: *Preprocessor,
    tokenizer: *Tokenizer,
    cont: enum { until_else, until_endif, until_endif_seen_else },
) Error!void {
    var ifs_seen: u32 = 0;
    var line_start = true;
    while (tokenizer.index < tokenizer.buf.len) {
        if (line_start) {
            const dir_start = tokenizer.index;
            const hash = tokenizer.next();
            if (hash.id == .nl) continue;
            line_start = false;
            if (hash.id != .hash) continue;
            const directive = tokenizer.next();
            switch (directive.id) {
                .keyword_else => {
                    if (ifs_seen != 0) continue;
                    if (cont == .until_endif_seen_else) {
                        try pp.err(directive, .else_after_else);
                        continue;
                    }
                    tokenizer.index = dir_start;
                    return;
                },
                .keyword_elif => {
                    if (ifs_seen != 0 or cont == .until_endif) continue;
                    if (cont == .until_endif_seen_else) {
                        try pp.err(directive, .elif_after_else);
                        continue;
                    }
                    tokenizer.index = dir_start;
                    return;
                },
                .keyword_endif => {
                    if (ifs_seen == 0) {
                        tokenizer.index = dir_start;
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
        } else {
            line_start = false;
            tokenizer.index += 1;
        }
    } else {
        const eof = tokenizer.next();
        return pp.err(eof, .unterminated_conditional_directive);
    }
}

// Skip until newline, ignore other tokens.
fn skipToNl(tokenizer: *Tokenizer) void {
    while (true) {
        const tok = tokenizer.next();
        if (tok.id == .nl or tok.id == .eof) return;
    }
}

const ExpandBuf = std.ArrayList(Token);
const MacroArguments = std.ArrayList([]const Token);
fn deinitMacroArguments(allocator: *Allocator, args: *const MacroArguments) void {
    for (args.items) |item| {
        allocator.free(item);
    }
    args.deinit();
}

fn expandObjMacro(pp: *Preprocessor, simple_macro: *const Macro) Error!ExpandBuf {
    var buf = ExpandBuf.init(pp.comp.gpa);
    try buf.ensureCapacity(simple_macro.tokens.len);

    // Add all of the simple_macros tokens to the new buffer handling any concats.
    var i: usize = 0;
    while (i < simple_macro.tokens.len) : (i += 1) {
        const raw = simple_macro.tokens[i];
        if (raw.id == .hash_hash) {
            const lhs = buf.pop();
            const rhs = tokFromRaw(simple_macro.tokens[i + 1]);
            i += 1;
            buf.appendAssumeCapacity(try pp.pasteTokens(lhs, rhs));
        } else {
            buf.appendAssumeCapacity(tokFromRaw(raw));
        }
    }

    return buf;
}

/// Join a possibly-parenthesized series of string literal tokens into a single string without
/// leading or trailing quotes. The returned slice is invalidated if pp.char_buf changes.
/// Returns error.ExpectedStringLiteral if parentheses are not balanced, a non-string-literal
/// is encountered, or if no string literals are encountered
/// TODO: destringize (replace all '\\' with a single `\` and all '\"' with a '"')
fn pasteStringsUnsafe(pp: *Preprocessor, toks: []const Token) ![]const u8 {
    const char_top = pp.char_buf.items.len;
    defer pp.char_buf.items.len = char_top;
    var unwrapped = toks;
    if (toks.len >= 2 and toks[0].id == .l_paren and toks[toks.len - 1].id == .r_paren) {
        unwrapped = toks[1 .. toks.len - 1];
    }
    if (unwrapped.len == 0) return error.ExpectedStringLiteral;

    for (unwrapped) |tok| {
        if (tok.id != .string_literal) return error.ExpectedStringLiteral;
        const str = pp.expandedSlice(tok);
        try pp.char_buf.appendSlice(str[1 .. str.len - 1]);
    }
    return pp.char_buf.items[char_top..];
}

fn handleBuiltinMacro(pp: *Preprocessor, builtin: RawToken.Id, param_toks: []const Token) Error!RawToken.Id {
    switch (builtin) {
        .macro_param_has_attribute => {
            if (param_toks.len != 1 or param_toks[0].id != .identifier) {
                try pp.comp.addDiagnostic(.{ .tag = .feature_check_requires_identifier, .loc = param_toks[0].loc });
                return .zero;
            }
            const attr_name = pp.expandedSlice(param_toks[0]);
            return if (AttrTag.fromString(attr_name) == null) .zero else .one;
        },
        .macro_param_has_warning => {
            const actual_param = pp.pasteStringsUnsafe(param_toks) catch |err| switch (err) {
                error.ExpectedStringLiteral => {
                    try pp.comp.addDiagnostic(.{
                        .tag = .expected_str_literal_in,
                        .loc = param_toks[0].loc,
                        .extra = .{ .str = "__has_warning" },
                    });
                    return .zero;
                },
                else => |e| return e,
            };
            if (!mem.startsWith(u8, actual_param, "-W")) {
                try pp.comp.addDiagnostic(.{
                    .tag = .malformed_warning_check,
                    .loc = param_toks[0].loc,
                    .extra = .{ .str = "__has_warning" },
                });
                return .zero;
            }
            const warning_name = actual_param[2..];
            return if (Diagnostics.warningExists(warning_name)) .one else .zero;
        },
        .macro_param_is_identifier => {
            if (param_toks.len > 1) {
                const extra = Diagnostics.Message.Extra{ .tok_id = .{ .expected = .r_paren, .actual = param_toks[1].id } };
                try pp.comp.addDiagnostic(.{ .tag = .missing_tok_builtin, .loc = param_toks[1].loc, .extra = extra });
                return .zero;
            }
            return if (param_toks[0].id == .identifier) .one else .zero;
        },
        else => unreachable,
    }
}

fn expandFuncMacro(
    pp: *Preprocessor,
    loc: Source.Location,
    func_macro: *const Macro,
    args: *const MacroArguments,
    expanded_args: *const MacroArguments,
) Error!ExpandBuf {
    var buf = ExpandBuf.init(pp.comp.gpa);
    try buf.ensureCapacity(func_macro.tokens.len);

    var expanded_variable_arguments = ExpandBuf.init(pp.comp.gpa);
    defer expanded_variable_arguments.deinit();
    var variable_arguments = ExpandBuf.init(pp.comp.gpa);
    defer variable_arguments.deinit();

    if (func_macro.var_args) {
        var i: usize = func_macro.params.len;
        while (i < expanded_args.items.len) : (i += 1) {
            try variable_arguments.appendSlice(args.items[i]);
            try expanded_variable_arguments.appendSlice(expanded_args.items[i]);
            if (i != expanded_args.items.len - 1) {
                const comma = Token{ .id = .comma, .loc = .{
                    .id = .generated,
                } };
                try variable_arguments.append(comma);
                try expanded_variable_arguments.append(comma);
            }
        }
    }

    // token concatenation and expansion phase
    var tok_i: usize = 0;
    while (tok_i < func_macro.tokens.len) : (tok_i += 1) {
        const raw = func_macro.tokens[tok_i];
        switch (raw.id) {
            .hash_hash => {
                const raw_next = func_macro.tokens[tok_i + 1];
                const placeholder_token = Token{ .id = .empty_arg, .loc = .{ .id = raw_next.source, .byte_offset = raw_next.start } };

                const prev = buf.pop();
                var next = switch (raw_next.id) {
                    .macro_param, .macro_param_no_expand => args.items[raw_next.end],
                    .keyword_va_args => variable_arguments.items,
                    else => &[1]Token{tokFromRaw(raw_next)},
                };
                next = if (next.len > 0) next else &[1]Token{placeholder_token};

                var pastedToken = try pp.pasteTokens(prev, next[0]);
                try buf.append(pastedToken);
                try buf.appendSlice(next[1..]);
                // skip next token
                tok_i += 1;
            },
            .macro_param_no_expand => {
                const placeholder_token = Token{ .id = .empty_arg, .loc = .{ .id = raw.source, .byte_offset = raw.start } };
                var slice = switch (raw.id) {
                    .macro_param_no_expand => args.items[raw.end],
                    .keyword_va_args => variable_arguments.items,
                    else => &[1]Token{tokFromRaw(raw)},
                };
                slice = if (slice.len > 0) slice else &[1]Token{placeholder_token};

                try buf.appendSlice(slice);
            },
            .macro_param => {
                const arg = expanded_args.items[raw.end];

                if (arg.len == 0) {
                    // needed for the following token pasting phase
                    try buf.append(.{ .id = .empty_arg, .loc = .{ .id = raw.source, .byte_offset = raw.start } });
                } else {
                    for (arg) |tok| {
                        try buf.ensureCapacity(buf.items.len + arg.len);
                        buf.appendAssumeCapacity(tok);
                    }
                }
            },
            .keyword_va_args => {
                try buf.ensureCapacity(buf.items.len + expanded_variable_arguments.items.len);
                buf.appendSliceAssumeCapacity(expanded_variable_arguments.items);
            },
            .stringify_param, .stringify_va_args => {
                const arg = if (raw.id == .stringify_va_args)
                    variable_arguments.items
                else
                    args.items[raw.end];

                pp.char_buf.clearRetainingCapacity();
                // TODO pretty print these
                try pp.char_buf.append('"');
                for (arg) |tok| {
                    for (pp.expandedSlice(tok)) |c| {
                        if (c == '"')
                            try pp.char_buf.appendSlice("\\\"")
                        else if (c == '\\')
                            try pp.char_buf.appendSlice("\\\\")
                        else
                            try pp.char_buf.append(c);
                    }
                }
                try pp.char_buf.appendSlice("\"\n");

                const start = pp.generated.items.len;
                try pp.generated.appendSlice(pp.char_buf.items);

                try buf.append(.{
                    .id = .string_literal,
                    .loc = .{ // location of token slice in the generated buffer
                        .id = .generated,
                        .byte_offset = @intCast(u32, start),
                    },
                });
            },
            .macro_param_has_attribute, .macro_param_has_warning, .macro_param_is_identifier => {
                const arg = expanded_args.items[0];
                if (arg.len == 0) {
                    const extra = Diagnostics.Message.Extra{ .arguments = .{ .expected = 1, .actual = 0 } };
                    try pp.comp.addDiagnostic(.{ .tag = .expected_arguments, .loc = loc, .extra = extra });
                    try buf.append(.{ .id = .zero, .loc = loc });
                    break;
                }
                const result_id = try pp.handleBuiltinMacro(raw.id, arg);
                try buf.append(.{
                    .id = result_id,
                    .loc = loc,
                });
            },
            else => {
                try buf.append(tokFromRaw(raw));
            },
        }
    }

    return buf;
}

fn shouldExpand(tok: Token, macro: *Macro) bool {
    const macro_loc = macro.*.loc;
    var maybe_loc = tok.loc.next;
    while (maybe_loc) |loc| {
        if (loc.id == macro_loc.id and loc.byte_offset == macro_loc.byte_offset) {
            return false;
        }
        maybe_loc = loc.next;
    }

    return true;
}

fn nextBufToken(pp: *Preprocessor, tokenizer: *Tokenizer, buf: *ExpandBuf, start_idx: *usize, end_idx: *usize, extend_buf: bool) Error!Token {
    start_idx.* += 1;
    if (start_idx.* == buf.items.len and start_idx.* == end_idx.*) {
        if (extend_buf) {
            const raw_tok = tokenizer.next();
            if (raw_tok.id.isMacroIdentifier() and pp.poisoned_identifiers.get(pp.tokSliceSafe(raw_tok)) != null) {
                try pp.err(raw_tok, .poisoned_identifier);
            }
            const new_tok = tokFromRaw(raw_tok);
            end_idx.* += 1;
            try buf.append(new_tok);
            return new_tok;
        } else {
            return Token{
                .id = .eof,
                .loc = .{
                    .id = .generated,
                },
            };
        }
    } else {
        return buf.items[start_idx.*];
    }
}

fn collectMacroFuncArguments(
    pp: *Preprocessor,
    tokenizer: *Tokenizer,
    buf: *ExpandBuf,
    start_idx: *usize,
    end_idx: *usize,
    extend_buf: bool,
    is_builtin: bool,
) Error!(?MacroArguments) {
    const name_tok = buf.items[start_idx.*];
    const initial_tokenizer_index = tokenizer.index;
    const old_end = end_idx.*;

    while (true) {
        const tok = try nextBufToken(pp, tokenizer, buf, start_idx, end_idx, extend_buf);
        switch (tok.id) {
            .nl => {},
            .l_paren => break,
            else => {
                if (is_builtin) {
                    const extra = Diagnostics.Message.Extra{ .tok_id = .{ .expected = .l_paren, .actual = tok.id } };
                    try pp.comp.addDiagnostic(.{ .tag = .missing_tok_builtin, .loc = tok.loc, .extra = extra });
                }
                // Not a macro function call, go over normal identifier, rewind
                tokenizer.index = initial_tokenizer_index;
                end_idx.* = old_end;
                return null;
            },
        }
    }

    // collect the arguments.
    var parens: u32 = 0;
    var args = MacroArguments.init(pp.comp.gpa);
    errdefer deinitMacroArguments(pp.comp.gpa, &args);
    var curArgument = std.ArrayList(Token).init(pp.comp.gpa);
    defer curArgument.deinit();
    var done = false;
    while (!done) {
        var tok = try nextBufToken(pp, tokenizer, buf, start_idx, end_idx, extend_buf);
        switch (tok.id) {
            .comma => {
                if (parens == 0) {
                    try args.append(curArgument.toOwnedSlice());
                } else {
                    try curArgument.append(tok);
                }
            },
            .l_paren => {
                try curArgument.append(tok);
                parens += 1;
            },
            .r_paren => {
                if (parens == 0) {
                    try args.append(curArgument.toOwnedSlice());
                    break;
                } else {
                    try curArgument.append(tok);
                    parens -= 1;
                }
            },
            .eof => {
                deinitMacroArguments(pp.comp.gpa, &args);
                tokenizer.index = initial_tokenizer_index;
                end_idx.* = old_end;
                try pp.comp.addDiagnostic(.{ .tag = .unterminated_macro_arg_list, .loc = name_tok.loc });
                return null;
            },
            else => {
                try curArgument.append(tok);
            },
        }
    }

    return args;
}

fn expandMacroExhaustive(pp: *Preprocessor, tokenizer: *Tokenizer, buf: *ExpandBuf, start_idx: usize, end_idx: usize, extend_buf: bool) Error!void {
    var moving_end_idx = end_idx;
    var advance_index: usize = 0;
    // rescan loop
    var do_rescan = true;
    while (do_rescan) {
        // last phase before rescan: remove placeholder tokens
        // NOTE: only do this if there were expansion (i.e. do_rescan is true)
        if (do_rescan) {
            var i: usize = start_idx;
            while (i < buf.items.len) {
                const tok = &buf.items[i];
                switch (tok.id) {
                    .empty_arg => {
                        _ = buf.orderedRemove(i);
                        moving_end_idx -= 1;
                    },
                    else => i += 1,
                }
            }
        }

        do_rescan = false;
        // expansion loop
        var idx: usize = start_idx + advance_index;
        while (idx < moving_end_idx) {
            const macro_tok = buf.items[idx];
            const macro_entry = pp.defines.getPtr(pp.expandedSlice(macro_tok));
            if (macro_entry == null or !shouldExpand(buf.items[idx], macro_entry.?)) {
                idx += 1;
                continue;
            }
            if (macro_entry) |macro| macro_handler: {
                if (macro.is_func) {
                    var macro_scan_idx = idx;
                    // to be saved in case this doesn't turn out to be a call
                    const args = (try pp.collectMacroFuncArguments(tokenizer, buf, &macro_scan_idx, &moving_end_idx, extend_buf, macro.is_builtin)) orelse {
                        idx += 1;
                        break :macro_handler;
                    };
                    defer {
                        for (args.items) |item| {
                            pp.comp.gpa.free(item);
                        }
                        args.deinit();
                    }

                    var args_count = @intCast(u32, args.items.len);
                    // if the macro has zero arguments g() args_count is still 1
                    if (args_count == 1 and macro.params.len == 0) args_count = 0;

                    // Validate argument count.
                    const extra = Diagnostics.Message.Extra{ .arguments = .{ .expected = @intCast(u32, macro.params.len), .actual = args_count } };
                    if (macro.var_args and args_count < macro.params.len) {
                        try pp.comp.addDiagnostic(.{ .tag = .expected_at_least_arguments, .loc = buf.items[idx].loc, .extra = extra });
                        idx += 1;
                        continue;
                    }
                    if (!macro.var_args and args_count != macro.params.len) {
                        try pp.comp.addDiagnostic(.{ .tag = .expected_arguments, .loc = buf.items[idx].loc, .extra = extra });
                        idx += 1;
                        continue;
                    }
                    var expanded_args = MacroArguments.init(pp.comp.gpa);
                    defer deinitMacroArguments(pp.comp.gpa, &expanded_args);
                    try expanded_args.ensureCapacity(args.items.len);
                    for (args.items) |arg| {
                        var expand_buf = ExpandBuf.init(pp.comp.gpa);
                        try expand_buf.appendSlice(arg);

                        try pp.expandMacroExhaustive(tokenizer, &expand_buf, 0, expand_buf.items.len, false);

                        expanded_args.appendAssumeCapacity(expand_buf.toOwnedSlice());
                    }

                    var res = try pp.expandFuncMacro(macro_tok.loc, macro, &args, &expanded_args);
                    defer res.deinit();
                    var expansion_loc = macro.loc;
                    expansion_loc.next = buf.items[idx].loc.next;
                    for (res.items) |*tok| {
                        if (buf.items[idx].loc.next) |ln| {
                            try pp.markExpandedFrom(tok, ln.*);
                        }
                        try pp.markExpandedFrom(tok, macro.loc);
                    }

                    try buf.replaceRange(idx, macro_scan_idx - idx + 1, res.items);
                    // TODO: moving_end_idx += res.items.len - (macro_scan_idx-idx+1)
                    // doesn't work when the RHS is negative (unsigned!)
                    moving_end_idx = moving_end_idx + res.items.len - (macro_scan_idx - idx + 1);
                    idx += res.items.len;
                    do_rescan = true;
                } else {
                    const res = try pp.expandObjMacro(macro);
                    defer res.deinit();
                    var expansion_loc = macro.loc;
                    expansion_loc.next = buf.items[idx].loc.next;
                    for (res.items) |*tok| {
                        if (buf.items[idx].loc.next) |ln| {
                            try pp.markExpandedFrom(tok, ln.*);
                        }
                        try pp.markExpandedFrom(tok, macro.loc);
                    }

                    try buf.replaceRange(idx, 1, res.items);
                    idx += res.items.len;
                    moving_end_idx = moving_end_idx + res.items.len - 1;
                    do_rescan = true;
                }
            }
            if (idx - start_idx == advance_index + 1 and !do_rescan) {
                advance_index += 1;
            }
        } // end of replacement phase
    }
    // end of scanning phase

    // trim excess buffer
    buf.shrinkAndFree(moving_end_idx);
}

/// Try to expand a macro after a possible candidate has been read from the `tokenizer`
/// into the `raw` token passed as argument
fn expandMacro(pp: *Preprocessor, tokenizer: *Tokenizer, raw: RawToken) Error!void {
    var buf = ExpandBuf.init(pp.comp.gpa);
    defer buf.deinit();
    try buf.append(tokFromRaw(raw));

    try pp.expandMacroExhaustive(tokenizer, &buf, 0, 1, true);
    try pp.tokens.ensureCapacity(pp.comp.gpa, pp.tokens.len + buf.items.len);
    for (buf.items) |*r| {
        pp.tokens.appendAssumeCapacity(r.*);
    }
}

// mark that this token has been expanded from `loc`
fn markExpandedFrom(pp: *Preprocessor, tok: *Token, loc: Source.Location) !void {
    if (loc.id == .generated) return;
    const new_loc = try pp.arena.allocator.create(Source.Location);
    new_loc.* = loc;
    new_loc.next = tok.loc.next;
    tok.loc.next = new_loc;
}

// TODO there are like 5 tokSlice functions, can we combine them somehow.
pub fn expandedSlice(pp: *Preprocessor, tok: Token) []const u8 {
    if (tok.id.lexeme()) |some| return some;
    var tmp_tokenizer = Tokenizer{
        .buf = if (tok.loc.id == .generated)
            pp.generated.items
        else
            pp.comp.getSource(tok.loc.id).buf,
        .comp = pp.comp,
        .index = tok.loc.byte_offset,
        .source = .generated,
    };
    if (tok.id == .macro_string) {
        while (true) : (tmp_tokenizer.index += 1) {
            if (tmp_tokenizer.buf[tmp_tokenizer.index] == '>') break;
        }
        return tmp_tokenizer.buf[tok.loc.byte_offset .. tmp_tokenizer.index + 1];
    }
    const res = tmp_tokenizer.next();
    return tmp_tokenizer.buf[res.start..res.end];
}

/// Concat two tokens and add the result to pp.generated
fn pasteTokens(pp: *Preprocessor, lhs: Token, rhs: Token) Error!Token {
    if (lhs.id == .empty_arg) {
        return rhs;
    } else if (rhs.id == .empty_arg) {
        return lhs;
    }

    const start = pp.generated.items.len;
    const end = start + pp.expandedSlice(lhs).len + pp.expandedSlice(rhs).len;
    try pp.generated.ensureCapacity(end + 1); // +1 for a newline
    // We cannot use the same slices here since they might be invalidated by `ensureCapacity`
    pp.generated.appendSliceAssumeCapacity(pp.expandedSlice(lhs));
    pp.generated.appendSliceAssumeCapacity(pp.expandedSlice(rhs));
    pp.generated.appendAssumeCapacity('\n');

    // Try to tokenize the result.
    var tmp_tokenizer = Tokenizer{
        .buf = pp.generated.items,
        .comp = pp.comp,
        .index = @intCast(u32, start),
        .source = .generated,
    };
    const pasted_token = tmp_tokenizer.next();
    const next = tmp_tokenizer.next().id;
    if (next != .nl and next != .eof) {
        try pp.comp.addDiagnostic(.{
            .tag = .pasting_formed_invalid,
            .loc = .{ .id = lhs.loc.id, .byte_offset = lhs.loc.byte_offset },
            .extra = .{ .str = try pp.arena.allocator.dupe(u8, pp.generated.items[start..end]) },
        });
    }

    return Token{
        .id = pasted_token.id,
        .loc = .{ // location of token slice in the generated buffer
            .id = .generated,
            .byte_offset = @intCast(u32, start),
        },
    };
}

/// Defines a new macro and warns if it is a duplicate
fn defineMacro(pp: *Preprocessor, name_tok: RawToken, macro: Macro) Error!void {
    const name_str = pp.tokSliceSafe(name_tok);
    const gop = try pp.defines.getOrPut(name_str);
    if (gop.found_existing and !gop.value_ptr.eql(macro, pp)) {
        try pp.comp.addDiagnostic(.{
            .tag = if (gop.value_ptr.is_builtin) .builtin_macro_redefined else .macro_redefined,
            .loc = .{ .id = name_tok.source, .byte_offset = name_tok.start },
            .extra = .{ .str = name_str },
        });
        // TODO add a previous definition note
    }
    gop.value_ptr.* = macro;
}

/// Handle a #define directive.
fn define(pp: *Preprocessor, tokenizer: *Tokenizer) Error!void {
    // Get macro name and validate it.
    const macro_name = tokenizer.next();
    if (macro_name.id == .keyword_defined) {
        try pp.err(macro_name, .defined_as_macro_name);
        return skipToNl(tokenizer);
    }
    if (!macro_name.id.isMacroIdentifier()) {
        try pp.err(macro_name, .macro_name_must_be_identifier);
        return skipToNl(tokenizer);
    }

    // Check for function macros and empty defines.
    var first = tokenizer.next();
    first.id.simplifyMacroKeyword();
    if (first.id == .nl or first.id == .eof) {
        return pp.defineMacro(macro_name, .{
            .params = undefined,
            .tokens = undefined,
            .var_args = false,
            .loc = undefined,
            .is_func = false,
        });
    } else if (first.start == macro_name.end) {
        if (first.id == .l_paren) return pp.defineFn(tokenizer, macro_name, first);
        try pp.err(first, .whitespace_after_macro_name);
    } else if (first.id == .hash_hash) {
        try pp.err(first, .hash_hash_at_start);
    }

    pp.token_buf.items.len = 0; // Safe to use since we can only be in one directive at a time.
    try pp.token_buf.append(first);

    // Collect the token body and validate any ## found.
    while (true) {
        var tok = tokenizer.next();
        tok.id.simplifyMacroKeyword();
        switch (tok.id) {
            .hash_hash => {
                const next = tokenizer.next();
                if (next.id == .nl or next.id == .eof) {
                    try pp.err(tok, .hash_hash_at_end);
                    break;
                }
                try pp.token_buf.append(tok);
                try pp.token_buf.append(next);
            },
            .nl, .eof => break,
            else => try pp.token_buf.append(tok),
        }
    }

    const list = try pp.arena.allocator.dupe(RawToken, pp.token_buf.items);
    try pp.defineMacro(macro_name, .{
        .loc = .{ .id = macro_name.source, .byte_offset = macro_name.start },
        .tokens = list,
        .params = undefined,
        .is_func = false,
        .var_args = false,
    });
}

/// Handle a function like #define directive.
fn defineFn(pp: *Preprocessor, tokenizer: *Tokenizer, macro_name: RawToken, l_paren: RawToken) Error!void {
    assert(macro_name.id.isMacroIdentifier());
    var params = std.ArrayList([]const u8).init(pp.comp.gpa);
    defer params.deinit();

    // Parse the parameter list.
    var var_args = false;
    while (true) {
        var tok = tokenizer.next();
        if (tok.id == .r_paren) break;
        if (params.items.len != 0) {
            if (tok.id != .comma)
                try pp.err(tok, .invalid_token_param_list)
            else
                tok = tokenizer.next();
        }
        if (tok.id == .eof) return pp.err(tok, .unterminated_macro_param_list);
        if (tok.id == .ellipsis) {
            var_args = true;
            const r_paren = tokenizer.next();
            if (r_paren.id != .r_paren) {
                try pp.err(r_paren, .missing_paren_param_list);
                try pp.err(l_paren, .to_match_paren);
            }
            break;
        }
        if (!tok.id.isMacroIdentifier()) {
            try pp.err(tok, .invalid_token_param_list);
            continue;
        }

        try params.append(pp.tokSliceSafe(tok));
    }

    // Collect the body tokens and validate # and ##'s found.
    pp.token_buf.items.len = 0; // Safe to use since we can only be in one directive at a time.
    tok_loop: while (true) {
        var tok = tokenizer.next();
        switch (tok.id) {
            .nl, .eof => break,
            .hash => {
                const param = tokenizer.next();
                blk: {
                    if (var_args and param.id == .keyword_va_args) {
                        tok.id = .stringify_va_args;
                        try pp.token_buf.append(tok);
                        continue :tok_loop;
                    }
                    if (!param.id.isMacroIdentifier()) break :blk;
                    const s = pp.tokSliceSafe(param);
                    for (params.items) |p, i| {
                        if (mem.eql(u8, p, s)) {
                            tok.id = .stringify_param;
                            tok.end = @intCast(u32, i);
                            try pp.token_buf.append(tok);
                            continue :tok_loop;
                        }
                    }
                }
                try pp.err(param, .hash_not_followed_param);
                tok = param;
            },
            .hash_hash => {
                // if ## appears at the beginning, the token buf is still empty
                // in this case, error out
                if (pp.token_buf.items.len == 0) {
                    try pp.err(tok, .hash_hash_at_start);
                    continue;
                }
                const start = tokenizer.index;
                const next = tokenizer.next();
                if (next.id == .nl or next.id == .eof) {
                    try pp.err(tok, .hash_hash_at_end);
                    continue;
                }
                tokenizer.index = start;
                // convert the previous token to .macro_param_no_expand if it was .macro_param
                if (pp.token_buf.items[pp.token_buf.items.len - 1].id == .macro_param) {
                    pp.token_buf.items[pp.token_buf.items.len - 1].id = .macro_param_no_expand;
                }
                try pp.token_buf.append(tok);
            },
            else => {
                if (var_args and tok.id == .keyword_va_args) {
                    // do nothing
                } else if (tok.id.isMacroIdentifier()) {
                    tok.id.simplifyMacroKeyword();
                    const s = pp.tokSliceSafe(tok);
                    for (params.items) |param, i| {
                        if (mem.eql(u8, param, s)) {
                            // NOTE: it doesn't matter to assign .macro_param_no_expand
                            // here in case a ## was the previous token, because
                            // ## processing will eat this token with the same semantics
                            tok.id = .macro_param;
                            tok.end = @intCast(u32, i);
                            break;
                        }
                    }
                }
                try pp.token_buf.append(tok);
            },
        }
    }

    const param_list = try pp.arena.allocator.dupe([]const u8, params.items);
    const token_list = try pp.arena.allocator.dupe(RawToken, pp.token_buf.items);
    try pp.defineMacro(macro_name, .{
        .is_func = true,
        .params = param_list,
        .var_args = var_args,
        .tokens = token_list,
        .loc = .{ .id = macro_name.source, .byte_offset = macro_name.start },
    });
}

// Handle a #include directive.
fn include(pp: *Preprocessor, tokenizer: *Tokenizer) Error!void {
    const new_source = findIncludeSource(pp, tokenizer) catch |er| switch (er) {
        error.InvalidInclude => return,
        else => |e| return e,
    };

    // Prevent stack overflow
    pp.include_depth += 1;
    defer pp.include_depth -= 1;
    if (pp.include_depth > max_include_depth) return;

    try pp.preprocess(new_source);
}

/// Handle a pragma directive
fn pragma(pp: *Preprocessor, tokenizer: *Tokenizer, pragma_tok: RawToken) !void {
    const name_tok = tokenizer.next();
    if (name_tok.id == .nl or name_tok.id == .eof) return;

    const name = pp.tokSlice(name_tok);
    try pp.tokens.append(pp.comp.gpa, tokFromRaw(pragma_tok));
    const pragma_start = @intCast(u32, pp.tokens.len);

    try pp.tokens.append(pp.comp.gpa, tokFromRaw(name_tok));
    while (true) {
        const next_tok = tokenizer.next();
        if (next_tok.id == .eof) {
            try pp.tokens.append(pp.comp.gpa, .{
                .id = .nl,
                .loc = .{ .id = .generated },
            });
            break;
        }
        try pp.tokens.append(pp.comp.gpa, tokFromRaw(next_tok));
        if (next_tok.id == .nl) break;
    }
    if (pp.comp.getPragma(name)) |prag| unknown: {
        return prag.preprocessorCB(pp, pragma_start) catch |err| switch (err) {
            error.UnknownPragma => break :unknown,
            else => |e| return e,
        };
    }
    return pp.comp.addDiagnostic(.{
        .tag = .unsupported_pragma,
        .loc = .{ .id = name_tok.source, .byte_offset = name_tok.start },
        .extra = .{ .str = name },
    });
}

fn findIncludeSource(pp: *Preprocessor, tokenizer: *Tokenizer) !Source {
    const start = pp.tokens.len;
    defer pp.tokens.len = start;

    var first = tokenizer.next();
    if (first.id == .angle_bracket_left) to_end: {
        // The tokenizer does not handle <foo> include strings so do it here.
        while (tokenizer.index < tokenizer.buf.len) : (tokenizer.index += 1) {
            switch (tokenizer.buf[tokenizer.index]) {
                '>' => {
                    tokenizer.index += 1;
                    first.end = tokenizer.index;
                    first.id = .macro_string;
                    break :to_end;
                },
                '\n' => break,
                else => {},
            }
        }
        try pp.comp.addDiagnostic(.{
            .tag = .header_str_closing,
            .loc = .{ .id = first.source, .byte_offset = first.start },
        });
        try pp.err(first, .header_str_match);
    }
    // Try to expand if the argument is a macro.
    try pp.expandMacro(tokenizer, first);

    // Check that we actually got a string.
    const filename_tok = pp.tokens.get(start);
    switch (filename_tok.id) {
        .string_literal, .macro_string => {},
        else => {
            try pp.err(first, .expected_filename);
            try pp.expectNl(tokenizer);
            return error.InvalidInclude;
        },
    }
    // Error on extra tokens.
    const nl = tokenizer.next();
    if ((nl.id != .nl and nl.id != .eof) or pp.tokens.len > start + 1) {
        skipToNl(tokenizer);
        try pp.err(first, .extra_tokens_directive_end);
    }

    // Check for empty filename.
    const tok_slice = pp.expandedSlice(filename_tok);
    if (tok_slice.len < 3) {
        try pp.err(first, .empty_filename);
        return error.InvalidInclude;
    }

    // Find the file.
    const filename = tok_slice[1 .. tok_slice.len - 1];
    return pp.comp.findInclude(first, filename, filename_tok.id == .string_literal);
}

/// Pretty print tokens and try to preserve whitespace.
pub fn prettyPrintTokens(pp: *Preprocessor, w: anytype) !void {
    var i: usize = 0;
    var cur: Token = pp.tokens.get(i);
    while (true) {
        if (cur.id == .eof) break;

        i += 1;
        const next = pp.tokens.get(i);
        if (cur.id == .nl) {
            cur = next;
            continue;
        }

        if (cur.id == .keyword_pragma) {
            const pragma_name = pp.expandedSlice(next);
            const end_idx = mem.indexOfScalarPos(Token.Id, pp.tokens.items(.id), i, .nl).?;
            const pragma_len = @intCast(u32, end_idx) - i;

            if (pp.comp.getPragma(pragma_name)) |prag| {
                if (!prag.shouldPreserveTokens(pp, @intCast(u32, i))) {
                    i += pragma_len;
                    cur = pp.tokens.get(i);
                    continue;
                }
            }
            try w.writeByte('#');
        }
        const slice = pp.expandedSlice(cur);
        try w.writeAll(slice);

        if (next.id == .eof or next.id == .keyword_pragma or next.id == .nl) {
            try w.writeByte('\n');
        } else if (next.loc.next != null or next.loc.id == .generated) {
            // next was expanded from a macro
            try w.writeByte(' ');
        } else if (next.loc.id == cur.loc.id) {
            // TODO fix this
            // const source = pp.comp.getSource(cur.loc.id).buf;
            // const cur_end = cur.loc.byte_offset + slice.len;
            // try printInBetween(source[cur_end..next.loc.byte_offset], w);
            try w.writeByte(' ');
        } else {
            // next was included from another file
            try w.writeByte('\n');
        }
        cur = next;
    }
}

fn printInBetween(slice: []const u8, w: anytype) !void {
    var in_between = slice;
    while (true) {
        if (mem.indexOfScalar(u8, in_between, '#') orelse mem.indexOf(u8, in_between, "//")) |some| {
            try w.writeAll(in_between[0..some]);
            in_between = in_between[some..];
            const nl = mem.indexOfScalar(u8, in_between, '\n') orelse in_between.len;
            in_between = in_between[nl..];
        } else if (mem.indexOf(u8, in_between, "/*")) |some| {
            try w.writeAll(in_between[0..some]);
            in_between = in_between[some..];
            const nl = mem.indexOf(u8, in_between, "*/") orelse in_between.len;
            in_between = in_between[nl + 2 ..];
        } else break;
    }
    try w.writeAll(in_between);
}

test "Preserve pragma tokens sometimes" {
    const allocator = std.testing.allocator;
    const Test = struct {
        fn runPreprocessor(source_text: []const u8) ![]const u8 {
            var buf = std.ArrayList(u8).init(allocator);
            defer buf.deinit();

            var comp = Compilation.init(allocator);
            defer comp.deinit();

            try comp.addDefaultPragmaHandlers();

            var pp = Preprocessor.init(&comp);
            defer pp.deinit();

            const test_runner_macros = blk: {
                const duped_path = try allocator.dupe(u8, "<test_runner>");
                errdefer comp.gpa.free(duped_path);

                const contents = try allocator.dupe(u8, source_text);
                errdefer comp.gpa.free(contents);

                const source = Source{
                    .id = @intToEnum(Source.Id, comp.sources.count() + 2),
                    .path = duped_path,
                    .buf = contents,
                };
                try comp.sources.put(duped_path, source);
                break :blk source;
            };

            try pp.preprocess(test_runner_macros);

            try pp.tokens.append(pp.comp.gpa, .{
                .id = .eof,
                .loc = .{ .id = test_runner_macros.id, .byte_offset = @intCast(u32, test_runner_macros.buf.len) },
            });
            try pp.prettyPrintTokens(buf.writer());
            return allocator.dupe(u8, buf.items);
        }

        fn check(source_text: []const u8, expected: []const u8) !void {
            const output = try runPreprocessor(source_text);
            defer allocator.free(output);

            try std.testing.expectEqualStrings(expected, output);
        }
    };
    // TODO: space between `x` and `;` is an artifact of token prettyprinting
    const preserve_gcc_diagnostic =
        \\#pragma GCC diagnostic error "-Wnewline-eof"
        \\#pragma GCC warning error "-Wnewline-eof"
        \\int x ;
        \\#pragma GCC ignored error "-Wnewline-eof"
        \\
    ;
    try Test.check(preserve_gcc_diagnostic, preserve_gcc_diagnostic);

    const omit_once =
        \\#pragma once
        \\int x ;
        \\#pragma once
        \\
    ;
    try Test.check(omit_once, "int x ;\n");

    const omit_poison =
        \\#pragma GCC poison foobar
        \\
    ;
    try Test.check(omit_poison, "");
}
