const std = @import("std");
const mem = std.mem;
const Allocator = mem.Allocator;
const assert = std.debug.assert;
const Compilation = @import("Compilation.zig");
const Source = @import("Source.zig");
const Tokenizer = @import("Tokenizer.zig");
const Token = Tokenizer.Token;

const Preprocessor = @This();
const DefineMap = std.StringHashMap(Macro);
const TokenList = std.ArrayList(Token);

const Macro = union(enum) {
    empty,
    func: struct {
        params: []const []const u8,
        tokens: []const Token,
        var_args: bool,
    },
    simple: []const Token,
};

comp: *Compilation,
arena: std.heap.ArenaAllocator,
defines: DefineMap,
tokens: TokenList,
generated: std.ArrayList(u8),

pub fn init(comp: *Compilation) Preprocessor {
    return .{
        .comp = comp,
        .arena = std.heap.ArenaAllocator.init(comp.gpa),
        .defines = DefineMap.init(comp.gpa),
        .tokens = TokenList.init(comp.gpa),
        .generated = std.ArrayList(u8).init(comp.gpa),
    };
}

pub fn deinit(pp: *Preprocessor) void {
    pp.defines.deinit();
    pp.tokens.deinit();
    pp.arena.deinit();
    pp.generated.deinit();
}

const Error = Allocator.Error || error{PreprocessingFailed};

/// Preprocess a source file.
pub fn preprocess(pp: *Preprocessor, source: Source) !void {
    var tokenizer = Tokenizer{
        .buf = source.buf,
        .source = source,
    };

    // Estimate how many new tokens this source will contain.
    const estimated_token_count = source.buf.len / 8;
    try pp.tokens.ensureCapacity(pp.tokens.items.len + estimated_token_count);

    const last = try pp.preprocessInternal(&tokenizer, .until_eof);
    assert(last == .eof);
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
        const source_buf = pp.comp.sources.items()[token.source.index()].value.buf;
        return source_buf[token.loc.start..token.loc.end];
    }
}

/// Preprocess the source until `cont` condition is met.
fn preprocessInternal(
    pp: *Preprocessor,
    tokenizer: *Tokenizer,
    cont: enum { until_eof, until_else, until_endif },
) Error!Token.Id {
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
                        const loc = Source.Location{ .start = start, .end = tokenizer.index };
                        var slice = tokenizer.source.buf[loc.start..loc.end];
                        slice = mem.trim(u8, slice, " \t\x0B\x0C");
                        return pp.fail(tokenizer.source, slice, directive);
                    },
                    .keyword_if => try pp.expandConditional(tokenizer, try pp.expandBoolExpr(tokenizer)),
                    .keyword_ifdef => {
                        const macro_name = try pp.expectMacroName(tokenizer);
                        try pp.expectNl(tokenizer, false);
                        try pp.expandConditional(tokenizer, pp.defines.get(macro_name) != null);
                    },
                    .keyword_ifndef => {
                        const macro_name = try pp.expectMacroName(tokenizer);
                        try pp.expectNl(tokenizer, false);
                        try pp.expandConditional(tokenizer, pp.defines.get(macro_name) == null);
                    },
                    .keyword_define => try pp.define(tokenizer),
                    .keyword_include => return pp.fail(tokenizer.source, "TODO include directive", directive),
                    .keyword_pragma => return pp.fail(tokenizer.source, "TODO pragma directive", directive),
                    .keyword_undef => {
                        const macro_name = try pp.expectMacroName(tokenizer);

                        _ = pp.defines.remove(macro_name);
                        try pp.expectNl(tokenizer, true);
                    },
                    .keyword_elif => {
                        if (cont == .until_eof) return pp.fail(tokenizer.source, "#elif without #if", directive);
                        if (cont == .until_endif) return pp.fail(tokenizer.source, "#elif after #else", directive);
                        return directive.id;
                    },
                    .keyword_else => {
                        if (cont == .until_eof) return pp.fail(tokenizer.source, "#else without #if", directive);
                        if (cont == .until_endif) return pp.fail(tokenizer.source, "#else after #else", directive);
                        try pp.expectNl(tokenizer, false);
                        return directive.id;
                    },
                    .keyword_endif => {
                        if (cont == .until_eof) return pp.fail(tokenizer.source, "#endif without #if", directive);
                        try pp.expectNl(tokenizer, true);
                        return directive.id;
                    },
                    .keyword_line => {
                        const digits = tokenizer.next();
                        if (digits.id != .integer_literal) return pp.fail(tokenizer.source, "#line directive requires a simple digit sequence", digits);
                        const name = tokenizer.next();
                        if (name.id == .eof or name.id == .nl) continue;
                        if (name.id != .string_literal) return pp.fail(tokenizer.source, "invalid filename for #line directive", name);
                        try pp.expectNl(tokenizer, true);
                    },
                    .nl => {},
                    .eof => {
                        if (cont != .until_eof) return pp.fail(tokenizer.source, "unterminated conditional directive", directive);
                        try pp.tokens.append(directive);
                        return directive.id;
                    },
                    else => return pp.fail(tokenizer.source, "invalid preprocessing directive", directive),
                }
            },
            .nl => start_of_line = true,
            .eof => {
                if (cont != .until_eof) return pp.fail(tokenizer.source, "unterminated conditional directive", tok);
                try pp.tokens.append(tok);
                return tok.id;
            },
            else => {
                start_of_line = false;
                if (tok.id.isMacroIdentifier()) {
                    tok.id.simplifyMacroKeyword();
                    try pp.expandMacro(tokenizer, tok, &pp.tokens);
                } else {
                    try pp.tokens.append(tok);
                }
            },
        }
    }
}

