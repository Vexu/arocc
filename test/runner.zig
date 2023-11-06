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

/// Returns only_preprocess and line_markers settings if saw -E
fn addCommandLineArgs(comp: *aro.Compilation, file: aro.Source, macro_buf: anytype) !struct { bool, aro.Preprocessor.Linemarkers, aro.Compilation.SystemDefinesMode } {
    var only_preprocess = false;
    var line_markers: aro.Preprocessor.Linemarkers = .none;
    var system_defines: aro.Compilation.SystemDefinesMode = .include_system_defines;
    if (std.mem.startsWith(u8, file.buf, "//aro-args")) {
        var test_args = std.ArrayList([]const u8).init(comp.gpa);
        defer test_args.deinit();
        const nl = std.mem.indexOfAny(u8, file.buf, "\n\r") orelse file.buf.len;
        var it = std.mem.tokenize(u8, file.buf[0..nl], " ");
        while (it.next()) |some| try test_args.append(some);

        var driver: aro.Driver = .{ .comp = comp };
        defer driver.deinit();
        _ = try driver.parseArgs(std.io.null_writer, macro_buf, test_args.items);
        only_preprocess = driver.only_preprocess;
        system_defines = driver.system_defines;
        if (only_preprocess) {
            if (driver.line_commands) {
                line_markers = if (driver.use_line_directives) .line_directives else .numeric_directives;
            }
        }
    }
    if (std.mem.indexOf(u8, file.buf, "//aro-env")) |idx| {
        const buf = file.buf[idx..];
        const nl = std.mem.indexOfAny(u8, buf, "\n\r") orelse buf.len;
        var it = std.mem.tokenize(u8, buf[0..nl], " ");
        while (it.next()) |some| {
            var parts = std.mem.splitScalar(u8, some, '=');
            const name = parts.next().?;
            const val = parts.next() orelse "";
            inline for (@typeInfo(aro.Compilation.Environment).Struct.fields) |field| {
                if (std.ascii.eqlIgnoreCase(name, field.name)) {
                    @field(comp.environment, field.name) = val;
                }
            }
        }
    }

    return .{ only_preprocess, line_markers, system_defines };
}

fn testOne(allocator: std.mem.Allocator, path: []const u8, test_dir: []const u8) !void {
    var comp = aro.Compilation.init(allocator);
    defer comp.deinit();

    try comp.addDefaultPragmaHandlers();
    try comp.defineSystemIncludes(test_dir);

    const file = try comp.addSourceFromPath(path);
    var macro_buf = std.ArrayList(u8).init(comp.gpa);
    defer macro_buf.deinit();

    _, _, const system_defines = try addCommandLineArgs(&comp, file, macro_buf.writer());
    const user_macros = try comp.addSourceFromBuffer("<command line>", macro_buf.items);

    const builtin_macros = try comp.generateBuiltinMacros(system_defines);

    var pp = aro.Preprocessor.init(&comp);
    defer pp.deinit();
    try pp.addBuiltinMacros();

    if (comp.langopts.ms_extensions) {
        comp.ms_cwd_source_id = file.id;
    }

    _ = try pp.preprocess(builtin_macros);
    _ = try pp.preprocess(user_macros);

    const eof = try pp.preprocess(file);
    try pp.tokens.append(allocator, eof);

    var tree = try aro.Parser.parse(&pp);
    defer tree.deinit();
    tree.dump(false, std.io.null_writer) catch {};
}

fn testAllAllocationFailures(cases: [][]const u8, test_dir: []const u8) !void {
    var progress = std.Progress{};
    const root_node = progress.start("Memory Allocation Test", cases.len);

    for (cases) |case| {
        const case_name = std.mem.sliceTo(std.fs.path.basename(case), '.');
        var case_node = root_node.start(case_name, 0);
        case_node.activate();
        defer case_node.end();
        progress.refresh();

        std.testing.checkAllAllocationFailures(std.testing.allocator, testOne, .{ case, test_dir }) catch |er| switch (er) {
            error.SwallowedOutOfMemoryError => {},
            else => |e| return e,
        };
    }
    root_node.end();
}

