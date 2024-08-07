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

var fixed_buffer_mem: [20 * 1024 * 1024]u8 = undefined;

export fn compile_c_buf(buf: [*]const u8, len: c_int) void {
    compileSlice(buf[0..@intCast(len)]) catch |e| switch (e) {
        error.FatalError,
        error.OutOfMemory,
        => {},
        else => unreachable,
    };
}

fn compileSlice(buf: []const u8) !void {
    var fixed_allocator = std.heap.FixedBufferAllocator.init(fixed_buffer_mem[0..]);
    const allocator = fixed_allocator.allocator();

    const aro_dir = try std.fs.selfExePathAlloc(allocator);
    defer allocator.free(aro_dir);

    var comp = Compilation.init(allocator, std.fs.cwd());
    defer comp.deinit();

    try comp.addDefaultPragmaHandlers();
    try comp.addSystemIncludeDir(aro_dir);

    const builtin = try comp.generateBuiltinMacros(.include_system_defines);
    const user_source = try comp.addSourceFromBuffer("<STDIN>", buf);

    try processSource(&comp, builtin, user_source);
    _ = comp.sources.swapRemove(user_source.path);
}

fn processSource(comp: *Compilation, builtin: Source, user_source: Source) !void {
    var pp = Preprocessor.init(comp);
    defer pp.deinit();
    try pp.addBuiltinMacros();

    _ = try pp.preprocess(builtin);
    const eof = try pp.preprocess(user_source);
    try pp.addToken(eof);

    var tree = try Parser.parse(&pp);
    defer tree.deinit();

    try tree.dump(.no_color, std.io.null_writer);
}
