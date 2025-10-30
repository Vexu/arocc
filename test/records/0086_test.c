// SPDX-License-Identifier: GPL-3.0-or-later

// This test file is auto-generated. do not edit.
// This file is a derivative work from the test files found
// in this repo : https://github.com/mahkoh/repr-c
// and is under the same licence as the original work.

typedef struct {
    char c;
    int i __attribute__((aligned(32)));
} A000;
A000 var1;
struct A000_extra_alignment {
    char a;
    A000 b;
};
struct A000_extra_alignment var2;
#pragma pack(1)
struct A000_extra_packed {
    A000 a;
};
#pragma pack()
struct A000_extra_required_alignment {
    char a;
    struct A000_extra_packed b;
};
struct A000_extra_required_alignment var3;
struct A000_extra_size {
    char a[sizeof(A000)+1];
    char b;
};
struct A000_extra_size var4;

typedef struct {
    char c;
    int i __attribute__((aligned(32)));
} __attribute__((packed)) A001;
A001 var5;
struct A001_extra_alignment {
    char a;
    A001 b;
};
struct A001_extra_alignment var6;
#pragma pack(1)
struct A001_extra_packed {
    A001 a;
};
#pragma pack()
struct A001_extra_required_alignment {
    char a;
    struct A001_extra_packed b;
};
struct A001_extra_required_alignment var7;
struct A001_extra_size {
    char a[sizeof(A001)+1];
    char b;
};
struct A001_extra_size var8;

typedef struct {
    char c;
    int i __attribute__((aligned(32))) __attribute__((packed));
} A002;
A002 var9;
struct A002_extra_alignment {
    char a;
    A002 b;
};
struct A002_extra_alignment var10;
#pragma pack(1)
struct A002_extra_packed {
    A002 a;
};
#pragma pack()
struct A002_extra_required_alignment {
    char a;
    struct A002_extra_packed b;
};
struct A002_extra_required_alignment var11;
struct A002_extra_size {
    char a[sizeof(A002)+1];
    char b;
};
struct A002_extra_size var12;

typedef struct {
    char c;
    int i __attribute__((aligned(32))) __attribute__((packed));
} __attribute__((packed)) A003;
A003 var13;
struct A003_extra_alignment {
    char a;
    A003 b;
};
struct A003_extra_alignment var14;
#pragma pack(1)
struct A003_extra_packed {
    A003 a;
};
#pragma pack()
struct A003_extra_required_alignment {
    char a;
    struct A003_extra_packed b;
};
struct A003_extra_required_alignment var15;
struct A003_extra_size {
    char a[sizeof(A003)+1];
    char b;
};
struct A003_extra_size var16;

typedef int A004 __attribute__((aligned(16)));
A004 var17;
struct A004_extra_alignment {
    char a;
    A004 b;
};
struct A004_extra_alignment var18;
#pragma pack(1)
struct A004_extra_packed {
    A004 a;
};
#pragma pack()
struct A004_extra_required_alignment {
    char a;
    struct A004_extra_packed b;
};
struct A004_extra_required_alignment var19;
struct A004_extra_size {
    char a[sizeof(A004)+1];
    char b;
};
struct A004_extra_size var20;

typedef struct {
    char c;
    A004 i __attribute__((aligned(32)));
} A005;
A005 var21;
struct A005_extra_alignment {
    char a;
    A005 b;
};
struct A005_extra_alignment var22;
#pragma pack(1)
struct A005_extra_packed {
    A005 a;
};
#pragma pack()
struct A005_extra_required_alignment {
    char a;
    struct A005_extra_packed b;
};
struct A005_extra_required_alignment var23;
struct A005_extra_size {
    char a[sizeof(A005)+1];
    char b;
};
struct A005_extra_size var24;

typedef struct {
    char c;
    A004 i __attribute__((aligned(32)));
} __attribute__((packed)) A006;
A006 var25;
struct A006_extra_alignment {
    char a;
    A006 b;
};
struct A006_extra_alignment var26;
#pragma pack(1)
struct A006_extra_packed {
    A006 a;
};
#pragma pack()
struct A006_extra_required_alignment {
    char a;
    struct A006_extra_packed b;
};
struct A006_extra_required_alignment var27;
struct A006_extra_size {
    char a[sizeof(A006)+1];
    char b;
};
struct A006_extra_size var28;

typedef struct {
    char c;
    A004 i __attribute__((aligned(32))) __attribute__((packed));
} A007;
A007 var29;
struct A007_extra_alignment {
    char a;
    A007 b;
};
struct A007_extra_alignment var30;
#pragma pack(1)
struct A007_extra_packed {
    A007 a;
};
#pragma pack()
struct A007_extra_required_alignment {
    char a;
    struct A007_extra_packed b;
};
struct A007_extra_required_alignment var31;
struct A007_extra_size {
    char a[sizeof(A007)+1];
    char b;
};
struct A007_extra_size var32;

typedef struct {
    char c;
    A004 i __attribute__((aligned(32))) __attribute__((packed));
} __attribute__((packed)) A008;
A008 var33;
struct A008_extra_alignment {
    char a;
    A008 b;
};
struct A008_extra_alignment var34;
#pragma pack(1)
struct A008_extra_packed {
    A008 a;
};
#pragma pack()
struct A008_extra_required_alignment {
    char a;
    struct A008_extra_packed b;
};
struct A008_extra_required_alignment var35;
struct A008_extra_size {
    char a[sizeof(A008)+1];
    char b;
};
struct A008_extra_size var36;

#pragma pack(2)
typedef struct {
    char c;
    int i __attribute__((aligned(32)));
} A100;
A100 var37;
#pragma pack()
struct A100_extra_alignment {
    char a;
    A100 b;
};
struct A100_extra_alignment var38;
#pragma pack(1)
struct A100_extra_packed {
    A100 a;
};
#pragma pack()
struct A100_extra_required_alignment {
    char a;
    struct A100_extra_packed b;
};
struct A100_extra_required_alignment var39;
struct A100_extra_size {
    char a[sizeof(A100)+1];
    char b;
};
struct A100_extra_size var40;

#pragma pack(2)
typedef struct {
    char c;
    int i __attribute__((aligned(32)));
} __attribute__((packed)) A101;
A101 var41;
#pragma pack()
struct A101_extra_alignment {
    char a;
    A101 b;
};
struct A101_extra_alignment var42;
#pragma pack(1)
struct A101_extra_packed {
    A101 a;
};
#pragma pack()
struct A101_extra_required_alignment {
    char a;
    struct A101_extra_packed b;
};
struct A101_extra_required_alignment var43;
struct A101_extra_size {
    char a[sizeof(A101)+1];
    char b;
};
struct A101_extra_size var44;

#pragma pack(2)
typedef struct {
    char c;
    int i __attribute__((aligned(32))) __attribute__((packed));
} A102;
A102 var45;
#pragma pack()
struct A102_extra_alignment {
    char a;
    A102 b;
};
struct A102_extra_alignment var46;
#pragma pack(1)
struct A102_extra_packed {
    A102 a;
};
#pragma pack()
struct A102_extra_required_alignment {
    char a;
    struct A102_extra_packed b;
};
struct A102_extra_required_alignment var47;
struct A102_extra_size {
    char a[sizeof(A102)+1];
    char b;
};
struct A102_extra_size var48;

#pragma pack(2)
typedef struct {
    char c;
    int i __attribute__((aligned(32))) __attribute__((packed));
} __attribute__((packed)) A103;
A103 var49;
#pragma pack()
struct A103_extra_alignment {
    char a;
    A103 b;
};
struct A103_extra_alignment var50;
#pragma pack(1)
struct A103_extra_packed {
    A103 a;
};
#pragma pack()
struct A103_extra_required_alignment {
    char a;
    struct A103_extra_packed b;
};
struct A103_extra_required_alignment var51;
struct A103_extra_size {
    char a[sizeof(A103)+1];
    char b;
};
struct A103_extra_size var52;

typedef int A104 __attribute__((aligned(16)));
A104 var53;
struct A104_extra_alignment {
    char a;
    A104 b;
};
struct A104_extra_alignment var54;
#pragma pack(1)
struct A104_extra_packed {
    A104 a;
};
#pragma pack()
struct A104_extra_required_alignment {
    char a;
    struct A104_extra_packed b;
};
struct A104_extra_required_alignment var55;
struct A104_extra_size {
    char a[sizeof(A104)+1];
    char b;
};
struct A104_extra_size var56;

#pragma pack(2)
typedef struct {
    char c;
    A104 i __attribute__((aligned(32)));
} A105;
A105 var57;
#pragma pack()
struct A105_extra_alignment {
    char a;
    A105 b;
};
struct A105_extra_alignment var58;
#pragma pack(1)
struct A105_extra_packed {
    A105 a;
};
#pragma pack()
struct A105_extra_required_alignment {
    char a;
    struct A105_extra_packed b;
};
struct A105_extra_required_alignment var59;
struct A105_extra_size {
    char a[sizeof(A105)+1];
    char b;
};
struct A105_extra_size var60;

#pragma pack(2)
typedef struct {
    char c;
    A104 i __attribute__((aligned(32)));
} __attribute__((packed)) A106;
A106 var61;
#pragma pack()
struct A106_extra_alignment {
    char a;
    A106 b;
};
struct A106_extra_alignment var62;
#pragma pack(1)
struct A106_extra_packed {
    A106 a;
};
#pragma pack()
struct A106_extra_required_alignment {
    char a;
    struct A106_extra_packed b;
};
struct A106_extra_required_alignment var63;
struct A106_extra_size {
    char a[sizeof(A106)+1];
    char b;
};
struct A106_extra_size var64;

#pragma pack(2)
typedef struct {
    char c;
    A104 i __attribute__((aligned(32))) __attribute__((packed));
} A107;
A107 var65;
#pragma pack()
struct A107_extra_alignment {
    char a;
    A107 b;
};
struct A107_extra_alignment var66;
#pragma pack(1)
struct A107_extra_packed {
    A107 a;
};
#pragma pack()
struct A107_extra_required_alignment {
    char a;
    struct A107_extra_packed b;
};
struct A107_extra_required_alignment var67;
struct A107_extra_size {
    char a[sizeof(A107)+1];
    char b;
};
struct A107_extra_size var68;

#pragma pack(2)
typedef struct {
    char c;
    A104 i __attribute__((aligned(32))) __attribute__((packed));
} __attribute__((packed)) A108;
A108 var69;
#pragma pack()
struct A108_extra_alignment {
    char a;
    A108 b;
};
struct A108_extra_alignment var70;
#pragma pack(1)
struct A108_extra_packed {
    A108 a;
};
#pragma pack()
struct A108_extra_required_alignment {
    char a;
    struct A108_extra_packed b;
};
struct A108_extra_required_alignment var71;
struct A108_extra_size {
    char a[sizeof(A108)+1];
    char b;
};
struct A108_extra_size var72;

typedef union {
    char c;
    int i __attribute__((aligned(32)));
} B000;
B000 var73;
struct B000_extra_alignment {
    char a;
    B000 b;
};
struct B000_extra_alignment var74;
#pragma pack(1)
struct B000_extra_packed {
    B000 a;
};
#pragma pack()
struct B000_extra_required_alignment {
    char a;
    struct B000_extra_packed b;
};
struct B000_extra_required_alignment var75;
struct B000_extra_size {
    char a[sizeof(B000)+1];
    char b;
};
struct B000_extra_size var76;

typedef union {
    char c;
    int i __attribute__((aligned(32)));
} __attribute__((packed)) B001;
B001 var77;
struct B001_extra_alignment {
    char a;
    B001 b;
};
struct B001_extra_alignment var78;
#pragma pack(1)
struct B001_extra_packed {
    B001 a;
};
#pragma pack()
struct B001_extra_required_alignment {
    char a;
    struct B001_extra_packed b;
};
struct B001_extra_required_alignment var79;
struct B001_extra_size {
    char a[sizeof(B001)+1];
    char b;
};
struct B001_extra_size var80;

