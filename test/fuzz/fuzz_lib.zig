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

var fixed_buffer_mem: [10 * 1024 * 1024]u8 = undefined;

export fn compile_c_buf(buf: [*]const u8, len: c_int) void {
    compileSlice(buf[0..@intCast(usize, len)]) catch unreachable;
}

fn compileSlice(buf: []const u8) !void {
    var fixed_allocator = std.heap.FixedBufferAllocator.init(fixed_buffer_mem[0..]);
    var allocator = fixed_allocator.allocator();

    var comp = Compilation.init(allocator);
    defer comp.deinit();

    try comp.addDefaultPragmaHandlers();
    try comp.defineSystemIncludes();

    const builtin = try comp.generateBuiltinMacros();
    const user_source = try comp.addSourceFromBuffer("<STDIN>", buf);

    processSource(&comp, builtin, user_source) catch |e| switch (e) {
        error.FatalError => {},
        else => |err| return err,
    };
    _ = comp.sources.swapRemove(user_source.path);
}

fn processSource(comp: *Compilation, builtin: Source, user_source: Source) !void {
    var pp = Preprocessor.init(comp);
    defer pp.deinit();
    try pp.addBuiltinMacros();

    _ = try pp.preprocess(builtin);
    const eof = try pp.preprocess(user_source);
    try pp.tokens.append(pp.comp.gpa, eof);

    var tree = try Parser.parse(&pp);
    defer tree.deinit();

    try tree.dump(std.io.null_writer);
}
