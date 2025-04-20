const std = @import("std");
const mem = std.mem;
const Allocator = mem.Allocator;

const Compilation = @import("Compilation.zig");
const LangOpts = @import("LangOpts.zig");
const Source = @import("Source.zig");

pub const Message = struct {
    kind: Kind,
    text: []const u8,

    opt: ?Option = null,
    extension: bool = false,
    location: ?Source.ExpandedLocation,

    pub const Kind = enum {
        off,
        note,
        warning,
        @"error",
        @"fatal error",
    };
};

pub const Option = enum {
    @"unsupported-pragma",
    @"c99-extensions",
    @"implicit-int",
    @"duplicate-decl-specifier",
    @"missing-declaration",
    @"extern-initializer",
    @"implicit-function-declaration",
    @"unused-value",
    @"unreachable-code",
    @"unknown-warning-option",
    @"gnu-empty-struct",
    @"gnu-alignof-expression",
    @"macro-redefined",
    @"generic-qual-type",
    multichar,
    @"pointer-integer-compare",
    @"compare-distinct-pointer-types",
    @"literal-conversion",
    @"cast-qualifiers",
    @"array-bounds",
    @"int-conversion",
    @"pointer-type-mismatch",
    @"c23-extensions",
    @"incompatible-pointer-types",
    @"excess-initializers",
    @"division-by-zero",
    @"initializer-overrides",
    @"incompatible-pointer-types-discards-qualifiers",
    @"unknown-attributes",
    @"ignored-attributes",
    @"builtin-macro-redefined",
    @"gnu-label-as-value",
    @"malformed-warning-check",
    @"#pragma-messages",
    @"newline-eof",
    @"empty-translation-unit",
    @"implicitly-unsigned-literal",
    @"c99-compat",
    @"unicode-zero-width",
    @"unicode-homoglyph",
    unicode,
    @"return-type",
    @"dollar-in-identifier-extension",
    @"unknown-pragmas",
    @"predefined-identifier-outside-function",
    @"many-braces-around-scalar-init",
    uninitialized,
    @"gnu-statement-expression",
    @"gnu-imaginary-constant",
    @"gnu-complex-integer",
    @"ignored-qualifiers",
    @"integer-overflow",
    @"extra-semi",
    @"gnu-binary-literal",
    @"variadic-macros",
    varargs,
    @"#warnings",
    @"deprecated-declarations",
    @"backslash-newline-escape",
    @"pointer-to-int-cast",
    @"gnu-case-range",
    @"c++-compat",
    vla,
    @"float-overflow-conversion",
    @"float-zero-conversion",
    @"float-conversion",
    @"gnu-folding-constant",
    undef,
    @"ignored-pragmas",
    @"gnu-include-next",
    @"include-next-outside-header",
    @"include-next-absolute-path",
    @"enum-too-large",
    @"fixed-enum-extension",
    @"designated-init",
    @"attribute-warning",
    @"invalid-noreturn",
    @"zero-length-array",
    @"old-style-flexible-struct",
    @"gnu-zero-variadic-macro-arguments",
    @"main-return-type",
    @"expansion-to-defined",
    @"bit-int-extension",
    @"keyword-macro",
    @"pointer-arith",
    @"sizeof-array-argument",
    @"pre-c23-compat",
    @"pointer-bool-conversion",
    @"string-conversion",
    @"gnu-auto-type",
    @"gnu-pointer-arith",
    @"gnu-union-cast",
    @"pointer-sign",
    @"fuse-ld-path",
    @"language-extension-token",
    @"complex-component-init",
    @"microsoft-include",
    @"microsoft-end-of-file",
    @"invalid-source-encoding",
    @"four-char-constants",
    @"unknown-escape-sequence",
    @"invalid-pp-token",
    @"deprecated-non-prototype",
    @"duplicate-embed-param",
    @"unsupported-embed-param",
    @"unused-result",
    normalized,
    @"shift-count-negative",
    @"shift-count-overflow",
    @"constant-conversion",
    @"sign-conversion",
    @"address-of-packed-member",
    nonnull,
    @"atomic-access",
    @"gnu-designator",
    @"empty-body",
    @"nullability-extension",
    nullability,
    @"microsoft-flexible-array",

    /// GNU extensions
    pub const gnu = [_]Option{
        .@"gnu-empty-struct",
        .@"gnu-alignof-expression",
        .@"gnu-label-as-value",
        .@"gnu-statement-expression",
        .@"gnu-imaginary-constant",
        .@"gnu-complex-integer",
        .@"gnu-binary-literal",
        .@"gnu-case-range",
        .@"gnu-folding-constant",
        .@"gnu-include-next",
        .@"gnu-zero-variadic-macro-arguments",
        .@"gnu-auto-type",
        .@"gnu-pointer-arith",
        .@"gnu-union-cast",
        .@"gnu-designator",
        .@"zero-length-array",
    };

    /// Clang extensions
    pub const clang = [_]Option{
        .@"fixed-enum-extension",
        .@"bit-int-extension",
        .@"nullability-extension",
    };

    /// Microsoft extensions
    pub const microsoft = [_]Option{
        .@"microsoft-end-of-file",
        .@"microsoft-include",
        .@"microsoft-flexible-array",
    };

    pub const extra = [_]Option{
        .@"initializer-overrides",
        .@"ignored-qualifiers",
        .@"initializer-overrides",
        .@"expansion-to-defined",
        .@"fuse-ld-path",
    };

    pub const implicit = [_]Option{
        .@"implicit-int",
        .@"implicit-function-declaration",
    };

    pub const unused = [_]Option{
        .@"unused-value",
        .@"unused-result",
    };

    pub const most = implicit ++ unused ++ [_]Option{
        .@"initializer-overrides",
        .@"ignored-qualifiers",
        .@"initializer-overrides",
        .multichar,
        .@"return-type",
        .@"sizeof-array-argument",
        .uninitialized,
        .@"unknown-pragmas",
    };

    pub const all = most ++ [_]Option{
        .nonnull,
        .@"unreachable-code",
        .@"malformed-warning-check",
    };
};

