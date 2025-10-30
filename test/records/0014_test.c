// SPDX-License-Identifier: GPL-3.0-or-later

// This test file is auto-generated. do not edit.
// This file is a derivative work from the test files found
// in this repo : https://github.com/mahkoh/repr-c
// and is under the same licence as the original work.

#ifdef MSVC
__declspec(align(1)) typedef int A;
#else
typedef int A __attribute__((aligned(1)));
#endif
A var1;
struct A_extra_alignment {
    char a;
    A b;
};
struct A_extra_alignment var2;
#pragma pack(1)
struct A_extra_packed {
#ifdef MSVC
    char a[sizeof(A)];
#else
    A a;
#endif
};
#pragma pack()
struct A_extra_required_alignment {
    char a;
    struct A_extra_packed b;
};
struct A_extra_required_alignment var3;
struct A_extra_size {
    char a[sizeof(A)+1];
    char b;
};
struct A_extra_size var4;

#ifdef MSVC
__declspec(align(2)) typedef int B;
#else
typedef int B __attribute__((aligned(2)));
#endif
B var5;
struct B_extra_alignment {
    char a;
    B b;
};
struct B_extra_alignment var6;
#pragma pack(1)
struct B_extra_packed {
#ifdef MSVC
    char a[sizeof(B)];
#else
    B a;
#endif
};
#pragma pack()
struct B_extra_required_alignment {
    char a;
    struct B_extra_packed b;
};
struct B_extra_required_alignment var7;
struct B_extra_size {
    char a[sizeof(B)+1];
    char b;
};
struct B_extra_size var8;

#ifdef MSVC
__declspec(align(4)) typedef int C;
#else
typedef int C __attribute__((aligned(4)));
#endif
C var9;
struct C_extra_alignment {
    char a;
    C b;
};
struct C_extra_alignment var10;
#pragma pack(1)
struct C_extra_packed {
#ifdef MSVC
    char a[sizeof(C)];
#else
    C a;
#endif
};
#pragma pack()
struct C_extra_required_alignment {
    char a;
    struct C_extra_packed b;
};
struct C_extra_required_alignment var11;
struct C_extra_size {
    char a[sizeof(C)+1];
    char b;
};
struct C_extra_size var12;

#ifdef MSVC
__declspec(align(8)) typedef int D;
#else
typedef int D __attribute__((aligned(8)));
#endif
D var13;
struct D_extra_alignment {
    char a;
    D b;
};
struct D_extra_alignment var14;
#pragma pack(1)
struct D_extra_packed {
#ifdef MSVC
    char a[sizeof(D)];
#else
    D a;
#endif
};
#pragma pack()
struct D_extra_required_alignment {
    char a;
    struct D_extra_packed b;
};
struct D_extra_required_alignment var15;
struct D_extra_size {
    char a[sizeof(D)+1];
    char b;
};
struct D_extra_size var16;

#ifdef MSVC
__declspec(align(16)) typedef int E;
#else
typedef int E __attribute__((aligned(16)));
#endif
E var17;
struct E_extra_alignment {
    char a;
    E b;
};
struct E_extra_alignment var18;
#pragma pack(1)
struct E_extra_packed {
#ifdef MSVC
    char a[sizeof(E)];
#else
    E a;
#endif
};
#pragma pack()
struct E_extra_required_alignment {
    char a;
    struct E_extra_packed b;
};
struct E_extra_required_alignment var19;
struct E_extra_size {
    char a[sizeof(E)+1];
    char b;
};
struct E_extra_size var20;

#ifdef MSVC
__declspec(align(32)) typedef int F;
#else
typedef int F __attribute__((aligned(32)));
#endif
F var21;
struct F_extra_alignment {
    char a;
    F b;
};
struct F_extra_alignment var22;
#pragma pack(1)
struct F_extra_packed {
#ifdef MSVC
    char a[sizeof(F)];
#else
    F a;
#endif
};
#pragma pack()
struct F_extra_required_alignment {
    char a;
    struct F_extra_packed b;
};
struct F_extra_required_alignment var23;
struct F_extra_size {
    char a[sizeof(F)+1];
    char b;
};
struct F_extra_size var24;

#ifdef MSVC
__declspec(align(64)) typedef int G;
#else
typedef int G __attribute__((aligned(64)));
#endif
G var25;
struct G_extra_alignment {
    char a;
    G b;
};
struct G_extra_alignment var26;
#pragma pack(1)
struct G_extra_packed {
#ifdef MSVC
    char a[sizeof(G)];
#else
    G a;
#endif
};
#pragma pack()
struct G_extra_required_alignment {
    char a;
    struct G_extra_packed b;
};
struct G_extra_required_alignment var27;
struct G_extra_size {
    char a[sizeof(G)+1];
    char b;
};
struct G_extra_size var28;

#ifdef MSVC
__declspec(align(128)) typedef int H;
#else
typedef int H __attribute__((aligned(128)));
#endif
H var29;
struct H_extra_alignment {
    char a;
    H b;
};
struct H_extra_alignment var30;
#pragma pack(1)
struct H_extra_packed {
#ifdef MSVC
    char a[sizeof(H)];
#else
    H a;
#endif
};
#pragma pack()
struct H_extra_required_alignment {
    char a;
    struct H_extra_packed b;
};
struct H_extra_required_alignment var31;
struct H_extra_size {
    char a[sizeof(H)+1];
    char b;
};
struct H_extra_size var32;

#ifdef MSVC
__declspec(align(1)) typedef A AA;
#else
typedef A AA __attribute__((aligned(1)));
#endif
AA var33;
struct AA_extra_alignment {
    char a;
    AA b;
};
struct AA_extra_alignment var34;
#pragma pack(1)
struct AA_extra_packed {
#ifdef MSVC
    char a[sizeof(AA)];
#else
    AA a;
#endif
};
#pragma pack()
struct AA_extra_required_alignment {
    char a;
    struct AA_extra_packed b;
};
struct AA_extra_required_alignment var35;
struct AA_extra_size {
    char a[sizeof(AA)+1];
    char b;
};
struct AA_extra_size var36;

#ifdef MSVC
__declspec(align(2)) typedef A AB;
#else
typedef A AB __attribute__((aligned(2)));
#endif
AB var37;
struct AB_extra_alignment {
    char a;
    AB b;
};
struct AB_extra_alignment var38;
#pragma pack(1)
struct AB_extra_packed {
#ifdef MSVC
    char a[sizeof(AB)];
#else
    AB a;
#endif
};
#pragma pack()
struct AB_extra_required_alignment {
    char a;
    struct AB_extra_packed b;
};
struct AB_extra_required_alignment var39;
struct AB_extra_size {
    char a[sizeof(AB)+1];
    char b;
};
struct AB_extra_size var40;

#ifdef MSVC
__declspec(align(4)) typedef A AC;
#else
typedef A AC __attribute__((aligned(4)));
#endif
AC var41;
struct AC_extra_alignment {
    char a;
    AC b;
};
struct AC_extra_alignment var42;
#pragma pack(1)
struct AC_extra_packed {
#ifdef MSVC
    char a[sizeof(AC)];
#else
    AC a;
#endif
};
#pragma pack()
struct AC_extra_required_alignment {
    char a;
    struct AC_extra_packed b;
};
struct AC_extra_required_alignment var43;
struct AC_extra_size {
    char a[sizeof(AC)+1];
    char b;
};
struct AC_extra_size var44;

#ifdef MSVC
__declspec(align(8)) typedef A AD;
#else
typedef A AD __attribute__((aligned(8)));
#endif
AD var45;
struct AD_extra_alignment {
    char a;
    AD b;
};
struct AD_extra_alignment var46;
#pragma pack(1)
struct AD_extra_packed {
#ifdef MSVC
    char a[sizeof(AD)];
#else
    AD a;
#endif
};
#pragma pack()
struct AD_extra_required_alignment {
    char a;
    struct AD_extra_packed b;
};
struct AD_extra_required_alignment var47;
struct AD_extra_size {
    char a[sizeof(AD)+1];
    char b;
};
struct AD_extra_size var48;

#ifdef MSVC
__declspec(align(16)) typedef A AE;
#else
typedef A AE __attribute__((aligned(16)));
#endif
AE var49;
struct AE_extra_alignment {
    char a;
    AE b;
};
struct AE_extra_alignment var50;
#pragma pack(1)
struct AE_extra_packed {
#ifdef MSVC
    char a[sizeof(AE)];
#else
    AE a;
#endif
};
#pragma pack()
struct AE_extra_required_alignment {
    char a;
    struct AE_extra_packed b;
};
struct AE_extra_required_alignment var51;
struct AE_extra_size {
    char a[sizeof(AE)+1];
    char b;
};
struct AE_extra_size var52;

#ifdef MSVC
__declspec(align(32)) typedef A AF;
#else
typedef A AF __attribute__((aligned(32)));
#endif
AF var53;
struct AF_extra_alignment {
    char a;
    AF b;
};
struct AF_extra_alignment var54;
#pragma pack(1)
struct AF_extra_packed {
#ifdef MSVC
    char a[sizeof(AF)];
#else
    AF a;
#endif
};
#pragma pack()
struct AF_extra_required_alignment {
    char a;
    struct AF_extra_packed b;
};
struct AF_extra_required_alignment var55;
struct AF_extra_size {
    char a[sizeof(AF)+1];
    char b;
};
struct AF_extra_size var56;

#ifdef MSVC
__declspec(align(64)) typedef A AG;
#else
typedef A AG __attribute__((aligned(64)));
#endif
AG var57;
struct AG_extra_alignment {
    char a;
    AG b;
};
struct AG_extra_alignment var58;
#pragma pack(1)
struct AG_extra_packed {
#ifdef MSVC
    char a[sizeof(AG)];
#else
    AG a;
#endif
};
#pragma pack()
struct AG_extra_required_alignment {
    char a;
    struct AG_extra_packed b;
};
struct AG_extra_required_alignment var59;
struct AG_extra_size {
    char a[sizeof(AG)+1];
    char b;
};
struct AG_extra_size var60;

#ifdef MSVC
__declspec(align(128)) typedef A AH;
#else
typedef A AH __attribute__((aligned(128)));
#endif
AH var61;
struct AH_extra_alignment {
    char a;
    AH b;
};
struct AH_extra_alignment var62;
#pragma pack(1)
struct AH_extra_packed {
#ifdef MSVC
    char a[sizeof(AH)];
#else
    AH a;
#endif
};
#pragma pack()
struct AH_extra_required_alignment {
    char a;
    struct AH_extra_packed b;
};
struct AH_extra_required_alignment var63;
struct AH_extra_size {
    char a[sizeof(AH)+1];
    char b;
};
struct AH_extra_size var64;

#ifdef MSVC
__declspec(align(1)) typedef B BA;
#else
typedef B BA __attribute__((aligned(1)));
#endif
BA var65;
struct BA_extra_alignment {
    char a;
    BA b;
};
struct BA_extra_alignment var66;
#pragma pack(1)
struct BA_extra_packed {
#ifdef MSVC
    char a[sizeof(BA)];
#else
    BA a;
#endif
};
#pragma pack()
struct BA_extra_required_alignment {
    char a;
    struct BA_extra_packed b;
};
struct BA_extra_required_alignment var67;
struct BA_extra_size {
    char a[sizeof(BA)+1];
    char b;
};
struct BA_extra_size var68;

#ifdef MSVC
__declspec(align(2)) typedef B BB;
#else
typedef B BB __attribute__((aligned(2)));
#endif
BB var69;
struct BB_extra_alignment {
    char a;
    BB b;
};
struct BB_extra_alignment var70;
#pragma pack(1)
struct BB_extra_packed {
#ifdef MSVC
    char a[sizeof(BB)];
#else
    BB a;
#endif
};
#pragma pack()
struct BB_extra_required_alignment {
    char a;
    struct BB_extra_packed b;
};
struct BB_extra_required_alignment var71;
struct BB_extra_size {
    char a[sizeof(BB)+1];
    char b;
};
struct BB_extra_size var72;

#ifdef MSVC
__declspec(align(4)) typedef B BC;
#else
typedef B BC __attribute__((aligned(4)));
#endif
BC var73;
struct BC_extra_alignment {
    char a;
    BC b;
};
struct BC_extra_alignment var74;
#pragma pack(1)
struct BC_extra_packed {
#ifdef MSVC
    char a[sizeof(BC)];
#else
    BC a;
#endif
};
#pragma pack()
struct BC_extra_required_alignment {
    char a;
    struct BC_extra_packed b;
};
struct BC_extra_required_alignment var75;
struct BC_extra_size {
    char a[sizeof(BC)+1];
    char b;
};
struct BC_extra_size var76;

#ifdef MSVC
__declspec(align(8)) typedef B BD;
#else
typedef B BD __attribute__((aligned(8)));
#endif
BD var77;
struct BD_extra_alignment {
    char a;
    BD b;
};
struct BD_extra_alignment var78;
#pragma pack(1)
struct BD_extra_packed {
#ifdef MSVC
    char a[sizeof(BD)];
#else
    BD a;
#endif
};
#pragma pack()
struct BD_extra_required_alignment {
    char a;
    struct BD_extra_packed b;
};
struct BD_extra_required_alignment var79;
struct BD_extra_size {
    char a[sizeof(BD)+1];
    char b;
};
struct BD_extra_size var80;

