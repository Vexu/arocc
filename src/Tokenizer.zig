const std = @import("std");
const assert = std.debug.assert;
const Source = @import("Source.zig");

const Tokenizer = @This();

pub const Token = struct {
    id: Id,
    source: Source.Id,
    loc: Source.Location,

    comptime {
        assert(@sizeOf(Token) == 12);
    }

    pub const Id = enum(u8) {
        invalid,
        nl,
        eof,
        identifier,

        // string literals with prefixes
        string_literal,
        string_literal_utf_16,
        string_literal_utf_8,
        string_literal_utf_32,
        string_literal_wide,

        // char literals with prefixes
        char_literal,
        char_literal_utf_16,
        char_literal_utf_32,
        char_literal_wide,

        // float literals with suffixes
        float_literal,
        float_literal_f,
        float_literal_l,

        // integer literals with suffixes
        integer_literal,
        integer_literal_u,
        integer_literal_l,
        integer_literal_lu,
        integer_literal_ll,
        integer_literal_llu,

        bang,
        bang_equal,
        pipe,
        pipe_pipe,
        pipe_equal,
        equal,
        equal_equal,
        l_paren,
        r_paren,
        l_brace,
        r_brace,
        l_bracket,
        r_bracket,
        period,
        ellipsis,
        caret,
        caret_equal,
        plus,
        plus_plus,
        plus_equal,
        minus,
        minus_minus,
        minus_equal,
        asterisk,
        asterisk_equal,
        percent,
        percent_equal,
        arrow,
        colon,
        semicolon,
        slash,
        slash_equal,
        comma,
        ampersand,
        ampersand_ampersand,
        ampersand_equal,
        question_mark,
        angle_bracket_left,
        angle_bracket_left_equal,
        angle_bracket_angle_bracket_left,
        angle_bracket_angle_bracket_left_equal,
        angle_bracket_right,
        angle_bracket_right_equal,
        angle_bracket_angle_bracket_right,
        angle_bracket_angle_bracket_right_equal,
        tilde,
        hash,
        hash_hash,

        /// Special token to speed up preprocessing, `loc.end` will be an index to the param list.
        macro_param,
        /// Special token to speed up preprocessing, `loc.end` will be an index to the param list.
        stringify_param,

        keyword_auto,
        keyword_break,
        keyword_case,
        keyword_char,
        keyword_const,
        keyword_continue,
        keyword_default,
        keyword_do,
        keyword_double,
        keyword_else,
        keyword_enum,
        keyword_extern,
        keyword_float,
        keyword_for,
        keyword_goto,
        keyword_if,
        keyword_int,
        keyword_long,
        keyword_register,
        keyword_return,
        keyword_short,
        keyword_signed,
        keyword_sizeof,
        keyword_static,
        keyword_struct,
        keyword_switch,
        keyword_typedef,
        keyword_union,
        keyword_unsigned,
        keyword_void,
        keyword_volatile,
        keyword_while,

        // ISO C99
        keyword_bool,
        keyword_complex,
        keyword_imaginary,
        keyword_inline,
        keyword_restrict,

        // ISO C11
        keyword_alignas,
        keyword_alignof,
        keyword_atomic,
        keyword_generic,
        keyword_noreturn,
        keyword_static_assert,
        keyword_thread_local,

        // Preprocessor directives
        keyword_include,
        keyword_define,
        keyword_defined,
        keyword_undef,
        keyword_ifdef,
        keyword_ifndef,
        keyword_elif,
        keyword_endif,
        keyword_error,
        keyword_pragma,
        keyword_line,

        /// Return true if token is identifier or keyword.
        pub fn isMacroIdentifier(id: Id) bool {
            switch (id) {
                .keyword_include,
                .keyword_define,
                .keyword_defined,
                .keyword_undef,
                .keyword_ifdef,
                .keyword_ifndef,
                .keyword_elif,
                .keyword_endif,
                .keyword_error,
                .keyword_pragma,
                .keyword_line,
                .keyword_auto,
                .keyword_break,
                .keyword_case,
                .keyword_char,
                .keyword_const,
                .keyword_continue,
                .keyword_default,
                .keyword_do,
                .keyword_double,
                .keyword_else,
                .keyword_enum,
                .keyword_extern,
                .keyword_float,
                .keyword_for,
                .keyword_goto,
                .keyword_if,
                .keyword_int,
                .keyword_long,
                .keyword_register,
                .keyword_return,
                .keyword_short,
                .keyword_signed,
                .keyword_sizeof,
                .keyword_static,
                .keyword_struct,
                .keyword_switch,
                .keyword_typedef,
                .keyword_union,
                .keyword_unsigned,
                .keyword_void,
                .keyword_volatile,
                .keyword_while,
                .keyword_bool,
                .keyword_complex,
                .keyword_imaginary,
                .keyword_inline,
                .keyword_restrict,
                .keyword_alignas,
                .keyword_alignof,
                .keyword_atomic,
                .keyword_generic,
                .keyword_noreturn,
                .keyword_static_assert,
                .keyword_thread_local,
                .identifier,
                => return true,
                else => return false,
            }
        }

        /// Turn macro keywords into identifiers.
        pub fn simplifyMacroKeyword(id: *Id) void {
            switch (id.*) {
                .keyword_include,
                .keyword_define,
                .keyword_defined,
                .keyword_undef,
                .keyword_ifdef,
                .keyword_ifndef,
                .keyword_elif,
                .keyword_endif,
                .keyword_error,
                .keyword_pragma,
                .keyword_line,
                => id.* = .identifier,
                else => {},
            }
        }
    };

    pub const keywords = std.ComptimeStringMap(Id, .{
        .{ "auto", .keyword_auto },
        .{ "break", .keyword_break },
        .{ "case", .keyword_case },
        .{ "char", .keyword_char },
        .{ "const", .keyword_const },
        .{ "continue", .keyword_continue },
        .{ "default", .keyword_default },
        .{ "do", .keyword_do },
        .{ "double", .keyword_double },
        .{ "else", .keyword_else },
        .{ "enum", .keyword_enum },
        .{ "extern", .keyword_extern },
        .{ "float", .keyword_float },
        .{ "for", .keyword_for },
        .{ "goto", .keyword_goto },
        .{ "if", .keyword_if },
        .{ "int", .keyword_int },
        .{ "long", .keyword_long },
        .{ "register", .keyword_register },
        .{ "return", .keyword_return },
        .{ "short", .keyword_short },
        .{ "signed", .keyword_signed },
        .{ "sizeof", .keyword_sizeof },
        .{ "static", .keyword_static },
        .{ "struct", .keyword_struct },
        .{ "switch", .keyword_switch },
        .{ "typedef", .keyword_typedef },
        .{ "union", .keyword_union },
        .{ "unsigned", .keyword_unsigned },
        .{ "void", .keyword_void },
        .{ "volatile", .keyword_volatile },
        .{ "while", .keyword_while },

        // ISO C99
        .{ "_Bool", .keyword_bool },
        .{ "_Complex", .keyword_complex },
        .{ "_Imaginary", .keyword_imaginary },
        .{ "inline", .keyword_inline },
        .{ "restrict", .keyword_restrict },

        // ISO C11
        .{ "_Alignas", .keyword_alignas },
        .{ "_Alignof", .keyword_alignof },
        .{ "_Atomic", .keyword_atomic },
        .{ "_Generic", .keyword_generic },
        .{ "_Noreturn", .keyword_noreturn },
        .{ "_Static_assert", .keyword_static_assert },
        .{ "_Thread_local", .keyword_thread_local },

        // Preprocessor directives
        .{ "include", .keyword_include },
        .{ "define", .keyword_define },
        .{ "defined", .keyword_defined },
        .{ "undef", .keyword_undef },
        .{ "ifdef", .keyword_ifdef },
        .{ "ifndef", .keyword_ifndef },
        .{ "elif", .keyword_elif },
        .{ "endif", .keyword_endif },
        .{ "error", .keyword_error },
        .{ "pragma", .keyword_pragma },
        .{ "line", .keyword_line },
    });
};

