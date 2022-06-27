// SPDX-License-Identifier: GPL-3.0-or-later

// This test file is auto-generated. do not edit.
// This file is a derivative work from the test files found// in this repo : https://github.com/mahkoh/repr-c
// and is under the same licence as the original work.

typedef struct {
    char a;
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

typedef struct {
#ifdef MSVC
    __declspec(align(4)) long long a;
#else
    long long a __attribute__((aligned(4)));
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

#pragma pack(2)
typedef struct {
    B a;
    char b;
    int c;
} X;
X var9;
#pragma pack()
struct X_alignment {
#ifdef MSVC
    char a[_Alignof(X)];
    char b;
#else
    char a;
    X b;
#endif
};
struct X_alignment var10;
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
struct X_required_alignment var11;
struct X_size {
    char a[sizeof(X)+1];
    char b;
};
struct X_size var12;

#pragma pack(16)
typedef struct {
#ifdef MSVC
    __declspec(align(32)) char:1;
#else
    char:1 __attribute__((aligned(32)));
#endif
} YA;
YA var13;
#pragma pack()
struct YA_alignment {
#ifdef MSVC
    char a[_Alignof(YA)];
    char b;
#else
    char a;
    YA b;
#endif
};
struct YA_alignment var14;
#pragma pack(1)
struct YA_packed {
    YA a;
};
#pragma pack()
struct YA_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct YA_packed)];
    char b;
#else
    char a;
    struct YA_packed b;
#endif
};
struct YA_required_alignment var15;
struct YA_size {
    char a[sizeof(YA)+1];
    char b;
};
struct YA_size var16;

#pragma pack(1)
typedef struct {
    char a;
    YA b;
} YB;
YB var17;
#pragma pack()
struct YB_alignment {
#ifdef MSVC
    char a[_Alignof(YB)];
    char b;
#else
    char a;
    YB b;
#endif
};
struct YB_alignment var18;
#pragma pack(1)
struct YB_packed {
    YB a;
};
#pragma pack()
struct YB_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct YB_packed)];
    char b;
#else
    char a;
    struct YB_packed b;
#endif
};
struct YB_required_alignment var19;
struct YB_size {
    char a[sizeof(YB)+1];
    char b;
};
struct YB_size var20;

#pragma pack(8)
typedef struct {
#ifdef MSVC
    __declspec(align(32)) char:1;
#else
    char:1 __attribute__((aligned(32)));
#endif
} YC;
YC var21;
#pragma pack()
struct YC_alignment {
#ifdef MSVC
    char a[_Alignof(YC)];
    char b;
#else
    char a;
    YC b;
#endif
};
struct YC_alignment var22;
#pragma pack(1)
struct YC_packed {
    YC a;
};
#pragma pack()
struct YC_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct YC_packed)];
    char b;
#else
    char a;
    struct YC_packed b;
#endif
};
struct YC_required_alignment var23;
struct YC_size {
    char a[sizeof(YC)+1];
    char b;
};
struct YC_size var24;

#pragma pack(1)
typedef struct {
    char a;
    YC b;
} YD;
YD var25;
#pragma pack()
struct YD_alignment {
#ifdef MSVC
    char a[_Alignof(YD)];
    char b;
#else
    char a;
    YD b;
#endif
};
struct YD_alignment var26;
#pragma pack(1)
struct YD_packed {
    YD a;
};
#pragma pack()
struct YD_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct YD_packed)];
    char b;
#else
    char a;
    struct YD_packed b;
#endif
};
struct YD_required_alignment var27;
struct YD_size {
    char a[sizeof(YD)+1];
    char b;
};
struct YD_size var28;

#pragma pack(4)
typedef struct {
#ifdef MSVC
    __declspec(align(32)) char:1;
#else
    char:1 __attribute__((aligned(32)));
#endif
} YE;
YE var29;
#pragma pack()
struct YE_alignment {
#ifdef MSVC
    char a[_Alignof(YE)];
    char b;
#else
    char a;
    YE b;
#endif
};
struct YE_alignment var30;
#pragma pack(1)
struct YE_packed {
    YE a;
};
#pragma pack()
struct YE_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct YE_packed)];
    char b;
#else
    char a;
    struct YE_packed b;
#endif
};
struct YE_required_alignment var31;
struct YE_size {
    char a[sizeof(YE)+1];
    char b;
};
struct YE_size var32;

#pragma pack(1)
typedef struct {
    char a;
    YE b;
} YF;
YF var33;
#pragma pack()
struct YF_alignment {
#ifdef MSVC
    char a[_Alignof(YF)];
    char b;
#else
    char a;
    YF b;
#endif
};
struct YF_alignment var34;
#pragma pack(1)
struct YF_packed {
    YF a;
};
#pragma pack()
struct YF_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct YF_packed)];
    char b;
#else
    char a;
    struct YF_packed b;
#endif
};
struct YF_required_alignment var35;
struct YF_size {
    char a[sizeof(YF)+1];
    char b;
};
struct YF_size var36;

#pragma pack(16)
#ifdef MSVC
__declspec(align(16)) typedef struct {
#else
typedef struct {
#endif
    char a;
#ifdef MSVC
} D0;
#else
} __attribute__((aligned(16))) D0;
#endif
D0 var37;
#pragma pack()
struct D0_alignment {
#ifdef MSVC
    char a[_Alignof(D0)];
    char b;
#else
    char a;
    D0 b;
#endif
};
struct D0_alignment var38;
#pragma pack(1)
struct D0_packed {
    D0 a;
};
#pragma pack()
struct D0_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct D0_packed)];
    char b;
#else
    char a;
    struct D0_packed b;
#endif
};
struct D0_required_alignment var39;
struct D0_size {
    char a[sizeof(D0)+1];
    char b;
};
struct D0_size var40;

#pragma pack(1)
#ifdef MSVC
__declspec(align(8)) typedef struct {
    __declspec(align(1024)) int b:3;
} RB0;
#else
typedef struct {
    int b:3 __attribute__((aligned(1024)));
} __attribute__((aligned(8))) RB0;
#endif
RB0 var41;
#pragma pack()
struct RB0_alignment {
#ifdef MSVC
    char a[_Alignof(RB0)];
    char b;
#else
    char a;
    RB0 b;
#endif
};
struct RB0_alignment var42;
#pragma pack(1)
struct RB0_packed {
    RB0 a;
};
#pragma pack()
struct RB0_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct RB0_packed)];
    char b;
#else
    char a;
    struct RB0_packed b;
#endif
};
struct RB0_required_alignment var43;
struct RB0_size {
    char a[sizeof(RB0)+1];
    char b;
};
struct RB0_size var44;

#pragma pack(1)
typedef struct {
    char a;
#ifdef MSVC
    __declspec(align(1024)) int c:3;
#else
    int c:3 __attribute__((aligned(1024)));
#endif
} RC;
RC var45;
#pragma pack()
struct RC_alignment {
#ifdef MSVC
    char a[_Alignof(RC)];
    char b;
#else
    char a;
    RC b;
#endif
};
struct RC_alignment var46;
#pragma pack(1)
struct RC_packed {
    RC a;
};
#pragma pack()
struct RC_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct RC_packed)];
    char b;
#else
    char a;
    struct RC_packed b;
#endif
};
struct RC_required_alignment var47;
struct RC_size {
    char a[sizeof(RC)+1];
    char b;
};
struct RC_size var48;

#pragma pack(1)
typedef struct {
    char a;
    RC c;
} RE;
RE var49;
#pragma pack()
struct RE_alignment {
#ifdef MSVC
    char a[_Alignof(RE)];
    char b;
#else
    char a;
    RE b;
#endif
};
struct RE_alignment var50;
#pragma pack(1)
struct RE_packed {
    RE a;
};
#pragma pack()
struct RE_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct RE_packed)];
    char b;
#else
    char a;
    struct RE_packed b;
#endif
};
struct RE_required_alignment var51;
struct RE_size {
    char a[sizeof(RE)+1];
    char b;
};
struct RE_size var52;

#ifdef MSVC
__declspec(align(4)) typedef struct {
#else
typedef struct {
#endif
    int c;
#ifdef MSVC
} PA;
#else
} __attribute__((aligned(4))) PA;
#endif
PA var53;
struct PA_alignment {
#ifdef MSVC
    char a[_Alignof(PA)];
    char b;
#else
    char a;
    PA b;
#endif
};
struct PA_alignment var54;
#pragma pack(1)
struct PA_packed {
    PA a;
};
#pragma pack()
struct PA_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct PA_packed)];
    char b;
#else
    char a;
    struct PA_packed b;
#endif
};
struct PA_required_alignment var55;
struct PA_size {
    char a[sizeof(PA)+1];
    char b;
};
struct PA_size var56;

#ifdef MSVC
__declspec(align(8)) typedef PA PB;
#else
typedef PA PB __attribute__((aligned(8)));
#endif
PB var57;
struct PB_alignment {
#ifdef MSVC
    char a[_Alignof(PB)];
    char b;
#else
    char a;
    PB b;
#endif
};
struct PB_alignment var58;
#pragma pack(1)
struct PB_packed {
    PB a;
};
#pragma pack()
struct PB_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct PB_packed)];
    char b;
#else
    char a;
    struct PB_packed b;
#endif
};
struct PB_required_alignment var59;
struct PB_size {
    char a[sizeof(PB)+1];
    char b;
};
struct PB_size var60;

#pragma pack(1)
typedef struct {
    char a;
    PB x;
} PC;
PC var61;
#pragma pack()
struct PC_alignment {
#ifdef MSVC
    char a[_Alignof(PC)];
    char b;
#else
    char a;
    PC b;
#endif
};
struct PC_alignment var62;
#pragma pack(1)
struct PC_packed {
    PC a;
};
#pragma pack()
struct PC_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct PC_packed)];
    char b;
#else
    char a;
    struct PC_packed b;
#endif
};
struct PC_required_alignment var63;
struct PC_size {
    char a[sizeof(PC)+1];
    char b;
};
struct PC_size var64;

typedef PB PD;
PD var65;
struct PD_alignment {
#ifdef MSVC
    char a[_Alignof(PD)];
    char b;
#else
    char a;
    PD b;
#endif
};
struct PD_alignment var66;
#pragma pack(1)
struct PD_packed {
    PD a;
};
#pragma pack()
struct PD_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct PD_packed)];
    char b;
#else
    char a;
    struct PD_packed b;
#endif
};
struct PD_required_alignment var67;
struct PD_size {
    char a[sizeof(PD)+1];
    char b;
};
struct PD_size var68;

#pragma pack(1)
typedef struct {
    char a;
    PD x;
} PE;
PE var69;
#pragma pack()
struct PE_alignment {
#ifdef MSVC
    char a[_Alignof(PE)];
    char b;
#else
    char a;
    PE b;
#endif
};
struct PE_alignment var70;
#pragma pack(1)
struct PE_packed {
    PE a;
};
#pragma pack()
struct PE_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct PE_packed)];
    char b;
#else
    char a;
    struct PE_packed b;
#endif
};
struct PE_required_alignment var71;
struct PE_size {
    char a[sizeof(PE)+1];
    char b;
};
struct PE_size var72;

#ifdef MSVC
__declspec(align(2)) typedef int QA;
#else
typedef int QA __attribute__((aligned(2)));
#endif
QA var73;
struct QA_alignment {
#ifdef MSVC
    char a[_Alignof(QA)];
    char b;
#else
    char a;
    QA b;
#endif
};
struct QA_alignment var74;
#pragma pack(1)
struct QA_packed {
    QA a;
};
#pragma pack()
struct QA_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct QA_packed)];
    char b;
#else
    char a;
    struct QA_packed b;
#endif
};
struct QA_required_alignment var75;
struct QA_size {
    char a[sizeof(QA)+1];
    char b;
};
struct QA_size var76;

#pragma pack(1)
typedef struct {
    char a;
    QA b;
} QB;
QB var77;
#pragma pack()
struct QB_alignment {
#ifdef MSVC
    char a[_Alignof(QB)];
    char b;
#else
    char a;
    QB b;
#endif
};
struct QB_alignment var78;
#pragma pack(1)
struct QB_packed {
    QB a;
};
#pragma pack()
struct QB_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct QB_packed)];
    char b;
#else
    char a;
    struct QB_packed b;
#endif
};
struct QB_required_alignment var79;
struct QB_size {
    char a[sizeof(QB)+1];
    char b;
};
struct QB_size var80;

typedef struct {
    char a;
    QA b;
} QC;
QC var81;
struct QC_alignment {
#ifdef MSVC
    char a[_Alignof(QC)];
    char b;
#else
    char a;
    QC b;
#endif
};
struct QC_alignment var82;
#pragma pack(1)
struct QC_packed {
    QC a;
};
#pragma pack()
struct QC_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct QC_packed)];
    char b;
#else
    char a;
    struct QC_packed b;
#endif
};
struct QC_required_alignment var83;
struct QC_size {
    char a[sizeof(QC)+1];
    char b;
};
struct QC_size var84;

typedef struct {
    char a;
    QA b:3;
} QD;
QD var85;
struct QD_alignment {
#ifdef MSVC
    char a[_Alignof(QD)];
    char b;
#else
    char a;
    QD b;
#endif
};
struct QD_alignment var86;
#pragma pack(1)
struct QD_packed {
    QD a;
};
#pragma pack()
struct QD_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct QD_packed)];
    char b;
#else
    char a;
    struct QD_packed b;
#endif
};
struct QD_required_alignment var87;
struct QD_size {
    char a[sizeof(QD)+1];
    char b;
};
struct QD_size var88;

#ifdef MSVC
typedef long long unnamed_type_89[];
#else
typedef long long unnamed_type_89[0];
#endif
unnamed_type_89 var90;
struct unnamed_type_89_alignment {
#ifdef MSVC
    char a[_Alignof(unnamed_type_89)];
    char b;
#else
    char a;
    unnamed_type_89 b;
#endif
};
struct unnamed_type_89_alignment var91;
#pragma pack(1)
struct unnamed_type_89_packed {
    unnamed_type_89 a;
};
#pragma pack()
struct unnamed_type_89_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct unnamed_type_89_packed)];
    char b;
#else
    char a;
    struct unnamed_type_89_packed b;
#endif
};
struct unnamed_type_89_required_alignment var92;
struct unnamed_type_89_size {
    char a[sizeof(unnamed_type_89)+1];
    char b;
};
struct unnamed_type_89_size var93;

#ifdef MSVC
__declspec(align(4)) typedef struct {
#else
typedef struct {
#endif
    unnamed_type_89 FlexArrayMemb;
#ifdef MSVC
} EmptyAlignedLongLongMemb;
#else
} __attribute__((aligned(4))) EmptyAlignedLongLongMemb;
#endif
EmptyAlignedLongLongMemb var94;
struct EmptyAlignedLongLongMemb_alignment {
#ifdef MSVC
    char a[_Alignof(EmptyAlignedLongLongMemb)];
    char b;
#else
    char a;
    EmptyAlignedLongLongMemb b;
#endif
};
struct EmptyAlignedLongLongMemb_alignment var95;
#pragma pack(1)
struct EmptyAlignedLongLongMemb_packed {
    EmptyAlignedLongLongMemb a;
};
#pragma pack()
struct EmptyAlignedLongLongMemb_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct EmptyAlignedLongLongMemb_packed)];
    char b;
#else
    char a;
    struct EmptyAlignedLongLongMemb_packed b;
#endif
};
struct EmptyAlignedLongLongMemb_required_alignment var96;
struct EmptyAlignedLongLongMemb_size {
    char a[sizeof(EmptyAlignedLongLongMemb)+1];
    char b;
};
struct EmptyAlignedLongLongMemb_size var97;

#ifdef MSVC
typedef long long unnamed_type_98[];
#else
typedef long long unnamed_type_98[0];
#endif
unnamed_type_98 var99;
struct unnamed_type_98_alignment {
#ifdef MSVC
    char a[_Alignof(unnamed_type_98)];
    char b;
#else
    char a;
    unnamed_type_98 b;
#endif
};
struct unnamed_type_98_alignment var100;
#pragma pack(1)
struct unnamed_type_98_packed {
    unnamed_type_98 a;
};
#pragma pack()
struct unnamed_type_98_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct unnamed_type_98_packed)];
    char b;
#else
    char a;
    struct unnamed_type_98_packed b;
#endif
};
struct unnamed_type_98_required_alignment var101;
struct unnamed_type_98_size {
    char a[sizeof(unnamed_type_98)+1];
    char b;
};
struct unnamed_type_98_size var102;

#pragma pack(1)
#ifdef MSVC
__declspec(align(4)) typedef struct {
#else
typedef struct {
#endif
    unnamed_type_98 FlexArrayMemb;
#ifdef MSVC
} EmptyPackedAlignedLongLongMemb;
#else
} __attribute__((aligned(4))) EmptyPackedAlignedLongLongMemb;
#endif
EmptyPackedAlignedLongLongMemb var103;
#pragma pack()
struct EmptyPackedAlignedLongLongMemb_alignment {
#ifdef MSVC
    char a[_Alignof(EmptyPackedAlignedLongLongMemb)];
    char b;
#else
    char a;
    EmptyPackedAlignedLongLongMemb b;
#endif
};
struct EmptyPackedAlignedLongLongMemb_alignment var104;
#pragma pack(1)
struct EmptyPackedAlignedLongLongMemb_packed {
    EmptyPackedAlignedLongLongMemb a;
};
#pragma pack()
struct EmptyPackedAlignedLongLongMemb_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct EmptyPackedAlignedLongLongMemb_packed)];
    char b;
#else
    char a;
    struct EmptyPackedAlignedLongLongMemb_packed b;
