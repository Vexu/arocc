const std = @import("std");
const mem = std.mem;

const system_defaults = @import("system_defaults");

const Compilation = @import("../../Compilation.zig");
const Distro = @import("../Distro.zig");
const GCCDetector = @import("../GCCDetector.zig");
const Target = @import("../../Target.zig");
const Toolchain = @import("../../Toolchain.zig");

const Linux = @This();

distro: Distro.Tag = .unknown,
extra_opts: std.ArrayList([]const u8) = .empty,
gcc_detector: GCCDetector = .{},

pub fn discover(self: *Linux, tc: *Toolchain) !void {
    self.distro = Distro.detect(tc.getTarget(), tc);
    try self.gcc_detector.discover(tc);
    tc.selected_multilib = self.gcc_detector.selected;

    try self.gcc_detector.appendToolPath(tc);
    try self.buildExtraOpts(tc);
    try self.findPaths(tc);
}

fn buildExtraOpts(self: *Linux, tc: *const Toolchain) !void {
    const gpa = tc.comp.gpa;
    const target = tc.getTarget();
    const is_android = target.abi.isAndroid();
    if (self.distro.isAlpine() or is_android) {
        try self.extra_opts.ensureUnusedCapacity(gpa, 2);
        self.extra_opts.appendAssumeCapacity("-z");
        self.extra_opts.appendAssumeCapacity("now");
    }

    if (self.distro.isOpenSUSE() or self.distro.isUbuntu() or self.distro.isAlpine() or is_android) {
        try self.extra_opts.ensureUnusedCapacity(gpa, 2);
        self.extra_opts.appendAssumeCapacity("-z");
        self.extra_opts.appendAssumeCapacity("relro");
    }

    if ((target.cpu.arch.isArm() and !target.cpu.arch.isThumb()) or target.cpu.arch.isAARCH64() or is_android) {
        try self.extra_opts.ensureUnusedCapacity(gpa, 2);
        self.extra_opts.appendAssumeCapacity("-z");
        self.extra_opts.appendAssumeCapacity("max-page-size=4096");
    }

    if (target.cpu.arch == .arm or target.cpu.arch == .thumb) {
        try self.extra_opts.append(gpa, "-X");
    }

    if (!target.cpu.arch.isMIPS() and target.cpu.arch != .hexagon) {
        const hash_style = if (is_android) .both else self.distro.getHashStyle();
        try self.extra_opts.append(gpa, switch (hash_style) {
            inline else => |tag| "--hash-style=" ++ @tagName(tag),
        });
    }

    if (system_defaults.enable_linker_build_id) {
        try self.extra_opts.append(gpa, "--build-id");
    }
}

fn addMultiLibPaths(self: *Linux, tc: *Toolchain, sysroot: []const u8, os_lib_dir: []const u8) !void {
    if (!self.gcc_detector.is_valid) return;
    const gcc_triple = self.gcc_detector.gcc_triple;
    const lib_path = self.gcc_detector.parent_lib_path;

    // Add lib/gcc/$triple/$version, with an optional /multilib suffix.
    try tc.addPathIfExists(&.{ self.gcc_detector.install_path, tc.selected_multilib.gcc_suffix }, .file);

    // Add lib/gcc/$triple/$libdir
    // For GCC built with --enable-version-specific-runtime-libs.
    try tc.addPathIfExists(&.{ self.gcc_detector.install_path, "..", os_lib_dir }, .file);

    try tc.addPathIfExists(&.{ lib_path, "..", gcc_triple, "lib", "..", os_lib_dir, tc.selected_multilib.os_suffix }, .file);

    // If the GCC installation we found is inside of the sysroot, we want to
    // prefer libraries installed in the parent prefix of the GCC installation.
    // It is important to *not* use these paths when the GCC installation is
    // outside of the system root as that can pick up unintended libraries.
    // This usually happens when there is an external cross compiler on the
    // host system, and a more minimal sysroot available that is the target of
    // the cross. Note that GCC does include some of these directories in some
    // configurations but this seems somewhere between questionable and simply
    // a bug.
    if (mem.startsWith(u8, lib_path, sysroot)) {
        try tc.addPathIfExists(&.{ lib_path, "..", os_lib_dir }, .file);
    }
}

