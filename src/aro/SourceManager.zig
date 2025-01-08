const std = @import("std");
const mem = std.mem;

const Diagnostics = @import("Diagnostics.zig");
const Token = @import("Tokenizer.zig").Token;

pub const Source = struct {
    path: []const u8,
    buf: []const u8,
    id: Id,
    /// each entry represents a byte position within `buf` where a backslash+newline was deleted
    /// from the original raw buffer. The same position can appear multiple times if multiple
    /// consecutive splices happened. Guaranteed to be non-decreasing
    splice_locs: []const u32,
    kind: Kind,

    pub const Id = enum(u32) {
        unused = std.math.maxInt(u32) - 0,
        generated = std.math.maxInt(u32) - 1,
        _,

        pub fn get(id: Id, sm: *const SourceManager) Source {
            if (id == .generated) return .{
                .path = "<scratch space>",
                .buf = sm.generated_buf.items,
                .id = .generated,
                .splice_locs = &.{},
                .kind = .user,
            };
            return sm.sources.values()[@intFromEnum(id)];
        }
    };

    /// Classifies the file for line marker output in -E mode
    pub const Kind = enum {
        /// regular file
        user,
        /// Included from a system include directory
        system,
        /// Included from an "implicit extern C" directory
        extern_c_system,
    };
    const LineCol = struct { line: []const u8, line_no: u32, col: u32, width: u32, end_with_splice: bool };

    pub fn lineCol(source: Source, loc: Location) LineCol {
        var start: usize = 0;
        // find the start of the line which is either a newline or a splice
        if (std.mem.lastIndexOfScalar(u8, source.buf[0..loc.byte_offset], '\n')) |some| start = some + 1;
        const splice_index: u32 = for (source.splice_locs, 0..) |splice_offset, i| {
            if (splice_offset > start) {
                if (splice_offset < loc.byte_offset) {
                    start = splice_offset;
                    break @as(u32, @intCast(i)) + 1;
                }
                break @intCast(i);
            }
        } else @intCast(source.splice_locs.len);
        var i: usize = start;
        var col: u32 = 1;
        var width: u32 = 0;

        while (i < loc.byte_offset) : (col += 1) { // TODO this is still incorrect, but better
            const len = std.unicode.utf8ByteSequenceLength(source.buf[i]) catch {
                i += 1;
                continue;
            };
            const slice = source.buf[i..];
            if (len > slice.len) {
                break;
            }
            const cp = switch (len) {
                1 => slice[0],
                2 => std.unicode.utf8Decode2(slice[0..2].*),
                3 => std.unicode.utf8Decode3(slice[0..3].*),
                4 => std.unicode.utf8Decode4(slice[0..4].*),
                else => unreachable,
            } catch {
                i += 1;
                continue;
            };
            width += codepointWidth(cp);
            i += len;
        }

        // find the end of the line which is either a newline, EOF or a splice
        var nl = source.buf.len;
        var end_with_splice = false;
        if (std.mem.indexOfScalar(u8, source.buf[start..], '\n')) |some| nl = some + start;
        if (source.splice_locs.len > splice_index and nl > source.splice_locs[splice_index] and source.splice_locs[splice_index] > start) {
            end_with_splice = true;
            nl = source.splice_locs[splice_index];
        }
        return .{
            .line = source.buf[start..nl],
            .line_no = loc.line + splice_index,
            .col = col,
            .width = width,
            .end_with_splice = end_with_splice,
        };
    }

    /// Todo: binary search instead of scanning entire `splice_locs`.
    pub fn numSplicesBefore(source: Source, byte_offset: u32) u32 {
        for (source.splice_locs, 0..) |splice_offset, i| {
            if (splice_offset > byte_offset) return @intCast(i);
        }
        return @intCast(source.splice_locs.len);
    }

    /// Returns the actual line number (before newline splicing) of a Location
    /// This corresponds to what the user would actually see in their text editor
    pub fn physicalLine(source: Source, loc: Location) u32 {
        return loc.line + source.numSplicesBefore(loc.byte_offset);
    }
};