#ifdef MSVC
__declspec(align(16)) typedef B BE;
#else
typedef B BE __attribute__((aligned(16)));
#endif
BE var81;
struct BE_extra_alignment {
    char a;
    BE b;
};
struct BE_extra_alignment var82;
#pragma pack(1)
struct BE_extra_packed {
#ifdef MSVC
    char a[sizeof(BE)];
#else
    BE a;
#endif
};
#pragma pack()
struct BE_extra_required_alignment {
    char a;
    struct BE_extra_packed b;
};
struct BE_extra_required_alignment var83;
struct BE_extra_size {
    char a[sizeof(BE)+1];
    char b;
};
struct BE_extra_size var84;

#ifdef MSVC
__declspec(align(32)) typedef B BF;
#else
typedef B BF __attribute__((aligned(32)));
#endif
BF var85;
struct BF_extra_alignment {
    char a;
    BF b;
};
struct BF_extra_alignment var86;
#pragma pack(1)
struct BF_extra_packed {
#ifdef MSVC
    char a[sizeof(BF)];
#else
    BF a;
#endif
};
#pragma pack()
struct BF_extra_required_alignment {
    char a;
    struct BF_extra_packed b;
};
struct BF_extra_required_alignment var87;
struct BF_extra_size {
    char a[sizeof(BF)+1];
    char b;
};
struct BF_extra_size var88;

#ifdef MSVC
__declspec(align(64)) typedef B BG;
#else
typedef B BG __attribute__((aligned(64)));
#endif
BG var89;
struct BG_extra_alignment {
    char a;
    BG b;
};
struct BG_extra_alignment var90;
#pragma pack(1)
struct BG_extra_packed {
#ifdef MSVC
    char a[sizeof(BG)];
#else
    BG a;
#endif
};
#pragma pack()
struct BG_extra_required_alignment {
    char a;
    struct BG_extra_packed b;
};
struct BG_extra_required_alignment var91;
struct BG_extra_size {
    char a[sizeof(BG)+1];
    char b;
};
struct BG_extra_size var92;

#ifdef MSVC
__declspec(align(128)) typedef B BH;
#else
typedef B BH __attribute__((aligned(128)));
#endif
BH var93;
struct BH_extra_alignment {
    char a;
    BH b;
};
struct BH_extra_alignment var94;
#pragma pack(1)
struct BH_extra_packed {
#ifdef MSVC
    char a[sizeof(BH)];
#else
    BH a;
#endif
};
#pragma pack()
struct BH_extra_required_alignment {
    char a;
    struct BH_extra_packed b;
};
struct BH_extra_required_alignment var95;
struct BH_extra_size {
    char a[sizeof(BH)+1];
    char b;
};
struct BH_extra_size var96;

#ifdef MSVC
__declspec(align(1)) typedef D DA;
#else
typedef D DA __attribute__((aligned(1)));
#endif
DA var97;
struct DA_extra_alignment {
    char a;
    DA b;
};
struct DA_extra_alignment var98;
#pragma pack(1)
struct DA_extra_packed {
#ifdef MSVC
    char a[sizeof(DA)];
#else
    DA a;
#endif
};
#pragma pack()
struct DA_extra_required_alignment {
    char a;
    struct DA_extra_packed b;
};
struct DA_extra_required_alignment var99;
struct DA_extra_size {
    char a[sizeof(DA)+1];
    char b;
};
struct DA_extra_size var100;

#ifdef MSVC
__declspec(align(2)) typedef D DB;
#else
typedef D DB __attribute__((aligned(2)));
#endif
DB var101;
struct DB_extra_alignment {
    char a;
    DB b;
};
struct DB_extra_alignment var102;
#pragma pack(1)
struct DB_extra_packed {
#ifdef MSVC
    char a[sizeof(DB)];
#else
    DB a;
#endif
};
#pragma pack()
struct DB_extra_required_alignment {
    char a;
    struct DB_extra_packed b;
};
struct DB_extra_required_alignment var103;
struct DB_extra_size {
    char a[sizeof(DB)+1];
    char b;
};
struct DB_extra_size var104;

#ifdef MSVC
__declspec(align(4)) typedef D DC;
#else
typedef D DC __attribute__((aligned(4)));
#endif
DC var105;
struct DC_extra_alignment {
    char a;
    DC b;
};
struct DC_extra_alignment var106;
#pragma pack(1)
struct DC_extra_packed {
#ifdef MSVC
    char a[sizeof(DC)];
#else
    DC a;
#endif
};
#pragma pack()
struct DC_extra_required_alignment {
    char a;
    struct DC_extra_packed b;
};
struct DC_extra_required_alignment var107;
struct DC_extra_size {
    char a[sizeof(DC)+1];
    char b;
};
struct DC_extra_size var108;

#ifdef MSVC
__declspec(align(8)) typedef D DD;
#else
typedef D DD __attribute__((aligned(8)));
#endif
DD var109;
struct DD_extra_alignment {
    char a;
    DD b;
};
struct DD_extra_alignment var110;
#pragma pack(1)
struct DD_extra_packed {
#ifdef MSVC
    char a[sizeof(DD)];
#else
    DD a;
#endif
};
#pragma pack()
struct DD_extra_required_alignment {
    char a;
    struct DD_extra_packed b;
};
struct DD_extra_required_alignment var111;
struct DD_extra_size {
    char a[sizeof(DD)+1];
    char b;
};
struct DD_extra_size var112;

#ifdef MSVC
__declspec(align(16)) typedef D DE;
#else
typedef D DE __attribute__((aligned(16)));
#endif
DE var113;
struct DE_extra_alignment {
    char a;
    DE b;
};
struct DE_extra_alignment var114;
#pragma pack(1)
struct DE_extra_packed {
#ifdef MSVC
    char a[sizeof(DE)];
#else
    DE a;
#endif
};
#pragma pack()
struct DE_extra_required_alignment {
    char a;
    struct DE_extra_packed b;
};
struct DE_extra_required_alignment var115;
struct DE_extra_size {
    char a[sizeof(DE)+1];
    char b;
};
struct DE_extra_size var116;

#ifdef MSVC
__declspec(align(32)) typedef D DF;
#else
typedef D DF __attribute__((aligned(32)));
#endif
DF var117;
struct DF_extra_alignment {
    char a;
    DF b;
};
struct DF_extra_alignment var118;
#pragma pack(1)
struct DF_extra_packed {
#ifdef MSVC
    char a[sizeof(DF)];
#else
    DF a;
#endif
};
#pragma pack()
struct DF_extra_required_alignment {
    char a;
    struct DF_extra_packed b;
};
struct DF_extra_required_alignment var119;
struct DF_extra_size {
    char a[sizeof(DF)+1];
    char b;
};
struct DF_extra_size var120;

#ifdef MSVC
__declspec(align(64)) typedef D DG;
#else
typedef D DG __attribute__((aligned(64)));
#endif
DG var121;
struct DG_extra_alignment {
    char a;
    DG b;
};
struct DG_extra_alignment var122;
#pragma pack(1)
struct DG_extra_packed {
#ifdef MSVC
    char a[sizeof(DG)];
#else
    DG a;
#endif
};
#pragma pack()
struct DG_extra_required_alignment {
    char a;
    struct DG_extra_packed b;
};
struct DG_extra_required_alignment var123;
struct DG_extra_size {
    char a[sizeof(DG)+1];
    char b;
};
struct DG_extra_size var124;

#ifdef MSVC
__declspec(align(128)) typedef D DH;
#else
typedef D DH __attribute__((aligned(128)));
#endif
DH var125;
struct DH_extra_alignment {
    char a;
    DH b;
};
struct DH_extra_alignment var126;
#pragma pack(1)
struct DH_extra_packed {
#ifdef MSVC
    char a[sizeof(DH)];
#else
    DH a;
#endif
};
#pragma pack()
struct DH_extra_required_alignment {
    char a;
    struct DH_extra_packed b;
};
struct DH_extra_required_alignment var127;
struct DH_extra_size {
    char a[sizeof(DH)+1];
    char b;
};
struct DH_extra_size var128;

