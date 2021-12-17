const std = @import("std");
const assert = std.debug.assert;
const Compilation = @import("Compilation.zig");
const Type = @import("Type.zig");

const Value = @This();

tag: Tag = .unavailable,
data: union {
    none: void,
    int: u128,
    float: f128,
    array: []Value,
    bytes: []u8,
} = .{ .none = {} },

const Tag = enum {
    unavailable,
    /// int is used to store integer, boolean and pointer values
    int,
    float,
    array,
    bytes,
};

pub const zero = int(0);
pub const one = int(1);

pub fn int(v: anytype) Value {
    return .{ .tag = .int, .data = .{ .int = v } };
}

pub fn float(v: anytype) Value {
    return .{ .tag = .float, .data = .{ .float = v } };
}

pub fn bytes(v: anytype) Value {
    return .{ .tag = .bytes, .data = .{ .bytes = v } };
}

/// Converts the stored value from a float to an integer.
/// `.unavailable` value remains unchanged.
pub fn floatToInt(v: *Value, old_ty: Type, new_ty: Type) void {
    assert(old_ty.isFloat());
    if (v.tag == .unavailable) return;
    _ = new_ty;
}

/// Converts the stored value from an integer to a float.
/// `.unavailable` value remains unchanged.
pub fn intToFloat(v: *Value, old_ty: Type) void {
    assert(old_ty.isInt());
    if (v.tag == .unavailable) return;
}

/// Truncates or extends bits based on type.
/// old_ty is only used for size.
pub fn intCast(v: *Value, old_ty: Type, new_ty: Type) void {
    _ = v;
    _ = old_ty;
    _ = new_ty;
}

/// Truncates data.int to one bit
pub fn intToBool(v: *Value) void {
    if (v.tag == .unavailable) return;
    assert(v.tag == .int);
    v.data.int = @boolToInt(v.getBool());
}

pub fn isZero(v: Value) bool {
    return switch (v.tag) {
        .unavailable => unreachable,
        .int => v.data.int == 0,
        .float => v.data.float == 0,
        .array => unreachable,
        .bytes => unreachable,
    };
}

pub fn getBool(v: Value) bool {
    return switch (v.tag) {
        .unavailable => unreachable,
        .int => v.data.int != 0,
        .float => v.data.float != 0,
        .array => unreachable,
        .bytes => unreachable,
    };
}

pub fn getInt(v: Value, comptime T: type) T {
    if (T == u128) return v.data.int;
    return if (@typeInfo(T).Int.signedness == .unsigned)
        @truncate(T, v.data.int)
    else
        @truncate(T, @bitCast(i128, v.data.int));
}

pub fn getFloat(v: Value, comptime T: type) T {
    if (T == f128) return v.data.float;
    return @floatCast(T, v.data.float);
}

const bin_overflow = struct {
    inline fn addInt(comptime T: type, out: *Value, a: Value, b: Value) bool {
        const a_val = a.getInt(T);
        const b_val = b.getInt(T);
        var c: T = undefined;
        const overflow = @addWithOverflow(T, a_val, b_val, &c);
        const OutT = std.meta.Int(.unsigned, @typeInfo(T).Int.bits);
        out.* = Value.int(@bitCast(OutT, c));
        return overflow;
    }
    inline fn addFloat(comptime T: type, aa: Value, bb: Value) Value {
        const a_val = aa.getFloat(T);
        const b_val = bb.getFloat(T);
        return Value.float(a_val + b_val);
    }

    inline fn subInt(comptime T: type, out: *Value, a: Value, b: Value) bool {
        const a_val = a.getInt(T);
        const b_val = b.getInt(T);
        var c: T = undefined;
        const overflow = @subWithOverflow(T, a_val, b_val, &c);
        const OutT = std.meta.Int(.unsigned, @typeInfo(T).Int.bits);
        out.* = Value.int(@bitCast(OutT, c));
        return overflow;
    }
    inline fn subFloat(comptime T: type, aa: Value, bb: Value) Value {
        const a_val = aa.getFloat(T);
        const b_val = bb.getFloat(T);
        return Value.float(a_val - b_val);
    }

    inline fn mulInt(comptime T: type, out: *Value, a: Value, b: Value) bool {
        const a_val = a.getInt(T);
        const b_val = b.getInt(T);
        var c: T = undefined;
        const overflow = @mulWithOverflow(T, a_val, b_val, &c);
        const OutT = std.meta.Int(.unsigned, @typeInfo(T).Int.bits);
        out.* = Value.int(@bitCast(OutT, c));
        return overflow;
    }
    inline fn mulFloat(comptime T: type, aa: Value, bb: Value) Value {
        const a_val = aa.getFloat(T);
        const b_val = bb.getFloat(T);
        return Value.float(a_val * b_val);
    }

    const FT = fn (*Value, Value, Value, Type, *Compilation) bool;
    fn getOp(intFunc: anytype, floatFunc: anytype) FT {
        return struct {
            fn op(res: *Value, a: Value, b: Value, ty: Type, comp: *Compilation) bool {
                const size = ty.sizeof(comp).?;
                if (@TypeOf(floatFunc) != @TypeOf(null) and ty.isFloat()) {
                    res.* = switch (size) {
                        4 => floatFunc(f32, a, b),
                        8 => floatFunc(f64, a, b),
                        16 => floatFunc(f128, a, b),
                        else => unreachable,
                    };
                    return false;
                }

                if (ty.isUnsignedInt(comp)) switch (size) {
                    1 => unreachable, // promoted to int
                    2 => unreachable, // promoted to int
                    4 => return intFunc(u32, res, a, b),
                    8 => return intFunc(u64, res, a, b),
                    16 => return intFunc(u128, res, a, b),
                    else => unreachable,
                } else switch (size) {
                    1 => unreachable, // promoted to int
                    2 => unreachable, // promoted to int
                    4 => return intFunc(i32, res, a, b),
                    8 => return intFunc(i64, res, a, b),
                    16 => return intFunc(i128, res, a, b),
                    else => unreachable,
                }
            }
        }.op;
    }
};