pub const State = struct {
    // Treat all errors as fatal, set by -Wfatal-errors
    fatal_errors: bool = false,
    // Treat all warnings as errors, set by -Werror
    error_warnings: bool = false,
    /// Enable all warnings, set by -Weverything
    enable_all_warnings: bool = false,
    /// Ignore all warnings, set by -w
    ignore_warnings: bool = false,
    /// How to treat extension diagnostics, set by -Wpedantic
    extensions: Message.Kind = .off,
    /// How to treat individual options, set by -W<name>
    options: std.EnumMap(Option, Message.Kind) = .{},
};

const Diagnostics = @This();

output: union(enum) {
    to_file: struct {
        file: std.fs.File,
        config: std.io.tty.Config,
    },
    to_list: struct {
        messages: std.ArrayListUnmanaged(Message),
        arena: std.heap.ArenaAllocator,
    },
},
state: State = .{},
/// Amount of error or fatal error messages that have been sent to `output`.
errors: u32 = 0,
/// Amount of warnings that have been sent to `output`.
warnings: u32 = 0,
// Total amount of diagnostics messages sent to `output`.
total: u32 = 0,
macro_backtrace_limit: u32 = 6,

pub fn deinit(d: *Diagnostics) void {
    switch (d.output) {
        .to_file => {},
        .to_list => |*list| {
            list.messages.deinit(list.arena.child_allocator);
            list.arena.deinit();
        },
    }
}

/// Used by the __has_warning builtin macro.
pub fn warningExists(name: []const u8) bool {
    if (std.mem.eql(u8, name, "pedantic")) return true;
    inline for (comptime std.meta.declarations(Option)) |group| {
        if (std.mem.eql(u8, name, group.name)) return true;
    }
    return std.meta.stringToEnum(Option, name) != null;
}

