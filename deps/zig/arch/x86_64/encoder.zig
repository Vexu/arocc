const std = @import("std");
const assert = std.debug.assert;
const log = std.log.scoped(.x86_64_encoder);
const math = std.math;
const testing = std.testing;

const bits = @import("bits.zig");
const Encoding = @import("Encoding.zig");
const FrameIndex = bits.FrameIndex;
const Immediate = bits.Immediate;
const Register = bits.Register;
const Symbol = bits.Symbol;

pub const Instruction = struct {
    prefix: Prefix = .none,
    encoding: Encoding,
    ops: [4]Operand = .{.none} ** 4,

    pub const Mnemonic = Encoding.Mnemonic;

    pub const Prefix = enum(u3) {
        none,
        lock,
        rep,
        repe,
        repz,
        repne,
        repnz,
    };

    pub const Memory = union(enum) {
        sib: Sib,
        rip: Rip,
        moffs: Moffs,

        pub const Base = bits.Memory.Base;

        pub const ScaleIndex = struct {
            scale: u4,
            index: Register,

            const none = ScaleIndex{ .scale = 0, .index = undefined };
        };

        pub const PtrSize = bits.Memory.Size;

        pub const Sib = struct {
            ptr_size: PtrSize,
            base: Base,
            scale_index: ScaleIndex,
            disp: i32,
        };

        pub const Rip = struct {
            ptr_size: PtrSize,
            disp: i32,
        };

        pub const Moffs = struct {
            seg: Register,
            offset: u64,
        };

        pub fn moffs(reg: Register, offset: u64) Memory {
            assert(reg.class() == .segment);
            return .{ .moffs = .{ .seg = reg, .offset = offset } };
        }

        pub fn sib(ptr_size: PtrSize, args: struct {
            disp: i32 = 0,
            base: Base = .none,
            scale_index: ?ScaleIndex = null,
        }) Memory {
            if (args.scale_index) |si| assert(std.math.isPowerOfTwo(si.scale));
            return .{ .sib = .{
                .base = args.base,
                .disp = args.disp,
                .ptr_size = ptr_size,
                .scale_index = if (args.scale_index) |si| si else ScaleIndex.none,
            } };
        }

        pub fn rip(ptr_size: PtrSize, disp: i32) Memory {
            return .{ .rip = .{ .ptr_size = ptr_size, .disp = disp } };
        }

        pub fn isSegmentRegister(mem: Memory) bool {
            return switch (mem) {
                .moffs => true,
                .rip => false,
                .sib => |s| switch (s.base) {
                    .none, .frame, .reloc => false,
                    .reg => |reg| reg.class() == .segment,
                },
            };
        }

        pub fn base(mem: Memory) Base {
            return switch (mem) {
                .moffs => |m| .{ .reg = m.seg },
                .sib => |s| s.base,
                .rip => .none,
            };
        }

        pub fn scaleIndex(mem: Memory) ?ScaleIndex {
            return switch (mem) {
                .moffs, .rip => null,
                .sib => |s| if (s.scale_index.scale > 0) s.scale_index else null,
            };
        }

        pub fn bitSize(mem: Memory) u64 {
            return switch (mem) {
                .rip => |r| r.ptr_size.bitSize(),
                .sib => |s| s.ptr_size.bitSize(),
                .moffs => 64,
            };
        }
    };

    pub const Operand = union(enum) {
        none,
        reg: Register,
        mem: Memory,
        imm: Immediate,

        /// Returns the bitsize of the operand.
        pub fn bitSize(op: Operand) u64 {
            return switch (op) {
                .none => unreachable,
                .reg => |reg| reg.bitSize(),
                .mem => |mem| mem.bitSize(),
                .imm => unreachable,
            };
        }

        /// Returns true if the operand is a segment register.
        /// Asserts the operand is either register or memory.
        pub fn isSegmentRegister(op: Operand) bool {
            return switch (op) {
                .none => unreachable,
                .reg => |reg| reg.class() == .segment,
                .mem => |mem| mem.isSegmentRegister(),
                .imm => unreachable,
            };
        }

        pub fn isBaseExtended(op: Operand) bool {
            return switch (op) {
                .none, .imm => false,
                .reg => |reg| reg.isExtended(),
                .mem => |mem| mem.base().isExtended(),
            };
        }

        pub fn isIndexExtended(op: Operand) bool {
            return switch (op) {
                .none, .reg, .imm => false,
                .mem => |mem| if (mem.scaleIndex()) |si| si.index.isExtended() else false,
            };
        }

        fn format(
            op: Operand,
            comptime unused_format_string: []const u8,
            options: std.fmt.FormatOptions,
            writer: anytype,
        ) !void {
            _ = op;
            _ = unused_format_string;
            _ = options;
            _ = writer;
            @compileError("do not format Operand directly; use fmtPrint() instead");
        }

        const FormatContext = struct {
            op: Operand,
            enc_op: Encoding.Op,
        };

        fn fmt(
            ctx: FormatContext,
            comptime unused_format_string: []const u8,
            options: std.fmt.FormatOptions,
            writer: anytype,
        ) @TypeOf(writer).Error!void {
            _ = unused_format_string;
            _ = options;
            const op = ctx.op;
            const enc_op = ctx.enc_op;
            switch (op) {
                .none => {},
                .reg => |reg| try writer.writeAll(@tagName(reg)),
                .mem => |mem| switch (mem) {
                    .rip => |rip| {
                        try writer.print("{} [rip", .{rip.ptr_size});
                        if (rip.disp != 0) try writer.print(" {c} 0x{x}", .{
                            @as(u8, if (rip.disp < 0) '-' else '+'),
                            @abs(rip.disp),
                        });
                        try writer.writeByte(']');
                    },
                    .sib => |sib| {
                        try writer.print("{} ", .{sib.ptr_size});

                        if (mem.isSegmentRegister()) {
                            return writer.print("{s}:0x{x}", .{ @tagName(sib.base.reg), sib.disp });
                        }

                        try writer.writeByte('[');

                        var any = false;
                        switch (sib.base) {
                            .none => {},
                            .reg => |reg| {
                                try writer.print("{s}", .{@tagName(reg)});
                                any = true;
                            },
                            inline .frame, .reloc => |payload| {
                                try writer.print("{}", .{payload});
                                any = true;
                            },
                        }
                        if (mem.scaleIndex()) |si| {
                            if (any) try writer.writeAll(" + ");
                            try writer.print("{s} * {d}", .{ @tagName(si.index), si.scale });
                            any = true;
                        }
                        if (sib.disp != 0 or !any) {
                            if (any)
                                try writer.print(" {c} ", .{@as(u8, if (sib.disp < 0) '-' else '+')})
                            else if (sib.disp < 0)
                                try writer.writeByte('-');
                            try writer.print("0x{x}", .{@abs(sib.disp)});
                            any = true;
                        }

                        try writer.writeByte(']');
                    },
                    .moffs => |moffs| try writer.print("{s}:0x{x}", .{
                        @tagName(moffs.seg),
                        moffs.offset,
                    }),
                },
                .imm => |imm| if (enc_op.isSigned()) {
                    const imms = imm.asSigned(enc_op.immBitSize());
                    if (imms < 0) try writer.writeByte('-');
                    try writer.print("0x{x}", .{@abs(imms)});
                } else try writer.print("0x{x}", .{imm.asUnsigned(enc_op.immBitSize())}),
            }
        }

        pub fn fmtPrint(op: Operand, enc_op: Encoding.Op) std.fmt.Formatter(fmt) {
            return .{ .data = .{ .op = op, .enc_op = enc_op } };
        }
    };

    pub fn new(prefix: Prefix, mnemonic: Mnemonic, ops: []const Operand) !Instruction {
        const encoding = (try Encoding.findByMnemonic(prefix, mnemonic, ops)) orelse {
            log.err("no encoding found for: {s} {s} {s} {s} {s} {s}", .{
                @tagName(prefix),
                @tagName(mnemonic),
                @tagName(if (ops.len > 0) Encoding.Op.fromOperand(ops[0]) else .none),
                @tagName(if (ops.len > 1) Encoding.Op.fromOperand(ops[1]) else .none),
                @tagName(if (ops.len > 2) Encoding.Op.fromOperand(ops[2]) else .none),
                @tagName(if (ops.len > 3) Encoding.Op.fromOperand(ops[3]) else .none),
            });
            return error.InvalidInstruction;
        };
        log.debug("selected encoding: {}", .{encoding});

        var inst = Instruction{
            .prefix = prefix,
            .encoding = encoding,
            .ops = [1]Operand{.none} ** 4,
        };
        @memcpy(inst.ops[0..ops.len], ops);
        return inst;
    }

    pub fn format(
        inst: Instruction,
        comptime unused_format_string: []const u8,
        options: std.fmt.FormatOptions,
        writer: anytype,
    ) @TypeOf(writer).Error!void {
        _ = unused_format_string;
        _ = options;
        if (inst.prefix != .none) try writer.print("{s} ", .{@tagName(inst.prefix)});
        try writer.print("{s}", .{@tagName(inst.encoding.mnemonic)});
        for (inst.ops, inst.encoding.data.ops, 0..) |op, enc, i| {
            if (op == .none) break;
            if (i > 0) try writer.writeByte(',');
            try writer.writeByte(' ');
            try writer.print("{}", .{op.fmtPrint(enc)});
        }
    }

    pub fn encode(inst: Instruction, writer: anytype, comptime opts: Options) !void {
        const encoder = Encoder(@TypeOf(writer), opts){ .writer = writer };
        const enc = inst.encoding;
        const data = enc.data;

        if (data.mode.isVex()) {
            try inst.encodeVexPrefix(encoder);
            const opc = inst.encoding.opcode();
            try encoder.opcode_1byte(opc[opc.len - 1]);
        } else {
            try inst.encodeLegacyPrefixes(encoder);
            try inst.encodeMandatoryPrefix(encoder);
            try inst.encodeRexPrefix(encoder);
            try inst.encodeOpcode(encoder);
        }

        switch (data.op_en) {
            .zo, .o => {},
            .i, .d => try encodeImm(inst.ops[0].imm, data.ops[0], encoder),
            .zi, .oi => try encodeImm(inst.ops[1].imm, data.ops[1], encoder),
            .fd => try encoder.imm64(inst.ops[1].mem.moffs.offset),
            .td => try encoder.imm64(inst.ops[0].mem.moffs.offset),
            else => {
                const mem_op = switch (data.op_en) {
                    .m, .mi, .m1, .mc, .mr, .mri, .mrc, .mvr => inst.ops[0],
                    .rm, .rmi, .rm0, .vmi => inst.ops[1],
                    .rvm, .rvmr, .rvmi => inst.ops[2],
                    else => unreachable,
                };
                switch (mem_op) {
                    .reg => |reg| {
                        const rm = switch (data.op_en) {
                            .m, .mi, .m1, .mc, .vmi => enc.modRmExt(),
                            .mr, .mri, .mrc => inst.ops[1].reg.lowEnc(),
                            .rm, .rmi, .rm0, .rvm, .rvmr, .rvmi => inst.ops[0].reg.lowEnc(),
                            .mvr => inst.ops[2].reg.lowEnc(),
                            else => unreachable,
                        };
                        try encoder.modRm_direct(rm, reg.lowEnc());
                    },
                    .mem => |mem| {
                        const op = switch (data.op_en) {
                            .m, .mi, .m1, .mc, .vmi => .none,
                            .mr, .mri, .mrc => inst.ops[1],
                            .rm, .rmi, .rm0, .rvm, .rvmr, .rvmi => inst.ops[0],
                            .mvr => inst.ops[2],
                            else => unreachable,
                        };
                        try encodeMemory(enc, mem, op, encoder);
                    },
                    else => unreachable,
                }

                switch (data.op_en) {
                    .mi => try encodeImm(inst.ops[1].imm, data.ops[1], encoder),
                    .rmi, .mri, .vmi => try encodeImm(inst.ops[2].imm, data.ops[2], encoder),
                    .rvmr => try encoder.imm8(@as(u8, inst.ops[3].reg.enc()) << 4),
                    .rvmi => try encodeImm(inst.ops[3].imm, data.ops[3], encoder),
                    else => {},
                }
            },
        }
    }

    fn encodeOpcode(inst: Instruction, encoder: anytype) !void {
        const opcode = inst.encoding.opcode();
        const first = @intFromBool(inst.encoding.mandatoryPrefix() != null);
        const final = opcode.len - 1;
        for (opcode[first..final]) |byte| try encoder.opcode_1byte(byte);
        switch (inst.encoding.data.op_en) {
            .o, .oi => try encoder.opcode_withReg(opcode[final], inst.ops[0].reg.lowEnc()),
            else => try encoder.opcode_1byte(opcode[final]),
        }
    }

    fn encodeLegacyPrefixes(inst: Instruction, encoder: anytype) !void {
        const enc = inst.encoding;
        const data = enc.data;
        const op_en = data.op_en;

        var legacy = LegacyPrefixes{};

        switch (inst.prefix) {
            .none => {},
            .lock => legacy.prefix_f0 = true,
            .repne, .repnz => legacy.prefix_f2 = true,
            .rep, .repe, .repz => legacy.prefix_f3 = true,
        }

        switch (data.mode) {
            .short, .rex_short => legacy.set16BitOverride(),
            else => {},
        }

        const segment_override: ?Register = switch (op_en) {
            .zo, .i, .zi, .o, .oi, .d => null,
            .fd => inst.ops[1].mem.base().reg,
            .td => inst.ops[0].mem.base().reg,
            .rm, .rmi, .rm0 => if (inst.ops[1].isSegmentRegister())
                switch (inst.ops[1]) {
                    .reg => |reg| reg,
                    .mem => |mem| mem.base().reg,
                    else => unreachable,
                }
            else
                null,
            .m, .mi, .m1, .mc, .mr, .mri, .mrc => if (inst.ops[0].isSegmentRegister())
                switch (inst.ops[0]) {
                    .reg => |reg| reg,
                    .mem => |mem| mem.base().reg,
                    else => unreachable,
                }
            else
                null,
            .vmi, .rvm, .rvmr, .rvmi, .mvr => unreachable,
        };
        if (segment_override) |seg| {
            legacy.setSegmentOverride(seg);
        }

        try encoder.legacyPrefixes(legacy);
    }

    fn encodeRexPrefix(inst: Instruction, encoder: anytype) !void {
        const op_en = inst.encoding.data.op_en;

        var rex = Rex{};
        rex.present = inst.encoding.data.mode == .rex;
        rex.w = inst.encoding.data.mode == .long;

        switch (op_en) {
            .zo, .i, .zi, .fd, .td, .d => {},
            .o, .oi => rex.b = inst.ops[0].reg.isExtended(),
            .m, .mi, .m1, .mc, .mr, .rm, .rmi, .mri, .mrc, .rm0 => {
                const r_op = switch (op_en) {
                    .rm, .rmi, .rm0 => inst.ops[0],
                    .mr, .mri, .mrc => inst.ops[1],
                    else => .none,
                };
                rex.r = r_op.isBaseExtended();

                const b_x_op = switch (op_en) {
                    .rm, .rmi, .rm0 => inst.ops[1],
                    .m, .mi, .m1, .mc, .mr, .mri, .mrc => inst.ops[0],
                    else => unreachable,
                };
                rex.b = b_x_op.isBaseExtended();
                rex.x = b_x_op.isIndexExtended();
            },
            .vmi, .rvm, .rvmr, .rvmi, .mvr => unreachable,
        }

        try encoder.rex(rex);
    }

    fn encodeVexPrefix(inst: Instruction, encoder: anytype) !void {
        const op_en = inst.encoding.data.op_en;
        const opc = inst.encoding.opcode();
        const mand_pre = inst.encoding.mandatoryPrefix();

        var vex = Vex{};

        vex.w = inst.encoding.data.mode.isLong();

        switch (op_en) {
            .zo, .i, .zi, .fd, .td, .d => {},
            .o, .oi => vex.b = inst.ops[0].reg.isExtended(),
            .m, .mi, .m1, .mc, .mr, .rm, .rmi, .mri, .mrc, .rm0, .vmi, .rvm, .rvmr, .rvmi, .mvr => {
                const r_op = switch (op_en) {
                    .rm, .rmi, .rm0, .rvm, .rvmr, .rvmi => inst.ops[0],
                    .mr, .mri, .mrc => inst.ops[1],
                    .mvr => inst.ops[2],
                    .m, .mi, .m1, .mc, .vmi => .none,
                    else => unreachable,
                };
                vex.r = r_op.isBaseExtended();

                const b_x_op = switch (op_en) {
                    .rm, .rmi, .rm0, .vmi => inst.ops[1],
                    .m, .mi, .m1, .mc, .mr, .mri, .mrc, .mvr => inst.ops[0],
                    .rvm, .rvmr, .rvmi => inst.ops[2],
                    else => unreachable,
                };
                vex.b = b_x_op.isBaseExtended();
                vex.x = b_x_op.isIndexExtended();
            },
        }

        vex.l = inst.encoding.data.mode.isVecLong();

        vex.p = if (mand_pre) |mand| switch (mand) {
            0x66 => .@"66",
            0xf2 => .f2,
            0xf3 => .f3,
            else => unreachable,
        } else .none;

        const leading: usize = if (mand_pre) |_| 1 else 0;
        assert(opc[leading] == 0x0f);
        vex.m = switch (opc[leading + 1]) {
            else => .@"0f",
            0x38 => .@"0f38",
            0x3a => .@"0f3a",
        };

        switch (op_en) {
            else => {},
            .vmi => vex.v = inst.ops[0].reg,
            .rvm, .rvmr, .rvmi => vex.v = inst.ops[1].reg,
        }

        try encoder.vex(vex);
    }

    fn encodeMandatoryPrefix(inst: Instruction, encoder: anytype) !void {
        const prefix = inst.encoding.mandatoryPrefix() orelse return;
        try encoder.opcode_1byte(prefix);
    }

    fn encodeMemory(encoding: Encoding, mem: Memory, operand: Operand, encoder: anytype) !void {
        const operand_enc = switch (operand) {
            .reg => |reg| reg.lowEnc(),
            .none => encoding.modRmExt(),
            else => unreachable,
        };

        switch (mem) {
            .moffs => unreachable,
            .sib => |sib| switch (sib.base) {
                .none => {
                    try encoder.modRm_SIBDisp0(operand_enc);
                    if (mem.scaleIndex()) |si| {
                        const scale = math.log2_int(u4, si.scale);
                        try encoder.sib_scaleIndexDisp32(scale, si.index.lowEnc());
                    } else {
                        try encoder.sib_disp32();
                    }
                    try encoder.disp32(sib.disp);
                },
                .reg => |base| if (base.class() == .segment) {
                    // TODO audit this wrt SIB
                    try encoder.modRm_SIBDisp0(operand_enc);
                    if (mem.scaleIndex()) |si| {
                        const scale = math.log2_int(u4, si.scale);
                        try encoder.sib_scaleIndexDisp32(scale, si.index.lowEnc());
                    } else {
                        try encoder.sib_disp32();
                    }
                    try encoder.disp32(sib.disp);
                } else {
                    assert(base.class() == .general_purpose);
                    const dst = base.lowEnc();
                    const src = operand_enc;
                    if (dst == 4 or mem.scaleIndex() != null) {
                        if (sib.disp == 0 and dst != 5) {
                            try encoder.modRm_SIBDisp0(src);
                            if (mem.scaleIndex()) |si| {
                                const scale = math.log2_int(u4, si.scale);
                                try encoder.sib_scaleIndexBase(scale, si.index.lowEnc(), dst);
                            } else {
                                try encoder.sib_base(dst);
                            }
                        } else if (math.cast(i8, sib.disp)) |_| {
                            try encoder.modRm_SIBDisp8(src);
                            if (mem.scaleIndex()) |si| {
                                const scale = math.log2_int(u4, si.scale);
                                try encoder.sib_scaleIndexBaseDisp8(scale, si.index.lowEnc(), dst);
                            } else {
                                try encoder.sib_baseDisp8(dst);
                            }
                            try encoder.disp8(@as(i8, @truncate(sib.disp)));
                        } else {
                            try encoder.modRm_SIBDisp32(src);
                            if (mem.scaleIndex()) |si| {
                                const scale = math.log2_int(u4, si.scale);
                                try encoder.sib_scaleIndexBaseDisp32(scale, si.index.lowEnc(), dst);
                            } else {
                                try encoder.sib_baseDisp32(dst);
                            }
                            try encoder.disp32(sib.disp);
                        }
                    } else {
                        if (sib.disp == 0 and dst != 5) {
                            try encoder.modRm_indirectDisp0(src, dst);
                        } else if (math.cast(i8, sib.disp)) |_| {
                            try encoder.modRm_indirectDisp8(src, dst);
                            try encoder.disp8(@as(i8, @truncate(sib.disp)));
                        } else {
                            try encoder.modRm_indirectDisp32(src, dst);
                            try encoder.disp32(sib.disp);
                        }
                    }
                },
                .frame => if (@TypeOf(encoder).options.allow_frame_locs) {
                    try encoder.modRm_indirectDisp32(operand_enc, undefined);
                    try encoder.disp32(undefined);
                } else return error.CannotEncode,
                .reloc => if (@TypeOf(encoder).options.allow_symbols) {
                    try encoder.modRm_indirectDisp32(operand_enc, undefined);
                    try encoder.disp32(undefined);
                } else return error.CannotEncode,
            },
            .rip => |rip| {
                try encoder.modRm_RIPDisp32(operand_enc);
                try encoder.disp32(rip.disp);
            },
        }
    }

    fn encodeImm(imm: Immediate, kind: Encoding.Op, encoder: anytype) !void {
        const raw = imm.asUnsigned(kind.immBitSize());
        switch (kind.immBitSize()) {
            8 => try encoder.imm8(@as(u8, @intCast(raw))),
            16 => try encoder.imm16(@as(u16, @intCast(raw))),
            32 => try encoder.imm32(@as(u32, @intCast(raw))),
            64 => try encoder.imm64(raw),
            else => unreachable,
        }
    }
};

