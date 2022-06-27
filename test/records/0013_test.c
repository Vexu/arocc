// SPDX-License-Identifier: GPL-3.0-or-later

// This test file is auto-generated. do not edit.
// This file is a derivative work from the test files found// in this repo : https://github.com/mahkoh/repr-c
// and is under the same licence as the original work.

typedef char A;
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

typedef unsigned char B;
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

typedef signed char C;
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

typedef unsigned short D;
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

typedef short E;
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

typedef unsigned int F;
F var21;
struct F_alignment {
#ifdef MSVC
    char a[_Alignof(F)];
    char b;
#else
    char a;
    F b;
#endif
};
struct F_alignment var22;
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
struct F_required_alignment var23;
struct F_size {
    char a[sizeof(F)+1];
    char b;
};
struct F_size var24;

typedef int G;
G var25;
struct G_alignment {
#ifdef MSVC
    char a[_Alignof(G)];
    char b;
#else
    char a;
    G b;
#endif
};
struct G_alignment var26;
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
struct G_required_alignment var27;
struct G_size {
    char a[sizeof(G)+1];
    char b;
};
struct G_size var28;

typedef unsigned long H;
H var29;
struct H_alignment {
#ifdef MSVC
    char a[_Alignof(H)];
    char b;
#else
    char a;
    H b;
#endif
};
struct H_alignment var30;
#pragma pack(1)
struct H_packed {
    H a;
};
#pragma pack()
struct H_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct H_packed)];
    char b;
#else
    char a;
    struct H_packed b;
#endif
};
struct H_required_alignment var31;
struct H_size {
    char a[sizeof(H)+1];
    char b;
};
struct H_size var32;

typedef long I;
I var33;
struct I_alignment {
#ifdef MSVC
    char a[_Alignof(I)];
    char b;
#else
    char a;
    I b;
#endif
};
struct I_alignment var34;
#pragma pack(1)
struct I_packed {
    I a;
};
#pragma pack()
struct I_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct I_packed)];
    char b;
#else
    char a;
    struct I_packed b;
#endif
};
struct I_required_alignment var35;
struct I_size {
    char a[sizeof(I)+1];
    char b;
};
struct I_size var36;

typedef unsigned long long J;
J var37;
struct J_alignment {
#ifdef MSVC
    char a[_Alignof(J)];
    char b;
#else
    char a;
    J b;
#endif
};
struct J_alignment var38;
#pragma pack(1)
struct J_packed {
    J a;
};
#pragma pack()
struct J_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct J_packed)];
    char b;
#else
    char a;
    struct J_packed b;
#endif
};
struct J_required_alignment var39;
struct J_size {
    char a[sizeof(J)+1];
    char b;
};
struct J_size var40;

typedef long long K;
K var41;
struct K_alignment {
#ifdef MSVC
    char a[_Alignof(K)];
    char b;
#else
    char a;
    K b;
#endif
};
struct K_alignment var42;
#pragma pack(1)
struct K_packed {
    K a;
};
#pragma pack()
struct K_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct K_packed)];
    char b;
#else
    char a;
    struct K_packed b;
#endif
};
struct K_required_alignment var43;
struct K_size {
    char a[sizeof(K)+1];
    char b;
};
struct K_size var44;

typedef void* L;
L var45;
struct L_alignment {
#ifdef MSVC
    char a[_Alignof(L)];
    char b;
#else
    char a;
    L b;
#endif
};
struct L_alignment var46;
#pragma pack(1)
struct L_packed {
    L a;
};
#pragma pack()
struct L_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct L_packed)];
    char b;
#else
    char a;
    struct L_packed b;
#endif
};
struct L_required_alignment var47;
struct L_size {
    char a[sizeof(L)+1];
    char b;
};
struct L_size var48;

typedef float M;
M var49;
struct M_alignment {
#ifdef MSVC
    char a[_Alignof(M)];
    char b;
#else
    char a;
    M b;
#endif
};
struct M_alignment var50;
#pragma pack(1)
struct M_packed {
    M a;
};
#pragma pack()
struct M_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct M_packed)];
    char b;
#else
    char a;
    struct M_packed b;
#endif
};
struct M_required_alignment var51;
struct M_size {
    char a[sizeof(M)+1];
    char b;
};
struct M_size var52;

typedef double N;
N var53;
struct N_alignment {
#ifdef MSVC
    char a[_Alignof(N)];
    char b;
#else
    char a;
    N b;
#endif
};
struct N_alignment var54;
#pragma pack(1)
struct N_packed {
    N a;
};
#pragma pack()
struct N_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct N_packed)];
    char b;
#else
    char a;
    struct N_packed b;
#endif
};
struct N_required_alignment var55;
struct N_size {
    char a[sizeof(N)+1];
    char b;
};
struct N_size var56;