typedef union {
    char c;
    int i __attribute__((aligned(32))) __attribute__((packed));
} B002;
B002 var81;
struct B002_extra_alignment {
    char a;
    B002 b;
};
struct B002_extra_alignment var82;
#pragma pack(1)
struct B002_extra_packed {
    B002 a;
};
#pragma pack()
struct B002_extra_required_alignment {
    char a;
    struct B002_extra_packed b;
};
struct B002_extra_required_alignment var83;
struct B002_extra_size {
    char a[sizeof(B002)+1];
    char b;
};
struct B002_extra_size var84;

typedef union {
    char c;
    int i __attribute__((aligned(32))) __attribute__((packed));
} __attribute__((packed)) B003;
B003 var85;
struct B003_extra_alignment {
    char a;
    B003 b;
};
struct B003_extra_alignment var86;
#pragma pack(1)
struct B003_extra_packed {
    B003 a;
};
#pragma pack()
struct B003_extra_required_alignment {
    char a;
    struct B003_extra_packed b;
};
struct B003_extra_required_alignment var87;
struct B003_extra_size {
    char a[sizeof(B003)+1];
    char b;
};
struct B003_extra_size var88;

typedef int B004 __attribute__((aligned(16)));
B004 var89;
struct B004_extra_alignment {
    char a;
    B004 b;
};
struct B004_extra_alignment var90;
#pragma pack(1)
struct B004_extra_packed {
    B004 a;
};
#pragma pack()
struct B004_extra_required_alignment {
    char a;
    struct B004_extra_packed b;
};
struct B004_extra_required_alignment var91;
struct B004_extra_size {
    char a[sizeof(B004)+1];
    char b;
};
struct B004_extra_size var92;

typedef union {
    char c;
    A004 i __attribute__((aligned(32)));
} B005;
B005 var93;
struct B005_extra_alignment {
    char a;
    B005 b;
};
struct B005_extra_alignment var94;
#pragma pack(1)
struct B005_extra_packed {
    B005 a;
};
#pragma pack()
struct B005_extra_required_alignment {
    char a;
    struct B005_extra_packed b;
};
struct B005_extra_required_alignment var95;
struct B005_extra_size {
    char a[sizeof(B005)+1];
    char b;
};
struct B005_extra_size var96;

typedef union {
    char c;
    A004 i __attribute__((aligned(32)));
} __attribute__((packed)) B006;
B006 var97;
struct B006_extra_alignment {
    char a;
    B006 b;
};
struct B006_extra_alignment var98;
#pragma pack(1)
struct B006_extra_packed {
    B006 a;
};
#pragma pack()
struct B006_extra_required_alignment {
    char a;
    struct B006_extra_packed b;
};
struct B006_extra_required_alignment var99;
struct B006_extra_size {
    char a[sizeof(B006)+1];
    char b;
};
struct B006_extra_size var100;

typedef union {
    char c;
    A004 i __attribute__((aligned(32))) __attribute__((packed));
} B007;
B007 var101;
struct B007_extra_alignment {
    char a;
    B007 b;
};
struct B007_extra_alignment var102;
#pragma pack(1)
struct B007_extra_packed {
    B007 a;
};
#pragma pack()
struct B007_extra_required_alignment {
    char a;
    struct B007_extra_packed b;
};
struct B007_extra_required_alignment var103;
struct B007_extra_size {
    char a[sizeof(B007)+1];
    char b;
};
struct B007_extra_size var104;

typedef union {
    char c;
    A004 i __attribute__((aligned(32))) __attribute__((packed));
} __attribute__((packed)) B008;
B008 var105;
struct B008_extra_alignment {
    char a;
    B008 b;
};
struct B008_extra_alignment var106;
#pragma pack(1)
struct B008_extra_packed {
    B008 a;
};
#pragma pack()
struct B008_extra_required_alignment {
    char a;
    struct B008_extra_packed b;
};
struct B008_extra_required_alignment var107;
struct B008_extra_size {
    char a[sizeof(B008)+1];
    char b;
};
struct B008_extra_size var108;

#pragma pack(2)
typedef union {
    char c;
    int i __attribute__((aligned(32)));
} B100;
B100 var109;
#pragma pack()
struct B100_extra_alignment {
    char a;
    B100 b;
};
struct B100_extra_alignment var110;
#pragma pack(1)
struct B100_extra_packed {
    B100 a;
};
#pragma pack()
struct B100_extra_required_alignment {
    char a;
    struct B100_extra_packed b;
};
struct B100_extra_required_alignment var111;
struct B100_extra_size {
    char a[sizeof(B100)+1];
    char b;
};
struct B100_extra_size var112;

#pragma pack(2)
typedef union {
    char c;
    int i __attribute__((aligned(32)));
} __attribute__((packed)) B101;
B101 var113;
#pragma pack()
struct B101_extra_alignment {
    char a;
    B101 b;
};
struct B101_extra_alignment var114;
#pragma pack(1)
struct B101_extra_packed {
    B101 a;
};
#pragma pack()
struct B101_extra_required_alignment {
    char a;
    struct B101_extra_packed b;
};
struct B101_extra_required_alignment var115;
struct B101_extra_size {
    char a[sizeof(B101)+1];
    char b;
};
struct B101_extra_size var116;

#pragma pack(2)
typedef union {
    char c;
    int i __attribute__((aligned(32))) __attribute__((packed));
} B102;
B102 var117;
#pragma pack()
struct B102_extra_alignment {
    char a;
    B102 b;
};
struct B102_extra_alignment var118;
#pragma pack(1)
struct B102_extra_packed {
    B102 a;
};
#pragma pack()
struct B102_extra_required_alignment {
    char a;
    struct B102_extra_packed b;
};
struct B102_extra_required_alignment var119;
struct B102_extra_size {
    char a[sizeof(B102)+1];
    char b;
};
struct B102_extra_size var120;

#pragma pack(2)
typedef union {
    char c;
    int i __attribute__((aligned(32))) __attribute__((packed));
} __attribute__((packed)) B103;
B103 var121;
#pragma pack()
struct B103_extra_alignment {
    char a;
    B103 b;
};
struct B103_extra_alignment var122;
#pragma pack(1)
struct B103_extra_packed {
    B103 a;
};
#pragma pack()
struct B103_extra_required_alignment {
    char a;
    struct B103_extra_packed b;
};
struct B103_extra_required_alignment var123;
struct B103_extra_size {
    char a[sizeof(B103)+1];
    char b;
};
struct B103_extra_size var124;

typedef int B104 __attribute__((aligned(16)));
B104 var125;
struct B104_extra_alignment {
    char a;
    B104 b;
};
struct B104_extra_alignment var126;
#pragma pack(1)
struct B104_extra_packed {
    B104 a;
};
#pragma pack()
struct B104_extra_required_alignment {
    char a;
    struct B104_extra_packed b;
};
struct B104_extra_required_alignment var127;
struct B104_extra_size {
    char a[sizeof(B104)+1];
    char b;
};
struct B104_extra_size var128;

#pragma pack(2)
typedef union {
    char c;
    A104 i __attribute__((aligned(32)));
} B105;
B105 var129;
#pragma pack()
struct B105_extra_alignment {
    char a;
    B105 b;
};
struct B105_extra_alignment var130;
#pragma pack(1)
struct B105_extra_packed {
    B105 a;
};
#pragma pack()
struct B105_extra_required_alignment {
    char a;
    struct B105_extra_packed b;
};
struct B105_extra_required_alignment var131;
struct B105_extra_size {
    char a[sizeof(B105)+1];
    char b;
};
struct B105_extra_size var132;

#pragma pack(2)
typedef union {
    char c;
    A104 i __attribute__((aligned(32)));
} __attribute__((packed)) B106;
B106 var133;
#pragma pack()
struct B106_extra_alignment {
    char a;
    B106 b;
};
struct B106_extra_alignment var134;
#pragma pack(1)
struct B106_extra_packed {
    B106 a;
};
#pragma pack()
struct B106_extra_required_alignment {
    char a;
    struct B106_extra_packed b;
};
struct B106_extra_required_alignment var135;
struct B106_extra_size {
    char a[sizeof(B106)+1];
    char b;
};
struct B106_extra_size var136;

#pragma pack(2)
typedef union {
    char c;
    A104 i __attribute__((aligned(32))) __attribute__((packed));
} B107;
B107 var137;
#pragma pack()
struct B107_extra_alignment {
    char a;
    B107 b;
};
struct B107_extra_alignment var138;
#pragma pack(1)
struct B107_extra_packed {
    B107 a;
};
#pragma pack()
struct B107_extra_required_alignment {
    char a;
    struct B107_extra_packed b;
};
struct B107_extra_required_alignment var139;
struct B107_extra_size {
    char a[sizeof(B107)+1];
    char b;
};
struct B107_extra_size var140;

#pragma pack(2)
typedef union {
    char c;
    A104 i __attribute__((aligned(32))) __attribute__((packed));
} __attribute__((packed)) B108;
B108 var141;
#pragma pack()
struct B108_extra_alignment {
    char a;
    B108 b;
};
struct B108_extra_alignment var142;
#pragma pack(1)
struct B108_extra_packed {
    B108 a;
};
#pragma pack()
struct B108_extra_required_alignment {
    char a;
    struct B108_extra_packed b;
};
struct B108_extra_required_alignment var143;
struct B108_extra_size {
    char a[sizeof(B108)+1];
    char b;
};
struct B108_extra_size var144;


