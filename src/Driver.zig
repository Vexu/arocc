const std = @import("std");
const mem = std.mem;
const Allocator = mem.Allocator;
const process = std.process;
const Codegen = @import("Codegen_legacy.zig");
const Compilation = @import("Compilation.zig");
const LangOpts = @import("LangOpts.zig");
const Preprocessor = @import("Preprocessor.zig");
const Parser = @import("Parser.zig");
const Source = @import("Source.zig");
const util = @import("util.zig");
const target_util = @import("target.zig");

const Driver = @This();

pub const Linker = enum {
    ld,
    bfd,
    gold,
    lld,
    mold,
};

comp: *Compilation,
inputs: std.ArrayListUnmanaged(Source) = .{},
link_objects: std.ArrayListUnmanaged([]const u8) = .{},
output_name: ?[]const u8 = null,
temp_file_count: u32 = 0,
only_preprocess: bool = false,
only_syntax: bool = false,
only_compile: bool = false,
only_preprocess_and_compile: bool = false,
verbose_ast: bool = false,
verbose_pp: bool = false,
verbose_ir: bool = false,

// linker options
use_linker: Linker = .ld,
linker_path: ?[]const u8 = null,

pub fn deinit(d: *Driver) void {
    const linking = !(d.only_preprocess or d.only_syntax or d.only_compile or d.only_preprocess_and_compile);
    if (linking) for (d.link_objects.items[d.link_objects.items.len - d.temp_file_count ..]) |obj| {
        std.fs.deleteFileAbsolute(obj) catch {};
        d.comp.gpa.free(obj);
    };
    d.inputs.deinit(d.comp.gpa);
    d.link_objects.deinit(d.comp.gpa);
    d.* = undefined;
}

pub const usage =
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
    \\  -fchar8_t               Enable char8_t (enabled by default in C2X and later)
    \\  -fno-char8_t            Disable char8_t (disabled by default for pre-C2X)
    \\  -fcolor-diagnostics     Enable colors in diagnostics
    \\  -fno-color-diagnostics  Disable colors in diagnostics
    \\  -fdeclspec              Enable support for __declspec attributes
    \\  -fno-declspec           Disable support for __declspec attributes
    \\  -ffp-eval-method=[source|double|extended]
    \\                          Evaluation method to use for floating-point arithmetic
    \\  -fms-extensions         Enable support for Microsoft extensions
    \\  -fno-ms-extensions      Disable support for Microsoft extensions
    \\  -fdollars-in-identifiers        
    \\                          Allow '$' in identifiers
    \\  -fno-dollars-in-identifiers     
    \\                          Disallow '$' in identifiers
    \\  -fmacro-backtrace-limit=<limit>
    \\                          Set limit on how many macro expansion traces are shown in errors (default 6)
    \\  -fnative-half-type      Use the native half type for __fp16 instead of promoting to float
    \\  -fnative-half-arguments-and-returns
    \\                          Allow half-precision function arguments and return values
    \\  -fshort-enums           Use the narrowest possible integer type for enums
    \\  -fno-short-enums        Use "int" as the tag type for enums
    \\  -fsigned-char           "char" is signed
    \\  -fno-signed-char        "char" is unsigned
    \\  -fsyntax-only           Only run the preprocessor, parser, and semantic analysis stages
    \\  -funsigned-char         "char" is unsigned
    \\  -fno-unsigned-char      "char" is signed
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