pub const add = bin_overflow.getOp(bin_overflow.addInt, bin_overflow.addFloat);
pub const sub = bin_overflow.getOp(bin_overflow.subInt, bin_overflow.subFloat);
pub const mul = bin_overflow.getOp(bin_overflow.mulInt, bin_overflow.mulFloat);

const bin_ops = struct {
    inline fn divInt(comptime T: type, aa: Value, bb: Value) Value {
        const a_val = aa.getInt(T);
        const b_val = bb.getInt(T);
        const OutT = std.meta.Int(.unsigned, @typeInfo(T).Int.bits);
        return Value.int(@bitCast(OutT, @divTrunc(a_val, b_val)));
    }
    inline fn divFloat(comptime T: type, aa: Value, bb: Value) Value {
        const a_val = aa.getFloat(T);
        const b_val = bb.getFloat(T);
        return Value.float(a_val / b_val);
    }

    inline fn remInt(comptime T: type, a: Value, b: Value) Value {
        const a_val = a.getInt(T);
        const b_val = b.getInt(T);

        const OutT = std.meta.Int(.unsigned, @typeInfo(T).Int.bits);
        if (@typeInfo(T).Int.signedness == .signed) {
            if (a_val == std.math.minInt(T) and b_val == -1) {
                return Value{ .tag = .unavailable, .data = .{ .none = {} } };
            } else {
                if (b_val > 0) return Value.int(@bitCast(OutT, @rem(a_val, b_val)));
                return Value.int(@bitCast(OutT, a_val - @divTrunc(a_val, b_val) * b_val));
            }
        } else {
            return Value.int(@bitCast(OutT, a_val % b_val));
        }
    }

    inline fn orInt(comptime T: type, a: Value, b: Value) Value {
        const a_val = a.getInt(T);
        const b_val = b.getInt(T);
        const OutT = std.meta.Int(.unsigned, @typeInfo(T).Int.bits);
        return Value.int(@bitCast(OutT, a_val | b_val));
    }
    inline fn xorInt(comptime T: type, a: Value, b: Value) Value {
        const a_val = a.getInt(T);
        const b_val = b.getInt(T);
        const OutT = std.meta.Int(.unsigned, @typeInfo(T).Int.bits);
        return Value.int(@bitCast(OutT, a_val ^ b_val));
    }
    inline fn andInt(comptime T: type, a: Value, b: Value) Value {
        const a_val = a.getInt(T);
        const b_val = b.getInt(T);
        const OutT = std.meta.Int(.unsigned, @typeInfo(T).Int.bits);
        return Value.int(@bitCast(OutT, a_val & b_val));
    }

    inline fn shl(comptime T: type, a: Value, b: Value) Value {
        const ShiftT = std.math.Log2Int(T);
        const info = @typeInfo(T).Int;
        const UT = std.meta.Int(.unsigned, info.bits);
        const b_val = b.getInt(T);

        if (b_val > std.math.maxInt(ShiftT)) {
            return if (info.signedness == .unsigned) 
                Value.int(@as(UT, std.math.maxInt(UT)))
            else
                Value.int(@bitCast(UT, @as(T, std.math.minInt(T))));
        }
        const amt = @truncate(ShiftT, @bitCast(UT, b_val));
        const a_val = a.getInt(T);
        return Value.int(@bitCast(UT, a_val << amt));
    }
    inline fn shr(comptime T: type, a: Value, b: Value) Value {
        const ShiftT = std.math.Log2Int(T);
        const UT = std.meta.Int(.unsigned, @typeInfo(T).Int.bits);

        const b_val = b.getInt(T);
        if (b_val > std.math.maxInt(ShiftT)) return Value.zero;

        const amt = @truncate(ShiftT, @intCast(UT, b_val));
        const a_val = a.getInt(T);
        return Value.int(@bitCast(UT, a_val >> amt));
    }

    const FT = fn (Value, Value, Type, *Compilation) Value;
    fn getOp(intFunc: anytype, floatFunc: anytype) FT {
        return struct {
            fn op(a: Value, b: Value, ty: Type, comp: *Compilation) Value {
                const size = ty.sizeof(comp).?;
                if (@TypeOf(floatFunc) != @TypeOf(null) and ty.isFloat()) {
                    switch (size) {
                        4 => return floatFunc(f32, a, b),
                        8 => return floatFunc(f64, a, b),
                        16 => return floatFunc(f128, a, b),
                        else => unreachable,
                    }
                }

                if (ty.isUnsignedInt(comp)) switch (size) {
                    1 => unreachable, // promoted to int
                    2 => unreachable, // promoted to int
                    4 => return intFunc(u32, a, b),
                    8 => return intFunc(u64, a, b),
                    16 => return intFunc(u128, a, b),
                    else => unreachable,
                } else switch (size) {
                    1 => unreachable, // promoted to int
                    2 => unreachable, // promoted to int
                    4 => return intFunc(i32, a, b),
                    8 => return intFunc(i64, a, b),
                    16 => return intFunc(i128, a, b),
                    else => unreachable,
                }
            }
        }.op;
    }
};

