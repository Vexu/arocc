// SPDX-License-Identifier: GPL-3.0-or-later

// This test file is auto-generated. do not edit.
// This file is a derivative work from the test files found
// in this repo : https://github.com/mahkoh/repr-c
// and is under the same licence as the original work.

typedef struct {
    char a;
} A;
A var1;
struct A_extra_alignment {
#ifdef MSVC
    char a[_Alignof(A)];
    char b;
#else
    char a;
    A b;
#endif
};
struct A_extra_alignment var2;
#pragma pack(1)
struct A_extra_packed {
    A a;
};
#pragma pack()
struct A_extra_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct A_extra_packed)];
    char b;
#else
    char a;
    struct A_extra_packed b;
#endif
};
struct A_extra_required_alignment var3;
struct A_extra_size {
    char a[sizeof(A)+1];
    char b;
};
struct A_extra_size var4;

typedef struct {
#ifdef MSVC
    __declspec(align(4)) long long a;
#else
    long long a __attribute__((aligned(4)));
#endif
} B;
B var5;
struct B_extra_alignment {
#ifdef MSVC
    char a[_Alignof(B)];
    char b;
#else
    char a;
    B b;
#endif
};
struct B_extra_alignment var6;
#pragma pack(1)
struct B_extra_packed {
    B a;
};
#pragma pack()
struct B_extra_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct B_extra_packed)];
    char b;
#else
    char a;
    struct B_extra_packed b;
#endif
};
struct B_extra_required_alignment var7;
struct B_extra_size {
    char a[sizeof(B)+1];
    char b;
};
struct B_extra_size var8;

#pragma pack(2)
typedef struct {
    B a;
    char b;
    int c;
} X;
X var9;
#pragma pack()
struct X_extra_alignment {
#ifdef MSVC
    char a[_Alignof(X)];
    char b;
#else
    char a;
    X b;
#endif
};
struct X_extra_alignment var10;
#pragma pack(1)
struct X_extra_packed {
    X a;
};
#pragma pack()
struct X_extra_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct X_extra_packed)];
    char b;
#else
    char a;
    struct X_extra_packed b;
#endif
};
struct X_extra_required_alignment var11;
struct X_extra_size {
    char a[sizeof(X)+1];
    char b;
};
struct X_extra_size var12;

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
struct YA_extra_alignment {
#ifdef MSVC
    char a[_Alignof(YA)];
    char b;
#else
    char a;
    YA b;
#endif
};
struct YA_extra_alignment var14;
#pragma pack(1)
struct YA_extra_packed {
    YA a;
};
#pragma pack()
struct YA_extra_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct YA_extra_packed)];
    char b;
#else
    char a;
    struct YA_extra_packed b;
#endif
};
struct YA_extra_required_alignment var15;
struct YA_extra_size {
    char a[sizeof(YA)+1];
    char b;
};
struct YA_extra_size var16;

#pragma pack(1)
typedef struct {
    char a;
    YA b;
} YB;
YB var17;
#pragma pack()
struct YB_extra_alignment {
#ifdef MSVC
    char a[_Alignof(YB)];
    char b;
#else
    char a;
    YB b;
#endif
};
struct YB_extra_alignment var18;
#pragma pack(1)
struct YB_extra_packed {
    YB a;
};
#pragma pack()
struct YB_extra_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct YB_extra_packed)];
    char b;
#else
    char a;
    struct YB_extra_packed b;
#endif
};
struct YB_extra_required_alignment var19;
struct YB_extra_size {
    char a[sizeof(YB)+1];
    char b;
};
struct YB_extra_size var20;

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
struct YC_extra_alignment {
#ifdef MSVC
    char a[_Alignof(YC)];
    char b;
#else
    char a;
    YC b;
#endif
};
struct YC_extra_alignment var22;
#pragma pack(1)
struct YC_extra_packed {
    YC a;
};
#pragma pack()
struct YC_extra_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct YC_extra_packed)];
    char b;
#else
    char a;
    struct YC_extra_packed b;
#endif
};
struct YC_extra_required_alignment var23;
struct YC_extra_size {
    char a[sizeof(YC)+1];
    char b;
};
struct YC_extra_size var24;

#pragma pack(1)
typedef struct {
    char a;
    YC b;
} YD;
YD var25;
#pragma pack()
struct YD_extra_alignment {
#ifdef MSVC
    char a[_Alignof(YD)];
    char b;
#else
    char a;
    YD b;
#endif
};
struct YD_extra_alignment var26;
#pragma pack(1)
struct YD_extra_packed {
    YD a;
};
#pragma pack()
struct YD_extra_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct YD_extra_packed)];
    char b;
#else
    char a;
    struct YD_extra_packed b;
#endif
};
struct YD_extra_required_alignment var27;
struct YD_extra_size {
    char a[sizeof(YD)+1];
    char b;
};
struct YD_extra_size var28;

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
struct YE_extra_alignment {
#ifdef MSVC
    char a[_Alignof(YE)];
    char b;
#else
    char a;
    YE b;
#endif
};
struct YE_extra_alignment var30;
#pragma pack(1)
struct YE_extra_packed {
    YE a;
};
#pragma pack()
struct YE_extra_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct YE_extra_packed)];
    char b;
#else
    char a;
    struct YE_extra_packed b;
#endif
};
struct YE_extra_required_alignment var31;
struct YE_extra_size {
    char a[sizeof(YE)+1];
    char b;
};
struct YE_extra_size var32;

#pragma pack(1)
typedef struct {
    char a;
    YE b;
} YF;
YF var33;
#pragma pack()
struct YF_extra_alignment {
#ifdef MSVC
    char a[_Alignof(YF)];
    char b;
#else
    char a;
    YF b;
#endif
};
struct YF_extra_alignment var34;
#pragma pack(1)
struct YF_extra_packed {
    YF a;
};
#pragma pack()
struct YF_extra_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct YF_extra_packed)];
    char b;
#else
    char a;
    struct YF_extra_packed b;
#endif
};
struct YF_extra_required_alignment var35;
struct YF_extra_size {
    char a[sizeof(YF)+1];
    char b;
};
struct YF_extra_size var36;

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
struct D0_extra_alignment {
#ifdef MSVC
    char a[_Alignof(D0)];
    char b;
#else
    char a;
    D0 b;
#endif
};
struct D0_extra_alignment var38;
#pragma pack(1)
struct D0_extra_packed {
    D0 a;
};
#pragma pack()
struct D0_extra_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct D0_extra_packed)];
    char b;
#else
    char a;
    struct D0_extra_packed b;
#endif
};
struct D0_extra_required_alignment var39;
struct D0_extra_size {
    char a[sizeof(D0)+1];
    char b;
};
struct D0_extra_size var40;

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
struct RB0_extra_alignment {
#ifdef MSVC
    char a[_Alignof(RB0)];
    char b;
#else
    char a;
    RB0 b;
#endif
};
struct RB0_extra_alignment var42;
#pragma pack(1)
struct RB0_extra_packed {
    RB0 a;
};
#pragma pack()
struct RB0_extra_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct RB0_extra_packed)];
    char b;
#else
    char a;
    struct RB0_extra_packed b;
#endif
};
struct RB0_extra_required_alignment var43;
struct RB0_extra_size {
    char a[sizeof(RB0)+1];
    char b;
};
struct RB0_extra_size var44;

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
struct RC_extra_alignment {
#ifdef MSVC
    char a[_Alignof(RC)];
    char b;
#else
    char a;
    RC b;
#endif
};
struct RC_extra_alignment var46;
#pragma pack(1)
struct RC_extra_packed {
    RC a;
};
#pragma pack()
struct RC_extra_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct RC_extra_packed)];
    char b;
#else
    char a;
    struct RC_extra_packed b;
#endif
};
struct RC_extra_required_alignment var47;
struct RC_extra_size {
    char a[sizeof(RC)+1];
    char b;
};
struct RC_extra_size var48;

#pragma pack(1)
typedef struct {
    char a;
    RC c;
} RE;
RE var49;
#pragma pack()
struct RE_extra_alignment {
#ifdef MSVC
    char a[_Alignof(RE)];
    char b;
#else
    char a;
    RE b;
#endif
};
struct RE_extra_alignment var50;
#pragma pack(1)
struct RE_extra_packed {
    RE a;
};
#pragma pack()
struct RE_extra_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct RE_extra_packed)];
    char b;
#else
    char a;
    struct RE_extra_packed b;
#endif
};
struct RE_extra_required_alignment var51;
struct RE_extra_size {
    char a[sizeof(RE)+1];
    char b;
};
struct RE_extra_size var52;

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
struct PA_extra_alignment {
#ifdef MSVC
    char a[_Alignof(PA)];
    char b;
#else
    char a;
    PA b;
#endif
};
struct PA_extra_alignment var54;
#pragma pack(1)
struct PA_extra_packed {
    PA a;
};
#pragma pack()
struct PA_extra_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct PA_extra_packed)];
    char b;
#else
    char a;
    struct PA_extra_packed b;
#endif
};
struct PA_extra_required_alignment var55;
struct PA_extra_size {
    char a[sizeof(PA)+1];
    char b;
};
struct PA_extra_size var56;

#ifdef MSVC
__declspec(align(8)) typedef PA PB;
#else
typedef PA PB __attribute__((aligned(8)));
#endif
PB var57;
struct PB_extra_alignment {
#ifdef MSVC
    char a[_Alignof(PB)];
    char b;
#else
    char a;
    PB b;
#endif
};
struct PB_extra_alignment var58;
#pragma pack(1)
struct PB_extra_packed {
    PB a;
};
#pragma pack()
struct PB_extra_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct PB_extra_packed)];
    char b;
#else
    char a;
    struct PB_extra_packed b;
#endif
};
struct PB_extra_required_alignment var59;
struct PB_extra_size {
    char a[sizeof(PB)+1];
    char b;
};
struct PB_extra_size var60;

#pragma pack(1)
typedef struct {
    char a;
    PB x;
} PC;
PC var61;
#pragma pack()
struct PC_extra_alignment {
#ifdef MSVC
    char a[_Alignof(PC)];
    char b;
#else
    char a;
    PC b;
#endif
};
struct PC_extra_alignment var62;
#pragma pack(1)
struct PC_extra_packed {
    PC a;
};
#pragma pack()
struct PC_extra_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct PC_extra_packed)];
    char b;
#else
    char a;
    struct PC_extra_packed b;
#endif
};
struct PC_extra_required_alignment var63;
struct PC_extra_size {
    char a[sizeof(PC)+1];
    char b;
};
struct PC_extra_size var64;

typedef PB PD;
PD var65;
struct PD_extra_alignment {
#ifdef MSVC
    char a[_Alignof(PD)];
    char b;
#else
    char a;
    PD b;
#endif
};
struct PD_extra_alignment var66;
#pragma pack(1)
struct PD_extra_packed {
    PD a;
};
#pragma pack()
struct PD_extra_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct PD_extra_packed)];
    char b;
#else
    char a;
    struct PD_extra_packed b;
#endif
};
struct PD_extra_required_alignment var67;
struct PD_extra_size {
    char a[sizeof(PD)+1];
    char b;
};
struct PD_extra_size var68;

#pragma pack(1)
typedef struct {
    char a;
    PD x;
} PE;
PE var69;
#pragma pack()
struct PE_extra_alignment {
#ifdef MSVC
    char a[_Alignof(PE)];
    char b;
#else
    char a;
    PE b;
#endif
};
struct PE_extra_alignment var70;
#pragma pack(1)
struct PE_extra_packed {
    PE a;
};
#pragma pack()
struct PE_extra_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct PE_extra_packed)];
    char b;
#else
    char a;
    struct PE_extra_packed b;
#endif
};
struct PE_extra_required_alignment var71;
struct PE_extra_size {
    char a[sizeof(PE)+1];
    char b;
};
struct PE_extra_size var72;

#ifdef MSVC
__declspec(align(2)) typedef int QA;
#else
typedef int QA __attribute__((aligned(2)));
#endif
QA var73;
struct QA_extra_alignment {
#ifdef MSVC
    char a[_Alignof(QA)];
    char b;
#else
    char a;
    QA b;
#endif
};
struct QA_extra_alignment var74;
#pragma pack(1)
struct QA_extra_packed {
    QA a;
};
#pragma pack()
struct QA_extra_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct QA_extra_packed)];
    char b;
#else
    char a;
    struct QA_extra_packed b;
#endif
};
struct QA_extra_required_alignment var75;
struct QA_extra_size {
    char a[sizeof(QA)+1];
    char b;
};
struct QA_extra_size var76;

#pragma pack(1)
typedef struct {
    char a;
    QA b;
} QB;
QB var77;
#pragma pack()
struct QB_extra_alignment {
#ifdef MSVC
    char a[_Alignof(QB)];
    char b;
#else
    char a;
    QB b;
#endif
};
struct QB_extra_alignment var78;
#pragma pack(1)
struct QB_extra_packed {
    QB a;
};
#pragma pack()
struct QB_extra_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct QB_extra_packed)];
    char b;
#else
    char a;
    struct QB_extra_packed b;
#endif
};
struct QB_extra_required_alignment var79;
struct QB_extra_size {
    char a[sizeof(QB)+1];
    char b;
};
struct QB_extra_size var80;

typedef struct {
    char a;
    QA b;
} QC;
QC var81;
struct QC_extra_alignment {
#ifdef MSVC
    char a[_Alignof(QC)];
    char b;
#else
    char a;
    QC b;
#endif
};
struct QC_extra_alignment var82;
#pragma pack(1)
struct QC_extra_packed {
    QC a;
};
#pragma pack()
struct QC_extra_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct QC_extra_packed)];
    char b;
#else
    char a;
    struct QC_extra_packed b;
#endif
};
struct QC_extra_required_alignment var83;
struct QC_extra_size {
    char a[sizeof(QC)+1];
    char b;
};
struct QC_extra_size var84;

typedef struct {
    char a;
    QA b:3;
} QD;
QD var85;
struct QD_extra_alignment {
#ifdef MSVC
    char a[_Alignof(QD)];
    char b;
#else
    char a;
    QD b;
#endif
};
struct QD_extra_alignment var86;
#pragma pack(1)
struct QD_extra_packed {
    QD a;
};
#pragma pack()
struct QD_extra_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct QD_extra_packed)];
    char b;
#else
    char a;
    struct QD_extra_packed b;
#endif
};
struct QD_extra_required_alignment var87;
struct QD_extra_size {
    char a[sizeof(QD)+1];
    char b;
};
struct QD_extra_size var88;

#ifdef MSVC
typedef long long unnamed_type_89[];
#else
typedef long long unnamed_type_89[0];
#endif
unnamed_type_89 var90;
struct unnamed_type_89_extra_alignment {
#ifdef MSVC
    char a[_Alignof(unnamed_type_89)];
    char b;
#else
    char a;
    unnamed_type_89 b;
#endif
};
struct unnamed_type_89_extra_alignment var91;
#pragma pack(1)
struct unnamed_type_89_extra_packed {
    unnamed_type_89 a;
};
#pragma pack()
struct unnamed_type_89_extra_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct unnamed_type_89_extra_packed)];
    char b;
#else
    char a;
    struct unnamed_type_89_extra_packed b;
#endif
};
struct unnamed_type_89_extra_required_alignment var92;
struct unnamed_type_89_extra_size {
    char a[sizeof(unnamed_type_89)+1];
    char b;
};
struct unnamed_type_89_extra_size var93;

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
struct EmptyAlignedLongLongMemb_extra_alignment {
#ifdef MSVC
    char a[_Alignof(EmptyAlignedLongLongMemb)];
    char b;
#else
    char a;
    EmptyAlignedLongLongMemb b;
#endif
};
struct EmptyAlignedLongLongMemb_extra_alignment var95;
#pragma pack(1)
struct EmptyAlignedLongLongMemb_extra_packed {
    EmptyAlignedLongLongMemb a;
};
#pragma pack()
struct EmptyAlignedLongLongMemb_extra_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct EmptyAlignedLongLongMemb_extra_packed)];
    char b;
#else
    char a;
    struct EmptyAlignedLongLongMemb_extra_packed b;
#endif
};
struct EmptyAlignedLongLongMemb_extra_required_alignment var96;
struct EmptyAlignedLongLongMemb_extra_size {
    char a[sizeof(EmptyAlignedLongLongMemb)+1];
    char b;
};
struct EmptyAlignedLongLongMemb_extra_size var97;

#ifdef MSVC
typedef long long unnamed_type_98[];
#else
typedef long long unnamed_type_98[0];
#endif
unnamed_type_98 var99;
struct unnamed_type_98_extra_alignment {
#ifdef MSVC
    char a[_Alignof(unnamed_type_98)];
    char b;
#else
    char a;
    unnamed_type_98 b;
#endif
};
struct unnamed_type_98_extra_alignment var100;
#pragma pack(1)
struct unnamed_type_98_extra_packed {
    unnamed_type_98 a;
};
#pragma pack()
struct unnamed_type_98_extra_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct unnamed_type_98_extra_packed)];
    char b;
#else
    char a;
    struct unnamed_type_98_extra_packed b;
#endif
};
struct unnamed_type_98_extra_required_alignment var101;
struct unnamed_type_98_extra_size {
    char a[sizeof(unnamed_type_98)+1];
    char b;
};
struct unnamed_type_98_extra_size var102;

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
struct EmptyPackedAlignedLongLongMemb_extra_alignment {
#ifdef MSVC
    char a[_Alignof(EmptyPackedAlignedLongLongMemb)];
    char b;
#else
    char a;
    EmptyPackedAlignedLongLongMemb b;
#endif
};
struct EmptyPackedAlignedLongLongMemb_extra_alignment var104;
#pragma pack(1)
struct EmptyPackedAlignedLongLongMemb_extra_packed {
    EmptyPackedAlignedLongLongMemb a;
};
#pragma pack()
struct EmptyPackedAlignedLongLongMemb_extra_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct EmptyPackedAlignedLongLongMemb_extra_packed)];
    char b;
#else
    char a;
    struct EmptyPackedAlignedLongLongMemb_extra_packed b;
#endif
};
struct EmptyPackedAlignedLongLongMemb_extra_required_alignment var105;
struct EmptyPackedAlignedLongLongMemb_extra_size {
    char a[sizeof(EmptyPackedAlignedLongLongMemb)+1];
    char b;
};
struct EmptyPackedAlignedLongLongMemb_extra_size var106;

