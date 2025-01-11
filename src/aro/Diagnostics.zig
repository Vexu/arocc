const std = @import("std");
const mem = std.mem;
const Allocator = mem.Allocator;

const Attribute = @import("Attribute.zig");
const Builtins = @import("Builtins.zig");
const Builtin = Builtins.Builtin;
const Header = @import("Builtins/Properties.zig").Header;
const Compilation = @import("Compilation.zig");
const LangOpts = @import("LangOpts.zig");
const Source = @import("Source.zig");
const Tree = @import("Tree.zig");

const is_windows = @import("builtin").os.tag == .windows;

pub const Message = struct {
    tag: Tag,
    kind: Kind = undefined,
    loc: Source.Location = .{},
    extra: Extra = .{ .none = {} },

    pub const Extra = union {
        str: []const u8,
        tok_id: struct {
            expected: Tree.Token.Id,
            actual: Tree.Token.Id,
        },
        tok_id_expected: Tree.Token.Id,
        arguments: struct {
            expected: u32,
            actual: u32,
        },
        codepoints: struct {
            actual: u21,
            resembles: u21,
        },
        attr_arg_count: struct {
            attribute: Attribute.Tag,
            expected: u32,
        },
        attr_arg_type: struct {
            expected: Attribute.ArgumentType,
            actual: Attribute.ArgumentType,
        },
        attr_enum: struct {
            tag: Attribute.Tag,
        },
        ignored_record_attr: struct {
            tag: Attribute.Tag,
            tag_kind: enum { @"struct", @"union", @"enum" },
        },
        attribute_todo: struct {
            tag: Attribute.Tag,
            kind: enum { variables, fields, types, functions },
        },
        builtin_with_header: struct {
            builtin: Builtin.Tag,
            header: Header,
        },
        invalid_escape: struct {
            offset: u32,
            char: u8,
        },
        actual_codepoint: u21,
        ascii: u7,
        unsigned: u64,
        offset: u64,
        pow_2_as_string: u8,
        signed: i64,
        normalized: []const u8,
        none: void,
    };
};

const Properties = struct {
    msg: []const u8,
    kind: Kind,
    extra: std.meta.FieldEnum(Message.Extra) = .none,
    opt: ?Option = null,
    extension: bool = false,

    // TODO look into removing these
    suppress_version: ?LangOpts.Standard = null,
    suppress_unless_version: ?LangOpts.Standard = null,

    pub const max_bits = Compilation.bit_int_max_bits;
};

pub const Tag = @import("Diagnostics/messages.def").with(Properties).Tag;

pub const Kind = enum {
    off,
    note,
    warning,
    @"error",
    @"fatal error",
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
    extensions: Kind = .off,
    /// How to treat individual options, set by -W<name>
    options: std.EnumMap(Option, Kind) = .{},
};

const Diagnostics = @This();

list: std.ArrayListUnmanaged(Message) = .{},
arena: std.heap.ArenaAllocator,
state: State = .{},
errors: u32 = 0,
macro_backtrace_limit: u32 = 6,

/// Used by the __has_warning builtin macro.
pub fn warningExists(name: []const u8) bool {
    if (std.mem.eql(u8, name, "pedantic")) return true;
    inline for (comptime std.meta.declarations(Option)) |group| {
        if (std.mem.eql(u8, name, group.name)) return true;
    }
    return std.meta.stringToEnum(Option, name) != null;
}

pub fn set(d: *Diagnostics, name: []const u8, to: Kind) !void {
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
            d.setGroup(&@field(Option, group.name), to);
            return;
        }
    }

    try d.addExtra(.{}, .{
        .tag = .unknown_warning,
        .extra = .{ .str = name },
    }, &.{}, true);
}

fn setGroup(d: *Diagnostics, group: []const Option, to: Kind) void {
    for (group) |option| {
        d.state.options.put(option, to);
    }
}

pub fn init(gpa: Allocator) Diagnostics {
    return .{
        .arena = std.heap.ArenaAllocator.init(gpa),
    };
}

pub fn deinit(d: *Diagnostics) void {
    d.list.deinit(d.arena.child_allocator);
    d.arena.deinit();
}

pub fn add(comp: *Compilation, msg: Message, expansion_locs: []const Source.Location) Compilation.Error!void {
    return comp.diagnostics.addExtra(comp.langopts, msg, expansion_locs, true);
}