#if defined(AARCH64_APPLE_MACOSX) ||  defined(AARCH64_FUCHSIA) ||  defined(AARCH64_LINUX_ANDROID) ||  defined(AARCH64_UNKNOWN_FREEBSD) ||  \
 defined(AARCH64_UNKNOWN_HERMIT) ||  defined(AARCH64_UNKNOWN_LINUX_GNU) ||  defined(AARCH64_UNKNOWN_LINUX_MUSL) ||  defined(AARCH64_UNKNOWN_NETBSD) ||  \
 defined(AARCH64_UNKNOWN_NONE) ||  defined(AARCH64_UNKNOWN_OPENBSD) ||  defined(AARCH64_UNKNOWN_REDOX) ||  defined(ARM64_APPLE_IOS) ||  \
 defined(ARM64_APPLE_IOS_MACABI) ||  defined(ARM64_APPLE_TVOS) ||  defined(MIPS64EL_UNKNOWN_LINUX_GNUABI64) ||  defined(MIPS64EL_UNKNOWN_LINUX_MUSL) ||  \
 defined(MIPS64_UNKNOWN_LINUX_GNUABI64) ||  defined(MIPS64_UNKNOWN_LINUX_MUSL) ||  defined(MIPSISA64R6EL_UNKNOWN_LINUX_GNUABI64) ||  \
 defined(MIPSISA64R6_UNKNOWN_LINUX_GNUABI64) ||  defined(POWERPC64LE_UNKNOWN_LINUX_GNU) ||  defined(POWERPC64LE_UNKNOWN_LINUX_MUSL) ||  \
 defined(POWERPC64_UNKNOWN_FREEBSD) ||  defined(POWERPC64_UNKNOWN_LINUX_GNU) ||  defined(POWERPC64_UNKNOWN_LINUX_MUSL) ||  defined(RISCV64) ||  \
 defined(RISCV64_UNKNOWN_LINUX_GNU) ||  defined(S390X_UNKNOWN_LINUX_GNU) ||  defined(SPARC64_UNKNOWN_LINUX_GNU) ||  defined(SPARC64_UNKNOWN_NETBSD) ||  \
 defined(SPARC64_UNKNOWN_OPENBSD) ||  defined(SPARCV9_SUN_SOLARIS) ||  defined(X8664_APPLE_IOS_MACABI) ||  defined(X8664_APPLE_IOS) ||  \
 defined(X8664_APPLE_MACOSX) ||  defined(X8664_APPLE_TVOS) ||  defined(X8664_ELF) ||  defined(X8664_FUCHSIA) ||  defined(X8664_LINUX_ANDROID) ||  \
 defined(X8664_PC_SOLARIS) ||  defined(X8664_RUMPRUN_NETBSD) ||  defined(X8664_UNKNOWN_DRAGONFLY) ||  defined(X8664_UNKNOWN_FREEBSD) ||  \
 defined(X8664_UNKNOWN_HAIKU) ||  defined(X8664_UNKNOWN_HERMIT) ||  defined(X8664_UNKNOWN_L4RE_UCLIBC) ||  defined(X8664_UNKNOWN_LINUX_GNU) ||  \
 defined(X8664_UNKNOWN_LINUX_MUSL) ||  defined(X8664_UNKNOWN_NETBSD) ||  defined(X8664_UNKNOWN_OPENBSD) ||  defined(X8664_UNKNOWN_REDOX) 
