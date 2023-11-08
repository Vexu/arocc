const std = @import("std");
const assert = std.debug.assert;
const Compilation = @import("Compilation.zig");
const Type = @import("Type.zig");
const Interner = @import("Interner.zig");
const BigIntSpace = Interner.Tag.Int.BigIntSpace;
const BigIntConst = std.math.big.int.Const;
const BigIntMutable = std.math.big.int.Mutable;

const Value = @This();

pub const Context = struct {
    interner: *const Interner,
    comp: *const Compilation,
    mutable: if (std.debug.runtime_safety) bool else void =
        if (std.debug.runtime_safety) false else {},

    pub fn intern(ctx: Context, k: Interner.Key) !Value {
        if (std.debug.runtime_safety) assert(ctx.mutable);
        const r = try @constCast(ctx.interner).put(ctx.comp.gpa, k);
        return .{ .opt_ref = @enumFromInt(@intFromEnum(r)) };
    }
};

pub const ByteRange = struct {
    start: u32,
    end: u32,

    pub fn len(self: ByteRange) u32 {
        return self.end - self.start;
    }

    pub fn trim(self: ByteRange, amount: u32) ByteRange {
        std.debug.assert(self.start <= self.end - amount);
        return .{ .start = self.start, .end = self.end - amount };
    }

    pub fn slice(self: ByteRange, all_bytes: []const u8, comptime size: Compilation.CharUnitSize) []const size.Type() {
        switch (size) {
            inline else => |sz| {
                const aligned: []align(@alignOf(sz.Type())) const u8 = @alignCast(all_bytes[self.start..self.end]);
                return std.mem.bytesAsSlice(sz.Type(), aligned);
            },
        }
    }

    pub fn dumpString(range: ByteRange, ty: Type, comp: *const Compilation, strings: []const u8, w: anytype) !void {
        const size: Compilation.CharUnitSize = @enumFromInt(ty.elemType().sizeof(comp).?);
        const without_null = range.trim(@intFromEnum(size));
        switch (size) {
            inline .@"1", .@"2" => |sz| {
                const data_slice = without_null.slice(strings, sz);
                const formatter = if (sz == .@"1") std.zig.fmtEscapes(data_slice) else std.unicode.fmtUtf16le(data_slice);
                try w.print("\"{}\"", .{formatter});
            },
            .@"4" => {
                try w.writeByte('"');
                const data_slice = without_null.slice(strings, .@"4");
                var buf: [4]u8 = undefined;
                for (data_slice) |item| {
                    if (item <= std.math.maxInt(u21) and std.unicode.utf8ValidCodepoint(@intCast(item))) {
                        const codepoint: u21 = @intCast(item);
                        const written = std.unicode.utf8Encode(codepoint, &buf) catch unreachable;
                        try w.print("{s}", .{buf[0..written]});
                    } else {
                        try w.print("\\x{x}", .{item});
                    }
                }
                try w.writeByte('"');
            },
        }
    }
};

pub const OptRef = enum(u32) {
    none = std.math.maxInt(u32),
    _,
};

opt_ref: OptRef = .none,

tag: Tag = .unavailable,
data: union {
    none: void,
    int: u64,
    float: f64,
    bytes: ByteRange,
} = .{ .none = {} },

const Tag = enum {
    unavailable,
    nullptr_t,
    /// int is used to store integer, boolean and pointer values
    int,
    float,
    bytes,
};

pub const zero = Value{ .opt_ref = @enumFromInt(@intFromEnum(Interner.Ref.zero)) };
pub const one = Value{ .opt_ref = @enumFromInt(@intFromEnum(Interner.Ref.zero)) };

pub fn ref(v: Value) Interner.Ref {
    std.debug.assert(v.opt_ref != .none);
    return @enumFromInt(@intFromEnum(v.opt_ref));
}

