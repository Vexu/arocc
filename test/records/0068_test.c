// SPDX-License-Identifier: GPL-3.0-or-later

// This test file is auto-generated. do not edit.
// This file is a derivative work from the test files found
// in this repo : https://github.com/mahkoh/repr-c
// and is under the same licence as the original work.

typedef struct {
    char:0 __attribute__((aligned(4)));
    char d;
} A;
A var1;
struct A_extra_alignment {
    char a;
    A b;
};
struct A_extra_alignment var2;
#pragma pack(1)
struct A_extra_packed {
    A a;
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

typedef struct {
    char c;
    char:0 __attribute__((aligned(4)));
    char d;
} A_;
A_ var5;
struct A__extra_alignment {
    char a;
    A_ b;
};
struct A__extra_alignment var6;
#pragma pack(1)
struct A__extra_packed {
    A_ a;
};
#pragma pack()
struct A__extra_required_alignment {
    char a;
    struct A__extra_packed b;
};
struct A__extra_required_alignment var7;
struct A__extra_size {
    char a[sizeof(A_)+1];
    char b;
};
struct A__extra_size var8;

typedef struct {
    long long:0 __attribute__((aligned(4)));
    char d;
} B;
B var9;
struct B_extra_alignment {
    char a;
    B b;
};
struct B_extra_alignment var10;
#pragma pack(1)
struct B_extra_packed {
    B a;
};
#pragma pack()
struct B_extra_required_alignment {
    char a;
    struct B_extra_packed b;
};
struct B_extra_required_alignment var11;
struct B_extra_size {
    char a[sizeof(B)+1];
    char b;
};
struct B_extra_size var12;

typedef struct {
    char c;
    long long:0 __attribute__((aligned(4)));
    char d;
} B_;
B_ var13;
struct B__extra_alignment {
    char a;
    B_ b;
};
struct B__extra_alignment var14;
#pragma pack(1)
struct B__extra_packed {
    B_ a;
};
#pragma pack()
struct B__extra_required_alignment {
    char a;
    struct B__extra_packed b;
};
struct B__extra_required_alignment var15;
struct B__extra_size {
    char a[sizeof(B_)+1];
    char b;
};
struct B__extra_size var16;

typedef struct {
    long long:0;
    char d;
} C;
C var17;
struct C_extra_alignment {
    char a;
    C b;
};
struct C_extra_alignment var18;
#pragma pack(1)
struct C_extra_packed {
    C a;
};
#pragma pack()
struct C_extra_required_alignment {
    char a;
    struct C_extra_packed b;
};
struct C_extra_required_alignment var19;
struct C_extra_size {
    char a[sizeof(C)+1];
    char b;
};
struct C_extra_size var20;

typedef struct {
    char c;
    long long:0;
    char d;
} C_;
C_ var21;
struct C__extra_alignment {
    char a;
    C_ b;
};
struct C__extra_alignment var22;
#pragma pack(1)
struct C__extra_packed {
    C_ a;
};
#pragma pack()
struct C__extra_required_alignment {
    char a;
    struct C__extra_packed b;
};
struct C__extra_required_alignment var23;
struct C__extra_size {
    char a[sizeof(C_)+1];
    char b;
};
struct C__extra_size var24;

typedef struct {
    char c;
    long long d;
    char e;
} D;
D var25;
struct D_extra_alignment {
    char a;
    D b;
};
struct D_extra_alignment var26;
#pragma pack(1)
struct D_extra_packed {
    D a;
};
#pragma pack()
struct D_extra_required_alignment {
    char a;
    struct D_extra_packed b;
};
struct D_extra_required_alignment var27;
struct D_extra_size {
    char a[sizeof(D)+1];
    char b;
};
struct D_extra_size var28;

typedef struct {
    char c;
    long long d __attribute__((aligned(16)));
    char e;
} F;
F var29;
struct F_extra_alignment {
    char a;
    F b;
};
struct F_extra_alignment var30;
#pragma pack(1)
struct F_extra_packed {
    F a;
};
#pragma pack()
struct F_extra_required_alignment {
    char a;
    struct F_extra_packed b;
};
struct F_extra_required_alignment var31;
struct F_extra_size {
    char a[sizeof(F)+1];
    char b;
};
struct F_extra_size var32;

typedef struct {
    char c;
    long long d __attribute__((aligned(2))) __attribute__((packed));
    char e;
} G;
G var33;
struct G_extra_alignment {
    char a;
    G b;
};
struct G_extra_alignment var34;
#pragma pack(1)
struct G_extra_packed {
    G a;
};
#pragma pack()
struct G_extra_required_alignment {
    char a;
    struct G_extra_packed b;
};
struct G_extra_required_alignment var35;
struct G_extra_size {
    char a[sizeof(G)+1];
    char b;
};
struct G_extra_size var36;

#pragma pack(2)
typedef struct {
    char c;
    long long d __attribute__((aligned(4))) __attribute__((packed));
    char e;
} H;
H var37;
#pragma pack()
struct H_extra_alignment {
    char a;
    H b;
};
struct H_extra_alignment var38;
#pragma pack(1)
struct H_extra_packed {
    H a;
};
#pragma pack()
struct H_extra_required_alignment {
    char a;
    struct H_extra_packed b;
};
struct H_extra_required_alignment var39;
struct H_extra_size {
    char a[sizeof(H)+1];
    char b;
};
struct H_extra_size var40;

typedef struct {
    char c;
    long long d __attribute__((packed));
    char e;
} I;
I var41;
struct I_extra_alignment {
    char a;
    I b;
};
struct I_extra_alignment var42;
#pragma pack(1)
struct I_extra_packed {
    I a;
};
#pragma pack()
struct I_extra_required_alignment {
    char a;
    struct I_extra_packed b;
};
struct I_extra_required_alignment var43;
struct I_extra_size {
    char a[sizeof(I)+1];
    char b;
};
struct I_extra_size var44;

#pragma pack(2)
typedef struct {
    char c;
    long long d;
    char e;
} J;
J var45;
#pragma pack()
struct J_extra_alignment {
    char a;
    J b;
};
struct J_extra_alignment var46;
#pragma pack(1)
struct J_extra_packed {
    J a;
};
#pragma pack()
struct J_extra_required_alignment {
    char a;
    struct J_extra_packed b;
};
struct J_extra_required_alignment var47;
struct J_extra_size {
    char a[sizeof(J)+1];
    char b;
};
struct J_extra_size var48;

typedef struct {
    char c;
    long long d:1;
    char e;
} K;
K var49;
struct K_extra_alignment {
    char a;
    K b;
};
struct K_extra_alignment var50;
#pragma pack(1)
struct K_extra_packed {
    K a;
};
#pragma pack()
struct K_extra_required_alignment {
    char a;
    struct K_extra_packed b;
};
struct K_extra_required_alignment var51;
struct K_extra_size {
    char a[sizeof(K)+1];
    char b;
};
struct K_extra_size var52;

typedef struct {
    char c;
    long long d:1 __attribute__((aligned(16)));
    char e;
} L;
L var53;
struct L_extra_alignment {
    char a;
    L b;
};
struct L_extra_alignment var54;
#pragma pack(1)
struct L_extra_packed {
    L a;
};
#pragma pack()
struct L_extra_required_alignment {
    char a;
    struct L_extra_packed b;
};
struct L_extra_required_alignment var55;
struct L_extra_size {
    char a[sizeof(L)+1];
    char b;
};
struct L_extra_size var56;

typedef struct {
    char c;
    long long d:1 __attribute__((aligned(2))) __attribute__((packed));
    char e;
} M;
M var57;
struct M_extra_alignment {
    char a;
    M b;
};
struct M_extra_alignment var58;
#pragma pack(1)
struct M_extra_packed {
    M a;
};
#pragma pack()
struct M_extra_required_alignment {
    char a;
    struct M_extra_packed b;
};
struct M_extra_required_alignment var59;
struct M_extra_size {
    char a[sizeof(M)+1];
    char b;
};
struct M_extra_size var60;

#pragma pack(2)
typedef struct {
    char c;
    long long d:1 __attribute__((aligned(4))) __attribute__((packed));
    char e;
} N;
N var61;
#pragma pack()
struct N_extra_alignment {
    char a;
    N b;
};
struct N_extra_alignment var62;
#pragma pack(1)
struct N_extra_packed {
    N a;
};
#pragma pack()
struct N_extra_required_alignment {
    char a;
    struct N_extra_packed b;
};
struct N_extra_required_alignment var63;
struct N_extra_size {
    char a[sizeof(N)+1];
    char b;
};
struct N_extra_size var64;

typedef struct {
    char c;
    long long d:1 __attribute__((packed));
    char e;
} O;
O var65;
struct O_extra_alignment {
    char a;
    O b;
};
struct O_extra_alignment var66;
#pragma pack(1)
struct O_extra_packed {
    O a;
};
#pragma pack()
struct O_extra_required_alignment {
    char a;
    struct O_extra_packed b;
};
struct O_extra_required_alignment var67;
struct O_extra_size {
    char a[sizeof(O)+1];
    char b;
};
struct O_extra_size var68;

#pragma pack(2)
typedef struct {
    char c;
    long long d:1;
    char e;
} P;
P var69;
#pragma pack()
struct P_extra_alignment {
    char a;
    P b;
};
struct P_extra_alignment var70;
#pragma pack(1)
struct P_extra_packed {
    P a;
};
#pragma pack()
struct P_extra_required_alignment {
    char a;
    struct P_extra_packed b;
};
struct P_extra_required_alignment var71;
struct P_extra_size {
    char a[sizeof(P)+1];
    char b;
};
struct P_extra_size var72;

typedef struct {
    char c;
    char x:1;
    long long d:1;
    char e;
} Q;
Q var73;
struct Q_extra_alignment {
    char a;
    Q b;
};
struct Q_extra_alignment var74;
#pragma pack(1)
struct Q_extra_packed {
    Q a;
};
#pragma pack()
struct Q_extra_required_alignment {
    char a;
    struct Q_extra_packed b;
};
struct Q_extra_required_alignment var75;
struct Q_extra_size {
    char a[sizeof(Q)+1];
    char b;
};
struct Q_extra_size var76;

typedef struct {
    char c;
    char x:1;
    long long:0 __attribute__((aligned(16)));
    char e;
} R;
R var77;
struct R_extra_alignment {
    char a;
    R b;
};
struct R_extra_alignment var78;
#pragma pack(1)
struct R_extra_packed {
    R a;
};
#pragma pack()
struct R_extra_required_alignment {
    char a;
    struct R_extra_packed b;
};
struct R_extra_required_alignment var79;
struct R_extra_size {
    char a[sizeof(R)+1];
    char b;
};
struct R_extra_size var80;

typedef struct {
    char c;
    char x:1;
    long long:0 __attribute__((aligned(2))) __attribute__((packed));
    char e;
} S;
S var81;
struct S_extra_alignment {
    char a;
    S b;
};
struct S_extra_alignment var82;
#pragma pack(1)
struct S_extra_packed {
    S a;
};
#pragma pack()
struct S_extra_required_alignment {
    char a;
    struct S_extra_packed b;
};
struct S_extra_required_alignment var83;
struct S_extra_size {
    char a[sizeof(S)+1];
    char b;
};
struct S_extra_size var84;

#pragma pack(2)
typedef struct {
    char c;
    char x:1;
    long long:0 __attribute__((aligned(4))) __attribute__((packed));
    char e;
} T;
T var85;
#pragma pack()
struct T_extra_alignment {
    char a;
    T b;
};
struct T_extra_alignment var86;
#pragma pack(1)
struct T_extra_packed {
    T a;
};
#pragma pack()
struct T_extra_required_alignment {
    char a;
    struct T_extra_packed b;
};
struct T_extra_required_alignment var87;
struct T_extra_size {
    char a[sizeof(T)+1];
    char b;
};
struct T_extra_size var88;

typedef struct {
    char c;
    char x:1;
    long long:0 __attribute__((packed));
    char e;
} U;
U var89;
struct U_extra_alignment {
    char a;
    U b;
};
struct U_extra_alignment var90;
#pragma pack(1)
struct U_extra_packed {
    U a;
};
#pragma pack()
struct U_extra_required_alignment {
    char a;
    struct U_extra_packed b;
};
struct U_extra_required_alignment var91;
struct U_extra_size {
    char a[sizeof(U)+1];
    char b;
};
struct U_extra_size var92;

#pragma pack(2)
typedef struct {
    char c;
    char x:1;
    long long:0;
    char e;
} V;
V var93;
#pragma pack()
struct V_extra_alignment {
    char a;
    V b;
};
struct V_extra_alignment var94;
#pragma pack(1)
struct V_extra_packed {
    V a;
};
#pragma pack()
struct V_extra_required_alignment {
    char a;
    struct V_extra_packed b;
};
struct V_extra_required_alignment var95;
struct V_extra_size {
    char a[sizeof(V)+1];
    char b;
};
struct V_extra_size var96;

typedef struct {
    char c;
    char x:1;
    long long:0 __attribute__((aligned(16))) __attribute__((packed));
    char e;
} W;
W var97;
struct W_extra_alignment {
    char a;
    W b;
};
struct W_extra_alignment var98;
#pragma pack(1)
struct W_extra_packed {
    W a;
};
#pragma pack()
struct W_extra_required_alignment {
    char a;
    struct W_extra_packed b;
};
struct W_extra_required_alignment var99;
struct W_extra_size {
    char a[sizeof(W)+1];
    char b;
};
struct W_extra_size var100;

#pragma pack(1)
typedef struct {
    char c;
    long long:0 __attribute__((aligned(16)));
    char e;
} W_;
W_ var101;
#pragma pack()
struct W__extra_alignment {
    char a;
    W_ b;
};
struct W__extra_alignment var102;
#pragma pack(1)
struct W__extra_packed {
    W_ a;
};
#pragma pack()
struct W__extra_required_alignment {
    char a;
    struct W__extra_packed b;
};
struct W__extra_required_alignment var103;
struct W__extra_size {
    char a[sizeof(W_)+1];
    char b;
};
struct W__extra_size var104;

#pragma pack(2)
typedef struct {
    char c;
    char x:1;
    long long:0 __attribute__((aligned(16))) __attribute__((packed));
    char e;
} X;
X var105;
#pragma pack()
struct X_extra_alignment {
    char a;
    X b;
};
struct X_extra_alignment var106;
#pragma pack(1)
struct X_extra_packed {
    X a;
};
#pragma pack()
struct X_extra_required_alignment {
    char a;
    struct X_extra_packed b;
};
struct X_extra_required_alignment var107;
struct X_extra_size {
    char a[sizeof(X)+1];
    char b;
};
struct X_extra_size var108;

typedef union {
    char:0 __attribute__((aligned(4)));
    char d;
} A2;
A2 var109;
struct A2_extra_alignment {
    char a;
    A2 b;
};
struct A2_extra_alignment var110;
#pragma pack(1)
struct A2_extra_packed {
    A2 a;
};
#pragma pack()
struct A2_extra_required_alignment {
    char a;
    struct A2_extra_packed b;
};
struct A2_extra_required_alignment var111;
struct A2_extra_size {
    char a[sizeof(A2)+1];
    char b;
};
struct A2_extra_size var112;

typedef union {
    char c;
    char:0 __attribute__((aligned(4)));
    char d;
} A_2;
A_2 var113;
struct A_2_extra_alignment {
    char a;
    A_2 b;
};
struct A_2_extra_alignment var114;
#pragma pack(1)
struct A_2_extra_packed {
    A_2 a;
};
#pragma pack()
struct A_2_extra_required_alignment {
    char a;
    struct A_2_extra_packed b;
};
struct A_2_extra_required_alignment var115;
struct A_2_extra_size {
    char a[sizeof(A_2)+1];
    char b;
};
struct A_2_extra_size var116;

typedef union {
    long long:0 __attribute__((aligned(4)));
    char d;
} B2;
B2 var117;
struct B2_extra_alignment {
    char a;
    B2 b;
};
struct B2_extra_alignment var118;
#pragma pack(1)
struct B2_extra_packed {
    B2 a;
};
#pragma pack()
struct B2_extra_required_alignment {
    char a;
    struct B2_extra_packed b;
};
struct B2_extra_required_alignment var119;
struct B2_extra_size {
    char a[sizeof(B2)+1];
    char b;
};
struct B2_extra_size var120;

typedef union {
    char c;
    long long:0 __attribute__((aligned(4)));
    char d;
} B_2;
B_2 var121;
struct B_2_extra_alignment {
    char a;
    B_2 b;
};
struct B_2_extra_alignment var122;
#pragma pack(1)
struct B_2_extra_packed {
    B_2 a;
};
#pragma pack()
struct B_2_extra_required_alignment {
    char a;
    struct B_2_extra_packed b;
};
struct B_2_extra_required_alignment var123;
struct B_2_extra_size {
    char a[sizeof(B_2)+1];
    char b;
};
struct B_2_extra_size var124;

typedef union {
    long long:0;
    char d;
} C2;
C2 var125;
struct C2_extra_alignment {
    char a;
    C2 b;
};
struct C2_extra_alignment var126;
#pragma pack(1)
struct C2_extra_packed {
    C2 a;
};
#pragma pack()
struct C2_extra_required_alignment {
    char a;
    struct C2_extra_packed b;
};
struct C2_extra_required_alignment var127;
struct C2_extra_size {
    char a[sizeof(C2)+1];
    char b;
};
struct C2_extra_size var128;

typedef union {
    char c;
    long long:0;
    char d;
} C22;
C22 var129;
struct C22_extra_alignment {
    char a;
    C22 b;
};
struct C22_extra_alignment var130;
#pragma pack(1)
struct C22_extra_packed {
    C22 a;
};
#pragma pack()
struct C22_extra_required_alignment {
    char a;
    struct C22_extra_packed b;
};
struct C22_extra_required_alignment var131;
struct C22_extra_size {
    char a[sizeof(C22)+1];
    char b;
};
struct C22_extra_size var132;

typedef union {
    char c;
    long long d;
    char e;
} D2;
D2 var133;
struct D2_extra_alignment {
    char a;
    D2 b;
};
struct D2_extra_alignment var134;
#pragma pack(1)
struct D2_extra_packed {
    D2 a;
};
#pragma pack()
struct D2_extra_required_alignment {
    char a;
    struct D2_extra_packed b;
};
struct D2_extra_required_alignment var135;
struct D2_extra_size {
    char a[sizeof(D2)+1];
    char b;
};
struct D2_extra_size var136;

typedef union {
    char c;
    long long d __attribute__((aligned(16)));
    char e;
} F2;
F2 var137;
struct F2_extra_alignment {
    char a;
    F2 b;
};
struct F2_extra_alignment var138;
#pragma pack(1)
struct F2_extra_packed {
    F2 a;
};
#pragma pack()
struct F2_extra_required_alignment {
    char a;
    struct F2_extra_packed b;
};
struct F2_extra_required_alignment var139;
struct F2_extra_size {
    char a[sizeof(F2)+1];
    char b;
};
struct F2_extra_size var140;

typedef union {
    char c;
    long long d __attribute__((aligned(2))) __attribute__((packed));
    char e;
} G2;
G2 var141;
struct G2_extra_alignment {
    char a;
    G2 b;
};
struct G2_extra_alignment var142;
#pragma pack(1)
struct G2_extra_packed {
    G2 a;
};
#pragma pack()
struct G2_extra_required_alignment {
    char a;
    struct G2_extra_packed b;
};
struct G2_extra_required_alignment var143;
struct G2_extra_size {
    char a[sizeof(G2)+1];
    char b;
};
struct G2_extra_size var144;

#pragma pack(2)
typedef union {
    char c;
    long long d __attribute__((aligned(4))) __attribute__((packed));
    char e;
} H2;
H2 var145;
#pragma pack()
struct H2_extra_alignment {
    char a;
    H2 b;
};
struct H2_extra_alignment var146;
#pragma pack(1)
struct H2_extra_packed {
    H2 a;
};
#pragma pack()
struct H2_extra_required_alignment {
    char a;
    struct H2_extra_packed b;
};
struct H2_extra_required_alignment var147;
struct H2_extra_size {
    char a[sizeof(H2)+1];
    char b;
};
struct H2_extra_size var148;

typedef union {
    char c;
    long long d __attribute__((packed));
    char e;
} I2;
I2 var149;
struct I2_extra_alignment {
    char a;
    I2 b;
};
struct I2_extra_alignment var150;
#pragma pack(1)
struct I2_extra_packed {
    I2 a;
};
#pragma pack()
struct I2_extra_required_alignment {
    char a;
    struct I2_extra_packed b;
};
struct I2_extra_required_alignment var151;
struct I2_extra_size {
    char a[sizeof(I2)+1];
    char b;
};
struct I2_extra_size var152;

#pragma pack(2)
typedef union {
    char c;
    long long d;
    char e;
} J2;
J2 var153;
#pragma pack()
struct J2_extra_alignment {
    char a;
    J2 b;
};
struct J2_extra_alignment var154;
#pragma pack(1)
struct J2_extra_packed {
    J2 a;
};
#pragma pack()
struct J2_extra_required_alignment {
    char a;
    struct J2_extra_packed b;
};
struct J2_extra_required_alignment var155;
struct J2_extra_size {
    char a[sizeof(J2)+1];
    char b;
};
struct J2_extra_size var156;

typedef union {
    char c;
    long long d:1;
    char e;
} K2;
K2 var157;
struct K2_extra_alignment {
    char a;
    K2 b;
};
struct K2_extra_alignment var158;
#pragma pack(1)
struct K2_extra_packed {
    K2 a;
};
#pragma pack()
struct K2_extra_required_alignment {
    char a;
    struct K2_extra_packed b;
};
struct K2_extra_required_alignment var159;
struct K2_extra_size {
    char a[sizeof(K2)+1];
    char b;
};
struct K2_extra_size var160;

typedef union {
    char c;
    long long d:1 __attribute__((aligned(16)));
    char e;
} L2;
L2 var161;
struct L2_extra_alignment {
    char a;
    L2 b;
};
struct L2_extra_alignment var162;
#pragma pack(1)
struct L2_extra_packed {
    L2 a;
};
#pragma pack()
struct L2_extra_required_alignment {
    char a;
    struct L2_extra_packed b;
};
struct L2_extra_required_alignment var163;
struct L2_extra_size {
    char a[sizeof(L2)+1];
    char b;
};
struct L2_extra_size var164;

typedef union {
    char c;
    long long d:1 __attribute__((aligned(2))) __attribute__((packed));
    char e;
} M2;
M2 var165;
struct M2_extra_alignment {
    char a;
    M2 b;
};
struct M2_extra_alignment var166;
#pragma pack(1)
struct M2_extra_packed {
    M2 a;
};
#pragma pack()
struct M2_extra_required_alignment {
    char a;
    struct M2_extra_packed b;
};
struct M2_extra_required_alignment var167;
struct M2_extra_size {
    char a[sizeof(M2)+1];
    char b;
};
struct M2_extra_size var168;

#pragma pack(2)
typedef union {
    char c;
    long long d:1 __attribute__((aligned(4))) __attribute__((packed));
    char e;
} N2;
N2 var169;
#pragma pack()
struct N2_extra_alignment {
    char a;
    N2 b;
};
struct N2_extra_alignment var170;
#pragma pack(1)
struct N2_extra_packed {
    N2 a;
};
#pragma pack()
struct N2_extra_required_alignment {
    char a;
    struct N2_extra_packed b;
};
struct N2_extra_required_alignment var171;
struct N2_extra_size {
    char a[sizeof(N2)+1];
    char b;
};
struct N2_extra_size var172;

typedef union {
    char c;
    long long d:1 __attribute__((packed));
    char e;
} O2;
O2 var173;
struct O2_extra_alignment {
    char a;
    O2 b;
};
struct O2_extra_alignment var174;
#pragma pack(1)
struct O2_extra_packed {
    O2 a;
};
#pragma pack()
struct O2_extra_required_alignment {
    char a;
    struct O2_extra_packed b;
};
struct O2_extra_required_alignment var175;
struct O2_extra_size {
    char a[sizeof(O2)+1];
    char b;
};
struct O2_extra_size var176;

#pragma pack(2)
typedef union {
    char c;
    long long d:1;
    char e;
} P2;
P2 var177;
#pragma pack()
struct P2_extra_alignment {
    char a;
    P2 b;
};
struct P2_extra_alignment var178;
#pragma pack(1)
struct P2_extra_packed {
    P2 a;
};
#pragma pack()
struct P2_extra_required_alignment {
    char a;
    struct P2_extra_packed b;
};
struct P2_extra_required_alignment var179;
struct P2_extra_size {
    char a[sizeof(P2)+1];
    char b;
};
struct P2_extra_size var180;

typedef union {
    char c;
    char x:1;
    long long d:1;
    char e;
} Q2;
Q2 var181;
struct Q2_extra_alignment {
    char a;
    Q2 b;
};
struct Q2_extra_alignment var182;
#pragma pack(1)
struct Q2_extra_packed {
    Q2 a;
};
#pragma pack()
struct Q2_extra_required_alignment {
    char a;
    struct Q2_extra_packed b;
};
struct Q2_extra_required_alignment var183;
struct Q2_extra_size {
    char a[sizeof(Q2)+1];
    char b;
};
struct Q2_extra_size var184;

typedef union {
    char c;
    char x:1;
    long long:0 __attribute__((aligned(16)));
    char e;
} R2;
R2 var185;
struct R2_extra_alignment {
    char a;
    R2 b;
};
struct R2_extra_alignment var186;
#pragma pack(1)
struct R2_extra_packed {
    R2 a;
};
#pragma pack()
struct R2_extra_required_alignment {
    char a;
    struct R2_extra_packed b;
};
struct R2_extra_required_alignment var187;
struct R2_extra_size {
    char a[sizeof(R2)+1];
    char b;
};
struct R2_extra_size var188;

typedef union {
    char c;
    char x:1;
    long long:0 __attribute__((aligned(2))) __attribute__((packed));
    char e;
} S2;
S2 var189;
struct S2_extra_alignment {
    char a;
    S2 b;
};
struct S2_extra_alignment var190;
#pragma pack(1)
struct S2_extra_packed {
    S2 a;
};
#pragma pack()
struct S2_extra_required_alignment {
    char a;
    struct S2_extra_packed b;
};
struct S2_extra_required_alignment var191;
struct S2_extra_size {
    char a[sizeof(S2)+1];
    char b;
};
struct S2_extra_size var192;

#pragma pack(2)
typedef union {
    char c;
    char x:1;
    long long:0 __attribute__((aligned(4))) __attribute__((packed));
    char e;
} T2;
T2 var193;
#pragma pack()
struct T2_extra_alignment {
    char a;
    T2 b;
};
struct T2_extra_alignment var194;
#pragma pack(1)
struct T2_extra_packed {
    T2 a;
};
#pragma pack()
struct T2_extra_required_alignment {
    char a;
    struct T2_extra_packed b;
};
struct T2_extra_required_alignment var195;
struct T2_extra_size {
    char a[sizeof(T2)+1];
    char b;
};
struct T2_extra_size var196;

typedef union {
    char c;
    char x:1;
    long long:0 __attribute__((packed));
    char e;
} U2;
U2 var197;
struct U2_extra_alignment {
    char a;
    U2 b;
};
struct U2_extra_alignment var198;
#pragma pack(1)
struct U2_extra_packed {
    U2 a;
};
#pragma pack()
struct U2_extra_required_alignment {
    char a;
    struct U2_extra_packed b;
};
struct U2_extra_required_alignment var199;
struct U2_extra_size {
    char a[sizeof(U2)+1];
    char b;
};
struct U2_extra_size var200;

#pragma pack(2)
typedef union {
    char c;
    char x:1;
    long long:0;
    char e;
} V2;
V2 var201;
#pragma pack()
struct V2_extra_alignment {
    char a;
    V2 b;
};
struct V2_extra_alignment var202;
#pragma pack(1)
struct V2_extra_packed {
    V2 a;
};
#pragma pack()
struct V2_extra_required_alignment {
    char a;
    struct V2_extra_packed b;
};
struct V2_extra_required_alignment var203;
struct V2_extra_size {
    char a[sizeof(V2)+1];
    char b;
};
struct V2_extra_size var204;

typedef union {
    char c;
    char x:1;
    long long:0 __attribute__((aligned(16))) __attribute__((packed));
    char e;
} W2;
W2 var205;
struct W2_extra_alignment {
    char a;
    W2 b;
};
struct W2_extra_alignment var206;
#pragma pack(1)
struct W2_extra_packed {
    W2 a;
};
#pragma pack()
struct W2_extra_required_alignment {
    char a;
    struct W2_extra_packed b;
};
struct W2_extra_required_alignment var207;
struct W2_extra_size {
    char a[sizeof(W2)+1];
    char b;
};
struct W2_extra_size var208;

#pragma pack(1)
typedef union {
    char c;
    long long:0 __attribute__((aligned(16)));
    char e;
} W_2;
W_2 var209;
#pragma pack()
struct W_2_extra_alignment {
    char a;
    W_2 b;
};
struct W_2_extra_alignment var210;
#pragma pack(1)
struct W_2_extra_packed {
    W_2 a;
};
#pragma pack()
struct W_2_extra_required_alignment {
    char a;
    struct W_2_extra_packed b;
};
struct W_2_extra_required_alignment var211;
struct W_2_extra_size {
    char a[sizeof(W_2)+1];
    char b;
};
struct W_2_extra_size var212;

#pragma pack(2)
typedef union {
    char c;
    char x:1;
    long long:0 __attribute__((aligned(16))) __attribute__((packed));
    char e;
} X2;
X2 var213;
#pragma pack()
struct X2_extra_alignment {
    char a;
    X2 b;
};
struct X2_extra_alignment var214;
#pragma pack(1)
struct X2_extra_packed {
    X2 a;
};
#pragma pack()
struct X2_extra_required_alignment {
    char a;
    struct X2_extra_packed b;
};
struct X2_extra_required_alignment var215;
struct X2_extra_size {
    char a[sizeof(X2)+1];
    char b;
};
struct X2_extra_size var216;

typedef struct {
    char c:1;
    long long:0 __attribute__((packed));
    char d;
} Y;
Y var217;
struct Y_extra_alignment {
    char a;
    Y b;
};
struct Y_extra_alignment var218;
#pragma pack(1)
struct Y_extra_packed {
    Y a;
};
#pragma pack()
struct Y_extra_required_alignment {
    char a;
    struct Y_extra_packed b;
};
struct Y_extra_required_alignment var219;
struct Y_extra_size {
    char a[sizeof(Y)+1];
    char b;
};
struct Y_extra_size var220;

typedef union {
    char c:1;
    long long:0 __attribute__((packed));
    char d;
} Y2;
Y2 var221;
struct Y2_extra_alignment {
    char a;
    Y2 b;
};
struct Y2_extra_alignment var222;
#pragma pack(1)
struct Y2_extra_packed {
    Y2 a;
};
#pragma pack()
struct Y2_extra_required_alignment {
    char a;
    struct Y2_extra_packed b;
};
struct Y2_extra_required_alignment var223;
struct Y2_extra_size {
    char a[sizeof(Y2)+1];
    char b;
};
struct Y2_extra_size var224;

typedef struct {
    char c:1;
    long long:0 __attribute__((aligned(32)));
    char d:1;
} A3;
A3 var225;
struct A3_extra_alignment {
    char a;
    A3 b;
};
struct A3_extra_alignment var226;
#pragma pack(1)
struct A3_extra_packed {
    A3 a;
};
#pragma pack()
struct A3_extra_required_alignment {
    char a;
    struct A3_extra_packed b;
};
struct A3_extra_required_alignment var227;
struct A3_extra_size {
    char a[sizeof(A3)+1];
    char b;
};
struct A3_extra_size var228;

typedef char A4 __attribute__((aligned(32)));
A4 var229;
struct A4_extra_alignment {
    char a;
    A4 b;
};
struct A4_extra_alignment var230;
#pragma pack(1)
struct A4_extra_packed {
    A4 a;
};
#pragma pack()
struct A4_extra_required_alignment {
    char a;
    struct A4_extra_packed b;
};
struct A4_extra_required_alignment var231;
struct A4_extra_size {
    char a[sizeof(A4)+1];
    char b;
};
struct A4_extra_size var232;

typedef struct {
    char c:1;
    A4:0;
    char d:1;
} A5;
A5 var233;
struct A5_extra_alignment {
    char a;
    A5 b;
};
struct A5_extra_alignment var234;
#pragma pack(1)
struct A5_extra_packed {
    A5 a;
};
#pragma pack()
struct A5_extra_required_alignment {
    char a;
    struct A5_extra_packed b;
};
struct A5_extra_required_alignment var235;
struct A5_extra_size {
    char a[sizeof(A5)+1];
    char b;
};
struct A5_extra_size var236;

typedef struct {
    A4 a;
} A7;
A7 var237;
struct A7_extra_alignment {
    char a;
    A7 b;
};
struct A7_extra_alignment var238;
#pragma pack(1)
struct A7_extra_packed {
    A7 a;
};
#pragma pack()
struct A7_extra_required_alignment {
    char a;
    struct A7_extra_packed b;
};
struct A7_extra_required_alignment var239;
struct A7_extra_size {
    char a[sizeof(A7)+1];
    char b;
};
struct A7_extra_size var240;

typedef struct {
    char c;
    long i:31 __attribute__((packed));
    long j:2;
} A8;
A8 var241;
struct A8_extra_alignment {
    char a;
    A8 b;
};
struct A8_extra_alignment var242;
#pragma pack(1)
struct A8_extra_packed {
    A8 a;
};
#pragma pack()
struct A8_extra_required_alignment {
    char a;
    struct A8_extra_packed b;
};
struct A8_extra_required_alignment var243;
struct A8_extra_size {
    char a[sizeof(A8)+1];
    char b;
};
struct A8_extra_size var244;

typedef struct {
    char c;
    long i:31 __attribute__((packed));
    long j;
} A9;
A9 var245;
struct A9_extra_alignment {
    char a;
    A9 b;
};
struct A9_extra_alignment var246;
#pragma pack(1)
struct A9_extra_packed {
    A9 a;
};
#pragma pack()
struct A9_extra_required_alignment {
    char a;
    struct A9_extra_packed b;
};
struct A9_extra_required_alignment var247;
struct A9_extra_size {
    char a[sizeof(A9)+1];
    char b;
};
struct A9_extra_size var248;

typedef long A10 __attribute__((aligned(16)));
A10 var249;
struct A10_extra_alignment {
    char a;
    A10 b;
};
struct A10_extra_alignment var250;
#pragma pack(1)
struct A10_extra_packed {
    A10 a;
};
#pragma pack()
struct A10_extra_required_alignment {
    char a;
    struct A10_extra_packed b;
};
struct A10_extra_required_alignment var251;
struct A10_extra_size {
    char a[sizeof(A10)+1];
    char b;
};
struct A10_extra_size var252;

typedef struct {
    char c;
    long i:31 __attribute__((packed));
    A10 j:2;
} A11;
A11 var253;
struct A11_extra_alignment {
    char a;
    A11 b;
};
struct A11_extra_alignment var254;
#pragma pack(1)
struct A11_extra_packed {
    A11 a;
};
#pragma pack()
struct A11_extra_required_alignment {
    char a;
    struct A11_extra_packed b;
};
struct A11_extra_required_alignment var255;
struct A11_extra_size {
    char a[sizeof(A11)+1];
    char b;
};
struct A11_extra_size var256;

typedef struct {
    char c;
    long i:31 __attribute__((packed));
    A10 j;
} A12;
A12 var257;
struct A12_extra_alignment {
    char a;
    A12 b;
};
struct A12_extra_alignment var258;
#pragma pack(1)
struct A12_extra_packed {
    A12 a;
};
#pragma pack()
struct A12_extra_required_alignment {
    char a;
    struct A12_extra_packed b;
};
struct A12_extra_required_alignment var259;
struct A12_extra_size {
    char a[sizeof(A12)+1];
    char b;
};
struct A12_extra_size var260;

typedef struct {
    char c;
    long i:1;
    long j:1 __attribute__((aligned(16)));
    char d;
} A13;
A13 var261;
struct A13_extra_alignment {
    char a;
    A13 b;
};
struct A13_extra_alignment var262;
#pragma pack(1)
struct A13_extra_packed {
    A13 a;
};
#pragma pack()
struct A13_extra_required_alignment {
    char a;
    struct A13_extra_packed b;
};
struct A13_extra_required_alignment var263;
struct A13_extra_size {
    char a[sizeof(A13)+1];
    char b;
};
struct A13_extra_size var264;


// MAPPING|ONE|aarch64-generic-macos-none:Clang|aarch64-generic-ios-none:Clang|aarch64-generic-maccatalyst-none:Clang|aarch64-generic-tvos-none:Clang|powerpc64-ppc64-freebsd-gnu:Clang|riscv64-baseline_rv64-other-eabi:Clang|sparc64-v9-netbsd-gnu:Clang|sparc64-v9-openbsd-gnu:Clang|sparc64-v9-illumos-eabi:Clang|x86_64-x86_64-maccatalyst-none:Clang|x86_64-x86_64-ios-none:Clang|x86_64-x86_64-macos-none:Clang|x86_64-x86_64-tvos-none:Clang|x86_64-x86_64-other-eabi:Clang|x86_64-x86_64-fuchsia-gnu:Clang|x86_64-x86_64-linux-android:Clang|x86_64-x86_64-illumos-eabi:Clang|x86_64-x86_64-dragonfly-eabi:Clang|x86_64-x86_64-freebsd-gnu:Clang|x86_64-x86_64-haiku-gnu:Clang|x86_64-x86_64-hermit-eabi:Clang|x86_64-x86_64-netbsd-gnu:Clang|x86_64-x86_64-openbsd-gnu:Clang|END
// repr targets Aarch64AppleMacosx|Some("aarch64-generic-macos-none") Arm64AppleIos|Some("aarch64-generic-ios-none") Arm64AppleIosMacabi|Some("aarch64-generic-maccatalyst-none") Arm64AppleTvos|Some("aarch64-generic-tvos-none") Powerpc64UnknownFreebsd|Some("powerpc64-ppc64-freebsd-gnu") Riscv64|Some("riscv64-baseline_rv64-other-eabi") Sparc64UnknownNetbsd|Some("sparc64-v9-netbsd-gnu") Sparc64UnknownOpenbsd|Some("sparc64-v9-openbsd-gnu") Sparcv9Sunillumos|Some("sparc64-v9-illumos-eabi") X86_64AppleIosMacabi|Some("x86_64-x86_64-maccatalyst-none") X86_64AppleIos|Some("x86_64-x86_64-ios-none") X86_64AppleMacosx|Some("x86_64-x86_64-macos-none") X86_64AppleTvos|Some("x86_64-x86_64-tvos-none") X86_64Elf|Some("x86_64-x86_64-other-eabi") X86_64Fuchsia|Some("x86_64-x86_64-fuchsia-gnu") X86_64LinuxAndroid|Some("x86_64-x86_64-linux-android") X86_64Pcillumos|Some("x86_64-x86_64-illumos-eabi") X86_64RumprunNetbsd|None X86_64UnknownDragonfly|Some("x86_64-x86_64-dragonfly-eabi") X86_64UnknownFreebsd|Some("x86_64-x86_64-freebsd-gnu") X86_64UnknownHaiku|Some("x86_64-x86_64-haiku-gnu") X86_64UnknownHermit|Some("x86_64-x86_64-hermit-eabi") X86_64UnknownL4reUclibc|None X86_64UnknownNetbsd|Some("x86_64-x86_64-netbsd-gnu") X86_64UnknownOpenbsd|Some("x86_64-x86_64-openbsd-gnu") X86_64UnknownRedox|None 
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
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A,d) == 0, "");
#endif
_Static_assert(sizeof(A_) == 5, "");
_Static_assert(_Alignof(A_) == 1, "");
_Static_assert(sizeof(struct A__extra_alignment) == 6, "");
_Static_assert(_Alignof(struct A__extra_alignment) == 1, "");
_Static_assert(sizeof(struct A__extra_packed) == 5, "");
_Static_assert(_Alignof(struct A__extra_packed) == 1, "");
_Static_assert(sizeof(struct A__extra_required_alignment) == 6, "");
_Static_assert(_Alignof(struct A__extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A__extra_size) == 7, "");
_Static_assert(_Alignof(struct A__extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_,d) == 32, "");
#endif
_Static_assert(sizeof(B) == 1, "");
_Static_assert(_Alignof(B) == 1, "");
_Static_assert(sizeof(struct B_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct B_extra_alignment) == 1, "");
_Static_assert(sizeof(struct B_extra_packed) == 1, "");
_Static_assert(_Alignof(struct B_extra_packed) == 1, "");
_Static_assert(sizeof(struct B_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct B_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B_extra_size) == 3, "");
_Static_assert(_Alignof(struct B_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B,d) == 0, "");
#endif
_Static_assert(sizeof(B_) == 9, "");
_Static_assert(_Alignof(B_) == 1, "");
_Static_assert(sizeof(struct B__extra_alignment) == 10, "");
_Static_assert(_Alignof(struct B__extra_alignment) == 1, "");
_Static_assert(sizeof(struct B__extra_packed) == 9, "");
_Static_assert(_Alignof(struct B__extra_packed) == 1, "");
_Static_assert(sizeof(struct B__extra_required_alignment) == 10, "");
_Static_assert(_Alignof(struct B__extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B__extra_size) == 11, "");
_Static_assert(_Alignof(struct B__extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B_,d) == 64, "");
#endif
_Static_assert(sizeof(C) == 1, "");
_Static_assert(_Alignof(C) == 1, "");
_Static_assert(sizeof(struct C_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct C_extra_alignment) == 1, "");
_Static_assert(sizeof(struct C_extra_packed) == 1, "");
_Static_assert(_Alignof(struct C_extra_packed) == 1, "");
_Static_assert(sizeof(struct C_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct C_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct C_extra_size) == 3, "");
_Static_assert(_Alignof(struct C_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(C,d) == 0, "");
#endif
_Static_assert(sizeof(C_) == 9, "");
_Static_assert(_Alignof(C_) == 1, "");
_Static_assert(sizeof(struct C__extra_alignment) == 10, "");
_Static_assert(_Alignof(struct C__extra_alignment) == 1, "");
_Static_assert(sizeof(struct C__extra_packed) == 9, "");
_Static_assert(_Alignof(struct C__extra_packed) == 1, "");
_Static_assert(sizeof(struct C__extra_required_alignment) == 10, "");
_Static_assert(_Alignof(struct C__extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct C__extra_size) == 11, "");
_Static_assert(_Alignof(struct C__extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(C_,d) == 64, "");
#endif
_Static_assert(sizeof(D) == 24, "");
_Static_assert(_Alignof(D) == 8, "");
_Static_assert(sizeof(struct D_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct D_extra_alignment) == 8, "");
_Static_assert(sizeof(struct D_extra_packed) == 24, "");
_Static_assert(_Alignof(struct D_extra_packed) == 1, "");
_Static_assert(sizeof(struct D_extra_required_alignment) == 25, "");
_Static_assert(_Alignof(struct D_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct D_extra_size) == 26, "");
_Static_assert(_Alignof(struct D_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(D,d) == 64, "");
_Static_assert(__builtin_bitoffsetof(D,e) == 128, "");
#endif
_Static_assert(sizeof(F) == 32, "");
_Static_assert(_Alignof(F) == 16, "");
_Static_assert(sizeof(struct F_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct F_extra_alignment) == 16, "");
_Static_assert(sizeof(struct F_extra_packed) == 32, "");
_Static_assert(_Alignof(struct F_extra_packed) == 1, "");
_Static_assert(sizeof(struct F_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct F_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct F_extra_size) == 34, "");
_Static_assert(_Alignof(struct F_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(F,d) == 128, "");
_Static_assert(__builtin_bitoffsetof(F,e) == 192, "");
#endif
_Static_assert(sizeof(G) == 12, "");
_Static_assert(_Alignof(G) == 2, "");
_Static_assert(sizeof(struct G_extra_alignment) == 14, "");
_Static_assert(_Alignof(struct G_extra_alignment) == 2, "");
_Static_assert(sizeof(struct G_extra_packed) == 12, "");
_Static_assert(_Alignof(struct G_extra_packed) == 1, "");
_Static_assert(sizeof(struct G_extra_required_alignment) == 13, "");
_Static_assert(_Alignof(struct G_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct G_extra_size) == 14, "");
_Static_assert(_Alignof(struct G_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(G,d) == 16, "");
_Static_assert(__builtin_bitoffsetof(G,e) == 80, "");
#endif
_Static_assert(sizeof(H) == 12, "");
_Static_assert(_Alignof(H) == 2, "");
_Static_assert(sizeof(struct H_extra_alignment) == 14, "");
_Static_assert(_Alignof(struct H_extra_alignment) == 2, "");
_Static_assert(sizeof(struct H_extra_packed) == 12, "");
_Static_assert(_Alignof(struct H_extra_packed) == 1, "");
_Static_assert(sizeof(struct H_extra_required_alignment) == 13, "");
_Static_assert(_Alignof(struct H_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct H_extra_size) == 14, "");
_Static_assert(_Alignof(struct H_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(H,d) == 16, "");
_Static_assert(__builtin_bitoffsetof(H,e) == 80, "");
#endif
_Static_assert(sizeof(I) == 10, "");
_Static_assert(_Alignof(I) == 1, "");
_Static_assert(sizeof(struct I_extra_alignment) == 11, "");
_Static_assert(_Alignof(struct I_extra_alignment) == 1, "");
_Static_assert(sizeof(struct I_extra_packed) == 10, "");
_Static_assert(_Alignof(struct I_extra_packed) == 1, "");
_Static_assert(sizeof(struct I_extra_required_alignment) == 11, "");
_Static_assert(_Alignof(struct I_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct I_extra_size) == 12, "");
_Static_assert(_Alignof(struct I_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(I,d) == 8, "");
_Static_assert(__builtin_bitoffsetof(I,e) == 72, "");
#endif
_Static_assert(sizeof(J) == 12, "");
_Static_assert(_Alignof(J) == 2, "");
_Static_assert(sizeof(struct J_extra_alignment) == 14, "");
_Static_assert(_Alignof(struct J_extra_alignment) == 2, "");
_Static_assert(sizeof(struct J_extra_packed) == 12, "");
_Static_assert(_Alignof(struct J_extra_packed) == 1, "");
_Static_assert(sizeof(struct J_extra_required_alignment) == 13, "");
_Static_assert(_Alignof(struct J_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct J_extra_size) == 14, "");
_Static_assert(_Alignof(struct J_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(J,d) == 16, "");
_Static_assert(__builtin_bitoffsetof(J,e) == 80, "");
#endif
_Static_assert(sizeof(K) == 8, "");
_Static_assert(_Alignof(K) == 8, "");
_Static_assert(sizeof(struct K_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct K_extra_alignment) == 8, "");
_Static_assert(sizeof(struct K_extra_packed) == 8, "");
_Static_assert(_Alignof(struct K_extra_packed) == 1, "");
_Static_assert(sizeof(struct K_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct K_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct K_extra_size) == 10, "");
_Static_assert(_Alignof(struct K_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(K,d) == 8, "");
_Static_assert(__builtin_bitoffsetof(K,e) == 16, "");
#endif
_Static_assert(sizeof(L) == 32, "");
_Static_assert(_Alignof(L) == 16, "");
_Static_assert(sizeof(struct L_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct L_extra_alignment) == 16, "");
_Static_assert(sizeof(struct L_extra_packed) == 32, "");
_Static_assert(_Alignof(struct L_extra_packed) == 1, "");
_Static_assert(sizeof(struct L_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct L_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct L_extra_size) == 34, "");
_Static_assert(_Alignof(struct L_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(L,d) == 128, "");
_Static_assert(__builtin_bitoffsetof(L,e) == 136, "");
#endif
_Static_assert(sizeof(M) == 4, "");
_Static_assert(_Alignof(M) == 2, "");
_Static_assert(sizeof(struct M_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct M_extra_alignment) == 2, "");
_Static_assert(sizeof(struct M_extra_packed) == 4, "");
_Static_assert(_Alignof(struct M_extra_packed) == 1, "");
_Static_assert(sizeof(struct M_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct M_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct M_extra_size) == 6, "");
_Static_assert(_Alignof(struct M_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(M,d) == 16, "");
_Static_assert(__builtin_bitoffsetof(M,e) == 24, "");
#endif
_Static_assert(sizeof(N) == 4, "");
_Static_assert(_Alignof(N) == 2, "");
_Static_assert(sizeof(struct N_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct N_extra_alignment) == 2, "");
_Static_assert(sizeof(struct N_extra_packed) == 4, "");
_Static_assert(_Alignof(struct N_extra_packed) == 1, "");
_Static_assert(sizeof(struct N_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct N_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct N_extra_size) == 6, "");
_Static_assert(_Alignof(struct N_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(N,d) == 8, "");
_Static_assert(__builtin_bitoffsetof(N,e) == 16, "");
#endif
_Static_assert(sizeof(O) == 3, "");
_Static_assert(_Alignof(O) == 1, "");
_Static_assert(sizeof(struct O_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct O_extra_alignment) == 1, "");
_Static_assert(sizeof(struct O_extra_packed) == 3, "");
_Static_assert(_Alignof(struct O_extra_packed) == 1, "");
_Static_assert(sizeof(struct O_extra_required_alignment) == 4, "");
_Static_assert(_Alignof(struct O_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct O_extra_size) == 5, "");
_Static_assert(_Alignof(struct O_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(O,d) == 8, "");
_Static_assert(__builtin_bitoffsetof(O,e) == 16, "");
#endif
_Static_assert(sizeof(P) == 4, "");
_Static_assert(_Alignof(P) == 2, "");
_Static_assert(sizeof(struct P_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct P_extra_alignment) == 2, "");
_Static_assert(sizeof(struct P_extra_packed) == 4, "");
_Static_assert(_Alignof(struct P_extra_packed) == 1, "");
_Static_assert(sizeof(struct P_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct P_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct P_extra_size) == 6, "");
_Static_assert(_Alignof(struct P_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(P,d) == 8, "");
_Static_assert(__builtin_bitoffsetof(P,e) == 16, "");
#endif
_Static_assert(sizeof(Q) == 8, "");
_Static_assert(_Alignof(Q) == 8, "");
_Static_assert(sizeof(struct Q_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct Q_extra_alignment) == 8, "");
_Static_assert(sizeof(struct Q_extra_packed) == 8, "");
_Static_assert(_Alignof(struct Q_extra_packed) == 1, "");
_Static_assert(sizeof(struct Q_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct Q_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct Q_extra_size) == 10, "");
_Static_assert(_Alignof(struct Q_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(Q,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(Q,d) == 9, "");
_Static_assert(__builtin_bitoffsetof(Q,e) == 16, "");
#endif
_Static_assert(sizeof(R) == 17, "");
_Static_assert(_Alignof(R) == 1, "");
_Static_assert(sizeof(struct R_extra_alignment) == 18, "");
_Static_assert(_Alignof(struct R_extra_alignment) == 1, "");
_Static_assert(sizeof(struct R_extra_packed) == 17, "");
_Static_assert(_Alignof(struct R_extra_packed) == 1, "");
_Static_assert(sizeof(struct R_extra_required_alignment) == 18, "");
_Static_assert(_Alignof(struct R_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct R_extra_size) == 19, "");
_Static_assert(_Alignof(struct R_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(R,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(R,e) == 128, "");
#endif
_Static_assert(sizeof(S) == 9, "");
_Static_assert(_Alignof(S) == 1, "");
_Static_assert(sizeof(struct S_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct S_extra_alignment) == 1, "");
_Static_assert(sizeof(struct S_extra_packed) == 9, "");
_Static_assert(_Alignof(struct S_extra_packed) == 1, "");
_Static_assert(sizeof(struct S_extra_required_alignment) == 10, "");
_Static_assert(_Alignof(struct S_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct S_extra_size) == 11, "");
_Static_assert(_Alignof(struct S_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(S,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(S,e) == 64, "");
#endif
_Static_assert(sizeof(T) == 9, "");
_Static_assert(_Alignof(T) == 1, "");
_Static_assert(sizeof(struct T_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct T_extra_alignment) == 1, "");
_Static_assert(sizeof(struct T_extra_packed) == 9, "");
_Static_assert(_Alignof(struct T_extra_packed) == 1, "");
_Static_assert(sizeof(struct T_extra_required_alignment) == 10, "");
_Static_assert(_Alignof(struct T_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct T_extra_size) == 11, "");
_Static_assert(_Alignof(struct T_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(T,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(T,e) == 64, "");
#endif
_Static_assert(sizeof(U) == 9, "");
_Static_assert(_Alignof(U) == 1, "");
_Static_assert(sizeof(struct U_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct U_extra_alignment) == 1, "");
_Static_assert(sizeof(struct U_extra_packed) == 9, "");
_Static_assert(_Alignof(struct U_extra_packed) == 1, "");
_Static_assert(sizeof(struct U_extra_required_alignment) == 10, "");
_Static_assert(_Alignof(struct U_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct U_extra_size) == 11, "");
_Static_assert(_Alignof(struct U_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(U,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(U,e) == 64, "");
#endif
_Static_assert(sizeof(V) == 9, "");
_Static_assert(_Alignof(V) == 1, "");
_Static_assert(sizeof(struct V_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct V_extra_alignment) == 1, "");
_Static_assert(sizeof(struct V_extra_packed) == 9, "");
_Static_assert(_Alignof(struct V_extra_packed) == 1, "");
_Static_assert(sizeof(struct V_extra_required_alignment) == 10, "");
_Static_assert(_Alignof(struct V_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct V_extra_size) == 11, "");
_Static_assert(_Alignof(struct V_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(V,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(V,e) == 64, "");
#endif
_Static_assert(sizeof(W) == 17, "");
_Static_assert(_Alignof(W) == 1, "");
_Static_assert(sizeof(struct W_extra_alignment) == 18, "");
_Static_assert(_Alignof(struct W_extra_alignment) == 1, "");
_Static_assert(sizeof(struct W_extra_packed) == 17, "");
_Static_assert(_Alignof(struct W_extra_packed) == 1, "");
_Static_assert(sizeof(struct W_extra_required_alignment) == 18, "");
_Static_assert(_Alignof(struct W_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct W_extra_size) == 19, "");
_Static_assert(_Alignof(struct W_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(W,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(W,e) == 128, "");
#endif
_Static_assert(sizeof(W_) == 17, "");
_Static_assert(_Alignof(W_) == 1, "");
_Static_assert(sizeof(struct W__extra_alignment) == 18, "");
_Static_assert(_Alignof(struct W__extra_alignment) == 1, "");
_Static_assert(sizeof(struct W__extra_packed) == 17, "");
_Static_assert(_Alignof(struct W__extra_packed) == 1, "");
_Static_assert(sizeof(struct W__extra_required_alignment) == 18, "");
_Static_assert(_Alignof(struct W__extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct W__extra_size) == 19, "");
_Static_assert(_Alignof(struct W__extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(W_,e) == 128, "");
#endif
_Static_assert(sizeof(X) == 17, "");
_Static_assert(_Alignof(X) == 1, "");
_Static_assert(sizeof(struct X_extra_alignment) == 18, "");
_Static_assert(_Alignof(struct X_extra_alignment) == 1, "");
_Static_assert(sizeof(struct X_extra_packed) == 17, "");
_Static_assert(_Alignof(struct X_extra_packed) == 1, "");
_Static_assert(sizeof(struct X_extra_required_alignment) == 18, "");
_Static_assert(_Alignof(struct X_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct X_extra_size) == 19, "");
_Static_assert(_Alignof(struct X_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(X,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(X,e) == 128, "");
#endif
_Static_assert(sizeof(A2) == 1, "");
_Static_assert(_Alignof(A2) == 1, "");
_Static_assert(sizeof(struct A2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct A2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct A2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct A2_extra_packed) == 1, "");
_Static_assert(sizeof(struct A2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct A2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A2_extra_size) == 3, "");
_Static_assert(_Alignof(struct A2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A2,d) == 0, "");
#endif
_Static_assert(sizeof(A_2) == 1, "");
_Static_assert(_Alignof(A_2) == 1, "");
_Static_assert(sizeof(struct A_2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct A_2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct A_2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct A_2_extra_packed) == 1, "");
_Static_assert(sizeof(struct A_2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct A_2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A_2_extra_size) == 3, "");
_Static_assert(_Alignof(struct A_2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_2,d) == 0, "");
#endif
_Static_assert(sizeof(B2) == 1, "");
_Static_assert(_Alignof(B2) == 1, "");
_Static_assert(sizeof(struct B2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct B2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct B2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct B2_extra_packed) == 1, "");
_Static_assert(sizeof(struct B2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct B2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B2_extra_size) == 3, "");
_Static_assert(_Alignof(struct B2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B2,d) == 0, "");
#endif
_Static_assert(sizeof(B_2) == 1, "");
_Static_assert(_Alignof(B_2) == 1, "");
_Static_assert(sizeof(struct B_2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct B_2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct B_2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct B_2_extra_packed) == 1, "");
_Static_assert(sizeof(struct B_2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct B_2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B_2_extra_size) == 3, "");
_Static_assert(_Alignof(struct B_2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B_2,d) == 0, "");
#endif
_Static_assert(sizeof(C2) == 1, "");
_Static_assert(_Alignof(C2) == 1, "");
_Static_assert(sizeof(struct C2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct C2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct C2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct C2_extra_packed) == 1, "");
_Static_assert(sizeof(struct C2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct C2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct C2_extra_size) == 3, "");
_Static_assert(_Alignof(struct C2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(C2,d) == 0, "");
#endif
_Static_assert(sizeof(C22) == 1, "");
_Static_assert(_Alignof(C22) == 1, "");
_Static_assert(sizeof(struct C22_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct C22_extra_alignment) == 1, "");
_Static_assert(sizeof(struct C22_extra_packed) == 1, "");
_Static_assert(_Alignof(struct C22_extra_packed) == 1, "");
_Static_assert(sizeof(struct C22_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct C22_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct C22_extra_size) == 3, "");
_Static_assert(_Alignof(struct C22_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(C22,d) == 0, "");
#endif
_Static_assert(sizeof(D2) == 8, "");
_Static_assert(_Alignof(D2) == 8, "");
_Static_assert(sizeof(struct D2_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct D2_extra_alignment) == 8, "");
_Static_assert(sizeof(struct D2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct D2_extra_packed) == 1, "");
_Static_assert(sizeof(struct D2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct D2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct D2_extra_size) == 10, "");
_Static_assert(_Alignof(struct D2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(D2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(D2,e) == 0, "");
#endif
_Static_assert(sizeof(F2) == 16, "");
_Static_assert(_Alignof(F2) == 16, "");
_Static_assert(sizeof(struct F2_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct F2_extra_alignment) == 16, "");
_Static_assert(sizeof(struct F2_extra_packed) == 16, "");
_Static_assert(_Alignof(struct F2_extra_packed) == 1, "");
_Static_assert(sizeof(struct F2_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct F2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct F2_extra_size) == 18, "");
_Static_assert(_Alignof(struct F2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(F2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(F2,e) == 0, "");
#endif
_Static_assert(sizeof(G2) == 8, "");
_Static_assert(_Alignof(G2) == 2, "");
_Static_assert(sizeof(struct G2_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct G2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct G2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct G2_extra_packed) == 1, "");
_Static_assert(sizeof(struct G2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct G2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct G2_extra_size) == 10, "");
_Static_assert(_Alignof(struct G2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(G2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(G2,e) == 0, "");
#endif
_Static_assert(sizeof(H2) == 8, "");
_Static_assert(_Alignof(H2) == 2, "");
_Static_assert(sizeof(struct H2_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct H2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct H2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct H2_extra_packed) == 1, "");
_Static_assert(sizeof(struct H2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct H2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct H2_extra_size) == 10, "");
_Static_assert(_Alignof(struct H2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(H2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(H2,e) == 0, "");
#endif
_Static_assert(sizeof(I2) == 8, "");
_Static_assert(_Alignof(I2) == 1, "");
_Static_assert(sizeof(struct I2_extra_alignment) == 9, "");
_Static_assert(_Alignof(struct I2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct I2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct I2_extra_packed) == 1, "");
_Static_assert(sizeof(struct I2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct I2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct I2_extra_size) == 10, "");
_Static_assert(_Alignof(struct I2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(I2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(I2,e) == 0, "");
#endif
_Static_assert(sizeof(J2) == 8, "");
_Static_assert(_Alignof(J2) == 2, "");
_Static_assert(sizeof(struct J2_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct J2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct J2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct J2_extra_packed) == 1, "");
_Static_assert(sizeof(struct J2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct J2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct J2_extra_size) == 10, "");
_Static_assert(_Alignof(struct J2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(J2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(J2,e) == 0, "");
#endif
_Static_assert(sizeof(K2) == 8, "");
_Static_assert(_Alignof(K2) == 8, "");
_Static_assert(sizeof(struct K2_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct K2_extra_alignment) == 8, "");
_Static_assert(sizeof(struct K2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct K2_extra_packed) == 1, "");
_Static_assert(sizeof(struct K2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct K2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct K2_extra_size) == 10, "");
_Static_assert(_Alignof(struct K2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(K2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(K2,e) == 0, "");
#endif
_Static_assert(sizeof(L2) == 16, "");
_Static_assert(_Alignof(L2) == 16, "");
_Static_assert(sizeof(struct L2_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct L2_extra_alignment) == 16, "");
_Static_assert(sizeof(struct L2_extra_packed) == 16, "");
_Static_assert(_Alignof(struct L2_extra_packed) == 1, "");
_Static_assert(sizeof(struct L2_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct L2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct L2_extra_size) == 18, "");
_Static_assert(_Alignof(struct L2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(L2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(L2,e) == 0, "");
#endif
_Static_assert(sizeof(M2) == 2, "");
_Static_assert(_Alignof(M2) == 2, "");
_Static_assert(sizeof(struct M2_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct M2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct M2_extra_packed) == 2, "");
_Static_assert(_Alignof(struct M2_extra_packed) == 1, "");
_Static_assert(sizeof(struct M2_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct M2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct M2_extra_size) == 4, "");
_Static_assert(_Alignof(struct M2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(M2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(M2,e) == 0, "");
#endif
_Static_assert(sizeof(N2) == 2, "");
_Static_assert(_Alignof(N2) == 2, "");
_Static_assert(sizeof(struct N2_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct N2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct N2_extra_packed) == 2, "");
_Static_assert(_Alignof(struct N2_extra_packed) == 1, "");
_Static_assert(sizeof(struct N2_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct N2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct N2_extra_size) == 4, "");
_Static_assert(_Alignof(struct N2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(N2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(N2,e) == 0, "");
#endif
_Static_assert(sizeof(O2) == 1, "");
_Static_assert(_Alignof(O2) == 1, "");
_Static_assert(sizeof(struct O2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct O2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct O2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct O2_extra_packed) == 1, "");
_Static_assert(sizeof(struct O2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct O2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct O2_extra_size) == 3, "");
_Static_assert(_Alignof(struct O2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(O2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(O2,e) == 0, "");
#endif
_Static_assert(sizeof(P2) == 2, "");
_Static_assert(_Alignof(P2) == 2, "");
_Static_assert(sizeof(struct P2_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct P2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct P2_extra_packed) == 2, "");
_Static_assert(_Alignof(struct P2_extra_packed) == 1, "");
_Static_assert(sizeof(struct P2_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct P2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct P2_extra_size) == 4, "");
_Static_assert(_Alignof(struct P2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(P2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(P2,e) == 0, "");
#endif
_Static_assert(sizeof(Q2) == 8, "");
_Static_assert(_Alignof(Q2) == 8, "");
_Static_assert(sizeof(struct Q2_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct Q2_extra_alignment) == 8, "");
_Static_assert(sizeof(struct Q2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct Q2_extra_packed) == 1, "");
_Static_assert(sizeof(struct Q2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct Q2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct Q2_extra_size) == 10, "");
_Static_assert(_Alignof(struct Q2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(Q2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(Q2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(Q2,e) == 0, "");
#endif
_Static_assert(sizeof(R2) == 1, "");
_Static_assert(_Alignof(R2) == 1, "");
_Static_assert(sizeof(struct R2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct R2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct R2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct R2_extra_packed) == 1, "");
_Static_assert(sizeof(struct R2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct R2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct R2_extra_size) == 3, "");
_Static_assert(_Alignof(struct R2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(R2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(R2,e) == 0, "");
#endif
_Static_assert(sizeof(S2) == 1, "");
_Static_assert(_Alignof(S2) == 1, "");
_Static_assert(sizeof(struct S2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct S2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct S2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct S2_extra_packed) == 1, "");
_Static_assert(sizeof(struct S2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct S2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct S2_extra_size) == 3, "");
_Static_assert(_Alignof(struct S2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(S2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(S2,e) == 0, "");
#endif
_Static_assert(sizeof(T2) == 1, "");
_Static_assert(_Alignof(T2) == 1, "");
_Static_assert(sizeof(struct T2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct T2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct T2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct T2_extra_packed) == 1, "");
_Static_assert(sizeof(struct T2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct T2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct T2_extra_size) == 3, "");
_Static_assert(_Alignof(struct T2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(T2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(T2,e) == 0, "");
#endif
_Static_assert(sizeof(U2) == 1, "");
_Static_assert(_Alignof(U2) == 1, "");
_Static_assert(sizeof(struct U2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct U2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct U2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct U2_extra_packed) == 1, "");
_Static_assert(sizeof(struct U2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct U2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct U2_extra_size) == 3, "");
_Static_assert(_Alignof(struct U2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(U2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(U2,e) == 0, "");
#endif
_Static_assert(sizeof(V2) == 1, "");
_Static_assert(_Alignof(V2) == 1, "");
_Static_assert(sizeof(struct V2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct V2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct V2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct V2_extra_packed) == 1, "");
_Static_assert(sizeof(struct V2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct V2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct V2_extra_size) == 3, "");
_Static_assert(_Alignof(struct V2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(V2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(V2,e) == 0, "");
#endif
_Static_assert(sizeof(W2) == 1, "");
_Static_assert(_Alignof(W2) == 1, "");
_Static_assert(sizeof(struct W2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct W2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct W2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct W2_extra_packed) == 1, "");
_Static_assert(sizeof(struct W2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct W2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct W2_extra_size) == 3, "");
_Static_assert(_Alignof(struct W2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(W2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(W2,e) == 0, "");
#endif
_Static_assert(sizeof(W_2) == 1, "");
_Static_assert(_Alignof(W_2) == 1, "");
_Static_assert(sizeof(struct W_2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct W_2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct W_2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct W_2_extra_packed) == 1, "");
_Static_assert(sizeof(struct W_2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct W_2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct W_2_extra_size) == 3, "");
_Static_assert(_Alignof(struct W_2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(W_2,e) == 0, "");
#endif
_Static_assert(sizeof(X2) == 1, "");
_Static_assert(_Alignof(X2) == 1, "");
_Static_assert(sizeof(struct X2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct X2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct X2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct X2_extra_packed) == 1, "");
_Static_assert(sizeof(struct X2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct X2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct X2_extra_size) == 3, "");
_Static_assert(_Alignof(struct X2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(X2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(X2,e) == 0, "");
#endif
_Static_assert(sizeof(Y) == 9, "");
_Static_assert(_Alignof(Y) == 1, "");
_Static_assert(sizeof(struct Y_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct Y_extra_alignment) == 1, "");
_Static_assert(sizeof(struct Y_extra_packed) == 9, "");
_Static_assert(_Alignof(struct Y_extra_packed) == 1, "");
_Static_assert(sizeof(struct Y_extra_required_alignment) == 10, "");
_Static_assert(_Alignof(struct Y_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct Y_extra_size) == 11, "");
_Static_assert(_Alignof(struct Y_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(Y,d) == 64, "");
#endif
_Static_assert(sizeof(Y2) == 1, "");
_Static_assert(_Alignof(Y2) == 1, "");
_Static_assert(sizeof(struct Y2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct Y2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct Y2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct Y2_extra_packed) == 1, "");
_Static_assert(sizeof(struct Y2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct Y2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct Y2_extra_size) == 3, "");
_Static_assert(_Alignof(struct Y2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(Y2,d) == 0, "");
#endif
_Static_assert(sizeof(A3) == 33, "");
_Static_assert(_Alignof(A3) == 1, "");
_Static_assert(sizeof(struct A3_extra_alignment) == 34, "");
_Static_assert(_Alignof(struct A3_extra_alignment) == 1, "");
_Static_assert(sizeof(struct A3_extra_packed) == 33, "");
_Static_assert(_Alignof(struct A3_extra_packed) == 1, "");
_Static_assert(sizeof(struct A3_extra_required_alignment) == 34, "");
_Static_assert(_Alignof(struct A3_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A3_extra_size) == 35, "");
_Static_assert(_Alignof(struct A3_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A3,d) == 256, "");
#endif
_Static_assert(sizeof(A4) == 1, "");
_Static_assert(_Alignof(A4) == 32, "");
_Static_assert(sizeof(struct A4_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct A4_extra_alignment) == 32, "");
_Static_assert(sizeof(struct A4_extra_packed) == 1, "");
_Static_assert(_Alignof(struct A4_extra_packed) == 1, "");
_Static_assert(sizeof(struct A4_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct A4_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A4_extra_size) == 3, "");
_Static_assert(_Alignof(struct A4_extra_size) == 1, "");
_Static_assert(sizeof(A5) == 33, "");
_Static_assert(_Alignof(A5) == 1, "");
_Static_assert(sizeof(struct A5_extra_alignment) == 34, "");
_Static_assert(_Alignof(struct A5_extra_alignment) == 1, "");
_Static_assert(sizeof(struct A5_extra_packed) == 33, "");
_Static_assert(_Alignof(struct A5_extra_packed) == 1, "");
_Static_assert(sizeof(struct A5_extra_required_alignment) == 34, "");
_Static_assert(_Alignof(struct A5_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A5_extra_size) == 35, "");
_Static_assert(_Alignof(struct A5_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A5,d) == 256, "");
#endif
_Static_assert(sizeof(A7) == 32, "");
_Static_assert(_Alignof(A7) == 32, "");
_Static_assert(sizeof(struct A7_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct A7_extra_alignment) == 32, "");
_Static_assert(sizeof(struct A7_extra_packed) == 32, "");
_Static_assert(_Alignof(struct A7_extra_packed) == 1, "");
_Static_assert(sizeof(struct A7_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct A7_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A7_extra_size) == 34, "");
_Static_assert(_Alignof(struct A7_extra_size) == 1, "");
_Static_assert(sizeof(A8) == 8, "");
_Static_assert(_Alignof(A8) == 8, "");
_Static_assert(sizeof(struct A8_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct A8_extra_alignment) == 8, "");
_Static_assert(sizeof(struct A8_extra_packed) == 8, "");
_Static_assert(_Alignof(struct A8_extra_packed) == 1, "");
_Static_assert(sizeof(struct A8_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct A8_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A8_extra_size) == 10, "");
_Static_assert(_Alignof(struct A8_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A8,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A8,j) == 39, "");
#endif
_Static_assert(sizeof(A9) == 16, "");
_Static_assert(_Alignof(A9) == 8, "");
_Static_assert(sizeof(struct A9_extra_alignment) == 24, "");
_Static_assert(_Alignof(struct A9_extra_alignment) == 8, "");
_Static_assert(sizeof(struct A9_extra_packed) == 16, "");
_Static_assert(_Alignof(struct A9_extra_packed) == 1, "");
_Static_assert(sizeof(struct A9_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct A9_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A9_extra_size) == 18, "");
_Static_assert(_Alignof(struct A9_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A9,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A9,j) == 64, "");
#endif
_Static_assert(sizeof(A10) == 8, "");
_Static_assert(_Alignof(A10) == 16, "");
_Static_assert(sizeof(struct A10_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct A10_extra_alignment) == 16, "");
_Static_assert(sizeof(struct A10_extra_packed) == 8, "");
_Static_assert(_Alignof(struct A10_extra_packed) == 1, "");
_Static_assert(sizeof(struct A10_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct A10_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A10_extra_size) == 10, "");
_Static_assert(_Alignof(struct A10_extra_size) == 1, "");
_Static_assert(sizeof(A11) == 16, "");
_Static_assert(_Alignof(A11) == 16, "");
_Static_assert(sizeof(struct A11_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct A11_extra_alignment) == 16, "");
_Static_assert(sizeof(struct A11_extra_packed) == 16, "");
_Static_assert(_Alignof(struct A11_extra_packed) == 1, "");
_Static_assert(sizeof(struct A11_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct A11_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A11_extra_size) == 18, "");
_Static_assert(_Alignof(struct A11_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A11,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A11,j) == 39, "");
#endif
_Static_assert(sizeof(A12) == 32, "");
_Static_assert(_Alignof(A12) == 16, "");
_Static_assert(sizeof(struct A12_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct A12_extra_alignment) == 16, "");
_Static_assert(sizeof(struct A12_extra_packed) == 32, "");
_Static_assert(_Alignof(struct A12_extra_packed) == 1, "");
_Static_assert(sizeof(struct A12_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct A12_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A12_extra_size) == 34, "");
_Static_assert(_Alignof(struct A12_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A12,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A12,j) == 128, "");
#endif
_Static_assert(sizeof(A13) == 32, "");
_Static_assert(_Alignof(A13) == 16, "");
_Static_assert(sizeof(struct A13_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct A13_extra_alignment) == 16, "");
_Static_assert(sizeof(struct A13_extra_packed) == 32, "");
_Static_assert(_Alignof(struct A13_extra_packed) == 1, "");
_Static_assert(sizeof(struct A13_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct A13_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A13_extra_size) == 34, "");
_Static_assert(_Alignof(struct A13_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A13,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A13,j) == 128, "");
_Static_assert(__builtin_bitoffsetof(A13,d) == 136, "");
#endif
// MAPPING|TWO|aarch64-generic-fuchsia-gnu:Clang|aarch64-generic-linux-android:Clang|aarch64-generic-freebsd-gnu:Clang|aarch64-generic-hermit-eabi:Clang|aarch64-generic-netbsd-gnu:Clang|aarch64-generic-other-none:Clang|aarch64-generic-openbsd-gnu:Clang|END
// repr targets Aarch64Fuchsia|Some("aarch64-generic-fuchsia-gnu") Aarch64LinuxAndroid|Some("aarch64-generic-linux-android") Aarch64UnknownFreebsd|Some("aarch64-generic-freebsd-gnu") Aarch64UnknownHermit|Some("aarch64-generic-hermit-eabi") Aarch64UnknownNetbsd|Some("aarch64-generic-netbsd-gnu") Aarch64UnknownNone|Some("aarch64-generic-other-none") Aarch64UnknownOpenbsd|Some("aarch64-generic-openbsd-gnu") Aarch64UnknownRedox|None 
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
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A,d) == 0, "");
#endif
_Static_assert(sizeof(A_) == 8, "");
_Static_assert(_Alignof(A_) == 4, "");
_Static_assert(sizeof(struct A__extra_alignment) == 12, "");
_Static_assert(_Alignof(struct A__extra_alignment) == 4, "");
_Static_assert(sizeof(struct A__extra_packed) == 8, "");
_Static_assert(_Alignof(struct A__extra_packed) == 1, "");
_Static_assert(sizeof(struct A__extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct A__extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A__extra_size) == 10, "");
_Static_assert(_Alignof(struct A__extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_,d) == 32, "");
#endif
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
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B,d) == 0, "");
#endif
_Static_assert(sizeof(B_) == 16, "");
_Static_assert(_Alignof(B_) == 8, "");
_Static_assert(sizeof(struct B__extra_alignment) == 24, "");
_Static_assert(_Alignof(struct B__extra_alignment) == 8, "");
_Static_assert(sizeof(struct B__extra_packed) == 16, "");
_Static_assert(_Alignof(struct B__extra_packed) == 1, "");
_Static_assert(sizeof(struct B__extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct B__extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B__extra_size) == 18, "");
_Static_assert(_Alignof(struct B__extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B_,d) == 64, "");
#endif
_Static_assert(sizeof(C) == 8, "");
_Static_assert(_Alignof(C) == 8, "");
_Static_assert(sizeof(struct C_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct C_extra_alignment) == 8, "");
_Static_assert(sizeof(struct C_extra_packed) == 8, "");
_Static_assert(_Alignof(struct C_extra_packed) == 1, "");
_Static_assert(sizeof(struct C_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct C_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct C_extra_size) == 10, "");
_Static_assert(_Alignof(struct C_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(C,d) == 0, "");
#endif
_Static_assert(sizeof(C_) == 16, "");
_Static_assert(_Alignof(C_) == 8, "");
_Static_assert(sizeof(struct C__extra_alignment) == 24, "");
_Static_assert(_Alignof(struct C__extra_alignment) == 8, "");
_Static_assert(sizeof(struct C__extra_packed) == 16, "");
_Static_assert(_Alignof(struct C__extra_packed) == 1, "");
_Static_assert(sizeof(struct C__extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct C__extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct C__extra_size) == 18, "");
_Static_assert(_Alignof(struct C__extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(C_,d) == 64, "");
#endif
_Static_assert(sizeof(D) == 24, "");
_Static_assert(_Alignof(D) == 8, "");
_Static_assert(sizeof(struct D_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct D_extra_alignment) == 8, "");
_Static_assert(sizeof(struct D_extra_packed) == 24, "");
_Static_assert(_Alignof(struct D_extra_packed) == 1, "");
_Static_assert(sizeof(struct D_extra_required_alignment) == 25, "");
_Static_assert(_Alignof(struct D_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct D_extra_size) == 26, "");
_Static_assert(_Alignof(struct D_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(D,d) == 64, "");
_Static_assert(__builtin_bitoffsetof(D,e) == 128, "");
#endif
_Static_assert(sizeof(F) == 32, "");
_Static_assert(_Alignof(F) == 16, "");
_Static_assert(sizeof(struct F_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct F_extra_alignment) == 16, "");
_Static_assert(sizeof(struct F_extra_packed) == 32, "");
_Static_assert(_Alignof(struct F_extra_packed) == 1, "");
_Static_assert(sizeof(struct F_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct F_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct F_extra_size) == 34, "");
_Static_assert(_Alignof(struct F_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(F,d) == 128, "");
_Static_assert(__builtin_bitoffsetof(F,e) == 192, "");
#endif
_Static_assert(sizeof(G) == 12, "");
_Static_assert(_Alignof(G) == 2, "");
_Static_assert(sizeof(struct G_extra_alignment) == 14, "");
_Static_assert(_Alignof(struct G_extra_alignment) == 2, "");
_Static_assert(sizeof(struct G_extra_packed) == 12, "");
_Static_assert(_Alignof(struct G_extra_packed) == 1, "");
_Static_assert(sizeof(struct G_extra_required_alignment) == 13, "");
_Static_assert(_Alignof(struct G_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct G_extra_size) == 14, "");
_Static_assert(_Alignof(struct G_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(G,d) == 16, "");
_Static_assert(__builtin_bitoffsetof(G,e) == 80, "");
#endif
_Static_assert(sizeof(H) == 12, "");
_Static_assert(_Alignof(H) == 2, "");
_Static_assert(sizeof(struct H_extra_alignment) == 14, "");
_Static_assert(_Alignof(struct H_extra_alignment) == 2, "");
_Static_assert(sizeof(struct H_extra_packed) == 12, "");
_Static_assert(_Alignof(struct H_extra_packed) == 1, "");
_Static_assert(sizeof(struct H_extra_required_alignment) == 13, "");
_Static_assert(_Alignof(struct H_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct H_extra_size) == 14, "");
_Static_assert(_Alignof(struct H_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(H,d) == 16, "");
_Static_assert(__builtin_bitoffsetof(H,e) == 80, "");
#endif
_Static_assert(sizeof(I) == 10, "");
_Static_assert(_Alignof(I) == 1, "");
_Static_assert(sizeof(struct I_extra_alignment) == 11, "");
_Static_assert(_Alignof(struct I_extra_alignment) == 1, "");
_Static_assert(sizeof(struct I_extra_packed) == 10, "");
_Static_assert(_Alignof(struct I_extra_packed) == 1, "");
_Static_assert(sizeof(struct I_extra_required_alignment) == 11, "");
_Static_assert(_Alignof(struct I_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct I_extra_size) == 12, "");
_Static_assert(_Alignof(struct I_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(I,d) == 8, "");
_Static_assert(__builtin_bitoffsetof(I,e) == 72, "");
#endif
_Static_assert(sizeof(J) == 12, "");
_Static_assert(_Alignof(J) == 2, "");
_Static_assert(sizeof(struct J_extra_alignment) == 14, "");
_Static_assert(_Alignof(struct J_extra_alignment) == 2, "");
_Static_assert(sizeof(struct J_extra_packed) == 12, "");
_Static_assert(_Alignof(struct J_extra_packed) == 1, "");
_Static_assert(sizeof(struct J_extra_required_alignment) == 13, "");
_Static_assert(_Alignof(struct J_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct J_extra_size) == 14, "");
_Static_assert(_Alignof(struct J_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(J,d) == 16, "");
_Static_assert(__builtin_bitoffsetof(J,e) == 80, "");
#endif
_Static_assert(sizeof(K) == 8, "");
_Static_assert(_Alignof(K) == 8, "");
_Static_assert(sizeof(struct K_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct K_extra_alignment) == 8, "");
_Static_assert(sizeof(struct K_extra_packed) == 8, "");
_Static_assert(_Alignof(struct K_extra_packed) == 1, "");
_Static_assert(sizeof(struct K_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct K_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct K_extra_size) == 10, "");
_Static_assert(_Alignof(struct K_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(K,d) == 8, "");
_Static_assert(__builtin_bitoffsetof(K,e) == 16, "");
#endif
_Static_assert(sizeof(L) == 32, "");
_Static_assert(_Alignof(L) == 16, "");
_Static_assert(sizeof(struct L_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct L_extra_alignment) == 16, "");
_Static_assert(sizeof(struct L_extra_packed) == 32, "");
_Static_assert(_Alignof(struct L_extra_packed) == 1, "");
_Static_assert(sizeof(struct L_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct L_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct L_extra_size) == 34, "");
_Static_assert(_Alignof(struct L_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(L,d) == 128, "");
_Static_assert(__builtin_bitoffsetof(L,e) == 136, "");
#endif
_Static_assert(sizeof(M) == 4, "");
_Static_assert(_Alignof(M) == 2, "");
_Static_assert(sizeof(struct M_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct M_extra_alignment) == 2, "");
_Static_assert(sizeof(struct M_extra_packed) == 4, "");
_Static_assert(_Alignof(struct M_extra_packed) == 1, "");
_Static_assert(sizeof(struct M_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct M_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct M_extra_size) == 6, "");
_Static_assert(_Alignof(struct M_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(M,d) == 16, "");
_Static_assert(__builtin_bitoffsetof(M,e) == 24, "");
#endif
_Static_assert(sizeof(N) == 4, "");
_Static_assert(_Alignof(N) == 2, "");
_Static_assert(sizeof(struct N_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct N_extra_alignment) == 2, "");
_Static_assert(sizeof(struct N_extra_packed) == 4, "");
_Static_assert(_Alignof(struct N_extra_packed) == 1, "");
_Static_assert(sizeof(struct N_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct N_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct N_extra_size) == 6, "");
_Static_assert(_Alignof(struct N_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(N,d) == 8, "");
_Static_assert(__builtin_bitoffsetof(N,e) == 16, "");
#endif
_Static_assert(sizeof(O) == 3, "");
_Static_assert(_Alignof(O) == 1, "");
_Static_assert(sizeof(struct O_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct O_extra_alignment) == 1, "");
_Static_assert(sizeof(struct O_extra_packed) == 3, "");
_Static_assert(_Alignof(struct O_extra_packed) == 1, "");
_Static_assert(sizeof(struct O_extra_required_alignment) == 4, "");
_Static_assert(_Alignof(struct O_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct O_extra_size) == 5, "");
_Static_assert(_Alignof(struct O_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(O,d) == 8, "");
_Static_assert(__builtin_bitoffsetof(O,e) == 16, "");
#endif
_Static_assert(sizeof(P) == 4, "");
_Static_assert(_Alignof(P) == 2, "");
_Static_assert(sizeof(struct P_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct P_extra_alignment) == 2, "");
_Static_assert(sizeof(struct P_extra_packed) == 4, "");
_Static_assert(_Alignof(struct P_extra_packed) == 1, "");
_Static_assert(sizeof(struct P_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct P_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct P_extra_size) == 6, "");
_Static_assert(_Alignof(struct P_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(P,d) == 8, "");
_Static_assert(__builtin_bitoffsetof(P,e) == 16, "");
#endif
_Static_assert(sizeof(Q) == 8, "");
_Static_assert(_Alignof(Q) == 8, "");
_Static_assert(sizeof(struct Q_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct Q_extra_alignment) == 8, "");
_Static_assert(sizeof(struct Q_extra_packed) == 8, "");
_Static_assert(_Alignof(struct Q_extra_packed) == 1, "");
_Static_assert(sizeof(struct Q_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct Q_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct Q_extra_size) == 10, "");
_Static_assert(_Alignof(struct Q_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(Q,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(Q,d) == 9, "");
_Static_assert(__builtin_bitoffsetof(Q,e) == 16, "");
#endif
_Static_assert(sizeof(R) == 32, "");
_Static_assert(_Alignof(R) == 16, "");
_Static_assert(sizeof(struct R_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct R_extra_alignment) == 16, "");
_Static_assert(sizeof(struct R_extra_packed) == 32, "");
_Static_assert(_Alignof(struct R_extra_packed) == 1, "");
_Static_assert(sizeof(struct R_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct R_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct R_extra_size) == 34, "");
_Static_assert(_Alignof(struct R_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(R,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(R,e) == 128, "");
#endif
_Static_assert(sizeof(S) == 16, "");
_Static_assert(_Alignof(S) == 8, "");
_Static_assert(sizeof(struct S_extra_alignment) == 24, "");
_Static_assert(_Alignof(struct S_extra_alignment) == 8, "");
_Static_assert(sizeof(struct S_extra_packed) == 16, "");
_Static_assert(_Alignof(struct S_extra_packed) == 1, "");
_Static_assert(sizeof(struct S_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct S_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct S_extra_size) == 18, "");
_Static_assert(_Alignof(struct S_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(S,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(S,e) == 64, "");
#endif
_Static_assert(sizeof(T) == 16, "");
_Static_assert(_Alignof(T) == 8, "");
_Static_assert(sizeof(struct T_extra_alignment) == 24, "");
_Static_assert(_Alignof(struct T_extra_alignment) == 8, "");
_Static_assert(sizeof(struct T_extra_packed) == 16, "");
_Static_assert(_Alignof(struct T_extra_packed) == 1, "");
_Static_assert(sizeof(struct T_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct T_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct T_extra_size) == 18, "");
_Static_assert(_Alignof(struct T_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(T,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(T,e) == 64, "");
#endif
_Static_assert(sizeof(U) == 16, "");
_Static_assert(_Alignof(U) == 8, "");
_Static_assert(sizeof(struct U_extra_alignment) == 24, "");
_Static_assert(_Alignof(struct U_extra_alignment) == 8, "");
_Static_assert(sizeof(struct U_extra_packed) == 16, "");
_Static_assert(_Alignof(struct U_extra_packed) == 1, "");
_Static_assert(sizeof(struct U_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct U_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct U_extra_size) == 18, "");
_Static_assert(_Alignof(struct U_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(U,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(U,e) == 64, "");
#endif
_Static_assert(sizeof(V) == 16, "");
_Static_assert(_Alignof(V) == 8, "");
_Static_assert(sizeof(struct V_extra_alignment) == 24, "");
_Static_assert(_Alignof(struct V_extra_alignment) == 8, "");
_Static_assert(sizeof(struct V_extra_packed) == 16, "");
_Static_assert(_Alignof(struct V_extra_packed) == 1, "");
_Static_assert(sizeof(struct V_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct V_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct V_extra_size) == 18, "");
_Static_assert(_Alignof(struct V_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(V,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(V,e) == 64, "");
#endif
_Static_assert(sizeof(W) == 32, "");
_Static_assert(_Alignof(W) == 16, "");
_Static_assert(sizeof(struct W_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct W_extra_alignment) == 16, "");
_Static_assert(sizeof(struct W_extra_packed) == 32, "");
_Static_assert(_Alignof(struct W_extra_packed) == 1, "");
_Static_assert(sizeof(struct W_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct W_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct W_extra_size) == 34, "");
_Static_assert(_Alignof(struct W_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(W,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(W,e) == 128, "");
#endif
_Static_assert(sizeof(W_) == 32, "");
_Static_assert(_Alignof(W_) == 16, "");
_Static_assert(sizeof(struct W__extra_alignment) == 48, "");
_Static_assert(_Alignof(struct W__extra_alignment) == 16, "");
_Static_assert(sizeof(struct W__extra_packed) == 32, "");
_Static_assert(_Alignof(struct W__extra_packed) == 1, "");
_Static_assert(sizeof(struct W__extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct W__extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct W__extra_size) == 34, "");
_Static_assert(_Alignof(struct W__extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(W_,e) == 128, "");
#endif
_Static_assert(sizeof(X) == 32, "");
_Static_assert(_Alignof(X) == 16, "");
_Static_assert(sizeof(struct X_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct X_extra_alignment) == 16, "");
_Static_assert(sizeof(struct X_extra_packed) == 32, "");
_Static_assert(_Alignof(struct X_extra_packed) == 1, "");
_Static_assert(sizeof(struct X_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct X_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct X_extra_size) == 34, "");
_Static_assert(_Alignof(struct X_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(X,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(X,e) == 128, "");
#endif
_Static_assert(sizeof(A2) == 4, "");
_Static_assert(_Alignof(A2) == 4, "");
_Static_assert(sizeof(struct A2_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct A2_extra_alignment) == 4, "");
_Static_assert(sizeof(struct A2_extra_packed) == 4, "");
_Static_assert(_Alignof(struct A2_extra_packed) == 1, "");
_Static_assert(sizeof(struct A2_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct A2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A2_extra_size) == 6, "");
_Static_assert(_Alignof(struct A2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A2,d) == 0, "");
#endif
_Static_assert(sizeof(A_2) == 4, "");
_Static_assert(_Alignof(A_2) == 4, "");
_Static_assert(sizeof(struct A_2_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct A_2_extra_alignment) == 4, "");
_Static_assert(sizeof(struct A_2_extra_packed) == 4, "");
_Static_assert(_Alignof(struct A_2_extra_packed) == 1, "");
_Static_assert(sizeof(struct A_2_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct A_2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A_2_extra_size) == 6, "");
_Static_assert(_Alignof(struct A_2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_2,d) == 0, "");
#endif
_Static_assert(sizeof(B2) == 8, "");
_Static_assert(_Alignof(B2) == 8, "");
_Static_assert(sizeof(struct B2_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct B2_extra_alignment) == 8, "");
_Static_assert(sizeof(struct B2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct B2_extra_packed) == 1, "");
_Static_assert(sizeof(struct B2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct B2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B2_extra_size) == 10, "");
_Static_assert(_Alignof(struct B2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B2,d) == 0, "");
#endif
_Static_assert(sizeof(B_2) == 8, "");
_Static_assert(_Alignof(B_2) == 8, "");
_Static_assert(sizeof(struct B_2_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct B_2_extra_alignment) == 8, "");
_Static_assert(sizeof(struct B_2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct B_2_extra_packed) == 1, "");
_Static_assert(sizeof(struct B_2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct B_2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B_2_extra_size) == 10, "");
_Static_assert(_Alignof(struct B_2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B_2,d) == 0, "");
#endif
_Static_assert(sizeof(C2) == 8, "");
_Static_assert(_Alignof(C2) == 8, "");
_Static_assert(sizeof(struct C2_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct C2_extra_alignment) == 8, "");
_Static_assert(sizeof(struct C2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct C2_extra_packed) == 1, "");
_Static_assert(sizeof(struct C2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct C2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct C2_extra_size) == 10, "");
_Static_assert(_Alignof(struct C2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(C2,d) == 0, "");
#endif
_Static_assert(sizeof(C22) == 8, "");
_Static_assert(_Alignof(C22) == 8, "");
_Static_assert(sizeof(struct C22_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct C22_extra_alignment) == 8, "");
_Static_assert(sizeof(struct C22_extra_packed) == 8, "");
_Static_assert(_Alignof(struct C22_extra_packed) == 1, "");
_Static_assert(sizeof(struct C22_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct C22_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct C22_extra_size) == 10, "");
_Static_assert(_Alignof(struct C22_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(C22,d) == 0, "");
#endif
_Static_assert(sizeof(D2) == 8, "");
_Static_assert(_Alignof(D2) == 8, "");
_Static_assert(sizeof(struct D2_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct D2_extra_alignment) == 8, "");
_Static_assert(sizeof(struct D2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct D2_extra_packed) == 1, "");
_Static_assert(sizeof(struct D2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct D2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct D2_extra_size) == 10, "");
_Static_assert(_Alignof(struct D2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(D2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(D2,e) == 0, "");
#endif
_Static_assert(sizeof(F2) == 16, "");
_Static_assert(_Alignof(F2) == 16, "");
_Static_assert(sizeof(struct F2_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct F2_extra_alignment) == 16, "");
_Static_assert(sizeof(struct F2_extra_packed) == 16, "");
_Static_assert(_Alignof(struct F2_extra_packed) == 1, "");
_Static_assert(sizeof(struct F2_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct F2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct F2_extra_size) == 18, "");
_Static_assert(_Alignof(struct F2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(F2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(F2,e) == 0, "");
#endif
_Static_assert(sizeof(G2) == 8, "");
_Static_assert(_Alignof(G2) == 2, "");
_Static_assert(sizeof(struct G2_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct G2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct G2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct G2_extra_packed) == 1, "");
_Static_assert(sizeof(struct G2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct G2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct G2_extra_size) == 10, "");
_Static_assert(_Alignof(struct G2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(G2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(G2,e) == 0, "");
#endif
_Static_assert(sizeof(H2) == 8, "");
_Static_assert(_Alignof(H2) == 2, "");
_Static_assert(sizeof(struct H2_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct H2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct H2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct H2_extra_packed) == 1, "");
_Static_assert(sizeof(struct H2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct H2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct H2_extra_size) == 10, "");
_Static_assert(_Alignof(struct H2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(H2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(H2,e) == 0, "");
#endif
_Static_assert(sizeof(I2) == 8, "");
_Static_assert(_Alignof(I2) == 1, "");
_Static_assert(sizeof(struct I2_extra_alignment) == 9, "");
_Static_assert(_Alignof(struct I2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct I2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct I2_extra_packed) == 1, "");
_Static_assert(sizeof(struct I2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct I2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct I2_extra_size) == 10, "");
_Static_assert(_Alignof(struct I2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(I2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(I2,e) == 0, "");
#endif
_Static_assert(sizeof(J2) == 8, "");
_Static_assert(_Alignof(J2) == 2, "");
_Static_assert(sizeof(struct J2_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct J2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct J2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct J2_extra_packed) == 1, "");
_Static_assert(sizeof(struct J2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct J2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct J2_extra_size) == 10, "");
_Static_assert(_Alignof(struct J2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(J2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(J2,e) == 0, "");
#endif
_Static_assert(sizeof(K2) == 8, "");
_Static_assert(_Alignof(K2) == 8, "");
_Static_assert(sizeof(struct K2_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct K2_extra_alignment) == 8, "");
_Static_assert(sizeof(struct K2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct K2_extra_packed) == 1, "");
_Static_assert(sizeof(struct K2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct K2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct K2_extra_size) == 10, "");
_Static_assert(_Alignof(struct K2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(K2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(K2,e) == 0, "");
#endif
_Static_assert(sizeof(L2) == 16, "");
_Static_assert(_Alignof(L2) == 16, "");
_Static_assert(sizeof(struct L2_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct L2_extra_alignment) == 16, "");
_Static_assert(sizeof(struct L2_extra_packed) == 16, "");
_Static_assert(_Alignof(struct L2_extra_packed) == 1, "");
_Static_assert(sizeof(struct L2_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct L2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct L2_extra_size) == 18, "");
_Static_assert(_Alignof(struct L2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(L2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(L2,e) == 0, "");
#endif
_Static_assert(sizeof(M2) == 2, "");
_Static_assert(_Alignof(M2) == 2, "");
_Static_assert(sizeof(struct M2_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct M2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct M2_extra_packed) == 2, "");
_Static_assert(_Alignof(struct M2_extra_packed) == 1, "");
_Static_assert(sizeof(struct M2_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct M2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct M2_extra_size) == 4, "");
_Static_assert(_Alignof(struct M2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(M2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(M2,e) == 0, "");
#endif
_Static_assert(sizeof(N2) == 2, "");
_Static_assert(_Alignof(N2) == 2, "");
_Static_assert(sizeof(struct N2_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct N2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct N2_extra_packed) == 2, "");
_Static_assert(_Alignof(struct N2_extra_packed) == 1, "");
_Static_assert(sizeof(struct N2_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct N2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct N2_extra_size) == 4, "");
_Static_assert(_Alignof(struct N2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(N2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(N2,e) == 0, "");
#endif
_Static_assert(sizeof(O2) == 1, "");
_Static_assert(_Alignof(O2) == 1, "");
_Static_assert(sizeof(struct O2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct O2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct O2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct O2_extra_packed) == 1, "");
_Static_assert(sizeof(struct O2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct O2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct O2_extra_size) == 3, "");
_Static_assert(_Alignof(struct O2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(O2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(O2,e) == 0, "");
#endif
_Static_assert(sizeof(P2) == 2, "");
_Static_assert(_Alignof(P2) == 2, "");
_Static_assert(sizeof(struct P2_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct P2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct P2_extra_packed) == 2, "");
_Static_assert(_Alignof(struct P2_extra_packed) == 1, "");
_Static_assert(sizeof(struct P2_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct P2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct P2_extra_size) == 4, "");
_Static_assert(_Alignof(struct P2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(P2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(P2,e) == 0, "");
#endif
_Static_assert(sizeof(Q2) == 8, "");
_Static_assert(_Alignof(Q2) == 8, "");
_Static_assert(sizeof(struct Q2_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct Q2_extra_alignment) == 8, "");
_Static_assert(sizeof(struct Q2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct Q2_extra_packed) == 1, "");
_Static_assert(sizeof(struct Q2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct Q2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct Q2_extra_size) == 10, "");
_Static_assert(_Alignof(struct Q2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(Q2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(Q2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(Q2,e) == 0, "");
#endif
_Static_assert(sizeof(R2) == 16, "");
_Static_assert(_Alignof(R2) == 16, "");
_Static_assert(sizeof(struct R2_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct R2_extra_alignment) == 16, "");
_Static_assert(sizeof(struct R2_extra_packed) == 16, "");
_Static_assert(_Alignof(struct R2_extra_packed) == 1, "");
_Static_assert(sizeof(struct R2_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct R2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct R2_extra_size) == 18, "");
_Static_assert(_Alignof(struct R2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(R2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(R2,e) == 0, "");
#endif
_Static_assert(sizeof(S2) == 8, "");
_Static_assert(_Alignof(S2) == 8, "");
_Static_assert(sizeof(struct S2_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct S2_extra_alignment) == 8, "");
_Static_assert(sizeof(struct S2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct S2_extra_packed) == 1, "");
_Static_assert(sizeof(struct S2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct S2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct S2_extra_size) == 10, "");
_Static_assert(_Alignof(struct S2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(S2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(S2,e) == 0, "");
#endif
_Static_assert(sizeof(T2) == 8, "");
_Static_assert(_Alignof(T2) == 8, "");
_Static_assert(sizeof(struct T2_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct T2_extra_alignment) == 8, "");
_Static_assert(sizeof(struct T2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct T2_extra_packed) == 1, "");
_Static_assert(sizeof(struct T2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct T2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct T2_extra_size) == 10, "");
_Static_assert(_Alignof(struct T2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(T2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(T2,e) == 0, "");
#endif
_Static_assert(sizeof(U2) == 8, "");
_Static_assert(_Alignof(U2) == 8, "");
_Static_assert(sizeof(struct U2_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct U2_extra_alignment) == 8, "");
_Static_assert(sizeof(struct U2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct U2_extra_packed) == 1, "");
_Static_assert(sizeof(struct U2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct U2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct U2_extra_size) == 10, "");
_Static_assert(_Alignof(struct U2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(U2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(U2,e) == 0, "");
#endif
_Static_assert(sizeof(V2) == 8, "");
_Static_assert(_Alignof(V2) == 8, "");
_Static_assert(sizeof(struct V2_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct V2_extra_alignment) == 8, "");
_Static_assert(sizeof(struct V2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct V2_extra_packed) == 1, "");
_Static_assert(sizeof(struct V2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct V2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct V2_extra_size) == 10, "");
_Static_assert(_Alignof(struct V2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(V2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(V2,e) == 0, "");
#endif
_Static_assert(sizeof(W2) == 16, "");
_Static_assert(_Alignof(W2) == 16, "");
_Static_assert(sizeof(struct W2_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct W2_extra_alignment) == 16, "");
_Static_assert(sizeof(struct W2_extra_packed) == 16, "");
_Static_assert(_Alignof(struct W2_extra_packed) == 1, "");
_Static_assert(sizeof(struct W2_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct W2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct W2_extra_size) == 18, "");
_Static_assert(_Alignof(struct W2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(W2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(W2,e) == 0, "");
#endif
_Static_assert(sizeof(W_2) == 16, "");
_Static_assert(_Alignof(W_2) == 16, "");
_Static_assert(sizeof(struct W_2_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct W_2_extra_alignment) == 16, "");
_Static_assert(sizeof(struct W_2_extra_packed) == 16, "");
_Static_assert(_Alignof(struct W_2_extra_packed) == 1, "");
_Static_assert(sizeof(struct W_2_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct W_2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct W_2_extra_size) == 18, "");
_Static_assert(_Alignof(struct W_2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(W_2,e) == 0, "");
#endif
_Static_assert(sizeof(X2) == 16, "");
_Static_assert(_Alignof(X2) == 16, "");
_Static_assert(sizeof(struct X2_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct X2_extra_alignment) == 16, "");
_Static_assert(sizeof(struct X2_extra_packed) == 16, "");
_Static_assert(_Alignof(struct X2_extra_packed) == 1, "");
_Static_assert(sizeof(struct X2_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct X2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct X2_extra_size) == 18, "");
_Static_assert(_Alignof(struct X2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(X2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(X2,e) == 0, "");
#endif
_Static_assert(sizeof(Y) == 16, "");
_Static_assert(_Alignof(Y) == 8, "");
_Static_assert(sizeof(struct Y_extra_alignment) == 24, "");
_Static_assert(_Alignof(struct Y_extra_alignment) == 8, "");
_Static_assert(sizeof(struct Y_extra_packed) == 16, "");
_Static_assert(_Alignof(struct Y_extra_packed) == 1, "");
_Static_assert(sizeof(struct Y_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct Y_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct Y_extra_size) == 18, "");
_Static_assert(_Alignof(struct Y_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(Y,d) == 64, "");
#endif
_Static_assert(sizeof(Y2) == 8, "");
_Static_assert(_Alignof(Y2) == 8, "");
_Static_assert(sizeof(struct Y2_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct Y2_extra_alignment) == 8, "");
_Static_assert(sizeof(struct Y2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct Y2_extra_packed) == 1, "");
_Static_assert(sizeof(struct Y2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct Y2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct Y2_extra_size) == 10, "");
_Static_assert(_Alignof(struct Y2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(Y2,d) == 0, "");
#endif
_Static_assert(sizeof(A3) == 64, "");
_Static_assert(_Alignof(A3) == 32, "");
_Static_assert(sizeof(struct A3_extra_alignment) == 96, "");
_Static_assert(_Alignof(struct A3_extra_alignment) == 32, "");
_Static_assert(sizeof(struct A3_extra_packed) == 64, "");
_Static_assert(_Alignof(struct A3_extra_packed) == 1, "");
_Static_assert(sizeof(struct A3_extra_required_alignment) == 65, "");
_Static_assert(_Alignof(struct A3_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A3_extra_size) == 66, "");
_Static_assert(_Alignof(struct A3_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A3,d) == 256, "");
#endif
_Static_assert(sizeof(A4) == 1, "");
_Static_assert(_Alignof(A4) == 32, "");
_Static_assert(sizeof(struct A4_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct A4_extra_alignment) == 32, "");
_Static_assert(sizeof(struct A4_extra_packed) == 1, "");
_Static_assert(_Alignof(struct A4_extra_packed) == 1, "");
_Static_assert(sizeof(struct A4_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct A4_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A4_extra_size) == 3, "");
_Static_assert(_Alignof(struct A4_extra_size) == 1, "");
_Static_assert(sizeof(A5) == 64, "");
_Static_assert(_Alignof(A5) == 32, "");
_Static_assert(sizeof(struct A5_extra_alignment) == 96, "");
_Static_assert(_Alignof(struct A5_extra_alignment) == 32, "");
_Static_assert(sizeof(struct A5_extra_packed) == 64, "");
_Static_assert(_Alignof(struct A5_extra_packed) == 1, "");
_Static_assert(sizeof(struct A5_extra_required_alignment) == 65, "");
_Static_assert(_Alignof(struct A5_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A5_extra_size) == 66, "");
_Static_assert(_Alignof(struct A5_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A5,d) == 256, "");
#endif
_Static_assert(sizeof(A7) == 32, "");
_Static_assert(_Alignof(A7) == 32, "");
_Static_assert(sizeof(struct A7_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct A7_extra_alignment) == 32, "");
_Static_assert(sizeof(struct A7_extra_packed) == 32, "");
_Static_assert(_Alignof(struct A7_extra_packed) == 1, "");
_Static_assert(sizeof(struct A7_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct A7_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A7_extra_size) == 34, "");
_Static_assert(_Alignof(struct A7_extra_size) == 1, "");
_Static_assert(sizeof(A8) == 8, "");
_Static_assert(_Alignof(A8) == 8, "");
_Static_assert(sizeof(struct A8_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct A8_extra_alignment) == 8, "");
_Static_assert(sizeof(struct A8_extra_packed) == 8, "");
_Static_assert(_Alignof(struct A8_extra_packed) == 1, "");
_Static_assert(sizeof(struct A8_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct A8_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A8_extra_size) == 10, "");
_Static_assert(_Alignof(struct A8_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A8,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A8,j) == 39, "");
#endif
_Static_assert(sizeof(A9) == 16, "");
_Static_assert(_Alignof(A9) == 8, "");
_Static_assert(sizeof(struct A9_extra_alignment) == 24, "");
_Static_assert(_Alignof(struct A9_extra_alignment) == 8, "");
_Static_assert(sizeof(struct A9_extra_packed) == 16, "");
_Static_assert(_Alignof(struct A9_extra_packed) == 1, "");
_Static_assert(sizeof(struct A9_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct A9_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A9_extra_size) == 18, "");
_Static_assert(_Alignof(struct A9_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A9,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A9,j) == 64, "");
#endif
_Static_assert(sizeof(A10) == 8, "");
_Static_assert(_Alignof(A10) == 16, "");
_Static_assert(sizeof(struct A10_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct A10_extra_alignment) == 16, "");
_Static_assert(sizeof(struct A10_extra_packed) == 8, "");
_Static_assert(_Alignof(struct A10_extra_packed) == 1, "");
_Static_assert(sizeof(struct A10_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct A10_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A10_extra_size) == 10, "");
_Static_assert(_Alignof(struct A10_extra_size) == 1, "");
_Static_assert(sizeof(A11) == 16, "");
_Static_assert(_Alignof(A11) == 16, "");
_Static_assert(sizeof(struct A11_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct A11_extra_alignment) == 16, "");
_Static_assert(sizeof(struct A11_extra_packed) == 16, "");
_Static_assert(_Alignof(struct A11_extra_packed) == 1, "");
_Static_assert(sizeof(struct A11_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct A11_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A11_extra_size) == 18, "");
_Static_assert(_Alignof(struct A11_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A11,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A11,j) == 39, "");
#endif
_Static_assert(sizeof(A12) == 32, "");
_Static_assert(_Alignof(A12) == 16, "");
_Static_assert(sizeof(struct A12_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct A12_extra_alignment) == 16, "");
_Static_assert(sizeof(struct A12_extra_packed) == 32, "");
_Static_assert(_Alignof(struct A12_extra_packed) == 1, "");
_Static_assert(sizeof(struct A12_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct A12_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A12_extra_size) == 34, "");
_Static_assert(_Alignof(struct A12_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A12,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A12,j) == 128, "");
#endif
_Static_assert(sizeof(A13) == 32, "");
_Static_assert(_Alignof(A13) == 16, "");
_Static_assert(sizeof(struct A13_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct A13_extra_alignment) == 16, "");
_Static_assert(sizeof(struct A13_extra_packed) == 32, "");
_Static_assert(_Alignof(struct A13_extra_packed) == 1, "");
_Static_assert(sizeof(struct A13_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct A13_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A13_extra_size) == 34, "");
_Static_assert(_Alignof(struct A13_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A13,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A13,j) == 128, "");
_Static_assert(__builtin_bitoffsetof(A13,d) == 136, "");
#endif
// MAPPING|THREE|aarch64-generic-linux-gnu:Gcc|aarch64-generic-linux-musl:Gcc|END
// repr targets Aarch64UnknownLinuxGnu|Some("aarch64-generic-linux-gnu") Aarch64UnknownLinuxMusl|Some("aarch64-generic-linux-musl") 
#elif defined(THREE)
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
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A,d) == 0, "");
#endif
_Static_assert(sizeof(A_) == 8, "");
_Static_assert(_Alignof(A_) == 4, "");
_Static_assert(sizeof(struct A__extra_alignment) == 12, "");
_Static_assert(_Alignof(struct A__extra_alignment) == 4, "");
_Static_assert(sizeof(struct A__extra_packed) == 8, "");
_Static_assert(_Alignof(struct A__extra_packed) == 1, "");
_Static_assert(sizeof(struct A__extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct A__extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A__extra_size) == 10, "");
_Static_assert(_Alignof(struct A__extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_,d) == 32, "");
#endif
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
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B,d) == 0, "");
#endif
_Static_assert(sizeof(B_) == 16, "");
_Static_assert(_Alignof(B_) == 8, "");
_Static_assert(sizeof(struct B__extra_alignment) == 24, "");
_Static_assert(_Alignof(struct B__extra_alignment) == 8, "");
_Static_assert(sizeof(struct B__extra_packed) == 16, "");
_Static_assert(_Alignof(struct B__extra_packed) == 1, "");
_Static_assert(sizeof(struct B__extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct B__extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B__extra_size) == 18, "");
_Static_assert(_Alignof(struct B__extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B_,d) == 64, "");
#endif
_Static_assert(sizeof(C) == 8, "");
_Static_assert(_Alignof(C) == 8, "");
_Static_assert(sizeof(struct C_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct C_extra_alignment) == 8, "");
_Static_assert(sizeof(struct C_extra_packed) == 8, "");
_Static_assert(_Alignof(struct C_extra_packed) == 1, "");
_Static_assert(sizeof(struct C_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct C_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct C_extra_size) == 10, "");
_Static_assert(_Alignof(struct C_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(C,d) == 0, "");
#endif
_Static_assert(sizeof(C_) == 16, "");
_Static_assert(_Alignof(C_) == 8, "");
_Static_assert(sizeof(struct C__extra_alignment) == 24, "");
_Static_assert(_Alignof(struct C__extra_alignment) == 8, "");
_Static_assert(sizeof(struct C__extra_packed) == 16, "");
_Static_assert(_Alignof(struct C__extra_packed) == 1, "");
_Static_assert(sizeof(struct C__extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct C__extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct C__extra_size) == 18, "");
_Static_assert(_Alignof(struct C__extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(C_,d) == 64, "");
#endif
_Static_assert(sizeof(D) == 24, "");
_Static_assert(_Alignof(D) == 8, "");
_Static_assert(sizeof(struct D_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct D_extra_alignment) == 8, "");
_Static_assert(sizeof(struct D_extra_packed) == 24, "");
_Static_assert(_Alignof(struct D_extra_packed) == 1, "");
_Static_assert(sizeof(struct D_extra_required_alignment) == 25, "");
_Static_assert(_Alignof(struct D_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct D_extra_size) == 26, "");
_Static_assert(_Alignof(struct D_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(D,d) == 64, "");
_Static_assert(__builtin_bitoffsetof(D,e) == 128, "");
#endif
_Static_assert(sizeof(F) == 32, "");
_Static_assert(_Alignof(F) == 16, "");
_Static_assert(sizeof(struct F_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct F_extra_alignment) == 16, "");
_Static_assert(sizeof(struct F_extra_packed) == 32, "");
_Static_assert(_Alignof(struct F_extra_packed) == 1, "");
_Static_assert(sizeof(struct F_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct F_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct F_extra_size) == 34, "");
_Static_assert(_Alignof(struct F_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(F,d) == 128, "");
_Static_assert(__builtin_bitoffsetof(F,e) == 192, "");
#endif
_Static_assert(sizeof(G) == 12, "");
_Static_assert(_Alignof(G) == 2, "");
_Static_assert(sizeof(struct G_extra_alignment) == 14, "");
_Static_assert(_Alignof(struct G_extra_alignment) == 2, "");
_Static_assert(sizeof(struct G_extra_packed) == 12, "");
_Static_assert(_Alignof(struct G_extra_packed) == 1, "");
_Static_assert(sizeof(struct G_extra_required_alignment) == 13, "");
_Static_assert(_Alignof(struct G_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct G_extra_size) == 14, "");
_Static_assert(_Alignof(struct G_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(G,d) == 16, "");
_Static_assert(__builtin_bitoffsetof(G,e) == 80, "");
#endif
_Static_assert(sizeof(H) == 12, "");
_Static_assert(_Alignof(H) == 2, "");
_Static_assert(sizeof(struct H_extra_alignment) == 14, "");
_Static_assert(_Alignof(struct H_extra_alignment) == 2, "");
_Static_assert(sizeof(struct H_extra_packed) == 12, "");
_Static_assert(_Alignof(struct H_extra_packed) == 1, "");
_Static_assert(sizeof(struct H_extra_required_alignment) == 13, "");
_Static_assert(_Alignof(struct H_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct H_extra_size) == 14, "");
_Static_assert(_Alignof(struct H_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(H,d) == 16, "");
_Static_assert(__builtin_bitoffsetof(H,e) == 80, "");
#endif
_Static_assert(sizeof(I) == 10, "");
_Static_assert(_Alignof(I) == 1, "");
_Static_assert(sizeof(struct I_extra_alignment) == 11, "");
_Static_assert(_Alignof(struct I_extra_alignment) == 1, "");
_Static_assert(sizeof(struct I_extra_packed) == 10, "");
_Static_assert(_Alignof(struct I_extra_packed) == 1, "");
_Static_assert(sizeof(struct I_extra_required_alignment) == 11, "");
_Static_assert(_Alignof(struct I_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct I_extra_size) == 12, "");
_Static_assert(_Alignof(struct I_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(I,d) == 8, "");
_Static_assert(__builtin_bitoffsetof(I,e) == 72, "");
#endif
_Static_assert(sizeof(J) == 12, "");
_Static_assert(_Alignof(J) == 2, "");
_Static_assert(sizeof(struct J_extra_alignment) == 14, "");
_Static_assert(_Alignof(struct J_extra_alignment) == 2, "");
_Static_assert(sizeof(struct J_extra_packed) == 12, "");
_Static_assert(_Alignof(struct J_extra_packed) == 1, "");
_Static_assert(sizeof(struct J_extra_required_alignment) == 13, "");
_Static_assert(_Alignof(struct J_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct J_extra_size) == 14, "");
_Static_assert(_Alignof(struct J_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(J,d) == 16, "");
_Static_assert(__builtin_bitoffsetof(J,e) == 80, "");
#endif
_Static_assert(sizeof(K) == 8, "");
_Static_assert(_Alignof(K) == 8, "");
_Static_assert(sizeof(struct K_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct K_extra_alignment) == 8, "");
_Static_assert(sizeof(struct K_extra_packed) == 8, "");
_Static_assert(_Alignof(struct K_extra_packed) == 1, "");
_Static_assert(sizeof(struct K_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct K_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct K_extra_size) == 10, "");
_Static_assert(_Alignof(struct K_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(K,d) == 8, "");
_Static_assert(__builtin_bitoffsetof(K,e) == 16, "");
#endif
_Static_assert(sizeof(L) == 32, "");
_Static_assert(_Alignof(L) == 16, "");
_Static_assert(sizeof(struct L_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct L_extra_alignment) == 16, "");
_Static_assert(sizeof(struct L_extra_packed) == 32, "");
_Static_assert(_Alignof(struct L_extra_packed) == 1, "");
_Static_assert(sizeof(struct L_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct L_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct L_extra_size) == 34, "");
_Static_assert(_Alignof(struct L_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(L,d) == 128, "");
_Static_assert(__builtin_bitoffsetof(L,e) == 136, "");
#endif
_Static_assert(sizeof(M) == 4, "");
_Static_assert(_Alignof(M) == 2, "");
_Static_assert(sizeof(struct M_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct M_extra_alignment) == 2, "");
_Static_assert(sizeof(struct M_extra_packed) == 4, "");
_Static_assert(_Alignof(struct M_extra_packed) == 1, "");
_Static_assert(sizeof(struct M_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct M_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct M_extra_size) == 6, "");
_Static_assert(_Alignof(struct M_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(M,d) == 16, "");
_Static_assert(__builtin_bitoffsetof(M,e) == 24, "");
#endif
_Static_assert(sizeof(N) == 4, "");
_Static_assert(_Alignof(N) == 2, "");
_Static_assert(sizeof(struct N_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct N_extra_alignment) == 2, "");
_Static_assert(sizeof(struct N_extra_packed) == 4, "");
_Static_assert(_Alignof(struct N_extra_packed) == 1, "");
_Static_assert(sizeof(struct N_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct N_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct N_extra_size) == 6, "");
_Static_assert(_Alignof(struct N_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(N,d) == 16, "");
_Static_assert(__builtin_bitoffsetof(N,e) == 24, "");
#endif
_Static_assert(sizeof(O) == 3, "");
_Static_assert(_Alignof(O) == 1, "");
_Static_assert(sizeof(struct O_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct O_extra_alignment) == 1, "");
_Static_assert(sizeof(struct O_extra_packed) == 3, "");
_Static_assert(_Alignof(struct O_extra_packed) == 1, "");
_Static_assert(sizeof(struct O_extra_required_alignment) == 4, "");
_Static_assert(_Alignof(struct O_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct O_extra_size) == 5, "");
_Static_assert(_Alignof(struct O_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(O,d) == 8, "");
_Static_assert(__builtin_bitoffsetof(O,e) == 16, "");
#endif
_Static_assert(sizeof(P) == 4, "");
_Static_assert(_Alignof(P) == 2, "");
_Static_assert(sizeof(struct P_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct P_extra_alignment) == 2, "");
_Static_assert(sizeof(struct P_extra_packed) == 4, "");
_Static_assert(_Alignof(struct P_extra_packed) == 1, "");
_Static_assert(sizeof(struct P_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct P_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct P_extra_size) == 6, "");
_Static_assert(_Alignof(struct P_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(P,d) == 8, "");
_Static_assert(__builtin_bitoffsetof(P,e) == 16, "");
#endif
_Static_assert(sizeof(Q) == 8, "");
_Static_assert(_Alignof(Q) == 8, "");
_Static_assert(sizeof(struct Q_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct Q_extra_alignment) == 8, "");
_Static_assert(sizeof(struct Q_extra_packed) == 8, "");
_Static_assert(_Alignof(struct Q_extra_packed) == 1, "");
_Static_assert(sizeof(struct Q_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct Q_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct Q_extra_size) == 10, "");
_Static_assert(_Alignof(struct Q_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(Q,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(Q,d) == 9, "");
_Static_assert(__builtin_bitoffsetof(Q,e) == 16, "");
#endif
_Static_assert(sizeof(R) == 32, "");
_Static_assert(_Alignof(R) == 16, "");
_Static_assert(sizeof(struct R_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct R_extra_alignment) == 16, "");
_Static_assert(sizeof(struct R_extra_packed) == 32, "");
_Static_assert(_Alignof(struct R_extra_packed) == 1, "");
_Static_assert(sizeof(struct R_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct R_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct R_extra_size) == 34, "");
_Static_assert(_Alignof(struct R_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(R,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(R,e) == 128, "");
#endif
_Static_assert(sizeof(S) == 16, "");
_Static_assert(_Alignof(S) == 8, "");
_Static_assert(sizeof(struct S_extra_alignment) == 24, "");
_Static_assert(_Alignof(struct S_extra_alignment) == 8, "");
_Static_assert(sizeof(struct S_extra_packed) == 16, "");
_Static_assert(_Alignof(struct S_extra_packed) == 1, "");
_Static_assert(sizeof(struct S_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct S_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct S_extra_size) == 18, "");
_Static_assert(_Alignof(struct S_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(S,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(S,e) == 64, "");
#endif
_Static_assert(sizeof(T) == 16, "");
_Static_assert(_Alignof(T) == 8, "");
_Static_assert(sizeof(struct T_extra_alignment) == 24, "");
_Static_assert(_Alignof(struct T_extra_alignment) == 8, "");
_Static_assert(sizeof(struct T_extra_packed) == 16, "");
_Static_assert(_Alignof(struct T_extra_packed) == 1, "");
_Static_assert(sizeof(struct T_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct T_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct T_extra_size) == 18, "");
_Static_assert(_Alignof(struct T_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(T,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(T,e) == 64, "");
#endif
_Static_assert(sizeof(U) == 16, "");
_Static_assert(_Alignof(U) == 8, "");
_Static_assert(sizeof(struct U_extra_alignment) == 24, "");
_Static_assert(_Alignof(struct U_extra_alignment) == 8, "");
_Static_assert(sizeof(struct U_extra_packed) == 16, "");
_Static_assert(_Alignof(struct U_extra_packed) == 1, "");
_Static_assert(sizeof(struct U_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct U_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct U_extra_size) == 18, "");
_Static_assert(_Alignof(struct U_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(U,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(U,e) == 64, "");
#endif
_Static_assert(sizeof(V) == 16, "");
_Static_assert(_Alignof(V) == 8, "");
_Static_assert(sizeof(struct V_extra_alignment) == 24, "");
_Static_assert(_Alignof(struct V_extra_alignment) == 8, "");
_Static_assert(sizeof(struct V_extra_packed) == 16, "");
_Static_assert(_Alignof(struct V_extra_packed) == 1, "");
_Static_assert(sizeof(struct V_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct V_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct V_extra_size) == 18, "");
_Static_assert(_Alignof(struct V_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(V,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(V,e) == 64, "");
#endif
_Static_assert(sizeof(W) == 32, "");
_Static_assert(_Alignof(W) == 16, "");
_Static_assert(sizeof(struct W_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct W_extra_alignment) == 16, "");
_Static_assert(sizeof(struct W_extra_packed) == 32, "");
_Static_assert(_Alignof(struct W_extra_packed) == 1, "");
_Static_assert(sizeof(struct W_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct W_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct W_extra_size) == 34, "");
_Static_assert(_Alignof(struct W_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(W,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(W,e) == 128, "");
#endif
_Static_assert(sizeof(W_) == 32, "");
_Static_assert(_Alignof(W_) == 16, "");
_Static_assert(sizeof(struct W__extra_alignment) == 48, "");
_Static_assert(_Alignof(struct W__extra_alignment) == 16, "");
_Static_assert(sizeof(struct W__extra_packed) == 32, "");
_Static_assert(_Alignof(struct W__extra_packed) == 1, "");
_Static_assert(sizeof(struct W__extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct W__extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct W__extra_size) == 34, "");
_Static_assert(_Alignof(struct W__extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(W_,e) == 128, "");
#endif
_Static_assert(sizeof(X) == 32, "");
_Static_assert(_Alignof(X) == 16, "");
_Static_assert(sizeof(struct X_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct X_extra_alignment) == 16, "");
_Static_assert(sizeof(struct X_extra_packed) == 32, "");
_Static_assert(_Alignof(struct X_extra_packed) == 1, "");
_Static_assert(sizeof(struct X_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct X_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct X_extra_size) == 34, "");
_Static_assert(_Alignof(struct X_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(X,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(X,e) == 128, "");
#endif
_Static_assert(sizeof(A2) == 4, "");
_Static_assert(_Alignof(A2) == 4, "");
_Static_assert(sizeof(struct A2_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct A2_extra_alignment) == 4, "");
_Static_assert(sizeof(struct A2_extra_packed) == 4, "");
_Static_assert(_Alignof(struct A2_extra_packed) == 1, "");
_Static_assert(sizeof(struct A2_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct A2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A2_extra_size) == 6, "");
_Static_assert(_Alignof(struct A2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A2,d) == 0, "");
#endif
_Static_assert(sizeof(A_2) == 4, "");
_Static_assert(_Alignof(A_2) == 4, "");
_Static_assert(sizeof(struct A_2_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct A_2_extra_alignment) == 4, "");
_Static_assert(sizeof(struct A_2_extra_packed) == 4, "");
_Static_assert(_Alignof(struct A_2_extra_packed) == 1, "");
_Static_assert(sizeof(struct A_2_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct A_2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A_2_extra_size) == 6, "");
_Static_assert(_Alignof(struct A_2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_2,d) == 0, "");
#endif
_Static_assert(sizeof(B2) == 8, "");
_Static_assert(_Alignof(B2) == 8, "");
_Static_assert(sizeof(struct B2_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct B2_extra_alignment) == 8, "");
_Static_assert(sizeof(struct B2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct B2_extra_packed) == 1, "");
_Static_assert(sizeof(struct B2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct B2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B2_extra_size) == 10, "");
_Static_assert(_Alignof(struct B2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B2,d) == 0, "");
#endif
_Static_assert(sizeof(B_2) == 8, "");
_Static_assert(_Alignof(B_2) == 8, "");
_Static_assert(sizeof(struct B_2_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct B_2_extra_alignment) == 8, "");
_Static_assert(sizeof(struct B_2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct B_2_extra_packed) == 1, "");
_Static_assert(sizeof(struct B_2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct B_2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B_2_extra_size) == 10, "");
_Static_assert(_Alignof(struct B_2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B_2,d) == 0, "");
#endif
_Static_assert(sizeof(C2) == 8, "");
_Static_assert(_Alignof(C2) == 8, "");
_Static_assert(sizeof(struct C2_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct C2_extra_alignment) == 8, "");
_Static_assert(sizeof(struct C2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct C2_extra_packed) == 1, "");
_Static_assert(sizeof(struct C2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct C2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct C2_extra_size) == 10, "");
_Static_assert(_Alignof(struct C2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(C2,d) == 0, "");
#endif
_Static_assert(sizeof(C22) == 8, "");
_Static_assert(_Alignof(C22) == 8, "");
_Static_assert(sizeof(struct C22_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct C22_extra_alignment) == 8, "");
_Static_assert(sizeof(struct C22_extra_packed) == 8, "");
_Static_assert(_Alignof(struct C22_extra_packed) == 1, "");
_Static_assert(sizeof(struct C22_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct C22_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct C22_extra_size) == 10, "");
_Static_assert(_Alignof(struct C22_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(C22,d) == 0, "");
#endif
_Static_assert(sizeof(D2) == 8, "");
_Static_assert(_Alignof(D2) == 8, "");
_Static_assert(sizeof(struct D2_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct D2_extra_alignment) == 8, "");
_Static_assert(sizeof(struct D2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct D2_extra_packed) == 1, "");
_Static_assert(sizeof(struct D2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct D2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct D2_extra_size) == 10, "");
_Static_assert(_Alignof(struct D2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(D2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(D2,e) == 0, "");
#endif
_Static_assert(sizeof(F2) == 16, "");
_Static_assert(_Alignof(F2) == 16, "");
_Static_assert(sizeof(struct F2_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct F2_extra_alignment) == 16, "");
_Static_assert(sizeof(struct F2_extra_packed) == 16, "");
_Static_assert(_Alignof(struct F2_extra_packed) == 1, "");
_Static_assert(sizeof(struct F2_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct F2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct F2_extra_size) == 18, "");
_Static_assert(_Alignof(struct F2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(F2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(F2,e) == 0, "");
#endif
_Static_assert(sizeof(G2) == 8, "");
_Static_assert(_Alignof(G2) == 2, "");
_Static_assert(sizeof(struct G2_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct G2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct G2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct G2_extra_packed) == 1, "");
_Static_assert(sizeof(struct G2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct G2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct G2_extra_size) == 10, "");
_Static_assert(_Alignof(struct G2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(G2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(G2,e) == 0, "");
#endif
_Static_assert(sizeof(H2) == 8, "");
_Static_assert(_Alignof(H2) == 2, "");
_Static_assert(sizeof(struct H2_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct H2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct H2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct H2_extra_packed) == 1, "");
_Static_assert(sizeof(struct H2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct H2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct H2_extra_size) == 10, "");
_Static_assert(_Alignof(struct H2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(H2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(H2,e) == 0, "");
#endif
_Static_assert(sizeof(I2) == 8, "");
_Static_assert(_Alignof(I2) == 1, "");
_Static_assert(sizeof(struct I2_extra_alignment) == 9, "");
_Static_assert(_Alignof(struct I2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct I2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct I2_extra_packed) == 1, "");
_Static_assert(sizeof(struct I2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct I2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct I2_extra_size) == 10, "");
_Static_assert(_Alignof(struct I2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(I2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(I2,e) == 0, "");
#endif
_Static_assert(sizeof(J2) == 8, "");
_Static_assert(_Alignof(J2) == 2, "");
_Static_assert(sizeof(struct J2_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct J2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct J2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct J2_extra_packed) == 1, "");
_Static_assert(sizeof(struct J2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct J2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct J2_extra_size) == 10, "");
_Static_assert(_Alignof(struct J2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(J2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(J2,e) == 0, "");
#endif
_Static_assert(sizeof(K2) == 8, "");
_Static_assert(_Alignof(K2) == 8, "");
_Static_assert(sizeof(struct K2_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct K2_extra_alignment) == 8, "");
_Static_assert(sizeof(struct K2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct K2_extra_packed) == 1, "");
_Static_assert(sizeof(struct K2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct K2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct K2_extra_size) == 10, "");
_Static_assert(_Alignof(struct K2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(K2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(K2,e) == 0, "");
#endif
_Static_assert(sizeof(L2) == 16, "");
_Static_assert(_Alignof(L2) == 16, "");
_Static_assert(sizeof(struct L2_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct L2_extra_alignment) == 16, "");
_Static_assert(sizeof(struct L2_extra_packed) == 16, "");
_Static_assert(_Alignof(struct L2_extra_packed) == 1, "");
_Static_assert(sizeof(struct L2_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct L2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct L2_extra_size) == 18, "");
_Static_assert(_Alignof(struct L2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(L2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(L2,e) == 0, "");
#endif
_Static_assert(sizeof(M2) == 2, "");
_Static_assert(_Alignof(M2) == 2, "");
_Static_assert(sizeof(struct M2_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct M2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct M2_extra_packed) == 2, "");
_Static_assert(_Alignof(struct M2_extra_packed) == 1, "");
_Static_assert(sizeof(struct M2_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct M2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct M2_extra_size) == 4, "");
_Static_assert(_Alignof(struct M2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(M2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(M2,e) == 0, "");
#endif
_Static_assert(sizeof(N2) == 2, "");
_Static_assert(_Alignof(N2) == 2, "");
_Static_assert(sizeof(struct N2_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct N2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct N2_extra_packed) == 2, "");
_Static_assert(_Alignof(struct N2_extra_packed) == 1, "");
_Static_assert(sizeof(struct N2_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct N2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct N2_extra_size) == 4, "");
_Static_assert(_Alignof(struct N2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(N2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(N2,e) == 0, "");
#endif
_Static_assert(sizeof(O2) == 1, "");
_Static_assert(_Alignof(O2) == 1, "");
_Static_assert(sizeof(struct O2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct O2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct O2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct O2_extra_packed) == 1, "");
_Static_assert(sizeof(struct O2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct O2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct O2_extra_size) == 3, "");
_Static_assert(_Alignof(struct O2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(O2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(O2,e) == 0, "");
#endif
_Static_assert(sizeof(P2) == 2, "");
_Static_assert(_Alignof(P2) == 2, "");
_Static_assert(sizeof(struct P2_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct P2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct P2_extra_packed) == 2, "");
_Static_assert(_Alignof(struct P2_extra_packed) == 1, "");
_Static_assert(sizeof(struct P2_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct P2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct P2_extra_size) == 4, "");
_Static_assert(_Alignof(struct P2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(P2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(P2,e) == 0, "");
#endif
_Static_assert(sizeof(Q2) == 8, "");
_Static_assert(_Alignof(Q2) == 8, "");
_Static_assert(sizeof(struct Q2_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct Q2_extra_alignment) == 8, "");
_Static_assert(sizeof(struct Q2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct Q2_extra_packed) == 1, "");
_Static_assert(sizeof(struct Q2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct Q2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct Q2_extra_size) == 10, "");
_Static_assert(_Alignof(struct Q2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(Q2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(Q2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(Q2,e) == 0, "");
#endif
_Static_assert(sizeof(R2) == 16, "");
_Static_assert(_Alignof(R2) == 16, "");
_Static_assert(sizeof(struct R2_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct R2_extra_alignment) == 16, "");
_Static_assert(sizeof(struct R2_extra_packed) == 16, "");
_Static_assert(_Alignof(struct R2_extra_packed) == 1, "");
_Static_assert(sizeof(struct R2_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct R2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct R2_extra_size) == 18, "");
_Static_assert(_Alignof(struct R2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(R2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(R2,e) == 0, "");
#endif
_Static_assert(sizeof(S2) == 8, "");
_Static_assert(_Alignof(S2) == 8, "");
_Static_assert(sizeof(struct S2_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct S2_extra_alignment) == 8, "");
_Static_assert(sizeof(struct S2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct S2_extra_packed) == 1, "");
_Static_assert(sizeof(struct S2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct S2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct S2_extra_size) == 10, "");
_Static_assert(_Alignof(struct S2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(S2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(S2,e) == 0, "");
#endif
_Static_assert(sizeof(T2) == 8, "");
_Static_assert(_Alignof(T2) == 8, "");
_Static_assert(sizeof(struct T2_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct T2_extra_alignment) == 8, "");
_Static_assert(sizeof(struct T2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct T2_extra_packed) == 1, "");
_Static_assert(sizeof(struct T2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct T2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct T2_extra_size) == 10, "");
_Static_assert(_Alignof(struct T2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(T2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(T2,e) == 0, "");
#endif
_Static_assert(sizeof(U2) == 8, "");
_Static_assert(_Alignof(U2) == 8, "");
_Static_assert(sizeof(struct U2_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct U2_extra_alignment) == 8, "");
_Static_assert(sizeof(struct U2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct U2_extra_packed) == 1, "");
_Static_assert(sizeof(struct U2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct U2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct U2_extra_size) == 10, "");
_Static_assert(_Alignof(struct U2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(U2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(U2,e) == 0, "");
#endif
_Static_assert(sizeof(V2) == 8, "");
_Static_assert(_Alignof(V2) == 8, "");
_Static_assert(sizeof(struct V2_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct V2_extra_alignment) == 8, "");
_Static_assert(sizeof(struct V2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct V2_extra_packed) == 1, "");
_Static_assert(sizeof(struct V2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct V2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct V2_extra_size) == 10, "");
_Static_assert(_Alignof(struct V2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(V2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(V2,e) == 0, "");
#endif
_Static_assert(sizeof(W2) == 16, "");
_Static_assert(_Alignof(W2) == 16, "");
_Static_assert(sizeof(struct W2_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct W2_extra_alignment) == 16, "");
_Static_assert(sizeof(struct W2_extra_packed) == 16, "");
_Static_assert(_Alignof(struct W2_extra_packed) == 1, "");
_Static_assert(sizeof(struct W2_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct W2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct W2_extra_size) == 18, "");
_Static_assert(_Alignof(struct W2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(W2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(W2,e) == 0, "");
#endif
_Static_assert(sizeof(W_2) == 16, "");
_Static_assert(_Alignof(W_2) == 16, "");
_Static_assert(sizeof(struct W_2_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct W_2_extra_alignment) == 16, "");
_Static_assert(sizeof(struct W_2_extra_packed) == 16, "");
_Static_assert(_Alignof(struct W_2_extra_packed) == 1, "");
_Static_assert(sizeof(struct W_2_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct W_2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct W_2_extra_size) == 18, "");
_Static_assert(_Alignof(struct W_2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(W_2,e) == 0, "");
#endif
_Static_assert(sizeof(X2) == 16, "");
_Static_assert(_Alignof(X2) == 16, "");
_Static_assert(sizeof(struct X2_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct X2_extra_alignment) == 16, "");
_Static_assert(sizeof(struct X2_extra_packed) == 16, "");
_Static_assert(_Alignof(struct X2_extra_packed) == 1, "");
_Static_assert(sizeof(struct X2_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct X2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct X2_extra_size) == 18, "");
_Static_assert(_Alignof(struct X2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(X2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(X2,e) == 0, "");
#endif
_Static_assert(sizeof(Y) == 16, "");
_Static_assert(_Alignof(Y) == 8, "");
_Static_assert(sizeof(struct Y_extra_alignment) == 24, "");
_Static_assert(_Alignof(struct Y_extra_alignment) == 8, "");
_Static_assert(sizeof(struct Y_extra_packed) == 16, "");
_Static_assert(_Alignof(struct Y_extra_packed) == 1, "");
_Static_assert(sizeof(struct Y_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct Y_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct Y_extra_size) == 18, "");
_Static_assert(_Alignof(struct Y_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(Y,d) == 64, "");
#endif
_Static_assert(sizeof(Y2) == 8, "");
_Static_assert(_Alignof(Y2) == 8, "");
_Static_assert(sizeof(struct Y2_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct Y2_extra_alignment) == 8, "");
_Static_assert(sizeof(struct Y2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct Y2_extra_packed) == 1, "");
_Static_assert(sizeof(struct Y2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct Y2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct Y2_extra_size) == 10, "");
_Static_assert(_Alignof(struct Y2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(Y2,d) == 0, "");
#endif
_Static_assert(sizeof(A3) == 64, "");
_Static_assert(_Alignof(A3) == 32, "");
_Static_assert(sizeof(struct A3_extra_alignment) == 96, "");
_Static_assert(_Alignof(struct A3_extra_alignment) == 32, "");
_Static_assert(sizeof(struct A3_extra_packed) == 64, "");
_Static_assert(_Alignof(struct A3_extra_packed) == 1, "");
_Static_assert(sizeof(struct A3_extra_required_alignment) == 65, "");
_Static_assert(_Alignof(struct A3_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A3_extra_size) == 66, "");
_Static_assert(_Alignof(struct A3_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A3,d) == 256, "");
#endif
_Static_assert(sizeof(A4) == 1, "");
_Static_assert(_Alignof(A4) == 32, "");
_Static_assert(sizeof(struct A4_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct A4_extra_alignment) == 32, "");
_Static_assert(sizeof(struct A4_extra_packed) == 1, "");
_Static_assert(_Alignof(struct A4_extra_packed) == 1, "");
_Static_assert(sizeof(struct A4_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct A4_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A4_extra_size) == 3, "");
_Static_assert(_Alignof(struct A4_extra_size) == 1, "");
_Static_assert(sizeof(A5) == 64, "");
_Static_assert(_Alignof(A5) == 32, "");
_Static_assert(sizeof(struct A5_extra_alignment) == 96, "");
_Static_assert(_Alignof(struct A5_extra_alignment) == 32, "");
_Static_assert(sizeof(struct A5_extra_packed) == 64, "");
_Static_assert(_Alignof(struct A5_extra_packed) == 1, "");
_Static_assert(sizeof(struct A5_extra_required_alignment) == 65, "");
_Static_assert(_Alignof(struct A5_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A5_extra_size) == 66, "");
_Static_assert(_Alignof(struct A5_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A5,d) == 256, "");
#endif
_Static_assert(sizeof(A7) == 32, "");
_Static_assert(_Alignof(A7) == 32, "");
_Static_assert(sizeof(struct A7_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct A7_extra_alignment) == 32, "");
_Static_assert(sizeof(struct A7_extra_packed) == 32, "");
_Static_assert(_Alignof(struct A7_extra_packed) == 1, "");
_Static_assert(sizeof(struct A7_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct A7_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A7_extra_size) == 34, "");
_Static_assert(_Alignof(struct A7_extra_size) == 1, "");
_Static_assert(sizeof(A8) == 8, "");
_Static_assert(_Alignof(A8) == 8, "");
_Static_assert(sizeof(struct A8_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct A8_extra_alignment) == 8, "");
_Static_assert(sizeof(struct A8_extra_packed) == 8, "");
_Static_assert(_Alignof(struct A8_extra_packed) == 1, "");
_Static_assert(sizeof(struct A8_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct A8_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A8_extra_size) == 10, "");
_Static_assert(_Alignof(struct A8_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A8,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A8,j) == 39, "");
#endif
_Static_assert(sizeof(A9) == 16, "");
_Static_assert(_Alignof(A9) == 8, "");
_Static_assert(sizeof(struct A9_extra_alignment) == 24, "");
_Static_assert(_Alignof(struct A9_extra_alignment) == 8, "");
_Static_assert(sizeof(struct A9_extra_packed) == 16, "");
_Static_assert(_Alignof(struct A9_extra_packed) == 1, "");
_Static_assert(sizeof(struct A9_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct A9_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A9_extra_size) == 18, "");
_Static_assert(_Alignof(struct A9_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A9,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A9,j) == 64, "");
#endif
_Static_assert(sizeof(A10) == 8, "");
_Static_assert(_Alignof(A10) == 16, "");
_Static_assert(sizeof(struct A10_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct A10_extra_alignment) == 16, "");
_Static_assert(sizeof(struct A10_extra_packed) == 8, "");
_Static_assert(_Alignof(struct A10_extra_packed) == 1, "");
_Static_assert(sizeof(struct A10_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct A10_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A10_extra_size) == 10, "");
_Static_assert(_Alignof(struct A10_extra_size) == 1, "");
_Static_assert(sizeof(A11) == 32, "");
_Static_assert(_Alignof(A11) == 16, "");
_Static_assert(sizeof(struct A11_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct A11_extra_alignment) == 16, "");
_Static_assert(sizeof(struct A11_extra_packed) == 32, "");
_Static_assert(_Alignof(struct A11_extra_packed) == 1, "");
_Static_assert(sizeof(struct A11_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct A11_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A11_extra_size) == 34, "");
_Static_assert(_Alignof(struct A11_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A11,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A11,j) == 128, "");
#endif
_Static_assert(sizeof(A12) == 32, "");
_Static_assert(_Alignof(A12) == 16, "");
_Static_assert(sizeof(struct A12_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct A12_extra_alignment) == 16, "");
_Static_assert(sizeof(struct A12_extra_packed) == 32, "");
_Static_assert(_Alignof(struct A12_extra_packed) == 1, "");
_Static_assert(sizeof(struct A12_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct A12_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A12_extra_size) == 34, "");
_Static_assert(_Alignof(struct A12_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A12,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A12,j) == 128, "");
#endif
_Static_assert(sizeof(A13) == 32, "");
_Static_assert(_Alignof(A13) == 16, "");
_Static_assert(sizeof(struct A13_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct A13_extra_alignment) == 16, "");
_Static_assert(sizeof(struct A13_extra_packed) == 32, "");
_Static_assert(_Alignof(struct A13_extra_packed) == 1, "");
_Static_assert(sizeof(struct A13_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct A13_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A13_extra_size) == 34, "");
_Static_assert(_Alignof(struct A13_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A13,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A13,j) == 128, "");
_Static_assert(__builtin_bitoffsetof(A13,d) == 136, "");
#endif
// MAPPING|FOUR|arm-baseline-other-eabi:Clang|arm-baseline-other-eabihf:Clang|arm-arm1136j_s-freebsd-gnueabihf:Clang|arm-arm1136j_s-netbsd-eabihf:Clang|arm-baseline-other-eabi:Clang|arm-baseline-other-eabihf:Clang|arm-cortex_r4-linux-android:Clang|arm-cortex_r4-other-eabi:Clang|arm-cortex_r4-other-eabihf:Clang|arm-cortex_r4-freebsd-gnueabihf:Clang|arm-cortex_r4-netbsd-eabihf:Clang|thumb-arm710t-other-eabi:Clang|thumb-cortex_m0-other-eabi:Clang|thumb-cortex_m4-other-eabihf:Clang|thumb-cortex_m4-other-eabi:Clang|thumb-cortex_m3-other-eabi:Clang|thumb-baseline-other-eabi:Clang|thumb-cortex_m33-other-eabihf:Clang|thumb-cortex_m33-other-eabi:Clang|END
// repr targets Armebv7rUnknownNoneEabi|Some("arm-baseline-other-eabi") Armebv7rUnknownNoneEabihf|Some("arm-baseline-other-eabihf") ArmLinuxAndroideabi|None Armv6UnknownFreebsdGnueabihf|Some("arm-arm1136j_s-freebsd-gnueabihf") Armv6UnknownNetbsdelfEabihf|Some("arm-arm1136j_s-netbsd-eabihf") Armv7aNoneEabi|Some("arm-baseline-other-eabi") Armv7aNoneEabihf|Some("arm-baseline-other-eabihf") Armv7NoneLinuxAndroid|Some("arm-cortex_r4-linux-android") Armv7rUnknownNoneEabi|Some("arm-cortex_r4-other-eabi") Armv7rUnknownNoneEabihf|Some("arm-cortex_r4-other-eabihf") Armv7UnknownFreebsdGnueabihf|Some("arm-cortex_r4-freebsd-gnueabihf") Armv7UnknownNetbsdelfEabihf|Some("arm-cortex_r4-netbsd-eabihf") Thumbv4tNoneEabi|Some("thumb-arm710t-other-eabi") Thumbv6mNoneEabi|Some("thumb-cortex_m0-other-eabi") Thumbv7emNoneEabihf|Some("thumb-cortex_m4-other-eabihf") Thumbv7emNoneEabi|Some("thumb-cortex_m4-other-eabi") Thumbv7mNoneEabi|Some("thumb-cortex_m3-other-eabi") Thumbv8mBaseNoneEabi|Some("thumb-baseline-other-eabi") Thumbv8mMainNoneEabihf|Some("thumb-cortex_m33-other-eabihf") Thumbv8mMainNoneEabi|Some("thumb-cortex_m33-other-eabi") 
#elif defined(FOUR)
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
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A,d) == 0, "");
#endif
_Static_assert(sizeof(A_) == 8, "");
_Static_assert(_Alignof(A_) == 4, "");
_Static_assert(sizeof(struct A__extra_alignment) == 12, "");
_Static_assert(_Alignof(struct A__extra_alignment) == 4, "");
_Static_assert(sizeof(struct A__extra_packed) == 8, "");
_Static_assert(_Alignof(struct A__extra_packed) == 1, "");
_Static_assert(sizeof(struct A__extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct A__extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A__extra_size) == 10, "");
_Static_assert(_Alignof(struct A__extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_,d) == 32, "");
#endif
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
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B,d) == 0, "");
#endif
_Static_assert(sizeof(B_) == 16, "");
_Static_assert(_Alignof(B_) == 8, "");
_Static_assert(sizeof(struct B__extra_alignment) == 24, "");
_Static_assert(_Alignof(struct B__extra_alignment) == 8, "");
_Static_assert(sizeof(struct B__extra_packed) == 16, "");
_Static_assert(_Alignof(struct B__extra_packed) == 1, "");
_Static_assert(sizeof(struct B__extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct B__extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B__extra_size) == 18, "");
_Static_assert(_Alignof(struct B__extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B_,d) == 64, "");
#endif
_Static_assert(sizeof(C) == 8, "");
_Static_assert(_Alignof(C) == 8, "");
_Static_assert(sizeof(struct C_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct C_extra_alignment) == 8, "");
_Static_assert(sizeof(struct C_extra_packed) == 8, "");
_Static_assert(_Alignof(struct C_extra_packed) == 1, "");
_Static_assert(sizeof(struct C_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct C_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct C_extra_size) == 10, "");
_Static_assert(_Alignof(struct C_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(C,d) == 0, "");
#endif
_Static_assert(sizeof(C_) == 16, "");
_Static_assert(_Alignof(C_) == 8, "");
_Static_assert(sizeof(struct C__extra_alignment) == 24, "");
_Static_assert(_Alignof(struct C__extra_alignment) == 8, "");
_Static_assert(sizeof(struct C__extra_packed) == 16, "");
_Static_assert(_Alignof(struct C__extra_packed) == 1, "");
_Static_assert(sizeof(struct C__extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct C__extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct C__extra_size) == 18, "");
_Static_assert(_Alignof(struct C__extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(C_,d) == 64, "");
#endif
_Static_assert(sizeof(D) == 24, "");
_Static_assert(_Alignof(D) == 8, "");
_Static_assert(sizeof(struct D_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct D_extra_alignment) == 8, "");
_Static_assert(sizeof(struct D_extra_packed) == 24, "");
_Static_assert(_Alignof(struct D_extra_packed) == 1, "");
_Static_assert(sizeof(struct D_extra_required_alignment) == 25, "");
_Static_assert(_Alignof(struct D_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct D_extra_size) == 26, "");
_Static_assert(_Alignof(struct D_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(D,d) == 64, "");
_Static_assert(__builtin_bitoffsetof(D,e) == 128, "");
#endif
_Static_assert(sizeof(F) == 32, "");
_Static_assert(_Alignof(F) == 16, "");
_Static_assert(sizeof(struct F_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct F_extra_alignment) == 16, "");
_Static_assert(sizeof(struct F_extra_packed) == 32, "");
_Static_assert(_Alignof(struct F_extra_packed) == 1, "");
_Static_assert(sizeof(struct F_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct F_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct F_extra_size) == 34, "");
_Static_assert(_Alignof(struct F_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(F,d) == 128, "");
_Static_assert(__builtin_bitoffsetof(F,e) == 192, "");
#endif
_Static_assert(sizeof(G) == 12, "");
_Static_assert(_Alignof(G) == 2, "");
_Static_assert(sizeof(struct G_extra_alignment) == 14, "");
_Static_assert(_Alignof(struct G_extra_alignment) == 2, "");
_Static_assert(sizeof(struct G_extra_packed) == 12, "");
_Static_assert(_Alignof(struct G_extra_packed) == 1, "");
_Static_assert(sizeof(struct G_extra_required_alignment) == 13, "");
_Static_assert(_Alignof(struct G_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct G_extra_size) == 14, "");
_Static_assert(_Alignof(struct G_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(G,d) == 16, "");
_Static_assert(__builtin_bitoffsetof(G,e) == 80, "");
#endif
_Static_assert(sizeof(H) == 12, "");
_Static_assert(_Alignof(H) == 2, "");
_Static_assert(sizeof(struct H_extra_alignment) == 14, "");
_Static_assert(_Alignof(struct H_extra_alignment) == 2, "");
_Static_assert(sizeof(struct H_extra_packed) == 12, "");
_Static_assert(_Alignof(struct H_extra_packed) == 1, "");
_Static_assert(sizeof(struct H_extra_required_alignment) == 13, "");
_Static_assert(_Alignof(struct H_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct H_extra_size) == 14, "");
_Static_assert(_Alignof(struct H_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(H,d) == 16, "");
_Static_assert(__builtin_bitoffsetof(H,e) == 80, "");
#endif
_Static_assert(sizeof(I) == 10, "");
_Static_assert(_Alignof(I) == 1, "");
_Static_assert(sizeof(struct I_extra_alignment) == 11, "");
_Static_assert(_Alignof(struct I_extra_alignment) == 1, "");
_Static_assert(sizeof(struct I_extra_packed) == 10, "");
_Static_assert(_Alignof(struct I_extra_packed) == 1, "");
_Static_assert(sizeof(struct I_extra_required_alignment) == 11, "");
_Static_assert(_Alignof(struct I_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct I_extra_size) == 12, "");
_Static_assert(_Alignof(struct I_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(I,d) == 8, "");
_Static_assert(__builtin_bitoffsetof(I,e) == 72, "");
#endif
_Static_assert(sizeof(J) == 12, "");
_Static_assert(_Alignof(J) == 2, "");
_Static_assert(sizeof(struct J_extra_alignment) == 14, "");
_Static_assert(_Alignof(struct J_extra_alignment) == 2, "");
_Static_assert(sizeof(struct J_extra_packed) == 12, "");
_Static_assert(_Alignof(struct J_extra_packed) == 1, "");
_Static_assert(sizeof(struct J_extra_required_alignment) == 13, "");
_Static_assert(_Alignof(struct J_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct J_extra_size) == 14, "");
_Static_assert(_Alignof(struct J_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(J,d) == 16, "");
_Static_assert(__builtin_bitoffsetof(J,e) == 80, "");
#endif
_Static_assert(sizeof(K) == 8, "");
_Static_assert(_Alignof(K) == 8, "");
_Static_assert(sizeof(struct K_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct K_extra_alignment) == 8, "");
_Static_assert(sizeof(struct K_extra_packed) == 8, "");
_Static_assert(_Alignof(struct K_extra_packed) == 1, "");
_Static_assert(sizeof(struct K_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct K_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct K_extra_size) == 10, "");
_Static_assert(_Alignof(struct K_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(K,d) == 8, "");
_Static_assert(__builtin_bitoffsetof(K,e) == 16, "");
#endif
_Static_assert(sizeof(L) == 32, "");
_Static_assert(_Alignof(L) == 16, "");
_Static_assert(sizeof(struct L_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct L_extra_alignment) == 16, "");
_Static_assert(sizeof(struct L_extra_packed) == 32, "");
_Static_assert(_Alignof(struct L_extra_packed) == 1, "");
_Static_assert(sizeof(struct L_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct L_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct L_extra_size) == 34, "");
_Static_assert(_Alignof(struct L_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(L,d) == 128, "");
_Static_assert(__builtin_bitoffsetof(L,e) == 136, "");
#endif
_Static_assert(sizeof(M) == 4, "");
_Static_assert(_Alignof(M) == 2, "");
_Static_assert(sizeof(struct M_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct M_extra_alignment) == 2, "");
_Static_assert(sizeof(struct M_extra_packed) == 4, "");
_Static_assert(_Alignof(struct M_extra_packed) == 1, "");
_Static_assert(sizeof(struct M_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct M_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct M_extra_size) == 6, "");
_Static_assert(_Alignof(struct M_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(M,d) == 16, "");
_Static_assert(__builtin_bitoffsetof(M,e) == 24, "");
#endif
_Static_assert(sizeof(N) == 4, "");
_Static_assert(_Alignof(N) == 2, "");
_Static_assert(sizeof(struct N_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct N_extra_alignment) == 2, "");
_Static_assert(sizeof(struct N_extra_packed) == 4, "");
_Static_assert(_Alignof(struct N_extra_packed) == 1, "");
_Static_assert(sizeof(struct N_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct N_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct N_extra_size) == 6, "");
_Static_assert(_Alignof(struct N_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(N,d) == 8, "");
_Static_assert(__builtin_bitoffsetof(N,e) == 16, "");
#endif
_Static_assert(sizeof(O) == 3, "");
_Static_assert(_Alignof(O) == 1, "");
_Static_assert(sizeof(struct O_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct O_extra_alignment) == 1, "");
_Static_assert(sizeof(struct O_extra_packed) == 3, "");
_Static_assert(_Alignof(struct O_extra_packed) == 1, "");
_Static_assert(sizeof(struct O_extra_required_alignment) == 4, "");
_Static_assert(_Alignof(struct O_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct O_extra_size) == 5, "");
_Static_assert(_Alignof(struct O_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(O,d) == 8, "");
_Static_assert(__builtin_bitoffsetof(O,e) == 16, "");
#endif
_Static_assert(sizeof(P) == 4, "");
_Static_assert(_Alignof(P) == 2, "");
_Static_assert(sizeof(struct P_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct P_extra_alignment) == 2, "");
_Static_assert(sizeof(struct P_extra_packed) == 4, "");
_Static_assert(_Alignof(struct P_extra_packed) == 1, "");
_Static_assert(sizeof(struct P_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct P_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct P_extra_size) == 6, "");
_Static_assert(_Alignof(struct P_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(P,d) == 8, "");
_Static_assert(__builtin_bitoffsetof(P,e) == 16, "");
#endif
_Static_assert(sizeof(Q) == 8, "");
_Static_assert(_Alignof(Q) == 8, "");
_Static_assert(sizeof(struct Q_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct Q_extra_alignment) == 8, "");
_Static_assert(sizeof(struct Q_extra_packed) == 8, "");
_Static_assert(_Alignof(struct Q_extra_packed) == 1, "");
_Static_assert(sizeof(struct Q_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct Q_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct Q_extra_size) == 10, "");
_Static_assert(_Alignof(struct Q_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(Q,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(Q,d) == 9, "");
_Static_assert(__builtin_bitoffsetof(Q,e) == 16, "");
#endif
_Static_assert(sizeof(R) == 32, "");
_Static_assert(_Alignof(R) == 16, "");
_Static_assert(sizeof(struct R_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct R_extra_alignment) == 16, "");
_Static_assert(sizeof(struct R_extra_packed) == 32, "");
_Static_assert(_Alignof(struct R_extra_packed) == 1, "");
_Static_assert(sizeof(struct R_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct R_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct R_extra_size) == 34, "");
_Static_assert(_Alignof(struct R_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(R,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(R,e) == 128, "");
#endif
_Static_assert(sizeof(S) == 16, "");
_Static_assert(_Alignof(S) == 8, "");
_Static_assert(sizeof(struct S_extra_alignment) == 24, "");
_Static_assert(_Alignof(struct S_extra_alignment) == 8, "");
_Static_assert(sizeof(struct S_extra_packed) == 16, "");
_Static_assert(_Alignof(struct S_extra_packed) == 1, "");
_Static_assert(sizeof(struct S_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct S_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct S_extra_size) == 18, "");
_Static_assert(_Alignof(struct S_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(S,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(S,e) == 64, "");
#endif
_Static_assert(sizeof(T) == 16, "");
_Static_assert(_Alignof(T) == 8, "");
_Static_assert(sizeof(struct T_extra_alignment) == 24, "");
_Static_assert(_Alignof(struct T_extra_alignment) == 8, "");
_Static_assert(sizeof(struct T_extra_packed) == 16, "");
_Static_assert(_Alignof(struct T_extra_packed) == 1, "");
_Static_assert(sizeof(struct T_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct T_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct T_extra_size) == 18, "");
_Static_assert(_Alignof(struct T_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(T,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(T,e) == 64, "");
#endif
_Static_assert(sizeof(U) == 16, "");
_Static_assert(_Alignof(U) == 8, "");
_Static_assert(sizeof(struct U_extra_alignment) == 24, "");
_Static_assert(_Alignof(struct U_extra_alignment) == 8, "");
_Static_assert(sizeof(struct U_extra_packed) == 16, "");
_Static_assert(_Alignof(struct U_extra_packed) == 1, "");
_Static_assert(sizeof(struct U_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct U_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct U_extra_size) == 18, "");
_Static_assert(_Alignof(struct U_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(U,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(U,e) == 64, "");
#endif
_Static_assert(sizeof(V) == 16, "");
_Static_assert(_Alignof(V) == 8, "");
_Static_assert(sizeof(struct V_extra_alignment) == 24, "");
_Static_assert(_Alignof(struct V_extra_alignment) == 8, "");
_Static_assert(sizeof(struct V_extra_packed) == 16, "");
_Static_assert(_Alignof(struct V_extra_packed) == 1, "");
_Static_assert(sizeof(struct V_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct V_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct V_extra_size) == 18, "");
_Static_assert(_Alignof(struct V_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(V,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(V,e) == 64, "");
#endif
_Static_assert(sizeof(W) == 32, "");
_Static_assert(_Alignof(W) == 16, "");
_Static_assert(sizeof(struct W_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct W_extra_alignment) == 16, "");
_Static_assert(sizeof(struct W_extra_packed) == 32, "");
_Static_assert(_Alignof(struct W_extra_packed) == 1, "");
_Static_assert(sizeof(struct W_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct W_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct W_extra_size) == 34, "");
_Static_assert(_Alignof(struct W_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(W,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(W,e) == 128, "");
#endif
_Static_assert(sizeof(W_) == 32, "");
_Static_assert(_Alignof(W_) == 16, "");
_Static_assert(sizeof(struct W__extra_alignment) == 48, "");
_Static_assert(_Alignof(struct W__extra_alignment) == 16, "");
_Static_assert(sizeof(struct W__extra_packed) == 32, "");
_Static_assert(_Alignof(struct W__extra_packed) == 1, "");
_Static_assert(sizeof(struct W__extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct W__extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct W__extra_size) == 34, "");
_Static_assert(_Alignof(struct W__extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(W_,e) == 128, "");
#endif
_Static_assert(sizeof(X) == 32, "");
_Static_assert(_Alignof(X) == 16, "");
_Static_assert(sizeof(struct X_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct X_extra_alignment) == 16, "");
_Static_assert(sizeof(struct X_extra_packed) == 32, "");
_Static_assert(_Alignof(struct X_extra_packed) == 1, "");
_Static_assert(sizeof(struct X_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct X_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct X_extra_size) == 34, "");
_Static_assert(_Alignof(struct X_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(X,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(X,e) == 128, "");
#endif
_Static_assert(sizeof(A2) == 4, "");
_Static_assert(_Alignof(A2) == 4, "");
_Static_assert(sizeof(struct A2_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct A2_extra_alignment) == 4, "");
_Static_assert(sizeof(struct A2_extra_packed) == 4, "");
_Static_assert(_Alignof(struct A2_extra_packed) == 1, "");
_Static_assert(sizeof(struct A2_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct A2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A2_extra_size) == 6, "");
_Static_assert(_Alignof(struct A2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A2,d) == 0, "");
#endif
_Static_assert(sizeof(A_2) == 4, "");
_Static_assert(_Alignof(A_2) == 4, "");
_Static_assert(sizeof(struct A_2_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct A_2_extra_alignment) == 4, "");
_Static_assert(sizeof(struct A_2_extra_packed) == 4, "");
_Static_assert(_Alignof(struct A_2_extra_packed) == 1, "");
_Static_assert(sizeof(struct A_2_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct A_2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A_2_extra_size) == 6, "");
_Static_assert(_Alignof(struct A_2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_2,d) == 0, "");
#endif
_Static_assert(sizeof(B2) == 8, "");
_Static_assert(_Alignof(B2) == 8, "");
_Static_assert(sizeof(struct B2_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct B2_extra_alignment) == 8, "");
_Static_assert(sizeof(struct B2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct B2_extra_packed) == 1, "");
_Static_assert(sizeof(struct B2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct B2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B2_extra_size) == 10, "");
_Static_assert(_Alignof(struct B2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B2,d) == 0, "");
#endif
_Static_assert(sizeof(B_2) == 8, "");
_Static_assert(_Alignof(B_2) == 8, "");
_Static_assert(sizeof(struct B_2_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct B_2_extra_alignment) == 8, "");
_Static_assert(sizeof(struct B_2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct B_2_extra_packed) == 1, "");
_Static_assert(sizeof(struct B_2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct B_2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B_2_extra_size) == 10, "");
_Static_assert(_Alignof(struct B_2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B_2,d) == 0, "");
#endif
_Static_assert(sizeof(C2) == 8, "");
_Static_assert(_Alignof(C2) == 8, "");
_Static_assert(sizeof(struct C2_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct C2_extra_alignment) == 8, "");
_Static_assert(sizeof(struct C2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct C2_extra_packed) == 1, "");
_Static_assert(sizeof(struct C2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct C2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct C2_extra_size) == 10, "");
_Static_assert(_Alignof(struct C2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(C2,d) == 0, "");
#endif
_Static_assert(sizeof(C22) == 8, "");
_Static_assert(_Alignof(C22) == 8, "");
_Static_assert(sizeof(struct C22_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct C22_extra_alignment) == 8, "");
_Static_assert(sizeof(struct C22_extra_packed) == 8, "");
_Static_assert(_Alignof(struct C22_extra_packed) == 1, "");
_Static_assert(sizeof(struct C22_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct C22_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct C22_extra_size) == 10, "");
_Static_assert(_Alignof(struct C22_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(C22,d) == 0, "");
#endif
_Static_assert(sizeof(D2) == 8, "");
_Static_assert(_Alignof(D2) == 8, "");
_Static_assert(sizeof(struct D2_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct D2_extra_alignment) == 8, "");
_Static_assert(sizeof(struct D2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct D2_extra_packed) == 1, "");
_Static_assert(sizeof(struct D2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct D2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct D2_extra_size) == 10, "");
_Static_assert(_Alignof(struct D2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(D2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(D2,e) == 0, "");
#endif
_Static_assert(sizeof(F2) == 16, "");
_Static_assert(_Alignof(F2) == 16, "");
_Static_assert(sizeof(struct F2_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct F2_extra_alignment) == 16, "");
_Static_assert(sizeof(struct F2_extra_packed) == 16, "");
_Static_assert(_Alignof(struct F2_extra_packed) == 1, "");
_Static_assert(sizeof(struct F2_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct F2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct F2_extra_size) == 18, "");
_Static_assert(_Alignof(struct F2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(F2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(F2,e) == 0, "");
#endif
_Static_assert(sizeof(G2) == 8, "");
_Static_assert(_Alignof(G2) == 2, "");
_Static_assert(sizeof(struct G2_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct G2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct G2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct G2_extra_packed) == 1, "");
_Static_assert(sizeof(struct G2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct G2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct G2_extra_size) == 10, "");
_Static_assert(_Alignof(struct G2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(G2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(G2,e) == 0, "");
#endif
_Static_assert(sizeof(H2) == 8, "");
_Static_assert(_Alignof(H2) == 2, "");
_Static_assert(sizeof(struct H2_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct H2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct H2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct H2_extra_packed) == 1, "");
_Static_assert(sizeof(struct H2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct H2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct H2_extra_size) == 10, "");
_Static_assert(_Alignof(struct H2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(H2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(H2,e) == 0, "");
#endif
_Static_assert(sizeof(I2) == 8, "");
_Static_assert(_Alignof(I2) == 1, "");
_Static_assert(sizeof(struct I2_extra_alignment) == 9, "");
_Static_assert(_Alignof(struct I2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct I2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct I2_extra_packed) == 1, "");
_Static_assert(sizeof(struct I2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct I2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct I2_extra_size) == 10, "");
_Static_assert(_Alignof(struct I2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(I2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(I2,e) == 0, "");
#endif
_Static_assert(sizeof(J2) == 8, "");
_Static_assert(_Alignof(J2) == 2, "");
_Static_assert(sizeof(struct J2_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct J2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct J2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct J2_extra_packed) == 1, "");
_Static_assert(sizeof(struct J2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct J2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct J2_extra_size) == 10, "");
_Static_assert(_Alignof(struct J2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(J2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(J2,e) == 0, "");
#endif
_Static_assert(sizeof(K2) == 8, "");
_Static_assert(_Alignof(K2) == 8, "");
_Static_assert(sizeof(struct K2_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct K2_extra_alignment) == 8, "");
_Static_assert(sizeof(struct K2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct K2_extra_packed) == 1, "");
_Static_assert(sizeof(struct K2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct K2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct K2_extra_size) == 10, "");
_Static_assert(_Alignof(struct K2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(K2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(K2,e) == 0, "");
#endif
_Static_assert(sizeof(L2) == 16, "");
_Static_assert(_Alignof(L2) == 16, "");
_Static_assert(sizeof(struct L2_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct L2_extra_alignment) == 16, "");
_Static_assert(sizeof(struct L2_extra_packed) == 16, "");
_Static_assert(_Alignof(struct L2_extra_packed) == 1, "");
_Static_assert(sizeof(struct L2_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct L2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct L2_extra_size) == 18, "");
_Static_assert(_Alignof(struct L2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(L2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(L2,e) == 0, "");
#endif
_Static_assert(sizeof(M2) == 2, "");
_Static_assert(_Alignof(M2) == 2, "");
_Static_assert(sizeof(struct M2_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct M2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct M2_extra_packed) == 2, "");
_Static_assert(_Alignof(struct M2_extra_packed) == 1, "");
_Static_assert(sizeof(struct M2_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct M2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct M2_extra_size) == 4, "");
_Static_assert(_Alignof(struct M2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(M2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(M2,e) == 0, "");
#endif
_Static_assert(sizeof(N2) == 2, "");
_Static_assert(_Alignof(N2) == 2, "");
_Static_assert(sizeof(struct N2_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct N2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct N2_extra_packed) == 2, "");
_Static_assert(_Alignof(struct N2_extra_packed) == 1, "");
_Static_assert(sizeof(struct N2_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct N2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct N2_extra_size) == 4, "");
_Static_assert(_Alignof(struct N2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(N2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(N2,e) == 0, "");
#endif
_Static_assert(sizeof(O2) == 1, "");
_Static_assert(_Alignof(O2) == 1, "");
_Static_assert(sizeof(struct O2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct O2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct O2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct O2_extra_packed) == 1, "");
_Static_assert(sizeof(struct O2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct O2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct O2_extra_size) == 3, "");
_Static_assert(_Alignof(struct O2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(O2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(O2,e) == 0, "");
#endif
_Static_assert(sizeof(P2) == 2, "");
_Static_assert(_Alignof(P2) == 2, "");
_Static_assert(sizeof(struct P2_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct P2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct P2_extra_packed) == 2, "");
_Static_assert(_Alignof(struct P2_extra_packed) == 1, "");
_Static_assert(sizeof(struct P2_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct P2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct P2_extra_size) == 4, "");
_Static_assert(_Alignof(struct P2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(P2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(P2,e) == 0, "");
#endif
_Static_assert(sizeof(Q2) == 8, "");
_Static_assert(_Alignof(Q2) == 8, "");
_Static_assert(sizeof(struct Q2_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct Q2_extra_alignment) == 8, "");
_Static_assert(sizeof(struct Q2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct Q2_extra_packed) == 1, "");
_Static_assert(sizeof(struct Q2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct Q2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct Q2_extra_size) == 10, "");
_Static_assert(_Alignof(struct Q2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(Q2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(Q2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(Q2,e) == 0, "");
#endif
_Static_assert(sizeof(R2) == 16, "");
_Static_assert(_Alignof(R2) == 16, "");
_Static_assert(sizeof(struct R2_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct R2_extra_alignment) == 16, "");
_Static_assert(sizeof(struct R2_extra_packed) == 16, "");
_Static_assert(_Alignof(struct R2_extra_packed) == 1, "");
_Static_assert(sizeof(struct R2_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct R2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct R2_extra_size) == 18, "");
_Static_assert(_Alignof(struct R2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(R2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(R2,e) == 0, "");
#endif
_Static_assert(sizeof(S2) == 8, "");
_Static_assert(_Alignof(S2) == 8, "");
_Static_assert(sizeof(struct S2_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct S2_extra_alignment) == 8, "");
_Static_assert(sizeof(struct S2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct S2_extra_packed) == 1, "");
_Static_assert(sizeof(struct S2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct S2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct S2_extra_size) == 10, "");
_Static_assert(_Alignof(struct S2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(S2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(S2,e) == 0, "");
#endif
_Static_assert(sizeof(T2) == 8, "");
_Static_assert(_Alignof(T2) == 8, "");
_Static_assert(sizeof(struct T2_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct T2_extra_alignment) == 8, "");
_Static_assert(sizeof(struct T2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct T2_extra_packed) == 1, "");
_Static_assert(sizeof(struct T2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct T2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct T2_extra_size) == 10, "");
_Static_assert(_Alignof(struct T2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(T2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(T2,e) == 0, "");
#endif
_Static_assert(sizeof(U2) == 8, "");
_Static_assert(_Alignof(U2) == 8, "");
_Static_assert(sizeof(struct U2_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct U2_extra_alignment) == 8, "");
_Static_assert(sizeof(struct U2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct U2_extra_packed) == 1, "");
_Static_assert(sizeof(struct U2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct U2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct U2_extra_size) == 10, "");
_Static_assert(_Alignof(struct U2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(U2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(U2,e) == 0, "");
#endif
_Static_assert(sizeof(V2) == 8, "");
_Static_assert(_Alignof(V2) == 8, "");
_Static_assert(sizeof(struct V2_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct V2_extra_alignment) == 8, "");
_Static_assert(sizeof(struct V2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct V2_extra_packed) == 1, "");
_Static_assert(sizeof(struct V2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct V2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct V2_extra_size) == 10, "");
_Static_assert(_Alignof(struct V2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(V2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(V2,e) == 0, "");
#endif
_Static_assert(sizeof(W2) == 16, "");
_Static_assert(_Alignof(W2) == 16, "");
_Static_assert(sizeof(struct W2_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct W2_extra_alignment) == 16, "");
_Static_assert(sizeof(struct W2_extra_packed) == 16, "");
_Static_assert(_Alignof(struct W2_extra_packed) == 1, "");
_Static_assert(sizeof(struct W2_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct W2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct W2_extra_size) == 18, "");
_Static_assert(_Alignof(struct W2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(W2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(W2,e) == 0, "");
#endif
_Static_assert(sizeof(W_2) == 16, "");
_Static_assert(_Alignof(W_2) == 16, "");
_Static_assert(sizeof(struct W_2_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct W_2_extra_alignment) == 16, "");
_Static_assert(sizeof(struct W_2_extra_packed) == 16, "");
_Static_assert(_Alignof(struct W_2_extra_packed) == 1, "");
_Static_assert(sizeof(struct W_2_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct W_2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct W_2_extra_size) == 18, "");
_Static_assert(_Alignof(struct W_2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(W_2,e) == 0, "");
#endif
_Static_assert(sizeof(X2) == 16, "");
_Static_assert(_Alignof(X2) == 16, "");
_Static_assert(sizeof(struct X2_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct X2_extra_alignment) == 16, "");
_Static_assert(sizeof(struct X2_extra_packed) == 16, "");
_Static_assert(_Alignof(struct X2_extra_packed) == 1, "");
_Static_assert(sizeof(struct X2_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct X2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct X2_extra_size) == 18, "");
_Static_assert(_Alignof(struct X2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(X2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(X2,e) == 0, "");
#endif
_Static_assert(sizeof(Y) == 16, "");
_Static_assert(_Alignof(Y) == 8, "");
_Static_assert(sizeof(struct Y_extra_alignment) == 24, "");
_Static_assert(_Alignof(struct Y_extra_alignment) == 8, "");
_Static_assert(sizeof(struct Y_extra_packed) == 16, "");
_Static_assert(_Alignof(struct Y_extra_packed) == 1, "");
_Static_assert(sizeof(struct Y_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct Y_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct Y_extra_size) == 18, "");
_Static_assert(_Alignof(struct Y_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(Y,d) == 64, "");
#endif
_Static_assert(sizeof(Y2) == 8, "");
_Static_assert(_Alignof(Y2) == 8, "");
_Static_assert(sizeof(struct Y2_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct Y2_extra_alignment) == 8, "");
_Static_assert(sizeof(struct Y2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct Y2_extra_packed) == 1, "");
_Static_assert(sizeof(struct Y2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct Y2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct Y2_extra_size) == 10, "");
_Static_assert(_Alignof(struct Y2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(Y2,d) == 0, "");
#endif
_Static_assert(sizeof(A3) == 64, "");
_Static_assert(_Alignof(A3) == 32, "");
_Static_assert(sizeof(struct A3_extra_alignment) == 96, "");
_Static_assert(_Alignof(struct A3_extra_alignment) == 32, "");
_Static_assert(sizeof(struct A3_extra_packed) == 64, "");
_Static_assert(_Alignof(struct A3_extra_packed) == 1, "");
_Static_assert(sizeof(struct A3_extra_required_alignment) == 65, "");
_Static_assert(_Alignof(struct A3_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A3_extra_size) == 66, "");
_Static_assert(_Alignof(struct A3_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A3,d) == 256, "");
#endif
_Static_assert(sizeof(A4) == 1, "");
_Static_assert(_Alignof(A4) == 32, "");
_Static_assert(sizeof(struct A4_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct A4_extra_alignment) == 32, "");
_Static_assert(sizeof(struct A4_extra_packed) == 1, "");
_Static_assert(_Alignof(struct A4_extra_packed) == 1, "");
_Static_assert(sizeof(struct A4_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct A4_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A4_extra_size) == 3, "");
_Static_assert(_Alignof(struct A4_extra_size) == 1, "");
_Static_assert(sizeof(A5) == 64, "");
_Static_assert(_Alignof(A5) == 32, "");
_Static_assert(sizeof(struct A5_extra_alignment) == 96, "");
_Static_assert(_Alignof(struct A5_extra_alignment) == 32, "");
_Static_assert(sizeof(struct A5_extra_packed) == 64, "");
_Static_assert(_Alignof(struct A5_extra_packed) == 1, "");
_Static_assert(sizeof(struct A5_extra_required_alignment) == 65, "");
_Static_assert(_Alignof(struct A5_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A5_extra_size) == 66, "");
_Static_assert(_Alignof(struct A5_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A5,d) == 256, "");
#endif
_Static_assert(sizeof(A7) == 32, "");
_Static_assert(_Alignof(A7) == 32, "");
_Static_assert(sizeof(struct A7_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct A7_extra_alignment) == 32, "");
_Static_assert(sizeof(struct A7_extra_packed) == 32, "");
_Static_assert(_Alignof(struct A7_extra_packed) == 1, "");
_Static_assert(sizeof(struct A7_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct A7_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A7_extra_size) == 34, "");
_Static_assert(_Alignof(struct A7_extra_size) == 1, "");
_Static_assert(sizeof(A8) == 8, "");
_Static_assert(_Alignof(A8) == 4, "");
_Static_assert(sizeof(struct A8_extra_alignment) == 12, "");
_Static_assert(_Alignof(struct A8_extra_alignment) == 4, "");
_Static_assert(sizeof(struct A8_extra_packed) == 8, "");
_Static_assert(_Alignof(struct A8_extra_packed) == 1, "");
_Static_assert(sizeof(struct A8_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct A8_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A8_extra_size) == 10, "");
_Static_assert(_Alignof(struct A8_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A8,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A8,j) == 39, "");
#endif
_Static_assert(sizeof(A9) == 12, "");
_Static_assert(_Alignof(A9) == 4, "");
_Static_assert(sizeof(struct A9_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct A9_extra_alignment) == 4, "");
_Static_assert(sizeof(struct A9_extra_packed) == 12, "");
_Static_assert(_Alignof(struct A9_extra_packed) == 1, "");
_Static_assert(sizeof(struct A9_extra_required_alignment) == 13, "");
_Static_assert(_Alignof(struct A9_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A9_extra_size) == 14, "");
_Static_assert(_Alignof(struct A9_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A9,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A9,j) == 64, "");
#endif
_Static_assert(sizeof(A10) == 4, "");
_Static_assert(_Alignof(A10) == 16, "");
_Static_assert(sizeof(struct A10_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct A10_extra_alignment) == 16, "");
_Static_assert(sizeof(struct A10_extra_packed) == 4, "");
_Static_assert(_Alignof(struct A10_extra_packed) == 1, "");
_Static_assert(sizeof(struct A10_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct A10_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A10_extra_size) == 6, "");
_Static_assert(_Alignof(struct A10_extra_size) == 1, "");
_Static_assert(sizeof(A11) == 32, "");
_Static_assert(_Alignof(A11) == 16, "");
_Static_assert(sizeof(struct A11_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct A11_extra_alignment) == 16, "");
_Static_assert(sizeof(struct A11_extra_packed) == 32, "");
_Static_assert(_Alignof(struct A11_extra_packed) == 1, "");
_Static_assert(sizeof(struct A11_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct A11_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A11_extra_size) == 34, "");
_Static_assert(_Alignof(struct A11_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A11,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A11,j) == 128, "");
#endif
_Static_assert(sizeof(A12) == 32, "");
_Static_assert(_Alignof(A12) == 16, "");
_Static_assert(sizeof(struct A12_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct A12_extra_alignment) == 16, "");
_Static_assert(sizeof(struct A12_extra_packed) == 32, "");
_Static_assert(_Alignof(struct A12_extra_packed) == 1, "");
_Static_assert(sizeof(struct A12_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct A12_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A12_extra_size) == 34, "");
_Static_assert(_Alignof(struct A12_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A12,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A12,j) == 128, "");
#endif
_Static_assert(sizeof(A13) == 32, "");
_Static_assert(_Alignof(A13) == 16, "");
_Static_assert(sizeof(struct A13_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct A13_extra_alignment) == 16, "");
_Static_assert(sizeof(struct A13_extra_packed) == 32, "");
_Static_assert(_Alignof(struct A13_extra_packed) == 1, "");
_Static_assert(sizeof(struct A13_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct A13_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A13_extra_size) == 34, "");
_Static_assert(_Alignof(struct A13_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A13,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A13,j) == 128, "");
_Static_assert(__builtin_bitoffsetof(A13,d) == 136, "");
#endif
// MAPPING|FIVE|arm-baseline-linux-gnueabi:Gcc|arm-baseline-linux-gnueabihf:Gcc|arm-arm710t-linux-gnueabi:Gcc|arm-arm1020e-linux-gnueabi:Gcc|arm-cortex_r4-linux-gnueabi:Gcc|arm-cortex_r4-linux-gnueabihf:Gcc|END
// repr targets ArmUnknownLinuxGnueabi|Some("arm-baseline-linux-gnueabi") ArmUnknownLinuxGnueabihf|Some("arm-baseline-linux-gnueabihf") Armv4tUnknownLinuxGnueabi|Some("arm-arm710t-linux-gnueabi") Armv5teUnknownLinuxGnueabi|Some("arm-arm1020e-linux-gnueabi") Armv5teUnknownLinuxUclibcgnueabi|None Armv7UnknownLinuxGnueabi|Some("arm-cortex_r4-linux-gnueabi") Armv7UnknownLinuxGnueabihf|Some("arm-cortex_r4-linux-gnueabihf") 
#elif defined(FIVE)
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
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A,d) == 0, "");
#endif
_Static_assert(sizeof(A_) == 8, "");
_Static_assert(_Alignof(A_) == 4, "");
_Static_assert(sizeof(struct A__extra_alignment) == 12, "");
_Static_assert(_Alignof(struct A__extra_alignment) == 4, "");
_Static_assert(sizeof(struct A__extra_packed) == 8, "");
_Static_assert(_Alignof(struct A__extra_packed) == 1, "");
_Static_assert(sizeof(struct A__extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct A__extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A__extra_size) == 10, "");
_Static_assert(_Alignof(struct A__extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_,d) == 32, "");
#endif
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
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B,d) == 0, "");
#endif
_Static_assert(sizeof(B_) == 16, "");
_Static_assert(_Alignof(B_) == 8, "");
_Static_assert(sizeof(struct B__extra_alignment) == 24, "");
_Static_assert(_Alignof(struct B__extra_alignment) == 8, "");
_Static_assert(sizeof(struct B__extra_packed) == 16, "");
_Static_assert(_Alignof(struct B__extra_packed) == 1, "");
_Static_assert(sizeof(struct B__extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct B__extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B__extra_size) == 18, "");
_Static_assert(_Alignof(struct B__extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B_,d) == 64, "");
#endif
_Static_assert(sizeof(C) == 8, "");
_Static_assert(_Alignof(C) == 8, "");
_Static_assert(sizeof(struct C_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct C_extra_alignment) == 8, "");
_Static_assert(sizeof(struct C_extra_packed) == 8, "");
_Static_assert(_Alignof(struct C_extra_packed) == 1, "");
_Static_assert(sizeof(struct C_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct C_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct C_extra_size) == 10, "");
_Static_assert(_Alignof(struct C_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(C,d) == 0, "");
#endif
_Static_assert(sizeof(C_) == 16, "");
_Static_assert(_Alignof(C_) == 8, "");
_Static_assert(sizeof(struct C__extra_alignment) == 24, "");
_Static_assert(_Alignof(struct C__extra_alignment) == 8, "");
_Static_assert(sizeof(struct C__extra_packed) == 16, "");
_Static_assert(_Alignof(struct C__extra_packed) == 1, "");
_Static_assert(sizeof(struct C__extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct C__extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct C__extra_size) == 18, "");
_Static_assert(_Alignof(struct C__extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(C_,d) == 64, "");
#endif
_Static_assert(sizeof(D) == 24, "");
_Static_assert(_Alignof(D) == 8, "");
_Static_assert(sizeof(struct D_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct D_extra_alignment) == 8, "");
_Static_assert(sizeof(struct D_extra_packed) == 24, "");
_Static_assert(_Alignof(struct D_extra_packed) == 1, "");
_Static_assert(sizeof(struct D_extra_required_alignment) == 25, "");
_Static_assert(_Alignof(struct D_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct D_extra_size) == 26, "");
_Static_assert(_Alignof(struct D_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(D,d) == 64, "");
_Static_assert(__builtin_bitoffsetof(D,e) == 128, "");
#endif
_Static_assert(sizeof(F) == 32, "");
_Static_assert(_Alignof(F) == 16, "");
_Static_assert(sizeof(struct F_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct F_extra_alignment) == 16, "");
_Static_assert(sizeof(struct F_extra_packed) == 32, "");
_Static_assert(_Alignof(struct F_extra_packed) == 1, "");
_Static_assert(sizeof(struct F_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct F_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct F_extra_size) == 34, "");
_Static_assert(_Alignof(struct F_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(F,d) == 128, "");
_Static_assert(__builtin_bitoffsetof(F,e) == 192, "");
#endif
_Static_assert(sizeof(G) == 12, "");
_Static_assert(_Alignof(G) == 2, "");
_Static_assert(sizeof(struct G_extra_alignment) == 14, "");
_Static_assert(_Alignof(struct G_extra_alignment) == 2, "");
_Static_assert(sizeof(struct G_extra_packed) == 12, "");
_Static_assert(_Alignof(struct G_extra_packed) == 1, "");
_Static_assert(sizeof(struct G_extra_required_alignment) == 13, "");
_Static_assert(_Alignof(struct G_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct G_extra_size) == 14, "");
_Static_assert(_Alignof(struct G_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(G,d) == 16, "");
_Static_assert(__builtin_bitoffsetof(G,e) == 80, "");
#endif
_Static_assert(sizeof(H) == 12, "");
_Static_assert(_Alignof(H) == 2, "");
_Static_assert(sizeof(struct H_extra_alignment) == 14, "");
_Static_assert(_Alignof(struct H_extra_alignment) == 2, "");
_Static_assert(sizeof(struct H_extra_packed) == 12, "");
_Static_assert(_Alignof(struct H_extra_packed) == 1, "");
_Static_assert(sizeof(struct H_extra_required_alignment) == 13, "");
_Static_assert(_Alignof(struct H_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct H_extra_size) == 14, "");
_Static_assert(_Alignof(struct H_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(H,d) == 16, "");
_Static_assert(__builtin_bitoffsetof(H,e) == 80, "");
#endif
_Static_assert(sizeof(I) == 10, "");
_Static_assert(_Alignof(I) == 1, "");
_Static_assert(sizeof(struct I_extra_alignment) == 11, "");
_Static_assert(_Alignof(struct I_extra_alignment) == 1, "");
_Static_assert(sizeof(struct I_extra_packed) == 10, "");
_Static_assert(_Alignof(struct I_extra_packed) == 1, "");
_Static_assert(sizeof(struct I_extra_required_alignment) == 11, "");
_Static_assert(_Alignof(struct I_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct I_extra_size) == 12, "");
_Static_assert(_Alignof(struct I_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(I,d) == 8, "");
_Static_assert(__builtin_bitoffsetof(I,e) == 72, "");
#endif
_Static_assert(sizeof(J) == 12, "");
_Static_assert(_Alignof(J) == 2, "");
_Static_assert(sizeof(struct J_extra_alignment) == 14, "");
_Static_assert(_Alignof(struct J_extra_alignment) == 2, "");
_Static_assert(sizeof(struct J_extra_packed) == 12, "");
_Static_assert(_Alignof(struct J_extra_packed) == 1, "");
_Static_assert(sizeof(struct J_extra_required_alignment) == 13, "");
_Static_assert(_Alignof(struct J_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct J_extra_size) == 14, "");
_Static_assert(_Alignof(struct J_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(J,d) == 16, "");
_Static_assert(__builtin_bitoffsetof(J,e) == 80, "");
#endif
_Static_assert(sizeof(K) == 8, "");
_Static_assert(_Alignof(K) == 8, "");
_Static_assert(sizeof(struct K_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct K_extra_alignment) == 8, "");
_Static_assert(sizeof(struct K_extra_packed) == 8, "");
_Static_assert(_Alignof(struct K_extra_packed) == 1, "");
_Static_assert(sizeof(struct K_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct K_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct K_extra_size) == 10, "");
_Static_assert(_Alignof(struct K_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(K,d) == 8, "");
_Static_assert(__builtin_bitoffsetof(K,e) == 16, "");
#endif
_Static_assert(sizeof(L) == 32, "");
_Static_assert(_Alignof(L) == 16, "");
_Static_assert(sizeof(struct L_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct L_extra_alignment) == 16, "");
_Static_assert(sizeof(struct L_extra_packed) == 32, "");
_Static_assert(_Alignof(struct L_extra_packed) == 1, "");
_Static_assert(sizeof(struct L_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct L_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct L_extra_size) == 34, "");
_Static_assert(_Alignof(struct L_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(L,d) == 128, "");
_Static_assert(__builtin_bitoffsetof(L,e) == 136, "");
#endif
_Static_assert(sizeof(M) == 4, "");
_Static_assert(_Alignof(M) == 2, "");
_Static_assert(sizeof(struct M_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct M_extra_alignment) == 2, "");
_Static_assert(sizeof(struct M_extra_packed) == 4, "");
_Static_assert(_Alignof(struct M_extra_packed) == 1, "");
_Static_assert(sizeof(struct M_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct M_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct M_extra_size) == 6, "");
_Static_assert(_Alignof(struct M_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(M,d) == 16, "");
_Static_assert(__builtin_bitoffsetof(M,e) == 24, "");
#endif
_Static_assert(sizeof(N) == 4, "");
_Static_assert(_Alignof(N) == 2, "");
_Static_assert(sizeof(struct N_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct N_extra_alignment) == 2, "");
_Static_assert(sizeof(struct N_extra_packed) == 4, "");
_Static_assert(_Alignof(struct N_extra_packed) == 1, "");
_Static_assert(sizeof(struct N_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct N_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct N_extra_size) == 6, "");
_Static_assert(_Alignof(struct N_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(N,d) == 16, "");
_Static_assert(__builtin_bitoffsetof(N,e) == 24, "");
#endif
_Static_assert(sizeof(O) == 3, "");
_Static_assert(_Alignof(O) == 1, "");
_Static_assert(sizeof(struct O_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct O_extra_alignment) == 1, "");
_Static_assert(sizeof(struct O_extra_packed) == 3, "");
_Static_assert(_Alignof(struct O_extra_packed) == 1, "");
_Static_assert(sizeof(struct O_extra_required_alignment) == 4, "");
_Static_assert(_Alignof(struct O_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct O_extra_size) == 5, "");
_Static_assert(_Alignof(struct O_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(O,d) == 8, "");
_Static_assert(__builtin_bitoffsetof(O,e) == 16, "");
#endif
_Static_assert(sizeof(P) == 4, "");
_Static_assert(_Alignof(P) == 2, "");
_Static_assert(sizeof(struct P_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct P_extra_alignment) == 2, "");
_Static_assert(sizeof(struct P_extra_packed) == 4, "");
_Static_assert(_Alignof(struct P_extra_packed) == 1, "");
_Static_assert(sizeof(struct P_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct P_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct P_extra_size) == 6, "");
_Static_assert(_Alignof(struct P_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(P,d) == 8, "");
_Static_assert(__builtin_bitoffsetof(P,e) == 16, "");
#endif
_Static_assert(sizeof(Q) == 8, "");
_Static_assert(_Alignof(Q) == 8, "");
_Static_assert(sizeof(struct Q_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct Q_extra_alignment) == 8, "");
_Static_assert(sizeof(struct Q_extra_packed) == 8, "");
_Static_assert(_Alignof(struct Q_extra_packed) == 1, "");
_Static_assert(sizeof(struct Q_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct Q_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct Q_extra_size) == 10, "");
_Static_assert(_Alignof(struct Q_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(Q,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(Q,d) == 9, "");
_Static_assert(__builtin_bitoffsetof(Q,e) == 16, "");
#endif
_Static_assert(sizeof(R) == 32, "");
_Static_assert(_Alignof(R) == 16, "");
_Static_assert(sizeof(struct R_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct R_extra_alignment) == 16, "");
_Static_assert(sizeof(struct R_extra_packed) == 32, "");
_Static_assert(_Alignof(struct R_extra_packed) == 1, "");
_Static_assert(sizeof(struct R_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct R_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct R_extra_size) == 34, "");
_Static_assert(_Alignof(struct R_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(R,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(R,e) == 128, "");
#endif
_Static_assert(sizeof(S) == 16, "");
_Static_assert(_Alignof(S) == 8, "");
_Static_assert(sizeof(struct S_extra_alignment) == 24, "");
_Static_assert(_Alignof(struct S_extra_alignment) == 8, "");
_Static_assert(sizeof(struct S_extra_packed) == 16, "");
_Static_assert(_Alignof(struct S_extra_packed) == 1, "");
_Static_assert(sizeof(struct S_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct S_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct S_extra_size) == 18, "");
_Static_assert(_Alignof(struct S_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(S,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(S,e) == 64, "");
#endif
_Static_assert(sizeof(T) == 16, "");
_Static_assert(_Alignof(T) == 8, "");
_Static_assert(sizeof(struct T_extra_alignment) == 24, "");
_Static_assert(_Alignof(struct T_extra_alignment) == 8, "");
_Static_assert(sizeof(struct T_extra_packed) == 16, "");
_Static_assert(_Alignof(struct T_extra_packed) == 1, "");
_Static_assert(sizeof(struct T_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct T_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct T_extra_size) == 18, "");
_Static_assert(_Alignof(struct T_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(T,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(T,e) == 64, "");
#endif
_Static_assert(sizeof(U) == 16, "");
_Static_assert(_Alignof(U) == 8, "");
_Static_assert(sizeof(struct U_extra_alignment) == 24, "");
_Static_assert(_Alignof(struct U_extra_alignment) == 8, "");
_Static_assert(sizeof(struct U_extra_packed) == 16, "");
_Static_assert(_Alignof(struct U_extra_packed) == 1, "");
_Static_assert(sizeof(struct U_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct U_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct U_extra_size) == 18, "");
_Static_assert(_Alignof(struct U_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(U,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(U,e) == 64, "");
#endif
_Static_assert(sizeof(V) == 16, "");
_Static_assert(_Alignof(V) == 8, "");
_Static_assert(sizeof(struct V_extra_alignment) == 24, "");
_Static_assert(_Alignof(struct V_extra_alignment) == 8, "");
_Static_assert(sizeof(struct V_extra_packed) == 16, "");
_Static_assert(_Alignof(struct V_extra_packed) == 1, "");
_Static_assert(sizeof(struct V_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct V_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct V_extra_size) == 18, "");
_Static_assert(_Alignof(struct V_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(V,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(V,e) == 64, "");
#endif
_Static_assert(sizeof(W) == 32, "");
_Static_assert(_Alignof(W) == 16, "");
_Static_assert(sizeof(struct W_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct W_extra_alignment) == 16, "");
_Static_assert(sizeof(struct W_extra_packed) == 32, "");
_Static_assert(_Alignof(struct W_extra_packed) == 1, "");
_Static_assert(sizeof(struct W_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct W_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct W_extra_size) == 34, "");
_Static_assert(_Alignof(struct W_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(W,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(W,e) == 128, "");
#endif
_Static_assert(sizeof(W_) == 32, "");
_Static_assert(_Alignof(W_) == 16, "");
_Static_assert(sizeof(struct W__extra_alignment) == 48, "");
_Static_assert(_Alignof(struct W__extra_alignment) == 16, "");
_Static_assert(sizeof(struct W__extra_packed) == 32, "");
_Static_assert(_Alignof(struct W__extra_packed) == 1, "");
_Static_assert(sizeof(struct W__extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct W__extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct W__extra_size) == 34, "");
_Static_assert(_Alignof(struct W__extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(W_,e) == 128, "");
#endif
_Static_assert(sizeof(X) == 32, "");
_Static_assert(_Alignof(X) == 16, "");
_Static_assert(sizeof(struct X_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct X_extra_alignment) == 16, "");
_Static_assert(sizeof(struct X_extra_packed) == 32, "");
_Static_assert(_Alignof(struct X_extra_packed) == 1, "");
_Static_assert(sizeof(struct X_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct X_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct X_extra_size) == 34, "");
_Static_assert(_Alignof(struct X_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(X,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(X,e) == 128, "");
#endif
_Static_assert(sizeof(A2) == 4, "");
_Static_assert(_Alignof(A2) == 4, "");
_Static_assert(sizeof(struct A2_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct A2_extra_alignment) == 4, "");
_Static_assert(sizeof(struct A2_extra_packed) == 4, "");
_Static_assert(_Alignof(struct A2_extra_packed) == 1, "");
_Static_assert(sizeof(struct A2_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct A2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A2_extra_size) == 6, "");
_Static_assert(_Alignof(struct A2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A2,d) == 0, "");
#endif
_Static_assert(sizeof(A_2) == 4, "");
_Static_assert(_Alignof(A_2) == 4, "");
_Static_assert(sizeof(struct A_2_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct A_2_extra_alignment) == 4, "");
_Static_assert(sizeof(struct A_2_extra_packed) == 4, "");
_Static_assert(_Alignof(struct A_2_extra_packed) == 1, "");
_Static_assert(sizeof(struct A_2_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct A_2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A_2_extra_size) == 6, "");
_Static_assert(_Alignof(struct A_2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_2,d) == 0, "");
#endif
_Static_assert(sizeof(B2) == 8, "");
_Static_assert(_Alignof(B2) == 8, "");
_Static_assert(sizeof(struct B2_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct B2_extra_alignment) == 8, "");
_Static_assert(sizeof(struct B2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct B2_extra_packed) == 1, "");
_Static_assert(sizeof(struct B2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct B2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B2_extra_size) == 10, "");
_Static_assert(_Alignof(struct B2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B2,d) == 0, "");
#endif
_Static_assert(sizeof(B_2) == 8, "");
_Static_assert(_Alignof(B_2) == 8, "");
_Static_assert(sizeof(struct B_2_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct B_2_extra_alignment) == 8, "");
_Static_assert(sizeof(struct B_2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct B_2_extra_packed) == 1, "");
_Static_assert(sizeof(struct B_2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct B_2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B_2_extra_size) == 10, "");
_Static_assert(_Alignof(struct B_2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B_2,d) == 0, "");
#endif
_Static_assert(sizeof(C2) == 8, "");
_Static_assert(_Alignof(C2) == 8, "");
_Static_assert(sizeof(struct C2_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct C2_extra_alignment) == 8, "");
_Static_assert(sizeof(struct C2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct C2_extra_packed) == 1, "");
_Static_assert(sizeof(struct C2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct C2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct C2_extra_size) == 10, "");
_Static_assert(_Alignof(struct C2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(C2,d) == 0, "");
#endif
_Static_assert(sizeof(C22) == 8, "");
_Static_assert(_Alignof(C22) == 8, "");
_Static_assert(sizeof(struct C22_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct C22_extra_alignment) == 8, "");
_Static_assert(sizeof(struct C22_extra_packed) == 8, "");
_Static_assert(_Alignof(struct C22_extra_packed) == 1, "");
_Static_assert(sizeof(struct C22_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct C22_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct C22_extra_size) == 10, "");
_Static_assert(_Alignof(struct C22_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(C22,d) == 0, "");
#endif
_Static_assert(sizeof(D2) == 8, "");
_Static_assert(_Alignof(D2) == 8, "");
_Static_assert(sizeof(struct D2_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct D2_extra_alignment) == 8, "");
_Static_assert(sizeof(struct D2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct D2_extra_packed) == 1, "");
_Static_assert(sizeof(struct D2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct D2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct D2_extra_size) == 10, "");
_Static_assert(_Alignof(struct D2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(D2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(D2,e) == 0, "");
#endif
_Static_assert(sizeof(F2) == 16, "");
_Static_assert(_Alignof(F2) == 16, "");
_Static_assert(sizeof(struct F2_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct F2_extra_alignment) == 16, "");
_Static_assert(sizeof(struct F2_extra_packed) == 16, "");
_Static_assert(_Alignof(struct F2_extra_packed) == 1, "");
_Static_assert(sizeof(struct F2_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct F2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct F2_extra_size) == 18, "");
_Static_assert(_Alignof(struct F2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(F2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(F2,e) == 0, "");
#endif
_Static_assert(sizeof(G2) == 8, "");
_Static_assert(_Alignof(G2) == 2, "");
_Static_assert(sizeof(struct G2_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct G2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct G2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct G2_extra_packed) == 1, "");
_Static_assert(sizeof(struct G2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct G2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct G2_extra_size) == 10, "");
_Static_assert(_Alignof(struct G2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(G2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(G2,e) == 0, "");
#endif
_Static_assert(sizeof(H2) == 8, "");
_Static_assert(_Alignof(H2) == 2, "");
_Static_assert(sizeof(struct H2_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct H2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct H2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct H2_extra_packed) == 1, "");
_Static_assert(sizeof(struct H2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct H2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct H2_extra_size) == 10, "");
_Static_assert(_Alignof(struct H2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(H2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(H2,e) == 0, "");
#endif
_Static_assert(sizeof(I2) == 8, "");
_Static_assert(_Alignof(I2) == 1, "");
_Static_assert(sizeof(struct I2_extra_alignment) == 9, "");
_Static_assert(_Alignof(struct I2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct I2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct I2_extra_packed) == 1, "");
_Static_assert(sizeof(struct I2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct I2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct I2_extra_size) == 10, "");
_Static_assert(_Alignof(struct I2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(I2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(I2,e) == 0, "");
#endif
_Static_assert(sizeof(J2) == 8, "");
_Static_assert(_Alignof(J2) == 2, "");
_Static_assert(sizeof(struct J2_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct J2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct J2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct J2_extra_packed) == 1, "");
_Static_assert(sizeof(struct J2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct J2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct J2_extra_size) == 10, "");
_Static_assert(_Alignof(struct J2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(J2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(J2,e) == 0, "");
#endif
_Static_assert(sizeof(K2) == 8, "");
_Static_assert(_Alignof(K2) == 8, "");
_Static_assert(sizeof(struct K2_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct K2_extra_alignment) == 8, "");
_Static_assert(sizeof(struct K2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct K2_extra_packed) == 1, "");
_Static_assert(sizeof(struct K2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct K2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct K2_extra_size) == 10, "");
_Static_assert(_Alignof(struct K2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(K2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(K2,e) == 0, "");
#endif
_Static_assert(sizeof(L2) == 16, "");
_Static_assert(_Alignof(L2) == 16, "");
_Static_assert(sizeof(struct L2_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct L2_extra_alignment) == 16, "");
_Static_assert(sizeof(struct L2_extra_packed) == 16, "");
_Static_assert(_Alignof(struct L2_extra_packed) == 1, "");
_Static_assert(sizeof(struct L2_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct L2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct L2_extra_size) == 18, "");
_Static_assert(_Alignof(struct L2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(L2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(L2,e) == 0, "");
#endif
_Static_assert(sizeof(M2) == 2, "");
_Static_assert(_Alignof(M2) == 2, "");
_Static_assert(sizeof(struct M2_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct M2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct M2_extra_packed) == 2, "");
_Static_assert(_Alignof(struct M2_extra_packed) == 1, "");
_Static_assert(sizeof(struct M2_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct M2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct M2_extra_size) == 4, "");
_Static_assert(_Alignof(struct M2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(M2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(M2,e) == 0, "");
#endif
_Static_assert(sizeof(N2) == 2, "");
_Static_assert(_Alignof(N2) == 2, "");
_Static_assert(sizeof(struct N2_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct N2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct N2_extra_packed) == 2, "");
_Static_assert(_Alignof(struct N2_extra_packed) == 1, "");
_Static_assert(sizeof(struct N2_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct N2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct N2_extra_size) == 4, "");
_Static_assert(_Alignof(struct N2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(N2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(N2,e) == 0, "");
#endif
_Static_assert(sizeof(O2) == 1, "");
_Static_assert(_Alignof(O2) == 1, "");
_Static_assert(sizeof(struct O2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct O2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct O2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct O2_extra_packed) == 1, "");
_Static_assert(sizeof(struct O2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct O2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct O2_extra_size) == 3, "");
_Static_assert(_Alignof(struct O2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(O2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(O2,e) == 0, "");
#endif
_Static_assert(sizeof(P2) == 2, "");
_Static_assert(_Alignof(P2) == 2, "");
_Static_assert(sizeof(struct P2_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct P2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct P2_extra_packed) == 2, "");
_Static_assert(_Alignof(struct P2_extra_packed) == 1, "");
_Static_assert(sizeof(struct P2_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct P2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct P2_extra_size) == 4, "");
_Static_assert(_Alignof(struct P2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(P2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(P2,e) == 0, "");
#endif
_Static_assert(sizeof(Q2) == 8, "");
_Static_assert(_Alignof(Q2) == 8, "");
_Static_assert(sizeof(struct Q2_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct Q2_extra_alignment) == 8, "");
_Static_assert(sizeof(struct Q2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct Q2_extra_packed) == 1, "");
_Static_assert(sizeof(struct Q2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct Q2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct Q2_extra_size) == 10, "");
_Static_assert(_Alignof(struct Q2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(Q2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(Q2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(Q2,e) == 0, "");
#endif
_Static_assert(sizeof(R2) == 16, "");
_Static_assert(_Alignof(R2) == 16, "");
_Static_assert(sizeof(struct R2_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct R2_extra_alignment) == 16, "");
_Static_assert(sizeof(struct R2_extra_packed) == 16, "");
_Static_assert(_Alignof(struct R2_extra_packed) == 1, "");
_Static_assert(sizeof(struct R2_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct R2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct R2_extra_size) == 18, "");
_Static_assert(_Alignof(struct R2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(R2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(R2,e) == 0, "");
#endif
_Static_assert(sizeof(S2) == 8, "");
_Static_assert(_Alignof(S2) == 8, "");
_Static_assert(sizeof(struct S2_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct S2_extra_alignment) == 8, "");
_Static_assert(sizeof(struct S2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct S2_extra_packed) == 1, "");
_Static_assert(sizeof(struct S2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct S2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct S2_extra_size) == 10, "");
_Static_assert(_Alignof(struct S2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(S2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(S2,e) == 0, "");
#endif
_Static_assert(sizeof(T2) == 8, "");
_Static_assert(_Alignof(T2) == 8, "");
_Static_assert(sizeof(struct T2_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct T2_extra_alignment) == 8, "");
_Static_assert(sizeof(struct T2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct T2_extra_packed) == 1, "");
_Static_assert(sizeof(struct T2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct T2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct T2_extra_size) == 10, "");
_Static_assert(_Alignof(struct T2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(T2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(T2,e) == 0, "");
#endif
_Static_assert(sizeof(U2) == 8, "");
_Static_assert(_Alignof(U2) == 8, "");
_Static_assert(sizeof(struct U2_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct U2_extra_alignment) == 8, "");
_Static_assert(sizeof(struct U2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct U2_extra_packed) == 1, "");
_Static_assert(sizeof(struct U2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct U2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct U2_extra_size) == 10, "");
_Static_assert(_Alignof(struct U2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(U2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(U2,e) == 0, "");
#endif
_Static_assert(sizeof(V2) == 8, "");
_Static_assert(_Alignof(V2) == 8, "");
_Static_assert(sizeof(struct V2_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct V2_extra_alignment) == 8, "");
_Static_assert(sizeof(struct V2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct V2_extra_packed) == 1, "");
_Static_assert(sizeof(struct V2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct V2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct V2_extra_size) == 10, "");
_Static_assert(_Alignof(struct V2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(V2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(V2,e) == 0, "");
#endif
_Static_assert(sizeof(W2) == 16, "");
_Static_assert(_Alignof(W2) == 16, "");
_Static_assert(sizeof(struct W2_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct W2_extra_alignment) == 16, "");
_Static_assert(sizeof(struct W2_extra_packed) == 16, "");
_Static_assert(_Alignof(struct W2_extra_packed) == 1, "");
_Static_assert(sizeof(struct W2_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct W2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct W2_extra_size) == 18, "");
_Static_assert(_Alignof(struct W2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(W2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(W2,e) == 0, "");
#endif
_Static_assert(sizeof(W_2) == 16, "");
_Static_assert(_Alignof(W_2) == 16, "");
_Static_assert(sizeof(struct W_2_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct W_2_extra_alignment) == 16, "");
_Static_assert(sizeof(struct W_2_extra_packed) == 16, "");
_Static_assert(_Alignof(struct W_2_extra_packed) == 1, "");
_Static_assert(sizeof(struct W_2_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct W_2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct W_2_extra_size) == 18, "");
_Static_assert(_Alignof(struct W_2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(W_2,e) == 0, "");
#endif
_Static_assert(sizeof(X2) == 16, "");
_Static_assert(_Alignof(X2) == 16, "");
_Static_assert(sizeof(struct X2_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct X2_extra_alignment) == 16, "");
_Static_assert(sizeof(struct X2_extra_packed) == 16, "");
_Static_assert(_Alignof(struct X2_extra_packed) == 1, "");
_Static_assert(sizeof(struct X2_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct X2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct X2_extra_size) == 18, "");
_Static_assert(_Alignof(struct X2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(X2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(X2,e) == 0, "");
#endif
_Static_assert(sizeof(Y) == 16, "");
_Static_assert(_Alignof(Y) == 8, "");
_Static_assert(sizeof(struct Y_extra_alignment) == 24, "");
_Static_assert(_Alignof(struct Y_extra_alignment) == 8, "");
_Static_assert(sizeof(struct Y_extra_packed) == 16, "");
_Static_assert(_Alignof(struct Y_extra_packed) == 1, "");
_Static_assert(sizeof(struct Y_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct Y_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct Y_extra_size) == 18, "");
_Static_assert(_Alignof(struct Y_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(Y,d) == 64, "");
#endif
_Static_assert(sizeof(Y2) == 8, "");
_Static_assert(_Alignof(Y2) == 8, "");
_Static_assert(sizeof(struct Y2_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct Y2_extra_alignment) == 8, "");
_Static_assert(sizeof(struct Y2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct Y2_extra_packed) == 1, "");
_Static_assert(sizeof(struct Y2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct Y2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct Y2_extra_size) == 10, "");
_Static_assert(_Alignof(struct Y2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(Y2,d) == 0, "");
#endif
_Static_assert(sizeof(A3) == 64, "");
_Static_assert(_Alignof(A3) == 32, "");
_Static_assert(sizeof(struct A3_extra_alignment) == 96, "");
_Static_assert(_Alignof(struct A3_extra_alignment) == 32, "");
_Static_assert(sizeof(struct A3_extra_packed) == 64, "");
_Static_assert(_Alignof(struct A3_extra_packed) == 1, "");
_Static_assert(sizeof(struct A3_extra_required_alignment) == 65, "");
_Static_assert(_Alignof(struct A3_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A3_extra_size) == 66, "");
_Static_assert(_Alignof(struct A3_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A3,d) == 256, "");
#endif
_Static_assert(sizeof(A4) == 1, "");
_Static_assert(_Alignof(A4) == 32, "");
_Static_assert(sizeof(struct A4_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct A4_extra_alignment) == 32, "");
_Static_assert(sizeof(struct A4_extra_packed) == 1, "");
_Static_assert(_Alignof(struct A4_extra_packed) == 1, "");
_Static_assert(sizeof(struct A4_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct A4_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A4_extra_size) == 3, "");
_Static_assert(_Alignof(struct A4_extra_size) == 1, "");
_Static_assert(sizeof(A5) == 64, "");
_Static_assert(_Alignof(A5) == 32, "");
_Static_assert(sizeof(struct A5_extra_alignment) == 96, "");
_Static_assert(_Alignof(struct A5_extra_alignment) == 32, "");
_Static_assert(sizeof(struct A5_extra_packed) == 64, "");
_Static_assert(_Alignof(struct A5_extra_packed) == 1, "");
_Static_assert(sizeof(struct A5_extra_required_alignment) == 65, "");
_Static_assert(_Alignof(struct A5_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A5_extra_size) == 66, "");
_Static_assert(_Alignof(struct A5_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A5,d) == 256, "");
#endif
_Static_assert(sizeof(A7) == 32, "");
_Static_assert(_Alignof(A7) == 32, "");
_Static_assert(sizeof(struct A7_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct A7_extra_alignment) == 32, "");
_Static_assert(sizeof(struct A7_extra_packed) == 32, "");
_Static_assert(_Alignof(struct A7_extra_packed) == 1, "");
_Static_assert(sizeof(struct A7_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct A7_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A7_extra_size) == 34, "");
_Static_assert(_Alignof(struct A7_extra_size) == 1, "");
_Static_assert(sizeof(A8) == 8, "");
_Static_assert(_Alignof(A8) == 4, "");
_Static_assert(sizeof(struct A8_extra_alignment) == 12, "");
_Static_assert(_Alignof(struct A8_extra_alignment) == 4, "");
_Static_assert(sizeof(struct A8_extra_packed) == 8, "");
_Static_assert(_Alignof(struct A8_extra_packed) == 1, "");
_Static_assert(sizeof(struct A8_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct A8_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A8_extra_size) == 10, "");
_Static_assert(_Alignof(struct A8_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A8,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A8,j) == 39, "");
#endif
_Static_assert(sizeof(A9) == 12, "");
_Static_assert(_Alignof(A9) == 4, "");
_Static_assert(sizeof(struct A9_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct A9_extra_alignment) == 4, "");
_Static_assert(sizeof(struct A9_extra_packed) == 12, "");
_Static_assert(_Alignof(struct A9_extra_packed) == 1, "");
_Static_assert(sizeof(struct A9_extra_required_alignment) == 13, "");
_Static_assert(_Alignof(struct A9_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A9_extra_size) == 14, "");
_Static_assert(_Alignof(struct A9_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A9,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A9,j) == 64, "");
#endif
_Static_assert(sizeof(A10) == 4, "");
_Static_assert(_Alignof(A10) == 16, "");
_Static_assert(sizeof(struct A10_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct A10_extra_alignment) == 16, "");
_Static_assert(sizeof(struct A10_extra_packed) == 4, "");
_Static_assert(_Alignof(struct A10_extra_packed) == 1, "");
_Static_assert(sizeof(struct A10_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct A10_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A10_extra_size) == 6, "");
_Static_assert(_Alignof(struct A10_extra_size) == 1, "");
_Static_assert(sizeof(A11) == 32, "");
_Static_assert(_Alignof(A11) == 16, "");
_Static_assert(sizeof(struct A11_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct A11_extra_alignment) == 16, "");
_Static_assert(sizeof(struct A11_extra_packed) == 32, "");
_Static_assert(_Alignof(struct A11_extra_packed) == 1, "");
_Static_assert(sizeof(struct A11_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct A11_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A11_extra_size) == 34, "");
_Static_assert(_Alignof(struct A11_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A11,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A11,j) == 128, "");
#endif
_Static_assert(sizeof(A12) == 32, "");
_Static_assert(_Alignof(A12) == 16, "");
_Static_assert(sizeof(struct A12_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct A12_extra_alignment) == 16, "");
_Static_assert(sizeof(struct A12_extra_packed) == 32, "");
_Static_assert(_Alignof(struct A12_extra_packed) == 1, "");
_Static_assert(sizeof(struct A12_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct A12_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A12_extra_size) == 34, "");
_Static_assert(_Alignof(struct A12_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A12,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A12,j) == 128, "");
#endif
_Static_assert(sizeof(A13) == 32, "");
_Static_assert(_Alignof(A13) == 16, "");
_Static_assert(sizeof(struct A13_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct A13_extra_alignment) == 16, "");
_Static_assert(sizeof(struct A13_extra_packed) == 32, "");
_Static_assert(_Alignof(struct A13_extra_packed) == 1, "");
_Static_assert(sizeof(struct A13_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct A13_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A13_extra_size) == 34, "");
_Static_assert(_Alignof(struct A13_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A13,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A13,j) == 128, "");
_Static_assert(__builtin_bitoffsetof(A13,d) == 136, "");
#endif
// MAPPING|SIX|arm-cortex_r4-ios-none:Clang|arm-baseline-ios-none:Clang|END
// repr targets Armv7AppleIos|Some("arm-cortex_r4-ios-none") Armv7sAppleIos|Some("arm-baseline-ios-none") 
#elif defined(SIX)
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
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A,d) == 0, "");
#endif
_Static_assert(sizeof(A_) == 8, "");
_Static_assert(_Alignof(A_) == 4, "");
_Static_assert(sizeof(struct A__extra_alignment) == 12, "");
_Static_assert(_Alignof(struct A__extra_alignment) == 4, "");
_Static_assert(sizeof(struct A__extra_packed) == 8, "");
_Static_assert(_Alignof(struct A__extra_packed) == 1, "");
_Static_assert(sizeof(struct A__extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct A__extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A__extra_size) == 10, "");
_Static_assert(_Alignof(struct A__extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_,d) == 32, "");
#endif
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
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B,d) == 0, "");
#endif
_Static_assert(sizeof(B_) == 8, "");
_Static_assert(_Alignof(B_) == 4, "");
_Static_assert(sizeof(struct B__extra_alignment) == 12, "");
_Static_assert(_Alignof(struct B__extra_alignment) == 4, "");
_Static_assert(sizeof(struct B__extra_packed) == 8, "");
_Static_assert(_Alignof(struct B__extra_packed) == 1, "");
_Static_assert(sizeof(struct B__extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct B__extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B__extra_size) == 10, "");
_Static_assert(_Alignof(struct B__extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B_,d) == 32, "");
#endif
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
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(C,d) == 0, "");
#endif
_Static_assert(sizeof(C_) == 8, "");
_Static_assert(_Alignof(C_) == 4, "");
_Static_assert(sizeof(struct C__extra_alignment) == 12, "");
_Static_assert(_Alignof(struct C__extra_alignment) == 4, "");
_Static_assert(sizeof(struct C__extra_packed) == 8, "");
_Static_assert(_Alignof(struct C__extra_packed) == 1, "");
_Static_assert(sizeof(struct C__extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct C__extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct C__extra_size) == 10, "");
_Static_assert(_Alignof(struct C__extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(C_,d) == 32, "");
#endif
_Static_assert(sizeof(D) == 16, "");
_Static_assert(_Alignof(D) == 4, "");
_Static_assert(sizeof(struct D_extra_alignment) == 20, "");
_Static_assert(_Alignof(struct D_extra_alignment) == 4, "");
_Static_assert(sizeof(struct D_extra_packed) == 16, "");
_Static_assert(_Alignof(struct D_extra_packed) == 1, "");
_Static_assert(sizeof(struct D_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct D_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct D_extra_size) == 18, "");
_Static_assert(_Alignof(struct D_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(D,d) == 32, "");
_Static_assert(__builtin_bitoffsetof(D,e) == 96, "");
#endif
_Static_assert(sizeof(F) == 32, "");
_Static_assert(_Alignof(F) == 16, "");
_Static_assert(sizeof(struct F_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct F_extra_alignment) == 16, "");
_Static_assert(sizeof(struct F_extra_packed) == 32, "");
_Static_assert(_Alignof(struct F_extra_packed) == 1, "");
_Static_assert(sizeof(struct F_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct F_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct F_extra_size) == 34, "");
_Static_assert(_Alignof(struct F_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(F,d) == 128, "");
_Static_assert(__builtin_bitoffsetof(F,e) == 192, "");
#endif
_Static_assert(sizeof(G) == 12, "");
_Static_assert(_Alignof(G) == 2, "");
_Static_assert(sizeof(struct G_extra_alignment) == 14, "");
_Static_assert(_Alignof(struct G_extra_alignment) == 2, "");
_Static_assert(sizeof(struct G_extra_packed) == 12, "");
_Static_assert(_Alignof(struct G_extra_packed) == 1, "");
_Static_assert(sizeof(struct G_extra_required_alignment) == 13, "");
_Static_assert(_Alignof(struct G_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct G_extra_size) == 14, "");
_Static_assert(_Alignof(struct G_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(G,d) == 16, "");
_Static_assert(__builtin_bitoffsetof(G,e) == 80, "");
#endif
_Static_assert(sizeof(H) == 12, "");
_Static_assert(_Alignof(H) == 2, "");
_Static_assert(sizeof(struct H_extra_alignment) == 14, "");
_Static_assert(_Alignof(struct H_extra_alignment) == 2, "");
_Static_assert(sizeof(struct H_extra_packed) == 12, "");
_Static_assert(_Alignof(struct H_extra_packed) == 1, "");
_Static_assert(sizeof(struct H_extra_required_alignment) == 13, "");
_Static_assert(_Alignof(struct H_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct H_extra_size) == 14, "");
_Static_assert(_Alignof(struct H_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(H,d) == 16, "");
_Static_assert(__builtin_bitoffsetof(H,e) == 80, "");
#endif
_Static_assert(sizeof(I) == 10, "");
_Static_assert(_Alignof(I) == 1, "");
_Static_assert(sizeof(struct I_extra_alignment) == 11, "");
_Static_assert(_Alignof(struct I_extra_alignment) == 1, "");
_Static_assert(sizeof(struct I_extra_packed) == 10, "");
_Static_assert(_Alignof(struct I_extra_packed) == 1, "");
_Static_assert(sizeof(struct I_extra_required_alignment) == 11, "");
_Static_assert(_Alignof(struct I_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct I_extra_size) == 12, "");
_Static_assert(_Alignof(struct I_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(I,d) == 8, "");
_Static_assert(__builtin_bitoffsetof(I,e) == 72, "");
#endif
_Static_assert(sizeof(J) == 12, "");
_Static_assert(_Alignof(J) == 2, "");
_Static_assert(sizeof(struct J_extra_alignment) == 14, "");
_Static_assert(_Alignof(struct J_extra_alignment) == 2, "");
_Static_assert(sizeof(struct J_extra_packed) == 12, "");
_Static_assert(_Alignof(struct J_extra_packed) == 1, "");
_Static_assert(sizeof(struct J_extra_required_alignment) == 13, "");
_Static_assert(_Alignof(struct J_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct J_extra_size) == 14, "");
_Static_assert(_Alignof(struct J_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(J,d) == 16, "");
_Static_assert(__builtin_bitoffsetof(J,e) == 80, "");
#endif
_Static_assert(sizeof(K) == 3, "");
_Static_assert(_Alignof(K) == 1, "");
_Static_assert(sizeof(struct K_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct K_extra_alignment) == 1, "");
_Static_assert(sizeof(struct K_extra_packed) == 3, "");
_Static_assert(_Alignof(struct K_extra_packed) == 1, "");
_Static_assert(sizeof(struct K_extra_required_alignment) == 4, "");
_Static_assert(_Alignof(struct K_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct K_extra_size) == 5, "");
_Static_assert(_Alignof(struct K_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(K,d) == 8, "");
_Static_assert(__builtin_bitoffsetof(K,e) == 16, "");
#endif
_Static_assert(sizeof(L) == 32, "");
_Static_assert(_Alignof(L) == 16, "");
_Static_assert(sizeof(struct L_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct L_extra_alignment) == 16, "");
_Static_assert(sizeof(struct L_extra_packed) == 32, "");
_Static_assert(_Alignof(struct L_extra_packed) == 1, "");
_Static_assert(sizeof(struct L_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct L_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct L_extra_size) == 34, "");
_Static_assert(_Alignof(struct L_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(L,d) == 128, "");
_Static_assert(__builtin_bitoffsetof(L,e) == 136, "");
#endif
_Static_assert(sizeof(M) == 4, "");
_Static_assert(_Alignof(M) == 2, "");
_Static_assert(sizeof(struct M_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct M_extra_alignment) == 2, "");
_Static_assert(sizeof(struct M_extra_packed) == 4, "");
_Static_assert(_Alignof(struct M_extra_packed) == 1, "");
_Static_assert(sizeof(struct M_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct M_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct M_extra_size) == 6, "");
_Static_assert(_Alignof(struct M_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(M,d) == 16, "");
_Static_assert(__builtin_bitoffsetof(M,e) == 24, "");
#endif
_Static_assert(sizeof(N) == 4, "");
_Static_assert(_Alignof(N) == 2, "");
_Static_assert(sizeof(struct N_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct N_extra_alignment) == 2, "");
_Static_assert(sizeof(struct N_extra_packed) == 4, "");
_Static_assert(_Alignof(struct N_extra_packed) == 1, "");
_Static_assert(sizeof(struct N_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct N_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct N_extra_size) == 6, "");
_Static_assert(_Alignof(struct N_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(N,d) == 8, "");
_Static_assert(__builtin_bitoffsetof(N,e) == 16, "");
#endif
_Static_assert(sizeof(O) == 3, "");
_Static_assert(_Alignof(O) == 1, "");
_Static_assert(sizeof(struct O_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct O_extra_alignment) == 1, "");
_Static_assert(sizeof(struct O_extra_packed) == 3, "");
_Static_assert(_Alignof(struct O_extra_packed) == 1, "");
_Static_assert(sizeof(struct O_extra_required_alignment) == 4, "");
_Static_assert(_Alignof(struct O_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct O_extra_size) == 5, "");
_Static_assert(_Alignof(struct O_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(O,d) == 8, "");
_Static_assert(__builtin_bitoffsetof(O,e) == 16, "");
#endif
_Static_assert(sizeof(P) == 3, "");
_Static_assert(_Alignof(P) == 1, "");
_Static_assert(sizeof(struct P_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct P_extra_alignment) == 1, "");
_Static_assert(sizeof(struct P_extra_packed) == 3, "");
_Static_assert(_Alignof(struct P_extra_packed) == 1, "");
_Static_assert(sizeof(struct P_extra_required_alignment) == 4, "");
_Static_assert(_Alignof(struct P_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct P_extra_size) == 5, "");
_Static_assert(_Alignof(struct P_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(P,d) == 8, "");
_Static_assert(__builtin_bitoffsetof(P,e) == 16, "");
#endif
_Static_assert(sizeof(Q) == 3, "");
_Static_assert(_Alignof(Q) == 1, "");
_Static_assert(sizeof(struct Q_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct Q_extra_alignment) == 1, "");
_Static_assert(sizeof(struct Q_extra_packed) == 3, "");
_Static_assert(_Alignof(struct Q_extra_packed) == 1, "");
_Static_assert(sizeof(struct Q_extra_required_alignment) == 4, "");
_Static_assert(_Alignof(struct Q_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct Q_extra_size) == 5, "");
_Static_assert(_Alignof(struct Q_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(Q,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(Q,d) == 9, "");
_Static_assert(__builtin_bitoffsetof(Q,e) == 16, "");
#endif
_Static_assert(sizeof(R) == 32, "");
_Static_assert(_Alignof(R) == 16, "");
_Static_assert(sizeof(struct R_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct R_extra_alignment) == 16, "");
_Static_assert(sizeof(struct R_extra_packed) == 32, "");
_Static_assert(_Alignof(struct R_extra_packed) == 1, "");
_Static_assert(sizeof(struct R_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct R_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct R_extra_size) == 34, "");
_Static_assert(_Alignof(struct R_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(R,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(R,e) == 128, "");
#endif
_Static_assert(sizeof(S) == 8, "");
_Static_assert(_Alignof(S) == 4, "");
_Static_assert(sizeof(struct S_extra_alignment) == 12, "");
_Static_assert(_Alignof(struct S_extra_alignment) == 4, "");
_Static_assert(sizeof(struct S_extra_packed) == 8, "");
_Static_assert(_Alignof(struct S_extra_packed) == 1, "");
_Static_assert(sizeof(struct S_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct S_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct S_extra_size) == 10, "");
_Static_assert(_Alignof(struct S_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(S,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(S,e) == 32, "");
#endif
_Static_assert(sizeof(T) == 8, "");
_Static_assert(_Alignof(T) == 4, "");
_Static_assert(sizeof(struct T_extra_alignment) == 12, "");
_Static_assert(_Alignof(struct T_extra_alignment) == 4, "");
_Static_assert(sizeof(struct T_extra_packed) == 8, "");
_Static_assert(_Alignof(struct T_extra_packed) == 1, "");
_Static_assert(sizeof(struct T_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct T_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct T_extra_size) == 10, "");
_Static_assert(_Alignof(struct T_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(T,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(T,e) == 32, "");
#endif
_Static_assert(sizeof(U) == 8, "");
_Static_assert(_Alignof(U) == 4, "");
_Static_assert(sizeof(struct U_extra_alignment) == 12, "");
_Static_assert(_Alignof(struct U_extra_alignment) == 4, "");
_Static_assert(sizeof(struct U_extra_packed) == 8, "");
_Static_assert(_Alignof(struct U_extra_packed) == 1, "");
_Static_assert(sizeof(struct U_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct U_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct U_extra_size) == 10, "");
_Static_assert(_Alignof(struct U_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(U,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(U,e) == 32, "");
#endif
_Static_assert(sizeof(V) == 8, "");
_Static_assert(_Alignof(V) == 4, "");
_Static_assert(sizeof(struct V_extra_alignment) == 12, "");
_Static_assert(_Alignof(struct V_extra_alignment) == 4, "");
_Static_assert(sizeof(struct V_extra_packed) == 8, "");
_Static_assert(_Alignof(struct V_extra_packed) == 1, "");
_Static_assert(sizeof(struct V_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct V_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct V_extra_size) == 10, "");
_Static_assert(_Alignof(struct V_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(V,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(V,e) == 32, "");
#endif
_Static_assert(sizeof(W) == 32, "");
_Static_assert(_Alignof(W) == 16, "");
_Static_assert(sizeof(struct W_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct W_extra_alignment) == 16, "");
_Static_assert(sizeof(struct W_extra_packed) == 32, "");
_Static_assert(_Alignof(struct W_extra_packed) == 1, "");
_Static_assert(sizeof(struct W_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct W_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct W_extra_size) == 34, "");
_Static_assert(_Alignof(struct W_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(W,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(W,e) == 128, "");
#endif
_Static_assert(sizeof(W_) == 32, "");
_Static_assert(_Alignof(W_) == 16, "");
_Static_assert(sizeof(struct W__extra_alignment) == 48, "");
_Static_assert(_Alignof(struct W__extra_alignment) == 16, "");
_Static_assert(sizeof(struct W__extra_packed) == 32, "");
_Static_assert(_Alignof(struct W__extra_packed) == 1, "");
_Static_assert(sizeof(struct W__extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct W__extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct W__extra_size) == 34, "");
_Static_assert(_Alignof(struct W__extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(W_,e) == 128, "");
#endif
_Static_assert(sizeof(X) == 32, "");
_Static_assert(_Alignof(X) == 16, "");
_Static_assert(sizeof(struct X_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct X_extra_alignment) == 16, "");
_Static_assert(sizeof(struct X_extra_packed) == 32, "");
_Static_assert(_Alignof(struct X_extra_packed) == 1, "");
_Static_assert(sizeof(struct X_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct X_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct X_extra_size) == 34, "");
_Static_assert(_Alignof(struct X_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(X,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(X,e) == 128, "");
#endif
_Static_assert(sizeof(A2) == 4, "");
_Static_assert(_Alignof(A2) == 4, "");
_Static_assert(sizeof(struct A2_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct A2_extra_alignment) == 4, "");
_Static_assert(sizeof(struct A2_extra_packed) == 4, "");
_Static_assert(_Alignof(struct A2_extra_packed) == 1, "");
_Static_assert(sizeof(struct A2_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct A2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A2_extra_size) == 6, "");
_Static_assert(_Alignof(struct A2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A2,d) == 0, "");
#endif
_Static_assert(sizeof(A_2) == 4, "");
_Static_assert(_Alignof(A_2) == 4, "");
_Static_assert(sizeof(struct A_2_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct A_2_extra_alignment) == 4, "");
_Static_assert(sizeof(struct A_2_extra_packed) == 4, "");
_Static_assert(_Alignof(struct A_2_extra_packed) == 1, "");
_Static_assert(sizeof(struct A_2_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct A_2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A_2_extra_size) == 6, "");
_Static_assert(_Alignof(struct A_2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_2,d) == 0, "");
#endif
_Static_assert(sizeof(B2) == 4, "");
_Static_assert(_Alignof(B2) == 4, "");
_Static_assert(sizeof(struct B2_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct B2_extra_alignment) == 4, "");
_Static_assert(sizeof(struct B2_extra_packed) == 4, "");
_Static_assert(_Alignof(struct B2_extra_packed) == 1, "");
_Static_assert(sizeof(struct B2_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct B2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B2_extra_size) == 6, "");
_Static_assert(_Alignof(struct B2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B2,d) == 0, "");
#endif
_Static_assert(sizeof(B_2) == 4, "");
_Static_assert(_Alignof(B_2) == 4, "");
_Static_assert(sizeof(struct B_2_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct B_2_extra_alignment) == 4, "");
_Static_assert(sizeof(struct B_2_extra_packed) == 4, "");
_Static_assert(_Alignof(struct B_2_extra_packed) == 1, "");
_Static_assert(sizeof(struct B_2_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct B_2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B_2_extra_size) == 6, "");
_Static_assert(_Alignof(struct B_2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B_2,d) == 0, "");
#endif
_Static_assert(sizeof(C2) == 4, "");
_Static_assert(_Alignof(C2) == 4, "");
_Static_assert(sizeof(struct C2_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct C2_extra_alignment) == 4, "");
_Static_assert(sizeof(struct C2_extra_packed) == 4, "");
_Static_assert(_Alignof(struct C2_extra_packed) == 1, "");
_Static_assert(sizeof(struct C2_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct C2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct C2_extra_size) == 6, "");
_Static_assert(_Alignof(struct C2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(C2,d) == 0, "");
#endif
_Static_assert(sizeof(C22) == 4, "");
_Static_assert(_Alignof(C22) == 4, "");
_Static_assert(sizeof(struct C22_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct C22_extra_alignment) == 4, "");
_Static_assert(sizeof(struct C22_extra_packed) == 4, "");
_Static_assert(_Alignof(struct C22_extra_packed) == 1, "");
_Static_assert(sizeof(struct C22_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct C22_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct C22_extra_size) == 6, "");
_Static_assert(_Alignof(struct C22_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(C22,d) == 0, "");
#endif
_Static_assert(sizeof(D2) == 8, "");
_Static_assert(_Alignof(D2) == 4, "");
_Static_assert(sizeof(struct D2_extra_alignment) == 12, "");
_Static_assert(_Alignof(struct D2_extra_alignment) == 4, "");
_Static_assert(sizeof(struct D2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct D2_extra_packed) == 1, "");
_Static_assert(sizeof(struct D2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct D2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct D2_extra_size) == 10, "");
_Static_assert(_Alignof(struct D2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(D2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(D2,e) == 0, "");
#endif
_Static_assert(sizeof(F2) == 16, "");
_Static_assert(_Alignof(F2) == 16, "");
_Static_assert(sizeof(struct F2_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct F2_extra_alignment) == 16, "");
_Static_assert(sizeof(struct F2_extra_packed) == 16, "");
_Static_assert(_Alignof(struct F2_extra_packed) == 1, "");
_Static_assert(sizeof(struct F2_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct F2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct F2_extra_size) == 18, "");
_Static_assert(_Alignof(struct F2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(F2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(F2,e) == 0, "");
#endif
_Static_assert(sizeof(G2) == 8, "");
_Static_assert(_Alignof(G2) == 2, "");
_Static_assert(sizeof(struct G2_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct G2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct G2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct G2_extra_packed) == 1, "");
_Static_assert(sizeof(struct G2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct G2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct G2_extra_size) == 10, "");
_Static_assert(_Alignof(struct G2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(G2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(G2,e) == 0, "");
#endif
_Static_assert(sizeof(H2) == 8, "");
_Static_assert(_Alignof(H2) == 2, "");
_Static_assert(sizeof(struct H2_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct H2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct H2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct H2_extra_packed) == 1, "");
_Static_assert(sizeof(struct H2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct H2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct H2_extra_size) == 10, "");
_Static_assert(_Alignof(struct H2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(H2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(H2,e) == 0, "");
#endif
_Static_assert(sizeof(I2) == 8, "");
_Static_assert(_Alignof(I2) == 1, "");
_Static_assert(sizeof(struct I2_extra_alignment) == 9, "");
_Static_assert(_Alignof(struct I2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct I2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct I2_extra_packed) == 1, "");
_Static_assert(sizeof(struct I2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct I2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct I2_extra_size) == 10, "");
_Static_assert(_Alignof(struct I2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(I2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(I2,e) == 0, "");
#endif
_Static_assert(sizeof(J2) == 8, "");
_Static_assert(_Alignof(J2) == 2, "");
_Static_assert(sizeof(struct J2_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct J2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct J2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct J2_extra_packed) == 1, "");
_Static_assert(sizeof(struct J2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct J2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct J2_extra_size) == 10, "");
_Static_assert(_Alignof(struct J2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(J2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(J2,e) == 0, "");
#endif
_Static_assert(sizeof(K2) == 1, "");
_Static_assert(_Alignof(K2) == 1, "");
_Static_assert(sizeof(struct K2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct K2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct K2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct K2_extra_packed) == 1, "");
_Static_assert(sizeof(struct K2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct K2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct K2_extra_size) == 3, "");
_Static_assert(_Alignof(struct K2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(K2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(K2,e) == 0, "");
#endif
_Static_assert(sizeof(L2) == 16, "");
_Static_assert(_Alignof(L2) == 16, "");
_Static_assert(sizeof(struct L2_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct L2_extra_alignment) == 16, "");
_Static_assert(sizeof(struct L2_extra_packed) == 16, "");
_Static_assert(_Alignof(struct L2_extra_packed) == 1, "");
_Static_assert(sizeof(struct L2_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct L2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct L2_extra_size) == 18, "");
_Static_assert(_Alignof(struct L2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(L2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(L2,e) == 0, "");
#endif
_Static_assert(sizeof(M2) == 2, "");
_Static_assert(_Alignof(M2) == 2, "");
_Static_assert(sizeof(struct M2_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct M2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct M2_extra_packed) == 2, "");
_Static_assert(_Alignof(struct M2_extra_packed) == 1, "");
_Static_assert(sizeof(struct M2_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct M2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct M2_extra_size) == 4, "");
_Static_assert(_Alignof(struct M2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(M2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(M2,e) == 0, "");
#endif
_Static_assert(sizeof(N2) == 2, "");
_Static_assert(_Alignof(N2) == 2, "");
_Static_assert(sizeof(struct N2_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct N2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct N2_extra_packed) == 2, "");
_Static_assert(_Alignof(struct N2_extra_packed) == 1, "");
_Static_assert(sizeof(struct N2_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct N2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct N2_extra_size) == 4, "");
_Static_assert(_Alignof(struct N2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(N2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(N2,e) == 0, "");
#endif
_Static_assert(sizeof(O2) == 1, "");
_Static_assert(_Alignof(O2) == 1, "");
_Static_assert(sizeof(struct O2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct O2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct O2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct O2_extra_packed) == 1, "");
_Static_assert(sizeof(struct O2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct O2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct O2_extra_size) == 3, "");
_Static_assert(_Alignof(struct O2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(O2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(O2,e) == 0, "");
#endif
_Static_assert(sizeof(P2) == 1, "");
_Static_assert(_Alignof(P2) == 1, "");
_Static_assert(sizeof(struct P2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct P2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct P2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct P2_extra_packed) == 1, "");
_Static_assert(sizeof(struct P2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct P2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct P2_extra_size) == 3, "");
_Static_assert(_Alignof(struct P2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(P2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(P2,e) == 0, "");
#endif
_Static_assert(sizeof(Q2) == 1, "");
_Static_assert(_Alignof(Q2) == 1, "");
_Static_assert(sizeof(struct Q2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct Q2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct Q2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct Q2_extra_packed) == 1, "");
_Static_assert(sizeof(struct Q2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct Q2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct Q2_extra_size) == 3, "");
_Static_assert(_Alignof(struct Q2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(Q2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(Q2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(Q2,e) == 0, "");
#endif
_Static_assert(sizeof(R2) == 16, "");
_Static_assert(_Alignof(R2) == 16, "");
_Static_assert(sizeof(struct R2_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct R2_extra_alignment) == 16, "");
_Static_assert(sizeof(struct R2_extra_packed) == 16, "");
_Static_assert(_Alignof(struct R2_extra_packed) == 1, "");
_Static_assert(sizeof(struct R2_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct R2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct R2_extra_size) == 18, "");
_Static_assert(_Alignof(struct R2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(R2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(R2,e) == 0, "");
#endif
_Static_assert(sizeof(S2) == 4, "");
_Static_assert(_Alignof(S2) == 4, "");
_Static_assert(sizeof(struct S2_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct S2_extra_alignment) == 4, "");
_Static_assert(sizeof(struct S2_extra_packed) == 4, "");
_Static_assert(_Alignof(struct S2_extra_packed) == 1, "");
_Static_assert(sizeof(struct S2_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct S2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct S2_extra_size) == 6, "");
_Static_assert(_Alignof(struct S2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(S2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(S2,e) == 0, "");
#endif
_Static_assert(sizeof(T2) == 4, "");
_Static_assert(_Alignof(T2) == 4, "");
_Static_assert(sizeof(struct T2_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct T2_extra_alignment) == 4, "");
_Static_assert(sizeof(struct T2_extra_packed) == 4, "");
_Static_assert(_Alignof(struct T2_extra_packed) == 1, "");
_Static_assert(sizeof(struct T2_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct T2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct T2_extra_size) == 6, "");
_Static_assert(_Alignof(struct T2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(T2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(T2,e) == 0, "");
#endif
_Static_assert(sizeof(U2) == 4, "");
_Static_assert(_Alignof(U2) == 4, "");
_Static_assert(sizeof(struct U2_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct U2_extra_alignment) == 4, "");
_Static_assert(sizeof(struct U2_extra_packed) == 4, "");
_Static_assert(_Alignof(struct U2_extra_packed) == 1, "");
_Static_assert(sizeof(struct U2_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct U2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct U2_extra_size) == 6, "");
_Static_assert(_Alignof(struct U2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(U2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(U2,e) == 0, "");
#endif
_Static_assert(sizeof(V2) == 4, "");
_Static_assert(_Alignof(V2) == 4, "");
_Static_assert(sizeof(struct V2_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct V2_extra_alignment) == 4, "");
_Static_assert(sizeof(struct V2_extra_packed) == 4, "");
_Static_assert(_Alignof(struct V2_extra_packed) == 1, "");
_Static_assert(sizeof(struct V2_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct V2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct V2_extra_size) == 6, "");
_Static_assert(_Alignof(struct V2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(V2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(V2,e) == 0, "");
#endif
_Static_assert(sizeof(W2) == 16, "");
_Static_assert(_Alignof(W2) == 16, "");
_Static_assert(sizeof(struct W2_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct W2_extra_alignment) == 16, "");
_Static_assert(sizeof(struct W2_extra_packed) == 16, "");
_Static_assert(_Alignof(struct W2_extra_packed) == 1, "");
_Static_assert(sizeof(struct W2_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct W2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct W2_extra_size) == 18, "");
_Static_assert(_Alignof(struct W2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(W2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(W2,e) == 0, "");
#endif
_Static_assert(sizeof(W_2) == 16, "");
_Static_assert(_Alignof(W_2) == 16, "");
_Static_assert(sizeof(struct W_2_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct W_2_extra_alignment) == 16, "");
_Static_assert(sizeof(struct W_2_extra_packed) == 16, "");
_Static_assert(_Alignof(struct W_2_extra_packed) == 1, "");
_Static_assert(sizeof(struct W_2_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct W_2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct W_2_extra_size) == 18, "");
_Static_assert(_Alignof(struct W_2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(W_2,e) == 0, "");
#endif
_Static_assert(sizeof(X2) == 16, "");
_Static_assert(_Alignof(X2) == 16, "");
_Static_assert(sizeof(struct X2_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct X2_extra_alignment) == 16, "");
_Static_assert(sizeof(struct X2_extra_packed) == 16, "");
_Static_assert(_Alignof(struct X2_extra_packed) == 1, "");
_Static_assert(sizeof(struct X2_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct X2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct X2_extra_size) == 18, "");
_Static_assert(_Alignof(struct X2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(X2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(X2,e) == 0, "");
#endif
_Static_assert(sizeof(Y) == 8, "");
_Static_assert(_Alignof(Y) == 4, "");
_Static_assert(sizeof(struct Y_extra_alignment) == 12, "");
_Static_assert(_Alignof(struct Y_extra_alignment) == 4, "");
_Static_assert(sizeof(struct Y_extra_packed) == 8, "");
_Static_assert(_Alignof(struct Y_extra_packed) == 1, "");
_Static_assert(sizeof(struct Y_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct Y_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct Y_extra_size) == 10, "");
_Static_assert(_Alignof(struct Y_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(Y,d) == 32, "");
#endif
_Static_assert(sizeof(Y2) == 4, "");
_Static_assert(_Alignof(Y2) == 4, "");
_Static_assert(sizeof(struct Y2_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct Y2_extra_alignment) == 4, "");
_Static_assert(sizeof(struct Y2_extra_packed) == 4, "");
_Static_assert(_Alignof(struct Y2_extra_packed) == 1, "");
_Static_assert(sizeof(struct Y2_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct Y2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct Y2_extra_size) == 6, "");
_Static_assert(_Alignof(struct Y2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(Y2,d) == 0, "");
#endif
_Static_assert(sizeof(A3) == 64, "");
_Static_assert(_Alignof(A3) == 32, "");
_Static_assert(sizeof(struct A3_extra_alignment) == 96, "");
_Static_assert(_Alignof(struct A3_extra_alignment) == 32, "");
_Static_assert(sizeof(struct A3_extra_packed) == 64, "");
_Static_assert(_Alignof(struct A3_extra_packed) == 1, "");
_Static_assert(sizeof(struct A3_extra_required_alignment) == 65, "");
_Static_assert(_Alignof(struct A3_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A3_extra_size) == 66, "");
_Static_assert(_Alignof(struct A3_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A3,d) == 256, "");
#endif
_Static_assert(sizeof(A4) == 1, "");
_Static_assert(_Alignof(A4) == 32, "");
_Static_assert(sizeof(struct A4_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct A4_extra_alignment) == 32, "");
_Static_assert(sizeof(struct A4_extra_packed) == 1, "");
_Static_assert(_Alignof(struct A4_extra_packed) == 1, "");
_Static_assert(sizeof(struct A4_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct A4_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A4_extra_size) == 3, "");
_Static_assert(_Alignof(struct A4_extra_size) == 1, "");
_Static_assert(sizeof(A5) == 64, "");
_Static_assert(_Alignof(A5) == 32, "");
_Static_assert(sizeof(struct A5_extra_alignment) == 96, "");
_Static_assert(_Alignof(struct A5_extra_alignment) == 32, "");
_Static_assert(sizeof(struct A5_extra_packed) == 64, "");
_Static_assert(_Alignof(struct A5_extra_packed) == 1, "");
_Static_assert(sizeof(struct A5_extra_required_alignment) == 65, "");
_Static_assert(_Alignof(struct A5_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A5_extra_size) == 66, "");
_Static_assert(_Alignof(struct A5_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A5,d) == 256, "");
#endif
_Static_assert(sizeof(A7) == 32, "");
_Static_assert(_Alignof(A7) == 32, "");
_Static_assert(sizeof(struct A7_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct A7_extra_alignment) == 32, "");
_Static_assert(sizeof(struct A7_extra_packed) == 32, "");
_Static_assert(_Alignof(struct A7_extra_packed) == 1, "");
_Static_assert(sizeof(struct A7_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct A7_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A7_extra_size) == 34, "");
_Static_assert(_Alignof(struct A7_extra_size) == 1, "");
_Static_assert(sizeof(A8) == 6, "");
_Static_assert(_Alignof(A8) == 1, "");
_Static_assert(sizeof(struct A8_extra_alignment) == 7, "");
_Static_assert(_Alignof(struct A8_extra_alignment) == 1, "");
_Static_assert(sizeof(struct A8_extra_packed) == 6, "");
_Static_assert(_Alignof(struct A8_extra_packed) == 1, "");
_Static_assert(sizeof(struct A8_extra_required_alignment) == 7, "");
_Static_assert(_Alignof(struct A8_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A8_extra_size) == 8, "");
_Static_assert(_Alignof(struct A8_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A8,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A8,j) == 39, "");
#endif
_Static_assert(sizeof(A9) == 12, "");
_Static_assert(_Alignof(A9) == 4, "");
_Static_assert(sizeof(struct A9_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct A9_extra_alignment) == 4, "");
_Static_assert(sizeof(struct A9_extra_packed) == 12, "");
_Static_assert(_Alignof(struct A9_extra_packed) == 1, "");
_Static_assert(sizeof(struct A9_extra_required_alignment) == 13, "");
_Static_assert(_Alignof(struct A9_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A9_extra_size) == 14, "");
_Static_assert(_Alignof(struct A9_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A9,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A9,j) == 64, "");
#endif
_Static_assert(sizeof(A10) == 4, "");
_Static_assert(_Alignof(A10) == 16, "");
_Static_assert(sizeof(struct A10_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct A10_extra_alignment) == 16, "");
_Static_assert(sizeof(struct A10_extra_packed) == 4, "");
_Static_assert(_Alignof(struct A10_extra_packed) == 1, "");
_Static_assert(sizeof(struct A10_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct A10_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A10_extra_size) == 6, "");
_Static_assert(_Alignof(struct A10_extra_size) == 1, "");
_Static_assert(sizeof(A11) == 6, "");
_Static_assert(_Alignof(A11) == 1, "");
_Static_assert(sizeof(struct A11_extra_alignment) == 7, "");
_Static_assert(_Alignof(struct A11_extra_alignment) == 1, "");
_Static_assert(sizeof(struct A11_extra_packed) == 6, "");
_Static_assert(_Alignof(struct A11_extra_packed) == 1, "");
_Static_assert(sizeof(struct A11_extra_required_alignment) == 7, "");
_Static_assert(_Alignof(struct A11_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A11_extra_size) == 8, "");
_Static_assert(_Alignof(struct A11_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A11,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A11,j) == 39, "");
#endif
_Static_assert(sizeof(A12) == 32, "");
_Static_assert(_Alignof(A12) == 16, "");
_Static_assert(sizeof(struct A12_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct A12_extra_alignment) == 16, "");
_Static_assert(sizeof(struct A12_extra_packed) == 32, "");
_Static_assert(_Alignof(struct A12_extra_packed) == 1, "");
_Static_assert(sizeof(struct A12_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct A12_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A12_extra_size) == 34, "");
_Static_assert(_Alignof(struct A12_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A12,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A12,j) == 128, "");
#endif
_Static_assert(sizeof(A13) == 32, "");
_Static_assert(_Alignof(A13) == 16, "");
_Static_assert(sizeof(struct A13_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct A13_extra_alignment) == 16, "");
_Static_assert(sizeof(struct A13_extra_packed) == 32, "");
_Static_assert(_Alignof(struct A13_extra_packed) == 1, "");
_Static_assert(sizeof(struct A13_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct A13_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A13_extra_size) == 34, "");
_Static_assert(_Alignof(struct A13_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A13,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A13,j) == 128, "");
_Static_assert(__builtin_bitoffsetof(A13,d) == 136, "");
#endif
// MAPPING|SEVEN|avr-avr2-other-eabi:Gcc|END
// repr targets AvrUnknownUnknown|Some("avr-avr2-other-eabi") 
#elif defined(SEVEN)
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
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A,d) == 0, "");
#endif
_Static_assert(sizeof(A_) == 8, "");
_Static_assert(_Alignof(A_) == 4, "");
_Static_assert(sizeof(struct A__extra_alignment) == 12, "");
_Static_assert(_Alignof(struct A__extra_alignment) == 4, "");
_Static_assert(sizeof(struct A__extra_packed) == 8, "");
_Static_assert(_Alignof(struct A__extra_packed) == 1, "");
_Static_assert(sizeof(struct A__extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct A__extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A__extra_size) == 10, "");
_Static_assert(_Alignof(struct A__extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_,d) == 32, "");
#endif
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
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B,d) == 0, "");
#endif
_Static_assert(sizeof(B_) == 8, "");
_Static_assert(_Alignof(B_) == 4, "");
_Static_assert(sizeof(struct B__extra_alignment) == 12, "");
_Static_assert(_Alignof(struct B__extra_alignment) == 4, "");
_Static_assert(sizeof(struct B__extra_packed) == 8, "");
_Static_assert(_Alignof(struct B__extra_packed) == 1, "");
_Static_assert(sizeof(struct B__extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct B__extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B__extra_size) == 10, "");
_Static_assert(_Alignof(struct B__extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B_,d) == 32, "");
#endif
_Static_assert(sizeof(C) == 1, "");
_Static_assert(_Alignof(C) == 1, "");
_Static_assert(sizeof(struct C_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct C_extra_alignment) == 1, "");
_Static_assert(sizeof(struct C_extra_packed) == 1, "");
_Static_assert(_Alignof(struct C_extra_packed) == 1, "");
_Static_assert(sizeof(struct C_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct C_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct C_extra_size) == 3, "");
_Static_assert(_Alignof(struct C_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(C,d) == 0, "");
#endif
_Static_assert(sizeof(C_) == 2, "");
_Static_assert(_Alignof(C_) == 1, "");
_Static_assert(sizeof(struct C__extra_alignment) == 3, "");
_Static_assert(_Alignof(struct C__extra_alignment) == 1, "");
_Static_assert(sizeof(struct C__extra_packed) == 2, "");
_Static_assert(_Alignof(struct C__extra_packed) == 1, "");
_Static_assert(sizeof(struct C__extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct C__extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct C__extra_size) == 4, "");
_Static_assert(_Alignof(struct C__extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(C_,d) == 8, "");
#endif
_Static_assert(sizeof(D) == 10, "");
_Static_assert(_Alignof(D) == 1, "");
_Static_assert(sizeof(struct D_extra_alignment) == 11, "");
_Static_assert(_Alignof(struct D_extra_alignment) == 1, "");
_Static_assert(sizeof(struct D_extra_packed) == 10, "");
_Static_assert(_Alignof(struct D_extra_packed) == 1, "");
_Static_assert(sizeof(struct D_extra_required_alignment) == 11, "");
_Static_assert(_Alignof(struct D_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct D_extra_size) == 12, "");
_Static_assert(_Alignof(struct D_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(D,d) == 8, "");
_Static_assert(__builtin_bitoffsetof(D,e) == 72, "");
#endif
_Static_assert(sizeof(F) == 32, "");
_Static_assert(_Alignof(F) == 16, "");
_Static_assert(sizeof(struct F_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct F_extra_alignment) == 16, "");
_Static_assert(sizeof(struct F_extra_packed) == 32, "");
_Static_assert(_Alignof(struct F_extra_packed) == 1, "");
_Static_assert(sizeof(struct F_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct F_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct F_extra_size) == 34, "");
_Static_assert(_Alignof(struct F_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(F,d) == 128, "");
_Static_assert(__builtin_bitoffsetof(F,e) == 192, "");
#endif
_Static_assert(sizeof(G) == 12, "");
_Static_assert(_Alignof(G) == 2, "");
_Static_assert(sizeof(struct G_extra_alignment) == 14, "");
_Static_assert(_Alignof(struct G_extra_alignment) == 2, "");
_Static_assert(sizeof(struct G_extra_packed) == 12, "");
_Static_assert(_Alignof(struct G_extra_packed) == 1, "");
_Static_assert(sizeof(struct G_extra_required_alignment) == 13, "");
_Static_assert(_Alignof(struct G_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct G_extra_size) == 14, "");
_Static_assert(_Alignof(struct G_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(G,d) == 16, "");
_Static_assert(__builtin_bitoffsetof(G,e) == 80, "");
#endif
_Static_assert(sizeof(H) == 12, "");
_Static_assert(_Alignof(H) == 2, "");
_Static_assert(sizeof(struct H_extra_alignment) == 14, "");
_Static_assert(_Alignof(struct H_extra_alignment) == 2, "");
_Static_assert(sizeof(struct H_extra_packed) == 12, "");
_Static_assert(_Alignof(struct H_extra_packed) == 1, "");
_Static_assert(sizeof(struct H_extra_required_alignment) == 13, "");
_Static_assert(_Alignof(struct H_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct H_extra_size) == 14, "");
_Static_assert(_Alignof(struct H_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(H,d) == 16, "");
_Static_assert(__builtin_bitoffsetof(H,e) == 80, "");
#endif
_Static_assert(sizeof(I) == 10, "");
_Static_assert(_Alignof(I) == 1, "");
_Static_assert(sizeof(struct I_extra_alignment) == 11, "");
_Static_assert(_Alignof(struct I_extra_alignment) == 1, "");
_Static_assert(sizeof(struct I_extra_packed) == 10, "");
_Static_assert(_Alignof(struct I_extra_packed) == 1, "");
_Static_assert(sizeof(struct I_extra_required_alignment) == 11, "");
_Static_assert(_Alignof(struct I_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct I_extra_size) == 12, "");
_Static_assert(_Alignof(struct I_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(I,d) == 8, "");
_Static_assert(__builtin_bitoffsetof(I,e) == 72, "");
#endif
_Static_assert(sizeof(J) == 10, "");
_Static_assert(_Alignof(J) == 1, "");
_Static_assert(sizeof(struct J_extra_alignment) == 11, "");
_Static_assert(_Alignof(struct J_extra_alignment) == 1, "");
_Static_assert(sizeof(struct J_extra_packed) == 10, "");
_Static_assert(_Alignof(struct J_extra_packed) == 1, "");
_Static_assert(sizeof(struct J_extra_required_alignment) == 11, "");
_Static_assert(_Alignof(struct J_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct J_extra_size) == 12, "");
_Static_assert(_Alignof(struct J_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(J,d) == 8, "");
_Static_assert(__builtin_bitoffsetof(J,e) == 72, "");
#endif
_Static_assert(sizeof(K) == 3, "");
_Static_assert(_Alignof(K) == 1, "");
_Static_assert(sizeof(struct K_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct K_extra_alignment) == 1, "");
_Static_assert(sizeof(struct K_extra_packed) == 3, "");
_Static_assert(_Alignof(struct K_extra_packed) == 1, "");
_Static_assert(sizeof(struct K_extra_required_alignment) == 4, "");
_Static_assert(_Alignof(struct K_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct K_extra_size) == 5, "");
_Static_assert(_Alignof(struct K_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(K,d) == 8, "");
_Static_assert(__builtin_bitoffsetof(K,e) == 16, "");
#endif
_Static_assert(sizeof(L) == 32, "");
_Static_assert(_Alignof(L) == 16, "");
_Static_assert(sizeof(struct L_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct L_extra_alignment) == 16, "");
_Static_assert(sizeof(struct L_extra_packed) == 32, "");
_Static_assert(_Alignof(struct L_extra_packed) == 1, "");
_Static_assert(sizeof(struct L_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct L_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct L_extra_size) == 34, "");
_Static_assert(_Alignof(struct L_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(L,d) == 128, "");
_Static_assert(__builtin_bitoffsetof(L,e) == 136, "");
#endif
_Static_assert(sizeof(M) == 4, "");
_Static_assert(_Alignof(M) == 2, "");
_Static_assert(sizeof(struct M_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct M_extra_alignment) == 2, "");
_Static_assert(sizeof(struct M_extra_packed) == 4, "");
_Static_assert(_Alignof(struct M_extra_packed) == 1, "");
_Static_assert(sizeof(struct M_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct M_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct M_extra_size) == 6, "");
_Static_assert(_Alignof(struct M_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(M,d) == 16, "");
_Static_assert(__builtin_bitoffsetof(M,e) == 24, "");
#endif
_Static_assert(sizeof(N) == 4, "");
_Static_assert(_Alignof(N) == 2, "");
_Static_assert(sizeof(struct N_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct N_extra_alignment) == 2, "");
_Static_assert(sizeof(struct N_extra_packed) == 4, "");
_Static_assert(_Alignof(struct N_extra_packed) == 1, "");
_Static_assert(sizeof(struct N_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct N_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct N_extra_size) == 6, "");
_Static_assert(_Alignof(struct N_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(N,d) == 16, "");
_Static_assert(__builtin_bitoffsetof(N,e) == 24, "");
#endif
_Static_assert(sizeof(O) == 3, "");
_Static_assert(_Alignof(O) == 1, "");
_Static_assert(sizeof(struct O_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct O_extra_alignment) == 1, "");
_Static_assert(sizeof(struct O_extra_packed) == 3, "");
_Static_assert(_Alignof(struct O_extra_packed) == 1, "");
_Static_assert(sizeof(struct O_extra_required_alignment) == 4, "");
_Static_assert(_Alignof(struct O_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct O_extra_size) == 5, "");
_Static_assert(_Alignof(struct O_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(O,d) == 8, "");
_Static_assert(__builtin_bitoffsetof(O,e) == 16, "");
#endif
_Static_assert(sizeof(P) == 3, "");
_Static_assert(_Alignof(P) == 1, "");
_Static_assert(sizeof(struct P_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct P_extra_alignment) == 1, "");
_Static_assert(sizeof(struct P_extra_packed) == 3, "");
_Static_assert(_Alignof(struct P_extra_packed) == 1, "");
_Static_assert(sizeof(struct P_extra_required_alignment) == 4, "");
_Static_assert(_Alignof(struct P_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct P_extra_size) == 5, "");
_Static_assert(_Alignof(struct P_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(P,d) == 8, "");
_Static_assert(__builtin_bitoffsetof(P,e) == 16, "");
#endif
_Static_assert(sizeof(Q) == 3, "");
_Static_assert(_Alignof(Q) == 1, "");
_Static_assert(sizeof(struct Q_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct Q_extra_alignment) == 1, "");
_Static_assert(sizeof(struct Q_extra_packed) == 3, "");
_Static_assert(_Alignof(struct Q_extra_packed) == 1, "");
_Static_assert(sizeof(struct Q_extra_required_alignment) == 4, "");
_Static_assert(_Alignof(struct Q_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct Q_extra_size) == 5, "");
_Static_assert(_Alignof(struct Q_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(Q,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(Q,d) == 9, "");
_Static_assert(__builtin_bitoffsetof(Q,e) == 16, "");
#endif
_Static_assert(sizeof(R) == 32, "");
_Static_assert(_Alignof(R) == 16, "");
_Static_assert(sizeof(struct R_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct R_extra_alignment) == 16, "");
_Static_assert(sizeof(struct R_extra_packed) == 32, "");
_Static_assert(_Alignof(struct R_extra_packed) == 1, "");
_Static_assert(sizeof(struct R_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct R_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct R_extra_size) == 34, "");
_Static_assert(_Alignof(struct R_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(R,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(R,e) == 128, "");
#endif
_Static_assert(sizeof(S) == 4, "");
_Static_assert(_Alignof(S) == 2, "");
_Static_assert(sizeof(struct S_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct S_extra_alignment) == 2, "");
_Static_assert(sizeof(struct S_extra_packed) == 4, "");
_Static_assert(_Alignof(struct S_extra_packed) == 1, "");
_Static_assert(sizeof(struct S_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct S_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct S_extra_size) == 6, "");
_Static_assert(_Alignof(struct S_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(S,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(S,e) == 16, "");
#endif
_Static_assert(sizeof(T) == 8, "");
_Static_assert(_Alignof(T) == 4, "");
_Static_assert(sizeof(struct T_extra_alignment) == 12, "");
_Static_assert(_Alignof(struct T_extra_alignment) == 4, "");
_Static_assert(sizeof(struct T_extra_packed) == 8, "");
_Static_assert(_Alignof(struct T_extra_packed) == 1, "");
_Static_assert(sizeof(struct T_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct T_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct T_extra_size) == 10, "");
_Static_assert(_Alignof(struct T_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(T,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(T,e) == 32, "");
#endif
_Static_assert(sizeof(U) == 3, "");
_Static_assert(_Alignof(U) == 1, "");
_Static_assert(sizeof(struct U_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct U_extra_alignment) == 1, "");
_Static_assert(sizeof(struct U_extra_packed) == 3, "");
_Static_assert(_Alignof(struct U_extra_packed) == 1, "");
_Static_assert(sizeof(struct U_extra_required_alignment) == 4, "");
_Static_assert(_Alignof(struct U_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct U_extra_size) == 5, "");
_Static_assert(_Alignof(struct U_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(U,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(U,e) == 16, "");
#endif
_Static_assert(sizeof(V) == 3, "");
_Static_assert(_Alignof(V) == 1, "");
_Static_assert(sizeof(struct V_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct V_extra_alignment) == 1, "");
_Static_assert(sizeof(struct V_extra_packed) == 3, "");
_Static_assert(_Alignof(struct V_extra_packed) == 1, "");
_Static_assert(sizeof(struct V_extra_required_alignment) == 4, "");
_Static_assert(_Alignof(struct V_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct V_extra_size) == 5, "");
_Static_assert(_Alignof(struct V_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(V,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(V,e) == 16, "");
#endif
_Static_assert(sizeof(W) == 32, "");
_Static_assert(_Alignof(W) == 16, "");
_Static_assert(sizeof(struct W_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct W_extra_alignment) == 16, "");
_Static_assert(sizeof(struct W_extra_packed) == 32, "");
_Static_assert(_Alignof(struct W_extra_packed) == 1, "");
_Static_assert(sizeof(struct W_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct W_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct W_extra_size) == 34, "");
_Static_assert(_Alignof(struct W_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(W,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(W,e) == 128, "");
#endif
_Static_assert(sizeof(W_) == 32, "");
_Static_assert(_Alignof(W_) == 16, "");
_Static_assert(sizeof(struct W__extra_alignment) == 48, "");
_Static_assert(_Alignof(struct W__extra_alignment) == 16, "");
_Static_assert(sizeof(struct W__extra_packed) == 32, "");
_Static_assert(_Alignof(struct W__extra_packed) == 1, "");
_Static_assert(sizeof(struct W__extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct W__extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct W__extra_size) == 34, "");
_Static_assert(_Alignof(struct W__extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(W_,e) == 128, "");
#endif
_Static_assert(sizeof(X) == 32, "");
_Static_assert(_Alignof(X) == 16, "");
_Static_assert(sizeof(struct X_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct X_extra_alignment) == 16, "");
_Static_assert(sizeof(struct X_extra_packed) == 32, "");
_Static_assert(_Alignof(struct X_extra_packed) == 1, "");
_Static_assert(sizeof(struct X_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct X_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct X_extra_size) == 34, "");
_Static_assert(_Alignof(struct X_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(X,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(X,e) == 128, "");
#endif
_Static_assert(sizeof(A2) == 4, "");
_Static_assert(_Alignof(A2) == 4, "");
_Static_assert(sizeof(struct A2_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct A2_extra_alignment) == 4, "");
_Static_assert(sizeof(struct A2_extra_packed) == 4, "");
_Static_assert(_Alignof(struct A2_extra_packed) == 1, "");
_Static_assert(sizeof(struct A2_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct A2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A2_extra_size) == 6, "");
_Static_assert(_Alignof(struct A2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A2,d) == 0, "");
#endif
_Static_assert(sizeof(A_2) == 4, "");
_Static_assert(_Alignof(A_2) == 4, "");
_Static_assert(sizeof(struct A_2_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct A_2_extra_alignment) == 4, "");
_Static_assert(sizeof(struct A_2_extra_packed) == 4, "");
_Static_assert(_Alignof(struct A_2_extra_packed) == 1, "");
_Static_assert(sizeof(struct A_2_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct A_2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A_2_extra_size) == 6, "");
_Static_assert(_Alignof(struct A_2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_2,d) == 0, "");
#endif
_Static_assert(sizeof(B2) == 4, "");
_Static_assert(_Alignof(B2) == 4, "");
_Static_assert(sizeof(struct B2_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct B2_extra_alignment) == 4, "");
_Static_assert(sizeof(struct B2_extra_packed) == 4, "");
_Static_assert(_Alignof(struct B2_extra_packed) == 1, "");
_Static_assert(sizeof(struct B2_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct B2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B2_extra_size) == 6, "");
_Static_assert(_Alignof(struct B2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B2,d) == 0, "");
#endif
_Static_assert(sizeof(B_2) == 4, "");
_Static_assert(_Alignof(B_2) == 4, "");
_Static_assert(sizeof(struct B_2_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct B_2_extra_alignment) == 4, "");
_Static_assert(sizeof(struct B_2_extra_packed) == 4, "");
_Static_assert(_Alignof(struct B_2_extra_packed) == 1, "");
_Static_assert(sizeof(struct B_2_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct B_2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B_2_extra_size) == 6, "");
_Static_assert(_Alignof(struct B_2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B_2,d) == 0, "");
#endif
_Static_assert(sizeof(C2) == 1, "");
_Static_assert(_Alignof(C2) == 1, "");
_Static_assert(sizeof(struct C2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct C2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct C2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct C2_extra_packed) == 1, "");
_Static_assert(sizeof(struct C2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct C2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct C2_extra_size) == 3, "");
_Static_assert(_Alignof(struct C2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(C2,d) == 0, "");
#endif
_Static_assert(sizeof(C22) == 1, "");
_Static_assert(_Alignof(C22) == 1, "");
_Static_assert(sizeof(struct C22_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct C22_extra_alignment) == 1, "");
_Static_assert(sizeof(struct C22_extra_packed) == 1, "");
_Static_assert(_Alignof(struct C22_extra_packed) == 1, "");
_Static_assert(sizeof(struct C22_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct C22_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct C22_extra_size) == 3, "");
_Static_assert(_Alignof(struct C22_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(C22,d) == 0, "");
#endif
_Static_assert(sizeof(D2) == 8, "");
_Static_assert(_Alignof(D2) == 1, "");
_Static_assert(sizeof(struct D2_extra_alignment) == 9, "");
_Static_assert(_Alignof(struct D2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct D2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct D2_extra_packed) == 1, "");
_Static_assert(sizeof(struct D2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct D2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct D2_extra_size) == 10, "");
_Static_assert(_Alignof(struct D2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(D2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(D2,e) == 0, "");
#endif
_Static_assert(sizeof(F2) == 16, "");
_Static_assert(_Alignof(F2) == 16, "");
_Static_assert(sizeof(struct F2_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct F2_extra_alignment) == 16, "");
_Static_assert(sizeof(struct F2_extra_packed) == 16, "");
_Static_assert(_Alignof(struct F2_extra_packed) == 1, "");
_Static_assert(sizeof(struct F2_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct F2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct F2_extra_size) == 18, "");
_Static_assert(_Alignof(struct F2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(F2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(F2,e) == 0, "");
#endif
_Static_assert(sizeof(G2) == 8, "");
_Static_assert(_Alignof(G2) == 2, "");
_Static_assert(sizeof(struct G2_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct G2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct G2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct G2_extra_packed) == 1, "");
_Static_assert(sizeof(struct G2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct G2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct G2_extra_size) == 10, "");
_Static_assert(_Alignof(struct G2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(G2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(G2,e) == 0, "");
#endif
_Static_assert(sizeof(H2) == 8, "");
_Static_assert(_Alignof(H2) == 2, "");
_Static_assert(sizeof(struct H2_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct H2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct H2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct H2_extra_packed) == 1, "");
_Static_assert(sizeof(struct H2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct H2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct H2_extra_size) == 10, "");
_Static_assert(_Alignof(struct H2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(H2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(H2,e) == 0, "");
#endif
_Static_assert(sizeof(I2) == 8, "");
_Static_assert(_Alignof(I2) == 1, "");
_Static_assert(sizeof(struct I2_extra_alignment) == 9, "");
_Static_assert(_Alignof(struct I2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct I2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct I2_extra_packed) == 1, "");
_Static_assert(sizeof(struct I2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct I2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct I2_extra_size) == 10, "");
_Static_assert(_Alignof(struct I2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(I2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(I2,e) == 0, "");
#endif
_Static_assert(sizeof(J2) == 8, "");
_Static_assert(_Alignof(J2) == 1, "");
_Static_assert(sizeof(struct J2_extra_alignment) == 9, "");
_Static_assert(_Alignof(struct J2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct J2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct J2_extra_packed) == 1, "");
_Static_assert(sizeof(struct J2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct J2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct J2_extra_size) == 10, "");
_Static_assert(_Alignof(struct J2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(J2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(J2,e) == 0, "");
#endif
_Static_assert(sizeof(K2) == 1, "");
_Static_assert(_Alignof(K2) == 1, "");
_Static_assert(sizeof(struct K2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct K2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct K2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct K2_extra_packed) == 1, "");
_Static_assert(sizeof(struct K2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct K2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct K2_extra_size) == 3, "");
_Static_assert(_Alignof(struct K2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(K2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(K2,e) == 0, "");
#endif
_Static_assert(sizeof(L2) == 16, "");
_Static_assert(_Alignof(L2) == 16, "");
_Static_assert(sizeof(struct L2_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct L2_extra_alignment) == 16, "");
_Static_assert(sizeof(struct L2_extra_packed) == 16, "");
_Static_assert(_Alignof(struct L2_extra_packed) == 1, "");
_Static_assert(sizeof(struct L2_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct L2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct L2_extra_size) == 18, "");
_Static_assert(_Alignof(struct L2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(L2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(L2,e) == 0, "");
#endif
_Static_assert(sizeof(M2) == 2, "");
_Static_assert(_Alignof(M2) == 2, "");
_Static_assert(sizeof(struct M2_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct M2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct M2_extra_packed) == 2, "");
_Static_assert(_Alignof(struct M2_extra_packed) == 1, "");
_Static_assert(sizeof(struct M2_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct M2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct M2_extra_size) == 4, "");
_Static_assert(_Alignof(struct M2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(M2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(M2,e) == 0, "");
#endif
_Static_assert(sizeof(N2) == 2, "");
_Static_assert(_Alignof(N2) == 2, "");
_Static_assert(sizeof(struct N2_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct N2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct N2_extra_packed) == 2, "");
_Static_assert(_Alignof(struct N2_extra_packed) == 1, "");
_Static_assert(sizeof(struct N2_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct N2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct N2_extra_size) == 4, "");
_Static_assert(_Alignof(struct N2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(N2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(N2,e) == 0, "");
#endif
_Static_assert(sizeof(O2) == 1, "");
_Static_assert(_Alignof(O2) == 1, "");
_Static_assert(sizeof(struct O2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct O2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct O2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct O2_extra_packed) == 1, "");
_Static_assert(sizeof(struct O2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct O2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct O2_extra_size) == 3, "");
_Static_assert(_Alignof(struct O2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(O2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(O2,e) == 0, "");
#endif
_Static_assert(sizeof(P2) == 1, "");
_Static_assert(_Alignof(P2) == 1, "");
_Static_assert(sizeof(struct P2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct P2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct P2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct P2_extra_packed) == 1, "");
_Static_assert(sizeof(struct P2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct P2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct P2_extra_size) == 3, "");
_Static_assert(_Alignof(struct P2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(P2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(P2,e) == 0, "");
#endif
_Static_assert(sizeof(Q2) == 1, "");
_Static_assert(_Alignof(Q2) == 1, "");
_Static_assert(sizeof(struct Q2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct Q2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct Q2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct Q2_extra_packed) == 1, "");
_Static_assert(sizeof(struct Q2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct Q2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct Q2_extra_size) == 3, "");
_Static_assert(_Alignof(struct Q2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(Q2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(Q2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(Q2,e) == 0, "");
#endif
_Static_assert(sizeof(R2) == 16, "");
_Static_assert(_Alignof(R2) == 16, "");
_Static_assert(sizeof(struct R2_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct R2_extra_alignment) == 16, "");
_Static_assert(sizeof(struct R2_extra_packed) == 16, "");
_Static_assert(_Alignof(struct R2_extra_packed) == 1, "");
_Static_assert(sizeof(struct R2_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct R2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct R2_extra_size) == 18, "");
_Static_assert(_Alignof(struct R2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(R2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(R2,e) == 0, "");
#endif
_Static_assert(sizeof(S2) == 2, "");
_Static_assert(_Alignof(S2) == 2, "");
_Static_assert(sizeof(struct S2_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct S2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct S2_extra_packed) == 2, "");
_Static_assert(_Alignof(struct S2_extra_packed) == 1, "");
_Static_assert(sizeof(struct S2_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct S2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct S2_extra_size) == 4, "");
_Static_assert(_Alignof(struct S2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(S2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(S2,e) == 0, "");
#endif
_Static_assert(sizeof(T2) == 4, "");
_Static_assert(_Alignof(T2) == 4, "");
_Static_assert(sizeof(struct T2_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct T2_extra_alignment) == 4, "");
_Static_assert(sizeof(struct T2_extra_packed) == 4, "");
_Static_assert(_Alignof(struct T2_extra_packed) == 1, "");
_Static_assert(sizeof(struct T2_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct T2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct T2_extra_size) == 6, "");
_Static_assert(_Alignof(struct T2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(T2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(T2,e) == 0, "");
#endif
_Static_assert(sizeof(U2) == 1, "");
_Static_assert(_Alignof(U2) == 1, "");
_Static_assert(sizeof(struct U2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct U2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct U2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct U2_extra_packed) == 1, "");
_Static_assert(sizeof(struct U2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct U2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct U2_extra_size) == 3, "");
_Static_assert(_Alignof(struct U2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(U2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(U2,e) == 0, "");
#endif
_Static_assert(sizeof(V2) == 1, "");
_Static_assert(_Alignof(V2) == 1, "");
_Static_assert(sizeof(struct V2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct V2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct V2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct V2_extra_packed) == 1, "");
_Static_assert(sizeof(struct V2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct V2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct V2_extra_size) == 3, "");
_Static_assert(_Alignof(struct V2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(V2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(V2,e) == 0, "");
#endif
_Static_assert(sizeof(W2) == 16, "");
_Static_assert(_Alignof(W2) == 16, "");
_Static_assert(sizeof(struct W2_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct W2_extra_alignment) == 16, "");
_Static_assert(sizeof(struct W2_extra_packed) == 16, "");
_Static_assert(_Alignof(struct W2_extra_packed) == 1, "");
_Static_assert(sizeof(struct W2_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct W2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct W2_extra_size) == 18, "");
_Static_assert(_Alignof(struct W2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(W2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(W2,e) == 0, "");
#endif
_Static_assert(sizeof(W_2) == 16, "");
_Static_assert(_Alignof(W_2) == 16, "");
_Static_assert(sizeof(struct W_2_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct W_2_extra_alignment) == 16, "");
_Static_assert(sizeof(struct W_2_extra_packed) == 16, "");
_Static_assert(_Alignof(struct W_2_extra_packed) == 1, "");
_Static_assert(sizeof(struct W_2_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct W_2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct W_2_extra_size) == 18, "");
_Static_assert(_Alignof(struct W_2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(W_2,e) == 0, "");
#endif
_Static_assert(sizeof(X2) == 16, "");
_Static_assert(_Alignof(X2) == 16, "");
_Static_assert(sizeof(struct X2_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct X2_extra_alignment) == 16, "");
_Static_assert(sizeof(struct X2_extra_packed) == 16, "");
_Static_assert(_Alignof(struct X2_extra_packed) == 1, "");
_Static_assert(sizeof(struct X2_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct X2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct X2_extra_size) == 18, "");
_Static_assert(_Alignof(struct X2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(X2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(X2,e) == 0, "");
#endif
_Static_assert(sizeof(Y) == 2, "");
_Static_assert(_Alignof(Y) == 1, "");
_Static_assert(sizeof(struct Y_extra_alignment) == 3, "");
_Static_assert(_Alignof(struct Y_extra_alignment) == 1, "");
_Static_assert(sizeof(struct Y_extra_packed) == 2, "");
_Static_assert(_Alignof(struct Y_extra_packed) == 1, "");
_Static_assert(sizeof(struct Y_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct Y_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct Y_extra_size) == 4, "");
_Static_assert(_Alignof(struct Y_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(Y,d) == 8, "");
#endif
_Static_assert(sizeof(Y2) == 1, "");
_Static_assert(_Alignof(Y2) == 1, "");
_Static_assert(sizeof(struct Y2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct Y2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct Y2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct Y2_extra_packed) == 1, "");
_Static_assert(sizeof(struct Y2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct Y2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct Y2_extra_size) == 3, "");
_Static_assert(_Alignof(struct Y2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(Y2,d) == 0, "");
#endif
_Static_assert(sizeof(A3) == 64, "");
_Static_assert(_Alignof(A3) == 32, "");
_Static_assert(sizeof(struct A3_extra_alignment) == 96, "");
_Static_assert(_Alignof(struct A3_extra_alignment) == 32, "");
_Static_assert(sizeof(struct A3_extra_packed) == 64, "");
_Static_assert(_Alignof(struct A3_extra_packed) == 1, "");
_Static_assert(sizeof(struct A3_extra_required_alignment) == 65, "");
_Static_assert(_Alignof(struct A3_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A3_extra_size) == 66, "");
_Static_assert(_Alignof(struct A3_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A3,d) == 256, "");
#endif
_Static_assert(sizeof(A4) == 1, "");
_Static_assert(_Alignof(A4) == 32, "");
_Static_assert(sizeof(struct A4_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct A4_extra_alignment) == 32, "");
_Static_assert(sizeof(struct A4_extra_packed) == 1, "");
_Static_assert(_Alignof(struct A4_extra_packed) == 1, "");
_Static_assert(sizeof(struct A4_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct A4_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A4_extra_size) == 3, "");
_Static_assert(_Alignof(struct A4_extra_size) == 1, "");
_Static_assert(sizeof(A5) == 2, "");
_Static_assert(_Alignof(A5) == 1, "");
_Static_assert(sizeof(struct A5_extra_alignment) == 3, "");
_Static_assert(_Alignof(struct A5_extra_alignment) == 1, "");
_Static_assert(sizeof(struct A5_extra_packed) == 2, "");
_Static_assert(_Alignof(struct A5_extra_packed) == 1, "");
_Static_assert(sizeof(struct A5_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct A5_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A5_extra_size) == 4, "");
_Static_assert(_Alignof(struct A5_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A5,d) == 8, "");
#endif
_Static_assert(sizeof(A7) == 32, "");
_Static_assert(_Alignof(A7) == 32, "");
_Static_assert(sizeof(struct A7_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct A7_extra_alignment) == 32, "");
_Static_assert(sizeof(struct A7_extra_packed) == 32, "");
_Static_assert(_Alignof(struct A7_extra_packed) == 1, "");
_Static_assert(sizeof(struct A7_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct A7_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A7_extra_size) == 34, "");
_Static_assert(_Alignof(struct A7_extra_size) == 1, "");
_Static_assert(sizeof(A8) == 6, "");
_Static_assert(_Alignof(A8) == 1, "");
_Static_assert(sizeof(struct A8_extra_alignment) == 7, "");
_Static_assert(_Alignof(struct A8_extra_alignment) == 1, "");
_Static_assert(sizeof(struct A8_extra_packed) == 6, "");
_Static_assert(_Alignof(struct A8_extra_packed) == 1, "");
_Static_assert(sizeof(struct A8_extra_required_alignment) == 7, "");
_Static_assert(_Alignof(struct A8_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A8_extra_size) == 8, "");
_Static_assert(_Alignof(struct A8_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A8,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A8,j) == 39, "");
#endif
_Static_assert(sizeof(A9) == 9, "");
_Static_assert(_Alignof(A9) == 1, "");
_Static_assert(sizeof(struct A9_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct A9_extra_alignment) == 1, "");
_Static_assert(sizeof(struct A9_extra_packed) == 9, "");
_Static_assert(_Alignof(struct A9_extra_packed) == 1, "");
_Static_assert(sizeof(struct A9_extra_required_alignment) == 10, "");
_Static_assert(_Alignof(struct A9_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A9_extra_size) == 11, "");
_Static_assert(_Alignof(struct A9_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A9,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A9,j) == 40, "");
#endif
_Static_assert(sizeof(A10) == 4, "");
_Static_assert(_Alignof(A10) == 16, "");
_Static_assert(sizeof(struct A10_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct A10_extra_alignment) == 16, "");
_Static_assert(sizeof(struct A10_extra_packed) == 4, "");
_Static_assert(_Alignof(struct A10_extra_packed) == 1, "");
_Static_assert(sizeof(struct A10_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct A10_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A10_extra_size) == 6, "");
_Static_assert(_Alignof(struct A10_extra_size) == 1, "");
_Static_assert(sizeof(A11) == 6, "");
_Static_assert(_Alignof(A11) == 1, "");
_Static_assert(sizeof(struct A11_extra_alignment) == 7, "");
_Static_assert(_Alignof(struct A11_extra_alignment) == 1, "");
_Static_assert(sizeof(struct A11_extra_packed) == 6, "");
_Static_assert(_Alignof(struct A11_extra_packed) == 1, "");
_Static_assert(sizeof(struct A11_extra_required_alignment) == 7, "");
_Static_assert(_Alignof(struct A11_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A11_extra_size) == 8, "");
_Static_assert(_Alignof(struct A11_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A11,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A11,j) == 39, "");
#endif
_Static_assert(sizeof(A12) == 32, "");
_Static_assert(_Alignof(A12) == 16, "");
_Static_assert(sizeof(struct A12_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct A12_extra_alignment) == 16, "");
_Static_assert(sizeof(struct A12_extra_packed) == 32, "");
_Static_assert(_Alignof(struct A12_extra_packed) == 1, "");
_Static_assert(sizeof(struct A12_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct A12_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A12_extra_size) == 34, "");
_Static_assert(_Alignof(struct A12_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A12,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A12,j) == 128, "");
#endif
_Static_assert(sizeof(A13) == 32, "");
_Static_assert(_Alignof(A13) == 16, "");
_Static_assert(sizeof(struct A13_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct A13_extra_alignment) == 16, "");
_Static_assert(sizeof(struct A13_extra_packed) == 32, "");
_Static_assert(_Alignof(struct A13_extra_packed) == 1, "");
_Static_assert(sizeof(struct A13_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct A13_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A13_extra_size) == 34, "");
_Static_assert(_Alignof(struct A13_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A13,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A13,j) == 128, "");
_Static_assert(__builtin_bitoffsetof(A13,d) == 136, "");
#endif
// MAPPING|EIGHT|hexagon-generic-linux-musl:Clang|mipsel-mips32-other-none:Clang|powerpc-ppc-netbsd-gnu:Clang|riscv32-baseline_rv32-other-eabi:Clang|wasm32-generic-emscripten-musl:Clang|wasm32-generic-other-musl:Clang|wasm32-generic-wasi-musl:Clang|END
// repr targets HexagonUnknownLinuxMusl|Some("hexagon-generic-linux-musl") MipselSonyPsp|None MipselUnknownNone|Some("mipsel-mips32-other-none") PowerpcUnknownLinuxGnuspe|None PowerpcUnknownNetbsd|Some("powerpc-ppc-netbsd-gnu") Riscv32|Some("riscv32-baseline_rv32-other-eabi") Wasm32UnknownEmscripten|Some("wasm32-generic-emscripten-musl") Wasm32UnknownUnknown|Some("wasm32-generic-other-musl") Wasm32Wasi|Some("wasm32-generic-wasi-musl") 
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
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A,d) == 0, "");
#endif
_Static_assert(sizeof(A_) == 5, "");
_Static_assert(_Alignof(A_) == 1, "");
_Static_assert(sizeof(struct A__extra_alignment) == 6, "");
_Static_assert(_Alignof(struct A__extra_alignment) == 1, "");
_Static_assert(sizeof(struct A__extra_packed) == 5, "");
_Static_assert(_Alignof(struct A__extra_packed) == 1, "");
_Static_assert(sizeof(struct A__extra_required_alignment) == 6, "");
_Static_assert(_Alignof(struct A__extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A__extra_size) == 7, "");
_Static_assert(_Alignof(struct A__extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_,d) == 32, "");
#endif
_Static_assert(sizeof(B) == 1, "");
_Static_assert(_Alignof(B) == 1, "");
_Static_assert(sizeof(struct B_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct B_extra_alignment) == 1, "");
_Static_assert(sizeof(struct B_extra_packed) == 1, "");
_Static_assert(_Alignof(struct B_extra_packed) == 1, "");
_Static_assert(sizeof(struct B_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct B_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B_extra_size) == 3, "");
_Static_assert(_Alignof(struct B_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B,d) == 0, "");
#endif
_Static_assert(sizeof(B_) == 9, "");
_Static_assert(_Alignof(B_) == 1, "");
_Static_assert(sizeof(struct B__extra_alignment) == 10, "");
_Static_assert(_Alignof(struct B__extra_alignment) == 1, "");
_Static_assert(sizeof(struct B__extra_packed) == 9, "");
_Static_assert(_Alignof(struct B__extra_packed) == 1, "");
_Static_assert(sizeof(struct B__extra_required_alignment) == 10, "");
_Static_assert(_Alignof(struct B__extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B__extra_size) == 11, "");
_Static_assert(_Alignof(struct B__extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B_,d) == 64, "");
#endif
_Static_assert(sizeof(C) == 1, "");
_Static_assert(_Alignof(C) == 1, "");
_Static_assert(sizeof(struct C_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct C_extra_alignment) == 1, "");
_Static_assert(sizeof(struct C_extra_packed) == 1, "");
_Static_assert(_Alignof(struct C_extra_packed) == 1, "");
_Static_assert(sizeof(struct C_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct C_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct C_extra_size) == 3, "");
_Static_assert(_Alignof(struct C_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(C,d) == 0, "");
#endif
_Static_assert(sizeof(C_) == 9, "");
_Static_assert(_Alignof(C_) == 1, "");
_Static_assert(sizeof(struct C__extra_alignment) == 10, "");
_Static_assert(_Alignof(struct C__extra_alignment) == 1, "");
_Static_assert(sizeof(struct C__extra_packed) == 9, "");
_Static_assert(_Alignof(struct C__extra_packed) == 1, "");
_Static_assert(sizeof(struct C__extra_required_alignment) == 10, "");
_Static_assert(_Alignof(struct C__extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct C__extra_size) == 11, "");
_Static_assert(_Alignof(struct C__extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(C_,d) == 64, "");
#endif
_Static_assert(sizeof(D) == 24, "");
_Static_assert(_Alignof(D) == 8, "");
_Static_assert(sizeof(struct D_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct D_extra_alignment) == 8, "");
_Static_assert(sizeof(struct D_extra_packed) == 24, "");
_Static_assert(_Alignof(struct D_extra_packed) == 1, "");
_Static_assert(sizeof(struct D_extra_required_alignment) == 25, "");
_Static_assert(_Alignof(struct D_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct D_extra_size) == 26, "");
_Static_assert(_Alignof(struct D_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(D,d) == 64, "");
_Static_assert(__builtin_bitoffsetof(D,e) == 128, "");
#endif
_Static_assert(sizeof(F) == 32, "");
_Static_assert(_Alignof(F) == 16, "");
_Static_assert(sizeof(struct F_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct F_extra_alignment) == 16, "");
_Static_assert(sizeof(struct F_extra_packed) == 32, "");
_Static_assert(_Alignof(struct F_extra_packed) == 1, "");
_Static_assert(sizeof(struct F_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct F_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct F_extra_size) == 34, "");
_Static_assert(_Alignof(struct F_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(F,d) == 128, "");
_Static_assert(__builtin_bitoffsetof(F,e) == 192, "");
#endif
_Static_assert(sizeof(G) == 12, "");
_Static_assert(_Alignof(G) == 2, "");
_Static_assert(sizeof(struct G_extra_alignment) == 14, "");
_Static_assert(_Alignof(struct G_extra_alignment) == 2, "");
_Static_assert(sizeof(struct G_extra_packed) == 12, "");
_Static_assert(_Alignof(struct G_extra_packed) == 1, "");
_Static_assert(sizeof(struct G_extra_required_alignment) == 13, "");
_Static_assert(_Alignof(struct G_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct G_extra_size) == 14, "");
_Static_assert(_Alignof(struct G_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(G,d) == 16, "");
_Static_assert(__builtin_bitoffsetof(G,e) == 80, "");
#endif
_Static_assert(sizeof(H) == 12, "");
_Static_assert(_Alignof(H) == 2, "");
_Static_assert(sizeof(struct H_extra_alignment) == 14, "");
_Static_assert(_Alignof(struct H_extra_alignment) == 2, "");
_Static_assert(sizeof(struct H_extra_packed) == 12, "");
_Static_assert(_Alignof(struct H_extra_packed) == 1, "");
_Static_assert(sizeof(struct H_extra_required_alignment) == 13, "");
_Static_assert(_Alignof(struct H_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct H_extra_size) == 14, "");
_Static_assert(_Alignof(struct H_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(H,d) == 16, "");
_Static_assert(__builtin_bitoffsetof(H,e) == 80, "");
#endif
_Static_assert(sizeof(I) == 10, "");
_Static_assert(_Alignof(I) == 1, "");
_Static_assert(sizeof(struct I_extra_alignment) == 11, "");
_Static_assert(_Alignof(struct I_extra_alignment) == 1, "");
_Static_assert(sizeof(struct I_extra_packed) == 10, "");
_Static_assert(_Alignof(struct I_extra_packed) == 1, "");
_Static_assert(sizeof(struct I_extra_required_alignment) == 11, "");
_Static_assert(_Alignof(struct I_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct I_extra_size) == 12, "");
_Static_assert(_Alignof(struct I_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(I,d) == 8, "");
_Static_assert(__builtin_bitoffsetof(I,e) == 72, "");
#endif
_Static_assert(sizeof(J) == 12, "");
_Static_assert(_Alignof(J) == 2, "");
_Static_assert(sizeof(struct J_extra_alignment) == 14, "");
_Static_assert(_Alignof(struct J_extra_alignment) == 2, "");
_Static_assert(sizeof(struct J_extra_packed) == 12, "");
_Static_assert(_Alignof(struct J_extra_packed) == 1, "");
_Static_assert(sizeof(struct J_extra_required_alignment) == 13, "");
_Static_assert(_Alignof(struct J_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct J_extra_size) == 14, "");
_Static_assert(_Alignof(struct J_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(J,d) == 16, "");
_Static_assert(__builtin_bitoffsetof(J,e) == 80, "");
#endif
_Static_assert(sizeof(K) == 8, "");
_Static_assert(_Alignof(K) == 8, "");
_Static_assert(sizeof(struct K_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct K_extra_alignment) == 8, "");
_Static_assert(sizeof(struct K_extra_packed) == 8, "");
_Static_assert(_Alignof(struct K_extra_packed) == 1, "");
_Static_assert(sizeof(struct K_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct K_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct K_extra_size) == 10, "");
_Static_assert(_Alignof(struct K_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(K,d) == 8, "");
_Static_assert(__builtin_bitoffsetof(K,e) == 16, "");
#endif
_Static_assert(sizeof(L) == 32, "");
_Static_assert(_Alignof(L) == 16, "");
_Static_assert(sizeof(struct L_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct L_extra_alignment) == 16, "");
_Static_assert(sizeof(struct L_extra_packed) == 32, "");
_Static_assert(_Alignof(struct L_extra_packed) == 1, "");
_Static_assert(sizeof(struct L_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct L_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct L_extra_size) == 34, "");
_Static_assert(_Alignof(struct L_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(L,d) == 128, "");
_Static_assert(__builtin_bitoffsetof(L,e) == 136, "");
#endif
_Static_assert(sizeof(M) == 4, "");
_Static_assert(_Alignof(M) == 2, "");
_Static_assert(sizeof(struct M_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct M_extra_alignment) == 2, "");
_Static_assert(sizeof(struct M_extra_packed) == 4, "");
_Static_assert(_Alignof(struct M_extra_packed) == 1, "");
_Static_assert(sizeof(struct M_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct M_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct M_extra_size) == 6, "");
_Static_assert(_Alignof(struct M_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(M,d) == 16, "");
_Static_assert(__builtin_bitoffsetof(M,e) == 24, "");
#endif
_Static_assert(sizeof(N) == 4, "");
_Static_assert(_Alignof(N) == 2, "");
_Static_assert(sizeof(struct N_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct N_extra_alignment) == 2, "");
_Static_assert(sizeof(struct N_extra_packed) == 4, "");
_Static_assert(_Alignof(struct N_extra_packed) == 1, "");
_Static_assert(sizeof(struct N_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct N_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct N_extra_size) == 6, "");
_Static_assert(_Alignof(struct N_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(N,d) == 8, "");
_Static_assert(__builtin_bitoffsetof(N,e) == 16, "");
#endif
_Static_assert(sizeof(O) == 3, "");
_Static_assert(_Alignof(O) == 1, "");
_Static_assert(sizeof(struct O_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct O_extra_alignment) == 1, "");
_Static_assert(sizeof(struct O_extra_packed) == 3, "");
_Static_assert(_Alignof(struct O_extra_packed) == 1, "");
_Static_assert(sizeof(struct O_extra_required_alignment) == 4, "");
_Static_assert(_Alignof(struct O_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct O_extra_size) == 5, "");
_Static_assert(_Alignof(struct O_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(O,d) == 8, "");
_Static_assert(__builtin_bitoffsetof(O,e) == 16, "");
#endif
_Static_assert(sizeof(P) == 4, "");
_Static_assert(_Alignof(P) == 2, "");
_Static_assert(sizeof(struct P_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct P_extra_alignment) == 2, "");
_Static_assert(sizeof(struct P_extra_packed) == 4, "");
_Static_assert(_Alignof(struct P_extra_packed) == 1, "");
_Static_assert(sizeof(struct P_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct P_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct P_extra_size) == 6, "");
_Static_assert(_Alignof(struct P_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(P,d) == 8, "");
_Static_assert(__builtin_bitoffsetof(P,e) == 16, "");
#endif
_Static_assert(sizeof(Q) == 8, "");
_Static_assert(_Alignof(Q) == 8, "");
_Static_assert(sizeof(struct Q_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct Q_extra_alignment) == 8, "");
_Static_assert(sizeof(struct Q_extra_packed) == 8, "");
_Static_assert(_Alignof(struct Q_extra_packed) == 1, "");
_Static_assert(sizeof(struct Q_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct Q_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct Q_extra_size) == 10, "");
_Static_assert(_Alignof(struct Q_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(Q,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(Q,d) == 9, "");
_Static_assert(__builtin_bitoffsetof(Q,e) == 16, "");
#endif
_Static_assert(sizeof(R) == 17, "");
_Static_assert(_Alignof(R) == 1, "");
_Static_assert(sizeof(struct R_extra_alignment) == 18, "");
_Static_assert(_Alignof(struct R_extra_alignment) == 1, "");
_Static_assert(sizeof(struct R_extra_packed) == 17, "");
_Static_assert(_Alignof(struct R_extra_packed) == 1, "");
_Static_assert(sizeof(struct R_extra_required_alignment) == 18, "");
_Static_assert(_Alignof(struct R_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct R_extra_size) == 19, "");
_Static_assert(_Alignof(struct R_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(R,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(R,e) == 128, "");
#endif
_Static_assert(sizeof(S) == 9, "");
_Static_assert(_Alignof(S) == 1, "");
_Static_assert(sizeof(struct S_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct S_extra_alignment) == 1, "");
_Static_assert(sizeof(struct S_extra_packed) == 9, "");
_Static_assert(_Alignof(struct S_extra_packed) == 1, "");
_Static_assert(sizeof(struct S_extra_required_alignment) == 10, "");
_Static_assert(_Alignof(struct S_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct S_extra_size) == 11, "");
_Static_assert(_Alignof(struct S_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(S,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(S,e) == 64, "");
#endif
_Static_assert(sizeof(T) == 9, "");
_Static_assert(_Alignof(T) == 1, "");
_Static_assert(sizeof(struct T_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct T_extra_alignment) == 1, "");
_Static_assert(sizeof(struct T_extra_packed) == 9, "");
_Static_assert(_Alignof(struct T_extra_packed) == 1, "");
_Static_assert(sizeof(struct T_extra_required_alignment) == 10, "");
_Static_assert(_Alignof(struct T_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct T_extra_size) == 11, "");
_Static_assert(_Alignof(struct T_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(T,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(T,e) == 64, "");
#endif
_Static_assert(sizeof(U) == 9, "");
_Static_assert(_Alignof(U) == 1, "");
_Static_assert(sizeof(struct U_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct U_extra_alignment) == 1, "");
_Static_assert(sizeof(struct U_extra_packed) == 9, "");
_Static_assert(_Alignof(struct U_extra_packed) == 1, "");
_Static_assert(sizeof(struct U_extra_required_alignment) == 10, "");
_Static_assert(_Alignof(struct U_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct U_extra_size) == 11, "");
_Static_assert(_Alignof(struct U_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(U,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(U,e) == 64, "");
#endif
_Static_assert(sizeof(V) == 9, "");
_Static_assert(_Alignof(V) == 1, "");
_Static_assert(sizeof(struct V_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct V_extra_alignment) == 1, "");
_Static_assert(sizeof(struct V_extra_packed) == 9, "");
_Static_assert(_Alignof(struct V_extra_packed) == 1, "");
_Static_assert(sizeof(struct V_extra_required_alignment) == 10, "");
_Static_assert(_Alignof(struct V_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct V_extra_size) == 11, "");
_Static_assert(_Alignof(struct V_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(V,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(V,e) == 64, "");
#endif
_Static_assert(sizeof(W) == 17, "");
_Static_assert(_Alignof(W) == 1, "");
_Static_assert(sizeof(struct W_extra_alignment) == 18, "");
_Static_assert(_Alignof(struct W_extra_alignment) == 1, "");
_Static_assert(sizeof(struct W_extra_packed) == 17, "");
_Static_assert(_Alignof(struct W_extra_packed) == 1, "");
_Static_assert(sizeof(struct W_extra_required_alignment) == 18, "");
_Static_assert(_Alignof(struct W_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct W_extra_size) == 19, "");
_Static_assert(_Alignof(struct W_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(W,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(W,e) == 128, "");
#endif
_Static_assert(sizeof(W_) == 17, "");
_Static_assert(_Alignof(W_) == 1, "");
_Static_assert(sizeof(struct W__extra_alignment) == 18, "");
_Static_assert(_Alignof(struct W__extra_alignment) == 1, "");
_Static_assert(sizeof(struct W__extra_packed) == 17, "");
_Static_assert(_Alignof(struct W__extra_packed) == 1, "");
_Static_assert(sizeof(struct W__extra_required_alignment) == 18, "");
_Static_assert(_Alignof(struct W__extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct W__extra_size) == 19, "");
_Static_assert(_Alignof(struct W__extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(W_,e) == 128, "");
#endif
_Static_assert(sizeof(X) == 17, "");
_Static_assert(_Alignof(X) == 1, "");
_Static_assert(sizeof(struct X_extra_alignment) == 18, "");
_Static_assert(_Alignof(struct X_extra_alignment) == 1, "");
_Static_assert(sizeof(struct X_extra_packed) == 17, "");
_Static_assert(_Alignof(struct X_extra_packed) == 1, "");
_Static_assert(sizeof(struct X_extra_required_alignment) == 18, "");
_Static_assert(_Alignof(struct X_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct X_extra_size) == 19, "");
_Static_assert(_Alignof(struct X_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(X,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(X,e) == 128, "");
#endif
_Static_assert(sizeof(A2) == 1, "");
_Static_assert(_Alignof(A2) == 1, "");
_Static_assert(sizeof(struct A2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct A2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct A2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct A2_extra_packed) == 1, "");
_Static_assert(sizeof(struct A2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct A2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A2_extra_size) == 3, "");
_Static_assert(_Alignof(struct A2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A2,d) == 0, "");
#endif
_Static_assert(sizeof(A_2) == 1, "");
_Static_assert(_Alignof(A_2) == 1, "");
_Static_assert(sizeof(struct A_2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct A_2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct A_2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct A_2_extra_packed) == 1, "");
_Static_assert(sizeof(struct A_2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct A_2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A_2_extra_size) == 3, "");
_Static_assert(_Alignof(struct A_2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_2,d) == 0, "");
#endif
_Static_assert(sizeof(B2) == 1, "");
_Static_assert(_Alignof(B2) == 1, "");
_Static_assert(sizeof(struct B2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct B2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct B2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct B2_extra_packed) == 1, "");
_Static_assert(sizeof(struct B2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct B2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B2_extra_size) == 3, "");
_Static_assert(_Alignof(struct B2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B2,d) == 0, "");
#endif
_Static_assert(sizeof(B_2) == 1, "");
_Static_assert(_Alignof(B_2) == 1, "");
_Static_assert(sizeof(struct B_2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct B_2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct B_2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct B_2_extra_packed) == 1, "");
_Static_assert(sizeof(struct B_2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct B_2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B_2_extra_size) == 3, "");
_Static_assert(_Alignof(struct B_2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B_2,d) == 0, "");
#endif
_Static_assert(sizeof(C2) == 1, "");
_Static_assert(_Alignof(C2) == 1, "");
_Static_assert(sizeof(struct C2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct C2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct C2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct C2_extra_packed) == 1, "");
_Static_assert(sizeof(struct C2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct C2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct C2_extra_size) == 3, "");
_Static_assert(_Alignof(struct C2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(C2,d) == 0, "");
#endif
_Static_assert(sizeof(C22) == 1, "");
_Static_assert(_Alignof(C22) == 1, "");
_Static_assert(sizeof(struct C22_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct C22_extra_alignment) == 1, "");
_Static_assert(sizeof(struct C22_extra_packed) == 1, "");
_Static_assert(_Alignof(struct C22_extra_packed) == 1, "");
_Static_assert(sizeof(struct C22_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct C22_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct C22_extra_size) == 3, "");
_Static_assert(_Alignof(struct C22_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(C22,d) == 0, "");
#endif
_Static_assert(sizeof(D2) == 8, "");
_Static_assert(_Alignof(D2) == 8, "");
_Static_assert(sizeof(struct D2_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct D2_extra_alignment) == 8, "");
_Static_assert(sizeof(struct D2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct D2_extra_packed) == 1, "");
_Static_assert(sizeof(struct D2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct D2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct D2_extra_size) == 10, "");
_Static_assert(_Alignof(struct D2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(D2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(D2,e) == 0, "");
#endif
_Static_assert(sizeof(F2) == 16, "");
_Static_assert(_Alignof(F2) == 16, "");
_Static_assert(sizeof(struct F2_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct F2_extra_alignment) == 16, "");
_Static_assert(sizeof(struct F2_extra_packed) == 16, "");
_Static_assert(_Alignof(struct F2_extra_packed) == 1, "");
_Static_assert(sizeof(struct F2_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct F2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct F2_extra_size) == 18, "");
_Static_assert(_Alignof(struct F2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(F2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(F2,e) == 0, "");
#endif
_Static_assert(sizeof(G2) == 8, "");
_Static_assert(_Alignof(G2) == 2, "");
_Static_assert(sizeof(struct G2_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct G2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct G2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct G2_extra_packed) == 1, "");
_Static_assert(sizeof(struct G2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct G2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct G2_extra_size) == 10, "");
_Static_assert(_Alignof(struct G2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(G2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(G2,e) == 0, "");
#endif
_Static_assert(sizeof(H2) == 8, "");
_Static_assert(_Alignof(H2) == 2, "");
_Static_assert(sizeof(struct H2_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct H2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct H2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct H2_extra_packed) == 1, "");
_Static_assert(sizeof(struct H2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct H2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct H2_extra_size) == 10, "");
_Static_assert(_Alignof(struct H2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(H2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(H2,e) == 0, "");
#endif
_Static_assert(sizeof(I2) == 8, "");
_Static_assert(_Alignof(I2) == 1, "");
_Static_assert(sizeof(struct I2_extra_alignment) == 9, "");
_Static_assert(_Alignof(struct I2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct I2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct I2_extra_packed) == 1, "");
_Static_assert(sizeof(struct I2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct I2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct I2_extra_size) == 10, "");
_Static_assert(_Alignof(struct I2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(I2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(I2,e) == 0, "");
#endif
_Static_assert(sizeof(J2) == 8, "");
_Static_assert(_Alignof(J2) == 2, "");
_Static_assert(sizeof(struct J2_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct J2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct J2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct J2_extra_packed) == 1, "");
_Static_assert(sizeof(struct J2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct J2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct J2_extra_size) == 10, "");
_Static_assert(_Alignof(struct J2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(J2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(J2,e) == 0, "");
#endif
_Static_assert(sizeof(K2) == 8, "");
_Static_assert(_Alignof(K2) == 8, "");
_Static_assert(sizeof(struct K2_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct K2_extra_alignment) == 8, "");
_Static_assert(sizeof(struct K2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct K2_extra_packed) == 1, "");
_Static_assert(sizeof(struct K2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct K2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct K2_extra_size) == 10, "");
_Static_assert(_Alignof(struct K2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(K2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(K2,e) == 0, "");
#endif
_Static_assert(sizeof(L2) == 16, "");
_Static_assert(_Alignof(L2) == 16, "");
_Static_assert(sizeof(struct L2_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct L2_extra_alignment) == 16, "");
_Static_assert(sizeof(struct L2_extra_packed) == 16, "");
_Static_assert(_Alignof(struct L2_extra_packed) == 1, "");
_Static_assert(sizeof(struct L2_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct L2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct L2_extra_size) == 18, "");
_Static_assert(_Alignof(struct L2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(L2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(L2,e) == 0, "");
#endif
_Static_assert(sizeof(M2) == 2, "");
_Static_assert(_Alignof(M2) == 2, "");
_Static_assert(sizeof(struct M2_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct M2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct M2_extra_packed) == 2, "");
_Static_assert(_Alignof(struct M2_extra_packed) == 1, "");
_Static_assert(sizeof(struct M2_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct M2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct M2_extra_size) == 4, "");
_Static_assert(_Alignof(struct M2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(M2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(M2,e) == 0, "");
#endif
_Static_assert(sizeof(N2) == 2, "");
_Static_assert(_Alignof(N2) == 2, "");
_Static_assert(sizeof(struct N2_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct N2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct N2_extra_packed) == 2, "");
_Static_assert(_Alignof(struct N2_extra_packed) == 1, "");
_Static_assert(sizeof(struct N2_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct N2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct N2_extra_size) == 4, "");
_Static_assert(_Alignof(struct N2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(N2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(N2,e) == 0, "");
#endif
_Static_assert(sizeof(O2) == 1, "");
_Static_assert(_Alignof(O2) == 1, "");
_Static_assert(sizeof(struct O2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct O2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct O2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct O2_extra_packed) == 1, "");
_Static_assert(sizeof(struct O2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct O2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct O2_extra_size) == 3, "");
_Static_assert(_Alignof(struct O2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(O2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(O2,e) == 0, "");
#endif
_Static_assert(sizeof(P2) == 2, "");
_Static_assert(_Alignof(P2) == 2, "");
_Static_assert(sizeof(struct P2_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct P2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct P2_extra_packed) == 2, "");
_Static_assert(_Alignof(struct P2_extra_packed) == 1, "");
_Static_assert(sizeof(struct P2_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct P2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct P2_extra_size) == 4, "");
_Static_assert(_Alignof(struct P2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(P2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(P2,e) == 0, "");
#endif
_Static_assert(sizeof(Q2) == 8, "");
_Static_assert(_Alignof(Q2) == 8, "");
_Static_assert(sizeof(struct Q2_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct Q2_extra_alignment) == 8, "");
_Static_assert(sizeof(struct Q2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct Q2_extra_packed) == 1, "");
_Static_assert(sizeof(struct Q2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct Q2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct Q2_extra_size) == 10, "");
_Static_assert(_Alignof(struct Q2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(Q2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(Q2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(Q2,e) == 0, "");
#endif
_Static_assert(sizeof(R2) == 1, "");
_Static_assert(_Alignof(R2) == 1, "");
_Static_assert(sizeof(struct R2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct R2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct R2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct R2_extra_packed) == 1, "");
_Static_assert(sizeof(struct R2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct R2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct R2_extra_size) == 3, "");
_Static_assert(_Alignof(struct R2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(R2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(R2,e) == 0, "");
#endif
_Static_assert(sizeof(S2) == 1, "");
_Static_assert(_Alignof(S2) == 1, "");
_Static_assert(sizeof(struct S2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct S2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct S2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct S2_extra_packed) == 1, "");
_Static_assert(sizeof(struct S2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct S2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct S2_extra_size) == 3, "");
_Static_assert(_Alignof(struct S2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(S2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(S2,e) == 0, "");
#endif
_Static_assert(sizeof(T2) == 1, "");
_Static_assert(_Alignof(T2) == 1, "");
_Static_assert(sizeof(struct T2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct T2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct T2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct T2_extra_packed) == 1, "");
_Static_assert(sizeof(struct T2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct T2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct T2_extra_size) == 3, "");
_Static_assert(_Alignof(struct T2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(T2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(T2,e) == 0, "");
#endif
_Static_assert(sizeof(U2) == 1, "");
_Static_assert(_Alignof(U2) == 1, "");
_Static_assert(sizeof(struct U2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct U2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct U2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct U2_extra_packed) == 1, "");
_Static_assert(sizeof(struct U2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct U2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct U2_extra_size) == 3, "");
_Static_assert(_Alignof(struct U2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(U2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(U2,e) == 0, "");
#endif
_Static_assert(sizeof(V2) == 1, "");
_Static_assert(_Alignof(V2) == 1, "");
_Static_assert(sizeof(struct V2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct V2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct V2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct V2_extra_packed) == 1, "");
_Static_assert(sizeof(struct V2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct V2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct V2_extra_size) == 3, "");
_Static_assert(_Alignof(struct V2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(V2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(V2,e) == 0, "");
#endif
_Static_assert(sizeof(W2) == 1, "");
_Static_assert(_Alignof(W2) == 1, "");
_Static_assert(sizeof(struct W2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct W2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct W2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct W2_extra_packed) == 1, "");
_Static_assert(sizeof(struct W2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct W2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct W2_extra_size) == 3, "");
_Static_assert(_Alignof(struct W2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(W2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(W2,e) == 0, "");
#endif
_Static_assert(sizeof(W_2) == 1, "");
_Static_assert(_Alignof(W_2) == 1, "");
_Static_assert(sizeof(struct W_2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct W_2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct W_2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct W_2_extra_packed) == 1, "");
_Static_assert(sizeof(struct W_2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct W_2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct W_2_extra_size) == 3, "");
_Static_assert(_Alignof(struct W_2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(W_2,e) == 0, "");
#endif
_Static_assert(sizeof(X2) == 1, "");
_Static_assert(_Alignof(X2) == 1, "");
_Static_assert(sizeof(struct X2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct X2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct X2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct X2_extra_packed) == 1, "");
_Static_assert(sizeof(struct X2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct X2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct X2_extra_size) == 3, "");
_Static_assert(_Alignof(struct X2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(X2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(X2,e) == 0, "");
#endif
_Static_assert(sizeof(Y) == 9, "");
_Static_assert(_Alignof(Y) == 1, "");
_Static_assert(sizeof(struct Y_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct Y_extra_alignment) == 1, "");
_Static_assert(sizeof(struct Y_extra_packed) == 9, "");
_Static_assert(_Alignof(struct Y_extra_packed) == 1, "");
_Static_assert(sizeof(struct Y_extra_required_alignment) == 10, "");
_Static_assert(_Alignof(struct Y_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct Y_extra_size) == 11, "");
_Static_assert(_Alignof(struct Y_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(Y,d) == 64, "");
#endif
_Static_assert(sizeof(Y2) == 1, "");
_Static_assert(_Alignof(Y2) == 1, "");
_Static_assert(sizeof(struct Y2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct Y2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct Y2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct Y2_extra_packed) == 1, "");
_Static_assert(sizeof(struct Y2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct Y2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct Y2_extra_size) == 3, "");
_Static_assert(_Alignof(struct Y2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(Y2,d) == 0, "");
#endif
_Static_assert(sizeof(A3) == 33, "");
_Static_assert(_Alignof(A3) == 1, "");
_Static_assert(sizeof(struct A3_extra_alignment) == 34, "");
_Static_assert(_Alignof(struct A3_extra_alignment) == 1, "");
_Static_assert(sizeof(struct A3_extra_packed) == 33, "");
_Static_assert(_Alignof(struct A3_extra_packed) == 1, "");
_Static_assert(sizeof(struct A3_extra_required_alignment) == 34, "");
_Static_assert(_Alignof(struct A3_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A3_extra_size) == 35, "");
_Static_assert(_Alignof(struct A3_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A3,d) == 256, "");
#endif
_Static_assert(sizeof(A4) == 1, "");
_Static_assert(_Alignof(A4) == 32, "");
_Static_assert(sizeof(struct A4_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct A4_extra_alignment) == 32, "");
_Static_assert(sizeof(struct A4_extra_packed) == 1, "");
_Static_assert(_Alignof(struct A4_extra_packed) == 1, "");
_Static_assert(sizeof(struct A4_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct A4_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A4_extra_size) == 3, "");
_Static_assert(_Alignof(struct A4_extra_size) == 1, "");
_Static_assert(sizeof(A5) == 33, "");
_Static_assert(_Alignof(A5) == 1, "");
_Static_assert(sizeof(struct A5_extra_alignment) == 34, "");
_Static_assert(_Alignof(struct A5_extra_alignment) == 1, "");
_Static_assert(sizeof(struct A5_extra_packed) == 33, "");
_Static_assert(_Alignof(struct A5_extra_packed) == 1, "");
_Static_assert(sizeof(struct A5_extra_required_alignment) == 34, "");
_Static_assert(_Alignof(struct A5_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A5_extra_size) == 35, "");
_Static_assert(_Alignof(struct A5_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A5,d) == 256, "");
#endif
_Static_assert(sizeof(A7) == 32, "");
_Static_assert(_Alignof(A7) == 32, "");
_Static_assert(sizeof(struct A7_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct A7_extra_alignment) == 32, "");
_Static_assert(sizeof(struct A7_extra_packed) == 32, "");
_Static_assert(_Alignof(struct A7_extra_packed) == 1, "");
_Static_assert(sizeof(struct A7_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct A7_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A7_extra_size) == 34, "");
_Static_assert(_Alignof(struct A7_extra_size) == 1, "");
_Static_assert(sizeof(A8) == 8, "");
_Static_assert(_Alignof(A8) == 4, "");
_Static_assert(sizeof(struct A8_extra_alignment) == 12, "");
_Static_assert(_Alignof(struct A8_extra_alignment) == 4, "");
_Static_assert(sizeof(struct A8_extra_packed) == 8, "");
_Static_assert(_Alignof(struct A8_extra_packed) == 1, "");
_Static_assert(sizeof(struct A8_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct A8_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A8_extra_size) == 10, "");
_Static_assert(_Alignof(struct A8_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A8,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A8,j) == 39, "");
#endif
_Static_assert(sizeof(A9) == 12, "");
_Static_assert(_Alignof(A9) == 4, "");
_Static_assert(sizeof(struct A9_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct A9_extra_alignment) == 4, "");
_Static_assert(sizeof(struct A9_extra_packed) == 12, "");
_Static_assert(_Alignof(struct A9_extra_packed) == 1, "");
_Static_assert(sizeof(struct A9_extra_required_alignment) == 13, "");
_Static_assert(_Alignof(struct A9_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A9_extra_size) == 14, "");
_Static_assert(_Alignof(struct A9_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A9,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A9,j) == 64, "");
#endif
_Static_assert(sizeof(A10) == 4, "");
_Static_assert(_Alignof(A10) == 16, "");
_Static_assert(sizeof(struct A10_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct A10_extra_alignment) == 16, "");
_Static_assert(sizeof(struct A10_extra_packed) == 4, "");
_Static_assert(_Alignof(struct A10_extra_packed) == 1, "");
_Static_assert(sizeof(struct A10_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct A10_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A10_extra_size) == 6, "");
_Static_assert(_Alignof(struct A10_extra_size) == 1, "");
_Static_assert(sizeof(A11) == 32, "");
_Static_assert(_Alignof(A11) == 16, "");
_Static_assert(sizeof(struct A11_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct A11_extra_alignment) == 16, "");
_Static_assert(sizeof(struct A11_extra_packed) == 32, "");
_Static_assert(_Alignof(struct A11_extra_packed) == 1, "");
_Static_assert(sizeof(struct A11_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct A11_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A11_extra_size) == 34, "");
_Static_assert(_Alignof(struct A11_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A11,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A11,j) == 128, "");
#endif
_Static_assert(sizeof(A12) == 32, "");
_Static_assert(_Alignof(A12) == 16, "");
_Static_assert(sizeof(struct A12_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct A12_extra_alignment) == 16, "");
_Static_assert(sizeof(struct A12_extra_packed) == 32, "");
_Static_assert(_Alignof(struct A12_extra_packed) == 1, "");
_Static_assert(sizeof(struct A12_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct A12_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A12_extra_size) == 34, "");
_Static_assert(_Alignof(struct A12_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A12,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A12,j) == 128, "");
#endif
_Static_assert(sizeof(A13) == 32, "");
_Static_assert(_Alignof(A13) == 16, "");
_Static_assert(sizeof(struct A13_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct A13_extra_alignment) == 16, "");
_Static_assert(sizeof(struct A13_extra_packed) == 32, "");
_Static_assert(_Alignof(struct A13_extra_packed) == 1, "");
_Static_assert(sizeof(struct A13_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct A13_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A13_extra_size) == 34, "");
_Static_assert(_Alignof(struct A13_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A13,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A13,j) == 128, "");
_Static_assert(__builtin_bitoffsetof(A13,d) == 136, "");
#endif
// MAPPING|NINE|x86-pentium4-ios-none:Clang|x86-i686-macos-none:Clang|x86-i686-linux-android:Clang|x86-i686-freebsd-gnu:Clang|x86-i686-haiku-gnu:Clang|x86-i686-netbsd-gnu:Clang|x86-i686-openbsd-gnu:Clang|END
// repr targets I386AppleIos|Some("x86-pentium4-ios-none") I686AppleMacosx|Some("x86-i686-macos-none") I686LinuxAndroid|Some("x86-i686-linux-android") I686UnknownFreebsd|Some("x86-i686-freebsd-gnu") I686UnknownHaiku|Some("x86-i686-haiku-gnu") I686UnknownNetbsdelf|Some("x86-i686-netbsd-gnu") I686UnknownOpenbsd|Some("x86-i686-openbsd-gnu") 
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
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A,d) == 0, "");
#endif
_Static_assert(sizeof(A_) == 5, "");
_Static_assert(_Alignof(A_) == 1, "");
_Static_assert(sizeof(struct A__extra_alignment) == 6, "");
_Static_assert(_Alignof(struct A__extra_alignment) == 1, "");
_Static_assert(sizeof(struct A__extra_packed) == 5, "");
_Static_assert(_Alignof(struct A__extra_packed) == 1, "");
_Static_assert(sizeof(struct A__extra_required_alignment) == 6, "");
_Static_assert(_Alignof(struct A__extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A__extra_size) == 7, "");
_Static_assert(_Alignof(struct A__extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_,d) == 32, "");
#endif
_Static_assert(sizeof(B) == 1, "");
_Static_assert(_Alignof(B) == 1, "");
_Static_assert(sizeof(struct B_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct B_extra_alignment) == 1, "");
_Static_assert(sizeof(struct B_extra_packed) == 1, "");
_Static_assert(_Alignof(struct B_extra_packed) == 1, "");
_Static_assert(sizeof(struct B_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct B_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B_extra_size) == 3, "");
_Static_assert(_Alignof(struct B_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B,d) == 0, "");
#endif
_Static_assert(sizeof(B_) == 5, "");
_Static_assert(_Alignof(B_) == 1, "");
_Static_assert(sizeof(struct B__extra_alignment) == 6, "");
_Static_assert(_Alignof(struct B__extra_alignment) == 1, "");
_Static_assert(sizeof(struct B__extra_packed) == 5, "");
_Static_assert(_Alignof(struct B__extra_packed) == 1, "");
_Static_assert(sizeof(struct B__extra_required_alignment) == 6, "");
_Static_assert(_Alignof(struct B__extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B__extra_size) == 7, "");
_Static_assert(_Alignof(struct B__extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B_,d) == 32, "");
#endif
_Static_assert(sizeof(C) == 1, "");
_Static_assert(_Alignof(C) == 1, "");
_Static_assert(sizeof(struct C_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct C_extra_alignment) == 1, "");
_Static_assert(sizeof(struct C_extra_packed) == 1, "");
_Static_assert(_Alignof(struct C_extra_packed) == 1, "");
_Static_assert(sizeof(struct C_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct C_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct C_extra_size) == 3, "");
_Static_assert(_Alignof(struct C_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(C,d) == 0, "");
#endif
_Static_assert(sizeof(C_) == 5, "");
_Static_assert(_Alignof(C_) == 1, "");
_Static_assert(sizeof(struct C__extra_alignment) == 6, "");
_Static_assert(_Alignof(struct C__extra_alignment) == 1, "");
_Static_assert(sizeof(struct C__extra_packed) == 5, "");
_Static_assert(_Alignof(struct C__extra_packed) == 1, "");
_Static_assert(sizeof(struct C__extra_required_alignment) == 6, "");
_Static_assert(_Alignof(struct C__extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct C__extra_size) == 7, "");
_Static_assert(_Alignof(struct C__extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(C_,d) == 32, "");
#endif
_Static_assert(sizeof(D) == 16, "");
_Static_assert(_Alignof(D) == 4, "");
_Static_assert(sizeof(struct D_extra_alignment) == 20, "");
_Static_assert(_Alignof(struct D_extra_alignment) == 4, "");
_Static_assert(sizeof(struct D_extra_packed) == 16, "");
_Static_assert(_Alignof(struct D_extra_packed) == 1, "");
_Static_assert(sizeof(struct D_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct D_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct D_extra_size) == 18, "");
_Static_assert(_Alignof(struct D_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(D,d) == 32, "");
_Static_assert(__builtin_bitoffsetof(D,e) == 96, "");
#endif
_Static_assert(sizeof(F) == 32, "");
_Static_assert(_Alignof(F) == 16, "");
_Static_assert(sizeof(struct F_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct F_extra_alignment) == 16, "");
_Static_assert(sizeof(struct F_extra_packed) == 32, "");
_Static_assert(_Alignof(struct F_extra_packed) == 1, "");
_Static_assert(sizeof(struct F_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct F_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct F_extra_size) == 34, "");
_Static_assert(_Alignof(struct F_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(F,d) == 128, "");
_Static_assert(__builtin_bitoffsetof(F,e) == 192, "");
#endif
_Static_assert(sizeof(G) == 12, "");
_Static_assert(_Alignof(G) == 2, "");
_Static_assert(sizeof(struct G_extra_alignment) == 14, "");
_Static_assert(_Alignof(struct G_extra_alignment) == 2, "");
_Static_assert(sizeof(struct G_extra_packed) == 12, "");
_Static_assert(_Alignof(struct G_extra_packed) == 1, "");
_Static_assert(sizeof(struct G_extra_required_alignment) == 13, "");
_Static_assert(_Alignof(struct G_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct G_extra_size) == 14, "");
_Static_assert(_Alignof(struct G_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(G,d) == 16, "");
_Static_assert(__builtin_bitoffsetof(G,e) == 80, "");
#endif
_Static_assert(sizeof(H) == 12, "");
_Static_assert(_Alignof(H) == 2, "");
_Static_assert(sizeof(struct H_extra_alignment) == 14, "");
_Static_assert(_Alignof(struct H_extra_alignment) == 2, "");
_Static_assert(sizeof(struct H_extra_packed) == 12, "");
_Static_assert(_Alignof(struct H_extra_packed) == 1, "");
_Static_assert(sizeof(struct H_extra_required_alignment) == 13, "");
_Static_assert(_Alignof(struct H_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct H_extra_size) == 14, "");
_Static_assert(_Alignof(struct H_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(H,d) == 16, "");
_Static_assert(__builtin_bitoffsetof(H,e) == 80, "");
#endif
_Static_assert(sizeof(I) == 10, "");
_Static_assert(_Alignof(I) == 1, "");
_Static_assert(sizeof(struct I_extra_alignment) == 11, "");
_Static_assert(_Alignof(struct I_extra_alignment) == 1, "");
_Static_assert(sizeof(struct I_extra_packed) == 10, "");
_Static_assert(_Alignof(struct I_extra_packed) == 1, "");
_Static_assert(sizeof(struct I_extra_required_alignment) == 11, "");
_Static_assert(_Alignof(struct I_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct I_extra_size) == 12, "");
_Static_assert(_Alignof(struct I_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(I,d) == 8, "");
_Static_assert(__builtin_bitoffsetof(I,e) == 72, "");
#endif
_Static_assert(sizeof(J) == 12, "");
_Static_assert(_Alignof(J) == 2, "");
_Static_assert(sizeof(struct J_extra_alignment) == 14, "");
_Static_assert(_Alignof(struct J_extra_alignment) == 2, "");
_Static_assert(sizeof(struct J_extra_packed) == 12, "");
_Static_assert(_Alignof(struct J_extra_packed) == 1, "");
_Static_assert(sizeof(struct J_extra_required_alignment) == 13, "");
_Static_assert(_Alignof(struct J_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct J_extra_size) == 14, "");
_Static_assert(_Alignof(struct J_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(J,d) == 16, "");
_Static_assert(__builtin_bitoffsetof(J,e) == 80, "");
#endif
_Static_assert(sizeof(K) == 4, "");
_Static_assert(_Alignof(K) == 4, "");
_Static_assert(sizeof(struct K_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct K_extra_alignment) == 4, "");
_Static_assert(sizeof(struct K_extra_packed) == 4, "");
_Static_assert(_Alignof(struct K_extra_packed) == 1, "");
_Static_assert(sizeof(struct K_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct K_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct K_extra_size) == 6, "");
_Static_assert(_Alignof(struct K_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(K,d) == 8, "");
_Static_assert(__builtin_bitoffsetof(K,e) == 16, "");
#endif
_Static_assert(sizeof(L) == 32, "");
_Static_assert(_Alignof(L) == 16, "");
_Static_assert(sizeof(struct L_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct L_extra_alignment) == 16, "");
_Static_assert(sizeof(struct L_extra_packed) == 32, "");
_Static_assert(_Alignof(struct L_extra_packed) == 1, "");
_Static_assert(sizeof(struct L_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct L_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct L_extra_size) == 34, "");
_Static_assert(_Alignof(struct L_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(L,d) == 128, "");
_Static_assert(__builtin_bitoffsetof(L,e) == 136, "");
#endif
_Static_assert(sizeof(M) == 4, "");
_Static_assert(_Alignof(M) == 2, "");
_Static_assert(sizeof(struct M_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct M_extra_alignment) == 2, "");
_Static_assert(sizeof(struct M_extra_packed) == 4, "");
_Static_assert(_Alignof(struct M_extra_packed) == 1, "");
_Static_assert(sizeof(struct M_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct M_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct M_extra_size) == 6, "");
_Static_assert(_Alignof(struct M_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(M,d) == 16, "");
_Static_assert(__builtin_bitoffsetof(M,e) == 24, "");
#endif
_Static_assert(sizeof(N) == 4, "");
_Static_assert(_Alignof(N) == 2, "");
_Static_assert(sizeof(struct N_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct N_extra_alignment) == 2, "");
_Static_assert(sizeof(struct N_extra_packed) == 4, "");
_Static_assert(_Alignof(struct N_extra_packed) == 1, "");
_Static_assert(sizeof(struct N_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct N_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct N_extra_size) == 6, "");
_Static_assert(_Alignof(struct N_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(N,d) == 8, "");
_Static_assert(__builtin_bitoffsetof(N,e) == 16, "");
#endif
_Static_assert(sizeof(O) == 3, "");
_Static_assert(_Alignof(O) == 1, "");
_Static_assert(sizeof(struct O_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct O_extra_alignment) == 1, "");
_Static_assert(sizeof(struct O_extra_packed) == 3, "");
_Static_assert(_Alignof(struct O_extra_packed) == 1, "");
_Static_assert(sizeof(struct O_extra_required_alignment) == 4, "");
_Static_assert(_Alignof(struct O_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct O_extra_size) == 5, "");
_Static_assert(_Alignof(struct O_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(O,d) == 8, "");
_Static_assert(__builtin_bitoffsetof(O,e) == 16, "");
#endif
_Static_assert(sizeof(P) == 4, "");
_Static_assert(_Alignof(P) == 2, "");
_Static_assert(sizeof(struct P_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct P_extra_alignment) == 2, "");
_Static_assert(sizeof(struct P_extra_packed) == 4, "");
_Static_assert(_Alignof(struct P_extra_packed) == 1, "");
_Static_assert(sizeof(struct P_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct P_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct P_extra_size) == 6, "");
_Static_assert(_Alignof(struct P_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(P,d) == 8, "");
_Static_assert(__builtin_bitoffsetof(P,e) == 16, "");
#endif
_Static_assert(sizeof(Q) == 4, "");
_Static_assert(_Alignof(Q) == 4, "");
_Static_assert(sizeof(struct Q_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct Q_extra_alignment) == 4, "");
_Static_assert(sizeof(struct Q_extra_packed) == 4, "");
_Static_assert(_Alignof(struct Q_extra_packed) == 1, "");
_Static_assert(sizeof(struct Q_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct Q_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct Q_extra_size) == 6, "");
_Static_assert(_Alignof(struct Q_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(Q,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(Q,d) == 9, "");
_Static_assert(__builtin_bitoffsetof(Q,e) == 16, "");
#endif
_Static_assert(sizeof(R) == 17, "");
_Static_assert(_Alignof(R) == 1, "");
_Static_assert(sizeof(struct R_extra_alignment) == 18, "");
_Static_assert(_Alignof(struct R_extra_alignment) == 1, "");
_Static_assert(sizeof(struct R_extra_packed) == 17, "");
_Static_assert(_Alignof(struct R_extra_packed) == 1, "");
_Static_assert(sizeof(struct R_extra_required_alignment) == 18, "");
_Static_assert(_Alignof(struct R_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct R_extra_size) == 19, "");
_Static_assert(_Alignof(struct R_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(R,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(R,e) == 128, "");
#endif
_Static_assert(sizeof(S) == 5, "");
_Static_assert(_Alignof(S) == 1, "");
_Static_assert(sizeof(struct S_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct S_extra_alignment) == 1, "");
_Static_assert(sizeof(struct S_extra_packed) == 5, "");
_Static_assert(_Alignof(struct S_extra_packed) == 1, "");
_Static_assert(sizeof(struct S_extra_required_alignment) == 6, "");
_Static_assert(_Alignof(struct S_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct S_extra_size) == 7, "");
_Static_assert(_Alignof(struct S_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(S,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(S,e) == 32, "");
#endif
_Static_assert(sizeof(T) == 5, "");
_Static_assert(_Alignof(T) == 1, "");
_Static_assert(sizeof(struct T_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct T_extra_alignment) == 1, "");
_Static_assert(sizeof(struct T_extra_packed) == 5, "");
_Static_assert(_Alignof(struct T_extra_packed) == 1, "");
_Static_assert(sizeof(struct T_extra_required_alignment) == 6, "");
_Static_assert(_Alignof(struct T_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct T_extra_size) == 7, "");
_Static_assert(_Alignof(struct T_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(T,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(T,e) == 32, "");
#endif
_Static_assert(sizeof(U) == 5, "");
_Static_assert(_Alignof(U) == 1, "");
_Static_assert(sizeof(struct U_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct U_extra_alignment) == 1, "");
_Static_assert(sizeof(struct U_extra_packed) == 5, "");
_Static_assert(_Alignof(struct U_extra_packed) == 1, "");
_Static_assert(sizeof(struct U_extra_required_alignment) == 6, "");
_Static_assert(_Alignof(struct U_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct U_extra_size) == 7, "");
_Static_assert(_Alignof(struct U_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(U,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(U,e) == 32, "");
#endif
_Static_assert(sizeof(V) == 5, "");
_Static_assert(_Alignof(V) == 1, "");
_Static_assert(sizeof(struct V_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct V_extra_alignment) == 1, "");
_Static_assert(sizeof(struct V_extra_packed) == 5, "");
_Static_assert(_Alignof(struct V_extra_packed) == 1, "");
_Static_assert(sizeof(struct V_extra_required_alignment) == 6, "");
_Static_assert(_Alignof(struct V_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct V_extra_size) == 7, "");
_Static_assert(_Alignof(struct V_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(V,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(V,e) == 32, "");
#endif
_Static_assert(sizeof(W) == 17, "");
_Static_assert(_Alignof(W) == 1, "");
_Static_assert(sizeof(struct W_extra_alignment) == 18, "");
_Static_assert(_Alignof(struct W_extra_alignment) == 1, "");
_Static_assert(sizeof(struct W_extra_packed) == 17, "");
_Static_assert(_Alignof(struct W_extra_packed) == 1, "");
_Static_assert(sizeof(struct W_extra_required_alignment) == 18, "");
_Static_assert(_Alignof(struct W_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct W_extra_size) == 19, "");
_Static_assert(_Alignof(struct W_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(W,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(W,e) == 128, "");
#endif
_Static_assert(sizeof(W_) == 17, "");
_Static_assert(_Alignof(W_) == 1, "");
_Static_assert(sizeof(struct W__extra_alignment) == 18, "");
_Static_assert(_Alignof(struct W__extra_alignment) == 1, "");
_Static_assert(sizeof(struct W__extra_packed) == 17, "");
_Static_assert(_Alignof(struct W__extra_packed) == 1, "");
_Static_assert(sizeof(struct W__extra_required_alignment) == 18, "");
_Static_assert(_Alignof(struct W__extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct W__extra_size) == 19, "");
_Static_assert(_Alignof(struct W__extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(W_,e) == 128, "");
#endif
_Static_assert(sizeof(X) == 17, "");
_Static_assert(_Alignof(X) == 1, "");
_Static_assert(sizeof(struct X_extra_alignment) == 18, "");
_Static_assert(_Alignof(struct X_extra_alignment) == 1, "");
_Static_assert(sizeof(struct X_extra_packed) == 17, "");
_Static_assert(_Alignof(struct X_extra_packed) == 1, "");
_Static_assert(sizeof(struct X_extra_required_alignment) == 18, "");
_Static_assert(_Alignof(struct X_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct X_extra_size) == 19, "");
_Static_assert(_Alignof(struct X_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(X,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(X,e) == 128, "");
#endif
_Static_assert(sizeof(A2) == 1, "");
_Static_assert(_Alignof(A2) == 1, "");
_Static_assert(sizeof(struct A2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct A2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct A2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct A2_extra_packed) == 1, "");
_Static_assert(sizeof(struct A2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct A2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A2_extra_size) == 3, "");
_Static_assert(_Alignof(struct A2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A2,d) == 0, "");
#endif
_Static_assert(sizeof(A_2) == 1, "");
_Static_assert(_Alignof(A_2) == 1, "");
_Static_assert(sizeof(struct A_2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct A_2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct A_2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct A_2_extra_packed) == 1, "");
_Static_assert(sizeof(struct A_2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct A_2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A_2_extra_size) == 3, "");
_Static_assert(_Alignof(struct A_2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_2,d) == 0, "");
#endif
_Static_assert(sizeof(B2) == 1, "");
_Static_assert(_Alignof(B2) == 1, "");
_Static_assert(sizeof(struct B2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct B2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct B2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct B2_extra_packed) == 1, "");
_Static_assert(sizeof(struct B2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct B2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B2_extra_size) == 3, "");
_Static_assert(_Alignof(struct B2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B2,d) == 0, "");
#endif
_Static_assert(sizeof(B_2) == 1, "");
_Static_assert(_Alignof(B_2) == 1, "");
_Static_assert(sizeof(struct B_2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct B_2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct B_2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct B_2_extra_packed) == 1, "");
_Static_assert(sizeof(struct B_2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct B_2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B_2_extra_size) == 3, "");
_Static_assert(_Alignof(struct B_2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B_2,d) == 0, "");
#endif
_Static_assert(sizeof(C2) == 1, "");
_Static_assert(_Alignof(C2) == 1, "");
_Static_assert(sizeof(struct C2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct C2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct C2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct C2_extra_packed) == 1, "");
_Static_assert(sizeof(struct C2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct C2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct C2_extra_size) == 3, "");
_Static_assert(_Alignof(struct C2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(C2,d) == 0, "");
#endif
_Static_assert(sizeof(C22) == 1, "");
_Static_assert(_Alignof(C22) == 1, "");
_Static_assert(sizeof(struct C22_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct C22_extra_alignment) == 1, "");
_Static_assert(sizeof(struct C22_extra_packed) == 1, "");
_Static_assert(_Alignof(struct C22_extra_packed) == 1, "");
_Static_assert(sizeof(struct C22_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct C22_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct C22_extra_size) == 3, "");
_Static_assert(_Alignof(struct C22_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(C22,d) == 0, "");
#endif
_Static_assert(sizeof(D2) == 8, "");
_Static_assert(_Alignof(D2) == 4, "");
_Static_assert(sizeof(struct D2_extra_alignment) == 12, "");
_Static_assert(_Alignof(struct D2_extra_alignment) == 4, "");
_Static_assert(sizeof(struct D2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct D2_extra_packed) == 1, "");
_Static_assert(sizeof(struct D2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct D2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct D2_extra_size) == 10, "");
_Static_assert(_Alignof(struct D2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(D2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(D2,e) == 0, "");
#endif
_Static_assert(sizeof(F2) == 16, "");
_Static_assert(_Alignof(F2) == 16, "");
_Static_assert(sizeof(struct F2_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct F2_extra_alignment) == 16, "");
_Static_assert(sizeof(struct F2_extra_packed) == 16, "");
_Static_assert(_Alignof(struct F2_extra_packed) == 1, "");
_Static_assert(sizeof(struct F2_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct F2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct F2_extra_size) == 18, "");
_Static_assert(_Alignof(struct F2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(F2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(F2,e) == 0, "");
#endif
_Static_assert(sizeof(G2) == 8, "");
_Static_assert(_Alignof(G2) == 2, "");
_Static_assert(sizeof(struct G2_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct G2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct G2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct G2_extra_packed) == 1, "");
_Static_assert(sizeof(struct G2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct G2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct G2_extra_size) == 10, "");
_Static_assert(_Alignof(struct G2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(G2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(G2,e) == 0, "");
#endif
_Static_assert(sizeof(H2) == 8, "");
_Static_assert(_Alignof(H2) == 2, "");
_Static_assert(sizeof(struct H2_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct H2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct H2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct H2_extra_packed) == 1, "");
_Static_assert(sizeof(struct H2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct H2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct H2_extra_size) == 10, "");
_Static_assert(_Alignof(struct H2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(H2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(H2,e) == 0, "");
#endif
_Static_assert(sizeof(I2) == 8, "");
_Static_assert(_Alignof(I2) == 1, "");
_Static_assert(sizeof(struct I2_extra_alignment) == 9, "");
_Static_assert(_Alignof(struct I2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct I2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct I2_extra_packed) == 1, "");
_Static_assert(sizeof(struct I2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct I2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct I2_extra_size) == 10, "");
_Static_assert(_Alignof(struct I2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(I2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(I2,e) == 0, "");
#endif
_Static_assert(sizeof(J2) == 8, "");
_Static_assert(_Alignof(J2) == 2, "");
_Static_assert(sizeof(struct J2_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct J2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct J2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct J2_extra_packed) == 1, "");
_Static_assert(sizeof(struct J2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct J2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct J2_extra_size) == 10, "");
_Static_assert(_Alignof(struct J2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(J2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(J2,e) == 0, "");
#endif
_Static_assert(sizeof(K2) == 4, "");
_Static_assert(_Alignof(K2) == 4, "");
_Static_assert(sizeof(struct K2_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct K2_extra_alignment) == 4, "");
_Static_assert(sizeof(struct K2_extra_packed) == 4, "");
_Static_assert(_Alignof(struct K2_extra_packed) == 1, "");
_Static_assert(sizeof(struct K2_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct K2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct K2_extra_size) == 6, "");
_Static_assert(_Alignof(struct K2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(K2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(K2,e) == 0, "");
#endif
_Static_assert(sizeof(L2) == 16, "");
_Static_assert(_Alignof(L2) == 16, "");
_Static_assert(sizeof(struct L2_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct L2_extra_alignment) == 16, "");
_Static_assert(sizeof(struct L2_extra_packed) == 16, "");
_Static_assert(_Alignof(struct L2_extra_packed) == 1, "");
_Static_assert(sizeof(struct L2_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct L2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct L2_extra_size) == 18, "");
_Static_assert(_Alignof(struct L2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(L2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(L2,e) == 0, "");
#endif
_Static_assert(sizeof(M2) == 2, "");
_Static_assert(_Alignof(M2) == 2, "");
_Static_assert(sizeof(struct M2_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct M2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct M2_extra_packed) == 2, "");
_Static_assert(_Alignof(struct M2_extra_packed) == 1, "");
_Static_assert(sizeof(struct M2_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct M2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct M2_extra_size) == 4, "");
_Static_assert(_Alignof(struct M2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(M2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(M2,e) == 0, "");
#endif
_Static_assert(sizeof(N2) == 2, "");
_Static_assert(_Alignof(N2) == 2, "");
_Static_assert(sizeof(struct N2_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct N2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct N2_extra_packed) == 2, "");
_Static_assert(_Alignof(struct N2_extra_packed) == 1, "");
_Static_assert(sizeof(struct N2_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct N2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct N2_extra_size) == 4, "");
_Static_assert(_Alignof(struct N2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(N2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(N2,e) == 0, "");
#endif
_Static_assert(sizeof(O2) == 1, "");
_Static_assert(_Alignof(O2) == 1, "");
_Static_assert(sizeof(struct O2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct O2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct O2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct O2_extra_packed) == 1, "");
_Static_assert(sizeof(struct O2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct O2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct O2_extra_size) == 3, "");
_Static_assert(_Alignof(struct O2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(O2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(O2,e) == 0, "");
#endif
_Static_assert(sizeof(P2) == 2, "");
_Static_assert(_Alignof(P2) == 2, "");
_Static_assert(sizeof(struct P2_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct P2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct P2_extra_packed) == 2, "");
_Static_assert(_Alignof(struct P2_extra_packed) == 1, "");
_Static_assert(sizeof(struct P2_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct P2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct P2_extra_size) == 4, "");
_Static_assert(_Alignof(struct P2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(P2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(P2,e) == 0, "");
#endif
_Static_assert(sizeof(Q2) == 4, "");
_Static_assert(_Alignof(Q2) == 4, "");
_Static_assert(sizeof(struct Q2_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct Q2_extra_alignment) == 4, "");
_Static_assert(sizeof(struct Q2_extra_packed) == 4, "");
_Static_assert(_Alignof(struct Q2_extra_packed) == 1, "");
_Static_assert(sizeof(struct Q2_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct Q2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct Q2_extra_size) == 6, "");
_Static_assert(_Alignof(struct Q2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(Q2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(Q2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(Q2,e) == 0, "");
#endif
_Static_assert(sizeof(R2) == 1, "");
_Static_assert(_Alignof(R2) == 1, "");
_Static_assert(sizeof(struct R2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct R2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct R2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct R2_extra_packed) == 1, "");
_Static_assert(sizeof(struct R2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct R2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct R2_extra_size) == 3, "");
_Static_assert(_Alignof(struct R2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(R2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(R2,e) == 0, "");
#endif
_Static_assert(sizeof(S2) == 1, "");
_Static_assert(_Alignof(S2) == 1, "");
_Static_assert(sizeof(struct S2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct S2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct S2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct S2_extra_packed) == 1, "");
_Static_assert(sizeof(struct S2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct S2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct S2_extra_size) == 3, "");
_Static_assert(_Alignof(struct S2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(S2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(S2,e) == 0, "");
#endif
_Static_assert(sizeof(T2) == 1, "");
_Static_assert(_Alignof(T2) == 1, "");
_Static_assert(sizeof(struct T2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct T2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct T2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct T2_extra_packed) == 1, "");
_Static_assert(sizeof(struct T2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct T2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct T2_extra_size) == 3, "");
_Static_assert(_Alignof(struct T2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(T2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(T2,e) == 0, "");
#endif
_Static_assert(sizeof(U2) == 1, "");
_Static_assert(_Alignof(U2) == 1, "");
_Static_assert(sizeof(struct U2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct U2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct U2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct U2_extra_packed) == 1, "");
_Static_assert(sizeof(struct U2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct U2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct U2_extra_size) == 3, "");
_Static_assert(_Alignof(struct U2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(U2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(U2,e) == 0, "");
#endif
_Static_assert(sizeof(V2) == 1, "");
_Static_assert(_Alignof(V2) == 1, "");
_Static_assert(sizeof(struct V2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct V2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct V2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct V2_extra_packed) == 1, "");
_Static_assert(sizeof(struct V2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct V2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct V2_extra_size) == 3, "");
_Static_assert(_Alignof(struct V2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(V2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(V2,e) == 0, "");
#endif
_Static_assert(sizeof(W2) == 1, "");
_Static_assert(_Alignof(W2) == 1, "");
_Static_assert(sizeof(struct W2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct W2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct W2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct W2_extra_packed) == 1, "");
_Static_assert(sizeof(struct W2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct W2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct W2_extra_size) == 3, "");
_Static_assert(_Alignof(struct W2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(W2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(W2,e) == 0, "");
#endif
_Static_assert(sizeof(W_2) == 1, "");
_Static_assert(_Alignof(W_2) == 1, "");
_Static_assert(sizeof(struct W_2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct W_2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct W_2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct W_2_extra_packed) == 1, "");
_Static_assert(sizeof(struct W_2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct W_2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct W_2_extra_size) == 3, "");
_Static_assert(_Alignof(struct W_2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(W_2,e) == 0, "");
#endif
_Static_assert(sizeof(X2) == 1, "");
_Static_assert(_Alignof(X2) == 1, "");
_Static_assert(sizeof(struct X2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct X2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct X2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct X2_extra_packed) == 1, "");
_Static_assert(sizeof(struct X2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct X2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct X2_extra_size) == 3, "");
_Static_assert(_Alignof(struct X2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(X2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(X2,e) == 0, "");
#endif
_Static_assert(sizeof(Y) == 5, "");
_Static_assert(_Alignof(Y) == 1, "");
_Static_assert(sizeof(struct Y_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct Y_extra_alignment) == 1, "");
_Static_assert(sizeof(struct Y_extra_packed) == 5, "");
_Static_assert(_Alignof(struct Y_extra_packed) == 1, "");
_Static_assert(sizeof(struct Y_extra_required_alignment) == 6, "");
_Static_assert(_Alignof(struct Y_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct Y_extra_size) == 7, "");
_Static_assert(_Alignof(struct Y_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(Y,d) == 32, "");
#endif
_Static_assert(sizeof(Y2) == 1, "");
_Static_assert(_Alignof(Y2) == 1, "");
_Static_assert(sizeof(struct Y2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct Y2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct Y2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct Y2_extra_packed) == 1, "");
_Static_assert(sizeof(struct Y2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct Y2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct Y2_extra_size) == 3, "");
_Static_assert(_Alignof(struct Y2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(Y2,d) == 0, "");
#endif
_Static_assert(sizeof(A3) == 33, "");
_Static_assert(_Alignof(A3) == 1, "");
_Static_assert(sizeof(struct A3_extra_alignment) == 34, "");
_Static_assert(_Alignof(struct A3_extra_alignment) == 1, "");
_Static_assert(sizeof(struct A3_extra_packed) == 33, "");
_Static_assert(_Alignof(struct A3_extra_packed) == 1, "");
_Static_assert(sizeof(struct A3_extra_required_alignment) == 34, "");
_Static_assert(_Alignof(struct A3_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A3_extra_size) == 35, "");
_Static_assert(_Alignof(struct A3_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A3,d) == 256, "");
#endif
_Static_assert(sizeof(A4) == 1, "");
_Static_assert(_Alignof(A4) == 32, "");
_Static_assert(sizeof(struct A4_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct A4_extra_alignment) == 32, "");
_Static_assert(sizeof(struct A4_extra_packed) == 1, "");
_Static_assert(_Alignof(struct A4_extra_packed) == 1, "");
_Static_assert(sizeof(struct A4_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct A4_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A4_extra_size) == 3, "");
_Static_assert(_Alignof(struct A4_extra_size) == 1, "");
_Static_assert(sizeof(A5) == 33, "");
_Static_assert(_Alignof(A5) == 1, "");
_Static_assert(sizeof(struct A5_extra_alignment) == 34, "");
_Static_assert(_Alignof(struct A5_extra_alignment) == 1, "");
_Static_assert(sizeof(struct A5_extra_packed) == 33, "");
_Static_assert(_Alignof(struct A5_extra_packed) == 1, "");
_Static_assert(sizeof(struct A5_extra_required_alignment) == 34, "");
_Static_assert(_Alignof(struct A5_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A5_extra_size) == 35, "");
_Static_assert(_Alignof(struct A5_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A5,d) == 256, "");
#endif
_Static_assert(sizeof(A7) == 32, "");
_Static_assert(_Alignof(A7) == 32, "");
_Static_assert(sizeof(struct A7_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct A7_extra_alignment) == 32, "");
_Static_assert(sizeof(struct A7_extra_packed) == 32, "");
_Static_assert(_Alignof(struct A7_extra_packed) == 1, "");
_Static_assert(sizeof(struct A7_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct A7_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A7_extra_size) == 34, "");
_Static_assert(_Alignof(struct A7_extra_size) == 1, "");
_Static_assert(sizeof(A8) == 8, "");
_Static_assert(_Alignof(A8) == 4, "");
_Static_assert(sizeof(struct A8_extra_alignment) == 12, "");
_Static_assert(_Alignof(struct A8_extra_alignment) == 4, "");
_Static_assert(sizeof(struct A8_extra_packed) == 8, "");
_Static_assert(_Alignof(struct A8_extra_packed) == 1, "");
_Static_assert(sizeof(struct A8_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct A8_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A8_extra_size) == 10, "");
_Static_assert(_Alignof(struct A8_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A8,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A8,j) == 39, "");
#endif
_Static_assert(sizeof(A9) == 12, "");
_Static_assert(_Alignof(A9) == 4, "");
_Static_assert(sizeof(struct A9_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct A9_extra_alignment) == 4, "");
_Static_assert(sizeof(struct A9_extra_packed) == 12, "");
_Static_assert(_Alignof(struct A9_extra_packed) == 1, "");
_Static_assert(sizeof(struct A9_extra_required_alignment) == 13, "");
_Static_assert(_Alignof(struct A9_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A9_extra_size) == 14, "");
_Static_assert(_Alignof(struct A9_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A9,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A9,j) == 64, "");
#endif
_Static_assert(sizeof(A10) == 4, "");
_Static_assert(_Alignof(A10) == 16, "");
_Static_assert(sizeof(struct A10_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct A10_extra_alignment) == 16, "");
_Static_assert(sizeof(struct A10_extra_packed) == 4, "");
_Static_assert(_Alignof(struct A10_extra_packed) == 1, "");
_Static_assert(sizeof(struct A10_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct A10_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A10_extra_size) == 6, "");
_Static_assert(_Alignof(struct A10_extra_size) == 1, "");
_Static_assert(sizeof(A11) == 32, "");
_Static_assert(_Alignof(A11) == 16, "");
_Static_assert(sizeof(struct A11_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct A11_extra_alignment) == 16, "");
_Static_assert(sizeof(struct A11_extra_packed) == 32, "");
_Static_assert(_Alignof(struct A11_extra_packed) == 1, "");
_Static_assert(sizeof(struct A11_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct A11_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A11_extra_size) == 34, "");
_Static_assert(_Alignof(struct A11_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A11,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A11,j) == 128, "");
#endif
_Static_assert(sizeof(A12) == 32, "");
_Static_assert(_Alignof(A12) == 16, "");
_Static_assert(sizeof(struct A12_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct A12_extra_alignment) == 16, "");
_Static_assert(sizeof(struct A12_extra_packed) == 32, "");
_Static_assert(_Alignof(struct A12_extra_packed) == 1, "");
_Static_assert(sizeof(struct A12_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct A12_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A12_extra_size) == 34, "");
_Static_assert(_Alignof(struct A12_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A12,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A12,j) == 128, "");
#endif
_Static_assert(sizeof(A13) == 32, "");
_Static_assert(_Alignof(A13) == 16, "");
_Static_assert(sizeof(struct A13_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct A13_extra_alignment) == 16, "");
_Static_assert(sizeof(struct A13_extra_packed) == 32, "");
_Static_assert(_Alignof(struct A13_extra_packed) == 1, "");
_Static_assert(sizeof(struct A13_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct A13_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A13_extra_size) == 34, "");
_Static_assert(_Alignof(struct A13_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A13,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A13,j) == 128, "");
_Static_assert(__builtin_bitoffsetof(A13,d) == 136, "");
#endif
// MAPPING|TEN|x86-i586-linux-gnu:Gcc|x86-i586-linux-musl:Gcc|x86-i686-linux-gnu:Gcc|x86-i686-linux-musl:Gcc|END
// repr targets I586UnknownLinuxGnu|Some("x86-i586-linux-gnu") I586UnknownLinuxMusl|Some("x86-i586-linux-musl") I686UnknownLinuxGnu|Some("x86-i686-linux-gnu") I686UnknownLinuxMusl|Some("x86-i686-linux-musl") 
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
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A,d) == 0, "");
#endif
_Static_assert(sizeof(A_) == 5, "");
_Static_assert(_Alignof(A_) == 1, "");
_Static_assert(sizeof(struct A__extra_alignment) == 6, "");
_Static_assert(_Alignof(struct A__extra_alignment) == 1, "");
_Static_assert(sizeof(struct A__extra_packed) == 5, "");
_Static_assert(_Alignof(struct A__extra_packed) == 1, "");
_Static_assert(sizeof(struct A__extra_required_alignment) == 6, "");
_Static_assert(_Alignof(struct A__extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A__extra_size) == 7, "");
_Static_assert(_Alignof(struct A__extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_,d) == 32, "");
#endif
_Static_assert(sizeof(B) == 1, "");
_Static_assert(_Alignof(B) == 1, "");
_Static_assert(sizeof(struct B_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct B_extra_alignment) == 1, "");
_Static_assert(sizeof(struct B_extra_packed) == 1, "");
_Static_assert(_Alignof(struct B_extra_packed) == 1, "");
_Static_assert(sizeof(struct B_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct B_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B_extra_size) == 3, "");
_Static_assert(_Alignof(struct B_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B,d) == 0, "");
#endif
_Static_assert(sizeof(B_) == 5, "");
_Static_assert(_Alignof(B_) == 1, "");
_Static_assert(sizeof(struct B__extra_alignment) == 6, "");
_Static_assert(_Alignof(struct B__extra_alignment) == 1, "");
_Static_assert(sizeof(struct B__extra_packed) == 5, "");
_Static_assert(_Alignof(struct B__extra_packed) == 1, "");
_Static_assert(sizeof(struct B__extra_required_alignment) == 6, "");
_Static_assert(_Alignof(struct B__extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B__extra_size) == 7, "");
_Static_assert(_Alignof(struct B__extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B_,d) == 32, "");
#endif
_Static_assert(sizeof(C) == 1, "");
_Static_assert(_Alignof(C) == 1, "");
_Static_assert(sizeof(struct C_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct C_extra_alignment) == 1, "");
_Static_assert(sizeof(struct C_extra_packed) == 1, "");
_Static_assert(_Alignof(struct C_extra_packed) == 1, "");
_Static_assert(sizeof(struct C_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct C_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct C_extra_size) == 3, "");
_Static_assert(_Alignof(struct C_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(C,d) == 0, "");
#endif
_Static_assert(sizeof(C_) == 5, "");
_Static_assert(_Alignof(C_) == 1, "");
_Static_assert(sizeof(struct C__extra_alignment) == 6, "");
_Static_assert(_Alignof(struct C__extra_alignment) == 1, "");
_Static_assert(sizeof(struct C__extra_packed) == 5, "");
_Static_assert(_Alignof(struct C__extra_packed) == 1, "");
_Static_assert(sizeof(struct C__extra_required_alignment) == 6, "");
_Static_assert(_Alignof(struct C__extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct C__extra_size) == 7, "");
_Static_assert(_Alignof(struct C__extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(C_,d) == 32, "");
#endif
_Static_assert(sizeof(D) == 16, "");
_Static_assert(_Alignof(D) == 4, "");
_Static_assert(sizeof(struct D_extra_alignment) == 20, "");
_Static_assert(_Alignof(struct D_extra_alignment) == 4, "");
_Static_assert(sizeof(struct D_extra_packed) == 16, "");
_Static_assert(_Alignof(struct D_extra_packed) == 1, "");
_Static_assert(sizeof(struct D_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct D_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct D_extra_size) == 18, "");
_Static_assert(_Alignof(struct D_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(D,d) == 32, "");
_Static_assert(__builtin_bitoffsetof(D,e) == 96, "");
#endif
_Static_assert(sizeof(F) == 32, "");
_Static_assert(_Alignof(F) == 16, "");
_Static_assert(sizeof(struct F_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct F_extra_alignment) == 16, "");
_Static_assert(sizeof(struct F_extra_packed) == 32, "");
_Static_assert(_Alignof(struct F_extra_packed) == 1, "");
_Static_assert(sizeof(struct F_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct F_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct F_extra_size) == 34, "");
_Static_assert(_Alignof(struct F_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(F,d) == 128, "");
_Static_assert(__builtin_bitoffsetof(F,e) == 192, "");
#endif
_Static_assert(sizeof(G) == 12, "");
_Static_assert(_Alignof(G) == 2, "");
_Static_assert(sizeof(struct G_extra_alignment) == 14, "");
_Static_assert(_Alignof(struct G_extra_alignment) == 2, "");
_Static_assert(sizeof(struct G_extra_packed) == 12, "");
_Static_assert(_Alignof(struct G_extra_packed) == 1, "");
_Static_assert(sizeof(struct G_extra_required_alignment) == 13, "");
_Static_assert(_Alignof(struct G_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct G_extra_size) == 14, "");
_Static_assert(_Alignof(struct G_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(G,d) == 16, "");
_Static_assert(__builtin_bitoffsetof(G,e) == 80, "");
#endif
_Static_assert(sizeof(H) == 12, "");
_Static_assert(_Alignof(H) == 2, "");
_Static_assert(sizeof(struct H_extra_alignment) == 14, "");
_Static_assert(_Alignof(struct H_extra_alignment) == 2, "");
_Static_assert(sizeof(struct H_extra_packed) == 12, "");
_Static_assert(_Alignof(struct H_extra_packed) == 1, "");
_Static_assert(sizeof(struct H_extra_required_alignment) == 13, "");
_Static_assert(_Alignof(struct H_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct H_extra_size) == 14, "");
_Static_assert(_Alignof(struct H_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(H,d) == 16, "");
_Static_assert(__builtin_bitoffsetof(H,e) == 80, "");
#endif
_Static_assert(sizeof(I) == 10, "");
_Static_assert(_Alignof(I) == 1, "");
_Static_assert(sizeof(struct I_extra_alignment) == 11, "");
_Static_assert(_Alignof(struct I_extra_alignment) == 1, "");
_Static_assert(sizeof(struct I_extra_packed) == 10, "");
_Static_assert(_Alignof(struct I_extra_packed) == 1, "");
_Static_assert(sizeof(struct I_extra_required_alignment) == 11, "");
_Static_assert(_Alignof(struct I_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct I_extra_size) == 12, "");
_Static_assert(_Alignof(struct I_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(I,d) == 8, "");
_Static_assert(__builtin_bitoffsetof(I,e) == 72, "");
#endif
_Static_assert(sizeof(J) == 12, "");
_Static_assert(_Alignof(J) == 2, "");
_Static_assert(sizeof(struct J_extra_alignment) == 14, "");
_Static_assert(_Alignof(struct J_extra_alignment) == 2, "");
_Static_assert(sizeof(struct J_extra_packed) == 12, "");
_Static_assert(_Alignof(struct J_extra_packed) == 1, "");
_Static_assert(sizeof(struct J_extra_required_alignment) == 13, "");
_Static_assert(_Alignof(struct J_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct J_extra_size) == 14, "");
_Static_assert(_Alignof(struct J_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(J,d) == 16, "");
_Static_assert(__builtin_bitoffsetof(J,e) == 80, "");
#endif
_Static_assert(sizeof(K) == 4, "");
_Static_assert(_Alignof(K) == 4, "");
_Static_assert(sizeof(struct K_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct K_extra_alignment) == 4, "");
_Static_assert(sizeof(struct K_extra_packed) == 4, "");
_Static_assert(_Alignof(struct K_extra_packed) == 1, "");
_Static_assert(sizeof(struct K_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct K_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct K_extra_size) == 6, "");
_Static_assert(_Alignof(struct K_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(K,d) == 8, "");
_Static_assert(__builtin_bitoffsetof(K,e) == 16, "");
#endif
_Static_assert(sizeof(L) == 32, "");
_Static_assert(_Alignof(L) == 16, "");
_Static_assert(sizeof(struct L_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct L_extra_alignment) == 16, "");
_Static_assert(sizeof(struct L_extra_packed) == 32, "");
_Static_assert(_Alignof(struct L_extra_packed) == 1, "");
_Static_assert(sizeof(struct L_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct L_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct L_extra_size) == 34, "");
_Static_assert(_Alignof(struct L_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(L,d) == 128, "");
_Static_assert(__builtin_bitoffsetof(L,e) == 136, "");
#endif
_Static_assert(sizeof(M) == 4, "");
_Static_assert(_Alignof(M) == 2, "");
_Static_assert(sizeof(struct M_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct M_extra_alignment) == 2, "");
_Static_assert(sizeof(struct M_extra_packed) == 4, "");
_Static_assert(_Alignof(struct M_extra_packed) == 1, "");
_Static_assert(sizeof(struct M_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct M_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct M_extra_size) == 6, "");
_Static_assert(_Alignof(struct M_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(M,d) == 16, "");
_Static_assert(__builtin_bitoffsetof(M,e) == 24, "");
#endif
_Static_assert(sizeof(N) == 4, "");
_Static_assert(_Alignof(N) == 2, "");
_Static_assert(sizeof(struct N_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct N_extra_alignment) == 2, "");
_Static_assert(sizeof(struct N_extra_packed) == 4, "");
_Static_assert(_Alignof(struct N_extra_packed) == 1, "");
_Static_assert(sizeof(struct N_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct N_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct N_extra_size) == 6, "");
_Static_assert(_Alignof(struct N_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(N,d) == 16, "");
_Static_assert(__builtin_bitoffsetof(N,e) == 24, "");
#endif
_Static_assert(sizeof(O) == 3, "");
_Static_assert(_Alignof(O) == 1, "");
_Static_assert(sizeof(struct O_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct O_extra_alignment) == 1, "");
_Static_assert(sizeof(struct O_extra_packed) == 3, "");
_Static_assert(_Alignof(struct O_extra_packed) == 1, "");
_Static_assert(sizeof(struct O_extra_required_alignment) == 4, "");
_Static_assert(_Alignof(struct O_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct O_extra_size) == 5, "");
_Static_assert(_Alignof(struct O_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(O,d) == 8, "");
_Static_assert(__builtin_bitoffsetof(O,e) == 16, "");
#endif
_Static_assert(sizeof(P) == 4, "");
_Static_assert(_Alignof(P) == 2, "");
_Static_assert(sizeof(struct P_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct P_extra_alignment) == 2, "");
_Static_assert(sizeof(struct P_extra_packed) == 4, "");
_Static_assert(_Alignof(struct P_extra_packed) == 1, "");
_Static_assert(sizeof(struct P_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct P_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct P_extra_size) == 6, "");
_Static_assert(_Alignof(struct P_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(P,d) == 8, "");
_Static_assert(__builtin_bitoffsetof(P,e) == 16, "");
#endif
_Static_assert(sizeof(Q) == 4, "");
_Static_assert(_Alignof(Q) == 4, "");
_Static_assert(sizeof(struct Q_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct Q_extra_alignment) == 4, "");
_Static_assert(sizeof(struct Q_extra_packed) == 4, "");
_Static_assert(_Alignof(struct Q_extra_packed) == 1, "");
_Static_assert(sizeof(struct Q_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct Q_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct Q_extra_size) == 6, "");
_Static_assert(_Alignof(struct Q_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(Q,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(Q,d) == 9, "");
_Static_assert(__builtin_bitoffsetof(Q,e) == 16, "");
#endif
_Static_assert(sizeof(R) == 17, "");
_Static_assert(_Alignof(R) == 1, "");
_Static_assert(sizeof(struct R_extra_alignment) == 18, "");
_Static_assert(_Alignof(struct R_extra_alignment) == 1, "");
_Static_assert(sizeof(struct R_extra_packed) == 17, "");
_Static_assert(_Alignof(struct R_extra_packed) == 1, "");
_Static_assert(sizeof(struct R_extra_required_alignment) == 18, "");
_Static_assert(_Alignof(struct R_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct R_extra_size) == 19, "");
_Static_assert(_Alignof(struct R_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(R,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(R,e) == 128, "");
#endif
_Static_assert(sizeof(S) == 5, "");
_Static_assert(_Alignof(S) == 1, "");
_Static_assert(sizeof(struct S_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct S_extra_alignment) == 1, "");
_Static_assert(sizeof(struct S_extra_packed) == 5, "");
_Static_assert(_Alignof(struct S_extra_packed) == 1, "");
_Static_assert(sizeof(struct S_extra_required_alignment) == 6, "");
_Static_assert(_Alignof(struct S_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct S_extra_size) == 7, "");
_Static_assert(_Alignof(struct S_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(S,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(S,e) == 32, "");
#endif
_Static_assert(sizeof(T) == 5, "");
_Static_assert(_Alignof(T) == 1, "");
_Static_assert(sizeof(struct T_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct T_extra_alignment) == 1, "");
_Static_assert(sizeof(struct T_extra_packed) == 5, "");
_Static_assert(_Alignof(struct T_extra_packed) == 1, "");
_Static_assert(sizeof(struct T_extra_required_alignment) == 6, "");
_Static_assert(_Alignof(struct T_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct T_extra_size) == 7, "");
_Static_assert(_Alignof(struct T_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(T,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(T,e) == 32, "");
#endif
_Static_assert(sizeof(U) == 5, "");
_Static_assert(_Alignof(U) == 1, "");
_Static_assert(sizeof(struct U_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct U_extra_alignment) == 1, "");
_Static_assert(sizeof(struct U_extra_packed) == 5, "");
_Static_assert(_Alignof(struct U_extra_packed) == 1, "");
_Static_assert(sizeof(struct U_extra_required_alignment) == 6, "");
_Static_assert(_Alignof(struct U_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct U_extra_size) == 7, "");
_Static_assert(_Alignof(struct U_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(U,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(U,e) == 32, "");
#endif
_Static_assert(sizeof(V) == 5, "");
_Static_assert(_Alignof(V) == 1, "");
_Static_assert(sizeof(struct V_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct V_extra_alignment) == 1, "");
_Static_assert(sizeof(struct V_extra_packed) == 5, "");
_Static_assert(_Alignof(struct V_extra_packed) == 1, "");
_Static_assert(sizeof(struct V_extra_required_alignment) == 6, "");
_Static_assert(_Alignof(struct V_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct V_extra_size) == 7, "");
_Static_assert(_Alignof(struct V_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(V,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(V,e) == 32, "");
#endif
_Static_assert(sizeof(W) == 17, "");
_Static_assert(_Alignof(W) == 1, "");
_Static_assert(sizeof(struct W_extra_alignment) == 18, "");
_Static_assert(_Alignof(struct W_extra_alignment) == 1, "");
_Static_assert(sizeof(struct W_extra_packed) == 17, "");
_Static_assert(_Alignof(struct W_extra_packed) == 1, "");
_Static_assert(sizeof(struct W_extra_required_alignment) == 18, "");
_Static_assert(_Alignof(struct W_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct W_extra_size) == 19, "");
_Static_assert(_Alignof(struct W_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(W,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(W,e) == 128, "");
#endif
_Static_assert(sizeof(W_) == 17, "");
_Static_assert(_Alignof(W_) == 1, "");
_Static_assert(sizeof(struct W__extra_alignment) == 18, "");
_Static_assert(_Alignof(struct W__extra_alignment) == 1, "");
_Static_assert(sizeof(struct W__extra_packed) == 17, "");
_Static_assert(_Alignof(struct W__extra_packed) == 1, "");
_Static_assert(sizeof(struct W__extra_required_alignment) == 18, "");
_Static_assert(_Alignof(struct W__extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct W__extra_size) == 19, "");
_Static_assert(_Alignof(struct W__extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(W_,e) == 128, "");
#endif
_Static_assert(sizeof(X) == 17, "");
_Static_assert(_Alignof(X) == 1, "");
_Static_assert(sizeof(struct X_extra_alignment) == 18, "");
_Static_assert(_Alignof(struct X_extra_alignment) == 1, "");
_Static_assert(sizeof(struct X_extra_packed) == 17, "");
_Static_assert(_Alignof(struct X_extra_packed) == 1, "");
_Static_assert(sizeof(struct X_extra_required_alignment) == 18, "");
_Static_assert(_Alignof(struct X_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct X_extra_size) == 19, "");
_Static_assert(_Alignof(struct X_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(X,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(X,e) == 128, "");
#endif
_Static_assert(sizeof(A2) == 1, "");
_Static_assert(_Alignof(A2) == 1, "");
_Static_assert(sizeof(struct A2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct A2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct A2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct A2_extra_packed) == 1, "");
_Static_assert(sizeof(struct A2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct A2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A2_extra_size) == 3, "");
_Static_assert(_Alignof(struct A2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A2,d) == 0, "");
#endif
_Static_assert(sizeof(A_2) == 1, "");
_Static_assert(_Alignof(A_2) == 1, "");
_Static_assert(sizeof(struct A_2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct A_2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct A_2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct A_2_extra_packed) == 1, "");
_Static_assert(sizeof(struct A_2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct A_2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A_2_extra_size) == 3, "");
_Static_assert(_Alignof(struct A_2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_2,d) == 0, "");
#endif
_Static_assert(sizeof(B2) == 1, "");
_Static_assert(_Alignof(B2) == 1, "");
_Static_assert(sizeof(struct B2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct B2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct B2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct B2_extra_packed) == 1, "");
_Static_assert(sizeof(struct B2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct B2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B2_extra_size) == 3, "");
_Static_assert(_Alignof(struct B2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B2,d) == 0, "");
#endif
_Static_assert(sizeof(B_2) == 1, "");
_Static_assert(_Alignof(B_2) == 1, "");
_Static_assert(sizeof(struct B_2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct B_2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct B_2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct B_2_extra_packed) == 1, "");
_Static_assert(sizeof(struct B_2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct B_2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B_2_extra_size) == 3, "");
_Static_assert(_Alignof(struct B_2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B_2,d) == 0, "");
#endif
_Static_assert(sizeof(C2) == 1, "");
_Static_assert(_Alignof(C2) == 1, "");
_Static_assert(sizeof(struct C2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct C2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct C2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct C2_extra_packed) == 1, "");
_Static_assert(sizeof(struct C2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct C2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct C2_extra_size) == 3, "");
_Static_assert(_Alignof(struct C2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(C2,d) == 0, "");
#endif
_Static_assert(sizeof(C22) == 1, "");
_Static_assert(_Alignof(C22) == 1, "");
_Static_assert(sizeof(struct C22_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct C22_extra_alignment) == 1, "");
_Static_assert(sizeof(struct C22_extra_packed) == 1, "");
_Static_assert(_Alignof(struct C22_extra_packed) == 1, "");
_Static_assert(sizeof(struct C22_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct C22_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct C22_extra_size) == 3, "");
_Static_assert(_Alignof(struct C22_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(C22,d) == 0, "");
#endif
_Static_assert(sizeof(D2) == 8, "");
_Static_assert(_Alignof(D2) == 4, "");
_Static_assert(sizeof(struct D2_extra_alignment) == 12, "");
_Static_assert(_Alignof(struct D2_extra_alignment) == 4, "");
_Static_assert(sizeof(struct D2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct D2_extra_packed) == 1, "");
_Static_assert(sizeof(struct D2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct D2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct D2_extra_size) == 10, "");
_Static_assert(_Alignof(struct D2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(D2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(D2,e) == 0, "");
#endif
_Static_assert(sizeof(F2) == 16, "");
_Static_assert(_Alignof(F2) == 16, "");
_Static_assert(sizeof(struct F2_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct F2_extra_alignment) == 16, "");
_Static_assert(sizeof(struct F2_extra_packed) == 16, "");
_Static_assert(_Alignof(struct F2_extra_packed) == 1, "");
_Static_assert(sizeof(struct F2_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct F2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct F2_extra_size) == 18, "");
_Static_assert(_Alignof(struct F2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(F2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(F2,e) == 0, "");
#endif
_Static_assert(sizeof(G2) == 8, "");
_Static_assert(_Alignof(G2) == 2, "");
_Static_assert(sizeof(struct G2_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct G2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct G2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct G2_extra_packed) == 1, "");
_Static_assert(sizeof(struct G2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct G2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct G2_extra_size) == 10, "");
_Static_assert(_Alignof(struct G2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(G2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(G2,e) == 0, "");
#endif
_Static_assert(sizeof(H2) == 8, "");
_Static_assert(_Alignof(H2) == 2, "");
_Static_assert(sizeof(struct H2_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct H2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct H2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct H2_extra_packed) == 1, "");
_Static_assert(sizeof(struct H2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct H2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct H2_extra_size) == 10, "");
_Static_assert(_Alignof(struct H2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(H2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(H2,e) == 0, "");
#endif
_Static_assert(sizeof(I2) == 8, "");
_Static_assert(_Alignof(I2) == 1, "");
_Static_assert(sizeof(struct I2_extra_alignment) == 9, "");
_Static_assert(_Alignof(struct I2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct I2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct I2_extra_packed) == 1, "");
_Static_assert(sizeof(struct I2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct I2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct I2_extra_size) == 10, "");
_Static_assert(_Alignof(struct I2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(I2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(I2,e) == 0, "");
#endif
_Static_assert(sizeof(J2) == 8, "");
_Static_assert(_Alignof(J2) == 2, "");
_Static_assert(sizeof(struct J2_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct J2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct J2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct J2_extra_packed) == 1, "");
_Static_assert(sizeof(struct J2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct J2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct J2_extra_size) == 10, "");
_Static_assert(_Alignof(struct J2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(J2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(J2,e) == 0, "");
#endif
_Static_assert(sizeof(K2) == 4, "");
_Static_assert(_Alignof(K2) == 4, "");
_Static_assert(sizeof(struct K2_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct K2_extra_alignment) == 4, "");
_Static_assert(sizeof(struct K2_extra_packed) == 4, "");
_Static_assert(_Alignof(struct K2_extra_packed) == 1, "");
_Static_assert(sizeof(struct K2_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct K2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct K2_extra_size) == 6, "");
_Static_assert(_Alignof(struct K2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(K2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(K2,e) == 0, "");
#endif
_Static_assert(sizeof(L2) == 16, "");
_Static_assert(_Alignof(L2) == 16, "");
_Static_assert(sizeof(struct L2_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct L2_extra_alignment) == 16, "");
_Static_assert(sizeof(struct L2_extra_packed) == 16, "");
_Static_assert(_Alignof(struct L2_extra_packed) == 1, "");
_Static_assert(sizeof(struct L2_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct L2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct L2_extra_size) == 18, "");
_Static_assert(_Alignof(struct L2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(L2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(L2,e) == 0, "");
#endif
_Static_assert(sizeof(M2) == 2, "");
_Static_assert(_Alignof(M2) == 2, "");
_Static_assert(sizeof(struct M2_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct M2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct M2_extra_packed) == 2, "");
_Static_assert(_Alignof(struct M2_extra_packed) == 1, "");
_Static_assert(sizeof(struct M2_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct M2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct M2_extra_size) == 4, "");
_Static_assert(_Alignof(struct M2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(M2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(M2,e) == 0, "");
#endif
_Static_assert(sizeof(N2) == 2, "");
_Static_assert(_Alignof(N2) == 2, "");
_Static_assert(sizeof(struct N2_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct N2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct N2_extra_packed) == 2, "");
_Static_assert(_Alignof(struct N2_extra_packed) == 1, "");
_Static_assert(sizeof(struct N2_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct N2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct N2_extra_size) == 4, "");
_Static_assert(_Alignof(struct N2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(N2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(N2,e) == 0, "");
#endif
_Static_assert(sizeof(O2) == 1, "");
_Static_assert(_Alignof(O2) == 1, "");
_Static_assert(sizeof(struct O2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct O2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct O2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct O2_extra_packed) == 1, "");
_Static_assert(sizeof(struct O2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct O2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct O2_extra_size) == 3, "");
_Static_assert(_Alignof(struct O2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(O2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(O2,e) == 0, "");
#endif
_Static_assert(sizeof(P2) == 2, "");
_Static_assert(_Alignof(P2) == 2, "");
_Static_assert(sizeof(struct P2_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct P2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct P2_extra_packed) == 2, "");
_Static_assert(_Alignof(struct P2_extra_packed) == 1, "");
_Static_assert(sizeof(struct P2_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct P2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct P2_extra_size) == 4, "");
_Static_assert(_Alignof(struct P2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(P2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(P2,e) == 0, "");
#endif
_Static_assert(sizeof(Q2) == 4, "");
_Static_assert(_Alignof(Q2) == 4, "");
_Static_assert(sizeof(struct Q2_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct Q2_extra_alignment) == 4, "");
_Static_assert(sizeof(struct Q2_extra_packed) == 4, "");
_Static_assert(_Alignof(struct Q2_extra_packed) == 1, "");
_Static_assert(sizeof(struct Q2_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct Q2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct Q2_extra_size) == 6, "");
_Static_assert(_Alignof(struct Q2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(Q2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(Q2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(Q2,e) == 0, "");
#endif
_Static_assert(sizeof(R2) == 1, "");
_Static_assert(_Alignof(R2) == 1, "");
_Static_assert(sizeof(struct R2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct R2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct R2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct R2_extra_packed) == 1, "");
_Static_assert(sizeof(struct R2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct R2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct R2_extra_size) == 3, "");
_Static_assert(_Alignof(struct R2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(R2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(R2,e) == 0, "");
#endif
_Static_assert(sizeof(S2) == 1, "");
_Static_assert(_Alignof(S2) == 1, "");
_Static_assert(sizeof(struct S2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct S2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct S2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct S2_extra_packed) == 1, "");
_Static_assert(sizeof(struct S2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct S2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct S2_extra_size) == 3, "");
_Static_assert(_Alignof(struct S2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(S2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(S2,e) == 0, "");
#endif
_Static_assert(sizeof(T2) == 1, "");
_Static_assert(_Alignof(T2) == 1, "");
_Static_assert(sizeof(struct T2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct T2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct T2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct T2_extra_packed) == 1, "");
_Static_assert(sizeof(struct T2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct T2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct T2_extra_size) == 3, "");
_Static_assert(_Alignof(struct T2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(T2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(T2,e) == 0, "");
#endif
_Static_assert(sizeof(U2) == 1, "");
_Static_assert(_Alignof(U2) == 1, "");
_Static_assert(sizeof(struct U2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct U2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct U2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct U2_extra_packed) == 1, "");
_Static_assert(sizeof(struct U2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct U2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct U2_extra_size) == 3, "");
_Static_assert(_Alignof(struct U2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(U2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(U2,e) == 0, "");
#endif
_Static_assert(sizeof(V2) == 1, "");
_Static_assert(_Alignof(V2) == 1, "");
_Static_assert(sizeof(struct V2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct V2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct V2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct V2_extra_packed) == 1, "");
_Static_assert(sizeof(struct V2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct V2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct V2_extra_size) == 3, "");
_Static_assert(_Alignof(struct V2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(V2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(V2,e) == 0, "");
#endif
_Static_assert(sizeof(W2) == 1, "");
_Static_assert(_Alignof(W2) == 1, "");
_Static_assert(sizeof(struct W2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct W2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct W2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct W2_extra_packed) == 1, "");
_Static_assert(sizeof(struct W2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct W2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct W2_extra_size) == 3, "");
_Static_assert(_Alignof(struct W2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(W2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(W2,e) == 0, "");
#endif
_Static_assert(sizeof(W_2) == 1, "");
_Static_assert(_Alignof(W_2) == 1, "");
_Static_assert(sizeof(struct W_2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct W_2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct W_2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct W_2_extra_packed) == 1, "");
_Static_assert(sizeof(struct W_2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct W_2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct W_2_extra_size) == 3, "");
_Static_assert(_Alignof(struct W_2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(W_2,e) == 0, "");
#endif
_Static_assert(sizeof(X2) == 1, "");
_Static_assert(_Alignof(X2) == 1, "");
_Static_assert(sizeof(struct X2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct X2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct X2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct X2_extra_packed) == 1, "");
_Static_assert(sizeof(struct X2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct X2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct X2_extra_size) == 3, "");
_Static_assert(_Alignof(struct X2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(X2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(X2,e) == 0, "");
#endif
_Static_assert(sizeof(Y) == 5, "");
_Static_assert(_Alignof(Y) == 1, "");
_Static_assert(sizeof(struct Y_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct Y_extra_alignment) == 1, "");
_Static_assert(sizeof(struct Y_extra_packed) == 5, "");
_Static_assert(_Alignof(struct Y_extra_packed) == 1, "");
_Static_assert(sizeof(struct Y_extra_required_alignment) == 6, "");
_Static_assert(_Alignof(struct Y_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct Y_extra_size) == 7, "");
_Static_assert(_Alignof(struct Y_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(Y,d) == 32, "");
#endif
_Static_assert(sizeof(Y2) == 1, "");
_Static_assert(_Alignof(Y2) == 1, "");
_Static_assert(sizeof(struct Y2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct Y2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct Y2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct Y2_extra_packed) == 1, "");
_Static_assert(sizeof(struct Y2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct Y2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct Y2_extra_size) == 3, "");
_Static_assert(_Alignof(struct Y2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(Y2,d) == 0, "");
#endif
_Static_assert(sizeof(A3) == 33, "");
_Static_assert(_Alignof(A3) == 1, "");
_Static_assert(sizeof(struct A3_extra_alignment) == 34, "");
_Static_assert(_Alignof(struct A3_extra_alignment) == 1, "");
_Static_assert(sizeof(struct A3_extra_packed) == 33, "");
_Static_assert(_Alignof(struct A3_extra_packed) == 1, "");
_Static_assert(sizeof(struct A3_extra_required_alignment) == 34, "");
_Static_assert(_Alignof(struct A3_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A3_extra_size) == 35, "");
_Static_assert(_Alignof(struct A3_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A3,d) == 256, "");
#endif
_Static_assert(sizeof(A4) == 1, "");
_Static_assert(_Alignof(A4) == 32, "");
_Static_assert(sizeof(struct A4_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct A4_extra_alignment) == 32, "");
_Static_assert(sizeof(struct A4_extra_packed) == 1, "");
_Static_assert(_Alignof(struct A4_extra_packed) == 1, "");
_Static_assert(sizeof(struct A4_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct A4_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A4_extra_size) == 3, "");
_Static_assert(_Alignof(struct A4_extra_size) == 1, "");
_Static_assert(sizeof(A5) == 33, "");
_Static_assert(_Alignof(A5) == 1, "");
_Static_assert(sizeof(struct A5_extra_alignment) == 34, "");
_Static_assert(_Alignof(struct A5_extra_alignment) == 1, "");
_Static_assert(sizeof(struct A5_extra_packed) == 33, "");
_Static_assert(_Alignof(struct A5_extra_packed) == 1, "");
_Static_assert(sizeof(struct A5_extra_required_alignment) == 34, "");
_Static_assert(_Alignof(struct A5_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A5_extra_size) == 35, "");
_Static_assert(_Alignof(struct A5_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A5,d) == 256, "");
#endif
_Static_assert(sizeof(A7) == 32, "");
_Static_assert(_Alignof(A7) == 32, "");
_Static_assert(sizeof(struct A7_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct A7_extra_alignment) == 32, "");
_Static_assert(sizeof(struct A7_extra_packed) == 32, "");
_Static_assert(_Alignof(struct A7_extra_packed) == 1, "");
_Static_assert(sizeof(struct A7_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct A7_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A7_extra_size) == 34, "");
_Static_assert(_Alignof(struct A7_extra_size) == 1, "");
_Static_assert(sizeof(A8) == 8, "");
_Static_assert(_Alignof(A8) == 4, "");
_Static_assert(sizeof(struct A8_extra_alignment) == 12, "");
_Static_assert(_Alignof(struct A8_extra_alignment) == 4, "");
_Static_assert(sizeof(struct A8_extra_packed) == 8, "");
_Static_assert(_Alignof(struct A8_extra_packed) == 1, "");
_Static_assert(sizeof(struct A8_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct A8_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A8_extra_size) == 10, "");
_Static_assert(_Alignof(struct A8_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A8,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A8,j) == 39, "");
#endif
_Static_assert(sizeof(A9) == 12, "");
_Static_assert(_Alignof(A9) == 4, "");
_Static_assert(sizeof(struct A9_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct A9_extra_alignment) == 4, "");
_Static_assert(sizeof(struct A9_extra_packed) == 12, "");
_Static_assert(_Alignof(struct A9_extra_packed) == 1, "");
_Static_assert(sizeof(struct A9_extra_required_alignment) == 13, "");
_Static_assert(_Alignof(struct A9_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A9_extra_size) == 14, "");
_Static_assert(_Alignof(struct A9_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A9,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A9,j) == 64, "");
#endif
_Static_assert(sizeof(A10) == 4, "");
_Static_assert(_Alignof(A10) == 16, "");
_Static_assert(sizeof(struct A10_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct A10_extra_alignment) == 16, "");
_Static_assert(sizeof(struct A10_extra_packed) == 4, "");
_Static_assert(_Alignof(struct A10_extra_packed) == 1, "");
_Static_assert(sizeof(struct A10_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct A10_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A10_extra_size) == 6, "");
_Static_assert(_Alignof(struct A10_extra_size) == 1, "");
_Static_assert(sizeof(A11) == 32, "");
_Static_assert(_Alignof(A11) == 16, "");
_Static_assert(sizeof(struct A11_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct A11_extra_alignment) == 16, "");
_Static_assert(sizeof(struct A11_extra_packed) == 32, "");
_Static_assert(_Alignof(struct A11_extra_packed) == 1, "");
_Static_assert(sizeof(struct A11_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct A11_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A11_extra_size) == 34, "");
_Static_assert(_Alignof(struct A11_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A11,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A11,j) == 128, "");
#endif
_Static_assert(sizeof(A12) == 32, "");
_Static_assert(_Alignof(A12) == 16, "");
_Static_assert(sizeof(struct A12_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct A12_extra_alignment) == 16, "");
_Static_assert(sizeof(struct A12_extra_packed) == 32, "");
_Static_assert(_Alignof(struct A12_extra_packed) == 1, "");
_Static_assert(sizeof(struct A12_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct A12_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A12_extra_size) == 34, "");
_Static_assert(_Alignof(struct A12_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A12,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A12,j) == 128, "");
#endif
_Static_assert(sizeof(A13) == 32, "");
_Static_assert(_Alignof(A13) == 16, "");
_Static_assert(sizeof(struct A13_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct A13_extra_alignment) == 16, "");
_Static_assert(sizeof(struct A13_extra_packed) == 32, "");
_Static_assert(_Alignof(struct A13_extra_packed) == 1, "");
_Static_assert(sizeof(struct A13_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct A13_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A13_extra_size) == 34, "");
_Static_assert(_Alignof(struct A13_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A13,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A13,j) == 128, "");
_Static_assert(__builtin_bitoffsetof(A13,d) == 136, "");
#endif
// MAPPING|ELEVEN|x86-i686-windows-gnu:Gcc|x86_64-x86_64-windows-gnu:Gcc|END
// repr targets I686PcWindowsGnu|Some("x86-i686-windows-gnu") X86_64PcWindowsGnu|Some("x86_64-x86_64-windows-gnu") 
#elif defined(ELEVEN)
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
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A,d) == 0, "");
#endif
_Static_assert(sizeof(A_) == 5, "");
_Static_assert(_Alignof(A_) == 1, "");
_Static_assert(sizeof(struct A__extra_alignment) == 6, "");
_Static_assert(_Alignof(struct A__extra_alignment) == 1, "");
_Static_assert(sizeof(struct A__extra_packed) == 5, "");
_Static_assert(_Alignof(struct A__extra_packed) == 1, "");
_Static_assert(sizeof(struct A__extra_required_alignment) == 6, "");
_Static_assert(_Alignof(struct A__extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A__extra_size) == 7, "");
_Static_assert(_Alignof(struct A__extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_,d) == 32, "");
#endif
_Static_assert(sizeof(B) == 1, "");
_Static_assert(_Alignof(B) == 1, "");
_Static_assert(sizeof(struct B_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct B_extra_alignment) == 1, "");
_Static_assert(sizeof(struct B_extra_packed) == 1, "");
_Static_assert(_Alignof(struct B_extra_packed) == 1, "");
_Static_assert(sizeof(struct B_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct B_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B_extra_size) == 3, "");
_Static_assert(_Alignof(struct B_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B,d) == 0, "");
#endif
_Static_assert(sizeof(B_) == 5, "");
_Static_assert(_Alignof(B_) == 1, "");
_Static_assert(sizeof(struct B__extra_alignment) == 6, "");
_Static_assert(_Alignof(struct B__extra_alignment) == 1, "");
_Static_assert(sizeof(struct B__extra_packed) == 5, "");
_Static_assert(_Alignof(struct B__extra_packed) == 1, "");
_Static_assert(sizeof(struct B__extra_required_alignment) == 6, "");
_Static_assert(_Alignof(struct B__extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B__extra_size) == 7, "");
_Static_assert(_Alignof(struct B__extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B_,d) == 32, "");
#endif
_Static_assert(sizeof(C) == 1, "");
_Static_assert(_Alignof(C) == 1, "");
_Static_assert(sizeof(struct C_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct C_extra_alignment) == 1, "");
_Static_assert(sizeof(struct C_extra_packed) == 1, "");
_Static_assert(_Alignof(struct C_extra_packed) == 1, "");
_Static_assert(sizeof(struct C_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct C_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct C_extra_size) == 3, "");
_Static_assert(_Alignof(struct C_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(C,d) == 0, "");
#endif
_Static_assert(sizeof(C_) == 2, "");
_Static_assert(_Alignof(C_) == 1, "");
_Static_assert(sizeof(struct C__extra_alignment) == 3, "");
_Static_assert(_Alignof(struct C__extra_alignment) == 1, "");
_Static_assert(sizeof(struct C__extra_packed) == 2, "");
_Static_assert(_Alignof(struct C__extra_packed) == 1, "");
_Static_assert(sizeof(struct C__extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct C__extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct C__extra_size) == 4, "");
_Static_assert(_Alignof(struct C__extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(C_,d) == 8, "");
#endif
_Static_assert(sizeof(D) == 24, "");
_Static_assert(_Alignof(D) == 8, "");
_Static_assert(sizeof(struct D_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct D_extra_alignment) == 8, "");
_Static_assert(sizeof(struct D_extra_packed) == 24, "");
_Static_assert(_Alignof(struct D_extra_packed) == 1, "");
_Static_assert(sizeof(struct D_extra_required_alignment) == 25, "");
_Static_assert(_Alignof(struct D_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct D_extra_size) == 26, "");
_Static_assert(_Alignof(struct D_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(D,d) == 64, "");
_Static_assert(__builtin_bitoffsetof(D,e) == 128, "");
#endif
_Static_assert(sizeof(F) == 32, "");
_Static_assert(_Alignof(F) == 16, "");
_Static_assert(sizeof(struct F_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct F_extra_alignment) == 16, "");
_Static_assert(sizeof(struct F_extra_packed) == 32, "");
_Static_assert(_Alignof(struct F_extra_packed) == 1, "");
_Static_assert(sizeof(struct F_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct F_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct F_extra_size) == 34, "");
_Static_assert(_Alignof(struct F_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(F,d) == 128, "");
_Static_assert(__builtin_bitoffsetof(F,e) == 192, "");
#endif
_Static_assert(sizeof(G) == 12, "");
_Static_assert(_Alignof(G) == 2, "");
_Static_assert(sizeof(struct G_extra_alignment) == 14, "");
_Static_assert(_Alignof(struct G_extra_alignment) == 2, "");
_Static_assert(sizeof(struct G_extra_packed) == 12, "");
_Static_assert(_Alignof(struct G_extra_packed) == 1, "");
_Static_assert(sizeof(struct G_extra_required_alignment) == 13, "");
_Static_assert(_Alignof(struct G_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct G_extra_size) == 14, "");
_Static_assert(_Alignof(struct G_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(G,d) == 16, "");
_Static_assert(__builtin_bitoffsetof(G,e) == 80, "");
#endif
_Static_assert(sizeof(H) == 12, "");
_Static_assert(_Alignof(H) == 2, "");
_Static_assert(sizeof(struct H_extra_alignment) == 14, "");
_Static_assert(_Alignof(struct H_extra_alignment) == 2, "");
_Static_assert(sizeof(struct H_extra_packed) == 12, "");
_Static_assert(_Alignof(struct H_extra_packed) == 1, "");
_Static_assert(sizeof(struct H_extra_required_alignment) == 13, "");
_Static_assert(_Alignof(struct H_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct H_extra_size) == 14, "");
_Static_assert(_Alignof(struct H_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(H,d) == 16, "");
_Static_assert(__builtin_bitoffsetof(H,e) == 80, "");
#endif
_Static_assert(sizeof(I) == 10, "");
_Static_assert(_Alignof(I) == 1, "");
_Static_assert(sizeof(struct I_extra_alignment) == 11, "");
_Static_assert(_Alignof(struct I_extra_alignment) == 1, "");
_Static_assert(sizeof(struct I_extra_packed) == 10, "");
_Static_assert(_Alignof(struct I_extra_packed) == 1, "");
_Static_assert(sizeof(struct I_extra_required_alignment) == 11, "");
_Static_assert(_Alignof(struct I_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct I_extra_size) == 12, "");
_Static_assert(_Alignof(struct I_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(I,d) == 8, "");
_Static_assert(__builtin_bitoffsetof(I,e) == 72, "");
#endif
_Static_assert(sizeof(J) == 12, "");
_Static_assert(_Alignof(J) == 2, "");
_Static_assert(sizeof(struct J_extra_alignment) == 14, "");
_Static_assert(_Alignof(struct J_extra_alignment) == 2, "");
_Static_assert(sizeof(struct J_extra_packed) == 12, "");
_Static_assert(_Alignof(struct J_extra_packed) == 1, "");
_Static_assert(sizeof(struct J_extra_required_alignment) == 13, "");
_Static_assert(_Alignof(struct J_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct J_extra_size) == 14, "");
_Static_assert(_Alignof(struct J_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(J,d) == 16, "");
_Static_assert(__builtin_bitoffsetof(J,e) == 80, "");
#endif
_Static_assert(sizeof(K) == 24, "");
_Static_assert(_Alignof(K) == 8, "");
_Static_assert(sizeof(struct K_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct K_extra_alignment) == 8, "");
_Static_assert(sizeof(struct K_extra_packed) == 24, "");
_Static_assert(_Alignof(struct K_extra_packed) == 1, "");
_Static_assert(sizeof(struct K_extra_required_alignment) == 25, "");
_Static_assert(_Alignof(struct K_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct K_extra_size) == 26, "");
_Static_assert(_Alignof(struct K_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(K,d) == 64, "");
_Static_assert(__builtin_bitoffsetof(K,e) == 128, "");
#endif
_Static_assert(sizeof(L) == 32, "");
_Static_assert(_Alignof(L) == 16, "");
_Static_assert(sizeof(struct L_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct L_extra_alignment) == 16, "");
_Static_assert(sizeof(struct L_extra_packed) == 32, "");
_Static_assert(_Alignof(struct L_extra_packed) == 1, "");
_Static_assert(sizeof(struct L_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct L_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct L_extra_size) == 34, "");
_Static_assert(_Alignof(struct L_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(L,d) == 128, "");
_Static_assert(__builtin_bitoffsetof(L,e) == 192, "");
#endif
_Static_assert(sizeof(M) == 11, "");
_Static_assert(_Alignof(M) == 1, "");
_Static_assert(sizeof(struct M_extra_alignment) == 12, "");
_Static_assert(_Alignof(struct M_extra_alignment) == 1, "");
_Static_assert(sizeof(struct M_extra_packed) == 11, "");
_Static_assert(_Alignof(struct M_extra_packed) == 1, "");
_Static_assert(sizeof(struct M_extra_required_alignment) == 12, "");
_Static_assert(_Alignof(struct M_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct M_extra_size) == 13, "");
_Static_assert(_Alignof(struct M_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(M,d) == 16, "");
_Static_assert(__builtin_bitoffsetof(M,e) == 80, "");
#endif
_Static_assert(sizeof(N) == 11, "");
_Static_assert(_Alignof(N) == 1, "");
_Static_assert(sizeof(struct N_extra_alignment) == 12, "");
_Static_assert(_Alignof(struct N_extra_alignment) == 1, "");
_Static_assert(sizeof(struct N_extra_packed) == 11, "");
_Static_assert(_Alignof(struct N_extra_packed) == 1, "");
_Static_assert(sizeof(struct N_extra_required_alignment) == 12, "");
_Static_assert(_Alignof(struct N_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct N_extra_size) == 13, "");
_Static_assert(_Alignof(struct N_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(N,d) == 16, "");
_Static_assert(__builtin_bitoffsetof(N,e) == 80, "");
#endif
_Static_assert(sizeof(O) == 10, "");
_Static_assert(_Alignof(O) == 1, "");
_Static_assert(sizeof(struct O_extra_alignment) == 11, "");
_Static_assert(_Alignof(struct O_extra_alignment) == 1, "");
_Static_assert(sizeof(struct O_extra_packed) == 10, "");
_Static_assert(_Alignof(struct O_extra_packed) == 1, "");
_Static_assert(sizeof(struct O_extra_required_alignment) == 11, "");
_Static_assert(_Alignof(struct O_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct O_extra_size) == 12, "");
_Static_assert(_Alignof(struct O_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(O,d) == 8, "");
_Static_assert(__builtin_bitoffsetof(O,e) == 72, "");
#endif
_Static_assert(sizeof(P) == 12, "");
_Static_assert(_Alignof(P) == 2, "");
_Static_assert(sizeof(struct P_extra_alignment) == 14, "");
_Static_assert(_Alignof(struct P_extra_alignment) == 2, "");
_Static_assert(sizeof(struct P_extra_packed) == 12, "");
_Static_assert(_Alignof(struct P_extra_packed) == 1, "");
_Static_assert(sizeof(struct P_extra_required_alignment) == 13, "");
_Static_assert(_Alignof(struct P_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct P_extra_size) == 14, "");
_Static_assert(_Alignof(struct P_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(P,d) == 16, "");
_Static_assert(__builtin_bitoffsetof(P,e) == 80, "");
#endif
_Static_assert(sizeof(Q) == 24, "");
_Static_assert(_Alignof(Q) == 8, "");
_Static_assert(sizeof(struct Q_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct Q_extra_alignment) == 8, "");
_Static_assert(sizeof(struct Q_extra_packed) == 24, "");
_Static_assert(_Alignof(struct Q_extra_packed) == 1, "");
_Static_assert(sizeof(struct Q_extra_required_alignment) == 25, "");
_Static_assert(_Alignof(struct Q_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct Q_extra_size) == 26, "");
_Static_assert(_Alignof(struct Q_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(Q,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(Q,d) == 64, "");
_Static_assert(__builtin_bitoffsetof(Q,e) == 128, "");
#endif
_Static_assert(sizeof(R) == 32, "");
_Static_assert(_Alignof(R) == 16, "");
_Static_assert(sizeof(struct R_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct R_extra_alignment) == 16, "");
_Static_assert(sizeof(struct R_extra_packed) == 32, "");
_Static_assert(_Alignof(struct R_extra_packed) == 1, "");
_Static_assert(sizeof(struct R_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct R_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct R_extra_size) == 34, "");
_Static_assert(_Alignof(struct R_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(R,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(R,e) == 128, "");
#endif
_Static_assert(sizeof(S) == 8, "");
_Static_assert(_Alignof(S) == 8, "");
_Static_assert(sizeof(struct S_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct S_extra_alignment) == 8, "");
_Static_assert(sizeof(struct S_extra_packed) == 8, "");
_Static_assert(_Alignof(struct S_extra_packed) == 1, "");
_Static_assert(sizeof(struct S_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct S_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct S_extra_size) == 10, "");
_Static_assert(_Alignof(struct S_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(S,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(S,e) == 16, "");
#endif
_Static_assert(sizeof(T) == 4, "");
_Static_assert(_Alignof(T) == 2, "");
_Static_assert(sizeof(struct T_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct T_extra_alignment) == 2, "");
_Static_assert(sizeof(struct T_extra_packed) == 4, "");
_Static_assert(_Alignof(struct T_extra_packed) == 1, "");
_Static_assert(sizeof(struct T_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct T_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct T_extra_size) == 6, "");
_Static_assert(_Alignof(struct T_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(T,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(T,e) == 16, "");
#endif
_Static_assert(sizeof(U) == 8, "");
_Static_assert(_Alignof(U) == 8, "");
_Static_assert(sizeof(struct U_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct U_extra_alignment) == 8, "");
_Static_assert(sizeof(struct U_extra_packed) == 8, "");
_Static_assert(_Alignof(struct U_extra_packed) == 1, "");
_Static_assert(sizeof(struct U_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct U_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct U_extra_size) == 10, "");
_Static_assert(_Alignof(struct U_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(U,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(U,e) == 16, "");
#endif
_Static_assert(sizeof(V) == 4, "");
_Static_assert(_Alignof(V) == 2, "");
_Static_assert(sizeof(struct V_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct V_extra_alignment) == 2, "");
_Static_assert(sizeof(struct V_extra_packed) == 4, "");
_Static_assert(_Alignof(struct V_extra_packed) == 1, "");
_Static_assert(sizeof(struct V_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct V_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct V_extra_size) == 6, "");
_Static_assert(_Alignof(struct V_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(V,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(V,e) == 16, "");
#endif
_Static_assert(sizeof(W) == 32, "");
_Static_assert(_Alignof(W) == 16, "");
_Static_assert(sizeof(struct W_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct W_extra_alignment) == 16, "");
_Static_assert(sizeof(struct W_extra_packed) == 32, "");
_Static_assert(_Alignof(struct W_extra_packed) == 1, "");
_Static_assert(sizeof(struct W_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct W_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct W_extra_size) == 34, "");
_Static_assert(_Alignof(struct W_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(W,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(W,e) == 128, "");
#endif
_Static_assert(sizeof(W_) == 2, "");
_Static_assert(_Alignof(W_) == 1, "");
_Static_assert(sizeof(struct W__extra_alignment) == 3, "");
_Static_assert(_Alignof(struct W__extra_alignment) == 1, "");
_Static_assert(sizeof(struct W__extra_packed) == 2, "");
_Static_assert(_Alignof(struct W__extra_packed) == 1, "");
_Static_assert(sizeof(struct W__extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct W__extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct W__extra_size) == 4, "");
_Static_assert(_Alignof(struct W__extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(W_,e) == 8, "");
#endif
_Static_assert(sizeof(X) == 4, "");
_Static_assert(_Alignof(X) == 2, "");
_Static_assert(sizeof(struct X_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct X_extra_alignment) == 2, "");
_Static_assert(sizeof(struct X_extra_packed) == 4, "");
_Static_assert(_Alignof(struct X_extra_packed) == 1, "");
_Static_assert(sizeof(struct X_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct X_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct X_extra_size) == 6, "");
_Static_assert(_Alignof(struct X_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(X,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(X,e) == 16, "");
#endif
_Static_assert(sizeof(A2) == 1, "");
_Static_assert(_Alignof(A2) == 1, "");
_Static_assert(sizeof(struct A2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct A2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct A2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct A2_extra_packed) == 1, "");
_Static_assert(sizeof(struct A2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct A2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A2_extra_size) == 3, "");
_Static_assert(_Alignof(struct A2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A2,d) == 0, "");
#endif
_Static_assert(sizeof(A_2) == 1, "");
_Static_assert(_Alignof(A_2) == 1, "");
_Static_assert(sizeof(struct A_2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct A_2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct A_2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct A_2_extra_packed) == 1, "");
_Static_assert(sizeof(struct A_2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct A_2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A_2_extra_size) == 3, "");
_Static_assert(_Alignof(struct A_2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_2,d) == 0, "");
#endif
_Static_assert(sizeof(B2) == 1, "");
_Static_assert(_Alignof(B2) == 1, "");
_Static_assert(sizeof(struct B2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct B2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct B2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct B2_extra_packed) == 1, "");
_Static_assert(sizeof(struct B2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct B2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B2_extra_size) == 3, "");
_Static_assert(_Alignof(struct B2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B2,d) == 0, "");
#endif
_Static_assert(sizeof(B_2) == 1, "");
_Static_assert(_Alignof(B_2) == 1, "");
_Static_assert(sizeof(struct B_2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct B_2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct B_2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct B_2_extra_packed) == 1, "");
_Static_assert(sizeof(struct B_2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct B_2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B_2_extra_size) == 3, "");
_Static_assert(_Alignof(struct B_2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B_2,d) == 0, "");
#endif
_Static_assert(sizeof(C2) == 1, "");
_Static_assert(_Alignof(C2) == 1, "");
_Static_assert(sizeof(struct C2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct C2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct C2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct C2_extra_packed) == 1, "");
_Static_assert(sizeof(struct C2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct C2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct C2_extra_size) == 3, "");
_Static_assert(_Alignof(struct C2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(C2,d) == 0, "");
#endif
_Static_assert(sizeof(C22) == 1, "");
_Static_assert(_Alignof(C22) == 1, "");
_Static_assert(sizeof(struct C22_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct C22_extra_alignment) == 1, "");
_Static_assert(sizeof(struct C22_extra_packed) == 1, "");
_Static_assert(_Alignof(struct C22_extra_packed) == 1, "");
_Static_assert(sizeof(struct C22_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct C22_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct C22_extra_size) == 3, "");
_Static_assert(_Alignof(struct C22_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(C22,d) == 0, "");
#endif
_Static_assert(sizeof(D2) == 8, "");
_Static_assert(_Alignof(D2) == 8, "");
_Static_assert(sizeof(struct D2_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct D2_extra_alignment) == 8, "");
_Static_assert(sizeof(struct D2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct D2_extra_packed) == 1, "");
_Static_assert(sizeof(struct D2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct D2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct D2_extra_size) == 10, "");
_Static_assert(_Alignof(struct D2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(D2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(D2,e) == 0, "");
#endif
_Static_assert(sizeof(F2) == 16, "");
_Static_assert(_Alignof(F2) == 16, "");
_Static_assert(sizeof(struct F2_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct F2_extra_alignment) == 16, "");
_Static_assert(sizeof(struct F2_extra_packed) == 16, "");
_Static_assert(_Alignof(struct F2_extra_packed) == 1, "");
_Static_assert(sizeof(struct F2_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct F2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct F2_extra_size) == 18, "");
_Static_assert(_Alignof(struct F2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(F2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(F2,e) == 0, "");
#endif
_Static_assert(sizeof(G2) == 8, "");
_Static_assert(_Alignof(G2) == 2, "");
_Static_assert(sizeof(struct G2_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct G2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct G2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct G2_extra_packed) == 1, "");
_Static_assert(sizeof(struct G2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct G2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct G2_extra_size) == 10, "");
_Static_assert(_Alignof(struct G2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(G2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(G2,e) == 0, "");
#endif
_Static_assert(sizeof(H2) == 8, "");
_Static_assert(_Alignof(H2) == 2, "");
_Static_assert(sizeof(struct H2_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct H2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct H2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct H2_extra_packed) == 1, "");
_Static_assert(sizeof(struct H2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct H2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct H2_extra_size) == 10, "");
_Static_assert(_Alignof(struct H2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(H2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(H2,e) == 0, "");
#endif
_Static_assert(sizeof(I2) == 8, "");
_Static_assert(_Alignof(I2) == 1, "");
_Static_assert(sizeof(struct I2_extra_alignment) == 9, "");
_Static_assert(_Alignof(struct I2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct I2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct I2_extra_packed) == 1, "");
_Static_assert(sizeof(struct I2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct I2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct I2_extra_size) == 10, "");
_Static_assert(_Alignof(struct I2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(I2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(I2,e) == 0, "");
#endif
_Static_assert(sizeof(J2) == 8, "");
_Static_assert(_Alignof(J2) == 2, "");
_Static_assert(sizeof(struct J2_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct J2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct J2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct J2_extra_packed) == 1, "");
_Static_assert(sizeof(struct J2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct J2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct J2_extra_size) == 10, "");
_Static_assert(_Alignof(struct J2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(J2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(J2,e) == 0, "");
#endif
_Static_assert(sizeof(K2) == 8, "");
_Static_assert(_Alignof(K2) == 8, "");
_Static_assert(sizeof(struct K2_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct K2_extra_alignment) == 8, "");
_Static_assert(sizeof(struct K2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct K2_extra_packed) == 1, "");
_Static_assert(sizeof(struct K2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct K2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct K2_extra_size) == 10, "");
_Static_assert(_Alignof(struct K2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(K2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(K2,e) == 0, "");
#endif
_Static_assert(sizeof(L2) == 16, "");
_Static_assert(_Alignof(L2) == 16, "");
_Static_assert(sizeof(struct L2_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct L2_extra_alignment) == 16, "");
_Static_assert(sizeof(struct L2_extra_packed) == 16, "");
_Static_assert(_Alignof(struct L2_extra_packed) == 1, "");
_Static_assert(sizeof(struct L2_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct L2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct L2_extra_size) == 18, "");
_Static_assert(_Alignof(struct L2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(L2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(L2,e) == 0, "");
#endif
_Static_assert(sizeof(M2) == 1, "");
_Static_assert(_Alignof(M2) == 1, "");
_Static_assert(sizeof(struct M2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct M2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct M2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct M2_extra_packed) == 1, "");
_Static_assert(sizeof(struct M2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct M2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct M2_extra_size) == 3, "");
_Static_assert(_Alignof(struct M2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(M2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(M2,e) == 0, "");
#endif
_Static_assert(sizeof(N2) == 1, "");
_Static_assert(_Alignof(N2) == 1, "");
_Static_assert(sizeof(struct N2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct N2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct N2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct N2_extra_packed) == 1, "");
_Static_assert(sizeof(struct N2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct N2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct N2_extra_size) == 3, "");
_Static_assert(_Alignof(struct N2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(N2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(N2,e) == 0, "");
#endif
_Static_assert(sizeof(O2) == 1, "");
_Static_assert(_Alignof(O2) == 1, "");
_Static_assert(sizeof(struct O2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct O2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct O2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct O2_extra_packed) == 1, "");
_Static_assert(sizeof(struct O2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct O2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct O2_extra_size) == 3, "");
_Static_assert(_Alignof(struct O2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(O2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(O2,e) == 0, "");
#endif
_Static_assert(sizeof(P2) == 2, "");
_Static_assert(_Alignof(P2) == 2, "");
_Static_assert(sizeof(struct P2_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct P2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct P2_extra_packed) == 2, "");
_Static_assert(_Alignof(struct P2_extra_packed) == 1, "");
_Static_assert(sizeof(struct P2_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct P2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct P2_extra_size) == 4, "");
_Static_assert(_Alignof(struct P2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(P2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(P2,e) == 0, "");
#endif
_Static_assert(sizeof(Q2) == 8, "");
_Static_assert(_Alignof(Q2) == 8, "");
_Static_assert(sizeof(struct Q2_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct Q2_extra_alignment) == 8, "");
_Static_assert(sizeof(struct Q2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct Q2_extra_packed) == 1, "");
_Static_assert(sizeof(struct Q2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct Q2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct Q2_extra_size) == 10, "");
_Static_assert(_Alignof(struct Q2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(Q2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(Q2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(Q2,e) == 0, "");
#endif
_Static_assert(sizeof(R2) == 1, "");
_Static_assert(_Alignof(R2) == 1, "");
_Static_assert(sizeof(struct R2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct R2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct R2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct R2_extra_packed) == 1, "");
_Static_assert(sizeof(struct R2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct R2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct R2_extra_size) == 3, "");
_Static_assert(_Alignof(struct R2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(R2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(R2,e) == 0, "");
#endif
_Static_assert(sizeof(S2) == 1, "");
_Static_assert(_Alignof(S2) == 1, "");
_Static_assert(sizeof(struct S2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct S2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct S2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct S2_extra_packed) == 1, "");
_Static_assert(sizeof(struct S2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct S2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct S2_extra_size) == 3, "");
_Static_assert(_Alignof(struct S2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(S2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(S2,e) == 0, "");
#endif
_Static_assert(sizeof(T2) == 1, "");
_Static_assert(_Alignof(T2) == 1, "");
_Static_assert(sizeof(struct T2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct T2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct T2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct T2_extra_packed) == 1, "");
_Static_assert(sizeof(struct T2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct T2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct T2_extra_size) == 3, "");
_Static_assert(_Alignof(struct T2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(T2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(T2,e) == 0, "");
#endif
_Static_assert(sizeof(U2) == 1, "");
_Static_assert(_Alignof(U2) == 1, "");
_Static_assert(sizeof(struct U2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct U2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct U2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct U2_extra_packed) == 1, "");
_Static_assert(sizeof(struct U2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct U2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct U2_extra_size) == 3, "");
_Static_assert(_Alignof(struct U2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(U2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(U2,e) == 0, "");
#endif
_Static_assert(sizeof(V2) == 1, "");
_Static_assert(_Alignof(V2) == 1, "");
_Static_assert(sizeof(struct V2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct V2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct V2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct V2_extra_packed) == 1, "");
_Static_assert(sizeof(struct V2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct V2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct V2_extra_size) == 3, "");
_Static_assert(_Alignof(struct V2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(V2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(V2,e) == 0, "");
#endif
_Static_assert(sizeof(W2) == 1, "");
_Static_assert(_Alignof(W2) == 1, "");
_Static_assert(sizeof(struct W2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct W2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct W2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct W2_extra_packed) == 1, "");
_Static_assert(sizeof(struct W2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct W2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct W2_extra_size) == 3, "");
_Static_assert(_Alignof(struct W2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(W2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(W2,e) == 0, "");
#endif
_Static_assert(sizeof(W_2) == 1, "");
_Static_assert(_Alignof(W_2) == 1, "");
_Static_assert(sizeof(struct W_2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct W_2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct W_2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct W_2_extra_packed) == 1, "");
_Static_assert(sizeof(struct W_2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct W_2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct W_2_extra_size) == 3, "");
_Static_assert(_Alignof(struct W_2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(W_2,e) == 0, "");
#endif
_Static_assert(sizeof(X2) == 1, "");
_Static_assert(_Alignof(X2) == 1, "");
_Static_assert(sizeof(struct X2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct X2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct X2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct X2_extra_packed) == 1, "");
_Static_assert(sizeof(struct X2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct X2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct X2_extra_size) == 3, "");
_Static_assert(_Alignof(struct X2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(X2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(X2,e) == 0, "");
#endif
_Static_assert(sizeof(Y) == 8, "");
_Static_assert(_Alignof(Y) == 8, "");
_Static_assert(sizeof(struct Y_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct Y_extra_alignment) == 8, "");
_Static_assert(sizeof(struct Y_extra_packed) == 8, "");
_Static_assert(_Alignof(struct Y_extra_packed) == 1, "");
_Static_assert(sizeof(struct Y_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct Y_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct Y_extra_size) == 10, "");
_Static_assert(_Alignof(struct Y_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(Y,d) == 8, "");
#endif
_Static_assert(sizeof(Y2) == 1, "");
_Static_assert(_Alignof(Y2) == 1, "");
_Static_assert(sizeof(struct Y2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct Y2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct Y2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct Y2_extra_packed) == 1, "");
_Static_assert(sizeof(struct Y2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct Y2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct Y2_extra_size) == 3, "");
_Static_assert(_Alignof(struct Y2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(Y2,d) == 0, "");
#endif
_Static_assert(sizeof(A3) == 64, "");
_Static_assert(_Alignof(A3) == 32, "");
_Static_assert(sizeof(struct A3_extra_alignment) == 96, "");
_Static_assert(_Alignof(struct A3_extra_alignment) == 32, "");
_Static_assert(sizeof(struct A3_extra_packed) == 64, "");
_Static_assert(_Alignof(struct A3_extra_packed) == 1, "");
_Static_assert(sizeof(struct A3_extra_required_alignment) == 65, "");
_Static_assert(_Alignof(struct A3_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A3_extra_size) == 66, "");
_Static_assert(_Alignof(struct A3_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A3,d) == 256, "");
#endif
_Static_assert(sizeof(A4) == 1, "");
_Static_assert(_Alignof(A4) == 32, "");
_Static_assert(sizeof(struct A4_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct A4_extra_alignment) == 32, "");
_Static_assert(sizeof(struct A4_extra_packed) == 1, "");
_Static_assert(_Alignof(struct A4_extra_packed) == 1, "");
_Static_assert(sizeof(struct A4_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct A4_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A4_extra_size) == 3, "");
_Static_assert(_Alignof(struct A4_extra_size) == 1, "");
_Static_assert(sizeof(A5) == 32, "");
_Static_assert(_Alignof(A5) == 32, "");
_Static_assert(sizeof(struct A5_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct A5_extra_alignment) == 32, "");
_Static_assert(sizeof(struct A5_extra_packed) == 32, "");
_Static_assert(_Alignof(struct A5_extra_packed) == 1, "");
_Static_assert(sizeof(struct A5_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct A5_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A5_extra_size) == 34, "");
_Static_assert(_Alignof(struct A5_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A5,d) == 8, "");
#endif
_Static_assert(sizeof(A7) == 32, "");
_Static_assert(_Alignof(A7) == 32, "");
_Static_assert(sizeof(struct A7_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct A7_extra_alignment) == 32, "");
_Static_assert(sizeof(struct A7_extra_packed) == 32, "");
_Static_assert(_Alignof(struct A7_extra_packed) == 1, "");
_Static_assert(sizeof(struct A7_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct A7_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A7_extra_size) == 34, "");
_Static_assert(_Alignof(struct A7_extra_size) == 1, "");
_Static_assert(sizeof(A8) == 12, "");
_Static_assert(_Alignof(A8) == 4, "");
_Static_assert(sizeof(struct A8_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct A8_extra_alignment) == 4, "");
_Static_assert(sizeof(struct A8_extra_packed) == 12, "");
_Static_assert(_Alignof(struct A8_extra_packed) == 1, "");
_Static_assert(sizeof(struct A8_extra_required_alignment) == 13, "");
_Static_assert(_Alignof(struct A8_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A8_extra_size) == 14, "");
_Static_assert(_Alignof(struct A8_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A8,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A8,j) == 40, "");
#endif
_Static_assert(sizeof(A9) == 12, "");
_Static_assert(_Alignof(A9) == 4, "");
_Static_assert(sizeof(struct A9_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct A9_extra_alignment) == 4, "");
_Static_assert(sizeof(struct A9_extra_packed) == 12, "");
_Static_assert(_Alignof(struct A9_extra_packed) == 1, "");
_Static_assert(sizeof(struct A9_extra_required_alignment) == 13, "");
_Static_assert(_Alignof(struct A9_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A9_extra_size) == 14, "");
_Static_assert(_Alignof(struct A9_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A9,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A9,j) == 64, "");
#endif
_Static_assert(sizeof(A10) == 4, "");
_Static_assert(_Alignof(A10) == 16, "");
_Static_assert(sizeof(struct A10_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct A10_extra_alignment) == 16, "");
_Static_assert(sizeof(struct A10_extra_packed) == 4, "");
_Static_assert(_Alignof(struct A10_extra_packed) == 1, "");
_Static_assert(sizeof(struct A10_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct A10_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A10_extra_size) == 6, "");
_Static_assert(_Alignof(struct A10_extra_size) == 1, "");
_Static_assert(sizeof(A11) == 16, "");
_Static_assert(_Alignof(A11) == 16, "");
_Static_assert(sizeof(struct A11_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct A11_extra_alignment) == 16, "");
_Static_assert(sizeof(struct A11_extra_packed) == 16, "");
_Static_assert(_Alignof(struct A11_extra_packed) == 1, "");
_Static_assert(sizeof(struct A11_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct A11_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A11_extra_size) == 18, "");
_Static_assert(_Alignof(struct A11_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A11,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A11,j) == 40, "");
#endif
_Static_assert(sizeof(A12) == 32, "");
_Static_assert(_Alignof(A12) == 16, "");
_Static_assert(sizeof(struct A12_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct A12_extra_alignment) == 16, "");
_Static_assert(sizeof(struct A12_extra_packed) == 32, "");
_Static_assert(_Alignof(struct A12_extra_packed) == 1, "");
_Static_assert(sizeof(struct A12_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct A12_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A12_extra_size) == 34, "");
_Static_assert(_Alignof(struct A12_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A12,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A12,j) == 128, "");
#endif
_Static_assert(sizeof(A13) == 16, "");
_Static_assert(_Alignof(A13) == 16, "");
_Static_assert(sizeof(struct A13_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct A13_extra_alignment) == 16, "");
_Static_assert(sizeof(struct A13_extra_packed) == 16, "");
_Static_assert(_Alignof(struct A13_extra_packed) == 1, "");
_Static_assert(sizeof(struct A13_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct A13_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A13_extra_size) == 18, "");
_Static_assert(_Alignof(struct A13_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A13,i) == 32, "");
_Static_assert(__builtin_bitoffsetof(A13,j) == 33, "");
_Static_assert(__builtin_bitoffsetof(A13,d) == 64, "");
#endif
// MAPPING|TWELVE|mips64el-mips64-linux-gnuabi64:Gcc|mips64el-mips64-linux-musl:Gcc|mips64-mips64-linux-gnuabi64:Gcc|mips64-mips64-linux-musl:Gcc|mips-mips32-linux-gnuabi64:Gcc|mips-mips64r6-linux-gnuabi64:Gcc|powerpc64le-ppc64le-linux-gnu:Gcc|powerpc64le-ppc64le-linux-musl:Gcc|powerpc64-ppc64-linux-gnu:Gcc|powerpc64-ppc64-linux-musl:Gcc|riscv64-baseline_rv64-linux-gnu:Gcc|s390x-generic-linux-gnu:Gcc|sparc64-v9-linux-gnu:Gcc|x86_64-x86_64-linux-gnu:Gcc|x86_64-x86_64-linux-musl:Gcc|END
// repr targets Mips64elUnknownLinuxGnuabi64|Some("mips64el-mips64-linux-gnuabi64") Mips64elUnknownLinuxMusl|Some("mips64el-mips64-linux-musl") Mips64UnknownLinuxGnuabi64|Some("mips64-mips64-linux-gnuabi64") Mips64UnknownLinuxMusl|Some("mips64-mips64-linux-musl") Mipsisa64r6elUnknownLinuxGnuabi64|Some("mips-mips32-linux-gnuabi64") Mipsisa64r6UnknownLinuxGnuabi64|Some("mips-mips64r6-linux-gnuabi64") Powerpc64leUnknownLinuxGnu|Some("powerpc64le-ppc64le-linux-gnu") Powerpc64leUnknownLinuxMusl|Some("powerpc64le-ppc64le-linux-musl") Powerpc64UnknownLinuxGnu|Some("powerpc64-ppc64-linux-gnu") Powerpc64UnknownLinuxMusl|Some("powerpc64-ppc64-linux-musl") Riscv64UnknownLinuxGnu|Some("riscv64-baseline_rv64-linux-gnu") S390xUnknownLinuxGnu|Some("s390x-generic-linux-gnu") Sparc64UnknownLinuxGnu|Some("sparc64-v9-linux-gnu") X86_64UnknownLinuxGnu|Some("x86_64-x86_64-linux-gnu") X86_64UnknownLinuxMusl|Some("x86_64-x86_64-linux-musl") 
#elif defined(TWELVE)
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
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A,d) == 0, "");
#endif
_Static_assert(sizeof(A_) == 5, "");
_Static_assert(_Alignof(A_) == 1, "");
_Static_assert(sizeof(struct A__extra_alignment) == 6, "");
_Static_assert(_Alignof(struct A__extra_alignment) == 1, "");
_Static_assert(sizeof(struct A__extra_packed) == 5, "");
_Static_assert(_Alignof(struct A__extra_packed) == 1, "");
_Static_assert(sizeof(struct A__extra_required_alignment) == 6, "");
_Static_assert(_Alignof(struct A__extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A__extra_size) == 7, "");
_Static_assert(_Alignof(struct A__extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_,d) == 32, "");
#endif
_Static_assert(sizeof(B) == 1, "");
_Static_assert(_Alignof(B) == 1, "");
_Static_assert(sizeof(struct B_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct B_extra_alignment) == 1, "");
_Static_assert(sizeof(struct B_extra_packed) == 1, "");
_Static_assert(_Alignof(struct B_extra_packed) == 1, "");
_Static_assert(sizeof(struct B_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct B_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B_extra_size) == 3, "");
_Static_assert(_Alignof(struct B_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B,d) == 0, "");
#endif
_Static_assert(sizeof(B_) == 9, "");
_Static_assert(_Alignof(B_) == 1, "");
_Static_assert(sizeof(struct B__extra_alignment) == 10, "");
_Static_assert(_Alignof(struct B__extra_alignment) == 1, "");
_Static_assert(sizeof(struct B__extra_packed) == 9, "");
_Static_assert(_Alignof(struct B__extra_packed) == 1, "");
_Static_assert(sizeof(struct B__extra_required_alignment) == 10, "");
_Static_assert(_Alignof(struct B__extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B__extra_size) == 11, "");
_Static_assert(_Alignof(struct B__extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B_,d) == 64, "");
#endif
_Static_assert(sizeof(C) == 1, "");
_Static_assert(_Alignof(C) == 1, "");
_Static_assert(sizeof(struct C_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct C_extra_alignment) == 1, "");
_Static_assert(sizeof(struct C_extra_packed) == 1, "");
_Static_assert(_Alignof(struct C_extra_packed) == 1, "");
_Static_assert(sizeof(struct C_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct C_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct C_extra_size) == 3, "");
_Static_assert(_Alignof(struct C_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(C,d) == 0, "");
#endif
_Static_assert(sizeof(C_) == 9, "");
_Static_assert(_Alignof(C_) == 1, "");
_Static_assert(sizeof(struct C__extra_alignment) == 10, "");
_Static_assert(_Alignof(struct C__extra_alignment) == 1, "");
_Static_assert(sizeof(struct C__extra_packed) == 9, "");
_Static_assert(_Alignof(struct C__extra_packed) == 1, "");
_Static_assert(sizeof(struct C__extra_required_alignment) == 10, "");
_Static_assert(_Alignof(struct C__extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct C__extra_size) == 11, "");
_Static_assert(_Alignof(struct C__extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(C_,d) == 64, "");
#endif
_Static_assert(sizeof(D) == 24, "");
_Static_assert(_Alignof(D) == 8, "");
_Static_assert(sizeof(struct D_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct D_extra_alignment) == 8, "");
_Static_assert(sizeof(struct D_extra_packed) == 24, "");
_Static_assert(_Alignof(struct D_extra_packed) == 1, "");
_Static_assert(sizeof(struct D_extra_required_alignment) == 25, "");
_Static_assert(_Alignof(struct D_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct D_extra_size) == 26, "");
_Static_assert(_Alignof(struct D_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(D,d) == 64, "");
_Static_assert(__builtin_bitoffsetof(D,e) == 128, "");
#endif
_Static_assert(sizeof(F) == 32, "");
_Static_assert(_Alignof(F) == 16, "");
_Static_assert(sizeof(struct F_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct F_extra_alignment) == 16, "");
_Static_assert(sizeof(struct F_extra_packed) == 32, "");
_Static_assert(_Alignof(struct F_extra_packed) == 1, "");
_Static_assert(sizeof(struct F_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct F_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct F_extra_size) == 34, "");
_Static_assert(_Alignof(struct F_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(F,d) == 128, "");
_Static_assert(__builtin_bitoffsetof(F,e) == 192, "");
#endif
_Static_assert(sizeof(G) == 12, "");
_Static_assert(_Alignof(G) == 2, "");
_Static_assert(sizeof(struct G_extra_alignment) == 14, "");
_Static_assert(_Alignof(struct G_extra_alignment) == 2, "");
_Static_assert(sizeof(struct G_extra_packed) == 12, "");
_Static_assert(_Alignof(struct G_extra_packed) == 1, "");
_Static_assert(sizeof(struct G_extra_required_alignment) == 13, "");
_Static_assert(_Alignof(struct G_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct G_extra_size) == 14, "");
_Static_assert(_Alignof(struct G_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(G,d) == 16, "");
_Static_assert(__builtin_bitoffsetof(G,e) == 80, "");
#endif
_Static_assert(sizeof(H) == 12, "");
_Static_assert(_Alignof(H) == 2, "");
_Static_assert(sizeof(struct H_extra_alignment) == 14, "");
_Static_assert(_Alignof(struct H_extra_alignment) == 2, "");
_Static_assert(sizeof(struct H_extra_packed) == 12, "");
_Static_assert(_Alignof(struct H_extra_packed) == 1, "");
_Static_assert(sizeof(struct H_extra_required_alignment) == 13, "");
_Static_assert(_Alignof(struct H_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct H_extra_size) == 14, "");
_Static_assert(_Alignof(struct H_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(H,d) == 16, "");
_Static_assert(__builtin_bitoffsetof(H,e) == 80, "");
#endif
_Static_assert(sizeof(I) == 10, "");
_Static_assert(_Alignof(I) == 1, "");
_Static_assert(sizeof(struct I_extra_alignment) == 11, "");
_Static_assert(_Alignof(struct I_extra_alignment) == 1, "");
_Static_assert(sizeof(struct I_extra_packed) == 10, "");
_Static_assert(_Alignof(struct I_extra_packed) == 1, "");
_Static_assert(sizeof(struct I_extra_required_alignment) == 11, "");
_Static_assert(_Alignof(struct I_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct I_extra_size) == 12, "");
_Static_assert(_Alignof(struct I_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(I,d) == 8, "");
_Static_assert(__builtin_bitoffsetof(I,e) == 72, "");
#endif
_Static_assert(sizeof(J) == 12, "");
_Static_assert(_Alignof(J) == 2, "");
_Static_assert(sizeof(struct J_extra_alignment) == 14, "");
_Static_assert(_Alignof(struct J_extra_alignment) == 2, "");
_Static_assert(sizeof(struct J_extra_packed) == 12, "");
_Static_assert(_Alignof(struct J_extra_packed) == 1, "");
_Static_assert(sizeof(struct J_extra_required_alignment) == 13, "");
_Static_assert(_Alignof(struct J_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct J_extra_size) == 14, "");
_Static_assert(_Alignof(struct J_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(J,d) == 16, "");
_Static_assert(__builtin_bitoffsetof(J,e) == 80, "");
#endif
_Static_assert(sizeof(K) == 8, "");
_Static_assert(_Alignof(K) == 8, "");
_Static_assert(sizeof(struct K_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct K_extra_alignment) == 8, "");
_Static_assert(sizeof(struct K_extra_packed) == 8, "");
_Static_assert(_Alignof(struct K_extra_packed) == 1, "");
_Static_assert(sizeof(struct K_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct K_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct K_extra_size) == 10, "");
_Static_assert(_Alignof(struct K_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(K,d) == 8, "");
_Static_assert(__builtin_bitoffsetof(K,e) == 16, "");
#endif
_Static_assert(sizeof(L) == 32, "");
_Static_assert(_Alignof(L) == 16, "");
_Static_assert(sizeof(struct L_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct L_extra_alignment) == 16, "");
_Static_assert(sizeof(struct L_extra_packed) == 32, "");
_Static_assert(_Alignof(struct L_extra_packed) == 1, "");
_Static_assert(sizeof(struct L_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct L_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct L_extra_size) == 34, "");
_Static_assert(_Alignof(struct L_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(L,d) == 128, "");
_Static_assert(__builtin_bitoffsetof(L,e) == 136, "");
#endif
_Static_assert(sizeof(M) == 4, "");
_Static_assert(_Alignof(M) == 2, "");
_Static_assert(sizeof(struct M_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct M_extra_alignment) == 2, "");
_Static_assert(sizeof(struct M_extra_packed) == 4, "");
_Static_assert(_Alignof(struct M_extra_packed) == 1, "");
_Static_assert(sizeof(struct M_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct M_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct M_extra_size) == 6, "");
_Static_assert(_Alignof(struct M_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(M,d) == 16, "");
_Static_assert(__builtin_bitoffsetof(M,e) == 24, "");
#endif
_Static_assert(sizeof(N) == 4, "");
_Static_assert(_Alignof(N) == 2, "");
_Static_assert(sizeof(struct N_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct N_extra_alignment) == 2, "");
_Static_assert(sizeof(struct N_extra_packed) == 4, "");
_Static_assert(_Alignof(struct N_extra_packed) == 1, "");
_Static_assert(sizeof(struct N_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct N_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct N_extra_size) == 6, "");
_Static_assert(_Alignof(struct N_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(N,d) == 16, "");
_Static_assert(__builtin_bitoffsetof(N,e) == 24, "");
#endif
_Static_assert(sizeof(O) == 3, "");
_Static_assert(_Alignof(O) == 1, "");
_Static_assert(sizeof(struct O_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct O_extra_alignment) == 1, "");
_Static_assert(sizeof(struct O_extra_packed) == 3, "");
_Static_assert(_Alignof(struct O_extra_packed) == 1, "");
_Static_assert(sizeof(struct O_extra_required_alignment) == 4, "");
_Static_assert(_Alignof(struct O_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct O_extra_size) == 5, "");
_Static_assert(_Alignof(struct O_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(O,d) == 8, "");
_Static_assert(__builtin_bitoffsetof(O,e) == 16, "");
#endif
_Static_assert(sizeof(P) == 4, "");
_Static_assert(_Alignof(P) == 2, "");
_Static_assert(sizeof(struct P_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct P_extra_alignment) == 2, "");
_Static_assert(sizeof(struct P_extra_packed) == 4, "");
_Static_assert(_Alignof(struct P_extra_packed) == 1, "");
_Static_assert(sizeof(struct P_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct P_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct P_extra_size) == 6, "");
_Static_assert(_Alignof(struct P_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(P,d) == 8, "");
_Static_assert(__builtin_bitoffsetof(P,e) == 16, "");
#endif
_Static_assert(sizeof(Q) == 8, "");
_Static_assert(_Alignof(Q) == 8, "");
_Static_assert(sizeof(struct Q_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct Q_extra_alignment) == 8, "");
_Static_assert(sizeof(struct Q_extra_packed) == 8, "");
_Static_assert(_Alignof(struct Q_extra_packed) == 1, "");
_Static_assert(sizeof(struct Q_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct Q_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct Q_extra_size) == 10, "");
_Static_assert(_Alignof(struct Q_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(Q,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(Q,d) == 9, "");
_Static_assert(__builtin_bitoffsetof(Q,e) == 16, "");
#endif
_Static_assert(sizeof(R) == 17, "");
_Static_assert(_Alignof(R) == 1, "");
_Static_assert(sizeof(struct R_extra_alignment) == 18, "");
_Static_assert(_Alignof(struct R_extra_alignment) == 1, "");
_Static_assert(sizeof(struct R_extra_packed) == 17, "");
_Static_assert(_Alignof(struct R_extra_packed) == 1, "");
_Static_assert(sizeof(struct R_extra_required_alignment) == 18, "");
_Static_assert(_Alignof(struct R_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct R_extra_size) == 19, "");
_Static_assert(_Alignof(struct R_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(R,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(R,e) == 128, "");
#endif
_Static_assert(sizeof(S) == 9, "");
_Static_assert(_Alignof(S) == 1, "");
_Static_assert(sizeof(struct S_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct S_extra_alignment) == 1, "");
_Static_assert(sizeof(struct S_extra_packed) == 9, "");
_Static_assert(_Alignof(struct S_extra_packed) == 1, "");
_Static_assert(sizeof(struct S_extra_required_alignment) == 10, "");
_Static_assert(_Alignof(struct S_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct S_extra_size) == 11, "");
_Static_assert(_Alignof(struct S_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(S,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(S,e) == 64, "");
#endif
_Static_assert(sizeof(T) == 9, "");
_Static_assert(_Alignof(T) == 1, "");
_Static_assert(sizeof(struct T_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct T_extra_alignment) == 1, "");
_Static_assert(sizeof(struct T_extra_packed) == 9, "");
_Static_assert(_Alignof(struct T_extra_packed) == 1, "");
_Static_assert(sizeof(struct T_extra_required_alignment) == 10, "");
_Static_assert(_Alignof(struct T_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct T_extra_size) == 11, "");
_Static_assert(_Alignof(struct T_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(T,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(T,e) == 64, "");
#endif
_Static_assert(sizeof(U) == 9, "");
_Static_assert(_Alignof(U) == 1, "");
_Static_assert(sizeof(struct U_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct U_extra_alignment) == 1, "");
_Static_assert(sizeof(struct U_extra_packed) == 9, "");
_Static_assert(_Alignof(struct U_extra_packed) == 1, "");
_Static_assert(sizeof(struct U_extra_required_alignment) == 10, "");
_Static_assert(_Alignof(struct U_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct U_extra_size) == 11, "");
_Static_assert(_Alignof(struct U_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(U,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(U,e) == 64, "");
#endif
_Static_assert(sizeof(V) == 9, "");
_Static_assert(_Alignof(V) == 1, "");
_Static_assert(sizeof(struct V_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct V_extra_alignment) == 1, "");
_Static_assert(sizeof(struct V_extra_packed) == 9, "");
_Static_assert(_Alignof(struct V_extra_packed) == 1, "");
_Static_assert(sizeof(struct V_extra_required_alignment) == 10, "");
_Static_assert(_Alignof(struct V_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct V_extra_size) == 11, "");
_Static_assert(_Alignof(struct V_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(V,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(V,e) == 64, "");
#endif
_Static_assert(sizeof(W) == 17, "");
_Static_assert(_Alignof(W) == 1, "");
_Static_assert(sizeof(struct W_extra_alignment) == 18, "");
_Static_assert(_Alignof(struct W_extra_alignment) == 1, "");
_Static_assert(sizeof(struct W_extra_packed) == 17, "");
_Static_assert(_Alignof(struct W_extra_packed) == 1, "");
_Static_assert(sizeof(struct W_extra_required_alignment) == 18, "");
_Static_assert(_Alignof(struct W_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct W_extra_size) == 19, "");
_Static_assert(_Alignof(struct W_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(W,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(W,e) == 128, "");
#endif
_Static_assert(sizeof(W_) == 17, "");
_Static_assert(_Alignof(W_) == 1, "");
_Static_assert(sizeof(struct W__extra_alignment) == 18, "");
_Static_assert(_Alignof(struct W__extra_alignment) == 1, "");
_Static_assert(sizeof(struct W__extra_packed) == 17, "");
_Static_assert(_Alignof(struct W__extra_packed) == 1, "");
_Static_assert(sizeof(struct W__extra_required_alignment) == 18, "");
_Static_assert(_Alignof(struct W__extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct W__extra_size) == 19, "");
_Static_assert(_Alignof(struct W__extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(W_,e) == 128, "");
#endif
_Static_assert(sizeof(X) == 17, "");
_Static_assert(_Alignof(X) == 1, "");
_Static_assert(sizeof(struct X_extra_alignment) == 18, "");
_Static_assert(_Alignof(struct X_extra_alignment) == 1, "");
_Static_assert(sizeof(struct X_extra_packed) == 17, "");
_Static_assert(_Alignof(struct X_extra_packed) == 1, "");
_Static_assert(sizeof(struct X_extra_required_alignment) == 18, "");
_Static_assert(_Alignof(struct X_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct X_extra_size) == 19, "");
_Static_assert(_Alignof(struct X_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(X,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(X,e) == 128, "");
#endif
_Static_assert(sizeof(A2) == 1, "");
_Static_assert(_Alignof(A2) == 1, "");
_Static_assert(sizeof(struct A2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct A2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct A2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct A2_extra_packed) == 1, "");
_Static_assert(sizeof(struct A2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct A2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A2_extra_size) == 3, "");
_Static_assert(_Alignof(struct A2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A2,d) == 0, "");
#endif
_Static_assert(sizeof(A_2) == 1, "");
_Static_assert(_Alignof(A_2) == 1, "");
_Static_assert(sizeof(struct A_2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct A_2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct A_2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct A_2_extra_packed) == 1, "");
_Static_assert(sizeof(struct A_2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct A_2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A_2_extra_size) == 3, "");
_Static_assert(_Alignof(struct A_2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_2,d) == 0, "");
#endif
_Static_assert(sizeof(B2) == 1, "");
_Static_assert(_Alignof(B2) == 1, "");
_Static_assert(sizeof(struct B2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct B2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct B2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct B2_extra_packed) == 1, "");
_Static_assert(sizeof(struct B2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct B2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B2_extra_size) == 3, "");
_Static_assert(_Alignof(struct B2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B2,d) == 0, "");
#endif
_Static_assert(sizeof(B_2) == 1, "");
_Static_assert(_Alignof(B_2) == 1, "");
_Static_assert(sizeof(struct B_2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct B_2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct B_2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct B_2_extra_packed) == 1, "");
_Static_assert(sizeof(struct B_2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct B_2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B_2_extra_size) == 3, "");
_Static_assert(_Alignof(struct B_2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B_2,d) == 0, "");
#endif
_Static_assert(sizeof(C2) == 1, "");
_Static_assert(_Alignof(C2) == 1, "");
_Static_assert(sizeof(struct C2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct C2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct C2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct C2_extra_packed) == 1, "");
_Static_assert(sizeof(struct C2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct C2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct C2_extra_size) == 3, "");
_Static_assert(_Alignof(struct C2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(C2,d) == 0, "");
#endif
_Static_assert(sizeof(C22) == 1, "");
_Static_assert(_Alignof(C22) == 1, "");
_Static_assert(sizeof(struct C22_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct C22_extra_alignment) == 1, "");
_Static_assert(sizeof(struct C22_extra_packed) == 1, "");
_Static_assert(_Alignof(struct C22_extra_packed) == 1, "");
_Static_assert(sizeof(struct C22_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct C22_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct C22_extra_size) == 3, "");
_Static_assert(_Alignof(struct C22_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(C22,d) == 0, "");
#endif
_Static_assert(sizeof(D2) == 8, "");
_Static_assert(_Alignof(D2) == 8, "");
_Static_assert(sizeof(struct D2_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct D2_extra_alignment) == 8, "");
_Static_assert(sizeof(struct D2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct D2_extra_packed) == 1, "");
_Static_assert(sizeof(struct D2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct D2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct D2_extra_size) == 10, "");
_Static_assert(_Alignof(struct D2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(D2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(D2,e) == 0, "");
#endif
_Static_assert(sizeof(F2) == 16, "");
_Static_assert(_Alignof(F2) == 16, "");
_Static_assert(sizeof(struct F2_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct F2_extra_alignment) == 16, "");
_Static_assert(sizeof(struct F2_extra_packed) == 16, "");
_Static_assert(_Alignof(struct F2_extra_packed) == 1, "");
_Static_assert(sizeof(struct F2_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct F2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct F2_extra_size) == 18, "");
_Static_assert(_Alignof(struct F2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(F2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(F2,e) == 0, "");
#endif
_Static_assert(sizeof(G2) == 8, "");
_Static_assert(_Alignof(G2) == 2, "");
_Static_assert(sizeof(struct G2_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct G2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct G2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct G2_extra_packed) == 1, "");
_Static_assert(sizeof(struct G2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct G2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct G2_extra_size) == 10, "");
_Static_assert(_Alignof(struct G2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(G2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(G2,e) == 0, "");
#endif
_Static_assert(sizeof(H2) == 8, "");
_Static_assert(_Alignof(H2) == 2, "");
_Static_assert(sizeof(struct H2_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct H2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct H2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct H2_extra_packed) == 1, "");
_Static_assert(sizeof(struct H2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct H2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct H2_extra_size) == 10, "");
_Static_assert(_Alignof(struct H2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(H2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(H2,e) == 0, "");
#endif
_Static_assert(sizeof(I2) == 8, "");
_Static_assert(_Alignof(I2) == 1, "");
_Static_assert(sizeof(struct I2_extra_alignment) == 9, "");
_Static_assert(_Alignof(struct I2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct I2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct I2_extra_packed) == 1, "");
_Static_assert(sizeof(struct I2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct I2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct I2_extra_size) == 10, "");
_Static_assert(_Alignof(struct I2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(I2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(I2,e) == 0, "");
#endif
_Static_assert(sizeof(J2) == 8, "");
_Static_assert(_Alignof(J2) == 2, "");
_Static_assert(sizeof(struct J2_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct J2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct J2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct J2_extra_packed) == 1, "");
_Static_assert(sizeof(struct J2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct J2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct J2_extra_size) == 10, "");
_Static_assert(_Alignof(struct J2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(J2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(J2,e) == 0, "");
#endif
_Static_assert(sizeof(K2) == 8, "");
_Static_assert(_Alignof(K2) == 8, "");
_Static_assert(sizeof(struct K2_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct K2_extra_alignment) == 8, "");
_Static_assert(sizeof(struct K2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct K2_extra_packed) == 1, "");
_Static_assert(sizeof(struct K2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct K2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct K2_extra_size) == 10, "");
_Static_assert(_Alignof(struct K2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(K2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(K2,e) == 0, "");
#endif
_Static_assert(sizeof(L2) == 16, "");
_Static_assert(_Alignof(L2) == 16, "");
_Static_assert(sizeof(struct L2_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct L2_extra_alignment) == 16, "");
_Static_assert(sizeof(struct L2_extra_packed) == 16, "");
_Static_assert(_Alignof(struct L2_extra_packed) == 1, "");
_Static_assert(sizeof(struct L2_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct L2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct L2_extra_size) == 18, "");
_Static_assert(_Alignof(struct L2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(L2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(L2,e) == 0, "");
#endif
_Static_assert(sizeof(M2) == 2, "");
_Static_assert(_Alignof(M2) == 2, "");
_Static_assert(sizeof(struct M2_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct M2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct M2_extra_packed) == 2, "");
_Static_assert(_Alignof(struct M2_extra_packed) == 1, "");
_Static_assert(sizeof(struct M2_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct M2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct M2_extra_size) == 4, "");
_Static_assert(_Alignof(struct M2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(M2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(M2,e) == 0, "");
#endif
_Static_assert(sizeof(N2) == 2, "");
_Static_assert(_Alignof(N2) == 2, "");
_Static_assert(sizeof(struct N2_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct N2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct N2_extra_packed) == 2, "");
_Static_assert(_Alignof(struct N2_extra_packed) == 1, "");
_Static_assert(sizeof(struct N2_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct N2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct N2_extra_size) == 4, "");
_Static_assert(_Alignof(struct N2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(N2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(N2,e) == 0, "");
#endif
_Static_assert(sizeof(O2) == 1, "");
_Static_assert(_Alignof(O2) == 1, "");
_Static_assert(sizeof(struct O2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct O2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct O2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct O2_extra_packed) == 1, "");
_Static_assert(sizeof(struct O2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct O2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct O2_extra_size) == 3, "");
_Static_assert(_Alignof(struct O2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(O2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(O2,e) == 0, "");
#endif
_Static_assert(sizeof(P2) == 2, "");
_Static_assert(_Alignof(P2) == 2, "");
_Static_assert(sizeof(struct P2_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct P2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct P2_extra_packed) == 2, "");
_Static_assert(_Alignof(struct P2_extra_packed) == 1, "");
_Static_assert(sizeof(struct P2_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct P2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct P2_extra_size) == 4, "");
_Static_assert(_Alignof(struct P2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(P2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(P2,e) == 0, "");
#endif
_Static_assert(sizeof(Q2) == 8, "");
_Static_assert(_Alignof(Q2) == 8, "");
_Static_assert(sizeof(struct Q2_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct Q2_extra_alignment) == 8, "");
_Static_assert(sizeof(struct Q2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct Q2_extra_packed) == 1, "");
_Static_assert(sizeof(struct Q2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct Q2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct Q2_extra_size) == 10, "");
_Static_assert(_Alignof(struct Q2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(Q2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(Q2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(Q2,e) == 0, "");
#endif
_Static_assert(sizeof(R2) == 1, "");
_Static_assert(_Alignof(R2) == 1, "");
_Static_assert(sizeof(struct R2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct R2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct R2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct R2_extra_packed) == 1, "");
_Static_assert(sizeof(struct R2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct R2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct R2_extra_size) == 3, "");
_Static_assert(_Alignof(struct R2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(R2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(R2,e) == 0, "");
#endif
_Static_assert(sizeof(S2) == 1, "");
_Static_assert(_Alignof(S2) == 1, "");
_Static_assert(sizeof(struct S2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct S2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct S2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct S2_extra_packed) == 1, "");
_Static_assert(sizeof(struct S2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct S2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct S2_extra_size) == 3, "");
_Static_assert(_Alignof(struct S2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(S2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(S2,e) == 0, "");
#endif
_Static_assert(sizeof(T2) == 1, "");
_Static_assert(_Alignof(T2) == 1, "");
_Static_assert(sizeof(struct T2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct T2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct T2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct T2_extra_packed) == 1, "");
_Static_assert(sizeof(struct T2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct T2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct T2_extra_size) == 3, "");
_Static_assert(_Alignof(struct T2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(T2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(T2,e) == 0, "");
#endif
_Static_assert(sizeof(U2) == 1, "");
_Static_assert(_Alignof(U2) == 1, "");
_Static_assert(sizeof(struct U2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct U2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct U2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct U2_extra_packed) == 1, "");
_Static_assert(sizeof(struct U2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct U2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct U2_extra_size) == 3, "");
_Static_assert(_Alignof(struct U2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(U2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(U2,e) == 0, "");
#endif
_Static_assert(sizeof(V2) == 1, "");
_Static_assert(_Alignof(V2) == 1, "");
_Static_assert(sizeof(struct V2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct V2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct V2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct V2_extra_packed) == 1, "");
_Static_assert(sizeof(struct V2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct V2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct V2_extra_size) == 3, "");
_Static_assert(_Alignof(struct V2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(V2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(V2,e) == 0, "");
#endif
_Static_assert(sizeof(W2) == 1, "");
_Static_assert(_Alignof(W2) == 1, "");
_Static_assert(sizeof(struct W2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct W2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct W2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct W2_extra_packed) == 1, "");
_Static_assert(sizeof(struct W2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct W2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct W2_extra_size) == 3, "");
_Static_assert(_Alignof(struct W2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(W2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(W2,e) == 0, "");
#endif
_Static_assert(sizeof(W_2) == 1, "");
_Static_assert(_Alignof(W_2) == 1, "");
_Static_assert(sizeof(struct W_2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct W_2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct W_2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct W_2_extra_packed) == 1, "");
_Static_assert(sizeof(struct W_2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct W_2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct W_2_extra_size) == 3, "");
_Static_assert(_Alignof(struct W_2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(W_2,e) == 0, "");
#endif
_Static_assert(sizeof(X2) == 1, "");
_Static_assert(_Alignof(X2) == 1, "");
_Static_assert(sizeof(struct X2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct X2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct X2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct X2_extra_packed) == 1, "");
_Static_assert(sizeof(struct X2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct X2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct X2_extra_size) == 3, "");
_Static_assert(_Alignof(struct X2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(X2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(X2,e) == 0, "");
#endif
_Static_assert(sizeof(Y) == 9, "");
_Static_assert(_Alignof(Y) == 1, "");
_Static_assert(sizeof(struct Y_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct Y_extra_alignment) == 1, "");
_Static_assert(sizeof(struct Y_extra_packed) == 9, "");
_Static_assert(_Alignof(struct Y_extra_packed) == 1, "");
_Static_assert(sizeof(struct Y_extra_required_alignment) == 10, "");
_Static_assert(_Alignof(struct Y_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct Y_extra_size) == 11, "");
_Static_assert(_Alignof(struct Y_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(Y,d) == 64, "");
#endif
_Static_assert(sizeof(Y2) == 1, "");
_Static_assert(_Alignof(Y2) == 1, "");
_Static_assert(sizeof(struct Y2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct Y2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct Y2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct Y2_extra_packed) == 1, "");
_Static_assert(sizeof(struct Y2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct Y2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct Y2_extra_size) == 3, "");
_Static_assert(_Alignof(struct Y2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(Y2,d) == 0, "");
#endif
_Static_assert(sizeof(A3) == 33, "");
_Static_assert(_Alignof(A3) == 1, "");
_Static_assert(sizeof(struct A3_extra_alignment) == 34, "");
_Static_assert(_Alignof(struct A3_extra_alignment) == 1, "");
_Static_assert(sizeof(struct A3_extra_packed) == 33, "");
_Static_assert(_Alignof(struct A3_extra_packed) == 1, "");
_Static_assert(sizeof(struct A3_extra_required_alignment) == 34, "");
_Static_assert(_Alignof(struct A3_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A3_extra_size) == 35, "");
_Static_assert(_Alignof(struct A3_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A3,d) == 256, "");
#endif
_Static_assert(sizeof(A4) == 1, "");
_Static_assert(_Alignof(A4) == 32, "");
_Static_assert(sizeof(struct A4_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct A4_extra_alignment) == 32, "");
_Static_assert(sizeof(struct A4_extra_packed) == 1, "");
_Static_assert(_Alignof(struct A4_extra_packed) == 1, "");
_Static_assert(sizeof(struct A4_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct A4_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A4_extra_size) == 3, "");
_Static_assert(_Alignof(struct A4_extra_size) == 1, "");
_Static_assert(sizeof(A5) == 33, "");
_Static_assert(_Alignof(A5) == 1, "");
_Static_assert(sizeof(struct A5_extra_alignment) == 34, "");
_Static_assert(_Alignof(struct A5_extra_alignment) == 1, "");
_Static_assert(sizeof(struct A5_extra_packed) == 33, "");
_Static_assert(_Alignof(struct A5_extra_packed) == 1, "");
_Static_assert(sizeof(struct A5_extra_required_alignment) == 34, "");
_Static_assert(_Alignof(struct A5_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A5_extra_size) == 35, "");
_Static_assert(_Alignof(struct A5_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A5,d) == 256, "");
#endif
_Static_assert(sizeof(A7) == 32, "");
_Static_assert(_Alignof(A7) == 32, "");
_Static_assert(sizeof(struct A7_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct A7_extra_alignment) == 32, "");
_Static_assert(sizeof(struct A7_extra_packed) == 32, "");
_Static_assert(_Alignof(struct A7_extra_packed) == 1, "");
_Static_assert(sizeof(struct A7_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct A7_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A7_extra_size) == 34, "");
_Static_assert(_Alignof(struct A7_extra_size) == 1, "");
_Static_assert(sizeof(A8) == 8, "");
_Static_assert(_Alignof(A8) == 8, "");
_Static_assert(sizeof(struct A8_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct A8_extra_alignment) == 8, "");
_Static_assert(sizeof(struct A8_extra_packed) == 8, "");
_Static_assert(_Alignof(struct A8_extra_packed) == 1, "");
_Static_assert(sizeof(struct A8_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct A8_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A8_extra_size) == 10, "");
_Static_assert(_Alignof(struct A8_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A8,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A8,j) == 39, "");
#endif
_Static_assert(sizeof(A9) == 16, "");
_Static_assert(_Alignof(A9) == 8, "");
_Static_assert(sizeof(struct A9_extra_alignment) == 24, "");
_Static_assert(_Alignof(struct A9_extra_alignment) == 8, "");
_Static_assert(sizeof(struct A9_extra_packed) == 16, "");
_Static_assert(_Alignof(struct A9_extra_packed) == 1, "");
_Static_assert(sizeof(struct A9_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct A9_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A9_extra_size) == 18, "");
_Static_assert(_Alignof(struct A9_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A9,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A9,j) == 64, "");
#endif
_Static_assert(sizeof(A10) == 8, "");
_Static_assert(_Alignof(A10) == 16, "");
_Static_assert(sizeof(struct A10_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct A10_extra_alignment) == 16, "");
_Static_assert(sizeof(struct A10_extra_packed) == 8, "");
_Static_assert(_Alignof(struct A10_extra_packed) == 1, "");
_Static_assert(sizeof(struct A10_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct A10_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A10_extra_size) == 10, "");
_Static_assert(_Alignof(struct A10_extra_size) == 1, "");
_Static_assert(sizeof(A11) == 32, "");
_Static_assert(_Alignof(A11) == 16, "");
_Static_assert(sizeof(struct A11_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct A11_extra_alignment) == 16, "");
_Static_assert(sizeof(struct A11_extra_packed) == 32, "");
_Static_assert(_Alignof(struct A11_extra_packed) == 1, "");
_Static_assert(sizeof(struct A11_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct A11_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A11_extra_size) == 34, "");
_Static_assert(_Alignof(struct A11_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A11,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A11,j) == 128, "");
#endif
_Static_assert(sizeof(A12) == 32, "");
_Static_assert(_Alignof(A12) == 16, "");
_Static_assert(sizeof(struct A12_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct A12_extra_alignment) == 16, "");
_Static_assert(sizeof(struct A12_extra_packed) == 32, "");
_Static_assert(_Alignof(struct A12_extra_packed) == 1, "");
_Static_assert(sizeof(struct A12_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct A12_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A12_extra_size) == 34, "");
_Static_assert(_Alignof(struct A12_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A12,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A12,j) == 128, "");
#endif
_Static_assert(sizeof(A13) == 32, "");
_Static_assert(_Alignof(A13) == 16, "");
_Static_assert(sizeof(struct A13_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct A13_extra_alignment) == 16, "");
_Static_assert(sizeof(struct A13_extra_packed) == 32, "");
_Static_assert(_Alignof(struct A13_extra_packed) == 1, "");
_Static_assert(sizeof(struct A13_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct A13_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A13_extra_size) == 34, "");
_Static_assert(_Alignof(struct A13_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A13,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A13,j) == 128, "");
_Static_assert(__builtin_bitoffsetof(A13,d) == 136, "");
#endif
// MAPPING|THIRTEEN|mipsel-mips32-linux-gnu:Gcc|mipsel-mips32-linux-musl:Gcc|mips-mips32-linux-gnu:Gcc|mips-mips32r6-linux-gnu:Gcc|mips-mips32-linux-gnu:Gcc|mips-mips32-linux-musl:Gcc|powerpc-ppc-linux-gnu:Gcc|powerpc-ppc-linux-musl:Gcc|riscv32-baseline_rv32-linux-gnu:Gcc|sparc-v8-linux-gnu:Gcc|x86_64-x86_64-linux-gnux32:Gcc|END
// repr targets MipselUnknownLinuxGnu|Some("mipsel-mips32-linux-gnu") MipselUnknownLinuxMusl|Some("mipsel-mips32-linux-musl") MipselUnknownLinuxUclibc|None Mipsisa32r6elUnknownLinuxGnu|Some("mips-mips32-linux-gnu") Mipsisa32r6UnknownLinuxGnu|Some("mips-mips32r6-linux-gnu") MipsUnknownLinuxGnu|Some("mips-mips32-linux-gnu") MipsUnknownLinuxMusl|Some("mips-mips32-linux-musl") MipsUnknownLinuxUclibc|None PowerpcUnknownLinuxGnu|Some("powerpc-ppc-linux-gnu") PowerpcUnknownLinuxMusl|Some("powerpc-ppc-linux-musl") Riscv32UnknownLinuxGnu|Some("riscv32-baseline_rv32-linux-gnu") SparcUnknownLinuxGnu|Some("sparc-v8-linux-gnu") X86_64UnknownLinuxGnux32|Some("x86_64-x86_64-linux-gnux32") 
#elif defined(THIRTEEN)
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
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A,d) == 0, "");
#endif
_Static_assert(sizeof(A_) == 5, "");
_Static_assert(_Alignof(A_) == 1, "");
_Static_assert(sizeof(struct A__extra_alignment) == 6, "");
_Static_assert(_Alignof(struct A__extra_alignment) == 1, "");
_Static_assert(sizeof(struct A__extra_packed) == 5, "");
_Static_assert(_Alignof(struct A__extra_packed) == 1, "");
_Static_assert(sizeof(struct A__extra_required_alignment) == 6, "");
_Static_assert(_Alignof(struct A__extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A__extra_size) == 7, "");
_Static_assert(_Alignof(struct A__extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_,d) == 32, "");
#endif
_Static_assert(sizeof(B) == 1, "");
_Static_assert(_Alignof(B) == 1, "");
_Static_assert(sizeof(struct B_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct B_extra_alignment) == 1, "");
_Static_assert(sizeof(struct B_extra_packed) == 1, "");
_Static_assert(_Alignof(struct B_extra_packed) == 1, "");
_Static_assert(sizeof(struct B_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct B_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B_extra_size) == 3, "");
_Static_assert(_Alignof(struct B_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B,d) == 0, "");
#endif
_Static_assert(sizeof(B_) == 9, "");
_Static_assert(_Alignof(B_) == 1, "");
_Static_assert(sizeof(struct B__extra_alignment) == 10, "");
_Static_assert(_Alignof(struct B__extra_alignment) == 1, "");
_Static_assert(sizeof(struct B__extra_packed) == 9, "");
_Static_assert(_Alignof(struct B__extra_packed) == 1, "");
_Static_assert(sizeof(struct B__extra_required_alignment) == 10, "");
_Static_assert(_Alignof(struct B__extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B__extra_size) == 11, "");
_Static_assert(_Alignof(struct B__extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B_,d) == 64, "");
#endif
_Static_assert(sizeof(C) == 1, "");
_Static_assert(_Alignof(C) == 1, "");
_Static_assert(sizeof(struct C_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct C_extra_alignment) == 1, "");
_Static_assert(sizeof(struct C_extra_packed) == 1, "");
_Static_assert(_Alignof(struct C_extra_packed) == 1, "");
_Static_assert(sizeof(struct C_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct C_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct C_extra_size) == 3, "");
_Static_assert(_Alignof(struct C_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(C,d) == 0, "");
#endif
_Static_assert(sizeof(C_) == 9, "");
_Static_assert(_Alignof(C_) == 1, "");
_Static_assert(sizeof(struct C__extra_alignment) == 10, "");
_Static_assert(_Alignof(struct C__extra_alignment) == 1, "");
_Static_assert(sizeof(struct C__extra_packed) == 9, "");
_Static_assert(_Alignof(struct C__extra_packed) == 1, "");
_Static_assert(sizeof(struct C__extra_required_alignment) == 10, "");
_Static_assert(_Alignof(struct C__extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct C__extra_size) == 11, "");
_Static_assert(_Alignof(struct C__extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(C_,d) == 64, "");
#endif
_Static_assert(sizeof(D) == 24, "");
_Static_assert(_Alignof(D) == 8, "");
_Static_assert(sizeof(struct D_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct D_extra_alignment) == 8, "");
_Static_assert(sizeof(struct D_extra_packed) == 24, "");
_Static_assert(_Alignof(struct D_extra_packed) == 1, "");
_Static_assert(sizeof(struct D_extra_required_alignment) == 25, "");
_Static_assert(_Alignof(struct D_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct D_extra_size) == 26, "");
_Static_assert(_Alignof(struct D_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(D,d) == 64, "");
_Static_assert(__builtin_bitoffsetof(D,e) == 128, "");
#endif
_Static_assert(sizeof(F) == 32, "");
_Static_assert(_Alignof(F) == 16, "");
_Static_assert(sizeof(struct F_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct F_extra_alignment) == 16, "");
_Static_assert(sizeof(struct F_extra_packed) == 32, "");
_Static_assert(_Alignof(struct F_extra_packed) == 1, "");
_Static_assert(sizeof(struct F_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct F_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct F_extra_size) == 34, "");
_Static_assert(_Alignof(struct F_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(F,d) == 128, "");
_Static_assert(__builtin_bitoffsetof(F,e) == 192, "");
#endif
_Static_assert(sizeof(G) == 12, "");
_Static_assert(_Alignof(G) == 2, "");
_Static_assert(sizeof(struct G_extra_alignment) == 14, "");
_Static_assert(_Alignof(struct G_extra_alignment) == 2, "");
_Static_assert(sizeof(struct G_extra_packed) == 12, "");
_Static_assert(_Alignof(struct G_extra_packed) == 1, "");
_Static_assert(sizeof(struct G_extra_required_alignment) == 13, "");
_Static_assert(_Alignof(struct G_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct G_extra_size) == 14, "");
_Static_assert(_Alignof(struct G_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(G,d) == 16, "");
_Static_assert(__builtin_bitoffsetof(G,e) == 80, "");
#endif
_Static_assert(sizeof(H) == 12, "");
_Static_assert(_Alignof(H) == 2, "");
_Static_assert(sizeof(struct H_extra_alignment) == 14, "");
_Static_assert(_Alignof(struct H_extra_alignment) == 2, "");
_Static_assert(sizeof(struct H_extra_packed) == 12, "");
_Static_assert(_Alignof(struct H_extra_packed) == 1, "");
_Static_assert(sizeof(struct H_extra_required_alignment) == 13, "");
_Static_assert(_Alignof(struct H_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct H_extra_size) == 14, "");
_Static_assert(_Alignof(struct H_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(H,d) == 16, "");
_Static_assert(__builtin_bitoffsetof(H,e) == 80, "");
#endif
_Static_assert(sizeof(I) == 10, "");
_Static_assert(_Alignof(I) == 1, "");
_Static_assert(sizeof(struct I_extra_alignment) == 11, "");
_Static_assert(_Alignof(struct I_extra_alignment) == 1, "");
_Static_assert(sizeof(struct I_extra_packed) == 10, "");
_Static_assert(_Alignof(struct I_extra_packed) == 1, "");
_Static_assert(sizeof(struct I_extra_required_alignment) == 11, "");
_Static_assert(_Alignof(struct I_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct I_extra_size) == 12, "");
_Static_assert(_Alignof(struct I_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(I,d) == 8, "");
_Static_assert(__builtin_bitoffsetof(I,e) == 72, "");
#endif
_Static_assert(sizeof(J) == 12, "");
_Static_assert(_Alignof(J) == 2, "");
_Static_assert(sizeof(struct J_extra_alignment) == 14, "");
_Static_assert(_Alignof(struct J_extra_alignment) == 2, "");
_Static_assert(sizeof(struct J_extra_packed) == 12, "");
_Static_assert(_Alignof(struct J_extra_packed) == 1, "");
_Static_assert(sizeof(struct J_extra_required_alignment) == 13, "");
_Static_assert(_Alignof(struct J_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct J_extra_size) == 14, "");
_Static_assert(_Alignof(struct J_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(J,d) == 16, "");
_Static_assert(__builtin_bitoffsetof(J,e) == 80, "");
#endif
_Static_assert(sizeof(K) == 8, "");
_Static_assert(_Alignof(K) == 8, "");
_Static_assert(sizeof(struct K_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct K_extra_alignment) == 8, "");
_Static_assert(sizeof(struct K_extra_packed) == 8, "");
_Static_assert(_Alignof(struct K_extra_packed) == 1, "");
_Static_assert(sizeof(struct K_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct K_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct K_extra_size) == 10, "");
_Static_assert(_Alignof(struct K_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(K,d) == 8, "");
_Static_assert(__builtin_bitoffsetof(K,e) == 16, "");
#endif
_Static_assert(sizeof(L) == 32, "");
_Static_assert(_Alignof(L) == 16, "");
_Static_assert(sizeof(struct L_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct L_extra_alignment) == 16, "");
_Static_assert(sizeof(struct L_extra_packed) == 32, "");
_Static_assert(_Alignof(struct L_extra_packed) == 1, "");
_Static_assert(sizeof(struct L_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct L_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct L_extra_size) == 34, "");
_Static_assert(_Alignof(struct L_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(L,d) == 128, "");
_Static_assert(__builtin_bitoffsetof(L,e) == 136, "");
#endif
_Static_assert(sizeof(M) == 4, "");
_Static_assert(_Alignof(M) == 2, "");
_Static_assert(sizeof(struct M_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct M_extra_alignment) == 2, "");
_Static_assert(sizeof(struct M_extra_packed) == 4, "");
_Static_assert(_Alignof(struct M_extra_packed) == 1, "");
_Static_assert(sizeof(struct M_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct M_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct M_extra_size) == 6, "");
_Static_assert(_Alignof(struct M_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(M,d) == 16, "");
_Static_assert(__builtin_bitoffsetof(M,e) == 24, "");
#endif
_Static_assert(sizeof(N) == 4, "");
_Static_assert(_Alignof(N) == 2, "");
_Static_assert(sizeof(struct N_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct N_extra_alignment) == 2, "");
_Static_assert(sizeof(struct N_extra_packed) == 4, "");
_Static_assert(_Alignof(struct N_extra_packed) == 1, "");
_Static_assert(sizeof(struct N_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct N_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct N_extra_size) == 6, "");
_Static_assert(_Alignof(struct N_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(N,d) == 16, "");
_Static_assert(__builtin_bitoffsetof(N,e) == 24, "");
#endif
_Static_assert(sizeof(O) == 3, "");
_Static_assert(_Alignof(O) == 1, "");
_Static_assert(sizeof(struct O_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct O_extra_alignment) == 1, "");
_Static_assert(sizeof(struct O_extra_packed) == 3, "");
_Static_assert(_Alignof(struct O_extra_packed) == 1, "");
_Static_assert(sizeof(struct O_extra_required_alignment) == 4, "");
_Static_assert(_Alignof(struct O_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct O_extra_size) == 5, "");
_Static_assert(_Alignof(struct O_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(O,d) == 8, "");
_Static_assert(__builtin_bitoffsetof(O,e) == 16, "");
#endif
_Static_assert(sizeof(P) == 4, "");
_Static_assert(_Alignof(P) == 2, "");
_Static_assert(sizeof(struct P_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct P_extra_alignment) == 2, "");
_Static_assert(sizeof(struct P_extra_packed) == 4, "");
_Static_assert(_Alignof(struct P_extra_packed) == 1, "");
_Static_assert(sizeof(struct P_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct P_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct P_extra_size) == 6, "");
_Static_assert(_Alignof(struct P_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(P,d) == 8, "");
_Static_assert(__builtin_bitoffsetof(P,e) == 16, "");
#endif
_Static_assert(sizeof(Q) == 8, "");
_Static_assert(_Alignof(Q) == 8, "");
_Static_assert(sizeof(struct Q_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct Q_extra_alignment) == 8, "");
_Static_assert(sizeof(struct Q_extra_packed) == 8, "");
_Static_assert(_Alignof(struct Q_extra_packed) == 1, "");
_Static_assert(sizeof(struct Q_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct Q_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct Q_extra_size) == 10, "");
_Static_assert(_Alignof(struct Q_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(Q,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(Q,d) == 9, "");
_Static_assert(__builtin_bitoffsetof(Q,e) == 16, "");
#endif
_Static_assert(sizeof(R) == 17, "");
_Static_assert(_Alignof(R) == 1, "");
_Static_assert(sizeof(struct R_extra_alignment) == 18, "");
_Static_assert(_Alignof(struct R_extra_alignment) == 1, "");
_Static_assert(sizeof(struct R_extra_packed) == 17, "");
_Static_assert(_Alignof(struct R_extra_packed) == 1, "");
_Static_assert(sizeof(struct R_extra_required_alignment) == 18, "");
_Static_assert(_Alignof(struct R_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct R_extra_size) == 19, "");
_Static_assert(_Alignof(struct R_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(R,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(R,e) == 128, "");
#endif
_Static_assert(sizeof(S) == 9, "");
_Static_assert(_Alignof(S) == 1, "");
_Static_assert(sizeof(struct S_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct S_extra_alignment) == 1, "");
_Static_assert(sizeof(struct S_extra_packed) == 9, "");
_Static_assert(_Alignof(struct S_extra_packed) == 1, "");
_Static_assert(sizeof(struct S_extra_required_alignment) == 10, "");
_Static_assert(_Alignof(struct S_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct S_extra_size) == 11, "");
_Static_assert(_Alignof(struct S_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(S,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(S,e) == 64, "");
#endif
_Static_assert(sizeof(T) == 9, "");
_Static_assert(_Alignof(T) == 1, "");
_Static_assert(sizeof(struct T_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct T_extra_alignment) == 1, "");
_Static_assert(sizeof(struct T_extra_packed) == 9, "");
_Static_assert(_Alignof(struct T_extra_packed) == 1, "");
_Static_assert(sizeof(struct T_extra_required_alignment) == 10, "");
_Static_assert(_Alignof(struct T_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct T_extra_size) == 11, "");
_Static_assert(_Alignof(struct T_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(T,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(T,e) == 64, "");
#endif
_Static_assert(sizeof(U) == 9, "");
_Static_assert(_Alignof(U) == 1, "");
_Static_assert(sizeof(struct U_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct U_extra_alignment) == 1, "");
_Static_assert(sizeof(struct U_extra_packed) == 9, "");
_Static_assert(_Alignof(struct U_extra_packed) == 1, "");
_Static_assert(sizeof(struct U_extra_required_alignment) == 10, "");
_Static_assert(_Alignof(struct U_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct U_extra_size) == 11, "");
_Static_assert(_Alignof(struct U_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(U,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(U,e) == 64, "");
#endif
_Static_assert(sizeof(V) == 9, "");
_Static_assert(_Alignof(V) == 1, "");
_Static_assert(sizeof(struct V_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct V_extra_alignment) == 1, "");
_Static_assert(sizeof(struct V_extra_packed) == 9, "");
_Static_assert(_Alignof(struct V_extra_packed) == 1, "");
_Static_assert(sizeof(struct V_extra_required_alignment) == 10, "");
_Static_assert(_Alignof(struct V_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct V_extra_size) == 11, "");
_Static_assert(_Alignof(struct V_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(V,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(V,e) == 64, "");
#endif
_Static_assert(sizeof(W) == 17, "");
_Static_assert(_Alignof(W) == 1, "");
_Static_assert(sizeof(struct W_extra_alignment) == 18, "");
_Static_assert(_Alignof(struct W_extra_alignment) == 1, "");
_Static_assert(sizeof(struct W_extra_packed) == 17, "");
_Static_assert(_Alignof(struct W_extra_packed) == 1, "");
_Static_assert(sizeof(struct W_extra_required_alignment) == 18, "");
_Static_assert(_Alignof(struct W_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct W_extra_size) == 19, "");
_Static_assert(_Alignof(struct W_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(W,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(W,e) == 128, "");
#endif
_Static_assert(sizeof(W_) == 17, "");
_Static_assert(_Alignof(W_) == 1, "");
_Static_assert(sizeof(struct W__extra_alignment) == 18, "");
_Static_assert(_Alignof(struct W__extra_alignment) == 1, "");
_Static_assert(sizeof(struct W__extra_packed) == 17, "");
_Static_assert(_Alignof(struct W__extra_packed) == 1, "");
_Static_assert(sizeof(struct W__extra_required_alignment) == 18, "");
_Static_assert(_Alignof(struct W__extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct W__extra_size) == 19, "");
_Static_assert(_Alignof(struct W__extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(W_,e) == 128, "");
#endif
_Static_assert(sizeof(X) == 17, "");
_Static_assert(_Alignof(X) == 1, "");
_Static_assert(sizeof(struct X_extra_alignment) == 18, "");
_Static_assert(_Alignof(struct X_extra_alignment) == 1, "");
_Static_assert(sizeof(struct X_extra_packed) == 17, "");
_Static_assert(_Alignof(struct X_extra_packed) == 1, "");
_Static_assert(sizeof(struct X_extra_required_alignment) == 18, "");
_Static_assert(_Alignof(struct X_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct X_extra_size) == 19, "");
_Static_assert(_Alignof(struct X_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(X,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(X,e) == 128, "");
#endif
_Static_assert(sizeof(A2) == 1, "");
_Static_assert(_Alignof(A2) == 1, "");
_Static_assert(sizeof(struct A2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct A2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct A2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct A2_extra_packed) == 1, "");
_Static_assert(sizeof(struct A2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct A2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A2_extra_size) == 3, "");
_Static_assert(_Alignof(struct A2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A2,d) == 0, "");
#endif
_Static_assert(sizeof(A_2) == 1, "");
_Static_assert(_Alignof(A_2) == 1, "");
_Static_assert(sizeof(struct A_2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct A_2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct A_2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct A_2_extra_packed) == 1, "");
_Static_assert(sizeof(struct A_2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct A_2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A_2_extra_size) == 3, "");
_Static_assert(_Alignof(struct A_2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_2,d) == 0, "");
#endif
_Static_assert(sizeof(B2) == 1, "");
_Static_assert(_Alignof(B2) == 1, "");
_Static_assert(sizeof(struct B2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct B2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct B2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct B2_extra_packed) == 1, "");
_Static_assert(sizeof(struct B2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct B2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B2_extra_size) == 3, "");
_Static_assert(_Alignof(struct B2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B2,d) == 0, "");
#endif
_Static_assert(sizeof(B_2) == 1, "");
_Static_assert(_Alignof(B_2) == 1, "");
_Static_assert(sizeof(struct B_2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct B_2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct B_2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct B_2_extra_packed) == 1, "");
_Static_assert(sizeof(struct B_2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct B_2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B_2_extra_size) == 3, "");
_Static_assert(_Alignof(struct B_2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B_2,d) == 0, "");
#endif
_Static_assert(sizeof(C2) == 1, "");
_Static_assert(_Alignof(C2) == 1, "");
_Static_assert(sizeof(struct C2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct C2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct C2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct C2_extra_packed) == 1, "");
_Static_assert(sizeof(struct C2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct C2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct C2_extra_size) == 3, "");
_Static_assert(_Alignof(struct C2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(C2,d) == 0, "");
#endif
_Static_assert(sizeof(C22) == 1, "");
_Static_assert(_Alignof(C22) == 1, "");
_Static_assert(sizeof(struct C22_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct C22_extra_alignment) == 1, "");
_Static_assert(sizeof(struct C22_extra_packed) == 1, "");
_Static_assert(_Alignof(struct C22_extra_packed) == 1, "");
_Static_assert(sizeof(struct C22_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct C22_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct C22_extra_size) == 3, "");
_Static_assert(_Alignof(struct C22_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(C22,d) == 0, "");
#endif
_Static_assert(sizeof(D2) == 8, "");
_Static_assert(_Alignof(D2) == 8, "");
_Static_assert(sizeof(struct D2_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct D2_extra_alignment) == 8, "");
_Static_assert(sizeof(struct D2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct D2_extra_packed) == 1, "");
_Static_assert(sizeof(struct D2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct D2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct D2_extra_size) == 10, "");
_Static_assert(_Alignof(struct D2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(D2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(D2,e) == 0, "");
#endif
_Static_assert(sizeof(F2) == 16, "");
_Static_assert(_Alignof(F2) == 16, "");
_Static_assert(sizeof(struct F2_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct F2_extra_alignment) == 16, "");
_Static_assert(sizeof(struct F2_extra_packed) == 16, "");
_Static_assert(_Alignof(struct F2_extra_packed) == 1, "");
_Static_assert(sizeof(struct F2_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct F2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct F2_extra_size) == 18, "");
_Static_assert(_Alignof(struct F2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(F2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(F2,e) == 0, "");
#endif
_Static_assert(sizeof(G2) == 8, "");
_Static_assert(_Alignof(G2) == 2, "");
_Static_assert(sizeof(struct G2_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct G2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct G2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct G2_extra_packed) == 1, "");
_Static_assert(sizeof(struct G2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct G2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct G2_extra_size) == 10, "");
_Static_assert(_Alignof(struct G2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(G2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(G2,e) == 0, "");
#endif
_Static_assert(sizeof(H2) == 8, "");
_Static_assert(_Alignof(H2) == 2, "");
_Static_assert(sizeof(struct H2_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct H2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct H2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct H2_extra_packed) == 1, "");
_Static_assert(sizeof(struct H2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct H2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct H2_extra_size) == 10, "");
_Static_assert(_Alignof(struct H2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(H2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(H2,e) == 0, "");
#endif
_Static_assert(sizeof(I2) == 8, "");
_Static_assert(_Alignof(I2) == 1, "");
_Static_assert(sizeof(struct I2_extra_alignment) == 9, "");
_Static_assert(_Alignof(struct I2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct I2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct I2_extra_packed) == 1, "");
_Static_assert(sizeof(struct I2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct I2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct I2_extra_size) == 10, "");
_Static_assert(_Alignof(struct I2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(I2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(I2,e) == 0, "");
#endif
_Static_assert(sizeof(J2) == 8, "");
_Static_assert(_Alignof(J2) == 2, "");
_Static_assert(sizeof(struct J2_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct J2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct J2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct J2_extra_packed) == 1, "");
_Static_assert(sizeof(struct J2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct J2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct J2_extra_size) == 10, "");
_Static_assert(_Alignof(struct J2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(J2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(J2,e) == 0, "");
#endif
_Static_assert(sizeof(K2) == 8, "");
_Static_assert(_Alignof(K2) == 8, "");
_Static_assert(sizeof(struct K2_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct K2_extra_alignment) == 8, "");
_Static_assert(sizeof(struct K2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct K2_extra_packed) == 1, "");
_Static_assert(sizeof(struct K2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct K2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct K2_extra_size) == 10, "");
_Static_assert(_Alignof(struct K2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(K2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(K2,e) == 0, "");
#endif
_Static_assert(sizeof(L2) == 16, "");
_Static_assert(_Alignof(L2) == 16, "");
_Static_assert(sizeof(struct L2_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct L2_extra_alignment) == 16, "");
_Static_assert(sizeof(struct L2_extra_packed) == 16, "");
_Static_assert(_Alignof(struct L2_extra_packed) == 1, "");
_Static_assert(sizeof(struct L2_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct L2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct L2_extra_size) == 18, "");
_Static_assert(_Alignof(struct L2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(L2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(L2,e) == 0, "");
#endif
_Static_assert(sizeof(M2) == 2, "");
_Static_assert(_Alignof(M2) == 2, "");
_Static_assert(sizeof(struct M2_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct M2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct M2_extra_packed) == 2, "");
_Static_assert(_Alignof(struct M2_extra_packed) == 1, "");
_Static_assert(sizeof(struct M2_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct M2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct M2_extra_size) == 4, "");
_Static_assert(_Alignof(struct M2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(M2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(M2,e) == 0, "");
#endif
_Static_assert(sizeof(N2) == 2, "");
_Static_assert(_Alignof(N2) == 2, "");
_Static_assert(sizeof(struct N2_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct N2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct N2_extra_packed) == 2, "");
_Static_assert(_Alignof(struct N2_extra_packed) == 1, "");
_Static_assert(sizeof(struct N2_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct N2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct N2_extra_size) == 4, "");
_Static_assert(_Alignof(struct N2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(N2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(N2,e) == 0, "");
#endif
_Static_assert(sizeof(O2) == 1, "");
_Static_assert(_Alignof(O2) == 1, "");
_Static_assert(sizeof(struct O2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct O2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct O2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct O2_extra_packed) == 1, "");
_Static_assert(sizeof(struct O2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct O2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct O2_extra_size) == 3, "");
_Static_assert(_Alignof(struct O2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(O2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(O2,e) == 0, "");
#endif
_Static_assert(sizeof(P2) == 2, "");
_Static_assert(_Alignof(P2) == 2, "");
_Static_assert(sizeof(struct P2_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct P2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct P2_extra_packed) == 2, "");
_Static_assert(_Alignof(struct P2_extra_packed) == 1, "");
_Static_assert(sizeof(struct P2_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct P2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct P2_extra_size) == 4, "");
_Static_assert(_Alignof(struct P2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(P2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(P2,e) == 0, "");
#endif
_Static_assert(sizeof(Q2) == 8, "");
_Static_assert(_Alignof(Q2) == 8, "");
_Static_assert(sizeof(struct Q2_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct Q2_extra_alignment) == 8, "");
_Static_assert(sizeof(struct Q2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct Q2_extra_packed) == 1, "");
_Static_assert(sizeof(struct Q2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct Q2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct Q2_extra_size) == 10, "");
_Static_assert(_Alignof(struct Q2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(Q2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(Q2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(Q2,e) == 0, "");
#endif
_Static_assert(sizeof(R2) == 1, "");
_Static_assert(_Alignof(R2) == 1, "");
_Static_assert(sizeof(struct R2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct R2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct R2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct R2_extra_packed) == 1, "");
_Static_assert(sizeof(struct R2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct R2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct R2_extra_size) == 3, "");
_Static_assert(_Alignof(struct R2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(R2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(R2,e) == 0, "");
#endif
_Static_assert(sizeof(S2) == 1, "");
_Static_assert(_Alignof(S2) == 1, "");
_Static_assert(sizeof(struct S2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct S2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct S2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct S2_extra_packed) == 1, "");
_Static_assert(sizeof(struct S2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct S2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct S2_extra_size) == 3, "");
_Static_assert(_Alignof(struct S2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(S2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(S2,e) == 0, "");
#endif
_Static_assert(sizeof(T2) == 1, "");
_Static_assert(_Alignof(T2) == 1, "");
_Static_assert(sizeof(struct T2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct T2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct T2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct T2_extra_packed) == 1, "");
_Static_assert(sizeof(struct T2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct T2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct T2_extra_size) == 3, "");
_Static_assert(_Alignof(struct T2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(T2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(T2,e) == 0, "");
#endif
_Static_assert(sizeof(U2) == 1, "");
_Static_assert(_Alignof(U2) == 1, "");
_Static_assert(sizeof(struct U2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct U2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct U2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct U2_extra_packed) == 1, "");
_Static_assert(sizeof(struct U2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct U2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct U2_extra_size) == 3, "");
_Static_assert(_Alignof(struct U2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(U2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(U2,e) == 0, "");
#endif
_Static_assert(sizeof(V2) == 1, "");
_Static_assert(_Alignof(V2) == 1, "");
_Static_assert(sizeof(struct V2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct V2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct V2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct V2_extra_packed) == 1, "");
_Static_assert(sizeof(struct V2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct V2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct V2_extra_size) == 3, "");
_Static_assert(_Alignof(struct V2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(V2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(V2,e) == 0, "");
#endif
_Static_assert(sizeof(W2) == 1, "");
_Static_assert(_Alignof(W2) == 1, "");
_Static_assert(sizeof(struct W2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct W2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct W2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct W2_extra_packed) == 1, "");
_Static_assert(sizeof(struct W2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct W2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct W2_extra_size) == 3, "");
_Static_assert(_Alignof(struct W2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(W2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(W2,e) == 0, "");
#endif
_Static_assert(sizeof(W_2) == 1, "");
_Static_assert(_Alignof(W_2) == 1, "");
_Static_assert(sizeof(struct W_2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct W_2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct W_2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct W_2_extra_packed) == 1, "");
_Static_assert(sizeof(struct W_2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct W_2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct W_2_extra_size) == 3, "");
_Static_assert(_Alignof(struct W_2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(W_2,e) == 0, "");
#endif
_Static_assert(sizeof(X2) == 1, "");
_Static_assert(_Alignof(X2) == 1, "");
_Static_assert(sizeof(struct X2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct X2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct X2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct X2_extra_packed) == 1, "");
_Static_assert(sizeof(struct X2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct X2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct X2_extra_size) == 3, "");
_Static_assert(_Alignof(struct X2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(X2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(X2,e) == 0, "");
#endif
_Static_assert(sizeof(Y) == 9, "");
_Static_assert(_Alignof(Y) == 1, "");
_Static_assert(sizeof(struct Y_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct Y_extra_alignment) == 1, "");
_Static_assert(sizeof(struct Y_extra_packed) == 9, "");
_Static_assert(_Alignof(struct Y_extra_packed) == 1, "");
_Static_assert(sizeof(struct Y_extra_required_alignment) == 10, "");
_Static_assert(_Alignof(struct Y_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct Y_extra_size) == 11, "");
_Static_assert(_Alignof(struct Y_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(Y,d) == 64, "");
#endif
_Static_assert(sizeof(Y2) == 1, "");
_Static_assert(_Alignof(Y2) == 1, "");
_Static_assert(sizeof(struct Y2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct Y2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct Y2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct Y2_extra_packed) == 1, "");
_Static_assert(sizeof(struct Y2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct Y2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct Y2_extra_size) == 3, "");
_Static_assert(_Alignof(struct Y2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(Y2,d) == 0, "");
#endif
_Static_assert(sizeof(A3) == 33, "");
_Static_assert(_Alignof(A3) == 1, "");
_Static_assert(sizeof(struct A3_extra_alignment) == 34, "");
_Static_assert(_Alignof(struct A3_extra_alignment) == 1, "");
_Static_assert(sizeof(struct A3_extra_packed) == 33, "");
_Static_assert(_Alignof(struct A3_extra_packed) == 1, "");
_Static_assert(sizeof(struct A3_extra_required_alignment) == 34, "");
_Static_assert(_Alignof(struct A3_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A3_extra_size) == 35, "");
_Static_assert(_Alignof(struct A3_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A3,d) == 256, "");
#endif
_Static_assert(sizeof(A4) == 1, "");
_Static_assert(_Alignof(A4) == 32, "");
_Static_assert(sizeof(struct A4_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct A4_extra_alignment) == 32, "");
_Static_assert(sizeof(struct A4_extra_packed) == 1, "");
_Static_assert(_Alignof(struct A4_extra_packed) == 1, "");
_Static_assert(sizeof(struct A4_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct A4_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A4_extra_size) == 3, "");
_Static_assert(_Alignof(struct A4_extra_size) == 1, "");
_Static_assert(sizeof(A5) == 33, "");
_Static_assert(_Alignof(A5) == 1, "");
_Static_assert(sizeof(struct A5_extra_alignment) == 34, "");
_Static_assert(_Alignof(struct A5_extra_alignment) == 1, "");
_Static_assert(sizeof(struct A5_extra_packed) == 33, "");
_Static_assert(_Alignof(struct A5_extra_packed) == 1, "");
_Static_assert(sizeof(struct A5_extra_required_alignment) == 34, "");
_Static_assert(_Alignof(struct A5_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A5_extra_size) == 35, "");
_Static_assert(_Alignof(struct A5_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A5,d) == 256, "");
#endif
_Static_assert(sizeof(A7) == 32, "");
_Static_assert(_Alignof(A7) == 32, "");
_Static_assert(sizeof(struct A7_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct A7_extra_alignment) == 32, "");
_Static_assert(sizeof(struct A7_extra_packed) == 32, "");
_Static_assert(_Alignof(struct A7_extra_packed) == 1, "");
_Static_assert(sizeof(struct A7_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct A7_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A7_extra_size) == 34, "");
_Static_assert(_Alignof(struct A7_extra_size) == 1, "");
_Static_assert(sizeof(A8) == 8, "");
_Static_assert(_Alignof(A8) == 4, "");
_Static_assert(sizeof(struct A8_extra_alignment) == 12, "");
_Static_assert(_Alignof(struct A8_extra_alignment) == 4, "");
_Static_assert(sizeof(struct A8_extra_packed) == 8, "");
_Static_assert(_Alignof(struct A8_extra_packed) == 1, "");
_Static_assert(sizeof(struct A8_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct A8_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A8_extra_size) == 10, "");
_Static_assert(_Alignof(struct A8_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A8,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A8,j) == 39, "");
#endif
_Static_assert(sizeof(A9) == 12, "");
_Static_assert(_Alignof(A9) == 4, "");
_Static_assert(sizeof(struct A9_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct A9_extra_alignment) == 4, "");
_Static_assert(sizeof(struct A9_extra_packed) == 12, "");
_Static_assert(_Alignof(struct A9_extra_packed) == 1, "");
_Static_assert(sizeof(struct A9_extra_required_alignment) == 13, "");
_Static_assert(_Alignof(struct A9_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A9_extra_size) == 14, "");
_Static_assert(_Alignof(struct A9_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A9,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A9,j) == 64, "");
#endif
_Static_assert(sizeof(A10) == 4, "");
_Static_assert(_Alignof(A10) == 16, "");
_Static_assert(sizeof(struct A10_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct A10_extra_alignment) == 16, "");
_Static_assert(sizeof(struct A10_extra_packed) == 4, "");
_Static_assert(_Alignof(struct A10_extra_packed) == 1, "");
_Static_assert(sizeof(struct A10_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct A10_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A10_extra_size) == 6, "");
_Static_assert(_Alignof(struct A10_extra_size) == 1, "");
_Static_assert(sizeof(A11) == 32, "");
_Static_assert(_Alignof(A11) == 16, "");
_Static_assert(sizeof(struct A11_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct A11_extra_alignment) == 16, "");
_Static_assert(sizeof(struct A11_extra_packed) == 32, "");
_Static_assert(_Alignof(struct A11_extra_packed) == 1, "");
_Static_assert(sizeof(struct A11_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct A11_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A11_extra_size) == 34, "");
_Static_assert(_Alignof(struct A11_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A11,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A11,j) == 128, "");
#endif
_Static_assert(sizeof(A12) == 32, "");
_Static_assert(_Alignof(A12) == 16, "");
_Static_assert(sizeof(struct A12_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct A12_extra_alignment) == 16, "");
_Static_assert(sizeof(struct A12_extra_packed) == 32, "");
_Static_assert(_Alignof(struct A12_extra_packed) == 1, "");
_Static_assert(sizeof(struct A12_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct A12_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A12_extra_size) == 34, "");
_Static_assert(_Alignof(struct A12_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A12,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A12,j) == 128, "");
#endif
_Static_assert(sizeof(A13) == 32, "");
_Static_assert(_Alignof(A13) == 16, "");
_Static_assert(sizeof(struct A13_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct A13_extra_alignment) == 16, "");
_Static_assert(sizeof(struct A13_extra_packed) == 32, "");
_Static_assert(_Alignof(struct A13_extra_packed) == 1, "");
_Static_assert(sizeof(struct A13_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct A13_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A13_extra_size) == 34, "");
_Static_assert(_Alignof(struct A13_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A13,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A13,j) == 128, "");
_Static_assert(__builtin_bitoffsetof(A13,d) == 136, "");
#endif
// MAPPING|FOURTEEN|msp430-msp430-other-eabi:Clang|END
// repr targets Msp430NoneElf|Some("msp430-msp430-other-eabi") 
#elif defined(FOURTEEN)
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
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A,d) == 0, "");
#endif
_Static_assert(sizeof(A_) == 5, "");
_Static_assert(_Alignof(A_) == 1, "");
_Static_assert(sizeof(struct A__extra_alignment) == 6, "");
_Static_assert(_Alignof(struct A__extra_alignment) == 1, "");
_Static_assert(sizeof(struct A__extra_packed) == 5, "");
_Static_assert(_Alignof(struct A__extra_packed) == 1, "");
_Static_assert(sizeof(struct A__extra_required_alignment) == 6, "");
_Static_assert(_Alignof(struct A__extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A__extra_size) == 7, "");
_Static_assert(_Alignof(struct A__extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_,d) == 32, "");
#endif
_Static_assert(sizeof(B) == 1, "");
_Static_assert(_Alignof(B) == 1, "");
_Static_assert(sizeof(struct B_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct B_extra_alignment) == 1, "");
_Static_assert(sizeof(struct B_extra_packed) == 1, "");
_Static_assert(_Alignof(struct B_extra_packed) == 1, "");
_Static_assert(sizeof(struct B_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct B_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B_extra_size) == 3, "");
_Static_assert(_Alignof(struct B_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B,d) == 0, "");
#endif
_Static_assert(sizeof(B_) == 5, "");
_Static_assert(_Alignof(B_) == 1, "");
_Static_assert(sizeof(struct B__extra_alignment) == 6, "");
_Static_assert(_Alignof(struct B__extra_alignment) == 1, "");
_Static_assert(sizeof(struct B__extra_packed) == 5, "");
_Static_assert(_Alignof(struct B__extra_packed) == 1, "");
_Static_assert(sizeof(struct B__extra_required_alignment) == 6, "");
_Static_assert(_Alignof(struct B__extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B__extra_size) == 7, "");
_Static_assert(_Alignof(struct B__extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B_,d) == 32, "");
#endif
_Static_assert(sizeof(C) == 1, "");
_Static_assert(_Alignof(C) == 1, "");
_Static_assert(sizeof(struct C_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct C_extra_alignment) == 1, "");
_Static_assert(sizeof(struct C_extra_packed) == 1, "");
_Static_assert(_Alignof(struct C_extra_packed) == 1, "");
_Static_assert(sizeof(struct C_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct C_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct C_extra_size) == 3, "");
_Static_assert(_Alignof(struct C_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(C,d) == 0, "");
#endif
_Static_assert(sizeof(C_) == 3, "");
_Static_assert(_Alignof(C_) == 1, "");
_Static_assert(sizeof(struct C__extra_alignment) == 4, "");
_Static_assert(_Alignof(struct C__extra_alignment) == 1, "");
_Static_assert(sizeof(struct C__extra_packed) == 3, "");
_Static_assert(_Alignof(struct C__extra_packed) == 1, "");
_Static_assert(sizeof(struct C__extra_required_alignment) == 4, "");
_Static_assert(_Alignof(struct C__extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct C__extra_size) == 5, "");
_Static_assert(_Alignof(struct C__extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(C_,d) == 16, "");
#endif
_Static_assert(sizeof(D) == 12, "");
_Static_assert(_Alignof(D) == 2, "");
_Static_assert(sizeof(struct D_extra_alignment) == 14, "");
_Static_assert(_Alignof(struct D_extra_alignment) == 2, "");
_Static_assert(sizeof(struct D_extra_packed) == 12, "");
_Static_assert(_Alignof(struct D_extra_packed) == 1, "");
_Static_assert(sizeof(struct D_extra_required_alignment) == 13, "");
_Static_assert(_Alignof(struct D_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct D_extra_size) == 14, "");
_Static_assert(_Alignof(struct D_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(D,d) == 16, "");
_Static_assert(__builtin_bitoffsetof(D,e) == 80, "");
#endif
_Static_assert(sizeof(F) == 32, "");
_Static_assert(_Alignof(F) == 16, "");
_Static_assert(sizeof(struct F_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct F_extra_alignment) == 16, "");
_Static_assert(sizeof(struct F_extra_packed) == 32, "");
_Static_assert(_Alignof(struct F_extra_packed) == 1, "");
_Static_assert(sizeof(struct F_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct F_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct F_extra_size) == 34, "");
_Static_assert(_Alignof(struct F_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(F,d) == 128, "");
_Static_assert(__builtin_bitoffsetof(F,e) == 192, "");
#endif
_Static_assert(sizeof(G) == 12, "");
_Static_assert(_Alignof(G) == 2, "");
_Static_assert(sizeof(struct G_extra_alignment) == 14, "");
_Static_assert(_Alignof(struct G_extra_alignment) == 2, "");
_Static_assert(sizeof(struct G_extra_packed) == 12, "");
_Static_assert(_Alignof(struct G_extra_packed) == 1, "");
_Static_assert(sizeof(struct G_extra_required_alignment) == 13, "");
_Static_assert(_Alignof(struct G_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct G_extra_size) == 14, "");
_Static_assert(_Alignof(struct G_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(G,d) == 16, "");
_Static_assert(__builtin_bitoffsetof(G,e) == 80, "");
#endif
_Static_assert(sizeof(H) == 12, "");
_Static_assert(_Alignof(H) == 2, "");
_Static_assert(sizeof(struct H_extra_alignment) == 14, "");
_Static_assert(_Alignof(struct H_extra_alignment) == 2, "");
_Static_assert(sizeof(struct H_extra_packed) == 12, "");
_Static_assert(_Alignof(struct H_extra_packed) == 1, "");
_Static_assert(sizeof(struct H_extra_required_alignment) == 13, "");
_Static_assert(_Alignof(struct H_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct H_extra_size) == 14, "");
_Static_assert(_Alignof(struct H_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(H,d) == 16, "");
_Static_assert(__builtin_bitoffsetof(H,e) == 80, "");
#endif
_Static_assert(sizeof(I) == 10, "");
_Static_assert(_Alignof(I) == 1, "");
_Static_assert(sizeof(struct I_extra_alignment) == 11, "");
_Static_assert(_Alignof(struct I_extra_alignment) == 1, "");
_Static_assert(sizeof(struct I_extra_packed) == 10, "");
_Static_assert(_Alignof(struct I_extra_packed) == 1, "");
_Static_assert(sizeof(struct I_extra_required_alignment) == 11, "");
_Static_assert(_Alignof(struct I_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct I_extra_size) == 12, "");
_Static_assert(_Alignof(struct I_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(I,d) == 8, "");
_Static_assert(__builtin_bitoffsetof(I,e) == 72, "");
#endif
_Static_assert(sizeof(J) == 12, "");
_Static_assert(_Alignof(J) == 2, "");
_Static_assert(sizeof(struct J_extra_alignment) == 14, "");
_Static_assert(_Alignof(struct J_extra_alignment) == 2, "");
_Static_assert(sizeof(struct J_extra_packed) == 12, "");
_Static_assert(_Alignof(struct J_extra_packed) == 1, "");
_Static_assert(sizeof(struct J_extra_required_alignment) == 13, "");
_Static_assert(_Alignof(struct J_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct J_extra_size) == 14, "");
_Static_assert(_Alignof(struct J_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(J,d) == 16, "");
_Static_assert(__builtin_bitoffsetof(J,e) == 80, "");
#endif
_Static_assert(sizeof(K) == 4, "");
_Static_assert(_Alignof(K) == 2, "");
_Static_assert(sizeof(struct K_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct K_extra_alignment) == 2, "");
_Static_assert(sizeof(struct K_extra_packed) == 4, "");
_Static_assert(_Alignof(struct K_extra_packed) == 1, "");
_Static_assert(sizeof(struct K_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct K_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct K_extra_size) == 6, "");
_Static_assert(_Alignof(struct K_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(K,d) == 8, "");
_Static_assert(__builtin_bitoffsetof(K,e) == 16, "");
#endif
_Static_assert(sizeof(L) == 32, "");
_Static_assert(_Alignof(L) == 16, "");
_Static_assert(sizeof(struct L_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct L_extra_alignment) == 16, "");
_Static_assert(sizeof(struct L_extra_packed) == 32, "");
_Static_assert(_Alignof(struct L_extra_packed) == 1, "");
_Static_assert(sizeof(struct L_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct L_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct L_extra_size) == 34, "");
_Static_assert(_Alignof(struct L_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(L,d) == 128, "");
_Static_assert(__builtin_bitoffsetof(L,e) == 136, "");
#endif
_Static_assert(sizeof(M) == 4, "");
_Static_assert(_Alignof(M) == 2, "");
_Static_assert(sizeof(struct M_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct M_extra_alignment) == 2, "");
_Static_assert(sizeof(struct M_extra_packed) == 4, "");
_Static_assert(_Alignof(struct M_extra_packed) == 1, "");
_Static_assert(sizeof(struct M_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct M_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct M_extra_size) == 6, "");
_Static_assert(_Alignof(struct M_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(M,d) == 16, "");
_Static_assert(__builtin_bitoffsetof(M,e) == 24, "");
#endif
_Static_assert(sizeof(N) == 4, "");
_Static_assert(_Alignof(N) == 2, "");
_Static_assert(sizeof(struct N_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct N_extra_alignment) == 2, "");
_Static_assert(sizeof(struct N_extra_packed) == 4, "");
_Static_assert(_Alignof(struct N_extra_packed) == 1, "");
_Static_assert(sizeof(struct N_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct N_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct N_extra_size) == 6, "");
_Static_assert(_Alignof(struct N_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(N,d) == 8, "");
_Static_assert(__builtin_bitoffsetof(N,e) == 16, "");
#endif
_Static_assert(sizeof(O) == 3, "");
_Static_assert(_Alignof(O) == 1, "");
_Static_assert(sizeof(struct O_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct O_extra_alignment) == 1, "");
_Static_assert(sizeof(struct O_extra_packed) == 3, "");
_Static_assert(_Alignof(struct O_extra_packed) == 1, "");
_Static_assert(sizeof(struct O_extra_required_alignment) == 4, "");
_Static_assert(_Alignof(struct O_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct O_extra_size) == 5, "");
_Static_assert(_Alignof(struct O_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(O,d) == 8, "");
_Static_assert(__builtin_bitoffsetof(O,e) == 16, "");
#endif
_Static_assert(sizeof(P) == 4, "");
_Static_assert(_Alignof(P) == 2, "");
_Static_assert(sizeof(struct P_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct P_extra_alignment) == 2, "");
_Static_assert(sizeof(struct P_extra_packed) == 4, "");
_Static_assert(_Alignof(struct P_extra_packed) == 1, "");
_Static_assert(sizeof(struct P_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct P_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct P_extra_size) == 6, "");
_Static_assert(_Alignof(struct P_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(P,d) == 8, "");
_Static_assert(__builtin_bitoffsetof(P,e) == 16, "");
#endif
_Static_assert(sizeof(Q) == 4, "");
_Static_assert(_Alignof(Q) == 2, "");
_Static_assert(sizeof(struct Q_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct Q_extra_alignment) == 2, "");
_Static_assert(sizeof(struct Q_extra_packed) == 4, "");
_Static_assert(_Alignof(struct Q_extra_packed) == 1, "");
_Static_assert(sizeof(struct Q_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct Q_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct Q_extra_size) == 6, "");
_Static_assert(_Alignof(struct Q_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(Q,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(Q,d) == 9, "");
_Static_assert(__builtin_bitoffsetof(Q,e) == 16, "");
#endif
_Static_assert(sizeof(R) == 17, "");
_Static_assert(_Alignof(R) == 1, "");
_Static_assert(sizeof(struct R_extra_alignment) == 18, "");
_Static_assert(_Alignof(struct R_extra_alignment) == 1, "");
_Static_assert(sizeof(struct R_extra_packed) == 17, "");
_Static_assert(_Alignof(struct R_extra_packed) == 1, "");
_Static_assert(sizeof(struct R_extra_required_alignment) == 18, "");
_Static_assert(_Alignof(struct R_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct R_extra_size) == 19, "");
_Static_assert(_Alignof(struct R_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(R,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(R,e) == 128, "");
#endif
_Static_assert(sizeof(S) == 3, "");
_Static_assert(_Alignof(S) == 1, "");
_Static_assert(sizeof(struct S_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct S_extra_alignment) == 1, "");
_Static_assert(sizeof(struct S_extra_packed) == 3, "");
_Static_assert(_Alignof(struct S_extra_packed) == 1, "");
_Static_assert(sizeof(struct S_extra_required_alignment) == 4, "");
_Static_assert(_Alignof(struct S_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct S_extra_size) == 5, "");
_Static_assert(_Alignof(struct S_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(S,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(S,e) == 16, "");
#endif
_Static_assert(sizeof(T) == 5, "");
_Static_assert(_Alignof(T) == 1, "");
_Static_assert(sizeof(struct T_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct T_extra_alignment) == 1, "");
_Static_assert(sizeof(struct T_extra_packed) == 5, "");
_Static_assert(_Alignof(struct T_extra_packed) == 1, "");
_Static_assert(sizeof(struct T_extra_required_alignment) == 6, "");
_Static_assert(_Alignof(struct T_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct T_extra_size) == 7, "");
_Static_assert(_Alignof(struct T_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(T,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(T,e) == 32, "");
#endif
_Static_assert(sizeof(U) == 3, "");
_Static_assert(_Alignof(U) == 1, "");
_Static_assert(sizeof(struct U_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct U_extra_alignment) == 1, "");
_Static_assert(sizeof(struct U_extra_packed) == 3, "");
_Static_assert(_Alignof(struct U_extra_packed) == 1, "");
_Static_assert(sizeof(struct U_extra_required_alignment) == 4, "");
_Static_assert(_Alignof(struct U_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct U_extra_size) == 5, "");
_Static_assert(_Alignof(struct U_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(U,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(U,e) == 16, "");
#endif
_Static_assert(sizeof(V) == 3, "");
_Static_assert(_Alignof(V) == 1, "");
_Static_assert(sizeof(struct V_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct V_extra_alignment) == 1, "");
_Static_assert(sizeof(struct V_extra_packed) == 3, "");
_Static_assert(_Alignof(struct V_extra_packed) == 1, "");
_Static_assert(sizeof(struct V_extra_required_alignment) == 4, "");
_Static_assert(_Alignof(struct V_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct V_extra_size) == 5, "");
_Static_assert(_Alignof(struct V_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(V,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(V,e) == 16, "");
#endif
_Static_assert(sizeof(W) == 17, "");
_Static_assert(_Alignof(W) == 1, "");
_Static_assert(sizeof(struct W_extra_alignment) == 18, "");
_Static_assert(_Alignof(struct W_extra_alignment) == 1, "");
_Static_assert(sizeof(struct W_extra_packed) == 17, "");
_Static_assert(_Alignof(struct W_extra_packed) == 1, "");
_Static_assert(sizeof(struct W_extra_required_alignment) == 18, "");
_Static_assert(_Alignof(struct W_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct W_extra_size) == 19, "");
_Static_assert(_Alignof(struct W_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(W,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(W,e) == 128, "");
#endif
_Static_assert(sizeof(W_) == 17, "");
_Static_assert(_Alignof(W_) == 1, "");
_Static_assert(sizeof(struct W__extra_alignment) == 18, "");
_Static_assert(_Alignof(struct W__extra_alignment) == 1, "");
_Static_assert(sizeof(struct W__extra_packed) == 17, "");
_Static_assert(_Alignof(struct W__extra_packed) == 1, "");
_Static_assert(sizeof(struct W__extra_required_alignment) == 18, "");
_Static_assert(_Alignof(struct W__extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct W__extra_size) == 19, "");
_Static_assert(_Alignof(struct W__extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(W_,e) == 128, "");
#endif
_Static_assert(sizeof(X) == 17, "");
_Static_assert(_Alignof(X) == 1, "");
_Static_assert(sizeof(struct X_extra_alignment) == 18, "");
_Static_assert(_Alignof(struct X_extra_alignment) == 1, "");
_Static_assert(sizeof(struct X_extra_packed) == 17, "");
_Static_assert(_Alignof(struct X_extra_packed) == 1, "");
_Static_assert(sizeof(struct X_extra_required_alignment) == 18, "");
_Static_assert(_Alignof(struct X_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct X_extra_size) == 19, "");
_Static_assert(_Alignof(struct X_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(X,x) == 8, "");
_Static_assert(__builtin_bitoffsetof(X,e) == 128, "");
#endif
_Static_assert(sizeof(A2) == 1, "");
_Static_assert(_Alignof(A2) == 1, "");
_Static_assert(sizeof(struct A2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct A2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct A2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct A2_extra_packed) == 1, "");
_Static_assert(sizeof(struct A2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct A2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A2_extra_size) == 3, "");
_Static_assert(_Alignof(struct A2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A2,d) == 0, "");
#endif
_Static_assert(sizeof(A_2) == 1, "");
_Static_assert(_Alignof(A_2) == 1, "");
_Static_assert(sizeof(struct A_2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct A_2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct A_2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct A_2_extra_packed) == 1, "");
_Static_assert(sizeof(struct A_2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct A_2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A_2_extra_size) == 3, "");
_Static_assert(_Alignof(struct A_2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_2,d) == 0, "");
#endif
_Static_assert(sizeof(B2) == 1, "");
_Static_assert(_Alignof(B2) == 1, "");
_Static_assert(sizeof(struct B2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct B2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct B2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct B2_extra_packed) == 1, "");
_Static_assert(sizeof(struct B2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct B2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B2_extra_size) == 3, "");
_Static_assert(_Alignof(struct B2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B2,d) == 0, "");
#endif
_Static_assert(sizeof(B_2) == 1, "");
_Static_assert(_Alignof(B_2) == 1, "");
_Static_assert(sizeof(struct B_2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct B_2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct B_2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct B_2_extra_packed) == 1, "");
_Static_assert(sizeof(struct B_2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct B_2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B_2_extra_size) == 3, "");
_Static_assert(_Alignof(struct B_2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(B_2,d) == 0, "");
#endif
_Static_assert(sizeof(C2) == 1, "");
_Static_assert(_Alignof(C2) == 1, "");
_Static_assert(sizeof(struct C2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct C2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct C2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct C2_extra_packed) == 1, "");
_Static_assert(sizeof(struct C2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct C2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct C2_extra_size) == 3, "");
_Static_assert(_Alignof(struct C2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(C2,d) == 0, "");
#endif
_Static_assert(sizeof(C22) == 1, "");
_Static_assert(_Alignof(C22) == 1, "");
_Static_assert(sizeof(struct C22_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct C22_extra_alignment) == 1, "");
_Static_assert(sizeof(struct C22_extra_packed) == 1, "");
_Static_assert(_Alignof(struct C22_extra_packed) == 1, "");
_Static_assert(sizeof(struct C22_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct C22_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct C22_extra_size) == 3, "");
_Static_assert(_Alignof(struct C22_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(C22,d) == 0, "");
#endif
_Static_assert(sizeof(D2) == 8, "");
_Static_assert(_Alignof(D2) == 2, "");
_Static_assert(sizeof(struct D2_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct D2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct D2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct D2_extra_packed) == 1, "");
_Static_assert(sizeof(struct D2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct D2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct D2_extra_size) == 10, "");
_Static_assert(_Alignof(struct D2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(D2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(D2,e) == 0, "");
#endif
_Static_assert(sizeof(F2) == 16, "");
_Static_assert(_Alignof(F2) == 16, "");
_Static_assert(sizeof(struct F2_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct F2_extra_alignment) == 16, "");
_Static_assert(sizeof(struct F2_extra_packed) == 16, "");
_Static_assert(_Alignof(struct F2_extra_packed) == 1, "");
_Static_assert(sizeof(struct F2_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct F2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct F2_extra_size) == 18, "");
_Static_assert(_Alignof(struct F2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(F2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(F2,e) == 0, "");
#endif
_Static_assert(sizeof(G2) == 8, "");
_Static_assert(_Alignof(G2) == 2, "");
_Static_assert(sizeof(struct G2_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct G2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct G2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct G2_extra_packed) == 1, "");
_Static_assert(sizeof(struct G2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct G2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct G2_extra_size) == 10, "");
_Static_assert(_Alignof(struct G2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(G2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(G2,e) == 0, "");
#endif
_Static_assert(sizeof(H2) == 8, "");
_Static_assert(_Alignof(H2) == 2, "");
_Static_assert(sizeof(struct H2_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct H2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct H2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct H2_extra_packed) == 1, "");
_Static_assert(sizeof(struct H2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct H2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct H2_extra_size) == 10, "");
_Static_assert(_Alignof(struct H2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(H2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(H2,e) == 0, "");
#endif
_Static_assert(sizeof(I2) == 8, "");
_Static_assert(_Alignof(I2) == 1, "");
_Static_assert(sizeof(struct I2_extra_alignment) == 9, "");
_Static_assert(_Alignof(struct I2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct I2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct I2_extra_packed) == 1, "");
_Static_assert(sizeof(struct I2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct I2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct I2_extra_size) == 10, "");
_Static_assert(_Alignof(struct I2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(I2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(I2,e) == 0, "");
#endif
_Static_assert(sizeof(J2) == 8, "");
_Static_assert(_Alignof(J2) == 2, "");
_Static_assert(sizeof(struct J2_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct J2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct J2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct J2_extra_packed) == 1, "");
_Static_assert(sizeof(struct J2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct J2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct J2_extra_size) == 10, "");
_Static_assert(_Alignof(struct J2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(J2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(J2,e) == 0, "");
#endif
_Static_assert(sizeof(K2) == 2, "");
_Static_assert(_Alignof(K2) == 2, "");
_Static_assert(sizeof(struct K2_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct K2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct K2_extra_packed) == 2, "");
_Static_assert(_Alignof(struct K2_extra_packed) == 1, "");
_Static_assert(sizeof(struct K2_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct K2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct K2_extra_size) == 4, "");
_Static_assert(_Alignof(struct K2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(K2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(K2,e) == 0, "");
#endif
_Static_assert(sizeof(L2) == 16, "");
_Static_assert(_Alignof(L2) == 16, "");
_Static_assert(sizeof(struct L2_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct L2_extra_alignment) == 16, "");
_Static_assert(sizeof(struct L2_extra_packed) == 16, "");
_Static_assert(_Alignof(struct L2_extra_packed) == 1, "");
_Static_assert(sizeof(struct L2_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct L2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct L2_extra_size) == 18, "");
_Static_assert(_Alignof(struct L2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(L2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(L2,e) == 0, "");
#endif
_Static_assert(sizeof(M2) == 2, "");
_Static_assert(_Alignof(M2) == 2, "");
_Static_assert(sizeof(struct M2_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct M2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct M2_extra_packed) == 2, "");
_Static_assert(_Alignof(struct M2_extra_packed) == 1, "");
_Static_assert(sizeof(struct M2_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct M2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct M2_extra_size) == 4, "");
_Static_assert(_Alignof(struct M2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(M2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(M2,e) == 0, "");
#endif
_Static_assert(sizeof(N2) == 2, "");
_Static_assert(_Alignof(N2) == 2, "");
_Static_assert(sizeof(struct N2_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct N2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct N2_extra_packed) == 2, "");
_Static_assert(_Alignof(struct N2_extra_packed) == 1, "");
_Static_assert(sizeof(struct N2_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct N2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct N2_extra_size) == 4, "");
_Static_assert(_Alignof(struct N2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(N2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(N2,e) == 0, "");
#endif
_Static_assert(sizeof(O2) == 1, "");
_Static_assert(_Alignof(O2) == 1, "");
_Static_assert(sizeof(struct O2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct O2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct O2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct O2_extra_packed) == 1, "");
_Static_assert(sizeof(struct O2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct O2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct O2_extra_size) == 3, "");
_Static_assert(_Alignof(struct O2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(O2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(O2,e) == 0, "");
#endif
_Static_assert(sizeof(P2) == 2, "");
_Static_assert(_Alignof(P2) == 2, "");
_Static_assert(sizeof(struct P2_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct P2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct P2_extra_packed) == 2, "");
_Static_assert(_Alignof(struct P2_extra_packed) == 1, "");
_Static_assert(sizeof(struct P2_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct P2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct P2_extra_size) == 4, "");
_Static_assert(_Alignof(struct P2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(P2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(P2,e) == 0, "");
#endif
_Static_assert(sizeof(Q2) == 2, "");
_Static_assert(_Alignof(Q2) == 2, "");
_Static_assert(sizeof(struct Q2_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct Q2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct Q2_extra_packed) == 2, "");
_Static_assert(_Alignof(struct Q2_extra_packed) == 1, "");
_Static_assert(sizeof(struct Q2_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct Q2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct Q2_extra_size) == 4, "");
_Static_assert(_Alignof(struct Q2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(Q2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(Q2,d) == 0, "");
_Static_assert(__builtin_bitoffsetof(Q2,e) == 0, "");
#endif
_Static_assert(sizeof(R2) == 1, "");
_Static_assert(_Alignof(R2) == 1, "");
_Static_assert(sizeof(struct R2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct R2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct R2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct R2_extra_packed) == 1, "");
_Static_assert(sizeof(struct R2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct R2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct R2_extra_size) == 3, "");
_Static_assert(_Alignof(struct R2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(R2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(R2,e) == 0, "");
#endif
_Static_assert(sizeof(S2) == 1, "");
_Static_assert(_Alignof(S2) == 1, "");
_Static_assert(sizeof(struct S2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct S2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct S2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct S2_extra_packed) == 1, "");
_Static_assert(sizeof(struct S2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct S2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct S2_extra_size) == 3, "");
_Static_assert(_Alignof(struct S2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(S2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(S2,e) == 0, "");
#endif
_Static_assert(sizeof(T2) == 1, "");
_Static_assert(_Alignof(T2) == 1, "");
_Static_assert(sizeof(struct T2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct T2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct T2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct T2_extra_packed) == 1, "");
_Static_assert(sizeof(struct T2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct T2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct T2_extra_size) == 3, "");
_Static_assert(_Alignof(struct T2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(T2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(T2,e) == 0, "");
#endif
_Static_assert(sizeof(U2) == 1, "");
_Static_assert(_Alignof(U2) == 1, "");
_Static_assert(sizeof(struct U2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct U2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct U2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct U2_extra_packed) == 1, "");
_Static_assert(sizeof(struct U2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct U2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct U2_extra_size) == 3, "");
_Static_assert(_Alignof(struct U2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(U2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(U2,e) == 0, "");
#endif
_Static_assert(sizeof(V2) == 1, "");
_Static_assert(_Alignof(V2) == 1, "");
_Static_assert(sizeof(struct V2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct V2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct V2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct V2_extra_packed) == 1, "");
_Static_assert(sizeof(struct V2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct V2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct V2_extra_size) == 3, "");
_Static_assert(_Alignof(struct V2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(V2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(V2,e) == 0, "");
#endif
_Static_assert(sizeof(W2) == 1, "");
_Static_assert(_Alignof(W2) == 1, "");
_Static_assert(sizeof(struct W2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct W2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct W2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct W2_extra_packed) == 1, "");
_Static_assert(sizeof(struct W2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct W2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct W2_extra_size) == 3, "");
_Static_assert(_Alignof(struct W2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(W2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(W2,e) == 0, "");
#endif
_Static_assert(sizeof(W_2) == 1, "");
_Static_assert(_Alignof(W_2) == 1, "");
_Static_assert(sizeof(struct W_2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct W_2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct W_2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct W_2_extra_packed) == 1, "");
_Static_assert(sizeof(struct W_2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct W_2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct W_2_extra_size) == 3, "");
_Static_assert(_Alignof(struct W_2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(W_2,e) == 0, "");
#endif
_Static_assert(sizeof(X2) == 1, "");
_Static_assert(_Alignof(X2) == 1, "");
_Static_assert(sizeof(struct X2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct X2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct X2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct X2_extra_packed) == 1, "");
_Static_assert(sizeof(struct X2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct X2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct X2_extra_size) == 3, "");
_Static_assert(_Alignof(struct X2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(X2,x) == 0, "");
_Static_assert(__builtin_bitoffsetof(X2,e) == 0, "");
#endif
_Static_assert(sizeof(Y) == 3, "");
_Static_assert(_Alignof(Y) == 1, "");
_Static_assert(sizeof(struct Y_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct Y_extra_alignment) == 1, "");
_Static_assert(sizeof(struct Y_extra_packed) == 3, "");
_Static_assert(_Alignof(struct Y_extra_packed) == 1, "");
_Static_assert(sizeof(struct Y_extra_required_alignment) == 4, "");
_Static_assert(_Alignof(struct Y_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct Y_extra_size) == 5, "");
_Static_assert(_Alignof(struct Y_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(Y,d) == 16, "");
#endif
_Static_assert(sizeof(Y2) == 1, "");
_Static_assert(_Alignof(Y2) == 1, "");
_Static_assert(sizeof(struct Y2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct Y2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct Y2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct Y2_extra_packed) == 1, "");
_Static_assert(sizeof(struct Y2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct Y2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct Y2_extra_size) == 3, "");
_Static_assert(_Alignof(struct Y2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(Y2,d) == 0, "");
#endif
_Static_assert(sizeof(A3) == 33, "");
_Static_assert(_Alignof(A3) == 1, "");
_Static_assert(sizeof(struct A3_extra_alignment) == 34, "");
_Static_assert(_Alignof(struct A3_extra_alignment) == 1, "");
_Static_assert(sizeof(struct A3_extra_packed) == 33, "");
_Static_assert(_Alignof(struct A3_extra_packed) == 1, "");
_Static_assert(sizeof(struct A3_extra_required_alignment) == 34, "");
_Static_assert(_Alignof(struct A3_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A3_extra_size) == 35, "");
_Static_assert(_Alignof(struct A3_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A3,d) == 256, "");
#endif
_Static_assert(sizeof(A4) == 1, "");
_Static_assert(_Alignof(A4) == 32, "");
_Static_assert(sizeof(struct A4_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct A4_extra_alignment) == 32, "");
_Static_assert(sizeof(struct A4_extra_packed) == 1, "");
_Static_assert(_Alignof(struct A4_extra_packed) == 1, "");
_Static_assert(sizeof(struct A4_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct A4_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A4_extra_size) == 3, "");
_Static_assert(_Alignof(struct A4_extra_size) == 1, "");
_Static_assert(sizeof(A5) == 33, "");
_Static_assert(_Alignof(A5) == 1, "");
_Static_assert(sizeof(struct A5_extra_alignment) == 34, "");
_Static_assert(_Alignof(struct A5_extra_alignment) == 1, "");
_Static_assert(sizeof(struct A5_extra_packed) == 33, "");
_Static_assert(_Alignof(struct A5_extra_packed) == 1, "");
_Static_assert(sizeof(struct A5_extra_required_alignment) == 34, "");
_Static_assert(_Alignof(struct A5_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A5_extra_size) == 35, "");
_Static_assert(_Alignof(struct A5_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A5,d) == 256, "");
#endif
_Static_assert(sizeof(A7) == 32, "");
_Static_assert(_Alignof(A7) == 32, "");
_Static_assert(sizeof(struct A7_extra_alignment) == 64, "");
_Static_assert(_Alignof(struct A7_extra_alignment) == 32, "");
_Static_assert(sizeof(struct A7_extra_packed) == 32, "");
_Static_assert(_Alignof(struct A7_extra_packed) == 1, "");
_Static_assert(sizeof(struct A7_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct A7_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A7_extra_size) == 34, "");
_Static_assert(_Alignof(struct A7_extra_size) == 1, "");
_Static_assert(sizeof(A8) == 6, "");
_Static_assert(_Alignof(A8) == 2, "");
_Static_assert(sizeof(struct A8_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct A8_extra_alignment) == 2, "");
_Static_assert(sizeof(struct A8_extra_packed) == 6, "");
_Static_assert(_Alignof(struct A8_extra_packed) == 1, "");
_Static_assert(sizeof(struct A8_extra_required_alignment) == 7, "");
_Static_assert(_Alignof(struct A8_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A8_extra_size) == 8, "");
_Static_assert(_Alignof(struct A8_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A8,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A8,j) == 39, "");
#endif
_Static_assert(sizeof(A9) == 10, "");
_Static_assert(_Alignof(A9) == 2, "");
_Static_assert(sizeof(struct A9_extra_alignment) == 12, "");
_Static_assert(_Alignof(struct A9_extra_alignment) == 2, "");
_Static_assert(sizeof(struct A9_extra_packed) == 10, "");
_Static_assert(_Alignof(struct A9_extra_packed) == 1, "");
_Static_assert(sizeof(struct A9_extra_required_alignment) == 11, "");
_Static_assert(_Alignof(struct A9_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A9_extra_size) == 12, "");
_Static_assert(_Alignof(struct A9_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A9,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A9,j) == 48, "");
#endif
_Static_assert(sizeof(A10) == 4, "");
_Static_assert(_Alignof(A10) == 16, "");
_Static_assert(sizeof(struct A10_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct A10_extra_alignment) == 16, "");
_Static_assert(sizeof(struct A10_extra_packed) == 4, "");
_Static_assert(_Alignof(struct A10_extra_packed) == 1, "");
_Static_assert(sizeof(struct A10_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct A10_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A10_extra_size) == 6, "");
_Static_assert(_Alignof(struct A10_extra_size) == 1, "");
_Static_assert(sizeof(A11) == 32, "");
_Static_assert(_Alignof(A11) == 16, "");
_Static_assert(sizeof(struct A11_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct A11_extra_alignment) == 16, "");
_Static_assert(sizeof(struct A11_extra_packed) == 32, "");
_Static_assert(_Alignof(struct A11_extra_packed) == 1, "");
_Static_assert(sizeof(struct A11_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct A11_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A11_extra_size) == 34, "");
_Static_assert(_Alignof(struct A11_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A11,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A11,j) == 128, "");
#endif
_Static_assert(sizeof(A12) == 32, "");
_Static_assert(_Alignof(A12) == 16, "");
_Static_assert(sizeof(struct A12_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct A12_extra_alignment) == 16, "");
_Static_assert(sizeof(struct A12_extra_packed) == 32, "");
_Static_assert(_Alignof(struct A12_extra_packed) == 1, "");
_Static_assert(sizeof(struct A12_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct A12_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A12_extra_size) == 34, "");
_Static_assert(_Alignof(struct A12_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A12,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A12,j) == 128, "");
#endif
_Static_assert(sizeof(A13) == 32, "");
_Static_assert(_Alignof(A13) == 16, "");
_Static_assert(sizeof(struct A13_extra_alignment) == 48, "");
_Static_assert(_Alignof(struct A13_extra_alignment) == 16, "");
_Static_assert(sizeof(struct A13_extra_packed) == 32, "");
_Static_assert(_Alignof(struct A13_extra_packed) == 1, "");
_Static_assert(sizeof(struct A13_extra_required_alignment) == 33, "");
_Static_assert(_Alignof(struct A13_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A13_extra_size) == 34, "");
_Static_assert(_Alignof(struct A13_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(A13,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A13,j) == 128, "");
_Static_assert(__builtin_bitoffsetof(A13,d) == 136, "");
#endif
#endif
