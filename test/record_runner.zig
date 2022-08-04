const std = @import("std");
const build_options = @import("build_options");

const print = std.debug.print;
const aro = @import("aro");
const Runner = @import("runner.zig");
const Codegen = aro.Codegen;
const Tree = aro.Tree;
const Token = Tree.Token;
const NodeIndex = Tree.NodeIndex;
const AllocatorError = std.mem.Allocator.Error;

// used a fixed size allocator for each run.
var fixie: std.mem.Allocator = undefined;

// these tests don't work for any target. parse only
const global_test_skip = [_][]const u8{
    "0011", "0014", "0044", "0046", // issue #332 https://github.com/Vexu/arocc/issues/332
};
// these targets don't work at all. Don't even parse
const global_target_skip = [_][]const u8{
    "avr-atmega328-other-gnu:Gcc",
    "arm-baseline-ios-none:Clang", //these IOS targets fail on macos.
    "arm-cortex_r4-ios-none:Clang",
};
// these files don't parse the MSVC extensions
const msvc_hard_skip = [_][]const u8{
    "0018", "0024", "0025", "0026", "0036",
    "0042", "0043", "0044", "0045", "0053",
};

const TestControl = struct {
    target: []const u8,
    non_working_tests: []const []const u8, // parse only. no asserts
    skip_offset_checks: []const []const u8, // don't check bit offsets of records
    skip_extra_checks: []const []const u8, // don't do extra automated size/align tests
};
// for debugging specific targets w/ specific tests.
const Single = struct {
    target: []const u8,
    c_test: []const u8,
};
const do_single: ?Single = if (false)
.{
    .target = "x86_64-x86_64-windows-msvc:Msvc",
    .c_test = "00", // run all the tests
    // .target = "arm-arm1136j_s-freebsd-gnu:Clang",
    // .c_test = "0052",
} else null;

