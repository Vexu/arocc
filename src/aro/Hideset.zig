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

const LangOpts = @import("LangOpts.zig");
const SourceManager = @import("SourceManager.zig");
const Tokenizer = @import("Tokenizer.zig");

pub const Hideset = @This();

const Identifier = struct {
    id: SourceManager.Source.Id = .unused,
    byte_offset: u32 = 0,

    fn slice(self: Identifier, sm: *const SourceManager, langopts: LangOpts) []const u8 {
        var tmp_tokenizer = Tokenizer{
            .buf = self.id.get(sm).buf,
            .langopts = langopts,
            .index = self.byte_offset,
            .source = .generated,
        };
        const res = tmp_tokenizer.next();
        return tmp_tokenizer.buf[res.start..res.end];
    }

    fn fromLocation(loc: SourceManager.Location) Identifier {
        return .{
            .id = loc.id,
            .byte_offset = loc.byte_offset,
        };
    }
};

const Item = struct {
    identifier: Identifier = .{},
    next: Index = .none,

    const List = std.MultiArrayList(Item);
};

pub const Index = enum(u32) {
    none = std.math.maxInt(u32),
    _,
};

map: std.AutoHashMapUnmanaged(Identifier, Index) = .empty,
/// Used for computing union/intersection of two lists; stored here so that allocations can be retained
/// until hideset is deinit'ed
tmp_map: std.AutoHashMapUnmanaged(Identifier, void) = .empty,
linked_list: Item.List = .empty,

/// Invalidated if the underlying MultiArrayList slice is reallocated due to resize
const Iterator = struct {
    slice: Item.List.Slice,
    i: Index,

    fn next(self: *Iterator) ?Identifier {
        if (self.i == .none) return null;
        defer self.i = self.slice.items(.next)[@intFromEnum(self.i)];
        return self.slice.items(.identifier)[@intFromEnum(self.i)];
    }
};

pub fn deinit(self: *Hideset, gpa: mem.Allocator) void {
    self.map.deinit(gpa);
    self.tmp_map.deinit(gpa);
    self.linked_list.deinit(gpa);
    self.* = undefined;
}

pub fn clearRetainingCapacity(self: *Hideset) void {
    self.linked_list.shrinkRetainingCapacity(0);
    self.map.clearRetainingCapacity();
}

pub fn clearAndFree(self: *Hideset, gpa: mem.Allocator) void {
    self.map.clearAndFree(gpa);
    self.tmp_map.clearAndFree(gpa);
    self.linked_list.shrinkAndFree(gpa, 0);
}

/// Iterator is invalidated if the underlying MultiArrayList slice is reallocated due to resize
fn iterator(self: *const Hideset, idx: Index) Iterator {
    return .{
        .slice = self.linked_list.slice(),
        .i = idx,
    };
}

pub fn get(self: *const Hideset, loc: SourceManager.Location) Index {
    return self.map.get(Identifier.fromLocation(loc)) orelse .none;
}

pub fn put(self: *Hideset, gpa: Allocator, loc: SourceManager.Location, value: Index) !void {
    try self.map.put(gpa, Identifier.fromLocation(loc), value);
}

fn ensureUnusedCapacity(self: *Hideset, gpa: Allocator, new_size: usize) !void {
    try self.linked_list.ensureUnusedCapacity(gpa, new_size);
}

/// Creates a one-item list with contents `identifier`
fn createNodeAssumeCapacity(self: *Hideset, identifier: Identifier) Index {
    return self.createNodeAssumeCapacityExtra(identifier, .none);
}

/// Creates a one-item list with contents `identifier`
fn createNodeAssumeCapacityExtra(self: *Hideset, identifier: Identifier, next: Index) Index {
    const next_idx = self.linked_list.len;
    self.linked_list.appendAssumeCapacity(.{ .identifier = identifier, .next = next });
    return @enumFromInt(next_idx);
}

/// Create a new list with `identifier` at the front followed by `tail`
pub fn prepend(self: *Hideset, gpa: Allocator, loc: SourceManager.Location, tail: Index) !Index {
    const new_idx = self.linked_list.len;
    try self.linked_list.append(gpa, .{ .identifier = Identifier.fromLocation(loc), .next = tail });
    return @enumFromInt(new_idx);
}

/// Attach elements of `b` to the front of `a` (if they're not in `a`)
pub fn @"union"(self: *Hideset, gpa: mem.Allocator, a: Index, b: Index) !Index {
    if (a == .none) return b;
    if (b == .none) return a;
    self.tmp_map.clearRetainingCapacity();

    var it = self.iterator(b);
    while (it.next()) |identifier| {
        try self.tmp_map.put(gpa, identifier, {});
    }

    var head: Index = b;
    try self.ensureUnusedCapacity(gpa, self.len(a));
    it = self.iterator(a);
    while (it.next()) |identifier| {
        if (!self.tmp_map.contains(identifier)) {
            head = self.createNodeAssumeCapacityExtra(identifier, head);
        }
    }
    return head;
}

pub fn contains(self: *const Hideset, sm: *const SourceManager, langopts: LangOpts, list: Index, str: []const u8) bool {
    var it = self.iterator(list);
    while (it.next()) |identifier| {
        if (mem.eql(u8, str, identifier.slice(sm, langopts))) return true;
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

pub fn intersection(self: *Hideset, gpa: Allocator, a: Index, b: Index) !Index {
    if (a == .none or b == .none) return .none;
    self.tmp_map.clearRetainingCapacity();

    var cur: Index = .none;
    var head: Index = .none;
    var it = self.iterator(a);
    var a_len: usize = 0;
    while (it.next()) |identifier| : (a_len += 1) {
        try self.tmp_map.put(gpa, identifier, {});
    }
    try self.ensureUnusedCapacity(gpa, @min(a_len, self.len(b)));

    it = self.iterator(b);
    while (it.next()) |identifier| {
        if (self.tmp_map.contains(identifier)) {
            const new_idx = self.createNodeAssumeCapacity(identifier);
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
