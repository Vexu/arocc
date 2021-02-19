const std = @import("std");
const mem = std.mem;
const Allocator = mem.Allocator;
const process = std.process;
const Compilation = @import("Compilation");
const build_options = @import("build_options");

var general_purpose_allocator = std.heap.GeneralPurposeAllocator(.{}){};

pub fn main() void {
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
        fail("out of memory", .{});
        process.exit(1);
    };
    handleArgs(gpa, args) catch |err| {
        fail("{s}", .{@errorName(err)});
        process.exit(1);
    };
}

fn fail(comptime msg: []const u8, args: anytype) void {
    std.debug.print("error: " ++ msg ++ "\n", args);
}

const usage =
    \\Usage {s}: [options] file..
    \\
    \\Options:
    \\  -h, --help      Print this message.
    \\  -v, --version   Print sfcc version.
    \\
    \\
;

fn handleArgs(gpa: *Allocator, args: [][]const u8) !void {
    var source_files = std.ArrayList([]const u8).init(gpa);
    defer source_files.deinit();

    for (args[1..]) |arg| {
        if (mem.startsWith(u8, arg, "-")) {
            if (mem.eql(u8, arg, "-h") or mem.eql(u8, arg, "--help")) {
                const std_out = std.io.getStdOut().writer();
                return std_out.print(usage, .{args[0]});
            } else if (mem.eql(u8, arg, "-v") or mem.eql(u8, arg, "--version")) {
                const std_out = std.io.getStdOut().writer();
                return std_out.writeAll(build_options.version_str ++ "\n");
            } else {
                const std_out = std.io.getStdErr().writer();
                try std_out.print(usage, .{args[0]});
                return fail("unknown command: {s}", .{arg});
            }
        } else {
            try source_files.append(arg);
        }
    }

    if (source_files.items.len == 0) {
        return fail("no input files", .{});
    }
}

test {
    _ = @import("Compilation.zig");
    _ = @import("Preprocessor.zig");
    _ = @import("Source.zig");
    _ = @import("Tokenizer.zig");
}
