const std = @import("std");
const mem = std.mem;
const Allocator = mem.Allocator;
const Source = @import("Source.zig");
const Compilation = @import("Compilation.zig");
const Tree = @import("Tree.zig");

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
        actual_codepoint: u21,
        unsigned: u64,
        signed: i64,
        none: void,
    };
};

pub const Tag = blk: {
    const decls = @typeInfo(messages).Struct.decls;
    var enum_fields: [decls.len]std.builtin.TypeInfo.EnumField = undefined;
    inline for (decls) |decl, i| {
        enum_fields[i] = .{
            .name = decl.name,
            .value = i,
        };
    }
    break :blk @Type(.{
        .Enum = .{
            .layout = .Auto,
            .tag_type = std.math.IntFittingRange(0, decls.len - 1),
            .fields = &enum_fields,
            .decls = &.{},
            .is_exhaustive = true,
        },
    });
};

pub const Kind = enum { @"fatal error", @"error", note, warning, off };

pub const Options = struct {
    @"unsupported-pragma": ?Kind = null,
    @"c99-extensions": ?Kind = null,
    @"implicit-int": ?Kind = null,
    @"duplicate-decl-specifier": ?Kind = null,
    @"missing-declaration": ?Kind = null,
    @"extern-initializer": ?Kind = null,
    @"implicit-function-declaration": ?Kind = null,
    @"unused-value": ?Kind = null,
    @"unreachable-code": ?Kind = null,
    @"unknown-warning-option": ?Kind = null,
    @"empty-struct": ?Kind = null,
    @"gnu-alignof-expression": ?Kind = null,
    @"macro-redefined": ?Kind = null,
    @"generic-qual-type": ?Kind = null,
    multichar: ?Kind = null,
    @"pointer-integer-compare": ?Kind = null,
    @"compare-distinct-pointer-types": ?Kind = null,
    @"literal-conversion": ?Kind = null,
    @"cast-qualifiers": ?Kind = null,
    @"array-bounds": ?Kind = null,
    @"int-conversion": ?Kind = null,
    @"pointer-type-mismatch": ?Kind = null,
    @"c2x-extensions": ?Kind = null,
    @"incompatible-pointer-types": ?Kind = null,
    @"excess-initializers": ?Kind = null,
    @"division-by-zero": ?Kind = null,
    @"initializer-overrides": ?Kind = null,
    @"incompatible-pointer-types-discards-qualifiers": ?Kind = null,
    @"unknown-attributes": ?Kind = null,
    @"ignored-attributes": ?Kind = null,
    @"builtin-macro-redefined": ?Kind = null,
    @"gnu-label-as-value": ?Kind = null,
    @"malformed-warning-check": ?Kind = null,
    @"#pragma-messages": ?Kind = null,
    @"newline-eof": ?Kind = null,
    @"empty-translation-unit": ?Kind = null,
    @"implicitly-unsigned-literal": ?Kind = null,
    @"c99-compat": ?Kind = null,
    @"unicode-zero-width": ?Kind = null,
    @"unicode-homoglyph": ?Kind = null,
    @"return-type": ?Kind = null,
    @"dollar-in-identifier-extension": ?Kind = null,
    @"unknown-pragmas": ?Kind = null,
    @"predefined-identifier-outside-function": ?Kind = null,
};

