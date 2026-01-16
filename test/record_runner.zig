const std = @import("std");
const Io = std.Io;
const mem = std.mem;
const print = std.debug.print;
const process = std.process;

/// These tests don't work for any platform due to Aro bugs.
/// Skip entirely.
/// To skip a test entirely just put the test name as a single-element tuple e.g. initComptime(.{.{"0044"}});
const global_test_exclude = std.StaticStringMap(void).initComptime(.{
    .{"0008"},
    .{"0010"},
    .{"0011"},
    .{"0014"},
    .{"0017"},
    .{"0018"},
    .{"0025"},
    .{"0026"},
    .{"0042"},
    .{"0045"},
    .{"0046"},
});

fn lessThan(_: void, lhs: []const u8, rhs: []const u8) bool {
    return mem.lessThan(u8, lhs, rhs);
}

const Stats = struct {
    ok_count: u32 = 0,
    fail_count: u32 = 0,
    skip_count: u32 = 0,
    invalid_target_count: u32 = 0,
    max_alloc: usize = 0,
    root_node: std.Progress.Node,

    const ResultKind = enum {
        ok,
        fail,
        skip,
        invalid_target,
    };

    fn recordResult(self: *Stats, kind: ResultKind) void {
        const ptr = switch (kind) {
            .ok => &self.ok_count,
            .fail => &self.fail_count,
            .skip => &self.skip_count,
            .invalid_target => &self.invalid_target_count,
        };
        _ = @atomicRmw(u32, ptr, .Add, 1, .monotonic);
    }

    fn updateMaxMemUsage(self: *Stats, bytes: usize) void {
        _ = @atomicRmw(usize, &self.max_alloc, .Max, bytes, .monotonic);
    }
};

const TestCase = struct {
    c_define: []const u8,
    target: []const u8,
    path: []const u8,

    const List = std.ArrayList(TestCase);
};

/// Types of failures expected.
/// For any given test. `true` = expected failure
const ExpectedFailure = struct {
    parse: bool = false,
    layout: bool = false,
    extra: bool = false,
    offset: bool = false,

    fn any(self: ExpectedFailure) bool {
        return self.parse or self.layout or self.extra or self.offset;
    }
    fn eql(self: ExpectedFailure, other: ExpectedFailure) bool {
        return std.meta.eql(self, other);
    }
};

const gpa = std.heap.smp_allocator;

pub fn main(init: process.Init.Minimal) !void {
    var arena_allocator = std.heap.ArenaAllocator.init(gpa);
    defer arena_allocator.deinit();
    const arena = arena_allocator.allocator();

    const args = try init.args.toSlice(arena);
    if (args.len != 2) {
        print("Usage: {s} <arocc-exe>", .{args[0]});
        process.exit(1);
    }

    var threaded: std.Io.Threaded = .init(gpa, .{
        .argv0 = .init(init.args),
        .environ = init.environ,
    });
    defer threaded.deinit();
    const io = threaded.io();

    const arocc_exe = args[1];

    var cases: std.ArrayList([]const u8) = .empty;
    defer cases.deinit(gpa);

    // Collect all cases. Set scope to clean when done.
    {
        var cases_dir = try Io.Dir.cwd().openDir(io, "test/records", .{ .iterate = true });
        defer cases_dir.close(io);

        var it = cases_dir.iterate();
        while (try it.next(io)) |entry| {
            if (entry.kind != .file) continue;

            if (std.ascii.indexOfIgnoreCase(entry.name, "_test.c") != null) {
                try cases.append(gpa, try std.fs.path.join(arena, &.{ "test/records", entry.name }));
            }
        }
    }

    mem.sort([]const u8, cases.items, {}, lessThan);

    var test_cases: TestCase.List = .empty;
    defer test_cases.deinit(gpa);

    for (cases.items) |path| {
        try parseTargetsFromCode(io, &test_cases, arena, path);
    }

    const root_node = std.Progress.start(io, .{
        .root_name = "record layout tests",
        .estimated_total_items = test_cases.items.len,
    });

    var group: Io.Group = .init;
    var stats: Stats = .{
        .root_node = root_node,
    };

    for (test_cases.items) |case| {
        group.async(io, runCase, .{ io, arocc_exe, case, &stats });
    }

    try group.await(io);
    root_node.end();

    print("max mem used = {Bi:.2}\n", .{stats.max_alloc});
    if (stats.ok_count == cases.items.len and stats.skip_count == 0) {
        print("All {d} tests passed ({d} invalid targets)\n", .{ stats.ok_count, stats.invalid_target_count });
    } else if (stats.fail_count == 0) {
        print("{d} passed; {d} skipped ({d} invalid targets).\n", .{ stats.ok_count, stats.skip_count, stats.invalid_target_count });
    } else {
        print("{d} passed; {d} failed ({d} invalid targets).\n\n", .{ stats.ok_count, stats.fail_count, stats.invalid_target_count });
        process.exit(1);
    }
}