pub const Location = struct {
    id: Source.Id = .unused,
    byte_offset: u32 = 0,
    line: u32 = 0,

    pub fn eql(a: Location, b: Location) bool {
        return a.id == b.id and a.byte_offset == b.byte_offset and a.line == b.line;
    }
};

const SourceManager = @This();

const path_buf_stack_limit = 1024;

cwd: std.fs.Dir,

/// If this is not null, the directory containing the specified Source will be searched for includes
/// Used by MS extensions which allow searching for includes relative to the directory of the main source file.
ms_cwd_source_id: ?Source.Id = null,
sources: std.StringArrayHashMapUnmanaged(Source) = .empty,
include_dirs: std.ArrayListUnmanaged([]const u8) = .empty,
system_include_dirs: std.ArrayListUnmanaged([]const u8) = .empty,
/// The source bytes for Source.Id.generated
generated_buf: std.ArrayListUnmanaged(u8) = .empty,

pub fn deinit(sm: *SourceManager, gpa: mem.Allocator) void {
    for (sm.sources.values()) |source| {
        gpa.free(source.path);
        gpa.free(source.buf);
        gpa.free(source.splice_locs);
    }
    sm.sources.deinit(gpa);
    sm.include_dirs.deinit(gpa);
    for (sm.system_include_dirs.items) |path| gpa.free(path);
    sm.system_include_dirs.deinit(gpa);
    sm.generated_buf.deinit(gpa);
    sm.* = undefined;
}

fn codepointWidth(cp: u32) u32 {
    return switch (cp) {
        0x1100...0x115F,
        0x2329,
        0x232A,
        0x2E80...0x303F,
        0x3040...0x3247,
        0x3250...0x4DBF,
        0x4E00...0xA4C6,
        0xA960...0xA97C,
        0xAC00...0xD7A3,
        0xF900...0xFAFF,
        0xFE10...0xFE19,
        0xFE30...0xFE6B,
        0xFF01...0xFF60,
        0xFFE0...0xFFE6,
        0x1B000...0x1B001,
        0x1F200...0x1F251,
        0x20000...0x3FFFD,
        0x1F300...0x1F5FF,
        0x1F900...0x1F9FF,
        => 2,
        else => 1,
    };
}

/// Add built-in aro headers directory to system include paths
pub fn addBuiltinIncludeDir(
    sm: *SourceManager,
    gpa: mem.Allocator,
    aro_dir: []const u8,
) !void {
    var search_path = aro_dir;
    while (std.fs.path.dirname(search_path)) |dirname| : (search_path = dirname) {
        var base_dir = sm.cwd.openDir(dirname, .{}) catch continue;
        defer base_dir.close();

        base_dir.access("include/stddef.h", .{}) catch continue;
        const path = try std.fs.path.join(gpa, &.{ dirname, "include" });
        errdefer gpa.free(path);
        try sm.system_include_dirs.append(gpa, path);
        break;
    } else return error.AroIncludeNotFound;
}

pub fn addSystemIncludeDir(
    sm: *SourceManager,
    gpa: mem.Allocator,
    path: []const u8,
) !void {
    const duped = try gpa.dupe(u8, path);
    errdefer gpa.free(duped);
    try sm.system_include_dirs.append(gpa, duped);
}

/// Creates a Source from the contents of `reader` and adds it to the SourceManager
pub fn addSourceFromReader(
    sm: *SourceManager,
    gpa: mem.Allocator,
    diagnostics: *Diagnostics,
    reader: anytype,
    path: []const u8,
    kind: Source.Kind,
) !Source {
    const contents = try reader.readAllAlloc(gpa, std.math.maxInt(u32));
    errdefer gpa.free(contents);
    return sm.addSourceFromOwnedBuffer(gpa, diagnostics, contents, path, kind);
}

