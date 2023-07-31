//! Environment variables used by aro
//! Aro internals should avoid calling `getenv` because it will not always be available
//! e.g. if using aro as a library on linux without linking libc
//! See https://github.com/ziglang/zig/issues/4524
//! Instead, the environment variables should be loaded by the driver and passed to the compilation

const std = @import("std");
const enums = std.enums;

const Environment = @This();

pub const Name = enum {
    SOURCE_DATE_EPOCH,
};

const FieldType = ?[]const u8;
const default_value: FieldType = null;

const Variables = [enums.directEnumArrayLen(Name, 0)]?[]const u8;
const FieldStruct = enums.EnumFieldStruct(Name, FieldType, default_value);
const Default: Variables = enums.directEnumArrayDefault(Name, FieldType, default_value, 0, .{});

variables: Variables = Default,

/// See tests for usage
pub fn init(variables: FieldStruct) Environment {
    return Environment{
        .variables = enums.directEnumArrayDefault(Name, FieldType, default_value, 0, variables),
    };
}

/// Load the environment variables using the std.process API
/// `self` owns the strings that are loaded, and deinitFromProcess should be called for cleanup
pub fn initFromProcess(allocator: std.mem.Allocator) !Environment {
    var self: Environment = .{};
    var env_map = try std.process.getEnvMap(allocator);
    defer env_map.deinit();
    errdefer self.deinitFromProcess(allocator);

    for (enums.values(Name)) |name| {
        const val = env_map.get(@tagName(name)) orelse continue;
        self.set(name, try allocator.dupe(u8, val));
    }
    return self;
}

/// deinit function that should be called if `initFromProcess` was used
pub fn deinitFromProcess(self: *const Environment, allocator: std.mem.Allocator) void {
    for (self.variables) |variable| {
        allocator.free(variable orelse continue);
    }
}

pub fn set(self: *Environment, name: Name, val: ?[]const u8) void {
    self.variables[@intFromEnum(name)] = val;
}

pub fn get(self: *const Environment, name: Name) ?[]const u8 {
    return self.variables[@intFromEnum(name)];
}

pub fn getSourceEpoch(self: *const Environment, max: i64) !?i64 {
    const provided = self.get(.SOURCE_DATE_EPOCH) orelse return null;
    const parsed = std.fmt.parseInt(i64, provided, 10) catch return error.InvalidEpoch;
    if (parsed < 0 or parsed > max) return error.InvalidEpoch;
    return parsed;
}

test Environment {
    var env1 = Environment.init(.{
        .SOURCE_DATE_EPOCH = "123",
    });
    try std.testing.expectEqualStrings("123", env1.get(.SOURCE_DATE_EPOCH).?);

    var env2 = Environment.init(.{});
    try std.testing.expectEqual(default_value, env2.get(.SOURCE_DATE_EPOCH));

    var env3: Environment = .{};
    try std.testing.expectEqual(default_value, env3.get(.SOURCE_DATE_EPOCH));
}
