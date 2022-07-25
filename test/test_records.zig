const std = @import("std");
const build_options = @import("build_options");

const print = std.debug.print;
const aro = @import("aro");
const Runner = @import("runner.zig");
const Codegen = aro.Codegen;
const Tree = aro.Tree;
const Token = Tree.Token;
const NodeIndex = Tree.NodeIndex;
const AllocatorError = std.mem.Allocator.Error;

var general_purpose_allocator = std.heap.GeneralPurposeAllocator(.{}){};
const gpa = general_purpose_allocator.allocator();

// skip some tests (or parts of tests) for some targets
// currently only targets in this list will be tested
const TestControl = struct {
    target: []const u8,
    non_working_tests: []const []const u8, // parse only. no asserts
    skip_offset_checks: []const []const u8, // don't check bit offsets of records
    skip_extra_tests: []const []const u8, // don't do extra automated size/align tests
};

const working_targets = [_]TestControl{
    .{
        .target = "x86_64-x86_64-netbsd-gnu:Clang", // generic linux clang.
        .non_working_tests = &.{
            "0011", "0014", "0044", "0046",
        },
        .skip_offset_checks = &.{},
        .skip_extra_tests = &.{},
    },
    .{
        .target = "x86_64-x86_64-linux-gnu:Gcc", // generic linux gcc
        .non_working_tests = &.{
            "0011", "0014", "0044", "0046",
        },
        .skip_offset_checks = &.{},
        .skip_extra_tests = &.{},
    },
};
const Stats = struct {
    ok_count: u32 = 0,
    fail_count: u32 = 0,
    skip_count: u32 = 0,
    progress: *std.Progress,
    root_node: *std.Progress.Node,
};

const Settings = struct {
    check_offsets: bool = true,
    extra_checks: bool = true,
    ifdef: ?[]const u8 = null,
    target: []const u8 = "",
};

pub fn main() !void {
    defer if (general_purpose_allocator.deinit()) std.process.exit(1);

    var args = try std.process.argsAlloc(gpa);
    defer std.process.argsFree(gpa, args);

    if (args.len != 3) {
        print("expected test case directory and zig executable as only arguments\n", .{});
        return error.InvalidArguments;
    }

    var buf = std.ArrayList(u8).init(gpa);
    var cases = std.ArrayList([]const u8).init(gpa);
    defer {
        for (cases.items) |path| gpa.free(path);
        cases.deinit();
        buf.deinit();
    }

    // collect all cases
    {
        var cases_dir = try std.fs.cwd().openIterableDir(args[1], .{});
        defer cases_dir.close();

        var it = cases_dir.iterate();
        while (try it.next()) |entry| {
            if (entry.kind == .Directory) continue;
            if (entry.kind != .File) {
                print("skipping non file entry '{s}'\n", .{entry.name});
                continue;
            }

            if (std.mem.count(u8, entry.name, "_test.c") == 1) {
                defer buf.items.len = 0;
                try buf.writer().print("{s}{c}{s}", .{ args[1], std.fs.path.sep, entry.name });
                try cases.append(try gpa.dupe(u8, buf.items));
            }
        }
    }

    std.sort.sort([]const u8, cases.items, u8, std.mem.lessThan);

    var progress = std.Progress{};
    // * 2 for MSVC version
    const root_node = progress.start("Test", cases.items.len * working_targets.len);

    // prepare compiler
    var comp = aro.Compilation.init(gpa);
    defer comp.deinit();

    // apparently we can't use setAstCwd without libc on windows yet
    const win = @import("builtin").os.tag == .windows;
    var tmp_dir = if (!win) std.testing.tmpDir(.{});
    defer if (!win) tmp_dir.cleanup();

    if (!win) try tmp_dir.dir.setAsCwd();

    try comp.addDefaultPragmaHandlers();
    try comp.defineSystemIncludes();

    var stats = Stats{
        .progress = &progress,
        .root_node = root_node,
    };

    // iterate over all cases
    for (cases.items) |path| {
        const source = try std.fs.cwd().readFileAlloc(gpa, path, 1024 * 1024 * 16); // the test files are at most 2M.
        defer gpa.free(source);

        // for each ifdef, a list of targets
        var code_targets = std.StringHashMap(std.StringHashMap(void)).init(gpa);
        defer {
            var iter = code_targets.iterator();
            while (iter.next()) |ent| {
                ent.value_ptr.deinit();
            }
            code_targets.deinit();
        }
        try parseTargetsFromCode(&code_targets, source);
        for (working_targets) |working| {
            var settings: Settings = .{};

            settings.ifdef = findTarget(code_targets, working.target);
            if (settings.ifdef == null) continue;
            settings.target = working.target;

            // these flags are all for testing record layout. Which is in another
            // branch. For now, we are just testing the parser. No static asserts
            for (working.non_working_tests) |skip| {
                if (std.mem.count(u8, path, skip) > 0) {
                    settings.ifdef = null;
                    break;
                }
            }
            for (working.skip_offset_checks) |skip| {
                if (std.mem.count(u8, path, skip) > 0) {
                    settings.check_offsets = false;
                }
            }

            for (working.skip_extra_tests) |skip| {
                if (std.mem.count(u8, path, skip) > 0) {
                    settings.extra_checks = false;
                    break;
                }
            }

            // copy the comp for each run
            var run_comp = comp;
            // gcc/clang fmt
            try singleRun(path, source, settings, &stats, &run_comp);
        }
    }

    root_node.end();
    if (stats.ok_count == cases.items.len and stats.skip_count == 0) {
        print("All {d} tests passed.\n", .{stats.ok_count});
    } else if (stats.fail_count == 0) {
        print("{d} passed; {d} skipped.\n", .{ stats.ok_count, stats.skip_count });
    } else {
        print("{d} passed; {d} failed.\n\n", .{ stats.ok_count, stats.fail_count });
        std.process.exit(1);
    }
}

