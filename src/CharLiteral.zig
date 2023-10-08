const std = @import("std");
const Compilation = @import("Compilation.zig");
const Type = @import("Type.zig");
const Diagnostics = @import("Diagnostics.zig");
const Tokenizer = @import("Tokenizer.zig");
const mem = std.mem;

pub const Item = union(enum) {
    /// decoded escape
    value: u32,
    /// Char literal in the source text is not utf8 encoded
    improperly_encoded: []const u8,
    /// 1 or more unescaped bytes
    utf8_text: std.unicode.Utf8View,
};

const CharDiagnostic = struct {
    tag: Diagnostics.Tag,
    extra: Diagnostics.Message.Extra,
};

pub const Kind = enum {
    char,
    wide,
    utf_8,
    utf_16,
    utf_32,

    pub fn classify(id: Tokenizer.Token.Id) Kind {
        return switch (id) {
            .char_literal,
            .string_literal,
            => .char,
            .char_literal_utf_8,
            .string_literal_utf_8,
            => .utf_8,
            .char_literal_wide,
            .string_literal_wide,
            => .wide,
            .char_literal_utf_16,
            .string_literal_utf_16,
            => .utf_16,
            .char_literal_utf_32,
            .string_literal_utf_32,
            => .utf_32,
            else => unreachable,
        };
    }

    /// Largest unicode codepoint that can be represented by this character kind
    /// May be smaller than the largest value that can be represented.
    /// For example u8 char literals may only specify 0-127 via literals or
    /// character escapes, but may specify up to \xFF via hex escapes.
    fn maxCodepoint(kind: Kind, comp: *const Compilation) u21 {
        return @intCast(switch (kind) {
            .char => std.math.maxInt(u7),
            .wide => @min(0x10FFFF, comp.types.wchar.maxInt(comp)),
            .utf_8 => std.math.maxInt(u7),
            .utf_16 => std.math.maxInt(u16),
            .utf_32 => 0x10FFFF,
        });
    }

    /// Largest integer that can be represented by this character kind
    fn maxInt(kind: Kind, comp: *const Compilation) u32 {
        return @intCast(switch (kind) {
            .char, .utf_8 => std.math.maxInt(u8),
            .wide => comp.types.wchar.sizeof(comp).?,
            .utf_16 => std.math.maxInt(u16),
            .utf_32 => std.math.maxInt(u32),
        });
    }

    pub fn charLiteralType(kind: Kind, comp: *const Compilation) Type {
        return switch (kind) {
            .char => .{ .specifier = .int },
            .wide => comp.types.wchar,
            .utf_8 => .{ .specifier = .uchar },
            .utf_16 => comp.types.uint_least16_t,
            .utf_32 => comp.types.uint_least32_t,
        };
    }
};

pub const Parser = struct {
    literal: []const u8,
    i: usize = 0,
    max_codepoint: u21,
    max_int: u32,
    /// We only want to issue a max of 1 error per char literal
    errored: bool = false,
    errors: std.BoundedArray(CharDiagnostic, 4) = .{},
    comp: *const Compilation,

    pub fn init(literal: []const u8, kind: Kind, comp: *const Compilation) Parser {
        return .{
            .literal = literal,
            .comp = comp,
            .max_int = kind.maxInt(comp),
            .max_codepoint = kind.maxCodepoint(comp),
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

    fn parseUnicodeEscape(self: *Parser) ?Item {
        const start = self.i;

        std.debug.assert(self.literal[self.i] == '\\');

        const kind = self.literal[self.i + 1];
        std.debug.assert(kind == 'u' or kind == 'U');

        self.i += 2;
        if (self.i >= self.literal.len or !std.ascii.isHex(self.literal[self.i])) {
            self.err(.non_hex_ucn, .{ .ascii = @intCast(kind) });
            return null;
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
            return null;
        }

        if (count != expected_len) {
            self.err(.incomplete_universal_character, .{ .none = {} });
            return null;
        }

        if (val > std.math.maxInt(u21) or !std.unicode.utf8ValidCodepoint(@intCast(val))) {
            self.err(.invalid_universal_character, .{ .unsigned = start });
            return null;
        }

        if (val > self.max_codepoint) {
            self.err(.char_too_large, .{ .none = {} });
        }

        if (val < 0xA0 and (val != '$' and val != '@' and val != '`')) {
            const is_error = !self.comp.langopts.standard.atLeast(.c2x);
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
        return .{ .value = val };
    }

    fn parseEscapedChar(self: *Parser) Item {
        self.i += 1;

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
            'x' => return .{ .value = self.parseNumberEscape(.hex) },
            '0'...'7' => return .{ .value = self.parseNumberEscape(.octal) },
            'u', 'U' => unreachable, // handled by parseUnicodeEscape
            else => unreachable,
        }
    }

    fn parseNumberEscape(self: *Parser, base: EscapeBase) u32 {
        var val: u32 = 0;
        var count: usize = 0;
        var overflowed = false;
        defer self.i += count;
        const slice = switch (base) {
            .octal => self.literal[self.i..@min(self.literal.len, self.i + 3)], // max 3 chars
            .hex => blk: {
                self.i += 1;
                break :blk self.literal[self.i..]; // skip over 'x'; could have an arbitrary number of chars
            },
        };
        for (slice) |c| {
            const char = std.fmt.charToDigit(c, @intFromEnum(base)) catch break;
            val, const overflow = @shlWithOverflow(val, base.log2());
            if (overflow != 0) overflowed = true;
            val += char;
            count += 1;
        }
        if (overflowed or val > self.max_int) {
            self.err(.escape_sequence_overflow, .{ .unsigned = 0 });
        }
        return val;
    }
};

const EscapeBase = enum(u8) {
    octal = 8,
    hex = 16,

    fn log2(base: EscapeBase) u4 {
        return switch (base) {
            .octal => 3,
            .hex => 4,
        };
    }
};
