// SPDX-License-Identifier: GPL-3.0-or-later

// This test file is auto-generated. do not edit.
// This file is a derivative work from the test files found// in this repo : https://github.com/mahkoh/repr-c
// and is under the same licence as the original work.

#pragma pack(1)
typedef struct {
#ifdef MSVC
    __declspec(align(2)) char a:1;
#else
    char a:1 __attribute__((aligned(2)));
#endif
} S2;
S2 var1;
#pragma pack()
struct S2_alignment {
#ifdef MSVC
    char a[_Alignof(S2)];
    char b;
#else
    char a;
    S2 b;
#endif
};
struct S2_alignment var2;
#pragma pack(1)
struct S2_packed {
    S2 a;
};
#pragma pack()
struct S2_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct S2_packed)];
    char b;
#else
    char a;
    struct S2_packed b;
#endif
};
struct S2_required_alignment var3;
struct S2_size {
    char a[sizeof(S2)+1];
    char b;
};
struct S2_size var4;

#pragma pack(1)
typedef struct {
#ifdef MSVC
    __declspec(align(4)) char a:1;
#else
    char a:1 __attribute__((aligned(4)));
#endif
} S4;
S4 var5;
#pragma pack()
struct S4_alignment {
#ifdef MSVC
    char a[_Alignof(S4)];
    char b;
#else
    char a;
    S4 b;
#endif
};
struct S4_alignment var6;
#pragma pack(1)
struct S4_packed {
    S4 a;
};
#pragma pack()
struct S4_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct S4_packed)];
    char b;
#else
    char a;
    struct S4_packed b;
#endif
};
struct S4_required_alignment var7;
struct S4_size {
    char a[sizeof(S4)+1];
    char b;
};
struct S4_size var8;

#pragma pack(1)
typedef struct {
#ifdef MSVC
    __declspec(align(8)) char a:1;
#else
    char a:1 __attribute__((aligned(8)));
#endif
} S8;
S8 var9;
#pragma pack()
struct S8_alignment {
#ifdef MSVC
    char a[_Alignof(S8)];
    char b;
#else
    char a;
    S8 b;
#endif
};
struct S8_alignment var10;
#pragma pack(1)
struct S8_packed {
    S8 a;
};
#pragma pack()
struct S8_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct S8_packed)];
    char b;
#else
    char a;
    struct S8_packed b;
#endif
};
struct S8_required_alignment var11;
struct S8_size {
    char a[sizeof(S8)+1];
    char b;
};
struct S8_size var12;

#pragma pack(1)
typedef struct {
#ifdef MSVC
    __declspec(align(16)) char a:1;
#else
    char a:1 __attribute__((aligned(16)));
#endif
} S16;
S16 var13;
#pragma pack()
struct S16_alignment {
#ifdef MSVC
    char a[_Alignof(S16)];
    char b;
#else
    char a;
    S16 b;
#endif
};
struct S16_alignment var14;
#pragma pack(1)
struct S16_packed {
    S16 a;
};
#pragma pack()
struct S16_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct S16_packed)];
    char b;
#else
    char a;
    struct S16_packed b;
#endif
};
struct S16_required_alignment var15;
struct S16_size {
    char a[sizeof(S16)+1];
    char b;
};
struct S16_size var16;

#pragma pack(1)
typedef struct {
#ifdef MSVC
    __declspec(align(32)) char a:1;
#else
    char a:1 __attribute__((aligned(32)));
#endif
} S32;
S32 var17;
#pragma pack()
struct S32_alignment {
#ifdef MSVC
    char a[_Alignof(S32)];
    char b;
#else
    char a;
    S32 b;
#endif
};
struct S32_alignment var18;
#pragma pack(1)
struct S32_packed {
    S32 a;
};
#pragma pack()
struct S32_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct S32_packed)];
    char b;
#else
    char a;
    struct S32_packed b;
#endif
};
struct S32_required_alignment var19;
struct S32_size {
    char a[sizeof(S32)+1];
    char b;
};
struct S32_size var20;