_Static_assert(sizeof(A) == 1, "record A wrong sizeof");
_Static_assert(_Alignof(A) == 1, "record A wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 2, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_alignment) == 1, "record A wrong alignment");
_Static_assert(sizeof(struct A_packed) == 1, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_packed) == 1, "record A wrong alignment");
_Static_assert(sizeof(struct A_required_alignment) == 2, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "record A wrong alignment");
_Static_assert(sizeof(struct A_size) == 3, "record A wrong sizeof");
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
_Static_assert(sizeof(D) == 2, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 2, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 4, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 2, "record D wrong alignment");
_Static_assert(sizeof(struct D_packed) == 2, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 3, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_size) == 4, "record D wrong sizeof");
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
_Static_assert(sizeof(G) == 4, "record G wrong sizeof");
_Static_assert(_Alignof(G) == 4, "record G wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 8, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_alignment) == 4, "record G wrong alignment");
_Static_assert(sizeof(struct G_packed) == 4, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_packed) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_required_alignment) == 5, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_size) == 6, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_size) == 1, "record G wrong alignment");
#endif
_Static_assert(sizeof(H) == 8, "record H wrong sizeof");
_Static_assert(_Alignof(H) == 8, "record H wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 16, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_alignment) == 8, "record H wrong alignment");
_Static_assert(sizeof(struct H_packed) == 8, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_packed) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_required_alignment) == 9, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_size) == 10, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_size) == 1, "record H wrong alignment");
#endif
_Static_assert(sizeof(I) == 8, "record I wrong sizeof");
_Static_assert(_Alignof(I) == 8, "record I wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I_alignment) == 16, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_alignment) == 8, "record I wrong alignment");
_Static_assert(sizeof(struct I_packed) == 8, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_packed) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_required_alignment) == 9, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_required_alignment) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_size) == 10, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_size) == 1, "record I wrong alignment");
#endif
_Static_assert(sizeof(J) == 8, "record J wrong sizeof");
_Static_assert(_Alignof(J) == 8, "record J wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J_alignment) == 16, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_alignment) == 8, "record J wrong alignment");
_Static_assert(sizeof(struct J_packed) == 8, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_packed) == 1, "record J wrong alignment");
_Static_assert(sizeof(struct J_required_alignment) == 9, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_required_alignment) == 1, "record J wrong alignment");
_Static_assert(sizeof(struct J_size) == 10, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_size) == 1, "record J wrong alignment");
#endif
_Static_assert(sizeof(K) == 8, "record K wrong sizeof");
_Static_assert(_Alignof(K) == 8, "record K wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct K_alignment) == 16, "record K wrong sizeof");
_Static_assert(_Alignof(struct K_alignment) == 8, "record K wrong alignment");
_Static_assert(sizeof(struct K_packed) == 8, "record K wrong sizeof");
_Static_assert(_Alignof(struct K_packed) == 1, "record K wrong alignment");
_Static_assert(sizeof(struct K_required_alignment) == 9, "record K wrong sizeof");
_Static_assert(_Alignof(struct K_required_alignment) == 1, "record K wrong alignment");
_Static_assert(sizeof(struct K_size) == 10, "record K wrong sizeof");
_Static_assert(_Alignof(struct K_size) == 1, "record K wrong alignment");
#endif
_Static_assert(sizeof(L) == 8, "record L wrong sizeof");
_Static_assert(_Alignof(L) == 8, "record L wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct L_alignment) == 16, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_alignment) == 8, "record L wrong alignment");
_Static_assert(sizeof(struct L_packed) == 8, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_packed) == 1, "record L wrong alignment");
_Static_assert(sizeof(struct L_required_alignment) == 9, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_required_alignment) == 1, "record L wrong alignment");
_Static_assert(sizeof(struct L_size) == 10, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_size) == 1, "record L wrong alignment");
#endif
_Static_assert(sizeof(M) == 4, "record M wrong sizeof");
_Static_assert(_Alignof(M) == 4, "record M wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct M_alignment) == 8, "record M wrong sizeof");
_Static_assert(_Alignof(struct M_alignment) == 4, "record M wrong alignment");
_Static_assert(sizeof(struct M_packed) == 4, "record M wrong sizeof");
_Static_assert(_Alignof(struct M_packed) == 1, "record M wrong alignment");
_Static_assert(sizeof(struct M_required_alignment) == 5, "record M wrong sizeof");
_Static_assert(_Alignof(struct M_required_alignment) == 1, "record M wrong alignment");
_Static_assert(sizeof(struct M_size) == 6, "record M wrong sizeof");
_Static_assert(_Alignof(struct M_size) == 1, "record M wrong alignment");
#endif
_Static_assert(sizeof(N) == 8, "record N wrong sizeof");
_Static_assert(_Alignof(N) == 8, "record N wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct N_alignment) == 16, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_alignment) == 8, "record N wrong alignment");
_Static_assert(sizeof(struct N_packed) == 8, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_packed) == 1, "record N wrong alignment");
_Static_assert(sizeof(struct N_required_alignment) == 9, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_required_alignment) == 1, "record N wrong alignment");
_Static_assert(sizeof(struct N_size) == 10, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_size) == 1, "record N wrong alignment");
#endif
#elif defined(AARCH64_PC_WINDOWS_MSVC) ||  defined(X8664_PC_WINDOWS_GNU) ||  defined(X8664_PC_WINDOWS_MSVC) ||  defined(X8664_UNKNOWN_WINDOWS) 
_Static_assert(sizeof(A) == 1, "record A wrong sizeof");
_Static_assert(_Alignof(A) == 1, "record A wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 2, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_alignment) == 1, "record A wrong alignment");
_Static_assert(sizeof(struct A_packed) == 1, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_packed) == 1, "record A wrong alignment");
_Static_assert(sizeof(struct A_required_alignment) == 2, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "record A wrong alignment");
_Static_assert(sizeof(struct A_size) == 3, "record A wrong sizeof");
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
_Static_assert(sizeof(D) == 2, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 2, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 4, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 2, "record D wrong alignment");
_Static_assert(sizeof(struct D_packed) == 2, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 3, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_size) == 4, "record D wrong sizeof");
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
_Static_assert(sizeof(G) == 4, "record G wrong sizeof");
_Static_assert(_Alignof(G) == 4, "record G wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 8, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_alignment) == 4, "record G wrong alignment");
_Static_assert(sizeof(struct G_packed) == 4, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_packed) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_required_alignment) == 5, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_size) == 6, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_size) == 1, "record G wrong alignment");
#endif
_Static_assert(sizeof(H) == 4, "record H wrong sizeof");
_Static_assert(_Alignof(H) == 4, "record H wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 8, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_alignment) == 4, "record H wrong alignment");
_Static_assert(sizeof(struct H_packed) == 4, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_packed) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_required_alignment) == 5, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_size) == 6, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_size) == 1, "record H wrong alignment");
#endif
_Static_assert(sizeof(I) == 4, "record I wrong sizeof");
_Static_assert(_Alignof(I) == 4, "record I wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I_alignment) == 8, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_alignment) == 4, "record I wrong alignment");
_Static_assert(sizeof(struct I_packed) == 4, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_packed) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_required_alignment) == 5, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_required_alignment) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_size) == 6, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_size) == 1, "record I wrong alignment");
#endif
_Static_assert(sizeof(J) == 8, "record J wrong sizeof");
_Static_assert(_Alignof(J) == 8, "record J wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J_alignment) == 16, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_alignment) == 8, "record J wrong alignment");
_Static_assert(sizeof(struct J_packed) == 8, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_packed) == 1, "record J wrong alignment");
_Static_assert(sizeof(struct J_required_alignment) == 9, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_required_alignment) == 1, "record J wrong alignment");
_Static_assert(sizeof(struct J_size) == 10, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_size) == 1, "record J wrong alignment");
#endif
_Static_assert(sizeof(K) == 8, "record K wrong sizeof");
_Static_assert(_Alignof(K) == 8, "record K wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct K_alignment) == 16, "record K wrong sizeof");
_Static_assert(_Alignof(struct K_alignment) == 8, "record K wrong alignment");
_Static_assert(sizeof(struct K_packed) == 8, "record K wrong sizeof");
_Static_assert(_Alignof(struct K_packed) == 1, "record K wrong alignment");
_Static_assert(sizeof(struct K_required_alignment) == 9, "record K wrong sizeof");
_Static_assert(_Alignof(struct K_required_alignment) == 1, "record K wrong alignment");
_Static_assert(sizeof(struct K_size) == 10, "record K wrong sizeof");
_Static_assert(_Alignof(struct K_size) == 1, "record K wrong alignment");
#endif
_Static_assert(sizeof(L) == 8, "record L wrong sizeof");
_Static_assert(_Alignof(L) == 8, "record L wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct L_alignment) == 16, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_alignment) == 8, "record L wrong alignment");
_Static_assert(sizeof(struct L_packed) == 8, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_packed) == 1, "record L wrong alignment");
_Static_assert(sizeof(struct L_required_alignment) == 9, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_required_alignment) == 1, "record L wrong alignment");
_Static_assert(sizeof(struct L_size) == 10, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_size) == 1, "record L wrong alignment");
#endif
_Static_assert(sizeof(M) == 4, "record M wrong sizeof");
_Static_assert(_Alignof(M) == 4, "record M wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct M_alignment) == 8, "record M wrong sizeof");
_Static_assert(_Alignof(struct M_alignment) == 4, "record M wrong alignment");
_Static_assert(sizeof(struct M_packed) == 4, "record M wrong sizeof");
_Static_assert(_Alignof(struct M_packed) == 1, "record M wrong alignment");
_Static_assert(sizeof(struct M_required_alignment) == 5, "record M wrong sizeof");
_Static_assert(_Alignof(struct M_required_alignment) == 1, "record M wrong alignment");
_Static_assert(sizeof(struct M_size) == 6, "record M wrong sizeof");
_Static_assert(_Alignof(struct M_size) == 1, "record M wrong alignment");
#endif
_Static_assert(sizeof(N) == 8, "record N wrong sizeof");
_Static_assert(_Alignof(N) == 8, "record N wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct N_alignment) == 16, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_alignment) == 8, "record N wrong alignment");
_Static_assert(sizeof(struct N_packed) == 8, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_packed) == 1, "record N wrong alignment");
_Static_assert(sizeof(struct N_required_alignment) == 9, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_required_alignment) == 1, "record N wrong alignment");
_Static_assert(sizeof(struct N_size) == 10, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_size) == 1, "record N wrong alignment");
#endif
#elif defined(ARMEBV7R_UNKNOWN_NONE_EABI) ||  defined(ARMEBV7R_UNKNOWN_NONE_EABIHF) ||  defined(ARM_LINUX_ANDROIDEABI) ||  defined(ARM_UNKNOWN_LINUX_GNUEABI) ||  \
 defined(ARM_UNKNOWN_LINUX_GNUEABIHF) ||  defined(ARMV4T_UNKNOWN_LINUX_GNUEABI) ||  defined(ARMV5TE_UNKNOWN_LINUX_GNUEABI) ||  defined(ARMV5TE_UNKNOWN_LINUX_UCLIBCGNUEABI) ||  \
 defined(ARMV6_UNKNOWN_FREEBSD_GNUEABIHF) ||  defined(ARMV6_UNKNOWN_NETBSDELF_EABIHF) ||  defined(ARMV7A_NONE_EABI) ||  defined(ARMV7A_NONE_EABIHF) ||  \
 defined(ARMV7_NONE_LINUX_ANDROID) ||  defined(ARMV7R_UNKNOWN_NONE_EABI) ||  defined(ARMV7R_UNKNOWN_NONE_EABIHF) ||  defined(ARMV7_UNKNOWN_FREEBSD_GNUEABIHF) ||  \
 defined(ARMV7_UNKNOWN_LINUX_GNUEABI) ||  defined(ARMV7_UNKNOWN_LINUX_GNUEABIHF) ||  defined(ARMV7_UNKNOWN_NETBSDELF_EABIHF) ||  defined(HEXAGON_UNKNOWN_LINUX_MUSL) ||  \
 defined(I586_PC_WINDOWS_MSVC) ||  defined(I686_PC_WINDOWS_GNU) ||  defined(I686_PC_WINDOWS_MSVC) ||  defined(I686_UNKNOWN_WINDOWS) ||  \
 defined(MIPSEL_SONY_PSP) ||  defined(MIPSEL_UNKNOWN_LINUX_GNU) ||  defined(MIPSEL_UNKNOWN_LINUX_MUSL) ||  defined(MIPSEL_UNKNOWN_LINUX_UCLIBC) ||  \
 defined(MIPSEL_UNKNOWN_NONE) ||  defined(MIPSISA32R6EL_UNKNOWN_LINUX_GNU) ||  defined(MIPSISA32R6_UNKNOWN_LINUX_GNU) ||  defined(MIPS_UNKNOWN_LINUX_GNU) ||  \
 defined(MIPS_UNKNOWN_LINUX_MUSL) ||  defined(MIPS_UNKNOWN_LINUX_UCLIBC) ||  defined(POWERPC_UNKNOWN_LINUX_GNU) ||  defined(POWERPC_UNKNOWN_LINUX_GNUSPE) ||  \
 defined(POWERPC_UNKNOWN_LINUX_MUSL) ||  defined(POWERPC_UNKNOWN_NETBSD) ||  defined(RISCV32) ||  defined(RISCV32_UNKNOWN_LINUX_GNU) ||  \
 defined(SPARC_UNKNOWN_LINUX_GNU) ||  defined(THUMBV4T_NONE_EABI) ||  defined(THUMBV6M_NONE_EABI) ||  defined(THUMBV7A_PC_WINDOWS_MSVC) ||  \
 defined(THUMBV7EM_NONE_EABIHF) ||  defined(THUMBV7EM_NONE_EABI) ||  defined(THUMBV7M_NONE_EABI) ||  defined(THUMBV8MBASE_NONE_EABI) ||  \
 defined(THUMBV8MMAIN_NONE_EABIHF) ||  defined(THUMBV8MMAIN_NONE_EABI) ||  defined(WASM32_UNKNOWN_EMSCRIPTEN) ||  defined(WASM32_UNKNOWN_UNKNOWN) ||  \
 defined(WASM32_WASI) ||  defined(X8664_UNKNOWN_LINUX_GNUX32) 
