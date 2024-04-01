//! Step for determining the zig lib dir and various subdirectories via `zig env`

const std = @import("std");
const Step = std.Build.Step;
const ZigLibDir = @This();
const LazyPath = std.Build.LazyPath;

step: Step,
/// path to zig's lib directory
lib_dir: std.Build.GeneratedFile,
/// path to compiler-rt directory
compiler_rt: std.Build.GeneratedFile,
/// path to directory which has zig.h
include: std.Build.GeneratedFile,

pub fn create(owner: *std.Build) !*ZigLibDir {
    const self = try owner.allocator.create(ZigLibDir);
    const name = "zig lib dir";
    self.* = .{
        .step = Step.init(.{
            .id = .custom,
            .name = name,
            .owner = owner,
            .makeFn = make,
        }),
        .lib_dir = .{ .step = &self.step },
        .compiler_rt = .{ .step = &self.step },
        .include = .{ .step = &self.step },
    };
    return self;
}

const ZigEnv = struct {
    lib_dir: []const u8,
};

fn make(step: *Step, prog_node: *std.Progress.Node) !void {
    _ = prog_node;

    const b = step.owner;
    const self: *ZigLibDir = @fieldParentPtr("step", step);

    const zig_env_args: [2][]const u8 = .{ b.graph.zig_exe, "env" };
    var out_code: u8 = undefined;
    const zig_env = try b.runAllowFail(&zig_env_args, &out_code, .Ignore);

    const parsed_str = try std.json.parseFromSlice(ZigEnv, b.allocator, zig_env, .{ .ignore_unknown_fields = true });
    defer parsed_str.deinit();

    self.lib_dir.path = parsed_str.value.lib_dir;
    self.compiler_rt.path = try std.fs.path.join(b.allocator, &[_][]const u8{ parsed_str.value.lib_dir, "compiler_rt.zig" });
    self.include.path = try std.fs.path.join(b.allocator, &[_][]const u8{ parsed_str.value.lib_dir, "include" });
}

pub fn getLibPath(self: *ZigLibDir) std.Build.LazyPath {
    return .{ .generated = &self.lib_dir };
}

pub fn getCompilerRTPath(self: *ZigLibDir) std.Build.LazyPath {
    return .{ .generated = &self.compiler_rt };
}

pub fn getIncludePath(self: *ZigLibDir) std.Build.LazyPath {
    return .{ .generated = &self.include };
}