// MAPPING|ONE|aarch64-generic-macos-none:Clang|aarch64-generic-ios-none:Clang|aarch64-generic-ios-macabi:Clang|aarch64-generic-tvos-none:Clang|hexagon-generic-linux-musl:Clang|mips64el-mips64-linux-gnuabi64:Gcc|mips64el-mips64-linux-musl:Gcc|mips64-mips64-linux-gnuabi64:Gcc|mips64-mips64-linux-musl:Gcc|mipsel-mips32-linux-gnu:Gcc|mipsel-mips32-linux-musl:Gcc|mipsel-mips32-other-none:Clang|mips-mips32-linux-gnu:Gcc|mips-mips32r6-linux-gnu:Gcc|mips-mips32-linux-gnuabi64:Gcc|mips-mips64r6-linux-gnuabi64:Gcc|mips-mips32-linux-gnu:Gcc|mips-mips32-linux-musl:Gcc|powerpc64le-ppc64le-linux-gnu:Gcc|powerpc64le-ppc64le-linux-musl:Gcc|powerpc64-ppc64-freebsd-gnu:Clang|powerpc64-ppc64-linux-gnu:Gcc|powerpc64-ppc64-linux-musl:Gcc|powerpc-ppc-linux-gnu:Gcc|powerpc-ppc-linux-musl:Gcc|powerpc-ppc-netbsd-gnu:Clang|riscv32-baseline_rv32-other-eabi:Clang|riscv32-baseline_rv32-linux-gnu:Gcc|riscv64-baseline_rv64-other-eabi:Clang|riscv64-baseline_rv64-linux-gnu:Gcc|s390x-generic-linux-gnu:Gcc|sparc64-v9-linux-gnu:Gcc|sparc64-v9-netbsd-gnu:Clang|sparc64-v9-openbsd-gnu:Clang|sparc-v8-linux-gnu:Gcc|sparc-v9-solaris-eabi:Clang|wasm32-generic-emscripten-musl:Clang|wasm32-generic-other-musl:Clang|wasm32-generic-wasi-musl:Clang|x86_64-x86_64-ios-macabi:Clang|x86_64-x86_64-ios-none:Clang|x86_64-x86_64-macos-none:Clang|x86_64-x86_64-tvos-none:Clang|x86_64-x86_64-other-eabi:Clang|x86_64-x86_64-fuchsia-gnu:Clang|x86_64-x86_64-linux-android:Clang|x86_64-x86_64-solaris-eabi:Clang|x86_64-x86_64-dragonfly-eabi:Clang|x86_64-x86_64-freebsd-gnu:Clang|x86_64-x86_64-haiku-gnu:Clang|x86_64-x86_64-hermit-eabi:Clang|x86_64-x86_64-linux-gnux32:Gcc|x86_64-x86_64-linux-gnu:Gcc|x86_64-x86_64-linux-musl:Gcc|x86_64-x86_64-netbsd-gnu:Clang|x86_64-x86_64-openbsd-gnu:Clang|END
// repr targets Aarch64AppleMacosx|Some("aarch64-generic-macos-none") Arm64AppleIos|Some("aarch64-generic-ios-none") Arm64AppleIosMacabi|Some("aarch64-generic-ios-macabi") Arm64AppleTvos|Some("aarch64-generic-tvos-none") HexagonUnknownLinuxMusl|Some("hexagon-generic-linux-musl") Mips64elUnknownLinuxGnuabi64|Some("mips64el-mips64-linux-gnuabi64") Mips64elUnknownLinuxMusl|Some("mips64el-mips64-linux-musl") Mips64UnknownLinuxGnuabi64|Some("mips64-mips64-linux-gnuabi64") Mips64UnknownLinuxMusl|Some("mips64-mips64-linux-musl") MipselSonyPsp|None MipselUnknownLinuxGnu|Some("mipsel-mips32-linux-gnu") MipselUnknownLinuxMusl|Some("mipsel-mips32-linux-musl") MipselUnknownLinuxUclibc|None MipselUnknownNone|Some("mipsel-mips32-other-none") Mipsisa32r6elUnknownLinuxGnu|Some("mips-mips32-linux-gnu") Mipsisa32r6UnknownLinuxGnu|Some("mips-mips32r6-linux-gnu") Mipsisa64r6elUnknownLinuxGnuabi64|Some("mips-mips32-linux-gnuabi64") Mipsisa64r6UnknownLinuxGnuabi64|Some("mips-mips64r6-linux-gnuabi64") MipsUnknownLinuxGnu|Some("mips-mips32-linux-gnu") MipsUnknownLinuxMusl|Some("mips-mips32-linux-musl") MipsUnknownLinuxUclibc|None Powerpc64leUnknownLinuxGnu|Some("powerpc64le-ppc64le-linux-gnu") Powerpc64leUnknownLinuxMusl|Some("powerpc64le-ppc64le-linux-musl") Powerpc64UnknownFreebsd|Some("powerpc64-ppc64-freebsd-gnu") Powerpc64UnknownLinuxGnu|Some("powerpc64-ppc64-linux-gnu") Powerpc64UnknownLinuxMusl|Some("powerpc64-ppc64-linux-musl") PowerpcUnknownLinuxGnu|Some("powerpc-ppc-linux-gnu") PowerpcUnknownLinuxGnuspe|None PowerpcUnknownLinuxMusl|Some("powerpc-ppc-linux-musl") PowerpcUnknownNetbsd|Some("powerpc-ppc-netbsd-gnu") Riscv32|Some("riscv32-baseline_rv32-other-eabi") Riscv32UnknownLinuxGnu|Some("riscv32-baseline_rv32-linux-gnu") Riscv64|Some("riscv64-baseline_rv64-other-eabi") Riscv64UnknownLinuxGnu|Some("riscv64-baseline_rv64-linux-gnu") S390xUnknownLinuxGnu|Some("s390x-generic-linux-gnu") Sparc64UnknownLinuxGnu|Some("sparc64-v9-linux-gnu") Sparc64UnknownNetbsd|Some("sparc64-v9-netbsd-gnu") Sparc64UnknownOpenbsd|Some("sparc64-v9-openbsd-gnu") SparcUnknownLinuxGnu|Some("sparc-v8-linux-gnu") Sparcv9SunSolaris|Some("sparc-v9-solaris-eabi") Wasm32UnknownEmscripten|Some("wasm32-generic-emscripten-musl") Wasm32UnknownUnknown|Some("wasm32-generic-other-musl") Wasm32Wasi|Some("wasm32-generic-wasi-musl") X86_64AppleIosMacabi|Some("x86_64-x86_64-ios-macabi") X86_64AppleIos|Some("x86_64-x86_64-ios-none") X86_64AppleMacosx|Some("x86_64-x86_64-macos-none") X86_64AppleTvos|Some("x86_64-x86_64-tvos-none") X86_64Elf|Some("x86_64-x86_64-other-eabi") X86_64Fuchsia|Some("x86_64-x86_64-fuchsia-gnu") X86_64LinuxAndroid|Some("x86_64-x86_64-linux-android") X86_64PcSolaris|Some("x86_64-x86_64-solaris-eabi") X86_64RumprunNetbsd|None X86_64UnknownDragonfly|Some("x86_64-x86_64-dragonfly-eabi") X86_64UnknownFreebsd|Some("x86_64-x86_64-freebsd-gnu") X86_64UnknownHaiku|Some("x86_64-x86_64-haiku-gnu") X86_64UnknownHermit|Some("x86_64-x86_64-hermit-eabi") X86_64UnknownL4reUclibc|None X86_64UnknownLinuxGnux32|Some("x86_64-x86_64-linux-gnux32") X86_64UnknownLinuxGnu|Some("x86_64-x86_64-linux-gnu") X86_64UnknownLinuxMusl|Some("x86_64-x86_64-linux-musl") X86_64UnknownNetbsd|Some("x86_64-x86_64-netbsd-gnu") X86_64UnknownOpenbsd|Some("x86_64-x86_64-openbsd-gnu") X86_64UnknownRedox|None 
#ifdef ONE
_Static_assert(sizeof(A) == 1, "");
_Static_assert(_Alignof(A) == 1, "");
_Static_assert(sizeof(struct A_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct A_extra_alignment) == 1, "");
_Static_assert(sizeof(struct A_extra_packed) == 1, "");
_Static_assert(_Alignof(struct A_extra_packed) == 1, "");
_Static_assert(sizeof(struct A_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct A_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A_extra_size) == 3, "");
_Static_assert(_Alignof(struct A_extra_size) == 1, "");
_Static_assert(sizeof(B) == 8, "");
_Static_assert(_Alignof(B) == 8, "");
_Static_assert(sizeof(struct B_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct B_extra_alignment) == 8, "");
_Static_assert(sizeof(struct B_extra_packed) == 8, "");
_Static_assert(_Alignof(struct B_extra_packed) == 1, "");
_Static_assert(sizeof(struct B_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct B_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B_extra_size) == 10, "");
_Static_assert(_Alignof(struct B_extra_size) == 1, "");
_Static_assert(sizeof(X) == 14, "");
_Static_assert(_Alignof(X) == 2, "");
_Static_assert(sizeof(struct X_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct X_extra_alignment) == 2, "");
_Static_assert(sizeof(struct X_extra_packed) == 14, "");
_Static_assert(_Alignof(struct X_extra_packed) == 1, "");
_Static_assert(sizeof(struct X_extra_required_alignment) == 15, "");
_Static_assert(_Alignof(struct X_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct X_extra_size) == 16, "");
_Static_assert(_Alignof(struct X_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(X,b) == 64, "");
_Static_assert(__builtin_bitoffsetof(X,c) == 80, "");
#endif
_Static_assert(sizeof(YA) == 1, "");
_Static_assert(_Alignof(YA) == 1, "");
_Static_assert(sizeof(struct YA_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct YA_extra_alignment) == 1, "");
_Static_assert(sizeof(struct YA_extra_packed) == 1, "");
_Static_assert(_Alignof(struct YA_extra_packed) == 1, "");
_Static_assert(sizeof(struct YA_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct YA_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct YA_extra_size) == 3, "");
_Static_assert(_Alignof(struct YA_extra_size) == 1, "");
_Static_assert(sizeof(YB) == 2, "");
_Static_assert(_Alignof(YB) == 1, "");
_Static_assert(sizeof(struct YB_extra_alignment) == 3, "");
_Static_assert(_Alignof(struct YB_extra_alignment) == 1, "");
_Static_assert(sizeof(struct YB_extra_packed) == 2, "");
_Static_assert(_Alignof(struct YB_extra_packed) == 1, "");
_Static_assert(sizeof(struct YB_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct YB_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct YB_extra_size) == 4, "");
_Static_assert(_Alignof(struct YB_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(YB,b) == 8, "");
#endif
_Static_assert(sizeof(YC) == 1, "");
_Static_assert(_Alignof(YC) == 1, "");
_Static_assert(sizeof(struct YC_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct YC_extra_alignment) == 1, "");
_Static_assert(sizeof(struct YC_extra_packed) == 1, "");
_Static_assert(_Alignof(struct YC_extra_packed) == 1, "");
_Static_assert(sizeof(struct YC_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct YC_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct YC_extra_size) == 3, "");
_Static_assert(_Alignof(struct YC_extra_size) == 1, "");
_Static_assert(sizeof(YD) == 2, "");
_Static_assert(_Alignof(YD) == 1, "");
_Static_assert(sizeof(struct YD_extra_alignment) == 3, "");
_Static_assert(_Alignof(struct YD_extra_alignment) == 1, "");
_Static_assert(sizeof(struct YD_extra_packed) == 2, "");
_Static_assert(_Alignof(struct YD_extra_packed) == 1, "");
_Static_assert(sizeof(struct YD_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct YD_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct YD_extra_size) == 4, "");
_Static_assert(_Alignof(struct YD_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(YD,b) == 8, "");
#endif
_Static_assert(sizeof(YE) == 1, "");
_Static_assert(_Alignof(YE) == 1, "");
_Static_assert(sizeof(struct YE_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct YE_extra_alignment) == 1, "");
_Static_assert(sizeof(struct YE_extra_packed) == 1, "");
_Static_assert(_Alignof(struct YE_extra_packed) == 1, "");
_Static_assert(sizeof(struct YE_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct YE_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct YE_extra_size) == 3, "");
_Static_assert(_Alignof(struct YE_extra_size) == 1, "");
_Static_assert(sizeof(YF) == 2, "");
_Static_assert(_Alignof(YF) == 1, "");
_Static_assert(sizeof(struct YF_extra_alignment) == 3, "");
_Static_assert(_Alignof(struct YF_extra_alignment) == 1, "");
_Static_assert(sizeof(struct YF_extra_packed) == 2, "");
_Static_assert(_Alignof(struct YF_extra_packed) == 1, "");
_Static_assert(sizeof(struct YF_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct YF_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct YF_extra_size) == 4, "");
_Static_assert(_Alignof(struct YF_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(YF,b) == 8, "");
#endif
_Static_assert(sizeof(D0) == 16, "");
_Static_assert(_Alignof(D0) == 16, "");
_Static_assert(sizeof(struct D0_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct D0_extra_alignment) == 16, "");
_Static_assert(sizeof(struct D0_extra_packed) == 16, "");
_Static_assert(_Alignof(struct D0_extra_packed) == 1, "");
_Static_assert(sizeof(struct D0_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct D0_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct D0_extra_size) == 18, "");
_Static_assert(_Alignof(struct D0_extra_size) == 1, "");
_Static_assert(sizeof(RB0) == 8, "");
_Static_assert(_Alignof(RB0) == 8, "");
_Static_assert(sizeof(struct RB0_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct RB0_extra_alignment) == 8, "");
_Static_assert(sizeof(struct RB0_extra_packed) == 8, "");
_Static_assert(_Alignof(struct RB0_extra_packed) == 1, "");
_Static_assert(sizeof(struct RB0_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct RB0_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct RB0_extra_size) == 10, "");
_Static_assert(_Alignof(struct RB0_extra_size) == 1, "");
_Static_assert(sizeof(RC) == 2, "");
_Static_assert(_Alignof(RC) == 1, "");
_Static_assert(sizeof(struct RC_extra_alignment) == 3, "");
_Static_assert(_Alignof(struct RC_extra_alignment) == 1, "");
_Static_assert(sizeof(struct RC_extra_packed) == 2, "");
_Static_assert(_Alignof(struct RC_extra_packed) == 1, "");
_Static_assert(sizeof(struct RC_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct RC_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct RC_extra_size) == 4, "");
_Static_assert(_Alignof(struct RC_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(RC,c) == 8, "");
#endif
_Static_assert(sizeof(RE) == 3, "");
_Static_assert(_Alignof(RE) == 1, "");
_Static_assert(sizeof(struct RE_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct RE_extra_alignment) == 1, "");
_Static_assert(sizeof(struct RE_extra_packed) == 3, "");
_Static_assert(_Alignof(struct RE_extra_packed) == 1, "");
_Static_assert(sizeof(struct RE_extra_required_alignment) == 4, "");
_Static_assert(_Alignof(struct RE_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct RE_extra_size) == 5, "");
_Static_assert(_Alignof(struct RE_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(RE,c) == 8, "");
#endif
_Static_assert(sizeof(PA) == 4, "");
_Static_assert(_Alignof(PA) == 4, "");
_Static_assert(sizeof(struct PA_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct PA_extra_alignment) == 4, "");
_Static_assert(sizeof(struct PA_extra_packed) == 4, "");
_Static_assert(_Alignof(struct PA_extra_packed) == 1, "");
_Static_assert(sizeof(struct PA_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct PA_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct PA_extra_size) == 6, "");
_Static_assert(_Alignof(struct PA_extra_size) == 1, "");
_Static_assert(sizeof(PB) == 4, "");
_Static_assert(_Alignof(PB) == 8, "");
_Static_assert(sizeof(struct PB_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct PB_extra_alignment) == 8, "");
_Static_assert(sizeof(struct PB_extra_packed) == 4, "");
_Static_assert(_Alignof(struct PB_extra_packed) == 1, "");
_Static_assert(sizeof(struct PB_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct PB_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct PB_extra_size) == 6, "");
_Static_assert(_Alignof(struct PB_extra_size) == 1, "");
_Static_assert(sizeof(PC) == 5, "");
_Static_assert(_Alignof(PC) == 1, "");
_Static_assert(sizeof(struct PC_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct PC_extra_alignment) == 1, "");
_Static_assert(sizeof(struct PC_extra_packed) == 5, "");
_Static_assert(_Alignof(struct PC_extra_packed) == 1, "");
_Static_assert(sizeof(struct PC_extra_required_alignment) == 6, "");
_Static_assert(_Alignof(struct PC_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct PC_extra_size) == 7, "");
_Static_assert(_Alignof(struct PC_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(PC,x) == 8, "");
#endif
_Static_assert(sizeof(PD) == 4, "");
_Static_assert(_Alignof(PD) == 8, "");
_Static_assert(sizeof(struct PD_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct PD_extra_alignment) == 8, "");
_Static_assert(sizeof(struct PD_extra_packed) == 4, "");
_Static_assert(_Alignof(struct PD_extra_packed) == 1, "");
_Static_assert(sizeof(struct PD_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct PD_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct PD_extra_size) == 6, "");
_Static_assert(_Alignof(struct PD_extra_size) == 1, "");
_Static_assert(sizeof(PE) == 5, "");
_Static_assert(_Alignof(PE) == 1, "");
_Static_assert(sizeof(struct PE_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct PE_extra_alignment) == 1, "");
_Static_assert(sizeof(struct PE_extra_packed) == 5, "");
_Static_assert(_Alignof(struct PE_extra_packed) == 1, "");
_Static_assert(sizeof(struct PE_extra_required_alignment) == 6, "");
_Static_assert(_Alignof(struct PE_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct PE_extra_size) == 7, "");
_Static_assert(_Alignof(struct PE_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(PE,x) == 8, "");
#endif
_Static_assert(sizeof(QA) == 4, "");
_Static_assert(_Alignof(QA) == 2, "");
_Static_assert(sizeof(struct QA_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct QA_extra_alignment) == 2, "");
_Static_assert(sizeof(struct QA_extra_packed) == 4, "");
_Static_assert(_Alignof(struct QA_extra_packed) == 1, "");
_Static_assert(sizeof(struct QA_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct QA_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct QA_extra_size) == 6, "");
_Static_assert(_Alignof(struct QA_extra_size) == 1, "");
_Static_assert(sizeof(QB) == 5, "");
_Static_assert(_Alignof(QB) == 1, "");
_Static_assert(sizeof(struct QB_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct QB_extra_alignment) == 1, "");
_Static_assert(sizeof(struct QB_extra_packed) == 5, "");
_Static_assert(_Alignof(struct QB_extra_packed) == 1, "");
_Static_assert(sizeof(struct QB_extra_required_alignment) == 6, "");
_Static_assert(_Alignof(struct QB_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct QB_extra_size) == 7, "");
_Static_assert(_Alignof(struct QB_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(QB,b) == 8, "");
#endif
_Static_assert(sizeof(QC) == 6, "");
_Static_assert(_Alignof(QC) == 2, "");
_Static_assert(sizeof(struct QC_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct QC_extra_alignment) == 2, "");
_Static_assert(sizeof(struct QC_extra_packed) == 6, "");
_Static_assert(_Alignof(struct QC_extra_packed) == 1, "");
_Static_assert(sizeof(struct QC_extra_required_alignment) == 7, "");
_Static_assert(_Alignof(struct QC_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct QC_extra_size) == 8, "");
_Static_assert(_Alignof(struct QC_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(QC,b) == 16, "");
#endif
_Static_assert(sizeof(QD) == 2, "");
_Static_assert(_Alignof(QD) == 2, "");
_Static_assert(sizeof(struct QD_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct QD_extra_alignment) == 2, "");
_Static_assert(sizeof(struct QD_extra_packed) == 2, "");
_Static_assert(_Alignof(struct QD_extra_packed) == 1, "");
_Static_assert(sizeof(struct QD_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct QD_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct QD_extra_size) == 4, "");
_Static_assert(_Alignof(struct QD_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(QD,b) == 8, "");
#endif
_Static_assert(sizeof(EmptyAlignedLongLongMemb) == 0, "");
_Static_assert(_Alignof(EmptyAlignedLongLongMemb) == 8, "");
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_extra_alignment) == 8, "");
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_extra_packed) == 0, "");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_extra_packed) == 1, "");
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_extra_size) == 2, "");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_extra_size) == 1, "");
_Static_assert(sizeof(EmptyPackedAlignedLongLongMemb) == 0, "");
_Static_assert(_Alignof(EmptyPackedAlignedLongLongMemb) == 4, "");
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_extra_alignment) == 4, "");
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_extra_packed) == 0, "");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_extra_packed) == 1, "");
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_extra_size) == 2, "");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_extra_size) == 1, "");
// MAPPING|TWO|aarch64-generic-fuchsia-gnu:Clang|aarch64-generic-linux-android:Clang|aarch64-generic-freebsd-gnu:Clang|aarch64-generic-hermit-eabi:Clang|aarch64-generic-linux-gnu:Gcc|aarch64-generic-linux-musl:Gcc|aarch64-generic-netbsd-gnu:Clang|aarch64-generic-other-none:Clang|aarch64-generic-openbsd-gnu:Clang|arm-baseline-other-eabi:Clang|arm-baseline-other-eabihf:Clang|arm-baseline-linux-gnueabi:Gcc|arm-baseline-linux-gnueabihf:Gcc|arm-arm710t-linux-gnueabi:Gcc|arm-arm1020e-linux-gnueabi:Gcc|arm-arm1136j_s-freebsd-gnueabihf:Clang|arm-arm1136j_s-netbsd-eabihf:Clang|arm-baseline-other-eabi:Clang|arm-baseline-other-eabihf:Clang|arm-cortex_r4-linux-android:Clang|arm-cortex_r4-other-eabi:Clang|arm-cortex_r4-other-eabihf:Clang|arm-cortex_r4-freebsd-gnueabihf:Clang|arm-cortex_r4-linux-gnueabi:Gcc|arm-cortex_r4-linux-gnueabihf:Gcc|arm-cortex_r4-netbsd-eabihf:Clang|thumb-arm710t-other-eabi:Clang|thumb-cortex_m0-other-eabi:Clang|thumb-cortex_m4-other-eabihf:Clang|thumb-cortex_m4-other-eabi:Clang|thumb-cortex_m3-other-eabi:Clang|thumb-baseline-other-eabi:Clang|thumb-cortex_m33-other-eabihf:Clang|thumb-cortex_m33-other-eabi:Clang|END
// repr targets Aarch64Fuchsia|Some("aarch64-generic-fuchsia-gnu") Aarch64LinuxAndroid|Some("aarch64-generic-linux-android") Aarch64UnknownFreebsd|Some("aarch64-generic-freebsd-gnu") Aarch64UnknownHermit|Some("aarch64-generic-hermit-eabi") Aarch64UnknownLinuxGnu|Some("aarch64-generic-linux-gnu") Aarch64UnknownLinuxMusl|Some("aarch64-generic-linux-musl") Aarch64UnknownNetbsd|Some("aarch64-generic-netbsd-gnu") Aarch64UnknownNone|Some("aarch64-generic-other-none") Aarch64UnknownOpenbsd|Some("aarch64-generic-openbsd-gnu") Aarch64UnknownRedox|None Armebv7rUnknownNoneEabi|Some("arm-baseline-other-eabi") Armebv7rUnknownNoneEabihf|Some("arm-baseline-other-eabihf") ArmLinuxAndroideabi|None ArmUnknownLinuxGnueabi|Some("arm-baseline-linux-gnueabi") ArmUnknownLinuxGnueabihf|Some("arm-baseline-linux-gnueabihf") Armv4tUnknownLinuxGnueabi|Some("arm-arm710t-linux-gnueabi") Armv5teUnknownLinuxGnueabi|Some("arm-arm1020e-linux-gnueabi") Armv5teUnknownLinuxUclibcgnueabi|None Armv6UnknownFreebsdGnueabihf|Some("arm-arm1136j_s-freebsd-gnueabihf") Armv6UnknownNetbsdelfEabihf|Some("arm-arm1136j_s-netbsd-eabihf") Armv7aNoneEabi|Some("arm-baseline-other-eabi") Armv7aNoneEabihf|Some("arm-baseline-other-eabihf") Armv7NoneLinuxAndroid|Some("arm-cortex_r4-linux-android") Armv7rUnknownNoneEabi|Some("arm-cortex_r4-other-eabi") Armv7rUnknownNoneEabihf|Some("arm-cortex_r4-other-eabihf") Armv7UnknownFreebsdGnueabihf|Some("arm-cortex_r4-freebsd-gnueabihf") Armv7UnknownLinuxGnueabi|Some("arm-cortex_r4-linux-gnueabi") Armv7UnknownLinuxGnueabihf|Some("arm-cortex_r4-linux-gnueabihf") Armv7UnknownNetbsdelfEabihf|Some("arm-cortex_r4-netbsd-eabihf") Thumbv4tNoneEabi|Some("thumb-arm710t-other-eabi") Thumbv6mNoneEabi|Some("thumb-cortex_m0-other-eabi") Thumbv7emNoneEabihf|Some("thumb-cortex_m4-other-eabihf") Thumbv7emNoneEabi|Some("thumb-cortex_m4-other-eabi") Thumbv7mNoneEabi|Some("thumb-cortex_m3-other-eabi") Thumbv8mBaseNoneEabi|Some("thumb-baseline-other-eabi") Thumbv8mMainNoneEabihf|Some("thumb-cortex_m33-other-eabihf") Thumbv8mMainNoneEabi|Some("thumb-cortex_m33-other-eabi") 
#elif defined(TWO)
_Static_assert(sizeof(A) == 1, "");
_Static_assert(_Alignof(A) == 1, "");
_Static_assert(sizeof(struct A_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct A_extra_alignment) == 1, "");
_Static_assert(sizeof(struct A_extra_packed) == 1, "");
_Static_assert(_Alignof(struct A_extra_packed) == 1, "");
_Static_assert(sizeof(struct A_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct A_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A_extra_size) == 3, "");
_Static_assert(_Alignof(struct A_extra_size) == 1, "");
_Static_assert(sizeof(B) == 8, "");
_Static_assert(_Alignof(B) == 8, "");
_Static_assert(sizeof(struct B_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct B_extra_alignment) == 8, "");
_Static_assert(sizeof(struct B_extra_packed) == 8, "");
_Static_assert(_Alignof(struct B_extra_packed) == 1, "");
_Static_assert(sizeof(struct B_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct B_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B_extra_size) == 10, "");
_Static_assert(_Alignof(struct B_extra_size) == 1, "");
_Static_assert(sizeof(X) == 14, "");
_Static_assert(_Alignof(X) == 2, "");
_Static_assert(sizeof(struct X_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct X_extra_alignment) == 2, "");
_Static_assert(sizeof(struct X_extra_packed) == 14, "");
_Static_assert(_Alignof(struct X_extra_packed) == 1, "");
_Static_assert(sizeof(struct X_extra_required_alignment) == 15, "");
_Static_assert(_Alignof(struct X_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct X_extra_size) == 16, "");
_Static_assert(_Alignof(struct X_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(X,b) == 64, "");
_Static_assert(__builtin_bitoffsetof(X,c) == 80, "");
#endif
_Static_assert(sizeof(YA) == 16, "");
_Static_assert(_Alignof(YA) == 16, "");
_Static_assert(sizeof(struct YA_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct YA_extra_alignment) == 16, "");
_Static_assert(sizeof(struct YA_extra_packed) == 16, "");
_Static_assert(_Alignof(struct YA_extra_packed) == 1, "");
_Static_assert(sizeof(struct YA_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct YA_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct YA_extra_size) == 18, "");
_Static_assert(_Alignof(struct YA_extra_size) == 1, "");
_Static_assert(sizeof(YB) == 17, "");
_Static_assert(_Alignof(YB) == 1, "");
_Static_assert(sizeof(struct YB_extra_alignment) == 18, "");
_Static_assert(_Alignof(struct YB_extra_alignment) == 1, "");
_Static_assert(sizeof(struct YB_extra_packed) == 17, "");
_Static_assert(_Alignof(struct YB_extra_packed) == 1, "");
_Static_assert(sizeof(struct YB_extra_required_alignment) == 18, "");
_Static_assert(_Alignof(struct YB_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct YB_extra_size) == 19, "");
_Static_assert(_Alignof(struct YB_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(YB,b) == 8, "");
#endif
_Static_assert(sizeof(YC) == 8, "");
_Static_assert(_Alignof(YC) == 8, "");
_Static_assert(sizeof(struct YC_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct YC_extra_alignment) == 8, "");
_Static_assert(sizeof(struct YC_extra_packed) == 8, "");
_Static_assert(_Alignof(struct YC_extra_packed) == 1, "");
_Static_assert(sizeof(struct YC_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct YC_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct YC_extra_size) == 10, "");
_Static_assert(_Alignof(struct YC_extra_size) == 1, "");
_Static_assert(sizeof(YD) == 9, "");
_Static_assert(_Alignof(YD) == 1, "");
_Static_assert(sizeof(struct YD_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct YD_extra_alignment) == 1, "");
_Static_assert(sizeof(struct YD_extra_packed) == 9, "");
_Static_assert(_Alignof(struct YD_extra_packed) == 1, "");
_Static_assert(sizeof(struct YD_extra_required_alignment) == 10, "");
_Static_assert(_Alignof(struct YD_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct YD_extra_size) == 11, "");
_Static_assert(_Alignof(struct YD_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(YD,b) == 8, "");
#endif
_Static_assert(sizeof(YE) == 4, "");
_Static_assert(_Alignof(YE) == 4, "");
_Static_assert(sizeof(struct YE_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct YE_extra_alignment) == 4, "");
_Static_assert(sizeof(struct YE_extra_packed) == 4, "");
_Static_assert(_Alignof(struct YE_extra_packed) == 1, "");
_Static_assert(sizeof(struct YE_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct YE_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct YE_extra_size) == 6, "");
_Static_assert(_Alignof(struct YE_extra_size) == 1, "");
_Static_assert(sizeof(YF) == 5, "");
_Static_assert(_Alignof(YF) == 1, "");
_Static_assert(sizeof(struct YF_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct YF_extra_alignment) == 1, "");
_Static_assert(sizeof(struct YF_extra_packed) == 5, "");
_Static_assert(_Alignof(struct YF_extra_packed) == 1, "");
_Static_assert(sizeof(struct YF_extra_required_alignment) == 6, "");
_Static_assert(_Alignof(struct YF_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct YF_extra_size) == 7, "");
_Static_assert(_Alignof(struct YF_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(YF,b) == 8, "");
#endif
_Static_assert(sizeof(D0) == 16, "");
_Static_assert(_Alignof(D0) == 16, "");
_Static_assert(sizeof(struct D0_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct D0_extra_alignment) == 16, "");
_Static_assert(sizeof(struct D0_extra_packed) == 16, "");
_Static_assert(_Alignof(struct D0_extra_packed) == 1, "");
_Static_assert(sizeof(struct D0_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct D0_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct D0_extra_size) == 18, "");
_Static_assert(_Alignof(struct D0_extra_size) == 1, "");
_Static_assert(sizeof(RB0) == 8, "");
_Static_assert(_Alignof(RB0) == 8, "");
_Static_assert(sizeof(struct RB0_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct RB0_extra_alignment) == 8, "");
_Static_assert(sizeof(struct RB0_extra_packed) == 8, "");
_Static_assert(_Alignof(struct RB0_extra_packed) == 1, "");
_Static_assert(sizeof(struct RB0_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct RB0_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct RB0_extra_size) == 10, "");
_Static_assert(_Alignof(struct RB0_extra_size) == 1, "");
_Static_assert(sizeof(RC) == 2, "");
_Static_assert(_Alignof(RC) == 1, "");
_Static_assert(sizeof(struct RC_extra_alignment) == 3, "");
_Static_assert(_Alignof(struct RC_extra_alignment) == 1, "");
_Static_assert(sizeof(struct RC_extra_packed) == 2, "");
_Static_assert(_Alignof(struct RC_extra_packed) == 1, "");
_Static_assert(sizeof(struct RC_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct RC_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct RC_extra_size) == 4, "");
_Static_assert(_Alignof(struct RC_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(RC,c) == 8, "");
#endif
_Static_assert(sizeof(RE) == 3, "");
_Static_assert(_Alignof(RE) == 1, "");
_Static_assert(sizeof(struct RE_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct RE_extra_alignment) == 1, "");
_Static_assert(sizeof(struct RE_extra_packed) == 3, "");
_Static_assert(_Alignof(struct RE_extra_packed) == 1, "");
_Static_assert(sizeof(struct RE_extra_required_alignment) == 4, "");
_Static_assert(_Alignof(struct RE_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct RE_extra_size) == 5, "");
_Static_assert(_Alignof(struct RE_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(RE,c) == 8, "");
#endif
_Static_assert(sizeof(PA) == 4, "");
_Static_assert(_Alignof(PA) == 4, "");
_Static_assert(sizeof(struct PA_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct PA_extra_alignment) == 4, "");
_Static_assert(sizeof(struct PA_extra_packed) == 4, "");
_Static_assert(_Alignof(struct PA_extra_packed) == 1, "");
_Static_assert(sizeof(struct PA_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct PA_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct PA_extra_size) == 6, "");
_Static_assert(_Alignof(struct PA_extra_size) == 1, "");
_Static_assert(sizeof(PB) == 4, "");
_Static_assert(_Alignof(PB) == 8, "");
_Static_assert(sizeof(struct PB_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct PB_extra_alignment) == 8, "");
_Static_assert(sizeof(struct PB_extra_packed) == 4, "");
_Static_assert(_Alignof(struct PB_extra_packed) == 1, "");
_Static_assert(sizeof(struct PB_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct PB_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct PB_extra_size) == 6, "");
_Static_assert(_Alignof(struct PB_extra_size) == 1, "");
_Static_assert(sizeof(PC) == 5, "");
_Static_assert(_Alignof(PC) == 1, "");
_Static_assert(sizeof(struct PC_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct PC_extra_alignment) == 1, "");
_Static_assert(sizeof(struct PC_extra_packed) == 5, "");
_Static_assert(_Alignof(struct PC_extra_packed) == 1, "");
_Static_assert(sizeof(struct PC_extra_required_alignment) == 6, "");
_Static_assert(_Alignof(struct PC_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct PC_extra_size) == 7, "");
_Static_assert(_Alignof(struct PC_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(PC,x) == 8, "");
#endif
_Static_assert(sizeof(PD) == 4, "");
_Static_assert(_Alignof(PD) == 8, "");
_Static_assert(sizeof(struct PD_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct PD_extra_alignment) == 8, "");
_Static_assert(sizeof(struct PD_extra_packed) == 4, "");
_Static_assert(_Alignof(struct PD_extra_packed) == 1, "");
_Static_assert(sizeof(struct PD_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct PD_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct PD_extra_size) == 6, "");
_Static_assert(_Alignof(struct PD_extra_size) == 1, "");
_Static_assert(sizeof(PE) == 5, "");
_Static_assert(_Alignof(PE) == 1, "");
_Static_assert(sizeof(struct PE_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct PE_extra_alignment) == 1, "");
_Static_assert(sizeof(struct PE_extra_packed) == 5, "");
_Static_assert(_Alignof(struct PE_extra_packed) == 1, "");
_Static_assert(sizeof(struct PE_extra_required_alignment) == 6, "");
_Static_assert(_Alignof(struct PE_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct PE_extra_size) == 7, "");
_Static_assert(_Alignof(struct PE_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(PE,x) == 8, "");
#endif
_Static_assert(sizeof(QA) == 4, "");
_Static_assert(_Alignof(QA) == 2, "");
_Static_assert(sizeof(struct QA_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct QA_extra_alignment) == 2, "");
_Static_assert(sizeof(struct QA_extra_packed) == 4, "");
_Static_assert(_Alignof(struct QA_extra_packed) == 1, "");
_Static_assert(sizeof(struct QA_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct QA_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct QA_extra_size) == 6, "");
_Static_assert(_Alignof(struct QA_extra_size) == 1, "");
_Static_assert(sizeof(QB) == 5, "");
_Static_assert(_Alignof(QB) == 1, "");
_Static_assert(sizeof(struct QB_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct QB_extra_alignment) == 1, "");
_Static_assert(sizeof(struct QB_extra_packed) == 5, "");
_Static_assert(_Alignof(struct QB_extra_packed) == 1, "");
_Static_assert(sizeof(struct QB_extra_required_alignment) == 6, "");
_Static_assert(_Alignof(struct QB_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct QB_extra_size) == 7, "");
_Static_assert(_Alignof(struct QB_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(QB,b) == 8, "");
#endif
_Static_assert(sizeof(QC) == 6, "");
_Static_assert(_Alignof(QC) == 2, "");
_Static_assert(sizeof(struct QC_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct QC_extra_alignment) == 2, "");
_Static_assert(sizeof(struct QC_extra_packed) == 6, "");
_Static_assert(_Alignof(struct QC_extra_packed) == 1, "");
_Static_assert(sizeof(struct QC_extra_required_alignment) == 7, "");
_Static_assert(_Alignof(struct QC_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct QC_extra_size) == 8, "");
_Static_assert(_Alignof(struct QC_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(QC,b) == 16, "");
#endif
_Static_assert(sizeof(QD) == 2, "");
_Static_assert(_Alignof(QD) == 2, "");
_Static_assert(sizeof(struct QD_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct QD_extra_alignment) == 2, "");
_Static_assert(sizeof(struct QD_extra_packed) == 2, "");
_Static_assert(_Alignof(struct QD_extra_packed) == 1, "");
_Static_assert(sizeof(struct QD_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct QD_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct QD_extra_size) == 4, "");
_Static_assert(_Alignof(struct QD_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(QD,b) == 8, "");
#endif
_Static_assert(sizeof(EmptyAlignedLongLongMemb) == 0, "");
_Static_assert(_Alignof(EmptyAlignedLongLongMemb) == 8, "");
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_extra_alignment) == 8, "");
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_extra_packed) == 0, "");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_extra_packed) == 1, "");
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_extra_size) == 2, "");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_extra_size) == 1, "");
_Static_assert(sizeof(EmptyPackedAlignedLongLongMemb) == 0, "");
_Static_assert(_Alignof(EmptyPackedAlignedLongLongMemb) == 4, "");
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_extra_alignment) == 4, "");
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_extra_packed) == 0, "");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_extra_packed) == 1, "");
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_extra_size) == 2, "");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_extra_size) == 1, "");
// MAPPING|THREE|aarch64-generic-windows-msvc:Msvc|x86_64-x86_64-windows-msvc:Msvc|x86_64-x86_64-uefi-msvc:Msvc|END
// repr targets Aarch64PcWindowsMsvc|Some("aarch64-generic-windows-msvc") X86_64PcWindowsMsvc|Some("x86_64-x86_64-windows-msvc") X86_64UnknownWindows|Some("x86_64-x86_64-uefi-msvc") 
#elif defined(THREE)
_Static_assert(sizeof(A) == 1, "");
_Static_assert(_Alignof(A) == 1, "");
_Static_assert(sizeof(struct A_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct A_extra_alignment) == 1, "");
_Static_assert(sizeof(struct A_extra_packed) == 1, "");
_Static_assert(_Alignof(struct A_extra_packed) == 1, "");
_Static_assert(sizeof(struct A_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct A_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A_extra_size) == 3, "");
_Static_assert(_Alignof(struct A_extra_size) == 1, "");
_Static_assert(sizeof(B) == 8, "");
_Static_assert(_Alignof(B) == 8, "");
_Static_assert(sizeof(struct B_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct B_extra_alignment) == 8, "");
_Static_assert(sizeof(struct B_extra_packed) == 8, "");
_Static_assert(_Alignof(struct B_extra_packed) == 1, "");
_Static_assert(sizeof(struct B_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct B_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B_extra_size) == 10, "");
_Static_assert(_Alignof(struct B_extra_size) == 1, "");
_Static_assert(sizeof(X) == 16, "");
_Static_assert(_Alignof(X) == 4, "");
_Static_assert(sizeof(struct X_extra_alignment) == 20, "");
_Static_assert(_Alignof(struct X_extra_alignment) == 4, "");
_Static_assert(sizeof(struct X_extra_packed) == 16, "");
_Static_assert(_Alignof(struct X_extra_packed) == 1, "");
_Static_assert(sizeof(struct X_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct X_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct X_extra_size) == 18, "");
_Static_assert(_Alignof(struct X_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(X,b) == 64, "");
_Static_assert(__builtin_bitoffsetof(X,c) == 80, "");
#endif
_Static_assert(sizeof(YA) == 32, "");
_Static_assert(_Alignof(YA) == 32, "");
_Static_assert(sizeof(struct YA_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct YA_extra_alignment) == 32, "");
_Static_assert(sizeof(struct YA_extra_packed) == 32, "");
_Static_assert(_Alignof(struct YA_extra_packed) == 1, "");
_Static_assert(sizeof(struct YA_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct YA_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct YA_extra_size) == 34, "");
_Static_assert(_Alignof(struct YA_extra_size) == 1, "");
_Static_assert(sizeof(YB) == 33, "");
_Static_assert(_Alignof(YB) == 1, "");
_Static_assert(sizeof(struct YB_extra_alignment) == 34, "");
_Static_assert(_Alignof(struct YB_extra_alignment) == 1, "");
_Static_assert(sizeof(struct YB_extra_packed) == 33, "");
_Static_assert(_Alignof(struct YB_extra_packed) == 1, "");
_Static_assert(sizeof(struct YB_extra_required_alignment) == 34, "");
_Static_assert(_Alignof(struct YB_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct YB_extra_size) == 35, "");
_Static_assert(_Alignof(struct YB_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(YB,b) == 8, "");
#endif
_Static_assert(sizeof(YC) == 8, "");
_Static_assert(_Alignof(YC) == 32, "");
_Static_assert(sizeof(struct YC_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct YC_extra_alignment) == 32, "");
_Static_assert(sizeof(struct YC_extra_packed) == 8, "");
_Static_assert(_Alignof(struct YC_extra_packed) == 1, "");
_Static_assert(sizeof(struct YC_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct YC_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct YC_extra_size) == 10, "");
_Static_assert(_Alignof(struct YC_extra_size) == 1, "");
_Static_assert(sizeof(YD) == 9, "");
_Static_assert(_Alignof(YD) == 1, "");
_Static_assert(sizeof(struct YD_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct YD_extra_alignment) == 1, "");
_Static_assert(sizeof(struct YD_extra_packed) == 9, "");
_Static_assert(_Alignof(struct YD_extra_packed) == 1, "");
_Static_assert(sizeof(struct YD_extra_required_alignment) == 10, "");
_Static_assert(_Alignof(struct YD_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct YD_extra_size) == 11, "");
_Static_assert(_Alignof(struct YD_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(YD,b) == 8, "");
#endif
_Static_assert(sizeof(YE) == 4, "");
_Static_assert(_Alignof(YE) == 32, "");
_Static_assert(sizeof(struct YE_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct YE_extra_alignment) == 32, "");
_Static_assert(sizeof(struct YE_extra_packed) == 4, "");
_Static_assert(_Alignof(struct YE_extra_packed) == 1, "");
_Static_assert(sizeof(struct YE_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct YE_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct YE_extra_size) == 6, "");
_Static_assert(_Alignof(struct YE_extra_size) == 1, "");
_Static_assert(sizeof(YF) == 5, "");
_Static_assert(_Alignof(YF) == 1, "");
_Static_assert(sizeof(struct YF_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct YF_extra_alignment) == 1, "");
_Static_assert(sizeof(struct YF_extra_packed) == 5, "");
_Static_assert(_Alignof(struct YF_extra_packed) == 1, "");
_Static_assert(sizeof(struct YF_extra_required_alignment) == 6, "");
_Static_assert(_Alignof(struct YF_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct YF_extra_size) == 7, "");
_Static_assert(_Alignof(struct YF_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(YF,b) == 8, "");
#endif
_Static_assert(sizeof(D0) == 16, "");
_Static_assert(_Alignof(D0) == 16, "");
_Static_assert(sizeof(struct D0_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct D0_extra_alignment) == 16, "");
_Static_assert(sizeof(struct D0_extra_packed) == 16, "");
_Static_assert(_Alignof(struct D0_extra_packed) == 1, "");
_Static_assert(sizeof(struct D0_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct D0_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct D0_extra_size) == 18, "");
_Static_assert(_Alignof(struct D0_extra_size) == 1, "");
_Static_assert(sizeof(RB0) == 8, "");
_Static_assert(_Alignof(RB0) == 1024, "");
_Static_assert(sizeof(struct RB0_extra_alignment) == 2048, "");
_Static_assert(_Alignof(struct RB0_extra_alignment) == 1024, "");
_Static_assert(sizeof(struct RB0_extra_packed) == 8, "");
_Static_assert(_Alignof(struct RB0_extra_packed) == 1, "");
_Static_assert(sizeof(struct RB0_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct RB0_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct RB0_extra_size) == 10, "");
_Static_assert(_Alignof(struct RB0_extra_size) == 1, "");
_Static_assert(sizeof(RC) == 1028, "");
_Static_assert(_Alignof(RC) == 1024, "");
_Static_assert(sizeof(struct RC_extra_alignment) == 3072, "");
_Static_assert(_Alignof(struct RC_extra_alignment) == 1024, "");
_Static_assert(sizeof(struct RC_extra_packed) == 1028, "");
_Static_assert(_Alignof(struct RC_extra_packed) == 1, "");
_Static_assert(sizeof(struct RC_extra_required_alignment) == 1029, "");
_Static_assert(_Alignof(struct RC_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct RC_extra_size) == 1030, "");
_Static_assert(_Alignof(struct RC_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(RC,c) == 8192, "");
#endif
_Static_assert(sizeof(RE) == 1029, "");
_Static_assert(_Alignof(RE) == 1, "");
_Static_assert(sizeof(struct RE_extra_alignment) == 1030, "");
_Static_assert(_Alignof(struct RE_extra_alignment) == 1, "");
_Static_assert(sizeof(struct RE_extra_packed) == 1029, "");
_Static_assert(_Alignof(struct RE_extra_packed) == 1, "");
_Static_assert(sizeof(struct RE_extra_required_alignment) == 1030, "");
_Static_assert(_Alignof(struct RE_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct RE_extra_size) == 1031, "");
_Static_assert(_Alignof(struct RE_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(RE,c) == 8, "");
#endif
_Static_assert(sizeof(PA) == 4, "");
_Static_assert(_Alignof(PA) == 4, "");
_Static_assert(sizeof(struct PA_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct PA_extra_alignment) == 4, "");
_Static_assert(sizeof(struct PA_extra_packed) == 4, "");
_Static_assert(_Alignof(struct PA_extra_packed) == 1, "");
_Static_assert(sizeof(struct PA_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct PA_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct PA_extra_size) == 6, "");
_Static_assert(_Alignof(struct PA_extra_size) == 1, "");
_Static_assert(sizeof(PB) == 4, "");
_Static_assert(_Alignof(PB) == 8, "");
_Static_assert(sizeof(struct PB_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct PB_extra_alignment) == 8, "");
_Static_assert(sizeof(struct PB_extra_packed) == 4, "");
_Static_assert(_Alignof(struct PB_extra_packed) == 1, "");
_Static_assert(sizeof(struct PB_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct PB_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct PB_extra_size) == 6, "");
_Static_assert(_Alignof(struct PB_extra_size) == 1, "");
_Static_assert(sizeof(PC) == 16, "");
_Static_assert(_Alignof(PC) == 8, "");
_Static_assert(sizeof(struct PC_extra_alignment) == 24, "");
_Static_assert(_Alignof(struct PC_extra_alignment) == 8, "");
_Static_assert(sizeof(struct PC_extra_packed) == 16, "");
_Static_assert(_Alignof(struct PC_extra_packed) == 1, "");
_Static_assert(sizeof(struct PC_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct PC_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct PC_extra_size) == 18, "");
_Static_assert(_Alignof(struct PC_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(PC,x) == 64, "");
#endif
_Static_assert(sizeof(PD) == 4, "");
_Static_assert(_Alignof(PD) == 8, "");
_Static_assert(sizeof(struct PD_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct PD_extra_alignment) == 8, "");
_Static_assert(sizeof(struct PD_extra_packed) == 4, "");
_Static_assert(_Alignof(struct PD_extra_packed) == 1, "");
_Static_assert(sizeof(struct PD_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct PD_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct PD_extra_size) == 6, "");
_Static_assert(_Alignof(struct PD_extra_size) == 1, "");
_Static_assert(sizeof(PE) == 16, "");
_Static_assert(_Alignof(PE) == 8, "");
_Static_assert(sizeof(struct PE_extra_alignment) == 24, "");
_Static_assert(_Alignof(struct PE_extra_alignment) == 8, "");
_Static_assert(sizeof(struct PE_extra_packed) == 16, "");
_Static_assert(_Alignof(struct PE_extra_packed) == 1, "");
_Static_assert(sizeof(struct PE_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct PE_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct PE_extra_size) == 18, "");
_Static_assert(_Alignof(struct PE_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(PE,x) == 64, "");
#endif
_Static_assert(sizeof(QA) == 4, "");
_Static_assert(_Alignof(QA) == 4, "");
_Static_assert(sizeof(struct QA_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct QA_extra_alignment) == 4, "");
_Static_assert(sizeof(struct QA_extra_packed) == 4, "");
_Static_assert(_Alignof(struct QA_extra_packed) == 1, "");
_Static_assert(sizeof(struct QA_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct QA_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct QA_extra_size) == 6, "");
_Static_assert(_Alignof(struct QA_extra_size) == 1, "");
_Static_assert(sizeof(QB) == 6, "");
_Static_assert(_Alignof(QB) == 2, "");
_Static_assert(sizeof(struct QB_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct QB_extra_alignment) == 2, "");
_Static_assert(sizeof(struct QB_extra_packed) == 6, "");
_Static_assert(_Alignof(struct QB_extra_packed) == 1, "");
_Static_assert(sizeof(struct QB_extra_required_alignment) == 7, "");
_Static_assert(_Alignof(struct QB_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct QB_extra_size) == 8, "");
_Static_assert(_Alignof(struct QB_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(QB,b) == 16, "");
#endif
_Static_assert(sizeof(QC) == 8, "");
_Static_assert(_Alignof(QC) == 4, "");
_Static_assert(sizeof(struct QC_extra_alignment) == 12, "");
_Static_assert(_Alignof(struct QC_extra_alignment) == 4, "");
_Static_assert(sizeof(struct QC_extra_packed) == 8, "");
_Static_assert(_Alignof(struct QC_extra_packed) == 1, "");
_Static_assert(sizeof(struct QC_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct QC_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct QC_extra_size) == 10, "");
_Static_assert(_Alignof(struct QC_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(QC,b) == 32, "");
#endif
_Static_assert(sizeof(QD) == 8, "");
_Static_assert(_Alignof(QD) == 4, "");
_Static_assert(sizeof(struct QD_extra_alignment) == 12, "");
_Static_assert(_Alignof(struct QD_extra_alignment) == 4, "");
_Static_assert(sizeof(struct QD_extra_packed) == 8, "");
_Static_assert(_Alignof(struct QD_extra_packed) == 1, "");
_Static_assert(sizeof(struct QD_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct QD_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct QD_extra_size) == 10, "");
_Static_assert(_Alignof(struct QD_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(QD,b) == 32, "");
#endif
_Static_assert(sizeof(EmptyAlignedLongLongMemb) == 4, "");
_Static_assert(_Alignof(EmptyAlignedLongLongMemb) == 8, "");
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_extra_alignment) == 8, "");
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_extra_packed) == 4, "");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_extra_packed) == 1, "");
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_extra_size) == 6, "");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_extra_size) == 1, "");
_Static_assert(sizeof(EmptyPackedAlignedLongLongMemb) == 4, "");
_Static_assert(_Alignof(EmptyPackedAlignedLongLongMemb) == 4, "");
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_extra_alignment) == 4, "");
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_extra_packed) == 4, "");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_extra_packed) == 1, "");
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_extra_size) == 6, "");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_extra_size) == 1, "");
// MAPPING|FOUR|arm-cortex_r4-ios-none:Clang|arm-baseline-ios-none:Clang|END
// repr targets Armv7AppleIos|Some("arm-cortex_r4-ios-none") Armv7sAppleIos|Some("arm-baseline-ios-none") 
#elif defined(FOUR)
_Static_assert(sizeof(A) == 1, "");
_Static_assert(_Alignof(A) == 1, "");
_Static_assert(sizeof(struct A_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct A_extra_alignment) == 1, "");
_Static_assert(sizeof(struct A_extra_packed) == 1, "");
_Static_assert(_Alignof(struct A_extra_packed) == 1, "");
_Static_assert(sizeof(struct A_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct A_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A_extra_size) == 3, "");
_Static_assert(_Alignof(struct A_extra_size) == 1, "");
_Static_assert(sizeof(B) == 8, "");
_Static_assert(_Alignof(B) == 4, "");
_Static_assert(sizeof(struct B_extra_alignment) == 12, "");
_Static_assert(_Alignof(struct B_extra_alignment) == 4, "");
_Static_assert(sizeof(struct B_extra_packed) == 8, "");
_Static_assert(_Alignof(struct B_extra_packed) == 1, "");
_Static_assert(sizeof(struct B_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct B_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B_extra_size) == 10, "");
_Static_assert(_Alignof(struct B_extra_size) == 1, "");
_Static_assert(sizeof(X) == 14, "");
_Static_assert(_Alignof(X) == 2, "");
_Static_assert(sizeof(struct X_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct X_extra_alignment) == 2, "");
_Static_assert(sizeof(struct X_extra_packed) == 14, "");
_Static_assert(_Alignof(struct X_extra_packed) == 1, "");
_Static_assert(sizeof(struct X_extra_required_alignment) == 15, "");
_Static_assert(_Alignof(struct X_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct X_extra_size) == 16, "");
_Static_assert(_Alignof(struct X_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(X,b) == 64, "");
_Static_assert(__builtin_bitoffsetof(X,c) == 80, "");
#endif
_Static_assert(sizeof(YA) == 16, "");
_Static_assert(_Alignof(YA) == 16, "");
_Static_assert(sizeof(struct YA_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct YA_extra_alignment) == 16, "");
_Static_assert(sizeof(struct YA_extra_packed) == 16, "");
_Static_assert(_Alignof(struct YA_extra_packed) == 1, "");
_Static_assert(sizeof(struct YA_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct YA_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct YA_extra_size) == 18, "");
_Static_assert(_Alignof(struct YA_extra_size) == 1, "");
_Static_assert(sizeof(YB) == 17, "");
_Static_assert(_Alignof(YB) == 1, "");
_Static_assert(sizeof(struct YB_extra_alignment) == 18, "");
_Static_assert(_Alignof(struct YB_extra_alignment) == 1, "");
_Static_assert(sizeof(struct YB_extra_packed) == 17, "");
_Static_assert(_Alignof(struct YB_extra_packed) == 1, "");
_Static_assert(sizeof(struct YB_extra_required_alignment) == 18, "");
_Static_assert(_Alignof(struct YB_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct YB_extra_size) == 19, "");
_Static_assert(_Alignof(struct YB_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(YB,b) == 8, "");
#endif
_Static_assert(sizeof(YC) == 8, "");
_Static_assert(_Alignof(YC) == 8, "");
_Static_assert(sizeof(struct YC_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct YC_extra_alignment) == 8, "");
_Static_assert(sizeof(struct YC_extra_packed) == 8, "");
_Static_assert(_Alignof(struct YC_extra_packed) == 1, "");
_Static_assert(sizeof(struct YC_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct YC_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct YC_extra_size) == 10, "");
_Static_assert(_Alignof(struct YC_extra_size) == 1, "");
_Static_assert(sizeof(YD) == 9, "");
_Static_assert(_Alignof(YD) == 1, "");
_Static_assert(sizeof(struct YD_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct YD_extra_alignment) == 1, "");
_Static_assert(sizeof(struct YD_extra_packed) == 9, "");
_Static_assert(_Alignof(struct YD_extra_packed) == 1, "");
_Static_assert(sizeof(struct YD_extra_required_alignment) == 10, "");
_Static_assert(_Alignof(struct YD_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct YD_extra_size) == 11, "");
_Static_assert(_Alignof(struct YD_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(YD,b) == 8, "");
#endif
_Static_assert(sizeof(YE) == 4, "");
_Static_assert(_Alignof(YE) == 4, "");
_Static_assert(sizeof(struct YE_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct YE_extra_alignment) == 4, "");
_Static_assert(sizeof(struct YE_extra_packed) == 4, "");
_Static_assert(_Alignof(struct YE_extra_packed) == 1, "");
_Static_assert(sizeof(struct YE_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct YE_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct YE_extra_size) == 6, "");
_Static_assert(_Alignof(struct YE_extra_size) == 1, "");
_Static_assert(sizeof(YF) == 5, "");
_Static_assert(_Alignof(YF) == 1, "");
_Static_assert(sizeof(struct YF_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct YF_extra_alignment) == 1, "");
_Static_assert(sizeof(struct YF_extra_packed) == 5, "");
_Static_assert(_Alignof(struct YF_extra_packed) == 1, "");
_Static_assert(sizeof(struct YF_extra_required_alignment) == 6, "");
_Static_assert(_Alignof(struct YF_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct YF_extra_size) == 7, "");
_Static_assert(_Alignof(struct YF_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(YF,b) == 8, "");
#endif
_Static_assert(sizeof(D0) == 16, "");
_Static_assert(_Alignof(D0) == 16, "");
_Static_assert(sizeof(struct D0_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct D0_extra_alignment) == 16, "");
_Static_assert(sizeof(struct D0_extra_packed) == 16, "");
_Static_assert(_Alignof(struct D0_extra_packed) == 1, "");
_Static_assert(sizeof(struct D0_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct D0_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct D0_extra_size) == 18, "");
_Static_assert(_Alignof(struct D0_extra_size) == 1, "");
_Static_assert(sizeof(RB0) == 8, "");
_Static_assert(_Alignof(RB0) == 8, "");
_Static_assert(sizeof(struct RB0_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct RB0_extra_alignment) == 8, "");
_Static_assert(sizeof(struct RB0_extra_packed) == 8, "");
_Static_assert(_Alignof(struct RB0_extra_packed) == 1, "");
_Static_assert(sizeof(struct RB0_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct RB0_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct RB0_extra_size) == 10, "");
_Static_assert(_Alignof(struct RB0_extra_size) == 1, "");
_Static_assert(sizeof(RC) == 2, "");
_Static_assert(_Alignof(RC) == 1, "");
_Static_assert(sizeof(struct RC_extra_alignment) == 3, "");
_Static_assert(_Alignof(struct RC_extra_alignment) == 1, "");
_Static_assert(sizeof(struct RC_extra_packed) == 2, "");
_Static_assert(_Alignof(struct RC_extra_packed) == 1, "");
_Static_assert(sizeof(struct RC_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct RC_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct RC_extra_size) == 4, "");
_Static_assert(_Alignof(struct RC_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(RC,c) == 8, "");
#endif
_Static_assert(sizeof(RE) == 3, "");
_Static_assert(_Alignof(RE) == 1, "");
_Static_assert(sizeof(struct RE_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct RE_extra_alignment) == 1, "");
_Static_assert(sizeof(struct RE_extra_packed) == 3, "");
_Static_assert(_Alignof(struct RE_extra_packed) == 1, "");
_Static_assert(sizeof(struct RE_extra_required_alignment) == 4, "");
_Static_assert(_Alignof(struct RE_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct RE_extra_size) == 5, "");
_Static_assert(_Alignof(struct RE_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(RE,c) == 8, "");
#endif
_Static_assert(sizeof(PA) == 4, "");
_Static_assert(_Alignof(PA) == 4, "");
_Static_assert(sizeof(struct PA_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct PA_extra_alignment) == 4, "");
_Static_assert(sizeof(struct PA_extra_packed) == 4, "");
_Static_assert(_Alignof(struct PA_extra_packed) == 1, "");
_Static_assert(sizeof(struct PA_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct PA_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct PA_extra_size) == 6, "");
_Static_assert(_Alignof(struct PA_extra_size) == 1, "");
_Static_assert(sizeof(PB) == 4, "");
_Static_assert(_Alignof(PB) == 8, "");
_Static_assert(sizeof(struct PB_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct PB_extra_alignment) == 8, "");
_Static_assert(sizeof(struct PB_extra_packed) == 4, "");
_Static_assert(_Alignof(struct PB_extra_packed) == 1, "");
_Static_assert(sizeof(struct PB_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct PB_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct PB_extra_size) == 6, "");
_Static_assert(_Alignof(struct PB_extra_size) == 1, "");
_Static_assert(sizeof(PC) == 5, "");
_Static_assert(_Alignof(PC) == 1, "");
_Static_assert(sizeof(struct PC_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct PC_extra_alignment) == 1, "");
_Static_assert(sizeof(struct PC_extra_packed) == 5, "");
_Static_assert(_Alignof(struct PC_extra_packed) == 1, "");
_Static_assert(sizeof(struct PC_extra_required_alignment) == 6, "");
_Static_assert(_Alignof(struct PC_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct PC_extra_size) == 7, "");
_Static_assert(_Alignof(struct PC_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(PC,x) == 8, "");
#endif
_Static_assert(sizeof(PD) == 4, "");
_Static_assert(_Alignof(PD) == 8, "");
_Static_assert(sizeof(struct PD_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct PD_extra_alignment) == 8, "");
_Static_assert(sizeof(struct PD_extra_packed) == 4, "");
_Static_assert(_Alignof(struct PD_extra_packed) == 1, "");
_Static_assert(sizeof(struct PD_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct PD_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct PD_extra_size) == 6, "");
_Static_assert(_Alignof(struct PD_extra_size) == 1, "");
_Static_assert(sizeof(PE) == 5, "");
_Static_assert(_Alignof(PE) == 1, "");
_Static_assert(sizeof(struct PE_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct PE_extra_alignment) == 1, "");
_Static_assert(sizeof(struct PE_extra_packed) == 5, "");
_Static_assert(_Alignof(struct PE_extra_packed) == 1, "");
_Static_assert(sizeof(struct PE_extra_required_alignment) == 6, "");
_Static_assert(_Alignof(struct PE_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct PE_extra_size) == 7, "");
_Static_assert(_Alignof(struct PE_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(PE,x) == 8, "");
#endif
_Static_assert(sizeof(QA) == 4, "");
_Static_assert(_Alignof(QA) == 2, "");
_Static_assert(sizeof(struct QA_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct QA_extra_alignment) == 2, "");
_Static_assert(sizeof(struct QA_extra_packed) == 4, "");
_Static_assert(_Alignof(struct QA_extra_packed) == 1, "");
_Static_assert(sizeof(struct QA_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct QA_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct QA_extra_size) == 6, "");
_Static_assert(_Alignof(struct QA_extra_size) == 1, "");
_Static_assert(sizeof(QB) == 5, "");
_Static_assert(_Alignof(QB) == 1, "");
_Static_assert(sizeof(struct QB_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct QB_extra_alignment) == 1, "");
_Static_assert(sizeof(struct QB_extra_packed) == 5, "");
_Static_assert(_Alignof(struct QB_extra_packed) == 1, "");
_Static_assert(sizeof(struct QB_extra_required_alignment) == 6, "");
_Static_assert(_Alignof(struct QB_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct QB_extra_size) == 7, "");
_Static_assert(_Alignof(struct QB_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(QB,b) == 8, "");
#endif
_Static_assert(sizeof(QC) == 6, "");
_Static_assert(_Alignof(QC) == 2, "");
_Static_assert(sizeof(struct QC_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct QC_extra_alignment) == 2, "");
_Static_assert(sizeof(struct QC_extra_packed) == 6, "");
_Static_assert(_Alignof(struct QC_extra_packed) == 1, "");
_Static_assert(sizeof(struct QC_extra_required_alignment) == 7, "");
_Static_assert(_Alignof(struct QC_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct QC_extra_size) == 8, "");
_Static_assert(_Alignof(struct QC_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(QC,b) == 16, "");
#endif
_Static_assert(sizeof(QD) == 2, "");
_Static_assert(_Alignof(QD) == 1, "");
_Static_assert(sizeof(struct QD_extra_alignment) == 3, "");
_Static_assert(_Alignof(struct QD_extra_alignment) == 1, "");
_Static_assert(sizeof(struct QD_extra_packed) == 2, "");
_Static_assert(_Alignof(struct QD_extra_packed) == 1, "");
_Static_assert(sizeof(struct QD_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct QD_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct QD_extra_size) == 4, "");
_Static_assert(_Alignof(struct QD_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(QD,b) == 8, "");
#endif
_Static_assert(sizeof(EmptyAlignedLongLongMemb) == 0, "");
_Static_assert(_Alignof(EmptyAlignedLongLongMemb) == 4, "");
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_extra_alignment) == 4, "");
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_extra_packed) == 0, "");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_extra_packed) == 1, "");
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_extra_size) == 2, "");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_extra_size) == 1, "");
_Static_assert(sizeof(EmptyPackedAlignedLongLongMemb) == 0, "");
_Static_assert(_Alignof(EmptyPackedAlignedLongLongMemb) == 4, "");
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_extra_alignment) == 4, "");
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_extra_packed) == 0, "");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_extra_packed) == 1, "");
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_extra_size) == 2, "");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_extra_size) == 1, "");
// MAPPING|FIVE|avr-avr2-other-eabi:Gcc|END
// repr targets AvrUnknownUnknown|Some("avr-avr2-other-eabi") 
#elif defined(FIVE)
_Static_assert(sizeof(A) == 1, "");
_Static_assert(_Alignof(A) == 1, "");
_Static_assert(sizeof(struct A_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct A_extra_alignment) == 1, "");
_Static_assert(sizeof(struct A_extra_packed) == 1, "");
_Static_assert(_Alignof(struct A_extra_packed) == 1, "");
_Static_assert(sizeof(struct A_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct A_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A_extra_size) == 3, "");
_Static_assert(_Alignof(struct A_extra_size) == 1, "");
_Static_assert(sizeof(B) == 8, "");
_Static_assert(_Alignof(B) == 4, "");
_Static_assert(sizeof(struct B_extra_alignment) == 12, "");
_Static_assert(_Alignof(struct B_extra_alignment) == 4, "");
_Static_assert(sizeof(struct B_extra_packed) == 8, "");
_Static_assert(_Alignof(struct B_extra_packed) == 1, "");
_Static_assert(sizeof(struct B_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct B_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B_extra_size) == 10, "");
_Static_assert(_Alignof(struct B_extra_size) == 1, "");
_Static_assert(sizeof(X) == 12, "");
_Static_assert(_Alignof(X) == 2, "");
_Static_assert(sizeof(struct X_extra_alignment) == 14, "");
_Static_assert(_Alignof(struct X_extra_alignment) == 2, "");
_Static_assert(sizeof(struct X_extra_packed) == 12, "");
_Static_assert(_Alignof(struct X_extra_packed) == 1, "");
_Static_assert(sizeof(struct X_extra_required_alignment) == 13, "");
_Static_assert(_Alignof(struct X_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct X_extra_size) == 14, "");
_Static_assert(_Alignof(struct X_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(X,b) == 64, "");
_Static_assert(__builtin_bitoffsetof(X,c) == 72, "");
#endif
_Static_assert(sizeof(YA) == 16, "");
_Static_assert(_Alignof(YA) == 16, "");
_Static_assert(sizeof(struct YA_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct YA_extra_alignment) == 16, "");
_Static_assert(sizeof(struct YA_extra_packed) == 16, "");
_Static_assert(_Alignof(struct YA_extra_packed) == 1, "");
_Static_assert(sizeof(struct YA_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct YA_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct YA_extra_size) == 18, "");
_Static_assert(_Alignof(struct YA_extra_size) == 1, "");
_Static_assert(sizeof(YB) == 17, "");
_Static_assert(_Alignof(YB) == 1, "");
_Static_assert(sizeof(struct YB_extra_alignment) == 18, "");
_Static_assert(_Alignof(struct YB_extra_alignment) == 1, "");
_Static_assert(sizeof(struct YB_extra_packed) == 17, "");
_Static_assert(_Alignof(struct YB_extra_packed) == 1, "");
_Static_assert(sizeof(struct YB_extra_required_alignment) == 18, "");
_Static_assert(_Alignof(struct YB_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct YB_extra_size) == 19, "");
_Static_assert(_Alignof(struct YB_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(YB,b) == 8, "");
#endif
_Static_assert(sizeof(YC) == 8, "");
_Static_assert(_Alignof(YC) == 8, "");
_Static_assert(sizeof(struct YC_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct YC_extra_alignment) == 8, "");
_Static_assert(sizeof(struct YC_extra_packed) == 8, "");
_Static_assert(_Alignof(struct YC_extra_packed) == 1, "");
_Static_assert(sizeof(struct YC_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct YC_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct YC_extra_size) == 10, "");
_Static_assert(_Alignof(struct YC_extra_size) == 1, "");
_Static_assert(sizeof(YD) == 9, "");
_Static_assert(_Alignof(YD) == 1, "");
_Static_assert(sizeof(struct YD_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct YD_extra_alignment) == 1, "");
_Static_assert(sizeof(struct YD_extra_packed) == 9, "");
_Static_assert(_Alignof(struct YD_extra_packed) == 1, "");
_Static_assert(sizeof(struct YD_extra_required_alignment) == 10, "");
_Static_assert(_Alignof(struct YD_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct YD_extra_size) == 11, "");
_Static_assert(_Alignof(struct YD_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(YD,b) == 8, "");
#endif
_Static_assert(sizeof(YE) == 4, "");
_Static_assert(_Alignof(YE) == 4, "");
_Static_assert(sizeof(struct YE_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct YE_extra_alignment) == 4, "");
_Static_assert(sizeof(struct YE_extra_packed) == 4, "");
_Static_assert(_Alignof(struct YE_extra_packed) == 1, "");
_Static_assert(sizeof(struct YE_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct YE_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct YE_extra_size) == 6, "");
_Static_assert(_Alignof(struct YE_extra_size) == 1, "");
_Static_assert(sizeof(YF) == 5, "");
_Static_assert(_Alignof(YF) == 1, "");
_Static_assert(sizeof(struct YF_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct YF_extra_alignment) == 1, "");
_Static_assert(sizeof(struct YF_extra_packed) == 5, "");
_Static_assert(_Alignof(struct YF_extra_packed) == 1, "");
_Static_assert(sizeof(struct YF_extra_required_alignment) == 6, "");
_Static_assert(_Alignof(struct YF_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct YF_extra_size) == 7, "");
_Static_assert(_Alignof(struct YF_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(YF,b) == 8, "");
#endif
_Static_assert(sizeof(D0) == 16, "");
_Static_assert(_Alignof(D0) == 16, "");
_Static_assert(sizeof(struct D0_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct D0_extra_alignment) == 16, "");
_Static_assert(sizeof(struct D0_extra_packed) == 16, "");
_Static_assert(_Alignof(struct D0_extra_packed) == 1, "");
_Static_assert(sizeof(struct D0_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct D0_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct D0_extra_size) == 18, "");
_Static_assert(_Alignof(struct D0_extra_size) == 1, "");
_Static_assert(sizeof(RB0) == 8, "");
_Static_assert(_Alignof(RB0) == 8, "");
_Static_assert(sizeof(struct RB0_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct RB0_extra_alignment) == 8, "");
_Static_assert(sizeof(struct RB0_extra_packed) == 8, "");
_Static_assert(_Alignof(struct RB0_extra_packed) == 1, "");
_Static_assert(sizeof(struct RB0_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct RB0_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct RB0_extra_size) == 10, "");
_Static_assert(_Alignof(struct RB0_extra_size) == 1, "");
_Static_assert(sizeof(RC) == 2, "");
_Static_assert(_Alignof(RC) == 1, "");
_Static_assert(sizeof(struct RC_extra_alignment) == 3, "");
_Static_assert(_Alignof(struct RC_extra_alignment) == 1, "");
_Static_assert(sizeof(struct RC_extra_packed) == 2, "");
_Static_assert(_Alignof(struct RC_extra_packed) == 1, "");
_Static_assert(sizeof(struct RC_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct RC_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct RC_extra_size) == 4, "");
_Static_assert(_Alignof(struct RC_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(RC,c) == 8, "");
#endif
_Static_assert(sizeof(RE) == 3, "");
_Static_assert(_Alignof(RE) == 1, "");
_Static_assert(sizeof(struct RE_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct RE_extra_alignment) == 1, "");
_Static_assert(sizeof(struct RE_extra_packed) == 3, "");
_Static_assert(_Alignof(struct RE_extra_packed) == 1, "");
_Static_assert(sizeof(struct RE_extra_required_alignment) == 4, "");
_Static_assert(_Alignof(struct RE_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct RE_extra_size) == 5, "");
_Static_assert(_Alignof(struct RE_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(RE,c) == 8, "");
#endif
_Static_assert(sizeof(PA) == 4, "");
_Static_assert(_Alignof(PA) == 4, "");
_Static_assert(sizeof(struct PA_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct PA_extra_alignment) == 4, "");
_Static_assert(sizeof(struct PA_extra_packed) == 4, "");
_Static_assert(_Alignof(struct PA_extra_packed) == 1, "");
_Static_assert(sizeof(struct PA_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct PA_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct PA_extra_size) == 6, "");
_Static_assert(_Alignof(struct PA_extra_size) == 1, "");
_Static_assert(sizeof(PB) == 4, "");
_Static_assert(_Alignof(PB) == 8, "");
_Static_assert(sizeof(struct PB_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct PB_extra_alignment) == 8, "");
_Static_assert(sizeof(struct PB_extra_packed) == 4, "");
_Static_assert(_Alignof(struct PB_extra_packed) == 1, "");
_Static_assert(sizeof(struct PB_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct PB_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct PB_extra_size) == 6, "");
_Static_assert(_Alignof(struct PB_extra_size) == 1, "");
_Static_assert(sizeof(PC) == 5, "");
_Static_assert(_Alignof(PC) == 1, "");
_Static_assert(sizeof(struct PC_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct PC_extra_alignment) == 1, "");
_Static_assert(sizeof(struct PC_extra_packed) == 5, "");
_Static_assert(_Alignof(struct PC_extra_packed) == 1, "");
_Static_assert(sizeof(struct PC_extra_required_alignment) == 6, "");
_Static_assert(_Alignof(struct PC_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct PC_extra_size) == 7, "");
_Static_assert(_Alignof(struct PC_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(PC,x) == 8, "");
#endif
_Static_assert(sizeof(PD) == 4, "");
_Static_assert(_Alignof(PD) == 8, "");
_Static_assert(sizeof(struct PD_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct PD_extra_alignment) == 8, "");
_Static_assert(sizeof(struct PD_extra_packed) == 4, "");
_Static_assert(_Alignof(struct PD_extra_packed) == 1, "");
_Static_assert(sizeof(struct PD_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct PD_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct PD_extra_size) == 6, "");
_Static_assert(_Alignof(struct PD_extra_size) == 1, "");
_Static_assert(sizeof(PE) == 5, "");
_Static_assert(_Alignof(PE) == 1, "");
_Static_assert(sizeof(struct PE_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct PE_extra_alignment) == 1, "");
_Static_assert(sizeof(struct PE_extra_packed) == 5, "");
_Static_assert(_Alignof(struct PE_extra_packed) == 1, "");
_Static_assert(sizeof(struct PE_extra_required_alignment) == 6, "");
_Static_assert(_Alignof(struct PE_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct PE_extra_size) == 7, "");
_Static_assert(_Alignof(struct PE_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(PE,x) == 8, "");
#endif
_Static_assert(sizeof(QA) == 2, "");
_Static_assert(_Alignof(QA) == 2, "");
_Static_assert(sizeof(struct QA_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct QA_extra_alignment) == 2, "");
_Static_assert(sizeof(struct QA_extra_packed) == 2, "");
_Static_assert(_Alignof(struct QA_extra_packed) == 1, "");
_Static_assert(sizeof(struct QA_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct QA_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct QA_extra_size) == 4, "");
_Static_assert(_Alignof(struct QA_extra_size) == 1, "");
_Static_assert(sizeof(QB) == 3, "");
_Static_assert(_Alignof(QB) == 1, "");
_Static_assert(sizeof(struct QB_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct QB_extra_alignment) == 1, "");
_Static_assert(sizeof(struct QB_extra_packed) == 3, "");
_Static_assert(_Alignof(struct QB_extra_packed) == 1, "");
_Static_assert(sizeof(struct QB_extra_required_alignment) == 4, "");
_Static_assert(_Alignof(struct QB_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct QB_extra_size) == 5, "");
_Static_assert(_Alignof(struct QB_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(QB,b) == 8, "");
#endif
_Static_assert(sizeof(QC) == 4, "");
_Static_assert(_Alignof(QC) == 2, "");
_Static_assert(sizeof(struct QC_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct QC_extra_alignment) == 2, "");
_Static_assert(sizeof(struct QC_extra_packed) == 4, "");
_Static_assert(_Alignof(struct QC_extra_packed) == 1, "");
_Static_assert(sizeof(struct QC_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct QC_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct QC_extra_size) == 6, "");
_Static_assert(_Alignof(struct QC_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(QC,b) == 16, "");
#endif
_Static_assert(sizeof(QD) == 2, "");
_Static_assert(_Alignof(QD) == 1, "");
_Static_assert(sizeof(struct QD_extra_alignment) == 3, "");
_Static_assert(_Alignof(struct QD_extra_alignment) == 1, "");
_Static_assert(sizeof(struct QD_extra_packed) == 2, "");
_Static_assert(_Alignof(struct QD_extra_packed) == 1, "");
_Static_assert(sizeof(struct QD_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct QD_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct QD_extra_size) == 4, "");
_Static_assert(_Alignof(struct QD_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(QD,b) == 8, "");
#endif
_Static_assert(sizeof(EmptyAlignedLongLongMemb) == 0, "");
_Static_assert(_Alignof(EmptyAlignedLongLongMemb) == 4, "");
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_extra_alignment) == 4, "");
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_extra_packed) == 0, "");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_extra_packed) == 1, "");
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_extra_size) == 2, "");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_extra_size) == 1, "");
_Static_assert(sizeof(EmptyPackedAlignedLongLongMemb) == 0, "");
_Static_assert(_Alignof(EmptyPackedAlignedLongLongMemb) == 4, "");
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_extra_alignment) == 4, "");
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_extra_packed) == 0, "");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_extra_packed) == 1, "");
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_extra_size) == 2, "");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_extra_size) == 1, "");
// MAPPING|SIX|x86-pentium4-ios-none:Clang|x86-i586-linux-gnu:Gcc|x86-i586-linux-musl:Gcc|x86-i686-macos-none:Clang|x86-i686-linux-android:Clang|x86-i686-freebsd-gnu:Clang|x86-i686-haiku-gnu:Clang|x86-i686-linux-gnu:Gcc|x86-i686-linux-musl:Gcc|x86-i686-netbsd-gnu:Clang|x86-i686-openbsd-gnu:Clang|END
// repr targets I386AppleIos|Some("x86-pentium4-ios-none") I586UnknownLinuxGnu|Some("x86-i586-linux-gnu") I586UnknownLinuxMusl|Some("x86-i586-linux-musl") I686AppleMacosx|Some("x86-i686-macos-none") I686LinuxAndroid|Some("x86-i686-linux-android") I686UnknownFreebsd|Some("x86-i686-freebsd-gnu") I686UnknownHaiku|Some("x86-i686-haiku-gnu") I686UnknownLinuxGnu|Some("x86-i686-linux-gnu") I686UnknownLinuxMusl|Some("x86-i686-linux-musl") I686UnknownNetbsdelf|Some("x86-i686-netbsd-gnu") I686UnknownOpenbsd|Some("x86-i686-openbsd-gnu") 
#elif defined(SIX)
_Static_assert(sizeof(A) == 1, "");
_Static_assert(_Alignof(A) == 1, "");
_Static_assert(sizeof(struct A_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct A_extra_alignment) == 1, "");
_Static_assert(sizeof(struct A_extra_packed) == 1, "");
_Static_assert(_Alignof(struct A_extra_packed) == 1, "");
_Static_assert(sizeof(struct A_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct A_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A_extra_size) == 3, "");
_Static_assert(_Alignof(struct A_extra_size) == 1, "");
_Static_assert(sizeof(B) == 8, "");
_Static_assert(_Alignof(B) == 4, "");
_Static_assert(sizeof(struct B_extra_alignment) == 12, "");
_Static_assert(_Alignof(struct B_extra_alignment) == 4, "");
_Static_assert(sizeof(struct B_extra_packed) == 8, "");
_Static_assert(_Alignof(struct B_extra_packed) == 1, "");
_Static_assert(sizeof(struct B_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct B_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B_extra_size) == 10, "");
_Static_assert(_Alignof(struct B_extra_size) == 1, "");
_Static_assert(sizeof(X) == 14, "");
_Static_assert(_Alignof(X) == 2, "");
_Static_assert(sizeof(struct X_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct X_extra_alignment) == 2, "");
_Static_assert(sizeof(struct X_extra_packed) == 14, "");
_Static_assert(_Alignof(struct X_extra_packed) == 1, "");
_Static_assert(sizeof(struct X_extra_required_alignment) == 15, "");
_Static_assert(_Alignof(struct X_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct X_extra_size) == 16, "");
_Static_assert(_Alignof(struct X_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(X,b) == 64, "");
_Static_assert(__builtin_bitoffsetof(X,c) == 80, "");
#endif
_Static_assert(sizeof(YA) == 1, "");
_Static_assert(_Alignof(YA) == 1, "");
_Static_assert(sizeof(struct YA_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct YA_extra_alignment) == 1, "");
_Static_assert(sizeof(struct YA_extra_packed) == 1, "");
_Static_assert(_Alignof(struct YA_extra_packed) == 1, "");
_Static_assert(sizeof(struct YA_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct YA_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct YA_extra_size) == 3, "");
_Static_assert(_Alignof(struct YA_extra_size) == 1, "");
_Static_assert(sizeof(YB) == 2, "");
_Static_assert(_Alignof(YB) == 1, "");
_Static_assert(sizeof(struct YB_extra_alignment) == 3, "");
_Static_assert(_Alignof(struct YB_extra_alignment) == 1, "");
_Static_assert(sizeof(struct YB_extra_packed) == 2, "");
_Static_assert(_Alignof(struct YB_extra_packed) == 1, "");
_Static_assert(sizeof(struct YB_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct YB_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct YB_extra_size) == 4, "");
_Static_assert(_Alignof(struct YB_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(YB,b) == 8, "");
#endif
_Static_assert(sizeof(YC) == 1, "");
_Static_assert(_Alignof(YC) == 1, "");
_Static_assert(sizeof(struct YC_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct YC_extra_alignment) == 1, "");
_Static_assert(sizeof(struct YC_extra_packed) == 1, "");
_Static_assert(_Alignof(struct YC_extra_packed) == 1, "");
_Static_assert(sizeof(struct YC_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct YC_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct YC_extra_size) == 3, "");
_Static_assert(_Alignof(struct YC_extra_size) == 1, "");
_Static_assert(sizeof(YD) == 2, "");
_Static_assert(_Alignof(YD) == 1, "");
_Static_assert(sizeof(struct YD_extra_alignment) == 3, "");
_Static_assert(_Alignof(struct YD_extra_alignment) == 1, "");
_Static_assert(sizeof(struct YD_extra_packed) == 2, "");
_Static_assert(_Alignof(struct YD_extra_packed) == 1, "");
_Static_assert(sizeof(struct YD_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct YD_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct YD_extra_size) == 4, "");
_Static_assert(_Alignof(struct YD_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(YD,b) == 8, "");
#endif
_Static_assert(sizeof(YE) == 1, "");
_Static_assert(_Alignof(YE) == 1, "");
_Static_assert(sizeof(struct YE_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct YE_extra_alignment) == 1, "");
_Static_assert(sizeof(struct YE_extra_packed) == 1, "");
_Static_assert(_Alignof(struct YE_extra_packed) == 1, "");
_Static_assert(sizeof(struct YE_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct YE_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct YE_extra_size) == 3, "");
_Static_assert(_Alignof(struct YE_extra_size) == 1, "");
_Static_assert(sizeof(YF) == 2, "");
_Static_assert(_Alignof(YF) == 1, "");
_Static_assert(sizeof(struct YF_extra_alignment) == 3, "");
_Static_assert(_Alignof(struct YF_extra_alignment) == 1, "");
_Static_assert(sizeof(struct YF_extra_packed) == 2, "");
_Static_assert(_Alignof(struct YF_extra_packed) == 1, "");
_Static_assert(sizeof(struct YF_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct YF_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct YF_extra_size) == 4, "");
_Static_assert(_Alignof(struct YF_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(YF,b) == 8, "");
#endif
_Static_assert(sizeof(D0) == 16, "");
_Static_assert(_Alignof(D0) == 16, "");
_Static_assert(sizeof(struct D0_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct D0_extra_alignment) == 16, "");
_Static_assert(sizeof(struct D0_extra_packed) == 16, "");
_Static_assert(_Alignof(struct D0_extra_packed) == 1, "");
_Static_assert(sizeof(struct D0_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct D0_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct D0_extra_size) == 18, "");
_Static_assert(_Alignof(struct D0_extra_size) == 1, "");
_Static_assert(sizeof(RB0) == 8, "");
_Static_assert(_Alignof(RB0) == 8, "");
_Static_assert(sizeof(struct RB0_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct RB0_extra_alignment) == 8, "");
_Static_assert(sizeof(struct RB0_extra_packed) == 8, "");
_Static_assert(_Alignof(struct RB0_extra_packed) == 1, "");
_Static_assert(sizeof(struct RB0_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct RB0_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct RB0_extra_size) == 10, "");
_Static_assert(_Alignof(struct RB0_extra_size) == 1, "");
_Static_assert(sizeof(RC) == 2, "");
_Static_assert(_Alignof(RC) == 1, "");
_Static_assert(sizeof(struct RC_extra_alignment) == 3, "");
_Static_assert(_Alignof(struct RC_extra_alignment) == 1, "");
_Static_assert(sizeof(struct RC_extra_packed) == 2, "");
_Static_assert(_Alignof(struct RC_extra_packed) == 1, "");
_Static_assert(sizeof(struct RC_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct RC_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct RC_extra_size) == 4, "");
_Static_assert(_Alignof(struct RC_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(RC,c) == 8, "");
#endif
_Static_assert(sizeof(RE) == 3, "");
_Static_assert(_Alignof(RE) == 1, "");
_Static_assert(sizeof(struct RE_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct RE_extra_alignment) == 1, "");
_Static_assert(sizeof(struct RE_extra_packed) == 3, "");
_Static_assert(_Alignof(struct RE_extra_packed) == 1, "");
_Static_assert(sizeof(struct RE_extra_required_alignment) == 4, "");
_Static_assert(_Alignof(struct RE_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct RE_extra_size) == 5, "");
_Static_assert(_Alignof(struct RE_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(RE,c) == 8, "");
#endif
_Static_assert(sizeof(PA) == 4, "");
_Static_assert(_Alignof(PA) == 4, "");
_Static_assert(sizeof(struct PA_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct PA_extra_alignment) == 4, "");
_Static_assert(sizeof(struct PA_extra_packed) == 4, "");
_Static_assert(_Alignof(struct PA_extra_packed) == 1, "");
_Static_assert(sizeof(struct PA_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct PA_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct PA_extra_size) == 6, "");
_Static_assert(_Alignof(struct PA_extra_size) == 1, "");
_Static_assert(sizeof(PB) == 4, "");
_Static_assert(_Alignof(PB) == 8, "");
_Static_assert(sizeof(struct PB_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct PB_extra_alignment) == 8, "");
_Static_assert(sizeof(struct PB_extra_packed) == 4, "");
_Static_assert(_Alignof(struct PB_extra_packed) == 1, "");
_Static_assert(sizeof(struct PB_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct PB_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct PB_extra_size) == 6, "");
_Static_assert(_Alignof(struct PB_extra_size) == 1, "");
_Static_assert(sizeof(PC) == 5, "");
_Static_assert(_Alignof(PC) == 1, "");
_Static_assert(sizeof(struct PC_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct PC_extra_alignment) == 1, "");
_Static_assert(sizeof(struct PC_extra_packed) == 5, "");
_Static_assert(_Alignof(struct PC_extra_packed) == 1, "");
_Static_assert(sizeof(struct PC_extra_required_alignment) == 6, "");
_Static_assert(_Alignof(struct PC_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct PC_extra_size) == 7, "");
_Static_assert(_Alignof(struct PC_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(PC,x) == 8, "");
#endif
_Static_assert(sizeof(PD) == 4, "");
_Static_assert(_Alignof(PD) == 8, "");
_Static_assert(sizeof(struct PD_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct PD_extra_alignment) == 8, "");
_Static_assert(sizeof(struct PD_extra_packed) == 4, "");
_Static_assert(_Alignof(struct PD_extra_packed) == 1, "");
_Static_assert(sizeof(struct PD_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct PD_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct PD_extra_size) == 6, "");
_Static_assert(_Alignof(struct PD_extra_size) == 1, "");
_Static_assert(sizeof(PE) == 5, "");
_Static_assert(_Alignof(PE) == 1, "");
_Static_assert(sizeof(struct PE_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct PE_extra_alignment) == 1, "");
_Static_assert(sizeof(struct PE_extra_packed) == 5, "");
_Static_assert(_Alignof(struct PE_extra_packed) == 1, "");
_Static_assert(sizeof(struct PE_extra_required_alignment) == 6, "");
_Static_assert(_Alignof(struct PE_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct PE_extra_size) == 7, "");
_Static_assert(_Alignof(struct PE_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(PE,x) == 8, "");
#endif
_Static_assert(sizeof(QA) == 4, "");
_Static_assert(_Alignof(QA) == 2, "");
_Static_assert(sizeof(struct QA_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct QA_extra_alignment) == 2, "");
_Static_assert(sizeof(struct QA_extra_packed) == 4, "");
_Static_assert(_Alignof(struct QA_extra_packed) == 1, "");
_Static_assert(sizeof(struct QA_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct QA_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct QA_extra_size) == 6, "");
_Static_assert(_Alignof(struct QA_extra_size) == 1, "");
_Static_assert(sizeof(QB) == 5, "");
_Static_assert(_Alignof(QB) == 1, "");
_Static_assert(sizeof(struct QB_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct QB_extra_alignment) == 1, "");
_Static_assert(sizeof(struct QB_extra_packed) == 5, "");
_Static_assert(_Alignof(struct QB_extra_packed) == 1, "");
_Static_assert(sizeof(struct QB_extra_required_alignment) == 6, "");
_Static_assert(_Alignof(struct QB_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct QB_extra_size) == 7, "");
_Static_assert(_Alignof(struct QB_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(QB,b) == 8, "");
#endif
_Static_assert(sizeof(QC) == 6, "");
_Static_assert(_Alignof(QC) == 2, "");
_Static_assert(sizeof(struct QC_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct QC_extra_alignment) == 2, "");
_Static_assert(sizeof(struct QC_extra_packed) == 6, "");
_Static_assert(_Alignof(struct QC_extra_packed) == 1, "");
_Static_assert(sizeof(struct QC_extra_required_alignment) == 7, "");
_Static_assert(_Alignof(struct QC_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct QC_extra_size) == 8, "");
_Static_assert(_Alignof(struct QC_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(QC,b) == 16, "");
#endif
_Static_assert(sizeof(QD) == 2, "");
_Static_assert(_Alignof(QD) == 2, "");
_Static_assert(sizeof(struct QD_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct QD_extra_alignment) == 2, "");
_Static_assert(sizeof(struct QD_extra_packed) == 2, "");
_Static_assert(_Alignof(struct QD_extra_packed) == 1, "");
_Static_assert(sizeof(struct QD_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct QD_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct QD_extra_size) == 4, "");
_Static_assert(_Alignof(struct QD_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(QD,b) == 8, "");
#endif
_Static_assert(sizeof(EmptyAlignedLongLongMemb) == 0, "");
_Static_assert(_Alignof(EmptyAlignedLongLongMemb) == 4, "");
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_extra_alignment) == 4, "");
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_extra_packed) == 0, "");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_extra_packed) == 1, "");
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_extra_size) == 2, "");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_extra_size) == 1, "");
_Static_assert(sizeof(EmptyPackedAlignedLongLongMemb) == 0, "");
_Static_assert(_Alignof(EmptyPackedAlignedLongLongMemb) == 4, "");
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_extra_alignment) == 4, "");
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_extra_packed) == 0, "");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_extra_packed) == 1, "");
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_extra_size) == 2, "");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_extra_size) == 1, "");
// MAPPING|SEVEN|x86-i586-windows-msvc:Msvc|x86-i686-windows-msvc:Msvc|x86-i686-uefi-msvc:Msvc|END
// repr targets I586PcWindowsMsvc|Some("x86-i586-windows-msvc") I686PcWindowsMsvc|Some("x86-i686-windows-msvc") I686UnknownWindows|Some("x86-i686-uefi-msvc") 
#elif defined(SEVEN)
_Static_assert(sizeof(A) == 1, "");
_Static_assert(_Alignof(A) == 1, "");
_Static_assert(sizeof(struct A_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct A_extra_alignment) == 1, "");
_Static_assert(sizeof(struct A_extra_packed) == 1, "");
_Static_assert(_Alignof(struct A_extra_packed) == 1, "");
_Static_assert(sizeof(struct A_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct A_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A_extra_size) == 3, "");
_Static_assert(_Alignof(struct A_extra_size) == 1, "");
_Static_assert(sizeof(B) == 8, "");
_Static_assert(_Alignof(B) == 8, "");
_Static_assert(sizeof(struct B_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct B_extra_alignment) == 8, "");
_Static_assert(sizeof(struct B_extra_packed) == 8, "");
_Static_assert(_Alignof(struct B_extra_packed) == 1, "");
_Static_assert(sizeof(struct B_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct B_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B_extra_size) == 10, "");
_Static_assert(_Alignof(struct B_extra_size) == 1, "");
_Static_assert(sizeof(X) == 16, "");
_Static_assert(_Alignof(X) == 4, "");
_Static_assert(sizeof(struct X_extra_alignment) == 20, "");
_Static_assert(_Alignof(struct X_extra_alignment) == 4, "");
_Static_assert(sizeof(struct X_extra_packed) == 16, "");
_Static_assert(_Alignof(struct X_extra_packed) == 1, "");
_Static_assert(sizeof(struct X_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct X_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct X_extra_size) == 18, "");
_Static_assert(_Alignof(struct X_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(X,b) == 64, "");
_Static_assert(__builtin_bitoffsetof(X,c) == 80, "");
#endif
_Static_assert(sizeof(YA) == 32, "");
_Static_assert(_Alignof(YA) == 32, "");
_Static_assert(sizeof(struct YA_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct YA_extra_alignment) == 32, "");
_Static_assert(sizeof(struct YA_extra_packed) == 32, "");
_Static_assert(_Alignof(struct YA_extra_packed) == 1, "");
_Static_assert(sizeof(struct YA_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct YA_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct YA_extra_size) == 34, "");
_Static_assert(_Alignof(struct YA_extra_size) == 1, "");
_Static_assert(sizeof(YB) == 33, "");
_Static_assert(_Alignof(YB) == 1, "");
_Static_assert(sizeof(struct YB_extra_alignment) == 34, "");
_Static_assert(_Alignof(struct YB_extra_alignment) == 1, "");
_Static_assert(sizeof(struct YB_extra_packed) == 33, "");
_Static_assert(_Alignof(struct YB_extra_packed) == 1, "");
_Static_assert(sizeof(struct YB_extra_required_alignment) == 34, "");
_Static_assert(_Alignof(struct YB_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct YB_extra_size) == 35, "");
_Static_assert(_Alignof(struct YB_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(YB,b) == 8, "");
#endif
_Static_assert(sizeof(YC) == 32, "");
_Static_assert(_Alignof(YC) == 32, "");
_Static_assert(sizeof(struct YC_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct YC_extra_alignment) == 32, "");
_Static_assert(sizeof(struct YC_extra_packed) == 32, "");
_Static_assert(_Alignof(struct YC_extra_packed) == 1, "");
_Static_assert(sizeof(struct YC_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct YC_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct YC_extra_size) == 34, "");
_Static_assert(_Alignof(struct YC_extra_size) == 1, "");
_Static_assert(sizeof(YD) == 33, "");
_Static_assert(_Alignof(YD) == 1, "");
_Static_assert(sizeof(struct YD_extra_alignment) == 34, "");
_Static_assert(_Alignof(struct YD_extra_alignment) == 1, "");
_Static_assert(sizeof(struct YD_extra_packed) == 33, "");
_Static_assert(_Alignof(struct YD_extra_packed) == 1, "");
_Static_assert(sizeof(struct YD_extra_required_alignment) == 34, "");
_Static_assert(_Alignof(struct YD_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct YD_extra_size) == 35, "");
_Static_assert(_Alignof(struct YD_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(YD,b) == 8, "");
#endif
_Static_assert(sizeof(YE) == 4, "");
_Static_assert(_Alignof(YE) == 32, "");
_Static_assert(sizeof(struct YE_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct YE_extra_alignment) == 32, "");
_Static_assert(sizeof(struct YE_extra_packed) == 4, "");
_Static_assert(_Alignof(struct YE_extra_packed) == 1, "");
_Static_assert(sizeof(struct YE_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct YE_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct YE_extra_size) == 6, "");
_Static_assert(_Alignof(struct YE_extra_size) == 1, "");
_Static_assert(sizeof(YF) == 5, "");
_Static_assert(_Alignof(YF) == 1, "");
_Static_assert(sizeof(struct YF_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct YF_extra_alignment) == 1, "");
_Static_assert(sizeof(struct YF_extra_packed) == 5, "");
_Static_assert(_Alignof(struct YF_extra_packed) == 1, "");
_Static_assert(sizeof(struct YF_extra_required_alignment) == 6, "");
_Static_assert(_Alignof(struct YF_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct YF_extra_size) == 7, "");
_Static_assert(_Alignof(struct YF_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(YF,b) == 8, "");
#endif
_Static_assert(sizeof(D0) == 16, "");
_Static_assert(_Alignof(D0) == 16, "");
_Static_assert(sizeof(struct D0_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct D0_extra_alignment) == 16, "");
_Static_assert(sizeof(struct D0_extra_packed) == 16, "");
_Static_assert(_Alignof(struct D0_extra_packed) == 1, "");
_Static_assert(sizeof(struct D0_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct D0_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct D0_extra_size) == 18, "");
_Static_assert(_Alignof(struct D0_extra_size) == 1, "");
_Static_assert(sizeof(RB0) == 8, "");
_Static_assert(_Alignof(RB0) == 1024, "");
_Static_assert(sizeof(struct RB0_extra_alignment) == 2048, "");
_Static_assert(_Alignof(struct RB0_extra_alignment) == 1024, "");
_Static_assert(sizeof(struct RB0_extra_packed) == 8, "");
_Static_assert(_Alignof(struct RB0_extra_packed) == 1, "");
_Static_assert(sizeof(struct RB0_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct RB0_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct RB0_extra_size) == 10, "");
_Static_assert(_Alignof(struct RB0_extra_size) == 1, "");
_Static_assert(sizeof(RC) == 1028, "");
_Static_assert(_Alignof(RC) == 1024, "");
_Static_assert(sizeof(struct RC_extra_alignment) == 3072, "");
_Static_assert(_Alignof(struct RC_extra_alignment) == 1024, "");
_Static_assert(sizeof(struct RC_extra_packed) == 1028, "");
_Static_assert(_Alignof(struct RC_extra_packed) == 1, "");
_Static_assert(sizeof(struct RC_extra_required_alignment) == 1029, "");
_Static_assert(_Alignof(struct RC_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct RC_extra_size) == 1030, "");
_Static_assert(_Alignof(struct RC_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(RC,c) == 8192, "");
#endif
_Static_assert(sizeof(RE) == 1029, "");
_Static_assert(_Alignof(RE) == 1, "");
_Static_assert(sizeof(struct RE_extra_alignment) == 1030, "");
_Static_assert(_Alignof(struct RE_extra_alignment) == 1, "");
_Static_assert(sizeof(struct RE_extra_packed) == 1029, "");
_Static_assert(_Alignof(struct RE_extra_packed) == 1, "");
_Static_assert(sizeof(struct RE_extra_required_alignment) == 1030, "");
_Static_assert(_Alignof(struct RE_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct RE_extra_size) == 1031, "");
_Static_assert(_Alignof(struct RE_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(RE,c) == 8, "");
#endif
_Static_assert(sizeof(PA) == 4, "");
_Static_assert(_Alignof(PA) == 4, "");
_Static_assert(sizeof(struct PA_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct PA_extra_alignment) == 4, "");
_Static_assert(sizeof(struct PA_extra_packed) == 4, "");
_Static_assert(_Alignof(struct PA_extra_packed) == 1, "");
_Static_assert(sizeof(struct PA_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct PA_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct PA_extra_size) == 6, "");
_Static_assert(_Alignof(struct PA_extra_size) == 1, "");
_Static_assert(sizeof(PB) == 4, "");
_Static_assert(_Alignof(PB) == 8, "");
_Static_assert(sizeof(struct PB_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct PB_extra_alignment) == 8, "");
_Static_assert(sizeof(struct PB_extra_packed) == 4, "");
_Static_assert(_Alignof(struct PB_extra_packed) == 1, "");
_Static_assert(sizeof(struct PB_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct PB_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct PB_extra_size) == 6, "");
_Static_assert(_Alignof(struct PB_extra_size) == 1, "");
_Static_assert(sizeof(PC) == 16, "");
_Static_assert(_Alignof(PC) == 8, "");
_Static_assert(sizeof(struct PC_extra_alignment) == 24, "");
_Static_assert(_Alignof(struct PC_extra_alignment) == 8, "");
_Static_assert(sizeof(struct PC_extra_packed) == 16, "");
_Static_assert(_Alignof(struct PC_extra_packed) == 1, "");
_Static_assert(sizeof(struct PC_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct PC_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct PC_extra_size) == 18, "");
_Static_assert(_Alignof(struct PC_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(PC,x) == 64, "");
#endif
_Static_assert(sizeof(PD) == 4, "");
_Static_assert(_Alignof(PD) == 8, "");
_Static_assert(sizeof(struct PD_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct PD_extra_alignment) == 8, "");
_Static_assert(sizeof(struct PD_extra_packed) == 4, "");
_Static_assert(_Alignof(struct PD_extra_packed) == 1, "");
_Static_assert(sizeof(struct PD_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct PD_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct PD_extra_size) == 6, "");
_Static_assert(_Alignof(struct PD_extra_size) == 1, "");
_Static_assert(sizeof(PE) == 16, "");
_Static_assert(_Alignof(PE) == 8, "");
_Static_assert(sizeof(struct PE_extra_alignment) == 24, "");
_Static_assert(_Alignof(struct PE_extra_alignment) == 8, "");
_Static_assert(sizeof(struct PE_extra_packed) == 16, "");
_Static_assert(_Alignof(struct PE_extra_packed) == 1, "");
_Static_assert(sizeof(struct PE_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct PE_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct PE_extra_size) == 18, "");
_Static_assert(_Alignof(struct PE_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(PE,x) == 64, "");
#endif
_Static_assert(sizeof(QA) == 4, "");
_Static_assert(_Alignof(QA) == 4, "");
_Static_assert(sizeof(struct QA_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct QA_extra_alignment) == 4, "");
_Static_assert(sizeof(struct QA_extra_packed) == 4, "");
_Static_assert(_Alignof(struct QA_extra_packed) == 1, "");
_Static_assert(sizeof(struct QA_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct QA_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct QA_extra_size) == 6, "");
_Static_assert(_Alignof(struct QA_extra_size) == 1, "");
_Static_assert(sizeof(QB) == 6, "");
_Static_assert(_Alignof(QB) == 2, "");
_Static_assert(sizeof(struct QB_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct QB_extra_alignment) == 2, "");
_Static_assert(sizeof(struct QB_extra_packed) == 6, "");
_Static_assert(_Alignof(struct QB_extra_packed) == 1, "");
_Static_assert(sizeof(struct QB_extra_required_alignment) == 7, "");
_Static_assert(_Alignof(struct QB_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct QB_extra_size) == 8, "");
_Static_assert(_Alignof(struct QB_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(QB,b) == 16, "");
#endif
_Static_assert(sizeof(QC) == 8, "");
_Static_assert(_Alignof(QC) == 4, "");
_Static_assert(sizeof(struct QC_extra_alignment) == 12, "");
_Static_assert(_Alignof(struct QC_extra_alignment) == 4, "");
_Static_assert(sizeof(struct QC_extra_packed) == 8, "");
_Static_assert(_Alignof(struct QC_extra_packed) == 1, "");
_Static_assert(sizeof(struct QC_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct QC_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct QC_extra_size) == 10, "");
_Static_assert(_Alignof(struct QC_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(QC,b) == 32, "");
#endif
_Static_assert(sizeof(QD) == 8, "");
_Static_assert(_Alignof(QD) == 4, "");
_Static_assert(sizeof(struct QD_extra_alignment) == 12, "");
_Static_assert(_Alignof(struct QD_extra_alignment) == 4, "");
_Static_assert(sizeof(struct QD_extra_packed) == 8, "");
_Static_assert(_Alignof(struct QD_extra_packed) == 1, "");
_Static_assert(sizeof(struct QD_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct QD_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct QD_extra_size) == 10, "");
_Static_assert(_Alignof(struct QD_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(QD,b) == 32, "");
#endif
_Static_assert(sizeof(EmptyAlignedLongLongMemb) == 4, "");
_Static_assert(_Alignof(EmptyAlignedLongLongMemb) == 8, "");
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_extra_alignment) == 8, "");
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_extra_packed) == 4, "");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_extra_packed) == 1, "");
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_extra_size) == 6, "");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_extra_size) == 1, "");
_Static_assert(sizeof(EmptyPackedAlignedLongLongMemb) == 4, "");
_Static_assert(_Alignof(EmptyPackedAlignedLongLongMemb) == 4, "");
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_extra_alignment) == 4, "");
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_extra_packed) == 4, "");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_extra_packed) == 1, "");
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_extra_size) == 6, "");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_extra_size) == 1, "");
// MAPPING|EIGHT|x86-i686-windows-gnu:Gcc|x86_64-x86_64-windows-gnu:Gcc|END
// repr targets I686PcWindowsGnu|Some("x86-i686-windows-gnu") X86_64PcWindowsGnu|Some("x86_64-x86_64-windows-gnu") 
#elif defined(EIGHT)
_Static_assert(sizeof(A) == 1, "");
_Static_assert(_Alignof(A) == 1, "");
_Static_assert(sizeof(struct A_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct A_extra_alignment) == 1, "");
_Static_assert(sizeof(struct A_extra_packed) == 1, "");
_Static_assert(_Alignof(struct A_extra_packed) == 1, "");
_Static_assert(sizeof(struct A_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct A_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A_extra_size) == 3, "");
_Static_assert(_Alignof(struct A_extra_size) == 1, "");
_Static_assert(sizeof(B) == 8, "");
_Static_assert(_Alignof(B) == 8, "");
_Static_assert(sizeof(struct B_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct B_extra_alignment) == 8, "");
_Static_assert(sizeof(struct B_extra_packed) == 8, "");
_Static_assert(_Alignof(struct B_extra_packed) == 1, "");
_Static_assert(sizeof(struct B_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct B_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B_extra_size) == 10, "");
_Static_assert(_Alignof(struct B_extra_size) == 1, "");
_Static_assert(sizeof(X) == 14, "");
_Static_assert(_Alignof(X) == 2, "");
_Static_assert(sizeof(struct X_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct X_extra_alignment) == 2, "");
_Static_assert(sizeof(struct X_extra_packed) == 14, "");
_Static_assert(_Alignof(struct X_extra_packed) == 1, "");
_Static_assert(sizeof(struct X_extra_required_alignment) == 15, "");
_Static_assert(_Alignof(struct X_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct X_extra_size) == 16, "");
_Static_assert(_Alignof(struct X_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(X,b) == 64, "");
_Static_assert(__builtin_bitoffsetof(X,c) == 80, "");
#endif
_Static_assert(sizeof(YA) == 16, "");
_Static_assert(_Alignof(YA) == 16, "");
_Static_assert(sizeof(struct YA_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct YA_extra_alignment) == 16, "");
_Static_assert(sizeof(struct YA_extra_packed) == 16, "");
_Static_assert(_Alignof(struct YA_extra_packed) == 1, "");
_Static_assert(sizeof(struct YA_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct YA_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct YA_extra_size) == 18, "");
_Static_assert(_Alignof(struct YA_extra_size) == 1, "");
_Static_assert(sizeof(YB) == 17, "");
_Static_assert(_Alignof(YB) == 1, "");
_Static_assert(sizeof(struct YB_extra_alignment) == 18, "");
_Static_assert(_Alignof(struct YB_extra_alignment) == 1, "");
_Static_assert(sizeof(struct YB_extra_packed) == 17, "");
_Static_assert(_Alignof(struct YB_extra_packed) == 1, "");
_Static_assert(sizeof(struct YB_extra_required_alignment) == 18, "");
_Static_assert(_Alignof(struct YB_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct YB_extra_size) == 19, "");
_Static_assert(_Alignof(struct YB_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(YB,b) == 8, "");
#endif
_Static_assert(sizeof(YC) == 8, "");
_Static_assert(_Alignof(YC) == 8, "");
_Static_assert(sizeof(struct YC_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct YC_extra_alignment) == 8, "");
_Static_assert(sizeof(struct YC_extra_packed) == 8, "");
_Static_assert(_Alignof(struct YC_extra_packed) == 1, "");
_Static_assert(sizeof(struct YC_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct YC_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct YC_extra_size) == 10, "");
_Static_assert(_Alignof(struct YC_extra_size) == 1, "");
_Static_assert(sizeof(YD) == 9, "");
_Static_assert(_Alignof(YD) == 1, "");
_Static_assert(sizeof(struct YD_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct YD_extra_alignment) == 1, "");
_Static_assert(sizeof(struct YD_extra_packed) == 9, "");
_Static_assert(_Alignof(struct YD_extra_packed) == 1, "");
_Static_assert(sizeof(struct YD_extra_required_alignment) == 10, "");
_Static_assert(_Alignof(struct YD_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct YD_extra_size) == 11, "");
_Static_assert(_Alignof(struct YD_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(YD,b) == 8, "");
#endif
_Static_assert(sizeof(YE) == 4, "");
_Static_assert(_Alignof(YE) == 4, "");
_Static_assert(sizeof(struct YE_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct YE_extra_alignment) == 4, "");
_Static_assert(sizeof(struct YE_extra_packed) == 4, "");
_Static_assert(_Alignof(struct YE_extra_packed) == 1, "");
_Static_assert(sizeof(struct YE_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct YE_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct YE_extra_size) == 6, "");
_Static_assert(_Alignof(struct YE_extra_size) == 1, "");
_Static_assert(sizeof(YF) == 5, "");
_Static_assert(_Alignof(YF) == 1, "");
_Static_assert(sizeof(struct YF_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct YF_extra_alignment) == 1, "");
_Static_assert(sizeof(struct YF_extra_packed) == 5, "");
_Static_assert(_Alignof(struct YF_extra_packed) == 1, "");
_Static_assert(sizeof(struct YF_extra_required_alignment) == 6, "");
_Static_assert(_Alignof(struct YF_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct YF_extra_size) == 7, "");
_Static_assert(_Alignof(struct YF_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(YF,b) == 8, "");
#endif
_Static_assert(sizeof(D0) == 16, "");
_Static_assert(_Alignof(D0) == 16, "");
_Static_assert(sizeof(struct D0_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct D0_extra_alignment) == 16, "");
_Static_assert(sizeof(struct D0_extra_packed) == 16, "");
_Static_assert(_Alignof(struct D0_extra_packed) == 1, "");
_Static_assert(sizeof(struct D0_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct D0_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct D0_extra_size) == 18, "");
_Static_assert(_Alignof(struct D0_extra_size) == 1, "");
_Static_assert(sizeof(RB0) == 8, "");
_Static_assert(_Alignof(RB0) == 8, "");
_Static_assert(sizeof(struct RB0_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct RB0_extra_alignment) == 8, "");
_Static_assert(sizeof(struct RB0_extra_packed) == 8, "");
_Static_assert(_Alignof(struct RB0_extra_packed) == 1, "");
_Static_assert(sizeof(struct RB0_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct RB0_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct RB0_extra_size) == 10, "");
_Static_assert(_Alignof(struct RB0_extra_size) == 1, "");
_Static_assert(sizeof(RC) == 5, "");
_Static_assert(_Alignof(RC) == 1, "");
_Static_assert(sizeof(struct RC_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct RC_extra_alignment) == 1, "");
_Static_assert(sizeof(struct RC_extra_packed) == 5, "");
_Static_assert(_Alignof(struct RC_extra_packed) == 1, "");
_Static_assert(sizeof(struct RC_extra_required_alignment) == 6, "");
_Static_assert(_Alignof(struct RC_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct RC_extra_size) == 7, "");
_Static_assert(_Alignof(struct RC_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(RC,c) == 8, "");
#endif
_Static_assert(sizeof(RE) == 6, "");
_Static_assert(_Alignof(RE) == 1, "");
_Static_assert(sizeof(struct RE_extra_alignment) == 7, "");
_Static_assert(_Alignof(struct RE_extra_alignment) == 1, "");
_Static_assert(sizeof(struct RE_extra_packed) == 6, "");
_Static_assert(_Alignof(struct RE_extra_packed) == 1, "");
_Static_assert(sizeof(struct RE_extra_required_alignment) == 7, "");
_Static_assert(_Alignof(struct RE_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct RE_extra_size) == 8, "");
_Static_assert(_Alignof(struct RE_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(RE,c) == 8, "");
#endif
_Static_assert(sizeof(PA) == 4, "");
_Static_assert(_Alignof(PA) == 4, "");
_Static_assert(sizeof(struct PA_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct PA_extra_alignment) == 4, "");
_Static_assert(sizeof(struct PA_extra_packed) == 4, "");
_Static_assert(_Alignof(struct PA_extra_packed) == 1, "");
_Static_assert(sizeof(struct PA_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct PA_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct PA_extra_size) == 6, "");
_Static_assert(_Alignof(struct PA_extra_size) == 1, "");
_Static_assert(sizeof(PB) == 4, "");
_Static_assert(_Alignof(PB) == 8, "");
_Static_assert(sizeof(struct PB_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct PB_extra_alignment) == 8, "");
_Static_assert(sizeof(struct PB_extra_packed) == 4, "");
_Static_assert(_Alignof(struct PB_extra_packed) == 1, "");
_Static_assert(sizeof(struct PB_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct PB_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct PB_extra_size) == 6, "");
_Static_assert(_Alignof(struct PB_extra_size) == 1, "");
_Static_assert(sizeof(PC) == 5, "");
_Static_assert(_Alignof(PC) == 1, "");
_Static_assert(sizeof(struct PC_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct PC_extra_alignment) == 1, "");
_Static_assert(sizeof(struct PC_extra_packed) == 5, "");
_Static_assert(_Alignof(struct PC_extra_packed) == 1, "");
_Static_assert(sizeof(struct PC_extra_required_alignment) == 6, "");
_Static_assert(_Alignof(struct PC_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct PC_extra_size) == 7, "");
_Static_assert(_Alignof(struct PC_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(PC,x) == 8, "");
#endif
_Static_assert(sizeof(PD) == 4, "");
_Static_assert(_Alignof(PD) == 8, "");
_Static_assert(sizeof(struct PD_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct PD_extra_alignment) == 8, "");
_Static_assert(sizeof(struct PD_extra_packed) == 4, "");
_Static_assert(_Alignof(struct PD_extra_packed) == 1, "");
_Static_assert(sizeof(struct PD_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct PD_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct PD_extra_size) == 6, "");
_Static_assert(_Alignof(struct PD_extra_size) == 1, "");
_Static_assert(sizeof(PE) == 5, "");
_Static_assert(_Alignof(PE) == 1, "");
_Static_assert(sizeof(struct PE_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct PE_extra_alignment) == 1, "");
_Static_assert(sizeof(struct PE_extra_packed) == 5, "");
_Static_assert(_Alignof(struct PE_extra_packed) == 1, "");
_Static_assert(sizeof(struct PE_extra_required_alignment) == 6, "");
_Static_assert(_Alignof(struct PE_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct PE_extra_size) == 7, "");
_Static_assert(_Alignof(struct PE_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(PE,x) == 8, "");
#endif
_Static_assert(sizeof(QA) == 4, "");
_Static_assert(_Alignof(QA) == 2, "");
_Static_assert(sizeof(struct QA_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct QA_extra_alignment) == 2, "");
_Static_assert(sizeof(struct QA_extra_packed) == 4, "");
_Static_assert(_Alignof(struct QA_extra_packed) == 1, "");
_Static_assert(sizeof(struct QA_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct QA_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct QA_extra_size) == 6, "");
_Static_assert(_Alignof(struct QA_extra_size) == 1, "");
_Static_assert(sizeof(QB) == 5, "");
_Static_assert(_Alignof(QB) == 1, "");
_Static_assert(sizeof(struct QB_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct QB_extra_alignment) == 1, "");
_Static_assert(sizeof(struct QB_extra_packed) == 5, "");
_Static_assert(_Alignof(struct QB_extra_packed) == 1, "");
_Static_assert(sizeof(struct QB_extra_required_alignment) == 6, "");
_Static_assert(_Alignof(struct QB_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct QB_extra_size) == 7, "");
_Static_assert(_Alignof(struct QB_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(QB,b) == 8, "");
#endif
_Static_assert(sizeof(QC) == 6, "");
_Static_assert(_Alignof(QC) == 2, "");
_Static_assert(sizeof(struct QC_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct QC_extra_alignment) == 2, "");
_Static_assert(sizeof(struct QC_extra_packed) == 6, "");
_Static_assert(_Alignof(struct QC_extra_packed) == 1, "");
_Static_assert(sizeof(struct QC_extra_required_alignment) == 7, "");
_Static_assert(_Alignof(struct QC_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct QC_extra_size) == 8, "");
_Static_assert(_Alignof(struct QC_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(QC,b) == 16, "");
#endif
_Static_assert(sizeof(QD) == 6, "");
_Static_assert(_Alignof(QD) == 2, "");
_Static_assert(sizeof(struct QD_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct QD_extra_alignment) == 2, "");
_Static_assert(sizeof(struct QD_extra_packed) == 6, "");
_Static_assert(_Alignof(struct QD_extra_packed) == 1, "");
_Static_assert(sizeof(struct QD_extra_required_alignment) == 7, "");
_Static_assert(_Alignof(struct QD_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct QD_extra_size) == 8, "");
_Static_assert(_Alignof(struct QD_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(QD,b) == 16, "");
#endif
_Static_assert(sizeof(EmptyAlignedLongLongMemb) == 0, "");
_Static_assert(_Alignof(EmptyAlignedLongLongMemb) == 8, "");
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_extra_alignment) == 8, "");
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_extra_packed) == 0, "");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_extra_packed) == 1, "");
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_extra_size) == 2, "");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_extra_size) == 1, "");
_Static_assert(sizeof(EmptyPackedAlignedLongLongMemb) == 0, "");
_Static_assert(_Alignof(EmptyPackedAlignedLongLongMemb) == 4, "");
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_extra_alignment) == 4, "");
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_extra_packed) == 0, "");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_extra_packed) == 1, "");
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_extra_size) == 2, "");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_extra_size) == 1, "");
// MAPPING|NINE|msp430-msp430-other-eabi:Clang|END
// repr targets Msp430NoneElf|Some("msp430-msp430-other-eabi") 
#elif defined(NINE)
_Static_assert(sizeof(A) == 1, "");
_Static_assert(_Alignof(A) == 1, "");
_Static_assert(sizeof(struct A_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct A_extra_alignment) == 1, "");
_Static_assert(sizeof(struct A_extra_packed) == 1, "");
_Static_assert(_Alignof(struct A_extra_packed) == 1, "");
_Static_assert(sizeof(struct A_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct A_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A_extra_size) == 3, "");
_Static_assert(_Alignof(struct A_extra_size) == 1, "");
_Static_assert(sizeof(B) == 8, "");
_Static_assert(_Alignof(B) == 4, "");
_Static_assert(sizeof(struct B_extra_alignment) == 12, "");
_Static_assert(_Alignof(struct B_extra_alignment) == 4, "");
_Static_assert(sizeof(struct B_extra_packed) == 8, "");
_Static_assert(_Alignof(struct B_extra_packed) == 1, "");
_Static_assert(sizeof(struct B_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct B_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B_extra_size) == 10, "");
_Static_assert(_Alignof(struct B_extra_size) == 1, "");
_Static_assert(sizeof(X) == 12, "");
_Static_assert(_Alignof(X) == 2, "");
_Static_assert(sizeof(struct X_extra_alignment) == 14, "");
_Static_assert(_Alignof(struct X_extra_alignment) == 2, "");
_Static_assert(sizeof(struct X_extra_packed) == 12, "");
_Static_assert(_Alignof(struct X_extra_packed) == 1, "");
_Static_assert(sizeof(struct X_extra_required_alignment) == 13, "");
_Static_assert(_Alignof(struct X_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct X_extra_size) == 14, "");
_Static_assert(_Alignof(struct X_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(X,b) == 64, "");
_Static_assert(__builtin_bitoffsetof(X,c) == 80, "");
#endif
_Static_assert(sizeof(YA) == 1, "");
_Static_assert(_Alignof(YA) == 1, "");
_Static_assert(sizeof(struct YA_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct YA_extra_alignment) == 1, "");
_Static_assert(sizeof(struct YA_extra_packed) == 1, "");
_Static_assert(_Alignof(struct YA_extra_packed) == 1, "");
_Static_assert(sizeof(struct YA_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct YA_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct YA_extra_size) == 3, "");
_Static_assert(_Alignof(struct YA_extra_size) == 1, "");
_Static_assert(sizeof(YB) == 2, "");
_Static_assert(_Alignof(YB) == 1, "");
_Static_assert(sizeof(struct YB_extra_alignment) == 3, "");
_Static_assert(_Alignof(struct YB_extra_alignment) == 1, "");
_Static_assert(sizeof(struct YB_extra_packed) == 2, "");
_Static_assert(_Alignof(struct YB_extra_packed) == 1, "");
_Static_assert(sizeof(struct YB_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct YB_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct YB_extra_size) == 4, "");
_Static_assert(_Alignof(struct YB_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(YB,b) == 8, "");
#endif
_Static_assert(sizeof(YC) == 1, "");
_Static_assert(_Alignof(YC) == 1, "");
_Static_assert(sizeof(struct YC_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct YC_extra_alignment) == 1, "");
_Static_assert(sizeof(struct YC_extra_packed) == 1, "");
_Static_assert(_Alignof(struct YC_extra_packed) == 1, "");
_Static_assert(sizeof(struct YC_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct YC_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct YC_extra_size) == 3, "");
_Static_assert(_Alignof(struct YC_extra_size) == 1, "");
_Static_assert(sizeof(YD) == 2, "");
_Static_assert(_Alignof(YD) == 1, "");
_Static_assert(sizeof(struct YD_extra_alignment) == 3, "");
_Static_assert(_Alignof(struct YD_extra_alignment) == 1, "");
_Static_assert(sizeof(struct YD_extra_packed) == 2, "");
_Static_assert(_Alignof(struct YD_extra_packed) == 1, "");
_Static_assert(sizeof(struct YD_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct YD_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct YD_extra_size) == 4, "");
_Static_assert(_Alignof(struct YD_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(YD,b) == 8, "");
#endif
_Static_assert(sizeof(YE) == 1, "");
_Static_assert(_Alignof(YE) == 1, "");
_Static_assert(sizeof(struct YE_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct YE_extra_alignment) == 1, "");
_Static_assert(sizeof(struct YE_extra_packed) == 1, "");
_Static_assert(_Alignof(struct YE_extra_packed) == 1, "");
_Static_assert(sizeof(struct YE_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct YE_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct YE_extra_size) == 3, "");
_Static_assert(_Alignof(struct YE_extra_size) == 1, "");
_Static_assert(sizeof(YF) == 2, "");
_Static_assert(_Alignof(YF) == 1, "");
_Static_assert(sizeof(struct YF_extra_alignment) == 3, "");
_Static_assert(_Alignof(struct YF_extra_alignment) == 1, "");
_Static_assert(sizeof(struct YF_extra_packed) == 2, "");
_Static_assert(_Alignof(struct YF_extra_packed) == 1, "");
_Static_assert(sizeof(struct YF_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct YF_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct YF_extra_size) == 4, "");
_Static_assert(_Alignof(struct YF_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(YF,b) == 8, "");
#endif
_Static_assert(sizeof(D0) == 16, "");
_Static_assert(_Alignof(D0) == 16, "");
_Static_assert(sizeof(struct D0_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct D0_extra_alignment) == 16, "");
_Static_assert(sizeof(struct D0_extra_packed) == 16, "");
_Static_assert(_Alignof(struct D0_extra_packed) == 1, "");
_Static_assert(sizeof(struct D0_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct D0_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct D0_extra_size) == 18, "");
_Static_assert(_Alignof(struct D0_extra_size) == 1, "");
_Static_assert(sizeof(RB0) == 8, "");
_Static_assert(_Alignof(RB0) == 8, "");
_Static_assert(sizeof(struct RB0_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct RB0_extra_alignment) == 8, "");
_Static_assert(sizeof(struct RB0_extra_packed) == 8, "");
_Static_assert(_Alignof(struct RB0_extra_packed) == 1, "");
_Static_assert(sizeof(struct RB0_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct RB0_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct RB0_extra_size) == 10, "");
_Static_assert(_Alignof(struct RB0_extra_size) == 1, "");
_Static_assert(sizeof(RC) == 2, "");
_Static_assert(_Alignof(RC) == 1, "");
_Static_assert(sizeof(struct RC_extra_alignment) == 3, "");
_Static_assert(_Alignof(struct RC_extra_alignment) == 1, "");
_Static_assert(sizeof(struct RC_extra_packed) == 2, "");
_Static_assert(_Alignof(struct RC_extra_packed) == 1, "");
_Static_assert(sizeof(struct RC_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct RC_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct RC_extra_size) == 4, "");
_Static_assert(_Alignof(struct RC_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(RC,c) == 8, "");
#endif
_Static_assert(sizeof(RE) == 3, "");
_Static_assert(_Alignof(RE) == 1, "");
_Static_assert(sizeof(struct RE_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct RE_extra_alignment) == 1, "");
_Static_assert(sizeof(struct RE_extra_packed) == 3, "");
_Static_assert(_Alignof(struct RE_extra_packed) == 1, "");
_Static_assert(sizeof(struct RE_extra_required_alignment) == 4, "");
_Static_assert(_Alignof(struct RE_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct RE_extra_size) == 5, "");
_Static_assert(_Alignof(struct RE_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(RE,c) == 8, "");
#endif
_Static_assert(sizeof(PA) == 4, "");
_Static_assert(_Alignof(PA) == 4, "");
_Static_assert(sizeof(struct PA_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct PA_extra_alignment) == 4, "");
_Static_assert(sizeof(struct PA_extra_packed) == 4, "");
_Static_assert(_Alignof(struct PA_extra_packed) == 1, "");
_Static_assert(sizeof(struct PA_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct PA_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct PA_extra_size) == 6, "");
_Static_assert(_Alignof(struct PA_extra_size) == 1, "");
_Static_assert(sizeof(PB) == 4, "");
_Static_assert(_Alignof(PB) == 8, "");
_Static_assert(sizeof(struct PB_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct PB_extra_alignment) == 8, "");
_Static_assert(sizeof(struct PB_extra_packed) == 4, "");
_Static_assert(_Alignof(struct PB_extra_packed) == 1, "");
_Static_assert(sizeof(struct PB_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct PB_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct PB_extra_size) == 6, "");
_Static_assert(_Alignof(struct PB_extra_size) == 1, "");
_Static_assert(sizeof(PC) == 5, "");
_Static_assert(_Alignof(PC) == 1, "");
_Static_assert(sizeof(struct PC_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct PC_extra_alignment) == 1, "");
_Static_assert(sizeof(struct PC_extra_packed) == 5, "");
_Static_assert(_Alignof(struct PC_extra_packed) == 1, "");
_Static_assert(sizeof(struct PC_extra_required_alignment) == 6, "");
_Static_assert(_Alignof(struct PC_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct PC_extra_size) == 7, "");
_Static_assert(_Alignof(struct PC_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(PC,x) == 8, "");
#endif
_Static_assert(sizeof(PD) == 4, "");
_Static_assert(_Alignof(PD) == 8, "");
_Static_assert(sizeof(struct PD_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct PD_extra_alignment) == 8, "");
_Static_assert(sizeof(struct PD_extra_packed) == 4, "");
_Static_assert(_Alignof(struct PD_extra_packed) == 1, "");
_Static_assert(sizeof(struct PD_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct PD_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct PD_extra_size) == 6, "");
_Static_assert(_Alignof(struct PD_extra_size) == 1, "");
_Static_assert(sizeof(PE) == 5, "");
_Static_assert(_Alignof(PE) == 1, "");
_Static_assert(sizeof(struct PE_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct PE_extra_alignment) == 1, "");
_Static_assert(sizeof(struct PE_extra_packed) == 5, "");
_Static_assert(_Alignof(struct PE_extra_packed) == 1, "");
_Static_assert(sizeof(struct PE_extra_required_alignment) == 6, "");
_Static_assert(_Alignof(struct PE_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct PE_extra_size) == 7, "");
_Static_assert(_Alignof(struct PE_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(PE,x) == 8, "");
#endif
_Static_assert(sizeof(QA) == 2, "");
_Static_assert(_Alignof(QA) == 2, "");
_Static_assert(sizeof(struct QA_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct QA_extra_alignment) == 2, "");
_Static_assert(sizeof(struct QA_extra_packed) == 2, "");
_Static_assert(_Alignof(struct QA_extra_packed) == 1, "");
_Static_assert(sizeof(struct QA_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct QA_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct QA_extra_size) == 4, "");
_Static_assert(_Alignof(struct QA_extra_size) == 1, "");
_Static_assert(sizeof(QB) == 3, "");
_Static_assert(_Alignof(QB) == 1, "");
_Static_assert(sizeof(struct QB_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct QB_extra_alignment) == 1, "");
_Static_assert(sizeof(struct QB_extra_packed) == 3, "");
_Static_assert(_Alignof(struct QB_extra_packed) == 1, "");
_Static_assert(sizeof(struct QB_extra_required_alignment) == 4, "");
_Static_assert(_Alignof(struct QB_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct QB_extra_size) == 5, "");
_Static_assert(_Alignof(struct QB_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(QB,b) == 8, "");
#endif
_Static_assert(sizeof(QC) == 4, "");
_Static_assert(_Alignof(QC) == 2, "");
_Static_assert(sizeof(struct QC_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct QC_extra_alignment) == 2, "");
_Static_assert(sizeof(struct QC_extra_packed) == 4, "");
_Static_assert(_Alignof(struct QC_extra_packed) == 1, "");
_Static_assert(sizeof(struct QC_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct QC_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct QC_extra_size) == 6, "");
_Static_assert(_Alignof(struct QC_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(QC,b) == 16, "");
#endif
_Static_assert(sizeof(QD) == 2, "");
_Static_assert(_Alignof(QD) == 2, "");
_Static_assert(sizeof(struct QD_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct QD_extra_alignment) == 2, "");
_Static_assert(sizeof(struct QD_extra_packed) == 2, "");
_Static_assert(_Alignof(struct QD_extra_packed) == 1, "");
_Static_assert(sizeof(struct QD_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct QD_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct QD_extra_size) == 4, "");
_Static_assert(_Alignof(struct QD_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(QD,b) == 8, "");
#endif
_Static_assert(sizeof(EmptyAlignedLongLongMemb) == 0, "");
_Static_assert(_Alignof(EmptyAlignedLongLongMemb) == 4, "");
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_extra_alignment) == 4, "");
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_extra_packed) == 0, "");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_extra_packed) == 1, "");
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_extra_size) == 2, "");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_extra_size) == 1, "");
_Static_assert(sizeof(EmptyPackedAlignedLongLongMemb) == 0, "");
_Static_assert(_Alignof(EmptyPackedAlignedLongLongMemb) == 4, "");
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_extra_alignment) == 4, "");
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_extra_packed) == 0, "");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_extra_packed) == 1, "");
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_extra_size) == 2, "");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_extra_size) == 1, "");
// MAPPING|TEN|thumb-baseline-windows-msvc:Msvc|END
// repr targets Thumbv7aPcWindowsMsvc|Some("thumb-baseline-windows-msvc") 
#elif defined(TEN)
_Static_assert(sizeof(A) == 1, "");
_Static_assert(_Alignof(A) == 1, "");
_Static_assert(sizeof(struct A_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct A_extra_alignment) == 1, "");
_Static_assert(sizeof(struct A_extra_packed) == 1, "");
_Static_assert(_Alignof(struct A_extra_packed) == 1, "");
_Static_assert(sizeof(struct A_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct A_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A_extra_size) == 3, "");
_Static_assert(_Alignof(struct A_extra_size) == 1, "");
_Static_assert(sizeof(B) == 8, "");
_Static_assert(_Alignof(B) == 8, "");
_Static_assert(sizeof(struct B_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct B_extra_alignment) == 8, "");
_Static_assert(sizeof(struct B_extra_packed) == 8, "");
_Static_assert(_Alignof(struct B_extra_packed) == 1, "");
_Static_assert(sizeof(struct B_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct B_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B_extra_size) == 10, "");
_Static_assert(_Alignof(struct B_extra_size) == 1, "");
_Static_assert(sizeof(X) == 16, "");
_Static_assert(_Alignof(X) == 4, "");
_Static_assert(sizeof(struct X_extra_alignment) == 20, "");
_Static_assert(_Alignof(struct X_extra_alignment) == 4, "");
_Static_assert(sizeof(struct X_extra_packed) == 16, "");
_Static_assert(_Alignof(struct X_extra_packed) == 1, "");
_Static_assert(sizeof(struct X_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct X_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct X_extra_size) == 18, "");
_Static_assert(_Alignof(struct X_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(X,b) == 64, "");
_Static_assert(__builtin_bitoffsetof(X,c) == 80, "");
#endif
_Static_assert(sizeof(YA) == 16, "");
_Static_assert(_Alignof(YA) == 32, "");
_Static_assert(sizeof(struct YA_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct YA_extra_alignment) == 32, "");
_Static_assert(sizeof(struct YA_extra_packed) == 16, "");
_Static_assert(_Alignof(struct YA_extra_packed) == 1, "");
_Static_assert(sizeof(struct YA_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct YA_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct YA_extra_size) == 18, "");
_Static_assert(_Alignof(struct YA_extra_size) == 1, "");
_Static_assert(sizeof(YB) == 17, "");
_Static_assert(_Alignof(YB) == 1, "");
_Static_assert(sizeof(struct YB_extra_alignment) == 18, "");
_Static_assert(_Alignof(struct YB_extra_alignment) == 1, "");
_Static_assert(sizeof(struct YB_extra_packed) == 17, "");
_Static_assert(_Alignof(struct YB_extra_packed) == 1, "");
_Static_assert(sizeof(struct YB_extra_required_alignment) == 18, "");
_Static_assert(_Alignof(struct YB_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct YB_extra_size) == 19, "");
_Static_assert(_Alignof(struct YB_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(YB,b) == 8, "");
#endif
_Static_assert(sizeof(YC) == 8, "");
_Static_assert(_Alignof(YC) == 32, "");
_Static_assert(sizeof(struct YC_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct YC_extra_alignment) == 32, "");
_Static_assert(sizeof(struct YC_extra_packed) == 8, "");
_Static_assert(_Alignof(struct YC_extra_packed) == 1, "");
_Static_assert(sizeof(struct YC_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct YC_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct YC_extra_size) == 10, "");
_Static_assert(_Alignof(struct YC_extra_size) == 1, "");
_Static_assert(sizeof(YD) == 9, "");
_Static_assert(_Alignof(YD) == 1, "");
_Static_assert(sizeof(struct YD_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct YD_extra_alignment) == 1, "");
_Static_assert(sizeof(struct YD_extra_packed) == 9, "");
_Static_assert(_Alignof(struct YD_extra_packed) == 1, "");
_Static_assert(sizeof(struct YD_extra_required_alignment) == 10, "");
_Static_assert(_Alignof(struct YD_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct YD_extra_size) == 11, "");
_Static_assert(_Alignof(struct YD_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(YD,b) == 8, "");
#endif
_Static_assert(sizeof(YE) == 4, "");
_Static_assert(_Alignof(YE) == 32, "");
_Static_assert(sizeof(struct YE_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct YE_extra_alignment) == 32, "");
_Static_assert(sizeof(struct YE_extra_packed) == 4, "");
_Static_assert(_Alignof(struct YE_extra_packed) == 1, "");
_Static_assert(sizeof(struct YE_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct YE_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct YE_extra_size) == 6, "");
_Static_assert(_Alignof(struct YE_extra_size) == 1, "");
_Static_assert(sizeof(YF) == 5, "");
_Static_assert(_Alignof(YF) == 1, "");
_Static_assert(sizeof(struct YF_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct YF_extra_alignment) == 1, "");
_Static_assert(sizeof(struct YF_extra_packed) == 5, "");
_Static_assert(_Alignof(struct YF_extra_packed) == 1, "");
_Static_assert(sizeof(struct YF_extra_required_alignment) == 6, "");
_Static_assert(_Alignof(struct YF_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct YF_extra_size) == 7, "");
_Static_assert(_Alignof(struct YF_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(YF,b) == 8, "");
#endif
_Static_assert(sizeof(D0) == 16, "");
_Static_assert(_Alignof(D0) == 16, "");
_Static_assert(sizeof(struct D0_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct D0_extra_alignment) == 16, "");
_Static_assert(sizeof(struct D0_extra_packed) == 16, "");
_Static_assert(_Alignof(struct D0_extra_packed) == 1, "");
_Static_assert(sizeof(struct D0_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct D0_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct D0_extra_size) == 18, "");
_Static_assert(_Alignof(struct D0_extra_size) == 1, "");
_Static_assert(sizeof(RB0) == 8, "");
_Static_assert(_Alignof(RB0) == 1024, "");
_Static_assert(sizeof(struct RB0_extra_alignment) == 2048, "");
_Static_assert(_Alignof(struct RB0_extra_alignment) == 1024, "");
_Static_assert(sizeof(struct RB0_extra_packed) == 8, "");
_Static_assert(_Alignof(struct RB0_extra_packed) == 1, "");
_Static_assert(sizeof(struct RB0_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct RB0_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct RB0_extra_size) == 10, "");
_Static_assert(_Alignof(struct RB0_extra_size) == 1, "");
_Static_assert(sizeof(RC) == 1028, "");
_Static_assert(_Alignof(RC) == 1024, "");
_Static_assert(sizeof(struct RC_extra_alignment) == 3072, "");
_Static_assert(_Alignof(struct RC_extra_alignment) == 1024, "");
_Static_assert(sizeof(struct RC_extra_packed) == 1028, "");
_Static_assert(_Alignof(struct RC_extra_packed) == 1, "");
_Static_assert(sizeof(struct RC_extra_required_alignment) == 1029, "");
_Static_assert(_Alignof(struct RC_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct RC_extra_size) == 1030, "");
_Static_assert(_Alignof(struct RC_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(RC,c) == 8192, "");
#endif
_Static_assert(sizeof(RE) == 1029, "");
_Static_assert(_Alignof(RE) == 1, "");
_Static_assert(sizeof(struct RE_extra_alignment) == 1030, "");
_Static_assert(_Alignof(struct RE_extra_alignment) == 1, "");
_Static_assert(sizeof(struct RE_extra_packed) == 1029, "");
_Static_assert(_Alignof(struct RE_extra_packed) == 1, "");
_Static_assert(sizeof(struct RE_extra_required_alignment) == 1030, "");
_Static_assert(_Alignof(struct RE_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct RE_extra_size) == 1031, "");
_Static_assert(_Alignof(struct RE_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(RE,c) == 8, "");
#endif
_Static_assert(sizeof(PA) == 4, "");
_Static_assert(_Alignof(PA) == 4, "");
_Static_assert(sizeof(struct PA_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct PA_extra_alignment) == 4, "");
_Static_assert(sizeof(struct PA_extra_packed) == 4, "");
_Static_assert(_Alignof(struct PA_extra_packed) == 1, "");
_Static_assert(sizeof(struct PA_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct PA_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct PA_extra_size) == 6, "");
_Static_assert(_Alignof(struct PA_extra_size) == 1, "");
_Static_assert(sizeof(PB) == 4, "");
_Static_assert(_Alignof(PB) == 8, "");
_Static_assert(sizeof(struct PB_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct PB_extra_alignment) == 8, "");
_Static_assert(sizeof(struct PB_extra_packed) == 4, "");
_Static_assert(_Alignof(struct PB_extra_packed) == 1, "");
_Static_assert(sizeof(struct PB_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct PB_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct PB_extra_size) == 6, "");
_Static_assert(_Alignof(struct PB_extra_size) == 1, "");
_Static_assert(sizeof(PC) == 16, "");
_Static_assert(_Alignof(PC) == 8, "");
_Static_assert(sizeof(struct PC_extra_alignment) == 24, "");
_Static_assert(_Alignof(struct PC_extra_alignment) == 8, "");
_Static_assert(sizeof(struct PC_extra_packed) == 16, "");
_Static_assert(_Alignof(struct PC_extra_packed) == 1, "");
_Static_assert(sizeof(struct PC_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct PC_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct PC_extra_size) == 18, "");
_Static_assert(_Alignof(struct PC_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(PC,x) == 64, "");
#endif
_Static_assert(sizeof(PD) == 4, "");
_Static_assert(_Alignof(PD) == 8, "");
_Static_assert(sizeof(struct PD_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct PD_extra_alignment) == 8, "");
_Static_assert(sizeof(struct PD_extra_packed) == 4, "");
_Static_assert(_Alignof(struct PD_extra_packed) == 1, "");
_Static_assert(sizeof(struct PD_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct PD_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct PD_extra_size) == 6, "");
_Static_assert(_Alignof(struct PD_extra_size) == 1, "");
_Static_assert(sizeof(PE) == 16, "");
_Static_assert(_Alignof(PE) == 8, "");
_Static_assert(sizeof(struct PE_extra_alignment) == 24, "");
_Static_assert(_Alignof(struct PE_extra_alignment) == 8, "");
_Static_assert(sizeof(struct PE_extra_packed) == 16, "");
_Static_assert(_Alignof(struct PE_extra_packed) == 1, "");
_Static_assert(sizeof(struct PE_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct PE_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct PE_extra_size) == 18, "");
_Static_assert(_Alignof(struct PE_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(PE,x) == 64, "");
#endif
_Static_assert(sizeof(QA) == 4, "");
_Static_assert(_Alignof(QA) == 4, "");
_Static_assert(sizeof(struct QA_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct QA_extra_alignment) == 4, "");
_Static_assert(sizeof(struct QA_extra_packed) == 4, "");
_Static_assert(_Alignof(struct QA_extra_packed) == 1, "");
_Static_assert(sizeof(struct QA_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct QA_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct QA_extra_size) == 6, "");
_Static_assert(_Alignof(struct QA_extra_size) == 1, "");
_Static_assert(sizeof(QB) == 6, "");
_Static_assert(_Alignof(QB) == 2, "");
_Static_assert(sizeof(struct QB_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct QB_extra_alignment) == 2, "");
_Static_assert(sizeof(struct QB_extra_packed) == 6, "");
_Static_assert(_Alignof(struct QB_extra_packed) == 1, "");
_Static_assert(sizeof(struct QB_extra_required_alignment) == 7, "");
_Static_assert(_Alignof(struct QB_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct QB_extra_size) == 8, "");
_Static_assert(_Alignof(struct QB_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(QB,b) == 16, "");
#endif
_Static_assert(sizeof(QC) == 8, "");
_Static_assert(_Alignof(QC) == 4, "");
_Static_assert(sizeof(struct QC_extra_alignment) == 12, "");
_Static_assert(_Alignof(struct QC_extra_alignment) == 4, "");
_Static_assert(sizeof(struct QC_extra_packed) == 8, "");
_Static_assert(_Alignof(struct QC_extra_packed) == 1, "");
_Static_assert(sizeof(struct QC_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct QC_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct QC_extra_size) == 10, "");
_Static_assert(_Alignof(struct QC_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(QC,b) == 32, "");
#endif
_Static_assert(sizeof(QD) == 8, "");
_Static_assert(_Alignof(QD) == 4, "");
_Static_assert(sizeof(struct QD_extra_alignment) == 12, "");
_Static_assert(_Alignof(struct QD_extra_alignment) == 4, "");
_Static_assert(sizeof(struct QD_extra_packed) == 8, "");
_Static_assert(_Alignof(struct QD_extra_packed) == 1, "");
_Static_assert(sizeof(struct QD_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct QD_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct QD_extra_size) == 10, "");
_Static_assert(_Alignof(struct QD_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(QD,b) == 32, "");
#endif
_Static_assert(sizeof(EmptyAlignedLongLongMemb) == 4, "");
_Static_assert(_Alignof(EmptyAlignedLongLongMemb) == 8, "");
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_extra_alignment) == 8, "");
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_extra_packed) == 4, "");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_extra_packed) == 1, "");
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct EmptyAlignedLongLongMemb_extra_size) == 6, "");
_Static_assert(_Alignof(struct EmptyAlignedLongLongMemb_extra_size) == 1, "");
_Static_assert(sizeof(EmptyPackedAlignedLongLongMemb) == 4, "");
_Static_assert(_Alignof(EmptyPackedAlignedLongLongMemb) == 4, "");
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_extra_alignment) == 4, "");
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_extra_packed) == 4, "");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_extra_packed) == 1, "");
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct EmptyPackedAlignedLongLongMemb_extra_size) == 6, "");
_Static_assert(_Alignof(struct EmptyPackedAlignedLongLongMemb_extra_size) == 1, "");
#endif
