// SPDX-License-Identifier: GPL-3.0-or-later

// This test file is auto-generated. do not edit.
// This file is a derivative work from the test files found// in this repo : https://github.com/mahkoh/repr-c
// and is under the same licence as the original work.

#pragma pack(0)
typedef struct {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} A00;
A00 var1;
#pragma pack()
struct A00_alignment {
#ifdef MSVC
    char a[_Alignof(A00)];
    char b;
#else
    char a;
    A00 b;
#endif
};
struct A00_alignment var2;
#pragma pack(1)
struct A00_packed {
    A00 a;
};
#pragma pack()
struct A00_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct A00_packed)];
    char b;
#else
    char a;
    struct A00_packed b;
#endif
};
struct A00_required_alignment var3;
struct A00_size {
    char a[sizeof(A00)+1];
    char b;
};
struct A00_size var4;

#pragma pack(1)
typedef struct {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} A01;
A01 var5;
#pragma pack()
struct A01_alignment {
#ifdef MSVC
    char a[_Alignof(A01)];
    char b;
#else
    char a;
    A01 b;
#endif
};
struct A01_alignment var6;
#pragma pack(1)
struct A01_packed {
    A01 a;
};
#pragma pack()
struct A01_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct A01_packed)];
    char b;
#else
    char a;
    struct A01_packed b;
#endif
};
struct A01_required_alignment var7;
struct A01_size {
    char a[sizeof(A01)+1];
    char b;
};
struct A01_size var8;

#pragma pack(2)
typedef struct {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} A02;
A02 var9;
#pragma pack()
struct A02_alignment {
#ifdef MSVC
    char a[_Alignof(A02)];
    char b;
#else
    char a;
    A02 b;
#endif
};
struct A02_alignment var10;
#pragma pack(1)
struct A02_packed {
    A02 a;
};
#pragma pack()
struct A02_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct A02_packed)];
    char b;
#else
    char a;
    struct A02_packed b;
#endif
};
struct A02_required_alignment var11;
struct A02_size {
    char a[sizeof(A02)+1];
    char b;
};
struct A02_size var12;

#pragma pack(3)
typedef struct {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} A03;
A03 var13;
#pragma pack()
struct A03_alignment {
#ifdef MSVC
    char a[_Alignof(A03)];
    char b;
#else
    char a;
    A03 b;
#endif
};
struct A03_alignment var14;
#pragma pack(1)
struct A03_packed {
    A03 a;
};
#pragma pack()
struct A03_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct A03_packed)];
    char b;
#else
    char a;
    struct A03_packed b;
#endif
};
struct A03_required_alignment var15;
struct A03_size {
    char a[sizeof(A03)+1];
    char b;
};
struct A03_size var16;

#pragma pack(4)
typedef struct {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} A04;
A04 var17;
#pragma pack()
struct A04_alignment {
#ifdef MSVC
    char a[_Alignof(A04)];
    char b;
#else
    char a;
    A04 b;
#endif
};
struct A04_alignment var18;
#pragma pack(1)
struct A04_packed {
    A04 a;
};
#pragma pack()
struct A04_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct A04_packed)];
    char b;
#else
    char a;
    struct A04_packed b;
#endif
};
struct A04_required_alignment var19;
struct A04_size {
    char a[sizeof(A04)+1];
    char b;
};
struct A04_size var20;

#pragma pack(5)
typedef struct {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} A05;
A05 var21;
#pragma pack()
struct A05_alignment {
#ifdef MSVC
    char a[_Alignof(A05)];
    char b;
#else
    char a;
    A05 b;
#endif
};
struct A05_alignment var22;
#pragma pack(1)
struct A05_packed {
    A05 a;
};
#pragma pack()
struct A05_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct A05_packed)];
    char b;
#else
    char a;
    struct A05_packed b;
#endif
};
struct A05_required_alignment var23;
struct A05_size {
    char a[sizeof(A05)+1];
    char b;
};
struct A05_size var24;

#pragma pack(6)
typedef struct {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} A06;
A06 var25;
#pragma pack()
struct A06_alignment {
#ifdef MSVC
    char a[_Alignof(A06)];
    char b;
#else
    char a;
    A06 b;
#endif
};
struct A06_alignment var26;
#pragma pack(1)
struct A06_packed {
    A06 a;
};
#pragma pack()
struct A06_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct A06_packed)];
    char b;
#else
    char a;
    struct A06_packed b;
#endif
};
struct A06_required_alignment var27;
struct A06_size {
    char a[sizeof(A06)+1];
    char b;
};
struct A06_size var28;

#pragma pack(7)
typedef struct {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} A07;
A07 var29;
#pragma pack()
struct A07_alignment {
#ifdef MSVC
    char a[_Alignof(A07)];
    char b;
#else
    char a;
    A07 b;
#endif
};
struct A07_alignment var30;
#pragma pack(1)
struct A07_packed {
    A07 a;
};
#pragma pack()
struct A07_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct A07_packed)];
    char b;
#else
    char a;
    struct A07_packed b;
#endif
};
struct A07_required_alignment var31;
struct A07_size {
    char a[sizeof(A07)+1];
    char b;
};
struct A07_size var32;

#pragma pack(8)
typedef struct {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} A08;
A08 var33;
#pragma pack()
struct A08_alignment {
#ifdef MSVC
    char a[_Alignof(A08)];
    char b;
#else
    char a;
    A08 b;
#endif
};
struct A08_alignment var34;
#pragma pack(1)
struct A08_packed {
    A08 a;
};
#pragma pack()
struct A08_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct A08_packed)];
    char b;
#else
    char a;
    struct A08_packed b;
#endif
};
struct A08_required_alignment var35;
struct A08_size {
    char a[sizeof(A08)+1];
    char b;
};
struct A08_size var36;

#pragma pack(9)
typedef struct {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} A09;
A09 var37;
#pragma pack()
struct A09_alignment {
#ifdef MSVC
    char a[_Alignof(A09)];
    char b;
#else
    char a;
    A09 b;
#endif
};
struct A09_alignment var38;
#pragma pack(1)
struct A09_packed {
    A09 a;
};
#pragma pack()
struct A09_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct A09_packed)];
    char b;
#else
    char a;
    struct A09_packed b;
#endif
};
struct A09_required_alignment var39;
struct A09_size {
    char a[sizeof(A09)+1];
    char b;
};
struct A09_size var40;

#pragma pack(10)
typedef struct {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} A10;
A10 var41;
#pragma pack()
struct A10_alignment {
#ifdef MSVC
    char a[_Alignof(A10)];
    char b;
#else
    char a;
    A10 b;
#endif
};
struct A10_alignment var42;
#pragma pack(1)
struct A10_packed {
    A10 a;
};
#pragma pack()
struct A10_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct A10_packed)];
    char b;
#else
    char a;
    struct A10_packed b;
#endif
};
struct A10_required_alignment var43;
struct A10_size {
    char a[sizeof(A10)+1];
    char b;
};
struct A10_size var44;

#pragma pack(11)
typedef struct {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} A11;
A11 var45;
#pragma pack()
struct A11_alignment {
#ifdef MSVC
    char a[_Alignof(A11)];
    char b;
#else
    char a;
    A11 b;
#endif
};
struct A11_alignment var46;
#pragma pack(1)
struct A11_packed {
    A11 a;
};
#pragma pack()
struct A11_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct A11_packed)];
    char b;
#else
    char a;
    struct A11_packed b;
#endif
};
struct A11_required_alignment var47;
struct A11_size {
    char a[sizeof(A11)+1];
    char b;
};
struct A11_size var48;

#pragma pack(12)
typedef struct {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} A12;
A12 var49;
#pragma pack()
struct A12_alignment {
#ifdef MSVC
    char a[_Alignof(A12)];
    char b;
#else
    char a;
    A12 b;
#endif
};
struct A12_alignment var50;
#pragma pack(1)
struct A12_packed {
    A12 a;
};
#pragma pack()
struct A12_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct A12_packed)];
    char b;
#else
    char a;
    struct A12_packed b;
#endif
};
struct A12_required_alignment var51;
struct A12_size {
    char a[sizeof(A12)+1];
    char b;
};
struct A12_size var52;

#pragma pack(13)
typedef struct {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} A13;
A13 var53;
#pragma pack()
struct A13_alignment {
#ifdef MSVC
    char a[_Alignof(A13)];
    char b;
#else
    char a;
    A13 b;
#endif
};
struct A13_alignment var54;
#pragma pack(1)
struct A13_packed {
    A13 a;
};
#pragma pack()
struct A13_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct A13_packed)];
    char b;
#else
    char a;
    struct A13_packed b;
#endif
};
struct A13_required_alignment var55;
struct A13_size {
    char a[sizeof(A13)+1];
    char b;
};
struct A13_size var56;

#pragma pack(14)
typedef struct {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} A14;
A14 var57;
#pragma pack()
struct A14_alignment {
#ifdef MSVC
    char a[_Alignof(A14)];
    char b;
#else
    char a;
    A14 b;
#endif
};
struct A14_alignment var58;
#pragma pack(1)
struct A14_packed {
    A14 a;
};
#pragma pack()
struct A14_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct A14_packed)];
    char b;
#else
    char a;
    struct A14_packed b;
#endif
};
struct A14_required_alignment var59;
struct A14_size {
    char a[sizeof(A14)+1];
    char b;
};
struct A14_size var60;

#pragma pack(15)
typedef struct {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} A15;
A15 var61;
#pragma pack()
struct A15_alignment {
#ifdef MSVC
    char a[_Alignof(A15)];
    char b;
#else
    char a;
    A15 b;
#endif
};
struct A15_alignment var62;
#pragma pack(1)
struct A15_packed {
    A15 a;
};
#pragma pack()
struct A15_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct A15_packed)];
    char b;
#else
    char a;
    struct A15_packed b;
#endif
};
struct A15_required_alignment var63;
struct A15_size {
    char a[sizeof(A15)+1];
    char b;
};
struct A15_size var64;

#pragma pack(16)
typedef struct {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} A16;
A16 var65;
#pragma pack()
struct A16_alignment {
#ifdef MSVC
    char a[_Alignof(A16)];
    char b;
#else
    char a;
    A16 b;
#endif
};
struct A16_alignment var66;
#pragma pack(1)
struct A16_packed {
    A16 a;
};
#pragma pack()
struct A16_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct A16_packed)];
    char b;
#else
    char a;
    struct A16_packed b;
#endif
};
struct A16_required_alignment var67;
struct A16_size {
    char a[sizeof(A16)+1];
    char b;
};
struct A16_size var68;

#pragma pack(17)
typedef struct {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} A17;
A17 var69;
#pragma pack()
struct A17_alignment {
#ifdef MSVC
    char a[_Alignof(A17)];
    char b;
#else
    char a;
    A17 b;
#endif
};
struct A17_alignment var70;
#pragma pack(1)
struct A17_packed {
    A17 a;
};
#pragma pack()
struct A17_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct A17_packed)];
    char b;
#else
    char a;
    struct A17_packed b;
#endif
};
struct A17_required_alignment var71;
struct A17_size {
    char a[sizeof(A17)+1];
    char b;
};
struct A17_size var72;

#pragma pack(18)
typedef struct {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} A18;
A18 var73;
#pragma pack()
struct A18_alignment {
#ifdef MSVC
    char a[_Alignof(A18)];
    char b;
#else
    char a;
    A18 b;
#endif
};
struct A18_alignment var74;
#pragma pack(1)
struct A18_packed {
    A18 a;
};
#pragma pack()
struct A18_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct A18_packed)];
    char b;
#else
    char a;
    struct A18_packed b;
#endif
};
struct A18_required_alignment var75;
struct A18_size {
    char a[sizeof(A18)+1];
    char b;
};
struct A18_size var76;

#pragma pack(19)
typedef struct {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} A19;
A19 var77;
#pragma pack()
struct A19_alignment {
#ifdef MSVC
    char a[_Alignof(A19)];
    char b;
#else
    char a;
    A19 b;
#endif
};
struct A19_alignment var78;
#pragma pack(1)
struct A19_packed {
    A19 a;
};
#pragma pack()
struct A19_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct A19_packed)];
    char b;
#else
    char a;
    struct A19_packed b;
#endif
};
struct A19_required_alignment var79;
struct A19_size {
    char a[sizeof(A19)+1];
    char b;
};
struct A19_size var80;

#pragma pack(20)
typedef struct {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} A20;
A20 var81;
#pragma pack()
struct A20_alignment {
#ifdef MSVC
    char a[_Alignof(A20)];
    char b;
#else
    char a;
    A20 b;
#endif
};
struct A20_alignment var82;
#pragma pack(1)
struct A20_packed {
    A20 a;
};
#pragma pack()
struct A20_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct A20_packed)];
    char b;
#else
    char a;
    struct A20_packed b;
#endif
};
struct A20_required_alignment var83;
struct A20_size {
    char a[sizeof(A20)+1];
    char b;
};
struct A20_size var84;

#pragma pack(21)
typedef struct {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} A21;
A21 var85;
#pragma pack()
struct A21_alignment {
#ifdef MSVC
    char a[_Alignof(A21)];
    char b;
#else
    char a;
    A21 b;
#endif
};
struct A21_alignment var86;
#pragma pack(1)
struct A21_packed {
    A21 a;
};
#pragma pack()
struct A21_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct A21_packed)];
    char b;
#else
    char a;
    struct A21_packed b;
#endif
};
struct A21_required_alignment var87;
struct A21_size {
    char a[sizeof(A21)+1];
    char b;
};
struct A21_size var88;

#pragma pack(22)
typedef struct {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} A22;
A22 var89;
#pragma pack()
struct A22_alignment {
#ifdef MSVC
    char a[_Alignof(A22)];
    char b;
#else
    char a;
    A22 b;
#endif
};
struct A22_alignment var90;
#pragma pack(1)
struct A22_packed {
    A22 a;
};
#pragma pack()
struct A22_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct A22_packed)];
    char b;
#else
    char a;
    struct A22_packed b;
#endif
};
struct A22_required_alignment var91;
struct A22_size {
    char a[sizeof(A22)+1];
    char b;
};
struct A22_size var92;

#pragma pack(23)
typedef struct {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} A23;
A23 var93;
#pragma pack()
struct A23_alignment {
#ifdef MSVC
    char a[_Alignof(A23)];
    char b;
#else
    char a;
    A23 b;
#endif
};
struct A23_alignment var94;
#pragma pack(1)
struct A23_packed {
    A23 a;
};
#pragma pack()
struct A23_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct A23_packed)];
    char b;
#else
    char a;
    struct A23_packed b;
#endif
};
struct A23_required_alignment var95;
struct A23_size {
    char a[sizeof(A23)+1];
    char b;
};
struct A23_size var96;

#pragma pack(24)
typedef struct {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} A24;
A24 var97;
#pragma pack()
struct A24_alignment {
#ifdef MSVC
    char a[_Alignof(A24)];
    char b;
#else
    char a;
    A24 b;
#endif
};
struct A24_alignment var98;
#pragma pack(1)
struct A24_packed {
    A24 a;
};
#pragma pack()
struct A24_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct A24_packed)];
    char b;
#else
    char a;
    struct A24_packed b;
#endif
};
struct A24_required_alignment var99;
struct A24_size {
    char a[sizeof(A24)+1];
    char b;
};
struct A24_size var100;

#pragma pack(25)
typedef struct {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} A25;
A25 var101;
#pragma pack()
struct A25_alignment {
#ifdef MSVC
    char a[_Alignof(A25)];
    char b;
#else
    char a;
    A25 b;
#endif
};
struct A25_alignment var102;
#pragma pack(1)
struct A25_packed {
    A25 a;
};
#pragma pack()
struct A25_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct A25_packed)];
    char b;
#else
    char a;
    struct A25_packed b;
#endif
};
struct A25_required_alignment var103;
struct A25_size {
    char a[sizeof(A25)+1];
    char b;
};
struct A25_size var104;

#pragma pack(26)
typedef struct {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} A26;
A26 var105;
#pragma pack()
struct A26_alignment {
#ifdef MSVC
    char a[_Alignof(A26)];
    char b;
#else
    char a;
    A26 b;
#endif
};
struct A26_alignment var106;
#pragma pack(1)
struct A26_packed {
    A26 a;
};
#pragma pack()
struct A26_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct A26_packed)];
    char b;
#else
    char a;
    struct A26_packed b;
#endif
};
struct A26_required_alignment var107;
struct A26_size {
    char a[sizeof(A26)+1];
    char b;
};
struct A26_size var108;

#pragma pack(27)
typedef struct {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} A27;
A27 var109;
#pragma pack()
struct A27_alignment {
#ifdef MSVC
    char a[_Alignof(A27)];
    char b;
#else
    char a;
    A27 b;
#endif
};
struct A27_alignment var110;
#pragma pack(1)
struct A27_packed {
    A27 a;
};
#pragma pack()
struct A27_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct A27_packed)];
    char b;
#else
    char a;
    struct A27_packed b;
#endif
};
struct A27_required_alignment var111;
struct A27_size {
    char a[sizeof(A27)+1];
    char b;
};
struct A27_size var112;

#pragma pack(28)
typedef struct {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} A28;
A28 var113;
#pragma pack()
struct A28_alignment {
#ifdef MSVC
    char a[_Alignof(A28)];
    char b;
#else
    char a;
    A28 b;
#endif
};
struct A28_alignment var114;
#pragma pack(1)
struct A28_packed {
    A28 a;
};
#pragma pack()
struct A28_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct A28_packed)];
    char b;
#else
    char a;
    struct A28_packed b;
#endif
};
struct A28_required_alignment var115;
struct A28_size {
    char a[sizeof(A28)+1];
    char b;
};
struct A28_size var116;

#pragma pack(29)
typedef struct {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} A29;
A29 var117;
#pragma pack()
struct A29_alignment {
#ifdef MSVC
    char a[_Alignof(A29)];
    char b;
#else
    char a;
    A29 b;
#endif
};
struct A29_alignment var118;
#pragma pack(1)
struct A29_packed {
    A29 a;
};
#pragma pack()
struct A29_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct A29_packed)];
    char b;
#else
    char a;
    struct A29_packed b;
#endif
};
struct A29_required_alignment var119;
struct A29_size {
    char a[sizeof(A29)+1];
    char b;
};
struct A29_size var120;

#pragma pack(30)
typedef struct {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} A30;
A30 var121;
#pragma pack()
struct A30_alignment {
#ifdef MSVC
    char a[_Alignof(A30)];
    char b;
#else
    char a;
    A30 b;
#endif
};
struct A30_alignment var122;
#pragma pack(1)
struct A30_packed {
    A30 a;
};
#pragma pack()
struct A30_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct A30_packed)];
    char b;
#else
    char a;
    struct A30_packed b;
#endif
};
struct A30_required_alignment var123;
struct A30_size {
    char a[sizeof(A30)+1];
    char b;
};
struct A30_size var124;

#pragma pack(31)
typedef struct {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} A31;
A31 var125;
#pragma pack()
struct A31_alignment {
#ifdef MSVC
    char a[_Alignof(A31)];
    char b;
#else
    char a;
    A31 b;
#endif
};
struct A31_alignment var126;
#pragma pack(1)
struct A31_packed {
    A31 a;
};
#pragma pack()
struct A31_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct A31_packed)];
    char b;
#else
    char a;
    struct A31_packed b;
#endif
};
struct A31_required_alignment var127;
struct A31_size {
    char a[sizeof(A31)+1];
    char b;
};
struct A31_size var128;

#pragma pack(32)
typedef struct {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} A32;
A32 var129;
#pragma pack()
struct A32_alignment {
#ifdef MSVC
    char a[_Alignof(A32)];
    char b;
#else
    char a;
    A32 b;
#endif
};
struct A32_alignment var130;
#pragma pack(1)
struct A32_packed {
    A32 a;
};
#pragma pack()
struct A32_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct A32_packed)];
    char b;
#else
    char a;
    struct A32_packed b;
#endif
};
struct A32_required_alignment var131;
struct A32_size {
    char a[sizeof(A32)+1];
    char b;
};
struct A32_size var132;

#pragma pack(33)
typedef struct {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} A33;
A33 var133;
#pragma pack()
struct A33_alignment {
#ifdef MSVC
    char a[_Alignof(A33)];
    char b;
#else
    char a;
    A33 b;
#endif
};
struct A33_alignment var134;
#pragma pack(1)
struct A33_packed {
    A33 a;
};
#pragma pack()
struct A33_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct A33_packed)];
    char b;
#else
    char a;
    struct A33_packed b;
#endif
};
struct A33_required_alignment var135;
struct A33_size {
    char a[sizeof(A33)+1];
    char b;
};
struct A33_size var136;

#pragma pack(34)
typedef struct {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} A34;
A34 var137;
#pragma pack()
struct A34_alignment {
#ifdef MSVC
    char a[_Alignof(A34)];
    char b;
#else
    char a;
    A34 b;
#endif
};
struct A34_alignment var138;
#pragma pack(1)
struct A34_packed {
    A34 a;
};
#pragma pack()
struct A34_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct A34_packed)];
    char b;
#else
    char a;
    struct A34_packed b;
#endif
};
struct A34_required_alignment var139;
struct A34_size {
    char a[sizeof(A34)+1];
    char b;
};
struct A34_size var140;

#pragma pack(35)
typedef struct {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} A35;
A35 var141;
#pragma pack()
struct A35_alignment {
#ifdef MSVC
    char a[_Alignof(A35)];
    char b;
#else
    char a;
    A35 b;
#endif
};
struct A35_alignment var142;
#pragma pack(1)
struct A35_packed {
    A35 a;
};
#pragma pack()
struct A35_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct A35_packed)];
    char b;
#else
    char a;
    struct A35_packed b;
#endif
};
struct A35_required_alignment var143;
struct A35_size {
    char a[sizeof(A35)+1];
    char b;
};
struct A35_size var144;

#pragma pack(36)
typedef struct {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} A36;
A36 var145;
#pragma pack()
struct A36_alignment {
#ifdef MSVC
    char a[_Alignof(A36)];
    char b;
#else
    char a;
    A36 b;
#endif
};
struct A36_alignment var146;
#pragma pack(1)
struct A36_packed {
    A36 a;
};
#pragma pack()
struct A36_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct A36_packed)];
    char b;
#else
    char a;
    struct A36_packed b;
#endif
};
struct A36_required_alignment var147;
struct A36_size {
    char a[sizeof(A36)+1];
    char b;
};
struct A36_size var148;

#pragma pack(37)
typedef struct {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} A37;
A37 var149;
#pragma pack()
struct A37_alignment {
#ifdef MSVC
    char a[_Alignof(A37)];
    char b;
#else
    char a;
    A37 b;
#endif
};
struct A37_alignment var150;
#pragma pack(1)
struct A37_packed {
    A37 a;
};
#pragma pack()
struct A37_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct A37_packed)];
    char b;
#else
    char a;
    struct A37_packed b;
#endif
};
struct A37_required_alignment var151;
struct A37_size {
    char a[sizeof(A37)+1];
    char b;
};
struct A37_size var152;

#pragma pack(38)
typedef struct {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} A38;
A38 var153;
#pragma pack()
struct A38_alignment {
#ifdef MSVC
    char a[_Alignof(A38)];
    char b;
#else
    char a;
    A38 b;
#endif
};
struct A38_alignment var154;
#pragma pack(1)
struct A38_packed {
    A38 a;
};
#pragma pack()
struct A38_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct A38_packed)];
    char b;
#else
    char a;
    struct A38_packed b;
#endif
};
struct A38_required_alignment var155;
struct A38_size {
    char a[sizeof(A38)+1];
    char b;
};
struct A38_size var156;

#pragma pack(39)
typedef struct {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} A39;
A39 var157;
#pragma pack()
struct A39_alignment {
#ifdef MSVC
    char a[_Alignof(A39)];
    char b;
#else
    char a;
    A39 b;
#endif
};
struct A39_alignment var158;
#pragma pack(1)
struct A39_packed {
    A39 a;
};
#pragma pack()
struct A39_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct A39_packed)];
    char b;
#else
    char a;
    struct A39_packed b;
#endif
};
struct A39_required_alignment var159;
struct A39_size {
    char a[sizeof(A39)+1];
    char b;
};
struct A39_size var160;

#pragma pack(0)
typedef union {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} B00;
B00 var161;
#pragma pack()
struct B00_alignment {
#ifdef MSVC
    char a[_Alignof(B00)];
    char b;
#else
    char a;
    B00 b;
#endif
};
struct B00_alignment var162;
#pragma pack(1)
struct B00_packed {
    B00 a;
};
#pragma pack()
struct B00_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct B00_packed)];
    char b;
#else
    char a;
    struct B00_packed b;
#endif
};
struct B00_required_alignment var163;
struct B00_size {
    char a[sizeof(B00)+1];
    char b;
};
struct B00_size var164;

#pragma pack(1)
typedef union {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} B01;
B01 var165;
#pragma pack()
struct B01_alignment {
#ifdef MSVC
    char a[_Alignof(B01)];
    char b;
#else
    char a;
    B01 b;
#endif
};
struct B01_alignment var166;
#pragma pack(1)
struct B01_packed {
    B01 a;
};
#pragma pack()
struct B01_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct B01_packed)];
    char b;
#else
    char a;
    struct B01_packed b;
#endif
};
struct B01_required_alignment var167;
struct B01_size {
    char a[sizeof(B01)+1];
    char b;
};
struct B01_size var168;

#pragma pack(2)
typedef union {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} B02;
B02 var169;
#pragma pack()
struct B02_alignment {
#ifdef MSVC
    char a[_Alignof(B02)];
    char b;
#else
    char a;
    B02 b;
#endif
};
struct B02_alignment var170;
#pragma pack(1)
struct B02_packed {
    B02 a;
};
#pragma pack()
struct B02_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct B02_packed)];
    char b;
#else
    char a;
    struct B02_packed b;
#endif
};
struct B02_required_alignment var171;
struct B02_size {
    char a[sizeof(B02)+1];
    char b;
};
struct B02_size var172;

#pragma pack(3)
typedef union {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} B03;
B03 var173;
#pragma pack()
struct B03_alignment {
#ifdef MSVC
    char a[_Alignof(B03)];
    char b;
#else
    char a;
    B03 b;
#endif
};
struct B03_alignment var174;
#pragma pack(1)
struct B03_packed {
    B03 a;
};
#pragma pack()
struct B03_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct B03_packed)];
    char b;
#else
    char a;
    struct B03_packed b;
#endif
};
struct B03_required_alignment var175;
struct B03_size {
    char a[sizeof(B03)+1];
    char b;
};
struct B03_size var176;

#pragma pack(4)
typedef union {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} B04;
B04 var177;
#pragma pack()
struct B04_alignment {
#ifdef MSVC
    char a[_Alignof(B04)];
    char b;
#else
    char a;
    B04 b;
#endif
};
struct B04_alignment var178;
#pragma pack(1)
struct B04_packed {
    B04 a;
};
#pragma pack()
struct B04_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct B04_packed)];
    char b;
#else
    char a;
    struct B04_packed b;
#endif
};
struct B04_required_alignment var179;
struct B04_size {
    char a[sizeof(B04)+1];
    char b;
};
struct B04_size var180;

#pragma pack(5)
typedef union {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} B05;
B05 var181;
#pragma pack()
struct B05_alignment {
#ifdef MSVC
    char a[_Alignof(B05)];
    char b;
#else
    char a;
    B05 b;
#endif
};
struct B05_alignment var182;
#pragma pack(1)
struct B05_packed {
    B05 a;
};
#pragma pack()
struct B05_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct B05_packed)];
    char b;
#else
    char a;
    struct B05_packed b;
#endif
};
struct B05_required_alignment var183;
struct B05_size {
    char a[sizeof(B05)+1];
    char b;
};
struct B05_size var184;

#pragma pack(6)
typedef union {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} B06;
B06 var185;
#pragma pack()
struct B06_alignment {
#ifdef MSVC
    char a[_Alignof(B06)];
    char b;
#else
    char a;
    B06 b;
#endif
};
struct B06_alignment var186;
#pragma pack(1)
struct B06_packed {
    B06 a;
};
#pragma pack()
struct B06_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct B06_packed)];
    char b;
#else
    char a;
    struct B06_packed b;
#endif
};
struct B06_required_alignment var187;
struct B06_size {
    char a[sizeof(B06)+1];
    char b;
};
struct B06_size var188;

#pragma pack(7)
typedef union {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} B07;
B07 var189;
#pragma pack()
struct B07_alignment {
#ifdef MSVC
    char a[_Alignof(B07)];
    char b;
#else
    char a;
    B07 b;
#endif
};
struct B07_alignment var190;
#pragma pack(1)
struct B07_packed {
    B07 a;
};
#pragma pack()
struct B07_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct B07_packed)];
    char b;
#else
    char a;
    struct B07_packed b;
#endif
};
struct B07_required_alignment var191;
struct B07_size {
    char a[sizeof(B07)+1];
    char b;
};
struct B07_size var192;

#pragma pack(8)
typedef union {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} B08;
B08 var193;
#pragma pack()
struct B08_alignment {
#ifdef MSVC
    char a[_Alignof(B08)];
    char b;
#else
    char a;
    B08 b;
#endif
};
struct B08_alignment var194;
#pragma pack(1)
struct B08_packed {
    B08 a;
};
#pragma pack()
struct B08_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct B08_packed)];
    char b;
#else
    char a;
    struct B08_packed b;
#endif
};
struct B08_required_alignment var195;
struct B08_size {
    char a[sizeof(B08)+1];
    char b;
};
struct B08_size var196;

#pragma pack(9)
typedef union {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} B09;
B09 var197;
#pragma pack()
struct B09_alignment {
#ifdef MSVC
    char a[_Alignof(B09)];
    char b;
#else
    char a;
    B09 b;
#endif
};
struct B09_alignment var198;
#pragma pack(1)
struct B09_packed {
    B09 a;
};
#pragma pack()
struct B09_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct B09_packed)];
    char b;
#else
    char a;
    struct B09_packed b;
#endif
};
struct B09_required_alignment var199;
struct B09_size {
    char a[sizeof(B09)+1];
    char b;
};
struct B09_size var200;

#pragma pack(10)
typedef union {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} B10;
B10 var201;
#pragma pack()
struct B10_alignment {
#ifdef MSVC
    char a[_Alignof(B10)];
    char b;
#else
    char a;
    B10 b;
#endif
};
struct B10_alignment var202;
#pragma pack(1)
struct B10_packed {
    B10 a;
};
#pragma pack()
struct B10_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct B10_packed)];
    char b;
#else
    char a;
    struct B10_packed b;
#endif
};
struct B10_required_alignment var203;
struct B10_size {
    char a[sizeof(B10)+1];
    char b;
};
struct B10_size var204;

#pragma pack(11)
typedef union {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} B11;
B11 var205;
#pragma pack()
struct B11_alignment {
#ifdef MSVC
    char a[_Alignof(B11)];
    char b;
#else
    char a;
    B11 b;
#endif
};
struct B11_alignment var206;
#pragma pack(1)
struct B11_packed {
    B11 a;
};
#pragma pack()
struct B11_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct B11_packed)];
    char b;
#else
    char a;
    struct B11_packed b;
#endif
};
struct B11_required_alignment var207;
struct B11_size {
    char a[sizeof(B11)+1];
    char b;
};
struct B11_size var208;

#pragma pack(12)
typedef union {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} B12;
B12 var209;
#pragma pack()
struct B12_alignment {
#ifdef MSVC
    char a[_Alignof(B12)];
    char b;
#else
    char a;
    B12 b;
#endif
};
struct B12_alignment var210;
#pragma pack(1)
struct B12_packed {
    B12 a;
};
#pragma pack()
struct B12_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct B12_packed)];
    char b;
#else
    char a;
    struct B12_packed b;
#endif
};
struct B12_required_alignment var211;
struct B12_size {
    char a[sizeof(B12)+1];
    char b;
};
struct B12_size var212;

#pragma pack(13)
typedef union {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} B13;
B13 var213;
#pragma pack()
struct B13_alignment {
#ifdef MSVC
    char a[_Alignof(B13)];
    char b;
#else
    char a;
    B13 b;
#endif
};
struct B13_alignment var214;
#pragma pack(1)
struct B13_packed {
    B13 a;
};
#pragma pack()
struct B13_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct B13_packed)];
    char b;
#else
    char a;
    struct B13_packed b;
#endif
};
struct B13_required_alignment var215;
struct B13_size {
    char a[sizeof(B13)+1];
    char b;
};
struct B13_size var216;

#pragma pack(14)
typedef union {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} B14;
B14 var217;
#pragma pack()
struct B14_alignment {
#ifdef MSVC
    char a[_Alignof(B14)];
    char b;
#else
    char a;
    B14 b;
#endif
};
struct B14_alignment var218;
#pragma pack(1)
struct B14_packed {
    B14 a;
};
#pragma pack()
struct B14_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct B14_packed)];
    char b;
#else
    char a;
    struct B14_packed b;
#endif
};
struct B14_required_alignment var219;
struct B14_size {
    char a[sizeof(B14)+1];
    char b;
};
struct B14_size var220;

#pragma pack(15)
typedef union {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} B15;
B15 var221;
#pragma pack()
struct B15_alignment {
#ifdef MSVC
    char a[_Alignof(B15)];
    char b;
#else
    char a;
    B15 b;
#endif
};
struct B15_alignment var222;
#pragma pack(1)
struct B15_packed {
    B15 a;
};
#pragma pack()
struct B15_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct B15_packed)];
    char b;
#else
    char a;
    struct B15_packed b;
#endif
};
struct B15_required_alignment var223;
struct B15_size {
    char a[sizeof(B15)+1];
    char b;
};
struct B15_size var224;

#pragma pack(16)
typedef union {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} B16;
B16 var225;
#pragma pack()
struct B16_alignment {
#ifdef MSVC
    char a[_Alignof(B16)];
    char b;
#else
    char a;
    B16 b;
#endif
};
struct B16_alignment var226;
#pragma pack(1)
struct B16_packed {
    B16 a;
};
#pragma pack()
struct B16_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct B16_packed)];
    char b;
#else
    char a;
    struct B16_packed b;
#endif
};
struct B16_required_alignment var227;
struct B16_size {
    char a[sizeof(B16)+1];
    char b;
};
struct B16_size var228;

#pragma pack(17)
typedef union {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} B17;
B17 var229;
#pragma pack()
struct B17_alignment {
#ifdef MSVC
    char a[_Alignof(B17)];
    char b;
#else
    char a;
    B17 b;
#endif
};
struct B17_alignment var230;
#pragma pack(1)
struct B17_packed {
    B17 a;
};
#pragma pack()
struct B17_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct B17_packed)];
    char b;
#else
    char a;
    struct B17_packed b;
#endif
};
struct B17_required_alignment var231;
struct B17_size {
    char a[sizeof(B17)+1];
    char b;
};
struct B17_size var232;

#pragma pack(18)
typedef union {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} B18;
B18 var233;
#pragma pack()
struct B18_alignment {
#ifdef MSVC
    char a[_Alignof(B18)];
    char b;
#else
    char a;
    B18 b;
#endif
};
struct B18_alignment var234;
#pragma pack(1)
struct B18_packed {
    B18 a;
};
#pragma pack()
struct B18_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct B18_packed)];
    char b;
#else
    char a;
    struct B18_packed b;
#endif
};
struct B18_required_alignment var235;
struct B18_size {
    char a[sizeof(B18)+1];
    char b;
};
struct B18_size var236;

#pragma pack(19)
typedef union {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} B19;
B19 var237;
#pragma pack()
struct B19_alignment {
#ifdef MSVC
    char a[_Alignof(B19)];
    char b;
#else
    char a;
    B19 b;
#endif
};
struct B19_alignment var238;
#pragma pack(1)
struct B19_packed {
    B19 a;
};
#pragma pack()
struct B19_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct B19_packed)];
    char b;
#else
    char a;
    struct B19_packed b;
#endif
};
struct B19_required_alignment var239;
struct B19_size {
    char a[sizeof(B19)+1];
    char b;
};
struct B19_size var240;

#pragma pack(20)
typedef union {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} B20;
B20 var241;
#pragma pack()
struct B20_alignment {
#ifdef MSVC
    char a[_Alignof(B20)];
    char b;
#else
    char a;
    B20 b;
#endif
};
struct B20_alignment var242;
#pragma pack(1)
struct B20_packed {
    B20 a;
};
#pragma pack()
struct B20_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct B20_packed)];
    char b;
#else
    char a;
    struct B20_packed b;
#endif
};
struct B20_required_alignment var243;
struct B20_size {
    char a[sizeof(B20)+1];
    char b;
};
struct B20_size var244;

#pragma pack(21)
typedef union {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} B21;
B21 var245;
#pragma pack()
struct B21_alignment {
#ifdef MSVC
    char a[_Alignof(B21)];
    char b;
#else
    char a;
    B21 b;
#endif
};
struct B21_alignment var246;
#pragma pack(1)
struct B21_packed {
    B21 a;
};
#pragma pack()
struct B21_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct B21_packed)];
    char b;
#else
    char a;
    struct B21_packed b;
#endif
};
struct B21_required_alignment var247;
struct B21_size {
    char a[sizeof(B21)+1];
    char b;
};
struct B21_size var248;

#pragma pack(22)
typedef union {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} B22;
B22 var249;
#pragma pack()
struct B22_alignment {
#ifdef MSVC
    char a[_Alignof(B22)];
    char b;
#else
    char a;
    B22 b;
#endif
};
struct B22_alignment var250;
#pragma pack(1)
struct B22_packed {
    B22 a;
};
#pragma pack()
struct B22_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct B22_packed)];
    char b;
#else
    char a;
    struct B22_packed b;
#endif
};
struct B22_required_alignment var251;
struct B22_size {
    char a[sizeof(B22)+1];
    char b;
};
struct B22_size var252;

#pragma pack(23)
typedef union {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} B23;
B23 var253;
#pragma pack()
struct B23_alignment {
#ifdef MSVC
    char a[_Alignof(B23)];
    char b;
#else
    char a;
    B23 b;
#endif
};
struct B23_alignment var254;
#pragma pack(1)
struct B23_packed {
    B23 a;
};
#pragma pack()
struct B23_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct B23_packed)];
    char b;
#else
    char a;
    struct B23_packed b;
#endif
};
struct B23_required_alignment var255;
struct B23_size {
    char a[sizeof(B23)+1];
    char b;
};
struct B23_size var256;

#pragma pack(24)
typedef union {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} B24;
B24 var257;
#pragma pack()
struct B24_alignment {
#ifdef MSVC
    char a[_Alignof(B24)];
    char b;
#else
    char a;
    B24 b;
#endif
};
struct B24_alignment var258;
#pragma pack(1)
struct B24_packed {
    B24 a;
};
#pragma pack()
struct B24_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct B24_packed)];
    char b;
#else
    char a;
    struct B24_packed b;
#endif
};
struct B24_required_alignment var259;
struct B24_size {
    char a[sizeof(B24)+1];
    char b;
};
struct B24_size var260;

#pragma pack(25)
typedef union {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} B25;
B25 var261;
#pragma pack()
struct B25_alignment {
#ifdef MSVC
    char a[_Alignof(B25)];
    char b;
#else
    char a;
    B25 b;
#endif
};
struct B25_alignment var262;
#pragma pack(1)
struct B25_packed {
    B25 a;
};
#pragma pack()
struct B25_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct B25_packed)];
    char b;
#else
    char a;
    struct B25_packed b;
#endif
};
struct B25_required_alignment var263;
struct B25_size {
    char a[sizeof(B25)+1];
    char b;
};
struct B25_size var264;

#pragma pack(26)
typedef union {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} B26;
B26 var265;
#pragma pack()
struct B26_alignment {
#ifdef MSVC
    char a[_Alignof(B26)];
    char b;
#else
    char a;
    B26 b;
#endif
};
struct B26_alignment var266;
#pragma pack(1)
struct B26_packed {
    B26 a;
};
#pragma pack()
struct B26_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct B26_packed)];
    char b;
#else
    char a;
    struct B26_packed b;
#endif
};
struct B26_required_alignment var267;
struct B26_size {
    char a[sizeof(B26)+1];
    char b;
};
struct B26_size var268;

#pragma pack(27)
typedef union {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} B27;
B27 var269;
#pragma pack()
struct B27_alignment {
#ifdef MSVC
    char a[_Alignof(B27)];
    char b;
#else
    char a;
    B27 b;
#endif
};
struct B27_alignment var270;
#pragma pack(1)
struct B27_packed {
    B27 a;
};
#pragma pack()
struct B27_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct B27_packed)];
    char b;
#else
    char a;
    struct B27_packed b;
#endif
};
struct B27_required_alignment var271;
struct B27_size {
    char a[sizeof(B27)+1];
    char b;
};
struct B27_size var272;

#pragma pack(28)
typedef union {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} B28;
B28 var273;
#pragma pack()
struct B28_alignment {
#ifdef MSVC
    char a[_Alignof(B28)];
    char b;
#else
    char a;
    B28 b;
#endif
};
struct B28_alignment var274;
#pragma pack(1)
struct B28_packed {
    B28 a;
};
#pragma pack()
struct B28_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct B28_packed)];
    char b;
#else
    char a;
    struct B28_packed b;
#endif
};
struct B28_required_alignment var275;
struct B28_size {
    char a[sizeof(B28)+1];
    char b;
};
struct B28_size var276;

#pragma pack(29)
typedef union {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} B29;
B29 var277;
#pragma pack()
struct B29_alignment {
#ifdef MSVC
    char a[_Alignof(B29)];
    char b;
#else
    char a;
    B29 b;
#endif
};
struct B29_alignment var278;
#pragma pack(1)
struct B29_packed {
    B29 a;
};
#pragma pack()
struct B29_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct B29_packed)];
    char b;
#else
    char a;
    struct B29_packed b;
#endif
};
struct B29_required_alignment var279;
struct B29_size {
    char a[sizeof(B29)+1];
    char b;
};
struct B29_size var280;

#pragma pack(30)
typedef union {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} B30;
B30 var281;
#pragma pack()
struct B30_alignment {
#ifdef MSVC
    char a[_Alignof(B30)];
    char b;
#else
    char a;
    B30 b;
#endif
};
struct B30_alignment var282;
#pragma pack(1)
struct B30_packed {
    B30 a;
};
#pragma pack()
struct B30_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct B30_packed)];
    char b;
#else
    char a;
    struct B30_packed b;
#endif
};
struct B30_required_alignment var283;
struct B30_size {
    char a[sizeof(B30)+1];
    char b;
};
struct B30_size var284;

#pragma pack(31)
typedef union {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} B31;
B31 var285;
#pragma pack()
struct B31_alignment {
#ifdef MSVC
    char a[_Alignof(B31)];
    char b;
#else
    char a;
    B31 b;
#endif
};
struct B31_alignment var286;
#pragma pack(1)
struct B31_packed {
    B31 a;
};
#pragma pack()
struct B31_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct B31_packed)];
    char b;
#else
    char a;
    struct B31_packed b;
#endif
};
struct B31_required_alignment var287;
struct B31_size {
    char a[sizeof(B31)+1];
    char b;
};
struct B31_size var288;

#pragma pack(32)
typedef union {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} B32;
B32 var289;
#pragma pack()
struct B32_alignment {
#ifdef MSVC
    char a[_Alignof(B32)];
    char b;
#else
    char a;
    B32 b;
#endif
};
struct B32_alignment var290;
#pragma pack(1)
struct B32_packed {
    B32 a;
};
#pragma pack()
struct B32_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct B32_packed)];
    char b;
#else
    char a;
    struct B32_packed b;
#endif
};
struct B32_required_alignment var291;
struct B32_size {
    char a[sizeof(B32)+1];
    char b;
};
struct B32_size var292;

#pragma pack(33)
typedef union {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} B33;
B33 var293;
#pragma pack()
struct B33_alignment {
#ifdef MSVC
    char a[_Alignof(B33)];
    char b;
#else
    char a;
    B33 b;
#endif
};
struct B33_alignment var294;
#pragma pack(1)
struct B33_packed {
    B33 a;
};
#pragma pack()
struct B33_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct B33_packed)];
    char b;
#else
    char a;
    struct B33_packed b;
#endif
};
struct B33_required_alignment var295;
struct B33_size {
    char a[sizeof(B33)+1];
    char b;
};
struct B33_size var296;

#pragma pack(34)
typedef union {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} B34;
B34 var297;
#pragma pack()
struct B34_alignment {
#ifdef MSVC
    char a[_Alignof(B34)];
    char b;
#else
    char a;
    B34 b;
#endif
};
struct B34_alignment var298;
#pragma pack(1)
struct B34_packed {
    B34 a;
};
#pragma pack()
struct B34_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct B34_packed)];
    char b;
#else
    char a;
    struct B34_packed b;
#endif
};
struct B34_required_alignment var299;
struct B34_size {
    char a[sizeof(B34)+1];
    char b;
};
struct B34_size var300;

#pragma pack(35)
typedef union {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} B35;
B35 var301;
#pragma pack()
struct B35_alignment {
#ifdef MSVC
    char a[_Alignof(B35)];
    char b;
#else
    char a;
    B35 b;
#endif
};
struct B35_alignment var302;
#pragma pack(1)
struct B35_packed {
    B35 a;
};
#pragma pack()
struct B35_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct B35_packed)];
    char b;
#else
    char a;
    struct B35_packed b;
#endif
};
struct B35_required_alignment var303;
struct B35_size {
    char a[sizeof(B35)+1];
    char b;
};
struct B35_size var304;

#pragma pack(36)
typedef union {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} B36;
B36 var305;
#pragma pack()
struct B36_alignment {
#ifdef MSVC
    char a[_Alignof(B36)];
    char b;
#else
    char a;
    B36 b;
#endif
};
struct B36_alignment var306;
#pragma pack(1)
struct B36_packed {
    B36 a;
};
#pragma pack()
struct B36_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct B36_packed)];
    char b;
#else
    char a;
    struct B36_packed b;
#endif
};
struct B36_required_alignment var307;
struct B36_size {
    char a[sizeof(B36)+1];
    char b;
};
struct B36_size var308;

#pragma pack(37)
typedef union {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} B37;
B37 var309;
#pragma pack()
struct B37_alignment {
#ifdef MSVC
    char a[_Alignof(B37)];
    char b;
#else
    char a;
    B37 b;
#endif
};
struct B37_alignment var310;
#pragma pack(1)
struct B37_packed {
    B37 a;
};
#pragma pack()
struct B37_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct B37_packed)];
    char b;
#else
    char a;
    struct B37_packed b;
#endif
};
struct B37_required_alignment var311;
struct B37_size {
    char a[sizeof(B37)+1];
    char b;
};
struct B37_size var312;

#pragma pack(38)
typedef union {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} B38;
B38 var313;
#pragma pack()
struct B38_alignment {
#ifdef MSVC
    char a[_Alignof(B38)];
    char b;
#else
    char a;
    B38 b;
#endif
};
struct B38_alignment var314;
#pragma pack(1)
struct B38_packed {
    B38 a;
};
#pragma pack()
struct B38_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct B38_packed)];
    char b;
#else
    char a;
    struct B38_packed b;
#endif
};
struct B38_required_alignment var315;
struct B38_size {
    char a[sizeof(B38)+1];
    char b;
};
struct B38_size var316;

#pragma pack(39)
typedef union {
#ifdef MSVC
    __declspec(align(128)) long long l;
#else
    long long l __attribute__((aligned(128)));
#endif
} B39;
B39 var317;
#pragma pack()
struct B39_alignment {
#ifdef MSVC
    char a[_Alignof(B39)];
    char b;
#else
    char a;
    B39 b;
#endif
};
struct B39_alignment var318;
#pragma pack(1)
struct B39_packed {
    B39 a;
};
#pragma pack()
struct B39_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct B39_packed)];
    char b;
#else
    char a;
    struct B39_packed b;
#endif
};
struct B39_required_alignment var319;
struct B39_size {
    char a[sizeof(B39)+1];
    char b;
};
struct B39_size var320;

// MAPPING|ONE|aarch64-generic-macos-none:Clang|aarch64-generic-fuchsia-gnu:Clang|aarch64-generic-linux-android:Clang|aarch64-generic-freebsd-gnu:Clang|aarch64-generic-hermit-eabi:Clang|aarch64-generic-linux-gnu:Gcc|aarch64-generic-linux-musl:Gcc|aarch64-generic-netbsd-gnu:Clang|aarch64-generic-other-none:Clang|aarch64-generic-openbsd-gnu:Clang|aarch64-generic-ios-none:Clang|aarch64-generic-ios-macabi:Clang|aarch64-generic-tvos-none:Clang|arm-baseline-other-eabi:Clang|arm-baseline-other-eabihf:Clang|arm-baseline-linux-gnueabi:Gcc|arm-baseline-linux-gnueabihf:Gcc|arm-arm710t-linux-gnueabi:Gcc|arm-arm1020e-linux-gnueabi:Gcc|arm-arm1136j_s-freebsd-gnu:Clang|arm-arm1136j_s-netbsd-eabihf:Clang|arm-baseline-other-eabi:Clang|arm-baseline-other-eabihf:Clang|arm-cortex_r4-other-eabi:Clang|arm-cortex_r4-other-eabihf:Clang|arm-cortex_r4-freebsd-gnu:Clang|arm-cortex_r4-linux-gnueabi:Gcc|arm-cortex_r4-linux-gnueabihf:Gcc|arm-cortex_r4-netbsd-eabihf:Clang|hexagon-generic-linux-musl:Clang|i386-i686-windows-gnu:Gcc|mips64el-mips64-linux-gnuabi64:Gcc|mips64-mips64-linux-gnuabi64:Gcc|mipsel-mips32-linux-gnu:Gcc|mipsel-mips32-linux-musl:Gcc|mipsel-mips32-other-none:Clang|mips-mips32-linux-gnu:Gcc|mips-mips32r6-linux-gnu:Gcc|mips-mips32-linux-gnuabi64:Gcc|mips-mips64r6-linux-gnuabi64:Gcc|mips-mips32-linux-gnu:Gcc|mips-mips32-linux-musl:Gcc|powerpc64le-ppc64le-linux-gnu:Gcc|powerpc64le-ppc64le-linux-musl:Gcc|powerpc64-ppc64-freebsd-gnu:Clang|powerpc64-ppc64-linux-gnu:Gcc|powerpc64-ppc64-linux-musl:Gcc|powerpc-ppc-linux-gnu:Gcc|powerpc-ppc-linux-musl:Gcc|powerpc-ppc-netbsd-gnu:Clang|riscv32-generic_rv32-other-none:Clang|riscv32-generic_rv32-linux-gnu:Gcc|riscv64-generic_rv64-other-none:Clang|riscv64-generic_rv64-linux-gnu:Gcc|s390x-generic-linux-gnu:Gcc|sparc64-v9-linux-gnu:Gcc|sparc64-v9-netbsd-gnu:Clang|sparc64-v9-openbsd-gnu:Clang|sparc-v8-linux-gnu:Gcc|sparc-v9-solaris-eabi:Clang|thumb-arm710t-other-eabi:Clang|thumb-cortex_m0-other-eabi:Clang|thumb-cortex_m4-other-eabihf:Clang|thumb-cortex_m4-other-eabi:Clang|thumb-cortex_m3-other-eabi:Clang|thumb-baseline-other-eabi:Clang|thumb-cortex_m33-other-eabihf:Clang|thumb-cortex_m33-other-eabi:Clang|wasm32-generic-emscripten-musl:Clang|wasm32-generic-other-none:Clang|wasm32-generic-wasi-musl:Clang|x86_64-x86_64-ios-macabi:Clang|x86_64-x86_64-ios-none:Clang|x86_64-x86_64-macos-none:Clang|x86_64-x86_64-tvos-none:Clang|x86_64-x86_64-fuchsia-gnu:Clang|x86_64-x86_64-linux-android:Clang|x86_64-x86_64-solaris-eabi:Clang|x86_64-x86_64-windows-gnu:Gcc|x86_64-x86_64-dragonfly-eabi:Clang|x86_64-x86_64-freebsd-gnu:Clang|x86_64-x86_64-haiku-gnu:Clang|x86_64-x86_64-hermit-eabi:Clang|x86_64-x86_64-linux-gnux32:Gcc|x86_64-x86_64-linux-gnu:Gcc|x86_64-x86_64-linux-musl:Gcc|x86_64-x86_64-netbsd-gnu:Clang|x86_64-x86_64-openbsd-gnu:Clang|END
// repr targets Aarch64AppleMacosx|Some("aarch64-generic-macos-none") Aarch64Fuchsia|Some("aarch64-generic-fuchsia-gnu") Aarch64LinuxAndroid|Some("aarch64-generic-linux-android") Aarch64UnknownFreebsd|Some("aarch64-generic-freebsd-gnu") Aarch64UnknownHermit|Some("aarch64-generic-hermit-eabi") Aarch64UnknownLinuxGnu|Some("aarch64-generic-linux-gnu") Aarch64UnknownLinuxMusl|Some("aarch64-generic-linux-musl") Aarch64UnknownNetbsd|Some("aarch64-generic-netbsd-gnu") Aarch64UnknownNone|Some("aarch64-generic-other-none") Aarch64UnknownOpenbsd|Some("aarch64-generic-openbsd-gnu") Aarch64UnknownRedox|None Arm64AppleIos|Some("aarch64-generic-ios-none") Arm64AppleIosMacabi|Some("aarch64-generic-ios-macabi") Arm64AppleTvos|Some("aarch64-generic-tvos-none") Armebv7rUnknownNoneEabi|Some("arm-baseline-other-eabi") Armebv7rUnknownNoneEabihf|Some("arm-baseline-other-eabihf") ArmLinuxAndroideabi|None ArmUnknownLinuxGnueabi|Some("arm-baseline-linux-gnueabi") ArmUnknownLinuxGnueabihf|Some("arm-baseline-linux-gnueabihf") Armv4tUnknownLinuxGnueabi|Some("arm-arm710t-linux-gnueabi") Armv5teUnknownLinuxGnueabi|Some("arm-arm1020e-linux-gnueabi") Armv5teUnknownLinuxUclibcgnueabi|None Armv6UnknownFreebsdGnueabihf|Some("arm-arm1136j_s-freebsd-gnu") Armv6UnknownNetbsdelfEabihf|Some("arm-arm1136j_s-netbsd-eabihf") Armv7aNoneEabi|Some("arm-baseline-other-eabi") Armv7aNoneEabihf|Some("arm-baseline-other-eabihf") Armv7NoneLinuxAndroid|None Armv7rUnknownNoneEabi|Some("arm-cortex_r4-other-eabi") Armv7rUnknownNoneEabihf|Some("arm-cortex_r4-other-eabihf") Armv7UnknownFreebsdGnueabihf|Some("arm-cortex_r4-freebsd-gnu") Armv7UnknownLinuxGnueabi|Some("arm-cortex_r4-linux-gnueabi") Armv7UnknownLinuxGnueabihf|Some("arm-cortex_r4-linux-gnueabihf") Armv7UnknownNetbsdelfEabihf|Some("arm-cortex_r4-netbsd-eabihf") HexagonUnknownLinuxMusl|Some("hexagon-generic-linux-musl") I686PcWindowsGnu|Some("i386-i686-windows-gnu") Mips64elUnknownLinuxGnuabi64|Some("mips64el-mips64-linux-gnuabi64") Mips64elUnknownLinuxMusl|None Mips64UnknownLinuxGnuabi64|Some("mips64-mips64-linux-gnuabi64") Mips64UnknownLinuxMusl|None MipselSonyPsp|None MipselUnknownLinuxGnu|Some("mipsel-mips32-linux-gnu") MipselUnknownLinuxMusl|Some("mipsel-mips32-linux-musl") MipselUnknownLinuxUclibc|None MipselUnknownNone|Some("mipsel-mips32-other-none") Mipsisa32r6elUnknownLinuxGnu|Some("mips-mips32-linux-gnu") Mipsisa32r6UnknownLinuxGnu|Some("mips-mips32r6-linux-gnu") Mipsisa64r6elUnknownLinuxGnuabi64|Some("mips-mips32-linux-gnuabi64") Mipsisa64r6UnknownLinuxGnuabi64|Some("mips-mips64r6-linux-gnuabi64") MipsUnknownLinuxGnu|Some("mips-mips32-linux-gnu") MipsUnknownLinuxMusl|Some("mips-mips32-linux-musl") MipsUnknownLinuxUclibc|None Powerpc64leUnknownLinuxGnu|Some("powerpc64le-ppc64le-linux-gnu") Powerpc64leUnknownLinuxMusl|Some("powerpc64le-ppc64le-linux-musl") Powerpc64UnknownFreebsd|Some("powerpc64-ppc64-freebsd-gnu") Powerpc64UnknownLinuxGnu|Some("powerpc64-ppc64-linux-gnu") Powerpc64UnknownLinuxMusl|Some("powerpc64-ppc64-linux-musl") PowerpcUnknownLinuxGnu|Some("powerpc-ppc-linux-gnu") PowerpcUnknownLinuxGnuspe|None PowerpcUnknownLinuxMusl|Some("powerpc-ppc-linux-musl") PowerpcUnknownNetbsd|Some("powerpc-ppc-netbsd-gnu") Riscv32|Some("riscv32-generic_rv32-other-none") Riscv32UnknownLinuxGnu|Some("riscv32-generic_rv32-linux-gnu") Riscv64|Some("riscv64-generic_rv64-other-none") Riscv64UnknownLinuxGnu|Some("riscv64-generic_rv64-linux-gnu") S390xUnknownLinuxGnu|Some("s390x-generic-linux-gnu") Sparc64UnknownLinuxGnu|Some("sparc64-v9-linux-gnu") Sparc64UnknownNetbsd|Some("sparc64-v9-netbsd-gnu") Sparc64UnknownOpenbsd|Some("sparc64-v9-openbsd-gnu") SparcUnknownLinuxGnu|Some("sparc-v8-linux-gnu") Sparcv9SunSolaris|Some("sparc-v9-solaris-eabi") Thumbv4tNoneEabi|Some("thumb-arm710t-other-eabi") Thumbv6mNoneEabi|Some("thumb-cortex_m0-other-eabi") Thumbv7emNoneEabihf|Some("thumb-cortex_m4-other-eabihf") Thumbv7emNoneEabi|Some("thumb-cortex_m4-other-eabi") Thumbv7mNoneEabi|Some("thumb-cortex_m3-other-eabi") Thumbv8mBaseNoneEabi|Some("thumb-baseline-other-eabi") Thumbv8mMainNoneEabihf|Some("thumb-cortex_m33-other-eabihf") Thumbv8mMainNoneEabi|Some("thumb-cortex_m33-other-eabi") Wasm32UnknownEmscripten|Some("wasm32-generic-emscripten-musl") Wasm32UnknownUnknown|Some("wasm32-generic-other-none") Wasm32Wasi|Some("wasm32-generic-wasi-musl") X86_64AppleIosMacabi|Some("x86_64-x86_64-ios-macabi") X86_64AppleIos|Some("x86_64-x86_64-ios-none") X86_64AppleMacosx|Some("x86_64-x86_64-macos-none") X86_64AppleTvos|Some("x86_64-x86_64-tvos-none") X86_64Elf|None X86_64Fuchsia|Some("x86_64-x86_64-fuchsia-gnu") X86_64LinuxAndroid|Some("x86_64-x86_64-linux-android") X86_64PcSolaris|Some("x86_64-x86_64-solaris-eabi") X86_64PcWindowsGnu|Some("x86_64-x86_64-windows-gnu") X86_64RumprunNetbsd|None X86_64UnknownDragonfly|Some("x86_64-x86_64-dragonfly-eabi") X86_64UnknownFreebsd|Some("x86_64-x86_64-freebsd-gnu") X86_64UnknownHaiku|Some("x86_64-x86_64-haiku-gnu") X86_64UnknownHermit|Some("x86_64-x86_64-hermit-eabi") X86_64UnknownL4reUclibc|None X86_64UnknownLinuxGnux32|Some("x86_64-x86_64-linux-gnux32") X86_64UnknownLinuxGnu|Some("x86_64-x86_64-linux-gnu") X86_64UnknownLinuxMusl|Some("x86_64-x86_64-linux-musl") X86_64UnknownNetbsd|Some("x86_64-x86_64-netbsd-gnu") X86_64UnknownOpenbsd|Some("x86_64-x86_64-openbsd-gnu") X86_64UnknownRedox|None 
#ifdef ONE
_Static_assert(sizeof(A00) == 128, "record A00 wrong sizeof");
_Static_assert(_Alignof(A00) == 128, "record A00 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A00_alignment) == 256, "record A00 wrong sizeof");
_Static_assert(_Alignof(struct A00_alignment) == 128, "record A00 wrong alignment");
_Static_assert(sizeof(struct A00_packed) == 128, "record A00 wrong sizeof");
_Static_assert(_Alignof(struct A00_packed) == 1, "record A00 wrong alignment");
_Static_assert(sizeof(struct A00_required_alignment) == 129, "record A00 wrong sizeof");
_Static_assert(_Alignof(struct A00_required_alignment) == 1, "record A00 wrong alignment");
_Static_assert(sizeof(struct A00_size) == 130, "record A00 wrong sizeof");
_Static_assert(_Alignof(struct A00_size) == 1, "record A00 wrong alignment");
#endif
_Static_assert(sizeof(A01) == 8, "record A01 wrong sizeof");
_Static_assert(_Alignof(A01) == 1, "record A01 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A01_alignment) == 9, "record A01 wrong sizeof");
_Static_assert(_Alignof(struct A01_alignment) == 1, "record A01 wrong alignment");
_Static_assert(sizeof(struct A01_packed) == 8, "record A01 wrong sizeof");
_Static_assert(_Alignof(struct A01_packed) == 1, "record A01 wrong alignment");
_Static_assert(sizeof(struct A01_required_alignment) == 9, "record A01 wrong sizeof");
_Static_assert(_Alignof(struct A01_required_alignment) == 1, "record A01 wrong alignment");
_Static_assert(sizeof(struct A01_size) == 10, "record A01 wrong sizeof");
_Static_assert(_Alignof(struct A01_size) == 1, "record A01 wrong alignment");
#endif
_Static_assert(sizeof(A02) == 8, "record A02 wrong sizeof");
_Static_assert(_Alignof(A02) == 2, "record A02 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A02_alignment) == 10, "record A02 wrong sizeof");
_Static_assert(_Alignof(struct A02_alignment) == 2, "record A02 wrong alignment");
_Static_assert(sizeof(struct A02_packed) == 8, "record A02 wrong sizeof");
_Static_assert(_Alignof(struct A02_packed) == 1, "record A02 wrong alignment");
_Static_assert(sizeof(struct A02_required_alignment) == 9, "record A02 wrong sizeof");
_Static_assert(_Alignof(struct A02_required_alignment) == 1, "record A02 wrong alignment");
_Static_assert(sizeof(struct A02_size) == 10, "record A02 wrong sizeof");
_Static_assert(_Alignof(struct A02_size) == 1, "record A02 wrong alignment");
#endif
_Static_assert(sizeof(A03) == 128, "record A03 wrong sizeof");
_Static_assert(_Alignof(A03) == 128, "record A03 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A03_alignment) == 256, "record A03 wrong sizeof");
_Static_assert(_Alignof(struct A03_alignment) == 128, "record A03 wrong alignment");
_Static_assert(sizeof(struct A03_packed) == 128, "record A03 wrong sizeof");
_Static_assert(_Alignof(struct A03_packed) == 1, "record A03 wrong alignment");
_Static_assert(sizeof(struct A03_required_alignment) == 129, "record A03 wrong sizeof");
_Static_assert(_Alignof(struct A03_required_alignment) == 1, "record A03 wrong alignment");
_Static_assert(sizeof(struct A03_size) == 130, "record A03 wrong sizeof");
_Static_assert(_Alignof(struct A03_size) == 1, "record A03 wrong alignment");
#endif
_Static_assert(sizeof(A04) == 8, "record A04 wrong sizeof");
_Static_assert(_Alignof(A04) == 4, "record A04 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A04_alignment) == 12, "record A04 wrong sizeof");
_Static_assert(_Alignof(struct A04_alignment) == 4, "record A04 wrong alignment");
_Static_assert(sizeof(struct A04_packed) == 8, "record A04 wrong sizeof");
_Static_assert(_Alignof(struct A04_packed) == 1, "record A04 wrong alignment");
_Static_assert(sizeof(struct A04_required_alignment) == 9, "record A04 wrong sizeof");
_Static_assert(_Alignof(struct A04_required_alignment) == 1, "record A04 wrong alignment");
_Static_assert(sizeof(struct A04_size) == 10, "record A04 wrong sizeof");
_Static_assert(_Alignof(struct A04_size) == 1, "record A04 wrong alignment");
#endif
_Static_assert(sizeof(A05) == 128, "record A05 wrong sizeof");
_Static_assert(_Alignof(A05) == 128, "record A05 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A05_alignment) == 256, "record A05 wrong sizeof");
_Static_assert(_Alignof(struct A05_alignment) == 128, "record A05 wrong alignment");
_Static_assert(sizeof(struct A05_packed) == 128, "record A05 wrong sizeof");
_Static_assert(_Alignof(struct A05_packed) == 1, "record A05 wrong alignment");
_Static_assert(sizeof(struct A05_required_alignment) == 129, "record A05 wrong sizeof");
_Static_assert(_Alignof(struct A05_required_alignment) == 1, "record A05 wrong alignment");
_Static_assert(sizeof(struct A05_size) == 130, "record A05 wrong sizeof");
_Static_assert(_Alignof(struct A05_size) == 1, "record A05 wrong alignment");
#endif
_Static_assert(sizeof(A06) == 128, "record A06 wrong sizeof");
_Static_assert(_Alignof(A06) == 128, "record A06 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A06_alignment) == 256, "record A06 wrong sizeof");
_Static_assert(_Alignof(struct A06_alignment) == 128, "record A06 wrong alignment");
_Static_assert(sizeof(struct A06_packed) == 128, "record A06 wrong sizeof");
_Static_assert(_Alignof(struct A06_packed) == 1, "record A06 wrong alignment");
_Static_assert(sizeof(struct A06_required_alignment) == 129, "record A06 wrong sizeof");
_Static_assert(_Alignof(struct A06_required_alignment) == 1, "record A06 wrong alignment");
_Static_assert(sizeof(struct A06_size) == 130, "record A06 wrong sizeof");
_Static_assert(_Alignof(struct A06_size) == 1, "record A06 wrong alignment");
#endif
_Static_assert(sizeof(A07) == 128, "record A07 wrong sizeof");
_Static_assert(_Alignof(A07) == 128, "record A07 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A07_alignment) == 256, "record A07 wrong sizeof");
_Static_assert(_Alignof(struct A07_alignment) == 128, "record A07 wrong alignment");
_Static_assert(sizeof(struct A07_packed) == 128, "record A07 wrong sizeof");
_Static_assert(_Alignof(struct A07_packed) == 1, "record A07 wrong alignment");
_Static_assert(sizeof(struct A07_required_alignment) == 129, "record A07 wrong sizeof");
_Static_assert(_Alignof(struct A07_required_alignment) == 1, "record A07 wrong alignment");
_Static_assert(sizeof(struct A07_size) == 130, "record A07 wrong sizeof");
_Static_assert(_Alignof(struct A07_size) == 1, "record A07 wrong alignment");
#endif
_Static_assert(sizeof(A08) == 8, "record A08 wrong sizeof");
_Static_assert(_Alignof(A08) == 8, "record A08 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A08_alignment) == 16, "record A08 wrong sizeof");
_Static_assert(_Alignof(struct A08_alignment) == 8, "record A08 wrong alignment");
_Static_assert(sizeof(struct A08_packed) == 8, "record A08 wrong sizeof");
_Static_assert(_Alignof(struct A08_packed) == 1, "record A08 wrong alignment");
_Static_assert(sizeof(struct A08_required_alignment) == 9, "record A08 wrong sizeof");
_Static_assert(_Alignof(struct A08_required_alignment) == 1, "record A08 wrong alignment");
_Static_assert(sizeof(struct A08_size) == 10, "record A08 wrong sizeof");
_Static_assert(_Alignof(struct A08_size) == 1, "record A08 wrong alignment");
#endif
_Static_assert(sizeof(A09) == 128, "record A09 wrong sizeof");
_Static_assert(_Alignof(A09) == 128, "record A09 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A09_alignment) == 256, "record A09 wrong sizeof");
_Static_assert(_Alignof(struct A09_alignment) == 128, "record A09 wrong alignment");
_Static_assert(sizeof(struct A09_packed) == 128, "record A09 wrong sizeof");
_Static_assert(_Alignof(struct A09_packed) == 1, "record A09 wrong alignment");
_Static_assert(sizeof(struct A09_required_alignment) == 129, "record A09 wrong sizeof");
_Static_assert(_Alignof(struct A09_required_alignment) == 1, "record A09 wrong alignment");
_Static_assert(sizeof(struct A09_size) == 130, "record A09 wrong sizeof");
_Static_assert(_Alignof(struct A09_size) == 1, "record A09 wrong alignment");
#endif
_Static_assert(sizeof(A10) == 128, "record A10 wrong sizeof");
_Static_assert(_Alignof(A10) == 128, "record A10 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A10_alignment) == 256, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_alignment) == 128, "record A10 wrong alignment");
_Static_assert(sizeof(struct A10_packed) == 128, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_packed) == 1, "record A10 wrong alignment");
_Static_assert(sizeof(struct A10_required_alignment) == 129, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_required_alignment) == 1, "record A10 wrong alignment");
_Static_assert(sizeof(struct A10_size) == 130, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_size) == 1, "record A10 wrong alignment");
#endif
_Static_assert(sizeof(A11) == 128, "record A11 wrong sizeof");
_Static_assert(_Alignof(A11) == 128, "record A11 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A11_alignment) == 256, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_alignment) == 128, "record A11 wrong alignment");
_Static_assert(sizeof(struct A11_packed) == 128, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_packed) == 1, "record A11 wrong alignment");
_Static_assert(sizeof(struct A11_required_alignment) == 129, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_required_alignment) == 1, "record A11 wrong alignment");
_Static_assert(sizeof(struct A11_size) == 130, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_size) == 1, "record A11 wrong alignment");
#endif
_Static_assert(sizeof(A12) == 128, "record A12 wrong sizeof");
_Static_assert(_Alignof(A12) == 128, "record A12 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A12_alignment) == 256, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_alignment) == 128, "record A12 wrong alignment");
_Static_assert(sizeof(struct A12_packed) == 128, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_packed) == 1, "record A12 wrong alignment");
_Static_assert(sizeof(struct A12_required_alignment) == 129, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_required_alignment) == 1, "record A12 wrong alignment");
_Static_assert(sizeof(struct A12_size) == 130, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_size) == 1, "record A12 wrong alignment");
#endif
_Static_assert(sizeof(A13) == 128, "record A13 wrong sizeof");
_Static_assert(_Alignof(A13) == 128, "record A13 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A13_alignment) == 256, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_alignment) == 128, "record A13 wrong alignment");
_Static_assert(sizeof(struct A13_packed) == 128, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_packed) == 1, "record A13 wrong alignment");
_Static_assert(sizeof(struct A13_required_alignment) == 129, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_required_alignment) == 1, "record A13 wrong alignment");
_Static_assert(sizeof(struct A13_size) == 130, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_size) == 1, "record A13 wrong alignment");
#endif
_Static_assert(sizeof(A14) == 128, "record A14 wrong sizeof");
_Static_assert(_Alignof(A14) == 128, "record A14 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A14_alignment) == 256, "record A14 wrong sizeof");
_Static_assert(_Alignof(struct A14_alignment) == 128, "record A14 wrong alignment");
_Static_assert(sizeof(struct A14_packed) == 128, "record A14 wrong sizeof");
_Static_assert(_Alignof(struct A14_packed) == 1, "record A14 wrong alignment");
_Static_assert(sizeof(struct A14_required_alignment) == 129, "record A14 wrong sizeof");
_Static_assert(_Alignof(struct A14_required_alignment) == 1, "record A14 wrong alignment");
_Static_assert(sizeof(struct A14_size) == 130, "record A14 wrong sizeof");
_Static_assert(_Alignof(struct A14_size) == 1, "record A14 wrong alignment");
#endif
_Static_assert(sizeof(A15) == 128, "record A15 wrong sizeof");
_Static_assert(_Alignof(A15) == 128, "record A15 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A15_alignment) == 256, "record A15 wrong sizeof");
_Static_assert(_Alignof(struct A15_alignment) == 128, "record A15 wrong alignment");
_Static_assert(sizeof(struct A15_packed) == 128, "record A15 wrong sizeof");
_Static_assert(_Alignof(struct A15_packed) == 1, "record A15 wrong alignment");
_Static_assert(sizeof(struct A15_required_alignment) == 129, "record A15 wrong sizeof");
_Static_assert(_Alignof(struct A15_required_alignment) == 1, "record A15 wrong alignment");
_Static_assert(sizeof(struct A15_size) == 130, "record A15 wrong sizeof");
_Static_assert(_Alignof(struct A15_size) == 1, "record A15 wrong alignment");
#endif
_Static_assert(sizeof(A16) == 16, "record A16 wrong sizeof");
_Static_assert(_Alignof(A16) == 16, "record A16 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A16_alignment) == 32, "record A16 wrong sizeof");
_Static_assert(_Alignof(struct A16_alignment) == 16, "record A16 wrong alignment");
_Static_assert(sizeof(struct A16_packed) == 16, "record A16 wrong sizeof");
_Static_assert(_Alignof(struct A16_packed) == 1, "record A16 wrong alignment");
_Static_assert(sizeof(struct A16_required_alignment) == 17, "record A16 wrong sizeof");
_Static_assert(_Alignof(struct A16_required_alignment) == 1, "record A16 wrong alignment");
_Static_assert(sizeof(struct A16_size) == 18, "record A16 wrong sizeof");
_Static_assert(_Alignof(struct A16_size) == 1, "record A16 wrong alignment");
#endif
_Static_assert(sizeof(A17) == 128, "record A17 wrong sizeof");
_Static_assert(_Alignof(A17) == 128, "record A17 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A17_alignment) == 256, "record A17 wrong sizeof");
_Static_assert(_Alignof(struct A17_alignment) == 128, "record A17 wrong alignment");
_Static_assert(sizeof(struct A17_packed) == 128, "record A17 wrong sizeof");
_Static_assert(_Alignof(struct A17_packed) == 1, "record A17 wrong alignment");
_Static_assert(sizeof(struct A17_required_alignment) == 129, "record A17 wrong sizeof");
_Static_assert(_Alignof(struct A17_required_alignment) == 1, "record A17 wrong alignment");
_Static_assert(sizeof(struct A17_size) == 130, "record A17 wrong sizeof");
_Static_assert(_Alignof(struct A17_size) == 1, "record A17 wrong alignment");
#endif
_Static_assert(sizeof(A18) == 128, "record A18 wrong sizeof");
_Static_assert(_Alignof(A18) == 128, "record A18 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A18_alignment) == 256, "record A18 wrong sizeof");
_Static_assert(_Alignof(struct A18_alignment) == 128, "record A18 wrong alignment");
_Static_assert(sizeof(struct A18_packed) == 128, "record A18 wrong sizeof");
_Static_assert(_Alignof(struct A18_packed) == 1, "record A18 wrong alignment");
_Static_assert(sizeof(struct A18_required_alignment) == 129, "record A18 wrong sizeof");
_Static_assert(_Alignof(struct A18_required_alignment) == 1, "record A18 wrong alignment");
_Static_assert(sizeof(struct A18_size) == 130, "record A18 wrong sizeof");
_Static_assert(_Alignof(struct A18_size) == 1, "record A18 wrong alignment");
#endif
_Static_assert(sizeof(A19) == 128, "record A19 wrong sizeof");
_Static_assert(_Alignof(A19) == 128, "record A19 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A19_alignment) == 256, "record A19 wrong sizeof");
_Static_assert(_Alignof(struct A19_alignment) == 128, "record A19 wrong alignment");
_Static_assert(sizeof(struct A19_packed) == 128, "record A19 wrong sizeof");
_Static_assert(_Alignof(struct A19_packed) == 1, "record A19 wrong alignment");
_Static_assert(sizeof(struct A19_required_alignment) == 129, "record A19 wrong sizeof");
_Static_assert(_Alignof(struct A19_required_alignment) == 1, "record A19 wrong alignment");
_Static_assert(sizeof(struct A19_size) == 130, "record A19 wrong sizeof");
_Static_assert(_Alignof(struct A19_size) == 1, "record A19 wrong alignment");
#endif
_Static_assert(sizeof(A20) == 128, "record A20 wrong sizeof");
_Static_assert(_Alignof(A20) == 128, "record A20 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A20_alignment) == 256, "record A20 wrong sizeof");
_Static_assert(_Alignof(struct A20_alignment) == 128, "record A20 wrong alignment");
_Static_assert(sizeof(struct A20_packed) == 128, "record A20 wrong sizeof");
_Static_assert(_Alignof(struct A20_packed) == 1, "record A20 wrong alignment");
_Static_assert(sizeof(struct A20_required_alignment) == 129, "record A20 wrong sizeof");
_Static_assert(_Alignof(struct A20_required_alignment) == 1, "record A20 wrong alignment");
_Static_assert(sizeof(struct A20_size) == 130, "record A20 wrong sizeof");
_Static_assert(_Alignof(struct A20_size) == 1, "record A20 wrong alignment");
#endif
_Static_assert(sizeof(A21) == 128, "record A21 wrong sizeof");
_Static_assert(_Alignof(A21) == 128, "record A21 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A21_alignment) == 256, "record A21 wrong sizeof");
_Static_assert(_Alignof(struct A21_alignment) == 128, "record A21 wrong alignment");
_Static_assert(sizeof(struct A21_packed) == 128, "record A21 wrong sizeof");
_Static_assert(_Alignof(struct A21_packed) == 1, "record A21 wrong alignment");
_Static_assert(sizeof(struct A21_required_alignment) == 129, "record A21 wrong sizeof");
_Static_assert(_Alignof(struct A21_required_alignment) == 1, "record A21 wrong alignment");
_Static_assert(sizeof(struct A21_size) == 130, "record A21 wrong sizeof");
_Static_assert(_Alignof(struct A21_size) == 1, "record A21 wrong alignment");
#endif
_Static_assert(sizeof(A22) == 128, "record A22 wrong sizeof");
_Static_assert(_Alignof(A22) == 128, "record A22 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A22_alignment) == 256, "record A22 wrong sizeof");
_Static_assert(_Alignof(struct A22_alignment) == 128, "record A22 wrong alignment");
_Static_assert(sizeof(struct A22_packed) == 128, "record A22 wrong sizeof");
_Static_assert(_Alignof(struct A22_packed) == 1, "record A22 wrong alignment");
_Static_assert(sizeof(struct A22_required_alignment) == 129, "record A22 wrong sizeof");
_Static_assert(_Alignof(struct A22_required_alignment) == 1, "record A22 wrong alignment");
_Static_assert(sizeof(struct A22_size) == 130, "record A22 wrong sizeof");
_Static_assert(_Alignof(struct A22_size) == 1, "record A22 wrong alignment");
#endif
_Static_assert(sizeof(A23) == 128, "record A23 wrong sizeof");
_Static_assert(_Alignof(A23) == 128, "record A23 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A23_alignment) == 256, "record A23 wrong sizeof");
_Static_assert(_Alignof(struct A23_alignment) == 128, "record A23 wrong alignment");
_Static_assert(sizeof(struct A23_packed) == 128, "record A23 wrong sizeof");
_Static_assert(_Alignof(struct A23_packed) == 1, "record A23 wrong alignment");
_Static_assert(sizeof(struct A23_required_alignment) == 129, "record A23 wrong sizeof");
_Static_assert(_Alignof(struct A23_required_alignment) == 1, "record A23 wrong alignment");
_Static_assert(sizeof(struct A23_size) == 130, "record A23 wrong sizeof");
_Static_assert(_Alignof(struct A23_size) == 1, "record A23 wrong alignment");
#endif
_Static_assert(sizeof(A24) == 128, "record A24 wrong sizeof");
_Static_assert(_Alignof(A24) == 128, "record A24 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A24_alignment) == 256, "record A24 wrong sizeof");
_Static_assert(_Alignof(struct A24_alignment) == 128, "record A24 wrong alignment");
_Static_assert(sizeof(struct A24_packed) == 128, "record A24 wrong sizeof");
_Static_assert(_Alignof(struct A24_packed) == 1, "record A24 wrong alignment");
_Static_assert(sizeof(struct A24_required_alignment) == 129, "record A24 wrong sizeof");
_Static_assert(_Alignof(struct A24_required_alignment) == 1, "record A24 wrong alignment");
_Static_assert(sizeof(struct A24_size) == 130, "record A24 wrong sizeof");
_Static_assert(_Alignof(struct A24_size) == 1, "record A24 wrong alignment");
#endif
_Static_assert(sizeof(A25) == 128, "record A25 wrong sizeof");
_Static_assert(_Alignof(A25) == 128, "record A25 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A25_alignment) == 256, "record A25 wrong sizeof");
_Static_assert(_Alignof(struct A25_alignment) == 128, "record A25 wrong alignment");
_Static_assert(sizeof(struct A25_packed) == 128, "record A25 wrong sizeof");
_Static_assert(_Alignof(struct A25_packed) == 1, "record A25 wrong alignment");
_Static_assert(sizeof(struct A25_required_alignment) == 129, "record A25 wrong sizeof");
_Static_assert(_Alignof(struct A25_required_alignment) == 1, "record A25 wrong alignment");
_Static_assert(sizeof(struct A25_size) == 130, "record A25 wrong sizeof");
_Static_assert(_Alignof(struct A25_size) == 1, "record A25 wrong alignment");
#endif
_Static_assert(sizeof(A26) == 128, "record A26 wrong sizeof");
_Static_assert(_Alignof(A26) == 128, "record A26 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A26_alignment) == 256, "record A26 wrong sizeof");
_Static_assert(_Alignof(struct A26_alignment) == 128, "record A26 wrong alignment");
_Static_assert(sizeof(struct A26_packed) == 128, "record A26 wrong sizeof");
_Static_assert(_Alignof(struct A26_packed) == 1, "record A26 wrong alignment");
_Static_assert(sizeof(struct A26_required_alignment) == 129, "record A26 wrong sizeof");
_Static_assert(_Alignof(struct A26_required_alignment) == 1, "record A26 wrong alignment");
_Static_assert(sizeof(struct A26_size) == 130, "record A26 wrong sizeof");
_Static_assert(_Alignof(struct A26_size) == 1, "record A26 wrong alignment");
#endif
_Static_assert(sizeof(A27) == 128, "record A27 wrong sizeof");
_Static_assert(_Alignof(A27) == 128, "record A27 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A27_alignment) == 256, "record A27 wrong sizeof");
_Static_assert(_Alignof(struct A27_alignment) == 128, "record A27 wrong alignment");
_Static_assert(sizeof(struct A27_packed) == 128, "record A27 wrong sizeof");
_Static_assert(_Alignof(struct A27_packed) == 1, "record A27 wrong alignment");
_Static_assert(sizeof(struct A27_required_alignment) == 129, "record A27 wrong sizeof");
_Static_assert(_Alignof(struct A27_required_alignment) == 1, "record A27 wrong alignment");
_Static_assert(sizeof(struct A27_size) == 130, "record A27 wrong sizeof");
_Static_assert(_Alignof(struct A27_size) == 1, "record A27 wrong alignment");
#endif
_Static_assert(sizeof(A28) == 128, "record A28 wrong sizeof");
_Static_assert(_Alignof(A28) == 128, "record A28 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A28_alignment) == 256, "record A28 wrong sizeof");
_Static_assert(_Alignof(struct A28_alignment) == 128, "record A28 wrong alignment");
_Static_assert(sizeof(struct A28_packed) == 128, "record A28 wrong sizeof");
_Static_assert(_Alignof(struct A28_packed) == 1, "record A28 wrong alignment");
_Static_assert(sizeof(struct A28_required_alignment) == 129, "record A28 wrong sizeof");
_Static_assert(_Alignof(struct A28_required_alignment) == 1, "record A28 wrong alignment");
_Static_assert(sizeof(struct A28_size) == 130, "record A28 wrong sizeof");
_Static_assert(_Alignof(struct A28_size) == 1, "record A28 wrong alignment");
#endif
_Static_assert(sizeof(A29) == 128, "record A29 wrong sizeof");
_Static_assert(_Alignof(A29) == 128, "record A29 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A29_alignment) == 256, "record A29 wrong sizeof");
_Static_assert(_Alignof(struct A29_alignment) == 128, "record A29 wrong alignment");
_Static_assert(sizeof(struct A29_packed) == 128, "record A29 wrong sizeof");
_Static_assert(_Alignof(struct A29_packed) == 1, "record A29 wrong alignment");
_Static_assert(sizeof(struct A29_required_alignment) == 129, "record A29 wrong sizeof");
_Static_assert(_Alignof(struct A29_required_alignment) == 1, "record A29 wrong alignment");
_Static_assert(sizeof(struct A29_size) == 130, "record A29 wrong sizeof");
_Static_assert(_Alignof(struct A29_size) == 1, "record A29 wrong alignment");
#endif
_Static_assert(sizeof(A30) == 128, "record A30 wrong sizeof");
_Static_assert(_Alignof(A30) == 128, "record A30 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A30_alignment) == 256, "record A30 wrong sizeof");
_Static_assert(_Alignof(struct A30_alignment) == 128, "record A30 wrong alignment");
_Static_assert(sizeof(struct A30_packed) == 128, "record A30 wrong sizeof");
_Static_assert(_Alignof(struct A30_packed) == 1, "record A30 wrong alignment");
_Static_assert(sizeof(struct A30_required_alignment) == 129, "record A30 wrong sizeof");
_Static_assert(_Alignof(struct A30_required_alignment) == 1, "record A30 wrong alignment");
_Static_assert(sizeof(struct A30_size) == 130, "record A30 wrong sizeof");
_Static_assert(_Alignof(struct A30_size) == 1, "record A30 wrong alignment");
#endif
_Static_assert(sizeof(A31) == 128, "record A31 wrong sizeof");
_Static_assert(_Alignof(A31) == 128, "record A31 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A31_alignment) == 256, "record A31 wrong sizeof");
_Static_assert(_Alignof(struct A31_alignment) == 128, "record A31 wrong alignment");
_Static_assert(sizeof(struct A31_packed) == 128, "record A31 wrong sizeof");
_Static_assert(_Alignof(struct A31_packed) == 1, "record A31 wrong alignment");
_Static_assert(sizeof(struct A31_required_alignment) == 129, "record A31 wrong sizeof");
_Static_assert(_Alignof(struct A31_required_alignment) == 1, "record A31 wrong alignment");
_Static_assert(sizeof(struct A31_size) == 130, "record A31 wrong sizeof");
_Static_assert(_Alignof(struct A31_size) == 1, "record A31 wrong alignment");
#endif
_Static_assert(sizeof(A32) == 128, "record A32 wrong sizeof");
_Static_assert(_Alignof(A32) == 128, "record A32 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A32_alignment) == 256, "record A32 wrong sizeof");
_Static_assert(_Alignof(struct A32_alignment) == 128, "record A32 wrong alignment");
_Static_assert(sizeof(struct A32_packed) == 128, "record A32 wrong sizeof");
_Static_assert(_Alignof(struct A32_packed) == 1, "record A32 wrong alignment");
_Static_assert(sizeof(struct A32_required_alignment) == 129, "record A32 wrong sizeof");
_Static_assert(_Alignof(struct A32_required_alignment) == 1, "record A32 wrong alignment");
_Static_assert(sizeof(struct A32_size) == 130, "record A32 wrong sizeof");
_Static_assert(_Alignof(struct A32_size) == 1, "record A32 wrong alignment");
#endif
_Static_assert(sizeof(A33) == 128, "record A33 wrong sizeof");
_Static_assert(_Alignof(A33) == 128, "record A33 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A33_alignment) == 256, "record A33 wrong sizeof");
_Static_assert(_Alignof(struct A33_alignment) == 128, "record A33 wrong alignment");
_Static_assert(sizeof(struct A33_packed) == 128, "record A33 wrong sizeof");
_Static_assert(_Alignof(struct A33_packed) == 1, "record A33 wrong alignment");
_Static_assert(sizeof(struct A33_required_alignment) == 129, "record A33 wrong sizeof");
_Static_assert(_Alignof(struct A33_required_alignment) == 1, "record A33 wrong alignment");
_Static_assert(sizeof(struct A33_size) == 130, "record A33 wrong sizeof");
_Static_assert(_Alignof(struct A33_size) == 1, "record A33 wrong alignment");
#endif
_Static_assert(sizeof(A34) == 128, "record A34 wrong sizeof");
_Static_assert(_Alignof(A34) == 128, "record A34 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A34_alignment) == 256, "record A34 wrong sizeof");
_Static_assert(_Alignof(struct A34_alignment) == 128, "record A34 wrong alignment");
_Static_assert(sizeof(struct A34_packed) == 128, "record A34 wrong sizeof");
_Static_assert(_Alignof(struct A34_packed) == 1, "record A34 wrong alignment");
_Static_assert(sizeof(struct A34_required_alignment) == 129, "record A34 wrong sizeof");
_Static_assert(_Alignof(struct A34_required_alignment) == 1, "record A34 wrong alignment");
_Static_assert(sizeof(struct A34_size) == 130, "record A34 wrong sizeof");
_Static_assert(_Alignof(struct A34_size) == 1, "record A34 wrong alignment");
#endif
_Static_assert(sizeof(A35) == 128, "record A35 wrong sizeof");
_Static_assert(_Alignof(A35) == 128, "record A35 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A35_alignment) == 256, "record A35 wrong sizeof");
_Static_assert(_Alignof(struct A35_alignment) == 128, "record A35 wrong alignment");
_Static_assert(sizeof(struct A35_packed) == 128, "record A35 wrong sizeof");
_Static_assert(_Alignof(struct A35_packed) == 1, "record A35 wrong alignment");
_Static_assert(sizeof(struct A35_required_alignment) == 129, "record A35 wrong sizeof");
_Static_assert(_Alignof(struct A35_required_alignment) == 1, "record A35 wrong alignment");
_Static_assert(sizeof(struct A35_size) == 130, "record A35 wrong sizeof");
_Static_assert(_Alignof(struct A35_size) == 1, "record A35 wrong alignment");
#endif
_Static_assert(sizeof(A36) == 128, "record A36 wrong sizeof");
_Static_assert(_Alignof(A36) == 128, "record A36 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A36_alignment) == 256, "record A36 wrong sizeof");
_Static_assert(_Alignof(struct A36_alignment) == 128, "record A36 wrong alignment");
_Static_assert(sizeof(struct A36_packed) == 128, "record A36 wrong sizeof");
_Static_assert(_Alignof(struct A36_packed) == 1, "record A36 wrong alignment");
_Static_assert(sizeof(struct A36_required_alignment) == 129, "record A36 wrong sizeof");
_Static_assert(_Alignof(struct A36_required_alignment) == 1, "record A36 wrong alignment");
_Static_assert(sizeof(struct A36_size) == 130, "record A36 wrong sizeof");
_Static_assert(_Alignof(struct A36_size) == 1, "record A36 wrong alignment");
#endif
_Static_assert(sizeof(A37) == 128, "record A37 wrong sizeof");
_Static_assert(_Alignof(A37) == 128, "record A37 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A37_alignment) == 256, "record A37 wrong sizeof");
_Static_assert(_Alignof(struct A37_alignment) == 128, "record A37 wrong alignment");
_Static_assert(sizeof(struct A37_packed) == 128, "record A37 wrong sizeof");
_Static_assert(_Alignof(struct A37_packed) == 1, "record A37 wrong alignment");
_Static_assert(sizeof(struct A37_required_alignment) == 129, "record A37 wrong sizeof");
_Static_assert(_Alignof(struct A37_required_alignment) == 1, "record A37 wrong alignment");
_Static_assert(sizeof(struct A37_size) == 130, "record A37 wrong sizeof");
_Static_assert(_Alignof(struct A37_size) == 1, "record A37 wrong alignment");
#endif
_Static_assert(sizeof(A38) == 128, "record A38 wrong sizeof");
_Static_assert(_Alignof(A38) == 128, "record A38 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A38_alignment) == 256, "record A38 wrong sizeof");
_Static_assert(_Alignof(struct A38_alignment) == 128, "record A38 wrong alignment");
_Static_assert(sizeof(struct A38_packed) == 128, "record A38 wrong sizeof");
_Static_assert(_Alignof(struct A38_packed) == 1, "record A38 wrong alignment");
_Static_assert(sizeof(struct A38_required_alignment) == 129, "record A38 wrong sizeof");
_Static_assert(_Alignof(struct A38_required_alignment) == 1, "record A38 wrong alignment");
_Static_assert(sizeof(struct A38_size) == 130, "record A38 wrong sizeof");
_Static_assert(_Alignof(struct A38_size) == 1, "record A38 wrong alignment");
#endif
_Static_assert(sizeof(A39) == 128, "record A39 wrong sizeof");
_Static_assert(_Alignof(A39) == 128, "record A39 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A39_alignment) == 256, "record A39 wrong sizeof");
_Static_assert(_Alignof(struct A39_alignment) == 128, "record A39 wrong alignment");
_Static_assert(sizeof(struct A39_packed) == 128, "record A39 wrong sizeof");
_Static_assert(_Alignof(struct A39_packed) == 1, "record A39 wrong alignment");
_Static_assert(sizeof(struct A39_required_alignment) == 129, "record A39 wrong sizeof");
_Static_assert(_Alignof(struct A39_required_alignment) == 1, "record A39 wrong alignment");
_Static_assert(sizeof(struct A39_size) == 130, "record A39 wrong sizeof");
_Static_assert(_Alignof(struct A39_size) == 1, "record A39 wrong alignment");
#endif
_Static_assert(sizeof(B00) == 128, "record B00 wrong sizeof");
_Static_assert(_Alignof(B00) == 128, "record B00 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B00_alignment) == 256, "record B00 wrong sizeof");
_Static_assert(_Alignof(struct B00_alignment) == 128, "record B00 wrong alignment");
_Static_assert(sizeof(struct B00_packed) == 128, "record B00 wrong sizeof");
_Static_assert(_Alignof(struct B00_packed) == 1, "record B00 wrong alignment");
_Static_assert(sizeof(struct B00_required_alignment) == 129, "record B00 wrong sizeof");
_Static_assert(_Alignof(struct B00_required_alignment) == 1, "record B00 wrong alignment");
_Static_assert(sizeof(struct B00_size) == 130, "record B00 wrong sizeof");
_Static_assert(_Alignof(struct B00_size) == 1, "record B00 wrong alignment");
#endif
_Static_assert(sizeof(B01) == 8, "record B01 wrong sizeof");
_Static_assert(_Alignof(B01) == 1, "record B01 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B01_alignment) == 9, "record B01 wrong sizeof");
_Static_assert(_Alignof(struct B01_alignment) == 1, "record B01 wrong alignment");
_Static_assert(sizeof(struct B01_packed) == 8, "record B01 wrong sizeof");
_Static_assert(_Alignof(struct B01_packed) == 1, "record B01 wrong alignment");
_Static_assert(sizeof(struct B01_required_alignment) == 9, "record B01 wrong sizeof");
_Static_assert(_Alignof(struct B01_required_alignment) == 1, "record B01 wrong alignment");
_Static_assert(sizeof(struct B01_size) == 10, "record B01 wrong sizeof");
_Static_assert(_Alignof(struct B01_size) == 1, "record B01 wrong alignment");
#endif
_Static_assert(sizeof(B02) == 8, "record B02 wrong sizeof");
_Static_assert(_Alignof(B02) == 2, "record B02 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B02_alignment) == 10, "record B02 wrong sizeof");
_Static_assert(_Alignof(struct B02_alignment) == 2, "record B02 wrong alignment");
_Static_assert(sizeof(struct B02_packed) == 8, "record B02 wrong sizeof");
_Static_assert(_Alignof(struct B02_packed) == 1, "record B02 wrong alignment");
_Static_assert(sizeof(struct B02_required_alignment) == 9, "record B02 wrong sizeof");
_Static_assert(_Alignof(struct B02_required_alignment) == 1, "record B02 wrong alignment");
_Static_assert(sizeof(struct B02_size) == 10, "record B02 wrong sizeof");
_Static_assert(_Alignof(struct B02_size) == 1, "record B02 wrong alignment");
#endif
_Static_assert(sizeof(B03) == 128, "record B03 wrong sizeof");
_Static_assert(_Alignof(B03) == 128, "record B03 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B03_alignment) == 256, "record B03 wrong sizeof");
_Static_assert(_Alignof(struct B03_alignment) == 128, "record B03 wrong alignment");
_Static_assert(sizeof(struct B03_packed) == 128, "record B03 wrong sizeof");
_Static_assert(_Alignof(struct B03_packed) == 1, "record B03 wrong alignment");
_Static_assert(sizeof(struct B03_required_alignment) == 129, "record B03 wrong sizeof");
_Static_assert(_Alignof(struct B03_required_alignment) == 1, "record B03 wrong alignment");
_Static_assert(sizeof(struct B03_size) == 130, "record B03 wrong sizeof");
_Static_assert(_Alignof(struct B03_size) == 1, "record B03 wrong alignment");
#endif
_Static_assert(sizeof(B04) == 8, "record B04 wrong sizeof");
_Static_assert(_Alignof(B04) == 4, "record B04 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B04_alignment) == 12, "record B04 wrong sizeof");
_Static_assert(_Alignof(struct B04_alignment) == 4, "record B04 wrong alignment");
_Static_assert(sizeof(struct B04_packed) == 8, "record B04 wrong sizeof");
_Static_assert(_Alignof(struct B04_packed) == 1, "record B04 wrong alignment");
_Static_assert(sizeof(struct B04_required_alignment) == 9, "record B04 wrong sizeof");
_Static_assert(_Alignof(struct B04_required_alignment) == 1, "record B04 wrong alignment");
_Static_assert(sizeof(struct B04_size) == 10, "record B04 wrong sizeof");
_Static_assert(_Alignof(struct B04_size) == 1, "record B04 wrong alignment");
#endif
_Static_assert(sizeof(B05) == 128, "record B05 wrong sizeof");
_Static_assert(_Alignof(B05) == 128, "record B05 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B05_alignment) == 256, "record B05 wrong sizeof");
_Static_assert(_Alignof(struct B05_alignment) == 128, "record B05 wrong alignment");
_Static_assert(sizeof(struct B05_packed) == 128, "record B05 wrong sizeof");
_Static_assert(_Alignof(struct B05_packed) == 1, "record B05 wrong alignment");
_Static_assert(sizeof(struct B05_required_alignment) == 129, "record B05 wrong sizeof");
_Static_assert(_Alignof(struct B05_required_alignment) == 1, "record B05 wrong alignment");
_Static_assert(sizeof(struct B05_size) == 130, "record B05 wrong sizeof");
_Static_assert(_Alignof(struct B05_size) == 1, "record B05 wrong alignment");
#endif
_Static_assert(sizeof(B06) == 128, "record B06 wrong sizeof");
_Static_assert(_Alignof(B06) == 128, "record B06 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B06_alignment) == 256, "record B06 wrong sizeof");
_Static_assert(_Alignof(struct B06_alignment) == 128, "record B06 wrong alignment");
_Static_assert(sizeof(struct B06_packed) == 128, "record B06 wrong sizeof");
_Static_assert(_Alignof(struct B06_packed) == 1, "record B06 wrong alignment");
_Static_assert(sizeof(struct B06_required_alignment) == 129, "record B06 wrong sizeof");
_Static_assert(_Alignof(struct B06_required_alignment) == 1, "record B06 wrong alignment");
_Static_assert(sizeof(struct B06_size) == 130, "record B06 wrong sizeof");
_Static_assert(_Alignof(struct B06_size) == 1, "record B06 wrong alignment");
#endif
_Static_assert(sizeof(B07) == 128, "record B07 wrong sizeof");
_Static_assert(_Alignof(B07) == 128, "record B07 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B07_alignment) == 256, "record B07 wrong sizeof");
_Static_assert(_Alignof(struct B07_alignment) == 128, "record B07 wrong alignment");
_Static_assert(sizeof(struct B07_packed) == 128, "record B07 wrong sizeof");
_Static_assert(_Alignof(struct B07_packed) == 1, "record B07 wrong alignment");
_Static_assert(sizeof(struct B07_required_alignment) == 129, "record B07 wrong sizeof");
_Static_assert(_Alignof(struct B07_required_alignment) == 1, "record B07 wrong alignment");
_Static_assert(sizeof(struct B07_size) == 130, "record B07 wrong sizeof");
_Static_assert(_Alignof(struct B07_size) == 1, "record B07 wrong alignment");
#endif
_Static_assert(sizeof(B08) == 8, "record B08 wrong sizeof");
_Static_assert(_Alignof(B08) == 8, "record B08 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B08_alignment) == 16, "record B08 wrong sizeof");
_Static_assert(_Alignof(struct B08_alignment) == 8, "record B08 wrong alignment");
_Static_assert(sizeof(struct B08_packed) == 8, "record B08 wrong sizeof");
_Static_assert(_Alignof(struct B08_packed) == 1, "record B08 wrong alignment");
_Static_assert(sizeof(struct B08_required_alignment) == 9, "record B08 wrong sizeof");
_Static_assert(_Alignof(struct B08_required_alignment) == 1, "record B08 wrong alignment");
_Static_assert(sizeof(struct B08_size) == 10, "record B08 wrong sizeof");
_Static_assert(_Alignof(struct B08_size) == 1, "record B08 wrong alignment");
#endif
_Static_assert(sizeof(B09) == 128, "record B09 wrong sizeof");
_Static_assert(_Alignof(B09) == 128, "record B09 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B09_alignment) == 256, "record B09 wrong sizeof");
_Static_assert(_Alignof(struct B09_alignment) == 128, "record B09 wrong alignment");
_Static_assert(sizeof(struct B09_packed) == 128, "record B09 wrong sizeof");
_Static_assert(_Alignof(struct B09_packed) == 1, "record B09 wrong alignment");
_Static_assert(sizeof(struct B09_required_alignment) == 129, "record B09 wrong sizeof");
_Static_assert(_Alignof(struct B09_required_alignment) == 1, "record B09 wrong alignment");
_Static_assert(sizeof(struct B09_size) == 130, "record B09 wrong sizeof");
_Static_assert(_Alignof(struct B09_size) == 1, "record B09 wrong alignment");
#endif
_Static_assert(sizeof(B10) == 128, "record B10 wrong sizeof");
_Static_assert(_Alignof(B10) == 128, "record B10 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B10_alignment) == 256, "record B10 wrong sizeof");
_Static_assert(_Alignof(struct B10_alignment) == 128, "record B10 wrong alignment");
_Static_assert(sizeof(struct B10_packed) == 128, "record B10 wrong sizeof");
_Static_assert(_Alignof(struct B10_packed) == 1, "record B10 wrong alignment");
_Static_assert(sizeof(struct B10_required_alignment) == 129, "record B10 wrong sizeof");
_Static_assert(_Alignof(struct B10_required_alignment) == 1, "record B10 wrong alignment");
_Static_assert(sizeof(struct B10_size) == 130, "record B10 wrong sizeof");
_Static_assert(_Alignof(struct B10_size) == 1, "record B10 wrong alignment");
#endif
_Static_assert(sizeof(B11) == 128, "record B11 wrong sizeof");
_Static_assert(_Alignof(B11) == 128, "record B11 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B11_alignment) == 256, "record B11 wrong sizeof");
_Static_assert(_Alignof(struct B11_alignment) == 128, "record B11 wrong alignment");
_Static_assert(sizeof(struct B11_packed) == 128, "record B11 wrong sizeof");
_Static_assert(_Alignof(struct B11_packed) == 1, "record B11 wrong alignment");
_Static_assert(sizeof(struct B11_required_alignment) == 129, "record B11 wrong sizeof");
_Static_assert(_Alignof(struct B11_required_alignment) == 1, "record B11 wrong alignment");
_Static_assert(sizeof(struct B11_size) == 130, "record B11 wrong sizeof");
_Static_assert(_Alignof(struct B11_size) == 1, "record B11 wrong alignment");
#endif
_Static_assert(sizeof(B12) == 128, "record B12 wrong sizeof");
_Static_assert(_Alignof(B12) == 128, "record B12 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B12_alignment) == 256, "record B12 wrong sizeof");
_Static_assert(_Alignof(struct B12_alignment) == 128, "record B12 wrong alignment");
_Static_assert(sizeof(struct B12_packed) == 128, "record B12 wrong sizeof");
_Static_assert(_Alignof(struct B12_packed) == 1, "record B12 wrong alignment");
_Static_assert(sizeof(struct B12_required_alignment) == 129, "record B12 wrong sizeof");
_Static_assert(_Alignof(struct B12_required_alignment) == 1, "record B12 wrong alignment");
_Static_assert(sizeof(struct B12_size) == 130, "record B12 wrong sizeof");
_Static_assert(_Alignof(struct B12_size) == 1, "record B12 wrong alignment");
#endif
_Static_assert(sizeof(B13) == 128, "record B13 wrong sizeof");
_Static_assert(_Alignof(B13) == 128, "record B13 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B13_alignment) == 256, "record B13 wrong sizeof");
_Static_assert(_Alignof(struct B13_alignment) == 128, "record B13 wrong alignment");
_Static_assert(sizeof(struct B13_packed) == 128, "record B13 wrong sizeof");
_Static_assert(_Alignof(struct B13_packed) == 1, "record B13 wrong alignment");
_Static_assert(sizeof(struct B13_required_alignment) == 129, "record B13 wrong sizeof");
_Static_assert(_Alignof(struct B13_required_alignment) == 1, "record B13 wrong alignment");
_Static_assert(sizeof(struct B13_size) == 130, "record B13 wrong sizeof");
_Static_assert(_Alignof(struct B13_size) == 1, "record B13 wrong alignment");
#endif
_Static_assert(sizeof(B14) == 128, "record B14 wrong sizeof");
_Static_assert(_Alignof(B14) == 128, "record B14 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B14_alignment) == 256, "record B14 wrong sizeof");
_Static_assert(_Alignof(struct B14_alignment) == 128, "record B14 wrong alignment");
_Static_assert(sizeof(struct B14_packed) == 128, "record B14 wrong sizeof");
_Static_assert(_Alignof(struct B14_packed) == 1, "record B14 wrong alignment");
_Static_assert(sizeof(struct B14_required_alignment) == 129, "record B14 wrong sizeof");
_Static_assert(_Alignof(struct B14_required_alignment) == 1, "record B14 wrong alignment");
_Static_assert(sizeof(struct B14_size) == 130, "record B14 wrong sizeof");
_Static_assert(_Alignof(struct B14_size) == 1, "record B14 wrong alignment");
#endif
_Static_assert(sizeof(B15) == 128, "record B15 wrong sizeof");
_Static_assert(_Alignof(B15) == 128, "record B15 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B15_alignment) == 256, "record B15 wrong sizeof");
_Static_assert(_Alignof(struct B15_alignment) == 128, "record B15 wrong alignment");
_Static_assert(sizeof(struct B15_packed) == 128, "record B15 wrong sizeof");
_Static_assert(_Alignof(struct B15_packed) == 1, "record B15 wrong alignment");
_Static_assert(sizeof(struct B15_required_alignment) == 129, "record B15 wrong sizeof");
_Static_assert(_Alignof(struct B15_required_alignment) == 1, "record B15 wrong alignment");
_Static_assert(sizeof(struct B15_size) == 130, "record B15 wrong sizeof");
_Static_assert(_Alignof(struct B15_size) == 1, "record B15 wrong alignment");
#endif
_Static_assert(sizeof(B16) == 16, "record B16 wrong sizeof");
_Static_assert(_Alignof(B16) == 16, "record B16 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B16_alignment) == 32, "record B16 wrong sizeof");
_Static_assert(_Alignof(struct B16_alignment) == 16, "record B16 wrong alignment");
_Static_assert(sizeof(struct B16_packed) == 16, "record B16 wrong sizeof");
_Static_assert(_Alignof(struct B16_packed) == 1, "record B16 wrong alignment");
_Static_assert(sizeof(struct B16_required_alignment) == 17, "record B16 wrong sizeof");
_Static_assert(_Alignof(struct B16_required_alignment) == 1, "record B16 wrong alignment");
_Static_assert(sizeof(struct B16_size) == 18, "record B16 wrong sizeof");
_Static_assert(_Alignof(struct B16_size) == 1, "record B16 wrong alignment");
#endif
_Static_assert(sizeof(B17) == 128, "record B17 wrong sizeof");
_Static_assert(_Alignof(B17) == 128, "record B17 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B17_alignment) == 256, "record B17 wrong sizeof");
_Static_assert(_Alignof(struct B17_alignment) == 128, "record B17 wrong alignment");
_Static_assert(sizeof(struct B17_packed) == 128, "record B17 wrong sizeof");
_Static_assert(_Alignof(struct B17_packed) == 1, "record B17 wrong alignment");
_Static_assert(sizeof(struct B17_required_alignment) == 129, "record B17 wrong sizeof");
_Static_assert(_Alignof(struct B17_required_alignment) == 1, "record B17 wrong alignment");
_Static_assert(sizeof(struct B17_size) == 130, "record B17 wrong sizeof");
_Static_assert(_Alignof(struct B17_size) == 1, "record B17 wrong alignment");
#endif
_Static_assert(sizeof(B18) == 128, "record B18 wrong sizeof");
_Static_assert(_Alignof(B18) == 128, "record B18 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B18_alignment) == 256, "record B18 wrong sizeof");
_Static_assert(_Alignof(struct B18_alignment) == 128, "record B18 wrong alignment");
_Static_assert(sizeof(struct B18_packed) == 128, "record B18 wrong sizeof");
_Static_assert(_Alignof(struct B18_packed) == 1, "record B18 wrong alignment");
_Static_assert(sizeof(struct B18_required_alignment) == 129, "record B18 wrong sizeof");
_Static_assert(_Alignof(struct B18_required_alignment) == 1, "record B18 wrong alignment");
_Static_assert(sizeof(struct B18_size) == 130, "record B18 wrong sizeof");
_Static_assert(_Alignof(struct B18_size) == 1, "record B18 wrong alignment");
#endif
_Static_assert(sizeof(B19) == 128, "record B19 wrong sizeof");
_Static_assert(_Alignof(B19) == 128, "record B19 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B19_alignment) == 256, "record B19 wrong sizeof");
_Static_assert(_Alignof(struct B19_alignment) == 128, "record B19 wrong alignment");
_Static_assert(sizeof(struct B19_packed) == 128, "record B19 wrong sizeof");
_Static_assert(_Alignof(struct B19_packed) == 1, "record B19 wrong alignment");
_Static_assert(sizeof(struct B19_required_alignment) == 129, "record B19 wrong sizeof");
_Static_assert(_Alignof(struct B19_required_alignment) == 1, "record B19 wrong alignment");
_Static_assert(sizeof(struct B19_size) == 130, "record B19 wrong sizeof");
_Static_assert(_Alignof(struct B19_size) == 1, "record B19 wrong alignment");
#endif
_Static_assert(sizeof(B20) == 128, "record B20 wrong sizeof");
_Static_assert(_Alignof(B20) == 128, "record B20 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B20_alignment) == 256, "record B20 wrong sizeof");
_Static_assert(_Alignof(struct B20_alignment) == 128, "record B20 wrong alignment");
_Static_assert(sizeof(struct B20_packed) == 128, "record B20 wrong sizeof");
_Static_assert(_Alignof(struct B20_packed) == 1, "record B20 wrong alignment");
_Static_assert(sizeof(struct B20_required_alignment) == 129, "record B20 wrong sizeof");
_Static_assert(_Alignof(struct B20_required_alignment) == 1, "record B20 wrong alignment");
_Static_assert(sizeof(struct B20_size) == 130, "record B20 wrong sizeof");
_Static_assert(_Alignof(struct B20_size) == 1, "record B20 wrong alignment");
#endif
_Static_assert(sizeof(B21) == 128, "record B21 wrong sizeof");
_Static_assert(_Alignof(B21) == 128, "record B21 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B21_alignment) == 256, "record B21 wrong sizeof");
_Static_assert(_Alignof(struct B21_alignment) == 128, "record B21 wrong alignment");
_Static_assert(sizeof(struct B21_packed) == 128, "record B21 wrong sizeof");
_Static_assert(_Alignof(struct B21_packed) == 1, "record B21 wrong alignment");
_Static_assert(sizeof(struct B21_required_alignment) == 129, "record B21 wrong sizeof");
_Static_assert(_Alignof(struct B21_required_alignment) == 1, "record B21 wrong alignment");
_Static_assert(sizeof(struct B21_size) == 130, "record B21 wrong sizeof");
_Static_assert(_Alignof(struct B21_size) == 1, "record B21 wrong alignment");
#endif
_Static_assert(sizeof(B22) == 128, "record B22 wrong sizeof");
_Static_assert(_Alignof(B22) == 128, "record B22 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B22_alignment) == 256, "record B22 wrong sizeof");
_Static_assert(_Alignof(struct B22_alignment) == 128, "record B22 wrong alignment");
_Static_assert(sizeof(struct B22_packed) == 128, "record B22 wrong sizeof");
_Static_assert(_Alignof(struct B22_packed) == 1, "record B22 wrong alignment");
_Static_assert(sizeof(struct B22_required_alignment) == 129, "record B22 wrong sizeof");
_Static_assert(_Alignof(struct B22_required_alignment) == 1, "record B22 wrong alignment");
_Static_assert(sizeof(struct B22_size) == 130, "record B22 wrong sizeof");
_Static_assert(_Alignof(struct B22_size) == 1, "record B22 wrong alignment");
#endif
_Static_assert(sizeof(B23) == 128, "record B23 wrong sizeof");
_Static_assert(_Alignof(B23) == 128, "record B23 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B23_alignment) == 256, "record B23 wrong sizeof");
_Static_assert(_Alignof(struct B23_alignment) == 128, "record B23 wrong alignment");
_Static_assert(sizeof(struct B23_packed) == 128, "record B23 wrong sizeof");
_Static_assert(_Alignof(struct B23_packed) == 1, "record B23 wrong alignment");
_Static_assert(sizeof(struct B23_required_alignment) == 129, "record B23 wrong sizeof");
_Static_assert(_Alignof(struct B23_required_alignment) == 1, "record B23 wrong alignment");
_Static_assert(sizeof(struct B23_size) == 130, "record B23 wrong sizeof");
_Static_assert(_Alignof(struct B23_size) == 1, "record B23 wrong alignment");
#endif
_Static_assert(sizeof(B24) == 128, "record B24 wrong sizeof");
_Static_assert(_Alignof(B24) == 128, "record B24 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B24_alignment) == 256, "record B24 wrong sizeof");
_Static_assert(_Alignof(struct B24_alignment) == 128, "record B24 wrong alignment");
_Static_assert(sizeof(struct B24_packed) == 128, "record B24 wrong sizeof");
_Static_assert(_Alignof(struct B24_packed) == 1, "record B24 wrong alignment");
_Static_assert(sizeof(struct B24_required_alignment) == 129, "record B24 wrong sizeof");
_Static_assert(_Alignof(struct B24_required_alignment) == 1, "record B24 wrong alignment");
_Static_assert(sizeof(struct B24_size) == 130, "record B24 wrong sizeof");
_Static_assert(_Alignof(struct B24_size) == 1, "record B24 wrong alignment");
#endif
_Static_assert(sizeof(B25) == 128, "record B25 wrong sizeof");
_Static_assert(_Alignof(B25) == 128, "record B25 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B25_alignment) == 256, "record B25 wrong sizeof");
_Static_assert(_Alignof(struct B25_alignment) == 128, "record B25 wrong alignment");
_Static_assert(sizeof(struct B25_packed) == 128, "record B25 wrong sizeof");
_Static_assert(_Alignof(struct B25_packed) == 1, "record B25 wrong alignment");
_Static_assert(sizeof(struct B25_required_alignment) == 129, "record B25 wrong sizeof");
_Static_assert(_Alignof(struct B25_required_alignment) == 1, "record B25 wrong alignment");
_Static_assert(sizeof(struct B25_size) == 130, "record B25 wrong sizeof");
_Static_assert(_Alignof(struct B25_size) == 1, "record B25 wrong alignment");
#endif
_Static_assert(sizeof(B26) == 128, "record B26 wrong sizeof");
_Static_assert(_Alignof(B26) == 128, "record B26 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B26_alignment) == 256, "record B26 wrong sizeof");
_Static_assert(_Alignof(struct B26_alignment) == 128, "record B26 wrong alignment");
_Static_assert(sizeof(struct B26_packed) == 128, "record B26 wrong sizeof");
_Static_assert(_Alignof(struct B26_packed) == 1, "record B26 wrong alignment");
_Static_assert(sizeof(struct B26_required_alignment) == 129, "record B26 wrong sizeof");
_Static_assert(_Alignof(struct B26_required_alignment) == 1, "record B26 wrong alignment");
_Static_assert(sizeof(struct B26_size) == 130, "record B26 wrong sizeof");
_Static_assert(_Alignof(struct B26_size) == 1, "record B26 wrong alignment");
#endif
_Static_assert(sizeof(B27) == 128, "record B27 wrong sizeof");
_Static_assert(_Alignof(B27) == 128, "record B27 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B27_alignment) == 256, "record B27 wrong sizeof");
_Static_assert(_Alignof(struct B27_alignment) == 128, "record B27 wrong alignment");
_Static_assert(sizeof(struct B27_packed) == 128, "record B27 wrong sizeof");
_Static_assert(_Alignof(struct B27_packed) == 1, "record B27 wrong alignment");
_Static_assert(sizeof(struct B27_required_alignment) == 129, "record B27 wrong sizeof");
_Static_assert(_Alignof(struct B27_required_alignment) == 1, "record B27 wrong alignment");
_Static_assert(sizeof(struct B27_size) == 130, "record B27 wrong sizeof");
_Static_assert(_Alignof(struct B27_size) == 1, "record B27 wrong alignment");
#endif
_Static_assert(sizeof(B28) == 128, "record B28 wrong sizeof");
_Static_assert(_Alignof(B28) == 128, "record B28 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B28_alignment) == 256, "record B28 wrong sizeof");
_Static_assert(_Alignof(struct B28_alignment) == 128, "record B28 wrong alignment");
_Static_assert(sizeof(struct B28_packed) == 128, "record B28 wrong sizeof");
_Static_assert(_Alignof(struct B28_packed) == 1, "record B28 wrong alignment");
_Static_assert(sizeof(struct B28_required_alignment) == 129, "record B28 wrong sizeof");
_Static_assert(_Alignof(struct B28_required_alignment) == 1, "record B28 wrong alignment");
_Static_assert(sizeof(struct B28_size) == 130, "record B28 wrong sizeof");
_Static_assert(_Alignof(struct B28_size) == 1, "record B28 wrong alignment");
#endif
_Static_assert(sizeof(B29) == 128, "record B29 wrong sizeof");
_Static_assert(_Alignof(B29) == 128, "record B29 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B29_alignment) == 256, "record B29 wrong sizeof");
_Static_assert(_Alignof(struct B29_alignment) == 128, "record B29 wrong alignment");
_Static_assert(sizeof(struct B29_packed) == 128, "record B29 wrong sizeof");
_Static_assert(_Alignof(struct B29_packed) == 1, "record B29 wrong alignment");
_Static_assert(sizeof(struct B29_required_alignment) == 129, "record B29 wrong sizeof");
_Static_assert(_Alignof(struct B29_required_alignment) == 1, "record B29 wrong alignment");
_Static_assert(sizeof(struct B29_size) == 130, "record B29 wrong sizeof");
_Static_assert(_Alignof(struct B29_size) == 1, "record B29 wrong alignment");
#endif
_Static_assert(sizeof(B30) == 128, "record B30 wrong sizeof");
_Static_assert(_Alignof(B30) == 128, "record B30 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B30_alignment) == 256, "record B30 wrong sizeof");
_Static_assert(_Alignof(struct B30_alignment) == 128, "record B30 wrong alignment");
_Static_assert(sizeof(struct B30_packed) == 128, "record B30 wrong sizeof");
_Static_assert(_Alignof(struct B30_packed) == 1, "record B30 wrong alignment");
_Static_assert(sizeof(struct B30_required_alignment) == 129, "record B30 wrong sizeof");
_Static_assert(_Alignof(struct B30_required_alignment) == 1, "record B30 wrong alignment");
_Static_assert(sizeof(struct B30_size) == 130, "record B30 wrong sizeof");
_Static_assert(_Alignof(struct B30_size) == 1, "record B30 wrong alignment");
#endif
_Static_assert(sizeof(B31) == 128, "record B31 wrong sizeof");
_Static_assert(_Alignof(B31) == 128, "record B31 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B31_alignment) == 256, "record B31 wrong sizeof");
_Static_assert(_Alignof(struct B31_alignment) == 128, "record B31 wrong alignment");
_Static_assert(sizeof(struct B31_packed) == 128, "record B31 wrong sizeof");
_Static_assert(_Alignof(struct B31_packed) == 1, "record B31 wrong alignment");
_Static_assert(sizeof(struct B31_required_alignment) == 129, "record B31 wrong sizeof");
_Static_assert(_Alignof(struct B31_required_alignment) == 1, "record B31 wrong alignment");
_Static_assert(sizeof(struct B31_size) == 130, "record B31 wrong sizeof");
_Static_assert(_Alignof(struct B31_size) == 1, "record B31 wrong alignment");
#endif
_Static_assert(sizeof(B32) == 128, "record B32 wrong sizeof");
_Static_assert(_Alignof(B32) == 128, "record B32 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B32_alignment) == 256, "record B32 wrong sizeof");
_Static_assert(_Alignof(struct B32_alignment) == 128, "record B32 wrong alignment");
_Static_assert(sizeof(struct B32_packed) == 128, "record B32 wrong sizeof");
_Static_assert(_Alignof(struct B32_packed) == 1, "record B32 wrong alignment");
_Static_assert(sizeof(struct B32_required_alignment) == 129, "record B32 wrong sizeof");
_Static_assert(_Alignof(struct B32_required_alignment) == 1, "record B32 wrong alignment");
_Static_assert(sizeof(struct B32_size) == 130, "record B32 wrong sizeof");
_Static_assert(_Alignof(struct B32_size) == 1, "record B32 wrong alignment");
#endif
_Static_assert(sizeof(B33) == 128, "record B33 wrong sizeof");
_Static_assert(_Alignof(B33) == 128, "record B33 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B33_alignment) == 256, "record B33 wrong sizeof");
_Static_assert(_Alignof(struct B33_alignment) == 128, "record B33 wrong alignment");
_Static_assert(sizeof(struct B33_packed) == 128, "record B33 wrong sizeof");
_Static_assert(_Alignof(struct B33_packed) == 1, "record B33 wrong alignment");
_Static_assert(sizeof(struct B33_required_alignment) == 129, "record B33 wrong sizeof");
_Static_assert(_Alignof(struct B33_required_alignment) == 1, "record B33 wrong alignment");
_Static_assert(sizeof(struct B33_size) == 130, "record B33 wrong sizeof");
_Static_assert(_Alignof(struct B33_size) == 1, "record B33 wrong alignment");
#endif
_Static_assert(sizeof(B34) == 128, "record B34 wrong sizeof");
_Static_assert(_Alignof(B34) == 128, "record B34 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B34_alignment) == 256, "record B34 wrong sizeof");
_Static_assert(_Alignof(struct B34_alignment) == 128, "record B34 wrong alignment");
_Static_assert(sizeof(struct B34_packed) == 128, "record B34 wrong sizeof");
_Static_assert(_Alignof(struct B34_packed) == 1, "record B34 wrong alignment");
_Static_assert(sizeof(struct B34_required_alignment) == 129, "record B34 wrong sizeof");
_Static_assert(_Alignof(struct B34_required_alignment) == 1, "record B34 wrong alignment");
_Static_assert(sizeof(struct B34_size) == 130, "record B34 wrong sizeof");
_Static_assert(_Alignof(struct B34_size) == 1, "record B34 wrong alignment");
#endif
_Static_assert(sizeof(B35) == 128, "record B35 wrong sizeof");
_Static_assert(_Alignof(B35) == 128, "record B35 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B35_alignment) == 256, "record B35 wrong sizeof");
_Static_assert(_Alignof(struct B35_alignment) == 128, "record B35 wrong alignment");
_Static_assert(sizeof(struct B35_packed) == 128, "record B35 wrong sizeof");
_Static_assert(_Alignof(struct B35_packed) == 1, "record B35 wrong alignment");
_Static_assert(sizeof(struct B35_required_alignment) == 129, "record B35 wrong sizeof");
_Static_assert(_Alignof(struct B35_required_alignment) == 1, "record B35 wrong alignment");
_Static_assert(sizeof(struct B35_size) == 130, "record B35 wrong sizeof");
_Static_assert(_Alignof(struct B35_size) == 1, "record B35 wrong alignment");
#endif
_Static_assert(sizeof(B36) == 128, "record B36 wrong sizeof");
_Static_assert(_Alignof(B36) == 128, "record B36 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B36_alignment) == 256, "record B36 wrong sizeof");
_Static_assert(_Alignof(struct B36_alignment) == 128, "record B36 wrong alignment");
_Static_assert(sizeof(struct B36_packed) == 128, "record B36 wrong sizeof");
_Static_assert(_Alignof(struct B36_packed) == 1, "record B36 wrong alignment");
_Static_assert(sizeof(struct B36_required_alignment) == 129, "record B36 wrong sizeof");
_Static_assert(_Alignof(struct B36_required_alignment) == 1, "record B36 wrong alignment");
_Static_assert(sizeof(struct B36_size) == 130, "record B36 wrong sizeof");
_Static_assert(_Alignof(struct B36_size) == 1, "record B36 wrong alignment");
#endif
_Static_assert(sizeof(B37) == 128, "record B37 wrong sizeof");
_Static_assert(_Alignof(B37) == 128, "record B37 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B37_alignment) == 256, "record B37 wrong sizeof");
_Static_assert(_Alignof(struct B37_alignment) == 128, "record B37 wrong alignment");
_Static_assert(sizeof(struct B37_packed) == 128, "record B37 wrong sizeof");
_Static_assert(_Alignof(struct B37_packed) == 1, "record B37 wrong alignment");
_Static_assert(sizeof(struct B37_required_alignment) == 129, "record B37 wrong sizeof");
_Static_assert(_Alignof(struct B37_required_alignment) == 1, "record B37 wrong alignment");
_Static_assert(sizeof(struct B37_size) == 130, "record B37 wrong sizeof");
_Static_assert(_Alignof(struct B37_size) == 1, "record B37 wrong alignment");
#endif
_Static_assert(sizeof(B38) == 128, "record B38 wrong sizeof");
_Static_assert(_Alignof(B38) == 128, "record B38 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B38_alignment) == 256, "record B38 wrong sizeof");
_Static_assert(_Alignof(struct B38_alignment) == 128, "record B38 wrong alignment");
_Static_assert(sizeof(struct B38_packed) == 128, "record B38 wrong sizeof");
_Static_assert(_Alignof(struct B38_packed) == 1, "record B38 wrong alignment");
_Static_assert(sizeof(struct B38_required_alignment) == 129, "record B38 wrong sizeof");
_Static_assert(_Alignof(struct B38_required_alignment) == 1, "record B38 wrong alignment");
_Static_assert(sizeof(struct B38_size) == 130, "record B38 wrong sizeof");
_Static_assert(_Alignof(struct B38_size) == 1, "record B38 wrong alignment");
#endif
_Static_assert(sizeof(B39) == 128, "record B39 wrong sizeof");
_Static_assert(_Alignof(B39) == 128, "record B39 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B39_alignment) == 256, "record B39 wrong sizeof");
_Static_assert(_Alignof(struct B39_alignment) == 128, "record B39 wrong alignment");
_Static_assert(sizeof(struct B39_packed) == 128, "record B39 wrong sizeof");
_Static_assert(_Alignof(struct B39_packed) == 1, "record B39 wrong alignment");
_Static_assert(sizeof(struct B39_required_alignment) == 129, "record B39 wrong sizeof");
_Static_assert(_Alignof(struct B39_required_alignment) == 1, "record B39 wrong alignment");
_Static_assert(sizeof(struct B39_size) == 130, "record B39 wrong sizeof");
_Static_assert(_Alignof(struct B39_size) == 1, "record B39 wrong alignment");
#endif
// MAPPING|TWO|aarch64-generic-windows-msvc:Msvc|i386-i586-windows-msvc:Msvc|i386-i686-windows-msvc:Msvc|i386-i686-uefi-msvc:Msvc|thumb-baseline-windows-msvc:Msvc|x86_64-x86_64-windows-msvc:Msvc|x86_64-x86_64-uefi-msvc:Msvc|END
// repr targets Aarch64PcWindowsMsvc|Some("aarch64-generic-windows-msvc") I586PcWindowsMsvc|Some("i386-i586-windows-msvc") I686PcWindowsMsvc|Some("i386-i686-windows-msvc") I686UnknownWindows|Some("i386-i686-uefi-msvc") Thumbv7aPcWindowsMsvc|Some("thumb-baseline-windows-msvc") X86_64PcWindowsMsvc|Some("x86_64-x86_64-windows-msvc") X86_64UnknownWindows|Some("x86_64-x86_64-uefi-msvc") 
#elif defined(TWO)
_Static_assert(sizeof(A00) == 128, "record A00 wrong sizeof");
_Static_assert(_Alignof(A00) == 128, "record A00 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A00_alignment) == 256, "record A00 wrong sizeof");
_Static_assert(_Alignof(struct A00_alignment) == 128, "record A00 wrong alignment");
_Static_assert(sizeof(struct A00_packed) == 128, "record A00 wrong sizeof");
_Static_assert(_Alignof(struct A00_packed) == 1, "record A00 wrong alignment");
_Static_assert(sizeof(struct A00_required_alignment) == 129, "record A00 wrong sizeof");
_Static_assert(_Alignof(struct A00_required_alignment) == 1, "record A00 wrong alignment");
_Static_assert(sizeof(struct A00_size) == 130, "record A00 wrong sizeof");
_Static_assert(_Alignof(struct A00_size) == 1, "record A00 wrong alignment");
#endif
_Static_assert(sizeof(A01) == 128, "record A01 wrong sizeof");
_Static_assert(_Alignof(A01) == 128, "record A01 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A01_alignment) == 256, "record A01 wrong sizeof");
_Static_assert(_Alignof(struct A01_alignment) == 128, "record A01 wrong alignment");
_Static_assert(sizeof(struct A01_packed) == 128, "record A01 wrong sizeof");
_Static_assert(_Alignof(struct A01_packed) == 1, "record A01 wrong alignment");
_Static_assert(sizeof(struct A01_required_alignment) == 129, "record A01 wrong sizeof");
_Static_assert(_Alignof(struct A01_required_alignment) == 1, "record A01 wrong alignment");
_Static_assert(sizeof(struct A01_size) == 130, "record A01 wrong sizeof");
_Static_assert(_Alignof(struct A01_size) == 1, "record A01 wrong alignment");
#endif
_Static_assert(sizeof(A02) == 128, "record A02 wrong sizeof");
_Static_assert(_Alignof(A02) == 128, "record A02 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A02_alignment) == 256, "record A02 wrong sizeof");
_Static_assert(_Alignof(struct A02_alignment) == 128, "record A02 wrong alignment");
_Static_assert(sizeof(struct A02_packed) == 128, "record A02 wrong sizeof");
_Static_assert(_Alignof(struct A02_packed) == 1, "record A02 wrong alignment");
_Static_assert(sizeof(struct A02_required_alignment) == 129, "record A02 wrong sizeof");
_Static_assert(_Alignof(struct A02_required_alignment) == 1, "record A02 wrong alignment");
_Static_assert(sizeof(struct A02_size) == 130, "record A02 wrong sizeof");
_Static_assert(_Alignof(struct A02_size) == 1, "record A02 wrong alignment");
#endif
_Static_assert(sizeof(A03) == 128, "record A03 wrong sizeof");
_Static_assert(_Alignof(A03) == 128, "record A03 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A03_alignment) == 256, "record A03 wrong sizeof");
_Static_assert(_Alignof(struct A03_alignment) == 128, "record A03 wrong alignment");
_Static_assert(sizeof(struct A03_packed) == 128, "record A03 wrong sizeof");
_Static_assert(_Alignof(struct A03_packed) == 1, "record A03 wrong alignment");
_Static_assert(sizeof(struct A03_required_alignment) == 129, "record A03 wrong sizeof");
_Static_assert(_Alignof(struct A03_required_alignment) == 1, "record A03 wrong alignment");
_Static_assert(sizeof(struct A03_size) == 130, "record A03 wrong sizeof");
_Static_assert(_Alignof(struct A03_size) == 1, "record A03 wrong alignment");
#endif
_Static_assert(sizeof(A04) == 128, "record A04 wrong sizeof");
_Static_assert(_Alignof(A04) == 128, "record A04 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A04_alignment) == 256, "record A04 wrong sizeof");
_Static_assert(_Alignof(struct A04_alignment) == 128, "record A04 wrong alignment");
_Static_assert(sizeof(struct A04_packed) == 128, "record A04 wrong sizeof");
_Static_assert(_Alignof(struct A04_packed) == 1, "record A04 wrong alignment");
_Static_assert(sizeof(struct A04_required_alignment) == 129, "record A04 wrong sizeof");
_Static_assert(_Alignof(struct A04_required_alignment) == 1, "record A04 wrong alignment");
_Static_assert(sizeof(struct A04_size) == 130, "record A04 wrong sizeof");
_Static_assert(_Alignof(struct A04_size) == 1, "record A04 wrong alignment");
#endif
_Static_assert(sizeof(A05) == 128, "record A05 wrong sizeof");
_Static_assert(_Alignof(A05) == 128, "record A05 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A05_alignment) == 256, "record A05 wrong sizeof");
_Static_assert(_Alignof(struct A05_alignment) == 128, "record A05 wrong alignment");
_Static_assert(sizeof(struct A05_packed) == 128, "record A05 wrong sizeof");
_Static_assert(_Alignof(struct A05_packed) == 1, "record A05 wrong alignment");
_Static_assert(sizeof(struct A05_required_alignment) == 129, "record A05 wrong sizeof");
_Static_assert(_Alignof(struct A05_required_alignment) == 1, "record A05 wrong alignment");
_Static_assert(sizeof(struct A05_size) == 130, "record A05 wrong sizeof");
_Static_assert(_Alignof(struct A05_size) == 1, "record A05 wrong alignment");
#endif
_Static_assert(sizeof(A06) == 128, "record A06 wrong sizeof");
_Static_assert(_Alignof(A06) == 128, "record A06 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A06_alignment) == 256, "record A06 wrong sizeof");
_Static_assert(_Alignof(struct A06_alignment) == 128, "record A06 wrong alignment");
_Static_assert(sizeof(struct A06_packed) == 128, "record A06 wrong sizeof");
_Static_assert(_Alignof(struct A06_packed) == 1, "record A06 wrong alignment");
_Static_assert(sizeof(struct A06_required_alignment) == 129, "record A06 wrong sizeof");
_Static_assert(_Alignof(struct A06_required_alignment) == 1, "record A06 wrong alignment");
_Static_assert(sizeof(struct A06_size) == 130, "record A06 wrong sizeof");
_Static_assert(_Alignof(struct A06_size) == 1, "record A06 wrong alignment");
#endif
_Static_assert(sizeof(A07) == 128, "record A07 wrong sizeof");
_Static_assert(_Alignof(A07) == 128, "record A07 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A07_alignment) == 256, "record A07 wrong sizeof");
_Static_assert(_Alignof(struct A07_alignment) == 128, "record A07 wrong alignment");
_Static_assert(sizeof(struct A07_packed) == 128, "record A07 wrong sizeof");
_Static_assert(_Alignof(struct A07_packed) == 1, "record A07 wrong alignment");
_Static_assert(sizeof(struct A07_required_alignment) == 129, "record A07 wrong sizeof");
_Static_assert(_Alignof(struct A07_required_alignment) == 1, "record A07 wrong alignment");
_Static_assert(sizeof(struct A07_size) == 130, "record A07 wrong sizeof");
_Static_assert(_Alignof(struct A07_size) == 1, "record A07 wrong alignment");
#endif
_Static_assert(sizeof(A08) == 128, "record A08 wrong sizeof");
_Static_assert(_Alignof(A08) == 128, "record A08 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A08_alignment) == 256, "record A08 wrong sizeof");
_Static_assert(_Alignof(struct A08_alignment) == 128, "record A08 wrong alignment");
_Static_assert(sizeof(struct A08_packed) == 128, "record A08 wrong sizeof");
_Static_assert(_Alignof(struct A08_packed) == 1, "record A08 wrong alignment");
_Static_assert(sizeof(struct A08_required_alignment) == 129, "record A08 wrong sizeof");
_Static_assert(_Alignof(struct A08_required_alignment) == 1, "record A08 wrong alignment");
_Static_assert(sizeof(struct A08_size) == 130, "record A08 wrong sizeof");
_Static_assert(_Alignof(struct A08_size) == 1, "record A08 wrong alignment");
#endif
_Static_assert(sizeof(A09) == 128, "record A09 wrong sizeof");
_Static_assert(_Alignof(A09) == 128, "record A09 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A09_alignment) == 256, "record A09 wrong sizeof");
_Static_assert(_Alignof(struct A09_alignment) == 128, "record A09 wrong alignment");
_Static_assert(sizeof(struct A09_packed) == 128, "record A09 wrong sizeof");
_Static_assert(_Alignof(struct A09_packed) == 1, "record A09 wrong alignment");
_Static_assert(sizeof(struct A09_required_alignment) == 129, "record A09 wrong sizeof");
_Static_assert(_Alignof(struct A09_required_alignment) == 1, "record A09 wrong alignment");
_Static_assert(sizeof(struct A09_size) == 130, "record A09 wrong sizeof");
_Static_assert(_Alignof(struct A09_size) == 1, "record A09 wrong alignment");
#endif
_Static_assert(sizeof(A10) == 128, "record A10 wrong sizeof");
_Static_assert(_Alignof(A10) == 128, "record A10 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A10_alignment) == 256, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_alignment) == 128, "record A10 wrong alignment");
_Static_assert(sizeof(struct A10_packed) == 128, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_packed) == 1, "record A10 wrong alignment");
_Static_assert(sizeof(struct A10_required_alignment) == 129, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_required_alignment) == 1, "record A10 wrong alignment");
_Static_assert(sizeof(struct A10_size) == 130, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_size) == 1, "record A10 wrong alignment");
#endif
_Static_assert(sizeof(A11) == 128, "record A11 wrong sizeof");
_Static_assert(_Alignof(A11) == 128, "record A11 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A11_alignment) == 256, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_alignment) == 128, "record A11 wrong alignment");
_Static_assert(sizeof(struct A11_packed) == 128, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_packed) == 1, "record A11 wrong alignment");
_Static_assert(sizeof(struct A11_required_alignment) == 129, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_required_alignment) == 1, "record A11 wrong alignment");
_Static_assert(sizeof(struct A11_size) == 130, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_size) == 1, "record A11 wrong alignment");
#endif
_Static_assert(sizeof(A12) == 128, "record A12 wrong sizeof");
_Static_assert(_Alignof(A12) == 128, "record A12 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A12_alignment) == 256, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_alignment) == 128, "record A12 wrong alignment");
_Static_assert(sizeof(struct A12_packed) == 128, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_packed) == 1, "record A12 wrong alignment");
_Static_assert(sizeof(struct A12_required_alignment) == 129, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_required_alignment) == 1, "record A12 wrong alignment");
_Static_assert(sizeof(struct A12_size) == 130, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_size) == 1, "record A12 wrong alignment");
#endif
_Static_assert(sizeof(A13) == 128, "record A13 wrong sizeof");
_Static_assert(_Alignof(A13) == 128, "record A13 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A13_alignment) == 256, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_alignment) == 128, "record A13 wrong alignment");
_Static_assert(sizeof(struct A13_packed) == 128, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_packed) == 1, "record A13 wrong alignment");
_Static_assert(sizeof(struct A13_required_alignment) == 129, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_required_alignment) == 1, "record A13 wrong alignment");
_Static_assert(sizeof(struct A13_size) == 130, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_size) == 1, "record A13 wrong alignment");
#endif
_Static_assert(sizeof(A14) == 128, "record A14 wrong sizeof");
_Static_assert(_Alignof(A14) == 128, "record A14 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A14_alignment) == 256, "record A14 wrong sizeof");
_Static_assert(_Alignof(struct A14_alignment) == 128, "record A14 wrong alignment");
_Static_assert(sizeof(struct A14_packed) == 128, "record A14 wrong sizeof");
_Static_assert(_Alignof(struct A14_packed) == 1, "record A14 wrong alignment");
_Static_assert(sizeof(struct A14_required_alignment) == 129, "record A14 wrong sizeof");
_Static_assert(_Alignof(struct A14_required_alignment) == 1, "record A14 wrong alignment");
_Static_assert(sizeof(struct A14_size) == 130, "record A14 wrong sizeof");
_Static_assert(_Alignof(struct A14_size) == 1, "record A14 wrong alignment");
#endif
_Static_assert(sizeof(A15) == 128, "record A15 wrong sizeof");
_Static_assert(_Alignof(A15) == 128, "record A15 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A15_alignment) == 256, "record A15 wrong sizeof");
_Static_assert(_Alignof(struct A15_alignment) == 128, "record A15 wrong alignment");
_Static_assert(sizeof(struct A15_packed) == 128, "record A15 wrong sizeof");
_Static_assert(_Alignof(struct A15_packed) == 1, "record A15 wrong alignment");
_Static_assert(sizeof(struct A15_required_alignment) == 129, "record A15 wrong sizeof");
_Static_assert(_Alignof(struct A15_required_alignment) == 1, "record A15 wrong alignment");
_Static_assert(sizeof(struct A15_size) == 130, "record A15 wrong sizeof");
_Static_assert(_Alignof(struct A15_size) == 1, "record A15 wrong alignment");
#endif
_Static_assert(sizeof(A16) == 128, "record A16 wrong sizeof");
_Static_assert(_Alignof(A16) == 128, "record A16 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A16_alignment) == 256, "record A16 wrong sizeof");
_Static_assert(_Alignof(struct A16_alignment) == 128, "record A16 wrong alignment");
_Static_assert(sizeof(struct A16_packed) == 128, "record A16 wrong sizeof");
_Static_assert(_Alignof(struct A16_packed) == 1, "record A16 wrong alignment");
_Static_assert(sizeof(struct A16_required_alignment) == 129, "record A16 wrong sizeof");
_Static_assert(_Alignof(struct A16_required_alignment) == 1, "record A16 wrong alignment");
_Static_assert(sizeof(struct A16_size) == 130, "record A16 wrong sizeof");
_Static_assert(_Alignof(struct A16_size) == 1, "record A16 wrong alignment");
#endif
_Static_assert(sizeof(A17) == 128, "record A17 wrong sizeof");
_Static_assert(_Alignof(A17) == 128, "record A17 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A17_alignment) == 256, "record A17 wrong sizeof");
_Static_assert(_Alignof(struct A17_alignment) == 128, "record A17 wrong alignment");
_Static_assert(sizeof(struct A17_packed) == 128, "record A17 wrong sizeof");
_Static_assert(_Alignof(struct A17_packed) == 1, "record A17 wrong alignment");
_Static_assert(sizeof(struct A17_required_alignment) == 129, "record A17 wrong sizeof");
_Static_assert(_Alignof(struct A17_required_alignment) == 1, "record A17 wrong alignment");
_Static_assert(sizeof(struct A17_size) == 130, "record A17 wrong sizeof");
_Static_assert(_Alignof(struct A17_size) == 1, "record A17 wrong alignment");
#endif
_Static_assert(sizeof(A18) == 128, "record A18 wrong sizeof");
_Static_assert(_Alignof(A18) == 128, "record A18 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A18_alignment) == 256, "record A18 wrong sizeof");
_Static_assert(_Alignof(struct A18_alignment) == 128, "record A18 wrong alignment");
_Static_assert(sizeof(struct A18_packed) == 128, "record A18 wrong sizeof");
_Static_assert(_Alignof(struct A18_packed) == 1, "record A18 wrong alignment");
_Static_assert(sizeof(struct A18_required_alignment) == 129, "record A18 wrong sizeof");
_Static_assert(_Alignof(struct A18_required_alignment) == 1, "record A18 wrong alignment");
_Static_assert(sizeof(struct A18_size) == 130, "record A18 wrong sizeof");
_Static_assert(_Alignof(struct A18_size) == 1, "record A18 wrong alignment");
#endif
_Static_assert(sizeof(A19) == 128, "record A19 wrong sizeof");
_Static_assert(_Alignof(A19) == 128, "record A19 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A19_alignment) == 256, "record A19 wrong sizeof");
_Static_assert(_Alignof(struct A19_alignment) == 128, "record A19 wrong alignment");
_Static_assert(sizeof(struct A19_packed) == 128, "record A19 wrong sizeof");
_Static_assert(_Alignof(struct A19_packed) == 1, "record A19 wrong alignment");
_Static_assert(sizeof(struct A19_required_alignment) == 129, "record A19 wrong sizeof");
_Static_assert(_Alignof(struct A19_required_alignment) == 1, "record A19 wrong alignment");
_Static_assert(sizeof(struct A19_size) == 130, "record A19 wrong sizeof");
_Static_assert(_Alignof(struct A19_size) == 1, "record A19 wrong alignment");
#endif
_Static_assert(sizeof(A20) == 128, "record A20 wrong sizeof");
_Static_assert(_Alignof(A20) == 128, "record A20 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A20_alignment) == 256, "record A20 wrong sizeof");
_Static_assert(_Alignof(struct A20_alignment) == 128, "record A20 wrong alignment");
_Static_assert(sizeof(struct A20_packed) == 128, "record A20 wrong sizeof");
_Static_assert(_Alignof(struct A20_packed) == 1, "record A20 wrong alignment");
_Static_assert(sizeof(struct A20_required_alignment) == 129, "record A20 wrong sizeof");
_Static_assert(_Alignof(struct A20_required_alignment) == 1, "record A20 wrong alignment");
_Static_assert(sizeof(struct A20_size) == 130, "record A20 wrong sizeof");
_Static_assert(_Alignof(struct A20_size) == 1, "record A20 wrong alignment");
#endif
_Static_assert(sizeof(A21) == 128, "record A21 wrong sizeof");
_Static_assert(_Alignof(A21) == 128, "record A21 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A21_alignment) == 256, "record A21 wrong sizeof");
_Static_assert(_Alignof(struct A21_alignment) == 128, "record A21 wrong alignment");
_Static_assert(sizeof(struct A21_packed) == 128, "record A21 wrong sizeof");
_Static_assert(_Alignof(struct A21_packed) == 1, "record A21 wrong alignment");
_Static_assert(sizeof(struct A21_required_alignment) == 129, "record A21 wrong sizeof");
_Static_assert(_Alignof(struct A21_required_alignment) == 1, "record A21 wrong alignment");
_Static_assert(sizeof(struct A21_size) == 130, "record A21 wrong sizeof");
_Static_assert(_Alignof(struct A21_size) == 1, "record A21 wrong alignment");
#endif
_Static_assert(sizeof(A22) == 128, "record A22 wrong sizeof");
_Static_assert(_Alignof(A22) == 128, "record A22 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A22_alignment) == 256, "record A22 wrong sizeof");
_Static_assert(_Alignof(struct A22_alignment) == 128, "record A22 wrong alignment");
_Static_assert(sizeof(struct A22_packed) == 128, "record A22 wrong sizeof");
_Static_assert(_Alignof(struct A22_packed) == 1, "record A22 wrong alignment");
_Static_assert(sizeof(struct A22_required_alignment) == 129, "record A22 wrong sizeof");
_Static_assert(_Alignof(struct A22_required_alignment) == 1, "record A22 wrong alignment");
_Static_assert(sizeof(struct A22_size) == 130, "record A22 wrong sizeof");
_Static_assert(_Alignof(struct A22_size) == 1, "record A22 wrong alignment");
#endif
_Static_assert(sizeof(A23) == 128, "record A23 wrong sizeof");
_Static_assert(_Alignof(A23) == 128, "record A23 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A23_alignment) == 256, "record A23 wrong sizeof");
_Static_assert(_Alignof(struct A23_alignment) == 128, "record A23 wrong alignment");
_Static_assert(sizeof(struct A23_packed) == 128, "record A23 wrong sizeof");
_Static_assert(_Alignof(struct A23_packed) == 1, "record A23 wrong alignment");
_Static_assert(sizeof(struct A23_required_alignment) == 129, "record A23 wrong sizeof");
_Static_assert(_Alignof(struct A23_required_alignment) == 1, "record A23 wrong alignment");
_Static_assert(sizeof(struct A23_size) == 130, "record A23 wrong sizeof");
_Static_assert(_Alignof(struct A23_size) == 1, "record A23 wrong alignment");
#endif
_Static_assert(sizeof(A24) == 128, "record A24 wrong sizeof");
_Static_assert(_Alignof(A24) == 128, "record A24 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A24_alignment) == 256, "record A24 wrong sizeof");
_Static_assert(_Alignof(struct A24_alignment) == 128, "record A24 wrong alignment");
_Static_assert(sizeof(struct A24_packed) == 128, "record A24 wrong sizeof");
_Static_assert(_Alignof(struct A24_packed) == 1, "record A24 wrong alignment");
_Static_assert(sizeof(struct A24_required_alignment) == 129, "record A24 wrong sizeof");
_Static_assert(_Alignof(struct A24_required_alignment) == 1, "record A24 wrong alignment");
_Static_assert(sizeof(struct A24_size) == 130, "record A24 wrong sizeof");
_Static_assert(_Alignof(struct A24_size) == 1, "record A24 wrong alignment");
#endif
_Static_assert(sizeof(A25) == 128, "record A25 wrong sizeof");
_Static_assert(_Alignof(A25) == 128, "record A25 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A25_alignment) == 256, "record A25 wrong sizeof");
_Static_assert(_Alignof(struct A25_alignment) == 128, "record A25 wrong alignment");
_Static_assert(sizeof(struct A25_packed) == 128, "record A25 wrong sizeof");
_Static_assert(_Alignof(struct A25_packed) == 1, "record A25 wrong alignment");
_Static_assert(sizeof(struct A25_required_alignment) == 129, "record A25 wrong sizeof");
_Static_assert(_Alignof(struct A25_required_alignment) == 1, "record A25 wrong alignment");
_Static_assert(sizeof(struct A25_size) == 130, "record A25 wrong sizeof");
_Static_assert(_Alignof(struct A25_size) == 1, "record A25 wrong alignment");
#endif
_Static_assert(sizeof(A26) == 128, "record A26 wrong sizeof");
_Static_assert(_Alignof(A26) == 128, "record A26 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A26_alignment) == 256, "record A26 wrong sizeof");
_Static_assert(_Alignof(struct A26_alignment) == 128, "record A26 wrong alignment");
_Static_assert(sizeof(struct A26_packed) == 128, "record A26 wrong sizeof");
_Static_assert(_Alignof(struct A26_packed) == 1, "record A26 wrong alignment");
_Static_assert(sizeof(struct A26_required_alignment) == 129, "record A26 wrong sizeof");
_Static_assert(_Alignof(struct A26_required_alignment) == 1, "record A26 wrong alignment");
_Static_assert(sizeof(struct A26_size) == 130, "record A26 wrong sizeof");
_Static_assert(_Alignof(struct A26_size) == 1, "record A26 wrong alignment");
#endif
_Static_assert(sizeof(A27) == 128, "record A27 wrong sizeof");
_Static_assert(_Alignof(A27) == 128, "record A27 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A27_alignment) == 256, "record A27 wrong sizeof");
_Static_assert(_Alignof(struct A27_alignment) == 128, "record A27 wrong alignment");
_Static_assert(sizeof(struct A27_packed) == 128, "record A27 wrong sizeof");
_Static_assert(_Alignof(struct A27_packed) == 1, "record A27 wrong alignment");
_Static_assert(sizeof(struct A27_required_alignment) == 129, "record A27 wrong sizeof");
_Static_assert(_Alignof(struct A27_required_alignment) == 1, "record A27 wrong alignment");
_Static_assert(sizeof(struct A27_size) == 130, "record A27 wrong sizeof");
_Static_assert(_Alignof(struct A27_size) == 1, "record A27 wrong alignment");
#endif
_Static_assert(sizeof(A28) == 128, "record A28 wrong sizeof");
_Static_assert(_Alignof(A28) == 128, "record A28 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A28_alignment) == 256, "record A28 wrong sizeof");
_Static_assert(_Alignof(struct A28_alignment) == 128, "record A28 wrong alignment");
_Static_assert(sizeof(struct A28_packed) == 128, "record A28 wrong sizeof");
_Static_assert(_Alignof(struct A28_packed) == 1, "record A28 wrong alignment");
_Static_assert(sizeof(struct A28_required_alignment) == 129, "record A28 wrong sizeof");
_Static_assert(_Alignof(struct A28_required_alignment) == 1, "record A28 wrong alignment");
_Static_assert(sizeof(struct A28_size) == 130, "record A28 wrong sizeof");
_Static_assert(_Alignof(struct A28_size) == 1, "record A28 wrong alignment");
#endif
_Static_assert(sizeof(A29) == 128, "record A29 wrong sizeof");
_Static_assert(_Alignof(A29) == 128, "record A29 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A29_alignment) == 256, "record A29 wrong sizeof");
_Static_assert(_Alignof(struct A29_alignment) == 128, "record A29 wrong alignment");
_Static_assert(sizeof(struct A29_packed) == 128, "record A29 wrong sizeof");
_Static_assert(_Alignof(struct A29_packed) == 1, "record A29 wrong alignment");
_Static_assert(sizeof(struct A29_required_alignment) == 129, "record A29 wrong sizeof");
_Static_assert(_Alignof(struct A29_required_alignment) == 1, "record A29 wrong alignment");
_Static_assert(sizeof(struct A29_size) == 130, "record A29 wrong sizeof");
_Static_assert(_Alignof(struct A29_size) == 1, "record A29 wrong alignment");
#endif
_Static_assert(sizeof(A30) == 128, "record A30 wrong sizeof");
_Static_assert(_Alignof(A30) == 128, "record A30 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A30_alignment) == 256, "record A30 wrong sizeof");
_Static_assert(_Alignof(struct A30_alignment) == 128, "record A30 wrong alignment");
_Static_assert(sizeof(struct A30_packed) == 128, "record A30 wrong sizeof");
_Static_assert(_Alignof(struct A30_packed) == 1, "record A30 wrong alignment");
_Static_assert(sizeof(struct A30_required_alignment) == 129, "record A30 wrong sizeof");
_Static_assert(_Alignof(struct A30_required_alignment) == 1, "record A30 wrong alignment");
_Static_assert(sizeof(struct A30_size) == 130, "record A30 wrong sizeof");
_Static_assert(_Alignof(struct A30_size) == 1, "record A30 wrong alignment");
#endif
_Static_assert(sizeof(A31) == 128, "record A31 wrong sizeof");
_Static_assert(_Alignof(A31) == 128, "record A31 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A31_alignment) == 256, "record A31 wrong sizeof");
_Static_assert(_Alignof(struct A31_alignment) == 128, "record A31 wrong alignment");
_Static_assert(sizeof(struct A31_packed) == 128, "record A31 wrong sizeof");
_Static_assert(_Alignof(struct A31_packed) == 1, "record A31 wrong alignment");
_Static_assert(sizeof(struct A31_required_alignment) == 129, "record A31 wrong sizeof");
_Static_assert(_Alignof(struct A31_required_alignment) == 1, "record A31 wrong alignment");
_Static_assert(sizeof(struct A31_size) == 130, "record A31 wrong sizeof");
_Static_assert(_Alignof(struct A31_size) == 1, "record A31 wrong alignment");
#endif
_Static_assert(sizeof(A32) == 128, "record A32 wrong sizeof");
_Static_assert(_Alignof(A32) == 128, "record A32 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A32_alignment) == 256, "record A32 wrong sizeof");
_Static_assert(_Alignof(struct A32_alignment) == 128, "record A32 wrong alignment");
_Static_assert(sizeof(struct A32_packed) == 128, "record A32 wrong sizeof");
_Static_assert(_Alignof(struct A32_packed) == 1, "record A32 wrong alignment");
_Static_assert(sizeof(struct A32_required_alignment) == 129, "record A32 wrong sizeof");
_Static_assert(_Alignof(struct A32_required_alignment) == 1, "record A32 wrong alignment");
_Static_assert(sizeof(struct A32_size) == 130, "record A32 wrong sizeof");
_Static_assert(_Alignof(struct A32_size) == 1, "record A32 wrong alignment");
#endif
_Static_assert(sizeof(A33) == 128, "record A33 wrong sizeof");
_Static_assert(_Alignof(A33) == 128, "record A33 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A33_alignment) == 256, "record A33 wrong sizeof");
_Static_assert(_Alignof(struct A33_alignment) == 128, "record A33 wrong alignment");
_Static_assert(sizeof(struct A33_packed) == 128, "record A33 wrong sizeof");
_Static_assert(_Alignof(struct A33_packed) == 1, "record A33 wrong alignment");
_Static_assert(sizeof(struct A33_required_alignment) == 129, "record A33 wrong sizeof");
_Static_assert(_Alignof(struct A33_required_alignment) == 1, "record A33 wrong alignment");
_Static_assert(sizeof(struct A33_size) == 130, "record A33 wrong sizeof");
_Static_assert(_Alignof(struct A33_size) == 1, "record A33 wrong alignment");
#endif
_Static_assert(sizeof(A34) == 128, "record A34 wrong sizeof");
_Static_assert(_Alignof(A34) == 128, "record A34 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A34_alignment) == 256, "record A34 wrong sizeof");
_Static_assert(_Alignof(struct A34_alignment) == 128, "record A34 wrong alignment");
_Static_assert(sizeof(struct A34_packed) == 128, "record A34 wrong sizeof");
_Static_assert(_Alignof(struct A34_packed) == 1, "record A34 wrong alignment");
_Static_assert(sizeof(struct A34_required_alignment) == 129, "record A34 wrong sizeof");
_Static_assert(_Alignof(struct A34_required_alignment) == 1, "record A34 wrong alignment");
_Static_assert(sizeof(struct A34_size) == 130, "record A34 wrong sizeof");
_Static_assert(_Alignof(struct A34_size) == 1, "record A34 wrong alignment");
#endif
_Static_assert(sizeof(A35) == 128, "record A35 wrong sizeof");
_Static_assert(_Alignof(A35) == 128, "record A35 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A35_alignment) == 256, "record A35 wrong sizeof");
_Static_assert(_Alignof(struct A35_alignment) == 128, "record A35 wrong alignment");
_Static_assert(sizeof(struct A35_packed) == 128, "record A35 wrong sizeof");
_Static_assert(_Alignof(struct A35_packed) == 1, "record A35 wrong alignment");
_Static_assert(sizeof(struct A35_required_alignment) == 129, "record A35 wrong sizeof");
_Static_assert(_Alignof(struct A35_required_alignment) == 1, "record A35 wrong alignment");
_Static_assert(sizeof(struct A35_size) == 130, "record A35 wrong sizeof");
_Static_assert(_Alignof(struct A35_size) == 1, "record A35 wrong alignment");
#endif
_Static_assert(sizeof(A36) == 128, "record A36 wrong sizeof");
_Static_assert(_Alignof(A36) == 128, "record A36 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A36_alignment) == 256, "record A36 wrong sizeof");
_Static_assert(_Alignof(struct A36_alignment) == 128, "record A36 wrong alignment");
_Static_assert(sizeof(struct A36_packed) == 128, "record A36 wrong sizeof");
_Static_assert(_Alignof(struct A36_packed) == 1, "record A36 wrong alignment");
_Static_assert(sizeof(struct A36_required_alignment) == 129, "record A36 wrong sizeof");
_Static_assert(_Alignof(struct A36_required_alignment) == 1, "record A36 wrong alignment");
_Static_assert(sizeof(struct A36_size) == 130, "record A36 wrong sizeof");
_Static_assert(_Alignof(struct A36_size) == 1, "record A36 wrong alignment");
#endif
_Static_assert(sizeof(A37) == 128, "record A37 wrong sizeof");
_Static_assert(_Alignof(A37) == 128, "record A37 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A37_alignment) == 256, "record A37 wrong sizeof");
_Static_assert(_Alignof(struct A37_alignment) == 128, "record A37 wrong alignment");
_Static_assert(sizeof(struct A37_packed) == 128, "record A37 wrong sizeof");
_Static_assert(_Alignof(struct A37_packed) == 1, "record A37 wrong alignment");
_Static_assert(sizeof(struct A37_required_alignment) == 129, "record A37 wrong sizeof");
_Static_assert(_Alignof(struct A37_required_alignment) == 1, "record A37 wrong alignment");
_Static_assert(sizeof(struct A37_size) == 130, "record A37 wrong sizeof");
_Static_assert(_Alignof(struct A37_size) == 1, "record A37 wrong alignment");
#endif
_Static_assert(sizeof(A38) == 128, "record A38 wrong sizeof");
_Static_assert(_Alignof(A38) == 128, "record A38 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A38_alignment) == 256, "record A38 wrong sizeof");
_Static_assert(_Alignof(struct A38_alignment) == 128, "record A38 wrong alignment");
_Static_assert(sizeof(struct A38_packed) == 128, "record A38 wrong sizeof");
_Static_assert(_Alignof(struct A38_packed) == 1, "record A38 wrong alignment");
_Static_assert(sizeof(struct A38_required_alignment) == 129, "record A38 wrong sizeof");
_Static_assert(_Alignof(struct A38_required_alignment) == 1, "record A38 wrong alignment");
_Static_assert(sizeof(struct A38_size) == 130, "record A38 wrong sizeof");
_Static_assert(_Alignof(struct A38_size) == 1, "record A38 wrong alignment");
#endif
_Static_assert(sizeof(A39) == 128, "record A39 wrong sizeof");
_Static_assert(_Alignof(A39) == 128, "record A39 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A39_alignment) == 256, "record A39 wrong sizeof");
_Static_assert(_Alignof(struct A39_alignment) == 128, "record A39 wrong alignment");
_Static_assert(sizeof(struct A39_packed) == 128, "record A39 wrong sizeof");
_Static_assert(_Alignof(struct A39_packed) == 1, "record A39 wrong alignment");
_Static_assert(sizeof(struct A39_required_alignment) == 129, "record A39 wrong sizeof");
_Static_assert(_Alignof(struct A39_required_alignment) == 1, "record A39 wrong alignment");
_Static_assert(sizeof(struct A39_size) == 130, "record A39 wrong sizeof");
_Static_assert(_Alignof(struct A39_size) == 1, "record A39 wrong alignment");
#endif
_Static_assert(sizeof(B00) == 128, "record B00 wrong sizeof");
_Static_assert(_Alignof(B00) == 128, "record B00 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B00_alignment) == 256, "record B00 wrong sizeof");
_Static_assert(_Alignof(struct B00_alignment) == 128, "record B00 wrong alignment");
_Static_assert(sizeof(struct B00_packed) == 128, "record B00 wrong sizeof");
_Static_assert(_Alignof(struct B00_packed) == 1, "record B00 wrong alignment");
_Static_assert(sizeof(struct B00_required_alignment) == 129, "record B00 wrong sizeof");
_Static_assert(_Alignof(struct B00_required_alignment) == 1, "record B00 wrong alignment");
_Static_assert(sizeof(struct B00_size) == 130, "record B00 wrong sizeof");
_Static_assert(_Alignof(struct B00_size) == 1, "record B00 wrong alignment");
#endif
_Static_assert(sizeof(B01) == 128, "record B01 wrong sizeof");
_Static_assert(_Alignof(B01) == 128, "record B01 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B01_alignment) == 256, "record B01 wrong sizeof");
_Static_assert(_Alignof(struct B01_alignment) == 128, "record B01 wrong alignment");
_Static_assert(sizeof(struct B01_packed) == 128, "record B01 wrong sizeof");
_Static_assert(_Alignof(struct B01_packed) == 1, "record B01 wrong alignment");
_Static_assert(sizeof(struct B01_required_alignment) == 129, "record B01 wrong sizeof");
_Static_assert(_Alignof(struct B01_required_alignment) == 1, "record B01 wrong alignment");
_Static_assert(sizeof(struct B01_size) == 130, "record B01 wrong sizeof");
_Static_assert(_Alignof(struct B01_size) == 1, "record B01 wrong alignment");
#endif
_Static_assert(sizeof(B02) == 128, "record B02 wrong sizeof");
_Static_assert(_Alignof(B02) == 128, "record B02 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B02_alignment) == 256, "record B02 wrong sizeof");
_Static_assert(_Alignof(struct B02_alignment) == 128, "record B02 wrong alignment");
_Static_assert(sizeof(struct B02_packed) == 128, "record B02 wrong sizeof");
_Static_assert(_Alignof(struct B02_packed) == 1, "record B02 wrong alignment");
_Static_assert(sizeof(struct B02_required_alignment) == 129, "record B02 wrong sizeof");
_Static_assert(_Alignof(struct B02_required_alignment) == 1, "record B02 wrong alignment");
_Static_assert(sizeof(struct B02_size) == 130, "record B02 wrong sizeof");
_Static_assert(_Alignof(struct B02_size) == 1, "record B02 wrong alignment");
#endif
_Static_assert(sizeof(B03) == 128, "record B03 wrong sizeof");
_Static_assert(_Alignof(B03) == 128, "record B03 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B03_alignment) == 256, "record B03 wrong sizeof");
_Static_assert(_Alignof(struct B03_alignment) == 128, "record B03 wrong alignment");
_Static_assert(sizeof(struct B03_packed) == 128, "record B03 wrong sizeof");
_Static_assert(_Alignof(struct B03_packed) == 1, "record B03 wrong alignment");
_Static_assert(sizeof(struct B03_required_alignment) == 129, "record B03 wrong sizeof");
_Static_assert(_Alignof(struct B03_required_alignment) == 1, "record B03 wrong alignment");
_Static_assert(sizeof(struct B03_size) == 130, "record B03 wrong sizeof");
_Static_assert(_Alignof(struct B03_size) == 1, "record B03 wrong alignment");
#endif
_Static_assert(sizeof(B04) == 128, "record B04 wrong sizeof");
_Static_assert(_Alignof(B04) == 128, "record B04 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B04_alignment) == 256, "record B04 wrong sizeof");
_Static_assert(_Alignof(struct B04_alignment) == 128, "record B04 wrong alignment");
_Static_assert(sizeof(struct B04_packed) == 128, "record B04 wrong sizeof");
_Static_assert(_Alignof(struct B04_packed) == 1, "record B04 wrong alignment");
_Static_assert(sizeof(struct B04_required_alignment) == 129, "record B04 wrong sizeof");
_Static_assert(_Alignof(struct B04_required_alignment) == 1, "record B04 wrong alignment");
_Static_assert(sizeof(struct B04_size) == 130, "record B04 wrong sizeof");
_Static_assert(_Alignof(struct B04_size) == 1, "record B04 wrong alignment");
#endif
_Static_assert(sizeof(B05) == 128, "record B05 wrong sizeof");
_Static_assert(_Alignof(B05) == 128, "record B05 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B05_alignment) == 256, "record B05 wrong sizeof");
_Static_assert(_Alignof(struct B05_alignment) == 128, "record B05 wrong alignment");
_Static_assert(sizeof(struct B05_packed) == 128, "record B05 wrong sizeof");
_Static_assert(_Alignof(struct B05_packed) == 1, "record B05 wrong alignment");
_Static_assert(sizeof(struct B05_required_alignment) == 129, "record B05 wrong sizeof");
_Static_assert(_Alignof(struct B05_required_alignment) == 1, "record B05 wrong alignment");
_Static_assert(sizeof(struct B05_size) == 130, "record B05 wrong sizeof");
_Static_assert(_Alignof(struct B05_size) == 1, "record B05 wrong alignment");
#endif
_Static_assert(sizeof(B06) == 128, "record B06 wrong sizeof");
_Static_assert(_Alignof(B06) == 128, "record B06 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B06_alignment) == 256, "record B06 wrong sizeof");
_Static_assert(_Alignof(struct B06_alignment) == 128, "record B06 wrong alignment");
_Static_assert(sizeof(struct B06_packed) == 128, "record B06 wrong sizeof");
_Static_assert(_Alignof(struct B06_packed) == 1, "record B06 wrong alignment");
_Static_assert(sizeof(struct B06_required_alignment) == 129, "record B06 wrong sizeof");
_Static_assert(_Alignof(struct B06_required_alignment) == 1, "record B06 wrong alignment");
_Static_assert(sizeof(struct B06_size) == 130, "record B06 wrong sizeof");
_Static_assert(_Alignof(struct B06_size) == 1, "record B06 wrong alignment");
#endif
_Static_assert(sizeof(B07) == 128, "record B07 wrong sizeof");
_Static_assert(_Alignof(B07) == 128, "record B07 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B07_alignment) == 256, "record B07 wrong sizeof");
_Static_assert(_Alignof(struct B07_alignment) == 128, "record B07 wrong alignment");
_Static_assert(sizeof(struct B07_packed) == 128, "record B07 wrong sizeof");
_Static_assert(_Alignof(struct B07_packed) == 1, "record B07 wrong alignment");
_Static_assert(sizeof(struct B07_required_alignment) == 129, "record B07 wrong sizeof");
_Static_assert(_Alignof(struct B07_required_alignment) == 1, "record B07 wrong alignment");
_Static_assert(sizeof(struct B07_size) == 130, "record B07 wrong sizeof");
_Static_assert(_Alignof(struct B07_size) == 1, "record B07 wrong alignment");
#endif
_Static_assert(sizeof(B08) == 128, "record B08 wrong sizeof");
_Static_assert(_Alignof(B08) == 128, "record B08 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B08_alignment) == 256, "record B08 wrong sizeof");
_Static_assert(_Alignof(struct B08_alignment) == 128, "record B08 wrong alignment");
_Static_assert(sizeof(struct B08_packed) == 128, "record B08 wrong sizeof");
_Static_assert(_Alignof(struct B08_packed) == 1, "record B08 wrong alignment");
_Static_assert(sizeof(struct B08_required_alignment) == 129, "record B08 wrong sizeof");
_Static_assert(_Alignof(struct B08_required_alignment) == 1, "record B08 wrong alignment");
_Static_assert(sizeof(struct B08_size) == 130, "record B08 wrong sizeof");
_Static_assert(_Alignof(struct B08_size) == 1, "record B08 wrong alignment");
#endif
_Static_assert(sizeof(B09) == 128, "record B09 wrong sizeof");
_Static_assert(_Alignof(B09) == 128, "record B09 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B09_alignment) == 256, "record B09 wrong sizeof");
_Static_assert(_Alignof(struct B09_alignment) == 128, "record B09 wrong alignment");
_Static_assert(sizeof(struct B09_packed) == 128, "record B09 wrong sizeof");
_Static_assert(_Alignof(struct B09_packed) == 1, "record B09 wrong alignment");
_Static_assert(sizeof(struct B09_required_alignment) == 129, "record B09 wrong sizeof");
_Static_assert(_Alignof(struct B09_required_alignment) == 1, "record B09 wrong alignment");
_Static_assert(sizeof(struct B09_size) == 130, "record B09 wrong sizeof");
_Static_assert(_Alignof(struct B09_size) == 1, "record B09 wrong alignment");
#endif
_Static_assert(sizeof(B10) == 128, "record B10 wrong sizeof");
_Static_assert(_Alignof(B10) == 128, "record B10 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B10_alignment) == 256, "record B10 wrong sizeof");
_Static_assert(_Alignof(struct B10_alignment) == 128, "record B10 wrong alignment");
_Static_assert(sizeof(struct B10_packed) == 128, "record B10 wrong sizeof");
_Static_assert(_Alignof(struct B10_packed) == 1, "record B10 wrong alignment");
_Static_assert(sizeof(struct B10_required_alignment) == 129, "record B10 wrong sizeof");
_Static_assert(_Alignof(struct B10_required_alignment) == 1, "record B10 wrong alignment");
_Static_assert(sizeof(struct B10_size) == 130, "record B10 wrong sizeof");
_Static_assert(_Alignof(struct B10_size) == 1, "record B10 wrong alignment");
#endif
_Static_assert(sizeof(B11) == 128, "record B11 wrong sizeof");
_Static_assert(_Alignof(B11) == 128, "record B11 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B11_alignment) == 256, "record B11 wrong sizeof");
_Static_assert(_Alignof(struct B11_alignment) == 128, "record B11 wrong alignment");
_Static_assert(sizeof(struct B11_packed) == 128, "record B11 wrong sizeof");
_Static_assert(_Alignof(struct B11_packed) == 1, "record B11 wrong alignment");
_Static_assert(sizeof(struct B11_required_alignment) == 129, "record B11 wrong sizeof");
_Static_assert(_Alignof(struct B11_required_alignment) == 1, "record B11 wrong alignment");
_Static_assert(sizeof(struct B11_size) == 130, "record B11 wrong sizeof");
_Static_assert(_Alignof(struct B11_size) == 1, "record B11 wrong alignment");
#endif
_Static_assert(sizeof(B12) == 128, "record B12 wrong sizeof");
_Static_assert(_Alignof(B12) == 128, "record B12 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B12_alignment) == 256, "record B12 wrong sizeof");
_Static_assert(_Alignof(struct B12_alignment) == 128, "record B12 wrong alignment");
_Static_assert(sizeof(struct B12_packed) == 128, "record B12 wrong sizeof");
_Static_assert(_Alignof(struct B12_packed) == 1, "record B12 wrong alignment");
_Static_assert(sizeof(struct B12_required_alignment) == 129, "record B12 wrong sizeof");
_Static_assert(_Alignof(struct B12_required_alignment) == 1, "record B12 wrong alignment");
_Static_assert(sizeof(struct B12_size) == 130, "record B12 wrong sizeof");
_Static_assert(_Alignof(struct B12_size) == 1, "record B12 wrong alignment");
#endif
_Static_assert(sizeof(B13) == 128, "record B13 wrong sizeof");
_Static_assert(_Alignof(B13) == 128, "record B13 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B13_alignment) == 256, "record B13 wrong sizeof");
_Static_assert(_Alignof(struct B13_alignment) == 128, "record B13 wrong alignment");
_Static_assert(sizeof(struct B13_packed) == 128, "record B13 wrong sizeof");
_Static_assert(_Alignof(struct B13_packed) == 1, "record B13 wrong alignment");
_Static_assert(sizeof(struct B13_required_alignment) == 129, "record B13 wrong sizeof");
_Static_assert(_Alignof(struct B13_required_alignment) == 1, "record B13 wrong alignment");
_Static_assert(sizeof(struct B13_size) == 130, "record B13 wrong sizeof");
_Static_assert(_Alignof(struct B13_size) == 1, "record B13 wrong alignment");
#endif
_Static_assert(sizeof(B14) == 128, "record B14 wrong sizeof");
_Static_assert(_Alignof(B14) == 128, "record B14 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B14_alignment) == 256, "record B14 wrong sizeof");
_Static_assert(_Alignof(struct B14_alignment) == 128, "record B14 wrong alignment");
_Static_assert(sizeof(struct B14_packed) == 128, "record B14 wrong sizeof");
_Static_assert(_Alignof(struct B14_packed) == 1, "record B14 wrong alignment");
_Static_assert(sizeof(struct B14_required_alignment) == 129, "record B14 wrong sizeof");
_Static_assert(_Alignof(struct B14_required_alignment) == 1, "record B14 wrong alignment");
_Static_assert(sizeof(struct B14_size) == 130, "record B14 wrong sizeof");
_Static_assert(_Alignof(struct B14_size) == 1, "record B14 wrong alignment");
#endif
_Static_assert(sizeof(B15) == 128, "record B15 wrong sizeof");
_Static_assert(_Alignof(B15) == 128, "record B15 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B15_alignment) == 256, "record B15 wrong sizeof");
_Static_assert(_Alignof(struct B15_alignment) == 128, "record B15 wrong alignment");
_Static_assert(sizeof(struct B15_packed) == 128, "record B15 wrong sizeof");
_Static_assert(_Alignof(struct B15_packed) == 1, "record B15 wrong alignment");
_Static_assert(sizeof(struct B15_required_alignment) == 129, "record B15 wrong sizeof");
_Static_assert(_Alignof(struct B15_required_alignment) == 1, "record B15 wrong alignment");
_Static_assert(sizeof(struct B15_size) == 130, "record B15 wrong sizeof");
_Static_assert(_Alignof(struct B15_size) == 1, "record B15 wrong alignment");
#endif
_Static_assert(sizeof(B16) == 128, "record B16 wrong sizeof");
_Static_assert(_Alignof(B16) == 128, "record B16 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B16_alignment) == 256, "record B16 wrong sizeof");
_Static_assert(_Alignof(struct B16_alignment) == 128, "record B16 wrong alignment");
_Static_assert(sizeof(struct B16_packed) == 128, "record B16 wrong sizeof");
_Static_assert(_Alignof(struct B16_packed) == 1, "record B16 wrong alignment");
_Static_assert(sizeof(struct B16_required_alignment) == 129, "record B16 wrong sizeof");
_Static_assert(_Alignof(struct B16_required_alignment) == 1, "record B16 wrong alignment");
_Static_assert(sizeof(struct B16_size) == 130, "record B16 wrong sizeof");
_Static_assert(_Alignof(struct B16_size) == 1, "record B16 wrong alignment");
#endif
_Static_assert(sizeof(B17) == 128, "record B17 wrong sizeof");
_Static_assert(_Alignof(B17) == 128, "record B17 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B17_alignment) == 256, "record B17 wrong sizeof");
_Static_assert(_Alignof(struct B17_alignment) == 128, "record B17 wrong alignment");
_Static_assert(sizeof(struct B17_packed) == 128, "record B17 wrong sizeof");
_Static_assert(_Alignof(struct B17_packed) == 1, "record B17 wrong alignment");
_Static_assert(sizeof(struct B17_required_alignment) == 129, "record B17 wrong sizeof");
_Static_assert(_Alignof(struct B17_required_alignment) == 1, "record B17 wrong alignment");
_Static_assert(sizeof(struct B17_size) == 130, "record B17 wrong sizeof");
_Static_assert(_Alignof(struct B17_size) == 1, "record B17 wrong alignment");
#endif
_Static_assert(sizeof(B18) == 128, "record B18 wrong sizeof");
_Static_assert(_Alignof(B18) == 128, "record B18 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B18_alignment) == 256, "record B18 wrong sizeof");
_Static_assert(_Alignof(struct B18_alignment) == 128, "record B18 wrong alignment");
_Static_assert(sizeof(struct B18_packed) == 128, "record B18 wrong sizeof");
_Static_assert(_Alignof(struct B18_packed) == 1, "record B18 wrong alignment");
_Static_assert(sizeof(struct B18_required_alignment) == 129, "record B18 wrong sizeof");
_Static_assert(_Alignof(struct B18_required_alignment) == 1, "record B18 wrong alignment");
_Static_assert(sizeof(struct B18_size) == 130, "record B18 wrong sizeof");
_Static_assert(_Alignof(struct B18_size) == 1, "record B18 wrong alignment");
#endif
_Static_assert(sizeof(B19) == 128, "record B19 wrong sizeof");
_Static_assert(_Alignof(B19) == 128, "record B19 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B19_alignment) == 256, "record B19 wrong sizeof");
_Static_assert(_Alignof(struct B19_alignment) == 128, "record B19 wrong alignment");
_Static_assert(sizeof(struct B19_packed) == 128, "record B19 wrong sizeof");
_Static_assert(_Alignof(struct B19_packed) == 1, "record B19 wrong alignment");
_Static_assert(sizeof(struct B19_required_alignment) == 129, "record B19 wrong sizeof");
_Static_assert(_Alignof(struct B19_required_alignment) == 1, "record B19 wrong alignment");
_Static_assert(sizeof(struct B19_size) == 130, "record B19 wrong sizeof");
_Static_assert(_Alignof(struct B19_size) == 1, "record B19 wrong alignment");
#endif
_Static_assert(sizeof(B20) == 128, "record B20 wrong sizeof");
_Static_assert(_Alignof(B20) == 128, "record B20 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B20_alignment) == 256, "record B20 wrong sizeof");
_Static_assert(_Alignof(struct B20_alignment) == 128, "record B20 wrong alignment");
_Static_assert(sizeof(struct B20_packed) == 128, "record B20 wrong sizeof");
_Static_assert(_Alignof(struct B20_packed) == 1, "record B20 wrong alignment");
_Static_assert(sizeof(struct B20_required_alignment) == 129, "record B20 wrong sizeof");
_Static_assert(_Alignof(struct B20_required_alignment) == 1, "record B20 wrong alignment");
_Static_assert(sizeof(struct B20_size) == 130, "record B20 wrong sizeof");
_Static_assert(_Alignof(struct B20_size) == 1, "record B20 wrong alignment");
#endif
_Static_assert(sizeof(B21) == 128, "record B21 wrong sizeof");
_Static_assert(_Alignof(B21) == 128, "record B21 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B21_alignment) == 256, "record B21 wrong sizeof");
_Static_assert(_Alignof(struct B21_alignment) == 128, "record B21 wrong alignment");
_Static_assert(sizeof(struct B21_packed) == 128, "record B21 wrong sizeof");
_Static_assert(_Alignof(struct B21_packed) == 1, "record B21 wrong alignment");
_Static_assert(sizeof(struct B21_required_alignment) == 129, "record B21 wrong sizeof");
_Static_assert(_Alignof(struct B21_required_alignment) == 1, "record B21 wrong alignment");
_Static_assert(sizeof(struct B21_size) == 130, "record B21 wrong sizeof");
_Static_assert(_Alignof(struct B21_size) == 1, "record B21 wrong alignment");
#endif
_Static_assert(sizeof(B22) == 128, "record B22 wrong sizeof");
_Static_assert(_Alignof(B22) == 128, "record B22 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B22_alignment) == 256, "record B22 wrong sizeof");
_Static_assert(_Alignof(struct B22_alignment) == 128, "record B22 wrong alignment");
_Static_assert(sizeof(struct B22_packed) == 128, "record B22 wrong sizeof");
_Static_assert(_Alignof(struct B22_packed) == 1, "record B22 wrong alignment");
_Static_assert(sizeof(struct B22_required_alignment) == 129, "record B22 wrong sizeof");
_Static_assert(_Alignof(struct B22_required_alignment) == 1, "record B22 wrong alignment");
_Static_assert(sizeof(struct B22_size) == 130, "record B22 wrong sizeof");
_Static_assert(_Alignof(struct B22_size) == 1, "record B22 wrong alignment");
#endif
_Static_assert(sizeof(B23) == 128, "record B23 wrong sizeof");
_Static_assert(_Alignof(B23) == 128, "record B23 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B23_alignment) == 256, "record B23 wrong sizeof");
_Static_assert(_Alignof(struct B23_alignment) == 128, "record B23 wrong alignment");
_Static_assert(sizeof(struct B23_packed) == 128, "record B23 wrong sizeof");
_Static_assert(_Alignof(struct B23_packed) == 1, "record B23 wrong alignment");
_Static_assert(sizeof(struct B23_required_alignment) == 129, "record B23 wrong sizeof");
_Static_assert(_Alignof(struct B23_required_alignment) == 1, "record B23 wrong alignment");
_Static_assert(sizeof(struct B23_size) == 130, "record B23 wrong sizeof");
_Static_assert(_Alignof(struct B23_size) == 1, "record B23 wrong alignment");
#endif
_Static_assert(sizeof(B24) == 128, "record B24 wrong sizeof");
_Static_assert(_Alignof(B24) == 128, "record B24 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B24_alignment) == 256, "record B24 wrong sizeof");
_Static_assert(_Alignof(struct B24_alignment) == 128, "record B24 wrong alignment");
_Static_assert(sizeof(struct B24_packed) == 128, "record B24 wrong sizeof");
_Static_assert(_Alignof(struct B24_packed) == 1, "record B24 wrong alignment");
_Static_assert(sizeof(struct B24_required_alignment) == 129, "record B24 wrong sizeof");
_Static_assert(_Alignof(struct B24_required_alignment) == 1, "record B24 wrong alignment");
_Static_assert(sizeof(struct B24_size) == 130, "record B24 wrong sizeof");
_Static_assert(_Alignof(struct B24_size) == 1, "record B24 wrong alignment");
#endif
_Static_assert(sizeof(B25) == 128, "record B25 wrong sizeof");
_Static_assert(_Alignof(B25) == 128, "record B25 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B25_alignment) == 256, "record B25 wrong sizeof");
_Static_assert(_Alignof(struct B25_alignment) == 128, "record B25 wrong alignment");
_Static_assert(sizeof(struct B25_packed) == 128, "record B25 wrong sizeof");
_Static_assert(_Alignof(struct B25_packed) == 1, "record B25 wrong alignment");
_Static_assert(sizeof(struct B25_required_alignment) == 129, "record B25 wrong sizeof");
_Static_assert(_Alignof(struct B25_required_alignment) == 1, "record B25 wrong alignment");
_Static_assert(sizeof(struct B25_size) == 130, "record B25 wrong sizeof");
_Static_assert(_Alignof(struct B25_size) == 1, "record B25 wrong alignment");
#endif
_Static_assert(sizeof(B26) == 128, "record B26 wrong sizeof");
_Static_assert(_Alignof(B26) == 128, "record B26 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B26_alignment) == 256, "record B26 wrong sizeof");
_Static_assert(_Alignof(struct B26_alignment) == 128, "record B26 wrong alignment");
_Static_assert(sizeof(struct B26_packed) == 128, "record B26 wrong sizeof");
_Static_assert(_Alignof(struct B26_packed) == 1, "record B26 wrong alignment");
_Static_assert(sizeof(struct B26_required_alignment) == 129, "record B26 wrong sizeof");
_Static_assert(_Alignof(struct B26_required_alignment) == 1, "record B26 wrong alignment");
_Static_assert(sizeof(struct B26_size) == 130, "record B26 wrong sizeof");
_Static_assert(_Alignof(struct B26_size) == 1, "record B26 wrong alignment");
#endif
_Static_assert(sizeof(B27) == 128, "record B27 wrong sizeof");
_Static_assert(_Alignof(B27) == 128, "record B27 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B27_alignment) == 256, "record B27 wrong sizeof");
_Static_assert(_Alignof(struct B27_alignment) == 128, "record B27 wrong alignment");
_Static_assert(sizeof(struct B27_packed) == 128, "record B27 wrong sizeof");
_Static_assert(_Alignof(struct B27_packed) == 1, "record B27 wrong alignment");
_Static_assert(sizeof(struct B27_required_alignment) == 129, "record B27 wrong sizeof");
_Static_assert(_Alignof(struct B27_required_alignment) == 1, "record B27 wrong alignment");
_Static_assert(sizeof(struct B27_size) == 130, "record B27 wrong sizeof");
_Static_assert(_Alignof(struct B27_size) == 1, "record B27 wrong alignment");
#endif
_Static_assert(sizeof(B28) == 128, "record B28 wrong sizeof");
_Static_assert(_Alignof(B28) == 128, "record B28 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B28_alignment) == 256, "record B28 wrong sizeof");
_Static_assert(_Alignof(struct B28_alignment) == 128, "record B28 wrong alignment");
_Static_assert(sizeof(struct B28_packed) == 128, "record B28 wrong sizeof");
_Static_assert(_Alignof(struct B28_packed) == 1, "record B28 wrong alignment");
_Static_assert(sizeof(struct B28_required_alignment) == 129, "record B28 wrong sizeof");
_Static_assert(_Alignof(struct B28_required_alignment) == 1, "record B28 wrong alignment");
_Static_assert(sizeof(struct B28_size) == 130, "record B28 wrong sizeof");
_Static_assert(_Alignof(struct B28_size) == 1, "record B28 wrong alignment");
#endif
_Static_assert(sizeof(B29) == 128, "record B29 wrong sizeof");
_Static_assert(_Alignof(B29) == 128, "record B29 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B29_alignment) == 256, "record B29 wrong sizeof");
_Static_assert(_Alignof(struct B29_alignment) == 128, "record B29 wrong alignment");
_Static_assert(sizeof(struct B29_packed) == 128, "record B29 wrong sizeof");
_Static_assert(_Alignof(struct B29_packed) == 1, "record B29 wrong alignment");
_Static_assert(sizeof(struct B29_required_alignment) == 129, "record B29 wrong sizeof");
_Static_assert(_Alignof(struct B29_required_alignment) == 1, "record B29 wrong alignment");
_Static_assert(sizeof(struct B29_size) == 130, "record B29 wrong sizeof");
_Static_assert(_Alignof(struct B29_size) == 1, "record B29 wrong alignment");
#endif
_Static_assert(sizeof(B30) == 128, "record B30 wrong sizeof");
_Static_assert(_Alignof(B30) == 128, "record B30 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B30_alignment) == 256, "record B30 wrong sizeof");
_Static_assert(_Alignof(struct B30_alignment) == 128, "record B30 wrong alignment");
_Static_assert(sizeof(struct B30_packed) == 128, "record B30 wrong sizeof");
_Static_assert(_Alignof(struct B30_packed) == 1, "record B30 wrong alignment");
_Static_assert(sizeof(struct B30_required_alignment) == 129, "record B30 wrong sizeof");
_Static_assert(_Alignof(struct B30_required_alignment) == 1, "record B30 wrong alignment");
_Static_assert(sizeof(struct B30_size) == 130, "record B30 wrong sizeof");
_Static_assert(_Alignof(struct B30_size) == 1, "record B30 wrong alignment");
#endif
_Static_assert(sizeof(B31) == 128, "record B31 wrong sizeof");
_Static_assert(_Alignof(B31) == 128, "record B31 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B31_alignment) == 256, "record B31 wrong sizeof");
_Static_assert(_Alignof(struct B31_alignment) == 128, "record B31 wrong alignment");
_Static_assert(sizeof(struct B31_packed) == 128, "record B31 wrong sizeof");
_Static_assert(_Alignof(struct B31_packed) == 1, "record B31 wrong alignment");
_Static_assert(sizeof(struct B31_required_alignment) == 129, "record B31 wrong sizeof");
_Static_assert(_Alignof(struct B31_required_alignment) == 1, "record B31 wrong alignment");
_Static_assert(sizeof(struct B31_size) == 130, "record B31 wrong sizeof");
_Static_assert(_Alignof(struct B31_size) == 1, "record B31 wrong alignment");
#endif
_Static_assert(sizeof(B32) == 128, "record B32 wrong sizeof");
_Static_assert(_Alignof(B32) == 128, "record B32 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B32_alignment) == 256, "record B32 wrong sizeof");
_Static_assert(_Alignof(struct B32_alignment) == 128, "record B32 wrong alignment");
_Static_assert(sizeof(struct B32_packed) == 128, "record B32 wrong sizeof");
_Static_assert(_Alignof(struct B32_packed) == 1, "record B32 wrong alignment");
_Static_assert(sizeof(struct B32_required_alignment) == 129, "record B32 wrong sizeof");
_Static_assert(_Alignof(struct B32_required_alignment) == 1, "record B32 wrong alignment");
_Static_assert(sizeof(struct B32_size) == 130, "record B32 wrong sizeof");
_Static_assert(_Alignof(struct B32_size) == 1, "record B32 wrong alignment");
#endif
_Static_assert(sizeof(B33) == 128, "record B33 wrong sizeof");
_Static_assert(_Alignof(B33) == 128, "record B33 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B33_alignment) == 256, "record B33 wrong sizeof");
_Static_assert(_Alignof(struct B33_alignment) == 128, "record B33 wrong alignment");
_Static_assert(sizeof(struct B33_packed) == 128, "record B33 wrong sizeof");
_Static_assert(_Alignof(struct B33_packed) == 1, "record B33 wrong alignment");
_Static_assert(sizeof(struct B33_required_alignment) == 129, "record B33 wrong sizeof");
_Static_assert(_Alignof(struct B33_required_alignment) == 1, "record B33 wrong alignment");
_Static_assert(sizeof(struct B33_size) == 130, "record B33 wrong sizeof");
_Static_assert(_Alignof(struct B33_size) == 1, "record B33 wrong alignment");
#endif
_Static_assert(sizeof(B34) == 128, "record B34 wrong sizeof");
_Static_assert(_Alignof(B34) == 128, "record B34 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B34_alignment) == 256, "record B34 wrong sizeof");
_Static_assert(_Alignof(struct B34_alignment) == 128, "record B34 wrong alignment");
_Static_assert(sizeof(struct B34_packed) == 128, "record B34 wrong sizeof");
_Static_assert(_Alignof(struct B34_packed) == 1, "record B34 wrong alignment");
_Static_assert(sizeof(struct B34_required_alignment) == 129, "record B34 wrong sizeof");
_Static_assert(_Alignof(struct B34_required_alignment) == 1, "record B34 wrong alignment");
_Static_assert(sizeof(struct B34_size) == 130, "record B34 wrong sizeof");
_Static_assert(_Alignof(struct B34_size) == 1, "record B34 wrong alignment");
#endif
_Static_assert(sizeof(B35) == 128, "record B35 wrong sizeof");
_Static_assert(_Alignof(B35) == 128, "record B35 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B35_alignment) == 256, "record B35 wrong sizeof");
_Static_assert(_Alignof(struct B35_alignment) == 128, "record B35 wrong alignment");
_Static_assert(sizeof(struct B35_packed) == 128, "record B35 wrong sizeof");
_Static_assert(_Alignof(struct B35_packed) == 1, "record B35 wrong alignment");
_Static_assert(sizeof(struct B35_required_alignment) == 129, "record B35 wrong sizeof");
_Static_assert(_Alignof(struct B35_required_alignment) == 1, "record B35 wrong alignment");
_Static_assert(sizeof(struct B35_size) == 130, "record B35 wrong sizeof");
_Static_assert(_Alignof(struct B35_size) == 1, "record B35 wrong alignment");
#endif
_Static_assert(sizeof(B36) == 128, "record B36 wrong sizeof");
_Static_assert(_Alignof(B36) == 128, "record B36 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B36_alignment) == 256, "record B36 wrong sizeof");
_Static_assert(_Alignof(struct B36_alignment) == 128, "record B36 wrong alignment");
_Static_assert(sizeof(struct B36_packed) == 128, "record B36 wrong sizeof");
_Static_assert(_Alignof(struct B36_packed) == 1, "record B36 wrong alignment");
_Static_assert(sizeof(struct B36_required_alignment) == 129, "record B36 wrong sizeof");
_Static_assert(_Alignof(struct B36_required_alignment) == 1, "record B36 wrong alignment");
_Static_assert(sizeof(struct B36_size) == 130, "record B36 wrong sizeof");
_Static_assert(_Alignof(struct B36_size) == 1, "record B36 wrong alignment");
#endif
_Static_assert(sizeof(B37) == 128, "record B37 wrong sizeof");
_Static_assert(_Alignof(B37) == 128, "record B37 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B37_alignment) == 256, "record B37 wrong sizeof");
_Static_assert(_Alignof(struct B37_alignment) == 128, "record B37 wrong alignment");
_Static_assert(sizeof(struct B37_packed) == 128, "record B37 wrong sizeof");
_Static_assert(_Alignof(struct B37_packed) == 1, "record B37 wrong alignment");
_Static_assert(sizeof(struct B37_required_alignment) == 129, "record B37 wrong sizeof");
_Static_assert(_Alignof(struct B37_required_alignment) == 1, "record B37 wrong alignment");
_Static_assert(sizeof(struct B37_size) == 130, "record B37 wrong sizeof");
_Static_assert(_Alignof(struct B37_size) == 1, "record B37 wrong alignment");
#endif
_Static_assert(sizeof(B38) == 128, "record B38 wrong sizeof");
_Static_assert(_Alignof(B38) == 128, "record B38 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B38_alignment) == 256, "record B38 wrong sizeof");
_Static_assert(_Alignof(struct B38_alignment) == 128, "record B38 wrong alignment");
_Static_assert(sizeof(struct B38_packed) == 128, "record B38 wrong sizeof");
_Static_assert(_Alignof(struct B38_packed) == 1, "record B38 wrong alignment");
_Static_assert(sizeof(struct B38_required_alignment) == 129, "record B38 wrong sizeof");
_Static_assert(_Alignof(struct B38_required_alignment) == 1, "record B38 wrong alignment");
_Static_assert(sizeof(struct B38_size) == 130, "record B38 wrong sizeof");
_Static_assert(_Alignof(struct B38_size) == 1, "record B38 wrong alignment");
#endif
_Static_assert(sizeof(B39) == 128, "record B39 wrong sizeof");
_Static_assert(_Alignof(B39) == 128, "record B39 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B39_alignment) == 256, "record B39 wrong sizeof");
_Static_assert(_Alignof(struct B39_alignment) == 128, "record B39 wrong alignment");
_Static_assert(sizeof(struct B39_packed) == 128, "record B39 wrong sizeof");
_Static_assert(_Alignof(struct B39_packed) == 1, "record B39 wrong alignment");
_Static_assert(sizeof(struct B39_required_alignment) == 129, "record B39 wrong sizeof");
_Static_assert(_Alignof(struct B39_required_alignment) == 1, "record B39 wrong alignment");
_Static_assert(sizeof(struct B39_size) == 130, "record B39 wrong sizeof");
_Static_assert(_Alignof(struct B39_size) == 1, "record B39 wrong alignment");
#endif
// MAPPING|THREE|arm-cortex_r4-ios-none:Clang|arm-baseline-ios-none:Clang|i386-i386-ios-none:Clang|i386-i586-linux-gnu:Gcc|i386-i586-linux-musl:Gcc|x86_64-i686-macos-none:Clang|i386-i686-linux-android:Clang|i386-i686-freebsd-gnu:Clang|i386-i686-haiku-gnu:Clang|i386-i686-linux-gnu:Gcc|i386-i686-linux-musl:Gcc|i386-i686-netbsd-gnu:Clang|i386-i686-openbsd-gnu:Clang|END
// repr targets Armv7AppleIos|Some("arm-cortex_r4-ios-none") Armv7sAppleIos|Some("arm-baseline-ios-none") I386AppleIos|Some("i386-i386-ios-none") I586UnknownLinuxGnu|Some("i386-i586-linux-gnu") I586UnknownLinuxMusl|Some("i386-i586-linux-musl") I686AppleMacosx|Some("x86_64-i686-macos-none") I686LinuxAndroid|Some("i386-i686-linux-android") I686UnknownFreebsd|Some("i386-i686-freebsd-gnu") I686UnknownHaiku|Some("i386-i686-haiku-gnu") I686UnknownLinuxGnu|Some("i386-i686-linux-gnu") I686UnknownLinuxMusl|Some("i386-i686-linux-musl") I686UnknownNetbsdelf|Some("i386-i686-netbsd-gnu") I686UnknownOpenbsd|Some("i386-i686-openbsd-gnu") 
#elif defined(THREE)
_Static_assert(sizeof(A00) == 128, "record A00 wrong sizeof");
_Static_assert(_Alignof(A00) == 128, "record A00 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A00_alignment) == 256, "record A00 wrong sizeof");
_Static_assert(_Alignof(struct A00_alignment) == 128, "record A00 wrong alignment");
_Static_assert(sizeof(struct A00_packed) == 128, "record A00 wrong sizeof");
_Static_assert(_Alignof(struct A00_packed) == 1, "record A00 wrong alignment");
_Static_assert(sizeof(struct A00_required_alignment) == 129, "record A00 wrong sizeof");
_Static_assert(_Alignof(struct A00_required_alignment) == 1, "record A00 wrong alignment");
_Static_assert(sizeof(struct A00_size) == 130, "record A00 wrong sizeof");
_Static_assert(_Alignof(struct A00_size) == 1, "record A00 wrong alignment");
#endif
_Static_assert(sizeof(A01) == 8, "record A01 wrong sizeof");
_Static_assert(_Alignof(A01) == 1, "record A01 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A01_alignment) == 9, "record A01 wrong sizeof");
_Static_assert(_Alignof(struct A01_alignment) == 1, "record A01 wrong alignment");
_Static_assert(sizeof(struct A01_packed) == 8, "record A01 wrong sizeof");
_Static_assert(_Alignof(struct A01_packed) == 1, "record A01 wrong alignment");
_Static_assert(sizeof(struct A01_required_alignment) == 9, "record A01 wrong sizeof");
_Static_assert(_Alignof(struct A01_required_alignment) == 1, "record A01 wrong alignment");
_Static_assert(sizeof(struct A01_size) == 10, "record A01 wrong sizeof");
_Static_assert(_Alignof(struct A01_size) == 1, "record A01 wrong alignment");
#endif
_Static_assert(sizeof(A02) == 8, "record A02 wrong sizeof");
_Static_assert(_Alignof(A02) == 2, "record A02 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A02_alignment) == 10, "record A02 wrong sizeof");
_Static_assert(_Alignof(struct A02_alignment) == 2, "record A02 wrong alignment");
_Static_assert(sizeof(struct A02_packed) == 8, "record A02 wrong sizeof");
_Static_assert(_Alignof(struct A02_packed) == 1, "record A02 wrong alignment");
_Static_assert(sizeof(struct A02_required_alignment) == 9, "record A02 wrong sizeof");
_Static_assert(_Alignof(struct A02_required_alignment) == 1, "record A02 wrong alignment");
_Static_assert(sizeof(struct A02_size) == 10, "record A02 wrong sizeof");
_Static_assert(_Alignof(struct A02_size) == 1, "record A02 wrong alignment");
#endif
_Static_assert(sizeof(A03) == 128, "record A03 wrong sizeof");
_Static_assert(_Alignof(A03) == 128, "record A03 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A03_alignment) == 256, "record A03 wrong sizeof");
_Static_assert(_Alignof(struct A03_alignment) == 128, "record A03 wrong alignment");
_Static_assert(sizeof(struct A03_packed) == 128, "record A03 wrong sizeof");
_Static_assert(_Alignof(struct A03_packed) == 1, "record A03 wrong alignment");
_Static_assert(sizeof(struct A03_required_alignment) == 129, "record A03 wrong sizeof");
_Static_assert(_Alignof(struct A03_required_alignment) == 1, "record A03 wrong alignment");
_Static_assert(sizeof(struct A03_size) == 130, "record A03 wrong sizeof");
_Static_assert(_Alignof(struct A03_size) == 1, "record A03 wrong alignment");
#endif
_Static_assert(sizeof(A04) == 8, "record A04 wrong sizeof");
_Static_assert(_Alignof(A04) == 4, "record A04 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A04_alignment) == 12, "record A04 wrong sizeof");
_Static_assert(_Alignof(struct A04_alignment) == 4, "record A04 wrong alignment");
_Static_assert(sizeof(struct A04_packed) == 8, "record A04 wrong sizeof");
_Static_assert(_Alignof(struct A04_packed) == 1, "record A04 wrong alignment");
_Static_assert(sizeof(struct A04_required_alignment) == 9, "record A04 wrong sizeof");
_Static_assert(_Alignof(struct A04_required_alignment) == 1, "record A04 wrong alignment");
_Static_assert(sizeof(struct A04_size) == 10, "record A04 wrong sizeof");
_Static_assert(_Alignof(struct A04_size) == 1, "record A04 wrong alignment");
#endif
_Static_assert(sizeof(A05) == 128, "record A05 wrong sizeof");
_Static_assert(_Alignof(A05) == 128, "record A05 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A05_alignment) == 256, "record A05 wrong sizeof");
_Static_assert(_Alignof(struct A05_alignment) == 128, "record A05 wrong alignment");
_Static_assert(sizeof(struct A05_packed) == 128, "record A05 wrong sizeof");
_Static_assert(_Alignof(struct A05_packed) == 1, "record A05 wrong alignment");
_Static_assert(sizeof(struct A05_required_alignment) == 129, "record A05 wrong sizeof");
_Static_assert(_Alignof(struct A05_required_alignment) == 1, "record A05 wrong alignment");
_Static_assert(sizeof(struct A05_size) == 130, "record A05 wrong sizeof");
_Static_assert(_Alignof(struct A05_size) == 1, "record A05 wrong alignment");
#endif
_Static_assert(sizeof(A06) == 128, "record A06 wrong sizeof");
_Static_assert(_Alignof(A06) == 128, "record A06 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A06_alignment) == 256, "record A06 wrong sizeof");
_Static_assert(_Alignof(struct A06_alignment) == 128, "record A06 wrong alignment");
_Static_assert(sizeof(struct A06_packed) == 128, "record A06 wrong sizeof");
_Static_assert(_Alignof(struct A06_packed) == 1, "record A06 wrong alignment");
_Static_assert(sizeof(struct A06_required_alignment) == 129, "record A06 wrong sizeof");
_Static_assert(_Alignof(struct A06_required_alignment) == 1, "record A06 wrong alignment");
_Static_assert(sizeof(struct A06_size) == 130, "record A06 wrong sizeof");
_Static_assert(_Alignof(struct A06_size) == 1, "record A06 wrong alignment");
#endif
_Static_assert(sizeof(A07) == 128, "record A07 wrong sizeof");
_Static_assert(_Alignof(A07) == 128, "record A07 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A07_alignment) == 256, "record A07 wrong sizeof");
_Static_assert(_Alignof(struct A07_alignment) == 128, "record A07 wrong alignment");
_Static_assert(sizeof(struct A07_packed) == 128, "record A07 wrong sizeof");
_Static_assert(_Alignof(struct A07_packed) == 1, "record A07 wrong alignment");
_Static_assert(sizeof(struct A07_required_alignment) == 129, "record A07 wrong sizeof");
_Static_assert(_Alignof(struct A07_required_alignment) == 1, "record A07 wrong alignment");
_Static_assert(sizeof(struct A07_size) == 130, "record A07 wrong sizeof");
_Static_assert(_Alignof(struct A07_size) == 1, "record A07 wrong alignment");
#endif
_Static_assert(sizeof(A08) == 8, "record A08 wrong sizeof");
_Static_assert(_Alignof(A08) == 8, "record A08 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A08_alignment) == 16, "record A08 wrong sizeof");
_Static_assert(_Alignof(struct A08_alignment) == 8, "record A08 wrong alignment");
_Static_assert(sizeof(struct A08_packed) == 8, "record A08 wrong sizeof");
_Static_assert(_Alignof(struct A08_packed) == 1, "record A08 wrong alignment");
_Static_assert(sizeof(struct A08_required_alignment) == 9, "record A08 wrong sizeof");
_Static_assert(_Alignof(struct A08_required_alignment) == 1, "record A08 wrong alignment");
_Static_assert(sizeof(struct A08_size) == 10, "record A08 wrong sizeof");
_Static_assert(_Alignof(struct A08_size) == 1, "record A08 wrong alignment");
#endif
_Static_assert(sizeof(A09) == 128, "record A09 wrong sizeof");
_Static_assert(_Alignof(A09) == 128, "record A09 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A09_alignment) == 256, "record A09 wrong sizeof");
_Static_assert(_Alignof(struct A09_alignment) == 128, "record A09 wrong alignment");
_Static_assert(sizeof(struct A09_packed) == 128, "record A09 wrong sizeof");
_Static_assert(_Alignof(struct A09_packed) == 1, "record A09 wrong alignment");
_Static_assert(sizeof(struct A09_required_alignment) == 129, "record A09 wrong sizeof");
_Static_assert(_Alignof(struct A09_required_alignment) == 1, "record A09 wrong alignment");
_Static_assert(sizeof(struct A09_size) == 130, "record A09 wrong sizeof");
_Static_assert(_Alignof(struct A09_size) == 1, "record A09 wrong alignment");
#endif
_Static_assert(sizeof(A10) == 128, "record A10 wrong sizeof");
_Static_assert(_Alignof(A10) == 128, "record A10 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A10_alignment) == 256, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_alignment) == 128, "record A10 wrong alignment");
_Static_assert(sizeof(struct A10_packed) == 128, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_packed) == 1, "record A10 wrong alignment");
_Static_assert(sizeof(struct A10_required_alignment) == 129, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_required_alignment) == 1, "record A10 wrong alignment");
_Static_assert(sizeof(struct A10_size) == 130, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_size) == 1, "record A10 wrong alignment");
#endif
_Static_assert(sizeof(A11) == 128, "record A11 wrong sizeof");
_Static_assert(_Alignof(A11) == 128, "record A11 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A11_alignment) == 256, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_alignment) == 128, "record A11 wrong alignment");
_Static_assert(sizeof(struct A11_packed) == 128, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_packed) == 1, "record A11 wrong alignment");
_Static_assert(sizeof(struct A11_required_alignment) == 129, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_required_alignment) == 1, "record A11 wrong alignment");
_Static_assert(sizeof(struct A11_size) == 130, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_size) == 1, "record A11 wrong alignment");
#endif
_Static_assert(sizeof(A12) == 128, "record A12 wrong sizeof");
_Static_assert(_Alignof(A12) == 128, "record A12 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A12_alignment) == 256, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_alignment) == 128, "record A12 wrong alignment");
_Static_assert(sizeof(struct A12_packed) == 128, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_packed) == 1, "record A12 wrong alignment");
_Static_assert(sizeof(struct A12_required_alignment) == 129, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_required_alignment) == 1, "record A12 wrong alignment");
_Static_assert(sizeof(struct A12_size) == 130, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_size) == 1, "record A12 wrong alignment");
#endif
_Static_assert(sizeof(A13) == 128, "record A13 wrong sizeof");
_Static_assert(_Alignof(A13) == 128, "record A13 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A13_alignment) == 256, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_alignment) == 128, "record A13 wrong alignment");
_Static_assert(sizeof(struct A13_packed) == 128, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_packed) == 1, "record A13 wrong alignment");
_Static_assert(sizeof(struct A13_required_alignment) == 129, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_required_alignment) == 1, "record A13 wrong alignment");
_Static_assert(sizeof(struct A13_size) == 130, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_size) == 1, "record A13 wrong alignment");
#endif
_Static_assert(sizeof(A14) == 128, "record A14 wrong sizeof");
_Static_assert(_Alignof(A14) == 128, "record A14 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A14_alignment) == 256, "record A14 wrong sizeof");
_Static_assert(_Alignof(struct A14_alignment) == 128, "record A14 wrong alignment");
_Static_assert(sizeof(struct A14_packed) == 128, "record A14 wrong sizeof");
_Static_assert(_Alignof(struct A14_packed) == 1, "record A14 wrong alignment");
_Static_assert(sizeof(struct A14_required_alignment) == 129, "record A14 wrong sizeof");
_Static_assert(_Alignof(struct A14_required_alignment) == 1, "record A14 wrong alignment");
_Static_assert(sizeof(struct A14_size) == 130, "record A14 wrong sizeof");
_Static_assert(_Alignof(struct A14_size) == 1, "record A14 wrong alignment");
#endif
_Static_assert(sizeof(A15) == 128, "record A15 wrong sizeof");
_Static_assert(_Alignof(A15) == 128, "record A15 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A15_alignment) == 256, "record A15 wrong sizeof");
_Static_assert(_Alignof(struct A15_alignment) == 128, "record A15 wrong alignment");
_Static_assert(sizeof(struct A15_packed) == 128, "record A15 wrong sizeof");
_Static_assert(_Alignof(struct A15_packed) == 1, "record A15 wrong alignment");
_Static_assert(sizeof(struct A15_required_alignment) == 129, "record A15 wrong sizeof");
_Static_assert(_Alignof(struct A15_required_alignment) == 1, "record A15 wrong alignment");
_Static_assert(sizeof(struct A15_size) == 130, "record A15 wrong sizeof");
_Static_assert(_Alignof(struct A15_size) == 1, "record A15 wrong alignment");
#endif
_Static_assert(sizeof(A16) == 16, "record A16 wrong sizeof");
_Static_assert(_Alignof(A16) == 16, "record A16 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A16_alignment) == 32, "record A16 wrong sizeof");
_Static_assert(_Alignof(struct A16_alignment) == 16, "record A16 wrong alignment");
_Static_assert(sizeof(struct A16_packed) == 16, "record A16 wrong sizeof");
_Static_assert(_Alignof(struct A16_packed) == 1, "record A16 wrong alignment");
_Static_assert(sizeof(struct A16_required_alignment) == 17, "record A16 wrong sizeof");
_Static_assert(_Alignof(struct A16_required_alignment) == 1, "record A16 wrong alignment");
_Static_assert(sizeof(struct A16_size) == 18, "record A16 wrong sizeof");
_Static_assert(_Alignof(struct A16_size) == 1, "record A16 wrong alignment");
#endif
_Static_assert(sizeof(A17) == 128, "record A17 wrong sizeof");
_Static_assert(_Alignof(A17) == 128, "record A17 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A17_alignment) == 256, "record A17 wrong sizeof");
_Static_assert(_Alignof(struct A17_alignment) == 128, "record A17 wrong alignment");
_Static_assert(sizeof(struct A17_packed) == 128, "record A17 wrong sizeof");
_Static_assert(_Alignof(struct A17_packed) == 1, "record A17 wrong alignment");
_Static_assert(sizeof(struct A17_required_alignment) == 129, "record A17 wrong sizeof");
_Static_assert(_Alignof(struct A17_required_alignment) == 1, "record A17 wrong alignment");
_Static_assert(sizeof(struct A17_size) == 130, "record A17 wrong sizeof");
_Static_assert(_Alignof(struct A17_size) == 1, "record A17 wrong alignment");
#endif
_Static_assert(sizeof(A18) == 128, "record A18 wrong sizeof");
_Static_assert(_Alignof(A18) == 128, "record A18 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A18_alignment) == 256, "record A18 wrong sizeof");
_Static_assert(_Alignof(struct A18_alignment) == 128, "record A18 wrong alignment");
_Static_assert(sizeof(struct A18_packed) == 128, "record A18 wrong sizeof");
_Static_assert(_Alignof(struct A18_packed) == 1, "record A18 wrong alignment");
_Static_assert(sizeof(struct A18_required_alignment) == 129, "record A18 wrong sizeof");
_Static_assert(_Alignof(struct A18_required_alignment) == 1, "record A18 wrong alignment");
_Static_assert(sizeof(struct A18_size) == 130, "record A18 wrong sizeof");
_Static_assert(_Alignof(struct A18_size) == 1, "record A18 wrong alignment");
#endif
_Static_assert(sizeof(A19) == 128, "record A19 wrong sizeof");
_Static_assert(_Alignof(A19) == 128, "record A19 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A19_alignment) == 256, "record A19 wrong sizeof");
_Static_assert(_Alignof(struct A19_alignment) == 128, "record A19 wrong alignment");
_Static_assert(sizeof(struct A19_packed) == 128, "record A19 wrong sizeof");
_Static_assert(_Alignof(struct A19_packed) == 1, "record A19 wrong alignment");
_Static_assert(sizeof(struct A19_required_alignment) == 129, "record A19 wrong sizeof");
_Static_assert(_Alignof(struct A19_required_alignment) == 1, "record A19 wrong alignment");
_Static_assert(sizeof(struct A19_size) == 130, "record A19 wrong sizeof");
_Static_assert(_Alignof(struct A19_size) == 1, "record A19 wrong alignment");
#endif
_Static_assert(sizeof(A20) == 128, "record A20 wrong sizeof");
_Static_assert(_Alignof(A20) == 128, "record A20 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A20_alignment) == 256, "record A20 wrong sizeof");
_Static_assert(_Alignof(struct A20_alignment) == 128, "record A20 wrong alignment");
_Static_assert(sizeof(struct A20_packed) == 128, "record A20 wrong sizeof");
_Static_assert(_Alignof(struct A20_packed) == 1, "record A20 wrong alignment");
_Static_assert(sizeof(struct A20_required_alignment) == 129, "record A20 wrong sizeof");
_Static_assert(_Alignof(struct A20_required_alignment) == 1, "record A20 wrong alignment");
_Static_assert(sizeof(struct A20_size) == 130, "record A20 wrong sizeof");
_Static_assert(_Alignof(struct A20_size) == 1, "record A20 wrong alignment");
#endif
_Static_assert(sizeof(A21) == 128, "record A21 wrong sizeof");
_Static_assert(_Alignof(A21) == 128, "record A21 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A21_alignment) == 256, "record A21 wrong sizeof");
_Static_assert(_Alignof(struct A21_alignment) == 128, "record A21 wrong alignment");
_Static_assert(sizeof(struct A21_packed) == 128, "record A21 wrong sizeof");
_Static_assert(_Alignof(struct A21_packed) == 1, "record A21 wrong alignment");
_Static_assert(sizeof(struct A21_required_alignment) == 129, "record A21 wrong sizeof");
_Static_assert(_Alignof(struct A21_required_alignment) == 1, "record A21 wrong alignment");
_Static_assert(sizeof(struct A21_size) == 130, "record A21 wrong sizeof");
_Static_assert(_Alignof(struct A21_size) == 1, "record A21 wrong alignment");
#endif
_Static_assert(sizeof(A22) == 128, "record A22 wrong sizeof");
_Static_assert(_Alignof(A22) == 128, "record A22 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A22_alignment) == 256, "record A22 wrong sizeof");
_Static_assert(_Alignof(struct A22_alignment) == 128, "record A22 wrong alignment");
_Static_assert(sizeof(struct A22_packed) == 128, "record A22 wrong sizeof");
_Static_assert(_Alignof(struct A22_packed) == 1, "record A22 wrong alignment");
_Static_assert(sizeof(struct A22_required_alignment) == 129, "record A22 wrong sizeof");
_Static_assert(_Alignof(struct A22_required_alignment) == 1, "record A22 wrong alignment");
_Static_assert(sizeof(struct A22_size) == 130, "record A22 wrong sizeof");
_Static_assert(_Alignof(struct A22_size) == 1, "record A22 wrong alignment");
#endif
_Static_assert(sizeof(A23) == 128, "record A23 wrong sizeof");
_Static_assert(_Alignof(A23) == 128, "record A23 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A23_alignment) == 256, "record A23 wrong sizeof");
_Static_assert(_Alignof(struct A23_alignment) == 128, "record A23 wrong alignment");
_Static_assert(sizeof(struct A23_packed) == 128, "record A23 wrong sizeof");
_Static_assert(_Alignof(struct A23_packed) == 1, "record A23 wrong alignment");
_Static_assert(sizeof(struct A23_required_alignment) == 129, "record A23 wrong sizeof");
_Static_assert(_Alignof(struct A23_required_alignment) == 1, "record A23 wrong alignment");
_Static_assert(sizeof(struct A23_size) == 130, "record A23 wrong sizeof");
_Static_assert(_Alignof(struct A23_size) == 1, "record A23 wrong alignment");
#endif
_Static_assert(sizeof(A24) == 128, "record A24 wrong sizeof");
_Static_assert(_Alignof(A24) == 128, "record A24 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A24_alignment) == 256, "record A24 wrong sizeof");
_Static_assert(_Alignof(struct A24_alignment) == 128, "record A24 wrong alignment");
_Static_assert(sizeof(struct A24_packed) == 128, "record A24 wrong sizeof");
_Static_assert(_Alignof(struct A24_packed) == 1, "record A24 wrong alignment");
_Static_assert(sizeof(struct A24_required_alignment) == 129, "record A24 wrong sizeof");
_Static_assert(_Alignof(struct A24_required_alignment) == 1, "record A24 wrong alignment");
_Static_assert(sizeof(struct A24_size) == 130, "record A24 wrong sizeof");
_Static_assert(_Alignof(struct A24_size) == 1, "record A24 wrong alignment");
#endif
_Static_assert(sizeof(A25) == 128, "record A25 wrong sizeof");
_Static_assert(_Alignof(A25) == 128, "record A25 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A25_alignment) == 256, "record A25 wrong sizeof");
_Static_assert(_Alignof(struct A25_alignment) == 128, "record A25 wrong alignment");
_Static_assert(sizeof(struct A25_packed) == 128, "record A25 wrong sizeof");
_Static_assert(_Alignof(struct A25_packed) == 1, "record A25 wrong alignment");
_Static_assert(sizeof(struct A25_required_alignment) == 129, "record A25 wrong sizeof");
_Static_assert(_Alignof(struct A25_required_alignment) == 1, "record A25 wrong alignment");
_Static_assert(sizeof(struct A25_size) == 130, "record A25 wrong sizeof");
_Static_assert(_Alignof(struct A25_size) == 1, "record A25 wrong alignment");
#endif
_Static_assert(sizeof(A26) == 128, "record A26 wrong sizeof");
_Static_assert(_Alignof(A26) == 128, "record A26 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A26_alignment) == 256, "record A26 wrong sizeof");
_Static_assert(_Alignof(struct A26_alignment) == 128, "record A26 wrong alignment");
_Static_assert(sizeof(struct A26_packed) == 128, "record A26 wrong sizeof");
_Static_assert(_Alignof(struct A26_packed) == 1, "record A26 wrong alignment");
_Static_assert(sizeof(struct A26_required_alignment) == 129, "record A26 wrong sizeof");
_Static_assert(_Alignof(struct A26_required_alignment) == 1, "record A26 wrong alignment");
_Static_assert(sizeof(struct A26_size) == 130, "record A26 wrong sizeof");
_Static_assert(_Alignof(struct A26_size) == 1, "record A26 wrong alignment");
#endif
_Static_assert(sizeof(A27) == 128, "record A27 wrong sizeof");
_Static_assert(_Alignof(A27) == 128, "record A27 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A27_alignment) == 256, "record A27 wrong sizeof");
_Static_assert(_Alignof(struct A27_alignment) == 128, "record A27 wrong alignment");
_Static_assert(sizeof(struct A27_packed) == 128, "record A27 wrong sizeof");
_Static_assert(_Alignof(struct A27_packed) == 1, "record A27 wrong alignment");
_Static_assert(sizeof(struct A27_required_alignment) == 129, "record A27 wrong sizeof");
_Static_assert(_Alignof(struct A27_required_alignment) == 1, "record A27 wrong alignment");
_Static_assert(sizeof(struct A27_size) == 130, "record A27 wrong sizeof");
_Static_assert(_Alignof(struct A27_size) == 1, "record A27 wrong alignment");
#endif
_Static_assert(sizeof(A28) == 128, "record A28 wrong sizeof");
_Static_assert(_Alignof(A28) == 128, "record A28 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A28_alignment) == 256, "record A28 wrong sizeof");
_Static_assert(_Alignof(struct A28_alignment) == 128, "record A28 wrong alignment");
_Static_assert(sizeof(struct A28_packed) == 128, "record A28 wrong sizeof");
_Static_assert(_Alignof(struct A28_packed) == 1, "record A28 wrong alignment");
_Static_assert(sizeof(struct A28_required_alignment) == 129, "record A28 wrong sizeof");
_Static_assert(_Alignof(struct A28_required_alignment) == 1, "record A28 wrong alignment");
_Static_assert(sizeof(struct A28_size) == 130, "record A28 wrong sizeof");
_Static_assert(_Alignof(struct A28_size) == 1, "record A28 wrong alignment");
#endif
_Static_assert(sizeof(A29) == 128, "record A29 wrong sizeof");
_Static_assert(_Alignof(A29) == 128, "record A29 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A29_alignment) == 256, "record A29 wrong sizeof");
_Static_assert(_Alignof(struct A29_alignment) == 128, "record A29 wrong alignment");
_Static_assert(sizeof(struct A29_packed) == 128, "record A29 wrong sizeof");
_Static_assert(_Alignof(struct A29_packed) == 1, "record A29 wrong alignment");
_Static_assert(sizeof(struct A29_required_alignment) == 129, "record A29 wrong sizeof");
_Static_assert(_Alignof(struct A29_required_alignment) == 1, "record A29 wrong alignment");
_Static_assert(sizeof(struct A29_size) == 130, "record A29 wrong sizeof");
_Static_assert(_Alignof(struct A29_size) == 1, "record A29 wrong alignment");
#endif
_Static_assert(sizeof(A30) == 128, "record A30 wrong sizeof");
_Static_assert(_Alignof(A30) == 128, "record A30 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A30_alignment) == 256, "record A30 wrong sizeof");
_Static_assert(_Alignof(struct A30_alignment) == 128, "record A30 wrong alignment");
_Static_assert(sizeof(struct A30_packed) == 128, "record A30 wrong sizeof");
_Static_assert(_Alignof(struct A30_packed) == 1, "record A30 wrong alignment");
_Static_assert(sizeof(struct A30_required_alignment) == 129, "record A30 wrong sizeof");
_Static_assert(_Alignof(struct A30_required_alignment) == 1, "record A30 wrong alignment");
_Static_assert(sizeof(struct A30_size) == 130, "record A30 wrong sizeof");
_Static_assert(_Alignof(struct A30_size) == 1, "record A30 wrong alignment");
#endif
_Static_assert(sizeof(A31) == 128, "record A31 wrong sizeof");
_Static_assert(_Alignof(A31) == 128, "record A31 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A31_alignment) == 256, "record A31 wrong sizeof");
_Static_assert(_Alignof(struct A31_alignment) == 128, "record A31 wrong alignment");
_Static_assert(sizeof(struct A31_packed) == 128, "record A31 wrong sizeof");
_Static_assert(_Alignof(struct A31_packed) == 1, "record A31 wrong alignment");
_Static_assert(sizeof(struct A31_required_alignment) == 129, "record A31 wrong sizeof");
_Static_assert(_Alignof(struct A31_required_alignment) == 1, "record A31 wrong alignment");
_Static_assert(sizeof(struct A31_size) == 130, "record A31 wrong sizeof");
_Static_assert(_Alignof(struct A31_size) == 1, "record A31 wrong alignment");
#endif
_Static_assert(sizeof(A32) == 128, "record A32 wrong sizeof");
_Static_assert(_Alignof(A32) == 128, "record A32 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A32_alignment) == 256, "record A32 wrong sizeof");
_Static_assert(_Alignof(struct A32_alignment) == 128, "record A32 wrong alignment");
_Static_assert(sizeof(struct A32_packed) == 128, "record A32 wrong sizeof");
_Static_assert(_Alignof(struct A32_packed) == 1, "record A32 wrong alignment");
_Static_assert(sizeof(struct A32_required_alignment) == 129, "record A32 wrong sizeof");
_Static_assert(_Alignof(struct A32_required_alignment) == 1, "record A32 wrong alignment");
_Static_assert(sizeof(struct A32_size) == 130, "record A32 wrong sizeof");
_Static_assert(_Alignof(struct A32_size) == 1, "record A32 wrong alignment");
#endif
_Static_assert(sizeof(A33) == 128, "record A33 wrong sizeof");
_Static_assert(_Alignof(A33) == 128, "record A33 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A33_alignment) == 256, "record A33 wrong sizeof");
_Static_assert(_Alignof(struct A33_alignment) == 128, "record A33 wrong alignment");
_Static_assert(sizeof(struct A33_packed) == 128, "record A33 wrong sizeof");
_Static_assert(_Alignof(struct A33_packed) == 1, "record A33 wrong alignment");
_Static_assert(sizeof(struct A33_required_alignment) == 129, "record A33 wrong sizeof");
_Static_assert(_Alignof(struct A33_required_alignment) == 1, "record A33 wrong alignment");
_Static_assert(sizeof(struct A33_size) == 130, "record A33 wrong sizeof");
_Static_assert(_Alignof(struct A33_size) == 1, "record A33 wrong alignment");
#endif
_Static_assert(sizeof(A34) == 128, "record A34 wrong sizeof");
_Static_assert(_Alignof(A34) == 128, "record A34 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A34_alignment) == 256, "record A34 wrong sizeof");
_Static_assert(_Alignof(struct A34_alignment) == 128, "record A34 wrong alignment");
_Static_assert(sizeof(struct A34_packed) == 128, "record A34 wrong sizeof");
_Static_assert(_Alignof(struct A34_packed) == 1, "record A34 wrong alignment");
_Static_assert(sizeof(struct A34_required_alignment) == 129, "record A34 wrong sizeof");
_Static_assert(_Alignof(struct A34_required_alignment) == 1, "record A34 wrong alignment");
_Static_assert(sizeof(struct A34_size) == 130, "record A34 wrong sizeof");
_Static_assert(_Alignof(struct A34_size) == 1, "record A34 wrong alignment");
#endif
_Static_assert(sizeof(A35) == 128, "record A35 wrong sizeof");
_Static_assert(_Alignof(A35) == 128, "record A35 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A35_alignment) == 256, "record A35 wrong sizeof");
_Static_assert(_Alignof(struct A35_alignment) == 128, "record A35 wrong alignment");
_Static_assert(sizeof(struct A35_packed) == 128, "record A35 wrong sizeof");
_Static_assert(_Alignof(struct A35_packed) == 1, "record A35 wrong alignment");
_Static_assert(sizeof(struct A35_required_alignment) == 129, "record A35 wrong sizeof");
_Static_assert(_Alignof(struct A35_required_alignment) == 1, "record A35 wrong alignment");
_Static_assert(sizeof(struct A35_size) == 130, "record A35 wrong sizeof");
_Static_assert(_Alignof(struct A35_size) == 1, "record A35 wrong alignment");
#endif
_Static_assert(sizeof(A36) == 128, "record A36 wrong sizeof");
_Static_assert(_Alignof(A36) == 128, "record A36 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A36_alignment) == 256, "record A36 wrong sizeof");
_Static_assert(_Alignof(struct A36_alignment) == 128, "record A36 wrong alignment");
_Static_assert(sizeof(struct A36_packed) == 128, "record A36 wrong sizeof");
_Static_assert(_Alignof(struct A36_packed) == 1, "record A36 wrong alignment");
_Static_assert(sizeof(struct A36_required_alignment) == 129, "record A36 wrong sizeof");
_Static_assert(_Alignof(struct A36_required_alignment) == 1, "record A36 wrong alignment");
_Static_assert(sizeof(struct A36_size) == 130, "record A36 wrong sizeof");
_Static_assert(_Alignof(struct A36_size) == 1, "record A36 wrong alignment");
#endif
_Static_assert(sizeof(A37) == 128, "record A37 wrong sizeof");
_Static_assert(_Alignof(A37) == 128, "record A37 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A37_alignment) == 256, "record A37 wrong sizeof");
_Static_assert(_Alignof(struct A37_alignment) == 128, "record A37 wrong alignment");
_Static_assert(sizeof(struct A37_packed) == 128, "record A37 wrong sizeof");
_Static_assert(_Alignof(struct A37_packed) == 1, "record A37 wrong alignment");
_Static_assert(sizeof(struct A37_required_alignment) == 129, "record A37 wrong sizeof");
_Static_assert(_Alignof(struct A37_required_alignment) == 1, "record A37 wrong alignment");
_Static_assert(sizeof(struct A37_size) == 130, "record A37 wrong sizeof");
_Static_assert(_Alignof(struct A37_size) == 1, "record A37 wrong alignment");
#endif
_Static_assert(sizeof(A38) == 128, "record A38 wrong sizeof");
_Static_assert(_Alignof(A38) == 128, "record A38 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A38_alignment) == 256, "record A38 wrong sizeof");
_Static_assert(_Alignof(struct A38_alignment) == 128, "record A38 wrong alignment");
_Static_assert(sizeof(struct A38_packed) == 128, "record A38 wrong sizeof");
_Static_assert(_Alignof(struct A38_packed) == 1, "record A38 wrong alignment");
_Static_assert(sizeof(struct A38_required_alignment) == 129, "record A38 wrong sizeof");
_Static_assert(_Alignof(struct A38_required_alignment) == 1, "record A38 wrong alignment");
_Static_assert(sizeof(struct A38_size) == 130, "record A38 wrong sizeof");
_Static_assert(_Alignof(struct A38_size) == 1, "record A38 wrong alignment");
#endif
_Static_assert(sizeof(A39) == 128, "record A39 wrong sizeof");
_Static_assert(_Alignof(A39) == 128, "record A39 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A39_alignment) == 256, "record A39 wrong sizeof");
_Static_assert(_Alignof(struct A39_alignment) == 128, "record A39 wrong alignment");
_Static_assert(sizeof(struct A39_packed) == 128, "record A39 wrong sizeof");
_Static_assert(_Alignof(struct A39_packed) == 1, "record A39 wrong alignment");
_Static_assert(sizeof(struct A39_required_alignment) == 129, "record A39 wrong sizeof");
_Static_assert(_Alignof(struct A39_required_alignment) == 1, "record A39 wrong alignment");
_Static_assert(sizeof(struct A39_size) == 130, "record A39 wrong sizeof");
_Static_assert(_Alignof(struct A39_size) == 1, "record A39 wrong alignment");
#endif
_Static_assert(sizeof(B00) == 128, "record B00 wrong sizeof");
_Static_assert(_Alignof(B00) == 128, "record B00 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B00_alignment) == 256, "record B00 wrong sizeof");
_Static_assert(_Alignof(struct B00_alignment) == 128, "record B00 wrong alignment");
_Static_assert(sizeof(struct B00_packed) == 128, "record B00 wrong sizeof");
_Static_assert(_Alignof(struct B00_packed) == 1, "record B00 wrong alignment");
_Static_assert(sizeof(struct B00_required_alignment) == 129, "record B00 wrong sizeof");
_Static_assert(_Alignof(struct B00_required_alignment) == 1, "record B00 wrong alignment");
_Static_assert(sizeof(struct B00_size) == 130, "record B00 wrong sizeof");
_Static_assert(_Alignof(struct B00_size) == 1, "record B00 wrong alignment");
#endif
_Static_assert(sizeof(B01) == 8, "record B01 wrong sizeof");
_Static_assert(_Alignof(B01) == 1, "record B01 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B01_alignment) == 9, "record B01 wrong sizeof");
_Static_assert(_Alignof(struct B01_alignment) == 1, "record B01 wrong alignment");
_Static_assert(sizeof(struct B01_packed) == 8, "record B01 wrong sizeof");
_Static_assert(_Alignof(struct B01_packed) == 1, "record B01 wrong alignment");
_Static_assert(sizeof(struct B01_required_alignment) == 9, "record B01 wrong sizeof");
_Static_assert(_Alignof(struct B01_required_alignment) == 1, "record B01 wrong alignment");
_Static_assert(sizeof(struct B01_size) == 10, "record B01 wrong sizeof");
_Static_assert(_Alignof(struct B01_size) == 1, "record B01 wrong alignment");
#endif
_Static_assert(sizeof(B02) == 8, "record B02 wrong sizeof");
_Static_assert(_Alignof(B02) == 2, "record B02 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B02_alignment) == 10, "record B02 wrong sizeof");
_Static_assert(_Alignof(struct B02_alignment) == 2, "record B02 wrong alignment");
_Static_assert(sizeof(struct B02_packed) == 8, "record B02 wrong sizeof");
_Static_assert(_Alignof(struct B02_packed) == 1, "record B02 wrong alignment");
_Static_assert(sizeof(struct B02_required_alignment) == 9, "record B02 wrong sizeof");
_Static_assert(_Alignof(struct B02_required_alignment) == 1, "record B02 wrong alignment");
_Static_assert(sizeof(struct B02_size) == 10, "record B02 wrong sizeof");
_Static_assert(_Alignof(struct B02_size) == 1, "record B02 wrong alignment");
#endif
_Static_assert(sizeof(B03) == 128, "record B03 wrong sizeof");
_Static_assert(_Alignof(B03) == 128, "record B03 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B03_alignment) == 256, "record B03 wrong sizeof");
_Static_assert(_Alignof(struct B03_alignment) == 128, "record B03 wrong alignment");
_Static_assert(sizeof(struct B03_packed) == 128, "record B03 wrong sizeof");
_Static_assert(_Alignof(struct B03_packed) == 1, "record B03 wrong alignment");
_Static_assert(sizeof(struct B03_required_alignment) == 129, "record B03 wrong sizeof");
_Static_assert(_Alignof(struct B03_required_alignment) == 1, "record B03 wrong alignment");
_Static_assert(sizeof(struct B03_size) == 130, "record B03 wrong sizeof");
_Static_assert(_Alignof(struct B03_size) == 1, "record B03 wrong alignment");
#endif
_Static_assert(sizeof(B04) == 8, "record B04 wrong sizeof");
_Static_assert(_Alignof(B04) == 4, "record B04 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B04_alignment) == 12, "record B04 wrong sizeof");
_Static_assert(_Alignof(struct B04_alignment) == 4, "record B04 wrong alignment");
_Static_assert(sizeof(struct B04_packed) == 8, "record B04 wrong sizeof");
_Static_assert(_Alignof(struct B04_packed) == 1, "record B04 wrong alignment");
_Static_assert(sizeof(struct B04_required_alignment) == 9, "record B04 wrong sizeof");
_Static_assert(_Alignof(struct B04_required_alignment) == 1, "record B04 wrong alignment");
_Static_assert(sizeof(struct B04_size) == 10, "record B04 wrong sizeof");
_Static_assert(_Alignof(struct B04_size) == 1, "record B04 wrong alignment");
#endif
_Static_assert(sizeof(B05) == 128, "record B05 wrong sizeof");
_Static_assert(_Alignof(B05) == 128, "record B05 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B05_alignment) == 256, "record B05 wrong sizeof");
_Static_assert(_Alignof(struct B05_alignment) == 128, "record B05 wrong alignment");
_Static_assert(sizeof(struct B05_packed) == 128, "record B05 wrong sizeof");
_Static_assert(_Alignof(struct B05_packed) == 1, "record B05 wrong alignment");
_Static_assert(sizeof(struct B05_required_alignment) == 129, "record B05 wrong sizeof");
_Static_assert(_Alignof(struct B05_required_alignment) == 1, "record B05 wrong alignment");
_Static_assert(sizeof(struct B05_size) == 130, "record B05 wrong sizeof");
_Static_assert(_Alignof(struct B05_size) == 1, "record B05 wrong alignment");
#endif
_Static_assert(sizeof(B06) == 128, "record B06 wrong sizeof");
_Static_assert(_Alignof(B06) == 128, "record B06 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B06_alignment) == 256, "record B06 wrong sizeof");
_Static_assert(_Alignof(struct B06_alignment) == 128, "record B06 wrong alignment");
_Static_assert(sizeof(struct B06_packed) == 128, "record B06 wrong sizeof");
_Static_assert(_Alignof(struct B06_packed) == 1, "record B06 wrong alignment");
_Static_assert(sizeof(struct B06_required_alignment) == 129, "record B06 wrong sizeof");
_Static_assert(_Alignof(struct B06_required_alignment) == 1, "record B06 wrong alignment");
_Static_assert(sizeof(struct B06_size) == 130, "record B06 wrong sizeof");
_Static_assert(_Alignof(struct B06_size) == 1, "record B06 wrong alignment");
#endif
_Static_assert(sizeof(B07) == 128, "record B07 wrong sizeof");
_Static_assert(_Alignof(B07) == 128, "record B07 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B07_alignment) == 256, "record B07 wrong sizeof");
_Static_assert(_Alignof(struct B07_alignment) == 128, "record B07 wrong alignment");
_Static_assert(sizeof(struct B07_packed) == 128, "record B07 wrong sizeof");
_Static_assert(_Alignof(struct B07_packed) == 1, "record B07 wrong alignment");
_Static_assert(sizeof(struct B07_required_alignment) == 129, "record B07 wrong sizeof");
_Static_assert(_Alignof(struct B07_required_alignment) == 1, "record B07 wrong alignment");
_Static_assert(sizeof(struct B07_size) == 130, "record B07 wrong sizeof");
_Static_assert(_Alignof(struct B07_size) == 1, "record B07 wrong alignment");
#endif
_Static_assert(sizeof(B08) == 8, "record B08 wrong sizeof");
_Static_assert(_Alignof(B08) == 8, "record B08 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B08_alignment) == 16, "record B08 wrong sizeof");
_Static_assert(_Alignof(struct B08_alignment) == 8, "record B08 wrong alignment");
_Static_assert(sizeof(struct B08_packed) == 8, "record B08 wrong sizeof");
_Static_assert(_Alignof(struct B08_packed) == 1, "record B08 wrong alignment");
_Static_assert(sizeof(struct B08_required_alignment) == 9, "record B08 wrong sizeof");
_Static_assert(_Alignof(struct B08_required_alignment) == 1, "record B08 wrong alignment");
_Static_assert(sizeof(struct B08_size) == 10, "record B08 wrong sizeof");
_Static_assert(_Alignof(struct B08_size) == 1, "record B08 wrong alignment");
#endif
_Static_assert(sizeof(B09) == 128, "record B09 wrong sizeof");
_Static_assert(_Alignof(B09) == 128, "record B09 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B09_alignment) == 256, "record B09 wrong sizeof");
_Static_assert(_Alignof(struct B09_alignment) == 128, "record B09 wrong alignment");
_Static_assert(sizeof(struct B09_packed) == 128, "record B09 wrong sizeof");
_Static_assert(_Alignof(struct B09_packed) == 1, "record B09 wrong alignment");
_Static_assert(sizeof(struct B09_required_alignment) == 129, "record B09 wrong sizeof");
_Static_assert(_Alignof(struct B09_required_alignment) == 1, "record B09 wrong alignment");
_Static_assert(sizeof(struct B09_size) == 130, "record B09 wrong sizeof");
_Static_assert(_Alignof(struct B09_size) == 1, "record B09 wrong alignment");
#endif
_Static_assert(sizeof(B10) == 128, "record B10 wrong sizeof");
_Static_assert(_Alignof(B10) == 128, "record B10 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B10_alignment) == 256, "record B10 wrong sizeof");
_Static_assert(_Alignof(struct B10_alignment) == 128, "record B10 wrong alignment");
_Static_assert(sizeof(struct B10_packed) == 128, "record B10 wrong sizeof");
_Static_assert(_Alignof(struct B10_packed) == 1, "record B10 wrong alignment");
_Static_assert(sizeof(struct B10_required_alignment) == 129, "record B10 wrong sizeof");
_Static_assert(_Alignof(struct B10_required_alignment) == 1, "record B10 wrong alignment");
_Static_assert(sizeof(struct B10_size) == 130, "record B10 wrong sizeof");
_Static_assert(_Alignof(struct B10_size) == 1, "record B10 wrong alignment");
#endif
_Static_assert(sizeof(B11) == 128, "record B11 wrong sizeof");
_Static_assert(_Alignof(B11) == 128, "record B11 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B11_alignment) == 256, "record B11 wrong sizeof");
_Static_assert(_Alignof(struct B11_alignment) == 128, "record B11 wrong alignment");
_Static_assert(sizeof(struct B11_packed) == 128, "record B11 wrong sizeof");
_Static_assert(_Alignof(struct B11_packed) == 1, "record B11 wrong alignment");
_Static_assert(sizeof(struct B11_required_alignment) == 129, "record B11 wrong sizeof");
_Static_assert(_Alignof(struct B11_required_alignment) == 1, "record B11 wrong alignment");
_Static_assert(sizeof(struct B11_size) == 130, "record B11 wrong sizeof");
_Static_assert(_Alignof(struct B11_size) == 1, "record B11 wrong alignment");
#endif
_Static_assert(sizeof(B12) == 128, "record B12 wrong sizeof");
_Static_assert(_Alignof(B12) == 128, "record B12 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B12_alignment) == 256, "record B12 wrong sizeof");
_Static_assert(_Alignof(struct B12_alignment) == 128, "record B12 wrong alignment");
_Static_assert(sizeof(struct B12_packed) == 128, "record B12 wrong sizeof");
_Static_assert(_Alignof(struct B12_packed) == 1, "record B12 wrong alignment");
_Static_assert(sizeof(struct B12_required_alignment) == 129, "record B12 wrong sizeof");
_Static_assert(_Alignof(struct B12_required_alignment) == 1, "record B12 wrong alignment");
_Static_assert(sizeof(struct B12_size) == 130, "record B12 wrong sizeof");
_Static_assert(_Alignof(struct B12_size) == 1, "record B12 wrong alignment");
#endif
_Static_assert(sizeof(B13) == 128, "record B13 wrong sizeof");
_Static_assert(_Alignof(B13) == 128, "record B13 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B13_alignment) == 256, "record B13 wrong sizeof");
_Static_assert(_Alignof(struct B13_alignment) == 128, "record B13 wrong alignment");
_Static_assert(sizeof(struct B13_packed) == 128, "record B13 wrong sizeof");
_Static_assert(_Alignof(struct B13_packed) == 1, "record B13 wrong alignment");
_Static_assert(sizeof(struct B13_required_alignment) == 129, "record B13 wrong sizeof");
_Static_assert(_Alignof(struct B13_required_alignment) == 1, "record B13 wrong alignment");
_Static_assert(sizeof(struct B13_size) == 130, "record B13 wrong sizeof");
_Static_assert(_Alignof(struct B13_size) == 1, "record B13 wrong alignment");
#endif
_Static_assert(sizeof(B14) == 128, "record B14 wrong sizeof");
_Static_assert(_Alignof(B14) == 128, "record B14 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B14_alignment) == 256, "record B14 wrong sizeof");
_Static_assert(_Alignof(struct B14_alignment) == 128, "record B14 wrong alignment");
_Static_assert(sizeof(struct B14_packed) == 128, "record B14 wrong sizeof");
_Static_assert(_Alignof(struct B14_packed) == 1, "record B14 wrong alignment");
_Static_assert(sizeof(struct B14_required_alignment) == 129, "record B14 wrong sizeof");
_Static_assert(_Alignof(struct B14_required_alignment) == 1, "record B14 wrong alignment");
_Static_assert(sizeof(struct B14_size) == 130, "record B14 wrong sizeof");
_Static_assert(_Alignof(struct B14_size) == 1, "record B14 wrong alignment");
#endif
_Static_assert(sizeof(B15) == 128, "record B15 wrong sizeof");
_Static_assert(_Alignof(B15) == 128, "record B15 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B15_alignment) == 256, "record B15 wrong sizeof");
_Static_assert(_Alignof(struct B15_alignment) == 128, "record B15 wrong alignment");
_Static_assert(sizeof(struct B15_packed) == 128, "record B15 wrong sizeof");
_Static_assert(_Alignof(struct B15_packed) == 1, "record B15 wrong alignment");
_Static_assert(sizeof(struct B15_required_alignment) == 129, "record B15 wrong sizeof");
_Static_assert(_Alignof(struct B15_required_alignment) == 1, "record B15 wrong alignment");
_Static_assert(sizeof(struct B15_size) == 130, "record B15 wrong sizeof");
_Static_assert(_Alignof(struct B15_size) == 1, "record B15 wrong alignment");
#endif
_Static_assert(sizeof(B16) == 16, "record B16 wrong sizeof");
_Static_assert(_Alignof(B16) == 16, "record B16 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B16_alignment) == 32, "record B16 wrong sizeof");
_Static_assert(_Alignof(struct B16_alignment) == 16, "record B16 wrong alignment");
_Static_assert(sizeof(struct B16_packed) == 16, "record B16 wrong sizeof");
_Static_assert(_Alignof(struct B16_packed) == 1, "record B16 wrong alignment");
_Static_assert(sizeof(struct B16_required_alignment) == 17, "record B16 wrong sizeof");
_Static_assert(_Alignof(struct B16_required_alignment) == 1, "record B16 wrong alignment");
_Static_assert(sizeof(struct B16_size) == 18, "record B16 wrong sizeof");
_Static_assert(_Alignof(struct B16_size) == 1, "record B16 wrong alignment");
#endif
_Static_assert(sizeof(B17) == 128, "record B17 wrong sizeof");
_Static_assert(_Alignof(B17) == 128, "record B17 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B17_alignment) == 256, "record B17 wrong sizeof");
_Static_assert(_Alignof(struct B17_alignment) == 128, "record B17 wrong alignment");
_Static_assert(sizeof(struct B17_packed) == 128, "record B17 wrong sizeof");
_Static_assert(_Alignof(struct B17_packed) == 1, "record B17 wrong alignment");
_Static_assert(sizeof(struct B17_required_alignment) == 129, "record B17 wrong sizeof");
_Static_assert(_Alignof(struct B17_required_alignment) == 1, "record B17 wrong alignment");
_Static_assert(sizeof(struct B17_size) == 130, "record B17 wrong sizeof");
_Static_assert(_Alignof(struct B17_size) == 1, "record B17 wrong alignment");
#endif
_Static_assert(sizeof(B18) == 128, "record B18 wrong sizeof");
_Static_assert(_Alignof(B18) == 128, "record B18 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B18_alignment) == 256, "record B18 wrong sizeof");
_Static_assert(_Alignof(struct B18_alignment) == 128, "record B18 wrong alignment");
_Static_assert(sizeof(struct B18_packed) == 128, "record B18 wrong sizeof");
_Static_assert(_Alignof(struct B18_packed) == 1, "record B18 wrong alignment");
_Static_assert(sizeof(struct B18_required_alignment) == 129, "record B18 wrong sizeof");
_Static_assert(_Alignof(struct B18_required_alignment) == 1, "record B18 wrong alignment");
_Static_assert(sizeof(struct B18_size) == 130, "record B18 wrong sizeof");
_Static_assert(_Alignof(struct B18_size) == 1, "record B18 wrong alignment");
#endif
_Static_assert(sizeof(B19) == 128, "record B19 wrong sizeof");
_Static_assert(_Alignof(B19) == 128, "record B19 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B19_alignment) == 256, "record B19 wrong sizeof");
_Static_assert(_Alignof(struct B19_alignment) == 128, "record B19 wrong alignment");
_Static_assert(sizeof(struct B19_packed) == 128, "record B19 wrong sizeof");
_Static_assert(_Alignof(struct B19_packed) == 1, "record B19 wrong alignment");
_Static_assert(sizeof(struct B19_required_alignment) == 129, "record B19 wrong sizeof");
_Static_assert(_Alignof(struct B19_required_alignment) == 1, "record B19 wrong alignment");
_Static_assert(sizeof(struct B19_size) == 130, "record B19 wrong sizeof");
_Static_assert(_Alignof(struct B19_size) == 1, "record B19 wrong alignment");
#endif
_Static_assert(sizeof(B20) == 128, "record B20 wrong sizeof");
_Static_assert(_Alignof(B20) == 128, "record B20 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B20_alignment) == 256, "record B20 wrong sizeof");
_Static_assert(_Alignof(struct B20_alignment) == 128, "record B20 wrong alignment");
_Static_assert(sizeof(struct B20_packed) == 128, "record B20 wrong sizeof");
_Static_assert(_Alignof(struct B20_packed) == 1, "record B20 wrong alignment");
_Static_assert(sizeof(struct B20_required_alignment) == 129, "record B20 wrong sizeof");
_Static_assert(_Alignof(struct B20_required_alignment) == 1, "record B20 wrong alignment");
_Static_assert(sizeof(struct B20_size) == 130, "record B20 wrong sizeof");
_Static_assert(_Alignof(struct B20_size) == 1, "record B20 wrong alignment");
#endif
_Static_assert(sizeof(B21) == 128, "record B21 wrong sizeof");
_Static_assert(_Alignof(B21) == 128, "record B21 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B21_alignment) == 256, "record B21 wrong sizeof");
_Static_assert(_Alignof(struct B21_alignment) == 128, "record B21 wrong alignment");
_Static_assert(sizeof(struct B21_packed) == 128, "record B21 wrong sizeof");
_Static_assert(_Alignof(struct B21_packed) == 1, "record B21 wrong alignment");
_Static_assert(sizeof(struct B21_required_alignment) == 129, "record B21 wrong sizeof");
_Static_assert(_Alignof(struct B21_required_alignment) == 1, "record B21 wrong alignment");
_Static_assert(sizeof(struct B21_size) == 130, "record B21 wrong sizeof");
_Static_assert(_Alignof(struct B21_size) == 1, "record B21 wrong alignment");
#endif
_Static_assert(sizeof(B22) == 128, "record B22 wrong sizeof");
_Static_assert(_Alignof(B22) == 128, "record B22 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B22_alignment) == 256, "record B22 wrong sizeof");
_Static_assert(_Alignof(struct B22_alignment) == 128, "record B22 wrong alignment");
_Static_assert(sizeof(struct B22_packed) == 128, "record B22 wrong sizeof");
_Static_assert(_Alignof(struct B22_packed) == 1, "record B22 wrong alignment");
_Static_assert(sizeof(struct B22_required_alignment) == 129, "record B22 wrong sizeof");
_Static_assert(_Alignof(struct B22_required_alignment) == 1, "record B22 wrong alignment");
_Static_assert(sizeof(struct B22_size) == 130, "record B22 wrong sizeof");
_Static_assert(_Alignof(struct B22_size) == 1, "record B22 wrong alignment");
#endif
_Static_assert(sizeof(B23) == 128, "record B23 wrong sizeof");
_Static_assert(_Alignof(B23) == 128, "record B23 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B23_alignment) == 256, "record B23 wrong sizeof");
_Static_assert(_Alignof(struct B23_alignment) == 128, "record B23 wrong alignment");
_Static_assert(sizeof(struct B23_packed) == 128, "record B23 wrong sizeof");
_Static_assert(_Alignof(struct B23_packed) == 1, "record B23 wrong alignment");
_Static_assert(sizeof(struct B23_required_alignment) == 129, "record B23 wrong sizeof");
_Static_assert(_Alignof(struct B23_required_alignment) == 1, "record B23 wrong alignment");
_Static_assert(sizeof(struct B23_size) == 130, "record B23 wrong sizeof");
_Static_assert(_Alignof(struct B23_size) == 1, "record B23 wrong alignment");
#endif
_Static_assert(sizeof(B24) == 128, "record B24 wrong sizeof");
_Static_assert(_Alignof(B24) == 128, "record B24 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B24_alignment) == 256, "record B24 wrong sizeof");
_Static_assert(_Alignof(struct B24_alignment) == 128, "record B24 wrong alignment");
_Static_assert(sizeof(struct B24_packed) == 128, "record B24 wrong sizeof");
_Static_assert(_Alignof(struct B24_packed) == 1, "record B24 wrong alignment");
_Static_assert(sizeof(struct B24_required_alignment) == 129, "record B24 wrong sizeof");
_Static_assert(_Alignof(struct B24_required_alignment) == 1, "record B24 wrong alignment");
_Static_assert(sizeof(struct B24_size) == 130, "record B24 wrong sizeof");
_Static_assert(_Alignof(struct B24_size) == 1, "record B24 wrong alignment");
#endif
_Static_assert(sizeof(B25) == 128, "record B25 wrong sizeof");
_Static_assert(_Alignof(B25) == 128, "record B25 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B25_alignment) == 256, "record B25 wrong sizeof");
_Static_assert(_Alignof(struct B25_alignment) == 128, "record B25 wrong alignment");
_Static_assert(sizeof(struct B25_packed) == 128, "record B25 wrong sizeof");
_Static_assert(_Alignof(struct B25_packed) == 1, "record B25 wrong alignment");
_Static_assert(sizeof(struct B25_required_alignment) == 129, "record B25 wrong sizeof");
_Static_assert(_Alignof(struct B25_required_alignment) == 1, "record B25 wrong alignment");
_Static_assert(sizeof(struct B25_size) == 130, "record B25 wrong sizeof");
_Static_assert(_Alignof(struct B25_size) == 1, "record B25 wrong alignment");
#endif
_Static_assert(sizeof(B26) == 128, "record B26 wrong sizeof");
_Static_assert(_Alignof(B26) == 128, "record B26 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B26_alignment) == 256, "record B26 wrong sizeof");
_Static_assert(_Alignof(struct B26_alignment) == 128, "record B26 wrong alignment");
_Static_assert(sizeof(struct B26_packed) == 128, "record B26 wrong sizeof");
_Static_assert(_Alignof(struct B26_packed) == 1, "record B26 wrong alignment");
_Static_assert(sizeof(struct B26_required_alignment) == 129, "record B26 wrong sizeof");
_Static_assert(_Alignof(struct B26_required_alignment) == 1, "record B26 wrong alignment");
_Static_assert(sizeof(struct B26_size) == 130, "record B26 wrong sizeof");
_Static_assert(_Alignof(struct B26_size) == 1, "record B26 wrong alignment");
#endif
_Static_assert(sizeof(B27) == 128, "record B27 wrong sizeof");
_Static_assert(_Alignof(B27) == 128, "record B27 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B27_alignment) == 256, "record B27 wrong sizeof");
_Static_assert(_Alignof(struct B27_alignment) == 128, "record B27 wrong alignment");
_Static_assert(sizeof(struct B27_packed) == 128, "record B27 wrong sizeof");
_Static_assert(_Alignof(struct B27_packed) == 1, "record B27 wrong alignment");
_Static_assert(sizeof(struct B27_required_alignment) == 129, "record B27 wrong sizeof");
_Static_assert(_Alignof(struct B27_required_alignment) == 1, "record B27 wrong alignment");
_Static_assert(sizeof(struct B27_size) == 130, "record B27 wrong sizeof");
_Static_assert(_Alignof(struct B27_size) == 1, "record B27 wrong alignment");
#endif
_Static_assert(sizeof(B28) == 128, "record B28 wrong sizeof");
_Static_assert(_Alignof(B28) == 128, "record B28 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B28_alignment) == 256, "record B28 wrong sizeof");
_Static_assert(_Alignof(struct B28_alignment) == 128, "record B28 wrong alignment");
_Static_assert(sizeof(struct B28_packed) == 128, "record B28 wrong sizeof");
_Static_assert(_Alignof(struct B28_packed) == 1, "record B28 wrong alignment");
_Static_assert(sizeof(struct B28_required_alignment) == 129, "record B28 wrong sizeof");
_Static_assert(_Alignof(struct B28_required_alignment) == 1, "record B28 wrong alignment");
_Static_assert(sizeof(struct B28_size) == 130, "record B28 wrong sizeof");
_Static_assert(_Alignof(struct B28_size) == 1, "record B28 wrong alignment");
#endif
_Static_assert(sizeof(B29) == 128, "record B29 wrong sizeof");
_Static_assert(_Alignof(B29) == 128, "record B29 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B29_alignment) == 256, "record B29 wrong sizeof");
_Static_assert(_Alignof(struct B29_alignment) == 128, "record B29 wrong alignment");
_Static_assert(sizeof(struct B29_packed) == 128, "record B29 wrong sizeof");
_Static_assert(_Alignof(struct B29_packed) == 1, "record B29 wrong alignment");
_Static_assert(sizeof(struct B29_required_alignment) == 129, "record B29 wrong sizeof");
_Static_assert(_Alignof(struct B29_required_alignment) == 1, "record B29 wrong alignment");
_Static_assert(sizeof(struct B29_size) == 130, "record B29 wrong sizeof");
_Static_assert(_Alignof(struct B29_size) == 1, "record B29 wrong alignment");
#endif
_Static_assert(sizeof(B30) == 128, "record B30 wrong sizeof");
_Static_assert(_Alignof(B30) == 128, "record B30 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B30_alignment) == 256, "record B30 wrong sizeof");
_Static_assert(_Alignof(struct B30_alignment) == 128, "record B30 wrong alignment");
_Static_assert(sizeof(struct B30_packed) == 128, "record B30 wrong sizeof");
_Static_assert(_Alignof(struct B30_packed) == 1, "record B30 wrong alignment");
_Static_assert(sizeof(struct B30_required_alignment) == 129, "record B30 wrong sizeof");
_Static_assert(_Alignof(struct B30_required_alignment) == 1, "record B30 wrong alignment");
_Static_assert(sizeof(struct B30_size) == 130, "record B30 wrong sizeof");
_Static_assert(_Alignof(struct B30_size) == 1, "record B30 wrong alignment");
#endif
_Static_assert(sizeof(B31) == 128, "record B31 wrong sizeof");
_Static_assert(_Alignof(B31) == 128, "record B31 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B31_alignment) == 256, "record B31 wrong sizeof");
_Static_assert(_Alignof(struct B31_alignment) == 128, "record B31 wrong alignment");
_Static_assert(sizeof(struct B31_packed) == 128, "record B31 wrong sizeof");
_Static_assert(_Alignof(struct B31_packed) == 1, "record B31 wrong alignment");
_Static_assert(sizeof(struct B31_required_alignment) == 129, "record B31 wrong sizeof");
_Static_assert(_Alignof(struct B31_required_alignment) == 1, "record B31 wrong alignment");
_Static_assert(sizeof(struct B31_size) == 130, "record B31 wrong sizeof");
_Static_assert(_Alignof(struct B31_size) == 1, "record B31 wrong alignment");
#endif
_Static_assert(sizeof(B32) == 128, "record B32 wrong sizeof");
_Static_assert(_Alignof(B32) == 128, "record B32 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B32_alignment) == 256, "record B32 wrong sizeof");
_Static_assert(_Alignof(struct B32_alignment) == 128, "record B32 wrong alignment");
_Static_assert(sizeof(struct B32_packed) == 128, "record B32 wrong sizeof");
_Static_assert(_Alignof(struct B32_packed) == 1, "record B32 wrong alignment");
_Static_assert(sizeof(struct B32_required_alignment) == 129, "record B32 wrong sizeof");
_Static_assert(_Alignof(struct B32_required_alignment) == 1, "record B32 wrong alignment");
_Static_assert(sizeof(struct B32_size) == 130, "record B32 wrong sizeof");
_Static_assert(_Alignof(struct B32_size) == 1, "record B32 wrong alignment");
#endif
_Static_assert(sizeof(B33) == 128, "record B33 wrong sizeof");
_Static_assert(_Alignof(B33) == 128, "record B33 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B33_alignment) == 256, "record B33 wrong sizeof");
_Static_assert(_Alignof(struct B33_alignment) == 128, "record B33 wrong alignment");
_Static_assert(sizeof(struct B33_packed) == 128, "record B33 wrong sizeof");
_Static_assert(_Alignof(struct B33_packed) == 1, "record B33 wrong alignment");
_Static_assert(sizeof(struct B33_required_alignment) == 129, "record B33 wrong sizeof");
_Static_assert(_Alignof(struct B33_required_alignment) == 1, "record B33 wrong alignment");
_Static_assert(sizeof(struct B33_size) == 130, "record B33 wrong sizeof");
_Static_assert(_Alignof(struct B33_size) == 1, "record B33 wrong alignment");
#endif
_Static_assert(sizeof(B34) == 128, "record B34 wrong sizeof");
_Static_assert(_Alignof(B34) == 128, "record B34 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B34_alignment) == 256, "record B34 wrong sizeof");
_Static_assert(_Alignof(struct B34_alignment) == 128, "record B34 wrong alignment");
_Static_assert(sizeof(struct B34_packed) == 128, "record B34 wrong sizeof");
_Static_assert(_Alignof(struct B34_packed) == 1, "record B34 wrong alignment");
_Static_assert(sizeof(struct B34_required_alignment) == 129, "record B34 wrong sizeof");
_Static_assert(_Alignof(struct B34_required_alignment) == 1, "record B34 wrong alignment");
_Static_assert(sizeof(struct B34_size) == 130, "record B34 wrong sizeof");
_Static_assert(_Alignof(struct B34_size) == 1, "record B34 wrong alignment");
#endif
_Static_assert(sizeof(B35) == 128, "record B35 wrong sizeof");
_Static_assert(_Alignof(B35) == 128, "record B35 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B35_alignment) == 256, "record B35 wrong sizeof");
_Static_assert(_Alignof(struct B35_alignment) == 128, "record B35 wrong alignment");
_Static_assert(sizeof(struct B35_packed) == 128, "record B35 wrong sizeof");
_Static_assert(_Alignof(struct B35_packed) == 1, "record B35 wrong alignment");
_Static_assert(sizeof(struct B35_required_alignment) == 129, "record B35 wrong sizeof");
_Static_assert(_Alignof(struct B35_required_alignment) == 1, "record B35 wrong alignment");
_Static_assert(sizeof(struct B35_size) == 130, "record B35 wrong sizeof");
_Static_assert(_Alignof(struct B35_size) == 1, "record B35 wrong alignment");
#endif
_Static_assert(sizeof(B36) == 128, "record B36 wrong sizeof");
_Static_assert(_Alignof(B36) == 128, "record B36 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B36_alignment) == 256, "record B36 wrong sizeof");
_Static_assert(_Alignof(struct B36_alignment) == 128, "record B36 wrong alignment");
_Static_assert(sizeof(struct B36_packed) == 128, "record B36 wrong sizeof");
_Static_assert(_Alignof(struct B36_packed) == 1, "record B36 wrong alignment");
_Static_assert(sizeof(struct B36_required_alignment) == 129, "record B36 wrong sizeof");
_Static_assert(_Alignof(struct B36_required_alignment) == 1, "record B36 wrong alignment");
_Static_assert(sizeof(struct B36_size) == 130, "record B36 wrong sizeof");
_Static_assert(_Alignof(struct B36_size) == 1, "record B36 wrong alignment");
#endif
_Static_assert(sizeof(B37) == 128, "record B37 wrong sizeof");
_Static_assert(_Alignof(B37) == 128, "record B37 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B37_alignment) == 256, "record B37 wrong sizeof");
_Static_assert(_Alignof(struct B37_alignment) == 128, "record B37 wrong alignment");
_Static_assert(sizeof(struct B37_packed) == 128, "record B37 wrong sizeof");
_Static_assert(_Alignof(struct B37_packed) == 1, "record B37 wrong alignment");
_Static_assert(sizeof(struct B37_required_alignment) == 129, "record B37 wrong sizeof");
_Static_assert(_Alignof(struct B37_required_alignment) == 1, "record B37 wrong alignment");
_Static_assert(sizeof(struct B37_size) == 130, "record B37 wrong sizeof");
_Static_assert(_Alignof(struct B37_size) == 1, "record B37 wrong alignment");
#endif
_Static_assert(sizeof(B38) == 128, "record B38 wrong sizeof");
_Static_assert(_Alignof(B38) == 128, "record B38 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B38_alignment) == 256, "record B38 wrong sizeof");
_Static_assert(_Alignof(struct B38_alignment) == 128, "record B38 wrong alignment");
_Static_assert(sizeof(struct B38_packed) == 128, "record B38 wrong sizeof");
_Static_assert(_Alignof(struct B38_packed) == 1, "record B38 wrong alignment");
_Static_assert(sizeof(struct B38_required_alignment) == 129, "record B38 wrong sizeof");
_Static_assert(_Alignof(struct B38_required_alignment) == 1, "record B38 wrong alignment");
_Static_assert(sizeof(struct B38_size) == 130, "record B38 wrong sizeof");
_Static_assert(_Alignof(struct B38_size) == 1, "record B38 wrong alignment");
#endif
_Static_assert(sizeof(B39) == 128, "record B39 wrong sizeof");
_Static_assert(_Alignof(B39) == 128, "record B39 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B39_alignment) == 256, "record B39 wrong sizeof");
_Static_assert(_Alignof(struct B39_alignment) == 128, "record B39 wrong alignment");
_Static_assert(sizeof(struct B39_packed) == 128, "record B39 wrong sizeof");
_Static_assert(_Alignof(struct B39_packed) == 1, "record B39 wrong alignment");
_Static_assert(sizeof(struct B39_required_alignment) == 129, "record B39 wrong sizeof");
_Static_assert(_Alignof(struct B39_required_alignment) == 1, "record B39 wrong alignment");
_Static_assert(sizeof(struct B39_size) == 130, "record B39 wrong sizeof");
_Static_assert(_Alignof(struct B39_size) == 1, "record B39 wrong alignment");
#endif
// MAPPING|FOUR|avr-atmega328-other-gnu:Gcc|END
// repr targets AvrUnknownUnknown|Some("avr-atmega328-other-gnu") 
#elif defined(FOUR)
_Static_assert(sizeof(A00) == 128, "record A00 wrong sizeof");
_Static_assert(_Alignof(A00) == 128, "record A00 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A00_alignment) == 256, "record A00 wrong sizeof");
_Static_assert(_Alignof(struct A00_alignment) == 128, "record A00 wrong alignment");
_Static_assert(sizeof(struct A00_packed) == 128, "record A00 wrong sizeof");
_Static_assert(_Alignof(struct A00_packed) == 1, "record A00 wrong alignment");
_Static_assert(sizeof(struct A00_required_alignment) == 129, "record A00 wrong sizeof");
_Static_assert(_Alignof(struct A00_required_alignment) == 1, "record A00 wrong alignment");
_Static_assert(sizeof(struct A00_size) == 130, "record A00 wrong sizeof");
_Static_assert(_Alignof(struct A00_size) == 1, "record A00 wrong alignment");
#endif
_Static_assert(sizeof(A01) == 8, "record A01 wrong sizeof");
_Static_assert(_Alignof(A01) == 1, "record A01 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A01_alignment) == 9, "record A01 wrong sizeof");
_Static_assert(_Alignof(struct A01_alignment) == 1, "record A01 wrong alignment");
_Static_assert(sizeof(struct A01_packed) == 8, "record A01 wrong sizeof");
_Static_assert(_Alignof(struct A01_packed) == 1, "record A01 wrong alignment");
_Static_assert(sizeof(struct A01_required_alignment) == 9, "record A01 wrong sizeof");
_Static_assert(_Alignof(struct A01_required_alignment) == 1, "record A01 wrong alignment");
_Static_assert(sizeof(struct A01_size) == 10, "record A01 wrong sizeof");
_Static_assert(_Alignof(struct A01_size) == 1, "record A01 wrong alignment");
#endif
_Static_assert(sizeof(A02) == 8, "record A02 wrong sizeof");
_Static_assert(_Alignof(A02) == 2, "record A02 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A02_alignment) == 10, "record A02 wrong sizeof");
_Static_assert(_Alignof(struct A02_alignment) == 2, "record A02 wrong alignment");
_Static_assert(sizeof(struct A02_packed) == 8, "record A02 wrong sizeof");
_Static_assert(_Alignof(struct A02_packed) == 1, "record A02 wrong alignment");
_Static_assert(sizeof(struct A02_required_alignment) == 9, "record A02 wrong sizeof");
_Static_assert(_Alignof(struct A02_required_alignment) == 1, "record A02 wrong alignment");
_Static_assert(sizeof(struct A02_size) == 10, "record A02 wrong sizeof");
_Static_assert(_Alignof(struct A02_size) == 1, "record A02 wrong alignment");
#endif
_Static_assert(sizeof(A03) == 128, "record A03 wrong sizeof");
_Static_assert(_Alignof(A03) == 128, "record A03 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A03_alignment) == 256, "record A03 wrong sizeof");
_Static_assert(_Alignof(struct A03_alignment) == 128, "record A03 wrong alignment");
_Static_assert(sizeof(struct A03_packed) == 128, "record A03 wrong sizeof");
_Static_assert(_Alignof(struct A03_packed) == 1, "record A03 wrong alignment");
_Static_assert(sizeof(struct A03_required_alignment) == 129, "record A03 wrong sizeof");
_Static_assert(_Alignof(struct A03_required_alignment) == 1, "record A03 wrong alignment");
_Static_assert(sizeof(struct A03_size) == 130, "record A03 wrong sizeof");
_Static_assert(_Alignof(struct A03_size) == 1, "record A03 wrong alignment");
#endif
_Static_assert(sizeof(A04) == 8, "record A04 wrong sizeof");
_Static_assert(_Alignof(A04) == 4, "record A04 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A04_alignment) == 12, "record A04 wrong sizeof");
_Static_assert(_Alignof(struct A04_alignment) == 4, "record A04 wrong alignment");
_Static_assert(sizeof(struct A04_packed) == 8, "record A04 wrong sizeof");
_Static_assert(_Alignof(struct A04_packed) == 1, "record A04 wrong alignment");
_Static_assert(sizeof(struct A04_required_alignment) == 9, "record A04 wrong sizeof");
_Static_assert(_Alignof(struct A04_required_alignment) == 1, "record A04 wrong alignment");
_Static_assert(sizeof(struct A04_size) == 10, "record A04 wrong sizeof");
_Static_assert(_Alignof(struct A04_size) == 1, "record A04 wrong alignment");
#endif
_Static_assert(sizeof(A05) == 128, "record A05 wrong sizeof");
_Static_assert(_Alignof(A05) == 128, "record A05 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A05_alignment) == 256, "record A05 wrong sizeof");
_Static_assert(_Alignof(struct A05_alignment) == 128, "record A05 wrong alignment");
_Static_assert(sizeof(struct A05_packed) == 128, "record A05 wrong sizeof");
_Static_assert(_Alignof(struct A05_packed) == 1, "record A05 wrong alignment");
_Static_assert(sizeof(struct A05_required_alignment) == 129, "record A05 wrong sizeof");
_Static_assert(_Alignof(struct A05_required_alignment) == 1, "record A05 wrong alignment");
_Static_assert(sizeof(struct A05_size) == 130, "record A05 wrong sizeof");
_Static_assert(_Alignof(struct A05_size) == 1, "record A05 wrong alignment");
#endif
_Static_assert(sizeof(A06) == 128, "record A06 wrong sizeof");
_Static_assert(_Alignof(A06) == 128, "record A06 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A06_alignment) == 256, "record A06 wrong sizeof");
_Static_assert(_Alignof(struct A06_alignment) == 128, "record A06 wrong alignment");
_Static_assert(sizeof(struct A06_packed) == 128, "record A06 wrong sizeof");
_Static_assert(_Alignof(struct A06_packed) == 1, "record A06 wrong alignment");
_Static_assert(sizeof(struct A06_required_alignment) == 129, "record A06 wrong sizeof");
_Static_assert(_Alignof(struct A06_required_alignment) == 1, "record A06 wrong alignment");
_Static_assert(sizeof(struct A06_size) == 130, "record A06 wrong sizeof");
_Static_assert(_Alignof(struct A06_size) == 1, "record A06 wrong alignment");
#endif
_Static_assert(sizeof(A07) == 128, "record A07 wrong sizeof");
_Static_assert(_Alignof(A07) == 128, "record A07 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A07_alignment) == 256, "record A07 wrong sizeof");
_Static_assert(_Alignof(struct A07_alignment) == 128, "record A07 wrong alignment");
_Static_assert(sizeof(struct A07_packed) == 128, "record A07 wrong sizeof");
_Static_assert(_Alignof(struct A07_packed) == 1, "record A07 wrong alignment");
_Static_assert(sizeof(struct A07_required_alignment) == 129, "record A07 wrong sizeof");
_Static_assert(_Alignof(struct A07_required_alignment) == 1, "record A07 wrong alignment");
_Static_assert(sizeof(struct A07_size) == 130, "record A07 wrong sizeof");
_Static_assert(_Alignof(struct A07_size) == 1, "record A07 wrong alignment");
#endif
_Static_assert(sizeof(A08) == 8, "record A08 wrong sizeof");
_Static_assert(_Alignof(A08) == 8, "record A08 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A08_alignment) == 16, "record A08 wrong sizeof");
_Static_assert(_Alignof(struct A08_alignment) == 8, "record A08 wrong alignment");
_Static_assert(sizeof(struct A08_packed) == 8, "record A08 wrong sizeof");
_Static_assert(_Alignof(struct A08_packed) == 1, "record A08 wrong alignment");
_Static_assert(sizeof(struct A08_required_alignment) == 9, "record A08 wrong sizeof");
_Static_assert(_Alignof(struct A08_required_alignment) == 1, "record A08 wrong alignment");
_Static_assert(sizeof(struct A08_size) == 10, "record A08 wrong sizeof");
_Static_assert(_Alignof(struct A08_size) == 1, "record A08 wrong alignment");
#endif
_Static_assert(sizeof(A09) == 128, "record A09 wrong sizeof");
_Static_assert(_Alignof(A09) == 128, "record A09 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A09_alignment) == 256, "record A09 wrong sizeof");
_Static_assert(_Alignof(struct A09_alignment) == 128, "record A09 wrong alignment");
_Static_assert(sizeof(struct A09_packed) == 128, "record A09 wrong sizeof");
_Static_assert(_Alignof(struct A09_packed) == 1, "record A09 wrong alignment");
_Static_assert(sizeof(struct A09_required_alignment) == 129, "record A09 wrong sizeof");
_Static_assert(_Alignof(struct A09_required_alignment) == 1, "record A09 wrong alignment");
_Static_assert(sizeof(struct A09_size) == 130, "record A09 wrong sizeof");
_Static_assert(_Alignof(struct A09_size) == 1, "record A09 wrong alignment");
#endif
_Static_assert(sizeof(A10) == 128, "record A10 wrong sizeof");
_Static_assert(_Alignof(A10) == 128, "record A10 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A10_alignment) == 256, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_alignment) == 128, "record A10 wrong alignment");
_Static_assert(sizeof(struct A10_packed) == 128, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_packed) == 1, "record A10 wrong alignment");
_Static_assert(sizeof(struct A10_required_alignment) == 129, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_required_alignment) == 1, "record A10 wrong alignment");
_Static_assert(sizeof(struct A10_size) == 130, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_size) == 1, "record A10 wrong alignment");
#endif
_Static_assert(sizeof(A11) == 128, "record A11 wrong sizeof");
_Static_assert(_Alignof(A11) == 128, "record A11 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A11_alignment) == 256, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_alignment) == 128, "record A11 wrong alignment");
_Static_assert(sizeof(struct A11_packed) == 128, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_packed) == 1, "record A11 wrong alignment");
_Static_assert(sizeof(struct A11_required_alignment) == 129, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_required_alignment) == 1, "record A11 wrong alignment");
_Static_assert(sizeof(struct A11_size) == 130, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_size) == 1, "record A11 wrong alignment");
#endif
_Static_assert(sizeof(A12) == 128, "record A12 wrong sizeof");
_Static_assert(_Alignof(A12) == 128, "record A12 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A12_alignment) == 256, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_alignment) == 128, "record A12 wrong alignment");
_Static_assert(sizeof(struct A12_packed) == 128, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_packed) == 1, "record A12 wrong alignment");
_Static_assert(sizeof(struct A12_required_alignment) == 129, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_required_alignment) == 1, "record A12 wrong alignment");
_Static_assert(sizeof(struct A12_size) == 130, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_size) == 1, "record A12 wrong alignment");
#endif
_Static_assert(sizeof(A13) == 128, "record A13 wrong sizeof");
_Static_assert(_Alignof(A13) == 128, "record A13 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A13_alignment) == 256, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_alignment) == 128, "record A13 wrong alignment");
_Static_assert(sizeof(struct A13_packed) == 128, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_packed) == 1, "record A13 wrong alignment");
_Static_assert(sizeof(struct A13_required_alignment) == 129, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_required_alignment) == 1, "record A13 wrong alignment");
_Static_assert(sizeof(struct A13_size) == 130, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_size) == 1, "record A13 wrong alignment");
#endif
_Static_assert(sizeof(A14) == 128, "record A14 wrong sizeof");
_Static_assert(_Alignof(A14) == 128, "record A14 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A14_alignment) == 256, "record A14 wrong sizeof");
_Static_assert(_Alignof(struct A14_alignment) == 128, "record A14 wrong alignment");
_Static_assert(sizeof(struct A14_packed) == 128, "record A14 wrong sizeof");
_Static_assert(_Alignof(struct A14_packed) == 1, "record A14 wrong alignment");
_Static_assert(sizeof(struct A14_required_alignment) == 129, "record A14 wrong sizeof");
_Static_assert(_Alignof(struct A14_required_alignment) == 1, "record A14 wrong alignment");
_Static_assert(sizeof(struct A14_size) == 130, "record A14 wrong sizeof");
_Static_assert(_Alignof(struct A14_size) == 1, "record A14 wrong alignment");
#endif
_Static_assert(sizeof(A15) == 128, "record A15 wrong sizeof");
_Static_assert(_Alignof(A15) == 128, "record A15 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A15_alignment) == 256, "record A15 wrong sizeof");
_Static_assert(_Alignof(struct A15_alignment) == 128, "record A15 wrong alignment");
_Static_assert(sizeof(struct A15_packed) == 128, "record A15 wrong sizeof");
_Static_assert(_Alignof(struct A15_packed) == 1, "record A15 wrong alignment");
_Static_assert(sizeof(struct A15_required_alignment) == 129, "record A15 wrong sizeof");
_Static_assert(_Alignof(struct A15_required_alignment) == 1, "record A15 wrong alignment");
_Static_assert(sizeof(struct A15_size) == 130, "record A15 wrong sizeof");
_Static_assert(_Alignof(struct A15_size) == 1, "record A15 wrong alignment");
#endif
_Static_assert(sizeof(A16) == 16, "record A16 wrong sizeof");
_Static_assert(_Alignof(A16) == 16, "record A16 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A16_alignment) == 32, "record A16 wrong sizeof");
_Static_assert(_Alignof(struct A16_alignment) == 16, "record A16 wrong alignment");
_Static_assert(sizeof(struct A16_packed) == 16, "record A16 wrong sizeof");
_Static_assert(_Alignof(struct A16_packed) == 1, "record A16 wrong alignment");
_Static_assert(sizeof(struct A16_required_alignment) == 17, "record A16 wrong sizeof");
_Static_assert(_Alignof(struct A16_required_alignment) == 1, "record A16 wrong alignment");
_Static_assert(sizeof(struct A16_size) == 18, "record A16 wrong sizeof");
_Static_assert(_Alignof(struct A16_size) == 1, "record A16 wrong alignment");
#endif
_Static_assert(sizeof(A17) == 128, "record A17 wrong sizeof");
_Static_assert(_Alignof(A17) == 128, "record A17 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A17_alignment) == 256, "record A17 wrong sizeof");
_Static_assert(_Alignof(struct A17_alignment) == 128, "record A17 wrong alignment");
_Static_assert(sizeof(struct A17_packed) == 128, "record A17 wrong sizeof");
_Static_assert(_Alignof(struct A17_packed) == 1, "record A17 wrong alignment");
_Static_assert(sizeof(struct A17_required_alignment) == 129, "record A17 wrong sizeof");
_Static_assert(_Alignof(struct A17_required_alignment) == 1, "record A17 wrong alignment");
_Static_assert(sizeof(struct A17_size) == 130, "record A17 wrong sizeof");
_Static_assert(_Alignof(struct A17_size) == 1, "record A17 wrong alignment");
#endif
_Static_assert(sizeof(A18) == 128, "record A18 wrong sizeof");
_Static_assert(_Alignof(A18) == 128, "record A18 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A18_alignment) == 256, "record A18 wrong sizeof");
_Static_assert(_Alignof(struct A18_alignment) == 128, "record A18 wrong alignment");
_Static_assert(sizeof(struct A18_packed) == 128, "record A18 wrong sizeof");
_Static_assert(_Alignof(struct A18_packed) == 1, "record A18 wrong alignment");
_Static_assert(sizeof(struct A18_required_alignment) == 129, "record A18 wrong sizeof");
_Static_assert(_Alignof(struct A18_required_alignment) == 1, "record A18 wrong alignment");
_Static_assert(sizeof(struct A18_size) == 130, "record A18 wrong sizeof");
_Static_assert(_Alignof(struct A18_size) == 1, "record A18 wrong alignment");
#endif
_Static_assert(sizeof(A19) == 128, "record A19 wrong sizeof");
_Static_assert(_Alignof(A19) == 128, "record A19 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A19_alignment) == 256, "record A19 wrong sizeof");
_Static_assert(_Alignof(struct A19_alignment) == 128, "record A19 wrong alignment");
_Static_assert(sizeof(struct A19_packed) == 128, "record A19 wrong sizeof");
_Static_assert(_Alignof(struct A19_packed) == 1, "record A19 wrong alignment");
_Static_assert(sizeof(struct A19_required_alignment) == 129, "record A19 wrong sizeof");
_Static_assert(_Alignof(struct A19_required_alignment) == 1, "record A19 wrong alignment");
_Static_assert(sizeof(struct A19_size) == 130, "record A19 wrong sizeof");
_Static_assert(_Alignof(struct A19_size) == 1, "record A19 wrong alignment");
#endif
_Static_assert(sizeof(A20) == 128, "record A20 wrong sizeof");
_Static_assert(_Alignof(A20) == 128, "record A20 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A20_alignment) == 256, "record A20 wrong sizeof");
_Static_assert(_Alignof(struct A20_alignment) == 128, "record A20 wrong alignment");
_Static_assert(sizeof(struct A20_packed) == 128, "record A20 wrong sizeof");
_Static_assert(_Alignof(struct A20_packed) == 1, "record A20 wrong alignment");
_Static_assert(sizeof(struct A20_required_alignment) == 129, "record A20 wrong sizeof");
_Static_assert(_Alignof(struct A20_required_alignment) == 1, "record A20 wrong alignment");
_Static_assert(sizeof(struct A20_size) == 130, "record A20 wrong sizeof");
_Static_assert(_Alignof(struct A20_size) == 1, "record A20 wrong alignment");
#endif
_Static_assert(sizeof(A21) == 128, "record A21 wrong sizeof");
_Static_assert(_Alignof(A21) == 128, "record A21 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A21_alignment) == 256, "record A21 wrong sizeof");
_Static_assert(_Alignof(struct A21_alignment) == 128, "record A21 wrong alignment");
_Static_assert(sizeof(struct A21_packed) == 128, "record A21 wrong sizeof");
_Static_assert(_Alignof(struct A21_packed) == 1, "record A21 wrong alignment");
_Static_assert(sizeof(struct A21_required_alignment) == 129, "record A21 wrong sizeof");
_Static_assert(_Alignof(struct A21_required_alignment) == 1, "record A21 wrong alignment");
_Static_assert(sizeof(struct A21_size) == 130, "record A21 wrong sizeof");
_Static_assert(_Alignof(struct A21_size) == 1, "record A21 wrong alignment");
#endif
_Static_assert(sizeof(A22) == 128, "record A22 wrong sizeof");
_Static_assert(_Alignof(A22) == 128, "record A22 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A22_alignment) == 256, "record A22 wrong sizeof");
_Static_assert(_Alignof(struct A22_alignment) == 128, "record A22 wrong alignment");
_Static_assert(sizeof(struct A22_packed) == 128, "record A22 wrong sizeof");
_Static_assert(_Alignof(struct A22_packed) == 1, "record A22 wrong alignment");
_Static_assert(sizeof(struct A22_required_alignment) == 129, "record A22 wrong sizeof");
_Static_assert(_Alignof(struct A22_required_alignment) == 1, "record A22 wrong alignment");
_Static_assert(sizeof(struct A22_size) == 130, "record A22 wrong sizeof");
_Static_assert(_Alignof(struct A22_size) == 1, "record A22 wrong alignment");
#endif
_Static_assert(sizeof(A23) == 128, "record A23 wrong sizeof");
_Static_assert(_Alignof(A23) == 128, "record A23 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A23_alignment) == 256, "record A23 wrong sizeof");
_Static_assert(_Alignof(struct A23_alignment) == 128, "record A23 wrong alignment");
_Static_assert(sizeof(struct A23_packed) == 128, "record A23 wrong sizeof");
_Static_assert(_Alignof(struct A23_packed) == 1, "record A23 wrong alignment");
_Static_assert(sizeof(struct A23_required_alignment) == 129, "record A23 wrong sizeof");
_Static_assert(_Alignof(struct A23_required_alignment) == 1, "record A23 wrong alignment");
_Static_assert(sizeof(struct A23_size) == 130, "record A23 wrong sizeof");
_Static_assert(_Alignof(struct A23_size) == 1, "record A23 wrong alignment");
#endif
_Static_assert(sizeof(A24) == 128, "record A24 wrong sizeof");
_Static_assert(_Alignof(A24) == 128, "record A24 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A24_alignment) == 256, "record A24 wrong sizeof");
_Static_assert(_Alignof(struct A24_alignment) == 128, "record A24 wrong alignment");
_Static_assert(sizeof(struct A24_packed) == 128, "record A24 wrong sizeof");
_Static_assert(_Alignof(struct A24_packed) == 1, "record A24 wrong alignment");
_Static_assert(sizeof(struct A24_required_alignment) == 129, "record A24 wrong sizeof");
_Static_assert(_Alignof(struct A24_required_alignment) == 1, "record A24 wrong alignment");
_Static_assert(sizeof(struct A24_size) == 130, "record A24 wrong sizeof");
_Static_assert(_Alignof(struct A24_size) == 1, "record A24 wrong alignment");
#endif
_Static_assert(sizeof(A25) == 128, "record A25 wrong sizeof");
_Static_assert(_Alignof(A25) == 128, "record A25 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A25_alignment) == 256, "record A25 wrong sizeof");
_Static_assert(_Alignof(struct A25_alignment) == 128, "record A25 wrong alignment");
_Static_assert(sizeof(struct A25_packed) == 128, "record A25 wrong sizeof");
_Static_assert(_Alignof(struct A25_packed) == 1, "record A25 wrong alignment");
_Static_assert(sizeof(struct A25_required_alignment) == 129, "record A25 wrong sizeof");
_Static_assert(_Alignof(struct A25_required_alignment) == 1, "record A25 wrong alignment");
_Static_assert(sizeof(struct A25_size) == 130, "record A25 wrong sizeof");
_Static_assert(_Alignof(struct A25_size) == 1, "record A25 wrong alignment");
#endif
_Static_assert(sizeof(A26) == 128, "record A26 wrong sizeof");
_Static_assert(_Alignof(A26) == 128, "record A26 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A26_alignment) == 256, "record A26 wrong sizeof");
_Static_assert(_Alignof(struct A26_alignment) == 128, "record A26 wrong alignment");
_Static_assert(sizeof(struct A26_packed) == 128, "record A26 wrong sizeof");
_Static_assert(_Alignof(struct A26_packed) == 1, "record A26 wrong alignment");
_Static_assert(sizeof(struct A26_required_alignment) == 129, "record A26 wrong sizeof");
_Static_assert(_Alignof(struct A26_required_alignment) == 1, "record A26 wrong alignment");
_Static_assert(sizeof(struct A26_size) == 130, "record A26 wrong sizeof");
_Static_assert(_Alignof(struct A26_size) == 1, "record A26 wrong alignment");
#endif
_Static_assert(sizeof(A27) == 128, "record A27 wrong sizeof");
_Static_assert(_Alignof(A27) == 128, "record A27 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A27_alignment) == 256, "record A27 wrong sizeof");
_Static_assert(_Alignof(struct A27_alignment) == 128, "record A27 wrong alignment");
_Static_assert(sizeof(struct A27_packed) == 128, "record A27 wrong sizeof");
_Static_assert(_Alignof(struct A27_packed) == 1, "record A27 wrong alignment");
_Static_assert(sizeof(struct A27_required_alignment) == 129, "record A27 wrong sizeof");
_Static_assert(_Alignof(struct A27_required_alignment) == 1, "record A27 wrong alignment");
_Static_assert(sizeof(struct A27_size) == 130, "record A27 wrong sizeof");
_Static_assert(_Alignof(struct A27_size) == 1, "record A27 wrong alignment");
#endif
_Static_assert(sizeof(A28) == 128, "record A28 wrong sizeof");
_Static_assert(_Alignof(A28) == 128, "record A28 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A28_alignment) == 256, "record A28 wrong sizeof");
_Static_assert(_Alignof(struct A28_alignment) == 128, "record A28 wrong alignment");
_Static_assert(sizeof(struct A28_packed) == 128, "record A28 wrong sizeof");
_Static_assert(_Alignof(struct A28_packed) == 1, "record A28 wrong alignment");
_Static_assert(sizeof(struct A28_required_alignment) == 129, "record A28 wrong sizeof");
_Static_assert(_Alignof(struct A28_required_alignment) == 1, "record A28 wrong alignment");
_Static_assert(sizeof(struct A28_size) == 130, "record A28 wrong sizeof");
_Static_assert(_Alignof(struct A28_size) == 1, "record A28 wrong alignment");
#endif
_Static_assert(sizeof(A29) == 128, "record A29 wrong sizeof");
_Static_assert(_Alignof(A29) == 128, "record A29 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A29_alignment) == 256, "record A29 wrong sizeof");
_Static_assert(_Alignof(struct A29_alignment) == 128, "record A29 wrong alignment");
_Static_assert(sizeof(struct A29_packed) == 128, "record A29 wrong sizeof");
_Static_assert(_Alignof(struct A29_packed) == 1, "record A29 wrong alignment");
_Static_assert(sizeof(struct A29_required_alignment) == 129, "record A29 wrong sizeof");
_Static_assert(_Alignof(struct A29_required_alignment) == 1, "record A29 wrong alignment");
_Static_assert(sizeof(struct A29_size) == 130, "record A29 wrong sizeof");
_Static_assert(_Alignof(struct A29_size) == 1, "record A29 wrong alignment");
#endif
_Static_assert(sizeof(A30) == 128, "record A30 wrong sizeof");
_Static_assert(_Alignof(A30) == 128, "record A30 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A30_alignment) == 256, "record A30 wrong sizeof");
_Static_assert(_Alignof(struct A30_alignment) == 128, "record A30 wrong alignment");
_Static_assert(sizeof(struct A30_packed) == 128, "record A30 wrong sizeof");
_Static_assert(_Alignof(struct A30_packed) == 1, "record A30 wrong alignment");
_Static_assert(sizeof(struct A30_required_alignment) == 129, "record A30 wrong sizeof");
_Static_assert(_Alignof(struct A30_required_alignment) == 1, "record A30 wrong alignment");
_Static_assert(sizeof(struct A30_size) == 130, "record A30 wrong sizeof");
_Static_assert(_Alignof(struct A30_size) == 1, "record A30 wrong alignment");
#endif
_Static_assert(sizeof(A31) == 128, "record A31 wrong sizeof");
_Static_assert(_Alignof(A31) == 128, "record A31 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A31_alignment) == 256, "record A31 wrong sizeof");
_Static_assert(_Alignof(struct A31_alignment) == 128, "record A31 wrong alignment");
_Static_assert(sizeof(struct A31_packed) == 128, "record A31 wrong sizeof");
_Static_assert(_Alignof(struct A31_packed) == 1, "record A31 wrong alignment");
_Static_assert(sizeof(struct A31_required_alignment) == 129, "record A31 wrong sizeof");
_Static_assert(_Alignof(struct A31_required_alignment) == 1, "record A31 wrong alignment");
_Static_assert(sizeof(struct A31_size) == 130, "record A31 wrong sizeof");
_Static_assert(_Alignof(struct A31_size) == 1, "record A31 wrong alignment");
#endif
_Static_assert(sizeof(A32) == 128, "record A32 wrong sizeof");
_Static_assert(_Alignof(A32) == 128, "record A32 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A32_alignment) == 256, "record A32 wrong sizeof");
_Static_assert(_Alignof(struct A32_alignment) == 128, "record A32 wrong alignment");
_Static_assert(sizeof(struct A32_packed) == 128, "record A32 wrong sizeof");
_Static_assert(_Alignof(struct A32_packed) == 1, "record A32 wrong alignment");
_Static_assert(sizeof(struct A32_required_alignment) == 129, "record A32 wrong sizeof");
_Static_assert(_Alignof(struct A32_required_alignment) == 1, "record A32 wrong alignment");
_Static_assert(sizeof(struct A32_size) == 130, "record A32 wrong sizeof");
_Static_assert(_Alignof(struct A32_size) == 1, "record A32 wrong alignment");
#endif
_Static_assert(sizeof(A33) == 128, "record A33 wrong sizeof");
_Static_assert(_Alignof(A33) == 128, "record A33 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A33_alignment) == 256, "record A33 wrong sizeof");
_Static_assert(_Alignof(struct A33_alignment) == 128, "record A33 wrong alignment");
_Static_assert(sizeof(struct A33_packed) == 128, "record A33 wrong sizeof");
_Static_assert(_Alignof(struct A33_packed) == 1, "record A33 wrong alignment");
_Static_assert(sizeof(struct A33_required_alignment) == 129, "record A33 wrong sizeof");
_Static_assert(_Alignof(struct A33_required_alignment) == 1, "record A33 wrong alignment");
_Static_assert(sizeof(struct A33_size) == 130, "record A33 wrong sizeof");
_Static_assert(_Alignof(struct A33_size) == 1, "record A33 wrong alignment");
#endif
_Static_assert(sizeof(A34) == 128, "record A34 wrong sizeof");
_Static_assert(_Alignof(A34) == 128, "record A34 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A34_alignment) == 256, "record A34 wrong sizeof");
_Static_assert(_Alignof(struct A34_alignment) == 128, "record A34 wrong alignment");
_Static_assert(sizeof(struct A34_packed) == 128, "record A34 wrong sizeof");
_Static_assert(_Alignof(struct A34_packed) == 1, "record A34 wrong alignment");
_Static_assert(sizeof(struct A34_required_alignment) == 129, "record A34 wrong sizeof");
_Static_assert(_Alignof(struct A34_required_alignment) == 1, "record A34 wrong alignment");
_Static_assert(sizeof(struct A34_size) == 130, "record A34 wrong sizeof");
_Static_assert(_Alignof(struct A34_size) == 1, "record A34 wrong alignment");
#endif
_Static_assert(sizeof(A35) == 128, "record A35 wrong sizeof");
_Static_assert(_Alignof(A35) == 128, "record A35 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A35_alignment) == 256, "record A35 wrong sizeof");
_Static_assert(_Alignof(struct A35_alignment) == 128, "record A35 wrong alignment");
_Static_assert(sizeof(struct A35_packed) == 128, "record A35 wrong sizeof");
_Static_assert(_Alignof(struct A35_packed) == 1, "record A35 wrong alignment");
_Static_assert(sizeof(struct A35_required_alignment) == 129, "record A35 wrong sizeof");
_Static_assert(_Alignof(struct A35_required_alignment) == 1, "record A35 wrong alignment");
_Static_assert(sizeof(struct A35_size) == 130, "record A35 wrong sizeof");
_Static_assert(_Alignof(struct A35_size) == 1, "record A35 wrong alignment");
#endif
_Static_assert(sizeof(A36) == 128, "record A36 wrong sizeof");
_Static_assert(_Alignof(A36) == 128, "record A36 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A36_alignment) == 256, "record A36 wrong sizeof");
_Static_assert(_Alignof(struct A36_alignment) == 128, "record A36 wrong alignment");
_Static_assert(sizeof(struct A36_packed) == 128, "record A36 wrong sizeof");
_Static_assert(_Alignof(struct A36_packed) == 1, "record A36 wrong alignment");
_Static_assert(sizeof(struct A36_required_alignment) == 129, "record A36 wrong sizeof");
_Static_assert(_Alignof(struct A36_required_alignment) == 1, "record A36 wrong alignment");
_Static_assert(sizeof(struct A36_size) == 130, "record A36 wrong sizeof");
_Static_assert(_Alignof(struct A36_size) == 1, "record A36 wrong alignment");
#endif
_Static_assert(sizeof(A37) == 128, "record A37 wrong sizeof");
_Static_assert(_Alignof(A37) == 128, "record A37 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A37_alignment) == 256, "record A37 wrong sizeof");
_Static_assert(_Alignof(struct A37_alignment) == 128, "record A37 wrong alignment");
_Static_assert(sizeof(struct A37_packed) == 128, "record A37 wrong sizeof");
_Static_assert(_Alignof(struct A37_packed) == 1, "record A37 wrong alignment");
_Static_assert(sizeof(struct A37_required_alignment) == 129, "record A37 wrong sizeof");
_Static_assert(_Alignof(struct A37_required_alignment) == 1, "record A37 wrong alignment");
_Static_assert(sizeof(struct A37_size) == 130, "record A37 wrong sizeof");
_Static_assert(_Alignof(struct A37_size) == 1, "record A37 wrong alignment");
#endif
_Static_assert(sizeof(A38) == 128, "record A38 wrong sizeof");
_Static_assert(_Alignof(A38) == 128, "record A38 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A38_alignment) == 256, "record A38 wrong sizeof");
_Static_assert(_Alignof(struct A38_alignment) == 128, "record A38 wrong alignment");
_Static_assert(sizeof(struct A38_packed) == 128, "record A38 wrong sizeof");
_Static_assert(_Alignof(struct A38_packed) == 1, "record A38 wrong alignment");
_Static_assert(sizeof(struct A38_required_alignment) == 129, "record A38 wrong sizeof");
_Static_assert(_Alignof(struct A38_required_alignment) == 1, "record A38 wrong alignment");
_Static_assert(sizeof(struct A38_size) == 130, "record A38 wrong sizeof");
_Static_assert(_Alignof(struct A38_size) == 1, "record A38 wrong alignment");
#endif
_Static_assert(sizeof(A39) == 128, "record A39 wrong sizeof");
_Static_assert(_Alignof(A39) == 128, "record A39 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A39_alignment) == 256, "record A39 wrong sizeof");
_Static_assert(_Alignof(struct A39_alignment) == 128, "record A39 wrong alignment");
_Static_assert(sizeof(struct A39_packed) == 128, "record A39 wrong sizeof");
_Static_assert(_Alignof(struct A39_packed) == 1, "record A39 wrong alignment");
_Static_assert(sizeof(struct A39_required_alignment) == 129, "record A39 wrong sizeof");
_Static_assert(_Alignof(struct A39_required_alignment) == 1, "record A39 wrong alignment");
_Static_assert(sizeof(struct A39_size) == 130, "record A39 wrong sizeof");
_Static_assert(_Alignof(struct A39_size) == 1, "record A39 wrong alignment");
#endif
_Static_assert(sizeof(B00) == 128, "record B00 wrong sizeof");
_Static_assert(_Alignof(B00) == 128, "record B00 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B00_alignment) == 256, "record B00 wrong sizeof");
_Static_assert(_Alignof(struct B00_alignment) == 128, "record B00 wrong alignment");
_Static_assert(sizeof(struct B00_packed) == 128, "record B00 wrong sizeof");
_Static_assert(_Alignof(struct B00_packed) == 1, "record B00 wrong alignment");
_Static_assert(sizeof(struct B00_required_alignment) == 129, "record B00 wrong sizeof");
_Static_assert(_Alignof(struct B00_required_alignment) == 1, "record B00 wrong alignment");
_Static_assert(sizeof(struct B00_size) == 130, "record B00 wrong sizeof");
_Static_assert(_Alignof(struct B00_size) == 1, "record B00 wrong alignment");
#endif
_Static_assert(sizeof(B01) == 8, "record B01 wrong sizeof");
_Static_assert(_Alignof(B01) == 1, "record B01 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B01_alignment) == 9, "record B01 wrong sizeof");
_Static_assert(_Alignof(struct B01_alignment) == 1, "record B01 wrong alignment");
_Static_assert(sizeof(struct B01_packed) == 8, "record B01 wrong sizeof");
_Static_assert(_Alignof(struct B01_packed) == 1, "record B01 wrong alignment");
_Static_assert(sizeof(struct B01_required_alignment) == 9, "record B01 wrong sizeof");
_Static_assert(_Alignof(struct B01_required_alignment) == 1, "record B01 wrong alignment");
_Static_assert(sizeof(struct B01_size) == 10, "record B01 wrong sizeof");
_Static_assert(_Alignof(struct B01_size) == 1, "record B01 wrong alignment");
#endif
_Static_assert(sizeof(B02) == 8, "record B02 wrong sizeof");
_Static_assert(_Alignof(B02) == 2, "record B02 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B02_alignment) == 10, "record B02 wrong sizeof");
_Static_assert(_Alignof(struct B02_alignment) == 2, "record B02 wrong alignment");
_Static_assert(sizeof(struct B02_packed) == 8, "record B02 wrong sizeof");
_Static_assert(_Alignof(struct B02_packed) == 1, "record B02 wrong alignment");
_Static_assert(sizeof(struct B02_required_alignment) == 9, "record B02 wrong sizeof");
_Static_assert(_Alignof(struct B02_required_alignment) == 1, "record B02 wrong alignment");
_Static_assert(sizeof(struct B02_size) == 10, "record B02 wrong sizeof");
_Static_assert(_Alignof(struct B02_size) == 1, "record B02 wrong alignment");
#endif
_Static_assert(sizeof(B03) == 128, "record B03 wrong sizeof");
_Static_assert(_Alignof(B03) == 128, "record B03 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B03_alignment) == 256, "record B03 wrong sizeof");
_Static_assert(_Alignof(struct B03_alignment) == 128, "record B03 wrong alignment");
_Static_assert(sizeof(struct B03_packed) == 128, "record B03 wrong sizeof");
_Static_assert(_Alignof(struct B03_packed) == 1, "record B03 wrong alignment");
_Static_assert(sizeof(struct B03_required_alignment) == 129, "record B03 wrong sizeof");
_Static_assert(_Alignof(struct B03_required_alignment) == 1, "record B03 wrong alignment");
_Static_assert(sizeof(struct B03_size) == 130, "record B03 wrong sizeof");
_Static_assert(_Alignof(struct B03_size) == 1, "record B03 wrong alignment");
#endif
_Static_assert(sizeof(B04) == 8, "record B04 wrong sizeof");
_Static_assert(_Alignof(B04) == 4, "record B04 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B04_alignment) == 12, "record B04 wrong sizeof");
_Static_assert(_Alignof(struct B04_alignment) == 4, "record B04 wrong alignment");
_Static_assert(sizeof(struct B04_packed) == 8, "record B04 wrong sizeof");
_Static_assert(_Alignof(struct B04_packed) == 1, "record B04 wrong alignment");
_Static_assert(sizeof(struct B04_required_alignment) == 9, "record B04 wrong sizeof");
_Static_assert(_Alignof(struct B04_required_alignment) == 1, "record B04 wrong alignment");
_Static_assert(sizeof(struct B04_size) == 10, "record B04 wrong sizeof");
_Static_assert(_Alignof(struct B04_size) == 1, "record B04 wrong alignment");
#endif
_Static_assert(sizeof(B05) == 128, "record B05 wrong sizeof");
_Static_assert(_Alignof(B05) == 128, "record B05 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B05_alignment) == 256, "record B05 wrong sizeof");
_Static_assert(_Alignof(struct B05_alignment) == 128, "record B05 wrong alignment");
_Static_assert(sizeof(struct B05_packed) == 128, "record B05 wrong sizeof");
_Static_assert(_Alignof(struct B05_packed) == 1, "record B05 wrong alignment");
_Static_assert(sizeof(struct B05_required_alignment) == 129, "record B05 wrong sizeof");
_Static_assert(_Alignof(struct B05_required_alignment) == 1, "record B05 wrong alignment");
_Static_assert(sizeof(struct B05_size) == 130, "record B05 wrong sizeof");
_Static_assert(_Alignof(struct B05_size) == 1, "record B05 wrong alignment");
#endif
_Static_assert(sizeof(B06) == 128, "record B06 wrong sizeof");
_Static_assert(_Alignof(B06) == 128, "record B06 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B06_alignment) == 256, "record B06 wrong sizeof");
_Static_assert(_Alignof(struct B06_alignment) == 128, "record B06 wrong alignment");
_Static_assert(sizeof(struct B06_packed) == 128, "record B06 wrong sizeof");
_Static_assert(_Alignof(struct B06_packed) == 1, "record B06 wrong alignment");
_Static_assert(sizeof(struct B06_required_alignment) == 129, "record B06 wrong sizeof");
_Static_assert(_Alignof(struct B06_required_alignment) == 1, "record B06 wrong alignment");
_Static_assert(sizeof(struct B06_size) == 130, "record B06 wrong sizeof");
_Static_assert(_Alignof(struct B06_size) == 1, "record B06 wrong alignment");
#endif
_Static_assert(sizeof(B07) == 128, "record B07 wrong sizeof");
_Static_assert(_Alignof(B07) == 128, "record B07 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B07_alignment) == 256, "record B07 wrong sizeof");
_Static_assert(_Alignof(struct B07_alignment) == 128, "record B07 wrong alignment");
_Static_assert(sizeof(struct B07_packed) == 128, "record B07 wrong sizeof");
_Static_assert(_Alignof(struct B07_packed) == 1, "record B07 wrong alignment");
_Static_assert(sizeof(struct B07_required_alignment) == 129, "record B07 wrong sizeof");
_Static_assert(_Alignof(struct B07_required_alignment) == 1, "record B07 wrong alignment");
_Static_assert(sizeof(struct B07_size) == 130, "record B07 wrong sizeof");
_Static_assert(_Alignof(struct B07_size) == 1, "record B07 wrong alignment");
#endif
_Static_assert(sizeof(B08) == 8, "record B08 wrong sizeof");
_Static_assert(_Alignof(B08) == 8, "record B08 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B08_alignment) == 16, "record B08 wrong sizeof");
_Static_assert(_Alignof(struct B08_alignment) == 8, "record B08 wrong alignment");
_Static_assert(sizeof(struct B08_packed) == 8, "record B08 wrong sizeof");
_Static_assert(_Alignof(struct B08_packed) == 1, "record B08 wrong alignment");
_Static_assert(sizeof(struct B08_required_alignment) == 9, "record B08 wrong sizeof");
_Static_assert(_Alignof(struct B08_required_alignment) == 1, "record B08 wrong alignment");
_Static_assert(sizeof(struct B08_size) == 10, "record B08 wrong sizeof");
_Static_assert(_Alignof(struct B08_size) == 1, "record B08 wrong alignment");
#endif
_Static_assert(sizeof(B09) == 128, "record B09 wrong sizeof");
_Static_assert(_Alignof(B09) == 128, "record B09 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B09_alignment) == 256, "record B09 wrong sizeof");
_Static_assert(_Alignof(struct B09_alignment) == 128, "record B09 wrong alignment");
_Static_assert(sizeof(struct B09_packed) == 128, "record B09 wrong sizeof");
_Static_assert(_Alignof(struct B09_packed) == 1, "record B09 wrong alignment");
_Static_assert(sizeof(struct B09_required_alignment) == 129, "record B09 wrong sizeof");
_Static_assert(_Alignof(struct B09_required_alignment) == 1, "record B09 wrong alignment");
_Static_assert(sizeof(struct B09_size) == 130, "record B09 wrong sizeof");
_Static_assert(_Alignof(struct B09_size) == 1, "record B09 wrong alignment");
#endif
_Static_assert(sizeof(B10) == 128, "record B10 wrong sizeof");
_Static_assert(_Alignof(B10) == 128, "record B10 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B10_alignment) == 256, "record B10 wrong sizeof");
_Static_assert(_Alignof(struct B10_alignment) == 128, "record B10 wrong alignment");
_Static_assert(sizeof(struct B10_packed) == 128, "record B10 wrong sizeof");
_Static_assert(_Alignof(struct B10_packed) == 1, "record B10 wrong alignment");
_Static_assert(sizeof(struct B10_required_alignment) == 129, "record B10 wrong sizeof");
_Static_assert(_Alignof(struct B10_required_alignment) == 1, "record B10 wrong alignment");
_Static_assert(sizeof(struct B10_size) == 130, "record B10 wrong sizeof");
_Static_assert(_Alignof(struct B10_size) == 1, "record B10 wrong alignment");
#endif
_Static_assert(sizeof(B11) == 128, "record B11 wrong sizeof");
_Static_assert(_Alignof(B11) == 128, "record B11 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B11_alignment) == 256, "record B11 wrong sizeof");
_Static_assert(_Alignof(struct B11_alignment) == 128, "record B11 wrong alignment");
_Static_assert(sizeof(struct B11_packed) == 128, "record B11 wrong sizeof");
_Static_assert(_Alignof(struct B11_packed) == 1, "record B11 wrong alignment");
_Static_assert(sizeof(struct B11_required_alignment) == 129, "record B11 wrong sizeof");
_Static_assert(_Alignof(struct B11_required_alignment) == 1, "record B11 wrong alignment");
_Static_assert(sizeof(struct B11_size) == 130, "record B11 wrong sizeof");
_Static_assert(_Alignof(struct B11_size) == 1, "record B11 wrong alignment");
#endif
_Static_assert(sizeof(B12) == 128, "record B12 wrong sizeof");
_Static_assert(_Alignof(B12) == 128, "record B12 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B12_alignment) == 256, "record B12 wrong sizeof");
_Static_assert(_Alignof(struct B12_alignment) == 128, "record B12 wrong alignment");
_Static_assert(sizeof(struct B12_packed) == 128, "record B12 wrong sizeof");
_Static_assert(_Alignof(struct B12_packed) == 1, "record B12 wrong alignment");
_Static_assert(sizeof(struct B12_required_alignment) == 129, "record B12 wrong sizeof");
_Static_assert(_Alignof(struct B12_required_alignment) == 1, "record B12 wrong alignment");
_Static_assert(sizeof(struct B12_size) == 130, "record B12 wrong sizeof");
_Static_assert(_Alignof(struct B12_size) == 1, "record B12 wrong alignment");
#endif
_Static_assert(sizeof(B13) == 128, "record B13 wrong sizeof");
_Static_assert(_Alignof(B13) == 128, "record B13 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B13_alignment) == 256, "record B13 wrong sizeof");
_Static_assert(_Alignof(struct B13_alignment) == 128, "record B13 wrong alignment");
_Static_assert(sizeof(struct B13_packed) == 128, "record B13 wrong sizeof");
_Static_assert(_Alignof(struct B13_packed) == 1, "record B13 wrong alignment");
_Static_assert(sizeof(struct B13_required_alignment) == 129, "record B13 wrong sizeof");
_Static_assert(_Alignof(struct B13_required_alignment) == 1, "record B13 wrong alignment");
_Static_assert(sizeof(struct B13_size) == 130, "record B13 wrong sizeof");
_Static_assert(_Alignof(struct B13_size) == 1, "record B13 wrong alignment");
#endif
_Static_assert(sizeof(B14) == 128, "record B14 wrong sizeof");
_Static_assert(_Alignof(B14) == 128, "record B14 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B14_alignment) == 256, "record B14 wrong sizeof");
_Static_assert(_Alignof(struct B14_alignment) == 128, "record B14 wrong alignment");
_Static_assert(sizeof(struct B14_packed) == 128, "record B14 wrong sizeof");
_Static_assert(_Alignof(struct B14_packed) == 1, "record B14 wrong alignment");
_Static_assert(sizeof(struct B14_required_alignment) == 129, "record B14 wrong sizeof");
_Static_assert(_Alignof(struct B14_required_alignment) == 1, "record B14 wrong alignment");
_Static_assert(sizeof(struct B14_size) == 130, "record B14 wrong sizeof");
_Static_assert(_Alignof(struct B14_size) == 1, "record B14 wrong alignment");
#endif
_Static_assert(sizeof(B15) == 128, "record B15 wrong sizeof");
_Static_assert(_Alignof(B15) == 128, "record B15 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B15_alignment) == 256, "record B15 wrong sizeof");
_Static_assert(_Alignof(struct B15_alignment) == 128, "record B15 wrong alignment");
_Static_assert(sizeof(struct B15_packed) == 128, "record B15 wrong sizeof");
_Static_assert(_Alignof(struct B15_packed) == 1, "record B15 wrong alignment");
_Static_assert(sizeof(struct B15_required_alignment) == 129, "record B15 wrong sizeof");
_Static_assert(_Alignof(struct B15_required_alignment) == 1, "record B15 wrong alignment");
_Static_assert(sizeof(struct B15_size) == 130, "record B15 wrong sizeof");
_Static_assert(_Alignof(struct B15_size) == 1, "record B15 wrong alignment");
#endif
_Static_assert(sizeof(B16) == 16, "record B16 wrong sizeof");
_Static_assert(_Alignof(B16) == 16, "record B16 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B16_alignment) == 32, "record B16 wrong sizeof");
_Static_assert(_Alignof(struct B16_alignment) == 16, "record B16 wrong alignment");
_Static_assert(sizeof(struct B16_packed) == 16, "record B16 wrong sizeof");
_Static_assert(_Alignof(struct B16_packed) == 1, "record B16 wrong alignment");
_Static_assert(sizeof(struct B16_required_alignment) == 17, "record B16 wrong sizeof");
_Static_assert(_Alignof(struct B16_required_alignment) == 1, "record B16 wrong alignment");
_Static_assert(sizeof(struct B16_size) == 18, "record B16 wrong sizeof");
_Static_assert(_Alignof(struct B16_size) == 1, "record B16 wrong alignment");
#endif
_Static_assert(sizeof(B17) == 128, "record B17 wrong sizeof");
_Static_assert(_Alignof(B17) == 128, "record B17 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B17_alignment) == 256, "record B17 wrong sizeof");
_Static_assert(_Alignof(struct B17_alignment) == 128, "record B17 wrong alignment");
_Static_assert(sizeof(struct B17_packed) == 128, "record B17 wrong sizeof");
_Static_assert(_Alignof(struct B17_packed) == 1, "record B17 wrong alignment");
_Static_assert(sizeof(struct B17_required_alignment) == 129, "record B17 wrong sizeof");
_Static_assert(_Alignof(struct B17_required_alignment) == 1, "record B17 wrong alignment");
_Static_assert(sizeof(struct B17_size) == 130, "record B17 wrong sizeof");
_Static_assert(_Alignof(struct B17_size) == 1, "record B17 wrong alignment");
#endif
_Static_assert(sizeof(B18) == 128, "record B18 wrong sizeof");
_Static_assert(_Alignof(B18) == 128, "record B18 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B18_alignment) == 256, "record B18 wrong sizeof");
_Static_assert(_Alignof(struct B18_alignment) == 128, "record B18 wrong alignment");
_Static_assert(sizeof(struct B18_packed) == 128, "record B18 wrong sizeof");
_Static_assert(_Alignof(struct B18_packed) == 1, "record B18 wrong alignment");
_Static_assert(sizeof(struct B18_required_alignment) == 129, "record B18 wrong sizeof");
_Static_assert(_Alignof(struct B18_required_alignment) == 1, "record B18 wrong alignment");
_Static_assert(sizeof(struct B18_size) == 130, "record B18 wrong sizeof");
_Static_assert(_Alignof(struct B18_size) == 1, "record B18 wrong alignment");
#endif
_Static_assert(sizeof(B19) == 128, "record B19 wrong sizeof");
_Static_assert(_Alignof(B19) == 128, "record B19 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B19_alignment) == 256, "record B19 wrong sizeof");
_Static_assert(_Alignof(struct B19_alignment) == 128, "record B19 wrong alignment");
_Static_assert(sizeof(struct B19_packed) == 128, "record B19 wrong sizeof");
_Static_assert(_Alignof(struct B19_packed) == 1, "record B19 wrong alignment");
_Static_assert(sizeof(struct B19_required_alignment) == 129, "record B19 wrong sizeof");
_Static_assert(_Alignof(struct B19_required_alignment) == 1, "record B19 wrong alignment");
_Static_assert(sizeof(struct B19_size) == 130, "record B19 wrong sizeof");
_Static_assert(_Alignof(struct B19_size) == 1, "record B19 wrong alignment");
#endif
_Static_assert(sizeof(B20) == 128, "record B20 wrong sizeof");
_Static_assert(_Alignof(B20) == 128, "record B20 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B20_alignment) == 256, "record B20 wrong sizeof");
_Static_assert(_Alignof(struct B20_alignment) == 128, "record B20 wrong alignment");
_Static_assert(sizeof(struct B20_packed) == 128, "record B20 wrong sizeof");
_Static_assert(_Alignof(struct B20_packed) == 1, "record B20 wrong alignment");
_Static_assert(sizeof(struct B20_required_alignment) == 129, "record B20 wrong sizeof");
_Static_assert(_Alignof(struct B20_required_alignment) == 1, "record B20 wrong alignment");
_Static_assert(sizeof(struct B20_size) == 130, "record B20 wrong sizeof");
_Static_assert(_Alignof(struct B20_size) == 1, "record B20 wrong alignment");
#endif
_Static_assert(sizeof(B21) == 128, "record B21 wrong sizeof");
_Static_assert(_Alignof(B21) == 128, "record B21 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B21_alignment) == 256, "record B21 wrong sizeof");
_Static_assert(_Alignof(struct B21_alignment) == 128, "record B21 wrong alignment");
_Static_assert(sizeof(struct B21_packed) == 128, "record B21 wrong sizeof");
_Static_assert(_Alignof(struct B21_packed) == 1, "record B21 wrong alignment");
_Static_assert(sizeof(struct B21_required_alignment) == 129, "record B21 wrong sizeof");
_Static_assert(_Alignof(struct B21_required_alignment) == 1, "record B21 wrong alignment");
_Static_assert(sizeof(struct B21_size) == 130, "record B21 wrong sizeof");
_Static_assert(_Alignof(struct B21_size) == 1, "record B21 wrong alignment");
#endif
_Static_assert(sizeof(B22) == 128, "record B22 wrong sizeof");
_Static_assert(_Alignof(B22) == 128, "record B22 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B22_alignment) == 256, "record B22 wrong sizeof");
_Static_assert(_Alignof(struct B22_alignment) == 128, "record B22 wrong alignment");
_Static_assert(sizeof(struct B22_packed) == 128, "record B22 wrong sizeof");
_Static_assert(_Alignof(struct B22_packed) == 1, "record B22 wrong alignment");
_Static_assert(sizeof(struct B22_required_alignment) == 129, "record B22 wrong sizeof");
_Static_assert(_Alignof(struct B22_required_alignment) == 1, "record B22 wrong alignment");
_Static_assert(sizeof(struct B22_size) == 130, "record B22 wrong sizeof");
_Static_assert(_Alignof(struct B22_size) == 1, "record B22 wrong alignment");
#endif
_Static_assert(sizeof(B23) == 128, "record B23 wrong sizeof");
_Static_assert(_Alignof(B23) == 128, "record B23 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B23_alignment) == 256, "record B23 wrong sizeof");
_Static_assert(_Alignof(struct B23_alignment) == 128, "record B23 wrong alignment");
_Static_assert(sizeof(struct B23_packed) == 128, "record B23 wrong sizeof");
_Static_assert(_Alignof(struct B23_packed) == 1, "record B23 wrong alignment");
_Static_assert(sizeof(struct B23_required_alignment) == 129, "record B23 wrong sizeof");
_Static_assert(_Alignof(struct B23_required_alignment) == 1, "record B23 wrong alignment");
_Static_assert(sizeof(struct B23_size) == 130, "record B23 wrong sizeof");
_Static_assert(_Alignof(struct B23_size) == 1, "record B23 wrong alignment");
#endif
_Static_assert(sizeof(B24) == 128, "record B24 wrong sizeof");
_Static_assert(_Alignof(B24) == 128, "record B24 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B24_alignment) == 256, "record B24 wrong sizeof");
_Static_assert(_Alignof(struct B24_alignment) == 128, "record B24 wrong alignment");
_Static_assert(sizeof(struct B24_packed) == 128, "record B24 wrong sizeof");
_Static_assert(_Alignof(struct B24_packed) == 1, "record B24 wrong alignment");
_Static_assert(sizeof(struct B24_required_alignment) == 129, "record B24 wrong sizeof");
_Static_assert(_Alignof(struct B24_required_alignment) == 1, "record B24 wrong alignment");
_Static_assert(sizeof(struct B24_size) == 130, "record B24 wrong sizeof");
_Static_assert(_Alignof(struct B24_size) == 1, "record B24 wrong alignment");
#endif
_Static_assert(sizeof(B25) == 128, "record B25 wrong sizeof");
_Static_assert(_Alignof(B25) == 128, "record B25 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B25_alignment) == 256, "record B25 wrong sizeof");
_Static_assert(_Alignof(struct B25_alignment) == 128, "record B25 wrong alignment");
_Static_assert(sizeof(struct B25_packed) == 128, "record B25 wrong sizeof");
_Static_assert(_Alignof(struct B25_packed) == 1, "record B25 wrong alignment");
_Static_assert(sizeof(struct B25_required_alignment) == 129, "record B25 wrong sizeof");
_Static_assert(_Alignof(struct B25_required_alignment) == 1, "record B25 wrong alignment");
_Static_assert(sizeof(struct B25_size) == 130, "record B25 wrong sizeof");
_Static_assert(_Alignof(struct B25_size) == 1, "record B25 wrong alignment");
#endif
_Static_assert(sizeof(B26) == 128, "record B26 wrong sizeof");
_Static_assert(_Alignof(B26) == 128, "record B26 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B26_alignment) == 256, "record B26 wrong sizeof");
_Static_assert(_Alignof(struct B26_alignment) == 128, "record B26 wrong alignment");
_Static_assert(sizeof(struct B26_packed) == 128, "record B26 wrong sizeof");
_Static_assert(_Alignof(struct B26_packed) == 1, "record B26 wrong alignment");
_Static_assert(sizeof(struct B26_required_alignment) == 129, "record B26 wrong sizeof");
_Static_assert(_Alignof(struct B26_required_alignment) == 1, "record B26 wrong alignment");
_Static_assert(sizeof(struct B26_size) == 130, "record B26 wrong sizeof");
_Static_assert(_Alignof(struct B26_size) == 1, "record B26 wrong alignment");
#endif
_Static_assert(sizeof(B27) == 128, "record B27 wrong sizeof");
_Static_assert(_Alignof(B27) == 128, "record B27 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B27_alignment) == 256, "record B27 wrong sizeof");
_Static_assert(_Alignof(struct B27_alignment) == 128, "record B27 wrong alignment");
_Static_assert(sizeof(struct B27_packed) == 128, "record B27 wrong sizeof");
_Static_assert(_Alignof(struct B27_packed) == 1, "record B27 wrong alignment");
_Static_assert(sizeof(struct B27_required_alignment) == 129, "record B27 wrong sizeof");
_Static_assert(_Alignof(struct B27_required_alignment) == 1, "record B27 wrong alignment");
_Static_assert(sizeof(struct B27_size) == 130, "record B27 wrong sizeof");
_Static_assert(_Alignof(struct B27_size) == 1, "record B27 wrong alignment");
#endif
_Static_assert(sizeof(B28) == 128, "record B28 wrong sizeof");
_Static_assert(_Alignof(B28) == 128, "record B28 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B28_alignment) == 256, "record B28 wrong sizeof");
_Static_assert(_Alignof(struct B28_alignment) == 128, "record B28 wrong alignment");
_Static_assert(sizeof(struct B28_packed) == 128, "record B28 wrong sizeof");
_Static_assert(_Alignof(struct B28_packed) == 1, "record B28 wrong alignment");
_Static_assert(sizeof(struct B28_required_alignment) == 129, "record B28 wrong sizeof");
_Static_assert(_Alignof(struct B28_required_alignment) == 1, "record B28 wrong alignment");
_Static_assert(sizeof(struct B28_size) == 130, "record B28 wrong sizeof");
_Static_assert(_Alignof(struct B28_size) == 1, "record B28 wrong alignment");
#endif
_Static_assert(sizeof(B29) == 128, "record B29 wrong sizeof");
_Static_assert(_Alignof(B29) == 128, "record B29 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B29_alignment) == 256, "record B29 wrong sizeof");
_Static_assert(_Alignof(struct B29_alignment) == 128, "record B29 wrong alignment");
_Static_assert(sizeof(struct B29_packed) == 128, "record B29 wrong sizeof");
_Static_assert(_Alignof(struct B29_packed) == 1, "record B29 wrong alignment");
_Static_assert(sizeof(struct B29_required_alignment) == 129, "record B29 wrong sizeof");
_Static_assert(_Alignof(struct B29_required_alignment) == 1, "record B29 wrong alignment");
_Static_assert(sizeof(struct B29_size) == 130, "record B29 wrong sizeof");
_Static_assert(_Alignof(struct B29_size) == 1, "record B29 wrong alignment");
#endif
_Static_assert(sizeof(B30) == 128, "record B30 wrong sizeof");
_Static_assert(_Alignof(B30) == 128, "record B30 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B30_alignment) == 256, "record B30 wrong sizeof");
_Static_assert(_Alignof(struct B30_alignment) == 128, "record B30 wrong alignment");
_Static_assert(sizeof(struct B30_packed) == 128, "record B30 wrong sizeof");
_Static_assert(_Alignof(struct B30_packed) == 1, "record B30 wrong alignment");
_Static_assert(sizeof(struct B30_required_alignment) == 129, "record B30 wrong sizeof");
_Static_assert(_Alignof(struct B30_required_alignment) == 1, "record B30 wrong alignment");
_Static_assert(sizeof(struct B30_size) == 130, "record B30 wrong sizeof");
_Static_assert(_Alignof(struct B30_size) == 1, "record B30 wrong alignment");
#endif
_Static_assert(sizeof(B31) == 128, "record B31 wrong sizeof");
_Static_assert(_Alignof(B31) == 128, "record B31 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B31_alignment) == 256, "record B31 wrong sizeof");
_Static_assert(_Alignof(struct B31_alignment) == 128, "record B31 wrong alignment");
_Static_assert(sizeof(struct B31_packed) == 128, "record B31 wrong sizeof");
_Static_assert(_Alignof(struct B31_packed) == 1, "record B31 wrong alignment");
_Static_assert(sizeof(struct B31_required_alignment) == 129, "record B31 wrong sizeof");
_Static_assert(_Alignof(struct B31_required_alignment) == 1, "record B31 wrong alignment");
_Static_assert(sizeof(struct B31_size) == 130, "record B31 wrong sizeof");
_Static_assert(_Alignof(struct B31_size) == 1, "record B31 wrong alignment");
#endif
_Static_assert(sizeof(B32) == 128, "record B32 wrong sizeof");
_Static_assert(_Alignof(B32) == 128, "record B32 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B32_alignment) == 256, "record B32 wrong sizeof");
_Static_assert(_Alignof(struct B32_alignment) == 128, "record B32 wrong alignment");
_Static_assert(sizeof(struct B32_packed) == 128, "record B32 wrong sizeof");
_Static_assert(_Alignof(struct B32_packed) == 1, "record B32 wrong alignment");
_Static_assert(sizeof(struct B32_required_alignment) == 129, "record B32 wrong sizeof");
_Static_assert(_Alignof(struct B32_required_alignment) == 1, "record B32 wrong alignment");
_Static_assert(sizeof(struct B32_size) == 130, "record B32 wrong sizeof");
_Static_assert(_Alignof(struct B32_size) == 1, "record B32 wrong alignment");
#endif
_Static_assert(sizeof(B33) == 128, "record B33 wrong sizeof");
_Static_assert(_Alignof(B33) == 128, "record B33 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B33_alignment) == 256, "record B33 wrong sizeof");
_Static_assert(_Alignof(struct B33_alignment) == 128, "record B33 wrong alignment");
_Static_assert(sizeof(struct B33_packed) == 128, "record B33 wrong sizeof");
_Static_assert(_Alignof(struct B33_packed) == 1, "record B33 wrong alignment");
_Static_assert(sizeof(struct B33_required_alignment) == 129, "record B33 wrong sizeof");
_Static_assert(_Alignof(struct B33_required_alignment) == 1, "record B33 wrong alignment");
_Static_assert(sizeof(struct B33_size) == 130, "record B33 wrong sizeof");
_Static_assert(_Alignof(struct B33_size) == 1, "record B33 wrong alignment");
#endif
_Static_assert(sizeof(B34) == 128, "record B34 wrong sizeof");
_Static_assert(_Alignof(B34) == 128, "record B34 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B34_alignment) == 256, "record B34 wrong sizeof");
_Static_assert(_Alignof(struct B34_alignment) == 128, "record B34 wrong alignment");
_Static_assert(sizeof(struct B34_packed) == 128, "record B34 wrong sizeof");
_Static_assert(_Alignof(struct B34_packed) == 1, "record B34 wrong alignment");
_Static_assert(sizeof(struct B34_required_alignment) == 129, "record B34 wrong sizeof");
_Static_assert(_Alignof(struct B34_required_alignment) == 1, "record B34 wrong alignment");
_Static_assert(sizeof(struct B34_size) == 130, "record B34 wrong sizeof");
_Static_assert(_Alignof(struct B34_size) == 1, "record B34 wrong alignment");
#endif
_Static_assert(sizeof(B35) == 128, "record B35 wrong sizeof");
_Static_assert(_Alignof(B35) == 128, "record B35 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B35_alignment) == 256, "record B35 wrong sizeof");
_Static_assert(_Alignof(struct B35_alignment) == 128, "record B35 wrong alignment");
_Static_assert(sizeof(struct B35_packed) == 128, "record B35 wrong sizeof");
_Static_assert(_Alignof(struct B35_packed) == 1, "record B35 wrong alignment");
_Static_assert(sizeof(struct B35_required_alignment) == 129, "record B35 wrong sizeof");
_Static_assert(_Alignof(struct B35_required_alignment) == 1, "record B35 wrong alignment");
_Static_assert(sizeof(struct B35_size) == 130, "record B35 wrong sizeof");
_Static_assert(_Alignof(struct B35_size) == 1, "record B35 wrong alignment");
#endif
_Static_assert(sizeof(B36) == 128, "record B36 wrong sizeof");
_Static_assert(_Alignof(B36) == 128, "record B36 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B36_alignment) == 256, "record B36 wrong sizeof");
_Static_assert(_Alignof(struct B36_alignment) == 128, "record B36 wrong alignment");
_Static_assert(sizeof(struct B36_packed) == 128, "record B36 wrong sizeof");
_Static_assert(_Alignof(struct B36_packed) == 1, "record B36 wrong alignment");
_Static_assert(sizeof(struct B36_required_alignment) == 129, "record B36 wrong sizeof");
_Static_assert(_Alignof(struct B36_required_alignment) == 1, "record B36 wrong alignment");
_Static_assert(sizeof(struct B36_size) == 130, "record B36 wrong sizeof");
_Static_assert(_Alignof(struct B36_size) == 1, "record B36 wrong alignment");
#endif
_Static_assert(sizeof(B37) == 128, "record B37 wrong sizeof");
_Static_assert(_Alignof(B37) == 128, "record B37 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B37_alignment) == 256, "record B37 wrong sizeof");
_Static_assert(_Alignof(struct B37_alignment) == 128, "record B37 wrong alignment");
_Static_assert(sizeof(struct B37_packed) == 128, "record B37 wrong sizeof");
_Static_assert(_Alignof(struct B37_packed) == 1, "record B37 wrong alignment");
_Static_assert(sizeof(struct B37_required_alignment) == 129, "record B37 wrong sizeof");
_Static_assert(_Alignof(struct B37_required_alignment) == 1, "record B37 wrong alignment");
_Static_assert(sizeof(struct B37_size) == 130, "record B37 wrong sizeof");
_Static_assert(_Alignof(struct B37_size) == 1, "record B37 wrong alignment");
#endif
_Static_assert(sizeof(B38) == 128, "record B38 wrong sizeof");
_Static_assert(_Alignof(B38) == 128, "record B38 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B38_alignment) == 256, "record B38 wrong sizeof");
_Static_assert(_Alignof(struct B38_alignment) == 128, "record B38 wrong alignment");
_Static_assert(sizeof(struct B38_packed) == 128, "record B38 wrong sizeof");
_Static_assert(_Alignof(struct B38_packed) == 1, "record B38 wrong alignment");
_Static_assert(sizeof(struct B38_required_alignment) == 129, "record B38 wrong sizeof");
_Static_assert(_Alignof(struct B38_required_alignment) == 1, "record B38 wrong alignment");
_Static_assert(sizeof(struct B38_size) == 130, "record B38 wrong sizeof");
_Static_assert(_Alignof(struct B38_size) == 1, "record B38 wrong alignment");
#endif
_Static_assert(sizeof(B39) == 128, "record B39 wrong sizeof");
_Static_assert(_Alignof(B39) == 128, "record B39 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B39_alignment) == 256, "record B39 wrong sizeof");
_Static_assert(_Alignof(struct B39_alignment) == 128, "record B39 wrong alignment");
_Static_assert(sizeof(struct B39_packed) == 128, "record B39 wrong sizeof");
_Static_assert(_Alignof(struct B39_packed) == 1, "record B39 wrong alignment");
_Static_assert(sizeof(struct B39_required_alignment) == 129, "record B39 wrong sizeof");
_Static_assert(_Alignof(struct B39_required_alignment) == 1, "record B39 wrong alignment");
_Static_assert(sizeof(struct B39_size) == 130, "record B39 wrong sizeof");
_Static_assert(_Alignof(struct B39_size) == 1, "record B39 wrong alignment");
#endif
// MAPPING|FIVE|msp430-msp430-other-none:Clang|END
// repr targets Msp430NoneElf|Some("msp430-msp430-other-none") 
#elif defined(FIVE)
_Static_assert(sizeof(A00) == 128, "record A00 wrong sizeof");
_Static_assert(_Alignof(A00) == 128, "record A00 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A00_alignment) == 256, "record A00 wrong sizeof");
_Static_assert(_Alignof(struct A00_alignment) == 128, "record A00 wrong alignment");
_Static_assert(sizeof(struct A00_packed) == 128, "record A00 wrong sizeof");
_Static_assert(_Alignof(struct A00_packed) == 1, "record A00 wrong alignment");
_Static_assert(sizeof(struct A00_required_alignment) == 129, "record A00 wrong sizeof");
_Static_assert(_Alignof(struct A00_required_alignment) == 1, "record A00 wrong alignment");
_Static_assert(sizeof(struct A00_size) == 130, "record A00 wrong sizeof");
_Static_assert(_Alignof(struct A00_size) == 1, "record A00 wrong alignment");
#endif
_Static_assert(sizeof(A01) == 8, "record A01 wrong sizeof");
_Static_assert(_Alignof(A01) == 1, "record A01 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A01_alignment) == 9, "record A01 wrong sizeof");
_Static_assert(_Alignof(struct A01_alignment) == 1, "record A01 wrong alignment");
_Static_assert(sizeof(struct A01_packed) == 8, "record A01 wrong sizeof");
_Static_assert(_Alignof(struct A01_packed) == 1, "record A01 wrong alignment");
_Static_assert(sizeof(struct A01_required_alignment) == 9, "record A01 wrong sizeof");
_Static_assert(_Alignof(struct A01_required_alignment) == 1, "record A01 wrong alignment");
_Static_assert(sizeof(struct A01_size) == 10, "record A01 wrong sizeof");
_Static_assert(_Alignof(struct A01_size) == 1, "record A01 wrong alignment");
#endif
_Static_assert(sizeof(A02) == 8, "record A02 wrong sizeof");
_Static_assert(_Alignof(A02) == 2, "record A02 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A02_alignment) == 10, "record A02 wrong sizeof");
_Static_assert(_Alignof(struct A02_alignment) == 2, "record A02 wrong alignment");
_Static_assert(sizeof(struct A02_packed) == 8, "record A02 wrong sizeof");
_Static_assert(_Alignof(struct A02_packed) == 1, "record A02 wrong alignment");
_Static_assert(sizeof(struct A02_required_alignment) == 9, "record A02 wrong sizeof");
_Static_assert(_Alignof(struct A02_required_alignment) == 1, "record A02 wrong alignment");
_Static_assert(sizeof(struct A02_size) == 10, "record A02 wrong sizeof");
_Static_assert(_Alignof(struct A02_size) == 1, "record A02 wrong alignment");
#endif
_Static_assert(sizeof(A03) == 128, "record A03 wrong sizeof");
_Static_assert(_Alignof(A03) == 128, "record A03 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A03_alignment) == 256, "record A03 wrong sizeof");
_Static_assert(_Alignof(struct A03_alignment) == 128, "record A03 wrong alignment");
_Static_assert(sizeof(struct A03_packed) == 128, "record A03 wrong sizeof");
_Static_assert(_Alignof(struct A03_packed) == 1, "record A03 wrong alignment");
_Static_assert(sizeof(struct A03_required_alignment) == 129, "record A03 wrong sizeof");
_Static_assert(_Alignof(struct A03_required_alignment) == 1, "record A03 wrong alignment");
_Static_assert(sizeof(struct A03_size) == 130, "record A03 wrong sizeof");
_Static_assert(_Alignof(struct A03_size) == 1, "record A03 wrong alignment");
#endif
_Static_assert(sizeof(A04) == 8, "record A04 wrong sizeof");
_Static_assert(_Alignof(A04) == 4, "record A04 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A04_alignment) == 12, "record A04 wrong sizeof");
_Static_assert(_Alignof(struct A04_alignment) == 4, "record A04 wrong alignment");
_Static_assert(sizeof(struct A04_packed) == 8, "record A04 wrong sizeof");
_Static_assert(_Alignof(struct A04_packed) == 1, "record A04 wrong alignment");
_Static_assert(sizeof(struct A04_required_alignment) == 9, "record A04 wrong sizeof");
_Static_assert(_Alignof(struct A04_required_alignment) == 1, "record A04 wrong alignment");
_Static_assert(sizeof(struct A04_size) == 10, "record A04 wrong sizeof");
_Static_assert(_Alignof(struct A04_size) == 1, "record A04 wrong alignment");
#endif
_Static_assert(sizeof(A05) == 128, "record A05 wrong sizeof");
_Static_assert(_Alignof(A05) == 128, "record A05 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A05_alignment) == 256, "record A05 wrong sizeof");
_Static_assert(_Alignof(struct A05_alignment) == 128, "record A05 wrong alignment");
_Static_assert(sizeof(struct A05_packed) == 128, "record A05 wrong sizeof");
_Static_assert(_Alignof(struct A05_packed) == 1, "record A05 wrong alignment");
_Static_assert(sizeof(struct A05_required_alignment) == 129, "record A05 wrong sizeof");
_Static_assert(_Alignof(struct A05_required_alignment) == 1, "record A05 wrong alignment");
_Static_assert(sizeof(struct A05_size) == 130, "record A05 wrong sizeof");
_Static_assert(_Alignof(struct A05_size) == 1, "record A05 wrong alignment");
#endif
_Static_assert(sizeof(A06) == 128, "record A06 wrong sizeof");
_Static_assert(_Alignof(A06) == 128, "record A06 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A06_alignment) == 256, "record A06 wrong sizeof");
_Static_assert(_Alignof(struct A06_alignment) == 128, "record A06 wrong alignment");
_Static_assert(sizeof(struct A06_packed) == 128, "record A06 wrong sizeof");
_Static_assert(_Alignof(struct A06_packed) == 1, "record A06 wrong alignment");
_Static_assert(sizeof(struct A06_required_alignment) == 129, "record A06 wrong sizeof");
_Static_assert(_Alignof(struct A06_required_alignment) == 1, "record A06 wrong alignment");
_Static_assert(sizeof(struct A06_size) == 130, "record A06 wrong sizeof");
_Static_assert(_Alignof(struct A06_size) == 1, "record A06 wrong alignment");
#endif
_Static_assert(sizeof(A07) == 128, "record A07 wrong sizeof");
_Static_assert(_Alignof(A07) == 128, "record A07 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A07_alignment) == 256, "record A07 wrong sizeof");
_Static_assert(_Alignof(struct A07_alignment) == 128, "record A07 wrong alignment");
_Static_assert(sizeof(struct A07_packed) == 128, "record A07 wrong sizeof");
_Static_assert(_Alignof(struct A07_packed) == 1, "record A07 wrong alignment");
_Static_assert(sizeof(struct A07_required_alignment) == 129, "record A07 wrong sizeof");
_Static_assert(_Alignof(struct A07_required_alignment) == 1, "record A07 wrong alignment");
_Static_assert(sizeof(struct A07_size) == 130, "record A07 wrong sizeof");
_Static_assert(_Alignof(struct A07_size) == 1, "record A07 wrong alignment");
#endif
_Static_assert(sizeof(A08) == 8, "record A08 wrong sizeof");
_Static_assert(_Alignof(A08) == 8, "record A08 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A08_alignment) == 16, "record A08 wrong sizeof");
_Static_assert(_Alignof(struct A08_alignment) == 8, "record A08 wrong alignment");
_Static_assert(sizeof(struct A08_packed) == 8, "record A08 wrong sizeof");
_Static_assert(_Alignof(struct A08_packed) == 1, "record A08 wrong alignment");
_Static_assert(sizeof(struct A08_required_alignment) == 9, "record A08 wrong sizeof");
_Static_assert(_Alignof(struct A08_required_alignment) == 1, "record A08 wrong alignment");
_Static_assert(sizeof(struct A08_size) == 10, "record A08 wrong sizeof");
_Static_assert(_Alignof(struct A08_size) == 1, "record A08 wrong alignment");
#endif
_Static_assert(sizeof(A09) == 128, "record A09 wrong sizeof");
_Static_assert(_Alignof(A09) == 128, "record A09 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A09_alignment) == 256, "record A09 wrong sizeof");
_Static_assert(_Alignof(struct A09_alignment) == 128, "record A09 wrong alignment");
_Static_assert(sizeof(struct A09_packed) == 128, "record A09 wrong sizeof");
_Static_assert(_Alignof(struct A09_packed) == 1, "record A09 wrong alignment");
_Static_assert(sizeof(struct A09_required_alignment) == 129, "record A09 wrong sizeof");
_Static_assert(_Alignof(struct A09_required_alignment) == 1, "record A09 wrong alignment");
_Static_assert(sizeof(struct A09_size) == 130, "record A09 wrong sizeof");
_Static_assert(_Alignof(struct A09_size) == 1, "record A09 wrong alignment");
#endif
_Static_assert(sizeof(A10) == 128, "record A10 wrong sizeof");
_Static_assert(_Alignof(A10) == 128, "record A10 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A10_alignment) == 256, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_alignment) == 128, "record A10 wrong alignment");
_Static_assert(sizeof(struct A10_packed) == 128, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_packed) == 1, "record A10 wrong alignment");
_Static_assert(sizeof(struct A10_required_alignment) == 129, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_required_alignment) == 1, "record A10 wrong alignment");
_Static_assert(sizeof(struct A10_size) == 130, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_size) == 1, "record A10 wrong alignment");
#endif
_Static_assert(sizeof(A11) == 128, "record A11 wrong sizeof");
_Static_assert(_Alignof(A11) == 128, "record A11 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A11_alignment) == 256, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_alignment) == 128, "record A11 wrong alignment");
_Static_assert(sizeof(struct A11_packed) == 128, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_packed) == 1, "record A11 wrong alignment");
_Static_assert(sizeof(struct A11_required_alignment) == 129, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_required_alignment) == 1, "record A11 wrong alignment");
_Static_assert(sizeof(struct A11_size) == 130, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_size) == 1, "record A11 wrong alignment");
#endif
_Static_assert(sizeof(A12) == 128, "record A12 wrong sizeof");
_Static_assert(_Alignof(A12) == 128, "record A12 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A12_alignment) == 256, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_alignment) == 128, "record A12 wrong alignment");
_Static_assert(sizeof(struct A12_packed) == 128, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_packed) == 1, "record A12 wrong alignment");
_Static_assert(sizeof(struct A12_required_alignment) == 129, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_required_alignment) == 1, "record A12 wrong alignment");
_Static_assert(sizeof(struct A12_size) == 130, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_size) == 1, "record A12 wrong alignment");
#endif
_Static_assert(sizeof(A13) == 128, "record A13 wrong sizeof");
_Static_assert(_Alignof(A13) == 128, "record A13 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A13_alignment) == 256, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_alignment) == 128, "record A13 wrong alignment");
_Static_assert(sizeof(struct A13_packed) == 128, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_packed) == 1, "record A13 wrong alignment");
_Static_assert(sizeof(struct A13_required_alignment) == 129, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_required_alignment) == 1, "record A13 wrong alignment");
_Static_assert(sizeof(struct A13_size) == 130, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_size) == 1, "record A13 wrong alignment");
#endif
_Static_assert(sizeof(A14) == 128, "record A14 wrong sizeof");
_Static_assert(_Alignof(A14) == 128, "record A14 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A14_alignment) == 256, "record A14 wrong sizeof");
_Static_assert(_Alignof(struct A14_alignment) == 128, "record A14 wrong alignment");
_Static_assert(sizeof(struct A14_packed) == 128, "record A14 wrong sizeof");
_Static_assert(_Alignof(struct A14_packed) == 1, "record A14 wrong alignment");
_Static_assert(sizeof(struct A14_required_alignment) == 129, "record A14 wrong sizeof");
_Static_assert(_Alignof(struct A14_required_alignment) == 1, "record A14 wrong alignment");
_Static_assert(sizeof(struct A14_size) == 130, "record A14 wrong sizeof");
_Static_assert(_Alignof(struct A14_size) == 1, "record A14 wrong alignment");
#endif
_Static_assert(sizeof(A15) == 128, "record A15 wrong sizeof");
_Static_assert(_Alignof(A15) == 128, "record A15 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A15_alignment) == 256, "record A15 wrong sizeof");
_Static_assert(_Alignof(struct A15_alignment) == 128, "record A15 wrong alignment");
_Static_assert(sizeof(struct A15_packed) == 128, "record A15 wrong sizeof");
_Static_assert(_Alignof(struct A15_packed) == 1, "record A15 wrong alignment");
_Static_assert(sizeof(struct A15_required_alignment) == 129, "record A15 wrong sizeof");
_Static_assert(_Alignof(struct A15_required_alignment) == 1, "record A15 wrong alignment");
_Static_assert(sizeof(struct A15_size) == 130, "record A15 wrong sizeof");
_Static_assert(_Alignof(struct A15_size) == 1, "record A15 wrong alignment");
#endif
_Static_assert(sizeof(A16) == 16, "record A16 wrong sizeof");
_Static_assert(_Alignof(A16) == 16, "record A16 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A16_alignment) == 32, "record A16 wrong sizeof");
_Static_assert(_Alignof(struct A16_alignment) == 16, "record A16 wrong alignment");
_Static_assert(sizeof(struct A16_packed) == 16, "record A16 wrong sizeof");
_Static_assert(_Alignof(struct A16_packed) == 1, "record A16 wrong alignment");
_Static_assert(sizeof(struct A16_required_alignment) == 17, "record A16 wrong sizeof");
_Static_assert(_Alignof(struct A16_required_alignment) == 1, "record A16 wrong alignment");
_Static_assert(sizeof(struct A16_size) == 18, "record A16 wrong sizeof");
_Static_assert(_Alignof(struct A16_size) == 1, "record A16 wrong alignment");
#endif
_Static_assert(sizeof(A17) == 128, "record A17 wrong sizeof");
_Static_assert(_Alignof(A17) == 128, "record A17 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A17_alignment) == 256, "record A17 wrong sizeof");
_Static_assert(_Alignof(struct A17_alignment) == 128, "record A17 wrong alignment");
_Static_assert(sizeof(struct A17_packed) == 128, "record A17 wrong sizeof");
_Static_assert(_Alignof(struct A17_packed) == 1, "record A17 wrong alignment");
_Static_assert(sizeof(struct A17_required_alignment) == 129, "record A17 wrong sizeof");
_Static_assert(_Alignof(struct A17_required_alignment) == 1, "record A17 wrong alignment");
_Static_assert(sizeof(struct A17_size) == 130, "record A17 wrong sizeof");
_Static_assert(_Alignof(struct A17_size) == 1, "record A17 wrong alignment");
#endif
_Static_assert(sizeof(A18) == 128, "record A18 wrong sizeof");
_Static_assert(_Alignof(A18) == 128, "record A18 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A18_alignment) == 256, "record A18 wrong sizeof");
_Static_assert(_Alignof(struct A18_alignment) == 128, "record A18 wrong alignment");
_Static_assert(sizeof(struct A18_packed) == 128, "record A18 wrong sizeof");
_Static_assert(_Alignof(struct A18_packed) == 1, "record A18 wrong alignment");
_Static_assert(sizeof(struct A18_required_alignment) == 129, "record A18 wrong sizeof");
_Static_assert(_Alignof(struct A18_required_alignment) == 1, "record A18 wrong alignment");
_Static_assert(sizeof(struct A18_size) == 130, "record A18 wrong sizeof");
_Static_assert(_Alignof(struct A18_size) == 1, "record A18 wrong alignment");
#endif
_Static_assert(sizeof(A19) == 128, "record A19 wrong sizeof");
_Static_assert(_Alignof(A19) == 128, "record A19 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A19_alignment) == 256, "record A19 wrong sizeof");
_Static_assert(_Alignof(struct A19_alignment) == 128, "record A19 wrong alignment");
_Static_assert(sizeof(struct A19_packed) == 128, "record A19 wrong sizeof");
_Static_assert(_Alignof(struct A19_packed) == 1, "record A19 wrong alignment");
_Static_assert(sizeof(struct A19_required_alignment) == 129, "record A19 wrong sizeof");
_Static_assert(_Alignof(struct A19_required_alignment) == 1, "record A19 wrong alignment");
_Static_assert(sizeof(struct A19_size) == 130, "record A19 wrong sizeof");
_Static_assert(_Alignof(struct A19_size) == 1, "record A19 wrong alignment");
#endif
_Static_assert(sizeof(A20) == 128, "record A20 wrong sizeof");
_Static_assert(_Alignof(A20) == 128, "record A20 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A20_alignment) == 256, "record A20 wrong sizeof");
_Static_assert(_Alignof(struct A20_alignment) == 128, "record A20 wrong alignment");
_Static_assert(sizeof(struct A20_packed) == 128, "record A20 wrong sizeof");
_Static_assert(_Alignof(struct A20_packed) == 1, "record A20 wrong alignment");
_Static_assert(sizeof(struct A20_required_alignment) == 129, "record A20 wrong sizeof");
_Static_assert(_Alignof(struct A20_required_alignment) == 1, "record A20 wrong alignment");
_Static_assert(sizeof(struct A20_size) == 130, "record A20 wrong sizeof");
_Static_assert(_Alignof(struct A20_size) == 1, "record A20 wrong alignment");
#endif
_Static_assert(sizeof(A21) == 128, "record A21 wrong sizeof");
_Static_assert(_Alignof(A21) == 128, "record A21 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A21_alignment) == 256, "record A21 wrong sizeof");
_Static_assert(_Alignof(struct A21_alignment) == 128, "record A21 wrong alignment");
_Static_assert(sizeof(struct A21_packed) == 128, "record A21 wrong sizeof");
_Static_assert(_Alignof(struct A21_packed) == 1, "record A21 wrong alignment");
_Static_assert(sizeof(struct A21_required_alignment) == 129, "record A21 wrong sizeof");
_Static_assert(_Alignof(struct A21_required_alignment) == 1, "record A21 wrong alignment");
_Static_assert(sizeof(struct A21_size) == 130, "record A21 wrong sizeof");
_Static_assert(_Alignof(struct A21_size) == 1, "record A21 wrong alignment");
#endif
_Static_assert(sizeof(A22) == 128, "record A22 wrong sizeof");
_Static_assert(_Alignof(A22) == 128, "record A22 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A22_alignment) == 256, "record A22 wrong sizeof");
_Static_assert(_Alignof(struct A22_alignment) == 128, "record A22 wrong alignment");
_Static_assert(sizeof(struct A22_packed) == 128, "record A22 wrong sizeof");
_Static_assert(_Alignof(struct A22_packed) == 1, "record A22 wrong alignment");
_Static_assert(sizeof(struct A22_required_alignment) == 129, "record A22 wrong sizeof");
_Static_assert(_Alignof(struct A22_required_alignment) == 1, "record A22 wrong alignment");
_Static_assert(sizeof(struct A22_size) == 130, "record A22 wrong sizeof");
_Static_assert(_Alignof(struct A22_size) == 1, "record A22 wrong alignment");
#endif
_Static_assert(sizeof(A23) == 128, "record A23 wrong sizeof");
_Static_assert(_Alignof(A23) == 128, "record A23 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A23_alignment) == 256, "record A23 wrong sizeof");
_Static_assert(_Alignof(struct A23_alignment) == 128, "record A23 wrong alignment");
_Static_assert(sizeof(struct A23_packed) == 128, "record A23 wrong sizeof");
_Static_assert(_Alignof(struct A23_packed) == 1, "record A23 wrong alignment");
_Static_assert(sizeof(struct A23_required_alignment) == 129, "record A23 wrong sizeof");
_Static_assert(_Alignof(struct A23_required_alignment) == 1, "record A23 wrong alignment");
_Static_assert(sizeof(struct A23_size) == 130, "record A23 wrong sizeof");
_Static_assert(_Alignof(struct A23_size) == 1, "record A23 wrong alignment");
#endif
_Static_assert(sizeof(A24) == 128, "record A24 wrong sizeof");
_Static_assert(_Alignof(A24) == 128, "record A24 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A24_alignment) == 256, "record A24 wrong sizeof");
_Static_assert(_Alignof(struct A24_alignment) == 128, "record A24 wrong alignment");
_Static_assert(sizeof(struct A24_packed) == 128, "record A24 wrong sizeof");
_Static_assert(_Alignof(struct A24_packed) == 1, "record A24 wrong alignment");
_Static_assert(sizeof(struct A24_required_alignment) == 129, "record A24 wrong sizeof");
_Static_assert(_Alignof(struct A24_required_alignment) == 1, "record A24 wrong alignment");
_Static_assert(sizeof(struct A24_size) == 130, "record A24 wrong sizeof");
_Static_assert(_Alignof(struct A24_size) == 1, "record A24 wrong alignment");
#endif
_Static_assert(sizeof(A25) == 128, "record A25 wrong sizeof");
_Static_assert(_Alignof(A25) == 128, "record A25 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A25_alignment) == 256, "record A25 wrong sizeof");
_Static_assert(_Alignof(struct A25_alignment) == 128, "record A25 wrong alignment");
_Static_assert(sizeof(struct A25_packed) == 128, "record A25 wrong sizeof");
_Static_assert(_Alignof(struct A25_packed) == 1, "record A25 wrong alignment");
_Static_assert(sizeof(struct A25_required_alignment) == 129, "record A25 wrong sizeof");
_Static_assert(_Alignof(struct A25_required_alignment) == 1, "record A25 wrong alignment");
_Static_assert(sizeof(struct A25_size) == 130, "record A25 wrong sizeof");
_Static_assert(_Alignof(struct A25_size) == 1, "record A25 wrong alignment");
#endif
_Static_assert(sizeof(A26) == 128, "record A26 wrong sizeof");
_Static_assert(_Alignof(A26) == 128, "record A26 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A26_alignment) == 256, "record A26 wrong sizeof");
_Static_assert(_Alignof(struct A26_alignment) == 128, "record A26 wrong alignment");
_Static_assert(sizeof(struct A26_packed) == 128, "record A26 wrong sizeof");
_Static_assert(_Alignof(struct A26_packed) == 1, "record A26 wrong alignment");
_Static_assert(sizeof(struct A26_required_alignment) == 129, "record A26 wrong sizeof");
_Static_assert(_Alignof(struct A26_required_alignment) == 1, "record A26 wrong alignment");
_Static_assert(sizeof(struct A26_size) == 130, "record A26 wrong sizeof");
_Static_assert(_Alignof(struct A26_size) == 1, "record A26 wrong alignment");
#endif
_Static_assert(sizeof(A27) == 128, "record A27 wrong sizeof");
_Static_assert(_Alignof(A27) == 128, "record A27 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A27_alignment) == 256, "record A27 wrong sizeof");
_Static_assert(_Alignof(struct A27_alignment) == 128, "record A27 wrong alignment");
_Static_assert(sizeof(struct A27_packed) == 128, "record A27 wrong sizeof");
_Static_assert(_Alignof(struct A27_packed) == 1, "record A27 wrong alignment");
_Static_assert(sizeof(struct A27_required_alignment) == 129, "record A27 wrong sizeof");
_Static_assert(_Alignof(struct A27_required_alignment) == 1, "record A27 wrong alignment");
_Static_assert(sizeof(struct A27_size) == 130, "record A27 wrong sizeof");
_Static_assert(_Alignof(struct A27_size) == 1, "record A27 wrong alignment");
#endif
_Static_assert(sizeof(A28) == 128, "record A28 wrong sizeof");
_Static_assert(_Alignof(A28) == 128, "record A28 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A28_alignment) == 256, "record A28 wrong sizeof");
_Static_assert(_Alignof(struct A28_alignment) == 128, "record A28 wrong alignment");
_Static_assert(sizeof(struct A28_packed) == 128, "record A28 wrong sizeof");
_Static_assert(_Alignof(struct A28_packed) == 1, "record A28 wrong alignment");
_Static_assert(sizeof(struct A28_required_alignment) == 129, "record A28 wrong sizeof");
_Static_assert(_Alignof(struct A28_required_alignment) == 1, "record A28 wrong alignment");
_Static_assert(sizeof(struct A28_size) == 130, "record A28 wrong sizeof");
_Static_assert(_Alignof(struct A28_size) == 1, "record A28 wrong alignment");
#endif
_Static_assert(sizeof(A29) == 128, "record A29 wrong sizeof");
_Static_assert(_Alignof(A29) == 128, "record A29 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A29_alignment) == 256, "record A29 wrong sizeof");
_Static_assert(_Alignof(struct A29_alignment) == 128, "record A29 wrong alignment");
_Static_assert(sizeof(struct A29_packed) == 128, "record A29 wrong sizeof");
_Static_assert(_Alignof(struct A29_packed) == 1, "record A29 wrong alignment");
_Static_assert(sizeof(struct A29_required_alignment) == 129, "record A29 wrong sizeof");
_Static_assert(_Alignof(struct A29_required_alignment) == 1, "record A29 wrong alignment");
_Static_assert(sizeof(struct A29_size) == 130, "record A29 wrong sizeof");
_Static_assert(_Alignof(struct A29_size) == 1, "record A29 wrong alignment");
#endif
_Static_assert(sizeof(A30) == 128, "record A30 wrong sizeof");
_Static_assert(_Alignof(A30) == 128, "record A30 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A30_alignment) == 256, "record A30 wrong sizeof");
_Static_assert(_Alignof(struct A30_alignment) == 128, "record A30 wrong alignment");
_Static_assert(sizeof(struct A30_packed) == 128, "record A30 wrong sizeof");
_Static_assert(_Alignof(struct A30_packed) == 1, "record A30 wrong alignment");
_Static_assert(sizeof(struct A30_required_alignment) == 129, "record A30 wrong sizeof");
_Static_assert(_Alignof(struct A30_required_alignment) == 1, "record A30 wrong alignment");
_Static_assert(sizeof(struct A30_size) == 130, "record A30 wrong sizeof");
_Static_assert(_Alignof(struct A30_size) == 1, "record A30 wrong alignment");
#endif
_Static_assert(sizeof(A31) == 128, "record A31 wrong sizeof");
_Static_assert(_Alignof(A31) == 128, "record A31 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A31_alignment) == 256, "record A31 wrong sizeof");
_Static_assert(_Alignof(struct A31_alignment) == 128, "record A31 wrong alignment");
_Static_assert(sizeof(struct A31_packed) == 128, "record A31 wrong sizeof");
_Static_assert(_Alignof(struct A31_packed) == 1, "record A31 wrong alignment");
_Static_assert(sizeof(struct A31_required_alignment) == 129, "record A31 wrong sizeof");
_Static_assert(_Alignof(struct A31_required_alignment) == 1, "record A31 wrong alignment");
_Static_assert(sizeof(struct A31_size) == 130, "record A31 wrong sizeof");
_Static_assert(_Alignof(struct A31_size) == 1, "record A31 wrong alignment");
#endif
_Static_assert(sizeof(A32) == 128, "record A32 wrong sizeof");
_Static_assert(_Alignof(A32) == 128, "record A32 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A32_alignment) == 256, "record A32 wrong sizeof");
_Static_assert(_Alignof(struct A32_alignment) == 128, "record A32 wrong alignment");
_Static_assert(sizeof(struct A32_packed) == 128, "record A32 wrong sizeof");
_Static_assert(_Alignof(struct A32_packed) == 1, "record A32 wrong alignment");
_Static_assert(sizeof(struct A32_required_alignment) == 129, "record A32 wrong sizeof");
_Static_assert(_Alignof(struct A32_required_alignment) == 1, "record A32 wrong alignment");
_Static_assert(sizeof(struct A32_size) == 130, "record A32 wrong sizeof");
_Static_assert(_Alignof(struct A32_size) == 1, "record A32 wrong alignment");
#endif
_Static_assert(sizeof(A33) == 128, "record A33 wrong sizeof");
_Static_assert(_Alignof(A33) == 128, "record A33 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A33_alignment) == 256, "record A33 wrong sizeof");
_Static_assert(_Alignof(struct A33_alignment) == 128, "record A33 wrong alignment");
_Static_assert(sizeof(struct A33_packed) == 128, "record A33 wrong sizeof");
_Static_assert(_Alignof(struct A33_packed) == 1, "record A33 wrong alignment");
_Static_assert(sizeof(struct A33_required_alignment) == 129, "record A33 wrong sizeof");
_Static_assert(_Alignof(struct A33_required_alignment) == 1, "record A33 wrong alignment");
_Static_assert(sizeof(struct A33_size) == 130, "record A33 wrong sizeof");
_Static_assert(_Alignof(struct A33_size) == 1, "record A33 wrong alignment");
#endif
_Static_assert(sizeof(A34) == 128, "record A34 wrong sizeof");
_Static_assert(_Alignof(A34) == 128, "record A34 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A34_alignment) == 256, "record A34 wrong sizeof");
_Static_assert(_Alignof(struct A34_alignment) == 128, "record A34 wrong alignment");
_Static_assert(sizeof(struct A34_packed) == 128, "record A34 wrong sizeof");
_Static_assert(_Alignof(struct A34_packed) == 1, "record A34 wrong alignment");
_Static_assert(sizeof(struct A34_required_alignment) == 129, "record A34 wrong sizeof");
_Static_assert(_Alignof(struct A34_required_alignment) == 1, "record A34 wrong alignment");
_Static_assert(sizeof(struct A34_size) == 130, "record A34 wrong sizeof");
_Static_assert(_Alignof(struct A34_size) == 1, "record A34 wrong alignment");
#endif
_Static_assert(sizeof(A35) == 128, "record A35 wrong sizeof");
_Static_assert(_Alignof(A35) == 128, "record A35 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A35_alignment) == 256, "record A35 wrong sizeof");
_Static_assert(_Alignof(struct A35_alignment) == 128, "record A35 wrong alignment");
_Static_assert(sizeof(struct A35_packed) == 128, "record A35 wrong sizeof");
_Static_assert(_Alignof(struct A35_packed) == 1, "record A35 wrong alignment");
_Static_assert(sizeof(struct A35_required_alignment) == 129, "record A35 wrong sizeof");
_Static_assert(_Alignof(struct A35_required_alignment) == 1, "record A35 wrong alignment");
_Static_assert(sizeof(struct A35_size) == 130, "record A35 wrong sizeof");
_Static_assert(_Alignof(struct A35_size) == 1, "record A35 wrong alignment");
#endif
_Static_assert(sizeof(A36) == 128, "record A36 wrong sizeof");
_Static_assert(_Alignof(A36) == 128, "record A36 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A36_alignment) == 256, "record A36 wrong sizeof");
_Static_assert(_Alignof(struct A36_alignment) == 128, "record A36 wrong alignment");
_Static_assert(sizeof(struct A36_packed) == 128, "record A36 wrong sizeof");
_Static_assert(_Alignof(struct A36_packed) == 1, "record A36 wrong alignment");
_Static_assert(sizeof(struct A36_required_alignment) == 129, "record A36 wrong sizeof");
_Static_assert(_Alignof(struct A36_required_alignment) == 1, "record A36 wrong alignment");
_Static_assert(sizeof(struct A36_size) == 130, "record A36 wrong sizeof");
_Static_assert(_Alignof(struct A36_size) == 1, "record A36 wrong alignment");
#endif
_Static_assert(sizeof(A37) == 128, "record A37 wrong sizeof");
_Static_assert(_Alignof(A37) == 128, "record A37 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A37_alignment) == 256, "record A37 wrong sizeof");
_Static_assert(_Alignof(struct A37_alignment) == 128, "record A37 wrong alignment");
_Static_assert(sizeof(struct A37_packed) == 128, "record A37 wrong sizeof");
_Static_assert(_Alignof(struct A37_packed) == 1, "record A37 wrong alignment");
_Static_assert(sizeof(struct A37_required_alignment) == 129, "record A37 wrong sizeof");
_Static_assert(_Alignof(struct A37_required_alignment) == 1, "record A37 wrong alignment");
_Static_assert(sizeof(struct A37_size) == 130, "record A37 wrong sizeof");
_Static_assert(_Alignof(struct A37_size) == 1, "record A37 wrong alignment");
#endif
_Static_assert(sizeof(A38) == 128, "record A38 wrong sizeof");
_Static_assert(_Alignof(A38) == 128, "record A38 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A38_alignment) == 256, "record A38 wrong sizeof");
_Static_assert(_Alignof(struct A38_alignment) == 128, "record A38 wrong alignment");
_Static_assert(sizeof(struct A38_packed) == 128, "record A38 wrong sizeof");
_Static_assert(_Alignof(struct A38_packed) == 1, "record A38 wrong alignment");
_Static_assert(sizeof(struct A38_required_alignment) == 129, "record A38 wrong sizeof");
_Static_assert(_Alignof(struct A38_required_alignment) == 1, "record A38 wrong alignment");
_Static_assert(sizeof(struct A38_size) == 130, "record A38 wrong sizeof");
_Static_assert(_Alignof(struct A38_size) == 1, "record A38 wrong alignment");
#endif
_Static_assert(sizeof(A39) == 128, "record A39 wrong sizeof");
_Static_assert(_Alignof(A39) == 128, "record A39 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A39_alignment) == 256, "record A39 wrong sizeof");
_Static_assert(_Alignof(struct A39_alignment) == 128, "record A39 wrong alignment");
_Static_assert(sizeof(struct A39_packed) == 128, "record A39 wrong sizeof");
_Static_assert(_Alignof(struct A39_packed) == 1, "record A39 wrong alignment");
_Static_assert(sizeof(struct A39_required_alignment) == 129, "record A39 wrong sizeof");
_Static_assert(_Alignof(struct A39_required_alignment) == 1, "record A39 wrong alignment");
_Static_assert(sizeof(struct A39_size) == 130, "record A39 wrong sizeof");
_Static_assert(_Alignof(struct A39_size) == 1, "record A39 wrong alignment");
#endif
_Static_assert(sizeof(B00) == 128, "record B00 wrong sizeof");
_Static_assert(_Alignof(B00) == 128, "record B00 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B00_alignment) == 256, "record B00 wrong sizeof");
_Static_assert(_Alignof(struct B00_alignment) == 128, "record B00 wrong alignment");
_Static_assert(sizeof(struct B00_packed) == 128, "record B00 wrong sizeof");
_Static_assert(_Alignof(struct B00_packed) == 1, "record B00 wrong alignment");
_Static_assert(sizeof(struct B00_required_alignment) == 129, "record B00 wrong sizeof");
_Static_assert(_Alignof(struct B00_required_alignment) == 1, "record B00 wrong alignment");
_Static_assert(sizeof(struct B00_size) == 130, "record B00 wrong sizeof");
_Static_assert(_Alignof(struct B00_size) == 1, "record B00 wrong alignment");
#endif
_Static_assert(sizeof(B01) == 8, "record B01 wrong sizeof");
_Static_assert(_Alignof(B01) == 1, "record B01 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B01_alignment) == 9, "record B01 wrong sizeof");
_Static_assert(_Alignof(struct B01_alignment) == 1, "record B01 wrong alignment");
_Static_assert(sizeof(struct B01_packed) == 8, "record B01 wrong sizeof");
_Static_assert(_Alignof(struct B01_packed) == 1, "record B01 wrong alignment");
_Static_assert(sizeof(struct B01_required_alignment) == 9, "record B01 wrong sizeof");
_Static_assert(_Alignof(struct B01_required_alignment) == 1, "record B01 wrong alignment");
_Static_assert(sizeof(struct B01_size) == 10, "record B01 wrong sizeof");
_Static_assert(_Alignof(struct B01_size) == 1, "record B01 wrong alignment");
#endif
_Static_assert(sizeof(B02) == 8, "record B02 wrong sizeof");
_Static_assert(_Alignof(B02) == 2, "record B02 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B02_alignment) == 10, "record B02 wrong sizeof");
_Static_assert(_Alignof(struct B02_alignment) == 2, "record B02 wrong alignment");
_Static_assert(sizeof(struct B02_packed) == 8, "record B02 wrong sizeof");
_Static_assert(_Alignof(struct B02_packed) == 1, "record B02 wrong alignment");
_Static_assert(sizeof(struct B02_required_alignment) == 9, "record B02 wrong sizeof");
_Static_assert(_Alignof(struct B02_required_alignment) == 1, "record B02 wrong alignment");
_Static_assert(sizeof(struct B02_size) == 10, "record B02 wrong sizeof");
_Static_assert(_Alignof(struct B02_size) == 1, "record B02 wrong alignment");
#endif
_Static_assert(sizeof(B03) == 128, "record B03 wrong sizeof");
_Static_assert(_Alignof(B03) == 128, "record B03 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B03_alignment) == 256, "record B03 wrong sizeof");
_Static_assert(_Alignof(struct B03_alignment) == 128, "record B03 wrong alignment");
_Static_assert(sizeof(struct B03_packed) == 128, "record B03 wrong sizeof");
_Static_assert(_Alignof(struct B03_packed) == 1, "record B03 wrong alignment");
_Static_assert(sizeof(struct B03_required_alignment) == 129, "record B03 wrong sizeof");
_Static_assert(_Alignof(struct B03_required_alignment) == 1, "record B03 wrong alignment");
_Static_assert(sizeof(struct B03_size) == 130, "record B03 wrong sizeof");
_Static_assert(_Alignof(struct B03_size) == 1, "record B03 wrong alignment");
#endif
_Static_assert(sizeof(B04) == 8, "record B04 wrong sizeof");
_Static_assert(_Alignof(B04) == 4, "record B04 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B04_alignment) == 12, "record B04 wrong sizeof");
_Static_assert(_Alignof(struct B04_alignment) == 4, "record B04 wrong alignment");
_Static_assert(sizeof(struct B04_packed) == 8, "record B04 wrong sizeof");
_Static_assert(_Alignof(struct B04_packed) == 1, "record B04 wrong alignment");
_Static_assert(sizeof(struct B04_required_alignment) == 9, "record B04 wrong sizeof");
_Static_assert(_Alignof(struct B04_required_alignment) == 1, "record B04 wrong alignment");
_Static_assert(sizeof(struct B04_size) == 10, "record B04 wrong sizeof");
_Static_assert(_Alignof(struct B04_size) == 1, "record B04 wrong alignment");
#endif
_Static_assert(sizeof(B05) == 128, "record B05 wrong sizeof");
_Static_assert(_Alignof(B05) == 128, "record B05 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B05_alignment) == 256, "record B05 wrong sizeof");
_Static_assert(_Alignof(struct B05_alignment) == 128, "record B05 wrong alignment");
_Static_assert(sizeof(struct B05_packed) == 128, "record B05 wrong sizeof");
_Static_assert(_Alignof(struct B05_packed) == 1, "record B05 wrong alignment");
_Static_assert(sizeof(struct B05_required_alignment) == 129, "record B05 wrong sizeof");
_Static_assert(_Alignof(struct B05_required_alignment) == 1, "record B05 wrong alignment");
_Static_assert(sizeof(struct B05_size) == 130, "record B05 wrong sizeof");
_Static_assert(_Alignof(struct B05_size) == 1, "record B05 wrong alignment");
#endif
_Static_assert(sizeof(B06) == 128, "record B06 wrong sizeof");
_Static_assert(_Alignof(B06) == 128, "record B06 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B06_alignment) == 256, "record B06 wrong sizeof");
_Static_assert(_Alignof(struct B06_alignment) == 128, "record B06 wrong alignment");
_Static_assert(sizeof(struct B06_packed) == 128, "record B06 wrong sizeof");
_Static_assert(_Alignof(struct B06_packed) == 1, "record B06 wrong alignment");
_Static_assert(sizeof(struct B06_required_alignment) == 129, "record B06 wrong sizeof");
_Static_assert(_Alignof(struct B06_required_alignment) == 1, "record B06 wrong alignment");
_Static_assert(sizeof(struct B06_size) == 130, "record B06 wrong sizeof");
_Static_assert(_Alignof(struct B06_size) == 1, "record B06 wrong alignment");
#endif
_Static_assert(sizeof(B07) == 128, "record B07 wrong sizeof");
_Static_assert(_Alignof(B07) == 128, "record B07 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B07_alignment) == 256, "record B07 wrong sizeof");
_Static_assert(_Alignof(struct B07_alignment) == 128, "record B07 wrong alignment");
_Static_assert(sizeof(struct B07_packed) == 128, "record B07 wrong sizeof");
_Static_assert(_Alignof(struct B07_packed) == 1, "record B07 wrong alignment");
_Static_assert(sizeof(struct B07_required_alignment) == 129, "record B07 wrong sizeof");
_Static_assert(_Alignof(struct B07_required_alignment) == 1, "record B07 wrong alignment");
_Static_assert(sizeof(struct B07_size) == 130, "record B07 wrong sizeof");
_Static_assert(_Alignof(struct B07_size) == 1, "record B07 wrong alignment");
#endif
_Static_assert(sizeof(B08) == 8, "record B08 wrong sizeof");
_Static_assert(_Alignof(B08) == 8, "record B08 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B08_alignment) == 16, "record B08 wrong sizeof");
_Static_assert(_Alignof(struct B08_alignment) == 8, "record B08 wrong alignment");
_Static_assert(sizeof(struct B08_packed) == 8, "record B08 wrong sizeof");
_Static_assert(_Alignof(struct B08_packed) == 1, "record B08 wrong alignment");
_Static_assert(sizeof(struct B08_required_alignment) == 9, "record B08 wrong sizeof");
_Static_assert(_Alignof(struct B08_required_alignment) == 1, "record B08 wrong alignment");
_Static_assert(sizeof(struct B08_size) == 10, "record B08 wrong sizeof");
_Static_assert(_Alignof(struct B08_size) == 1, "record B08 wrong alignment");
#endif
_Static_assert(sizeof(B09) == 128, "record B09 wrong sizeof");
_Static_assert(_Alignof(B09) == 128, "record B09 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B09_alignment) == 256, "record B09 wrong sizeof");
_Static_assert(_Alignof(struct B09_alignment) == 128, "record B09 wrong alignment");
_Static_assert(sizeof(struct B09_packed) == 128, "record B09 wrong sizeof");
_Static_assert(_Alignof(struct B09_packed) == 1, "record B09 wrong alignment");
_Static_assert(sizeof(struct B09_required_alignment) == 129, "record B09 wrong sizeof");
_Static_assert(_Alignof(struct B09_required_alignment) == 1, "record B09 wrong alignment");
_Static_assert(sizeof(struct B09_size) == 130, "record B09 wrong sizeof");
_Static_assert(_Alignof(struct B09_size) == 1, "record B09 wrong alignment");
#endif
_Static_assert(sizeof(B10) == 128, "record B10 wrong sizeof");
_Static_assert(_Alignof(B10) == 128, "record B10 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B10_alignment) == 256, "record B10 wrong sizeof");
_Static_assert(_Alignof(struct B10_alignment) == 128, "record B10 wrong alignment");
_Static_assert(sizeof(struct B10_packed) == 128, "record B10 wrong sizeof");
_Static_assert(_Alignof(struct B10_packed) == 1, "record B10 wrong alignment");
_Static_assert(sizeof(struct B10_required_alignment) == 129, "record B10 wrong sizeof");
_Static_assert(_Alignof(struct B10_required_alignment) == 1, "record B10 wrong alignment");
_Static_assert(sizeof(struct B10_size) == 130, "record B10 wrong sizeof");
_Static_assert(_Alignof(struct B10_size) == 1, "record B10 wrong alignment");
#endif
_Static_assert(sizeof(B11) == 128, "record B11 wrong sizeof");
_Static_assert(_Alignof(B11) == 128, "record B11 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B11_alignment) == 256, "record B11 wrong sizeof");
_Static_assert(_Alignof(struct B11_alignment) == 128, "record B11 wrong alignment");
_Static_assert(sizeof(struct B11_packed) == 128, "record B11 wrong sizeof");
_Static_assert(_Alignof(struct B11_packed) == 1, "record B11 wrong alignment");
_Static_assert(sizeof(struct B11_required_alignment) == 129, "record B11 wrong sizeof");
_Static_assert(_Alignof(struct B11_required_alignment) == 1, "record B11 wrong alignment");
_Static_assert(sizeof(struct B11_size) == 130, "record B11 wrong sizeof");
_Static_assert(_Alignof(struct B11_size) == 1, "record B11 wrong alignment");
#endif
_Static_assert(sizeof(B12) == 128, "record B12 wrong sizeof");
_Static_assert(_Alignof(B12) == 128, "record B12 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B12_alignment) == 256, "record B12 wrong sizeof");
_Static_assert(_Alignof(struct B12_alignment) == 128, "record B12 wrong alignment");
_Static_assert(sizeof(struct B12_packed) == 128, "record B12 wrong sizeof");
_Static_assert(_Alignof(struct B12_packed) == 1, "record B12 wrong alignment");
_Static_assert(sizeof(struct B12_required_alignment) == 129, "record B12 wrong sizeof");
_Static_assert(_Alignof(struct B12_required_alignment) == 1, "record B12 wrong alignment");
_Static_assert(sizeof(struct B12_size) == 130, "record B12 wrong sizeof");
_Static_assert(_Alignof(struct B12_size) == 1, "record B12 wrong alignment");
#endif
_Static_assert(sizeof(B13) == 128, "record B13 wrong sizeof");
_Static_assert(_Alignof(B13) == 128, "record B13 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B13_alignment) == 256, "record B13 wrong sizeof");
_Static_assert(_Alignof(struct B13_alignment) == 128, "record B13 wrong alignment");
_Static_assert(sizeof(struct B13_packed) == 128, "record B13 wrong sizeof");
_Static_assert(_Alignof(struct B13_packed) == 1, "record B13 wrong alignment");
_Static_assert(sizeof(struct B13_required_alignment) == 129, "record B13 wrong sizeof");
_Static_assert(_Alignof(struct B13_required_alignment) == 1, "record B13 wrong alignment");
_Static_assert(sizeof(struct B13_size) == 130, "record B13 wrong sizeof");
_Static_assert(_Alignof(struct B13_size) == 1, "record B13 wrong alignment");
#endif
_Static_assert(sizeof(B14) == 128, "record B14 wrong sizeof");
_Static_assert(_Alignof(B14) == 128, "record B14 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B14_alignment) == 256, "record B14 wrong sizeof");
_Static_assert(_Alignof(struct B14_alignment) == 128, "record B14 wrong alignment");
_Static_assert(sizeof(struct B14_packed) == 128, "record B14 wrong sizeof");
_Static_assert(_Alignof(struct B14_packed) == 1, "record B14 wrong alignment");
_Static_assert(sizeof(struct B14_required_alignment) == 129, "record B14 wrong sizeof");
_Static_assert(_Alignof(struct B14_required_alignment) == 1, "record B14 wrong alignment");
_Static_assert(sizeof(struct B14_size) == 130, "record B14 wrong sizeof");
_Static_assert(_Alignof(struct B14_size) == 1, "record B14 wrong alignment");
#endif
_Static_assert(sizeof(B15) == 128, "record B15 wrong sizeof");
_Static_assert(_Alignof(B15) == 128, "record B15 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B15_alignment) == 256, "record B15 wrong sizeof");
_Static_assert(_Alignof(struct B15_alignment) == 128, "record B15 wrong alignment");
_Static_assert(sizeof(struct B15_packed) == 128, "record B15 wrong sizeof");
_Static_assert(_Alignof(struct B15_packed) == 1, "record B15 wrong alignment");
_Static_assert(sizeof(struct B15_required_alignment) == 129, "record B15 wrong sizeof");
_Static_assert(_Alignof(struct B15_required_alignment) == 1, "record B15 wrong alignment");
_Static_assert(sizeof(struct B15_size) == 130, "record B15 wrong sizeof");
_Static_assert(_Alignof(struct B15_size) == 1, "record B15 wrong alignment");
#endif
_Static_assert(sizeof(B16) == 16, "record B16 wrong sizeof");
_Static_assert(_Alignof(B16) == 16, "record B16 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B16_alignment) == 32, "record B16 wrong sizeof");
_Static_assert(_Alignof(struct B16_alignment) == 16, "record B16 wrong alignment");
_Static_assert(sizeof(struct B16_packed) == 16, "record B16 wrong sizeof");
_Static_assert(_Alignof(struct B16_packed) == 1, "record B16 wrong alignment");
_Static_assert(sizeof(struct B16_required_alignment) == 17, "record B16 wrong sizeof");
_Static_assert(_Alignof(struct B16_required_alignment) == 1, "record B16 wrong alignment");
_Static_assert(sizeof(struct B16_size) == 18, "record B16 wrong sizeof");
_Static_assert(_Alignof(struct B16_size) == 1, "record B16 wrong alignment");
#endif
_Static_assert(sizeof(B17) == 128, "record B17 wrong sizeof");
_Static_assert(_Alignof(B17) == 128, "record B17 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B17_alignment) == 256, "record B17 wrong sizeof");
_Static_assert(_Alignof(struct B17_alignment) == 128, "record B17 wrong alignment");
_Static_assert(sizeof(struct B17_packed) == 128, "record B17 wrong sizeof");
_Static_assert(_Alignof(struct B17_packed) == 1, "record B17 wrong alignment");
_Static_assert(sizeof(struct B17_required_alignment) == 129, "record B17 wrong sizeof");
_Static_assert(_Alignof(struct B17_required_alignment) == 1, "record B17 wrong alignment");
_Static_assert(sizeof(struct B17_size) == 130, "record B17 wrong sizeof");
_Static_assert(_Alignof(struct B17_size) == 1, "record B17 wrong alignment");
#endif
_Static_assert(sizeof(B18) == 128, "record B18 wrong sizeof");
_Static_assert(_Alignof(B18) == 128, "record B18 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B18_alignment) == 256, "record B18 wrong sizeof");
_Static_assert(_Alignof(struct B18_alignment) == 128, "record B18 wrong alignment");
_Static_assert(sizeof(struct B18_packed) == 128, "record B18 wrong sizeof");
_Static_assert(_Alignof(struct B18_packed) == 1, "record B18 wrong alignment");
_Static_assert(sizeof(struct B18_required_alignment) == 129, "record B18 wrong sizeof");
_Static_assert(_Alignof(struct B18_required_alignment) == 1, "record B18 wrong alignment");
_Static_assert(sizeof(struct B18_size) == 130, "record B18 wrong sizeof");
_Static_assert(_Alignof(struct B18_size) == 1, "record B18 wrong alignment");
#endif
_Static_assert(sizeof(B19) == 128, "record B19 wrong sizeof");
_Static_assert(_Alignof(B19) == 128, "record B19 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B19_alignment) == 256, "record B19 wrong sizeof");
_Static_assert(_Alignof(struct B19_alignment) == 128, "record B19 wrong alignment");
_Static_assert(sizeof(struct B19_packed) == 128, "record B19 wrong sizeof");
_Static_assert(_Alignof(struct B19_packed) == 1, "record B19 wrong alignment");
_Static_assert(sizeof(struct B19_required_alignment) == 129, "record B19 wrong sizeof");
_Static_assert(_Alignof(struct B19_required_alignment) == 1, "record B19 wrong alignment");
_Static_assert(sizeof(struct B19_size) == 130, "record B19 wrong sizeof");
_Static_assert(_Alignof(struct B19_size) == 1, "record B19 wrong alignment");
#endif
_Static_assert(sizeof(B20) == 128, "record B20 wrong sizeof");
_Static_assert(_Alignof(B20) == 128, "record B20 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B20_alignment) == 256, "record B20 wrong sizeof");
_Static_assert(_Alignof(struct B20_alignment) == 128, "record B20 wrong alignment");
_Static_assert(sizeof(struct B20_packed) == 128, "record B20 wrong sizeof");
_Static_assert(_Alignof(struct B20_packed) == 1, "record B20 wrong alignment");
_Static_assert(sizeof(struct B20_required_alignment) == 129, "record B20 wrong sizeof");
_Static_assert(_Alignof(struct B20_required_alignment) == 1, "record B20 wrong alignment");
_Static_assert(sizeof(struct B20_size) == 130, "record B20 wrong sizeof");
_Static_assert(_Alignof(struct B20_size) == 1, "record B20 wrong alignment");
#endif
_Static_assert(sizeof(B21) == 128, "record B21 wrong sizeof");
_Static_assert(_Alignof(B21) == 128, "record B21 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B21_alignment) == 256, "record B21 wrong sizeof");
_Static_assert(_Alignof(struct B21_alignment) == 128, "record B21 wrong alignment");
_Static_assert(sizeof(struct B21_packed) == 128, "record B21 wrong sizeof");
_Static_assert(_Alignof(struct B21_packed) == 1, "record B21 wrong alignment");
_Static_assert(sizeof(struct B21_required_alignment) == 129, "record B21 wrong sizeof");
_Static_assert(_Alignof(struct B21_required_alignment) == 1, "record B21 wrong alignment");
_Static_assert(sizeof(struct B21_size) == 130, "record B21 wrong sizeof");
_Static_assert(_Alignof(struct B21_size) == 1, "record B21 wrong alignment");
#endif
_Static_assert(sizeof(B22) == 128, "record B22 wrong sizeof");
_Static_assert(_Alignof(B22) == 128, "record B22 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B22_alignment) == 256, "record B22 wrong sizeof");
_Static_assert(_Alignof(struct B22_alignment) == 128, "record B22 wrong alignment");
_Static_assert(sizeof(struct B22_packed) == 128, "record B22 wrong sizeof");
_Static_assert(_Alignof(struct B22_packed) == 1, "record B22 wrong alignment");
_Static_assert(sizeof(struct B22_required_alignment) == 129, "record B22 wrong sizeof");
_Static_assert(_Alignof(struct B22_required_alignment) == 1, "record B22 wrong alignment");
_Static_assert(sizeof(struct B22_size) == 130, "record B22 wrong sizeof");
_Static_assert(_Alignof(struct B22_size) == 1, "record B22 wrong alignment");
#endif
_Static_assert(sizeof(B23) == 128, "record B23 wrong sizeof");
_Static_assert(_Alignof(B23) == 128, "record B23 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B23_alignment) == 256, "record B23 wrong sizeof");
_Static_assert(_Alignof(struct B23_alignment) == 128, "record B23 wrong alignment");
_Static_assert(sizeof(struct B23_packed) == 128, "record B23 wrong sizeof");
_Static_assert(_Alignof(struct B23_packed) == 1, "record B23 wrong alignment");
_Static_assert(sizeof(struct B23_required_alignment) == 129, "record B23 wrong sizeof");
_Static_assert(_Alignof(struct B23_required_alignment) == 1, "record B23 wrong alignment");
_Static_assert(sizeof(struct B23_size) == 130, "record B23 wrong sizeof");
_Static_assert(_Alignof(struct B23_size) == 1, "record B23 wrong alignment");
#endif
_Static_assert(sizeof(B24) == 128, "record B24 wrong sizeof");
_Static_assert(_Alignof(B24) == 128, "record B24 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B24_alignment) == 256, "record B24 wrong sizeof");
_Static_assert(_Alignof(struct B24_alignment) == 128, "record B24 wrong alignment");
_Static_assert(sizeof(struct B24_packed) == 128, "record B24 wrong sizeof");
_Static_assert(_Alignof(struct B24_packed) == 1, "record B24 wrong alignment");
_Static_assert(sizeof(struct B24_required_alignment) == 129, "record B24 wrong sizeof");
_Static_assert(_Alignof(struct B24_required_alignment) == 1, "record B24 wrong alignment");
_Static_assert(sizeof(struct B24_size) == 130, "record B24 wrong sizeof");
_Static_assert(_Alignof(struct B24_size) == 1, "record B24 wrong alignment");
#endif
_Static_assert(sizeof(B25) == 128, "record B25 wrong sizeof");
_Static_assert(_Alignof(B25) == 128, "record B25 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B25_alignment) == 256, "record B25 wrong sizeof");
_Static_assert(_Alignof(struct B25_alignment) == 128, "record B25 wrong alignment");
_Static_assert(sizeof(struct B25_packed) == 128, "record B25 wrong sizeof");
_Static_assert(_Alignof(struct B25_packed) == 1, "record B25 wrong alignment");
_Static_assert(sizeof(struct B25_required_alignment) == 129, "record B25 wrong sizeof");
_Static_assert(_Alignof(struct B25_required_alignment) == 1, "record B25 wrong alignment");
_Static_assert(sizeof(struct B25_size) == 130, "record B25 wrong sizeof");
_Static_assert(_Alignof(struct B25_size) == 1, "record B25 wrong alignment");
#endif
_Static_assert(sizeof(B26) == 128, "record B26 wrong sizeof");
_Static_assert(_Alignof(B26) == 128, "record B26 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B26_alignment) == 256, "record B26 wrong sizeof");
_Static_assert(_Alignof(struct B26_alignment) == 128, "record B26 wrong alignment");
_Static_assert(sizeof(struct B26_packed) == 128, "record B26 wrong sizeof");
_Static_assert(_Alignof(struct B26_packed) == 1, "record B26 wrong alignment");
_Static_assert(sizeof(struct B26_required_alignment) == 129, "record B26 wrong sizeof");
_Static_assert(_Alignof(struct B26_required_alignment) == 1, "record B26 wrong alignment");
_Static_assert(sizeof(struct B26_size) == 130, "record B26 wrong sizeof");
_Static_assert(_Alignof(struct B26_size) == 1, "record B26 wrong alignment");
#endif
_Static_assert(sizeof(B27) == 128, "record B27 wrong sizeof");
_Static_assert(_Alignof(B27) == 128, "record B27 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B27_alignment) == 256, "record B27 wrong sizeof");
_Static_assert(_Alignof(struct B27_alignment) == 128, "record B27 wrong alignment");
_Static_assert(sizeof(struct B27_packed) == 128, "record B27 wrong sizeof");
_Static_assert(_Alignof(struct B27_packed) == 1, "record B27 wrong alignment");
_Static_assert(sizeof(struct B27_required_alignment) == 129, "record B27 wrong sizeof");
_Static_assert(_Alignof(struct B27_required_alignment) == 1, "record B27 wrong alignment");
_Static_assert(sizeof(struct B27_size) == 130, "record B27 wrong sizeof");
_Static_assert(_Alignof(struct B27_size) == 1, "record B27 wrong alignment");
#endif
_Static_assert(sizeof(B28) == 128, "record B28 wrong sizeof");
_Static_assert(_Alignof(B28) == 128, "record B28 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B28_alignment) == 256, "record B28 wrong sizeof");
_Static_assert(_Alignof(struct B28_alignment) == 128, "record B28 wrong alignment");
_Static_assert(sizeof(struct B28_packed) == 128, "record B28 wrong sizeof");
_Static_assert(_Alignof(struct B28_packed) == 1, "record B28 wrong alignment");
_Static_assert(sizeof(struct B28_required_alignment) == 129, "record B28 wrong sizeof");
_Static_assert(_Alignof(struct B28_required_alignment) == 1, "record B28 wrong alignment");
_Static_assert(sizeof(struct B28_size) == 130, "record B28 wrong sizeof");
_Static_assert(_Alignof(struct B28_size) == 1, "record B28 wrong alignment");
#endif
_Static_assert(sizeof(B29) == 128, "record B29 wrong sizeof");
_Static_assert(_Alignof(B29) == 128, "record B29 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B29_alignment) == 256, "record B29 wrong sizeof");
_Static_assert(_Alignof(struct B29_alignment) == 128, "record B29 wrong alignment");
_Static_assert(sizeof(struct B29_packed) == 128, "record B29 wrong sizeof");
_Static_assert(_Alignof(struct B29_packed) == 1, "record B29 wrong alignment");
_Static_assert(sizeof(struct B29_required_alignment) == 129, "record B29 wrong sizeof");
_Static_assert(_Alignof(struct B29_required_alignment) == 1, "record B29 wrong alignment");
_Static_assert(sizeof(struct B29_size) == 130, "record B29 wrong sizeof");
_Static_assert(_Alignof(struct B29_size) == 1, "record B29 wrong alignment");
#endif
_Static_assert(sizeof(B30) == 128, "record B30 wrong sizeof");
_Static_assert(_Alignof(B30) == 128, "record B30 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B30_alignment) == 256, "record B30 wrong sizeof");
_Static_assert(_Alignof(struct B30_alignment) == 128, "record B30 wrong alignment");
_Static_assert(sizeof(struct B30_packed) == 128, "record B30 wrong sizeof");
_Static_assert(_Alignof(struct B30_packed) == 1, "record B30 wrong alignment");
_Static_assert(sizeof(struct B30_required_alignment) == 129, "record B30 wrong sizeof");
_Static_assert(_Alignof(struct B30_required_alignment) == 1, "record B30 wrong alignment");
_Static_assert(sizeof(struct B30_size) == 130, "record B30 wrong sizeof");
_Static_assert(_Alignof(struct B30_size) == 1, "record B30 wrong alignment");
#endif
_Static_assert(sizeof(B31) == 128, "record B31 wrong sizeof");
_Static_assert(_Alignof(B31) == 128, "record B31 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B31_alignment) == 256, "record B31 wrong sizeof");
_Static_assert(_Alignof(struct B31_alignment) == 128, "record B31 wrong alignment");
_Static_assert(sizeof(struct B31_packed) == 128, "record B31 wrong sizeof");
_Static_assert(_Alignof(struct B31_packed) == 1, "record B31 wrong alignment");
_Static_assert(sizeof(struct B31_required_alignment) == 129, "record B31 wrong sizeof");
_Static_assert(_Alignof(struct B31_required_alignment) == 1, "record B31 wrong alignment");
_Static_assert(sizeof(struct B31_size) == 130, "record B31 wrong sizeof");
_Static_assert(_Alignof(struct B31_size) == 1, "record B31 wrong alignment");
#endif
_Static_assert(sizeof(B32) == 128, "record B32 wrong sizeof");
_Static_assert(_Alignof(B32) == 128, "record B32 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B32_alignment) == 256, "record B32 wrong sizeof");
_Static_assert(_Alignof(struct B32_alignment) == 128, "record B32 wrong alignment");
_Static_assert(sizeof(struct B32_packed) == 128, "record B32 wrong sizeof");
_Static_assert(_Alignof(struct B32_packed) == 1, "record B32 wrong alignment");
_Static_assert(sizeof(struct B32_required_alignment) == 129, "record B32 wrong sizeof");
_Static_assert(_Alignof(struct B32_required_alignment) == 1, "record B32 wrong alignment");
_Static_assert(sizeof(struct B32_size) == 130, "record B32 wrong sizeof");
_Static_assert(_Alignof(struct B32_size) == 1, "record B32 wrong alignment");
#endif
_Static_assert(sizeof(B33) == 128, "record B33 wrong sizeof");
_Static_assert(_Alignof(B33) == 128, "record B33 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B33_alignment) == 256, "record B33 wrong sizeof");
_Static_assert(_Alignof(struct B33_alignment) == 128, "record B33 wrong alignment");
_Static_assert(sizeof(struct B33_packed) == 128, "record B33 wrong sizeof");
_Static_assert(_Alignof(struct B33_packed) == 1, "record B33 wrong alignment");
_Static_assert(sizeof(struct B33_required_alignment) == 129, "record B33 wrong sizeof");
_Static_assert(_Alignof(struct B33_required_alignment) == 1, "record B33 wrong alignment");
_Static_assert(sizeof(struct B33_size) == 130, "record B33 wrong sizeof");
_Static_assert(_Alignof(struct B33_size) == 1, "record B33 wrong alignment");
#endif
_Static_assert(sizeof(B34) == 128, "record B34 wrong sizeof");
_Static_assert(_Alignof(B34) == 128, "record B34 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B34_alignment) == 256, "record B34 wrong sizeof");
_Static_assert(_Alignof(struct B34_alignment) == 128, "record B34 wrong alignment");
_Static_assert(sizeof(struct B34_packed) == 128, "record B34 wrong sizeof");
_Static_assert(_Alignof(struct B34_packed) == 1, "record B34 wrong alignment");
_Static_assert(sizeof(struct B34_required_alignment) == 129, "record B34 wrong sizeof");
_Static_assert(_Alignof(struct B34_required_alignment) == 1, "record B34 wrong alignment");
_Static_assert(sizeof(struct B34_size) == 130, "record B34 wrong sizeof");
_Static_assert(_Alignof(struct B34_size) == 1, "record B34 wrong alignment");
#endif
_Static_assert(sizeof(B35) == 128, "record B35 wrong sizeof");
_Static_assert(_Alignof(B35) == 128, "record B35 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B35_alignment) == 256, "record B35 wrong sizeof");
_Static_assert(_Alignof(struct B35_alignment) == 128, "record B35 wrong alignment");
_Static_assert(sizeof(struct B35_packed) == 128, "record B35 wrong sizeof");
_Static_assert(_Alignof(struct B35_packed) == 1, "record B35 wrong alignment");
_Static_assert(sizeof(struct B35_required_alignment) == 129, "record B35 wrong sizeof");
_Static_assert(_Alignof(struct B35_required_alignment) == 1, "record B35 wrong alignment");
_Static_assert(sizeof(struct B35_size) == 130, "record B35 wrong sizeof");
_Static_assert(_Alignof(struct B35_size) == 1, "record B35 wrong alignment");
#endif
_Static_assert(sizeof(B36) == 128, "record B36 wrong sizeof");
_Static_assert(_Alignof(B36) == 128, "record B36 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B36_alignment) == 256, "record B36 wrong sizeof");
_Static_assert(_Alignof(struct B36_alignment) == 128, "record B36 wrong alignment");
_Static_assert(sizeof(struct B36_packed) == 128, "record B36 wrong sizeof");
_Static_assert(_Alignof(struct B36_packed) == 1, "record B36 wrong alignment");
_Static_assert(sizeof(struct B36_required_alignment) == 129, "record B36 wrong sizeof");
_Static_assert(_Alignof(struct B36_required_alignment) == 1, "record B36 wrong alignment");
_Static_assert(sizeof(struct B36_size) == 130, "record B36 wrong sizeof");
_Static_assert(_Alignof(struct B36_size) == 1, "record B36 wrong alignment");
#endif
_Static_assert(sizeof(B37) == 128, "record B37 wrong sizeof");
_Static_assert(_Alignof(B37) == 128, "record B37 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B37_alignment) == 256, "record B37 wrong sizeof");
_Static_assert(_Alignof(struct B37_alignment) == 128, "record B37 wrong alignment");
_Static_assert(sizeof(struct B37_packed) == 128, "record B37 wrong sizeof");
_Static_assert(_Alignof(struct B37_packed) == 1, "record B37 wrong alignment");
_Static_assert(sizeof(struct B37_required_alignment) == 129, "record B37 wrong sizeof");
_Static_assert(_Alignof(struct B37_required_alignment) == 1, "record B37 wrong alignment");
_Static_assert(sizeof(struct B37_size) == 130, "record B37 wrong sizeof");
_Static_assert(_Alignof(struct B37_size) == 1, "record B37 wrong alignment");
#endif
_Static_assert(sizeof(B38) == 128, "record B38 wrong sizeof");
_Static_assert(_Alignof(B38) == 128, "record B38 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B38_alignment) == 256, "record B38 wrong sizeof");
_Static_assert(_Alignof(struct B38_alignment) == 128, "record B38 wrong alignment");
_Static_assert(sizeof(struct B38_packed) == 128, "record B38 wrong sizeof");
_Static_assert(_Alignof(struct B38_packed) == 1, "record B38 wrong alignment");
_Static_assert(sizeof(struct B38_required_alignment) == 129, "record B38 wrong sizeof");
_Static_assert(_Alignof(struct B38_required_alignment) == 1, "record B38 wrong alignment");
_Static_assert(sizeof(struct B38_size) == 130, "record B38 wrong sizeof");
_Static_assert(_Alignof(struct B38_size) == 1, "record B38 wrong alignment");
#endif
_Static_assert(sizeof(B39) == 128, "record B39 wrong sizeof");
_Static_assert(_Alignof(B39) == 128, "record B39 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B39_alignment) == 256, "record B39 wrong sizeof");
_Static_assert(_Alignof(struct B39_alignment) == 128, "record B39 wrong alignment");
_Static_assert(sizeof(struct B39_packed) == 128, "record B39 wrong sizeof");
_Static_assert(_Alignof(struct B39_packed) == 1, "record B39 wrong alignment");
_Static_assert(sizeof(struct B39_required_alignment) == 129, "record B39 wrong sizeof");
_Static_assert(_Alignof(struct B39_required_alignment) == 1, "record B39 wrong alignment");
_Static_assert(sizeof(struct B39_size) == 130, "record B39 wrong sizeof");
_Static_assert(_Alignof(struct B39_size) == 1, "record B39 wrong alignment");
#endif
#endif
