// SPDX-License-Identifier: GPL-3.0-or-later

// This test file is auto-generated. do not edit.
// This file is a derivative work from the test files found// in this repo : https://github.com/mahkoh/repr-c
// and is under the same licence as the original work.

typedef union {
    int a:1;
} A;
A var1;
struct A_alignment {
#ifdef MSVC
    char a[_Alignof(A)];
    char b;
#else
    char a;
    A b;
#endif
};
struct A_alignment var2;
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
struct A_required_alignment var3;
struct A_size {
    char a[sizeof(A)+1];
    char b;
};
struct A_size var4;

typedef union {
#ifdef MSVC
    __declspec(align(8)) int a:1;
#else
    int a:1 __attribute__((aligned(8)));
#endif
} B;
B var5;
struct B_alignment {
#ifdef MSVC
    char a[_Alignof(B)];
    char b;
#else
    char a;
    B b;
#endif
};
struct B_alignment var6;
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
struct B_required_alignment var7;
struct B_size {
    char a[sizeof(B)+1];
    char b;
};
struct B_size var8;

typedef union {
#ifdef MSVC
    __declspec(align(8)) int:0;
#else
    int:0 __attribute__((aligned(8)));
#endif
} C;
C var9;
struct C_alignment {
#ifdef MSVC
    char a[_Alignof(C)];
    char b;
#else
    char a;
    C b;
#endif
};
struct C_alignment var10;
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
struct C_required_alignment var11;
struct C_size {
    char a[sizeof(C)+1];
    char b;
};
struct C_size var12;

typedef union {
    char c;
#ifdef MSVC
    __declspec(align(8)) int:0;
#else
    int:0 __attribute__((aligned(8)));
#endif
} D;
D var13;
struct D_alignment {
#ifdef MSVC
    char a[_Alignof(D)];
    char b;
#else
    char a;
    D b;
#endif
};
struct D_alignment var14;
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
struct D_required_alignment var15;
struct D_size {
    char a[sizeof(D)+1];
    char b;
};
struct D_size var16;

typedef union {
    char c;
#ifdef MSVC
    __declspec(align(8)) int:0;
    __declspec(align(8)) int:0;
#else
    int:0 __attribute__((aligned(8)));
    int:0 __attribute__((aligned(8)));
#endif
} E;
E var17;
struct E_alignment {
#ifdef MSVC
    char a[_Alignof(E)];
    char b;
#else
    char a;
    E b;
#endif
};
struct E_alignment var18;
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
struct E_required_alignment var19;
struct E_size {
    char a[sizeof(E)+1];
    char b;
};
struct E_size var20;

