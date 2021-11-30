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
};

path: []const u8,
buf: []const u8,
id: Id,
invalid_utf8_loc: ?Location = null,

const LineCol = struct { line: []const u8, col: u32 };

pub fn lineCol(source: Source, byte_offset: u32) LineCol {
    var start = byte_offset;
    while (true) : (start -= 1) {
        if (start == 0) break;
        if (start < source.buf.len and source.buf[start] == '\n') {
            start += 1;
            break;
        }
    }
    const col = byte_offset - start + 1; // TODO unicode awareness
    return .{ .line = std.mem.sliceTo(source.buf[start..], '\n'), .col = col };
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
