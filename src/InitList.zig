//! Sparsely populated list of used indexes.
//! Used for detecting duplicate initializers.
const std = @import("std");
const Allocator = std.mem.Allocator;
const testing = std.testing;
const Tree = @import("Tree.zig");
const Token = Tree.Token;
const TokenIndex = Tree.TokenIndex;
const NodeIndex = Tree.NodeIndex;
const Type = @import("Type.zig");
const Diagnostics = @import("Diagnostics.zig");
const NodeList = std.ArrayList(NodeIndex);
const Parser = @import("Parser.zig");

const InitList = @This();

const Item = struct {
    list: InitList = .{},
    index: u64,
    node: NodeIndex,
    tok: TokenIndex,

    fn order(_: void, a: Item, b: Item) std.math.Order {
        return std.math.order(a.index, b.index);
    }
};

list: std.ArrayListUnmanaged(Item) = .{},

/// Deinitialize freeing all memory.
pub fn deinit(il: *InitList, gpa: *Allocator) void {
    for (il.list.items) |*item| item.list.deinit(gpa);
    il.list.deinit(gpa);
    il.* = undefined;
}

/// Insert initializer at index, returning previous entry if one exists.
pub fn put(il: *InitList, gpa: *Allocator, index: usize, node: NodeIndex, tok: TokenIndex) !?TokenIndex {
    const items = il.list.items;
    var left: usize = 0;
    var right: usize = items.len;

    while (left < right) {
        // Avoid overflowing in the midpoint calculation
        const mid = left + (right - left) / 2;
        // Compare the key with the midpoint element
        switch (std.math.order(items[mid].index, index)) {
            .eq => {
                // Replace previous entry.
                const prev = items[mid].tok;
                items[mid].list.deinit(gpa);
                items[mid] = .{
                    .node = node,
                    .tok = tok,
                    .index = index,
                };
                return prev;
            },
            .gt => left = mid + 1,
            .lt => right = mid,
        }
    }

    // Insert a new value into a sorted position.
    try il.list.insert(gpa, left, .{
        .node = node,
        .tok = tok,
        .index = index,
    });
    return null;
}

/// Find item at index, create new if one does not exist.
pub fn find(il: *InitList, gpa: *Allocator, index: usize) !*Item {
    const items = il.list.items;
    var left: usize = 0;
    var right: usize = items.len;

    while (left < right) {
        // Avoid overflowing in the midpoint calculation
        const mid = left + (right - left) / 2;
        // Compare the key with the midpoint element
        switch (std.math.order(items[mid].index, index)) {
            .eq => return &items[mid],
            .gt => left = mid + 1,
            .lt => right = mid,
        }
    }

    // Insert a new value into a sorted position.
    try il.list.insert(gpa, left, .{
        .node = .none,
        .tok = 0,
        .index = index,
    });
    return &il.list.items[left];
}

test "basic usage" {
    const gpa = testing.allocator;
    var il: InitList = .{};
    defer il.deinit(gpa);

    {
        var i: usize = 0;
        while (i < 5) : (i += 1) {
            const prev = try il.put(gpa, i, .none, 0);
            try testing.expect(prev == null);
        }
    }

    {
        const failing = testing.failing_allocator;
        var i: usize = 0;
        while (i < 5) : (i += 1) {
            _ = try il.find(failing, i);
        }
    }

    {
        var item = try il.find(gpa, 0);
        var i: usize = 1;
        while (i < 5) : (i += 1) {
            item = try item.list.find(gpa, i);
        }
    }

    {
        const failing = testing.failing_allocator;
        var item = try il.find(failing, 0);
        var i: usize = 1;
        while (i < 5) : (i += 1) {
            item = try item.list.find(failing, i);
        }
    }
}
