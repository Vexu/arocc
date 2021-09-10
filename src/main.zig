const std = @import("std");
const mem = std.mem;
const Allocator = mem.Allocator;
const process = std.process;
const Compilation = @import("Compilation.zig");
const Source = @import("Source.zig");
const Preprocessor = @import("Preprocessor.zig");
const Parser = @import("Parser.zig");

var general_purpose_allocator = std.heap.GeneralPurposeAllocator(.{}){};

pub fn main() u8 {
    const gpa = if (std.builtin.link_libc)
        std.heap.raw_c_allocator
    else
        &general_purpose_allocator.allocator;
    defer if (!std.builtin.link_libc) {
        _ = general_purpose_allocator.deinit();
    };

    var arena_instance = std.heap.ArenaAllocator.init(gpa);
    defer arena_instance.deinit();
    const arena = &arena_instance.allocator;

    const args = process.argsAlloc(arena) catch {
        std.debug.print("out of memory\n", .{});
        return 1;
    };

    var comp = Compilation.init(gpa);
    defer comp.deinit();

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
    \\Feature options:
    \\  -E                      Only run the preprocessor
    \\  -D <macro>=<value>      Define <macro> to <value> (defaults to 1)
    \\  -U <macro>              Undefine <macro>
    \\  -fcolor-diagnostics     Enable colors in diagnostics
    \\  -fno-color-diagnostics  Disable colors in diagnostics
    \\  -I <dir>                Add directory to include search path
    \\  -isystem                Add directory to SYSTEM include search path
    \\  -o <file>               Write output to <file>
    \\  -std=<standard>         Specify language standard
    \\  -Wall                   Enable all warnings
    \\  -Werror                 Treat all warnings as errors
    \\  -Werror=<warning>       Treat warning as error
    \\  -W<warning>             Enable the specified warning
    \\  -Wno-<warning>          Disable the specified warning
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
                comp.langopts.setStandard(standard) catch return comp.diag.fatalNoSrc("Invalid standard '{s}'", .{standard});
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
            error.FatalError => {},
        };
    }
}

fn processSource(comp: *Compilation, source: Source, builtin: Source, user_macros: Source) !void {
    var pp = Preprocessor.init(comp);
    defer pp.deinit();

    try pp.preprocess(builtin);
    try pp.preprocess(user_macros);
    try pp.preprocess(source);
    try pp.tokens.append(pp.comp.gpa, .{
        .id = .eof,
        .loc = .{ .id = source.id, .byte_offset = @intCast(u32, source.buf.len) },
    });

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

    comp.renderErrors();

    tree.dump(std.io.getStdOut().writer()) catch {};
}

test {
    _ = @import("Compilation.zig");
    _ = @import("Diagnostics.zig");
    _ = @import("InitList.zig");
    _ = @import("Parser.zig");
    _ = @import("Preprocessor.zig");
    _ = @import("Source.zig");
    _ = @import("Tokenizer.zig");
    _ = @import("Tree.zig");
    _ = @import("Type.zig");
}
