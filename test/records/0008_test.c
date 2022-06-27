// SPDX-License-Identifier: GPL-3.0-or-later

// This test file is auto-generated. do not edit.
// This file is a derivative work from the test files found// in this repo : https://github.com/mahkoh/repr-c
// and is under the same licence as the original work.

typedef int unnamed_type_1[3];
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

#ifdef MSVC
__declspec(align(8)) typedef unnamed_type_1 Int;
#else
typedef unnamed_type_1 Int __attribute__((aligned(8)));
#endif
Int var6;
struct Int_alignment {
#ifdef MSVC
    char a[_Alignof(Int)];
    char b;
#else
    char a;
    Int b;
#endif
};
struct Int_alignment var7;
#pragma pack(1)
struct Int_packed {
    Int a;
};
#pragma pack()
struct Int_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct Int_packed)];
    char b;
#else
    char a;
    struct Int_packed b;
#endif
};
struct Int_required_alignment var8;
struct Int_size {
    char a[sizeof(Int)+1];
    char b;
};
struct Int_size var9;

typedef Int unnamed_type_10[3];
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

typedef unnamed_type_10 Y;
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

typedef struct {
    Y y;
    int i;
} Z;
Z var19;
struct Z_alignment {
#ifdef MSVC
    char a[_Alignof(Z)];
    char b;
#else
    char a;
    Z b;
#endif
};
struct Z_alignment var20;
#pragma pack(1)
struct Z_packed {
    Z a;
};
#pragma pack()
struct Z_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct Z_packed)];
    char b;
#else
    char a;
    struct Z_packed b;
#endif
};
struct Z_required_alignment var21;
struct Z_size {
    char a[sizeof(Z)+1];
    char b;
};
struct Z_size var22;

