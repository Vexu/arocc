const std = @import("std");
const mem = std.mem;
const Allocator = mem.Allocator;
const process = std.process;
const Codegen = @import("Codegen.zig");
const Compilation = @import("Compilation.zig");
const Source = @import("Source.zig");
const Preprocessor = @import("Preprocessor.zig");
const Parser = @import("Parser.zig");

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

    const args = process.argsAlloc(arena) catch {
        std.debug.print("out of memory\n", .{});
        return 1;
    };

    var comp = Compilation.init(gpa);
    defer comp.deinit();

    comp.addDefaultPragmaHandlers() catch |err| switch (err) {
        error.OutOfMemory => {
            std.debug.print("out of memory\n", .{});
            return 1;
        },
    };

    handleArgs(&comp, args) catch |err| switch (err) {
        error.OutOfMemory => {
            std.debug.print("out of memory\n", .{});
            return 1;
        },
        error.FatalError => comp.renderErrors(),
    };
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
    \\  -o <file>               Write output to <file>
    \\  -std=<standard>         Specify language standard
    \\  --target=<value>        Generate code for the given target
    \\  -U <macro>              Undefine <macro>
    \\  -Wall                   Enable all warnings
    \\  -Werror                 Treat all warnings as errors
    \\  -Werror=<warning>       Treat warning as error
    \\  -W<warning>             Enable the specified warning
    \\  -Wno-<warning>          Disable the specified warning
    \\
    \\Depub options:
    \\  --verbose-ast           Dump produced AST to stdout
    \\
    \\
;

fn handleArgs(comp: *Compilation, args: [][]const u8) !void {
    comp.defineSystemIncludes() catch |err| switch (err) {
        error.OutOfMemory => return error.OutOfMemory,
        error.SelfExeNotFound => return comp.diag.fatalNoSrc("could not find Aro executable path", .{}),
        error.AroIncludeNotFound => return comp.diag.fatalNoSrc("could not find Aro builtin headers", .{}),
    };

    var source_files = std.ArrayList(Source).init(comp.gpa);
    defer source_files.deinit();

    var macro_buf = std.ArrayList(u8).init(comp.gpa);
    defer macro_buf.deinit();

    var i: usize = 1;
    while (i < args.len) : (i += 1) {
        const arg = args[i];
        if (mem.startsWith(u8, arg, "-")) {
            if (mem.eql(u8, arg, "-h") or mem.eql(u8, arg, "--help")) {
                const std_out = std.io.getStdOut().writer();
                std_out.print(usage, .{args[0]}) catch |err| {
                    return comp.diag.fatalNoSrc("{s} when trying to print usage", .{@errorName(err)});
                };
                return;
            } else if (mem.eql(u8, arg, "-v") or mem.eql(u8, arg, "--version")) {
                const std_out = std.io.getStdOut().writer();
                std_out.writeAll(@import("lib.zig").version_str ++ "\n") catch |err| {
                    return comp.diag.fatalNoSrc("{s} when trying to print version", .{@errorName(err)});
                };
                return;
            } else if (mem.eql(u8, arg, "-c")) {
                comp.only_compile = true;
            } else if (mem.startsWith(u8, arg, "-D")) {
                var macro = arg["-D".len..];
                if (macro.len == 0) {
                    i += 1;
                    if (i >= args.len) return comp.diag.fatalNoSrc("expected argument after -I", .{});
                    macro = args[i];
                }
                var value: []const u8 = "1";
                if (mem.indexOfScalar(u8, macro, '=')) |some| {
                    value = macro[some + 1 ..];
                    macro = macro[0..some];
                }
                try macro_buf.writer().print("#define {s} {s}\n", .{ macro, value });
            } else if (mem.startsWith(u8, arg, "-U")) {
                var macro = arg["-U".len..];
                if (macro.len == 0) {
                    i += 1;
                    if (i >= args.len) return comp.diag.fatalNoSrc("expected argument after -I", .{});
                    macro = args[i];
                }
                try macro_buf.writer().print("#undef {s}\n", .{macro});
            } else if (mem.eql(u8, arg, "-E")) {
                comp.only_preprocess = true;
            } else if (mem.eql(u8, arg, "-fcolor-diagnostics")) {
                comp.diag.color = true;
            } else if (mem.eql(u8, arg, "-fno-color-diagnostics")) {
                comp.diag.color = false;
            } else if (mem.eql(u8, arg, "-fdollars-in-identifiers")) {
                comp.langopts.dollars_in_identifiers = true;
            } else if (mem.eql(u8, arg, "-fno-dollars-in-identifiers")) {
                comp.langopts.dollars_in_identifiers = false;
            } else if (mem.startsWith(u8, arg, "-fmacro-backtrace-limit=")) {
                const limit_str = arg["-fmacro-backtrace-limit=".len..];
                var limit = std.fmt.parseInt(u32, limit_str, 10) catch
                    return comp.diag.fatalNoSrc("-fmacro-backtrace-limit takes a number argument", .{});

                if (limit == 0) limit = std.math.maxInt(u32);
                comp.diag.macro_backtrace_limit = limit;
            } else if (mem.eql(u8, arg, "-fshort-enums")) {
                comp.langopts.short_enums = true;
            } else if (mem.eql(u8, arg, "-fno-short-enums")) {
                comp.langopts.short_enums = false;
            } else if (mem.startsWith(u8, arg, "-I")) {
                var path = arg["-I".len..];
                if (path.len == 0) {
                    i += 1;
                    if (i >= args.len) return comp.diag.fatalNoSrc("expected argument after -I", .{});
                    path = args[i];
                }
                try comp.include_dirs.append(path);
            } else if (mem.startsWith(u8, arg, "-isystem")) {
                var path = arg["-isystem".len..];
                if (path.len == 0) {
                    i += 1;
                    if (i >= args.len) return comp.diag.fatalNoSrc("expected argument after -isystem", .{});
                    path = args[i];
                }
                try comp.system_include_dirs.append(path);
            } else if (mem.startsWith(u8, arg, "-o")) {
                var file = arg["-o".len..];
                if (file.len == 0) {
                    i += 1;
                    if (i >= args.len) return comp.diag.fatalNoSrc("expected argument after -o", .{});
                    file = args[i];
                }
                comp.output_name = file;
            } else if (mem.eql(u8, arg, "-Wall")) {
                comp.diag.setAll(.warning);
            } else if (mem.eql(u8, arg, "-Werror")) {
                comp.diag.setAll(.@"error");
            } else if (mem.startsWith(u8, arg, "-Werror=")) {
                const option = arg["-Werror=".len..];
                try comp.diag.set(option, .@"error");
            } else if (mem.startsWith(u8, arg, "-Wno-")) {
                const option = arg["-Wno-".len..];
                try comp.diag.set(option, .off);
            } else if (mem.startsWith(u8, arg, "-W")) {
                const option = arg["-W".len..];
                try comp.diag.set(option, .warning);
            } else if (mem.startsWith(u8, arg, "-std=")) {
                const standard = arg["-std=".len..];
                comp.langopts.setStandard(standard) catch
                    return comp.diag.fatalNoSrc("Invalid standard '{s}'", .{standard});
            } else if (mem.startsWith(u8, arg, "--target=")) {
                const triple = arg["--target=".len..];
                const cross = std.zig.CrossTarget.parse(.{ .arch_os_abi = triple }) catch
                    return comp.diag.fatalNoSrc("Invalid target '{s}'", .{triple});
                comp.target = cross.toTarget(); // TODO deprecated
            } else if (mem.eql(u8, arg, "--verbose-ast")) {
                comp.verbose_ast = true;
            } else {
                const std_out = std.io.getStdErr().writer();
                std_out.print(usage, .{args[0]}) catch {};
                return comp.diag.fatalNoSrc("unknown command: {s}", .{arg});
            }
        } else {
            const file = comp.addSource(arg) catch |err| return comp.diag.fatalNoSrc("{s}", .{@errorName(err)});
            try source_files.append(file);
        }
    }

    if (source_files.items.len == 0) {
        return comp.diag.fatalNoSrc("no input files", .{});
    } else if (source_files.items.len != 1 and comp.output_name != null) {
        return comp.diag.fatalNoSrc("cannot specify -o when generating multiple output files", .{});
    }

    const builtin = try comp.generateBuiltinMacros();
    const user_macros = blk: {
        const duped_path = try comp.gpa.dupe(u8, "<command line>");
        errdefer comp.gpa.free(duped_path);

        const contents = macro_buf.toOwnedSlice();
        errdefer comp.gpa.free(contents);

        const source = Source{
            .id = @intToEnum(Source.Id, comp.sources.count() + 2),
            .path = duped_path,
            .buf = contents,
        };
        try comp.sources.put(duped_path, source);
        break :blk source;
    };

    for (source_files.items) |source| {
        processSource(comp, source, builtin, user_macros) catch |e| switch (e) {
            error.OutOfMemory => return error.OutOfMemory,
            error.FatalError => {
                comp.renderErrors();
            },
        };
    }
}