/// Creates a Source from `buf` and adds it to the SourceManager
/// Performs newline splicing and line-ending normalization to '\n'
/// `buf` will be modified and the allocation will be resized if newline splicing
/// or line-ending changes happen.
/// caller retains ownership of `path`
/// To add the contents of an arbitrary reader as a Source, see addSourceFromReader
/// To add a file's contents given its path, see addSourceFromPath
pub fn addSourceFromOwnedBuffer(
    sm: *SourceManager,
    gpa: mem.Allocator,
    diagnostics: *Diagnostics,
    buf: []u8,
    path: []const u8,
    kind: Source.Kind,
) !Source {
    try sm.sources.ensureUnusedCapacity(gpa, 1);

    var contents = buf;
    const duped_path = try gpa.dupe(u8, path);
    errdefer gpa.free(duped_path);

    var splice_list = std.ArrayList(u32).init(gpa);
    defer splice_list.deinit();

    const source_id: Source.Id = @enumFromInt(sm.sources.count());

    var i: u32 = 0;
    var backslash_loc: u32 = undefined;
    var state: enum {
        beginning_of_file,
        bom1,
        bom2,
        start,
        back_slash,
        cr,
        back_slash_cr,
        trailing_ws,
    } = .beginning_of_file;
    var line: u32 = 1;

    for (contents) |byte| {
        contents[i] = byte;

        switch (byte) {
            '\r' => {
                switch (state) {
                    .start, .cr, .beginning_of_file => {
                        state = .start;
                        line += 1;
                        state = .cr;
                        contents[i] = '\n';
                        i += 1;
                    },
                    .back_slash, .trailing_ws, .back_slash_cr => {
                        i = backslash_loc;
                        try splice_list.append(i);
                        if (state == .trailing_ws) {
                            try diagnostics.addExtra(.{}, .{
                                .tag = .backslash_newline_escape,
                                .loc = .{ .id = source_id, .byte_offset = i, .line = line },
                            }, &.{}, true);
                        }
                        state = if (state == .back_slash_cr) .cr else .back_slash_cr;
                    },
                    .bom1, .bom2 => break, // invalid utf-8
                }
            },
            '\n' => {
                switch (state) {
                    .start, .beginning_of_file => {
                        state = .start;
                        line += 1;
                        i += 1;
                    },
                    .cr, .back_slash_cr => {},
                    .back_slash, .trailing_ws => {
                        i = backslash_loc;
                        if (state == .back_slash or state == .trailing_ws) {
                            try splice_list.append(i);
                        }
                        if (state == .trailing_ws) {
                            try diagnostics.addExtra(.{}, .{
                                .tag = .backslash_newline_escape,
                                .loc = .{ .id = source_id, .byte_offset = i, .line = line },
                            }, &.{}, true);
                        }
                    },
                    .bom1, .bom2 => break,
                }
                state = .start;
            },
            '\\' => {
                backslash_loc = i;
                state = .back_slash;
                i += 1;
            },
            '\t', '\x0B', '\x0C', ' ' => {
                switch (state) {
                    .start, .trailing_ws => {},
                    .beginning_of_file => state = .start,
                    .cr, .back_slash_cr => state = .start,
                    .back_slash => state = .trailing_ws,
                    .bom1, .bom2 => break,
                }
                i += 1;
            },
            '\xEF' => {
                i += 1;
                state = switch (state) {
                    .beginning_of_file => .bom1,
                    else => .start,
                };
            },
            '\xBB' => {
                i += 1;
                state = switch (state) {
                    .bom1 => .bom2,
                    else => .start,
                };
            },
            '\xBF' => {
                switch (state) {
                    .bom2 => i = 0, // rewind and overwrite the BOM
                    else => i += 1,
                }
                state = .start;
            },
            else => {
                i += 1;
                state = .start;
            },
        }
    }

    const splice_locs = try splice_list.toOwnedSlice();
    errdefer gpa.free(splice_locs);

    if (i != contents.len) contents = try gpa.realloc(contents, i);
    errdefer @compileError("errdefers in callers would possibly free the realloced slice using the original len");

    const source = Source{
        .id = source_id,
        .path = duped_path,
        .buf = contents,
        .splice_locs = splice_locs,
        .kind = kind,
    };

    sm.sources.putAssumeCapacityNoClobber(duped_path, source);
    return source;
}

