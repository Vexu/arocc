// SPDX-License-Identifier: GPL-3.0-or-later

// This test file is auto-generated. do not edit.
// This file is a derivative work from the test files found// in this repo : https://github.com/mahkoh/repr-c
// and is under the same licence as the original work.

typedef struct {
    long long a;
} A;
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

typedef struct {
    long long a:1;
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

typedef struct {
    char a:1;
    long long:0;
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

typedef struct {
    long long:0;
} D;
D var13;
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

typedef struct {
    char c;
    long long:0;
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

typedef struct {
    char c;
    int:0;
    long long:0;
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

typedef struct {
    int a:1 __attribute__((packed));
} G;
G var25;
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

typedef struct {
    int a:1 __attribute__((aligned(16))) __attribute__((packed));
} H;
H var29;
struct H_alignment {
    char a;
    H b;
};
struct H_alignment var30;
#pragma pack(1)
struct H_packed {
    H a;
};
#pragma pack()
struct H_required_alignment {
    char a;
    struct H_packed b;
};
struct H_required_alignment var31;
struct H_size {
    char a[sizeof(H)+1];
    char b;
};
struct H_size var32;

typedef union {
    long long a;
} A2;
A2 var33;
struct A2_alignment {
    char a;
    A2 b;
};
struct A2_alignment var34;
#pragma pack(1)
struct A2_packed {
    A2 a;
};
#pragma pack()
struct A2_required_alignment {
    char a;
    struct A2_packed b;
};
struct A2_required_alignment var35;
struct A2_size {
    char a[sizeof(A2)+1];
    char b;
};
struct A2_size var36;

typedef union {
    long long a:1;
} B2;
B2 var37;
struct B2_alignment {
    char a;
    B2 b;
};
struct B2_alignment var38;
#pragma pack(1)
struct B2_packed {
    B2 a;
};
#pragma pack()
struct B2_required_alignment {
    char a;
    struct B2_packed b;
};
struct B2_required_alignment var39;
struct B2_size {
    char a[sizeof(B2)+1];
    char b;
};
struct B2_size var40;

typedef union {
    char a:1;
    long long:0;
} C2;
C2 var41;
struct C2_alignment {
    char a;
    C2 b;
};
struct C2_alignment var42;
#pragma pack(1)
struct C2_packed {
    C2 a;
};
#pragma pack()
struct C2_required_alignment {
    char a;
    struct C2_packed b;
};
struct C2_required_alignment var43;
struct C2_size {
    char a[sizeof(C2)+1];
    char b;
};
struct C2_size var44;

typedef union {
    long long:0;
} D2;
D2 var45;
struct D2_alignment {
    char a;
    D2 b;
};
struct D2_alignment var46;
#pragma pack(1)
struct D2_packed {
    D2 a;
};
#pragma pack()
struct D2_required_alignment {
    char a;
    struct D2_packed b;
};
struct D2_required_alignment var47;
struct D2_size {
    char a[sizeof(D2)+1];
    char b;
};
struct D2_size var48;

typedef union {
    char c;
    long long:0;
} E2;
E2 var49;
struct E2_alignment {
    char a;
    E2 b;
};
struct E2_alignment var50;
#pragma pack(1)
struct E2_packed {
    E2 a;
};
#pragma pack()
struct E2_required_alignment {
    char a;
    struct E2_packed b;
};
struct E2_required_alignment var51;
struct E2_size {
    char a[sizeof(E2)+1];
    char b;
};
struct E2_size var52;

typedef union {
    char c;
    int:0;
    long long:0;
} F2;
F2 var53;
struct F2_alignment {
    char a;
    F2 b;
};
struct F2_alignment var54;
#pragma pack(1)
struct F2_packed {
    F2 a;
};
#pragma pack()
struct F2_required_alignment {
    char a;
    struct F2_packed b;
};
struct F2_required_alignment var55;
struct F2_size {
    char a[sizeof(F2)+1];
    char b;
};
struct F2_size var56;

typedef union {
    int a:1 __attribute__((packed));
} G2;
G2 var57;
struct G2_alignment {
    char a;
    G2 b;
};
struct G2_alignment var58;
#pragma pack(1)
struct G2_packed {
    G2 a;
};
#pragma pack()
struct G2_required_alignment {
    char a;
    struct G2_packed b;
};
struct G2_required_alignment var59;
struct G2_size {
    char a[sizeof(G2)+1];
    char b;
};
struct G2_size var60;

typedef union {
    int a:1 __attribute__((aligned(16))) __attribute__((packed));
} H2;
H2 var61;
struct H2_alignment {
    char a;
    H2 b;
};
struct H2_alignment var62;
#pragma pack(1)
struct H2_packed {
    H2 a;
};
#pragma pack()
struct H2_required_alignment {
    char a;
    struct H2_packed b;
};
struct H2_required_alignment var63;
struct H2_size {
    char a[sizeof(H2)+1];
    char b;
};
struct H2_size var64;


#if defined(AARCH64_APPLE_MACOSX) ||  defined(ARM64_APPLE_IOS) ||  defined(ARM64_APPLE_IOS_MACABI) ||  defined(ARM64_APPLE_TVOS) ||  \
 defined(HEXAGON_UNKNOWN_LINUX_MUSL) ||  defined(MIPS64EL_UNKNOWN_LINUX_GNUABI64) ||  defined(MIPS64EL_UNKNOWN_LINUX_MUSL) ||  defined(MIPS64_UNKNOWN_LINUX_GNUABI64) ||  \
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
 defined(X8664_FUCHSIA) ||  defined(X8664_LINUX_ANDROID) ||  defined(X8664_PC_SOLARIS) ||  defined(X8664_RUMPRUN_NETBSD) ||  defined(X8664_UNKNOWN_DRAGONFLY) ||  \
 defined(X8664_UNKNOWN_FREEBSD) ||  defined(X8664_UNKNOWN_HAIKU) ||  defined(X8664_UNKNOWN_HERMIT) ||  defined(X8664_UNKNOWN_L4RE_UCLIBC) ||  \
 defined(X8664_UNKNOWN_LINUX_GNUX32) ||  defined(X8664_UNKNOWN_LINUX_GNU) ||  defined(X8664_UNKNOWN_LINUX_MUSL) ||  defined(X8664_UNKNOWN_NETBSD) ||  \
 defined(X8664_UNKNOWN_OPENBSD) ||  defined(X8664_UNKNOWN_REDOX) 
_Static_assert(sizeof(A) == 8, "record A wrong sizeof");
_Static_assert(_Alignof(A) == 8, "record A wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 16, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_alignment) == 8, "record A wrong alignment");
_Static_assert(sizeof(struct A_packed) == 8, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_packed) == 1, "record A wrong alignment");
_Static_assert(sizeof(struct A_required_alignment) == 9, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "record A wrong alignment");
_Static_assert(sizeof(struct A_size) == 10, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_size) == 1, "record A wrong alignment");
#endif
_Static_assert(sizeof(B) == 8, "record B wrong sizeof");
_Static_assert(_Alignof(B) == 8, "record B wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 16, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_alignment) == 8, "record B wrong alignment");
_Static_assert(sizeof(struct B_packed) == 8, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_packed) == 1, "record B wrong alignment");
_Static_assert(sizeof(struct B_required_alignment) == 9, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "record B wrong alignment");
_Static_assert(sizeof(struct B_size) == 10, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_size) == 1, "record B wrong alignment");
#endif
_Static_assert(sizeof(C) == 8, "record C wrong sizeof");
_Static_assert(_Alignof(C) == 1, "record C wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 9, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_alignment) == 1, "record C wrong alignment");
_Static_assert(sizeof(struct C_packed) == 8, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_packed) == 1, "record C wrong alignment");
_Static_assert(sizeof(struct C_required_alignment) == 9, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "record C wrong alignment");
_Static_assert(sizeof(struct C_size) == 10, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_size) == 1, "record C wrong alignment");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(D) == 0, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 1, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 1, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_packed) == 0, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 1, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_size) == 2, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_size) == 1, "record D wrong alignment");
#endif
_Static_assert(sizeof(E) == 8, "record E wrong sizeof");
_Static_assert(_Alignof(E) == 1, "record E wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 9, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_alignment) == 1, "record E wrong alignment");
_Static_assert(sizeof(struct E_packed) == 8, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_packed) == 1, "record E wrong alignment");
_Static_assert(sizeof(struct E_required_alignment) == 9, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "record E wrong alignment");
_Static_assert(sizeof(struct E_size) == 10, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_size) == 1, "record E wrong alignment");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(F) == 8, "record F wrong sizeof");
_Static_assert(_Alignof(F) == 1, "record F wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 9, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_alignment) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_packed) == 8, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_packed) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_required_alignment) == 9, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_size) == 10, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_size) == 1, "record F wrong alignment");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(G) == 1, "record G wrong sizeof");
_Static_assert(_Alignof(G) == 1, "record G wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 2, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_alignment) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_packed) == 1, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_packed) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_required_alignment) == 2, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_size) == 3, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_size) == 1, "record G wrong alignment");
#endif
_Static_assert(sizeof(H) == 16, "record H wrong sizeof");
_Static_assert(_Alignof(H) == 16, "record H wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 32, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_alignment) == 16, "record H wrong alignment");
_Static_assert(sizeof(struct H_packed) == 16, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_packed) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_required_alignment) == 17, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_size) == 18, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_size) == 1, "record H wrong alignment");
#endif
_Static_assert(sizeof(A2) == 8, "record A2 wrong sizeof");
_Static_assert(_Alignof(A2) == 8, "record A2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A2_alignment) == 16, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_alignment) == 8, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_packed) == 8, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_packed) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_required_alignment) == 9, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_required_alignment) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_size) == 10, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_size) == 1, "record A2 wrong alignment");
#endif
_Static_assert(sizeof(B2) == 8, "record B2 wrong sizeof");
_Static_assert(_Alignof(B2) == 8, "record B2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B2_alignment) == 16, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_alignment) == 8, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_packed) == 8, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_packed) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_required_alignment) == 9, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_required_alignment) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_size) == 10, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_size) == 1, "record B2 wrong alignment");
#endif
_Static_assert(sizeof(C2) == 1, "record C2 wrong sizeof");
_Static_assert(_Alignof(C2) == 1, "record C2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C2_alignment) == 2, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_alignment) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_packed) == 1, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_packed) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_required_alignment) == 2, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_required_alignment) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_size) == 3, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_size) == 1, "record C2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(D2) == 0, "record D2 wrong sizeof");
_Static_assert(_Alignof(D2) == 1, "record D2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D2_alignment) == 1, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_alignment) == 1, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_packed) == 0, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_packed) == 1, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_required_alignment) == 1, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_required_alignment) == 1, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_size) == 2, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_size) == 1, "record D2 wrong alignment");
#endif
_Static_assert(sizeof(E2) == 1, "record E2 wrong sizeof");
_Static_assert(_Alignof(E2) == 1, "record E2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E2_alignment) == 2, "record E2 wrong sizeof");
_Static_assert(_Alignof(struct E2_alignment) == 1, "record E2 wrong alignment");
_Static_assert(sizeof(struct E2_packed) == 1, "record E2 wrong sizeof");
_Static_assert(_Alignof(struct E2_packed) == 1, "record E2 wrong alignment");
_Static_assert(sizeof(struct E2_required_alignment) == 2, "record E2 wrong sizeof");
_Static_assert(_Alignof(struct E2_required_alignment) == 1, "record E2 wrong alignment");
_Static_assert(sizeof(struct E2_size) == 3, "record E2 wrong sizeof");
_Static_assert(_Alignof(struct E2_size) == 1, "record E2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(F2) == 1, "record F2 wrong sizeof");
_Static_assert(_Alignof(F2) == 1, "record F2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F2_alignment) == 2, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_alignment) == 1, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_packed) == 1, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_packed) == 1, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_required_alignment) == 2, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_required_alignment) == 1, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_size) == 3, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_size) == 1, "record F2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(G2) == 1, "record G2 wrong sizeof");
_Static_assert(_Alignof(G2) == 1, "record G2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G2_alignment) == 2, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_alignment) == 1, "record G2 wrong alignment");
_Static_assert(sizeof(struct G2_packed) == 1, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_packed) == 1, "record G2 wrong alignment");
_Static_assert(sizeof(struct G2_required_alignment) == 2, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_required_alignment) == 1, "record G2 wrong alignment");
_Static_assert(sizeof(struct G2_size) == 3, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_size) == 1, "record G2 wrong alignment");
#endif
_Static_assert(sizeof(H2) == 16, "record H2 wrong sizeof");
_Static_assert(_Alignof(H2) == 16, "record H2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H2_alignment) == 32, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_alignment) == 16, "record H2 wrong alignment");
_Static_assert(sizeof(struct H2_packed) == 16, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_packed) == 1, "record H2 wrong alignment");
_Static_assert(sizeof(struct H2_required_alignment) == 17, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_required_alignment) == 1, "record H2 wrong alignment");
_Static_assert(sizeof(struct H2_size) == 18, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_size) == 1, "record H2 wrong alignment");
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
_Static_assert(sizeof(A) == 8, "record A wrong sizeof");
_Static_assert(_Alignof(A) == 8, "record A wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 16, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_alignment) == 8, "record A wrong alignment");
_Static_assert(sizeof(struct A_packed) == 8, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_packed) == 1, "record A wrong alignment");
_Static_assert(sizeof(struct A_required_alignment) == 9, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "record A wrong alignment");
_Static_assert(sizeof(struct A_size) == 10, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_size) == 1, "record A wrong alignment");
#endif
_Static_assert(sizeof(B) == 8, "record B wrong sizeof");
_Static_assert(_Alignof(B) == 8, "record B wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 16, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_alignment) == 8, "record B wrong alignment");
_Static_assert(sizeof(struct B_packed) == 8, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_packed) == 1, "record B wrong alignment");
_Static_assert(sizeof(struct B_required_alignment) == 9, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "record B wrong alignment");
_Static_assert(sizeof(struct B_size) == 10, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_size) == 1, "record B wrong alignment");
#endif
_Static_assert(sizeof(C) == 8, "record C wrong sizeof");
_Static_assert(_Alignof(C) == 8, "record C wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 16, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_alignment) == 8, "record C wrong alignment");
_Static_assert(sizeof(struct C_packed) == 8, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_packed) == 1, "record C wrong alignment");
_Static_assert(sizeof(struct C_required_alignment) == 9, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "record C wrong alignment");
_Static_assert(sizeof(struct C_size) == 10, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_size) == 1, "record C wrong alignment");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(D) == 0, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 8, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 8, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 8, "record D wrong alignment");
_Static_assert(sizeof(struct D_packed) == 0, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 1, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_size) == 2, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_size) == 1, "record D wrong alignment");
#endif
_Static_assert(sizeof(E) == 8, "record E wrong sizeof");
_Static_assert(_Alignof(E) == 8, "record E wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 16, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_alignment) == 8, "record E wrong alignment");
_Static_assert(sizeof(struct E_packed) == 8, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_packed) == 1, "record E wrong alignment");
_Static_assert(sizeof(struct E_required_alignment) == 9, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "record E wrong alignment");
_Static_assert(sizeof(struct E_size) == 10, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_size) == 1, "record E wrong alignment");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(F) == 8, "record F wrong sizeof");
_Static_assert(_Alignof(F) == 8, "record F wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 16, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_alignment) == 8, "record F wrong alignment");
_Static_assert(sizeof(struct F_packed) == 8, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_packed) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_required_alignment) == 9, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_size) == 10, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_size) == 1, "record F wrong alignment");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(G) == 1, "record G wrong sizeof");
_Static_assert(_Alignof(G) == 1, "record G wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 2, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_alignment) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_packed) == 1, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_packed) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_required_alignment) == 2, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_size) == 3, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_size) == 1, "record G wrong alignment");
#endif
_Static_assert(sizeof(H) == 16, "record H wrong sizeof");
_Static_assert(_Alignof(H) == 16, "record H wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 32, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_alignment) == 16, "record H wrong alignment");
_Static_assert(sizeof(struct H_packed) == 16, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_packed) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_required_alignment) == 17, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_size) == 18, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_size) == 1, "record H wrong alignment");
#endif
_Static_assert(sizeof(A2) == 8, "record A2 wrong sizeof");
_Static_assert(_Alignof(A2) == 8, "record A2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A2_alignment) == 16, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_alignment) == 8, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_packed) == 8, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_packed) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_required_alignment) == 9, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_required_alignment) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_size) == 10, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_size) == 1, "record A2 wrong alignment");
#endif
_Static_assert(sizeof(B2) == 8, "record B2 wrong sizeof");
_Static_assert(_Alignof(B2) == 8, "record B2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B2_alignment) == 16, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_alignment) == 8, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_packed) == 8, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_packed) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_required_alignment) == 9, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_required_alignment) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_size) == 10, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_size) == 1, "record B2 wrong alignment");
#endif
_Static_assert(sizeof(C2) == 8, "record C2 wrong sizeof");
_Static_assert(_Alignof(C2) == 8, "record C2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C2_alignment) == 16, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_alignment) == 8, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_packed) == 8, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_packed) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_required_alignment) == 9, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_required_alignment) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_size) == 10, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_size) == 1, "record C2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(D2) == 0, "record D2 wrong sizeof");
_Static_assert(_Alignof(D2) == 8, "record D2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D2_alignment) == 8, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_alignment) == 8, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_packed) == 0, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_packed) == 1, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_required_alignment) == 1, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_required_alignment) == 1, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_size) == 2, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_size) == 1, "record D2 wrong alignment");
#endif
_Static_assert(sizeof(E2) == 8, "record E2 wrong sizeof");
_Static_assert(_Alignof(E2) == 8, "record E2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E2_alignment) == 16, "record E2 wrong sizeof");
_Static_assert(_Alignof(struct E2_alignment) == 8, "record E2 wrong alignment");
_Static_assert(sizeof(struct E2_packed) == 8, "record E2 wrong sizeof");
_Static_assert(_Alignof(struct E2_packed) == 1, "record E2 wrong alignment");
_Static_assert(sizeof(struct E2_required_alignment) == 9, "record E2 wrong sizeof");
_Static_assert(_Alignof(struct E2_required_alignment) == 1, "record E2 wrong alignment");
_Static_assert(sizeof(struct E2_size) == 10, "record E2 wrong sizeof");
_Static_assert(_Alignof(struct E2_size) == 1, "record E2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(F2) == 8, "record F2 wrong sizeof");
_Static_assert(_Alignof(F2) == 8, "record F2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F2_alignment) == 16, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_alignment) == 8, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_packed) == 8, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_packed) == 1, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_required_alignment) == 9, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_required_alignment) == 1, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_size) == 10, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_size) == 1, "record F2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(G2) == 1, "record G2 wrong sizeof");
_Static_assert(_Alignof(G2) == 1, "record G2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G2_alignment) == 2, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_alignment) == 1, "record G2 wrong alignment");
_Static_assert(sizeof(struct G2_packed) == 1, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_packed) == 1, "record G2 wrong alignment");
_Static_assert(sizeof(struct G2_required_alignment) == 2, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_required_alignment) == 1, "record G2 wrong alignment");
_Static_assert(sizeof(struct G2_size) == 3, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_size) == 1, "record G2 wrong alignment");
#endif
_Static_assert(sizeof(H2) == 16, "record H2 wrong sizeof");
_Static_assert(_Alignof(H2) == 16, "record H2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H2_alignment) == 32, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_alignment) == 16, "record H2 wrong alignment");
_Static_assert(sizeof(struct H2_packed) == 16, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_packed) == 1, "record H2 wrong alignment");
_Static_assert(sizeof(struct H2_required_alignment) == 17, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_required_alignment) == 1, "record H2 wrong alignment");
_Static_assert(sizeof(struct H2_size) == 18, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_size) == 1, "record H2 wrong alignment");
#endif
#elif defined(ARMV7_APPLE_IOS) ||  defined(ARMV7S_APPLE_IOS) 
_Static_assert(sizeof(A) == 8, "record A wrong sizeof");
_Static_assert(_Alignof(A) == 4, "record A wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 12, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_alignment) == 4, "record A wrong alignment");
_Static_assert(sizeof(struct A_packed) == 8, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_packed) == 1, "record A wrong alignment");
_Static_assert(sizeof(struct A_required_alignment) == 9, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "record A wrong alignment");
_Static_assert(sizeof(struct A_size) == 10, "record A wrong sizeof");
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
_Static_assert(sizeof(C) == 4, "record C wrong sizeof");
_Static_assert(_Alignof(C) == 4, "record C wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 8, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_alignment) == 4, "record C wrong alignment");
_Static_assert(sizeof(struct C_packed) == 4, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_packed) == 1, "record C wrong alignment");
_Static_assert(sizeof(struct C_required_alignment) == 5, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "record C wrong alignment");
_Static_assert(sizeof(struct C_size) == 6, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_size) == 1, "record C wrong alignment");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(D) == 0, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 4, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 4, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 4, "record D wrong alignment");
_Static_assert(sizeof(struct D_packed) == 0, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 1, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_size) == 2, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_size) == 1, "record D wrong alignment");
#endif
_Static_assert(sizeof(E) == 4, "record E wrong sizeof");
_Static_assert(_Alignof(E) == 4, "record E wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 8, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_alignment) == 4, "record E wrong alignment");
_Static_assert(sizeof(struct E_packed) == 4, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_packed) == 1, "record E wrong alignment");
_Static_assert(sizeof(struct E_required_alignment) == 5, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "record E wrong alignment");
_Static_assert(sizeof(struct E_size) == 6, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_size) == 1, "record E wrong alignment");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(F) == 4, "record F wrong sizeof");
_Static_assert(_Alignof(F) == 4, "record F wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 8, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_alignment) == 4, "record F wrong alignment");
_Static_assert(sizeof(struct F_packed) == 4, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_packed) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_required_alignment) == 5, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_size) == 6, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_size) == 1, "record F wrong alignment");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(G) == 1, "record G wrong sizeof");
_Static_assert(_Alignof(G) == 1, "record G wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 2, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_alignment) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_packed) == 1, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_packed) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_required_alignment) == 2, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_size) == 3, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_size) == 1, "record G wrong alignment");
#endif
_Static_assert(sizeof(H) == 16, "record H wrong sizeof");
_Static_assert(_Alignof(H) == 16, "record H wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 32, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_alignment) == 16, "record H wrong alignment");
_Static_assert(sizeof(struct H_packed) == 16, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_packed) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_required_alignment) == 17, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_size) == 18, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_size) == 1, "record H wrong alignment");
#endif
_Static_assert(sizeof(A2) == 8, "record A2 wrong sizeof");
_Static_assert(_Alignof(A2) == 4, "record A2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A2_alignment) == 12, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_alignment) == 4, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_packed) == 8, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_packed) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_required_alignment) == 9, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_required_alignment) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_size) == 10, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_size) == 1, "record A2 wrong alignment");
#endif
_Static_assert(sizeof(B2) == 1, "record B2 wrong sizeof");
_Static_assert(_Alignof(B2) == 1, "record B2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B2_alignment) == 2, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_alignment) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_packed) == 1, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_packed) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_required_alignment) == 2, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_required_alignment) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_size) == 3, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_size) == 1, "record B2 wrong alignment");
#endif
_Static_assert(sizeof(C2) == 4, "record C2 wrong sizeof");
_Static_assert(_Alignof(C2) == 4, "record C2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C2_alignment) == 8, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_alignment) == 4, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_packed) == 4, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_packed) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_required_alignment) == 5, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_required_alignment) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_size) == 6, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_size) == 1, "record C2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(D2) == 0, "record D2 wrong sizeof");
_Static_assert(_Alignof(D2) == 4, "record D2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D2_alignment) == 4, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_alignment) == 4, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_packed) == 0, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_packed) == 1, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_required_alignment) == 1, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_required_alignment) == 1, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_size) == 2, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_size) == 1, "record D2 wrong alignment");
#endif
_Static_assert(sizeof(E2) == 4, "record E2 wrong sizeof");
_Static_assert(_Alignof(E2) == 4, "record E2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E2_alignment) == 8, "record E2 wrong sizeof");
_Static_assert(_Alignof(struct E2_alignment) == 4, "record E2 wrong alignment");
_Static_assert(sizeof(struct E2_packed) == 4, "record E2 wrong sizeof");
_Static_assert(_Alignof(struct E2_packed) == 1, "record E2 wrong alignment");
_Static_assert(sizeof(struct E2_required_alignment) == 5, "record E2 wrong sizeof");
_Static_assert(_Alignof(struct E2_required_alignment) == 1, "record E2 wrong alignment");
_Static_assert(sizeof(struct E2_size) == 6, "record E2 wrong sizeof");
_Static_assert(_Alignof(struct E2_size) == 1, "record E2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(F2) == 4, "record F2 wrong sizeof");
_Static_assert(_Alignof(F2) == 4, "record F2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F2_alignment) == 8, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_alignment) == 4, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_packed) == 4, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_packed) == 1, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_required_alignment) == 5, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_required_alignment) == 1, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_size) == 6, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_size) == 1, "record F2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(G2) == 1, "record G2 wrong sizeof");
_Static_assert(_Alignof(G2) == 1, "record G2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G2_alignment) == 2, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_alignment) == 1, "record G2 wrong alignment");
_Static_assert(sizeof(struct G2_packed) == 1, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_packed) == 1, "record G2 wrong alignment");
_Static_assert(sizeof(struct G2_required_alignment) == 2, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_required_alignment) == 1, "record G2 wrong alignment");
_Static_assert(sizeof(struct G2_size) == 3, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_size) == 1, "record G2 wrong alignment");
#endif
_Static_assert(sizeof(H2) == 16, "record H2 wrong sizeof");
_Static_assert(_Alignof(H2) == 16, "record H2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H2_alignment) == 32, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_alignment) == 16, "record H2 wrong alignment");
_Static_assert(sizeof(struct H2_packed) == 16, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_packed) == 1, "record H2 wrong alignment");
_Static_assert(sizeof(struct H2_required_alignment) == 17, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_required_alignment) == 1, "record H2 wrong alignment");
_Static_assert(sizeof(struct H2_size) == 18, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_size) == 1, "record H2 wrong alignment");
#endif
#elif defined(AVR_UNKNOWN_UNKNOWN) 
_Static_assert(sizeof(A) == 8, "record A wrong sizeof");
_Static_assert(_Alignof(A) == 1, "record A wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 9, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_alignment) == 1, "record A wrong alignment");
_Static_assert(sizeof(struct A_packed) == 8, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_packed) == 1, "record A wrong alignment");
_Static_assert(sizeof(struct A_required_alignment) == 9, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "record A wrong alignment");
_Static_assert(sizeof(struct A_size) == 10, "record A wrong sizeof");
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
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(D) == 0, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 1, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 1, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_packed) == 0, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 1, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_size) == 2, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_size) == 1, "record D wrong alignment");
#endif
_Static_assert(sizeof(E) == 1, "record E wrong sizeof");
_Static_assert(_Alignof(E) == 1, "record E wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 2, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_alignment) == 1, "record E wrong alignment");
_Static_assert(sizeof(struct E_packed) == 1, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_packed) == 1, "record E wrong alignment");
_Static_assert(sizeof(struct E_required_alignment) == 2, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "record E wrong alignment");
_Static_assert(sizeof(struct E_size) == 3, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_size) == 1, "record E wrong alignment");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(F) == 1, "record F wrong sizeof");
_Static_assert(_Alignof(F) == 1, "record F wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 2, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_alignment) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_packed) == 1, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_packed) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_required_alignment) == 2, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_size) == 3, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_size) == 1, "record F wrong alignment");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(G) == 1, "record G wrong sizeof");
_Static_assert(_Alignof(G) == 1, "record G wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 2, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_alignment) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_packed) == 1, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_packed) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_required_alignment) == 2, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_size) == 3, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_size) == 1, "record G wrong alignment");
#endif
_Static_assert(sizeof(H) == 16, "record H wrong sizeof");
_Static_assert(_Alignof(H) == 16, "record H wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 32, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_alignment) == 16, "record H wrong alignment");
_Static_assert(sizeof(struct H_packed) == 16, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_packed) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_required_alignment) == 17, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_size) == 18, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_size) == 1, "record H wrong alignment");
#endif
_Static_assert(sizeof(A2) == 8, "record A2 wrong sizeof");
_Static_assert(_Alignof(A2) == 1, "record A2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A2_alignment) == 9, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_alignment) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_packed) == 8, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_packed) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_required_alignment) == 9, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_required_alignment) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_size) == 10, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_size) == 1, "record A2 wrong alignment");
#endif
_Static_assert(sizeof(B2) == 1, "record B2 wrong sizeof");
_Static_assert(_Alignof(B2) == 1, "record B2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B2_alignment) == 2, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_alignment) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_packed) == 1, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_packed) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_required_alignment) == 2, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_required_alignment) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_size) == 3, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_size) == 1, "record B2 wrong alignment");
#endif
_Static_assert(sizeof(C2) == 1, "record C2 wrong sizeof");
_Static_assert(_Alignof(C2) == 1, "record C2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C2_alignment) == 2, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_alignment) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_packed) == 1, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_packed) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_required_alignment) == 2, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_required_alignment) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_size) == 3, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_size) == 1, "record C2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(D2) == 0, "record D2 wrong sizeof");
_Static_assert(_Alignof(D2) == 1, "record D2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D2_alignment) == 1, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_alignment) == 1, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_packed) == 0, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_packed) == 1, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_required_alignment) == 1, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_required_alignment) == 1, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_size) == 2, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_size) == 1, "record D2 wrong alignment");
#endif
_Static_assert(sizeof(E2) == 1, "record E2 wrong sizeof");
_Static_assert(_Alignof(E2) == 1, "record E2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E2_alignment) == 2, "record E2 wrong sizeof");
_Static_assert(_Alignof(struct E2_alignment) == 1, "record E2 wrong alignment");
_Static_assert(sizeof(struct E2_packed) == 1, "record E2 wrong sizeof");
_Static_assert(_Alignof(struct E2_packed) == 1, "record E2 wrong alignment");
_Static_assert(sizeof(struct E2_required_alignment) == 2, "record E2 wrong sizeof");
_Static_assert(_Alignof(struct E2_required_alignment) == 1, "record E2 wrong alignment");
_Static_assert(sizeof(struct E2_size) == 3, "record E2 wrong sizeof");
_Static_assert(_Alignof(struct E2_size) == 1, "record E2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(F2) == 1, "record F2 wrong sizeof");
_Static_assert(_Alignof(F2) == 1, "record F2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F2_alignment) == 2, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_alignment) == 1, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_packed) == 1, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_packed) == 1, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_required_alignment) == 2, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_required_alignment) == 1, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_size) == 3, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_size) == 1, "record F2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(G2) == 1, "record G2 wrong sizeof");
_Static_assert(_Alignof(G2) == 1, "record G2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G2_alignment) == 2, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_alignment) == 1, "record G2 wrong alignment");
_Static_assert(sizeof(struct G2_packed) == 1, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_packed) == 1, "record G2 wrong alignment");
_Static_assert(sizeof(struct G2_required_alignment) == 2, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_required_alignment) == 1, "record G2 wrong alignment");
_Static_assert(sizeof(struct G2_size) == 3, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_size) == 1, "record G2 wrong alignment");
#endif
_Static_assert(sizeof(H2) == 16, "record H2 wrong sizeof");
_Static_assert(_Alignof(H2) == 16, "record H2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H2_alignment) == 32, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_alignment) == 16, "record H2 wrong alignment");
_Static_assert(sizeof(struct H2_packed) == 16, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_packed) == 1, "record H2 wrong alignment");
_Static_assert(sizeof(struct H2_required_alignment) == 17, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_required_alignment) == 1, "record H2 wrong alignment");
_Static_assert(sizeof(struct H2_size) == 18, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_size) == 1, "record H2 wrong alignment");
#endif
#elif defined(I386_APPLE_IOS) ||  defined(I586_UNKNOWN_LINUX_GNU) ||  defined(I586_UNKNOWN_LINUX_MUSL) ||  defined(I686_APPLE_MACOSX) ||  \
 defined(I686_LINUX_ANDROID) ||  defined(I686_UNKNOWN_FREEBSD) ||  defined(I686_UNKNOWN_HAIKU) ||  defined(I686_UNKNOWN_LINUX_GNU) ||  \
 defined(I686_UNKNOWN_LINUX_MUSL) ||  defined(I686_UNKNOWN_NETBSDELF) ||  defined(I686_UNKNOWN_OPENBSD) 
_Static_assert(sizeof(A) == 8, "record A wrong sizeof");
_Static_assert(_Alignof(A) == 4, "record A wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 12, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_alignment) == 4, "record A wrong alignment");
_Static_assert(sizeof(struct A_packed) == 8, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_packed) == 1, "record A wrong alignment");
_Static_assert(sizeof(struct A_required_alignment) == 9, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "record A wrong alignment");
_Static_assert(sizeof(struct A_size) == 10, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_size) == 1, "record A wrong alignment");
#endif
_Static_assert(sizeof(B) == 4, "record B wrong sizeof");
_Static_assert(_Alignof(B) == 4, "record B wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 8, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_alignment) == 4, "record B wrong alignment");
_Static_assert(sizeof(struct B_packed) == 4, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_packed) == 1, "record B wrong alignment");
_Static_assert(sizeof(struct B_required_alignment) == 5, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "record B wrong alignment");
_Static_assert(sizeof(struct B_size) == 6, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_size) == 1, "record B wrong alignment");
#endif
_Static_assert(sizeof(C) == 4, "record C wrong sizeof");
_Static_assert(_Alignof(C) == 1, "record C wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 5, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_alignment) == 1, "record C wrong alignment");
_Static_assert(sizeof(struct C_packed) == 4, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_packed) == 1, "record C wrong alignment");
_Static_assert(sizeof(struct C_required_alignment) == 5, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "record C wrong alignment");
_Static_assert(sizeof(struct C_size) == 6, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_size) == 1, "record C wrong alignment");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(D) == 0, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 1, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 1, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_packed) == 0, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 1, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_size) == 2, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_size) == 1, "record D wrong alignment");
#endif
_Static_assert(sizeof(E) == 4, "record E wrong sizeof");
_Static_assert(_Alignof(E) == 1, "record E wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 5, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_alignment) == 1, "record E wrong alignment");
_Static_assert(sizeof(struct E_packed) == 4, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_packed) == 1, "record E wrong alignment");
_Static_assert(sizeof(struct E_required_alignment) == 5, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "record E wrong alignment");
_Static_assert(sizeof(struct E_size) == 6, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_size) == 1, "record E wrong alignment");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(F) == 4, "record F wrong sizeof");
_Static_assert(_Alignof(F) == 1, "record F wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 5, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_alignment) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_packed) == 4, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_packed) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_required_alignment) == 5, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_size) == 6, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_size) == 1, "record F wrong alignment");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(G) == 1, "record G wrong sizeof");
_Static_assert(_Alignof(G) == 1, "record G wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 2, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_alignment) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_packed) == 1, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_packed) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_required_alignment) == 2, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_size) == 3, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_size) == 1, "record G wrong alignment");
#endif
_Static_assert(sizeof(H) == 16, "record H wrong sizeof");
_Static_assert(_Alignof(H) == 16, "record H wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 32, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_alignment) == 16, "record H wrong alignment");
_Static_assert(sizeof(struct H_packed) == 16, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_packed) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_required_alignment) == 17, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_size) == 18, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_size) == 1, "record H wrong alignment");
#endif
_Static_assert(sizeof(A2) == 8, "record A2 wrong sizeof");
_Static_assert(_Alignof(A2) == 4, "record A2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A2_alignment) == 12, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_alignment) == 4, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_packed) == 8, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_packed) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_required_alignment) == 9, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_required_alignment) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_size) == 10, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_size) == 1, "record A2 wrong alignment");
#endif
_Static_assert(sizeof(B2) == 4, "record B2 wrong sizeof");
_Static_assert(_Alignof(B2) == 4, "record B2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B2_alignment) == 8, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_alignment) == 4, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_packed) == 4, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_packed) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_required_alignment) == 5, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_required_alignment) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_size) == 6, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_size) == 1, "record B2 wrong alignment");
#endif
_Static_assert(sizeof(C2) == 1, "record C2 wrong sizeof");
_Static_assert(_Alignof(C2) == 1, "record C2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C2_alignment) == 2, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_alignment) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_packed) == 1, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_packed) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_required_alignment) == 2, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_required_alignment) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_size) == 3, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_size) == 1, "record C2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(D2) == 0, "record D2 wrong sizeof");
_Static_assert(_Alignof(D2) == 1, "record D2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D2_alignment) == 1, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_alignment) == 1, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_packed) == 0, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_packed) == 1, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_required_alignment) == 1, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_required_alignment) == 1, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_size) == 2, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_size) == 1, "record D2 wrong alignment");
#endif
_Static_assert(sizeof(E2) == 1, "record E2 wrong sizeof");
_Static_assert(_Alignof(E2) == 1, "record E2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E2_alignment) == 2, "record E2 wrong sizeof");
_Static_assert(_Alignof(struct E2_alignment) == 1, "record E2 wrong alignment");
_Static_assert(sizeof(struct E2_packed) == 1, "record E2 wrong sizeof");
_Static_assert(_Alignof(struct E2_packed) == 1, "record E2 wrong alignment");
_Static_assert(sizeof(struct E2_required_alignment) == 2, "record E2 wrong sizeof");
_Static_assert(_Alignof(struct E2_required_alignment) == 1, "record E2 wrong alignment");
_Static_assert(sizeof(struct E2_size) == 3, "record E2 wrong sizeof");
_Static_assert(_Alignof(struct E2_size) == 1, "record E2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(F2) == 1, "record F2 wrong sizeof");
_Static_assert(_Alignof(F2) == 1, "record F2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F2_alignment) == 2, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_alignment) == 1, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_packed) == 1, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_packed) == 1, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_required_alignment) == 2, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_required_alignment) == 1, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_size) == 3, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_size) == 1, "record F2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(G2) == 1, "record G2 wrong sizeof");
_Static_assert(_Alignof(G2) == 1, "record G2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G2_alignment) == 2, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_alignment) == 1, "record G2 wrong alignment");
_Static_assert(sizeof(struct G2_packed) == 1, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_packed) == 1, "record G2 wrong alignment");
_Static_assert(sizeof(struct G2_required_alignment) == 2, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_required_alignment) == 1, "record G2 wrong alignment");
_Static_assert(sizeof(struct G2_size) == 3, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_size) == 1, "record G2 wrong alignment");
#endif
_Static_assert(sizeof(H2) == 16, "record H2 wrong sizeof");
_Static_assert(_Alignof(H2) == 16, "record H2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H2_alignment) == 32, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_alignment) == 16, "record H2 wrong alignment");
_Static_assert(sizeof(struct H2_packed) == 16, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_packed) == 1, "record H2 wrong alignment");
_Static_assert(sizeof(struct H2_required_alignment) == 17, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_required_alignment) == 1, "record H2 wrong alignment");
_Static_assert(sizeof(struct H2_size) == 18, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_size) == 1, "record H2 wrong alignment");
#endif
#elif defined(I686_PC_WINDOWS_GNU) ||  defined(X8664_PC_WINDOWS_GNU) 
_Static_assert(sizeof(A) == 8, "record A wrong sizeof");
_Static_assert(_Alignof(A) == 8, "record A wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 16, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_alignment) == 8, "record A wrong alignment");
_Static_assert(sizeof(struct A_packed) == 8, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_packed) == 1, "record A wrong alignment");
_Static_assert(sizeof(struct A_required_alignment) == 9, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "record A wrong alignment");
_Static_assert(sizeof(struct A_size) == 10, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_size) == 1, "record A wrong alignment");
#endif
_Static_assert(sizeof(B) == 8, "record B wrong sizeof");
_Static_assert(_Alignof(B) == 8, "record B wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 16, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_alignment) == 8, "record B wrong alignment");
_Static_assert(sizeof(struct B_packed) == 8, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_packed) == 1, "record B wrong alignment");
_Static_assert(sizeof(struct B_required_alignment) == 9, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "record B wrong alignment");
_Static_assert(sizeof(struct B_size) == 10, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_size) == 1, "record B wrong alignment");
#endif
_Static_assert(sizeof(C) == 8, "record C wrong sizeof");
_Static_assert(_Alignof(C) == 8, "record C wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 16, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_alignment) == 8, "record C wrong alignment");
_Static_assert(sizeof(struct C_packed) == 8, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_packed) == 1, "record C wrong alignment");
_Static_assert(sizeof(struct C_required_alignment) == 9, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "record C wrong alignment");
_Static_assert(sizeof(struct C_size) == 10, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_size) == 1, "record C wrong alignment");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(D) == 0, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 1, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 1, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_packed) == 0, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 1, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_size) == 2, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_size) == 1, "record D wrong alignment");
#endif
_Static_assert(sizeof(E) == 1, "record E wrong sizeof");
_Static_assert(_Alignof(E) == 1, "record E wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 2, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_alignment) == 1, "record E wrong alignment");
_Static_assert(sizeof(struct E_packed) == 1, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_packed) == 1, "record E wrong alignment");
_Static_assert(sizeof(struct E_required_alignment) == 2, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "record E wrong alignment");
_Static_assert(sizeof(struct E_size) == 3, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_size) == 1, "record E wrong alignment");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(F) == 1, "record F wrong sizeof");
_Static_assert(_Alignof(F) == 1, "record F wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 2, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_alignment) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_packed) == 1, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_packed) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_required_alignment) == 2, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_size) == 3, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_size) == 1, "record F wrong alignment");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(G) == 4, "record G wrong sizeof");
_Static_assert(_Alignof(G) == 1, "record G wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 5, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_alignment) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_packed) == 4, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_packed) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_required_alignment) == 5, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_size) == 6, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_size) == 1, "record G wrong alignment");
#endif
_Static_assert(sizeof(H) == 4, "record H wrong sizeof");
_Static_assert(_Alignof(H) == 1, "record H wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 5, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_alignment) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_packed) == 4, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_packed) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_required_alignment) == 5, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_size) == 6, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_size) == 1, "record H wrong alignment");
#endif
_Static_assert(sizeof(A2) == 8, "record A2 wrong sizeof");
_Static_assert(_Alignof(A2) == 8, "record A2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A2_alignment) == 16, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_alignment) == 8, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_packed) == 8, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_packed) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_required_alignment) == 9, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_required_alignment) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_size) == 10, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_size) == 1, "record A2 wrong alignment");
#endif
_Static_assert(sizeof(B2) == 8, "record B2 wrong sizeof");
_Static_assert(_Alignof(B2) == 8, "record B2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B2_alignment) == 16, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_alignment) == 8, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_packed) == 8, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_packed) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_required_alignment) == 9, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_required_alignment) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_size) == 10, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_size) == 1, "record B2 wrong alignment");
#endif
_Static_assert(sizeof(C2) == 1, "record C2 wrong sizeof");
_Static_assert(_Alignof(C2) == 1, "record C2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C2_alignment) == 2, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_alignment) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_packed) == 1, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_packed) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_required_alignment) == 2, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_required_alignment) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_size) == 3, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_size) == 1, "record C2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(D2) == 0, "record D2 wrong sizeof");
_Static_assert(_Alignof(D2) == 1, "record D2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D2_alignment) == 1, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_alignment) == 1, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_packed) == 0, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_packed) == 1, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_required_alignment) == 1, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_required_alignment) == 1, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_size) == 2, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_size) == 1, "record D2 wrong alignment");
#endif
_Static_assert(sizeof(E2) == 1, "record E2 wrong sizeof");
_Static_assert(_Alignof(E2) == 1, "record E2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E2_alignment) == 2, "record E2 wrong sizeof");
_Static_assert(_Alignof(struct E2_alignment) == 1, "record E2 wrong alignment");
_Static_assert(sizeof(struct E2_packed) == 1, "record E2 wrong sizeof");
_Static_assert(_Alignof(struct E2_packed) == 1, "record E2 wrong alignment");
_Static_assert(sizeof(struct E2_required_alignment) == 2, "record E2 wrong sizeof");
_Static_assert(_Alignof(struct E2_required_alignment) == 1, "record E2 wrong alignment");
_Static_assert(sizeof(struct E2_size) == 3, "record E2 wrong sizeof");
_Static_assert(_Alignof(struct E2_size) == 1, "record E2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(F2) == 1, "record F2 wrong sizeof");
_Static_assert(_Alignof(F2) == 1, "record F2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F2_alignment) == 2, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_alignment) == 1, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_packed) == 1, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_packed) == 1, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_required_alignment) == 2, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_required_alignment) == 1, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_size) == 3, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_size) == 1, "record F2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(G2) == 1, "record G2 wrong sizeof");
_Static_assert(_Alignof(G2) == 1, "record G2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G2_alignment) == 2, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_alignment) == 1, "record G2 wrong alignment");
_Static_assert(sizeof(struct G2_packed) == 1, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_packed) == 1, "record G2 wrong alignment");
_Static_assert(sizeof(struct G2_required_alignment) == 2, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_required_alignment) == 1, "record G2 wrong alignment");
_Static_assert(sizeof(struct G2_size) == 3, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_size) == 1, "record G2 wrong alignment");
#endif
_Static_assert(sizeof(H2) == 1, "record H2 wrong sizeof");
_Static_assert(_Alignof(H2) == 1, "record H2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H2_alignment) == 2, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_alignment) == 1, "record H2 wrong alignment");
_Static_assert(sizeof(struct H2_packed) == 1, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_packed) == 1, "record H2 wrong alignment");
_Static_assert(sizeof(struct H2_required_alignment) == 2, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_required_alignment) == 1, "record H2 wrong alignment");
_Static_assert(sizeof(struct H2_size) == 3, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_size) == 1, "record H2 wrong alignment");
#endif
#elif defined(MSP430_NONE_ELF) 
_Static_assert(sizeof(A) == 8, "record A wrong sizeof");
_Static_assert(_Alignof(A) == 2, "record A wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 10, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_alignment) == 2, "record A wrong alignment");
_Static_assert(sizeof(struct A_packed) == 8, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_packed) == 1, "record A wrong alignment");
_Static_assert(sizeof(struct A_required_alignment) == 9, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "record A wrong alignment");
_Static_assert(sizeof(struct A_size) == 10, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_size) == 1, "record A wrong alignment");
#endif
_Static_assert(sizeof(B) == 2, "record B wrong sizeof");
_Static_assert(_Alignof(B) == 2, "record B wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 4, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_alignment) == 2, "record B wrong alignment");
_Static_assert(sizeof(struct B_packed) == 2, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_packed) == 1, "record B wrong alignment");
_Static_assert(sizeof(struct B_required_alignment) == 3, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "record B wrong alignment");
_Static_assert(sizeof(struct B_size) == 4, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_size) == 1, "record B wrong alignment");
#endif
_Static_assert(sizeof(C) == 2, "record C wrong sizeof");
_Static_assert(_Alignof(C) == 1, "record C wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 3, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_alignment) == 1, "record C wrong alignment");
_Static_assert(sizeof(struct C_packed) == 2, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_packed) == 1, "record C wrong alignment");
_Static_assert(sizeof(struct C_required_alignment) == 3, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "record C wrong alignment");
_Static_assert(sizeof(struct C_size) == 4, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_size) == 1, "record C wrong alignment");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(D) == 0, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 1, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 1, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_packed) == 0, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 1, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_size) == 2, "record D wrong sizeof");
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
#ifdef CHECK_OFFSETS
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
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(G) == 1, "record G wrong sizeof");
_Static_assert(_Alignof(G) == 1, "record G wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 2, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_alignment) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_packed) == 1, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_packed) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_required_alignment) == 2, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_size) == 3, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_size) == 1, "record G wrong alignment");
#endif
_Static_assert(sizeof(H) == 16, "record H wrong sizeof");
_Static_assert(_Alignof(H) == 16, "record H wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 32, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_alignment) == 16, "record H wrong alignment");
_Static_assert(sizeof(struct H_packed) == 16, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_packed) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_required_alignment) == 17, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_size) == 18, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_size) == 1, "record H wrong alignment");
#endif
_Static_assert(sizeof(A2) == 8, "record A2 wrong sizeof");
_Static_assert(_Alignof(A2) == 2, "record A2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A2_alignment) == 10, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_alignment) == 2, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_packed) == 8, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_packed) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_required_alignment) == 9, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_required_alignment) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_size) == 10, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_size) == 1, "record A2 wrong alignment");
#endif
_Static_assert(sizeof(B2) == 2, "record B2 wrong sizeof");
_Static_assert(_Alignof(B2) == 2, "record B2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B2_alignment) == 4, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_alignment) == 2, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_packed) == 2, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_packed) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_required_alignment) == 3, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_required_alignment) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_size) == 4, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_size) == 1, "record B2 wrong alignment");
#endif
_Static_assert(sizeof(C2) == 1, "record C2 wrong sizeof");
_Static_assert(_Alignof(C2) == 1, "record C2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C2_alignment) == 2, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_alignment) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_packed) == 1, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_packed) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_required_alignment) == 2, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_required_alignment) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_size) == 3, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_size) == 1, "record C2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(D2) == 0, "record D2 wrong sizeof");
_Static_assert(_Alignof(D2) == 1, "record D2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D2_alignment) == 1, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_alignment) == 1, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_packed) == 0, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_packed) == 1, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_required_alignment) == 1, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_required_alignment) == 1, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_size) == 2, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_size) == 1, "record D2 wrong alignment");
#endif
_Static_assert(sizeof(E2) == 1, "record E2 wrong sizeof");
_Static_assert(_Alignof(E2) == 1, "record E2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E2_alignment) == 2, "record E2 wrong sizeof");
_Static_assert(_Alignof(struct E2_alignment) == 1, "record E2 wrong alignment");
_Static_assert(sizeof(struct E2_packed) == 1, "record E2 wrong sizeof");
_Static_assert(_Alignof(struct E2_packed) == 1, "record E2 wrong alignment");
_Static_assert(sizeof(struct E2_required_alignment) == 2, "record E2 wrong sizeof");
_Static_assert(_Alignof(struct E2_required_alignment) == 1, "record E2 wrong alignment");
_Static_assert(sizeof(struct E2_size) == 3, "record E2 wrong sizeof");
_Static_assert(_Alignof(struct E2_size) == 1, "record E2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(F2) == 1, "record F2 wrong sizeof");
_Static_assert(_Alignof(F2) == 1, "record F2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F2_alignment) == 2, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_alignment) == 1, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_packed) == 1, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_packed) == 1, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_required_alignment) == 2, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_required_alignment) == 1, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_size) == 3, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_size) == 1, "record F2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(G2) == 1, "record G2 wrong sizeof");
_Static_assert(_Alignof(G2) == 1, "record G2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G2_alignment) == 2, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_alignment) == 1, "record G2 wrong alignment");
_Static_assert(sizeof(struct G2_packed) == 1, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_packed) == 1, "record G2 wrong alignment");
_Static_assert(sizeof(struct G2_required_alignment) == 2, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_required_alignment) == 1, "record G2 wrong alignment");
_Static_assert(sizeof(struct G2_size) == 3, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_size) == 1, "record G2 wrong alignment");
#endif
_Static_assert(sizeof(H2) == 16, "record H2 wrong sizeof");
_Static_assert(_Alignof(H2) == 16, "record H2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H2_alignment) == 32, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_alignment) == 16, "record H2 wrong alignment");
_Static_assert(sizeof(struct H2_packed) == 16, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_packed) == 1, "record H2 wrong alignment");
_Static_assert(sizeof(struct H2_required_alignment) == 17, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_required_alignment) == 1, "record H2 wrong alignment");
_Static_assert(sizeof(struct H2_size) == 18, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_size) == 1, "record H2 wrong alignment");
#endif
#endif
