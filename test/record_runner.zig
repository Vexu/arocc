const std = @import("std");
const print = std.debug.print;
const aro = @import("aro");

/// These tests don't work for any platform due to Aro bugs.
/// Skip entirely.
const global_test_exclude = std.ComptimeStringMap(void, .{
    .{"0044"},
});

/// Set true to debug specific targets w/ specific tests.
const test_single_target = false;
const single_target = .{
    // .target = "arm-cortex_r4-ios-none:Clang",
    // .c_test = "0064",
    // .target = "s390x-generic-linux-gnu:Gcc",
    // .c_test = "00", // run all the tests
    // .target = "i386-i586-linux-gnu:Gcc",
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
    progress: *std.Progress,
    root_node: *std.Progress.Node,
};

const TestCase = struct {
    c_define: []const u8,
    target: []const u8,
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
};

pub fn main() !void {
    var general_purpose_allocator = std.heap.GeneralPurposeAllocator(.{}){};
    const gpa = general_purpose_allocator.allocator();
    // max file size < 2M. max total use < 12M
    var fixed_buffer = try gpa.alloc(u8, 1024 * 1024 * 16);
    var fixed_alloc = std.heap.FixedBufferAllocator.init(fixed_buffer);
    const alloc = fixed_alloc.allocator();
    defer {
        gpa.free(fixed_buffer);
        if (general_purpose_allocator.deinit()) std.process.exit(1);
    }

    var args = try std.process.argsAlloc(gpa);
    defer std.process.argsFree(gpa, args);

    if (args.len != 3) {
        print("expected test case directory and zig executable as only arguments\n", .{});
        return error.InvalidArguments;
    }

    var cases = std.ArrayList([]const u8).init(gpa);
    defer {
        for (cases.items) |path| gpa.free(path);
        cases.deinit();
    }

    // Collect all cases. Set scope to clean when done.
    {
        var cases_dir = try std.fs.cwd().openIterableDir(args[1], .{});
        defer cases_dir.close();
        var buf: [1024]u8 = undefined;
        var buf_strm = std.io.fixedBufferStream(&buf);

        var it = cases_dir.iterate();
        while (try it.next()) |entry| {
            if (entry.kind == .Directory) continue;
            if (entry.kind != .File) {
                print("skipping non file entry '{s}'\n", .{entry.name});
                continue;
            }

            if (std.ascii.indexOfIgnoreCase(entry.name, "_test.c") != null) {
                buf_strm.reset();
                try buf_strm.writer().print("{s}{c}{s}", .{ args[1], std.fs.path.sep, entry.name });
                try cases.append(try gpa.dupe(u8, buf[0..buf_strm.pos]));
            }
        }
    }

    std.sort.sort([]const u8, cases.items, u8, std.mem.lessThan);

    var progress = std.Progress{};
    const root_node = progress.start("Layout", 0);

    var stats = Stats{
        .progress = &progress,
        .root_node = root_node,
    };
    // The most memory used for a single run.
    var max_alloc_size: usize = 0;

    // Iterate over all cases
    for (cases.items) |path| {
        fixed_alloc.reset();
        // Read the test into memory.
        const source: []const u8 = fread: {
            const file = try std.fs.cwd().openFile(path, .{});
            defer file.close();
            const file_size = (try file.stat()).size;
            var src_buf = try alloc.alloc(u8, file_size);
            const read_len = try file.readAll(src_buf);
            std.debug.assert(read_len >= file_size);
            break :fread src_buf[0..read_len];
        };

        const test_targets = try parseTargetsFromCode(alloc, source);
        defer test_targets.deinit();

        // Reset the fixed allocator to this point before each run.
        const mem_reset_pos = fixed_alloc.end_index;
        for (test_targets.items) |test_case| {
            if (test_single_target) {
                if (std.ascii.indexOfIgnoreCase(test_case.target, single_target.target) == null) continue;
                if (std.mem.indexOf(u8, path, single_target.c_test) == null) continue;
            }
            fixed_alloc.end_index = mem_reset_pos;

            try singleRun(alloc, path, source, test_case, &stats);

            max_alloc_size = std.math.max(max_alloc_size, fixed_alloc.end_index);
        }
    }

    root_node.end();
    std.debug.print("max mem used = {:.2}\n", .{std.fmt.fmtIntSizeBin(max_alloc_size)});
    if (stats.ok_count == cases.items.len and stats.skip_count == 0) {
        print("All {d} tests passed.\n", .{stats.ok_count});
    } else if (stats.fail_count == 0) {
        print("{d} passed; {d} skipped.\n", .{ stats.ok_count, stats.skip_count });
    } else {
        print("{d} passed; {d} failed.\n\n", .{ stats.ok_count, stats.fail_count });
        std.process.exit(1);
    }
}

