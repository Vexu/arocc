const std = @import("std");
const build_options = @import("build_options");
const print = std.debug.print;
const aro = @import("aro");
const Codegen = aro.Codegen;
const Tree = aro.Tree;
const Token = Tree.Token;
const NodeIndex = Tree.NodeIndex;
const AllocatorError = std.mem.Allocator.Error;

var general_purpose_allocator = std.heap.GeneralPurposeAllocator(.{}){};

fn addCommandLineArgs(comp: *aro.Compilation, file: aro.Source) !void {
    if (std.mem.startsWith(u8, file.buf, "//aro-args")) {
        var test_args = std.ArrayList([]const u8).init(comp.gpa);
        defer test_args.deinit();
        const nl = std.mem.indexOfAny(u8, file.buf, "\n\r") orelse file.buf.len;
        var it = std.mem.tokenize(u8, file.buf[0..nl], " ");
        while (it.next()) |some| try test_args.append(some);

        var source_files = std.ArrayList(aro.Source).init(std.testing.failing_allocator);
        _ = try aro.parseArgs(comp, std.io.null_writer, &source_files, std.io.null_writer, test_args.items);
    }
}

fn testOne(allocator: std.mem.Allocator, path: []const u8) !void {
    var comp = aro.Compilation.init(allocator);
    defer comp.deinit();

    try comp.addDefaultPragmaHandlers();
    try comp.defineSystemIncludes();

    const file = try comp.addSourceFromPath(path);
    try addCommandLineArgs(&comp, file);

    const builtin_macros = try comp.generateBuiltinMacros();

    var pp = aro.Preprocessor.init(&comp);
    defer pp.deinit();
    try pp.addBuiltinMacros();

    _ = try pp.preprocess(builtin_macros);

    const eof = pp.preprocess(file) catch |err| {
        if (!std.unicode.utf8ValidateSlice(file.buf)) {
            if (comp.diag.list.items.len > 0 and comp.diag.list.items[comp.diag.list.items.len - 1].tag == .invalid_utf8) {
                return;
            }
        }
        return err;
    };
    try pp.tokens.append(allocator, eof);

    var tree = try aro.Parser.parse(&pp);
    defer tree.deinit();
    tree.dump(std.io.null_writer) catch {};
}

