const std = @import("std");

const backend = @import("backend");

const LangOpts = @import("LangOpts.zig");
const QualType = @import("TypeStore.zig").QualType;

pub const Vendor = enum {
    apple,
    pc,
    scei,
    sie,
    freescale,
    ibm,
    imagination_technologies,
    mips,
    nvidia,
    csr,
    amd,
    mesa,
    suse,
    open_embedded,
    intel,
    unknown,

    const vendor_strings = std.StaticStringMap(Vendor).initComptime(.{
        .{ "apple", .apple },
        .{ "pc", .pc },
        .{ "scei", .scei },
        .{ "sie", .scei },
        .{ "fsl", .freescale },
        .{ "ibm", .ibm },
        .{ "img", .imagination_technologies },
        .{ "mti", .mips },
        .{ "nvidia", .nvidia },
        .{ "csr", .csr },
        .{ "amd", .amd },
        .{ "mesa", .mesa },
        .{ "suse", .suse },
        .{ "oe", .open_embedded },
        .{ "intel", .intel },
    });

    pub fn parse(candidate: []const u8) ?Vendor {
        return vendor_strings.get(candidate);
    }
};

/// intmax_t for this target
pub fn intMaxType(target: *const std.Target) QualType {
    switch (target.cpu.arch) {
        .aarch64,
        .aarch64_be,
        .sparc64,
        => if (target.os.tag != .openbsd) return .long,

        .bpfel,
        .bpfeb,
        .loongarch64,
        .riscv64,
        .powerpc64,
        .powerpc64le,
        .ve,
        => return .long,

        .x86_64 => switch (target.os.tag) {
            .windows, .openbsd => {},
            else => switch (target.abi) {
                .gnux32, .muslx32 => {},
                else => return .long,
            },
        },

        else => {},
    }
    return .long_long;
}

/// intptr_t for this target
pub fn intPtrType(target: *const std.Target) QualType {
    if (target.os.tag == .haiku) return .long;

    switch (target.cpu.arch) {
        .aarch64, .aarch64_be => switch (target.os.tag) {
            .windows => return .long_long,
            else => {},
        },

        .msp430,
        .csky,
        .loongarch32,
        .riscv32,
        .xcore,
        .hexagon,
        .m68k,
        .spirv32,
        .arc,
        .avr,
        => return .int,

        .sparc => switch (target.os.tag) {
            .netbsd, .openbsd => {},
            else => return .int,
        },

        .powerpc, .powerpcle => switch (target.os.tag) {
            .linux, .freebsd, .netbsd => return .int,
            else => {},
        },

        // 32-bit x86 Darwin, OpenBSD, and RTEMS use long (the default); others use int
        .x86 => switch (target.os.tag) {
            .openbsd, .rtems => {},
            else => if (!target.os.tag.isDarwin()) return .int,
        },

        .x86_64 => switch (target.os.tag) {
            .windows => return .long_long,
            else => switch (target.abi) {
                .gnux32, .muslx32 => return .int,
                else => {},
            },
        },

        else => {},
    }

    return .long;
}

/// int16_t for this target
pub fn int16Type(target: *const std.Target) QualType {
    return switch (target.cpu.arch) {
        .avr => .int,
        else => .short,
    };
}

/// sig_atomic_t for this target
pub fn sigAtomicType(target: *const std.Target) QualType {
    if (target.cpu.arch.isWasm()) return .long;
    return switch (target.cpu.arch) {
        .avr => .schar,
        .msp430 => .long,
        else => .int,
    };
}

/// int64_t for this target
pub fn int64Type(target: *const std.Target) QualType {
    switch (target.cpu.arch) {
        .loongarch64,
        .ve,
        .riscv64,
        .powerpc64,
        .powerpc64le,
        .bpfel,
        .bpfeb,
        => return .long,

        .sparc64 => return intMaxType(target),

        .x86, .x86_64 => if (!target.os.tag.isDarwin()) return intMaxType(target),
        .aarch64, .aarch64_be => if (!target.os.tag.isDarwin() and target.os.tag != .openbsd and target.os.tag != .windows) return .long,
        else => {},
    }
    return .long_long;
}

