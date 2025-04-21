const std = @import("std");
const mem = std.mem;
const fs = std.fs;

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

    // TODO %INCLUDE%
    // TODO %EXTERNAL_INCLUDE%

    const gpa = tc.driver.comp.gpa;
    const sdk = std.zig.WindowsSdk.find(gpa, tc.driver.comp.target.cpu.arch) catch |err| switch (err) {
        error.NotFound => return,
        error.PathTooLong => return,
        error.OutOfMemory => return error.OutOfMemory,
    };
    defer sdk.free(gpa);

    try addMsvcIncludeDir(tc, sdk);
    try addIncludeDir(tc, sdk);
}

fn addMsvcIncludeDir(tc: *const Toolchain, sdk: std.zig.WindowsSdk) !void {
    const gpa = tc.driver.comp.gpa;

    const msvc_lib_dir = sdk.msvc_lib_dir orelse return;
    const up1 = fs.path.dirname(msvc_lib_dir) orelse return;
    const up2 = fs.path.dirname(up1) orelse return;

    var free_path = true;
    const dir_path = try fs.path.join(gpa, &[_][]const u8{ up2, "include" });
    defer if (free_path) gpa.free(dir_path);

    var dir = fs.cwd().openDir(dir_path, .{}) catch return;
    defer dir.close();

    dir.accessZ("vcruntime.h", .{}) catch return;

    try tc.driver.comp.system_include_dirs.append(gpa, dir_path);
    free_path = false;
}

fn addIncludeDir(tc: *const Toolchain, sdk: std.zig.WindowsSdk) !void {
    const gpa = tc.driver.comp.gpa;
    var result_buf = std.ArrayList(u8).init(gpa);
    defer result_buf.deinit();

    for ([_]?std.zig.WindowsSdk.Installation{ sdk.windows10sdk, sdk.windows81sdk }) |opt_install| {
        const install = opt_install orelse continue;
        result_buf.items.len = 0;
        try result_buf.writer().print("{s}\\Include\\{s}\\ucrt", .{ install.path, install.version });

        var dir = fs.cwd().openDir(result_buf.items, .{}) catch continue;
        defer dir.close();

        dir.accessZ("stdlib.h", .{}) catch continue;

        const dir_path = try result_buf.toOwnedSlice();
        errdefer gpa.free(dir_path);

        try tc.driver.comp.include_dirs.append(gpa, dir_path);
        return;
    }
}