_Static_assert(sizeof(A) == 1, "record A wrong sizeof");
_Static_assert(_Alignof(A) == 1, "record A wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 2, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_alignment) == 1, "record A wrong alignment");
_Static_assert(sizeof(struct A_packed) == 1, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_packed) == 1, "record A wrong alignment");
_Static_assert(sizeof(struct A_required_alignment) == 2, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "record A wrong alignment");
_Static_assert(sizeof(struct A_size) == 3, "record A wrong sizeof");
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
_Static_assert(sizeof(D) == 2, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 2, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 4, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 2, "record D wrong alignment");
_Static_assert(sizeof(struct D_packed) == 2, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 3, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_size) == 4, "record D wrong sizeof");
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
_Static_assert(sizeof(G) == 4, "record G wrong sizeof");
_Static_assert(_Alignof(G) == 4, "record G wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 8, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_alignment) == 4, "record G wrong alignment");
_Static_assert(sizeof(struct G_packed) == 4, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_packed) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_required_alignment) == 5, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_size) == 6, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_size) == 1, "record G wrong alignment");
#endif
_Static_assert(sizeof(H) == 4, "record H wrong sizeof");
_Static_assert(_Alignof(H) == 4, "record H wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 8, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_alignment) == 4, "record H wrong alignment");
_Static_assert(sizeof(struct H_packed) == 4, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_packed) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_required_alignment) == 5, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_size) == 6, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_size) == 1, "record H wrong alignment");
#endif
_Static_assert(sizeof(I) == 4, "record I wrong sizeof");
_Static_assert(_Alignof(I) == 4, "record I wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I_alignment) == 8, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_alignment) == 4, "record I wrong alignment");
_Static_assert(sizeof(struct I_packed) == 4, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_packed) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_required_alignment) == 5, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_required_alignment) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_size) == 6, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_size) == 1, "record I wrong alignment");
#endif
_Static_assert(sizeof(J) == 8, "record J wrong sizeof");
_Static_assert(_Alignof(J) == 8, "record J wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J_alignment) == 16, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_alignment) == 8, "record J wrong alignment");
_Static_assert(sizeof(struct J_packed) == 8, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_packed) == 1, "record J wrong alignment");
_Static_assert(sizeof(struct J_required_alignment) == 9, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_required_alignment) == 1, "record J wrong alignment");
_Static_assert(sizeof(struct J_size) == 10, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_size) == 1, "record J wrong alignment");
#endif
_Static_assert(sizeof(K) == 8, "record K wrong sizeof");
_Static_assert(_Alignof(K) == 8, "record K wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct K_alignment) == 16, "record K wrong sizeof");
_Static_assert(_Alignof(struct K_alignment) == 8, "record K wrong alignment");
_Static_assert(sizeof(struct K_packed) == 8, "record K wrong sizeof");
_Static_assert(_Alignof(struct K_packed) == 1, "record K wrong alignment");
_Static_assert(sizeof(struct K_required_alignment) == 9, "record K wrong sizeof");
_Static_assert(_Alignof(struct K_required_alignment) == 1, "record K wrong alignment");
_Static_assert(sizeof(struct K_size) == 10, "record K wrong sizeof");
_Static_assert(_Alignof(struct K_size) == 1, "record K wrong alignment");
#endif
_Static_assert(sizeof(L) == 4, "record L wrong sizeof");
_Static_assert(_Alignof(L) == 4, "record L wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct L_alignment) == 8, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_alignment) == 4, "record L wrong alignment");
_Static_assert(sizeof(struct L_packed) == 4, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_packed) == 1, "record L wrong alignment");
_Static_assert(sizeof(struct L_required_alignment) == 5, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_required_alignment) == 1, "record L wrong alignment");
_Static_assert(sizeof(struct L_size) == 6, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_size) == 1, "record L wrong alignment");
#endif
_Static_assert(sizeof(M) == 4, "record M wrong sizeof");
_Static_assert(_Alignof(M) == 4, "record M wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct M_alignment) == 8, "record M wrong sizeof");
_Static_assert(_Alignof(struct M_alignment) == 4, "record M wrong alignment");
_Static_assert(sizeof(struct M_packed) == 4, "record M wrong sizeof");
_Static_assert(_Alignof(struct M_packed) == 1, "record M wrong alignment");
_Static_assert(sizeof(struct M_required_alignment) == 5, "record M wrong sizeof");
_Static_assert(_Alignof(struct M_required_alignment) == 1, "record M wrong alignment");
_Static_assert(sizeof(struct M_size) == 6, "record M wrong sizeof");
_Static_assert(_Alignof(struct M_size) == 1, "record M wrong alignment");
#endif
_Static_assert(sizeof(N) == 8, "record N wrong sizeof");
_Static_assert(_Alignof(N) == 8, "record N wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct N_alignment) == 16, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_alignment) == 8, "record N wrong alignment");
_Static_assert(sizeof(struct N_packed) == 8, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_packed) == 1, "record N wrong alignment");
_Static_assert(sizeof(struct N_required_alignment) == 9, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_required_alignment) == 1, "record N wrong alignment");
_Static_assert(sizeof(struct N_size) == 10, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_size) == 1, "record N wrong alignment");
#endif
#elif defined(ARMV7_APPLE_IOS) ||  defined(ARMV7S_APPLE_IOS) ||  defined(I386_APPLE_IOS) ||  defined(I586_UNKNOWN_LINUX_GNU) ||  defined(I586_UNKNOWN_LINUX_MUSL) ||  \
 defined(I686_APPLE_MACOSX) ||  defined(I686_LINUX_ANDROID) ||  defined(I686_UNKNOWN_FREEBSD) ||  defined(I686_UNKNOWN_HAIKU) ||  defined(I686_UNKNOWN_LINUX_GNU) ||  \
 defined(I686_UNKNOWN_LINUX_MUSL) ||  defined(I686_UNKNOWN_NETBSDELF) ||  defined(I686_UNKNOWN_OPENBSD) 
