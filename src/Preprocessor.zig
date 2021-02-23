const std = @import("std");
const mem = std.mem;
const Allocator = mem.Allocator;
const assert = std.debug.assert;
const Compilation = @import("Compilation.zig");
const Error = Compilation.Error;
const Source = @import("Source.zig");
const Tokenizer = @import("Tokenizer.zig");
const Token = Tokenizer.Token;
const Parser = @import("Parser.zig");
const Diagnostics = @import("Diagnostics.zig");

const Preprocessor = @This();
const DefineMap = std.StringHashMap(Macro);
const TokenList = std.ArrayList(Token);

const Macro = union(enum) {
    /// #define FOO
    empty,
    /// #define FOO FOO
    self,
    /// #define FOO a + b
    simple: []const Token,
    /// #define FOO(a,b) ((a)+(b))
    func: struct {
        params: []const []const u8,
        tokens: []const Token,
        var_args: bool,
    },
};

comp: *Compilation,
arena: std.heap.ArenaAllocator,
defines: DefineMap,
tokens: TokenList,
generated: std.ArrayList(u8),
token_buf: TokenList,
pragma_once: std.AutoHashMap(Source.Id, void),

pub fn init(comp: *Compilation) Preprocessor {
    return .{
        .comp = comp,
        .arena = std.heap.ArenaAllocator.init(comp.gpa),
        .defines = DefineMap.init(comp.gpa),
        .tokens = TokenList.init(comp.gpa),
        .generated = std.ArrayList(u8).init(comp.gpa),
        .token_buf = TokenList.init(comp.gpa),
        .pragma_once = std.AutoHashMap(Source.Id, void).init(comp.gpa),
    };
}

pub fn deinit(pp: *Preprocessor) void {
    pp.defines.deinit();
    pp.tokens.deinit();
    pp.arena.deinit();
    pp.generated.deinit();
    pp.token_buf.deinit();
    pp.pragma_once.deinit();
}

/// Preprocess a source file.
pub fn preprocess(pp: *Preprocessor, source: Source) Error!void {
    var tokenizer = Tokenizer{
        .buf = source.buf,
        .source = source.id,
    };

    // Estimate how many new tokens this source will contain.
    const estimated_token_count = source.buf.len / 8;
    try pp.tokens.ensureCapacity(pp.tokens.items.len + estimated_token_count);

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
                        const start = tokenizer.index;
                        while (tokenizer.index < tokenizer.buf.len) : (tokenizer.index += 1) {
                            if (tokenizer.buf[tokenizer.index] == '\n') break;
                        }
                        var slice = tokenizer.buf[start..tokenizer.index];
                        slice = mem.trim(u8, slice, " \t\x0B\x0C");
                        try pp.comp.diag.add(.{
                            .tag = .error_directive,
                            .source_id = tok.source,
                            .loc_start = tok.loc.start,
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
                                .source_id = tok.source,
                                .loc_start = tok.loc.start,
                                .extra = .{ .str = slice },
                            });
                        }
                    },
                    .keyword_line => {
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
                        return pp.tokens.append(directive);
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
                return pp.tokens.append(tok);
            },
            else => {
                start_of_line = false;
                if (tok.id.isMacroIdentifier()) {
                    tok.id.simplifyMacroKeyword();
                    try pp.expandMacro(&tokenizer, tok, &pp.tokens);
                } else {
                    try pp.tokens.append(tok);
                }
            },
        }
    }
}

fn tokSliceSafe(pp: *Preprocessor, token: Token) []const u8 {
    if (token.id.lexeme()) |some| return some;
    assert(!token.source.isGenerated());
    const source_buf = pp.comp.sources.items()[token.source.index()].value.buf;
    return source_buf[token.loc.start..token.loc.end];
}

// Returned slice is invalidated when generated is updated.
pub fn tokSlice(pp: *Preprocessor, token: Token) []const u8 {
    if (token.id.lexeme()) |some| return some;
    if (token.source.isGenerated()) {
        return pp.generated.items[token.loc.start..token.loc.end];
    } else {
        const source = pp.comp.getSource(token.source);
        return source.buf[token.loc.start..token.loc.end];
    }
}

fn err(pp: *Preprocessor, tok: Token, tag: Diagnostics.Tag) !void {
    try pp.comp.diag.add(.{
        .tag = tag,
        .source_id = tok.source,
        .loc_start = tok.loc.start,
    });
}

