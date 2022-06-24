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

const non_working_tests = std.ComptimeStringMap(void, .{
    // attributes on field not supported (exclude attributes on types to get working)
    .{"0007"}, .{"0008"}, .{"0010"}, .{"0011"}, .{"0014"}, .{"0028"}, .{"0029"}, .{"0044"}, .{"0045"}, .{"0046"}, .{"0058"},
    .{"0066"}, .{"0070"}, .{"0080"}, .{"0081"}, .{"0084"}, .{"0085"}, .{"0086"},
    // // enum attr packed issue.
    .{"0055"}, .{"0060"}, .{"0062"},
    // __int128 issue
    .{"0050"},
    // clang-13 fails
    .{"0006"}, .{"0016"}, .{"0051"}, .{"0063"}, .{"0068"}, .{"0083"},
});

const skip_extra_tests = [_][]const u8{
    // clang-13 works w/ all the extra tests.
    // more work for arocc
    "0076", "0079", "0087", "0088",
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
            _ = try mac_writer.write("#define X8664_UNKNOWN_LINUX_MUSL\n");
            _ = try mac_writer.write("#define CHECK_OFFSETS\n");
            if (!skip_extras) _ = try mac_writer.write("#define EXTRA_TESTS\n");
            // try macro_buf.append("-Wno-ignored-pragmas");
            comp.diag.options.@"ignored-pragmas" = .off;
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

        if (try checkExpectedErrors(&pp, &progress, &buf)) |some| {
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
        const owned = m.buf.toOwnedSlice();
        errdefer m.buf.allocator.free(owned);
        try self.types.append(owned);
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
