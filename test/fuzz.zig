const std = @import("std");
const aro = @import("aro");
const mem = std.mem;
const Allocator = mem.Allocator;
const process = std.process;
const Codegen = aro.Codegen;
const Compilation = aro.Compilation;
const Source = aro.Source;
const Preprocessor = aro.Preprocessor;
const Parser = aro.Parser;

fn cMain() callconv(.C) void {
    main() catch unreachable;
}

comptime {
    @export(cMain, .{ .name = "main", .linkage = .Strong });
}

var general_purpose_allocator = std.heap.GeneralPurposeAllocator(.{}){};

pub fn main() !void {
    const gpa = &general_purpose_allocator.allocator;
    defer std.debug.assert(general_purpose_allocator.deinit() == false);

    var comp = Compilation.init(gpa);
    defer comp.deinit();

    try compileInput(&comp);
}

fn compileInput(comp: *Compilation) !void {
    try comp.addDefaultPragmaHandlers();
    try comp.defineSystemIncludes();

    const builtin = try comp.generateBuiltinMacros();
    const user_source = blk: {
        const path = try comp.gpa.dupe(u8, "<STDIN>");
        errdefer comp.gpa.free(path);

        const stdin = std.io.getStdIn();
        const buf = try stdin.readToEndAlloc(comp.gpa, std.math.maxInt(usize));
        errdefer comp.gpa.free(buf);

        const source = Source{
            .id = @intToEnum(Source.Id, comp.sources.count() + 2),
            .path = path,
            .buf = buf,
        };
        try comp.sources.put(path, source);
        break :blk source;
    };

    processSource(comp, builtin, user_source) catch |e| switch (e) {
        error.FatalError => {},
        else => |err| return err,
    };
}

fn processSource(comp: *Compilation, builtin: Source, user_source: Source) !void {
    var pp = Preprocessor.init(comp);
    defer pp.deinit();
    try pp.addBuiltinMacros();

    try pp.preprocess(builtin);
    try pp.preprocess(user_source);
    try pp.tokens.append(pp.comp.gpa, .{
        .id = .eof,
        .loc = .{ .id = user_source.id, .byte_offset = @intCast(u32, user_source.buf.len) },
    });

    var tree = try Parser.parse(&pp);
    defer tree.deinit();

    var buf_writer = std.io.bufferedWriter(std.io.getStdOut().writer());
    try tree.dump(buf_writer.writer());
    try buf_writer.flush();

    comp.renderErrors();
}