const messages = struct {
    const todo = struct { // Maybe someday this will no longer be needed.
        const msg = "TODO: {s}";
        const extra = .str;
        const kind = .@"error";
    };
    const error_directive = struct {
        const msg = "{s}";
        const extra = .str;
        const kind = .@"error";
    };
    const elif_without_if = struct {
        const msg = "#elif without #if";
        const kind = .@"error";
    };
    const elif_after_else = struct {
        const msg = "#elif after #else";
        const kind = .@"error";
    };
    const else_without_if = struct {
        const msg = "#else without #if";
        const kind = .@"error";
    };
    const else_after_else = struct {
        const msg = "#else after #else";
        const kind = .@"error";
    };
    const endif_without_if = struct {
        const msg = "#endif without #if";
        const kind = .@"error";
    };
    const unsupported_pragma = struct {
        const msg = "unsupported #pragma directive '{s}'";
        const extra = .str;
        const opt = "unsupported-pragma";
        const kind = .warning;
    };
    const line_simple_digit = struct {
        const msg = "#line directive requires a simple digit sequence";
        const kind = .@"error";
    };
    const line_invalid_filename = struct {
        const msg = "invalid filename for #line directive";
        const kind = .@"error";
    };
    const unterminated_conditional_directive = struct {
        const msg = "unterminated conditional directive";
        const kind = .@"error";
    };
    const invalid_preprocessing_directive = struct {
        const msg = "invalid preprocessing directive";
        const kind = .@"error";
    };
    const macro_name_missing = struct {
        const msg = "macro name missing";
        const kind = .@"error";
    };
    const extra_tokens_directive_end = struct {
        const msg = "extra tokens at end of macro directive";
        const kind = .@"error";
    };
    const expected_value_in_expr = struct {
        const msg = "expected value in expression";
        const kind = .@"error";
    };
    const closing_paren = struct {
        const msg = "expected closing ')'";
        const kind = .@"error";
    };
    const to_match_paren = struct {
        const msg = "to match this '('";
        const kind = .note;
    };
    const to_match_brace = struct {
        const msg = "to match this '{'";
        const kind = .note;
    };
    const to_match_bracket = struct {
        const msg = "to match this '['";
        const kind = .note;
    };
    const header_str_closing = struct {
        const msg = "expected closing '>'";
        const kind = .@"error";
    };
    const header_str_match = struct {
        const msg = "to match this '<'";
        const kind = .note;
    };
    const string_literal_in_pp_expr = struct {
        const msg = "string literal in preprocessor expression";
        const kind = .@"error";
    };
    const float_literal_in_pp_expr = struct {
        const msg = "floating point literal in preprocessor expression";
        const kind = .@"error";
    };
    const defined_as_macro_name = struct {
        const msg = "'defined' cannot be used as a macro name";
        const kind = .@"error";
    };
    const macro_name_must_be_identifier = struct {
        const msg = "macro name must be an identifier";
        const kind = .@"error";
    };
    const whitespace_after_macro_name = struct {
        const msg = "ISO C99 requires whitespace after the macro name";
        const opt = "c99-extensions";
        const kind = .warning;
    };
    const hash_hash_at_start = struct {
        const msg = "'##' cannot appear at the start of a macro expansion";
        const kind = .@"error";
    };
    const hash_hash_at_end = struct {
        const msg = "'##' cannot appear at the end of a macro expansion";
        const kind = .@"error";
    };
    const pasting_formed_invalid = struct {
        const msg = "pasting formed '{s}', an invalid preprocessing token";
        const extra = .str;
        const kind = .@"error";
    };
    const missing_paren_param_list = struct {
        const msg = "missing ')' in macro parameter list";
        const kind = .@"error";
    };
    const unterminated_macro_param_list = struct {
        const msg = "unterminated macro param list";
        const kind = .@"error";
    };
    const invalid_token_param_list = struct {
        const msg = "invalid token in macro parameter list";
        const kind = .@"error";
    };
    const hash_not_followed_param = struct {
        const msg = "'#' is not followed by a macro parameter";
        const kind = .@"error";
    };
    const expected_filename = struct {
        const msg = "expected \"FILENAME\" or <FILENAME>";
        const kind = .@"error";
    };
    const empty_filename = struct {
        const msg = "empty filename";
        const kind = .@"error";
    };
    const expected_invalid = struct {
        const msg = "expected '{s}', found invalid bytes";
        const extra = .tok_id_expected;
        const kind = .@"error";
    };
    const expected_token = struct {
        const msg = "expected '{s}', found '{s}'";
        const extra = .tok_id;
        const kind = .@"error";
    };
    const expected_expr = struct {
        const msg = "expected expression";
        const kind = .@"error";
    };
    const expected_integer_constant_expr = struct {
        const msg = "expression is not an integer constant expression";
        const kind = .@"error";
    };
    const missing_type_specifier = struct {
        const msg = "type specifier missing, defaults to 'int'";
        const opt = "implicit-int";
        const kind = .warning;
    };
    const multiple_storage_class = struct {
        const msg = "cannot combine with previous '{s}' declaration specifier";
        const extra = .str;
        const kind = .@"error";
    };
    const static_assert_failure = struct {
        const msg = "static assertion failed";
        const kind = .@"error";
    };
    const static_assert_failure_message = struct {
        const msg = "static assertion failed {s}";
        const extra = .str;
        const kind = .@"error";
    };
    const expected_type = struct {
        const msg = "expected a type";
        const kind = .@"error";
    };
    const cannot_combine_spec = struct {
        const msg = "cannot combine with previous '{s}' specifier";
        const extra = .str;
        const kind = .@"error";
    };
    const duplicate_decl_spec = struct {
        const msg = "duplicate '{s}' declaration specifier";
        const extra = .str;
        const opt = "duplicate-decl-specifier";
        const kind = .warning;
    };
    const restrict_non_pointer = struct {
        const msg = "restrict requires a pointer or reference ('{s}' is invalid)";
        const extra = .str;
        const kind = .@"error";
    };
    const expected_external_decl = struct {
        const msg = "expected external declaration";
        const kind = .@"error";
    };
    const expected_ident_or_l_paren = struct {
        const msg = "expected identifier or '('";
        const kind = .@"error";
    };
    const missing_declaration = struct {
        const msg = "declaration does not declare anything";
        const opt = "missing-declaration";
        const kind = .warning;
    };
    const func_not_in_root = struct {
        const msg = "function definition is not allowed here";
        const kind = .@"error";
    };
    const illegal_initializer = struct {
        const msg = "illegal initializer (only variables can be initialized)";
        const kind = .@"error";
    };
    const extern_initializer = struct {
        const msg = "extern variable has initializer";
        const opt = "extern-initializer";
        const kind = .warning;
    };
    const spec_from_typedef = struct {
        const msg = "'{s}' came from typedef";
        const extra = .str;
        const kind = .note;
    };
    const type_is_invalid = struct {
        const msg = "'{s}' is invalid";
        const extra = .str;
        const kind = .@"error";
    };
    const param_before_var_args = struct {
        const msg = "ISO C requires a named parameter before '...'";
        const kind = .@"error";
    };
    const void_only_param = struct {
        const msg = "'void' must be the only parameter if specified";
        const kind = .@"error";
    };
    const void_param_qualified = struct {
        const msg = "'void' parameter cannot be qualified";
        const kind = .@"error";
    };
    const void_must_be_first_param = struct {
        const msg = "'void' must be the first parameter if specified";
        const kind = .@"error";
    };
    const invalid_storage_on_param = struct {
        const msg = "invalid storage class on function parameter";
        const kind = .@"error";
    };
    const threadlocal_non_var = struct {
        const msg = "_Thread_local only allowed on variables";
        const kind = .@"error";
    };
    const func_spec_non_func = struct {
        const msg = "'{s}' can only appear on functions";
        const extra = .str;
        const kind = .@"error";
    };
    const illegal_storage_on_func = struct {
        const msg = "illegal storage class on function";
        const kind = .@"error";
    };
    const illegal_storage_on_global = struct {
        const msg = "illegal storage class on global variable";
        const kind = .@"error";
    };
    const expected_stmt = struct {
        const msg = "expected statement";
        const kind = .@"error";
    };
    const func_cannot_return_func = struct {
        const msg = "function cannot return a function";
        const kind = .@"error";
    };
    const func_cannot_return_array = struct {
        const msg = "function cannot return an array";
        const kind = .@"error";
    };
    const undeclared_identifier = struct {
        const msg = "use of undeclared identifier '{s}'";
        const extra = .str;
        const kind = .@"error";
    };
    const not_callable = struct {
        const msg = "cannot call non function type '{s}'";
        const extra = .str;
        const kind = .@"error";
    };
    const unsupported_str_cat = struct {
        const msg = "unsupported string literal concatenation";
        const kind = .@"error";
    };
    const static_func_not_global = struct {
        const msg = "static functions must be global";
        const kind = .@"error";
    };
    const implicit_func_decl = struct {
        const msg = "implicit declaration of function '{s}' is invalid in C99";
        const extra = .str;
        const opt = "implicit-function-declaration";
        const kind = .warning;
    };
    const expected_param_decl = struct {
        const msg = "expected parameter declaration";
        const kind = .@"error";
    };
    const invalid_old_style_params = struct {
        const msg = "identifier parameter lists are only allowed in function definitions";
        const kind = .warning;
    };
    const expected_fn_body = struct {
        const msg = "expected function body after function declaration";
        const kind = .@"error";
    };
    const invalid_void_param = struct {
        const msg = "parameter cannot have void type";
        const kind = .@"error";
    };
    const unused_value = struct {
        const msg = "expression result unused";
        const opt = "unused-value";
        const kind = .warning;
    };
    const continue_not_in_loop = struct {
        const msg = "'continue' statement not in a loop";
        const kind = .@"error";
    };
    const break_not_in_loop_or_switch = struct {
        const msg = "'break' statement not in a loop or a switch";
        const kind = .@"error";
    };
    const unreachable_code = struct {
        const msg = "unreachable code";
        const opt = "unreachable-code";
        const kind = .warning;
    };
    const duplicate_label = struct {
        const msg = "duplicate label '{s}'";
        const extra = .str;
        const kind = .@"error";
    };
    const previous_label = struct {
        const msg = "previous definition of label '{s}' was here";
        const extra = .str;
        const kind = .note;
    };
    const undeclared_label = struct {
        const msg = "use of undeclared label '{s}'";
        const extra = .str;
        const kind = .@"error";
    };
    const case_not_in_switch = struct {
        const msg = "'{s}' statement not in a switch statement";
        const extra = .str;
        const kind = .@"error";
    };
    const duplicate_switch_case_signed = struct {
        const msg = "duplicate case value '{d}'";
        const extra = .signed;
        const kind = .@"error";
    };
    const duplicate_switch_case_unsigned = struct {
        const msg = "duplicate case value '{d}'";
        const extra = .unsigned;
        const kind = .@"error";
    };
    const multiple_default = struct {
        const msg = "multiple default cases in the same switch";
        const kind = .@"error";
    };
    const previous_case = struct {
        const msg = "previous case defined here";
        const kind = .note;
    };
    const expected_arguments = struct {
        const msg = "expected {d} argument(s) got {d}";
        const extra = .arguments;
        const kind = .@"error";
    };
    const expected_arguments_old = struct {
        const msg = expected_arguments.msg;
        const extra = .arguments;
        const kind = .warning;
    };
    const expected_at_least_arguments = struct {
        const msg = "expected at least {d} argument(s) got {d}";
        const extra = .arguments;
        const kind = .warning;
    };
    const invalid_static_star = struct {
        const msg = "'static' may not be used with an unspecified variable length array size";
        const kind = .@"error";
    };
    const static_non_param = struct {
        const msg = "'static' used outside of function parameters";
        const kind = .@"error";
    };
    const array_qualifiers = struct {
        const msg = "type qualifier in non parameter array type";
        const kind = .@"error";
    };
    const star_non_param = struct {
        const msg = "star modifier used outside of function parameters";
        const kind = .@"error";
    };
    const variable_len_array_file_scope = struct {
        const msg = "variable length arrays not allowed at file scope";
        const kind = .@"error";
    };
    const useless_static = struct {
        const msg = "'static' useless without a constant size";
        const kind = .warning;
    };
    const negative_array_size = struct {
        const msg = "array size must be 0 or greater";
        const kind = .@"error";
    };
    const array_incomplete_elem = struct {
        const msg = "array has incomplete element type '{s}'";
        const extra = .str;
        const kind = .@"error";
    };
    const array_func_elem = struct {
        const msg = "arrays cannot have functions as their element type";
        const kind = .@"error";
    };
    const static_non_outermost_array = struct {
        const msg = "'static' used in non-outermost array type";
        const kind = .@"error";
    };
    const qualifier_non_outermost_array = struct {
        const msg = "type qualifier used in non-outermost array type";
        const kind = .@"error";
    };
    const unterminated_macro_arg_list = struct {
        const msg = "unterminated function macro argument list";
        const kind = .@"error";
    };
    const unknown_warning = struct {
        const msg = "unknown warning '{s}'";
        const extra = .str;
        const opt = "unknown-warning-option";
        const kind = .warning;
    };
    const overflow_signed = struct {
        const msg = "overflow in expression; result is '{d}'";
        const extra = .signed;
        const kind = .@"error";
    };
    const overflow_unsigned = struct {
        const msg = overflow_signed.msg;
        const extra = .unsigned;
        const kind = .warning;
    };
    const int_literal_too_big = struct {
        const msg = "integer literal is too large to be represented in any integer type";
        const kind = .@"error";
    };
    const indirection_ptr = struct {
        const msg = "indirection requires pointer operand";
        const kind = .@"error";
    };
    const addr_of_rvalue = struct {
        const msg = "cannot take the address of an rvalue";
        const kind = .@"error";
    };
    const not_assignable = struct {
        const msg = "expression is not assignable";
        const kind = .@"error";
    };
    const ident_or_l_brace = struct {
        const msg = "expected identifier or '{'";
        const kind = .@"error";
    };
    const empty_enum = struct {
        const msg = "empty enum is invalid";
        const kind = .@"error";
    };
    const redefinition = struct {
        const msg = "redefinition of '{s}'";
        const extra = .str;
        const kind = .@"error";
    };
    const previous_definition = struct {
        const msg = "previous definition is here";
        const kind = .note;
    };
    const expected_identifier = struct {
        const msg = "expected identifier";
        const kind = .@"error";
    };
    const expected_str_literal = struct {
        const msg = "expected string literal for diagnostic message in static_assert";
        const kind = .@"error";
    };
    const expected_str_literal_in = struct {
        const msg = "expected string literal in '{s}'";
        const extra = .str;
        const kind = .@"error";
    };
    const parameter_missing = struct {
        const msg = "parameter named '{s}' is missing";
        const extra = .str;
        const kind = .@"error";
    };
    const empty_record = struct {
        const msg = "empty {s} is a GNU extension";
        const extra = .str;
        const opt = "empty-struct";
        const kind = .off;
    };
    const wrong_tag = struct {
        const msg = "use of '{s}' with tag type that does not match previous definition";
        const extra = .str;
        const kind = .@"error";
    };
    const expected_parens_around_typename = struct {
        const msg = "expected parentheses around type name";
        const kind = .@"error";
    };
    const alignof_expr = struct {
        const msg = "'_Alignof' applied to an expression is a GNU extension";
        const opt = "gnu-alignof-expression";
        const kind = .warning;
        const suppress_gnu = true;
    };
    const invalid_sizeof = struct {
        const msg = "invalid application of 'sizeof' to an incomplete type '{s}'";
        const extra = .str;
        const kind = .@"error";
    };
    const macro_redefined = struct {
        const msg = "'{s}' macro redefined";
        const extra = .str;
        const opt = "macro-redefined";
        const kind = .warning;
    };
    const generic_qual_type = struct {
        const msg = "generic association with qualifiers cannot be matched with";
        const opt = "generic-qual-type";
        const kind = .warning;
    };
    const generic_duplicate = struct {
        const msg = "type '{s}' in generic association compatible with previously specified type";
        const extra = .str;
        const kind = .@"error";
    };
    const generic_duplicate_default = struct {
        const msg = "duplicate default generic association";
        const kind = .@"error";
    };
    const generic_no_match = struct {
        const msg = "controlling expression type '{s}' not compatible with any generic association type";
        const extra = .str;
        const kind = .@"error";
    };
    const escape_sequence_overflow = struct {
        const msg = "escape sequence out of range";
        const kind = .@"error";
    };
    const invalid_universal_character = struct {
        const msg = "invalid universal character";
        const kind = .@"error";
    };
    const multichar_literal = struct {
        const msg = "multi-character character constant";
        const opt = "multichar";
        const kind = .warning;
    };
    const unicode_multichar_literal = struct {
        const msg = "Unicode character literals may not contain multiple characters";
        const kind = .@"error";
    };
    const wide_multichar_literal = struct {
        const msg = "extraneous characters in character constant ignored";
        const kind = .warning;
    };
    const char_lit_too_wide = struct {
        const msg = "character constant too long for its type";
        const kind = .warning;
    };
    const char_too_large = struct {
        const msg = "character too large for enclosing character literal type";
        const kind = .@"error";
    };
    const must_use_struct = struct {
        const msg = "must use 'struct' tag to refer to type '{s}'";
        const extra = .str;
        const kind = .@"error";
    };
    const must_use_union = struct {
        const msg = "must use 'union' tag to refer to type '{s}'";
        const extra = .str;
        const kind = .@"error";
    };
    const must_use_enum = struct {
        const msg = "must use 'enum' tag to refer to type '{s}'";
        const extra = .str;
        const kind = .@"error";
    };
    const redefinition_different_sym = struct {
        const msg = "redefinition of '{s}' as different kind of symbol";
        const extra = .str;
        const kind = .@"error";
    };
    const redefinition_incompatible = struct {
        const msg = "redefinition of '{s}' with a different type";
        const extra = .str;
        const kind = .@"error";
    };
    const redefinition_of_parameter = struct {
        const msg = "redefinition of parameter '{s}'";
        const extra = .str;
        const kind = .@"error";
    };
    const invalid_bin_types = struct {
        const msg = "invalid operands to binary expression ({s})";
        const extra = .str;
        const kind = .@"error";
    };
    const comparison_ptr_int = struct {
        const msg = "comparison between pointer and integer ({s})";
        const extra = .str;
        const opt = "pointer-integer-compare";
        const kind = .warning;
    };
    const comparison_distinct_ptr = struct {
        const msg = "comparison of distinct pointer types ({s})";
        const extra = .str;
        const opt = "compare-distinct-pointer-types";
        const kind = .warning;
    };
    const incompatible_pointers = struct {
        const msg = "incompatible pointer types ({s})";
        const extra = .str;
        const kind = .@"error";
    };
    const invalid_argument_un = struct {
        const msg = "invalid argument type '{s}' to unary expression";
        const extra = .str;
        const kind = .@"error";
    };
    const incompatible_assign = struct {
        const msg = "assignment to {s}";
        const extra = .str;
        const kind = .@"error";
    };
    const implicit_ptr_to_int = struct {
        const msg = "implicit pointer to integer conversion from {s}";
        const extra = .str;
        const opt = "literal-conversion";
        const kind = .warning;
    };
    const invalid_cast_to_float = struct {
        const msg = "pointer cannot be cast to type '{s}'";
        const extra = .str;
        const kind = .@"error";
    };
    const invalid_cast_to_pointer = struct {
        const msg = "operand of type '{s}' cannot be cast to a pointer type";
        const extra = .str;
        const kind = .@"error";
    };
    const invalid_cast_type = struct {
        const msg = "cannot cast to non arithmetic or pointer type '{s}'";
        const extra = .str;
        const kind = .@"error";
    };
    const qual_cast = struct {
        const msg = "cast to type '{s}' will not preserve qualifiers";
        const extra = .str;
        const opt = "cast-qualifiers";
        const kind = .warning;
    };
    const invalid_index = struct {
        const msg = "array subscript is not an integer";
        const kind = .@"error";
    };
    const invalid_subscript = struct {
        const msg = "subscripted value is not an array or pointer";
        const kind = .@"error";
    };
    const array_after = struct {
        const msg = "array index {d} is past the end of the array";
        const extra = .unsigned;
        const opt = "array-bounds";
        const kind = .warning;
    };
    const array_before = struct {
        const msg = "array index {d} is before the beginning of the array";
        const extra = .signed;
        const opt = "array-bounds";
        const kind = .warning;
    };
    const statement_int = struct {
        const msg = "statement requires expression with integer type ('{s}' invalid)";
        const extra = .str;
        const kind = .@"error";
    };
    const statement_scalar = struct {
        const msg = "statement requires expression with scalar type ('{s}' invalid)";
        const extra = .str;
        const kind = .@"error";
    };
    const func_should_return = struct {
        const msg = "non-void function '{s}' should return a value";
        const extra = .str;
        const opt = "return-type";
        const kind = .@"error";
    };
    const incompatible_return = struct {
        const msg = "returning '{s}' from a function with incompatible result type";
        const extra = .str;
        const kind = .@"error";
    };
    const implicit_int_to_ptr = struct {
        const msg = "implicit integer to pointer conversion from {s}";
        const extra = .str;
        const opt = "int-conversion";
        const kind = .warning;
    };
    const func_does_not_return = struct {
        const msg = "non-void function '{s}' does not return a value";
        const extra = .str;
        const opt = "return-type";
        const kind = .warning;
    };
    const void_func_returns_value = struct {
        const msg = "void function '{s}' should not return a value";
        const extra = .str;
        const opt = "return-type";
        const kind = .@"error";
    };
    const incompatible_param = struct {
        const msg = "passing '{s}' to parameter of incompatible type";
        const extra = .str;
        const kind = .@"error";
    };
    const parameter_here = struct {
        const msg = "passing argument to parameter here";
        const kind = .note;
    };
    const atomic_array = struct {
        const msg = "atomic cannot be applied to array type '{s}'";
        const extra = .str;
        const kind = .@"error";
    };
    const atomic_func = struct {
        const msg = "atomic cannot be applied to function type '{s}'";
        const extra = .str;
        const kind = .@"error";
    };
    const atomic_incomplete = struct {
        const msg = "atomic cannot be applied to incomplete type '{s}'";
        const extra = .str;
        const kind = .@"error";
    };
    const addr_of_register = struct {
        const msg = "address of register variable requested";
        const kind = .@"error";
    };
    const variable_incomplete_ty = struct {
        const msg = "variable has incomplete type '{s}'";
        const extra = .str;
        const kind = .@"error";
    };
    const parameter_incomplete_ty = struct {
        const msg = "parameter has incomplete type '{s}'";
        const extra = .str;
        const kind = .@"error";
    };
    const deref_incomplete_ty_ptr = struct {
        const msg = "dereferencing pointer to incomplete type '{s}'";
        const extra = .str;
        const kind = .@"error";
    };
    const alignas_on_func = struct {
        const msg = "'_Alignas' attribute only applies to variables and fields";
        const kind = .@"error";
    };
    const alignas_on_param = struct {
        const msg = "'_Alignas' attribute cannot be applied to a function parameter";
        const kind = .@"error";
    };
    const minimum_alignment = struct {
        const msg = "requested alignment is less than minimum alignment of {d}";
        const extra = .unsigned;
        const kind = .@"error";
    };
    const maximum_alignment = struct {
        const msg = "requested alignment of {d} is too large";
        const extra = .unsigned;
        const kind = .@"error";
    };
    const negative_alignment = struct {
        const msg = "requested negative alignment of {d} is invalid";
        const extra = .signed;
        const kind = .@"error";
    };
    const align_ignored = struct {
        const msg = "'_Alignas' attribute is ignored here";
        const kind = .warning;
    };
    const zero_align_ignored = struct {
        const msg = "requested alignment of zero is ignored";
        const kind = .warning;
    };
    const non_pow2_align = struct {
        const msg = "requested alignment is not a power of 2";
        const kind = .@"error";
    };
    const pointer_mismatch = struct {
        const msg = "pointer type mismatch ({s})";
        const extra = .str;
        const opt = "pointer-type-mismatch";
        const kind = .warning;
    };
    const static_assert_not_constant = struct {
        const msg = "static_assert expression is not an integral constant expression";
        const kind = .@"error";
    };
    const static_assert_missing_message = struct {
        const msg = "static_assert with no message is a C2X extension";
        const opt = "c2x-extensions";
        const kind = .warning;
        const suppress_version = .c2x;
    };
    const unbound_vla = struct {
        const msg = "variable length array must be bound in function definition";
        const kind = .@"error";
    };
    const array_too_large = struct {
        const msg = "array is too large";
        const kind = .@"error";
    };
    const incompatible_ptr_init = struct {
        const msg = "incompatible pointer types initializing {s}";
        const extra = .str;
        const opt = "incompatible-pointer-types";
        const kind = .warning;
    };
    const incompatible_ptr_assign = struct {
        const msg = "incompatible pointer types assigning to {s}";
        const extra = .str;
        const opt = "incompatible-pointer-types";
        const kind = .warning;
    };
    const vla_init = struct {
        const msg = "variable-sized object may not be initialized";
        const kind = .@"error";
    };
    const func_init = struct {
        const msg = "illegal initializer type";
        const kind = .@"error";
    };
    const incompatible_init = struct {
        const msg = "initializing {s}";
        const extra = .str;
        const kind = .@"error";
    };
    const empty_scalar_init = struct {
        const msg = "scalar initializer cannot be empty";
        const kind = .@"error";
    };
    const excess_scalar_init = struct {
        const msg = "excess elements in scalar initializer";
        const opt = "excess-initializers";
        const kind = .warning;
    };
    const excess_str_init = struct {
        const msg = "excess elements in string initializer";
        const opt = "excess-initializers";
        const kind = .warning;
    };
    const excess_struct_init = struct {
        const msg = "excess elements in struct initializer";
        const opt = "excess-initializers";
        const kind = .warning;
    };
    const excess_array_init = struct {
        const msg = "excess elements in array initializer";
        const opt = "excess-initializers";
        const kind = .warning;
    };
    const str_init_too_long = struct {
        const msg = "initializer-string for char array is too long";
        const opt = "excess-initializers";
        const kind = .warning;
    };
    const arr_init_too_long = struct {
        const msg = "cannot initialize type ({s})";
        const extra = .str;
        const kind = .@"error";
    };
    const invalid_typeof = struct {
        const msg = "'{s} typeof' is invalid";
        const extra = .str;
        const kind = .@"error";
    };
    const division_by_zero = struct {
        const msg = "{s} by zero is undefined";
        const extra = .str;
        const opt = "division-by-zero";
        const kind = .warning;
    };
    const division_by_zero_macro = struct {
        const msg = "{s} by zero in preprocessor expression";
        const extra = .str;
        const kind = .@"error";
    };
    const builtin_choose_cond = struct {
        const msg = "'__builtin_choose_expr' requires a constant expression";
        const kind = .@"error";
    };
    const alignas_unavailable = struct {
        const msg = "'_Alignas' attribute requires integer constant expression";
        const kind = .@"error";
    };
    const case_val_unavailable = struct {
        const msg = "case value must be an integer constant expression";
        const kind = .@"error";
    };
    const enum_val_unavailable = struct {
        const msg = "enum value must be an integer constant expression";
        const kind = .@"error";
    };
    const incompatible_array_init = struct {
        const msg = "cannot initialize array of type {s}";
        const extra = .str;
        const kind = .@"error";
    };
    const array_init_str = struct {
        const msg = "array initializer must be an initializer list or wide string literal";
        const kind = .@"error";
    };
    const initializer_overrides = struct {
        const msg = "initializer overrides previous initialization";
        const opt = "initializer-overrides";
        const kind = .warning;
    };
    const previous_initializer = struct {
        const msg = "previous initialization";
        const kind = .note;
    };
    const invalid_array_designator = struct {
        const msg = "array designator used for non-array type '{s}'";
        const extra = .str;
        const kind = .@"error";
    };
    const negative_array_designator = struct {
        const msg = "array designator value {d} is negative";
        const extra = .signed;
        const kind = .@"error";
    };
    const oob_array_designator = struct {
        const msg = "array designator index {d} exceeds array bounds";
        const extra = .unsigned;
        const kind = .@"error";
    };
    const invalid_field_designator = struct {
        const msg = "field designator used for non-record type '{s}'";
        const extra = .str;
        const kind = .@"error";
    };
    const no_such_field_designator = struct {
        const msg = "record type has no field named '{s}'";
        const extra = .str;
        const kind = .@"error";
    };
    const empty_aggregate_init_braces = struct {
        const msg = "initializer for aggregate with no elements requires explicit braces";
        const kind = .@"error";
    };
    const ptr_init_discards_quals = struct {
        const msg = "initializing {s} discards qualifiers";
        const extra = .str;
        const opt = "incompatible-pointer-types-discards-qualifiers";
        const kind = .warning;
    };
    const ptr_assign_discards_quals = struct {
        const msg = "assigning to {s} discards qualifiers";
        const extra = .str;
        const opt = "incompatible-pointer-types-discards-qualifiers";
        const kind = .warning;
    };
    const unknown_attribute = struct {
        const msg = "unknown attribute '{s}' ignored";
        const extra = .str;
        const opt = "unknown-attributes";
        const kind = .warning;
    };
    const ignored_attribute = struct {
        const msg = "{s}";
        const extra = .str;
        const opt = "ignored-attributes";
        const kind = .warning;
    };
    const invalid_fallthrough = struct {
        const msg = "fallthrough annotation does not directly precede switch label";
        const kind = .@"error";
    };
    const cannot_apply_attribute_to_statement = struct {
        const msg = "attribute cannot be applied to a statement";
        const kind = .@"error";
    };
    const builtin_macro_redefined = struct {
        const msg = "redefining builtin macro";
        const opt = "builtin-macro-redefined";
        const kind = .warning;
    };
    const feature_check_requires_identifier = struct {
        const msg = "builtin feature check macro requires a parenthesized identifier";
        const kind = .@"error";
    };
    const missing_tok_builtin = struct {
        const msg = "missing '{s}', after builtin feature-check macro";
        const extra = .tok_id_expected;
        const kind = .@"error";
    };
    const gnu_label_as_value = struct {
        const msg = "use of GNU address-of-label extension";
        const opt = "gnu-label-as-value";
        const kind = .off;
    };
    const expected_record_ty = struct {
        const msg = "member reference base type '{s}' is not a structure or union";
        const extra = .str;
        const kind = .@"error";
    };
    const member_expr_not_ptr = struct {
        const msg = "member reference type '{s}' is not a pointer; did you mean to use '.'?";
        const extra = .str;
        const kind = .@"error";
    };
    const member_expr_ptr = struct {
        const msg = "member reference type '{s}' is a pointer; did you mean to use '->'?";
        const extra = .str;
        const kind = .@"error";
    };
    const no_such_member = struct {
        const msg = "no member named {s}";
        const extra = .str;
        const kind = .@"error";
    };
    const malformed_warning_check = struct {
        const msg = "{s} expected option name (e.g. \"-Wundef\")";
        const extra = .str;
        const opt = "malformed-warning-check";
        const kind = .warning;
    };
    const invalid_computed_goto = struct {
        const msg = "computed goto in function with no address-of-label expressions";
        const kind = .@"error";
    };
    const pragma_warning_message = struct {
        const msg = "{s}";
        const extra = .str;
        const opt = "#pragma-messages";
        const kind = .warning;
    };
    const pragma_error_message = struct {
        const msg = "{s}";
        const extra = .str;
        const kind = .@"error";
    };
    const pragma_message = struct {
        const msg = "#pragma message: {s}";
        const extra = .str;
        const kind = .note;
    };
    const pragma_requires_string_literal = struct {
        const msg = "pragma {s} requires string literal";
        const extra = .str;
        const kind = .@"error";
    };
    const poisoned_identifier = struct {
        const msg = "attempt to use a poisoned identifier";
        const kind = .@"error";
    };
    const pragma_poison_identifier = struct {
        const msg = "can only poison identifier tokens";
        const kind = .@"error";
    };
    const pragma_poison_macro = struct {
        const msg = "poisoning existing macro";
        const kind = .warning;
    };
    const newline_eof = struct {
        const msg = "no newline at end of file";
        const opt = "newline-eof";
        const kind = .off;
    };
    const empty_translation_unit = struct {
        const msg = "ISO C requires a translation unit to contain at least one declaration";
        const opt = "empty-translation-unit";
        const kind = .off;
    };
    const omitting_parameter_name = struct {
        const msg = "omitting the parameter name in a function definition is a C2x extension";
        const opt = "c2x-extensions";
        const kind = .warning;
        const suppress_version = .c2x;
    };
    const non_int_bitfield = struct {
        const msg = "bit-field has non-integer type '{s}'";
        const extra = .str;
        const kind = .@"error";
    };
    const negative_bitwidth = struct {
        const msg = "bit-field has negative width ({d})";
        const extra = .signed;
        const kind = .@"error";
    };
    const zero_width_named_field = struct {
        const msg = "named bit-field has zero width";
        const kind = .@"error";
    };
    const bitfield_too_big = struct {
        const msg = "width of bit-field exceeds width of its type";
        const kind = .@"error";
    };
    const invalid_utf8 = struct {
        const msg = "source file is not valid UTF-8";
        const kind = .@"error";
    };
    const implicitly_unsigned_literal = struct {
        const msg = "integer literal is too large to be represented in a signed integer type, interpreting as unsigned";
        const opt = "implicitly-unsigned-literal";
        const kind = .warning;
    };
    const invalid_preproc_operator = struct {
        const msg = "token is not a valid binary operator in a preprocessor subexpression";
        const kind = .@"error";
    };
    const invalid_preproc_expr_start = struct {
        const msg = "invalid token at start of a preprocessor expression";
        const kind = .@"error";
    };
    const c99_compat = struct {
        const msg = "using this character in an identifier is incompatible with C99";
        const opt = "c99-compat";
        const kind = .warning;
    };
    const unicode_zero_width = struct {
        const msg = "identifier contains Unicode character <U+{X:0>4}> that is invisible in some environments";
        const opt = "unicode-homoglyph";
        const extra = .actual_codepoint;
        const kind = .warning;
    };
    const unicode_homoglyph = struct {
        const msg = "treating Unicode character <U+{X:0>4}> as identifier character rather than as '{u}' symbol";
        const extra = .codepoints;
        const opt = "unicode-homoglyph";
        const kind = .warning;
    };
    const pragma_inside_macro = struct {
        const msg = "#pragma directive in macro expansion";
        const kind = .@"error";
    };
    const meaningless_asm_qual = struct {
        const msg = "meaningless '{s}' on assembly outside function";
        const extra = .str;
        const kind = .@"error";
    };
    const duplicate_asm_qual = struct {
        const msg = "duplicate asm qualifier '{s}'";
        const extra = .str;
        const kind = .@"error";
    };
    const invalid_asm_str = struct {
        const msg = "cannot use {s} string literal in assembly";
        const extra = .str;
        const kind = .@"error";
    };
    const dollar_in_identifier_extension = struct {
        const msg = "'$' in identifier";
        const opt = "dollar-in-identifier-extension";
        const kind = .off;
        const suppress_language_option = "dollars_in_identifiers";
    };
    const dollars_in_identifiers = struct {
        const msg = "illegal character '$' in identifier";
        const kind = .@"error";
    };
    const expanded_from_here = struct {
        const msg = "expanded from here";
        const kind = .note;
    };
    const skipping_macro_backtrace = struct {
        const msg = "(skipping {d} expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)";
        const extra = .unsigned;
        const kind = .note;
    };
    const pragma_operator_string_literal = struct {
        const msg = "_Pragma requires exactly one string literal token";
        const kind = .@"error";
    };
    const unknown_gcc_pragma = struct {
        const msg = "pragma GCC expected 'error', 'warning', 'diagnostic', 'poison'";
        const kind = .warning;
    };
    const unknown_gcc_pragma_directive = struct {
        const msg = "pragma GCC diagnostic expected 'error', 'warning', 'ignored', 'fatal', 'push', or 'pop'";
        const opt = "unknown-pragmas";
        const kind = .warning;
    };
    const predefined_top_level = struct {
        const msg = "predefined identifier is only valid inside function";
        const opt = "predefined-identifier-outside-function";
        const kind = .warning;
    };
};

