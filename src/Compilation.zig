const std = @import("std");
const assert = std.debug.assert;
const mem = std.mem;
const Allocator = mem.Allocator;
const EpochSeconds = std.time.epoch.EpochSeconds;
const Diagnostics = @import("Diagnostics.zig");
const LangOpts = @import("LangOpts.zig");
const Preprocessor = @import("Preprocessor.zig");
const Source = @import("Source.zig");
const Tokenizer = @import("Tokenizer.zig");
const Token = Tokenizer.Token;
const Type = @import("Type.zig");

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
builtin_header_path: ?[]u8 = null,
target: std.Target = std.Target.current,
only_preprocess: bool = false,
only_compile: bool = false,
verbose_ast: bool = false,
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
    if (comp.builtin_header_path) |some| comp.gpa.free(some);
}

fn generateDateAndTime(w: anytype) !void {
    const timestamp = std.math.clamp(std.time.timestamp(), 0, std.math.maxInt(i64));
    const epoch_seconds = EpochSeconds{ .secs = @intCast(u64, timestamp) };
    const epoch_day = epoch_seconds.getEpochDay();
    const day_seconds = epoch_seconds.getDaySeconds();
    const year_day = epoch_day.calculateYearDay();

    const month_day = year_day.calculateMonthDay();

    const MonthNames = [_][]const u8{ "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
    std.debug.assert(std.time.epoch.Month.jan.numeric() == 1);

    const monthName = MonthNames[month_day.month.numeric() - 1];
    try w.print("#define __DATE__ \"{s} {d: >2} {d}\"\n", .{
        monthName,
        month_day.day_index + 1,
        year_day.year,
    });
    try w.print("#define __TIME__ \"{d:0>2}:{d:0>2}:{d:0>2}\"\n", .{
        day_seconds.getHoursIntoDay(),
        day_seconds.getMinutesIntoHour(),
        day_seconds.getSecondsIntoMinute(),
    });
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
        \\#define __STDC_NO_ATOMICS__ 1
        \\#define __STDC_NO_COMPLEX__ 1
        \\#define __STDC_NO_THREADS__ 1
        \\#define __STDC_NO_VLA__ 1
        \\
    );
    try generateDateAndTime(buf.writer());

    if (comp.langopts.standard.StdCVersionMacro()) |stdc_version| {
        try buf.writer().print("#define __STDC_VERSION__ {s}\n", .{stdc_version});
    }

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

    const w = buf.writer();
    try generateTypeMacro(w, "__PTRDIFF_TYPE__", Type.ptrDiffT(comp));
    try generateTypeMacro(w, "__SIZE_TYPE__", Type.sizeT(comp));
    try generateTypeMacro(w, "__WCHAR_TYPE__", Type.wideChar(comp));

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

fn generateTypeMacro(w: anytype, name: []const u8, ty: Type) !void {
    try w.print("#define {s} ", .{name});
    try ty.print(w);
    try w.writeByte('\n');
}

pub fn defineSystemIncludes(comp: *Compilation) !void {
    var buf: [std.fs.MAX_PATH_BYTES]u8 = undefined;
    var search_path: []const u8 = std.fs.selfExePath(&buf) catch return error.SelfExeNotFound;
    while (std.fs.path.dirname(search_path)) |dirname| : (search_path = dirname) {
        var base_dir = std.fs.cwd().openDir(dirname, .{}) catch continue;
        defer base_dir.close();

        base_dir.access("include/stddef.h", .{}) catch continue;
        const path = try std.fs.path.join(comp.gpa, &.{ dirname, "include" });
        comp.builtin_header_path = path;
        try comp.system_include_dirs.append(path);
        break;
    } else return error.AroIncludeNotFound;

    try comp.system_include_dirs.append("/usr/include");
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
