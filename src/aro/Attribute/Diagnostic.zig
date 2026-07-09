const std = @import("std");

const Diagnostics = @import("../Diagnostics.zig");

const Diagnostic = @This();

fmt: []const u8,
kind: Diagnostics.Message.Kind,
opt: ?Diagnostics.Option = null,

// TODO get rid of this
pub const unimplemented: Diagnostic = .{
    .fmt = "TODO: implement {at} attribute",
    .kind = .warning,
};

pub const arg_count_zero: Diagnostic = .{
    .fmt = "{at} attribute takes no arguments",
    .kind = .@"error",
};

pub const arg_count_one: Diagnostic = .{
    .fmt = "{at} attribute takes one argument",
    .kind = .@"error",
};

pub const arg_count: Diagnostic = .{
    .fmt = "{at} attribute takes {d} arguments",
    .kind = .@"error",
};

pub const not_enough_args: Diagnostic = .{
    .fmt = "{at} attribute takes at least {d} argument(s)",
    .kind = .@"error",
};

pub const too_many_args: Diagnostic = .{
    .fmt = "{at} attribute takes at most {d} argument(s)",
    .kind = .@"error",
};

pub const arg_type: Diagnostic = .{
    .fmt = "expected {s} as argmuent of {at} attribute but got {s}",
    .kind = .@"error",
};

pub const arg_int_out_of_range: Diagnostic = .{
    .fmt = "attribute {at} argument value '{value}' out of range",
    .kind = .@"error",
};

pub const arg_requires_string: Diagnostic = .{
    .fmt = "expected string literal as argmuent of {at} attribute",
    .kind = .@"error",
};

pub const unknown_enum: Diagnostic = .{
    .fmt = "unknown {at} argument. Possible values are: {choices}",
    .kind = .warning,
    .opt = .@"ignored-attributes",
};

pub const invalid_target: Diagnostic = .{
    .fmt = "{at} attribute only applies to {choices}",
    .kind = .warning,
    .opt = .@"ignored-attributes",
};

pub const incompatible_attr: Diagnostic = .{
    .fmt = "{at} and {at} attributes are not compatible",
    .kind = .@"error",
};

pub const invalid_stmt_attr: Diagnostic = .{
    .fmt = "{at} attribute cannot be applied to a statement",
    .kind = .@"error",
};

pub const previous_attribute: Diagnostic = .{
    .fmt = "previous attribute is here",
    .kind = .note,
};

pub const ignored_attribute: Diagnostic = .{
    .fmt = "{at} attribute ignored",
    .kind = .warning,
    .opt = .@"ignored-attributes",
};

pub const conflicting_attribute: Diagnostic = .{
    .fmt = "conflicting attribute is here",
    .kind = .note,
};

// vector_size
pub const invalid_vec_elem_ty: Diagnostic = .{
    .fmt = "invalid vector element type {qt}",
    .kind = .@"error",
};

pub const bit_int_vec_too_small: Diagnostic = .{
    .fmt = "'_BitInt' vector element width must be at least as wide as 'CHAR_BIT'",
    .kind = .@"error",
};

pub const bit_int_vec_not_pow2: Diagnostic = .{
    .fmt = "'_BitInt' vector element width must be a power of 2",
    .kind = .@"error",
};

pub const vec_size_not_multiple: Diagnostic = .{
    .fmt = "vector size not an integral multiple of component size",
    .kind = .@"error",
};

// alignment
pub const alignas_on_func: Diagnostic = .{
    .fmt = "{at} attribute only applies to variables and fields",
    .kind = .@"error",
};

pub const alignas_on_param: Diagnostic = .{
    .fmt = "{at} attribute cannot be applied to a function parameter",
    .kind = .@"error",
};

pub const alignas_bitfield: Diagnostic = .{
    .fmt = "{at} attribute cannot be applied to a bit-field",
    .kind = .@"error",
};

pub const minimum_alignment: Diagnostic = .{
    .fmt = "requested alignment is less than minimum alignment of {d}",
    .kind = .@"error",
};

pub const maximum_alignment: Diagnostic = .{
    .fmt = "requested alignment of {d} is too large",
    .kind = .@"error",
};

pub const negative_alignment: Diagnostic = .{
    .fmt = "requested negative alignment of {d} is invalid",
    .kind = .@"error",
};

pub const non_pow2_align: Diagnostic = .{
    .fmt = "requested alignment is not a power of 2",
    .kind = .@"error",
};

pub const msvc_enum_align_ignored: Diagnostic = .{
    .fmt = "alignment specifier is ignored on enum",
    .kind = .warning,
    .opt = .@"ignored-attributes",
};

// warn_unused_result
pub const warn_unused_result_void: Diagnostic = .{
    .fmt = "attribute {at} cannot be applied to functions without return value",
    .kind = .warning,
    .opt = .@"ignored-attributes",
};

// nonnull
pub const nonnull_param_args: Diagnostic = .{
    .fmt = "{at} attribute when used on parameters takes no arguments",
    .kind = .warning,
    .opt = .@"ignored-attributes",
};