list: std.ArrayList(Message),
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
    if (std.mem.eql(u8, name, "fatal-errors")) {
        diag.fatal_errors = to != .off;
        return;
    }
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

pub fn setAll(diag: *Diagnostics, to: Kind) void {
    inline for (std.meta.fields(Options)) |f| {
        @field(diag.options, f.name) = to;
    }
}

pub fn init(gpa: Allocator) Diagnostics {
    return .{
        .color = std.io.getStdErr().supportsAnsiEscapeCodes(),
        .list = std.ArrayList(Message).init(gpa),
    };
}

pub fn deinit(diag: *Diagnostics) void {
    diag.list.deinit();
}

pub fn add(diag: *Diagnostics, msg: Message, expansion_locs: []const Source.Location) Compilation.Error!void {
    const kind = diag.tagKind(msg.tag);
    if (kind == .off) return;
    var copy = msg;
    copy.kind = kind;

    if (expansion_locs.len != 0) copy.loc = expansion_locs[expansion_locs.len - 1];
    try diag.list.append(copy);
    if (expansion_locs.len != 0) {
        // Add macro backtrace notes in reverse order omitting from the middle if needed.
        var i = expansion_locs.len - 1;
        const half = diag.macro_backtrace_limit / 2;
        const limit = if (i < diag.macro_backtrace_limit) 0 else i - half;
        try diag.list.ensureUnusedCapacity(if (limit == 0) expansion_locs.len else diag.macro_backtrace_limit + 1);
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
    m.end(line, col);
    return error.FatalError;
}

pub fn fatalNoSrc(diag: *Diagnostics, comptime fmt: []const u8, args: anytype) Compilation.Error {
    if (@import("builtin").os.tag == .windows or !diag.color) {
        std.debug.print("fatal error: " ++ fmt ++ "\n", args);
    } else {
        const RED = "\x1b[31;1m";
        const RESET = "\x1b[0m";
        const BOLD = RESET ++ "\x1b[1m";

        std.debug.print(RED ++ "fatal error: " ++ BOLD ++ fmt ++ "\n" ++ RESET, args);
    }
    return error.FatalError;
}

pub fn render(comp: *Compilation) void {
    if (comp.diag.list.items.len == 0) return;
    var m = MsgWriter.init(comp.diag.color);
    defer m.deinit();

    renderExtra(comp, &m);
}

pub fn renderExtra(comp: *Compilation, m: anytype) void {
    var errors: u32 = 0;
    var warnings: u32 = 0;
    for (comp.diag.list.items) |msg| {
        switch (msg.kind) {
            .@"fatal error", .@"error" => errors += 1,
            .warning => warnings += 1,
            .note => {},
            .off => continue, // happens if an error is added before it is disabled
        }

        var line: ?[]const u8 = null;
        var col = switch (msg.tag) {
            .escape_sequence_overflow,
            .invalid_universal_character,
            // use msg.extra.unsigned for index into string literal
            => @truncate(u32, msg.extra.unsigned),
            else => 0,
        };
        if (msg.loc.id != .unused) {
            const source = comp.getSource(msg.loc.id);
            const line_col = source.lineCol(msg.loc.byte_offset);
            line = line_col.line;
            col += line_col.col;
            m.location(source.path, msg.loc.line, col);
        }

        m.start(msg.kind);
        inline for (std.meta.fields(Tag)) |field| {
            if (field.value == @enumToInt(msg.tag)) {
                const info = @field(messages, field.name);
                if (@hasDecl(info, "extra")) {
                    switch (info.extra) {
                        .str => m.print(info.msg, .{msg.extra.str}),
                        .tok_id => m.print(info.msg, .{
                            msg.extra.tok_id.expected.symbol(),
                            msg.extra.tok_id.actual.symbol(),
                        }),
                        .tok_id_expected => m.print(info.msg, .{msg.extra.tok_id_expected.symbol()}),
                        .arguments => m.print(info.msg, .{ msg.extra.arguments.expected, msg.extra.arguments.actual }),
                        .codepoints => m.print(info.msg, .{
                            msg.extra.codepoints.actual,
                            msg.extra.codepoints.resembles,
                        }),
                        .actual_codepoint => m.print(info.msg, .{msg.extra.actual_codepoint}),
                        .unsigned => m.print(info.msg, .{msg.extra.unsigned}),
                        .signed => m.print(info.msg, .{msg.extra.signed}),
                        else => unreachable,
                    }
                } else {
                    m.write(info.msg);
                }

                if (@hasDecl(info, "opt")) {
                    if (@field(comp.diag.options, info.opt) != null and @field(comp.diag.options, info.opt).? == .@"error") {
                        m.print(" [-Werror={s}]", .{info.opt});
                    } else {
                        m.print(" [-W{s}]", .{info.opt});
                    }
                }
            }
        }

        m.end(line, col);
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

fn tagKind(diag: *Diagnostics, tag: Tag) Kind {
    // XXX: horrible hack, do not do this
    const comp = @fieldParentPtr(Compilation, "diag", diag);

    var kind: Kind = undefined;
    inline for (std.meta.fields(Tag)) |field| {
        if (field.value == @enumToInt(tag)) {
            const info = @field(messages, field.name);
            kind = info.kind;

            // stage1 doesn't like when I combine these ifs
            if (@hasDecl(info, "opt")) {
                if (@field(diag.options, info.opt)) |some| kind = some;
            }
            if (@hasDecl(info, "suppress_version")) if (comp.langopts.standard.atLeast(info.suppress_version)) return .off;
            if (@hasDecl(info, "suppress_gnu")) if (comp.langopts.standard.isExplicitGNU()) return .off;
            if (@hasDecl(info, "suppress_language_option")) if (!@field(comp.langopts, info.suppress_language_option)) return .off;
            if (kind == .@"error" and diag.fatal_errors) kind = .@"fatal error";
            return kind;
        }
    }
    unreachable;
}

const MsgWriter = struct {
    w: std.fs.File.Writer,
    color: bool,

    fn init(color: bool) MsgWriter {
        std.debug.getStderrMutex().lock();
        return .{
            .w = std.io.getStdErr().writer(),
            .color = color,
        };
    }

    fn deinit(_: *MsgWriter) void {
        std.debug.getStderrMutex().unlock();
    }

    fn print(m: *MsgWriter, comptime fmt: []const u8, args: anytype) void {
        m.w.print(fmt, args) catch {};
    }

    fn write(m: *MsgWriter, msg: []const u8) void {
        m.w.writeAll(msg) catch {};
    }

    fn location(m: *MsgWriter, path: []const u8, line: u32, col: u32) void {
        const prefix = if (std.fs.path.dirname(path) == null and path[0] != '<') "." ++ std.fs.path.sep_str else "";
        if (@import("builtin").os.tag == .windows or !m.color) {
            m.print("{s}{s}:{d}:{d}: ", .{ prefix, path, line, col });
        } else {
            const BOLD = "\x1b[0m\x1b[1m";
            m.print(BOLD ++ "{s}{s}:{d}:{d}: ", .{ prefix, path, line, col });
        }
    }

    fn start(m: *MsgWriter, kind: Kind) void {
        if (@import("builtin").os.tag == .windows or !m.color) {
            m.print("{s}: ", .{@tagName(kind)});
        } else {
            const PURPLE = "\x1b[35;1m";
            const CYAN = "\x1b[36;1m";
            const RED = "\x1b[31;1m";
            const BOLD = "\x1b[0m\x1b[1m";

            const msg_kind_str = switch (kind) {
                .@"fatal error" => RED ++ "fatal error: " ++ BOLD,
                .@"error" => RED ++ "error: " ++ BOLD,
                .note => CYAN ++ "note: " ++ BOLD,
                .warning => PURPLE ++ "warning: " ++ BOLD,
                .off => unreachable,
            };
            m.write(msg_kind_str);
        }
    }

    fn end(m: *MsgWriter, maybe_line: ?[]const u8, col: u32) void {
        const line = maybe_line orelse {
            m.write("\n");
            return;
        };
        if (@import("builtin").os.tag == .windows or !m.color) {
            m.print("\n{s}\n", .{line});
            m.print("{s: >[1]}^\n", .{ "", col - 1 });
        } else {
            const GREEN = "\x1b[32;1m";
            const RESET = "\x1b[0m";

            m.print("\n" ++ RESET ++ "{s}\n", .{line});
            m.print("{s: >[1]}" ++ GREEN ++ "^" ++ RESET ++ "\n", .{ "", col - 1 });
        }
    }
};