fn failFmt(pp: *Preprocessor, source: Source, tok: Token, comptime fmt: []const u8, args: anytype) Error {
    assert(source.id == tok.source);
    const lcs = source.lineColString(tok.loc);
    pp.comp.printErrStart(source.path, lcs);
    std.debug.print(fmt, args);
    pp.comp.printErrEnd(lcs);
    return error.PreprocessingFailed;
}

fn fail(pp: *Preprocessor, source: Source, msg: []const u8, tok: Token) Error {
    return pp.failFmt(source, tok, "{s}", .{msg});
}

fn expectMacroName(pp: *Preprocessor, tokenizer: *Tokenizer) Error![]const u8 {
    const macro_name = tokenizer.next();
    if (!macro_name.id.isMacroIdentifier()) return pp.fail(tokenizer.source, "macro name missing", macro_name);
    return pp.tokSliceSafe(macro_name);
}

fn expectNl(pp: *Preprocessor, tokenizer: *Tokenizer, allow_eof: bool) Error!void {
    const tok = tokenizer.next();
    if (tok.id == .eof) {
        if (!allow_eof) return pp.fail(tokenizer.source, "unterminated conditional directive", tok);
        return;
    }
    if (tok.id != .nl) return pp.fail(tokenizer.source, "extra tokens at end of macro directive", tok);
}

fn expandBoolExpr(pp: *Preprocessor, tokenizer: *Tokenizer) Error!bool {
    const next = tokenizer.next();
    return pp.fail(tokenizer.source, "TODO macro bool condition", next);
}

/// Handles one level of #if ... #endif.
fn expandConditional(pp: *Preprocessor, tokenizer: *Tokenizer, first_cond: bool) Error!void {
    var cond = first_cond;
    while (true) {
        if (cond) {
            const directive = try pp.preprocessInternal(tokenizer, .until_else);
            switch (directive) {
                .keyword_endif => return,
                .keyword_else => {
                    const last = try pp.skip(tokenizer, .until_endif);
                    assert(last == .keyword_endif);
                    return;
                },
                .keyword_elif => cond = try pp.expandBoolExpr(tokenizer),
                else => unreachable,
            }
        } else {
            const directive = try pp.skip(tokenizer, .until_else);
            switch (directive) {
                .keyword_endif => return,
                .keyword_else => {
                    const last = try pp.preprocessInternal(tokenizer, .until_endif);
                    assert(last == .keyword_endif);
                    return;
                },
                .keyword_elif => cond = try pp.expandBoolExpr(tokenizer),
                else => unreachable,
            }
        }
    }
}

