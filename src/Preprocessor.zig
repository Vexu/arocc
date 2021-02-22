const std = @import("std");
const mem = std.mem;
const Allocator = mem.Allocator;
const assert = std.debug.assert;
const Compilation = @import("Compilation.zig");
const Source = @import("Source.zig");
const Tokenizer = @import("Tokenizer.zig");
const Token = Tokenizer.Token;
const Parser = @import("Parser.zig");

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

const Error = Allocator.Error || error{PreprocessingFailed};

comp: *Compilation,
arena: std.heap.ArenaAllocator,
defines: DefineMap,
tokens: TokenList,
generated: std.ArrayList(u8),
token_buf: TokenList,
char_buf: std.ArrayList(u8),
pragma_once: std.AutoHashMap(Source.Id, void),

pub fn init(comp: *Compilation) Preprocessor {
    return .{
        .comp = comp,
        .arena = std.heap.ArenaAllocator.init(comp.gpa),
        .defines = DefineMap.init(comp.gpa),
        .tokens = TokenList.init(comp.gpa),
        .generated = std.ArrayList(u8).init(comp.gpa),
        .token_buf = TokenList.init(comp.gpa),
        .char_buf = std.ArrayList(u8).init(comp.gpa),
        .pragma_once = std.AutoHashMap(Source.Id, void).init(comp.gpa),
    };
}

pub fn deinit(pp: *Preprocessor) void {
    pp.defines.deinit();
    pp.tokens.deinit();
    pp.arena.deinit();
    pp.generated.deinit();
    pp.token_buf.deinit();
    pp.char_buf.deinit();
    pp.pragma_once.deinit();
}