/// Number of bits needed to hold `v`.
/// Asserts that `v` is not negative
pub fn minUnsignedBits(v: Value, ctx: Context) usize {
    var space: BigIntSpace = undefined;
    const big = v.toBigInt(&space, ctx);
    assert(big.positive);
    return big.bitCountAbs();
}

test "minUnsignedBits" {
    const Test = struct {
        fn checkIntBits(ctx: Context, v: u64, expected: usize) !void {
            const val = try ctx.intern(.{ .int = .{ .u64 = v } });
            try std.testing.expectEqual(expected, val.minUnsignedBits(ctx));
        }
    };

    var comp = Compilation.init(std.testing.allocator);
    defer comp.deinit();
    comp.target = (try std.zig.CrossTarget.parse(.{ .arch_os_abi = "x86_64-linux-gnu" })).toTarget();
    var interner: Interner = .{};
    defer interner.deinit(comp.gpa);
    var ctx: Context = .{
        .comp = &comp,
        .interner = &interner,
        .mutable = if (std.debug.runtime_safety) true else {},
    };

    try Test.checkIntBits(ctx, .int, 0, 0);
    try Test.checkIntBits(ctx, .int, 1, 1);
    try Test.checkIntBits(ctx, .int, 2, 2);
    try Test.checkIntBits(ctx, .int, std.math.maxInt(i8), 7);
    try Test.checkIntBits(ctx, .int, std.math.maxInt(u8), 8);
    try Test.checkIntBits(ctx, .int, std.math.maxInt(i16), 15);
    try Test.checkIntBits(ctx, .int, std.math.maxInt(u16), 16);
    try Test.checkIntBits(ctx, .int, std.math.maxInt(i32), 31);
    try Test.checkIntBits(ctx, .uint, std.math.maxInt(u32), 32);
    try Test.checkIntBits(ctx, .long, std.math.maxInt(i64), 63);
    try Test.checkIntBits(ctx, .ulong, std.math.maxInt(u64), 64);
    try Test.checkIntBits(ctx, .long_long, std.math.maxInt(i64), 63);
    try Test.checkIntBits(ctx, .ulong_long, std.math.maxInt(u64), 64);
}

/// Minimum number of bits needed to represent `v` in 2's complement notation
/// Asserts that `v` is negative.
pub fn minSignedBits(v: Value, ctx: Context) usize {
    var space: BigIntSpace = undefined;
    const big = v.toBigInt(&space, ctx);
    assert(!big.positive);
    return big.bitCountTwosComp();
}

test "minSignedBits" {
    const Test = struct {
        fn checkIntBits(ctx: Context, v: i64, expected: usize) !void {
            const val = try ctx.intern(.{ .int = .{ .i64 = v } });
            try std.testing.expectEqual(expected, val.minSignedBits(ctx));
        }
    };

    var comp = Compilation.init(std.testing.allocator);
    defer comp.deinit();
    comp.target = (try std.zig.CrossTarget.parse(.{ .arch_os_abi = "x86_64-linux-gnu" })).toTarget();
    var interner: Interner = .{};
    defer interner.deinit(comp.gpa);
    var ctx: Context = .{
        .comp = &comp,
        .interner = &interner,
        .mutable = if (std.debug.runtime_safety) true else {},
    };

    try Test.checkIntBits(ctx, -1, 1);
    try Test.checkIntBits(ctx, -2, 2);
    try Test.checkIntBits(ctx, -10, 5);
    try Test.checkIntBits(ctx, -101, 8);
    try Test.checkIntBits(ctx, std.math.minInt(i8), 8);
    try Test.checkIntBits(ctx, std.math.minInt(i16), 16);
    try Test.checkIntBits(ctx, std.math.minInt(i32), 32);
    try Test.checkIntBits(ctx, std.math.minInt(i64), 64);
}

pub const FloatToIntChangeKind = enum {
    /// value did not change
    none,
    /// floating point number too small or large for destination integer type
    out_of_range,
    /// tried to convert a NaN or Infinity
    overflow,
    /// fractional value was converted to zero
    nonzero_to_zero,
    /// fractional part truncated
    value_changed,
};

