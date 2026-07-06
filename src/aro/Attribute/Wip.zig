const std = @import("std");
const Allocator = std.mem.Allocator;
const assert = std.debug.assert;

const Attribute = @import("../Attribute.zig");
const Diagnostic = @import("Diagnostic.zig");
const Parser = @import("../Parser.zig");
const Tree = @import("../Tree.zig");
const TokenIndex = Tree.TokenIndex;
const TypeStore = @import("../TypeStore.zig");
const QualType = TypeStore.QualType;
const Type = TypeStore.Type;

const Wip = @This();

attrs: std.ArrayList(Parsed) = .empty,
args: std.ArrayList(Parser.Result) = .empty,
applied: std.ArrayList(Attribute.Map.Ref) = .empty,
top: u32 = 0,

current: struct {
    attr: *Parsed,
    target: ?Tree.Node.Index = null,
    qt: QualType,
    parser: *Parser,
    arg_i: u32 = 0,

    fn node(c: *const @This()) Tree.Node {
        return c.target.?.get(&c.parser.tree);
    }
} = undefined,

pub const Parsed = struct {
    name: Attribute.Namespaced,
    syntax: Attribute.Syntax,
    args_index: u32,
    args_len: u32,
    tok: TokenIndex,
    used_as_type_attr: bool = false,

    fn args(a: Parsed, wip: *Wip) []const Parser.Result {
        return wip.args.items[a.args_index..][0..a.args_len];
    }
};

comptime {
    assert(@sizeOf(Parsed) == 16);
}

pub const State = struct {
    attrs: u32,
    args: u32,
    top: u32,
};

pub fn state(wip: *Wip, move_top: bool) State {
    defer {
        if (move_top) wip.top = @intCast(wip.attrs.items.len);
    }
    return .{ .attrs = @intCast(wip.attrs.items.len), .args = @intCast(wip.args.items.len), .top = wip.top };
}

pub fn restore(wip: *Wip, old_state: State) void {
    wip.attrs.items.len = old_state.attrs;
    wip.args.items.len = old_state.args;
    wip.top = old_state.top;
}

pub fn deinit(wip: *Wip, gpa: Allocator) void {
    wip.attrs.deinit(gpa);
    wip.args.deinit(gpa);
    wip.applied.deinit(gpa);
    wip.* = undefined;
}

pub fn addKeyword(wip: *Wip, p: *const Parser, keyword: TokenIndex, args: []const Parser.Result) !void {
    const args_index = wip.args.items.len;
    const gpa = p.comp.gpa;
    try wip.args.appendSlice(gpa, args);
    try wip.attrs.append(gpa, .{
        .name = .fromKeyword(p.tok_ids[keyword]),
        .syntax = .keyword,
        .args_len = @intCast(args.len),
        .args_index = @intCast(args_index),
        .tok = keyword,
    });
}

fn err(wip: *Wip, diagnostic: Diagnostic, args: anytype) !void {
    try wip.errTok(wip.current.attr.tok, diagnostic, args);
}

fn errTok(wip: *Wip, tok: TokenIndex, diagnostic: Diagnostic, args: anytype) !void {
    try wip.current.parser.err(tok, .{
        .fmt = diagnostic.fmt,
        .kind = diagnostic.kind,
        .opt = diagnostic.opt,
    }, args);
}

fn argCountMinMax(wip: *Wip, min: u32, max: u32) !bool {
    const actual_count = wip.current.attr.args_len;

    if (actual_count < min) {
        try wip.err(.not_enough_args, .{ wip.current.attr, min });
        return true;
    } else if (actual_count > max) {
        try wip.err(.too_many_args, .{ wip.current.attr, max });
        return true;
    }
    return false;
}

fn argCount(wip: *Wip, count: u32) !bool {
    const actual_count = wip.current.attr.args_len;
    if (actual_count == count) return false;

    switch (count) {
        0 => try wip.err(.arg_count_zero, .{wip.current.attr}),
        1 => try wip.err(.arg_count_one, .{wip.current.attr}),
        else => try wip.err(.arg_count, .{ wip.current.attr, count }),
    }
    return true;
}

fn arg(wip: *Wip, comptime WantedBase: type) !?WantedBase {
    const args = wip.current.attr.args(wip);
    const Wanted = if (@typeInfo(WantedBase) == .optional) blk: {
        if (wip.current.arg_i >= args.len) return @as(WantedBase, null);
        break :blk @typeInfo(WantedBase).optional.child;
    } else WantedBase;
    const arg_res = args[wip.current.arg_i];
    wip.current.arg_i += 1;

    const comp = wip.current.parser.comp;
    const tree = &wip.current.parser.tree;
    const tok = arg_res.node.tok(tree);

    const string = "a string";
    const identifier = "an identifier";
    const int = "an integer constant";
    const expression = "an expression";
    const expected: []const u8 = switch (Wanted) {
        []const u8 => string,
        Tree.Node.DeclRef => identifier,
        else => switch (@typeInfo(Wanted)) {
            .int => int,
            .@"enum" => if (Wanted.opts.enum_kind == .string) string else identifier,
            else => comptime unreachable,
        },
    };

    if (arg_res.val.opt_ref == .none) {
        const node = arg_res.node.get(tree);
        if (Wanted == Tree.Node.DeclRef and node == .decl_ref_expr) {
            return node.decl_ref_expr;
        }
        if (@typeInfo(@TypeOf(Wanted)) == .@"enum" and Wanted.opts.enum_kind == .identifier and node == .identifier_arg) {
            const str = tree.tokSlice(node.identifier_arg.identifier_tok);
            if (Wanted.opts.map.get(str)) |enum_val| return enum_val;

            try wip.errTok(tok, .unknown_enum, .{ wip.current.attr, Parser.ChoicesStr.init(Wanted.opts.map.keys(), null) });
            return null;
        }

        try wip.errTok(tok, .arg_type, .{ expected, wip.current.attr, expression });
        return null;
    }
    const key = comp.interner.get(arg_res.val.ref());
    switch (key) {
        .int => {
            if (@typeInfo(Wanted) == .int) {
                if (arg_res.val.toInt(Wanted, comp)) |some| return some;
                try wip.errTok(tok, .arg_int_out_of_range, .{ wip.current.attr, arg_res });
                return null;
            }
        },
        .bytes => |bytes| {
            const str = bytes[0 .. bytes.len - 1];
            if (Wanted == []const u8) {
                validate: {
                    const node = arg_res.node.get(tree);
                    if (node != .string_literal_expr) break :validate;
                    switch (node.string_literal_expr.qt.childType(comp).get(comp, .int).?) {
                        .char, .uchar, .schar => {},
                        else => break :validate,
                    }
                    return str;
                }

                try wip.errTok(tok, .arg_requires_string, .{wip.current.attr});
                return null;
            } else if (@typeInfo(Wanted) == .@"enum" and Wanted.opts.enum_kind == .string) {
                if (Wanted.opts.map.get(str)) |enum_val| return enum_val;

                try wip.errTok(tok, .unknown_enum, .{ wip.current.attr, Parser.ChoicesStr.init(Wanted.opts.map.keys(), '"') });
                return null;
            }
        },
        else => {},
    }

    try wip.errTok(tok, .arg_type, .{
        expected,
        wip.current.attr,
        switch (key) {
            .int => int,
            .bytes => string,
            .float => "a floating point number",
            .complex => "a complex floating point number",
            .null => "nullptr",
            else => unreachable,
        },
    });
    return null;
}

