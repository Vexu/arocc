const std = @import("std");
const Attribute = @import("../Attribute.zig");
const Tree = @import("../Tree.zig");
const TokenIndex = Tree.TokenIndex;

const Map = @This();

const Repr = struct {
    tag: Tag,
    data: u32,
    syntax: Attribute.Syntax,
    name: Attribute.Namespaced,

    pub const Tag = enum(u8) {
        @"packed",
    };
};

attributes: std.MultiArrayList(Repr) = .empty,
extra: std.ArrayList(u32) = .empty,

pub const Ref = enum(u32) { _ };

pub fn deinit(map: *Map, gpa: std.mem.Allocator) void {
    map.attributes.deinit(gpa);
    map.extra.deinit(gpa);
    map.* = undefined;
}

pub fn put(map: *Map, gpa: std.mem.Allocator, attribute: Attribute) !Ref {
    var repr: Repr = .{
        .tag = undefined,
        .data = attribute.tok,
        .name = attribute.name,
        .syntax = attribute.syntax,
    };
    _ = &repr;
    switch (attribute.args) {
        .@"packed" => repr.tag = .@"packed",
        else => @panic("TODO"),
    }

    const index = map.attributes.len;
    try map.attributes.append(gpa, repr);
    return @enumFromInt(index);
}

pub fn get(map: *const Map, ref: Ref) Attribute {
    const repr = map.attributes.get(@intFromEnum(ref));
    return .{
        .args = switch (repr.tag) {
            .@"packed" => .@"packed",
        },
        .name = repr.name,
        .syntax = repr.syntax,
        .tok = undefined,
    };
}
