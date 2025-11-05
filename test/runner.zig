const std = @import("std");
const build_options = @import("build_options");
const print = std.debug.print;
const aro = @import("aro");
const CodeGen = aro.CodeGen;
const Tree = aro.Tree;
const Token = Tree.Token;
const Node = Tree.Node;
const AllocatorError = std.mem.Allocator.Error;

var debug_allocator: std.heap.DebugAllocator(.{
    .stack_trace_frames = if (build_options.debug_allocations and std.debug.sys_can_stack_trace) 10 else 0,
    .resize_stack_traces = build_options.debug_allocations,
    // A unique value so that when a default-constructed
    // GeneralPurposeAllocator is incorrectly passed to testing allocator, or
    // vice versa, panic occurs.
    .canary = @truncate(0xc647026dc6875134),
}) = .{};

const AddCommandLineArgsResult = struct {
    bool,
    aro.Preprocessor.Linemarkers,
    aro.Compilation.SystemDefinesMode,
    aro.Preprocessor.DumpMode,
    std.ArrayList(aro.Source),
};

/// Returns only_preprocess and line_markers settings if saw -E
fn addCommandLineArgs(comp: *aro.Compilation, file: aro.Source, macro_buf: *std.ArrayListUnmanaged(u8)) !AddCommandLineArgsResult {
    var implicit_includes: std.ArrayList(aro.Source) = .empty;
    var only_preprocess = false;
    var line_markers: aro.Preprocessor.Linemarkers = .none;
    var system_defines: aro.Compilation.SystemDefinesMode = .include_system_defines;
    var dump_mode: aro.Preprocessor.DumpMode = .result_only;
    if (std.mem.startsWith(u8, file.buf, "//aro-args")) {
        var test_args: std.ArrayList([]const u8) = .empty;
        defer test_args.deinit(comp.gpa);
        const nl = std.mem.indexOfAny(u8, file.buf, "\n\r") orelse file.buf.len;
        var it = std.mem.tokenizeScalar(u8, file.buf[0..nl], ' ');
        while (it.next()) |some| try test_args.append(comp.gpa, some);

        var driver: aro.Driver = .{ .comp = comp, .diagnostics = comp.diagnostics };
        defer driver.deinit();

        var discard_buf: [256]u8 = undefined;
        var discarding: std.Io.Writer.Discarding = .init(&discard_buf);
        _ = try driver.parseArgs(&discarding.writer, macro_buf, test_args.items);
        only_preprocess = driver.only_preprocess;
        system_defines = driver.system_defines;
        dump_mode = driver.debug_dump_letters.getPreprocessorDumpMode();
        if (only_preprocess) {
            if (driver.line_commands) {
                line_markers = if (driver.use_line_directives) .line_directives else .numeric_directives;
            }
        }
        const slice = try driver.implicit_includes.toOwnedSlice(comp.gpa);
        implicit_includes = .fromOwnedSlice(slice);
    }
    if (std.mem.indexOf(u8, file.buf, "//aro-env")) |idx| {
        const buf = file.buf[idx..];
        const nl = std.mem.indexOfAny(u8, buf, "\n\r") orelse buf.len;
        var it = std.mem.tokenizeScalar(u8, buf[0..nl], ' ');
        while (it.next()) |some| {
            var parts = std.mem.splitScalar(u8, some, '=');
            const name = parts.next().?;
            const val = parts.next() orelse "";
            inline for (@typeInfo(aro.Compilation.Environment).@"struct".fields) |field| {
                if (std.ascii.eqlIgnoreCase(name, field.name)) {
                    @field(comp.environment, field.name) = val;
                }
            }
        }
    }

    return .{ only_preprocess, line_markers, system_defines, dump_mode, implicit_includes };
}

