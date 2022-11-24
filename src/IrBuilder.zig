const std = @import("std");
const Allocator = std.mem.Allocator;
const assert = std.debug.assert;
const Compilation = @import("Compilation.zig");
const Tree = @import("Tree.zig");
const NodeIndex = Tree.NodeIndex;
const Ir = @import("Ir.zig");
const Type = @import("Type.zig");
const IrPool = @import("IrPool.zig");
const Value = @import("Value.zig");
const StringId = @import("StringInterner.zig").StringId;

const IrBuilder = @This();

const WipSwitch = struct {
    cases: Cases = .{},
    default: ?Ir.Ref = null,
    size: u64,

    const Cases = std.MultiArrayList(struct {
        val: IrPool.Ref,
        label: Ir.Ref,
        // block: *Ir.Block,
    });
};

const Symbol = struct {
    name: StringId,
    val: Ir.Ref,
};

const BoolCtx = struct {
    false_label: Ir.Ref,
    true_label: Ir.Ref,
};

pub const Error = Compilation.Error || error{IrGenFailed};

gpa: Allocator,
arena: std.heap.ArenaAllocator,
instructions: std.MultiArrayList(Ir.Inst) = .{},
tree: Tree,
comp: *Compilation,
node_tag: []const Tree.Tag,
node_data: []const Tree.Node.Data,
node_ty: []const Type,
wip_switch: *WipSwitch = undefined,
symbols: std.ArrayListUnmanaged(Symbol) = .{},
body: std.ArrayListUnmanaged(Ir.Ref) = .{},
allocs: u32 = 0,
cond_dummy_ref: Ir.Ref = undefined,
pool: IrPool = .{},
bool_ctx: ?BoolCtx = null,
continue_label: Ir.Ref = undefined,
break_label: Ir.Ref = undefined,
return_label: Ir.Ref = undefined,

fn deinit(irb: *IrBuilder) void {
    irb.arena.deinit();
    irb.symbols.deinit(irb.gpa);
    irb.instructions.deinit(irb.gpa);
    irb.body.deinit(irb.gpa);
    irb.pool.deinit(irb.gpa);
    irb.* = undefined;
}

fn finish(irb: IrBuilder) Ir {
    return .{
        .pool = irb.pool,
        .instructions = irb.instructions,
        .arena = irb.arena.state,
        .body = irb.body,
    };
}

fn addAlloc(irb: *IrBuilder, ty: Type) !Ir.Ref {
    const ref = @intToEnum(Ir.Ref, irb.instructions.len);
    const size = @intCast(u32, ty.sizeof(irb.comp).?); // TODO add error in parser
    const @"align" = ty.alignof(irb.comp);
    try irb.instructions.append(irb.comp.gpa, .{
        .tag = .alloc,
        .data = .{ .alloc = .{ .size = size, .@"align" = @"align" } },
        .ty = .ptr,
    });
    try irb.body.insert(irb.comp.gpa, irb.allocs, ref);
    irb.allocs += 1;
    return ref;
}

fn addLabel(irb: *IrBuilder, name: [*:0]const u8) !Ir.Ref {
    const ref = @intToEnum(Ir.Ref, irb.instructions.len);
    try irb.instructions.append(irb.comp.gpa, .{ .tag = .label, .data = .{ .label = name }, .ty = .void });
    return ref;
}

fn addInstVoid(irb: *IrBuilder, tag: Ir.Inst.Tag, data: Ir.Inst.Data) !void {
    const ref = @intToEnum(Ir.Ref, irb.instructions.len);
    try irb.instructions.append(irb.comp.gpa, .{ .tag = tag, .data = data, .ty = .void });
    try irb.body.append(irb.comp.gpa, ref);
}

fn addInstNoReturn(irb: *IrBuilder, tag: Ir.Inst.Tag, data: Ir.Inst.Data) !void {
    const ref = @intToEnum(Ir.Ref, irb.instructions.len);
    try irb.instructions.append(irb.comp.gpa, .{ .tag = tag, .data = data, .ty = .noreturn });
    try irb.body.append(irb.comp.gpa, ref);
}

fn addInst(irb: *IrBuilder, tag: Ir.Inst.Tag, data: Ir.Inst.Data, ty: Type) !Ir.Ref {
    const ref = @intToEnum(Ir.Ref, irb.instructions.len);
    const ty_ref = try irb.genType(ty);
    try irb.instructions.append(irb.comp.gpa, .{ .tag = tag, .data = data, .ty = ty_ref });
    try irb.body.append(irb.comp.gpa, ref);
    return ref;
}

fn addBranch(irb: *IrBuilder, cond: Ir.Ref) !void {
    const branch = try irb.arena.allocator().create(Ir.Inst.Branch);
    branch.* = .{
        .cond = cond,
        .then = irb.bool_ctx.?.true_label,
        .@"else" = irb.bool_ctx.?.false_label,
    };
    try irb.addInstNoReturn(.branch, .{ .branch = branch });
}

fn addConstant(irb: *IrBuilder, val: Value, ty: Type) !Ir.Ref {
    const ref = @intToEnum(Ir.Ref, irb.instructions.len);
    const ty_ref = try irb.genType(ty);
    const key: IrPool.Key = .{
        .value = val,
    };
    const val_ref = try irb.pool.put(irb.gpa, key);
    try irb.instructions.append(irb.comp.gpa, .{ .tag = .constant, .data = .{
        .constant = val_ref,
    }, .ty = ty_ref });
    return ref;
}

