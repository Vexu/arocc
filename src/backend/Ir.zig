const std = @import("std");
const Allocator = std.mem.Allocator;
const assert = std.debug.assert;
const Interner = @import("Interner.zig");
const Object = @import("Object.zig");

pub const Decl = struct {
    decl_ty: Interner.Ref,
    instructions: std.MultiArrayList(Inst),
    body: std.ArrayListUnmanaged(Inst.Ref),
    arena: std.heap.ArenaAllocator.State,
    /// The first `attr_count` instructions in `body` will be attributes
    /// specific to this declaration.
    attr_count: u32,

    pub fn deinit(decl: *Decl, gpa: Allocator) void {
        decl.instructions.deinit(gpa);
        decl.body.deinit(gpa);
        decl.arena.promote(gpa).deinit();
    }

    pub fn data(decl: *const Decl, ref: Inst.Ref) Inst.Data {
        return decl.instructions.items(.data)[@intFromEnum(ref)];
    }

    pub fn tag(decl: *const Decl, ref: Inst.Ref) Inst.Tag {
        return decl.instructions.items(.tag)[@intFromEnum(ref)];
    }

    pub fn ty(decl: *const Decl, ref: Inst.Ref) Interner.Ref {
        var cur = ref;
        while (true) switch (decl.tag(cur)) {
            .attribute => unreachable,
            .constant => return decl.data(cur).constant.ty,
            .param => return decl.data(cur).param.ty,
            .symbol => return .ptr,
            .label => unreachable,
            .jmp => return .noreturn,
            .@"switch" => return .noreturn,
            .branch => return .noreturn,
            .select => cur = decl.data(cur).branch.then,
            .call => return decl.data(cur).call.ret_ty,
            .alloc => return .ptr,
            .phi => cur = decl.data(cur).phi.inputs()[0].value,
            .ret => {
                cur = decl.data(cur).ret;
                if (cur == .none) return .void;
            },
            .load => return decl.data(cur).load.ty,
            // zig fmt: off
            .store, .bit_or, .bit_xor, .bit_and, .bit_shl, .bit_shr,
            .add, .sub, .mul, .div, .mod
            => return decl.data(cur).bin.ty,
            .cmp_eq, .cmp_ne, .cmp_lt, .cmp_lte, .cmp_gt, .cmp_gte,
            => return .i1,
            .bit_not, .negate, .trunc, .zext, .sext
            => return decl.data(cur).un.ty,
            // zig fmt: on
        };
    }
};

const Ir = @This();

interner: *Interner,
decls: std.StringArrayHashMapUnmanaged(Decl),

pub fn deinit(ir: *Ir, gpa: std.mem.Allocator) void {
    for (ir.decls.values()) |*decl| {
        decl.deinit(gpa);
    }
    ir.decls.deinit(gpa);
    ir.* = undefined;
}