const Target = enum {
    function,
    function_pointer,
    variable,
    local_variable,
    global_variable,
    label,
    param,
    tag,
    field,
    typedef,

    pub fn str(t: Target) []const u8 {
        return switch (t) {
            .function => "functions",
            .function_pointer => "function pointers",
            .variable => "variables",
            .local_variable => "local variables",
            .global_variable => "global variables",
            .label => "labels",
            .param => "parameters",
            .tag => "tag types",
            .field => "fields",
            .typedef => "typedefs",
        };
    }
};

fn checkTarget(wip: *Wip, list: []const Target) !bool {
    const node = wip.current.node();
    for (list) |target| switch (target) {
        .function => switch (node) {
            .function => return false,
            else => {},
        },
        .function_pointer => {
            const comp = wip.current.parser.comp;
            const qt = wip.current.qt;

            const ptr: TypeStore.Type.Pointer = qt.get(comp, .pointer) orelse continue;
            if (ptr.child.is(comp, .func)) return false;
        },
        .variable => switch (node) {
            .variable => return false,
            else => {},
        },
        .local_variable => switch (node) {
            .variable => |variable| switch (variable.storage_class) {
                .auto, .register => if (wip.current.parser.func.qt != null) return false,
                .@"extern", .static => {},
            },
            else => {},
        },
        .global_variable => switch (node) {
            .variable => |variable| switch (variable.storage_class) {
                .static => {},
                .auto, .register => if (wip.current.parser.func.qt == null) return false,
                .@"extern" => return false,
            },
            else => {},
        },
        .label => switch (node) {
            .labeled_stmt, .default_stmt, .case_stmt => return false,
            else => {},
        },
        .param => switch (node) {
            .param => return false,
            else => {},
        },
        .tag => switch (node) {
            .struct_decl,
            .union_decl,
            .enum_decl,
            .struct_forward_decl,
            .union_forward_decl,
            .enum_forward_decl,
            => return false,
            else => {},
        },
        .field => switch (node) {
            .enum_field, .record_field => return false,
            else => {},
        },
        .typedef => switch (node) {
            .typedef => return false,
            else => {},
        },
    };

    try wip.err(.invalid_target, .{ wip.current.attr, Parser.Choices(Target).init(list, null) });
    return true;
}

fn incompatible(wip: *Wip, attr: Attribute.Tag) !void {
    const am = &wip.current.parser.tree.attr_map;
    var i: usize = 0;
    while (i < wip.applied.items.len) {
        const prev_attr = am.get(wip.applied.items[i]);
        if (prev_attr.args == attr) {
            try wip.err(.incompatible_attr, .{ wip.current.attr, prev_attr });
            try wip.errTok(prev_attr.tok, .conflicting_attribute, .{});
            _ = wip.applied.orderedRemove(i);
            continue;
        }
        i += 1;
    }
}

fn add(wip: *Wip, args: Attribute.Args) !void {
    const parser = wip.current.parser;
    const gpa = parser.comp.gpa;
    const current = wip.current.attr;
    const ref = try parser.tree.attr_map.put(gpa, .{
        .args = args,
        .name = current.name,
        .syntax = current.syntax,
        .tok = current.tok,
    });
    try wip.applied.append(gpa, ref);
}

pub fn applyDeclAttrs(wip: *Wip, p: *Parser, decl: Tree.Node.Index, prev_decl: Tree.Node.OptIndex) !void {
    return wip.applyDeclAttrsExtra(p, decl, decl.qt(&p.tree), prev_decl);
}

