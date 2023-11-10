const std = @import("std");
const assert = std.debug.assert;
const Allocator = std.mem.Allocator;
const Compilation = @import("Compilation.zig");
const Interner = @import("Interner.zig");
const StringId = @import("StringInterner.zig").StringId;
const Value = @import("Value.zig");

const Ir = @This();

interner: *Interner,
decls: std.StringArrayHashMapUnmanaged(Decl),

pub const Decl = struct {
    instructions: std.MultiArrayList(Inst),
    body: std.ArrayListUnmanaged(Ref),
    arena: std.heap.ArenaAllocator.State,

    pub fn deinit(decl: *Decl, gpa: Allocator) void {
        decl.instructions.deinit(gpa);
        decl.body.deinit(gpa);
        decl.arena.promote(gpa).deinit();
    }
};

pub const Builder = struct {
    gpa: Allocator,
    arena: std.heap.ArenaAllocator,
    decls: std.StringArrayHashMapUnmanaged(Decl) = .{},
    instructions: std.MultiArrayList(Ir.Inst) = .{},
    body: std.ArrayListUnmanaged(Ref) = .{},
    alloc_count: u32 = 0,
    arg_count: u32 = 0,
    interner: *Interner,
    current_label: Ref = undefined,

    pub fn deinit(b: *Builder) void {
        for (b.decls.values()) |*decl| {
            decl.deinit(b.gpa);
        }
        b.arena.deinit();
        b.instructions.deinit(b.gpa);
        b.body.deinit(b.gpa);
        b.* = undefined;
    }

    pub fn finish(b: *Builder) Ir {
        return .{
            .interner = b.interner,
            .decls = b.decls.move(),
        };
    }

    pub fn startFn(b: *Builder) Allocator.Error!void {
        const entry = try b.makeLabel("entry");
        try b.body.append(b.gpa, entry);
        b.current_label = entry;
    }

    pub fn finishFn(b: *Builder, name: []const u8) !void {
        var duped_instructions = try b.instructions.clone(b.gpa);
        errdefer duped_instructions.deinit(b.gpa);
        var duped_body = try b.body.clone(b.gpa);
        errdefer duped_body.deinit(b.gpa);

        try b.decls.put(b.gpa, name, .{
            .instructions = duped_instructions,
            .body = duped_body,
            .arena = b.arena.state,
        });
        b.instructions.shrinkRetainingCapacity(0);
        b.body.shrinkRetainingCapacity(0);
        b.arena = std.heap.ArenaAllocator.init(b.gpa);
        b.alloc_count = 0;
        b.arg_count = 0;
    }

    pub fn startBlock(b: *Builder, label: Ref) !void {
        try b.body.append(b.gpa, label);
        b.current_label = label;
    }

    pub fn addArg(b: *Builder, ty: Interner.Ref) Allocator.Error!Ref {
        const ref: Ref = @enumFromInt(b.instructions.len);
        try b.instructions.append(b.gpa, .{ .tag = .arg, .data = .{ .none = {} }, .ty = ty });
        try b.body.insert(b.gpa, b.arg_count, ref);
        b.arg_count += 1;
        return ref;
    }

    pub fn addAlloc(b: *Builder, size: u32, @"align": u32) Allocator.Error!Ref {
        const ref: Ref = @enumFromInt(b.instructions.len);
        try b.instructions.append(b.gpa, .{
            .tag = .alloc,
            .data = .{ .alloc = .{ .size = size, .@"align" = @"align" } },
            .ty = .ptr,
        });
        try b.body.insert(b.gpa, b.alloc_count + b.arg_count + 1, ref);
        b.alloc_count += 1;
        return ref;
    }

    pub fn addInst(b: *Builder, tag: Ir.Inst.Tag, data: Ir.Inst.Data, ty: Interner.Ref) Allocator.Error!Ref {
        const ref: Ref = @enumFromInt(b.instructions.len);
        try b.instructions.append(b.gpa, .{ .tag = tag, .data = data, .ty = ty });
        try b.body.append(b.gpa, ref);
        return ref;
    }

    pub fn makeLabel(b: *Builder, name: [*:0]const u8) Allocator.Error!Ref {
        const ref: Ref = @enumFromInt(b.instructions.len);
        try b.instructions.append(b.gpa, .{ .tag = .label, .data = .{ .label = name }, .ty = .void });
        return ref;
    }

    pub fn addJump(b: *Builder, label: Ref) Allocator.Error!void {
        _ = try b.addInst(.jmp, .{ .un = label }, .noreturn);
    }

    pub fn addBranch(b: *Builder, cond: Ref, true_label: Ref, false_label: Ref) Allocator.Error!void {
        const branch = try b.arena.allocator().create(Ir.Inst.Branch);
        branch.* = .{
            .cond = cond,
            .then = true_label,
            .@"else" = false_label,
        };
        _ = try b.addInst(.branch, .{ .branch = branch }, .noreturn);
    }

    pub fn addSwitch(b: *Builder, target: Ref, values: []Interner.Ref, labels: []Ref, default: Ref) Allocator.Error!void {
        assert(values.len == labels.len);
        const a = b.arena.allocator();
        const @"switch" = try a.create(Ir.Inst.Switch);
        @"switch".* = .{
            .target = target,
            .cases_len = @intCast(values.len),
            .case_vals = (try a.dupe(Interner.Ref, values)).ptr,
            .case_labels = (try a.dupe(Ref, labels)).ptr,
            .default = default,
        };
        _ = try b.addInst(.@"switch", .{ .@"switch" = @"switch" }, .noreturn);
    }

    pub fn addStore(b: *Builder, ptr: Ref, val: Ref) Allocator.Error!void {
        _ = try b.addInst(.store, .{ .bin = .{ .lhs = ptr, .rhs = val } }, .void);
    }

    pub fn addConstant(b: *Builder, val: Value, ty: Interner.Ref) Allocator.Error!Ref {
        const ref: Ref = @enumFromInt(b.instructions.len);
        try b.instructions.append(b.gpa, .{
            .tag = .constant,
            .data = .{ .constant = val.ref() },
            .ty = ty,
        });
        return ref;
    }

    pub fn addPhi(b: *Builder, inputs: []const Inst.Phi.Input, ty: Interner.Ref) Allocator.Error!Ref {
        const a = b.arena.allocator();
        const input_refs = try a.alloc(Ref, inputs.len * 2 + 1);
        input_refs[0] = @enumFromInt(inputs.len);
        std.mem.copy(Ref, input_refs[1..], std.mem.bytesAsSlice(Ref, std.mem.sliceAsBytes(inputs)));

        return b.addInst(.phi, .{ .phi = .{ .ptr = input_refs.ptr } }, ty);
    }

    pub fn addSelect(b: *Builder, cond: Ref, then: Ref, @"else": Ref, ty: Interner.Ref) Allocator.Error!Ref {
        const branch = try b.arena.allocator().create(Ir.Inst.Branch);
        branch.* = .{
            .cond = cond,
            .then = then,
            .@"else" = @"else",
        };
        return b.addInst(.select, .{ .branch = branch }, ty);
    }
};

