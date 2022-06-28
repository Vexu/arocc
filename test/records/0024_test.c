// SPDX-License-Identifier: GPL-3.0-or-later

// This test file is auto-generated. do not edit.
// This file is a derivative work from the test files found// in this repo : https://github.com/mahkoh/repr-c
// and is under the same licence as the original work.

#ifdef MSVC
typedef long long unnamed_type_1[];
#else
typedef long long unnamed_type_1[0];
#endif
unnamed_type_1 var2;
struct unnamed_type_1_alignment {
#ifdef MSVC
    char a[_Alignof(unnamed_type_1)];
    char b;
#else
    char a;
    unnamed_type_1 b;
#endif
};
struct unnamed_type_1_alignment var3;
#pragma pack(1)
struct unnamed_type_1_packed {
    unnamed_type_1 a;
};
#pragma pack()
struct unnamed_type_1_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct unnamed_type_1_packed)];
    char b;
#else
    char a;
    struct unnamed_type_1_packed b;
#endif
};
struct unnamed_type_1_required_alignment var4;
struct unnamed_type_1_size {
    char a[sizeof(unnamed_type_1)+1];
    char b;
};
struct unnamed_type_1_size var5;

typedef union {
    unnamed_type_1 b;
} X;
X var6;
struct X_alignment {
#ifdef MSVC
    char a[_Alignof(X)];
    char b;
#else
    char a;
    X b;
#endif
};
struct X_alignment var7;
#pragma pack(1)
struct X_packed {
    X a;
};
#pragma pack()
struct X_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct X_packed)];
    char b;
#else
    char a;
    struct X_packed b;
#endif
};
struct X_required_alignment var8;
struct X_size {
    char a[sizeof(X)+1];
    char b;
};
struct X_size var9;

#ifdef MSVC
typedef char unnamed_type_10[];
#else
typedef char unnamed_type_10[0];
#endif
unnamed_type_10 var11;
struct unnamed_type_10_alignment {
#ifdef MSVC
    char a[_Alignof(unnamed_type_10)];
    char b;
#else
    char a;
    unnamed_type_10 b;
#endif
};
struct unnamed_type_10_alignment var12;
#pragma pack(1)
struct unnamed_type_10_packed {
    unnamed_type_10 a;
};
#pragma pack()
struct unnamed_type_10_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct unnamed_type_10_packed)];
    char b;
#else
    char a;
    struct unnamed_type_10_packed b;
#endif
};
struct unnamed_type_10_required_alignment var13;
struct unnamed_type_10_size {
    char a[sizeof(unnamed_type_10)+1];
    char b;
};
struct unnamed_type_10_size var14;

typedef union {
    long long:0;
    unnamed_type_10 b;
} Y;
Y var15;
struct Y_alignment {
#ifdef MSVC
    char a[_Alignof(Y)];
    char b;
#else
    char a;
    Y b;
#endif
};
struct Y_alignment var16;
#pragma pack(1)
struct Y_packed {
    Y a;
};
#pragma pack()
struct Y_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct Y_packed)];
    char b;
#else
    char a;
    struct Y_packed b;
#endif
};
struct Y_required_alignment var17;
struct Y_size {
    char a[sizeof(Y)+1];
    char b;
};
struct Y_size var18;

