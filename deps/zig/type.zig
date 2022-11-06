const std = @import("std");
const Target = std.Target;

pub const CType = enum {
    short,
    ushort,
    int,
    uint,
    long,
    ulong,
    longlong,
    ulonglong,
    longdouble,

    // We don't have a `c_float`/`c_double` type in Zig, but these
    // are useful for querying target-correct alignment and checking
    // whether C's double is f64 or f32
    float,
    double,

    pub fn ptrBitWidth(target: Target) u16 {
        switch (target.abi) {
            .gnux32, .muslx32, .gnuabin32, .gnuilp32 => return 32,
            .gnuabi64 => return 64,
            else => {},
        }
        switch (target.cpu.arch) {
            .sparc => if (std.Target.sparc.featureSetHas(target.cpu.features, .v9)) return 64,
            else => {},
        }
        return target.cpu.arch.ptrBitWidth();
    }

    pub fn sizeInBits(self: CType, target: Target) u16 {
        switch (target.os.tag) {
            .freestanding, .other => switch (target.cpu.arch) {
                .msp430 => switch (self) {
                    .short, .ushort, .int, .uint => return 16,
                    .float, .long, .ulong => return 32,
                    .longlong, .ulonglong, .double, .longdouble => return 64,
                },
                .avr => switch (self) {
                    .short, .ushort, .int, .uint => return 16,
                    .long, .ulong, .float, .double, .longdouble => return 32,
                    .longlong, .ulonglong => return 64,
                },
                .tce, .tcele => switch (self) {
                    .short, .ushort => return 16,
                    .int, .uint, .long, .ulong, .longlong, .ulonglong => return 32,
                    .float, .double, .longdouble => return 32,
                },
                .mips64, .mips64el => switch (self) {
                    .short, .ushort => return 16,
                    .int, .uint, .float => return 32,
                    .long, .ulong => return if (target.abi != .gnuabin32) 64 else 32,
                    .longlong, .ulonglong, .double => return 64,
                    .longdouble => return 128,
                },
                .x86_64 => switch (self) {
                    .short, .ushort => return 16,
                    .int, .uint, .float => return 32,
                    .long, .ulong => switch (target.abi) {
                        .gnux32, .muslx32 => return 32,
                        else => return 64,
                    },
                    .longlong, .ulonglong, .double => return 64,
                    .longdouble => return 80,
                },
                else => switch (self) {
                    .short, .ushort => return 16,
                    .int, .uint, .float => return 32,
                    .long, .ulong => return ptrBitWidth(target),
                    .longlong, .ulonglong, .double => return 64,
                    .longdouble => switch (target.cpu.arch) {
                        .x86 => switch (target.abi) {
                            .android => return 64,
                            else => return 80,
                        },

                        .powerpc,
                        .powerpcle,
                        .powerpc64,
                        .powerpc64le,
                        => switch (target.abi) {
                            .musl,
                            .musleabi,
                            .musleabihf,
                            .muslx32,
                            => return 64,
                            else => return 128,
                        },

                        .riscv32,
                        .riscv64,
                        .aarch64,
                        .aarch64_be,
                        .aarch64_32,
                        .s390x,
                        .sparc,
                        .sparc64,
                        .sparcel,
                        .wasm32,
                        .wasm64,
                        => return 128,

                        else => return 64,
                    },
                },
            },

            .linux,
            .freebsd,
            .netbsd,
            .dragonfly,
            .openbsd,
            .wasi,
            .emscripten,
            .plan9,
            .solaris,
            .haiku,
            .ananas,
            .fuchsia,
            .minix,
            => switch (target.cpu.arch) {
                .msp430 => switch (self) {
                    .short, .ushort, .int, .uint => return 16,
                    .long, .ulong, .float => return 32,
                    .longlong, .ulonglong, .double, .longdouble => return 64,
                },
                .avr => switch (self) {
                    .short, .ushort, .int, .uint => return 16,
                    .long, .ulong, .float, .double, .longdouble => return 32,
                    .longlong, .ulonglong => return 64,
                },
                .tce, .tcele => switch (self) {
                    .short, .ushort => return 16,
                    .int, .uint, .long, .ulong, .longlong, .ulonglong => return 32,
                    .float, .double, .longdouble => return 32,
                },
                .mips64, .mips64el => switch (self) {
                    .short, .ushort => return 16,
                    .int, .uint, .float => return 32,
                    .long, .ulong => return if (target.abi != .gnuabin32) 64 else 32,
                    .longlong, .ulonglong, .double => return 64,
                    .longdouble => if (target.os.tag == .freebsd) return 64 else return 128,
                },
                .x86_64 => switch (self) {
                    .short, .ushort => return 16,
                    .int, .uint, .float => return 32,
                    .long, .ulong => switch (target.abi) {
                        .gnux32, .muslx32 => return 32,
                        else => return 64,
                    },
                    .longlong, .ulonglong, .double => return 64,
                    .longdouble => return 80,
                },
                else => switch (self) {
                    .short, .ushort => return 16,
                    .int, .uint, .float => return 32,
                    .long, .ulong => return ptrBitWidth(target),
                    .longlong, .ulonglong, .double => return 64,
                    .longdouble => switch (target.cpu.arch) {
                        .x86 => switch (target.abi) {
                            .android => return 64,
                            else => return 80,
                        },

                        .powerpc,
                        .powerpcle,
                        => switch (target.abi) {
                            .musl,
                            .musleabi,
                            .musleabihf,
                            .muslx32,
                            => return 64,
                            else => switch (target.os.tag) {
                                .freebsd, .netbsd, .openbsd => return 64,
                                else => return 128,
                            },
                        },

                        .powerpc64,
                        .powerpc64le,
                        => switch (target.abi) {
                            .musl,
                            .musleabi,
                            .musleabihf,
                            .muslx32,
                            => return 64,
                            else => switch (target.os.tag) {
                                .freebsd, .openbsd => return 64,
                                else => return 128,
                            },
                        },

                        .riscv32,
                        .riscv64,
                        .aarch64,
                        .aarch64_be,
                        .aarch64_32,
                        .s390x,
                        .mips64,
                        .mips64el,
                        .sparc,
                        .sparc64,
                        .sparcel,
                        .wasm32,
                        .wasm64,
                        => return 128,

                        else => return 64,
                    },
                },
            },

            .windows, .uefi => switch (target.cpu.arch) {
                .x86 => switch (self) {
                    .short, .ushort => return 16,
                    .int, .uint, .float => return 32,
                    .long, .ulong => return 32,
                    .longlong, .ulonglong, .double => return 64,
                    .longdouble => switch (target.abi) {
                        .gnu, .gnuilp32, .cygnus => return 80,
                        else => return 64,
                    },
                },
                .x86_64 => switch (self) {
                    .short, .ushort => return 16,
                    .int, .uint, .float => return 32,
                    .long, .ulong => switch (target.abi) {
                        .cygnus => return 64,
                        else => return 32,
                    },
                    .longlong, .ulonglong, .double => return 64,
                    .longdouble => switch (target.abi) {
                        .gnu, .gnuilp32, .cygnus => return 80,
                        else => return 64,
                    },
                },
                else => switch (self) {
                    .short, .ushort => return 16,
                    .int, .uint, .float => return 32,
                    .long, .ulong => return 32,
                    .longlong, .ulonglong, .double => return 64,
                    .longdouble => return 64,
                },
            },

            .macos, .ios, .tvos, .watchos => switch (self) {
                .short, .ushort => return 16,
                .int, .uint, .float => return 32,
                .long, .ulong => switch (target.cpu.arch) {
                    .x86, .arm, .aarch64_32 => return 32,
                    .x86_64 => switch (target.abi) {
                        .gnux32, .muslx32 => return 32,
                        else => return 64,
                    },
                    else => return 64,
                },
                .longlong, .ulonglong, .double => return 64,
                .longdouble => switch (target.cpu.arch) {
                    .x86 => switch (target.abi) {
                        .android => return 64,
                        else => return 80,
                    },
                    .x86_64 => return 80,
                    else => return 64,
                },
            },

            .nvcl, .cuda => switch (self) {
                .short, .ushort => return 16,
                .int, .uint, .float => return 32,
                .long, .ulong => switch (target.cpu.arch) {
                    .nvptx => return 32,
                    .nvptx64 => return 64,
                    else => return 64,
                },
                .longlong, .ulonglong, .double => return 64,
                .longdouble => return 64,
            },

            .amdhsa, .amdpal => switch (self) {
                .short, .ushort => return 16,
                .int, .uint, .float => return 32,
                .long, .ulong, .longlong, .ulonglong, .double => return 64,
                .longdouble => return 128,
            },

            .cloudabi,
            .kfreebsd,
            .lv2,
            .zos,
            .rtems,
            .nacl,
            .aix,
            .ps4,
            .ps5,
            .elfiamcu,
            .mesa3d,
            .contiki,
            .hermit,
            .hurd,
            .opencl,
            .glsl450,
            .vulkan,
            .driverkit,
            .shadermodel,
            => @panic("TODO specify the C integer and float type sizes for this OS"),
        }
    }

    pub fn alignment(self: CType, target: Target) u16 {

        // Overrides for unusual alignments
        switch (target.cpu.arch) {
            .avr => return 1,
            .x86 => switch (target.os.tag) {
                .windows, .uefi => switch (self) {
                    .longlong, .ulonglong, .double => return 8,
                    .longdouble => switch (target.abi) {
                        .gnu, .gnuilp32, .cygnus => return 4,
                        else => return 8,
                    },
                    else => {},
                },
                else => {},
            },
            else => {},
        }

        // Next-power-of-two-aligned, up to a maximum.
        return @min(
            std.math.ceilPowerOfTwoAssert(u16, (self.sizeInBits(target) + 7) / 8),
            switch (target.cpu.arch) {
                .arm, .armeb, .thumb, .thumbeb => switch (target.os.tag) {
                    .netbsd => switch (target.abi) {
                        .gnueabi,
                        .gnueabihf,
                        .eabi,
                        .eabihf,
                        .android,
                        .musleabi,
                        .musleabihf,
                        => 8,

                        else => @as(u16, 4),
                    },
                    .ios, .tvos, .watchos => 4,
                    else => 8,
                },

                .msp430,
                .avr,
                => 2,

                .arc,
                .csky,
                .x86,
                .xcore,
                .dxil,
                .loongarch32,
                .tce,
                .tcele,
                .le32,
                .amdil,
                .hsail,
                .spir,
                .spirv32,
                .kalimba,
                .shave,
                .renderscript32,
                .ve,
                .spu_2,
                => 4,

                .aarch64_32,
                .amdgcn,
                .amdil64,
                .bpfel,
                .bpfeb,
                .hexagon,
                .hsail64,
                .loongarch64,
                .m68k,
                .mips,
                .mipsel,
                .sparc,
                .sparcel,
                .sparc64,
                .lanai,
                .le64,
                .nvptx,
                .nvptx64,
                .r600,
                .s390x,
                .spir64,
                .spirv64,
                .renderscript64,
                => 8,

                .aarch64,
                .aarch64_be,
                .mips64,
                .mips64el,
                .powerpc,
                .powerpcle,
                .powerpc64,
                .powerpc64le,
                .riscv32,
                .riscv64,
                .x86_64,
                .wasm32,
                .wasm64,
                => 16,
            },
        );
    }

    /// Preferred alignment reported by GNU `__alignof__`
    pub fn preferredAlignment(self: CType, target: Target) u16 {

        // Overrides for unusual alignments
        switch (target.cpu.arch) {
            .arm, .armeb, .thumb, .thumbeb => switch (target.os.tag) {
                .netbsd => switch (target.abi) {
                    .gnueabi,
                    .gnueabihf,
                    .eabi,
                    .eabihf,
                    .android,
                    .musleabi,
                    .musleabihf,
                    => {},

                    else => switch (self) {
                        .longdouble => return 4,
                        else => {},
                    },
                },
                .ios, .tvos, .watchos => switch (self) {
                    .longdouble => return 4,
                    else => {},
                },
                else => {},
            },
            .arc => switch (self) {
                .longdouble => return 4,
                else => {},
            },
            .avr => switch (self) {
                .int, .uint, .long, .ulong, .float, .longdouble => return 1,
                .short, .ushort => return 2,
                .double => return 4,
                .longlong, .ulonglong => return 8,
            },
            .x86 => switch (target.os.tag) {
                .windows, .uefi => switch (self) {
                    .longdouble => switch (target.abi) {
                        .gnu, .gnuilp32, .cygnus => return 4,
                        else => return 8,
                    },
                    else => {},
                },
                else => switch (self) {
                    .longdouble => return 4,
                    else => {},
                },
            },
            else => {},
        }

        // Next-power-of-two-aligned, up to a maximum.
        return @min(
            std.math.ceilPowerOfTwoAssert(u16, (self.sizeInBits(target) + 7) / 8),
            switch (target.cpu.arch) {
                .msp430 => @as(u16, 2),

                .csky,
                .xcore,
                .dxil,
                .loongarch32,
                .tce,
                .tcele,
                .le32,
                .amdil,
                .hsail,
                .spir,
                .spirv32,
                .kalimba,
                .shave,
                .renderscript32,
                .ve,
                .spu_2,
                => 4,

                .arc,
                .arm,
                .armeb,
                .avr,
                .thumb,
                .thumbeb,
                .aarch64_32,
                .amdgcn,
                .amdil64,
                .bpfel,
                .bpfeb,
                .hexagon,
                .hsail64,
                .x86,
                .loongarch64,
                .m68k,
                .mips,
                .mipsel,
                .sparc,
                .sparcel,
                .sparc64,
                .lanai,
                .le64,
                .nvptx,
                .nvptx64,
                .r600,
                .s390x,
                .spir64,
                .spirv64,
                .renderscript64,
                => 8,

                .aarch64,
                .aarch64_be,
                .mips64,
                .mips64el,
                .powerpc,
                .powerpcle,
                .powerpc64,
                .powerpc64le,
                .riscv32,
                .riscv64,
                .x86_64,
                .wasm32,
                .wasm64,
                => 16,
            },
        );
    }
};