fn singleRun(path: []const u8, source: []const u8, settings: Settings, state: *Stats, comp: *aro.Compilation) !void {
    defer {
        // preserve some values
        comp.include_dirs = @TypeOf(comp.include_dirs).init(gpa);
        comp.system_include_dirs = @TypeOf(comp.system_include_dirs).init(gpa);
        comp.pragma_handlers = @TypeOf(comp.pragma_handlers).init(gpa);
        // reset everything else
        comp.deinit();
    }
    _ = source;

    var case_name = std.ArrayList(u8).init(gpa);
    defer case_name.deinit();

    try case_name.writer().print("{s} | {s} | {s}", .{
        std.mem.sliceTo(std.fs.path.basename(path), '.'),
        settings.target,
        settings.ifdef,
    });

    var case_node = state.root_node.start(case_name.items, 0);
    case_node.activate();
    defer case_node.end();
    state.progress.refresh();

    const file = comp.addSourceFromPath(path) catch |err| {
        // const file = comp.addSourceFromBuffer(path, source) catch |err| {
        state.fail_count += 1;
        state.progress.log("could not add source '{s}': {s}\n", .{ path, @errorName(err) });
        return;
    };

    var macro_buf = std.ArrayList(u8).init(comp.gpa);
    defer macro_buf.deinit();

    try setTarget(comp, settings.target);

    {
        var cmd_args = std.ArrayList([]const u8).init(comp.gpa);
        defer cmd_args.deinit();

        // for now we're just going CLANG and Target::X86_64UnknownLinuxGnu
        const mac_writer = macro_buf.writer();
        if (settings.ifdef) |d| {
            _ = try mac_writer.print("#define {s}\n", .{d});
        } else {
            // we're just testing the parser.
            // count this as a skip.
            state.skip_count += 1;
        }
        if (settings.check_offsets) {
            _ = try mac_writer.write("#define CHECK_OFFSETS\n");
        }
        if (settings.extra_checks) {
            _ = try mac_writer.write("#define EXTRA_TESTS\n");
        }
        // TODO: only turn these of for the files we know emit these warnings
        comp.diag.options.@"ignored-pragmas" = .off;
        comp.diag.options.@"implicitly-unsigned-literal" = .off;
        var source_files = std.ArrayList(aro.Source).init(std.testing.failing_allocator);
        _ = try aro.parseArgs(comp, std.io.null_writer, &source_files, mac_writer, cmd_args.items);
    }

    const user_macros = try comp.addSourceFromBuffer("<command line>", macro_buf.items);

    const builtin_macros = try comp.generateBuiltinMacros();

    comp.diag.errors = 0;
    var pp = aro.Preprocessor.init(comp);
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
    try pp.tokens.append(gpa, eof);

    comp.renderErrors();
    if (comp.diag.errors != 0) {
        state.fail_count += 1;
        return;
    }
    var tree = try aro.Parser.parse(&pp);
    defer tree.deinit();
    tree.dump(false, std.io.null_writer) catch {};

    var buf = std.ArrayList(u8).init(gpa);
    defer buf.deinit();

    if (try Runner.checkExpectedErrors(&pp, state.progress, &buf)) |some| {
        if (some) state.ok_count += 1 else state.fail_count += 1;
        return;
    }

    comp.renderErrors();

    if (comp.diag.errors != 0) state.fail_count += 1 else state.ok_count += 1;
}

fn findTarget(map: std.StringHashMap(std.StringHashMap(void)), find: []const u8) ?[]const u8 {
    var iter = map.iterator();
    while (iter.next()) |ent| {
        if (ent.value_ptr.contains(find)) {
            return ent.key_ptr.*;
        }
    }
    return null;
}
fn parseTargetsFromCode(maps: *std.StringHashMap(std.StringHashMap(void)), source: []const u8) !void {
    var lines = std.mem.tokenize(u8, source, "\n");
    while (lines.next()) |line| {
        if (std.mem.count(u8, line, "// MAPPING|") <= 0) continue;
        std.debug.assert(std.mem.count(u8, line, "|") > 1);
        var parts = std.mem.tokenize(u8, line, "|");
        _ = parts.next(); // skip the MAPPING bit
        const ifdef = parts.next().?; // the ifset to set for this chunk.
        var t_set = std.StringHashMap(void).init(gpa);
        while (parts.next()) |target| {
            if (std.mem.startsWith(u8, target, "END")) break;
            var ent = try t_set.getOrPut(target);
            ent.value_ptr.* = .{};
        }
        try maps.put(ifdef, t_set);
    }
}
fn setTarget(comp: *aro.Compilation, target: []const u8) !void {
    const split_idex = std.mem.indexOf(u8, target, ":").?;

    var iter = std.mem.tokenize(u8, target[0..split_idex], "-");
    comp.target.cpu.arch = std.meta.stringToEnum(std.Target.Cpu.Arch, iter.next().?).?;
    comp.target.cpu.model = try std.Target.Cpu.Arch.parseCpuModel(comp.target.cpu.arch, iter.next().?);
    const tag = std.meta.stringToEnum(std.Target.Os.Tag, iter.next().?).?;
    comp.target.os = std.Target.Os.Tag.defaultVersionRange(tag, comp.target.cpu.arch);
    comp.target.abi = std.meta.stringToEnum(std.Target.Abi, iter.next().?).?;

    comp.langopts.emulate = comp.systemCompiler();
    const c_name = target[split_idex + 1 ..];
    const m_name = @tagName(comp.langopts.emulate);
    std.debug.assert(std.ascii.eqlIgnoreCase(m_name, c_name));
}