buf: []const u8,
index: u32 = 0,
source: Source,

pub fn next(self: *Tokenizer) Token {
    const start_index = self.index;
    var state: enum {
        start,
        cr,
        back_slash,
        back_slash_cr,
        u,
        u8,
        U,
        L,
        string_literal,
        char_literal_start,
        char_literal,
        escape_sequence,
        cr_escape,
        octal_escape,
        hex_escape,
        unicode_escape,
        identifier,
        equal,
        bang,
        pipe,
        percent,
        asterisk,
        plus,
        angle_bracket_left,
        angle_bracket_angle_bracket_left,
        angle_bracket_right,
        angle_bracket_angle_bracket_right,
        caret,
        period,
        period2,
        minus,
        slash,
        ampersand,
        hash,
        line_comment,
        multi_line_comment,
        multi_line_comment_asterisk,
        zero,
        integer_literal_oct,
        integer_literal_binary,
        integer_literal_hex,
        integer_literal,
        integer_suffix,
        integer_suffix_u,
        integer_suffix_l,
        integer_suffix_ll,
        integer_suffix_ul,
        float_fraction,
        float_fraction_hex,
        float_exponent,
        float_exponent_digits,
        float_suffix,
    } = .start;

    var start = self.index;
    var id: Token.Id = .eof;

    var string = false;
    var counter: u32 = 0;
    while (self.index < self.buf.len) : (self.index += 1) {
        const c = self.buf[self.index];
        switch (state) {
            .start => switch (c) {
                '\n' => {
                    id = .nl;
                    self.index += 1;
                    break;
                },
                '\r' => state = .cr,
                '"' => {
                    id = .string_literal;
                    state = .string_literal;
                },
                '\'' => {
                    id = .char_literal;
                    state = .char_literal_start;
                },
                'u' => state = .u,
                'U' => state = .U,
                'L' => state = .L,
                'a'...'t', 'v'...'z', 'A'...'K', 'M'...'T', 'V'...'Z', '_', '$' => state = .identifier,
                '=' => state = .equal,
                '!' => state = .bang,
                '|' => state = .pipe,
                '(' => {
                    id = .l_paren;
                    self.index += 1;
                    break;
                },
                ')' => {
                    id = .r_paren;
                    self.index += 1;
                    break;
                },
                '[' => {
                    id = .l_bracket;
                    self.index += 1;
                    break;
                },
                ']' => {
                    id = .r_bracket;
                    self.index += 1;
                    break;
                },
                ';' => {
                    id = .semicolon;
                    self.index += 1;
                    break;
                },
                ',' => {
                    id = .comma;
                    self.index += 1;
                    break;
                },
                '?' => {
                    id = .question_mark;
                    self.index += 1;
                    break;
                },
                ':' => {
                    id = .colon;
                    self.index += 1;
                    break;
                },
                '%' => state = .percent,
                '*' => state = .asterisk,
                '+' => state = .plus,
                '<' => state = .angle_bracket_left,
                '>' => state = .angle_bracket_right,
                '^' => state = .caret,
                '{' => {
                    id = .l_brace;
                    self.index += 1;
                    break;
                },
                '}' => {
                    id = .r_brace;
                    self.index += 1;
                    break;
                },
                '~' => {
                    id = .tilde;
                    self.index += 1;
                    break;
                },
                '.' => state = .period,
                '-' => state = .minus,
                '/' => state = .slash,
                '&' => state = .ampersand,
                '#' => state = .hash,
                '0' => state = .zero,
                '1'...'9' => state = .integer_literal,
                '\\' => state = .back_slash,
                '\t', '\x0B', '\x0C', ' ' => start = self.index + 1,
                else => {
                    id = .invalid;
                    self.index += 1;
                    break;
                },
            },
            .cr => switch (c) {
                '\n' => {
                    id = .nl;
                    self.index += 1;
                    break;
                },
                else => {
                    id = .invalid;
                    break;
                },
            },
            .back_slash => switch (c) {
                '\n' => {
                    start = self.index + 1;
                    state = .start;
                },
                '\r' => state = .back_slash_cr,
                '\t', '\x0B', '\x0C', ' ' => {
                    // TODO warn
                },
                else => {
                    id = .invalid;
                    break;
                },
            },
            .back_slash_cr => switch (c) {
                '\n' => {
                    start = self.index + 1;
                    state = .start;
                },
                else => {
                    id = .invalid;
                    break;
                },
            },
            .u => switch (c) {
                '8' => {
                    state = .u8;
                },
                '\'' => {
                    id = .char_literal_utf_16;
                    state = .char_literal_start;
                },
                '\"' => {
                    id = .string_literal_utf_16;
                    state = .string_literal;
                },
                else => {
                    self.index -= 1;
                    state = .identifier;
                },
            },
            .u8 => switch (c) {
                '\"' => {
                    id = .string_literal_utf_8;
                    state = .string_literal;
                },
                else => {
                    self.index -= 1;
                    state = .identifier;
                },
            },
            .U => switch (c) {
                '\'' => {
                    id = .char_literal_utf_32;
                    state = .char_literal_start;
                },
                '\"' => {
                    id = .string_literal_utf_32;
                    state = .string_literal;
                },
                else => {
                    self.index -= 1;
                    state = .identifier;
                },
            },
            .L => switch (c) {
                '\'' => {
                    id = .char_literal_wide;
                    state = .char_literal_start;
                },
                '\"' => {
                    id = .string_literal_wide;
                    state = .string_literal;
                },
                else => {
                    self.index -= 1;
                    state = .identifier;
                },
            },
            .string_literal => switch (c) {
                '\\' => {
                    string = true;
                    state = .escape_sequence;
                },
                '"' => {
                    self.index += 1;
                    break;
                },
                '\n', '\r' => {
                    id = .invalid;
                    break;
                },
                else => {},
            },
            .char_literal_start => switch (c) {
                '\\' => {
                    string = false;
                    state = .escape_sequence;
                },

                '\'', '\n' => {
                    id = .invalid;
                    break;
                },
                else => {
                    state = .char_literal;
                },
            },
            .char_literal => switch (c) {
                '\\' => {
                    string = false;
                    state = .escape_sequence;
                },
                '\'' => {
                    self.index += 1;
                    break;
                },
                '\n' => {
                    id = .invalid;
                    break;
                },
                else => {},
            },
            .escape_sequence => switch (c) {
                '\'', '"', '?', '\\', 'a', 'b', 'f', 'n', 'r', 't', 'v', '\n' => {
                    state = if (string) .string_literal else .char_literal;
                },
                '\r' => state = .cr_escape,
                '0'...'7' => {
                    counter = 1;
                    state = .octal_escape;
                },
                'x' => state = .hex_escape,
                'u' => {
                    counter = 4;
                    state = .octal_escape;
                },
                'U' => {
                    counter = 8;
                    state = .octal_escape;
                },
                else => {
                    id = .invalid;
                    break;
                },
            },
            .cr_escape => switch (c) {
                '\n' => {
                    state = if (string) .string_literal else .char_literal;
                },
                else => {
                    id = .invalid;
                    break;
                },
            },
            .octal_escape => switch (c) {
                '0'...'7' => {
                    counter += 1;
                    if (counter == 3) {
                        state = if (string) .string_literal else .char_literal;
                    }
                },
                else => {
                    self.index -= 1;
                    state = if (string) .string_literal else .char_literal;
                },
            },
            .hex_escape => switch (c) {
                '0'...'9', 'a'...'f', 'A'...'F' => {},
                else => {
                    self.index -= 1;
                    state = if (string) .string_literal else .char_literal;
                },
            },
            .unicode_escape => switch (c) {
                '0'...'9', 'a'...'f', 'A'...'F' => {
                    counter -= 1;
                    if (counter == 0) {
                        state = if (string) .string_literal else .char_literal;
                    }
                },
                else => {
                    if (counter != 0) {
                        id = .invalid;
                        break;
                    }
                    self.index -= 1;
                    state = if (string) .string_literal else .char_literal;
                },
            },
            .identifier => switch (c) {
                'a'...'z', 'A'...'Z', '_', '0'...'9', '$' => {},
                else => {
                    id = Token.keywords.get(self.buf[start..self.index]) orelse .identifier;
                    break;
                },
            },
            .equal => switch (c) {
                '=' => {
                    id = .equal_equal;
                    self.index += 1;
                    break;
                },
                else => {
                    id = .equal;
                    break;
                },
            },
            .bang => switch (c) {
                '=' => {
                    id = .bang_equal;
                    self.index += 1;
                    break;
                },
                else => {
                    id = .bang;
                    break;
                },
            },
            .pipe => switch (c) {
                '=' => {
                    id = .pipe_equal;
                    self.index += 1;
                    break;
                },
                '|' => {
                    id = .pipe_pipe;
                    self.index += 1;
                    break;
                },
                else => {
                    id = .pipe;
                    break;
                },
            },
            .percent => switch (c) {
                '=' => {
                    id = .percent_equal;
                    self.index += 1;
                    break;
                },
                else => {
                    id = .percent;
                    break;
                },
            },
            .asterisk => switch (c) {
                '=' => {
                    id = .asterisk_equal;
                    self.index += 1;
                    break;
                },
                else => {
                    id = .asterisk;
                    break;
                },
            },
            .plus => switch (c) {
                '=' => {
                    id = .plus_equal;
                    self.index += 1;
                    break;
                },
                '+' => {
                    id = .plus_plus;
                    self.index += 1;
                    break;
                },
                else => {
                    id = .plus;
                    break;
                },
            },
            .angle_bracket_left => switch (c) {
                '<' => {
                    state = .angle_bracket_angle_bracket_left;
                },
                '=' => {
                    id = .angle_bracket_left_equal;
                    self.index += 1;
                    break;
                },
                else => {
                    id = .angle_bracket_left;
                    break;
                },
            },
            .angle_bracket_angle_bracket_left => switch (c) {
                '=' => {
                    id = .angle_bracket_angle_bracket_left_equal;
                    self.index += 1;
                    break;
                },
                else => {
                    id = .angle_bracket_angle_bracket_left;
                    break;
                },
            },
            .angle_bracket_right => switch (c) {
                '>' => {
                    state = .angle_bracket_angle_bracket_right;
                },
                '=' => {
                    id = .angle_bracket_right_equal;
                    self.index += 1;
                    break;
                },
                else => {
                    id = .angle_bracket_right;
                    break;
                },
            },
            .angle_bracket_angle_bracket_right => switch (c) {
                '=' => {
                    id = .angle_bracket_angle_bracket_right_equal;
                    self.index += 1;
                    break;
                },
                else => {
                    id = .angle_bracket_angle_bracket_right;
                    break;
                },
            },
            .caret => switch (c) {
                '=' => {
                    id = .caret_equal;
                    self.index += 1;
                    break;
                },
                else => {
                    id = .caret;
                    break;
                },
            },
            .period => switch (c) {
                '.' => {
                    state = .period2;
                },
                '0'...'9' => {
                    state = .float_fraction;
                },
                else => {
                    id = .period;
                    break;
                },
            },
            .period2 => switch (c) {
                '.' => {
                    id = .ellipsis;
                    self.index += 1;
                    break;
                },
                else => {
                    id = .period;
                    self.index -= 1;
                    break;
                },
            },
            .minus => switch (c) {
                '>' => {
                    id = .arrow;
                    self.index += 1;
                    break;
                },
                '=' => {
                    id = .minus_equal;
                    self.index += 1;
                    break;
                },
                '-' => {
                    id = .minus_minus;
                    self.index += 1;
                    break;
                },
                else => {
                    id = .minus;
                    break;
                },
            },
            .ampersand => switch (c) {
                '&' => {
                    id = .ampersand_ampersand;
                    self.index += 1;
                    break;
                },
                '=' => {
                    id = .ampersand_equal;
                    self.index += 1;
                    break;
                },
                else => {
                    id = .ampersand;
                    break;
                },
            },
            .hash => switch (c) {
                '#' => {
                    id = .hash_hash;
                    self.index += 1;
                    break;
                },
                else => {
                    id = .hash;
                    break;
                },
            },
            .slash => switch (c) {
                '/' => {
                    state = .line_comment;
                },
                '*' => {
                    state = .multi_line_comment;
                },
                '=' => {
                    id = .slash_equal;
                    self.index += 1;
                    break;
                },
                else => {
                    id = .slash;
                    break;
                },
            },
            .line_comment => switch (c) {
                '\n' => {
                    self.index -= 1;
                    state = .start;
                },
                else => {},
            },
            .multi_line_comment => switch (c) {
                '*' => state = .multi_line_comment_asterisk,
                else => {},
            },
            .multi_line_comment_asterisk => switch (c) {
                '/' => state = .start,
                else => state = .multi_line_comment,
            },
            .zero => switch (c) {
                '0'...'9' => state = .integer_literal_oct,
                'b', 'B' => state = .integer_literal_binary,
                'x', 'X' => state = .integer_literal_hex,
                '.' => state = .float_fraction,
                else => {
                    state = .integer_suffix;
                    self.index -= 1;
                },
            },
            .integer_literal_oct => switch (c) {
                '0'...'7' => {},
                else => {
                    state = .integer_suffix;
                    self.index -= 1;
                },
            },
            .integer_literal_binary => switch (c) {
                '0', '1' => {},
                else => {
                    state = .integer_suffix;
                    self.index -= 1;
                },
            },
            .integer_literal_hex => switch (c) {
                '0'...'9', 'a'...'f', 'A'...'F' => {},
                '.' => state = .float_fraction_hex,
                'p', 'P' => state = .float_exponent,
                else => {
                    state = .integer_suffix;
                    self.index -= 1;
                },
            },
            .integer_literal => switch (c) {
                '0'...'9' => {},
                '.' => state = .float_fraction,
                'e', 'E' => state = .float_exponent,
                else => {
                    state = .integer_suffix;
                    self.index -= 1;
                },
            },
            .integer_suffix => switch (c) {
                'u', 'U' => state = .integer_suffix_u,
                'l', 'L' => state = .integer_suffix_l,
                else => {
                    id = .integer_literal;
                    break;
                },
            },
            .integer_suffix_u => switch (c) {
                'l', 'L' => state = .integer_suffix_ul,
                else => {
                    id = .integer_literal_u;
                    break;
                },
            },
            .integer_suffix_l => switch (c) {
                'l', 'L' => state = .integer_suffix_ll,
                'u', 'U' => {
                    id = .integer_literal_lu;
                    self.index += 1;
                    break;
                },
                else => {
                    id = .integer_literal_l;
                    break;
                },
            },
            .integer_suffix_ll => switch (c) {
                'u', 'U' => {
                    id = .integer_literal_llu;
                    self.index += 1;
                    break;
                },
                else => {
                    id = .integer_literal_ll;
                    break;
                },
            },
            .integer_suffix_ul => switch (c) {
                'l', 'L' => {
                    id = .integer_literal_llu;
                    self.index += 1;
                    break;
                },
                else => {
                    id = .integer_literal_lu;
                    break;
                },
            },
            .float_fraction => switch (c) {
                '0'...'9' => {},
                'e', 'E' => state = .float_exponent,
                else => {
                    self.index -= 1;
                    state = .float_suffix;
                },
            },
            .float_fraction_hex => switch (c) {
                '0'...'9', 'a'...'f', 'A'...'F' => {},
                'p', 'P' => state = .float_exponent,
                else => {
                    id = .invalid;
                    break;
                },
            },
            .float_exponent => switch (c) {
                '+', '-' => state = .float_exponent_digits,
                else => {
                    self.index -= 1;
                    state = .float_exponent_digits;
                },
            },
            .float_exponent_digits => switch (c) {
                '0'...'9' => counter += 1,
                else => {
                    if (counter == 0) {
                        id = .invalid;
                        break;
                    }
                    self.index -= 1;
                    state = .float_suffix;
                },
            },
            .float_suffix => switch (c) {
                'l', 'L' => {
                    id = .float_literal_l;
                    self.index += 1;
                    break;
                },
                'f', 'F' => {
                    id = .float_literal_f;
                    self.index += 1;
                    break;
                },
                else => {
                    id = .float_literal;
                    break;
                },
            },
        }
    } else if (self.index == self.buf.len) {
        switch (state) {
            .start, .line_comment => {},
            .u, .u8, .U, .L, .identifier => {
                id = Token.keywords.get(self.buf[start..self.index]) orelse .identifier;
            },
            .cr,
            .back_slash,
            .back_slash_cr,
            .period2,
            .string_literal,
            .char_literal_start,
            .char_literal,
            .escape_sequence,
            .cr_escape,
            .octal_escape,
            .hex_escape,
            .unicode_escape,
            .multi_line_comment,
            .multi_line_comment_asterisk,
            .float_exponent,
            => id = .invalid,

            .float_exponent_digits => id = if (counter == 0) .invalid else .float_literal,
            .float_fraction,
            .float_fraction_hex,
            => id = .float_literal,
            .integer_literal_oct,
            .integer_literal_binary,
            .integer_literal_hex,
            .integer_literal,
            .integer_suffix,
            .zero,
            => id = .integer_literal,
            .integer_suffix_u => id = .integer_literal_u,
            .integer_suffix_l => id = .integer_literal_l,
            .integer_suffix_ll => id = .integer_literal_ll,
            .integer_suffix_ul => id = .integer_literal_lu,

            .float_suffix => id = .float_literal,
            .equal => id = .equal,
            .bang => id = .bang,
            .minus => id = .minus,
            .slash => id = .slash,
            .ampersand => id = .ampersand,
            .hash => id = .hash,
            .period => id = .period,
            .pipe => id = .pipe,
            .angle_bracket_angle_bracket_right => id = .angle_bracket_angle_bracket_right,
            .angle_bracket_right => id = .angle_bracket_right,
            .angle_bracket_angle_bracket_left => id = .angle_bracket_angle_bracket_left,
            .angle_bracket_left => id = .angle_bracket_left,
            .plus => id = .plus,
            .percent => id = .percent,
            .caret => id = .caret,
            .asterisk => id = .asterisk,
        }
    }

    return .{
        .id = id,
        .loc = .{
            .start = start,
            .end = self.index,
        },
        .source = self.source.id,
    };
}

