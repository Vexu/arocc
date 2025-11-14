const std = @import("std");
const Io = std.Io;
const mem = std.mem;
const print = std.debug.print;
const process = std.process;

const gpa = std.heap.smp_allocator;

pub fn main() !void {
    var arena_allocator = std.heap.ArenaAllocator.init(gpa);
    defer arena_allocator.deinit();
    const arena = arena_allocator.allocator();

    const args = try process.argsAlloc(arena);
    if (args.len != 2) {
        print("Usage: {s} <arocc-exe>", .{args[0]});
        process.exit(1);
    }

    const arocc_exe = args[1];

    var threaded: Io.Threaded = .init(gpa);
    defer threaded.deinit();
    const io = threaded.io();

    var dir = std.fs.cwd().openDir("test/cases2", .{ .iterate = true }) catch |err| {
        std.debug.panic("unable to open test/cases: {t}", .{err});
    };
    defer dir.close();

    var group: Io.Group = .init;
    var stats: Stats = .{};

    const root_prog_node = std.Progress.start(.{ .root_name = "integration tests" });

    var it = dir.iterate();
    while (try it.next()) |entry| {
        if (entry.kind != .file) continue;
        root_prog_node.increaseEstimatedTotalItems(1);
        _ = @atomicRmw(u32, &stats.total, .Add, 1, .monotonic);

        group.async(io, runCase, .{ io, entry.name, arocc_exe, root_prog_node, &stats });
    }
    group.wait(io);
    root_prog_node.end();

    if (stats.failed == 0 and stats.skipped == 0) {
        print("All {d} tests passed.\n", .{stats.total});
    } else if (stats.failed == 0) {
        print("{d} passed; {d} skipped.\n", .{ stats.total, stats.skipped });
    } else {
        print("{d} passed; {d} failed.\n\n", .{ stats.total, stats.failed });
        std.process.exit(1);
    }
}

const Stats = struct {
    total: u32 = 0,
    failed: u32 = 0,
    skipped: u32 = 0,
};

fn runCase(
    io: Io,
    filename: []const u8,
    aro_exe: []const u8,
    root_node: std.Progress.Node,
    stats: *Stats,
) void {
    defer root_node.completeOne();

    var arena_allocator = std.heap.ArenaAllocator.init(gpa);
    defer arena_allocator.deinit();
    const arena = arena_allocator.allocator();

    const case_node = root_node.start(std.fs.path.stem(filename), 0);
    defer case_node.end();

    runCaseExtra(io, arena, filename, aro_exe, stats) catch {
        _ = @atomicRmw(u32, &stats.failed, .Add, 1, .monotonic);
    };
}