fn singleRun(alloc: std.mem.Allocator, path: []const u8, source: []const u8, test_case: TestCase, state: *Stats) !void {
    var comp = aro.Compilation.init(alloc);
    defer comp.deinit();

    try comp.addDefaultPragmaHandlers();
    try comp.defineSystemIncludes();

    const target = setTarget(&comp, test_case.target) catch |err| switch (err) {
        error.InvalidTarget => return, // Skip invalid targets.
        error.UnknownCpuModel => unreachable,
    };
    switch (target.os.tag) {
        .hermit => return, // Skip targets Aro doesn't support.
        else => {},
    }

    var case_name = std.ArrayList(u8).init(alloc);
    defer case_name.deinit();

    const test_name = std.mem.sliceTo(std.fs.path.basename(path), '_');
    try case_name.writer().print("{s} | {s} | {s}", .{
        test_name,
        test_case.target,
        test_case.c_define,
    });

    var case_node = state.root_node.start(case_name.items, 0);
    case_node.activate();
    defer case_node.end();
    state.progress.refresh();

    const file = comp.addSourceFromBuffer(path, source) catch |err| {
        state.fail_count += 1;
        state.progress.log("could not add source '{s}': {s}\n", .{ path, @errorName(err) });
        return;
    };

    var macro_buf = std.ArrayList(u8).init(comp.gpa);
    defer macro_buf.deinit();

    comp.langopts.setEmulatedCompiler(comp.systemCompiler());

    const mac_writer = macro_buf.writer();
    try mac_writer.print("#define {s}\n", .{test_case.c_define});
    if (comp.target.os.tag == .windows) {
        comp.langopts.enableMSExtensions();
        try mac_writer.writeAll("#define MSVC\n");
    }

    var source_files = std.ArrayList(aro.Source).init(std.testing.failing_allocator);
    _ = try aro.parseArgs(&comp, std.io.null_writer, &source_files, mac_writer, &.{});

    const user_macros = try comp.addSourceFromBuffer("<command line>", macro_buf.items);
    const builtin_macros = try comp.generateBuiltinMacros();

    var pp = aro.Preprocessor.init(&comp);
    defer pp.deinit();
    try pp.addBuiltinMacros();

    _ = try pp.preprocess(builtin_macros);
    _ = try pp.preprocess(user_macros);
    const eof = pp.preprocess(file) catch |err| {
        if (!std.unicode.utf8ValidateSlice(file.buf)) {
            // non-utf8 files are not preprocessed, so we can't use EXPECTED_ERRORS; instead we
            // check that the most recent error is .invalid_utf8
            if (comp.diag.list.items.len > 0 and comp.diag.list.items[comp.diag.list.items.len - 1].tag == .invalid_utf8) {
                _ = comp.diag.list.pop();
                return;
            }
        }

        state.fail_count += 1;
        state.progress.log("could not preprocess file '{s}': {s}\n", .{ path, @errorName(err) });
        return;
    };
    try pp.tokens.append(alloc, eof);

    var tree = try aro.Parser.parse(&pp);
    defer tree.deinit();
    tree.dump(false, std.io.null_writer) catch {};

    if (test_single_target) |_| {
        comp.renderErrors();
        return;
    }

    if (global_test_exclude.has(test_name)) {
        state.skip_count += 1;
        return;
    }

    var buf: [128]u8 = undefined;
    var buf_strm = std.io.fixedBufferStream(&buf);
    try buf_strm.writer().print("{s}|{s}", .{ test_case.target, test_name });

    const expected = compErr.get(buf[0..buf_strm.pos]) orelse ExpectedFailure{};

    if (comp.diag.list.items.len == 0 and expected.any()) {
        state.progress.log("\nTest Passed when failures expected:\n\texpected:{any}\n", .{expected});
    } else {
        var m = aro.Diagnostics.defaultMsgWriter(&comp);
        defer m.deinit();
        var expected_errors = false;
        var new_error = false;
        for (comp.diag.list.items) |msg| {
            switch (msg.kind) {
                .@"fatal error", .@"error" => {},
                else => continue,
            }
            const src = comp.getSource(msg.loc.id);
            const line = src.lineCol(msg.loc).line;
            var render = false;
            if (std.ascii.indexOfIgnoreCase(line, "_Static_assert") != null) {
                if (std.ascii.indexOfIgnoreCase(line, "_extra_") != null) {
                    // MSVC _extra_ tests are all assumed to fail atm.
                    if (comp.langopts.emulate == .msvc or expected.extra) expected_errors = true else render = true;
                } else if (std.ascii.indexOfIgnoreCase(line, "_bitoffsetof") != null) {
                    if (!expected.offset) render = true else expected_errors = true;
                } else if (std.ascii.indexOfIgnoreCase(line, "sizeof") != null or
                    std.ascii.indexOfIgnoreCase(line, "_alignof") != null)
                {
                    if (!expected.layout) render = true else expected_errors = true;
                } else unreachable;
            } else if (!expected.parse) render = true else expected_errors = true;

            if (render) {
                if (!new_error) m.print("\n", .{});
                aro.Diagnostics.renderMessage(&comp, &m, msg);
                new_error = true;
            }
        }
        if (new_error) {
            state.fail_count += 1;
        } else if (expected_errors) {
            state.skip_count += 1;
        } else {
            state.ok_count += 1;
        }
    }
}

