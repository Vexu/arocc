const std = @import("std");
const mem = std.mem;
const Allocator = mem.Allocator;
const Source = @import("Source.zig");
const Compilation = @import("Compilation.zig");
const Token = @import("Tokenizer.zig").Token;

const Diagnostics = @This();

const Message = struct {
    tag: Tag,
    source_id: Source.Id,
    loc_start: u32,
    extra: union {
        str: []const u8,
        tok_id: struct {
            expected: Token.Id,
            actual: Token.Id,
        },
        none: void,
    } = .{ .none = {} },
};

pub const Tag = enum {
    // Maybe someday this will no longer be needed.
    todo,
    error_directive,
    elif_without_if,
    elif_after_else,
    else_without_if,
    else_after_else,
    endif_without_if,
    unsupported_pragma,
    line_simple_digit,
    line_invalid_filename,
    unterminated_conditional_directive,
    invalid_preprocessing_directive,
    macro_name_missing,
    extra_tokens_directive_end,
    expected_value_in_expr,
    closing_paren,
    to_match_paren,
    header_str_closing,
    header_str_match,
    string_literal_in_pp_expr,
    float_literal_in_pp_expr,
    defined_as_macro_name,
    macro_name_must_be_identifier,
    whitespace_after_macro_name,
    hash_hash_at_start,
    hash_hash_at_end,
    pasting_formed_invalid,
    missing_paren_param_list,
    unterminated_macro_param_list,
    invalid_token_param_list,
    hash_not_followed_param,
    expected_filename,
    empty_filename,
    expected_invalid,
    expected_token,
    expected_expr,
    expected_integer_constant_expr,
};

list: std.ArrayList(Message),
color: bool = true,

pub fn init(gpa: *Allocator) Diagnostics {
    return .{
        .color = std.io.getStdErr().supportsAnsiEscapeCodes(),
        .list = std.ArrayList(Message).init(gpa),
    };
}

pub fn deinit(diag: *Diagnostics) void {
    diag.list.deinit();
}

pub fn fatal(diag: *Diagnostics, path: []const u8, lcs: Source.LCS, comptime fmt: []const u8, args: anytype) Compilation.Error {
    var m = MsgWriter.init(diag.color);
    defer m.deinit();

    m.start(.@"fatal error", path, lcs);
    std.debug.print(fmt, args);
    m.end(lcs);
    return error.FatalError;
}

pub fn fatalNoSrc(comp: *Compilation, comptime fmt: []const u8, args: anytype) Compilation.Error {
    if (std.builtin.os.tag == .windows or !comp.diag.color) {
        std.debug.print("fatal error: " ++ fmt ++ "\n", args);
    } else {
        const RED = "\x1b[31;1m";
        const WHITE = "\x1b[37;1m";
        const RESET = "\x1b[0m";

        std.debug.print(RED ++ "fatal error: " ++ WHITE ++ fmt ++ "\n" ++ RESET, args);
    }
    return error.FatalError;
}

pub fn render(comp: *Compilation) void {
    if (comp.diag.list.items.len == 0) return;
    var m = MsgWriter.init(comp.diag.color);
    defer m.deinit();

    var errors: u32 = 0;
    var warnings: u32 = 0;
    for (comp.diag.list.items) |msg| {
        const source = comp.getSource(msg.source_id);
        const lcs = source.lineColString(msg.loc_start);
        const kind = comp.diag.tagKind(msg.tag);
        switch (kind) {
            .@"error" => errors += 1,
            .warning => warnings += 1,
            .note => {},
            .@"fatal error" => unreachable,
        }
        m.start(kind, source.path, lcs);
        switch (msg.tag) {
            .todo => m.print("TODO: {s}", .{msg.extra.str}),
            .error_directive => m.print("{s}", .{msg.extra.str}),
            .elif_without_if => m.write("#elif without #if"),
            .elif_after_else => m.write("#elif after #else"),
            .else_without_if => m.write("#else without #if"),
            .else_after_else => m.write("#else after #else"),
            .endif_without_if => m.write("#endif without #if"),
            .unsupported_pragma => m.print("unsupported #pragma directive '{s}'", .{msg.extra.str}),
            .line_simple_digit => m.write("#line directive requires a simple digit sequence"),
            .line_invalid_filename => m.write("invalid filename for #line directive"),
            .unterminated_conditional_directive => m.write("unterminated conditional directive"),
            .invalid_preprocessing_directive => m.write("invalid preprocessing directive"),
            .macro_name_missing => m.write("macro name missing"),
            .extra_tokens_directive_end => m.write("extra tokens at end of macro directive"),
            .expected_value_in_expr => m.write("expected value in expression"),
            .closing_paren => m.write("expected closing ')'"),
            .to_match_paren => m.write("to match this '('"),
            .header_str_closing => m.write("expected closing '>'"),
            .header_str_match => m.write("to match this '<'"),
            .string_literal_in_pp_expr => m.write("string literal in preprocessor expression"),
            .float_literal_in_pp_expr => m.write("floating point literal in preprocessor expression"),
            .defined_as_macro_name => m.write("'defined' cannot be used as a macro name"),
            .macro_name_must_be_identifier => m.write("macro name must be an identifier"),
            .whitespace_after_macro_name => m.write("ISO C99 requires whitespace after the macro name"),
            .hash_hash_at_start => m.write("'##' cannot appear at the start of a macro expansion"),
            .hash_hash_at_end => m.write("'##' cannot appear at the end of a macro expansion"),
            .pasting_formed_invalid => m.print("pasting formed '{s}', an invalid preprocessing token", .{msg.extra.str}),
            .missing_paren_param_list => m.write("missing ')' in macro parameter list"),
            .unterminated_macro_param_list => m.write("unterminated macro param list"),
            .invalid_token_param_list => m.write("invalid token in macro parameter list"),
            .hash_not_followed_param => m.write("'#' is not followed by a macro parameter"),
            .expected_filename => m.write("expected \"FILENAME\" or <FILENAME>"),
            .empty_filename => m.write("empty filename"),
            .expected_invalid => m.print("expected '{s}', found invalid bytes", .{msg.extra.tok_id.expected.symbol()}),
            .expected_token => m.print("expected '{s}', found '{s}'", .{
                msg.extra.tok_id.expected.symbol(),
                msg.extra.tok_id.actual.symbol(),
            }),
            .expected_expr => m.write("expected expression"),
            .expected_integer_constant_expr => m.write("expression is not an integer constant expression")
        }
        m.end(lcs);
    }
    if (errors != 0 and warnings != 0) {}
}

