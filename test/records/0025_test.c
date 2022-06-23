// SPDX-License-Identifier: GPL-3.0-or-later

// This test file is auto-generated. do not edit.
// This file is a derivative work from the test files found// in this repo : https://github.com/mahkoh/repr-c
// and is under the same licence as the original work.

#pragma pack(4)
typedef struct {
#ifdef MSVC
    __declspec(align(8)) char:1;
#else
    char:1 __attribute__((aligned(8)));
#endif
} A;
A var1;
#pragma pack()
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
typedef A unnamed_type_5[];
#else
typedef A unnamed_type_5[0];
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

typedef union {
    unnamed_type_5 a;
} BA;
BA var10;
struct BA_alignment {
#ifdef MSVC
    char a[_Alignof(BA)];
    char b;
#else
    char a;
    BA b;
#endif
};
struct BA_alignment var11;
#pragma pack(1)
struct BA_packed {
    BA a;
};
#pragma pack()
struct BA_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct BA_packed)];
    char b;
#else
    char a;
    struct BA_packed b;
#endif
};
struct BA_required_alignment var12;
struct BA_size {
    char a[sizeof(BA)+1];
    char b;
};
struct BA_size var13;

#ifdef MSVC
typedef A unnamed_type_14[];
#else
typedef A unnamed_type_14[0];
#endif
unnamed_type_14 var15;
struct unnamed_type_14_alignment {
#ifdef MSVC
    char a[_Alignof(unnamed_type_14)];
    char b;
#else
    char a;
    unnamed_type_14 b;
#endif
};
struct unnamed_type_14_alignment var16;
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
struct unnamed_type_14_required_alignment var17;
struct unnamed_type_14_size {
    char a[sizeof(unnamed_type_14)+1];
    char b;
};
struct unnamed_type_14_size var18;

typedef union {
#ifdef MSVC
    __declspec(align(16)) char:0;
#else
    char:0 __attribute__((aligned(16)));
#endif
    unnamed_type_14 a;
} BB;
BB var19;
struct BB_alignment {
#ifdef MSVC
    char a[_Alignof(BB)];
    char b;
#else
    char a;
    BB b;
#endif
};
struct BB_alignment var20;
#pragma pack(1)
struct BB_packed {
    BB a;
};
#pragma pack()
struct BB_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct BB_packed)];
    char b;
#else
    char a;
    struct BB_packed b;
#endif
};
struct BB_required_alignment var21;
struct BB_size {
    char a[sizeof(BB)+1];
    char b;
};
struct BB_size var22;

#ifdef MSVC
typedef A unnamed_type_23[];
#else
typedef A unnamed_type_23[0];
#endif
unnamed_type_23 var24;
struct unnamed_type_23_alignment {
#ifdef MSVC
    char a[_Alignof(unnamed_type_23)];
    char b;
#else
    char a;
    unnamed_type_23 b;
#endif
};
struct unnamed_type_23_alignment var25;
#pragma pack(1)
struct unnamed_type_23_packed {
    unnamed_type_23 a;
};
#pragma pack()
struct unnamed_type_23_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct unnamed_type_23_packed)];
    char b;
#else
    char a;
    struct unnamed_type_23_packed b;
#endif
};
struct unnamed_type_23_required_alignment var26;
struct unnamed_type_23_size {
    char a[sizeof(unnamed_type_23)+1];
    char b;
};
struct unnamed_type_23_size var27;

typedef union {
    unnamed_type_23 a;
#ifdef MSVC
    __declspec(align(16)) char:0;
#else
    char:0 __attribute__((aligned(16)));
#endif
} BC;
BC var28;
struct BC_alignment {
#ifdef MSVC
    char a[_Alignof(BC)];
    char b;
#else
    char a;
    BC b;
#endif
};
struct BC_alignment var29;
#pragma pack(1)
struct BC_packed {
    BC a;
};
#pragma pack()
struct BC_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct BC_packed)];
    char b;
#else
    char a;
    struct BC_packed b;
#endif
};
struct BC_required_alignment var30;
struct BC_size {
    char a[sizeof(BC)+1];
    char b;
};
struct BC_size var31;

#ifdef MSVC
typedef A unnamed_type_32[];
#else
typedef A unnamed_type_32[0];
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

#ifdef MSVC
__declspec(align(16)) typedef union {
#else
typedef union {
#endif
    unnamed_type_32 a;
#ifdef MSVC
} BD;
#else
} __attribute__((aligned(16))) BD;
#endif
BD var37;
struct BD_alignment {
#ifdef MSVC
    char a[_Alignof(BD)];
    char b;
#else
    char a;
    BD b;
#endif
};
struct BD_alignment var38;
#pragma pack(1)
struct BD_packed {
    BD a;
};
#pragma pack()
struct BD_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct BD_packed)];
    char b;
#else
    char a;
    struct BD_packed b;
#endif
};
struct BD_required_alignment var39;
struct BD_size {
    char a[sizeof(BD)+1];
    char b;
};
struct BD_size var40;

#ifdef MSVC
typedef A unnamed_type_41[];
#else
typedef A unnamed_type_41[0];
#endif
unnamed_type_41 var42;
struct unnamed_type_41_alignment {
#ifdef MSVC
    char a[_Alignof(unnamed_type_41)];
    char b;
#else
    char a;
    unnamed_type_41 b;
#endif
};
struct unnamed_type_41_alignment var43;
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
struct unnamed_type_41_required_alignment var44;
struct unnamed_type_41_size {
    char a[sizeof(unnamed_type_41)+1];
    char b;
};
struct unnamed_type_41_size var45;

#ifdef MSVC
__declspec(align(2)) typedef union {
#else
typedef union {
#endif
    unnamed_type_41 a;
#ifdef MSVC
} BE;
#else
} __attribute__((aligned(2))) BE;
#endif
BE var46;
struct BE_alignment {
#ifdef MSVC
    char a[_Alignof(BE)];
    char b;
#else
    char a;
    BE b;
#endif
};
struct BE_alignment var47;
#pragma pack(1)
struct BE_packed {
    BE a;
};
#pragma pack()
struct BE_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct BE_packed)];
    char b;
#else
    char a;
    struct BE_packed b;
#endif
};
struct BE_required_alignment var48;
struct BE_size {
    char a[sizeof(BE)+1];
    char b;
};
struct BE_size var49;

#ifdef MSVC
__declspec(align(8)) typedef char C;
#else
typedef char C __attribute__((aligned(8)));
#endif
C var50;
struct C_alignment {
#ifdef MSVC
    char a[_Alignof(C)];
    char b;
#else
    char a;
    C b;
#endif
};
struct C_alignment var51;
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
struct C_required_alignment var52;
struct C_size {
    char a[sizeof(C)+1];
    char b;
};
struct C_size var53;

