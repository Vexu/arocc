const std = @import("std");
const Driver = @import("Driver.zig");
const Compilation = @import("Compilation.zig");
const util = @import("util.zig");
const mem = std.mem;
const system_defaults = @import("system_defaults");
const Linux = @import("toolchains/Linux.zig");

const Toolchain = @This();

pub const PathList = std.ArrayListUnmanaged([]const u8);

const Inner = union(enum) {
    linux: Linux,
    unknown: void,

    fn deinit(self: *Inner, allocator: mem.Allocator) void {
        switch (self.*) {
            .linux => |*linux| linux.deinit(allocator),
            .unknown => {},
        }
    }
};

driver: *Driver,
arena: mem.Allocator,

/// The list of toolchain specific path prefixes to search for libraries.
library_paths: PathList = .{},

/// The list of toolchain specific path prefixes to search for files.
file_paths: PathList = .{},

/// The list of toolchain specific path prefixes to search for programs.
program_paths: PathList = .{},

inner: Inner = .{ .unknown = {} },

pub fn getTarget(self: *const Toolchain) std.Target {
    return self.driver.comp.target;
}

fn getDefaultLinker(self: *const Toolchain) []const u8 {
    return switch (self.inner) {
        .linux => |linux| linux.getDefaultLinker(self.getTarget()),
        .unknown => "ld",
    };
}

/// Call this after driver has finished parsing command line arguments to find the toolchain
pub fn discover(self: *Toolchain) !void {
    const target = self.getTarget();
    self.inner = switch (target.os.tag) {
        .elfiamcu,
        .linux,
        => if (target.cpu.arch == .hexagon)
            .{ .unknown = {} } // TODO
        else if (target.cpu.arch.isMIPS())
            .{ .unknown = {} } // TODO
        else if (target.cpu.arch.isPPC())
            .{ .unknown = {} } // TODO
        else if (target.cpu.arch == .ve)
            .{ .unknown = {} } // TODO
        else
            .{ .linux = .{} },
        else => .{ .unknown = {} }, // TODO
    };
    return switch (self.inner) {
        .linux => |*linux| linux.discover(self),
        .unknown => {},
    };
}

pub fn deinit(self: *Toolchain) void {
    const gpa = self.driver.comp.gpa;
    self.inner.deinit(gpa);

    self.library_paths.deinit(gpa);
    self.file_paths.deinit(gpa);
    self.program_paths.deinit(gpa);
}

/// Write linker path to `buf` and return a slice of it
pub fn getLinkerPath(self: *const Toolchain, buf: []u8) ![]const u8 {
    // --ld-path= takes precedence over -fuse-ld= and specifies the executable
    // name. -B, COMPILER_PATH and PATH are consulted if the value does not
    // contain a path component separator.
    // -fuse-ld=lld can be used with --ld-path= to indicate that the binary
    // that --ld-path= points to is lld.
    const use_linker = self.driver.use_linker orelse system_defaults.linker;

    if (self.driver.linker_path) |ld_path| {
        var path = ld_path;
        if (path.len > 0) {
            if (std.fs.path.dirname(path) == null) {
                path = self.getProgramPath(path, buf);
            }
            if (util.canExecute(path)) {
                return path;
            }
        }
        return self.driver.fatal(
            "invalid linker name in argument '--ld-path={s}'",
            .{path},
        );
    }

    // If we're passed -fuse-ld= with no argument, or with the argument ld,
    // then use whatever the default system linker is.
    if (use_linker.len == 0 or mem.eql(u8, use_linker, "ld")) {
        const default = self.getDefaultLinker();
        if (std.fs.path.isAbsolute(default)) return default;
        return self.getProgramPath(default, buf);
    }

    // Extending -fuse-ld= to an absolute or relative path is unexpected. Checking
    // for the linker flavor is brittle. In addition, prepending "ld." or "ld64."
    // to a relative path is surprising. This is more complex due to priorities
    // among -B, COMPILER_PATH and PATH. --ld-path= should be used instead.
    if (mem.indexOfScalar(u8, use_linker, '/') != null) {
        try self.driver.comp.diag.add(.{ .tag = .fuse_ld_path }, &.{});
    }

    if (std.fs.path.isAbsolute(use_linker)) {
        if (util.canExecute(use_linker)) {
            return use_linker;
        }
    } else {
        var linker_name = try std.ArrayList(u8).initCapacity(self.driver.comp.gpa, 5 + use_linker.len); // "ld64." ++ use_linker
        defer linker_name.deinit();
        if (self.getTarget().isDarwin()) {
            linker_name.appendSliceAssumeCapacity("ld64.");
        } else {
            linker_name.appendSliceAssumeCapacity("ld.");
        }
        linker_name.appendSliceAssumeCapacity(use_linker);
        const linker_path = self.getProgramPath(linker_name.items, buf);
        if (util.canExecute(linker_path)) {
            return linker_path;
        }
    }

    if (self.driver.use_linker) |linker| {
        return self.driver.fatal(
            "invalid linker name in argument '-fuse-ld={s}'",
            .{linker},
        );
    }
    const default_linker = self.getDefaultLinker();
    return self.getProgramPath(default_linker, buf);
}