#if defined(AARCH64_APPLE_MACOSX) ||  defined(ARM64_APPLE_IOS) ||  defined(ARM64_APPLE_IOS_MACABI) ||  defined(ARM64_APPLE_TVOS) ||  \
 defined(HEXAGON_UNKNOWN_LINUX_MUSL) ||  defined(I386_APPLE_IOS) ||  defined(I586_UNKNOWN_LINUX_GNU) ||  defined(I586_UNKNOWN_LINUX_MUSL) ||  \
 defined(I686_APPLE_MACOSX) ||  defined(I686_LINUX_ANDROID) ||  defined(I686_PC_WINDOWS_GNU) ||  defined(I686_UNKNOWN_FREEBSD) ||  \
 defined(I686_UNKNOWN_HAIKU) ||  defined(I686_UNKNOWN_LINUX_GNU) ||  defined(I686_UNKNOWN_LINUX_MUSL) ||  defined(I686_UNKNOWN_NETBSDELF) ||  \
 defined(I686_UNKNOWN_OPENBSD) ||  defined(MIPS64EL_UNKNOWN_LINUX_GNUABI64) ||  defined(MIPS64EL_UNKNOWN_LINUX_MUSL) ||  defined(MIPS64_UNKNOWN_LINUX_GNUABI64) ||  \
 defined(MIPS64_UNKNOWN_LINUX_MUSL) ||  defined(MIPSEL_SONY_PSP) ||  defined(MIPSEL_UNKNOWN_LINUX_GNU) ||  defined(MIPSEL_UNKNOWN_LINUX_MUSL) ||  \
 defined(MIPSEL_UNKNOWN_LINUX_UCLIBC) ||  defined(MIPSEL_UNKNOWN_NONE) ||  defined(MIPSISA32R6EL_UNKNOWN_LINUX_GNU) ||  defined(MIPSISA32R6_UNKNOWN_LINUX_GNU) ||  \
 defined(MIPSISA64R6EL_UNKNOWN_LINUX_GNUABI64) ||  defined(MIPSISA64R6_UNKNOWN_LINUX_GNUABI64) ||  defined(MIPS_UNKNOWN_LINUX_GNU) ||  \
 defined(MIPS_UNKNOWN_LINUX_MUSL) ||  defined(MIPS_UNKNOWN_LINUX_UCLIBC) ||  defined(POWERPC64LE_UNKNOWN_LINUX_GNU) ||  defined(POWERPC64LE_UNKNOWN_LINUX_MUSL) ||  \
 defined(POWERPC64_UNKNOWN_FREEBSD) ||  defined(POWERPC64_UNKNOWN_LINUX_GNU) ||  defined(POWERPC64_UNKNOWN_LINUX_MUSL) ||  defined(POWERPC_UNKNOWN_LINUX_GNU) ||  \
 defined(POWERPC_UNKNOWN_LINUX_GNUSPE) ||  defined(POWERPC_UNKNOWN_LINUX_MUSL) ||  defined(POWERPC_UNKNOWN_NETBSD) ||  defined(RISCV32) ||  \
 defined(RISCV32_UNKNOWN_LINUX_GNU) ||  defined(RISCV64) ||  defined(RISCV64_UNKNOWN_LINUX_GNU) ||  defined(S390X_UNKNOWN_LINUX_GNU) ||  \
 defined(SPARC64_UNKNOWN_LINUX_GNU) ||  defined(SPARC64_UNKNOWN_NETBSD) ||  defined(SPARC64_UNKNOWN_OPENBSD) ||  defined(SPARC_UNKNOWN_LINUX_GNU) ||  \
 defined(SPARCV9_SUN_SOLARIS) ||  defined(WASM32_UNKNOWN_EMSCRIPTEN) ||  defined(WASM32_UNKNOWN_UNKNOWN) ||  defined(WASM32_WASI) ||  \
 defined(X8664_APPLE_IOS_MACABI) ||  defined(X8664_APPLE_IOS) ||  defined(X8664_APPLE_MACOSX) ||  defined(X8664_APPLE_TVOS) ||  defined(X8664_ELF) ||  \
 defined(X8664_FUCHSIA) ||  defined(X8664_LINUX_ANDROID) ||  defined(X8664_PC_SOLARIS) ||  defined(X8664_PC_WINDOWS_GNU) ||  defined(X8664_RUMPRUN_NETBSD) ||  \
 defined(X8664_UNKNOWN_DRAGONFLY) ||  defined(X8664_UNKNOWN_FREEBSD) ||  defined(X8664_UNKNOWN_HAIKU) ||  defined(X8664_UNKNOWN_HERMIT) ||  \
 defined(X8664_UNKNOWN_L4RE_UCLIBC) ||  defined(X8664_UNKNOWN_LINUX_GNUX32) ||  defined(X8664_UNKNOWN_LINUX_GNU) ||  defined(X8664_UNKNOWN_LINUX_MUSL) ||  \
 defined(X8664_UNKNOWN_NETBSD) ||  defined(X8664_UNKNOWN_OPENBSD) ||  defined(X8664_UNKNOWN_REDOX) 