/// Generate tree to an object file.
/// Caller is responsible for flushing and freeing the returned object.
pub fn generateTree(comp: *Compilation, tree: Tree) Compilation.Error!void {
    var irb = IrBuilder{
        .gpa = comp.gpa,
        .arena = std.heap.ArenaAllocator.init(comp.gpa),
        .tree = tree,
        .comp = comp,
        .node_tag = tree.nodes.items(.tag),
        .node_data = tree.nodes.items(.data),
        .node_ty = tree.nodes.items(.ty),
    };
    defer irb.deinit();

    const node_tags = tree.nodes.items(.tag);
    for (tree.root_decls) |decl| {
        irb.arena.deinit();
        irb.arena = std.heap.ArenaAllocator.init(comp.gpa);
        irb.instructions.len = 0;
        irb.body.items.len = 0;

        switch (node_tags[@enumToInt(decl)]) {
            // these produce no code
            .static_assert,
            .typedef,
            .struct_decl_two,
            .union_decl_two,
            .enum_decl_two,
            .struct_decl,
            .union_decl,
            .enum_decl,
            => {},

            // define symbol
            .fn_proto,
            .static_fn_proto,
            .inline_fn_proto,
            .inline_static_fn_proto,
            .extern_var,
            .threadlocal_extern_var,
            => {},

            // function definition
            .fn_def,
            .static_fn_def,
            .inline_fn_def,
            .inline_static_fn_def,
            => irb.genFn(decl) catch |err| switch (err) {
                error.FatalError => return error.FatalError,
                error.OutOfMemory => return error.OutOfMemory,
                error.IrGenFailed => continue,
            },

            .@"var",
            .static_var,
            .threadlocal_var,
            .threadlocal_static_var,
            => irb.genVar(decl) catch |err| switch (err) {
                error.FatalError => return error.FatalError,
                error.OutOfMemory => return error.OutOfMemory,
                error.IrGenFailed => continue,
            },
            else => unreachable,
        }
    }
}

fn genType(irb: *IrBuilder, base_ty: Type) !IrPool.Ref {
    var key: IrPool.Key = undefined;
    const ty = base_ty.canonicalize(.standard);
    switch (ty.specifier) {
        .void => return .void,
        .bool => return .i1,
        else => {},
    }
    if (ty.isPtr()) return .ptr;
    if (ty.isFunc()) return .func;
    if (!ty.isReal()) @panic("TODO lower complex types");
    if (ty.isInt()) {
        const bits = ty.bitSizeof(irb.comp).?;
        key = .{ .int = @intCast(u16, bits) };
    } else if (ty.isFloat()) {
        const bits = ty.bitSizeof(irb.comp).?;
        key = .{ .float = @intCast(u16, bits) };
    } else if (ty.isArray()) {
        const elem = try irb.genType(ty.elemType());
        key = .{ .array = .{ .child = elem, .len = ty.arrayLen().? } };
    } else if (ty.specifier == .vector) {
        const elem = try irb.genType(ty.elemType());
        key = .{ .vector = .{ .child = elem, .len = @intCast(u32, ty.data.array.len) } };
    }
    return irb.pool.put(irb.gpa, key);
}

fn genFn(irb: *IrBuilder, decl: NodeIndex) Error!void {
    const name = irb.tree.tokSlice(irb.node_data[@enumToInt(decl)].decl.name);
    const func_ty = irb.node_ty[@enumToInt(decl)].canonicalize(.standard);
    irb.allocs = 0;

    // reserve space for arg instructions
    const params = func_ty.data.func.params;
    try irb.instructions.ensureUnusedCapacity(irb.gpa, params.len);
    irb.instructions.len = params.len;

    for (params) |param, i| {
        // TODO handle calling convention here
        const arg = @intToEnum(Ir.Ref, i);
        irb.instructions.set(i, .{
            .tag = .arg,
            .data = .{ .arg = @intCast(u32, i) },
            .ty = try irb.genType(param.ty),
        });
        const alloc = try irb.addAlloc(param.ty);
        try irb.addInstVoid(.store, .{ .bin = .{ .lhs = alloc, .rhs = arg } });
        try irb.symbols.append(irb.comp.gpa, .{ .name = param.name, .val = alloc });
    }
    // Generate body
    irb.return_label = try irb.addLabel("return");
    try irb.genStmt(irb.node_data[@enumToInt(decl)].decl.node);

    // Relocate returns
    try irb.body.append(irb.gpa, irb.return_label);
    try irb.addInstNoReturn(.ret, undefined);

    var res = irb.finish();
    res.dump(name, irb.comp.diag.color, std.io.getStdOut().writer()) catch {};
}

