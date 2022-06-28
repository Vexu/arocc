// SPDX-License-Identifier: GPL-3.0-or-later

// This test file is auto-generated. do not edit.
// This file is a derivative work from the test files found// in this repo : https://github.com/mahkoh/repr-c
// and is under the same licence as the original work.

#ifdef MSVC
__declspec(align(2)) typedef long long F;
#else
typedef long long F __attribute__((aligned(2)));
#endif
F var1;
struct F_alignment {
#ifdef MSVC
    char a[_Alignof(F)];
    char b;
#else
    char a;
    F b;
#endif
};
struct F_alignment var2;
#pragma pack(1)
struct F_packed {
    F a;
};
#pragma pack()
struct F_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct F_packed)];
    char b;
#else
    char a;
    struct F_packed b;
#endif
};
struct F_required_alignment var3;
struct F_size {
    char a[sizeof(F)+1];
    char b;
};
struct F_size var4;

typedef struct {
    F c:15;
    F d:64;
} G;
G var5;
struct G_alignment {
#ifdef MSVC
    char a[_Alignof(G)];
    char b;
#else
    char a;
    G b;
#endif
};
struct G_alignment var6;
#pragma pack(1)
struct G_packed {
    G a;
};
#pragma pack()
struct G_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct G_packed)];
    char b;
#else
    char a;
    struct G_packed b;
#endif
};
struct G_required_alignment var7;
struct G_size {
    char a[sizeof(G)+1];
    char b;
};
struct G_size var8;

