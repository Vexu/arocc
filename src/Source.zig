const Source = @This();

pub const Id = enum(u16) {
    _,

    const generated_bit: u16 = 1 << 15;
    const generated_mask: u16 = generated_bit - 1;

    pub fn index(id: Id) u16 {
        return @enumToInt(id) & generated_mask;
    }

    pub fn isGenerated(id: Id) bool {
        return (@enumToInt(id) & generated_bit) != 0;
    }

    pub fn markGenerated(id: *Id) void {
        id.* = @intToEnum(Id, (@enumToInt(id.*) | Id.generated_bit));
    }
};

pub const Location = struct { start: u32, end: u32 };

path: []const u8,
buf: []const u8,
id: Id,

pub const LCS = struct { line: u32, col: u32, str: []const u8 };

pub fn lineColString(source: Source, loc_start: u32) LCS {
    if (source.id.isGenerated()) return .{ .line = 0, .col = 0, .str = "" };
    var line: u32 = 1;
    var col: u32 = 1;
    var i: u32 = 0;
    while (i < loc_start) : (i += 1) {
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
