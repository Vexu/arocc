/// Persistent treap data structure. Nodes are immutable and set operations do not invalidate
/// existing nodes.
/// Adapted from https://arxiv.org/pdf/1301.3388
const std = @import("std");

const Treap = @This();
const Key = []const u8;

pub const Node = ?*const Item;

const Item = struct {
    key: Key,
    left: Node,
    right: Node,

    fn priority(node: *const Item) u64 {
        return std.hash.Wyhash.hash(0, node.key);
    }

    const HashContext = struct {
        pub fn hash(self: @This(), s: *const Item) u64 {
            _ = self;
            return std.hash.Wyhash.hash(0, std.mem.asBytes(s));
        }
        pub fn eql(self: @This(), a: *const Item, b: *const Item) bool {
            _ = self;
            return a.left == b.left and a.right == b.right and std.mem.eql(u8, a.key, b.key);
        }
    };
};

allocator: std.mem.Allocator,
node_arena: std.heap.ArenaAllocator,
/// nodes are hash-consed so structural equality can be determined by comparing pointers
nodes: std.HashMapUnmanaged(*const Item, void, Item.HashContext, std.hash_map.default_max_load_percentage) = .{},

pub fn init(allocator: std.mem.Allocator) Treap {
    return .{ .allocator = allocator, .node_arena = std.heap.ArenaAllocator.init(allocator) };
}

pub fn deinit(self: *Treap) void {
    self.nodes.deinit(self.allocator);
    self.node_arena.deinit();
}

fn makeNode(self: *Treap, key: Key, left: Node, right: Node) !Node {
    const node: Item = .{ .key = key, .left = left, .right = right };
    const gop = try self.nodes.getOrPut(self.allocator, &node);
    if (gop.found_existing) return gop.key_ptr.*;

    const new_node = try self.node_arena.allocator().create(Item);
    new_node.* = .{
        .key = key,
        .left = left,
        .right = right,
    };
    gop.key_ptr.* = new_node;
    return new_node;
}

fn join(self: *Treap, t1_arg: Node, t2_arg: Node) !Node {
    const t1 = t1_arg orelse return t2_arg;
    const t2 = t2_arg orelse return t1_arg;
    if (t1.priority() < t2.priority()) {
        return self.makeNode(t2.key, try self.join(t1, t2.left), t2.right);
    } else {
        return self.makeNode(t1.key, t1.left, try self.join(t1.right, t2));
    }
}

fn split(self: *Treap, t_arg: Node, key: Key) !struct { Node, Node } {
    const t = t_arg orelse return .{ null, null };
    switch (std.mem.order(u8, key, t.key)) {
        .lt => {
            const l1, const l2 = try self.split(t.left, key);
            return .{ l1, try self.makeNode(t.key, l2, t.right) };
        },
        .eq, .gt => {
            const r1, const r2 = try self.split(t.right, key);
            return .{ try self.makeNode(t.key, t.left, r1), r2 };
        },
    }
}

fn add(self: *Treap, t1_arg: Node, t2_arg: Node) !Node {
    const t1 = t1_arg orelse return t2_arg;
    const t2 = t2_arg orelse return t1_arg;
    std.debug.assert(!std.mem.eql(u8, t1.key, t2.key));
    if (t1.priority() < t2.priority()) {
        const l1, const r1 = try self.split(t1, t2.key);
        return self.makeNode(t2.key, try self.add(l1, t2.left), try self.add(r1, t2.right));
    } else {
        const l2, const r2 = try self.split(t2, t1.key);
        return self.makeNode(t1.key, try self.add(t1.left, l2), try self.add(t1.right, r2));
    }
}

pub fn addNodeTo(self: *Treap, t1: Node, key: Key) !Node {
    std.debug.assert(!self.contains(t1, key));
    const node = try self.makeNode(key, null, null);
    return self.add(t1, node);
}

pub fn @"union"(self: *Treap, t1_arg: Node, t2_arg: Node) !Node {
    if (t1_arg == t2_arg) return t1_arg;
    const t1 = t1_arg orelse return t2_arg;
    const t2 = t2_arg orelse return t1_arg;

    if (std.mem.eql(u8, t1.key, t2.key)) {
        return self.makeNode(t1.key, try self.@"union"(t1.left, t2.left), try self.@"union"(t1.right, t2.right));
    } else if (t1.priority() < t2.priority()) {
        const l1, const r1 = try self.split(t1, t2.key);
        return self.makeNode(t2.key, try self.@"union"(l1, t2.left), try self.@"union"(r1, t2.right));
    } else {
        const l2, const r2 = try self.split(t2, t1.key);
        return self.makeNode(t1.key, try self.@"union"(t1.left, l2), try self.@"union"(t1.right, r2));
    }
}

pub fn intersection(self: *Treap, t1_arg: Node, t2_arg: Node) !Node {
    if (t1_arg == t2_arg) return t1_arg;
    const t1 = t1_arg orelse return null;
    const t2 = t2_arg orelse return null;

    if (std.mem.eql(u8, t1.key, t2.key)) {
        return self.makeNode(t1.key, try self.intersection(t1.left, t2.left), try self.intersection(t1.right, t2.right));
    } else if (t1.priority() < t2.priority()) {
        const l1, const r1 = try self.split(t1, t2.key);
        return self.join(try self.intersection(l1, t2.left), try self.intersection(r1, t2.right));
    } else {
        const l2, const r2 = try self.split(t2, t1.key);
        return self.join(try self.intersection(t1.left, l2), try self.intersection(t1.right, r2));
    }
}

pub fn contains(self: *Treap, t_arg: Node, key: Key) bool {
    const t = t_arg orelse return false;
    return switch (std.mem.order(u8, key, t.key)) {
        .eq => true,
        .lt => self.contains(t.left, key),
        .gt => self.contains(t.right, key),
    };
}

test add {
    var treap = Treap.init(std.testing.allocator);
    defer treap.deinit();

    const tree1 = try treap.addNodeTo(null, "1");
    const tree2 = try treap.addNodeTo(tree1, "2");
    const tree3 = try treap.addNodeTo(tree2, "3");
    const tree4 = try treap.addNodeTo(tree3, "4");

    try std.testing.expect(treap.contains(tree1, "1"));
    try std.testing.expect(!treap.contains(tree1, "2"));
    try std.testing.expect(treap.contains(tree2, "1"));
    try std.testing.expect(treap.contains(tree2, "2"));
    try std.testing.expect(!treap.contains(tree2, "3"));
    try std.testing.expect(treap.contains(tree3, "1"));
    try std.testing.expect(treap.contains(tree3, "2"));
    try std.testing.expect(treap.contains(tree3, "3"));
    try std.testing.expect(!treap.contains(tree3, "4"));

    try std.testing.expect(treap.contains(tree4, "4"));
}
