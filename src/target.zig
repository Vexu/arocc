const std = @import("std");
const LangOpts = @import("LangOpts.zig");
const Type = @import("Type.zig");
const CType = @import("zig").CType;
const TargetSet = @import("builtins/Properties.zig").TargetSet;

pub fn getCharSignedness(target: std.Target) std.builtin.Signedness {
    switch (target.cpu.arch) {
        .aarch64,
        .aarch64_32,
        .aarch64_be,
        .arm,
        .armeb,
        .thumb,
        .thumbeb,
        => return if (target.os.tag.isDarwin() or target.os.tag == .windows) .signed else .unsigned,
        .powerpc, .powerpc64 => return if (target.os.tag.isDarwin()) .signed else .unsigned,
        .powerpc64le,
        .s390x,
        .xcore,
        .arc,
        .msp430,
        => return .unsigned,
        else => return .signed,
    }
}

/// This function returns 1 if function alignment is not observable or settable.
pub fn defaultFunctionAlignment(target: std.Target) u8 {
    return switch (target.cpu.arch) {
        .arm, .armeb => 4,
        .aarch64, .aarch64_32, .aarch64_be => 4,
        .sparc, .sparcel, .sparc64 => 4,
        .riscv64 => 2,
        else => 1,
    };
}

pub fn isTlsSupported(target: std.Target) bool {
    if (target.isDarwin()) {
        var supported = false;
        switch (target.os.tag) {
            .macos => supported = !(target.os.isAtLeast(.macos, .{ .major = 10, .minor = 7 }) orelse false),
            else => {},
        }
        return supported;
    }
    return switch (target.cpu.arch) {
        .tce, .tcele, .bpfel, .bpfeb, .msp430, .nvptx, .nvptx64, .x86, .arm, .armeb, .thumb, .thumbeb => false,
        else => true,
    };
}

pub fn ignoreNonZeroSizedBitfieldTypeAlignment(target: std.Target) bool {
    switch (target.cpu.arch) {
        .avr => return true,
        .arm => {
            if (std.Target.arm.featureSetHas(target.cpu.features, .has_v7)) {
                switch (target.os.tag) {
                    .ios => return true,
                    else => return false,
                }
            }
        },
        else => return false,
    }
    return false;
}

pub fn ignoreZeroSizedBitfieldTypeAlignment(target: std.Target) bool {
    switch (target.cpu.arch) {
        .avr => return true,
        else => return false,
    }
}

pub fn minZeroWidthBitfieldAlignment(target: std.Target) ?u29 {
    switch (target.cpu.arch) {
        .avr => return 8,
        .arm => {
            if (std.Target.arm.featureSetHas(target.cpu.features, .has_v7)) {
                switch (target.os.tag) {
                    .ios => return 32,
                    else => return null,
                }
            } else return null;
        },
        else => return null,
    }
}

pub fn unnamedFieldAffectsAlignment(target: std.Target) bool {
    switch (target.cpu.arch) {
        .aarch64 => {
            if (target.isDarwin() or target.os.tag == .windows) return false;
            return true;
        },
        .armeb => {
            if (std.Target.arm.featureSetHas(target.cpu.features, .has_v7)) {
                if (std.Target.Abi.default(target.cpu.arch, target.os) == .eabi) return true;
            }
        },
        .arm => return true,
        .avr => return true,
        .thumb => {
            if (target.os.tag == .windows) return false;
            return true;
        },
        else => return false,
    }
    return false;
}

pub fn packAllEnums(target: std.Target) bool {
    return switch (target.cpu.arch) {
        .hexagon => true,
        else => false,
    };
}

