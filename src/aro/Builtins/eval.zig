const std = @import("std");
const backend = @import("backend");
const Interner = backend.Interner;
const Builtins = @import("../Builtins.zig");
const Builtin = Builtins.Builtin;
const Parser = @import("../Parser.zig");
const Tree = @import("../Tree.zig");
const NodeIndex = Tree.NodeIndex;
const Type = @import("../Type.zig");
const Value = @import("../Value.zig");

pub fn eval(tag: Builtin.Tag, p: *Parser, args: []const NodeIndex) !Value {
    const builtin = Builtin.fromTag(tag);
    if (!builtin.properties.attributes.const_evaluable) return .{};

    switch (tag) {
        Builtin.tagFromName("__builtin_inff").?,
        Builtin.tagFromName("__builtin_inf").?,
        Builtin.tagFromName("__builtin_infl").?,
        => {
            const ty: Type = switch (tag) {
                Builtin.tagFromName("__builtin_inff").? => .{ .specifier = .float },
                Builtin.tagFromName("__builtin_inf").? => .{ .specifier = .double },
                Builtin.tagFromName("__builtin_infl").? => .{ .specifier = .long_double },
                else => unreachable,
            };
            const f: Interner.Key.Float = switch (ty.bitSizeof(p.comp).?) {
                32 => .{ .f32 = std.math.inf(f32) },
                64 => .{ .f64 = std.math.inf(f64) },
                80 => .{ .f80 = std.math.inf(f80) },
                128 => .{ .f128 = std.math.inf(f128) },
                else => unreachable,
            };
            return Value.intern(p.comp, .{ .float = f });
        },
        Builtin.tagFromName("__builtin_isinf").? => blk: {
            if (args.len == 0) break :blk;
            const val = p.value_map.get(args[0]) orelse break :blk;
            return Value.fromBool(val.isInf(p.comp));
        },
        Builtin.tagFromName("__builtin_isnan").? => blk: {
            if (args.len == 0) break :blk;
            const val = p.value_map.get(args[0]) orelse break :blk;
            return Value.fromBool(val.isNan(p.comp));
        },
        else => {},
    }
    return .{};
}
