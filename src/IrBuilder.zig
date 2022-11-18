const std = @import("std");
const Allocator = std.mem.Allocator;
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
    cases: Cases,
    default: ?Ir.Ref = null,
    size: u64,

    const Cases = std.ArrayList(struct {
        val: Ir.Ref,
        label: Ir.Ref,
        // block: *Ir.Block,
    });
};

const Symbol = struct {
    name: StringId,
    val: Ir.Ref,
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
breaks: std.ArrayListUnmanaged(u32) = .{},
continues: std.ArrayListUnmanaged(u32) = .{},
returns: std.ArrayListUnmanaged(u32) = .{},
body: std.ArrayListUnmanaged(Ir.Ref) = .{},
allocs: u32 = 0,
pool: IrPool = .{},

fn deinit(irb: *IrBuilder) void {
    irb.arena.deinit();
    irb.symbols.deinit(irb.gpa);
    irb.breaks.deinit(irb.gpa);
    irb.continues.deinit(irb.gpa);
    irb.returns.deinit(irb.gpa);
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
    try irb.body.append(irb.comp.gpa, ref);
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
    if (!ty.isReal()) @panic("TODO lower complex types");
    if (ty.isInt()) {
        const bits = ty.bitSizeof(irb.comp).?;
        key = .{ .int = @intCast(u16, bits) };
    } else if (ty.isFloat()) {
        const bits = ty.bitSizeof(irb.comp).?;
        key = .{ .float = @intCast(u16, bits) };
    }
    return irb.pool.put(irb.gpa, key);
}

fn genFn(irb: *IrBuilder, decl: NodeIndex) Error!void {
    const name = irb.tree.tokSlice(irb.node_data[@enumToInt(decl)].decl.name);
    const func_ty = irb.node_ty[@enumToInt(decl)].canonicalize(.standard);
    irb.returns.items.len = 0;
    irb.allocs = 0;

    // reserve space for arg instructions
    const params = func_ty.data.func.params;
    try irb.instructions.ensureUnusedCapacity(irb.gpa, params.len);
    irb.instructions.len = params.len;

    for (params) |param, i| {
        var arg = @intToEnum(Ir.Ref, i);
        irb.instructions.set(i, .{
            .tag = .arg,
            .data = .{ .arg = @intCast(u32, i) },
            .ty = try irb.genType(param.ty),
        });
        // create allocation for mutable parameters
        if (!param.ty.qual.@"const") {
            const alloc = try irb.addAlloc(param.ty);
            try irb.addInstVoid(.store, .{ .bin = .{ .lhs = alloc, .rhs = arg } });
            arg = alloc;
        }
        try irb.symbols.append(irb.comp.gpa, .{ .name = param.name, .val = arg });
    }
    // Generate body
    _ = try irb.genNode(irb.node_data[@enumToInt(decl)].decl.node);

    // Relocate returns
    if (irb.returns.items.len == 1 and irb.returns.items[0] == irb.instructions.len - 1) {
        irb.instructions.items(.tag)[irb.returns.items[0]] = .ret;
    } else if (irb.returns.items.len > 1) {
        const data = irb.instructions.items(.data);
        if (irb.returns.items[irb.returns.items.len - 1] == irb.instructions.len - 1) {
            // avoid a jump to an immediately following label
            irb.instructions.len -= 1;
            irb.body.items.len -= 1;
            irb.returns.items.len -= 1;
        }
        const return_label = try irb.addLabel("return");
        for (irb.returns.items) |ret_index| {
            data[ret_index] = .{ .un = return_label };
        }
        try irb.addInstNoReturn(.ret, undefined);
    }

    var res = irb.finish();
    res.dump(name, irb.comp.diag.color, std.io.getStdOut().writer()) catch {};
}

fn genNode(irb: *IrBuilder, node: NodeIndex) Error!Ir.Ref {
    std.debug.assert(node != .none);
    const ty = irb.node_ty[@enumToInt(node)];
    if (irb.tree.value_map.get(node)) |val| {
        return irb.addConstant(val, ty);
    }
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
                const res = try irb.genNode(data.decl.node);
                try irb.addInstVoid(.store, .{ .bin = .{ .lhs = alloc, .rhs = res } });
            }
            return alloc;
        },
        .labeled_stmt => {
            _ = try irb.addLabel("label");
            _ = try irb.genNode(data.decl.node);
        },
        .compound_stmt_two => {
            const old_sym_len = irb.symbols.items.len;
            irb.symbols.items.len = old_sym_len;

            if (data.bin.lhs != .none) _ = try irb.genNode(data.bin.lhs);
            if (data.bin.rhs != .none) _ = try irb.genNode(data.bin.rhs);
        },
        .compound_stmt => {
            const old_sym_len = irb.symbols.items.len;
            irb.symbols.items.len = old_sym_len;

            for (irb.tree.data[data.range.start..data.range.end]) |stmt| _ = try irb.genNode(stmt);
        },
        .if_then_else_stmt => {
            const cond = try irb.genNode(data.if3.cond);

            const branch_index = irb.instructions.len;
            try irb.addInstNoReturn(.branch, undefined);

            const then_label = try irb.addLabel("then");
            _ = try irb.genNode(irb.tree.data[data.if3.body]); // then
            const jmp_end_index = irb.instructions.len;
            try irb.addInstVoid(.jmp, undefined);

            const else_label = try irb.addLabel("else");
            _ = try irb.genNode(irb.tree.data[data.if3.body + 1]); // else

            const end_label = try irb.addLabel("end");

            const branch = try irb.arena.allocator().create(Ir.Inst.Branch);
            branch.* = .{
                .cond = cond,
                .then = then_label,
                .@"else" = else_label,
            };
            irb.instructions.items(.data)[branch_index] = .{ .branch = branch };
            irb.instructions.items(.data)[jmp_end_index] = .{ .un = end_label };
        },
        .if_then_stmt => {
            const cond = try irb.genNode(data.bin.lhs);
            const branch_index = irb.instructions.len;
            try irb.addInstNoReturn(.branch, undefined);
            const then_label = try irb.addLabel("then");
            _ = try irb.genNode(data.bin.rhs);
            const end_label = try irb.addLabel("end");
            const branch = try irb.arena.allocator().create(Ir.Inst.Branch);
            branch.* = .{
                .cond = cond,
                .then = then_label,
                .@"else" = end_label,
            };
            irb.instructions.items(.data)[branch_index] = .{ .branch = branch };
        },
        // .switch_stmt => {
        //     var wip_switch = WipSwitch{
        //         .cases = WipSwitch.Cases.init(irb.comp.gpa),
        //         .size = irb.node_ty[@enumToInt(data.bin.lhs)].sizeof(irb.comp).?,
        //     };
        //     defer wip_switch.cases.deinit();

        //     const old_wip_switch = irb.wip_switch;
        //     defer irb.wip_switch = old_wip_switch;
        //     irb.wip_switch = &wip_switch;

        //     const old_breaks = irb.breaks.items.len;
        //     defer irb.breaks.items.len = old_breaks;

        //     const cond = try irb.genNode(data.bin.lhs);
        //     const switch_index = irb.instructions.len;
        //     _ = try irb.addInst(.@"switch", undefined, ty);

        //     _ = try irb.genNode(data.bin.rhs); // body

        //     const end_ref = try irb.addInst(.label, .{ .label = "end" }, ty);
        //     const default_ref = wip_switch.default orelse end_ref;

        //     const inst_data = irb.instructions.items(.data);
        //     for (irb.breaks.items[old_breaks..]) |break_index| {
        //         inst_data[break_index] = .{ .un = end_ref };
        //     }

        //     const switch_data = try irb.arena.allocator().create(Ir.Inst.Switch);
        //     switch_data.* = .{
        //         .target = cond,
        //         .cases = try irb.arena.allocator().dupe(Ir.Inst.Switch.Case, wip_switch.cases.items),
        //         .default = default_ref,
        //     };
        //     inst_data[switch_index] = .{ .@"switch" = switch_data };
        // },
        // .case_stmt => {
        //     try irb.wip_switch.cases.append(.{
        //         .val = .{ .int = irb.tree.value_map.get(data.bin.lhs).? },
        //         .label = try irb.addInst(.label, .{ .label = "case" }, ty),
        //     });
        //     _ = try irb.genNode(data.bin.rhs);
        // },
        .default_stmt => {
            irb.wip_switch.default = try irb.addLabel("default");
            _ = try irb.genNode(data.un);
        },
        .while_stmt => {
            const old_breaks = irb.breaks.items.len;
            defer irb.breaks.items.len = old_breaks;
            const old_continues = irb.continues.items.len;
            defer irb.continues.items.len = old_continues;

            const start_label = try irb.addLabel("start");
            const cond = try irb.genNode(data.bin.lhs);
            const branch_index = irb.instructions.len;
            try irb.addInstNoReturn(.branch, undefined);
            const then_label = try irb.addLabel("then");
            _ = try irb.genNode(data.bin.rhs);
            try irb.addInstNoReturn(.jmp, .{ .un = start_label });
            const end_label = try irb.addLabel("end");

            const inst_data = irb.instructions.items(.data);
            for (irb.breaks.items[old_breaks..]) |break_index| {
                inst_data[break_index] = .{ .un = end_label };
            }
            const branch = try irb.arena.allocator().create(Ir.Inst.Branch);
            branch.* = .{
                .cond = cond,
                .then = then_label,
                .@"else" = end_label,
            };
            irb.instructions.items(.data)[branch_index] = .{ .branch = branch };
            for (irb.continues.items[old_continues..]) |continue_index| {
                inst_data[continue_index] = .{ .un = start_label };
            }
        },
        // .do_while_stmt => {
        //     const old_breaks = irb.breaks.items.len;
        //     defer irb.breaks.items.len = old_breaks;
        //     const old_continues = irb.continues.items.len;
        //     defer irb.continues.items.len = old_continues;

        //     const start_ref = try irb.addInst(.label, .{ .label = "start" }, ty);
        //     _ = try irb.genNode(data.bin.rhs);

        //     const cond_ref = try irb.addInst(.label, .{ .label = "cond" });
        //     const cond = try irb.genNode(data.bin.lhs);
        //     const jmp_index = irb.instructions.len;
        //     _ = try irb.addInst(.jmp_true, undefined, ty);
        //     const end_ref = try irb.addInst(.label, .{ .label = "end" }, ty);

        //     const inst_data = irb.instructions.items(.data);
        //     for (irb.breaks.items[old_breaks..]) |break_index| {
        //         inst_data[break_index] = .{ .un = end_ref };
        //     }
        //     inst_data[jmp_index] = .{ .bin = .{ .lhs = cond, .rhs = start_ref } };
        //     for (irb.continues.items[old_continues..]) |continue_index| {
        //         inst_data[continue_index] = .{ .un = cond_ref };
        //     }
        // },
        // .for_decl_stmt => {
        //     const old_breaks = irb.breaks.items.len;
        //     defer irb.breaks.items.len = old_breaks;
        //     const old_continues = irb.continues.items.len;
        //     defer irb.continues.items.len = old_continues;

        //     const for_decl = data.forDecl(irb.tree);
        //     for (for_decl.decls) |decl| _ = try irb.genNode(decl);

        //     const start_ref = try irb.addInst(.label, .{ .label = "start" }, ty);

        //     const jmp_index = irb.instructions.len;
        //     var cond: ?Ir.Ref = null;
        //     if (for_decl.cond != .none) {
        //         cond = try irb.genNode(for_decl.cond);
        //         _ = try irb.addInst(.jmp_false, undefined, ty);
        //     }

        //     _ = try irb.genNode(for_decl.body);

        //     const continue_ref = try irb.addInst(.label, .{ .label = "continue" }, ty);
        //     if (for_decl.incr != .none) {
        //         _ = try irb.genNode(for_decl.incr);
        //     }
        //     _ = try irb.addInst(.jmp, .{ .un = start_ref }, ty);

        //     const end_ref = try irb.addInst(.label, .{ .label = "end" }, ty);

        //     const inst_data = irb.instructions.items(.data);
        //     for (irb.breaks.items[old_breaks..]) |break_index| {
        //         inst_data[break_index] = .{ .un = end_ref };
        //     }
        //     if (cond) |some| {
        //         inst_data[jmp_index] = .{ .bin = .{ .lhs = some, .rhs = end_ref } };
        //     }
        //     for (irb.continues.items[old_continues..]) |continue_index| {
        //         inst_data[continue_index] = .{ .un = continue_ref };
        //     }
        // },
        .forever_stmt => {
            const old_breaks = irb.breaks.items.len;
            defer irb.breaks.items.len = old_breaks;
            const old_continues = irb.continues.items.len;
            defer irb.continues.items.len = old_continues;

            const start_label = try irb.addLabel("start");
            _ = try irb.genNode(data.un);
            try irb.addInstNoReturn(.jmp, .{ .un = start_label });
            const end_label = try irb.addLabel("end");

            const inst_data = irb.instructions.items(.data);
            for (irb.breaks.items[old_breaks..]) |break_index| {
                inst_data[break_index] = .{ .un = end_label };
            }
            for (irb.continues.items[old_continues..]) |continue_index| {
                inst_data[continue_index] = .{ .un = start_label };
            }
        },
        // .for_stmt => {
        //     const old_breaks = irb.breaks.items.len;
        //     defer irb.breaks.items.len = old_breaks;
        //     const old_continues = irb.continues.items.len;
        //     defer irb.continues.items.len = old_continues;

        //     const for_stmt = data.forStmt(irb.tree);
        //     if (for_stmt.init != .none) _ = try irb.genNode(for_stmt.init);

        //     const start_ref = try irb.addInst(.label, .{ .label = "start" }, ty);

        //     const jmp_index = irb.instructions.len;
        //     var cond: ?Ir.Ref = null;
        //     if (for_stmt.cond != .none) {
        //         cond = try irb.genNode(for_stmt.cond);
        //         _ = try irb.addInst(.jmp_false, undefined, ty);
        //     }

        //     _ = try irb.genNode(for_stmt.body);

        //     const continue_ref = try irb.addInst(.label, .{ .label = "continue" }, ty);
        //     if (for_stmt.incr != .none) {
        //         _ = try irb.genNode(for_stmt.incr);
        //     }
        //     _ = try irb.addInst(.jmp, .{ .un = start_ref }, ty);

        //     const end_ref = try irb.addInst(.label, .{ .label = "end" }, ty);

        //     const inst_data = irb.instructions.items(.data);
        //     for (irb.breaks.items[old_breaks..]) |break_index| {
        //         inst_data[break_index] = .{ .un = end_ref };
        //     }
        //     if (cond) |some| {
        //         inst_data[jmp_index] = .{ .bin = .{ .lhs = some, .rhs = end_ref } };
        //     }
        //     for (irb.continues.items[old_continues..]) |continue_index| {
        //         inst_data[continue_index] = .{ .un = continue_ref };
        //     }
        // },
        .continue_stmt => {
            try irb.continues.append(irb.comp.gpa, @intCast(u32, irb.instructions.len));
            try irb.addInstNoReturn(.jmp, undefined);
        },
        .break_stmt => {
            try irb.breaks.append(irb.comp.gpa, @intCast(u32, irb.instructions.len));
            try irb.addInstNoReturn(.jmp, undefined);
        },
        .return_stmt => {
            if (data.un != .none) {
                const operand = try irb.genNode(data.un);
                try irb.addInstVoid(.ret_value, .{ .un = operand });
            }
            try irb.returns.append(irb.comp.gpa, @intCast(u32, irb.instructions.len));
            try irb.addInstNoReturn(.jmp, undefined);
        },
        .comma_expr => {
            _ = try irb.genNode(data.bin.lhs);
            return irb.genNode(data.bin.rhs);
        },
        .assign_expr => {
            const rhs = try irb.genNode(data.bin.rhs);
            const lhs = try irb.genNode(data.bin.lhs);
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
        .equal_expr => return irb.genBinOp(node, .cmp_eql),
        .not_equal_expr => return irb.genBinOp(node, .cmp_not_eql),
        .less_than_expr => return irb.genBinOp(node, .cmp_lt),
        .less_than_equal_expr => return irb.genBinOp(node, .cmp_lte),
        .greater_than_expr => return irb.genBinOp(node, .cmp_gt),
        .greater_than_equal_expr => return irb.genBinOp(node, .cmp_gte),
        .shl_expr => return irb.genBinOp(node, .bit_shl),
        .shr_expr => return irb.genBinOp(node, .bit_shr),
        .add_expr => return irb.genBinOp(node, .add),
        .sub_expr => return irb.genBinOp(node, .sub),
        .mul_expr => return irb.genBinOp(node, .mul),
        .div_expr => return irb.genBinOp(node, .div),
        .mod_expr => return irb.genBinOp(node, .mod),
        .addr_of_expr => return try irb.genNode(data.un),
        .deref_expr => {
            const operand = try irb.genNode(data.un);
            return irb.addInst(.load, .{ .un = operand }, ty);
        },
        .plus_expr => return irb.genNode(data.un),
        // .negate_expr => {
        //     const zero = try irb.addInst(.const_int, .{ .int = 0 }, ty);
        //     const operand = try irb.genNode(data.un);
        //     return irb.addInst(.sub, .{ .bin = .{ .lhs = zero, .rhs = operand } }, ty);
        // },
        .bit_not_expr => {
            const operand = try irb.genNode(data.un);
            return irb.addInst(.bit_not, .{ .un = operand }, ty);
        },
        // .bool_not_expr => {
        //     const zero = try irb.addInst(.const_int, .{ .int = 0 }, ty);
        //     const operand = try irb.genNode(data.un);
        //     return irb.addInst(.cmp_not_eql, .{ .bin = .{ .lhs = zero, .rhs = operand } }, ty);
        // },
        // .pre_inc_expr => {
        //     const operand = try irb.genNode(data.un);
        //     const val = try irb.addInst(.load, .{ .un = operand }, ty);
        //     const one = try irb.addInst(.const_int, .{ .int = 1 }, ty);
        //     const plus_one = try irb.addInst(.add, .{ .bin = .{ .lhs = val, .rhs = one } }, ty);
        //     _ = try irb.addInst(.store, .{ .bin = .{ .lhs = operand, .rhs = plus_one } }, ty);
        //     return plus_one;
        // },
        // .pre_dec_expr => {
        //     const operand = try irb.genNode(data.un);
        //     const val = try irb.addInst(.load, .{ .un = operand }, ty);
        //     const one = try irb.addInst(.const_int, .{ .int = 1 }, ty);
        //     const plus_one = try irb.addInst(.sub, .{ .bin = .{ .lhs = val, .rhs = one } }, ty);
        //     _ = try irb.addInst(.store, .{ .bin = .{ .lhs = operand, .rhs = plus_one } }, ty);
        //     return plus_one;
        // },
        // .post_inc_expr => {
        //     const operand = try irb.genNode(data.un);
        //     const val = try irb.addInst(.load, .{ .un = operand }, ty);
        //     const one = try irb.addInst(.const_int, .{ .int = 1 }, ty);
        //     const plus_one = try irb.addInst(.add, .{ .bin = .{ .lhs = val, .rhs = one } }, ty);
        //     _ = try irb.addInst(.store, .{ .bin = .{ .lhs = operand, .rhs = plus_one } }, ty);
        //     return val;
        // },
        // .post_dec_expr => {
        //     const operand = try irb.genNode(data.un);
        //     const val = try irb.addInst(.load, .{ .un = operand }, ty);
        //     const one = try irb.addInst(.const_int, .{ .int = 1 }, ty);
        //     const plus_one = try irb.addInst(.sub, .{ .bin = .{ .lhs = val, .rhs = one } }, ty);
        //     _ = try irb.addInst(.store, .{ .bin = .{ .lhs = operand, .rhs = plus_one } }, ty);
        //     return val;
        // },
        .paren_expr => return irb.genNode(data.un),
        .decl_ref_expr => {
            const name = try irb.comp.intern(irb.tree.tokSlice(data.decl_ref));
            var i = irb.symbols.items.len;
            while (i > 0) {
                i -= 1;
                if (irb.symbols.items[i].name == name) {
                    return irb.symbols.items[i].val;
                }
            }

            return irb.addInst(.symbol, .{ .arg = 0 }, ty);
        },
        // .int_literal => {
        //     return irb.addInst(.const_int, .{ .int = data.int }, ty);
        // },
        // .implicit_return => {
        //     if (irb.node_ty[@enumToInt(node)].get(.void)) |_| {
        //         _ = try irb.addInst(.ret_void, .{ .none = {} }, ty);
        //     } else {
        //         const zero = try irb.addInst(.const_int, .{ .int = 0 }, ty);
        //         _ = try irb.addInst(.ret, .{ .un = zero }, ty);
        //     }
        // },
        else => {},
    }
    return @as(Ir.Ref, undefined); // statement, value is ignored
}

fn genCompoundAssign(irb: *IrBuilder, node: NodeIndex, tag: Ir.Inst.Tag) Error!Ir.Ref {
    const bin = irb.node_data[@enumToInt(node)].bin;
    const ty = irb.node_ty[@enumToInt(node)];
    const rhs = try irb.genNode(bin.rhs);
    const lhs = try irb.genNode(bin.lhs);
    const res = try irb.addInst(tag, .{ .bin = .{ .lhs = lhs, .rhs = rhs } }, ty);
    try irb.addInstVoid(.store, .{ .bin = .{ .lhs = lhs, .rhs = res } });
    return res;
}

fn genBinOp(irb: *IrBuilder, node: NodeIndex, tag: Ir.Inst.Tag) Error!Ir.Ref {
    const bin = irb.node_data[@enumToInt(node)].bin;
    const ty = irb.node_ty[@enumToInt(node)];
    const lhs = try irb.genNode(bin.lhs);
    const rhs = try irb.genNode(bin.rhs);
    return irb.addInst(tag, .{ .bin = .{ .lhs = lhs, .rhs = rhs } }, ty);
}

fn genVar(irb: *IrBuilder, decl: NodeIndex) Error!void {
    _ = irb;
    _ = decl;
}