fn floatToIntExtra(comptime FloatTy: type, int_ty_signedness: std.builtin.Signedness, int_ty_size: u16, v: *Value) FloatToIntChangeKind {
    const float_val = v.getFloat(FloatTy);
    const was_zero = float_val == 0;
    const had_fraction = std.math.modf(float_val).fpart != 0;

    switch (int_ty_signedness) {
        inline else => |signedness| switch (int_ty_size) {
            inline 1, 2, 4, 8 => |bytecount| {
                const IntTy = std.meta.Int(signedness, bytecount * 8);

                const intVal = std.math.lossyCast(IntTy, float_val);
                v.* = int(intVal);
                if (!was_zero and v.isZero()) return .nonzero_to_zero;
                if (float_val <= std.math.minInt(IntTy) or float_val >= std.math.maxInt(IntTy)) return .out_of_range;
                if (had_fraction) return .value_changed;
                return .none;
            },
            else => unreachable,
        },
    }
}

/// Converts the stored value from a float to an integer.
/// `.unavailable` value remains unchanged.
pub fn floatToInt(v: *Value, old_ty: Type, new_ty: Type, comp: *Compilation) FloatToIntChangeKind {
    assert(old_ty.isFloat());
    if (v.tag == .unavailable) return .none;
    if (new_ty.is(.bool)) {
        const was_zero = v.isZero();
        const was_one = v.getFloat(f64) == 1.0;
        v.toBool();
        if (was_zero or was_one) return .none;
        return .value_changed;
    } else if (new_ty.isUnsignedInt(comp) and v.data.float < 0) {
        v.* = int(0);
        return .out_of_range;
    } else if (!std.math.isFinite(v.data.float)) {
        v.tag = .unavailable;
        return .overflow;
    }
    const old_size = old_ty.sizeof(comp).?;
    const new_size: u16 = @intCast(new_ty.sizeof(comp).?);
    if (new_ty.isUnsignedInt(comp)) switch (old_size) {
        1 => unreachable, // promoted to int
        2 => unreachable, // promoted to int
        4 => return floatToIntExtra(f32, .unsigned, new_size, v),
        8 => return floatToIntExtra(f64, .unsigned, new_size, v),
        else => unreachable,
    } else switch (old_size) {
        1 => unreachable, // promoted to int
        2 => unreachable, // promoted to int
        4 => return floatToIntExtra(f32, .signed, new_size, v),
        8 => return floatToIntExtra(f64, .signed, new_size, v),
        else => unreachable,
    }
}

/// Converts the stored value from an integer to a float.
/// `.none` value remains unchanged.
pub fn intToFloat(v: *Value, dest_ty: Type, ctx: Context) !void {
    if (v.opt_ref == .none) return;
    const bits = dest_ty.bitSizeof(ctx.comp).?;
    return switch (ctx.interner.get(v.ref()).int) {
        inline .u64, .i64 => |data| {
            const f: Interner.Key.Float = switch (bits) {
                16 => .{ .f16 = @floatFromInt(data) },
                32 => .{ .f32 = @floatFromInt(data) },
                64 => .{ .f64 = @floatFromInt(data) },
                80 => .{ .f80 = @floatFromInt(data) },
                128 => .{ .f128 = @floatFromInt(data) },
                else => unreachable,
            };
            v.* = try ctx.intern(.{ .float = f });
        },
        .big_int => |data| {
            const big_f = bigIntToFloat(data.limbs, data.positive);
            const f: Interner.Key.Float = switch (bits) {
                16 => .{ .f16 = @floatCast(big_f) },
                32 => .{ .f32 = @floatCast(big_f) },
                64 => .{ .f64 = @floatCast(big_f) },
                80 => .{ .f80 = @floatCast(big_f) },
                128 => .{ .f128 = @floatCast(big_f) },
                else => unreachable,
            };
            v.* = try ctx.intern(.{ .float = f });
        },
    };
}