pub fn applyDeclAttrsExtra(
    wip: *Wip,
    p: *Parser,
    decl: Tree.Node.Index,
    qt: QualType,
    prev_decl: Tree.Node.OptIndex,
) !void {
    wip.applied.items.len = 0;
    wip.current = .{
        .attr = undefined,
        .target = decl,
        .qt = qt,
        .parser = p,
    };

    if (prev_decl.unpack()) |prev| try wip.inherit(p, prev);

    for (wip.attrs.items[wip.top..]) |*attr| {
        if (attr.used_as_type_attr) continue;
        wip.current.attr = attr;
        wip.current.arg_i = 0;

        switch (attr.name) {
            .standard => |standard_attr| switch (standard_attr) {
                .deprecated => try wip.applyDeprecated(),
                .nodiscard => try wip.applyWarnUnusedResult(),
                .noreturn, ._Noreturn => try wip.applyNoreturn(),
                else => {
                    try wip.err(.unimplemented, .{attr});
                },
            },
            .gnu => |gnu_attr| switch (gnu_attr) {
                .@"packed" => {
                    if (try wip.checkTarget(&.{ .tag, .field })) continue;
                    if (try wip.argCount(0)) continue;
                    try wip.add(.@"packed");
                },
                .cold => {
                    if (try wip.checkTarget(&.{.function})) continue;
                    if (try wip.argCount(0)) continue;
                    try wip.incompatible(.hot);
                    try wip.add(.cold);
                },
                .hot => {
                    if (try wip.checkTarget(&.{.function})) continue;
                    if (try wip.argCount(0)) continue;
                    try wip.incompatible(.cold);
                    try wip.add(.hot);
                },
                .@"const", .__const => {
                    if (try wip.argCount(0)) continue;
                    try wip.add(.@"const");
                },
                .aligned => try wip.applyAlignment(),
                .deprecated => try wip.applyDeprecated(),
                .warning => {
                    if (try wip.checkTarget(&.{.function})) continue;
                    if (try wip.argCount(1)) continue;

                    const msg = (try wip.arg([]const u8)) orelse continue;
                    try wip.add(.{ .warning = msg });
                },
                .@"error" => {
                    if (try wip.checkTarget(&.{.function})) continue;
                    if (try wip.argCount(1)) continue;

                    const msg = (try wip.arg([]const u8)) orelse continue;
                    try wip.add(.{ .@"error" = msg });
                },
                .warn_unused_result => try wip.applyWarnUnusedResult(),
                .nonnull => try wip.applyNonnull(),
                .transparent_union => try wip.applyTransparentUnion(),
                .designated_init => {
                    if (wip.current.node() != .struct_decl) {
                        try wip.err(.designated_init_invalid, .{wip.current.attr});
                        continue;
                    }
                    if (try wip.argCount(0)) return;
                    try wip.add(.designated_init);
                },
                .cdecl,
                .fastcall,
                .ms_abi,
                .pcs,
                .regcall,
                .stdcall,
                .sysv_abi,
                .thiscall,
                => try wip.applyCallingConvention(),
                .visibility => try wip.applyVisibility(),
                .noreturn => try wip.applyNoreturn(),
                .cleanup => try wip.applyCleanup(),
                .always_inline => try wip.applyAlwaysInline(),
                .gnu_inline => try wip.applyGnuInline(),
                .section => try wip.applySection(),
                .weak => {
                    if (try wip.checkTarget(&.{ .function, .variable })) continue;
                    if (try wip.argCount(0)) continue;
                    try wip.add(.weak);
                },
                .selectany => {
                    if (try wip.argCount(0)) continue;
                    try wip.add(.selectany);
                },
                else => {
                    try wip.err(.unimplemented, .{attr});
                },
            },
            .clang => |clang_attr| switch (clang_attr) {
                .unavailable => {
                    if (try wip.argCountMinMax(0, 1)) continue;

                    const maybe_msg = (try wip.arg(?[]const u8)) orelse continue;
                    try wip.add(.{ .unavailable = maybe_msg });
                },
                .aarch64_sve_pcs,
                .aarch64_vector_pcs,
                .riscv_vector_cc,
                .riscv_vls_cc,
                .vectorcall,
                => try wip.applyCallingConvention(),
                .always_inline => try wip.applyAlwaysInline(),
                .internal_linkage => {
                    if (try wip.checkTarget(&.{ .function, .variable })) continue;
                    if (try wip.argCount(0)) continue;
                    try wip.add(.internal_linkage);
                },
                else => {
                    try wip.err(.unimplemented, .{attr});
                },
            },
            .aro => {
                try wip.err(.unimplemented, .{attr});
            },
            .declspec => |declspec_attr| switch (declspec_attr) {
                .@"align" => try wip.applyAlignment(),
                .deprecated => try wip.applyDeprecated(),
                .noreturn => try wip.applyNoreturn(),
                .allocate => try wip.applySection(),
                .selectany => {
                    if (try wip.argCount(0)) continue;
                    try wip.add(.selectany);
                },
                else => {
                    try wip.err(.unimplemented, .{attr});
                },
            },
            .msvc => {
                try wip.err(.unimplemented, .{attr});
            },
            .riscv => |riscv_attr| switch (riscv_attr) {
                .vector_cc,
                .vls_cc,
                => try wip.applyCallingConvention(),
            },
            .keyword => |keyword_attr| switch (keyword_attr) {
                ._Alignas, .alignas => try wip.applyAlignment(),
                ._cdecl,
                .__cdecl,
                ._fastcall,
                .__fastcall,
                ._regcall,
                ._stdcall,
                .__stdcall,
                ._thiscall,
                .__thiscall,
                ._vectorcall,
                .__vectorcall,
                => try wip.applyCallingConvention(),
                .noreturn => try wip.applyNoreturn(),
                ._forceinline, .__forceinline => try wip.applyAlwaysInline(),
                else => {
                    try wip.err(.unimplemented, .{attr});
                },
            },
        }
    }

    try wip.checkLinkageAttrs();

    try wip.addAppliedAttrs();
}

fn inherit(wip: *Wip, p: *Parser, decl: Tree.Node.Index) !void {
    const gpa = p.comp.gpa;
    const am = &p.tree.attr_map;
    for (am.attrs(decl)) |ref| {
        const attr = am.get(ref);

        switch (attr.args) {
            .@"packed",
            .hot,
            .cold,
            .@"const",
            .deprecated,
            .unavailable,
            .@"error",
            .warning,
            .visibility,
            .noreturn,
            .cleanup,
            .always_inline,
            .gnu_inline,
            => {},
            .alignment => {
                try wip.addAlignmentToTypeMap(attr.args.alignment);
            },
            else => continue,
        }

        try wip.applied.append(gpa, ref);
    }
}

