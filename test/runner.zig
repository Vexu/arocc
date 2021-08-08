const std = @import("std");
const print = std.debug.print;
const aro = @import("aro");

const predefined_macros =
    \\#define EXPECT(x) _Static_assert(x, "unexpected result")
;

var general_purpose_allocator = std.heap.GeneralPurposeAllocator(.{}){};

pub fn main() !u8 {
    const gpa = &general_purpose_allocator.allocator;
    defer _ = general_purpose_allocator.deinit();

    var args = try std.process.argsAlloc(gpa);
    defer std.process.argsFree(gpa, args);

    if (args.len != 2) {
        print("expected test case directory as only argument\n", .{});
        return error.InvalidArguments;
    }

    var cases_dir = try std.fs.cwd().openDir(args[1], .{ .iterate = true });
    defer cases_dir.close();

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

    var path_buf = std.ArrayList(u8).init(gpa);
    defer path_buf.deinit();

    // iterate over all cases
    var any_error = false;
    var it = cases_dir.iterate();
    while (try it.next()) |entry| {
        if (entry.kind != .File) {
            print("skipping non file entry '{s}'\n", .{entry.name});
            continue;
        }

        path_buf.items.len = 0;
        try path_buf.writer().print("{s}{c}{s}", .{ args[1], std.fs.path.sep, entry.name });
        const path = path_buf.items;

        const file = comp.addSource(path) catch |err| {
            any_error = true;
            print("could not add source '{s}': {s}\n", .{ path, @errorName(err) });
            continue;
        };
        defer {
            _ = comp.sources.swapRemove(path);
            gpa.free(file.path);
            gpa.free(file.buf);
        }

        var pp = aro.Preprocessor.init(&comp);
        defer pp.deinit();

        try pp.preprocess(builtin_macros);
        try pp.preprocess(test_runner_macros);
        pp.preprocess(file) catch |err| {
            any_error = true;
            print("could not preprocess file '{s}': {s}\n", .{ path, @errorName(err) });
            continue;
        };
        try pp.tokens.append(pp.comp.gpa, .{
            .id = .eof,
            .loc = .{ .id = file.id, .byte_offset = @intCast(u32, file.buf.len) },
        });

        const case = std.mem.sliceTo(entry.name, '.');
        if (pp.defines.get("EXPECTED_TOKENS")) |macro| {
            comp.renderErrors();

            const expected_tokens = switch (macro) {
                .simple => |simple| simple.tokens,
                .empty => &[_]aro.Tokenizer.Token{},
                else => {
                    any_error = true;
                    print("case '{s}': invalid EXPECTED_TOKENS {}\n", .{ case, macro });
                    continue;
                },
            };

            if (pp.tokens.len - 1 != expected_tokens.len) {
                any_error = true;
                print(
                    "case '{s}': EXPECTED_TOKENS count differs: expected {d} found {d}\n",
                    .{ case, expected_tokens.len, pp.tokens.len - 1 },
                );
                continue;
            }

            var i: usize = 0;
            while (true) : (i += 1) {
                const tok = pp.tokens.get(i);
                if (tok.id == .eof) break;

                const expected = pp.tokSliceSafe(expected_tokens[i]);
                const actual = pp.expandedSlice(tok);
                if (!std.mem.eql(u8, expected, actual)) {
                    print(
                        "case '{s}': unexpected token found: expected '{s}' found '{s}'\n",
                        .{ case, expected, actual },
                    );
                    break;
                }
            }
            continue;
        }

        var tree = try aro.Parser.parse(&pp);
        defer tree.deinit();

        if (pp.defines.get("EXPECTED_ERRORS")) |_| {
            // TODO
            continue;
        }

        comp.renderErrors();
    }

    return @boolToInt(any_error or comp.diag.errors != 0);
}
