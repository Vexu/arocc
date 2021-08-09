const std = @import("std");
const print = std.debug.print;
const aro = @import("aro");

const predefined_macros =
    \\#define EXPECT(x) _Static_assert(x, "unexpected result")
;

var general_purpose_allocator = std.heap.GeneralPurposeAllocator(.{}){};

pub fn main() !void {
    const gpa = &general_purpose_allocator.allocator;
    defer _ = general_purpose_allocator.deinit();

    var args = try std.process.argsAlloc(gpa);
    defer std.process.argsFree(gpa, args);

    if (args.len != 2) {
        print("expected test case directory as only argument\n", .{});
        return error.InvalidArguments;
    }

    var path_buf = std.ArrayList(u8).init(gpa);
    defer path_buf.deinit();
    var cases = std.ArrayList(struct { start: usize, end: usize }).init(gpa);
    defer cases.deinit();

    // collect all cases
    {
        var cases_dir = try std.fs.cwd().openDir(args[1], .{ .iterate = true });
        defer cases_dir.close();

        var it = cases_dir.iterate();
        while (try it.next()) |entry| {
            if (entry.kind != .File) {
                print("skipping non file entry '{s}'\n", .{entry.name});
                continue;
            }

            const start = path_buf.items.len;
            try path_buf.writer().print("{s}{c}{s}", .{ args[1], std.fs.path.sep, entry.name });

            try cases.append(.{ .start = start, .end = path_buf.items.len });
        }
    }

    var progress = std.Progress{};
    const root_node = progress.start("Test", cases.items.len) catch |err| switch (err) {
        // TODO still run tests in this case
        error.TimerUnsupported => @panic("timer unsupported"),
    };

    // prepare compiler
    var comp = aro.Compilation.init(gpa);
    defer comp.deinit();

    const builtin_macros = try comp.generateBuiltinMacros();
    const test_runner_macros = blk: {
        const duped_path = try gpa.dupe(u8, "<test_runner>");
        errdefer comp.gpa.free(duped_path);

        const contents = try gpa.dupe(u8, predefined_macros);
        errdefer comp.gpa.free(contents);

        const source = aro.Source{
            .id = @intToEnum(aro.Source.Id, @intCast(u32, comp.sources.count() + 2)),
            .path = duped_path,
            .buf = contents,
        };
        try comp.sources.put(duped_path, source);
        break :blk source;
    };

    // iterate over all cases
    var ok_count: u32 = 0;
    var fail_count: u32 = 0;
    var skip_count: u32 = 0;
    for (cases.items) |range| {
        const path = path_buf.items[range.start..range.end];
        const file = comp.addSource(path) catch |err| {
            fail_count += 1;
            progress.log("could not add source '{s}': {s}\n", .{ path, @errorName(err) });
            continue;
        };
        defer {
            _ = comp.sources.swapRemove(path);
            gpa.free(file.path);
            gpa.free(file.buf);
        }

        const case = std.mem.sliceTo(std.fs.path.basename(path), '.');
        var case_node = root_node.start(case, 0);
        case_node.activate();
        progress.refresh();

        comp.diag.errors = 0;
        var pp = aro.Preprocessor.init(&comp);
        defer pp.deinit();

        try pp.preprocess(builtin_macros);
        try pp.preprocess(test_runner_macros);
        pp.preprocess(file) catch |err| {
            fail_count += 1;
            case_node.end();
            progress.log("could not preprocess file '{s}': {s}\n", .{ path, @errorName(err) });
            continue;
        };
        try pp.tokens.append(pp.comp.gpa, .{
            .id = .eof,
            .loc = .{ .id = file.id, .byte_offset = @intCast(u32, file.buf.len) },
        });

        if (pp.defines.get("TESTS_SKIPPED")) |macro| {
            if (macro != .simple or macro.simple.tokens.len != 1 or macro.simple.tokens[0].id != .integer_literal) {
                fail_count += 1;
                case_node.end();
                progress.log("{s}: invalid TESTS_SKIPPED, definition should contain exactly one integer literal {}\n", .{ case, macro });
                continue;
            }
            const tok_slice = pp.tokSliceSafe(macro.simple.tokens[0]);
            skip_count += try std.fmt.parseInt(u32, tok_slice, 0);
        }

        if (pp.defines.get("EXPECTED_TOKENS")) |macro| {
            comp.renderErrors();

            const expected_tokens = switch (macro) {
                .simple => |simple| simple.tokens,
                .empty => &[_]aro.Tokenizer.Token{},
                else => {
                    fail_count += 1;
                    case_node.end();
                    progress.log("{s}: invalid EXPECTED_TOKENS {}\n", .{ case, macro });
                    continue;
                },
            };

            if (pp.tokens.len - 1 != expected_tokens.len) {
                fail_count += 1;
                case_node.end();
                progress.log(
                    "{s}: EXPECTED_TOKENS count differs: expected {d} found {d}\n",
                    .{ case, expected_tokens.len, pp.tokens.len - 1 },
                );
                continue;
            }

            var i: usize = 0;
            while (true) : (i += 1) {
                const tok = pp.tokens.get(i);
                if (tok.id == .eof) {
                    if (comp.diag.errors != 0) fail_count += 1 else ok_count += 1;
                    case_node.end();
                    break;
                }

                const expected = pp.tokSliceSafe(expected_tokens[i]);
                const actual = pp.expandedSlice(tok);
                if (!std.mem.eql(u8, expected, actual)) {
                    fail_count += 1;
                    case_node.end();
                    progress.log(
                        "{s}: unexpected token found: expected '{s}' found '{s}'\n",
                        .{ case, expected, actual },
                    );
                    break;
                }
            }
            continue;
        }

        var tree = try aro.Parser.parse(&pp);
        defer tree.deinit();

        if (pp.defines.get("EXPECTED_ERRORS")) |macro| {
            var m = MsgWriter.init(gpa);
            defer m.deinit();
            aro.Diagnostics.renderExtra(&comp, &m);

            if (macro != .simple) {
                fail_count += 1;
                case_node.end();
                progress.log("{s}: invalid EXPECTED_ERRORS {}\n", .{ case, macro });
                continue;
            }

            for (macro.simple.tokens) |str| {
                if (str.id != .string_literal) {
                    fail_count += 1;
                    case_node.end();
                    progress.log("{s}: EXPECTED_ERRORS tokens must be string literals (found {s})\n", .{ case, @tagName(str.id) });
                    break;
                }
                const expected_error = std.mem.trim(u8, pp.tokSliceSafe(str), "\"");

                if (std.mem.indexOf(u8, m.buf.items, expected_error) == null) {
                    fail_count += 1;
                    case_node.end();
                    progress.log(
                        \\{s}: expected to find error:
                        \\{s}
                        \\
                        \\but output does not contain it
                        \\{s}
                        \\
                        \\
                    , .{ case, expected_error, m.buf.items });
                    break;
                }
            } else {
                ok_count += 1;
                case_node.end();
            }
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
