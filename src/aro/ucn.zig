//! Universal Character Name support

const std = @import("std");

const Kind = enum {
    /// Valid not escaped char
    normal,
    /// Not escaped, but not valid UTF-8
    invalid_utf_8,
    /// Valid UCN char
    ucn,
    /// Incomplete UCN escape sequence
    incomplete_ucn,
    /// UCN escape sequence does not specify a unicode code point
    invalid_codepoint,
    /// UCN names a control character
    control,
    /// UCN names a basic character set character
    not_allowed,
};

pub const DecodedUniversalChar = struct {
    codepoint: u32,
    consumed: usize,
    buf: []const u8,
    kind: Kind,
};

/// Decodes a C99-style universal character name (e.g., \uXXXX or \UXXXXXXXX)
/// into a unicode codepoint. Returns the decoded character and the number of
/// bytes consumed from the input string.
fn decodeUniversalChar(input: []const u8, output: []u8) DecodedUniversalChar {
    std.debug.assert(input.len >= 2 and input[0] == '\\' and (input[1] == 'u' or input[1] == 'U'));
    const is_long = input[1] == 'U';
    const required: usize = if (is_long) 10 else 6;

    if (input.len < required) {
        return .{
            .codepoint = 0,
            .consumed = input.len,
            .buf = input,
            .kind = .incomplete_ucn,
        };
    }

    const hex_part = input[2..required];
    var codepoint: u32 = 0;
    for (hex_part, 0..) |c, i| {
        codepoint *= 16;
        const value = switch (c) {
            '0'...'9' => c - '0',
            'a'...'f' => 10 + (c - 'a'),
            'A'...'F' => 10 + (c - 'A'),
            else => return .{ .codepoint = 0, .consumed = i, .buf = input[0..i], .kind = .incomplete_ucn },
        };
        codepoint += value;
    }
    if (codepoint > std.math.maxInt(u21)) {
        return .{ .codepoint = 0, .consumed = required, .buf = input, .kind = .invalid_codepoint };
    }

    const len = std.unicode.utf8Encode(@as(u21, @intCast(codepoint)), output) catch {
        return .{ .codepoint = codepoint, .consumed = required, .buf = input, .kind = .invalid_codepoint };
    };
    const kind: Kind = switch (codepoint) {
        0...0x1F, 0x7F...0x9F => .control,
        0x20...0x7E => .not_allowed,
        else => .ucn,
    };
    return .{ .codepoint = codepoint, .consumed = required, .buf = output[0..len], .kind = kind };
}

pub const CharIterator = struct {
    str: []const u8,
    i: usize,
    buf: [10]u8,

    pub fn init(str: []const u8) CharIterator {
        return .{ .str = str, .i = 0, .buf = undefined };
    }

    pub fn next(self: *@This()) ?DecodedUniversalChar {
        if (self.i >= self.str.len) return null;
        if (self.str[self.i] == '\\' and self.i + 1 < self.str.len and (self.str[self.i + 1] == 'u' or self.str[self.i + 1] == 'U')) {
            const decoded = decodeUniversalChar(self.str[self.i..], self.buf[0..]);
            self.i += decoded.consumed;
            return decoded;
        } else {
            const len = std.unicode.utf8ByteSequenceLength(self.str[self.i]) catch {
                defer self.i += 1;
                return .{ .codepoint = self.str[self.i], .consumed = 1, .buf = self.str[self.i..][0..1], .kind = .invalid_utf_8 };
            };
            defer self.i += len;
            return .{ .codepoint = 0, .consumed = len, .buf = self.str[self.i..][0..len], .kind = .normal };
        }
    }
};
