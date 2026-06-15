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
    attr: *const Parsed,
    target: ?Tree.Node.Index = null,
    args: []const Parser.Result,
    parser: *Parser,
    arg_i: u32 = 0,

    fn node(c: *const @This()) Tree.Node {
        return c.target.?.get(&c.parser.tree);
    }

    fn qt(c: *const @This()) QualType {
        return c.target.?.qt(&c.parser.tree);
    }

    fn tok(c: *const @This()) TokenIndex {
        return c.args[c.arg_i - 1].node.tok(&c.parser.tree);
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
    const actual_count = wip.current.args.len;

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
    const actual_count = wip.current.args.len;
    if (actual_count == count) return false;

    switch (count) {
        0 => try wip.err(.arg_count_zero, .{wip.current.attr}),
        1 => try wip.err(.arg_count_one, .{wip.current.attr}),
        else => try wip.err(.arg_count, .{ wip.current.attr, count }),
    }
    return true;
}

fn arg(wip: *Wip, comptime WantedBase: type) !?WantedBase {
    const Wanted = if (@typeInfo(WantedBase) == .optional) blk: {
        if (wip.current.arg_i >= wip.current.args.len) return @as(WantedBase, null);
        break :blk @typeInfo(WantedBase).optional.child;
    } else WantedBase;
    const arg_res = wip.current.args[wip.current.arg_i];
    wip.current.arg_i += 1;

    const comp = wip.current.parser.comp;
    const tok = wip.current.tok();

    const string = "a string";
    const identifier = "an identifier";
    const int = "an integer constant";
    const expression = "an expression";
    const expected: []const u8 = switch (Wanted) {
        []const u8 => string,
        Tree.Node.DeclRef => identifier,
        // Alignment => alignment,
        else => switch (@typeInfo(Wanted)) {
            .int => int,
            .@"enum" => if (Wanted.opts.enum_kind == .string) string else identifier,
            else => unreachable,
        },
    };

    if (arg_res.val.opt_ref == .none) {
        const node = arg_res.node.get(&wip.current.parser.tree);
        if (Wanted == Tree.Node.DeclRef and node == .decl_ref_expr) {
            return node.decl_ref_expr;
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
                    const node = arg_res.node.get(&wip.current.parser.tree);
                    if (node != .string_literal_expr) break :validate;
                    switch (node.string_literal_expr.qt.childType(comp).get(comp, .int).?) {
                        .char, .uchar, .schar => {},
                        else => break :validate,
                    }
                    return str;
                }

                try wip.errTok(tok, .arg_requires_string, .{wip.current.attr});
                return null;
            } else if (@typeInfo(Wanted) == .@"enum" and @hasDecl(Wanted, "opts") and Wanted.opts.enum_kind == .string) {
                if (std.meta.stringToEnum(Wanted, str)) |enum_val| {
                    return enum_val;
                }

                try wip.errTok(tok, .unknown_enum, .{ wip.current.attr, Parser.Choices(Wanted).init(std.enums.values(Wanted), '"') });
                return true;
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
            const qt = wip.current.qt();

            const ptr: TypeStore.Type.Pointer = qt.get(comp, .pointer) orelse continue;
            if (ptr.child.is(comp, .func)) return false;
        },
        .variable => switch (node) {
            .variable => return false,
            else => {},
        },
        .local_variable => switch (node) {
            .variable => if (wip.current.parser.func.qt != null) return false,
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
            try wip.current.parser.err(prev_attr.tok, .{
                .fmt = "conflicting attribute is here",
                .kind = .note,
            }, .{});
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
    wip.applied.items.len = 0;
    if (prev_decl.unpack()) |prev| try wip.inherit(p, prev);

    for (wip.attrs.items[wip.top..]) |*attr| {
        if (attr.used_as_type_attr) continue;
        wip.current = .{
            .args = attr.args(wip),
            .attr = attr,
            .target = decl,
            .parser = p,
        };

        switch (attr.name) {
            .standard => |standard_attr| switch (standard_attr) {
                .deprecated => try wip.applyDeprecated(),
                .nodiscard => try wip.applyWarnUnusedResult(),
                else => {},
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
                else => {},
            },
            .clang => |clang_attr| switch (clang_attr) {
                .unavailable => {
                    if (try wip.argCountMinMax(0, 1)) continue;

                    const maybe_msg = (try wip.arg(?[]const u8)) orelse continue;
                    try wip.add(.{ .unavailable = maybe_msg });
                },
                else => {},
            },
            .aro => {},
            .declspec => |declspec_attr| switch (declspec_attr) {
                .@"align" => try wip.applyAlignment(),
                .deprecated => try wip.applyDeprecated(),
                else => {},
            },
            .msvc => {},
            .riscv => {},
            .keyword => |keyword_attr| switch (keyword_attr) {
                ._Alignas, .alignas => try wip.applyAlignment(),
                else => {},
            },
        }
    }

    const gpa = p.comp.gpa;
    const tree = &p.tree;
    const start_index = tree.extra.items.len;

    try tree.extra.appendSlice(gpa, @ptrCast(wip.applied.items));
    try tree.decl_attrs.put(gpa, decl, .{ @intCast(start_index), @intCast(wip.applied.items.len) });
}

fn inherit(wip: *Wip, p: *Parser, decl: Tree.Node.Index) !void {
    const gpa = p.comp.gpa;
    const tree = &p.tree;
    for (tree.attrs(decl)) |ref| {
        const attr = tree.attr_map.get(ref);

        switch (attr.args) {
            .@"packed",
            .hot,
            .cold,
            .@"const",
            .alignment,
            .deprecated,
            .unavailable,
            .@"error",
            .warning,
            => {},
            else => continue,
        }

        try wip.applied.append(gpa, ref);
    }
}

fn applyAlignment(wip: *Wip) !void {
    const qt = wip.current.qt();
    if (qt.isInvalid()) return;
    if (try wip.argCountMinMax(0, 1)) return;
    if (wip.current.attr.syntax == .keyword) {
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

    const maybe_requested = (try wip.arg(?i64)) orelse return;
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
        casted = @intCast(requested);
    }
    try wip.add(.{ .alignment = casted });
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
    if (wip.current.qt().getFunc(comp)) |func| {
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
    const qt = wip.current.qt();
    if (qt.isInvalid()) return;
    if (try wip.checkTarget(&.{ .function, .function_pointer, .param })) return;
    if (wip.current.node() == .param) {
        if (wip.current.args.len != 0) {
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
    try parser.list_buf.ensureUnusedCapacity(comp.gpa, wip.current.args.len);

    const func_ty = qt.getFunc(comp).?;
    for (0..wip.current.args.len) |i| {
        const position = (try wip.arg(u32)) orelse return;
        const tok = wip.current.tok();

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

pub fn applyTypeAttrs(wip: *Wip, p: *Parser, qt: QualType) !QualType {
    var res_qt = qt;

    for (wip.attrs.items[wip.top..]) |*attr| {
        if (attr.used_as_type_attr) continue;
        wip.current = .{
            .args = attr.args(wip),
            .attr = attr,
            .parser = p,
        };

        switch (attr.name) {
            .standard => {},
            .gnu => |gnu_attr| switch (gnu_attr) {
                .vector_size => {
                    try wip.applyVectorSize(&res_qt);
                    attr.used_as_type_attr = true;
                },
                else => {},
            },
            .clang => |clang_attr| switch (clang_attr) {
                .neon_vector_type => {
                    try wip.applyNeonVector(&res_qt, .neon);
                    attr.used_as_type_attr = true;
                },
                .neon_polyvector_type => {
                    try wip.applyNeonVector(&res_qt, .neon_poly);
                    attr.used_as_type_attr = true;
                },
                else => {},
            },
            .aro => {},
            .declspec => {},
            .msvc => {},
            .riscv => {},
            .keyword => {},
        }
    }
    return res_qt;
}

fn applyVectorSize(wip: *Wip, qt: *QualType) !void {
    if (qt.isInvalid()) return;
    if (try wip.argCount(1)) return;

    const comp = wip.current.parser.comp;

    const scalar_kind = qt.scalarKind(comp);
    if (scalar_kind != .int and scalar_kind != .float) {
        if (qt.get(comp, .@"enum")) |enum_ty| {
            if (comp.langopts.emulate == .clang and enum_ty.incomplete) {
                return; // Clang silently ignores vector_size on incomplete enums.
            }
        }
        try wip.err(.invalid_vec_elem_ty, .{qt.*});
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

    qt.* = try comp.type_store.put(comp.gpa, .{ .vector = .{
        .elem = qt.*,
        .len = @intCast(vec_bytes / elem_size),
    } });
}

fn applyNeonVector(wip: *Wip, qt: *QualType, kind: Type.Vector.Kind) !void {
    if (qt.isInvalid()) return;
    if (try wip.argCount(1)) return;

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
        try wip.err(.invalid_vec_elem_ty, .{qt.*});
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

    qt.* = try comp.type_store.put(comp.gpa, .{ .vector = .{
        .elem = qt.*,
        .len = vec_len,
        .kind = kind,
    } });
}

pub fn applyStmtAttrs(wip: *Wip, p: *Parser, stmt: Tree.Node.Index) !void {
    _ = stmt; // autofix
    _ = wip; // autofix
    _ = p; // autofix
}