fn addMultiArchPaths(self: *Linux, tc: *Toolchain) !void {
    if (!self.gcc_detector.is_valid) return;
    const lib_path = self.gcc_detector.parent_lib_path;
    const gcc_triple = self.gcc_detector.gcc_triple;
    const multilib = self.gcc_detector.selected;
    try tc.addPathIfExists(&.{ lib_path, "..", gcc_triple, "lib", multilib.os_suffix }, .file);
}

/// TODO: Very incomplete
fn findPaths(self: *Linux, tc: *Toolchain) !void {
    const target = tc.getTarget();
    const sysroot = tc.getSysroot();

    var output: [64]u8 = undefined;

    const os_lib_dir = getOSLibDir(target);
    const multiarch_triple = getMultiarchTriple(target) orelse target.toLLVMTriple(&output);

    try self.addMultiLibPaths(tc, sysroot, os_lib_dir);

    try tc.addPathIfExists(&.{ sysroot, "/lib", multiarch_triple }, .file);
    try tc.addPathIfExists(&.{ sysroot, "/lib", "..", os_lib_dir }, .file);

    if (target.abi.isAndroid()) {
        // TODO
    }
    try tc.addPathIfExists(&.{ sysroot, "/usr", "lib", multiarch_triple }, .file);
    try tc.addPathIfExists(&.{ sysroot, "/usr", "lib", "..", os_lib_dir }, .file);

    try self.addMultiArchPaths(tc);

    try tc.addPathIfExists(&.{ sysroot, "/lib" }, .file);
    try tc.addPathIfExists(&.{ sysroot, "/usr", "lib" }, .file);
}

pub fn deinit(self: *Linux, allocator: std.mem.Allocator) void {
    self.extra_opts.deinit(allocator);
}

fn isPIEDefault(self: *const Linux) bool {
    _ = self;
    return false;
}

fn getPIE(self: *const Linux, tc_opts: *const Toolchain.Options) bool {
    if (tc_opts.shared or tc_opts.static or tc_opts.relocatable or tc_opts.static_pie) {
        return false;
    }
    return tc_opts.pie orelse self.isPIEDefault();
}

fn getStaticPIE(self: *const Linux, tc: *const Toolchain) !bool {
    _ = self;
    if (tc.opts.static_pie and tc.opts.pie != null) {
        try tc.err("cannot specify 'nopie' along with 'static-pie'", .{});
    }
    return tc.opts.static_pie;
}

fn getStatic(self: *const Linux, tc_opts: *const Toolchain.Options) bool {
    _ = self;
    return tc_opts.static and !tc_opts.static_pie;
}

pub fn getDefaultLinker(self: *const Linux, target: *const Target) []const u8 {
    _ = self;
    if (target.abi.isAndroid()) {
        return "ld.lld";
    }
    return "ld";
}