fn runCaseExtra(
    io: Io,
    arena: mem.Allocator,
    filename: []const u8,
    aro_exe: []const u8,
    stats: *Stats,
) !void {
    if (!mem.endsWith(u8, filename, ".c")) {
        print("test case is not a .c file: '{s}'\n", .{filename});
        return error.InvalidName;
    }
    const path = try std.fs.path.join(arena, &.{ "test", "cases2", filename });
    const case = try caseFromFile(io, arena, path);

    const base_args = [_][]const u8{ aro_exe, path, "-fno-color-diagnostics" };
    const kind_args: []const []const u8 = switch (case.kind) {
        .syntax, .syntax_no_error => &.{ "-fsyntax-only", "--verbose-ast" },
        .expand, .expand_partial => &.{ "-E", "-P" },
    };

    var args: std.ArrayList([]const u8) = .empty;
    try args.ensureUnusedCapacity(arena, base_args.len + kind_args.len + case.args.len);
    args.appendSliceAssumeCapacity(&base_args);
    args.appendSliceAssumeCapacity(kind_args);
    args.appendSliceAssumeCapacity(case.args);

    var child = process.Child.init(args.items, arena);
    child.stdout_behavior = .Pipe;
    child.stderr_behavior = .Pipe;
    child.stdin_behavior = .Ignore;

    var env_map: process.EnvMap = undefined;
    if (case.env.len > 0) {
        env_map = try process.getEnvMap(arena);
        for (case.env) |kv| {
            try env_map.put(kv.key, kv.value);
        }
        child.env_map = &env_map;
    }

    var stdout: []u8 = undefined;
    var stderr: []u8 = undefined;

    {
        try child.spawn();
        errdefer _ = child.kill() catch {};

        var stdout_reader = child.stdout.?.readerStreaming(io, &.{});
        stdout = try stdout_reader.interface.allocRemaining(arena, .unlimited);

        var stderr_reader = child.stderr.?.readerStreaming(io, &.{});
        stderr = try stderr_reader.interface.allocRemaining(arena, .unlimited);

        const term = try child.wait();
        if (term != .Exited) {
            const cmd = try mem.join(arena, " ", args.items);
            print("arocc command crashed:\n{s}\n", .{cmd});
            return error.Crashed;
        }
    }

    switch (case.kind) {
        .syntax, .expand, .expand_partial => |expected_errors| {
            const actual_errors = stderr;

            for (expected_errors) |expected| {
                if (mem.indexOf(u8, actual_errors, expected) == null) {
                    print(
                        \\
                        \\======= expected to find error =======
                        \\{s}
                        \\
                        \\=== but output does not contain it ===
                        \\{s}
                        \\
                        \\
                    , .{ expected, actual_errors });
                    return error.MissingError;
                }
            }

            {
                var actual_count: u32 = 0;
                var it = mem.tokenizeScalar(u8, actual_errors, '\n');
                while (it.next()) |msg| {
                    _, const actual = mem.cut(u8, msg, ".c:") orelse continue;
                    actual_count += 1;
                    for (expected_errors) |expected| {
                        if (mem.indexOf(u8, expected, actual) != null) break;
                    } else {
                        print(
                            \\
                            \\========= new error ==========
                            \\{s}
                            \\
                            \\=== not in EXPECTED_ERRORS ===
                            \\
                            \\
                        , .{msg});
                    }
                }
                if (actual_count != expected_errors.len) return error.NewErrors;
            }
        },
        else => {},
    }

    switch (case.kind) {
        .syntax => {
            const ast_path = try std.fs.path.join(arena, &.{ "test", "cases2", "ast", std.fs.path.basename(path) });
            if (std.fs.cwd().readFileAlloc(ast_path, gpa, .unlimited)) |expected| {
                defer gpa.free(expected);

                try std.testing.expectEqualStrings(expected, stdout);
            } else |err| if (err != error.FileNotFound) {
                print("can't open ast file '{s}': {t}\n", .{ ast_path, err });
                return err;
            }
        },
        .syntax_no_error => {},
        .expand => {
            const expanded_path = try std.fs.path.join(arena, &.{ "test", "cases2", "expanded", std.fs.path.basename(path) });
            if (std.fs.cwd().readFileAlloc(expanded_path, gpa, .unlimited)) |expected| {
                defer gpa.free(expected);

                try std.testing.expectEqualStrings(expected, stdout);
            } else |err| if (err != error.FileNotFound) {
                print("can't open expanded file '{s}': {t}\n", .{ expanded_path, err });
                return err;
            }
        },
        .expand_partial => {
            const expanded_path = try std.fs.path.join(arena, &.{ "test", "cases2", "expanded", std.fs.path.basename(path) });
            if (std.fs.cwd().readFileAlloc(expanded_path, gpa, .unlimited)) |expected| {
                defer gpa.free(expected);

                try std.testing.expectStringEndsWith(stdout, expected);
            } else |err| if (err != error.FileNotFound) {
                print("can't open expanded file '{s}': {t}\n", .{ expanded_path, err });
                return err;
            }
        },
    }

    if (case.skipped != 0) {
        print("{s}: {d} test{s} skipped\n", .{ case.name, case.skipped, if (case.skipped == 1) @as([]const u8, "") else "s" });
        _ = @atomicRmw(u32, &stats.skipped, .Add, case.skipped, .monotonic);
    }
}

const Case = struct {
    name: []const u8,
    kind: Kind,
    skipped: u32,
    args: []const []const u8,
    env: []const KV,

    const Kind = union(enum) {
        /// Compile with -fsyntax-only and check expected compile errors.
        syntax: []const []const u8,
        /// Compile with -fsyntax-only and ignore compile errors.
        syntax_no_error,
        /// Compile with -E -P and check expected compile errors as well as expansion result.
        expand: []const []const u8,
        /// Compile with -E -P and check expected compile errors as well as expansion result.
        expand_partial: []const []const u8,
    };
    const KV = struct { key: []const u8, value: []const u8 };
};