/// Process command line arguments, returns true if something was written to std_out.
pub fn parseArgs(
    d: *Driver,
    std_out: anytype,
    macro_buf: anytype,
    args: []const []const u8,
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
                    return d.fatal("unable to print usage: {s}", .{util.errorDescription(er)});
                };
                return true;
            } else if (mem.eql(u8, arg, "-v") or mem.eql(u8, arg, "--version")) {
                std_out.writeAll(@import("lib.zig").version_str ++ "\n") catch |er| {
                    return d.fatal("unable to print version: {s}", .{util.errorDescription(er)});
                };
                return true;
            } else if (mem.startsWith(u8, arg, "-D")) {
                var macro = arg["-D".len..];
                if (macro.len == 0) {
                    i += 1;
                    if (i >= args.len) {
                        try d.err("expected argument after -I");
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
                        try d.err("expected argument after -I");
                        continue;
                    }
                    macro = args[i];
                }
                try macro_buf.print("#undef {s}\n", .{macro});
            } else if (mem.eql(u8, arg, "-c")) {
                d.only_compile = true;
            } else if (mem.eql(u8, arg, "-E")) {
                d.only_preprocess = true;
            } else if (mem.eql(u8, arg, "-fchar8_t")) {
                d.comp.langopts.has_char8_t_override = true;
            } else if (mem.eql(u8, arg, "-fno-char8_t")) {
                d.comp.langopts.has_char8_t_override = false;
            } else if (mem.eql(u8, arg, "-fcolor-diagnostics")) {
                color_setting = .on;
            } else if (mem.eql(u8, arg, "-fno-color-diagnostics")) {
                color_setting = .off;
            } else if (mem.eql(u8, arg, "-fdollars-in-identifiers")) {
                d.comp.langopts.dollars_in_identifiers = true;
            } else if (mem.eql(u8, arg, "-fno-dollars-in-identifiers")) {
                d.comp.langopts.dollars_in_identifiers = false;
            } else if (mem.eql(u8, arg, "-fdigraphs")) {
                d.comp.langopts.digraphs = true;
            } else if (mem.eql(u8, arg, "-fno-digraphs")) {
                d.comp.langopts.digraphs = false;
            } else if (option(arg, "-fmacro-backtrace-limit=")) |limit_str| {
                var limit = std.fmt.parseInt(u32, limit_str, 10) catch {
                    try d.err("-fmacro-backtrace-limit takes a number argument");
                    continue;
                };

                if (limit == 0) limit = std.math.maxInt(u32);
                d.comp.diag.macro_backtrace_limit = limit;
            } else if (mem.eql(u8, arg, "-fnative-half-type")) {
                d.comp.langopts.use_native_half_type = true;
            } else if (mem.eql(u8, arg, "-fnative-half-arguments-and-returns")) {
                d.comp.langopts.allow_half_args_and_returns = true;
            } else if (mem.eql(u8, arg, "-fshort-enums")) {
                d.comp.langopts.short_enums = true;
            } else if (mem.eql(u8, arg, "-fno-short-enums")) {
                d.comp.langopts.short_enums = false;
            } else if (mem.eql(u8, arg, "-fsigned-char")) {
                d.comp.langopts.setCharSignedness(.signed);
            } else if (mem.eql(u8, arg, "-fno-signed-char")) {
                d.comp.langopts.setCharSignedness(.unsigned);
            } else if (mem.eql(u8, arg, "-funsigned-char")) {
                d.comp.langopts.setCharSignedness(.unsigned);
            } else if (mem.eql(u8, arg, "-fno-unsigned-char")) {
                d.comp.langopts.setCharSignedness(.signed);
            } else if (mem.eql(u8, arg, "-fdeclspec")) {
                d.comp.langopts.declspec_attrs = true;
            } else if (mem.eql(u8, arg, "-fno-declspec")) {
                d.comp.langopts.declspec_attrs = false;
            } else if (mem.eql(u8, arg, "-fms-extensions")) {
                d.comp.langopts.enableMSExtensions();
            } else if (mem.eql(u8, arg, "-fno-ms-extensions")) {
                d.comp.langopts.disableMSExtensions();
            } else if (mem.startsWith(u8, arg, "-I")) {
                var path = arg["-I".len..];
                if (path.len == 0) {
                    i += 1;
                    if (i >= args.len) {
                        try d.err("expected argument after -I");
                        continue;
                    }
                    path = args[i];
                }
                try d.comp.include_dirs.append(path);
            } else if (mem.startsWith(u8, arg, "-fsyntax-only")) {
                d.only_syntax = true;
            } else if (mem.startsWith(u8, arg, "-fno-syntax-only")) {
                d.only_syntax = false;
            } else if (mem.startsWith(u8, arg, "-isystem")) {
                var path = arg["-isystem".len..];
                if (path.len == 0) {
                    i += 1;
                    if (i >= args.len) {
                        try d.err("expected argument after -isystem");
                        continue;
                    }
                    path = args[i];
                }
                const duped = try d.comp.gpa.dupe(u8, path);
                errdefer d.comp.gpa.free(duped);
                try d.comp.system_include_dirs.append(duped);
            } else if (option(arg, "--emulate=")) |compiler_str| {
                const compiler = std.meta.stringToEnum(LangOpts.Compiler, compiler_str) orelse {
                    try d.comp.diag.add(.{ .tag = .cli_invalid_emulate, .extra = .{ .str = arg } }, &.{});
                    continue;
                };
                d.comp.langopts.setEmulatedCompiler(compiler);
            } else if (option(arg, "-ffp-eval-method=")) |fp_method_str| {
                const fp_eval_method = std.meta.stringToEnum(LangOpts.FPEvalMethod, fp_method_str) orelse .indeterminate;
                if (fp_eval_method == .indeterminate) {
                    try d.comp.diag.add(.{ .tag = .cli_invalid_fp_eval_method, .extra = .{ .str = fp_method_str } }, &.{});
                    continue;
                }
                d.comp.langopts.setFpEvalMethod(fp_eval_method);
            } else if (mem.startsWith(u8, arg, "-o")) {
                var file = arg["-o".len..];
                if (file.len == 0) {
                    i += 1;
                    if (i >= args.len) {
                        try d.err("expected argument after -o");
                        continue;
                    }
                    file = args[i];
                }
                d.output_name = file;
            } else if (mem.eql(u8, arg, "-pedantic")) {
                d.comp.diag.options.pedantic = .warning;
            } else if (option(arg, "-Werror=")) |err_name| {
                try d.comp.diag.set(err_name, .@"error");
            } else if (mem.eql(u8, arg, "-Wno-fatal-errors")) {
                d.comp.diag.fatal_errors = false;
            } else if (option(arg, "-Wno-")) |err_name| {
                try d.comp.diag.set(err_name, .off);
            } else if (mem.eql(u8, arg, "-Wfatal-errors")) {
                d.comp.diag.fatal_errors = true;
            } else if (option(arg, "-W")) |err_name| {
                try d.comp.diag.set(err_name, .warning);
            } else if (option(arg, "-std=")) |standard| {
                d.comp.langopts.setStandard(standard) catch
                    try d.comp.diag.add(.{ .tag = .cli_invalid_standard, .extra = .{ .str = arg } }, &.{});
            } else if (mem.eql(u8, arg, "-S")) {
                d.only_preprocess_and_compile = true;
            } else if (option(arg, "--target=")) |triple| {
                const cross = std.zig.CrossTarget.parse(.{ .arch_os_abi = triple }) catch {
                    try d.comp.diag.add(.{ .tag = .cli_invalid_target, .extra = .{ .str = arg } }, &.{});
                    continue;
                };
                d.comp.target = cross.toTarget(); // TODO deprecated
                d.comp.langopts.setEmulatedCompiler(target_util.systemCompiler(d.comp.target));
            } else if (mem.eql(u8, arg, "--verbose-ast")) {
                d.verbose_ast = true;
            } else if (mem.eql(u8, arg, "--verbose-pp")) {
                d.verbose_pp = true;
            } else if (mem.eql(u8, arg, "--verbose-ir")) {
                d.verbose_ir = true;
            } else if (option(arg, "-fuse-ld=")) |linker_name| {
                d.use_linker = std.meta.stringToEnum(Linker, linker_name) orelse {
                    try d.comp.diag.add(.{ .tag = .cli_unknown_linker, .extra = .{ .str = arg } }, &.{});
                    continue;
                };
            } else if (option(arg, "--ld-path=")) |linker_path| {
                d.linker_path = linker_path;
            } else {
                try d.comp.diag.add(.{ .tag = .cli_unknown_arg, .extra = .{ .str = arg } }, &.{});
            }
        } else if (std.mem.endsWith(u8, arg, ".o") or std.mem.endsWith(u8, arg, ".obj")) {
            try d.link_objects.append(d.comp.gpa, arg);
        } else {
            const source = d.addSource(arg) catch |er| {
                return d.fatal("unable to add source file '{s}': {s}", .{ arg, util.errorDescription(er) });
            };
            try d.inputs.append(d.comp.gpa, source);
        }
    }
    d.comp.diag.color = switch (color_setting) {
        .on => true,
        .off => false,
        .unset => util.fileSupportsColor(std.io.getStdErr()) and !std.process.hasEnvVarConstant("NO_COLOR"),
    };
    return false;
}