pub fn set(d: *Diagnostics, name: []const u8, to: Message.Kind) !void {
    if (std.mem.eql(u8, name, "pedantic")) {
        d.state.extensions = to;
        return;
    }
    if (std.meta.stringToEnum(Option, name)) |option| {
        d.state.options.put(option, to);
        return;
    }

    inline for (comptime std.meta.declarations(Option)) |group| {
        if (std.mem.eql(u8, name, group.name)) {
            for (@field(Option, group.name)) |option| {
                d.state.options.put(option, to);
            }
            return;
        }
    }

    var buf: [256]u8 = undefined;
    const slice = std.fmt.bufPrint(&buf, "unknown warning '{s}'", .{name}) catch &buf;

    try d.add(.{
        .text = slice,
        .kind = .warning,
        .opt = .@"unknown-warning-option",
        .location = null,
    });
}

pub fn effectiveKind(d: *Diagnostics, message: anytype) Message.Kind {
    var kind = message.kind;

    // -w disregards explicit kind set with -W<name>
    if (d.state.ignore_warnings and kind == .warning) return .off;

    // Get explicit kind set by -W<name>=
    var set_explicit = false;
    if (message.opt) |option| {
        if (d.state.options.get(option)) |explicit| {
            kind = explicit;
            set_explicit = true;
        }
    }

    // Use extension diagnostic behavior if not set explicitly.
    if (message.extension and !set_explicit) {
        kind = @enumFromInt(@max(@intFromEnum(kind), @intFromEnum(d.state.extensions)));
    }

    // Make diagnostic a warning if -Weverything is set.
    if (kind == .off and d.state.enable_all_warnings) kind = .warning;

    // Upgrade warnigns to errors if -Werror is set
    if (kind == .warning and d.state.error_warnings) kind = .@"error";

    // Upgrade errors to fatal errors if -Wfatal-errors is set
    if (kind == .@"error" and d.state.fatal_errors) kind = .@"fatal error";
    return kind;
}

pub fn add(d: *Diagnostics, msg: Message) Compilation.Error!void {
    var copy = msg;
    copy.kind = d.effectiveKind(msg);
    if (copy.kind == .off) return;
    try d.addMessage(copy);
}

pub fn addWithLocation(
    d: *Diagnostics,
    comp: *const Compilation,
    msg: Message,
    expansion_locs: []const Source.Location,
    note_msg_loc: bool,
) Compilation.Error!void {
    var copy = msg;
    copy.kind = d.effectiveKind(msg);
    if (copy.kind == .off) return;
    if (copy.kind == .@"error" or copy.kind == .@"fatal error") d.errors += 1;
    if (expansion_locs.len != 0) copy.location = expansion_locs[expansion_locs.len - 1].expand(comp);
    try d.addMessage(copy);

    if (expansion_locs.len != 0) {
        // Add macro backtrace notes in reverse order omitting from the middle if needed.
        var i = expansion_locs.len - 1;
        const half = d.macro_backtrace_limit / 2;
        const limit = if (i < d.macro_backtrace_limit) 0 else i - half;
        while (i > limit) {
            i -= 1;
            try d.addMessage(.{
                .kind = .note,
                .text = "expanded from here",
                .location = expansion_locs[i].expand(comp),
            });
        }
        if (limit != 0) {
            var buf: [256]u8 = undefined;
            try d.addMessage(.{
                .kind = .note,
                .text = std.fmt.bufPrint(
                    &buf,
                    "(skipping {d} expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)",
                    .{expansion_locs.len - d.macro_backtrace_limit},
                ) catch unreachable,
                .location = null,
            });
            i = half -| 1;
            while (i > 0) {
                i -= 1;
                try d.addMessage(.{
                    .kind = .note,
                    .text = "expanded from here",
                    .location = expansion_locs[i].expand(comp),
                });
            }
        }

        if (note_msg_loc) {
            try d.add(.{
                .kind = .note,
                .text = "expanded from here",
                .location = msg.location.?,
            });
        }
    }
    if (copy.kind == .@"fatal error") return error.FatalError;
}