fn runCase(io: Io, aro_exe: []const u8, test_case: TestCase, stats: *Stats) void {
    runCaseExtra(io, aro_exe, test_case, stats) catch {
        stats.recordResult(.fail);
    };
}

fn runCaseExtra(io: Io, aro_exe: []const u8, test_case: TestCase, stats: *Stats) !void {
    const path = test_case.path;

    var arena_allocator = std.heap.ArenaAllocator.init(gpa);
    defer arena_allocator.deinit();
    const arena = arena_allocator.allocator();

    const target_str, _ = mem.cutScalar(u8, test_case.target, ':').?;
    var iter = mem.tokenizeScalar(u8, target_str, '-');
    const arch = iter.next().?;
    const model = iter.next().?;
    const os = iter.next().?;
    const abi = iter.next().?;

    var buf: [128]u8 = undefined;
    var w = Io.Writer.fixed(&buf);
    try w.print("{s}-{s}-{s}", .{ arch, os, abi });

    const query = try std.Target.Query.parse(.{
        .arch_os_abi = w.buffered(),
        .cpu_features = model,
    });
    const target = try std.zig.system.resolveTargetQuery(io, query);
    switch (target.os.tag) {
        .hermit => {
            stats.recordResult(.invalid_target);
            return; // Skip targets Aro doesn't support.
        },
        .ios, .macos => {
            switch (target.cpu.arch) {
                .x86, .arm => {
                    stats.recordResult(.invalid_target);
                    return; // Skip targets Aro doesn't support.
                },
                else => {},
            }
        },
        else => {},
    }

    var name_buf: [1024]u8 = undefined;
    var name_writer: Io.Writer = .fixed(&name_buf);

    const test_name = mem.sliceTo(std.fs.path.basename(path), '_');
    try name_writer.print("{s} | {s} | {s}", .{
        test_name,
        test_case.target,
        test_case.c_define,
    });

    var case_node = stats.root_node.start(name_writer.buffered(), 0);
    defer case_node.end();

    var args: std.ArrayList([]const u8) = .empty;
    defer args.deinit(gpa);

    try args.appendSlice(gpa, &.{
        aro_exe,
        path,
        "-fsyntax-only",
        "-fno-color-diagnostics",
        "-target",
        w.buffered(),
        "-mcpu",
        model,
        "--verbose-ast",
        "-D",
        test_case.c_define,
    });
    if (target.abi == .msvc) {
        try args.append(gpa, "-DMSVC");
    }

    var stderr: []u8 = undefined;
    const code = code: {
        var child = try process.spawn(io, .{
            .argv = args.items,

            .stdout = .ignore,
            .stderr = .pipe,
            .stdin = .ignore,

            .request_resource_usage_statistics = true,
        });
        defer child.kill(io);

        var stderr_reader = child.stderr.?.readerStreaming(io, &.{});
        stderr = try stderr_reader.interface.allocRemaining(arena, .unlimited);

        const term = try child.wait(io);
        if (term != .exited) {
            const cmd = try mem.join(arena, " ", args.items);
            print("arocc command crashed:\n{s}\n", .{cmd});
            return error.Crashed;
        }
        if (child.resource_usage_statistics.getMaxRss()) |max_rss| {
            stats.updateMaxMemUsage(max_rss);
        }

        break :code term.exited;
    };

    if (global_test_exclude.has(test_name)) {
        stats.recordResult(.skip);
        return;
    }

    var expected_buf: [128]u8 = undefined;
    var expected_writer: std.Io.Writer = .fixed(&expected_buf);
    try expected_writer.print("{s}|{s}", .{ test_case.target, test_name });

    const expected = compErr.get(expected_writer.buffered()) orelse ExpectedFailure{};

    if (code == 0 and expected.any()) {
        print("\nTest Passed when failures expected:\n\texpected:{any}\n", .{expected});
        stats.recordResult(.fail);
    } else {
        var actual = ExpectedFailure{};
        var it = mem.tokenizeScalar(u8, stderr, '\n');
        while (it.next()) |msg| {
            if (mem.find(u8, msg, ": error: ") == null) continue;
            const line = it.next().?;

            if (std.ascii.indexOfIgnoreCase(line, "_Static_assert") != null) {
                if (std.ascii.indexOfIgnoreCase(line, "_extra_") != null) {
                    actual.extra = true;
                } else if (std.ascii.indexOfIgnoreCase(line, "_bitoffsetof") != null) {
                    actual.offset = true;
                } else if (std.ascii.indexOfIgnoreCase(line, "sizeof") != null or
                    std.ascii.indexOfIgnoreCase(line, "_alignof") != null)
                {
                    actual.layout = true;
                } else unreachable;
            } else {
                actual.parse = true;
            }
        }
        if (!expected.eql(actual)) {
            print("in case {s}:\nexp:{any}\nact:{any}\n{s}", .{ expected_writer.buffered(), expected, actual, stderr });
            stats.recordResult(.fail);
        } else if (actual.any()) {
            stats.recordResult(.skip);
        } else {
            stats.recordResult(.ok);
        }
    }
}

