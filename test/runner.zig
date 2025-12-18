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
    if (args.len != 3) {
        print("Usage: {s} <arocc-exe> <cases-dir>", .{args[0]});
        process.exit(1);
    }

    const arocc_exe = args[1];
    const cases_dir = args[2];

    const relative_arocc_exe = try std.fs.path.relative(arena, cases_dir, arocc_exe);

    var threaded: Io.Threaded = .init(gpa);
    defer threaded.deinit();
    const io = threaded.io();

    var dir = std.fs.cwd().openDir(cases_dir, .{ .iterate = true }) catch |err| {
        std.debug.panic("unable to open '{s}': {t}", .{ cases_dir, err });
    };
    defer dir.close();

    var group: Io.Group = .init;
    var stats: Stats = .{};

    const root_prog_node = std.Progress.start(.{ .root_name = "integration tests" });

    var it = dir.iterate();
    while (try it.next()) |entry| {
        if (entry.kind != .file) continue;
        if (mem.eql(u8, entry.name, "README.md")) continue;
        root_prog_node.increaseEstimatedTotalItems(1);
        _ = @atomicRmw(u32, &stats.total, .Add, 1, .monotonic);

        const path = try std.fs.path.join(arena, &.{ cases_dir, entry.name });
        group.async(io, runCase, .{ io, path, relative_arocc_exe, root_prog_node, &stats });
    }
    group.wait(io);
    root_prog_node.end();

    print("max mem used = {Bi:.2}\n", .{stats.max_rss});
    if (stats.failed == 0 and stats.skipped == 0) {
        print("All {d} tests passed.\n", .{stats.total});
    } else if (stats.failed == 0) {
        print("{d} passed; {d} skipped.\n", .{ stats.total - stats.failed, stats.skipped });
    } else {
        print("{d} passed; {d} failed.\n\n", .{ stats.total - stats.failed, stats.failed });
        process.exit(1);
    }
}

const Stats = struct {
    total: u32 = 0,
    failed: u32 = 0,
    skipped: u32 = 0,
    max_rss: usize = 0,
};

fn runCase(
    io: Io,
    path: []const u8,
    aro_exe: []const u8,
    root_node: std.Progress.Node,
    stats: *Stats,
) void {
    defer root_node.completeOne();

    var arena_allocator = std.heap.ArenaAllocator.init(gpa);
    defer arena_allocator.deinit();
    const arena = arena_allocator.allocator();

    const case_node = root_node.start(std.fs.path.stem(path), 0);
    defer case_node.end();

    runCaseExtra(io, arena, path, aro_exe, stats) catch {
        _ = @atomicRmw(u32, &stats.failed, .Add, 1, .monotonic);
    };
}