fn checkLinkageAttrs(wip: *Wip) !void {
    const am = &wip.current.parser.tree.attr_map;

    const internal_linkage = blk: {
        for (wip.applied.items) |ref| {
            const attr = am.get(ref);
            if (attr.args == .internal_linkage) break :blk true;
        }

        break :blk switch (wip.current.node()) {
            .function => |function| function.static,
            .variable => |variable| switch (variable.storage_class) {
                .static => true,
                .@"extern" => false,
                .auto, .register => wip.current.parser.func.qt != null,
            },
            else => false,
        };
    };

    const remove_weak = internal_linkage;
    const remove_selectany = internal_linkage or wip.current.node() == .function;

    var err_weak = false;
    var err_selectany = false;

    var i: usize = 0;
    for (wip.applied.items) |ref| {
        const attr = am.get(ref);
        if (attr.args == .weak and remove_weak) {
            if (!err_weak) {
                try wip.errTok(attr.tok, .invalid_weak, .{attr});
                err_weak = true;
            }
            continue;
        }
        if (attr.args == .selectany and remove_selectany) {
            if (!err_selectany) {
                try wip.errTok(attr.tok, .invalid_selectany, .{attr});
                err_selectany = true;
            }
            continue;
        }
        wip.applied.items[i] = ref;
        i += 1;
    }
    wip.applied.items.len = i;
}

fn applyAlignment(wip: *Wip) !void {
    const qt = wip.current.qt;
    if (qt.isInvalid()) return;
    if (try wip.argCountMinMax(0, 1)) return;
    const is_alignas = wip.current.attr.syntax == .keyword;
    if (is_alignas) {
        switch (wip.current.node()) {
            .variable,
            .struct_decl,
            .union_decl,
            .enum_decl,
            .struct_forward_decl,
            .union_forward_decl,
            .enum_forward_decl,
            => {},
            .record_field => |field| if (field.bit_width != null) {
                try wip.err(.alignas_bitfield, .{wip.current.attr});
                return;
            },
            .param => {
                try wip.err(.alignas_on_param, .{wip.current.attr});
                return;
            },
            else => {
                try wip.err(.alignas_on_func, .{wip.current.attr});
                return;
            },
        }
    } else if (try wip.checkTarget(&.{ .function, .variable, .typedef, .tag, .param, .field })) return;

    const comp = wip.current.parser.comp;

    const alignas_requested = if (is_alignas) blk: {
        const args = wip.current.attr.args(wip);
        const arg_res = args[wip.current.arg_i];
        const node = arg_res.node.get(&wip.current.parser.tree);
        if (node != .alignas_type) break :blk null;
        break :blk node.alignas_type.qt.alignof(comp);
    } else null;
    const maybe_requested = alignas_requested orelse (try wip.arg(?i64)) orelse return;
    var casted: ?u32 = null;

    if (maybe_requested) |requested| {
        if (requested < 0) {
            try wip.err(.negative_alignment, .{requested});
            return;
        }
        if (requested > std.math.maxInt(u32)) {
            try wip.err(.maximum_alignment, .{requested});
            return;
        }
        if (!std.mem.isValidAlign(@intCast(requested))) {
            try wip.err(.non_pow2_align, .{});
            return;
        }
        if (is_alignas) {
            const default_align = qt.alignof(comp);
            if (is_alignas and requested < default_align) {
                try wip.err(.minimum_alignment, .{default_align});
            }
        }
        casted = @intCast(requested);
    }
    if (comp.langopts.emulate == .msvc) {
        switch (wip.current.node()) {
            .enum_forward_decl, .enum_decl => {
                try wip.err(.msvc_enum_align_ignored, .{});
                return;
            },
            else => {},
        }
    }
    try wip.addAlignmentToTypeMap(casted);
    try wip.add(.{ .alignment = casted });
}

fn addAlignmentToTypeMap(wip: *Wip, opt_alignment: ?u32) !void {
    const comp = wip.current.parser.comp;
    const qt = wip.current.qt;
    switch (wip.current.node()) {
        .typedef => assert(qt.type(comp) == .typedef),
        .enum_forward_decl, .enum_decl => assert(qt.type(comp) == .@"enum"),
        else => return,
    }
    const alignment = opt_alignment orelse comp.target.defaultAlignment();
    const gop = try comp.type_store.requested_aligns.getOrPut(comp.gpa, qt);
    if (gop.found_existing) {
        gop.value_ptr.* = @max(gop.value_ptr.*, alignment);
    } else {
        gop.value_ptr.* = alignment;
    }
}

fn addAppliedAttrs(wip: *Wip) !void {
    const gpa = wip.current.parser.comp.gpa;
    const am = &wip.current.parser.tree.attr_map;
    const start_index = am.extra.items.len;

    try am.extra.appendSlice(gpa, @ptrCast(wip.applied.items));
    try am.decl_attrs.put(gpa, wip.current.target.?, .{ @intCast(start_index), @intCast(wip.applied.items.len) });
}

fn applyDeprecated(wip: *Wip) !void {
    const max_args: u8 = if (wip.current.attr.syntax == .gnu) 2 else 1;
    if (try wip.argCountMinMax(0, max_args)) return;

    const maybe_msg = (try wip.arg(?[]const u8)) orelse return;
    const maybe_replacement = (try wip.arg(?[]const u8)) orelse return;

    try wip.add(.{ .deprecated = .{
        .msg = maybe_msg,
        .replacement = maybe_replacement,
    } });
}