pub fn float80Type(target: *const std.Target) ?QualType {
    switch (target.cpu.arch) {
        .x86, .x86_64 => return .long_double,
        else => {},
    }
    return null;
}

/// This function returns 1 if function alignment is not observable or settable.
pub fn defaultFunctionAlignment(target: *const std.Target) u8 {
    return switch (target.cpu.arch) {
        .arm, .armeb => 4,
        .aarch64, .aarch64_be => 4,
        .sparc, .sparc64 => 4,
        .riscv64 => 2,
        else => 1,
    };
}

pub fn isTlsSupported(target: *const std.Target) bool {
    if (target.os.tag.isDarwin()) {
        var supported = false;
        switch (target.os.tag) {
            .macos => supported = !(target.os.isAtLeast(.macos, .{ .major = 10, .minor = 7, .patch = 0 }) orelse false),
            else => {},
        }
        return supported;
    }
    return switch (target.cpu.arch) {
        .bpfel, .bpfeb, .msp430, .nvptx, .nvptx64, .x86, .arm, .armeb, .thumb, .thumbeb => false,
        else => true,
    };
}

pub fn ignoreNonZeroSizedBitfieldTypeAlignment(target: *const std.Target) bool {
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

pub fn ignoreZeroSizedBitfieldTypeAlignment(target: *const std.Target) bool {
    switch (target.cpu.arch) {
        .avr => return true,
        else => return false,
    }
}

pub fn minZeroWidthBitfieldAlignment(target: *const std.Target) ?u29 {
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

pub fn unnamedFieldAffectsAlignment(target: *const std.Target) bool {
    switch (target.cpu.arch) {
        .aarch64 => {
            if (target.os.tag.isDarwin() or target.os.tag == .windows) return false;
            return true;
        },
        .armeb => {
            if (std.Target.arm.featureSetHas(target.cpu.features, .has_v7)) {
                if (std.Target.Abi.default(target.cpu.arch, target.os.tag) == .eabi) return true;
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

pub fn packAllEnums(target: *const std.Target) bool {
    return switch (target.cpu.arch) {
        .hexagon => true,
        else => false,
    };
}

/// Default alignment (in bytes) for __attribute__((aligned)) when no alignment is specified
pub fn defaultAlignment(target: *const std.Target) u29 {
    switch (target.cpu.arch) {
        .avr => return 1,
        .arm => if (target.abi.isAndroid() or target.os.tag == .ios) return 16 else return 8,
        .sparc => if (std.Target.sparc.featureSetHas(target.cpu.features, .v9)) return 16 else return 8,
        .mips, .mipsel => switch (target.abi) {
            .none, .gnuabi64 => return 16,
            else => return 8,
        },
        .s390x, .armeb, .thumbeb, .thumb => return 8,
        else => return 16,
    }
}
pub fn systemCompiler(target: *const std.Target) LangOpts.Compiler {
    // Android is linux but not gcc, so these checks go first
    // the rest for documentation as fn returns .clang
    if (target.os.tag.isDarwin() or
        target.abi.isAndroid() or
        target.os.tag.isBSD() or
        target.os.tag == .fuchsia or
        target.os.tag == .illumos or
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

pub fn hasFloat128(target: *const std.Target) bool {
    if (target.cpu.arch.isWasm()) return true;
    if (target.os.tag.isDarwin()) return false;
    if (target.cpu.arch.isPowerPC()) return std.Target.powerpc.featureSetHas(target.cpu.features, .float128);
    return switch (target.os.tag) {
        .dragonfly,
        .haiku,
        .linux,
        .openbsd,
        .illumos,
        => target.cpu.arch.isX86(),
        else => false,
    };
}

pub fn hasInt128(target: *const std.Target) bool {
    if (target.cpu.arch == .wasm32) return true;
    if (target.cpu.arch == .x86_64) return true;
    return target.ptrBitWidth() >= 64;
}

pub fn hasHalfPrecisionFloatABI(target: *const std.Target) bool {
    return switch (target.cpu.arch) {
        .thumb, .thumbeb, .arm, .aarch64 => true,
        else => false,
    };
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
    pub fn forType(ty: std.Target.CType, target: *const std.Target) FPSemantics {
        std.debug.assert(ty == .float or ty == .double or ty == .longdouble);
        return switch (target.cTypeBitSize(ty)) {
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

    pub fn halfPrecisionType(target: *const std.Target) ?FPSemantics {
        switch (target.cpu.arch) {
            .aarch64,
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

pub fn isLP64(target: *const std.Target) bool {
    return target.cTypeBitSize(.int) == 32 and target.ptrBitWidth() == 64;
}

pub fn isKnownWindowsMSVCEnvironment(target: *const std.Target) bool {
    return target.os.tag == .windows and target.abi == .msvc;
}

pub fn isWindowsMSVCEnvironment(target: *const std.Target) bool {
    return target.os.tag == .windows and (target.abi == .msvc or target.abi == .none);
}

pub fn isCygwinMinGW(target: *const std.Target) bool {
    return target.os.tag == .windows and (target.abi == .gnu or target.abi == .cygnus);
}

pub fn isPS(target: *const std.Target) bool {
    return (target.os.tag == .ps4 or target.os.tag == .ps5) and target.cpu.arch == .x86_64;
}

fn toLower(src: []const u8, dest: []u8) ?[]const u8 {
    if (src.len > dest.len) return null;
    for (src, dest[0..src.len]) |a, *b| {
        b.* = std.ascii.toLower(a);
    }
    return dest[0..src.len];
}

pub fn parseArch(query: []const u8) ?std.Target.Cpu.Arch {
    var buf: [64]u8 = undefined;
    const lower = toLower(query, &buf) orelse return null;
    return std.meta.stringToEnum(std.Target.Cpu.Arch, lower) orelse
        std.StaticStringMap(std.Target.Cpu.Arch).initComptime(.{
            .{ "i386", .x86 },
            .{ "i486", .x86 },
            .{ "i586", .x86 },
            .{ "i686", .x86 },
            .{ "i786", .x86 },
            .{ "i886", .x86 },
            .{ "i986", .x86 },
            .{ "amd64", .x86_64 },
            .{ "x86_64h", .x86_64 },
            .{ "powerpcspe", .powerpc },
            .{ "ppc", .powerpc },
            .{ "ppc32", .powerpc },
            .{ "ppcle", .powerpcle },
            .{ "ppc32le", .powerpcle },
            .{ "ppu", .powerpc64 },
            .{ "ppc64", .powerpc64 },
            .{ "ppc64le", .powerpc64le },
            .{ "xscale", .arm },
            .{ "xscaleeb", .armeb },
            .{ "arm64", .aarch64 },
            .{ "arm64e", .aarch64 },
            .{ "arm64ec", .aarch64 },
            .{ "mipseb", .mips },
            .{ "mipsallegrex", .mips },
            .{ "mipsisa32r6", .mips },
            .{ "mipsr6", .mips },
            .{ "mipsallegrexel", .mipsel },
            .{ "mipsisa32r6el", .mipsel },
            .{ "mipsr6el", .mipsel },
            .{ "mips64eb", .mips64 },
            .{ "mipsn32", .mips64 },
            .{ "mipsisa64r6", .mips64 },
            .{ "mips64r6", .mips64 },
            .{ "mipsn32r6", .mips64 },
            .{ "mipsn32el", .mips64el },
            .{ "mipsisa64r6el", .mips64el },
            .{ "mips64r6el", .mips64el },
            .{ "mipsn32r6el", .mips64el },
            .{ "systemz", .s390x },
            .{ "sparcv9", .sparc64 },
            .{ "spirv32", .spirv32 },
            .{ "spirv32v1.0", .spirv32 },
            .{ "spirv32v1.1", .spirv32 },
            .{ "spirv32v1.2", .spirv32 },
            .{ "spirv32v1.3", .spirv32 },
            .{ "spirv32v1.4", .spirv32 },
            .{ "spirv32v1.5", .spirv32 },
            .{ "spirv32v1.6", .spirv32 },
            .{ "spirv64v1.0", .spirv64 },
            .{ "spirv64v1.1", .spirv64 },
            .{ "spirv64v1.2", .spirv64 },
            .{ "spirv64v1.3", .spirv64 },
            .{ "spirv64v1.4", .spirv64 },
            .{ "spirv64v1.5", .spirv64 },
            .{ "spirv64v1.6", .spirv64 },
        }).get(lower) orelse return null;
}

pub fn parseOs(query: []const u8) ?std.Target.Os.Tag {
    var buf: [64]u8 = undefined;
    const lower = toLower(query, &buf) orelse return null;
    return std.meta.stringToEnum(std.Target.Os.Tag, lower) orelse
        std.StaticStringMap(std.Target.Os.Tag).initComptime(.{
            .{ "win32", .windows },
            .{ "xros", .visionos },
        }).get(lower) orelse return null;
}

pub fn isOs(target: *const std.Target, query: []const u8) bool {
    const parsed = parseOs(query) orelse return false;

    if (parsed.isDarwin()) {
        // clang treats all darwin OS's as equivalent
        return target.os.tag.isDarwin();
    }
    return parsed == target.os.tag;
}

pub fn parseVendor(query: []const u8) ?Vendor {
    var buf: [64]u8 = undefined;
    const lower = toLower(query, &buf) orelse return null;
    return Vendor.parse(lower);
}

pub fn parseAbi(query: []const u8) ?std.Target.Abi {
    var buf: [64]u8 = undefined;
    const lower = toLower(query, &buf) orelse return null;
    return std.meta.stringToEnum(std.Target.Abi, lower);
}

pub fn defaultFpEvalMethod(target: *const std.Target) LangOpts.FPEvalMethod {
    switch (target.cpu.arch) {
        .x86, .x86_64 => {
            if (target.ptrBitWidth() == 32 and target.os.tag == .netbsd) {
                if (target.os.version_range.semver.min.order(.{ .major = 6, .minor = 99, .patch = 26 }) != .gt) {
                    // NETBSD <= 6.99.26 on 32-bit x86 defaults to double
                    return .double;
                }
            }
            if (std.Target.x86.featureSetHas(target.cpu.features, .sse)) {
                return .source;
            }
            return .extended;
        },
        else => {},
    }
    return .source;
}

/// Value of the `-m` flag for `ld` for this target
pub fn ldEmulationOption(target: *const std.Target, arm_endianness: ?std.builtin.Endian) ?[]const u8 {
    return switch (target.cpu.arch) {
        .x86 => "elf_i386",
        .arm,
        .armeb,
        .thumb,
        .thumbeb,
        => switch (arm_endianness orelse target.cpu.arch.endian()) {
            .little => "armelf_linux_eabi",
            .big => "armelfb_linux_eabi",
        },
        .aarch64 => "aarch64linux",
        .aarch64_be => "aarch64linuxb",
        .m68k => "m68kelf",
        .powerpc => if (target.os.tag == .linux) "elf32ppclinux" else "elf32ppc",
        .powerpcle => if (target.os.tag == .linux) "elf32lppclinux" else "elf32lppc",
        .powerpc64 => "elf64ppc",
        .powerpc64le => "elf64lppc",
        .riscv32 => "elf32lriscv",
        .riscv64 => "elf64lriscv",
        .sparc => "elf32_sparc",
        .sparc64 => "elf64_sparc",
        .loongarch32 => "elf32loongarch",
        .loongarch64 => "elf64loongarch",
        .mips => "elf32btsmip",
        .mipsel => "elf32ltsmip",
        .mips64 => switch (target.abi) {
            .gnuabin32, .muslabin32 => "elf32btsmipn32",
            else => "elf64btsmip",
        },
        .mips64el => switch (target.abi) {
            .gnuabin32, .muslabin32 => "elf32ltsmipn32",
            else => "elf64ltsmip",
        },
        .x86_64 => switch (target.abi) {
            .gnux32, .muslx32 => "elf32_x86_64",
            else => "elf_x86_64",
        },
        .ve => "elf64ve",
        .csky => "cskyelf_linux",
        else => null,
    };
}

pub fn get32BitArchVariant(target: *const std.Target) ?std.Target {
    var copy = target.*;
    switch (target.cpu.arch) {
        .alpha,
        .amdgcn,
        .avr,
        .bpfeb,
        .bpfel,
        .msp430,
        .s390x,
        .ve,
        => return null,

        .arc,
        .arceb,
        .arm,
        .armeb,
        .csky,
        .hexagon,
        .hppa,
        .kalimba,
        .lanai,
        .loongarch32,
        .m68k,
        .microblaze,
        .microblazeel,
        .mips,
        .mipsel,
        .nvptx,
        .or1k,
        .powerpc,
        .powerpcle,
        .propeller,
        .riscv32,
        .riscv32be,
        .sh,
        .sheb,
        .sparc,
        .spirv32,
        .thumb,
        .thumbeb,
        .wasm32,
        .x86,
        .xcore,
        .xtensa,
        .xtensaeb,
        => {}, // Already 32 bit

        .aarch64 => copy.cpu.arch = .arm,
        .aarch64_be => copy.cpu.arch = .armeb,
        .hppa64 => copy.cpu.arch = .hppa,
        .loongarch64 => copy.cpu.arch = .loongarch32,
        .mips64 => copy.cpu.arch = .mips,
        .mips64el => copy.cpu.arch = .mipsel,
        .nvptx64 => copy.cpu.arch = .nvptx,
        .powerpc64 => copy.cpu.arch = .powerpc,
        .powerpc64le => copy.cpu.arch = .powerpcle,
        .riscv64 => copy.cpu.arch = .riscv32,
        .riscv64be => copy.cpu.arch = .riscv32be,
        .sparc64 => copy.cpu.arch = .sparc,
        .spirv64 => copy.cpu.arch = .spirv32,
        .wasm64 => copy.cpu.arch = .wasm32,
        .x86_16 => copy.cpu.arch = .x86,
        .x86_64 => copy.cpu.arch = .x86,
    }
    return copy;
}

pub fn get64BitArchVariant(target: *const std.Target) ?std.Target {
    var copy = target.*;
    switch (target.cpu.arch) {
        .arc,
        .arceb,
        .avr,
        .csky,
        .hexagon,
        .kalimba,
        .lanai,
        .m68k,
        .microblaze,
        .microblazeel,
        .msp430,
        .or1k,
        .propeller,
        .sh,
        .sheb,
        .xcore,
        .xtensa,
        .xtensaeb,
        => return null,

        .aarch64_be,
        .aarch64,
        .alpha,
        .amdgcn,
        .bpfeb,
        .bpfel,
        .hppa64,
        .loongarch64,
        .mips64,
        .mips64el,
        .nvptx64,
        .powerpc64,
        .powerpc64le,
        .riscv64,
        .riscv64be,
        .s390x,
        .sparc64,
        .spirv64,
        .ve,
        .wasm64,
        .x86_64,
        => {}, // Already 64 bit

        .arm => copy.cpu.arch = .aarch64,
        .armeb => copy.cpu.arch = .aarch64_be,
        .hppa => copy.cpu.arch = .hppa64,
        .loongarch32 => copy.cpu.arch = .loongarch64,
        .mips => copy.cpu.arch = .mips64,
        .mipsel => copy.cpu.arch = .mips64el,
        .nvptx => copy.cpu.arch = .nvptx64,
        .powerpc => copy.cpu.arch = .powerpc64,
        .powerpcle => copy.cpu.arch = .powerpc64le,
        .riscv32 => copy.cpu.arch = .riscv64,
        .riscv32be => copy.cpu.arch = .riscv64be,
        .sparc => copy.cpu.arch = .sparc64,
        .spirv32 => copy.cpu.arch = .spirv64,
        .thumb => copy.cpu.arch = .aarch64,
        .thumbeb => copy.cpu.arch = .aarch64_be,
        .wasm32 => copy.cpu.arch = .wasm64,
        .x86 => copy.cpu.arch = .x86_64,
        .x86_16 => copy.cpu.arch = .x86_64,
    }
    return copy;
}

/// Adapted from Zig's src/codegen/llvm.zig
pub fn toLLVMTriple(target: *const std.Target, buf: []u8) []const u8 {
    // 64 bytes is assumed to be large enough to hold any target triple; increase if necessary
    std.debug.assert(buf.len >= 64);

    var writer: std.Io.Writer = .fixed(buf);

    const llvm_arch = switch (target.cpu.arch) {
        .arm => "arm",
        .armeb => "armeb",
        .aarch64 => if (target.abi == .ilp32) "aarch64_32" else "aarch64",
        .aarch64_be => "aarch64_be",
        .arc => "arc",
        .avr => "avr",
        .bpfel => "bpfel",
        .bpfeb => "bpfeb",
        .csky => "csky",
        .hexagon => "hexagon",
        .loongarch32 => "loongarch32",
        .loongarch64 => "loongarch64",
        .m68k => "m68k",
        .mips => "mips",
        .mipsel => "mipsel",
        .mips64 => "mips64",
        .mips64el => "mips64el",
        .msp430 => "msp430",
        .powerpc => "powerpc",
        .powerpcle => "powerpcle",
        .powerpc64 => "powerpc64",
        .powerpc64le => "powerpc64le",
        .amdgcn => "amdgcn",
        .riscv32 => "riscv32",
        .riscv32be => "riscv32be",
        .riscv64 => "riscv64",
        .riscv64be => "riscv64be",
        .sparc => "sparc",
        .sparc64 => "sparc64",
        .s390x => "s390x",
        .thumb => "thumb",
        .thumbeb => "thumbeb",
        .x86 => "i386",
        .x86_64 => "x86_64",
        .xcore => "xcore",
        .xtensa => "xtensa",
        .nvptx => "nvptx",
        .nvptx64 => "nvptx64",
        .spirv32 => "spirv32",
        .spirv64 => "spirv64",
        .lanai => "lanai",
        .wasm32 => "wasm32",
        .wasm64 => "wasm64",
        .ve => "ve",
        // Note: these are not supported in LLVM; this is the Zig arch name
        .kalimba => "kalimba",
        .propeller => "propeller",
        .or1k => "or1k",
        .alpha => "alpha",
        .arceb => "arceb",
        .hppa => "hppa",
        .hppa64 => "hppa64",
        .microblaze => "microblaze",
        .microblazeel => "microblazeel",
        .sh => "sh",
        .sheb => "sheb",
        .xtensaeb => "xtensaeb",
        .x86_16 => "i86",
    };
    writer.writeAll(llvm_arch) catch unreachable;
    writer.writeByte('-') catch unreachable;

    const llvm_os = switch (target.os.tag) {
        .freestanding => "unknown",
        .dragonfly => "dragonfly",
        .freebsd => "freebsd",
        .fuchsia => "fuchsia",
        .linux => "linux",
        .ps3 => "lv2",
        .netbsd => "netbsd",
        .openbsd => "openbsd",
        .illumos => "illumos",
        .windows => "windows",
        .haiku => "haiku",
        .rtems => "rtems",
        .cuda => "cuda",
        .nvcl => "nvcl",
        .amdhsa => "amdhsa",
        .ps4 => "ps4",
        .ps5 => "ps5",
        .mesa3d => "mesa3d",
        .contiki => "contiki",
        .amdpal => "amdpal",
        .hermit => "hermit",
        .hurd => "hurd",
        .wasi => "wasi",
        .emscripten => "emscripten",
        .uefi => "windows",
        .macos => "macosx",
        .ios => "ios",
        .tvos => "tvos",
        .watchos => "watchos",
        .driverkit => "driverkit",
        .visionos => "xros",
        .serenity => "serenity",
        .vulkan => "vulkan",
        .managarm => "managarm",
        .@"3ds",
        .vita,
        .opencl,
        .opengl,
        .plan9,
        .other,
        => "unknown",
    };
    writer.writeAll(llvm_os) catch unreachable;

    if (target.os.tag.isDarwin()) {
        const min_version = target.os.version_range.semver.min;
        writer.print("{d}.{d}.{d}", .{
            min_version.major,
            min_version.minor,
            min_version.patch,
        }) catch unreachable;
    }
    writer.writeByte('-') catch unreachable;

    const llvm_abi = switch (target.abi) {
        .none, .ilp32 => "unknown",
        .gnu => "gnu",
        .gnuabin32 => "gnuabin32",
        .gnuabi64 => "gnuabi64",
        .gnueabi => "gnueabi",
        .gnueabihf => "gnueabihf",
        .gnuf32 => "gnuf32",
        .gnusf => "gnusf",
        .gnux32 => "gnux32",
        .code16 => "code16",
        .eabi => "eabi",
        .eabihf => "eabihf",
        .android => "android",
        .androideabi => "androideabi",
        .musl => "musl",
        .muslabin32 => "muslabin32",
        .muslabi64 => "muslabi64",
        .musleabi => "musleabi",
        .musleabihf => "musleabihf",
        .muslf32 => "muslf32",
        .muslsf => "muslsf",
        .muslx32 => "muslx32",
        .msvc => "msvc",
        .itanium => "itanium",
        .cygnus => "cygnus",
        .simulator => "simulator",
        .macabi => "macabi",
        .ohos => "ohos",
        .ohoseabi => "ohoseabi",
    };
    writer.writeAll(llvm_abi) catch unreachable;
    return writer.buffered();
}

pub const DefaultPIStatus = enum { yes, no, depends_on_linker };

pub fn isPIEDefault(target: *const std.Target) DefaultPIStatus {
    return switch (target.os.tag) {
        .haiku,

        .macos,
        .ios,
        .tvos,
        .watchos,
        .visionos,
        .driverkit,

        .dragonfly,
        .netbsd,
        .freebsd,
        .illumos,

        .cuda,
        .amdhsa,
        .amdpal,
        .mesa3d,

        .ps4,
        .ps5,

        .hurd,
        => .no,

        .openbsd,
        .fuchsia,
        => .yes,

        .linux => {
            if (target.abi == .ohos)
                return .yes;

            switch (target.cpu.arch) {
                .ve => return .no,
                else => return if (target.os.tag == .linux or target.abi.isAndroid() or target.abi.isMusl()) .yes else .no,
            }
        },

        .windows => {
            if (target.isMinGW())
                return .no;

            if (target.abi == .itanium)
                return if (target.cpu.arch == .x86_64) .yes else .no;

            if (target.abi == .msvc or target.abi == .none)
                return .depends_on_linker;

            return .no;
        },

        else => {
            switch (target.cpu.arch) {
                .hexagon => {
                    // CLANG_DEFAULT_PIE_ON_LINUX
                    return if (target.os.tag == .linux or target.abi.isAndroid() or target.abi.isMusl()) .yes else .no;
                },

                else => return .no,
            }
        },
    };
}

pub fn isPICdefault(target: *const std.Target) DefaultPIStatus {
    return switch (target.os.tag) {
        .haiku,

        .macos,
        .ios,
        .tvos,
        .watchos,
        .visionos,
        .driverkit,

        .amdhsa,
        .amdpal,
        .mesa3d,

        .ps4,
        .ps5,
        => .yes,

        .fuchsia,
        .cuda,
        => .no,

        .dragonfly,
        .openbsd,
        .netbsd,
        .freebsd,
        .illumos,
        .hurd,
        => {
            return switch (target.cpu.arch) {
                .mips64, .mips64el => .yes,
                else => .no,
            };
        },

        .linux => {
            if (target.abi == .ohos)
                return .no;

            return switch (target.cpu.arch) {
                .mips64, .mips64el => .yes,
                else => .no,
            };
        },

        .windows => {
            if (target.isMinGW())
                return if (target.cpu.arch == .x86_64 or target.cpu.arch == .aarch64) .yes else .no;

            if (target.abi == .itanium)
                return if (target.cpu.arch == .x86_64) .yes else .no;

            if (target.abi == .msvc or target.abi == .none)
                return .depends_on_linker;

            if (target.ofmt == .macho)
                return .yes;

            return switch (target.cpu.arch) {
                .x86_64, .mips64, .mips64el => .yes,
                else => .no,
            };
        },

        else => {
            if (target.ofmt == .macho)
                return .yes;

            return switch (target.cpu.arch) {
                .mips64, .mips64el => .yes,
                else => .no,
            };
        },
    };
}

pub fn isPICDefaultForced(target: *const std.Target) DefaultPIStatus {
    return switch (target.os.tag) {
        .amdhsa, .amdpal, .mesa3d => .yes,

        .haiku,
        .dragonfly,
        .openbsd,
        .netbsd,
        .freebsd,
        .illumos,
        .cuda,
        .ps4,
        .ps5,
        .hurd,
        .linux,
        .fuchsia,
        => .no,

        .windows => {
            if (target.isMinGW())
                return .yes;

            if (target.abi == .itanium)
                return if (target.cpu.arch == .x86_64) .yes else .no;

            // if (bfd) return target.cpu.arch == .x86_64 else target.cpu.arch == .x86_64 or target.cpu.arch == .aarch64;
            if (target.abi == .msvc or target.abi == .none)
                return .depends_on_linker;

            if (target.ofmt == .macho)
                return if (target.cpu.arch == .aarch64 or target.cpu.arch == .x86_64) .yes else .no;

            return if (target.cpu.arch == .x86_64) .yes else .no;
        },

        .macos,
        .ios,
        .tvos,
        .watchos,
        .visionos,
        .driverkit,
        => if (target.cpu.arch == .x86_64 or target.cpu.arch == .aarch64) .yes else .no,

        else => {
            return switch (target.cpu.arch) {
                .hexagon,
                .lanai,
                .avr,
                .riscv32,
                .riscv64,
                .csky,
                .xcore,
                .wasm32,
                .wasm64,
                .ve,
                .spirv32,
                .spirv64,
                => .no,

                .msp430 => .yes,

                else => {
                    if (target.ofmt == .macho)
                        return if (target.cpu.arch == .aarch64 or target.cpu.arch == .x86_64) .yes else .no;
                    return .no;
                },
            };
        },
    };
}

test "alignment functions - smoke test" {
    const linux: std.Target.Os = .{ .tag = .linux, .version_range = .{ .none = {} } };
    const x86_64_target: std.Target = .{
        .abi = .default(.x86_64, linux.tag),
        .cpu = std.Target.Cpu.Model.generic(.x86_64).toCpu(.x86_64),
        .os = linux,
        .ofmt = .elf,
    };

    try std.testing.expect(isTlsSupported(&x86_64_target));
    try std.testing.expect(!ignoreNonZeroSizedBitfieldTypeAlignment(&x86_64_target));
    try std.testing.expect(minZeroWidthBitfieldAlignment(&x86_64_target) == null);
    try std.testing.expect(!unnamedFieldAffectsAlignment(&x86_64_target));
    try std.testing.expect(defaultAlignment(&x86_64_target) == 16);
    try std.testing.expect(!packAllEnums(&x86_64_target));
    try std.testing.expect(systemCompiler(&x86_64_target) == .gcc);
}

test "target size/align tests" {
    var comp: @import("Compilation.zig") = undefined;

    const linux: std.Target.Os = .{ .tag = .linux, .version_range = .{ .none = {} } };
    const x86_target: std.Target = .{
        .abi = .default(.x86, linux.tag),
        .cpu = std.Target.Cpu.Model.generic(.x86).toCpu(.x86),
        .os = linux,
        .ofmt = .elf,
    };
    comp.target = x86_target;

    const tt: QualType = .long_long;

    try std.testing.expectEqual(@as(u64, 8), tt.sizeof(&comp));
    try std.testing.expectEqual(@as(u64, 4), tt.alignof(&comp));
}

/// The canonical integer representation of nullptr_t.
pub fn nullRepr(_: *const std.Target) u64 {
    return 0;
}