/// Caller retains ownership of `path` and `buf`.
/// Dupes the source buffer; if it is acceptable to modify the source buffer and possibly resize
/// the allocation, please use `addSourceFromOwnedBuffer`
pub fn addSourceFromBuffer(
    sm: *SourceManager,
    gpa: mem.Allocator,
    diagnostics: *Diagnostics,
    path: []const u8,
    buf: []const u8,
) !Source {
    if (sm.sources.get(path)) |some| return some;
    if (@as(u64, buf.len) > std.math.maxInt(u32)) return error.StreamTooLong;

    const contents = try gpa.dupe(u8, buf);
    errdefer gpa.free(contents);

    return sm.addSourceFromOwnedBuffer(gpa, diagnostics, contents, path, .user);
}

/// Caller retains ownership of `path`.
pub fn addSourceFromPath(
    sm: *SourceManager,
    gpa: mem.Allocator,
    diagnostics: *Diagnostics,
    path: []const u8,
) !Source {
    return sm.addSourceFromPathExtra(gpa, diagnostics, path, .user);
}

/// Caller retains ownership of `path`.
fn addSourceFromPathExtra(
    sm: *SourceManager,
    gpa: mem.Allocator,
    diagnostics: *Diagnostics,
    path: []const u8,
    kind: Source.Kind,
) !Source {
    if (sm.sources.get(path)) |some| return some;

    if (mem.indexOfScalar(u8, path, 0) != null) {
        return error.FileNotFound;
    }

    const file = try sm.cwd.openFile(path, .{});
    defer file.close();

    const contents = file.readToEndAlloc(gpa, std.math.maxInt(u32)) catch |err| switch (err) {
        error.FileTooBig => return error.StreamTooLong,
        else => |e| return e,
    };
    errdefer gpa.free(contents);

    return sm.addSourceFromOwnedBuffer(gpa, diagnostics, contents, path, kind);
}

pub const IncludeDirIterator = struct {
    sm: *const SourceManager,
    cwd_source_id: ?Source.Id,
    include_dirs_idx: usize = 0,
    sys_include_dirs_idx: usize = 0,
    tried_ms_cwd: bool = false,
    replace_ms_slashes: bool,

    const FoundSource = struct {
        path: []const u8,
        kind: Source.Kind,
    };

    fn next(it: *IncludeDirIterator) ?FoundSource {
        if (it.cwd_source_id) |source_id| {
            it.cwd_source_id = null;
            const path = source_id.get(it.sm).path;
            return .{ .path = std.fs.path.dirname(path) orelse ".", .kind = .user };
        }
        if (it.include_dirs_idx < it.sm.include_dirs.items.len) {
            defer it.include_dirs_idx += 1;
            return .{ .path = it.sm.include_dirs.items[it.include_dirs_idx], .kind = .user };
        }
        if (it.sys_include_dirs_idx < it.sm.system_include_dirs.items.len) {
            defer it.sys_include_dirs_idx += 1;
            return .{ .path = it.sm.system_include_dirs.items[it.sys_include_dirs_idx], .kind = .system };
        }
        if (it.sm.ms_cwd_source_id) |source_id| {
            if (it.tried_ms_cwd) return null;
            it.tried_ms_cwd = true;
            const path = source_id.get(it.sm).path;
            return .{ .path = std.fs.path.dirname(path) orelse ".", .kind = .user };
        }
        return null;
    }

    /// Returned value's path field must be freed by allocator
    fn nextWithFile(it: *IncludeDirIterator, filename: []const u8, allocator: mem.Allocator) !?FoundSource {
        while (it.next()) |found| {
            const path = try std.fs.path.join(allocator, &.{ found.path, filename });
            if (it.replace_ms_slashes) {
                std.mem.replaceScalar(u8, path, '\\', '/');
            }
            return .{ .path = path, .kind = found.kind };
        }
        return null;
    }

    /// Advance the iterator until it finds an include directory that matches
    /// the directory which contains `source`.
    fn skipUntilDirMatch(it: *IncludeDirIterator, source_id: Source.Id) void {
        const path = source_id.get(it.sm).path;
        const includer_path = std.fs.path.dirname(path) orelse ".";
        while (it.next()) |found| {
            if (mem.eql(u8, includer_path, found.path)) break;
        }
    }
};

