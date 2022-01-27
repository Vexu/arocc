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
    line: u32 = 0,

    pub fn eql(a: Location, b: Location) bool {
        return a.id == b.id and a.byte_offset == b.byte_offset and a.line == b.line;
    }
};

path: []const u8,
buf: []const u8,
id: Id,
invalid_utf8_loc: ?Location = null,

const LineCol = struct { line: []const u8, col: u32, width: u32 };

pub fn lineCol(source: Source, byte_offset: u32) LineCol {
    var start: usize = 0;
    if (std.mem.lastIndexOfScalar(u8, source.buf[0..byte_offset], '\n')) |some| start = some + 1;
    var i: usize = start;
    var col: u32 = 1;
    var width: u32 = 0;

    while (i < byte_offset) : (col += 1) { // TODO this is still incorrect, but better
        const len = std.unicode.utf8ByteSequenceLength(source.buf[i]) catch unreachable;
        const cp = std.unicode.utf8Decode(source.buf[i..][0..len]) catch unreachable;
        width += codepointWidth(cp);
        i += len;
    }
    const slice = source.buf[start..];
    const nl = std.mem.indexOfAny(u8, slice, "\n\r") orelse slice.len;
    return .{ .line = slice[0..nl], .col = col, .width = width };
}

fn codepointWidth(cp: u32) u32 {
    return switch (cp) {
        0x1100...0x115F,
        0x2329,
        0x232A,
        0x2E80...0x303F,
        0x3040...0x3247,
        0x3250...0x4DBF,
        0x4E00...0xA4C6,
        0xA960...0xA97C,
        0xAC00...0xD7A3,
        0xF900...0xFAFF,
        0xFE10...0xFE19,
        0xFE30...0xFE6B,
        0xFF01...0xFF60,
        0xFFE0...0xFFE6,
        0x1B000...0x1B001,
        0x1F200...0x1F251,
        0x20000...0x3FFFD,
        0x1F300...0x1F5FF,
        0x1F900...0x1F9FF,
        => 2,
        else => 1,
    };
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