pub const Ref = enum(u32) { none = std.math.maxInt(u32), _ };

pub const Inst = struct {
    tag: Tag,
    data: Data,
    ty: Interner.Ref,

    pub const Tag = enum {
        // data.constant
        // not included in blocks
        constant,

        // data.arg
        // not included in blocks
        arg,
        symbol,

        // data.label
        label,

        // data.block
        label_addr,
        jmp,

        // data.switch
        @"switch",

        // data.branch
        branch,
        select,

        // data.un
        jmp_val,

        // data.call
        call,

        // data.alloc
        alloc,

        // data.phi
        phi,

        // data.bin
        store,
        bit_or,
        bit_xor,
        bit_and,
        bit_shl,
        bit_shr,
        cmp_eq,
        cmp_ne,
        cmp_lt,
        cmp_lte,
        cmp_gt,
        cmp_gte,
        add,
        sub,
        mul,
        div,
        mod,

        // data.un
        ret,
        load,
        bit_not,
        negate,
        trunc,
        zext,
        sext,
    };

    pub const Data = union {
        constant: Interner.Ref,
        none: void,
        bin: struct {
            lhs: Ref,
            rhs: Ref,
        },
        un: Ref,
        arg: u32,
        alloc: struct {
            size: u32,
            @"align": u32,
        },
        @"switch": *Switch,
        call: *Call,
        label: [*:0]const u8,
        branch: *Branch,
        phi: Phi,
    };

    pub const Branch = struct {
        cond: Ref,
        then: Ref,
        @"else": Ref,
    };

    pub const Switch = struct {
        target: Ref,
        cases_len: u32,
        default: Ref,
        case_vals: [*]Interner.Ref,
        case_labels: [*]Ref,
    };

    pub const Call = struct {
        func: Ref,
        args_len: u32,
        args_ptr: [*]Ref,

        pub fn args(c: Call) []Ref {
            return c.args_ptr[0..c.args_len];
        }
    };

    pub const Phi = struct {
        ptr: [*]Ir.Ref,

        pub const Input = struct {
            label: Ir.Ref,
            value: Ir.Ref,
        };

        pub fn inputs(p: Phi) []Input {
            const len = @intFromEnum(p.ptr[0]) * 2;
            const slice = (p.ptr + 1)[0..len];
            return std.mem.bytesAsSlice(Input, std.mem.sliceAsBytes(slice));
        }
    };
};