pub const Builder = struct {
    gpa: Allocator,
    arena: std.heap.ArenaAllocator,
    interner: *Interner,

    decls: std.StringArrayHashMapUnmanaged(Decl) = .{},
    instructions: std.MultiArrayList(Ir.Inst) = .{},
    body: std.ArrayListUnmanaged(Inst.Ref) = .{},
    param_index: u32 = 0,
    alloc_index: u32 = 1,
    current_label: Inst.Ref = undefined,

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

    pub fn finishFn(b: *Builder, name: []const u8, attributes: []const Attribute) !void {
        try b.instructions.ensureUnusedCapacity(b.gpa, attributes.len);
        const attr_dest = try b.body.addManyAt(b.gpa, 0, attributes.len);
        for (attr_dest, attributes) |*dest, attr| {
            const ref: Inst.Ref = @enumFromInt(b.instructions.len);
            b.instructions.appendAssumeCapacity(.{ .tag = .attribute, .data = .{
                .attribute = attr,
            } });
            dest.* = ref;
        }
        try b.decls.ensureUnusedCapacity(b.gpa, 1);

        var duped_instructions = try b.instructions.clone(b.gpa);
        errdefer duped_instructions.deinit(b.gpa);
        var duped_body = try b.body.clone(b.gpa);
        errdefer duped_body.deinit(b.gpa);

        b.decls.putAssumeCapacity(name, .{
            .decl_ty = .func,
            .instructions = duped_instructions,
            .body = duped_body,
            .arena = b.arena.state,
            .attr_count = @intCast(attributes.len),
        });
        b.instructions.shrinkRetainingCapacity(0);
        b.body.shrinkRetainingCapacity(0);
        b.arena = std.heap.ArenaAllocator.init(b.gpa);
        b.alloc_index = 1;
        b.param_index = 0;
    }

    pub fn startBlock(b: *Builder, label: Inst.Ref) !void {
        try b.body.append(b.gpa, label);
        b.current_label = label;
    }

    pub fn addParam(b: *Builder, ty: Interner.Ref, attributes: []const Attribute) Allocator.Error!Inst.Ref {
        try b.instructions.ensureUnusedCapacity(b.gpa, attributes.len + 1);
        const attr_dest = try b.body.addManyAt(b.gpa, b.param_index, attributes.len + 1);
        for (attr_dest[0..attributes.len], attributes) |*dest, attr| {
            const ref: Inst.Ref = @enumFromInt(b.instructions.len);
            b.instructions.appendAssumeCapacity(.{ .tag = .attribute, .data = .{
                .attribute = attr,
            } });
            dest.* = ref;
        }

        const ref: Inst.Ref = @enumFromInt(b.instructions.len);
        b.instructions.appendAssumeCapacity(.{ .tag = .param, .data = .{
            .param = .{ .ty = ty },
        } });
        attr_dest[attributes.len] = ref;
        b.param_index += @intCast(attr_dest.len);
        return ref;
    }

    pub fn addAlloc(b: *Builder, size: u32, @"align": u32) Allocator.Error!Inst.Ref {
        const ref: Inst.Ref = @enumFromInt(b.instructions.len);
        try b.instructions.append(b.gpa, .{ .tag = .alloc, .data = .{
            .alloc = .{ .size = size, .@"align" = @"align" },
        } });
        try b.body.insert(b.gpa, b.param_index + b.alloc_index, ref);
        b.alloc_index += 1;
        return ref;
    }

    pub fn addInst(b: *Builder, tag: Ir.Inst.Tag, data: Ir.Inst.Data) Allocator.Error!Inst.Ref {
        const ref: Inst.Ref = @enumFromInt(b.instructions.len);
        try b.instructions.append(b.gpa, .{ .tag = tag, .data = data });
        try b.body.append(b.gpa, ref);
        return ref;
    }

    pub fn makeLabel(b: *Builder, name: [:0]const u8) Allocator.Error!Inst.Ref {
        const ref: Inst.Ref = @enumFromInt(b.instructions.len);
        try b.instructions.append(b.gpa, .{ .tag = .label, .data = .{
            .label = .{ .ptr = name.ptr, .len = @intCast(name.len) },
        } });
        return ref;
    }

    pub fn addJump(b: *Builder, label: Inst.Ref) Allocator.Error!void {
        _ = try b.addInst(.jmp, .{ .jmp = label });
    }

    pub const addSelect = addBranch;

    pub fn addBranch(
        b: *Builder,
        cond: Inst.Ref,
        true_label: Inst.Ref,
        false_label: Inst.Ref,
    ) Allocator.Error!void {
        const branch = try b.arena.allocator().create(Ir.Inst.Branch);
        branch.* = .{
            .cond = cond,
            .then = true_label,
            .@"else" = false_label,
        };
        _ = try b.addInst(.branch, .{ .branch = branch });
    }

    pub fn addSwitch(
        b: *Builder,
        target: Inst.Ref,
        values: []Interner.Ref,
        labels: []Inst.Ref,
        default: Inst.Ref,
    ) Allocator.Error!void {
        assert(values.len == labels.len);
        const @"switch" = try b.arena.allocator().alloc(Inst.Ref, Inst.Call.size + values.len * 2);
        @as(*Inst.Switch, @ptrCast(@"switch".ptr)).* = .{
            .target = target,
            .default = default,
            .cases_len = @intCast(values.len),
        };
        std.mem.copy(Interner.Ref, @ptrCast(@"switch"[Inst.Switch.size..]), values);
        std.mem.copy(Inst.Ref, @"switch"[Inst.Switch.size + values.len ..], labels);
        _ = try b.addInst(.@"switch", .{ .@"switch" = @ptrCast(@"switch".ptr) });
    }

    pub fn addStore(b: *Builder, ptr: Inst.Ref, val: Inst.Ref, attr: Inst.MemoryAttributes) Allocator.Error!void {
        _ = try b.addInst(.store, .{ .store = .{ .ptr = ptr, .val = val, .attr = attr } });
    }

    pub fn addLoad(b: *Builder, ptr: Inst.Ref, ty: Interner.Ref, attr: Inst.MemoryAttributes) Allocator.Error!Inst.Ref {
        return b.addInst(.load, .{ .load = .{ .ptr = ptr, .ty = ty, .attr = attr } });
    }

    pub fn addConstant(b: *Builder, val: Interner.Ref, ty: Interner.Ref) Allocator.Error!Inst.Ref {
        const ref: Inst.Ref = @enumFromInt(b.instructions.len);
        try b.instructions.append(b.gpa, .{ .tag = .constant, .data = .{
            .constant = .{ .val = val, .ty = ty },
        } });
        return ref;
    }

    pub fn addPhi(b: *Builder, inputs: []const Inst.Phi.Input) Allocator.Error!Inst.Ref {
        const a = b.arena.allocator();
        const input_refs = try a.alloc(Inst.Ref, inputs.len * 2);
        std.mem.copy(Inst.Ref, input_refs, std.mem.bytesAsSlice(Inst.Ref, std.mem.sliceAsBytes(inputs)));

        return b.addInst(.phi, .{ .phi = .{ .ptr = input_refs.ptr, .len = @intCast(inputs.len) } });
    }

    pub fn addSymbol(b: *Builder, name: []const u8) Allocator.Error!Inst.Ref {
        const duped_name = try b.arena.allocator().dupeZ(u8, name);
        const ref: Inst.Ref = @enumFromInt(b.instructions.len);
        try b.instructions.append(b.gpa, .{ .tag = .symbol, .data = .{
            .symbol = .{ .ptr = duped_name.ptr, .len = @intCast(duped_name.len) },
        } });
        return ref;
    }

    pub fn addCall(
        b: *Builder,
        fn_ref: Inst.Ref,
        ret_ty: Interner.Ref,
        args: []const Inst.Ref,
    ) Allocator.Error!Inst.Ref {
        const call = try b.arena.allocator().alloc(Inst.Ref, Inst.Call.size + args.len);
        @as(*Inst.Call, @ptrCast(call.ptr)).* = .{
            .func = fn_ref,
            .ret_ty = ret_ty,
            .args_len = @intCast(args.len),
        };
        std.mem.copy(Inst.Ref, call[Inst.Call.size..], args);
        return b.addInst(.call, .{ .call = @ptrCast(call.ptr) });
    }
};