// control which tests to skip for which targets.
// or which parts of tests.
//
// a few trends in here. 0052 and 32bit systems don't get along
// zig fmt: off
const test_control = [_]TestControl{
    // msvc is work in progress
    .{
        .target = "x86_64-x86_64-windows-msvc:Msvc",
        .non_working_tests = &.{
            // "0003", "0005", "0006", "0007",
            "0005", "0006", "0007",
            "0008", "0009", "0010", "0011",
            "0012", "0014", "0015", "0016",
            "0017", "0018", "0019", "0020",
            "0021", "0022", "0023", "0024",
            "0025", "0026", "0027", "0028",
            "0029", "0030", "0031", "0032",
            "0033", "0034", "0035", "0036",
            "0037", "0038", "0039", "0040",
            "0041", "0042", "0043", "0044",
            "0045", "0046", "0047", "0048",
            "0049", "0050", "0051", "0052",
            "0053", "0054", "0055", "0056",
            "0057", "0058", "0059", "0060",
            "0061", "0062", "0063", "0064",
            "0065", "0066", "0067", "0068",
            "0069", "0070", "0071", "0072",
            "0073", "0074", "0075", "0076",
            "0077", "0078", "0079", "0080",
            "0081", "0082", "0083", "0084",
            "0085", "0086", "0087", "0088",
        },
        .skip_offset_checks = &.{},
        .skip_extra_checks = &.{
            "0001", "0002", "0004", "0013",
        },
    },
    .{
        .target = "aarch64-generic-ios-macabi:Clang",
        .non_working_tests = &.{
            "0001", "0013", "0032", "0033", "0034", "0035",
            "0054", "0055", "0060", "0061", "0062", "0068",
            "0083",
        },
        .skip_offset_checks = &.{},
        .skip_extra_checks = &.{},
    },

    .{
        .target = "aarch64-generic-ios-none:Clang",
        .non_working_tests = &.{
            "0001", "0013", "0032", "0033", "0034", "0035",
            "0054", "0055", "0060", "0061", "0062", "0068",
            "0083",
        },
        .skip_offset_checks = &.{},
        .skip_extra_checks = &.{},
    },
    .{
        .target = "aarch64-generic-other-none:Clang",
        .non_working_tests = &.{
            "0001", "0013", "0015", "0032", "0033", "0034",
            "0035", "0054", "0055", "0060", "0061", "0062",
            "0068", "0083",
        },
        .skip_offset_checks = &.{},
        .skip_extra_checks = &.{},
    },
    .{
        .target = "aarch64-generic-tvos-none:Clang",
        .non_working_tests = &.{
            "0001", "0013", "0032", "0033", "0034", "0035",
            "0054", "0055", "0060", "0061", "0062", "0068",
            "0083",
        },
        .skip_offset_checks = &.{},
        .skip_extra_checks = &.{},
    },
    .{
        .target = "arm-baseline-ios-none:Clang",
        .non_working_tests = &.{
            "0001", "0002", "0013", "0018", "0024", "0032",
            "0033", "0034", "0043", "0067", "0068", "0069",
            "0073", "0082", "0083", "0087", "0088",
        },
        .skip_offset_checks = &.{},
        .skip_extra_checks = &.{},
    },
    .{
        .target = "arm-arm1136j_s-freebsd-gnu:Clang",
        .non_working_tests = &.{
            "0052",
        },
        .skip_offset_checks = &.{},
        .skip_extra_checks = &.{},
    },
    .{
        .target = "arm-cortex_r4-freebsd-gnu:Clang",
        .non_working_tests = &.{
            "0052",
        },
        .skip_offset_checks = &.{},
        .skip_extra_checks = &.{},
    },
    .{
        .target = "arm-cortex_r4-ios-none:Clang",
        .non_working_tests = &.{
            "0001", "0002", "0013", "0018", "0024", "0032",
            "0033", "0034", "0043", "0067", "0068", "0069",
            "0073", "0082", "0083", "0087", "0088",
        },
        .skip_offset_checks = &.{},
        .skip_extra_checks = &.{},
    },
    .{
        .target = "hexagon-generic-linux-musl:Clang",
        .non_working_tests = &.{
            "0016", "0019", "0051", "0054", "0060", "0061",
            "0062", "0063",
        },
        .skip_offset_checks = &.{},
        .skip_extra_checks = &.{},
    },
    .{
        .target = "i386-i386-ios-none:Clang",
        .non_working_tests = &.{
            "0001", "0002", "0013", "0018", "0024", "0032",
            "0033", "0034", "0043", "0067", "0068", "0069",
            "0082", "0083", "0087", "0088",
        },
        .skip_offset_checks = &.{},
        .skip_extra_checks = &.{},
    },
    .{
        .target = "i386-i586-linux-gnu:Gcc",
        .non_working_tests = &.{
            "0002", "0013", "0019", "0024", "0043", "0054",
            "0055", "0060", "0061", "0062", "0068", "0069",
            "0082", "0087", "0088",
        },
        .skip_offset_checks = &.{},
        .skip_extra_checks = &.{},
    },
    .{
        .target = "i386-i586-linux-musl:Gcc",
        .non_working_tests = &.{
            "0002", "0013", "0019", "0024", "0043", "0054",
            "0055", "0060", "0061", "0062", "0068", "0069",
            "0082", "0087", "0088",
        },
        .skip_offset_checks = &.{},
        .skip_extra_checks = &.{},
    },
    .{
        .target = "i386-i686-freebsd-gnu:Clang",
        .non_working_tests = &.{
            "0002", "0013", "0018", "0024", "0043", "0054",
            "0055", "0060", "0061", "0062", "0068", "0069",
            "0082", "0087", "0088",
        },
        .skip_offset_checks = &.{},
        .skip_extra_checks = &.{},
    },
    .{
        .target = "i386-i686-linux-android:Clang",
        .non_working_tests = &.{
            "0002", "0013", "0018", "0024", "0043", "0054",
            "0055", "0060", "0061", "0062", "0068", "0069",
            "0082", "0087", "0088",
        },
        .skip_offset_checks = &.{},
        .skip_extra_checks = &.{},
    },
    .{
        .target = "i386-i686-linux-gnu:Gcc",
        .non_working_tests = &.{
            "0002", "0013", "0019", "0024", "0043", "0054",
            "0055", "0060", "0061", "0062", "0068", "0069",
            "0082", "0087", "0088",
        },
        .skip_offset_checks = &.{},
        .skip_extra_checks = &.{},
    },
    .{
        .target = "i386-i686-linux-musl:Gcc",
        .non_working_tests = &.{
            "0002", "0013", "0019", "0024", "0043", "0054",
            "0055", "0060", "0061", "0062", "0068", "0069",
            "0082", "0087", "0088",
        },
        .skip_offset_checks = &.{},
        .skip_extra_checks = &.{},
    },
    .{
        .target = "i386-i686-netbsd-gnu:Clang",
        .non_working_tests = &.{
            "0002", "0013", "0018", "0024", "0043", "0054",
            "0055", "0060", "0061", "0062", "0068", "0069",
            "0082", "0087", "0088",
        },
        .skip_offset_checks = &.{},
        .skip_extra_checks = &.{},
    },
    .{
        .target = "i386-i686-openbsd-gnu:Clang",
        .non_working_tests = &.{
            "0002", "0013", "0018", "0024", "0043", "0054",
            "0055", "0060", "0061", "0062", "0068", "0069",
            "0082", "0087", "0088",
        },
        .skip_offset_checks = &.{},
        .skip_extra_checks = &.{},
    },
    .{
        .target = "mipsel-mips32-linux-gnu:Gcc",
        .non_working_tests = &.{
            "0052",
        },
        .skip_offset_checks = &.{},
        .skip_extra_checks = &.{},
    },
    .{
        .target = "mipsel-mips32-linux-musl:Gcc",
        .non_working_tests = &.{
            "0052",
        },
        .skip_offset_checks = &.{},
        .skip_extra_checks = &.{},
    },
    .{
        .target = "mips-mips32-linux-gnuabi64:Gcc",
        .non_working_tests = &.{
            "0001", "0013", "0032", "0033", "0034", "0035",
            "0067", "0068", "0083",
        },
        .skip_offset_checks = &.{},
        .skip_extra_checks = &.{},
    },
    .{
        .target = "mips-mips32-linux-gnu:Gcc",
        .non_working_tests = &.{
            "0052",
        },
        .skip_offset_checks = &.{},
        .skip_extra_checks = &.{},
    },
    .{
        .target = "mips-mips32-linux-musl:Gcc",
        .non_working_tests = &.{
            "0052",
        },
        .skip_offset_checks = &.{},
        .skip_extra_checks = &.{},
    },
    .{
        .target = "mips-mips32r6-linux-gnu:Gcc",
        .non_working_tests = &.{
            "0052",
        },
        .skip_offset_checks = &.{},
        .skip_extra_checks = &.{},
    },
    .{
        .target = "mips-mips64r6-linux-gnuabi64:Gcc",
        .non_working_tests = &.{
            "0001", "0013", "0032", "0033", "0034", "0035",
            "0067", "0068", "0083",
        },
        .skip_offset_checks = &.{},
        .skip_extra_checks = &.{},
    },
    .{
        .target = "msp430-msp430-other-none:Clang",
        .non_working_tests = &.{
            "0062",
        },
        .skip_offset_checks = &.{},
        .skip_extra_checks = &.{},
    },
    .{
        .target = "riscv64-generic_rv64-other-none:Clang",
        .non_working_tests = &.{
            "0001", "0013", "0032", "0033", "0034", "0035",
            "0054", "0055", "0060", "0061", "0062", "0068",
            "0083",
        },
        .skip_offset_checks = &.{},
        .skip_extra_checks = &.{},
    },
    .{
        .target = "s390x-generic-linux-gnu:Gcc",
        .non_working_tests = &.{
            "0050",
            "0052",
        },
        .skip_offset_checks = &.{},
        .skip_extra_checks = &.{},
    },
    .{
        .target = "sparc-v8-linux-gnu:Gcc",
        .non_working_tests = &.{
            "0052",
        },
        .skip_offset_checks = &.{},
        .skip_extra_checks = &.{},
    },
    .{
        .target = "sparc-v9-solaris-eabi:Clang",
        .non_working_tests = &.{
            "0001", "0013", "0032", "0033", "0034", "0035",
            "0067", "0068", "0083",
        },
        .skip_offset_checks = &.{},
        .skip_extra_checks = &.{},
    },
    .{
        .target = "x86_64-i686-macos-none:Clang",
        .non_working_tests = &.{
            "0001", "0002", "0013", "0018", "0024", "0032",
            "0033", "0034", "0035", "0043", "0054", "0055",
            "0060", "0061", "0062", "0067", "0068", "0069",
            "0082", "0083", "0087", "0088",
        },
        .skip_offset_checks = &.{},
        .skip_extra_checks = &.{},
    },
    .{
        .target = "x86_64-x86_64-ios-macabi:Clang",
        .non_working_tests = &.{
            "0001", "0013", "0032", "0033", "0034", "0035",
            "0054", "0055", "0060", "0061", "0062", "0068",
            "0083",
        },
        .skip_offset_checks = &.{},
        .skip_extra_checks = &.{},
    },
    .{
        .target = "x86_64-x86_64-ios-none:Clang",
        .non_working_tests = &.{
            "0001", "0013", "0032", "0033", "0034", "0035",
            "0054", "0055", "0060", "0061", "0062", "0068",
            "0083",
        },
        .skip_offset_checks = &.{},
        .skip_extra_checks = &.{},
    },
    .{
        .target = "x86_64-x86_64-linux-gnux32:Gcc",
        .non_working_tests = &.{
            "0001", "0013", "0032", "0033", "0034", "0035",
            "0067", "0068", "0083",
        },
        .skip_offset_checks = &.{},
        .skip_extra_checks = &.{},
    },
    .{
        .target = "x86_64-x86_64-solaris-eabi:Clang",
        .non_working_tests = &.{
            "0001", "0013", "0032", "0033", "0034", "0035",
            "0054", "0055", "0060", "0061", "0062", "0068",
            "0083",
        },
        .skip_offset_checks = &.{},
        .skip_extra_checks = &.{},
    },
    .{
        .target = "x86_64-x86_64-tvos-none:Clang",
        .non_working_tests = &.{
            "0001", "0013", "0032", "0033", "0034", "0035",
            "0054", "0055", "0060", "0061", "0062", "0068",
            "0083",
        },
        .skip_offset_checks = &.{},
        .skip_extra_checks = &.{},
    },
};
// zig fmt: on