fn expectMacroName(pp: *Preprocessor, tokenizer: *Tokenizer) Error!?[]const u8 {
    const macro_name = tokenizer.next();
    if (!macro_name.id.isMacroIdentifier()) {
        try pp.err(macro_name, .macro_name_missing);
        skipToNl(tokenizer);
        return null;
    }
    return pp.tokSliceSafe(macro_name);
}

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

fn expr(pp: *Preprocessor, tokenizer: *Tokenizer) Error!bool {
    pp.token_buf.items.len = 0; // Safe to use since we can only be in one directive at a time.
    while (true) {
        var tok = tokenizer.next();
        if (tok.id == .nl or tok.id == .eof) {
            if (pp.token_buf.items.len == 0) {
                try pp.err(tok, .expected_value_in_expr);
                try pp.expectNl(tokenizer);
                return false;
            }
            tok.id = .eof;
            try pp.token_buf.append(tok);
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
        } else if (tok.id.isMacroIdentifier()) {
            try pp.expandMacro(tokenizer, tok, &pp.token_buf);
            continue;
        }
        try pp.token_buf.append(tok);
    }

    for (pp.token_buf.items) |*tok| {
        switch (tok.id) {
            .string_literal,
            .string_literal_utf_16,
            .string_literal_utf_8,
            .string_literal_utf_32,
            .string_literal_wide,
            => {
                try pp.err(tok.*, .string_literal_in_pp_expr);
                return false;
            },
            .float_literal,
            .float_literal_f,
            .float_literal_l,
            => {
                try pp.err(tok.*, .float_literal_in_pp_expr);
                return false;
            },
            else => if (tok.id.isMacroIdentifier()) {
                tok.id = .zero; // clang and gcc seem to do this
            },
        }
    }

    var parser = Parser{
        .pp = pp,
        .tokens = pp.token_buf.items,
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

fn skipToNl(tokenizer: *Tokenizer) void {
    while (true) {
        const tok = tokenizer.next();
        if (tok.id == .nl or tok.id == .eof) return;
    }
}

/// Try to expand a macro.
fn expandMacro(pp: *Preprocessor, tokenizer: *Tokenizer, tok: Token, tokens: *TokenList) Error!void {
    const name = pp.tokSliceSafe(tok); // TODO is this safe?
    return pp.expandExtra(tokenizer, name, tok, tokens);
}

fn expandExtra(pp: *Preprocessor, tokenizer: *Tokenizer, orig_name: []const u8, arg: Token, tokens: *TokenList) Error!void {
    if (pp.defines.get(pp.tokSlice(arg))) |some| switch (some) {
        .empty => {},
        .self => try tokens.append(arg),
        .simple => |macro_tokens| {
            for (macro_tokens) |tok| {
                if (tok.id.isMacroIdentifier() and !std.mem.eql(u8, pp.tokSlice(tok), orig_name)) {
                    try pp.expandExtra(tokenizer, orig_name, tok, tokens);
                } else {
                    try tokens.append(tok);
                }
            }
        },
        .func => return pp.comp.fatal(arg, "TODO func macro expansion", .{}),
    } else {
        try tokens.append(arg);
    }
}

/// Handle a #define directive.
fn define(pp: *Preprocessor, tokenizer: *Tokenizer) Error!void {
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

    var first = tokenizer.next();
    first.id.simplifyMacroKeyword();
    if (first.id == .nl or first.id == .eof) {
        _ = try pp.defines.put(name_str, .empty);
        return;
    } else if (first.loc.start == macro_name.loc.end) {
        if (first.id == .l_paren) return pp.defineFn(tokenizer, first, macro_name);
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

    while (true) {
        var tok = tokenizer.next();
        tok.id.simplifyMacroKeyword();
        switch (tok.id) {
            .hash_hash => {
                const prev = pp.token_buf.pop();
                const next = tokenizer.next();
                if (next.id == .nl or next.id == .eof) {
                    try pp.err(tok, .hash_hash_at_end);
                    continue;
                }
                const next_slice = pp.tokSliceSafe(next);

                const start = pp.generated.items.len;
                const end = start + pp.tokSlice(prev).len + next_slice.len;
                try pp.generated.ensureCapacity(end);
                pp.generated.appendSliceAssumeCapacity(pp.tokSlice(prev));
                pp.generated.appendSliceAssumeCapacity(next_slice);

                var tmp_source = tokenizer.source;
                tmp_source.markGenerated();
                var tmp_tokenizer = Tokenizer{
                    .buf = pp.generated.items,
                    .index = @intCast(u32, start),
                    .source = tmp_source,
                };
                const pasted_token = tmp_tokenizer.next();
                if (tmp_tokenizer.next().id != .eof) {
                    try pp.comp.diag.add(.{
                        .tag = .pasting_formed_invalid,
                        .source_id = tok.source,
                        .loc_start = tok.loc.start,
                        .extra = .{ .str = try pp.arena.allocator.dupe(u8, pp.generated.items[start..end]) },
                    });
                }
                try pp.token_buf.append(pasted_token);
            },
            .nl, .eof => break,
            else => try pp.token_buf.append(tok),
        }
    }

    const list = try pp.arena.allocator.dupe(Token, pp.token_buf.items);
    _ = try pp.defines.put(name_str, .{ .simple = list });
}

/// Handle a function like #define directive.
fn defineFn(pp: *Preprocessor, tokenizer: *Tokenizer, macro_name: Token, l_paren: Token) Error!void {
    var params = std.ArrayList([]const u8).init(pp.comp.gpa);
    defer params.deinit();

    var var_args = false;
    while (true) {
        const tok = tokenizer.next();
        if (tok.id == .r_paren) break;
        if (params.items.len != 0) {
            if (tok.id != .comma)
                try pp.err(tok, .invalid_token_param_list)
            else
                continue;
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

    pp.token_buf.items.len = 0; // Safe to use since we can only be in one directive at a time.
    tok_loop: while (true) {
        var tok = tokenizer.next();
        switch (tok.id) {
            .nl, .eof => break,
            .hash => {
                const param = tokenizer.next();
                blk: {
                    if (!param.id.isMacroIdentifier()) break :blk;
                    const s = pp.tokSliceSafe(param);
                    for (params.items) |p, i| {
                        if (mem.eql(u8, p, s)) {
                            tok.id = .stringify_param;
                            tok.loc.end = @intCast(u32, i);
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
                if (tok.id.isMacroIdentifier()) {
                    tok.id.simplifyMacroKeyword();
                    const s = pp.tokSliceSafe(tok);
                    for (params.items) |param, i| {
                        if (mem.eql(u8, param, s)) {
                            tok.id = .macro_param;
                            tok.loc.end = @intCast(u32, i);
                            break;
                        }
                    }
                }
                try pp.token_buf.append(tok);
            },
        }
    }

    const param_list = try pp.arena.allocator.dupe([]const u8, params.items);
    const token_list = try pp.arena.allocator.dupe(Token, pp.token_buf.items);
    const name_str = pp.tokSliceSafe(macro_name);
    _ = try pp.defines.put(name_str, .{ .func = .{ .params = param_list, .var_args = var_args, .tokens = token_list } });
}

// Handle a #include directive.
fn include(pp: *Preprocessor, tokenizer: *Tokenizer) Error!void {
    pp.token_buf.items.len = 0; // Safe to use since we can only be in one directive at a time.
    var first = tokenizer.next();
    if (first.id == .angle_bracket_left) to_end: {
        while (tokenizer.index < tokenizer.buf.len) : (tokenizer.index += 1) {
            switch (tokenizer.buf[tokenizer.index]) {
                '>' => {
                    tokenizer.index += 1;
                    first.loc.end = tokenizer.index;
                    first.id = .macro_string;
                    break :to_end;
                },
                '\n' => break,
                else => {},
            }
        }
        try pp.comp.diag.add(.{
            .tag = .header_str_closing,
            .source_id = first.source,
            .loc_start = tokenizer.index,
        });
        try pp.err(first, .header_str_match);
    }
    try pp.expandMacro(tokenizer, first, &pp.token_buf);

    const filename_tok = if (pp.token_buf.items.len == 0) first else pp.token_buf.items[0];
    switch (filename_tok.id) {
        .string_literal, .macro_string => {},
        else => {
            try pp.err(first, .expected_filename);
            return pp.expectNl(tokenizer);
        },
    }
    const nl = tokenizer.next();
    if ((nl.id != .nl and nl.id != .eof) or pp.token_buf.items.len > 1) {
        skipToNl(tokenizer);
        return pp.err(first, .extra_tokens_directive_end);
    }

    const tok_slice = pp.tokSlice(filename_tok);
    if (tok_slice.len < 3) return pp.err(first, .empty_filename);

    const filename = tok_slice[1 .. tok_slice.len - 1];
    const new_source = try pp.comp.findInclude(filename_tok, filename, filename_tok.id == .string_literal);
    return pp.preprocess(new_source);
}
