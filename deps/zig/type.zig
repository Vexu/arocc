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

    pub fn sizeInBits(self: CType, target: Target) u16 {
        switch (target.os.tag) {
            .freestanding, .other => switch (target.cpu.arch) {
                .msp430 => switch (self) {
                    .short, .ushort, .int, .uint => return 16,
                    .long, .ulong => return 32,
                    .longlong, .ulonglong, .longdouble => return 64,
                },
                .avr => switch (self) {
                    .short, .ushort, .int, .uint => return 16,
                    .long, .ulong, .longdouble => return 32,
                    .longlong, .ulonglong => return 64,
                },
                else => switch (self) {
                    .short, .ushort => return 16,
                    .int, .uint => return 32,
                    .long, .ulong => return target.cpu.arch.ptrBitWidth(),
                    .longlong, .ulonglong => return 64,
                    .longdouble => switch (target.cpu.arch) {
                        .i386, .x86_64 => return 80,

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
                        .powerpc,
                        .powerpcle,
                        .powerpc64,
                        .powerpc64le,
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
                .avr => switch (self) {
                    .short, .ushort, .int, .uint => return 16,
                    .long, .ulong, .longdouble => return 32,
                    .longlong, .ulonglong => return 64,
                },
                else => switch (self) {
                    .short, .ushort => return 16,
                    .int, .uint => return 32,
                    .long, .ulong => return target.cpu.arch.ptrBitWidth(),
                    .longlong, .ulonglong => return 64,
                    .longdouble => switch (target.cpu.arch) {
                        .i386, .x86_64 => return 80,

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
                        .powerpc,
                        .powerpcle,
                        .powerpc64,
                        .powerpc64le,
                        => return 128,

                        else => return 64,
                    },
                },
            },

            .windows, .uefi => switch (self) {
                .short, .ushort => return 16,
                .int, .uint, .long, .ulong => return 32,
                .longlong, .ulonglong, .longdouble => return 64,
            },

            .macos, .ios, .tvos, .watchos => switch (self) {
                .short, .ushort => return 16,
                .int, .uint => return 32,
                .long, .ulong, .longlong, .ulonglong => return 64,
                .longdouble => switch (target.cpu.arch) {
                    .i386, .x86_64 => return 80,
                    else => return 64,
                },
            },

            .cloudabi,
            .kfreebsd,
            .lv2,
            .zos,
            .rtems,
            .nacl,
            .aix,
            .cuda,
            .nvcl,
            .amdhsa,
            .ps4,
            .elfiamcu,
            .mesa3d,
            .contiki,
            .amdpal,
            .hermit,
            .hurd,
            .opencl,
            .glsl450,
            .vulkan,
            => @panic("TODO specify the C integer and float type sizes for this OS"),
        }
    }
};