#ifdef MSVC
typedef C unnamed_type_54[];
#else
typedef C unnamed_type_54[0];
#endif
unnamed_type_54 var55;
struct unnamed_type_54_alignment {
#ifdef MSVC
    char a[_Alignof(unnamed_type_54)];
    char b;
#else
    char a;
    unnamed_type_54 b;
#endif
};
struct unnamed_type_54_alignment var56;
#pragma pack(1)
struct unnamed_type_54_packed {
    unnamed_type_54 a;
};
#pragma pack()
struct unnamed_type_54_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct unnamed_type_54_packed)];
    char b;
#else
    char a;
    struct unnamed_type_54_packed b;
#endif
};
struct unnamed_type_54_required_alignment var57;
struct unnamed_type_54_size {
    char a[sizeof(unnamed_type_54)+1];
    char b;
};
struct unnamed_type_54_size var58;

typedef union {
    unnamed_type_54 a;
} D;
D var59;
struct D_alignment {
#ifdef MSVC
    char a[_Alignof(D)];
    char b;
#else
    char a;
    D b;
#endif
};
struct D_alignment var60;
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
struct D_required_alignment var61;
struct D_size {
    char a[sizeof(D)+1];
    char b;
};
struct D_size var62;

typedef union {
    char:0;
} E;
E var63;
struct E_alignment {
#ifdef MSVC
    char a[_Alignof(E)];
    char b;
#else
    char a;
    E b;
#endif
};
struct E_alignment var64;
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
struct E_required_alignment var65;
struct E_size {
    char a[sizeof(E)+1];
    char b;
};
struct E_size var66;

typedef union {
    int:0;
} F;
F var67;
struct F_alignment {
#ifdef MSVC
    char a[_Alignof(F)];
    char b;
#else
    char a;
    F b;
#endif
};
struct F_alignment var68;
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
struct F_required_alignment var69;
struct F_size {
    char a[sizeof(F)+1];
    char b;
};
struct F_size var70;

typedef union {
    long long:0;
} G;
G var71;
struct G_alignment {
#ifdef MSVC
    char a[_Alignof(G)];
    char b;
#else
    char a;
    G b;
#endif
};
struct G_alignment var72;
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
struct G_required_alignment var73;
struct G_size {
    char a[sizeof(G)+1];
    char b;
};
struct G_size var74;

typedef union {
    char:0;
    long long:0;
} H;
H var75;
struct H_alignment {
#ifdef MSVC
    char a[_Alignof(H)];
    char b;
#else
    char a;
    H b;
#endif
};
struct H_alignment var76;
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
struct H_required_alignment var77;
struct H_size {
    char a[sizeof(H)+1];
    char b;
};
struct H_size var78;

#ifdef MSVC
typedef char unnamed_type_79[];
#else
typedef char unnamed_type_79[0];
#endif
unnamed_type_79 var80;
struct unnamed_type_79_alignment {
#ifdef MSVC
    char a[_Alignof(unnamed_type_79)];
    char b;
#else
    char a;
    unnamed_type_79 b;
#endif
};
struct unnamed_type_79_alignment var81;
#pragma pack(1)
struct unnamed_type_79_packed {
    unnamed_type_79 a;
};
#pragma pack()
struct unnamed_type_79_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct unnamed_type_79_packed)];
    char b;
#else
    char a;
    struct unnamed_type_79_packed b;
#endif
};
struct unnamed_type_79_required_alignment var82;
struct unnamed_type_79_size {
    char a[sizeof(unnamed_type_79)+1];
    char b;
};
struct unnamed_type_79_size var83;

typedef union {
    unnamed_type_79 c;
} I;
I var84;
struct I_alignment {
#ifdef MSVC
    char a[_Alignof(I)];
    char b;
#else
    char a;
    I b;
#endif
};
struct I_alignment var85;
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
struct I_required_alignment var86;
struct I_size {
    char a[sizeof(I)+1];
    char b;
};
struct I_size var87;

