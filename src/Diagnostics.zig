const std = @import("std");
const mem = std.mem;
const Allocator = mem.Allocator;
const Source = @import("Source.zig");
const Compilation = @import("Compilation.zig");
const Tree = @import("Tree.zig");

const Diagnostics = @This();

pub const Message = struct {
    tag: Tag,
    loc: Source.Location = .{},
    extra: Extra = .{ .none = {} },

    pub const Extra = union {
        str: []const u8,
        tok_id: struct {
            expected: Tree.Token.Id,
            actual: Tree.Token.Id,
        },
        arguments: struct {
            expected: u32,
            actual: u32,
        },
        unsigned: u64,
        signed: i64,
        none: void,
    };
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
    to_match_brace,
    to_match_bracket,
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
    missing_type_specifier,
    multiple_storage_class,
    static_assert_failure,
    static_assert_failure_message,
    expected_type,
    cannot_combine_spec,
    duplicate_decl_spec,
    restrict_non_pointer,
    expected_external_decl,
    expected_ident_or_l_paren,
    missing_declaration,
    func_not_in_root,
    illegal_initializer,
    extern_initializer,
    spec_from_typedef,
    type_is_invalid,
    param_before_var_args,
    void_only_param,
    void_param_qualified,
    void_must_be_first_param,
    invalid_storage_on_param,
    threadlocal_non_var,
    func_spec_non_func,
    illegal_storage_on_func,
    illegal_storage_on_global,
    expected_stmt,
    func_cannot_return_func,
    func_cannot_return_array,
    undeclared_identifier,
    not_callable,
    unsupported_str_cat,
    static_func_not_global,
    implicit_func_decl,
    expected_param_decl,
    invalid_old_style_params,
    expected_fn_body,
    invalid_void_param,
    unused_value,
    continue_not_in_loop,
    break_not_in_loop_or_switch,
    unreachable_code,
    duplicate_label,
    previous_label,
    undeclared_label,
    case_not_in_switch,
    duplicate_switch_case_signed,
    duplicate_switch_case_unsigned,
    multiple_default,
    previous_case,
    expected_arguments,
    expected_arguments_old,
    expected_at_least_arguments,
    invalid_static_star,
    static_non_param,
    array_qualifiers,
    star_non_param,
    variable_len_array_file_scope,
    useless_static,
    negative_array_size,
    array_incomplete_elem,
    array_func_elem,
    static_non_outermost_array,
    qualifier_non_outermost_array,
    unterminated_macro_arg_list,
    unknown_warning,
    overflow_unsigned,
    overflow_signed,
    int_literal_too_big,
    indirection_ptr,
    addr_of_rvalue,
    not_assignable,
    ident_or_l_brace,
    empty_enum,
    redefinition,
    previous_definition,
    expected_identifier,
    expected_str_literal,
    parameter_missing,
    empty_record,
    wrong_tag,
    expected_parens_around_typename,
    alignof_expr,
    invalid_sizeof,
    macro_redefined,
    generic_qual_type,
    generic_duplicate,
    generic_duplicate_default,
    generic_no_match,
    escape_sequence_overflow,
    invalid_universal_character,
    multichar_literal,
    char_lit_too_wide,
    must_use_struct,
    must_use_union,
    must_use_enum,
    redefinition_different_sym,
    redefinition_incompatible,
    redefinition_of_parameter,
    invalid_bin_types,
    comparison_ptr_int,
    comparison_distinct_ptr,
    incompatible_pointers,
    invalid_argument_un,
    incompatible_assign,
    implicit_ptr_to_int,
    invalid_cast_to_float,
    invalid_cast_to_pointer,
    invalid_cast_type,
    qual_cast,
    invalid_index,
    invalid_subscript,
    array_after,
    array_before,
    statement_int,
    statement_scalar,
    func_should_return,
    incompatible_return,
    implicit_int_to_ptr,
    func_does_not_return,
    incompatible_param,
    parameter_here,
    atomic_array,
    atomic_func,
    atomic_incomplete,
    addr_of_register,
    variable_incomplete_ty,
    alignas_on_func,
    alignas_on_param,
    minimum_alignment,
    maximum_alignment,
    negative_alignment,
    align_ignored,
    zero_align_ignored,
    non_pow2_align,
    pointer_mismatch,
    static_assert_not_constant,
    static_assert_missing_message,
    unbound_vla,
    array_too_large,
    incompatible_ptr_init,
    incompatible_ptr_assign,
    vla_init,
    func_init,
    incompatible_init,
    empty_scalar_init,
    excess_scalar_init,
    excess_str_init,
    excess_struct_init,
    excess_array_init,
    str_init_too_long,
    arr_init_too_long,
    invalid_typeof,
    division_by_zero,
    builtin_choose_cond,
    alignas_unavailable,
    case_val_unavailable,
    enum_val_unavailable,
    incompatible_array_init,
    initializer_overrides,
    previous_initializer,
    invalid_array_designator,
    negative_array_designator,
    oob_array_designator,
    invalid_field_designator,
    no_such_field_designator,
    empty_aggregate_init_braces,
    ptr_init_discards_quals,
    ptr_assign_discards_quals,
};

