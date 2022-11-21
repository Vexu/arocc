const std = @import("std");
const mem = std.mem;
const Allocator = mem.Allocator;
const process = std.process;
const Codegen = @import("Codegen.zig");
const Compilation = @import("Compilation.zig");
const LangOpts = @import("LangOpts.zig");
const Preprocessor = @import("Preprocessor.zig");
const Parser = @import("Parser.zig");
const Source = @import("Source.zig");
const util = @import("util.zig");

var general_purpose_allocator = std.heap.GeneralPurposeAllocator(.{}){};

pub fn main() u8 {
    const gpa = if (@import("builtin").link_libc)
        std.heap.raw_c_allocator
    else
        general_purpose_allocator.allocator();
    defer if (!@import("builtin").link_libc) {
        _ = general_purpose_allocator.deinit();
    };

    var arena_instance = std.heap.ArenaAllocator.init(gpa);
    defer arena_instance.deinit();
    const arena = arena_instance.allocator();

    const fast_exit = @import("builtin").mode != .Debug;

    const args = process.argsAlloc(arena) catch {
        std.debug.print("out of memory\n", .{});
        if (fast_exit) std.process.exit(1);
        return 1;
    };

    var comp = Compilation.init(gpa);
    defer comp.deinit();

    comp.addDefaultPragmaHandlers() catch |er| switch (er) {
        error.OutOfMemory => {
            std.debug.print("out of memory\n", .{});
            if (fast_exit) std.process.exit(1);
            return 1;
        },
    };
    comp.langopts.setEmulatedCompiler(comp.systemCompiler());

    mainExtra(&comp, args) catch |er| switch (er) {
        error.OutOfMemory => {
            std.debug.print("out of memory\n", .{});
            if (fast_exit) std.process.exit(1);
            return 1;
        },
        error.StreamTooLong => {
            std.debug.print("maximum file size exceeded\n", .{});
            if (fast_exit) std.process.exit(1);
            return 1;
        },
        error.FatalError => {
            comp.renderErrors();
            if (fast_exit) std.process.exit(1);
            return 1;
        },
    };
    if (fast_exit) std.process.exit(@boolToInt(comp.diag.errors != 0));
    return @boolToInt(comp.diag.errors != 0);
}

const usage =
    \\Usage {s}: [options] file..
    \\
    \\General options:
    \\  -h, --help      Print this message.
    \\  -v, --version   Print aro version.
    \\
    \\Compile options:
    \\  -c                      Only run preprocess, compile, and assemble steps
    \\  -D <macro>=<value>      Define <macro> to <value> (defaults to 1)
    \\  -E                      Only run the preprocessor
    \\  -fcolor-diagnostics     Enable colors in diagnostics
    \\  -fno-color-diagnostics  Disable colors in diagnostics
    \\  -fdeclspec              Enable support for __declspec attributes
    \\  -fno-declspec           Disable support for __declspec attributes
    \\  -fms-extensions         Enable support for Microsoft extensions
    \\  -fno-ms-extensions      Disable support for Microsoft extensions
    \\  -fdollars-in-identifiers        
    \\                          Allow '$' in identifiers
    \\  -fno-dollars-in-identifiers     
    \\                          Disallow '$' in identifiers
    \\  -fmacro-backtrace-limit=<limit>
    \\                          Set limit on how many macro expansion traces are shown in errors (default 6)
    \\  -fshort-enums           Use the narrowest possible integer type for enums
    \\  -fno-short-enums        Use "int" as the tag type for enums
    \\  -I <dir>                Add directory to include search path
    \\  -isystem                Add directory to SYSTEM include search path
    \\  --emulate=[clang|gcc|msvc]
    \\                          Select which C compiler to emulate (default clang)
    \\  -o <file>               Write output to <file>
    \\  -pedantic               Warn on language extensions
    \\  -std=<standard>         Specify language standard
    \\  -S                      Only run preprocess and compilation steps
    \\  --target=<value>        Generate code for the given target
    \\  -U <macro>              Undefine <macro>
    \\  -Werror                 Treat all warnings as errors
    \\  -Werror=<warning>       Treat warning as error
    \\  -W<warning>             Enable the specified warning
    \\  -Wno-<warning>          Disable the specified warning
    \\
    \\Link options:
    \\  -fuse-ld=[bfd|gold|lld|mold]
    \\                          Use specific linker
    \\  --ld-path=<path>        Use linker specified by <path>
    \\
    \\Debug options:
    \\  --verbose-ast           Dump produced AST to stdout
    \\  --verbose-pp            Dump preprocessor state
    \\  --verbose-ir            Dump ir to stdout
    \\
    \\