fn applyWarnUnusedResult(wip: *Wip) !void {
    if (try wip.checkTarget(if (wip.current.attr.syntax == .standard)
        &.{ .function, .tag }
    else
        &.{ .function, .tag, .function_pointer, .typedef })) return;

    const max_args: u8 = if (wip.current.attr.syntax == .standard) 1 else 0;
    if (try wip.argCountMinMax(0, max_args)) return;

    const maybe_msg = (try wip.arg(?[]const u8)) orelse return;

    const comp = wip.current.parser.comp;
    if (wip.current.qt.getFunc(comp)) |func| {
        if (func.return_type.is(comp, .void)) {
            try wip.err(.warn_unused_result_void, .{wip.current.attr});
            return;
        }
    }

    try wip.add(.{ .warn_unused_result = maybe_msg });
}

fn applyNonnull(wip: *Wip) !void {
    const parser = wip.current.parser;
    const comp = parser.comp;
    const qt = wip.current.qt;
    if (qt.isInvalid()) return;
    if (try wip.checkTarget(&.{ .function, .function_pointer, .param })) return;
    if (wip.current.node() == .param) {
        if (wip.current.attr.args_len != 0) {
            try wip.err(.nonnull_param_args, .{wip.current.attr});
            return;
        }
        if (!qt.isPointer(comp)) {
            try wip.err(.nonnull_pointer_only, .{wip.current.attr});
            return;
        }
        // TODO these should also be inherited
        try wip.add(.{ .nonnull = &.{} });
        return;
    }

    const list_buf_top = parser.list_buf.items.len;
    defer parser.list_buf.items.len = list_buf_top;
    try parser.list_buf.ensureUnusedCapacity(comp.gpa, wip.current.attr.args_len);

    const func_ty = qt.getFunc(comp).?;
    for (wip.current.attr.args(wip), 0..) |arg_res, i| {
        const position = (try wip.arg(u32)) orelse return;
        const tok = arg_res.node.tok(&parser.tree);

        if (position == 0 or position > func_ty.params.len) {
            try wip.errTok(tok, .param_out_of_bounds, .{ wip.current.attr, i + 1 });
            return;
        }

        const arg_qt = func_ty.params[position - 1].qt;
        if (arg_qt.isInvalid()) continue;
        if (!arg_qt.isPointer(comp)) {
            try wip.errTok(tok, .nonnull_pointer_only, .{wip.current.attr});
            continue;
        }
        parser.list_buf.appendAssumeCapacity(@enumFromInt(position));
    }
    try wip.add(.{ .nonnull = @ptrCast(parser.list_buf.items[list_buf_top..]) });
}

fn applyTransparentUnion(wip: *Wip) !void {
    const qt = wip.current.qt;
    if (qt.isInvalid()) return;
    const fields = switch (wip.current.node()) {
        .union_decl => |decl| decl.fields,
        .union_forward_decl => {
            try wip.err(.transparent_union_forward_decl, .{wip.current.attr});
            return;
        },
        else => {
            try wip.err(.transparent_union_wrong_type, .{wip.current.attr});
            return;
        },
    };
    if (try wip.argCount(0)) return;

    const parser = wip.current.parser;
    const comp = parser.comp;
    const tree = &parser.tree;

    if (fields.len == 0) {
        try wip.err(.transparent_union_one_field, .{wip.current.attr});
        return;
    }
    var opt_first_field_size: ?u64 = null;
    for (fields) |field| {
        const field_size = (field.qt(tree).sizeofOrNull(comp) orelse continue) * 8;
        const first_field_size = opt_first_field_size orelse {
            opt_first_field_size = field_size;
            continue;
        };
        if (field_size == first_field_size) continue;

        const field_tok = field.tok(tree);
        try wip.errTok(field_tok, .transparent_union_size, .{ parser.tokSlice(field_tok), field_size, wip.current.attr });
        try wip.errTok(fields[0].tok(tree), .transparent_union_size_note, .{first_field_size});
        return;
    }

    try wip.add(.transparent_union);
}

fn applyVisibility(wip: *Wip) !void {
    if (try wip.checkTarget(&.{ .function, .global_variable })) return;
    if (try wip.argCount(1)) return;

    var kind = (try wip.arg(Attribute.Args.Visibility)) orelse return;
    if (kind == .protected and !wip.current.parser.comp.target.hasProtectedVisibility()) {
        try wip.err(.visibility_protected_invalid, .{});
        kind = .default;
    }

    const am = &wip.current.parser.tree.attr_map;
    for (wip.applied.items, 0..) |ref, i| {
        const prev_attr = am.get(ref);
        if (prev_attr.args == .visibility) {
            if (prev_attr.args.visibility == kind) {
                _ = wip.applied.orderedRemove(i);
                break;
            }

            try wip.err(.incompatible_visibility, .{});
            try wip.errTok(prev_attr.tok, .previous_attribute, .{});
            return;
        }
    }

    try wip.add(.{ .visibility = kind });
}

fn applyNoreturn(wip: *Wip) !void {
    if (try wip.checkTarget(&.{.function})) return;
    if (try wip.argCount(0)) return;

    const name = wip.current.attr.name;
    if (name == .standard and name.standard == ._Noreturn) {
        try wip.err(.deprecated_noreturn, .{});
    }

    try wip.add(.noreturn);
}

