const std = @import("std");
const Compilation = @import("Compilation.zig");
const Preprocessor = @import("Preprocessor.zig");
const Parser = @import("Parser.zig");
const TokenIndex = @import("Tree.zig").TokenIndex;

const Pragma = @This();

pub const Error = Compilation.Error || error{ UnknownPragma, StopPreprocessing };

/// Called during Preprocessor.init
beforePreprocess: ?fn (*Pragma, *Compilation) void = null,

/// Called at the beginning of Parser.parse
beforeParse: ?fn (*Pragma, *Compilation) void = null,

/// Called at the end of Parser.parse if a Tree was successfully parsed
afterParse: ?fn (*Pragma, *Compilation) void = null,

/// Called during Compilation.deinit
deinit: fn (*Pragma, *Compilation) void,

/// Called whenever the preprocessor encounters this pragma. `start_idx` is the index
/// within `pp.tokens` of the pragma name token. `len` is the number of tokens in the
/// pragma, including the name token. It is always greater than zero.
/// As an example, given the following line:
///     #pragma GCC diagnostic error "-Wnewline-eof"
/// Then pp.tokens.get(start_idx) will return the `GCC` token and `len` will be 4
/// Return error.UnknownPragma to emit an `unsupported_pragma` diagnostic
/// Return error.StopPreprocessing to stop preprocessing the current file (see once.zig)
preprocessorHandler: ?fn (*Pragma, *Preprocessor, start_idx: TokenIndex, len: u32) Error!void = null,

/// Called during token pretty-printing (`-E` option). If this returns true, the pragma will
/// be printed; otherwise it will be omitted. start_idx and len behave the same as they do
/// in preprocessorHandler
preserveTokens: ?fn (*Pragma, *Preprocessor, start_idx: TokenIndex, len: u32) bool = null,

/// Same as preprocessorHandler except called during parsing
/// The parser's `p.tok_i` field must not be changed
parserHandler: ?fn (*Pragma, *Parser, start_idx: TokenIndex, len: u32) Compilation.Error!void = null,

pub fn pasteTokens(pp: *Preprocessor, start_idx: TokenIndex, len: u32) ![]const u8 {
    if (len == 0) return error.ExpectedStringLiteral;

    const char_top = pp.char_buf.items.len;
    defer pp.char_buf.items.len = char_top;
    var i: usize = 0;
    var paren_count: usize = 0;
    while (i < len) : (i += 1) {
        const tok = pp.tokens.get(start_idx + i);
        switch (tok.id) {
            .l_paren => {
                if (paren_count != i) return error.ExpectedStringLiteral;
                paren_count += 1;
            },
            .r_paren => {
                if (paren_count + i != len) return error.ExpectedStringLiteral;
                paren_count -= 1;
            },
            .string_literal => {
                const str = pp.expandedSlice(tok);
                try pp.char_buf.appendSlice(str[1 .. str.len - 1]);
            },
            else => return error.ExpectedStringLiteral,
        }
    }
    if (paren_count != 0) return error.ExpectedStringLiteral;
    return pp.char_buf.items[char_top..];
}

pub fn shouldPreserveTokens(self: *Pragma, pp: *Preprocessor, start_idx: TokenIndex, len: u32) bool {
    if (self.preserveTokens) |func| return func(self, pp, start_idx, len);
    return false;
}

pub fn preprocessorCB(self: *Pragma, pp: *Preprocessor, start_idx: TokenIndex, len: u32) Error!void {
    if (self.preprocessorHandler) |func| return func(self, pp, start_idx, len);
}

pub fn parserCB(self: *Pragma, p: *Parser, start_idx: TokenIndex, len: u32) Compilation.Error!void {
    const tok_index = p.tok_i;
    defer std.debug.assert(tok_index == p.tok_i);
    if (self.parserHandler) |func| return func(self, p, start_idx, len);
}
