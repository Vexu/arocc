const std = @import("std");
const print = std.debug.print;
const aro = @import("aro");

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
    return std.mem.lessThan(u8, lhs, rhs);
}

const MAX_MEM_PER_TEST = 1024 * 1024 * 16;

/// Set true to debug specific targets w/ specific tests.
const test_single_target = false;
const single_target = .{
    // .target = "arm-cortex_r4-ios-none:Clang",
    // .c_test = "0064",
    // .target = "s390x-generic-linux-gnu:Gcc",
    // .c_test = "00", // run all the tests
    // .target = "x86-i586-linux-gnu:Gcc",
    // .c_test = "0002",
    .target = "x86_64-x86_64-windows-msvc:Msvc",
    .c_test = "0018", // run all the tests
    // .target = "arm-arm1136j_s-freebsd-gnu:Clang",
    // .c_test = "0052",
};

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
    source: []const u8,

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
const builtin = @import("builtin");

pub fn main() !void {
    var general_purpose_allocator = std.heap.GeneralPurposeAllocator(.{}){};
    const gpa = general_purpose_allocator.allocator();
    defer if (general_purpose_allocator.deinit() == .leak) std.process.exit(1);

    const args = try std.process.argsAlloc(gpa);
    defer std.process.argsFree(gpa, args);

    if (args.len != 2) {
        print("expected test case directory as only argument\n", .{});
        return error.InvalidArguments;
    }

    const test_dir = args[1];

    var cases = std.ArrayList([]const u8).init(gpa);
    defer {
        for (cases.items) |path| gpa.free(path);
        cases.deinit();
    }

    // Collect all cases. Set scope to clean when done.
    {
        var cases_dir = try std.fs.cwd().openDir(args[1], .{ .iterate = true });
        defer cases_dir.close();
        var name_buf: [1024]u8 = undefined;
        var name_writer: std.io.Writer = .fixed(&name_buf);

        var it = cases_dir.iterate();
        while (try it.next()) |entry| {
            if (entry.kind == .directory) continue;
            if (entry.kind != .file) {
                print("skipping non file entry '{s}'\n", .{entry.name});
                continue;
            }

            if (std.ascii.indexOfIgnoreCase(entry.name, "_test.c") != null) {
                _ = name_writer.consumeAll();
                try name_writer.print("{s}{c}{s}", .{ args[1], std.fs.path.sep, entry.name });
                try cases.append(try gpa.dupe(u8, name_writer.buffered()));
            }
        }
    }

    std.mem.sort([]const u8, cases.items, {}, lessThan);

    var arena_instance = std.heap.ArenaAllocator.init(gpa);
    defer arena_instance.deinit();
    const arena = arena_instance.allocator();

    const thread_count = @max(1, std.Thread.getCpuCount() catch 1);

    var thread_pool: std.Thread.Pool = undefined;
    try thread_pool.init(.{ .allocator = arena, .n_jobs = @intCast(thread_count) });
    defer thread_pool.deinit();

    var wait_group: std.Thread.WaitGroup = .{};

    var test_cases = TestCase.List.init(gpa);
    defer test_cases.deinit();

    for (cases.items) |path| {
        const source = try std.fs.cwd().readFileAlloc(arena, path, std.math.maxInt(u32));
        try parseTargetsFromCode(&test_cases, path, source);
    }

    const root_node = std.Progress.start(.{
        .disable_printing = false,
        .root_name = "Layout",
        .estimated_total_items = test_cases.items.len,
    });

    var stats = Stats{
        .root_node = root_node,
    };

    for (0..thread_count) |i| {
        wait_group.start();
        try thread_pool.spawn(runTestCases, .{
            gpa, test_dir, &wait_group, test_cases.items[i..], thread_count, &stats,
        });
    }

    thread_pool.waitAndWork(&wait_group);
    root_node.end();

    std.debug.print("max mem used = {Bi:.2}\n", .{stats.max_alloc});
    if (stats.ok_count == cases.items.len and stats.skip_count == 0) {
        print("All {d} tests passed ({d} invalid targets)\n", .{ stats.ok_count, stats.invalid_target_count });
    } else if (stats.fail_count == 0) {
        print("{d} passed; {d} skipped ({d} invalid targets).\n", .{ stats.ok_count, stats.skip_count, stats.invalid_target_count });
    } else {
        print("{d} passed; {d} failed ({d} invalid targets).\n\n", .{ stats.ok_count, stats.fail_count, stats.invalid_target_count });
        std.process.exit(1);
    }
}