pub fn main() !void {
    const mode = @import("builtin").mode;
    if (mode == .ReleaseFast or mode == .ReleaseSmall) {
        return; // Building the test runner in release modes crashes the Zig compiler.
    }
    const gpa = general_purpose_allocator.allocator();
    defer if (general_purpose_allocator.deinit() == .leak) std.process.exit(1);

    var args = try std.process.argsAlloc(gpa);
    defer std.process.argsFree(gpa, args);

    if (args.len != 3) {
        print("expected test case directory and zig executable as only arguments\n", .{});
        return error.InvalidArguments;
    }

    const test_dir = args[1];

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
            if (entry.kind == .directory) continue;
            if (entry.kind != .file) {
                print("skipping non file entry '{s}'\n", .{entry.name});
                continue;
            }

            defer buf.items.len = 0;
            try buf.writer().print("{s}{c}{s}", .{ args[1], std.fs.path.sep, entry.name });
            try cases.append(try gpa.dupe(u8, buf.items));
        }
    }
    if (build_options.test_all_allocation_failures) {
        return testAllAllocationFailures(cases.items, test_dir);
    }

    var progress = std.Progress{};
    const root_node = progress.start("Test", cases.items.len);

    // prepare compiler
    var initial_comp = aro.Compilation.init(gpa);
    defer initial_comp.deinit();

    const cases_include_dir = try std.fs.path.join(gpa, &.{ args[1], "include" });
    defer gpa.free(cases_include_dir);

    try initial_comp.include_dirs.append(cases_include_dir);

    const cases_next_include_dir = try std.fs.path.join(gpa, &.{ args[1], "include", "next" });
    defer gpa.free(cases_next_include_dir);

    try initial_comp.include_dirs.append(cases_next_include_dir);

    try initial_comp.addDefaultPragmaHandlers();
    try initial_comp.defineSystemIncludes(test_dir);

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
            comp.include_dirs = @TypeOf(comp.include_dirs).init(gpa);
            comp.system_include_dirs = @TypeOf(comp.system_include_dirs).init(gpa);
            comp.pragma_handlers = @TypeOf(comp.pragma_handlers).init(gpa);
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

        const only_preprocess, const linemarkers, const system_defines = try addCommandLineArgs(&comp, file, macro_buf.writer());
        const user_macros = try comp.addSourceFromBuffer("<command line>", macro_buf.items);

        const builtin_macros = try comp.generateBuiltinMacros(system_defines);

        comp.diag.errors = 0;
        var pp = aro.Preprocessor.init(&comp);
        defer pp.deinit();
        if (only_preprocess) {
            pp.preserve_whitespace = true;
            pp.linemarkers = linemarkers;
        }
        try pp.addBuiltinMacros();

        if (comp.langopts.ms_extensions) {
            comp.ms_cwd_source_id = file.id;
        }

        _ = try pp.preprocess(builtin_macros);
        _ = try pp.preprocess(user_macros);
        const eof = pp.preprocess(file) catch |err| {
            fail_count += 1;
            progress.log("could not preprocess file '{s}': {s}\n", .{ path, @errorName(err) });
            continue;
        };
        try pp.tokens.append(gpa, eof);

        if (pp.defines.get("TESTS_SKIPPED")) |macro| {
            if (macro.is_func or macro.tokens.len != 1 or macro.tokens[0].id != .pp_num) {
                fail_count += 1;
                progress.log("invalid TESTS_SKIPPED, definition should contain exactly one integer literal {}\n", .{macro});
                continue;
            }
            const tok_slice = pp.tokSlice(macro.tokens[0]);
            const tests_skipped = try std.fmt.parseInt(u32, tok_slice, 0);
            progress.log("{d} test{s} skipped\n", .{ tests_skipped, if (tests_skipped == 1) @as([]const u8, "") else "s" });
            skip_count += tests_skipped;
        }

        if (only_preprocess) {
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
                const expanded_path = try std.fs.path.join(gpa, &.{ args[1], "expanded", std.fs.path.basename(path) });
                defer gpa.free(expanded_path);

                break :blk std.fs.cwd().readFileAlloc(gpa, expanded_path, std.math.maxInt(u32)) catch |err| {
                    fail_count += 1;
                    progress.log("could not open expanded file '{s}': {s}\n", .{ path, @errorName(err) });
                    continue;
                };
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

        var tree = aro.Parser.parse(&pp) catch |err| switch (err) {
            error.FatalError => {
                if (try checkExpectedErrors(&pp, &progress, &buf)) |some| {
                    if (some) ok_count += 1 else fail_count += 1;
                }
                continue;
            },
            else => |e| return e,
        };
        defer tree.deinit();

        const ast_path = try std.fs.path.join(gpa, &.{ args[1], "ast", std.fs.path.basename(path) });
        defer gpa.free(ast_path);
        const maybe_ast = std.fs.cwd().readFileAlloc(gpa, ast_path, std.math.maxInt(u32)) catch null;
        if (maybe_ast) |expected_ast| {
            defer gpa.free(expected_ast);
            var actual_ast = std.ArrayList(u8).init(gpa);
            defer actual_ast.deinit();

            try tree.dump(false, actual_ast.writer());
            std.testing.expectEqualStrings(expected_ast, actual_ast.items) catch {
                fail_count += 1;
                break;
            };
        } else tree.dump(false, std.io.null_writer) catch {};

        if (expected_types) |types| {
            const test_fn = for (tree.root_decls) |decl| {
                if (tree.nodes.items(.tag)[@intFromEnum(decl)] == .fn_def) break tree.nodes.items(.data)[@intFromEnum(decl)];
            } else {
                fail_count += 1;
                progress.log("EXPECTED_TYPES requires a function to be defined\n", .{});
                break;
            };

            var actual = StmtTypeDumper.init(gpa);
            defer actual.deinit(gpa);

            const mapper = try tree.comp.string_interner.getFastTypeMapper(gpa);
            defer mapper.deinit(gpa);
            try actual.dump(&tree, mapper, test_fn.decl.node, gpa);

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
            std.debug.assert((try std.zig.string_literal.parseWrite(buf.writer(), pp.tokSlice(macro.tokens[0]))) == .success);
            const expected_output = buf.items;

            const obj_name = "test_object.o";
            {
                const obj = try Codegen.generateTree(&comp, tree);
                defer obj.deinit();

                const out_file = try std.fs.cwd().createFile(obj_name, .{});
                defer out_file.close();

                try obj.finish(out_file);
            }

            var child = std.ChildProcess.init(&.{ args[2], "run", "-lc", obj_name }, gpa);
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
    aro.Diagnostics.renderMessages(pp.comp, &m);

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
        std.debug.assert((try std.zig.string_literal.parseWrite(buf.writer(), pp.tokSlice(str))) == .success);
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

    fn dumpNode(self: *StmtTypeDumper, tree: *const aro.Tree, mapper: aro.TypeMapper, node: NodeIndex, m: *MsgWriter) AllocatorError!void {
        if (node == .none) return;
        const tag = tree.nodes.items(.tag)[@intFromEnum(node)];
        if (tag == .implicit_return) return;
        const ty = tree.nodes.items(.ty)[@intFromEnum(node)];
        ty.dump(mapper, tree.comp.langopts, m.buf.writer()) catch {};
        const owned = try m.buf.toOwnedSlice();
        errdefer m.buf.allocator.free(owned);
        try self.types.append(owned);
    }

    fn dump(self: *StmtTypeDumper, tree: *const aro.Tree, mapper: aro.TypeMapper, decl_idx: NodeIndex, allocator: std.mem.Allocator) AllocatorError!void {
        var m = MsgWriter.init(allocator);
        defer m.deinit();

        const idx = @intFromEnum(decl_idx);

        const tag = tree.nodes.items(.tag)[idx];
        const data = tree.nodes.items(.data)[idx];

        switch (tag) {
            .compound_stmt_two => {
                try self.dumpNode(tree, mapper, data.bin.lhs, &m);
                try self.dumpNode(tree, mapper, data.bin.rhs, &m);
            },
            .compound_stmt => {
                for (tree.data[data.range.start..data.range.end]) |stmt| {
                    try self.dumpNode(tree, mapper, stmt, &m);
                }
            },
            else => unreachable,
        }
    }
};
