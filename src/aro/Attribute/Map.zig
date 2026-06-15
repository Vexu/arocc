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
        hot,
        cold,
        @"const",
        alignment,
        alignment_null,
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
        .hot => repr.tag = .hot,
        .cold => repr.tag = .cold,
        .@"const" => repr.tag = .@"const",
        .alignment => |opt_value| if (opt_value) |value| {
            repr.tag = .alignment;
            repr.data = @intCast(map.extra.items.len);
            try map.extra.appendSlice(gpa, &.{ attribute.tok, value });
        } else {
            repr.tag = .alignment_null;
        },
        else => @panic("TODO"),
    }

    const index = map.attributes.len;
    try map.attributes.append(gpa, repr);
    return @enumFromInt(index);
}

pub fn get(map: *const Map, ref: Ref) Attribute {
    const repr = map.attributes.get(@intFromEnum(ref));
    var res: Attribute = .{
        .name = repr.name,
        .syntax = repr.syntax,
        .tok = repr.data,
        .args = undefined,
    };
    switch (repr.tag) {
        .@"packed" => res.args = .@"packed",
        .hot => res.args = .hot,
        .cold => res.args = .cold,
        .@"const" => res.args = .@"const",
        .alignment_null => res.args = .{ .alignment = null },
        .alignment => {
            res.tok = map.extra.items[repr.data];
            res.args = .{ .alignment = map.extra.items[repr.data + 1] };
        },
    }
    return res;
}