pub fn buildLinkerArgs(self: *const Linux, tc: *const Toolchain, argv: *std.ArrayList([]const u8), output_name: ?[]const u8, link_objects: []const []const u8) Compilation.Error!void {
    const target = tc.getTarget();
    const gpa = tc.comp.gpa;

    const is_pie = self.getPIE(tc.opts);
    const is_static_pie = try self.getStaticPIE(tc);
    const is_static = self.getStatic(tc.opts);
    const is_android = target.abi.isAndroid();
    const is_ve = target.cpu.arch == .ve;
    const has_crt_begin_end_files = target.abi != .none; // TODO: clang checks for MIPS vendor

    if (is_pie) {
        try argv.append(gpa, "-pie");
    }
    if (is_static_pie) {
        try argv.appendSlice(gpa, &.{ "-static", "-pie", "--no-dynamic-linker", "-z", "text" });
    }

    if (tc.opts.rdynamic) {
        try argv.append(gpa, "-export-dynamic");
    }

    if (tc.opts.strip) {
        try argv.append(gpa, "-s");
    }

    try argv.appendSlice(gpa, self.extra_opts.items);
    try argv.append(gpa, "--eh-frame-hdr");

    // Todo: Driver should parse `-EL`/`-EB` for arm to set endianness for arm targets
    if (tc.comp.target.ldEmulationOption(null)) |emulation| {
        try argv.appendSlice(gpa, &.{ "-m", emulation });
    } else {
        try tc.err("Unknown target triple", .{});
        return;
    }
    if (tc.comp.target.cpu.arch.isRISCV()) {
        try argv.append(gpa, "-X");
    }
    if (tc.opts.shared) {
        try argv.append(gpa, "-shared");
    }
    if (is_static) {
        try argv.append(gpa, "-static");
    } else {
        if (tc.opts.rdynamic) {
            try argv.append(gpa, "-export-dynamic");
        }
        if (!tc.opts.shared and !is_static_pie and !tc.opts.relocatable) {
            const dynamic_linker = tc.comp.target.standardDynamicLinkerPath();
            // todo: check for --dyld-prefix
            if (dynamic_linker.get()) |path| {
                try argv.appendSlice(gpa, &.{ "-dynamic-linker", try tc.comp.arena.dupe(u8, path) });
            } else {
                try tc.err("Could not find dynamic linker path", .{});
            }
        }
    }

    try argv.appendSlice(gpa, &.{ "-o", output_name orelse "a.out" });

    if (!tc.opts.nostdlib and !tc.opts.nostartfiles and !tc.opts.relocatable) {
        if (!is_android) {
            if (!tc.opts.shared) {
                const crt1 = if (is_pie)
                    "Scrt1.o"
                else if (is_static_pie)
                    "rcrt1.o"
                else
                    "crt1.o";
                try argv.append(gpa, try tc.getFilePath(crt1));
            }
            try argv.append(gpa, try tc.getFilePath("crti.o"));
        }
        if (is_ve) {
            try argv.appendSlice(gpa, &.{ "-z", "max-page-size=0x4000000" });
        }

        if (has_crt_begin_end_files) {
            var path: []const u8 = "";
            if (tc.getRuntimeLibKind() == .compiler_rt and !is_android) {
                const crt_begin = try tc.getCompilerRt("crtbegin", .object);
                if (tc.exists(crt_begin)) {
                    path = crt_begin;
                }
            }
            if (path.len == 0) {
                const crt_begin = if (tc.opts.shared)
                    if (is_android) "crtbegin_so.o" else "crtbeginS.o"
                else if (is_static)
                    if (is_android) "crtbegin_static.o" else "crtbeginT.o"
                else if (is_pie or is_static_pie)
                    if (is_android) "crtbegin_dynamic.o" else "crtbeginS.o"
                else if (is_android) "crtbegin_dynamic.o" else "crtbegin.o";
                path = try tc.getFilePath(crt_begin);
            }
            try argv.append(gpa, path);
        }
    }

    // TODO add -L opts
    // TODO add -u opts

    try tc.addFilePathLibArgs(argv);

    // TODO handle LTO

    try argv.appendSlice(gpa, link_objects);

    if (!tc.opts.nostdlib and !tc.opts.relocatable) {
        if (!tc.opts.nodefaultlibs) {
            if (is_static or is_static_pie) {
                try argv.append(gpa, "--start-group");
            }
            try tc.addRuntimeLibs(argv);

            // TODO: add pthread if needed
            if (!tc.opts.nolibc) {
                try argv.append(gpa, "-lc");
            }
            if (is_static or is_static_pie) {
                try argv.append(gpa, "--end-group");
            } else {
                try tc.addRuntimeLibs(argv);
            }
        }
        if (!tc.opts.nostartfiles) {
            if (has_crt_begin_end_files) {
                var path: []const u8 = "";
                if (tc.getRuntimeLibKind() == .compiler_rt and !is_android) {
                    const crt_end = try tc.getCompilerRt("crtend", .object);
                    if (tc.exists(crt_end)) {
                        path = crt_end;
                    }
                }
                if (path.len == 0) {
                    const crt_end = if (tc.opts.shared)
                        if (is_android) "crtend_so.o" else "crtendS.o"
                    else if (is_pie or is_static_pie)
                        if (is_android) "crtend_android.o" else "crtendS.o"
                    else if (is_android) "crtend_android.o" else "crtend.o";
                    path = try tc.getFilePath(crt_end);
                }
                try argv.append(gpa, path);
            }
            if (!is_android) {
                try argv.append(gpa, try tc.getFilePath("crtn.o"));
            }
        }
    }

    // TODO add -T args
}

