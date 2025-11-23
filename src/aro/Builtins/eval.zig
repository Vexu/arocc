const std = @import("std");
const assert = std.debug.assert;

const backend = @import("backend");
const Interner = backend.Interner;
const Builtins = @import("../Builtins.zig");
const Parser = @import("../Parser.zig");
const Tree = @import("../Tree.zig");
const TypeStore = @import("../TypeStore.zig");
const QualType = TypeStore.QualType;
const Type = TypeStore.Type;
const Value = @import("../Value.zig");

fn makeNan(comptime T: type, str: []const u8) T {
    const UnsignedSameSize = std.meta.Int(.unsigned, @bitSizeOf(T));
    const parsed = std.fmt.parseUnsigned(UnsignedSameSize, str[0 .. str.len - 1], 0) catch 0;
    const bits: switch (T) {
        f32 => u23,
        f64 => u52,
        f80 => u63,
        f128 => u112,
        else => @compileError("Invalid type for makeNan"),
    } = @truncate(parsed);
    return @bitCast(@as(UnsignedSameSize, bits) | @as(UnsignedSameSize, @bitCast(std.math.nan(T))));
}

pub fn eval(expanded: Builtins.Expanded, p: *Parser, args: []const Tree.Node.Index) !Value {
    if (!expanded.attributes.const_evaluable) return .{};
    switch (expanded.tag) {
        .common => |tag| switch (tag) {
            .__builtin_inff,
            .__builtin_inf,
            .__builtin_infl,
            => {
                const qt: QualType = switch (tag) {
                    .__builtin_inff => .float,
                    .__builtin_inf => .double,
                    .__builtin_infl => .long_double,
                    else => unreachable,
                };
                const f: Interner.Key.Float = switch (qt.bitSizeof(p.comp)) {
                    32 => .{ .f32 = std.math.inf(f32) },
                    64 => .{ .f64 = std.math.inf(f64) },
                    80 => .{ .f80 = std.math.inf(f80) },
                    128 => .{ .f128 = std.math.inf(f128) },
                    else => unreachable,
                };
                return Value.intern(p.comp, .{ .float = f });
            },
            .__builtin_isinf => blk: {
                assert(args.len == 1);
                const val = p.tree.value_map.get(args[0]) orelse break :blk;
                return Value.fromBool(val.isInf(p.comp));
            },
            .__builtin_isinf_sign => blk: {
                assert(args.len == 1);
                const val = p.tree.value_map.get(args[0]) orelse break :blk;
                switch (val.isInfSign(p.comp)) {
                    .unknown => {},
                    .finite => return Value.zero,
                    .positive => return Value.one,
                    .negative => return Value.int(@as(i64, -1), p.comp),
                }
            },
            .__builtin_isnan => blk: {
                assert(args.len == 1);
                const val = p.tree.value_map.get(args[0]) orelse break :blk;
                return Value.fromBool(val.isNan(p.comp));
            },
            .__builtin_nan => blk: {
                assert(args.len == 1);
                const val = p.getDecayedStringLiteral(args[0]) orelse break :blk;
                const bytes = p.comp.interner.get(val.ref()).bytes;

                const f: Interner.Key.Float = switch (Type.Float.double.bits(p.comp)) {
                    32 => .{ .f32 = makeNan(f32, bytes) },
                    64 => .{ .f64 = makeNan(f64, bytes) },
                    80 => .{ .f80 = makeNan(f80, bytes) },
                    128 => .{ .f128 = makeNan(f128, bytes) },
                    else => unreachable,
                };
                return Value.intern(p.comp, .{ .float = f });
            },
            .__builtin_constant_p => {
                assert(args.len == 1);
                const arg = args[0];
                const val = p.tree.value_map.get(arg) orelse return Value.fromBool(p.isAddressOfStringLiteral(arg));
                return Value.fromBool(!val.isPointer(p.comp));
            },
            else => {},
        },
        else => {},
    }
    return .{};
}
