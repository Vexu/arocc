// SPDX-License-Identifier: GPL-3.0-or-later

// This test file is auto-generated. do not edit.
// This file is a derivative work from the test files found// in this repo : https://github.com/mahkoh/repr-c
// and is under the same licence as the original work.

typedef char unnamed_type_1[3];
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
__declspec(align(2)) typedef unnamed_type_1 A;
#else
typedef unnamed_type_1 A __attribute__((aligned(2)));
#endif
A var6;
struct A_alignment {
#ifdef MSVC
    char a[_Alignof(A)];
    char b;
#else
    char a;
    A b;
#endif
};
struct A_alignment var7;
#pragma pack(1)
struct A_packed {
    A a;
};
#pragma pack()
struct A_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct A_packed)];
    char b;
#else
    char a;
    struct A_packed b;
#endif
};
struct A_required_alignment var8;
struct A_size {
    char a[sizeof(A)+1];
    char b;
};
struct A_size var9;

typedef A B[3];
B var10;
struct B_alignment {
#ifdef MSVC
    char a[_Alignof(B)];
    char b;
#else
    char a;
    B b;
#endif
};
struct B_alignment var11;
#pragma pack(1)
struct B_packed {
    B a;
};
#pragma pack()
struct B_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct B_packed)];
    char b;
#else
    char a;
    struct B_packed b;
#endif
};
struct B_required_alignment var12;
struct B_size {
    char a[sizeof(B)+1];
    char b;
};
struct B_size var13;

typedef char C[3];
C var14;
struct C_alignment {
#ifdef MSVC
    char a[_Alignof(C)];
    char b;
#else
    char a;
    C b;
#endif
};
struct C_alignment var15;
#pragma pack(1)
struct C_packed {
    C a;
};
#pragma pack()
struct C_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct C_packed)];
    char b;
#else
    char a;
    struct C_packed b;
#endif
};
struct C_required_alignment var16;
struct C_size {
    char a[sizeof(C)+1];
    char b;
};
struct C_size var17;

#ifdef MSVC
typedef B D[];
#else
typedef B D[0];
#endif
D var18;
struct D_alignment {
#ifdef MSVC
    char a[_Alignof(D)];
    char b;
#else
    char a;
    D b;
#endif
};
struct D_alignment var19;
#pragma pack(1)
struct D_packed {
    D a;
};
#pragma pack()
struct D_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct D_packed)];
    char b;
#else
    char a;
    struct D_packed b;
#endif
};
struct D_required_alignment var20;
struct D_size {
    char a[sizeof(D)+1];
    char b;
};
struct D_size var21;

typedef struct {
    char c;
    D d;
} E;
E var22;
struct E_alignment {
#ifdef MSVC
    char a[_Alignof(E)];
    char b;
#else
    char a;
    E b;
#endif
};
struct E_alignment var23;
#pragma pack(1)
struct E_packed {
    E a;
};
#pragma pack()
struct E_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct E_packed)];
    char b;
#else
    char a;
    struct E_packed b;
#endif
};
struct E_required_alignment var24;
struct E_size {
    char a[sizeof(E)+1];
    char b;
};
struct E_size var25;

#ifdef MSVC
typedef B unnamed_type_26[];
#else
typedef B unnamed_type_26[0];
#endif
unnamed_type_26 var27;
struct unnamed_type_26_alignment {
#ifdef MSVC
    char a[_Alignof(unnamed_type_26)];
    char b;
#else
    char a;
    unnamed_type_26 b;
#endif
};
struct unnamed_type_26_alignment var28;
#pragma pack(1)
struct unnamed_type_26_packed {
    unnamed_type_26 a;
};
#pragma pack()
struct unnamed_type_26_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct unnamed_type_26_packed)];
    char b;
#else
    char a;
    struct unnamed_type_26_packed b;
#endif
};
struct unnamed_type_26_required_alignment var29;
struct unnamed_type_26_size {
    char a[sizeof(unnamed_type_26)+1];
    char b;
};
struct unnamed_type_26_size var30;