fn testAllAllocationFailures(cases: [][]const u8) !void {
    var progress = std.Progress{};
    const root_node = progress.start("Memory Allocation Test", cases.len);

    for (cases) |case| {
        const case_name = std.mem.sliceTo(std.fs.path.basename(case), '.');
        var case_node = root_node.start(case_name, 0);
        case_node.activate();
        defer case_node.end();
        progress.refresh();

        try std.testing.checkAllAllocationFailures(std.testing.allocator, testOne, .{case});
    }
    root_node.end();
}

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

            defer buf.items.len = 0;
            try buf.writer().print("{s}{c}{s}", .{ args[1], std.fs.path.sep, entry.name });
            try cases.append(try gpa.dupe(u8, buf.items));
        }
    }
    if (build_options.test_all_allocation_failures) {
        return testAllAllocationFailures(cases.items);
    }

    var progress = std.Progress{};
    const root_node = progress.start("Test", cases.items.len);

    // prepare compiler
    var initial_comp = aro.Compilation.init(gpa);
    defer initial_comp.deinit();

    try initial_comp.addDefaultPragmaHandlers();
    try initial_comp.defineSystemIncludes();

    // apparently we can't use setAstCwd without libc on windows yet
    const win = @import("builtin").os.tag == .windows;
    var tmp_dir = if (!win) std.testing.tmpDir(.{});
    defer if (!win) tmp_dir.cleanup();

    if (!win) try tmp_dir.dir.setAsCwd();

    // iterate over all cases
    var ok_count: u32 = 0;
    var fail_count: u32 = 0;
    var skip_count: u32 = 0;
    next_test: for (cases.items) |path| {
        var comp = initial_comp;
        defer {
            // preserve some values
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

        try addCommandLineArgs(&comp, file);

        const builtin_macros = try comp.generateBuiltinMacros();

        comp.diag.errors = 0;
        var pp = aro.Preprocessor.init(&comp);
        defer pp.deinit();
        try pp.addBuiltinMacros();

        _ = try pp.preprocess(builtin_macros);
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

        if (pp.defines.get("TESTS_SKIPPED")) |macro| {
            if (macro.is_func or macro.tokens.len != 1 or macro.tokens[0].id != .integer_literal) {
                fail_count += 1;
                progress.log("invalid TESTS_SKIPPED, definition should contain exactly one integer literal {}\n", .{macro});
                continue;
            }
            const tok_slice = pp.tokSlice(macro.tokens[0]);
            const tests_skipped = try std.fmt.parseInt(u32, tok_slice, 0);
            progress.log("{d} test{s} skipped\n", .{ tests_skipped, if (tests_skipped == 1) @as([]const u8, "") else "s" });
            skip_count += tests_skipped;
        }

        if (comp.only_preprocess) {
            if (try checkExpectedErrors(&pp, &progress, &buf)) |some| {
                if (!some) {
                    fail_count += 1;
                    continue;
                }
            } else {
                comp.renderErrors();
                if (comp.diag.errors != 0) {
                    fail_count += 1;
                    continue;
                }
            }

            const expected_output = blk: {
                const expaned_path = try std.fs.path.join(gpa, &.{ args[1], "expanded", std.fs.path.basename(path) });
                defer gpa.free(expaned_path);

                break :blk try std.fs.cwd().readFileAlloc(gpa, expaned_path, std.math.maxInt(u32));
            };
            defer gpa.free(expected_output);

            var output = std.ArrayList(u8).init(gpa);
            defer output.deinit();

            try pp.prettyPrintTokens(output.writer());

            if (std.testing.expectEqualStrings(expected_output, output.items))
                ok_count += 1
            else |_|
                fail_count += 1;
            continue;
        }

        const expected_types = pp.defines.get("EXPECTED_TYPES");

        var tree = try aro.Parser.parse(&pp);
        defer tree.deinit();
        tree.dump(std.io.null_writer) catch {};

        if (expected_types) |types| {
            const test_fn = for (tree.root_decls) |decl| {
                if (tree.nodes.items(.tag)[@enumToInt(decl)] == .fn_def) break tree.nodes.items(.data)[@enumToInt(decl)];
            } else {
                fail_count += 1;
                progress.log("EXPECTED_TYPES requires a function to be defined\n", .{});
                break;
            };

            var actual = StmtTypeDumper.init(gpa);
            defer actual.deinit(gpa);

            try actual.dump(&tree, test_fn.decl.node, gpa);

            var i: usize = 0;
            for (types.tokens) |str| {
                if (str.id == .macro_ws) continue;
                if (str.id != .string_literal) {
                    fail_count += 1;
                    progress.log("EXPECTED_TYPES tokens must be string literals (found {s})\n", .{@tagName(str.id)});
                    continue :next_test;
                }
                defer i += 1;
                if (i >= actual.types.items.len) continue;

                const expected_type = std.mem.trim(u8, pp.tokSlice(str), "\"");
                const actual_type = actual.types.items[i];
                if (!std.mem.eql(u8, expected_type, actual_type)) {
                    fail_count += 1;
                    progress.log("expected type '{s}' did not match actual type '{s}'\n", .{
                        expected_type,
                        actual_type,
                    });
                    continue :next_test;
                }
            }
            if (i != actual.types.items.len) {
                fail_count += 1;
                progress.log(
                    "EXPECTED_TYPES count differs: expected {d} found {d}\n",
                    .{ i, actual.types.items.len },
                );
                continue;
            }
        }

        if (try checkExpectedErrors(&pp, &progress, &buf)) |some| {
            if (some) ok_count += 1 else fail_count += 1;
            continue;
        }

        comp.renderErrors();

        if (pp.defines.get("EXPECTED_OUTPUT")) |macro| blk: {
            if (comp.diag.errors != 0) break :blk;

            if (macro.is_func) {
                fail_count += 1;
                progress.log("invalid EXPECTED_OUTPUT {}\n", .{macro});
                continue;
            }

            if (macro.tokens.len != 1 or macro.tokens[0].id != .string_literal) {
                fail_count += 1;
                progress.log("EXPECTED_OUTPUT takes exactly one string", .{});
                continue;
            }

            defer buf.items.len = 0;
            // realistically the strings will only contain \" if any escapes so we can use Zig's string parsing
            std.debug.assert((try std.zig.string_literal.parseAppend(&buf, pp.tokSlice(macro.tokens[0]))) == .success);
            const expected_output = buf.items;

            const obj_name = "test_object.o";
            {
                const obj = try Codegen.generateTree(&comp, tree);
                defer obj.deinit();

                const out_file = try std.fs.cwd().createFile(obj_name, .{});
                defer out_file.close();

                try obj.finish(out_file);
            }

            var child = try std.ChildProcess.init(&.{ args[2], "run", "-lc", obj_name }, gpa);
            defer child.deinit();

            child.stdout_behavior = .Pipe;

            try child.spawn();

            const stdout = try child.stdout.?.reader().readAllAlloc(gpa, std.math.maxInt(u16));
            defer gpa.free(stdout);

            switch (try child.wait()) {
                .Exited => |code| if (code != 0) {
                    fail_count += 1;
                    continue;
                },
                else => {
                    fail_count += 1;
                    continue;
                },
            }

            if (!std.mem.eql(u8, expected_output, stdout)) {
                fail_count += 1;
                progress.log(
                    \\
                    \\======= expected output =======
                    \\{s}
                    \\
                    \\=== but output does not contain it ===
                    \\{s}
                    \\
                    \\
                , .{ expected_output, stdout });
                break;
            }

            ok_count += 1;
            continue;
        }

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

// returns true if passed
fn checkExpectedErrors(pp: *aro.Preprocessor, progress: *std.Progress, buf: *std.ArrayList(u8)) !?bool {
    const macro = pp.defines.get("EXPECTED_ERRORS") orelse return null;

    const expected_count = pp.comp.diag.list.items.len;
    var m = MsgWriter.init(pp.comp.gpa);
    defer m.deinit();
    aro.Diagnostics.renderExtra(pp.comp, &m);

    if (macro.is_func) {
        progress.log("invalid EXPECTED_ERRORS {}\n", .{macro});
        return false;
    }

    var count: usize = 0;
    for (macro.tokens) |str| {
        if (str.id == .macro_ws) continue;
        if (str.id != .string_literal) {
            progress.log("EXPECTED_ERRORS tokens must be string literals (found {s})\n", .{@tagName(str.id)});
            return false;
        }
        defer count += 1;
        if (count >= expected_count) continue;

        defer buf.items.len = 0;
        // realistically the strings will only contain \" if any escapes so we can use Zig's string parsing
        std.debug.assert((try std.zig.string_literal.parseAppend(buf, pp.tokSlice(str))) == .success);
        try buf.append('\n');
        const expected_error = buf.items;

        const index = std.mem.indexOf(u8, m.buf.items, expected_error);
        if (index == null) {
            progress.log(
                \\
                \\======= expected to find error =======
                \\{s}
                \\
                \\=== but output does not contain it ===
                \\{s}
                \\
                \\
            , .{ expected_error, m.buf.items });
            return false;
        }
    }

    if (count != expected_count) {
        progress.log(
            \\EXPECTED_ERRORS missing errors, expected {d} found {d},
            \\=== actual output ===
            \\{s}
            \\
            \\
        , .{ count, expected_count, m.buf.items });
        return false;
    }
    return true;
}

const MsgWriter = struct {
    buf: std.ArrayList(u8),

    fn init(gpa: std.mem.Allocator) MsgWriter {
        return .{
            .buf = std.ArrayList(u8).init(gpa),
        };
    }

    fn deinit(m: *MsgWriter) void {
        m.buf.deinit();
    }

    pub fn print(m: *MsgWriter, comptime fmt: []const u8, args: anytype) void {
        m.buf.writer().print(fmt, args) catch {};
    }

    pub fn write(m: *MsgWriter, msg: []const u8) void {
        m.buf.writer().writeAll(msg) catch {};
    }

    pub fn location(m: *MsgWriter, path: []const u8, line: u32, col: u32) void {
        m.print("{s}:{d}:{d}: ", .{ path, line, col });
    }

    pub fn start(m: *MsgWriter, kind: aro.Diagnostics.Kind) void {
        m.print("{s}: ", .{@tagName(kind)});
    }

    pub fn end(m: *MsgWriter, maybe_line: ?[]const u8, col: u32, end_with_splice: bool) void {
        const line = maybe_line orelse {
            m.write("\n");
            return;
        };
        const trailer = if (end_with_splice) "\\ " else "";
        m.print("\n{s}{s}\n", .{ line, trailer });
        m.print("{s: >[1]}^\n", .{ "", col });
    }
};

const StmtTypeDumper = struct {
    types: std.ArrayList([]const u8),

    fn deinit(self: *StmtTypeDumper, allocator: std.mem.Allocator) void {
        for (self.types.items) |t| {
            allocator.free(t);
        }
        self.types.deinit();
    }

    fn init(allocator: std.mem.Allocator) StmtTypeDumper {
        return .{
            .types = std.ArrayList([]const u8).init(allocator),
        };
    }

    fn dumpNode(self: *StmtTypeDumper, tree: *const aro.Tree, node: NodeIndex, m: *MsgWriter) AllocatorError!void {
        if (node == .none) return;
        const tag = tree.nodes.items(.tag)[@enumToInt(node)];
        if (tag == .implicit_return) return;
        const ty = tree.nodes.items(.ty)[@enumToInt(node)];
        ty.dump(m.buf.writer()) catch {};
        try self.types.append(m.buf.toOwnedSlice());
    }

    fn dump(self: *StmtTypeDumper, tree: *const aro.Tree, decl_idx: NodeIndex, allocator: std.mem.Allocator) AllocatorError!void {
        var m = MsgWriter.init(allocator);
        defer m.deinit();

        const idx = @enumToInt(decl_idx);

        const tag = tree.nodes.items(.tag)[idx];
        const data = tree.nodes.items(.data)[idx];

        switch (tag) {
            .compound_stmt_two => {
                try self.dumpNode(tree, data.bin.lhs, &m);
                try self.dumpNode(tree, data.bin.rhs, &m);
            },
            .compound_stmt => {
                for (tree.data[data.range.start..data.range.end]) |stmt| {
                    try self.dumpNode(tree, stmt, &m);
                }
            },
            else => unreachable,
        }
    }
};