test "operators" {
    expectTokens(
        \\ ! != | || |= = ==
        \\ ( ) { } [ ] . .. ...
        \\ ^ ^= + ++ += - -- -=
        \\ * *= % %= -> : ; / /=
        \\ , & && &= ? < <= <<
        \\  <<= > >= >> >>= ~ # ##
        \\
    , &.{
        .bang,
        .bang_equal,
        .pipe,
        .pipe_pipe,
        .pipe_equal,
        .equal,
        .equal_equal,
        .nl,
        .l_paren,
        .r_paren,
        .l_brace,
        .r_brace,
        .l_bracket,
        .r_bracket,
        .period,
        .period,
        .period,
        .ellipsis,
        .nl,
        .caret,
        .caret_equal,
        .plus,
        .plus_plus,
        .plus_equal,
        .minus,
        .minus_minus,
        .minus_equal,
        .nl,
        .asterisk,
        .asterisk_equal,
        .percent,
        .percent_equal,
        .arrow,
        .colon,
        .semicolon,
        .slash,
        .slash_equal,
        .nl,
        .comma,
        .ampersand,
        .ampersand_ampersand,
        .ampersand_equal,
        .question_mark,
        .angle_bracket_left,
        .angle_bracket_left_equal,
        .angle_bracket_angle_bracket_left,
        .nl,
        .angle_bracket_angle_bracket_left_equal,
        .angle_bracket_right,
        .angle_bracket_right_equal,
        .angle_bracket_angle_bracket_right,
        .angle_bracket_angle_bracket_right_equal,
        .tilde,
        .hash,
        .hash_hash,
        .nl,
    });
}

