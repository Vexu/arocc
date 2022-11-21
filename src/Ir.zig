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
        select,

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
        alloc: struct {
            size: u32,
            @"align": u32,
        },
        @"switch": *Switch,
        call: *Call,
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
        default: Ref,
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

const util = @import("util.zig");
const TYPE = util.Color.purple;
const INST = util.Color.cyan;
const REF = util.Color.blue;
const LITERAL = util.Color.green;
const ATTRIBUTE = util.Color.yellow;

pub fn dump(ir: Ir, name: []const u8, color: bool, w: anytype) !void {
    const tags = ir.instructions.items(.tag);
    const data = ir.instructions.items(.data);

    if (color) util.setColor(REF, w);
    try w.writeAll(name);
    if (color) util.setColor(.reset, w);
    try w.writeAll(" (");
    for (tags) |tag, i| {
        if (tag != .arg) break;
        if (i != 0) try w.writeAll(", ");
        try ir.writeRef(@intToEnum(Ref, i), color, w);
        if (color) util.setColor(.reset, w);
    }
    try w.writeAll(") {\n");

    for (ir.body.items) |ref| {
        const i = @enumToInt(ref);
        const tag = tags[i];
        switch (tag) {
            .arg, .constant, .symbol => unreachable,
            .label => {
                if (color) util.setColor(REF, w);
                try w.print("{s}.{d}:\n", .{ data[i].label, i });
            },
            // .label_val => {
            //     const un = data[i].un;
            //     try w.print("    %{d} = label.{d}\n", .{ i, @enumToInt(un) });
            // },
            .jmp => {
                const un = data[i].un;
                if (color) util.setColor(INST, w);
                try w.writeAll("    jmp ");
                try ir.writeLabel(un, color, w);
                try w.writeByte('\n');
            },
            .branch => {
                const br = data[i].branch;
                if (color) util.setColor(INST, w);
                try w.writeAll("    branch ");
                try ir.writeRef(br.cond, color, w);
                if (color) util.setColor(.reset, w);
                try w.writeAll(", ");
                try ir.writeLabel(br.then, color, w);
                if (color) util.setColor(.reset, w);
                try w.writeAll(", ");
                try ir.writeLabel(br.@"else", color, w);
                try w.writeByte('\n');
            },
            .select => {
                const br = data[i].branch;
                try w.writeAll("    ");
                try ir.writeRef(@intToEnum(Ref, i), color, w);
                if (color) util.setColor(.reset, w);
                try w.writeAll(" = ");
                if (color) util.setColor(INST, w);
                try w.writeAll("select ");
                try ir.writeRef(br.cond, color, w);
                if (color) util.setColor(.reset, w);
                try w.writeAll(", ");
                try ir.writeRef(br.then, color, w);
                if (color) util.setColor(.reset, w);
                try w.writeAll(", ");
                try ir.writeRef(br.@"else", color, w);
                try w.writeByte('\n');
            },
            // .jmp_val => {
            //     const bin = data[i].bin;
            //     try w.print("    %{s} %{d} label.{d}\n", .{ @tagName(tag), @enumToInt(bin.lhs), @enumToInt(bin.rhs) });
            // },
            .@"switch" => {
                const @"switch" = data[i].@"switch";
                if (color) util.setColor(INST, w);
                try w.writeAll("    switch ");
                try ir.writeRef(@"switch".target, color, w);
                if (color) util.setColor(.reset, w);
                try w.writeAll(" {");
                for (@"switch".case_vals[0..@"switch".cases_len]) |val_ref, case_i| {
                    try w.writeAll("\n        ");
                    try ir.writeValue(val_ref, color, w);
                    if (color) util.setColor(.reset, w);
                    try w.writeAll(" => ");
                    try ir.writeLabel(@"switch".case_labels[case_i], color, w);
                    if (color) util.setColor(.reset, w);
                }
                if (color) util.setColor(LITERAL, w);
                try w.writeAll("\n        default ");
                if (color) util.setColor(.reset, w);
                try w.writeAll("=> ");
                try ir.writeLabel(@"switch".default, color, w);
                if (color) util.setColor(.reset, w);
                try w.writeAll("\n    }\n");
            },
            .call => {
                const call = data[i].call;
                try w.writeAll("    ");
                try ir.writeRef(@intToEnum(Ref, i), color, w);
                if (color) util.setColor(.reset, w);
                try w.writeAll(" = ");
                if (color) util.setColor(INST, w);
                try w.writeAll("call ");
                try ir.writeRef(call.func, color, w);
                if (color) util.setColor(.reset, w);
                try w.writeAll(" (");
                for (call.args()) |arg, arg_i| {
                    if (arg_i != 0) try w.writeAll(", ");
                    try ir.writeRef(arg, color, w);
                    if (color) util.setColor(.reset, w);
                }
                try w.writeAll(")\n");
            },
            .alloc => {
                const alloc = data[i].alloc;
                try w.writeAll("    ");
                try ir.writeRef(@intToEnum(Ref, i), color, w);
                if (color) util.setColor(.reset, w);
                try w.writeAll(" = ");
                if (color) util.setColor(INST, w);
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
            .store => {
                const bin = data[i].bin;
                if (color) util.setColor(INST, w);
                try w.writeAll("    store ");
                try ir.writeRef(bin.lhs, color, w);
                if (color) util.setColor(.reset, w);
                try w.writeAll(", ");
                try ir.writeRef(bin.rhs, color, w);
                try w.writeByte('\n');
            },
            .ret => {
                if (color) util.setColor(INST, w);
                try w.writeAll("    ret\n");
            },
            .ret_value => {
                if (color) util.setColor(INST, w);
                try w.writeAll("    ret_value ");
                try ir.writeRef(data[i].un, color, w);
                try w.writeByte('\n');
            },
            .load => {
                try w.writeAll("    ");
                try ir.writeRef(@intToEnum(Ref, i), color, w);
                try w.writeAll(" = ");
                if (color) util.setColor(INST, w);
                try w.writeAll("load ");
                try ir.writeRef(data[i].un, color, w);
                try w.writeByte('\n');
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
                try w.writeAll("    ");
                try ir.writeRef(@intToEnum(Ref, i), color, w);
                if (color) util.setColor(.reset, w);
                try w.writeAll(" = ");
                if (color) util.setColor(INST, w);
                try w.print("{s} ", .{@tagName(tag)});
                try ir.writeRef(bin.lhs, color, w);
                if (color) util.setColor(.reset, w);
                try w.writeAll(", ");
                try ir.writeRef(bin.rhs, color, w);
                try w.writeByte('\n');
            },
            .bit_not,
            .negate,
            => {
                const un = data[i].un;
                try w.writeAll("    ");
                try ir.writeRef(@intToEnum(Ref, i), color, w);
                if (color) util.setColor(.reset, w);
                try w.writeAll(" = ");
                if (color) util.setColor(INST, w);
                try w.print("{s} ", .{@tagName(tag)});
                try ir.writeRef(un, color, w);
                try w.writeByte('\n');
            },
            else => {},
        }
    }
    if (color) util.setColor(.reset, w);
    try w.writeAll("}\n\n");
}

fn writeType(ir: Ir, ty_ref: IrPool.Ref, color: bool, w: anytype) !void {
    const ty = ir.pool.get(ty_ref);
    if (color) util.setColor(TYPE, w);
    switch (ty) {
        .value => unreachable,
        .ptr, .noreturn, .void, .func => try w.writeAll(@tagName(ty)),
        .int => |bits| try w.print("i{d}", .{bits}),
        .float => |bits| try w.print("f{d}", .{bits}),
        .array => |info| {
            try w.print("[{d} * ", .{info.len});
            try ir.writeType(info.child, false, w);
            try w.writeByte(']');
        },
        .vector => |info| {
            try w.print("<{d} * ", .{info.len});
            try ir.writeType(info.child, false, w);
            try w.writeByte('>');
        },
    }
}

fn writeValue(ir: Ir, val_ref: IrPool.Ref, color: bool, w: anytype) !void {
    const v = ir.pool.get(val_ref).value;
    if (color) util.setColor(LITERAL, w);
    switch (v.tag) {
        .unavailable => try w.writeAll(" unavailable"),
        .int => try w.print("{d}", .{v.data.int}),
        .bytes => try w.print("\"{s}\"", .{v.data.bytes}),
        // std.fmt does @as instead of @floatCast
        .float => try w.print("{d}", .{@floatCast(f64, v.data.float)}),
        else => try w.print("({s})", .{@tagName(v.tag)}),
    }
}

fn writeRef(ir: Ir, ref: Ref, color: bool, w: anytype) !void {
    const index = @enumToInt(ref);
    const ty_ref = ir.instructions.items(.ty)[index];
    if (ir.instructions.items(.tag)[index] == .constant) {
        try ir.writeType(ty_ref, color, w);
        const v_ref = ir.instructions.items(.data)[index].constant;
        try w.writeByte(' ');
        try ir.writeValue(v_ref, color, w);
        return;
    } else if (ir.instructions.items(.tag)[index] == .symbol) {
        const name = ir.instructions.items(.data)[index].label;
        try ir.writeType(ty_ref, color, w);
        if (color) util.setColor(REF, w);
        try w.print(" @{s}", .{name});
        return;
    }
    try ir.writeType(ty_ref, color, w);
    if (color) util.setColor(REF, w);
    try w.print(" %{d}", .{index});
}

fn writeLabel(ir: Ir, ref: Ref, color: bool, w: anytype) !void {
    const index = @enumToInt(ref);
    const label = ir.instructions.items(.data)[index].label;
    if (color) util.setColor(REF, w);
    try w.print("{s}.{d}", .{ label, index });
}