pub const Renderer = struct {
    gpa: Allocator,
    obj: *Object,
    ir: *const Ir,
    errors: ErrorList = .{},

    pub const ErrorList = std.StringArrayHashMapUnmanaged([]const u8);

    pub const Error = Allocator.Error || error{LowerFail};

    pub fn deinit(r: *Renderer) void {
        for (r.errors.values()) |msg| r.gpa.free(msg);
        r.errors.deinit(r.gpa);
    }

    pub fn render(r: *Renderer) !void {
        switch (r.obj.target.cpu.arch) {
            .x86, .x86_64 => return @import("Ir/x86/Renderer.zig").render(r),
            else => unreachable,
        }
    }

    pub fn fail(
        r: *Renderer,
        name: []const u8,
        comptime format: []const u8,
        args: anytype,
    ) Error {
        try r.errors.ensureUnusedCapacity(r.gpa, 1);
        r.errors.putAssumeCapacity(name, try std.fmt.allocPrint(r.gpa, format, args));
        return error.LowerFail;
    }
};

pub fn render(
    ir: *const Ir,
    gpa: Allocator,
    target: std.Target,
    errors: ?*Renderer.ErrorList,
) !*Object {
    const obj = try Object.create(gpa, target);
    errdefer obj.deinit();

    var renderer: Renderer = .{
        .gpa = gpa,
        .obj = obj,
        .ir = ir,
    };
    defer {
        if (errors) |some| {
            some.* = renderer.errors.move();
        }
        renderer.deinit();
    }

    try renderer.render();
    return obj;
}