// MAPPING|ONE|aarch64-generic-macos-none:Clang|aarch64-generic-fuchsia-gnu:Clang|aarch64-generic-linux-android:Clang|aarch64-generic-freebsd-gnu:Clang|aarch64-generic-hermit-eabi:Clang|aarch64-generic-linux-gnu:Gcc|aarch64-generic-linux-musl:Gcc|aarch64-generic-netbsd-gnu:Clang|aarch64-generic-other-none:Clang|aarch64-generic-openbsd-gnu:Clang|aarch64-generic-ios-none:Clang|aarch64-generic-ios-macabi:Clang|aarch64-generic-tvos-none:Clang|arm-baseline-other-eabi:Clang|arm-baseline-other-eabihf:Clang|arm-baseline-linux-gnueabi:Gcc|arm-baseline-linux-gnueabihf:Gcc|arm-arm710t-linux-gnueabi:Gcc|arm-arm1020e-linux-gnueabi:Gcc|arm-arm1136j_s-freebsd-gnueabihf:Clang|arm-arm1136j_s-netbsd-eabihf:Clang|arm-baseline-other-eabi:Clang|arm-baseline-other-eabihf:Clang|arm-cortex_r4-ios-none:Clang|arm-cortex_r4-linux-android:Clang|arm-cortex_r4-other-eabi:Clang|arm-cortex_r4-other-eabihf:Clang|arm-baseline-ios-none:Clang|arm-cortex_r4-freebsd-gnueabihf:Clang|arm-cortex_r4-linux-gnueabi:Gcc|arm-cortex_r4-linux-gnueabihf:Gcc|arm-cortex_r4-netbsd-eabihf:Clang|hexagon-generic-linux-musl:Clang|x86-pentium4-ios-none:Clang|x86-i586-linux-gnu:Gcc|x86-i586-linux-musl:Gcc|x86-i686-macos-none:Clang|x86-i686-linux-android:Clang|x86-i686-windows-gnu:Gcc|x86-i686-freebsd-gnu:Clang|x86-i686-haiku-gnu:Clang|x86-i686-linux-gnu:Gcc|x86-i686-linux-musl:Gcc|x86-i686-netbsd-gnu:Clang|x86-i686-openbsd-gnu:Clang|mips64el-mips64-linux-gnuabi64:Gcc|mips64el-mips64-linux-musl:Gcc|mips64-mips64-linux-gnuabi64:Gcc|mips64-mips64-linux-musl:Gcc|mipsel-mips32-linux-gnu:Gcc|mipsel-mips32-linux-musl:Gcc|mipsel-mips32-other-none:Clang|mips-mips32-linux-gnu:Gcc|mips-mips32r6-linux-gnu:Gcc|mips-mips32-linux-gnuabi64:Gcc|mips-mips64r6-linux-gnuabi64:Gcc|mips-mips32-linux-gnu:Gcc|mips-mips32-linux-musl:Gcc|powerpc64le-ppc64le-linux-gnu:Gcc|powerpc64le-ppc64le-linux-musl:Gcc|powerpc64-ppc64-freebsd-gnu:Clang|powerpc64-ppc64-linux-gnu:Gcc|powerpc64-ppc64-linux-musl:Gcc|powerpc-ppc-linux-gnu:Gcc|powerpc-ppc-linux-musl:Gcc|powerpc-ppc-netbsd-gnu:Clang|riscv32-baseline_rv32-other-eabi:Clang|riscv32-baseline_rv32-linux-gnu:Gcc|riscv64-baseline_rv64-other-eabi:Clang|riscv64-baseline_rv64-linux-gnu:Gcc|s390x-generic-linux-gnu:Gcc|sparc64-v9-linux-gnu:Gcc|sparc64-v9-netbsd-gnu:Clang|sparc64-v9-openbsd-gnu:Clang|sparc-v8-linux-gnu:Gcc|sparc64-v9-illumos-eabi:Clang|thumb-arm710t-other-eabi:Clang|thumb-cortex_m0-other-eabi:Clang|thumb-cortex_m4-other-eabihf:Clang|thumb-cortex_m4-other-eabi:Clang|thumb-cortex_m3-other-eabi:Clang|thumb-baseline-other-eabi:Clang|thumb-cortex_m33-other-eabihf:Clang|thumb-cortex_m33-other-eabi:Clang|wasm32-generic-emscripten-musl:Clang|wasm32-generic-other-musl:Clang|wasm32-generic-wasi-musl:Clang|x86_64-x86_64-ios-macabi:Clang|x86_64-x86_64-ios-none:Clang|x86_64-x86_64-macos-none:Clang|x86_64-x86_64-tvos-none:Clang|x86_64-x86_64-other-eabi:Clang|x86_64-x86_64-fuchsia-gnu:Clang|x86_64-x86_64-linux-android:Clang|x86_64-x86_64-illumos-eabi:Clang|x86_64-x86_64-windows-gnu:Gcc|x86_64-x86_64-dragonfly-eabi:Clang|x86_64-x86_64-freebsd-gnu:Clang|x86_64-x86_64-haiku-gnu:Clang|x86_64-x86_64-hermit-eabi:Clang|x86_64-x86_64-linux-gnux32:Gcc|x86_64-x86_64-linux-gnu:Gcc|x86_64-x86_64-linux-musl:Gcc|x86_64-x86_64-netbsd-gnu:Clang|x86_64-x86_64-openbsd-gnu:Clang|END
// repr targets Aarch64AppleMacosx|Some("aarch64-generic-macos-none") Aarch64Fuchsia|Some("aarch64-generic-fuchsia-gnu") Aarch64LinuxAndroid|Some("aarch64-generic-linux-android") Aarch64UnknownFreebsd|Some("aarch64-generic-freebsd-gnu") Aarch64UnknownHermit|Some("aarch64-generic-hermit-eabi") Aarch64UnknownLinuxGnu|Some("aarch64-generic-linux-gnu") Aarch64UnknownLinuxMusl|Some("aarch64-generic-linux-musl") Aarch64UnknownNetbsd|Some("aarch64-generic-netbsd-gnu") Aarch64UnknownNone|Some("aarch64-generic-other-none") Aarch64UnknownOpenbsd|Some("aarch64-generic-openbsd-gnu") Aarch64UnknownRedox|None Arm64AppleIos|Some("aarch64-generic-ios-none") Arm64AppleIosMacabi|Some("aarch64-generic-ios-macabi") Arm64AppleTvos|Some("aarch64-generic-tvos-none") Armebv7rUnknownNoneEabi|Some("arm-baseline-other-eabi") Armebv7rUnknownNoneEabihf|Some("arm-baseline-other-eabihf") ArmLinuxAndroideabi|None ArmUnknownLinuxGnueabi|Some("arm-baseline-linux-gnueabi") ArmUnknownLinuxGnueabihf|Some("arm-baseline-linux-gnueabihf") Armv4tUnknownLinuxGnueabi|Some("arm-arm710t-linux-gnueabi") Armv5teUnknownLinuxGnueabi|Some("arm-arm1020e-linux-gnueabi") Armv5teUnknownLinuxUclibcgnueabi|None Armv6UnknownFreebsdGnueabihf|Some("arm-arm1136j_s-freebsd-gnueabihf") Armv6UnknownNetbsdelfEabihf|Some("arm-arm1136j_s-netbsd-eabihf") Armv7aNoneEabi|Some("arm-baseline-other-eabi") Armv7aNoneEabihf|Some("arm-baseline-other-eabihf") Armv7AppleIos|Some("arm-cortex_r4-ios-none") Armv7NoneLinuxAndroid|Some("arm-cortex_r4-linux-android") Armv7rUnknownNoneEabi|Some("arm-cortex_r4-other-eabi") Armv7rUnknownNoneEabihf|Some("arm-cortex_r4-other-eabihf") Armv7sAppleIos|Some("arm-baseline-ios-none") Armv7UnknownFreebsdGnueabihf|Some("arm-cortex_r4-freebsd-gnueabihf") Armv7UnknownLinuxGnueabi|Some("arm-cortex_r4-linux-gnueabi") Armv7UnknownLinuxGnueabihf|Some("arm-cortex_r4-linux-gnueabihf") Armv7UnknownNetbsdelfEabihf|Some("arm-cortex_r4-netbsd-eabihf") HexagonUnknownLinuxMusl|Some("hexagon-generic-linux-musl") I386AppleIos|Some("x86-pentium4-ios-none") I586UnknownLinuxGnu|Some("x86-i586-linux-gnu") I586UnknownLinuxMusl|Some("x86-i586-linux-musl") I686AppleMacosx|Some("x86-i686-macos-none") I686LinuxAndroid|Some("x86-i686-linux-android") I686PcWindowsGnu|Some("x86-i686-windows-gnu") I686UnknownFreebsd|Some("x86-i686-freebsd-gnu") I686UnknownHaiku|Some("x86-i686-haiku-gnu") I686UnknownLinuxGnu|Some("x86-i686-linux-gnu") I686UnknownLinuxMusl|Some("x86-i686-linux-musl") I686UnknownNetbsdelf|Some("x86-i686-netbsd-gnu") I686UnknownOpenbsd|Some("x86-i686-openbsd-gnu") Mips64elUnknownLinuxGnuabi64|Some("mips64el-mips64-linux-gnuabi64") Mips64elUnknownLinuxMusl|Some("mips64el-mips64-linux-musl") Mips64UnknownLinuxGnuabi64|Some("mips64-mips64-linux-gnuabi64") Mips64UnknownLinuxMusl|Some("mips64-mips64-linux-musl") MipselSonyPsp|None MipselUnknownLinuxGnu|Some("mipsel-mips32-linux-gnu") MipselUnknownLinuxMusl|Some("mipsel-mips32-linux-musl") MipselUnknownLinuxUclibc|None MipselUnknownNone|Some("mipsel-mips32-other-none") Mipsisa32r6elUnknownLinuxGnu|Some("mips-mips32-linux-gnu") Mipsisa32r6UnknownLinuxGnu|Some("mips-mips32r6-linux-gnu") Mipsisa64r6elUnknownLinuxGnuabi64|Some("mips-mips32-linux-gnuabi64") Mipsisa64r6UnknownLinuxGnuabi64|Some("mips-mips64r6-linux-gnuabi64") MipsUnknownLinuxGnu|Some("mips-mips32-linux-gnu") MipsUnknownLinuxMusl|Some("mips-mips32-linux-musl") MipsUnknownLinuxUclibc|None Powerpc64leUnknownLinuxGnu|Some("powerpc64le-ppc64le-linux-gnu") Powerpc64leUnknownLinuxMusl|Some("powerpc64le-ppc64le-linux-musl") Powerpc64UnknownFreebsd|Some("powerpc64-ppc64-freebsd-gnu") Powerpc64UnknownLinuxGnu|Some("powerpc64-ppc64-linux-gnu") Powerpc64UnknownLinuxMusl|Some("powerpc64-ppc64-linux-musl") PowerpcUnknownLinuxGnu|Some("powerpc-ppc-linux-gnu") PowerpcUnknownLinuxGnuspe|None PowerpcUnknownLinuxMusl|Some("powerpc-ppc-linux-musl") PowerpcUnknownNetbsd|Some("powerpc-ppc-netbsd-gnu") Riscv32|Some("riscv32-baseline_rv32-other-eabi") Riscv32UnknownLinuxGnu|Some("riscv32-baseline_rv32-linux-gnu") Riscv64|Some("riscv64-baseline_rv64-other-eabi") Riscv64UnknownLinuxGnu|Some("riscv64-baseline_rv64-linux-gnu") S390xUnknownLinuxGnu|Some("s390x-generic-linux-gnu") Sparc64UnknownLinuxGnu|Some("sparc64-v9-linux-gnu") Sparc64UnknownNetbsd|Some("sparc64-v9-netbsd-gnu") Sparc64UnknownOpenbsd|Some("sparc64-v9-openbsd-gnu") SparcUnknownLinuxGnu|Some("sparc-v8-linux-gnu") Sparcv9Sunillumos|Some("sparc64-v9-illumos-eabi") Thumbv4tNoneEabi|Some("thumb-arm710t-other-eabi") Thumbv6mNoneEabi|Some("thumb-cortex_m0-other-eabi") Thumbv7emNoneEabihf|Some("thumb-cortex_m4-other-eabihf") Thumbv7emNoneEabi|Some("thumb-cortex_m4-other-eabi") Thumbv7mNoneEabi|Some("thumb-cortex_m3-other-eabi") Thumbv8mBaseNoneEabi|Some("thumb-baseline-other-eabi") Thumbv8mMainNoneEabihf|Some("thumb-cortex_m33-other-eabihf") Thumbv8mMainNoneEabi|Some("thumb-cortex_m33-other-eabi") Wasm32UnknownEmscripten|Some("wasm32-generic-emscripten-musl") Wasm32UnknownUnknown|Some("wasm32-generic-other-musl") Wasm32Wasi|Some("wasm32-generic-wasi-musl") X86_64AppleIosMacabi|Some("x86_64-x86_64-ios-macabi") X86_64AppleIos|Some("x86_64-x86_64-ios-none") X86_64AppleMacosx|Some("x86_64-x86_64-macos-none") X86_64AppleTvos|Some("x86_64-x86_64-tvos-none") X86_64Elf|Some("x86_64-x86_64-other-eabi") X86_64Fuchsia|Some("x86_64-x86_64-fuchsia-gnu") X86_64LinuxAndroid|Some("x86_64-x86_64-linux-android") X86_64Pcillumos|Some("x86_64-x86_64-illumos-eabi") X86_64PcWindowsGnu|Some("x86_64-x86_64-windows-gnu") X86_64RumprunNetbsd|None X86_64UnknownDragonfly|Some("x86_64-x86_64-dragonfly-eabi") X86_64UnknownFreebsd|Some("x86_64-x86_64-freebsd-gnu") X86_64UnknownHaiku|Some("x86_64-x86_64-haiku-gnu") X86_64UnknownHermit|Some("x86_64-x86_64-hermit-eabi") X86_64UnknownL4reUclibc|None X86_64UnknownLinuxGnux32|Some("x86_64-x86_64-linux-gnux32") X86_64UnknownLinuxGnu|Some("x86_64-x86_64-linux-gnu") X86_64UnknownLinuxMusl|Some("x86_64-x86_64-linux-musl") X86_64UnknownNetbsd|Some("x86_64-x86_64-netbsd-gnu") X86_64UnknownOpenbsd|Some("x86_64-x86_64-openbsd-gnu") X86_64UnknownRedox|None 
#ifdef ONE
_Static_assert(sizeof(A) == 4, "");
_Static_assert(_Alignof(A) == 1, "");
_Static_assert(sizeof(struct A_extra_alignment) == 5, "");
_Static_assert(_Alignof(struct A_extra_alignment) == 1, "");
_Static_assert(sizeof(struct A_extra_packed) == 4, "");
_Static_assert(_Alignof(struct A_extra_packed) == 1, "");
_Static_assert(sizeof(struct A_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct A_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A_extra_size) == 6, "");
_Static_assert(_Alignof(struct A_extra_size) == 1, "");
_Static_assert(sizeof(B) == 4, "");
_Static_assert(_Alignof(B) == 2, "");
_Static_assert(sizeof(struct B_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct B_extra_alignment) == 2, "");
_Static_assert(sizeof(struct B_extra_packed) == 4, "");
_Static_assert(_Alignof(struct B_extra_packed) == 1, "");
_Static_assert(sizeof(struct B_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct B_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B_extra_size) == 6, "");
_Static_assert(_Alignof(struct B_extra_size) == 1, "");
_Static_assert(sizeof(C) == 4, "");
_Static_assert(_Alignof(C) == 4, "");
_Static_assert(sizeof(struct C_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct C_extra_alignment) == 4, "");
_Static_assert(sizeof(struct C_extra_packed) == 4, "");
_Static_assert(_Alignof(struct C_extra_packed) == 1, "");
_Static_assert(sizeof(struct C_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct C_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct C_extra_size) == 6, "");
_Static_assert(_Alignof(struct C_extra_size) == 1, "");
_Static_assert(sizeof(D) == 4, "");
_Static_assert(_Alignof(D) == 8, "");
_Static_assert(sizeof(struct D_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct D_extra_alignment) == 8, "");
_Static_assert(sizeof(struct D_extra_packed) == 4, "");
_Static_assert(_Alignof(struct D_extra_packed) == 1, "");
_Static_assert(sizeof(struct D_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct D_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct D_extra_size) == 6, "");
_Static_assert(_Alignof(struct D_extra_size) == 1, "");
_Static_assert(sizeof(E) == 4, "");
_Static_assert(_Alignof(E) == 16, "");
_Static_assert(sizeof(struct E_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct E_extra_alignment) == 16, "");
_Static_assert(sizeof(struct E_extra_packed) == 4, "");
_Static_assert(_Alignof(struct E_extra_packed) == 1, "");
_Static_assert(sizeof(struct E_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct E_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct E_extra_size) == 6, "");
_Static_assert(_Alignof(struct E_extra_size) == 1, "");
_Static_assert(sizeof(F) == 4, "");
_Static_assert(_Alignof(F) == 32, "");
_Static_assert(sizeof(struct F_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct F_extra_alignment) == 32, "");
_Static_assert(sizeof(struct F_extra_packed) == 4, "");
_Static_assert(_Alignof(struct F_extra_packed) == 1, "");
_Static_assert(sizeof(struct F_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct F_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct F_extra_size) == 6, "");
_Static_assert(_Alignof(struct F_extra_size) == 1, "");
_Static_assert(sizeof(G) == 4, "");
_Static_assert(_Alignof(G) == 64, "");
_Static_assert(sizeof(struct G_extra_alignment) == 128, "");
_Static_assert(_Alignof(struct G_extra_alignment) == 64, "");
_Static_assert(sizeof(struct G_extra_packed) == 4, "");
_Static_assert(_Alignof(struct G_extra_packed) == 1, "");
_Static_assert(sizeof(struct G_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct G_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct G_extra_size) == 6, "");
_Static_assert(_Alignof(struct G_extra_size) == 1, "");
_Static_assert(sizeof(H) == 4, "");
_Static_assert(_Alignof(H) == 128, "");
_Static_assert(sizeof(struct H_extra_alignment) == 256, "");
_Static_assert(_Alignof(struct H_extra_alignment) == 128, "");
_Static_assert(sizeof(struct H_extra_packed) == 4, "");
_Static_assert(_Alignof(struct H_extra_packed) == 1, "");
_Static_assert(sizeof(struct H_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct H_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct H_extra_size) == 6, "");
_Static_assert(_Alignof(struct H_extra_size) == 1, "");
_Static_assert(sizeof(AA) == 4, "");
_Static_assert(_Alignof(AA) == 1, "");
_Static_assert(sizeof(struct AA_extra_alignment) == 5, "");
_Static_assert(_Alignof(struct AA_extra_alignment) == 1, "");
_Static_assert(sizeof(struct AA_extra_packed) == 4, "");
_Static_assert(_Alignof(struct AA_extra_packed) == 1, "");
_Static_assert(sizeof(struct AA_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct AA_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct AA_extra_size) == 6, "");
_Static_assert(_Alignof(struct AA_extra_size) == 1, "");
_Static_assert(sizeof(AB) == 4, "");
_Static_assert(_Alignof(AB) == 2, "");
_Static_assert(sizeof(struct AB_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct AB_extra_alignment) == 2, "");
_Static_assert(sizeof(struct AB_extra_packed) == 4, "");
_Static_assert(_Alignof(struct AB_extra_packed) == 1, "");
_Static_assert(sizeof(struct AB_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct AB_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct AB_extra_size) == 6, "");
_Static_assert(_Alignof(struct AB_extra_size) == 1, "");
_Static_assert(sizeof(AC) == 4, "");
_Static_assert(_Alignof(AC) == 4, "");
_Static_assert(sizeof(struct AC_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct AC_extra_alignment) == 4, "");
_Static_assert(sizeof(struct AC_extra_packed) == 4, "");
_Static_assert(_Alignof(struct AC_extra_packed) == 1, "");
_Static_assert(sizeof(struct AC_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct AC_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct AC_extra_size) == 6, "");
_Static_assert(_Alignof(struct AC_extra_size) == 1, "");
_Static_assert(sizeof(AD) == 4, "");
_Static_assert(_Alignof(AD) == 8, "");
_Static_assert(sizeof(struct AD_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct AD_extra_alignment) == 8, "");
_Static_assert(sizeof(struct AD_extra_packed) == 4, "");
_Static_assert(_Alignof(struct AD_extra_packed) == 1, "");
_Static_assert(sizeof(struct AD_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct AD_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct AD_extra_size) == 6, "");
_Static_assert(_Alignof(struct AD_extra_size) == 1, "");
_Static_assert(sizeof(AE) == 4, "");
_Static_assert(_Alignof(AE) == 16, "");
_Static_assert(sizeof(struct AE_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct AE_extra_alignment) == 16, "");
_Static_assert(sizeof(struct AE_extra_packed) == 4, "");
_Static_assert(_Alignof(struct AE_extra_packed) == 1, "");
_Static_assert(sizeof(struct AE_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct AE_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct AE_extra_size) == 6, "");
_Static_assert(_Alignof(struct AE_extra_size) == 1, "");
_Static_assert(sizeof(AF) == 4, "");
_Static_assert(_Alignof(AF) == 32, "");
_Static_assert(sizeof(struct AF_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct AF_extra_alignment) == 32, "");
_Static_assert(sizeof(struct AF_extra_packed) == 4, "");
_Static_assert(_Alignof(struct AF_extra_packed) == 1, "");
_Static_assert(sizeof(struct AF_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct AF_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct AF_extra_size) == 6, "");
_Static_assert(_Alignof(struct AF_extra_size) == 1, "");
_Static_assert(sizeof(AG) == 4, "");
_Static_assert(_Alignof(AG) == 64, "");
_Static_assert(sizeof(struct AG_extra_alignment) == 128, "");
_Static_assert(_Alignof(struct AG_extra_alignment) == 64, "");
_Static_assert(sizeof(struct AG_extra_packed) == 4, "");
_Static_assert(_Alignof(struct AG_extra_packed) == 1, "");
_Static_assert(sizeof(struct AG_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct AG_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct AG_extra_size) == 6, "");
_Static_assert(_Alignof(struct AG_extra_size) == 1, "");
_Static_assert(sizeof(AH) == 4, "");
_Static_assert(_Alignof(AH) == 128, "");
_Static_assert(sizeof(struct AH_extra_alignment) == 256, "");
_Static_assert(_Alignof(struct AH_extra_alignment) == 128, "");
_Static_assert(sizeof(struct AH_extra_packed) == 4, "");
_Static_assert(_Alignof(struct AH_extra_packed) == 1, "");
_Static_assert(sizeof(struct AH_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct AH_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct AH_extra_size) == 6, "");
_Static_assert(_Alignof(struct AH_extra_size) == 1, "");
_Static_assert(sizeof(BA) == 4, "");
_Static_assert(_Alignof(BA) == 1, "");
_Static_assert(sizeof(struct BA_extra_alignment) == 5, "");
_Static_assert(_Alignof(struct BA_extra_alignment) == 1, "");
_Static_assert(sizeof(struct BA_extra_packed) == 4, "");
_Static_assert(_Alignof(struct BA_extra_packed) == 1, "");
_Static_assert(sizeof(struct BA_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct BA_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct BA_extra_size) == 6, "");
_Static_assert(_Alignof(struct BA_extra_size) == 1, "");
_Static_assert(sizeof(BB) == 4, "");
_Static_assert(_Alignof(BB) == 2, "");
_Static_assert(sizeof(struct BB_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct BB_extra_alignment) == 2, "");
_Static_assert(sizeof(struct BB_extra_packed) == 4, "");
_Static_assert(_Alignof(struct BB_extra_packed) == 1, "");
_Static_assert(sizeof(struct BB_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct BB_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct BB_extra_size) == 6, "");
_Static_assert(_Alignof(struct BB_extra_size) == 1, "");
_Static_assert(sizeof(BC) == 4, "");
_Static_assert(_Alignof(BC) == 4, "");
_Static_assert(sizeof(struct BC_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct BC_extra_alignment) == 4, "");
_Static_assert(sizeof(struct BC_extra_packed) == 4, "");
_Static_assert(_Alignof(struct BC_extra_packed) == 1, "");
_Static_assert(sizeof(struct BC_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct BC_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct BC_extra_size) == 6, "");
_Static_assert(_Alignof(struct BC_extra_size) == 1, "");
_Static_assert(sizeof(BD) == 4, "");
_Static_assert(_Alignof(BD) == 8, "");
_Static_assert(sizeof(struct BD_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct BD_extra_alignment) == 8, "");
_Static_assert(sizeof(struct BD_extra_packed) == 4, "");
_Static_assert(_Alignof(struct BD_extra_packed) == 1, "");
_Static_assert(sizeof(struct BD_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct BD_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct BD_extra_size) == 6, "");
_Static_assert(_Alignof(struct BD_extra_size) == 1, "");
_Static_assert(sizeof(BE) == 4, "");
_Static_assert(_Alignof(BE) == 16, "");
_Static_assert(sizeof(struct BE_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct BE_extra_alignment) == 16, "");
_Static_assert(sizeof(struct BE_extra_packed) == 4, "");
_Static_assert(_Alignof(struct BE_extra_packed) == 1, "");
_Static_assert(sizeof(struct BE_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct BE_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct BE_extra_size) == 6, "");
_Static_assert(_Alignof(struct BE_extra_size) == 1, "");
_Static_assert(sizeof(BF) == 4, "");
_Static_assert(_Alignof(BF) == 32, "");
_Static_assert(sizeof(struct BF_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct BF_extra_alignment) == 32, "");
_Static_assert(sizeof(struct BF_extra_packed) == 4, "");
_Static_assert(_Alignof(struct BF_extra_packed) == 1, "");
_Static_assert(sizeof(struct BF_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct BF_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct BF_extra_size) == 6, "");
_Static_assert(_Alignof(struct BF_extra_size) == 1, "");
_Static_assert(sizeof(BG) == 4, "");
_Static_assert(_Alignof(BG) == 64, "");
_Static_assert(sizeof(struct BG_extra_alignment) == 128, "");
_Static_assert(_Alignof(struct BG_extra_alignment) == 64, "");
_Static_assert(sizeof(struct BG_extra_packed) == 4, "");
_Static_assert(_Alignof(struct BG_extra_packed) == 1, "");
_Static_assert(sizeof(struct BG_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct BG_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct BG_extra_size) == 6, "");
_Static_assert(_Alignof(struct BG_extra_size) == 1, "");
_Static_assert(sizeof(BH) == 4, "");
_Static_assert(_Alignof(BH) == 128, "");
_Static_assert(sizeof(struct BH_extra_alignment) == 256, "");
_Static_assert(_Alignof(struct BH_extra_alignment) == 128, "");
_Static_assert(sizeof(struct BH_extra_packed) == 4, "");
_Static_assert(_Alignof(struct BH_extra_packed) == 1, "");
_Static_assert(sizeof(struct BH_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct BH_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct BH_extra_size) == 6, "");
_Static_assert(_Alignof(struct BH_extra_size) == 1, "");
_Static_assert(sizeof(DA) == 4, "");
_Static_assert(_Alignof(DA) == 1, "");
_Static_assert(sizeof(struct DA_extra_alignment) == 5, "");
_Static_assert(_Alignof(struct DA_extra_alignment) == 1, "");
_Static_assert(sizeof(struct DA_extra_packed) == 4, "");
_Static_assert(_Alignof(struct DA_extra_packed) == 1, "");
_Static_assert(sizeof(struct DA_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct DA_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct DA_extra_size) == 6, "");
_Static_assert(_Alignof(struct DA_extra_size) == 1, "");
_Static_assert(sizeof(DB) == 4, "");
_Static_assert(_Alignof(DB) == 2, "");
_Static_assert(sizeof(struct DB_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct DB_extra_alignment) == 2, "");
_Static_assert(sizeof(struct DB_extra_packed) == 4, "");
_Static_assert(_Alignof(struct DB_extra_packed) == 1, "");
_Static_assert(sizeof(struct DB_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct DB_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct DB_extra_size) == 6, "");
_Static_assert(_Alignof(struct DB_extra_size) == 1, "");
_Static_assert(sizeof(DC) == 4, "");
_Static_assert(_Alignof(DC) == 4, "");
_Static_assert(sizeof(struct DC_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct DC_extra_alignment) == 4, "");
_Static_assert(sizeof(struct DC_extra_packed) == 4, "");
_Static_assert(_Alignof(struct DC_extra_packed) == 1, "");
_Static_assert(sizeof(struct DC_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct DC_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct DC_extra_size) == 6, "");
_Static_assert(_Alignof(struct DC_extra_size) == 1, "");
_Static_assert(sizeof(DD) == 4, "");
_Static_assert(_Alignof(DD) == 8, "");
_Static_assert(sizeof(struct DD_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct DD_extra_alignment) == 8, "");
_Static_assert(sizeof(struct DD_extra_packed) == 4, "");
_Static_assert(_Alignof(struct DD_extra_packed) == 1, "");
_Static_assert(sizeof(struct DD_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct DD_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct DD_extra_size) == 6, "");
_Static_assert(_Alignof(struct DD_extra_size) == 1, "");
_Static_assert(sizeof(DE) == 4, "");
_Static_assert(_Alignof(DE) == 16, "");
_Static_assert(sizeof(struct DE_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct DE_extra_alignment) == 16, "");
_Static_assert(sizeof(struct DE_extra_packed) == 4, "");
_Static_assert(_Alignof(struct DE_extra_packed) == 1, "");
_Static_assert(sizeof(struct DE_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct DE_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct DE_extra_size) == 6, "");
_Static_assert(_Alignof(struct DE_extra_size) == 1, "");
_Static_assert(sizeof(DF) == 4, "");
_Static_assert(_Alignof(DF) == 32, "");
_Static_assert(sizeof(struct DF_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct DF_extra_alignment) == 32, "");
_Static_assert(sizeof(struct DF_extra_packed) == 4, "");
_Static_assert(_Alignof(struct DF_extra_packed) == 1, "");
_Static_assert(sizeof(struct DF_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct DF_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct DF_extra_size) == 6, "");
_Static_assert(_Alignof(struct DF_extra_size) == 1, "");
_Static_assert(sizeof(DG) == 4, "");
_Static_assert(_Alignof(DG) == 64, "");
_Static_assert(sizeof(struct DG_extra_alignment) == 128, "");
_Static_assert(_Alignof(struct DG_extra_alignment) == 64, "");
_Static_assert(sizeof(struct DG_extra_packed) == 4, "");
_Static_assert(_Alignof(struct DG_extra_packed) == 1, "");
_Static_assert(sizeof(struct DG_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct DG_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct DG_extra_size) == 6, "");
_Static_assert(_Alignof(struct DG_extra_size) == 1, "");
_Static_assert(sizeof(DH) == 4, "");
_Static_assert(_Alignof(DH) == 128, "");
_Static_assert(sizeof(struct DH_extra_alignment) == 256, "");
_Static_assert(_Alignof(struct DH_extra_alignment) == 128, "");
_Static_assert(sizeof(struct DH_extra_packed) == 4, "");
_Static_assert(_Alignof(struct DH_extra_packed) == 1, "");
_Static_assert(sizeof(struct DH_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct DH_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct DH_extra_size) == 6, "");
_Static_assert(_Alignof(struct DH_extra_size) == 1, "");
// MAPPING|TWO|aarch64-generic-windows-msvc:Msvc|x86-i586-windows-msvc:Msvc|x86-i686-windows-msvc:Msvc|x86-i686-uefi-msvc:Msvc|thumb-baseline-windows-msvc:Msvc|x86_64-x86_64-windows-msvc:Msvc|x86_64-x86_64-uefi-msvc:Msvc|END
// repr targets Aarch64PcWindowsMsvc|Some("aarch64-generic-windows-msvc") I586PcWindowsMsvc|Some("x86-i586-windows-msvc") I686PcWindowsMsvc|Some("x86-i686-windows-msvc") I686UnknownWindows|Some("x86-i686-uefi-msvc") Thumbv7aPcWindowsMsvc|Some("thumb-baseline-windows-msvc") X86_64PcWindowsMsvc|Some("x86_64-x86_64-windows-msvc") X86_64UnknownWindows|Some("x86_64-x86_64-uefi-msvc") 
#elif defined(TWO)
_Static_assert(sizeof(A) == 4, "");
_Static_assert(_Alignof(A) == 4, "");
_Static_assert(sizeof(struct A_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct A_extra_alignment) == 4, "");
_Static_assert(sizeof(struct A_extra_packed) == 4, "");
_Static_assert(_Alignof(struct A_extra_packed) == 1, "");
_Static_assert(sizeof(struct A_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct A_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A_extra_size) == 6, "");
_Static_assert(_Alignof(struct A_extra_size) == 1, "");
_Static_assert(sizeof(B) == 4, "");
_Static_assert(_Alignof(B) == 4, "");
_Static_assert(sizeof(struct B_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct B_extra_alignment) == 4, "");
_Static_assert(sizeof(struct B_extra_packed) == 4, "");
_Static_assert(_Alignof(struct B_extra_packed) == 1, "");
_Static_assert(sizeof(struct B_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct B_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B_extra_size) == 6, "");
_Static_assert(_Alignof(struct B_extra_size) == 1, "");
_Static_assert(sizeof(C) == 4, "");
_Static_assert(_Alignof(C) == 4, "");
_Static_assert(sizeof(struct C_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct C_extra_alignment) == 4, "");
_Static_assert(sizeof(struct C_extra_packed) == 4, "");
_Static_assert(_Alignof(struct C_extra_packed) == 1, "");
_Static_assert(sizeof(struct C_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct C_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct C_extra_size) == 6, "");
_Static_assert(_Alignof(struct C_extra_size) == 1, "");
_Static_assert(sizeof(D) == 4, "");
_Static_assert(_Alignof(D) == 8, "");
_Static_assert(sizeof(struct D_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct D_extra_alignment) == 8, "");
_Static_assert(sizeof(struct D_extra_packed) == 4, "");
_Static_assert(_Alignof(struct D_extra_packed) == 1, "");
_Static_assert(sizeof(struct D_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct D_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct D_extra_size) == 6, "");
_Static_assert(_Alignof(struct D_extra_size) == 1, "");
_Static_assert(sizeof(E) == 4, "");
_Static_assert(_Alignof(E) == 16, "");
_Static_assert(sizeof(struct E_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct E_extra_alignment) == 16, "");
_Static_assert(sizeof(struct E_extra_packed) == 4, "");
_Static_assert(_Alignof(struct E_extra_packed) == 1, "");
_Static_assert(sizeof(struct E_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct E_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct E_extra_size) == 6, "");
_Static_assert(_Alignof(struct E_extra_size) == 1, "");
_Static_assert(sizeof(F) == 4, "");
_Static_assert(_Alignof(F) == 32, "");
_Static_assert(sizeof(struct F_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct F_extra_alignment) == 32, "");
_Static_assert(sizeof(struct F_extra_packed) == 4, "");
_Static_assert(_Alignof(struct F_extra_packed) == 1, "");
_Static_assert(sizeof(struct F_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct F_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct F_extra_size) == 6, "");
_Static_assert(_Alignof(struct F_extra_size) == 1, "");
_Static_assert(sizeof(G) == 4, "");
_Static_assert(_Alignof(G) == 64, "");
_Static_assert(sizeof(struct G_extra_alignment) == 128, "");
_Static_assert(_Alignof(struct G_extra_alignment) == 64, "");
_Static_assert(sizeof(struct G_extra_packed) == 4, "");
_Static_assert(_Alignof(struct G_extra_packed) == 1, "");
_Static_assert(sizeof(struct G_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct G_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct G_extra_size) == 6, "");
_Static_assert(_Alignof(struct G_extra_size) == 1, "");
_Static_assert(sizeof(H) == 4, "");
_Static_assert(_Alignof(H) == 128, "");
_Static_assert(sizeof(struct H_extra_alignment) == 256, "");
_Static_assert(_Alignof(struct H_extra_alignment) == 128, "");
_Static_assert(sizeof(struct H_extra_packed) == 4, "");
_Static_assert(_Alignof(struct H_extra_packed) == 1, "");
_Static_assert(sizeof(struct H_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct H_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct H_extra_size) == 6, "");
_Static_assert(_Alignof(struct H_extra_size) == 1, "");
_Static_assert(sizeof(AA) == 4, "");
_Static_assert(_Alignof(AA) == 4, "");
_Static_assert(sizeof(struct AA_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct AA_extra_alignment) == 4, "");
_Static_assert(sizeof(struct AA_extra_packed) == 4, "");
_Static_assert(_Alignof(struct AA_extra_packed) == 1, "");
_Static_assert(sizeof(struct AA_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct AA_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct AA_extra_size) == 6, "");
_Static_assert(_Alignof(struct AA_extra_size) == 1, "");
_Static_assert(sizeof(AB) == 4, "");
_Static_assert(_Alignof(AB) == 4, "");
_Static_assert(sizeof(struct AB_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct AB_extra_alignment) == 4, "");
_Static_assert(sizeof(struct AB_extra_packed) == 4, "");
_Static_assert(_Alignof(struct AB_extra_packed) == 1, "");
_Static_assert(sizeof(struct AB_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct AB_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct AB_extra_size) == 6, "");
_Static_assert(_Alignof(struct AB_extra_size) == 1, "");
_Static_assert(sizeof(AC) == 4, "");
_Static_assert(_Alignof(AC) == 4, "");
_Static_assert(sizeof(struct AC_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct AC_extra_alignment) == 4, "");
_Static_assert(sizeof(struct AC_extra_packed) == 4, "");
_Static_assert(_Alignof(struct AC_extra_packed) == 1, "");
_Static_assert(sizeof(struct AC_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct AC_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct AC_extra_size) == 6, "");
_Static_assert(_Alignof(struct AC_extra_size) == 1, "");
_Static_assert(sizeof(AD) == 4, "");
_Static_assert(_Alignof(AD) == 8, "");
_Static_assert(sizeof(struct AD_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct AD_extra_alignment) == 8, "");
_Static_assert(sizeof(struct AD_extra_packed) == 4, "");
_Static_assert(_Alignof(struct AD_extra_packed) == 1, "");
_Static_assert(sizeof(struct AD_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct AD_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct AD_extra_size) == 6, "");
_Static_assert(_Alignof(struct AD_extra_size) == 1, "");
_Static_assert(sizeof(AE) == 4, "");
_Static_assert(_Alignof(AE) == 16, "");
_Static_assert(sizeof(struct AE_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct AE_extra_alignment) == 16, "");
_Static_assert(sizeof(struct AE_extra_packed) == 4, "");
_Static_assert(_Alignof(struct AE_extra_packed) == 1, "");
_Static_assert(sizeof(struct AE_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct AE_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct AE_extra_size) == 6, "");
_Static_assert(_Alignof(struct AE_extra_size) == 1, "");
_Static_assert(sizeof(AF) == 4, "");
_Static_assert(_Alignof(AF) == 32, "");
_Static_assert(sizeof(struct AF_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct AF_extra_alignment) == 32, "");
_Static_assert(sizeof(struct AF_extra_packed) == 4, "");
_Static_assert(_Alignof(struct AF_extra_packed) == 1, "");
_Static_assert(sizeof(struct AF_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct AF_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct AF_extra_size) == 6, "");
_Static_assert(_Alignof(struct AF_extra_size) == 1, "");
_Static_assert(sizeof(AG) == 4, "");
_Static_assert(_Alignof(AG) == 64, "");
_Static_assert(sizeof(struct AG_extra_alignment) == 128, "");
_Static_assert(_Alignof(struct AG_extra_alignment) == 64, "");
_Static_assert(sizeof(struct AG_extra_packed) == 4, "");
_Static_assert(_Alignof(struct AG_extra_packed) == 1, "");
_Static_assert(sizeof(struct AG_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct AG_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct AG_extra_size) == 6, "");
_Static_assert(_Alignof(struct AG_extra_size) == 1, "");
_Static_assert(sizeof(AH) == 4, "");
_Static_assert(_Alignof(AH) == 128, "");
_Static_assert(sizeof(struct AH_extra_alignment) == 256, "");
_Static_assert(_Alignof(struct AH_extra_alignment) == 128, "");
_Static_assert(sizeof(struct AH_extra_packed) == 4, "");
_Static_assert(_Alignof(struct AH_extra_packed) == 1, "");
_Static_assert(sizeof(struct AH_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct AH_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct AH_extra_size) == 6, "");
_Static_assert(_Alignof(struct AH_extra_size) == 1, "");
_Static_assert(sizeof(BA) == 4, "");
_Static_assert(_Alignof(BA) == 4, "");
_Static_assert(sizeof(struct BA_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct BA_extra_alignment) == 4, "");
_Static_assert(sizeof(struct BA_extra_packed) == 4, "");
_Static_assert(_Alignof(struct BA_extra_packed) == 1, "");
_Static_assert(sizeof(struct BA_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct BA_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct BA_extra_size) == 6, "");
_Static_assert(_Alignof(struct BA_extra_size) == 1, "");
_Static_assert(sizeof(BB) == 4, "");
_Static_assert(_Alignof(BB) == 4, "");
_Static_assert(sizeof(struct BB_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct BB_extra_alignment) == 4, "");
_Static_assert(sizeof(struct BB_extra_packed) == 4, "");
_Static_assert(_Alignof(struct BB_extra_packed) == 1, "");
_Static_assert(sizeof(struct BB_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct BB_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct BB_extra_size) == 6, "");
_Static_assert(_Alignof(struct BB_extra_size) == 1, "");
_Static_assert(sizeof(BC) == 4, "");
_Static_assert(_Alignof(BC) == 4, "");
_Static_assert(sizeof(struct BC_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct BC_extra_alignment) == 4, "");
_Static_assert(sizeof(struct BC_extra_packed) == 4, "");
_Static_assert(_Alignof(struct BC_extra_packed) == 1, "");
_Static_assert(sizeof(struct BC_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct BC_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct BC_extra_size) == 6, "");
_Static_assert(_Alignof(struct BC_extra_size) == 1, "");
_Static_assert(sizeof(BD) == 4, "");
_Static_assert(_Alignof(BD) == 8, "");
_Static_assert(sizeof(struct BD_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct BD_extra_alignment) == 8, "");
_Static_assert(sizeof(struct BD_extra_packed) == 4, "");
_Static_assert(_Alignof(struct BD_extra_packed) == 1, "");
_Static_assert(sizeof(struct BD_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct BD_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct BD_extra_size) == 6, "");
_Static_assert(_Alignof(struct BD_extra_size) == 1, "");
_Static_assert(sizeof(BE) == 4, "");
_Static_assert(_Alignof(BE) == 16, "");
_Static_assert(sizeof(struct BE_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct BE_extra_alignment) == 16, "");
_Static_assert(sizeof(struct BE_extra_packed) == 4, "");
_Static_assert(_Alignof(struct BE_extra_packed) == 1, "");
_Static_assert(sizeof(struct BE_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct BE_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct BE_extra_size) == 6, "");
_Static_assert(_Alignof(struct BE_extra_size) == 1, "");
_Static_assert(sizeof(BF) == 4, "");
_Static_assert(_Alignof(BF) == 32, "");
_Static_assert(sizeof(struct BF_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct BF_extra_alignment) == 32, "");
_Static_assert(sizeof(struct BF_extra_packed) == 4, "");
_Static_assert(_Alignof(struct BF_extra_packed) == 1, "");
_Static_assert(sizeof(struct BF_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct BF_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct BF_extra_size) == 6, "");
_Static_assert(_Alignof(struct BF_extra_size) == 1, "");
_Static_assert(sizeof(BG) == 4, "");
_Static_assert(_Alignof(BG) == 64, "");
_Static_assert(sizeof(struct BG_extra_alignment) == 128, "");
_Static_assert(_Alignof(struct BG_extra_alignment) == 64, "");
_Static_assert(sizeof(struct BG_extra_packed) == 4, "");
_Static_assert(_Alignof(struct BG_extra_packed) == 1, "");
_Static_assert(sizeof(struct BG_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct BG_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct BG_extra_size) == 6, "");
_Static_assert(_Alignof(struct BG_extra_size) == 1, "");
_Static_assert(sizeof(BH) == 4, "");
_Static_assert(_Alignof(BH) == 128, "");
_Static_assert(sizeof(struct BH_extra_alignment) == 256, "");
_Static_assert(_Alignof(struct BH_extra_alignment) == 128, "");
_Static_assert(sizeof(struct BH_extra_packed) == 4, "");
_Static_assert(_Alignof(struct BH_extra_packed) == 1, "");
_Static_assert(sizeof(struct BH_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct BH_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct BH_extra_size) == 6, "");
_Static_assert(_Alignof(struct BH_extra_size) == 1, "");
_Static_assert(sizeof(DA) == 4, "");
_Static_assert(_Alignof(DA) == 8, "");
_Static_assert(sizeof(struct DA_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct DA_extra_alignment) == 8, "");
_Static_assert(sizeof(struct DA_extra_packed) == 4, "");
_Static_assert(_Alignof(struct DA_extra_packed) == 1, "");
_Static_assert(sizeof(struct DA_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct DA_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct DA_extra_size) == 6, "");
_Static_assert(_Alignof(struct DA_extra_size) == 1, "");
_Static_assert(sizeof(DB) == 4, "");
_Static_assert(_Alignof(DB) == 8, "");
_Static_assert(sizeof(struct DB_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct DB_extra_alignment) == 8, "");
_Static_assert(sizeof(struct DB_extra_packed) == 4, "");
_Static_assert(_Alignof(struct DB_extra_packed) == 1, "");
_Static_assert(sizeof(struct DB_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct DB_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct DB_extra_size) == 6, "");
_Static_assert(_Alignof(struct DB_extra_size) == 1, "");
_Static_assert(sizeof(DC) == 4, "");
_Static_assert(_Alignof(DC) == 8, "");
_Static_assert(sizeof(struct DC_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct DC_extra_alignment) == 8, "");
_Static_assert(sizeof(struct DC_extra_packed) == 4, "");
_Static_assert(_Alignof(struct DC_extra_packed) == 1, "");
_Static_assert(sizeof(struct DC_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct DC_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct DC_extra_size) == 6, "");
_Static_assert(_Alignof(struct DC_extra_size) == 1, "");
_Static_assert(sizeof(DD) == 4, "");
_Static_assert(_Alignof(DD) == 8, "");
_Static_assert(sizeof(struct DD_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct DD_extra_alignment) == 8, "");
_Static_assert(sizeof(struct DD_extra_packed) == 4, "");
_Static_assert(_Alignof(struct DD_extra_packed) == 1, "");
_Static_assert(sizeof(struct DD_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct DD_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct DD_extra_size) == 6, "");
_Static_assert(_Alignof(struct DD_extra_size) == 1, "");
_Static_assert(sizeof(DE) == 4, "");
_Static_assert(_Alignof(DE) == 16, "");
_Static_assert(sizeof(struct DE_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct DE_extra_alignment) == 16, "");
_Static_assert(sizeof(struct DE_extra_packed) == 4, "");
_Static_assert(_Alignof(struct DE_extra_packed) == 1, "");
_Static_assert(sizeof(struct DE_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct DE_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct DE_extra_size) == 6, "");
_Static_assert(_Alignof(struct DE_extra_size) == 1, "");
_Static_assert(sizeof(DF) == 4, "");
_Static_assert(_Alignof(DF) == 32, "");
_Static_assert(sizeof(struct DF_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct DF_extra_alignment) == 32, "");
_Static_assert(sizeof(struct DF_extra_packed) == 4, "");
_Static_assert(_Alignof(struct DF_extra_packed) == 1, "");
_Static_assert(sizeof(struct DF_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct DF_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct DF_extra_size) == 6, "");
_Static_assert(_Alignof(struct DF_extra_size) == 1, "");
_Static_assert(sizeof(DG) == 4, "");
_Static_assert(_Alignof(DG) == 64, "");
_Static_assert(sizeof(struct DG_extra_alignment) == 128, "");
_Static_assert(_Alignof(struct DG_extra_alignment) == 64, "");
_Static_assert(sizeof(struct DG_extra_packed) == 4, "");
_Static_assert(_Alignof(struct DG_extra_packed) == 1, "");
_Static_assert(sizeof(struct DG_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct DG_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct DG_extra_size) == 6, "");
_Static_assert(_Alignof(struct DG_extra_size) == 1, "");
_Static_assert(sizeof(DH) == 4, "");
_Static_assert(_Alignof(DH) == 128, "");
_Static_assert(sizeof(struct DH_extra_alignment) == 256, "");
_Static_assert(_Alignof(struct DH_extra_alignment) == 128, "");
_Static_assert(sizeof(struct DH_extra_packed) == 4, "");
_Static_assert(_Alignof(struct DH_extra_packed) == 1, "");
_Static_assert(sizeof(struct DH_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct DH_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct DH_extra_size) == 6, "");
_Static_assert(_Alignof(struct DH_extra_size) == 1, "");
// MAPPING|THREE|avr-avr2-other-eabi:Gcc|END
// repr targets AvrUnknownUnknown|Some("avr-avr2-other-eabi") 
#elif defined(THREE)
_Static_assert(sizeof(A) == 2, "");
_Static_assert(_Alignof(A) == 1, "");
_Static_assert(sizeof(struct A_extra_alignment) == 3, "");
_Static_assert(_Alignof(struct A_extra_alignment) == 1, "");
_Static_assert(sizeof(struct A_extra_packed) == 2, "");
_Static_assert(_Alignof(struct A_extra_packed) == 1, "");
_Static_assert(sizeof(struct A_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct A_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A_extra_size) == 4, "");
_Static_assert(_Alignof(struct A_extra_size) == 1, "");
_Static_assert(sizeof(B) == 2, "");
_Static_assert(_Alignof(B) == 2, "");
_Static_assert(sizeof(struct B_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct B_extra_alignment) == 2, "");
_Static_assert(sizeof(struct B_extra_packed) == 2, "");
_Static_assert(_Alignof(struct B_extra_packed) == 1, "");
_Static_assert(sizeof(struct B_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct B_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B_extra_size) == 4, "");
_Static_assert(_Alignof(struct B_extra_size) == 1, "");
_Static_assert(sizeof(C) == 2, "");
_Static_assert(_Alignof(C) == 4, "");
_Static_assert(sizeof(struct C_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct C_extra_alignment) == 4, "");
_Static_assert(sizeof(struct C_extra_packed) == 2, "");
_Static_assert(_Alignof(struct C_extra_packed) == 1, "");
_Static_assert(sizeof(struct C_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct C_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct C_extra_size) == 4, "");
_Static_assert(_Alignof(struct C_extra_size) == 1, "");
_Static_assert(sizeof(D) == 2, "");
_Static_assert(_Alignof(D) == 8, "");
_Static_assert(sizeof(struct D_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct D_extra_alignment) == 8, "");
_Static_assert(sizeof(struct D_extra_packed) == 2, "");
_Static_assert(_Alignof(struct D_extra_packed) == 1, "");
_Static_assert(sizeof(struct D_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct D_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct D_extra_size) == 4, "");
_Static_assert(_Alignof(struct D_extra_size) == 1, "");
_Static_assert(sizeof(E) == 2, "");
_Static_assert(_Alignof(E) == 16, "");
_Static_assert(sizeof(struct E_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct E_extra_alignment) == 16, "");
_Static_assert(sizeof(struct E_extra_packed) == 2, "");
_Static_assert(_Alignof(struct E_extra_packed) == 1, "");
_Static_assert(sizeof(struct E_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct E_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct E_extra_size) == 4, "");
_Static_assert(_Alignof(struct E_extra_size) == 1, "");
_Static_assert(sizeof(F) == 2, "");
_Static_assert(_Alignof(F) == 32, "");
_Static_assert(sizeof(struct F_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct F_extra_alignment) == 32, "");
_Static_assert(sizeof(struct F_extra_packed) == 2, "");
_Static_assert(_Alignof(struct F_extra_packed) == 1, "");
_Static_assert(sizeof(struct F_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct F_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct F_extra_size) == 4, "");
_Static_assert(_Alignof(struct F_extra_size) == 1, "");
_Static_assert(sizeof(G) == 2, "");
_Static_assert(_Alignof(G) == 64, "");
_Static_assert(sizeof(struct G_extra_alignment) == 128, "");
_Static_assert(_Alignof(struct G_extra_alignment) == 64, "");
_Static_assert(sizeof(struct G_extra_packed) == 2, "");
_Static_assert(_Alignof(struct G_extra_packed) == 1, "");
_Static_assert(sizeof(struct G_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct G_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct G_extra_size) == 4, "");
_Static_assert(_Alignof(struct G_extra_size) == 1, "");
_Static_assert(sizeof(H) == 2, "");
_Static_assert(_Alignof(H) == 128, "");
_Static_assert(sizeof(struct H_extra_alignment) == 256, "");
_Static_assert(_Alignof(struct H_extra_alignment) == 128, "");
_Static_assert(sizeof(struct H_extra_packed) == 2, "");
_Static_assert(_Alignof(struct H_extra_packed) == 1, "");
_Static_assert(sizeof(struct H_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct H_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct H_extra_size) == 4, "");
_Static_assert(_Alignof(struct H_extra_size) == 1, "");
_Static_assert(sizeof(AA) == 2, "");
_Static_assert(_Alignof(AA) == 1, "");
_Static_assert(sizeof(struct AA_extra_alignment) == 3, "");
_Static_assert(_Alignof(struct AA_extra_alignment) == 1, "");
_Static_assert(sizeof(struct AA_extra_packed) == 2, "");
_Static_assert(_Alignof(struct AA_extra_packed) == 1, "");
_Static_assert(sizeof(struct AA_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct AA_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct AA_extra_size) == 4, "");
_Static_assert(_Alignof(struct AA_extra_size) == 1, "");
_Static_assert(sizeof(AB) == 2, "");
_Static_assert(_Alignof(AB) == 2, "");
_Static_assert(sizeof(struct AB_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct AB_extra_alignment) == 2, "");
_Static_assert(sizeof(struct AB_extra_packed) == 2, "");
_Static_assert(_Alignof(struct AB_extra_packed) == 1, "");
_Static_assert(sizeof(struct AB_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct AB_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct AB_extra_size) == 4, "");
_Static_assert(_Alignof(struct AB_extra_size) == 1, "");
_Static_assert(sizeof(AC) == 2, "");
_Static_assert(_Alignof(AC) == 4, "");
_Static_assert(sizeof(struct AC_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct AC_extra_alignment) == 4, "");
_Static_assert(sizeof(struct AC_extra_packed) == 2, "");
_Static_assert(_Alignof(struct AC_extra_packed) == 1, "");
_Static_assert(sizeof(struct AC_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct AC_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct AC_extra_size) == 4, "");
_Static_assert(_Alignof(struct AC_extra_size) == 1, "");
_Static_assert(sizeof(AD) == 2, "");
_Static_assert(_Alignof(AD) == 8, "");
_Static_assert(sizeof(struct AD_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct AD_extra_alignment) == 8, "");
_Static_assert(sizeof(struct AD_extra_packed) == 2, "");
_Static_assert(_Alignof(struct AD_extra_packed) == 1, "");
_Static_assert(sizeof(struct AD_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct AD_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct AD_extra_size) == 4, "");
_Static_assert(_Alignof(struct AD_extra_size) == 1, "");
_Static_assert(sizeof(AE) == 2, "");
_Static_assert(_Alignof(AE) == 16, "");
_Static_assert(sizeof(struct AE_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct AE_extra_alignment) == 16, "");
_Static_assert(sizeof(struct AE_extra_packed) == 2, "");
_Static_assert(_Alignof(struct AE_extra_packed) == 1, "");
_Static_assert(sizeof(struct AE_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct AE_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct AE_extra_size) == 4, "");
_Static_assert(_Alignof(struct AE_extra_size) == 1, "");
_Static_assert(sizeof(AF) == 2, "");
_Static_assert(_Alignof(AF) == 32, "");
_Static_assert(sizeof(struct AF_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct AF_extra_alignment) == 32, "");
_Static_assert(sizeof(struct AF_extra_packed) == 2, "");
_Static_assert(_Alignof(struct AF_extra_packed) == 1, "");
_Static_assert(sizeof(struct AF_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct AF_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct AF_extra_size) == 4, "");
_Static_assert(_Alignof(struct AF_extra_size) == 1, "");
_Static_assert(sizeof(AG) == 2, "");
_Static_assert(_Alignof(AG) == 64, "");
_Static_assert(sizeof(struct AG_extra_alignment) == 128, "");
_Static_assert(_Alignof(struct AG_extra_alignment) == 64, "");
_Static_assert(sizeof(struct AG_extra_packed) == 2, "");
_Static_assert(_Alignof(struct AG_extra_packed) == 1, "");
_Static_assert(sizeof(struct AG_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct AG_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct AG_extra_size) == 4, "");
_Static_assert(_Alignof(struct AG_extra_size) == 1, "");
_Static_assert(sizeof(AH) == 2, "");
_Static_assert(_Alignof(AH) == 128, "");
_Static_assert(sizeof(struct AH_extra_alignment) == 256, "");
_Static_assert(_Alignof(struct AH_extra_alignment) == 128, "");
_Static_assert(sizeof(struct AH_extra_packed) == 2, "");
_Static_assert(_Alignof(struct AH_extra_packed) == 1, "");
_Static_assert(sizeof(struct AH_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct AH_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct AH_extra_size) == 4, "");
_Static_assert(_Alignof(struct AH_extra_size) == 1, "");
_Static_assert(sizeof(BA) == 2, "");
_Static_assert(_Alignof(BA) == 1, "");
_Static_assert(sizeof(struct BA_extra_alignment) == 3, "");
_Static_assert(_Alignof(struct BA_extra_alignment) == 1, "");
_Static_assert(sizeof(struct BA_extra_packed) == 2, "");
_Static_assert(_Alignof(struct BA_extra_packed) == 1, "");
_Static_assert(sizeof(struct BA_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct BA_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct BA_extra_size) == 4, "");
_Static_assert(_Alignof(struct BA_extra_size) == 1, "");
_Static_assert(sizeof(BB) == 2, "");
_Static_assert(_Alignof(BB) == 2, "");
_Static_assert(sizeof(struct BB_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct BB_extra_alignment) == 2, "");
_Static_assert(sizeof(struct BB_extra_packed) == 2, "");
_Static_assert(_Alignof(struct BB_extra_packed) == 1, "");
_Static_assert(sizeof(struct BB_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct BB_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct BB_extra_size) == 4, "");
_Static_assert(_Alignof(struct BB_extra_size) == 1, "");
_Static_assert(sizeof(BC) == 2, "");
_Static_assert(_Alignof(BC) == 4, "");
_Static_assert(sizeof(struct BC_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct BC_extra_alignment) == 4, "");
_Static_assert(sizeof(struct BC_extra_packed) == 2, "");
_Static_assert(_Alignof(struct BC_extra_packed) == 1, "");
_Static_assert(sizeof(struct BC_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct BC_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct BC_extra_size) == 4, "");
_Static_assert(_Alignof(struct BC_extra_size) == 1, "");
_Static_assert(sizeof(BD) == 2, "");
_Static_assert(_Alignof(BD) == 8, "");
_Static_assert(sizeof(struct BD_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct BD_extra_alignment) == 8, "");
_Static_assert(sizeof(struct BD_extra_packed) == 2, "");
_Static_assert(_Alignof(struct BD_extra_packed) == 1, "");
_Static_assert(sizeof(struct BD_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct BD_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct BD_extra_size) == 4, "");
_Static_assert(_Alignof(struct BD_extra_size) == 1, "");
_Static_assert(sizeof(BE) == 2, "");
_Static_assert(_Alignof(BE) == 16, "");
_Static_assert(sizeof(struct BE_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct BE_extra_alignment) == 16, "");
_Static_assert(sizeof(struct BE_extra_packed) == 2, "");
_Static_assert(_Alignof(struct BE_extra_packed) == 1, "");
_Static_assert(sizeof(struct BE_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct BE_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct BE_extra_size) == 4, "");
_Static_assert(_Alignof(struct BE_extra_size) == 1, "");
_Static_assert(sizeof(BF) == 2, "");
_Static_assert(_Alignof(BF) == 32, "");
_Static_assert(sizeof(struct BF_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct BF_extra_alignment) == 32, "");
_Static_assert(sizeof(struct BF_extra_packed) == 2, "");
_Static_assert(_Alignof(struct BF_extra_packed) == 1, "");
_Static_assert(sizeof(struct BF_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct BF_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct BF_extra_size) == 4, "");
_Static_assert(_Alignof(struct BF_extra_size) == 1, "");
_Static_assert(sizeof(BG) == 2, "");
_Static_assert(_Alignof(BG) == 64, "");
_Static_assert(sizeof(struct BG_extra_alignment) == 128, "");
_Static_assert(_Alignof(struct BG_extra_alignment) == 64, "");
_Static_assert(sizeof(struct BG_extra_packed) == 2, "");
_Static_assert(_Alignof(struct BG_extra_packed) == 1, "");
_Static_assert(sizeof(struct BG_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct BG_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct BG_extra_size) == 4, "");
_Static_assert(_Alignof(struct BG_extra_size) == 1, "");
_Static_assert(sizeof(BH) == 2, "");
_Static_assert(_Alignof(BH) == 128, "");
_Static_assert(sizeof(struct BH_extra_alignment) == 256, "");
_Static_assert(_Alignof(struct BH_extra_alignment) == 128, "");
_Static_assert(sizeof(struct BH_extra_packed) == 2, "");
_Static_assert(_Alignof(struct BH_extra_packed) == 1, "");
_Static_assert(sizeof(struct BH_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct BH_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct BH_extra_size) == 4, "");
_Static_assert(_Alignof(struct BH_extra_size) == 1, "");
_Static_assert(sizeof(DA) == 2, "");
_Static_assert(_Alignof(DA) == 1, "");
_Static_assert(sizeof(struct DA_extra_alignment) == 3, "");
_Static_assert(_Alignof(struct DA_extra_alignment) == 1, "");
_Static_assert(sizeof(struct DA_extra_packed) == 2, "");
_Static_assert(_Alignof(struct DA_extra_packed) == 1, "");
_Static_assert(sizeof(struct DA_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct DA_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct DA_extra_size) == 4, "");
_Static_assert(_Alignof(struct DA_extra_size) == 1, "");
_Static_assert(sizeof(DB) == 2, "");
_Static_assert(_Alignof(DB) == 2, "");
_Static_assert(sizeof(struct DB_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct DB_extra_alignment) == 2, "");
_Static_assert(sizeof(struct DB_extra_packed) == 2, "");
_Static_assert(_Alignof(struct DB_extra_packed) == 1, "");
_Static_assert(sizeof(struct DB_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct DB_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct DB_extra_size) == 4, "");
_Static_assert(_Alignof(struct DB_extra_size) == 1, "");
_Static_assert(sizeof(DC) == 2, "");
_Static_assert(_Alignof(DC) == 4, "");
_Static_assert(sizeof(struct DC_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct DC_extra_alignment) == 4, "");
_Static_assert(sizeof(struct DC_extra_packed) == 2, "");
_Static_assert(_Alignof(struct DC_extra_packed) == 1, "");
_Static_assert(sizeof(struct DC_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct DC_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct DC_extra_size) == 4, "");
_Static_assert(_Alignof(struct DC_extra_size) == 1, "");
_Static_assert(sizeof(DD) == 2, "");
_Static_assert(_Alignof(DD) == 8, "");
_Static_assert(sizeof(struct DD_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct DD_extra_alignment) == 8, "");
_Static_assert(sizeof(struct DD_extra_packed) == 2, "");
_Static_assert(_Alignof(struct DD_extra_packed) == 1, "");
_Static_assert(sizeof(struct DD_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct DD_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct DD_extra_size) == 4, "");
_Static_assert(_Alignof(struct DD_extra_size) == 1, "");
_Static_assert(sizeof(DE) == 2, "");
_Static_assert(_Alignof(DE) == 16, "");
_Static_assert(sizeof(struct DE_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct DE_extra_alignment) == 16, "");
_Static_assert(sizeof(struct DE_extra_packed) == 2, "");
_Static_assert(_Alignof(struct DE_extra_packed) == 1, "");
_Static_assert(sizeof(struct DE_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct DE_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct DE_extra_size) == 4, "");
_Static_assert(_Alignof(struct DE_extra_size) == 1, "");
_Static_assert(sizeof(DF) == 2, "");
_Static_assert(_Alignof(DF) == 32, "");
_Static_assert(sizeof(struct DF_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct DF_extra_alignment) == 32, "");
_Static_assert(sizeof(struct DF_extra_packed) == 2, "");
_Static_assert(_Alignof(struct DF_extra_packed) == 1, "");
_Static_assert(sizeof(struct DF_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct DF_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct DF_extra_size) == 4, "");
_Static_assert(_Alignof(struct DF_extra_size) == 1, "");
_Static_assert(sizeof(DG) == 2, "");
_Static_assert(_Alignof(DG) == 64, "");
_Static_assert(sizeof(struct DG_extra_alignment) == 128, "");
_Static_assert(_Alignof(struct DG_extra_alignment) == 64, "");
_Static_assert(sizeof(struct DG_extra_packed) == 2, "");
_Static_assert(_Alignof(struct DG_extra_packed) == 1, "");
_Static_assert(sizeof(struct DG_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct DG_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct DG_extra_size) == 4, "");
_Static_assert(_Alignof(struct DG_extra_size) == 1, "");
_Static_assert(sizeof(DH) == 2, "");
_Static_assert(_Alignof(DH) == 128, "");
_Static_assert(sizeof(struct DH_extra_alignment) == 256, "");
_Static_assert(_Alignof(struct DH_extra_alignment) == 128, "");
_Static_assert(sizeof(struct DH_extra_packed) == 2, "");
_Static_assert(_Alignof(struct DH_extra_packed) == 1, "");
_Static_assert(sizeof(struct DH_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct DH_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct DH_extra_size) == 4, "");
_Static_assert(_Alignof(struct DH_extra_size) == 1, "");
// MAPPING|FOUR|msp430-msp430-other-eabi:Clang|END
// repr targets Msp430NoneElf|Some("msp430-msp430-other-eabi") 
#elif defined(FOUR)
_Static_assert(sizeof(A) == 2, "");
_Static_assert(_Alignof(A) == 1, "");
_Static_assert(sizeof(struct A_extra_alignment) == 3, "");
_Static_assert(_Alignof(struct A_extra_alignment) == 1, "");
_Static_assert(sizeof(struct A_extra_packed) == 2, "");
_Static_assert(_Alignof(struct A_extra_packed) == 1, "");
_Static_assert(sizeof(struct A_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct A_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A_extra_size) == 4, "");
_Static_assert(_Alignof(struct A_extra_size) == 1, "");
_Static_assert(sizeof(B) == 2, "");
_Static_assert(_Alignof(B) == 2, "");
_Static_assert(sizeof(struct B_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct B_extra_alignment) == 2, "");
_Static_assert(sizeof(struct B_extra_packed) == 2, "");
_Static_assert(_Alignof(struct B_extra_packed) == 1, "");
_Static_assert(sizeof(struct B_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct B_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B_extra_size) == 4, "");
_Static_assert(_Alignof(struct B_extra_size) == 1, "");
_Static_assert(sizeof(C) == 2, "");
_Static_assert(_Alignof(C) == 4, "");
_Static_assert(sizeof(struct C_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct C_extra_alignment) == 4, "");
_Static_assert(sizeof(struct C_extra_packed) == 2, "");
_Static_assert(_Alignof(struct C_extra_packed) == 1, "");
_Static_assert(sizeof(struct C_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct C_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct C_extra_size) == 4, "");
_Static_assert(_Alignof(struct C_extra_size) == 1, "");
_Static_assert(sizeof(D) == 2, "");
_Static_assert(_Alignof(D) == 8, "");
_Static_assert(sizeof(struct D_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct D_extra_alignment) == 8, "");
_Static_assert(sizeof(struct D_extra_packed) == 2, "");
_Static_assert(_Alignof(struct D_extra_packed) == 1, "");
_Static_assert(sizeof(struct D_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct D_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct D_extra_size) == 4, "");
_Static_assert(_Alignof(struct D_extra_size) == 1, "");
_Static_assert(sizeof(E) == 2, "");
_Static_assert(_Alignof(E) == 16, "");
_Static_assert(sizeof(struct E_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct E_extra_alignment) == 16, "");
_Static_assert(sizeof(struct E_extra_packed) == 2, "");
_Static_assert(_Alignof(struct E_extra_packed) == 1, "");
_Static_assert(sizeof(struct E_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct E_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct E_extra_size) == 4, "");
_Static_assert(_Alignof(struct E_extra_size) == 1, "");
_Static_assert(sizeof(F) == 2, "");
_Static_assert(_Alignof(F) == 32, "");
_Static_assert(sizeof(struct F_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct F_extra_alignment) == 32, "");
_Static_assert(sizeof(struct F_extra_packed) == 2, "");
_Static_assert(_Alignof(struct F_extra_packed) == 1, "");
_Static_assert(sizeof(struct F_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct F_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct F_extra_size) == 4, "");
_Static_assert(_Alignof(struct F_extra_size) == 1, "");
_Static_assert(sizeof(G) == 2, "");
_Static_assert(_Alignof(G) == 64, "");
_Static_assert(sizeof(struct G_extra_alignment) == 128, "");
_Static_assert(_Alignof(struct G_extra_alignment) == 64, "");
_Static_assert(sizeof(struct G_extra_packed) == 2, "");
_Static_assert(_Alignof(struct G_extra_packed) == 1, "");
_Static_assert(sizeof(struct G_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct G_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct G_extra_size) == 4, "");
_Static_assert(_Alignof(struct G_extra_size) == 1, "");
_Static_assert(sizeof(H) == 2, "");
_Static_assert(_Alignof(H) == 128, "");
_Static_assert(sizeof(struct H_extra_alignment) == 256, "");
_Static_assert(_Alignof(struct H_extra_alignment) == 128, "");
_Static_assert(sizeof(struct H_extra_packed) == 2, "");
_Static_assert(_Alignof(struct H_extra_packed) == 1, "");
_Static_assert(sizeof(struct H_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct H_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct H_extra_size) == 4, "");
_Static_assert(_Alignof(struct H_extra_size) == 1, "");
_Static_assert(sizeof(AA) == 2, "");
_Static_assert(_Alignof(AA) == 1, "");
_Static_assert(sizeof(struct AA_extra_alignment) == 3, "");
_Static_assert(_Alignof(struct AA_extra_alignment) == 1, "");
_Static_assert(sizeof(struct AA_extra_packed) == 2, "");
_Static_assert(_Alignof(struct AA_extra_packed) == 1, "");
_Static_assert(sizeof(struct AA_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct AA_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct AA_extra_size) == 4, "");
_Static_assert(_Alignof(struct AA_extra_size) == 1, "");
_Static_assert(sizeof(AB) == 2, "");
_Static_assert(_Alignof(AB) == 2, "");
_Static_assert(sizeof(struct AB_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct AB_extra_alignment) == 2, "");
_Static_assert(sizeof(struct AB_extra_packed) == 2, "");
_Static_assert(_Alignof(struct AB_extra_packed) == 1, "");
_Static_assert(sizeof(struct AB_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct AB_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct AB_extra_size) == 4, "");
_Static_assert(_Alignof(struct AB_extra_size) == 1, "");
_Static_assert(sizeof(AC) == 2, "");
_Static_assert(_Alignof(AC) == 4, "");
_Static_assert(sizeof(struct AC_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct AC_extra_alignment) == 4, "");
_Static_assert(sizeof(struct AC_extra_packed) == 2, "");
_Static_assert(_Alignof(struct AC_extra_packed) == 1, "");
_Static_assert(sizeof(struct AC_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct AC_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct AC_extra_size) == 4, "");
_Static_assert(_Alignof(struct AC_extra_size) == 1, "");
_Static_assert(sizeof(AD) == 2, "");
_Static_assert(_Alignof(AD) == 8, "");
_Static_assert(sizeof(struct AD_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct AD_extra_alignment) == 8, "");
_Static_assert(sizeof(struct AD_extra_packed) == 2, "");
_Static_assert(_Alignof(struct AD_extra_packed) == 1, "");
_Static_assert(sizeof(struct AD_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct AD_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct AD_extra_size) == 4, "");
_Static_assert(_Alignof(struct AD_extra_size) == 1, "");
_Static_assert(sizeof(AE) == 2, "");
_Static_assert(_Alignof(AE) == 16, "");
_Static_assert(sizeof(struct AE_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct AE_extra_alignment) == 16, "");
_Static_assert(sizeof(struct AE_extra_packed) == 2, "");
_Static_assert(_Alignof(struct AE_extra_packed) == 1, "");
_Static_assert(sizeof(struct AE_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct AE_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct AE_extra_size) == 4, "");
_Static_assert(_Alignof(struct AE_extra_size) == 1, "");
_Static_assert(sizeof(AF) == 2, "");
_Static_assert(_Alignof(AF) == 32, "");
_Static_assert(sizeof(struct AF_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct AF_extra_alignment) == 32, "");
_Static_assert(sizeof(struct AF_extra_packed) == 2, "");
_Static_assert(_Alignof(struct AF_extra_packed) == 1, "");
_Static_assert(sizeof(struct AF_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct AF_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct AF_extra_size) == 4, "");
_Static_assert(_Alignof(struct AF_extra_size) == 1, "");
_Static_assert(sizeof(AG) == 2, "");
_Static_assert(_Alignof(AG) == 64, "");
_Static_assert(sizeof(struct AG_extra_alignment) == 128, "");
_Static_assert(_Alignof(struct AG_extra_alignment) == 64, "");
_Static_assert(sizeof(struct AG_extra_packed) == 2, "");
_Static_assert(_Alignof(struct AG_extra_packed) == 1, "");
_Static_assert(sizeof(struct AG_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct AG_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct AG_extra_size) == 4, "");
_Static_assert(_Alignof(struct AG_extra_size) == 1, "");
_Static_assert(sizeof(AH) == 2, "");
_Static_assert(_Alignof(AH) == 128, "");
_Static_assert(sizeof(struct AH_extra_alignment) == 256, "");
_Static_assert(_Alignof(struct AH_extra_alignment) == 128, "");
_Static_assert(sizeof(struct AH_extra_packed) == 2, "");
_Static_assert(_Alignof(struct AH_extra_packed) == 1, "");
_Static_assert(sizeof(struct AH_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct AH_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct AH_extra_size) == 4, "");
_Static_assert(_Alignof(struct AH_extra_size) == 1, "");
_Static_assert(sizeof(BA) == 2, "");
_Static_assert(_Alignof(BA) == 1, "");
_Static_assert(sizeof(struct BA_extra_alignment) == 3, "");
_Static_assert(_Alignof(struct BA_extra_alignment) == 1, "");
_Static_assert(sizeof(struct BA_extra_packed) == 2, "");
_Static_assert(_Alignof(struct BA_extra_packed) == 1, "");
_Static_assert(sizeof(struct BA_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct BA_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct BA_extra_size) == 4, "");
_Static_assert(_Alignof(struct BA_extra_size) == 1, "");
_Static_assert(sizeof(BB) == 2, "");
_Static_assert(_Alignof(BB) == 2, "");
_Static_assert(sizeof(struct BB_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct BB_extra_alignment) == 2, "");
_Static_assert(sizeof(struct BB_extra_packed) == 2, "");
_Static_assert(_Alignof(struct BB_extra_packed) == 1, "");
_Static_assert(sizeof(struct BB_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct BB_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct BB_extra_size) == 4, "");
_Static_assert(_Alignof(struct BB_extra_size) == 1, "");
_Static_assert(sizeof(BC) == 2, "");
_Static_assert(_Alignof(BC) == 4, "");
_Static_assert(sizeof(struct BC_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct BC_extra_alignment) == 4, "");
_Static_assert(sizeof(struct BC_extra_packed) == 2, "");
_Static_assert(_Alignof(struct BC_extra_packed) == 1, "");
_Static_assert(sizeof(struct BC_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct BC_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct BC_extra_size) == 4, "");
_Static_assert(_Alignof(struct BC_extra_size) == 1, "");
_Static_assert(sizeof(BD) == 2, "");
_Static_assert(_Alignof(BD) == 8, "");
_Static_assert(sizeof(struct BD_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct BD_extra_alignment) == 8, "");
_Static_assert(sizeof(struct BD_extra_packed) == 2, "");
_Static_assert(_Alignof(struct BD_extra_packed) == 1, "");
_Static_assert(sizeof(struct BD_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct BD_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct BD_extra_size) == 4, "");
_Static_assert(_Alignof(struct BD_extra_size) == 1, "");
_Static_assert(sizeof(BE) == 2, "");
_Static_assert(_Alignof(BE) == 16, "");
_Static_assert(sizeof(struct BE_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct BE_extra_alignment) == 16, "");
_Static_assert(sizeof(struct BE_extra_packed) == 2, "");
_Static_assert(_Alignof(struct BE_extra_packed) == 1, "");
_Static_assert(sizeof(struct BE_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct BE_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct BE_extra_size) == 4, "");
_Static_assert(_Alignof(struct BE_extra_size) == 1, "");
_Static_assert(sizeof(BF) == 2, "");
_Static_assert(_Alignof(BF) == 32, "");
_Static_assert(sizeof(struct BF_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct BF_extra_alignment) == 32, "");
_Static_assert(sizeof(struct BF_extra_packed) == 2, "");
_Static_assert(_Alignof(struct BF_extra_packed) == 1, "");
_Static_assert(sizeof(struct BF_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct BF_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct BF_extra_size) == 4, "");
_Static_assert(_Alignof(struct BF_extra_size) == 1, "");
_Static_assert(sizeof(BG) == 2, "");
_Static_assert(_Alignof(BG) == 64, "");
_Static_assert(sizeof(struct BG_extra_alignment) == 128, "");
_Static_assert(_Alignof(struct BG_extra_alignment) == 64, "");
_Static_assert(sizeof(struct BG_extra_packed) == 2, "");
_Static_assert(_Alignof(struct BG_extra_packed) == 1, "");
_Static_assert(sizeof(struct BG_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct BG_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct BG_extra_size) == 4, "");
_Static_assert(_Alignof(struct BG_extra_size) == 1, "");
_Static_assert(sizeof(BH) == 2, "");
_Static_assert(_Alignof(BH) == 128, "");
_Static_assert(sizeof(struct BH_extra_alignment) == 256, "");
_Static_assert(_Alignof(struct BH_extra_alignment) == 128, "");
_Static_assert(sizeof(struct BH_extra_packed) == 2, "");
_Static_assert(_Alignof(struct BH_extra_packed) == 1, "");
_Static_assert(sizeof(struct BH_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct BH_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct BH_extra_size) == 4, "");
_Static_assert(_Alignof(struct BH_extra_size) == 1, "");
_Static_assert(sizeof(DA) == 2, "");
_Static_assert(_Alignof(DA) == 1, "");
_Static_assert(sizeof(struct DA_extra_alignment) == 3, "");
_Static_assert(_Alignof(struct DA_extra_alignment) == 1, "");
_Static_assert(sizeof(struct DA_extra_packed) == 2, "");
_Static_assert(_Alignof(struct DA_extra_packed) == 1, "");
_Static_assert(sizeof(struct DA_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct DA_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct DA_extra_size) == 4, "");
_Static_assert(_Alignof(struct DA_extra_size) == 1, "");
_Static_assert(sizeof(DB) == 2, "");
_Static_assert(_Alignof(DB) == 2, "");
_Static_assert(sizeof(struct DB_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct DB_extra_alignment) == 2, "");
_Static_assert(sizeof(struct DB_extra_packed) == 2, "");
_Static_assert(_Alignof(struct DB_extra_packed) == 1, "");
_Static_assert(sizeof(struct DB_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct DB_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct DB_extra_size) == 4, "");
_Static_assert(_Alignof(struct DB_extra_size) == 1, "");
_Static_assert(sizeof(DC) == 2, "");
_Static_assert(_Alignof(DC) == 4, "");
_Static_assert(sizeof(struct DC_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct DC_extra_alignment) == 4, "");
_Static_assert(sizeof(struct DC_extra_packed) == 2, "");
_Static_assert(_Alignof(struct DC_extra_packed) == 1, "");
_Static_assert(sizeof(struct DC_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct DC_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct DC_extra_size) == 4, "");
_Static_assert(_Alignof(struct DC_extra_size) == 1, "");
_Static_assert(sizeof(DD) == 2, "");
_Static_assert(_Alignof(DD) == 8, "");
_Static_assert(sizeof(struct DD_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct DD_extra_alignment) == 8, "");
_Static_assert(sizeof(struct DD_extra_packed) == 2, "");
_Static_assert(_Alignof(struct DD_extra_packed) == 1, "");
_Static_assert(sizeof(struct DD_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct DD_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct DD_extra_size) == 4, "");
_Static_assert(_Alignof(struct DD_extra_size) == 1, "");
_Static_assert(sizeof(DE) == 2, "");
_Static_assert(_Alignof(DE) == 16, "");
_Static_assert(sizeof(struct DE_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct DE_extra_alignment) == 16, "");
_Static_assert(sizeof(struct DE_extra_packed) == 2, "");
_Static_assert(_Alignof(struct DE_extra_packed) == 1, "");
_Static_assert(sizeof(struct DE_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct DE_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct DE_extra_size) == 4, "");
_Static_assert(_Alignof(struct DE_extra_size) == 1, "");
_Static_assert(sizeof(DF) == 2, "");
_Static_assert(_Alignof(DF) == 32, "");
_Static_assert(sizeof(struct DF_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct DF_extra_alignment) == 32, "");
_Static_assert(sizeof(struct DF_extra_packed) == 2, "");
_Static_assert(_Alignof(struct DF_extra_packed) == 1, "");
_Static_assert(sizeof(struct DF_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct DF_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct DF_extra_size) == 4, "");
_Static_assert(_Alignof(struct DF_extra_size) == 1, "");
_Static_assert(sizeof(DG) == 2, "");
_Static_assert(_Alignof(DG) == 64, "");
_Static_assert(sizeof(struct DG_extra_alignment) == 128, "");
_Static_assert(_Alignof(struct DG_extra_alignment) == 64, "");
_Static_assert(sizeof(struct DG_extra_packed) == 2, "");
_Static_assert(_Alignof(struct DG_extra_packed) == 1, "");
_Static_assert(sizeof(struct DG_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct DG_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct DG_extra_size) == 4, "");
_Static_assert(_Alignof(struct DG_extra_size) == 1, "");
_Static_assert(sizeof(DH) == 2, "");
_Static_assert(_Alignof(DH) == 128, "");
_Static_assert(sizeof(struct DH_extra_alignment) == 256, "");
_Static_assert(_Alignof(struct DH_extra_alignment) == 128, "");
_Static_assert(sizeof(struct DH_extra_packed) == 2, "");
_Static_assert(_Alignof(struct DH_extra_packed) == 1, "");
_Static_assert(sizeof(struct DH_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct DH_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct DH_extra_size) == 4, "");
_Static_assert(_Alignof(struct DH_extra_size) == 1, "");
#endif