test "keywords" {
    expectTokens(
        \\auto break case char const continue default do 
        \\double else enum extern float for goto if int 
        \\long register return short signed sizeof static 
        \\struct switch typedef union unsigned void volatile 
        \\while _Bool _Complex _Imaginary inline restrict _Alignas 
        \\_Alignof _Atomic _Generic _Noreturn _Static_assert _Thread_local 
        \\
    , &.{
        .keyword_auto,
        .keyword_break,
        .keyword_case,
        .keyword_char,
        .keyword_const,
        .keyword_continue,
        .keyword_default,
        .keyword_do,
        .nl,
        .keyword_double,
        .keyword_else,
        .keyword_enum,
        .keyword_extern,
        .keyword_float,
        .keyword_for,
        .keyword_goto,
        .keyword_if,
        .keyword_int,
        .nl,
        .keyword_long,
        .keyword_register,
        .keyword_return,
        .keyword_short,
        .keyword_signed,
        .keyword_sizeof,
        .keyword_static,
        .nl,
        .keyword_struct,
        .keyword_switch,
        .keyword_typedef,
        .keyword_union,
        .keyword_unsigned,
        .keyword_void,
        .keyword_volatile,
        .nl,
        .keyword_while,
        .keyword_bool,
        .keyword_complex,
        .keyword_imaginary,
        .keyword_inline,
        .keyword_restrict,
        .keyword_alignas,
        .nl,
        .keyword_alignof,
        .keyword_atomic,
        .keyword_generic,
        .keyword_noreturn,
        .keyword_static_assert,
        .keyword_thread_local,
        .nl,
    });
}