fn option(arg: []const u8, name: []const u8) ?[]const u8 {
    if (std.mem.startsWith(u8, arg, name) and arg.len > name.len) {
        return arg[name.len..];
    }
    return null;
}

fn addSource(d: *Driver, path: []const u8) !Source {
    if (mem.eql(u8, "-", path)) {
        const stdin = std.io.getStdIn().reader();
        const input = try stdin.readAllAlloc(d.comp.gpa, std.math.maxInt(u32));
        defer d.comp.gpa.free(input);
        return d.comp.addSourceFromBuffer("<stdin>", input);
    }
    return d.comp.addSourceFromPath(path);
}

fn err(d: *Driver, msg: []const u8) !void {
    try d.comp.diag.add(.{ .tag = .cli_error, .extra = .{ .str = msg } }, &.{});
}

fn fatal(d: *Driver, comptime fmt: []const u8, args: anytype) error{FatalError} {
    d.comp.renderErrors();
    return d.comp.diag.fatalNoSrc(fmt, args);
}

pub fn main(d: *Driver, args: []const []const u8) !void {
    var macro_buf = std.ArrayList(u8).init(d.comp.gpa);
    defer macro_buf.deinit();

    const std_out = std.io.getStdOut().writer();
    if (try parseArgs(d, std_out, macro_buf.writer(), args)) return;

    const linking = !(d.only_preprocess or d.only_syntax or d.only_compile or d.only_preprocess_and_compile);
    if (d.inputs.items.len == 0) {
        return d.fatal("no input files", .{});
    } else if (d.inputs.items.len != 1 and d.output_name != null and !linking) {
        return d.fatal("cannot specify -o when generating multiple output files", .{});
    }

    if (!linking) for (d.link_objects.items) |obj| {
        try d.comp.diag.add(.{ .tag = .cli_unused_link_object, .extra = .{ .str = obj } }, &.{});
    };

    if (linking and d.linker_path == null) {
        d.linker_path = d.getLinkerPath();
    }

    d.comp.defineSystemIncludes() catch |er| switch (er) {
        error.OutOfMemory => return error.OutOfMemory,
        error.SelfExeNotFound => return d.fatal("unable to find Aro executable path", .{}),
        error.AroIncludeNotFound => return d.fatal("unable to find Aro builtin headers", .{}),
    };

    const builtin = try d.comp.generateBuiltinMacros();
    const user_macros = try d.comp.addSourceFromBuffer("<command line>", macro_buf.items);

    const fast_exit = @import("builtin").mode != .Debug;

    if (fast_exit and d.inputs.items.len == 1) {
        d.processSource(d.inputs.items[0], builtin, user_macros, fast_exit) catch |e| switch (e) {
            error.OutOfMemory => return error.OutOfMemory,
            error.FatalError => {
                d.comp.renderErrors();
                d.exitWithCleanup(1);
            },
        };
        unreachable;
    }

    for (d.inputs.items) |source| {
        d.processSource(source, builtin, user_macros, fast_exit) catch |e| switch (e) {
            error.OutOfMemory => return error.OutOfMemory,
            error.FatalError => {
                d.comp.renderErrors();
            },
        };
    }
    if (d.comp.diag.errors != 0) {
        if (fast_exit) d.exitWithCleanup(1);
        return;
    }
    if (linking) {
        try d.invokeLinker();
        if (fast_exit) d.exitWithCleanup(0);
    }
    if (fast_exit) std.process.exit(0);
}

