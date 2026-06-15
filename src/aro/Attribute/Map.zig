const std = @import("std");
const mem = std.mem;
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
        deprecated_replacement,
        deprecated_reason,
        deprecated,
        unavailable_reason,
        unavailable,
        warning,
        @"error",
    };
};

attributes: std.MultiArrayList(Repr) = .empty,
extra: std.ArrayList(u32) = .empty,

pub const Ref = enum(u32) { _ };

pub fn deinit(map: *Map, gpa: mem.Allocator) void {
    map.attributes.deinit(gpa);
    map.extra.deinit(gpa);
    map.* = undefined;
}

pub fn put(map: *Map, gpa: mem.Allocator, attribute: Attribute) !Ref {
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
        .deprecated => |deprecated| if (deprecated.replacement) |replacement| {
            repr.tag = .deprecated_replacement;
            repr.data = @intCast(map.extra.items.len);
            try map.extra.append(gpa, attribute.tok);
            try map.putString(gpa, deprecated.msg.?);
            try map.putString(gpa, replacement);
        } else if (deprecated.msg) |msg| {
            repr.tag = .deprecated_reason;
            repr.data = @intCast(map.extra.items.len);
            try map.extra.append(gpa, attribute.tok);
            try map.putString(gpa, msg);
        } else {
            repr.tag = .deprecated;
        },
        .unavailable => |unavailable| if (unavailable.msg) |msg| {
            repr.tag = .unavailable_reason;
            repr.data = @intCast(map.extra.items.len);
            try map.extra.append(gpa, attribute.tok);
            try map.putString(gpa, msg);
        } else {
            repr.tag = .unavailable;
        },
        .warning => |msg| {
            repr.tag = .warning;
            repr.data = @intCast(map.extra.items.len);
            try map.extra.append(gpa, attribute.tok);
            try map.putString(gpa, msg);
        },
        .@"error" => |msg| {
            repr.tag = .@"error";
            repr.data = @intCast(map.extra.items.len);
            try map.extra.append(gpa, attribute.tok);
            try map.putString(gpa, msg);
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
        .deprecated_replacement => {
            res.tok = map.extra.items[repr.data];
            const msg, const replacement_index = map.getString(repr.data + 1);
            const replacement, _ = map.getString(replacement_index);
            res.args = .{ .deprecated = .{
                .msg = msg,
                .replacement = replacement,
            } };
        },
        .deprecated_reason => {
            res.tok = map.extra.items[repr.data];
            const msg, _ = map.getString(repr.data + 1);
            res.args = .{ .deprecated = .{ .msg = msg } };
        },
        .deprecated => res.args = .{ .deprecated = .{} },
        .unavailable_reason => {
            res.tok = map.extra.items[repr.data];
            const msg, _ = map.getString(repr.data + 1);
            res.args = .{ .unavailable = .{ .msg = msg } };
        },
        .unavailable => res.args = .{ .unavailable = .{} },
        .warning => {
            res.tok = map.extra.items[repr.data];
            const msg, _ = map.getString(repr.data + 1);
            res.args = .{ .warning = msg };
        },
        .@"error" => {
            res.tok = map.extra.items[repr.data];
            const msg, _ = map.getString(repr.data + 1);
            res.args = .{ .@"error" = msg };
        },
    }
    return res;
}

fn putString(map: *Map, gpa: mem.Allocator, str: []const u8) !void {
    const str_len: u32 = @intCast(str.len);
    const aligned_len = mem.alignForward(u32, str_len, 4) / 4;
    try map.extra.ensureUnusedCapacity(gpa, aligned_len + 1);
    map.extra.appendAssumeCapacity(str_len);
    const dest = map.extra.addManyAsSliceAssumeCapacity(aligned_len);
    @memcpy(@as([]u8, @ptrCast(dest))[0..str.len], str);
}

fn getString(map: *const Map, index: u32) struct { []const u8, u32 } {
    const str_len = map.extra.items[index];
    const aligned_len = mem.alignForward(u32, str_len, 4) / 4;
    return .{
        @as([]const u8, @ptrCast(map.extra.items[index + 1 ..]))[0..str_len],
        index + 1 + aligned_len,
    };
}
