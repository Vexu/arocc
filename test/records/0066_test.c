// SPDX-License-Identifier: GPL-3.0-or-later

// This test file is auto-generated. do not edit.
// This file is a derivative work from the test files found// in this repo : https://github.com/mahkoh/repr-c
// and is under the same licence as the original work.

typedef struct {
#ifdef MSVC
    __declspec(align(128)) int x;
#else
    int x __attribute__((aligned(128)));
#endif
} A1;
A1 var1;
struct A1_alignment {
#ifdef MSVC
    char a[_Alignof(A1)];
    char b;
#else
    char a;
    A1 b;
#endif
};
struct A1_alignment var2;
#pragma pack(1)
struct A1_packed {
    A1 a;
};
#pragma pack()
struct A1_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct A1_packed)];
    char b;
#else
    char a;
    struct A1_packed b;
#endif
};
struct A1_required_alignment var3;
struct A1_size {
    char a[sizeof(A1)+1];
    char b;
};
struct A1_size var4;

typedef union {
#ifdef MSVC
    __declspec(align(128)) int x;
#else
    int x __attribute__((aligned(128)));
#endif
} A2;
A2 var5;
struct A2_alignment {
#ifdef MSVC
    char a[_Alignof(A2)];
    char b;
#else
    char a;
    A2 b;
#endif
};
struct A2_alignment var6;
#pragma pack(1)
struct A2_packed {
    A2 a;
};
#pragma pack()
struct A2_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct A2_packed)];
    char b;
#else
    char a;
    struct A2_packed b;
#endif
};
struct A2_required_alignment var7;
struct A2_size {
    char a[sizeof(A2)+1];
    char b;
};
struct A2_size var8;

#ifdef MSVC
__declspec(align(128)) typedef int B;
#else
typedef int B __attribute__((aligned(128)));
#endif
B var9;
struct B_alignment {
#ifdef MSVC
    char a[_Alignof(B)];
    char b;
#else
    char a;
    B b;
#endif
};
struct B_alignment var10;
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
struct B_required_alignment var11;
struct B_size {
    char a[sizeof(B)+1];
    char b;
};
struct B_size var12;

typedef struct {
    B x;
} C1;
C1 var13;
struct C1_alignment {
#ifdef MSVC
    char a[_Alignof(C1)];
    char b;
#else
    char a;
    C1 b;
#endif
};
struct C1_alignment var14;
#pragma pack(1)
struct C1_packed {
    C1 a;
};
#pragma pack()
struct C1_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct C1_packed)];
    char b;
#else
    char a;
    struct C1_packed b;
#endif
};
struct C1_required_alignment var15;
struct C1_size {
    char a[sizeof(C1)+1];
    char b;
};
struct C1_size var16;

typedef union {
    B x;
} C2;
C2 var17;
struct C2_alignment {
#ifdef MSVC
    char a[_Alignof(C2)];
    char b;
#else
    char a;
    C2 b;
#endif
};
struct C2_alignment var18;
#pragma pack(1)
struct C2_packed {
    C2 a;
};
#pragma pack()
struct C2_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct C2_packed)];
    char b;
#else
    char a;
    struct C2_packed b;
#endif
};
struct C2_required_alignment var19;
struct C2_size {
    char a[sizeof(C2)+1];
    char b;
};
struct C2_size var20;

typedef struct {
#ifdef MSVC
    __declspec(align(256)) B x;
#else
    B x __attribute__((aligned(256)));
#endif
} D1;
D1 var21;
struct D1_alignment {
#ifdef MSVC
    char a[_Alignof(D1)];
    char b;
#else
    char a;
    D1 b;
#endif
};
struct D1_alignment var22;
#pragma pack(1)
struct D1_packed {
    D1 a;
};
#pragma pack()
struct D1_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct D1_packed)];
    char b;
#else
    char a;
    struct D1_packed b;
#endif
};
struct D1_required_alignment var23;
struct D1_size {
    char a[sizeof(D1)+1];
    char b;
};
struct D1_size var24;

typedef union {
#ifdef MSVC
    __declspec(align(256)) B x;
#else
    B x __attribute__((aligned(256)));
#endif
} D2;
D2 var25;
struct D2_alignment {
#ifdef MSVC
    char a[_Alignof(D2)];
    char b;
#else
    char a;
    D2 b;
#endif
};
struct D2_alignment var26;
#pragma pack(1)
struct D2_packed {
    D2 a;
};
#pragma pack()
struct D2_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct D2_packed)];
    char b;
#else
    char a;
    struct D2_packed b;
#endif
};
struct D2_required_alignment var27;
struct D2_size {
    char a[sizeof(D2)+1];
    char b;
};
struct D2_size var28;