#if defined(AARCH64_APPLE_MACOSX) ||  defined(AARCH64_FUCHSIA) ||  defined(AARCH64_LINUX_ANDROID) ||  defined(AARCH64_UNKNOWN_FREEBSD) ||  \
 defined(AARCH64_UNKNOWN_HERMIT) ||  defined(AARCH64_UNKNOWN_LINUX_GNU) ||  defined(AARCH64_UNKNOWN_LINUX_MUSL) ||  defined(AARCH64_UNKNOWN_NETBSD) ||  \
 defined(AARCH64_UNKNOWN_NONE) ||  defined(AARCH64_UNKNOWN_OPENBSD) ||  defined(AARCH64_UNKNOWN_REDOX) ||  defined(ARM64_APPLE_IOS) ||  \
 defined(ARM64_APPLE_IOS_MACABI) ||  defined(ARM64_APPLE_TVOS) ||  defined(ARMEBV7R_UNKNOWN_NONE_EABI) ||  defined(ARMEBV7R_UNKNOWN_NONE_EABIHF) ||  \
 defined(ARM_LINUX_ANDROIDEABI) ||  defined(ARM_UNKNOWN_LINUX_GNUEABI) ||  defined(ARM_UNKNOWN_LINUX_GNUEABIHF) ||  defined(ARMV4T_UNKNOWN_LINUX_GNUEABI) ||  \
 defined(ARMV5TE_UNKNOWN_LINUX_GNUEABI) ||  defined(ARMV5TE_UNKNOWN_LINUX_UCLIBCGNUEABI) ||  defined(ARMV6_UNKNOWN_FREEBSD_GNUEABIHF) ||  \
 defined(ARMV6_UNKNOWN_NETBSDELF_EABIHF) ||  defined(ARMV7A_NONE_EABI) ||  defined(ARMV7A_NONE_EABIHF) ||  defined(ARMV7_APPLE_IOS) ||  \
 defined(ARMV7_NONE_LINUX_ANDROID) ||  defined(ARMV7R_UNKNOWN_NONE_EABI) ||  defined(ARMV7R_UNKNOWN_NONE_EABIHF) ||  defined(ARMV7S_APPLE_IOS) ||  \
 defined(ARMV7_UNKNOWN_FREEBSD_GNUEABIHF) ||  defined(ARMV7_UNKNOWN_LINUX_GNUEABI) ||  defined(ARMV7_UNKNOWN_LINUX_GNUEABIHF) ||  \
 defined(ARMV7_UNKNOWN_NETBSDELF_EABIHF) ||  defined(HEXAGON_UNKNOWN_LINUX_MUSL) ||  defined(I386_APPLE_IOS) ||  defined(I586_UNKNOWN_LINUX_GNU) ||  \
 defined(I586_UNKNOWN_LINUX_MUSL) ||  defined(I686_APPLE_MACOSX) ||  defined(I686_LINUX_ANDROID) ||  defined(I686_PC_WINDOWS_GNU) ||  \
 defined(I686_UNKNOWN_FREEBSD) ||  defined(I686_UNKNOWN_HAIKU) ||  defined(I686_UNKNOWN_LINUX_GNU) ||  defined(I686_UNKNOWN_LINUX_MUSL) ||  \
 defined(I686_UNKNOWN_NETBSDELF) ||  defined(I686_UNKNOWN_OPENBSD) ||  defined(MIPS64EL_UNKNOWN_LINUX_GNUABI64) ||  defined(MIPS64EL_UNKNOWN_LINUX_MUSL) ||  \
 defined(MIPS64_UNKNOWN_LINUX_GNUABI64) ||  defined(MIPS64_UNKNOWN_LINUX_MUSL) ||  defined(MIPSEL_SONY_PSP) ||  defined(MIPSEL_UNKNOWN_LINUX_GNU) ||  \
 defined(MIPSEL_UNKNOWN_LINUX_MUSL) ||  defined(MIPSEL_UNKNOWN_LINUX_UCLIBC) ||  defined(MIPSEL_UNKNOWN_NONE) ||  defined(MIPSISA32R6EL_UNKNOWN_LINUX_GNU) ||  \
 defined(MIPSISA32R6_UNKNOWN_LINUX_GNU) ||  defined(MIPSISA64R6EL_UNKNOWN_LINUX_GNUABI64) ||  defined(MIPSISA64R6_UNKNOWN_LINUX_GNUABI64) ||  \
 defined(MIPS_UNKNOWN_LINUX_GNU) ||  defined(MIPS_UNKNOWN_LINUX_MUSL) ||  defined(MIPS_UNKNOWN_LINUX_UCLIBC) ||  defined(POWERPC64LE_UNKNOWN_LINUX_GNU) ||  \
 defined(POWERPC64LE_UNKNOWN_LINUX_MUSL) ||  defined(POWERPC64_UNKNOWN_FREEBSD) ||  defined(POWERPC64_UNKNOWN_LINUX_GNU) ||  defined(POWERPC64_UNKNOWN_LINUX_MUSL) ||  \
 defined(POWERPC_UNKNOWN_LINUX_GNU) ||  defined(POWERPC_UNKNOWN_LINUX_GNUSPE) ||  defined(POWERPC_UNKNOWN_LINUX_MUSL) ||  defined(POWERPC_UNKNOWN_NETBSD) ||  \
 defined(RISCV32) ||  defined(RISCV32_UNKNOWN_LINUX_GNU) ||  defined(RISCV64) ||  defined(RISCV64_UNKNOWN_LINUX_GNU) ||  defined(S390X_UNKNOWN_LINUX_GNU) ||  \
 defined(SPARC64_UNKNOWN_LINUX_GNU) ||  defined(SPARC64_UNKNOWN_NETBSD) ||  defined(SPARC64_UNKNOWN_OPENBSD) ||  defined(SPARC_UNKNOWN_LINUX_GNU) ||  \
 defined(SPARCV9_SUN_SOLARIS) ||  defined(THUMBV4T_NONE_EABI) ||  defined(THUMBV6M_NONE_EABI) ||  defined(THUMBV7EM_NONE_EABIHF) ||  \
 defined(THUMBV7EM_NONE_EABI) ||  defined(THUMBV7M_NONE_EABI) ||  defined(THUMBV8MBASE_NONE_EABI) ||  defined(THUMBV8MMAIN_NONE_EABIHF) ||  \
 defined(THUMBV8MMAIN_NONE_EABI) ||  defined(WASM32_UNKNOWN_EMSCRIPTEN) ||  defined(WASM32_UNKNOWN_UNKNOWN) ||  defined(WASM32_WASI) ||  \
 defined(X8664_APPLE_IOS_MACABI) ||  defined(X8664_APPLE_IOS) ||  defined(X8664_APPLE_MACOSX) ||  defined(X8664_APPLE_TVOS) ||  defined(X8664_ELF) ||  \
 defined(X8664_FUCHSIA) ||  defined(X8664_LINUX_ANDROID) ||  defined(X8664_PC_SOLARIS) ||  defined(X8664_PC_WINDOWS_GNU) ||  defined(X8664_RUMPRUN_NETBSD) ||  \
 defined(X8664_UNKNOWN_DRAGONFLY) ||  defined(X8664_UNKNOWN_FREEBSD) ||  defined(X8664_UNKNOWN_HAIKU) ||  defined(X8664_UNKNOWN_HERMIT) ||  \
 defined(X8664_UNKNOWN_L4RE_UCLIBC) ||  defined(X8664_UNKNOWN_LINUX_GNUX32) ||  defined(X8664_UNKNOWN_LINUX_GNU) ||  defined(X8664_UNKNOWN_LINUX_MUSL) ||  \
 defined(X8664_UNKNOWN_NETBSD) ||  defined(X8664_UNKNOWN_OPENBSD) ||  defined(X8664_UNKNOWN_REDOX) 
