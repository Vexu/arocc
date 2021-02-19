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

const Error = Allocator.Error || error{PreProcessingFailed};

pub fn preprocess(pp: *Preprocessor, source: Source) !void {
    var tokenizer = Tokenizer{
        .buf = source.buf,
        .source = source.id,
    };

    // Estimate how many new tokens this source will contain.
    const estimated_token_count = source.buf.len / 8;
    try pp.tokens.ensureCapacity(pp.tokens.items.len + estimated_token_count);

    var start_of_line = true;
    while (true) {
        const tok = tokenizer.next();
        switch (tok.id) {
            .hash => if (start_of_line) {
                const directive = tokenizer.next();
                switch (directive.id) {
                    .keyword_error => return pp.fail(source, "TODO error directive", directive),
                    .keyword_if => return pp.fail(source, "TODO if directive", directive),
                    .keyword_ifdef => return pp.fail(source, "TODO ifdef directive", directive),
                    .keyword_ifndef => return pp.fail(source, "TODO ifndef directive", directive),
                    .keyword_define => return pp.fail(source, "TODO define directive", directive),
                    .keyword_include => return pp.fail(source, "TODO include directive", directive),
                    .keyword_pragma => return pp.fail(source, "TODO pragma directive", directive),
                    .keyword_undef => {
                        const macro_name = tokenizer.next();
                        if (!macro_name.id.isIdentifier())
                            return pp.fail(source, "macro name missing", macro_name);

                        _ = pp.defines.remove(source.slice(tok.loc));
                    },
                    .keyword_else => return pp.fail(source, "#else without #if", directive),
                    .keyword_endif => return pp.fail(source, "#endif without #if", directive),
                    .nl => {},
                    .eof => {
                        try pp.tokens.append(tok);
                        return;
                    },
                    else => return pp.fail(source, "invalid preprocessing directive", directive),
                }
                start_of_line = true;
            },
            .nl => start_of_line = true,
            .eof => {
                try pp.tokens.append(tok);
                return;
            },
            else => {
                start_of_line = false;
                if (tok.id.isIdentifier()) if (pp.defines.get(source.slice(tok.loc))) |some| switch (some) {
                    .empty => continue,
                    .simple => |toks| {
                        try pp.tokens.appendSlice(toks);
                        continue;
                    },
                    .func => return pp.fail(source, "TODO func macro expansion", tok),
                };
                try pp.tokens.append(tok);
            }
        }
    }
}

pub fn fail(pp: *Preprocessor, source: Source, msg: []const u8, token: Token) Error {
    const line_col = source.lineCol(token.loc);
    std.debug.print("{s}:{d}:{d}: error: {s}\n", .{ source.path, line_col.line, line_col.col, msg });
    return error.PreProcessingFailed;
}
