// SPDX-License-Identifier: GPL-3.0-or-later

// This test file is auto-generated. do not edit.
// This file is a derivative work from the test files found// in this repo : https://github.com/mahkoh/repr-c
// and is under the same licence as the original work.

typedef int A __attribute__((aligned(1)));
A var1;
struct A_alignment {
    char a;
    A b;
};
struct A_alignment var2;
#pragma pack(1)
struct A_packed {
    A a;
};
#pragma pack()
struct A_required_alignment {
    char a;
    struct A_packed b;
};
struct A_required_alignment var3;
struct A_size {
    char a[sizeof(A)+1];
    char b;
};
struct A_size var4;

typedef union {
    A a:1;
} B;
B var5;
struct B_alignment {
    char a;
    B b;
};
struct B_alignment var6;
#pragma pack(1)
struct B_packed {
    B a;
};
#pragma pack()
struct B_required_alignment {
    char a;
    struct B_packed b;
};
struct B_required_alignment var7;
struct B_size {
    char a[sizeof(B)+1];
    char b;
};
struct B_size var8;

typedef union {
    int a:1 __attribute__((packed));
} C;
C var9;
struct C_alignment {
    char a;
    C b;
};
struct C_alignment var10;
#pragma pack(1)
struct C_packed {
    C a;
};
#pragma pack()
struct C_required_alignment {
    char a;
    struct C_packed b;
};
struct C_required_alignment var11;
struct C_size {
    char a[sizeof(C)+1];
    char b;
};
struct C_size var12;

#pragma pack(1)
typedef union {
    int a:1;
} D;
D var13;
#pragma pack()
struct D_alignment {
    char a;
    D b;
};
struct D_alignment var14;
#pragma pack(1)
struct D_packed {
    D a;
};
#pragma pack()
struct D_required_alignment {
    char a;
    struct D_packed b;
};
struct D_required_alignment var15;
struct D_size {
    char a[sizeof(D)+1];
    char b;
};
struct D_size var16;

typedef union {
    A a:9;
} E;
E var17;
struct E_alignment {
    char a;
    E b;
};
struct E_alignment var18;
#pragma pack(1)
struct E_packed {
    E a;
};
#pragma pack()
struct E_required_alignment {
    char a;
    struct E_packed b;
};
struct E_required_alignment var19;
struct E_size {
    char a[sizeof(E)+1];
    char b;
};
struct E_size var20;

typedef union {
    int a:9 __attribute__((packed));
} F;
F var21;
struct F_alignment {
    char a;
    F b;
};
struct F_alignment var22;
#pragma pack(1)
struct F_packed {
    F a;
};
#pragma pack()
struct F_required_alignment {
    char a;
    struct F_packed b;
};
struct F_required_alignment var23;
struct F_size {
    char a[sizeof(F)+1];
    char b;
};
struct F_size var24;

