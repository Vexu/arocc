const std = @import("std");
const Allocator = mem.Allocator;
const mem = std.mem;
const util = @import("backend").util;
const Source = @import("Source.zig");
const Compilation = @import("Compilation.zig");
const Attribute = @import("Attribute.zig");
const Builtins = @import("Builtins.zig");
const Builtin = Builtins.Builtin;
const Header = @import("Builtins/Properties.zig").Header;
const Tree = @import("Tree.zig");
const is_windows = @import("builtin").os.tag == .windows;
const LangOpts = @import("LangOpts.zig");

const Diagnostics = @This();

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
            specifier: enum { @"struct", @"union", @"enum" },
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
    opt: ?u8 = null,
    all: bool = false,
    w_extra: bool = false,
    pedantic: bool = false,
    suppress_version: ?LangOpts.Standard = null,
    suppress_unless_version: ?LangOpts.Standard = null,
    suppress_gnu: bool = false,
    suppress_gcc: bool = false,
    suppress_clang: bool = false,
    suppress_msvc: bool = false,

    pub fn makeOpt(comptime str: []const u8) u16 {
        return @offsetOf(Options, str);
    }
    pub fn getKind(prop: Properties, options: *Options) Kind {
        const opt = @as([*]Kind, @ptrCast(options))[prop.opt orelse return prop.kind];
        if (opt == .default) return prop.kind;
        return opt;
    }
    pub const max_bits = Compilation.bit_int_max_bits;
};

pub const Tag = @import("Diagnostics/messages.def").with(Properties).Tag;

pub const Kind = enum { @"fatal error", @"error", note, warning, off, default };