pub const LegacyPrefixes = packed struct {
    /// LOCK
    prefix_f0: bool = false,
    /// REPNZ, REPNE, REP, Scalar Double-precision
    prefix_f2: bool = false,
    /// REPZ, REPE, REP, Scalar Single-precision
    prefix_f3: bool = false,

    /// CS segment override or Branch not taken
    prefix_2e: bool = false,
    /// SS segment override
    prefix_36: bool = false,
    /// ES segment override
    prefix_26: bool = false,
    /// FS segment override
    prefix_64: bool = false,
    /// GS segment override
    prefix_65: bool = false,

    /// Branch taken
    prefix_3e: bool = false,

    /// Address size override (enables 16 bit address size)
    prefix_67: bool = false,

    /// Operand size override (enables 16 bit operation)
    prefix_66: bool = false,

    padding: u5 = 0,

    pub fn setSegmentOverride(self: *LegacyPrefixes, reg: Register) void {
        assert(reg.class() == .segment);
        switch (reg) {
            .cs => self.prefix_2e = true,
            .ss => self.prefix_36 = true,
            .es => self.prefix_26 = true,
            .fs => self.prefix_64 = true,
            .gs => self.prefix_65 = true,
            .ds => {},
            else => unreachable,
        }
    }

    pub fn set16BitOverride(self: *LegacyPrefixes) void {
        self.prefix_66 = true;
    }
};