/// Default alignment (in bytes) for __attribute__((aligned)) when no alignment is specified
pub fn defaultAlignment(target: std.Target) u29 {
    switch (target.cpu.arch) {
        .avr => return 1,
        .arm => if (target.isAndroid() or target.os.tag == .ios) return 16 else return 8,
        .sparc => if (std.Target.sparc.featureSetHas(target.cpu.features, .v9)) return 16 else return 8,
        .mips, .mipsel => switch (target.abi) {
            .none, .gnuabi64 => return 16,
            else => return 8,
        },
        .s390x, .armeb, .thumbeb, .thumb => return 8,
        else => return 16,
    }
}
pub fn systemCompiler(target: std.Target) LangOpts.Compiler {
    // Android is linux but not gcc, so these checks go first
    // the rest for documentation as fn returns .clang
    if (target.isDarwin() or
        target.isAndroid() or
        target.isBSD() or
        target.os.tag == .fuchsia or
        target.os.tag == .solaris or
        target.os.tag == .haiku or
        target.cpu.arch == .hexagon)
    {
        return .clang;
    }
    if (target.os.tag == .uefi) return .msvc;
    // this is before windows to grab WindowsGnu
    if (target.abi.isGnu() or
        target.os.tag == .linux)
    {
        return .gcc;
    }
    if (target.os.tag == .windows) {
        return .msvc;
    }
    if (target.cpu.arch == .avr) return .gcc;
    return .clang;
}

pub fn hasInt128(target: std.Target) bool {
    if (target.cpu.arch == .wasm32) return true;
    return target.cpu.arch.ptrBitWidth() >= 64;
}

pub const FPSemantics = enum {
    None,
    IEEEHalf,
    BFloat,
    IEEESingle,
    IEEEDouble,
    IEEEQuad,
    /// Minifloat 5-bit exponent 2-bit mantissa
    E5M2,
    /// Minifloat 4-bit exponent 3-bit mantissa
    E4M3,
    x87ExtendedDouble,
    IBMExtendedDouble,

    /// Only intended for generating float.h macros for the preprocessor
    pub fn forType(ty: CType, target: std.Target) FPSemantics {
        std.debug.assert(ty == .float or ty == .double or ty == .longdouble);
        return switch (ty.sizeInBits(target)) {
            32 => .IEEESingle,
            64 => .IEEEDouble,
            80 => .x87ExtendedDouble,
            128 => switch (target.cpu.arch) {
                .powerpc, .powerpcle, .powerpc64, .powerpc64le => .IBMExtendedDouble,
                else => .IEEEQuad,
            },
            else => unreachable,
        };
    }

    pub fn halfPrecisionType(target: std.Target) ?FPSemantics {
        switch (target.cpu.arch) {
            .aarch64,
            .aarch64_32,
            .aarch64_be,
            .arm,
            .armeb,
            .hexagon,
            .riscv32,
            .riscv64,
            .spirv32,
            .spirv64,
            => return .IEEEHalf,
            .x86, .x86_64 => if (std.Target.x86.featureSetHas(target.cpu.features, .sse2)) return .IEEEHalf,
            else => {},
        }
        return null;
    }

    pub fn chooseValue(self: FPSemantics, comptime T: type, values: [6]T) T {
        return switch (self) {
            .IEEEHalf => values[0],
            .IEEESingle => values[1],
            .IEEEDouble => values[2],
            .x87ExtendedDouble => values[3],
            .IBMExtendedDouble => values[4],
            .IEEEQuad => values[5],
            else => unreachable,
        };
    }
};

pub fn isLP64(target: std.Target) bool {
    return CType.sizeInBits(.int, target) == 32 and CType.ptrBitWidth(target) == 64;
}

pub fn builtinEnabled(target: std.Target, enabled_for: TargetSet) bool {
    var copy = enabled_for;
    var it = copy.iterator();
    while (it.next()) |val| {
        switch (val) {
            .basic => return true,
            .x86_64 => if (target.cpu.arch == .x86_64) return true,
            .aarch64 => if (target.cpu.arch == .aarch64) return true,
            .arm => if (target.cpu.arch == .arm) return true,
            .ppc => switch (target.cpu.arch) {
                .powerpc, .powerpc64, .powerpc64le => return true,
                else => {},
            },
            else => {
                // Todo: handle other target predicates
            },
        }
    }
    return false;
}