_Static_assert(sizeof(A) == 4, "record A wrong sizeof");
_Static_assert(_Alignof(A) == 4, "record A wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 8, "record A_alignment wrong sizeof");
_Static_assert(_Alignof(struct A_alignment) == 4, "record A_alignment wrong alignment");
_Static_assert(sizeof(struct A_packed) == 4, "record A_packed wrong sizeof");
_Static_assert(_Alignof(struct A_packed) == 1, "record A_packed wrong alignment");
_Static_assert(sizeof(struct A_required_alignment) == 5, "record A_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "record A_required_alignment wrong alignment");
_Static_assert(sizeof(struct A_size) == 6, "record A_size wrong sizeof");
_Static_assert(_Alignof(struct A_size) == 1, "record A_size wrong alignment");
#endif
_Static_assert(sizeof(B) == 8, "record B wrong sizeof");
_Static_assert(_Alignof(B) == 8, "record B wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 16, "record B_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_alignment) == 8, "record B_alignment wrong alignment");
_Static_assert(sizeof(struct B_packed) == 8, "record B_packed wrong sizeof");
_Static_assert(_Alignof(struct B_packed) == 1, "record B_packed wrong alignment");
_Static_assert(sizeof(struct B_required_alignment) == 9, "record B_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "record B_required_alignment wrong alignment");
_Static_assert(sizeof(struct B_size) == 10, "record B_size wrong sizeof");
_Static_assert(_Alignof(struct B_size) == 1, "record B_size wrong alignment");
#endif
_Static_assert(sizeof(C) == 0, "record C wrong sizeof");
_Static_assert(_Alignof(C) == 1, "record C wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 1, "record C_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_alignment) == 1, "record C_alignment wrong alignment");
_Static_assert(sizeof(struct C_packed) == 0, "record C_packed wrong sizeof");
_Static_assert(_Alignof(struct C_packed) == 1, "record C_packed wrong alignment");
_Static_assert(sizeof(struct C_required_alignment) == 1, "record C_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "record C_required_alignment wrong alignment");
_Static_assert(sizeof(struct C_size) == 2, "record C_size wrong sizeof");
_Static_assert(_Alignof(struct C_size) == 1, "record C_size wrong alignment");
#endif
_Static_assert(sizeof(D) == 1, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 1, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 2, "record D_alignment wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 1, "record D_alignment wrong alignment");
_Static_assert(sizeof(struct D_packed) == 1, "record D_packed wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D_packed wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 2, "record D_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D_required_alignment wrong alignment");
_Static_assert(sizeof(struct D_size) == 3, "record D_size wrong sizeof");
_Static_assert(_Alignof(struct D_size) == 1, "record D_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(E) == 1, "record E wrong sizeof");
_Static_assert(_Alignof(E) == 1, "record E wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 2, "record E_alignment wrong sizeof");
_Static_assert(_Alignof(struct E_alignment) == 1, "record E_alignment wrong alignment");
_Static_assert(sizeof(struct E_packed) == 1, "record E_packed wrong sizeof");
_Static_assert(_Alignof(struct E_packed) == 1, "record E_packed wrong alignment");
_Static_assert(sizeof(struct E_required_alignment) == 2, "record E_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "record E_required_alignment wrong alignment");
_Static_assert(sizeof(struct E_size) == 3, "record E_size wrong sizeof");
_Static_assert(_Alignof(struct E_size) == 1, "record E_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
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
_Static_assert(sizeof(A) == 4, "record A wrong sizeof");
_Static_assert(_Alignof(A) == 4, "record A wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 8, "record A_alignment wrong sizeof");
_Static_assert(_Alignof(struct A_alignment) == 4, "record A_alignment wrong alignment");
_Static_assert(sizeof(struct A_packed) == 4, "record A_packed wrong sizeof");
_Static_assert(_Alignof(struct A_packed) == 1, "record A_packed wrong alignment");
_Static_assert(sizeof(struct A_required_alignment) == 5, "record A_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "record A_required_alignment wrong alignment");
_Static_assert(sizeof(struct A_size) == 6, "record A_size wrong sizeof");
_Static_assert(_Alignof(struct A_size) == 1, "record A_size wrong alignment");
#endif
_Static_assert(sizeof(B) == 8, "record B wrong sizeof");
_Static_assert(_Alignof(B) == 8, "record B wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 16, "record B_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_alignment) == 8, "record B_alignment wrong alignment");
_Static_assert(sizeof(struct B_packed) == 8, "record B_packed wrong sizeof");
_Static_assert(_Alignof(struct B_packed) == 1, "record B_packed wrong alignment");
_Static_assert(sizeof(struct B_required_alignment) == 9, "record B_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "record B_required_alignment wrong alignment");
_Static_assert(sizeof(struct B_size) == 10, "record B_size wrong sizeof");
_Static_assert(_Alignof(struct B_size) == 1, "record B_size wrong alignment");
#endif
_Static_assert(sizeof(C) == 0, "record C wrong sizeof");
_Static_assert(_Alignof(C) == 8, "record C wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 8, "record C_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_alignment) == 8, "record C_alignment wrong alignment");
_Static_assert(sizeof(struct C_packed) == 0, "record C_packed wrong sizeof");
_Static_assert(_Alignof(struct C_packed) == 1, "record C_packed wrong alignment");
_Static_assert(sizeof(struct C_required_alignment) == 1, "record C_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "record C_required_alignment wrong alignment");
_Static_assert(sizeof(struct C_size) == 2, "record C_size wrong sizeof");
_Static_assert(_Alignof(struct C_size) == 1, "record C_size wrong alignment");
#endif
_Static_assert(sizeof(D) == 8, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 8, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 16, "record D_alignment wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 8, "record D_alignment wrong alignment");
_Static_assert(sizeof(struct D_packed) == 8, "record D_packed wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D_packed wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 9, "record D_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D_required_alignment wrong alignment");
_Static_assert(sizeof(struct D_size) == 10, "record D_size wrong sizeof");
_Static_assert(_Alignof(struct D_size) == 1, "record D_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(E) == 8, "record E wrong sizeof");
_Static_assert(_Alignof(E) == 8, "record E wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 16, "record E_alignment wrong sizeof");
_Static_assert(_Alignof(struct E_alignment) == 8, "record E_alignment wrong alignment");
_Static_assert(sizeof(struct E_packed) == 8, "record E_packed wrong sizeof");
_Static_assert(_Alignof(struct E_packed) == 1, "record E_packed wrong alignment");
_Static_assert(sizeof(struct E_required_alignment) == 9, "record E_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "record E_required_alignment wrong alignment");
_Static_assert(sizeof(struct E_size) == 10, "record E_size wrong sizeof");
_Static_assert(_Alignof(struct E_size) == 1, "record E_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
#endif
#elif defined(AARCH64_PC_WINDOWS_MSVC) ||  defined(I586_PC_WINDOWS_MSVC) ||  defined(I686_PC_WINDOWS_MSVC) ||  defined(I686_UNKNOWN_WINDOWS) ||  \
 defined(THUMBV7A_PC_WINDOWS_MSVC) ||  defined(X8664_PC_WINDOWS_MSVC) ||  defined(X8664_UNKNOWN_WINDOWS) 
_Static_assert(sizeof(A) == 4, "record A wrong sizeof");
_Static_assert(_Alignof(A) == 1, "record A wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 5, "record A_alignment wrong sizeof");
_Static_assert(_Alignof(struct A_alignment) == 1, "record A_alignment wrong alignment");
_Static_assert(sizeof(struct A_packed) == 4, "record A_packed wrong sizeof");
_Static_assert(_Alignof(struct A_packed) == 1, "record A_packed wrong alignment");
_Static_assert(sizeof(struct A_required_alignment) == 5, "record A_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "record A_required_alignment wrong alignment");
_Static_assert(sizeof(struct A_size) == 6, "record A_size wrong sizeof");
_Static_assert(_Alignof(struct A_size) == 1, "record A_size wrong alignment");
#endif
_Static_assert(sizeof(B) == 4, "record B wrong sizeof");
_Static_assert(_Alignof(B) == 1, "record B wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 5, "record B_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_alignment) == 1, "record B_alignment wrong alignment");
_Static_assert(sizeof(struct B_packed) == 4, "record B_packed wrong sizeof");
_Static_assert(_Alignof(struct B_packed) == 1, "record B_packed wrong alignment");
_Static_assert(sizeof(struct B_required_alignment) == 5, "record B_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "record B_required_alignment wrong alignment");
_Static_assert(sizeof(struct B_size) == 6, "record B_size wrong sizeof");
_Static_assert(_Alignof(struct B_size) == 1, "record B_size wrong alignment");
#endif
_Static_assert(sizeof(C) == 4, "record C wrong sizeof");
_Static_assert(_Alignof(C) == 1, "record C wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 5, "record C_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_alignment) == 1, "record C_alignment wrong alignment");
_Static_assert(sizeof(struct C_packed) == 4, "record C_packed wrong sizeof");
_Static_assert(_Alignof(struct C_packed) == 1, "record C_packed wrong alignment");
_Static_assert(sizeof(struct C_required_alignment) == 5, "record C_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "record C_required_alignment wrong alignment");
_Static_assert(sizeof(struct C_size) == 6, "record C_size wrong sizeof");
_Static_assert(_Alignof(struct C_size) == 1, "record C_size wrong alignment");
#endif
_Static_assert(sizeof(D) == 1, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 1, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 2, "record D_alignment wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 1, "record D_alignment wrong alignment");
_Static_assert(sizeof(struct D_packed) == 1, "record D_packed wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D_packed wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 2, "record D_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D_required_alignment wrong alignment");
_Static_assert(sizeof(struct D_size) == 3, "record D_size wrong sizeof");
_Static_assert(_Alignof(struct D_size) == 1, "record D_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(E) == 1, "record E wrong sizeof");
_Static_assert(_Alignof(E) == 1, "record E wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 2, "record E_alignment wrong sizeof");
_Static_assert(_Alignof(struct E_alignment) == 1, "record E_alignment wrong alignment");
_Static_assert(sizeof(struct E_packed) == 1, "record E_packed wrong sizeof");
_Static_assert(_Alignof(struct E_packed) == 1, "record E_packed wrong alignment");
_Static_assert(sizeof(struct E_required_alignment) == 2, "record E_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "record E_required_alignment wrong alignment");
_Static_assert(sizeof(struct E_size) == 3, "record E_size wrong sizeof");
_Static_assert(_Alignof(struct E_size) == 1, "record E_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
#endif
#elif defined(ARMV7_APPLE_IOS) ||  defined(ARMV7S_APPLE_IOS) 
_Static_assert(sizeof(A) == 1, "record A wrong sizeof");
_Static_assert(_Alignof(A) == 1, "record A wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 2, "record A_alignment wrong sizeof");
_Static_assert(_Alignof(struct A_alignment) == 1, "record A_alignment wrong alignment");
_Static_assert(sizeof(struct A_packed) == 1, "record A_packed wrong sizeof");
_Static_assert(_Alignof(struct A_packed) == 1, "record A_packed wrong alignment");
_Static_assert(sizeof(struct A_required_alignment) == 2, "record A_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "record A_required_alignment wrong alignment");
_Static_assert(sizeof(struct A_size) == 3, "record A_size wrong sizeof");
_Static_assert(_Alignof(struct A_size) == 1, "record A_size wrong alignment");
#endif
_Static_assert(sizeof(B) == 8, "record B wrong sizeof");
_Static_assert(_Alignof(B) == 8, "record B wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 16, "record B_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_alignment) == 8, "record B_alignment wrong alignment");
_Static_assert(sizeof(struct B_packed) == 8, "record B_packed wrong sizeof");
_Static_assert(_Alignof(struct B_packed) == 1, "record B_packed wrong alignment");
_Static_assert(sizeof(struct B_required_alignment) == 9, "record B_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "record B_required_alignment wrong alignment");
_Static_assert(sizeof(struct B_size) == 10, "record B_size wrong sizeof");
_Static_assert(_Alignof(struct B_size) == 1, "record B_size wrong alignment");
#endif
_Static_assert(sizeof(C) == 0, "record C wrong sizeof");
_Static_assert(_Alignof(C) == 8, "record C wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 8, "record C_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_alignment) == 8, "record C_alignment wrong alignment");
_Static_assert(sizeof(struct C_packed) == 0, "record C_packed wrong sizeof");
_Static_assert(_Alignof(struct C_packed) == 1, "record C_packed wrong alignment");
_Static_assert(sizeof(struct C_required_alignment) == 1, "record C_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "record C_required_alignment wrong alignment");
_Static_assert(sizeof(struct C_size) == 2, "record C_size wrong sizeof");
_Static_assert(_Alignof(struct C_size) == 1, "record C_size wrong alignment");
#endif
_Static_assert(sizeof(D) == 8, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 8, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 16, "record D_alignment wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 8, "record D_alignment wrong alignment");
_Static_assert(sizeof(struct D_packed) == 8, "record D_packed wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D_packed wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 9, "record D_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D_required_alignment wrong alignment");
_Static_assert(sizeof(struct D_size) == 10, "record D_size wrong sizeof");
_Static_assert(_Alignof(struct D_size) == 1, "record D_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(E) == 8, "record E wrong sizeof");
_Static_assert(_Alignof(E) == 8, "record E wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 16, "record E_alignment wrong sizeof");
_Static_assert(_Alignof(struct E_alignment) == 8, "record E_alignment wrong alignment");
_Static_assert(sizeof(struct E_packed) == 8, "record E_packed wrong sizeof");
_Static_assert(_Alignof(struct E_packed) == 1, "record E_packed wrong alignment");
_Static_assert(sizeof(struct E_required_alignment) == 9, "record E_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "record E_required_alignment wrong alignment");
_Static_assert(sizeof(struct E_size) == 10, "record E_size wrong sizeof");
_Static_assert(_Alignof(struct E_size) == 1, "record E_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
#endif
#elif defined(AVR_UNKNOWN_UNKNOWN) 
_Static_assert(sizeof(A) == 1, "record A wrong sizeof");
_Static_assert(_Alignof(A) == 1, "record A wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 2, "record A_alignment wrong sizeof");
_Static_assert(_Alignof(struct A_alignment) == 1, "record A_alignment wrong alignment");
_Static_assert(sizeof(struct A_packed) == 1, "record A_packed wrong sizeof");
_Static_assert(_Alignof(struct A_packed) == 1, "record A_packed wrong alignment");
_Static_assert(sizeof(struct A_required_alignment) == 2, "record A_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "record A_required_alignment wrong alignment");
_Static_assert(sizeof(struct A_size) == 3, "record A_size wrong sizeof");
_Static_assert(_Alignof(struct A_size) == 1, "record A_size wrong alignment");
#endif
_Static_assert(sizeof(B) == 8, "record B wrong sizeof");
_Static_assert(_Alignof(B) == 8, "record B wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 16, "record B_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_alignment) == 8, "record B_alignment wrong alignment");
_Static_assert(sizeof(struct B_packed) == 8, "record B_packed wrong sizeof");
_Static_assert(_Alignof(struct B_packed) == 1, "record B_packed wrong alignment");
_Static_assert(sizeof(struct B_required_alignment) == 9, "record B_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "record B_required_alignment wrong alignment");
_Static_assert(sizeof(struct B_size) == 10, "record B_size wrong sizeof");
_Static_assert(_Alignof(struct B_size) == 1, "record B_size wrong alignment");
#endif
_Static_assert(sizeof(C) == 0, "record C wrong sizeof");
_Static_assert(_Alignof(C) == 8, "record C wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 8, "record C_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_alignment) == 8, "record C_alignment wrong alignment");
_Static_assert(sizeof(struct C_packed) == 0, "record C_packed wrong sizeof");
_Static_assert(_Alignof(struct C_packed) == 1, "record C_packed wrong alignment");
_Static_assert(sizeof(struct C_required_alignment) == 1, "record C_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "record C_required_alignment wrong alignment");
_Static_assert(sizeof(struct C_size) == 2, "record C_size wrong sizeof");
_Static_assert(_Alignof(struct C_size) == 1, "record C_size wrong alignment");
#endif
_Static_assert(sizeof(D) == 8, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 8, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 16, "record D_alignment wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 8, "record D_alignment wrong alignment");
_Static_assert(sizeof(struct D_packed) == 8, "record D_packed wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D_packed wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 9, "record D_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D_required_alignment wrong alignment");
_Static_assert(sizeof(struct D_size) == 10, "record D_size wrong sizeof");
_Static_assert(_Alignof(struct D_size) == 1, "record D_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(E) == 8, "record E wrong sizeof");
_Static_assert(_Alignof(E) == 8, "record E wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 16, "record E_alignment wrong sizeof");
_Static_assert(_Alignof(struct E_alignment) == 8, "record E_alignment wrong alignment");
_Static_assert(sizeof(struct E_packed) == 8, "record E_packed wrong sizeof");
_Static_assert(_Alignof(struct E_packed) == 1, "record E_packed wrong alignment");
_Static_assert(sizeof(struct E_required_alignment) == 9, "record E_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "record E_required_alignment wrong alignment");
_Static_assert(sizeof(struct E_size) == 10, "record E_size wrong sizeof");
_Static_assert(_Alignof(struct E_size) == 1, "record E_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
#endif
#elif defined(MSP430_NONE_ELF) 
_Static_assert(sizeof(A) == 2, "record A wrong sizeof");
_Static_assert(_Alignof(A) == 2, "record A wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 4, "record A_alignment wrong sizeof");
_Static_assert(_Alignof(struct A_alignment) == 2, "record A_alignment wrong alignment");
_Static_assert(sizeof(struct A_packed) == 2, "record A_packed wrong sizeof");
_Static_assert(_Alignof(struct A_packed) == 1, "record A_packed wrong alignment");
_Static_assert(sizeof(struct A_required_alignment) == 3, "record A_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "record A_required_alignment wrong alignment");
_Static_assert(sizeof(struct A_size) == 4, "record A_size wrong sizeof");
_Static_assert(_Alignof(struct A_size) == 1, "record A_size wrong alignment");
#endif
_Static_assert(sizeof(B) == 8, "record B wrong sizeof");
_Static_assert(_Alignof(B) == 8, "record B wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 16, "record B_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_alignment) == 8, "record B_alignment wrong alignment");
_Static_assert(sizeof(struct B_packed) == 8, "record B_packed wrong sizeof");
_Static_assert(_Alignof(struct B_packed) == 1, "record B_packed wrong alignment");
_Static_assert(sizeof(struct B_required_alignment) == 9, "record B_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "record B_required_alignment wrong alignment");
_Static_assert(sizeof(struct B_size) == 10, "record B_size wrong sizeof");
_Static_assert(_Alignof(struct B_size) == 1, "record B_size wrong alignment");
#endif
_Static_assert(sizeof(C) == 0, "record C wrong sizeof");
_Static_assert(_Alignof(C) == 1, "record C wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 1, "record C_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_alignment) == 1, "record C_alignment wrong alignment");
_Static_assert(sizeof(struct C_packed) == 0, "record C_packed wrong sizeof");
_Static_assert(_Alignof(struct C_packed) == 1, "record C_packed wrong alignment");
_Static_assert(sizeof(struct C_required_alignment) == 1, "record C_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "record C_required_alignment wrong alignment");
_Static_assert(sizeof(struct C_size) == 2, "record C_size wrong sizeof");
_Static_assert(_Alignof(struct C_size) == 1, "record C_size wrong alignment");
#endif
_Static_assert(sizeof(D) == 1, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 1, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 2, "record D_alignment wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 1, "record D_alignment wrong alignment");
_Static_assert(sizeof(struct D_packed) == 1, "record D_packed wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D_packed wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 2, "record D_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D_required_alignment wrong alignment");
_Static_assert(sizeof(struct D_size) == 3, "record D_size wrong sizeof");
_Static_assert(_Alignof(struct D_size) == 1, "record D_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(E) == 1, "record E wrong sizeof");
_Static_assert(_Alignof(E) == 1, "record E wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 2, "record E_alignment wrong sizeof");
_Static_assert(_Alignof(struct E_alignment) == 1, "record E_alignment wrong alignment");
_Static_assert(sizeof(struct E_packed) == 1, "record E_packed wrong sizeof");
_Static_assert(_Alignof(struct E_packed) == 1, "record E_packed wrong alignment");
_Static_assert(sizeof(struct E_required_alignment) == 2, "record E_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "record E_required_alignment wrong alignment");
_Static_assert(sizeof(struct E_size) == 3, "record E_size wrong sizeof");
_Static_assert(_Alignof(struct E_size) == 1, "record E_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
#endif
#endif
