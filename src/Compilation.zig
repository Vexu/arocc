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

pub fn init(gpa: *Allocator) Compilation {
    return .{
        .gpa = gpa,
        .sources = std.StringArrayHashMap(Source).init(gpa),
        .diag = Diagnostics.init(gpa),
    };
}

pub fn deinit(comp: *Compilation) void {
    for (comp.sources.items()) |source| {
        comp.gpa.free(source.value.path);
        comp.gpa.free(source.value.buf);
    }
    comp.sources.deinit();
    comp.diag.deinit();
}

pub fn getSource(comp: *Compilation, id: Source.Id) Source {
    var src = comp.sources.items()[id.index()].value;
    if (id.isGenerated()) src.id.markGenerated();
    return src;
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

pub fn findInclude(comp: *Compilation, tok: Token, filename: []const u8, search_cwd: bool) !Source {
    // TODO actually implement this.
    return comp.addSource(filename) catch
        return comp.fatal(tok, "'{s}' not found", .{filename});
}

pub fn fatal(comp: *Compilation, tok: Token, comptime fmt: []const u8, args: anytype) Error {
    const source = comp.getSource(tok.source);
    const lcs = source.lineColString(tok.loc.start);
    return comp.diag.fatal(source.path, lcs, fmt, args);
}

pub const fatalNoSrc = Diagnostics.fatalNoSrc;
pub const renderErrors = Diagnostics.render;