const Stats = struct {
    ok_count: u32 = 0,
    fail_count: u32 = 0,
    skip_count: u32 = 0,
    progress: *std.Progress,
    root_node: *std.Progress.Node,
};

const Settings = struct {
    skip_all: bool = false, // don't even try and parse it.
    check_offsets: bool = true,
    extra_checks: bool = true,
    c_define: ?[]const u8 = null,
    target: []const u8 = "",
};

pub fn main() !void {
    var general_purpose_allocator = std.heap.GeneralPurposeAllocator(.{}){};
    const gpa = general_purpose_allocator.allocator();
    // max file sizse < 2M. max total use < 8M
    var fixed_buffer = try gpa.alloc(u8, 1024 * 1024 * 10);
    var fixed_alloc = std.heap.FixedBufferAllocator.init(fixed_buffer);
    fixie = fixed_alloc.allocator();
    defer {
        gpa.free(fixed_buffer);
        if (general_purpose_allocator.deinit()) std.process.exit(1);
    }

    var args = try std.process.argsAlloc(gpa);
    defer std.process.argsFree(gpa, args);

    if (args.len != 3) {
        print("expected test case directory and zig executable as only arguments\n", .{});
        return error.InvalidArguments;
    }

    var cases = std.ArrayList([]const u8).init(gpa);
    defer {
        for (cases.items) |path| gpa.free(path);
        cases.deinit();
    }

    // collect all cases
    {
        var cases_dir = try std.fs.cwd().openIterableDir(args[1], .{});
        defer cases_dir.close();
        var buf = std.ArrayList(u8).init(gpa);
        defer buf.deinit();

        var it = cases_dir.iterate();
        while (try it.next()) |entry| {
            if (entry.kind == .Directory) continue;
            if (entry.kind != .File) {
                print("skipping non file entry '{s}'\n", .{entry.name});
                continue;
            }

            if (std.mem.count(u8, entry.name, "_test.c") == 1) {
                defer buf.items.len = 0;
                try buf.writer().print("{s}{c}{s}", .{ args[1], std.fs.path.sep, entry.name });
                try cases.append(try gpa.dupe(u8, buf.items));
            }
        }
    }

    std.sort.sort([]const u8, cases.items, u8, std.mem.lessThan);

    var progress = std.Progress{};
    const root_node = progress.start("Layout", 0);

    // apparently we can't use setAstCwd without libc on windows yet
    const win = @import("builtin").os.tag == .windows;
    var tmp_dir = if (!win) std.testing.tmpDir(.{});
    defer if (!win) tmp_dir.cleanup();

    if (!win) try tmp_dir.dir.setAsCwd();

    var stats = Stats{
        .progress = &progress,
        .root_node = root_node,
    };
    var max_alloc_size: usize = 0;

    // iterate over all cases
    for (cases.items) |path| {
        fixed_alloc.reset();
        const source: []const u8 = fread: {
            const file = try std.fs.cwd().openFile(path, .{});
            defer file.close();
            const file_size = (try file.stat()).size;
            var src_buf = try fixie.alloc(u8, file_size + 1);
            const read_len = try file.readAll(src_buf);
            std.debug.assert(read_len >= file_size);
            break :fread src_buf[0..read_len];
        };

        // for each ifdef, a list of targets
        var source_targets = std.ArrayList(*Settings).init(fixie);

        try parseTargetsFromCode(&source_targets, source, path);
        // reset the fixed allocator to this point before each run.
        const mem_reset_pos = fixed_alloc.end_index;
        for (source_targets.items) |setting| {
            fixed_alloc.end_index = mem_reset_pos;
            if (setting.skip_all) {
                stats.skip_count += 1;
                continue;
            }
            if (do_single) |single| {
                if (std.mem.count(u8, setting.target, single.target) < 1) continue;
                if (std.mem.count(u8, path, single.c_test) < 1) continue;
            } else {
                const target = try getTarget(setting.target);

                switch (target.os.tag) {
                    .windows,
                    .uefi,
                    // arocc does not support
                    .haiku,
                    .fuchsia,
                    .hermit,
                    => {
                        stats.skip_count += 1;
                        continue;
                    },
                    else => {},
                }
            }
            if (setting.c_define == null) {
                stats.skip_count += 1;
            }

            try singleRun(path, source, setting.*, &stats);
            if (max_alloc_size < fixed_alloc.end_index) max_alloc_size = fixed_alloc.end_index;
        }
    }

    root_node.end();
    std.debug.print("max mem used = {}\n", .{std.fmt.fmtIntSizeBin(max_alloc_size)});
    if (stats.ok_count == cases.items.len and stats.skip_count == 0) {
        print("All {d} tests passed.\n", .{stats.ok_count});
    } else if (stats.fail_count == 0) {
        print("{d} passed; {d} skipped.\n", .{ stats.ok_count, stats.skip_count });
    } else {
        print("{d} passed; {d} failed.\n\n", .{ stats.ok_count, stats.fail_count });
        std.process.exit(1);
    }
}

