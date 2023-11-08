const Interner = @This();
const std = @import("std");
const Allocator = std.mem.Allocator;
const assert = std.debug.assert;
const BigIntConst = std.math.big.int.Const;
const BigIntMutable = std.math.big.int.Mutable;
const Hash = std.hash.Wyhash;

map: std.AutoArrayHashMapUnmanaged(void, void) = .{},
items: std.MultiArrayList(struct {
    tag: Tag,
    data: u32,
}) = .{},
extra: std.ArrayListUnmanaged(u32) = .{},
strings: std.ArrayListUnmanaged(u8),

const KeyAdapter = struct {
    interner: *const Interner,

    pub fn eql(adapter: KeyAdapter, a: Key, b_void: void, b_map_index: usize) bool {
        _ = b_void;
        return adapter.interner.get(@as(Ref, @enumFromInt(b_map_index))).eql(a);
    }

    pub fn hash(adapter: KeyAdapter, a: Key) u32 {
        _ = adapter;
        return a.hash();
    }
};

pub const Key = union(enum) {
    int_ty: u16,
    float_ty: u16,
    ptr_ty,
    noreturn_ty,
    void_ty,
    func_ty,
    array_ty: struct {
        len: u64,
        child: Ref,
    },
    vector_ty: struct {
        len: u32,
        child: Ref,
    },
    /// May not be zero
    null,
    int: union(enum) {
        u64: u64,
        i64: i64,
        big_int: BigIntConst,
    },
    float: union(enum) {
        f16: f16,
        f32: f32,
        f64: f64,
        f80: f80,
        f128: f128,
    },
    bytes: []const u8,
    record: struct {
        /// Pointer to user data, value used for hash and equality check.
        user_ptr: *anyopaque,
        elements: []const Ref,
    },

    pub fn hash(key: Key) u32 {
        var hasher = Hash.init(0);
        switch (key) {
            .bytes => |bytes| {
                const tag = std.meta.activeTag(key);
                std.hash.autoHash(&hasher, tag);
                std.hash.autoHash(&hasher, bytes);
            },
            .record => |info| {
                std.hash.autoHash(&hasher, @intFromPtr(info.user_ptr));
            },
            inline else => |info| {
                std.hash.autoHash(&hasher, info);
            },
        }
        return @truncate(hasher.final());
    }

    pub fn eql(a: Key, b: Key) bool {
        const KeyTag = std.meta.Tag(Key);
        const a_tag: KeyTag = a;
        const b_tag: KeyTag = b;
        if (a_tag != b_tag) return false;
        switch (a) {
            .record => |a_info| {
                return a_info.user_ptr == b.record.user_ptr;
            },
            .bytes => |a_bytes| {
                const b_bytes = b.bytes;
                return std.mem.eql(u8, a_bytes, b_bytes);
            },
            inline else => |a_info, tag| {
                const b_info = @field(b, @tagName(tag));
                return std.meta.eql(a_info, b_info);
            },
        }
    }

    fn toRef(key: Key) ?Ref {
        switch (key) {
            .int => |bits| switch (bits) {
                1 => return .i1,
                8 => return .i8,
                16 => return .i16,
                32 => return .i32,
                64 => return .i64,
                128 => return .i128,
                else => {},
            },
            .float => |bits| switch (bits) {
                16 => return .f16,
                32 => return .f32,
                64 => return .f64,
                80 => return .f80,
                128 => return .f128,
                else => unreachable,
            },
            .ptr => return .ptr,
            .func => return .func,
            .noreturn => return .noreturn,
            .void => return .void,
            .int => |int| switch (int) {
                inline .u64, .i64 => |u| switch (u) {
                    0 => return .zero,
                    1 => return .one,
                    else => {},
                },
                .big_int => {},
            },
            .null => return .null,
            else => {},
        }
        return null;
    }
};

pub const Ref = enum(u32) {
    ptr,
    noreturn,
    void,
    i1,
    i8,
    i16,
    i32,
    i64,
    i128,
    f16,
    f32,
    f64,
    f80,
    f128,
    func,
    zero,
    one,
    null,
    _,
};

