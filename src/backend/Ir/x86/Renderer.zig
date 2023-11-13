const std = @import("std");
const Allocator = std.mem.Allocator;
const assert = std.debug.assert;
const Emit = @import("Emit.zig");
const Interner = @import("../../Interner.zig");
const Ir = @import("../../Ir.zig");
const BaseRenderer = Ir.Renderer;
const Object = @import("../../Object.zig");
const zig = @import("zig");
const abi = zig.arch.x86_64.abi;
const bits = zig.arch.x86_64.bits;
const Mir = zig.arch.x86_64.Mir;

const Condition = bits.Condition;
const Immediate = bits.Immediate;
const Memory = bits.Memory;
const Register = bits.Register;
const RegisterLock = RegisterManager.RegisterLock;
const FrameIndex = bits.FrameIndex;

const RegisterManager = zig.RegisterManager(Renderer, Register, Ir.Inst.Ref, abi.allocatable_regs);

// Register classes
const RegisterBitSet = RegisterManager.RegisterBitSet;
const RegisterClass = struct {
    const gp: RegisterBitSet = blk: {
        var set = RegisterBitSet.initEmpty();
        for (abi.allocatable_regs, 0..) |reg, index| if (reg.class() == .general_purpose) set.set(index);
        break :blk set;
    };
    const x87: RegisterBitSet = blk: {
        var set = RegisterBitSet.initEmpty();
        for (abi.allocatable_regs, 0..) |reg, index| if (reg.class() == .x87) set.set(index);
        break :blk set;
    };
    const sse: RegisterBitSet = blk: {
        var set = RegisterBitSet.initEmpty();
        for (abi.allocatable_regs, 0..) |reg, index| if (reg.class() == .sse) set.set(index);
        break :blk set;
    };
};

const Renderer = @This();

base: *BaseRenderer,
interner: *Interner,

register_manager: RegisterManager = .{},

mir_instructions: std.MultiArrayList(Mir.Inst) = .{},
mir_extra: std.ArrayListUnmanaged(u32) = .{},

free_frame_indices: std.AutoArrayHashMapUnmanaged(FrameIndex, void) = .{},
frame_locs: std.MultiArrayList(Mir.FrameLoc) = .{},

pub fn render(base: *BaseRenderer) !void {
    var renderer: Renderer = .{
        .base = base,
        .interner = base.ir.interner,
    };

    for (renderer.base.ir.decls.keys(), renderer.base.ir.decls.values()) |name, *decl| {
        if (decl.decl_ty == .func) {
            renderer.renderFn(name, decl) catch |e| switch (e) {
                error.OutOfMemory => return e,
                error.LowerFail => continue,
            };
        } else {
            renderer.renderVariable(name, decl) catch |e| switch (e) {
                error.OutOfMemory => return e,
                error.LowerFail => continue,
            };
        }
    }
    if (renderer.base.errors.entries.len != 0) return error.LowerFail;
}

fn renderVariable(r: *Renderer, name: []const u8, decl: *const Ir.Decl) !void {
    _ = decl;
    return r.base.fail(name, "TODO implement lowering variables", .{});
}

fn renderFn(r: *Renderer, name: []const u8, decl: *const Ir.Decl) !void {
    r.mir_instructions.shrinkRetainingCapacity(0);
    r.mir_extra.shrinkRetainingCapacity(0);

    // TODO setup calling convention

    const tags = decl.instructions.items(.tag);
    var arg_count: u32 = 0;
    while (true) : (arg_count += 1) {
        const ref = decl.body.items[arg_count];
        if (tags[@intFromEnum(ref)] != .arg) break;
        // TODO handle args
    }

    for (decl.body.items[arg_count..]) |inst| {
        try r.renderInst(decl, inst);
    }

    const cc: std.builtin.CallingConvention = .C;
    const section: Object.Section = .func;
    const code = try r.base.obj.getSection(section);

    var emit = Emit{
        .lower = .{
            .pic = false,
            .opt_bin_file = null,
            .allocator = r.base.gpa,
            .mir = .{
                .instructions = r.mir_instructions.slice(),
                .extra = r.mir_extra.items,
                .frame_locs = undefined,
            },
            .cc = cc,
        },
        .code = code,
    };
    defer emit.deinit();
    emit.emitMir() catch |err| switch (err) {
        error.LowerFail, error.EmitFail => {
            return r.base.fail(name, "{s}", .{emit.lower.err_msg.?});
        },
        error.InvalidInstruction, error.CannotEncode => |e| {
            const msg = switch (e) {
                error.InvalidInstruction => "CodeGen failed to find a viable instruction.",
                error.CannotEncode => "CodeGen failed to encode the instruction.",
            };
            return r.base.fail(name, "{s}", .{msg});
        },
        else => |e| return e,
    };
}

fn renderInst(r: *Renderer, decl: *const Ir.Decl, inst: Ir.Inst.Ref) !void {
    switch (decl.tag(inst)) {
        .constant, .arg, .symbol => unreachable,
        .label => {

        },
        .call => {

        },
        .ret => {

        },
        else => |t| return r.base.fail("decl.name", "TODO renderInst({s})", .{@tagName(t)}),
    }
}
