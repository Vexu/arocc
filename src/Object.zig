const std = @import("std");
const Compilation = @import("Compilation.zig");
const Elf = @import("object/Elf.zig");

const Object = @This();

pub const Kind = enum {
    elf,
};

comp: *Compilation,
kind: union(Kind) {
    elf: Elf,
},

pub fn init(comp: *Compilation, kind: Kind) Object {
    return .{
        .comp = comp,
        .kind = .{ .elf = .{}},
    };
}

pub fn deinit(o: *Object) void {
    // o.kind.deinit();
}

pub fn putRelocation(o: *Object, name: []const u8, section: ?[]const u8, offset: u64) !void {
    return;
}

pub fn putData(o: *Object, data: []const u8, read_only: bool) !u64 {
    return 0;
}

pub fn declareObject(o: *Object, name: []const u8, section: ?[]const u8, data: []const u8, read_only: bool) !void {
    return;
}

pub fn declareUninitialized(o: *Object, name: []const u8, section: ?[]const u8) !void {
    return;
}

pub fn declareFn(o: *Object, name: []const u8, section: ?[]const u8, contents: []const u8) !void {
    return;
}
