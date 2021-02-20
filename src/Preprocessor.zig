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

const Macro = union(enum) {
    empty,
    func: struct {
        args: []const []const u8,
        tokens: []const Token,
    },
    simple: []const Token,
};

comp: *Compilation,
arena: std.heap.ArenaAllocator,
defines: DefineMap,
tokens: std.ArrayList(Token),

pub fn init(comp: *Compilation) Preprocessor {
    return .{
        .comp = comp,
        .arena = std.heap.ArenaAllocator.init(comp.gpa),
        .defines = DefineMap.init(comp.gpa),
        .tokens = std.ArrayList(Token).init(comp.gpa),
    };
}

pub fn deinit(pp: *Preprocessor) void {
    pp.defines.deinit();
    pp.tokens.deinit();
    pp.arena.deinit();
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
                        var slice = tokenizer.source.slice(loc);
                        slice = mem.trim(u8, slice, " \t\x0B\x0C");
                        return pp.fail(tokenizer.source, slice, loc);
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
                    .keyword_define => return pp.fail(tokenizer.source, "TODO define directive", directive.loc),
                    .keyword_include => return pp.fail(tokenizer.source, "TODO include directive", directive.loc),
                    .keyword_pragma => return pp.fail(tokenizer.source, "TODO pragma directive", directive.loc),
                    .keyword_undef => {
                        const macro_name = try pp.expectMacroName(tokenizer);

                        _ = pp.defines.remove(macro_name);
                        try pp.expectNl(tokenizer, true);
                    },
                    .keyword_elif => {
                        if (cont == .until_eof) return pp.fail(tokenizer.source, "#elif without #if", directive.loc);
                        if (cont == .until_endif) return pp.fail(tokenizer.source, "#elif after #else", directive.loc);
                        return directive.id;
                    },
                    .keyword_else => {
                        if (cont == .until_eof) return pp.fail(tokenizer.source, "#else without #if", directive.loc);
                        if (cont == .until_endif) return pp.fail(tokenizer.source, "#else after #else", directive.loc);
                        return directive.id;
                    },
                    .keyword_endif => {
                        if (cont == .until_eof) return pp.fail(tokenizer.source, "#endif without #if", directive.loc);
                        return directive.id;
                    },
                    .nl => {},
                    .eof => {
                        if (cont != .until_eof) return pp.fail(tokenizer.source, "unterminated conditional directive", directive.loc);
                        try pp.tokens.append(directive);
                        return directive.id;
                    },
                    else => return pp.fail(tokenizer.source, "invalid preprocessing directive", directive.loc),
                }
                start_of_line = true;
            },
            .nl => start_of_line = true,
            .eof => {
                if (cont != .until_eof) return pp.fail(tokenizer.source, "unterminated conditional directive", tok.loc);
                try pp.tokens.append(tok);
                return tok.id;
            },
            else => {
                start_of_line = false;
                if (tok.id.isIdentifier()) {
                    if (pp.defines.get(tokenizer.source.slice(tok.loc))) |some| switch (some) {
                        .empty => continue,
                        .simple => |toks| {
                            try pp.tokens.appendSlice(toks);
                            continue;
                        },
                        .func => return pp.fail(tokenizer.source, "TODO func macro expansion", tok.loc),
                    };
                    tok.id = .identifier;
                }
                try pp.tokens.append(tok);
            },
        }
    }
}

fn fail(pp: *Preprocessor, source: Source, msg: []const u8, loc: Source.Location) Error {
    const line_col = source.lineCol(loc);
    std.debug.print("{s}:{d}:{d}: error: {s}\n", .{ source.path, line_col.line, line_col.col, msg });
    return error.PreprocessingFailed;
}

fn expectMacroName(pp: *Preprocessor, tokenizer: *Tokenizer) Error![]const u8 {
    const macro_name = tokenizer.next();
    if (!macro_name.id.isIdentifier()) return pp.fail(tokenizer.source, "macro name missing", macro_name.loc);
    return tokenizer.source.slice(macro_name.loc);
}

fn expectNl(pp: *Preprocessor, tokenizer: *Tokenizer, allow_eof: bool) Error!void {
    const tok = tokenizer.next();
    if (tok.id == .eof) {
        if (!allow_eof) return fail(pp, tokenizer.source, "unterminated conditional directive", tok.loc);
        return;
    }
    if (tok.id != .nl) return fail(pp, tokenizer.source, "extra tokens at end of macro directive", tok.loc);
}

fn expandBoolExpr(pp: *Preprocessor, tokenizer: *Tokenizer) Error!bool {
    const next = tokenizer.next();
    return fail(pp, tokenizer.source, "TODO macro bool condition", next.loc);
}


/// Handles one level of #if ... #endif.
fn expandConditional(pp: *Preprocessor, tokenizer: *Tokenizer, first_cond: bool) Error!void {
    var cond = first_cond;
    while (true) {
        if (cond) {
            const directive = try pp.preprocessInternal(tokenizer, .until_else);
            switch (directive) {
                .keyword_endif => return pp.expectNl(tokenizer, true),
                .keyword_else => {}, // fallthrough
                .keyword_elif => {
                    cond = try pp.expandBoolExpr(tokenizer);
                    continue;
                },
                else => unreachable,
            }
        }
        const directive = try pp.skip(tokenizer);
        switch (directive) {
            .keyword_endif => return pp.expectNl(tokenizer, true),
            .keyword_else => {
                _ = try pp.preprocessInternal(tokenizer, .until_endif);
                return;
            },
            .keyword_elif => {
                cond = try pp.expandBoolExpr(tokenizer);
            },
            else => unreachable,
        }
    }
}

/// Skip until #else #elif #endif, return last directive token id.
/// Also skips nested #if ... #endif's.
fn skip(pp: *Preprocessor, tokenizer: *Tokenizer) Error!Token.Id {
    var ifs_seen: u32 = 0;
    var line_start = true;
    while (tokenizer.index < tokenizer.buf.len) : (tokenizer.index += 1) {
        if (line_start) {
            line_start = false;
            var hash = tokenizer.next();
            while (hash.id == .nl) {
                hash = tokenizer.next();
            }
            if (hash.id != .hash) continue;
            const directive = tokenizer.next();
            switch (directive.id) {
                .keyword_else, .keyword_elif => return directive.id,
                .keyword_endif => {
                    if (ifs_seen == 0) return directive.id;
                    ifs_seen -= 1;
                },
                .keyword_if, .keyword_ifdef, .keyword_ifndef => ifs_seen += 1,
                else => {},
            }
        } else if (tokenizer.buf[tokenizer.index] == '\n') {
            line_start = true;
        } else {
            line_start = false;
        }
    } else {
        return pp.fail(tokenizer.source, "unterminated conditional directive", .{ .start = tokenizer.index - 1, .end = tokenizer.index });
    }
}