fn testOne(gpa: std.mem.Allocator, path: []const u8, test_dir: []const u8) !void {
    var arena: std.heap.ArenaAllocator = .init(gpa);
    defer arena.deinit();

    var comp = aro.Compilation.init(gpa, arena.allocator(), std.fs.cwd());
    defer comp.deinit();

    try comp.addDefaultPragmaHandlers();
    try comp.addBuiltinIncludeDir(test_dir, null);

    const file = try comp.addSourceFromPath(path);
    var macro_buf = std.ArrayList(u8).init(comp.gpa);
    defer macro_buf.deinit();

    _, _, const system_defines, _ = try addCommandLineArgs(&comp, file, macro_buf.writer());
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
    try pp.addToken(eof);

    var tree = try aro.Parser.parse(&pp);
    defer tree.deinit();
    tree.dump(false, std.Io.null_writer) catch {};
}

fn testAllAllocationFailures(cases: [][]const u8, test_dir: []const u8) !void {
    const root_node = std.Progress.start(.{
        .disable_printing = false,
        .root_name = "Memory Allocation Test",
        .estimated_total_items = cases.len,
    });

    for (cases) |case| {
        const case_name = std.mem.sliceTo(std.fs.path.basename(case), '.');
        var case_node = root_node.start(case_name, 0);
        defer case_node.end();

        std.testing.checkAllAllocationFailures(std.testing.allocator, testOne, .{ case, test_dir }) catch |er| switch (er) {
            error.SwallowedOutOfMemoryError => {},
            else => |e| return e,
        };
    }
    root_node.end();
}