fn runTestCases(allocator: std.mem.Allocator, test_dir: []const u8, wg: *std.Thread.WaitGroup, test_cases: []const TestCase, stride: usize, stats: *Stats) void {
    defer wg.finish();
    const mem = allocator.alloc(u8, MAX_MEM_PER_TEST) catch |err| {
        std.log.err("{s}", .{@errorName(err)});
        if (@errorReturnTrace()) |trace| {
            std.debug.dumpStackTrace(trace.*);
        }
        stats.recordResult(.fail);
        return;
    };
    defer allocator.free(mem);
    var fib = std.heap.FixedBufferAllocator.init(mem);

    for (test_cases, 0..) |case, i| {
        if (i % stride != 0) continue;
        defer fib.end_index = 0;

        singleRun(fib.allocator(), test_dir, case, stats) catch |err| {
            std.log.err("{s}", .{@errorName(err)});
            if (@errorReturnTrace()) |trace| {
                std.debug.dumpStackTrace(trace.*);
            }
            stats.recordResult(.fail);
        };
        stats.updateMaxMemUsage(fib.end_index);
    }
}

fn singleRun(gpa: std.mem.Allocator, test_dir: []const u8, test_case: TestCase, stats: *Stats) !void {
    const path = test_case.path;

    var arena: std.heap.ArenaAllocator = .init(gpa);
    defer arena.deinit();

    var diagnostics: aro.Diagnostics = .{
        .output = .{ .to_list = .{
            .arena = .init(gpa),
        } },
    };
    defer diagnostics.deinit();

    var comp = aro.Compilation.init(gpa, arena.allocator(), &diagnostics, std.fs.cwd());
    defer comp.deinit();

    try comp.addDefaultPragmaHandlers();
    try comp.addBuiltinIncludeDir(test_dir, null);

    try setTarget(&comp, test_case.target);
    switch (comp.target.os.tag) {
        .hermit => {
            stats.recordResult(.invalid_target);
            return; // Skip targets Aro doesn't support.
        },
        .ios, .macos => {
            switch (comp.target.cpu.arch) {
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
    var name_writer: std.io.Writer = .fixed(&name_buf);

    const test_name = std.mem.sliceTo(std.fs.path.basename(path), '_');
    try name_writer.print("{s} | {s} | {s}", .{
        test_name,
        test_case.target,
        test_case.c_define,
    });

    var case_node = stats.root_node.start(name_writer.buffered(), 0);
    defer case_node.end();

    const file = comp.addSourceFromBuffer(path, test_case.source) catch |err| {
        stats.recordResult(.fail);
        std.debug.print("could not add source '{s}': {s}\n", .{ path, @errorName(err) });
        return;
    };

    comp.langopts.setEmulatedCompiler(aro.target_util.systemCompiler(comp.target));

    var macro_buf: [1024]u8 = undefined;
    var macro_writer: std.io.Writer = .fixed(&macro_buf);
    try macro_writer.print("#define {s}\n", .{test_case.c_define});
    if (comp.langopts.emulate == .msvc) {
        comp.langopts.setMSExtensions(true);
        try macro_writer.writeAll("#define MSVC\n");
    }

    const user_macros = try comp.addSourceFromBuffer(macro_writer.buffered(), "<command line>");
    const builtin_macros = try comp.generateBuiltinMacros(.include_system_defines);

    var pp = try aro.Preprocessor.initDefault(&comp);
    defer pp.deinit();

    _ = try pp.preprocess(builtin_macros);
    _ = try pp.preprocess(user_macros);
    const eof = pp.preprocess(file) catch |err| {
        stats.recordResult(.fail);
        std.debug.print("could not preprocess file '{s}': {s}\n", .{ path, @errorName(err) });
        return;
    };
    try pp.addToken(eof);

    var tree = try aro.Parser.parse(&pp);
    defer tree.deinit();
    {
        var discard_buf: [256]u8 = undefined;
        var discarding: std.io.Writer.Discarding = .init(&discard_buf);
        tree.dump(.no_color, &discarding.writer) catch {};
    }

    if (test_single_target) {
        printDiagnostics(&diagnostics);
        return;
    }

    if (global_test_exclude.has(test_name)) {
        stats.recordResult(.skip);
        return;
    }

    var expected_buf: [128]u8 = undefined;
    var expected_writer: std.io.Writer = .fixed(&expected_buf);
    try expected_writer.print("{s}|{s}", .{ test_case.target, test_name });

    const expected = compErr.get(expected_writer.buffered()) orelse ExpectedFailure{};

    if (diagnostics.total == 0 and expected.any()) {
        std.debug.print("\nTest Passed when failures expected:\n\texpected:{any}\n", .{expected});
        stats.recordResult(.fail);
    } else {
        var actual = ExpectedFailure{};
        for (diagnostics.output.to_list.messages.items) |msg| {
            switch (msg.kind) {
                .@"fatal error", .@"error" => {},
                else => continue,
            }
            const line = msg.location.?.line;
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
            std.debug.print("\nexp:{any}\nact:{any}\n", .{ expected, actual });
            printDiagnostics(&diagnostics);
            stats.recordResult(.fail);
        } else if (actual.any()) {
            stats.recordResult(.skip);
        } else {
            stats.recordResult(.ok);
        }
    }
}

fn printDiagnostics(diagnostics: *aro.Diagnostics) void {
    for (diagnostics.output.to_list.messages.items) |msg| {
        if (msg.location) |loc| {
            std.debug.print("{s}:{d}:{d}: {s}: {s}\n{s}\n", .{
                loc.path, loc.line_no, loc.col, @tagName(msg.kind), msg.text, loc.line,
            });
        } else {
            std.debug.print("{s}: {s}\n", .{ @tagName(msg.kind), msg.text });
        }
    }
}

/// Get Zig std.Target from string in the arch-cpu-os-abi format.
fn getTarget(zig_target_string: []const u8) !std.Target {
    var buf: [128]u8 = undefined;
    var iter = std.mem.tokenizeScalar(u8, zig_target_string, '-');
    const arch = iter.next().?;
    const model = iter.next().?;
    const os = iter.next().?;
    const abi = iter.next().?;
    var fb = std.io.fixedBufferStream(&buf);
    try std.fmt.format(fb.writer(), "{s}-{s}-{s}", .{ arch, os, abi });

    const query = try std.Target.Query.parse(.{
        .arch_os_abi = fb.getWritten(),
        .cpu_features = model,
    });
    return std.zig.system.resolveTargetQuery(query);
}

fn setTarget(comp: *aro.Compilation, target: []const u8) !void {
    const compiler_split_index = std.mem.indexOf(u8, target, ":").?;

    comp.target = try getTarget(target[0..compiler_split_index]);
    comp.langopts.emulate = aro.target_util.systemCompiler(comp.target);

    const expected_compiler_name = target[compiler_split_index + 1 ..];
    const set_name = @tagName(comp.langopts.emulate);
    std.debug.assert(std.ascii.eqlIgnoreCase(set_name, expected_compiler_name));
}

fn parseTargetsFromCode(cases: *TestCase.List, path: []const u8, source: []const u8) !void {
    var lines = std.mem.tokenizeScalar(u8, source, '\n');
    while (lines.next()) |line| {
        if (std.mem.indexOf(u8, line, "// MAPPING|") == null) continue;

        std.debug.assert(std.mem.count(u8, line, "|") > 1);
        var parts = std.mem.tokenizeScalar(u8, line, '|');
        _ = parts.next(); // Skip the MAPPING bit
        const define = parts.next().?; // The define to set for this chunk.

        while (parts.next()) |target| {
            if (std.mem.startsWith(u8, target, "END")) break;
            // These point to source, which lives
            // for the life of the test. So should be ok
            try cases.append(.{
                .path = path,
                .source = source,
                .c_define = define,
                .target = target,
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