_Static_assert(sizeof(Int) == 12, "record Int wrong sizeof");
_Static_assert(_Alignof(Int) == 8, "record Int wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Int_alignment) == 20, "record Int wrong sizeof");
_Static_assert(_Alignof(struct Int_alignment) == 8, "record Int wrong alignment");
_Static_assert(sizeof(struct Int_packed) == 12, "record Int wrong sizeof");
_Static_assert(_Alignof(struct Int_packed) == 1, "record Int wrong alignment");
_Static_assert(sizeof(struct Int_required_alignment) == 13, "record Int wrong sizeof");
_Static_assert(_Alignof(struct Int_required_alignment) == 1, "record Int wrong alignment");
_Static_assert(sizeof(struct Int_size) == 14, "record Int wrong sizeof");
_Static_assert(_Alignof(struct Int_size) == 1, "record Int wrong alignment");
#endif
_Static_assert(sizeof(Y) == 40, "record Y wrong sizeof");
_Static_assert(_Alignof(Y) == 8, "record Y wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Y_alignment) == 48, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_alignment) == 8, "record Y wrong alignment");
_Static_assert(sizeof(struct Y_packed) == 40, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_packed) == 1, "record Y wrong alignment");
_Static_assert(sizeof(struct Y_required_alignment) == 41, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_required_alignment) == 1, "record Y wrong alignment");
_Static_assert(sizeof(struct Y_size) == 42, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_size) == 1, "record Y wrong alignment");
#endif
_Static_assert(sizeof(Z) == 48, "record Z wrong sizeof");
_Static_assert(_Alignof(Z) == 8, "record Z wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Z_alignment) == 56, "record Z wrong sizeof");
_Static_assert(_Alignof(struct Z_alignment) == 8, "record Z wrong alignment");
_Static_assert(sizeof(struct Z_packed) == 48, "record Z wrong sizeof");
_Static_assert(_Alignof(struct Z_packed) == 1, "record Z wrong alignment");
_Static_assert(sizeof(struct Z_required_alignment) == 49, "record Z wrong sizeof");
_Static_assert(_Alignof(struct Z_required_alignment) == 1, "record Z wrong alignment");
_Static_assert(sizeof(struct Z_size) == 50, "record Z wrong sizeof");
_Static_assert(_Alignof(struct Z_size) == 1, "record Z wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(Z,i) == 320, "field Z.i wrong bit offset");
#endif
#elif defined(AARCH64_PC_WINDOWS_MSVC) ||  defined(I586_PC_WINDOWS_MSVC) ||  defined(I686_PC_WINDOWS_MSVC) ||  defined(I686_UNKNOWN_WINDOWS) ||  \
 defined(THUMBV7A_PC_WINDOWS_MSVC) ||  defined(X8664_PC_WINDOWS_MSVC) ||  defined(X8664_UNKNOWN_WINDOWS) 
_Static_assert(sizeof(Int) == 12, "record Int wrong sizeof");
_Static_assert(_Alignof(Int) == 8, "record Int wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Int_alignment) == 20, "record Int wrong sizeof");
_Static_assert(_Alignof(struct Int_alignment) == 8, "record Int wrong alignment");
_Static_assert(sizeof(struct Int_packed) == 12, "record Int wrong sizeof");
_Static_assert(_Alignof(struct Int_packed) == 1, "record Int wrong alignment");
_Static_assert(sizeof(struct Int_required_alignment) == 13, "record Int wrong sizeof");
_Static_assert(_Alignof(struct Int_required_alignment) == 1, "record Int wrong alignment");
_Static_assert(sizeof(struct Int_size) == 14, "record Int wrong sizeof");
_Static_assert(_Alignof(struct Int_size) == 1, "record Int wrong alignment");
#endif
_Static_assert(sizeof(Y) == 36, "record Y wrong sizeof");
_Static_assert(_Alignof(Y) == 8, "record Y wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Y_alignment) == 44, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_alignment) == 8, "record Y wrong alignment");
_Static_assert(sizeof(struct Y_packed) == 36, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_packed) == 1, "record Y wrong alignment");
_Static_assert(sizeof(struct Y_required_alignment) == 37, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_required_alignment) == 1, "record Y wrong alignment");
_Static_assert(sizeof(struct Y_size) == 38, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_size) == 1, "record Y wrong alignment");
#endif
_Static_assert(sizeof(Z) == 40, "record Z wrong sizeof");
_Static_assert(_Alignof(Z) == 8, "record Z wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Z_alignment) == 48, "record Z wrong sizeof");
_Static_assert(_Alignof(struct Z_alignment) == 8, "record Z wrong alignment");
_Static_assert(sizeof(struct Z_packed) == 40, "record Z wrong sizeof");
_Static_assert(_Alignof(struct Z_packed) == 1, "record Z wrong alignment");
_Static_assert(sizeof(struct Z_required_alignment) == 41, "record Z wrong sizeof");
_Static_assert(_Alignof(struct Z_required_alignment) == 1, "record Z wrong alignment");
_Static_assert(sizeof(struct Z_size) == 42, "record Z wrong sizeof");
_Static_assert(_Alignof(struct Z_size) == 1, "record Z wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(Z,i) == 288, "field Z.i wrong bit offset");
#endif
#elif defined(MSP430_NONE_ELF) 
_Static_assert(sizeof(Int) == 6, "record Int wrong sizeof");
_Static_assert(_Alignof(Int) == 8, "record Int wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Int_alignment) == 16, "record Int wrong sizeof");
_Static_assert(_Alignof(struct Int_alignment) == 8, "record Int wrong alignment");
_Static_assert(sizeof(struct Int_packed) == 6, "record Int wrong sizeof");
_Static_assert(_Alignof(struct Int_packed) == 1, "record Int wrong alignment");
_Static_assert(sizeof(struct Int_required_alignment) == 7, "record Int wrong sizeof");
_Static_assert(_Alignof(struct Int_required_alignment) == 1, "record Int wrong alignment");
_Static_assert(sizeof(struct Int_size) == 8, "record Int wrong sizeof");
_Static_assert(_Alignof(struct Int_size) == 1, "record Int wrong alignment");
#endif
_Static_assert(sizeof(Y) == 24, "record Y wrong sizeof");
_Static_assert(_Alignof(Y) == 8, "record Y wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Y_alignment) == 32, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_alignment) == 8, "record Y wrong alignment");
_Static_assert(sizeof(struct Y_packed) == 24, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_packed) == 1, "record Y wrong alignment");
_Static_assert(sizeof(struct Y_required_alignment) == 25, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_required_alignment) == 1, "record Y wrong alignment");
_Static_assert(sizeof(struct Y_size) == 26, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_size) == 1, "record Y wrong alignment");
#endif
_Static_assert(sizeof(Z) == 32, "record Z wrong sizeof");
_Static_assert(_Alignof(Z) == 8, "record Z wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Z_alignment) == 40, "record Z wrong sizeof");
_Static_assert(_Alignof(struct Z_alignment) == 8, "record Z wrong alignment");
_Static_assert(sizeof(struct Z_packed) == 32, "record Z wrong sizeof");
_Static_assert(_Alignof(struct Z_packed) == 1, "record Z wrong alignment");
_Static_assert(sizeof(struct Z_required_alignment) == 33, "record Z wrong sizeof");
_Static_assert(_Alignof(struct Z_required_alignment) == 1, "record Z wrong alignment");
_Static_assert(sizeof(struct Z_size) == 34, "record Z wrong sizeof");
_Static_assert(_Alignof(struct Z_size) == 1, "record Z wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(Z,i) == 192, "field Z.i wrong bit offset");
#endif
#endif