fn singleRun(path: []const u8, source: []const u8, settings: Settings, state: *Stats) !void {
    // prepare compiler
    //
    var comp = aro.Compilation.init(fixie);
    defer comp.deinit();

    try comp.addDefaultPragmaHandlers();
    try comp.defineSystemIncludes();
    try setTarget(&comp, settings.target);

    var case_name = std.ArrayList(u8).init(fixie);
    defer case_name.deinit();

    try case_name.writer().print("{s} | {s} | {?s}", .{
        std.mem.sliceTo(std.fs.path.basename(path), '.'),
        settings.target,
        settings.c_define,
    });

    var case_node = state.root_node.start(case_name.items, 0);
    case_node.activate();
    defer case_node.end();
    state.progress.refresh();

    // const file = comp.addSourceFromPath(path) catch |err| {
    const file = comp.addSourceFromBuffer(path, source) catch |err| {
        state.fail_count += 1;
        state.progress.log("could not add source '{s}': {s}\n", .{ path, @errorName(err) });
        return;
    };

    var macro_buf = std.ArrayList(u8).init(comp.gpa);
    defer macro_buf.deinit();

    comp.langopts.setEmulatedCompiler(comp.systemCompiler());

    {
        var cmd_args = std.ArrayList([]const u8).init(comp.gpa);
        defer cmd_args.deinit();

        const mac_writer = macro_buf.writer();
        if (settings.c_define) |d| {
            _ = try mac_writer.print("#define {s}\n", .{d});
        } else {
            // we're just testing the parser.
            // count this as a skip.
            state.skip_count += 1;
        }
        if (settings.check_offsets) {
            _ = try mac_writer.write("#define CHECK_OFFSETS\n");
        }
        if (settings.extra_checks) {
            _ = try mac_writer.write("#define EXTRA_TESTS\n");
        }
        if (comp.target.os.tag == .windows) {
            for (msvc_hard_skip) |skip| {
                if (std.mem.count(u8, path, skip) > 0) return;
            }
            comp.langopts.enableMSExtensions();
            _ = try mac_writer.write("#define MSVC\n");
        }
        // TODO: only turn these of for the files we know emit these warnings
        comp.diag.options.@"ignored-pragmas" = .off;
        comp.diag.options.@"implicitly-unsigned-literal" = .off;
        var source_files = std.ArrayList(aro.Source).init(std.testing.failing_allocator);
        _ = try aro.parseArgs(&comp, std.io.null_writer, &source_files, mac_writer, cmd_args.items);
    }

    const user_macros = try comp.addSourceFromBuffer("<command line>", macro_buf.items);

    const builtin_macros = try comp.generateBuiltinMacros();

    comp.diag.errors = 0;
    var pp = aro.Preprocessor.init(&comp);
    defer pp.deinit();
    try pp.addBuiltinMacros();

    _ = try pp.preprocess(builtin_macros);
    _ = try pp.preprocess(user_macros);
    const eof = pp.preprocess(file) catch |err| {
        if (!std.unicode.utf8ValidateSlice(file.buf)) {
            // non-utf8 files are not preprocessed, so we can't use EXPECTED_ERRORS; instead we
            // check that the most recent error is .invalid_utf8
            if (comp.diag.list.items.len > 0 and comp.diag.list.items[comp.diag.list.items.len - 1].tag == .invalid_utf8) {
                _ = comp.diag.list.pop();
                return;
            }
        }

        state.fail_count += 1;
        state.progress.log("could not preprocess file '{s}': {s}\n", .{ path, @errorName(err) });
        return;
    };
    try pp.tokens.append(fixie, eof);

    comp.renderErrors();
    if (comp.diag.errors != 0) {
        state.fail_count += 1;
        return;
    }
    var tree = try aro.Parser.parse(&pp);
    defer tree.deinit();
    tree.dump(false, std.io.null_writer) catch {};

    var buf = std.ArrayList(u8).init(fixie);
    defer buf.deinit();

    if (try Runner.checkExpectedErrors(&pp, state.progress, &buf)) |some| {
        if (some) state.ok_count += 1 else state.fail_count += 1;
        return;
    }

    comp.renderErrors();

    if (comp.diag.errors != 0) state.fail_count += 1 else state.ok_count += 1;
}

