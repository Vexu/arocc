const std = @import("std");
const mem = std.mem;
const Allocator = mem.Allocator;
const assert = std.debug.assert;
const Preprocessor = @import("Preprocessor.zig");
const Source = @import("Source.zig");
const Tokenizer = @import("Tokenizer.zig");
const Token = Tokenizer.Token;

const Compilation = @This();

gpa: *Allocator,
sources: std.StringArrayHashMap(Source),
color: bool,

pub fn init(gpa: *Allocator) Compilation {
    return .{
        .gpa = gpa,
        .sources = std.StringArrayHashMap(Source).init(gpa),
        .color = std.io.getStdErr().supportsAnsiEscapeCodes(),
    };
}

pub fn printErrStart(comp: *Compilation, path: []const u8, lcs: Source.LCS) void {
    if (std.builtin.os.tag == .windows or !comp.color) {
        std.debug.print("{s}:{d}:{d}: error: ", .{ path, lcs.line, lcs.col });
    } else {
        const RED = "\x1b[31;1m";
        const WHITE = "\x1b[37;1m";

        std.debug.print(WHITE ++ "{s}:{d}:{d}: " ++ RED ++ "error: " ++ WHITE, .{ path, lcs.line, lcs.col });
    }
}

pub fn printErrEnd(comp: *Compilation, lcs: Source.LCS) void {
    if (std.builtin.os.tag == .windows or !comp.color) {
        std.debug.print("\n{s}\n", .{lcs.str});
        std.debug.print("{s: >[1]}^\n", .{ "", lcs.col - 1 });
    } else {
        const GREEN = "\x1b[32;1m";
        const WHITE = "\x1b[37;1m";
        const RESET = "\x1b[0m";

        std.debug.print("\n" ++ RESET ++ "{s}\n", .{lcs.str});
        std.debug.print("{s: >[1]}" ++ GREEN ++ "^" ++ RESET ++ "\n", .{ "", lcs.col - 1 });
    }
}

pub fn deinit(comp: *Compilation) void {
    for (comp.sources.items()) |source| {
        comp.gpa.free(source.value.path);
        comp.gpa.free(source.value.buf);
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
        .id = @intToEnum(Source.Id, @intCast(u15, comp.sources.count())),
        .path = duped_path,
        .buf = contents,
    };

    try comp.sources.put(duped_path, source);

    return source;
}