#ifdef MSVC
__declspec(align(256)) typedef struct {
#else
typedef struct {
#endif
    B x;
#ifdef MSVC
} E1;
#else
} __attribute__((aligned(256))) E1;
#endif
E1 var29;
struct E1_alignment {
#ifdef MSVC
    char a[_Alignof(E1)];
    char b;
#else
    char a;
    E1 b;
#endif
};
struct E1_alignment var30;
#pragma pack(1)
struct E1_packed {
    E1 a;
};
#pragma pack()
struct E1_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct E1_packed)];
    char b;
#else
    char a;
    struct E1_packed b;
#endif
};
struct E1_required_alignment var31;
struct E1_size {
    char a[sizeof(E1)+1];
    char b;
};
struct E1_size var32;

#ifdef MSVC
__declspec(align(256)) typedef union {
#else
typedef union {
#endif
    B x;
#ifdef MSVC
} E2;
#else
} __attribute__((aligned(256))) E2;
#endif
E2 var33;
struct E2_alignment {
#ifdef MSVC
    char a[_Alignof(E2)];
    char b;
#else
    char a;
    E2 b;
#endif
};
struct E2_alignment var34;
#pragma pack(1)
struct E2_packed {
    E2 a;
};
#pragma pack()
struct E2_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct E2_packed)];
    char b;
#else
    char a;
    struct E2_packed b;