fn parseTargetsFromCode(io: Io, cases: *TestCase.List, arena: mem.Allocator, path: []const u8) !void {
    const source = try Io.Dir.cwd().readFileAlloc(io, path, gpa, .unlimited);
    defer gpa.free(source);

    var index: usize = 0;
    while (mem.indexOfPos(u8, source, index, "// MAPPING|")) |mapping_start| {
        const line, _ = mem.cutScalar(u8, source[mapping_start..], '\n').?;
        index = mapping_start + line.len;

        var parts = mem.tokenizeScalar(u8, line, '|');
        _ = parts.next(); // Skip the MAPPING bit
        const define = parts.next().?; // The define to set for this chunk.

        while (parts.next()) |target| {
            if (mem.startsWith(u8, target, "END")) break;
            // These point to source, which lives
            // for the life of the test. So should be ok
            try cases.append(gpa, .{
                .path = path,
                .c_define = try arena.dupe(u8, define),
                .target = try arena.dupe(u8, target),
            });
        }
    }
}

const compErr = blk: {
    @setEvalBranchQuota(100_000);
    break :blk std.StaticStringMap(ExpectedFailure).initComptime(&[_]struct { []const u8, ExpectedFailure }{
        .{
            "aarch64-generic-windows-msvc:Msvc|0018",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "aarch64-generic-windows-msvc:Msvc|0020",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "aarch64-generic-windows-msvc:Msvc|0020",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "aarch64-generic-windows-msvc:Msvc|0021",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "aarch64-generic-windows-msvc:Msvc|0023",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "aarch64-generic-windows-msvc:Msvc|0025",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "aarch64-generic-windows-msvc:Msvc|0026",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "aarch64-generic-windows-msvc:Msvc|0029",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "aarch64-generic-windows-msvc:Msvc|0037",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "aarch64-generic-windows-msvc:Msvc|0039",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "aarch64-generic-windows-msvc:Msvc|0042",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "aarch64-generic-windows-msvc:Msvc|0044",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "aarch64-generic-windows-msvc:Msvc|0045",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "aarch64-generic-windows-msvc:Msvc|0053",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "aarch64-generic-windows-msvc:Msvc|0063",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "aarch64-generic-windows-msvc:Msvc|0065",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "aarch64-generic-windows-msvc:Msvc|0066",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "aarch64-generic-windows-msvc:Msvc|0072",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "aarch64-generic-windows-msvc:Msvc|0080",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86-i586-windows-msvc:Msvc|0018",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "x86-i586-windows-msvc:Msvc|0023",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86-i586-windows-msvc:Msvc|0025",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86-i586-windows-msvc:Msvc|0026",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86-i586-windows-msvc:Msvc|0029",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86-i586-windows-msvc:Msvc|0042",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "x86-i586-windows-msvc:Msvc|0044",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86-i586-windows-msvc:Msvc|0045",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "x86-i586-windows-msvc:Msvc|0053",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "x86-i586-windows-msvc:Msvc|0063",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86-i586-windows-msvc:Msvc|0065",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86-i586-windows-msvc:Msvc|0066",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86-i686-uefi-msvc:Msvc|0018",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "x86-i686-uefi-msvc:Msvc|0023",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86-i686-uefi-msvc:Msvc|0025",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86-i686-uefi-msvc:Msvc|0026",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86-i686-uefi-msvc:Msvc|0029",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86-i686-uefi-msvc:Msvc|0042",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "x86-i686-uefi-msvc:Msvc|0044",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86-i686-uefi-msvc:Msvc|0045",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "x86-i686-uefi-msvc:Msvc|0053",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "x86-i686-uefi-msvc:Msvc|0063",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86-i686-uefi-msvc:Msvc|0065",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86-i686-uefi-msvc:Msvc|0066",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86-i686-windows-msvc:Msvc|0018",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "x86-i686-windows-msvc:Msvc|0023",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86-i686-windows-msvc:Msvc|0025",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86-i686-windows-msvc:Msvc|0026",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86-i686-windows-msvc:Msvc|0029",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86-i686-windows-msvc:Msvc|0042",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "x86-i686-windows-msvc:Msvc|0044",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86-i686-windows-msvc:Msvc|0045",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "x86-i686-windows-msvc:Msvc|0053",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "x86-i686-windows-msvc:Msvc|0063",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86-i686-windows-msvc:Msvc|0065",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86-i686-windows-msvc:Msvc|0066",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "thumb-baseline-windows-msvc:Msvc|0018",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "thumb-baseline-windows-msvc:Msvc|0020",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "thumb-baseline-windows-msvc:Msvc|0021",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "thumb-baseline-windows-msvc:Msvc|0023",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "thumb-baseline-windows-msvc:Msvc|0025",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "thumb-baseline-windows-msvc:Msvc|0026",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "thumb-baseline-windows-msvc:Msvc|0029",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "thumb-baseline-windows-msvc:Msvc|0037",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "thumb-baseline-windows-msvc:Msvc|0039",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "thumb-baseline-windows-msvc:Msvc|0042",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "thumb-baseline-windows-msvc:Msvc|0044",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "thumb-baseline-windows-msvc:Msvc|0045",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "thumb-baseline-windows-msvc:Msvc|0053",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "thumb-baseline-windows-msvc:Msvc|0063",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "thumb-baseline-windows-msvc:Msvc|0065",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "thumb-baseline-windows-msvc:Msvc|0066",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "thumb-baseline-windows-msvc:Msvc|0072",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "thumb-baseline-windows-msvc:Msvc|0080",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-uefi-msvc:Msvc|0018",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-uefi-msvc:Msvc|0023",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-uefi-msvc:Msvc|0025",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-uefi-msvc:Msvc|0026",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-uefi-msvc:Msvc|0029",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-uefi-msvc:Msvc|0042",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "x86_64-x86_64-uefi-msvc:Msvc|0044",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-uefi-msvc:Msvc|0045",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-uefi-msvc:Msvc|0053",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-uefi-msvc:Msvc|0063",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-uefi-msvc:Msvc|0065",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-uefi-msvc:Msvc|0066",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-msvc:Msvc|0018",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-msvc:Msvc|0023",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-msvc:Msvc|0025",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-msvc:Msvc|0026",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-msvc:Msvc|0029",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-msvc:Msvc|0042",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "x86_64-x86_64-windows-msvc:Msvc|0044",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-msvc:Msvc|0045",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-msvc:Msvc|0053",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-msvc:Msvc|0063",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-msvc:Msvc|0065",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-msvc:Msvc|0066",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
    });
};
