const std = @import("std");
const mem = std.mem;
const Allocator = mem.Allocator;
const assert = std.debug.assert;
const Preprocessor = @import("Preprocessor.zig");
const Source = @import("Source.zig");

const Compilation = @This();

gpa: *Allocator,
sources: std.StringHashMap(Source),

pub fn init(gpa: *Allocator) Compilation {
    return .{
        .gpa = gpa,
        .sources = std.StringHashMap(Source).init(gpa),
    };
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