#if defined(AARCH64_APPLE_MACOSX) ||  defined(ARM64_APPLE_IOS) ||  defined(ARM64_APPLE_IOS_MACABI) ||  defined(ARM64_APPLE_TVOS) ||  \
 defined(HEXAGON_UNKNOWN_LINUX_MUSL) ||  defined(I686_PC_WINDOWS_GNU) ||  defined(MIPS64EL_UNKNOWN_LINUX_GNUABI64) ||  defined(MIPS64EL_UNKNOWN_LINUX_MUSL) ||  \
 defined(MIPS64_UNKNOWN_LINUX_GNUABI64) ||  defined(MIPS64_UNKNOWN_LINUX_MUSL) ||  defined(MIPSEL_SONY_PSP) ||  defined(MIPSEL_UNKNOWN_LINUX_GNU) ||  \
 defined(MIPSEL_UNKNOWN_LINUX_MUSL) ||  defined(MIPSEL_UNKNOWN_LINUX_UCLIBC) ||  defined(MIPSEL_UNKNOWN_NONE) ||  defined(MIPSISA32R6EL_UNKNOWN_LINUX_GNU) ||  \
 defined(MIPSISA32R6_UNKNOWN_LINUX_GNU) ||  defined(MIPSISA64R6EL_UNKNOWN_LINUX_GNUABI64) ||  defined(MIPSISA64R6_UNKNOWN_LINUX_GNUABI64) ||  \
 defined(MIPS_UNKNOWN_LINUX_GNU) ||  defined(MIPS_UNKNOWN_LINUX_MUSL) ||  defined(MIPS_UNKNOWN_LINUX_UCLIBC) ||  defined(POWERPC64LE_UNKNOWN_LINUX_GNU) ||  \
 defined(POWERPC64LE_UNKNOWN_LINUX_MUSL) ||  defined(POWERPC64_UNKNOWN_FREEBSD) ||  defined(POWERPC64_UNKNOWN_LINUX_GNU) ||  defined(POWERPC64_UNKNOWN_LINUX_MUSL) ||  \
 defined(POWERPC_UNKNOWN_LINUX_GNU) ||  defined(POWERPC_UNKNOWN_LINUX_GNUSPE) ||  defined(POWERPC_UNKNOWN_LINUX_MUSL) ||  defined(POWERPC_UNKNOWN_NETBSD) ||  \
 defined(RISCV32) ||  defined(RISCV32_UNKNOWN_LINUX_GNU) ||  defined(RISCV64) ||  defined(RISCV64_UNKNOWN_LINUX_GNU) ||  defined(S390X_UNKNOWN_LINUX_GNU) ||  \
 defined(SPARC64_UNKNOWN_LINUX_GNU) ||  defined(SPARC64_UNKNOWN_NETBSD) ||  defined(SPARC64_UNKNOWN_OPENBSD) ||  defined(SPARC_UNKNOWN_LINUX_GNU) ||  \
 defined(SPARCV9_SUN_SOLARIS) ||  defined(WASM32_UNKNOWN_EMSCRIPTEN) ||  defined(WASM32_UNKNOWN_UNKNOWN) ||  defined(WASM32_WASI) ||  \
 defined(X8664_APPLE_IOS_MACABI) ||  defined(X8664_APPLE_IOS) ||  defined(X8664_APPLE_MACOSX) ||  defined(X8664_APPLE_TVOS) ||  defined(X8664_ELF) ||  \
 defined(X8664_FUCHSIA) ||  defined(X8664_LINUX_ANDROID) ||  defined(X8664_PC_SOLARIS) ||  defined(X8664_PC_WINDOWS_GNU) ||  defined(X8664_RUMPRUN_NETBSD) ||  \
 defined(X8664_UNKNOWN_DRAGONFLY) ||  defined(X8664_UNKNOWN_FREEBSD) ||  defined(X8664_UNKNOWN_HAIKU) ||  defined(X8664_UNKNOWN_HERMIT) ||  \
 defined(X8664_UNKNOWN_L4RE_UCLIBC) ||  defined(X8664_UNKNOWN_LINUX_GNUX32) ||  defined(X8664_UNKNOWN_LINUX_GNU) ||  defined(X8664_UNKNOWN_LINUX_MUSL) ||  \
 defined(X8664_UNKNOWN_NETBSD) ||  defined(X8664_UNKNOWN_OPENBSD) ||  defined(X8664_UNKNOWN_REDOX) 