fn processSource(
    d: *Driver,
    source: Source,
    builtin: Source,
    user_macros: Source,
    comptime fast_exit: bool,
) !void {
    d.comp.generated_buf.items.len = 0;
    var pp = Preprocessor.init(d.comp);
    defer pp.deinit();

    if (d.verbose_pp) pp.verbose = true;
    if (d.only_preprocess) pp.preserve_whitespace = true;
    try pp.addBuiltinMacros();

    _ = try pp.preprocess(builtin);
    _ = try pp.preprocess(user_macros);
    const eof = try pp.preprocess(source);
    try pp.tokens.append(pp.comp.gpa, eof);

    if (d.only_preprocess) {
        d.comp.renderErrors();

        const file = if (d.output_name) |some|
            std.fs.cwd().createFile(some, .{}) catch |er|
                return d.fatal("unable to create output file '{s}': {s}", .{ some, util.errorDescription(er) })
        else
            std.io.getStdOut();
        defer if (d.output_name != null) file.close();

        var buf_w = std.io.bufferedWriter(file.writer());
        pp.prettyPrintTokens(buf_w.writer()) catch |er|
            return d.fatal("unable to write result: {s}", .{util.errorDescription(er)});

        buf_w.flush() catch |er|
            return d.fatal("unable to write result: {s}", .{util.errorDescription(er)});
        if (fast_exit) std.process.exit(0); // Not linking, no need for cleanup.
        return;
    }

    var tree = try Parser.parse(&pp);
    defer tree.deinit();

    if (d.verbose_ast) {
        const stdout = std.io.getStdOut();
        var buf_writer = std.io.bufferedWriter(stdout.writer());
        const color = d.comp.diag.color and util.fileSupportsColor(stdout);
        tree.dump(color, buf_writer.writer()) catch {};
        buf_writer.flush() catch {};
    }

    const prev_errors = d.comp.diag.errors;
    d.comp.renderErrors();

    if (d.comp.diag.errors != prev_errors) {
        if (fast_exit) d.exitWithCleanup(1);
        return; // do not compile if there were errors
    }

    if (d.only_syntax) {
        if (fast_exit) std.process.exit(0); // Not linking, no need for cleanup.
        return;
    }

    if (d.comp.target.ofmt != .elf or d.comp.target.cpu.arch != .x86_64) {
        return d.fatal(
            "unsupported target {s}-{s}-{s}, currently only x86-64 elf is supported",
            .{ @tagName(d.comp.target.cpu.arch), @tagName(d.comp.target.os.tag), @tagName(d.comp.target.abi) },
        );
    }

    if (d.verbose_ir) {
        try @import("CodeGen.zig").generateTree(d.comp, tree);
    }

    const obj = try Codegen.generateTree(d.comp, tree);
    defer obj.deinit();

    const out_file_name = if (d.only_compile) blk: {
        break :blk d.output_name orelse try std.fmt.allocPrint(d.comp.gpa, "{s}{s}", .{
            std.fs.path.stem(source.path),
            d.comp.target.ofmt.fileExt(d.comp.target.cpu.arch),
        });
    } else blk: {
        const random_bytes_count = 12;
        const sub_path_len = comptime std.fs.base64_encoder.calcSize(random_bytes_count);

        var random_bytes: [random_bytes_count]u8 = undefined;
        std.crypto.random.bytes(&random_bytes);
        var random_name: [sub_path_len]u8 = undefined;
        _ = std.fs.base64_encoder.encode(&random_name, &random_bytes);

        break :blk try std.fmt.allocPrint(d.comp.gpa, "/tmp/{s}{s}", .{
            random_name, d.comp.target.ofmt.fileExt(d.comp.target.cpu.arch),
        });
    };
    defer if (d.only_compile) d.comp.gpa.free(out_file_name);

    const out_file = std.fs.cwd().createFile(out_file_name, .{}) catch |er|
        return d.fatal("unable to create output file '{s}': {s}", .{ out_file_name, util.errorDescription(er) });
    defer out_file.close();

    obj.finish(out_file) catch |er|
        return d.fatal("could output to object file '{s}': {s}", .{ out_file_name, util.errorDescription(er) });

    if (d.only_compile) {
        if (fast_exit) std.process.exit(0); // Not linking, no need for cleanup.
        return;
    }

    try d.link_objects.append(d.comp.gpa, out_file_name);
    d.temp_file_count += 1;
    if (fast_exit) {
        try d.invokeLinker();
        d.exitWithCleanup(0);
    }
}

