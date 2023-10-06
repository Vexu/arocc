const std = @import("std");
const Diagnostics = @import("Diagnostics.zig");
const LangOpts = @import("LangOpts.zig");
const mem = std.mem;

pub const Item = union(enum) {
    /// hex/octal escape
    value: u32,
    /// Char literal in the source text is not utf8 encoded
    improperly_encoded: []const u8,
    /// 1 or more unescaped bytes
    utf8_text: std.unicode.Utf8View,

    const replacement: Item = .{ .value = 0xFFFD };
};

const CharDiagnostic = struct {
    tag: Diagnostics.Tag,
    extra: Diagnostics.Message.Extra,
};

pub const Parser = struct {
    literal: []const u8,
    i: usize = 0,
    /// We only want to issue a max of 1 error per char literal
    errored: bool = false,
    errors: std.BoundedArray(CharDiagnostic, 4) = .{},
    standard: LangOpts.Standard,
    codepoint_buf: [4]u8,

    pub fn init(literal: []const u8, standard: LangOpts.Standard) Parser {
        return .{
            .literal = literal,
            .standard = standard,
            .codepoint_buf = undefined,
        };
    }

    pub fn err(self: *Parser, tag: Diagnostics.Tag, extra: Diagnostics.Message.Extra) void {
        if (self.errored) return;
        self.errored = true;
        self.errors.append(.{ .tag = tag, .extra = extra }) catch {};
    }

    fn warn(self: *Parser, tag: Diagnostics.Tag, extra: Diagnostics.Message.Extra) void {
        if (self.errored) return;
        self.errors.append(.{ .tag = tag, .extra = extra }) catch {};
    }

    pub fn next(self: *Parser) ?Item {
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
            'u', 'U' => return self.parseUnicodeEscape(),
            else => return self.parseEscapedChar(),
        }
    }

    fn parseUnicodeEscape(self: *Parser) Item {
        const start = self.i;

        std.debug.assert(self.literal[self.i] == '\\');

        const kind = self.literal[self.i + 1];
        std.debug.assert(kind == 'u' or kind == 'U');

        self.i += 2;
        if (self.i >= self.literal.len or !std.ascii.isHex(self.literal[self.i])) {
            self.err(.non_hex_ucn, .{ .ascii = @intCast(kind) });
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
            self.err(.escape_sequence_overflow, .{ .unsigned = start });
            return Item.replacement;
        }

        if (count != expected_len) {
            self.err(.incomplete_universal_character, .{ .none = {} });
            return Item.replacement;
        }

        if (val > std.math.maxInt(u21) or !std.unicode.utf8ValidCodepoint(@intCast(val))) {
            self.err(.invalid_universal_character, .{ .unsigned = start });
            return Item.replacement;
        }

        if (val < 0xA0 and (val != '$' and val != '@' and val != '`')) {
            const is_error = !self.standard.atLeast(.c2x);
            if (val >= 0x20 and val <= 0x7F) {
                if (is_error) {
                    self.err(.ucn_basic_char_error, .{ .ascii = @intCast(val) });
                } else {
                    self.warn(.ucn_basic_char_warning, .{ .ascii = @intCast(val) });
                }
            } else {
                if (is_error) {
                    self.err(.ucn_control_char_error, .{ .none = {} });
                } else {
                    self.warn(.ucn_control_char_warning, .{ .none = {} });
                }
            }
        }

        self.warn(.c89_ucn_in_literal, .{ .none = {} });

        const to_write = std.unicode.utf8Encode(@intCast(val), &self.codepoint_buf) catch unreachable; // validated above
        const view = std.unicode.Utf8View.initUnchecked(self.codepoint_buf[0..to_write]);

        return .{ .utf8_text = view };
    }

    fn parseEscapedChar(self: *Parser) Item {
        self.i += 1;
        defer self.i += 1;

        switch (self.literal[self.i]) {
            '\n' => unreachable, // removed by line splicing
            '\r' => unreachable, // removed by line splicing
            '\'', '\"', '\\', '?' => |c| return .{ .value = c },
            'n' => return .{ .value = '\n' },
            'r' => return .{ .value = '\r' },
            't' => return .{ .value = '\t' },
            'a' => return .{ .value = 0x07 },
            'b' => return .{ .value = 0x08 },
            'e' => {
                self.warn(.non_standard_escape_char, .{ .unsigned = self.i });
                return .{ .value = 0x1B };
            },
            'f' => return .{ .value = 0x0C },
            'v' => return .{ .value = 0x0B },
            'x' => return .{ .value = self.parseHexEscape() },
            '0'...'7' => return .{ .value = self.parseOctalEscape() },
            'u', 'U' => unreachable, // handled by parseUnicodeEscape
            else => unreachable,
        }
    }

    fn parseHexEscape(self: *Parser) u32 {
        var val: u32 = 0;
        var count: usize = 0;
        var overflowed = false;
        defer self.i += count;

        for (self.literal[self.i + 1 ..]) |c| {
            const char = std.fmt.charToDigit(c, 16) catch break;
            val, const overflow = @shlWithOverflow(val, 4);
            if (overflow != 0) overflowed = true;
            val += char;
            count += 1;
        }
        if (overflowed) {
            std.debug.print("overflowed!\n", .{});
        }
        return val;
    }

    fn parseOctalEscape(self: *Parser) u32 {
        var val: u32 = 0;
        var count: usize = 0;
        defer self.i += count - 1;

        for (self.literal[self.i..], 0..) |c, i| {
            if (i == 3) break;
            const char = std.fmt.charToDigit(c, 8) catch break;
            val <<= 3;
            val += char;
            count += 1;
        }
        return val;
    }
};
