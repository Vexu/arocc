const std = @import("std");
const Driver = @import("driver/Driver.zig");
const Compilation = @import("Compilation.zig");
const Toolchain = @import("Toolchain.zig");

test Driver {
    var arena_instance = std.heap.ArenaAllocator.init(std.testing.allocator);
    defer arena_instance.deinit();
    const arena = arena_instance.allocator();

    var comp = Compilation.init(std.testing.allocator);
    defer comp.deinit();

    var driver: Driver = .{ .comp = &comp };
    defer driver.deinit();

    var toolchain: Toolchain = .{ .driver = &driver, .arena = arena };
    defer toolchain.deinit();

    try std.testing.expect(1 == 1);
}