const Options = struct {
    @"unsupported-pragma": Kind = .warning,
    @"c99-extensions": Kind = .warning,
    @"implicit-int": Kind = .warning,
    @"duplicate-decl-specifier": Kind = .warning,
    @"missing-declaration": Kind = .warning,
    @"extern-initializer": Kind = .warning,
    @"implicit-function-declaration": Kind = .warning,
    @"unused-value": Kind = .warning,
    @"unreachable-code": Kind = .warning,
    @"unknown-warning-option": Kind = .warning,
    @"empty-struct": Kind = .off,
    @"gnu-alignof-expression": Kind = .warning,
    @"macro-redefined": Kind = .warning,
    @"generic-qual-type": Kind = .warning,
    multichar: Kind = .warning,
    @"pointer-integer-compare": Kind = .warning,
    @"compare-distinct-pointer-types": Kind = .warning,
    @"literal-conversion": Kind = .warning,
    @"cast-qualifiers": Kind = .warning,
    @"array-bounds": Kind = .warning,
    @"int-conversion": Kind = .warning,
    @"pointer-type-mismatch": Kind = .warning,
    @"c2x-extension": Kind = .warning,
    @"incompatible-pointer-types": Kind = .warning,
    @"excess-initializers": Kind = .warning,
    @"division-by-zero": Kind = .warning,
    @"initializer-overrides": Kind = .warning,
    @"incompatible-pointer-types-discards-qualifiers": Kind = .warning,
};

list: std.ArrayList(Message),
color: bool = true,
fatal_errors: bool = false,
options: Options = .{},
errors: u32 = 0,

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
    });
}

pub fn setAll(diag: *Diagnostics, to: Kind) void {
    inline for (std.meta.fields(Options)) |f| {
        @field(diag.options, f.name) = to;
    }
}

pub fn init(gpa: *Allocator) Diagnostics {
    return .{
        .color = std.io.getStdErr().supportsAnsiEscapeCodes(),
        .list = std.ArrayList(Message).init(gpa),
    };
}

pub fn deinit(diag: *Diagnostics) void {
    diag.list.deinit();
}

pub fn add(diag: *Diagnostics, msg: Message) Compilation.Error!void {
    const kind = diag.tagKind(msg.tag);
    if (kind == .off) return;
    try diag.list.append(msg);
    if (kind == .@"fatal error" or (kind == .@"error" and diag.fatal_errors))
        return error.FatalError;
}

pub fn fatal(diag: *Diagnostics, path: []const u8, lcs: Source.LCS, comptime fmt: []const u8, args: anytype) Compilation.Error {
    var m = MsgWriter.init(diag.color);
    defer m.deinit();

    m.location(path, lcs);
    m.start(.@"fatal error");
    m.print(fmt, args);
    m.end(lcs);
    return error.FatalError;
}