pub const Inst = struct {
    tag: Tag,
    data: Data,

    pub const Ref = enum(u32) { none = std.math.maxInt(u32), _ };

    pub const Tag = enum {
        /// Uses `data.constant`.
        /// Not included in blocks.
        constant,
        /// Uses `data.param`.
        /// Not included in blocks.
        param,
        /// Uses `data.symbol`.
        /// Not included in blocks.
        symbol,
        /// Uses `data.attribute`.
        /// Only valid at the start of functions,
        /// before `param` instructions, and
        /// in call arguments.
        attribute,
        /// Uses `data.label`.
        label,
        /// Uses `data.jmp`.
        jmp,
        /// Uses `data.switch`.
        @"switch",
        /// Uses `data.branch`.
        branch,
        /// Uses `data.branch`.
        select,
        /// Uses `data.call`.
        call,
        /// Uses `data.alloc`.
        alloc,
        /// Uses `data.phi`.
        phi,
        /// Uses `data.ret`.
        ret,
        /// Uses `data.load`.
        load,

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
        bit_not,
        negate,
        trunc,
        zext,
        sext,
    };

    pub const Data = union {
        constant: struct {
            ty: Interner.Ref,
            val: Interner.Ref,
        },
        symbol: struct {
            len: u32,
            ptr: [*:0]const u8,

            pub fn name(s: @This()) []const u8 {
                return s.ptr[0..s.len];
            }
        },
        param: struct {
            ty: Interner.Ref,
        },
        attribute: Attribute,
        alloc: struct {
            size: u32,
            @"align": u32,
        },
        load: struct {
            ty: Interner.Ref,
            attr: MemoryAttributes,
            ptr: Ref,
        },
        store: struct {
            attr: MemoryAttributes,
            ptr: Ref,
            val: Ref,
        },
        call: *Call,
        ret: Ref,
        label: struct {
            len: u32,
            ptr: [*:0]const u8,

            pub fn name(l: @This()) []const u8 {
                return l.ptr[0..l.len];
            }
        },
        jmp: Ref,
        @"switch": *Switch,
        branch: *Branch,
        phi: Phi,
        bin: struct {
            ty: Interner.Ref,
            lhs: Ref,
            rhs: Ref,
        },
        un: struct {
            ty: Interner.Ref,
            operand: Ref,
        },
    };

    pub const MemoryAttributes = packed struct(u32) {
        @"volatile": bool,
        atomic: bool,
        @"align": u30,
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

        pub const size = std.meta.fields(Switch).len;

        pub fn values(s: *const Switch) []const Interner.Ref {
            return @as([*]const Interner.Ref, @ptrCast(s))[size..][0..s.cases_len];
        }

        pub fn labels(s: *const Switch) []const Ref {
            return @as([*]const Ref, @ptrCast(s))[size + s.cases_len ..][0..s.cases_len];
        }
    };

    pub const Call = struct {
        func: Ref,
        ret_ty: Interner.Ref,
        args_len: u32,

        pub const size = std.meta.fields(Call).len;

        pub fn args(c: *const Call) []const Ref {
            return @as([*]const Ref, @ptrCast(c))[size..][0..c.args_len];
        }
    };

    pub const Phi = struct {
        len: u32,
        ptr: [*]Ref,

        pub const Input = struct {
            label: Ref,
            value: Ref,
        };

        pub fn inputs(p: Phi) []Input {
            const slice = (p.ptr + 1)[0..p.len];
            return std.mem.bytesAsSlice(Input, std.mem.sliceAsBytes(slice));
        }
    };
};

