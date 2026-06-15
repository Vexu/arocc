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

const Wip = @This();

attrs: std.ArrayList(Parsed) = .empty,
args: std.ArrayList(Parser.Result) = .empty,
applied: std.ArrayList(Attribute) = .empty,
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
    try wip.current.parser.err(wip.current.attr.tok, .{
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

        try wip.err(.arg_type, .{ expected, wip.current.attr, expression });
        return null;
    }
    const key = comp.interner.get(arg_res.val.ref());
    switch (key) {
        .int => {
            if (@typeInfo(Wanted) == .int) {
                if (arg_res.val.toInt(Wanted, comp)) |some| return some;
                try wip.err(.arg_int_out_of_range, .{ wip.current.attr, arg_res });
                return null;
            }
        },
        .bytes => |bytes| {
            if (Wanted == []const u8) {
                validate: {
                    const node = arg_res.node.get(&wip.current.parser.tree);
                    if (node != .string_literal_expr) break :validate;
                    switch (node.string_literal_expr.qt.childType(comp).get(comp, .int).?) {
                        .char, .uchar, .schar => {},
                        else => break :validate,
                    }
                    return try wip.current.parser.removeNull(arg_res.val);
                }

                try wip.err(.arg_requires_string, .{wip.current.attr});
                return null;
            } else if (@typeInfo(Wanted) == .@"enum" and @hasDecl(Wanted, "opts") and Wanted.opts.enum_kind == .string) {
                const str = bytes[0 .. bytes.len - 1];
                if (std.meta.stringToEnum(Wanted, str)) |enum_val| {
                    return enum_val;
                }

                try wip.err(.unknown_enum, .{ wip.current.attr, Parser.Choices(Wanted).init(std.enums.values(Wanted), '"') });
                return true;
            }
        },
        else => {},
    }

    try wip.err(.arg_type, .{
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
    var i: usize = 0;
    while (i < wip.applied.items.len) {
        const prev_attr = wip.applied.items[i];
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
    const current = wip.current.attr;
    try wip.applied.append(wip.current.parser.comp.gpa, .{
        .args = args,
        .name = current.name,
        .syntax = current.syntax,
        .tok = current.tok,
    });
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
            .standard => {},
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
                else => {},
            },
            .clang => {},
            .aro => {},
            .declspec => |declspec_attr| switch (declspec_attr) {
                .@"align" => try wip.applyAlignment(),
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

    try tree.extra.ensureUnusedCapacity(gpa, wip.applied.items.len);
    for (wip.applied.items) |applied| {
        const ref = try tree.attr_map.put(gpa, applied);
        tree.extra.appendAssumeCapacity(@intFromEnum(ref));
    }
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
            => {},
            else => continue,
        }

        try wip.applied.append(gpa, attr);
    }
}

fn applyAlignment(wip: *Wip) !void {
    const qt = wip.current.qt();
    if (qt.isInvalid()) return;
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
    if (try wip.argCountMinMax(0, 1)) return;

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
            .clang => {},
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

pub fn applyStmtAttrs(wip: *Wip, p: *Parser, stmt: Tree.Node.Index) !void {
    _ = stmt; // autofix
    _ = wip; // autofix
    _ = p; // autofix
}