fn runCaseExtra(
    io: Io,
    arena: mem.Allocator,
    path: []const u8,
    aro_exe: []const u8,
    stats: *Stats,
) !void {
    if (!mem.endsWith(u8, path, ".c")) {
        print("test case is not a .c file: '{s}'\n", .{path});
        return error.InvalidName;
    }
    const cases_dir = std.fs.path.dirname(path) orelse ".";
    const case = try caseFromFile(io, arena, path);

    // TODO should not matter that -fno-color-diagnostics comes after the source file
    const base_args = [_][]const u8{ aro_exe, "-fno-color-diagnostics", std.fs.path.basename(path) };
    const kind_args: []const []const u8 = switch (case.kind) {
        .syntax, .syntax_ignore_errors => &.{ "-fsyntax-only", "--verbose-ast" },
        .expand_error, .expand, .expand_partial => &.{ "-E", "-P" },
        .compare_output => {
            print("{s}: TODO compare output\n", .{case.name});
            _ = @atomicRmw(u32, &stats.skipped, .Add, 1, .monotonic);
            return;
        },
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
    child.cwd = cases_dir;

    child.request_resource_usage_statistics = true;

    var env_map: process.EnvMap = undefined;
    if (case.env.len > 0) {
        env_map = try process.getEnvMap(arena);
        for (case.env) |kv| {
            try env_map.put(kv.key, kv.value);
        }
        child.env_map = &env_map;
    }

    if (@import("builtin").os.tag == .windows) {
        // I have no idea why these block on windows
        if (mem.eql(u8, case.name, "assignment") or
            mem.eql(u8, case.name, "attribute errors") or
            mem.eql(u8, case.name, "initializers") or
            mem.eql(u8, case.name, "layout overflow"))
        {
            print("{s}: skipped on windows\n", .{case.name});
            _ = @atomicRmw(u32, &stats.skipped, .Add, @intCast(case.skips.len), .monotonic);
            return;
        }
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
        if (child.resource_usage_statistics.getMaxRss()) |max_rss| {
            _ = @atomicRmw(usize, &stats.max_rss, .Max, max_rss, .monotonic);
        }
    }

    switch (case.kind) {
        .syntax, .expand_error, .expand, .expand_partial => |expected_errors| {
            var actual_errors: std.ArrayListUnmanaged([]const u8) = .empty;
            defer actual_errors.deinit(gpa);

            {
                var it = mem.tokenizeScalar(u8, stderr, '\n');
                while (it.next()) |msg| {
                    _ = mem.find(u8, msg, "error: ") orelse
                        mem.find(u8, msg, "warning: ") orelse
                        mem.find(u8, msg, "note: ") orelse continue;

                    try actual_errors.append(gpa, msg);
                }
            }

            const len = @min(expected_errors.len, actual_errors.items.len);
            for (expected_errors[0..len], actual_errors.items[0..len]) |expected, actual| {
                if (mem.find(u8, actual, expected) == null) {
                    print(
                        \\
                        \\======= expected to find error =======
                        \\{s}
                        \\
                        \\=== but output does not contain it ===
                        \\{s}
                        \\
                        \\in case '{s}'
                        \\
                    , .{ expected, stderr, case.name });
                    return error.MissingError;
                }
            }
            if (expected_errors.len != actual_errors.items.len) {
                const writer, _ = std.debug.lockStderrWriter(&.{});
                defer std.debug.unlockStderrWriter();
                for (expected_errors[len..]) |expected| {
                    try writer.print(
                        \\
                        \\======= expected to find error =======
                        \\{s}
                        \\
                        \\=== but output does not contain it ===
                        \\{s}
                    , .{ expected, stderr });
                }
                for (actual_errors.items[len..]) |actual| {
                    try writer.print(
                        \\
                        \\========= new error ==========
                        \\{s}
                        \\
                        \\=== not in expected errors ===
                        \\
                    , .{actual});
                }
                try writer.print("in case '{s}'\n", .{case.name});
                return error.MismatchedErrors;
            }
        },
        .compare_output => {
            print(
                \\{t} resulted in errors:
                \\{s}
                \\
                \\in case '{s}'
                \\
            , .{ case.kind, stderr, case.name });
        },
        .syntax_ignore_errors => {},
    }

    switch (case.kind) {
        .syntax, .syntax_ignore_errors => {
            const ast_path = try std.fs.path.join(arena, &.{ cases_dir, "ast", std.fs.path.basename(path) });
            if (std.fs.cwd().readFileAlloc(ast_path, gpa, .unlimited)) |expected| {
                defer gpa.free(expected);

                std.testing.expectEqualStrings(expected, stdout) catch |err| {
                    std.debug.print("in case '{s}'\n", .{case.name});
                    return err;
                };
            } else |err| if (err != error.FileNotFound) {
                print("can't open ast file '{s}': {t}\n", .{ ast_path, err });
                return err;
            }
        },
        .expand_error => {},
        .expand => {
            const expanded_path = try std.fs.path.join(arena, &.{ cases_dir, "expanded", std.fs.path.basename(path) });
            if (std.fs.cwd().readFileAlloc(expanded_path, gpa, .unlimited)) |expected| {
                defer gpa.free(expected);

                std.testing.expectEqualStrings(expected, stdout) catch |err| {
                    std.debug.print("in case '{s}'\n", .{case.name});
                    return err;
                };
            } else |err| {
                print("can't open expanded file '{s}': {t}\n", .{ expanded_path, err });
                return err;
            }
        },
        .expand_partial => {
            const expanded_path = try std.fs.path.join(arena, &.{ cases_dir, "expanded", std.fs.path.basename(path) });
            if (std.fs.cwd().readFileAlloc(expanded_path, gpa, .unlimited)) |expected| {
                defer gpa.free(expected);

                std.testing.expectStringEndsWith(stdout, expected) catch |err| {
                    std.debug.print("in case '{s}'\n", .{case.name});
                    return err;
                };
            } else |err| {
                print("can't open expanded file '{s}': {t}\n", .{ expanded_path, err });
                return err;
            }
        },
        .compare_output => |expected| {
            std.testing.expectEqualStrings(expected, stdout) catch |err| {
                std.debug.print("in case '{s}'\n", .{case.name});
                return err;
            };
        },
    }

    if (case.skips.len != 0) {
        const writer, _ = std.debug.lockStderrWriter(&.{});
        defer std.debug.unlockStderrWriter();
        for (case.skips) |skip| {
            try writer.print("{s}: {s}\n", .{ case.name, skip });
        }
        _ = @atomicRmw(u32, &stats.skipped, .Add, @intCast(case.skips.len), .monotonic);
    }
}

const Case = struct {
    name: []const u8,
    kind: Kind,
    skips: []const []const u8,
    args: []const []const u8,
    env: []const KV,

    const Kind = union(enum) {
        /// Compile with -fsyntax-only and check expected compile errors.
        syntax: []const []const u8,
        /// Compile with -fsyntax-only and ignore compile errors.
        syntax_ignore_errors,
        /// Compile with -E -P and check expected compile errors .
        expand_error: []const []const u8,
        /// Compile with -E -P and check expected compile errors as well as expansion result.
        expand: []const []const u8,
        /// Compile with -E -P and check expected compile errors as well as expansion result.
        expand_partial: []const []const u8,
        // Unimplemented
        compare_output: []const u8,
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
        const start_key = "/** manifest:";
        const end_key = "*/";
        const start = mem.find(u8, contents, start_key) orelse {
            print("{s}: no test manifest\n", .{name});
            return error.TestManifestMissing;
        };
        const end = mem.findLast(u8, contents, end_key) orelse {
            print("{s}: unterminated manifest\n", .{name});
            return error.UnterminatedManifest;
        };
        const manifest = contents[start + start_key.len .. end];
        break :manifest mem.trim(u8, manifest, " \t\n\r");
    };

    var skips: std.ArrayList([]const u8) = .empty;
    defer skips.deinit(gpa);
    var args: []const []const u8 = &.{};
    var env: []const Case.KV = &.{};

    var it = mem.splitScalar(u8, manifest, '\n');

    const kind = kind: {
        const line = it.next() orelse {
            print("{s}: test case type not specified\n", .{name});
            return error.TestManifestMissingType;
        };
        const trimmed = mem.trim(u8, line, " \t\r");
        break :kind std.meta.stringToEnum(std.meta.Tag(Case.Kind), trimmed) orelse {
            print("{s}: invalid test case type: {s}\n", .{ name, trimmed });
            return error.TestManifestInvalidType;
        };
    };

    while (it.next()) |line| {
        const trimmed = mem.trim(u8, line, " \t\r");
        if (trimmed.len == 0) break; // Start of trailing data.

        const key_raw, const value_raw = mem.cutScalar(u8, trimmed, '=') orelse {
            print("{s}: missing value for config option: {s}\n", .{ name, trimmed });
            return error.TestManifestMissingValue;
        };
        const key = mem.trimEnd(u8, key_raw, " \t");
        const value = mem.trimStart(u8, value_raw, " \t");
        if (mem.eql(u8, key, "skip")) {
            try skips.append(gpa, try arena.dupe(u8, value));
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
            .syntax_ignore_errors => .syntax_ignore_errors,
            .expand_error => .{ .expand_error = try trailingLines(arena, &it) },
            .expand => .{ .expand = try trailingLines(arena, &it) },
            .expand_partial => .{ .expand_partial = try trailingLines(arena, &it) },
            .compare_output => .{ .compare_output = it.rest() },
        },
        .skips = try arena.dupe([]const u8, skips.items),
        .args = args,
        .env = env,
    };
}

fn trailingLines(arena: mem.Allocator, it: *mem.SplitIterator(u8, .scalar)) ![]const []const u8 {
    var buf: std.ArrayList([]const u8) = .empty;
    defer buf.deinit(gpa);

    while (it.next()) |line| {
        try buf.append(gpa, mem.trim(u8, line, " \t\r"));
    }
    return try arena.dupe([]const u8, buf.items);
}