pub const Options = struct { allow_frame_locs: bool = false, allow_symbols: bool = false };

fn Encoder(comptime T: type, comptime opts: Options) type {
    return struct {
        writer: T,

        const Self = @This();
        pub const options = opts;

        // --------
        // Prefixes
        // --------

        /// Encodes legacy prefixes
        pub fn legacyPrefixes(self: Self, prefixes: LegacyPrefixes) !void {
            if (@as(u16, @bitCast(prefixes)) != 0) {
                // Hopefully this path isn't taken very often, so we'll do it the slow way for now

                // LOCK
                if (prefixes.prefix_f0) try self.writer.writeByte(0xf0);
                // REPNZ, REPNE, REP, Scalar Double-precision
                if (prefixes.prefix_f2) try self.writer.writeByte(0xf2);
                // REPZ, REPE, REP, Scalar Single-precision
                if (prefixes.prefix_f3) try self.writer.writeByte(0xf3);

                // CS segment override or Branch not taken
                if (prefixes.prefix_2e) try self.writer.writeByte(0x2e);
                // DS segment override
                if (prefixes.prefix_36) try self.writer.writeByte(0x36);
                // ES segment override
                if (prefixes.prefix_26) try self.writer.writeByte(0x26);
                // FS segment override
                if (prefixes.prefix_64) try self.writer.writeByte(0x64);
                // GS segment override
                if (prefixes.prefix_65) try self.writer.writeByte(0x65);

                // Branch taken
                if (prefixes.prefix_3e) try self.writer.writeByte(0x3e);

                // Operand size override
                if (prefixes.prefix_66) try self.writer.writeByte(0x66);

                // Address size override
                if (prefixes.prefix_67) try self.writer.writeByte(0x67);
            }
        }

        /// Use 16 bit operand size
        ///
        /// Note that this flag is overridden by REX.W, if both are present.
        pub fn prefix16BitMode(self: Self) !void {
            try self.writer.writeByte(0x66);
        }

        /// Encodes a REX prefix byte given all the fields
        ///
        /// Use this byte whenever you need 64 bit operation,
        /// or one of reg, index, r/m, base, or opcode-reg might be extended.
        ///
        /// See struct `Rex` for a description of each field.
        pub fn rex(self: Self, fields: Rex) !void {
            if (!fields.present and !fields.isSet()) return;

            var byte: u8 = 0b0100_0000;

            if (fields.w) byte |= 0b1000;
            if (fields.r) byte |= 0b0100;
            if (fields.x) byte |= 0b0010;
            if (fields.b) byte |= 0b0001;

            try self.writer.writeByte(byte);
        }

        /// Encodes a VEX prefix given all the fields
        ///
        /// See struct `Vex` for a description of each field.
        pub fn vex(self: Self, fields: Vex) !void {
            if (fields.is3Byte()) {
                try self.writer.writeByte(0b1100_0100);

                try self.writer.writeByte(
                    @as(u8, ~@intFromBool(fields.r)) << 7 |
                        @as(u8, ~@intFromBool(fields.x)) << 6 |
                        @as(u8, ~@intFromBool(fields.b)) << 5 |
                        @as(u8, @intFromEnum(fields.m)) << 0,
                );

                try self.writer.writeByte(
                    @as(u8, @intFromBool(fields.w)) << 7 |
                        @as(u8, ~fields.v.enc()) << 3 |
                        @as(u8, @intFromBool(fields.l)) << 2 |
                        @as(u8, @intFromEnum(fields.p)) << 0,
                );
            } else {
                try self.writer.writeByte(0b1100_0101);
                try self.writer.writeByte(
                    @as(u8, ~@intFromBool(fields.r)) << 7 |
                        @as(u8, ~fields.v.enc()) << 3 |
                        @as(u8, @intFromBool(fields.l)) << 2 |
                        @as(u8, @intFromEnum(fields.p)) << 0,
                );
            }
        }

        // ------
        // Opcode
        // ------

        /// Encodes a 1 byte opcode
        pub fn opcode_1byte(self: Self, opcode: u8) !void {
            try self.writer.writeByte(opcode);
        }

        /// Encodes a 2 byte opcode
        ///
        /// e.g. IMUL has the opcode 0x0f 0xaf, so you use
        ///
        /// encoder.opcode_2byte(0x0f, 0xaf);
        pub fn opcode_2byte(self: Self, prefix: u8, opcode: u8) !void {
            try self.writer.writeAll(&.{ prefix, opcode });
        }

        /// Encodes a 3 byte opcode
        ///
        /// e.g. MOVSD has the opcode 0xf2 0x0f 0x10
        ///
        /// encoder.opcode_3byte(0xf2, 0x0f, 0x10);
        pub fn opcode_3byte(self: Self, prefix_1: u8, prefix_2: u8, opcode: u8) !void {
            try self.writer.writeAll(&.{ prefix_1, prefix_2, opcode });
        }

        /// Encodes a 1 byte opcode with a reg field
        ///
        /// Remember to add a REX prefix byte if reg is extended!
        pub fn opcode_withReg(self: Self, opcode: u8, reg: u3) !void {
            assert(opcode & 0b111 == 0);
            try self.writer.writeByte(opcode | reg);
        }

        // ------
        // ModR/M
        // ------

        /// Construct a ModR/M byte given all the fields
        ///
        /// Remember to add a REX prefix byte if reg or rm are extended!
        pub fn modRm(self: Self, mod: u2, reg_or_opx: u3, rm: u3) !void {
            try self.writer.writeByte(@as(u8, mod) << 6 | @as(u8, reg_or_opx) << 3 | rm);
        }

        /// Construct a ModR/M byte using direct r/m addressing
        /// r/m effective address: r/m
        ///
        /// Note reg's effective address is always just reg for the ModR/M byte.
        /// Remember to add a REX prefix byte if reg or rm are extended!
        pub fn modRm_direct(self: Self, reg_or_opx: u3, rm: u3) !void {
            try self.modRm(0b11, reg_or_opx, rm);
        }

        /// Construct a ModR/M byte using indirect r/m addressing
        /// r/m effective address: [r/m]
        ///
        /// Note reg's effective address is always just reg for the ModR/M byte.
        /// Remember to add a REX prefix byte if reg or rm are extended!
        pub fn modRm_indirectDisp0(self: Self, reg_or_opx: u3, rm: u3) !void {
            assert(rm != 4 and rm != 5);
            try self.modRm(0b00, reg_or_opx, rm);
        }

        /// Construct a ModR/M byte using indirect SIB addressing
        /// r/m effective address: [SIB]
        ///
        /// Note reg's effective address is always just reg for the ModR/M byte.
        /// Remember to add a REX prefix byte if reg or rm are extended!
        pub fn modRm_SIBDisp0(self: Self, reg_or_opx: u3) !void {
            try self.modRm(0b00, reg_or_opx, 0b100);
        }

        /// Construct a ModR/M byte using RIP-relative addressing
        /// r/m effective address: [RIP + disp32]
        ///
        /// Note reg's effective address is always just reg for the ModR/M byte.
        /// Remember to add a REX prefix byte if reg or rm are extended!
        pub fn modRm_RIPDisp32(self: Self, reg_or_opx: u3) !void {
            try self.modRm(0b00, reg_or_opx, 0b101);
        }

        /// Construct a ModR/M byte using indirect r/m with a 8bit displacement
        /// r/m effective address: [r/m + disp8]
        ///
        /// Note reg's effective address is always just reg for the ModR/M byte.
        /// Remember to add a REX prefix byte if reg or rm are extended!
        pub fn modRm_indirectDisp8(self: Self, reg_or_opx: u3, rm: u3) !void {
            assert(rm != 4);
            try self.modRm(0b01, reg_or_opx, rm);
        }

        /// Construct a ModR/M byte using indirect SIB with a 8bit displacement
        /// r/m effective address: [SIB + disp8]
        ///
        /// Note reg's effective address is always just reg for the ModR/M byte.
        /// Remember to add a REX prefix byte if reg or rm are extended!
        pub fn modRm_SIBDisp8(self: Self, reg_or_opx: u3) !void {
            try self.modRm(0b01, reg_or_opx, 0b100);
        }

        /// Construct a ModR/M byte using indirect r/m with a 32bit displacement
        /// r/m effective address: [r/m + disp32]
        ///
        /// Note reg's effective address is always just reg for the ModR/M byte.
        /// Remember to add a REX prefix byte if reg or rm are extended!
        pub fn modRm_indirectDisp32(self: Self, reg_or_opx: u3, rm: u3) !void {
            assert(rm != 4);
            try self.modRm(0b10, reg_or_opx, rm);
        }

        /// Construct a ModR/M byte using indirect SIB with a 32bit displacement
        /// r/m effective address: [SIB + disp32]
        ///
        /// Note reg's effective address is always just reg for the ModR/M byte.
        /// Remember to add a REX prefix byte if reg or rm are extended!
        pub fn modRm_SIBDisp32(self: Self, reg_or_opx: u3) !void {
            try self.modRm(0b10, reg_or_opx, 0b100);
        }

        // ---
        // SIB
        // ---

        /// Construct a SIB byte given all the fields
        ///
        /// Remember to add a REX prefix byte if index or base are extended!
        pub fn sib(self: Self, scale: u2, index: u3, base: u3) !void {
            try self.writer.writeByte(@as(u8, scale) << 6 | @as(u8, index) << 3 | base);
        }

        /// Construct a SIB byte with scale * index + base, no frills.
        /// r/m effective address: [base + scale * index]
        ///
        /// Remember to add a REX prefix byte if index or base are extended!
        pub fn sib_scaleIndexBase(self: Self, scale: u2, index: u3, base: u3) !void {
            assert(base != 5);

            try self.sib(scale, index, base);
        }

        /// Construct a SIB byte with scale * index + disp32
        /// r/m effective address: [scale * index + disp32]
        ///
        /// Remember to add a REX prefix byte if index or base are extended!
        pub fn sib_scaleIndexDisp32(self: Self, scale: u2, index: u3) !void {
            // scale is actually ignored
            // index = 4 means no index if and only if we haven't extended the register
            // TODO enforce this
            // base = 5 means no base, if mod == 0.
            try self.sib(scale, index, 5);
        }

        /// Construct a SIB byte with just base
        /// r/m effective address: [base]
        ///
        /// Remember to add a REX prefix byte if index or base are extended!
        pub fn sib_base(self: Self, base: u3) !void {
            assert(base != 5);

            // scale is actually ignored
            // index = 4 means no index
            try self.sib(0, 4, base);
        }

        /// Construct a SIB byte with just disp32
        /// r/m effective address: [disp32]
        ///
        /// Remember to add a REX prefix byte if index or base are extended!
        pub fn sib_disp32(self: Self) !void {
            // scale is actually ignored
            // index = 4 means no index
            // base = 5 means no base, if mod == 0.
            try self.sib(0, 4, 5);
        }

        /// Construct a SIB byte with scale * index + base + disp8
        /// r/m effective address: [base + scale * index + disp8]
        ///
        /// Remember to add a REX prefix byte if index or base are extended!
        pub fn sib_scaleIndexBaseDisp8(self: Self, scale: u2, index: u3, base: u3) !void {
            try self.sib(scale, index, base);
        }

        /// Construct a SIB byte with base + disp8, no index
        /// r/m effective address: [base + disp8]
        ///
        /// Remember to add a REX prefix byte if index or base are extended!
        pub fn sib_baseDisp8(self: Self, base: u3) !void {
            // scale is ignored
            // index = 4 means no index
            try self.sib(0, 4, base);
        }

        /// Construct a SIB byte with scale * index + base + disp32
        /// r/m effective address: [base + scale * index + disp32]
        ///
        /// Remember to add a REX prefix byte if index or base are extended!
        pub fn sib_scaleIndexBaseDisp32(self: Self, scale: u2, index: u3, base: u3) !void {
            try self.sib(scale, index, base);
        }

        /// Construct a SIB byte with base + disp32, no index
        /// r/m effective address: [base + disp32]
        ///
        /// Remember to add a REX prefix byte if index or base are extended!
        pub fn sib_baseDisp32(self: Self, base: u3) !void {
            // scale is ignored
            // index = 4 means no index
            try self.sib(0, 4, base);
        }

        // -------------------------
        // Trivial (no bit fiddling)
        // -------------------------

        /// Encode an 8 bit displacement
        ///
        /// It is sign-extended to 64 bits by the cpu.
        pub fn disp8(self: Self, disp: i8) !void {
            try self.writer.writeByte(@as(u8, @bitCast(disp)));
        }

        /// Encode an 32 bit displacement
        ///
        /// It is sign-extended to 64 bits by the cpu.
        pub fn disp32(self: Self, disp: i32) !void {
            try self.writer.writeInt(i32, disp, .little);
        }

        /// Encode an 8 bit immediate
        ///
        /// It is sign-extended to 64 bits by the cpu.
        pub fn imm8(self: Self, imm: u8) !void {
            try self.writer.writeByte(imm);
        }

        /// Encode an 16 bit immediate
        ///
        /// It is sign-extended to 64 bits by the cpu.
        pub fn imm16(self: Self, imm: u16) !void {
            try self.writer.writeInt(u16, imm, .little);
        }

        /// Encode an 32 bit immediate
        ///
        /// It is sign-extended to 64 bits by the cpu.
        pub fn imm32(self: Self, imm: u32) !void {
            try self.writer.writeInt(u32, imm, .little);
        }

        /// Encode an 64 bit immediate
        ///
        /// It is sign-extended to 64 bits by the cpu.
        pub fn imm64(self: Self, imm: u64) !void {
            try self.writer.writeInt(u64, imm, .little);
        }
    };
}

