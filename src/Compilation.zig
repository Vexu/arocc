const std = @import("std");
const mem = std.mem;
const Allocator = mem.Allocator;
const assert = std.debug.assert;
const Preprocessor = @import("Preprocessor.zig");
const Source = @import("Source.zig");
const Tokenizer = @import("Tokenizer.zig");
const Token = Tokenizer.Token;
const Diagnostics = @import("Diagnostics.zig");
const LangOpts = @import("LangOpts.zig");

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
target: std.Target = std.Target.current,
only_preprocess: bool = false,
langopts: LangOpts = .{},

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
    for (comp.sources.values()) |source| {
        comp.gpa.free(source.path);
        comp.gpa.free(source.buf);
    }
    comp.sources.deinit();
    comp.diag.deinit();
    comp.include_dirs.deinit();
    comp.system_include_dirs.deinit();
}

/// Generate builtin macros that will be available to each source file.
pub fn generateBuiltinMacros(comp: *Compilation) !Source {
    var buf = std.ArrayList(u8).init(comp.gpa);
    defer buf.deinit();

    try buf.appendSlice(
        \\#define __VERSION__ "Aro 
    ++ @import("lib.zig").version_str ++ "\"\n" ++
        \\#define __STDC__ 1
        \\#define __STDC_HOSTED__ 1
        \\#define __STDC_VERSION__ 201710L
        \\#define __STDC_NO_ATOMICS__ 1
        \\#define __STDC_NO_COMPLEX__ 1
        \\#define __STDC_NO_THREADS__ 1
        \\#define __STDC_NO_VLA__ 1
        \\
    );

    switch (comp.target.os.tag) {
        .linux => try buf.appendSlice(
            \\#define unix 1
            \\#define __unix 1
            \\#define __unix__ 1
            \\#define linux 1
            \\#define __linux 1
            \\#define __linux__ 1
            \\
        ),
        .windows => if (comp.target.cpu.arch.ptrBitWidth() == 32)
            try buf.appendSlice("#define _WIN32 1\n")
        else
            try buf.appendSlice(
                \\#define _WIN32 1
                \\#define _WIN64 1
                \\
            ),
        else => {},
    }

    switch (comp.target.cpu.arch) {
        .x86_64 => try buf.appendSlice(
            \\#define __amd64__ 1
            \\#define __amd64 1
            \\#define __x86_64 1
            \\#define __x86_64__ 1
            \\
        ),
        else => {},
    }

    try buf.appendSlice(if (comp.target.cpu.arch.endian() == .Little)
        \\#define __ORDER_LITTLE_ENDIAN__ 1234
        \\#define __ORDER_BIG_ENDIAN__ 4321
        \\#define __ORDER_PDP_ENDIAN__ 3412
        \\#define __BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__
        \\#define __LITTLE_ENDIAN__ 1
        \\
    else
        \\#define __ORDER_LITTLE_ENDIAN__ 1234
        \\#define __ORDER_BIG_ENDIAN__ 4321
        \\#define __ORDER_PDP_ENDIAN__ 3412
        \\#define __BYTE_ORDER__ __ORDER_BIG_ENDIAN__;
        \\#define __BIG_ENDIAN__ 1
        \\
    );

    const duped_path = try comp.gpa.dupe(u8, "<builtin>");
    errdefer comp.gpa.free(duped_path);

    const contents = buf.toOwnedSlice();
    errdefer comp.gpa.free(contents);

    const source = Source{
        .id = @intToEnum(Source.Id, comp.sources.count() + 2),
        .path = duped_path,
        .buf = contents,
    };
    try comp.sources.put(duped_path, source);
    return source;
}

pub fn getSource(comp: *Compilation, id: Source.Id) Source {
    return comp.sources.values()[@enumToInt(id) - 2];
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
        .id = @intToEnum(Source.Id, comp.sources.count() + 2),
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

pub fn addDiagnostic(comp: *Compilation, msg: Diagnostics.Message) Error!void {
    if (comp.langopts.suppress(msg.tag)) return;
    return comp.diag.add(msg);
}

pub const renderErrors = Diagnostics.render;
