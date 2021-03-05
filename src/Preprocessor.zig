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

const Preprocessor = @This();
const DefineMap = std.StringHashMap(Macro);
const RawTokenList = std.ArrayList(RawToken);
const max_include_depth = 200;

const Macro = union(enum) {
    /// #define FOO
    empty,
    /// #define FOO FOO
    self,
    /// #define FOO a + b
    simple: struct {
        tokens: []const RawToken,
        loc: Source.Location,
    },
    /// #define FOO(a,b) ((a)+(b))
    func: Func,

    const Func = struct {
        params: []const []const u8,
        tokens: []const RawToken,
        var_args: bool,
        loc: Source.Location,
    };
};

comp: *Compilation,
arena: std.heap.ArenaAllocator,
defines: DefineMap,
tokens: Token.List = .{},
generated: std.ArrayList(u8),
token_buf: RawTokenList,
char_buf: std.ArrayList(u8),
pragma_once: std.AutoHashMap(Source.Id, void),
// It is safe to have pointers to entries of defines since it
// cannot be modified while we are expanding a macro.
expansion_log: std.AutoHashMap(*DefineMap.Entry, void),
include_depth: u8 = 0,

pub fn init(comp: *Compilation) Preprocessor {
    return .{
        .comp = comp,
        .arena = std.heap.ArenaAllocator.init(comp.gpa),
        .defines = DefineMap.init(comp.gpa),
        .generated = std.ArrayList(u8).init(comp.gpa),
        .token_buf = RawTokenList.init(comp.gpa),
        .char_buf = std.ArrayList(u8).init(comp.gpa),
        .pragma_once = std.AutoHashMap(Source.Id, void).init(comp.gpa),
        .expansion_log = std.AutoHashMap(*DefineMap.Entry, void).init(comp.gpa),
    };
}

pub fn deinit(pp: *Preprocessor) void {
    pp.defines.deinit();
    pp.tokens.deinit(pp.comp.gpa);
    pp.arena.deinit();
    pp.generated.deinit();
    pp.token_buf.deinit();
    pp.char_buf.deinit();
    pp.pragma_once.deinit();
    pp.expansion_log.deinit();
}

/// Preprocess a source file.
pub fn preprocess(pp: *Preprocessor, source: Source) Error!void {
    var tokenizer = Tokenizer{
        .buf = source.buf,
        .source = source.id,
    };

    // Estimate how many new tokens this source will contain.
    const estimated_token_count = source.buf.len / 8;
    try pp.tokens.ensureCapacity(pp.comp.gpa, pp.tokens.len + estimated_token_count);

    var if_level: u8 = 0;
    var if_kind = std.mem.zeroes(std.PackedIntArray(u2, 256));
    const until_else = 0;
    const until_endif = 1;
    const until_endif_seen_else = 2;
    var seen_pragma_once = false;

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
                        slice = mem.trim(u8, slice, " \t\x0B\x0C");
                        try pp.comp.diag.add(.{
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
                    .keyword_pragma => {
                        // #pragma tokens...
                        const start = tokenizer.index;
                        while (tokenizer.index < tokenizer.buf.len) : (tokenizer.index += 1) {
                            if (tokenizer.buf[tokenizer.index] == '\n') break;
                        }
                        var slice = tokenizer.buf[start..tokenizer.index];
                        slice = mem.trim(u8, slice, " \t\x0B\x0C");
                        if (mem.eql(u8, slice, "once")) {
                            const prev = try pp.pragma_once.fetchPut(tokenizer.source, {});
                            if (prev != null and !seen_pragma_once) {
                                return;
                            } else {
                                seen_pragma_once = true;
                            }
                        } else {
                            try pp.comp.diag.add(.{
                                .tag = .unsupported_pragma,
                                .loc = .{ .id = tok.source, .byte_offset = tok.start },
                                .extra = .{ .str = slice },
                            });
                        }
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
                        return pp.tokens.append(pp.comp.gpa, tokFromRaw(directive));
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
                return pp.tokens.append(pp.comp.gpa, tokFromRaw(tok));
            },
            else => {
                // Add the token to the buffer doing any necessary expansions.
                start_of_line = false;
                tok.id.simplifyMacroKeyword();
                try pp.expandMacro(&tokenizer, tok);
            },
        }
    }
}

