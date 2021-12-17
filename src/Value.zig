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
    return .{ .tag = .int, .data = .{ .int = v }};
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

pub fn add(res: *Value, a: Value, b: Value, ty: Type, comp: *Compilation) bool {
    if (ty.isFloat()) return addFloat(res, a, b, ty, comp);
    const size = ty.sizeof(comp).?;
    const S = struct {
        inline fn doAdd(comptime T: type, out: *u128, aa: Value, bb: Value) bool {
            const a_val = aa.getInt(T);
            const b_val = bb.getInt(T);
            var c: T = undefined;
            const overflow = @addWithOverflow(T, a_val, b_val, &c);
            const OutT = std.meta.Int(.unsigned, @typeInfo(T).Int.bits);
            out.* = @bitCast(OutT, c);
            return overflow;
        }
    };
    var overflow = false;
    var out: u128 = undefined;
    if (ty.isUnsignedInt(comp)) switch (size) {
        1 => unreachable, // promoted to int
        2 => unreachable, // promoted to int
        4 => overflow = S.doAdd(u32, &out, a, b),
        8 => overflow = S.doAdd(u64, &out, a, b),
        16 => overflow = S.doAdd(u128, &out, a, b),
        else => unreachable,
    } else switch (size) {
        1 => unreachable, // promoted to int
        2 => unreachable, // promoted to int
        4 => overflow = S.doAdd(i32, &out, a, b),
        8 => overflow = S.doAdd(i64, &out, a, b),
        16 => overflow = S.doAdd(i128, &out, a, b),
        else => unreachable,
    }
    res.* = .{ .tag = .int, .data = .{ .int = out } };
    return overflow;
}

fn addFloat(res: *Value, a: Value, b: Value, ty: Type, comp: *Compilation) bool {
    const size = ty.sizeof(comp).?;
    const S = struct {
        inline fn doAdd(comptime T: type, aa: Value, bb: Value) f128 {
            const a_val = aa.getFloat(T);
            const b_val = bb.getFloat(T);
            return a_val + b_val;
        }
    };
    res.* = .{ .tag = .float, .data = .{
        .float = switch (size) {
            4 => S.doAdd(f32, a, b),
            8 => S.doAdd(f64, a, b),
            16 => S.doAdd(f128, a, b),
            else => unreachable,
        },
    } };
    return false;
}

pub fn sub(res: *Value, a: Value, b: Value, ty: Type, comp: *Compilation) bool {
    if (ty.isFloat()) return subFloat(res, a, b, ty, comp);
    const size = ty.sizeof(comp).?;
    const S = struct {
        inline fn doSub(comptime T: type, out: *u128, aa: Value, bb: Value) bool {
            const a_val = aa.getInt(T);
            const b_val = bb.getInt(T);
            var c: T = undefined;
            const overflow = @subWithOverflow(T, a_val, b_val, &c);
            const OutT = std.meta.Int(.unsigned, @typeInfo(T).Int.bits);
            out.* = @bitCast(OutT, c);
            return overflow;
        }
    };
    var overflow = false;
    var out: u128 = undefined;
    if (ty.isUnsignedInt(comp)) switch (size) {
        1 => unreachable, // promoted to int
        2 => unreachable, // promoted to int
        4 => overflow = S.doSub(u32, &out, a, b),
        8 => overflow = S.doSub(u64, &out, a, b),
        16 => overflow = S.doSub(u128, &out, a, b),
        else => unreachable,
    } else switch (size) {
        1 => unreachable, // promoted to int
        2 => unreachable, // promoted to int
        4 => overflow = S.doSub(i32, &out, a, b),
        8 => overflow = S.doSub(i64, &out, a, b),
        16 => overflow = S.doSub(i128, &out, a, b),
        else => unreachable,
    }
    res.* = .{ .tag = .int, .data = .{ .int = out } };
    return overflow;
}

fn subFloat(res: *Value, a: Value, b: Value, ty: Type, comp: *Compilation) bool {
    const size = ty.sizeof(comp).?;
    const S = struct {
        inline fn doSub(comptime T: type, aa: Value, bb: Value) f128 {
            const a_val = aa.getFloat(T);
            const b_val = bb.getFloat(T);
            return a_val - b_val;
        }
    };
    res.* = .{ .tag = .float, .data = .{
        .float = switch (size) {
            4 => S.doSub(f32, a, b),
            8 => S.doSub(f64, a, b),
            16 => S.doSub(f128, a, b),
            else => unreachable,
        },
    } };
    return false;
}

pub fn mul(res: *Value, a: Value, b: Value, ty: Type, comp: *Compilation) bool {
    if (ty.isFloat()) return mulFloat(res, a, b, ty, comp);
    const size = ty.sizeof(comp).?;
    const S = struct {
        inline fn doMul(comptime T: type, out: *u128, aa: Value, bb: Value) bool {
            const a_val = aa.getInt(T);
            const b_val = bb.getInt(T);
            var c: T = undefined;
            const overflow = @mulWithOverflow(T, a_val, b_val, &c);
            const OutT = std.meta.Int(.unsigned, @typeInfo(T).Int.bits);
            out.* = @bitCast(OutT, c);
            return overflow;
        }
    };
    var overflow = false;
    var out: u128 = undefined;
    if (ty.isUnsignedInt(comp)) switch (size) {
        1 => unreachable, // promoted to int
        2 => unreachable, // promoted to int
        4 => overflow = S.doMul(u32, &out, a, b),
        8 => overflow = S.doMul(u64, &out, a, b),
        16 => overflow = S.doMul(u128, &out, a, b),
        else => unreachable,
    } else switch (size) {
        1 => unreachable, // promoted to int
        2 => unreachable, // promoted to int
        4 => overflow = S.doMul(i32, &out, a, b),
        8 => overflow = S.doMul(i64, &out, a, b),
        16 => overflow = S.doMul(i128, &out, a, b),
        else => unreachable,
    }
    res.* = .{ .tag = .int, .data = .{ .int = out } };
    return overflow;
}

