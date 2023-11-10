pub const Interner = @import("backend/Interner.zig");
pub const Ir = @import("backend/Ir.zig");
pub const Object = @import("backend/Object.zig");
pub const util = @import("backend/util.zig");

pub const CallingConvention = enum {
    C,
    stdcall,
    thiscall,
    vectorcall,
};

pub const version_str = "0.0.0-dev";
pub const version = @import("std").SemanticVersion.parse(version_str) catch unreachable;