test "preprocessor keywords" {
    expectTokens(
        \\#include
        \\#define
        \\#ifdef
        \\#ifndef
        \\#error
        \\#pragma
        \\
    , &.{
        .hash,
        .keyword_include,
        .nl,
        .hash,
        .keyword_define,
        .nl,
        .hash,
        .keyword_ifdef,
        .nl,
        .hash,
        .keyword_ifndef,
        .nl,
        .hash,
        .keyword_error,
        .nl,
        .hash,
        .keyword_pragma,
        .nl,
    });
}

test "line continuation" {
    expectTokens(
        \\#define foo \
        \\  bar
        \\"foo\
        \\ bar"
        \\#define "foo"
        \\ "bar"
        \\#define "foo" \
        \\ "bar"
    , &.{
        .hash,
        .keyword_define,
        .identifier,
        .identifier,
        .nl,
        .string_literal,
        .nl,
        .hash,
        .keyword_define,
        .string_literal,
        .nl,
        .string_literal,
        .nl,
        .hash,
        .keyword_define,
        .string_literal,
        .string_literal,
    });
}

test "string prefix" {
    expectTokens(
        \\"foo"
        \\u"foo"
        \\u8"foo"
        \\U"foo"
        \\L"foo"
        \\'foo'
        \\u'foo'
        \\U'foo'
        \\L'foo'
        \\
    , &.{
        .string_literal,
        .nl,
        .string_literal_utf_16,
        .nl,
        .string_literal_utf_8,
        .nl,
        .string_literal_utf_32,
        .nl,
        .string_literal_wide,
        .nl,
        .char_literal,
        .nl,
        .char_literal_utf_16,
        .nl,
        .char_literal_utf_32,
        .nl,
        .char_literal_wide,
        .nl,
    });
}