pub const param_out_of_bounds: Diagnostic = .{
    .fmt = "{at} attribute parameter {d} is out of bounds",
    .kind = .@"error",
};

pub const nonnull_pointer_only: Diagnostic = .{
    .fmt = "{at} attribute only applies to pointer arguments",
    .kind = .warning,
    .opt = .@"ignored-attributes",
};

// neon_vector_type, neon_polyvector_type
pub const invalid_neon_vec_size: Diagnostic = .{
    .fmt = "Neon vector size must be 64 or 128 bits",
    .kind = .@"error",
};

// transparent_union
pub const transparent_union_forward_decl: Diagnostic = .{
    .fmt = "{at} attribute can only be applied to a union definition; attribute ignored",
    .kind = .warning,
    .opt = .@"ignored-attributes",
};

pub const transparent_union_wrong_type: Diagnostic = .{
    .fmt = "{at} attribute only applies to unions",
    .kind = .warning,
    .opt = .@"ignored-attributes",
};

pub const transparent_union_one_field: Diagnostic = .{
    .fmt = "transparent union definition must contain at least one field; {at} attribute ignored",
    .opt = .@"ignored-attributes",
    .kind = .warning,
};

pub const transparent_union_size: Diagnostic = .{
    .fmt = "size of field '{s}' ({d} bits) does not match the size of the first field in transparent union; {at} attribute ignored",
    .kind = .warning,
    .opt = .@"ignored-attributes",
};

pub const transparent_union_size_note: Diagnostic = .{
    .fmt = "size of first field is {d}",
    .kind = .note,
};

// designated_init
pub const designated_init_invalid: Diagnostic = .{
    .fmt = "{at} attribute is only valid on 'struct' type'",
    .kind = .@"error",
};

// fallthrough
pub const fallthrough_non_empty: Diagnostic = .{
    .fmt = "{at} attribute is only allowed on empty statements",
    .kind = .@"error",
};

pub const fallthrough_outside_switch: Diagnostic = .{
    .fmt = "{at} attribute outside a switch statement",
    .kind = .@"error",
};

pub const fallthrough_not_before_case: Diagnostic = .{
    .fmt = "{at} attribute not preceding a switch label",
    .kind = .@"error",
};

// callconvs
pub const callconv_non_func: Diagnostic = .{
    .fmt = "{at} only applies to function types; type here is {qt}",
    .kind = .warning,
    .opt = .@"ignored-attributes",
};

pub const callconv_not_supported: Diagnostic = .{
    .fmt = "{at} calling convention is not supported for this target",
    .kind = .warning,
    .opt = .@"ignored-attributes",
};

pub const callconv_incompatible: Diagnostic = .{
    .fmt = "{s} and {s} attributes are not compatible",
    .kind = .warning,
    .opt = .@"ignored-attributes",
};

// visibility
pub const visibility_protected_invalid: Diagnostic = .{
    .fmt = "target does not support 'protected' visibility; using 'default'",
    .kind = .warning,
    .opt = .@"unsupported-visibility",
};

pub const incompatible_visibility: Diagnostic = .{
    .fmt = "visibility does not match previous declaration",
    .kind = .@"error",
};

// nullability
pub const conflicting_nullability: Diagnostic = .{
    .fmt = "nullability specifier '{s}' conflicts with existing specifier '{s}'",
    .kind = .@"error",
};

pub const invalid_nullability: Diagnostic = .{
    .fmt = "nullability specifier cannot be applied to non-pointer type {qt}",
    .kind = .@"error",
};

// [[_Noreturn]]
pub const deprecated_noreturn: Diagnostic = .{
    .fmt = "the '[[_Noreturn]]' attribute spelling is deprecated in C23; use '[[noreturn]]' instead",
    .kind = .warning,
    .opt = .@"deprecated-attributes",
};

// cleanup
pub const cleanup_non_function: Diagnostic = .{
    .fmt = "{at} argument '{s}' is not a function",
    .kind = .@"error",
};

pub const cleanup_one_arg: Diagnostic = .{
    .fmt = "{at} function '{s}' must take 1 parameter",
    .kind = .@"error",
};

pub const cleanup_arg_ty: Diagnostic = .{
    .fmt = "{at} function '{s}' parameter {qt} is incompatible with {qt}",
    .kind = .@"error",
};

// gnu_inline
pub const gnu_inline_non_inline: Diagnostic = .{
    .fmt = "{at} attribute requires function to be marked 'inline', attribute ignored",
    .kind = .warning,
    .opt = .@"ignored-attributes",
};

// section
pub const conflicting_section_name: Diagnostic = .{
    .fmt = "{at} does not match previous declaration",
    .kind = .warning,
    .opt = .section,
};

// linkages
pub const invalid_weak: Diagnostic = .{
    .fmt = "{at} cannot be applied to declarations with internal linkage",
    .kind = .@"error",
};

pub const invalid_selectany: Diagnostic = .{
    .fmt = "{at} can only be applied to data items with external linkage",
    .kind = .@"error",
};

// blocks
pub const blocks_only_local_variables: Diagnostic = .{
    .fmt = "'blocks' attribute only applies to local variables",
    .kind = .@"error",
};