_Static_assert(sizeof(A) == 1, "record A wrong sizeof");
_Static_assert(_Alignof(A) == 1, "record A wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 2, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_alignment) == 1, "record A wrong alignment");
_Static_assert(sizeof(struct A_packed) == 1, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_packed) == 1, "record A wrong alignment");
_Static_assert(sizeof(struct A_required_alignment) == 2, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "record A wrong alignment");
_Static_assert(sizeof(struct A_size) == 3, "record A wrong sizeof");
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
_Static_assert(sizeof(D) == 2, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 2, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 4, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 2, "record D wrong alignment");
_Static_assert(sizeof(struct D_packed) == 2, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 3, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_size) == 4, "record D wrong sizeof");
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
_Static_assert(sizeof(G) == 4, "record G wrong sizeof");
_Static_assert(_Alignof(G) == 4, "record G wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 8, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_alignment) == 4, "record G wrong alignment");
_Static_assert(sizeof(struct G_packed) == 4, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_packed) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_required_alignment) == 5, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_size) == 6, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_size) == 1, "record G wrong alignment");
#endif
_Static_assert(sizeof(H) == 4, "record H wrong sizeof");
_Static_assert(_Alignof(H) == 4, "record H wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 8, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_alignment) == 4, "record H wrong alignment");
_Static_assert(sizeof(struct H_packed) == 4, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_packed) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_required_alignment) == 5, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_size) == 6, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_size) == 1, "record H wrong alignment");
#endif
_Static_assert(sizeof(I) == 4, "record I wrong sizeof");
_Static_assert(_Alignof(I) == 4, "record I wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I_alignment) == 8, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_alignment) == 4, "record I wrong alignment");
_Static_assert(sizeof(struct I_packed) == 4, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_packed) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_required_alignment) == 5, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_required_alignment) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_size) == 6, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_size) == 1, "record I wrong alignment");
#endif
_Static_assert(sizeof(J) == 8, "record J wrong sizeof");
_Static_assert(_Alignof(J) == 4, "record J wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J_alignment) == 12, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_alignment) == 4, "record J wrong alignment");
_Static_assert(sizeof(struct J_packed) == 8, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_packed) == 1, "record J wrong alignment");
_Static_assert(sizeof(struct J_required_alignment) == 9, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_required_alignment) == 1, "record J wrong alignment");
_Static_assert(sizeof(struct J_size) == 10, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_size) == 1, "record J wrong alignment");
#endif
_Static_assert(sizeof(K) == 8, "record K wrong sizeof");
_Static_assert(_Alignof(K) == 4, "record K wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct K_alignment) == 12, "record K wrong sizeof");
_Static_assert(_Alignof(struct K_alignment) == 4, "record K wrong alignment");
_Static_assert(sizeof(struct K_packed) == 8, "record K wrong sizeof");
_Static_assert(_Alignof(struct K_packed) == 1, "record K wrong alignment");
_Static_assert(sizeof(struct K_required_alignment) == 9, "record K wrong sizeof");
_Static_assert(_Alignof(struct K_required_alignment) == 1, "record K wrong alignment");
_Static_assert(sizeof(struct K_size) == 10, "record K wrong sizeof");
_Static_assert(_Alignof(struct K_size) == 1, "record K wrong alignment");
#endif
_Static_assert(sizeof(L) == 4, "record L wrong sizeof");
_Static_assert(_Alignof(L) == 4, "record L wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct L_alignment) == 8, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_alignment) == 4, "record L wrong alignment");
_Static_assert(sizeof(struct L_packed) == 4, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_packed) == 1, "record L wrong alignment");
_Static_assert(sizeof(struct L_required_alignment) == 5, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_required_alignment) == 1, "record L wrong alignment");
_Static_assert(sizeof(struct L_size) == 6, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_size) == 1, "record L wrong alignment");
#endif
_Static_assert(sizeof(M) == 4, "record M wrong sizeof");
_Static_assert(_Alignof(M) == 4, "record M wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct M_alignment) == 8, "record M wrong sizeof");
_Static_assert(_Alignof(struct M_alignment) == 4, "record M wrong alignment");
_Static_assert(sizeof(struct M_packed) == 4, "record M wrong sizeof");
_Static_assert(_Alignof(struct M_packed) == 1, "record M wrong alignment");
_Static_assert(sizeof(struct M_required_alignment) == 5, "record M wrong sizeof");
_Static_assert(_Alignof(struct M_required_alignment) == 1, "record M wrong alignment");
_Static_assert(sizeof(struct M_size) == 6, "record M wrong sizeof");
_Static_assert(_Alignof(struct M_size) == 1, "record M wrong alignment");
#endif
_Static_assert(sizeof(N) == 8, "record N wrong sizeof");
_Static_assert(_Alignof(N) == 4, "record N wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct N_alignment) == 12, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_alignment) == 4, "record N wrong alignment");
_Static_assert(sizeof(struct N_packed) == 8, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_packed) == 1, "record N wrong alignment");
_Static_assert(sizeof(struct N_required_alignment) == 9, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_required_alignment) == 1, "record N wrong alignment");
_Static_assert(sizeof(struct N_size) == 10, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_size) == 1, "record N wrong alignment");
#endif
#elif defined(AVR_UNKNOWN_UNKNOWN) 
_Static_assert(sizeof(A) == 1, "record A wrong sizeof");
_Static_assert(_Alignof(A) == 1, "record A wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 2, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_alignment) == 1, "record A wrong alignment");
_Static_assert(sizeof(struct A_packed) == 1, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_packed) == 1, "record A wrong alignment");
_Static_assert(sizeof(struct A_required_alignment) == 2, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "record A wrong alignment");
_Static_assert(sizeof(struct A_size) == 3, "record A wrong sizeof");
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
_Static_assert(sizeof(D) == 2, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 1, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 3, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_packed) == 2, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 3, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_size) == 4, "record D wrong sizeof");
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
_Static_assert(sizeof(I) == 4, "record I wrong sizeof");
_Static_assert(_Alignof(I) == 1, "record I wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I_alignment) == 5, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_alignment) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_packed) == 4, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_packed) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_required_alignment) == 5, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_required_alignment) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_size) == 6, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_size) == 1, "record I wrong alignment");
#endif
_Static_assert(sizeof(J) == 8, "record J wrong sizeof");
_Static_assert(_Alignof(J) == 1, "record J wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J_alignment) == 9, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_alignment) == 1, "record J wrong alignment");
_Static_assert(sizeof(struct J_packed) == 8, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_packed) == 1, "record J wrong alignment");
_Static_assert(sizeof(struct J_required_alignment) == 9, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_required_alignment) == 1, "record J wrong alignment");
_Static_assert(sizeof(struct J_size) == 10, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_size) == 1, "record J wrong alignment");
#endif
_Static_assert(sizeof(K) == 8, "record K wrong sizeof");
_Static_assert(_Alignof(K) == 1, "record K wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct K_alignment) == 9, "record K wrong sizeof");
_Static_assert(_Alignof(struct K_alignment) == 1, "record K wrong alignment");
_Static_assert(sizeof(struct K_packed) == 8, "record K wrong sizeof");
_Static_assert(_Alignof(struct K_packed) == 1, "record K wrong alignment");
_Static_assert(sizeof(struct K_required_alignment) == 9, "record K wrong sizeof");
_Static_assert(_Alignof(struct K_required_alignment) == 1, "record K wrong alignment");
_Static_assert(sizeof(struct K_size) == 10, "record K wrong sizeof");
_Static_assert(_Alignof(struct K_size) == 1, "record K wrong alignment");
#endif
_Static_assert(sizeof(L) == 2, "record L wrong sizeof");
_Static_assert(_Alignof(L) == 1, "record L wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct L_alignment) == 3, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_alignment) == 1, "record L wrong alignment");
_Static_assert(sizeof(struct L_packed) == 2, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_packed) == 1, "record L wrong alignment");
_Static_assert(sizeof(struct L_required_alignment) == 3, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_required_alignment) == 1, "record L wrong alignment");
_Static_assert(sizeof(struct L_size) == 4, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_size) == 1, "record L wrong alignment");
#endif
_Static_assert(sizeof(M) == 4, "record M wrong sizeof");
_Static_assert(_Alignof(M) == 1, "record M wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct M_alignment) == 5, "record M wrong sizeof");
_Static_assert(_Alignof(struct M_alignment) == 1, "record M wrong alignment");
_Static_assert(sizeof(struct M_packed) == 4, "record M wrong sizeof");
_Static_assert(_Alignof(struct M_packed) == 1, "record M wrong alignment");
_Static_assert(sizeof(struct M_required_alignment) == 5, "record M wrong sizeof");
_Static_assert(_Alignof(struct M_required_alignment) == 1, "record M wrong alignment");
_Static_assert(sizeof(struct M_size) == 6, "record M wrong sizeof");
_Static_assert(_Alignof(struct M_size) == 1, "record M wrong alignment");
#endif
_Static_assert(sizeof(N) == 4, "record N wrong sizeof");
_Static_assert(_Alignof(N) == 1, "record N wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct N_alignment) == 5, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_alignment) == 1, "record N wrong alignment");
_Static_assert(sizeof(struct N_packed) == 4, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_packed) == 1, "record N wrong alignment");
_Static_assert(sizeof(struct N_required_alignment) == 5, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_required_alignment) == 1, "record N wrong alignment");
_Static_assert(sizeof(struct N_size) == 6, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_size) == 1, "record N wrong alignment");
#endif
#elif defined(MSP430_NONE_ELF) 
_Static_assert(sizeof(A) == 1, "record A wrong sizeof");
_Static_assert(_Alignof(A) == 1, "record A wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 2, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_alignment) == 1, "record A wrong alignment");
_Static_assert(sizeof(struct A_packed) == 1, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_packed) == 1, "record A wrong alignment");
_Static_assert(sizeof(struct A_required_alignment) == 2, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "record A wrong alignment");
_Static_assert(sizeof(struct A_size) == 3, "record A wrong sizeof");
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
_Static_assert(sizeof(D) == 2, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 2, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 4, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 2, "record D wrong alignment");
_Static_assert(sizeof(struct D_packed) == 2, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 3, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_size) == 4, "record D wrong sizeof");
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
_Static_assert(sizeof(G) == 2, "record G wrong sizeof");
_Static_assert(_Alignof(G) == 2, "record G wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 4, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_alignment) == 2, "record G wrong alignment");
_Static_assert(sizeof(struct G_packed) == 2, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_packed) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_required_alignment) == 3, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_size) == 4, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_size) == 1, "record G wrong alignment");
#endif
_Static_assert(sizeof(H) == 4, "record H wrong sizeof");
_Static_assert(_Alignof(H) == 2, "record H wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 6, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_alignment) == 2, "record H wrong alignment");
_Static_assert(sizeof(struct H_packed) == 4, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_packed) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_required_alignment) == 5, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_size) == 6, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_size) == 1, "record H wrong alignment");
#endif
_Static_assert(sizeof(I) == 4, "record I wrong sizeof");
_Static_assert(_Alignof(I) == 2, "record I wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I_alignment) == 6, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_alignment) == 2, "record I wrong alignment");
_Static_assert(sizeof(struct I_packed) == 4, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_packed) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_required_alignment) == 5, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_required_alignment) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_size) == 6, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_size) == 1, "record I wrong alignment");
#endif
_Static_assert(sizeof(J) == 8, "record J wrong sizeof");
_Static_assert(_Alignof(J) == 2, "record J wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J_alignment) == 10, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_alignment) == 2, "record J wrong alignment");
_Static_assert(sizeof(struct J_packed) == 8, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_packed) == 1, "record J wrong alignment");
_Static_assert(sizeof(struct J_required_alignment) == 9, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_required_alignment) == 1, "record J wrong alignment");
_Static_assert(sizeof(struct J_size) == 10, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_size) == 1, "record J wrong alignment");
#endif
_Static_assert(sizeof(K) == 8, "record K wrong sizeof");
_Static_assert(_Alignof(K) == 2, "record K wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct K_alignment) == 10, "record K wrong sizeof");
_Static_assert(_Alignof(struct K_alignment) == 2, "record K wrong alignment");
_Static_assert(sizeof(struct K_packed) == 8, "record K wrong sizeof");
_Static_assert(_Alignof(struct K_packed) == 1, "record K wrong alignment");
_Static_assert(sizeof(struct K_required_alignment) == 9, "record K wrong sizeof");
_Static_assert(_Alignof(struct K_required_alignment) == 1, "record K wrong alignment");
_Static_assert(sizeof(struct K_size) == 10, "record K wrong sizeof");
_Static_assert(_Alignof(struct K_size) == 1, "record K wrong alignment");
#endif
_Static_assert(sizeof(L) == 2, "record L wrong sizeof");
_Static_assert(_Alignof(L) == 2, "record L wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct L_alignment) == 4, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_alignment) == 2, "record L wrong alignment");
_Static_assert(sizeof(struct L_packed) == 2, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_packed) == 1, "record L wrong alignment");
_Static_assert(sizeof(struct L_required_alignment) == 3, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_required_alignment) == 1, "record L wrong alignment");
_Static_assert(sizeof(struct L_size) == 4, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_size) == 1, "record L wrong alignment");
#endif
_Static_assert(sizeof(M) == 4, "record M wrong sizeof");
_Static_assert(_Alignof(M) == 2, "record M wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct M_alignment) == 6, "record M wrong sizeof");
_Static_assert(_Alignof(struct M_alignment) == 2, "record M wrong alignment");
_Static_assert(sizeof(struct M_packed) == 4, "record M wrong sizeof");
_Static_assert(_Alignof(struct M_packed) == 1, "record M wrong alignment");
_Static_assert(sizeof(struct M_required_alignment) == 5, "record M wrong sizeof");
_Static_assert(_Alignof(struct M_required_alignment) == 1, "record M wrong alignment");
_Static_assert(sizeof(struct M_size) == 6, "record M wrong sizeof");
_Static_assert(_Alignof(struct M_size) == 1, "record M wrong alignment");
#endif
_Static_assert(sizeof(N) == 8, "record N wrong sizeof");
_Static_assert(_Alignof(N) == 2, "record N wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct N_alignment) == 10, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_alignment) == 2, "record N wrong alignment");
_Static_assert(sizeof(struct N_packed) == 8, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_packed) == 1, "record N wrong alignment");
_Static_assert(sizeof(struct N_required_alignment) == 9, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_required_alignment) == 1, "record N wrong alignment");
_Static_assert(sizeof(struct N_size) == 10, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_size) == 1, "record N wrong alignment");
#endif
#endif
