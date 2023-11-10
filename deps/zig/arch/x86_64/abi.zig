pub const Class = enum {
    integer,
    sse,
    sseup,
    x87,
    x87up,
    complex_x87,
    memory,
    none,
    win_i128,
    float,
    float_combine,
};

pub const SysV = struct {
    /// Note that .rsp and .rbp also belong to this set, however, we never expect to use them
    /// for anything else but stack offset tracking therefore we exclude them from this set.
    pub const callee_preserved_regs = [_]Register{ .rbx, .r12, .r13, .r14, .r15 };
    /// These registers need to be preserved (saved on the stack) and restored by the caller before
    /// the caller relinquishes control to a subroutine via call instruction (or similar).
    /// In other words, these registers are free to use by the callee.
    pub const caller_preserved_regs = [_]Register{ .rax, .rcx, .rdx, .rsi, .rdi, .r8, .r9, .r10, .r11 } ++ x87_regs ++ sse_avx_regs;

    pub const c_abi_int_param_regs = [_]Register{ .rdi, .rsi, .rdx, .rcx, .r8, .r9 };
    pub const c_abi_sse_param_regs = sse_avx_regs[0..8].*;
    pub const c_abi_int_return_regs = [_]Register{ .rax, .rdx };
    pub const c_abi_sse_return_regs = sse_avx_regs[0..2].*;
};

pub const Win64 = struct {
    /// Note that .rsp and .rbp also belong to this set, however, we never expect to use them
    /// for anything else but stack offset tracking therefore we exclude them from this set.
    pub const callee_preserved_regs = [_]Register{ .rbx, .rsi, .rdi, .r12, .r13, .r14, .r15 };
    /// These registers need to be preserved (saved on the stack) and restored by the caller before
    /// the caller relinquishes control to a subroutine via call instruction (or similar).
    /// In other words, these registers are free to use by the callee.
    pub const caller_preserved_regs = [_]Register{ .rax, .rcx, .rdx, .r8, .r9, .r10, .r11 } ++ x87_regs ++ sse_avx_regs;

    pub const c_abi_int_param_regs = [_]Register{ .rcx, .rdx, .r8, .r9 };
    pub const c_abi_sse_param_regs = sse_avx_regs[0..4].*;
    pub const c_abi_int_return_regs = [_]Register{.rax};
    pub const c_abi_sse_return_regs = sse_avx_regs[0..1].*;
};

pub fn resolveCallingConvention(
    cc: std.builtin.CallingConvention,
    target: std.Target,
) std.builtin.CallingConvention {
    return switch (cc) {
        .Unspecified, .C => switch (target.os.tag) {
            else => .SysV,
            .windows => .Win64,
        },
        else => cc,
    };
}

pub fn getCalleePreservedRegs(cc: std.builtin.CallingConvention) []const Register {
    return switch (cc) {
        .SysV => &SysV.callee_preserved_regs,
        .Win64 => &Win64.callee_preserved_regs,
        else => unreachable,
    };
}

pub fn getCallerPreservedRegs(cc: std.builtin.CallingConvention) []const Register {
    return switch (cc) {
        .SysV => &SysV.caller_preserved_regs,
        .Win64 => &Win64.caller_preserved_regs,
        else => unreachable,
    };
}

pub fn getCAbiIntParamRegs(cc: std.builtin.CallingConvention) []const Register {
    return switch (cc) {
        .SysV => &SysV.c_abi_int_param_regs,
        .Win64 => &Win64.c_abi_int_param_regs,
        else => unreachable,
    };
}

pub fn getCAbiSseParamRegs(cc: std.builtin.CallingConvention) []const Register {
    return switch (cc) {
        .SysV => &SysV.c_abi_sse_param_regs,
        .Win64 => &Win64.c_abi_sse_param_regs,
        else => unreachable,
    };
}

pub fn getCAbiIntReturnRegs(cc: std.builtin.CallingConvention) []const Register {
    return switch (cc) {
        .SysV => &SysV.c_abi_int_return_regs,
        .Win64 => &Win64.c_abi_int_return_regs,
        else => unreachable,
    };
}

pub fn getCAbiSseReturnRegs(cc: std.builtin.CallingConvention) []const Register {
    return switch (cc) {
        .SysV => &SysV.c_abi_sse_return_regs,
        .Win64 => &Win64.c_abi_sse_return_regs,
        else => unreachable,
    };
}

const gp_regs = [_]Register{
    .rax, .rcx, .rdx, .rbx, .rsi, .rdi, .r8, .r9, .r10, .r11, .r12, .r13, .r14, .r15,
};
const x87_regs = [_]Register{
    .st0, .st1, .st2, .st3, .st4, .st5, .st6, .st7,
};
const sse_avx_regs = [_]Register{
    .ymm0, .ymm1, .ymm2,  .ymm3,  .ymm4,  .ymm5,  .ymm6,  .ymm7,
    .ymm8, .ymm9, .ymm10, .ymm11, .ymm12, .ymm13, .ymm14, .ymm15,
};
pub const allocatable_regs = gp_regs ++ x87_regs[0 .. x87_regs.len - 1] ++ sse_avx_regs;

const builtin = @import("builtin");
const std = @import("std");
const assert = std.debug.assert;
const testing = std.testing;

const Register = @import("bits.zig").Register;
