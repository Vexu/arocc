const std = @import("std");

const Diagnostics = @import("../Diagnostics.zig");

const Diagnostic = @This();

fmt: []const u8,
kind: Diagnostics.Message.Kind,
opt: ?Diagnostics.Option = null,
// extension: bool = false,

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
    .fmt = "unknown `{s}` argument. Possible values are: {choices}",
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