fn caseFromFile(io: Io, arena: mem.Allocator, path: []const u8) !Case {
    const name = std.fs.path.stem(path);
    const contents = contents: {
        var file = try Io.Dir.cwd().openFile(io, path, .{});
        defer file.close(io);

        var reader = file.reader(io, &.{});
        break :contents try reader.interface.allocRemaining(arena, .unlimited);
    };

    const manifest = manifest: {
        var start: ?usize = null;
        const bytes = mem.trimRight(u8, contents, " \t\n");
        var cursor = bytes.len;
        while (true) : (cursor -= 1) {
            while (cursor > 0 and bytes[cursor - 1] != '\n') cursor -= 1;

            if (mem.startsWith(u8, bytes[cursor..], "//")) {
                start = cursor;
            } else break;
        }
        const manifest_start = start orelse {
            print("{s}: no test manifest\n", .{name});
            return error.TestManifestMissing;
        };
        break :manifest bytes[manifest_start..];
    };

    var skipped: u32 = 0;
    var args: []const []const u8 = &.{};
    var env: []const Case.KV = &.{};

    var it = mem.tokenizeScalar(u8, manifest, '\n');

    const kind = kind: {
        const line = it.next() orelse return error.TestManifestMissingType;
        const trimmed = mem.trim(u8, line[2..], " \t");
        break :kind std.meta.stringToEnum(std.meta.Tag(Case.Kind), trimmed) orelse {
            print("{s}: invalid test case type: {s}\n", .{ name, trimmed });
            return error.TestManifestInvalidType;
        };
    };

    while (it.next()) |line| {
        const trimmed = mem.trim(u8, line[2..], " \t");
        if (trimmed.len == 0) break; // Start of trailing data.

        const key_raw, const value_raw = mem.cutScalar(u8, trimmed, '=') orelse {
            print("{s}: missing value for config option: {s}\n", .{ name, trimmed });
            return error.TestManifestMissingValue;
        };
        const key = mem.trimEnd(u8, key_raw, " \t");
        const value = mem.trimStart(u8, value_raw, " \t");
        if (mem.eql(u8, key, "skipped")) {
            skipped = std.fmt.parseInt(u32, value, 10) catch |err| {
                print("{s}: invalid skipped '{s}': {t}\n", .{ name, trimmed, err });
                return err;
            };
        } else if (mem.eql(u8, key, "args")) {
            var buf: std.ArrayList([]const u8) = .empty;
            defer buf.deinit(gpa);

            var arg_it = mem.tokenizeScalar(u8, value, ' ');
            while (arg_it.next()) |arg| {
                try buf.append(gpa, arg);
            }
            args = try arena.dupe([]const u8, buf.items);
        } else if (mem.eql(u8, key, "env")) {
            var buf: std.ArrayList(Case.KV) = .empty;
            defer buf.deinit(gpa);

            var env_it = mem.tokenizeScalar(u8, value, ' ');
            while (env_it.next()) |env_kv| {
                const env_k, const env_v = mem.cutScalar(u8, env_kv, '=') orelse {
                    print("{s}: invalid env key value pair: {s}\n", .{ name, env_kv });
                    continue;
                };
                try buf.append(gpa, .{ .key = env_k, .value = env_v });
            }
            env = try arena.dupe(Case.KV, buf.items);
        } else {
            print("{s}: unknown config option: {s}\n", .{ name, key });
            return error.TestManifestUnknownOption;
        }
    }

    return .{
        .name = name,
        .kind = switch (kind) {
            .syntax => .{ .syntax = try trailingLines(arena, &it) },
            .syntax_no_error => .syntax_no_error,
            .expand => .{ .expand = try trailingLines(arena, &it) },
            .expand_partial => .{ .expand_partial = try trailingLines(arena, &it) },
        },
        .skipped = skipped,
        .args = args,
        .env = env,
    };
}

fn trailingLines(arena: mem.Allocator, it: *mem.TokenIterator(u8, .scalar)) ![]const []const u8 {
    var buf: std.ArrayList([]const u8) = .empty;
    defer buf.deinit(gpa);

    while (it.next()) |line| {
        try buf.append(gpa, mem.trim(u8, line[2..], " "));
    }
    return try arena.dupe([]const u8, buf.items);
}
