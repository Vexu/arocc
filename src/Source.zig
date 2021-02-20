const Source = @This();

pub const Id = u16;
pub const Location = struct { start: u32, end: u32 };

path: []const u8,
buf: []const u8,
id: Id,

pub fn slice(source: Source, loc: Location) []const u8 {
    return source.buf[loc.start..loc.end];
}

pub fn lineCol(source: Source, loc: Location) struct { line: u32, col: u32 } {
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
    return .{ .line = line, .col = col };
}