/// caller guarantees rhs != 0
pub const div = bin_ops.getOp(bin_ops.divInt, bin_ops.divFloat);
/// caller guarantees rhs != 0
/// caller guarantees lhs != std.math.minInt(T) OR rhs != -1
pub const rem = bin_ops.getOp(bin_ops.remInt, null);

pub const bitOr = bin_ops.getOp(bin_ops.orInt, null);
pub const bitXor = bin_ops.getOp(bin_ops.xorInt, null);
pub const bitAnd = bin_ops.getOp(bin_ops.andInt, null);

pub const shl = bin_ops.getOp(bin_ops.shl, null);
pub const shr = bin_ops.getOp(bin_ops.shr, null);

pub fn bitNot(v: Value, ty: Type, comp: *Compilation) Value {
    const size = ty.sizeof(comp).?;
    var out: Value = undefined;
    if (ty.isUnsignedInt(comp)) switch (size) {
        1 => unreachable, // promoted to int
        2 => unreachable, // promoted to int
        4 => out = Value.int(~v.getInt(u32)),
        8 => out = Value.int(~v.getInt(u64)),
        16 => out = Value.int(~v.getInt(u128)),
        else => unreachable,
    } else switch (size) {
        1 => unreachable, // promoted to int
        2 => unreachable, // promoted to int
        4 => out = Value.int(@bitCast(u32, ~v.getInt(i32))),
        8 => out = Value.int(@bitCast(u64, ~v.getInt(i64))),
        16 => out = Value.int(@bitCast(u128, ~v.getInt(i128))),
        else => unreachable,
    }
    return out;
}

pub fn compare(a: Value, op: std.math.CompareOperator, b: Value, ty: Type, comp: *Compilation) bool {
    assert(a.tag == b.tag);
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
            1 => unreachable, // promoted to int
            2 => unreachable, // promoted to int
            4 => return S.doICompare(u32, a, op, b),
            8 => return S.doICompare(u64, a, op, b),
            16 => return S.doICompare(u128, a, op, b),
            else => unreachable,
        } else switch (size) {
            1 => unreachable, // promoted to int
            2 => unreachable, // promoted to int
            4 => return S.doICompare(i32, a, op, b),
            8 => return S.doICompare(i64, a, op, b),
            16 => return S.doICompare(i128, a, op, b),
            else => unreachable,
        },
        .float => switch (size) {
            4 => return S.doFCompare(f32, a, op, b),
            8 => return S.doFCompare(f64, a, op, b),
            16 => return S.doFCompare(f128, a, op, b),
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

pub fn dump(v: Value, ty: Type, comp: *Compilation, w: anytype) !void {
    switch (v.tag) {
        .unavailable => try w.writeAll("unavailable"),
        .int => if (ty.isUnsignedInt(comp))
            try w.print("{d}", .{v.data.int})
        else
            try w.print("{d}", .{@bitCast(i128, v.data.int)}),
        // std.fmt does @as instead of @floatCast
        .float => try w.print("{d}", .{@floatCast(f64, v.data.float)}),
        else => try w.print("({s})", .{@tagName(v.tag)}),
    }
}
