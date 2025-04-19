pub const Assembly = @import("backend/Assembly.zig");
pub const CodeGenOptions = @import("backend/CodeGenOptions.zig");
pub const Interner = @import("backend/Interner.zig");
pub const Ir = @import("backend/Ir.zig");
pub const Object = @import("backend/Object.zig");

pub const CallingConvention = enum {
    c,
    stdcall,
    thiscall,
    vectorcall,
    fastcall,
    regcall,
};

pub const version_str = @import("build_options").version_str;
pub const version = @import("std").SemanticVersion.parse(version_str) catch unreachable;