pub fn deinit(ir: *Ir, gpa: std.mem.Allocator) void {
    for (ir.decls.values()) |*decl| {
        decl.deinit(gpa);
    }
    ir.decls.deinit(gpa);
    ir.* = undefined;
}

const util = @import("util.zig");
const TYPE = util.Color.purple;
const INST = util.Color.cyan;
const REF = util.Color.blue;
const LITERAL = util.Color.green;
const ATTRIBUTE = util.Color.yellow;

const RefMap = std.AutoArrayHashMap(Ref, void);

pub fn dump(ir: *const Ir, gpa: Allocator, color: bool, w: anytype) !void {
    for (ir.decls.keys(), ir.decls.values()) |name, *decl| {
        try ir.dumpDecl(decl, gpa, name, color, w);
    }
}

fn dumpDecl(ir: *const Ir, decl: *const Decl, gpa: Allocator, name: []const u8, color: bool, w: anytype) !void {
    const tags = decl.instructions.items(.tag);
    const data = decl.instructions.items(.data);

    var ref_map = RefMap.init(gpa);
    defer ref_map.deinit();

    var label_map = RefMap.init(gpa);
    defer label_map.deinit();

    const ret_inst = decl.body.items[decl.body.items.len - 1];
    const ret_operand = data[@intFromEnum(ret_inst)].un;
    const ret_ty = decl.instructions.items(.ty)[@intFromEnum(ret_operand)];
    try ir.writeType(ret_ty, color, w);
    if (color) util.setColor(REF, w);
    try w.print(" @{s}", .{name});
    if (color) util.setColor(.reset, w);
    try w.writeAll("(");

    var arg_count: u32 = 0;
    while (true) : (arg_count += 1) {
        const ref = decl.body.items[arg_count];
        if (tags[@intFromEnum(ref)] != .arg) break;
        if (arg_count != 0) try w.writeAll(", ");
        try ref_map.put(ref, {});
        try ir.writeRef(decl, &ref_map, ref, color, w);
        if (color) util.setColor(.reset, w);
    }
    try w.writeAll(") {\n");
    for (decl.body.items[arg_count..]) |ref| {
        switch (tags[@intFromEnum(ref)]) {
            .label => try label_map.put(ref, {}),
            else => {},
        }
    }

    for (decl.body.items[arg_count..]) |ref| {
        const i = @intFromEnum(ref);
        const tag = tags[i];
        switch (tag) {
            .arg, .constant, .symbol => unreachable,
            .label => {
                const label_index = label_map.getIndex(ref).?;
                if (color) util.setColor(REF, w);
                try w.print("{s}.{d}:\n", .{ data[i].label, label_index });
            },
            // .label_val => {
            //     const un = data[i].un;
            //     try w.print("    %{d} = label.{d}\n", .{ i, @intFromEnum(un) });
            // },
            .jmp => {
                const un = data[i].un;
                if (color) util.setColor(INST, w);
                try w.writeAll("    jmp ");
                try writeLabel(decl, &label_map, un, color, w);
                try w.writeByte('\n');
            },
            .branch => {
                const br = data[i].branch;
                if (color) util.setColor(INST, w);
                try w.writeAll("    branch ");
                try ir.writeRef(decl, &ref_map, br.cond, color, w);
                if (color) util.setColor(.reset, w);
                try w.writeAll(", ");
                try writeLabel(decl, &label_map, br.then, color, w);
                if (color) util.setColor(.reset, w);
                try w.writeAll(", ");
                try writeLabel(decl, &label_map, br.@"else", color, w);
                try w.writeByte('\n');
            },
            .select => {
                const br = data[i].branch;
                try ir.writeNewRef(decl, &ref_map, ref, color, w);
                try w.writeAll("select ");
                try ir.writeRef(decl, &ref_map, br.cond, color, w);
                if (color) util.setColor(.reset, w);
                try w.writeAll(", ");
                try ir.writeRef(decl, &ref_map, br.then, color, w);
                if (color) util.setColor(.reset, w);
                try w.writeAll(", ");
                try ir.writeRef(decl, &ref_map, br.@"else", color, w);
                try w.writeByte('\n');
            },
            // .jmp_val => {
            //     const bin = data[i].bin;
            //     try w.print("    %{s} %{d} label.{d}\n", .{ @tagName(tag), @intFromEnum(bin.lhs), @intFromEnum(bin.rhs) });
            // },
            .@"switch" => {
                const @"switch" = data[i].@"switch";
                if (color) util.setColor(INST, w);
                try w.writeAll("    switch ");
                try ir.writeRef(decl, &ref_map, @"switch".target, color, w);
                if (color) util.setColor(.reset, w);
                try w.writeAll(" {");
                for (@"switch".case_vals[0..@"switch".cases_len], @"switch".case_labels) |val_ref, label_ref| {
                    try w.writeAll("\n        ");
                    try ir.writeValue(val_ref, color, w);
                    if (color) util.setColor(.reset, w);
                    try w.writeAll(" => ");
                    try writeLabel(decl, &label_map, label_ref, color, w);
                    if (color) util.setColor(.reset, w);
                }
                if (color) util.setColor(LITERAL, w);
                try w.writeAll("\n        default ");
                if (color) util.setColor(.reset, w);
                try w.writeAll("=> ");
                try writeLabel(decl, &label_map, @"switch".default, color, w);
                if (color) util.setColor(.reset, w);
                try w.writeAll("\n    }\n");
            },
            .call => {
                const call = data[i].call;
                try ir.writeNewRef(decl, &ref_map, ref, color, w);
                try w.writeAll("call ");
                try ir.writeRef(decl, &ref_map, call.func, color, w);
                if (color) util.setColor(.reset, w);
                try w.writeAll("(");
                for (call.args(), 0..) |arg, arg_i| {
                    if (arg_i != 0) try w.writeAll(", ");
                    try ir.writeRef(decl, &ref_map, arg, color, w);
                    if (color) util.setColor(.reset, w);
                }
                try w.writeAll(")\n");
            },
            .alloc => {
                const alloc = data[i].alloc;
                try ir.writeNewRef(decl, &ref_map, ref, color, w);
                try w.writeAll("alloc ");
                if (color) util.setColor(ATTRIBUTE, w);
                try w.writeAll("size ");
                if (color) util.setColor(LITERAL, w);
                try w.print("{d}", .{alloc.size});
                if (color) util.setColor(ATTRIBUTE, w);
                try w.writeAll(" align ");
                if (color) util.setColor(LITERAL, w);
                try w.print("{d}", .{alloc.@"align"});
                try w.writeByte('\n');
            },
            .phi => {
                try ir.writeNewRef(decl, &ref_map, ref, color, w);
                try w.writeAll("phi");
                if (color) util.setColor(.reset, w);
                try w.writeAll(" {");
                for (data[i].phi.inputs()) |input| {
                    try w.writeAll("\n        ");
                    try writeLabel(decl, &label_map, input.label, color, w);
                    if (color) util.setColor(.reset, w);
                    try w.writeAll(" => ");
                    try ir.writeRef(decl, &ref_map, input.value, color, w);
                    if (color) util.setColor(.reset, w);
                }
                if (color) util.setColor(.reset, w);
                try w.writeAll("\n    }\n");
            },
            .store => {
                const bin = data[i].bin;
                if (color) util.setColor(INST, w);
                try w.writeAll("    store ");
                try ir.writeRef(decl, &ref_map, bin.lhs, color, w);
                if (color) util.setColor(.reset, w);
                try w.writeAll(", ");
                try ir.writeRef(decl, &ref_map, bin.rhs, color, w);
                try w.writeByte('\n');
            },
            .ret => {
                if (color) util.setColor(INST, w);
                try w.writeAll("    ret ");
                if (data[i].un != .none) try ir.writeRef(decl, &ref_map, data[i].un, color, w);
                try w.writeByte('\n');
            },
            .load => {
                try ir.writeNewRef(decl, &ref_map, ref, color, w);
                try w.writeAll("load ");
                try ir.writeRef(decl, &ref_map, data[i].un, color, w);
                try w.writeByte('\n');
            },
            .bit_or,
            .bit_xor,
            .bit_and,
            .bit_shl,
            .bit_shr,
            .cmp_eq,
            .cmp_ne,
            .cmp_lt,
            .cmp_lte,
            .cmp_gt,
            .cmp_gte,
            .add,
            .sub,
            .mul,
            .div,
            .mod,
            => {
                const bin = data[i].bin;
                try ir.writeNewRef(decl, &ref_map, ref, color, w);
                try w.print("{s} ", .{@tagName(tag)});
                try ir.writeRef(decl, &ref_map, bin.lhs, color, w);
                if (color) util.setColor(.reset, w);
                try w.writeAll(", ");
                try ir.writeRef(decl, &ref_map, bin.rhs, color, w);
                try w.writeByte('\n');
            },
            .bit_not,
            .negate,
            .trunc,
            .zext,
            .sext,
            => {
                const un = data[i].un;
                try ir.writeNewRef(decl, &ref_map, ref, color, w);
                try w.print("{s} ", .{@tagName(tag)});
                try ir.writeRef(decl, &ref_map, un, color, w);
                try w.writeByte('\n');
            },
            .label_addr, .jmp_val => {},
        }
    }
    if (color) util.setColor(.reset, w);
    try w.writeAll("}\n\n");
}