pub fn defaultFpEvalMethod(target: std.Target) LangOpts.FPEvalMethod {
    if (target.os.tag == .aix) return .double;
    if (target.cpu.arch == .x86 and target.os.tag == .netbsd) {
        if (target.os.version_range.semver.isAtLeast(.{ .major = 6, .minor = 99, .patch = 27 }) orelse true) {
            if (std.Target.x86.featureSetHas(target.cpu.features, .sse)) {
                return .source;
            } else {
                return .extended;
            }
        } else {
            return .double;
        }
    }
    return .source;
}

test "alignment functions - smoke test" {
    var target: std.Target = undefined;
    const x86 = std.Target.Cpu.Arch.x86_64;
    target.cpu = std.Target.Cpu.baseline(x86);
    target.os = std.Target.Os.Tag.defaultVersionRange(.linux, x86);
    target.abi = std.Target.Abi.default(x86, target.os);

    try std.testing.expect(isTlsSupported(target));
    try std.testing.expect(!ignoreNonZeroSizedBitfieldTypeAlignment(target));
    try std.testing.expect(minZeroWidthBitfieldAlignment(target) == null);
    try std.testing.expect(!unnamedFieldAffectsAlignment(target));
    try std.testing.expect(defaultAlignment(target) == 16);
    try std.testing.expect(!packAllEnums(target));
    try std.testing.expect(systemCompiler(target) == .gcc);

    const arm = std.Target.Cpu.Arch.arm;
    target.cpu = std.Target.Cpu.baseline(arm);
    target.os = std.Target.Os.Tag.defaultVersionRange(.ios, arm);
    target.abi = std.Target.Abi.default(arm, target.os);

    try std.testing.expect(!isTlsSupported(target));
    try std.testing.expect(ignoreNonZeroSizedBitfieldTypeAlignment(target));
    try std.testing.expectEqual(@as(?u29, 32), minZeroWidthBitfieldAlignment(target));
    try std.testing.expect(unnamedFieldAffectsAlignment(target));
    try std.testing.expect(defaultAlignment(target) == 16);
    try std.testing.expect(!packAllEnums(target));
    try std.testing.expect(systemCompiler(target) == .clang);
}

test "target size/align tests" {
    var comp: @import("Compilation.zig") = undefined;

    const x86 = std.Target.Cpu.Arch.x86;
    comp.target.cpu.arch = x86;
    comp.target.cpu.model = &std.Target.x86.cpu.i586;
    comp.target.os = std.Target.Os.Tag.defaultVersionRange(.linux, x86);
    comp.target.abi = std.Target.Abi.gnu;

    const tt: Type = .{
        .specifier = .long_long,
    };

    try std.testing.expectEqual(@as(u64, 8), tt.sizeof(&comp).?);
    try std.testing.expectEqual(@as(u64, 4), tt.alignof(&comp));

    const arm = std.Target.Cpu.Arch.arm;
    comp.target.cpu = std.Target.Cpu.Model.toCpu(&std.Target.arm.cpu.cortex_r4, arm);
    comp.target.os = std.Target.Os.Tag.defaultVersionRange(.ios, arm);
    comp.target.abi = std.Target.Abi.none;

    const ct: Type = .{
        .specifier = .char,
    };

    try std.testing.expectEqual(true, std.Target.arm.featureSetHas(comp.target.cpu.features, .has_v7));
    try std.testing.expectEqual(@as(u64, 1), ct.sizeof(&comp).?);
    try std.testing.expectEqual(@as(u64, 1), ct.alignof(&comp));
    try std.testing.expectEqual(true, ignoreNonZeroSizedBitfieldTypeAlignment(comp.target));
}