test "num suffixes" {
    expectTokens(
        \\ 1.0f 1.0L 1.0 .0 1.
        \\ 0l 0lu 0ll 0llu 0
        \\ 1u 1ul 1ull 1
        \\
    , &.{
        .float_literal_f,
        .float_literal_l,
        .float_literal,
        .float_literal,
        .float_literal,
        .nl,
        .integer_literal_l,
        .integer_literal_lu,
        .integer_literal_ll,
        .integer_literal_llu,
        .integer_literal,
        .nl,
        .integer_literal_u,
        .integer_literal_lu,
        .integer_literal_llu,
        .integer_literal,
        .nl,
    });
}

test "comments" {
    expectTokens(
        \\//foo
        \\#foo
    , &.{
        .nl,
        .hash,
        .identifier,
    });
}

fn expectTokens(source: []const u8, expected_tokens: []const Token.Id) void {
    var tokenizer = Tokenizer{
        .buf = source,
        .source = undefined,
    };
    for (expected_tokens) |expected_token_id| {
        const token = tokenizer.next();
        if (!std.meta.eql(token.id, expected_token_id)) {
            std.debug.panic("expected {s}, found {s}\n", .{ @tagName(expected_token_id), @tagName(token.id) });
        }
    }
    const last_token = tokenizer.next();
    std.testing.expect(last_token.id == .eof);
}
