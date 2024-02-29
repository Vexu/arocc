//! Complex arithmetic algorithms from C99 Annex G

const std = @import("std");

/// computes floating point z*w where a_param, b_param are real, imaginary parts of z and c_param, d_param are real, imaginary parts of w
pub fn complexFloatMul(comptime T: type, a_param: T, b_param: T, c_param: T, d_param: T) [2]T {
    var a = a_param;
    var b = b_param;
    var c = c_param;
    var d = d_param;

    const ac = a * c;
    const bd = b * d;
    const ad = a * d;
    const bc = b * c;
    var x = ac - bd;
    var y = ad + bc;
    if (std.math.isNan(x) and std.math.isNan(y)) {
        var recalc = false;
        if (std.math.isInf(a) or std.math.isInf(b)) {
            // lhs infinite
            // Box the infinity and change NaNs in the other factor to 0
            a = std.math.copysign(if (std.math.isInf(a)) @as(T, 1.0) else @as(T, 0.0), a);
            b = std.math.copysign(if (std.math.isInf(b)) @as(T, 1.0) else @as(T, 0.0), b);
            if (std.math.isNan(c)) c = std.math.copysign(@as(T, 0.0), c);
            if (std.math.isNan(d)) d = std.math.copysign(@as(T, 0.0), d);
            recalc = true;
        }
        if (std.math.isInf(c) or std.math.isInf(d)) {
            // rhs infinite
            // Box the infinity and change NaNs in the other factor to 0
            c = std.math.copysign(if (std.math.isInf(c)) @as(T, 1.0) else @as(T, 0.0), c);
            d = std.math.copysign(if (std.math.isInf(d)) @as(T, 1.0) else @as(T, 0.0), d);
            if (std.math.isNan(a)) a = std.math.copysign(@as(T, 0.0), a);
            if (std.math.isNan(b)) b = std.math.copysign(@as(T, 0.0), b);
            recalc = true;
        }
        if (!recalc and (std.math.isInf(ac) or std.math.isInf(bd) or std.math.isInf(ad) or std.math.isInf(bc))) {
            // Recover infinities from overflow by changing NaN's to 0
            if (std.math.isNan(a)) a = std.math.copysign(@as(T, 0.0), a);
            if (std.math.isNan(b)) b = std.math.copysign(@as(T, 0.0), b);
            if (std.math.isNan(c)) c = std.math.copysign(@as(T, 0.0), c);
            if (std.math.isNan(d)) d = std.math.copysign(@as(T, 0.0), d);
        }
        if (recalc) {
            x = std.math.inf(T) * (a * c - b * d);
            y = std.math.inf(T) * (a * d + b * c);
        }
    }
    return .{ x, y };
}

test complexFloatMul {
    // Naive algorithm would produce NaN + NaNi instead of inf + NaNi
    const result = complexFloatMul(f64, std.math.inf(f64), std.math.nan(f64), 2, 0);
    try std.testing.expect(std.math.isInf(result[0]));
    try std.testing.expect(std.math.isNan(result[1]));
}
