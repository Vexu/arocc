const std = @import("std");
const CParser = @import("Parser.zig");
const Diagnostics = @import("Diagnostics.zig");
const mem = std.mem;

pub const Item = union(enum) {
    /// escaped char
    codepoint: u21,
    /// Char literal in the source text is not utf8 encoded
    improperly_encoded: []const u8,
    /// 1 or more unescaped bytes
    utf8_text: std.unicode.Utf8View,

    const replacement: Item = .{ .codepoint = 0xFFFD };
};

pub const Parser = struct {
    literal: []const u8,
    i: usize = 0,
    /// We only want to issue a max of 1 error per char literal
    errored: bool = false,

    pub fn init(literal: []const u8) Parser {
        const start = mem.indexOfScalar(u8, literal, '\'').? + 1; // trim leading quote + specifier if any
        return .{
            .literal = literal[start .. literal.len - 1], // trim trailing quote
            .i = 0,
        };
    }

    pub fn next(self: *Parser, p: *CParser) !?Item {
        if (self.i >= self.literal.len) return null;

        const start = self.i;
        if (self.literal[start] != '\\') {
            self.i = mem.indexOfScalarPos(u8, self.literal, start + 1, '\\') orelse self.literal.len;
            const unescaped_slice = self.literal[start..self.i];

            const view = std.unicode.Utf8View.init(unescaped_slice) catch {
                return .{ .improperly_encoded = self.literal[start..self.i] };
            };
            return .{ .utf8_text = view };
        }
        switch (self.literal[start + 1]) {
            'u', 'U' => return try self.parseUnicodeEscape(p),
            else => return try self.parseEscapedChar(p),
        }
    }

    fn parseUnicodeEscape(self: *Parser, p: *CParser) !Item {
        const start = self.i;

        std.debug.assert(self.literal[self.i] == '\\');

        const kind = self.literal[self.i + 1];
        std.debug.assert(kind == 'u' or kind == 'U');

        self.i += 2;
        if (self.i >= self.literal.len or !std.ascii.isHex(self.literal[self.i])) {
            self.errored = true;
            try p.errExtra(.non_hex_ucn, p.tok_i, .{ .ascii = @intCast(kind) });
            return Item.replacement;
        }
        const expected_len: usize = if (kind == 'u') 4 else 8;
        var overflowed = false;
        var count: usize = 0;
        var val: u32 = 0;

        for (self.literal[self.i..], 0..) |c, i| {
            if (i == expected_len) break;

            const char = std.fmt.charToDigit(c, 16) catch {
                break;
            };

            val, const overflow = @shlWithOverflow(val, 4);
            overflowed = overflowed or overflow != 0;
            val |= char;
            count += 1;
        }
        self.i += expected_len;

        if (overflowed) {
            self.errored = true;
            try p.errExtra(.escape_sequence_overflow, p.tok_i, .{ .unsigned = start });
            return Item.replacement;
        }

        if (count != expected_len) {
            self.errored = true;
            try p.err(.incomplete_universal_character);
            return Item.replacement;
        }

        if (val > std.math.maxInt(u21) or !std.unicode.utf8ValidCodepoint(@intCast(val))) {
            self.errored = true;
            try p.errExtra(.invalid_universal_character, p.tok_i, .{ .unsigned = start });
            return Item.replacement;
        }

        if (val < 0xA0 and (val != '$' and val != '@' and val != '`')) {
            const is_error = !p.comp.langopts.standard.atLeast(.c2x);
            if (val >= 0x20 and val <= 0x7F) {
                const tag: Diagnostics.Tag = if (is_error) .ucn_basic_char_error else .ucn_basic_char_warning;
                try p.errExtra(tag, p.tok_i, .{ .ascii = @intCast(val) });
            } else {
                const tag: Diagnostics.Tag = if (is_error) .ucn_control_char_error else .ucn_control_char_warning;
                try p.err(tag);
            }
        }

        try p.err(.c89_ucn_in_literal);

        return .{ .codepoint = @intCast(val) };
    }

    fn parseEscapedChar(self: *Parser, p: *CParser) !Item {
        self.i += 1;
        defer self.i += 1;

        switch (self.literal[self.i]) {
            '\n' => unreachable, // removed by line splicing
            '\r' => unreachable, // removed by line splicing
            '\'', '\"', '\\', '?' => |c| return .{ .codepoint = c },
            'n' => return .{ .codepoint = '\n' },
            'r' => return .{ .codepoint = '\r' },
            't' => return .{ .codepoint = '\t' },
            'a' => return .{ .codepoint = 0x07 },
            'b' => return .{ .codepoint = 0x08 },
            'e' => {
                try p.errExtra(.non_standard_escape_char, p.tok_i, .{ .unsigned = self.i });
                return .{ .codepoint = 0x1B };
            },
            'f' => return .{ .codepoint = 0x0C },
            'v' => return .{ .codepoint = 0x0B },
            'x' => return .{ .codepoint = try p.parseNumberEscape(p.tok_i, 16, self.literal, &self.i) },
            '0'...'7' => return .{ .codepoint = try p.parseNumberEscape(p.tok_i, 8, self.literal, &self.i) },
            'u', 'U' => unreachable, // handled by parseUnicodeEscape
            else => unreachable,
        }
    }
};