#if defined(AARCH64_APPLE_MACOSX) ||  defined(AARCH64_FUCHSIA) ||  defined(AARCH64_LINUX_ANDROID) ||  defined(AARCH64_UNKNOWN_FREEBSD) ||  \
 defined(AARCH64_UNKNOWN_HERMIT) ||  defined(AARCH64_UNKNOWN_LINUX_GNU) ||  defined(AARCH64_UNKNOWN_LINUX_MUSL) ||  defined(AARCH64_UNKNOWN_NETBSD) ||  \
 defined(AARCH64_UNKNOWN_NONE) ||  defined(AARCH64_UNKNOWN_OPENBSD) ||  defined(AARCH64_UNKNOWN_REDOX) ||  defined(ARM64_APPLE_IOS) ||  \
 defined(ARM64_APPLE_IOS_MACABI) ||  defined(ARM64_APPLE_TVOS) ||  defined(ARMEBV7R_UNKNOWN_NONE_EABI) ||  defined(ARMEBV7R_UNKNOWN_NONE_EABIHF) ||  \
 defined(ARM_LINUX_ANDROIDEABI) ||  defined(ARM_UNKNOWN_LINUX_GNUEABI) ||  defined(ARM_UNKNOWN_LINUX_GNUEABIHF) ||  defined(ARMV4T_UNKNOWN_LINUX_GNUEABI) ||  \
 defined(ARMV5TE_UNKNOWN_LINUX_GNUEABI) ||  defined(ARMV5TE_UNKNOWN_LINUX_UCLIBCGNUEABI) ||  defined(ARMV6_UNKNOWN_FREEBSD_GNUEABIHF) ||  \
 defined(ARMV6_UNKNOWN_NETBSDELF_EABIHF) ||  defined(ARMV7A_NONE_EABI) ||  defined(ARMV7A_NONE_EABIHF) ||  defined(ARMV7_APPLE_IOS) ||  \
 defined(ARMV7_NONE_LINUX_ANDROID) ||  defined(ARMV7R_UNKNOWN_NONE_EABI) ||  defined(ARMV7R_UNKNOWN_NONE_EABIHF) ||  defined(ARMV7S_APPLE_IOS) ||  \
 defined(ARMV7_UNKNOWN_FREEBSD_GNUEABIHF) ||  defined(ARMV7_UNKNOWN_LINUX_GNUEABI) ||  defined(ARMV7_UNKNOWN_LINUX_GNUEABIHF) ||  \
 defined(ARMV7_UNKNOWN_NETBSDELF_EABIHF) ||  defined(AVR_UNKNOWN_UNKNOWN) ||  defined(HEXAGON_UNKNOWN_LINUX_MUSL) ||  defined(I386_APPLE_IOS) ||  \
 defined(I586_UNKNOWN_LINUX_GNU) ||  defined(I586_UNKNOWN_LINUX_MUSL) ||  defined(I686_APPLE_MACOSX) ||  defined(I686_LINUX_ANDROID) ||  \
 defined(I686_PC_WINDOWS_GNU) ||  defined(I686_UNKNOWN_FREEBSD) ||  defined(I686_UNKNOWN_HAIKU) ||  defined(I686_UNKNOWN_LINUX_GNU) ||  \
 defined(I686_UNKNOWN_LINUX_MUSL) ||  defined(I686_UNKNOWN_NETBSDELF) ||  defined(I686_UNKNOWN_OPENBSD) ||  defined(MIPS64EL_UNKNOWN_LINUX_GNUABI64) ||  \
 defined(MIPS64EL_UNKNOWN_LINUX_MUSL) ||  defined(MIPS64_UNKNOWN_LINUX_GNUABI64) ||  defined(MIPS64_UNKNOWN_LINUX_MUSL) ||  defined(MIPSEL_SONY_PSP) ||  \
 defined(MIPSEL_UNKNOWN_LINUX_GNU) ||  defined(MIPSEL_UNKNOWN_LINUX_MUSL) ||  defined(MIPSEL_UNKNOWN_LINUX_UCLIBC) ||  defined(MIPSEL_UNKNOWN_NONE) ||  \
 defined(MIPSISA32R6EL_UNKNOWN_LINUX_GNU) ||  defined(MIPSISA32R6_UNKNOWN_LINUX_GNU) ||  defined(MIPSISA64R6EL_UNKNOWN_LINUX_GNUABI64) ||  \
 defined(MIPSISA64R6_UNKNOWN_LINUX_GNUABI64) ||  defined(MIPS_UNKNOWN_LINUX_GNU) ||  defined(MIPS_UNKNOWN_LINUX_MUSL) ||  defined(MIPS_UNKNOWN_LINUX_UCLIBC) ||  \
 defined(MSP430_NONE_ELF) ||  defined(POWERPC64LE_UNKNOWN_LINUX_GNU) ||  defined(POWERPC64LE_UNKNOWN_LINUX_MUSL) ||  defined(POWERPC64_UNKNOWN_FREEBSD) ||  \
 defined(POWERPC64_UNKNOWN_LINUX_GNU) ||  defined(POWERPC64_UNKNOWN_LINUX_MUSL) ||  defined(POWERPC_UNKNOWN_LINUX_GNU) ||  defined(POWERPC_UNKNOWN_LINUX_GNUSPE) ||  \
 defined(POWERPC_UNKNOWN_LINUX_MUSL) ||  defined(POWERPC_UNKNOWN_NETBSD) ||  defined(RISCV32) ||  defined(RISCV32_UNKNOWN_LINUX_GNU) ||  \
 defined(RISCV64) ||  defined(RISCV64_UNKNOWN_LINUX_GNU) ||  defined(S390X_UNKNOWN_LINUX_GNU) ||  defined(SPARC64_UNKNOWN_LINUX_GNU) ||  \
 defined(SPARC64_UNKNOWN_NETBSD) ||  defined(SPARC64_UNKNOWN_OPENBSD) ||  defined(SPARC_UNKNOWN_LINUX_GNU) ||  defined(SPARCV9_SUN_SOLARIS) ||  \
 defined(THUMBV4T_NONE_EABI) ||  defined(THUMBV6M_NONE_EABI) ||  defined(THUMBV7EM_NONE_EABIHF) ||  defined(THUMBV7EM_NONE_EABI) ||  \
 defined(THUMBV7M_NONE_EABI) ||  defined(THUMBV8MBASE_NONE_EABI) ||  defined(THUMBV8MMAIN_NONE_EABIHF) ||  defined(THUMBV8MMAIN_NONE_EABI) ||  \
 defined(WASM32_UNKNOWN_EMSCRIPTEN) ||  defined(WASM32_UNKNOWN_UNKNOWN) ||  defined(WASM32_WASI) ||  defined(X8664_APPLE_IOS_MACABI) ||  \
 defined(X8664_APPLE_IOS) ||  defined(X8664_APPLE_MACOSX) ||  defined(X8664_APPLE_TVOS) ||  defined(X8664_ELF) ||  defined(X8664_FUCHSIA) ||  \
 defined(X8664_LINUX_ANDROID) ||  defined(X8664_PC_SOLARIS) ||  defined(X8664_PC_WINDOWS_GNU) ||  defined(X8664_RUMPRUN_NETBSD) ||  \
 defined(X8664_UNKNOWN_DRAGONFLY) ||  defined(X8664_UNKNOWN_FREEBSD) ||  defined(X8664_UNKNOWN_HAIKU) ||  defined(X8664_UNKNOWN_HERMIT) ||  \
 defined(X8664_UNKNOWN_L4RE_UCLIBC) ||  defined(X8664_UNKNOWN_LINUX_GNUX32) ||  defined(X8664_UNKNOWN_LINUX_GNU) ||  defined(X8664_UNKNOWN_LINUX_MUSL) ||  \
 defined(X8664_UNKNOWN_NETBSD) ||  defined(X8664_UNKNOWN_OPENBSD) ||  defined(X8664_UNKNOWN_REDOX) 