pub const Options = struct {
    // do not directly use these, instead add `const NAME = true;`
    all: Kind = .default,
    extra: Kind = .default,
    pedantic: Kind = .default,

    @"unsupported-pragma": Kind = .default,
    @"c99-extensions": Kind = .default,
    @"implicit-int": Kind = .default,
    @"duplicate-decl-specifier": Kind = .default,
    @"missing-declaration": Kind = .default,
    @"extern-initializer": Kind = .default,
    @"implicit-function-declaration": Kind = .default,
    @"unused-value": Kind = .default,
    @"unreachable-code": Kind = .default,
    @"unknown-warning-option": Kind = .default,
    @"gnu-empty-struct": Kind = .default,
    @"gnu-alignof-expression": Kind = .default,
    @"macro-redefined": Kind = .default,
    @"generic-qual-type": Kind = .default,
    multichar: Kind = .default,
    @"pointer-integer-compare": Kind = .default,
    @"compare-distinct-pointer-types": Kind = .default,
    @"literal-conversion": Kind = .default,
    @"cast-qualifiers": Kind = .default,
    @"array-bounds": Kind = .default,
    @"int-conversion": Kind = .default,
    @"pointer-type-mismatch": Kind = .default,
    @"c23-extensions": Kind = .default,
    @"incompatible-pointer-types": Kind = .default,
    @"excess-initializers": Kind = .default,
    @"division-by-zero": Kind = .default,
    @"initializer-overrides": Kind = .default,
    @"incompatible-pointer-types-discards-qualifiers": Kind = .default,
    @"unknown-attributes": Kind = .default,
    @"ignored-attributes": Kind = .default,
    @"builtin-macro-redefined": Kind = .default,
    @"gnu-label-as-value": Kind = .default,
    @"malformed-warning-check": Kind = .default,
    @"#pragma-messages": Kind = .default,
    @"newline-eof": Kind = .default,
    @"empty-translation-unit": Kind = .default,
    @"implicitly-unsigned-literal": Kind = .default,
    @"c99-compat": Kind = .default,
    @"unicode-zero-width": Kind = .default,
    @"unicode-homoglyph": Kind = .default,
    unicode: Kind = .default,
    @"return-type": Kind = .default,
    @"dollar-in-identifier-extension": Kind = .default,
    @"unknown-pragmas": Kind = .default,
    @"predefined-identifier-outside-function": Kind = .default,
    @"many-braces-around-scalar-init": Kind = .default,
    uninitialized: Kind = .default,
    @"gnu-statement-expression": Kind = .default,
    @"gnu-imaginary-constant": Kind = .default,
    @"gnu-complex-integer": Kind = .default,
    @"ignored-qualifiers": Kind = .default,
    @"integer-overflow": Kind = .default,
    @"extra-semi": Kind = .default,
    @"gnu-binary-literal": Kind = .default,
    @"variadic-macros": Kind = .default,
    varargs: Kind = .default,
    @"#warnings": Kind = .default,
    @"deprecated-declarations": Kind = .default,
    @"backslash-newline-escape": Kind = .default,
    @"pointer-to-int-cast": Kind = .default,
    @"gnu-case-range": Kind = .default,
    @"c++-compat": Kind = .default,
    vla: Kind = .default,
    @"float-overflow-conversion": Kind = .default,
    @"float-zero-conversion": Kind = .default,
    @"float-conversion": Kind = .default,
    @"gnu-folding-constant": Kind = .default,
    undef: Kind = .default,
    @"ignored-pragmas": Kind = .default,
    @"gnu-include-next": Kind = .default,
    @"include-next-outside-header": Kind = .default,
    @"include-next-absolute-path": Kind = .default,
    @"enum-too-large": Kind = .default,
    @"fixed-enum-extension": Kind = .default,
    @"designated-init": Kind = .default,
    @"attribute-warning": Kind = .default,
    @"invalid-noreturn": Kind = .default,
    @"zero-length-array": Kind = .default,
    @"old-style-flexible-struct": Kind = .default,
    @"gnu-zero-variadic-macro-arguments": Kind = .default,
    @"main-return-type": Kind = .default,
    @"expansion-to-defined": Kind = .default,
    @"bit-int-extension": Kind = .default,
    @"keyword-macro": Kind = .default,
    @"pointer-arith": Kind = .default,
    @"sizeof-array-argument": Kind = .default,
    @"pre-c23-compat": Kind = .default,
    @"pointer-bool-conversion": Kind = .default,
    @"string-conversion": Kind = .default,
    @"gnu-auto-type": Kind = .default,
    @"gnu-union-cast": Kind = .default,
    @"pointer-sign": Kind = .default,
    @"fuse-ld-path": Kind = .default,
    @"language-extension-token": Kind = .default,
    @"complex-component-init": Kind = .default,
    @"microsoft-include": Kind = .default,
    @"microsoft-end-of-file": Kind = .default,
    @"invalid-source-encoding": Kind = .default,
    @"four-char-constants": Kind = .default,
    @"unknown-escape-sequence": Kind = .default,
    @"invalid-pp-token": Kind = .default,
    @"deprecated-non-prototype": Kind = .default,
    @"duplicate-embed-param": Kind = .default,
    @"unsupported-embed-param": Kind = .default,
    @"unused-result": Kind = .default,
    normalized: Kind = .default,
};

list: std.ArrayListUnmanaged(Message) = .{},
arena: std.heap.ArenaAllocator,
color: bool = true,
fatal_errors: bool = false,
options: Options = .{},
errors: u32 = 0,
macro_backtrace_limit: u32 = 6,

pub fn warningExists(name: []const u8) bool {
    inline for (std.meta.fields(Options)) |f| {
        if (mem.eql(u8, f.name, name)) return true;
    }
    return false;
}

pub fn set(diag: *Diagnostics, name: []const u8, to: Kind) !void {
    inline for (std.meta.fields(Options)) |f| {
        if (mem.eql(u8, f.name, name)) {
            @field(diag.options, f.name) = to;
            return;
        }
    }
    try diag.add(.{
        .tag = .unknown_warning,
        .extra = .{ .str = name },
    }, &.{});
}

pub fn init(gpa: Allocator) Diagnostics {
    return .{
        .arena = std.heap.ArenaAllocator.init(gpa),
    };
}

pub fn deinit(diag: *Diagnostics) void {
    diag.list.deinit(diag.arena.allocator());
    diag.arena.deinit();
}