pub fn addExtra(
    d: *Diagnostics,
    langopts: LangOpts,
    msg: Message,
    expansion_locs: []const Source.Location,
    note_msg_loc: bool,
) Compilation.Error!void {
    const kind = d.tagKind(msg.tag, langopts);
    if (kind == .off) return;
    var copy = msg;
    copy.kind = kind;

    if (expansion_locs.len != 0) copy.loc = expansion_locs[expansion_locs.len - 1];
    try d.list.append(d.arena.child_allocator, copy);
    if (kind == .@"error" or kind == .@"fatal error") d.errors += 1;

    if (expansion_locs.len != 0) {
        // Add macro backtrace notes in reverse order omitting from the middle if needed.
        var i = expansion_locs.len - 1;
        const half = d.macro_backtrace_limit / 2;
        const limit = if (i < d.macro_backtrace_limit) 0 else i - half;
        try d.list.ensureUnusedCapacity(
            d.arena.child_allocator,
            if (limit == 0) expansion_locs.len else d.macro_backtrace_limit + 1,
        );
        while (i > limit) {
            i -= 1;
            d.list.appendAssumeCapacity(.{
                .tag = .expanded_from_here,
                .kind = .note,
                .loc = expansion_locs[i],
            });
        }
        if (limit != 0) {
            d.list.appendAssumeCapacity(.{
                .tag = .skipping_macro_backtrace,
                .kind = .note,
                .extra = .{ .unsigned = expansion_locs.len - d.macro_backtrace_limit },
            });
            i = half -| 1;
            while (i > 0) {
                i -= 1;
                d.list.appendAssumeCapacity(.{
                    .tag = .expanded_from_here,
                    .kind = .note,
                    .loc = expansion_locs[i],
                });
            }
        }

        if (note_msg_loc) d.list.appendAssumeCapacity(.{
            .tag = .expanded_from_here,
            .kind = .note,
            .loc = msg.loc,
        });
    }
    if (kind == .@"fatal error") return error.FatalError;
}

pub fn render(comp: *Compilation, config: std.io.tty.Config) void {
    if (comp.diagnostics.list.items.len == 0) return;
    var m = defaultMsgWriter(config);
    defer m.deinit();
    renderMessages(comp, &m);
}
pub fn defaultMsgWriter(config: std.io.tty.Config) MsgWriter {
    return MsgWriter.init(config);
}

pub fn renderMessages(comp: *Compilation, m: anytype) void {
    var errors: u32 = 0;
    var warnings: u32 = 0;
    for (comp.diagnostics.list.items) |msg| {
        switch (msg.kind) {
            .@"fatal error", .@"error" => errors += 1,
            .warning => warnings += 1,
            .note => {},
            .off => continue, // happens if an error is added before it is disabled
        }
        renderMessage(comp, m, msg);
    }
    const w_s: []const u8 = if (warnings == 1) "" else "s";
    const e_s: []const u8 = if (errors == 1) "" else "s";
    if (errors != 0 and warnings != 0) {
        m.print("{d} warning{s} and {d} error{s} generated.\n", .{ warnings, w_s, errors, e_s });
    } else if (warnings != 0) {
        m.print("{d} warning{s} generated.\n", .{ warnings, w_s });
    } else if (errors != 0) {
        m.print("{d} error{s} generated.\n", .{ errors, e_s });
    }

    comp.diagnostics.list.items.len = 0;
}

