const Source = @This();

pub const Id = u16;
pub const Location = struct { start: u32, end: u32 };

path: []const u8,
buf: []const u8,
id: Id,

pub fn slice(source: Source, loc: Location) []const u8 {
    return source.buf[loc.start..loc.end];
}

pub const LCS = struct { line: u32, col: u32, str: []const u8 };

pub fn lineColString(source: Source, loc: Location) LCS {
    var line: u32 = 1;
    var col: u32 = 1;
    var i: u32 = 0;
    while (i < loc.start) : (i += 1) {
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