pub const Rex = struct {
    w: bool = false,
    r: bool = false,
    x: bool = false,
    b: bool = false,
    present: bool = false,

    pub fn isSet(rex: Rex) bool {
        return rex.w or rex.r or rex.x or rex.b;
    }
};

pub const Vex = struct {
    w: bool = false,
    r: bool = false,
    x: bool = false,
    b: bool = false,
    l: bool = false,
    p: enum(u2) {
        none = 0b00,
        @"66" = 0b01,
        f3 = 0b10,
        f2 = 0b11,
    } = .none,
    m: enum(u5) {
        @"0f" = 0b0_0001,
        @"0f38" = 0b0_0010,
        @"0f3a" = 0b0_0011,
        _,
    } = .@"0f",
    v: Register = .ymm0,

    pub fn is3Byte(vex: Vex) bool {
        return vex.w or vex.x or vex.b or vex.m != .@"0f";
    }
};

const Assembler = struct {
    it: Tokenizer,

    const Tokenizer = struct {
        input: []const u8,
        pos: usize = 0,

        const Error = error{InvalidToken};

        const Token = struct {
            id: Id,
            start: usize,
            end: usize,

            const Id = enum {
                eof,

                space,
                new_line,

                colon,
                comma,
                open_br,
                close_br,
                plus,
                minus,
                star,

                string,
                numeral,
            };
        };

        const Iterator = struct {};

        fn next(it: *Tokenizer) !Token {
            var result = Token{
                .id = .eof,
                .start = it.pos,
                .end = it.pos,
            };

            var state: enum {
                start,
                space,
                new_line,
                string,
                numeral,
                numeral_hex,
            } = .start;

            while (it.pos < it.input.len) : (it.pos += 1) {
                const ch = it.input[it.pos];
                switch (state) {
                    .start => switch (ch) {
                        ',' => {
                            result.id = .comma;
                            it.pos += 1;
                            break;
                        },
                        ':' => {
                            result.id = .colon;
                            it.pos += 1;
                            break;
                        },
                        '[' => {
                            result.id = .open_br;
                            it.pos += 1;
                            break;
                        },
                        ']' => {
                            result.id = .close_br;
                            it.pos += 1;
                            break;
                        },
                        '+' => {
                            result.id = .plus;
                            it.pos += 1;
                            break;
                        },
                        '-' => {
                            result.id = .minus;
                            it.pos += 1;
                            break;
                        },
                        '*' => {
                            result.id = .star;
                            it.pos += 1;
                            break;
                        },
                        ' ', '\t' => state = .space,
                        '\n', '\r' => state = .new_line,
                        'a'...'z', 'A'...'Z' => state = .string,
                        '0'...'9' => state = .numeral,
                        else => return error.InvalidToken,
                    },

                    .space => switch (ch) {
                        ' ', '\t' => {},
                        else => {
                            result.id = .space;
                            break;
                        },
                    },

                    .new_line => switch (ch) {
                        '\n', '\r', ' ', '\t' => {},
                        else => {
                            result.id = .new_line;
                            break;
                        },
                    },

                    .string => switch (ch) {
                        'a'...'z', 'A'...'Z', '0'...'9' => {},
                        else => {
                            result.id = .string;
                            break;
                        },
                    },

                    .numeral => switch (ch) {
                        'x' => state = .numeral_hex,
                        '0'...'9' => {},
                        else => {
                            result.id = .numeral;
                            break;
                        },
                    },

                    .numeral_hex => switch (ch) {
                        'a'...'f' => {},
                        '0'...'9' => {},
                        else => {
                            result.id = .numeral;
                            break;
                        },
                    },
                }
            }

            if (it.pos >= it.input.len) {
                switch (state) {
                    .string => result.id = .string,
                    .numeral, .numeral_hex => result.id = .numeral,
                    else => {},
                }
            }

            result.end = it.pos;
            return result;
        }

        fn seekTo(it: *Tokenizer, pos: usize) void {
            it.pos = pos;
        }
    };

    pub fn init(input: []const u8) Assembler {
        return .{
            .it = Tokenizer{ .input = input },
        };
    }

    pub fn assemble(as: *Assembler, writer: anytype) !void {
        while (try as.next()) |parsed_inst| {
            const inst = try Instruction.new(.none, parsed_inst.mnemonic, &parsed_inst.ops);
            try inst.encode(writer);
        }
    }

    const ParseResult = struct {
        mnemonic: Instruction.Mnemonic,
        ops: [4]Instruction.Operand,
    };

    const ParseError = error{
        UnexpectedToken,
        InvalidMnemonic,
        InvalidOperand,
        InvalidRegister,
        InvalidPtrSize,
        InvalidMemoryOperand,
        InvalidScaleIndex,
    } || Tokenizer.Error || std.fmt.ParseIntError;

    fn next(as: *Assembler) ParseError!?ParseResult {
        try as.skip(2, .{ .space, .new_line });
        const mnemonic_tok = as.expect(.string) catch |err| switch (err) {
            error.UnexpectedToken => return if (try as.peek() == .eof) null else err,
            else => return err,
        };
        const mnemonic = mnemonicFromString(as.source(mnemonic_tok)) orelse
            return error.InvalidMnemonic;
        try as.skip(1, .{.space});

        const rules = .{
            .{},
            .{.register},
            .{.memory},
            .{.immediate},
            .{ .register, .register },
            .{ .register, .memory },
            .{ .memory, .register },
            .{ .register, .immediate },
            .{ .memory, .immediate },
            .{ .register, .register, .immediate },
            .{ .register, .memory, .immediate },
        };

        const pos = as.it.pos;
        inline for (rules) |rule| {
            var ops = [4]Instruction.Operand{ .none, .none, .none, .none };
            if (as.parseOperandRule(rule, &ops)) {
                return .{
                    .mnemonic = mnemonic,
                    .ops = ops,
                };
            } else |_| {
                as.it.seekTo(pos);
            }
        }

        return error.InvalidOperand;
    }

    fn source(as: *Assembler, token: Tokenizer.Token) []const u8 {
        return as.it.input[token.start..token.end];
    }

    fn peek(as: *Assembler) Tokenizer.Error!Tokenizer.Token.Id {
        const pos = as.it.pos;
        const next_tok = try as.it.next();
        const id = next_tok.id;
        as.it.seekTo(pos);
        return id;
    }

    fn expect(as: *Assembler, id: Tokenizer.Token.Id) ParseError!Tokenizer.Token {
        const next_tok_id = try as.peek();
        if (next_tok_id == id) return as.it.next();
        return error.UnexpectedToken;
    }

    fn skip(as: *Assembler, comptime num: comptime_int, tok_ids: [num]Tokenizer.Token.Id) Tokenizer.Error!void {
        outer: while (true) {
            const pos = as.it.pos;
            const next_tok = try as.it.next();
            inline for (tok_ids) |tok_id| {
                if (next_tok.id == tok_id) continue :outer;
            }
            as.it.seekTo(pos);
            break;
        }
    }

    fn mnemonicFromString(bytes: []const u8) ?Instruction.Mnemonic {
        const ti = @typeInfo(Instruction.Mnemonic).Enum;
        inline for (ti.fields) |field| {
            if (std.mem.eql(u8, bytes, field.name)) {
                return @field(Instruction.Mnemonic, field.name);
            }
        }
        return null;
    }

    fn parseOperandRule(as: *Assembler, rule: anytype, ops: *[4]Instruction.Operand) ParseError!void {
        inline for (rule, 0..) |cond, i| {
            comptime assert(i < 4);
            if (i > 0) {
                _ = try as.expect(.comma);
                try as.skip(1, .{.space});
            }
            if (@typeInfo(@TypeOf(cond)) != .EnumLiteral) {
                @compileError("invalid condition in the rule: " ++ @typeName(@TypeOf(cond)));
            }
            switch (cond) {
                .register => {
                    const reg_tok = try as.expect(.string);
                    const reg = registerFromString(as.source(reg_tok)) orelse
                        return error.InvalidOperand;
                    ops[i] = .{ .reg = reg };
                },
                .memory => {
                    const mem = try as.parseMemory();
                    ops[i] = .{ .mem = mem };
                },
                .immediate => {
                    const is_neg = if (as.expect(.minus)) |_| true else |_| false;
                    const imm_tok = try as.expect(.numeral);
                    const imm: Immediate = if (is_neg) blk: {
                        const imm = try std.fmt.parseInt(i32, as.source(imm_tok), 0);
                        break :blk .{ .signed = imm * -1 };
                    } else .{ .unsigned = try std.fmt.parseInt(u64, as.source(imm_tok), 0) };
                    ops[i] = .{ .imm = imm };
                },
                else => @compileError("unhandled enum literal " ++ @tagName(cond)),
            }
            try as.skip(1, .{.space});
        }

        try as.skip(1, .{.space});
        const tok = try as.it.next();
        switch (tok.id) {
            .new_line, .eof => {},
            else => return error.InvalidOperand,
        }
    }

    fn registerFromString(bytes: []const u8) ?Register {
        const ti = @typeInfo(Register).Enum;
        inline for (ti.fields) |field| {
            if (std.mem.eql(u8, bytes, field.name)) {
                return @field(Register, field.name);
            }
        }
        return null;
    }

    fn parseMemory(as: *Assembler) ParseError!Instruction.Memory {
        const ptr_size: ?Instruction.Memory.PtrSize = blk: {
            const pos = as.it.pos;
            const ptr_size = as.parsePtrSize() catch |err| switch (err) {
                error.UnexpectedToken => {
                    as.it.seekTo(pos);
                    break :blk null;
                },
                else => return err,
            };
            break :blk ptr_size;
        };

        try as.skip(1, .{.space});

        // Supported rules and orderings.
        const rules = .{
            .{ .open_br, .base, .close_br }, // [ base ]
            .{ .open_br, .base, .plus, .disp, .close_br }, // [ base + disp ]
            .{ .open_br, .base, .minus, .disp, .close_br }, // [ base - disp ]
            .{ .open_br, .disp, .plus, .base, .close_br }, // [ disp + base ]
            .{ .open_br, .base, .plus, .index, .close_br }, // [ base + index ]
            .{ .open_br, .base, .plus, .index, .star, .scale, .close_br }, // [ base + index * scale ]
            .{ .open_br, .index, .star, .scale, .plus, .base, .close_br }, // [ index * scale + base ]
            .{ .open_br, .base, .plus, .index, .star, .scale, .plus, .disp, .close_br }, // [ base + index * scale + disp ]
            .{ .open_br, .base, .plus, .index, .star, .scale, .minus, .disp, .close_br }, // [ base + index * scale - disp ]
            .{ .open_br, .index, .star, .scale, .plus, .base, .plus, .disp, .close_br }, // [ index * scale + base + disp ]
            .{ .open_br, .index, .star, .scale, .plus, .base, .minus, .disp, .close_br }, // [ index * scale + base - disp ]
            .{ .open_br, .disp, .plus, .index, .star, .scale, .plus, .base, .close_br }, // [ disp + index * scale + base ]
            .{ .open_br, .disp, .plus, .base, .plus, .index, .star, .scale, .close_br }, // [ disp + base + index * scale ]
            .{ .open_br, .base, .plus, .disp, .plus, .index, .star, .scale, .close_br }, // [ base + disp + index * scale ]
            .{ .open_br, .base, .minus, .disp, .plus, .index, .star, .scale, .close_br }, // [ base - disp + index * scale ]
            .{ .open_br, .base, .plus, .disp, .plus, .scale, .star, .index, .close_br }, // [ base + disp + scale * index ]
            .{ .open_br, .base, .minus, .disp, .plus, .scale, .star, .index, .close_br }, // [ base - disp + scale * index ]
            .{ .open_br, .rip, .plus, .disp, .close_br }, // [ rip + disp ]
            .{ .open_br, .rip, .minus, .disp, .close_br }, // [ rig - disp ]
            .{ .base, .colon, .disp }, // seg:disp
        };

        const pos = as.it.pos;
        inline for (rules) |rule| {
            if (as.parseMemoryRule(rule)) |res| {
                if (res.rip) {
                    if (res.base != null or res.scale_index != null or res.offset != null)
                        return error.InvalidMemoryOperand;
                    return Instruction.Memory.rip(ptr_size orelse .qword, res.disp orelse 0);
                }
                if (res.base) |base| {
                    if (res.rip)
                        return error.InvalidMemoryOperand;
                    if (res.offset) |offset| {
                        if (res.scale_index != null or res.disp != null)
                            return error.InvalidMemoryOperand;
                        return Instruction.Memory.moffs(base, offset);
                    }
                    return Instruction.Memory.sib(ptr_size orelse .qword, .{
                        .base = base,
                        .scale_index = res.scale_index,
                        .disp = res.disp orelse 0,
                    });
                }
                return error.InvalidMemoryOperand;
            } else |_| {
                as.it.seekTo(pos);
            }
        }

        return error.InvalidOperand;
    }

    const MemoryParseResult = struct {
        rip: bool = false,
        base: ?Register = null,
        scale_index: ?Instruction.Memory.ScaleIndex = null,
        disp: ?i32 = null,
        offset: ?u64 = null,
    };

    fn parseMemoryRule(as: *Assembler, rule: anytype) ParseError!Instruction.MemoryParseResult {
        var res: MemoryParseResult = .{};
        inline for (rule, 0..) |cond, i| {
            if (@typeInfo(@TypeOf(cond)) != .EnumLiteral) {
                @compileError("unsupported condition type in the rule: " ++ @typeName(@TypeOf(cond)));
            }
            switch (cond) {
                .open_br, .close_br, .plus, .minus, .star, .colon => {
                    _ = try as.expect(cond);
                },
                .base => {
                    const tok = try as.expect(.string);
                    res.base = registerFromString(as.source(tok)) orelse return error.InvalidMemoryOperand;
                },
                .rip => {
                    const tok = try as.expect(.string);
                    if (!std.mem.eql(u8, as.source(tok), "rip")) return error.InvalidMemoryOperand;
                    res.rip = true;
                },
                .index => {
                    const tok = try as.expect(.string);
                    const index = registerFromString(as.source(tok)) orelse
                        return error.InvalidMemoryOperand;
                    if (res.scale_index) |*si| {
                        si.index = index;
                    } else {
                        res.scale_index = .{ .scale = 1, .index = index };
                    }
                },
                .scale => {
                    const tok = try as.expect(.numeral);
                    const scale = try std.fmt.parseInt(u2, as.source(tok), 0);
                    if (res.scale_index) |*si| {
                        si.scale = scale;
                    } else {
                        res.scale_index = .{ .scale = scale, .index = undefined };
                    }
                },
                .disp => {
                    const tok = try as.expect(.numeral);
                    const is_neg = blk: {
                        if (i > 0) {
                            if (rule[i - 1] == .minus) break :blk true;
                        }
                        break :blk false;
                    };
                    if (std.fmt.parseInt(i32, as.source(tok), 0)) |disp| {
                        res.disp = if (is_neg) -1 * disp else disp;
                    } else |err| switch (err) {
                        error.Overflow => {
                            if (is_neg) return err;
                            if (res.base) |base| {
                                if (base.class() != .segment) return err;
                            }
                            const offset = try std.fmt.parseInt(u64, as.source(tok), 0);
                            res.offset = offset;
                        },
                        else => return err,
                    }
                },
                else => @compileError("unhandled operand output type: " ++ @tagName(cond)),
            }
            try as.skip(1, .{.space});
        }
        return res;
    }

    fn parsePtrSize(as: *Assembler) ParseError!Instruction.Memory.PtrSize {
        const size = try as.expect(.string);
        try as.skip(1, .{.space});
        const ptr = try as.expect(.string);

        const size_raw = as.source(size);
        const ptr_raw = as.source(ptr);
        const len = size_raw.len + ptr_raw.len + 1;
        var buf: ["qword ptr".len]u8 = undefined;
        if (len > buf.len) return error.InvalidPtrSize;

        for (size_raw, 0..) |c, i| {
            buf[i] = std.ascii.toLower(c);
        }
        buf[size_raw.len] = ' ';
        for (ptr_raw, 0..) |c, i| {
            buf[size_raw.len + i + 1] = std.ascii.toLower(c);
        }

        const slice = buf[0..len];
        if (std.mem.eql(u8, slice, "qword ptr")) return .qword;
        if (std.mem.eql(u8, slice, "dword ptr")) return .dword;
        if (std.mem.eql(u8, slice, "word ptr")) return .word;
        if (std.mem.eql(u8, slice, "byte ptr")) return .byte;
        if (std.mem.eql(u8, slice, "tbyte ptr")) return .tbyte;
        return error.InvalidPtrSize;
    }
};