;

fn option(arg: []const u8, name: []const u8) ?[]const u8 {
    if (std.mem.startsWith(u8, arg, name) and arg.len > name.len) {
        return arg[name.len..];
    }
    return null;
}

/// Process command line arguments, returns true if something was written to std_out.
pub fn parseArgs(
    comp: *Compilation,
    std_out: anytype,
    sources: *std.ArrayList(Source),
    link_objects: *std.ArrayList([]const u8),
    macro_buf: anytype,
    args: [][]const u8,
) !bool {
    var i: usize = 1;
    var color_setting: enum {
        on,
        off,
        unset,
    } = .unset;
    while (i < args.len) : (i += 1) {
        const arg = args[i];
        if (mem.startsWith(u8, arg, "-") and arg.len > 1) {
            if (mem.eql(u8, arg, "-h") or mem.eql(u8, arg, "--help")) {
                std_out.print(usage, .{args[0]}) catch |er| {
                    return fatal(comp, "unable to print usage: {s}", .{util.errorDescription(er)});
                };
                return true;
            } else if (mem.eql(u8, arg, "-v") or mem.eql(u8, arg, "--version")) {
                std_out.writeAll(@import("lib.zig").version_str ++ "\n") catch |er| {
                    return fatal(comp, "unable to print version: {s}", .{util.errorDescription(er)});
                };
                return true;
            } else if (mem.startsWith(u8, arg, "-D")) {
                var macro = arg["-D".len..];
                if (macro.len == 0) {
                    i += 1;
                    if (i >= args.len) {
                        try err(comp, "expected argument after -I");
                        continue;
                    }
                    macro = args[i];
                }
                var value: []const u8 = "1";
                if (mem.indexOfScalar(u8, macro, '=')) |some| {
                    value = macro[some + 1 ..];
                    macro = macro[0..some];
                }
                try macro_buf.print("#define {s} {s}\n", .{ macro, value });
            } else if (mem.startsWith(u8, arg, "-U")) {
                var macro = arg["-U".len..];
                if (macro.len == 0) {
                    i += 1;
                    if (i >= args.len) {
                        try err(comp, "expected argument after -I");
                        continue;
                    }
                    macro = args[i];
                }
                try macro_buf.print("#undef {s}\n", .{macro});
            } else if (mem.eql(u8, arg, "-c")) {
                comp.only_compile = true;
            } else if (mem.eql(u8, arg, "-E")) {
                comp.only_preprocess = true;
            } else if (mem.eql(u8, arg, "-fcolor-diagnostics")) {
                color_setting = .on;
            } else if (mem.eql(u8, arg, "-fno-color-diagnostics")) {
                color_setting = .off;
            } else if (mem.eql(u8, arg, "-fdollars-in-identifiers")) {
                comp.langopts.dollars_in_identifiers = true;
            } else if (mem.eql(u8, arg, "-fno-dollars-in-identifiers")) {
                comp.langopts.dollars_in_identifiers = false;
            } else if (mem.eql(u8, arg, "-fdigraphs")) {
                comp.langopts.digraphs = true;
            } else if (mem.eql(u8, arg, "-fno-digraphs")) {
                comp.langopts.digraphs = false;
            } else if (option(arg, "-fmacro-backtrace-limit=")) |limit_str| {
                var limit = std.fmt.parseInt(u32, limit_str, 10) catch {
                    try err(comp, "-fmacro-backtrace-limit takes a number argument");
                    continue;
                };

                if (limit == 0) limit = std.math.maxInt(u32);
                comp.diag.macro_backtrace_limit = limit;
            } else if (mem.eql(u8, arg, "-fshort-enums")) {
                comp.langopts.short_enums = true;
            } else if (mem.eql(u8, arg, "-fno-short-enums")) {
                comp.langopts.short_enums = false;
            } else if (mem.eql(u8, arg, "-fdeclspec")) {
                comp.langopts.declspec_attrs = true;
            } else if (mem.eql(u8, arg, "-fno-declspec")) {
                comp.langopts.declspec_attrs = false;
            } else if (mem.eql(u8, arg, "-fms-extensions")) {
                comp.langopts.enableMSExtensions();
            } else if (mem.eql(u8, arg, "-fno-ms-extensions")) {
                comp.langopts.disableMSExtensions();
            } else if (mem.startsWith(u8, arg, "-I")) {
                var path = arg["-I".len..];
                if (path.len == 0) {
                    i += 1;
                    if (i >= args.len) {
                        try err(comp, "expected argument after -I");
                        continue;
                    }
                    path = args[i];
                }
                try comp.include_dirs.append(path);
            } else if (mem.startsWith(u8, arg, "-isystem")) {
                var path = arg["-isystem".len..];
                if (path.len == 0) {
                    i += 1;
                    if (i >= args.len) {
                        try err(comp, "expected argument after -isystem");
                        continue;
                    }
                    path = args[i];
                }
                try comp.system_include_dirs.append(path);
            } else if (option(arg, "--emulate=")) |compiler_str| {
                const compiler = std.meta.stringToEnum(LangOpts.Compiler, compiler_str) orelse {
                    try comp.diag.add(.{ .tag = .cli_invalid_emulate, .extra = .{ .str = arg } }, &.{});
                    continue;
                };
                comp.langopts.setEmulatedCompiler(compiler);
            } else if (mem.startsWith(u8, arg, "-o")) {
                var file = arg["-o".len..];
                if (file.len == 0) {
                    i += 1;
                    if (i >= args.len) {
                        try err(comp, "expected argument after -o");
                        continue;
                    }
                    file = args[i];
                }
                comp.output_name = file;
            } else if (mem.eql(u8, arg, "-pedantic")) {
                comp.diag.options.pedantic = .warning;
            } else if (option(arg, "-Werror=")) |err_name| {
                try comp.diag.set(err_name, .@"error");
            } else if (mem.eql(u8, arg, "-Wno-fatal-errors")) {
                comp.diag.fatal_errors = false;
            } else if (option(arg, "-Wno-")) |err_name| {
                try comp.diag.set(err_name, .off);
            } else if (mem.eql(u8, arg, "-Wfatal-errors")) {
                comp.diag.fatal_errors = true;
            } else if (option(arg, "-W")) |err_name| {
                try comp.diag.set(err_name, .warning);
            } else if (option(arg, "-std=")) |standard| {
                comp.langopts.setStandard(standard) catch
                    try comp.diag.add(.{ .tag = .cli_invalid_standard, .extra = .{ .str = arg } }, &.{});
            } else if (mem.eql(u8, arg, "-S")) {
                comp.only_preprocess_and_compile = true;
            } else if (option(arg, "--target=")) |triple| {
                const cross = std.zig.CrossTarget.parse(.{ .arch_os_abi = triple }) catch {
                    try comp.diag.add(.{ .tag = .cli_invalid_target, .extra = .{ .str = arg } }, &.{});
                    continue;
                };
                comp.target = cross.toTarget(); // TODO deprecated
                comp.langopts.setEmulatedCompiler(comp.systemCompiler());
            } else if (mem.eql(u8, arg, "--verbose-ast")) {
                comp.verbose_ast = true;
            } else if (mem.eql(u8, arg, "--verbose-pp")) {
                comp.verbose_pp = true;
            } else if (mem.eql(u8, arg, "--verbose-ir")) {
                comp.verbose_ir = true;
            } else if (option(arg, "-fuse-ld=")) |linker_name| {
                comp.use_linker = std.meta.stringToEnum(Compilation.Linker, linker_name) orelse {
                    try comp.diag.add(.{ .tag = .cli_unknown_linker, .extra = .{ .str = arg } }, &.{});
                    continue;
                };
            } else if (option(arg, "--ld-path=")) |linker_path| {
                comp.linker_path = linker_path;
            } else {
                try comp.diag.add(.{ .tag = .cli_unknown_arg, .extra = .{ .str = arg } }, &.{});
            }
        } else if (std.mem.endsWith(u8, arg, ".o") or std.mem.endsWith(u8, arg, ".obj")) {
            try link_objects.append(arg);
        } else {
            const file = addSource(comp, arg) catch |er| {
                return fatal(comp, "unable to add source file '{s}': {s}", .{ arg, util.errorDescription(er) });
            };
            try sources.append(file);
        }
    }
    comp.diag.color = switch (color_setting) {
        .on => true,
        .off => false,
        .unset => util.fileSupportsColor(std.io.getStdOut()) and !std.process.hasEnvVarConstant("NO_COLOR"),
    };
    return false;
}