fn applyCleanup(wip: *Wip) !void {
    const qt = wip.current.qt;
    if (qt.isInvalid()) return;
    if (try wip.checkTarget(&.{.local_variable})) return;
    if (try wip.argCount(1)) return;

    const decl_ref = (try wip.arg(Tree.Node.DeclRef)) orelse return;

    const decl_node = decl_ref.decl.get(&wip.current.parser.tree);
    if (decl_node != .function) {
        try wip.err(.cleanup_non_function, .{ wip.current.attr, wip.current.parser.tokSlice(decl_ref.name_tok) });
        return;
    }
    const comp = wip.current.parser.comp;
    const func: Type.Func = decl_node.function.qt.get(comp, .func).?;

    if (func.params.len != 1) {
        try wip.err(.cleanup_one_arg, .{ wip.current.attr, wip.current.parser.tokSlice(decl_ref.name_tok) });
        return;
    }

    const expected_qt = try comp.type_store.put(comp.gpa, .{ .pointer = .{
        .child = qt,
    } });
    const actual_qt = func.params[0].qt;
    if (!actual_qt.eql(expected_qt, comp)) {
        try wip.err(.cleanup_arg_ty, .{ wip.current.attr, wip.current.parser.tokSlice(decl_ref.name_tok), actual_qt, expected_qt });
        return;
    }

    try wip.add(.{ .cleanup = .{ .function = decl_ref.decl } });
}

fn applyAlwaysInline(wip: *Wip) !void {
    if (try wip.checkTarget(&.{.function})) return;
    if (try wip.argCount(0)) return;

    const am = &wip.current.parser.tree.attr_map;
    for (wip.applied.items) |ref| {
        const prev_attr = am.get(ref);
        if (prev_attr.args == .optnone) {
            try wip.err(.ignored_attribute, .{wip.current.attr});
            try wip.errTok(prev_attr.tok, .conflicting_attribute, .{});
            return;
        }
        if (prev_attr.args == .always_inline) return;
    }

    try wip.add(.always_inline);
}

fn applyGnuInline(wip: *Wip) !void {
    if (try wip.checkTarget(&.{.function})) return;
    if (try wip.argCount(0)) return;

    const node = wip.current.node();
    if (!node.function.@"inline") {
        try wip.err(.gnu_inline_non_inline, .{wip.current.attr});
        return;
    }

    try wip.add(.gnu_inline);
}

fn applySection(wip: *Wip) !void {
    if (try wip.checkTarget(&.{ .function, .global_variable })) return;
    if (try wip.argCount(1)) return;

    const section_name = (try wip.arg([]const u8)) orelse return;
    // TODO Mach-O section name validation

    const am = &wip.current.parser.tree.attr_map;
    for (wip.applied.items) |ref| {
        const prev_attr = am.get(ref);
        if (prev_attr.args == .section) {
            if (std.mem.eql(u8, prev_attr.args.section, section_name)) return;

            try wip.err(.conflicting_section_name, .{wip.current.attr});
            try wip.errTok(prev_attr.tok, .conflicting_attribute, .{});
            return;
        }
    }

    try wip.add(.{ .section = section_name });
}

pub fn applyTypeAttrs(wip: *Wip, p: *Parser, qt: QualType) !QualType {
    wip.current = .{
        .attr = undefined,
        .qt = qt,
        .parser = p,
    };

    for (wip.attrs.items[wip.top..]) |*attr| {
        if (attr.used_as_type_attr) continue;
        wip.current.attr = attr;
        wip.current.arg_i = 0;

        switch (attr.name) {
            .gnu => |gnu_attr| switch (gnu_attr) {
                .vector_size => {
                    try wip.applyVectorSize();
                    attr.used_as_type_attr = true;
                },
                .cdecl,
                .fastcall,
                .ms_abi,
                .pcs,
                .regcall,
                .stdcall,
                .sysv_abi,
                .thiscall,
                => try wip.applyCallingConvention(),
                .regparm,
                .riscv_rvv_vector_bits,
                => {
                    try wip.err(.unimplemented, .{attr});
                    attr.used_as_type_attr = true;
                },
                else => {},
            },
            .clang => |clang_attr| switch (clang_attr) {
                .neon_vector_type => {
                    try wip.applyNeonVector(.neon);
                    attr.used_as_type_attr = true;
                },
                .neon_polyvector_type => {
                    try wip.applyNeonVector(.neon_poly);
                    attr.used_as_type_attr = true;
                },
                .aarch64_sve_pcs,
                .aarch64_vector_pcs,
                .riscv_vector_cc,
                .riscv_vls_cc,
                .vectorcall,
                => try wip.applyCallingConvention(),
                .address_space,
                .arm_sve_vector_bits,
                .ext_vector_type,
                .matrix_type,
                .noderef,
                => {
                    try wip.err(.unimplemented, .{attr});
                    attr.used_as_type_attr = true;
                },
                else => {},
            },
            .riscv => |riscv_attr| switch (riscv_attr) {
                .vector_cc,
                .vls_cc,
                => try wip.applyCallingConvention(),
            },
            .keyword => |keyword_attr| switch (keyword_attr) {
                ._cdecl,
                .__cdecl,
                ._fastcall,
                .__fastcall,
                ._regcall,
                ._stdcall,
                .__stdcall,
                ._thiscall,
                .__thiscall,
                ._vectorcall,
                .__vectorcall,
                => try wip.applyCallingConvention(),
                .nonnull,
                .null_unspecified,
                .nullable_result,
                .nullable,
                => try wip.applyNullability(),
                .ptr32,
                .ptr64,
                .sptr,
                .uptr,
                => {
                    try wip.err(.unimplemented, .{attr});
                    attr.used_as_type_attr = true;
                },
                else => {},
            },
            else => {},
        }
    }
    return wip.current.qt;
}

