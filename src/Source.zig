const std = @import("std");
const Source = @This();

pub const Id = enum(u32) {
    unused = 0,
    generated = 1,
    _,
};

pub const Location = struct {
    id: Id = .unused,
    byte_offset: u32 = 0,
    next: ?*Location = null,
};

path: []const u8,
buf: []const u8,
id: Id,
invalid_utf8_loc: ?Location = null,

pub const LCS = struct { line: u32, col: u32, str: []const u8 };

pub fn lineColString(source: Source, byte_offset: u32) LCS {
    var line: u32 = 1;
    var col: u32 = 1;
    var i: u32 = 0;
    while (i < byte_offset) : (i += 1) {
        if (source.buf[i] == '\n') {
            line += 1;
            col = 1;
        } else {
            col += 1;
        }
    }
    const start = i - (col - 1);
    while (i < source.buf.len) : (i += 1) {
        if (source.buf[i] == '\n') break;
    }
    return .{ .line = line, .col = col, .str = source.buf[start..i] };
}

/// Returns the first offset, if any, in buf where an invalid utf8 sequence
/// is found. Code adapted from std.unicode.utf8ValidateSlice
fn offsetOfInvalidUtf8(buf: []const u8) ?u32 {
    std.debug.assert(buf.len <= std.math.maxInt(u32));
    var i: u32 = 0;
    while (i < buf.len) {
        if (std.unicode.utf8ByteSequenceLength(buf[i])) |cp_len| {
            if (i + cp_len > buf.len) return i;
            if (std.meta.isError(std.unicode.utf8Decode(buf[i .. i + cp_len]))) return i;
            i += cp_len;
        } else |_| return i;
    }
    return null;
}

pub fn checkUtf8(source: *Source) void {
    if (offsetOfInvalidUtf8(source.buf)) |offset| {
        source.invalid_utf8_loc = Location{ .id = source.id, .byte_offset = offset };
    }
}