fn addSource(comp: *Compilation, path: []const u8) !Source {
    return comp.addSourceFromPath(path) catch |er| switch (er) {
        error.FileNotFound => {
            if (mem.eql(u8, "-", path)) {
                const stdin = std.io.getStdIn().reader();
                const input = try stdin.readAllAlloc(comp.gpa, std.math.maxInt(u32));
                defer comp.gpa.free(input);
                return comp.addSourceFromBuffer("<stdin>", input);
            }
            return er;
        },
        else => return er,
    };
}

fn err(comp: *Compilation, msg: []const u8) !void {
    try comp.diag.add(.{ .tag = .cli_error, .extra = .{ .str = msg } }, &.{});
}

fn fatal(comp: *Compilation, comptime fmt: []const u8, args: anytype) error{FatalError} {
    comp.renderErrors();
    return comp.diag.fatalNoSrc(fmt, args);
}

fn mainExtra(comp: *Compilation, args: [][]const u8) !void {
    var source_files = std.ArrayList(Source).init(comp.gpa);
    defer source_files.deinit();

    var link_objects = std.ArrayList([]const u8).init(comp.gpa);
    defer link_objects.deinit();

    var macro_buf = std.ArrayList(u8).init(comp.gpa);
    defer macro_buf.deinit();

    const std_out = std.io.getStdOut().writer();
    if (try parseArgs(comp, std_out, &source_files, &link_objects, macro_buf.writer(), args)) return;

    const linking = !(comp.only_preprocess or comp.only_compile or comp.only_preprocess_and_compile);
    var temp_file_count: u32 = 0;
    defer if (linking) for (link_objects.items[link_objects.items.len - temp_file_count ..]) |obj| {
        std.fs.deleteFileAbsolute(obj) catch {};
        comp.gpa.free(obj);
    };

    if (source_files.items.len == 0) {
        return fatal(comp, "no input files", .{});
    } else if (source_files.items.len != 1 and comp.output_name != null and !linking) {
        return fatal(comp, "cannot specify -o when generating multiple output files", .{});
    }

    if (!linking) for (link_objects.items) |obj| {
        try comp.diag.add(.{ .tag = .cli_unused_link_object, .extra = .{ .str = obj } }, &.{});
    };

    if (linking and comp.linker_path == null) {
        comp.linker_path = comp.getLinkerPath();
    }

    comp.defineSystemIncludes() catch |er| switch (er) {
        error.OutOfMemory => return error.OutOfMemory,
        error.SelfExeNotFound => return fatal(comp, "unable to find Aro executable path", .{}),
        error.AroIncludeNotFound => return fatal(comp, "unable to find Aro builtin headers", .{}),
    };

    const builtin = try comp.generateBuiltinMacros();
    const user_macros = try comp.addSourceFromBuffer("<command line>", macro_buf.items);

    const fast_exit = @import("builtin").mode != .Debug;

    if (fast_exit and source_files.items.len == 1) {
        processSource(comp, source_files.items[0], &link_objects, &temp_file_count, builtin, user_macros, fast_exit) catch |e| switch (e) {
            error.OutOfMemory => return error.OutOfMemory,
            error.FatalError => {
                comp.renderErrors();
                exitWithCleanup(link_objects.items, temp_file_count, 1);
            },
        };
        unreachable;
    }

    for (source_files.items) |source| {
        processSource(comp, source, &link_objects, &temp_file_count, builtin, user_macros, fast_exit) catch |e| switch (e) {
            error.OutOfMemory => return error.OutOfMemory,
            error.FatalError => {
                comp.renderErrors();
            },
        };
    }
    if (comp.diag.errors != 0) {
        if (fast_exit) exitWithCleanup(link_objects.items, temp_file_count, 1);
        return;
    }
    if (linking) {
        try invokeLinker(comp, link_objects.items, temp_file_count);
        if (fast_exit) exitWithCleanup(link_objects.items, temp_file_count, 0);
    }
    if (fast_exit) std.process.exit(0);
}