fn writeType(ir: Ir, ty_ref: Interner.Ref, color: bool, w: anytype) !void {
    const ty = ir.interner.get(ty_ref);
    if (color) util.setColor(TYPE, w);
    switch (ty) {
        .ptr_ty, .noreturn_ty, .void_ty, .func_ty => try w.writeAll(@tagName(ty)),
        .int_ty => |bits| try w.print("i{d}", .{bits}),
        .float_ty => |bits| try w.print("f{d}", .{bits}),
        .array_ty => |info| {
            try w.print("[{d} * ", .{info.len});
            try ir.writeType(info.child, false, w);
            try w.writeByte(']');
        },
        .vector_ty => |info| {
            try w.print("<{d} * ", .{info.len});
            try ir.writeType(info.child, false, w);
            try w.writeByte('>');
        },
        .record_ty => |elems| {
            // TODO collect into buffer and only print once
            try w.writeAll("{ ");
            for (elems, 0..) |elem, i| {
                if (i != 0) try w.writeAll(", ");
                try ir.writeType(elem, color, w);
            }
            try w.writeAll(" }");
        },
        else => unreachable, // not a type
    }
}

fn writeValue(ir: Ir, val_ref: Interner.Ref, color: bool, w: anytype) !void {
    const v: Value = .{ .opt_ref = @enumFromInt(@intFromEnum(val_ref)) };
    if (color) util.setColor(LITERAL, w);
    const key = ir.interner.get(v.ref());
    switch (key) {
        .null => return w.writeAll("nullptr_t"),
        .int => |repr| switch (repr) {
            inline else => |x| return w.print("{d}", .{x}),
        },
        .float => |repr| switch (repr) {
            inline else => |x| return w.print("{d}", .{@as(f64, @floatCast(x))}),
        },
        .bytes => |b| return std.zig.fmt.stringEscape(b, "", .{}, w),
        else => unreachable, // not a value
    }
}