fn genStmt(irb: *IrBuilder, node: NodeIndex) Error!void {
    std.debug.assert(node != .none);
    const ty = irb.node_ty[@enumToInt(node)];
    const data = irb.node_data[@enumToInt(node)];
    switch (irb.node_tag[@enumToInt(node)]) {
        .fn_def,
        .static_fn_def,
        .inline_fn_def,
        .inline_static_fn_def,
        .invalid,
        .threadlocal_var,
        => unreachable,
        .static_assert,
        .fn_proto,
        .static_fn_proto,
        .inline_fn_proto,
        .inline_static_fn_proto,
        .extern_var,
        .threadlocal_extern_var,
        .typedef,
        .struct_decl_two,
        .union_decl_two,
        .enum_decl_two,
        .struct_decl,
        .union_decl,
        .enum_decl,
        .enum_field_decl,
        .record_field_decl,
        .indirect_record_field_decl,
        .struct_forward_decl,
        .union_forward_decl,
        .enum_forward_decl,
        .null_stmt,
        => {},
        .static_var,
        .implicit_static_var,
        .threadlocal_static_var,
        => try irb.genVar(node), // TODO
        .@"var" => {
            const alloc = try irb.addAlloc(ty);
            const name = try irb.comp.intern(irb.tree.tokSlice(data.decl.name));
            try irb.symbols.append(irb.comp.gpa, .{ .name = name, .val = alloc });
            if (data.decl.node != .none) {
                const res = try irb.genExpr(data.decl.node);
                try irb.addInstVoid(.store, .{ .bin = .{ .lhs = alloc, .rhs = res } });
            }
        },
        .labeled_stmt => {
            const label = try irb.addLabel("label");
            try irb.body.append(irb.comp.gpa, label);
            try irb.genStmt(data.decl.node);
        },
        .compound_stmt_two => {
            const old_sym_len = irb.symbols.items.len;
            irb.symbols.items.len = old_sym_len;

            if (data.bin.lhs != .none) try irb.genStmt(data.bin.lhs);
            if (data.bin.rhs != .none) try irb.genStmt(data.bin.rhs);
        },
        .compound_stmt => {
            const old_sym_len = irb.symbols.items.len;
            irb.symbols.items.len = old_sym_len;

            for (irb.tree.data[data.range.start..data.range.end]) |stmt| try irb.genStmt(stmt);
        },
        .if_then_else_stmt => {
            const then_label = try irb.addLabel("if.then");
            const else_label = try irb.addLabel("if.else");
            const end_label = try irb.addLabel("if.end");

            {
                irb.bool_ctx = .{
                    .true_label = then_label,
                    .false_label = else_label,
                };
                defer irb.bool_ctx = null;
                try irb.genBoolExpr(data.if3.cond);
            }

            try irb.body.append(irb.gpa, then_label);
            try irb.genStmt(irb.tree.data[data.if3.body]); // then
            try irb.addInstVoid(.jmp, .{ .un = end_label });

            try irb.body.append(irb.gpa, else_label);
            try irb.genStmt(irb.tree.data[data.if3.body + 1]); // else

            try irb.body.append(irb.gpa, end_label);
        },
        .if_then_stmt => {
            const then_label = try irb.addLabel("if.then");
            const end_label = try irb.addLabel("if.end");

            {
                irb.bool_ctx = .{
                    .true_label = then_label,
                    .false_label = end_label,
                };
                defer irb.bool_ctx = null;
                try irb.genBoolExpr(data.bin.lhs);
            }
            try irb.body.append(irb.gpa, then_label);
            try irb.genStmt(data.bin.rhs); // then
            try irb.body.append(irb.gpa, end_label);
        },
        .switch_stmt => {
            var wip_switch = WipSwitch{
                .size = irb.node_ty[@enumToInt(data.bin.lhs)].sizeof(irb.comp).?,
            };
            defer wip_switch.cases.deinit(irb.gpa);

            const old_wip_switch = irb.wip_switch;
            defer irb.wip_switch = old_wip_switch;
            irb.wip_switch = &wip_switch;

            const old_break_label = irb.break_label;
            defer irb.break_label = old_break_label;
            const end_ref = try irb.addLabel("switch.end");
            irb.break_label = end_ref;

            const cond = try irb.genExpr(data.bin.lhs);
            const switch_index = irb.instructions.len;
            try irb.addInstNoReturn(.@"switch", undefined);

            try irb.genStmt(data.bin.rhs); // body

            try irb.body.append(irb.comp.gpa, end_ref);
            const default_ref = wip_switch.default orelse end_ref;
            try irb.body.append(irb.gpa, end_ref);

            const a = irb.arena.allocator();
            const switch_data = try a.create(Ir.Inst.Switch);
            switch_data.* = .{
                .target = cond,
                .cases_len = @intCast(u32, wip_switch.cases.len),
                .case_vals = (try a.dupe(IrPool.Ref, wip_switch.cases.items(.val))).ptr,
                .case_labels = (try a.dupe(Ir.Ref, wip_switch.cases.items(.label))).ptr,
                .default = default_ref,
            };
            irb.instructions.items(.data)[switch_index] = .{ .@"switch" = switch_data };
        },
        .case_stmt => {
            const val = irb.tree.value_map.get(data.bin.lhs).?;
            const label = try irb.addLabel("case");
            try irb.body.append(irb.comp.gpa, label);
            try irb.wip_switch.cases.append(irb.gpa, .{
                .val = try irb.pool.put(irb.gpa, .{ .value = val }),
                .label = label,
            });
            try irb.genStmt(data.bin.rhs);
        },
        .default_stmt => {
            const default = try irb.addLabel("default");
            try irb.body.append(irb.comp.gpa, default);
            irb.wip_switch.default = default;
            try irb.genStmt(data.un);
        },
        .while_stmt => {
            const old_break_label = irb.break_label;
            defer irb.break_label = old_break_label;

            const old_continue_label = irb.continue_label;
            defer irb.continue_label = old_continue_label;

            const cond_label = try irb.addLabel("while.cond");
            const then_label = try irb.addLabel("while.then");
            const end_label = try irb.addLabel("while.end");

            irb.continue_label = cond_label;
            irb.break_label = end_label;

            try irb.body.append(irb.gpa, cond_label);
            {
                irb.bool_ctx = .{
                    .true_label = then_label,
                    .false_label = end_label,
                };
                defer irb.bool_ctx = null;
                try irb.genBoolExpr(data.bin.lhs);
            }
            try irb.body.append(irb.gpa, then_label);
            try irb.genStmt(data.bin.rhs);
            try irb.addInstVoid(.jmp, .{ .un = cond_label });
            try irb.body.append(irb.gpa, end_label);
        },
        .do_while_stmt => {
            const old_break_label = irb.break_label;
            defer irb.break_label = old_break_label;

            const old_continue_label = irb.continue_label;
            defer irb.continue_label = old_continue_label;

            const then_label = try irb.addLabel("do.then");
            const cond_label = try irb.addLabel("do.cond");
            const end_label = try irb.addLabel("do.end");

            irb.continue_label = cond_label;
            irb.break_label = end_label;

            try irb.body.append(irb.gpa, then_label);
            try irb.genStmt(data.bin.rhs);
            try irb.body.append(irb.gpa, cond_label);
            {
                irb.bool_ctx = .{
                    .true_label = then_label,
                    .false_label = end_label,
                };
                defer irb.bool_ctx = null;
                try irb.genBoolExpr(data.bin.lhs);
            }
            try irb.body.append(irb.gpa, end_label);
        },
        .for_decl_stmt => {
            const old_break_label = irb.break_label;
            defer irb.break_label = old_break_label;

            const old_continue_label = irb.continue_label;
            defer irb.continue_label = old_continue_label;

            const for_decl = data.forDecl(irb.tree);
            for (for_decl.decls) |decl| try irb.genStmt(decl);

            const then_label = try irb.addLabel("for.then");
            var cond_label = then_label;
            const cont_label = try irb.addLabel("for.cont");
            const end_label = try irb.addLabel("for.end");

            irb.continue_label = cont_label;
            irb.break_label = end_label;

            if (for_decl.cond != .none) {
                cond_label = try irb.addLabel("for.cond");
                try irb.body.append(irb.gpa, cond_label);

                irb.bool_ctx = .{
                    .true_label = then_label,
                    .false_label = end_label,
                };
                defer irb.bool_ctx = null;
                try irb.genBoolExpr(for_decl.cond);
            }
            try irb.body.append(irb.gpa, then_label);
            try irb.genStmt(for_decl.body);
            if (for_decl.incr != .none) {
                _ = try irb.genExpr(for_decl.incr);
            }
            try irb.addInstVoid(.jmp, .{ .un = cond_label });
            try irb.body.append(irb.gpa, end_label);
        },
        .forever_stmt => {
            const old_break_label = irb.break_label;
            defer irb.break_label = old_break_label;

            const old_continue_label = irb.continue_label;
            defer irb.continue_label = old_continue_label;

            const then_label = try irb.addLabel("for.then");
            const end_label = try irb.addLabel("for.end");

            irb.continue_label = then_label;
            irb.break_label = end_label;

            try irb.body.append(irb.gpa, then_label);
            try irb.genStmt(data.un);
            try irb.body.append(irb.gpa, end_label);
        },
        .for_stmt => {
            const old_break_label = irb.break_label;
            defer irb.break_label = old_break_label;

            const old_continue_label = irb.continue_label;
            defer irb.continue_label = old_continue_label;

            const for_stmt = data.forStmt(irb.tree);
            if (for_stmt.init != .none) _ = try irb.genExpr(for_stmt.init);

            const then_label = try irb.addLabel("for.then");
            var cond_label = then_label;
            const cont_label = try irb.addLabel("for.cont");
            const end_label = try irb.addLabel("for.end");

            irb.continue_label = cont_label;
            irb.break_label = end_label;

            if (for_stmt.cond != .none) {
                cond_label = try irb.addLabel("for.cond");
                try irb.body.append(irb.gpa, cond_label);

                irb.bool_ctx = .{
                    .true_label = then_label,
                    .false_label = end_label,
                };
                defer irb.bool_ctx = null;
                try irb.genBoolExpr(for_stmt.cond);
            }
            try irb.body.append(irb.gpa, then_label);
            try irb.genStmt(for_stmt.body);
            if (for_stmt.incr != .none) {
                _ = try irb.genExpr(for_stmt.incr);
            }
            try irb.addInstVoid(.jmp, .{ .un = cond_label });
            try irb.body.append(irb.gpa, end_label);
        },
        .continue_stmt => try irb.addInstNoReturn(.jmp, .{ .un = irb.continue_label }),
        .break_stmt => try irb.addInstNoReturn(.jmp, .{ .un = irb.break_label }),
        .return_stmt => {
            if (data.un != .none) {
                const operand = try irb.genExpr(data.un);
                try irb.addInstVoid(.ret_value, .{ .un = operand });
            }
            try irb.addInstNoReturn(.jmp, .{ .un = irb.return_label });
        },
        .implicit_return => {
            if (data.return_zero) {
                const operand = try irb.addConstant(Value.int(0), ty);
                try irb.addInstVoid(.ret_value, .{ .un = operand });
            }
            // No need to emit a jump since implicit_return is always the last instruction.
        },
        .case_range_stmt,
        .goto_stmt,
        .computed_goto_stmt,
        => return irb.comp.diag.fatalNoSrc("TODO IrBuilder.genStmt {}\n", .{irb.node_tag[@enumToInt(node)]}),
        else => _ = try irb.genExpr(node),
    }
}