fn processSource(
    comp: *Compilation,
    source: Source,
    link_objects: *std.ArrayList([]const u8),
    temp_file_count: *u32,
    builtin: Source,
    user_macros: Source,
    comptime fast_exit: bool,
) !void {
    comp.generated_buf.items.len = 0;
    var pp = Preprocessor.init(comp);
    defer pp.deinit();
    try pp.addBuiltinMacros();

    _ = try pp.preprocess(builtin);
    _ = try pp.preprocess(user_macros);
    const eof = try pp.preprocess(source);
    try pp.tokens.append(pp.comp.gpa, eof);

    if (comp.only_preprocess) {
        comp.renderErrors();

        const file = if (comp.output_name) |some|
            std.fs.cwd().createFile(some, .{}) catch |er|
                return fatal(comp, "unable to create output file '{s}': {s}", .{ some, util.errorDescription(er) })
        else
            std.io.getStdOut();
        defer if (comp.output_name != null) file.close();

        var buf_w = std.io.bufferedWriter(file.writer());
        pp.prettyPrintTokens(buf_w.writer()) catch |er|
            return fatal(comp, "unable to write result: {s}", .{util.errorDescription(er)});

        buf_w.flush() catch |er|
            return fatal(comp, "unable to write result: {s}", .{util.errorDescription(er)});
        if (fast_exit) std.process.exit(0); // Not linking, no need for cleanup.
        return;
    }

    var tree = try Parser.parse(&pp);
    defer tree.deinit();

    if (comp.verbose_ast) {
        const stdout = std.io.getStdOut();
        var buf_writer = std.io.bufferedWriter(stdout.writer());
        const color = comp.diag.color and util.fileSupportsColor(stdout);
        tree.dump(color, buf_writer.writer()) catch {};
        buf_writer.flush() catch {};
    }

    const prev_errors = comp.diag.errors;
    comp.renderErrors();

    if (comp.diag.errors != prev_errors) {
        if (fast_exit) exitWithCleanup(link_objects.items, temp_file_count.*, 1);
        return; // do not compile if there were errors
    }

    if (comp.target.ofmt != .elf or comp.target.cpu.arch != .x86_64) {
        return fatal(
            comp,
            "unsupported target {s}-{s}-{s}, currently only x86-64 elf is supported",
            .{ @tagName(comp.target.cpu.arch), @tagName(comp.target.os.tag), @tagName(comp.target.abi) },
        );
    }

    if (comp.verbose_ir) {
        try @import("IrBuilder.zig").generateTree(comp, tree);
    }

    const obj = try Codegen.generateTree(comp, tree);
    defer obj.deinit();

    const out_file_name = if (comp.only_compile) blk: {
        const basename = std.fs.path.basename(source.path);
        break :blk comp.output_name orelse try std.fmt.allocPrint(comp.gpa, "{s}{s}", .{
            basename[0 .. basename.len - std.fs.path.extension(source.path).len],
            comp.target.ofmt.fileExt(comp.target.cpu.arch),
        });
    } else blk: {
        const random_bytes_count = 12;
        const sub_path_len = comptime std.fs.base64_encoder.calcSize(random_bytes_count);

        var random_bytes: [random_bytes_count]u8 = undefined;
        std.crypto.random.bytes(&random_bytes);
        var random_name: [sub_path_len]u8 = undefined;
        _ = std.fs.base64_encoder.encode(&random_name, &random_bytes);

        break :blk try std.fmt.allocPrint(comp.gpa, "/tmp/{s}{s}", .{
            random_name, comp.target.ofmt.fileExt(comp.target.cpu.arch),
        });
    };
    defer if (comp.only_compile) comp.gpa.free(out_file_name);

    const out_file = std.fs.cwd().createFile(out_file_name, .{}) catch |er|
        return fatal(comp, "unable to create output file '{s}': {s}", .{ out_file_name, util.errorDescription(er) });
    defer out_file.close();

    obj.finish(out_file) catch |er|
        return fatal(comp, "could output to object file '{s}': {s}", .{ out_file_name, util.errorDescription(er) });

    if (comp.only_compile) {
        if (fast_exit) std.process.exit(0); // Not linking, no need for cleanup.
        return;
    }

    try link_objects.append(out_file_name);
    temp_file_count.* += 1;
    if (fast_exit) {
        try invokeLinker(comp, link_objects.items, temp_file_count.*);
        exitWithCleanup(link_objects.items, temp_file_count.*, 0);
    }
}