#if defined(AARCH64_APPLE_MACOSX) ||  defined(AARCH64_FUCHSIA) ||  defined(AARCH64_LINUX_ANDROID) ||  defined(AARCH64_UNKNOWN_FREEBSD) ||  \
 defined(AARCH64_UNKNOWN_HERMIT) ||  defined(AARCH64_UNKNOWN_LINUX_GNU) ||  defined(AARCH64_UNKNOWN_LINUX_MUSL) ||  defined(AARCH64_UNKNOWN_NETBSD) ||  \
 defined(AARCH64_UNKNOWN_NONE) ||  defined(AARCH64_UNKNOWN_OPENBSD) ||  defined(AARCH64_UNKNOWN_REDOX) ||  defined(ARM64_APPLE_IOS) ||  \
 defined(ARM64_APPLE_IOS_MACABI) ||  defined(ARM64_APPLE_TVOS) ||  defined(ARMEBV7R_UNKNOWN_NONE_EABI) ||  defined(ARMEBV7R_UNKNOWN_NONE_EABIHF) ||  \
 defined(ARM_LINUX_ANDROIDEABI) ||  defined(ARM_UNKNOWN_LINUX_GNUEABI) ||  defined(ARM_UNKNOWN_LINUX_GNUEABIHF) ||  defined(ARMV4T_UNKNOWN_LINUX_GNUEABI) ||  \
 defined(ARMV5TE_UNKNOWN_LINUX_GNUEABI) ||  defined(ARMV5TE_UNKNOWN_LINUX_UCLIBCGNUEABI) ||  defined(ARMV6_UNKNOWN_FREEBSD_GNUEABIHF) ||  \
 defined(ARMV6_UNKNOWN_NETBSDELF_EABIHF) ||  defined(ARMV7A_NONE_EABI) ||  defined(ARMV7A_NONE_EABIHF) ||  defined(ARMV7_NONE_LINUX_ANDROID) ||  \
 defined(ARMV7R_UNKNOWN_NONE_EABI) ||  defined(ARMV7R_UNKNOWN_NONE_EABIHF) ||  defined(ARMV7_UNKNOWN_FREEBSD_GNUEABIHF) ||  defined(ARMV7_UNKNOWN_LINUX_GNUEABI) ||  \
 defined(ARMV7_UNKNOWN_LINUX_GNUEABIHF) ||  defined(ARMV7_UNKNOWN_NETBSDELF_EABIHF) ||  defined(HEXAGON_UNKNOWN_LINUX_MUSL) ||  defined(MIPS64EL_UNKNOWN_LINUX_GNUABI64) ||  \
 defined(MIPS64EL_UNKNOWN_LINUX_MUSL) ||  defined(MIPS64_UNKNOWN_LINUX_GNUABI64) ||  defined(MIPS64_UNKNOWN_LINUX_MUSL) ||  defined(MIPSEL_SONY_PSP) ||  \
 defined(MIPSEL_UNKNOWN_LINUX_GNU) ||  defined(MIPSEL_UNKNOWN_LINUX_MUSL) ||  defined(MIPSEL_UNKNOWN_LINUX_UCLIBC) ||  defined(MIPSEL_UNKNOWN_NONE) ||  \
 defined(MIPSISA32R6EL_UNKNOWN_LINUX_GNU) ||  defined(MIPSISA32R6_UNKNOWN_LINUX_GNU) ||  defined(MIPSISA64R6EL_UNKNOWN_LINUX_GNUABI64) ||  \
 defined(MIPSISA64R6_UNKNOWN_LINUX_GNUABI64) ||  defined(MIPS_UNKNOWN_LINUX_GNU) ||  defined(MIPS_UNKNOWN_LINUX_MUSL) ||  defined(MIPS_UNKNOWN_LINUX_UCLIBC) ||  \
 defined(POWERPC64LE_UNKNOWN_LINUX_GNU) ||  defined(POWERPC64LE_UNKNOWN_LINUX_MUSL) ||  defined(POWERPC64_UNKNOWN_FREEBSD) ||  defined(POWERPC64_UNKNOWN_LINUX_GNU) ||  \
 defined(POWERPC64_UNKNOWN_LINUX_MUSL) ||  defined(POWERPC_UNKNOWN_LINUX_GNU) ||  defined(POWERPC_UNKNOWN_LINUX_GNUSPE) ||  defined(POWERPC_UNKNOWN_LINUX_MUSL) ||  \
 defined(POWERPC_UNKNOWN_NETBSD) ||  defined(RISCV32) ||  defined(RISCV32_UNKNOWN_LINUX_GNU) ||  defined(RISCV64) ||  defined(RISCV64_UNKNOWN_LINUX_GNU) ||  \
 defined(S390X_UNKNOWN_LINUX_GNU) ||  defined(SPARC64_UNKNOWN_LINUX_GNU) ||  defined(SPARC64_UNKNOWN_NETBSD) ||  defined(SPARC64_UNKNOWN_OPENBSD) ||  \
 defined(SPARC_UNKNOWN_LINUX_GNU) ||  defined(SPARCV9_SUN_SOLARIS) ||  defined(THUMBV4T_NONE_EABI) ||  defined(THUMBV6M_NONE_EABI) ||  \
 defined(THUMBV7EM_NONE_EABIHF) ||  defined(THUMBV7EM_NONE_EABI) ||  defined(THUMBV7M_NONE_EABI) ||  defined(THUMBV8MBASE_NONE_EABI) ||  \
 defined(THUMBV8MMAIN_NONE_EABIHF) ||  defined(THUMBV8MMAIN_NONE_EABI) ||  defined(WASM32_UNKNOWN_EMSCRIPTEN) ||  defined(WASM32_UNKNOWN_UNKNOWN) ||  \
 defined(WASM32_WASI) ||  defined(X8664_APPLE_IOS_MACABI) ||  defined(X8664_APPLE_IOS) ||  defined(X8664_APPLE_MACOSX) ||  defined(X8664_APPLE_TVOS) ||  \
 defined(X8664_ELF) ||  defined(X8664_FUCHSIA) ||  defined(X8664_LINUX_ANDROID) ||  defined(X8664_PC_SOLARIS) ||  defined(X8664_RUMPRUN_NETBSD) ||  \
 defined(X8664_UNKNOWN_DRAGONFLY) ||  defined(X8664_UNKNOWN_FREEBSD) ||  defined(X8664_UNKNOWN_HAIKU) ||  defined(X8664_UNKNOWN_HERMIT) ||  \
 defined(X8664_UNKNOWN_L4RE_UCLIBC) ||  defined(X8664_UNKNOWN_LINUX_GNUX32) ||  defined(X8664_UNKNOWN_LINUX_GNU) ||  defined(X8664_UNKNOWN_LINUX_MUSL) ||  \
 defined(X8664_UNKNOWN_NETBSD) ||  defined(X8664_UNKNOWN_OPENBSD) ||  defined(X8664_UNKNOWN_REDOX) 
