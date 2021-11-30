const std = @import("std");
const print = std.debug.print;
const aro = @import("aro");
const Codegen = aro.Codegen;
const Tree = aro.Tree;
const Token = Tree.Token;
const NodeIndex = Tree.NodeIndex;
const AllocatorError = std.mem.Allocator.Error;

const predefined_macros =
    \\#define EXPECT(x) _Static_assert(x, "unexpected result")
;

var general_purpose_allocator = std.heap.GeneralPurposeAllocator(.{}){};

pub fn main() !void {
    const gpa = &general_purpose_allocator.allocator;
    defer _ = general_purpose_allocator.deinit();

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

    var progress = std.Progress{};
    const root_node = try progress.start("Test", cases.items.len);

    // prepare compiler
    var comp = aro.Compilation.init(gpa);
    defer comp.deinit();

    try comp.addDefaultPragmaHandlers();

    try comp.defineSystemIncludes();

    const test_runner_macros = blk: {
        const duped_path = try gpa.dupe(u8, "<test_runner>");
        errdefer comp.gpa.free(duped_path);

        const contents = try gpa.dupe(u8, predefined_macros);
        errdefer comp.gpa.free(contents);

        const source = aro.Source{
            .id = @intToEnum(aro.Source.Id, comp.sources.count() + 2),
            .path = duped_path,
            .buf = contents,
        };
        try comp.sources.put(duped_path, source);
        break :blk source;
    };

    // apparently we can't use setAstCwd without libc on windows yet
    const win = @import("builtin").os.tag == .windows;
    var tmp_dir = if (!win) std.testing.tmpDir(.{});
    defer if (!win) tmp_dir.cleanup();

    if (!win) try tmp_dir.dir.setAsCwd();

    // iterate over all cases
    var ok_count: u32 = 0;
    var fail_count: u32 = 0;
    var skip_count: u32 = 0;
    const initial_options = comp.diag.options;
    next_test: for (cases.items) |path| {
        comp.langopts.standard = .default;
        comp.diag.options = initial_options;
        comp.only_preprocess = false;
        const file = comp.addSource(path) catch |err| {
            fail_count += 1;
            progress.log("could not add source '{s}': {s}\n", .{ path, @errorName(err) });
            continue;
        };
        defer {
            _ = comp.sources.swapRemove(file.path);
            gpa.free(file.path);
            gpa.free(file.buf);
        }

        if (std.mem.startsWith(u8, file.buf, "//std=")) {
            const suffix = file.buf["//std=".len..];
            var it = std.mem.tokenize(u8, suffix, " \r\n");
            if (it.next()) |standard| {
                try comp.langopts.setStandard(standard);
            }
        } else if (std.mem.startsWith(u8, file.buf, "//test preprocess")) {
            comp.only_preprocess = true;
        }

        const builtin_macros = try comp.generateBuiltinMacros();
        defer {
            _ = comp.sources.swapRemove(builtin_macros.path);
            gpa.free(builtin_macros.path);
            gpa.free(builtin_macros.buf);
        }

        const case = std.mem.sliceTo(std.fs.path.basename(path), '.');
        var case_node = root_node.start(case, 0);
        case_node.activate();
        defer case_node.end();
        progress.refresh();

        comp.diag.errors = 0;
        var pp = aro.Preprocessor.init(&comp);
        defer pp.deinit();
        try pp.addBuiltinMacros();

        try pp.preprocess(builtin_macros);
        try pp.preprocess(test_runner_macros);
        pp.preprocess(file) catch |err| {
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
        try pp.tokens.append(gpa, .{
            .id = .eof,
            .loc = .{ .id = file.id, .byte_offset = @intCast(u32, file.buf.len) },
        });

        if (std.mem.startsWith(u8, file.buf, "//test preprocess")) {
            comp.renderErrors();

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

        if (pp.defines.get("TESTS_SKIPPED")) |macro| {
            if (macro.is_func or macro.tokens.len != 1 or macro.tokens[0].id != .integer_literal) {
                fail_count += 1;
                progress.log("invalid TESTS_SKIPPED, definition should contain exactly one integer literal {}\n", .{macro});
                continue;
            }
            const tok_slice = pp.tokSliceSafe(macro.tokens[0]);
            const tests_skipped = try std.fmt.parseInt(u32, tok_slice, 0);
            progress.log("{d} test{s} skipped\n", .{ tests_skipped, if (tests_skipped == 1) @as([]const u8, "") else "s" });
            skip_count += tests_skipped;
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
                if (str.id == .whitespace) continue;
                if (str.id != .string_literal) {
                    fail_count += 1;
                    progress.log("EXPECTED_TYPES tokens must be string literals (found {s})\n", .{@tagName(str.id)});
                    continue :next_test;
                }
                defer i += 1;
                if (i >= actual.types.items.len) continue;

                const expected_type = std.mem.trim(u8, pp.tokSliceSafe(str), "\"");
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

        if (pp.defines.get("EXPECTED_ERRORS")) |macro| {
            const expected_count = comp.diag.list.items.len;
            var m = MsgWriter.init(gpa);
            defer m.deinit();
            aro.Diagnostics.renderExtra(&comp, &m);

            if (macro.is_func) {
                fail_count += 1;
                progress.log("invalid EXPECTED_ERRORS {}\n", .{macro});
                continue;
            }

            var count: usize = 0;
            for (macro.tokens) |str| {
                if (str.id == .whitespace) continue;
                if (str.id != .string_literal) {
                    fail_count += 1;
                    progress.log("EXPECTED_ERRORS tokens must be string literals (found {s})\n", .{@tagName(str.id)});
                    continue :next_test;
                }
                defer count += 1;
                if (count >= expected_count) continue;

                defer buf.items.len = 0;
                // realistically the strings will only contain \" if any escapes so we can use Zig's string parsing
                std.debug.assert((try std.zig.string_literal.parseAppend(&buf, pp.tokSliceSafe(str))) == .success);
                const expected_error = buf.items;

                const index = std.mem.indexOf(u8, m.buf.items, expected_error);
                if (index == null) {
                    fail_count += 1;
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
                    continue :next_test;
                }
            }

            if (count != expected_count) {
                fail_count += 1;
                progress.log(
                    \\EXPECTED_ERRORS missing errors, expected {d} found {d},
                    \\=== actual output ===
                    \\{s}
                    \\
                    \\
                , .{ count, expected_count, m.buf.items });
                continue;
            }
            ok_count += 1;
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
            std.debug.assert((try std.zig.string_literal.parseAppend(&buf, pp.tokSliceSafe(macro.tokens[0]))) == .success);
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

const MsgWriter = struct {
    buf: std.ArrayList(u8),

    fn init(gpa: *std.mem.Allocator) MsgWriter {
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

    pub fn location(m: *MsgWriter, path: []const u8, lcs: aro.Source.LCS) void {
        m.print("{s}:{d}:{d}: ", .{ path, lcs.line, lcs.col });
    }

    pub fn start(m: *MsgWriter, kind: aro.Diagnostics.Kind) void {
        m.print("{s}: ", .{@tagName(kind)});
    }

    pub fn end(m: *MsgWriter, lcs: ?aro.Source.LCS) void {
        if (lcs == null) {
            m.write("\n");
            return;
        }
        m.print("\n{s}\n", .{lcs.?.str});
        m.print("{s: >[1]}^\n", .{ "", lcs.?.col - 1 });
    }
};

const StmtTypeDumper = struct {
    types: std.ArrayList([]const u8),

    fn deinit(self: *StmtTypeDumper, allocator: *std.mem.Allocator) void {
        for (self.types.items) |t| {
            allocator.free(t);
        }
        self.types.deinit();
    }

    fn init(allocator: *std.mem.Allocator) StmtTypeDumper {
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

    fn dump(self: *StmtTypeDumper, tree: *const aro.Tree, decl_idx: NodeIndex, allocator: *std.mem.Allocator) AllocatorError!void {
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