pub const Attribute = union(enum) {
    /// Only valid on functions.
    /// Sets stack alignment, must be a power of two.
    align_stack: Interner.Ref,
    /// Only valid on functions.
    /// Forces optimizer to inline the function at call sites.
    always_inline,
    /// Only valid on functions.
    /// Disallows optimizer from inlining the function.
    no_inline,
    /// Only valid on functions.
    /// Hints that inlining the function is desireable.
    inline_hint,
    /// Only valid on functions.
    /// Hints that the function is rarely called.
    cold,
    /// Only valid on functions.
    /// Hints that the function is frequently called.
    hot,
    /// Only valid on functions.
    /// Disables emitting prologue / epilogue for the function.
    naked,

    /// Valid on parameters and arguments.
    /// Specifies that an integer argument should be zero extended
    /// to an ABI sized integer.
    zero_extend,
    /// Valid on parameters and arguments.
    /// Specifies that an integer argument should be sign extended
    /// to an ABI sized integer.
    sign_extend,
    /// Valid on parameters and arguments.
    /// Gives the pointee type of an pointer argument that should be treated.
    /// Implies a hidden copy in the callee.
    by_value: Interner.Ref,
    /// Valid on parameters and arguments.
    /// Similar to `by_value` but does not imply a hidden copy.
    by_ref: Interner.Ref,
    /// Valid on parameters and arguments.
    /// Specifies that the pointer argument is used to return a value from
    /// the function. Callee must guarantee it to be valid.
    ret_ptr: Interner.Ref,
    /// Valid on parameters and arguments.
    /// Specifies the alignment of a pointer argument.
    @"align": Interner.Ref,
};

const TYPE = std.io.tty.Color.bright_magenta;
const INST = std.io.tty.Color.cyan;
const REF = std.io.tty.Color.blue;
const LITERAL = std.io.tty.Color.green;
const ATTRIBUTE = std.io.tty.Color.yellow;

const RefMap = std.AutoArrayHashMap(Inst.Ref, void);

pub fn dump(ir: *const Ir, gpa: Allocator, config: std.io.tty.Config, w: anytype) !void {
    for (ir.decls.keys(), ir.decls.values()) |name, *decl| {
        try ir.dumpDecl(decl, gpa, name, config, w);
    }
}