pub fn hasInclude(
    sm: *const SourceManager,
    gpa: mem.Allocator,
    filename: []const u8,
    includer_token_source: Source.Id,
    /// angle bracket vs quotes
    include_type: IncludeType,
    /// __has_include vs __has_include_next
    which: WhichInclude,
    replace_ms_slashes: bool,
) !bool {
    if (mem.indexOfScalar(u8, filename, 0) != null) {
        return false;
    }

    if (std.fs.path.isAbsolute(filename)) {
        if (which == .next) return false;
        return !std.meta.isError(sm.cwd.access(filename, .{}));
    }

    const cwd_source_id = switch (include_type) {
        .quotes => switch (which) {
            .first => includer_token_source,
            .next => null,
        },
        .angle_brackets => null,
    };
    var it: IncludeDirIterator = .{ .sm = sm, .cwd_source_id = cwd_source_id, .replace_ms_slashes = replace_ms_slashes };
    if (which == .next) {
        it.skipUntilDirMatch(includer_token_source);
    }

    var stack_fallback = std.heap.stackFallback(path_buf_stack_limit, gpa);
    const sf_allocator = stack_fallback.get();

    while (try it.nextWithFile(filename, sf_allocator)) |found| {
        defer sf_allocator.free(found.path);
        if (!std.meta.isError(sm.cwd.access(found.path, .{}))) return true;
    }
    return false;
}

pub const WhichInclude = enum { first, next };

pub const IncludeType = enum { quotes, angle_brackets };

fn getFileContents(sm: *const SourceManager, gpa: mem.Allocator, path: []const u8, limit: ?u32) ![]const u8 {
    if (mem.indexOfScalar(u8, path, 0) != null) {
        return error.FileNotFound;
    }

    const file = try sm.cwd.openFile(path, .{});
    defer file.close();

    var buf = std.ArrayList(u8).init(gpa);
    defer buf.deinit();

    const max = limit orelse std.math.maxInt(u32);
    file.reader().readAllArrayList(&buf, max) catch |e| switch (e) {
        error.StreamTooLong => if (limit == null) return e,
        else => return e,
    };

    return buf.toOwnedSlice();
}

pub fn findEmbed(
    sm: *const SourceManager,
    gpa: mem.Allocator,
    filename: []const u8,
    includer_token_source: Source.Id,
    /// angle bracket vs quotes
    include_type: IncludeType,
    limit: ?u32,
    replace_ms_slashes: bool,
) !?[]const u8 {
    if (std.fs.path.isAbsolute(filename)) {
        return if (sm.getFileContents(gpa, filename, limit)) |some|
            some
        else |err| switch (err) {
            error.OutOfMemory => |e| return e,
            else => null,
        };
    }

    const cwd_source_id = switch (include_type) {
        .quotes => includer_token_source,
        .angle_brackets => null,
    };
    var it = IncludeDirIterator{ .sm = sm, .cwd_source_id = cwd_source_id, .replace_ms_slashes = replace_ms_slashes };
    var stack_fallback = std.heap.stackFallback(path_buf_stack_limit, gpa);
    const sf_allocator = stack_fallback.get();

    while (try it.nextWithFile(filename, sf_allocator)) |found| {
        defer sf_allocator.free(found.path);
        if (sm.getFileContents(gpa, found.path, limit)) |some|
            return some
        else |err| switch (err) {
            error.OutOfMemory => return error.OutOfMemory,
            else => {},
        }
    }
    return null;
}

