const std = @import("std");
const mem = std.mem;
const Allocator = mem.Allocator;
const assert = std.debug.assert;
const Preprocessor = @import("Preprocessor.zig");
const Source = @import("Source.zig");

const Compilation = @This();

gpa: *Allocator,
sources: std.StringHashMap(Source),
color: bool,

pub fn init(gpa: *Allocator) Compilation {
    return .{
        .gpa = gpa,
        .sources = std.StringHashMap(Source).init(gpa),
        .color = std.io.getStdErr().supportsAnsiEscapeCodes(),
    };
}

pub fn printErr(comp: *Compilation, path: []const u8, lcs: Source.LCS, msg: []const u8) void {
    if (std.builtin.os.tag == .windows or !comp.color) {
        std.debug.print(
            "{s}:{d}:{d}: error: {s}\n{s}\n",
            .{ path, lcs.line, lcs.col, msg, lcs.str },
        );
        std.debug.print("{s: >[1]}^\n", .{ "", lcs.col - 1 });
    } else {
        const RED = "\x1b[31;1m";
        const GREEN = "\x1b[32;1m";
        const WHITE = "\x1b[37;1m";
        const RESET = "\x1b[0m";

        std.debug.print(
            WHITE ++
                "{s}:{d}:{d}: " ++
                RED ++
                "error: " ++
                WHITE ++
                "{s}\n" ++
                RESET ++
                "{s}\n",
            .{ path, lcs.line, lcs.col, msg, lcs.str },
        );
        std.debug.print("{s: >[1]}" ++ GREEN ++ "^" ++ RESET ++ "\n", .{ "", lcs.col - 1 });
    }
}

pub fn deinit(comp: *Compilation) void {
    {
        var it = comp.sources.iterator();
        while (it.next()) |source| {
            comp.gpa.free(source.value.path);
            comp.gpa.free(source.value.buf);
        }
    }
    comp.sources.deinit();
}

pub fn addSource(comp: *Compilation, path: []const u8) !Source {
    if (comp.sources.get(path)) |some| return some;

    const file = try std.fs.cwd().openFile(path, .{});
    defer file.close();

    const duped_path = try comp.gpa.dupe(u8, path);
    errdefer comp.gpa.free(duped_path);

    const contents = try file.reader().readAllAlloc(comp.gpa, std.math.maxInt(u32));
    errdefer comp.gpa.free(contents);

    const source = Source{
        .id = @intCast(Source.Id, comp.sources.count()),
        .path = duped_path,
        .buf = contents,
    };

    try comp.sources.put(duped_path, source);

    return source;
}