fn dumpDecl(ir: *const Ir, decl: *const Decl, gpa: Allocator, name: []const u8, config: std.io.tty.Config, w: anytype) !void {
    const tags = decl.instructions.items(.tag);
    const data = decl.instructions.items(.data);

    var ref_map = RefMap.init(gpa);
    defer ref_map.deinit();

    var label_map = RefMap.init(gpa);
    defer label_map.deinit();

    for (decl.body.items[0..decl.attr_count]) |ref| {
        const attr = data[@intFromEnum(ref)].attribute;
        try ir.writeAttribute(attr, config, w);
    }
    try w.writeByte('\n');

    const ret_inst = decl.body.items[decl.body.items.len - 1];
    const ret_ty = decl.ty(ret_inst);
    try ir.writeType(ret_ty, config, w);
    try config.setColor(w, REF);
    try w.print(" @{s}", .{name});
    try config.setColor(w, .reset);
    try w.writeAll("(");

    var arg_count: u32 = decl.attr_count;
    var need_param_comma = false;
    while (true) : (arg_count += 1) {
        const ref = decl.body.items[arg_count];
        switch (tags[@intFromEnum(ref)]) {
            .attribute => {
                if (need_param_comma) try w.writeAll(", ");
                need_param_comma = false;
                const attr = data[@intFromEnum(ref)].attribute;
                try ir.writeAttribute(attr, config, w);
                continue;
            },
            .param => {},
            else => break,
        }
        if (need_param_comma) try w.writeAll(", ");
        need_param_comma = true;
        try ref_map.put(ref, {});
        try ir.writeRef(decl, &ref_map, ref, config, w);
        try config.setColor(w, .reset);
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
        if (tag == .label) {
            const label_index = label_map.getIndex(ref).?;
            try config.setColor(w, REF);
            try w.print("{s}.{d}:\n", .{ data[i].label.name(), label_index });
            continue;
        }
        try w.writeAll("    ");
        switch (tag) {
            .param, .constant, .symbol, .attribute => unreachable, // not included in function bodies
            .label => unreachable, // handled above
            .jmp => {
                const operand = data[i].un.operand;
                try config.setColor(w, INST);
                try w.writeAll("jmp ");
                try writeLabel(decl, &label_map, operand, config, w);
                try w.writeByte('\n');
            },
            .branch => {
                const br = data[i].branch;
                try config.setColor(w, INST);
                try w.writeAll("branch ");
                try ir.writeRef(decl, &ref_map, br.cond, config, w);
                try config.setColor(w, .reset);
                try w.writeAll(", ");
                try writeLabel(decl, &label_map, br.then, config, w);
                try config.setColor(w, .reset);
                try w.writeAll(", ");
                try writeLabel(decl, &label_map, br.@"else", config, w);
                try w.writeByte('\n');
            },
            .select => {
                const br = data[i].branch;
                try ir.writeNewRef(decl, &ref_map, ref, config, w);
                try w.writeAll("select ");
                try ir.writeRef(decl, &ref_map, br.cond, config, w);
                try config.setColor(w, .reset);
                try w.writeAll(", ");
                try ir.writeRef(decl, &ref_map, br.then, config, w);
                try config.setColor(w, .reset);
                try w.writeAll(", ");
                try ir.writeRef(decl, &ref_map, br.@"else", config, w);
                try w.writeByte('\n');
            },
            .@"switch" => {
                const @"switch" = data[i].@"switch";
                try config.setColor(w, INST);
                try w.writeAll("switch ");
                try ir.writeRef(decl, &ref_map, @"switch".target, config, w);
                try config.setColor(w, .reset);
                try w.writeAll(" {");
                for (@"switch".values(), @"switch".labels()) |val_ref, label_ref| {
                    try w.writeAll("\n        ");
                    try ir.writeValue(val_ref, config, w);
                    try config.setColor(w, .reset);
                    try w.writeAll(" => ");
                    try writeLabel(decl, &label_map, label_ref, config, w);
                    try config.setColor(w, .reset);
                }
                try config.setColor(w, LITERAL);
                try w.writeAll("\n        default ");
                try config.setColor(w, .reset);
                try w.writeAll("=> ");
                try writeLabel(decl, &label_map, @"switch".default, config, w);
                try config.setColor(w, .reset);
                try w.writeAll("\n    }\n");
            },
            .call => {
                const call = data[i].call;
                try ir.writeNewRef(decl, &ref_map, ref, config, w);
                try w.writeAll("call");
                try ir.writeRefExtra(decl, &ref_map, call.func, false, config, w);
                try config.setColor(w, .reset);
                try w.writeAll("(");
                var need_arg_comma = false;
                for (call.args()) |arg| {
                    if (need_arg_comma) try w.writeAll(", ");
                    if (tags[@intFromEnum(arg)] == .attribute) {
                        need_arg_comma = false;
                        const attr = data[@intFromEnum(arg)].attribute;
                        try ir.writeAttribute(attr, config, w);
                        continue;
                    }
                    need_arg_comma = true;
                    try ir.writeRef(decl, &ref_map, arg, config, w);
                    try config.setColor(w, .reset);
                }
                try w.writeAll(")\n");
            },
            .alloc => {
                const alloc = data[i].alloc;
                try ir.writeNewRef(decl, &ref_map, ref, config, w);
                try w.writeAll("alloc ");
                try config.setColor(w, ATTRIBUTE);
                try w.writeAll("size ");
                try config.setColor(w, LITERAL);
                try w.print("{d}", .{alloc.size});
                try config.setColor(w, ATTRIBUTE);
                try w.writeAll(" align ");
                try config.setColor(w, LITERAL);
                try w.print("{d}", .{alloc.@"align"});
                try w.writeByte('\n');
            },
            .phi => {
                try ir.writeNewRef(decl, &ref_map, ref, config, w);
                try w.writeAll("phi");
                try config.setColor(w, .reset);
                try w.writeAll(" {");
                for (data[i].phi.inputs()) |input| {
                    try w.writeAll("\n        ");
                    try writeLabel(decl, &label_map, input.label, config, w);
                    try config.setColor(w, .reset);
                    try w.writeAll(" => ");
                    try ir.writeRef(decl, &ref_map, input.value, config, w);
                    try config.setColor(w, .reset);
                }
                try config.setColor(w, .reset);
                try w.writeAll("\n    }\n");
            },
            .store => {
                const store = data[i].store;
                try config.setColor(w, INST);
                try w.writeAll("store ");
                try writeMemAttr(store.attr, config, w);
                try ir.writeRef(decl, &ref_map, store.ptr, config, w);
                try config.setColor(w, .reset);
                try w.writeAll(", ");
                try ir.writeRef(decl, &ref_map, store.val, config, w);
                try w.writeByte('\n');
            },
            .ret => {
                try config.setColor(w, INST);
                try w.writeAll("ret ");
                const operand = data[i].ret;
                if (operand != .none) try ir.writeRef(decl, &ref_map, operand, config, w);
                try w.writeByte('\n');
            },
            .load => {
                try ir.writeNewRef(decl, &ref_map, ref, config, w);
                try w.writeAll("load ");
                const load = data[i].load;
                try writeMemAttr(load.attr, config, w);
                try ir.writeRef(decl, &ref_map, load.ptr, config, w);
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
                try ir.writeNewRef(decl, &ref_map, ref, config, w);
                try w.print("{s} ", .{@tagName(tag)});
                try ir.writeRef(decl, &ref_map, bin.lhs, config, w);
                try config.setColor(w, .reset);
                try w.writeAll(", ");
                try ir.writeRef(decl, &ref_map, bin.rhs, config, w);
                try w.writeByte('\n');
            },
            .bit_not,
            .negate,
            .trunc,
            .zext,
            .sext,
            => {
                const operand = data[i].un.operand;
                try ir.writeNewRef(decl, &ref_map, ref, config, w);
                try w.print("{s} ", .{@tagName(tag)});
                try ir.writeRef(decl, &ref_map, operand, config, w);
                try w.writeByte('\n');
            },
        }
    }
    try config.setColor(w, .reset);
    try w.writeAll("}\n\n");
}