pub fn findInclude(
    sm: *SourceManager,
    gpa: mem.Allocator,
    diagnostics: *Diagnostics,
    filename: []const u8,
    includer_token: Token,
    /// angle bracket vs quotes
    include_type: IncludeType,
    /// include vs include_next
    which: WhichInclude,
    replace_ms_slashes: bool,
) !?Source {
    if (std.fs.path.isAbsolute(filename)) {
        if (which == .next) return null;
        // TODO: classify absolute file as belonging to system includes or not?
        return if (sm.addSourceFromPath(gpa, diagnostics, filename)) |some|
            some
        else |err| switch (err) {
            error.OutOfMemory => |e| return e,
            else => null,
        };
    }
    const cwd_source_id = switch (include_type) {
        .quotes => switch (which) {
            .first => includer_token.source,
            .next => null,
        },
        .angle_brackets => null,
    };

    var it: IncludeDirIterator = .{ .sm = sm, .cwd_source_id = cwd_source_id, .replace_ms_slashes = replace_ms_slashes };

    if (which == .next) {
        it.skipUntilDirMatch(includer_token.source);
    }

    var stack_fallback = std.heap.stackFallback(path_buf_stack_limit, gpa);
    const sf_allocator = stack_fallback.get();

    while (try it.nextWithFile(filename, sf_allocator)) |found| {
        defer sf_allocator.free(found.path);
        if (sm.addSourceFromPathExtra(gpa, diagnostics, found.path, found.kind)) |some| {
            if (it.tried_ms_cwd) {
                try diagnostics.addExtra(.{}, .{
                    .tag = .ms_search_rule,
                    .extra = .{ .str = some.path },
                    .loc = .{
                        .id = includer_token.source,
                        .byte_offset = includer_token.start,
                        .line = includer_token.line,
                    },
                }, &.{}, true);
            }
            return some;
        } else |err| switch (err) {
            error.OutOfMemory => return error.OutOfMemory,
            else => {},
        }
    }
    return null;
}

test "addSourceFromReader" {
    const Test = struct {
        fn addSourceFromReader(str: []const u8, expected: []const u8, warning_count: u32, splices: []const u32) !void {
            const gpa = std.testing.allocator;

            var sm: SourceManager = .{ .cwd = std.fs.cwd() };
            defer sm.deinit(gpa);

            var diagnostics: Diagnostics = .{ .arena = .init(gpa) };
            defer diagnostics.deinit();

            var buf_reader = std.io.fixedBufferStream(str);
            const source = try sm.addSourceFromReader(gpa, &diagnostics, buf_reader.reader(), "path", .user);

            try std.testing.expectEqualStrings(expected, source.buf);
            try std.testing.expectEqual(warning_count, @as(u32, @intCast(diagnostics.list.items.len)));
            try std.testing.expectEqualSlices(u32, splices, source.splice_locs);
        }

        fn withAllocationFailures(allocator: std.mem.Allocator) !void {
            var sm: SourceManager = .{ .cwd = std.fs.cwd() };
            defer sm.deinit(allocator);

            _ = try sm.addSourceFromBuffer(allocator, undefined, "path", "spliced\\\nbuffer\n");
            _ = try sm.addSourceFromBuffer(allocator, undefined, "path", "non-spliced buffer\n");
        }
    };
    try Test.addSourceFromReader("ab\\\nc", "abc", 0, &.{2});
    try Test.addSourceFromReader("ab\\\rc", "abc", 0, &.{2});
    try Test.addSourceFromReader("ab\\\r\nc", "abc", 0, &.{2});
    try Test.addSourceFromReader("ab\\ \nc", "abc", 1, &.{2});
    try Test.addSourceFromReader("ab\\\t\nc", "abc", 1, &.{2});
    try Test.addSourceFromReader("ab\\                     \t\nc", "abc", 1, &.{2});
    try Test.addSourceFromReader("ab\\\r \nc", "ab \nc", 0, &.{2});
    try Test.addSourceFromReader("ab\\\\\nc", "ab\\c", 0, &.{3});
    try Test.addSourceFromReader("ab\\   \r\nc", "abc", 1, &.{2});
    try Test.addSourceFromReader("ab\\ \\\nc", "ab\\ c", 0, &.{4});
    try Test.addSourceFromReader("ab\\\r\\\nc", "abc", 0, &.{ 2, 2 });
    try Test.addSourceFromReader("ab\\  \rc", "abc", 1, &.{2});
    try Test.addSourceFromReader("ab\\", "ab\\", 0, &.{});
    try Test.addSourceFromReader("ab\\\\", "ab\\\\", 0, &.{});
    try Test.addSourceFromReader("ab\\ ", "ab\\ ", 0, &.{});
    try Test.addSourceFromReader("ab\\\n", "ab", 0, &.{2});
    try Test.addSourceFromReader("ab\\\r\n", "ab", 0, &.{2});
    try Test.addSourceFromReader("ab\\\r", "ab", 0, &.{2});

    // carriage return normalization
    try Test.addSourceFromReader("ab\r", "ab\n", 0, &.{});
    try Test.addSourceFromReader("ab\r\r", "ab\n\n", 0, &.{});
    try Test.addSourceFromReader("ab\r\r\n", "ab\n\n", 0, &.{});
    try Test.addSourceFromReader("ab\r\r\n\r", "ab\n\n\n", 0, &.{});
    try Test.addSourceFromReader("\r\\", "\n\\", 0, &.{});
    try Test.addSourceFromReader("\\\r\\", "\\", 0, &.{0});

    try std.testing.checkAllAllocationFailures(std.testing.allocator, Test.withAllocationFailures, .{});
}