fn getMultiarchTriple(target: *const Target) ?[]const u8 {
    const is_android = target.abi.isAndroid();
    const is_mips_r6 = std.Target.mips.featureSetHas(target.cpu.features, .mips32r6);
    return switch (target.cpu.arch) {
        .arm, .thumb => if (is_android) "arm-linux-androideabi" else if (target.abi == .gnueabihf) "arm-linux-gnueabihf" else "arm-linux-gnueabi",
        .armeb, .thumbeb => if (target.abi == .gnueabihf) "armeb-linux-gnueabihf" else "armeb-linux-gnueabi",
        .aarch64 => if (is_android) "aarch64-linux-android" else "aarch64-linux-gnu",
        .aarch64_be => "aarch64_be-linux-gnu",
        .x86 => if (is_android) "i686-linux-android" else "i386-linux-gnu",
        .x86_64 => if (is_android) "x86_64-linux-android" else if (target.abi == .gnux32) "x86_64-linux-gnux32" else "x86_64-linux-gnu",
        .m68k => "m68k-linux-gnu",
        .mips => if (is_mips_r6) "mipsisa32r6-linux-gnu" else "mips-linux-gnu",
        .mipsel => if (is_android) "mipsel-linux-android" else if (is_mips_r6) "mipsisa32r6el-linux-gnu" else "mipsel-linux-gnu",
        .powerpcle => "powerpcle-linux-gnu",
        .powerpc64 => "powerpc64-linux-gnu",
        .powerpc64le => "powerpc64le-linux-gnu",
        .riscv64 => "riscv64-linux-gnu",
        .sparc => "sparc-linux-gnu",
        .sparc64 => "sparc64-linux-gnu",
        .s390x => "s390x-linux-gnu",

        // TODO: expand this
        else => null,
    };
}

fn getOSLibDir(target: *const Target) []const u8 {
    switch (target.cpu.arch) {
        .x86,
        .powerpc,
        .powerpcle,
        .sparc,
        => return "lib32",
        else => {},
    }
    if (target.cpu.arch == .x86_64 and (target.abi == .gnux32 or target.abi == .muslx32)) {
        return "libx32";
    }
    if (target.cpu.arch == .riscv32) {
        return "lib32";
    }
    if (target.ptrBitWidth() == 32) {
        return "lib";
    }
    return "lib64";
}

