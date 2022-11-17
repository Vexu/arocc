const std = @import("std");
const IrPool = @import("IrPool.zig");

const Ir = @This();

pool: IrPool,
// decls: std.StringArrayHashMapUnmanaged(Decl),

// pub const Decl = struct {
instructions: std.MultiArrayList(Inst),
body: std.ArrayListUnmanaged(Ir.Ref),
arena: std.heap.ArenaAllocator.State,
// };

// pub const Block = struct {
//     name: [*:0]const u8,
//     insts: [*]Inst,
//     len: u32,
//     capacity: u32,
// };

pub const Ref = enum(u32) { _ };

pub const Inst = struct {
    tag: Tag,
    data: Data,
    ty: IrPool.Ref,

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

        // data.un
        jmp_val,

        // data.call
        call,

        // data.alloc
        alloc,

        // data.bin
        store,
        bit_or,
        bit_xor,
        bit_and,
        bit_shl,
        bit_shr,
        cmp_eql,
        cmp_not_eql,
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
        ret_value,
        load,
        bit_not,
        negate,

        // data.none
        ret,
    };

    pub const Data = union {
        constant: IrPool.Ref,
        none: void,
        bin: struct {
            lhs: Ref,
            rhs: Ref,
        },
        un: Ref,
        arg: u32,
        alloc: u64,
        @"switch": *Switch,
        @"call": *Call,
        // block: *Block,
        label: [*:0]const u8,
        branch: *Branch,
    };

    pub const Branch = struct {
        cond: Ref,
        // then: *Block,
        // @"else": *Block,
        then: Ref,
        @"else": Ref,
    };

    pub const Switch = struct {
        target: Ref,
        cases_len: u32,
        // default: *Block,
        @"else": Ref,
        case_vals: [*]IrPool.Ref,
        // case_labels: [*]*Block,
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
};

pub fn deinit(ir: *Ir, gpa: std.mem.Allocator) void {
    ir.arena.promote(gpa).deinit();
    ir.instructions.deinit(gpa);
    ir.* = undefined;
}

pub fn dump(ir: Ir, name: []const u8, w: anytype) !void {
    const tags = ir.instructions.items(.tag);
    const data = ir.instructions.items(.data);

    try w.print("{s}(", .{name});
    for (tags) |tag, i| {
        if (tag != .arg) break;
        if (i != 0) try w.writeAll(", ");
        try ir.writeRef(@intToEnum(Ref, i), w);
    }
    try w.writeAll(") {\n");

    for (ir.body.items) |ref| {
        const i = @enumToInt(ref);
        const tag = tags[i];
        switch (tag) {
            .arg => unreachable,
            .label => try w.print("{s}.{d}:\n", .{ data[i].label, i }),
            // .label_val => {
            //     const un = data[i].un;
            //     try w.print("    %{d} = label.{d}\n", .{ i, @enumToInt(un) });
            // },
            .jmp => {
                const un = data[i].un;
                try w.writeAll("    jmp ");
                try ir.writeLabel(un, w);
                try w.writeByte('\n');
            },
            // .jmp_false, .jmp_true, .jmp_val => {
            //     const bin = data[i].bin;
            //     try w.print("    %{s} %{d} label.{d}\n", .{ @tagName(tag), @enumToInt(bin.lhs), @enumToInt(bin.rhs) });
            // },
            .@"switch" => {
                const @"switch" = data[i].@"switch";
                try w.print("    {s} %{d} {{\n", .{ @tagName(tag), @enumToInt(@"switch".target) });
                // for (@"switch".cases) |case| {
                //     try w.writeAll("        ");
                //     try dumpVal(.const_int, case.val, w);
                //     try w.print(" label.{d}\n", .{@enumToInt(case.label)});
                // }
                // try w.print("        default label.{d}\n    }}\n", .{@enumToInt(@"switch".default)});
            },
            .call => {
                const call = data[i].call;
                try w.print("    %{d} = call {d} (", .{ i, @enumToInt(call.func) });
                for (call.args()) |arg, arg_i| {
                    if (arg_i != 0) try w.writeAll(", ");
                    try w.print("%{d}", .{@enumToInt(arg)});
                }
                try w.writeAll(")\n");
            },
            .symbol => {
                try w.print("    %{d} = symbol\n", .{i});
            },
            .alloc => {
                const size = data[i].alloc;
                try w.print("    %{d} = alloc {d}\n", .{ i, size });
            },
            .store => {
                const bin = data[i].bin;
                try w.writeAll("    store ");
                try ir.writeRef(bin.lhs, w);
                try w.writeAll(", ");
                try ir.writeRef(bin.rhs, w);
                try w.writeByte('\n');
            },
            .ret => {
                try w.writeAll("    ret ");
                try ir.writeRef(data[i].un, w);
                try w.writeByte('\n');
            },
            // .ret_void => {
            //     try w.writeAll("    ret\n");
            // },
            .load => {
                try w.print("    %{d} = load %{d}\n", .{ i, @enumToInt(data[i].un) });
            },
            .bit_or,
            .bit_xor,
            .bit_and,
            .bit_shl,
            .bit_shr,
            .cmp_eql,
            .cmp_not_eql,
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
                try w.print(
                    "    %{d} = {s} %{d}, %{d}\n",
                    .{ i, @tagName(tag), @enumToInt(bin.lhs), @enumToInt(bin.rhs) },
                );
            },
            .bit_not,
            .negate,
            => {
                const un = data[i].un;
                try w.print("    %{d} = {s} %{d}\n", .{ i, @tagName(tag), @enumToInt(un) });
            },
            else => {},
        }
    }
    try w.print("}} // {s}\n\n", .{name});
}

fn writeRef(ir: Ir, ref: Ref, w: anytype) !void {
    const index = @enumToInt(ref);
    const ty_ref = ir.instructions.items(.ty)[index];
    const ty = ir.pool.get(ty_ref);
    if (ir.instructions.items(.tag)[index] == .constant) {
        try w.print("{s} ", .{@tagName(ty)});
        const v_ref = ir.instructions.items(.data)[index].constant;
        const v = ir.pool.get(v_ref).value;
        switch (v.tag) {
            .unavailable => try w.writeAll("unavailable"),
            .int => try w.print("{d}", .{v.data.int}),
            .bytes => try w.print("\"{s}\"", .{v.data.bytes}),
            // std.fmt does @as instead of @floatCast
            .float => try w.print("{d}", .{@floatCast(f64, v.data.float)}),
            else => try w.print("({s})", .{@tagName(v.tag)}),
        }
        return;
    }
    try w.print("{s} %{d}", .{ @tagName(ty), index });
}

fn writeLabel(ir: Ir, ref: Ref, w: anytype) !void {
    const index = @enumToInt(ref);
    const label = ir.instructions.items(.data)[index].label;
    try w.print("{s}.{d}", .{ label, index });
}
