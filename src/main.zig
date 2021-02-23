const std = @import("std");
const mem = std.mem;
const Allocator = mem.Allocator;
const process = std.process;
const Compilation = @import("Compilation.zig");
const Source = @import("Source.zig");
const Preprocessor = @import("Preprocessor.zig");
const Parser = @import("Parser.zig");
const build_options = @import("build_options");

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
        process.exit(1);
    };

    handleArgs(gpa, args) catch |err| switch (err) {
        error.OutOfMemory => {
            std.debug.print("out of memory\n", .{});
            return 1;
        },
        error.FatalError => return 1,
    };
    return 0;
}

const usage =
    \\Usage {s}: [options] file..
    \\
    \\General options:
    \\  -h, --help      Print this message.
    \\  -v, --version   Print sfcc version.
    \\
    \\Feature options:
    \\  -E                      Only run the preprocessor
    \\  -fcolor-diagnostics     Enable colors in diagnostics
    \\  -fno-color-diagnostics  Disable colors in diagnostics
    \\  -Wall                   Enable all warnings
    \\  -Werror                 Treat all warnings as errors
    \\  -Werror=<warning>       Treat warning as error
    \\  -W<warning>             Enable the specified warning
    \\  -Wno-<warning>          Disable the specified warning
    \\
    \\
;

fn handleArgs(gpa: *Allocator, args: [][]const u8) !void {
    var comp = Compilation.init(gpa);
    defer comp.deinit();

    var source_files = std.ArrayList(Source).init(gpa);
    defer source_files.deinit();

    for (args[1..]) |arg| {
        if (mem.startsWith(u8, arg, "-")) {
            if (mem.eql(u8, arg, "-h") or mem.eql(u8, arg, "--help")) {
                const std_out = std.io.getStdOut().writer();
                std_out.print(usage, .{args[0]}) catch |err| {
                    return comp.diag.fatalNoSrc("{s} when trying to print usage", .{@errorName(err)});
                };
                return;
            } else if (mem.eql(u8, arg, "-v") or mem.eql(u8, arg, "--version")) {
                const std_out = std.io.getStdOut().writer();
                std_out.writeAll(build_options.version_str ++ "\n") catch |err| {
                    return comp.diag.fatalNoSrc("{s} when trying to print version", .{@errorName(err)});
                };
                return;
            } else if (mem.eql(u8, arg, "-fcolor-diagnostics")) {
                comp.diag.color = true;
            } else if (mem.eql(u8, arg, "-fno-color-diagnostics")) {
                comp.diag.color = false;
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
    }

    for (source_files.items) |source| {
        var pp = Preprocessor.init(&comp);
        defer pp.deinit();

        try pp.preprocess(source);
        

        var parser = Parser{
            .pp = &pp,
            .tokens = pp.tokens.items,
        };
        parser.parse() catch |e| switch (e) {
            error.FatalError => return error.FatalError,
            error.OutOfMemory => return error.OutOfMemory,
            error.ParsingFailed => {},
        };

        comp.renderErrors();
        comp.diag.list.items.len = 0;

        for (pp.tokens.items) |tok, i| {
            std.debug.print("id: {s} |{s}|\n", .{ @tagName(tok.id), pp.tokSlice(tok) });
        }
    }
}

test {
    _ = @import("Compilation.zig");
    _ = @import("Preprocessor.zig");
    _ = @import("Source.zig");
    _ = @import("Tokenizer.zig");
    _ = @import("Tree.zig");
    _ = @import("Type.zig");
}