_Static_assert(sizeof(S2) == 1, "record S2 wrong sizeof");
_Static_assert(_Alignof(S2) == 1, "record S2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct S2_alignment) == 2, "record S2_alignment wrong sizeof");
_Static_assert(_Alignof(struct S2_alignment) == 1, "record S2_alignment wrong alignment");
_Static_assert(sizeof(struct S2_packed) == 1, "record S2_packed wrong sizeof");
_Static_assert(_Alignof(struct S2_packed) == 1, "record S2_packed wrong alignment");
_Static_assert(sizeof(struct S2_required_alignment) == 2, "record S2_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct S2_required_alignment) == 1, "record S2_required_alignment wrong alignment");
_Static_assert(sizeof(struct S2_size) == 3, "record S2_size wrong sizeof");
_Static_assert(_Alignof(struct S2_size) == 1, "record S2_size wrong alignment");
#endif
_Static_assert(sizeof(S4) == 1, "record S4 wrong sizeof");
_Static_assert(_Alignof(S4) == 1, "record S4 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct S4_alignment) == 2, "record S4_alignment wrong sizeof");
_Static_assert(_Alignof(struct S4_alignment) == 1, "record S4_alignment wrong alignment");
_Static_assert(sizeof(struct S4_packed) == 1, "record S4_packed wrong sizeof");
_Static_assert(_Alignof(struct S4_packed) == 1, "record S4_packed wrong alignment");
_Static_assert(sizeof(struct S4_required_alignment) == 2, "record S4_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct S4_required_alignment) == 1, "record S4_required_alignment wrong alignment");
_Static_assert(sizeof(struct S4_size) == 3, "record S4_size wrong sizeof");
_Static_assert(_Alignof(struct S4_size) == 1, "record S4_size wrong alignment");
#endif
_Static_assert(sizeof(S8) == 1, "record S8 wrong sizeof");
_Static_assert(_Alignof(S8) == 1, "record S8 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct S8_alignment) == 2, "record S8_alignment wrong sizeof");
_Static_assert(_Alignof(struct S8_alignment) == 1, "record S8_alignment wrong alignment");
_Static_assert(sizeof(struct S8_packed) == 1, "record S8_packed wrong sizeof");
_Static_assert(_Alignof(struct S8_packed) == 1, "record S8_packed wrong alignment");
_Static_assert(sizeof(struct S8_required_alignment) == 2, "record S8_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct S8_required_alignment) == 1, "record S8_required_alignment wrong alignment");
_Static_assert(sizeof(struct S8_size) == 3, "record S8_size wrong sizeof");
_Static_assert(_Alignof(struct S8_size) == 1, "record S8_size wrong alignment");
#endif
_Static_assert(sizeof(S16) == 1, "record S16 wrong sizeof");
_Static_assert(_Alignof(S16) == 1, "record S16 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct S16_alignment) == 2, "record S16_alignment wrong sizeof");
_Static_assert(_Alignof(struct S16_alignment) == 1, "record S16_alignment wrong alignment");
_Static_assert(sizeof(struct S16_packed) == 1, "record S16_packed wrong sizeof");
_Static_assert(_Alignof(struct S16_packed) == 1, "record S16_packed wrong alignment");
_Static_assert(sizeof(struct S16_required_alignment) == 2, "record S16_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct S16_required_alignment) == 1, "record S16_required_alignment wrong alignment");
_Static_assert(sizeof(struct S16_size) == 3, "record S16_size wrong sizeof");
_Static_assert(_Alignof(struct S16_size) == 1, "record S16_size wrong alignment");
#endif
_Static_assert(sizeof(S32) == 1, "record S32 wrong sizeof");
_Static_assert(_Alignof(S32) == 1, "record S32 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct S32_alignment) == 2, "record S32_alignment wrong sizeof");
_Static_assert(_Alignof(struct S32_alignment) == 1, "record S32_alignment wrong alignment");
_Static_assert(sizeof(struct S32_packed) == 1, "record S32_packed wrong sizeof");
_Static_assert(_Alignof(struct S32_packed) == 1, "record S32_packed wrong alignment");
_Static_assert(sizeof(struct S32_required_alignment) == 2, "record S32_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct S32_required_alignment) == 1, "record S32_required_alignment wrong alignment");
_Static_assert(sizeof(struct S32_size) == 3, "record S32_size wrong sizeof");
_Static_assert(_Alignof(struct S32_size) == 1, "record S32_size wrong alignment");
#endif
#elif defined(AARCH64_PC_WINDOWS_MSVC) ||  defined(I586_PC_WINDOWS_MSVC) ||  defined(I686_PC_WINDOWS_MSVC) ||  defined(I686_UNKNOWN_WINDOWS) ||  \
 defined(THUMBV7A_PC_WINDOWS_MSVC) ||  defined(X8664_PC_WINDOWS_MSVC) ||  defined(X8664_UNKNOWN_WINDOWS) 
_Static_assert(sizeof(S2) == 1, "record S2 wrong sizeof");
_Static_assert(_Alignof(S2) == 2, "record S2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct S2_alignment) == 4, "record S2_alignment wrong sizeof");
_Static_assert(_Alignof(struct S2_alignment) == 2, "record S2_alignment wrong alignment");
_Static_assert(sizeof(struct S2_packed) == 1, "record S2_packed wrong sizeof");
_Static_assert(_Alignof(struct S2_packed) == 1, "record S2_packed wrong alignment");
_Static_assert(sizeof(struct S2_required_alignment) == 2, "record S2_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct S2_required_alignment) == 1, "record S2_required_alignment wrong alignment");
_Static_assert(sizeof(struct S2_size) == 3, "record S2_size wrong sizeof");
_Static_assert(_Alignof(struct S2_size) == 1, "record S2_size wrong alignment");
#endif
_Static_assert(sizeof(S4) == 1, "record S4 wrong sizeof");
_Static_assert(_Alignof(S4) == 4, "record S4 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct S4_alignment) == 8, "record S4_alignment wrong sizeof");
_Static_assert(_Alignof(struct S4_alignment) == 4, "record S4_alignment wrong alignment");
_Static_assert(sizeof(struct S4_packed) == 1, "record S4_packed wrong sizeof");
_Static_assert(_Alignof(struct S4_packed) == 1, "record S4_packed wrong alignment");
_Static_assert(sizeof(struct S4_required_alignment) == 2, "record S4_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct S4_required_alignment) == 1, "record S4_required_alignment wrong alignment");
_Static_assert(sizeof(struct S4_size) == 3, "record S4_size wrong sizeof");
_Static_assert(_Alignof(struct S4_size) == 1, "record S4_size wrong alignment");
#endif
_Static_assert(sizeof(S8) == 1, "record S8 wrong sizeof");
_Static_assert(_Alignof(S8) == 8, "record S8 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct S8_alignment) == 16, "record S8_alignment wrong sizeof");
_Static_assert(_Alignof(struct S8_alignment) == 8, "record S8_alignment wrong alignment");
_Static_assert(sizeof(struct S8_packed) == 1, "record S8_packed wrong sizeof");
_Static_assert(_Alignof(struct S8_packed) == 1, "record S8_packed wrong alignment");
_Static_assert(sizeof(struct S8_required_alignment) == 2, "record S8_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct S8_required_alignment) == 1, "record S8_required_alignment wrong alignment");
_Static_assert(sizeof(struct S8_size) == 3, "record S8_size wrong sizeof");
_Static_assert(_Alignof(struct S8_size) == 1, "record S8_size wrong alignment");
#endif
_Static_assert(sizeof(S16) == 1, "record S16 wrong sizeof");
_Static_assert(_Alignof(S16) == 16, "record S16 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct S16_alignment) == 32, "record S16_alignment wrong sizeof");
_Static_assert(_Alignof(struct S16_alignment) == 16, "record S16_alignment wrong alignment");
_Static_assert(sizeof(struct S16_packed) == 1, "record S16_packed wrong sizeof");
_Static_assert(_Alignof(struct S16_packed) == 1, "record S16_packed wrong alignment");
_Static_assert(sizeof(struct S16_required_alignment) == 2, "record S16_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct S16_required_alignment) == 1, "record S16_required_alignment wrong alignment");
_Static_assert(sizeof(struct S16_size) == 3, "record S16_size wrong sizeof");
_Static_assert(_Alignof(struct S16_size) == 1, "record S16_size wrong alignment");
#endif
_Static_assert(sizeof(S32) == 1, "record S32 wrong sizeof");
_Static_assert(_Alignof(S32) == 32, "record S32 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct S32_alignment) == 64, "record S32_alignment wrong sizeof");
_Static_assert(_Alignof(struct S32_alignment) == 32, "record S32_alignment wrong alignment");
_Static_assert(sizeof(struct S32_packed) == 1, "record S32_packed wrong sizeof");
_Static_assert(_Alignof(struct S32_packed) == 1, "record S32_packed wrong alignment");
_Static_assert(sizeof(struct S32_required_alignment) == 2, "record S32_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct S32_required_alignment) == 1, "record S32_required_alignment wrong alignment");
_Static_assert(sizeof(struct S32_size) == 3, "record S32_size wrong sizeof");
_Static_assert(_Alignof(struct S32_size) == 1, "record S32_size wrong alignment");
#endif
#endif