/// Truncates or extends bits based on type.
/// old_ty is only used for size.
pub fn intCast(v: *Value, old_ty: Type, new_ty: Type, comp: *Compilation) void {
    // assert(old_ty.isInt() and new_ty.isInt());
    if (v.tag == .unavailable) return;
    if (new_ty.is(.bool)) return v.toBool();
    if (!old_ty.isUnsignedInt(comp)) {
        const size = new_ty.sizeof(comp).?;
        switch (size) {
            1 => v.* = int(@as(u8, @truncate(@as(u64, @bitCast(v.signExtend(old_ty, comp)))))),
            2 => v.* = int(@as(u16, @truncate(@as(u64, @bitCast(v.signExtend(old_ty, comp)))))),
            4 => v.* = int(@as(u32, @truncate(@as(u64, @bitCast(v.signExtend(old_ty, comp)))))),
            8 => return,
            else => unreachable,
        }
    }
}

/// Converts the stored value from an integer to a float.
/// `.unavailable` value remains unchanged.
pub fn floatCast(v: *Value, old_ty: Type, new_ty: Type, comp: *Compilation) void {
    assert(old_ty.isFloat() and new_ty.isFloat());
    if (v.tag == .unavailable) return;
    const size = new_ty.sizeof(comp).?;
    if (!new_ty.isReal() or size > 8) {
        v.tag = .unavailable;
    } else if (size == 32) {
        v.* = float(@as(f32, @floatCast(v.data.float)));
    }
}

pub fn toFloat(v: Value, comptime T: type, ctx: Context) T {
    return switch (ctx.interner.get(v.ref())) {
        .int => |repr| switch (repr) {
            inline .u64, .i64 => |data| @floatFromInt(data),
            .big_int => |data| @floatCast(bigIntToFloat(data.limbs, data.positive)),
        },
        .float => |repr| switch (repr) {
            inline else => |data| @floatCast(data),
        },
        else => unreachable,
    };
}

fn bigIntToFloat(limbs: []const std.math.big.Limb, positive: bool) f128 {
    if (limbs.len == 0) return 0;

    const base = std.math.maxInt(std.math.big.Limb) + 1;
    var result: f128 = 0;
    var i: usize = limbs.len;
    while (i != 0) {
        i -= 1;
        const limb: f128 = @as(f128, @floatFromInt(limbs[i]));
        result = @mulAdd(f128, base, result, limb);
    }
    if (positive) {
        return result;
    } else {
        return -result;
    }
}

pub fn toBigInt(val: Value, space: *BigIntSpace, ctx: Context) BigIntConst {
    return switch (ctx.interner.get(val.ref()).int) {
        inline .u64, .i64 => |x| BigIntMutable.init(&space.limbs, x).toConst(),
        .big_int => |b| b,
    };
}

pub fn isZero(v: Value) bool {
    return v.ref() == .zero;
}

/// Converts value to zero or one;
pub fn boolCast(v: *Value) void {
    v.* = fromBool(v.toBool());
}

pub fn fromBool(b: bool) Value {
    return if (b) one else zero;
}

pub fn toBool(v: Value) bool {
    return v.ref() != .zero;
}