fn processSource(comp: *Compilation, source: Source, builtin: Source, user_macros: Source) !void {
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
            std.fs.cwd().createFile(some, .{}) catch |err|
                return comp.diag.fatalNoSrc("{s} when trying to create output file", .{@errorName(err)})
        else
            std.io.getStdOut();
        defer if (comp.output_name != null) file.close();

        return pp.prettyPrintTokens(file.writer()) catch |err|
            comp.diag.fatalNoSrc("{s} when trying to print tokens", .{@errorName(err)});
    }

    var tree = try Parser.parse(&pp);
    defer tree.deinit();

    if (comp.verbose_ast) {
        var buf_writer = std.io.bufferedWriter(std.io.getStdOut().writer());
        tree.dump(buf_writer.writer()) catch {};
        buf_writer.flush() catch {};
    }

    const prev_errors = comp.diag.errors;
    comp.renderErrors();

    if (comp.diag.errors != prev_errors) return; // do not compile if there were errors

    if (comp.target.getObjectFormat() != .elf or comp.target.cpu.arch != .x86_64) {
        return comp.diag.fatalNoSrc(
            "unsupported target {s}-{s}-{s}, currently only x86-64 elf is supported",
            .{ @tagName(comp.target.cpu.arch), @tagName(comp.target.os.tag), @tagName(comp.target.abi) },
        );
    }

    const obj = try Codegen.generateTree(comp, tree);
    defer obj.deinit();

    const basename = std.fs.path.basename(source.path);
    const out_file_name = comp.output_name orelse try std.fmt.allocPrint(comp.gpa, "{s}{s}", .{
        basename[0 .. basename.len - std.fs.path.extension(source.path).len],
        comp.target.getObjectFormat().fileExt(comp.target.cpu.arch),
    });
    defer if (comp.output_name == null) comp.gpa.free(out_file_name);

    const out_file = std.fs.cwd().createFile(out_file_name, .{}) catch |err|
        return comp.diag.fatalNoSrc("could not create output file '{s}': {s}", .{ out_file_name, @errorName(err) });
    defer out_file.close();

    obj.finish(out_file) catch |err|
        return comp.diag.fatalNoSrc("could output to object file '{s}': {s}", .{ out_file_name, @errorName(err) });

    if (comp.only_compile) return;

    // TODO invoke linker
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