// MAPPING|ONE|aarch64-generic-macos-none:Clang|aarch64-generic-fuchsia-gnu:Clang|aarch64-generic-linux-android:Clang|aarch64-generic-freebsd-gnu:Clang|aarch64-generic-hermit-eabi:Clang|aarch64-generic-linux-gnu:Gcc|aarch64-generic-linux-musl:Gcc|aarch64-generic-netbsd-gnu:Clang|aarch64-generic-other-none:Clang|aarch64-generic-openbsd-gnu:Clang|aarch64-generic-ios-none:Clang|aarch64-generic-ios-macabi:Clang|aarch64-generic-tvos-none:Clang|arm-baseline-other-eabi:Clang|arm-baseline-other-eabihf:Clang|arm-baseline-linux-gnueabi:Gcc|arm-baseline-linux-gnueabihf:Gcc|arm-arm710t-linux-gnueabi:Gcc|arm-arm1020e-linux-gnueabi:Gcc|arm-arm1136j_s-freebsd-gnueabihf:Clang|arm-arm1136j_s-netbsd-eabihf:Clang|arm-baseline-other-eabi:Clang|arm-baseline-other-eabihf:Clang|arm-cortex_r4-ios-none:Clang|arm-cortex_r4-linux-android:Clang|arm-cortex_r4-other-eabi:Clang|arm-cortex_r4-other-eabihf:Clang|arm-baseline-ios-none:Clang|arm-cortex_r4-freebsd-gnueabihf:Clang|arm-cortex_r4-linux-gnueabi:Gcc|arm-cortex_r4-linux-gnueabihf:Gcc|arm-cortex_r4-netbsd-eabihf:Clang|hexagon-generic-linux-musl:Clang|x86-pentium4-ios-none:Clang|x86-i586-linux-gnu:Gcc|x86-i586-linux-musl:Gcc|x86-i686-macos-none:Clang|x86-i686-linux-android:Clang|x86-i686-windows-gnu:Gcc|x86-i686-freebsd-gnu:Clang|x86-i686-haiku-gnu:Clang|x86-i686-linux-gnu:Gcc|x86-i686-linux-musl:Gcc|x86-i686-netbsd-gnu:Clang|x86-i686-openbsd-gnu:Clang|mips64el-mips64-linux-gnuabi64:Gcc|mips64el-mips64-linux-musl:Gcc|mips64-mips64-linux-gnuabi64:Gcc|mips64-mips64-linux-musl:Gcc|mipsel-mips32-linux-gnu:Gcc|mipsel-mips32-linux-musl:Gcc|mipsel-mips32-other-none:Clang|mips-mips32-linux-gnu:Gcc|mips-mips32r6-linux-gnu:Gcc|mips-mips32-linux-gnuabi64:Gcc|mips-mips64r6-linux-gnuabi64:Gcc|mips-mips32-linux-gnu:Gcc|mips-mips32-linux-musl:Gcc|powerpc64le-ppc64le-linux-gnu:Gcc|powerpc64le-ppc64le-linux-musl:Gcc|powerpc64-ppc64-freebsd-gnu:Clang|powerpc64-ppc64-linux-gnu:Gcc|powerpc64-ppc64-linux-musl:Gcc|powerpc-ppc-linux-gnu:Gcc|powerpc-ppc-linux-musl:Gcc|powerpc-ppc-netbsd-gnu:Clang|riscv32-baseline_rv32-other-eabi:Clang|riscv32-baseline_rv32-linux-gnu:Gcc|riscv64-baseline_rv64-other-eabi:Clang|riscv64-baseline_rv64-linux-gnu:Gcc|s390x-generic-linux-gnu:Gcc|sparc64-v9-linux-gnu:Gcc|sparc64-v9-netbsd-gnu:Clang|sparc64-v9-openbsd-gnu:Clang|sparc-v8-linux-gnu:Gcc|sparc64-v9-illumos-eabi:Clang|thumb-arm710t-other-eabi:Clang|thumb-cortex_m0-other-eabi:Clang|thumb-cortex_m4-other-eabihf:Clang|thumb-cortex_m4-other-eabi:Clang|thumb-cortex_m3-other-eabi:Clang|thumb-baseline-other-eabi:Clang|thumb-cortex_m33-other-eabihf:Clang|thumb-cortex_m33-other-eabi:Clang|wasm32-generic-emscripten-musl:Clang|wasm32-generic-other-musl:Clang|wasm32-generic-wasi-musl:Clang|x86_64-x86_64-ios-macabi:Clang|x86_64-x86_64-ios-none:Clang|x86_64-x86_64-macos-none:Clang|x86_64-x86_64-tvos-none:Clang|x86_64-x86_64-other-eabi:Clang|x86_64-x86_64-fuchsia-gnu:Clang|x86_64-x86_64-linux-android:Clang|x86_64-x86_64-illumos-eabi:Clang|x86_64-x86_64-windows-gnu:Gcc|x86_64-x86_64-dragonfly-eabi:Clang|x86_64-x86_64-freebsd-gnu:Clang|x86_64-x86_64-haiku-gnu:Clang|x86_64-x86_64-hermit-eabi:Clang|x86_64-x86_64-linux-gnux32:Gcc|x86_64-x86_64-linux-gnu:Gcc|x86_64-x86_64-linux-musl:Gcc|x86_64-x86_64-netbsd-gnu:Clang|x86_64-x86_64-openbsd-gnu:Clang|END
// repr targets Aarch64AppleMacosx|Some("aarch64-generic-macos-none") Aarch64Fuchsia|Some("aarch64-generic-fuchsia-gnu") Aarch64LinuxAndroid|Some("aarch64-generic-linux-android") Aarch64UnknownFreebsd|Some("aarch64-generic-freebsd-gnu") Aarch64UnknownHermit|Some("aarch64-generic-hermit-eabi") Aarch64UnknownLinuxGnu|Some("aarch64-generic-linux-gnu") Aarch64UnknownLinuxMusl|Some("aarch64-generic-linux-musl") Aarch64UnknownNetbsd|Some("aarch64-generic-netbsd-gnu") Aarch64UnknownNone|Some("aarch64-generic-other-none") Aarch64UnknownOpenbsd|Some("aarch64-generic-openbsd-gnu") Aarch64UnknownRedox|None Arm64AppleIos|Some("aarch64-generic-ios-none") Arm64AppleIosMacabi|Some("aarch64-generic-ios-macabi") Arm64AppleTvos|Some("aarch64-generic-tvos-none") Armebv7rUnknownNoneEabi|Some("arm-baseline-other-eabi") Armebv7rUnknownNoneEabihf|Some("arm-baseline-other-eabihf") ArmLinuxAndroideabi|None ArmUnknownLinuxGnueabi|Some("arm-baseline-linux-gnueabi") ArmUnknownLinuxGnueabihf|Some("arm-baseline-linux-gnueabihf") Armv4tUnknownLinuxGnueabi|Some("arm-arm710t-linux-gnueabi") Armv5teUnknownLinuxGnueabi|Some("arm-arm1020e-linux-gnueabi") Armv5teUnknownLinuxUclibcgnueabi|None Armv6UnknownFreebsdGnueabihf|Some("arm-arm1136j_s-freebsd-gnueabihf") Armv6UnknownNetbsdelfEabihf|Some("arm-arm1136j_s-netbsd-eabihf") Armv7aNoneEabi|Some("arm-baseline-other-eabi") Armv7aNoneEabihf|Some("arm-baseline-other-eabihf") Armv7AppleIos|Some("arm-cortex_r4-ios-none") Armv7NoneLinuxAndroid|Some("arm-cortex_r4-linux-android") Armv7rUnknownNoneEabi|Some("arm-cortex_r4-other-eabi") Armv7rUnknownNoneEabihf|Some("arm-cortex_r4-other-eabihf") Armv7sAppleIos|Some("arm-baseline-ios-none") Armv7UnknownFreebsdGnueabihf|Some("arm-cortex_r4-freebsd-gnueabihf") Armv7UnknownLinuxGnueabi|Some("arm-cortex_r4-linux-gnueabi") Armv7UnknownLinuxGnueabihf|Some("arm-cortex_r4-linux-gnueabihf") Armv7UnknownNetbsdelfEabihf|Some("arm-cortex_r4-netbsd-eabihf") HexagonUnknownLinuxMusl|Some("hexagon-generic-linux-musl") I386AppleIos|Some("x86-pentium4-ios-none") I586UnknownLinuxGnu|Some("x86-i586-linux-gnu") I586UnknownLinuxMusl|Some("x86-i586-linux-musl") I686AppleMacosx|Some("x86-i686-macos-none") I686LinuxAndroid|Some("x86-i686-linux-android") I686PcWindowsGnu|Some("x86-i686-windows-gnu") I686UnknownFreebsd|Some("x86-i686-freebsd-gnu") I686UnknownHaiku|Some("x86-i686-haiku-gnu") I686UnknownLinuxGnu|Some("x86-i686-linux-gnu") I686UnknownLinuxMusl|Some("x86-i686-linux-musl") I686UnknownNetbsdelf|Some("x86-i686-netbsd-gnu") I686UnknownOpenbsd|Some("x86-i686-openbsd-gnu") Mips64elUnknownLinuxGnuabi64|Some("mips64el-mips64-linux-gnuabi64") Mips64elUnknownLinuxMusl|Some("mips64el-mips64-linux-musl") Mips64UnknownLinuxGnuabi64|Some("mips64-mips64-linux-gnuabi64") Mips64UnknownLinuxMusl|Some("mips64-mips64-linux-musl") MipselSonyPsp|None MipselUnknownLinuxGnu|Some("mipsel-mips32-linux-gnu") MipselUnknownLinuxMusl|Some("mipsel-mips32-linux-musl") MipselUnknownLinuxUclibc|None MipselUnknownNone|Some("mipsel-mips32-other-none") Mipsisa32r6elUnknownLinuxGnu|Some("mips-mips32-linux-gnu") Mipsisa32r6UnknownLinuxGnu|Some("mips-mips32r6-linux-gnu") Mipsisa64r6elUnknownLinuxGnuabi64|Some("mips-mips32-linux-gnuabi64") Mipsisa64r6UnknownLinuxGnuabi64|Some("mips-mips64r6-linux-gnuabi64") MipsUnknownLinuxGnu|Some("mips-mips32-linux-gnu") MipsUnknownLinuxMusl|Some("mips-mips32-linux-musl") MipsUnknownLinuxUclibc|None Powerpc64leUnknownLinuxGnu|Some("powerpc64le-ppc64le-linux-gnu") Powerpc64leUnknownLinuxMusl|Some("powerpc64le-ppc64le-linux-musl") Powerpc64UnknownFreebsd|Some("powerpc64-ppc64-freebsd-gnu") Powerpc64UnknownLinuxGnu|Some("powerpc64-ppc64-linux-gnu") Powerpc64UnknownLinuxMusl|Some("powerpc64-ppc64-linux-musl") PowerpcUnknownLinuxGnu|Some("powerpc-ppc-linux-gnu") PowerpcUnknownLinuxGnuspe|None PowerpcUnknownLinuxMusl|Some("powerpc-ppc-linux-musl") PowerpcUnknownNetbsd|Some("powerpc-ppc-netbsd-gnu") Riscv32|Some("riscv32-baseline_rv32-other-eabi") Riscv32UnknownLinuxGnu|Some("riscv32-baseline_rv32-linux-gnu") Riscv64|Some("riscv64-baseline_rv64-other-eabi") Riscv64UnknownLinuxGnu|Some("riscv64-baseline_rv64-linux-gnu") S390xUnknownLinuxGnu|Some("s390x-generic-linux-gnu") Sparc64UnknownLinuxGnu|Some("sparc64-v9-linux-gnu") Sparc64UnknownNetbsd|Some("sparc64-v9-netbsd-gnu") Sparc64UnknownOpenbsd|Some("sparc64-v9-openbsd-gnu") SparcUnknownLinuxGnu|Some("sparc-v8-linux-gnu") Sparcv9Sunillumos|Some("sparc64-v9-illumos-eabi") Thumbv4tNoneEabi|Some("thumb-arm710t-other-eabi") Thumbv6mNoneEabi|Some("thumb-cortex_m0-other-eabi") Thumbv7emNoneEabihf|Some("thumb-cortex_m4-other-eabihf") Thumbv7emNoneEabi|Some("thumb-cortex_m4-other-eabi") Thumbv7mNoneEabi|Some("thumb-cortex_m3-other-eabi") Thumbv8mBaseNoneEabi|Some("thumb-baseline-other-eabi") Thumbv8mMainNoneEabihf|Some("thumb-cortex_m33-other-eabihf") Thumbv8mMainNoneEabi|Some("thumb-cortex_m33-other-eabi") Wasm32UnknownEmscripten|Some("wasm32-generic-emscripten-musl") Wasm32UnknownUnknown|Some("wasm32-generic-other-musl") Wasm32Wasi|Some("wasm32-generic-wasi-musl") X86_64AppleIosMacabi|Some("x86_64-x86_64-ios-macabi") X86_64AppleIos|Some("x86_64-x86_64-ios-none") X86_64AppleMacosx|Some("x86_64-x86_64-macos-none") X86_64AppleTvos|Some("x86_64-x86_64-tvos-none") X86_64Elf|Some("x86_64-x86_64-other-eabi") X86_64Fuchsia|Some("x86_64-x86_64-fuchsia-gnu") X86_64LinuxAndroid|Some("x86_64-x86_64-linux-android") X86_64Pcillumos|Some("x86_64-x86_64-illumos-eabi") X86_64PcWindowsGnu|Some("x86_64-x86_64-windows-gnu") X86_64RumprunNetbsd|None X86_64UnknownDragonfly|Some("x86_64-x86_64-dragonfly-eabi") X86_64UnknownFreebsd|Some("x86_64-x86_64-freebsd-gnu") X86_64UnknownHaiku|Some("x86_64-x86_64-haiku-gnu") X86_64UnknownHermit|Some("x86_64-x86_64-hermit-eabi") X86_64UnknownL4reUclibc|None X86_64UnknownLinuxGnux32|Some("x86_64-x86_64-linux-gnux32") X86_64UnknownLinuxGnu|Some("x86_64-x86_64-linux-gnu") X86_64UnknownLinuxMusl|Some("x86_64-x86_64-linux-musl") X86_64UnknownNetbsd|Some("x86_64-x86_64-netbsd-gnu") X86_64UnknownOpenbsd|Some("x86_64-x86_64-openbsd-gnu") X86_64UnknownRedox|None 
#ifdef ONE
_Static_assert(sizeof(A000) == 64, "");
_Static_assert(_Alignof(A000) == 32, "");
_Static_assert(sizeof(struct A000_extra_alignment) == 96, "");
_Static_assert(_Alignof(struct A000_extra_alignment) == 32, "");
_Static_assert(sizeof(struct A000_extra_packed) == 64, "");
_Static_assert(_Alignof(struct A000_extra_packed) == 1, "");
_Static_assert(sizeof(struct A000_extra_required_alignment) == 65, "");
_Static_assert(_Alignof(struct A000_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A000_extra_size) == 66, "");
_Static_assert(_Alignof(struct A000_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A000,i) == 256, "");
#endif
_Static_assert(sizeof(A001) == 64, "");
_Static_assert(_Alignof(A001) == 32, "");
_Static_assert(sizeof(struct A001_extra_alignment) == 96, "");
_Static_assert(_Alignof(struct A001_extra_alignment) == 32, "");
_Static_assert(sizeof(struct A001_extra_packed) == 64, "");
_Static_assert(_Alignof(struct A001_extra_packed) == 1, "");
_Static_assert(sizeof(struct A001_extra_required_alignment) == 65, "");
_Static_assert(_Alignof(struct A001_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A001_extra_size) == 66, "");
_Static_assert(_Alignof(struct A001_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A001,i) == 256, "");
#endif
_Static_assert(sizeof(A002) == 64, "");
_Static_assert(_Alignof(A002) == 32, "");
_Static_assert(sizeof(struct A002_extra_alignment) == 96, "");
_Static_assert(_Alignof(struct A002_extra_alignment) == 32, "");
_Static_assert(sizeof(struct A002_extra_packed) == 64, "");
_Static_assert(_Alignof(struct A002_extra_packed) == 1, "");
_Static_assert(sizeof(struct A002_extra_required_alignment) == 65, "");
_Static_assert(_Alignof(struct A002_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A002_extra_size) == 66, "");
_Static_assert(_Alignof(struct A002_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A002,i) == 256, "");
#endif
_Static_assert(sizeof(A003) == 64, "");
_Static_assert(_Alignof(A003) == 32, "");
_Static_assert(sizeof(struct A003_extra_alignment) == 96, "");
_Static_assert(_Alignof(struct A003_extra_alignment) == 32, "");
_Static_assert(sizeof(struct A003_extra_packed) == 64, "");
_Static_assert(_Alignof(struct A003_extra_packed) == 1, "");
_Static_assert(sizeof(struct A003_extra_required_alignment) == 65, "");
_Static_assert(_Alignof(struct A003_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A003_extra_size) == 66, "");
_Static_assert(_Alignof(struct A003_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A003,i) == 256, "");
#endif
_Static_assert(sizeof(A004) == 4, "");
_Static_assert(_Alignof(A004) == 16, "");
_Static_assert(sizeof(struct A004_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct A004_extra_alignment) == 16, "");
_Static_assert(sizeof(struct A004_extra_packed) == 4, "");
_Static_assert(_Alignof(struct A004_extra_packed) == 1, "");
_Static_assert(sizeof(struct A004_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct A004_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A004_extra_size) == 6, "");
_Static_assert(_Alignof(struct A004_extra_size) == 1, "");
_Static_assert(sizeof(A005) == 64, "");
_Static_assert(_Alignof(A005) == 32, "");
_Static_assert(sizeof(struct A005_extra_alignment) == 96, "");
_Static_assert(_Alignof(struct A005_extra_alignment) == 32, "");
_Static_assert(sizeof(struct A005_extra_packed) == 64, "");
_Static_assert(_Alignof(struct A005_extra_packed) == 1, "");
_Static_assert(sizeof(struct A005_extra_required_alignment) == 65, "");
_Static_assert(_Alignof(struct A005_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A005_extra_size) == 66, "");
_Static_assert(_Alignof(struct A005_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A005,i) == 256, "");
#endif
_Static_assert(sizeof(A006) == 64, "");
_Static_assert(_Alignof(A006) == 32, "");
_Static_assert(sizeof(struct A006_extra_alignment) == 96, "");
_Static_assert(_Alignof(struct A006_extra_alignment) == 32, "");
_Static_assert(sizeof(struct A006_extra_packed) == 64, "");
_Static_assert(_Alignof(struct A006_extra_packed) == 1, "");
_Static_assert(sizeof(struct A006_extra_required_alignment) == 65, "");
_Static_assert(_Alignof(struct A006_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A006_extra_size) == 66, "");
_Static_assert(_Alignof(struct A006_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A006,i) == 256, "");
#endif
_Static_assert(sizeof(A007) == 64, "");
_Static_assert(_Alignof(A007) == 32, "");
_Static_assert(sizeof(struct A007_extra_alignment) == 96, "");
_Static_assert(_Alignof(struct A007_extra_alignment) == 32, "");
_Static_assert(sizeof(struct A007_extra_packed) == 64, "");
_Static_assert(_Alignof(struct A007_extra_packed) == 1, "");
_Static_assert(sizeof(struct A007_extra_required_alignment) == 65, "");
_Static_assert(_Alignof(struct A007_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A007_extra_size) == 66, "");
_Static_assert(_Alignof(struct A007_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A007,i) == 256, "");
#endif
_Static_assert(sizeof(A008) == 64, "");
_Static_assert(_Alignof(A008) == 32, "");
_Static_assert(sizeof(struct A008_extra_alignment) == 96, "");
_Static_assert(_Alignof(struct A008_extra_alignment) == 32, "");
_Static_assert(sizeof(struct A008_extra_packed) == 64, "");
_Static_assert(_Alignof(struct A008_extra_packed) == 1, "");
_Static_assert(sizeof(struct A008_extra_required_alignment) == 65, "");
_Static_assert(_Alignof(struct A008_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A008_extra_size) == 66, "");
_Static_assert(_Alignof(struct A008_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A008,i) == 256, "");
#endif
_Static_assert(sizeof(A100) == 6, "");
_Static_assert(_Alignof(A100) == 2, "");
_Static_assert(sizeof(struct A100_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct A100_extra_alignment) == 2, "");
_Static_assert(sizeof(struct A100_extra_packed) == 6, "");
_Static_assert(_Alignof(struct A100_extra_packed) == 1, "");
_Static_assert(sizeof(struct A100_extra_required_alignment) == 7, "");
_Static_assert(_Alignof(struct A100_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A100_extra_size) == 8, "");
_Static_assert(_Alignof(struct A100_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A100,i) == 16, "");
#endif
_Static_assert(sizeof(A101) == 6, "");
_Static_assert(_Alignof(A101) == 2, "");
_Static_assert(sizeof(struct A101_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct A101_extra_alignment) == 2, "");
_Static_assert(sizeof(struct A101_extra_packed) == 6, "");
_Static_assert(_Alignof(struct A101_extra_packed) == 1, "");
_Static_assert(sizeof(struct A101_extra_required_alignment) == 7, "");
_Static_assert(_Alignof(struct A101_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A101_extra_size) == 8, "");
_Static_assert(_Alignof(struct A101_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A101,i) == 16, "");
#endif
_Static_assert(sizeof(A102) == 6, "");
_Static_assert(_Alignof(A102) == 2, "");
_Static_assert(sizeof(struct A102_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct A102_extra_alignment) == 2, "");
_Static_assert(sizeof(struct A102_extra_packed) == 6, "");
_Static_assert(_Alignof(struct A102_extra_packed) == 1, "");
_Static_assert(sizeof(struct A102_extra_required_alignment) == 7, "");
_Static_assert(_Alignof(struct A102_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A102_extra_size) == 8, "");
_Static_assert(_Alignof(struct A102_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A102,i) == 16, "");
#endif
_Static_assert(sizeof(A103) == 6, "");
_Static_assert(_Alignof(A103) == 2, "");
_Static_assert(sizeof(struct A103_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct A103_extra_alignment) == 2, "");
_Static_assert(sizeof(struct A103_extra_packed) == 6, "");
_Static_assert(_Alignof(struct A103_extra_packed) == 1, "");
_Static_assert(sizeof(struct A103_extra_required_alignment) == 7, "");
_Static_assert(_Alignof(struct A103_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A103_extra_size) == 8, "");
_Static_assert(_Alignof(struct A103_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A103,i) == 16, "");
#endif
_Static_assert(sizeof(A104) == 4, "");
_Static_assert(_Alignof(A104) == 16, "");
_Static_assert(sizeof(struct A104_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct A104_extra_alignment) == 16, "");
_Static_assert(sizeof(struct A104_extra_packed) == 4, "");
_Static_assert(_Alignof(struct A104_extra_packed) == 1, "");
_Static_assert(sizeof(struct A104_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct A104_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A104_extra_size) == 6, "");
_Static_assert(_Alignof(struct A104_extra_size) == 1, "");
_Static_assert(sizeof(A105) == 6, "");
_Static_assert(_Alignof(A105) == 2, "");
_Static_assert(sizeof(struct A105_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct A105_extra_alignment) == 2, "");
_Static_assert(sizeof(struct A105_extra_packed) == 6, "");
_Static_assert(_Alignof(struct A105_extra_packed) == 1, "");
_Static_assert(sizeof(struct A105_extra_required_alignment) == 7, "");
_Static_assert(_Alignof(struct A105_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A105_extra_size) == 8, "");
_Static_assert(_Alignof(struct A105_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A105,i) == 16, "");
#endif
_Static_assert(sizeof(A106) == 6, "");
_Static_assert(_Alignof(A106) == 2, "");
_Static_assert(sizeof(struct A106_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct A106_extra_alignment) == 2, "");
_Static_assert(sizeof(struct A106_extra_packed) == 6, "");
_Static_assert(_Alignof(struct A106_extra_packed) == 1, "");
_Static_assert(sizeof(struct A106_extra_required_alignment) == 7, "");
_Static_assert(_Alignof(struct A106_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A106_extra_size) == 8, "");
_Static_assert(_Alignof(struct A106_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A106,i) == 16, "");
#endif
_Static_assert(sizeof(A107) == 6, "");
_Static_assert(_Alignof(A107) == 2, "");
_Static_assert(sizeof(struct A107_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct A107_extra_alignment) == 2, "");
_Static_assert(sizeof(struct A107_extra_packed) == 6, "");
_Static_assert(_Alignof(struct A107_extra_packed) == 1, "");
_Static_assert(sizeof(struct A107_extra_required_alignment) == 7, "");
_Static_assert(_Alignof(struct A107_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A107_extra_size) == 8, "");
_Static_assert(_Alignof(struct A107_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A107,i) == 16, "");
#endif
_Static_assert(sizeof(A108) == 6, "");
_Static_assert(_Alignof(A108) == 2, "");
_Static_assert(sizeof(struct A108_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct A108_extra_alignment) == 2, "");
_Static_assert(sizeof(struct A108_extra_packed) == 6, "");
_Static_assert(_Alignof(struct A108_extra_packed) == 1, "");
_Static_assert(sizeof(struct A108_extra_required_alignment) == 7, "");
_Static_assert(_Alignof(struct A108_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A108_extra_size) == 8, "");
_Static_assert(_Alignof(struct A108_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A108,i) == 16, "");
#endif
_Static_assert(sizeof(B000) == 32, "");
_Static_assert(_Alignof(B000) == 32, "");
_Static_assert(sizeof(struct B000_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct B000_extra_alignment) == 32, "");
_Static_assert(sizeof(struct B000_extra_packed) == 32, "");
_Static_assert(_Alignof(struct B000_extra_packed) == 1, "");
_Static_assert(sizeof(struct B000_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct B000_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B000_extra_size) == 34, "");
_Static_assert(_Alignof(struct B000_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B000,i) == 0, "");
#endif
_Static_assert(sizeof(B001) == 32, "");
_Static_assert(_Alignof(B001) == 32, "");
_Static_assert(sizeof(struct B001_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct B001_extra_alignment) == 32, "");
_Static_assert(sizeof(struct B001_extra_packed) == 32, "");
_Static_assert(_Alignof(struct B001_extra_packed) == 1, "");
_Static_assert(sizeof(struct B001_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct B001_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B001_extra_size) == 34, "");
_Static_assert(_Alignof(struct B001_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B001,i) == 0, "");
#endif
_Static_assert(sizeof(B002) == 32, "");
_Static_assert(_Alignof(B002) == 32, "");
_Static_assert(sizeof(struct B002_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct B002_extra_alignment) == 32, "");
_Static_assert(sizeof(struct B002_extra_packed) == 32, "");
_Static_assert(_Alignof(struct B002_extra_packed) == 1, "");
_Static_assert(sizeof(struct B002_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct B002_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B002_extra_size) == 34, "");
_Static_assert(_Alignof(struct B002_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B002,i) == 0, "");
#endif
_Static_assert(sizeof(B003) == 32, "");
_Static_assert(_Alignof(B003) == 32, "");
_Static_assert(sizeof(struct B003_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct B003_extra_alignment) == 32, "");
_Static_assert(sizeof(struct B003_extra_packed) == 32, "");
_Static_assert(_Alignof(struct B003_extra_packed) == 1, "");
_Static_assert(sizeof(struct B003_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct B003_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B003_extra_size) == 34, "");
_Static_assert(_Alignof(struct B003_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B003,i) == 0, "");
#endif
_Static_assert(sizeof(B004) == 4, "");
_Static_assert(_Alignof(B004) == 16, "");
_Static_assert(sizeof(struct B004_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct B004_extra_alignment) == 16, "");
_Static_assert(sizeof(struct B004_extra_packed) == 4, "");
_Static_assert(_Alignof(struct B004_extra_packed) == 1, "");
_Static_assert(sizeof(struct B004_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct B004_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B004_extra_size) == 6, "");
_Static_assert(_Alignof(struct B004_extra_size) == 1, "");
_Static_assert(sizeof(B005) == 32, "");
_Static_assert(_Alignof(B005) == 32, "");
_Static_assert(sizeof(struct B005_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct B005_extra_alignment) == 32, "");
_Static_assert(sizeof(struct B005_extra_packed) == 32, "");
_Static_assert(_Alignof(struct B005_extra_packed) == 1, "");
_Static_assert(sizeof(struct B005_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct B005_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B005_extra_size) == 34, "");
_Static_assert(_Alignof(struct B005_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B005,i) == 0, "");
#endif
_Static_assert(sizeof(B006) == 32, "");
_Static_assert(_Alignof(B006) == 32, "");
_Static_assert(sizeof(struct B006_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct B006_extra_alignment) == 32, "");
_Static_assert(sizeof(struct B006_extra_packed) == 32, "");
_Static_assert(_Alignof(struct B006_extra_packed) == 1, "");
_Static_assert(sizeof(struct B006_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct B006_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B006_extra_size) == 34, "");
_Static_assert(_Alignof(struct B006_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B006,i) == 0, "");
#endif
_Static_assert(sizeof(B007) == 32, "");
_Static_assert(_Alignof(B007) == 32, "");
_Static_assert(sizeof(struct B007_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct B007_extra_alignment) == 32, "");
_Static_assert(sizeof(struct B007_extra_packed) == 32, "");
_Static_assert(_Alignof(struct B007_extra_packed) == 1, "");
_Static_assert(sizeof(struct B007_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct B007_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B007_extra_size) == 34, "");
_Static_assert(_Alignof(struct B007_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B007,i) == 0, "");
#endif
_Static_assert(sizeof(B008) == 32, "");
_Static_assert(_Alignof(B008) == 32, "");
_Static_assert(sizeof(struct B008_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct B008_extra_alignment) == 32, "");
_Static_assert(sizeof(struct B008_extra_packed) == 32, "");
_Static_assert(_Alignof(struct B008_extra_packed) == 1, "");
_Static_assert(sizeof(struct B008_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct B008_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B008_extra_size) == 34, "");
_Static_assert(_Alignof(struct B008_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B008,i) == 0, "");
#endif
_Static_assert(sizeof(B100) == 4, "");
_Static_assert(_Alignof(B100) == 2, "");
_Static_assert(sizeof(struct B100_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct B100_extra_alignment) == 2, "");
_Static_assert(sizeof(struct B100_extra_packed) == 4, "");
_Static_assert(_Alignof(struct B100_extra_packed) == 1, "");
_Static_assert(sizeof(struct B100_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct B100_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B100_extra_size) == 6, "");
_Static_assert(_Alignof(struct B100_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B100,i) == 0, "");
#endif
_Static_assert(sizeof(B101) == 4, "");
_Static_assert(_Alignof(B101) == 2, "");
_Static_assert(sizeof(struct B101_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct B101_extra_alignment) == 2, "");
_Static_assert(sizeof(struct B101_extra_packed) == 4, "");
_Static_assert(_Alignof(struct B101_extra_packed) == 1, "");
_Static_assert(sizeof(struct B101_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct B101_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B101_extra_size) == 6, "");
_Static_assert(_Alignof(struct B101_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B101,i) == 0, "");
#endif
_Static_assert(sizeof(B102) == 4, "");
_Static_assert(_Alignof(B102) == 2, "");
_Static_assert(sizeof(struct B102_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct B102_extra_alignment) == 2, "");
_Static_assert(sizeof(struct B102_extra_packed) == 4, "");
_Static_assert(_Alignof(struct B102_extra_packed) == 1, "");
_Static_assert(sizeof(struct B102_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct B102_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B102_extra_size) == 6, "");
_Static_assert(_Alignof(struct B102_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B102,i) == 0, "");
#endif
_Static_assert(sizeof(B103) == 4, "");
_Static_assert(_Alignof(B103) == 2, "");
_Static_assert(sizeof(struct B103_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct B103_extra_alignment) == 2, "");
_Static_assert(sizeof(struct B103_extra_packed) == 4, "");
_Static_assert(_Alignof(struct B103_extra_packed) == 1, "");
_Static_assert(sizeof(struct B103_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct B103_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B103_extra_size) == 6, "");
_Static_assert(_Alignof(struct B103_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B103,i) == 0, "");
#endif
_Static_assert(sizeof(B104) == 4, "");
_Static_assert(_Alignof(B104) == 16, "");
_Static_assert(sizeof(struct B104_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct B104_extra_alignment) == 16, "");
_Static_assert(sizeof(struct B104_extra_packed) == 4, "");
_Static_assert(_Alignof(struct B104_extra_packed) == 1, "");
_Static_assert(sizeof(struct B104_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct B104_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B104_extra_size) == 6, "");
_Static_assert(_Alignof(struct B104_extra_size) == 1, "");
_Static_assert(sizeof(B105) == 4, "");
_Static_assert(_Alignof(B105) == 2, "");
_Static_assert(sizeof(struct B105_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct B105_extra_alignment) == 2, "");
_Static_assert(sizeof(struct B105_extra_packed) == 4, "");
_Static_assert(_Alignof(struct B105_extra_packed) == 1, "");
_Static_assert(sizeof(struct B105_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct B105_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B105_extra_size) == 6, "");
_Static_assert(_Alignof(struct B105_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B105,i) == 0, "");
#endif
_Static_assert(sizeof(B106) == 4, "");
_Static_assert(_Alignof(B106) == 2, "");
_Static_assert(sizeof(struct B106_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct B106_extra_alignment) == 2, "");
_Static_assert(sizeof(struct B106_extra_packed) == 4, "");
_Static_assert(_Alignof(struct B106_extra_packed) == 1, "");
_Static_assert(sizeof(struct B106_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct B106_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B106_extra_size) == 6, "");
_Static_assert(_Alignof(struct B106_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B106,i) == 0, "");
#endif
_Static_assert(sizeof(B107) == 4, "");
_Static_assert(_Alignof(B107) == 2, "");
_Static_assert(sizeof(struct B107_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct B107_extra_alignment) == 2, "");
_Static_assert(sizeof(struct B107_extra_packed) == 4, "");
_Static_assert(_Alignof(struct B107_extra_packed) == 1, "");
_Static_assert(sizeof(struct B107_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct B107_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B107_extra_size) == 6, "");
_Static_assert(_Alignof(struct B107_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B107,i) == 0, "");
#endif
_Static_assert(sizeof(B108) == 4, "");
_Static_assert(_Alignof(B108) == 2, "");
_Static_assert(sizeof(struct B108_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct B108_extra_alignment) == 2, "");
_Static_assert(sizeof(struct B108_extra_packed) == 4, "");
_Static_assert(_Alignof(struct B108_extra_packed) == 1, "");
_Static_assert(sizeof(struct B108_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct B108_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B108_extra_size) == 6, "");
_Static_assert(_Alignof(struct B108_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B108,i) == 0, "");
#endif
// MAPPING|TWO|avr-avr2-other-eabi:Gcc|END
// repr targets AvrUnknownUnknown|Some("avr-avr2-other-eabi") 
#elif defined(TWO)
_Static_assert(sizeof(A000) == 64, "");
_Static_assert(_Alignof(A000) == 32, "");
_Static_assert(sizeof(struct A000_extra_alignment) == 96, "");
_Static_assert(_Alignof(struct A000_extra_alignment) == 32, "");
_Static_assert(sizeof(struct A000_extra_packed) == 64, "");
_Static_assert(_Alignof(struct A000_extra_packed) == 1, "");
_Static_assert(sizeof(struct A000_extra_required_alignment) == 65, "");
_Static_assert(_Alignof(struct A000_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A000_extra_size) == 66, "");
_Static_assert(_Alignof(struct A000_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A000,i) == 256, "");
#endif
_Static_assert(sizeof(A001) == 64, "");
_Static_assert(_Alignof(A001) == 32, "");
_Static_assert(sizeof(struct A001_extra_alignment) == 96, "");
_Static_assert(_Alignof(struct A001_extra_alignment) == 32, "");
_Static_assert(sizeof(struct A001_extra_packed) == 64, "");
_Static_assert(_Alignof(struct A001_extra_packed) == 1, "");
_Static_assert(sizeof(struct A001_extra_required_alignment) == 65, "");
_Static_assert(_Alignof(struct A001_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A001_extra_size) == 66, "");
_Static_assert(_Alignof(struct A001_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A001,i) == 256, "");
#endif
_Static_assert(sizeof(A002) == 64, "");
_Static_assert(_Alignof(A002) == 32, "");
_Static_assert(sizeof(struct A002_extra_alignment) == 96, "");
_Static_assert(_Alignof(struct A002_extra_alignment) == 32, "");
_Static_assert(sizeof(struct A002_extra_packed) == 64, "");
_Static_assert(_Alignof(struct A002_extra_packed) == 1, "");
_Static_assert(sizeof(struct A002_extra_required_alignment) == 65, "");
_Static_assert(_Alignof(struct A002_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A002_extra_size) == 66, "");
_Static_assert(_Alignof(struct A002_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A002,i) == 256, "");
#endif
_Static_assert(sizeof(A003) == 64, "");
_Static_assert(_Alignof(A003) == 32, "");
_Static_assert(sizeof(struct A003_extra_alignment) == 96, "");
_Static_assert(_Alignof(struct A003_extra_alignment) == 32, "");
_Static_assert(sizeof(struct A003_extra_packed) == 64, "");
_Static_assert(_Alignof(struct A003_extra_packed) == 1, "");
_Static_assert(sizeof(struct A003_extra_required_alignment) == 65, "");
_Static_assert(_Alignof(struct A003_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A003_extra_size) == 66, "");
_Static_assert(_Alignof(struct A003_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A003,i) == 256, "");
#endif
_Static_assert(sizeof(A004) == 2, "");
_Static_assert(_Alignof(A004) == 16, "");
_Static_assert(sizeof(struct A004_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct A004_extra_alignment) == 16, "");
_Static_assert(sizeof(struct A004_extra_packed) == 2, "");
_Static_assert(_Alignof(struct A004_extra_packed) == 1, "");
_Static_assert(sizeof(struct A004_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct A004_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A004_extra_size) == 4, "");
_Static_assert(_Alignof(struct A004_extra_size) == 1, "");
_Static_assert(sizeof(A005) == 64, "");
_Static_assert(_Alignof(A005) == 32, "");
_Static_assert(sizeof(struct A005_extra_alignment) == 96, "");
_Static_assert(_Alignof(struct A005_extra_alignment) == 32, "");
_Static_assert(sizeof(struct A005_extra_packed) == 64, "");
_Static_assert(_Alignof(struct A005_extra_packed) == 1, "");
_Static_assert(sizeof(struct A005_extra_required_alignment) == 65, "");
_Static_assert(_Alignof(struct A005_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A005_extra_size) == 66, "");
_Static_assert(_Alignof(struct A005_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A005,i) == 256, "");
#endif
_Static_assert(sizeof(A006) == 64, "");
_Static_assert(_Alignof(A006) == 32, "");
_Static_assert(sizeof(struct A006_extra_alignment) == 96, "");
_Static_assert(_Alignof(struct A006_extra_alignment) == 32, "");
_Static_assert(sizeof(struct A006_extra_packed) == 64, "");
_Static_assert(_Alignof(struct A006_extra_packed) == 1, "");
_Static_assert(sizeof(struct A006_extra_required_alignment) == 65, "");
_Static_assert(_Alignof(struct A006_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A006_extra_size) == 66, "");
_Static_assert(_Alignof(struct A006_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A006,i) == 256, "");
#endif
_Static_assert(sizeof(A007) == 64, "");
_Static_assert(_Alignof(A007) == 32, "");
_Static_assert(sizeof(struct A007_extra_alignment) == 96, "");
_Static_assert(_Alignof(struct A007_extra_alignment) == 32, "");
_Static_assert(sizeof(struct A007_extra_packed) == 64, "");
_Static_assert(_Alignof(struct A007_extra_packed) == 1, "");
_Static_assert(sizeof(struct A007_extra_required_alignment) == 65, "");
_Static_assert(_Alignof(struct A007_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A007_extra_size) == 66, "");
_Static_assert(_Alignof(struct A007_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A007,i) == 256, "");
#endif
_Static_assert(sizeof(A008) == 64, "");
_Static_assert(_Alignof(A008) == 32, "");
_Static_assert(sizeof(struct A008_extra_alignment) == 96, "");
_Static_assert(_Alignof(struct A008_extra_alignment) == 32, "");
_Static_assert(sizeof(struct A008_extra_packed) == 64, "");
_Static_assert(_Alignof(struct A008_extra_packed) == 1, "");
_Static_assert(sizeof(struct A008_extra_required_alignment) == 65, "");
_Static_assert(_Alignof(struct A008_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A008_extra_size) == 66, "");
_Static_assert(_Alignof(struct A008_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A008,i) == 256, "");
#endif
_Static_assert(sizeof(A100) == 4, "");
_Static_assert(_Alignof(A100) == 2, "");
_Static_assert(sizeof(struct A100_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct A100_extra_alignment) == 2, "");
_Static_assert(sizeof(struct A100_extra_packed) == 4, "");
_Static_assert(_Alignof(struct A100_extra_packed) == 1, "");
_Static_assert(sizeof(struct A100_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct A100_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A100_extra_size) == 6, "");
_Static_assert(_Alignof(struct A100_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A100,i) == 16, "");
#endif
_Static_assert(sizeof(A101) == 4, "");
_Static_assert(_Alignof(A101) == 2, "");
_Static_assert(sizeof(struct A101_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct A101_extra_alignment) == 2, "");
_Static_assert(sizeof(struct A101_extra_packed) == 4, "");
_Static_assert(_Alignof(struct A101_extra_packed) == 1, "");
_Static_assert(sizeof(struct A101_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct A101_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A101_extra_size) == 6, "");
_Static_assert(_Alignof(struct A101_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A101,i) == 16, "");
#endif
_Static_assert(sizeof(A102) == 4, "");
_Static_assert(_Alignof(A102) == 2, "");
_Static_assert(sizeof(struct A102_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct A102_extra_alignment) == 2, "");
_Static_assert(sizeof(struct A102_extra_packed) == 4, "");
_Static_assert(_Alignof(struct A102_extra_packed) == 1, "");
_Static_assert(sizeof(struct A102_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct A102_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A102_extra_size) == 6, "");
_Static_assert(_Alignof(struct A102_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A102,i) == 16, "");
#endif
_Static_assert(sizeof(A103) == 4, "");
_Static_assert(_Alignof(A103) == 2, "");
_Static_assert(sizeof(struct A103_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct A103_extra_alignment) == 2, "");
_Static_assert(sizeof(struct A103_extra_packed) == 4, "");
_Static_assert(_Alignof(struct A103_extra_packed) == 1, "");
_Static_assert(sizeof(struct A103_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct A103_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A103_extra_size) == 6, "");
_Static_assert(_Alignof(struct A103_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A103,i) == 16, "");
#endif
_Static_assert(sizeof(A104) == 2, "");
_Static_assert(_Alignof(A104) == 16, "");
_Static_assert(sizeof(struct A104_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct A104_extra_alignment) == 16, "");
_Static_assert(sizeof(struct A104_extra_packed) == 2, "");
_Static_assert(_Alignof(struct A104_extra_packed) == 1, "");
_Static_assert(sizeof(struct A104_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct A104_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A104_extra_size) == 4, "");
_Static_assert(_Alignof(struct A104_extra_size) == 1, "");
_Static_assert(sizeof(A105) == 4, "");
_Static_assert(_Alignof(A105) == 2, "");
_Static_assert(sizeof(struct A105_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct A105_extra_alignment) == 2, "");
_Static_assert(sizeof(struct A105_extra_packed) == 4, "");
_Static_assert(_Alignof(struct A105_extra_packed) == 1, "");
_Static_assert(sizeof(struct A105_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct A105_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A105_extra_size) == 6, "");
_Static_assert(_Alignof(struct A105_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A105,i) == 16, "");
#endif
_Static_assert(sizeof(A106) == 4, "");
_Static_assert(_Alignof(A106) == 2, "");
_Static_assert(sizeof(struct A106_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct A106_extra_alignment) == 2, "");
_Static_assert(sizeof(struct A106_extra_packed) == 4, "");
_Static_assert(_Alignof(struct A106_extra_packed) == 1, "");
_Static_assert(sizeof(struct A106_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct A106_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A106_extra_size) == 6, "");
_Static_assert(_Alignof(struct A106_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A106,i) == 16, "");
#endif
_Static_assert(sizeof(A107) == 4, "");
_Static_assert(_Alignof(A107) == 2, "");
_Static_assert(sizeof(struct A107_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct A107_extra_alignment) == 2, "");
_Static_assert(sizeof(struct A107_extra_packed) == 4, "");
_Static_assert(_Alignof(struct A107_extra_packed) == 1, "");
_Static_assert(sizeof(struct A107_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct A107_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A107_extra_size) == 6, "");
_Static_assert(_Alignof(struct A107_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A107,i) == 16, "");
#endif
_Static_assert(sizeof(A108) == 4, "");
_Static_assert(_Alignof(A108) == 2, "");
_Static_assert(sizeof(struct A108_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct A108_extra_alignment) == 2, "");
_Static_assert(sizeof(struct A108_extra_packed) == 4, "");
_Static_assert(_Alignof(struct A108_extra_packed) == 1, "");
_Static_assert(sizeof(struct A108_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct A108_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A108_extra_size) == 6, "");
_Static_assert(_Alignof(struct A108_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A108,i) == 16, "");
#endif
_Static_assert(sizeof(B000) == 32, "");
_Static_assert(_Alignof(B000) == 32, "");
_Static_assert(sizeof(struct B000_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct B000_extra_alignment) == 32, "");
_Static_assert(sizeof(struct B000_extra_packed) == 32, "");
_Static_assert(_Alignof(struct B000_extra_packed) == 1, "");
_Static_assert(sizeof(struct B000_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct B000_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B000_extra_size) == 34, "");
_Static_assert(_Alignof(struct B000_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B000,i) == 0, "");
#endif
_Static_assert(sizeof(B001) == 32, "");
_Static_assert(_Alignof(B001) == 32, "");
_Static_assert(sizeof(struct B001_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct B001_extra_alignment) == 32, "");
_Static_assert(sizeof(struct B001_extra_packed) == 32, "");
_Static_assert(_Alignof(struct B001_extra_packed) == 1, "");
_Static_assert(sizeof(struct B001_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct B001_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B001_extra_size) == 34, "");
_Static_assert(_Alignof(struct B001_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B001,i) == 0, "");
#endif
_Static_assert(sizeof(B002) == 32, "");
_Static_assert(_Alignof(B002) == 32, "");
_Static_assert(sizeof(struct B002_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct B002_extra_alignment) == 32, "");
_Static_assert(sizeof(struct B002_extra_packed) == 32, "");
_Static_assert(_Alignof(struct B002_extra_packed) == 1, "");
_Static_assert(sizeof(struct B002_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct B002_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B002_extra_size) == 34, "");
_Static_assert(_Alignof(struct B002_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B002,i) == 0, "");
#endif
_Static_assert(sizeof(B003) == 32, "");
_Static_assert(_Alignof(B003) == 32, "");
_Static_assert(sizeof(struct B003_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct B003_extra_alignment) == 32, "");
_Static_assert(sizeof(struct B003_extra_packed) == 32, "");
_Static_assert(_Alignof(struct B003_extra_packed) == 1, "");
_Static_assert(sizeof(struct B003_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct B003_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B003_extra_size) == 34, "");
_Static_assert(_Alignof(struct B003_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B003,i) == 0, "");
#endif
_Static_assert(sizeof(B004) == 2, "");
_Static_assert(_Alignof(B004) == 16, "");
_Static_assert(sizeof(struct B004_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct B004_extra_alignment) == 16, "");
_Static_assert(sizeof(struct B004_extra_packed) == 2, "");
_Static_assert(_Alignof(struct B004_extra_packed) == 1, "");
_Static_assert(sizeof(struct B004_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct B004_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B004_extra_size) == 4, "");
_Static_assert(_Alignof(struct B004_extra_size) == 1, "");
_Static_assert(sizeof(B005) == 32, "");
_Static_assert(_Alignof(B005) == 32, "");
_Static_assert(sizeof(struct B005_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct B005_extra_alignment) == 32, "");
_Static_assert(sizeof(struct B005_extra_packed) == 32, "");
_Static_assert(_Alignof(struct B005_extra_packed) == 1, "");
_Static_assert(sizeof(struct B005_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct B005_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B005_extra_size) == 34, "");
_Static_assert(_Alignof(struct B005_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B005,i) == 0, "");
#endif
_Static_assert(sizeof(B006) == 32, "");
_Static_assert(_Alignof(B006) == 32, "");
_Static_assert(sizeof(struct B006_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct B006_extra_alignment) == 32, "");
_Static_assert(sizeof(struct B006_extra_packed) == 32, "");
_Static_assert(_Alignof(struct B006_extra_packed) == 1, "");
_Static_assert(sizeof(struct B006_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct B006_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B006_extra_size) == 34, "");
_Static_assert(_Alignof(struct B006_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B006,i) == 0, "");
#endif
_Static_assert(sizeof(B007) == 32, "");
_Static_assert(_Alignof(B007) == 32, "");
_Static_assert(sizeof(struct B007_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct B007_extra_alignment) == 32, "");
_Static_assert(sizeof(struct B007_extra_packed) == 32, "");
_Static_assert(_Alignof(struct B007_extra_packed) == 1, "");
_Static_assert(sizeof(struct B007_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct B007_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B007_extra_size) == 34, "");
_Static_assert(_Alignof(struct B007_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B007,i) == 0, "");
#endif
_Static_assert(sizeof(B008) == 32, "");
_Static_assert(_Alignof(B008) == 32, "");
_Static_assert(sizeof(struct B008_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct B008_extra_alignment) == 32, "");
_Static_assert(sizeof(struct B008_extra_packed) == 32, "");
_Static_assert(_Alignof(struct B008_extra_packed) == 1, "");
_Static_assert(sizeof(struct B008_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct B008_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B008_extra_size) == 34, "");
_Static_assert(_Alignof(struct B008_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B008,i) == 0, "");
#endif
_Static_assert(sizeof(B100) == 2, "");
_Static_assert(_Alignof(B100) == 2, "");
_Static_assert(sizeof(struct B100_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct B100_extra_alignment) == 2, "");
_Static_assert(sizeof(struct B100_extra_packed) == 2, "");
_Static_assert(_Alignof(struct B100_extra_packed) == 1, "");
_Static_assert(sizeof(struct B100_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct B100_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B100_extra_size) == 4, "");
_Static_assert(_Alignof(struct B100_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B100,i) == 0, "");
#endif
_Static_assert(sizeof(B101) == 2, "");
_Static_assert(_Alignof(B101) == 2, "");
_Static_assert(sizeof(struct B101_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct B101_extra_alignment) == 2, "");
_Static_assert(sizeof(struct B101_extra_packed) == 2, "");
_Static_assert(_Alignof(struct B101_extra_packed) == 1, "");
_Static_assert(sizeof(struct B101_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct B101_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B101_extra_size) == 4, "");
_Static_assert(_Alignof(struct B101_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B101,i) == 0, "");
#endif
_Static_assert(sizeof(B102) == 2, "");
_Static_assert(_Alignof(B102) == 2, "");
_Static_assert(sizeof(struct B102_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct B102_extra_alignment) == 2, "");
_Static_assert(sizeof(struct B102_extra_packed) == 2, "");
_Static_assert(_Alignof(struct B102_extra_packed) == 1, "");
_Static_assert(sizeof(struct B102_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct B102_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B102_extra_size) == 4, "");
_Static_assert(_Alignof(struct B102_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B102,i) == 0, "");
#endif
_Static_assert(sizeof(B103) == 2, "");
_Static_assert(_Alignof(B103) == 2, "");
_Static_assert(sizeof(struct B103_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct B103_extra_alignment) == 2, "");
_Static_assert(sizeof(struct B103_extra_packed) == 2, "");
_Static_assert(_Alignof(struct B103_extra_packed) == 1, "");
_Static_assert(sizeof(struct B103_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct B103_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B103_extra_size) == 4, "");
_Static_assert(_Alignof(struct B103_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B103,i) == 0, "");
#endif
_Static_assert(sizeof(B104) == 2, "");
_Static_assert(_Alignof(B104) == 16, "");
_Static_assert(sizeof(struct B104_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct B104_extra_alignment) == 16, "");
_Static_assert(sizeof(struct B104_extra_packed) == 2, "");
_Static_assert(_Alignof(struct B104_extra_packed) == 1, "");
_Static_assert(sizeof(struct B104_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct B104_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B104_extra_size) == 4, "");
_Static_assert(_Alignof(struct B104_extra_size) == 1, "");
_Static_assert(sizeof(B105) == 2, "");
_Static_assert(_Alignof(B105) == 2, "");
_Static_assert(sizeof(struct B105_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct B105_extra_alignment) == 2, "");
_Static_assert(sizeof(struct B105_extra_packed) == 2, "");
_Static_assert(_Alignof(struct B105_extra_packed) == 1, "");
_Static_assert(sizeof(struct B105_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct B105_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B105_extra_size) == 4, "");
_Static_assert(_Alignof(struct B105_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B105,i) == 0, "");
#endif
_Static_assert(sizeof(B106) == 2, "");
_Static_assert(_Alignof(B106) == 2, "");
_Static_assert(sizeof(struct B106_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct B106_extra_alignment) == 2, "");
_Static_assert(sizeof(struct B106_extra_packed) == 2, "");
_Static_assert(_Alignof(struct B106_extra_packed) == 1, "");
_Static_assert(sizeof(struct B106_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct B106_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B106_extra_size) == 4, "");
_Static_assert(_Alignof(struct B106_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B106,i) == 0, "");
#endif
_Static_assert(sizeof(B107) == 2, "");
_Static_assert(_Alignof(B107) == 2, "");
_Static_assert(sizeof(struct B107_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct B107_extra_alignment) == 2, "");
_Static_assert(sizeof(struct B107_extra_packed) == 2, "");
_Static_assert(_Alignof(struct B107_extra_packed) == 1, "");
_Static_assert(sizeof(struct B107_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct B107_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B107_extra_size) == 4, "");
_Static_assert(_Alignof(struct B107_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B107,i) == 0, "");
#endif
_Static_assert(sizeof(B108) == 2, "");
_Static_assert(_Alignof(B108) == 2, "");
_Static_assert(sizeof(struct B108_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct B108_extra_alignment) == 2, "");
_Static_assert(sizeof(struct B108_extra_packed) == 2, "");
_Static_assert(_Alignof(struct B108_extra_packed) == 1, "");
_Static_assert(sizeof(struct B108_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct B108_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B108_extra_size) == 4, "");
_Static_assert(_Alignof(struct B108_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B108,i) == 0, "");
#endif
// MAPPING|THREE|msp430-msp430-other-eabi:Clang|END
// repr targets Msp430NoneElf|Some("msp430-msp430-other-eabi") 
#elif defined(THREE)
_Static_assert(sizeof(A000) == 64, "");
_Static_assert(_Alignof(A000) == 32, "");
_Static_assert(sizeof(struct A000_extra_alignment) == 96, "");
_Static_assert(_Alignof(struct A000_extra_alignment) == 32, "");
_Static_assert(sizeof(struct A000_extra_packed) == 64, "");
_Static_assert(_Alignof(struct A000_extra_packed) == 1, "");
_Static_assert(sizeof(struct A000_extra_required_alignment) == 65, "");
_Static_assert(_Alignof(struct A000_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A000_extra_size) == 66, "");
_Static_assert(_Alignof(struct A000_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A000,i) == 256, "");
#endif
_Static_assert(sizeof(A001) == 64, "");
_Static_assert(_Alignof(A001) == 32, "");
_Static_assert(sizeof(struct A001_extra_alignment) == 96, "");
_Static_assert(_Alignof(struct A001_extra_alignment) == 32, "");
_Static_assert(sizeof(struct A001_extra_packed) == 64, "");
_Static_assert(_Alignof(struct A001_extra_packed) == 1, "");
_Static_assert(sizeof(struct A001_extra_required_alignment) == 65, "");
_Static_assert(_Alignof(struct A001_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A001_extra_size) == 66, "");
_Static_assert(_Alignof(struct A001_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A001,i) == 256, "");
#endif
_Static_assert(sizeof(A002) == 64, "");
_Static_assert(_Alignof(A002) == 32, "");
_Static_assert(sizeof(struct A002_extra_alignment) == 96, "");
_Static_assert(_Alignof(struct A002_extra_alignment) == 32, "");
_Static_assert(sizeof(struct A002_extra_packed) == 64, "");
_Static_assert(_Alignof(struct A002_extra_packed) == 1, "");
_Static_assert(sizeof(struct A002_extra_required_alignment) == 65, "");
_Static_assert(_Alignof(struct A002_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A002_extra_size) == 66, "");
_Static_assert(_Alignof(struct A002_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A002,i) == 256, "");
#endif
_Static_assert(sizeof(A003) == 64, "");
_Static_assert(_Alignof(A003) == 32, "");
_Static_assert(sizeof(struct A003_extra_alignment) == 96, "");
_Static_assert(_Alignof(struct A003_extra_alignment) == 32, "");
_Static_assert(sizeof(struct A003_extra_packed) == 64, "");
_Static_assert(_Alignof(struct A003_extra_packed) == 1, "");
_Static_assert(sizeof(struct A003_extra_required_alignment) == 65, "");
_Static_assert(_Alignof(struct A003_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A003_extra_size) == 66, "");
_Static_assert(_Alignof(struct A003_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A003,i) == 256, "");
#endif
_Static_assert(sizeof(A004) == 2, "");
_Static_assert(_Alignof(A004) == 16, "");
_Static_assert(sizeof(struct A004_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct A004_extra_alignment) == 16, "");
_Static_assert(sizeof(struct A004_extra_packed) == 2, "");
_Static_assert(_Alignof(struct A004_extra_packed) == 1, "");
_Static_assert(sizeof(struct A004_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct A004_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A004_extra_size) == 4, "");
_Static_assert(_Alignof(struct A004_extra_size) == 1, "");
_Static_assert(sizeof(A005) == 64, "");
_Static_assert(_Alignof(A005) == 32, "");
_Static_assert(sizeof(struct A005_extra_alignment) == 96, "");
_Static_assert(_Alignof(struct A005_extra_alignment) == 32, "");
_Static_assert(sizeof(struct A005_extra_packed) == 64, "");
_Static_assert(_Alignof(struct A005_extra_packed) == 1, "");
_Static_assert(sizeof(struct A005_extra_required_alignment) == 65, "");
_Static_assert(_Alignof(struct A005_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A005_extra_size) == 66, "");
_Static_assert(_Alignof(struct A005_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A005,i) == 256, "");
#endif
_Static_assert(sizeof(A006) == 64, "");
_Static_assert(_Alignof(A006) == 32, "");
_Static_assert(sizeof(struct A006_extra_alignment) == 96, "");
_Static_assert(_Alignof(struct A006_extra_alignment) == 32, "");
_Static_assert(sizeof(struct A006_extra_packed) == 64, "");
_Static_assert(_Alignof(struct A006_extra_packed) == 1, "");
_Static_assert(sizeof(struct A006_extra_required_alignment) == 65, "");
_Static_assert(_Alignof(struct A006_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A006_extra_size) == 66, "");
_Static_assert(_Alignof(struct A006_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A006,i) == 256, "");
#endif
_Static_assert(sizeof(A007) == 64, "");
_Static_assert(_Alignof(A007) == 32, "");
_Static_assert(sizeof(struct A007_extra_alignment) == 96, "");
_Static_assert(_Alignof(struct A007_extra_alignment) == 32, "");
_Static_assert(sizeof(struct A007_extra_packed) == 64, "");
_Static_assert(_Alignof(struct A007_extra_packed) == 1, "");
_Static_assert(sizeof(struct A007_extra_required_alignment) == 65, "");
_Static_assert(_Alignof(struct A007_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A007_extra_size) == 66, "");
_Static_assert(_Alignof(struct A007_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A007,i) == 256, "");
#endif
_Static_assert(sizeof(A008) == 64, "");
_Static_assert(_Alignof(A008) == 32, "");
_Static_assert(sizeof(struct A008_extra_alignment) == 96, "");
_Static_assert(_Alignof(struct A008_extra_alignment) == 32, "");
_Static_assert(sizeof(struct A008_extra_packed) == 64, "");
_Static_assert(_Alignof(struct A008_extra_packed) == 1, "");
_Static_assert(sizeof(struct A008_extra_required_alignment) == 65, "");
_Static_assert(_Alignof(struct A008_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A008_extra_size) == 66, "");
_Static_assert(_Alignof(struct A008_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A008,i) == 256, "");
#endif
_Static_assert(sizeof(A100) == 4, "");
_Static_assert(_Alignof(A100) == 2, "");
_Static_assert(sizeof(struct A100_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct A100_extra_alignment) == 2, "");
_Static_assert(sizeof(struct A100_extra_packed) == 4, "");
_Static_assert(_Alignof(struct A100_extra_packed) == 1, "");
_Static_assert(sizeof(struct A100_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct A100_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A100_extra_size) == 6, "");
_Static_assert(_Alignof(struct A100_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A100,i) == 16, "");
#endif
_Static_assert(sizeof(A101) == 4, "");
_Static_assert(_Alignof(A101) == 2, "");
_Static_assert(sizeof(struct A101_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct A101_extra_alignment) == 2, "");
_Static_assert(sizeof(struct A101_extra_packed) == 4, "");
_Static_assert(_Alignof(struct A101_extra_packed) == 1, "");
_Static_assert(sizeof(struct A101_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct A101_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A101_extra_size) == 6, "");
_Static_assert(_Alignof(struct A101_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A101,i) == 16, "");
#endif
_Static_assert(sizeof(A102) == 4, "");
_Static_assert(_Alignof(A102) == 2, "");
_Static_assert(sizeof(struct A102_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct A102_extra_alignment) == 2, "");
_Static_assert(sizeof(struct A102_extra_packed) == 4, "");
_Static_assert(_Alignof(struct A102_extra_packed) == 1, "");
_Static_assert(sizeof(struct A102_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct A102_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A102_extra_size) == 6, "");
_Static_assert(_Alignof(struct A102_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A102,i) == 16, "");
#endif
_Static_assert(sizeof(A103) == 4, "");
_Static_assert(_Alignof(A103) == 2, "");
_Static_assert(sizeof(struct A103_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct A103_extra_alignment) == 2, "");
_Static_assert(sizeof(struct A103_extra_packed) == 4, "");
_Static_assert(_Alignof(struct A103_extra_packed) == 1, "");
_Static_assert(sizeof(struct A103_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct A103_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A103_extra_size) == 6, "");
_Static_assert(_Alignof(struct A103_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A103,i) == 16, "");
#endif
_Static_assert(sizeof(A104) == 2, "");
_Static_assert(_Alignof(A104) == 16, "");
_Static_assert(sizeof(struct A104_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct A104_extra_alignment) == 16, "");
_Static_assert(sizeof(struct A104_extra_packed) == 2, "");
_Static_assert(_Alignof(struct A104_extra_packed) == 1, "");
_Static_assert(sizeof(struct A104_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct A104_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A104_extra_size) == 4, "");
_Static_assert(_Alignof(struct A104_extra_size) == 1, "");
_Static_assert(sizeof(A105) == 4, "");
_Static_assert(_Alignof(A105) == 2, "");
_Static_assert(sizeof(struct A105_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct A105_extra_alignment) == 2, "");
_Static_assert(sizeof(struct A105_extra_packed) == 4, "");
_Static_assert(_Alignof(struct A105_extra_packed) == 1, "");
_Static_assert(sizeof(struct A105_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct A105_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A105_extra_size) == 6, "");
_Static_assert(_Alignof(struct A105_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A105,i) == 16, "");
#endif
_Static_assert(sizeof(A106) == 4, "");
_Static_assert(_Alignof(A106) == 2, "");
_Static_assert(sizeof(struct A106_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct A106_extra_alignment) == 2, "");
_Static_assert(sizeof(struct A106_extra_packed) == 4, "");
_Static_assert(_Alignof(struct A106_extra_packed) == 1, "");
_Static_assert(sizeof(struct A106_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct A106_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A106_extra_size) == 6, "");
_Static_assert(_Alignof(struct A106_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A106,i) == 16, "");
#endif
_Static_assert(sizeof(A107) == 4, "");
_Static_assert(_Alignof(A107) == 2, "");
_Static_assert(sizeof(struct A107_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct A107_extra_alignment) == 2, "");
_Static_assert(sizeof(struct A107_extra_packed) == 4, "");
_Static_assert(_Alignof(struct A107_extra_packed) == 1, "");
_Static_assert(sizeof(struct A107_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct A107_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A107_extra_size) == 6, "");
_Static_assert(_Alignof(struct A107_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A107,i) == 16, "");
#endif
_Static_assert(sizeof(A108) == 4, "");
_Static_assert(_Alignof(A108) == 2, "");
_Static_assert(sizeof(struct A108_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct A108_extra_alignment) == 2, "");
_Static_assert(sizeof(struct A108_extra_packed) == 4, "");
_Static_assert(_Alignof(struct A108_extra_packed) == 1, "");
_Static_assert(sizeof(struct A108_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct A108_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A108_extra_size) == 6, "");
_Static_assert(_Alignof(struct A108_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A108,i) == 16, "");
#endif
_Static_assert(sizeof(B000) == 32, "");
_Static_assert(_Alignof(B000) == 32, "");
_Static_assert(sizeof(struct B000_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct B000_extra_alignment) == 32, "");
_Static_assert(sizeof(struct B000_extra_packed) == 32, "");
_Static_assert(_Alignof(struct B000_extra_packed) == 1, "");
_Static_assert(sizeof(struct B000_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct B000_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B000_extra_size) == 34, "");
_Static_assert(_Alignof(struct B000_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B000,i) == 0, "");
#endif
_Static_assert(sizeof(B001) == 32, "");
_Static_assert(_Alignof(B001) == 32, "");
_Static_assert(sizeof(struct B001_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct B001_extra_alignment) == 32, "");
_Static_assert(sizeof(struct B001_extra_packed) == 32, "");
_Static_assert(_Alignof(struct B001_extra_packed) == 1, "");
_Static_assert(sizeof(struct B001_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct B001_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B001_extra_size) == 34, "");
_Static_assert(_Alignof(struct B001_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B001,i) == 0, "");
#endif
_Static_assert(sizeof(B002) == 32, "");
_Static_assert(_Alignof(B002) == 32, "");
_Static_assert(sizeof(struct B002_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct B002_extra_alignment) == 32, "");
_Static_assert(sizeof(struct B002_extra_packed) == 32, "");
_Static_assert(_Alignof(struct B002_extra_packed) == 1, "");
_Static_assert(sizeof(struct B002_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct B002_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B002_extra_size) == 34, "");
_Static_assert(_Alignof(struct B002_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B002,i) == 0, "");
#endif
_Static_assert(sizeof(B003) == 32, "");
_Static_assert(_Alignof(B003) == 32, "");
_Static_assert(sizeof(struct B003_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct B003_extra_alignment) == 32, "");
_Static_assert(sizeof(struct B003_extra_packed) == 32, "");
_Static_assert(_Alignof(struct B003_extra_packed) == 1, "");
_Static_assert(sizeof(struct B003_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct B003_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B003_extra_size) == 34, "");
_Static_assert(_Alignof(struct B003_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B003,i) == 0, "");
#endif
_Static_assert(sizeof(B004) == 2, "");
_Static_assert(_Alignof(B004) == 16, "");
_Static_assert(sizeof(struct B004_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct B004_extra_alignment) == 16, "");
_Static_assert(sizeof(struct B004_extra_packed) == 2, "");
_Static_assert(_Alignof(struct B004_extra_packed) == 1, "");
_Static_assert(sizeof(struct B004_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct B004_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B004_extra_size) == 4, "");
_Static_assert(_Alignof(struct B004_extra_size) == 1, "");
_Static_assert(sizeof(B005) == 32, "");
_Static_assert(_Alignof(B005) == 32, "");
_Static_assert(sizeof(struct B005_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct B005_extra_alignment) == 32, "");
_Static_assert(sizeof(struct B005_extra_packed) == 32, "");
_Static_assert(_Alignof(struct B005_extra_packed) == 1, "");
_Static_assert(sizeof(struct B005_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct B005_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B005_extra_size) == 34, "");
_Static_assert(_Alignof(struct B005_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B005,i) == 0, "");
#endif
_Static_assert(sizeof(B006) == 32, "");
_Static_assert(_Alignof(B006) == 32, "");
_Static_assert(sizeof(struct B006_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct B006_extra_alignment) == 32, "");
_Static_assert(sizeof(struct B006_extra_packed) == 32, "");
_Static_assert(_Alignof(struct B006_extra_packed) == 1, "");
_Static_assert(sizeof(struct B006_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct B006_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B006_extra_size) == 34, "");
_Static_assert(_Alignof(struct B006_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B006,i) == 0, "");
#endif
_Static_assert(sizeof(B007) == 32, "");
_Static_assert(_Alignof(B007) == 32, "");
_Static_assert(sizeof(struct B007_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct B007_extra_alignment) == 32, "");
_Static_assert(sizeof(struct B007_extra_packed) == 32, "");
_Static_assert(_Alignof(struct B007_extra_packed) == 1, "");
_Static_assert(sizeof(struct B007_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct B007_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B007_extra_size) == 34, "");
_Static_assert(_Alignof(struct B007_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B007,i) == 0, "");
#endif
_Static_assert(sizeof(B008) == 32, "");
_Static_assert(_Alignof(B008) == 32, "");
_Static_assert(sizeof(struct B008_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct B008_extra_alignment) == 32, "");
_Static_assert(sizeof(struct B008_extra_packed) == 32, "");
_Static_assert(_Alignof(struct B008_extra_packed) == 1, "");
_Static_assert(sizeof(struct B008_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct B008_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B008_extra_size) == 34, "");
_Static_assert(_Alignof(struct B008_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B008,i) == 0, "");
#endif
_Static_assert(sizeof(B100) == 2, "");
_Static_assert(_Alignof(B100) == 2, "");
_Static_assert(sizeof(struct B100_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct B100_extra_alignment) == 2, "");
_Static_assert(sizeof(struct B100_extra_packed) == 2, "");
_Static_assert(_Alignof(struct B100_extra_packed) == 1, "");
_Static_assert(sizeof(struct B100_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct B100_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B100_extra_size) == 4, "");
_Static_assert(_Alignof(struct B100_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B100,i) == 0, "");
#endif
_Static_assert(sizeof(B101) == 2, "");
_Static_assert(_Alignof(B101) == 2, "");
_Static_assert(sizeof(struct B101_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct B101_extra_alignment) == 2, "");
_Static_assert(sizeof(struct B101_extra_packed) == 2, "");
_Static_assert(_Alignof(struct B101_extra_packed) == 1, "");
_Static_assert(sizeof(struct B101_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct B101_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B101_extra_size) == 4, "");
_Static_assert(_Alignof(struct B101_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B101,i) == 0, "");
#endif
_Static_assert(sizeof(B102) == 2, "");
_Static_assert(_Alignof(B102) == 2, "");
_Static_assert(sizeof(struct B102_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct B102_extra_alignment) == 2, "");
_Static_assert(sizeof(struct B102_extra_packed) == 2, "");
_Static_assert(_Alignof(struct B102_extra_packed) == 1, "");
_Static_assert(sizeof(struct B102_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct B102_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B102_extra_size) == 4, "");
_Static_assert(_Alignof(struct B102_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B102,i) == 0, "");
#endif
_Static_assert(sizeof(B103) == 2, "");
_Static_assert(_Alignof(B103) == 2, "");
_Static_assert(sizeof(struct B103_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct B103_extra_alignment) == 2, "");
_Static_assert(sizeof(struct B103_extra_packed) == 2, "");
_Static_assert(_Alignof(struct B103_extra_packed) == 1, "");
_Static_assert(sizeof(struct B103_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct B103_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B103_extra_size) == 4, "");
_Static_assert(_Alignof(struct B103_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B103,i) == 0, "");
#endif
_Static_assert(sizeof(B104) == 2, "");
_Static_assert(_Alignof(B104) == 16, "");
_Static_assert(sizeof(struct B104_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct B104_extra_alignment) == 16, "");
_Static_assert(sizeof(struct B104_extra_packed) == 2, "");
_Static_assert(_Alignof(struct B104_extra_packed) == 1, "");
_Static_assert(sizeof(struct B104_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct B104_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B104_extra_size) == 4, "");
_Static_assert(_Alignof(struct B104_extra_size) == 1, "");
_Static_assert(sizeof(B105) == 2, "");
_Static_assert(_Alignof(B105) == 2, "");
_Static_assert(sizeof(struct B105_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct B105_extra_alignment) == 2, "");
_Static_assert(sizeof(struct B105_extra_packed) == 2, "");
_Static_assert(_Alignof(struct B105_extra_packed) == 1, "");
_Static_assert(sizeof(struct B105_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct B105_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B105_extra_size) == 4, "");
_Static_assert(_Alignof(struct B105_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B105,i) == 0, "");
#endif
_Static_assert(sizeof(B106) == 2, "");
_Static_assert(_Alignof(B106) == 2, "");
_Static_assert(sizeof(struct B106_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct B106_extra_alignment) == 2, "");
_Static_assert(sizeof(struct B106_extra_packed) == 2, "");
_Static_assert(_Alignof(struct B106_extra_packed) == 1, "");
_Static_assert(sizeof(struct B106_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct B106_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B106_extra_size) == 4, "");
_Static_assert(_Alignof(struct B106_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B106,i) == 0, "");
#endif
_Static_assert(sizeof(B107) == 2, "");
_Static_assert(_Alignof(B107) == 2, "");
_Static_assert(sizeof(struct B107_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct B107_extra_alignment) == 2, "");
_Static_assert(sizeof(struct B107_extra_packed) == 2, "");
_Static_assert(_Alignof(struct B107_extra_packed) == 1, "");
_Static_assert(sizeof(struct B107_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct B107_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B107_extra_size) == 4, "");
_Static_assert(_Alignof(struct B107_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B107,i) == 0, "");
#endif
_Static_assert(sizeof(B108) == 2, "");
_Static_assert(_Alignof(B108) == 2, "");
_Static_assert(sizeof(struct B108_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct B108_extra_alignment) == 2, "");
_Static_assert(sizeof(struct B108_extra_packed) == 2, "");
_Static_assert(_Alignof(struct B108_extra_packed) == 1, "");
_Static_assert(sizeof(struct B108_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct B108_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B108_extra_size) == 4, "");
_Static_assert(_Alignof(struct B108_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B108,i) == 0, "");
#endif
#endif
