const std = @import("std");
const mem = std.mem;
const Tree = @import("Tree.zig");
const NodeIndex = Tree.NodeIndex;
const TokenIndex = Tree.TokenIndex;

const Attribute = @This();

name: TokenIndex,
params: NodeIndex = .none,

pub const ParseContext = enum {
    any,
    @"enum",
    function,
    label,
    record,
    statement,
    typedef,
    variable,
};

pub const Tag = enum {
    access,
    alias,
    aligned,
    alloc_align,
    alloc_size,
    always_inline,
    artificial,
    assume_aligned,
    cleanup,
    cold,
    common,
    @"const",
    constructor,
    copy,
    deprecated,
    designated_init,
    destructor,
    @"error",
    externally_visible,
    fallthrough,
    flatten,
    format,
    format_arg,
    gnu_inline,
    hot,
    ifunc,
    interrupt,
    interrupt_handler,
    leaf,
    malloc,
    may_alias,
    mode,
    no_address_safety_analysis,
    no_icf,
    no_instrument_function,
    no_profile_instrument_function,
    no_reorder,
    no_sanitize,
    no_sanitize_address,
    no_sanitize_coverage,
    no_sanitize_thread,
    no_sanitize_undefined,
    no_split_stack,
    no_stack_limit,
    no_stack_protector,
    noclone,
    nocommon,
    noinit,
    @"noinline",
    noipa,
    nonnull,
    nonstring,
    noplt,
    noreturn,
    nothrow,
    optimize,
    @"packed",
    patchable_function_entry,
    persistent,
    pure,
    retain,
    returns_nonnull,
    returns_twice,
    scalar_storage_order,
    section,
    sentinel,
    simd,
    stack_protect,
    symver,
    target,
    target_clones,
    tls_model,
    transparent_union,
    unavailable,
    uninitialized,
    unused,
    used,
    vector_size,
    visibility,
    warn_if_not_aligned,
    warn_unused_result,
    warning,
    weak,
    weakref,
    zero_call_used_regs,

    fn normalize(name: []const u8) []const u8 {
        if (name.len >= 4 and mem.startsWith(u8, name, "__") and mem.endsWith(u8, name, "__")) {
            return name[2 .. name.len - 2];
        }
        return name;
    }

    pub fn fromString(name: []const u8) ?Tag {
        @setEvalBranchQuota(2500);
        return std.meta.stringToEnum(Tag, normalize(name));
    }

    pub fn allowedInContext(tag: Tag, context: ParseContext) bool {
        return switch (context) {
            .any => true,
            .@"enum" => tag.isEnumAttr(),
            .function => tag.isFuncAttr(),
            .label => tag.isLabelAttr(),
            .record => tag.isTypeAttr(),
            .statement => tag.isStatementAttr(),
            .typedef => tag.isTypeAttr(),
            .variable => tag.isVariableAttr(),
        };
    }

    pub fn isVariableAttr(tag: Tag) bool {
        return switch (tag) {
            .alias,
            .aligned,
            .alloc_size,
            .cleanup,
            .common,
            .copy,
            .deprecated,
            .mode,
            .nocommon,
            .noinit,
            .nonstring,
            .@"packed",
            .persistent,
            .retain,
            .section,
            .tls_model,
            .unavailable,
            .uninitialized,
            .unused,
            .used,
            .vector_size,
            .visibility,
            .warn_if_not_aligned,
            .weak,
            => true,
            else => false,
        };
    }

    pub fn isTypeAttr(tag: Tag) bool {
        return switch (tag) {
            .aligned,
            .alloc_size,
            .copy,
            .deprecated,
            .designated_init,
            .may_alias,
            .mode,
            .@"packed",
            .scalar_storage_order,
            .transparent_union,
            .unavailable,
            .unused,
            .vector_size,
            .warn_if_not_aligned,
            => true,
            else => false,
        };
    }

    pub fn isFuncAttr(tag: Tag) bool {
        return switch (tag) {
            .access,
            .alias,
            .aligned,
            .alloc_align,
            .alloc_size,
            .always_inline,
            .artificial,
            .assume_aligned,
            .cold,
            .@"const",
            .constructor,
            .copy,
            .deprecated,
            .destructor,
            .@"error",
            .externally_visible,
            .flatten,
            .format,
            .format_arg,
            .gnu_inline,
            .hot,
            .ifunc,
            .interrupt,
            .interrupt_handler,
            .leaf,
            .malloc,
            .no_address_safety_analysis,
            .no_icf,
            .no_instrument_function,
            .no_profile_instrument_function,
            .no_reorder,
            .no_sanitize,
            .no_sanitize_address,
            .no_sanitize_coverage,
            .no_sanitize_thread,
            .no_sanitize_undefined,
            .no_split_stack,
            .no_stack_limit,
            .no_stack_protector,
            .noclone,
            .@"noinline",
            .noipa,
            .nonnull,
            .noplt,
            .noreturn,
            .nothrow,
            .optimize,
            .patchable_function_entry,
            .pure,
            .retain,
            .returns_nonnull,
            .returns_twice,
            .section,
            .sentinel,
            .simd,
            .stack_protect,
            .symver,
            .target,
            .target_clones,
            .unavailable,
            .unused,
            .used,
            .visibility,
            .warn_unused_result,
            .warning,
            .weak,
            .weakref,
            .zero_call_used_regs,
            => true,
            else => false,
        };
    }

    pub fn isLabelAttr(tag: Tag) bool {
        return switch (tag) {
            .cold, .hot, .unused => true,
            else => false,
        };
    }

    pub fn isStatementAttr(tag: Tag) bool {
        return tag == .fallthrough;
    }

    pub fn isEnumAttr(tag: Tag) bool {
        return switch (tag) {
            .deprecated, .unavailable => true,
            else => false,
        };
    }
};