fn findTarget(map: std.StringHashMap(std.StringHashMap(void)), find: []const u8) ?[]const u8 {
    var iter = map.iterator();
    while (iter.next()) |ent| {
        if (ent.value_ptr.contains(find)) {
            return ent.key_ptr.*;
        }
    }
    return null;
}
fn inList(heystack: []const []const u8, needle: []const u8) bool {
    for (heystack) |check| {
        if (std.mem.count(u8, check, needle) > 0) return true;
    }
    return false;
}
fn getTarget(zig_target: []const u8) !std.Target {
    const split_idex = std.mem.indexOf(u8, zig_target, ":").?;
    var ret: std.Target = undefined;
    var iter = std.mem.tokenize(u8, zig_target[0..split_idex], "-");
    ret.cpu.arch = std.meta.stringToEnum(std.Target.Cpu.Arch, iter.next().?).?;
    ret.cpu.model = try std.Target.Cpu.Arch.parseCpuModel(ret.cpu.arch, iter.next().?);
    const tag = std.meta.stringToEnum(std.Target.Os.Tag, iter.next().?).?;
    ret.os = std.Target.Os.Tag.defaultVersionRange(tag, ret.cpu.arch);
    ret.abi = std.meta.stringToEnum(std.Target.Abi, iter.next().?).?;
    return ret;
}
fn parseTargetsFromCode(set_list: *std.ArrayList(*Settings), source: []const u8, path: []const u8) !void {
    var lines = std.mem.tokenize(u8, source, "\n");
    while (lines.next()) |line| {
        if (std.mem.count(u8, line, "// MAPPING|") <= 0) continue;
        std.debug.assert(std.mem.count(u8, line, "|") > 1);
        var parts = std.mem.tokenize(u8, line, "|");
        _ = parts.next(); // skip the MAPPING bit
        const define = parts.next().?; // the define to set for this chunk.
        while (parts.next()) |target| {
            if (std.mem.startsWith(u8, target, "END")) break;
            var set = try fixie.create(Settings);
            set.c_define = define;
            set.target = target;
            // ok. the great filter.
            for (global_target_skip) |skip| {
                if (std.mem.eql(u8, target, skip)) {
                    set.skip_all = true;
                }
            }
            for (global_test_skip) |skip| {
                if (std.mem.count(u8, path, skip) > 0) {
                    // parse only.
                    set.c_define = null;
                }
            }
            for (test_control) |control| {
                if (std.mem.eql(u8, control.target, set.target)) {
                    for (control.non_working_tests) |skip| {
                        if (std.mem.count(u8, path, skip) > 0) {
                            set.c_define = null;
                            break;
                        }
                    }
                    for (control.skip_offset_checks) |skip| {
                        if (std.mem.count(u8, path, skip) > 0) {
                            set.check_offsets = false;
                            break;
                        }
                    }
                    for (control.skip_extra_checks) |skip| {
                        if (std.mem.count(u8, path, skip) > 0) {
                            set.extra_checks = false;
                            break;
                        }
                    }
                    break;
                }
            }
            try set_list.append(set);
        }
    }
}