const TargetSpecificToolName = std.BoundedArray(u8, 64);

/// If an explicit target is provided, also check the prefixed tool-specific name
/// TODO: this isn't exactly right since our target names don't necessarily match up
/// with GCC's.
/// For example the Zig target `arm-freestanding-eabi` would need the `arm-none-eabi` tools
fn possibleProgramNames(raw_triple: ?[]const u8, name: []const u8, target_specific: *TargetSpecificToolName) std.BoundedArray([]const u8, 2) {
    var possible_names = std.BoundedArray([]const u8, 2).init(0) catch unreachable;
    if (raw_triple) |triple| {
        const w = target_specific.writer();
        if (w.print("{s}-{s}", .{ triple, name })) {
            possible_names.appendAssumeCapacity(target_specific.slice());
        } else |_| {}
    }
    possible_names.appendAssumeCapacity(name);

    return possible_names;
}

/// Search for an executable called `name` or `{triple}-{name} in program_paths and the $PATH environment variable
/// If not found there, just use `name`
/// Writes the result to `buf` and returns a slice of it
fn getProgramPath(tc: *const Toolchain, name: []const u8, buf: []u8) []const u8 {
    var path_buf: [std.fs.MAX_PATH_BYTES]u8 = undefined;
    var fib = std.heap.FixedBufferAllocator.init(&path_buf);

    var tool_specific_name = TargetSpecificToolName.init(0) catch unreachable;
    const possible_names = possibleProgramNames(tc.driver.raw_target_triple, name, &tool_specific_name);

    for (possible_names.slice()) |tool_name| {
        for (tc.program_paths.items) |program_path| {
            defer fib.reset();

            const candidate = std.fs.path.join(fib.allocator(), &.{ program_path, tool_name }) catch continue;

            if (util.canExecute(candidate) and candidate.len <= buf.len) {
                @memcpy(buf[0..candidate.len], candidate);
                return buf[0..candidate.len];
            }
        }
        // todo: check $PATH
    }
    @memcpy(buf[0..name.len], name);
    return buf[0..name.len];
}

pub fn getSysroot(tc: *const Toolchain) []const u8 {
    return tc.driver.sysroot orelse system_defaults.sysroot;
}

/// Search for `name` in a variety of places
/// TODO: cache results based on `name` so we're not repeatedly allocating the same strings?
pub fn getFilePath(tc: *const Toolchain, name: []const u8) ![]const u8 {
    var path_buf: [std.fs.MAX_PATH_BYTES]u8 = undefined;
    var fib = std.heap.FixedBufferAllocator.init(&path_buf);
    const allocator = fib.allocator();

    const sysroot = tc.getSysroot();

    // todo check resource dir
    // todo check compiler RT path

    const candidate = try std.fs.path.join(allocator, &.{ tc.driver.aro_dir, "..", name });
    if (util.exists(candidate)) {
        return tc.arena.dupe(u8, candidate);
    }

    fib.reset();
    if (searchPaths(allocator, sysroot, tc.library_paths.items, name)) |path| {
        return tc.arena.dupe(u8, path);
    }

    fib.reset();
    if (searchPaths(allocator, sysroot, tc.file_paths.items, name)) |path| {
        return try tc.arena.dupe(u8, path);
    }

    return name;
}

/// Search a list of `path_prefixes` for the existence `name`
/// Assumes that `fba` is a fixed-buffer allocator, so does not free joined path candidates
fn searchPaths(fba: mem.Allocator, sysroot: []const u8, path_prefixes: []const []const u8, name: []const u8) ?[]const u8 {
    for (path_prefixes) |path| {
        if (path.len == 0) continue;

        const candidate = if (path[0] == '=')
            std.fs.path.join(fba, &.{ sysroot, path[1..], name }) catch continue
        else
            std.fs.path.join(fba, &.{ path, name }) catch continue;

        if (util.exists(candidate)) {
            return candidate;
        }
    }
    return null;
}

const PathKind = enum {
    library,
    file,
    program,
};

/// Join `components` into a path. If the path exists, dupe it into the toolchain arena and
/// add it to the specified path list.
pub fn addPathIfExists(self: *Toolchain, components: []const []const u8, dest_kind: PathKind) !void {
    var path_buf: [std.fs.MAX_PATH_BYTES]u8 = undefined;
    var fib = std.heap.FixedBufferAllocator.init(&path_buf);

    const candidate = try std.fs.path.join(fib.allocator(), components);

    if (util.exists(candidate)) {
        const duped = try self.arena.dupe(u8, candidate);
        const dest = switch (dest_kind) {
            .library => &self.library_paths,
            .file => &self.file_paths,
            .program => &self.program_paths,
        };
        try dest.append(self.driver.comp.gpa, duped);
    }
}

pub fn buildLinkerArgs(self: *Toolchain, argv: *std.ArrayList([]const u8)) !void {
    return switch (self.inner) {
        .linux => |*linux| linux.buildLinkerArgs(self, argv),
        .unknown => @panic("This toolchain does not support linking yet"),
    };
}