fn genExpr(irb: *IrBuilder, node: NodeIndex) Error!Ir.Ref {
    std.debug.assert(node != .none);
    const ty = irb.node_ty[@enumToInt(node)];
    if (irb.tree.value_map.get(node)) |val| {
        return irb.addConstant(val, ty);
    }
    const data = irb.node_data[@enumToInt(node)];
    switch (irb.node_tag[@enumToInt(node)]) {
        .enumeration_ref,
        .int_literal,
        .char_literal,
        .float_literal,
        .double_literal,
        .imaginary_literal,
        .string_literal_expr,
        => unreachable, // These should have an entry in value_map.
        .comma_expr => {
            _ = try irb.genExpr(data.bin.lhs);
            return irb.genExpr(data.bin.rhs);
        },
        .assign_expr => {
            const rhs = try irb.genExpr(data.bin.rhs);
            const lhs = try irb.genLval(data.bin.lhs);
            try irb.addInstVoid(.store, .{ .bin = .{ .lhs = lhs, .rhs = rhs } });
            return rhs;
        },
        .mul_assign_expr => return irb.genCompoundAssign(node, .mul),
        .div_assign_expr => return irb.genCompoundAssign(node, .div),
        .mod_assign_expr => return irb.genCompoundAssign(node, .mod),
        .add_assign_expr => return irb.genCompoundAssign(node, .add),
        .sub_assign_expr => return irb.genCompoundAssign(node, .sub),
        .shl_assign_expr => return irb.genCompoundAssign(node, .bit_shl),
        .shr_assign_expr => return irb.genCompoundAssign(node, .bit_shr),
        .bit_and_assign_expr => return irb.genCompoundAssign(node, .bit_and),
        .bit_xor_assign_expr => return irb.genCompoundAssign(node, .bit_xor),
        .bit_or_assign_expr => return irb.genCompoundAssign(node, .bit_or),
        .bit_or_expr => return irb.genBinOp(node, .bit_or),
        .bit_xor_expr => return irb.genBinOp(node, .bit_xor),
        .bit_and_expr => return irb.genBinOp(node, .bit_and),
        .equal_expr => {
            const cmp = try irb.genComparison(node, .cmp_eq);
            return irb.addInst(.zext, .{ .un = cmp }, ty);
        },
        .not_equal_expr => {
            const cmp = try irb.genComparison(node, .cmp_ne);
            return irb.addInst(.zext, .{ .un = cmp }, ty);
        },
        .less_than_expr => {
            const cmp = try irb.genComparison(node, .cmp_lt);
            return irb.addInst(.zext, .{ .un = cmp }, ty);
        },
        .less_than_equal_expr => {
            const cmp = try irb.genComparison(node, .cmp_lte);
            return irb.addInst(.zext, .{ .un = cmp }, ty);
        },
        .greater_than_expr => {
            const cmp = try irb.genComparison(node, .cmp_gt);
            return irb.addInst(.zext, .{ .un = cmp }, ty);
        },
        .greater_than_equal_expr => {
            const cmp = try irb.genComparison(node, .cmp_gte);
            return irb.addInst(.zext, .{ .un = cmp }, ty);
        },
        .shl_expr => return irb.genBinOp(node, .bit_shl),
        .shr_expr => return irb.genBinOp(node, .bit_shr),
        .add_expr => {
            if (ty.isPtr()) {
                const lhs_ty = irb.node_ty[@enumToInt(data.bin.lhs)];
                if (lhs_ty.isPtr()) {
                    const ptr = try irb.genExpr(data.bin.lhs);
                    const offset = try irb.genExpr(data.bin.rhs);
                    const offset_ty = irb.node_ty[@enumToInt(data.bin.rhs)];
                    return irb.genPtrArithmetic(ptr, offset, offset_ty, ty);
                } else {
                    const offset = try irb.genExpr(data.bin.lhs);
                    const ptr = try irb.genExpr(data.bin.rhs);
                    const offset_ty = lhs_ty;
                    return irb.genPtrArithmetic(ptr, offset, offset_ty, ty);
                }
            }
            return irb.genBinOp(node, .add);
        },
        .sub_expr => {
            if (ty.isPtr()) {
                const ptr = try irb.genExpr(data.bin.lhs);
                const offset = try irb.genExpr(data.bin.rhs);
                const offset_ty = irb.node_ty[@enumToInt(data.bin.rhs)];
                return irb.genPtrArithmetic(ptr, offset, offset_ty, ty);
            }
            return irb.genBinOp(node, .sub);
        },
        .mul_expr => return irb.genBinOp(node, .mul),
        .div_expr => return irb.genBinOp(node, .div),
        .mod_expr => return irb.genBinOp(node, .mod),
        .addr_of_expr => return try irb.genLval(data.un),
        .deref_expr => {
            const un_data = irb.node_data[@enumToInt(data.un)];
            if (irb.node_tag[@enumToInt(data.un)] == .implicit_cast and un_data.cast.kind == .function_to_pointer) {
                return irb.genExpr(data.un);
            }
            const operand = try irb.genLval(data.un);
            return irb.addInst(.load, .{ .un = operand }, ty);
        },
        .plus_expr => return irb.genExpr(data.un),
        .negate_expr => {
            const zero = try irb.addConstant(Value.int(0), ty);
            const operand = try irb.genExpr(data.un);
            return irb.addInst(.sub, .{ .bin = .{ .lhs = zero, .rhs = operand } }, ty);
        },
        .bit_not_expr => {
            const operand = try irb.genExpr(data.un);
            return irb.addInst(.bit_not, .{ .un = operand }, ty);
        },
        .bool_not_expr => {
            const zero = try irb.addConstant(Value.int(0), ty);
            const operand = try irb.genExpr(data.un);
            return irb.addInst(.cmp_ne, .{ .bin = .{ .lhs = zero, .rhs = operand } }, ty);
        },
        .pre_inc_expr => {
            const operand = try irb.genExpr(data.un);
            const val = try irb.addInst(.load, .{ .un = operand }, ty);
            const one = try irb.addConstant(Value.int(1), ty);
            const plus_one = try irb.addInst(.add, .{ .bin = .{ .lhs = val, .rhs = one } }, ty);
            try irb.addInstVoid(.store, .{ .bin = .{ .lhs = operand, .rhs = plus_one } });
            return plus_one;
        },
        .pre_dec_expr => {
            const operand = try irb.genExpr(data.un);
            const val = try irb.addInst(.load, .{ .un = operand }, ty);
            const one = try irb.addConstant(Value.int(1), ty);
            const plus_one = try irb.addInst(.sub, .{ .bin = .{ .lhs = val, .rhs = one } }, ty);
            try irb.addInstVoid(.store, .{ .bin = .{ .lhs = operand, .rhs = plus_one } });
            return plus_one;
        },
        .post_inc_expr => {
            const operand = try irb.genExpr(data.un);
            const val = try irb.addInst(.load, .{ .un = operand }, ty);
            const one = try irb.addConstant(Value.int(1), ty);
            const plus_one = try irb.addInst(.add, .{ .bin = .{ .lhs = val, .rhs = one } }, ty);
            try irb.addInstVoid(.store, .{ .bin = .{ .lhs = operand, .rhs = plus_one } });
            return val;
        },
        .post_dec_expr => {
            const operand = try irb.genExpr(data.un);
            const val = try irb.addInst(.load, .{ .un = operand }, ty);
            const one = try irb.addConstant(Value.int(1), ty);
            const plus_one = try irb.addInst(.sub, .{ .bin = .{ .lhs = val, .rhs = one } }, ty);
            try irb.addInstVoid(.store, .{ .bin = .{ .lhs = operand, .rhs = plus_one } });
            return val;
        },
        .paren_expr => return irb.genExpr(data.un),
        .decl_ref_expr => unreachable, // Lval expression.
        .explicit_cast, .implicit_cast => switch (data.cast.kind) {
            .no_op => return irb.genExpr(data.cast.operand),
            .to_void => unreachable, // Not an expression.
            .lval_to_rval => {
                const operand = try irb.genLval(data.cast.operand);
                return irb.addInst(.load, .{ .un = operand }, ty);
            },
            .function_to_pointer, .array_to_pointer => {
                return irb.genLval(data.cast.operand);
            },
            .int_cast => {
                const operand = try irb.genExpr(data.cast.operand);
                const src_ty = irb.node_ty[@enumToInt(data.cast.operand)];
                const src_bits = src_ty.bitSizeof(irb.comp).?;
                const dest_bits = ty.bitSizeof(irb.comp).?;
                if (src_bits == dest_bits) {
                    return operand;
                } else if (src_bits < dest_bits) {
                    if (src_ty.isUnsignedInt(irb.comp))
                        return irb.addInst(.zext, .{ .un = operand }, ty)
                    else
                        return irb.addInst(.sext, .{ .un = operand }, ty);
                } else {
                    return irb.addInst(.trunc, .{ .un = operand }, ty);
                }
            },
            .bool_to_int => {
                const operand = try irb.genExpr(data.cast.operand);
                return irb.addInst(.zext, .{ .un = operand }, ty);
            },
            .pointer_to_bool, .int_to_bool, .float_to_bool => {
                const lhs = try irb.genExpr(data.cast.operand);
                const rhs = try irb.addConstant(Value.int(0), irb.node_ty[@enumToInt(node)]);
                const cmp = @intToEnum(Ir.Ref, irb.instructions.len);
                try irb.instructions.append(
                    irb.comp.gpa,
                    .{ .tag = .cmp_ne, .data = .{ .bin = .{ .lhs = lhs, .rhs = rhs } }, .ty = .i1 },
                );
                try irb.body.append(irb.comp.gpa, cmp);
                return cmp;
            },
            .bitcast,
            .pointer_to_int,
            .bool_to_float,
            .bool_to_pointer,
            .int_to_float,
            .complex_int_to_complex_float,
            .int_to_pointer,
            .float_to_int,
            .complex_float_to_complex_int,
            .complex_int_cast,
            .complex_int_to_real,
            .real_to_complex_int,
            .float_cast,
            .complex_float_cast,
            .complex_float_to_real,
            .real_to_complex_float,
            .null_to_pointer,
            .union_cast,
            .vector_splat,
            => return irb.comp.diag.fatalNoSrc("TODO IrBuilder gen CastKind {}\n", .{data.cast.kind}),
        },
        .binary_cond_expr => {
            const cond = try irb.genExpr(data.if3.cond);
            const then = then: {
                const old_cond_dummy_ref = irb.cond_dummy_ref;
                defer irb.cond_dummy_ref = old_cond_dummy_ref;
                irb.cond_dummy_ref = cond;

                break :then try irb.genExpr(irb.tree.data[data.if3.body]);
            };
            const @"else" = try irb.genExpr(irb.tree.data[data.if3.body + 1]);

            const branch = try irb.arena.allocator().create(Ir.Inst.Branch);
            branch.* = .{ .cond = cond, .then = then, .@"else" = @"else" };
            // TODO can't use select here
            return irb.addInst(.select, .{ .branch = branch }, ty);
        },
        .cond_dummy_expr => return irb.cond_dummy_ref,
        .cond_expr => {
            const cond = try irb.genExpr(data.if3.cond);
            const then = try irb.genExpr(irb.tree.data[data.if3.body]);
            const @"else" = try irb.genExpr(irb.tree.data[data.if3.body + 1]);

            const branch = try irb.arena.allocator().create(Ir.Inst.Branch);
            branch.* = .{ .cond = cond, .then = then, .@"else" = @"else" };
            // TODO can't use select here
            return irb.addInst(.select, .{ .branch = branch }, ty);
        },
        .call_expr_one => if (data.bin.rhs == .none) {
            return irb.genCall(data.bin.lhs, &.{}, ty);
        } else {
            return irb.genCall(data.bin.lhs, &.{data.bin.rhs}, ty);
        },
        .call_expr => {
            return irb.genCall(irb.tree.data[data.range.start], irb.tree.data[data.range.start + 1 .. data.range.end], ty);
        },
        .bool_or_expr,
        .bool_and_expr,
        .addr_of_label,
        .imag_expr,
        .real_expr,
        .array_access_expr,
        .builtin_call_expr_one,
        .builtin_call_expr,
        .member_access_expr,
        .member_access_ptr_expr,
        .sizeof_expr,
        .alignof_expr,
        .generic_expr_one,
        .generic_expr,
        .generic_association_expr,
        .generic_default_expr,
        .builtin_choose_expr,
        .stmt_expr,
        .array_init_expr_two,
        .array_init_expr,
        .struct_init_expr_two,
        .struct_init_expr,
        .union_init_expr,
        .compound_literal_expr,
        .array_filler_expr,
        .default_init_expr,
        => return irb.comp.diag.fatalNoSrc("TODO IrBuilder.genExpr {}\n", .{irb.node_tag[@enumToInt(node)]}),
        else => unreachable, // Not an expression.
    }
}

