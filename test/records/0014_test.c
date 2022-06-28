// SPDX-License-Identifier: GPL-3.0-or-later

// This test file is auto-generated. do not edit.
// This file is a derivative work from the test files found// in this repo : https://github.com/mahkoh/repr-c
// and is under the same licence as the original work.

#ifdef MSVC
__declspec(align(1)) typedef int A;
#else
typedef int A __attribute__((aligned(1)));
#endif
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
__declspec(align(2)) typedef int B;
#else
typedef int B __attribute__((aligned(2)));
#endif
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

#ifdef MSVC
__declspec(align(4)) typedef int C;
#else
typedef int C __attribute__((aligned(4)));
#endif
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

#ifdef MSVC
__declspec(align(8)) typedef int D;
#else
typedef int D __attribute__((aligned(8)));
#endif
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

#ifdef MSVC
__declspec(align(16)) typedef int E;
#else
typedef int E __attribute__((aligned(16)));
#endif
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

#ifdef MSVC
__declspec(align(32)) typedef int F;
#else
typedef int F __attribute__((aligned(32)));
#endif
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

#ifdef MSVC
__declspec(align(64)) typedef int G;
#else
typedef int G __attribute__((aligned(64)));
#endif
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

#ifdef MSVC
__declspec(align(128)) typedef int H;
#else
typedef int H __attribute__((aligned(128)));
#endif
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

#ifdef MSVC
__declspec(align(1)) typedef A AA;
#else
typedef A AA __attribute__((aligned(1)));
#endif
AA var33;
struct AA_alignment {
#ifdef MSVC
    char a[_Alignof(AA)];
    char b;
#else
    char a;
    AA b;
#endif
};
struct AA_alignment var34;
#pragma pack(1)
struct AA_packed {
    AA a;
};
#pragma pack()
struct AA_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct AA_packed)];
    char b;
#else
    char a;
    struct AA_packed b;
#endif
};
struct AA_required_alignment var35;
struct AA_size {
    char a[sizeof(AA)+1];
    char b;
};
struct AA_size var36;

#ifdef MSVC
__declspec(align(2)) typedef A AB;
#else
typedef A AB __attribute__((aligned(2)));
#endif
AB var37;
struct AB_alignment {
#ifdef MSVC
    char a[_Alignof(AB)];
    char b;
#else
    char a;
    AB b;
#endif
};
struct AB_alignment var38;
#pragma pack(1)
struct AB_packed {
    AB a;
};
#pragma pack()
struct AB_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct AB_packed)];
    char b;
#else
    char a;
    struct AB_packed b;
#endif
};
struct AB_required_alignment var39;
struct AB_size {
    char a[sizeof(AB)+1];
    char b;
};
struct AB_size var40;

#ifdef MSVC
__declspec(align(4)) typedef A AC;
#else
typedef A AC __attribute__((aligned(4)));
#endif
AC var41;
struct AC_alignment {
#ifdef MSVC
    char a[_Alignof(AC)];
    char b;
#else
    char a;
    AC b;
#endif
};
struct AC_alignment var42;
#pragma pack(1)
struct AC_packed {
    AC a;
};
#pragma pack()
struct AC_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct AC_packed)];
    char b;
#else
    char a;
    struct AC_packed b;
#endif
};
struct AC_required_alignment var43;
struct AC_size {
    char a[sizeof(AC)+1];
    char b;
};
struct AC_size var44;

#ifdef MSVC
__declspec(align(8)) typedef A AD;
#else
typedef A AD __attribute__((aligned(8)));
#endif
AD var45;
struct AD_alignment {
#ifdef MSVC
    char a[_Alignof(AD)];
    char b;
#else
    char a;
    AD b;
#endif
};
struct AD_alignment var46;
#pragma pack(1)
struct AD_packed {
    AD a;
};
#pragma pack()
struct AD_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct AD_packed)];
    char b;
#else
    char a;
    struct AD_packed b;
#endif
};
struct AD_required_alignment var47;
struct AD_size {
    char a[sizeof(AD)+1];
    char b;
};
struct AD_size var48;

#ifdef MSVC
__declspec(align(16)) typedef A AE;
#else
typedef A AE __attribute__((aligned(16)));
#endif
AE var49;
struct AE_alignment {
#ifdef MSVC
    char a[_Alignof(AE)];
    char b;
#else
    char a;
    AE b;
#endif
};
struct AE_alignment var50;
#pragma pack(1)
struct AE_packed {
    AE a;
};
#pragma pack()
struct AE_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct AE_packed)];
    char b;
#else
    char a;
    struct AE_packed b;
#endif
};
struct AE_required_alignment var51;
struct AE_size {
    char a[sizeof(AE)+1];
    char b;
};
struct AE_size var52;

#ifdef MSVC
__declspec(align(32)) typedef A AF;
#else
typedef A AF __attribute__((aligned(32)));
#endif
AF var53;
struct AF_alignment {
#ifdef MSVC
    char a[_Alignof(AF)];
    char b;
#else
    char a;
    AF b;
#endif
};
struct AF_alignment var54;
#pragma pack(1)
struct AF_packed {
    AF a;
};
#pragma pack()
struct AF_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct AF_packed)];
    char b;
#else
    char a;
    struct AF_packed b;
#endif
};
struct AF_required_alignment var55;
struct AF_size {
    char a[sizeof(AF)+1];
    char b;
};
struct AF_size var56;

#ifdef MSVC
__declspec(align(64)) typedef A AG;
#else
typedef A AG __attribute__((aligned(64)));
#endif
AG var57;
struct AG_alignment {
#ifdef MSVC
    char a[_Alignof(AG)];
    char b;
#else
    char a;
    AG b;
#endif
};
struct AG_alignment var58;
#pragma pack(1)
struct AG_packed {
    AG a;
};
#pragma pack()
struct AG_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct AG_packed)];
    char b;
#else
    char a;
    struct AG_packed b;
#endif
};
struct AG_required_alignment var59;
struct AG_size {
    char a[sizeof(AG)+1];
    char b;
};
struct AG_size var60;

#ifdef MSVC
__declspec(align(128)) typedef A AH;
#else
typedef A AH __attribute__((aligned(128)));
#endif
AH var61;
struct AH_alignment {
#ifdef MSVC
    char a[_Alignof(AH)];
    char b;
#else
    char a;
    AH b;
#endif
};
struct AH_alignment var62;
#pragma pack(1)
struct AH_packed {
    AH a;
};
#pragma pack()
struct AH_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct AH_packed)];
    char b;
#else
    char a;
    struct AH_packed b;
#endif
};
struct AH_required_alignment var63;
struct AH_size {
    char a[sizeof(AH)+1];
    char b;
};
struct AH_size var64;

#ifdef MSVC
__declspec(align(1)) typedef B BA;
#else
typedef B BA __attribute__((aligned(1)));
#endif
BA var65;
struct BA_alignment {
#ifdef MSVC
    char a[_Alignof(BA)];
    char b;
#else
    char a;
    BA b;
#endif
};
struct BA_alignment var66;
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
struct BA_required_alignment var67;
struct BA_size {
    char a[sizeof(BA)+1];
    char b;
};
struct BA_size var68;

#ifdef MSVC
__declspec(align(2)) typedef B BB;
#else
typedef B BB __attribute__((aligned(2)));
#endif
BB var69;
struct BB_alignment {
#ifdef MSVC
    char a[_Alignof(BB)];
    char b;
#else
    char a;
    BB b;
#endif
};
struct BB_alignment var70;
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
struct BB_required_alignment var71;
struct BB_size {
    char a[sizeof(BB)+1];
    char b;
};
struct BB_size var72;

#ifdef MSVC
__declspec(align(4)) typedef B BC;
#else
typedef B BC __attribute__((aligned(4)));
#endif
BC var73;
struct BC_alignment {
#ifdef MSVC
    char a[_Alignof(BC)];
    char b;
#else
    char a;
    BC b;
#endif
};
struct BC_alignment var74;
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
struct BC_required_alignment var75;
struct BC_size {
    char a[sizeof(BC)+1];
    char b;
};
struct BC_size var76;

#ifdef MSVC
__declspec(align(8)) typedef B BD;
#else
typedef B BD __attribute__((aligned(8)));
#endif
BD var77;
struct BD_alignment {
#ifdef MSVC
    char a[_Alignof(BD)];
    char b;
#else
    char a;
    BD b;
#endif
};
struct BD_alignment var78;
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
struct BD_required_alignment var79;
struct BD_size {
    char a[sizeof(BD)+1];
    char b;
};
struct BD_size var80;

#ifdef MSVC
__declspec(align(16)) typedef B BE;
#else
typedef B BE __attribute__((aligned(16)));
#endif
BE var81;
struct BE_alignment {
#ifdef MSVC
    char a[_Alignof(BE)];
    char b;
#else
    char a;
    BE b;
#endif
};
struct BE_alignment var82;
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
struct BE_required_alignment var83;
struct BE_size {
    char a[sizeof(BE)+1];
    char b;
};
struct BE_size var84;

#ifdef MSVC
__declspec(align(32)) typedef B BF;
#else
typedef B BF __attribute__((aligned(32)));
#endif
BF var85;
struct BF_alignment {
#ifdef MSVC
    char a[_Alignof(BF)];
    char b;
#else
    char a;
    BF b;
#endif
};
struct BF_alignment var86;
#pragma pack(1)
struct BF_packed {
    BF a;
};
#pragma pack()
struct BF_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct BF_packed)];
    char b;
#else
    char a;
    struct BF_packed b;
#endif
};
struct BF_required_alignment var87;
struct BF_size {
    char a[sizeof(BF)+1];
    char b;
};
struct BF_size var88;

#ifdef MSVC
__declspec(align(64)) typedef B BG;
#else
typedef B BG __attribute__((aligned(64)));
#endif
BG var89;
struct BG_alignment {
#ifdef MSVC
    char a[_Alignof(BG)];
    char b;
#else
    char a;
    BG b;
#endif
};
struct BG_alignment var90;
#pragma pack(1)
struct BG_packed {
    BG a;
};
#pragma pack()
struct BG_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct BG_packed)];
    char b;
#else
    char a;
    struct BG_packed b;
#endif
};
struct BG_required_alignment var91;
struct BG_size {
    char a[sizeof(BG)+1];
    char b;
};
struct BG_size var92;

#ifdef MSVC
__declspec(align(128)) typedef B BH;
#else
typedef B BH __attribute__((aligned(128)));
#endif
BH var93;
struct BH_alignment {
#ifdef MSVC
    char a[_Alignof(BH)];
    char b;
#else
    char a;
    BH b;
#endif
};
struct BH_alignment var94;
#pragma pack(1)
struct BH_packed {
    BH a;
};
#pragma pack()
struct BH_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct BH_packed)];
    char b;
#else
    char a;
    struct BH_packed b;
#endif
};
struct BH_required_alignment var95;
struct BH_size {
    char a[sizeof(BH)+1];
    char b;
};
struct BH_size var96;

#ifdef MSVC
__declspec(align(1)) typedef D DA;
#else
typedef D DA __attribute__((aligned(1)));
#endif
DA var97;
struct DA_alignment {
#ifdef MSVC
    char a[_Alignof(DA)];
    char b;
#else
    char a;
    DA b;
#endif
};
struct DA_alignment var98;
#pragma pack(1)
struct DA_packed {
    DA a;
};
#pragma pack()
struct DA_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct DA_packed)];
    char b;
#else
    char a;
    struct DA_packed b;
#endif
};
struct DA_required_alignment var99;
struct DA_size {
    char a[sizeof(DA)+1];
    char b;
};
struct DA_size var100;

#ifdef MSVC
__declspec(align(2)) typedef D DB;
#else
typedef D DB __attribute__((aligned(2)));
#endif
DB var101;
struct DB_alignment {
#ifdef MSVC
    char a[_Alignof(DB)];
    char b;
#else
    char a;
    DB b;
#endif
};
struct DB_alignment var102;
#pragma pack(1)
struct DB_packed {
    DB a;
};
#pragma pack()
struct DB_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct DB_packed)];
    char b;
#else
    char a;
    struct DB_packed b;
#endif
};
struct DB_required_alignment var103;
struct DB_size {
    char a[sizeof(DB)+1];
    char b;
};
struct DB_size var104;

#ifdef MSVC
__declspec(align(4)) typedef D DC;
#else
typedef D DC __attribute__((aligned(4)));
#endif
DC var105;
struct DC_alignment {
#ifdef MSVC
    char a[_Alignof(DC)];
    char b;
#else
    char a;
    DC b;
#endif
};
struct DC_alignment var106;
#pragma pack(1)
struct DC_packed {
    DC a;
};
#pragma pack()
struct DC_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct DC_packed)];
    char b;
#else
    char a;
    struct DC_packed b;
#endif
};
struct DC_required_alignment var107;
struct DC_size {
    char a[sizeof(DC)+1];
    char b;
};
struct DC_size var108;

#ifdef MSVC
__declspec(align(8)) typedef D DD;
#else
typedef D DD __attribute__((aligned(8)));
#endif
DD var109;
struct DD_alignment {
#ifdef MSVC
    char a[_Alignof(DD)];
    char b;
#else
    char a;
    DD b;
#endif
};
struct DD_alignment var110;
#pragma pack(1)
struct DD_packed {
    DD a;
};
#pragma pack()
struct DD_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct DD_packed)];
    char b;
#else
    char a;
    struct DD_packed b;
#endif
};
struct DD_required_alignment var111;
struct DD_size {
    char a[sizeof(DD)+1];
    char b;
};
struct DD_size var112;

#ifdef MSVC
__declspec(align(16)) typedef D DE;
#else
typedef D DE __attribute__((aligned(16)));
#endif
DE var113;
struct DE_alignment {
#ifdef MSVC
    char a[_Alignof(DE)];
    char b;
#else
    char a;
    DE b;
#endif
};
struct DE_alignment var114;
#pragma pack(1)
struct DE_packed {
    DE a;
};
#pragma pack()
struct DE_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct DE_packed)];
    char b;
#else
    char a;
    struct DE_packed b;
#endif
};
struct DE_required_alignment var115;
struct DE_size {
    char a[sizeof(DE)+1];
    char b;
};
struct DE_size var116;

#ifdef MSVC
__declspec(align(32)) typedef D DF;
#else
typedef D DF __attribute__((aligned(32)));
#endif
DF var117;
struct DF_alignment {
#ifdef MSVC
    char a[_Alignof(DF)];
    char b;
#else
    char a;
    DF b;
#endif
};
struct DF_alignment var118;
#pragma pack(1)
struct DF_packed {
    DF a;
};
#pragma pack()
struct DF_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct DF_packed)];
    char b;
#else
    char a;
    struct DF_packed b;
#endif
};
struct DF_required_alignment var119;
struct DF_size {
    char a[sizeof(DF)+1];
    char b;
};
struct DF_size var120;