fn writeRef(ir: Ir, decl: *const Decl, ref_map: *RefMap, ref: Ref, color: bool, w: anytype) !void {
    assert(ref != .none);
    const index = @intFromEnum(ref);
    const ty_ref = decl.instructions.items(.ty)[index];
    if (decl.instructions.items(.tag)[index] == .constant) {
        try ir.writeType(ty_ref, color, w);
        const v_ref = decl.instructions.items(.data)[index].constant;
        try w.writeByte(' ');
        try ir.writeValue(v_ref, color, w);
        return;
    } else if (decl.instructions.items(.tag)[index] == .symbol) {
        const name = decl.instructions.items(.data)[index].label;
        try ir.writeType(ty_ref, color, w);
        if (color) util.setColor(REF, w);
        try w.print(" @{s}", .{name});
        return;
    }
    try ir.writeType(ty_ref, color, w);
    if (color) util.setColor(REF, w);
    const ref_index = ref_map.getIndex(ref).?;
    try w.print(" %{d}", .{ref_index});
}

fn writeNewRef(ir: Ir, decl: *const Decl, ref_map: *RefMap, ref: Ref, color: bool, w: anytype) !void {
    try ref_map.put(ref, {});
    try w.writeAll("    ");
    try ir.writeRef(decl, ref_map, ref, color, w);
    if (color) util.setColor(.reset, w);
    try w.writeAll(" = ");
    if (color) util.setColor(INST, w);
}

fn writeLabel(decl: *const Decl, label_map: *RefMap, ref: Ref, color: bool, w: anytype) !void {
    assert(ref != .none);
    const index = @intFromEnum(ref);
    const label = decl.instructions.items(.data)[index].label;
    if (color) util.setColor(REF, w);
    const label_index = label_map.getIndex(ref).?;
    try w.print("{s}.{d}", .{ label, label_index });
}