fn genLval(irb: *IrBuilder, node: NodeIndex) Error!Ir.Ref {
    std.debug.assert(node != .none);
    assert(Tree.isLval(irb.tree.nodes, irb.tree.data, irb.tree.value_map, node));
    const data = irb.node_data[@enumToInt(node)];
    switch (irb.node_tag[@enumToInt(node)]) {
        .string_literal_expr => {
            const val = irb.tree.value_map.get(node).?.data.bytes;

            // TODO generate anonymous global
            const name = try std.fmt.allocPrintZ(irb.arena.allocator(), "\"{}\"", .{std.fmt.fmtSliceEscapeLower(val)});
            const ref = @intToEnum(Ir.Ref, irb.instructions.len);
            try irb.instructions.append(irb.comp.gpa, .{
                .tag = .symbol,
                .data = .{ .label = name },
                .ty = .ptr,
            });
            return ref;
        },
        .paren_expr => return irb.genLval(data.un),
        .decl_ref_expr => {
            const slice = irb.tree.tokSlice(data.decl_ref);
            const name = try irb.comp.intern(slice);
            var i = irb.symbols.items.len;
            while (i > 0) {
                i -= 1;
                if (irb.symbols.items[i].name == name) {
                    return irb.symbols.items[i].val;
                }
            }

            const ref = @intToEnum(Ir.Ref, irb.instructions.len);
            try irb.instructions.append(irb.comp.gpa, .{
                .tag = .symbol,
                .data = .{ .label = try irb.arena.allocator().dupeZ(u8, slice) },
                .ty = .ptr,
            });
            return ref;
        },
        .deref_expr => return irb.genExpr(data.un),
        else => return irb.comp.diag.fatalNoSrc("TODO IrBuilder.genLval {}\n", .{irb.node_tag[@enumToInt(node)]}),
    }
}