/// Get Zig std.Target from string in the arch-cpu-os-abi format.
fn getTarget(zig_target_string: []const u8) !std.Target {
    var ret: std.Target = undefined;
    var iter = std.mem.tokenize(u8, zig_target_string, "-");

    ret.cpu.arch = std.meta.stringToEnum(std.Target.Cpu.Arch, iter.next().?).?;
    ret.cpu.model = try std.Target.Cpu.Arch.parseCpuModel(ret.cpu.arch, iter.next().?);

    const tag = std.meta.stringToEnum(std.Target.Os.Tag, iter.next().?).?;
    // `defaultVersionRange` will panic for invalid targets, check that
    // here and return an error instead.
    if (tag == .macos) {
        switch (ret.cpu.arch) {
            .x86_64, .aarch64 => {},
            else => return error.InvalidTarget,
        }
    }

    ret.os = std.Target.Os.Tag.defaultVersionRange(tag, ret.cpu.arch);
    ret.abi = std.meta.stringToEnum(std.Target.Abi, iter.next().?).?;
    return ret;
}

fn setTarget(comp: *aro.Compilation, target: []const u8) !std.Target {
    const compiler_split_index = std.mem.indexOf(u8, target, ":").?;

    const zig_target = try getTarget(target[0..compiler_split_index]);
    comp.target.cpu = std.Target.Cpu.Model.toCpu(zig_target.cpu.model, zig_target.cpu.arch);
    comp.target.os.tag = zig_target.os.tag;
    comp.target.os.version_range = zig_target.os.version_range;
    comp.target.abi = zig_target.abi;

    comp.langopts.emulate = comp.systemCompiler();

    const expected_compiler_name = target[compiler_split_index + 1 ..];
    const set_name = @tagName(comp.langopts.emulate);
    std.debug.assert(std.ascii.eqlIgnoreCase(set_name, expected_compiler_name));

    return zig_target;
}

fn parseTargetsFromCode(alloc: std.mem.Allocator, source: []const u8) !std.ArrayList(TestCase) {
    var result = std.ArrayList(TestCase).init(alloc);
    var lines = std.mem.tokenize(u8, source, "\n");
    while (lines.next()) |line| {
        if (std.mem.indexOf(u8, line, "// MAPPING|") == null) continue;

        std.debug.assert(std.mem.count(u8, line, "|") > 1);
        var parts = std.mem.tokenize(u8, line, "|");
        _ = parts.next(); // Skip the MAPPING bit
        const define = parts.next().?; // The define to set for this chunk.

        while (parts.next()) |target| {
            if (std.mem.startsWith(u8, target, "END")) break;
            // skip MinGW targets for now.
            if (std.ascii.indexOfIgnoreCase(target, "windows-gnu") != null) continue;
            // These point to source, which lives
            // for the life of the test. So should be ok
            try result.append(.{
                .c_define = define,
                .target = target,
            });
        }
    }
    return result;
}

