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

// stuff for testing record layout, which is in progress.
// ignored for now.
const non_working_tests = [_][]const u8{
    // need to dig in to.
    "0008", "0010", "0011", "0014", "0017", "0018", "0044", "0045", "0046",
};

const skip_extra_tests = [_][]const u8{
    // all working at the moment
};

const Stats = struct {
    ok_count: u32 = 0,
    fail_count: u32 = 0,
    skip_count: u32 = 0,
    progress: *std.Progress,
    root_node: *std.Progress.Node,
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
        var cases_dir = try std.fs.cwd().openDir(args[1], .{ .iterate = true });
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
    const root_node = progress.start("Test", cases.items.len * 2);

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

        // these flags are all for testing record layout. Which is in another
        // branch. For now, we are just testing the parser. No static asserts
        // are being done.
        var skip_basics = false;
        for (non_working_tests) |skip| {
            if (std.mem.count(u8, path, skip) > 0) {
                skip_basics = true;
                break;
            }
        }

        var extra_checks = true;
        for (skip_extra_tests) |skip| {
            if (std.mem.count(u8, path, skip) > 0) {
                extra_checks = false;
                break;
            }
        }

        const target: ?[]const u8 = if (skip_basics) null else "X8664_UNKNOWN_NETBSD";

        // copy the comp for each run
        var run_comp = comp;
        // gcc/clang fmt
        try singleRun(path, target, true, extra_checks, false, &stats, &run_comp);

        // skip MSVC versions for now.
        // run_comp = comp;
        // // msvc
        // try singleRun(path, null, false, false, true, &stats, &run_comp);
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

fn singleRun(path: []const u8, target: ?[]const u8, check_offsets: bool, extra_checks: bool, do_msvc: bool, state: *Stats, comp: *aro.Compilation) !void {
    defer {
        // preserve some values
        comp.include_dirs = @TypeOf(comp.include_dirs).init(gpa);
        comp.system_include_dirs = @TypeOf(comp.system_include_dirs).init(gpa);
        comp.pragma_handlers = @TypeOf(comp.pragma_handlers).init(gpa);
        // reset everything else
        comp.deinit();
    }

    var case_name = std.ArrayList(u8).init(gpa);
    defer case_name.deinit();

    const exten = if (do_msvc) " - MSVC" else " - GCC";
    try case_name.writer().print("{s}{s}", .{
        std.mem.sliceTo(std.fs.path.basename(path), '.'),
        exten,
    });

    var case_node = state.root_node.start(case_name.items, 0);
    case_node.activate();
    defer case_node.end();
    state.progress.refresh();

    const file = comp.addSourceFromPath(path) catch |err| {
        state.fail_count += 1;
        state.progress.log("could not add source '{s}': {s}\n", .{ path, @errorName(err) });
        return;
    };

    var macro_buf = std.ArrayList(u8).init(comp.gpa);
    defer macro_buf.deinit();

    {
        var cmd_args = std.ArrayList([]const u8).init(comp.gpa);
        defer cmd_args.deinit();

        // for now we're just going CLANG and Target::X86_64UnknownLinuxGnu
        const mac_writer = macro_buf.writer();
        if (target) |d| {
            _ = try mac_writer.print("#define {s}\n", .{d});
        }
        if (check_offsets) {
            _ = try mac_writer.write("#define CHECK_OFFSETS\n");
        }
        if (extra_checks) {
            _ = try mac_writer.write("#define EXTRA_TESTS\n");
        }
        if (do_msvc) {
            _ = try mac_writer.write("#define MSVC\n");
            comp.langopts.enableMSExtensions();
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
    tree.dump(std.io.null_writer) catch {};

    var buf = std.ArrayList(u8).init(gpa);
    defer buf.deinit();

    if (try Runner.checkExpectedErrors(&pp, state.progress, &buf)) |some| {
        if (some) state.ok_count += 1 else state.fail_count += 1;
        return;
    }

    comp.renderErrors();

    if (comp.diag.errors != 0) state.fail_count += 1 else state.ok_count += 1;
}