test "addSourceFromReader - exhaustive check for carriage return elimination" {
    const alphabet = [_]u8{ '\r', '\n', ' ', '\\', 'a' };
    const alen = alphabet.len;
    var buf: [alphabet.len]u8 = [1]u8{alphabet[0]} ** alen;

    const gpa = std.testing.allocator;
    var diagnostics: Diagnostics = .{ .arena = .init(gpa) };
    defer diagnostics.deinit();
    var sm: SourceManager = .{ .cwd = std.fs.cwd() };
    defer sm.deinit(gpa);

    var source_count: u32 = 0;

    while (true) {
        const source = try sm.addSourceFromBuffer(gpa, &diagnostics, &buf, &buf);
        source_count += 1;
        try std.testing.expect(std.mem.indexOfScalar(u8, source.buf, '\r') == null);

        if (std.mem.allEqual(u8, &buf, alphabet[alen - 1])) break;

        var idx = std.mem.indexOfScalar(u8, &alphabet, buf[buf.len - 1]).?;
        buf[buf.len - 1] = alphabet[(idx + 1) % alen];
        var j = buf.len - 1;
        while (j > 0) : (j -= 1) {
            idx = std.mem.indexOfScalar(u8, &alphabet, buf[j - 1]).?;
            if (buf[j] == alphabet[0]) buf[j - 1] = alphabet[(idx + 1) % alen] else break;
        }
    }
    try std.testing.expect(source_count == std.math.powi(usize, alen, alen) catch unreachable);
}

test "ignore BOM at beginning of file" {
    const BOM = "\xEF\xBB\xBF";

    const Test = struct {
        fn run(buf: []const u8) !void {
            const gpa = std.testing.allocator;
            var sm: SourceManager = .{ .cwd = std.fs.cwd() };
            defer sm.deinit(gpa);

            var buf_reader = std.io.fixedBufferStream(buf);
            const source = try sm.addSourceFromReader(gpa, undefined, buf_reader.reader(), "file.c", .user);
            const expected_output = if (mem.startsWith(u8, buf, BOM)) buf[BOM.len..] else buf;
            try std.testing.expectEqualStrings(expected_output, source.buf);
        }
    };

    try Test.run(BOM);
    try Test.run(BOM ++ "x");
    try Test.run("x" ++ BOM);
    try Test.run(BOM ++ " ");
    try Test.run(BOM ++ "\n");
    try Test.run(BOM ++ "\\");

    try Test.run(BOM[0..1] ++ "x");
    try Test.run(BOM[0..2] ++ "x");
    try Test.run(BOM[1..] ++ "x");
    try Test.run(BOM[2..] ++ "x");
}
