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