pub fn main() !void {
    const gpa = debug_allocator.allocator();
    defer if (debug_allocator.deinit() == .leak) std.process.exit(1);

    var arena_state: std.heap.ArenaAllocator = .init(gpa);
    defer arena_state.deinit();
    const arena = arena_state.allocator();

    const args = try std.process.argsAlloc(arena);

    if (args.len != 3) {
        print("expected test case directory and zig executable as only arguments\n", .{});
        return error.InvalidArguments;
    }

    const test_dir = args[1];

    var buf: std.ArrayListUnmanaged(u8) = .empty;
    var cases: std.ArrayList([]const u8) = .empty;
    defer {
        cases.deinit(gpa);
        buf.deinit(gpa);
    }

    // collect all cases
    {
        var cases_dir = try std.fs.cwd().openDir(args[1], .{ .iterate = true });
        defer cases_dir.close();

        var it = cases_dir.iterate();
        while (try it.next()) |entry| {
            if (entry.kind == .directory) continue;
            if (entry.kind != .file) {
                print("skipping non file entry '{s}'\n", .{entry.name});
                continue;
            }
            try cases.append(gpa, try std.fmt.allocPrint(arena, "{s}{c}{s}", .{ args[1], std.fs.path.sep, entry.name }));
        }
    }
    if (build_options.test_all_allocation_failures) {
        return testAllAllocationFailures(cases.items, test_dir);
    }

    const root_node = std.Progress.start(.{
        .disable_printing = false,
        .root_name = "Test",
        .estimated_total_items = cases.items.len,
    });

    var diag_buf: std.Io.Writer.Allocating = .init(gpa);
    defer diag_buf.deinit();

    var diagnostics: aro.Diagnostics = .{
        .output = .{ .to_writer = .{
            .writer = &diag_buf.writer,
            .color = .no_color,
        } },
    };
    defer diagnostics.deinit();

    // prepare compiler
    var initial_comp = aro.Compilation.init(gpa, arena, std.testing.io, &diagnostics, std.fs.cwd());
    defer initial_comp.deinit();

    // Intentional reduntant and mixed-separator path for Windows-specific tests
    const cases_mixed_include_dir = try std.fs.path.join(arena, &.{ args[1], "include//mixed" });
    try initial_comp.include_dirs.append(gpa, cases_mixed_include_dir);

    const cases_include_dir = try std.fs.path.join(arena, &.{ args[1], "include" });
    try initial_comp.include_dirs.append(gpa, cases_include_dir);
    try initial_comp.embed_dirs.append(gpa, cases_include_dir);

    const cases_next_include_dir = try std.fs.path.join(arena, &.{ args[1], "include", "next" });
    try initial_comp.include_dirs.append(gpa, cases_next_include_dir);
    try initial_comp.embed_dirs.append(gpa, cases_next_include_dir);

    const cases_system_include_dir = try std.fs.path.join(arena, &.{ args[1], "include_system" });
    try initial_comp.system_include_dirs.append(gpa, cases_system_include_dir);

    const cases_system_next_include_dir = try std.fs.path.join(arena, &.{ args[1], "include_system", "next" });
    try initial_comp.system_include_dirs.append(gpa, cases_system_next_include_dir);

    const cases_frameworks_dir = try std.fs.path.join(arena, &.{ args[1], "frameworks" });
    try initial_comp.framework_dirs.append(gpa, cases_frameworks_dir);

    const cases_iquote_dir = try std.fs.path.join(arena, &.{ args[1], "include", "iquote" });
    try initial_comp.iquote_include_dirs.append(gpa, cases_iquote_dir);

    try initial_comp.addDefaultPragmaHandlers();
    try initial_comp.addBuiltinIncludeDir(test_dir, null);

    // iterate over all cases
    var ok_count: u32 = 0;
    var fail_count: u32 = 0;
    var skip_count: u32 = 0;
    next_test: for (cases.items) |path| {
        diag_buf.shrinkRetainingCapacity(0);
        diagnostics = .{
            .output = .{ .to_writer = .{
                .writer = &diag_buf.writer,
                .color = .no_color,
            } },
        };

        var comp = initial_comp;
        defer {
            // preserve some values
            comp.include_dirs = .{};
            comp.iquote_include_dirs = .{};
            comp.system_include_dirs = .{};
            comp.after_include_dirs = .{};
            comp.framework_dirs = .{};
            comp.system_framework_dirs = .{};
            comp.embed_dirs = .{};
            comp.pragma_handlers = .{};
            comp.environment = .{};
            // reset everything else
            comp.deinit();
        }

        const case = std.mem.sliceTo(std.fs.path.basename(path), '.');
        var case_node = root_node.start(case, 0);
        defer case_node.end();

        const file = comp.addSourceFromPath(path) catch |err| {
            fail_count += 1;
            std.debug.print("could not add source '{s}': {s}\n", .{ path, @errorName(err) });
            continue;
        };

        var macro_buf: std.ArrayListUnmanaged(u8) = .empty;
        defer macro_buf.deinit(comp.gpa);

        const only_preprocess, const linemarkers, const system_defines, const dump_mode, var implicit_includes = try addCommandLineArgs(&comp, file, &macro_buf);
        defer implicit_includes.deinit(comp.gpa);
        const user_macros = try comp.addSourceFromBuffer("<command line>", macro_buf.items);

        const builtin_macros = try comp.generateBuiltinMacros(system_defines);

        var pp = try aro.Preprocessor.initDefault(&comp);
        defer pp.deinit();
        if (only_preprocess) {
            pp.preserve_whitespace = true;
            pp.linemarkers = linemarkers;
            if (dump_mode != .result_only) {
                pp.store_macro_tokens = true;
            }
        }

        if (comp.langopts.ms_extensions) {
            comp.ms_cwd_source_id = file.id;
        }

        _ = try pp.preprocess(builtin_macros);
        _ = try pp.preprocess(user_macros);
        pp.include_depth = 1;
        for (implicit_includes.items) |header| {
            _ = try pp.preprocess(header);
            std.debug.assert(pp.include_depth == 1);
        }
        pp.include_depth = 0;
        const eof = pp.preprocess(file) catch |err| {
            fail_count += 1;
            std.debug.print("could not preprocess file '{s}': {s}\n", .{ path, @errorName(err) });
            continue;
        };
        try pp.addToken(eof);

        if (pp.defines.get("TESTS_SKIPPED")) |macro| {
            if (macro.is_func or macro.tokens.len != 1 or macro.tokens[0].id != .pp_num) {
                fail_count += 1;
                std.debug.print("{s}:\n", .{case});
                std.debug.print("invalid TESTS_SKIPPED, definition should contain exactly one integer literal {}\n", .{macro});
                continue;
            }
            const tok_slice = pp.tokSlice(macro.tokens[0]);
            const tests_skipped = try std.fmt.parseInt(u32, tok_slice, 0);
            std.debug.print("{s}: {d} test{s} skipped\n", .{ case, tests_skipped, if (tests_skipped == 1) @as([]const u8, "") else "s" });
            skip_count += tests_skipped;
        }

        if (only_preprocess) {
            if (try checkExpectedErrors(&pp, &buf, diag_buf.written())) |some| {
                if (!some) {
                    std.debug.print("in case {s}\n", .{case});
                    fail_count += 1;
                    continue;
                }
            } else {
                var stderr_buf: [4096]u8 = undefined;
                var stderr = std.fs.File.stderr().writer(&stderr_buf);
                try stderr.interface.writeAll(diag_buf.written());
                try stderr.interface.flush();

                if (comp.diagnostics.errors != 0) {
                    std.debug.print("in case {s}\n", .{case});
                    fail_count += 1;
                    continue;
                }
            }

            const expected_output = blk: {
                const expanded_path = try std.fs.path.join(gpa, &.{ args[1], "expanded", std.fs.path.basename(path) });
                defer gpa.free(expanded_path);

                break :blk std.fs.cwd().readFileAlloc(expanded_path, gpa, .unlimited) catch |err| {
                    fail_count += 1;
                    std.debug.print("could not open expanded file '{s}': {s}\n", .{ path, @errorName(err) });
                    continue;
                };
            };
            defer gpa.free(expected_output);

            var output: std.Io.Writer.Allocating = .init(gpa);
            defer output.deinit();

            try pp.prettyPrintTokens(&output.writer, dump_mode);

            if (pp.defines.contains("CHECK_PARTIAL_MATCH")) {
                const index = std.mem.indexOf(u8, output.written(), expected_output);
                if (index != null) {
                    ok_count += 1;
                } else {
                    fail_count += 1;
                    std.debug.print("{s}:\n", .{case});
                    std.debug.print("\n====== expected to find: =========\n", .{});
                    std.debug.print("{s}", .{expected_output});
                    std.debug.print("\n======== but did not find it in this: =========\n", .{});
                    std.debug.print("{s}", .{output.written()});
                    std.debug.print("\n======================================\n", .{});
                }
            } else {
                if (std.testing.expectEqualStrings(expected_output, output.written()))
                    ok_count += 1
                else |_|
                    fail_count += 1;
            }
            continue;
        }

        const expected_types = pp.defines.get("EXPECTED_TYPES");

        var tree = aro.Parser.parse(&pp) catch |err| switch (err) {
            error.FatalError => {
                if (try checkExpectedErrors(&pp, &buf, diag_buf.written())) |some| {
                    if (some) ok_count += 1 else {
                        std.debug.print("in case {s}\n", .{case});
                        fail_count += 1;
                    }
                }
                continue;
            },
            else => |e| return e,
        };
        defer tree.deinit();

        const ast_path = try std.fs.path.join(gpa, &.{ args[1], "ast", std.fs.path.basename(path) });
        defer gpa.free(ast_path);
        const maybe_ast = std.fs.cwd().readFileAlloc(ast_path, gpa, .unlimited) catch null;
        if (maybe_ast) |expected_ast| {
            defer gpa.free(expected_ast);
            var actual_ast: std.Io.Writer.Allocating = .init(gpa);
            defer actual_ast.deinit();

            try tree.dump(.no_color, &actual_ast.writer);
            std.testing.expectEqualStrings(expected_ast, actual_ast.written()) catch {
                std.debug.print("in case {s}\n", .{case});
                fail_count += 1;
                break;
            };
        } else {
            var discard_buf: [256]u8 = undefined;
            var discarding: std.Io.Writer.Discarding = .init(&discard_buf);
            tree.dump(.no_color, &discarding.writer) catch {};
        }

        if (expected_types) |types| {
            const test_fn = for (tree.root_decls.items) |decl| {
                const node = decl.get(&tree);
                if (node == .function and node.function.body != null) break node.function;
            } else {
                fail_count += 1;
                std.debug.print("{s}:\n", .{case});
                std.debug.print("EXPECTED_TYPES requires a function to be defined\n", .{});
                break;
            };

            var actual: StmtTypeDumper = .{};
            defer actual.deinit(gpa);

            try actual.dump(gpa, &tree, test_fn.body.?);

            var i: usize = 0;
            for (types.tokens) |str| {
                if (str.id == .macro_ws) continue;
                if (str.id != .string_literal) {
                    fail_count += 1;
                    std.debug.print("{s}:\n", .{case});
                    std.debug.print("EXPECTED_TYPES tokens must be string literals (found {s})\n", .{@tagName(str.id)});
                    continue :next_test;
                }
                defer i += 1;
                if (i >= actual.types.items.len) continue;

                const expected_type = std.mem.trim(u8, pp.tokSlice(str), "\"");
                const actual_type = actual.types.items[i];
                if (!std.mem.eql(u8, expected_type, actual_type)) {
                    fail_count += 1;
                    std.debug.print("{s}:\n", .{case});
                    std.debug.print("expected type '{s}' did not match actual type '{s}'\n", .{
                        expected_type,
                        actual_type,
                    });
                    continue :next_test;
                }
            }
            if (i != actual.types.items.len) {
                fail_count += 1;
                std.debug.print("{s}:\n", .{case});
                std.debug.print(
                    "EXPECTED_TYPES count differs: expected {d} found {d}\n",
                    .{ i, actual.types.items.len },
                );
                continue;
            }
        }

        if (try checkExpectedErrors(&pp, &buf, diag_buf.written())) |some| {
            if (some) ok_count += 1 else {
                std.debug.print("in case {s}\n", .{case});
                fail_count += 1;
            }
            continue;
        }

        if (pp.defines.contains("NO_ERROR_VALIDATION")) continue;
        {
            var stderr_buf: [4096]u8 = undefined;
            var stderr = std.fs.File.stderr().writer(&stderr_buf);
            try stderr.interface.writeAll(diag_buf.written());
            try stderr.interface.flush();
        }

        if (pp.defines.get("EXPECTED_OUTPUT")) |macro| blk: {
            if (comp.diagnostics.errors != 0) break :blk;

            if (macro.is_func) {
                fail_count += 1;
                std.debug.print("{s}:\n", .{case});
                std.debug.print("invalid EXPECTED_OUTPUT {}\n", .{macro});
                continue;
            }

            if (macro.tokens.len != 1 or macro.tokens[0].id != .string_literal) {
                fail_count += 1;
                std.debug.print("{s}:\n", .{case});
                std.debug.print("EXPECTED_OUTPUT takes exactly one string", .{});
                continue;
            }

            defer buf.items.len = 0;
            // realistically the strings will only contain \" if any escapes so we can use Zig's string parsing
            {
                var allocating: std.Io.Writer.Allocating = .fromArrayList(gpa, &buf);
                defer buf = allocating.toArrayList();
                std.debug.assert((try std.zig.string_literal.parseWrite(&allocating.writer, pp.tokSlice(macro.tokens[0]))) == .success);
            }
            const expected_output = buf.items;

            const obj_name = "test_object.o";
            if (true) @panic("no backend available");
            // {
            //     const obj = try Codegen.generateTree(&comp, tree);
            //     defer obj.deinit();

            //     const out_file = try std.fs.cwd().createFile(obj_name, .{});
            //     defer out_file.close();

            //     try obj.finish(out_file);
            // }

            var child = std.process.Child.init(&.{ args[2], "run", "-lc", obj_name }, gpa);
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
                std.debug.print("{s}:\n", .{case});
                std.debug.print(
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

        if (comp.diagnostics.errors != 0) fail_count += 1 else ok_count += 1;
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
fn checkExpectedErrors(pp: *aro.Preprocessor, buf: *std.ArrayListUnmanaged(u8), errors: []const u8) !?bool {
    const macro = pp.defines.get("EXPECTED_ERRORS") orelse return null;

    const expected_count = pp.diagnostics.total;
    if (macro.is_func) {
        std.debug.print("invalid EXPECTED_ERRORS {}\n", .{macro});
        return false;
    }
    buf.items.len = 0;

    var count: usize = 0;
    for (macro.tokens) |str| {
        if (str.id == .macro_ws) continue;
        if (str.id != .string_literal) {
            std.debug.print("EXPECTED_ERRORS tokens must be string literals (found {s})\n", .{@tagName(str.id)});
            return false;
        }
        defer count += 1;
        if (count >= expected_count) continue;

        const start = buf.items.len;
        // realistically the strings will only contain \" if any escapes so we can use Zig's string parsing
        {
            var allocating: std.Io.Writer.Allocating = .fromArrayList(pp.comp.gpa, buf);
            defer buf.* = allocating.toArrayList();
            std.debug.assert((try std.zig.string_literal.parseWrite(&allocating.writer, pp.tokSlice(str))) == .success);
        }
        try buf.append(pp.comp.gpa, '\n');
        const expected_error = buf.items[start..];

        const index = std.mem.indexOf(u8, errors, expected_error);
        if (index == null) {
            std.debug.print(
                \\
                \\======= expected to find error =======
                \\{s}
                \\
                \\=== but output does not contain it ===
                \\{s}
                \\
                \\
            , .{ expected_error, errors });
            return false;
        }
    }

    if (count != expected_count) {
        std.debug.print(
            \\EXPECTED_ERRORS missing errors, expected {d} found {d},
            \\
        , .{ count, expected_count });
        var it = std.mem.tokenizeScalar(u8, errors, '\n');
        while (it.next()) |msg| {
            const start = std.mem.indexOf(u8, msg, ".c:") orelse continue;
            const index = std.mem.indexOf(u8, buf.items, msg[start..]);
            if (index == null) {
                std.debug.print(
                    \\
                    \\========= new error ==========
                    \\{s}
                    \\
                    \\=== not in EXPECTED_ERRORS ===
                    \\
                    \\
                , .{msg});
            }
        }
        return false;
    }
    return true;
}

const StmtTypeDumper = struct {
    types: std.ArrayList([]const u8) = .empty,

    fn deinit(self: *StmtTypeDumper, allocator: std.mem.Allocator) void {
        for (self.types.items) |t| {
            allocator.free(t);
        }
        self.types.deinit(allocator);
    }

    fn dumpNode(self: *StmtTypeDumper, gpa: std.mem.Allocator, tree: *const aro.Tree, node: Node.Index) AllocatorError!void {
        const maybe_ret = node.get(tree);
        if (maybe_ret == .return_stmt and maybe_ret.return_stmt.operand == .implicit) return;

        var allocating: std.Io.Writer.Allocating = .init(gpa);
        defer allocating.deinit();

        node.qt(tree).dump(tree.comp, &allocating.writer) catch {};
        const owned = try allocating.toOwnedSlice();
        errdefer allocating.allocator.free(owned);

        try self.types.append(gpa, owned);
    }

    fn dump(self: *StmtTypeDumper, gpa: std.mem.Allocator, tree: *const aro.Tree, body: Node.Index) AllocatorError!void {
        const compound = body.get(tree).compound_stmt;
        for (compound.body) |stmt| {
            try self.dumpNode(gpa, tree, stmt);
        }
    }
};