#endif
};
struct E2_required_alignment var35;
struct E2_size {
    char a[sizeof(E2)+1];
    char b;
};
struct E2_size var36;

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
_Static_assert(sizeof(A1) == 128, "record A1 wrong sizeof");
_Static_assert(_Alignof(A1) == 128, "record A1 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A1_alignment) == 256, "record A1_alignment wrong sizeof");
_Static_assert(_Alignof(struct A1_alignment) == 128, "record A1_alignment wrong alignment");
_Static_assert(sizeof(struct A1_packed) == 128, "record A1_packed wrong sizeof");
_Static_assert(_Alignof(struct A1_packed) == 1, "record A1_packed wrong alignment");
_Static_assert(sizeof(struct A1_required_alignment) == 129, "record A1_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct A1_required_alignment) == 1, "record A1_required_alignment wrong alignment");
_Static_assert(sizeof(struct A1_size) == 130, "record A1_size wrong sizeof");
_Static_assert(_Alignof(struct A1_size) == 1, "record A1_size wrong alignment");
#endif
_Static_assert(sizeof(A2) == 128, "record A2 wrong sizeof");
_Static_assert(_Alignof(A2) == 128, "record A2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A2_alignment) == 256, "record A2_alignment wrong sizeof");
_Static_assert(_Alignof(struct A2_alignment) == 128, "record A2_alignment wrong alignment");
_Static_assert(sizeof(struct A2_packed) == 128, "record A2_packed wrong sizeof");
_Static_assert(_Alignof(struct A2_packed) == 1, "record A2_packed wrong alignment");
_Static_assert(sizeof(struct A2_required_alignment) == 129, "record A2_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct A2_required_alignment) == 1, "record A2_required_alignment wrong alignment");
_Static_assert(sizeof(struct A2_size) == 130, "record A2_size wrong sizeof");
_Static_assert(_Alignof(struct A2_size) == 1, "record A2_size wrong alignment");
#endif
_Static_assert(sizeof(B) == 4, "record B wrong sizeof");
_Static_assert(_Alignof(B) == 128, "record B wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 256, "record B_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_alignment) == 128, "record B_alignment wrong alignment");
_Static_assert(sizeof(struct B_packed) == 4, "record B_packed wrong sizeof");
_Static_assert(_Alignof(struct B_packed) == 1, "record B_packed wrong alignment");
_Static_assert(sizeof(struct B_required_alignment) == 5, "record B_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "record B_required_alignment wrong alignment");
_Static_assert(sizeof(struct B_size) == 6, "record B_size wrong sizeof");
_Static_assert(_Alignof(struct B_size) == 1, "record B_size wrong alignment");
#endif
_Static_assert(sizeof(C1) == 128, "record C1 wrong sizeof");
_Static_assert(_Alignof(C1) == 128, "record C1 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C1_alignment) == 256, "record C1_alignment wrong sizeof");
_Static_assert(_Alignof(struct C1_alignment) == 128, "record C1_alignment wrong alignment");
_Static_assert(sizeof(struct C1_packed) == 128, "record C1_packed wrong sizeof");
_Static_assert(_Alignof(struct C1_packed) == 1, "record C1_packed wrong alignment");
_Static_assert(sizeof(struct C1_required_alignment) == 129, "record C1_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct C1_required_alignment) == 1, "record C1_required_alignment wrong alignment");
_Static_assert(sizeof(struct C1_size) == 130, "record C1_size wrong sizeof");
_Static_assert(_Alignof(struct C1_size) == 1, "record C1_size wrong alignment");
#endif
_Static_assert(sizeof(C2) == 128, "record C2 wrong sizeof");
_Static_assert(_Alignof(C2) == 128, "record C2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C2_alignment) == 256, "record C2_alignment wrong sizeof");
_Static_assert(_Alignof(struct C2_alignment) == 128, "record C2_alignment wrong alignment");
_Static_assert(sizeof(struct C2_packed) == 128, "record C2_packed wrong sizeof");
_Static_assert(_Alignof(struct C2_packed) == 1, "record C2_packed wrong alignment");
_Static_assert(sizeof(struct C2_required_alignment) == 129, "record C2_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct C2_required_alignment) == 1, "record C2_required_alignment wrong alignment");
_Static_assert(sizeof(struct C2_size) == 130, "record C2_size wrong sizeof");
_Static_assert(_Alignof(struct C2_size) == 1, "record C2_size wrong alignment");
#endif
_Static_assert(sizeof(D1) == 256, "record D1 wrong sizeof");
_Static_assert(_Alignof(D1) == 256, "record D1 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D1_alignment) == 512, "record D1_alignment wrong sizeof");
_Static_assert(_Alignof(struct D1_alignment) == 256, "record D1_alignment wrong alignment");
_Static_assert(sizeof(struct D1_packed) == 256, "record D1_packed wrong sizeof");
_Static_assert(_Alignof(struct D1_packed) == 1, "record D1_packed wrong alignment");
_Static_assert(sizeof(struct D1_required_alignment) == 257, "record D1_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct D1_required_alignment) == 1, "record D1_required_alignment wrong alignment");
_Static_assert(sizeof(struct D1_size) == 258, "record D1_size wrong sizeof");
_Static_assert(_Alignof(struct D1_size) == 1, "record D1_size wrong alignment");
#endif
_Static_assert(sizeof(D2) == 256, "record D2 wrong sizeof");
_Static_assert(_Alignof(D2) == 256, "record D2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D2_alignment) == 512, "record D2_alignment wrong sizeof");
_Static_assert(_Alignof(struct D2_alignment) == 256, "record D2_alignment wrong alignment");
_Static_assert(sizeof(struct D2_packed) == 256, "record D2_packed wrong sizeof");
_Static_assert(_Alignof(struct D2_packed) == 1, "record D2_packed wrong alignment");
_Static_assert(sizeof(struct D2_required_alignment) == 257, "record D2_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct D2_required_alignment) == 1, "record D2_required_alignment wrong alignment");
_Static_assert(sizeof(struct D2_size) == 258, "record D2_size wrong sizeof");
_Static_assert(_Alignof(struct D2_size) == 1, "record D2_size wrong alignment");
#endif
_Static_assert(sizeof(E1) == 256, "record E1 wrong sizeof");
_Static_assert(_Alignof(E1) == 256, "record E1 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E1_alignment) == 512, "record E1_alignment wrong sizeof");
_Static_assert(_Alignof(struct E1_alignment) == 256, "record E1_alignment wrong alignment");
_Static_assert(sizeof(struct E1_packed) == 256, "record E1_packed wrong sizeof");
_Static_assert(_Alignof(struct E1_packed) == 1, "record E1_packed wrong alignment");
_Static_assert(sizeof(struct E1_required_alignment) == 257, "record E1_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct E1_required_alignment) == 1, "record E1_required_alignment wrong alignment");
_Static_assert(sizeof(struct E1_size) == 258, "record E1_size wrong sizeof");
_Static_assert(_Alignof(struct E1_size) == 1, "record E1_size wrong alignment");
#endif
_Static_assert(sizeof(E2) == 256, "record E2 wrong sizeof");
_Static_assert(_Alignof(E2) == 256, "record E2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E2_alignment) == 512, "record E2_alignment wrong sizeof");
_Static_assert(_Alignof(struct E2_alignment) == 256, "record E2_alignment wrong alignment");
_Static_assert(sizeof(struct E2_packed) == 256, "record E2_packed wrong sizeof");
_Static_assert(_Alignof(struct E2_packed) == 1, "record E2_packed wrong alignment");
_Static_assert(sizeof(struct E2_required_alignment) == 257, "record E2_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct E2_required_alignment) == 1, "record E2_required_alignment wrong alignment");
_Static_assert(sizeof(struct E2_size) == 258, "record E2_size wrong sizeof");
_Static_assert(_Alignof(struct E2_size) == 1, "record E2_size wrong alignment");
#endif
#elif defined(AARCH64_PC_WINDOWS_MSVC) ||  defined(I586_PC_WINDOWS_MSVC) ||  defined(I686_PC_WINDOWS_MSVC) ||  defined(I686_UNKNOWN_WINDOWS) ||  \
 defined(THUMBV7A_PC_WINDOWS_MSVC) ||  defined(X8664_PC_WINDOWS_MSVC) ||  defined(X8664_UNKNOWN_WINDOWS) 
_Static_assert(sizeof(A1) == 128, "record A1 wrong sizeof");
_Static_assert(_Alignof(A1) == 128, "record A1 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A1_alignment) == 256, "record A1_alignment wrong sizeof");
_Static_assert(_Alignof(struct A1_alignment) == 128, "record A1_alignment wrong alignment");
_Static_assert(sizeof(struct A1_packed) == 128, "record A1_packed wrong sizeof");
_Static_assert(_Alignof(struct A1_packed) == 1, "record A1_packed wrong alignment");
_Static_assert(sizeof(struct A1_required_alignment) == 129, "record A1_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct A1_required_alignment) == 1, "record A1_required_alignment wrong alignment");
_Static_assert(sizeof(struct A1_size) == 130, "record A1_size wrong sizeof");
_Static_assert(_Alignof(struct A1_size) == 1, "record A1_size wrong alignment");
#endif
_Static_assert(sizeof(A2) == 128, "record A2 wrong sizeof");
_Static_assert(_Alignof(A2) == 128, "record A2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A2_alignment) == 256, "record A2_alignment wrong sizeof");
_Static_assert(_Alignof(struct A2_alignment) == 128, "record A2_alignment wrong alignment");
_Static_assert(sizeof(struct A2_packed) == 128, "record A2_packed wrong sizeof");
_Static_assert(_Alignof(struct A2_packed) == 1, "record A2_packed wrong alignment");
_Static_assert(sizeof(struct A2_required_alignment) == 129, "record A2_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct A2_required_alignment) == 1, "record A2_required_alignment wrong alignment");
_Static_assert(sizeof(struct A2_size) == 130, "record A2_size wrong sizeof");
_Static_assert(_Alignof(struct A2_size) == 1, "record A2_size wrong alignment");
#endif
_Static_assert(sizeof(B) == 4, "record B wrong sizeof");
_Static_assert(_Alignof(B) == 128, "record B wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 256, "record B_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_alignment) == 128, "record B_alignment wrong alignment");
_Static_assert(sizeof(struct B_packed) == 4, "record B_packed wrong sizeof");
_Static_assert(_Alignof(struct B_packed) == 1, "record B_packed wrong alignment");
_Static_assert(sizeof(struct B_required_alignment) == 5, "record B_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "record B_required_alignment wrong alignment");
_Static_assert(sizeof(struct B_size) == 6, "record B_size wrong sizeof");
_Static_assert(_Alignof(struct B_size) == 1, "record B_size wrong alignment");
#endif
_Static_assert(sizeof(C1) == 128, "record C1 wrong sizeof");
_Static_assert(_Alignof(C1) == 128, "record C1 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C1_alignment) == 256, "record C1_alignment wrong sizeof");
_Static_assert(_Alignof(struct C1_alignment) == 128, "record C1_alignment wrong alignment");
_Static_assert(sizeof(struct C1_packed) == 128, "record C1_packed wrong sizeof");
_Static_assert(_Alignof(struct C1_packed) == 1, "record C1_packed wrong alignment");
_Static_assert(sizeof(struct C1_required_alignment) == 129, "record C1_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct C1_required_alignment) == 1, "record C1_required_alignment wrong alignment");
_Static_assert(sizeof(struct C1_size) == 130, "record C1_size wrong sizeof");
_Static_assert(_Alignof(struct C1_size) == 1, "record C1_size wrong alignment");
#endif
_Static_assert(sizeof(C2) == 128, "record C2 wrong sizeof");
_Static_assert(_Alignof(C2) == 128, "record C2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C2_alignment) == 256, "record C2_alignment wrong sizeof");
_Static_assert(_Alignof(struct C2_alignment) == 128, "record C2_alignment wrong alignment");
_Static_assert(sizeof(struct C2_packed) == 128, "record C2_packed wrong sizeof");
_Static_assert(_Alignof(struct C2_packed) == 1, "record C2_packed wrong alignment");
_Static_assert(sizeof(struct C2_required_alignment) == 129, "record C2_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct C2_required_alignment) == 1, "record C2_required_alignment wrong alignment");
_Static_assert(sizeof(struct C2_size) == 130, "record C2_size wrong sizeof");
_Static_assert(_Alignof(struct C2_size) == 1, "record C2_size wrong alignment");
#endif
_Static_assert(sizeof(D1) == 256, "record D1 wrong sizeof");
_Static_assert(_Alignof(D1) == 256, "record D1 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D1_alignment) == 512, "record D1_alignment wrong sizeof");
_Static_assert(_Alignof(struct D1_alignment) == 256, "record D1_alignment wrong alignment");
_Static_assert(sizeof(struct D1_packed) == 256, "record D1_packed wrong sizeof");
_Static_assert(_Alignof(struct D1_packed) == 1, "record D1_packed wrong alignment");
_Static_assert(sizeof(struct D1_required_alignment) == 257, "record D1_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct D1_required_alignment) == 1, "record D1_required_alignment wrong alignment");
_Static_assert(sizeof(struct D1_size) == 258, "record D1_size wrong sizeof");
_Static_assert(_Alignof(struct D1_size) == 1, "record D1_size wrong alignment");
#endif
_Static_assert(sizeof(D2) == 256, "record D2 wrong sizeof");
_Static_assert(_Alignof(D2) == 256, "record D2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D2_alignment) == 512, "record D2_alignment wrong sizeof");
_Static_assert(_Alignof(struct D2_alignment) == 256, "record D2_alignment wrong alignment");
_Static_assert(sizeof(struct D2_packed) == 256, "record D2_packed wrong sizeof");
_Static_assert(_Alignof(struct D2_packed) == 1, "record D2_packed wrong alignment");
_Static_assert(sizeof(struct D2_required_alignment) == 257, "record D2_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct D2_required_alignment) == 1, "record D2_required_alignment wrong alignment");
_Static_assert(sizeof(struct D2_size) == 258, "record D2_size wrong sizeof");
_Static_assert(_Alignof(struct D2_size) == 1, "record D2_size wrong alignment");
#endif
_Static_assert(sizeof(E1) == 256, "record E1 wrong sizeof");
_Static_assert(_Alignof(E1) == 256, "record E1 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E1_alignment) == 512, "record E1_alignment wrong sizeof");
_Static_assert(_Alignof(struct E1_alignment) == 256, "record E1_alignment wrong alignment");
_Static_assert(sizeof(struct E1_packed) == 256, "record E1_packed wrong sizeof");
_Static_assert(_Alignof(struct E1_packed) == 1, "record E1_packed wrong alignment");
_Static_assert(sizeof(struct E1_required_alignment) == 257, "record E1_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct E1_required_alignment) == 1, "record E1_required_alignment wrong alignment");
_Static_assert(sizeof(struct E1_size) == 258, "record E1_size wrong sizeof");
_Static_assert(_Alignof(struct E1_size) == 1, "record E1_size wrong alignment");
#endif
_Static_assert(sizeof(E2) == 256, "record E2 wrong sizeof");
_Static_assert(_Alignof(E2) == 256, "record E2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E2_alignment) == 512, "record E2_alignment wrong sizeof");
_Static_assert(_Alignof(struct E2_alignment) == 256, "record E2_alignment wrong alignment");
_Static_assert(sizeof(struct E2_packed) == 256, "record E2_packed wrong sizeof");
_Static_assert(_Alignof(struct E2_packed) == 1, "record E2_packed wrong alignment");
_Static_assert(sizeof(struct E2_required_alignment) == 257, "record E2_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct E2_required_alignment) == 1, "record E2_required_alignment wrong alignment");
_Static_assert(sizeof(struct E2_size) == 258, "record E2_size wrong sizeof");
_Static_assert(_Alignof(struct E2_size) == 1, "record E2_size wrong alignment");
#endif
#elif defined(AVR_UNKNOWN_UNKNOWN) 
_Static_assert(sizeof(A1) == 128, "record A1 wrong sizeof");
_Static_assert(_Alignof(A1) == 128, "record A1 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A1_alignment) == 256, "record A1_alignment wrong sizeof");
_Static_assert(_Alignof(struct A1_alignment) == 128, "record A1_alignment wrong alignment");
_Static_assert(sizeof(struct A1_packed) == 128, "record A1_packed wrong sizeof");
_Static_assert(_Alignof(struct A1_packed) == 1, "record A1_packed wrong alignment");
_Static_assert(sizeof(struct A1_required_alignment) == 129, "record A1_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct A1_required_alignment) == 1, "record A1_required_alignment wrong alignment");
_Static_assert(sizeof(struct A1_size) == 130, "record A1_size wrong sizeof");
_Static_assert(_Alignof(struct A1_size) == 1, "record A1_size wrong alignment");
#endif
_Static_assert(sizeof(A2) == 128, "record A2 wrong sizeof");
_Static_assert(_Alignof(A2) == 128, "record A2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A2_alignment) == 256, "record A2_alignment wrong sizeof");
_Static_assert(_Alignof(struct A2_alignment) == 128, "record A2_alignment wrong alignment");
_Static_assert(sizeof(struct A2_packed) == 128, "record A2_packed wrong sizeof");
_Static_assert(_Alignof(struct A2_packed) == 1, "record A2_packed wrong alignment");
_Static_assert(sizeof(struct A2_required_alignment) == 129, "record A2_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct A2_required_alignment) == 1, "record A2_required_alignment wrong alignment");
_Static_assert(sizeof(struct A2_size) == 130, "record A2_size wrong sizeof");
_Static_assert(_Alignof(struct A2_size) == 1, "record A2_size wrong alignment");
#endif
_Static_assert(sizeof(B) == 2, "record B wrong sizeof");
_Static_assert(_Alignof(B) == 128, "record B wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 256, "record B_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_alignment) == 128, "record B_alignment wrong alignment");
_Static_assert(sizeof(struct B_packed) == 2, "record B_packed wrong sizeof");
_Static_assert(_Alignof(struct B_packed) == 1, "record B_packed wrong alignment");
_Static_assert(sizeof(struct B_required_alignment) == 3, "record B_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "record B_required_alignment wrong alignment");
_Static_assert(sizeof(struct B_size) == 4, "record B_size wrong sizeof");
_Static_assert(_Alignof(struct B_size) == 1, "record B_size wrong alignment");
#endif
_Static_assert(sizeof(C1) == 128, "record C1 wrong sizeof");
_Static_assert(_Alignof(C1) == 128, "record C1 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C1_alignment) == 256, "record C1_alignment wrong sizeof");
_Static_assert(_Alignof(struct C1_alignment) == 128, "record C1_alignment wrong alignment");
_Static_assert(sizeof(struct C1_packed) == 128, "record C1_packed wrong sizeof");
_Static_assert(_Alignof(struct C1_packed) == 1, "record C1_packed wrong alignment");
_Static_assert(sizeof(struct C1_required_alignment) == 129, "record C1_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct C1_required_alignment) == 1, "record C1_required_alignment wrong alignment");
_Static_assert(sizeof(struct C1_size) == 130, "record C1_size wrong sizeof");
_Static_assert(_Alignof(struct C1_size) == 1, "record C1_size wrong alignment");
#endif
_Static_assert(sizeof(C2) == 128, "record C2 wrong sizeof");
_Static_assert(_Alignof(C2) == 128, "record C2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C2_alignment) == 256, "record C2_alignment wrong sizeof");
_Static_assert(_Alignof(struct C2_alignment) == 128, "record C2_alignment wrong alignment");
_Static_assert(sizeof(struct C2_packed) == 128, "record C2_packed wrong sizeof");
_Static_assert(_Alignof(struct C2_packed) == 1, "record C2_packed wrong alignment");
_Static_assert(sizeof(struct C2_required_alignment) == 129, "record C2_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct C2_required_alignment) == 1, "record C2_required_alignment wrong alignment");
_Static_assert(sizeof(struct C2_size) == 130, "record C2_size wrong sizeof");
_Static_assert(_Alignof(struct C2_size) == 1, "record C2_size wrong alignment");
#endif
_Static_assert(sizeof(D1) == 256, "record D1 wrong sizeof");
_Static_assert(_Alignof(D1) == 256, "record D1 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D1_alignment) == 512, "record D1_alignment wrong sizeof");
_Static_assert(_Alignof(struct D1_alignment) == 256, "record D1_alignment wrong alignment");
_Static_assert(sizeof(struct D1_packed) == 256, "record D1_packed wrong sizeof");
_Static_assert(_Alignof(struct D1_packed) == 1, "record D1_packed wrong alignment");
_Static_assert(sizeof(struct D1_required_alignment) == 257, "record D1_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct D1_required_alignment) == 1, "record D1_required_alignment wrong alignment");
_Static_assert(sizeof(struct D1_size) == 258, "record D1_size wrong sizeof");
_Static_assert(_Alignof(struct D1_size) == 1, "record D1_size wrong alignment");
#endif
_Static_assert(sizeof(D2) == 256, "record D2 wrong sizeof");
_Static_assert(_Alignof(D2) == 256, "record D2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D2_alignment) == 512, "record D2_alignment wrong sizeof");
_Static_assert(_Alignof(struct D2_alignment) == 256, "record D2_alignment wrong alignment");
_Static_assert(sizeof(struct D2_packed) == 256, "record D2_packed wrong sizeof");
_Static_assert(_Alignof(struct D2_packed) == 1, "record D2_packed wrong alignment");
_Static_assert(sizeof(struct D2_required_alignment) == 257, "record D2_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct D2_required_alignment) == 1, "record D2_required_alignment wrong alignment");
_Static_assert(sizeof(struct D2_size) == 258, "record D2_size wrong sizeof");
_Static_assert(_Alignof(struct D2_size) == 1, "record D2_size wrong alignment");
#endif
_Static_assert(sizeof(E1) == 256, "record E1 wrong sizeof");
_Static_assert(_Alignof(E1) == 256, "record E1 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E1_alignment) == 512, "record E1_alignment wrong sizeof");
_Static_assert(_Alignof(struct E1_alignment) == 256, "record E1_alignment wrong alignment");
_Static_assert(sizeof(struct E1_packed) == 256, "record E1_packed wrong sizeof");
_Static_assert(_Alignof(struct E1_packed) == 1, "record E1_packed wrong alignment");
_Static_assert(sizeof(struct E1_required_alignment) == 257, "record E1_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct E1_required_alignment) == 1, "record E1_required_alignment wrong alignment");
_Static_assert(sizeof(struct E1_size) == 258, "record E1_size wrong sizeof");
_Static_assert(_Alignof(struct E1_size) == 1, "record E1_size wrong alignment");
#endif
_Static_assert(sizeof(E2) == 256, "record E2 wrong sizeof");
_Static_assert(_Alignof(E2) == 256, "record E2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E2_alignment) == 512, "record E2_alignment wrong sizeof");
_Static_assert(_Alignof(struct E2_alignment) == 256, "record E2_alignment wrong alignment");
_Static_assert(sizeof(struct E2_packed) == 256, "record E2_packed wrong sizeof");
_Static_assert(_Alignof(struct E2_packed) == 1, "record E2_packed wrong alignment");
_Static_assert(sizeof(struct E2_required_alignment) == 257, "record E2_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct E2_required_alignment) == 1, "record E2_required_alignment wrong alignment");
_Static_assert(sizeof(struct E2_size) == 258, "record E2_size wrong sizeof");
_Static_assert(_Alignof(struct E2_size) == 1, "record E2_size wrong alignment");
#endif
#elif defined(MSP430_NONE_ELF) 
_Static_assert(sizeof(A1) == 128, "record A1 wrong sizeof");
_Static_assert(_Alignof(A1) == 128, "record A1 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A1_alignment) == 256, "record A1_alignment wrong sizeof");
_Static_assert(_Alignof(struct A1_alignment) == 128, "record A1_alignment wrong alignment");
_Static_assert(sizeof(struct A1_packed) == 128, "record A1_packed wrong sizeof");
_Static_assert(_Alignof(struct A1_packed) == 1, "record A1_packed wrong alignment");
_Static_assert(sizeof(struct A1_required_alignment) == 129, "record A1_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct A1_required_alignment) == 1, "record A1_required_alignment wrong alignment");
_Static_assert(sizeof(struct A1_size) == 130, "record A1_size wrong sizeof");
_Static_assert(_Alignof(struct A1_size) == 1, "record A1_size wrong alignment");
#endif
_Static_assert(sizeof(A2) == 128, "record A2 wrong sizeof");
_Static_assert(_Alignof(A2) == 128, "record A2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A2_alignment) == 256, "record A2_alignment wrong sizeof");
_Static_assert(_Alignof(struct A2_alignment) == 128, "record A2_alignment wrong alignment");
_Static_assert(sizeof(struct A2_packed) == 128, "record A2_packed wrong sizeof");
_Static_assert(_Alignof(struct A2_packed) == 1, "record A2_packed wrong alignment");
_Static_assert(sizeof(struct A2_required_alignment) == 129, "record A2_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct A2_required_alignment) == 1, "record A2_required_alignment wrong alignment");
_Static_assert(sizeof(struct A2_size) == 130, "record A2_size wrong sizeof");
_Static_assert(_Alignof(struct A2_size) == 1, "record A2_size wrong alignment");
#endif
_Static_assert(sizeof(B) == 2, "record B wrong sizeof");
_Static_assert(_Alignof(B) == 128, "record B wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 256, "record B_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_alignment) == 128, "record B_alignment wrong alignment");
_Static_assert(sizeof(struct B_packed) == 2, "record B_packed wrong sizeof");
_Static_assert(_Alignof(struct B_packed) == 1, "record B_packed wrong alignment");
_Static_assert(sizeof(struct B_required_alignment) == 3, "record B_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "record B_required_alignment wrong alignment");
_Static_assert(sizeof(struct B_size) == 4, "record B_size wrong sizeof");
_Static_assert(_Alignof(struct B_size) == 1, "record B_size wrong alignment");
#endif
_Static_assert(sizeof(C1) == 128, "record C1 wrong sizeof");
_Static_assert(_Alignof(C1) == 128, "record C1 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C1_alignment) == 256, "record C1_alignment wrong sizeof");
_Static_assert(_Alignof(struct C1_alignment) == 128, "record C1_alignment wrong alignment");
_Static_assert(sizeof(struct C1_packed) == 128, "record C1_packed wrong sizeof");
_Static_assert(_Alignof(struct C1_packed) == 1, "record C1_packed wrong alignment");
_Static_assert(sizeof(struct C1_required_alignment) == 129, "record C1_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct C1_required_alignment) == 1, "record C1_required_alignment wrong alignment");
_Static_assert(sizeof(struct C1_size) == 130, "record C1_size wrong sizeof");
_Static_assert(_Alignof(struct C1_size) == 1, "record C1_size wrong alignment");
#endif
_Static_assert(sizeof(C2) == 128, "record C2 wrong sizeof");
_Static_assert(_Alignof(C2) == 128, "record C2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C2_alignment) == 256, "record C2_alignment wrong sizeof");
_Static_assert(_Alignof(struct C2_alignment) == 128, "record C2_alignment wrong alignment");
_Static_assert(sizeof(struct C2_packed) == 128, "record C2_packed wrong sizeof");
_Static_assert(_Alignof(struct C2_packed) == 1, "record C2_packed wrong alignment");
_Static_assert(sizeof(struct C2_required_alignment) == 129, "record C2_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct C2_required_alignment) == 1, "record C2_required_alignment wrong alignment");
_Static_assert(sizeof(struct C2_size) == 130, "record C2_size wrong sizeof");
_Static_assert(_Alignof(struct C2_size) == 1, "record C2_size wrong alignment");
#endif
_Static_assert(sizeof(D1) == 256, "record D1 wrong sizeof");
_Static_assert(_Alignof(D1) == 256, "record D1 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D1_alignment) == 512, "record D1_alignment wrong sizeof");
_Static_assert(_Alignof(struct D1_alignment) == 256, "record D1_alignment wrong alignment");
_Static_assert(sizeof(struct D1_packed) == 256, "record D1_packed wrong sizeof");
_Static_assert(_Alignof(struct D1_packed) == 1, "record D1_packed wrong alignment");
_Static_assert(sizeof(struct D1_required_alignment) == 257, "record D1_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct D1_required_alignment) == 1, "record D1_required_alignment wrong alignment");
_Static_assert(sizeof(struct D1_size) == 258, "record D1_size wrong sizeof");
_Static_assert(_Alignof(struct D1_size) == 1, "record D1_size wrong alignment");
#endif
_Static_assert(sizeof(D2) == 256, "record D2 wrong sizeof");
_Static_assert(_Alignof(D2) == 256, "record D2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D2_alignment) == 512, "record D2_alignment wrong sizeof");
_Static_assert(_Alignof(struct D2_alignment) == 256, "record D2_alignment wrong alignment");
_Static_assert(sizeof(struct D2_packed) == 256, "record D2_packed wrong sizeof");
_Static_assert(_Alignof(struct D2_packed) == 1, "record D2_packed wrong alignment");
_Static_assert(sizeof(struct D2_required_alignment) == 257, "record D2_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct D2_required_alignment) == 1, "record D2_required_alignment wrong alignment");
_Static_assert(sizeof(struct D2_size) == 258, "record D2_size wrong sizeof");
_Static_assert(_Alignof(struct D2_size) == 1, "record D2_size wrong alignment");
#endif
_Static_assert(sizeof(E1) == 256, "record E1 wrong sizeof");
_Static_assert(_Alignof(E1) == 256, "record E1 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E1_alignment) == 512, "record E1_alignment wrong sizeof");
_Static_assert(_Alignof(struct E1_alignment) == 256, "record E1_alignment wrong alignment");
_Static_assert(sizeof(struct E1_packed) == 256, "record E1_packed wrong sizeof");
_Static_assert(_Alignof(struct E1_packed) == 1, "record E1_packed wrong alignment");
_Static_assert(sizeof(struct E1_required_alignment) == 257, "record E1_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct E1_required_alignment) == 1, "record E1_required_alignment wrong alignment");
_Static_assert(sizeof(struct E1_size) == 258, "record E1_size wrong sizeof");
_Static_assert(_Alignof(struct E1_size) == 1, "record E1_size wrong alignment");
#endif
_Static_assert(sizeof(E2) == 256, "record E2 wrong sizeof");
_Static_assert(_Alignof(E2) == 256, "record E2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E2_alignment) == 512, "record E2_alignment wrong sizeof");
_Static_assert(_Alignof(struct E2_alignment) == 256, "record E2_alignment wrong alignment");
_Static_assert(sizeof(struct E2_packed) == 256, "record E2_packed wrong sizeof");
_Static_assert(_Alignof(struct E2_packed) == 1, "record E2_packed wrong alignment");
_Static_assert(sizeof(struct E2_required_alignment) == 257, "record E2_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct E2_required_alignment) == 1, "record E2_required_alignment wrong alignment");
_Static_assert(sizeof(struct E2_size) == 258, "record E2_size wrong sizeof");
_Static_assert(_Alignof(struct E2_size) == 1, "record E2_size wrong alignment");
#endif
#endif