pub const Tag = enum(u8) {
    /// `data` is `u16`
    int_ty,
    /// `data` is `u16`
    float_ty,
    /// `data` is index to `Array`
    array_ty,
    /// `data` is index to `Vector`
    vector_ty,
    /// `data` is `u32`
    int_u32,
    /// `data` is `i32`
    int_i32,
    /// `data` is `Int`
    int_positive,
    /// `data` is `Int`
    int_negative,
    /// `data` is `f16`
    f16,
    /// `data` is `f32`
    f32,
    /// `data` is `F64`
    f64,
    /// `data` is `F80`
    f80,
    /// `data` is `F128`
    f128,
    /// `data` is `Bytes`
    bytes,
    /// `data` is `Record`
    record,

    pub const Array = struct {
        len0: u32,
        len1: u32,
        child: Ref,

        pub fn getLength(a: Array) u64 {
            return (PackedU64{
                .a = a.len0,
                .b = a.len1,
            }).get();
        }
    };

    pub const Vector = struct {
        len: u32,
        child: Ref,
    };

    pub const Int = struct {
        limbs_len: u32,
        // trailing:
        // [limbs_len]struct { limb_hi: u32, limb_lo: u32}
    };

    pub const F64 = struct {
        piece0: u32,
        piece1: u32,

        pub fn get(self: F64) f64 {
            const int_bits = @as(u64, self.piece0) | (@as(u64, self.piece1) << 32);
            return @bitCast(int_bits);
        }

        fn pack(val: f64) F64 {
            const bits = @as(u64, @bitCast(val));
            return .{
                .piece0 = @as(u32, @truncate(bits)),
                .piece1 = @as(u32, @truncate(bits >> 32)),
            };
        }
    };

    pub const F80 = struct {
        piece0: u32,
        piece1: u32,
        piece2: u32, // u16 part, top bits

        pub fn get(self: F128) f80 {
            const int_bits = @as(u80, self.piece0) |
                (@as(u80, self.piece1) << 32) |
                (@as(u80, self.piece2) << 64);
            return @bitCast(int_bits);
        }

        fn pack(val: f80) F128 {
            const bits = @as(u80, @bitCast(val));
            return .{
                .piece0 = @as(u32, @truncate(bits)),
                .piece1 = @as(u32, @truncate(bits >> 32)),
                .piece2 = @as(u16, @truncate(bits >> 64)),
            };
        }
    };

    pub const F128 = struct {
        piece0: u32,
        piece1: u32,
        piece2: u32,
        piece3: u32,

        pub fn get(self: F128) f128 {
            const int_bits = @as(u128, self.piece0) |
                (@as(u128, self.piece1) << 32) |
                (@as(u128, self.piece2) << 64) |
                (@as(u128, self.piece3) << 96);
            return @bitCast(int_bits);
        }

        fn pack(val: f128) F128 {
            const bits = @as(u128, @bitCast(val));
            return .{
                .piece0 = @as(u32, @truncate(bits)),
                .piece1 = @as(u32, @truncate(bits >> 32)),
                .piece2 = @as(u32, @truncate(bits >> 64)),
                .piece3 = @as(u32, @truncate(bits >> 96)),
            };
        }
    };

    pub const Bytes = struct {
        bytes_index: u32,
        bytes_len: u32,
    };

    pub const Record = struct {
        ptr_hi: u32,
        ptr_lo: u32,
        elements_len: u32,
        // trailing
        // [elements_len]Ref
    };
};

pub const PackedU64 = packed struct(u64) {
    a: u32,
    b: u32,

    pub fn get(x: PackedU64) u64 {
        return @bitCast(x);
    }

    pub fn init(x: u64) PackedU64 {
        return @bitCast(x);
    }
};

pub fn deinit(i: *Interner, gpa: Allocator) void {
    i.map.deinit(gpa);
    i.items.deinit(gpa);
    i.extra.deinit(gpa);
    i.strings.deinit(gpa);
}

pub fn put(i: *Interner, gpa: Allocator, key: Key) !Ref {
    if (key.toRef()) |some| return some;
    const adapter: KeyAdapter = .{ .interner = i };
    const gop = try i.map.getOrPutAdapted(gpa, key, adapter);
    return @enumFromInt(gop.index);
}

pub fn has(ip: *Interner, key: Key) ?Ref {
    if (key.toRef()) |some| return some;
    if (ip.map.getIndex(key)) |index| {
        return @enumFromInt(index);
    }
    return null;
}

pub fn get(ip: Interner, ref: Ref) Key {
    switch (ref) {
        .ptr => return .ptr,
        .func => return .func,
        .noreturn => return .noreturn,
        .void => return .void,
        .i1 => return .{ .int = 1 },
        .i8 => return .{ .int = 8 },
        .i16 => return .{ .int = 16 },
        .i32 => return .{ .int = 32 },
        .i64 => return .{ .int = 64 },
        .i128 => return .{ .int = 128 },
        .f16 => return .{ .float = 16 },
        .f32 => return .{ .float = 32 },
        .f64 => return .{ .float = 64 },
        .f80 => return .{ .float = 80 },
        .f128 => return .{ .float = 128 },
        else => {},
    }
    return ip.map.keys()[@intFromEnum(ref)];
}