fn tokSliceSafe(pp: *Preprocessor, token: RawToken) []const u8 {
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
    try pp.comp.diag.add(.{
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
            if (pp.defines.get(pp.tokSliceSafe(macro_tok))) |_| {
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
                try pp.comp.diag.add(.{
                    .tag = .string_literal_in_pp_expr,
                    .loc = pp.tokens.items(.loc)[i],
                });
                return false;
            },
            .float_literal,
            .float_literal_f,
            .float_literal_l,
            => {
                try pp.comp.diag.add(.{
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
        .cur_decl_list = undefined,
        .scopes = undefined,
        .data = undefined,
        .labels = undefined,
    };
    const res = parser.constExpr() catch |e| switch (e) {
        error.OutOfMemory => return error.OutOfMemory,
        error.FatalError => return error.FatalError,
        error.ParsingFailed => return false,
    };
    return res.getBool();
}

/// Skip until #else #elif #endif, return last directive token id.
/// Also skips nested #if ... #endif's.
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

/// Try to expand a macro.
fn expandMacro(pp: *Preprocessor, tokenizer: *Tokenizer, raw: RawToken) Error!void {
    if (pp.defines.getEntry(pp.tokSliceSafe(raw))) |some| switch (some.value) {
        .empty => return,
        .self => {},
        .simple => {
            pp.expansion_log.clearRetainingCapacity();
            var buf = ExpandBuf.init(pp.comp.gpa);
            defer buf.deinit();

            // Add the token to a new buffer and expand it.
            try buf.append(tokFromRaw(raw));
            var start_index: usize = 0;
            try pp.expandExtra(&buf, &start_index);

            // Add the resulting tokens to the token list and mark that they were expanded.
            try pp.tokens.ensureCapacity(pp.comp.gpa, pp.tokens.len + buf.items.len);
            const loc = Source.Location{ .id = raw.source, .byte_offset = raw.start };
            for (buf.items) |*r| {
                try pp.markExpandedFrom(r, loc);
                pp.tokens.appendAssumeCapacity(r.*);
            }
            return;
        },
        .func => |macro| blk: {
            const start = tokenizer.index;
            const l_paren = tokenizer.next();
            if (l_paren.id != .l_paren) {
                // If not followed by an argument list, continue as usual.
                tokenizer.index = start;
                break :blk;
            }
            pp.expansion_log.clearRetainingCapacity();
            var buf = ExpandBuf.init(pp.comp.gpa);
            defer buf.deinit();

            // Collect the macro name and arguments into a new buffer.
            try buf.append(tokFromRaw(raw));
            try buf.append(tokFromRaw(l_paren));
            var parens: u32 = 0;
            while (true) {
                const tok = tokenizer.next();
                switch (tok.id) {
                    .nl => continue,
                    .eof => {
                        try pp.err(tok, .unterminated_macro_arg_list);
                        return;
                    },
                    .l_paren => parens += 1,
                    .r_paren => {
                        if (parens == 0) {
                            try buf.append(tokFromRaw(tok));
                            break;
                        }
                        parens -= 1;
                    },
                    else => {},
                }
                try buf.append(tokFromRaw(tok));
            }
            var start_index: usize = 0;
            // Mark that we have seen this macro.
            try pp.expansion_log.putNoClobber(some, {});
            try pp.expandFunc(&buf, &start_index, macro);

            // Add the resulting tokens to the token list and mark that they were expanded.
            try pp.tokens.ensureCapacity(pp.comp.gpa, pp.tokens.len + buf.items.len);
            const loc = Source.Location{ .id = raw.source, .byte_offset = raw.start };
            for (buf.items) |*r| {
                try pp.markExpandedFrom(r, loc);
                pp.tokens.appendAssumeCapacity(r.*);
            }
            return;
        },
    };
    // Not a macro, continue as usual.
    try pp.tokens.append(pp.comp.gpa, tokFromRaw(raw));
}

/// Try to expand a macro in the `source` buffer at `start_index`.
fn expandExtra(pp: *Preprocessor, source: *ExpandBuf, start_index: *usize) Error!void {
    if (pp.defines.getEntry(pp.expandedSlice(source.items[start_index.*]))) |some| {
        if (pp.expansion_log.get(some)) |_| {
            // If we have already expanded this macro, do not recursively expand it.
            start_index.* += 1;
            return;
        }
        // Mark that we have seen this macro.
        try pp.expansion_log.putNoClobber(some, {});

        switch (some.value) {
            .empty => _ = source.orderedRemove(start_index.*), // Simply remove the token.
            .self => start_index.* += 1, // Just go over the token.
            .simple => |macro| {
                // Remove the token from the source and setup a new buffer.
                _ = source.orderedRemove(start_index.*);
                var buf = ExpandBuf.init(pp.comp.gpa);
                defer buf.deinit();
                try buf.ensureCapacity(macro.tokens.len);

                // Add all of the macros tokens to the new bufer handling any concats.
                var i: usize = 0;
                while (i < macro.tokens.len) : (i += 1) {
                    const raw = macro.tokens[i];
                    if (raw.id == .hash_hash) {
                        _ = buf.pop();
                        const lhs = tokFromRaw(macro.tokens[i - 1]);
                        const rhs = tokFromRaw(macro.tokens[i + 1]);
                        i += 1;
                        buf.appendAssumeCapacity(try pp.pasteTokens(lhs, rhs));
                    } else {
                        buf.appendAssumeCapacity(tokFromRaw(raw));
                    }
                }

                // Try to expand the resulting tokens.
                i = 0;
                while (i < buf.items.len) {
                    if (buf.items[i].id.isMacroIdentifier()) {
                        try pp.expandExtra(&buf, &i);
                    } else {
                        i += 1;
                    }
                }
                // Mark all the tokens before adding them to the source buffer.
                for (buf.items) |*tok| try pp.markExpandedFrom(tok, macro.loc);
                try source.insertSlice(start_index.*, buf.items);
                start_index.* += buf.items.len;
            },
            .func => |macro| return pp.expandFunc(source, start_index, macro),
        }
    } else start_index.* += 1; // go over normal identifiers
}

/// Try to expand a function like macro in the `source` buffer at `start_index`.
fn expandFunc(pp: *Preprocessor, source: *ExpandBuf, start_index: *usize, macro: Macro.Func) Error!void {
    const name_tok = source.items[start_index.*];
    const l_paren_index = start_index.* + 1;
    if (source.items.len <= l_paren_index or source.items[l_paren_index].id != .l_paren) {
        // Not a macro function call, go over normal identifier.
        start_index.* += 1;
        return;
    }

    // collect the arguments.
    // `args_count` starts with 1 since whitespace counts as an argument.
    var args_count: u32 = 0;
    var parens: u32 = 0;
    const args = for (source.items[l_paren_index + 1 ..]) |tok, i| {
        switch (tok.id) {
            .comma => if (parens == 0) {
                if (args_count == 0) args_count = 2 else args_count += 1;
            },
            .l_paren => parens += 1,
            .r_paren => {
                if (parens == 0) break source.items[l_paren_index + 1 ..][0..i];
                parens -= 1;
            },
            else => {},
        }
    } else {
        try pp.comp.diag.add(.{ .tag = .unterminated_macro_arg_list, .loc = name_tok.loc });
        start_index.* += 1;
        return;
    };
    if (args_count == 0 and args.len != 0) args_count = 1;

    // Validate argument count.
    const extra = Diagnostics.Message.Extra{ .arguments = .{ .expected = @intCast(u32, macro.params.len), .actual = args_count } };
    if (macro.var_args and args_count < macro.params.len) {
        try pp.comp.diag.add(.{ .tag = .expected_at_least_arguments, .loc = name_tok.loc, .extra = extra });
        start_index.* += 1;
        return;
    }
    if (!macro.var_args and args_count != macro.params.len) {
        try pp.comp.diag.add(.{ .tag = .expected_arguments, .loc = name_tok.loc, .extra = extra });
        start_index.* += 1;
        return;
    }

    var buf = ExpandBuf.init(pp.comp.gpa);
    defer buf.deinit();
    try buf.ensureCapacity(macro.tokens.len);

    // 1. Stringification and 2. Parameter replacement
    var tok_i: usize = 0;
    while (tok_i < macro.tokens.len) : (tok_i += 1) {
        const raw = macro.tokens[tok_i];
        switch (raw.id) {
            .stringify_param, .stringify_va_args => {
                const target_arg = if (raw.id == .stringify_va_args)
                    vaArgSlice(args, macro.params.len)
                else
                    argSlice(args, raw.end);
                pp.char_buf.items.len = 0; // Safe since we can only be stringifying one parameter at a time.

                // TODO pretty print these
                try pp.char_buf.append('"');
                for (target_arg) |a, i| {
                    if (i != 0) try pp.char_buf.append(' ');
                    for (pp.expandedSlice(a)) |c| {
                        if (c == '"')
                            try pp.char_buf.appendSlice("\\\"")
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
            .macro_param, .keyword_va_args => {
                const target_arg = if (raw.id == .keyword_va_args)
                    vaArgSlice(args, macro.params.len)
                else
                    argSlice(args, raw.end);

                if (target_arg.len == 0)
                    // This is needed so that we can properly do token pasting.
                    try buf.append(.{ .id = .empty_arg, .loc = .{ .id = raw.source, .byte_offset = raw.start } })
                else {
                    try buf.ensureCapacity(buf.items.len + target_arg.len);
                    for (target_arg) |arg| {
                        var copy = arg;
                        if (copy.id.isMacroIdentifier()) copy.id = .identifier_from_param else if (copy.id == .hash_hash) copy.id = .hash_hash_from_param;
                        buf.appendAssumeCapacity(copy);
                    }
                }
            },
            else => try buf.append(tokFromRaw(raw)),
        }
    }

    // 3. Concatenation
    tok_i = 0;
    while (tok_i < buf.items.len) : (tok_i += 1) {
        switch (buf.items[tok_i].id) {
            .hash_hash_from_param => buf.items[tok_i].id = .hash_hash,
            .hash_hash => {
                const prev = buf.items[tok_i - 1];
                const next = buf.items[tok_i + 1];

                buf.items[tok_i - 1] = try pp.pasteTokens(prev, next);
                mem.copy(Token, buf.items[tok_i..], buf.items[tok_i + 2 ..]);
                buf.items.len -= 2;
                tok_i -= 1;
            },
            else => {},
        }
    }

    // 4. Expand tokens from parameters
    tok_i = 0;
    while (tok_i < buf.items.len) {
        const tok = &buf.items[tok_i];
        switch (tok.id) {
            .empty_arg => _ = buf.orderedRemove(tok_i),
            .identifier_from_param => {
                tok.id = Tokenizer.Token.keywords.get(pp.expandedSlice(tok.*)) orelse .identifier;
                try pp.expandExtra(&buf, &tok_i);
            },
            else => tok_i += 1,
        }
    }

    // 5. Expand resulting tokens
    tok_i = 0;
    while (tok_i < buf.items.len) {
        if (buf.items[tok_i].id.isMacroIdentifier()) {
            try pp.expandExtra(&buf, &tok_i);
        } else {
            tok_i += 1;
        }
    }

    // Mark all the tokens before adding them to the source buffer.
    for (buf.items) |*tok| try pp.markExpandedFrom(tok, macro.loc);

    // Move tokens after the call out of the way.
    const input_len = args.len + 3; // +3 for identifier, ( and )
    if (input_len == buf.items.len) {
        // do nothing
    } else if (input_len > buf.items.len) {
        mem.copy(Token, source.items[start_index.* + buf.items.len ..], source.items[start_index.* + input_len ..]);
        source.items.len -= input_len - buf.items.len;
    } else {
        const new_len = source.items.len - input_len + buf.items.len;
        try source.ensureCapacity(new_len);
        const start_len = source.items.len;
        source.items.len = new_len;
        mem.copyBackwards(Token, source.items[start_index.* + buf.items.len ..], source.items[start_index.* + input_len .. start_len]);
    }

    // Insert resulting tokens to the source
    mem.copy(Token, source.items[start_index.*..], buf.items);
    start_index.* += buf.items.len;
}

/// Get var args from after index.
fn vaArgSlice(args: []const Token, index: usize) []const Token {
    if (index == 0) return args;
    // TODO this is a mess
    var commas_seen: usize = 0;
    var i: usize = 0;
    var parens: u32 = 0;
    while (i < args.len) : (i += 1) {
        switch (args[i].id) {
            .l_paren => parens += 1,
            .r_paren => parens -= 1,
            else => if (parens != 0) continue,
        }
        if (args[i].id == .comma) commas_seen += 1;
        if (commas_seen == index) return args[i + 1 ..];
    }
    return args[i..];
}

/// get argument at index from a list of tokens.
fn argSlice(args: []const Token, index: u32) []const Token {
    // TODO this is a mess
    var commas_seen: usize = 0;
    var i: usize = 0;
    var parens: u32 = 0;
    while (i < args.len) : (i += 1) {
        switch (args[i].id) {
            .l_paren => parens += 1,
            .r_paren => parens -= 1,
            else => if (parens != 0) continue,
        }
        if (args[i].id == .comma) {
            if (index == 0) return args[0..i];
            commas_seen += 1;
            continue;
        }
        if (commas_seen == index) for (args[i..]) |a_2, j| {
            if (a_2.id == .comma) {
                return args[i..][0..j];
            }
        } else return args[i..];
    } else return args[i..];
    unreachable;
}

// mark that this token has been expanded from `loc`
fn markExpandedFrom(pp: *Preprocessor, tok: *Token, loc: Source.Location) !void {
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
        .index = @intCast(u32, start),
        .source = .generated,
    };
    const pasted_token = tmp_tokenizer.next();
    const next = tmp_tokenizer.next().id;
    if (next != .nl and next != .eof) {
        try pp.comp.diag.add(.{
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
    const name_str = pp.tokSliceSafe(macro_name);

    // Check for function macros and empty defines.
    var first = tokenizer.next();
    first.id.simplifyMacroKeyword();
    if (first.id == .nl or first.id == .eof) {
        _ = try pp.defines.put(name_str, .empty);
        return;
    } else if (first.start == macro_name.end) {
        if (first.id == .l_paren) return pp.defineFn(tokenizer, macro_name, first);
        try pp.err(first, .whitespace_after_macro_name);
    } else if (first.id == .hash_hash) {
        try pp.err(first, .hash_hash_at_start);
    }

    { // Check for #define FOO FOO
        const start = tokenizer.index;
        const second = tokenizer.next();
        if (second.id == .nl or second.id == .eof) {
            if (mem.eql(u8, pp.tokSliceSafe(first), name_str)) {
                // #define FOO FOO
                _ = try pp.defines.put(name_str, .self);
                return;
            }
        }
        tokenizer.index = start;
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
    _ = try pp.defines.put(name_str, .{ .simple = .{
        .loc = .{ .id = macro_name.source, .byte_offset = macro_name.start },
        .tokens = list,
    } });
}

/// Handle a function like #define directive.
fn defineFn(pp: *Preprocessor, tokenizer: *Tokenizer, macro_name: RawToken, l_paren: RawToken) Error!void {
    assert(macro_name.id.isMacroIdentifier());
    var params = std.ArrayList([]const u8).init(pp.comp.gpa);
    defer params.deinit();

    // Parse the paremeter list.
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
                const start = tokenizer.index;
                const next = tokenizer.next();
                if (next.id == .nl or next.id == .eof) {
                    try pp.err(tok, .hash_hash_at_end);
                    continue;
                }
                tokenizer.index = start;
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
    const name_str = pp.tokSliceSafe(macro_name);
    _ = try pp.defines.put(name_str, .{ .func = .{
        .params = param_list,
        .var_args = var_args,
        .tokens = token_list,
        .loc = .{ .id = macro_name.source, .byte_offset = macro_name.start },
    } });
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
    pp.tokens.len -= 1; // remove eof
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
        try pp.comp.diag.add(.{
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

        const slice = pp.expandedSlice(cur);
        try w.writeAll(slice);

        i += 1;
        const next = pp.tokens.get(i);
        if (next.id == .eof) {
            try w.writeByte('\n');
        } else if (next.loc.next != null or next.loc.id == .generated) {
            // next was expanded from a macro
            try w.writeByte(' ');
        } else if (next.loc.id == cur.loc.id) {
            // TODO fix this
            // const source = pp.comp.getSource(cur.loc.id).buf;
            // const cur_end = cur.loc.byte_offset + slice.len;
            // try pp.printInBetween(source[cur_end..next.loc.byte_offset], w);
            try w.writeByte(' ');
        } else {
            // next was included from another file
            try w.writeByte('\n');
        }
        cur = next;
    }
}

fn printInBetween(pp: *Preprocessor, slice: []const u8, w: anytype) !void {
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