pub fn add(res: *Value, lhs: Value, rhs: Value, ty: Type, ctx: Context) !bool {
    const bits = ty.bitSizeof(ctx.comp).?;
    if (ty.isFloat()) {
        const f: Interner.Key.Float = switch (bits) {
            16 => .{ .f16 = lhs.toFloat(f16, ctx) + rhs.toFloat(f16, ctx) },
            32 => .{ .f32 = lhs.toFloat(f32, ctx) + rhs.toFloat(f32, ctx) },
            64 => .{ .f64 = lhs.toFloat(f64, ctx) + rhs.toFloat(f64, ctx) },
            80 => .{ .f80 = lhs.toFloat(f80, ctx) + rhs.toFloat(f80, ctx) },
            128 => .{ .f128 = lhs.toFloat(f128, ctx) + rhs.toFloat(f128, ctx) },
            else => unreachable,
        };
        res.* = try ctx.intern(.{ .float = f });
        return false;
    } else {
        var lhs_space: BigIntSpace = undefined;
        var rhs_space: BigIntSpace = undefined;
        const lhs_bigint = lhs.toBigInt(&lhs_space, ctx);
        const rhs_bigint = rhs.toBigInt(&rhs_space, ctx);

        const limbs = try ctx.comp.gpa.alloc(
            std.math.big.Limb,
            std.math.big.int.calcTwosCompLimbCount(bits),
        );
        defer ctx.comp.gpa.free(limbs);
        var result_bigint = std.math.big.int.Mutable{ .limbs = limbs, .positive = undefined, .len = undefined };

        const overflowed = result_bigint.addWrap(lhs_bigint, rhs_bigint, ty.signedness(ctx.comp), bits);
        res.* = try ctx.intern(.{ .int = .{ .big_int = result_bigint.toConst() } });
        return overflowed;
    }
}

pub fn sub(res: *Value, lhs: Value, rhs: Value, ty: Type, ctx: Context) !bool {
    const bits = ty.bitSizeof(ctx.comp).?;
    if (ty.isFloat()) {
        const f: Interner.Key.Float = switch (bits) {
            16 => .{ .f16 = lhs.toFloat(f16, ctx) - rhs.toFloat(f16, ctx) },
            32 => .{ .f32 = lhs.toFloat(f32, ctx) - rhs.toFloat(f32, ctx) },
            64 => .{ .f64 = lhs.toFloat(f64, ctx) - rhs.toFloat(f64, ctx) },
            80 => .{ .f80 = lhs.toFloat(f80, ctx) - rhs.toFloat(f80, ctx) },
            128 => .{ .f128 = lhs.toFloat(f128, ctx) - rhs.toFloat(f128, ctx) },
            else => unreachable,
        };
        res.* = try ctx.intern(.{ .float = f });
        return false;
    } else {
        var lhs_space: BigIntSpace = undefined;
        var rhs_space: BigIntSpace = undefined;
        const lhs_bigint = lhs.toBigInt(&lhs_space, ctx);
        const rhs_bigint = rhs.toBigInt(&rhs_space, ctx);

        const limbs = try ctx.comp.gpa.alloc(
            std.math.big.Limb,
            std.math.big.int.calcTwosCompLimbCount(bits),
        );
        defer ctx.comp.gpa.free(limbs);
        var result_bigint = std.math.big.int.Mutable{ .limbs = limbs, .positive = undefined, .len = undefined };

        const overflowed = result_bigint.subWrap(lhs_bigint, rhs_bigint, ty.signedness(ctx.comp), bits);
        res.* = try ctx.intern(.{ .int = .{ .big_int = result_bigint.toConst() } });
        return overflowed;
    }
}