fn writeType(ir: Ir, ty_ref: Interner.Ref, config: std.io.tty.Config, w: anytype) !void {
    const ty = ir.interner.get(ty_ref);
    try config.setColor(w, TYPE);
    switch (ty) {
        .ptr_ty, .noreturn_ty, .void_ty, .func_ty => {
            const tag = @tagName(ty);
            try w.writeAll(tag[0 .. tag.len - 3]);
        },
        .int_ty => |bits| try w.print("i{d}", .{bits}),
        .float_ty => |bits| try w.print("f{d}", .{bits}),
        .array_ty => |info| {
            try w.print("[{d} * ", .{info.len});
            try ir.writeType(info.child, .no_color, w);
            try w.writeByte(']');
        },
        .vector_ty => |info| {
            try w.print("<{d} * ", .{info.len});
            try ir.writeType(info.child, .no_color, w);
            try w.writeByte('>');
        },
        .record_ty => |elems| {
            // TODO collect into buffer and only print once
            try w.writeAll("{ ");
            for (elems, 0..) |elem, i| {
                if (i != 0) try w.writeAll(", ");
                try ir.writeType(elem, config, w);
            }
            try w.writeAll(" }");
        },
        else => unreachable, // not a type
    }
}

fn writeValue(ir: Ir, val: Interner.Ref, config: std.io.tty.Config, w: anytype) !void {
    try config.setColor(w, LITERAL);
    const key = ir.interner.get(val);
    switch (key) {
        .null => return w.writeAll("nullptr_t"),
        .int => |repr| switch (repr) {
            inline else => |x| return w.print("{d}", .{x}),
        },
        .float => |repr| switch (repr) {
            inline else => |x| return w.print("{d}", .{@as(f64, @floatCast(x))}),
        },
        .bytes => |b| {
            try w.writeByte('"');
            try std.zig.fmt.stringEscape(b, "", .{}, w);
            try w.writeByte('"');
        },
        else => unreachable, // not a value
    }
}