fn genBoolExpr(irb: *IrBuilder, base: NodeIndex) Error!void {
    var node = base;
    while (true) switch (irb.node_tag[@enumToInt(node)]) {
        .paren_expr => {
            node = irb.node_data[@enumToInt(node)].un;
        },
        else => break,
    };

    const data = irb.node_data[@enumToInt(node)];
    switch (irb.node_tag[@enumToInt(node)]) {
        .bool_or_expr => {
            if (irb.tree.value_map.get(data.bin.lhs)) |lhs| {
                const cond = lhs.getBool();
                if (cond) {
                    return irb.addInstNoReturn(.jmp, .{ .un = irb.bool_ctx.?.true_label });
                }
                return irb.genBoolExpr(data.bin.rhs);
            }
            const old_bool_ctx = irb.bool_ctx;
            defer irb.bool_ctx = old_bool_ctx;

            const false_label = try irb.addLabel("bool_or.false");
            irb.bool_ctx = .{
                .true_label = irb.bool_ctx.?.true_label,
                .false_label = false_label,
            };
            try irb.genBoolExpr(data.bin.lhs);
            try irb.body.append(irb.gpa, false_label);
            irb.bool_ctx = .{
                .true_label = irb.bool_ctx.?.true_label,
                .false_label = old_bool_ctx.?.false_label,
            };
            return irb.genBoolExpr(data.bin.rhs);
        },
        .bool_and_expr => {
            if (irb.tree.value_map.get(data.bin.lhs)) |lhs| {
                const cond = lhs.getBool();
                if (!cond) {
                    return irb.addInstNoReturn(.jmp, .{ .un = irb.bool_ctx.?.false_label });
                }
                return irb.genBoolExpr(data.bin.rhs);
            }
            const old_bool_ctx = irb.bool_ctx;
            defer irb.bool_ctx = old_bool_ctx;

            const true_label = try irb.addLabel("bool_and.true");
            irb.bool_ctx = .{
                .true_label = true_label,
                .false_label = irb.bool_ctx.?.false_label,
            };
            try irb.genBoolExpr(data.bin.lhs);
            try irb.body.append(irb.gpa, true_label);
            irb.bool_ctx = .{
                .true_label = old_bool_ctx.?.true_label,
                .false_label = irb.bool_ctx.?.false_label,
            };
            return irb.genBoolExpr(data.bin.rhs);
        },
        .bool_not_expr => {
            const old_bool_ctx = irb.bool_ctx;
            defer irb.bool_ctx = old_bool_ctx;

            irb.bool_ctx = .{
                .true_label = irb.bool_ctx.?.false_label,
                .false_label = irb.bool_ctx.?.true_label,
            };
            return irb.genBoolExpr(data.un);
        },
        .equal_expr => {
            const cmp = try irb.genComparison(node, .cmp_eq);
            return irb.addBranch(cmp);
        },
        .not_equal_expr => {
            const cmp = try irb.genComparison(node, .cmp_ne);
            return irb.addBranch(cmp);
        },
        .less_than_expr => {
            const cmp = try irb.genComparison(node, .cmp_lt);
            return irb.addBranch(cmp);
        },
        .less_than_equal_expr => {
            const cmp = try irb.genComparison(node, .cmp_lte);
            return irb.addBranch(cmp);
        },
        .greater_than_expr => {
            const cmp = try irb.genComparison(node, .cmp_gt);
            return irb.addBranch(cmp);
        },
        .greater_than_equal_expr => {
            const cmp = try irb.genComparison(node, .cmp_gte);
            return irb.addBranch(cmp);
        },
        .explicit_cast, .implicit_cast => switch (data.cast.kind) {
            .bool_to_int => {
                const operand = try irb.genExpr(data.cast.operand);
                return irb.addBranch(operand);
            },
            else => {},
        },
        else => {},
    }

    // Assume int operand.
    const lhs = try irb.genExpr(node);
    const rhs = try irb.addConstant(Value.int(0), irb.node_ty[@enumToInt(node)]);
    const cmp = @intToEnum(Ir.Ref, irb.instructions.len);
    try irb.instructions.append(
        irb.comp.gpa,
        .{ .tag = .cmp_ne, .data = .{ .bin = .{ .lhs = lhs, .rhs = rhs } }, .ty = .i1 },
    );
    try irb.body.append(irb.comp.gpa, cmp);
    try irb.addBranch(cmp);
}