pub fn renderMessage(comp: *Compilation, m: anytype, msg: Message) void {
    var line: ?[]const u8 = null;
    var end_with_splice = false;
    const width = if (msg.loc.id != .unused) blk: {
        var loc = msg.loc;
        switch (msg.tag) {
            .escape_sequence_overflow,
            .invalid_universal_character,
            => loc.byte_offset += @truncate(msg.extra.offset),
            .non_standard_escape_char,
            .unknown_escape_sequence,
            => loc.byte_offset += msg.extra.invalid_escape.offset,
            else => {},
        }
        const source = comp.getSource(loc.id);
        var line_col = source.lineCol(loc);
        line = line_col.line;
        end_with_splice = line_col.end_with_splice;
        if (msg.tag == .backslash_newline_escape) {
            line = line_col.line[0 .. line_col.col - 1];
            line_col.col += 1;
            line_col.width += 1;
        }
        m.location(source.path, line_col.line_no, line_col.col);
        break :blk line_col.width;
    } else 0;

    m.start(msg.kind);
    const prop = msg.tag.property();
    switch (prop.extra) {
        .str => printRt(m, prop.msg, .{"{s}"}, .{msg.extra.str}),
        .tok_id => printRt(m, prop.msg, .{ "{s}", "{s}" }, .{
            msg.extra.tok_id.expected.symbol(),
            msg.extra.tok_id.actual.symbol(),
        }),
        .tok_id_expected => printRt(m, prop.msg, .{"{s}"}, .{msg.extra.tok_id_expected.symbol()}),
        .arguments => printRt(m, prop.msg, .{ "{d}", "{d}" }, .{
            msg.extra.arguments.expected,
            msg.extra.arguments.actual,
        }),
        .codepoints => printRt(m, prop.msg, .{ "{X:0>4}", "{u}" }, .{
            msg.extra.codepoints.actual,
            msg.extra.codepoints.resembles,
        }),
        .attr_arg_count => printRt(m, prop.msg, .{ "{s}", "{d}" }, .{
            @tagName(msg.extra.attr_arg_count.attribute),
            msg.extra.attr_arg_count.expected,
        }),
        .attr_arg_type => printRt(m, prop.msg, .{ "{s}", "{s}" }, .{
            msg.extra.attr_arg_type.expected.toString(),
            msg.extra.attr_arg_type.actual.toString(),
        }),
        .actual_codepoint => printRt(m, prop.msg, .{"{X:0>4}"}, .{msg.extra.actual_codepoint}),
        .ascii => printRt(m, prop.msg, .{"{c}"}, .{msg.extra.ascii}),
        .unsigned => printRt(m, prop.msg, .{"{d}"}, .{msg.extra.unsigned}),
        .pow_2_as_string => printRt(m, prop.msg, .{"{s}"}, .{switch (msg.extra.pow_2_as_string) {
            63 => "9223372036854775808",
            64 => "18446744073709551616",
            127 => "170141183460469231731687303715884105728",
            128 => "340282366920938463463374607431768211456",
            else => unreachable,
        }}),
        .signed => printRt(m, prop.msg, .{"{d}"}, .{msg.extra.signed}),
        .attr_enum => printRt(m, prop.msg, .{ "{s}", "{s}" }, .{
            @tagName(msg.extra.attr_enum.tag),
            Attribute.Formatting.choices(msg.extra.attr_enum.tag),
        }),
        .ignored_record_attr => printRt(m, prop.msg, .{ "{s}", "{s}" }, .{
            @tagName(msg.extra.ignored_record_attr.tag),
            @tagName(msg.extra.ignored_record_attr.tag_kind),
        }),
        .attribute_todo => printRt(m, prop.msg, .{ "{s}", "{s}" }, .{
            @tagName(msg.extra.attribute_todo.tag),
            @tagName(msg.extra.attribute_todo.kind),
        }),
        .builtin_with_header => printRt(m, prop.msg, .{ "{s}", "{s}" }, .{
            @tagName(msg.extra.builtin_with_header.header),
            Builtin.nameFromTag(msg.extra.builtin_with_header.builtin).span(),
        }),
        .invalid_escape => {
            if (std.ascii.isPrint(msg.extra.invalid_escape.char)) {
                const str: [1]u8 = .{msg.extra.invalid_escape.char};
                printRt(m, prop.msg, .{"{s}"}, .{&str});
            } else {
                var buf: [3]u8 = undefined;
                const str = std.fmt.bufPrint(&buf, "x{x}", .{std.fmt.fmtSliceHexLower(&.{msg.extra.invalid_escape.char})}) catch unreachable;
                printRt(m, prop.msg, .{"{s}"}, .{str});
            }
        },
        .normalized => {
            const f = struct {
                pub fn f(
                    bytes: []const u8,
                    comptime _: []const u8,
                    _: std.fmt.FormatOptions,
                    writer: anytype,
                ) !void {
                    var it: std.unicode.Utf8Iterator = .{
                        .bytes = bytes,
                        .i = 0,
                    };
                    while (it.nextCodepoint()) |codepoint| {
                        if (codepoint < 0x7F) {
                            try writer.writeByte(@intCast(codepoint));
                        } else if (codepoint < 0xFFFF) {
                            try writer.writeAll("\\u");
                            try std.fmt.formatInt(codepoint, 16, .upper, .{
                                .fill = '0',
                                .width = 4,
                            }, writer);
                        } else {
                            try writer.writeAll("\\U");
                            try std.fmt.formatInt(codepoint, 16, .upper, .{
                                .fill = '0',
                                .width = 8,
                            }, writer);
                        }
                    }
                }
            }.f;
            printRt(m, prop.msg, .{"{s}"}, .{
                std.fmt.Formatter(f){ .data = msg.extra.normalized },
            });
        },
        .none, .offset => m.write(prop.msg),
    }

    if (prop.opt) |some| {
        if (msg.kind == .@"error" and prop.kind != .@"error") {
            m.print(" [-Werror,-W{s}]", .{@tagName(some)});
        } else if (msg.kind != .note) {
            m.print(" [-W{s}]", .{@tagName(some)});
        }
    } else if (prop.extension) {
        if (msg.kind == .@"error") {
            m.write(" [-Werror,-Wpedantic]");
        } else {
            m.write(" [-Wpedantic]");
        }
    }

    m.end(line, width, end_with_splice);
}