_Static_assert(sizeof(X) == 0, "record X wrong sizeof");
_Static_assert(_Alignof(X) == 8, "record X wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct X_alignment) == 8, "record X_alignment wrong sizeof");
_Static_assert(_Alignof(struct X_alignment) == 8, "record X_alignment wrong alignment");
_Static_assert(sizeof(struct X_packed) == 0, "record X_packed wrong sizeof");
_Static_assert(_Alignof(struct X_packed) == 1, "record X_packed wrong alignment");
_Static_assert(sizeof(struct X_required_alignment) == 1, "record X_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct X_required_alignment) == 1, "record X_required_alignment wrong alignment");
_Static_assert(sizeof(struct X_size) == 2, "record X_size wrong sizeof");
_Static_assert(_Alignof(struct X_size) == 1, "record X_size wrong alignment");
#endif
_Static_assert(sizeof(Y) == 0, "record Y wrong sizeof");
_Static_assert(_Alignof(Y) == 1, "record Y wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Y_alignment) == 1, "record Y_alignment wrong sizeof");
_Static_assert(_Alignof(struct Y_alignment) == 1, "record Y_alignment wrong alignment");
_Static_assert(sizeof(struct Y_packed) == 0, "record Y_packed wrong sizeof");
_Static_assert(_Alignof(struct Y_packed) == 1, "record Y_packed wrong alignment");
_Static_assert(sizeof(struct Y_required_alignment) == 1, "record Y_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct Y_required_alignment) == 1, "record Y_required_alignment wrong alignment");
_Static_assert(sizeof(struct Y_size) == 2, "record Y_size wrong sizeof");
_Static_assert(_Alignof(struct Y_size) == 1, "record Y_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(Y,b) == 0, "field Y.b wrong bit offset");
#endif
#elif defined(AARCH64_FUCHSIA) ||  defined(AARCH64_LINUX_ANDROID) ||  defined(AARCH64_UNKNOWN_FREEBSD) ||  defined(AARCH64_UNKNOWN_HERMIT) ||  \
 defined(AARCH64_UNKNOWN_LINUX_GNU) ||  defined(AARCH64_UNKNOWN_LINUX_MUSL) ||  defined(AARCH64_UNKNOWN_NETBSD) ||  defined(AARCH64_UNKNOWN_NONE) ||  \
 defined(AARCH64_UNKNOWN_OPENBSD) ||  defined(AARCH64_UNKNOWN_REDOX) ||  defined(ARMEBV7R_UNKNOWN_NONE_EABI) ||  defined(ARMEBV7R_UNKNOWN_NONE_EABIHF) ||  \
 defined(ARM_LINUX_ANDROIDEABI) ||  defined(ARM_UNKNOWN_LINUX_GNUEABI) ||  defined(ARM_UNKNOWN_LINUX_GNUEABIHF) ||  defined(ARMV4T_UNKNOWN_LINUX_GNUEABI) ||  \
 defined(ARMV5TE_UNKNOWN_LINUX_GNUEABI) ||  defined(ARMV5TE_UNKNOWN_LINUX_UCLIBCGNUEABI) ||  defined(ARMV6_UNKNOWN_FREEBSD_GNUEABIHF) ||  \
 defined(ARMV6_UNKNOWN_NETBSDELF_EABIHF) ||  defined(ARMV7A_NONE_EABI) ||  defined(ARMV7A_NONE_EABIHF) ||  defined(ARMV7_NONE_LINUX_ANDROID) ||  \
 defined(ARMV7R_UNKNOWN_NONE_EABI) ||  defined(ARMV7R_UNKNOWN_NONE_EABIHF) ||  defined(ARMV7_UNKNOWN_FREEBSD_GNUEABIHF) ||  defined(ARMV7_UNKNOWN_LINUX_GNUEABI) ||  \
 defined(ARMV7_UNKNOWN_LINUX_GNUEABIHF) ||  defined(ARMV7_UNKNOWN_NETBSDELF_EABIHF) ||  defined(THUMBV4T_NONE_EABI) ||  defined(THUMBV6M_NONE_EABI) ||  \
 defined(THUMBV7EM_NONE_EABIHF) ||  defined(THUMBV7EM_NONE_EABI) ||  defined(THUMBV7M_NONE_EABI) ||  defined(THUMBV8MBASE_NONE_EABI) ||  \
 defined(THUMBV8MMAIN_NONE_EABIHF) ||  defined(THUMBV8MMAIN_NONE_EABI) 
_Static_assert(sizeof(X) == 0, "record X wrong sizeof");
_Static_assert(_Alignof(X) == 8, "record X wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct X_alignment) == 8, "record X_alignment wrong sizeof");
_Static_assert(_Alignof(struct X_alignment) == 8, "record X_alignment wrong alignment");
_Static_assert(sizeof(struct X_packed) == 0, "record X_packed wrong sizeof");
_Static_assert(_Alignof(struct X_packed) == 1, "record X_packed wrong alignment");
_Static_assert(sizeof(struct X_required_alignment) == 1, "record X_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct X_required_alignment) == 1, "record X_required_alignment wrong alignment");
_Static_assert(sizeof(struct X_size) == 2, "record X_size wrong sizeof");
_Static_assert(_Alignof(struct X_size) == 1, "record X_size wrong alignment");
#endif
_Static_assert(sizeof(Y) == 0, "record Y wrong sizeof");
_Static_assert(_Alignof(Y) == 8, "record Y wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Y_alignment) == 8, "record Y_alignment wrong sizeof");
_Static_assert(_Alignof(struct Y_alignment) == 8, "record Y_alignment wrong alignment");
_Static_assert(sizeof(struct Y_packed) == 0, "record Y_packed wrong sizeof");
_Static_assert(_Alignof(struct Y_packed) == 1, "record Y_packed wrong alignment");
_Static_assert(sizeof(struct Y_required_alignment) == 1, "record Y_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct Y_required_alignment) == 1, "record Y_required_alignment wrong alignment");
_Static_assert(sizeof(struct Y_size) == 2, "record Y_size wrong sizeof");
_Static_assert(_Alignof(struct Y_size) == 1, "record Y_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(Y,b) == 0, "field Y.b wrong bit offset");
#endif
#elif defined(AARCH64_PC_WINDOWS_MSVC) ||  defined(I586_PC_WINDOWS_MSVC) ||  defined(I686_PC_WINDOWS_MSVC) ||  defined(I686_UNKNOWN_WINDOWS) ||  \
 defined(THUMBV7A_PC_WINDOWS_MSVC) ||  defined(X8664_PC_WINDOWS_MSVC) ||  defined(X8664_UNKNOWN_WINDOWS) 
_Static_assert(sizeof(X) == 8, "record X wrong sizeof");
_Static_assert(_Alignof(X) == 8, "record X wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct X_alignment) == 16, "record X_alignment wrong sizeof");
_Static_assert(_Alignof(struct X_alignment) == 8, "record X_alignment wrong alignment");
_Static_assert(sizeof(struct X_packed) == 8, "record X_packed wrong sizeof");
_Static_assert(_Alignof(struct X_packed) == 1, "record X_packed wrong alignment");
_Static_assert(sizeof(struct X_required_alignment) == 9, "record X_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct X_required_alignment) == 1, "record X_required_alignment wrong alignment");
_Static_assert(sizeof(struct X_size) == 10, "record X_size wrong sizeof");
_Static_assert(_Alignof(struct X_size) == 1, "record X_size wrong alignment");
#endif
_Static_assert(sizeof(Y) == 1, "record Y wrong sizeof");
_Static_assert(_Alignof(Y) == 1, "record Y wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Y_alignment) == 2, "record Y_alignment wrong sizeof");
_Static_assert(_Alignof(struct Y_alignment) == 1, "record Y_alignment wrong alignment");
_Static_assert(sizeof(struct Y_packed) == 1, "record Y_packed wrong sizeof");
_Static_assert(_Alignof(struct Y_packed) == 1, "record Y_packed wrong alignment");
_Static_assert(sizeof(struct Y_required_alignment) == 2, "record Y_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct Y_required_alignment) == 1, "record Y_required_alignment wrong alignment");
_Static_assert(sizeof(struct Y_size) == 3, "record Y_size wrong sizeof");
_Static_assert(_Alignof(struct Y_size) == 1, "record Y_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(Y,b) == 0, "field Y.b wrong bit offset");
#endif
#elif defined(ARMV7_APPLE_IOS) ||  defined(ARMV7S_APPLE_IOS) 
_Static_assert(sizeof(X) == 0, "record X wrong sizeof");
_Static_assert(_Alignof(X) == 4, "record X wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct X_alignment) == 4, "record X_alignment wrong sizeof");
_Static_assert(_Alignof(struct X_alignment) == 4, "record X_alignment wrong alignment");
_Static_assert(sizeof(struct X_packed) == 0, "record X_packed wrong sizeof");
_Static_assert(_Alignof(struct X_packed) == 1, "record X_packed wrong alignment");
_Static_assert(sizeof(struct X_required_alignment) == 1, "record X_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct X_required_alignment) == 1, "record X_required_alignment wrong alignment");
_Static_assert(sizeof(struct X_size) == 2, "record X_size wrong sizeof");
_Static_assert(_Alignof(struct X_size) == 1, "record X_size wrong alignment");
#endif
_Static_assert(sizeof(Y) == 0, "record Y wrong sizeof");
_Static_assert(_Alignof(Y) == 4, "record Y wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Y_alignment) == 4, "record Y_alignment wrong sizeof");
_Static_assert(_Alignof(struct Y_alignment) == 4, "record Y_alignment wrong alignment");
_Static_assert(sizeof(struct Y_packed) == 0, "record Y_packed wrong sizeof");
_Static_assert(_Alignof(struct Y_packed) == 1, "record Y_packed wrong alignment");
_Static_assert(sizeof(struct Y_required_alignment) == 1, "record Y_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct Y_required_alignment) == 1, "record Y_required_alignment wrong alignment");
_Static_assert(sizeof(struct Y_size) == 2, "record Y_size wrong sizeof");
_Static_assert(_Alignof(struct Y_size) == 1, "record Y_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(Y,b) == 0, "field Y.b wrong bit offset");
#endif
#elif defined(AVR_UNKNOWN_UNKNOWN) 
_Static_assert(sizeof(X) == 0, "record X wrong sizeof");
_Static_assert(_Alignof(X) == 1, "record X wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct X_alignment) == 1, "record X_alignment wrong sizeof");
_Static_assert(_Alignof(struct X_alignment) == 1, "record X_alignment wrong alignment");
_Static_assert(sizeof(struct X_packed) == 0, "record X_packed wrong sizeof");
_Static_assert(_Alignof(struct X_packed) == 1, "record X_packed wrong alignment");
_Static_assert(sizeof(struct X_required_alignment) == 1, "record X_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct X_required_alignment) == 1, "record X_required_alignment wrong alignment");
_Static_assert(sizeof(struct X_size) == 2, "record X_size wrong sizeof");
_Static_assert(_Alignof(struct X_size) == 1, "record X_size wrong alignment");
#endif
_Static_assert(sizeof(Y) == 0, "record Y wrong sizeof");
_Static_assert(_Alignof(Y) == 1, "record Y wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Y_alignment) == 1, "record Y_alignment wrong sizeof");
_Static_assert(_Alignof(struct Y_alignment) == 1, "record Y_alignment wrong alignment");
_Static_assert(sizeof(struct Y_packed) == 0, "record Y_packed wrong sizeof");
_Static_assert(_Alignof(struct Y_packed) == 1, "record Y_packed wrong alignment");
_Static_assert(sizeof(struct Y_required_alignment) == 1, "record Y_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct Y_required_alignment) == 1, "record Y_required_alignment wrong alignment");
_Static_assert(sizeof(struct Y_size) == 2, "record Y_size wrong sizeof");
_Static_assert(_Alignof(struct Y_size) == 1, "record Y_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(Y,b) == 0, "field Y.b wrong bit offset");
#endif
#elif defined(I386_APPLE_IOS) ||  defined(I586_UNKNOWN_LINUX_GNU) ||  defined(I586_UNKNOWN_LINUX_MUSL) ||  defined(I686_APPLE_MACOSX) ||  \
 defined(I686_LINUX_ANDROID) ||  defined(I686_UNKNOWN_FREEBSD) ||  defined(I686_UNKNOWN_HAIKU) ||  defined(I686_UNKNOWN_LINUX_GNU) ||  \
 defined(I686_UNKNOWN_LINUX_MUSL) ||  defined(I686_UNKNOWN_NETBSDELF) ||  defined(I686_UNKNOWN_OPENBSD) 
_Static_assert(sizeof(X) == 0, "record X wrong sizeof");
_Static_assert(_Alignof(X) == 4, "record X wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct X_alignment) == 4, "record X_alignment wrong sizeof");
_Static_assert(_Alignof(struct X_alignment) == 4, "record X_alignment wrong alignment");
_Static_assert(sizeof(struct X_packed) == 0, "record X_packed wrong sizeof");
_Static_assert(_Alignof(struct X_packed) == 1, "record X_packed wrong alignment");
_Static_assert(sizeof(struct X_required_alignment) == 1, "record X_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct X_required_alignment) == 1, "record X_required_alignment wrong alignment");
_Static_assert(sizeof(struct X_size) == 2, "record X_size wrong sizeof");
_Static_assert(_Alignof(struct X_size) == 1, "record X_size wrong alignment");
#endif
_Static_assert(sizeof(Y) == 0, "record Y wrong sizeof");
_Static_assert(_Alignof(Y) == 1, "record Y wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Y_alignment) == 1, "record Y_alignment wrong sizeof");
_Static_assert(_Alignof(struct Y_alignment) == 1, "record Y_alignment wrong alignment");
_Static_assert(sizeof(struct Y_packed) == 0, "record Y_packed wrong sizeof");
_Static_assert(_Alignof(struct Y_packed) == 1, "record Y_packed wrong alignment");
_Static_assert(sizeof(struct Y_required_alignment) == 1, "record Y_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct Y_required_alignment) == 1, "record Y_required_alignment wrong alignment");
_Static_assert(sizeof(struct Y_size) == 2, "record Y_size wrong sizeof");
_Static_assert(_Alignof(struct Y_size) == 1, "record Y_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(Y,b) == 0, "field Y.b wrong bit offset");
#endif
#elif defined(MSP430_NONE_ELF) 
_Static_assert(sizeof(X) == 0, "record X wrong sizeof");
_Static_assert(_Alignof(X) == 2, "record X wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct X_alignment) == 2, "record X_alignment wrong sizeof");
_Static_assert(_Alignof(struct X_alignment) == 2, "record X_alignment wrong alignment");
_Static_assert(sizeof(struct X_packed) == 0, "record X_packed wrong sizeof");
_Static_assert(_Alignof(struct X_packed) == 1, "record X_packed wrong alignment");
_Static_assert(sizeof(struct X_required_alignment) == 1, "record X_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct X_required_alignment) == 1, "record X_required_alignment wrong alignment");
_Static_assert(sizeof(struct X_size) == 2, "record X_size wrong sizeof");
_Static_assert(_Alignof(struct X_size) == 1, "record X_size wrong alignment");
#endif
_Static_assert(sizeof(Y) == 0, "record Y wrong sizeof");
_Static_assert(_Alignof(Y) == 1, "record Y wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Y_alignment) == 1, "record Y_alignment wrong sizeof");
_Static_assert(_Alignof(struct Y_alignment) == 1, "record Y_alignment wrong alignment");
_Static_assert(sizeof(struct Y_packed) == 0, "record Y_packed wrong sizeof");
_Static_assert(_Alignof(struct Y_packed) == 1, "record Y_packed wrong alignment");
_Static_assert(sizeof(struct Y_required_alignment) == 1, "record Y_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct Y_required_alignment) == 1, "record Y_required_alignment wrong alignment");
_Static_assert(sizeof(struct Y_size) == 2, "record Y_size wrong sizeof");
_Static_assert(_Alignof(struct Y_size) == 1, "record Y_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(Y,b) == 0, "field Y.b wrong bit offset");
#endif
#endif
