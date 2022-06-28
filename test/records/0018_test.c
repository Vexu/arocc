// SPDX-License-Identifier: GPL-3.0-or-later

// This test file is auto-generated. do not edit.
// This file is a derivative work from the test files found// in this repo : https://github.com/mahkoh/repr-c
// and is under the same licence as the original work.

typedef char A[3];
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

#ifdef MSVC
__declspec(align(4)) typedef char unnamed_type_5;
#else
typedef char unnamed_type_5 __attribute__((aligned(4)));
#endif
unnamed_type_5 var6;
struct unnamed_type_5_alignment {
#ifdef MSVC
    char a[_Alignof(unnamed_type_5)];
    char b;
#else
    char a;
    unnamed_type_5 b;
#endif
};
struct unnamed_type_5_alignment var7;
#pragma pack(1)
struct unnamed_type_5_packed {
    unnamed_type_5 a;
};
#pragma pack()
struct unnamed_type_5_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct unnamed_type_5_packed)];
    char b;
#else
    char a;
    struct unnamed_type_5_packed b;
#endif
};
struct unnamed_type_5_required_alignment var8;
struct unnamed_type_5_size {
    char a[sizeof(unnamed_type_5)+1];
    char b;
};
struct unnamed_type_5_size var9;

typedef unnamed_type_5 B[3];
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

#ifdef MSVC
__declspec(align(4)) typedef char unnamed_type_15;
#else
typedef char unnamed_type_15 __attribute__((aligned(4)));
#endif
unnamed_type_15 var16;
struct unnamed_type_15_alignment {
#ifdef MSVC
    char a[_Alignof(unnamed_type_15)];
    char b;
#else
    char a;
    unnamed_type_15 b;
#endif
};
struct unnamed_type_15_alignment var17;
#pragma pack(1)
struct unnamed_type_15_packed {
    unnamed_type_15 a;
};
#pragma pack()
struct unnamed_type_15_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct unnamed_type_15_packed)];
    char b;
#else
    char a;
    struct unnamed_type_15_packed b;
#endif
};
struct unnamed_type_15_required_alignment var18;
struct unnamed_type_15_size {
    char a[sizeof(unnamed_type_15)+1];
    char b;
};
struct unnamed_type_15_size var19;

typedef unnamed_type_15 unnamed_type_14[3];
unnamed_type_14 var20;
struct unnamed_type_14_alignment {
#ifdef MSVC
    char a[_Alignof(unnamed_type_14)];
    char b;
#else
    char a;
    unnamed_type_14 b;
#endif
};
struct unnamed_type_14_alignment var21;
#pragma pack(1)
struct unnamed_type_14_packed {
    unnamed_type_14 a;
};
#pragma pack()
struct unnamed_type_14_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct unnamed_type_14_packed)];
    char b;
#else
    char a;
    struct unnamed_type_14_packed b;
#endif
};
struct unnamed_type_14_required_alignment var22;
struct unnamed_type_14_size {
    char a[sizeof(unnamed_type_14)+1];
    char b;
};
struct unnamed_type_14_size var23;

typedef unnamed_type_14 C[3];
C var24;
struct C_alignment {
#ifdef MSVC
    char a[_Alignof(C)];
    char b;
#else
    char a;
    C b;
#endif
};
struct C_alignment var25;
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
struct C_required_alignment var26;
struct C_size {
    char a[sizeof(C)+1];
    char b;
};
struct C_size var27;

typedef short D[3];
D var28;
struct D_alignment {
#ifdef MSVC
    char a[_Alignof(D)];
    char b;
#else
    char a;
    D b;
#endif
};
struct D_alignment var29;
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
struct D_required_alignment var30;
struct D_size {
    char a[sizeof(D)+1];
    char b;
};
struct D_size var31;

#ifdef MSVC
__declspec(align(4)) typedef short unnamed_type_32;
#else
typedef short unnamed_type_32 __attribute__((aligned(4)));
#endif
unnamed_type_32 var33;
struct unnamed_type_32_alignment {
#ifdef MSVC
    char a[_Alignof(unnamed_type_32)];
    char b;
#else
    char a;
    unnamed_type_32 b;
#endif
};
struct unnamed_type_32_alignment var34;
#pragma pack(1)
struct unnamed_type_32_packed {
    unnamed_type_32 a;
};
#pragma pack()
struct unnamed_type_32_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct unnamed_type_32_packed)];
    char b;
#else
    char a;
    struct unnamed_type_32_packed b;
#endif
};
struct unnamed_type_32_required_alignment var35;
struct unnamed_type_32_size {
    char a[sizeof(unnamed_type_32)+1];
    char b;
};
struct unnamed_type_32_size var36;

typedef unnamed_type_32 E[3];
E var37;
struct E_alignment {
#ifdef MSVC
    char a[_Alignof(E)];
    char b;
#else
    char a;
    E b;
#endif
};
struct E_alignment var38;
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
struct E_required_alignment var39;
struct E_size {
    char a[sizeof(E)+1];
    char b;
};
struct E_size var40;

#ifdef MSVC
__declspec(align(4)) typedef short unnamed_type_42;
#else
typedef short unnamed_type_42 __attribute__((aligned(4)));
#endif
unnamed_type_42 var43;
struct unnamed_type_42_alignment {
#ifdef MSVC
    char a[_Alignof(unnamed_type_42)];
    char b;
#else
    char a;
    unnamed_type_42 b;
#endif
};
struct unnamed_type_42_alignment var44;
#pragma pack(1)
struct unnamed_type_42_packed {
    unnamed_type_42 a;
};
#pragma pack()
struct unnamed_type_42_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct unnamed_type_42_packed)];
    char b;
#else
    char a;
    struct unnamed_type_42_packed b;