fn invokeLinker(comp: *Compilation, link_objects: []const []const u8, temp_file_count: u32) !void {
    const args_len = 1 // linker name
    + 2 // -o output
    + 2 // -dynamic-linker <path>
    + 1 // -lc
    + 1 // Scrt1.0
    + link_objects.len;

    var argv = try std.ArrayList([]const u8).initCapacity(comp.gpa, args_len);
    defer argv.deinit();

    argv.appendAssumeCapacity(comp.linker_path.?);
    argv.appendAssumeCapacity("-o");
    argv.appendAssumeCapacity(comp.output_name orelse "a.out");
    argv.appendAssumeCapacity("-dynamic-linker");
    argv.appendAssumeCapacity(comp.target.standardDynamicLinkerPath().get().?);
    argv.appendAssumeCapacity("-lc");
    argv.appendAssumeCapacity("/usr/lib/Scrt1.o"); // TODO very bad
    argv.appendSliceAssumeCapacity(link_objects);

    var child = std.ChildProcess.init(argv.items, comp.gpa);
    // TODO handle better
    child.stdin_behavior = .Inherit;
    child.stdout_behavior = .Inherit;
    child.stderr_behavior = .Inherit;

    const term = child.spawnAndWait() catch |er| {
        return fatal(comp, "unable to spawn linker: {s}", .{util.errorDescription(er)});
    };
    switch (term) {
        .Exited => |code| if (code != 0) exitWithCleanup(link_objects, temp_file_count, code),
        else => std.process.abort(),
    }
    if (@import("builtin").mode != .Debug) exitWithCleanup(link_objects, temp_file_count, 1);
}

fn exitWithCleanup(link_objects: []const []const u8, temp_file_count: u32, code: u8) noreturn {
    for (link_objects[link_objects.len - temp_file_count ..]) |obj| {
        std.fs.deleteFileAbsolute(obj) catch {};
    }
    std.process.exit(code);
}

test {
    _ = @import("Codegen.zig");
    _ = @import("Compilation.zig");
    _ = @import("Diagnostics.zig");
    _ = @import("InitList.zig");
    _ = @import("LangOpts.zig");
    _ = @import("Parser.zig");
    _ = @import("Pragma.zig");
    _ = @import("Preprocessor.zig");
    _ = @import("Source.zig");
    _ = @import("Tokenizer.zig");
    _ = @import("Tree.zig");
    _ = @import("Type.zig");
}