fn addMessage(d: *Diagnostics, msg: Message) Compilation.Error!void {
    switch (msg.kind) {
        .off => unreachable,
        .@"error", .@"fatal error" => d.errors += 1,
        .warning => d.warnings += 1,
        .note => {},
    }
    d.total += 1;

    switch (d.output) {
        .to_file => |to_file| {
            _ = to_file;

            //     var line: ?[]const u8 = null;
            //     var end_with_splice = false;
            //     const width = if (msg.loc.id != .unused) blk: {
            //         var loc = msg.loc;
            //         switch (msg.tag) {
            //             .escape_sequence_overflow,
            //             .invalid_universal_character,
            //             => loc.byte_offset += @truncate(msg.extra.offset),
            //             .non_standard_escape_char,
            //             .unknown_escape_sequence,
            //             => loc.byte_offset += msg.extra.invalid_escape.offset,
            //             else => {},
            //         }
            //         const source = comp.getSource(loc.id);
            //         var line_col = source.lineCol(loc);
            //         line = line_col.line;
            //         end_with_splice = line_col.end_with_splice;
            //         if (msg.tag == .backslash_newline_escape) {
            //             line = line_col.line[0 .. line_col.col - 1];
            //             line_col.col += 1;
            //             line_col.width += 1;
            //         }
            //         m.location(source.path, line_col.line_no, line_col.col);
            //         break :blk line_col.width;
            //     } else 0;

            //     if (prop.opt) |some| {
            //         if (msg.kind == .@"error" and prop.kind != .@"error") {
            //             m.print(" [-Werror,-W{s}]", .{@tagName(some)});
            //         } else if (msg.kind != .note) {
            //             m.print(" [-W{s}]", .{@tagName(some)});
            //         }
            //     } else if (prop.extension) {
            //         if (msg.kind == .@"error") {
            //             m.write(" [-Werror,-Wpedantic]");
            //         } else {
            //             m.write(" [-Wpedantic]");
            //         }
            //     }

            //     fn end(m: *MsgWriter, maybe_line: ?[]const u8, col: u32, end_with_splice: bool) void {
            //         const line = maybe_line orelse {
            //             m.write("\n");
            //             m.setColor(.reset);
            //             return;
            //         };
            //         const trailer = if (end_with_splice) "\\ " else "";
            //         m.setColor(.reset);
            //         m.print("\n{s}{s}\n{s: >[3]}", .{ line, trailer, "", col });
            //         m.setColor(.bold);
            //         m.setColor(.bright_green);
            //         m.write("^\n");
            //         m.setColor(.reset);
        },
        .to_list => |*to_list| {
            const arena = to_list.arena.allocator();
            try to_list.messages.append(to_list.arena.child_allocator, .{
                .kind = msg.kind,
                .text = try arena.dupe(u8, msg.text),
                .location = if (msg.location) |some| .{
                    .path = try arena.dupe(u8, some.path),
                    .line = try arena.dupe(u8, some.line),
                    .col = some.col,
                    .line_no = some.line_no,
                    .width = some.width,
                    .end_with_splice = some.end_with_splice,
                } else null,
            });
        },
    }
}

pub fn formatArgs(w: anytype, fmt: []const u8, args: anytype) !void {
    var i: usize = 0;
    inline for (std.meta.fields(@TypeOf(args))) |arg_info| {
        const arg = @field(args, arg_info.name);
        i += switch (@TypeOf(arg)) {
            []const u8 => try formatString(w, fmt[i..], arg),
            else => switch (@typeInfo(@TypeOf(arg))) {
                .int, .comptime_int => try Diagnostics.formatInt(w, fmt[i..], arg),
                .pointer => try Diagnostics.formatString(w, fmt[i..], arg),
                else => unreachable,
            },
        };
    }
    try w.writeAll(fmt[i..]);
}

pub fn formatString(w: anytype, fmt: []const u8, str: []const u8) !usize {
    const i = std.mem.indexOf(u8, fmt, "{s}").?;
    try w.writeAll(fmt[0..i]);
    try w.writeAll(str);
    return i;
}

pub fn formatInt(w: anytype, fmt: []const u8, int: anytype) !usize {
    const i = std.mem.indexOf(u8, fmt, "{d}").?;
    try w.writeAll(fmt[0..i]);
    try std.fmt.formatInt(int, 10, .lower, .{}, w);
    return i;
}