fn applyVectorSize(wip: *Wip) !void {
    const qt = wip.current.qt;
    if (qt.isInvalid()) return;
    if (try wip.argCount(1)) return;

    if (qt.isAuto()) {
        try wip.err(.invalid_vec_elem_ty, .{qt});
        return error.ParsingFailed;
    }

    const comp = wip.current.parser.comp;

    const scalar_kind = qt.scalarKind(comp);
    if (scalar_kind != .int and scalar_kind != .float) {
        if (qt.get(comp, .@"enum")) |enum_ty| {
            if (comp.langopts.emulate == .clang and enum_ty.incomplete) {
                return; // Clang silently ignores vector_size on incomplete enums.
            }
        }
        try wip.err(.invalid_vec_elem_ty, .{qt});
        return error.ParsingFailed;
    }
    if (qt.get(comp, .bit_int)) |bit_int| {
        if (bit_int.bits < 8) {
            try wip.err(.bit_int_vec_too_small, .{});
            return error.ParsingFailed;
        } else if (!std.math.isPowerOfTwo(bit_int.bits)) {
            try wip.err(.bit_int_vec_not_pow2, .{});
            return error.ParsingFailed;
        }
    }

    const vec_bytes = (try wip.arg(u32)) orelse return;
    const elem_size = qt.sizeof(comp);
    if (vec_bytes % elem_size != 0) {
        return wip.err(.vec_size_not_multiple, .{});
    }

    wip.current.qt = try comp.type_store.put(comp.gpa, .{ .vector = .{
        .elem = qt,
        .len = @intCast(vec_bytes / elem_size),
    } });
}

fn applyNeonVector(wip: *Wip, kind: Type.Vector.Kind) !void {
    const qt = wip.current.qt;
    if (qt.isInvalid()) return;
    if (try wip.argCount(1)) return;

    if (qt.isAuto()) {
        try wip.err(.invalid_vec_elem_ty, .{qt});
        return error.ParsingFailed;
    }

    const comp = wip.current.parser.comp;

    const valid_elem_ty = blk: {
        if (kind == .neon_poly) {
            const int_ty = qt.get(comp, .int) orelse break :blk false;
            const poly_unsigned = comp.target.cpu.arch.isAARCH64();
            break :blk if (poly_unsigned)
                switch (int_ty) {
                    .uchar, .ushort, .ulong, .ulong_long => true,
                    else => false,
                }
            else switch (int_ty) {
                .schar, .short, .long_long => true,
                else => false,
            };
        }

        const base_ty = qt.base(comp).type;
        break :blk switch (base_ty) {
            .int => |int| switch (int) {
                .schar, .uchar, .short, .ushort, .int, .uint, .long, .ulong, .long_long, .ulong_long => true,
                else => false,
            },
            .float => |float| switch (float) {
                .float, .fp16, .bf16 => true,
                .double => comp.target.cpu.arch.isAARCH64(),
                else => false,
            },
            .storage_float => |storage_float| switch (storage_float) {
                .mfp8 => true,
            },
            else => false,
        };
    };
    if (!valid_elem_ty) {
        try wip.err(.invalid_vec_elem_ty, .{qt});
        return;
    }

    // Neon vector size must be 64 or 128 bits
    const elem_size = qt.bitSizeof(comp);
    const vec_len = (try wip.arg(u32)) orelse return;
    const vec_size = elem_size * vec_len;
    if (vec_size != 64 and vec_size != 128) {
        try wip.err(.invalid_neon_vec_size, .{});
        return;
    }

    wip.current.qt = try comp.type_store.put(comp.gpa, .{ .vector = .{
        .elem = qt,
        .len = vec_len,
        .kind = kind,
    } });
}

fn applyCallingConvention(wip: *Wip) !void {
    const attr = wip.current.attr;
    attr.used_as_type_attr = true;
    const qt = wip.current.qt;
    if (qt.isInvalid()) return;

    const arg_count: u8 = if (attr.name == .gnu and attr.name.gnu == .pcs) 1 else 0;
    if (try wip.argCount(arg_count)) return;

    const comp = wip.current.parser.comp;
    const base_qt, var func: Type.Func = blk: {
        const can_delay = attr.syntax != .standard and wip.current.target == null;

        var base_qt = qt;
        while (true) {
            if (base_qt.isInvalid()) return;
            if (base_qt.isAuto()) {
                if (can_delay) {
                    attr.used_as_type_attr = false;
                    return;
                }
                try wip.err(.callconv_non_func, .{ attr, qt });
                return;
            }

            if (base_qt._index == .declarator_combine) {
                // Incomplete declarator, try again later.
                attr.used_as_type_attr = false;
                return;
            }
            const base = base_qt.base(comp);
            switch (base.type) {
                .func => |func| break :blk .{ base.qt, func },
                .pointer => |pointer| {
                    base_qt = pointer.child;
                },
                else => {
                    if (can_delay) {
                        // __attribute__ or keyword used in wrong place, try again later.
                        attr.used_as_type_attr = false;
                        return;
                    }
                    try wip.err(.callconv_non_func, .{ attr, qt });
                    return;
                },
            }
        }
    };

    const cc: Type.Func.CallingConvention = switch (attr.name) {
        .gnu => |gnu_attr| switch (gnu_attr) {
            .cdecl => .cdecl,
            .fastcall => .fastcall,
            .ms_abi => .ms_abi,
            .regcall => .regcall,
            .stdcall => .stdcall,
            .sysv_abi => .sysv_abi,
            .thiscall => .thiscall,
            .pcs => pcs: {
                const PcsKind = enum {
                    aapcs,
                    aapcs_vfp,

                    const PcsKind = @This();
                    const opts = struct {
                        const enum_kind = .string;
                        const map = std.StaticStringMap(PcsKind).initComptime(.{
                            .{ "aapcs", .aapcs },
                            .{ "aapcs-vfp", .aapcs_vfp },
                        });
                    };
                };
                break :pcs switch ((try wip.arg(PcsKind)) orelse return) {
                    .aapcs => .arm_aapcs,
                    .aapcs_vfp => .arm_aapcs_vfp,
                };
            },
            else => unreachable,
        },
        .clang => |clang_attr| switch (clang_attr) {
            .aarch64_sve_pcs => .aarch64_sve_pcs,
            .aarch64_vector_pcs => .aarch64_vector_pcs,
            .riscv_vector_cc => .riscv_vector_cc,
            .riscv_vls_cc => .riscv_vls_cc,
            .vectorcall => .vectorcall,
            else => unreachable,
        },
        .riscv => |riscv_attr| switch (riscv_attr) {
            .vector_cc => .riscv_vector_cc,
            .vls_cc => .riscv_vls_cc,
        },
        .keyword => |keyword_attr| switch (keyword_attr) {
            .__cdecl, ._cdecl => .cdecl,
            .__fastcall, ._fastcall => .fastcall,
            ._regcall => .regcall,
            .__stdcall, ._stdcall => .stdcall,
            .__thiscall, ._thiscall => .thiscall,
            .__vectorcall, ._vectorcall => .vectorcall,
            else => unreachable,
        },
        else => unreachable,
    };

    const ms_abi = comp.target.os.tag == .windows or comp.target.os.tag == .uefi;
    const supported = check: switch (cc) {
        .default => unreachable,
        .cdecl => !(comp.target.cpu.arch.isArm() and comp.target.os.tag != .windows) and
            !comp.target.cpu.arch.isPowerPC64() and
            !comp.target.cpu.arch.isSpirV(),
        .aarch64_sve_pcs, .aarch64_vector_pcs => comp.target.cpu.arch.isAARCH64(),
        .arm_aapcs_vfp, .arm_aapcs => comp.target.cpu.arch.isArm(),
        .riscv_vector_cc, .riscv_vls_cc => comp.target.cpu.arch.isRISCV(),
        .ms_abi => if (ms_abi) continue :check .cdecl else (comp.target.cpu.arch == .x86_64 or comp.target.cpu.arch.isAARCH64()),
        .sysv_abi => if (ms_abi) comp.target.cpu.arch == .x86_64 else continue :check .cdecl,
        .fastcall, .regcall, .stdcall, .thiscall => comp.target.cpu.arch == .x86,
        .vectorcall => comp.target.cpu.arch == .x86 or comp.target.cpu.arch == .x86_64 or comp.target.cpu.arch.isAARCH64(),
    };
    if (!supported) {
        try wip.err(.callconv_not_supported, .{attr});
        return;
    }

    if (func.cc != cc and func.cc != .default) {
        try wip.err(.callconv_incompatible, .{ @tagName(cc), @tagName(func.cc) });
        return;
    }
    func.cc = cc;

    // We cannot pass the function type directly here because the pointer to
    // type_store.extra might get invalidated while setting the updated type.
    const lb = &wip.current.parser.list_buf;
    const list_buf_top = lb.items.len;
    defer lb.items.len = list_buf_top;
    try lb.appendSlice(comp.gpa, @ptrCast(func.params));
    func.params = @ptrCast(lb.items[list_buf_top..]);

    // TODO this can overwrite a typedef
    // typedef void (*fn_ptr)(void);
    // __cdecl fn_ptr a;
    try comp.type_store.set(comp.gpa, .{ .func = func }, @intFromEnum(base_qt._index));
}