/// Skip until #else #elif #endif, return last directive token id.
/// Also skips nested #if ... #endif's.
fn skip(
    pp: *Preprocessor,
    tokenizer: *Tokenizer,
    cont: enum { until_else, until_endif },
) Error!Token.Id {
    var ifs_seen: u32 = 0;
    var line_start = true;
    while (tokenizer.index < tokenizer.buf.len) {
        if (line_start) {
            line_start = false;
            const hash = tokenizer.next();
            if (hash.id != .hash) continue;
            const directive = tokenizer.next();
            switch (directive.id) {
                .keyword_else => {
                    if (ifs_seen != 0) continue;
                    if (cont == .until_endif) return pp.fail(tokenizer.source, "#else after #else", directive);
                    try pp.expectNl(tokenizer, false);
                    return directive.id;
                },
                .keyword_elif => {
                    if (ifs_seen != 0) continue;
                    if (cont == .until_endif) return pp.fail(tokenizer.source, "#elif after #else", directive);
                    return directive.id;
                },
                .keyword_endif => {
                    if (ifs_seen == 0) {
                        try pp.expectNl(tokenizer, true);
                        return directive.id;
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
        return pp.fail(tokenizer.source, "unterminated conditional directive", eof);
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
        .simple => |macro_tokens| {
            for (macro_tokens) |tok| {
                if (tok.id.isMacroIdentifier() and !std.mem.eql(u8, pp.tokSlice(tok), orig_name)) {
                    try pp.expandExtra(tokenizer, orig_name, tok, tokens);
                } else {
                    try tokens.append(tok);
                }
            }
        },
        .func => return pp.fail(tokenizer.source, "TODO func macro expansion", arg),
    } else {
        try tokens.append(arg);
    }
}

/// Handle a #define directive.
fn define(pp: *Preprocessor, tokenizer: *Tokenizer) Error!void {
    const macro_name = tokenizer.next();
    if (macro_name.id == .keyword_defined) return pp.fail(tokenizer.source, "'defined' cannot be used as a macro name", macro_name);
    if (!macro_name.id.isMacroIdentifier()) return pp.fail(tokenizer.source, "macro name must be an identifier", macro_name);
    const name_str = pp.tokSliceSafe(macro_name);

    var first = tokenizer.next();
    first.id.simplifyMacroKeyword();
    if (first.id == .nl or first.id == .eof) {
        _ = try pp.defines.put(name_str, .empty);
        return;
    } else if (first.loc.start == macro_name.loc.end) {
        if (first.id == .l_paren) return pp.defineFn(tokenizer, macro_name);
        return pp.fail(tokenizer.source, "ISO C99 requires whitespace after the macro name", first);
    } else if (first.id == .hash_hash) {
        return pp.fail(tokenizer.source, "'##' cannot appear at start of macro expansion", first);
    }

    var tokens = TokenList.init(pp.comp.gpa);
    defer tokens.deinit();
    try tokens.append(first);

    while (true) {
        var tok = tokenizer.next();
        tok.id.simplifyMacroKeyword();
        switch (tok.id) {
            .hash_hash => {
                const prev = tokens.pop();
                const next = tokenizer.next();
                if (next.id == .nl or next.id == .eof) return pp.fail(tokenizer.source, "'##' cannot appear at end of macro expansion", next);
                const next_slice = pp.tokSliceSafe(next);

                const start = pp.generated.items.len;
                const end = start + pp.tokSlice(prev).len + next_slice.len;
                try pp.generated.ensureCapacity(end);
                pp.generated.appendSliceAssumeCapacity(pp.tokSlice(prev));
                pp.generated.appendSliceAssumeCapacity(next_slice);

                var tmp_source = tokenizer.source;
                tmp_source.id.markGenerated();
                var tmp_tokenizer = Tokenizer{
                    .buf = pp.generated.items,
                    .index = @intCast(u32, start),
                    .source = tmp_source,
                };
                const pasted_token = tmp_tokenizer.next();
                if (tmp_tokenizer.next().id != .eof) {
                    return pp.failFmt(tokenizer.source, tok, "pasting formed '{s}', an invalid preprocessing token", .{pp.generated.items[start..end]});
                }
                try tokens.append(pasted_token);
            },
            .nl, .eof => break,
            else => try tokens.append(tok),
        }
    }

    const list = try pp.arena.allocator.dupe(Token, tokens.items);
    _ = try pp.defines.put(name_str, .{ .simple = list });
}

/// Handle a function like #define directive.
fn defineFn(pp: *Preprocessor, tokenizer: *Tokenizer, macro_name: Token) Error!void {
    var params = std.ArrayList([]const u8).init(pp.comp.gpa);
    defer params.deinit();

    while (true) {
        const tok = tokenizer.next();
        if (tok.id == .r_paren) break;
        if (tok.id.isMacroIdentifier())
            try params.append(pp.tokSliceSafe(tok))
        else
            return pp.fail(tokenizer.source, "invalid token in macro paramter list", tok);
    }

    var var_args = false;
    var tokens = TokenList.init(pp.comp.gpa);
    defer tokens.deinit();

    tok_loop: while (true) {
        var tok = tokenizer.next();
        tok.id.simplifyMacroKeyword();
        switch (tok.id) {
            .nl, .eof => break,
            .ellipsis => {
                var_args = true;
                const r_paren = tokenizer.next();
                if (r_paren.id != .r_paren)
                    return pp.fail(tokenizer.source, "missing ')' in macro parameter list", r_paren);
                break;
            },
            .hash => {
                const param = tokenizer.next();
                blk: {
                    if (!param.id.isMacroIdentifier()) break :blk;
                    const s = pp.tokSliceSafe(param);
                    for (params.items) |p, i| {
                        if (mem.eql(u8, p, s)) {
                            tok.id = .stringify_param;
                            tok.loc.end = @intCast(u32, i);
                            try tokens.append(tok);
                            continue :tok_loop;
                        }
                    }
                }
                return pp.fail(tokenizer.source, "'#' is not followed by a macro parameter", param);
            },
            else => {
                if (tok.id.isMacroIdentifier()) {
                    const s = pp.tokSliceSafe(tok);
                    for (params.items) |param, i| {
                        if (mem.eql(u8, param, s)) {
                            tok.id = .macro_param;
                            tok.loc.end = @intCast(u32, i);
                            break;
                        }
                    }
                }
                try tokens.append(tok);
            },
        }
    }

    const param_list = try pp.arena.allocator.dupe([]const u8, params.items);
    const token_list = try pp.arena.allocator.dupe(Token, tokens.items);
    const name_str = pp.tokSliceSafe(macro_name);
    _ = try pp.defines.put(name_str, .{ .func = .{ .params = param_list, .var_args = var_args, .tokens = token_list } });
}