const Kind = enum { @"fatal error", @"error", note, warning };

fn tagKind(diag: *Diagnostics, tag: Tag) Kind {
    return switch (tag) {
        .todo,
        .error_directive,
        .elif_without_if,
        .elif_after_else,
        .else_without_if,
        .else_after_else,
        .endif_without_if,
        .line_simple_digit,
        .line_invalid_filename,
        .unterminated_conditional_directive,
        .invalid_preprocessing_directive,
        .macro_name_missing,
        .extra_tokens_directive_end,
        .expected_value_in_expr,
        .closing_paren,
        .header_str_closing,
        .string_literal_in_pp_expr,
        .float_literal_in_pp_expr,
        .defined_as_macro_name,
        .macro_name_must_be_identifier,
        .whitespace_after_macro_name,
        .hash_hash_at_start,
        .hash_hash_at_end,
        .pasting_formed_invalid,
        .missing_paren_param_list,
        .unterminated_macro_param_list,
        .invalid_token_param_list,
        .hash_not_followed_param,
        .expected_filename,
        .empty_filename,
        .expected_invalid,
        .expected_token,
        .expected_expr,
        .expected_integer_constant_expr,
        => .@"error",
        .unsupported_pragma => .warning,
        .to_match_paren,
        .header_str_match,
        => .note,
    };
}

const MsgWriter = struct {
    // TODO Impl is private
    held: @typeInfo(@TypeOf(std.Thread.Mutex.acquire)).Fn.return_type.?,
    w: std.fs.File.Writer,
    color: bool,

    fn init(color: bool) MsgWriter {
        return .{
            .held = std.debug.getStderrMutex().acquire(),
            .w = std.io.getStdErr().writer(),
            .color = color,
        };
    }

    fn deinit(m: *MsgWriter) void {
        m.held.release();
    }

    fn print(m: *MsgWriter, comptime fmt: []const u8, args: anytype) void {
        m.w.print(fmt, args) catch {};
    }

    fn write(m: *MsgWriter, msg: []const u8) void {
        m.w.writeAll(msg) catch {};
    }

    fn start(m: *MsgWriter, kind: Kind, path: []const u8, lcs: Source.LCS) void {
        if (std.builtin.os.tag == .windows or !m.color) {
            if (lcs.col == 0)
                m.print("{s}:??:??: {s}: ", .{ path, @tagName(kind) })
            else
                m.print("{s}:{d}:{d}: {s}: ", .{ path, lcs.line, lcs.col, @tagName(kind) });
        } else {
            const PURPLE = "\x1b[35;1m";
            const CYAN = "\x1b[36;1m";
            const RED = "\x1b[31;1m";
            const WHITE = "\x1b[37;1m";

            const msg_kind_str = switch (kind) {
                .@"fatal error" => RED ++ "fatal error: " ++ WHITE,
                .@"error" => RED ++ "error: " ++ WHITE,
                .note => CYAN ++ "note: " ++ WHITE,
                .warning => PURPLE ++ "warning: " ++ WHITE,
            };

            if (lcs.col == 0)
                m.print(WHITE ++ "{s}:??:??: {s}", .{ path, msg_kind_str })
            else
                m.print(WHITE ++ "{s}:{d}:{d}: {s}", .{ path, lcs.line, lcs.col, msg_kind_str });
        }
    }

    fn end(m: *MsgWriter, lcs: Source.LCS) void {
        if (std.builtin.os.tag == .windows or !m.color) {
            if (lcs.col == 0) return;
            m.print("\n{s}\n", .{lcs.str});
            m.print("{s: >[1]}^\n", .{ "", lcs.col - 1 });
        } else {
            const GREEN = "\x1b[32;1m";
            const WHITE = "\x1b[37;1m";
            const RESET = "\x1b[0m";
            if (lcs.col == 0) {
                m.write("\n" ++ RESET);
                return;
            }

            m.print("\n" ++ RESET ++ "{s}\n", .{lcs.str});
            m.print("{s: >[1]}" ++ GREEN ++ "^" ++ RESET ++ "\n", .{ "", lcs.col - 1 });
        }
    }
};
