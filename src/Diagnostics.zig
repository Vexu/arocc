const std = @import("std");
const mem = std.mem;
const Allocator = mem.Allocator;
const Source = @import("Source.zig");
const Compilation = @import("Compilation.zig");

const Diagnostics = @This();

const Message = struct {
    tag: Tag,
    source_id: Source.Id,
    loc_start: u32,
    extra: union {
        str: []const u8,
        none: void,
    } = .{ .none = {} },
};

pub const Tag = enum {
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
    msgStart(diag.color, .@"fatal error", path, lcs);
    std.debug.print(fmt, args);
    msgEnd(diag.color, lcs);
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
        msgStart(comp.diag.color, kind, source.path, lcs);
        switch (msg.tag) {
            .error_directive => std.debug.print("{s}", .{msg.extra.str}),
            .elif_without_if => std.debug.print("#elif without #if", .{}),
            .elif_after_else => std.debug.print("#elif after #else", .{}),
            .else_without_if => std.debug.print("#else without #if", .{}),
            .else_after_else => std.debug.print("#else after #else", .{}),
            .endif_without_if => std.debug.print("#endif without #if", .{}),
            .unsupported_pragma => std.debug.print("unsupported #pragma directive '{s}'", .{msg.extra.str}),
            .line_simple_digit => std.debug.print("#line directive requires a simple digit sequence", .{}),
            .line_invalid_filename => std.debug.print("invalid filename for #line directive", .{}),
            .unterminated_conditional_directive => std.debug.print("unterminated conditional directive", .{}),
            .invalid_preprocessing_directive => std.debug.print("invalid preprocessing directive", .{}),
            .macro_name_missing => std.debug.print("macro name missing", .{}),
            .extra_tokens_directive_end => std.debug.print("extra tokens at end of macro directive", .{}),
            .expected_value_in_expr => std.debug.print("expected value in expression", .{}),
            .closing_paren => std.debug.print("expected closing ')'", .{}),
            .to_match_paren => std.debug.print("to match this '('", .{}),
            .header_str_closing => std.debug.print("expected closing '>'", .{}),
            .header_str_match => std.debug.print("to match this '<'", .{}),
            .string_literal_in_pp_expr => std.debug.print("string literal in preprocessor expression", .{}),
            .float_literal_in_pp_expr => std.debug.print("floating point literal in preprocessor expression", .{}),
            .defined_as_macro_name => std.debug.print("'defined' cannot be used as a macro name", .{}),
            .macro_name_must_be_identifier => std.debug.print("macro name must be an identifier", .{}),
            .whitespace_after_macro_name => std.debug.print("ISO C99 requires whitespace after the macro name", .{}),
            .hash_hash_at_start => std.debug.print("'##' cannot appear at the start of a macro expansion", .{}),
            .hash_hash_at_end => std.debug.print("'##' cannot appear at the end of a macro expansion", .{}),
            .pasting_formed_invalid => std.debug.print("pasting formed '{s}', an invalid preprocessing token", .{msg.extra.str}),
            .missing_paren_param_list => std.debug.print("missing ')' in macro parameter list", .{}),
            .unterminated_macro_param_list => std.debug.print("unterminated macro param list", .{}),
            .invalid_token_param_list => std.debug.print("invalid token in macro parameter list", .{}),
            .hash_not_followed_param => std.debug.print("'#' is not followed by a macro parameter", .{}),
            .expected_filename => std.debug.print("expected \"FILENAME\" or <FILENAME>", .{}),
            .empty_filename => std.debug.print("empty filename", .{}),
        }
        msgEnd(comp.diag.color, lcs);
    }
    if (errors != 0 and warnings != 0) {}
}

const Kind = enum { @"fatal error", @"error", note, warning };

fn tagKind(diag: *Diagnostics, tag: Tag) Kind {
    return switch (tag) {
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
        => .@"error",
        .unsupported_pragma => .warning,
        .to_match_paren,
        .header_str_match,
        => .note,
    };
}

fn msgStart(color: bool, kind: Kind, path: []const u8, lcs: Source.LCS) void {
    if (std.builtin.os.tag == .windows or !color) {
        if (lcs.col == 0)
            std.debug.print("{s}:??:??: {s}: ", .{ path, @tagName(kind) })
        else
            std.debug.print("{s}:{d}:{d}: {s}: ", .{ path, lcs.line, lcs.col, @tagName(kind) });
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
            std.debug.print(WHITE ++ "{s}:??:??: {s}", .{ path, msg_kind_str })
        else
            std.debug.print(WHITE ++ "{s}:{d}:{d}: {s}", .{ path, lcs.line, lcs.col, msg_kind_str });
    }
}

fn msgEnd(color: bool, lcs: Source.LCS) void {
    if (std.builtin.os.tag == .windows or !color) {
        if (lcs.col == 0) return;
        std.debug.print("\n{s}\n", .{lcs.str});
        std.debug.print("{s: >[1]}^\n", .{ "", lcs.col - 1 });
    } else {
        const GREEN = "\x1b[32;1m";
        const WHITE = "\x1b[37;1m";
        const RESET = "\x1b[0m";
        if (lcs.col == 0) {
            std.debug.print("\n" ++ RESET, .{});
            return;
        }

        std.debug.print("\n" ++ RESET ++ "{s}\n", .{lcs.str});
        std.debug.print("{s: >[1]}" ++ GREEN ++ "^" ++ RESET ++ "\n", .{ "", lcs.col - 1 });
    }
}