#ifdef MSVC
__declspec(align(64)) typedef D DG;
#else
typedef D DG __attribute__((aligned(64)));
#endif
DG var121;
struct DG_alignment {
#ifdef MSVC
    char a[_Alignof(DG)];
    char b;
#else
    char a;
    DG b;
#endif
};
struct DG_alignment var122;
#pragma pack(1)
struct DG_packed {
    DG a;
};
#pragma pack()
struct DG_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct DG_packed)];
    char b;
#else
    char a;
    struct DG_packed b;
#endif
};
struct DG_required_alignment var123;
struct DG_size {
    char a[sizeof(DG)+1];
    char b;
};
struct DG_size var124;

#ifdef MSVC
__declspec(align(128)) typedef D DH;
#else
typedef D DH __attribute__((aligned(128)));
#endif
DH var125;
struct DH_alignment {
#ifdef MSVC
    char a[_Alignof(DH)];
    char b;
#else
    char a;
    DH b;
#endif
};
struct DH_alignment var126;
#pragma pack(1)
struct DH_packed {
    DH a;
};
#pragma pack()
struct DH_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct DH_packed)];
    char b;
#else
    char a;
    struct DH_packed b;
#endif
};
struct DH_required_alignment var127;
struct DH_size {
    char a[sizeof(DH)+1];
    char b;
};
struct DH_size var128;

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
_Static_assert(_Alignof(B) == 2, "record B wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 6, "record B_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_alignment) == 2, "record B_alignment wrong alignment");
_Static_assert(sizeof(struct B_packed) == 4, "record B_packed wrong sizeof");
_Static_assert(_Alignof(struct B_packed) == 1, "record B_packed wrong alignment");
_Static_assert(sizeof(struct B_required_alignment) == 5, "record B_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "record B_required_alignment wrong alignment");
_Static_assert(sizeof(struct B_size) == 6, "record B_size wrong sizeof");
_Static_assert(_Alignof(struct B_size) == 1, "record B_size wrong alignment");
#endif
_Static_assert(sizeof(C) == 4, "record C wrong sizeof");
_Static_assert(_Alignof(C) == 4, "record C wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 8, "record C_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_alignment) == 4, "record C_alignment wrong alignment");
_Static_assert(sizeof(struct C_packed) == 4, "record C_packed wrong sizeof");
_Static_assert(_Alignof(struct C_packed) == 1, "record C_packed wrong alignment");
_Static_assert(sizeof(struct C_required_alignment) == 5, "record C_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "record C_required_alignment wrong alignment");
_Static_assert(sizeof(struct C_size) == 6, "record C_size wrong sizeof");
_Static_assert(_Alignof(struct C_size) == 1, "record C_size wrong alignment");
#endif
_Static_assert(sizeof(D) == 4, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 8, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 16, "record D_alignment wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 8, "record D_alignment wrong alignment");
_Static_assert(sizeof(struct D_packed) == 4, "record D_packed wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D_packed wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 5, "record D_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D_required_alignment wrong alignment");
_Static_assert(sizeof(struct D_size) == 6, "record D_size wrong sizeof");
_Static_assert(_Alignof(struct D_size) == 1, "record D_size wrong alignment");
#endif
_Static_assert(sizeof(E) == 4, "record E wrong sizeof");
_Static_assert(_Alignof(E) == 16, "record E wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 32, "record E_alignment wrong sizeof");
_Static_assert(_Alignof(struct E_alignment) == 16, "record E_alignment wrong alignment");
_Static_assert(sizeof(struct E_packed) == 4, "record E_packed wrong sizeof");
_Static_assert(_Alignof(struct E_packed) == 1, "record E_packed wrong alignment");
_Static_assert(sizeof(struct E_required_alignment) == 5, "record E_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "record E_required_alignment wrong alignment");
_Static_assert(sizeof(struct E_size) == 6, "record E_size wrong sizeof");
_Static_assert(_Alignof(struct E_size) == 1, "record E_size wrong alignment");
#endif
_Static_assert(sizeof(F) == 4, "record F wrong sizeof");
_Static_assert(_Alignof(F) == 32, "record F wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 64, "record F_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_alignment) == 32, "record F_alignment wrong alignment");
_Static_assert(sizeof(struct F_packed) == 4, "record F_packed wrong sizeof");
_Static_assert(_Alignof(struct F_packed) == 1, "record F_packed wrong alignment");
_Static_assert(sizeof(struct F_required_alignment) == 5, "record F_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "record F_required_alignment wrong alignment");
_Static_assert(sizeof(struct F_size) == 6, "record F_size wrong sizeof");
_Static_assert(_Alignof(struct F_size) == 1, "record F_size wrong alignment");
#endif
_Static_assert(sizeof(G) == 4, "record G wrong sizeof");
_Static_assert(_Alignof(G) == 64, "record G wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 128, "record G_alignment wrong sizeof");
_Static_assert(_Alignof(struct G_alignment) == 64, "record G_alignment wrong alignment");
_Static_assert(sizeof(struct G_packed) == 4, "record G_packed wrong sizeof");
_Static_assert(_Alignof(struct G_packed) == 1, "record G_packed wrong alignment");
_Static_assert(sizeof(struct G_required_alignment) == 5, "record G_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "record G_required_alignment wrong alignment");
_Static_assert(sizeof(struct G_size) == 6, "record G_size wrong sizeof");
_Static_assert(_Alignof(struct G_size) == 1, "record G_size wrong alignment");
#endif
_Static_assert(sizeof(H) == 4, "record H wrong sizeof");
_Static_assert(_Alignof(H) == 128, "record H wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 256, "record H_alignment wrong sizeof");
_Static_assert(_Alignof(struct H_alignment) == 128, "record H_alignment wrong alignment");
_Static_assert(sizeof(struct H_packed) == 4, "record H_packed wrong sizeof");
_Static_assert(_Alignof(struct H_packed) == 1, "record H_packed wrong alignment");
_Static_assert(sizeof(struct H_required_alignment) == 5, "record H_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "record H_required_alignment wrong alignment");
_Static_assert(sizeof(struct H_size) == 6, "record H_size wrong sizeof");
_Static_assert(_Alignof(struct H_size) == 1, "record H_size wrong alignment");
#endif
_Static_assert(sizeof(AA) == 4, "record AA wrong sizeof");
_Static_assert(_Alignof(AA) == 1, "record AA wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct AA_alignment) == 5, "record AA_alignment wrong sizeof");
_Static_assert(_Alignof(struct AA_alignment) == 1, "record AA_alignment wrong alignment");
_Static_assert(sizeof(struct AA_packed) == 4, "record AA_packed wrong sizeof");
_Static_assert(_Alignof(struct AA_packed) == 1, "record AA_packed wrong alignment");
_Static_assert(sizeof(struct AA_required_alignment) == 5, "record AA_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct AA_required_alignment) == 1, "record AA_required_alignment wrong alignment");
_Static_assert(sizeof(struct AA_size) == 6, "record AA_size wrong sizeof");
_Static_assert(_Alignof(struct AA_size) == 1, "record AA_size wrong alignment");
#endif
_Static_assert(sizeof(AB) == 4, "record AB wrong sizeof");
_Static_assert(_Alignof(AB) == 2, "record AB wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct AB_alignment) == 6, "record AB_alignment wrong sizeof");
_Static_assert(_Alignof(struct AB_alignment) == 2, "record AB_alignment wrong alignment");
_Static_assert(sizeof(struct AB_packed) == 4, "record AB_packed wrong sizeof");
_Static_assert(_Alignof(struct AB_packed) == 1, "record AB_packed wrong alignment");
_Static_assert(sizeof(struct AB_required_alignment) == 5, "record AB_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct AB_required_alignment) == 1, "record AB_required_alignment wrong alignment");
_Static_assert(sizeof(struct AB_size) == 6, "record AB_size wrong sizeof");
_Static_assert(_Alignof(struct AB_size) == 1, "record AB_size wrong alignment");
#endif
_Static_assert(sizeof(AC) == 4, "record AC wrong sizeof");
_Static_assert(_Alignof(AC) == 4, "record AC wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct AC_alignment) == 8, "record AC_alignment wrong sizeof");
_Static_assert(_Alignof(struct AC_alignment) == 4, "record AC_alignment wrong alignment");
_Static_assert(sizeof(struct AC_packed) == 4, "record AC_packed wrong sizeof");
_Static_assert(_Alignof(struct AC_packed) == 1, "record AC_packed wrong alignment");
_Static_assert(sizeof(struct AC_required_alignment) == 5, "record AC_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct AC_required_alignment) == 1, "record AC_required_alignment wrong alignment");
_Static_assert(sizeof(struct AC_size) == 6, "record AC_size wrong sizeof");
_Static_assert(_Alignof(struct AC_size) == 1, "record AC_size wrong alignment");
#endif
_Static_assert(sizeof(AD) == 4, "record AD wrong sizeof");
_Static_assert(_Alignof(AD) == 8, "record AD wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct AD_alignment) == 16, "record AD_alignment wrong sizeof");
_Static_assert(_Alignof(struct AD_alignment) == 8, "record AD_alignment wrong alignment");
_Static_assert(sizeof(struct AD_packed) == 4, "record AD_packed wrong sizeof");
_Static_assert(_Alignof(struct AD_packed) == 1, "record AD_packed wrong alignment");
_Static_assert(sizeof(struct AD_required_alignment) == 5, "record AD_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct AD_required_alignment) == 1, "record AD_required_alignment wrong alignment");
_Static_assert(sizeof(struct AD_size) == 6, "record AD_size wrong sizeof");
_Static_assert(_Alignof(struct AD_size) == 1, "record AD_size wrong alignment");
#endif
_Static_assert(sizeof(AE) == 4, "record AE wrong sizeof");
_Static_assert(_Alignof(AE) == 16, "record AE wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct AE_alignment) == 32, "record AE_alignment wrong sizeof");
_Static_assert(_Alignof(struct AE_alignment) == 16, "record AE_alignment wrong alignment");
_Static_assert(sizeof(struct AE_packed) == 4, "record AE_packed wrong sizeof");
_Static_assert(_Alignof(struct AE_packed) == 1, "record AE_packed wrong alignment");
_Static_assert(sizeof(struct AE_required_alignment) == 5, "record AE_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct AE_required_alignment) == 1, "record AE_required_alignment wrong alignment");
_Static_assert(sizeof(struct AE_size) == 6, "record AE_size wrong sizeof");
_Static_assert(_Alignof(struct AE_size) == 1, "record AE_size wrong alignment");
#endif
_Static_assert(sizeof(AF) == 4, "record AF wrong sizeof");
_Static_assert(_Alignof(AF) == 32, "record AF wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct AF_alignment) == 64, "record AF_alignment wrong sizeof");
_Static_assert(_Alignof(struct AF_alignment) == 32, "record AF_alignment wrong alignment");
_Static_assert(sizeof(struct AF_packed) == 4, "record AF_packed wrong sizeof");
_Static_assert(_Alignof(struct AF_packed) == 1, "record AF_packed wrong alignment");
_Static_assert(sizeof(struct AF_required_alignment) == 5, "record AF_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct AF_required_alignment) == 1, "record AF_required_alignment wrong alignment");
_Static_assert(sizeof(struct AF_size) == 6, "record AF_size wrong sizeof");
_Static_assert(_Alignof(struct AF_size) == 1, "record AF_size wrong alignment");
#endif
_Static_assert(sizeof(AG) == 4, "record AG wrong sizeof");
_Static_assert(_Alignof(AG) == 64, "record AG wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct AG_alignment) == 128, "record AG_alignment wrong sizeof");
_Static_assert(_Alignof(struct AG_alignment) == 64, "record AG_alignment wrong alignment");
_Static_assert(sizeof(struct AG_packed) == 4, "record AG_packed wrong sizeof");
_Static_assert(_Alignof(struct AG_packed) == 1, "record AG_packed wrong alignment");
_Static_assert(sizeof(struct AG_required_alignment) == 5, "record AG_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct AG_required_alignment) == 1, "record AG_required_alignment wrong alignment");
_Static_assert(sizeof(struct AG_size) == 6, "record AG_size wrong sizeof");
_Static_assert(_Alignof(struct AG_size) == 1, "record AG_size wrong alignment");
#endif
_Static_assert(sizeof(AH) == 4, "record AH wrong sizeof");
_Static_assert(_Alignof(AH) == 128, "record AH wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct AH_alignment) == 256, "record AH_alignment wrong sizeof");
_Static_assert(_Alignof(struct AH_alignment) == 128, "record AH_alignment wrong alignment");
_Static_assert(sizeof(struct AH_packed) == 4, "record AH_packed wrong sizeof");
_Static_assert(_Alignof(struct AH_packed) == 1, "record AH_packed wrong alignment");
_Static_assert(sizeof(struct AH_required_alignment) == 5, "record AH_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct AH_required_alignment) == 1, "record AH_required_alignment wrong alignment");
_Static_assert(sizeof(struct AH_size) == 6, "record AH_size wrong sizeof");
_Static_assert(_Alignof(struct AH_size) == 1, "record AH_size wrong alignment");
#endif
_Static_assert(sizeof(BA) == 4, "record BA wrong sizeof");
_Static_assert(_Alignof(BA) == 1, "record BA wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct BA_alignment) == 5, "record BA_alignment wrong sizeof");
_Static_assert(_Alignof(struct BA_alignment) == 1, "record BA_alignment wrong alignment");
_Static_assert(sizeof(struct BA_packed) == 4, "record BA_packed wrong sizeof");
_Static_assert(_Alignof(struct BA_packed) == 1, "record BA_packed wrong alignment");
_Static_assert(sizeof(struct BA_required_alignment) == 5, "record BA_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct BA_required_alignment) == 1, "record BA_required_alignment wrong alignment");
_Static_assert(sizeof(struct BA_size) == 6, "record BA_size wrong sizeof");
_Static_assert(_Alignof(struct BA_size) == 1, "record BA_size wrong alignment");
#endif
_Static_assert(sizeof(BB) == 4, "record BB wrong sizeof");
_Static_assert(_Alignof(BB) == 2, "record BB wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct BB_alignment) == 6, "record BB_alignment wrong sizeof");
_Static_assert(_Alignof(struct BB_alignment) == 2, "record BB_alignment wrong alignment");
_Static_assert(sizeof(struct BB_packed) == 4, "record BB_packed wrong sizeof");
_Static_assert(_Alignof(struct BB_packed) == 1, "record BB_packed wrong alignment");
_Static_assert(sizeof(struct BB_required_alignment) == 5, "record BB_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct BB_required_alignment) == 1, "record BB_required_alignment wrong alignment");
_Static_assert(sizeof(struct BB_size) == 6, "record BB_size wrong sizeof");
_Static_assert(_Alignof(struct BB_size) == 1, "record BB_size wrong alignment");
#endif
_Static_assert(sizeof(BC) == 4, "record BC wrong sizeof");
_Static_assert(_Alignof(BC) == 4, "record BC wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct BC_alignment) == 8, "record BC_alignment wrong sizeof");
_Static_assert(_Alignof(struct BC_alignment) == 4, "record BC_alignment wrong alignment");
_Static_assert(sizeof(struct BC_packed) == 4, "record BC_packed wrong sizeof");
_Static_assert(_Alignof(struct BC_packed) == 1, "record BC_packed wrong alignment");
_Static_assert(sizeof(struct BC_required_alignment) == 5, "record BC_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct BC_required_alignment) == 1, "record BC_required_alignment wrong alignment");
_Static_assert(sizeof(struct BC_size) == 6, "record BC_size wrong sizeof");
_Static_assert(_Alignof(struct BC_size) == 1, "record BC_size wrong alignment");
#endif
_Static_assert(sizeof(BD) == 4, "record BD wrong sizeof");
_Static_assert(_Alignof(BD) == 8, "record BD wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct BD_alignment) == 16, "record BD_alignment wrong sizeof");
_Static_assert(_Alignof(struct BD_alignment) == 8, "record BD_alignment wrong alignment");
_Static_assert(sizeof(struct BD_packed) == 4, "record BD_packed wrong sizeof");
_Static_assert(_Alignof(struct BD_packed) == 1, "record BD_packed wrong alignment");
_Static_assert(sizeof(struct BD_required_alignment) == 5, "record BD_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct BD_required_alignment) == 1, "record BD_required_alignment wrong alignment");
_Static_assert(sizeof(struct BD_size) == 6, "record BD_size wrong sizeof");
_Static_assert(_Alignof(struct BD_size) == 1, "record BD_size wrong alignment");
#endif
_Static_assert(sizeof(BE) == 4, "record BE wrong sizeof");
_Static_assert(_Alignof(BE) == 16, "record BE wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct BE_alignment) == 32, "record BE_alignment wrong sizeof");
_Static_assert(_Alignof(struct BE_alignment) == 16, "record BE_alignment wrong alignment");
_Static_assert(sizeof(struct BE_packed) == 4, "record BE_packed wrong sizeof");
_Static_assert(_Alignof(struct BE_packed) == 1, "record BE_packed wrong alignment");
_Static_assert(sizeof(struct BE_required_alignment) == 5, "record BE_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct BE_required_alignment) == 1, "record BE_required_alignment wrong alignment");
_Static_assert(sizeof(struct BE_size) == 6, "record BE_size wrong sizeof");
_Static_assert(_Alignof(struct BE_size) == 1, "record BE_size wrong alignment");
#endif
_Static_assert(sizeof(BF) == 4, "record BF wrong sizeof");
_Static_assert(_Alignof(BF) == 32, "record BF wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct BF_alignment) == 64, "record BF_alignment wrong sizeof");
_Static_assert(_Alignof(struct BF_alignment) == 32, "record BF_alignment wrong alignment");
_Static_assert(sizeof(struct BF_packed) == 4, "record BF_packed wrong sizeof");
_Static_assert(_Alignof(struct BF_packed) == 1, "record BF_packed wrong alignment");
_Static_assert(sizeof(struct BF_required_alignment) == 5, "record BF_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct BF_required_alignment) == 1, "record BF_required_alignment wrong alignment");
_Static_assert(sizeof(struct BF_size) == 6, "record BF_size wrong sizeof");
_Static_assert(_Alignof(struct BF_size) == 1, "record BF_size wrong alignment");
#endif
_Static_assert(sizeof(BG) == 4, "record BG wrong sizeof");
_Static_assert(_Alignof(BG) == 64, "record BG wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct BG_alignment) == 128, "record BG_alignment wrong sizeof");
_Static_assert(_Alignof(struct BG_alignment) == 64, "record BG_alignment wrong alignment");
_Static_assert(sizeof(struct BG_packed) == 4, "record BG_packed wrong sizeof");
_Static_assert(_Alignof(struct BG_packed) == 1, "record BG_packed wrong alignment");
_Static_assert(sizeof(struct BG_required_alignment) == 5, "record BG_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct BG_required_alignment) == 1, "record BG_required_alignment wrong alignment");
_Static_assert(sizeof(struct BG_size) == 6, "record BG_size wrong sizeof");
_Static_assert(_Alignof(struct BG_size) == 1, "record BG_size wrong alignment");
#endif
_Static_assert(sizeof(BH) == 4, "record BH wrong sizeof");
_Static_assert(_Alignof(BH) == 128, "record BH wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct BH_alignment) == 256, "record BH_alignment wrong sizeof");
_Static_assert(_Alignof(struct BH_alignment) == 128, "record BH_alignment wrong alignment");
_Static_assert(sizeof(struct BH_packed) == 4, "record BH_packed wrong sizeof");
_Static_assert(_Alignof(struct BH_packed) == 1, "record BH_packed wrong alignment");
_Static_assert(sizeof(struct BH_required_alignment) == 5, "record BH_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct BH_required_alignment) == 1, "record BH_required_alignment wrong alignment");
_Static_assert(sizeof(struct BH_size) == 6, "record BH_size wrong sizeof");
_Static_assert(_Alignof(struct BH_size) == 1, "record BH_size wrong alignment");
#endif
_Static_assert(sizeof(DA) == 4, "record DA wrong sizeof");
_Static_assert(_Alignof(DA) == 1, "record DA wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct DA_alignment) == 5, "record DA_alignment wrong sizeof");
_Static_assert(_Alignof(struct DA_alignment) == 1, "record DA_alignment wrong alignment");
_Static_assert(sizeof(struct DA_packed) == 4, "record DA_packed wrong sizeof");
_Static_assert(_Alignof(struct DA_packed) == 1, "record DA_packed wrong alignment");
_Static_assert(sizeof(struct DA_required_alignment) == 5, "record DA_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct DA_required_alignment) == 1, "record DA_required_alignment wrong alignment");
_Static_assert(sizeof(struct DA_size) == 6, "record DA_size wrong sizeof");
_Static_assert(_Alignof(struct DA_size) == 1, "record DA_size wrong alignment");
#endif
_Static_assert(sizeof(DB) == 4, "record DB wrong sizeof");
_Static_assert(_Alignof(DB) == 2, "record DB wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct DB_alignment) == 6, "record DB_alignment wrong sizeof");
_Static_assert(_Alignof(struct DB_alignment) == 2, "record DB_alignment wrong alignment");
_Static_assert(sizeof(struct DB_packed) == 4, "record DB_packed wrong sizeof");
_Static_assert(_Alignof(struct DB_packed) == 1, "record DB_packed wrong alignment");
_Static_assert(sizeof(struct DB_required_alignment) == 5, "record DB_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct DB_required_alignment) == 1, "record DB_required_alignment wrong alignment");
_Static_assert(sizeof(struct DB_size) == 6, "record DB_size wrong sizeof");
_Static_assert(_Alignof(struct DB_size) == 1, "record DB_size wrong alignment");
#endif
_Static_assert(sizeof(DC) == 4, "record DC wrong sizeof");
_Static_assert(_Alignof(DC) == 4, "record DC wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct DC_alignment) == 8, "record DC_alignment wrong sizeof");
_Static_assert(_Alignof(struct DC_alignment) == 4, "record DC_alignment wrong alignment");
_Static_assert(sizeof(struct DC_packed) == 4, "record DC_packed wrong sizeof");
_Static_assert(_Alignof(struct DC_packed) == 1, "record DC_packed wrong alignment");
_Static_assert(sizeof(struct DC_required_alignment) == 5, "record DC_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct DC_required_alignment) == 1, "record DC_required_alignment wrong alignment");
_Static_assert(sizeof(struct DC_size) == 6, "record DC_size wrong sizeof");
_Static_assert(_Alignof(struct DC_size) == 1, "record DC_size wrong alignment");
#endif
_Static_assert(sizeof(DD) == 4, "record DD wrong sizeof");
_Static_assert(_Alignof(DD) == 8, "record DD wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct DD_alignment) == 16, "record DD_alignment wrong sizeof");
_Static_assert(_Alignof(struct DD_alignment) == 8, "record DD_alignment wrong alignment");
_Static_assert(sizeof(struct DD_packed) == 4, "record DD_packed wrong sizeof");
_Static_assert(_Alignof(struct DD_packed) == 1, "record DD_packed wrong alignment");
_Static_assert(sizeof(struct DD_required_alignment) == 5, "record DD_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct DD_required_alignment) == 1, "record DD_required_alignment wrong alignment");
_Static_assert(sizeof(struct DD_size) == 6, "record DD_size wrong sizeof");
_Static_assert(_Alignof(struct DD_size) == 1, "record DD_size wrong alignment");
#endif
_Static_assert(sizeof(DE) == 4, "record DE wrong sizeof");
_Static_assert(_Alignof(DE) == 16, "record DE wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct DE_alignment) == 32, "record DE_alignment wrong sizeof");
_Static_assert(_Alignof(struct DE_alignment) == 16, "record DE_alignment wrong alignment");
_Static_assert(sizeof(struct DE_packed) == 4, "record DE_packed wrong sizeof");
_Static_assert(_Alignof(struct DE_packed) == 1, "record DE_packed wrong alignment");
_Static_assert(sizeof(struct DE_required_alignment) == 5, "record DE_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct DE_required_alignment) == 1, "record DE_required_alignment wrong alignment");
_Static_assert(sizeof(struct DE_size) == 6, "record DE_size wrong sizeof");
_Static_assert(_Alignof(struct DE_size) == 1, "record DE_size wrong alignment");
#endif
_Static_assert(sizeof(DF) == 4, "record DF wrong sizeof");
_Static_assert(_Alignof(DF) == 32, "record DF wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct DF_alignment) == 64, "record DF_alignment wrong sizeof");
_Static_assert(_Alignof(struct DF_alignment) == 32, "record DF_alignment wrong alignment");
_Static_assert(sizeof(struct DF_packed) == 4, "record DF_packed wrong sizeof");
_Static_assert(_Alignof(struct DF_packed) == 1, "record DF_packed wrong alignment");
_Static_assert(sizeof(struct DF_required_alignment) == 5, "record DF_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct DF_required_alignment) == 1, "record DF_required_alignment wrong alignment");
_Static_assert(sizeof(struct DF_size) == 6, "record DF_size wrong sizeof");
_Static_assert(_Alignof(struct DF_size) == 1, "record DF_size wrong alignment");
#endif
_Static_assert(sizeof(DG) == 4, "record DG wrong sizeof");
_Static_assert(_Alignof(DG) == 64, "record DG wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct DG_alignment) == 128, "record DG_alignment wrong sizeof");
_Static_assert(_Alignof(struct DG_alignment) == 64, "record DG_alignment wrong alignment");
_Static_assert(sizeof(struct DG_packed) == 4, "record DG_packed wrong sizeof");
_Static_assert(_Alignof(struct DG_packed) == 1, "record DG_packed wrong alignment");
_Static_assert(sizeof(struct DG_required_alignment) == 5, "record DG_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct DG_required_alignment) == 1, "record DG_required_alignment wrong alignment");
_Static_assert(sizeof(struct DG_size) == 6, "record DG_size wrong sizeof");
_Static_assert(_Alignof(struct DG_size) == 1, "record DG_size wrong alignment");
#endif
_Static_assert(sizeof(DH) == 4, "record DH wrong sizeof");
_Static_assert(_Alignof(DH) == 128, "record DH wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct DH_alignment) == 256, "record DH_alignment wrong sizeof");
_Static_assert(_Alignof(struct DH_alignment) == 128, "record DH_alignment wrong alignment");
_Static_assert(sizeof(struct DH_packed) == 4, "record DH_packed wrong sizeof");
_Static_assert(_Alignof(struct DH_packed) == 1, "record DH_packed wrong alignment");
_Static_assert(sizeof(struct DH_required_alignment) == 5, "record DH_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct DH_required_alignment) == 1, "record DH_required_alignment wrong alignment");
_Static_assert(sizeof(struct DH_size) == 6, "record DH_size wrong sizeof");
_Static_assert(_Alignof(struct DH_size) == 1, "record DH_size wrong alignment");
#endif
#elif defined(AARCH64_PC_WINDOWS_MSVC) ||  defined(I586_PC_WINDOWS_MSVC) ||  defined(I686_PC_WINDOWS_MSVC) ||  defined(I686_UNKNOWN_WINDOWS) ||  \
 defined(THUMBV7A_PC_WINDOWS_MSVC) ||  defined(X8664_PC_WINDOWS_MSVC) ||  defined(X8664_UNKNOWN_WINDOWS) 
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
_Static_assert(sizeof(C) == 4, "record C wrong sizeof");
_Static_assert(_Alignof(C) == 4, "record C wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 8, "record C_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_alignment) == 4, "record C_alignment wrong alignment");
_Static_assert(sizeof(struct C_packed) == 4, "record C_packed wrong sizeof");
_Static_assert(_Alignof(struct C_packed) == 1, "record C_packed wrong alignment");
_Static_assert(sizeof(struct C_required_alignment) == 5, "record C_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "record C_required_alignment wrong alignment");
_Static_assert(sizeof(struct C_size) == 6, "record C_size wrong sizeof");
_Static_assert(_Alignof(struct C_size) == 1, "record C_size wrong alignment");
#endif
_Static_assert(sizeof(D) == 4, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 8, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 16, "record D_alignment wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 8, "record D_alignment wrong alignment");
_Static_assert(sizeof(struct D_packed) == 4, "record D_packed wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D_packed wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 5, "record D_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D_required_alignment wrong alignment");
_Static_assert(sizeof(struct D_size) == 6, "record D_size wrong sizeof");
_Static_assert(_Alignof(struct D_size) == 1, "record D_size wrong alignment");
#endif
_Static_assert(sizeof(E) == 4, "record E wrong sizeof");
_Static_assert(_Alignof(E) == 16, "record E wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 32, "record E_alignment wrong sizeof");
_Static_assert(_Alignof(struct E_alignment) == 16, "record E_alignment wrong alignment");
_Static_assert(sizeof(struct E_packed) == 4, "record E_packed wrong sizeof");
_Static_assert(_Alignof(struct E_packed) == 1, "record E_packed wrong alignment");
_Static_assert(sizeof(struct E_required_alignment) == 5, "record E_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "record E_required_alignment wrong alignment");
_Static_assert(sizeof(struct E_size) == 6, "record E_size wrong sizeof");
_Static_assert(_Alignof(struct E_size) == 1, "record E_size wrong alignment");
#endif
_Static_assert(sizeof(F) == 4, "record F wrong sizeof");
_Static_assert(_Alignof(F) == 32, "record F wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 64, "record F_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_alignment) == 32, "record F_alignment wrong alignment");
_Static_assert(sizeof(struct F_packed) == 4, "record F_packed wrong sizeof");
_Static_assert(_Alignof(struct F_packed) == 1, "record F_packed wrong alignment");
_Static_assert(sizeof(struct F_required_alignment) == 5, "record F_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "record F_required_alignment wrong alignment");
_Static_assert(sizeof(struct F_size) == 6, "record F_size wrong sizeof");
_Static_assert(_Alignof(struct F_size) == 1, "record F_size wrong alignment");
#endif
_Static_assert(sizeof(G) == 4, "record G wrong sizeof");
_Static_assert(_Alignof(G) == 64, "record G wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 128, "record G_alignment wrong sizeof");
_Static_assert(_Alignof(struct G_alignment) == 64, "record G_alignment wrong alignment");
_Static_assert(sizeof(struct G_packed) == 4, "record G_packed wrong sizeof");
_Static_assert(_Alignof(struct G_packed) == 1, "record G_packed wrong alignment");
_Static_assert(sizeof(struct G_required_alignment) == 5, "record G_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "record G_required_alignment wrong alignment");
_Static_assert(sizeof(struct G_size) == 6, "record G_size wrong sizeof");
_Static_assert(_Alignof(struct G_size) == 1, "record G_size wrong alignment");
#endif
_Static_assert(sizeof(H) == 4, "record H wrong sizeof");
_Static_assert(_Alignof(H) == 128, "record H wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 256, "record H_alignment wrong sizeof");
_Static_assert(_Alignof(struct H_alignment) == 128, "record H_alignment wrong alignment");
_Static_assert(sizeof(struct H_packed) == 4, "record H_packed wrong sizeof");
_Static_assert(_Alignof(struct H_packed) == 1, "record H_packed wrong alignment");
_Static_assert(sizeof(struct H_required_alignment) == 5, "record H_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "record H_required_alignment wrong alignment");
_Static_assert(sizeof(struct H_size) == 6, "record H_size wrong sizeof");
_Static_assert(_Alignof(struct H_size) == 1, "record H_size wrong alignment");
#endif
_Static_assert(sizeof(AA) == 4, "record AA wrong sizeof");
_Static_assert(_Alignof(AA) == 4, "record AA wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct AA_alignment) == 8, "record AA_alignment wrong sizeof");
_Static_assert(_Alignof(struct AA_alignment) == 4, "record AA_alignment wrong alignment");
_Static_assert(sizeof(struct AA_packed) == 4, "record AA_packed wrong sizeof");
_Static_assert(_Alignof(struct AA_packed) == 1, "record AA_packed wrong alignment");
_Static_assert(sizeof(struct AA_required_alignment) == 5, "record AA_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct AA_required_alignment) == 1, "record AA_required_alignment wrong alignment");
_Static_assert(sizeof(struct AA_size) == 6, "record AA_size wrong sizeof");
_Static_assert(_Alignof(struct AA_size) == 1, "record AA_size wrong alignment");
#endif
_Static_assert(sizeof(AB) == 4, "record AB wrong sizeof");
_Static_assert(_Alignof(AB) == 4, "record AB wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct AB_alignment) == 8, "record AB_alignment wrong sizeof");
_Static_assert(_Alignof(struct AB_alignment) == 4, "record AB_alignment wrong alignment");
_Static_assert(sizeof(struct AB_packed) == 4, "record AB_packed wrong sizeof");
_Static_assert(_Alignof(struct AB_packed) == 1, "record AB_packed wrong alignment");
_Static_assert(sizeof(struct AB_required_alignment) == 5, "record AB_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct AB_required_alignment) == 1, "record AB_required_alignment wrong alignment");
_Static_assert(sizeof(struct AB_size) == 6, "record AB_size wrong sizeof");
_Static_assert(_Alignof(struct AB_size) == 1, "record AB_size wrong alignment");
#endif
_Static_assert(sizeof(AC) == 4, "record AC wrong sizeof");
_Static_assert(_Alignof(AC) == 4, "record AC wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct AC_alignment) == 8, "record AC_alignment wrong sizeof");
_Static_assert(_Alignof(struct AC_alignment) == 4, "record AC_alignment wrong alignment");
_Static_assert(sizeof(struct AC_packed) == 4, "record AC_packed wrong sizeof");
_Static_assert(_Alignof(struct AC_packed) == 1, "record AC_packed wrong alignment");
_Static_assert(sizeof(struct AC_required_alignment) == 5, "record AC_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct AC_required_alignment) == 1, "record AC_required_alignment wrong alignment");
_Static_assert(sizeof(struct AC_size) == 6, "record AC_size wrong sizeof");
_Static_assert(_Alignof(struct AC_size) == 1, "record AC_size wrong alignment");
#endif
_Static_assert(sizeof(AD) == 4, "record AD wrong sizeof");
_Static_assert(_Alignof(AD) == 8, "record AD wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct AD_alignment) == 16, "record AD_alignment wrong sizeof");
_Static_assert(_Alignof(struct AD_alignment) == 8, "record AD_alignment wrong alignment");
_Static_assert(sizeof(struct AD_packed) == 4, "record AD_packed wrong sizeof");
_Static_assert(_Alignof(struct AD_packed) == 1, "record AD_packed wrong alignment");
_Static_assert(sizeof(struct AD_required_alignment) == 5, "record AD_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct AD_required_alignment) == 1, "record AD_required_alignment wrong alignment");
_Static_assert(sizeof(struct AD_size) == 6, "record AD_size wrong sizeof");
_Static_assert(_Alignof(struct AD_size) == 1, "record AD_size wrong alignment");
#endif
_Static_assert(sizeof(AE) == 4, "record AE wrong sizeof");
_Static_assert(_Alignof(AE) == 16, "record AE wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct AE_alignment) == 32, "record AE_alignment wrong sizeof");
_Static_assert(_Alignof(struct AE_alignment) == 16, "record AE_alignment wrong alignment");
_Static_assert(sizeof(struct AE_packed) == 4, "record AE_packed wrong sizeof");
_Static_assert(_Alignof(struct AE_packed) == 1, "record AE_packed wrong alignment");
_Static_assert(sizeof(struct AE_required_alignment) == 5, "record AE_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct AE_required_alignment) == 1, "record AE_required_alignment wrong alignment");
_Static_assert(sizeof(struct AE_size) == 6, "record AE_size wrong sizeof");
_Static_assert(_Alignof(struct AE_size) == 1, "record AE_size wrong alignment");
#endif
_Static_assert(sizeof(AF) == 4, "record AF wrong sizeof");
_Static_assert(_Alignof(AF) == 32, "record AF wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct AF_alignment) == 64, "record AF_alignment wrong sizeof");
_Static_assert(_Alignof(struct AF_alignment) == 32, "record AF_alignment wrong alignment");
_Static_assert(sizeof(struct AF_packed) == 4, "record AF_packed wrong sizeof");
_Static_assert(_Alignof(struct AF_packed) == 1, "record AF_packed wrong alignment");
_Static_assert(sizeof(struct AF_required_alignment) == 5, "record AF_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct AF_required_alignment) == 1, "record AF_required_alignment wrong alignment");
_Static_assert(sizeof(struct AF_size) == 6, "record AF_size wrong sizeof");
_Static_assert(_Alignof(struct AF_size) == 1, "record AF_size wrong alignment");
#endif
_Static_assert(sizeof(AG) == 4, "record AG wrong sizeof");
_Static_assert(_Alignof(AG) == 64, "record AG wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct AG_alignment) == 128, "record AG_alignment wrong sizeof");
_Static_assert(_Alignof(struct AG_alignment) == 64, "record AG_alignment wrong alignment");
_Static_assert(sizeof(struct AG_packed) == 4, "record AG_packed wrong sizeof");
_Static_assert(_Alignof(struct AG_packed) == 1, "record AG_packed wrong alignment");
_Static_assert(sizeof(struct AG_required_alignment) == 5, "record AG_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct AG_required_alignment) == 1, "record AG_required_alignment wrong alignment");
_Static_assert(sizeof(struct AG_size) == 6, "record AG_size wrong sizeof");
_Static_assert(_Alignof(struct AG_size) == 1, "record AG_size wrong alignment");
#endif
_Static_assert(sizeof(AH) == 4, "record AH wrong sizeof");
_Static_assert(_Alignof(AH) == 128, "record AH wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct AH_alignment) == 256, "record AH_alignment wrong sizeof");
_Static_assert(_Alignof(struct AH_alignment) == 128, "record AH_alignment wrong alignment");
_Static_assert(sizeof(struct AH_packed) == 4, "record AH_packed wrong sizeof");
_Static_assert(_Alignof(struct AH_packed) == 1, "record AH_packed wrong alignment");
_Static_assert(sizeof(struct AH_required_alignment) == 5, "record AH_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct AH_required_alignment) == 1, "record AH_required_alignment wrong alignment");
_Static_assert(sizeof(struct AH_size) == 6, "record AH_size wrong sizeof");
_Static_assert(_Alignof(struct AH_size) == 1, "record AH_size wrong alignment");
#endif
_Static_assert(sizeof(BA) == 4, "record BA wrong sizeof");
_Static_assert(_Alignof(BA) == 4, "record BA wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct BA_alignment) == 8, "record BA_alignment wrong sizeof");
_Static_assert(_Alignof(struct BA_alignment) == 4, "record BA_alignment wrong alignment");
_Static_assert(sizeof(struct BA_packed) == 4, "record BA_packed wrong sizeof");
_Static_assert(_Alignof(struct BA_packed) == 1, "record BA_packed wrong alignment");
_Static_assert(sizeof(struct BA_required_alignment) == 5, "record BA_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct BA_required_alignment) == 1, "record BA_required_alignment wrong alignment");
_Static_assert(sizeof(struct BA_size) == 6, "record BA_size wrong sizeof");
_Static_assert(_Alignof(struct BA_size) == 1, "record BA_size wrong alignment");
#endif
_Static_assert(sizeof(BB) == 4, "record BB wrong sizeof");
_Static_assert(_Alignof(BB) == 4, "record BB wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct BB_alignment) == 8, "record BB_alignment wrong sizeof");
_Static_assert(_Alignof(struct BB_alignment) == 4, "record BB_alignment wrong alignment");
_Static_assert(sizeof(struct BB_packed) == 4, "record BB_packed wrong sizeof");
_Static_assert(_Alignof(struct BB_packed) == 1, "record BB_packed wrong alignment");
_Static_assert(sizeof(struct BB_required_alignment) == 5, "record BB_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct BB_required_alignment) == 1, "record BB_required_alignment wrong alignment");
_Static_assert(sizeof(struct BB_size) == 6, "record BB_size wrong sizeof");
_Static_assert(_Alignof(struct BB_size) == 1, "record BB_size wrong alignment");
#endif
_Static_assert(sizeof(BC) == 4, "record BC wrong sizeof");
_Static_assert(_Alignof(BC) == 4, "record BC wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct BC_alignment) == 8, "record BC_alignment wrong sizeof");
_Static_assert(_Alignof(struct BC_alignment) == 4, "record BC_alignment wrong alignment");
_Static_assert(sizeof(struct BC_packed) == 4, "record BC_packed wrong sizeof");
_Static_assert(_Alignof(struct BC_packed) == 1, "record BC_packed wrong alignment");
_Static_assert(sizeof(struct BC_required_alignment) == 5, "record BC_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct BC_required_alignment) == 1, "record BC_required_alignment wrong alignment");
_Static_assert(sizeof(struct BC_size) == 6, "record BC_size wrong sizeof");
_Static_assert(_Alignof(struct BC_size) == 1, "record BC_size wrong alignment");
#endif
_Static_assert(sizeof(BD) == 4, "record BD wrong sizeof");
_Static_assert(_Alignof(BD) == 8, "record BD wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct BD_alignment) == 16, "record BD_alignment wrong sizeof");
_Static_assert(_Alignof(struct BD_alignment) == 8, "record BD_alignment wrong alignment");
_Static_assert(sizeof(struct BD_packed) == 4, "record BD_packed wrong sizeof");
_Static_assert(_Alignof(struct BD_packed) == 1, "record BD_packed wrong alignment");
_Static_assert(sizeof(struct BD_required_alignment) == 5, "record BD_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct BD_required_alignment) == 1, "record BD_required_alignment wrong alignment");
_Static_assert(sizeof(struct BD_size) == 6, "record BD_size wrong sizeof");
_Static_assert(_Alignof(struct BD_size) == 1, "record BD_size wrong alignment");
#endif
_Static_assert(sizeof(BE) == 4, "record BE wrong sizeof");
_Static_assert(_Alignof(BE) == 16, "record BE wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct BE_alignment) == 32, "record BE_alignment wrong sizeof");
_Static_assert(_Alignof(struct BE_alignment) == 16, "record BE_alignment wrong alignment");
_Static_assert(sizeof(struct BE_packed) == 4, "record BE_packed wrong sizeof");
_Static_assert(_Alignof(struct BE_packed) == 1, "record BE_packed wrong alignment");
_Static_assert(sizeof(struct BE_required_alignment) == 5, "record BE_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct BE_required_alignment) == 1, "record BE_required_alignment wrong alignment");
_Static_assert(sizeof(struct BE_size) == 6, "record BE_size wrong sizeof");
_Static_assert(_Alignof(struct BE_size) == 1, "record BE_size wrong alignment");
#endif
_Static_assert(sizeof(BF) == 4, "record BF wrong sizeof");
_Static_assert(_Alignof(BF) == 32, "record BF wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct BF_alignment) == 64, "record BF_alignment wrong sizeof");
_Static_assert(_Alignof(struct BF_alignment) == 32, "record BF_alignment wrong alignment");
_Static_assert(sizeof(struct BF_packed) == 4, "record BF_packed wrong sizeof");
_Static_assert(_Alignof(struct BF_packed) == 1, "record BF_packed wrong alignment");
_Static_assert(sizeof(struct BF_required_alignment) == 5, "record BF_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct BF_required_alignment) == 1, "record BF_required_alignment wrong alignment");
_Static_assert(sizeof(struct BF_size) == 6, "record BF_size wrong sizeof");
_Static_assert(_Alignof(struct BF_size) == 1, "record BF_size wrong alignment");
#endif
_Static_assert(sizeof(BG) == 4, "record BG wrong sizeof");
_Static_assert(_Alignof(BG) == 64, "record BG wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct BG_alignment) == 128, "record BG_alignment wrong sizeof");
_Static_assert(_Alignof(struct BG_alignment) == 64, "record BG_alignment wrong alignment");
_Static_assert(sizeof(struct BG_packed) == 4, "record BG_packed wrong sizeof");
_Static_assert(_Alignof(struct BG_packed) == 1, "record BG_packed wrong alignment");
_Static_assert(sizeof(struct BG_required_alignment) == 5, "record BG_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct BG_required_alignment) == 1, "record BG_required_alignment wrong alignment");
_Static_assert(sizeof(struct BG_size) == 6, "record BG_size wrong sizeof");
_Static_assert(_Alignof(struct BG_size) == 1, "record BG_size wrong alignment");
#endif
_Static_assert(sizeof(BH) == 4, "record BH wrong sizeof");
_Static_assert(_Alignof(BH) == 128, "record BH wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct BH_alignment) == 256, "record BH_alignment wrong sizeof");
_Static_assert(_Alignof(struct BH_alignment) == 128, "record BH_alignment wrong alignment");
_Static_assert(sizeof(struct BH_packed) == 4, "record BH_packed wrong sizeof");
_Static_assert(_Alignof(struct BH_packed) == 1, "record BH_packed wrong alignment");
_Static_assert(sizeof(struct BH_required_alignment) == 5, "record BH_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct BH_required_alignment) == 1, "record BH_required_alignment wrong alignment");
_Static_assert(sizeof(struct BH_size) == 6, "record BH_size wrong sizeof");
_Static_assert(_Alignof(struct BH_size) == 1, "record BH_size wrong alignment");
#endif
_Static_assert(sizeof(DA) == 4, "record DA wrong sizeof");
_Static_assert(_Alignof(DA) == 8, "record DA wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct DA_alignment) == 16, "record DA_alignment wrong sizeof");
_Static_assert(_Alignof(struct DA_alignment) == 8, "record DA_alignment wrong alignment");
_Static_assert(sizeof(struct DA_packed) == 4, "record DA_packed wrong sizeof");
_Static_assert(_Alignof(struct DA_packed) == 1, "record DA_packed wrong alignment");
_Static_assert(sizeof(struct DA_required_alignment) == 5, "record DA_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct DA_required_alignment) == 1, "record DA_required_alignment wrong alignment");
_Static_assert(sizeof(struct DA_size) == 6, "record DA_size wrong sizeof");
_Static_assert(_Alignof(struct DA_size) == 1, "record DA_size wrong alignment");
#endif
_Static_assert(sizeof(DB) == 4, "record DB wrong sizeof");
_Static_assert(_Alignof(DB) == 8, "record DB wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct DB_alignment) == 16, "record DB_alignment wrong sizeof");
_Static_assert(_Alignof(struct DB_alignment) == 8, "record DB_alignment wrong alignment");
_Static_assert(sizeof(struct DB_packed) == 4, "record DB_packed wrong sizeof");
_Static_assert(_Alignof(struct DB_packed) == 1, "record DB_packed wrong alignment");
_Static_assert(sizeof(struct DB_required_alignment) == 5, "record DB_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct DB_required_alignment) == 1, "record DB_required_alignment wrong alignment");
_Static_assert(sizeof(struct DB_size) == 6, "record DB_size wrong sizeof");
_Static_assert(_Alignof(struct DB_size) == 1, "record DB_size wrong alignment");
#endif
_Static_assert(sizeof(DC) == 4, "record DC wrong sizeof");
_Static_assert(_Alignof(DC) == 8, "record DC wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct DC_alignment) == 16, "record DC_alignment wrong sizeof");
_Static_assert(_Alignof(struct DC_alignment) == 8, "record DC_alignment wrong alignment");
_Static_assert(sizeof(struct DC_packed) == 4, "record DC_packed wrong sizeof");
_Static_assert(_Alignof(struct DC_packed) == 1, "record DC_packed wrong alignment");
_Static_assert(sizeof(struct DC_required_alignment) == 5, "record DC_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct DC_required_alignment) == 1, "record DC_required_alignment wrong alignment");
_Static_assert(sizeof(struct DC_size) == 6, "record DC_size wrong sizeof");
_Static_assert(_Alignof(struct DC_size) == 1, "record DC_size wrong alignment");
#endif
_Static_assert(sizeof(DD) == 4, "record DD wrong sizeof");
_Static_assert(_Alignof(DD) == 8, "record DD wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct DD_alignment) == 16, "record DD_alignment wrong sizeof");
_Static_assert(_Alignof(struct DD_alignment) == 8, "record DD_alignment wrong alignment");
_Static_assert(sizeof(struct DD_packed) == 4, "record DD_packed wrong sizeof");
_Static_assert(_Alignof(struct DD_packed) == 1, "record DD_packed wrong alignment");
_Static_assert(sizeof(struct DD_required_alignment) == 5, "record DD_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct DD_required_alignment) == 1, "record DD_required_alignment wrong alignment");
_Static_assert(sizeof(struct DD_size) == 6, "record DD_size wrong sizeof");
_Static_assert(_Alignof(struct DD_size) == 1, "record DD_size wrong alignment");
#endif
_Static_assert(sizeof(DE) == 4, "record DE wrong sizeof");
_Static_assert(_Alignof(DE) == 16, "record DE wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct DE_alignment) == 32, "record DE_alignment wrong sizeof");
_Static_assert(_Alignof(struct DE_alignment) == 16, "record DE_alignment wrong alignment");
_Static_assert(sizeof(struct DE_packed) == 4, "record DE_packed wrong sizeof");
_Static_assert(_Alignof(struct DE_packed) == 1, "record DE_packed wrong alignment");
_Static_assert(sizeof(struct DE_required_alignment) == 5, "record DE_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct DE_required_alignment) == 1, "record DE_required_alignment wrong alignment");
_Static_assert(sizeof(struct DE_size) == 6, "record DE_size wrong sizeof");
_Static_assert(_Alignof(struct DE_size) == 1, "record DE_size wrong alignment");
#endif
_Static_assert(sizeof(DF) == 4, "record DF wrong sizeof");
_Static_assert(_Alignof(DF) == 32, "record DF wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct DF_alignment) == 64, "record DF_alignment wrong sizeof");
_Static_assert(_Alignof(struct DF_alignment) == 32, "record DF_alignment wrong alignment");
_Static_assert(sizeof(struct DF_packed) == 4, "record DF_packed wrong sizeof");
_Static_assert(_Alignof(struct DF_packed) == 1, "record DF_packed wrong alignment");
_Static_assert(sizeof(struct DF_required_alignment) == 5, "record DF_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct DF_required_alignment) == 1, "record DF_required_alignment wrong alignment");
_Static_assert(sizeof(struct DF_size) == 6, "record DF_size wrong sizeof");
_Static_assert(_Alignof(struct DF_size) == 1, "record DF_size wrong alignment");
#endif
_Static_assert(sizeof(DG) == 4, "record DG wrong sizeof");
_Static_assert(_Alignof(DG) == 64, "record DG wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct DG_alignment) == 128, "record DG_alignment wrong sizeof");
_Static_assert(_Alignof(struct DG_alignment) == 64, "record DG_alignment wrong alignment");
_Static_assert(sizeof(struct DG_packed) == 4, "record DG_packed wrong sizeof");
_Static_assert(_Alignof(struct DG_packed) == 1, "record DG_packed wrong alignment");
_Static_assert(sizeof(struct DG_required_alignment) == 5, "record DG_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct DG_required_alignment) == 1, "record DG_required_alignment wrong alignment");
_Static_assert(sizeof(struct DG_size) == 6, "record DG_size wrong sizeof");
_Static_assert(_Alignof(struct DG_size) == 1, "record DG_size wrong alignment");
#endif
_Static_assert(sizeof(DH) == 4, "record DH wrong sizeof");
_Static_assert(_Alignof(DH) == 128, "record DH wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct DH_alignment) == 256, "record DH_alignment wrong sizeof");
_Static_assert(_Alignof(struct DH_alignment) == 128, "record DH_alignment wrong alignment");
_Static_assert(sizeof(struct DH_packed) == 4, "record DH_packed wrong sizeof");
_Static_assert(_Alignof(struct DH_packed) == 1, "record DH_packed wrong alignment");
_Static_assert(sizeof(struct DH_required_alignment) == 5, "record DH_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct DH_required_alignment) == 1, "record DH_required_alignment wrong alignment");
_Static_assert(sizeof(struct DH_size) == 6, "record DH_size wrong sizeof");
_Static_assert(_Alignof(struct DH_size) == 1, "record DH_size wrong alignment");
#endif
#elif defined(AVR_UNKNOWN_UNKNOWN) 
_Static_assert(sizeof(A) == 2, "record A wrong sizeof");
_Static_assert(_Alignof(A) == 1, "record A wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 3, "record A_alignment wrong sizeof");
_Static_assert(_Alignof(struct A_alignment) == 1, "record A_alignment wrong alignment");
_Static_assert(sizeof(struct A_packed) == 2, "record A_packed wrong sizeof");
_Static_assert(_Alignof(struct A_packed) == 1, "record A_packed wrong alignment");
_Static_assert(sizeof(struct A_required_alignment) == 3, "record A_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "record A_required_alignment wrong alignment");
_Static_assert(sizeof(struct A_size) == 4, "record A_size wrong sizeof");
_Static_assert(_Alignof(struct A_size) == 1, "record A_size wrong alignment");
#endif
_Static_assert(sizeof(B) == 2, "record B wrong sizeof");
_Static_assert(_Alignof(B) == 2, "record B wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 4, "record B_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_alignment) == 2, "record B_alignment wrong alignment");
_Static_assert(sizeof(struct B_packed) == 2, "record B_packed wrong sizeof");
_Static_assert(_Alignof(struct B_packed) == 1, "record B_packed wrong alignment");
_Static_assert(sizeof(struct B_required_alignment) == 3, "record B_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "record B_required_alignment wrong alignment");
_Static_assert(sizeof(struct B_size) == 4, "record B_size wrong sizeof");
_Static_assert(_Alignof(struct B_size) == 1, "record B_size wrong alignment");
#endif
_Static_assert(sizeof(C) == 2, "record C wrong sizeof");
_Static_assert(_Alignof(C) == 4, "record C wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 8, "record C_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_alignment) == 4, "record C_alignment wrong alignment");
_Static_assert(sizeof(struct C_packed) == 2, "record C_packed wrong sizeof");
_Static_assert(_Alignof(struct C_packed) == 1, "record C_packed wrong alignment");
_Static_assert(sizeof(struct C_required_alignment) == 3, "record C_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "record C_required_alignment wrong alignment");
_Static_assert(sizeof(struct C_size) == 4, "record C_size wrong sizeof");
_Static_assert(_Alignof(struct C_size) == 1, "record C_size wrong alignment");
#endif
_Static_assert(sizeof(D) == 2, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 8, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 16, "record D_alignment wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 8, "record D_alignment wrong alignment");
_Static_assert(sizeof(struct D_packed) == 2, "record D_packed wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D_packed wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 3, "record D_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D_required_alignment wrong alignment");
_Static_assert(sizeof(struct D_size) == 4, "record D_size wrong sizeof");
_Static_assert(_Alignof(struct D_size) == 1, "record D_size wrong alignment");
#endif
_Static_assert(sizeof(E) == 2, "record E wrong sizeof");
_Static_assert(_Alignof(E) == 16, "record E wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 32, "record E_alignment wrong sizeof");
_Static_assert(_Alignof(struct E_alignment) == 16, "record E_alignment wrong alignment");
_Static_assert(sizeof(struct E_packed) == 2, "record E_packed wrong sizeof");
_Static_assert(_Alignof(struct E_packed) == 1, "record E_packed wrong alignment");
_Static_assert(sizeof(struct E_required_alignment) == 3, "record E_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "record E_required_alignment wrong alignment");
_Static_assert(sizeof(struct E_size) == 4, "record E_size wrong sizeof");
_Static_assert(_Alignof(struct E_size) == 1, "record E_size wrong alignment");
#endif
_Static_assert(sizeof(F) == 2, "record F wrong sizeof");
_Static_assert(_Alignof(F) == 32, "record F wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 64, "record F_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_alignment) == 32, "record F_alignment wrong alignment");
_Static_assert(sizeof(struct F_packed) == 2, "record F_packed wrong sizeof");
_Static_assert(_Alignof(struct F_packed) == 1, "record F_packed wrong alignment");
_Static_assert(sizeof(struct F_required_alignment) == 3, "record F_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "record F_required_alignment wrong alignment");
_Static_assert(sizeof(struct F_size) == 4, "record F_size wrong sizeof");
_Static_assert(_Alignof(struct F_size) == 1, "record F_size wrong alignment");
#endif
_Static_assert(sizeof(G) == 2, "record G wrong sizeof");
_Static_assert(_Alignof(G) == 64, "record G wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 128, "record G_alignment wrong sizeof");
_Static_assert(_Alignof(struct G_alignment) == 64, "record G_alignment wrong alignment");
_Static_assert(sizeof(struct G_packed) == 2, "record G_packed wrong sizeof");
_Static_assert(_Alignof(struct G_packed) == 1, "record G_packed wrong alignment");
_Static_assert(sizeof(struct G_required_alignment) == 3, "record G_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "record G_required_alignment wrong alignment");
_Static_assert(sizeof(struct G_size) == 4, "record G_size wrong sizeof");
_Static_assert(_Alignof(struct G_size) == 1, "record G_size wrong alignment");
#endif
_Static_assert(sizeof(H) == 2, "record H wrong sizeof");
_Static_assert(_Alignof(H) == 128, "record H wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 256, "record H_alignment wrong sizeof");
_Static_assert(_Alignof(struct H_alignment) == 128, "record H_alignment wrong alignment");
_Static_assert(sizeof(struct H_packed) == 2, "record H_packed wrong sizeof");
_Static_assert(_Alignof(struct H_packed) == 1, "record H_packed wrong alignment");
_Static_assert(sizeof(struct H_required_alignment) == 3, "record H_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "record H_required_alignment wrong alignment");
_Static_assert(sizeof(struct H_size) == 4, "record H_size wrong sizeof");
_Static_assert(_Alignof(struct H_size) == 1, "record H_size wrong alignment");
#endif
_Static_assert(sizeof(AA) == 2, "record AA wrong sizeof");
_Static_assert(_Alignof(AA) == 1, "record AA wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct AA_alignment) == 3, "record AA_alignment wrong sizeof");
_Static_assert(_Alignof(struct AA_alignment) == 1, "record AA_alignment wrong alignment");
_Static_assert(sizeof(struct AA_packed) == 2, "record AA_packed wrong sizeof");
_Static_assert(_Alignof(struct AA_packed) == 1, "record AA_packed wrong alignment");
_Static_assert(sizeof(struct AA_required_alignment) == 3, "record AA_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct AA_required_alignment) == 1, "record AA_required_alignment wrong alignment");
_Static_assert(sizeof(struct AA_size) == 4, "record AA_size wrong sizeof");
_Static_assert(_Alignof(struct AA_size) == 1, "record AA_size wrong alignment");
#endif
_Static_assert(sizeof(AB) == 2, "record AB wrong sizeof");
_Static_assert(_Alignof(AB) == 2, "record AB wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct AB_alignment) == 4, "record AB_alignment wrong sizeof");
_Static_assert(_Alignof(struct AB_alignment) == 2, "record AB_alignment wrong alignment");
_Static_assert(sizeof(struct AB_packed) == 2, "record AB_packed wrong sizeof");
_Static_assert(_Alignof(struct AB_packed) == 1, "record AB_packed wrong alignment");
_Static_assert(sizeof(struct AB_required_alignment) == 3, "record AB_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct AB_required_alignment) == 1, "record AB_required_alignment wrong alignment");
_Static_assert(sizeof(struct AB_size) == 4, "record AB_size wrong sizeof");
_Static_assert(_Alignof(struct AB_size) == 1, "record AB_size wrong alignment");
#endif
_Static_assert(sizeof(AC) == 2, "record AC wrong sizeof");
_Static_assert(_Alignof(AC) == 4, "record AC wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct AC_alignment) == 8, "record AC_alignment wrong sizeof");
_Static_assert(_Alignof(struct AC_alignment) == 4, "record AC_alignment wrong alignment");
_Static_assert(sizeof(struct AC_packed) == 2, "record AC_packed wrong sizeof");
_Static_assert(_Alignof(struct AC_packed) == 1, "record AC_packed wrong alignment");
_Static_assert(sizeof(struct AC_required_alignment) == 3, "record AC_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct AC_required_alignment) == 1, "record AC_required_alignment wrong alignment");
_Static_assert(sizeof(struct AC_size) == 4, "record AC_size wrong sizeof");
_Static_assert(_Alignof(struct AC_size) == 1, "record AC_size wrong alignment");
#endif
_Static_assert(sizeof(AD) == 2, "record AD wrong sizeof");
_Static_assert(_Alignof(AD) == 8, "record AD wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct AD_alignment) == 16, "record AD_alignment wrong sizeof");
_Static_assert(_Alignof(struct AD_alignment) == 8, "record AD_alignment wrong alignment");
_Static_assert(sizeof(struct AD_packed) == 2, "record AD_packed wrong sizeof");
_Static_assert(_Alignof(struct AD_packed) == 1, "record AD_packed wrong alignment");
_Static_assert(sizeof(struct AD_required_alignment) == 3, "record AD_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct AD_required_alignment) == 1, "record AD_required_alignment wrong alignment");
_Static_assert(sizeof(struct AD_size) == 4, "record AD_size wrong sizeof");
_Static_assert(_Alignof(struct AD_size) == 1, "record AD_size wrong alignment");
#endif
_Static_assert(sizeof(AE) == 2, "record AE wrong sizeof");
_Static_assert(_Alignof(AE) == 16, "record AE wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct AE_alignment) == 32, "record AE_alignment wrong sizeof");
_Static_assert(_Alignof(struct AE_alignment) == 16, "record AE_alignment wrong alignment");
_Static_assert(sizeof(struct AE_packed) == 2, "record AE_packed wrong sizeof");
_Static_assert(_Alignof(struct AE_packed) == 1, "record AE_packed wrong alignment");
_Static_assert(sizeof(struct AE_required_alignment) == 3, "record AE_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct AE_required_alignment) == 1, "record AE_required_alignment wrong alignment");
_Static_assert(sizeof(struct AE_size) == 4, "record AE_size wrong sizeof");
_Static_assert(_Alignof(struct AE_size) == 1, "record AE_size wrong alignment");
#endif
_Static_assert(sizeof(AF) == 2, "record AF wrong sizeof");
_Static_assert(_Alignof(AF) == 32, "record AF wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct AF_alignment) == 64, "record AF_alignment wrong sizeof");
_Static_assert(_Alignof(struct AF_alignment) == 32, "record AF_alignment wrong alignment");
_Static_assert(sizeof(struct AF_packed) == 2, "record AF_packed wrong sizeof");
_Static_assert(_Alignof(struct AF_packed) == 1, "record AF_packed wrong alignment");
_Static_assert(sizeof(struct AF_required_alignment) == 3, "record AF_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct AF_required_alignment) == 1, "record AF_required_alignment wrong alignment");
_Static_assert(sizeof(struct AF_size) == 4, "record AF_size wrong sizeof");
_Static_assert(_Alignof(struct AF_size) == 1, "record AF_size wrong alignment");
#endif
_Static_assert(sizeof(AG) == 2, "record AG wrong sizeof");
_Static_assert(_Alignof(AG) == 64, "record AG wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct AG_alignment) == 128, "record AG_alignment wrong sizeof");
_Static_assert(_Alignof(struct AG_alignment) == 64, "record AG_alignment wrong alignment");
_Static_assert(sizeof(struct AG_packed) == 2, "record AG_packed wrong sizeof");
_Static_assert(_Alignof(struct AG_packed) == 1, "record AG_packed wrong alignment");
_Static_assert(sizeof(struct AG_required_alignment) == 3, "record AG_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct AG_required_alignment) == 1, "record AG_required_alignment wrong alignment");
_Static_assert(sizeof(struct AG_size) == 4, "record AG_size wrong sizeof");
_Static_assert(_Alignof(struct AG_size) == 1, "record AG_size wrong alignment");
#endif
_Static_assert(sizeof(AH) == 2, "record AH wrong sizeof");
_Static_assert(_Alignof(AH) == 128, "record AH wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct AH_alignment) == 256, "record AH_alignment wrong sizeof");
_Static_assert(_Alignof(struct AH_alignment) == 128, "record AH_alignment wrong alignment");
_Static_assert(sizeof(struct AH_packed) == 2, "record AH_packed wrong sizeof");
_Static_assert(_Alignof(struct AH_packed) == 1, "record AH_packed wrong alignment");
_Static_assert(sizeof(struct AH_required_alignment) == 3, "record AH_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct AH_required_alignment) == 1, "record AH_required_alignment wrong alignment");
_Static_assert(sizeof(struct AH_size) == 4, "record AH_size wrong sizeof");
_Static_assert(_Alignof(struct AH_size) == 1, "record AH_size wrong alignment");
#endif
_Static_assert(sizeof(BA) == 2, "record BA wrong sizeof");
_Static_assert(_Alignof(BA) == 1, "record BA wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct BA_alignment) == 3, "record BA_alignment wrong sizeof");
_Static_assert(_Alignof(struct BA_alignment) == 1, "record BA_alignment wrong alignment");
_Static_assert(sizeof(struct BA_packed) == 2, "record BA_packed wrong sizeof");
_Static_assert(_Alignof(struct BA_packed) == 1, "record BA_packed wrong alignment");
_Static_assert(sizeof(struct BA_required_alignment) == 3, "record BA_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct BA_required_alignment) == 1, "record BA_required_alignment wrong alignment");
_Static_assert(sizeof(struct BA_size) == 4, "record BA_size wrong sizeof");
_Static_assert(_Alignof(struct BA_size) == 1, "record BA_size wrong alignment");
#endif
_Static_assert(sizeof(BB) == 2, "record BB wrong sizeof");
_Static_assert(_Alignof(BB) == 2, "record BB wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct BB_alignment) == 4, "record BB_alignment wrong sizeof");
_Static_assert(_Alignof(struct BB_alignment) == 2, "record BB_alignment wrong alignment");
_Static_assert(sizeof(struct BB_packed) == 2, "record BB_packed wrong sizeof");
_Static_assert(_Alignof(struct BB_packed) == 1, "record BB_packed wrong alignment");
_Static_assert(sizeof(struct BB_required_alignment) == 3, "record BB_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct BB_required_alignment) == 1, "record BB_required_alignment wrong alignment");
_Static_assert(sizeof(struct BB_size) == 4, "record BB_size wrong sizeof");
_Static_assert(_Alignof(struct BB_size) == 1, "record BB_size wrong alignment");
#endif
_Static_assert(sizeof(BC) == 2, "record BC wrong sizeof");
_Static_assert(_Alignof(BC) == 4, "record BC wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct BC_alignment) == 8, "record BC_alignment wrong sizeof");
_Static_assert(_Alignof(struct BC_alignment) == 4, "record BC_alignment wrong alignment");
_Static_assert(sizeof(struct BC_packed) == 2, "record BC_packed wrong sizeof");
_Static_assert(_Alignof(struct BC_packed) == 1, "record BC_packed wrong alignment");
_Static_assert(sizeof(struct BC_required_alignment) == 3, "record BC_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct BC_required_alignment) == 1, "record BC_required_alignment wrong alignment");
_Static_assert(sizeof(struct BC_size) == 4, "record BC_size wrong sizeof");
_Static_assert(_Alignof(struct BC_size) == 1, "record BC_size wrong alignment");
#endif
_Static_assert(sizeof(BD) == 2, "record BD wrong sizeof");
_Static_assert(_Alignof(BD) == 8, "record BD wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct BD_alignment) == 16, "record BD_alignment wrong sizeof");
_Static_assert(_Alignof(struct BD_alignment) == 8, "record BD_alignment wrong alignment");
_Static_assert(sizeof(struct BD_packed) == 2, "record BD_packed wrong sizeof");
_Static_assert(_Alignof(struct BD_packed) == 1, "record BD_packed wrong alignment");
_Static_assert(sizeof(struct BD_required_alignment) == 3, "record BD_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct BD_required_alignment) == 1, "record BD_required_alignment wrong alignment");
_Static_assert(sizeof(struct BD_size) == 4, "record BD_size wrong sizeof");
_Static_assert(_Alignof(struct BD_size) == 1, "record BD_size wrong alignment");
#endif
_Static_assert(sizeof(BE) == 2, "record BE wrong sizeof");
_Static_assert(_Alignof(BE) == 16, "record BE wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct BE_alignment) == 32, "record BE_alignment wrong sizeof");
_Static_assert(_Alignof(struct BE_alignment) == 16, "record BE_alignment wrong alignment");
_Static_assert(sizeof(struct BE_packed) == 2, "record BE_packed wrong sizeof");
_Static_assert(_Alignof(struct BE_packed) == 1, "record BE_packed wrong alignment");
_Static_assert(sizeof(struct BE_required_alignment) == 3, "record BE_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct BE_required_alignment) == 1, "record BE_required_alignment wrong alignment");
_Static_assert(sizeof(struct BE_size) == 4, "record BE_size wrong sizeof");
_Static_assert(_Alignof(struct BE_size) == 1, "record BE_size wrong alignment");
#endif
_Static_assert(sizeof(BF) == 2, "record BF wrong sizeof");
_Static_assert(_Alignof(BF) == 32, "record BF wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct BF_alignment) == 64, "record BF_alignment wrong sizeof");
_Static_assert(_Alignof(struct BF_alignment) == 32, "record BF_alignment wrong alignment");
_Static_assert(sizeof(struct BF_packed) == 2, "record BF_packed wrong sizeof");
_Static_assert(_Alignof(struct BF_packed) == 1, "record BF_packed wrong alignment");
_Static_assert(sizeof(struct BF_required_alignment) == 3, "record BF_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct BF_required_alignment) == 1, "record BF_required_alignment wrong alignment");
_Static_assert(sizeof(struct BF_size) == 4, "record BF_size wrong sizeof");
_Static_assert(_Alignof(struct BF_size) == 1, "record BF_size wrong alignment");
#endif
_Static_assert(sizeof(BG) == 2, "record BG wrong sizeof");
_Static_assert(_Alignof(BG) == 64, "record BG wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct BG_alignment) == 128, "record BG_alignment wrong sizeof");
_Static_assert(_Alignof(struct BG_alignment) == 64, "record BG_alignment wrong alignment");
_Static_assert(sizeof(struct BG_packed) == 2, "record BG_packed wrong sizeof");
_Static_assert(_Alignof(struct BG_packed) == 1, "record BG_packed wrong alignment");
_Static_assert(sizeof(struct BG_required_alignment) == 3, "record BG_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct BG_required_alignment) == 1, "record BG_required_alignment wrong alignment");
_Static_assert(sizeof(struct BG_size) == 4, "record BG_size wrong sizeof");
_Static_assert(_Alignof(struct BG_size) == 1, "record BG_size wrong alignment");
#endif
_Static_assert(sizeof(BH) == 2, "record BH wrong sizeof");
_Static_assert(_Alignof(BH) == 128, "record BH wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct BH_alignment) == 256, "record BH_alignment wrong sizeof");
_Static_assert(_Alignof(struct BH_alignment) == 128, "record BH_alignment wrong alignment");
_Static_assert(sizeof(struct BH_packed) == 2, "record BH_packed wrong sizeof");
_Static_assert(_Alignof(struct BH_packed) == 1, "record BH_packed wrong alignment");
_Static_assert(sizeof(struct BH_required_alignment) == 3, "record BH_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct BH_required_alignment) == 1, "record BH_required_alignment wrong alignment");
_Static_assert(sizeof(struct BH_size) == 4, "record BH_size wrong sizeof");
_Static_assert(_Alignof(struct BH_size) == 1, "record BH_size wrong alignment");
#endif
_Static_assert(sizeof(DA) == 2, "record DA wrong sizeof");
_Static_assert(_Alignof(DA) == 1, "record DA wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct DA_alignment) == 3, "record DA_alignment wrong sizeof");
_Static_assert(_Alignof(struct DA_alignment) == 1, "record DA_alignment wrong alignment");
_Static_assert(sizeof(struct DA_packed) == 2, "record DA_packed wrong sizeof");
_Static_assert(_Alignof(struct DA_packed) == 1, "record DA_packed wrong alignment");
_Static_assert(sizeof(struct DA_required_alignment) == 3, "record DA_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct DA_required_alignment) == 1, "record DA_required_alignment wrong alignment");
_Static_assert(sizeof(struct DA_size) == 4, "record DA_size wrong sizeof");
_Static_assert(_Alignof(struct DA_size) == 1, "record DA_size wrong alignment");
#endif
_Static_assert(sizeof(DB) == 2, "record DB wrong sizeof");
_Static_assert(_Alignof(DB) == 2, "record DB wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct DB_alignment) == 4, "record DB_alignment wrong sizeof");
_Static_assert(_Alignof(struct DB_alignment) == 2, "record DB_alignment wrong alignment");
_Static_assert(sizeof(struct DB_packed) == 2, "record DB_packed wrong sizeof");
_Static_assert(_Alignof(struct DB_packed) == 1, "record DB_packed wrong alignment");
_Static_assert(sizeof(struct DB_required_alignment) == 3, "record DB_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct DB_required_alignment) == 1, "record DB_required_alignment wrong alignment");
_Static_assert(sizeof(struct DB_size) == 4, "record DB_size wrong sizeof");
_Static_assert(_Alignof(struct DB_size) == 1, "record DB_size wrong alignment");
#endif
_Static_assert(sizeof(DC) == 2, "record DC wrong sizeof");
_Static_assert(_Alignof(DC) == 4, "record DC wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct DC_alignment) == 8, "record DC_alignment wrong sizeof");
_Static_assert(_Alignof(struct DC_alignment) == 4, "record DC_alignment wrong alignment");
_Static_assert(sizeof(struct DC_packed) == 2, "record DC_packed wrong sizeof");
_Static_assert(_Alignof(struct DC_packed) == 1, "record DC_packed wrong alignment");
_Static_assert(sizeof(struct DC_required_alignment) == 3, "record DC_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct DC_required_alignment) == 1, "record DC_required_alignment wrong alignment");
_Static_assert(sizeof(struct DC_size) == 4, "record DC_size wrong sizeof");
_Static_assert(_Alignof(struct DC_size) == 1, "record DC_size wrong alignment");
#endif
_Static_assert(sizeof(DD) == 2, "record DD wrong sizeof");
_Static_assert(_Alignof(DD) == 8, "record DD wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct DD_alignment) == 16, "record DD_alignment wrong sizeof");
_Static_assert(_Alignof(struct DD_alignment) == 8, "record DD_alignment wrong alignment");
_Static_assert(sizeof(struct DD_packed) == 2, "record DD_packed wrong sizeof");
_Static_assert(_Alignof(struct DD_packed) == 1, "record DD_packed wrong alignment");
_Static_assert(sizeof(struct DD_required_alignment) == 3, "record DD_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct DD_required_alignment) == 1, "record DD_required_alignment wrong alignment");
_Static_assert(sizeof(struct DD_size) == 4, "record DD_size wrong sizeof");
_Static_assert(_Alignof(struct DD_size) == 1, "record DD_size wrong alignment");
#endif
_Static_assert(sizeof(DE) == 2, "record DE wrong sizeof");
_Static_assert(_Alignof(DE) == 16, "record DE wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct DE_alignment) == 32, "record DE_alignment wrong sizeof");
_Static_assert(_Alignof(struct DE_alignment) == 16, "record DE_alignment wrong alignment");
_Static_assert(sizeof(struct DE_packed) == 2, "record DE_packed wrong sizeof");
_Static_assert(_Alignof(struct DE_packed) == 1, "record DE_packed wrong alignment");
_Static_assert(sizeof(struct DE_required_alignment) == 3, "record DE_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct DE_required_alignment) == 1, "record DE_required_alignment wrong alignment");
_Static_assert(sizeof(struct DE_size) == 4, "record DE_size wrong sizeof");
_Static_assert(_Alignof(struct DE_size) == 1, "record DE_size wrong alignment");
#endif
_Static_assert(sizeof(DF) == 2, "record DF wrong sizeof");
_Static_assert(_Alignof(DF) == 32, "record DF wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct DF_alignment) == 64, "record DF_alignment wrong sizeof");
_Static_assert(_Alignof(struct DF_alignment) == 32, "record DF_alignment wrong alignment");
_Static_assert(sizeof(struct DF_packed) == 2, "record DF_packed wrong sizeof");
_Static_assert(_Alignof(struct DF_packed) == 1, "record DF_packed wrong alignment");
_Static_assert(sizeof(struct DF_required_alignment) == 3, "record DF_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct DF_required_alignment) == 1, "record DF_required_alignment wrong alignment");
_Static_assert(sizeof(struct DF_size) == 4, "record DF_size wrong sizeof");
_Static_assert(_Alignof(struct DF_size) == 1, "record DF_size wrong alignment");
#endif
_Static_assert(sizeof(DG) == 2, "record DG wrong sizeof");
_Static_assert(_Alignof(DG) == 64, "record DG wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct DG_alignment) == 128, "record DG_alignment wrong sizeof");
_Static_assert(_Alignof(struct DG_alignment) == 64, "record DG_alignment wrong alignment");
_Static_assert(sizeof(struct DG_packed) == 2, "record DG_packed wrong sizeof");
_Static_assert(_Alignof(struct DG_packed) == 1, "record DG_packed wrong alignment");
_Static_assert(sizeof(struct DG_required_alignment) == 3, "record DG_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct DG_required_alignment) == 1, "record DG_required_alignment wrong alignment");
_Static_assert(sizeof(struct DG_size) == 4, "record DG_size wrong sizeof");
_Static_assert(_Alignof(struct DG_size) == 1, "record DG_size wrong alignment");
#endif
_Static_assert(sizeof(DH) == 2, "record DH wrong sizeof");
_Static_assert(_Alignof(DH) == 128, "record DH wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct DH_alignment) == 256, "record DH_alignment wrong sizeof");
_Static_assert(_Alignof(struct DH_alignment) == 128, "record DH_alignment wrong alignment");
_Static_assert(sizeof(struct DH_packed) == 2, "record DH_packed wrong sizeof");
_Static_assert(_Alignof(struct DH_packed) == 1, "record DH_packed wrong alignment");
_Static_assert(sizeof(struct DH_required_alignment) == 3, "record DH_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct DH_required_alignment) == 1, "record DH_required_alignment wrong alignment");
_Static_assert(sizeof(struct DH_size) == 4, "record DH_size wrong sizeof");
_Static_assert(_Alignof(struct DH_size) == 1, "record DH_size wrong alignment");
#endif
#elif defined(MSP430_NONE_ELF) 
_Static_assert(sizeof(A) == 2, "record A wrong sizeof");
_Static_assert(_Alignof(A) == 1, "record A wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 3, "record A_alignment wrong sizeof");
_Static_assert(_Alignof(struct A_alignment) == 1, "record A_alignment wrong alignment");
_Static_assert(sizeof(struct A_packed) == 2, "record A_packed wrong sizeof");
_Static_assert(_Alignof(struct A_packed) == 1, "record A_packed wrong alignment");
_Static_assert(sizeof(struct A_required_alignment) == 3, "record A_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "record A_required_alignment wrong alignment");
_Static_assert(sizeof(struct A_size) == 4, "record A_size wrong sizeof");
_Static_assert(_Alignof(struct A_size) == 1, "record A_size wrong alignment");
#endif
_Static_assert(sizeof(B) == 2, "record B wrong sizeof");
_Static_assert(_Alignof(B) == 2, "record B wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 4, "record B_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_alignment) == 2, "record B_alignment wrong alignment");
_Static_assert(sizeof(struct B_packed) == 2, "record B_packed wrong sizeof");
_Static_assert(_Alignof(struct B_packed) == 1, "record B_packed wrong alignment");
_Static_assert(sizeof(struct B_required_alignment) == 3, "record B_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "record B_required_alignment wrong alignment");
_Static_assert(sizeof(struct B_size) == 4, "record B_size wrong sizeof");
_Static_assert(_Alignof(struct B_size) == 1, "record B_size wrong alignment");
#endif
_Static_assert(sizeof(C) == 2, "record C wrong sizeof");
_Static_assert(_Alignof(C) == 4, "record C wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 8, "record C_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_alignment) == 4, "record C_alignment wrong alignment");
_Static_assert(sizeof(struct C_packed) == 2, "record C_packed wrong sizeof");
_Static_assert(_Alignof(struct C_packed) == 1, "record C_packed wrong alignment");
_Static_assert(sizeof(struct C_required_alignment) == 3, "record C_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "record C_required_alignment wrong alignment");
_Static_assert(sizeof(struct C_size) == 4, "record C_size wrong sizeof");
_Static_assert(_Alignof(struct C_size) == 1, "record C_size wrong alignment");
#endif
_Static_assert(sizeof(D) == 2, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 8, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 16, "record D_alignment wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 8, "record D_alignment wrong alignment");
_Static_assert(sizeof(struct D_packed) == 2, "record D_packed wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D_packed wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 3, "record D_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D_required_alignment wrong alignment");
_Static_assert(sizeof(struct D_size) == 4, "record D_size wrong sizeof");
_Static_assert(_Alignof(struct D_size) == 1, "record D_size wrong alignment");
#endif
_Static_assert(sizeof(E) == 2, "record E wrong sizeof");
_Static_assert(_Alignof(E) == 16, "record E wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 32, "record E_alignment wrong sizeof");
_Static_assert(_Alignof(struct E_alignment) == 16, "record E_alignment wrong alignment");
_Static_assert(sizeof(struct E_packed) == 2, "record E_packed wrong sizeof");
_Static_assert(_Alignof(struct E_packed) == 1, "record E_packed wrong alignment");
_Static_assert(sizeof(struct E_required_alignment) == 3, "record E_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "record E_required_alignment wrong alignment");
_Static_assert(sizeof(struct E_size) == 4, "record E_size wrong sizeof");
_Static_assert(_Alignof(struct E_size) == 1, "record E_size wrong alignment");
#endif
_Static_assert(sizeof(F) == 2, "record F wrong sizeof");
_Static_assert(_Alignof(F) == 32, "record F wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 64, "record F_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_alignment) == 32, "record F_alignment wrong alignment");
_Static_assert(sizeof(struct F_packed) == 2, "record F_packed wrong sizeof");
_Static_assert(_Alignof(struct F_packed) == 1, "record F_packed wrong alignment");
_Static_assert(sizeof(struct F_required_alignment) == 3, "record F_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "record F_required_alignment wrong alignment");
_Static_assert(sizeof(struct F_size) == 4, "record F_size wrong sizeof");
_Static_assert(_Alignof(struct F_size) == 1, "record F_size wrong alignment");
#endif
_Static_assert(sizeof(G) == 2, "record G wrong sizeof");
_Static_assert(_Alignof(G) == 64, "record G wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 128, "record G_alignment wrong sizeof");
_Static_assert(_Alignof(struct G_alignment) == 64, "record G_alignment wrong alignment");
_Static_assert(sizeof(struct G_packed) == 2, "record G_packed wrong sizeof");
_Static_assert(_Alignof(struct G_packed) == 1, "record G_packed wrong alignment");
_Static_assert(sizeof(struct G_required_alignment) == 3, "record G_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "record G_required_alignment wrong alignment");
_Static_assert(sizeof(struct G_size) == 4, "record G_size wrong sizeof");
_Static_assert(_Alignof(struct G_size) == 1, "record G_size wrong alignment");
#endif
_Static_assert(sizeof(H) == 2, "record H wrong sizeof");
_Static_assert(_Alignof(H) == 128, "record H wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 256, "record H_alignment wrong sizeof");
_Static_assert(_Alignof(struct H_alignment) == 128, "record H_alignment wrong alignment");
_Static_assert(sizeof(struct H_packed) == 2, "record H_packed wrong sizeof");
_Static_assert(_Alignof(struct H_packed) == 1, "record H_packed wrong alignment");
_Static_assert(sizeof(struct H_required_alignment) == 3, "record H_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "record H_required_alignment wrong alignment");
_Static_assert(sizeof(struct H_size) == 4, "record H_size wrong sizeof");
_Static_assert(_Alignof(struct H_size) == 1, "record H_size wrong alignment");
#endif
_Static_assert(sizeof(AA) == 2, "record AA wrong sizeof");
_Static_assert(_Alignof(AA) == 1, "record AA wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct AA_alignment) == 3, "record AA_alignment wrong sizeof");
_Static_assert(_Alignof(struct AA_alignment) == 1, "record AA_alignment wrong alignment");
_Static_assert(sizeof(struct AA_packed) == 2, "record AA_packed wrong sizeof");
_Static_assert(_Alignof(struct AA_packed) == 1, "record AA_packed wrong alignment");
_Static_assert(sizeof(struct AA_required_alignment) == 3, "record AA_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct AA_required_alignment) == 1, "record AA_required_alignment wrong alignment");
_Static_assert(sizeof(struct AA_size) == 4, "record AA_size wrong sizeof");
_Static_assert(_Alignof(struct AA_size) == 1, "record AA_size wrong alignment");
#endif
_Static_assert(sizeof(AB) == 2, "record AB wrong sizeof");
_Static_assert(_Alignof(AB) == 2, "record AB wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct AB_alignment) == 4, "record AB_alignment wrong sizeof");
_Static_assert(_Alignof(struct AB_alignment) == 2, "record AB_alignment wrong alignment");
_Static_assert(sizeof(struct AB_packed) == 2, "record AB_packed wrong sizeof");
_Static_assert(_Alignof(struct AB_packed) == 1, "record AB_packed wrong alignment");
_Static_assert(sizeof(struct AB_required_alignment) == 3, "record AB_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct AB_required_alignment) == 1, "record AB_required_alignment wrong alignment");
_Static_assert(sizeof(struct AB_size) == 4, "record AB_size wrong sizeof");
_Static_assert(_Alignof(struct AB_size) == 1, "record AB_size wrong alignment");
#endif
_Static_assert(sizeof(AC) == 2, "record AC wrong sizeof");
_Static_assert(_Alignof(AC) == 4, "record AC wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct AC_alignment) == 8, "record AC_alignment wrong sizeof");
_Static_assert(_Alignof(struct AC_alignment) == 4, "record AC_alignment wrong alignment");
_Static_assert(sizeof(struct AC_packed) == 2, "record AC_packed wrong sizeof");
_Static_assert(_Alignof(struct AC_packed) == 1, "record AC_packed wrong alignment");
_Static_assert(sizeof(struct AC_required_alignment) == 3, "record AC_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct AC_required_alignment) == 1, "record AC_required_alignment wrong alignment");
_Static_assert(sizeof(struct AC_size) == 4, "record AC_size wrong sizeof");
_Static_assert(_Alignof(struct AC_size) == 1, "record AC_size wrong alignment");
#endif
_Static_assert(sizeof(AD) == 2, "record AD wrong sizeof");
_Static_assert(_Alignof(AD) == 8, "record AD wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct AD_alignment) == 16, "record AD_alignment wrong sizeof");
_Static_assert(_Alignof(struct AD_alignment) == 8, "record AD_alignment wrong alignment");
_Static_assert(sizeof(struct AD_packed) == 2, "record AD_packed wrong sizeof");
_Static_assert(_Alignof(struct AD_packed) == 1, "record AD_packed wrong alignment");
_Static_assert(sizeof(struct AD_required_alignment) == 3, "record AD_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct AD_required_alignment) == 1, "record AD_required_alignment wrong alignment");
_Static_assert(sizeof(struct AD_size) == 4, "record AD_size wrong sizeof");
_Static_assert(_Alignof(struct AD_size) == 1, "record AD_size wrong alignment");
#endif
_Static_assert(sizeof(AE) == 2, "record AE wrong sizeof");
_Static_assert(_Alignof(AE) == 16, "record AE wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct AE_alignment) == 32, "record AE_alignment wrong sizeof");
_Static_assert(_Alignof(struct AE_alignment) == 16, "record AE_alignment wrong alignment");
_Static_assert(sizeof(struct AE_packed) == 2, "record AE_packed wrong sizeof");
_Static_assert(_Alignof(struct AE_packed) == 1, "record AE_packed wrong alignment");
_Static_assert(sizeof(struct AE_required_alignment) == 3, "record AE_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct AE_required_alignment) == 1, "record AE_required_alignment wrong alignment");
_Static_assert(sizeof(struct AE_size) == 4, "record AE_size wrong sizeof");
_Static_assert(_Alignof(struct AE_size) == 1, "record AE_size wrong alignment");
#endif
_Static_assert(sizeof(AF) == 2, "record AF wrong sizeof");
_Static_assert(_Alignof(AF) == 32, "record AF wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct AF_alignment) == 64, "record AF_alignment wrong sizeof");
_Static_assert(_Alignof(struct AF_alignment) == 32, "record AF_alignment wrong alignment");
_Static_assert(sizeof(struct AF_packed) == 2, "record AF_packed wrong sizeof");
_Static_assert(_Alignof(struct AF_packed) == 1, "record AF_packed wrong alignment");
_Static_assert(sizeof(struct AF_required_alignment) == 3, "record AF_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct AF_required_alignment) == 1, "record AF_required_alignment wrong alignment");
_Static_assert(sizeof(struct AF_size) == 4, "record AF_size wrong sizeof");
_Static_assert(_Alignof(struct AF_size) == 1, "record AF_size wrong alignment");
#endif
_Static_assert(sizeof(AG) == 2, "record AG wrong sizeof");
_Static_assert(_Alignof(AG) == 64, "record AG wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct AG_alignment) == 128, "record AG_alignment wrong sizeof");
_Static_assert(_Alignof(struct AG_alignment) == 64, "record AG_alignment wrong alignment");
_Static_assert(sizeof(struct AG_packed) == 2, "record AG_packed wrong sizeof");
_Static_assert(_Alignof(struct AG_packed) == 1, "record AG_packed wrong alignment");
_Static_assert(sizeof(struct AG_required_alignment) == 3, "record AG_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct AG_required_alignment) == 1, "record AG_required_alignment wrong alignment");
_Static_assert(sizeof(struct AG_size) == 4, "record AG_size wrong sizeof");
_Static_assert(_Alignof(struct AG_size) == 1, "record AG_size wrong alignment");
#endif
_Static_assert(sizeof(AH) == 2, "record AH wrong sizeof");
_Static_assert(_Alignof(AH) == 128, "record AH wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct AH_alignment) == 256, "record AH_alignment wrong sizeof");
_Static_assert(_Alignof(struct AH_alignment) == 128, "record AH_alignment wrong alignment");
_Static_assert(sizeof(struct AH_packed) == 2, "record AH_packed wrong sizeof");
_Static_assert(_Alignof(struct AH_packed) == 1, "record AH_packed wrong alignment");
_Static_assert(sizeof(struct AH_required_alignment) == 3, "record AH_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct AH_required_alignment) == 1, "record AH_required_alignment wrong alignment");
_Static_assert(sizeof(struct AH_size) == 4, "record AH_size wrong sizeof");
_Static_assert(_Alignof(struct AH_size) == 1, "record AH_size wrong alignment");
#endif
_Static_assert(sizeof(BA) == 2, "record BA wrong sizeof");
_Static_assert(_Alignof(BA) == 1, "record BA wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct BA_alignment) == 3, "record BA_alignment wrong sizeof");
_Static_assert(_Alignof(struct BA_alignment) == 1, "record BA_alignment wrong alignment");
_Static_assert(sizeof(struct BA_packed) == 2, "record BA_packed wrong sizeof");
_Static_assert(_Alignof(struct BA_packed) == 1, "record BA_packed wrong alignment");
_Static_assert(sizeof(struct BA_required_alignment) == 3, "record BA_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct BA_required_alignment) == 1, "record BA_required_alignment wrong alignment");
_Static_assert(sizeof(struct BA_size) == 4, "record BA_size wrong sizeof");
_Static_assert(_Alignof(struct BA_size) == 1, "record BA_size wrong alignment");
#endif
_Static_assert(sizeof(BB) == 2, "record BB wrong sizeof");
_Static_assert(_Alignof(BB) == 2, "record BB wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct BB_alignment) == 4, "record BB_alignment wrong sizeof");
_Static_assert(_Alignof(struct BB_alignment) == 2, "record BB_alignment wrong alignment");
_Static_assert(sizeof(struct BB_packed) == 2, "record BB_packed wrong sizeof");
_Static_assert(_Alignof(struct BB_packed) == 1, "record BB_packed wrong alignment");
_Static_assert(sizeof(struct BB_required_alignment) == 3, "record BB_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct BB_required_alignment) == 1, "record BB_required_alignment wrong alignment");
_Static_assert(sizeof(struct BB_size) == 4, "record BB_size wrong sizeof");
_Static_assert(_Alignof(struct BB_size) == 1, "record BB_size wrong alignment");
#endif
_Static_assert(sizeof(BC) == 2, "record BC wrong sizeof");
_Static_assert(_Alignof(BC) == 4, "record BC wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct BC_alignment) == 8, "record BC_alignment wrong sizeof");
_Static_assert(_Alignof(struct BC_alignment) == 4, "record BC_alignment wrong alignment");
_Static_assert(sizeof(struct BC_packed) == 2, "record BC_packed wrong sizeof");
_Static_assert(_Alignof(struct BC_packed) == 1, "record BC_packed wrong alignment");
_Static_assert(sizeof(struct BC_required_alignment) == 3, "record BC_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct BC_required_alignment) == 1, "record BC_required_alignment wrong alignment");
_Static_assert(sizeof(struct BC_size) == 4, "record BC_size wrong sizeof");
_Static_assert(_Alignof(struct BC_size) == 1, "record BC_size wrong alignment");
#endif
_Static_assert(sizeof(BD) == 2, "record BD wrong sizeof");
_Static_assert(_Alignof(BD) == 8, "record BD wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct BD_alignment) == 16, "record BD_alignment wrong sizeof");
_Static_assert(_Alignof(struct BD_alignment) == 8, "record BD_alignment wrong alignment");
_Static_assert(sizeof(struct BD_packed) == 2, "record BD_packed wrong sizeof");
_Static_assert(_Alignof(struct BD_packed) == 1, "record BD_packed wrong alignment");
_Static_assert(sizeof(struct BD_required_alignment) == 3, "record BD_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct BD_required_alignment) == 1, "record BD_required_alignment wrong alignment");
_Static_assert(sizeof(struct BD_size) == 4, "record BD_size wrong sizeof");
_Static_assert(_Alignof(struct BD_size) == 1, "record BD_size wrong alignment");
#endif
_Static_assert(sizeof(BE) == 2, "record BE wrong sizeof");
_Static_assert(_Alignof(BE) == 16, "record BE wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct BE_alignment) == 32, "record BE_alignment wrong sizeof");
_Static_assert(_Alignof(struct BE_alignment) == 16, "record BE_alignment wrong alignment");
_Static_assert(sizeof(struct BE_packed) == 2, "record BE_packed wrong sizeof");
_Static_assert(_Alignof(struct BE_packed) == 1, "record BE_packed wrong alignment");
_Static_assert(sizeof(struct BE_required_alignment) == 3, "record BE_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct BE_required_alignment) == 1, "record BE_required_alignment wrong alignment");
_Static_assert(sizeof(struct BE_size) == 4, "record BE_size wrong sizeof");
_Static_assert(_Alignof(struct BE_size) == 1, "record BE_size wrong alignment");
#endif
_Static_assert(sizeof(BF) == 2, "record BF wrong sizeof");
_Static_assert(_Alignof(BF) == 32, "record BF wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct BF_alignment) == 64, "record BF_alignment wrong sizeof");
_Static_assert(_Alignof(struct BF_alignment) == 32, "record BF_alignment wrong alignment");
_Static_assert(sizeof(struct BF_packed) == 2, "record BF_packed wrong sizeof");
_Static_assert(_Alignof(struct BF_packed) == 1, "record BF_packed wrong alignment");
_Static_assert(sizeof(struct BF_required_alignment) == 3, "record BF_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct BF_required_alignment) == 1, "record BF_required_alignment wrong alignment");
_Static_assert(sizeof(struct BF_size) == 4, "record BF_size wrong sizeof");
_Static_assert(_Alignof(struct BF_size) == 1, "record BF_size wrong alignment");
#endif
_Static_assert(sizeof(BG) == 2, "record BG wrong sizeof");
_Static_assert(_Alignof(BG) == 64, "record BG wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct BG_alignment) == 128, "record BG_alignment wrong sizeof");
_Static_assert(_Alignof(struct BG_alignment) == 64, "record BG_alignment wrong alignment");
_Static_assert(sizeof(struct BG_packed) == 2, "record BG_packed wrong sizeof");
_Static_assert(_Alignof(struct BG_packed) == 1, "record BG_packed wrong alignment");
_Static_assert(sizeof(struct BG_required_alignment) == 3, "record BG_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct BG_required_alignment) == 1, "record BG_required_alignment wrong alignment");
_Static_assert(sizeof(struct BG_size) == 4, "record BG_size wrong sizeof");
_Static_assert(_Alignof(struct BG_size) == 1, "record BG_size wrong alignment");
#endif
_Static_assert(sizeof(BH) == 2, "record BH wrong sizeof");
_Static_assert(_Alignof(BH) == 128, "record BH wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct BH_alignment) == 256, "record BH_alignment wrong sizeof");
_Static_assert(_Alignof(struct BH_alignment) == 128, "record BH_alignment wrong alignment");
_Static_assert(sizeof(struct BH_packed) == 2, "record BH_packed wrong sizeof");
_Static_assert(_Alignof(struct BH_packed) == 1, "record BH_packed wrong alignment");
_Static_assert(sizeof(struct BH_required_alignment) == 3, "record BH_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct BH_required_alignment) == 1, "record BH_required_alignment wrong alignment");
_Static_assert(sizeof(struct BH_size) == 4, "record BH_size wrong sizeof");
_Static_assert(_Alignof(struct BH_size) == 1, "record BH_size wrong alignment");
#endif
_Static_assert(sizeof(DA) == 2, "record DA wrong sizeof");
_Static_assert(_Alignof(DA) == 1, "record DA wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct DA_alignment) == 3, "record DA_alignment wrong sizeof");
_Static_assert(_Alignof(struct DA_alignment) == 1, "record DA_alignment wrong alignment");
_Static_assert(sizeof(struct DA_packed) == 2, "record DA_packed wrong sizeof");
_Static_assert(_Alignof(struct DA_packed) == 1, "record DA_packed wrong alignment");
_Static_assert(sizeof(struct DA_required_alignment) == 3, "record DA_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct DA_required_alignment) == 1, "record DA_required_alignment wrong alignment");
_Static_assert(sizeof(struct DA_size) == 4, "record DA_size wrong sizeof");
_Static_assert(_Alignof(struct DA_size) == 1, "record DA_size wrong alignment");
#endif
_Static_assert(sizeof(DB) == 2, "record DB wrong sizeof");
_Static_assert(_Alignof(DB) == 2, "record DB wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct DB_alignment) == 4, "record DB_alignment wrong sizeof");
_Static_assert(_Alignof(struct DB_alignment) == 2, "record DB_alignment wrong alignment");
_Static_assert(sizeof(struct DB_packed) == 2, "record DB_packed wrong sizeof");
_Static_assert(_Alignof(struct DB_packed) == 1, "record DB_packed wrong alignment");
_Static_assert(sizeof(struct DB_required_alignment) == 3, "record DB_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct DB_required_alignment) == 1, "record DB_required_alignment wrong alignment");
_Static_assert(sizeof(struct DB_size) == 4, "record DB_size wrong sizeof");
_Static_assert(_Alignof(struct DB_size) == 1, "record DB_size wrong alignment");
#endif
_Static_assert(sizeof(DC) == 2, "record DC wrong sizeof");
_Static_assert(_Alignof(DC) == 4, "record DC wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct DC_alignment) == 8, "record DC_alignment wrong sizeof");
_Static_assert(_Alignof(struct DC_alignment) == 4, "record DC_alignment wrong alignment");
_Static_assert(sizeof(struct DC_packed) == 2, "record DC_packed wrong sizeof");
_Static_assert(_Alignof(struct DC_packed) == 1, "record DC_packed wrong alignment");
_Static_assert(sizeof(struct DC_required_alignment) == 3, "record DC_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct DC_required_alignment) == 1, "record DC_required_alignment wrong alignment");
_Static_assert(sizeof(struct DC_size) == 4, "record DC_size wrong sizeof");
_Static_assert(_Alignof(struct DC_size) == 1, "record DC_size wrong alignment");
#endif
_Static_assert(sizeof(DD) == 2, "record DD wrong sizeof");
_Static_assert(_Alignof(DD) == 8, "record DD wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct DD_alignment) == 16, "record DD_alignment wrong sizeof");
_Static_assert(_Alignof(struct DD_alignment) == 8, "record DD_alignment wrong alignment");
_Static_assert(sizeof(struct DD_packed) == 2, "record DD_packed wrong sizeof");
_Static_assert(_Alignof(struct DD_packed) == 1, "record DD_packed wrong alignment");
_Static_assert(sizeof(struct DD_required_alignment) == 3, "record DD_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct DD_required_alignment) == 1, "record DD_required_alignment wrong alignment");
_Static_assert(sizeof(struct DD_size) == 4, "record DD_size wrong sizeof");
_Static_assert(_Alignof(struct DD_size) == 1, "record DD_size wrong alignment");
#endif
_Static_assert(sizeof(DE) == 2, "record DE wrong sizeof");
_Static_assert(_Alignof(DE) == 16, "record DE wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct DE_alignment) == 32, "record DE_alignment wrong sizeof");
_Static_assert(_Alignof(struct DE_alignment) == 16, "record DE_alignment wrong alignment");
_Static_assert(sizeof(struct DE_packed) == 2, "record DE_packed wrong sizeof");
_Static_assert(_Alignof(struct DE_packed) == 1, "record DE_packed wrong alignment");
_Static_assert(sizeof(struct DE_required_alignment) == 3, "record DE_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct DE_required_alignment) == 1, "record DE_required_alignment wrong alignment");
_Static_assert(sizeof(struct DE_size) == 4, "record DE_size wrong sizeof");
_Static_assert(_Alignof(struct DE_size) == 1, "record DE_size wrong alignment");
#endif
_Static_assert(sizeof(DF) == 2, "record DF wrong sizeof");
_Static_assert(_Alignof(DF) == 32, "record DF wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct DF_alignment) == 64, "record DF_alignment wrong sizeof");
_Static_assert(_Alignof(struct DF_alignment) == 32, "record DF_alignment wrong alignment");
_Static_assert(sizeof(struct DF_packed) == 2, "record DF_packed wrong sizeof");
_Static_assert(_Alignof(struct DF_packed) == 1, "record DF_packed wrong alignment");
_Static_assert(sizeof(struct DF_required_alignment) == 3, "record DF_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct DF_required_alignment) == 1, "record DF_required_alignment wrong alignment");
_Static_assert(sizeof(struct DF_size) == 4, "record DF_size wrong sizeof");
_Static_assert(_Alignof(struct DF_size) == 1, "record DF_size wrong alignment");
#endif
_Static_assert(sizeof(DG) == 2, "record DG wrong sizeof");
_Static_assert(_Alignof(DG) == 64, "record DG wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct DG_alignment) == 128, "record DG_alignment wrong sizeof");
_Static_assert(_Alignof(struct DG_alignment) == 64, "record DG_alignment wrong alignment");
_Static_assert(sizeof(struct DG_packed) == 2, "record DG_packed wrong sizeof");
_Static_assert(_Alignof(struct DG_packed) == 1, "record DG_packed wrong alignment");
_Static_assert(sizeof(struct DG_required_alignment) == 3, "record DG_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct DG_required_alignment) == 1, "record DG_required_alignment wrong alignment");
_Static_assert(sizeof(struct DG_size) == 4, "record DG_size wrong sizeof");
_Static_assert(_Alignof(struct DG_size) == 1, "record DG_size wrong alignment");
#endif
_Static_assert(sizeof(DH) == 2, "record DH wrong sizeof");
_Static_assert(_Alignof(DH) == 128, "record DH wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct DH_alignment) == 256, "record DH_alignment wrong sizeof");
_Static_assert(_Alignof(struct DH_alignment) == 128, "record DH_alignment wrong alignment");
_Static_assert(sizeof(struct DH_packed) == 2, "record DH_packed wrong sizeof");
_Static_assert(_Alignof(struct DH_packed) == 1, "record DH_packed wrong alignment");
_Static_assert(sizeof(struct DH_required_alignment) == 3, "record DH_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct DH_required_alignment) == 1, "record DH_required_alignment wrong alignment");
_Static_assert(sizeof(struct DH_size) == 4, "record DH_size wrong sizeof");
_Static_assert(_Alignof(struct DH_size) == 1, "record DH_size wrong alignment");
#endif
#endif