pub fn add(diag: *Diagnostics, msg: Message, expansion_locs: []const Source.Location) Compilation.Error!void {
    const kind = diag.tagKind(msg.tag);
    if (kind == .off) return;
    var copy = msg;
    copy.kind = kind;

    if (expansion_locs.len != 0) copy.loc = expansion_locs[expansion_locs.len - 1];
    try diag.list.append(diag.arena.allocator(), copy);
    if (expansion_locs.len != 0) {
        // Add macro backtrace notes in reverse order omitting from the middle if needed.
        var i = expansion_locs.len - 1;
        const half = diag.macro_backtrace_limit / 2;
        const limit = if (i < diag.macro_backtrace_limit) 0 else i - half;
        try diag.list.ensureUnusedCapacity(
            diag.arena.allocator(),
            if (limit == 0) expansion_locs.len else diag.macro_backtrace_limit + 1,
        );
        while (i > limit) {
            i -= 1;
            diag.list.appendAssumeCapacity(.{
                .tag = .expanded_from_here,
                .kind = .note,
                .loc = expansion_locs[i],
            });
        }
        if (limit != 0) {
            diag.list.appendAssumeCapacity(.{
                .tag = .skipping_macro_backtrace,
                .kind = .note,
                .extra = .{ .unsigned = expansion_locs.len - diag.macro_backtrace_limit },
            });
            i = half - 1;
            while (i > 0) {
                i -= 1;
                diag.list.appendAssumeCapacity(.{
                    .tag = .expanded_from_here,
                    .kind = .note,
                    .loc = expansion_locs[i],
                });
            }
        }

        diag.list.appendAssumeCapacity(.{
            .tag = .expanded_from_here,
            .kind = .note,
            .loc = msg.loc,
        });
    }
    if (kind == .@"fatal error" or (kind == .@"error" and diag.fatal_errors))
        return error.FatalError;
}

pub fn fatal(
    diag: *Diagnostics,
    path: []const u8,
    line: []const u8,
    line_no: u32,
    col: u32,
    comptime fmt: []const u8,
    args: anytype,
) Compilation.Error {
    var m = MsgWriter.init(diag.color);
    defer m.deinit();

    m.location(path, line_no, col);
    m.start(.@"fatal error");
    m.print(fmt, args);
    m.end(line, col, false);

    diag.errors += 1;
    return error.FatalError;
}

pub fn fatalNoSrc(diag: *Diagnostics, comptime fmt: []const u8, args: anytype) error{FatalError} {
    if (!diag.color) {
        std.debug.print("fatal error: " ++ fmt ++ "\n", args);
    } else {
        const std_err = std.io.getStdErr().writer();
        util.setColor(.red, std_err);
        std_err.writeAll("fatal error: ") catch {};
        util.setColor(.white, std_err);
        std_err.print(fmt ++ "\n", args) catch {};
        util.setColor(.reset, std_err);
    }
    diag.errors += 1;
    return error.FatalError;
}

pub fn render(comp: *Compilation) void {
    if (comp.diag.list.items.len == 0) return;
    var m = defaultMsgWriter(comp);
    defer m.deinit();
    renderMessages(comp, &m);
}
pub fn defaultMsgWriter(comp: *const Compilation) MsgWriter {
    return MsgWriter.init(comp.diag.color);
}