#endif
};
struct unnamed_type_42_required_alignment var45;
struct unnamed_type_42_size {
    char a[sizeof(unnamed_type_42)+1];
    char b;
};
struct unnamed_type_42_size var46;

typedef unnamed_type_42 unnamed_type_41[3];
unnamed_type_41 var47;
struct unnamed_type_41_alignment {
#ifdef MSVC
    char a[_Alignof(unnamed_type_41)];
    char b;
#else
    char a;
    unnamed_type_41 b;
#endif
};
struct unnamed_type_41_alignment var48;
#pragma pack(1)
struct unnamed_type_41_packed {
    unnamed_type_41 a;
};
#pragma pack()
struct unnamed_type_41_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct unnamed_type_41_packed)];
    char b;
#else
    char a;
    struct unnamed_type_41_packed b;
#endif
};
struct unnamed_type_41_required_alignment var49;
struct unnamed_type_41_size {
    char a[sizeof(unnamed_type_41)+1];
    char b;
};
struct unnamed_type_41_size var50;

typedef unnamed_type_41 F[3];
F var51;
struct F_alignment {
#ifdef MSVC
    char a[_Alignof(F)];
    char b;
#else
    char a;
    F b;
#endif
};
struct F_alignment var52;
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
struct F_required_alignment var53;
struct F_size {
    char a[sizeof(F)+1];
    char b;
};
struct F_size var54;

typedef long long G[3];
G var55;
struct G_alignment {
#ifdef MSVC
    char a[_Alignof(G)];
    char b;
#else
    char a;
    G b;
#endif
};
struct G_alignment var56;
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
struct G_required_alignment var57;
struct G_size {
    char a[sizeof(G)+1];
    char b;
};
struct G_size var58;

#ifdef MSVC
__declspec(align(128)) typedef long long unnamed_type_59;
#else
typedef long long unnamed_type_59 __attribute__((aligned(128)));
#endif
unnamed_type_59 var60;
struct unnamed_type_59_alignment {
#ifdef MSVC
    char a[_Alignof(unnamed_type_59)];
    char b;
#else
    char a;
    unnamed_type_59 b;
#endif
};
struct unnamed_type_59_alignment var61;
#pragma pack(1)
struct unnamed_type_59_packed {
    unnamed_type_59 a;
};
#pragma pack()
struct unnamed_type_59_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct unnamed_type_59_packed)];
    char b;
#else
    char a;
    struct unnamed_type_59_packed b;
#endif
};
struct unnamed_type_59_required_alignment var62;
struct unnamed_type_59_size {
    char a[sizeof(unnamed_type_59)+1];
    char b;
};
struct unnamed_type_59_size var63;

typedef unnamed_type_59 H[3];
H var64;
struct H_alignment {
#ifdef MSVC
    char a[_Alignof(H)];
    char b;
#else
    char a;
    H b;
#endif
};
struct H_alignment var65;
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
struct H_required_alignment var66;
struct H_size {
    char a[sizeof(H)+1];
    char b;
};
struct H_size var67;

#ifdef MSVC
__declspec(align(128)) typedef long long unnamed_type_69;
#else
typedef long long unnamed_type_69 __attribute__((aligned(128)));
#endif
unnamed_type_69 var70;
struct unnamed_type_69_alignment {
#ifdef MSVC
    char a[_Alignof(unnamed_type_69)];
    char b;
#else
    char a;
    unnamed_type_69 b;
#endif
};
struct unnamed_type_69_alignment var71;
#pragma pack(1)
struct unnamed_type_69_packed {
    unnamed_type_69 a;
};
#pragma pack()
struct unnamed_type_69_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct unnamed_type_69_packed)];
    char b;
#else
    char a;
    struct unnamed_type_69_packed b;
#endif
};
struct unnamed_type_69_required_alignment var72;
struct unnamed_type_69_size {
    char a[sizeof(unnamed_type_69)+1];
    char b;
};
struct unnamed_type_69_size var73;

typedef unnamed_type_69 unnamed_type_68[3];
unnamed_type_68 var74;
struct unnamed_type_68_alignment {
#ifdef MSVC
    char a[_Alignof(unnamed_type_68)];
    char b;
#else
    char a;
    unnamed_type_68 b;
#endif
};
struct unnamed_type_68_alignment var75;
#pragma pack(1)
struct unnamed_type_68_packed {
    unnamed_type_68 a;
};
#pragma pack()
struct unnamed_type_68_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct unnamed_type_68_packed)];
    char b;
#else
    char a;
    struct unnamed_type_68_packed b;
#endif
};
struct unnamed_type_68_required_alignment var76;
struct unnamed_type_68_size {
    char a[sizeof(unnamed_type_68)+1];
    char b;
};
struct unnamed_type_68_size var77;

typedef unnamed_type_68 I[3];
I var78;
struct I_alignment {
#ifdef MSVC
    char a[_Alignof(I)];
    char b;
#else
    char a;
    I b;
#endif
};
struct I_alignment var79;
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
struct I_required_alignment var80;
struct I_size {
    char a[sizeof(I)+1];
    char b;
};
struct I_size var81;

#ifdef MSVC
typedef int J[];
#else
typedef int J[0];
#endif
J var82;
struct J_alignment {
#ifdef MSVC
    char a[_Alignof(J)];
    char b;
#else
    char a;
    J b;
#endif
};
struct J_alignment var83;
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
struct J_required_alignment var84;
struct J_size {
    char a[sizeof(J)+1];
    char b;
};
struct J_size var85;