fn genCall(irb: *IrBuilder, fn_node: NodeIndex, arg_nodes: []const NodeIndex, ty: Type) Error!Ir.Ref {
    // Detect direct calls.
    const fn_ref = blk: {
        const data = irb.node_data[@enumToInt(fn_node)];
        if (irb.node_tag[@enumToInt(fn_node)] != .implicit_cast or data.cast.kind != .function_to_pointer) {
            break :blk try irb.genExpr(fn_node);
        }

        var cur = @enumToInt(data.cast.operand);
        while (true) switch (irb.node_tag[cur]) {
            .paren_expr, .addr_of_expr, .deref_expr => {
                cur = @enumToInt(irb.node_data[cur].un);
            },
            .implicit_cast => {
                const cast = irb.node_data[cur].cast;
                if (cast.kind != .function_to_pointer) {
                    break :blk try irb.genExpr(fn_node);
                }
                cur = @enumToInt(cast.operand);
            },
            .decl_ref_expr => {
                const slice = irb.tree.tokSlice(irb.node_data[cur].decl_ref);
                const name = try irb.comp.intern(slice);
                var i = irb.symbols.items.len;
                while (i > 0) {
                    i -= 1;
                    if (irb.symbols.items[i].name == name) {
                        break :blk try irb.genExpr(fn_node);
                    }
                }

                const ref = @intToEnum(Ir.Ref, irb.instructions.len);
                try irb.instructions.append(irb.comp.gpa, .{
                    .tag = .symbol,
                    .data = .{ .label = try irb.arena.allocator().dupeZ(u8, slice) },
                    .ty = .func,
                });
                break :blk ref;
            },
            else => break :blk try irb.genExpr(fn_node),
        };
    };

    const args = try irb.arena.allocator().alloc(Ir.Ref, arg_nodes.len);
    for (arg_nodes) |node, i| {
        // TODO handle calling convention here
        args[i] = try irb.genExpr(node);
    }
    // TODO handle variadic call
    const call = try irb.arena.allocator().create(Ir.Inst.Call);
    call.* = .{
        .func = fn_ref,
        .args_len = @intCast(u32, args.len),
        .args_ptr = args.ptr,
    };
    return irb.addInst(.call, .{ .call = call }, ty);
}

