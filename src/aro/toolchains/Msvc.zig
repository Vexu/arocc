const std = @import("std");
const mem = std.mem;

const system_defaults = @import("system_defaults");

const Compilation = @import("../Compilation.zig");
const Driver = @import("../Driver.zig");
const target_util = @import("../target.zig");
const Toolchain = @import("../Toolchain.zig");

const Msvc = @This();

pub fn defineSystemIncludes(tc: *const Toolchain) !void {
    if (tc.driver.nostdinc) return;

    const comp = tc.driver.comp;

    if (!tc.driver.nobuiltininc) {
        try comp.addBuiltinIncludeDir(tc.driver.aro_name);
    }

    // TODO -imsvc
    // TODO /external:env:
    // TODO DIA SDK


    if (tc.driver.nostdlibinc) return;

    if (try addSystemIncludeFromEnv(comp, "INCLUDE") or
        try addSystemIncludeFromEnv(comp, "EXTERNAL_INCLUDE")) return;
}

fn addSystemIncludeFromEnv(comp: *Compilation, env: []const u8) !bool {
    const value = std.process.getEnvVarOwned(comp.gpa, env) catch return false;
    if (value.len == 0) return false;
    var it = std.mem.tokenizeScalar(u8, value, ';');
    while (it.next()) |path| {
        try comp.addSystemIncludeDir(path);
    }
    return true;
}