pub fn renderMessages(comp: *Compilation, m: anytype) void {
    var errors: u32 = 0;
    var warnings: u32 = 0;
    for (comp.diag.list.items) |msg| {
        switch (msg.kind) {
            .@"fatal error", .@"error" => errors += 1,
            .warning => warnings += 1,
            .note => {},
            .off => continue, // happens if an error is added before it is disabled
            .default => unreachable,
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

    comp.diag.list.items.len = 0;
    comp.diag.errors += errors;
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
            @tagName(msg.extra.ignored_record_attr.specifier),
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
            m.print(" [-Werror,-W{s}]", .{optName(some)});
        } else if (msg.kind != .note) {
            m.print(" [-W{s}]", .{optName(some)});
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

fn optName(offset: u16) []const u8 {
    return std.meta.fieldNames(Options)[offset / @sizeOf(Kind)];
}

fn tagKind(diag: *Diagnostics, tag: Tag) Kind {
    // XXX: horrible hack, do not do this
    const comp = @fieldParentPtr(Compilation, "diag", diag);

    const prop = tag.property();
    var kind = prop.getKind(&diag.options);

    if (prop.all) {
        if (diag.options.all != .default) kind = diag.options.all;
    }
    if (prop.w_extra) {
        if (diag.options.extra != .default) kind = diag.options.extra;
    }
    if (prop.pedantic) {
        if (diag.options.pedantic != .default) kind = diag.options.pedantic;
    }
    if (prop.suppress_version) |some| if (comp.langopts.standard.atLeast(some)) return .off;
    if (prop.suppress_unless_version) |some| if (!comp.langopts.standard.atLeast(some)) return .off;
    if (prop.suppress_gnu and comp.langopts.standard.isExplicitGNU()) return .off;
    if (prop.suppress_gcc and comp.langopts.emulate == .gcc) return .off;
    if (prop.suppress_clang and comp.langopts.emulate == .clang) return .off;
    if (prop.suppress_msvc and comp.langopts.emulate == .msvc) return .off;
    if (kind == .@"error" and diag.fatal_errors) kind = .@"fatal error";
    return kind;
}

const MsgWriter = struct {
    w: std.io.BufferedWriter(4096, std.fs.File.Writer),
    color: bool,

    fn init(color: bool) MsgWriter {
        std.debug.getStderrMutex().lock();
        return .{
            .w = std.io.bufferedWriter(std.io.getStdErr().writer()),
            .color = color,
        };
    }

    pub fn deinit(m: *MsgWriter) void {
        m.w.flush() catch {};
        std.debug.getStderrMutex().unlock();
    }

    pub fn print(m: *MsgWriter, comptime fmt: []const u8, args: anytype) void {
        m.w.writer().print(fmt, args) catch {};
    }

    fn write(m: *MsgWriter, msg: []const u8) void {
        m.w.writer().writeAll(msg) catch {};
    }

    fn setColor(m: *MsgWriter, color: util.Color) void {
        util.setColor(color, m.w.writer());
    }

    fn location(m: *MsgWriter, path: []const u8, line: u32, col: u32) void {
        const prefix = if (std.fs.path.dirname(path) == null and path[0] != '<') "." ++ std.fs.path.sep_str else "";
        if (!m.color) {
            m.print("{s}{s}:{d}:{d}: ", .{ prefix, path, line, col });
        } else {
            m.setColor(.white);
            m.print("{s}{s}:{d}:{d}: ", .{ prefix, path, line, col });
        }
    }

    fn start(m: *MsgWriter, kind: Kind) void {
        if (!m.color) {
            m.print("{s}: ", .{@tagName(kind)});
        } else {
            switch (kind) {
                .@"fatal error", .@"error" => m.setColor(.red),
                .note => m.setColor(.cyan),
                .warning => m.setColor(.purple),
                .off, .default => unreachable,
            }
            m.write(switch (kind) {
                .@"fatal error" => "fatal error: ",
                .@"error" => "error: ",
                .note => "note: ",
                .warning => "warning: ",
                .off, .default => unreachable,
            });
            m.setColor(.white);
        }
    }

    fn end(m: *MsgWriter, maybe_line: ?[]const u8, col: u32, end_with_splice: bool) void {
        const line = maybe_line orelse {
            m.write("\n");
            m.setColor(.reset);
            return;
        };
        const trailer = if (end_with_splice) "\\ " else "";
        if (!m.color) {
            m.print("\n{s}{s}\n", .{ line, trailer });
            m.print("{s: >[1]}^\n", .{ "", col });
        } else {
            m.setColor(.reset);
            m.print("\n{s}{s}\n{s: >[3]}", .{ line, trailer, "", col });
            m.setColor(.green);
            m.write("^\n");
            m.setColor(.reset);
        }
    }
};