fn genCompoundAssign(irb: *IrBuilder, node: NodeIndex, tag: Ir.Inst.Tag) Error!Ir.Ref {
    const bin = irb.node_data[@enumToInt(node)].bin;
    const ty = irb.node_ty[@enumToInt(node)];
    const rhs = try irb.genExpr(bin.rhs);
    const lhs = try irb.genLval(bin.lhs);
    const res = try irb.addInst(tag, .{ .bin = .{ .lhs = lhs, .rhs = rhs } }, ty);
    try irb.addInstVoid(.store, .{ .bin = .{ .lhs = lhs, .rhs = res } });
    return res;
}

fn genBinOp(irb: *IrBuilder, node: NodeIndex, tag: Ir.Inst.Tag) Error!Ir.Ref {
    const bin = irb.node_data[@enumToInt(node)].bin;
    const ty = irb.node_ty[@enumToInt(node)];
    const lhs = try irb.genExpr(bin.lhs);
    const rhs = try irb.genExpr(bin.rhs);
    return irb.addInst(tag, .{ .bin = .{ .lhs = lhs, .rhs = rhs } }, ty);
}

fn genComparison(irb: *IrBuilder, node: NodeIndex, tag: Ir.Inst.Tag) Error!Ir.Ref {
    const bin = irb.node_data[@enumToInt(node)].bin;
    const lhs = try irb.genExpr(bin.lhs);
    const rhs = try irb.genExpr(bin.rhs);

    const cmp = @intToEnum(Ir.Ref, irb.instructions.len);
    try irb.instructions.append(
        irb.comp.gpa,
        .{ .tag = tag, .data = .{ .bin = .{ .lhs = lhs, .rhs = rhs } }, .ty = .i1 },
    );
    try irb.body.append(irb.comp.gpa, cmp);
    return cmp;
}

fn genPtrArithmetic(irb: *IrBuilder, ptr: Ir.Ref, offset: Ir.Ref, offset_ty: Type, ty: Type) Error!Ir.Ref {
    // TODO consider adding a getelemptr instruction
    const size = ty.elemType().sizeof(irb.comp).?;
    if (size == 1) {
        return irb.addInst(.add, .{ .bin = .{ .lhs = ptr, .rhs = offset } }, ty);
    }

    const size_inst = try irb.addConstant(Value.int(size), offset_ty);
    const offset_inst = try irb.addInst(.mul, .{ .bin = .{ .lhs = offset, .rhs = size_inst } }, offset_ty);
    return irb.addInst(.add, .{ .bin = .{ .lhs = ptr, .rhs = offset_inst } }, ty);
}

fn genVar(irb: *IrBuilder, decl: NodeIndex) Error!void {
    _ = decl;
    return irb.comp.diag.fatalNoSrc("TODO IrBuilder.genVar\n", .{});
}