#if defined(AARCH64_APPLE_MACOSX) ||  defined(ARM64_APPLE_IOS) ||  defined(ARM64_APPLE_IOS_MACABI) ||  defined(ARM64_APPLE_TVOS) ||  \
 defined(HEXAGON_UNKNOWN_LINUX_MUSL) ||  defined(MIPSEL_SONY_PSP) ||  defined(MIPSEL_UNKNOWN_NONE) ||  defined(POWERPC64_UNKNOWN_FREEBSD) ||  \
 defined(POWERPC_UNKNOWN_LINUX_GNUSPE) ||  defined(POWERPC_UNKNOWN_NETBSD) ||  defined(RISCV32) ||  defined(RISCV64) ||  defined(SPARC64_UNKNOWN_NETBSD) ||  \
 defined(SPARC64_UNKNOWN_OPENBSD) ||  defined(SPARCV9_SUN_SOLARIS) ||  defined(WASM32_UNKNOWN_EMSCRIPTEN) ||  defined(WASM32_UNKNOWN_UNKNOWN) ||  \
 defined(WASM32_WASI) ||  defined(X8664_APPLE_IOS_MACABI) ||  defined(X8664_APPLE_IOS) ||  defined(X8664_APPLE_MACOSX) ||  defined(X8664_APPLE_TVOS) ||  \
 defined(X8664_ELF) ||  defined(X8664_FUCHSIA) ||  defined(X8664_LINUX_ANDROID) ||  defined(X8664_PC_SOLARIS) ||  defined(X8664_RUMPRUN_NETBSD) ||  \
 defined(X8664_UNKNOWN_DRAGONFLY) ||  defined(X8664_UNKNOWN_FREEBSD) ||  defined(X8664_UNKNOWN_HAIKU) ||  defined(X8664_UNKNOWN_HERMIT) ||  \
 defined(X8664_UNKNOWN_L4RE_UCLIBC) ||  defined(X8664_UNKNOWN_NETBSD) ||  defined(X8664_UNKNOWN_OPENBSD) ||  defined(X8664_UNKNOWN_REDOX) 
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
_Static_assert(sizeof(BA) == 0, "record BA wrong sizeof");
_Static_assert(_Alignof(BA) == 1, "record BA wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct BA_alignment) == 1, "record BA wrong sizeof");
_Static_assert(_Alignof(struct BA_alignment) == 1, "record BA wrong alignment");
_Static_assert(sizeof(struct BA_packed) == 0, "record BA wrong sizeof");
_Static_assert(_Alignof(struct BA_packed) == 1, "record BA wrong alignment");
_Static_assert(sizeof(struct BA_required_alignment) == 1, "record BA wrong sizeof");
_Static_assert(_Alignof(struct BA_required_alignment) == 1, "record BA wrong alignment");
_Static_assert(sizeof(struct BA_size) == 2, "record BA wrong sizeof");
_Static_assert(_Alignof(struct BA_size) == 1, "record BA wrong alignment");
#endif
_Static_assert(sizeof(BB) == 0, "record BB wrong sizeof");
_Static_assert(_Alignof(BB) == 1, "record BB wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct BB_alignment) == 1, "record BB wrong sizeof");
_Static_assert(_Alignof(struct BB_alignment) == 1, "record BB wrong alignment");
_Static_assert(sizeof(struct BB_packed) == 0, "record BB wrong sizeof");
_Static_assert(_Alignof(struct BB_packed) == 1, "record BB wrong alignment");
_Static_assert(sizeof(struct BB_required_alignment) == 1, "record BB wrong sizeof");
_Static_assert(_Alignof(struct BB_required_alignment) == 1, "record BB wrong alignment");
_Static_assert(sizeof(struct BB_size) == 2, "record BB wrong sizeof");
_Static_assert(_Alignof(struct BB_size) == 1, "record BB wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(BB,a) == 0, "field BB.a wrong bit offset");
#endif
_Static_assert(sizeof(BC) == 0, "record BC wrong sizeof");
_Static_assert(_Alignof(BC) == 1, "record BC wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct BC_alignment) == 1, "record BC wrong sizeof");
_Static_assert(_Alignof(struct BC_alignment) == 1, "record BC wrong alignment");
_Static_assert(sizeof(struct BC_packed) == 0, "record BC wrong sizeof");
_Static_assert(_Alignof(struct BC_packed) == 1, "record BC wrong alignment");
_Static_assert(sizeof(struct BC_required_alignment) == 1, "record BC wrong sizeof");
_Static_assert(_Alignof(struct BC_required_alignment) == 1, "record BC wrong alignment");
_Static_assert(sizeof(struct BC_size) == 2, "record BC wrong sizeof");
_Static_assert(_Alignof(struct BC_size) == 1, "record BC wrong alignment");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(BD) == 0, "record BD wrong sizeof");
_Static_assert(_Alignof(BD) == 16, "record BD wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct BD_alignment) == 16, "record BD wrong sizeof");
_Static_assert(_Alignof(struct BD_alignment) == 16, "record BD wrong alignment");
_Static_assert(sizeof(struct BD_packed) == 0, "record BD wrong sizeof");
_Static_assert(_Alignof(struct BD_packed) == 1, "record BD wrong alignment");
_Static_assert(sizeof(struct BD_required_alignment) == 1, "record BD wrong sizeof");
_Static_assert(_Alignof(struct BD_required_alignment) == 1, "record BD wrong alignment");
_Static_assert(sizeof(struct BD_size) == 2, "record BD wrong sizeof");
_Static_assert(_Alignof(struct BD_size) == 1, "record BD wrong alignment");
#endif
_Static_assert(sizeof(BE) == 0, "record BE wrong sizeof");
_Static_assert(_Alignof(BE) == 2, "record BE wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct BE_alignment) == 2, "record BE wrong sizeof");
_Static_assert(_Alignof(struct BE_alignment) == 2, "record BE wrong alignment");
_Static_assert(sizeof(struct BE_packed) == 0, "record BE wrong sizeof");
_Static_assert(_Alignof(struct BE_packed) == 1, "record BE wrong alignment");
_Static_assert(sizeof(struct BE_required_alignment) == 1, "record BE wrong sizeof");
_Static_assert(_Alignof(struct BE_required_alignment) == 1, "record BE wrong alignment");
_Static_assert(sizeof(struct BE_size) == 2, "record BE wrong sizeof");
_Static_assert(_Alignof(struct BE_size) == 1, "record BE wrong alignment");
#endif
_Static_assert(sizeof(C) == 1, "record C wrong sizeof");
_Static_assert(_Alignof(C) == 8, "record C wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 16, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_alignment) == 8, "record C wrong alignment");
_Static_assert(sizeof(struct C_packed) == 1, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_packed) == 1, "record C wrong alignment");
_Static_assert(sizeof(struct C_required_alignment) == 2, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "record C wrong alignment");
_Static_assert(sizeof(struct C_size) == 3, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_size) == 1, "record C wrong alignment");
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
_Static_assert(sizeof(E) == 0, "record E wrong sizeof");
_Static_assert(_Alignof(E) == 1, "record E wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 1, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_alignment) == 1, "record E wrong alignment");
_Static_assert(sizeof(struct E_packed) == 0, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_packed) == 1, "record E wrong alignment");
_Static_assert(sizeof(struct E_required_alignment) == 1, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "record E wrong alignment");
_Static_assert(sizeof(struct E_size) == 2, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_size) == 1, "record E wrong alignment");
#endif
_Static_assert(sizeof(F) == 0, "record F wrong sizeof");
_Static_assert(_Alignof(F) == 1, "record F wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 1, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_alignment) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_packed) == 0, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_packed) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_required_alignment) == 1, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_size) == 2, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_size) == 1, "record F wrong alignment");
#endif
_Static_assert(sizeof(G) == 0, "record G wrong sizeof");
_Static_assert(_Alignof(G) == 1, "record G wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 1, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_alignment) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_packed) == 0, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_packed) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_required_alignment) == 1, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_size) == 2, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_size) == 1, "record G wrong alignment");
#endif
_Static_assert(sizeof(H) == 0, "record H wrong sizeof");
_Static_assert(_Alignof(H) == 1, "record H wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 1, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_alignment) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_packed) == 0, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_packed) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_required_alignment) == 1, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_size) == 2, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_size) == 1, "record H wrong alignment");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(I) == 0, "record I wrong sizeof");
_Static_assert(_Alignof(I) == 1, "record I wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I_alignment) == 1, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_alignment) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_packed) == 0, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_packed) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_required_alignment) == 1, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_required_alignment) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_size) == 2, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_size) == 1, "record I wrong alignment");
#endif
#elif defined(AARCH64_FUCHSIA) ||  defined(AARCH64_LINUX_ANDROID) ||  defined(AARCH64_UNKNOWN_FREEBSD) ||  defined(AARCH64_UNKNOWN_HERMIT) ||  \
 defined(AARCH64_UNKNOWN_NETBSD) ||  defined(AARCH64_UNKNOWN_NONE) ||  defined(AARCH64_UNKNOWN_OPENBSD) ||  defined(AARCH64_UNKNOWN_REDOX) ||  \
 defined(ARMEBV7R_UNKNOWN_NONE_EABI) ||  defined(ARMEBV7R_UNKNOWN_NONE_EABIHF) ||  defined(ARM_LINUX_ANDROIDEABI) ||  defined(ARMV6_UNKNOWN_FREEBSD_GNUEABIHF) ||  \
 defined(ARMV6_UNKNOWN_NETBSDELF_EABIHF) ||  defined(ARMV7A_NONE_EABI) ||  defined(ARMV7A_NONE_EABIHF) ||  defined(ARMV7_NONE_LINUX_ANDROID) ||  \
 defined(ARMV7R_UNKNOWN_NONE_EABI) ||  defined(ARMV7R_UNKNOWN_NONE_EABIHF) ||  defined(ARMV7_UNKNOWN_FREEBSD_GNUEABIHF) ||  defined(ARMV7_UNKNOWN_NETBSDELF_EABIHF) ||  \
 defined(THUMBV4T_NONE_EABI) ||  defined(THUMBV6M_NONE_EABI) ||  defined(THUMBV7EM_NONE_EABIHF) ||  defined(THUMBV7EM_NONE_EABI) ||  \
 defined(THUMBV7M_NONE_EABI) ||  defined(THUMBV8MBASE_NONE_EABI) ||  defined(THUMBV8MMAIN_NONE_EABIHF) ||  defined(THUMBV8MMAIN_NONE_EABI) 
_Static_assert(sizeof(A) == 4, "record A wrong sizeof");
_Static_assert(_Alignof(A) == 4, "record A wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 8, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_alignment) == 4, "record A wrong alignment");
_Static_assert(sizeof(struct A_packed) == 4, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_packed) == 1, "record A wrong alignment");
_Static_assert(sizeof(struct A_required_alignment) == 5, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "record A wrong alignment");
_Static_assert(sizeof(struct A_size) == 6, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_size) == 1, "record A wrong alignment");
#endif
_Static_assert(sizeof(BA) == 0, "record BA wrong sizeof");
_Static_assert(_Alignof(BA) == 4, "record BA wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct BA_alignment) == 4, "record BA wrong sizeof");
_Static_assert(_Alignof(struct BA_alignment) == 4, "record BA wrong alignment");
_Static_assert(sizeof(struct BA_packed) == 0, "record BA wrong sizeof");
_Static_assert(_Alignof(struct BA_packed) == 1, "record BA wrong alignment");
_Static_assert(sizeof(struct BA_required_alignment) == 1, "record BA wrong sizeof");
_Static_assert(_Alignof(struct BA_required_alignment) == 1, "record BA wrong alignment");
_Static_assert(sizeof(struct BA_size) == 2, "record BA wrong sizeof");
_Static_assert(_Alignof(struct BA_size) == 1, "record BA wrong alignment");
#endif
_Static_assert(sizeof(BB) == 0, "record BB wrong sizeof");
_Static_assert(_Alignof(BB) == 16, "record BB wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct BB_alignment) == 16, "record BB wrong sizeof");
_Static_assert(_Alignof(struct BB_alignment) == 16, "record BB wrong alignment");
_Static_assert(sizeof(struct BB_packed) == 0, "record BB wrong sizeof");
_Static_assert(_Alignof(struct BB_packed) == 1, "record BB wrong alignment");
_Static_assert(sizeof(struct BB_required_alignment) == 1, "record BB wrong sizeof");
_Static_assert(_Alignof(struct BB_required_alignment) == 1, "record BB wrong alignment");
_Static_assert(sizeof(struct BB_size) == 2, "record BB wrong sizeof");
_Static_assert(_Alignof(struct BB_size) == 1, "record BB wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(BB,a) == 0, "field BB.a wrong bit offset");
#endif
_Static_assert(sizeof(BC) == 0, "record BC wrong sizeof");
_Static_assert(_Alignof(BC) == 16, "record BC wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct BC_alignment) == 16, "record BC wrong sizeof");
_Static_assert(_Alignof(struct BC_alignment) == 16, "record BC wrong alignment");
_Static_assert(sizeof(struct BC_packed) == 0, "record BC wrong sizeof");
_Static_assert(_Alignof(struct BC_packed) == 1, "record BC wrong alignment");
_Static_assert(sizeof(struct BC_required_alignment) == 1, "record BC wrong sizeof");
_Static_assert(_Alignof(struct BC_required_alignment) == 1, "record BC wrong alignment");
_Static_assert(sizeof(struct BC_size) == 2, "record BC wrong sizeof");
_Static_assert(_Alignof(struct BC_size) == 1, "record BC wrong alignment");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(BD) == 0, "record BD wrong sizeof");
_Static_assert(_Alignof(BD) == 16, "record BD wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct BD_alignment) == 16, "record BD wrong sizeof");
_Static_assert(_Alignof(struct BD_alignment) == 16, "record BD wrong alignment");
_Static_assert(sizeof(struct BD_packed) == 0, "record BD wrong sizeof");
_Static_assert(_Alignof(struct BD_packed) == 1, "record BD wrong alignment");
_Static_assert(sizeof(struct BD_required_alignment) == 1, "record BD wrong sizeof");
_Static_assert(_Alignof(struct BD_required_alignment) == 1, "record BD wrong alignment");
_Static_assert(sizeof(struct BD_size) == 2, "record BD wrong sizeof");
_Static_assert(_Alignof(struct BD_size) == 1, "record BD wrong alignment");
#endif
_Static_assert(sizeof(BE) == 0, "record BE wrong sizeof");
_Static_assert(_Alignof(BE) == 4, "record BE wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct BE_alignment) == 4, "record BE wrong sizeof");
_Static_assert(_Alignof(struct BE_alignment) == 4, "record BE wrong alignment");
_Static_assert(sizeof(struct BE_packed) == 0, "record BE wrong sizeof");
_Static_assert(_Alignof(struct BE_packed) == 1, "record BE wrong alignment");
_Static_assert(sizeof(struct BE_required_alignment) == 1, "record BE wrong sizeof");
_Static_assert(_Alignof(struct BE_required_alignment) == 1, "record BE wrong alignment");
_Static_assert(sizeof(struct BE_size) == 2, "record BE wrong sizeof");
_Static_assert(_Alignof(struct BE_size) == 1, "record BE wrong alignment");
#endif
_Static_assert(sizeof(C) == 1, "record C wrong sizeof");
_Static_assert(_Alignof(C) == 8, "record C wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 16, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_alignment) == 8, "record C wrong alignment");
_Static_assert(sizeof(struct C_packed) == 1, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_packed) == 1, "record C wrong alignment");
_Static_assert(sizeof(struct C_required_alignment) == 2, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "record C wrong alignment");
_Static_assert(sizeof(struct C_size) == 3, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_size) == 1, "record C wrong alignment");
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
_Static_assert(sizeof(E) == 0, "record E wrong sizeof");
_Static_assert(_Alignof(E) == 1, "record E wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 1, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_alignment) == 1, "record E wrong alignment");
_Static_assert(sizeof(struct E_packed) == 0, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_packed) == 1, "record E wrong alignment");
_Static_assert(sizeof(struct E_required_alignment) == 1, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "record E wrong alignment");
_Static_assert(sizeof(struct E_size) == 2, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_size) == 1, "record E wrong alignment");
#endif
_Static_assert(sizeof(F) == 0, "record F wrong sizeof");
_Static_assert(_Alignof(F) == 4, "record F wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 4, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_alignment) == 4, "record F wrong alignment");
_Static_assert(sizeof(struct F_packed) == 0, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_packed) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_required_alignment) == 1, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_size) == 2, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_size) == 1, "record F wrong alignment");
#endif
_Static_assert(sizeof(G) == 0, "record G wrong sizeof");
_Static_assert(_Alignof(G) == 8, "record G wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 8, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_alignment) == 8, "record G wrong alignment");
_Static_assert(sizeof(struct G_packed) == 0, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_packed) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_required_alignment) == 1, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_size) == 2, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_size) == 1, "record G wrong alignment");
#endif
_Static_assert(sizeof(H) == 0, "record H wrong sizeof");
_Static_assert(_Alignof(H) == 8, "record H wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 8, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_alignment) == 8, "record H wrong alignment");
_Static_assert(sizeof(struct H_packed) == 0, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_packed) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_required_alignment) == 1, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_size) == 2, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_size) == 1, "record H wrong alignment");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(I) == 0, "record I wrong sizeof");
_Static_assert(_Alignof(I) == 1, "record I wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I_alignment) == 1, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_alignment) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_packed) == 0, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_packed) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_required_alignment) == 1, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_required_alignment) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_size) == 2, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_size) == 1, "record I wrong alignment");
#endif
#elif defined(AARCH64_PC_WINDOWS_MSVC) ||  defined(I586_PC_WINDOWS_MSVC) ||  defined(I686_PC_WINDOWS_MSVC) ||  defined(I686_UNKNOWN_WINDOWS) ||  \
 defined(THUMBV7A_PC_WINDOWS_MSVC) ||  defined(X8664_PC_WINDOWS_MSVC) ||  defined(X8664_UNKNOWN_WINDOWS) 
_Static_assert(sizeof(A) == 4, "record A wrong sizeof");
_Static_assert(_Alignof(A) == 8, "record A wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 16, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_alignment) == 8, "record A wrong alignment");
_Static_assert(sizeof(struct A_packed) == 4, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_packed) == 1, "record A wrong alignment");
_Static_assert(sizeof(struct A_required_alignment) == 5, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "record A wrong alignment");
_Static_assert(sizeof(struct A_size) == 6, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_size) == 1, "record A wrong alignment");
#endif
_Static_assert(sizeof(BA) == 8, "record BA wrong sizeof");
_Static_assert(_Alignof(BA) == 8, "record BA wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct BA_alignment) == 16, "record BA wrong sizeof");
_Static_assert(_Alignof(struct BA_alignment) == 8, "record BA wrong alignment");
_Static_assert(sizeof(struct BA_packed) == 8, "record BA wrong sizeof");
_Static_assert(_Alignof(struct BA_packed) == 1, "record BA wrong alignment");
_Static_assert(sizeof(struct BA_required_alignment) == 9, "record BA wrong sizeof");
_Static_assert(_Alignof(struct BA_required_alignment) == 1, "record BA wrong alignment");
_Static_assert(sizeof(struct BA_size) == 10, "record BA wrong sizeof");
_Static_assert(_Alignof(struct BA_size) == 1, "record BA wrong alignment");
#endif
_Static_assert(sizeof(BB) == 8, "record BB wrong sizeof");
_Static_assert(_Alignof(BB) == 8, "record BB wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct BB_alignment) == 16, "record BB wrong sizeof");
_Static_assert(_Alignof(struct BB_alignment) == 8, "record BB wrong alignment");
_Static_assert(sizeof(struct BB_packed) == 8, "record BB wrong sizeof");
_Static_assert(_Alignof(struct BB_packed) == 1, "record BB wrong alignment");
_Static_assert(sizeof(struct BB_required_alignment) == 9, "record BB wrong sizeof");
_Static_assert(_Alignof(struct BB_required_alignment) == 1, "record BB wrong alignment");
_Static_assert(sizeof(struct BB_size) == 10, "record BB wrong sizeof");
_Static_assert(_Alignof(struct BB_size) == 1, "record BB wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(BB,a) == 0, "field BB.a wrong bit offset");
#endif
_Static_assert(sizeof(BC) == 8, "record BC wrong sizeof");
_Static_assert(_Alignof(BC) == 8, "record BC wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct BC_alignment) == 16, "record BC wrong sizeof");
_Static_assert(_Alignof(struct BC_alignment) == 8, "record BC wrong alignment");
_Static_assert(sizeof(struct BC_packed) == 8, "record BC wrong sizeof");
_Static_assert(_Alignof(struct BC_packed) == 1, "record BC wrong alignment");
_Static_assert(sizeof(struct BC_required_alignment) == 9, "record BC wrong sizeof");
_Static_assert(_Alignof(struct BC_required_alignment) == 1, "record BC wrong alignment");
_Static_assert(sizeof(struct BC_size) == 10, "record BC wrong sizeof");
_Static_assert(_Alignof(struct BC_size) == 1, "record BC wrong alignment");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(BD) == 16, "record BD wrong sizeof");
_Static_assert(_Alignof(BD) == 16, "record BD wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct BD_alignment) == 32, "record BD wrong sizeof");
_Static_assert(_Alignof(struct BD_alignment) == 16, "record BD wrong alignment");
_Static_assert(sizeof(struct BD_packed) == 16, "record BD wrong sizeof");
_Static_assert(_Alignof(struct BD_packed) == 1, "record BD wrong alignment");
_Static_assert(sizeof(struct BD_required_alignment) == 17, "record BD wrong sizeof");
_Static_assert(_Alignof(struct BD_required_alignment) == 1, "record BD wrong alignment");
_Static_assert(sizeof(struct BD_size) == 18, "record BD wrong sizeof");
_Static_assert(_Alignof(struct BD_size) == 1, "record BD wrong alignment");
#endif
_Static_assert(sizeof(BE) == 8, "record BE wrong sizeof");
_Static_assert(_Alignof(BE) == 8, "record BE wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct BE_alignment) == 16, "record BE wrong sizeof");
_Static_assert(_Alignof(struct BE_alignment) == 8, "record BE wrong alignment");
_Static_assert(sizeof(struct BE_packed) == 8, "record BE wrong sizeof");
_Static_assert(_Alignof(struct BE_packed) == 1, "record BE wrong alignment");
_Static_assert(sizeof(struct BE_required_alignment) == 9, "record BE wrong sizeof");
_Static_assert(_Alignof(struct BE_required_alignment) == 1, "record BE wrong alignment");
_Static_assert(sizeof(struct BE_size) == 10, "record BE wrong sizeof");
_Static_assert(_Alignof(struct BE_size) == 1, "record BE wrong alignment");
#endif
_Static_assert(sizeof(C) == 1, "record C wrong sizeof");
_Static_assert(_Alignof(C) == 8, "record C wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 16, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_alignment) == 8, "record C wrong alignment");
_Static_assert(sizeof(struct C_packed) == 1, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_packed) == 1, "record C wrong alignment");
_Static_assert(sizeof(struct C_required_alignment) == 2, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "record C wrong alignment");
_Static_assert(sizeof(struct C_size) == 3, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_size) == 1, "record C wrong alignment");
#endif
_Static_assert(sizeof(D) == 8, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 8, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 16, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 8, "record D wrong alignment");
_Static_assert(sizeof(struct D_packed) == 8, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 9, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_size) == 10, "record D wrong sizeof");
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
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(I) == 1, "record I wrong sizeof");
_Static_assert(_Alignof(I) == 1, "record I wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I_alignment) == 2, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_alignment) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_packed) == 1, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_packed) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_required_alignment) == 2, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_required_alignment) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_size) == 3, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_size) == 1, "record I wrong alignment");
#endif
#elif defined(ARMV7_APPLE_IOS) ||  defined(ARMV7S_APPLE_IOS) 
_Static_assert(sizeof(A) == 4, "record A wrong sizeof");
_Static_assert(_Alignof(A) == 4, "record A wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 8, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_alignment) == 4, "record A wrong alignment");
_Static_assert(sizeof(struct A_packed) == 4, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_packed) == 1, "record A wrong alignment");
_Static_assert(sizeof(struct A_required_alignment) == 5, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "record A wrong alignment");
_Static_assert(sizeof(struct A_size) == 6, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_size) == 1, "record A wrong alignment");
#endif
_Static_assert(sizeof(BA) == 0, "record BA wrong sizeof");
_Static_assert(_Alignof(BA) == 4, "record BA wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct BA_alignment) == 4, "record BA wrong sizeof");
_Static_assert(_Alignof(struct BA_alignment) == 4, "record BA wrong alignment");
_Static_assert(sizeof(struct BA_packed) == 0, "record BA wrong sizeof");
_Static_assert(_Alignof(struct BA_packed) == 1, "record BA wrong alignment");
_Static_assert(sizeof(struct BA_required_alignment) == 1, "record BA wrong sizeof");
_Static_assert(_Alignof(struct BA_required_alignment) == 1, "record BA wrong alignment");
_Static_assert(sizeof(struct BA_size) == 2, "record BA wrong sizeof");
_Static_assert(_Alignof(struct BA_size) == 1, "record BA wrong alignment");
#endif
_Static_assert(sizeof(BB) == 0, "record BB wrong sizeof");
_Static_assert(_Alignof(BB) == 16, "record BB wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct BB_alignment) == 16, "record BB wrong sizeof");
_Static_assert(_Alignof(struct BB_alignment) == 16, "record BB wrong alignment");
_Static_assert(sizeof(struct BB_packed) == 0, "record BB wrong sizeof");
_Static_assert(_Alignof(struct BB_packed) == 1, "record BB wrong alignment");
_Static_assert(sizeof(struct BB_required_alignment) == 1, "record BB wrong sizeof");
_Static_assert(_Alignof(struct BB_required_alignment) == 1, "record BB wrong alignment");
_Static_assert(sizeof(struct BB_size) == 2, "record BB wrong sizeof");
_Static_assert(_Alignof(struct BB_size) == 1, "record BB wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(BB,a) == 0, "field BB.a wrong bit offset");
#endif
_Static_assert(sizeof(BC) == 0, "record BC wrong sizeof");
_Static_assert(_Alignof(BC) == 16, "record BC wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct BC_alignment) == 16, "record BC wrong sizeof");
_Static_assert(_Alignof(struct BC_alignment) == 16, "record BC wrong alignment");
_Static_assert(sizeof(struct BC_packed) == 0, "record BC wrong sizeof");
_Static_assert(_Alignof(struct BC_packed) == 1, "record BC wrong alignment");
_Static_assert(sizeof(struct BC_required_alignment) == 1, "record BC wrong sizeof");
_Static_assert(_Alignof(struct BC_required_alignment) == 1, "record BC wrong alignment");
_Static_assert(sizeof(struct BC_size) == 2, "record BC wrong sizeof");
_Static_assert(_Alignof(struct BC_size) == 1, "record BC wrong alignment");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(BD) == 0, "record BD wrong sizeof");
_Static_assert(_Alignof(BD) == 16, "record BD wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct BD_alignment) == 16, "record BD wrong sizeof");
_Static_assert(_Alignof(struct BD_alignment) == 16, "record BD wrong alignment");
_Static_assert(sizeof(struct BD_packed) == 0, "record BD wrong sizeof");
_Static_assert(_Alignof(struct BD_packed) == 1, "record BD wrong alignment");
_Static_assert(sizeof(struct BD_required_alignment) == 1, "record BD wrong sizeof");
_Static_assert(_Alignof(struct BD_required_alignment) == 1, "record BD wrong alignment");
_Static_assert(sizeof(struct BD_size) == 2, "record BD wrong sizeof");
_Static_assert(_Alignof(struct BD_size) == 1, "record BD wrong alignment");
#endif
_Static_assert(sizeof(BE) == 0, "record BE wrong sizeof");
_Static_assert(_Alignof(BE) == 4, "record BE wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct BE_alignment) == 4, "record BE wrong sizeof");
_Static_assert(_Alignof(struct BE_alignment) == 4, "record BE wrong alignment");
_Static_assert(sizeof(struct BE_packed) == 0, "record BE wrong sizeof");
_Static_assert(_Alignof(struct BE_packed) == 1, "record BE wrong alignment");
_Static_assert(sizeof(struct BE_required_alignment) == 1, "record BE wrong sizeof");
_Static_assert(_Alignof(struct BE_required_alignment) == 1, "record BE wrong alignment");
_Static_assert(sizeof(struct BE_size) == 2, "record BE wrong sizeof");
_Static_assert(_Alignof(struct BE_size) == 1, "record BE wrong alignment");
#endif
_Static_assert(sizeof(C) == 1, "record C wrong sizeof");
_Static_assert(_Alignof(C) == 8, "record C wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 16, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_alignment) == 8, "record C wrong alignment");
_Static_assert(sizeof(struct C_packed) == 1, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_packed) == 1, "record C wrong alignment");
_Static_assert(sizeof(struct C_required_alignment) == 2, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "record C wrong alignment");
_Static_assert(sizeof(struct C_size) == 3, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_size) == 1, "record C wrong alignment");
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
_Static_assert(sizeof(E) == 0, "record E wrong sizeof");
_Static_assert(_Alignof(E) == 4, "record E wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 4, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_alignment) == 4, "record E wrong alignment");
_Static_assert(sizeof(struct E_packed) == 0, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_packed) == 1, "record E wrong alignment");
_Static_assert(sizeof(struct E_required_alignment) == 1, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "record E wrong alignment");
_Static_assert(sizeof(struct E_size) == 2, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_size) == 1, "record E wrong alignment");
#endif
_Static_assert(sizeof(F) == 0, "record F wrong sizeof");
_Static_assert(_Alignof(F) == 4, "record F wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 4, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_alignment) == 4, "record F wrong alignment");
_Static_assert(sizeof(struct F_packed) == 0, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_packed) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_required_alignment) == 1, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_size) == 2, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_size) == 1, "record F wrong alignment");
#endif
_Static_assert(sizeof(G) == 0, "record G wrong sizeof");
_Static_assert(_Alignof(G) == 4, "record G wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 4, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_alignment) == 4, "record G wrong alignment");
_Static_assert(sizeof(struct G_packed) == 0, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_packed) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_required_alignment) == 1, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_size) == 2, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_size) == 1, "record G wrong alignment");
#endif
_Static_assert(sizeof(H) == 0, "record H wrong sizeof");
_Static_assert(_Alignof(H) == 4, "record H wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 4, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_alignment) == 4, "record H wrong alignment");
_Static_assert(sizeof(struct H_packed) == 0, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_packed) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_required_alignment) == 1, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_size) == 2, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_size) == 1, "record H wrong alignment");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(I) == 0, "record I wrong sizeof");
_Static_assert(_Alignof(I) == 1, "record I wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I_alignment) == 1, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_alignment) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_packed) == 0, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_packed) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_required_alignment) == 1, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_required_alignment) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_size) == 2, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_size) == 1, "record I wrong alignment");
#endif
#elif defined(I386_APPLE_IOS) ||  defined(I686_APPLE_MACOSX) ||  defined(I686_LINUX_ANDROID) ||  defined(I686_UNKNOWN_FREEBSD) ||  defined(I686_UNKNOWN_HAIKU) ||  \
 defined(I686_UNKNOWN_NETBSDELF) ||  defined(I686_UNKNOWN_OPENBSD) 
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
_Static_assert(sizeof(BA) == 0, "record BA wrong sizeof");
_Static_assert(_Alignof(BA) == 1, "record BA wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct BA_alignment) == 1, "record BA wrong sizeof");
_Static_assert(_Alignof(struct BA_alignment) == 1, "record BA wrong alignment");
_Static_assert(sizeof(struct BA_packed) == 0, "record BA wrong sizeof");
_Static_assert(_Alignof(struct BA_packed) == 1, "record BA wrong alignment");
_Static_assert(sizeof(struct BA_required_alignment) == 1, "record BA wrong sizeof");
_Static_assert(_Alignof(struct BA_required_alignment) == 1, "record BA wrong alignment");
_Static_assert(sizeof(struct BA_size) == 2, "record BA wrong sizeof");
_Static_assert(_Alignof(struct BA_size) == 1, "record BA wrong alignment");
#endif
_Static_assert(sizeof(BB) == 0, "record BB wrong sizeof");
_Static_assert(_Alignof(BB) == 1, "record BB wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct BB_alignment) == 1, "record BB wrong sizeof");
_Static_assert(_Alignof(struct BB_alignment) == 1, "record BB wrong alignment");
_Static_assert(sizeof(struct BB_packed) == 0, "record BB wrong sizeof");
_Static_assert(_Alignof(struct BB_packed) == 1, "record BB wrong alignment");
_Static_assert(sizeof(struct BB_required_alignment) == 1, "record BB wrong sizeof");
_Static_assert(_Alignof(struct BB_required_alignment) == 1, "record BB wrong alignment");
_Static_assert(sizeof(struct BB_size) == 2, "record BB wrong sizeof");
_Static_assert(_Alignof(struct BB_size) == 1, "record BB wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(BB,a) == 0, "field BB.a wrong bit offset");
#endif
_Static_assert(sizeof(BC) == 0, "record BC wrong sizeof");
_Static_assert(_Alignof(BC) == 1, "record BC wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct BC_alignment) == 1, "record BC wrong sizeof");
_Static_assert(_Alignof(struct BC_alignment) == 1, "record BC wrong alignment");
_Static_assert(sizeof(struct BC_packed) == 0, "record BC wrong sizeof");
_Static_assert(_Alignof(struct BC_packed) == 1, "record BC wrong alignment");
_Static_assert(sizeof(struct BC_required_alignment) == 1, "record BC wrong sizeof");
_Static_assert(_Alignof(struct BC_required_alignment) == 1, "record BC wrong alignment");
_Static_assert(sizeof(struct BC_size) == 2, "record BC wrong sizeof");
_Static_assert(_Alignof(struct BC_size) == 1, "record BC wrong alignment");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(BD) == 0, "record BD wrong sizeof");
_Static_assert(_Alignof(BD) == 16, "record BD wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct BD_alignment) == 16, "record BD wrong sizeof");
_Static_assert(_Alignof(struct BD_alignment) == 16, "record BD wrong alignment");
_Static_assert(sizeof(struct BD_packed) == 0, "record BD wrong sizeof");
_Static_assert(_Alignof(struct BD_packed) == 1, "record BD wrong alignment");
_Static_assert(sizeof(struct BD_required_alignment) == 1, "record BD wrong sizeof");
_Static_assert(_Alignof(struct BD_required_alignment) == 1, "record BD wrong alignment");
_Static_assert(sizeof(struct BD_size) == 2, "record BD wrong sizeof");
_Static_assert(_Alignof(struct BD_size) == 1, "record BD wrong alignment");
#endif
_Static_assert(sizeof(BE) == 0, "record BE wrong sizeof");
_Static_assert(_Alignof(BE) == 2, "record BE wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct BE_alignment) == 2, "record BE wrong sizeof");
_Static_assert(_Alignof(struct BE_alignment) == 2, "record BE wrong alignment");
_Static_assert(sizeof(struct BE_packed) == 0, "record BE wrong sizeof");
_Static_assert(_Alignof(struct BE_packed) == 1, "record BE wrong alignment");
_Static_assert(sizeof(struct BE_required_alignment) == 1, "record BE wrong sizeof");
_Static_assert(_Alignof(struct BE_required_alignment) == 1, "record BE wrong alignment");
_Static_assert(sizeof(struct BE_size) == 2, "record BE wrong sizeof");
_Static_assert(_Alignof(struct BE_size) == 1, "record BE wrong alignment");
#endif
_Static_assert(sizeof(C) == 1, "record C wrong sizeof");
_Static_assert(_Alignof(C) == 8, "record C wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 16, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_alignment) == 8, "record C wrong alignment");
_Static_assert(sizeof(struct C_packed) == 1, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_packed) == 1, "record C wrong alignment");
_Static_assert(sizeof(struct C_required_alignment) == 2, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "record C wrong alignment");
_Static_assert(sizeof(struct C_size) == 3, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_size) == 1, "record C wrong alignment");
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
_Static_assert(sizeof(E) == 0, "record E wrong sizeof");
_Static_assert(_Alignof(E) == 1, "record E wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 1, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_alignment) == 1, "record E wrong alignment");
_Static_assert(sizeof(struct E_packed) == 0, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_packed) == 1, "record E wrong alignment");
_Static_assert(sizeof(struct E_required_alignment) == 1, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "record E wrong alignment");
_Static_assert(sizeof(struct E_size) == 2, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_size) == 1, "record E wrong alignment");
#endif
_Static_assert(sizeof(F) == 0, "record F wrong sizeof");
_Static_assert(_Alignof(F) == 1, "record F wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 1, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_alignment) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_packed) == 0, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_packed) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_required_alignment) == 1, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_size) == 2, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_size) == 1, "record F wrong alignment");
#endif
_Static_assert(sizeof(G) == 0, "record G wrong sizeof");
_Static_assert(_Alignof(G) == 1, "record G wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 1, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_alignment) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_packed) == 0, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_packed) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_required_alignment) == 1, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_size) == 2, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_size) == 1, "record G wrong alignment");
#endif
_Static_assert(sizeof(H) == 0, "record H wrong sizeof");
_Static_assert(_Alignof(H) == 1, "record H wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 1, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_alignment) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_packed) == 0, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_packed) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_required_alignment) == 1, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_size) == 2, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_size) == 1, "record H wrong alignment");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(I) == 0, "record I wrong sizeof");
_Static_assert(_Alignof(I) == 1, "record I wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I_alignment) == 1, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_alignment) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_packed) == 0, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_packed) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_required_alignment) == 1, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_required_alignment) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_size) == 2, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_size) == 1, "record I wrong alignment");
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
_Static_assert(sizeof(BA) == 0, "record BA wrong sizeof");
_Static_assert(_Alignof(BA) == 1, "record BA wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct BA_alignment) == 1, "record BA wrong sizeof");
_Static_assert(_Alignof(struct BA_alignment) == 1, "record BA wrong alignment");
_Static_assert(sizeof(struct BA_packed) == 0, "record BA wrong sizeof");
_Static_assert(_Alignof(struct BA_packed) == 1, "record BA wrong alignment");
_Static_assert(sizeof(struct BA_required_alignment) == 1, "record BA wrong sizeof");
_Static_assert(_Alignof(struct BA_required_alignment) == 1, "record BA wrong alignment");
_Static_assert(sizeof(struct BA_size) == 2, "record BA wrong sizeof");
_Static_assert(_Alignof(struct BA_size) == 1, "record BA wrong alignment");
#endif
_Static_assert(sizeof(BB) == 0, "record BB wrong sizeof");
_Static_assert(_Alignof(BB) == 1, "record BB wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct BB_alignment) == 1, "record BB wrong sizeof");
_Static_assert(_Alignof(struct BB_alignment) == 1, "record BB wrong alignment");
_Static_assert(sizeof(struct BB_packed) == 0, "record BB wrong sizeof");
_Static_assert(_Alignof(struct BB_packed) == 1, "record BB wrong alignment");
_Static_assert(sizeof(struct BB_required_alignment) == 1, "record BB wrong sizeof");
_Static_assert(_Alignof(struct BB_required_alignment) == 1, "record BB wrong alignment");
_Static_assert(sizeof(struct BB_size) == 2, "record BB wrong sizeof");
_Static_assert(_Alignof(struct BB_size) == 1, "record BB wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(BB,a) == 0, "field BB.a wrong bit offset");
#endif
_Static_assert(sizeof(BC) == 0, "record BC wrong sizeof");
_Static_assert(_Alignof(BC) == 1, "record BC wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct BC_alignment) == 1, "record BC wrong sizeof");
_Static_assert(_Alignof(struct BC_alignment) == 1, "record BC wrong alignment");
_Static_assert(sizeof(struct BC_packed) == 0, "record BC wrong sizeof");
_Static_assert(_Alignof(struct BC_packed) == 1, "record BC wrong alignment");
_Static_assert(sizeof(struct BC_required_alignment) == 1, "record BC wrong sizeof");
_Static_assert(_Alignof(struct BC_required_alignment) == 1, "record BC wrong alignment");
_Static_assert(sizeof(struct BC_size) == 2, "record BC wrong sizeof");
_Static_assert(_Alignof(struct BC_size) == 1, "record BC wrong alignment");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(BD) == 0, "record BD wrong sizeof");
_Static_assert(_Alignof(BD) == 16, "record BD wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct BD_alignment) == 16, "record BD wrong sizeof");
_Static_assert(_Alignof(struct BD_alignment) == 16, "record BD wrong alignment");
_Static_assert(sizeof(struct BD_packed) == 0, "record BD wrong sizeof");
_Static_assert(_Alignof(struct BD_packed) == 1, "record BD wrong alignment");
_Static_assert(sizeof(struct BD_required_alignment) == 1, "record BD wrong sizeof");
_Static_assert(_Alignof(struct BD_required_alignment) == 1, "record BD wrong alignment");
_Static_assert(sizeof(struct BD_size) == 2, "record BD wrong sizeof");
_Static_assert(_Alignof(struct BD_size) == 1, "record BD wrong alignment");
#endif
_Static_assert(sizeof(BE) == 0, "record BE wrong sizeof");
_Static_assert(_Alignof(BE) == 2, "record BE wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct BE_alignment) == 2, "record BE wrong sizeof");
_Static_assert(_Alignof(struct BE_alignment) == 2, "record BE wrong alignment");
_Static_assert(sizeof(struct BE_packed) == 0, "record BE wrong sizeof");
_Static_assert(_Alignof(struct BE_packed) == 1, "record BE wrong alignment");
_Static_assert(sizeof(struct BE_required_alignment) == 1, "record BE wrong sizeof");
_Static_assert(_Alignof(struct BE_required_alignment) == 1, "record BE wrong alignment");
_Static_assert(sizeof(struct BE_size) == 2, "record BE wrong sizeof");
_Static_assert(_Alignof(struct BE_size) == 1, "record BE wrong alignment");
#endif
_Static_assert(sizeof(C) == 1, "record C wrong sizeof");
_Static_assert(_Alignof(C) == 8, "record C wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 16, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_alignment) == 8, "record C wrong alignment");
_Static_assert(sizeof(struct C_packed) == 1, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_packed) == 1, "record C wrong alignment");
_Static_assert(sizeof(struct C_required_alignment) == 2, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "record C wrong alignment");
_Static_assert(sizeof(struct C_size) == 3, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_size) == 1, "record C wrong alignment");
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
_Static_assert(sizeof(E) == 0, "record E wrong sizeof");
_Static_assert(_Alignof(E) == 1, "record E wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 1, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_alignment) == 1, "record E wrong alignment");
_Static_assert(sizeof(struct E_packed) == 0, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_packed) == 1, "record E wrong alignment");
_Static_assert(sizeof(struct E_required_alignment) == 1, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "record E wrong alignment");
_Static_assert(sizeof(struct E_size) == 2, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_size) == 1, "record E wrong alignment");
#endif
_Static_assert(sizeof(F) == 0, "record F wrong sizeof");
_Static_assert(_Alignof(F) == 1, "record F wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 1, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_alignment) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_packed) == 0, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_packed) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_required_alignment) == 1, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_size) == 2, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_size) == 1, "record F wrong alignment");
#endif
_Static_assert(sizeof(G) == 0, "record G wrong sizeof");
_Static_assert(_Alignof(G) == 1, "record G wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 1, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_alignment) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_packed) == 0, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_packed) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_required_alignment) == 1, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_size) == 2, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_size) == 1, "record G wrong alignment");
#endif
_Static_assert(sizeof(H) == 0, "record H wrong sizeof");
_Static_assert(_Alignof(H) == 1, "record H wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 1, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_alignment) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_packed) == 0, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_packed) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_required_alignment) == 1, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_size) == 2, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_size) == 1, "record H wrong alignment");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(I) == 0, "record I wrong sizeof");
_Static_assert(_Alignof(I) == 1, "record I wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I_alignment) == 1, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_alignment) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_packed) == 0, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_packed) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_required_alignment) == 1, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_required_alignment) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_size) == 2, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_size) == 1, "record I wrong alignment");
#endif
#endif
