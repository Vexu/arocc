const std = @import("std");
const mem = std.mem;
const Allocator = mem.Allocator;
const assert = std.debug.assert;
const Preprocessor = @import("Preprocessor.zig");
const Source = @import("Source.zig");
const Tokenizer = @import("Tokenizer.zig");
const Token = Tokenizer.Token;
const Diagnostics = @import("Diagnostics.zig");

const Compilation = @This();

pub const Error = error{
    /// A fatal error has ocurred and compilation has stopped.
    FatalError,
} || Allocator.Error;

gpa: *Allocator,
sources: std.StringArrayHashMap(Source),
diag: Diagnostics,
include_dirs: std.ArrayList([]const u8),
system_include_dirs: std.ArrayList([]const u8),
output_name: ?[]const u8 = null,

pub fn init(gpa: *Allocator) Compilation {
    return .{
        .gpa = gpa,
        .sources = std.StringArrayHashMap(Source).init(gpa),
        .diag = Diagnostics.init(gpa),
        .include_dirs = std.ArrayList([]const u8).init(gpa),
        .system_include_dirs = std.ArrayList([]const u8).init(gpa),
    };
}

pub fn deinit(comp: *Compilation) void {
    for (comp.sources.items()) |source| {
        comp.gpa.free(source.value.path);
        comp.gpa.free(source.value.buf);
    }
    comp.sources.deinit();
    comp.diag.deinit();
    comp.include_dirs.deinit();
    comp.system_include_dirs.deinit();
}

pub fn getSource(comp: *Compilation, id: Source.Id) Source {
    return comp.sources.items()[@enumToInt(id) - 2].value;
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
        .id = @intToEnum(Source.Id, @intCast(u32, comp.sources.count() + 2)),
        .path = duped_path,
        .buf = contents,
    };

    try comp.sources.put(duped_path, source);

    return source;
}

pub fn findInclude(comp: *Compilation, tok: Token, filename: []const u8, search_cwd: bool) !Source {
    var path_buf: [std.fs.MAX_PATH_BYTES]u8 = undefined;
    var fib = std.heap.FixedBufferAllocator.init(&path_buf);
    if (search_cwd) blk: {
        const source = comp.getSource(tok.source);
        const path = if (std.fs.path.dirname(source.path)) |some|
            std.fs.path.join(&fib.allocator, &.{ some, filename }) catch break :blk
        else
            filename;
        if (comp.addSource(path)) |some|
            return some
        else |err| switch (err) {
            error.OutOfMemory => return error.OutOfMemory,
            else => {},
        }
    }
    for (comp.include_dirs.items) |dir| {
        fib.end_index = 0;
        const path = std.fs.path.join(&fib.allocator, &.{ dir, filename }) catch continue;
        if (comp.addSource(path)) |some|
            return some
        else |err| switch (err) {
            error.OutOfMemory => return error.OutOfMemory,
            else => {},
        }
    }
    for (comp.system_include_dirs.items) |dir| {
        fib.end_index = 0;
        const path = std.fs.path.join(&fib.allocator, &.{ dir, filename }) catch continue;
        if (comp.addSource(path)) |some|
            return some
        else |err| switch (err) {
            error.OutOfMemory => return error.OutOfMemory,
            else => {},
        }
    }
    return comp.fatal(tok, "'{s}' not found", .{filename});
}

pub fn fatal(comp: *Compilation, tok: Token, comptime fmt: []const u8, args: anytype) Error {
    const source = comp.getSource(tok.source);
    const lcs = source.lineColString(tok.start);
    return comp.diag.fatal(source.path, lcs, fmt, args);
}

pub const fatalNoSrc = Diagnostics.fatalNoSrc;
pub const renderErrors = Diagnostics.render;