typedef struct {
    char c;
    unnamed_type_26 d;
} F;
F var31;
struct F_alignment {
#ifdef MSVC
    char a[_Alignof(F)];
    char b;
#else
    char a;
    F b;
#endif
};
struct F_alignment var32;
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
struct F_required_alignment var33;
struct F_size {
    char a[sizeof(F)+1];
    char b;
};
struct F_size var34;

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
_Static_assert(sizeof(A) == 3, "record A wrong sizeof");
_Static_assert(_Alignof(A) == 2, "record A wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 5, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_alignment) == 2, "record A wrong alignment");
_Static_assert(sizeof(struct A_packed) == 3, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_packed) == 1, "record A wrong alignment");
_Static_assert(sizeof(struct A_required_alignment) == 4, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "record A wrong alignment");
_Static_assert(sizeof(struct A_size) == 5, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_size) == 1, "record A wrong alignment");
#endif
_Static_assert(sizeof(B) == 10, "record B wrong sizeof");
_Static_assert(_Alignof(B) == 2, "record B wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 12, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_alignment) == 2, "record B wrong alignment");
_Static_assert(sizeof(struct B_packed) == 10, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_packed) == 1, "record B wrong alignment");
_Static_assert(sizeof(struct B_required_alignment) == 11, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "record B wrong alignment");
_Static_assert(sizeof(struct B_size) == 12, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_size) == 1, "record B wrong alignment");
#endif
_Static_assert(sizeof(C) == 3, "record C wrong sizeof");
_Static_assert(_Alignof(C) == 1, "record C wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 4, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_alignment) == 1, "record C wrong alignment");
_Static_assert(sizeof(struct C_packed) == 3, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_packed) == 1, "record C wrong alignment");
_Static_assert(sizeof(struct C_required_alignment) == 4, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "record C wrong alignment");
_Static_assert(sizeof(struct C_size) == 5, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_size) == 1, "record C wrong alignment");
#endif
_Static_assert(sizeof(D) == 0, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 2, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 2, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 2, "record D wrong alignment");
_Static_assert(sizeof(struct D_packed) == 0, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 1, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_size) == 2, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_size) == 1, "record D wrong alignment");
#endif
_Static_assert(sizeof(E) == 2, "record E wrong sizeof");
_Static_assert(_Alignof(E) == 2, "record E wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 4, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_alignment) == 2, "record E wrong alignment");
_Static_assert(sizeof(struct E_packed) == 2, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_packed) == 1, "record E wrong alignment");
_Static_assert(sizeof(struct E_required_alignment) == 3, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "record E wrong alignment");
_Static_assert(sizeof(struct E_size) == 4, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_size) == 1, "record E wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(E,d) == 16, "field E.d wrong bit offset");
#endif
_Static_assert(sizeof(F) == 2, "record F wrong sizeof");
_Static_assert(_Alignof(F) == 2, "record F wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 4, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_alignment) == 2, "record F wrong alignment");
_Static_assert(sizeof(struct F_packed) == 2, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_packed) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_required_alignment) == 3, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_size) == 4, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_size) == 1, "record F wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F,d) == 16, "field F.d wrong bit offset");
#endif
#elif defined(AARCH64_PC_WINDOWS_MSVC) ||  defined(I586_PC_WINDOWS_MSVC) ||  defined(I686_PC_WINDOWS_MSVC) ||  defined(I686_UNKNOWN_WINDOWS) ||  \
 defined(THUMBV7A_PC_WINDOWS_MSVC) ||  defined(X8664_PC_WINDOWS_MSVC) ||  defined(X8664_UNKNOWN_WINDOWS) 
_Static_assert(sizeof(A) == 3, "record A wrong sizeof");
_Static_assert(_Alignof(A) == 2, "record A wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 5, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_alignment) == 2, "record A wrong alignment");
_Static_assert(sizeof(struct A_packed) == 3, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_packed) == 1, "record A wrong alignment");
_Static_assert(sizeof(struct A_required_alignment) == 4, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "record A wrong alignment");
_Static_assert(sizeof(struct A_size) == 5, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_size) == 1, "record A wrong alignment");
#endif
_Static_assert(sizeof(B) == 9, "record B wrong sizeof");
_Static_assert(_Alignof(B) == 2, "record B wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 11, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_alignment) == 2, "record B wrong alignment");
_Static_assert(sizeof(struct B_packed) == 9, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_packed) == 1, "record B wrong alignment");
_Static_assert(sizeof(struct B_required_alignment) == 10, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "record B wrong alignment");
_Static_assert(sizeof(struct B_size) == 11, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_size) == 1, "record B wrong alignment");
#endif
_Static_assert(sizeof(C) == 3, "record C wrong sizeof");
_Static_assert(_Alignof(C) == 1, "record C wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 4, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_alignment) == 1, "record C wrong alignment");
_Static_assert(sizeof(struct C_packed) == 3, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_packed) == 1, "record C wrong alignment");
_Static_assert(sizeof(struct C_required_alignment) == 4, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "record C wrong alignment");
_Static_assert(sizeof(struct C_size) == 5, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_size) == 1, "record C wrong alignment");
#endif
_Static_assert(sizeof(D) == 0, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 2, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 2, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 2, "record D wrong alignment");
_Static_assert(sizeof(struct D_packed) == 0, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 1, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_size) == 2, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_size) == 1, "record D wrong alignment");
#endif
_Static_assert(sizeof(E) == 2, "record E wrong sizeof");
_Static_assert(_Alignof(E) == 2, "record E wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 4, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_alignment) == 2, "record E wrong alignment");
_Static_assert(sizeof(struct E_packed) == 2, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_packed) == 1, "record E wrong alignment");
_Static_assert(sizeof(struct E_required_alignment) == 3, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "record E wrong alignment");
_Static_assert(sizeof(struct E_size) == 4, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_size) == 1, "record E wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(E,d) == 16, "field E.d wrong bit offset");
#endif
_Static_assert(sizeof(F) == 2, "record F wrong sizeof");
_Static_assert(_Alignof(F) == 2, "record F wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 4, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_alignment) == 2, "record F wrong alignment");
_Static_assert(sizeof(struct F_packed) == 2, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_packed) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_required_alignment) == 3, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_size) == 4, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_size) == 1, "record F wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F,d) == 16, "field F.d wrong bit offset");
#endif
#endif
