const std = @import("std");
const mem = std.mem;
const Allocator = mem.Allocator;
const Source = @import("Source.zig");
const Compilation = @import("Compilation.zig");
const Tokenizer = @import("Tokenizer.zig");

pub const Hideset = @This();

const HashContext = struct {
    pub fn hash(ctx: HashContext, key: Identifier) u64 {
        _ = ctx;
        return std.hash.Wyhash.hash(0, std.mem.asBytes(&key));
    }
    pub fn eql(ctx: HashContext, a: Identifier, b: Identifier) bool {
        _ = ctx;
        return a.id == b.id and a.byte_offset == b.byte_offset;
    }
};

const Identifier = packed struct(u64) {
    id: Source.Id = .unused,
    byte_offset: u32 = 0,

    fn slice(self: Identifier, comp: *const Compilation) []const u8 {
        var tmp_tokenizer = Tokenizer{
            .buf = comp.getSource(self.id).buf,
            .langopts = comp.langopts,
            .index = self.byte_offset,
            .source = .generated,
        };
        const res = tmp_tokenizer.next();
        return tmp_tokenizer.buf[res.start..res.end];
    }
};

const Item = struct {
    name: Identifier = .{},
    next: Index = .sentinel,

    const List = std.MultiArrayList(Item);
};

const Index = enum(u32) {
    sentinel = std.math.maxInt(u32),
    _,
};

map: std.HashMapUnmanaged(Identifier, Index, HashContext, std.hash_map.default_max_load_percentage) = .{},
intersection_map: std.StringHashMapUnmanaged(void) = .{},
linked_list: Item.List = .{},
next_idx: Index = @enumFromInt(0),
comp: *const Compilation,

const Iterator = struct {
    slice: Item.List.Slice,
    i: Index,

    fn next(self: *Iterator) ?Identifier {
        if (self.i == .sentinel) return null;
        defer self.i = self.slice.items(.next)[@intFromEnum(self.i)];
        return self.slice.items(.name)[@intFromEnum(self.i)];
    }
};

pub fn init(comp: *const Compilation) Hideset {
    return Hideset{
        .comp = comp,
    };
}

pub fn deinit(self: *Hideset) void {
    self.map.deinit(self.comp.gpa);
    self.intersection_map.deinit(self.comp.gpa);
    self.linked_list.deinit(self.comp.gpa);
}

pub fn clearRetainingCapacity(self: *Hideset) void {
    self.next_idx = @enumFromInt(0);
    self.map.clearRetainingCapacity();
}

pub fn iterator(self: *const Hideset, idx: Index) Iterator {
    return Iterator{
        .slice = self.linked_list.slice(),
        .i = idx,
    };
}

pub fn get(self: *const Hideset, name: Identifier) Index {
    return self.map.get(name) orelse .sentinel;
}

pub fn put(self: *Hideset, key: Identifier, value: Index) !void {
    try self.map.put(self.comp.gpa, key, value);
}

pub fn ensureTotalCapacity(self: *Hideset, new_size: usize) !void {
    try self.linked_list.ensureTotalCapacity(self.comp.gpa, new_size);
}

/// Allocates a new item and returns its index
fn allocate(self: *Hideset, name: Identifier) !Index {
    const next: Index = if (@intFromEnum(self.next_idx) < self.linked_list.len) self.next_idx else blk: {
        const new_item_idx = try self.linked_list.addOne(self.comp.gpa);
        break :blk @enumFromInt(new_item_idx);
    };
    self.next_idx = @enumFromInt(@intFromEnum(next) + 1);
    self.linked_list.set(@intFromEnum(next), .{ .name = name });
    return next;
}

/// Create a new list with `name` at the front followed by `tail`
pub fn prepend(self: *Hideset, name: Identifier, tail: Index) !Index {
    const new_idx = try self.allocate(name);
    self.linked_list.items(.next)[@intFromEnum(new_idx)] = tail;
    return new_idx;
}

/// Copy a, then attach b at the end
pub fn @"union"(self: *Hideset, a: Index, b: Index) !Index {
    var cur: Index = .sentinel;
    var head: Index = b;
    var it = self.iterator(a);
    while (it.next()) |name| {
        const new_idx = try self.allocate(name);
        if (head == b) {
            head = new_idx;
        }
        if (cur != .sentinel) {
            self.linked_list.items(.next)[@intFromEnum(cur)] = new_idx;
        }
        cur = new_idx;
    }
    if (cur != .sentinel) {
        self.linked_list.items(.next)[@intFromEnum(cur)] = b;
    }
    return head;
}

pub fn contains(self: *const Hideset, list: Index, name: []const u8) bool {
    var it = self.iterator(list);
    while (it.next()) |item_name| {
        const this = item_name.slice(self.comp);
        if (mem.eql(u8, name, this)) return true;
    }
    return false;
}

pub fn intersection(self: *Hideset, a: Index, b: Index) !Index {
    if (a == .sentinel or b == .sentinel) return .sentinel;
    self.intersection_map.clearRetainingCapacity();

    var cur: Index = .sentinel;
    var head: Index = .sentinel;
    var it = self.iterator(a);
    while (it.next()) |name| {
        const str = name.slice(self.comp);
        try self.intersection_map.put(self.comp.gpa, str, {});
    }
    it = self.iterator(b);
    while (it.next()) |name| {
        const str = name.slice(self.comp);
        if (self.intersection_map.contains(str)) {
            const new_idx = try self.allocate(name);
            if (head == .sentinel) {
                head = new_idx;
            }
            if (cur != .sentinel) {
                self.linked_list.items(.next)[@intFromEnum(cur)] = new_idx;
            }
            cur = new_idx;
        }
    }
    return head;
}