#if defined(AARCH64_APPLE_MACOSX) ||  defined(AARCH64_FUCHSIA) ||  defined(AARCH64_LINUX_ANDROID) ||  defined(AARCH64_UNKNOWN_FREEBSD) ||  \
 defined(AARCH64_UNKNOWN_HERMIT) ||  defined(AARCH64_UNKNOWN_NETBSD) ||  defined(AARCH64_UNKNOWN_NONE) ||  defined(AARCH64_UNKNOWN_OPENBSD) ||  \
 defined(AARCH64_UNKNOWN_REDOX) ||  defined(ARM64_APPLE_IOS) ||  defined(ARM64_APPLE_IOS_MACABI) ||  defined(ARM64_APPLE_TVOS) ||  \
 defined(ARMEBV7R_UNKNOWN_NONE_EABI) ||  defined(ARMEBV7R_UNKNOWN_NONE_EABIHF) ||  defined(ARM_LINUX_ANDROIDEABI) ||  defined(ARMV6_UNKNOWN_FREEBSD_GNUEABIHF) ||  \
 defined(ARMV6_UNKNOWN_NETBSDELF_EABIHF) ||  defined(ARMV7A_NONE_EABI) ||  defined(ARMV7A_NONE_EABIHF) ||  defined(ARMV7_NONE_LINUX_ANDROID) ||  \
 defined(ARMV7R_UNKNOWN_NONE_EABI) ||  defined(ARMV7R_UNKNOWN_NONE_EABIHF) ||  defined(ARMV7_UNKNOWN_FREEBSD_GNUEABIHF) ||  defined(ARMV7_UNKNOWN_NETBSDELF_EABIHF) ||  \
 defined(HEXAGON_UNKNOWN_LINUX_MUSL) ||  defined(MIPSEL_SONY_PSP) ||  defined(MIPSEL_UNKNOWN_NONE) ||  defined(POWERPC64_UNKNOWN_FREEBSD) ||  \
 defined(POWERPC_UNKNOWN_LINUX_GNUSPE) ||  defined(POWERPC_UNKNOWN_NETBSD) ||  defined(RISCV32) ||  defined(RISCV64) ||  defined(SPARC64_UNKNOWN_NETBSD) ||  \
 defined(SPARC64_UNKNOWN_OPENBSD) ||  defined(SPARCV9_SUN_SOLARIS) ||  defined(THUMBV4T_NONE_EABI) ||  defined(THUMBV6M_NONE_EABI) ||  \
 defined(THUMBV7EM_NONE_EABIHF) ||  defined(THUMBV7EM_NONE_EABI) ||  defined(THUMBV7M_NONE_EABI) ||  defined(THUMBV8MBASE_NONE_EABI) ||  \
 defined(THUMBV8MMAIN_NONE_EABIHF) ||  defined(THUMBV8MMAIN_NONE_EABI) ||  defined(WASM32_UNKNOWN_EMSCRIPTEN) ||  defined(WASM32_UNKNOWN_UNKNOWN) ||  \
 defined(WASM32_WASI) ||  defined(X8664_APPLE_IOS_MACABI) ||  defined(X8664_APPLE_IOS) ||  defined(X8664_APPLE_MACOSX) ||  defined(X8664_APPLE_TVOS) ||  \
 defined(X8664_ELF) ||  defined(X8664_FUCHSIA) ||  defined(X8664_LINUX_ANDROID) ||  defined(X8664_PC_SOLARIS) ||  defined(X8664_RUMPRUN_NETBSD) ||  \
 defined(X8664_UNKNOWN_DRAGONFLY) ||  defined(X8664_UNKNOWN_FREEBSD) ||  defined(X8664_UNKNOWN_HAIKU) ||  defined(X8664_UNKNOWN_HERMIT) ||  \
 defined(X8664_UNKNOWN_L4RE_UCLIBC) ||  defined(X8664_UNKNOWN_NETBSD) ||  defined(X8664_UNKNOWN_OPENBSD) ||  defined(X8664_UNKNOWN_REDOX) 