pub fn mul(res: *Value, lhs: Value, rhs: Value, ty: Type, ctx: Context) !bool {
    const bits = ty.bitSizeof(ctx.comp).?;
    if (ty.isFloat()) {
        const f: Interner.Key.Float = switch (bits) {
            16 => .{ .f16 = lhs.toFloat(f16, ctx) * rhs.toFloat(f16, ctx) },
            32 => .{ .f32 = lhs.toFloat(f32, ctx) * rhs.toFloat(f32, ctx) },
            64 => .{ .f64 = lhs.toFloat(f64, ctx) * rhs.toFloat(f64, ctx) },
            80 => .{ .f80 = lhs.toFloat(f80, ctx) * rhs.toFloat(f80, ctx) },
            128 => .{ .f128 = lhs.toFloat(f128, ctx) * rhs.toFloat(f128, ctx) },
            else => unreachable,
        };
        res.* = try ctx.intern(.{ .float = f });
        return false;
    } else {
        var lhs_space: BigIntSpace = undefined;
        var rhs_space: BigIntSpace = undefined;
        const lhs_bigint = lhs.toBigInt(&lhs_space, ctx);
        const rhs_bigint = rhs.toBigInt(&rhs_space, ctx);

        const limbs = try ctx.comp.gpa.alloc(
            std.math.big.Limb,
            lhs_bigint.limbs.len + rhs_bigint.limbs.len,
        );
        defer ctx.comp.gpa.free(limbs);
        var result_bigint = BigIntMutable{ .limbs = limbs, .positive = undefined, .len = undefined };

        var limbs_buffer = try ctx.comp.gpa.alloc(
            std.math.big.Limb,
            std.math.big.int.calcMulLimbsBufferLen(lhs_bigint.limbs.len, rhs_bigint.limbs.len, 1),
        );
        defer ctx.comp.gpa.free(limbs_buffer);

        result_bigint.mul(lhs_bigint, rhs_bigint, limbs_buffer, ctx.comp.gpa);

        const signedness = ty.signedness(ctx.comp);
        const overflowed = !result_bigint.toConst().fitsInTwosComp(signedness, bits);
        if (overflowed) {
            result_bigint.truncate(result_bigint.toConst(), signedness, bits);
        }
        res.* = try ctx.intern(.{ .int = .{ .big_int = result_bigint.toConst() } });
        return overflowed;
    }
}

/// caller guarantees rhs != 0
pub fn div(res: *Value, lhs: Value, rhs: Value, ty: Type, ctx: Context) !bool {
    const bits = ty.bitSizeof(ctx.comp).?;
    if (ty.isFloat()) {
        const f: Interner.Key.Float = switch (bits) {
            16 => .{ .f16 = lhs.toFloat(f16, ctx) / rhs.toFloat(f16, ctx) },
            32 => .{ .f32 = lhs.toFloat(f32, ctx) / rhs.toFloat(f32, ctx) },
            64 => .{ .f64 = lhs.toFloat(f64, ctx) / rhs.toFloat(f64, ctx) },
            80 => .{ .f80 = lhs.toFloat(f80, ctx) / rhs.toFloat(f80, ctx) },
            128 => .{ .f128 = lhs.toFloat(f128, ctx) / rhs.toFloat(f128, ctx) },
            else => unreachable,
        };
        res.* = try ctx.intern(.{ .float = f });
        return false;
    } else {
        var lhs_space: BigIntSpace = undefined;
        var rhs_space: BigIntSpace = undefined;
        const lhs_bigint = lhs.toBigInt(&lhs_space, ctx);
        const rhs_bigint = rhs.toBigInt(&rhs_space, ctx);

        const limbs = try ctx.comp.gpa.alloc(
            std.math.big.Limb,
            lhs_bigint.limbs.len + rhs_bigint.limbs.len,
        );
        defer ctx.comp.gpa.free(limbs);
        var result_bigint = BigIntMutable{ .limbs = limbs, .positive = undefined, .len = undefined };

        const limbs_q = try ctx.comp.gpa.alloc(
            std.math.big.Limb,
            lhs_bigint.limbs.len,
        );
        defer ctx.comp.gpa.free(limbs_q);
        var result_q = BigIntMutable{ .limbs = limbs_q, .positive = undefined, .len = undefined };

        const limbs_r = try ctx.comp.gpa.alloc(
            std.math.big.Limb,
            rhs_bigint.limbs.len,
        );
        defer ctx.comp.gpa.free(limbs_r);
        var result_r = BigIntMutable{ .limbs = limbs_r, .positive = undefined, .len = undefined };

        const limbs_buffer = try ctx.comp.gpa.alloc(
            std.math.big.Limb,
            std.math.big.int.calcDivLimbsBufferLen(lhs_bigint.limbs.len, rhs_bigint.limbs.len),
        );
        defer ctx.comp.gpa.free(limbs_buffer);

        result_q.divTrunc(&result_r, lhs_bigint, rhs_bigint, limbs_buffer);

        res.* = try ctx.intern(.{ .int = .{ .big_int = result_bigint.toConst() } });
        return !result_q.toConst().fitsInTwosComp(ty.signedness(ctx.comp), bits);
    }
}