fn writeRef(ir: Ir, decl: *const Decl, ref_map: *RefMap, ref: Inst.Ref, config: std.io.tty.Config, w: anytype) !void {
    try ir.writeRefExtra(decl, ref_map, ref, true, config, w);
}

fn writeRefExtra(
    ir: Ir,
    decl: *const Decl,
    ref_map: *RefMap,
    ref: Inst.Ref,
    write_type: bool,
    config: std.io.tty.Config,
    w: anytype,
) !void {
    assert(ref != .none);
    switch (decl.tag(ref)) {
        .constant => {
            const constant = decl.data(ref).constant;
            if (write_type) try ir.writeType(constant.ty, config, w);
            try w.writeByte(' ');
            try ir.writeValue(constant.val, config, w);
        },
        .symbol => {
            const symbol = decl.data(ref).symbol;
            if (write_type) try ir.writeType(.ptr, config, w);
            try config.setColor(w, REF);
            try w.print(" @{s}", .{symbol.name()});
        },
        else => {
            try ir.writeType(decl.ty(ref), config, w);
            if (write_type) try config.setColor(w, REF);
            const ref_index = ref_map.getIndex(ref).?;
            try w.print(" %{d}", .{ref_index});
        },
    }
}

fn writeNewRef(ir: Ir, decl: *const Decl, ref_map: *RefMap, ref: Inst.Ref, config: std.io.tty.Config, w: anytype) !void {
    try ref_map.put(ref, {});
    try ir.writeRef(decl, ref_map, ref, config, w);
    try config.setColor(w, .reset);
    try w.writeAll(" = ");
    try config.setColor(w, INST);
}

fn writeLabel(decl: *const Decl, label_map: *RefMap, ref: Inst.Ref, config: std.io.tty.Config, w: anytype) !void {
    assert(ref != .none);
    const label = decl.data(ref).label;
    try config.setColor(w, REF);
    const label_index = label_map.getIndex(ref).?;
    try w.print("{s}.{d}", .{ label.name(), label_index });
}

fn writeMemAttr(attr: Inst.MemoryAttributes, config: std.io.tty.Config, w: anytype) !void {
    if (attr.@"volatile") {
        try config.setColor(w, ATTRIBUTE);
        try w.writeAll("volatile ");
    }
    if (attr.atomic) {
        try config.setColor(w, ATTRIBUTE);
        try w.writeAll("atomic ");
    }
    try config.setColor(w, ATTRIBUTE);
    try w.writeAll("align ");
    try config.setColor(w, LITERAL);
    try w.print("{d} ", .{attr.@"align"});
}

fn writeAttribute(ir: Ir, attr: Attribute, config: std.io.tty.Config, w: anytype) !void {
    try config.setColor(w, ATTRIBUTE);
    try w.writeAll(@tagName(attr));
    switch (attr) {
        .align_stack, .@"align" => |val| {
            try w.writeByte('(');
            try ir.writeValue(val, config, w);
            try config.setColor(w, ATTRIBUTE);
            try w.writeByte(')');
        },
        .by_value, .by_ref, .ret_ptr => |ty| {
            try w.writeByte('(');
            try ir.writeType(ty, config, w);
            try config.setColor(w, ATTRIBUTE);
            try w.writeByte(')');
        },
        else => {},
    }
    try w.writeByte(' ');
}