pub fn invokeLinker(d: *Driver) !void {
    const args_len = 1 // linker name
    + 2 // -o output
    + 2 // -dynamic-linker <path>
    + 1 // -lc
    + 1 // Scrt1.0
    + d.link_objects.items.len;

    var argv = try std.ArrayList([]const u8).initCapacity(d.comp.gpa, args_len);
    defer argv.deinit();

    argv.appendAssumeCapacity(d.linker_path.?);
    argv.appendAssumeCapacity("-o");
    argv.appendAssumeCapacity(d.output_name orelse "a.out");
    argv.appendAssumeCapacity("-dynamic-linker");
    argv.appendAssumeCapacity(d.comp.target.standardDynamicLinkerPath().get().?);
    argv.appendAssumeCapacity("-lc");
    argv.appendAssumeCapacity("/usr/lib/Scrt1.o"); // TODO very bad
    argv.appendSliceAssumeCapacity(d.link_objects.items);

    var child = std.ChildProcess.init(argv.items, d.comp.gpa);
    // TODO handle better
    child.stdin_behavior = .Inherit;
    child.stdout_behavior = .Inherit;
    child.stderr_behavior = .Inherit;

    const term = child.spawnAndWait() catch |er| {
        return d.fatal("unable to spawn linker: {s}", .{util.errorDescription(er)});
    };
    switch (term) {
        .Exited => |code| if (code != 0) d.exitWithCleanup(code),
        else => std.process.abort(),
    }
    if (@import("builtin").mode != .Debug) d.exitWithCleanup(1);
}

fn exitWithCleanup(d: *Driver, code: u8) noreturn {
    for (d.link_objects.items[d.link_objects.items.len - d.temp_file_count ..]) |obj| {
        std.fs.deleteFileAbsolute(obj) catch {};
    }
    std.process.exit(code);
}

pub fn getLinkerPath(d: *Driver) []const u8 {
    // TODO extremely incomplete
    return switch (d.use_linker) {
        .ld => "/usr/bin/ld",
        .bfd => "/usr/bin/ld.bfd",
        .gold => "/usr/bin/ld.gold",
        .lld => "/usr/bin/ld.lld",
        .mold => "/usr/bin/ld.mold",
    };
}