/// caller guarantees rhs != 0
/// caller guarantees lhs != std.math.minInt(T) OR rhs != -1

pub fn bitOr(lhs: Value, rhs: Value, ctx: Context) !Value {
    var lhs_space: BigIntSpace = undefined;
    var rhs_space: BigIntSpace = undefined;
    const lhs_bigint = lhs.toBigInt(&lhs_space, ctx);
    const rhs_bigint = rhs.toBigInt(&rhs_space, ctx);

    const limbs = try ctx.comp.gpa.alloc(
        std.math.big.Limb,
        @max(lhs_bigint.limbs.len, rhs_bigint.limbs.len),
    );
    defer ctx.comp.gpa.free(limbs);
    var result_bigint = std.math.big.int.Mutable{ .limbs = limbs, .positive = undefined, .len = undefined };

    result_bigint.bitOr(lhs_bigint, rhs_bigint);
    return ctx.intern(.{ .int = .{ .big_int = result_bigint.toConst() } });
}

pub fn bitXor(lhs: Value, rhs: Value, ctx: Context) !Value {
    var lhs_space: BigIntSpace = undefined;
    var rhs_space: BigIntSpace = undefined;
    const lhs_bigint = lhs.toBigInt(&lhs_space, ctx);
    const rhs_bigint = rhs.toBigInt(&rhs_space, ctx);

    const limbs = try ctx.comp.gpa.alloc(
        std.math.big.Limb,
        @max(lhs_bigint.limbs.len, rhs_bigint.limbs.len),
    );
    defer ctx.comp.gpa.free(limbs);
    var result_bigint = std.math.big.int.Mutable{ .limbs = limbs, .positive = undefined, .len = undefined };

    result_bigint.bitXor(lhs_bigint, rhs_bigint);
    return ctx.intern(.{ .int = .{ .big_int = result_bigint.toConst() } });
}

pub fn bitAnd(lhs: Value, rhs: Value, ctx: Context) !Value {
    var lhs_space: BigIntSpace = undefined;
    var rhs_space: BigIntSpace = undefined;
    const lhs_bigint = lhs.toBigInt(&lhs_space, ctx);
    const rhs_bigint = rhs.toBigInt(&rhs_space, ctx);

    const limbs = try ctx.comp.gpa.alloc(
        std.math.big.Limb,
        @max(lhs_bigint.limbs.len, rhs_bigint.limbs.len),
    );
    defer ctx.comp.gpa.free(limbs);
    var result_bigint = std.math.big.int.Mutable{ .limbs = limbs, .positive = undefined, .len = undefined };

    result_bigint.bitAnd(lhs_bigint, rhs_bigint);
    return ctx.intern(.{ .int = .{ .big_int = result_bigint.toConst() } });
}

pub fn bitNot(val: Value, ty: Type, ctx: Context) !Value {
    const bits = ty.bitSizeof(ctx.comp).?;
    var val_space: Value.BigIntSpace = undefined;
    const val_bigint = val.toBigInt(&val_space, ctx);

    const limbs = try ctx.comp.gpa.alloc(
        std.math.big.Limb,
        std.math.big.int.calcTwosCompLimbCount(bits),
    );
    defer ctx.comp.gpa.free(limbs);
    var result_bigint = std.math.big.int.Mutable{ .limbs = limbs, .positive = undefined, .len = undefined };

    result_bigint.bitNotWrap(val_bigint, ty.signedness(ctx.comp), bits);
    return ctx.intern(.{ .int = .{ .big_int = result_bigint.toConst() } });
}

