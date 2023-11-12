const std = @import("std");
const Allocator = std.mem.Allocator;
const assert = std.debug.assert;
const log = std.log.scoped(.emit);
const mem = std.mem;
const Interner = @import("../../Interner.zig");
const Ir = @import("../../Ir.zig");
const Lower = @import("zig").arch.x86_64.Lower;
const BaseRenderer = Ir.Renderer;
const zig = @import("zig");
const abi = zig.arch.x86_64.abi;
const bits = zig.arch.x86_64.bits;
const Mir = zig.arch.x86_64.Mir;

const Emit = @This();

lower: Lower,
code: *std.ArrayList(u8),

code_offset_mapping: std.AutoHashMapUnmanaged(Mir.Inst.Index, usize) = .{},
relocs: std.ArrayListUnmanaged(Reloc) = .{},

pub const Error = Lower.Error || error{
    EmitFail,
};

pub fn emitMir(emit: *Emit) Error!void {
    for (0..emit.lower.mir.instructions.len) |mir_i| {
        const mir_index: Mir.Inst.Index = @intCast(mir_i);
        try emit.code_offset_mapping.putNoClobber(
            emit.lower.allocator,
            mir_index,
            @intCast(emit.code.items.len),
        );
        const lowered = try emit.lower.lowerMir(mir_index);
        var lowered_relocs = lowered.relocs;
        for (lowered.insts, 0..) |lowered_inst, lowered_index| {
            const start_offset: u32 = @intCast(emit.code.items.len);
            _ = start_offset;
            try lowered_inst.encode(emit.code.writer(), .{});
            const end_offset: u32 = @intCast(emit.code.items.len);
            _ = end_offset;
            while (lowered_relocs.len > 0 and
                lowered_relocs[0].lowered_inst_index == lowered_index) : ({
                lowered_relocs = lowered_relocs[1..];
            }) switch (lowered_relocs[0].target) {
                else => {},
            };
        }
        std.debug.assert(lowered_relocs.len == 0);

        if (lowered.insts.len == 0) {
            const mir_inst = emit.lower.mir.instructions.get(mir_index);
            switch (mir_inst.tag) {
                else => unreachable,
                .pseudo => switch (mir_inst.ops) {
                    else => unreachable,
                    .pseudo_dbg_prologue_end_none => {},
                    .pseudo_dbg_line_line_column => {},
                    .pseudo_dbg_epilogue_begin_none => {},
                    .pseudo_dbg_inline_func => {},
                    .pseudo_dead_none => {},
                },
            }
        }
    }
    try emit.fixupRelocs();
}

pub fn deinit(emit: *Emit) void {
    if (emit.lower.err_msg) |some| emit.lower.allocator.free(some);
    emit.relocs.deinit(emit.lower.allocator);
    emit.code_offset_mapping.deinit(emit.lower.allocator);
    emit.* = undefined;
}

fn fail(emit: *Emit, comptime format: []const u8, args: anytype) Error {
    return switch (emit.lower.fail(format, args)) {
        error.LowerFail => error.EmitFail,
        else => |e| e,
    };
}

const Reloc = struct {
    /// Offset of the instruction.
    source: usize,
    /// Target of the relocation.
    target: Mir.Inst.Index,
    /// Offset of the relocation within the instruction.
    offset: u32,
    /// Length of the instruction.
    length: u5,
};

fn fixupRelocs(emit: *Emit) Error!void {
    // TODO this function currently assumes all relocs via JMP/CALL instructions are 32bit in size.
    // This should be reversed like it is done in aarch64 MIR emit code: start with the smallest
    // possible resolution, i.e., 8bit, and iteratively converge on the minimum required resolution
    // until the entire decl is correctly emitted with all JMP/CALL instructions within range.
    for (emit.relocs.items) |reloc| {
        const target = emit.code_offset_mapping.get(reloc.target) orelse
            return emit.fail("JMP/CALL relocation target not found!", .{});
        const disp = @as(i64, @intCast(target)) - @as(i64, @intCast(reloc.source + reloc.length));
        mem.writeInt(i32, emit.code.items[reloc.offset..][0..4], @intCast(disp), .little);
    }
}