/// Preprocess a source file.
pub fn preprocess(pp: *Preprocessor, source: Source) !void {
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
                        return pp.fail(slice, directive);
                    },
                    .keyword_if => {
                        if (@addWithOverflow(u8, if_level, 1, &if_level))
                            return pp.fail("too many #if nestings", directive);

                        if (try pp.expr(&tokenizer)) {
                            if_kind.set(if_level, until_endif);
                        } else {
                            if_kind.set(if_level, until_else);
                            try pp.skip(&tokenizer, .until_else);
                        }
                    },
                    .keyword_ifdef => {
                        if (@addWithOverflow(u8, if_level, 1, &if_level))
                            return pp.fail("too many #if nestings", directive);

                        const macro_name = try pp.expectMacroName(&tokenizer);
                        try pp.expectNl(&tokenizer, false);
                        if (pp.defines.get(macro_name) != null) {
                            if_kind.set(if_level, until_endif);
                        } else {
                            if_kind.set(if_level, until_else);
                            try pp.skip(&tokenizer, .until_else);
                        }
                    },
                    .keyword_ifndef => {
                        if (@addWithOverflow(u8, if_level, 1, &if_level))
                            return pp.fail("too many #if nestings", directive);

                        const macro_name = try pp.expectMacroName(&tokenizer);
                        try pp.expectNl(&tokenizer, false);
                        if (pp.defines.get(macro_name) == null) {
                            if_kind.set(if_level, until_endif);
                        } else {
                            if_kind.set(if_level, until_else);
                            try pp.skip(&tokenizer, .until_else);
                        }
                    },
                    .keyword_elif => {
                        if (if_level == 0) return pp.fail("#elif without #if", directive);
                        switch (if_kind.get(if_level)) {
                            until_else => if (try pp.expr(&tokenizer)) {
                                if_kind.set(if_level, until_endif);
                            } else {
                                try pp.skip(&tokenizer, .until_else);
                            },
                            until_endif => try pp.skip(&tokenizer, .until_endif),
                            until_endif_seen_else => return pp.fail("#elif after #else", directive),
                            else => unreachable,
                        }
                    },
                    .keyword_else => {
                        if (if_level == 0) return pp.fail("#else without #if", directive);
                        try pp.expectNl(&tokenizer, false);
                        switch (if_kind.get(if_level)) {
                            until_else => if_kind.set(if_level, until_endif_seen_else),
                            until_endif => try pp.skip(&tokenizer, .until_endif_seen_else),
                            until_endif_seen_else => return pp.fail("#else after #else", directive),
                            else => unreachable,
                        }
                    },
                    .keyword_endif => {
                        if (if_level == 0) return pp.fail("#endif without #if", directive);
                        try pp.expectNl(&tokenizer, true);
                        if_level -= 1;
                    },
                    .keyword_define => try pp.define(&tokenizer),
                    .keyword_undef => {
                        const macro_name = try pp.expectMacroName(&tokenizer);

                        _ = pp.defines.remove(macro_name);
                        try pp.expectNl(&tokenizer, true);
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
                            // unknown pragma, TODO erro/warn??
                        }
                    },
                    .keyword_line => {
                        const digits = tokenizer.next();
                        if (digits.id != .integer_literal) return pp.fail("#line directive requires a simple digit sequence", digits);
                        const name = tokenizer.next();
                        if (name.id == .eof or name.id == .nl) continue;
                        if (name.id != .string_literal) return pp.fail("invalid filename for #line directive", name);
                        try pp.expectNl(&tokenizer, true);
                    },
                    .nl => {},
                    .eof => {
                        if (if_level != 0) return pp.fail("unterminated conditional directive", directive);
                        try pp.tokens.append(directive);
                        return;
                    },
                    else => return pp.fail("invalid preprocessing directive", directive),
                }
            },
            .nl => start_of_line = true,
            .eof => {
                if (if_level != 0) return pp.fail("unterminated conditional directive", tok);
                try pp.tokens.append(tok);
                return;
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

fn failFmt(pp: *Preprocessor, tok: Token, comptime fmt: []const u8, args: anytype) Error {
    const source = pp.comp.getSource(tok.source);
    const lcs = source.lineColString(tok.loc);
    pp.comp.printErrStart(source.path, lcs);
    std.debug.print(fmt, args);
    pp.comp.printErrEnd(lcs);
    return error.PreprocessingFailed;
}

fn fail(pp: *Preprocessor, msg: []const u8, tok: Token) Error {
    return pp.failFmt(tok, "{s}", .{msg});
}

fn expectMacroName(pp: *Preprocessor, tokenizer: *Tokenizer) Error![]const u8 {
    const macro_name = tokenizer.next();
    if (!macro_name.id.isMacroIdentifier()) return pp.fail("macro name missing", macro_name);
    return pp.tokSliceSafe(macro_name);
}

fn expectNl(pp: *Preprocessor, tokenizer: *Tokenizer, allow_eof: bool) Error!void {
    const tok = tokenizer.next();
    if (tok.id == .eof) {
        if (!allow_eof) return pp.fail("unterminated conditional directive", tok);
        return;
    }
    if (tok.id != .nl) return pp.fail("extra tokens at end of macro directive", tok);
}

fn expr(pp: *Preprocessor, tokenizer: *Tokenizer) Error!bool {
    pp.token_buf.items.len = 0; // Safe to use since we can only be in one directive at a time.
    while (true) {
        var tok = tokenizer.next();
        if (tok.id == .nl or tok.id == .eof) {
            if (pp.token_buf.items.len == 0) return pp.fail("expected value in expression", tok);
            tok.id = .eof;
            try pp.token_buf.append(tok);
            break;
        } else if (tok.id == .keyword_defined) {
            const first = tokenizer.next();
            const macro_tok = if (first.id == .l_paren)
                tokenizer.next()
            else
                first;
            if (!macro_tok.id.isMacroIdentifier()) return pp.fail("macro name missing", macro_tok);
            if (first.id == .l_paren) {
                const r_paren = tokenizer.next();
                if (r_paren.id != .r_paren) return pp.fail("expected closing ')'", r_paren);
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
            => return pp.fail("string literal in preprocessor expression", tok.*),
            .float_literal,
            .float_literal_f,
            .float_literal_l,
            => return pp.fail("floating point literal in preprocessor expression", tok.*),
            else => if (tok.id.isMacroIdentifier()) {
                tok.id = .zero; // clang and gcc seem to do this
            },
        }
    }

    var parser = Parser{
        .pp = pp,
        .tokens = pp.token_buf.items,
    };
    const res = parser.constExpr() catch |err| switch (err) {
        error.OutOfMemory => unreachable, // TODO verify this
        error.ParsingFailed => return error.PreprocessingFailed,
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
                    if (cont == .until_endif_seen_else) return pp.fail("#else after #else", directive);
                    tokenizer.index = dir_start;
                    return;
                },
                .keyword_elif => {
                    if (ifs_seen != 0 or cont == .until_endif) continue;
                    if (cont == .until_endif_seen_else) return pp.fail("#elif after #else", directive);
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
        return pp.fail("unterminated conditional directive", eof);
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
        .func => return pp.fail("TODO func macro expansion", arg),
    } else {
        try tokens.append(arg);
    }
}

/// Handle a #define directive.
fn define(pp: *Preprocessor, tokenizer: *Tokenizer) Error!void {
    const macro_name = tokenizer.next();
    if (macro_name.id == .keyword_defined) return pp.fail("'defined' cannot be used as a macro name", macro_name);
    if (!macro_name.id.isMacroIdentifier()) return pp.fail("macro name must be an identifier", macro_name);
    const name_str = pp.tokSliceSafe(macro_name);

    var first = tokenizer.next();
    first.id.simplifyMacroKeyword();
    if (first.id == .nl or first.id == .eof) {
        _ = try pp.defines.put(name_str, .empty);
        return;
    } else if (first.loc.start == macro_name.loc.end) {
        if (first.id == .l_paren) return pp.defineFn(tokenizer, macro_name);
        return pp.fail("ISO C99 requires whitespace after the macro name", first);
    } else if (first.id == .hash_hash) {
        return pp.fail("'##' cannot appear at start of macro expansion", first);
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
                if (next.id == .nl or next.id == .eof) return pp.fail("'##' cannot appear at end of macro expansion", next);
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
                    return pp.failFmt(tok, "pasting formed '{s}', an invalid preprocessing token", .{pp.generated.items[start..end]});
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
fn defineFn(pp: *Preprocessor, tokenizer: *Tokenizer, macro_name: Token) Error!void {
    var params = std.ArrayList([]const u8).init(pp.comp.gpa);
    defer params.deinit();

    var var_args = false;
    while (true) {
        const tok = tokenizer.next();
        if (tok.id == .r_paren) break;
        if (tok.id == .ellipsis) {
            var_args = true;
            const r_paren = tokenizer.next();
            if (r_paren.id != .r_paren)
                return pp.fail("missing ')' in macro parameter list", r_paren);
            break;
        }
        if (!tok.id.isMacroIdentifier())
            return pp.fail("invalid token in macro parameter list", tok);

        try params.append(pp.tokSliceSafe(tok));
        const next = tokenizer.next();
        if (next.id == .r_paren) break;
        if (next.id != .comma) // TODO should not allow name(a,)
            return pp.fail("invalid token in macro parameter list", next);
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
                return pp.fail("'#' is not followed by a macro parameter", param);
            },
            .hash_hash => {
                const start = tokenizer.index;
                const next = tokenizer.next();
                if (next.id == .nl or next.id == .eof) {
                    return pp.fail("'##' cannot appear at start of macro expansion", tok);
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
    pp.char_buf.items.len = 0;

    var first: ?Token = null;
    while (true) {
        const tok = tokenizer.next();
        if (first == null) first = tok;
        if (tok.id == .nl or tok.id == .eof) break;
        if (tok.id.isMacroIdentifier())
            try pp.expandMacro(tokenizer, tok, &pp.token_buf)
        else
            try pp.token_buf.append(tok);
    }

    for (pp.token_buf.items) |tok| {
        try pp.char_buf.appendSlice(pp.tokSlice(tok));
    }

    fail: {
        if (pp.char_buf.items.len == 0) break :fail;
        const start = pp.char_buf.items[0];
        if (start != '"' and start != '<') break :fail;
        const end = pp.char_buf.items[pp.char_buf.items.len - 1];
        if ((start == '"' and end != '"') or (start == '<' and end != '>')) break :fail;

        const filename = pp.char_buf.items[1 .. pp.char_buf.items.len - 1];
        const new_source = pp.comp.findInclude(filename, start == '"') catch |err| switch (err) {
            error.OutOfMemory => return error.OutOfMemory,
            else => return pp.failFmt(first.?, "'{s}' not found", .{filename}),
        };
        return pp.preprocess(new_source);
    }
    return pp.fail("expected \"FILENAME\" or <FILENAME>", first.?);
}