#pragma pack(1)
typedef union {
    int a:9;
} G;
G var25;
#pragma pack()
struct G_alignment {
    char a;
    G b;
};
struct G_alignment var26;
#pragma pack(1)
struct G_packed {
    G a;
};
#pragma pack()
struct G_required_alignment {
    char a;
    struct G_packed b;
};
struct G_required_alignment var27;
struct G_size {
    char a[sizeof(G)+1];
    char b;
};
struct G_size var28;


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
_Static_assert(sizeof(A) == 4, "record A wrong sizeof");
_Static_assert(_Alignof(A) == 1, "record A wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 5, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_alignment) == 1, "record A wrong alignment");
_Static_assert(sizeof(struct A_packed) == 4, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_packed) == 1, "record A wrong alignment");
_Static_assert(sizeof(struct A_required_alignment) == 5, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "record A wrong alignment");
_Static_assert(sizeof(struct A_size) == 6, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_size) == 1, "record A wrong alignment");
#endif
_Static_assert(sizeof(B) == 1, "record B wrong sizeof");
_Static_assert(_Alignof(B) == 1, "record B wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 2, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_alignment) == 1, "record B wrong alignment");
_Static_assert(sizeof(struct B_packed) == 1, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_packed) == 1, "record B wrong alignment");
_Static_assert(sizeof(struct B_required_alignment) == 2, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "record B wrong alignment");
_Static_assert(sizeof(struct B_size) == 3, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_size) == 1, "record B wrong alignment");
#endif
_Static_assert(sizeof(C) == 1, "record C wrong sizeof");
_Static_assert(_Alignof(C) == 1, "record C wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 2, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_alignment) == 1, "record C wrong alignment");
_Static_assert(sizeof(struct C_packed) == 1, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_packed) == 1, "record C wrong alignment");
_Static_assert(sizeof(struct C_required_alignment) == 2, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "record C wrong alignment");
_Static_assert(sizeof(struct C_size) == 3, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_size) == 1, "record C wrong alignment");
#endif
_Static_assert(sizeof(D) == 1, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 1, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 2, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_packed) == 1, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 2, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_size) == 3, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_size) == 1, "record D wrong alignment");
#endif
_Static_assert(sizeof(E) == 2, "record E wrong sizeof");
_Static_assert(_Alignof(E) == 1, "record E wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 3, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_alignment) == 1, "record E wrong alignment");
_Static_assert(sizeof(struct E_packed) == 2, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_packed) == 1, "record E wrong alignment");
_Static_assert(sizeof(struct E_required_alignment) == 3, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "record E wrong alignment");
_Static_assert(sizeof(struct E_size) == 4, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_size) == 1, "record E wrong alignment");
#endif
_Static_assert(sizeof(F) == 2, "record F wrong sizeof");
_Static_assert(_Alignof(F) == 1, "record F wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 3, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_alignment) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_packed) == 2, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_packed) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_required_alignment) == 3, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_size) == 4, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_size) == 1, "record F wrong alignment");
#endif
_Static_assert(sizeof(G) == 2, "record G wrong sizeof");
_Static_assert(_Alignof(G) == 1, "record G wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 3, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_alignment) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_packed) == 2, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_packed) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_required_alignment) == 3, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_size) == 4, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_size) == 1, "record G wrong alignment");
#endif
#elif defined(AVR_UNKNOWN_UNKNOWN) 
_Static_assert(sizeof(A) == 2, "record A wrong sizeof");
_Static_assert(_Alignof(A) == 1, "record A wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 3, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_alignment) == 1, "record A wrong alignment");
_Static_assert(sizeof(struct A_packed) == 2, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_packed) == 1, "record A wrong alignment");
_Static_assert(sizeof(struct A_required_alignment) == 3, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "record A wrong alignment");
_Static_assert(sizeof(struct A_size) == 4, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_size) == 1, "record A wrong alignment");
#endif
_Static_assert(sizeof(B) == 1, "record B wrong sizeof");
_Static_assert(_Alignof(B) == 1, "record B wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 2, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_alignment) == 1, "record B wrong alignment");
_Static_assert(sizeof(struct B_packed) == 1, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_packed) == 1, "record B wrong alignment");
_Static_assert(sizeof(struct B_required_alignment) == 2, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "record B wrong alignment");
_Static_assert(sizeof(struct B_size) == 3, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_size) == 1, "record B wrong alignment");
#endif
_Static_assert(sizeof(C) == 1, "record C wrong sizeof");
_Static_assert(_Alignof(C) == 1, "record C wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 2, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_alignment) == 1, "record C wrong alignment");
_Static_assert(sizeof(struct C_packed) == 1, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_packed) == 1, "record C wrong alignment");
_Static_assert(sizeof(struct C_required_alignment) == 2, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "record C wrong alignment");
_Static_assert(sizeof(struct C_size) == 3, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_size) == 1, "record C wrong alignment");
#endif
_Static_assert(sizeof(D) == 1, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 1, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 2, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_packed) == 1, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 2, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_size) == 3, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_size) == 1, "record D wrong alignment");
#endif
_Static_assert(sizeof(E) == 2, "record E wrong sizeof");
_Static_assert(_Alignof(E) == 1, "record E wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 3, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_alignment) == 1, "record E wrong alignment");
_Static_assert(sizeof(struct E_packed) == 2, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_packed) == 1, "record E wrong alignment");
_Static_assert(sizeof(struct E_required_alignment) == 3, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "record E wrong alignment");
_Static_assert(sizeof(struct E_size) == 4, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_size) == 1, "record E wrong alignment");
#endif
_Static_assert(sizeof(F) == 2, "record F wrong sizeof");
_Static_assert(_Alignof(F) == 1, "record F wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 3, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_alignment) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_packed) == 2, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_packed) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_required_alignment) == 3, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_size) == 4, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_size) == 1, "record F wrong alignment");
#endif
_Static_assert(sizeof(G) == 2, "record G wrong sizeof");
_Static_assert(_Alignof(G) == 1, "record G wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 3, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_alignment) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_packed) == 2, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_packed) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_required_alignment) == 3, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_size) == 4, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_size) == 1, "record G wrong alignment");
#endif
#elif defined(MSP430_NONE_ELF) 
_Static_assert(sizeof(A) == 2, "record A wrong sizeof");
_Static_assert(_Alignof(A) == 1, "record A wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 3, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_alignment) == 1, "record A wrong alignment");
_Static_assert(sizeof(struct A_packed) == 2, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_packed) == 1, "record A wrong alignment");
_Static_assert(sizeof(struct A_required_alignment) == 3, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "record A wrong alignment");
_Static_assert(sizeof(struct A_size) == 4, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_size) == 1, "record A wrong alignment");
#endif
_Static_assert(sizeof(B) == 1, "record B wrong sizeof");
_Static_assert(_Alignof(B) == 1, "record B wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 2, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_alignment) == 1, "record B wrong alignment");
_Static_assert(sizeof(struct B_packed) == 1, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_packed) == 1, "record B wrong alignment");
_Static_assert(sizeof(struct B_required_alignment) == 2, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "record B wrong alignment");
_Static_assert(sizeof(struct B_size) == 3, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_size) == 1, "record B wrong alignment");
#endif
_Static_assert(sizeof(C) == 1, "record C wrong sizeof");
_Static_assert(_Alignof(C) == 1, "record C wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 2, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_alignment) == 1, "record C wrong alignment");
_Static_assert(sizeof(struct C_packed) == 1, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_packed) == 1, "record C wrong alignment");
_Static_assert(sizeof(struct C_required_alignment) == 2, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "record C wrong alignment");
_Static_assert(sizeof(struct C_size) == 3, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_size) == 1, "record C wrong alignment");
#endif
_Static_assert(sizeof(D) == 1, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 1, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 2, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_packed) == 1, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 2, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_size) == 3, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_size) == 1, "record D wrong alignment");
#endif
_Static_assert(sizeof(E) == 2, "record E wrong sizeof");
_Static_assert(_Alignof(E) == 1, "record E wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 3, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_alignment) == 1, "record E wrong alignment");
_Static_assert(sizeof(struct E_packed) == 2, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_packed) == 1, "record E wrong alignment");
_Static_assert(sizeof(struct E_required_alignment) == 3, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "record E wrong alignment");
_Static_assert(sizeof(struct E_size) == 4, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_size) == 1, "record E wrong alignment");
#endif
_Static_assert(sizeof(F) == 2, "record F wrong sizeof");
_Static_assert(_Alignof(F) == 1, "record F wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 3, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_alignment) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_packed) == 2, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_packed) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_required_alignment) == 3, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_size) == 4, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_size) == 1, "record F wrong alignment");
#endif
_Static_assert(sizeof(G) == 2, "record G wrong sizeof");
_Static_assert(_Alignof(G) == 1, "record G wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 3, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_alignment) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_packed) == 2, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_packed) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_required_alignment) == 3, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_size) == 4, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_size) == 1, "record G wrong alignment");
#endif
#endif
