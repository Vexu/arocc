//! A hideset is a linked list (implemented as an array so that elements are identified by 4-byte indices)
//! of the set of identifiers from which a token was expanded.
//! During macro expansion, if a token would otherwise be expanded, but its hideset contains
//! the token itself, then it is not expanded
//! Most tokens have an empty hideset, and the hideset is not needed once expansion is complete,
//! so we use a hash map to store them instead of directly storing them with the token.
//! The C standard underspecifies the algorithm for updating a token's hideset;
//! we use the one here: https://www.spinellis.gr/blog/20060626/cpp.algo.pdf

const std = @import("std");
const mem = std.mem;
const Allocator = mem.Allocator;

const Source = @import("Source.zig");

pub const Hideset = @This();

const Identifier = struct {
    id: Source.Id = .unused,
    byte_offset: u32 = 0,

    fn fromLocation(loc: Source.Location) Identifier {
        return .{
            .id = loc.id,
            .byte_offset = loc.byte_offset,
        };
    }
};

const Item = struct {
    identifier: Identifier = .{},
    str: []const u8,
    next: Index = .none,

    const List = std.MultiArrayList(Item);
};

pub const Index = enum(u32) {
    none = std.math.maxInt(u32),
    _,
};

map: std.AutoHashMapUnmanaged(Identifier, Index) = .{},
/// Used for computing union/intersection of two lists; stored here so that allocations can be retained
/// until hideset is deinit'ed
tmp_map: std.AutoHashMapUnmanaged(Identifier, void) = .{},
linked_list: Item.List = .{},
gpa: Allocator,

/// Invalidated if the underlying MultiArrayList slice is reallocated due to resize
const Iterator = struct {
    slice: Item.List.Slice,
    i: Index,

    fn next(self: *Iterator) ?Item {
        if (self.i == .none) return null;
        defer self.i = self.slice.items(.next)[@intFromEnum(self.i)];
        const identifier = self.slice.items(.identifier)[@intFromEnum(self.i)];
        const str = self.slice.items(.str)[@intFromEnum(self.i)];

        return .{
            .identifier = identifier,
            .str = str,
        };
    }
};

pub fn deinit(self: *Hideset) void {
    self.map.deinit(self.gpa);
    self.tmp_map.deinit(self.gpa);
    self.linked_list.deinit(self.gpa);
}

pub fn clearRetainingCapacity(self: *Hideset) void {
    self.linked_list.shrinkRetainingCapacity(0);
    self.map.clearRetainingCapacity();
}

pub fn clearAndFree(self: *Hideset) void {
    self.map.clearAndFree(self.gpa);
    self.tmp_map.clearAndFree(self.gpa);
    self.linked_list.shrinkAndFree(self.gpa, 0);
}

/// Iterator is invalidated if the underlying MultiArrayList slice is reallocated due to resize
fn iterator(self: *const Hideset, idx: Index) Iterator {
    return Iterator{
        .slice = self.linked_list.slice(),
        .i = idx,
    };
}

pub fn get(self: *const Hideset, loc: Source.Location) Index {
    return self.map.get(Identifier.fromLocation(loc)) orelse .none;
}

pub fn put(self: *Hideset, loc: Source.Location, value: Index) !void {
    try self.map.put(self.gpa, Identifier.fromLocation(loc), value);
}

fn ensureUnusedCapacity(self: *Hideset, new_size: usize) !void {
    try self.linked_list.ensureUnusedCapacity(self.gpa, new_size);
}

/// Creates a one-item list with contents `identifier`
fn createNodeAssumeCapacity(self: *Hideset, identifier: Identifier, str: []const u8) Index {
    return self.createNodeAssumeCapacityExtra(identifier, .none, str);
}

/// Creates a one-item list with contents `identifier`
fn createNodeAssumeCapacityExtra(self: *Hideset, identifier: Identifier, next: Index, str: []const u8) Index {
    const next_idx = self.linked_list.len;
    self.linked_list.appendAssumeCapacity(.{ .identifier = identifier, .next = next, .str = str });
    return @enumFromInt(next_idx);
}

/// Create a new list with `identifier` at the front followed by `tail`
pub fn prepend(self: *Hideset, loc: Source.Location, str: []const u8, tail: Index) !Index {
    const new_idx = self.linked_list.len;
    try self.linked_list.append(self.gpa, .{ .identifier = Identifier.fromLocation(loc), .next = tail, .str = str });
    return @enumFromInt(new_idx);
}

/// Attach elements of `b` to the front of `a` (if they're not in `a`)
pub fn @"union"(self: *Hideset, a: Index, b: Index) !Index {
    if (a == .none) return b;
    if (b == .none) return a;
    self.tmp_map.clearRetainingCapacity();

    var it = self.iterator(b);
    while (it.next()) |item| {
        try self.tmp_map.put(self.gpa, item.identifier, {});
    }

    var head: Index = b;
    try self.ensureUnusedCapacity(self.len(a));
    it = self.iterator(a);
    while (it.next()) |item| {
        if (!self.tmp_map.contains(item.identifier)) {
            head = self.createNodeAssumeCapacityExtra(item.identifier, head, item.str);
        }
    }
    return head;
}

pub fn contains(self: *const Hideset, list: Index, str: []const u8) bool {
    var it = self.iterator(list);
    while (it.next()) |item| {
        if (mem.eql(u8, str, item.str)) return true;
    }
    return false;
}

fn len(self: *const Hideset, list: Index) usize {
    const nexts = self.linked_list.items(.next);
    var cur = list;
    var count: usize = 0;
    while (cur != .none) : (count += 1) {
        cur = nexts[@intFromEnum(cur)];
    }
    return count;
}

pub fn intersection(self: *Hideset, a: Index, b: Index) !Index {
    if (a == .none or b == .none) return .none;
    self.tmp_map.clearRetainingCapacity();

    var cur: Index = .none;
    var head: Index = .none;
    var it = self.iterator(a);
    var a_len: usize = 0;
    while (it.next()) |item| : (a_len += 1) {
        try self.tmp_map.put(self.gpa, item.identifier, {});
    }
    try self.ensureUnusedCapacity(@min(a_len, self.len(b)));

    it = self.iterator(b);
    while (it.next()) |item| {
        if (self.tmp_map.contains(item.identifier)) {
            const new_idx = self.createNodeAssumeCapacity(item.identifier, item.str);
            if (head == .none) {
                head = new_idx;
            }
            if (cur != .none) {
                self.linked_list.items(.next)[@intFromEnum(cur)] = new_idx;
            }
            cur = new_idx;
        }
    }
    return head;
}
