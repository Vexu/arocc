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

const non_working_tests = std.ComptimeStringMap(void, .{
    // attributes on field not supported (exclude attributes on types to get working)
    // see issue #300
    .{"0007"}, .{"0008"}, .{"0010"}, .{"0011"}, .{"0014"}, .{"0017"}, .{"0018"}, .{"0025"},
    .{"0026"}, .{"0028"}, .{"0029"}, .{"0044"}, .{"0042"}, .{"0045"}, .{"0046"}, .{"0058"},
    .{"0066"}, .{"0070"}, .{"0072"}, .{"0080"}, .{"0081"}, .{"0084"}, .{"0085"}, .{"0086"},
    // __int128 issue
    .{"0050"},
    // TODO: figure out
    .{"0006"}, .{"0068"},
});

const skip_extra_tests = [_][]const u8{
    // clang-13 works w/ all the extra tests.
    // more work for arocc
    "0076", "0079", "0087", "0088", "0055", "0060", "0062",
};

pub fn main() !void {
    const gpa = general_purpose_allocator.allocator();
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
                if (!non_working_tests.has(entry.name[0..4])) {
                    defer buf.items.len = 0;
                    try buf.writer().print("{s}{c}{s}", .{ args[1], std.fs.path.sep, entry.name });
                    try cases.append(try gpa.dupe(u8, buf.items));
                }
            }
        }
    }

    std.sort.sort([]const u8, cases.items, u8, std.mem.lessThan);

    var progress = std.Progress{};
    const root_node = progress.start("Test", cases.items.len);

    // prepare compiler
    var initial_comp = aro.Compilation.init(gpa);
    defer initial_comp.deinit();

    // apparently we can't use setAstCwd without libc on windows yet
    const win = @import("builtin").os.tag == .windows;
    var tmp_dir = if (!win) std.testing.tmpDir(.{});
    defer if (!win) tmp_dir.cleanup();

    if (!win) try tmp_dir.dir.setAsCwd();

    try initial_comp.addDefaultPragmaHandlers();
    try initial_comp.defineSystemIncludes();
    // iterate over all cases
    var ok_count: u32 = 0;
    var fail_count: u32 = 0;
    var skip_count: u32 = 0;
    // next_test: for (cases.items) |path| {
    for (cases.items) |path| {
        var comp = initial_comp;
        defer {
            // preserve some values
            comp.include_dirs = @TypeOf(comp.include_dirs).init(gpa);
            comp.system_include_dirs = @TypeOf(comp.system_include_dirs).init(gpa);
            comp.pragma_handlers = @TypeOf(comp.pragma_handlers).init(gpa);
            comp.builtin_header_path = null;
            // reset everything else
            comp.deinit();
        }

        const case = std.mem.sliceTo(std.fs.path.basename(path), '.');
        var case_node = root_node.start(case, 0);
        case_node.activate();
        defer case_node.end();
        progress.refresh();

        const file = comp.addSourceFromPath(path) catch |err| {
            fail_count += 1;
            progress.log("could not add source '{s}': {s}\n", .{ path, @errorName(err) });
            continue;
        };

        var macro_buf = std.ArrayList(u8).init(comp.gpa);
        defer macro_buf.deinit();

        {
            var cmd_args = std.ArrayList([]const u8).init(comp.gpa);
            defer cmd_args.deinit();

            var skip_extras = false;
            for (skip_extra_tests) |skip| {
                if (std.mem.count(u8, path, skip) > 0) {
                    skip_extras = true;
                    break;
                }
            }
            // for now we're just going CLANG and Target::X86_64UnknownLinuxGnu
            const mac_writer = macro_buf.writer();
            _ = try mac_writer.write("#define X8664_UNKNOWN_NETBSD\n");
            _ = try mac_writer.write("#define CHECK_OFFSETS\n");
            if (!skip_extras) _ = try mac_writer.write("#define EXTRA_TESTS\n");
            // TODO: only turn these of for the files we know emit these warnings
            comp.diag.options.@"ignored-pragmas" = .off;
            comp.diag.options.@"implicitly-unsigned-literal" = .off;
            var source_files = std.ArrayList(aro.Source).init(std.testing.failing_allocator);
            _ = try aro.parseArgs(&comp, std.io.null_writer, &source_files, mac_writer, cmd_args.items);
        }

        const user_macros = try comp.addSourceFromBuffer("<command line>", macro_buf.items);

        const builtin_macros = try comp.generateBuiltinMacros();

        comp.diag.errors = 0;
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
                    continue;
                }
            }

            fail_count += 1;
            progress.log("could not preprocess file '{s}': {s}\n", .{ path, @errorName(err) });
            continue;
        };
        try pp.tokens.append(gpa, eof);

        comp.renderErrors();
        if (comp.diag.errors != 0) {
            fail_count += 1;
            continue;
        }
        var tree = try aro.Parser.parse(&pp);
        defer tree.deinit();
        tree.dump(std.io.null_writer) catch {};

        if (try Runner.checkExpectedErrors(&pp, &progress, &buf)) |some| {
            if (some) ok_count += 1 else fail_count += 1;
            continue;
        }

        comp.renderErrors();

        if (comp.diag.errors != 0) fail_count += 1 else ok_count += 1;
    }

    root_node.end();
    if (ok_count == cases.items.len and skip_count == 0) {
        print("All {d} tests passed.\n", .{ok_count});
    } else if (fail_count == 0) {
        print("{d} passed; {d} skipped.\n", .{ ok_count, skip_count });
    } else {
        print("{d} passed; {d} failed.\n\n", .{ ok_count, fail_count });
        std.process.exit(1);
    }
}