fn applyNullability(wip: *Wip) !void {
    const attr = wip.current.attr;
    attr.used_as_type_attr = true;
    const qt = wip.current.qt;
    if (qt.isInvalid()) return;

    const comp = wip.current.parser.comp;
    var pointer: Type.Pointer = qt.get(comp, .pointer) orelse {
        if (wip.current.target == null and qt.is(comp, .array)) {
            attr.used_as_type_attr = false;
            return;
        }

        try wip.err(.invalid_nullability, .{qt});
        return;
    };

    const new_nullability: Type.Pointer.Nullability = switch (attr.name.keyword) {
        .nonnull => .nonnull,
        .null_unspecified => .unspecified,
        .nullable_result => .nullable_result,
        .nullable => .nullable,
        else => unreachable,
    };
    if (pointer.nullability != .default and pointer.nullability != new_nullability) {
        try wip.err(.conflicting_nullability, .{ new_nullability.str(), pointer.nullability.str() });
        return;
    }

    pointer.nullability = new_nullability;
    wip.current.qt = try comp.type_store.put(comp.gpa, .{ .pointer = pointer });
}

pub fn applyStmtAttrs(wip: *Wip, p: *Parser, stmt: Tree.Node.Index) !void {
    wip.applied.items.len = 0;
    wip.current = .{
        .attr = undefined,
        .qt = .invalid,
        .target = stmt,
        .parser = p,
    };

    for (wip.attrs.items[wip.top..]) |*attr| {
        wip.current.attr = attr;
        wip.current.arg_i = 0;

        switch (attr.name) {
            .standard => |standard_attr| switch (standard_attr) {
                .fallthrough => {
                    try wip.applyFalltrhough();
                    continue;
                },
                else => {},
            },
            .gnu => |gnu_attr| switch (gnu_attr) {
                .fallthrough => {
                    try wip.applyFalltrhough();
                    continue;
                },
                .always_inline => {}, // invalid, use clang::always_inline
                else => {},
            },
            .clang => |clang_attr| switch (clang_attr) {
                .always_inline => {},
                else => {},
            },
            .aro => {},
            .declspec => {},
            .msvc => {},
            .riscv => {},
            .keyword => {},
        }

        try wip.err(.invalid_stmt_attr, .{attr});
    }

    try wip.addAppliedAttrs();
}

fn applyFalltrhough(wip: *Wip) !void {
    if (try wip.argCount(0)) return;
    if (wip.current.node() != .null_stmt) {
        try wip.err(.fallthrough_non_empty, .{wip.current.attr});
        return;
    }
    if (wip.current.parser.@"switch" == null) {
        try wip.err(.fallthrough_outside_switch, .{wip.current.attr});
        return;
    }
    for (wip.current.parser.tok_ids[wip.current.parser.tok_i..]) |tok_id| {
        switch (tok_id) {
            .keyword_case, .keyword_default, .eof => break,
            .r_brace, .semicolon => {},
            else => {
                try wip.err(.fallthrough_not_before_case, .{wip.current.attr});
                break;
            },
        }
    }

    try wip.add(.fallthrough);
}