pub fn compare(a: Value, op: std.math.CompareOperator, b: Value, ty: Type, comp: *const Compilation) bool {
    assert(a.tag == b.tag);
    if (a.tag == .nullptr_t) {
        return switch (op) {
            .eq => true,
            .neq => false,
            else => unreachable,
        };
    }
    const S = struct {
        inline fn doICompare(comptime T: type, aa: Value, opp: std.math.CompareOperator, bb: Value) bool {
            const a_val = aa.getInt(T);
            const b_val = bb.getInt(T);
            return std.math.compare(a_val, opp, b_val);
        }
        inline fn doFCompare(comptime T: type, aa: Value, opp: std.math.CompareOperator, bb: Value) bool {
            const a_val = aa.getFloat(T);
            const b_val = bb.getFloat(T);
            return std.math.compare(a_val, opp, b_val);
        }
    };
    const size = ty.sizeof(comp).?;
    switch (a.tag) {
        .unavailable => return true,
        .int => if (ty.isUnsignedInt(comp)) switch (size) {
            1 => return S.doICompare(u8, a, op, b),
            2 => return S.doICompare(u16, a, op, b),
            4 => return S.doICompare(u32, a, op, b),
            8 => return S.doICompare(u64, a, op, b),
            else => unreachable,
        } else switch (size) {
            1 => return S.doICompare(i8, a, op, b),
            2 => return S.doICompare(i16, a, op, b),
            4 => return S.doICompare(i32, a, op, b),
            8 => return S.doICompare(i64, a, op, b),
            else => unreachable,
        },
        .float => switch (size) {
            4 => return S.doFCompare(f32, a, op, b),
            8 => return S.doFCompare(f64, a, op, b),
            else => unreachable,
        },
        else => @panic("TODO"),
    }
    return false;
}

pub fn hash(v: Value) u64 {
    switch (v.tag) {
        .unavailable => unreachable,
        .int => return std.hash.Wyhash.hash(0, std.mem.asBytes(&v.data.int)),
        else => @panic("TODO"),
    }
}

pub fn compare(lhs: Value, op: std.math.CompareOperator, rhs: Value, ctx: Context) bool {
    const lhs_key = ctx.interner.get(lhs.ref());
    const rhs_key = ctx.interner.get(rhs.ref());
    if (lhs_key == .float or rhs_key == .float) {
        const lhs_f128 = lhs.toFloat(f128, ctx);
        const rhs_f128 = rhs.toFloat(f128, ctx);
        return std.math.compare(lhs_f128, op, rhs_f128);
    }

    var lhs_bigint_space: BigIntSpace = undefined;
    var rhs_bigint_space: BigIntSpace = undefined;
    const lhs_bigint = lhs.toBigInt(&lhs_bigint_space, ctx);
    const rhs_bigint = rhs.toBigInt(&rhs_bigint_space, ctx);
    return lhs_bigint.order(rhs_bigint).compare(op);
}

pub fn dump(v: Value, ty: Type, comp: *Compilation, strings: []const u8, w: anytype) !void {
    switch (v.tag) {
        .unavailable => try w.writeAll("unavailable"),
        .int => if (ty.is(.bool) and comp.langopts.standard.atLeast(.c23)) {
            try w.print("{s}", .{if (v.isZero()) "false" else "true"});
        } else if (ty.isUnsignedInt(comp)) {
            try w.print("{d}", .{v.data.int});
        } else {
            try w.print("{d}", .{v.signExtend(ty, comp)});
        },
        .bytes => try v.data.bytes.dumpString(ty, comp, strings, w),
        // std.fmt does @as instead of @floatCast
        .float => try w.print("{d}", .{@as(f64, @floatCast(v.data.float))}),
        else => try w.print("({s})", .{@tagName(v.tag)}),
    }
}