#endif
};
struct EmptyPackedAlignedLongLongMemb_required_alignment var105;
struct EmptyPackedAlignedLongLongMemb_size {
    char a[sizeof(EmptyPackedAlignedLongLongMemb)+1];
    char b;
};
struct EmptyPackedAlignedLongLongMemb_size var106;

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
_Static_assert(sizeof(X) == 14, "record X wrong sizeof");
_Static_assert(_Alignof(X) == 2, "record X wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct X_alignment) == 16, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_alignment) == 2, "record X wrong alignment");
_Static_assert(sizeof(struct X_packed) == 14, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_packed) == 1, "record X wrong alignment");
_Static_assert(sizeof(struct X_required_alignment) == 15, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_required_alignment) == 1, "record X wrong alignment");
_Static_assert(sizeof(struct X_size) == 16, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_size) == 1, "record X wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(X,b) == 64, "field X.b wrong bit offset");
_Static_assert(__builtin_bitoffsetof(X,c) == 80, "field X.c wrong bit offset");
#endif
_Static_assert(sizeof(YA) == 1, "record YA wrong sizeof");
_Static_assert(_Alignof(YA) == 1, "record YA wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct YA_alignment) == 2, "record YA wrong sizeof");
_Static_assert(_Alignof(struct YA_alignment) == 1, "record YA wrong alignment");
_Static_assert(sizeof(struct YA_packed) == 1, "record YA wrong sizeof");
_Static_assert(_Alignof(struct YA_packed) == 1, "record YA wrong alignment");
_Static_assert(sizeof(struct YA_required_alignment) == 2, "record YA wrong sizeof");
_Static_assert(_Alignof(struct YA_required_alignment) == 1, "record YA wrong alignment");
_Static_assert(sizeof(struct YA_size) == 3, "record YA wrong sizeof");
_Static_assert(_Alignof(struct YA_size) == 1, "record YA wrong alignment");
#endif
_Static_assert(sizeof(YB) == 2, "record YB wrong sizeof");
_Static_assert(_Alignof(YB) == 1, "record YB wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct YB_alignment) == 3, "record YB wrong sizeof");
_Static_assert(_Alignof(struct YB_alignment) == 1, "record YB wrong alignment");
_Static_assert(sizeof(struct YB_packed) == 2, "record YB wrong sizeof");
_Static_assert(_Alignof(struct YB_packed) == 1, "record YB wrong alignment");
_Static_assert(sizeof(struct YB_required_alignment) == 3, "record YB wrong sizeof");
_Static_assert(_Alignof(struct YB_required_alignment) == 1, "record YB wrong alignment");
_Static_assert(sizeof(struct YB_size) == 4, "record YB wrong sizeof");
_Static_assert(_Alignof(struct YB_size) == 1, "record YB wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(YB,b) == 8, "field YB.b wrong bit offset");
#endif
_Static_assert(sizeof(YC) == 1, "record YC wrong sizeof");
_Static_assert(_Alignof(YC) == 1, "record YC wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct YC_alignment) == 2, "record YC wrong sizeof");
_Static_assert(_Alignof(struct YC_alignment) == 1, "record YC wrong alignment");
_Static_assert(sizeof(struct YC_packed) == 1, "record YC wrong sizeof");
_Static_assert(_Alignof(struct YC_packed) == 1, "record YC wrong alignment");
_Static_assert(sizeof(struct YC_required_alignment) == 2, "record YC wrong sizeof");
_Static_assert(_Alignof(struct YC_required_alignment) == 1, "record YC wrong alignment");
_Static_assert(sizeof(struct YC_size) == 3, "record YC wrong sizeof");
_Static_assert(_Alignof(struct YC_size) == 1, "record YC wrong alignment");
#endif
_Static_assert(sizeof(YD) == 2, "record YD wrong sizeof");
_Static_assert(_Alignof(YD) == 1, "record YD wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct YD_alignment) == 3, "record YD wrong sizeof");
_Static_assert(_Alignof(struct YD_alignment) == 1, "record YD wrong alignment");
_Static_assert(sizeof(struct YD_packed) == 2, "record YD wrong sizeof");
_Static_assert(_Alignof(struct YD_packed) == 1, "record YD wrong alignment");
_Static_assert(sizeof(struct YD_required_alignment) == 3, "record YD wrong sizeof");
_Static_assert(_Alignof(struct YD_required_alignment) == 1, "record YD wrong alignment");
_Static_assert(sizeof(struct YD_size) == 4, "record YD wrong sizeof");
_Static_assert(_Alignof(struct YD_size) == 1, "record YD wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(YD,b) == 8, "field YD.b wrong bit offset");
#endif
_Static_assert(sizeof(YE) == 1, "record YE wrong sizeof");
_Static_assert(_Alignof(YE) == 1, "record YE wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct YE_alignment) == 2, "record YE wrong sizeof");
_Static_assert(_Alignof(struct YE_alignment) == 1, "record YE wrong alignment");
_Static_assert(sizeof(struct YE_packed) == 1, "record YE wrong sizeof");
_Static_assert(_Alignof(struct YE_packed) == 1, "record YE wrong alignment");
_Static_assert(sizeof(struct YE_required_alignment) == 2, "record YE wrong sizeof");
_Static_assert(_Alignof(struct YE_required_alignment) == 1, "record YE wrong alignment");
_Static_assert(sizeof(struct YE_size) == 3, "record YE wrong sizeof");
_Static_assert(_Alignof(struct YE_size) == 1, "record YE wrong alignment");
#endif
_Static_assert(sizeof(YF) == 2, "record YF wrong sizeof");
_Static_assert(_Alignof(YF) == 1, "record YF wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct YF_alignment) == 3, "record YF wrong sizeof");
_Static_assert(_Alignof(struct YF_alignment) == 1, "record YF wrong alignment");
_Static_assert(sizeof(struct YF_packed) == 2, "record YF wrong sizeof");
_Static_assert(_Alignof(struct YF_packed) == 1, "record YF wrong alignment");
_Static_assert(sizeof(struct YF_required_alignment) == 3, "record YF wrong sizeof");
_Static_assert(_Alignof(struct YF_required_alignment) == 1, "record YF wrong alignment");
_Static_assert(sizeof(struct YF_size) == 4, "record YF wrong sizeof");
_Static_assert(_Alignof(struct YF_size) == 1, "record YF wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(YF,b) == 8, "field YF.b wrong bit offset");
#endif
_Static_assert(sizeof(D0) == 16, "record D0 wrong sizeof");
_Static_assert(_Alignof(D0) == 16, "record D0 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D0_alignment) == 32, "record D0 wrong sizeof");
_Static_assert(_Alignof(struct D0_alignment) == 16, "record D0 wrong alignment");
_Static_assert(sizeof(struct D0_packed) == 16, "record D0 wrong sizeof");
_Static_assert(_Alignof(struct D0_packed) == 1, "record D0 wrong alignment");
_Static_assert(sizeof(struct D0_required_alignment) == 17, "record D0 wrong sizeof");
_Static_assert(_Alignof(struct D0_required_alignment) == 1, "record D0 wrong alignment");
_Static_assert(sizeof(struct D0_size) == 18, "record D0 wrong sizeof");
_Static_assert(_Alignof(struct D0_size) == 1, "record D0 wrong alignment");
#endif
_Static_assert(sizeof(RB0) == 8, "record RB0 wrong sizeof");
_Static_assert(_Alignof(RB0) == 8, "record RB0 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct RB0_alignment) == 16, "record RB0 wrong sizeof");
_Static_assert(_Alignof(struct RB0_alignment) == 8, "record RB0 wrong alignment");
_Static_assert(sizeof(struct RB0_packed) == 8, "record RB0 wrong sizeof");
_Static_assert(_Alignof(struct RB0_packed) == 1, "record RB0 wrong alignment");
_Static_assert(sizeof(struct RB0_required_alignment) == 9, "record RB0 wrong sizeof");
_Static_assert(_Alignof(struct RB0_required_alignment) == 1, "record RB0 wrong alignment");
_Static_assert(sizeof(struct RB0_size) == 10, "record RB0 wrong sizeof");
_Static_assert(_Alignof(struct RB0_size) == 1, "record RB0 wrong alignment");
#endif
_Static_assert(sizeof(RC) == 2, "record RC wrong sizeof");
_Static_assert(_Alignof(RC) == 1, "record RC wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct RC_alignment) == 3, "record RC wrong sizeof");
_Static_assert(_Alignof(struct RC_alignment) == 1, "record RC wrong alignment");
_Static_assert(sizeof(struct RC_packed) == 2, "record RC wrong sizeof");
_Static_assert(_Alignof(struct RC_packed) == 1, "record RC wrong alignment");
_Static_assert(sizeof(struct RC_required_alignment) == 3, "record RC wrong sizeof");
_Static_assert(_Alignof(struct RC_required_alignment) == 1, "record RC wrong alignment");
_Static_assert(sizeof(struct RC_size) == 4, "record RC wrong sizeof");
_Static_assert(_Alignof(struct RC_size) == 1, "record RC wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(RC,c) == 8, "field RC.c wrong bit offset");
#endif
_Static_assert(sizeof(RE) == 3, "record RE wrong sizeof");
_Static_assert(_Alignof(RE) == 1, "record RE wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct RE_alignment) == 4, "record RE wrong sizeof");
_Static_assert(_Alignof(struct RE_alignment) == 1, "record RE wrong alignment");
_Static_assert(sizeof(struct RE_packed) == 3, "record RE wrong sizeof");
_Static_assert(_Alignof(struct RE_packed) == 1, "record RE wrong alignment");
_Static_assert(sizeof(struct RE_required_alignment) == 4, "record RE wrong sizeof");
_Static_assert(_Alignof(struct RE_required_alignment) == 1, "record RE wrong alignment");
_Static_assert(sizeof(struct RE_size) == 5, "record RE wrong sizeof");
_Static_assert(_Alignof(struct RE_size) == 1, "record RE wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(RE,c) == 8, "field RE.c wrong bit offset");
#endif
_Static_assert(sizeof(PA) == 4, "record PA wrong sizeof");
_Static_assert(_Alignof(PA) == 4, "record PA wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct PA_alignment) == 8, "record PA wrong sizeof");
_Static_assert(_Alignof(struct PA_alignment) == 4, "record PA wrong alignment");
_Static_assert(sizeof(struct PA_packed) == 4, "record PA wrong sizeof");
_Static_assert(_Alignof(struct PA_packed) == 1, "record PA wrong alignment");
_Static_assert(sizeof(struct PA_required_alignment) == 5, "record PA wrong sizeof");
_Static_assert(_Alignof(struct PA_required_alignment) == 1, "record PA wrong alignment");
_Static_assert(sizeof(struct PA_size) == 6, "record PA wrong sizeof");
_Static_assert(_Alignof(struct PA_size) == 1, "record PA wrong alignment");
#endif
_Static_assert(sizeof(PB) == 4, "record PB wrong sizeof");
_Static_assert(_Alignof(PB) == 8, "record PB wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct PB_alignment) == 16, "record PB wrong sizeof");
_Static_assert(_Alignof(struct PB_alignment) == 8, "record PB wrong alignment");
_Static_assert(sizeof(struct PB_packed) == 4, "record PB wrong sizeof");
_Static_assert(_Alignof(struct PB_packed) == 1, "record PB wrong alignment");
_Static_assert(sizeof(struct PB_required_alignment) == 5, "record PB wrong sizeof");
_Static_assert(_Alignof(struct PB_required_alignment) == 1, "record PB wrong alignment");
_Static_assert(sizeof(struct PB_size) == 6, "record PB wrong sizeof");
_Static_assert(_Alignof(struct PB_size) == 1, "record PB wrong alignment");
#endif
_Static_assert(sizeof(PC) == 5, "record PC wrong sizeof");
_Static_assert(_Alignof(PC) == 1, "record PC wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct PC_alignment) == 6, "record PC wrong sizeof");
_Static_assert(_Alignof(struct PC_alignment) == 1, "record PC wrong alignment");
_Static_assert(sizeof(struct PC_packed) == 5, "record PC wrong sizeof");
_Static_assert(_Alignof(struct PC_packed) == 1, "record PC wrong alignment");
_Static_assert(sizeof(struct PC_required_alignment) == 6, "record PC wrong sizeof");
_Static_assert(_Alignof(struct PC_required_alignment) == 1, "record PC wrong alignment");
_Static_assert(sizeof(struct PC_size) == 7, "record PC wrong sizeof");
_Static_assert(_Alignof(struct PC_size) == 1, "record PC wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(PC,x) == 8, "field PC.x wrong bit offset");
#endif
_Static_assert(sizeof(PD) == 4, "record PD wrong sizeof");
_Static_assert(_Alignof(PD) == 8, "record PD wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct PD_alignment) == 16, "record PD wrong sizeof");
_Static_assert(_Alignof(struct PD_alignment) == 8, "record PD wrong alignment");
_Static_assert(sizeof(struct PD_packed) == 4, "record PD wrong sizeof");
_Static_assert(_Alignof(struct PD_packed) == 1, "record PD wrong alignment");
_Static_assert(sizeof(struct PD_required_alignment) == 5, "record PD wrong sizeof");
_Static_assert(_Alignof(struct PD_required_alignment) == 1, "record PD wrong alignment");
_Static_assert(sizeof(struct PD_size) == 6, "record PD wrong sizeof");
_Static_assert(_Alignof(struct PD_size) == 1, "record PD wrong alignment");
#endif
_Static_assert(sizeof(PE) == 5, "record PE wrong sizeof");
_Static_assert(_Alignof(PE) == 1, "record PE wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct PE_alignment) == 6, "record PE wrong sizeof");
_Static_assert(_Alignof(struct PE_alignment) == 1, "record PE wrong alignment");
_Static_assert(sizeof(struct PE_packed) == 5, "record PE wrong sizeof");
_Static_assert(_Alignof(struct PE_packed) == 1, "record PE wrong alignment");
_Static_assert(sizeof(struct PE_required_alignment) == 6, "record PE wrong sizeof");
_Static_assert(_Alignof(struct PE_required_alignment) == 1, "record PE wrong alignment");
_Static_assert(sizeof(struct PE_size) == 7, "record PE wrong sizeof");
_Static_assert(_Alignof(struct PE_size) == 1, "record PE wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(PE,x) == 8, "field PE.x wrong bit offset");
#endif
_Static_assert(sizeof(QA) == 4, "record QA wrong sizeof");
_Static_assert(_Alignof(QA) == 2, "record QA wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct QA_alignment) == 6, "record QA wrong sizeof");
_Static_assert(_Alignof(struct QA_alignment) == 2, "record QA wrong alignment");
_Static_assert(sizeof(struct QA_packed) == 4, "record QA wrong sizeof");
_Static_assert(_Alignof(struct QA_packed) == 1, "record QA wrong alignment");
_Static_assert(sizeof(struct QA_required_alignment) == 5, "record QA wrong sizeof");
_Static_assert(_Alignof(struct QA_required_alignment) == 1, "record QA wrong alignment");
_Static_assert(sizeof(struct QA_size) == 6, "record QA wrong sizeof");
_Static_assert(_Alignof(struct QA_size) == 1, "record QA wrong alignment");
#endif
_Static_assert(sizeof(QB) == 5, "record QB wrong sizeof");
_Static_assert(_Alignof(QB) == 1, "record QB wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct QB_alignment) == 6, "record QB wrong sizeof");
_Static_assert(_Alignof(struct QB_alignment) == 1, "record QB wrong alignment");
_Static_assert(sizeof(struct QB_packed) == 5, "record QB wrong sizeof");
_Static_assert(_Alignof(struct QB_packed) == 1, "record QB wrong alignment");
_Static_assert(sizeof(struct QB_required_alignment) == 6, "record QB wrong sizeof");
_Static_assert(_Alignof(struct QB_required_alignment) == 1, "record QB wrong alignment");
_Static_assert(sizeof(struct QB_size) == 7, "record QB wrong sizeof");
_Static_assert(_Alignof(struct QB_size) == 1, "record QB wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(QB,b) == 8, "field QB.b wrong bit offset");
#endif
_Static_assert(sizeof(QC) == 6, "record QC wrong sizeof");
_Static_assert(_Alignof(QC) == 2, "record QC wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct QC_alignment) == 8, "record QC wrong sizeof");
_Static_assert(_Alignof(struct QC_alignment) == 2, "record QC wrong alignment");
_Static_assert(sizeof(struct QC_packed) == 6, "record QC wrong sizeof");
_Static_assert(_Alignof(struct QC_packed) == 1, "record QC wrong alignment");
_Static_assert(sizeof(struct QC_required_alignment) == 7, "record QC wrong sizeof");
_Static_assert(_Alignof(struct QC_required_alignment) == 1, "record QC wrong alignment");
_Static_assert(sizeof(struct QC_size) == 8, "record QC wrong sizeof");
_Static_assert(_Alignof(struct QC_size) == 1, "record QC wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(QC,b) == 16, "field QC.b wrong bit offset");
#endif
_Static_assert(sizeof(QD) == 2, "record QD wrong sizeof");
_Static_assert(_Alignof(QD) == 2, "record QD wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct QD_alignment) == 4, "record QD wrong sizeof");
_Static_assert(_Alignof(struct QD_alignment) == 2, "record QD wrong alignment");
_Static_assert(sizeof(struct QD_packed) == 2, "record QD wrong sizeof");
_Static_assert(_Alignof(struct QD_packed) == 1, "record QD wrong alignment");
_Static_assert(sizeof(struct QD_required_alignment) == 3, "record QD wrong sizeof");
_Static_assert(_Alignof(struct QD_required_alignment) == 1, "record QD wrong alignment");
_Static_assert(sizeof(struct QD_size) == 4, "record QD wrong sizeof");
_Static_assert(_Alignof(struct QD_size) == 1, "record QD wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(QD,b) == 8, "field QD.b wrong bit offset");
#endif
_Static_assert(sizeof(EmptyAlignedLongLongMemb) == 0, "record EmptyAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(EmptyAlignedLongLongMemb) == 8, "record EmptyAlignedLongLongMemb wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_alignment) == 8, "record EmptyAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_alignment) == 8, "record EmptyAlignedLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_packed) == 0, "record EmptyAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_packed) == 1, "record EmptyAlignedLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_required_alignment) == 1, "record EmptyAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_required_alignment) == 1, "record EmptyAlignedLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_size) == 2, "record EmptyAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_size) == 1, "record EmptyAlignedLongLongMemb wrong alignment");
#endif
_Static_assert(sizeof(EmptyPackedAlignedLongLongMemb) == 0, "record EmptyPackedAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(EmptyPackedAlignedLongLongMemb) == 4, "record EmptyPackedAlignedLongLongMemb wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_alignment) == 4, "record EmptyPackedAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_alignment) == 4, "record EmptyPackedAlignedLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_packed) == 0, "record EmptyPackedAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_packed) == 1, "record EmptyPackedAlignedLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_required_alignment) == 1, "record EmptyPackedAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_required_alignment) == 1, "record EmptyPackedAlignedLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_size) == 2, "record EmptyPackedAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_size) == 1, "record EmptyPackedAlignedLongLongMemb wrong alignment");
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
_Static_assert(sizeof(X) == 14, "record X wrong sizeof");
_Static_assert(_Alignof(X) == 2, "record X wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct X_alignment) == 16, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_alignment) == 2, "record X wrong alignment");
_Static_assert(sizeof(struct X_packed) == 14, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_packed) == 1, "record X wrong alignment");
_Static_assert(sizeof(struct X_required_alignment) == 15, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_required_alignment) == 1, "record X wrong alignment");
_Static_assert(sizeof(struct X_size) == 16, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_size) == 1, "record X wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(X,b) == 64, "field X.b wrong bit offset");
_Static_assert(__builtin_bitoffsetof(X,c) == 80, "field X.c wrong bit offset");
#endif
_Static_assert(sizeof(YA) == 16, "record YA wrong sizeof");
_Static_assert(_Alignof(YA) == 16, "record YA wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct YA_alignment) == 32, "record YA wrong sizeof");
_Static_assert(_Alignof(struct YA_alignment) == 16, "record YA wrong alignment");
_Static_assert(sizeof(struct YA_packed) == 16, "record YA wrong sizeof");
_Static_assert(_Alignof(struct YA_packed) == 1, "record YA wrong alignment");
_Static_assert(sizeof(struct YA_required_alignment) == 17, "record YA wrong sizeof");
_Static_assert(_Alignof(struct YA_required_alignment) == 1, "record YA wrong alignment");
_Static_assert(sizeof(struct YA_size) == 18, "record YA wrong sizeof");
_Static_assert(_Alignof(struct YA_size) == 1, "record YA wrong alignment");
#endif
_Static_assert(sizeof(YB) == 17, "record YB wrong sizeof");
_Static_assert(_Alignof(YB) == 1, "record YB wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct YB_alignment) == 18, "record YB wrong sizeof");
_Static_assert(_Alignof(struct YB_alignment) == 1, "record YB wrong alignment");
_Static_assert(sizeof(struct YB_packed) == 17, "record YB wrong sizeof");
_Static_assert(_Alignof(struct YB_packed) == 1, "record YB wrong alignment");
_Static_assert(sizeof(struct YB_required_alignment) == 18, "record YB wrong sizeof");
_Static_assert(_Alignof(struct YB_required_alignment) == 1, "record YB wrong alignment");
_Static_assert(sizeof(struct YB_size) == 19, "record YB wrong sizeof");
_Static_assert(_Alignof(struct YB_size) == 1, "record YB wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(YB,b) == 8, "field YB.b wrong bit offset");
#endif
_Static_assert(sizeof(YC) == 8, "record YC wrong sizeof");
_Static_assert(_Alignof(YC) == 8, "record YC wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct YC_alignment) == 16, "record YC wrong sizeof");
_Static_assert(_Alignof(struct YC_alignment) == 8, "record YC wrong alignment");
_Static_assert(sizeof(struct YC_packed) == 8, "record YC wrong sizeof");
_Static_assert(_Alignof(struct YC_packed) == 1, "record YC wrong alignment");
_Static_assert(sizeof(struct YC_required_alignment) == 9, "record YC wrong sizeof");
_Static_assert(_Alignof(struct YC_required_alignment) == 1, "record YC wrong alignment");
_Static_assert(sizeof(struct YC_size) == 10, "record YC wrong sizeof");
_Static_assert(_Alignof(struct YC_size) == 1, "record YC wrong alignment");
#endif
_Static_assert(sizeof(YD) == 9, "record YD wrong sizeof");
_Static_assert(_Alignof(YD) == 1, "record YD wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct YD_alignment) == 10, "record YD wrong sizeof");
_Static_assert(_Alignof(struct YD_alignment) == 1, "record YD wrong alignment");
_Static_assert(sizeof(struct YD_packed) == 9, "record YD wrong sizeof");
_Static_assert(_Alignof(struct YD_packed) == 1, "record YD wrong alignment");
_Static_assert(sizeof(struct YD_required_alignment) == 10, "record YD wrong sizeof");
_Static_assert(_Alignof(struct YD_required_alignment) == 1, "record YD wrong alignment");
_Static_assert(sizeof(struct YD_size) == 11, "record YD wrong sizeof");
_Static_assert(_Alignof(struct YD_size) == 1, "record YD wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(YD,b) == 8, "field YD.b wrong bit offset");
#endif
_Static_assert(sizeof(YE) == 4, "record YE wrong sizeof");
_Static_assert(_Alignof(YE) == 4, "record YE wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct YE_alignment) == 8, "record YE wrong sizeof");
_Static_assert(_Alignof(struct YE_alignment) == 4, "record YE wrong alignment");
_Static_assert(sizeof(struct YE_packed) == 4, "record YE wrong sizeof");
_Static_assert(_Alignof(struct YE_packed) == 1, "record YE wrong alignment");
_Static_assert(sizeof(struct YE_required_alignment) == 5, "record YE wrong sizeof");
_Static_assert(_Alignof(struct YE_required_alignment) == 1, "record YE wrong alignment");
_Static_assert(sizeof(struct YE_size) == 6, "record YE wrong sizeof");
_Static_assert(_Alignof(struct YE_size) == 1, "record YE wrong alignment");
#endif
_Static_assert(sizeof(YF) == 5, "record YF wrong sizeof");
_Static_assert(_Alignof(YF) == 1, "record YF wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct YF_alignment) == 6, "record YF wrong sizeof");
_Static_assert(_Alignof(struct YF_alignment) == 1, "record YF wrong alignment");
_Static_assert(sizeof(struct YF_packed) == 5, "record YF wrong sizeof");
_Static_assert(_Alignof(struct YF_packed) == 1, "record YF wrong alignment");
_Static_assert(sizeof(struct YF_required_alignment) == 6, "record YF wrong sizeof");
_Static_assert(_Alignof(struct YF_required_alignment) == 1, "record YF wrong alignment");
_Static_assert(sizeof(struct YF_size) == 7, "record YF wrong sizeof");
_Static_assert(_Alignof(struct YF_size) == 1, "record YF wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(YF,b) == 8, "field YF.b wrong bit offset");
#endif
_Static_assert(sizeof(D0) == 16, "record D0 wrong sizeof");
_Static_assert(_Alignof(D0) == 16, "record D0 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D0_alignment) == 32, "record D0 wrong sizeof");
_Static_assert(_Alignof(struct D0_alignment) == 16, "record D0 wrong alignment");
_Static_assert(sizeof(struct D0_packed) == 16, "record D0 wrong sizeof");
_Static_assert(_Alignof(struct D0_packed) == 1, "record D0 wrong alignment");
_Static_assert(sizeof(struct D0_required_alignment) == 17, "record D0 wrong sizeof");
_Static_assert(_Alignof(struct D0_required_alignment) == 1, "record D0 wrong alignment");
_Static_assert(sizeof(struct D0_size) == 18, "record D0 wrong sizeof");
_Static_assert(_Alignof(struct D0_size) == 1, "record D0 wrong alignment");
#endif
_Static_assert(sizeof(RB0) == 8, "record RB0 wrong sizeof");
_Static_assert(_Alignof(RB0) == 8, "record RB0 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct RB0_alignment) == 16, "record RB0 wrong sizeof");
_Static_assert(_Alignof(struct RB0_alignment) == 8, "record RB0 wrong alignment");
_Static_assert(sizeof(struct RB0_packed) == 8, "record RB0 wrong sizeof");
_Static_assert(_Alignof(struct RB0_packed) == 1, "record RB0 wrong alignment");
_Static_assert(sizeof(struct RB0_required_alignment) == 9, "record RB0 wrong sizeof");
_Static_assert(_Alignof(struct RB0_required_alignment) == 1, "record RB0 wrong alignment");
_Static_assert(sizeof(struct RB0_size) == 10, "record RB0 wrong sizeof");
_Static_assert(_Alignof(struct RB0_size) == 1, "record RB0 wrong alignment");
#endif
_Static_assert(sizeof(RC) == 2, "record RC wrong sizeof");
_Static_assert(_Alignof(RC) == 1, "record RC wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct RC_alignment) == 3, "record RC wrong sizeof");
_Static_assert(_Alignof(struct RC_alignment) == 1, "record RC wrong alignment");
_Static_assert(sizeof(struct RC_packed) == 2, "record RC wrong sizeof");
_Static_assert(_Alignof(struct RC_packed) == 1, "record RC wrong alignment");
_Static_assert(sizeof(struct RC_required_alignment) == 3, "record RC wrong sizeof");
_Static_assert(_Alignof(struct RC_required_alignment) == 1, "record RC wrong alignment");
_Static_assert(sizeof(struct RC_size) == 4, "record RC wrong sizeof");
_Static_assert(_Alignof(struct RC_size) == 1, "record RC wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(RC,c) == 8, "field RC.c wrong bit offset");
#endif
_Static_assert(sizeof(RE) == 3, "record RE wrong sizeof");
_Static_assert(_Alignof(RE) == 1, "record RE wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct RE_alignment) == 4, "record RE wrong sizeof");
_Static_assert(_Alignof(struct RE_alignment) == 1, "record RE wrong alignment");
_Static_assert(sizeof(struct RE_packed) == 3, "record RE wrong sizeof");
_Static_assert(_Alignof(struct RE_packed) == 1, "record RE wrong alignment");
_Static_assert(sizeof(struct RE_required_alignment) == 4, "record RE wrong sizeof");
_Static_assert(_Alignof(struct RE_required_alignment) == 1, "record RE wrong alignment");
_Static_assert(sizeof(struct RE_size) == 5, "record RE wrong sizeof");
_Static_assert(_Alignof(struct RE_size) == 1, "record RE wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(RE,c) == 8, "field RE.c wrong bit offset");
#endif
_Static_assert(sizeof(PA) == 4, "record PA wrong sizeof");
_Static_assert(_Alignof(PA) == 4, "record PA wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct PA_alignment) == 8, "record PA wrong sizeof");
_Static_assert(_Alignof(struct PA_alignment) == 4, "record PA wrong alignment");
_Static_assert(sizeof(struct PA_packed) == 4, "record PA wrong sizeof");
_Static_assert(_Alignof(struct PA_packed) == 1, "record PA wrong alignment");
_Static_assert(sizeof(struct PA_required_alignment) == 5, "record PA wrong sizeof");
_Static_assert(_Alignof(struct PA_required_alignment) == 1, "record PA wrong alignment");
_Static_assert(sizeof(struct PA_size) == 6, "record PA wrong sizeof");
_Static_assert(_Alignof(struct PA_size) == 1, "record PA wrong alignment");
#endif
_Static_assert(sizeof(PB) == 4, "record PB wrong sizeof");
_Static_assert(_Alignof(PB) == 8, "record PB wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct PB_alignment) == 16, "record PB wrong sizeof");
_Static_assert(_Alignof(struct PB_alignment) == 8, "record PB wrong alignment");
_Static_assert(sizeof(struct PB_packed) == 4, "record PB wrong sizeof");
_Static_assert(_Alignof(struct PB_packed) == 1, "record PB wrong alignment");
_Static_assert(sizeof(struct PB_required_alignment) == 5, "record PB wrong sizeof");
_Static_assert(_Alignof(struct PB_required_alignment) == 1, "record PB wrong alignment");
_Static_assert(sizeof(struct PB_size) == 6, "record PB wrong sizeof");
_Static_assert(_Alignof(struct PB_size) == 1, "record PB wrong alignment");
#endif
_Static_assert(sizeof(PC) == 5, "record PC wrong sizeof");
_Static_assert(_Alignof(PC) == 1, "record PC wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct PC_alignment) == 6, "record PC wrong sizeof");
_Static_assert(_Alignof(struct PC_alignment) == 1, "record PC wrong alignment");
_Static_assert(sizeof(struct PC_packed) == 5, "record PC wrong sizeof");
_Static_assert(_Alignof(struct PC_packed) == 1, "record PC wrong alignment");
_Static_assert(sizeof(struct PC_required_alignment) == 6, "record PC wrong sizeof");
_Static_assert(_Alignof(struct PC_required_alignment) == 1, "record PC wrong alignment");
_Static_assert(sizeof(struct PC_size) == 7, "record PC wrong sizeof");
_Static_assert(_Alignof(struct PC_size) == 1, "record PC wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(PC,x) == 8, "field PC.x wrong bit offset");
#endif
_Static_assert(sizeof(PD) == 4, "record PD wrong sizeof");
_Static_assert(_Alignof(PD) == 8, "record PD wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct PD_alignment) == 16, "record PD wrong sizeof");
_Static_assert(_Alignof(struct PD_alignment) == 8, "record PD wrong alignment");
_Static_assert(sizeof(struct PD_packed) == 4, "record PD wrong sizeof");
_Static_assert(_Alignof(struct PD_packed) == 1, "record PD wrong alignment");
_Static_assert(sizeof(struct PD_required_alignment) == 5, "record PD wrong sizeof");
_Static_assert(_Alignof(struct PD_required_alignment) == 1, "record PD wrong alignment");
_Static_assert(sizeof(struct PD_size) == 6, "record PD wrong sizeof");
_Static_assert(_Alignof(struct PD_size) == 1, "record PD wrong alignment");
#endif
_Static_assert(sizeof(PE) == 5, "record PE wrong sizeof");
_Static_assert(_Alignof(PE) == 1, "record PE wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct PE_alignment) == 6, "record PE wrong sizeof");
_Static_assert(_Alignof(struct PE_alignment) == 1, "record PE wrong alignment");
_Static_assert(sizeof(struct PE_packed) == 5, "record PE wrong sizeof");
_Static_assert(_Alignof(struct PE_packed) == 1, "record PE wrong alignment");
_Static_assert(sizeof(struct PE_required_alignment) == 6, "record PE wrong sizeof");
_Static_assert(_Alignof(struct PE_required_alignment) == 1, "record PE wrong alignment");
_Static_assert(sizeof(struct PE_size) == 7, "record PE wrong sizeof");
_Static_assert(_Alignof(struct PE_size) == 1, "record PE wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(PE,x) == 8, "field PE.x wrong bit offset");
#endif
_Static_assert(sizeof(QA) == 4, "record QA wrong sizeof");
_Static_assert(_Alignof(QA) == 2, "record QA wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct QA_alignment) == 6, "record QA wrong sizeof");
_Static_assert(_Alignof(struct QA_alignment) == 2, "record QA wrong alignment");
_Static_assert(sizeof(struct QA_packed) == 4, "record QA wrong sizeof");
_Static_assert(_Alignof(struct QA_packed) == 1, "record QA wrong alignment");
_Static_assert(sizeof(struct QA_required_alignment) == 5, "record QA wrong sizeof");
_Static_assert(_Alignof(struct QA_required_alignment) == 1, "record QA wrong alignment");
_Static_assert(sizeof(struct QA_size) == 6, "record QA wrong sizeof");
_Static_assert(_Alignof(struct QA_size) == 1, "record QA wrong alignment");
#endif
_Static_assert(sizeof(QB) == 5, "record QB wrong sizeof");
_Static_assert(_Alignof(QB) == 1, "record QB wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct QB_alignment) == 6, "record QB wrong sizeof");
_Static_assert(_Alignof(struct QB_alignment) == 1, "record QB wrong alignment");
_Static_assert(sizeof(struct QB_packed) == 5, "record QB wrong sizeof");
_Static_assert(_Alignof(struct QB_packed) == 1, "record QB wrong alignment");
_Static_assert(sizeof(struct QB_required_alignment) == 6, "record QB wrong sizeof");
_Static_assert(_Alignof(struct QB_required_alignment) == 1, "record QB wrong alignment");
_Static_assert(sizeof(struct QB_size) == 7, "record QB wrong sizeof");
_Static_assert(_Alignof(struct QB_size) == 1, "record QB wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(QB,b) == 8, "field QB.b wrong bit offset");
#endif
_Static_assert(sizeof(QC) == 6, "record QC wrong sizeof");
_Static_assert(_Alignof(QC) == 2, "record QC wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct QC_alignment) == 8, "record QC wrong sizeof");
_Static_assert(_Alignof(struct QC_alignment) == 2, "record QC wrong alignment");
_Static_assert(sizeof(struct QC_packed) == 6, "record QC wrong sizeof");
_Static_assert(_Alignof(struct QC_packed) == 1, "record QC wrong alignment");
_Static_assert(sizeof(struct QC_required_alignment) == 7, "record QC wrong sizeof");
_Static_assert(_Alignof(struct QC_required_alignment) == 1, "record QC wrong alignment");
_Static_assert(sizeof(struct QC_size) == 8, "record QC wrong sizeof");
_Static_assert(_Alignof(struct QC_size) == 1, "record QC wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(QC,b) == 16, "field QC.b wrong bit offset");
#endif
_Static_assert(sizeof(QD) == 2, "record QD wrong sizeof");
_Static_assert(_Alignof(QD) == 2, "record QD wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct QD_alignment) == 4, "record QD wrong sizeof");
_Static_assert(_Alignof(struct QD_alignment) == 2, "record QD wrong alignment");
_Static_assert(sizeof(struct QD_packed) == 2, "record QD wrong sizeof");
_Static_assert(_Alignof(struct QD_packed) == 1, "record QD wrong alignment");
_Static_assert(sizeof(struct QD_required_alignment) == 3, "record QD wrong sizeof");
_Static_assert(_Alignof(struct QD_required_alignment) == 1, "record QD wrong alignment");
_Static_assert(sizeof(struct QD_size) == 4, "record QD wrong sizeof");
_Static_assert(_Alignof(struct QD_size) == 1, "record QD wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(QD,b) == 8, "field QD.b wrong bit offset");
#endif
_Static_assert(sizeof(EmptyAlignedLongLongMemb) == 0, "record EmptyAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(EmptyAlignedLongLongMemb) == 8, "record EmptyAlignedLongLongMemb wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_alignment) == 8, "record EmptyAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_alignment) == 8, "record EmptyAlignedLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_packed) == 0, "record EmptyAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_packed) == 1, "record EmptyAlignedLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_required_alignment) == 1, "record EmptyAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_required_alignment) == 1, "record EmptyAlignedLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_size) == 2, "record EmptyAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_size) == 1, "record EmptyAlignedLongLongMemb wrong alignment");
#endif
_Static_assert(sizeof(EmptyPackedAlignedLongLongMemb) == 0, "record EmptyPackedAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(EmptyPackedAlignedLongLongMemb) == 4, "record EmptyPackedAlignedLongLongMemb wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_alignment) == 4, "record EmptyPackedAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_alignment) == 4, "record EmptyPackedAlignedLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_packed) == 0, "record EmptyPackedAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_packed) == 1, "record EmptyPackedAlignedLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_required_alignment) == 1, "record EmptyPackedAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_required_alignment) == 1, "record EmptyPackedAlignedLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_size) == 2, "record EmptyPackedAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_size) == 1, "record EmptyPackedAlignedLongLongMemb wrong alignment");
#endif
#elif defined(AARCH64_PC_WINDOWS_MSVC) ||  defined(X8664_PC_WINDOWS_MSVC) ||  defined(X8664_UNKNOWN_WINDOWS) 
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
_Static_assert(sizeof(X) == 16, "record X wrong sizeof");
_Static_assert(_Alignof(X) == 4, "record X wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct X_alignment) == 20, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_alignment) == 4, "record X wrong alignment");
_Static_assert(sizeof(struct X_packed) == 16, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_packed) == 1, "record X wrong alignment");
_Static_assert(sizeof(struct X_required_alignment) == 17, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_required_alignment) == 1, "record X wrong alignment");
_Static_assert(sizeof(struct X_size) == 18, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_size) == 1, "record X wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(X,b) == 64, "field X.b wrong bit offset");
_Static_assert(__builtin_bitoffsetof(X,c) == 80, "field X.c wrong bit offset");
#endif
_Static_assert(sizeof(YA) == 32, "record YA wrong sizeof");
_Static_assert(_Alignof(YA) == 32, "record YA wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct YA_alignment) == 64, "record YA wrong sizeof");
_Static_assert(_Alignof(struct YA_alignment) == 32, "record YA wrong alignment");
_Static_assert(sizeof(struct YA_packed) == 32, "record YA wrong sizeof");
_Static_assert(_Alignof(struct YA_packed) == 1, "record YA wrong alignment");
_Static_assert(sizeof(struct YA_required_alignment) == 33, "record YA wrong sizeof");
_Static_assert(_Alignof(struct YA_required_alignment) == 1, "record YA wrong alignment");
_Static_assert(sizeof(struct YA_size) == 34, "record YA wrong sizeof");
_Static_assert(_Alignof(struct YA_size) == 1, "record YA wrong alignment");
#endif
_Static_assert(sizeof(YB) == 33, "record YB wrong sizeof");
_Static_assert(_Alignof(YB) == 1, "record YB wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct YB_alignment) == 34, "record YB wrong sizeof");
_Static_assert(_Alignof(struct YB_alignment) == 1, "record YB wrong alignment");
_Static_assert(sizeof(struct YB_packed) == 33, "record YB wrong sizeof");
_Static_assert(_Alignof(struct YB_packed) == 1, "record YB wrong alignment");
_Static_assert(sizeof(struct YB_required_alignment) == 34, "record YB wrong sizeof");
_Static_assert(_Alignof(struct YB_required_alignment) == 1, "record YB wrong alignment");
_Static_assert(sizeof(struct YB_size) == 35, "record YB wrong sizeof");
_Static_assert(_Alignof(struct YB_size) == 1, "record YB wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(YB,b) == 8, "field YB.b wrong bit offset");
#endif
_Static_assert(sizeof(YC) == 8, "record YC wrong sizeof");
_Static_assert(_Alignof(YC) == 32, "record YC wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct YC_alignment) == 64, "record YC wrong sizeof");
_Static_assert(_Alignof(struct YC_alignment) == 32, "record YC wrong alignment");
_Static_assert(sizeof(struct YC_packed) == 8, "record YC wrong sizeof");
_Static_assert(_Alignof(struct YC_packed) == 1, "record YC wrong alignment");
_Static_assert(sizeof(struct YC_required_alignment) == 9, "record YC wrong sizeof");
_Static_assert(_Alignof(struct YC_required_alignment) == 1, "record YC wrong alignment");
_Static_assert(sizeof(struct YC_size) == 10, "record YC wrong sizeof");
_Static_assert(_Alignof(struct YC_size) == 1, "record YC wrong alignment");
#endif
_Static_assert(sizeof(YD) == 9, "record YD wrong sizeof");
_Static_assert(_Alignof(YD) == 1, "record YD wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct YD_alignment) == 10, "record YD wrong sizeof");
_Static_assert(_Alignof(struct YD_alignment) == 1, "record YD wrong alignment");
_Static_assert(sizeof(struct YD_packed) == 9, "record YD wrong sizeof");
_Static_assert(_Alignof(struct YD_packed) == 1, "record YD wrong alignment");
_Static_assert(sizeof(struct YD_required_alignment) == 10, "record YD wrong sizeof");
_Static_assert(_Alignof(struct YD_required_alignment) == 1, "record YD wrong alignment");
_Static_assert(sizeof(struct YD_size) == 11, "record YD wrong sizeof");
_Static_assert(_Alignof(struct YD_size) == 1, "record YD wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(YD,b) == 8, "field YD.b wrong bit offset");
#endif
_Static_assert(sizeof(YE) == 4, "record YE wrong sizeof");
_Static_assert(_Alignof(YE) == 32, "record YE wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct YE_alignment) == 64, "record YE wrong sizeof");
_Static_assert(_Alignof(struct YE_alignment) == 32, "record YE wrong alignment");
_Static_assert(sizeof(struct YE_packed) == 4, "record YE wrong sizeof");
_Static_assert(_Alignof(struct YE_packed) == 1, "record YE wrong alignment");
_Static_assert(sizeof(struct YE_required_alignment) == 5, "record YE wrong sizeof");
_Static_assert(_Alignof(struct YE_required_alignment) == 1, "record YE wrong alignment");
_Static_assert(sizeof(struct YE_size) == 6, "record YE wrong sizeof");
_Static_assert(_Alignof(struct YE_size) == 1, "record YE wrong alignment");
#endif
_Static_assert(sizeof(YF) == 5, "record YF wrong sizeof");
_Static_assert(_Alignof(YF) == 1, "record YF wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct YF_alignment) == 6, "record YF wrong sizeof");
_Static_assert(_Alignof(struct YF_alignment) == 1, "record YF wrong alignment");
_Static_assert(sizeof(struct YF_packed) == 5, "record YF wrong sizeof");
_Static_assert(_Alignof(struct YF_packed) == 1, "record YF wrong alignment");
_Static_assert(sizeof(struct YF_required_alignment) == 6, "record YF wrong sizeof");
_Static_assert(_Alignof(struct YF_required_alignment) == 1, "record YF wrong alignment");
_Static_assert(sizeof(struct YF_size) == 7, "record YF wrong sizeof");
_Static_assert(_Alignof(struct YF_size) == 1, "record YF wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(YF,b) == 8, "field YF.b wrong bit offset");
#endif
_Static_assert(sizeof(D0) == 16, "record D0 wrong sizeof");
_Static_assert(_Alignof(D0) == 16, "record D0 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D0_alignment) == 32, "record D0 wrong sizeof");
_Static_assert(_Alignof(struct D0_alignment) == 16, "record D0 wrong alignment");
_Static_assert(sizeof(struct D0_packed) == 16, "record D0 wrong sizeof");
_Static_assert(_Alignof(struct D0_packed) == 1, "record D0 wrong alignment");
_Static_assert(sizeof(struct D0_required_alignment) == 17, "record D0 wrong sizeof");
_Static_assert(_Alignof(struct D0_required_alignment) == 1, "record D0 wrong alignment");
_Static_assert(sizeof(struct D0_size) == 18, "record D0 wrong sizeof");
_Static_assert(_Alignof(struct D0_size) == 1, "record D0 wrong alignment");
#endif
_Static_assert(sizeof(RB0) == 8, "record RB0 wrong sizeof");
_Static_assert(_Alignof(RB0) == 1024, "record RB0 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct RB0_alignment) == 2048, "record RB0 wrong sizeof");
_Static_assert(_Alignof(struct RB0_alignment) == 1024, "record RB0 wrong alignment");
_Static_assert(sizeof(struct RB0_packed) == 8, "record RB0 wrong sizeof");
_Static_assert(_Alignof(struct RB0_packed) == 1, "record RB0 wrong alignment");
_Static_assert(sizeof(struct RB0_required_alignment) == 9, "record RB0 wrong sizeof");
_Static_assert(_Alignof(struct RB0_required_alignment) == 1, "record RB0 wrong alignment");
_Static_assert(sizeof(struct RB0_size) == 10, "record RB0 wrong sizeof");
_Static_assert(_Alignof(struct RB0_size) == 1, "record RB0 wrong alignment");
#endif
_Static_assert(sizeof(RC) == 1028, "record RC wrong sizeof");
_Static_assert(_Alignof(RC) == 1024, "record RC wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct RC_alignment) == 2052, "record RC wrong sizeof");
_Static_assert(_Alignof(struct RC_alignment) == 1024, "record RC wrong alignment");
_Static_assert(sizeof(struct RC_packed) == 1028, "record RC wrong sizeof");
_Static_assert(_Alignof(struct RC_packed) == 1, "record RC wrong alignment");
_Static_assert(sizeof(struct RC_required_alignment) == 1029, "record RC wrong sizeof");
_Static_assert(_Alignof(struct RC_required_alignment) == 1, "record RC wrong alignment");
_Static_assert(sizeof(struct RC_size) == 1030, "record RC wrong sizeof");
_Static_assert(_Alignof(struct RC_size) == 1, "record RC wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(RC,c) == 8192, "field RC.c wrong bit offset");
#endif
_Static_assert(sizeof(RE) == 1029, "record RE wrong sizeof");
_Static_assert(_Alignof(RE) == 1, "record RE wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct RE_alignment) == 1030, "record RE wrong sizeof");
_Static_assert(_Alignof(struct RE_alignment) == 1, "record RE wrong alignment");
_Static_assert(sizeof(struct RE_packed) == 1029, "record RE wrong sizeof");
_Static_assert(_Alignof(struct RE_packed) == 1, "record RE wrong alignment");
_Static_assert(sizeof(struct RE_required_alignment) == 1030, "record RE wrong sizeof");
_Static_assert(_Alignof(struct RE_required_alignment) == 1, "record RE wrong alignment");
_Static_assert(sizeof(struct RE_size) == 1031, "record RE wrong sizeof");
_Static_assert(_Alignof(struct RE_size) == 1, "record RE wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(RE,c) == 8, "field RE.c wrong bit offset");
#endif
_Static_assert(sizeof(PA) == 4, "record PA wrong sizeof");
_Static_assert(_Alignof(PA) == 4, "record PA wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct PA_alignment) == 8, "record PA wrong sizeof");
_Static_assert(_Alignof(struct PA_alignment) == 4, "record PA wrong alignment");
_Static_assert(sizeof(struct PA_packed) == 4, "record PA wrong sizeof");
_Static_assert(_Alignof(struct PA_packed) == 1, "record PA wrong alignment");
_Static_assert(sizeof(struct PA_required_alignment) == 5, "record PA wrong sizeof");
_Static_assert(_Alignof(struct PA_required_alignment) == 1, "record PA wrong alignment");
_Static_assert(sizeof(struct PA_size) == 6, "record PA wrong sizeof");
_Static_assert(_Alignof(struct PA_size) == 1, "record PA wrong alignment");
#endif
_Static_assert(sizeof(PB) == 4, "record PB wrong sizeof");
_Static_assert(_Alignof(PB) == 8, "record PB wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct PB_alignment) == 16, "record PB wrong sizeof");
_Static_assert(_Alignof(struct PB_alignment) == 8, "record PB wrong alignment");
_Static_assert(sizeof(struct PB_packed) == 4, "record PB wrong sizeof");
_Static_assert(_Alignof(struct PB_packed) == 1, "record PB wrong alignment");
_Static_assert(sizeof(struct PB_required_alignment) == 5, "record PB wrong sizeof");
_Static_assert(_Alignof(struct PB_required_alignment) == 1, "record PB wrong alignment");
_Static_assert(sizeof(struct PB_size) == 6, "record PB wrong sizeof");
_Static_assert(_Alignof(struct PB_size) == 1, "record PB wrong alignment");
#endif
_Static_assert(sizeof(PC) == 16, "record PC wrong sizeof");
_Static_assert(_Alignof(PC) == 8, "record PC wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct PC_alignment) == 24, "record PC wrong sizeof");
_Static_assert(_Alignof(struct PC_alignment) == 8, "record PC wrong alignment");
_Static_assert(sizeof(struct PC_packed) == 16, "record PC wrong sizeof");
_Static_assert(_Alignof(struct PC_packed) == 1, "record PC wrong alignment");
_Static_assert(sizeof(struct PC_required_alignment) == 17, "record PC wrong sizeof");
_Static_assert(_Alignof(struct PC_required_alignment) == 1, "record PC wrong alignment");
_Static_assert(sizeof(struct PC_size) == 18, "record PC wrong sizeof");
_Static_assert(_Alignof(struct PC_size) == 1, "record PC wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(PC,x) == 64, "field PC.x wrong bit offset");
#endif
_Static_assert(sizeof(PD) == 4, "record PD wrong sizeof");
_Static_assert(_Alignof(PD) == 8, "record PD wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct PD_alignment) == 16, "record PD wrong sizeof");
_Static_assert(_Alignof(struct PD_alignment) == 8, "record PD wrong alignment");
_Static_assert(sizeof(struct PD_packed) == 4, "record PD wrong sizeof");
_Static_assert(_Alignof(struct PD_packed) == 1, "record PD wrong alignment");
_Static_assert(sizeof(struct PD_required_alignment) == 5, "record PD wrong sizeof");
_Static_assert(_Alignof(struct PD_required_alignment) == 1, "record PD wrong alignment");
_Static_assert(sizeof(struct PD_size) == 6, "record PD wrong sizeof");
_Static_assert(_Alignof(struct PD_size) == 1, "record PD wrong alignment");
#endif
_Static_assert(sizeof(PE) == 16, "record PE wrong sizeof");
_Static_assert(_Alignof(PE) == 8, "record PE wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct PE_alignment) == 24, "record PE wrong sizeof");
_Static_assert(_Alignof(struct PE_alignment) == 8, "record PE wrong alignment");
_Static_assert(sizeof(struct PE_packed) == 16, "record PE wrong sizeof");
_Static_assert(_Alignof(struct PE_packed) == 1, "record PE wrong alignment");
_Static_assert(sizeof(struct PE_required_alignment) == 17, "record PE wrong sizeof");
_Static_assert(_Alignof(struct PE_required_alignment) == 1, "record PE wrong alignment");
_Static_assert(sizeof(struct PE_size) == 18, "record PE wrong sizeof");
_Static_assert(_Alignof(struct PE_size) == 1, "record PE wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(PE,x) == 64, "field PE.x wrong bit offset");
#endif
_Static_assert(sizeof(QA) == 4, "record QA wrong sizeof");
_Static_assert(_Alignof(QA) == 4, "record QA wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct QA_alignment) == 8, "record QA wrong sizeof");
_Static_assert(_Alignof(struct QA_alignment) == 4, "record QA wrong alignment");
_Static_assert(sizeof(struct QA_packed) == 4, "record QA wrong sizeof");
_Static_assert(_Alignof(struct QA_packed) == 1, "record QA wrong alignment");
_Static_assert(sizeof(struct QA_required_alignment) == 5, "record QA wrong sizeof");
_Static_assert(_Alignof(struct QA_required_alignment) == 1, "record QA wrong alignment");
_Static_assert(sizeof(struct QA_size) == 6, "record QA wrong sizeof");
_Static_assert(_Alignof(struct QA_size) == 1, "record QA wrong alignment");
#endif
_Static_assert(sizeof(QB) == 6, "record QB wrong sizeof");
_Static_assert(_Alignof(QB) == 2, "record QB wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct QB_alignment) == 8, "record QB wrong sizeof");
_Static_assert(_Alignof(struct QB_alignment) == 2, "record QB wrong alignment");
_Static_assert(sizeof(struct QB_packed) == 6, "record QB wrong sizeof");
_Static_assert(_Alignof(struct QB_packed) == 1, "record QB wrong alignment");
_Static_assert(sizeof(struct QB_required_alignment) == 7, "record QB wrong sizeof");
_Static_assert(_Alignof(struct QB_required_alignment) == 1, "record QB wrong alignment");
_Static_assert(sizeof(struct QB_size) == 8, "record QB wrong sizeof");
_Static_assert(_Alignof(struct QB_size) == 1, "record QB wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(QB,b) == 16, "field QB.b wrong bit offset");
#endif
_Static_assert(sizeof(QC) == 8, "record QC wrong sizeof");
_Static_assert(_Alignof(QC) == 4, "record QC wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct QC_alignment) == 12, "record QC wrong sizeof");
_Static_assert(_Alignof(struct QC_alignment) == 4, "record QC wrong alignment");
_Static_assert(sizeof(struct QC_packed) == 8, "record QC wrong sizeof");
_Static_assert(_Alignof(struct QC_packed) == 1, "record QC wrong alignment");
_Static_assert(sizeof(struct QC_required_alignment) == 9, "record QC wrong sizeof");
_Static_assert(_Alignof(struct QC_required_alignment) == 1, "record QC wrong alignment");
_Static_assert(sizeof(struct QC_size) == 10, "record QC wrong sizeof");
_Static_assert(_Alignof(struct QC_size) == 1, "record QC wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(QC,b) == 32, "field QC.b wrong bit offset");
#endif
_Static_assert(sizeof(QD) == 8, "record QD wrong sizeof");
_Static_assert(_Alignof(QD) == 4, "record QD wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct QD_alignment) == 12, "record QD wrong sizeof");
_Static_assert(_Alignof(struct QD_alignment) == 4, "record QD wrong alignment");
_Static_assert(sizeof(struct QD_packed) == 8, "record QD wrong sizeof");
_Static_assert(_Alignof(struct QD_packed) == 1, "record QD wrong alignment");
_Static_assert(sizeof(struct QD_required_alignment) == 9, "record QD wrong sizeof");
_Static_assert(_Alignof(struct QD_required_alignment) == 1, "record QD wrong alignment");
_Static_assert(sizeof(struct QD_size) == 10, "record QD wrong sizeof");
_Static_assert(_Alignof(struct QD_size) == 1, "record QD wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(QD,b) == 32, "field QD.b wrong bit offset");
#endif
_Static_assert(sizeof(EmptyAlignedLongLongMemb) == 4, "record EmptyAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(EmptyAlignedLongLongMemb) == 8, "record EmptyAlignedLongLongMemb wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_alignment) == 16, "record EmptyAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_alignment) == 8, "record EmptyAlignedLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_packed) == 4, "record EmptyAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_packed) == 1, "record EmptyAlignedLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_required_alignment) == 5, "record EmptyAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_required_alignment) == 1, "record EmptyAlignedLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_size) == 6, "record EmptyAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_size) == 1, "record EmptyAlignedLongLongMemb wrong alignment");
#endif
_Static_assert(sizeof(EmptyPackedAlignedLongLongMemb) == 4, "record EmptyPackedAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(EmptyPackedAlignedLongLongMemb) == 4, "record EmptyPackedAlignedLongLongMemb wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_alignment) == 8, "record EmptyPackedAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_alignment) == 4, "record EmptyPackedAlignedLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_packed) == 4, "record EmptyPackedAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_packed) == 1, "record EmptyPackedAlignedLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_required_alignment) == 5, "record EmptyPackedAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_required_alignment) == 1, "record EmptyPackedAlignedLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_size) == 6, "record EmptyPackedAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_size) == 1, "record EmptyPackedAlignedLongLongMemb wrong alignment");
#endif
#elif defined(ARMV7_APPLE_IOS) ||  defined(ARMV7S_APPLE_IOS) 
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
_Static_assert(sizeof(B) == 8, "record B wrong sizeof");
_Static_assert(_Alignof(B) == 4, "record B wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 12, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_alignment) == 4, "record B wrong alignment");
_Static_assert(sizeof(struct B_packed) == 8, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_packed) == 1, "record B wrong alignment");
_Static_assert(sizeof(struct B_required_alignment) == 9, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "record B wrong alignment");
_Static_assert(sizeof(struct B_size) == 10, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_size) == 1, "record B wrong alignment");
#endif
_Static_assert(sizeof(X) == 14, "record X wrong sizeof");
_Static_assert(_Alignof(X) == 2, "record X wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct X_alignment) == 16, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_alignment) == 2, "record X wrong alignment");
_Static_assert(sizeof(struct X_packed) == 14, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_packed) == 1, "record X wrong alignment");
_Static_assert(sizeof(struct X_required_alignment) == 15, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_required_alignment) == 1, "record X wrong alignment");
_Static_assert(sizeof(struct X_size) == 16, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_size) == 1, "record X wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(X,b) == 64, "field X.b wrong bit offset");
_Static_assert(__builtin_bitoffsetof(X,c) == 80, "field X.c wrong bit offset");
#endif
_Static_assert(sizeof(YA) == 16, "record YA wrong sizeof");
_Static_assert(_Alignof(YA) == 16, "record YA wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct YA_alignment) == 32, "record YA wrong sizeof");
_Static_assert(_Alignof(struct YA_alignment) == 16, "record YA wrong alignment");
_Static_assert(sizeof(struct YA_packed) == 16, "record YA wrong sizeof");
_Static_assert(_Alignof(struct YA_packed) == 1, "record YA wrong alignment");
_Static_assert(sizeof(struct YA_required_alignment) == 17, "record YA wrong sizeof");
_Static_assert(_Alignof(struct YA_required_alignment) == 1, "record YA wrong alignment");
_Static_assert(sizeof(struct YA_size) == 18, "record YA wrong sizeof");
_Static_assert(_Alignof(struct YA_size) == 1, "record YA wrong alignment");
#endif
_Static_assert(sizeof(YB) == 17, "record YB wrong sizeof");
_Static_assert(_Alignof(YB) == 1, "record YB wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct YB_alignment) == 18, "record YB wrong sizeof");
_Static_assert(_Alignof(struct YB_alignment) == 1, "record YB wrong alignment");
_Static_assert(sizeof(struct YB_packed) == 17, "record YB wrong sizeof");
_Static_assert(_Alignof(struct YB_packed) == 1, "record YB wrong alignment");
_Static_assert(sizeof(struct YB_required_alignment) == 18, "record YB wrong sizeof");
_Static_assert(_Alignof(struct YB_required_alignment) == 1, "record YB wrong alignment");
_Static_assert(sizeof(struct YB_size) == 19, "record YB wrong sizeof");
_Static_assert(_Alignof(struct YB_size) == 1, "record YB wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(YB,b) == 8, "field YB.b wrong bit offset");
#endif
_Static_assert(sizeof(YC) == 8, "record YC wrong sizeof");
_Static_assert(_Alignof(YC) == 8, "record YC wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct YC_alignment) == 16, "record YC wrong sizeof");
_Static_assert(_Alignof(struct YC_alignment) == 8, "record YC wrong alignment");
_Static_assert(sizeof(struct YC_packed) == 8, "record YC wrong sizeof");
_Static_assert(_Alignof(struct YC_packed) == 1, "record YC wrong alignment");
_Static_assert(sizeof(struct YC_required_alignment) == 9, "record YC wrong sizeof");
_Static_assert(_Alignof(struct YC_required_alignment) == 1, "record YC wrong alignment");
_Static_assert(sizeof(struct YC_size) == 10, "record YC wrong sizeof");
_Static_assert(_Alignof(struct YC_size) == 1, "record YC wrong alignment");
#endif
_Static_assert(sizeof(YD) == 9, "record YD wrong sizeof");
_Static_assert(_Alignof(YD) == 1, "record YD wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct YD_alignment) == 10, "record YD wrong sizeof");
_Static_assert(_Alignof(struct YD_alignment) == 1, "record YD wrong alignment");
_Static_assert(sizeof(struct YD_packed) == 9, "record YD wrong sizeof");
_Static_assert(_Alignof(struct YD_packed) == 1, "record YD wrong alignment");
_Static_assert(sizeof(struct YD_required_alignment) == 10, "record YD wrong sizeof");
_Static_assert(_Alignof(struct YD_required_alignment) == 1, "record YD wrong alignment");
_Static_assert(sizeof(struct YD_size) == 11, "record YD wrong sizeof");
_Static_assert(_Alignof(struct YD_size) == 1, "record YD wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(YD,b) == 8, "field YD.b wrong bit offset");
#endif
_Static_assert(sizeof(YE) == 4, "record YE wrong sizeof");
_Static_assert(_Alignof(YE) == 4, "record YE wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct YE_alignment) == 8, "record YE wrong sizeof");
_Static_assert(_Alignof(struct YE_alignment) == 4, "record YE wrong alignment");
_Static_assert(sizeof(struct YE_packed) == 4, "record YE wrong sizeof");
_Static_assert(_Alignof(struct YE_packed) == 1, "record YE wrong alignment");
_Static_assert(sizeof(struct YE_required_alignment) == 5, "record YE wrong sizeof");
_Static_assert(_Alignof(struct YE_required_alignment) == 1, "record YE wrong alignment");
_Static_assert(sizeof(struct YE_size) == 6, "record YE wrong sizeof");
_Static_assert(_Alignof(struct YE_size) == 1, "record YE wrong alignment");
#endif
_Static_assert(sizeof(YF) == 5, "record YF wrong sizeof");
_Static_assert(_Alignof(YF) == 1, "record YF wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct YF_alignment) == 6, "record YF wrong sizeof");
_Static_assert(_Alignof(struct YF_alignment) == 1, "record YF wrong alignment");
_Static_assert(sizeof(struct YF_packed) == 5, "record YF wrong sizeof");
_Static_assert(_Alignof(struct YF_packed) == 1, "record YF wrong alignment");
_Static_assert(sizeof(struct YF_required_alignment) == 6, "record YF wrong sizeof");
_Static_assert(_Alignof(struct YF_required_alignment) == 1, "record YF wrong alignment");
_Static_assert(sizeof(struct YF_size) == 7, "record YF wrong sizeof");
_Static_assert(_Alignof(struct YF_size) == 1, "record YF wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(YF,b) == 8, "field YF.b wrong bit offset");
#endif
_Static_assert(sizeof(D0) == 16, "record D0 wrong sizeof");
_Static_assert(_Alignof(D0) == 16, "record D0 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D0_alignment) == 32, "record D0 wrong sizeof");
_Static_assert(_Alignof(struct D0_alignment) == 16, "record D0 wrong alignment");
_Static_assert(sizeof(struct D0_packed) == 16, "record D0 wrong sizeof");
_Static_assert(_Alignof(struct D0_packed) == 1, "record D0 wrong alignment");
_Static_assert(sizeof(struct D0_required_alignment) == 17, "record D0 wrong sizeof");
_Static_assert(_Alignof(struct D0_required_alignment) == 1, "record D0 wrong alignment");
_Static_assert(sizeof(struct D0_size) == 18, "record D0 wrong sizeof");
_Static_assert(_Alignof(struct D0_size) == 1, "record D0 wrong alignment");
#endif
_Static_assert(sizeof(RB0) == 8, "record RB0 wrong sizeof");
_Static_assert(_Alignof(RB0) == 8, "record RB0 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct RB0_alignment) == 16, "record RB0 wrong sizeof");
_Static_assert(_Alignof(struct RB0_alignment) == 8, "record RB0 wrong alignment");
_Static_assert(sizeof(struct RB0_packed) == 8, "record RB0 wrong sizeof");
_Static_assert(_Alignof(struct RB0_packed) == 1, "record RB0 wrong alignment");
_Static_assert(sizeof(struct RB0_required_alignment) == 9, "record RB0 wrong sizeof");
_Static_assert(_Alignof(struct RB0_required_alignment) == 1, "record RB0 wrong alignment");
_Static_assert(sizeof(struct RB0_size) == 10, "record RB0 wrong sizeof");
_Static_assert(_Alignof(struct RB0_size) == 1, "record RB0 wrong alignment");
#endif
_Static_assert(sizeof(RC) == 2, "record RC wrong sizeof");
_Static_assert(_Alignof(RC) == 1, "record RC wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct RC_alignment) == 3, "record RC wrong sizeof");
_Static_assert(_Alignof(struct RC_alignment) == 1, "record RC wrong alignment");
_Static_assert(sizeof(struct RC_packed) == 2, "record RC wrong sizeof");
_Static_assert(_Alignof(struct RC_packed) == 1, "record RC wrong alignment");
_Static_assert(sizeof(struct RC_required_alignment) == 3, "record RC wrong sizeof");
_Static_assert(_Alignof(struct RC_required_alignment) == 1, "record RC wrong alignment");
_Static_assert(sizeof(struct RC_size) == 4, "record RC wrong sizeof");
_Static_assert(_Alignof(struct RC_size) == 1, "record RC wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(RC,c) == 8, "field RC.c wrong bit offset");
#endif
_Static_assert(sizeof(RE) == 3, "record RE wrong sizeof");
_Static_assert(_Alignof(RE) == 1, "record RE wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct RE_alignment) == 4, "record RE wrong sizeof");
_Static_assert(_Alignof(struct RE_alignment) == 1, "record RE wrong alignment");
_Static_assert(sizeof(struct RE_packed) == 3, "record RE wrong sizeof");
_Static_assert(_Alignof(struct RE_packed) == 1, "record RE wrong alignment");
_Static_assert(sizeof(struct RE_required_alignment) == 4, "record RE wrong sizeof");
_Static_assert(_Alignof(struct RE_required_alignment) == 1, "record RE wrong alignment");
_Static_assert(sizeof(struct RE_size) == 5, "record RE wrong sizeof");
_Static_assert(_Alignof(struct RE_size) == 1, "record RE wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(RE,c) == 8, "field RE.c wrong bit offset");
#endif
_Static_assert(sizeof(PA) == 4, "record PA wrong sizeof");
_Static_assert(_Alignof(PA) == 4, "record PA wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct PA_alignment) == 8, "record PA wrong sizeof");
_Static_assert(_Alignof(struct PA_alignment) == 4, "record PA wrong alignment");
_Static_assert(sizeof(struct PA_packed) == 4, "record PA wrong sizeof");
_Static_assert(_Alignof(struct PA_packed) == 1, "record PA wrong alignment");
_Static_assert(sizeof(struct PA_required_alignment) == 5, "record PA wrong sizeof");
_Static_assert(_Alignof(struct PA_required_alignment) == 1, "record PA wrong alignment");
_Static_assert(sizeof(struct PA_size) == 6, "record PA wrong sizeof");
_Static_assert(_Alignof(struct PA_size) == 1, "record PA wrong alignment");
#endif
_Static_assert(sizeof(PB) == 4, "record PB wrong sizeof");
_Static_assert(_Alignof(PB) == 8, "record PB wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct PB_alignment) == 16, "record PB wrong sizeof");
_Static_assert(_Alignof(struct PB_alignment) == 8, "record PB wrong alignment");
_Static_assert(sizeof(struct PB_packed) == 4, "record PB wrong sizeof");
_Static_assert(_Alignof(struct PB_packed) == 1, "record PB wrong alignment");
_Static_assert(sizeof(struct PB_required_alignment) == 5, "record PB wrong sizeof");
_Static_assert(_Alignof(struct PB_required_alignment) == 1, "record PB wrong alignment");
_Static_assert(sizeof(struct PB_size) == 6, "record PB wrong sizeof");
_Static_assert(_Alignof(struct PB_size) == 1, "record PB wrong alignment");
#endif
_Static_assert(sizeof(PC) == 5, "record PC wrong sizeof");
_Static_assert(_Alignof(PC) == 1, "record PC wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct PC_alignment) == 6, "record PC wrong sizeof");
_Static_assert(_Alignof(struct PC_alignment) == 1, "record PC wrong alignment");
_Static_assert(sizeof(struct PC_packed) == 5, "record PC wrong sizeof");
_Static_assert(_Alignof(struct PC_packed) == 1, "record PC wrong alignment");
_Static_assert(sizeof(struct PC_required_alignment) == 6, "record PC wrong sizeof");
_Static_assert(_Alignof(struct PC_required_alignment) == 1, "record PC wrong alignment");
_Static_assert(sizeof(struct PC_size) == 7, "record PC wrong sizeof");
_Static_assert(_Alignof(struct PC_size) == 1, "record PC wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(PC,x) == 8, "field PC.x wrong bit offset");
#endif
_Static_assert(sizeof(PD) == 4, "record PD wrong sizeof");
_Static_assert(_Alignof(PD) == 8, "record PD wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct PD_alignment) == 16, "record PD wrong sizeof");
_Static_assert(_Alignof(struct PD_alignment) == 8, "record PD wrong alignment");
_Static_assert(sizeof(struct PD_packed) == 4, "record PD wrong sizeof");
_Static_assert(_Alignof(struct PD_packed) == 1, "record PD wrong alignment");
_Static_assert(sizeof(struct PD_required_alignment) == 5, "record PD wrong sizeof");
_Static_assert(_Alignof(struct PD_required_alignment) == 1, "record PD wrong alignment");
_Static_assert(sizeof(struct PD_size) == 6, "record PD wrong sizeof");
_Static_assert(_Alignof(struct PD_size) == 1, "record PD wrong alignment");
#endif
_Static_assert(sizeof(PE) == 5, "record PE wrong sizeof");
_Static_assert(_Alignof(PE) == 1, "record PE wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct PE_alignment) == 6, "record PE wrong sizeof");
_Static_assert(_Alignof(struct PE_alignment) == 1, "record PE wrong alignment");
_Static_assert(sizeof(struct PE_packed) == 5, "record PE wrong sizeof");
_Static_assert(_Alignof(struct PE_packed) == 1, "record PE wrong alignment");
_Static_assert(sizeof(struct PE_required_alignment) == 6, "record PE wrong sizeof");
_Static_assert(_Alignof(struct PE_required_alignment) == 1, "record PE wrong alignment");
_Static_assert(sizeof(struct PE_size) == 7, "record PE wrong sizeof");
_Static_assert(_Alignof(struct PE_size) == 1, "record PE wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(PE,x) == 8, "field PE.x wrong bit offset");
#endif
_Static_assert(sizeof(QA) == 4, "record QA wrong sizeof");
_Static_assert(_Alignof(QA) == 2, "record QA wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct QA_alignment) == 6, "record QA wrong sizeof");
_Static_assert(_Alignof(struct QA_alignment) == 2, "record QA wrong alignment");
_Static_assert(sizeof(struct QA_packed) == 4, "record QA wrong sizeof");
_Static_assert(_Alignof(struct QA_packed) == 1, "record QA wrong alignment");
_Static_assert(sizeof(struct QA_required_alignment) == 5, "record QA wrong sizeof");
_Static_assert(_Alignof(struct QA_required_alignment) == 1, "record QA wrong alignment");
_Static_assert(sizeof(struct QA_size) == 6, "record QA wrong sizeof");
_Static_assert(_Alignof(struct QA_size) == 1, "record QA wrong alignment");
#endif
_Static_assert(sizeof(QB) == 5, "record QB wrong sizeof");
_Static_assert(_Alignof(QB) == 1, "record QB wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct QB_alignment) == 6, "record QB wrong sizeof");
_Static_assert(_Alignof(struct QB_alignment) == 1, "record QB wrong alignment");
_Static_assert(sizeof(struct QB_packed) == 5, "record QB wrong sizeof");
_Static_assert(_Alignof(struct QB_packed) == 1, "record QB wrong alignment");
_Static_assert(sizeof(struct QB_required_alignment) == 6, "record QB wrong sizeof");
_Static_assert(_Alignof(struct QB_required_alignment) == 1, "record QB wrong alignment");
_Static_assert(sizeof(struct QB_size) == 7, "record QB wrong sizeof");
_Static_assert(_Alignof(struct QB_size) == 1, "record QB wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(QB,b) == 8, "field QB.b wrong bit offset");
#endif
_Static_assert(sizeof(QC) == 6, "record QC wrong sizeof");
_Static_assert(_Alignof(QC) == 2, "record QC wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct QC_alignment) == 8, "record QC wrong sizeof");
_Static_assert(_Alignof(struct QC_alignment) == 2, "record QC wrong alignment");
_Static_assert(sizeof(struct QC_packed) == 6, "record QC wrong sizeof");
_Static_assert(_Alignof(struct QC_packed) == 1, "record QC wrong alignment");
_Static_assert(sizeof(struct QC_required_alignment) == 7, "record QC wrong sizeof");
_Static_assert(_Alignof(struct QC_required_alignment) == 1, "record QC wrong alignment");
_Static_assert(sizeof(struct QC_size) == 8, "record QC wrong sizeof");
_Static_assert(_Alignof(struct QC_size) == 1, "record QC wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(QC,b) == 16, "field QC.b wrong bit offset");
#endif
_Static_assert(sizeof(QD) == 2, "record QD wrong sizeof");
_Static_assert(_Alignof(QD) == 1, "record QD wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct QD_alignment) == 3, "record QD wrong sizeof");
_Static_assert(_Alignof(struct QD_alignment) == 1, "record QD wrong alignment");
_Static_assert(sizeof(struct QD_packed) == 2, "record QD wrong sizeof");
_Static_assert(_Alignof(struct QD_packed) == 1, "record QD wrong alignment");
_Static_assert(sizeof(struct QD_required_alignment) == 3, "record QD wrong sizeof");
_Static_assert(_Alignof(struct QD_required_alignment) == 1, "record QD wrong alignment");
_Static_assert(sizeof(struct QD_size) == 4, "record QD wrong sizeof");
_Static_assert(_Alignof(struct QD_size) == 1, "record QD wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(QD,b) == 8, "field QD.b wrong bit offset");
#endif
_Static_assert(sizeof(EmptyAlignedLongLongMemb) == 0, "record EmptyAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(EmptyAlignedLongLongMemb) == 4, "record EmptyAlignedLongLongMemb wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_alignment) == 4, "record EmptyAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_alignment) == 4, "record EmptyAlignedLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_packed) == 0, "record EmptyAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_packed) == 1, "record EmptyAlignedLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_required_alignment) == 1, "record EmptyAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_required_alignment) == 1, "record EmptyAlignedLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_size) == 2, "record EmptyAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_size) == 1, "record EmptyAlignedLongLongMemb wrong alignment");
#endif
_Static_assert(sizeof(EmptyPackedAlignedLongLongMemb) == 0, "record EmptyPackedAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(EmptyPackedAlignedLongLongMemb) == 4, "record EmptyPackedAlignedLongLongMemb wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_alignment) == 4, "record EmptyPackedAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_alignment) == 4, "record EmptyPackedAlignedLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_packed) == 0, "record EmptyPackedAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_packed) == 1, "record EmptyPackedAlignedLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_required_alignment) == 1, "record EmptyPackedAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_required_alignment) == 1, "record EmptyPackedAlignedLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_size) == 2, "record EmptyPackedAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_size) == 1, "record EmptyPackedAlignedLongLongMemb wrong alignment");
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
_Static_assert(sizeof(B) == 8, "record B wrong sizeof");
_Static_assert(_Alignof(B) == 4, "record B wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 12, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_alignment) == 4, "record B wrong alignment");
_Static_assert(sizeof(struct B_packed) == 8, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_packed) == 1, "record B wrong alignment");
_Static_assert(sizeof(struct B_required_alignment) == 9, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "record B wrong alignment");
_Static_assert(sizeof(struct B_size) == 10, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_size) == 1, "record B wrong alignment");
#endif
_Static_assert(sizeof(X) == 12, "record X wrong sizeof");
_Static_assert(_Alignof(X) == 2, "record X wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct X_alignment) == 14, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_alignment) == 2, "record X wrong alignment");
_Static_assert(sizeof(struct X_packed) == 12, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_packed) == 1, "record X wrong alignment");
_Static_assert(sizeof(struct X_required_alignment) == 13, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_required_alignment) == 1, "record X wrong alignment");
_Static_assert(sizeof(struct X_size) == 14, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_size) == 1, "record X wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(X,b) == 64, "field X.b wrong bit offset");
_Static_assert(__builtin_bitoffsetof(X,c) == 72, "field X.c wrong bit offset");
#endif
_Static_assert(sizeof(YA) == 16, "record YA wrong sizeof");
_Static_assert(_Alignof(YA) == 16, "record YA wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct YA_alignment) == 32, "record YA wrong sizeof");
_Static_assert(_Alignof(struct YA_alignment) == 16, "record YA wrong alignment");
_Static_assert(sizeof(struct YA_packed) == 16, "record YA wrong sizeof");
_Static_assert(_Alignof(struct YA_packed) == 1, "record YA wrong alignment");
_Static_assert(sizeof(struct YA_required_alignment) == 17, "record YA wrong sizeof");
_Static_assert(_Alignof(struct YA_required_alignment) == 1, "record YA wrong alignment");
_Static_assert(sizeof(struct YA_size) == 18, "record YA wrong sizeof");
_Static_assert(_Alignof(struct YA_size) == 1, "record YA wrong alignment");
#endif
_Static_assert(sizeof(YB) == 17, "record YB wrong sizeof");
_Static_assert(_Alignof(YB) == 1, "record YB wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct YB_alignment) == 18, "record YB wrong sizeof");
_Static_assert(_Alignof(struct YB_alignment) == 1, "record YB wrong alignment");
_Static_assert(sizeof(struct YB_packed) == 17, "record YB wrong sizeof");
_Static_assert(_Alignof(struct YB_packed) == 1, "record YB wrong alignment");
_Static_assert(sizeof(struct YB_required_alignment) == 18, "record YB wrong sizeof");
_Static_assert(_Alignof(struct YB_required_alignment) == 1, "record YB wrong alignment");
_Static_assert(sizeof(struct YB_size) == 19, "record YB wrong sizeof");
_Static_assert(_Alignof(struct YB_size) == 1, "record YB wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(YB,b) == 8, "field YB.b wrong bit offset");
#endif
_Static_assert(sizeof(YC) == 8, "record YC wrong sizeof");
_Static_assert(_Alignof(YC) == 8, "record YC wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct YC_alignment) == 16, "record YC wrong sizeof");
_Static_assert(_Alignof(struct YC_alignment) == 8, "record YC wrong alignment");
_Static_assert(sizeof(struct YC_packed) == 8, "record YC wrong sizeof");
_Static_assert(_Alignof(struct YC_packed) == 1, "record YC wrong alignment");
_Static_assert(sizeof(struct YC_required_alignment) == 9, "record YC wrong sizeof");
_Static_assert(_Alignof(struct YC_required_alignment) == 1, "record YC wrong alignment");
_Static_assert(sizeof(struct YC_size) == 10, "record YC wrong sizeof");
_Static_assert(_Alignof(struct YC_size) == 1, "record YC wrong alignment");
#endif
_Static_assert(sizeof(YD) == 9, "record YD wrong sizeof");
_Static_assert(_Alignof(YD) == 1, "record YD wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct YD_alignment) == 10, "record YD wrong sizeof");
_Static_assert(_Alignof(struct YD_alignment) == 1, "record YD wrong alignment");
_Static_assert(sizeof(struct YD_packed) == 9, "record YD wrong sizeof");
_Static_assert(_Alignof(struct YD_packed) == 1, "record YD wrong alignment");
_Static_assert(sizeof(struct YD_required_alignment) == 10, "record YD wrong sizeof");
_Static_assert(_Alignof(struct YD_required_alignment) == 1, "record YD wrong alignment");
_Static_assert(sizeof(struct YD_size) == 11, "record YD wrong sizeof");
_Static_assert(_Alignof(struct YD_size) == 1, "record YD wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(YD,b) == 8, "field YD.b wrong bit offset");
#endif
_Static_assert(sizeof(YE) == 4, "record YE wrong sizeof");
_Static_assert(_Alignof(YE) == 4, "record YE wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct YE_alignment) == 8, "record YE wrong sizeof");
_Static_assert(_Alignof(struct YE_alignment) == 4, "record YE wrong alignment");
_Static_assert(sizeof(struct YE_packed) == 4, "record YE wrong sizeof");
_Static_assert(_Alignof(struct YE_packed) == 1, "record YE wrong alignment");
_Static_assert(sizeof(struct YE_required_alignment) == 5, "record YE wrong sizeof");
_Static_assert(_Alignof(struct YE_required_alignment) == 1, "record YE wrong alignment");
_Static_assert(sizeof(struct YE_size) == 6, "record YE wrong sizeof");
_Static_assert(_Alignof(struct YE_size) == 1, "record YE wrong alignment");
#endif
_Static_assert(sizeof(YF) == 5, "record YF wrong sizeof");
_Static_assert(_Alignof(YF) == 1, "record YF wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct YF_alignment) == 6, "record YF wrong sizeof");
_Static_assert(_Alignof(struct YF_alignment) == 1, "record YF wrong alignment");
_Static_assert(sizeof(struct YF_packed) == 5, "record YF wrong sizeof");
_Static_assert(_Alignof(struct YF_packed) == 1, "record YF wrong alignment");
_Static_assert(sizeof(struct YF_required_alignment) == 6, "record YF wrong sizeof");
_Static_assert(_Alignof(struct YF_required_alignment) == 1, "record YF wrong alignment");
_Static_assert(sizeof(struct YF_size) == 7, "record YF wrong sizeof");
_Static_assert(_Alignof(struct YF_size) == 1, "record YF wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(YF,b) == 8, "field YF.b wrong bit offset");
#endif
_Static_assert(sizeof(D0) == 16, "record D0 wrong sizeof");
_Static_assert(_Alignof(D0) == 16, "record D0 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D0_alignment) == 32, "record D0 wrong sizeof");
_Static_assert(_Alignof(struct D0_alignment) == 16, "record D0 wrong alignment");
_Static_assert(sizeof(struct D0_packed) == 16, "record D0 wrong sizeof");
_Static_assert(_Alignof(struct D0_packed) == 1, "record D0 wrong alignment");
_Static_assert(sizeof(struct D0_required_alignment) == 17, "record D0 wrong sizeof");
_Static_assert(_Alignof(struct D0_required_alignment) == 1, "record D0 wrong alignment");
_Static_assert(sizeof(struct D0_size) == 18, "record D0 wrong sizeof");
_Static_assert(_Alignof(struct D0_size) == 1, "record D0 wrong alignment");
#endif
_Static_assert(sizeof(RB0) == 8, "record RB0 wrong sizeof");
_Static_assert(_Alignof(RB0) == 8, "record RB0 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct RB0_alignment) == 16, "record RB0 wrong sizeof");
_Static_assert(_Alignof(struct RB0_alignment) == 8, "record RB0 wrong alignment");
_Static_assert(sizeof(struct RB0_packed) == 8, "record RB0 wrong sizeof");
_Static_assert(_Alignof(struct RB0_packed) == 1, "record RB0 wrong alignment");
_Static_assert(sizeof(struct RB0_required_alignment) == 9, "record RB0 wrong sizeof");
_Static_assert(_Alignof(struct RB0_required_alignment) == 1, "record RB0 wrong alignment");
_Static_assert(sizeof(struct RB0_size) == 10, "record RB0 wrong sizeof");
_Static_assert(_Alignof(struct RB0_size) == 1, "record RB0 wrong alignment");
#endif
_Static_assert(sizeof(RC) == 2, "record RC wrong sizeof");
_Static_assert(_Alignof(RC) == 1, "record RC wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct RC_alignment) == 3, "record RC wrong sizeof");
_Static_assert(_Alignof(struct RC_alignment) == 1, "record RC wrong alignment");
_Static_assert(sizeof(struct RC_packed) == 2, "record RC wrong sizeof");
_Static_assert(_Alignof(struct RC_packed) == 1, "record RC wrong alignment");
_Static_assert(sizeof(struct RC_required_alignment) == 3, "record RC wrong sizeof");
_Static_assert(_Alignof(struct RC_required_alignment) == 1, "record RC wrong alignment");
_Static_assert(sizeof(struct RC_size) == 4, "record RC wrong sizeof");
_Static_assert(_Alignof(struct RC_size) == 1, "record RC wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(RC,c) == 8, "field RC.c wrong bit offset");
#endif
_Static_assert(sizeof(RE) == 3, "record RE wrong sizeof");
_Static_assert(_Alignof(RE) == 1, "record RE wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct RE_alignment) == 4, "record RE wrong sizeof");
_Static_assert(_Alignof(struct RE_alignment) == 1, "record RE wrong alignment");
_Static_assert(sizeof(struct RE_packed) == 3, "record RE wrong sizeof");
_Static_assert(_Alignof(struct RE_packed) == 1, "record RE wrong alignment");
_Static_assert(sizeof(struct RE_required_alignment) == 4, "record RE wrong sizeof");
_Static_assert(_Alignof(struct RE_required_alignment) == 1, "record RE wrong alignment");
_Static_assert(sizeof(struct RE_size) == 5, "record RE wrong sizeof");
_Static_assert(_Alignof(struct RE_size) == 1, "record RE wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(RE,c) == 8, "field RE.c wrong bit offset");
#endif
_Static_assert(sizeof(PA) == 4, "record PA wrong sizeof");
_Static_assert(_Alignof(PA) == 4, "record PA wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct PA_alignment) == 8, "record PA wrong sizeof");
_Static_assert(_Alignof(struct PA_alignment) == 4, "record PA wrong alignment");
_Static_assert(sizeof(struct PA_packed) == 4, "record PA wrong sizeof");
_Static_assert(_Alignof(struct PA_packed) == 1, "record PA wrong alignment");
_Static_assert(sizeof(struct PA_required_alignment) == 5, "record PA wrong sizeof");
_Static_assert(_Alignof(struct PA_required_alignment) == 1, "record PA wrong alignment");
_Static_assert(sizeof(struct PA_size) == 6, "record PA wrong sizeof");
_Static_assert(_Alignof(struct PA_size) == 1, "record PA wrong alignment");
#endif
_Static_assert(sizeof(PB) == 4, "record PB wrong sizeof");
_Static_assert(_Alignof(PB) == 8, "record PB wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct PB_alignment) == 16, "record PB wrong sizeof");
_Static_assert(_Alignof(struct PB_alignment) == 8, "record PB wrong alignment");
_Static_assert(sizeof(struct PB_packed) == 4, "record PB wrong sizeof");
_Static_assert(_Alignof(struct PB_packed) == 1, "record PB wrong alignment");
_Static_assert(sizeof(struct PB_required_alignment) == 5, "record PB wrong sizeof");
_Static_assert(_Alignof(struct PB_required_alignment) == 1, "record PB wrong alignment");
_Static_assert(sizeof(struct PB_size) == 6, "record PB wrong sizeof");
_Static_assert(_Alignof(struct PB_size) == 1, "record PB wrong alignment");
#endif
_Static_assert(sizeof(PC) == 5, "record PC wrong sizeof");
_Static_assert(_Alignof(PC) == 1, "record PC wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct PC_alignment) == 6, "record PC wrong sizeof");
_Static_assert(_Alignof(struct PC_alignment) == 1, "record PC wrong alignment");
_Static_assert(sizeof(struct PC_packed) == 5, "record PC wrong sizeof");
_Static_assert(_Alignof(struct PC_packed) == 1, "record PC wrong alignment");
_Static_assert(sizeof(struct PC_required_alignment) == 6, "record PC wrong sizeof");
_Static_assert(_Alignof(struct PC_required_alignment) == 1, "record PC wrong alignment");
_Static_assert(sizeof(struct PC_size) == 7, "record PC wrong sizeof");
_Static_assert(_Alignof(struct PC_size) == 1, "record PC wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(PC,x) == 8, "field PC.x wrong bit offset");
#endif
_Static_assert(sizeof(PD) == 4, "record PD wrong sizeof");
_Static_assert(_Alignof(PD) == 8, "record PD wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct PD_alignment) == 16, "record PD wrong sizeof");
_Static_assert(_Alignof(struct PD_alignment) == 8, "record PD wrong alignment");
_Static_assert(sizeof(struct PD_packed) == 4, "record PD wrong sizeof");
_Static_assert(_Alignof(struct PD_packed) == 1, "record PD wrong alignment");
_Static_assert(sizeof(struct PD_required_alignment) == 5, "record PD wrong sizeof");
_Static_assert(_Alignof(struct PD_required_alignment) == 1, "record PD wrong alignment");
_Static_assert(sizeof(struct PD_size) == 6, "record PD wrong sizeof");
_Static_assert(_Alignof(struct PD_size) == 1, "record PD wrong alignment");
#endif
_Static_assert(sizeof(PE) == 5, "record PE wrong sizeof");
_Static_assert(_Alignof(PE) == 1, "record PE wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct PE_alignment) == 6, "record PE wrong sizeof");
_Static_assert(_Alignof(struct PE_alignment) == 1, "record PE wrong alignment");
_Static_assert(sizeof(struct PE_packed) == 5, "record PE wrong sizeof");
_Static_assert(_Alignof(struct PE_packed) == 1, "record PE wrong alignment");
_Static_assert(sizeof(struct PE_required_alignment) == 6, "record PE wrong sizeof");
_Static_assert(_Alignof(struct PE_required_alignment) == 1, "record PE wrong alignment");
_Static_assert(sizeof(struct PE_size) == 7, "record PE wrong sizeof");
_Static_assert(_Alignof(struct PE_size) == 1, "record PE wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(PE,x) == 8, "field PE.x wrong bit offset");
#endif
_Static_assert(sizeof(QA) == 2, "record QA wrong sizeof");
_Static_assert(_Alignof(QA) == 2, "record QA wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct QA_alignment) == 4, "record QA wrong sizeof");
_Static_assert(_Alignof(struct QA_alignment) == 2, "record QA wrong alignment");
_Static_assert(sizeof(struct QA_packed) == 2, "record QA wrong sizeof");
_Static_assert(_Alignof(struct QA_packed) == 1, "record QA wrong alignment");
_Static_assert(sizeof(struct QA_required_alignment) == 3, "record QA wrong sizeof");
_Static_assert(_Alignof(struct QA_required_alignment) == 1, "record QA wrong alignment");
_Static_assert(sizeof(struct QA_size) == 4, "record QA wrong sizeof");
_Static_assert(_Alignof(struct QA_size) == 1, "record QA wrong alignment");
#endif
_Static_assert(sizeof(QB) == 3, "record QB wrong sizeof");
_Static_assert(_Alignof(QB) == 1, "record QB wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct QB_alignment) == 4, "record QB wrong sizeof");
_Static_assert(_Alignof(struct QB_alignment) == 1, "record QB wrong alignment");
_Static_assert(sizeof(struct QB_packed) == 3, "record QB wrong sizeof");
_Static_assert(_Alignof(struct QB_packed) == 1, "record QB wrong alignment");
_Static_assert(sizeof(struct QB_required_alignment) == 4, "record QB wrong sizeof");
_Static_assert(_Alignof(struct QB_required_alignment) == 1, "record QB wrong alignment");
_Static_assert(sizeof(struct QB_size) == 5, "record QB wrong sizeof");
_Static_assert(_Alignof(struct QB_size) == 1, "record QB wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(QB,b) == 8, "field QB.b wrong bit offset");
#endif
_Static_assert(sizeof(QC) == 4, "record QC wrong sizeof");
_Static_assert(_Alignof(QC) == 2, "record QC wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct QC_alignment) == 6, "record QC wrong sizeof");
_Static_assert(_Alignof(struct QC_alignment) == 2, "record QC wrong alignment");
_Static_assert(sizeof(struct QC_packed) == 4, "record QC wrong sizeof");
_Static_assert(_Alignof(struct QC_packed) == 1, "record QC wrong alignment");
_Static_assert(sizeof(struct QC_required_alignment) == 5, "record QC wrong sizeof");
_Static_assert(_Alignof(struct QC_required_alignment) == 1, "record QC wrong alignment");
_Static_assert(sizeof(struct QC_size) == 6, "record QC wrong sizeof");
_Static_assert(_Alignof(struct QC_size) == 1, "record QC wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(QC,b) == 16, "field QC.b wrong bit offset");
#endif
_Static_assert(sizeof(QD) == 2, "record QD wrong sizeof");
_Static_assert(_Alignof(QD) == 1, "record QD wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct QD_alignment) == 3, "record QD wrong sizeof");
_Static_assert(_Alignof(struct QD_alignment) == 1, "record QD wrong alignment");
_Static_assert(sizeof(struct QD_packed) == 2, "record QD wrong sizeof");
_Static_assert(_Alignof(struct QD_packed) == 1, "record QD wrong alignment");
_Static_assert(sizeof(struct QD_required_alignment) == 3, "record QD wrong sizeof");
_Static_assert(_Alignof(struct QD_required_alignment) == 1, "record QD wrong alignment");
_Static_assert(sizeof(struct QD_size) == 4, "record QD wrong sizeof");
_Static_assert(_Alignof(struct QD_size) == 1, "record QD wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(QD,b) == 8, "field QD.b wrong bit offset");
#endif
_Static_assert(sizeof(EmptyAlignedLongLongMemb) == 0, "record EmptyAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(EmptyAlignedLongLongMemb) == 4, "record EmptyAlignedLongLongMemb wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_alignment) == 4, "record EmptyAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_alignment) == 4, "record EmptyAlignedLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_packed) == 0, "record EmptyAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_packed) == 1, "record EmptyAlignedLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_required_alignment) == 1, "record EmptyAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_required_alignment) == 1, "record EmptyAlignedLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_size) == 2, "record EmptyAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_size) == 1, "record EmptyAlignedLongLongMemb wrong alignment");
#endif
_Static_assert(sizeof(EmptyPackedAlignedLongLongMemb) == 0, "record EmptyPackedAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(EmptyPackedAlignedLongLongMemb) == 4, "record EmptyPackedAlignedLongLongMemb wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_alignment) == 4, "record EmptyPackedAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_alignment) == 4, "record EmptyPackedAlignedLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_packed) == 0, "record EmptyPackedAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_packed) == 1, "record EmptyPackedAlignedLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_required_alignment) == 1, "record EmptyPackedAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_required_alignment) == 1, "record EmptyPackedAlignedLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_size) == 2, "record EmptyPackedAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_size) == 1, "record EmptyPackedAlignedLongLongMemb wrong alignment");
#endif
#elif defined(I386_APPLE_IOS) ||  defined(I586_UNKNOWN_LINUX_GNU) ||  defined(I586_UNKNOWN_LINUX_MUSL) ||  defined(I686_APPLE_MACOSX) ||  \
 defined(I686_LINUX_ANDROID) ||  defined(I686_UNKNOWN_FREEBSD) ||  defined(I686_UNKNOWN_HAIKU) ||  defined(I686_UNKNOWN_LINUX_GNU) ||  \
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
_Static_assert(sizeof(B) == 8, "record B wrong sizeof");
_Static_assert(_Alignof(B) == 4, "record B wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 12, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_alignment) == 4, "record B wrong alignment");
_Static_assert(sizeof(struct B_packed) == 8, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_packed) == 1, "record B wrong alignment");
_Static_assert(sizeof(struct B_required_alignment) == 9, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "record B wrong alignment");
_Static_assert(sizeof(struct B_size) == 10, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_size) == 1, "record B wrong alignment");
#endif
_Static_assert(sizeof(X) == 14, "record X wrong sizeof");
_Static_assert(_Alignof(X) == 2, "record X wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct X_alignment) == 16, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_alignment) == 2, "record X wrong alignment");
_Static_assert(sizeof(struct X_packed) == 14, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_packed) == 1, "record X wrong alignment");
_Static_assert(sizeof(struct X_required_alignment) == 15, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_required_alignment) == 1, "record X wrong alignment");
_Static_assert(sizeof(struct X_size) == 16, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_size) == 1, "record X wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(X,b) == 64, "field X.b wrong bit offset");
_Static_assert(__builtin_bitoffsetof(X,c) == 80, "field X.c wrong bit offset");
#endif
_Static_assert(sizeof(YA) == 1, "record YA wrong sizeof");
_Static_assert(_Alignof(YA) == 1, "record YA wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct YA_alignment) == 2, "record YA wrong sizeof");
_Static_assert(_Alignof(struct YA_alignment) == 1, "record YA wrong alignment");
_Static_assert(sizeof(struct YA_packed) == 1, "record YA wrong sizeof");
_Static_assert(_Alignof(struct YA_packed) == 1, "record YA wrong alignment");
_Static_assert(sizeof(struct YA_required_alignment) == 2, "record YA wrong sizeof");
_Static_assert(_Alignof(struct YA_required_alignment) == 1, "record YA wrong alignment");
_Static_assert(sizeof(struct YA_size) == 3, "record YA wrong sizeof");
_Static_assert(_Alignof(struct YA_size) == 1, "record YA wrong alignment");
#endif
_Static_assert(sizeof(YB) == 2, "record YB wrong sizeof");
_Static_assert(_Alignof(YB) == 1, "record YB wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct YB_alignment) == 3, "record YB wrong sizeof");
_Static_assert(_Alignof(struct YB_alignment) == 1, "record YB wrong alignment");
_Static_assert(sizeof(struct YB_packed) == 2, "record YB wrong sizeof");
_Static_assert(_Alignof(struct YB_packed) == 1, "record YB wrong alignment");
_Static_assert(sizeof(struct YB_required_alignment) == 3, "record YB wrong sizeof");
_Static_assert(_Alignof(struct YB_required_alignment) == 1, "record YB wrong alignment");
_Static_assert(sizeof(struct YB_size) == 4, "record YB wrong sizeof");
_Static_assert(_Alignof(struct YB_size) == 1, "record YB wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(YB,b) == 8, "field YB.b wrong bit offset");
#endif
_Static_assert(sizeof(YC) == 1, "record YC wrong sizeof");
_Static_assert(_Alignof(YC) == 1, "record YC wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct YC_alignment) == 2, "record YC wrong sizeof");
_Static_assert(_Alignof(struct YC_alignment) == 1, "record YC wrong alignment");
_Static_assert(sizeof(struct YC_packed) == 1, "record YC wrong sizeof");
_Static_assert(_Alignof(struct YC_packed) == 1, "record YC wrong alignment");
_Static_assert(sizeof(struct YC_required_alignment) == 2, "record YC wrong sizeof");
_Static_assert(_Alignof(struct YC_required_alignment) == 1, "record YC wrong alignment");
_Static_assert(sizeof(struct YC_size) == 3, "record YC wrong sizeof");
_Static_assert(_Alignof(struct YC_size) == 1, "record YC wrong alignment");
#endif
_Static_assert(sizeof(YD) == 2, "record YD wrong sizeof");
_Static_assert(_Alignof(YD) == 1, "record YD wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct YD_alignment) == 3, "record YD wrong sizeof");
_Static_assert(_Alignof(struct YD_alignment) == 1, "record YD wrong alignment");
_Static_assert(sizeof(struct YD_packed) == 2, "record YD wrong sizeof");
_Static_assert(_Alignof(struct YD_packed) == 1, "record YD wrong alignment");
_Static_assert(sizeof(struct YD_required_alignment) == 3, "record YD wrong sizeof");
_Static_assert(_Alignof(struct YD_required_alignment) == 1, "record YD wrong alignment");
_Static_assert(sizeof(struct YD_size) == 4, "record YD wrong sizeof");
_Static_assert(_Alignof(struct YD_size) == 1, "record YD wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(YD,b) == 8, "field YD.b wrong bit offset");
#endif
_Static_assert(sizeof(YE) == 1, "record YE wrong sizeof");
_Static_assert(_Alignof(YE) == 1, "record YE wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct YE_alignment) == 2, "record YE wrong sizeof");
_Static_assert(_Alignof(struct YE_alignment) == 1, "record YE wrong alignment");
_Static_assert(sizeof(struct YE_packed) == 1, "record YE wrong sizeof");
_Static_assert(_Alignof(struct YE_packed) == 1, "record YE wrong alignment");
_Static_assert(sizeof(struct YE_required_alignment) == 2, "record YE wrong sizeof");
_Static_assert(_Alignof(struct YE_required_alignment) == 1, "record YE wrong alignment");
_Static_assert(sizeof(struct YE_size) == 3, "record YE wrong sizeof");
_Static_assert(_Alignof(struct YE_size) == 1, "record YE wrong alignment");
#endif
_Static_assert(sizeof(YF) == 2, "record YF wrong sizeof");
_Static_assert(_Alignof(YF) == 1, "record YF wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct YF_alignment) == 3, "record YF wrong sizeof");
_Static_assert(_Alignof(struct YF_alignment) == 1, "record YF wrong alignment");
_Static_assert(sizeof(struct YF_packed) == 2, "record YF wrong sizeof");
_Static_assert(_Alignof(struct YF_packed) == 1, "record YF wrong alignment");
_Static_assert(sizeof(struct YF_required_alignment) == 3, "record YF wrong sizeof");
_Static_assert(_Alignof(struct YF_required_alignment) == 1, "record YF wrong alignment");
_Static_assert(sizeof(struct YF_size) == 4, "record YF wrong sizeof");
_Static_assert(_Alignof(struct YF_size) == 1, "record YF wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(YF,b) == 8, "field YF.b wrong bit offset");
#endif
_Static_assert(sizeof(D0) == 16, "record D0 wrong sizeof");
_Static_assert(_Alignof(D0) == 16, "record D0 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D0_alignment) == 32, "record D0 wrong sizeof");
_Static_assert(_Alignof(struct D0_alignment) == 16, "record D0 wrong alignment");
_Static_assert(sizeof(struct D0_packed) == 16, "record D0 wrong sizeof");
_Static_assert(_Alignof(struct D0_packed) == 1, "record D0 wrong alignment");
_Static_assert(sizeof(struct D0_required_alignment) == 17, "record D0 wrong sizeof");
_Static_assert(_Alignof(struct D0_required_alignment) == 1, "record D0 wrong alignment");
_Static_assert(sizeof(struct D0_size) == 18, "record D0 wrong sizeof");
_Static_assert(_Alignof(struct D0_size) == 1, "record D0 wrong alignment");
#endif
_Static_assert(sizeof(RB0) == 8, "record RB0 wrong sizeof");
_Static_assert(_Alignof(RB0) == 8, "record RB0 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct RB0_alignment) == 16, "record RB0 wrong sizeof");
_Static_assert(_Alignof(struct RB0_alignment) == 8, "record RB0 wrong alignment");
_Static_assert(sizeof(struct RB0_packed) == 8, "record RB0 wrong sizeof");
_Static_assert(_Alignof(struct RB0_packed) == 1, "record RB0 wrong alignment");
_Static_assert(sizeof(struct RB0_required_alignment) == 9, "record RB0 wrong sizeof");
_Static_assert(_Alignof(struct RB0_required_alignment) == 1, "record RB0 wrong alignment");
_Static_assert(sizeof(struct RB0_size) == 10, "record RB0 wrong sizeof");
_Static_assert(_Alignof(struct RB0_size) == 1, "record RB0 wrong alignment");
#endif
_Static_assert(sizeof(RC) == 2, "record RC wrong sizeof");
_Static_assert(_Alignof(RC) == 1, "record RC wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct RC_alignment) == 3, "record RC wrong sizeof");
_Static_assert(_Alignof(struct RC_alignment) == 1, "record RC wrong alignment");
_Static_assert(sizeof(struct RC_packed) == 2, "record RC wrong sizeof");
_Static_assert(_Alignof(struct RC_packed) == 1, "record RC wrong alignment");
_Static_assert(sizeof(struct RC_required_alignment) == 3, "record RC wrong sizeof");
_Static_assert(_Alignof(struct RC_required_alignment) == 1, "record RC wrong alignment");
_Static_assert(sizeof(struct RC_size) == 4, "record RC wrong sizeof");
_Static_assert(_Alignof(struct RC_size) == 1, "record RC wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(RC,c) == 8, "field RC.c wrong bit offset");
#endif
_Static_assert(sizeof(RE) == 3, "record RE wrong sizeof");
_Static_assert(_Alignof(RE) == 1, "record RE wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct RE_alignment) == 4, "record RE wrong sizeof");
_Static_assert(_Alignof(struct RE_alignment) == 1, "record RE wrong alignment");
_Static_assert(sizeof(struct RE_packed) == 3, "record RE wrong sizeof");
_Static_assert(_Alignof(struct RE_packed) == 1, "record RE wrong alignment");
_Static_assert(sizeof(struct RE_required_alignment) == 4, "record RE wrong sizeof");
_Static_assert(_Alignof(struct RE_required_alignment) == 1, "record RE wrong alignment");
_Static_assert(sizeof(struct RE_size) == 5, "record RE wrong sizeof");
_Static_assert(_Alignof(struct RE_size) == 1, "record RE wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(RE,c) == 8, "field RE.c wrong bit offset");
#endif
_Static_assert(sizeof(PA) == 4, "record PA wrong sizeof");
_Static_assert(_Alignof(PA) == 4, "record PA wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct PA_alignment) == 8, "record PA wrong sizeof");
_Static_assert(_Alignof(struct PA_alignment) == 4, "record PA wrong alignment");
_Static_assert(sizeof(struct PA_packed) == 4, "record PA wrong sizeof");
_Static_assert(_Alignof(struct PA_packed) == 1, "record PA wrong alignment");
_Static_assert(sizeof(struct PA_required_alignment) == 5, "record PA wrong sizeof");
_Static_assert(_Alignof(struct PA_required_alignment) == 1, "record PA wrong alignment");
_Static_assert(sizeof(struct PA_size) == 6, "record PA wrong sizeof");
_Static_assert(_Alignof(struct PA_size) == 1, "record PA wrong alignment");
#endif
_Static_assert(sizeof(PB) == 4, "record PB wrong sizeof");
_Static_assert(_Alignof(PB) == 8, "record PB wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct PB_alignment) == 16, "record PB wrong sizeof");
_Static_assert(_Alignof(struct PB_alignment) == 8, "record PB wrong alignment");
_Static_assert(sizeof(struct PB_packed) == 4, "record PB wrong sizeof");
_Static_assert(_Alignof(struct PB_packed) == 1, "record PB wrong alignment");
_Static_assert(sizeof(struct PB_required_alignment) == 5, "record PB wrong sizeof");
_Static_assert(_Alignof(struct PB_required_alignment) == 1, "record PB wrong alignment");
_Static_assert(sizeof(struct PB_size) == 6, "record PB wrong sizeof");
_Static_assert(_Alignof(struct PB_size) == 1, "record PB wrong alignment");
#endif
_Static_assert(sizeof(PC) == 5, "record PC wrong sizeof");
_Static_assert(_Alignof(PC) == 1, "record PC wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct PC_alignment) == 6, "record PC wrong sizeof");
_Static_assert(_Alignof(struct PC_alignment) == 1, "record PC wrong alignment");
_Static_assert(sizeof(struct PC_packed) == 5, "record PC wrong sizeof");
_Static_assert(_Alignof(struct PC_packed) == 1, "record PC wrong alignment");
_Static_assert(sizeof(struct PC_required_alignment) == 6, "record PC wrong sizeof");
_Static_assert(_Alignof(struct PC_required_alignment) == 1, "record PC wrong alignment");
_Static_assert(sizeof(struct PC_size) == 7, "record PC wrong sizeof");
_Static_assert(_Alignof(struct PC_size) == 1, "record PC wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(PC,x) == 8, "field PC.x wrong bit offset");
#endif
_Static_assert(sizeof(PD) == 4, "record PD wrong sizeof");
_Static_assert(_Alignof(PD) == 8, "record PD wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct PD_alignment) == 16, "record PD wrong sizeof");
_Static_assert(_Alignof(struct PD_alignment) == 8, "record PD wrong alignment");
_Static_assert(sizeof(struct PD_packed) == 4, "record PD wrong sizeof");
_Static_assert(_Alignof(struct PD_packed) == 1, "record PD wrong alignment");
_Static_assert(sizeof(struct PD_required_alignment) == 5, "record PD wrong sizeof");
_Static_assert(_Alignof(struct PD_required_alignment) == 1, "record PD wrong alignment");
_Static_assert(sizeof(struct PD_size) == 6, "record PD wrong sizeof");
_Static_assert(_Alignof(struct PD_size) == 1, "record PD wrong alignment");
#endif
_Static_assert(sizeof(PE) == 5, "record PE wrong sizeof");
_Static_assert(_Alignof(PE) == 1, "record PE wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct PE_alignment) == 6, "record PE wrong sizeof");
_Static_assert(_Alignof(struct PE_alignment) == 1, "record PE wrong alignment");
_Static_assert(sizeof(struct PE_packed) == 5, "record PE wrong sizeof");
_Static_assert(_Alignof(struct PE_packed) == 1, "record PE wrong alignment");
_Static_assert(sizeof(struct PE_required_alignment) == 6, "record PE wrong sizeof");
_Static_assert(_Alignof(struct PE_required_alignment) == 1, "record PE wrong alignment");
_Static_assert(sizeof(struct PE_size) == 7, "record PE wrong sizeof");
_Static_assert(_Alignof(struct PE_size) == 1, "record PE wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(PE,x) == 8, "field PE.x wrong bit offset");
#endif
_Static_assert(sizeof(QA) == 4, "record QA wrong sizeof");
_Static_assert(_Alignof(QA) == 2, "record QA wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct QA_alignment) == 6, "record QA wrong sizeof");
_Static_assert(_Alignof(struct QA_alignment) == 2, "record QA wrong alignment");
_Static_assert(sizeof(struct QA_packed) == 4, "record QA wrong sizeof");
_Static_assert(_Alignof(struct QA_packed) == 1, "record QA wrong alignment");
_Static_assert(sizeof(struct QA_required_alignment) == 5, "record QA wrong sizeof");
_Static_assert(_Alignof(struct QA_required_alignment) == 1, "record QA wrong alignment");
_Static_assert(sizeof(struct QA_size) == 6, "record QA wrong sizeof");
_Static_assert(_Alignof(struct QA_size) == 1, "record QA wrong alignment");
#endif
_Static_assert(sizeof(QB) == 5, "record QB wrong sizeof");
_Static_assert(_Alignof(QB) == 1, "record QB wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct QB_alignment) == 6, "record QB wrong sizeof");
_Static_assert(_Alignof(struct QB_alignment) == 1, "record QB wrong alignment");
_Static_assert(sizeof(struct QB_packed) == 5, "record QB wrong sizeof");
_Static_assert(_Alignof(struct QB_packed) == 1, "record QB wrong alignment");
_Static_assert(sizeof(struct QB_required_alignment) == 6, "record QB wrong sizeof");
_Static_assert(_Alignof(struct QB_required_alignment) == 1, "record QB wrong alignment");
_Static_assert(sizeof(struct QB_size) == 7, "record QB wrong sizeof");
_Static_assert(_Alignof(struct QB_size) == 1, "record QB wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(QB,b) == 8, "field QB.b wrong bit offset");
#endif
_Static_assert(sizeof(QC) == 6, "record QC wrong sizeof");
_Static_assert(_Alignof(QC) == 2, "record QC wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct QC_alignment) == 8, "record QC wrong sizeof");
_Static_assert(_Alignof(struct QC_alignment) == 2, "record QC wrong alignment");
_Static_assert(sizeof(struct QC_packed) == 6, "record QC wrong sizeof");
_Static_assert(_Alignof(struct QC_packed) == 1, "record QC wrong alignment");
_Static_assert(sizeof(struct QC_required_alignment) == 7, "record QC wrong sizeof");
_Static_assert(_Alignof(struct QC_required_alignment) == 1, "record QC wrong alignment");
_Static_assert(sizeof(struct QC_size) == 8, "record QC wrong sizeof");
_Static_assert(_Alignof(struct QC_size) == 1, "record QC wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(QC,b) == 16, "field QC.b wrong bit offset");
#endif
_Static_assert(sizeof(QD) == 2, "record QD wrong sizeof");
_Static_assert(_Alignof(QD) == 2, "record QD wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct QD_alignment) == 4, "record QD wrong sizeof");
_Static_assert(_Alignof(struct QD_alignment) == 2, "record QD wrong alignment");
_Static_assert(sizeof(struct QD_packed) == 2, "record QD wrong sizeof");
_Static_assert(_Alignof(struct QD_packed) == 1, "record QD wrong alignment");
_Static_assert(sizeof(struct QD_required_alignment) == 3, "record QD wrong sizeof");
_Static_assert(_Alignof(struct QD_required_alignment) == 1, "record QD wrong alignment");
_Static_assert(sizeof(struct QD_size) == 4, "record QD wrong sizeof");
_Static_assert(_Alignof(struct QD_size) == 1, "record QD wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(QD,b) == 8, "field QD.b wrong bit offset");
#endif
_Static_assert(sizeof(EmptyAlignedLongLongMemb) == 0, "record EmptyAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(EmptyAlignedLongLongMemb) == 4, "record EmptyAlignedLongLongMemb wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_alignment) == 4, "record EmptyAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_alignment) == 4, "record EmptyAlignedLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_packed) == 0, "record EmptyAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_packed) == 1, "record EmptyAlignedLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_required_alignment) == 1, "record EmptyAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_required_alignment) == 1, "record EmptyAlignedLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_size) == 2, "record EmptyAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_size) == 1, "record EmptyAlignedLongLongMemb wrong alignment");
#endif
_Static_assert(sizeof(EmptyPackedAlignedLongLongMemb) == 0, "record EmptyPackedAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(EmptyPackedAlignedLongLongMemb) == 4, "record EmptyPackedAlignedLongLongMemb wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_alignment) == 4, "record EmptyPackedAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_alignment) == 4, "record EmptyPackedAlignedLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_packed) == 0, "record EmptyPackedAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_packed) == 1, "record EmptyPackedAlignedLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_required_alignment) == 1, "record EmptyPackedAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_required_alignment) == 1, "record EmptyPackedAlignedLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_size) == 2, "record EmptyPackedAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_size) == 1, "record EmptyPackedAlignedLongLongMemb wrong alignment");
#endif
#elif defined(I586_PC_WINDOWS_MSVC) ||  defined(I686_PC_WINDOWS_MSVC) ||  defined(I686_UNKNOWN_WINDOWS) 
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
_Static_assert(sizeof(X) == 16, "record X wrong sizeof");
_Static_assert(_Alignof(X) == 4, "record X wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct X_alignment) == 20, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_alignment) == 4, "record X wrong alignment");
_Static_assert(sizeof(struct X_packed) == 16, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_packed) == 1, "record X wrong alignment");
_Static_assert(sizeof(struct X_required_alignment) == 17, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_required_alignment) == 1, "record X wrong alignment");
_Static_assert(sizeof(struct X_size) == 18, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_size) == 1, "record X wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(X,b) == 64, "field X.b wrong bit offset");
_Static_assert(__builtin_bitoffsetof(X,c) == 80, "field X.c wrong bit offset");
#endif
_Static_assert(sizeof(YA) == 32, "record YA wrong sizeof");
_Static_assert(_Alignof(YA) == 32, "record YA wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct YA_alignment) == 64, "record YA wrong sizeof");
_Static_assert(_Alignof(struct YA_alignment) == 32, "record YA wrong alignment");
_Static_assert(sizeof(struct YA_packed) == 32, "record YA wrong sizeof");
_Static_assert(_Alignof(struct YA_packed) == 1, "record YA wrong alignment");
_Static_assert(sizeof(struct YA_required_alignment) == 33, "record YA wrong sizeof");
_Static_assert(_Alignof(struct YA_required_alignment) == 1, "record YA wrong alignment");
_Static_assert(sizeof(struct YA_size) == 34, "record YA wrong sizeof");
_Static_assert(_Alignof(struct YA_size) == 1, "record YA wrong alignment");
#endif
_Static_assert(sizeof(YB) == 33, "record YB wrong sizeof");
_Static_assert(_Alignof(YB) == 1, "record YB wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct YB_alignment) == 34, "record YB wrong sizeof");
_Static_assert(_Alignof(struct YB_alignment) == 1, "record YB wrong alignment");
_Static_assert(sizeof(struct YB_packed) == 33, "record YB wrong sizeof");
_Static_assert(_Alignof(struct YB_packed) == 1, "record YB wrong alignment");
_Static_assert(sizeof(struct YB_required_alignment) == 34, "record YB wrong sizeof");
_Static_assert(_Alignof(struct YB_required_alignment) == 1, "record YB wrong alignment");
_Static_assert(sizeof(struct YB_size) == 35, "record YB wrong sizeof");
_Static_assert(_Alignof(struct YB_size) == 1, "record YB wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(YB,b) == 8, "field YB.b wrong bit offset");
#endif
_Static_assert(sizeof(YC) == 32, "record YC wrong sizeof");
_Static_assert(_Alignof(YC) == 32, "record YC wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct YC_alignment) == 64, "record YC wrong sizeof");
_Static_assert(_Alignof(struct YC_alignment) == 32, "record YC wrong alignment");
_Static_assert(sizeof(struct YC_packed) == 32, "record YC wrong sizeof");
_Static_assert(_Alignof(struct YC_packed) == 1, "record YC wrong alignment");
_Static_assert(sizeof(struct YC_required_alignment) == 33, "record YC wrong sizeof");
_Static_assert(_Alignof(struct YC_required_alignment) == 1, "record YC wrong alignment");
_Static_assert(sizeof(struct YC_size) == 34, "record YC wrong sizeof");
_Static_assert(_Alignof(struct YC_size) == 1, "record YC wrong alignment");
#endif
_Static_assert(sizeof(YD) == 33, "record YD wrong sizeof");
_Static_assert(_Alignof(YD) == 1, "record YD wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct YD_alignment) == 34, "record YD wrong sizeof");
_Static_assert(_Alignof(struct YD_alignment) == 1, "record YD wrong alignment");
_Static_assert(sizeof(struct YD_packed) == 33, "record YD wrong sizeof");
_Static_assert(_Alignof(struct YD_packed) == 1, "record YD wrong alignment");
_Static_assert(sizeof(struct YD_required_alignment) == 34, "record YD wrong sizeof");
_Static_assert(_Alignof(struct YD_required_alignment) == 1, "record YD wrong alignment");
_Static_assert(sizeof(struct YD_size) == 35, "record YD wrong sizeof");
_Static_assert(_Alignof(struct YD_size) == 1, "record YD wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(YD,b) == 8, "field YD.b wrong bit offset");
#endif
_Static_assert(sizeof(YE) == 4, "record YE wrong sizeof");
_Static_assert(_Alignof(YE) == 32, "record YE wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct YE_alignment) == 64, "record YE wrong sizeof");
_Static_assert(_Alignof(struct YE_alignment) == 32, "record YE wrong alignment");
_Static_assert(sizeof(struct YE_packed) == 4, "record YE wrong sizeof");
_Static_assert(_Alignof(struct YE_packed) == 1, "record YE wrong alignment");
_Static_assert(sizeof(struct YE_required_alignment) == 5, "record YE wrong sizeof");
_Static_assert(_Alignof(struct YE_required_alignment) == 1, "record YE wrong alignment");
_Static_assert(sizeof(struct YE_size) == 6, "record YE wrong sizeof");
_Static_assert(_Alignof(struct YE_size) == 1, "record YE wrong alignment");
#endif
_Static_assert(sizeof(YF) == 5, "record YF wrong sizeof");
_Static_assert(_Alignof(YF) == 1, "record YF wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct YF_alignment) == 6, "record YF wrong sizeof");
_Static_assert(_Alignof(struct YF_alignment) == 1, "record YF wrong alignment");
_Static_assert(sizeof(struct YF_packed) == 5, "record YF wrong sizeof");
_Static_assert(_Alignof(struct YF_packed) == 1, "record YF wrong alignment");
_Static_assert(sizeof(struct YF_required_alignment) == 6, "record YF wrong sizeof");
_Static_assert(_Alignof(struct YF_required_alignment) == 1, "record YF wrong alignment");
_Static_assert(sizeof(struct YF_size) == 7, "record YF wrong sizeof");
_Static_assert(_Alignof(struct YF_size) == 1, "record YF wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(YF,b) == 8, "field YF.b wrong bit offset");
#endif
_Static_assert(sizeof(D0) == 16, "record D0 wrong sizeof");
_Static_assert(_Alignof(D0) == 16, "record D0 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D0_alignment) == 32, "record D0 wrong sizeof");
_Static_assert(_Alignof(struct D0_alignment) == 16, "record D0 wrong alignment");
_Static_assert(sizeof(struct D0_packed) == 16, "record D0 wrong sizeof");
_Static_assert(_Alignof(struct D0_packed) == 1, "record D0 wrong alignment");
_Static_assert(sizeof(struct D0_required_alignment) == 17, "record D0 wrong sizeof");
_Static_assert(_Alignof(struct D0_required_alignment) == 1, "record D0 wrong alignment");
_Static_assert(sizeof(struct D0_size) == 18, "record D0 wrong sizeof");
_Static_assert(_Alignof(struct D0_size) == 1, "record D0 wrong alignment");
#endif
_Static_assert(sizeof(RB0) == 8, "record RB0 wrong sizeof");
_Static_assert(_Alignof(RB0) == 1024, "record RB0 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct RB0_alignment) == 2048, "record RB0 wrong sizeof");
_Static_assert(_Alignof(struct RB0_alignment) == 1024, "record RB0 wrong alignment");
_Static_assert(sizeof(struct RB0_packed) == 8, "record RB0 wrong sizeof");
_Static_assert(_Alignof(struct RB0_packed) == 1, "record RB0 wrong alignment");
_Static_assert(sizeof(struct RB0_required_alignment) == 9, "record RB0 wrong sizeof");
_Static_assert(_Alignof(struct RB0_required_alignment) == 1, "record RB0 wrong alignment");
_Static_assert(sizeof(struct RB0_size) == 10, "record RB0 wrong sizeof");
_Static_assert(_Alignof(struct RB0_size) == 1, "record RB0 wrong alignment");
#endif
_Static_assert(sizeof(RC) == 1028, "record RC wrong sizeof");
_Static_assert(_Alignof(RC) == 1024, "record RC wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct RC_alignment) == 2052, "record RC wrong sizeof");
_Static_assert(_Alignof(struct RC_alignment) == 1024, "record RC wrong alignment");
_Static_assert(sizeof(struct RC_packed) == 1028, "record RC wrong sizeof");
_Static_assert(_Alignof(struct RC_packed) == 1, "record RC wrong alignment");
_Static_assert(sizeof(struct RC_required_alignment) == 1029, "record RC wrong sizeof");
_Static_assert(_Alignof(struct RC_required_alignment) == 1, "record RC wrong alignment");
_Static_assert(sizeof(struct RC_size) == 1030, "record RC wrong sizeof");
_Static_assert(_Alignof(struct RC_size) == 1, "record RC wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(RC,c) == 8192, "field RC.c wrong bit offset");
#endif
_Static_assert(sizeof(RE) == 1029, "record RE wrong sizeof");
_Static_assert(_Alignof(RE) == 1, "record RE wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct RE_alignment) == 1030, "record RE wrong sizeof");
_Static_assert(_Alignof(struct RE_alignment) == 1, "record RE wrong alignment");
_Static_assert(sizeof(struct RE_packed) == 1029, "record RE wrong sizeof");
_Static_assert(_Alignof(struct RE_packed) == 1, "record RE wrong alignment");
_Static_assert(sizeof(struct RE_required_alignment) == 1030, "record RE wrong sizeof");
_Static_assert(_Alignof(struct RE_required_alignment) == 1, "record RE wrong alignment");
_Static_assert(sizeof(struct RE_size) == 1031, "record RE wrong sizeof");
_Static_assert(_Alignof(struct RE_size) == 1, "record RE wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(RE,c) == 8, "field RE.c wrong bit offset");
#endif
_Static_assert(sizeof(PA) == 4, "record PA wrong sizeof");
_Static_assert(_Alignof(PA) == 4, "record PA wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct PA_alignment) == 8, "record PA wrong sizeof");
_Static_assert(_Alignof(struct PA_alignment) == 4, "record PA wrong alignment");
_Static_assert(sizeof(struct PA_packed) == 4, "record PA wrong sizeof");
_Static_assert(_Alignof(struct PA_packed) == 1, "record PA wrong alignment");
_Static_assert(sizeof(struct PA_required_alignment) == 5, "record PA wrong sizeof");
_Static_assert(_Alignof(struct PA_required_alignment) == 1, "record PA wrong alignment");
_Static_assert(sizeof(struct PA_size) == 6, "record PA wrong sizeof");
_Static_assert(_Alignof(struct PA_size) == 1, "record PA wrong alignment");
#endif
_Static_assert(sizeof(PB) == 4, "record PB wrong sizeof");
_Static_assert(_Alignof(PB) == 8, "record PB wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct PB_alignment) == 16, "record PB wrong sizeof");
_Static_assert(_Alignof(struct PB_alignment) == 8, "record PB wrong alignment");
_Static_assert(sizeof(struct PB_packed) == 4, "record PB wrong sizeof");
_Static_assert(_Alignof(struct PB_packed) == 1, "record PB wrong alignment");
_Static_assert(sizeof(struct PB_required_alignment) == 5, "record PB wrong sizeof");
_Static_assert(_Alignof(struct PB_required_alignment) == 1, "record PB wrong alignment");
_Static_assert(sizeof(struct PB_size) == 6, "record PB wrong sizeof");
_Static_assert(_Alignof(struct PB_size) == 1, "record PB wrong alignment");
#endif
_Static_assert(sizeof(PC) == 16, "record PC wrong sizeof");
_Static_assert(_Alignof(PC) == 8, "record PC wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct PC_alignment) == 24, "record PC wrong sizeof");
_Static_assert(_Alignof(struct PC_alignment) == 8, "record PC wrong alignment");
_Static_assert(sizeof(struct PC_packed) == 16, "record PC wrong sizeof");
_Static_assert(_Alignof(struct PC_packed) == 1, "record PC wrong alignment");
_Static_assert(sizeof(struct PC_required_alignment) == 17, "record PC wrong sizeof");
_Static_assert(_Alignof(struct PC_required_alignment) == 1, "record PC wrong alignment");
_Static_assert(sizeof(struct PC_size) == 18, "record PC wrong sizeof");
_Static_assert(_Alignof(struct PC_size) == 1, "record PC wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(PC,x) == 64, "field PC.x wrong bit offset");
#endif
_Static_assert(sizeof(PD) == 4, "record PD wrong sizeof");
_Static_assert(_Alignof(PD) == 8, "record PD wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct PD_alignment) == 16, "record PD wrong sizeof");
_Static_assert(_Alignof(struct PD_alignment) == 8, "record PD wrong alignment");
_Static_assert(sizeof(struct PD_packed) == 4, "record PD wrong sizeof");
_Static_assert(_Alignof(struct PD_packed) == 1, "record PD wrong alignment");
_Static_assert(sizeof(struct PD_required_alignment) == 5, "record PD wrong sizeof");
_Static_assert(_Alignof(struct PD_required_alignment) == 1, "record PD wrong alignment");
_Static_assert(sizeof(struct PD_size) == 6, "record PD wrong sizeof");
_Static_assert(_Alignof(struct PD_size) == 1, "record PD wrong alignment");
#endif
_Static_assert(sizeof(PE) == 16, "record PE wrong sizeof");
_Static_assert(_Alignof(PE) == 8, "record PE wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct PE_alignment) == 24, "record PE wrong sizeof");
_Static_assert(_Alignof(struct PE_alignment) == 8, "record PE wrong alignment");
_Static_assert(sizeof(struct PE_packed) == 16, "record PE wrong sizeof");
_Static_assert(_Alignof(struct PE_packed) == 1, "record PE wrong alignment");
_Static_assert(sizeof(struct PE_required_alignment) == 17, "record PE wrong sizeof");
_Static_assert(_Alignof(struct PE_required_alignment) == 1, "record PE wrong alignment");
_Static_assert(sizeof(struct PE_size) == 18, "record PE wrong sizeof");
_Static_assert(_Alignof(struct PE_size) == 1, "record PE wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(PE,x) == 64, "field PE.x wrong bit offset");
#endif
_Static_assert(sizeof(QA) == 4, "record QA wrong sizeof");
_Static_assert(_Alignof(QA) == 4, "record QA wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct QA_alignment) == 8, "record QA wrong sizeof");
_Static_assert(_Alignof(struct QA_alignment) == 4, "record QA wrong alignment");
_Static_assert(sizeof(struct QA_packed) == 4, "record QA wrong sizeof");
_Static_assert(_Alignof(struct QA_packed) == 1, "record QA wrong alignment");
_Static_assert(sizeof(struct QA_required_alignment) == 5, "record QA wrong sizeof");
_Static_assert(_Alignof(struct QA_required_alignment) == 1, "record QA wrong alignment");
_Static_assert(sizeof(struct QA_size) == 6, "record QA wrong sizeof");
_Static_assert(_Alignof(struct QA_size) == 1, "record QA wrong alignment");
#endif
_Static_assert(sizeof(QB) == 6, "record QB wrong sizeof");
_Static_assert(_Alignof(QB) == 2, "record QB wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct QB_alignment) == 8, "record QB wrong sizeof");
_Static_assert(_Alignof(struct QB_alignment) == 2, "record QB wrong alignment");
_Static_assert(sizeof(struct QB_packed) == 6, "record QB wrong sizeof");
_Static_assert(_Alignof(struct QB_packed) == 1, "record QB wrong alignment");
_Static_assert(sizeof(struct QB_required_alignment) == 7, "record QB wrong sizeof");
_Static_assert(_Alignof(struct QB_required_alignment) == 1, "record QB wrong alignment");
_Static_assert(sizeof(struct QB_size) == 8, "record QB wrong sizeof");
_Static_assert(_Alignof(struct QB_size) == 1, "record QB wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(QB,b) == 16, "field QB.b wrong bit offset");
#endif
_Static_assert(sizeof(QC) == 8, "record QC wrong sizeof");
_Static_assert(_Alignof(QC) == 4, "record QC wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct QC_alignment) == 12, "record QC wrong sizeof");
_Static_assert(_Alignof(struct QC_alignment) == 4, "record QC wrong alignment");
_Static_assert(sizeof(struct QC_packed) == 8, "record QC wrong sizeof");
_Static_assert(_Alignof(struct QC_packed) == 1, "record QC wrong alignment");
_Static_assert(sizeof(struct QC_required_alignment) == 9, "record QC wrong sizeof");
_Static_assert(_Alignof(struct QC_required_alignment) == 1, "record QC wrong alignment");
_Static_assert(sizeof(struct QC_size) == 10, "record QC wrong sizeof");
_Static_assert(_Alignof(struct QC_size) == 1, "record QC wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(QC,b) == 32, "field QC.b wrong bit offset");
#endif
_Static_assert(sizeof(QD) == 8, "record QD wrong sizeof");
_Static_assert(_Alignof(QD) == 4, "record QD wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct QD_alignment) == 12, "record QD wrong sizeof");
_Static_assert(_Alignof(struct QD_alignment) == 4, "record QD wrong alignment");
_Static_assert(sizeof(struct QD_packed) == 8, "record QD wrong sizeof");
_Static_assert(_Alignof(struct QD_packed) == 1, "record QD wrong alignment");
_Static_assert(sizeof(struct QD_required_alignment) == 9, "record QD wrong sizeof");
_Static_assert(_Alignof(struct QD_required_alignment) == 1, "record QD wrong alignment");
_Static_assert(sizeof(struct QD_size) == 10, "record QD wrong sizeof");
_Static_assert(_Alignof(struct QD_size) == 1, "record QD wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(QD,b) == 32, "field QD.b wrong bit offset");
#endif
_Static_assert(sizeof(EmptyAlignedLongLongMemb) == 4, "record EmptyAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(EmptyAlignedLongLongMemb) == 8, "record EmptyAlignedLongLongMemb wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_alignment) == 16, "record EmptyAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_alignment) == 8, "record EmptyAlignedLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_packed) == 4, "record EmptyAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_packed) == 1, "record EmptyAlignedLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_required_alignment) == 5, "record EmptyAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_required_alignment) == 1, "record EmptyAlignedLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_size) == 6, "record EmptyAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_size) == 1, "record EmptyAlignedLongLongMemb wrong alignment");
#endif
_Static_assert(sizeof(EmptyPackedAlignedLongLongMemb) == 4, "record EmptyPackedAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(EmptyPackedAlignedLongLongMemb) == 4, "record EmptyPackedAlignedLongLongMemb wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_alignment) == 8, "record EmptyPackedAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_alignment) == 4, "record EmptyPackedAlignedLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_packed) == 4, "record EmptyPackedAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_packed) == 1, "record EmptyPackedAlignedLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_required_alignment) == 5, "record EmptyPackedAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_required_alignment) == 1, "record EmptyPackedAlignedLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_size) == 6, "record EmptyPackedAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_size) == 1, "record EmptyPackedAlignedLongLongMemb wrong alignment");
#endif
#elif defined(I686_PC_WINDOWS_GNU) ||  defined(X8664_PC_WINDOWS_GNU) 
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
_Static_assert(sizeof(X) == 14, "record X wrong sizeof");
_Static_assert(_Alignof(X) == 2, "record X wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct X_alignment) == 16, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_alignment) == 2, "record X wrong alignment");
_Static_assert(sizeof(struct X_packed) == 14, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_packed) == 1, "record X wrong alignment");
_Static_assert(sizeof(struct X_required_alignment) == 15, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_required_alignment) == 1, "record X wrong alignment");
_Static_assert(sizeof(struct X_size) == 16, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_size) == 1, "record X wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(X,b) == 64, "field X.b wrong bit offset");
_Static_assert(__builtin_bitoffsetof(X,c) == 80, "field X.c wrong bit offset");
#endif
_Static_assert(sizeof(YA) == 16, "record YA wrong sizeof");
_Static_assert(_Alignof(YA) == 16, "record YA wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct YA_alignment) == 32, "record YA wrong sizeof");
_Static_assert(_Alignof(struct YA_alignment) == 16, "record YA wrong alignment");
_Static_assert(sizeof(struct YA_packed) == 16, "record YA wrong sizeof");
_Static_assert(_Alignof(struct YA_packed) == 1, "record YA wrong alignment");
_Static_assert(sizeof(struct YA_required_alignment) == 17, "record YA wrong sizeof");
_Static_assert(_Alignof(struct YA_required_alignment) == 1, "record YA wrong alignment");
_Static_assert(sizeof(struct YA_size) == 18, "record YA wrong sizeof");
_Static_assert(_Alignof(struct YA_size) == 1, "record YA wrong alignment");
#endif
_Static_assert(sizeof(YB) == 17, "record YB wrong sizeof");
_Static_assert(_Alignof(YB) == 1, "record YB wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct YB_alignment) == 18, "record YB wrong sizeof");
_Static_assert(_Alignof(struct YB_alignment) == 1, "record YB wrong alignment");
_Static_assert(sizeof(struct YB_packed) == 17, "record YB wrong sizeof");
_Static_assert(_Alignof(struct YB_packed) == 1, "record YB wrong alignment");
_Static_assert(sizeof(struct YB_required_alignment) == 18, "record YB wrong sizeof");
_Static_assert(_Alignof(struct YB_required_alignment) == 1, "record YB wrong alignment");
_Static_assert(sizeof(struct YB_size) == 19, "record YB wrong sizeof");
_Static_assert(_Alignof(struct YB_size) == 1, "record YB wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(YB,b) == 8, "field YB.b wrong bit offset");
#endif
_Static_assert(sizeof(YC) == 8, "record YC wrong sizeof");
_Static_assert(_Alignof(YC) == 8, "record YC wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct YC_alignment) == 16, "record YC wrong sizeof");
_Static_assert(_Alignof(struct YC_alignment) == 8, "record YC wrong alignment");
_Static_assert(sizeof(struct YC_packed) == 8, "record YC wrong sizeof");
_Static_assert(_Alignof(struct YC_packed) == 1, "record YC wrong alignment");
_Static_assert(sizeof(struct YC_required_alignment) == 9, "record YC wrong sizeof");
_Static_assert(_Alignof(struct YC_required_alignment) == 1, "record YC wrong alignment");
_Static_assert(sizeof(struct YC_size) == 10, "record YC wrong sizeof");
_Static_assert(_Alignof(struct YC_size) == 1, "record YC wrong alignment");
#endif
_Static_assert(sizeof(YD) == 9, "record YD wrong sizeof");
_Static_assert(_Alignof(YD) == 1, "record YD wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct YD_alignment) == 10, "record YD wrong sizeof");
_Static_assert(_Alignof(struct YD_alignment) == 1, "record YD wrong alignment");
_Static_assert(sizeof(struct YD_packed) == 9, "record YD wrong sizeof");
_Static_assert(_Alignof(struct YD_packed) == 1, "record YD wrong alignment");
_Static_assert(sizeof(struct YD_required_alignment) == 10, "record YD wrong sizeof");
_Static_assert(_Alignof(struct YD_required_alignment) == 1, "record YD wrong alignment");
_Static_assert(sizeof(struct YD_size) == 11, "record YD wrong sizeof");
_Static_assert(_Alignof(struct YD_size) == 1, "record YD wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(YD,b) == 8, "field YD.b wrong bit offset");
#endif
_Static_assert(sizeof(YE) == 4, "record YE wrong sizeof");
_Static_assert(_Alignof(YE) == 4, "record YE wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct YE_alignment) == 8, "record YE wrong sizeof");
_Static_assert(_Alignof(struct YE_alignment) == 4, "record YE wrong alignment");
_Static_assert(sizeof(struct YE_packed) == 4, "record YE wrong sizeof");
_Static_assert(_Alignof(struct YE_packed) == 1, "record YE wrong alignment");
_Static_assert(sizeof(struct YE_required_alignment) == 5, "record YE wrong sizeof");
_Static_assert(_Alignof(struct YE_required_alignment) == 1, "record YE wrong alignment");
_Static_assert(sizeof(struct YE_size) == 6, "record YE wrong sizeof");
_Static_assert(_Alignof(struct YE_size) == 1, "record YE wrong alignment");
#endif
_Static_assert(sizeof(YF) == 5, "record YF wrong sizeof");
_Static_assert(_Alignof(YF) == 1, "record YF wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct YF_alignment) == 6, "record YF wrong sizeof");
_Static_assert(_Alignof(struct YF_alignment) == 1, "record YF wrong alignment");
_Static_assert(sizeof(struct YF_packed) == 5, "record YF wrong sizeof");
_Static_assert(_Alignof(struct YF_packed) == 1, "record YF wrong alignment");
_Static_assert(sizeof(struct YF_required_alignment) == 6, "record YF wrong sizeof");
_Static_assert(_Alignof(struct YF_required_alignment) == 1, "record YF wrong alignment");
_Static_assert(sizeof(struct YF_size) == 7, "record YF wrong sizeof");
_Static_assert(_Alignof(struct YF_size) == 1, "record YF wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(YF,b) == 8, "field YF.b wrong bit offset");
#endif
_Static_assert(sizeof(D0) == 16, "record D0 wrong sizeof");
_Static_assert(_Alignof(D0) == 16, "record D0 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D0_alignment) == 32, "record D0 wrong sizeof");
_Static_assert(_Alignof(struct D0_alignment) == 16, "record D0 wrong alignment");
_Static_assert(sizeof(struct D0_packed) == 16, "record D0 wrong sizeof");
_Static_assert(_Alignof(struct D0_packed) == 1, "record D0 wrong alignment");
_Static_assert(sizeof(struct D0_required_alignment) == 17, "record D0 wrong sizeof");
_Static_assert(_Alignof(struct D0_required_alignment) == 1, "record D0 wrong alignment");
_Static_assert(sizeof(struct D0_size) == 18, "record D0 wrong sizeof");
_Static_assert(_Alignof(struct D0_size) == 1, "record D0 wrong alignment");
#endif
_Static_assert(sizeof(RB0) == 8, "record RB0 wrong sizeof");
_Static_assert(_Alignof(RB0) == 8, "record RB0 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct RB0_alignment) == 16, "record RB0 wrong sizeof");
_Static_assert(_Alignof(struct RB0_alignment) == 8, "record RB0 wrong alignment");
_Static_assert(sizeof(struct RB0_packed) == 8, "record RB0 wrong sizeof");
_Static_assert(_Alignof(struct RB0_packed) == 1, "record RB0 wrong alignment");
_Static_assert(sizeof(struct RB0_required_alignment) == 9, "record RB0 wrong sizeof");
_Static_assert(_Alignof(struct RB0_required_alignment) == 1, "record RB0 wrong alignment");
_Static_assert(sizeof(struct RB0_size) == 10, "record RB0 wrong sizeof");
_Static_assert(_Alignof(struct RB0_size) == 1, "record RB0 wrong alignment");
#endif
_Static_assert(sizeof(RC) == 5, "record RC wrong sizeof");
_Static_assert(_Alignof(RC) == 1, "record RC wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct RC_alignment) == 6, "record RC wrong sizeof");
_Static_assert(_Alignof(struct RC_alignment) == 1, "record RC wrong alignment");
_Static_assert(sizeof(struct RC_packed) == 5, "record RC wrong sizeof");
_Static_assert(_Alignof(struct RC_packed) == 1, "record RC wrong alignment");
_Static_assert(sizeof(struct RC_required_alignment) == 6, "record RC wrong sizeof");
_Static_assert(_Alignof(struct RC_required_alignment) == 1, "record RC wrong alignment");
_Static_assert(sizeof(struct RC_size) == 7, "record RC wrong sizeof");
_Static_assert(_Alignof(struct RC_size) == 1, "record RC wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(RC,c) == 8, "field RC.c wrong bit offset");
#endif
_Static_assert(sizeof(RE) == 6, "record RE wrong sizeof");
_Static_assert(_Alignof(RE) == 1, "record RE wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct RE_alignment) == 7, "record RE wrong sizeof");
_Static_assert(_Alignof(struct RE_alignment) == 1, "record RE wrong alignment");
_Static_assert(sizeof(struct RE_packed) == 6, "record RE wrong sizeof");
_Static_assert(_Alignof(struct RE_packed) == 1, "record RE wrong alignment");
_Static_assert(sizeof(struct RE_required_alignment) == 7, "record RE wrong sizeof");
_Static_assert(_Alignof(struct RE_required_alignment) == 1, "record RE wrong alignment");
_Static_assert(sizeof(struct RE_size) == 8, "record RE wrong sizeof");
_Static_assert(_Alignof(struct RE_size) == 1, "record RE wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(RE,c) == 8, "field RE.c wrong bit offset");
#endif
_Static_assert(sizeof(PA) == 4, "record PA wrong sizeof");
_Static_assert(_Alignof(PA) == 4, "record PA wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct PA_alignment) == 8, "record PA wrong sizeof");
_Static_assert(_Alignof(struct PA_alignment) == 4, "record PA wrong alignment");
_Static_assert(sizeof(struct PA_packed) == 4, "record PA wrong sizeof");
_Static_assert(_Alignof(struct PA_packed) == 1, "record PA wrong alignment");
_Static_assert(sizeof(struct PA_required_alignment) == 5, "record PA wrong sizeof");
_Static_assert(_Alignof(struct PA_required_alignment) == 1, "record PA wrong alignment");
_Static_assert(sizeof(struct PA_size) == 6, "record PA wrong sizeof");
_Static_assert(_Alignof(struct PA_size) == 1, "record PA wrong alignment");
#endif
_Static_assert(sizeof(PB) == 4, "record PB wrong sizeof");
_Static_assert(_Alignof(PB) == 8, "record PB wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct PB_alignment) == 16, "record PB wrong sizeof");
_Static_assert(_Alignof(struct PB_alignment) == 8, "record PB wrong alignment");
_Static_assert(sizeof(struct PB_packed) == 4, "record PB wrong sizeof");
_Static_assert(_Alignof(struct PB_packed) == 1, "record PB wrong alignment");
_Static_assert(sizeof(struct PB_required_alignment) == 5, "record PB wrong sizeof");
_Static_assert(_Alignof(struct PB_required_alignment) == 1, "record PB wrong alignment");
_Static_assert(sizeof(struct PB_size) == 6, "record PB wrong sizeof");
_Static_assert(_Alignof(struct PB_size) == 1, "record PB wrong alignment");
#endif
_Static_assert(sizeof(PC) == 5, "record PC wrong sizeof");
_Static_assert(_Alignof(PC) == 1, "record PC wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct PC_alignment) == 6, "record PC wrong sizeof");
_Static_assert(_Alignof(struct PC_alignment) == 1, "record PC wrong alignment");
_Static_assert(sizeof(struct PC_packed) == 5, "record PC wrong sizeof");
_Static_assert(_Alignof(struct PC_packed) == 1, "record PC wrong alignment");
_Static_assert(sizeof(struct PC_required_alignment) == 6, "record PC wrong sizeof");
_Static_assert(_Alignof(struct PC_required_alignment) == 1, "record PC wrong alignment");
_Static_assert(sizeof(struct PC_size) == 7, "record PC wrong sizeof");
_Static_assert(_Alignof(struct PC_size) == 1, "record PC wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(PC,x) == 8, "field PC.x wrong bit offset");
#endif
_Static_assert(sizeof(PD) == 4, "record PD wrong sizeof");
_Static_assert(_Alignof(PD) == 8, "record PD wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct PD_alignment) == 16, "record PD wrong sizeof");
_Static_assert(_Alignof(struct PD_alignment) == 8, "record PD wrong alignment");
_Static_assert(sizeof(struct PD_packed) == 4, "record PD wrong sizeof");
_Static_assert(_Alignof(struct PD_packed) == 1, "record PD wrong alignment");
_Static_assert(sizeof(struct PD_required_alignment) == 5, "record PD wrong sizeof");
_Static_assert(_Alignof(struct PD_required_alignment) == 1, "record PD wrong alignment");
_Static_assert(sizeof(struct PD_size) == 6, "record PD wrong sizeof");
_Static_assert(_Alignof(struct PD_size) == 1, "record PD wrong alignment");
#endif
_Static_assert(sizeof(PE) == 5, "record PE wrong sizeof");
_Static_assert(_Alignof(PE) == 1, "record PE wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct PE_alignment) == 6, "record PE wrong sizeof");
_Static_assert(_Alignof(struct PE_alignment) == 1, "record PE wrong alignment");
_Static_assert(sizeof(struct PE_packed) == 5, "record PE wrong sizeof");
_Static_assert(_Alignof(struct PE_packed) == 1, "record PE wrong alignment");
_Static_assert(sizeof(struct PE_required_alignment) == 6, "record PE wrong sizeof");
_Static_assert(_Alignof(struct PE_required_alignment) == 1, "record PE wrong alignment");
_Static_assert(sizeof(struct PE_size) == 7, "record PE wrong sizeof");
_Static_assert(_Alignof(struct PE_size) == 1, "record PE wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(PE,x) == 8, "field PE.x wrong bit offset");
#endif
_Static_assert(sizeof(QA) == 4, "record QA wrong sizeof");
_Static_assert(_Alignof(QA) == 2, "record QA wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct QA_alignment) == 6, "record QA wrong sizeof");
_Static_assert(_Alignof(struct QA_alignment) == 2, "record QA wrong alignment");
_Static_assert(sizeof(struct QA_packed) == 4, "record QA wrong sizeof");
_Static_assert(_Alignof(struct QA_packed) == 1, "record QA wrong alignment");
_Static_assert(sizeof(struct QA_required_alignment) == 5, "record QA wrong sizeof");
_Static_assert(_Alignof(struct QA_required_alignment) == 1, "record QA wrong alignment");
_Static_assert(sizeof(struct QA_size) == 6, "record QA wrong sizeof");
_Static_assert(_Alignof(struct QA_size) == 1, "record QA wrong alignment");
#endif
_Static_assert(sizeof(QB) == 5, "record QB wrong sizeof");
_Static_assert(_Alignof(QB) == 1, "record QB wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct QB_alignment) == 6, "record QB wrong sizeof");
_Static_assert(_Alignof(struct QB_alignment) == 1, "record QB wrong alignment");
_Static_assert(sizeof(struct QB_packed) == 5, "record QB wrong sizeof");
_Static_assert(_Alignof(struct QB_packed) == 1, "record QB wrong alignment");
_Static_assert(sizeof(struct QB_required_alignment) == 6, "record QB wrong sizeof");
_Static_assert(_Alignof(struct QB_required_alignment) == 1, "record QB wrong alignment");
_Static_assert(sizeof(struct QB_size) == 7, "record QB wrong sizeof");
_Static_assert(_Alignof(struct QB_size) == 1, "record QB wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(QB,b) == 8, "field QB.b wrong bit offset");
#endif
_Static_assert(sizeof(QC) == 6, "record QC wrong sizeof");
_Static_assert(_Alignof(QC) == 2, "record QC wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct QC_alignment) == 8, "record QC wrong sizeof");
_Static_assert(_Alignof(struct QC_alignment) == 2, "record QC wrong alignment");
_Static_assert(sizeof(struct QC_packed) == 6, "record QC wrong sizeof");
_Static_assert(_Alignof(struct QC_packed) == 1, "record QC wrong alignment");
_Static_assert(sizeof(struct QC_required_alignment) == 7, "record QC wrong sizeof");
_Static_assert(_Alignof(struct QC_required_alignment) == 1, "record QC wrong alignment");
_Static_assert(sizeof(struct QC_size) == 8, "record QC wrong sizeof");
_Static_assert(_Alignof(struct QC_size) == 1, "record QC wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(QC,b) == 16, "field QC.b wrong bit offset");
#endif
_Static_assert(sizeof(QD) == 6, "record QD wrong sizeof");
_Static_assert(_Alignof(QD) == 2, "record QD wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct QD_alignment) == 8, "record QD wrong sizeof");
_Static_assert(_Alignof(struct QD_alignment) == 2, "record QD wrong alignment");
_Static_assert(sizeof(struct QD_packed) == 6, "record QD wrong sizeof");
_Static_assert(_Alignof(struct QD_packed) == 1, "record QD wrong alignment");
_Static_assert(sizeof(struct QD_required_alignment) == 7, "record QD wrong sizeof");
_Static_assert(_Alignof(struct QD_required_alignment) == 1, "record QD wrong alignment");
_Static_assert(sizeof(struct QD_size) == 8, "record QD wrong sizeof");
_Static_assert(_Alignof(struct QD_size) == 1, "record QD wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(QD,b) == 16, "field QD.b wrong bit offset");
#endif
_Static_assert(sizeof(EmptyAlignedLongLongMemb) == 0, "record EmptyAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(EmptyAlignedLongLongMemb) == 8, "record EmptyAlignedLongLongMemb wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_alignment) == 8, "record EmptyAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_alignment) == 8, "record EmptyAlignedLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_packed) == 0, "record EmptyAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_packed) == 1, "record EmptyAlignedLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_required_alignment) == 1, "record EmptyAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_required_alignment) == 1, "record EmptyAlignedLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_size) == 2, "record EmptyAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_size) == 1, "record EmptyAlignedLongLongMemb wrong alignment");
#endif
_Static_assert(sizeof(EmptyPackedAlignedLongLongMemb) == 0, "record EmptyPackedAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(EmptyPackedAlignedLongLongMemb) == 4, "record EmptyPackedAlignedLongLongMemb wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_alignment) == 4, "record EmptyPackedAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_alignment) == 4, "record EmptyPackedAlignedLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_packed) == 0, "record EmptyPackedAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_packed) == 1, "record EmptyPackedAlignedLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_required_alignment) == 1, "record EmptyPackedAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_required_alignment) == 1, "record EmptyPackedAlignedLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_size) == 2, "record EmptyPackedAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_size) == 1, "record EmptyPackedAlignedLongLongMemb wrong alignment");
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
_Static_assert(sizeof(B) == 8, "record B wrong sizeof");
_Static_assert(_Alignof(B) == 4, "record B wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 12, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_alignment) == 4, "record B wrong alignment");
_Static_assert(sizeof(struct B_packed) == 8, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_packed) == 1, "record B wrong alignment");
_Static_assert(sizeof(struct B_required_alignment) == 9, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "record B wrong alignment");
_Static_assert(sizeof(struct B_size) == 10, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_size) == 1, "record B wrong alignment");
#endif
_Static_assert(sizeof(X) == 12, "record X wrong sizeof");
_Static_assert(_Alignof(X) == 2, "record X wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct X_alignment) == 14, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_alignment) == 2, "record X wrong alignment");
_Static_assert(sizeof(struct X_packed) == 12, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_packed) == 1, "record X wrong alignment");
_Static_assert(sizeof(struct X_required_alignment) == 13, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_required_alignment) == 1, "record X wrong alignment");
_Static_assert(sizeof(struct X_size) == 14, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_size) == 1, "record X wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(X,b) == 64, "field X.b wrong bit offset");
_Static_assert(__builtin_bitoffsetof(X,c) == 80, "field X.c wrong bit offset");
#endif
_Static_assert(sizeof(YA) == 1, "record YA wrong sizeof");
_Static_assert(_Alignof(YA) == 1, "record YA wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct YA_alignment) == 2, "record YA wrong sizeof");
_Static_assert(_Alignof(struct YA_alignment) == 1, "record YA wrong alignment");
_Static_assert(sizeof(struct YA_packed) == 1, "record YA wrong sizeof");
_Static_assert(_Alignof(struct YA_packed) == 1, "record YA wrong alignment");
_Static_assert(sizeof(struct YA_required_alignment) == 2, "record YA wrong sizeof");
_Static_assert(_Alignof(struct YA_required_alignment) == 1, "record YA wrong alignment");
_Static_assert(sizeof(struct YA_size) == 3, "record YA wrong sizeof");
_Static_assert(_Alignof(struct YA_size) == 1, "record YA wrong alignment");
#endif
_Static_assert(sizeof(YB) == 2, "record YB wrong sizeof");
_Static_assert(_Alignof(YB) == 1, "record YB wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct YB_alignment) == 3, "record YB wrong sizeof");
_Static_assert(_Alignof(struct YB_alignment) == 1, "record YB wrong alignment");
_Static_assert(sizeof(struct YB_packed) == 2, "record YB wrong sizeof");
_Static_assert(_Alignof(struct YB_packed) == 1, "record YB wrong alignment");
_Static_assert(sizeof(struct YB_required_alignment) == 3, "record YB wrong sizeof");
_Static_assert(_Alignof(struct YB_required_alignment) == 1, "record YB wrong alignment");
_Static_assert(sizeof(struct YB_size) == 4, "record YB wrong sizeof");
_Static_assert(_Alignof(struct YB_size) == 1, "record YB wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(YB,b) == 8, "field YB.b wrong bit offset");
#endif
_Static_assert(sizeof(YC) == 1, "record YC wrong sizeof");
_Static_assert(_Alignof(YC) == 1, "record YC wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct YC_alignment) == 2, "record YC wrong sizeof");
_Static_assert(_Alignof(struct YC_alignment) == 1, "record YC wrong alignment");
_Static_assert(sizeof(struct YC_packed) == 1, "record YC wrong sizeof");
_Static_assert(_Alignof(struct YC_packed) == 1, "record YC wrong alignment");
_Static_assert(sizeof(struct YC_required_alignment) == 2, "record YC wrong sizeof");
_Static_assert(_Alignof(struct YC_required_alignment) == 1, "record YC wrong alignment");
_Static_assert(sizeof(struct YC_size) == 3, "record YC wrong sizeof");
_Static_assert(_Alignof(struct YC_size) == 1, "record YC wrong alignment");
#endif
_Static_assert(sizeof(YD) == 2, "record YD wrong sizeof");
_Static_assert(_Alignof(YD) == 1, "record YD wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct YD_alignment) == 3, "record YD wrong sizeof");
_Static_assert(_Alignof(struct YD_alignment) == 1, "record YD wrong alignment");
_Static_assert(sizeof(struct YD_packed) == 2, "record YD wrong sizeof");
_Static_assert(_Alignof(struct YD_packed) == 1, "record YD wrong alignment");
_Static_assert(sizeof(struct YD_required_alignment) == 3, "record YD wrong sizeof");
_Static_assert(_Alignof(struct YD_required_alignment) == 1, "record YD wrong alignment");
_Static_assert(sizeof(struct YD_size) == 4, "record YD wrong sizeof");
_Static_assert(_Alignof(struct YD_size) == 1, "record YD wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(YD,b) == 8, "field YD.b wrong bit offset");
#endif
_Static_assert(sizeof(YE) == 1, "record YE wrong sizeof");
_Static_assert(_Alignof(YE) == 1, "record YE wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct YE_alignment) == 2, "record YE wrong sizeof");
_Static_assert(_Alignof(struct YE_alignment) == 1, "record YE wrong alignment");
_Static_assert(sizeof(struct YE_packed) == 1, "record YE wrong sizeof");
_Static_assert(_Alignof(struct YE_packed) == 1, "record YE wrong alignment");
_Static_assert(sizeof(struct YE_required_alignment) == 2, "record YE wrong sizeof");
_Static_assert(_Alignof(struct YE_required_alignment) == 1, "record YE wrong alignment");
_Static_assert(sizeof(struct YE_size) == 3, "record YE wrong sizeof");
_Static_assert(_Alignof(struct YE_size) == 1, "record YE wrong alignment");
#endif
_Static_assert(sizeof(YF) == 2, "record YF wrong sizeof");
_Static_assert(_Alignof(YF) == 1, "record YF wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct YF_alignment) == 3, "record YF wrong sizeof");
_Static_assert(_Alignof(struct YF_alignment) == 1, "record YF wrong alignment");
_Static_assert(sizeof(struct YF_packed) == 2, "record YF wrong sizeof");
_Static_assert(_Alignof(struct YF_packed) == 1, "record YF wrong alignment");
_Static_assert(sizeof(struct YF_required_alignment) == 3, "record YF wrong sizeof");
_Static_assert(_Alignof(struct YF_required_alignment) == 1, "record YF wrong alignment");
_Static_assert(sizeof(struct YF_size) == 4, "record YF wrong sizeof");
_Static_assert(_Alignof(struct YF_size) == 1, "record YF wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(YF,b) == 8, "field YF.b wrong bit offset");
#endif
_Static_assert(sizeof(D0) == 16, "record D0 wrong sizeof");
_Static_assert(_Alignof(D0) == 16, "record D0 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D0_alignment) == 32, "record D0 wrong sizeof");
_Static_assert(_Alignof(struct D0_alignment) == 16, "record D0 wrong alignment");
_Static_assert(sizeof(struct D0_packed) == 16, "record D0 wrong sizeof");
_Static_assert(_Alignof(struct D0_packed) == 1, "record D0 wrong alignment");
_Static_assert(sizeof(struct D0_required_alignment) == 17, "record D0 wrong sizeof");
_Static_assert(_Alignof(struct D0_required_alignment) == 1, "record D0 wrong alignment");
_Static_assert(sizeof(struct D0_size) == 18, "record D0 wrong sizeof");
_Static_assert(_Alignof(struct D0_size) == 1, "record D0 wrong alignment");
#endif
_Static_assert(sizeof(RB0) == 8, "record RB0 wrong sizeof");
_Static_assert(_Alignof(RB0) == 8, "record RB0 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct RB0_alignment) == 16, "record RB0 wrong sizeof");
_Static_assert(_Alignof(struct RB0_alignment) == 8, "record RB0 wrong alignment");
_Static_assert(sizeof(struct RB0_packed) == 8, "record RB0 wrong sizeof");
_Static_assert(_Alignof(struct RB0_packed) == 1, "record RB0 wrong alignment");
_Static_assert(sizeof(struct RB0_required_alignment) == 9, "record RB0 wrong sizeof");
_Static_assert(_Alignof(struct RB0_required_alignment) == 1, "record RB0 wrong alignment");
_Static_assert(sizeof(struct RB0_size) == 10, "record RB0 wrong sizeof");
_Static_assert(_Alignof(struct RB0_size) == 1, "record RB0 wrong alignment");
#endif
_Static_assert(sizeof(RC) == 2, "record RC wrong sizeof");
_Static_assert(_Alignof(RC) == 1, "record RC wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct RC_alignment) == 3, "record RC wrong sizeof");
_Static_assert(_Alignof(struct RC_alignment) == 1, "record RC wrong alignment");
_Static_assert(sizeof(struct RC_packed) == 2, "record RC wrong sizeof");
_Static_assert(_Alignof(struct RC_packed) == 1, "record RC wrong alignment");
_Static_assert(sizeof(struct RC_required_alignment) == 3, "record RC wrong sizeof");
_Static_assert(_Alignof(struct RC_required_alignment) == 1, "record RC wrong alignment");
_Static_assert(sizeof(struct RC_size) == 4, "record RC wrong sizeof");
_Static_assert(_Alignof(struct RC_size) == 1, "record RC wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(RC,c) == 8, "field RC.c wrong bit offset");
#endif
_Static_assert(sizeof(RE) == 3, "record RE wrong sizeof");
_Static_assert(_Alignof(RE) == 1, "record RE wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct RE_alignment) == 4, "record RE wrong sizeof");
_Static_assert(_Alignof(struct RE_alignment) == 1, "record RE wrong alignment");
_Static_assert(sizeof(struct RE_packed) == 3, "record RE wrong sizeof");
_Static_assert(_Alignof(struct RE_packed) == 1, "record RE wrong alignment");
_Static_assert(sizeof(struct RE_required_alignment) == 4, "record RE wrong sizeof");
_Static_assert(_Alignof(struct RE_required_alignment) == 1, "record RE wrong alignment");
_Static_assert(sizeof(struct RE_size) == 5, "record RE wrong sizeof");
_Static_assert(_Alignof(struct RE_size) == 1, "record RE wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(RE,c) == 8, "field RE.c wrong bit offset");
#endif
_Static_assert(sizeof(PA) == 4, "record PA wrong sizeof");
_Static_assert(_Alignof(PA) == 4, "record PA wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct PA_alignment) == 8, "record PA wrong sizeof");
_Static_assert(_Alignof(struct PA_alignment) == 4, "record PA wrong alignment");
_Static_assert(sizeof(struct PA_packed) == 4, "record PA wrong sizeof");
_Static_assert(_Alignof(struct PA_packed) == 1, "record PA wrong alignment");
_Static_assert(sizeof(struct PA_required_alignment) == 5, "record PA wrong sizeof");
_Static_assert(_Alignof(struct PA_required_alignment) == 1, "record PA wrong alignment");
_Static_assert(sizeof(struct PA_size) == 6, "record PA wrong sizeof");
_Static_assert(_Alignof(struct PA_size) == 1, "record PA wrong alignment");
#endif
_Static_assert(sizeof(PB) == 4, "record PB wrong sizeof");
_Static_assert(_Alignof(PB) == 8, "record PB wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct PB_alignment) == 16, "record PB wrong sizeof");
_Static_assert(_Alignof(struct PB_alignment) == 8, "record PB wrong alignment");
_Static_assert(sizeof(struct PB_packed) == 4, "record PB wrong sizeof");
_Static_assert(_Alignof(struct PB_packed) == 1, "record PB wrong alignment");
_Static_assert(sizeof(struct PB_required_alignment) == 5, "record PB wrong sizeof");
_Static_assert(_Alignof(struct PB_required_alignment) == 1, "record PB wrong alignment");
_Static_assert(sizeof(struct PB_size) == 6, "record PB wrong sizeof");
_Static_assert(_Alignof(struct PB_size) == 1, "record PB wrong alignment");
#endif
_Static_assert(sizeof(PC) == 5, "record PC wrong sizeof");
_Static_assert(_Alignof(PC) == 1, "record PC wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct PC_alignment) == 6, "record PC wrong sizeof");
_Static_assert(_Alignof(struct PC_alignment) == 1, "record PC wrong alignment");
_Static_assert(sizeof(struct PC_packed) == 5, "record PC wrong sizeof");
_Static_assert(_Alignof(struct PC_packed) == 1, "record PC wrong alignment");
_Static_assert(sizeof(struct PC_required_alignment) == 6, "record PC wrong sizeof");
_Static_assert(_Alignof(struct PC_required_alignment) == 1, "record PC wrong alignment");
_Static_assert(sizeof(struct PC_size) == 7, "record PC wrong sizeof");
_Static_assert(_Alignof(struct PC_size) == 1, "record PC wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(PC,x) == 8, "field PC.x wrong bit offset");
#endif
_Static_assert(sizeof(PD) == 4, "record PD wrong sizeof");
_Static_assert(_Alignof(PD) == 8, "record PD wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct PD_alignment) == 16, "record PD wrong sizeof");
_Static_assert(_Alignof(struct PD_alignment) == 8, "record PD wrong alignment");
_Static_assert(sizeof(struct PD_packed) == 4, "record PD wrong sizeof");
_Static_assert(_Alignof(struct PD_packed) == 1, "record PD wrong alignment");
_Static_assert(sizeof(struct PD_required_alignment) == 5, "record PD wrong sizeof");
_Static_assert(_Alignof(struct PD_required_alignment) == 1, "record PD wrong alignment");
_Static_assert(sizeof(struct PD_size) == 6, "record PD wrong sizeof");
_Static_assert(_Alignof(struct PD_size) == 1, "record PD wrong alignment");
#endif
_Static_assert(sizeof(PE) == 5, "record PE wrong sizeof");
_Static_assert(_Alignof(PE) == 1, "record PE wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct PE_alignment) == 6, "record PE wrong sizeof");
_Static_assert(_Alignof(struct PE_alignment) == 1, "record PE wrong alignment");
_Static_assert(sizeof(struct PE_packed) == 5, "record PE wrong sizeof");
_Static_assert(_Alignof(struct PE_packed) == 1, "record PE wrong alignment");
_Static_assert(sizeof(struct PE_required_alignment) == 6, "record PE wrong sizeof");
_Static_assert(_Alignof(struct PE_required_alignment) == 1, "record PE wrong alignment");
_Static_assert(sizeof(struct PE_size) == 7, "record PE wrong sizeof");
_Static_assert(_Alignof(struct PE_size) == 1, "record PE wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(PE,x) == 8, "field PE.x wrong bit offset");
#endif
_Static_assert(sizeof(QA) == 2, "record QA wrong sizeof");
_Static_assert(_Alignof(QA) == 2, "record QA wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct QA_alignment) == 4, "record QA wrong sizeof");
_Static_assert(_Alignof(struct QA_alignment) == 2, "record QA wrong alignment");
_Static_assert(sizeof(struct QA_packed) == 2, "record QA wrong sizeof");
_Static_assert(_Alignof(struct QA_packed) == 1, "record QA wrong alignment");
_Static_assert(sizeof(struct QA_required_alignment) == 3, "record QA wrong sizeof");
_Static_assert(_Alignof(struct QA_required_alignment) == 1, "record QA wrong alignment");
_Static_assert(sizeof(struct QA_size) == 4, "record QA wrong sizeof");
_Static_assert(_Alignof(struct QA_size) == 1, "record QA wrong alignment");
#endif
_Static_assert(sizeof(QB) == 3, "record QB wrong sizeof");
_Static_assert(_Alignof(QB) == 1, "record QB wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct QB_alignment) == 4, "record QB wrong sizeof");
_Static_assert(_Alignof(struct QB_alignment) == 1, "record QB wrong alignment");
_Static_assert(sizeof(struct QB_packed) == 3, "record QB wrong sizeof");
_Static_assert(_Alignof(struct QB_packed) == 1, "record QB wrong alignment");
_Static_assert(sizeof(struct QB_required_alignment) == 4, "record QB wrong sizeof");
_Static_assert(_Alignof(struct QB_required_alignment) == 1, "record QB wrong alignment");
_Static_assert(sizeof(struct QB_size) == 5, "record QB wrong sizeof");
_Static_assert(_Alignof(struct QB_size) == 1, "record QB wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(QB,b) == 8, "field QB.b wrong bit offset");
#endif
_Static_assert(sizeof(QC) == 4, "record QC wrong sizeof");
_Static_assert(_Alignof(QC) == 2, "record QC wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct QC_alignment) == 6, "record QC wrong sizeof");
_Static_assert(_Alignof(struct QC_alignment) == 2, "record QC wrong alignment");
_Static_assert(sizeof(struct QC_packed) == 4, "record QC wrong sizeof");
_Static_assert(_Alignof(struct QC_packed) == 1, "record QC wrong alignment");
_Static_assert(sizeof(struct QC_required_alignment) == 5, "record QC wrong sizeof");
_Static_assert(_Alignof(struct QC_required_alignment) == 1, "record QC wrong alignment");
_Static_assert(sizeof(struct QC_size) == 6, "record QC wrong sizeof");
_Static_assert(_Alignof(struct QC_size) == 1, "record QC wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(QC,b) == 16, "field QC.b wrong bit offset");
#endif
_Static_assert(sizeof(QD) == 2, "record QD wrong sizeof");
_Static_assert(_Alignof(QD) == 2, "record QD wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct QD_alignment) == 4, "record QD wrong sizeof");
_Static_assert(_Alignof(struct QD_alignment) == 2, "record QD wrong alignment");
_Static_assert(sizeof(struct QD_packed) == 2, "record QD wrong sizeof");
_Static_assert(_Alignof(struct QD_packed) == 1, "record QD wrong alignment");
_Static_assert(sizeof(struct QD_required_alignment) == 3, "record QD wrong sizeof");
_Static_assert(_Alignof(struct QD_required_alignment) == 1, "record QD wrong alignment");
_Static_assert(sizeof(struct QD_size) == 4, "record QD wrong sizeof");
_Static_assert(_Alignof(struct QD_size) == 1, "record QD wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(QD,b) == 8, "field QD.b wrong bit offset");
#endif
_Static_assert(sizeof(EmptyAlignedLongLongMemb) == 0, "record EmptyAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(EmptyAlignedLongLongMemb) == 4, "record EmptyAlignedLongLongMemb wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_alignment) == 4, "record EmptyAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_alignment) == 4, "record EmptyAlignedLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_packed) == 0, "record EmptyAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_packed) == 1, "record EmptyAlignedLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_required_alignment) == 1, "record EmptyAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_required_alignment) == 1, "record EmptyAlignedLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_size) == 2, "record EmptyAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_size) == 1, "record EmptyAlignedLongLongMemb wrong alignment");
#endif
_Static_assert(sizeof(EmptyPackedAlignedLongLongMemb) == 0, "record EmptyPackedAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(EmptyPackedAlignedLongLongMemb) == 4, "record EmptyPackedAlignedLongLongMemb wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_alignment) == 4, "record EmptyPackedAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_alignment) == 4, "record EmptyPackedAlignedLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_packed) == 0, "record EmptyPackedAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_packed) == 1, "record EmptyPackedAlignedLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_required_alignment) == 1, "record EmptyPackedAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_required_alignment) == 1, "record EmptyPackedAlignedLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_size) == 2, "record EmptyPackedAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_size) == 1, "record EmptyPackedAlignedLongLongMemb wrong alignment");
#endif
#elif defined(THUMBV7A_PC_WINDOWS_MSVC) 
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
_Static_assert(sizeof(X) == 16, "record X wrong sizeof");
_Static_assert(_Alignof(X) == 4, "record X wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct X_alignment) == 20, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_alignment) == 4, "record X wrong alignment");
_Static_assert(sizeof(struct X_packed) == 16, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_packed) == 1, "record X wrong alignment");
_Static_assert(sizeof(struct X_required_alignment) == 17, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_required_alignment) == 1, "record X wrong alignment");
_Static_assert(sizeof(struct X_size) == 18, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_size) == 1, "record X wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(X,b) == 64, "field X.b wrong bit offset");
_Static_assert(__builtin_bitoffsetof(X,c) == 80, "field X.c wrong bit offset");
#endif
_Static_assert(sizeof(YA) == 16, "record YA wrong sizeof");
_Static_assert(_Alignof(YA) == 32, "record YA wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct YA_alignment) == 64, "record YA wrong sizeof");
_Static_assert(_Alignof(struct YA_alignment) == 32, "record YA wrong alignment");
_Static_assert(sizeof(struct YA_packed) == 16, "record YA wrong sizeof");
_Static_assert(_Alignof(struct YA_packed) == 1, "record YA wrong alignment");
_Static_assert(sizeof(struct YA_required_alignment) == 17, "record YA wrong sizeof");
_Static_assert(_Alignof(struct YA_required_alignment) == 1, "record YA wrong alignment");
_Static_assert(sizeof(struct YA_size) == 18, "record YA wrong sizeof");
_Static_assert(_Alignof(struct YA_size) == 1, "record YA wrong alignment");
#endif
_Static_assert(sizeof(YB) == 17, "record YB wrong sizeof");
_Static_assert(_Alignof(YB) == 1, "record YB wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct YB_alignment) == 18, "record YB wrong sizeof");
_Static_assert(_Alignof(struct YB_alignment) == 1, "record YB wrong alignment");
_Static_assert(sizeof(struct YB_packed) == 17, "record YB wrong sizeof");
_Static_assert(_Alignof(struct YB_packed) == 1, "record YB wrong alignment");
_Static_assert(sizeof(struct YB_required_alignment) == 18, "record YB wrong sizeof");
_Static_assert(_Alignof(struct YB_required_alignment) == 1, "record YB wrong alignment");
_Static_assert(sizeof(struct YB_size) == 19, "record YB wrong sizeof");
_Static_assert(_Alignof(struct YB_size) == 1, "record YB wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(YB,b) == 8, "field YB.b wrong bit offset");
#endif
_Static_assert(sizeof(YC) == 8, "record YC wrong sizeof");
_Static_assert(_Alignof(YC) == 32, "record YC wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct YC_alignment) == 64, "record YC wrong sizeof");
_Static_assert(_Alignof(struct YC_alignment) == 32, "record YC wrong alignment");
_Static_assert(sizeof(struct YC_packed) == 8, "record YC wrong sizeof");
_Static_assert(_Alignof(struct YC_packed) == 1, "record YC wrong alignment");
_Static_assert(sizeof(struct YC_required_alignment) == 9, "record YC wrong sizeof");
_Static_assert(_Alignof(struct YC_required_alignment) == 1, "record YC wrong alignment");
_Static_assert(sizeof(struct YC_size) == 10, "record YC wrong sizeof");
_Static_assert(_Alignof(struct YC_size) == 1, "record YC wrong alignment");
#endif
_Static_assert(sizeof(YD) == 9, "record YD wrong sizeof");
_Static_assert(_Alignof(YD) == 1, "record YD wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct YD_alignment) == 10, "record YD wrong sizeof");
_Static_assert(_Alignof(struct YD_alignment) == 1, "record YD wrong alignment");
_Static_assert(sizeof(struct YD_packed) == 9, "record YD wrong sizeof");
_Static_assert(_Alignof(struct YD_packed) == 1, "record YD wrong alignment");
_Static_assert(sizeof(struct YD_required_alignment) == 10, "record YD wrong sizeof");
_Static_assert(_Alignof(struct YD_required_alignment) == 1, "record YD wrong alignment");
_Static_assert(sizeof(struct YD_size) == 11, "record YD wrong sizeof");
_Static_assert(_Alignof(struct YD_size) == 1, "record YD wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(YD,b) == 8, "field YD.b wrong bit offset");
#endif
_Static_assert(sizeof(YE) == 4, "record YE wrong sizeof");
_Static_assert(_Alignof(YE) == 32, "record YE wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct YE_alignment) == 64, "record YE wrong sizeof");
_Static_assert(_Alignof(struct YE_alignment) == 32, "record YE wrong alignment");
_Static_assert(sizeof(struct YE_packed) == 4, "record YE wrong sizeof");
_Static_assert(_Alignof(struct YE_packed) == 1, "record YE wrong alignment");
_Static_assert(sizeof(struct YE_required_alignment) == 5, "record YE wrong sizeof");
_Static_assert(_Alignof(struct YE_required_alignment) == 1, "record YE wrong alignment");
_Static_assert(sizeof(struct YE_size) == 6, "record YE wrong sizeof");
_Static_assert(_Alignof(struct YE_size) == 1, "record YE wrong alignment");
#endif
_Static_assert(sizeof(YF) == 5, "record YF wrong sizeof");
_Static_assert(_Alignof(YF) == 1, "record YF wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct YF_alignment) == 6, "record YF wrong sizeof");
_Static_assert(_Alignof(struct YF_alignment) == 1, "record YF wrong alignment");
_Static_assert(sizeof(struct YF_packed) == 5, "record YF wrong sizeof");
_Static_assert(_Alignof(struct YF_packed) == 1, "record YF wrong alignment");
_Static_assert(sizeof(struct YF_required_alignment) == 6, "record YF wrong sizeof");
_Static_assert(_Alignof(struct YF_required_alignment) == 1, "record YF wrong alignment");
_Static_assert(sizeof(struct YF_size) == 7, "record YF wrong sizeof");
_Static_assert(_Alignof(struct YF_size) == 1, "record YF wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(YF,b) == 8, "field YF.b wrong bit offset");
#endif
_Static_assert(sizeof(D0) == 16, "record D0 wrong sizeof");
_Static_assert(_Alignof(D0) == 16, "record D0 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D0_alignment) == 32, "record D0 wrong sizeof");
_Static_assert(_Alignof(struct D0_alignment) == 16, "record D0 wrong alignment");
_Static_assert(sizeof(struct D0_packed) == 16, "record D0 wrong sizeof");
_Static_assert(_Alignof(struct D0_packed) == 1, "record D0 wrong alignment");
_Static_assert(sizeof(struct D0_required_alignment) == 17, "record D0 wrong sizeof");
_Static_assert(_Alignof(struct D0_required_alignment) == 1, "record D0 wrong alignment");
_Static_assert(sizeof(struct D0_size) == 18, "record D0 wrong sizeof");
_Static_assert(_Alignof(struct D0_size) == 1, "record D0 wrong alignment");
#endif
_Static_assert(sizeof(RB0) == 8, "record RB0 wrong sizeof");
_Static_assert(_Alignof(RB0) == 1024, "record RB0 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct RB0_alignment) == 2048, "record RB0 wrong sizeof");
_Static_assert(_Alignof(struct RB0_alignment) == 1024, "record RB0 wrong alignment");
_Static_assert(sizeof(struct RB0_packed) == 8, "record RB0 wrong sizeof");
_Static_assert(_Alignof(struct RB0_packed) == 1, "record RB0 wrong alignment");
_Static_assert(sizeof(struct RB0_required_alignment) == 9, "record RB0 wrong sizeof");
_Static_assert(_Alignof(struct RB0_required_alignment) == 1, "record RB0 wrong alignment");
_Static_assert(sizeof(struct RB0_size) == 10, "record RB0 wrong sizeof");
_Static_assert(_Alignof(struct RB0_size) == 1, "record RB0 wrong alignment");
#endif
_Static_assert(sizeof(RC) == 1028, "record RC wrong sizeof");
_Static_assert(_Alignof(RC) == 1024, "record RC wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct RC_alignment) == 2052, "record RC wrong sizeof");
_Static_assert(_Alignof(struct RC_alignment) == 1024, "record RC wrong alignment");
_Static_assert(sizeof(struct RC_packed) == 1028, "record RC wrong sizeof");
_Static_assert(_Alignof(struct RC_packed) == 1, "record RC wrong alignment");
_Static_assert(sizeof(struct RC_required_alignment) == 1029, "record RC wrong sizeof");
_Static_assert(_Alignof(struct RC_required_alignment) == 1, "record RC wrong alignment");
_Static_assert(sizeof(struct RC_size) == 1030, "record RC wrong sizeof");
_Static_assert(_Alignof(struct RC_size) == 1, "record RC wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(RC,c) == 8192, "field RC.c wrong bit offset");
#endif
_Static_assert(sizeof(RE) == 1029, "record RE wrong sizeof");
_Static_assert(_Alignof(RE) == 1, "record RE wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct RE_alignment) == 1030, "record RE wrong sizeof");
_Static_assert(_Alignof(struct RE_alignment) == 1, "record RE wrong alignment");
_Static_assert(sizeof(struct RE_packed) == 1029, "record RE wrong sizeof");
_Static_assert(_Alignof(struct RE_packed) == 1, "record RE wrong alignment");
_Static_assert(sizeof(struct RE_required_alignment) == 1030, "record RE wrong sizeof");
_Static_assert(_Alignof(struct RE_required_alignment) == 1, "record RE wrong alignment");
_Static_assert(sizeof(struct RE_size) == 1031, "record RE wrong sizeof");
_Static_assert(_Alignof(struct RE_size) == 1, "record RE wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(RE,c) == 8, "field RE.c wrong bit offset");
#endif
_Static_assert(sizeof(PA) == 4, "record PA wrong sizeof");
_Static_assert(_Alignof(PA) == 4, "record PA wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct PA_alignment) == 8, "record PA wrong sizeof");
_Static_assert(_Alignof(struct PA_alignment) == 4, "record PA wrong alignment");
_Static_assert(sizeof(struct PA_packed) == 4, "record PA wrong sizeof");
_Static_assert(_Alignof(struct PA_packed) == 1, "record PA wrong alignment");
_Static_assert(sizeof(struct PA_required_alignment) == 5, "record PA wrong sizeof");
_Static_assert(_Alignof(struct PA_required_alignment) == 1, "record PA wrong alignment");
_Static_assert(sizeof(struct PA_size) == 6, "record PA wrong sizeof");
_Static_assert(_Alignof(struct PA_size) == 1, "record PA wrong alignment");
#endif
_Static_assert(sizeof(PB) == 4, "record PB wrong sizeof");
_Static_assert(_Alignof(PB) == 8, "record PB wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct PB_alignment) == 16, "record PB wrong sizeof");
_Static_assert(_Alignof(struct PB_alignment) == 8, "record PB wrong alignment");
_Static_assert(sizeof(struct PB_packed) == 4, "record PB wrong sizeof");
_Static_assert(_Alignof(struct PB_packed) == 1, "record PB wrong alignment");
_Static_assert(sizeof(struct PB_required_alignment) == 5, "record PB wrong sizeof");
_Static_assert(_Alignof(struct PB_required_alignment) == 1, "record PB wrong alignment");
_Static_assert(sizeof(struct PB_size) == 6, "record PB wrong sizeof");
_Static_assert(_Alignof(struct PB_size) == 1, "record PB wrong alignment");
#endif
_Static_assert(sizeof(PC) == 16, "record PC wrong sizeof");
_Static_assert(_Alignof(PC) == 8, "record PC wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct PC_alignment) == 24, "record PC wrong sizeof");
_Static_assert(_Alignof(struct PC_alignment) == 8, "record PC wrong alignment");
_Static_assert(sizeof(struct PC_packed) == 16, "record PC wrong sizeof");
_Static_assert(_Alignof(struct PC_packed) == 1, "record PC wrong alignment");
_Static_assert(sizeof(struct PC_required_alignment) == 17, "record PC wrong sizeof");
_Static_assert(_Alignof(struct PC_required_alignment) == 1, "record PC wrong alignment");
_Static_assert(sizeof(struct PC_size) == 18, "record PC wrong sizeof");
_Static_assert(_Alignof(struct PC_size) == 1, "record PC wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(PC,x) == 64, "field PC.x wrong bit offset");
#endif
_Static_assert(sizeof(PD) == 4, "record PD wrong sizeof");
_Static_assert(_Alignof(PD) == 8, "record PD wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct PD_alignment) == 16, "record PD wrong sizeof");
_Static_assert(_Alignof(struct PD_alignment) == 8, "record PD wrong alignment");
_Static_assert(sizeof(struct PD_packed) == 4, "record PD wrong sizeof");
_Static_assert(_Alignof(struct PD_packed) == 1, "record PD wrong alignment");
_Static_assert(sizeof(struct PD_required_alignment) == 5, "record PD wrong sizeof");
_Static_assert(_Alignof(struct PD_required_alignment) == 1, "record PD wrong alignment");
_Static_assert(sizeof(struct PD_size) == 6, "record PD wrong sizeof");
_Static_assert(_Alignof(struct PD_size) == 1, "record PD wrong alignment");
#endif
_Static_assert(sizeof(PE) == 16, "record PE wrong sizeof");
_Static_assert(_Alignof(PE) == 8, "record PE wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct PE_alignment) == 24, "record PE wrong sizeof");
_Static_assert(_Alignof(struct PE_alignment) == 8, "record PE wrong alignment");
_Static_assert(sizeof(struct PE_packed) == 16, "record PE wrong sizeof");
_Static_assert(_Alignof(struct PE_packed) == 1, "record PE wrong alignment");
_Static_assert(sizeof(struct PE_required_alignment) == 17, "record PE wrong sizeof");
_Static_assert(_Alignof(struct PE_required_alignment) == 1, "record PE wrong alignment");
_Static_assert(sizeof(struct PE_size) == 18, "record PE wrong sizeof");
_Static_assert(_Alignof(struct PE_size) == 1, "record PE wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(PE,x) == 64, "field PE.x wrong bit offset");
#endif
_Static_assert(sizeof(QA) == 4, "record QA wrong sizeof");
_Static_assert(_Alignof(QA) == 4, "record QA wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct QA_alignment) == 8, "record QA wrong sizeof");
_Static_assert(_Alignof(struct QA_alignment) == 4, "record QA wrong alignment");
_Static_assert(sizeof(struct QA_packed) == 4, "record QA wrong sizeof");
_Static_assert(_Alignof(struct QA_packed) == 1, "record QA wrong alignment");
_Static_assert(sizeof(struct QA_required_alignment) == 5, "record QA wrong sizeof");
_Static_assert(_Alignof(struct QA_required_alignment) == 1, "record QA wrong alignment");
_Static_assert(sizeof(struct QA_size) == 6, "record QA wrong sizeof");
_Static_assert(_Alignof(struct QA_size) == 1, "record QA wrong alignment");
#endif
_Static_assert(sizeof(QB) == 6, "record QB wrong sizeof");
_Static_assert(_Alignof(QB) == 2, "record QB wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct QB_alignment) == 8, "record QB wrong sizeof");
_Static_assert(_Alignof(struct QB_alignment) == 2, "record QB wrong alignment");
_Static_assert(sizeof(struct QB_packed) == 6, "record QB wrong sizeof");
_Static_assert(_Alignof(struct QB_packed) == 1, "record QB wrong alignment");
_Static_assert(sizeof(struct QB_required_alignment) == 7, "record QB wrong sizeof");
_Static_assert(_Alignof(struct QB_required_alignment) == 1, "record QB wrong alignment");
_Static_assert(sizeof(struct QB_size) == 8, "record QB wrong sizeof");
_Static_assert(_Alignof(struct QB_size) == 1, "record QB wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(QB,b) == 16, "field QB.b wrong bit offset");
#endif
_Static_assert(sizeof(QC) == 8, "record QC wrong sizeof");
_Static_assert(_Alignof(QC) == 4, "record QC wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct QC_alignment) == 12, "record QC wrong sizeof");
_Static_assert(_Alignof(struct QC_alignment) == 4, "record QC wrong alignment");
_Static_assert(sizeof(struct QC_packed) == 8, "record QC wrong sizeof");
_Static_assert(_Alignof(struct QC_packed) == 1, "record QC wrong alignment");
_Static_assert(sizeof(struct QC_required_alignment) == 9, "record QC wrong sizeof");
_Static_assert(_Alignof(struct QC_required_alignment) == 1, "record QC wrong alignment");
_Static_assert(sizeof(struct QC_size) == 10, "record QC wrong sizeof");
_Static_assert(_Alignof(struct QC_size) == 1, "record QC wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(QC,b) == 32, "field QC.b wrong bit offset");
#endif
_Static_assert(sizeof(QD) == 8, "record QD wrong sizeof");
_Static_assert(_Alignof(QD) == 4, "record QD wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct QD_alignment) == 12, "record QD wrong sizeof");
_Static_assert(_Alignof(struct QD_alignment) == 4, "record QD wrong alignment");
_Static_assert(sizeof(struct QD_packed) == 8, "record QD wrong sizeof");
_Static_assert(_Alignof(struct QD_packed) == 1, "record QD wrong alignment");
_Static_assert(sizeof(struct QD_required_alignment) == 9, "record QD wrong sizeof");
_Static_assert(_Alignof(struct QD_required_alignment) == 1, "record QD wrong alignment");
_Static_assert(sizeof(struct QD_size) == 10, "record QD wrong sizeof");
_Static_assert(_Alignof(struct QD_size) == 1, "record QD wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(QD,b) == 32, "field QD.b wrong bit offset");
#endif
_Static_assert(sizeof(EmptyAlignedLongLongMemb) == 4, "record EmptyAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(EmptyAlignedLongLongMemb) == 8, "record EmptyAlignedLongLongMemb wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_alignment) == 16, "record EmptyAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_alignment) == 8, "record EmptyAlignedLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_packed) == 4, "record EmptyAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_packed) == 1, "record EmptyAlignedLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_required_alignment) == 5, "record EmptyAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_required_alignment) == 1, "record EmptyAlignedLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_size) == 6, "record EmptyAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_size) == 1, "record EmptyAlignedLongLongMemb wrong alignment");
#endif
_Static_assert(sizeof(EmptyPackedAlignedLongLongMemb) == 4, "record EmptyPackedAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(EmptyPackedAlignedLongLongMemb) == 4, "record EmptyPackedAlignedLongLongMemb wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_alignment) == 8, "record EmptyPackedAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_alignment) == 4, "record EmptyPackedAlignedLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_packed) == 4, "record EmptyPackedAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_packed) == 1, "record EmptyPackedAlignedLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_required_alignment) == 5, "record EmptyPackedAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_required_alignment) == 1, "record EmptyPackedAlignedLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_size) == 6, "record EmptyPackedAlignedLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_size) == 1, "record EmptyPackedAlignedLongLongMemb wrong alignment");
#endif
#endif