const compErr = blk: {
    @setEvalBranchQuota(100_000);
    break :blk std.ComptimeStringMap(ExpectedFailure, .{
        .{
            "aarch64-generic-windows-msvc:Msvc|0003",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "aarch64-generic-windows-msvc:Msvc|0005",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "aarch64-generic-windows-msvc:Msvc|0007",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "aarch64-generic-windows-msvc:Msvc|0009",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "aarch64-generic-windows-msvc:Msvc|0011",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "aarch64-generic-windows-msvc:Msvc|0012",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "aarch64-generic-windows-msvc:Msvc|0014",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
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
            "aarch64-generic-windows-msvc:Msvc|0024",
            .{ .parse = true, .layout = true, .extra = true, .offset = true },
        },
        .{
            "aarch64-generic-windows-msvc:Msvc|0025",
            .{ .parse = true, .layout = true, .extra = true, .offset = true },
        },
        .{
            "aarch64-generic-windows-msvc:Msvc|0026",
            .{ .parse = true, .layout = true, .extra = true, .offset = false },
        },
        .{
            "aarch64-generic-windows-msvc:Msvc|0027",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "aarch64-generic-windows-msvc:Msvc|0028",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "aarch64-generic-windows-msvc:Msvc|0029",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "aarch64-generic-windows-msvc:Msvc|0030",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "aarch64-generic-windows-msvc:Msvc|0031",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
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
            .{ .parse = true, .layout = true, .extra = true, .offset = true },
        },
        .{
            "aarch64-generic-windows-msvc:Msvc|0043",
            .{ .parse = true, .layout = true, .extra = true, .offset = false },
        },
        .{
            "aarch64-generic-windows-msvc:Msvc|0045",
            .{ .parse = true, .layout = true, .extra = true, .offset = true },
        },
        .{
            "aarch64-generic-windows-msvc:Msvc|0046",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "aarch64-generic-windows-msvc:Msvc|0047",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "aarch64-generic-windows-msvc:Msvc|0057",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "aarch64-generic-windows-msvc:Msvc|0058",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "aarch64-generic-windows-msvc:Msvc|0063",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "aarch64-generic-windows-msvc:Msvc|0064",
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
            "aarch64-generic-windows-msvc:Msvc|0077",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "aarch64-generic-windows-msvc:Msvc|0080",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "aarch64-generic-windows-msvc:Msvc|0081",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "aarch64-generic-windows-msvc:Msvc|0088",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "avr-avr2-other-eabi:Gcc|0062",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "hexagon-generic-linux-musl:Clang|0016",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "hexagon-generic-linux-musl:Clang|0019",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "hexagon-generic-linux-musl:Clang|0051",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "hexagon-generic-linux-musl:Clang|0054",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "hexagon-generic-linux-musl:Clang|0060",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "hexagon-generic-linux-musl:Clang|0061",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "hexagon-generic-linux-musl:Clang|0062",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "hexagon-generic-linux-musl:Clang|0063",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i586-windows-msvc:Msvc|0003",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i586-windows-msvc:Msvc|0005",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i586-windows-msvc:Msvc|0007",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i586-windows-msvc:Msvc|0009",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i586-windows-msvc:Msvc|0011",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i586-windows-msvc:Msvc|0012",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i586-windows-msvc:Msvc|0014",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i586-windows-msvc:Msvc|0020",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i586-windows-msvc:Msvc|0021",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i586-windows-msvc:Msvc|0023",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i586-windows-msvc:Msvc|0024",
            .{ .parse = true, .layout = true, .extra = true, .offset = true },
        },
        .{
            "i386-i586-windows-msvc:Msvc|0025",
            .{ .parse = true, .layout = true, .extra = true, .offset = true },
        },
        .{
            "i386-i586-windows-msvc:Msvc|0026",
            .{ .parse = true, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i586-windows-msvc:Msvc|0027",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i586-windows-msvc:Msvc|0028",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "i386-i586-windows-msvc:Msvc|0029",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i586-windows-msvc:Msvc|0030",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i586-windows-msvc:Msvc|0031",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "i386-i586-windows-msvc:Msvc|0037",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i586-windows-msvc:Msvc|0039",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i586-windows-msvc:Msvc|0042",
            .{ .parse = true, .layout = true, .extra = true, .offset = true },
        },
        .{
            "i386-i586-windows-msvc:Msvc|0043",
            .{ .parse = true, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i586-windows-msvc:Msvc|0045",
            .{ .parse = true, .layout = true, .extra = true, .offset = true },
        },
        .{
            "i386-i586-windows-msvc:Msvc|0046",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i586-windows-msvc:Msvc|0047",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i586-windows-msvc:Msvc|0057",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i586-windows-msvc:Msvc|0058",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "i386-i586-windows-msvc:Msvc|0063",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i586-windows-msvc:Msvc|0064",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i586-windows-msvc:Msvc|0065",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i586-windows-msvc:Msvc|0066",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i586-windows-msvc:Msvc|0072",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i586-windows-msvc:Msvc|0077",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i586-windows-msvc:Msvc|0080",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "i386-i586-windows-msvc:Msvc|0081",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i586-windows-msvc:Msvc|0088",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i686-uefi-msvc:Msvc|0005",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i686-uefi-msvc:Msvc|0007",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i686-uefi-msvc:Msvc|0009",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i686-uefi-msvc:Msvc|0011",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i686-uefi-msvc:Msvc|0014",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i686-uefi-msvc:Msvc|0020",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i686-uefi-msvc:Msvc|0021",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i686-uefi-msvc:Msvc|0023",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i686-uefi-msvc:Msvc|0025",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i686-uefi-msvc:Msvc|0026",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i686-uefi-msvc:Msvc|0027",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i686-uefi-msvc:Msvc|0028",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "i386-i686-uefi-msvc:Msvc|0029",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i686-uefi-msvc:Msvc|0030",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i686-uefi-msvc:Msvc|0031",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "i386-i686-uefi-msvc:Msvc|0036",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i686-uefi-msvc:Msvc|0037",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i686-uefi-msvc:Msvc|0039",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i686-uefi-msvc:Msvc|0042",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "i386-i686-uefi-msvc:Msvc|0046",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i686-uefi-msvc:Msvc|0047",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i686-uefi-msvc:Msvc|0057",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i686-uefi-msvc:Msvc|0058",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "i386-i686-uefi-msvc:Msvc|0063",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i686-uefi-msvc:Msvc|0064",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i686-uefi-msvc:Msvc|0065",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i686-uefi-msvc:Msvc|0066",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i686-uefi-msvc:Msvc|0072",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i686-uefi-msvc:Msvc|0077",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i686-uefi-msvc:Msvc|0080",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "i386-i686-uefi-msvc:Msvc|0081",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i686-uefi-msvc:Msvc|0088",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-gnu:Gcc|0001",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-gnu:Gcc|0002",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-gnu:Gcc|0003",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-gnu:Gcc|0004",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-gnu:Gcc|0005",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-gnu:Gcc|0006",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "i386-i686-windows-gnu:Gcc|0007",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-gnu:Gcc|0008",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-gnu:Gcc|0009",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-gnu:Gcc|0010",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-gnu:Gcc|0011",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-gnu:Gcc|0012",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-gnu:Gcc|0014",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-gnu:Gcc|0013",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-gnu:Gcc|0016",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-gnu:Gcc|0019",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-gnu:Gcc|0020",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-gnu:Gcc|0021",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-gnu:Gcc|0023",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-gnu:Gcc|0024",
            .{ .parse = true, .layout = true, .extra = true, .offset = true },
        },
        .{
            "i386-i686-windows-gnu:Gcc|0027",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-gnu:Gcc|0028",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-gnu:Gcc|0029",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-gnu:Gcc|0030",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-gnu:Gcc|0031",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-gnu:Gcc|0032",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-gnu:Gcc|0033",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-gnu:Gcc|0034",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-gnu:Gcc|0035",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-gnu:Gcc|0037",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "i386-i686-windows-gnu:Gcc|0039",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-gnu:Gcc|0040",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-gnu:Gcc|0041",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-gnu:Gcc|0043",
            .{ .parse = true, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-gnu:Gcc|0045",
            .{ .parse = true, .layout = true, .extra = true, .offset = true },
        },
        .{
            "i386-i686-windows-gnu:Gcc|0046",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-gnu:Gcc|0047",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "i386-i686-windows-gnu:Gcc|0048",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-gnu:Gcc|0049",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "i386-i686-windows-gnu:Gcc|0051",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-gnu:Gcc|0053",
            .{ .parse = true, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-gnu:Gcc|0054",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-gnu:Gcc|0055",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-gnu:Gcc|0056",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-gnu:Gcc|0057",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-gnu:Gcc|0058",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-gnu:Gcc|0059",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "i386-i686-windows-gnu:Gcc|0061",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-gnu:Gcc|0063",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-gnu:Gcc|0064",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-gnu:Gcc|0065",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-gnu:Gcc|0066",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-gnu:Gcc|0067",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "i386-i686-windows-gnu:Gcc|0068",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "i386-i686-windows-gnu:Gcc|0069",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-gnu:Gcc|0071",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "i386-i686-windows-gnu:Gcc|0072",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "i386-i686-windows-gnu:Gcc|0073",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "i386-i686-windows-gnu:Gcc|0074",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-gnu:Gcc|0075",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "i386-i686-windows-gnu:Gcc|0076",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "i386-i686-windows-gnu:Gcc|0077",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-gnu:Gcc|0078",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-gnu:Gcc|0079",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "i386-i686-windows-gnu:Gcc|0080",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "i386-i686-windows-gnu:Gcc|0081",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "i386-i686-windows-gnu:Gcc|0082",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "i386-i686-windows-gnu:Gcc|0083",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "i386-i686-windows-gnu:Gcc|0088",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-msvc:Msvc|0003",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-msvc:Msvc|0005",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-msvc:Msvc|0007",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-msvc:Msvc|0009",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-msvc:Msvc|0011",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-msvc:Msvc|0012",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-msvc:Msvc|0014",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-msvc:Msvc|0020",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-msvc:Msvc|0021",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-msvc:Msvc|0023",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-msvc:Msvc|0024",
            .{ .parse = true, .layout = true, .extra = true, .offset = true },
        },
        .{
            "i386-i686-windows-msvc:Msvc|0025",
            .{ .parse = true, .layout = true, .extra = true, .offset = true },
        },
        .{
            "i386-i686-windows-msvc:Msvc|0026",
            .{ .parse = true, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-msvc:Msvc|0027",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-msvc:Msvc|0028",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "i386-i686-windows-msvc:Msvc|0029",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-msvc:Msvc|0030",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-msvc:Msvc|0031",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "i386-i686-windows-msvc:Msvc|0037",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-msvc:Msvc|0039",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-msvc:Msvc|0042",
            .{ .parse = true, .layout = true, .extra = true, .offset = true },
        },
        .{
            "i386-i686-windows-msvc:Msvc|0043",
            .{ .parse = true, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-msvc:Msvc|0045",
            .{ .parse = true, .layout = true, .extra = true, .offset = true },
        },
        .{
            "i386-i686-windows-msvc:Msvc|0046",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-msvc:Msvc|0047",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-msvc:Msvc|0057",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-msvc:Msvc|0058",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "i386-i686-windows-msvc:Msvc|0063",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-msvc:Msvc|0064",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-msvc:Msvc|0065",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-msvc:Msvc|0066",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-msvc:Msvc|0072",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-msvc:Msvc|0077",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-msvc:Msvc|0080",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "i386-i686-windows-msvc:Msvc|0081",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "i386-i686-windows-msvc:Msvc|0088",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "mips-mips32-linux-gnuabi64:Gcc|0001",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "mips-mips32-linux-gnuabi64:Gcc|0013",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "mips-mips32-linux-gnuabi64:Gcc|0032",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "mips-mips32-linux-gnuabi64:Gcc|0033",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "mips-mips32-linux-gnuabi64:Gcc|0034",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "mips-mips32-linux-gnuabi64:Gcc|0035",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "mips-mips32-linux-gnuabi64:Gcc|0052",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "mips-mips32-linux-gnuabi64:Gcc|0067",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "mips-mips32-linux-gnuabi64:Gcc|0068",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "mips-mips32-linux-gnuabi64:Gcc|0083",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "mips-mips64r6-linux-gnuabi64:Gcc|0001",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "mips-mips64r6-linux-gnuabi64:Gcc|0013",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "mips-mips64r6-linux-gnuabi64:Gcc|0032",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "mips-mips64r6-linux-gnuabi64:Gcc|0033",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "mips-mips64r6-linux-gnuabi64:Gcc|0034",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "mips-mips64r6-linux-gnuabi64:Gcc|0035",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "mips-mips64r6-linux-gnuabi64:Gcc|0052",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "mips-mips64r6-linux-gnuabi64:Gcc|0067",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "mips-mips64r6-linux-gnuabi64:Gcc|0068",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "mips-mips64r6-linux-gnuabi64:Gcc|0083",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "mipsel-mips32-other-eabi:Clang|0052",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "msp430-msp430-other-eabi:Clang|0062",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "s390x-generic-linux-gnu:Gcc|0050",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "sparc-v9-solaris-eabi:Clang|0001",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "sparc-v9-solaris-eabi:Clang|0013",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "sparc-v9-solaris-eabi:Clang|0032",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "sparc-v9-solaris-eabi:Clang|0033",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "sparc-v9-solaris-eabi:Clang|0034",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "sparc-v9-solaris-eabi:Clang|0035",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "sparc-v9-solaris-eabi:Clang|0052",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "sparc-v9-solaris-eabi:Clang|0067",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "sparc-v9-solaris-eabi:Clang|0068",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "sparc-v9-solaris-eabi:Clang|0083",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "thumb-baseline-windows-msvc:Msvc|0003",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "thumb-baseline-windows-msvc:Msvc|0005",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "thumb-baseline-windows-msvc:Msvc|0007",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "thumb-baseline-windows-msvc:Msvc|0009",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "thumb-baseline-windows-msvc:Msvc|0011",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "thumb-baseline-windows-msvc:Msvc|0012",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "thumb-baseline-windows-msvc:Msvc|0014",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
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
            "thumb-baseline-windows-msvc:Msvc|0024",
            .{ .parse = true, .layout = true, .extra = true, .offset = true },
        },
        .{
            "thumb-baseline-windows-msvc:Msvc|0025",
            .{ .parse = true, .layout = true, .extra = true, .offset = true },
        },
        .{
            "thumb-baseline-windows-msvc:Msvc|0026",
            .{ .parse = true, .layout = true, .extra = true, .offset = false },
        },
        .{
            "thumb-baseline-windows-msvc:Msvc|0027",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "thumb-baseline-windows-msvc:Msvc|0028",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "thumb-baseline-windows-msvc:Msvc|0029",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "thumb-baseline-windows-msvc:Msvc|0030",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "thumb-baseline-windows-msvc:Msvc|0031",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
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
            .{ .parse = true, .layout = true, .extra = true, .offset = true },
        },
        .{
            "thumb-baseline-windows-msvc:Msvc|0043",
            .{ .parse = true, .layout = true, .extra = true, .offset = false },
        },
        .{
            "thumb-baseline-windows-msvc:Msvc|0045",
            .{ .parse = true, .layout = true, .extra = true, .offset = true },
        },
        .{
            "thumb-baseline-windows-msvc:Msvc|0046",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "thumb-baseline-windows-msvc:Msvc|0047",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "thumb-baseline-windows-msvc:Msvc|0057",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "thumb-baseline-windows-msvc:Msvc|0058",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "thumb-baseline-windows-msvc:Msvc|0063",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "thumb-baseline-windows-msvc:Msvc|0064",
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
            "thumb-baseline-windows-msvc:Msvc|0077",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "thumb-baseline-windows-msvc:Msvc|0080",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "thumb-baseline-windows-msvc:Msvc|0081",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "thumb-baseline-windows-msvc:Msvc|0088",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-linux-gnux32:Gcc|0001",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "x86_64-x86_64-linux-gnux32:Gcc|0013",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-uefi-msvc:Msvc|0005",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-uefi-msvc:Msvc|0007",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-uefi-msvc:Msvc|0009",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-uefi-msvc:Msvc|0011",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-uefi-msvc:Msvc|0014",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-uefi-msvc:Msvc|0020",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-uefi-msvc:Msvc|0021",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
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
            "x86_64-x86_64-uefi-msvc:Msvc|0027",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-uefi-msvc:Msvc|0028",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "x86_64-x86_64-uefi-msvc:Msvc|0029",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-uefi-msvc:Msvc|0030",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-uefi-msvc:Msvc|0031",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "x86_64-x86_64-uefi-msvc:Msvc|0036",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-uefi-msvc:Msvc|0037",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-uefi-msvc:Msvc|0039",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-uefi-msvc:Msvc|0042",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "x86_64-x86_64-uefi-msvc:Msvc|0046",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-uefi-msvc:Msvc|0047",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-uefi-msvc:Msvc|0057",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-uefi-msvc:Msvc|0058",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "x86_64-x86_64-uefi-msvc:Msvc|0063",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-uefi-msvc:Msvc|0064",
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
            "x86_64-x86_64-uefi-msvc:Msvc|0072",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-uefi-msvc:Msvc|0077",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-uefi-msvc:Msvc|0080",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "x86_64-x86_64-uefi-msvc:Msvc|0081",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-uefi-msvc:Msvc|0088",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-gnu:Gcc|0001",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-gnu:Gcc|0002",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-gnu:Gcc|0003",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-gnu:Gcc|0004",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-gnu:Gcc|0005",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-gnu:Gcc|0006",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "x86_64-x86_64-windows-gnu:Gcc|0007",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-gnu:Gcc|0008",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-gnu:Gcc|0009",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-gnu:Gcc|0010",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-gnu:Gcc|0011",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-gnu:Gcc|0012",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-gnu:Gcc|0013",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-gnu:Gcc|0014",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-gnu:Gcc|0016",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-gnu:Gcc|0019",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-gnu:Gcc|0020",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-gnu:Gcc|0021",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-gnu:Gcc|0023",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-gnu:Gcc|0024",
            .{ .parse = true, .layout = true, .extra = true, .offset = true },
        },
        .{
            "x86_64-x86_64-windows-gnu:Gcc|0027",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-gnu:Gcc|0028",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-gnu:Gcc|0029",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-gnu:Gcc|0030",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-gnu:Gcc|0031",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-gnu:Gcc|0032",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-gnu:Gcc|0033",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-gnu:Gcc|0034",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-gnu:Gcc|0035",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-gnu:Gcc|0037",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "x86_64-x86_64-windows-gnu:Gcc|0039",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-gnu:Gcc|0040",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-gnu:Gcc|0041",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-gnu:Gcc|0043",
            .{ .parse = true, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-gnu:Gcc|0045",
            .{ .parse = true, .layout = true, .extra = true, .offset = true },
        },
        .{
            "x86_64-x86_64-windows-gnu:Gcc|0046",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-gnu:Gcc|0047",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "x86_64-x86_64-windows-gnu:Gcc|0048",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-gnu:Gcc|0049",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "x86_64-x86_64-windows-gnu:Gcc|0051",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-gnu:Gcc|0053",
            .{ .parse = true, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-gnu:Gcc|0054",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-gnu:Gcc|0055",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-gnu:Gcc|0056",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-gnu:Gcc|0057",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-gnu:Gcc|0058",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-gnu:Gcc|0059",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "x86_64-x86_64-windows-gnu:Gcc|0061",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-gnu:Gcc|0063",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-gnu:Gcc|0064",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-gnu:Gcc|0065",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-gnu:Gcc|0066",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-gnu:Gcc|0067",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "x86_64-x86_64-windows-gnu:Gcc|0068",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "x86_64-x86_64-windows-gnu:Gcc|0069",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-gnu:Gcc|0071",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "x86_64-x86_64-windows-gnu:Gcc|0072",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "x86_64-x86_64-windows-gnu:Gcc|0073",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "x86_64-x86_64-windows-gnu:Gcc|0074",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-gnu:Gcc|0075",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "x86_64-x86_64-windows-gnu:Gcc|0076",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "x86_64-x86_64-windows-gnu:Gcc|0077",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-gnu:Gcc|0078",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-gnu:Gcc|0079",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "x86_64-x86_64-windows-gnu:Gcc|0080",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "x86_64-x86_64-windows-gnu:Gcc|0081",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "x86_64-x86_64-windows-gnu:Gcc|0082",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "x86_64-x86_64-windows-gnu:Gcc|0083",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "x86_64-x86_64-windows-gnu:Gcc|0088",
            .{ .parse = false, .layout = false, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-msvc:Msvc|0003",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-msvc:Msvc|0005",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-msvc:Msvc|0007",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-msvc:Msvc|0009",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-msvc:Msvc|0011",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-msvc:Msvc|0012",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-msvc:Msvc|0014",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-msvc:Msvc|0020",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-msvc:Msvc|0021",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-msvc:Msvc|0023",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-msvc:Msvc|0024",
            .{ .parse = true, .layout = true, .extra = true, .offset = true },
        },
        .{
            "x86_64-x86_64-windows-msvc:Msvc|0025",
            .{ .parse = true, .layout = true, .extra = true, .offset = true },
        },
        .{
            "x86_64-x86_64-windows-msvc:Msvc|0026",
            .{ .parse = true, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-msvc:Msvc|0027",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-msvc:Msvc|0028",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "x86_64-x86_64-windows-msvc:Msvc|0029",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-msvc:Msvc|0030",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-msvc:Msvc|0031",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "x86_64-x86_64-windows-msvc:Msvc|0037",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-msvc:Msvc|0039",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-msvc:Msvc|0042",
            .{ .parse = true, .layout = true, .extra = true, .offset = true },
        },
        .{
            "x86_64-x86_64-windows-msvc:Msvc|0043",
            .{ .parse = true, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-msvc:Msvc|0045",
            .{ .parse = true, .layout = true, .extra = true, .offset = true },
        },
        .{
            "x86_64-x86_64-windows-msvc:Msvc|0046",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-msvc:Msvc|0047",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-msvc:Msvc|0057",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-msvc:Msvc|0058",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "x86_64-x86_64-windows-msvc:Msvc|0063",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-msvc:Msvc|0064",
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
        .{
            "x86_64-x86_64-windows-msvc:Msvc|0072",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-msvc:Msvc|0077",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-msvc:Msvc|0080",
            .{ .parse = false, .layout = true, .extra = true, .offset = true },
        },
        .{
            "x86_64-x86_64-windows-msvc:Msvc|0081",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
        .{
            "x86_64-x86_64-windows-msvc:Msvc|0088",
            .{ .parse = false, .layout = true, .extra = true, .offset = false },
        },
    });
};