fn mulFloat(res: *Value, a: Value, b: Value, ty: Type, comp: *Compilation) bool {
    const size = ty.sizeof(comp).?;
    const S = struct {
        inline fn doMul(comptime T: type, aa: Value, bb: Value) f128 {
            const a_val = aa.getFloat(T);
            const b_val = bb.getFloat(T);
            return a_val * b_val;
        }
    };
    res.* = .{ .tag = .float, .data = .{
        .float = switch (size) {
            4 => S.doMul(f32, a, b),
            8 => S.doMul(f64, a, b),
            16 => S.doMul(f128, a, b),
            else => unreachable,
        },
    } };
    return false;
}

pub fn div(a: Value, b: Value, ty: Type, comp: *Compilation) Value {
    if (ty.isFloat()) return divFloat(a, b, ty, comp);
    const size = ty.sizeof(comp).?;
    const S = struct {
        inline fn doDiv(comptime T: type, aa: Value, bb: Value) u128 {
            const a_val = aa.getInt(T);
            const b_val = bb.getInt(T);
            const OutT = std.meta.Int(.unsigned, @typeInfo(T).Int.bits);
            return @bitCast(OutT, @divTrunc(a_val, b_val));
        }
    };
    return .{
        .tag = .int,
        .data = .{
            .int = if (ty.isUnsignedInt(comp)) switch (size) {
                1 => unreachable, // promoted to int
                2 => unreachable, // promoted to int
                4 => S.doDiv(u32, a, b),
                8 => S.doDiv(u64, a, b),
                16 => S.doDiv(u128, a, b),
                else => unreachable,
            } else switch (size) {
                1 => unreachable, // promoted to int
                2 => unreachable, // promoted to int
                4 => S.doDiv(i32, a, b),
                8 => S.doDiv(i64, a, b),
                16 => S.doDiv(i128, a, b),
                else => unreachable,
            },
        },
    };
}

fn divFloat(a: Value, b: Value, ty: Type, comp: *Compilation) Value {
    const size = ty.sizeof(comp).?;
    const S = struct {
        inline fn doDiv(comptime T: type, aa: Value, bb: Value) f128 {
            const a_val = aa.getFloat(T);
            const b_val = bb.getFloat(T);
            return a_val / b_val;
        }
    };
    return .{ .tag = .float, .data = .{
        .float = switch (size) {
            4 => S.doDiv(f32, a, b),
            8 => S.doDiv(f64, a, b),
            16 => S.doDiv(f128, a, b),
            else => unreachable,
        },
    } };
}

pub fn rem(a: Value, b: Value, ty: Type, comp: *Compilation) Value {
    const size = ty.sizeof(comp).?;
    const S = struct {
        /// Implements C's % operator for signed integers, for evaluating constant expressions
        /// caller guarantees rhs != 0
        /// caller guarantees lhs != std.math.minInt(i64) OR rhs != -1
        inline fn signedRemainder(lhs: anytype, rhs: @TypeOf(lhs)) @TypeOf(lhs) {
            if (rhs > 0) return @rem(lhs, rhs);
            return lhs - @divTrunc(lhs, rhs) * rhs;
        }

        inline fn doRem(comptime T: type, res: *Value, aa: Value, bb: Value) void {
            const a_val = aa.getInt(T);
            const b_val = bb.getInt(T);

            const OutT = std.meta.Int(.unsigned, @typeInfo(T).Int.bits);
            if (@typeInfo(T).Int.signedness == .signed) {
                if (a_val == std.math.minInt(T) and b_val == -1) {
                    res.tag = .unavailable;
                } else {
                    res.data.int = @bitCast(OutT, signedRemainder(a_val, b_val));
                }
            } else {
                res.data.int = @bitCast(OutT, a_val % b_val);
            }
        }
    };
    var out = Value{ .tag = .int, .data = .{ .int = 0 } };
    if (ty.isUnsignedInt(comp)) switch (size) {
        1 => unreachable, // promoted to int
        2 => unreachable, // promoted to int
        4 => S.doRem(u32, &out, a, b),
        8 => S.doRem(u64, &out, a, b),
        16 => S.doRem(u128, &out, a, b),
        else => unreachable,
    } else switch (size) {
        1 => unreachable, // promoted to int
        2 => unreachable, // promoted to int
        4 => S.doRem(i32, &out, a, b),
        8 => S.doRem(i64, &out, a, b),
        16 => S.doRem(i128, &out, a, b),
        else => unreachable,
    }
    return out;
}

pub fn compare(a: Value, op: std.math.CompareOperator, b: Value) bool {
    _ = a;
    _ = op;
    _ = b;
    return false;
}

pub fn hash(v: Value) u64 {
    _ = v;
    return 0;
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