fn setTarget(comp: *aro.Compilation, target: []const u8) !void {
    const zig_target = try getTarget(target);
    comp.target.cpu.arch = zig_target.cpu.arch;
    comp.target.cpu.model = zig_target.cpu.model;
    comp.target.os.tag = zig_target.os.tag;
    comp.target.os.version_range = zig_target.os.version_range;
    comp.target.abi = zig_target.abi;

    const split_idex = std.mem.indexOf(u8, target, ":").?;

    // var iter = std.mem.tokenize(u8, target[0..split_idex], "-");
    // comp.target.cpu.arch = std.meta.stringToEnum(std.Target.Cpu.Arch, iter.next().?).?;
    // comp.target.cpu.model = try std.Target.Cpu.Arch.parseCpuModel(comp.target.cpu.arch, iter.next().?);
    // const tag = std.meta.stringToEnum(std.Target.Os.Tag, iter.next().?).?;
    // comp.target.os = std.Target.Os.Tag.defaultVersionRange(tag, comp.target.cpu.arch);
    // comp.target.abi = std.meta.stringToEnum(std.Target.Abi, iter.next().?).?;

    comp.langopts.emulate = comp.systemCompiler();
    const c_name = target[split_idex + 1 ..];
    const m_name = @tagName(comp.langopts.emulate);
    std.debug.assert(std.ascii.eqlIgnoreCase(m_name, c_name));
}
