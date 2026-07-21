const std = @import("std");
const mem = std.mem;
const Attribute = @import("../Attribute.zig");
const Compilation = @import("../Compilation.zig");
const Tree = @import("../Tree.zig");
const TokenIndex = Tree.TokenIndex;

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
        warn_unused_result_msg,
        warn_unused_result,
        nonnull_zero,
        nonnull_one,
        nonnull,
        transparent_union,
        designated_init,
        fallthrough,
        visibility_default,
        visibility_hidden,
        visibility_protected,
        noreturn,
        cleanup,
        always_inline,
        gnu_inline,
        section,
        weak,
        selectany,
        internal_linkage,
        unsequenced,
        reproducible,
        unused,
    };
};

const Map = @This();

attributes: std.MultiArrayList(Repr) = .empty,
extra: std.ArrayList(u32) = .empty,
decl_attrs: std.AutoHashMapUnmanaged(Tree.Node.Index, struct { u32, u32 }) = .empty,

pub const Ref = enum(u32) { _ };

pub fn deinit(map: *Map, gpa: mem.Allocator) void {
    map.attributes.deinit(gpa);
    map.extra.deinit(gpa);
    map.decl_attrs.deinit(gpa);
    map.* = undefined;
}

pub fn put(map: *Map, gpa: mem.Allocator, attribute: Attribute) !Ref {
    var repr: Repr = .{
        .tag = undefined,
        .data = attribute.tok,
        .name = attribute.name,
        .syntax = attribute.syntax,
    };
    switch (attribute.args) {
        inline .@"packed",
        .hot,
        .cold,
        .@"const",
        .transparent_union,
        .designated_init,
        .fallthrough,
        .noreturn,
        .always_inline,
        .gnu_inline,
        .weak,
        .selectany,
        .internal_linkage,
        .unsequenced,
        .reproducible,
        .unused,
        => |_, tag| repr.tag = @field(Repr.Tag, @tagName(tag)),
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
        .unavailable => |opt_msg| if (opt_msg) |msg| {
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
        .warn_unused_result => |opt_msg| if (opt_msg) |msg| {
            repr.tag = .warn_unused_result_msg;
            repr.data = @intCast(map.extra.items.len);
            try map.extra.append(gpa, attribute.tok);
            try map.putString(gpa, msg);
        } else {
            repr.tag = .warn_unused_result;
        },
        .nonnull => |positions| if (positions.len == 0) {
            repr.tag = .nonnull_zero;
        } else if (positions.len == 1) {
            repr.tag = .nonnull_one;
            repr.data = @intCast(map.extra.items.len);
            try map.extra.appendSlice(gpa, &.{ attribute.tok, positions[0] });
        } else {
            repr.tag = .nonnull;
            repr.data = @intCast(map.extra.items.len);
            try map.extra.ensureUnusedCapacity(gpa, 2 + positions.len);
            map.extra.appendAssumeCapacity(attribute.tok);
            map.extra.appendAssumeCapacity(@intCast(positions.len));
            map.extra.appendSliceAssumeCapacity(positions);
        },
        .visibility => |kind| {
            repr.tag = switch (kind) {
                .default => .visibility_default,
                .hidden => .visibility_hidden,
                .protected => .visibility_protected,
            };
        },
        .cleanup => |cleanup| {
            repr.tag = .cleanup;
            repr.data = @intCast(map.extra.items.len);
            try map.extra.append(gpa, attribute.tok);
            try map.extra.append(gpa, @backingInt(cleanup.function));
        },
        .section => |name| {
            repr.tag = .section;
            repr.data = @intCast(map.extra.items.len);
            try map.extra.append(gpa, attribute.tok);
            try map.putString(gpa, name);
        },
        else => @panic("TODO"),
    }

    const index = map.attributes.len;
    try map.attributes.append(gpa, repr);
    return @fromBackingInt(@intCast(index));
}

pub fn get(map: *const Map, ref: Ref) Attribute {
    const repr = map.attributes.get(@backingInt(ref));
    var res: Attribute = .{
        .name = repr.name,
        .syntax = repr.syntax,
        .tok = repr.data,
        .args = undefined,
    };
    switch (repr.tag) {
        inline .@"packed",
        .hot,
        .cold,
        .@"const",
        .transparent_union,
        .designated_init,
        .fallthrough,
        .noreturn,
        .always_inline,
        .gnu_inline,
        .weak,
        .selectany,
        .internal_linkage,
        .unsequenced,
        .reproducible,
        .unused,
        => |tag| res.args = @field(Attribute.Args, @tagName(tag)),
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
            res.args = .{ .unavailable = msg };
        },
        .unavailable => res.args = .{ .unavailable = null },
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
        .warn_unused_result_msg => {
            res.tok = map.extra.items[repr.data];
            const msg, _ = map.getString(repr.data + 1);
            res.args = .{ .warn_unused_result = msg };
        },
        .warn_unused_result => res.args = .{ .warn_unused_result = null },
        .nonnull => {
            res.tok = map.extra.items[repr.data];
            const positions_len = map.extra.items[repr.data + 1];
            res.args = .{ .nonnull = map.extra.items[repr.data + 2 ..][0..positions_len] };
        },
        .nonnull_one => {
            res.tok = map.extra.items[repr.data];
            res.args = .{ .nonnull = map.extra.items[repr.data + 1 ..][0..1] };
        },
        .nonnull_zero => res.args = .{ .nonnull = &.{} },
        .visibility_default => res.args = .{ .visibility = .default },
        .visibility_hidden => res.args = .{ .visibility = .hidden },
        .visibility_protected => res.args = .{ .visibility = .protected },
        .cleanup => {
            res.tok = map.extra.items[repr.data];
            res.args = .{ .cleanup = .{ .function = @fromBackingInt(map.extra.items[repr.data + 1]) } };
        },
        .section => {
            res.tok = map.extra.items[repr.data];
            const name, _ = map.getString(repr.data + 1);
            res.args = .{ .section = name };
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

pub fn attrs(map: *const Map, opt_node: anytype) []const Attribute.Map.Ref {
    const node: Tree.Node.Index = opt_node.unpack() orelse return &.{};
    const index, const len = map.decl_attrs.get(node) orelse return &.{};
    return @ptrCast(map.extra.items[index..][0..len]);
}

pub fn getAttribute(map: *const Map, opt_node: anytype, tag: Attribute.Tag) ?Attribute {
    const node: Tree.Node.Index = opt_node.unpack() orelse return null;
    const node_attrs = map.attrs(node);

    var i: usize = node_attrs.len;
    while (i > 0) {
        i -= 1;
        const attr = map.get(node_attrs[i]);
        if (attr.args == tag) return attr;
    }
    return null;
}

pub fn requestedAlignment(map: *const Map, opt_node: anytype, comp: *const Compilation) ?u32 {
    const node: Tree.Node.Index = opt_node.unpack() orelse return null;
    var max_requested: ?u32 = null;
    for (map.attrs(node)) |ref| {
        const attr = map.get(ref);
        if (attr.args != .alignment) continue;

        const requested = if (attr.args.alignment) |alignment| alignment else comp.target.defaultAlignment();
        if (max_requested == null or max_requested.? < requested) {
            max_requested = requested;
        }
    }
    return max_requested;
}

pub fn hasAttribute(map: *const Map, opt_node: anytype, tag: Attribute.Tag) bool {
    const node: Tree.Node.Index = opt_node.unpack() orelse return false;
    for (map.attrs(node)) |ref| {
        const attr = map.get(ref);
        if (attr.args == tag) return true;
    }
    return false;
}