fn printRt(m: anytype, str: []const u8, comptime fmts: anytype, args: anytype) void {
    var i: usize = 0;
    inline for (fmts, args) |fmt, arg| {
        const new = std.mem.indexOfPos(u8, str, i, fmt).?;
        m.write(str[i..new]);
        i = new + fmt.len;
        m.print(fmt, .{arg});
    }
    m.write(str[i..]);
}

fn tagKind(d: *Diagnostics, tag: Tag, langopts: LangOpts) Kind {
    const prop = tag.property();
    var kind = prop.kind;

    if (prop.suppress_version) |some| if (langopts.standard.atLeast(some)) return .off;
    if (prop.suppress_unless_version) |some| if (!langopts.standard.atLeast(some)) return .off;

    // -w disregards explicit kind set with -W<name>
    if (d.state.ignore_warnings and prop.kind == .warning) return .off;

    // Get explicit kind set by -W<name>=
    var set_explicit = false;
    if (prop.opt) |option| {
        if (d.state.options.get(option)) |explicit| {
            kind = explicit;
            set_explicit = true;
        }
    }

    // Use extension diagnostic behavior if not set explicitly.
    if (prop.extension and !set_explicit) {
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

const MsgWriter = struct {
    w: std.io.BufferedWriter(4096, std.fs.File.Writer),
    config: std.io.tty.Config,

    fn init(config: std.io.tty.Config) MsgWriter {
        std.debug.lockStdErr();
        return .{
            .w = std.io.bufferedWriter(std.io.getStdErr().writer()),
            .config = config,
        };
    }

    pub fn deinit(m: *MsgWriter) void {
        m.w.flush() catch {};
        std.debug.unlockStdErr();
    }

    pub fn print(m: *MsgWriter, comptime fmt: []const u8, args: anytype) void {
        m.w.writer().print(fmt, args) catch {};
    }

    fn write(m: *MsgWriter, msg: []const u8) void {
        m.w.writer().writeAll(msg) catch {};
    }

    fn setColor(m: *MsgWriter, color: std.io.tty.Color) void {
        m.config.setColor(m.w.writer(), color) catch {};
    }

    fn location(m: *MsgWriter, path: []const u8, line: u32, col: u32) void {
        m.setColor(.bold);
        m.print("{s}:{d}:{d}: ", .{ path, line, col });
    }

    fn start(m: *MsgWriter, kind: Kind) void {
        switch (kind) {
            .@"fatal error", .@"error" => m.setColor(.bright_red),
            .note => m.setColor(.bright_cyan),
            .warning => m.setColor(.bright_magenta),
            .off => unreachable,
        }
        m.write(switch (kind) {
            .@"fatal error" => "fatal error: ",
            .@"error" => "error: ",
            .note => "note: ",
            .warning => "warning: ",
            .off => unreachable,
        });
        m.setColor(.white);
    }

    fn end(m: *MsgWriter, maybe_line: ?[]const u8, col: u32, end_with_splice: bool) void {
        const line = maybe_line orelse {
            m.write("\n");
            m.setColor(.reset);
            return;
        };
        const trailer = if (end_with_splice) "\\ " else "";
        m.setColor(.reset);
        m.print("\n{s}{s}\n{s: >[3]}", .{ line, trailer, "", col });
        m.setColor(.bold);
        m.setColor(.bright_green);
        m.write("^\n");
        m.setColor(.reset);
    }
};