_Static_assert(sizeof(F) == 8, "record F wrong sizeof");
_Static_assert(_Alignof(F) == 2, "record F wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 10, "record F_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_alignment) == 2, "record F_alignment wrong alignment");
_Static_assert(sizeof(struct F_packed) == 8, "record F_packed wrong sizeof");
_Static_assert(_Alignof(struct F_packed) == 1, "record F_packed wrong alignment");
_Static_assert(sizeof(struct F_required_alignment) == 9, "record F_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "record F_required_alignment wrong alignment");
_Static_assert(sizeof(struct F_size) == 10, "record F_size wrong sizeof");
_Static_assert(_Alignof(struct F_size) == 1, "record F_size wrong alignment");
#endif
_Static_assert(sizeof(G) == 10, "record G wrong sizeof");
_Static_assert(_Alignof(G) == 2, "record G wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 12, "record G_alignment wrong sizeof");
_Static_assert(_Alignof(struct G_alignment) == 2, "record G_alignment wrong alignment");
_Static_assert(sizeof(struct G_packed) == 10, "record G_packed wrong sizeof");
_Static_assert(_Alignof(struct G_packed) == 1, "record G_packed wrong alignment");
_Static_assert(sizeof(struct G_required_alignment) == 11, "record G_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "record G_required_alignment wrong alignment");
_Static_assert(sizeof(struct G_size) == 12, "record G_size wrong sizeof");
_Static_assert(_Alignof(struct G_size) == 1, "record G_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(G,d) == 16, "field G.d wrong bit offset");
#endif
#elif defined(AARCH64_PC_WINDOWS_MSVC) ||  defined(I586_PC_WINDOWS_MSVC) ||  defined(I686_PC_WINDOWS_MSVC) ||  defined(I686_UNKNOWN_WINDOWS) ||  \
 defined(THUMBV7A_PC_WINDOWS_MSVC) ||  defined(X8664_PC_WINDOWS_MSVC) ||  defined(X8664_UNKNOWN_WINDOWS) 
_Static_assert(sizeof(F) == 8, "record F wrong sizeof");
_Static_assert(_Alignof(F) == 8, "record F wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 16, "record F_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_alignment) == 8, "record F_alignment wrong alignment");
_Static_assert(sizeof(struct F_packed) == 8, "record F_packed wrong sizeof");
_Static_assert(_Alignof(struct F_packed) == 1, "record F_packed wrong alignment");
_Static_assert(sizeof(struct F_required_alignment) == 9, "record F_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "record F_required_alignment wrong alignment");
_Static_assert(sizeof(struct F_size) == 10, "record F_size wrong sizeof");
_Static_assert(_Alignof(struct F_size) == 1, "record F_size wrong alignment");
#endif
_Static_assert(sizeof(G) == 16, "record G wrong sizeof");
_Static_assert(_Alignof(G) == 8, "record G wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 24, "record G_alignment wrong sizeof");
_Static_assert(_Alignof(struct G_alignment) == 8, "record G_alignment wrong alignment");
_Static_assert(sizeof(struct G_packed) == 16, "record G_packed wrong sizeof");
_Static_assert(_Alignof(struct G_packed) == 1, "record G_packed wrong alignment");
_Static_assert(sizeof(struct G_required_alignment) == 17, "record G_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "record G_required_alignment wrong alignment");
_Static_assert(sizeof(struct G_size) == 18, "record G_size wrong sizeof");
_Static_assert(_Alignof(struct G_size) == 1, "record G_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(G,d) == 64, "field G.d wrong bit offset");
#endif
#elif defined(ARMV7_APPLE_IOS) ||  defined(ARMV7S_APPLE_IOS) 
_Static_assert(sizeof(F) == 8, "record F wrong sizeof");
_Static_assert(_Alignof(F) == 2, "record F wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 10, "record F_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_alignment) == 2, "record F_alignment wrong alignment");
_Static_assert(sizeof(struct F_packed) == 8, "record F_packed wrong sizeof");
_Static_assert(_Alignof(struct F_packed) == 1, "record F_packed wrong alignment");
_Static_assert(sizeof(struct F_required_alignment) == 9, "record F_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "record F_required_alignment wrong alignment");
_Static_assert(sizeof(struct F_size) == 10, "record F_size wrong sizeof");
_Static_assert(_Alignof(struct F_size) == 1, "record F_size wrong alignment");
#endif
_Static_assert(sizeof(G) == 10, "record G wrong sizeof");
_Static_assert(_Alignof(G) == 1, "record G wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 11, "record G_alignment wrong sizeof");
_Static_assert(_Alignof(struct G_alignment) == 1, "record G_alignment wrong alignment");
_Static_assert(sizeof(struct G_packed) == 10, "record G_packed wrong sizeof");
_Static_assert(_Alignof(struct G_packed) == 1, "record G_packed wrong alignment");
_Static_assert(sizeof(struct G_required_alignment) == 11, "record G_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "record G_required_alignment wrong alignment");
_Static_assert(sizeof(struct G_size) == 12, "record G_size wrong sizeof");
_Static_assert(_Alignof(struct G_size) == 1, "record G_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(G,d) == 15, "field G.d wrong bit offset");
#endif
#elif defined(AVR_UNKNOWN_UNKNOWN) 
_Static_assert(sizeof(F) == 8, "record F wrong sizeof");
_Static_assert(_Alignof(F) == 2, "record F wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 10, "record F_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_alignment) == 2, "record F_alignment wrong alignment");
_Static_assert(sizeof(struct F_packed) == 8, "record F_packed wrong sizeof");
_Static_assert(_Alignof(struct F_packed) == 1, "record F_packed wrong alignment");
_Static_assert(sizeof(struct F_required_alignment) == 9, "record F_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "record F_required_alignment wrong alignment");
_Static_assert(sizeof(struct F_size) == 10, "record F_size wrong sizeof");
_Static_assert(_Alignof(struct F_size) == 1, "record F_size wrong alignment");
#endif
_Static_assert(sizeof(G) == 10, "record G wrong sizeof");
_Static_assert(_Alignof(G) == 1, "record G wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 11, "record G_alignment wrong sizeof");
_Static_assert(_Alignof(struct G_alignment) == 1, "record G_alignment wrong alignment");
_Static_assert(sizeof(struct G_packed) == 10, "record G_packed wrong sizeof");
_Static_assert(_Alignof(struct G_packed) == 1, "record G_packed wrong alignment");
_Static_assert(sizeof(struct G_required_alignment) == 11, "record G_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "record G_required_alignment wrong alignment");
_Static_assert(sizeof(struct G_size) == 12, "record G_size wrong sizeof");
_Static_assert(_Alignof(struct G_size) == 1, "record G_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(G,d) == 15, "field G.d wrong bit offset");
#endif
#elif defined(I386_APPLE_IOS) ||  defined(I586_UNKNOWN_LINUX_GNU) ||  defined(I586_UNKNOWN_LINUX_MUSL) ||  defined(I686_APPLE_MACOSX) ||  \
 defined(I686_LINUX_ANDROID) ||  defined(I686_UNKNOWN_FREEBSD) ||  defined(I686_UNKNOWN_HAIKU) ||  defined(I686_UNKNOWN_LINUX_GNU) ||  \
 defined(I686_UNKNOWN_LINUX_MUSL) ||  defined(I686_UNKNOWN_NETBSDELF) ||  defined(I686_UNKNOWN_OPENBSD) 
_Static_assert(sizeof(F) == 8, "record F wrong sizeof");
_Static_assert(_Alignof(F) == 2, "record F wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 10, "record F_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_alignment) == 2, "record F_alignment wrong alignment");
_Static_assert(sizeof(struct F_packed) == 8, "record F_packed wrong sizeof");
_Static_assert(_Alignof(struct F_packed) == 1, "record F_packed wrong alignment");
_Static_assert(sizeof(struct F_required_alignment) == 9, "record F_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "record F_required_alignment wrong alignment");
_Static_assert(sizeof(struct F_size) == 10, "record F_size wrong sizeof");
_Static_assert(_Alignof(struct F_size) == 1, "record F_size wrong alignment");
#endif
_Static_assert(sizeof(G) == 10, "record G wrong sizeof");
_Static_assert(_Alignof(G) == 2, "record G wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 12, "record G_alignment wrong sizeof");
_Static_assert(_Alignof(struct G_alignment) == 2, "record G_alignment wrong alignment");
_Static_assert(sizeof(struct G_packed) == 10, "record G_packed wrong sizeof");
_Static_assert(_Alignof(struct G_packed) == 1, "record G_packed wrong alignment");
_Static_assert(sizeof(struct G_required_alignment) == 11, "record G_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "record G_required_alignment wrong alignment");
_Static_assert(sizeof(struct G_size) == 12, "record G_size wrong sizeof");
_Static_assert(_Alignof(struct G_size) == 1, "record G_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(G,d) == 16, "field G.d wrong bit offset");
#endif
#elif defined(I686_PC_WINDOWS_GNU) ||  defined(X8664_PC_WINDOWS_GNU) 
_Static_assert(sizeof(F) == 8, "record F wrong sizeof");
_Static_assert(_Alignof(F) == 2, "record F wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 10, "record F_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_alignment) == 2, "record F_alignment wrong alignment");
_Static_assert(sizeof(struct F_packed) == 8, "record F_packed wrong sizeof");
_Static_assert(_Alignof(struct F_packed) == 1, "record F_packed wrong alignment");
_Static_assert(sizeof(struct F_required_alignment) == 9, "record F_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "record F_required_alignment wrong alignment");
_Static_assert(sizeof(struct F_size) == 10, "record F_size wrong sizeof");
_Static_assert(_Alignof(struct F_size) == 1, "record F_size wrong alignment");
#endif
_Static_assert(sizeof(G) == 16, "record G wrong sizeof");
_Static_assert(_Alignof(G) == 2, "record G wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 18, "record G_alignment wrong sizeof");
_Static_assert(_Alignof(struct G_alignment) == 2, "record G_alignment wrong alignment");
_Static_assert(sizeof(struct G_packed) == 16, "record G_packed wrong sizeof");
_Static_assert(_Alignof(struct G_packed) == 1, "record G_packed wrong alignment");
_Static_assert(sizeof(struct G_required_alignment) == 17, "record G_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "record G_required_alignment wrong alignment");
_Static_assert(sizeof(struct G_size) == 18, "record G_size wrong sizeof");
_Static_assert(_Alignof(struct G_size) == 1, "record G_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(G,d) == 64, "field G.d wrong bit offset");
#endif
#elif defined(MSP430_NONE_ELF) 
_Static_assert(sizeof(F) == 8, "record F wrong sizeof");
_Static_assert(_Alignof(F) == 2, "record F wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 10, "record F_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_alignment) == 2, "record F_alignment wrong alignment");
_Static_assert(sizeof(struct F_packed) == 8, "record F_packed wrong sizeof");
_Static_assert(_Alignof(struct F_packed) == 1, "record F_packed wrong alignment");
_Static_assert(sizeof(struct F_required_alignment) == 9, "record F_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "record F_required_alignment wrong alignment");
_Static_assert(sizeof(struct F_size) == 10, "record F_size wrong sizeof");
_Static_assert(_Alignof(struct F_size) == 1, "record F_size wrong alignment");
#endif
_Static_assert(sizeof(G) == 10, "record G wrong sizeof");
_Static_assert(_Alignof(G) == 2, "record G wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 12, "record G_alignment wrong sizeof");
_Static_assert(_Alignof(struct G_alignment) == 2, "record G_alignment wrong alignment");
_Static_assert(sizeof(struct G_packed) == 10, "record G_packed wrong sizeof");
_Static_assert(_Alignof(struct G_packed) == 1, "record G_packed wrong alignment");
_Static_assert(sizeof(struct G_required_alignment) == 11, "record G_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "record G_required_alignment wrong alignment");
_Static_assert(sizeof(struct G_size) == 12, "record G_size wrong sizeof");
_Static_assert(_Alignof(struct G_size) == 1, "record G_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(G,d) == 16, "field G.d wrong bit offset");
#endif
#endif