pub fn fatalNoSrc(diag: *Diagnostics, comptime fmt: []const u8, args: anytype) Compilation.Error {
    if (std.builtin.os.tag == .windows or !diag.color) {
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
        const kind = comp.diag.tagKind(msg.tag);
        switch (kind) {
            .@"fatal error", .@"error" => errors += 1,
            .warning => warnings += 1,
            .note => {},
            .off => unreachable,
        }

        var lcs: ?Source.LCS = null;
        if (msg.loc.id != .unused) {
            const loc = if (msg.loc.next != null) msg.loc.next.?.* else msg.loc;
            const source = comp.getSource(loc.id);
            lcs = source.lineColString(loc.byte_offset);
            switch (msg.tag) {
                .escape_sequence_overflow,
                .invalid_universal_character,
                => { // use msg.extra.unsigned for index into string literal
                    lcs.?.col += @truncate(u32, msg.extra.unsigned);
                },
                else => {},
            }
            m.location(source.path, lcs.?);
        }

        m.start(kind);
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
            .to_match_brace => m.write("to match this '{'"),
            .to_match_bracket => m.write("to match this '['"),
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
            .expected_integer_constant_expr => m.write("expression is not an integer constant expression"),
            .missing_type_specifier => m.write("type specifier missing, defaults to 'int'"),
            .multiple_storage_class => m.print("cannot combine with previous '{s}' declaration specifier", .{msg.extra.str}),
            .static_assert_failure => m.write("static assertion failed"),
            .static_assert_failure_message => m.print("static assertion failed {s}", .{msg.extra.str}),
            .expected_type => m.write("expected a type"),
            .cannot_combine_spec => m.print("cannot combine with previous '{s}' specifier", .{msg.extra.str}),
            .duplicate_decl_spec => m.print("duplicate '{s}' declaration specifier", .{msg.extra.str}),
            .restrict_non_pointer => m.print("restrict requires a pointer or reference ('{s}' is invalid)", .{msg.extra.str}),
            .expected_external_decl => m.write("expected external declaration"),
            .expected_ident_or_l_paren => m.write("expected identifier or '('"),
            .missing_declaration => m.write("declaration does not declare anything"),
            .func_not_in_root => m.write("function definition is not allowed here"),
            .illegal_initializer => m.write("illegal initializer (only variables can be initialized)"),
            .extern_initializer => m.write("extern variable has initializer"),
            .spec_from_typedef => m.print("'{s}' came from typedef", .{msg.extra.str}),
            .type_is_invalid => m.print("'{s}' is invalid", .{msg.extra.str}),
            .param_before_var_args => m.write("ISO C requires a named parameter before '...'"),
            .void_only_param => m.write("'void' must be the only parameter if specified"),
            .void_param_qualified => m.write("'void' parameter cannot be qualified"),
            .void_must_be_first_param => m.write("'void' must be the first parameter if specified"),
            .invalid_storage_on_param => m.write("invalid storage class on function parameter"),
            .threadlocal_non_var => m.write("_Thread_local only allowed on variables"),
            .func_spec_non_func => m.print("'{s}' can only appear on functions", .{msg.extra.str}),
            .illegal_storage_on_func => m.write("illegal storage class on function"),
            .illegal_storage_on_global => m.write("illegal storage class on global variable"),
            .expected_stmt => m.write("expected statement"),
            .func_cannot_return_func => m.write("function cannot return a function"),
            .func_cannot_return_array => m.write("function cannot return an array"),
            .undeclared_identifier => m.print("use of undeclared identifier '{s}'", .{msg.extra.str}),
            .not_callable => m.print("cannot call non function type '{s}'", .{msg.extra.str}),
            .unsupported_str_cat => m.write("unsupported string literal concatenation"),
            .static_func_not_global => m.write("static functions must be global"),
            .implicit_func_decl => m.print("implicit declaration of function '{s}' is invalid in C99", .{msg.extra.str}),
            .expected_param_decl => m.write("expected parameter declaration"),
            .invalid_old_style_params => m.write("identifier parameter lists are only allowed in function definitions"),
            .expected_fn_body => m.write("expected function body after function declaration"),
            .invalid_void_param => m.write("parameter cannot have void type"),
            .unused_value => m.write("expression result unused"),
            .continue_not_in_loop => m.write("'continue' statement not in a loop"),
            .break_not_in_loop_or_switch => m.write("'break' statement not in a loop or a switch"),
            .unreachable_code => m.write("unreachable code"),
            .duplicate_label => m.print("duplicate label '{s}'", .{msg.extra.str}),
            .previous_label => m.print("previous definition of label '{s}' was here", .{msg.extra.str}),
            .undeclared_label => m.print("use of undeclared label '{s}'", .{msg.extra.str}),
            .case_not_in_switch => m.print("'{s}' statement not in a switch statement", .{msg.extra.str}),
            .duplicate_switch_case_signed => m.print("duplicate case value '{d}'", .{msg.extra.signed}),
            .duplicate_switch_case_unsigned => m.print("duplicate case value '{d}'", .{msg.extra.unsigned}),
            .multiple_default => m.write("multiple default cases in the same switch"),
            .previous_case => m.write("previous case defined here"),
            .expected_arguments, .expected_arguments_old => m.print("expected {d} argument(s) got {d}", .{ msg.extra.arguments.expected, msg.extra.arguments.actual }),
            .expected_at_least_arguments => m.print("expected at least {d} argument(s) got {d}", .{ msg.extra.arguments.expected, msg.extra.arguments.actual }),
            .invalid_static_star => m.write("'static' may not be used with an unspecified variable length array size"),
            .static_non_param => m.write("'static' used outside of function parameters"),
            .array_qualifiers => m.write("type qualifier in non parameter array type"),
            .star_non_param => m.write("star modifier used outside of function parameters"),
            .variable_len_array_file_scope => m.write("variable length arrays not allowed at file scope"),
            .useless_static => m.write("'static' useless without a constant size"),
            .negative_array_size => m.write("array size must be 0 or greater"),
            .array_incomplete_elem => m.print("array has incomplete element type '{s}'", .{msg.extra.str}),
            .array_func_elem => m.write("arrays cannot have functions as their element type"),
            .static_non_outermost_array => m.write("'static' used in non-outermost array type"),
            .qualifier_non_outermost_array => m.write("type qualifier used in non-outermost array type"),
            .unterminated_macro_arg_list => m.write("unterminated function macro argument list"),
            .unknown_warning => m.print("unknown warning '{s}'", .{msg.extra.str}),
            .overflow_signed => m.print("overflow in expression; result is'{d}'", .{msg.extra.signed}),
            .overflow_unsigned => m.print("overflow in expression; result is '{d}'", .{msg.extra.unsigned}),
            .int_literal_too_big => m.write("integer literal is too large to be represented in any integer type"),
            .indirection_ptr => m.write("indirection requires pointer operand"),
            .addr_of_rvalue => m.write("cannot take the address of an rvalue"),
            .not_assignable => m.write("expression is not assignable"),
            .ident_or_l_brace => m.write("expected identifier or '{'"),
            .empty_enum => m.write("empty enum is invalid"),
            .redefinition => m.print("redefinition of '{s}'", .{msg.extra.str}),
            .previous_definition => m.write("previous definition is here"),
            .expected_identifier => m.write("expected identifier"),
            .expected_str_literal => m.write("expected string literal for diagnostic message in static_assert"),
            .parameter_missing => m.print("parameter named '{s}' is missing", .{msg.extra.str}),
            .empty_record => m.print("empty {s} is a GNU extension", .{msg.extra.str}),
            .wrong_tag => m.print("use of '{s}' with tag type that does not match previous definition", .{msg.extra.str}),
            .expected_parens_around_typename => m.write("expected parentheses around type name"),
            .alignof_expr => m.write("'_Alignof' applied to an expression is a GNU extension"),
            .invalid_sizeof => m.print("invalid application of 'sizeof' to an incomplete type '{s}'", .{msg.extra.str}),
            .macro_redefined => m.print("'{s}' macro redefined", .{msg.extra.str}),
            .generic_qual_type => m.write("generic association with qualifiers cannot be matched with"),
            .generic_duplicate => m.print("type '{s}' in generic association compatible with previously specified type", .{msg.extra.str}),
            .generic_duplicate_default => m.write("duplicate default generic association"),
            .generic_no_match => m.print("controlling expression type '{s}' not compatible with any generic association type", .{msg.extra.str}),
            .escape_sequence_overflow => m.write("escape sequence out of range"),
            .invalid_universal_character => m.write("invalid universal character"),
            .multichar_literal => m.write("multi-character character constant"),
            .char_lit_too_wide => m.write("character constant too long for its type"),
            .must_use_struct => m.print("must use 'struct' tag to refer to type '{s}'", .{msg.extra.str}),
            .must_use_union => m.print("must use 'union' tag to refer to type '{s}'", .{msg.extra.str}),
            .must_use_enum => m.print("must use 'enum' tag to refer to type '{s}'", .{msg.extra.str}),
            .redefinition_different_sym => m.print("redefinition of '{s}' as different kind of symbol", .{msg.extra.str}),
            .redefinition_incompatible => m.print("redefinition of '{s}' with a different type", .{msg.extra.str}),
            .redefinition_of_parameter => m.print("redefinition of parameter '{s}'", .{msg.extra.str}),
            .invalid_bin_types => m.print("invalid operands to binary expression ({s})", .{msg.extra.str}),
            .comparison_ptr_int => m.print("comparison between pointer and integer ({s})", .{msg.extra.str}),
            .comparison_distinct_ptr => m.print("comparison of distinct pointer types ({s})", .{msg.extra.str}),
            .incompatible_pointers => m.print("incompatible pointer types ({s})", .{msg.extra.str}),
            .invalid_argument_un => m.print("invalid argument type '{s}' to unary expression", .{msg.extra.str}),
            .incompatible_assign => m.print("assignment to {s}", .{msg.extra.str}),
            .implicit_ptr_to_int => m.print("implicit pointer to integer conversion from {s}", .{msg.extra.str}),
            .invalid_cast_to_float => m.print("pointer cannot be cast to type '{s}'", .{msg.extra.str}),
            .invalid_cast_to_pointer => m.print("operand of type '{s}' cannot be cast to a pointer type", .{msg.extra.str}),
            .invalid_cast_type => m.print("cannot cast to non arithmetic or pointer type '{s}'", .{msg.extra.str}),
            .qual_cast => m.print("cast to type '{s}' will not preserve qualifiers", .{msg.extra.str}),
            .invalid_index => m.write("array subscript is not an integer"),
            .invalid_subscript => m.write("subscripted value is not an array or pointer"),
            .array_after => m.print("array index {d} is past the end of the array", .{msg.extra.unsigned}),
            .array_before => m.print("array index {d} is before the beginning of the array", .{msg.extra.signed}),
            .statement_int => m.print("statement requires expression with integer type ('{s}' invalid)", .{msg.extra.str}),
            .statement_scalar => m.print("statement requires expression with scalar type ('{s}' invalid)", .{msg.extra.str}),
            .func_should_return => m.print("non-void function '{s}' should return a value", .{msg.extra.str}),
            .incompatible_return => m.print("returning '{s}' from a function with incompatible result type", .{msg.extra.str}),
            .implicit_int_to_ptr => m.print("implicit integer to pointer conversion from {s}", .{msg.extra.str}),
            .func_does_not_return => m.print("non-void function '{s}' does not return a value", .{msg.extra.str}),
            .incompatible_param => m.print("passing '{s}' to parameter of incompatible type", .{msg.extra.str}),
            .parameter_here => m.write("passing argument to parameter here"),
            .atomic_array => m.print("atomic cannot be applied to array type '{s}'", .{msg.extra.str}),
            .atomic_func => m.print("atomic cannot be applied to function type '{s}'", .{msg.extra.str}),
            .atomic_incomplete => m.print("atomic cannot be applied to incomplete type '{s}'", .{msg.extra.str}),
            .addr_of_register => m.write("address of register variable requested"),
            .variable_incomplete_ty => m.print("variable has incomplete type '{s}'", .{msg.extra.str}),
            .alignas_on_func => m.write("'_Alignas' attribute only applies to variables and fields"),
            .alignas_on_param => m.write("'_Alignas' attribute cannot be applied to a function parameter"),
            .minimum_alignment => m.print("requested alignment is less than minimum alignment of {d}", .{msg.extra.unsigned}),
            .maximum_alignment => m.print("requested alignment of {d} is too large", .{msg.extra.unsigned}),
            .negative_alignment => m.print("requested negative alignment of {d} is invalid", .{msg.extra.signed}),
            .align_ignored => m.write("'_Alignas' attribute is ignored here"),
            .zero_align_ignored => m.write("requested alignment of zero is ignored"),
            .non_pow2_align => m.write("requested alignment is not a power of 2"),
            .pointer_mismatch => m.print("pointer type mismatch ({s})", .{msg.extra.str}),
            .static_assert_not_constant => m.write("static_assert expression is not an integral constant expression"),
            .static_assert_missing_message => m.write("static_assert with no message is a C2X extension"),
            .unbound_vla => m.write("variable length array must be bound in function definition"),
            .array_too_large => m.write("array is too large"),
            .incompatible_ptr_init => m.print("incompatible pointer types initializing {s}", .{msg.extra.str}),
            .incompatible_ptr_assign => m.print("incompatible pointer types assigning to {s}", .{msg.extra.str}),
            .vla_init => m.write("variable-sized object may not be initialized"),
            .func_init => m.write("illegal initializer type"),
            .incompatible_init => m.print("initializing {s}", .{msg.extra.str}),
            .empty_scalar_init => m.write("scalar initializer cannot be empty"),
            .excess_scalar_init => m.write("excess elements in scalar initializer"),
            .excess_str_init => m.write("excess elements in string initializer"),
            .excess_struct_init => m.write("excess elements in struct initializer"),
            .excess_array_init => m.write("excess elements in array initializer"),
            .str_init_too_long => m.write("initializer-string for char array is too long"),
            .arr_init_too_long => m.print("cannot initialize type ({s})", .{msg.extra.str}),
            .invalid_typeof => m.print("'{s} typeof' is invalid", .{msg.extra.str}),
            .division_by_zero => m.print("{s} by zero is undefined", .{msg.extra.str}),
            .builtin_choose_cond => m.write("'__builtin_choose_expr' requires a constant expression"),
            .alignas_unavailable => m.write("'_Alignas' attribute requires integer constant expression"),
            .case_val_unavailable => m.write("case value must be an integer constant expression"),
            .enum_val_unavailable => m.write("enum value must be an integer constant expression"),
            .incompatible_array_init => m.print("cannot initialize array of type {s}", .{msg.extra.str}),
            .initializer_overrides => m.write("initializer overrides previous initialization"),
            .previous_initializer => m.write("previous initialization"),
            .invalid_array_designator => m.print("array designator used for non-array type '{s}'", .{msg.extra.str}),
            .negative_array_designator => m.print("array designator value {d} is negative", .{msg.extra.signed}),
            .oob_array_designator => m.print("array designator index {d} exceeds array bounds", .{msg.extra.unsigned}),
            .invalid_field_designator => m.print("field designator used for non-record type '{s}'", .{msg.extra.str}),
            .no_such_field_designator => m.print("record type has no field named '{s}'", .{msg.extra.str}),
            .empty_aggregate_init_braces => m.write("initializer for aggregate with no elements requires explicit braces"),
            .ptr_init_discards_quals => m.print("initializing {s} discards qualifiers", .{msg.extra.str}),
            .ptr_assign_discards_quals => m.print("assigning to {s} discards qualifiers", .{msg.extra.str}),
        }
        m.end(lcs);

        if (msg.loc.id != .unused) {
            var maybe_loc = msg.loc.next;
            if (msg.loc.next != null) maybe_loc = maybe_loc.?.next;

            while (maybe_loc) |loc| {
                const source = comp.getSource(loc.id);
                const e_lcs = source.lineColString(loc.byte_offset);
                m.location(source.path, e_lcs);
                m.start(.note);
                m.write("expanded from here");
                m.end(e_lcs);
                maybe_loc = loc.next;
            }
        }
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

pub const Kind = enum { @"fatal error", @"error", note, warning, off };

fn tagKind(diag: *Diagnostics, tag: Tag) Kind {
    var kind: Kind = switch (tag) {
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
        .multiple_storage_class,
        .static_assert_failure,
        .static_assert_failure_message,
        .expected_type,
        .cannot_combine_spec,
        .restrict_non_pointer,
        .expected_external_decl,
        .expected_ident_or_l_paren,
        .func_not_in_root,
        .illegal_initializer,
        .type_is_invalid,
        .param_before_var_args,
        .void_only_param,
        .void_param_qualified,
        .void_must_be_first_param,
        .invalid_storage_on_param,
        .threadlocal_non_var,
        .func_spec_non_func,
        .illegal_storage_on_func,
        .illegal_storage_on_global,
        .expected_stmt,
        .func_cannot_return_func,
        .func_cannot_return_array,
        .undeclared_identifier,
        .not_callable,
        .unsupported_str_cat,
        .static_func_not_global,
        .expected_param_decl,
        .expected_fn_body,
        .invalid_void_param,
        .continue_not_in_loop,
        .break_not_in_loop_or_switch,
        .duplicate_label,
        .undeclared_label,
        .case_not_in_switch,
        .duplicate_switch_case_signed,
        .duplicate_switch_case_unsigned,
        .multiple_default,
        .expected_arguments,
        .expected_at_least_arguments,
        .invalid_static_star,
        .static_non_param,
        .array_qualifiers,
        .star_non_param,
        .variable_len_array_file_scope,
        .negative_array_size,
        .array_incomplete_elem,
        .array_func_elem,
        .static_non_outermost_array,
        .qualifier_non_outermost_array,
        .unterminated_macro_arg_list,
        .int_literal_too_big,
        .indirection_ptr,
        .addr_of_rvalue,
        .not_assignable,
        .ident_or_l_brace,
        .empty_enum,
        .redefinition,
        .expected_identifier,
        .wrong_tag,
        .expected_str_literal,
        .parameter_missing,
        .expected_parens_around_typename,
        .invalid_sizeof,
        .generic_duplicate,
        .generic_duplicate_default,
        .generic_no_match,
        .escape_sequence_overflow,
        .invalid_universal_character,
        .must_use_struct,
        .must_use_union,
        .must_use_enum,
        .redefinition_different_sym,
        .redefinition_incompatible,
        .redefinition_of_parameter,
        .invalid_bin_types,
        .incompatible_pointers,
        .invalid_argument_un,
        .incompatible_assign,
        .invalid_cast_to_float,
        .invalid_cast_to_pointer,
        .invalid_cast_type,
        .invalid_index,
        .invalid_subscript,
        .statement_int,
        .statement_scalar,
        .func_should_return,
        .incompatible_return,
        .incompatible_param,
        .atomic_array,
        .atomic_func,
        .atomic_incomplete,
        .addr_of_register,
        .variable_incomplete_ty,
        .alignas_on_func,
        .alignas_on_param,
        .minimum_alignment,
        .maximum_alignment,
        .negative_alignment,
        .non_pow2_align,
        .static_assert_not_constant,
        .unbound_vla,
        .array_too_large,
        .vla_init,
        .func_init,
        .incompatible_init,
        .empty_scalar_init,
        .arr_init_too_long,
        .invalid_typeof,
        .builtin_choose_cond,
        .alignas_unavailable,
        .case_val_unavailable,
        .enum_val_unavailable,
        .incompatible_array_init,
        .invalid_array_designator,
        .negative_array_designator,
        .oob_array_designator,
        .invalid_field_designator,
        .no_such_field_designator,
        .empty_aggregate_init_braces,
        => .@"error",
        .to_match_paren,
        .to_match_brace,
        .to_match_bracket,
        .header_str_match,
        .spec_from_typedef,
        .previous_label,
        .previous_case,
        .previous_definition,
        .parameter_here,
        .previous_initializer,
        => .note,
        .invalid_old_style_params,
        .expected_arguments_old,
        .useless_static,
        .overflow_unsigned,
        .overflow_signed,
        .char_lit_too_wide,
        .func_does_not_return,
        .align_ignored,
        .zero_align_ignored,
        => .warning,
        .unsupported_pragma => diag.options.@"unsupported-pragma",
        .whitespace_after_macro_name => diag.options.@"c99-extensions",
        .missing_type_specifier => diag.options.@"implicit-int",
        .duplicate_decl_spec => diag.options.@"duplicate-decl-specifier",
        .missing_declaration => diag.options.@"missing-declaration",
        .extern_initializer => diag.options.@"extern-initializer",
        .implicit_func_decl => diag.options.@"implicit-function-declaration",
        .unused_value => diag.options.@"unused-value",
        .unreachable_code => diag.options.@"unreachable-code",
        .unknown_warning => diag.options.@"unknown-warning-option",
        .empty_record => diag.options.@"empty-struct",
        .alignof_expr => diag.options.@"gnu-alignof-expression",
        .macro_redefined => diag.options.@"macro-redefined",
        .generic_qual_type => diag.options.@"generic-qual-type",
        .multichar_literal => diag.options.multichar,
        .comparison_ptr_int => diag.options.@"pointer-integer-compare",
        .comparison_distinct_ptr => diag.options.@"compare-distinct-pointer-types",
        .implicit_ptr_to_int => diag.options.@"literal-conversion",
        .qual_cast => diag.options.@"cast-qualifiers",
        .array_after => diag.options.@"array-bounds",
        .array_before => diag.options.@"array-bounds",
        .implicit_int_to_ptr => diag.options.@"int-conversion",
        .pointer_mismatch => diag.options.@"pointer-type-mismatch",
        .static_assert_missing_message => diag.options.@"c2x-extension",
        .incompatible_ptr_init,
        .incompatible_ptr_assign,
        => diag.options.@"incompatible-pointer-types",
        .ptr_init_discards_quals,
        .ptr_assign_discards_quals,
        => diag.options.@"incompatible-pointer-types-discards-qualifiers",
        .excess_scalar_init,
        .excess_str_init,
        .excess_struct_init,
        .excess_array_init,
        .str_init_too_long,
        => diag.options.@"excess-initializers",
        .division_by_zero => diag.options.@"division-by-zero",
        .initializer_overrides => diag.options.@"initializer-overrides",
    };
    if (kind == .@"error" and diag.fatal_errors) kind = .@"fatal error";
    return kind;
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

    fn location(m: *MsgWriter, path: []const u8, lcs: Source.LCS) void {
        if (std.builtin.os.tag == .windows or !m.color) {
            m.print("{s}:{d}:{d}: ", .{ path, lcs.line, lcs.col });
        } else {
            const BOLD = "\x1b[0m\x1b[1m";
            m.print(BOLD ++ "{s}:{d}:{d}: ", .{ path, lcs.line, lcs.col });
        }
    }

    fn start(m: *MsgWriter, kind: Kind) void {
        if (std.builtin.os.tag == .windows or !m.color) {
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

    fn end(m: *MsgWriter, lcs: ?Source.LCS) void {
        if (std.builtin.os.tag == .windows or !m.color) {
            if (lcs == null) {
                m.write("\n");
                return;
            }
            m.print("\n{s}\n", .{lcs.?.str});
            m.print("{s: >[1]}^\n", .{ "", lcs.?.col - 1 });
        } else {
            const GREEN = "\x1b[32;1m";
            const RESET = "\x1b[0m";
            if (lcs == null) {
                m.write("\n" ++ RESET);
                return;
            }

            m.print("\n" ++ RESET ++ "{s}\n", .{lcs.?.str});
            m.print("{s: >[1]}" ++ GREEN ++ "^" ++ RESET ++ "\n", .{ "", lcs.?.col - 1 });
        }
    }
};