_Static_assert(sizeof(A) == 3, "record A wrong sizeof");
_Static_assert(_Alignof(A) == 1, "record A wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 4, "record A_alignment wrong sizeof");
_Static_assert(_Alignof(struct A_alignment) == 1, "record A_alignment wrong alignment");
_Static_assert(sizeof(struct A_packed) == 3, "record A_packed wrong sizeof");
_Static_assert(_Alignof(struct A_packed) == 1, "record A_packed wrong alignment");
_Static_assert(sizeof(struct A_required_alignment) == 4, "record A_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "record A_required_alignment wrong alignment");
_Static_assert(sizeof(struct A_size) == 5, "record A_size wrong sizeof");
_Static_assert(_Alignof(struct A_size) == 1, "record A_size wrong alignment");
#endif
_Static_assert(sizeof(B) == 4, "record B wrong sizeof");
_Static_assert(_Alignof(B) == 4, "record B wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 8, "record B_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_alignment) == 4, "record B_alignment wrong alignment");
_Static_assert(sizeof(struct B_packed) == 4, "record B_packed wrong sizeof");
_Static_assert(_Alignof(struct B_packed) == 1, "record B_packed wrong alignment");
_Static_assert(sizeof(struct B_required_alignment) == 5, "record B_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "record B_required_alignment wrong alignment");
_Static_assert(sizeof(struct B_size) == 6, "record B_size wrong sizeof");
_Static_assert(_Alignof(struct B_size) == 1, "record B_size wrong alignment");
#endif
_Static_assert(sizeof(C) == 12, "record C wrong sizeof");
_Static_assert(_Alignof(C) == 4, "record C wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 16, "record C_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_alignment) == 4, "record C_alignment wrong alignment");
_Static_assert(sizeof(struct C_packed) == 12, "record C_packed wrong sizeof");
_Static_assert(_Alignof(struct C_packed) == 1, "record C_packed wrong alignment");
_Static_assert(sizeof(struct C_required_alignment) == 13, "record C_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "record C_required_alignment wrong alignment");
_Static_assert(sizeof(struct C_size) == 14, "record C_size wrong sizeof");
_Static_assert(_Alignof(struct C_size) == 1, "record C_size wrong alignment");
#endif
_Static_assert(sizeof(D) == 6, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 2, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 8, "record D_alignment wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 2, "record D_alignment wrong alignment");
_Static_assert(sizeof(struct D_packed) == 6, "record D_packed wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D_packed wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 7, "record D_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D_required_alignment wrong alignment");
_Static_assert(sizeof(struct D_size) == 8, "record D_size wrong sizeof");
_Static_assert(_Alignof(struct D_size) == 1, "record D_size wrong alignment");
#endif
_Static_assert(sizeof(E) == 8, "record E wrong sizeof");
_Static_assert(_Alignof(E) == 4, "record E wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 12, "record E_alignment wrong sizeof");
_Static_assert(_Alignof(struct E_alignment) == 4, "record E_alignment wrong alignment");
_Static_assert(sizeof(struct E_packed) == 8, "record E_packed wrong sizeof");
_Static_assert(_Alignof(struct E_packed) == 1, "record E_packed wrong alignment");
_Static_assert(sizeof(struct E_required_alignment) == 9, "record E_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "record E_required_alignment wrong alignment");
_Static_assert(sizeof(struct E_size) == 10, "record E_size wrong sizeof");
_Static_assert(_Alignof(struct E_size) == 1, "record E_size wrong alignment");
#endif
_Static_assert(sizeof(F) == 24, "record F wrong sizeof");
_Static_assert(_Alignof(F) == 4, "record F wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 28, "record F_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_alignment) == 4, "record F_alignment wrong alignment");
_Static_assert(sizeof(struct F_packed) == 24, "record F_packed wrong sizeof");
_Static_assert(_Alignof(struct F_packed) == 1, "record F_packed wrong alignment");
_Static_assert(sizeof(struct F_required_alignment) == 25, "record F_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "record F_required_alignment wrong alignment");
_Static_assert(sizeof(struct F_size) == 26, "record F_size wrong sizeof");
_Static_assert(_Alignof(struct F_size) == 1, "record F_size wrong alignment");
#endif
_Static_assert(sizeof(G) == 24, "record G wrong sizeof");
_Static_assert(_Alignof(G) == 8, "record G wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 32, "record G_alignment wrong sizeof");
_Static_assert(_Alignof(struct G_alignment) == 8, "record G_alignment wrong alignment");
_Static_assert(sizeof(struct G_packed) == 24, "record G_packed wrong sizeof");
_Static_assert(_Alignof(struct G_packed) == 1, "record G_packed wrong alignment");
_Static_assert(sizeof(struct G_required_alignment) == 25, "record G_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "record G_required_alignment wrong alignment");
_Static_assert(sizeof(struct G_size) == 26, "record G_size wrong sizeof");
_Static_assert(_Alignof(struct G_size) == 1, "record G_size wrong alignment");
#endif
_Static_assert(sizeof(H) == 128, "record H wrong sizeof");
_Static_assert(_Alignof(H) == 128, "record H wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 256, "record H_alignment wrong sizeof");
_Static_assert(_Alignof(struct H_alignment) == 128, "record H_alignment wrong alignment");
_Static_assert(sizeof(struct H_packed) == 128, "record H_packed wrong sizeof");
_Static_assert(_Alignof(struct H_packed) == 1, "record H_packed wrong alignment");
_Static_assert(sizeof(struct H_required_alignment) == 129, "record H_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "record H_required_alignment wrong alignment");
_Static_assert(sizeof(struct H_size) == 130, "record H_size wrong sizeof");
_Static_assert(_Alignof(struct H_size) == 1, "record H_size wrong alignment");
#endif
_Static_assert(sizeof(I) == 384, "record I wrong sizeof");
_Static_assert(_Alignof(I) == 128, "record I wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I_alignment) == 512, "record I_alignment wrong sizeof");
_Static_assert(_Alignof(struct I_alignment) == 128, "record I_alignment wrong alignment");
_Static_assert(sizeof(struct I_packed) == 384, "record I_packed wrong sizeof");
_Static_assert(_Alignof(struct I_packed) == 1, "record I_packed wrong alignment");
_Static_assert(sizeof(struct I_required_alignment) == 385, "record I_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct I_required_alignment) == 1, "record I_required_alignment wrong alignment");
_Static_assert(sizeof(struct I_size) == 386, "record I_size wrong sizeof");
_Static_assert(_Alignof(struct I_size) == 1, "record I_size wrong alignment");
#endif
_Static_assert(sizeof(J) == 0, "record J wrong sizeof");
_Static_assert(_Alignof(J) == 4, "record J wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J_alignment) == 4, "record J_alignment wrong sizeof");
_Static_assert(_Alignof(struct J_alignment) == 4, "record J_alignment wrong alignment");
_Static_assert(sizeof(struct J_packed) == 0, "record J_packed wrong sizeof");
_Static_assert(_Alignof(struct J_packed) == 1, "record J_packed wrong alignment");
_Static_assert(sizeof(struct J_required_alignment) == 1, "record J_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct J_required_alignment) == 1, "record J_required_alignment wrong alignment");
_Static_assert(sizeof(struct J_size) == 2, "record J_size wrong sizeof");
_Static_assert(_Alignof(struct J_size) == 1, "record J_size wrong alignment");
#endif
#elif defined(AARCH64_PC_WINDOWS_MSVC) ||  defined(I586_PC_WINDOWS_MSVC) ||  defined(I686_PC_WINDOWS_MSVC) ||  defined(I686_UNKNOWN_WINDOWS) ||  \
 defined(THUMBV7A_PC_WINDOWS_MSVC) ||  defined(X8664_PC_WINDOWS_MSVC) ||  defined(X8664_UNKNOWN_WINDOWS) 
_Static_assert(sizeof(A) == 3, "record A wrong sizeof");
_Static_assert(_Alignof(A) == 1, "record A wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 4, "record A_alignment wrong sizeof");
_Static_assert(_Alignof(struct A_alignment) == 1, "record A_alignment wrong alignment");
_Static_assert(sizeof(struct A_packed) == 3, "record A_packed wrong sizeof");
_Static_assert(_Alignof(struct A_packed) == 1, "record A_packed wrong alignment");
_Static_assert(sizeof(struct A_required_alignment) == 4, "record A_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "record A_required_alignment wrong alignment");
_Static_assert(sizeof(struct A_size) == 5, "record A_size wrong sizeof");
_Static_assert(_Alignof(struct A_size) == 1, "record A_size wrong alignment");
#endif
_Static_assert(sizeof(B) == 3, "record B wrong sizeof");
_Static_assert(_Alignof(B) == 4, "record B wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 8, "record B_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_alignment) == 4, "record B_alignment wrong alignment");
_Static_assert(sizeof(struct B_packed) == 3, "record B_packed wrong sizeof");
_Static_assert(_Alignof(struct B_packed) == 1, "record B_packed wrong alignment");
_Static_assert(sizeof(struct B_required_alignment) == 4, "record B_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "record B_required_alignment wrong alignment");
_Static_assert(sizeof(struct B_size) == 5, "record B_size wrong sizeof");
_Static_assert(_Alignof(struct B_size) == 1, "record B_size wrong alignment");
#endif
_Static_assert(sizeof(C) == 9, "record C wrong sizeof");
_Static_assert(_Alignof(C) == 4, "record C wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 13, "record C_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_alignment) == 4, "record C_alignment wrong alignment");
_Static_assert(sizeof(struct C_packed) == 9, "record C_packed wrong sizeof");
_Static_assert(_Alignof(struct C_packed) == 1, "record C_packed wrong alignment");
_Static_assert(sizeof(struct C_required_alignment) == 10, "record C_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "record C_required_alignment wrong alignment");
_Static_assert(sizeof(struct C_size) == 11, "record C_size wrong sizeof");
_Static_assert(_Alignof(struct C_size) == 1, "record C_size wrong alignment");
#endif
_Static_assert(sizeof(D) == 6, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 2, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 8, "record D_alignment wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 2, "record D_alignment wrong alignment");
_Static_assert(sizeof(struct D_packed) == 6, "record D_packed wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D_packed wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 7, "record D_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D_required_alignment wrong alignment");
_Static_assert(sizeof(struct D_size) == 8, "record D_size wrong sizeof");
_Static_assert(_Alignof(struct D_size) == 1, "record D_size wrong alignment");
#endif
_Static_assert(sizeof(E) == 6, "record E wrong sizeof");
_Static_assert(_Alignof(E) == 4, "record E wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 10, "record E_alignment wrong sizeof");
_Static_assert(_Alignof(struct E_alignment) == 4, "record E_alignment wrong alignment");
_Static_assert(sizeof(struct E_packed) == 6, "record E_packed wrong sizeof");
_Static_assert(_Alignof(struct E_packed) == 1, "record E_packed wrong alignment");
_Static_assert(sizeof(struct E_required_alignment) == 7, "record E_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "record E_required_alignment wrong alignment");
_Static_assert(sizeof(struct E_size) == 8, "record E_size wrong sizeof");
_Static_assert(_Alignof(struct E_size) == 1, "record E_size wrong alignment");
#endif
_Static_assert(sizeof(F) == 18, "record F wrong sizeof");
_Static_assert(_Alignof(F) == 4, "record F wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 22, "record F_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_alignment) == 4, "record F_alignment wrong alignment");
_Static_assert(sizeof(struct F_packed) == 18, "record F_packed wrong sizeof");
_Static_assert(_Alignof(struct F_packed) == 1, "record F_packed wrong alignment");
_Static_assert(sizeof(struct F_required_alignment) == 19, "record F_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "record F_required_alignment wrong alignment");
_Static_assert(sizeof(struct F_size) == 20, "record F_size wrong sizeof");
_Static_assert(_Alignof(struct F_size) == 1, "record F_size wrong alignment");
#endif
_Static_assert(sizeof(G) == 24, "record G wrong sizeof");
_Static_assert(_Alignof(G) == 8, "record G wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 32, "record G_alignment wrong sizeof");
_Static_assert(_Alignof(struct G_alignment) == 8, "record G_alignment wrong alignment");
_Static_assert(sizeof(struct G_packed) == 24, "record G_packed wrong sizeof");
_Static_assert(_Alignof(struct G_packed) == 1, "record G_packed wrong alignment");
_Static_assert(sizeof(struct G_required_alignment) == 25, "record G_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "record G_required_alignment wrong alignment");
_Static_assert(sizeof(struct G_size) == 26, "record G_size wrong sizeof");
_Static_assert(_Alignof(struct G_size) == 1, "record G_size wrong alignment");
#endif
_Static_assert(sizeof(H) == 24, "record H wrong sizeof");
_Static_assert(_Alignof(H) == 128, "record H wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 256, "record H_alignment wrong sizeof");
_Static_assert(_Alignof(struct H_alignment) == 128, "record H_alignment wrong alignment");
_Static_assert(sizeof(struct H_packed) == 24, "record H_packed wrong sizeof");
_Static_assert(_Alignof(struct H_packed) == 1, "record H_packed wrong alignment");
_Static_assert(sizeof(struct H_required_alignment) == 25, "record H_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "record H_required_alignment wrong alignment");
_Static_assert(sizeof(struct H_size) == 26, "record H_size wrong sizeof");
_Static_assert(_Alignof(struct H_size) == 1, "record H_size wrong alignment");
#endif
_Static_assert(sizeof(I) == 72, "record I wrong sizeof");
_Static_assert(_Alignof(I) == 128, "record I wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I_alignment) == 256, "record I_alignment wrong sizeof");
_Static_assert(_Alignof(struct I_alignment) == 128, "record I_alignment wrong alignment");
_Static_assert(sizeof(struct I_packed) == 72, "record I_packed wrong sizeof");
_Static_assert(_Alignof(struct I_packed) == 1, "record I_packed wrong alignment");
_Static_assert(sizeof(struct I_required_alignment) == 73, "record I_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct I_required_alignment) == 1, "record I_required_alignment wrong alignment");
_Static_assert(sizeof(struct I_size) == 74, "record I_size wrong sizeof");
_Static_assert(_Alignof(struct I_size) == 1, "record I_size wrong alignment");
#endif
_Static_assert(sizeof(J) == 0, "record J wrong sizeof");
_Static_assert(_Alignof(J) == 4, "record J wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J_alignment) == 4, "record J_alignment wrong sizeof");
_Static_assert(_Alignof(struct J_alignment) == 4, "record J_alignment wrong alignment");
_Static_assert(sizeof(struct J_packed) == 0, "record J_packed wrong sizeof");
_Static_assert(_Alignof(struct J_packed) == 1, "record J_packed wrong alignment");
_Static_assert(sizeof(struct J_required_alignment) == 1, "record J_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct J_required_alignment) == 1, "record J_required_alignment wrong alignment");
_Static_assert(sizeof(struct J_size) == 2, "record J_size wrong sizeof");
_Static_assert(_Alignof(struct J_size) == 1, "record J_size wrong alignment");
#endif
#elif defined(ARMV7_APPLE_IOS) ||  defined(ARMV7S_APPLE_IOS) ||  defined(I386_APPLE_IOS) ||  defined(I686_APPLE_MACOSX) ||  defined(I686_LINUX_ANDROID) ||  \
 defined(I686_UNKNOWN_FREEBSD) ||  defined(I686_UNKNOWN_HAIKU) ||  defined(I686_UNKNOWN_NETBSDELF) ||  defined(I686_UNKNOWN_OPENBSD) 
_Static_assert(sizeof(A) == 3, "record A wrong sizeof");
_Static_assert(_Alignof(A) == 1, "record A wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 4, "record A_alignment wrong sizeof");
_Static_assert(_Alignof(struct A_alignment) == 1, "record A_alignment wrong alignment");
_Static_assert(sizeof(struct A_packed) == 3, "record A_packed wrong sizeof");
_Static_assert(_Alignof(struct A_packed) == 1, "record A_packed wrong alignment");
_Static_assert(sizeof(struct A_required_alignment) == 4, "record A_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "record A_required_alignment wrong alignment");
_Static_assert(sizeof(struct A_size) == 5, "record A_size wrong sizeof");
_Static_assert(_Alignof(struct A_size) == 1, "record A_size wrong alignment");
#endif
_Static_assert(sizeof(B) == 4, "record B wrong sizeof");
_Static_assert(_Alignof(B) == 4, "record B wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 8, "record B_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_alignment) == 4, "record B_alignment wrong alignment");
_Static_assert(sizeof(struct B_packed) == 4, "record B_packed wrong sizeof");
_Static_assert(_Alignof(struct B_packed) == 1, "record B_packed wrong alignment");
_Static_assert(sizeof(struct B_required_alignment) == 5, "record B_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "record B_required_alignment wrong alignment");
_Static_assert(sizeof(struct B_size) == 6, "record B_size wrong sizeof");
_Static_assert(_Alignof(struct B_size) == 1, "record B_size wrong alignment");
#endif
_Static_assert(sizeof(C) == 12, "record C wrong sizeof");
_Static_assert(_Alignof(C) == 4, "record C wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 16, "record C_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_alignment) == 4, "record C_alignment wrong alignment");
_Static_assert(sizeof(struct C_packed) == 12, "record C_packed wrong sizeof");
_Static_assert(_Alignof(struct C_packed) == 1, "record C_packed wrong alignment");
_Static_assert(sizeof(struct C_required_alignment) == 13, "record C_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "record C_required_alignment wrong alignment");
_Static_assert(sizeof(struct C_size) == 14, "record C_size wrong sizeof");
_Static_assert(_Alignof(struct C_size) == 1, "record C_size wrong alignment");
#endif
_Static_assert(sizeof(D) == 6, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 2, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 8, "record D_alignment wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 2, "record D_alignment wrong alignment");
_Static_assert(sizeof(struct D_packed) == 6, "record D_packed wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D_packed wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 7, "record D_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D_required_alignment wrong alignment");
_Static_assert(sizeof(struct D_size) == 8, "record D_size wrong sizeof");
_Static_assert(_Alignof(struct D_size) == 1, "record D_size wrong alignment");
#endif
_Static_assert(sizeof(E) == 8, "record E wrong sizeof");
_Static_assert(_Alignof(E) == 4, "record E wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 12, "record E_alignment wrong sizeof");
_Static_assert(_Alignof(struct E_alignment) == 4, "record E_alignment wrong alignment");
_Static_assert(sizeof(struct E_packed) == 8, "record E_packed wrong sizeof");
_Static_assert(_Alignof(struct E_packed) == 1, "record E_packed wrong alignment");
_Static_assert(sizeof(struct E_required_alignment) == 9, "record E_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "record E_required_alignment wrong alignment");
_Static_assert(sizeof(struct E_size) == 10, "record E_size wrong sizeof");
_Static_assert(_Alignof(struct E_size) == 1, "record E_size wrong alignment");
#endif
_Static_assert(sizeof(F) == 24, "record F wrong sizeof");
_Static_assert(_Alignof(F) == 4, "record F wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 28, "record F_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_alignment) == 4, "record F_alignment wrong alignment");
_Static_assert(sizeof(struct F_packed) == 24, "record F_packed wrong sizeof");
_Static_assert(_Alignof(struct F_packed) == 1, "record F_packed wrong alignment");
_Static_assert(sizeof(struct F_required_alignment) == 25, "record F_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "record F_required_alignment wrong alignment");
_Static_assert(sizeof(struct F_size) == 26, "record F_size wrong sizeof");
_Static_assert(_Alignof(struct F_size) == 1, "record F_size wrong alignment");
#endif
_Static_assert(sizeof(G) == 24, "record G wrong sizeof");
_Static_assert(_Alignof(G) == 4, "record G wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 28, "record G_alignment wrong sizeof");
_Static_assert(_Alignof(struct G_alignment) == 4, "record G_alignment wrong alignment");
_Static_assert(sizeof(struct G_packed) == 24, "record G_packed wrong sizeof");
_Static_assert(_Alignof(struct G_packed) == 1, "record G_packed wrong alignment");
_Static_assert(sizeof(struct G_required_alignment) == 25, "record G_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "record G_required_alignment wrong alignment");
_Static_assert(sizeof(struct G_size) == 26, "record G_size wrong sizeof");
_Static_assert(_Alignof(struct G_size) == 1, "record G_size wrong alignment");
#endif
_Static_assert(sizeof(H) == 128, "record H wrong sizeof");
_Static_assert(_Alignof(H) == 128, "record H wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 256, "record H_alignment wrong sizeof");
_Static_assert(_Alignof(struct H_alignment) == 128, "record H_alignment wrong alignment");
_Static_assert(sizeof(struct H_packed) == 128, "record H_packed wrong sizeof");
_Static_assert(_Alignof(struct H_packed) == 1, "record H_packed wrong alignment");
_Static_assert(sizeof(struct H_required_alignment) == 129, "record H_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "record H_required_alignment wrong alignment");
_Static_assert(sizeof(struct H_size) == 130, "record H_size wrong sizeof");
_Static_assert(_Alignof(struct H_size) == 1, "record H_size wrong alignment");
#endif
_Static_assert(sizeof(I) == 384, "record I wrong sizeof");
_Static_assert(_Alignof(I) == 128, "record I wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I_alignment) == 512, "record I_alignment wrong sizeof");
_Static_assert(_Alignof(struct I_alignment) == 128, "record I_alignment wrong alignment");
_Static_assert(sizeof(struct I_packed) == 384, "record I_packed wrong sizeof");
_Static_assert(_Alignof(struct I_packed) == 1, "record I_packed wrong alignment");
_Static_assert(sizeof(struct I_required_alignment) == 385, "record I_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct I_required_alignment) == 1, "record I_required_alignment wrong alignment");
_Static_assert(sizeof(struct I_size) == 386, "record I_size wrong sizeof");
_Static_assert(_Alignof(struct I_size) == 1, "record I_size wrong alignment");
#endif
_Static_assert(sizeof(J) == 0, "record J wrong sizeof");
_Static_assert(_Alignof(J) == 4, "record J wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J_alignment) == 4, "record J_alignment wrong sizeof");
_Static_assert(_Alignof(struct J_alignment) == 4, "record J_alignment wrong alignment");
_Static_assert(sizeof(struct J_packed) == 0, "record J_packed wrong sizeof");
_Static_assert(_Alignof(struct J_packed) == 1, "record J_packed wrong alignment");
_Static_assert(sizeof(struct J_required_alignment) == 1, "record J_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct J_required_alignment) == 1, "record J_required_alignment wrong alignment");
_Static_assert(sizeof(struct J_size) == 2, "record J_size wrong sizeof");
_Static_assert(_Alignof(struct J_size) == 1, "record J_size wrong alignment");
#endif
#elif defined(MSP430_NONE_ELF) 
_Static_assert(sizeof(A) == 3, "record A wrong sizeof");
_Static_assert(_Alignof(A) == 1, "record A wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 4, "record A_alignment wrong sizeof");
_Static_assert(_Alignof(struct A_alignment) == 1, "record A_alignment wrong alignment");
_Static_assert(sizeof(struct A_packed) == 3, "record A_packed wrong sizeof");
_Static_assert(_Alignof(struct A_packed) == 1, "record A_packed wrong alignment");
_Static_assert(sizeof(struct A_required_alignment) == 4, "record A_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "record A_required_alignment wrong alignment");
_Static_assert(sizeof(struct A_size) == 5, "record A_size wrong sizeof");
_Static_assert(_Alignof(struct A_size) == 1, "record A_size wrong alignment");
#endif
_Static_assert(sizeof(B) == 4, "record B wrong sizeof");
_Static_assert(_Alignof(B) == 4, "record B wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 8, "record B_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_alignment) == 4, "record B_alignment wrong alignment");
_Static_assert(sizeof(struct B_packed) == 4, "record B_packed wrong sizeof");
_Static_assert(_Alignof(struct B_packed) == 1, "record B_packed wrong alignment");
_Static_assert(sizeof(struct B_required_alignment) == 5, "record B_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "record B_required_alignment wrong alignment");
_Static_assert(sizeof(struct B_size) == 6, "record B_size wrong sizeof");
_Static_assert(_Alignof(struct B_size) == 1, "record B_size wrong alignment");
#endif
_Static_assert(sizeof(C) == 12, "record C wrong sizeof");
_Static_assert(_Alignof(C) == 4, "record C wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 16, "record C_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_alignment) == 4, "record C_alignment wrong alignment");
_Static_assert(sizeof(struct C_packed) == 12, "record C_packed wrong sizeof");
_Static_assert(_Alignof(struct C_packed) == 1, "record C_packed wrong alignment");
_Static_assert(sizeof(struct C_required_alignment) == 13, "record C_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "record C_required_alignment wrong alignment");
_Static_assert(sizeof(struct C_size) == 14, "record C_size wrong sizeof");
_Static_assert(_Alignof(struct C_size) == 1, "record C_size wrong alignment");
#endif
_Static_assert(sizeof(D) == 6, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 2, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 8, "record D_alignment wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 2, "record D_alignment wrong alignment");
_Static_assert(sizeof(struct D_packed) == 6, "record D_packed wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D_packed wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 7, "record D_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D_required_alignment wrong alignment");
_Static_assert(sizeof(struct D_size) == 8, "record D_size wrong sizeof");
_Static_assert(_Alignof(struct D_size) == 1, "record D_size wrong alignment");
#endif
_Static_assert(sizeof(E) == 8, "record E wrong sizeof");
_Static_assert(_Alignof(E) == 4, "record E wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 12, "record E_alignment wrong sizeof");
_Static_assert(_Alignof(struct E_alignment) == 4, "record E_alignment wrong alignment");
_Static_assert(sizeof(struct E_packed) == 8, "record E_packed wrong sizeof");
_Static_assert(_Alignof(struct E_packed) == 1, "record E_packed wrong alignment");
_Static_assert(sizeof(struct E_required_alignment) == 9, "record E_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "record E_required_alignment wrong alignment");
_Static_assert(sizeof(struct E_size) == 10, "record E_size wrong sizeof");
_Static_assert(_Alignof(struct E_size) == 1, "record E_size wrong alignment");
#endif
_Static_assert(sizeof(F) == 24, "record F wrong sizeof");
_Static_assert(_Alignof(F) == 4, "record F wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 28, "record F_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_alignment) == 4, "record F_alignment wrong alignment");
_Static_assert(sizeof(struct F_packed) == 24, "record F_packed wrong sizeof");
_Static_assert(_Alignof(struct F_packed) == 1, "record F_packed wrong alignment");
_Static_assert(sizeof(struct F_required_alignment) == 25, "record F_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "record F_required_alignment wrong alignment");
_Static_assert(sizeof(struct F_size) == 26, "record F_size wrong sizeof");
_Static_assert(_Alignof(struct F_size) == 1, "record F_size wrong alignment");
#endif
_Static_assert(sizeof(G) == 24, "record G wrong sizeof");
_Static_assert(_Alignof(G) == 2, "record G wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 26, "record G_alignment wrong sizeof");
_Static_assert(_Alignof(struct G_alignment) == 2, "record G_alignment wrong alignment");
_Static_assert(sizeof(struct G_packed) == 24, "record G_packed wrong sizeof");
_Static_assert(_Alignof(struct G_packed) == 1, "record G_packed wrong alignment");
_Static_assert(sizeof(struct G_required_alignment) == 25, "record G_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "record G_required_alignment wrong alignment");
_Static_assert(sizeof(struct G_size) == 26, "record G_size wrong sizeof");
_Static_assert(_Alignof(struct G_size) == 1, "record G_size wrong alignment");
#endif
_Static_assert(sizeof(H) == 128, "record H wrong sizeof");
_Static_assert(_Alignof(H) == 128, "record H wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 256, "record H_alignment wrong sizeof");
_Static_assert(_Alignof(struct H_alignment) == 128, "record H_alignment wrong alignment");
_Static_assert(sizeof(struct H_packed) == 128, "record H_packed wrong sizeof");
_Static_assert(_Alignof(struct H_packed) == 1, "record H_packed wrong alignment");
_Static_assert(sizeof(struct H_required_alignment) == 129, "record H_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "record H_required_alignment wrong alignment");
_Static_assert(sizeof(struct H_size) == 130, "record H_size wrong sizeof");
_Static_assert(_Alignof(struct H_size) == 1, "record H_size wrong alignment");
#endif
_Static_assert(sizeof(I) == 384, "record I wrong sizeof");
_Static_assert(_Alignof(I) == 128, "record I wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I_alignment) == 512, "record I_alignment wrong sizeof");
_Static_assert(_Alignof(struct I_alignment) == 128, "record I_alignment wrong alignment");
_Static_assert(sizeof(struct I_packed) == 384, "record I_packed wrong sizeof");
_Static_assert(_Alignof(struct I_packed) == 1, "record I_packed wrong alignment");
_Static_assert(sizeof(struct I_required_alignment) == 385, "record I_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct I_required_alignment) == 1, "record I_required_alignment wrong alignment");
_Static_assert(sizeof(struct I_size) == 386, "record I_size wrong sizeof");
_Static_assert(_Alignof(struct I_size) == 1, "record I_size wrong alignment");
#endif
_Static_assert(sizeof(J) == 0, "record J wrong sizeof");
_Static_assert(_Alignof(J) == 2, "record J wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J_alignment) == 2, "record J_alignment wrong sizeof");
_Static_assert(_Alignof(struct J_alignment) == 2, "record J_alignment wrong alignment");
_Static_assert(sizeof(struct J_packed) == 0, "record J_packed wrong sizeof");
_Static_assert(_Alignof(struct J_packed) == 1, "record J_packed wrong alignment");
_Static_assert(sizeof(struct J_required_alignment) == 1, "record J_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct J_required_alignment) == 1, "record J_required_alignment wrong alignment");
_Static_assert(sizeof(struct J_size) == 2, "record J_size wrong sizeof");
_Static_assert(_Alignof(struct J_size) == 1, "record J_size wrong alignment");
#endif
#endif