pub fn defineSystemIncludes(self: *const Linux, tc: *const Toolchain, includes: *std.ArrayList(Compilation.Include)) !void {
    if (tc.opts.nostdinc) return;

    const comp = tc.comp;
    const target = tc.getTarget();

    // musl prefers /usr/include before builtin includes, so musl targets will add builtins
    // at the end of this function (unless disabled with nostdlibinc)
    if (!tc.opts.nobuiltininc and (!target.abi.isMusl() or tc.opts.nostdlibinc)) {
        try tc.addBuiltinIncludeDir(includes);
    }

    if (tc.opts.nostdlibinc) return;

    const sysroot = tc.getSysroot();
    const local_include = try std.fs.path.join(comp.gpa, &.{ sysroot, "/usr/local/include" });
    defer comp.gpa.free(local_include);
    try tc.addSystemIncludeDir(local_include, includes);

    if (self.gcc_detector.is_valid) {
        const gcc_include_path = try std.fs.path.join(comp.gpa, &.{ self.gcc_detector.parent_lib_path, "..", self.gcc_detector.gcc_triple, "include" });
        defer comp.gpa.free(gcc_include_path);
        try tc.addSystemIncludeDir(gcc_include_path, includes);
    }

    if (getMultiarchTriple(target)) |triple| {
        const joined = try std.fs.path.join(comp.gpa, &.{ sysroot, "/usr/include", triple });
        defer comp.gpa.free(joined);
        if (tc.exists(joined)) {
            try tc.addSystemIncludeDir(joined, includes);
        }
    }

    if (target.os.tag == .rtems) return;

    try tc.addSystemIncludeDir("/include", includes);
    try tc.addSystemIncludeDir("/usr/include", includes);

    std.debug.assert(!tc.opts.nostdlibinc);
    if (!tc.opts.nobuiltininc and target.abi.isMusl()) {
        try tc.addBuiltinIncludeDir(includes);
    }
}

test Linux {
    if (@import("builtin").os.tag == .windows) return error.SkipZigTest;

    const gpa = std.testing.allocator;
    var arena_instance = std.heap.ArenaAllocator.init(gpa);
    defer arena_instance.deinit();
    const arena = arena_instance.allocator();

    const fake_fns = struct {
        fn dirAccess(_: ?*anyopaque, _: std.Io.Dir, sub_path: []const u8, options: std.Io.Dir.AccessOptions) std.Io.Dir.AccessError!void {
            var resolved_buf: [std.fs.max_path_bytes]u8 = undefined;
            var fib = std.heap.FixedBufferAllocator.init(&resolved_buf);
            const resolved = std.fs.path.resolve(fib.allocator(), &.{sub_path}) catch unreachable;

            const can_exec = std.StaticStringMap(bool).initComptime(.{
                .{ "/tmp", false },
                .{ "/usr", false },
                .{ "/usr/lib64", false },
                .{ "/usr/bin", false },
                .{ "/usr/bin/ld", true },
                .{ "/lib", false },
                .{ "/lib/x86_64-linux-gnu", false },
                .{ "/lib/x86_64-linux-gnu/crt1.o", false },
                .{ "/lib/x86_64-linux-gnu/crti.o", false },
                .{ "/lib/x86_64-linux-gnu/crtn.o", false },
                .{ "/lib64", false },
                .{ "/usr/lib", false },
                .{ "/usr/lib/gcc", false },
                .{ "/usr/lib/gcc/x86_64-linux-gnu", false },
                .{ "/usr/lib/gcc/x86_64-linux-gnu/9", false },
                .{ "/usr/lib/gcc/x86_64-linux-gnu/9/crtbegin.o", false },
                .{ "/usr/lib/gcc/x86_64-linux-gnu/9/crtend.o", false },
                .{ "/usr/lib/x86_64-linux-gnu", false },
            }).get(resolved) orelse return error.FileNotFound;
            if (options.execute and !can_exec) return error.PermissionDenied;
        }
        fn dirOpenFile(_: ?*anyopaque, _: std.Io.Dir, sub_path: []const u8, _: std.Io.Dir.OpenFileOptions) std.Io.File.OpenError!std.Io.File {
            if (!std.mem.eql(u8, sub_path, "/etc/lsb-release")) return error.FileNotFound;
            return .{ .handle = undefined, .flags = undefined };
        }
        fn fileClose(_: ?*anyopaque, _: []const std.Io.File) void {}
        fn fileReadPositional(_: ?*anyopaque, _: std.Io.File, data: []const []u8, offset: u64) std.Io.File.ReadPositionalError!usize {
            const contents =
                \\DISTRIB_ID=Ubuntu
                \\DISTRIB_RELEASE=20.04
                \\DISTRIB_CODENAME=focal
                \\DISTRIB_DESCRIPTION="Ubuntu 20.04.6 LTS"
                \\
            ;
            if (offset >= contents.len) return 0;
            @memcpy(data[0][0..contents.len], contents);
            return contents.len;
        }
    };
    var testing_io_vtable = std.testing.io.vtable.*;
    testing_io_vtable.dirAccess = fake_fns.dirAccess;
    testing_io_vtable.dirOpenFile = fake_fns.dirOpenFile;
    testing_io_vtable.fileClose = fake_fns.fileClose;
    testing_io_vtable.fileReadPositional = fake_fns.fileReadPositional;
    const fake_io: std.Io = .{
        .userdata = std.testing.io.userdata,
        .vtable = &testing_io_vtable,
    };

    var comp = try Compilation.init(.testing);
    comp.io = fake_io;
    comp.arena = arena;
    defer comp.deinit();
    comp.environment = .{
        .path = "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin",
    };
    defer comp.environment = .{};

    const raw_triple = "x86_64-linux-gnu";
    const target_query = try std.Target.Query.parse(.{ .arch_os_abi = raw_triple });
    comp.target = .fromZigTarget(try std.zig.system.resolveTargetQuery(fake_io, target_query));
    comp.langopts.setEmulatedCompiler(.gcc);

    var opts: Toolchain.Options = .{ .raw_target_triple = raw_triple };
    var link_objects: std.ArrayList([]const u8) = .empty;
    defer link_objects.deinit(comp.gpa);
    const link_obj = try comp.gpa.dupe(u8, "/tmp/foo.o");
    defer comp.gpa.free(link_obj);
    try link_objects.append(comp.gpa, link_obj);
    var toolchain: Toolchain = .{ .opts = &opts, .comp = &comp };
    defer toolchain.deinit();

    try toolchain.discover();

    var argv: std.ArrayList([]const u8) = .empty;
    defer argv.deinit(gpa);

    var linker_path_buf: [std.fs.max_path_bytes]u8 = undefined;
    const linker_path = try toolchain.getLinkerPath(&linker_path_buf);
    try argv.append(gpa, linker_path);

    try toolchain.buildLinkerArgs(&argv, null, link_objects.items);

    const expected = [_][]const u8{
        "/usr/bin/ld",
        "-z",
        "relro",
        "--hash-style=gnu",
        "--eh-frame-hdr",
        "-m",
        "elf_x86_64",
        "-dynamic-linker",
        "/lib64/ld-linux-x86-64.so.2",
        "-o",
        "a.out",
        "/lib/x86_64-linux-gnu/crt1.o",
        "/lib/x86_64-linux-gnu/crti.o",
        "crtbegin.o", // TODO wrong
        // "/usr/lib/gcc/x86_64-linux-gnu/9/crtbegin.o",
        // "-L/usr/lib/gcc/x86_64-linux-gnu/9",
        // "-L/usr/lib/gcc/x86_64-linux-gnu/9/../../../../lib64",
        "-L/lib/x86_64-linux-gnu",
        "-L/lib/../lib64",
        "-L/usr/lib/x86_64-linux-gnu",
        "-L/usr/lib/../lib64",
        "-L/lib",
        "-L/usr/lib",
        link_obj,
        "-lgcc",
        "--as-needed",
        "-lgcc_s",
        "--no-as-needed",
        "-lc",
        "-lgcc",
        "--as-needed",
        "-lgcc_s",
        "--no-as-needed",
        "crtend.o", // TODO wrong
        // "/usr/lib/gcc/x86_64-linux-gnu/9/crtend.o",
        "/lib/x86_64-linux-gnu/crtn.o",
    };
    try std.testing.expectEqual(expected.len, argv.items.len);
    for (expected, argv.items) |expected_item, actual_item| {
        try std.testing.expectEqualStrings(expected_item, actual_item);
    }
}
