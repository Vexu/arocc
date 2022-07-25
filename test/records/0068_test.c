// SPDX-License-Identifier: GPL-3.0-or-later

// This test file is auto-generated. do not edit.
// This file is a derivative work from the test files found// in this repo : https://github.com/mahkoh/repr-c
// and is under the same licence as the original work.

typedef struct {
    char:0 __attribute__((aligned(4)));
    char d;
} A;
A var1;
struct A_alignment {
    char a;
    A b;
};
struct A_alignment var2;
#pragma pack(1)
struct A_packed {
    A a;
};
#pragma pack()
struct A_required_alignment {
    char a;
    struct A_packed b;
};
struct A_required_alignment var3;
struct A_size {
    char a[sizeof(A)+1];
    char b;
};
struct A_size var4;

typedef struct {
    char c;
    char:0 __attribute__((aligned(4)));
    char d;
} A_;
A_ var5;
struct A__alignment {
    char a;
    A_ b;
};
struct A__alignment var6;
#pragma pack(1)
struct A__packed {
    A_ a;
};
#pragma pack()
struct A__required_alignment {
    char a;
    struct A__packed b;
};
struct A__required_alignment var7;
struct A__size {
    char a[sizeof(A_)+1];
    char b;
};
struct A__size var8;

typedef struct {
    long long:0 __attribute__((aligned(4)));
    char d;
} B;
B var9;
struct B_alignment {
    char a;
    B b;
};
struct B_alignment var10;
#pragma pack(1)
struct B_packed {
    B a;
};
#pragma pack()
struct B_required_alignment {
    char a;
    struct B_packed b;
};
struct B_required_alignment var11;
struct B_size {
    char a[sizeof(B)+1];
    char b;
};
struct B_size var12;

typedef struct {
    char c;
    long long:0 __attribute__((aligned(4)));
    char d;
} B_;
B_ var13;
struct B__alignment {
    char a;
    B_ b;
};
struct B__alignment var14;
#pragma pack(1)
struct B__packed {
    B_ a;
};
#pragma pack()
struct B__required_alignment {
    char a;
    struct B__packed b;
};
struct B__required_alignment var15;
struct B__size {
    char a[sizeof(B_)+1];
    char b;
};
struct B__size var16;

typedef struct {
    long long:0;
    char d;
} C;
C var17;
struct C_alignment {
    char a;
    C b;
};
struct C_alignment var18;
#pragma pack(1)
struct C_packed {
    C a;
};
#pragma pack()
struct C_required_alignment {
    char a;
    struct C_packed b;
};
struct C_required_alignment var19;
struct C_size {
    char a[sizeof(C)+1];
    char b;
};
struct C_size var20;

typedef struct {
    char c;
    long long:0;
    char d;
} C_;
C_ var21;
struct C__alignment {
    char a;
    C_ b;
};
struct C__alignment var22;
#pragma pack(1)
struct C__packed {
    C_ a;
};
#pragma pack()
struct C__required_alignment {
    char a;
    struct C__packed b;
};
struct C__required_alignment var23;
struct C__size {
    char a[sizeof(C_)+1];
    char b;
};
struct C__size var24;

typedef struct {
    char c;
    long long d;
    char e;
} D;
D var25;
struct D_alignment {
    char a;
    D b;
};
struct D_alignment var26;
#pragma pack(1)
struct D_packed {
    D a;
};
#pragma pack()
struct D_required_alignment {
    char a;
    struct D_packed b;
};
struct D_required_alignment var27;
struct D_size {
    char a[sizeof(D)+1];
    char b;
};
struct D_size var28;

typedef struct {
    char c;
    long long d __attribute__((aligned(16)));
    char e;
} F;
F var29;
struct F_alignment {
    char a;
    F b;
};
struct F_alignment var30;
#pragma pack(1)
struct F_packed {
    F a;
};
#pragma pack()
struct F_required_alignment {
    char a;
    struct F_packed b;
};
struct F_required_alignment var31;
struct F_size {
    char a[sizeof(F)+1];
    char b;
};
struct F_size var32;

typedef struct {
    char c;
    long long d __attribute__((aligned(2))) __attribute__((packed));
    char e;
} G;
G var33;
struct G_alignment {
    char a;
    G b;
};
struct G_alignment var34;
#pragma pack(1)
struct G_packed {
    G a;
};
#pragma pack()
struct G_required_alignment {
    char a;
    struct G_packed b;
};
struct G_required_alignment var35;
struct G_size {
    char a[sizeof(G)+1];
    char b;
};
struct G_size var36;

#pragma pack(2)
typedef struct {
    char c;
    long long d __attribute__((aligned(4))) __attribute__((packed));
    char e;
} H;
H var37;
#pragma pack()
struct H_alignment {
    char a;
    H b;
};
struct H_alignment var38;
#pragma pack(1)
struct H_packed {
    H a;
};
#pragma pack()
struct H_required_alignment {
    char a;
    struct H_packed b;
};
struct H_required_alignment var39;
struct H_size {
    char a[sizeof(H)+1];
    char b;
};
struct H_size var40;

typedef struct {
    char c;
    long long d __attribute__((packed));
    char e;
} I;
I var41;
struct I_alignment {
    char a;
    I b;
};
struct I_alignment var42;
#pragma pack(1)
struct I_packed {
    I a;
};
#pragma pack()
struct I_required_alignment {
    char a;
    struct I_packed b;
};
struct I_required_alignment var43;
struct I_size {
    char a[sizeof(I)+1];
    char b;
};
struct I_size var44;

#pragma pack(2)
typedef struct {
    char c;
    long long d;
    char e;
} J;
J var45;
#pragma pack()
struct J_alignment {
    char a;
    J b;
};
struct J_alignment var46;
#pragma pack(1)
struct J_packed {
    J a;
};
#pragma pack()
struct J_required_alignment {
    char a;
    struct J_packed b;
};
struct J_required_alignment var47;
struct J_size {
    char a[sizeof(J)+1];
    char b;
};
struct J_size var48;

typedef struct {
    char c;
    long long d:1;
    char e;
} K;
K var49;
struct K_alignment {
    char a;
    K b;
};
struct K_alignment var50;
#pragma pack(1)
struct K_packed {
    K a;
};
#pragma pack()
struct K_required_alignment {
    char a;
    struct K_packed b;
};
struct K_required_alignment var51;
struct K_size {
    char a[sizeof(K)+1];
    char b;
};
struct K_size var52;

typedef struct {
    char c;
    long long d:1 __attribute__((aligned(16)));
    char e;
} L;
L var53;
struct L_alignment {
    char a;
    L b;
};
struct L_alignment var54;
#pragma pack(1)
struct L_packed {
    L a;
};
#pragma pack()
struct L_required_alignment {
    char a;
    struct L_packed b;
};
struct L_required_alignment var55;
struct L_size {
    char a[sizeof(L)+1];
    char b;
};
struct L_size var56;

typedef struct {
    char c;
    long long d:1 __attribute__((aligned(2))) __attribute__((packed));
    char e;
} M;
M var57;
struct M_alignment {
    char a;
    M b;
};
struct M_alignment var58;
#pragma pack(1)
struct M_packed {
    M a;
};
#pragma pack()
struct M_required_alignment {
    char a;
    struct M_packed b;
};
struct M_required_alignment var59;
struct M_size {
    char a[sizeof(M)+1];
    char b;
};
struct M_size var60;

#pragma pack(2)
typedef struct {
    char c;
    long long d:1 __attribute__((aligned(4))) __attribute__((packed));
    char e;
} N;
N var61;
#pragma pack()
struct N_alignment {
    char a;
    N b;
};
struct N_alignment var62;
#pragma pack(1)
struct N_packed {
    N a;
};
#pragma pack()
struct N_required_alignment {
    char a;
    struct N_packed b;
};
struct N_required_alignment var63;
struct N_size {
    char a[sizeof(N)+1];
    char b;
};
struct N_size var64;

typedef struct {
    char c;
    long long d:1 __attribute__((packed));
    char e;
} O;
O var65;
struct O_alignment {
    char a;
    O b;
};
struct O_alignment var66;
#pragma pack(1)
struct O_packed {
    O a;
};
#pragma pack()
struct O_required_alignment {
    char a;
    struct O_packed b;
};
struct O_required_alignment var67;
struct O_size {
    char a[sizeof(O)+1];
    char b;
};
struct O_size var68;

#pragma pack(2)
typedef struct {
    char c;
    long long d:1;
    char e;
} P;
P var69;
#pragma pack()
struct P_alignment {
    char a;
    P b;
};
struct P_alignment var70;
#pragma pack(1)
struct P_packed {
    P a;
};
#pragma pack()
struct P_required_alignment {
    char a;
    struct P_packed b;
};
struct P_required_alignment var71;
struct P_size {
    char a[sizeof(P)+1];
    char b;
};
struct P_size var72;

typedef struct {
    char c;
    char x:1;
    long long d:1;
    char e;
} Q;
Q var73;
struct Q_alignment {
    char a;
    Q b;
};
struct Q_alignment var74;
#pragma pack(1)
struct Q_packed {
    Q a;
};
#pragma pack()
struct Q_required_alignment {
    char a;
    struct Q_packed b;
};
struct Q_required_alignment var75;
struct Q_size {
    char a[sizeof(Q)+1];
    char b;
};
struct Q_size var76;

typedef struct {
    char c;
    char x:1;
    long long:0 __attribute__((aligned(16)));
    char e;
} R;
R var77;
struct R_alignment {
    char a;
    R b;
};
struct R_alignment var78;
#pragma pack(1)
struct R_packed {
    R a;
};
#pragma pack()
struct R_required_alignment {
    char a;
    struct R_packed b;
};
struct R_required_alignment var79;
struct R_size {
    char a[sizeof(R)+1];
    char b;
};
struct R_size var80;

typedef struct {
    char c;
    char x:1;
    long long:0 __attribute__((aligned(2))) __attribute__((packed));
    char e;
} S;
S var81;
struct S_alignment {
    char a;
    S b;
};
struct S_alignment var82;
#pragma pack(1)
struct S_packed {
    S a;
};
#pragma pack()
struct S_required_alignment {
    char a;
    struct S_packed b;
};
struct S_required_alignment var83;
struct S_size {
    char a[sizeof(S)+1];
    char b;
};
struct S_size var84;

#pragma pack(2)
typedef struct {
    char c;
    char x:1;
    long long:0 __attribute__((aligned(4))) __attribute__((packed));
    char e;
} T;
T var85;
#pragma pack()
struct T_alignment {
    char a;
    T b;
};
struct T_alignment var86;
#pragma pack(1)
struct T_packed {
    T a;
};
#pragma pack()
struct T_required_alignment {
    char a;
    struct T_packed b;
};
struct T_required_alignment var87;
struct T_size {
    char a[sizeof(T)+1];
    char b;
};
struct T_size var88;

typedef struct {
    char c;
    char x:1;
    long long:0 __attribute__((packed));
    char e;
} U;
U var89;
struct U_alignment {
    char a;
    U b;
};
struct U_alignment var90;
#pragma pack(1)
struct U_packed {
    U a;
};
#pragma pack()
struct U_required_alignment {
    char a;
    struct U_packed b;
};
struct U_required_alignment var91;
struct U_size {
    char a[sizeof(U)+1];
    char b;
};
struct U_size var92;

#pragma pack(2)
typedef struct {
    char c;
    char x:1;
    long long:0;
    char e;
} V;
V var93;
#pragma pack()
struct V_alignment {
    char a;
    V b;
};
struct V_alignment var94;
#pragma pack(1)
struct V_packed {
    V a;
};
#pragma pack()
struct V_required_alignment {
    char a;
    struct V_packed b;
};
struct V_required_alignment var95;
struct V_size {
    char a[sizeof(V)+1];
    char b;
};
struct V_size var96;

typedef struct {
    char c;
    char x:1;
    long long:0 __attribute__((aligned(16))) __attribute__((packed));
    char e;
} W;
W var97;
struct W_alignment {
    char a;
    W b;
};
struct W_alignment var98;
#pragma pack(1)
struct W_packed {
    W a;
};
#pragma pack()
struct W_required_alignment {
    char a;
    struct W_packed b;
};
struct W_required_alignment var99;
struct W_size {
    char a[sizeof(W)+1];
    char b;
};
struct W_size var100;

#pragma pack(1)
typedef struct {
    char c;
    long long:0 __attribute__((aligned(16)));
    char e;
} W_;
W_ var101;
#pragma pack()
struct W__alignment {
    char a;
    W_ b;
};
struct W__alignment var102;
#pragma pack(1)
struct W__packed {
    W_ a;
};
#pragma pack()
struct W__required_alignment {
    char a;
    struct W__packed b;
};
struct W__required_alignment var103;
struct W__size {
    char a[sizeof(W_)+1];
    char b;
};
struct W__size var104;

#pragma pack(2)
typedef struct {
    char c;
    char x:1;
    long long:0 __attribute__((aligned(16))) __attribute__((packed));
    char e;
} X;
X var105;
#pragma pack()
struct X_alignment {
    char a;
    X b;
};
struct X_alignment var106;
#pragma pack(1)
struct X_packed {
    X a;
};
#pragma pack()
struct X_required_alignment {
    char a;
    struct X_packed b;
};
struct X_required_alignment var107;
struct X_size {
    char a[sizeof(X)+1];
    char b;
};
struct X_size var108;

typedef union {
    char:0 __attribute__((aligned(4)));
    char d;
} A2;
A2 var109;
struct A2_alignment {
    char a;
    A2 b;
};
struct A2_alignment var110;
#pragma pack(1)
struct A2_packed {
    A2 a;
};
#pragma pack()
struct A2_required_alignment {
    char a;
    struct A2_packed b;
};
struct A2_required_alignment var111;
struct A2_size {
    char a[sizeof(A2)+1];
    char b;
};
struct A2_size var112;

typedef union {
    char c;
    char:0 __attribute__((aligned(4)));
    char d;
} A_2;
A_2 var113;
struct A_2_alignment {
    char a;
    A_2 b;
};
struct A_2_alignment var114;
#pragma pack(1)
struct A_2_packed {
    A_2 a;
};
#pragma pack()
struct A_2_required_alignment {
    char a;
    struct A_2_packed b;
};
struct A_2_required_alignment var115;
struct A_2_size {
    char a[sizeof(A_2)+1];
    char b;
};
struct A_2_size var116;

typedef union {
    long long:0 __attribute__((aligned(4)));
    char d;
} B2;
B2 var117;
struct B2_alignment {
    char a;
    B2 b;
};
struct B2_alignment var118;
#pragma pack(1)
struct B2_packed {
    B2 a;
};
#pragma pack()
struct B2_required_alignment {
    char a;
    struct B2_packed b;
};
struct B2_required_alignment var119;
struct B2_size {
    char a[sizeof(B2)+1];
    char b;
};
struct B2_size var120;

typedef union {
    char c;
    long long:0 __attribute__((aligned(4)));
    char d;
} B_2;
B_2 var121;
struct B_2_alignment {
    char a;
    B_2 b;
};
struct B_2_alignment var122;
#pragma pack(1)
struct B_2_packed {
    B_2 a;
};
#pragma pack()
struct B_2_required_alignment {
    char a;
    struct B_2_packed b;
};
struct B_2_required_alignment var123;
struct B_2_size {
    char a[sizeof(B_2)+1];
    char b;
};
struct B_2_size var124;

typedef union {
    long long:0;
    char d;
} C2;
C2 var125;
struct C2_alignment {
    char a;
    C2 b;
};
struct C2_alignment var126;
#pragma pack(1)
struct C2_packed {
    C2 a;
};
#pragma pack()
struct C2_required_alignment {
    char a;
    struct C2_packed b;
};
struct C2_required_alignment var127;
struct C2_size {
    char a[sizeof(C2)+1];
    char b;
};
struct C2_size var128;

typedef union {
    char c;
    long long:0;
    char d;
} C22;
C22 var129;
struct C22_alignment {
    char a;
    C22 b;
};
struct C22_alignment var130;
#pragma pack(1)
struct C22_packed {
    C22 a;
};
#pragma pack()
struct C22_required_alignment {
    char a;
    struct C22_packed b;
};
struct C22_required_alignment var131;
struct C22_size {
    char a[sizeof(C22)+1];
    char b;
};
struct C22_size var132;

typedef union {
    char c;
    long long d;
    char e;
} D2;
D2 var133;
struct D2_alignment {
    char a;
    D2 b;
};
struct D2_alignment var134;
#pragma pack(1)
struct D2_packed {
    D2 a;
};
#pragma pack()
struct D2_required_alignment {
    char a;
    struct D2_packed b;
};
struct D2_required_alignment var135;
struct D2_size {
    char a[sizeof(D2)+1];
    char b;
};
struct D2_size var136;

typedef union {
    char c;
    long long d __attribute__((aligned(16)));
    char e;
} F2;
F2 var137;
struct F2_alignment {
    char a;
    F2 b;
};
struct F2_alignment var138;
#pragma pack(1)
struct F2_packed {
    F2 a;
};
#pragma pack()
struct F2_required_alignment {
    char a;
    struct F2_packed b;
};
struct F2_required_alignment var139;
struct F2_size {
    char a[sizeof(F2)+1];
    char b;
};
struct F2_size var140;

typedef union {
    char c;
    long long d __attribute__((aligned(2))) __attribute__((packed));
    char e;
} G2;
G2 var141;
struct G2_alignment {
    char a;
    G2 b;
};
struct G2_alignment var142;
#pragma pack(1)
struct G2_packed {
    G2 a;
};
#pragma pack()
struct G2_required_alignment {
    char a;
    struct G2_packed b;
};
struct G2_required_alignment var143;
struct G2_size {
    char a[sizeof(G2)+1];
    char b;
};
struct G2_size var144;

#pragma pack(2)
typedef union {
    char c;
    long long d __attribute__((aligned(4))) __attribute__((packed));
    char e;
} H2;
H2 var145;
#pragma pack()
struct H2_alignment {
    char a;
    H2 b;
};
struct H2_alignment var146;
#pragma pack(1)
struct H2_packed {
    H2 a;
};
#pragma pack()
struct H2_required_alignment {
    char a;
    struct H2_packed b;
};
struct H2_required_alignment var147;
struct H2_size {
    char a[sizeof(H2)+1];
    char b;
};
struct H2_size var148;

typedef union {
    char c;
    long long d __attribute__((packed));
    char e;
} I2;
I2 var149;
struct I2_alignment {
    char a;
    I2 b;
};
struct I2_alignment var150;
#pragma pack(1)
struct I2_packed {
    I2 a;
};
#pragma pack()
struct I2_required_alignment {
    char a;
    struct I2_packed b;
};
struct I2_required_alignment var151;
struct I2_size {
    char a[sizeof(I2)+1];
    char b;
};
struct I2_size var152;

#pragma pack(2)
typedef union {
    char c;
    long long d;
    char e;
} J2;
J2 var153;
#pragma pack()
struct J2_alignment {
    char a;
    J2 b;
};
struct J2_alignment var154;
#pragma pack(1)
struct J2_packed {
    J2 a;
};
#pragma pack()
struct J2_required_alignment {
    char a;
    struct J2_packed b;
};
struct J2_required_alignment var155;
struct J2_size {
    char a[sizeof(J2)+1];
    char b;
};
struct J2_size var156;

typedef union {
    char c;
    long long d:1;
    char e;
} K2;
K2 var157;
struct K2_alignment {
    char a;
    K2 b;
};
struct K2_alignment var158;
#pragma pack(1)
struct K2_packed {
    K2 a;
};
#pragma pack()
struct K2_required_alignment {
    char a;
    struct K2_packed b;
};
struct K2_required_alignment var159;
struct K2_size {
    char a[sizeof(K2)+1];
    char b;
};
struct K2_size var160;

typedef union {
    char c;
    long long d:1 __attribute__((aligned(16)));
    char e;
} L2;
L2 var161;
struct L2_alignment {
    char a;
    L2 b;
};
struct L2_alignment var162;
#pragma pack(1)
struct L2_packed {
    L2 a;
};
#pragma pack()
struct L2_required_alignment {
    char a;
    struct L2_packed b;
};
struct L2_required_alignment var163;
struct L2_size {
    char a[sizeof(L2)+1];
    char b;
};
struct L2_size var164;

typedef union {
    char c;
    long long d:1 __attribute__((aligned(2))) __attribute__((packed));
    char e;
} M2;
M2 var165;
struct M2_alignment {
    char a;
    M2 b;
};
struct M2_alignment var166;
#pragma pack(1)
struct M2_packed {
    M2 a;
};
#pragma pack()
struct M2_required_alignment {
    char a;
    struct M2_packed b;
};
struct M2_required_alignment var167;
struct M2_size {
    char a[sizeof(M2)+1];
    char b;
};
struct M2_size var168;

#pragma pack(2)
typedef union {
    char c;
    long long d:1 __attribute__((aligned(4))) __attribute__((packed));
    char e;
} N2;
N2 var169;
#pragma pack()
struct N2_alignment {
    char a;
    N2 b;
};
struct N2_alignment var170;
#pragma pack(1)
struct N2_packed {
    N2 a;
};
#pragma pack()
struct N2_required_alignment {
    char a;
    struct N2_packed b;
};
struct N2_required_alignment var171;
struct N2_size {
    char a[sizeof(N2)+1];
    char b;
};
struct N2_size var172;

typedef union {
    char c;
    long long d:1 __attribute__((packed));
    char e;
} O2;
O2 var173;
struct O2_alignment {
    char a;
    O2 b;
};
struct O2_alignment var174;
#pragma pack(1)
struct O2_packed {
    O2 a;
};
#pragma pack()
struct O2_required_alignment {
    char a;
    struct O2_packed b;
};
struct O2_required_alignment var175;
struct O2_size {
    char a[sizeof(O2)+1];
    char b;
};
struct O2_size var176;

#pragma pack(2)
typedef union {
    char c;
    long long d:1;
    char e;
} P2;
P2 var177;
#pragma pack()
struct P2_alignment {
    char a;
    P2 b;
};
struct P2_alignment var178;
#pragma pack(1)
struct P2_packed {
    P2 a;
};
#pragma pack()
struct P2_required_alignment {
    char a;
    struct P2_packed b;
};
struct P2_required_alignment var179;
struct P2_size {
    char a[sizeof(P2)+1];
    char b;
};
struct P2_size var180;

typedef union {
    char c;
    char x:1;
    long long d:1;
    char e;
} Q2;
Q2 var181;
struct Q2_alignment {
    char a;
    Q2 b;
};
struct Q2_alignment var182;
#pragma pack(1)
struct Q2_packed {
    Q2 a;
};
#pragma pack()
struct Q2_required_alignment {
    char a;
    struct Q2_packed b;
};
struct Q2_required_alignment var183;
struct Q2_size {
    char a[sizeof(Q2)+1];
    char b;
};
struct Q2_size var184;

typedef union {
    char c;
    char x:1;
    long long:0 __attribute__((aligned(16)));
    char e;
} R2;
R2 var185;
struct R2_alignment {
    char a;
    R2 b;
};
struct R2_alignment var186;
#pragma pack(1)
struct R2_packed {
    R2 a;
};
#pragma pack()
struct R2_required_alignment {
    char a;
    struct R2_packed b;
};
struct R2_required_alignment var187;
struct R2_size {
    char a[sizeof(R2)+1];
    char b;
};
struct R2_size var188;

typedef union {
    char c;
    char x:1;
    long long:0 __attribute__((aligned(2))) __attribute__((packed));
    char e;
} S2;
S2 var189;
struct S2_alignment {
    char a;
    S2 b;
};
struct S2_alignment var190;
#pragma pack(1)
struct S2_packed {
    S2 a;
};
#pragma pack()
struct S2_required_alignment {
    char a;
    struct S2_packed b;
};
struct S2_required_alignment var191;
struct S2_size {
    char a[sizeof(S2)+1];
    char b;
};
struct S2_size var192;

#pragma pack(2)
typedef union {
    char c;
    char x:1;
    long long:0 __attribute__((aligned(4))) __attribute__((packed));
    char e;
} T2;
T2 var193;
#pragma pack()
struct T2_alignment {
    char a;
    T2 b;
};
struct T2_alignment var194;
#pragma pack(1)
struct T2_packed {
    T2 a;
};
#pragma pack()
struct T2_required_alignment {
    char a;
    struct T2_packed b;
};
struct T2_required_alignment var195;
struct T2_size {
    char a[sizeof(T2)+1];
    char b;
};
struct T2_size var196;

typedef union {
    char c;
    char x:1;
    long long:0 __attribute__((packed));
    char e;
} U2;
U2 var197;
struct U2_alignment {
    char a;
    U2 b;
};
struct U2_alignment var198;
#pragma pack(1)
struct U2_packed {
    U2 a;
};
#pragma pack()
struct U2_required_alignment {
    char a;
    struct U2_packed b;
};
struct U2_required_alignment var199;
struct U2_size {
    char a[sizeof(U2)+1];
    char b;
};
struct U2_size var200;

#pragma pack(2)
typedef union {
    char c;
    char x:1;
    long long:0;
    char e;
} V2;
V2 var201;
#pragma pack()
struct V2_alignment {
    char a;
    V2 b;
};
struct V2_alignment var202;
#pragma pack(1)
struct V2_packed {
    V2 a;
};
#pragma pack()
struct V2_required_alignment {
    char a;
    struct V2_packed b;
};
struct V2_required_alignment var203;
struct V2_size {
    char a[sizeof(V2)+1];
    char b;
};
struct V2_size var204;

typedef union {
    char c;
    char x:1;
    long long:0 __attribute__((aligned(16))) __attribute__((packed));
    char e;
} W2;
W2 var205;
struct W2_alignment {
    char a;
    W2 b;
};
struct W2_alignment var206;
#pragma pack(1)
struct W2_packed {
    W2 a;
};
#pragma pack()
struct W2_required_alignment {
    char a;
    struct W2_packed b;
};
struct W2_required_alignment var207;
struct W2_size {
    char a[sizeof(W2)+1];
    char b;
};
struct W2_size var208;

#pragma pack(1)
typedef union {
    char c;
    long long:0 __attribute__((aligned(16)));
    char e;
} W_2;
W_2 var209;
#pragma pack()
struct W_2_alignment {
    char a;
    W_2 b;
};
struct W_2_alignment var210;
#pragma pack(1)
struct W_2_packed {
    W_2 a;
};
#pragma pack()
struct W_2_required_alignment {
    char a;
    struct W_2_packed b;
};
struct W_2_required_alignment var211;
struct W_2_size {
    char a[sizeof(W_2)+1];
    char b;
};
struct W_2_size var212;

#pragma pack(2)
typedef union {
    char c;
    char x:1;
    long long:0 __attribute__((aligned(16))) __attribute__((packed));
    char e;
} X2;
X2 var213;
#pragma pack()
struct X2_alignment {
    char a;
    X2 b;
};
struct X2_alignment var214;
#pragma pack(1)
struct X2_packed {
    X2 a;
};
#pragma pack()
struct X2_required_alignment {
    char a;
    struct X2_packed b;
};
struct X2_required_alignment var215;
struct X2_size {
    char a[sizeof(X2)+1];
    char b;
};
struct X2_size var216;

typedef struct {
    char c:1;
    long long:0 __attribute__((packed));
    char d;
} Y;
Y var217;
struct Y_alignment {
    char a;
    Y b;
};
struct Y_alignment var218;
#pragma pack(1)
struct Y_packed {
    Y a;
};
#pragma pack()
struct Y_required_alignment {
    char a;
    struct Y_packed b;
};
struct Y_required_alignment var219;
struct Y_size {
    char a[sizeof(Y)+1];
    char b;
};
struct Y_size var220;

typedef union {
    char c:1;
    long long:0 __attribute__((packed));
    char d;
} Y2;
Y2 var221;
struct Y2_alignment {
    char a;
    Y2 b;
};
struct Y2_alignment var222;
#pragma pack(1)
struct Y2_packed {
    Y2 a;
};
#pragma pack()
struct Y2_required_alignment {
    char a;
    struct Y2_packed b;
};
struct Y2_required_alignment var223;
struct Y2_size {
    char a[sizeof(Y2)+1];
    char b;
};
struct Y2_size var224;

typedef struct {
    char c:1;
    long long:0 __attribute__((aligned(32)));
    char d:1;
} A3;
A3 var225;
struct A3_alignment {
    char a;
    A3 b;
};
struct A3_alignment var226;
#pragma pack(1)
struct A3_packed {
    A3 a;
};
#pragma pack()
struct A3_required_alignment {
    char a;
    struct A3_packed b;
};
struct A3_required_alignment var227;
struct A3_size {
    char a[sizeof(A3)+1];
    char b;
};
struct A3_size var228;

typedef char A4 __attribute__((aligned(32)));
A4 var229;
struct A4_alignment {
    char a;
    A4 b;
};
struct A4_alignment var230;
#pragma pack(1)
struct A4_packed {
    A4 a;
};
#pragma pack()
struct A4_required_alignment {
    char a;
    struct A4_packed b;
};
struct A4_required_alignment var231;
struct A4_size {
    char a[sizeof(A4)+1];
    char b;
};
struct A4_size var232;

typedef struct {
    char c:1;
    A4:0;
    char d:1;
} A5;
A5 var233;
struct A5_alignment {
    char a;
    A5 b;
};
struct A5_alignment var234;
#pragma pack(1)
struct A5_packed {
    A5 a;
};
#pragma pack()
struct A5_required_alignment {
    char a;
    struct A5_packed b;
};
struct A5_required_alignment var235;
struct A5_size {
    char a[sizeof(A5)+1];
    char b;
};
struct A5_size var236;

typedef struct {
    A4 a;
} A7;
A7 var237;
struct A7_alignment {
    char a;
    A7 b;
};
struct A7_alignment var238;
#pragma pack(1)
struct A7_packed {
    A7 a;
};
#pragma pack()
struct A7_required_alignment {
    char a;
    struct A7_packed b;
};
struct A7_required_alignment var239;
struct A7_size {
    char a[sizeof(A7)+1];
    char b;
};
struct A7_size var240;

typedef struct {
    char c;
    long i:31 __attribute__((packed));
    long j:2;
} A8;
A8 var241;
struct A8_alignment {
    char a;
    A8 b;
};
struct A8_alignment var242;
#pragma pack(1)
struct A8_packed {
    A8 a;
};
#pragma pack()
struct A8_required_alignment {
    char a;
    struct A8_packed b;
};
struct A8_required_alignment var243;
struct A8_size {
    char a[sizeof(A8)+1];
    char b;
};
struct A8_size var244;

typedef struct {
    char c;
    long i:31 __attribute__((packed));
    long j;
} A9;
A9 var245;
struct A9_alignment {
    char a;
    A9 b;
};
struct A9_alignment var246;
#pragma pack(1)
struct A9_packed {
    A9 a;
};
#pragma pack()
struct A9_required_alignment {
    char a;
    struct A9_packed b;
};
struct A9_required_alignment var247;
struct A9_size {
    char a[sizeof(A9)+1];
    char b;
};
struct A9_size var248;

typedef long A10 __attribute__((aligned(16)));
A10 var249;
struct A10_alignment {
    char a;
    A10 b;
};
struct A10_alignment var250;
#pragma pack(1)
struct A10_packed {
    A10 a;
};
#pragma pack()
struct A10_required_alignment {
    char a;
    struct A10_packed b;
};
struct A10_required_alignment var251;
struct A10_size {
    char a[sizeof(A10)+1];
    char b;
};
struct A10_size var252;

typedef struct {
    char c;
    long i:31 __attribute__((packed));
    A10 j:2;
} A11;
A11 var253;
struct A11_alignment {
    char a;
    A11 b;
};
struct A11_alignment var254;
#pragma pack(1)
struct A11_packed {
    A11 a;
};
#pragma pack()
struct A11_required_alignment {
    char a;
    struct A11_packed b;
};
struct A11_required_alignment var255;
struct A11_size {
    char a[sizeof(A11)+1];
    char b;
};
struct A11_size var256;

typedef struct {
    char c;
    long i:31 __attribute__((packed));
    A10 j;
} A12;
A12 var257;
struct A12_alignment {
    char a;
    A12 b;
};
struct A12_alignment var258;
#pragma pack(1)
struct A12_packed {
    A12 a;
};
#pragma pack()
struct A12_required_alignment {
    char a;
    struct A12_packed b;
};
struct A12_required_alignment var259;
struct A12_size {
    char a[sizeof(A12)+1];
    char b;
};
struct A12_size var260;

typedef struct {
    char c;
    long i:1;
    long j:1 __attribute__((aligned(16)));
    char d;
} A13;
A13 var261;
struct A13_alignment {
    char a;
    A13 b;
};
struct A13_alignment var262;
#pragma pack(1)
struct A13_packed {
    A13 a;
};
#pragma pack()
struct A13_required_alignment {
    char a;
    struct A13_packed b;
};
struct A13_required_alignment var263;
struct A13_size {
    char a[sizeof(A13)+1];
    char b;
};
struct A13_size var264;


// MAPPING|ONE|aarch64-generic-macos-none:Clang|aarch64-generic-ios-none:Clang|aarch64-generic-ios-macabi:Clang|aarch64-generic-tvos-none:Clang|powerpc64-ppc64-freebsd-gnu:Clang|riscv64-generic_rv64-other-none:Clang|sparc64-v9-netbsd-gnu:Clang|sparc64-v9-openbsd-gnu:Clang|sparc-v9-solaris-eabi:Clang|x86_64-x86_64-ios-macabi:Clang|x86_64-x86_64-ios-none:Clang|x86_64-x86_64-macos-none:Clang|x86_64-x86_64-tvos-none:Clang|x86_64-x86_64-fuchsia-gnu:Clang|x86_64-x86_64-linux-android:Clang|x86_64-x86_64-solaris-eabi:Clang|x86_64-x86_64-dragonfly-eabi:Clang|x86_64-x86_64-freebsd-gnu:Clang|x86_64-x86_64-haiku-gnu:Clang|x86_64-x86_64-hermit-eabi:Clang|x86_64-x86_64-netbsd-gnu:Clang|x86_64-x86_64-openbsd-gnu:Clang|END
// repr targets Aarch64AppleMacosx|Some("aarch64-generic-macos-none") Arm64AppleIos|Some("aarch64-generic-ios-none") Arm64AppleIosMacabi|Some("aarch64-generic-ios-macabi") Arm64AppleTvos|Some("aarch64-generic-tvos-none") Powerpc64UnknownFreebsd|Some("powerpc64-ppc64-freebsd-gnu") Riscv64|Some("riscv64-generic_rv64-other-none") Sparc64UnknownNetbsd|Some("sparc64-v9-netbsd-gnu") Sparc64UnknownOpenbsd|Some("sparc64-v9-openbsd-gnu") Sparcv9SunSolaris|Some("sparc-v9-solaris-eabi") X86_64AppleIosMacabi|Some("x86_64-x86_64-ios-macabi") X86_64AppleIos|Some("x86_64-x86_64-ios-none") X86_64AppleMacosx|Some("x86_64-x86_64-macos-none") X86_64AppleTvos|Some("x86_64-x86_64-tvos-none") X86_64Elf|None X86_64Fuchsia|Some("x86_64-x86_64-fuchsia-gnu") X86_64LinuxAndroid|Some("x86_64-x86_64-linux-android") X86_64PcSolaris|Some("x86_64-x86_64-solaris-eabi") X86_64RumprunNetbsd|None X86_64UnknownDragonfly|Some("x86_64-x86_64-dragonfly-eabi") X86_64UnknownFreebsd|Some("x86_64-x86_64-freebsd-gnu") X86_64UnknownHaiku|Some("x86_64-x86_64-haiku-gnu") X86_64UnknownHermit|Some("x86_64-x86_64-hermit-eabi") X86_64UnknownL4reUclibc|None X86_64UnknownNetbsd|Some("x86_64-x86_64-netbsd-gnu") X86_64UnknownOpenbsd|Some("x86_64-x86_64-openbsd-gnu") X86_64UnknownRedox|None 
#ifdef ONE
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
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A,d) == 0, "field A.d wrong bit offset");
#endif
_Static_assert(sizeof(A_) == 5, "record A_ wrong sizeof");
_Static_assert(_Alignof(A_) == 1, "record A_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A__alignment) == 6, "record A_ wrong sizeof");
_Static_assert(_Alignof(struct A__alignment) == 1, "record A_ wrong alignment");
_Static_assert(sizeof(struct A__packed) == 5, "record A_ wrong sizeof");
_Static_assert(_Alignof(struct A__packed) == 1, "record A_ wrong alignment");
_Static_assert(sizeof(struct A__required_alignment) == 6, "record A_ wrong sizeof");
_Static_assert(_Alignof(struct A__required_alignment) == 1, "record A_ wrong alignment");
_Static_assert(sizeof(struct A__size) == 7, "record A_ wrong sizeof");
_Static_assert(_Alignof(struct A__size) == 1, "record A_ wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_,d) == 32, "field A_.d wrong bit offset");
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
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B,d) == 0, "field B.d wrong bit offset");
#endif
_Static_assert(sizeof(B_) == 9, "record B_ wrong sizeof");
_Static_assert(_Alignof(B_) == 1, "record B_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B__alignment) == 10, "record B_ wrong sizeof");
_Static_assert(_Alignof(struct B__alignment) == 1, "record B_ wrong alignment");
_Static_assert(sizeof(struct B__packed) == 9, "record B_ wrong sizeof");
_Static_assert(_Alignof(struct B__packed) == 1, "record B_ wrong alignment");
_Static_assert(sizeof(struct B__required_alignment) == 10, "record B_ wrong sizeof");
_Static_assert(_Alignof(struct B__required_alignment) == 1, "record B_ wrong alignment");
_Static_assert(sizeof(struct B__size) == 11, "record B_ wrong sizeof");
_Static_assert(_Alignof(struct B__size) == 1, "record B_ wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B_,d) == 64, "field B_.d wrong bit offset");
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
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C,d) == 0, "field C.d wrong bit offset");
#endif
_Static_assert(sizeof(C_) == 9, "record C_ wrong sizeof");
_Static_assert(_Alignof(C_) == 1, "record C_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C__alignment) == 10, "record C_ wrong sizeof");
_Static_assert(_Alignof(struct C__alignment) == 1, "record C_ wrong alignment");
_Static_assert(sizeof(struct C__packed) == 9, "record C_ wrong sizeof");
_Static_assert(_Alignof(struct C__packed) == 1, "record C_ wrong alignment");
_Static_assert(sizeof(struct C__required_alignment) == 10, "record C_ wrong sizeof");
_Static_assert(_Alignof(struct C__required_alignment) == 1, "record C_ wrong alignment");
_Static_assert(sizeof(struct C__size) == 11, "record C_ wrong sizeof");
_Static_assert(_Alignof(struct C__size) == 1, "record C_ wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C_,d) == 64, "field C_.d wrong bit offset");
#endif
_Static_assert(sizeof(D) == 24, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 8, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 32, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 8, "record D wrong alignment");
_Static_assert(sizeof(struct D_packed) == 24, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 25, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_size) == 26, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_size) == 1, "record D wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D,d) == 64, "field D.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(D,e) == 128, "field D.e wrong bit offset");
#endif
_Static_assert(sizeof(F) == 32, "record F wrong sizeof");
_Static_assert(_Alignof(F) == 16, "record F wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 48, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_alignment) == 16, "record F wrong alignment");
_Static_assert(sizeof(struct F_packed) == 32, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_packed) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_required_alignment) == 33, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_size) == 34, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_size) == 1, "record F wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F,d) == 128, "field F.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(F,e) == 192, "field F.e wrong bit offset");
#endif
_Static_assert(sizeof(G) == 12, "record G wrong sizeof");
_Static_assert(_Alignof(G) == 2, "record G wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 14, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_alignment) == 2, "record G wrong alignment");
_Static_assert(sizeof(struct G_packed) == 12, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_packed) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_required_alignment) == 13, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_size) == 14, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_size) == 1, "record G wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(G,d) == 16, "field G.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(G,e) == 80, "field G.e wrong bit offset");
#endif
_Static_assert(sizeof(H) == 12, "record H wrong sizeof");
_Static_assert(_Alignof(H) == 2, "record H wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 14, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_alignment) == 2, "record H wrong alignment");
_Static_assert(sizeof(struct H_packed) == 12, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_packed) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_required_alignment) == 13, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_size) == 14, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_size) == 1, "record H wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(H,d) == 16, "field H.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(H,e) == 80, "field H.e wrong bit offset");
#endif
_Static_assert(sizeof(I) == 10, "record I wrong sizeof");
_Static_assert(_Alignof(I) == 1, "record I wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I_alignment) == 11, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_alignment) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_packed) == 10, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_packed) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_required_alignment) == 11, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_required_alignment) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_size) == 12, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_size) == 1, "record I wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(I,d) == 8, "field I.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(I,e) == 72, "field I.e wrong bit offset");
#endif
_Static_assert(sizeof(J) == 12, "record J wrong sizeof");
_Static_assert(_Alignof(J) == 2, "record J wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J_alignment) == 14, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_alignment) == 2, "record J wrong alignment");
_Static_assert(sizeof(struct J_packed) == 12, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_packed) == 1, "record J wrong alignment");
_Static_assert(sizeof(struct J_required_alignment) == 13, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_required_alignment) == 1, "record J wrong alignment");
_Static_assert(sizeof(struct J_size) == 14, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_size) == 1, "record J wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(J,d) == 16, "field J.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(J,e) == 80, "field J.e wrong bit offset");
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
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(K,d) == 8, "field K.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(K,e) == 16, "field K.e wrong bit offset");
#endif
_Static_assert(sizeof(L) == 32, "record L wrong sizeof");
_Static_assert(_Alignof(L) == 16, "record L wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct L_alignment) == 48, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_alignment) == 16, "record L wrong alignment");
_Static_assert(sizeof(struct L_packed) == 32, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_packed) == 1, "record L wrong alignment");
_Static_assert(sizeof(struct L_required_alignment) == 33, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_required_alignment) == 1, "record L wrong alignment");
_Static_assert(sizeof(struct L_size) == 34, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_size) == 1, "record L wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(L,d) == 128, "field L.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(L,e) == 136, "field L.e wrong bit offset");
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
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(M,d) == 16, "field M.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(M,e) == 24, "field M.e wrong bit offset");
#endif
_Static_assert(sizeof(N) == 4, "record N wrong sizeof");
_Static_assert(_Alignof(N) == 2, "record N wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct N_alignment) == 6, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_alignment) == 2, "record N wrong alignment");
_Static_assert(sizeof(struct N_packed) == 4, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_packed) == 1, "record N wrong alignment");
_Static_assert(sizeof(struct N_required_alignment) == 5, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_required_alignment) == 1, "record N wrong alignment");
_Static_assert(sizeof(struct N_size) == 6, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_size) == 1, "record N wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(N,d) == 8, "field N.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(N,e) == 16, "field N.e wrong bit offset");
#endif
_Static_assert(sizeof(O) == 3, "record O wrong sizeof");
_Static_assert(_Alignof(O) == 1, "record O wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct O_alignment) == 4, "record O wrong sizeof");
_Static_assert(_Alignof(struct O_alignment) == 1, "record O wrong alignment");
_Static_assert(sizeof(struct O_packed) == 3, "record O wrong sizeof");
_Static_assert(_Alignof(struct O_packed) == 1, "record O wrong alignment");
_Static_assert(sizeof(struct O_required_alignment) == 4, "record O wrong sizeof");
_Static_assert(_Alignof(struct O_required_alignment) == 1, "record O wrong alignment");
_Static_assert(sizeof(struct O_size) == 5, "record O wrong sizeof");
_Static_assert(_Alignof(struct O_size) == 1, "record O wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(O,d) == 8, "field O.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(O,e) == 16, "field O.e wrong bit offset");
#endif
_Static_assert(sizeof(P) == 4, "record P wrong sizeof");
_Static_assert(_Alignof(P) == 2, "record P wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct P_alignment) == 6, "record P wrong sizeof");
_Static_assert(_Alignof(struct P_alignment) == 2, "record P wrong alignment");
_Static_assert(sizeof(struct P_packed) == 4, "record P wrong sizeof");
_Static_assert(_Alignof(struct P_packed) == 1, "record P wrong alignment");
_Static_assert(sizeof(struct P_required_alignment) == 5, "record P wrong sizeof");
_Static_assert(_Alignof(struct P_required_alignment) == 1, "record P wrong alignment");
_Static_assert(sizeof(struct P_size) == 6, "record P wrong sizeof");
_Static_assert(_Alignof(struct P_size) == 1, "record P wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(P,d) == 8, "field P.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(P,e) == 16, "field P.e wrong bit offset");
#endif
_Static_assert(sizeof(Q) == 8, "record Q wrong sizeof");
_Static_assert(_Alignof(Q) == 8, "record Q wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Q_alignment) == 16, "record Q wrong sizeof");
_Static_assert(_Alignof(struct Q_alignment) == 8, "record Q wrong alignment");
_Static_assert(sizeof(struct Q_packed) == 8, "record Q wrong sizeof");
_Static_assert(_Alignof(struct Q_packed) == 1, "record Q wrong alignment");
_Static_assert(sizeof(struct Q_required_alignment) == 9, "record Q wrong sizeof");
_Static_assert(_Alignof(struct Q_required_alignment) == 1, "record Q wrong alignment");
_Static_assert(sizeof(struct Q_size) == 10, "record Q wrong sizeof");
_Static_assert(_Alignof(struct Q_size) == 1, "record Q wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(Q,x) == 8, "field Q.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(Q,d) == 9, "field Q.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(Q,e) == 16, "field Q.e wrong bit offset");
#endif
_Static_assert(sizeof(R) == 17, "record R wrong sizeof");
_Static_assert(_Alignof(R) == 1, "record R wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct R_alignment) == 18, "record R wrong sizeof");
_Static_assert(_Alignof(struct R_alignment) == 1, "record R wrong alignment");
_Static_assert(sizeof(struct R_packed) == 17, "record R wrong sizeof");
_Static_assert(_Alignof(struct R_packed) == 1, "record R wrong alignment");
_Static_assert(sizeof(struct R_required_alignment) == 18, "record R wrong sizeof");
_Static_assert(_Alignof(struct R_required_alignment) == 1, "record R wrong alignment");
_Static_assert(sizeof(struct R_size) == 19, "record R wrong sizeof");
_Static_assert(_Alignof(struct R_size) == 1, "record R wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(R,x) == 8, "field R.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(R,e) == 128, "field R.e wrong bit offset");
#endif
_Static_assert(sizeof(S) == 9, "record S wrong sizeof");
_Static_assert(_Alignof(S) == 1, "record S wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct S_alignment) == 10, "record S wrong sizeof");
_Static_assert(_Alignof(struct S_alignment) == 1, "record S wrong alignment");
_Static_assert(sizeof(struct S_packed) == 9, "record S wrong sizeof");
_Static_assert(_Alignof(struct S_packed) == 1, "record S wrong alignment");
_Static_assert(sizeof(struct S_required_alignment) == 10, "record S wrong sizeof");
_Static_assert(_Alignof(struct S_required_alignment) == 1, "record S wrong alignment");
_Static_assert(sizeof(struct S_size) == 11, "record S wrong sizeof");
_Static_assert(_Alignof(struct S_size) == 1, "record S wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(S,x) == 8, "field S.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(S,e) == 64, "field S.e wrong bit offset");
#endif
_Static_assert(sizeof(T) == 9, "record T wrong sizeof");
_Static_assert(_Alignof(T) == 1, "record T wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct T_alignment) == 10, "record T wrong sizeof");
_Static_assert(_Alignof(struct T_alignment) == 1, "record T wrong alignment");
_Static_assert(sizeof(struct T_packed) == 9, "record T wrong sizeof");
_Static_assert(_Alignof(struct T_packed) == 1, "record T wrong alignment");
_Static_assert(sizeof(struct T_required_alignment) == 10, "record T wrong sizeof");
_Static_assert(_Alignof(struct T_required_alignment) == 1, "record T wrong alignment");
_Static_assert(sizeof(struct T_size) == 11, "record T wrong sizeof");
_Static_assert(_Alignof(struct T_size) == 1, "record T wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(T,x) == 8, "field T.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(T,e) == 64, "field T.e wrong bit offset");
#endif
_Static_assert(sizeof(U) == 9, "record U wrong sizeof");
_Static_assert(_Alignof(U) == 1, "record U wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct U_alignment) == 10, "record U wrong sizeof");
_Static_assert(_Alignof(struct U_alignment) == 1, "record U wrong alignment");
_Static_assert(sizeof(struct U_packed) == 9, "record U wrong sizeof");
_Static_assert(_Alignof(struct U_packed) == 1, "record U wrong alignment");
_Static_assert(sizeof(struct U_required_alignment) == 10, "record U wrong sizeof");
_Static_assert(_Alignof(struct U_required_alignment) == 1, "record U wrong alignment");
_Static_assert(sizeof(struct U_size) == 11, "record U wrong sizeof");
_Static_assert(_Alignof(struct U_size) == 1, "record U wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(U,x) == 8, "field U.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(U,e) == 64, "field U.e wrong bit offset");
#endif
_Static_assert(sizeof(V) == 9, "record V wrong sizeof");
_Static_assert(_Alignof(V) == 1, "record V wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct V_alignment) == 10, "record V wrong sizeof");
_Static_assert(_Alignof(struct V_alignment) == 1, "record V wrong alignment");
_Static_assert(sizeof(struct V_packed) == 9, "record V wrong sizeof");
_Static_assert(_Alignof(struct V_packed) == 1, "record V wrong alignment");
_Static_assert(sizeof(struct V_required_alignment) == 10, "record V wrong sizeof");
_Static_assert(_Alignof(struct V_required_alignment) == 1, "record V wrong alignment");
_Static_assert(sizeof(struct V_size) == 11, "record V wrong sizeof");
_Static_assert(_Alignof(struct V_size) == 1, "record V wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(V,x) == 8, "field V.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(V,e) == 64, "field V.e wrong bit offset");
#endif
_Static_assert(sizeof(W) == 17, "record W wrong sizeof");
_Static_assert(_Alignof(W) == 1, "record W wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct W_alignment) == 18, "record W wrong sizeof");
_Static_assert(_Alignof(struct W_alignment) == 1, "record W wrong alignment");
_Static_assert(sizeof(struct W_packed) == 17, "record W wrong sizeof");
_Static_assert(_Alignof(struct W_packed) == 1, "record W wrong alignment");
_Static_assert(sizeof(struct W_required_alignment) == 18, "record W wrong sizeof");
_Static_assert(_Alignof(struct W_required_alignment) == 1, "record W wrong alignment");
_Static_assert(sizeof(struct W_size) == 19, "record W wrong sizeof");
_Static_assert(_Alignof(struct W_size) == 1, "record W wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(W,x) == 8, "field W.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(W,e) == 128, "field W.e wrong bit offset");
#endif
_Static_assert(sizeof(W_) == 17, "record W_ wrong sizeof");
_Static_assert(_Alignof(W_) == 1, "record W_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct W__alignment) == 18, "record W_ wrong sizeof");
_Static_assert(_Alignof(struct W__alignment) == 1, "record W_ wrong alignment");
_Static_assert(sizeof(struct W__packed) == 17, "record W_ wrong sizeof");
_Static_assert(_Alignof(struct W__packed) == 1, "record W_ wrong alignment");
_Static_assert(sizeof(struct W__required_alignment) == 18, "record W_ wrong sizeof");
_Static_assert(_Alignof(struct W__required_alignment) == 1, "record W_ wrong alignment");
_Static_assert(sizeof(struct W__size) == 19, "record W_ wrong sizeof");
_Static_assert(_Alignof(struct W__size) == 1, "record W_ wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(W_,e) == 128, "field W_.e wrong bit offset");
#endif
_Static_assert(sizeof(X) == 17, "record X wrong sizeof");
_Static_assert(_Alignof(X) == 1, "record X wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct X_alignment) == 18, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_alignment) == 1, "record X wrong alignment");
_Static_assert(sizeof(struct X_packed) == 17, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_packed) == 1, "record X wrong alignment");
_Static_assert(sizeof(struct X_required_alignment) == 18, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_required_alignment) == 1, "record X wrong alignment");
_Static_assert(sizeof(struct X_size) == 19, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_size) == 1, "record X wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(X,x) == 8, "field X.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(X,e) == 128, "field X.e wrong bit offset");
#endif
_Static_assert(sizeof(A2) == 1, "record A2 wrong sizeof");
_Static_assert(_Alignof(A2) == 1, "record A2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A2_alignment) == 2, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_alignment) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_packed) == 1, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_packed) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_required_alignment) == 2, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_required_alignment) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_size) == 3, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_size) == 1, "record A2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A2,d) == 0, "field A2.d wrong bit offset");
#endif
_Static_assert(sizeof(A_2) == 1, "record A_2 wrong sizeof");
_Static_assert(_Alignof(A_2) == 1, "record A_2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_2_alignment) == 2, "record A_2 wrong sizeof");
_Static_assert(_Alignof(struct A_2_alignment) == 1, "record A_2 wrong alignment");
_Static_assert(sizeof(struct A_2_packed) == 1, "record A_2 wrong sizeof");
_Static_assert(_Alignof(struct A_2_packed) == 1, "record A_2 wrong alignment");
_Static_assert(sizeof(struct A_2_required_alignment) == 2, "record A_2 wrong sizeof");
_Static_assert(_Alignof(struct A_2_required_alignment) == 1, "record A_2 wrong alignment");
_Static_assert(sizeof(struct A_2_size) == 3, "record A_2 wrong sizeof");
_Static_assert(_Alignof(struct A_2_size) == 1, "record A_2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_2,d) == 0, "field A_2.d wrong bit offset");
#endif
_Static_assert(sizeof(B2) == 1, "record B2 wrong sizeof");
_Static_assert(_Alignof(B2) == 1, "record B2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B2_alignment) == 2, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_alignment) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_packed) == 1, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_packed) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_required_alignment) == 2, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_required_alignment) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_size) == 3, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_size) == 1, "record B2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B2,d) == 0, "field B2.d wrong bit offset");
#endif
_Static_assert(sizeof(B_2) == 1, "record B_2 wrong sizeof");
_Static_assert(_Alignof(B_2) == 1, "record B_2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_2_alignment) == 2, "record B_2 wrong sizeof");
_Static_assert(_Alignof(struct B_2_alignment) == 1, "record B_2 wrong alignment");
_Static_assert(sizeof(struct B_2_packed) == 1, "record B_2 wrong sizeof");
_Static_assert(_Alignof(struct B_2_packed) == 1, "record B_2 wrong alignment");
_Static_assert(sizeof(struct B_2_required_alignment) == 2, "record B_2 wrong sizeof");
_Static_assert(_Alignof(struct B_2_required_alignment) == 1, "record B_2 wrong alignment");
_Static_assert(sizeof(struct B_2_size) == 3, "record B_2 wrong sizeof");
_Static_assert(_Alignof(struct B_2_size) == 1, "record B_2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B_2,d) == 0, "field B_2.d wrong bit offset");
#endif
_Static_assert(sizeof(C2) == 1, "record C2 wrong sizeof");
_Static_assert(_Alignof(C2) == 1, "record C2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C2_alignment) == 2, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_alignment) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_packed) == 1, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_packed) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_required_alignment) == 2, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_required_alignment) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_size) == 3, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_size) == 1, "record C2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C2,d) == 0, "field C2.d wrong bit offset");
#endif
_Static_assert(sizeof(C22) == 1, "record C22 wrong sizeof");
_Static_assert(_Alignof(C22) == 1, "record C22 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C22_alignment) == 2, "record C22 wrong sizeof");
_Static_assert(_Alignof(struct C22_alignment) == 1, "record C22 wrong alignment");
_Static_assert(sizeof(struct C22_packed) == 1, "record C22 wrong sizeof");
_Static_assert(_Alignof(struct C22_packed) == 1, "record C22 wrong alignment");
_Static_assert(sizeof(struct C22_required_alignment) == 2, "record C22 wrong sizeof");
_Static_assert(_Alignof(struct C22_required_alignment) == 1, "record C22 wrong alignment");
_Static_assert(sizeof(struct C22_size) == 3, "record C22 wrong sizeof");
_Static_assert(_Alignof(struct C22_size) == 1, "record C22 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C22,d) == 0, "field C22.d wrong bit offset");
#endif
_Static_assert(sizeof(D2) == 8, "record D2 wrong sizeof");
_Static_assert(_Alignof(D2) == 8, "record D2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D2_alignment) == 16, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_alignment) == 8, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_packed) == 8, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_packed) == 1, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_required_alignment) == 9, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_required_alignment) == 1, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_size) == 10, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_size) == 1, "record D2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D2,d) == 0, "field D2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(D2,e) == 0, "field D2.e wrong bit offset");
#endif
_Static_assert(sizeof(F2) == 16, "record F2 wrong sizeof");
_Static_assert(_Alignof(F2) == 16, "record F2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F2_alignment) == 32, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_alignment) == 16, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_packed) == 16, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_packed) == 1, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_required_alignment) == 17, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_required_alignment) == 1, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_size) == 18, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_size) == 1, "record F2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F2,d) == 0, "field F2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(F2,e) == 0, "field F2.e wrong bit offset");
#endif
_Static_assert(sizeof(G2) == 8, "record G2 wrong sizeof");
_Static_assert(_Alignof(G2) == 2, "record G2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G2_alignment) == 10, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_alignment) == 2, "record G2 wrong alignment");
_Static_assert(sizeof(struct G2_packed) == 8, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_packed) == 1, "record G2 wrong alignment");
_Static_assert(sizeof(struct G2_required_alignment) == 9, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_required_alignment) == 1, "record G2 wrong alignment");
_Static_assert(sizeof(struct G2_size) == 10, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_size) == 1, "record G2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(G2,d) == 0, "field G2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(G2,e) == 0, "field G2.e wrong bit offset");
#endif
_Static_assert(sizeof(H2) == 8, "record H2 wrong sizeof");
_Static_assert(_Alignof(H2) == 2, "record H2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H2_alignment) == 10, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_alignment) == 2, "record H2 wrong alignment");
_Static_assert(sizeof(struct H2_packed) == 8, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_packed) == 1, "record H2 wrong alignment");
_Static_assert(sizeof(struct H2_required_alignment) == 9, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_required_alignment) == 1, "record H2 wrong alignment");
_Static_assert(sizeof(struct H2_size) == 10, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_size) == 1, "record H2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(H2,d) == 0, "field H2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(H2,e) == 0, "field H2.e wrong bit offset");
#endif
_Static_assert(sizeof(I2) == 8, "record I2 wrong sizeof");
_Static_assert(_Alignof(I2) == 1, "record I2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I2_alignment) == 9, "record I2 wrong sizeof");
_Static_assert(_Alignof(struct I2_alignment) == 1, "record I2 wrong alignment");
_Static_assert(sizeof(struct I2_packed) == 8, "record I2 wrong sizeof");
_Static_assert(_Alignof(struct I2_packed) == 1, "record I2 wrong alignment");
_Static_assert(sizeof(struct I2_required_alignment) == 9, "record I2 wrong sizeof");
_Static_assert(_Alignof(struct I2_required_alignment) == 1, "record I2 wrong alignment");
_Static_assert(sizeof(struct I2_size) == 10, "record I2 wrong sizeof");
_Static_assert(_Alignof(struct I2_size) == 1, "record I2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(I2,d) == 0, "field I2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(I2,e) == 0, "field I2.e wrong bit offset");
#endif
_Static_assert(sizeof(J2) == 8, "record J2 wrong sizeof");
_Static_assert(_Alignof(J2) == 2, "record J2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J2_alignment) == 10, "record J2 wrong sizeof");
_Static_assert(_Alignof(struct J2_alignment) == 2, "record J2 wrong alignment");
_Static_assert(sizeof(struct J2_packed) == 8, "record J2 wrong sizeof");
_Static_assert(_Alignof(struct J2_packed) == 1, "record J2 wrong alignment");
_Static_assert(sizeof(struct J2_required_alignment) == 9, "record J2 wrong sizeof");
_Static_assert(_Alignof(struct J2_required_alignment) == 1, "record J2 wrong alignment");
_Static_assert(sizeof(struct J2_size) == 10, "record J2 wrong sizeof");
_Static_assert(_Alignof(struct J2_size) == 1, "record J2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(J2,d) == 0, "field J2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(J2,e) == 0, "field J2.e wrong bit offset");
#endif
_Static_assert(sizeof(K2) == 8, "record K2 wrong sizeof");
_Static_assert(_Alignof(K2) == 8, "record K2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct K2_alignment) == 16, "record K2 wrong sizeof");
_Static_assert(_Alignof(struct K2_alignment) == 8, "record K2 wrong alignment");
_Static_assert(sizeof(struct K2_packed) == 8, "record K2 wrong sizeof");
_Static_assert(_Alignof(struct K2_packed) == 1, "record K2 wrong alignment");
_Static_assert(sizeof(struct K2_required_alignment) == 9, "record K2 wrong sizeof");
_Static_assert(_Alignof(struct K2_required_alignment) == 1, "record K2 wrong alignment");
_Static_assert(sizeof(struct K2_size) == 10, "record K2 wrong sizeof");
_Static_assert(_Alignof(struct K2_size) == 1, "record K2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(K2,d) == 0, "field K2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(K2,e) == 0, "field K2.e wrong bit offset");
#endif
_Static_assert(sizeof(L2) == 16, "record L2 wrong sizeof");
_Static_assert(_Alignof(L2) == 16, "record L2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct L2_alignment) == 32, "record L2 wrong sizeof");
_Static_assert(_Alignof(struct L2_alignment) == 16, "record L2 wrong alignment");
_Static_assert(sizeof(struct L2_packed) == 16, "record L2 wrong sizeof");
_Static_assert(_Alignof(struct L2_packed) == 1, "record L2 wrong alignment");
_Static_assert(sizeof(struct L2_required_alignment) == 17, "record L2 wrong sizeof");
_Static_assert(_Alignof(struct L2_required_alignment) == 1, "record L2 wrong alignment");
_Static_assert(sizeof(struct L2_size) == 18, "record L2 wrong sizeof");
_Static_assert(_Alignof(struct L2_size) == 1, "record L2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(L2,d) == 0, "field L2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(L2,e) == 0, "field L2.e wrong bit offset");
#endif
_Static_assert(sizeof(M2) == 2, "record M2 wrong sizeof");
_Static_assert(_Alignof(M2) == 2, "record M2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct M2_alignment) == 4, "record M2 wrong sizeof");
_Static_assert(_Alignof(struct M2_alignment) == 2, "record M2 wrong alignment");
_Static_assert(sizeof(struct M2_packed) == 2, "record M2 wrong sizeof");
_Static_assert(_Alignof(struct M2_packed) == 1, "record M2 wrong alignment");
_Static_assert(sizeof(struct M2_required_alignment) == 3, "record M2 wrong sizeof");
_Static_assert(_Alignof(struct M2_required_alignment) == 1, "record M2 wrong alignment");
_Static_assert(sizeof(struct M2_size) == 4, "record M2 wrong sizeof");
_Static_assert(_Alignof(struct M2_size) == 1, "record M2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(M2,d) == 0, "field M2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(M2,e) == 0, "field M2.e wrong bit offset");
#endif
_Static_assert(sizeof(N2) == 2, "record N2 wrong sizeof");
_Static_assert(_Alignof(N2) == 2, "record N2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct N2_alignment) == 4, "record N2 wrong sizeof");
_Static_assert(_Alignof(struct N2_alignment) == 2, "record N2 wrong alignment");
_Static_assert(sizeof(struct N2_packed) == 2, "record N2 wrong sizeof");
_Static_assert(_Alignof(struct N2_packed) == 1, "record N2 wrong alignment");
_Static_assert(sizeof(struct N2_required_alignment) == 3, "record N2 wrong sizeof");
_Static_assert(_Alignof(struct N2_required_alignment) == 1, "record N2 wrong alignment");
_Static_assert(sizeof(struct N2_size) == 4, "record N2 wrong sizeof");
_Static_assert(_Alignof(struct N2_size) == 1, "record N2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(N2,d) == 0, "field N2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(N2,e) == 0, "field N2.e wrong bit offset");
#endif
_Static_assert(sizeof(O2) == 1, "record O2 wrong sizeof");
_Static_assert(_Alignof(O2) == 1, "record O2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct O2_alignment) == 2, "record O2 wrong sizeof");
_Static_assert(_Alignof(struct O2_alignment) == 1, "record O2 wrong alignment");
_Static_assert(sizeof(struct O2_packed) == 1, "record O2 wrong sizeof");
_Static_assert(_Alignof(struct O2_packed) == 1, "record O2 wrong alignment");
_Static_assert(sizeof(struct O2_required_alignment) == 2, "record O2 wrong sizeof");
_Static_assert(_Alignof(struct O2_required_alignment) == 1, "record O2 wrong alignment");
_Static_assert(sizeof(struct O2_size) == 3, "record O2 wrong sizeof");
_Static_assert(_Alignof(struct O2_size) == 1, "record O2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(O2,d) == 0, "field O2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(O2,e) == 0, "field O2.e wrong bit offset");
#endif
_Static_assert(sizeof(P2) == 2, "record P2 wrong sizeof");
_Static_assert(_Alignof(P2) == 2, "record P2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct P2_alignment) == 4, "record P2 wrong sizeof");
_Static_assert(_Alignof(struct P2_alignment) == 2, "record P2 wrong alignment");
_Static_assert(sizeof(struct P2_packed) == 2, "record P2 wrong sizeof");
_Static_assert(_Alignof(struct P2_packed) == 1, "record P2 wrong alignment");
_Static_assert(sizeof(struct P2_required_alignment) == 3, "record P2 wrong sizeof");
_Static_assert(_Alignof(struct P2_required_alignment) == 1, "record P2 wrong alignment");
_Static_assert(sizeof(struct P2_size) == 4, "record P2 wrong sizeof");
_Static_assert(_Alignof(struct P2_size) == 1, "record P2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(P2,d) == 0, "field P2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(P2,e) == 0, "field P2.e wrong bit offset");
#endif
_Static_assert(sizeof(Q2) == 8, "record Q2 wrong sizeof");
_Static_assert(_Alignof(Q2) == 8, "record Q2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Q2_alignment) == 16, "record Q2 wrong sizeof");
_Static_assert(_Alignof(struct Q2_alignment) == 8, "record Q2 wrong alignment");
_Static_assert(sizeof(struct Q2_packed) == 8, "record Q2 wrong sizeof");
_Static_assert(_Alignof(struct Q2_packed) == 1, "record Q2 wrong alignment");
_Static_assert(sizeof(struct Q2_required_alignment) == 9, "record Q2 wrong sizeof");
_Static_assert(_Alignof(struct Q2_required_alignment) == 1, "record Q2 wrong alignment");
_Static_assert(sizeof(struct Q2_size) == 10, "record Q2 wrong sizeof");
_Static_assert(_Alignof(struct Q2_size) == 1, "record Q2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(Q2,x) == 0, "field Q2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(Q2,d) == 0, "field Q2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(Q2,e) == 0, "field Q2.e wrong bit offset");
#endif
_Static_assert(sizeof(R2) == 1, "record R2 wrong sizeof");
_Static_assert(_Alignof(R2) == 1, "record R2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct R2_alignment) == 2, "record R2 wrong sizeof");
_Static_assert(_Alignof(struct R2_alignment) == 1, "record R2 wrong alignment");
_Static_assert(sizeof(struct R2_packed) == 1, "record R2 wrong sizeof");
_Static_assert(_Alignof(struct R2_packed) == 1, "record R2 wrong alignment");
_Static_assert(sizeof(struct R2_required_alignment) == 2, "record R2 wrong sizeof");
_Static_assert(_Alignof(struct R2_required_alignment) == 1, "record R2 wrong alignment");
_Static_assert(sizeof(struct R2_size) == 3, "record R2 wrong sizeof");
_Static_assert(_Alignof(struct R2_size) == 1, "record R2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(R2,x) == 0, "field R2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(R2,e) == 0, "field R2.e wrong bit offset");
#endif
_Static_assert(sizeof(S2) == 1, "record S2 wrong sizeof");
_Static_assert(_Alignof(S2) == 1, "record S2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct S2_alignment) == 2, "record S2 wrong sizeof");
_Static_assert(_Alignof(struct S2_alignment) == 1, "record S2 wrong alignment");
_Static_assert(sizeof(struct S2_packed) == 1, "record S2 wrong sizeof");
_Static_assert(_Alignof(struct S2_packed) == 1, "record S2 wrong alignment");
_Static_assert(sizeof(struct S2_required_alignment) == 2, "record S2 wrong sizeof");
_Static_assert(_Alignof(struct S2_required_alignment) == 1, "record S2 wrong alignment");
_Static_assert(sizeof(struct S2_size) == 3, "record S2 wrong sizeof");
_Static_assert(_Alignof(struct S2_size) == 1, "record S2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(S2,x) == 0, "field S2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(S2,e) == 0, "field S2.e wrong bit offset");
#endif
_Static_assert(sizeof(T2) == 1, "record T2 wrong sizeof");
_Static_assert(_Alignof(T2) == 1, "record T2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct T2_alignment) == 2, "record T2 wrong sizeof");
_Static_assert(_Alignof(struct T2_alignment) == 1, "record T2 wrong alignment");
_Static_assert(sizeof(struct T2_packed) == 1, "record T2 wrong sizeof");
_Static_assert(_Alignof(struct T2_packed) == 1, "record T2 wrong alignment");
_Static_assert(sizeof(struct T2_required_alignment) == 2, "record T2 wrong sizeof");
_Static_assert(_Alignof(struct T2_required_alignment) == 1, "record T2 wrong alignment");
_Static_assert(sizeof(struct T2_size) == 3, "record T2 wrong sizeof");
_Static_assert(_Alignof(struct T2_size) == 1, "record T2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(T2,x) == 0, "field T2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(T2,e) == 0, "field T2.e wrong bit offset");
#endif
_Static_assert(sizeof(U2) == 1, "record U2 wrong sizeof");
_Static_assert(_Alignof(U2) == 1, "record U2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct U2_alignment) == 2, "record U2 wrong sizeof");
_Static_assert(_Alignof(struct U2_alignment) == 1, "record U2 wrong alignment");
_Static_assert(sizeof(struct U2_packed) == 1, "record U2 wrong sizeof");
_Static_assert(_Alignof(struct U2_packed) == 1, "record U2 wrong alignment");
_Static_assert(sizeof(struct U2_required_alignment) == 2, "record U2 wrong sizeof");
_Static_assert(_Alignof(struct U2_required_alignment) == 1, "record U2 wrong alignment");
_Static_assert(sizeof(struct U2_size) == 3, "record U2 wrong sizeof");
_Static_assert(_Alignof(struct U2_size) == 1, "record U2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(U2,x) == 0, "field U2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(U2,e) == 0, "field U2.e wrong bit offset");
#endif
_Static_assert(sizeof(V2) == 1, "record V2 wrong sizeof");
_Static_assert(_Alignof(V2) == 1, "record V2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct V2_alignment) == 2, "record V2 wrong sizeof");
_Static_assert(_Alignof(struct V2_alignment) == 1, "record V2 wrong alignment");
_Static_assert(sizeof(struct V2_packed) == 1, "record V2 wrong sizeof");
_Static_assert(_Alignof(struct V2_packed) == 1, "record V2 wrong alignment");
_Static_assert(sizeof(struct V2_required_alignment) == 2, "record V2 wrong sizeof");
_Static_assert(_Alignof(struct V2_required_alignment) == 1, "record V2 wrong alignment");
_Static_assert(sizeof(struct V2_size) == 3, "record V2 wrong sizeof");
_Static_assert(_Alignof(struct V2_size) == 1, "record V2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(V2,x) == 0, "field V2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(V2,e) == 0, "field V2.e wrong bit offset");
#endif
_Static_assert(sizeof(W2) == 1, "record W2 wrong sizeof");
_Static_assert(_Alignof(W2) == 1, "record W2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct W2_alignment) == 2, "record W2 wrong sizeof");
_Static_assert(_Alignof(struct W2_alignment) == 1, "record W2 wrong alignment");
_Static_assert(sizeof(struct W2_packed) == 1, "record W2 wrong sizeof");
_Static_assert(_Alignof(struct W2_packed) == 1, "record W2 wrong alignment");
_Static_assert(sizeof(struct W2_required_alignment) == 2, "record W2 wrong sizeof");
_Static_assert(_Alignof(struct W2_required_alignment) == 1, "record W2 wrong alignment");
_Static_assert(sizeof(struct W2_size) == 3, "record W2 wrong sizeof");
_Static_assert(_Alignof(struct W2_size) == 1, "record W2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(W2,x) == 0, "field W2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(W2,e) == 0, "field W2.e wrong bit offset");
#endif
_Static_assert(sizeof(W_2) == 1, "record W_2 wrong sizeof");
_Static_assert(_Alignof(W_2) == 1, "record W_2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct W_2_alignment) == 2, "record W_2 wrong sizeof");
_Static_assert(_Alignof(struct W_2_alignment) == 1, "record W_2 wrong alignment");
_Static_assert(sizeof(struct W_2_packed) == 1, "record W_2 wrong sizeof");
_Static_assert(_Alignof(struct W_2_packed) == 1, "record W_2 wrong alignment");
_Static_assert(sizeof(struct W_2_required_alignment) == 2, "record W_2 wrong sizeof");
_Static_assert(_Alignof(struct W_2_required_alignment) == 1, "record W_2 wrong alignment");
_Static_assert(sizeof(struct W_2_size) == 3, "record W_2 wrong sizeof");
_Static_assert(_Alignof(struct W_2_size) == 1, "record W_2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(W_2,e) == 0, "field W_2.e wrong bit offset");
#endif
_Static_assert(sizeof(X2) == 1, "record X2 wrong sizeof");
_Static_assert(_Alignof(X2) == 1, "record X2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct X2_alignment) == 2, "record X2 wrong sizeof");
_Static_assert(_Alignof(struct X2_alignment) == 1, "record X2 wrong alignment");
_Static_assert(sizeof(struct X2_packed) == 1, "record X2 wrong sizeof");
_Static_assert(_Alignof(struct X2_packed) == 1, "record X2 wrong alignment");
_Static_assert(sizeof(struct X2_required_alignment) == 2, "record X2 wrong sizeof");
_Static_assert(_Alignof(struct X2_required_alignment) == 1, "record X2 wrong alignment");
_Static_assert(sizeof(struct X2_size) == 3, "record X2 wrong sizeof");
_Static_assert(_Alignof(struct X2_size) == 1, "record X2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(X2,x) == 0, "field X2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(X2,e) == 0, "field X2.e wrong bit offset");
#endif
_Static_assert(sizeof(Y) == 9, "record Y wrong sizeof");
_Static_assert(_Alignof(Y) == 1, "record Y wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Y_alignment) == 10, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_alignment) == 1, "record Y wrong alignment");
_Static_assert(sizeof(struct Y_packed) == 9, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_packed) == 1, "record Y wrong alignment");
_Static_assert(sizeof(struct Y_required_alignment) == 10, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_required_alignment) == 1, "record Y wrong alignment");
_Static_assert(sizeof(struct Y_size) == 11, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_size) == 1, "record Y wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(Y,d) == 64, "field Y.d wrong bit offset");
#endif
_Static_assert(sizeof(Y2) == 1, "record Y2 wrong sizeof");
_Static_assert(_Alignof(Y2) == 1, "record Y2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Y2_alignment) == 2, "record Y2 wrong sizeof");
_Static_assert(_Alignof(struct Y2_alignment) == 1, "record Y2 wrong alignment");
_Static_assert(sizeof(struct Y2_packed) == 1, "record Y2 wrong sizeof");
_Static_assert(_Alignof(struct Y2_packed) == 1, "record Y2 wrong alignment");
_Static_assert(sizeof(struct Y2_required_alignment) == 2, "record Y2 wrong sizeof");
_Static_assert(_Alignof(struct Y2_required_alignment) == 1, "record Y2 wrong alignment");
_Static_assert(sizeof(struct Y2_size) == 3, "record Y2 wrong sizeof");
_Static_assert(_Alignof(struct Y2_size) == 1, "record Y2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(Y2,d) == 0, "field Y2.d wrong bit offset");
#endif
_Static_assert(sizeof(A3) == 33, "record A3 wrong sizeof");
_Static_assert(_Alignof(A3) == 1, "record A3 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A3_alignment) == 34, "record A3 wrong sizeof");
_Static_assert(_Alignof(struct A3_alignment) == 1, "record A3 wrong alignment");
_Static_assert(sizeof(struct A3_packed) == 33, "record A3 wrong sizeof");
_Static_assert(_Alignof(struct A3_packed) == 1, "record A3 wrong alignment");
_Static_assert(sizeof(struct A3_required_alignment) == 34, "record A3 wrong sizeof");
_Static_assert(_Alignof(struct A3_required_alignment) == 1, "record A3 wrong alignment");
_Static_assert(sizeof(struct A3_size) == 35, "record A3 wrong sizeof");
_Static_assert(_Alignof(struct A3_size) == 1, "record A3 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A3,d) == 256, "field A3.d wrong bit offset");
#endif
_Static_assert(sizeof(A4) == 1, "record A4 wrong sizeof");
_Static_assert(_Alignof(A4) == 32, "record A4 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A4_alignment) == 64, "record A4 wrong sizeof");
_Static_assert(_Alignof(struct A4_alignment) == 32, "record A4 wrong alignment");
_Static_assert(sizeof(struct A4_packed) == 1, "record A4 wrong sizeof");
_Static_assert(_Alignof(struct A4_packed) == 1, "record A4 wrong alignment");
_Static_assert(sizeof(struct A4_required_alignment) == 2, "record A4 wrong sizeof");
_Static_assert(_Alignof(struct A4_required_alignment) == 1, "record A4 wrong alignment");
_Static_assert(sizeof(struct A4_size) == 3, "record A4 wrong sizeof");
_Static_assert(_Alignof(struct A4_size) == 1, "record A4 wrong alignment");
#endif
_Static_assert(sizeof(A5) == 33, "record A5 wrong sizeof");
_Static_assert(_Alignof(A5) == 1, "record A5 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A5_alignment) == 34, "record A5 wrong sizeof");
_Static_assert(_Alignof(struct A5_alignment) == 1, "record A5 wrong alignment");
_Static_assert(sizeof(struct A5_packed) == 33, "record A5 wrong sizeof");
_Static_assert(_Alignof(struct A5_packed) == 1, "record A5 wrong alignment");
_Static_assert(sizeof(struct A5_required_alignment) == 34, "record A5 wrong sizeof");
_Static_assert(_Alignof(struct A5_required_alignment) == 1, "record A5 wrong alignment");
_Static_assert(sizeof(struct A5_size) == 35, "record A5 wrong sizeof");
_Static_assert(_Alignof(struct A5_size) == 1, "record A5 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A5,d) == 256, "field A5.d wrong bit offset");
#endif
_Static_assert(sizeof(A7) == 32, "record A7 wrong sizeof");
_Static_assert(_Alignof(A7) == 32, "record A7 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A7_alignment) == 64, "record A7 wrong sizeof");
_Static_assert(_Alignof(struct A7_alignment) == 32, "record A7 wrong alignment");
_Static_assert(sizeof(struct A7_packed) == 32, "record A7 wrong sizeof");
_Static_assert(_Alignof(struct A7_packed) == 1, "record A7 wrong alignment");
_Static_assert(sizeof(struct A7_required_alignment) == 33, "record A7 wrong sizeof");
_Static_assert(_Alignof(struct A7_required_alignment) == 1, "record A7 wrong alignment");
_Static_assert(sizeof(struct A7_size) == 34, "record A7 wrong sizeof");
_Static_assert(_Alignof(struct A7_size) == 1, "record A7 wrong alignment");
#endif
_Static_assert(sizeof(A8) == 8, "record A8 wrong sizeof");
_Static_assert(_Alignof(A8) == 8, "record A8 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A8_alignment) == 16, "record A8 wrong sizeof");
_Static_assert(_Alignof(struct A8_alignment) == 8, "record A8 wrong alignment");
_Static_assert(sizeof(struct A8_packed) == 8, "record A8 wrong sizeof");
_Static_assert(_Alignof(struct A8_packed) == 1, "record A8 wrong alignment");
_Static_assert(sizeof(struct A8_required_alignment) == 9, "record A8 wrong sizeof");
_Static_assert(_Alignof(struct A8_required_alignment) == 1, "record A8 wrong alignment");
_Static_assert(sizeof(struct A8_size) == 10, "record A8 wrong sizeof");
_Static_assert(_Alignof(struct A8_size) == 1, "record A8 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A8,i) == 8, "field A8.i wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A8,j) == 39, "field A8.j wrong bit offset");
#endif
_Static_assert(sizeof(A9) == 16, "record A9 wrong sizeof");
_Static_assert(_Alignof(A9) == 8, "record A9 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A9_alignment) == 24, "record A9 wrong sizeof");
_Static_assert(_Alignof(struct A9_alignment) == 8, "record A9 wrong alignment");
_Static_assert(sizeof(struct A9_packed) == 16, "record A9 wrong sizeof");
_Static_assert(_Alignof(struct A9_packed) == 1, "record A9 wrong alignment");
_Static_assert(sizeof(struct A9_required_alignment) == 17, "record A9 wrong sizeof");
_Static_assert(_Alignof(struct A9_required_alignment) == 1, "record A9 wrong alignment");
_Static_assert(sizeof(struct A9_size) == 18, "record A9 wrong sizeof");
_Static_assert(_Alignof(struct A9_size) == 1, "record A9 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A9,i) == 8, "field A9.i wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A9,j) == 64, "field A9.j wrong bit offset");
#endif
_Static_assert(sizeof(A10) == 8, "record A10 wrong sizeof");
_Static_assert(_Alignof(A10) == 16, "record A10 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A10_alignment) == 32, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_alignment) == 16, "record A10 wrong alignment");
_Static_assert(sizeof(struct A10_packed) == 8, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_packed) == 1, "record A10 wrong alignment");
_Static_assert(sizeof(struct A10_required_alignment) == 9, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_required_alignment) == 1, "record A10 wrong alignment");
_Static_assert(sizeof(struct A10_size) == 10, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_size) == 1, "record A10 wrong alignment");
#endif
_Static_assert(sizeof(A11) == 16, "record A11 wrong sizeof");
_Static_assert(_Alignof(A11) == 16, "record A11 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A11_alignment) == 32, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_alignment) == 16, "record A11 wrong alignment");
_Static_assert(sizeof(struct A11_packed) == 16, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_packed) == 1, "record A11 wrong alignment");
_Static_assert(sizeof(struct A11_required_alignment) == 17, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_required_alignment) == 1, "record A11 wrong alignment");
_Static_assert(sizeof(struct A11_size) == 18, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_size) == 1, "record A11 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A11,i) == 8, "field A11.i wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A11,j) == 39, "field A11.j wrong bit offset");
#endif
_Static_assert(sizeof(A12) == 32, "record A12 wrong sizeof");
_Static_assert(_Alignof(A12) == 16, "record A12 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A12_alignment) == 48, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_alignment) == 16, "record A12 wrong alignment");
_Static_assert(sizeof(struct A12_packed) == 32, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_packed) == 1, "record A12 wrong alignment");
_Static_assert(sizeof(struct A12_required_alignment) == 33, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_required_alignment) == 1, "record A12 wrong alignment");
_Static_assert(sizeof(struct A12_size) == 34, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_size) == 1, "record A12 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A12,i) == 8, "field A12.i wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A12,j) == 128, "field A12.j wrong bit offset");
#endif
_Static_assert(sizeof(A13) == 32, "record A13 wrong sizeof");
_Static_assert(_Alignof(A13) == 16, "record A13 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A13_alignment) == 48, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_alignment) == 16, "record A13 wrong alignment");
_Static_assert(sizeof(struct A13_packed) == 32, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_packed) == 1, "record A13 wrong alignment");
_Static_assert(sizeof(struct A13_required_alignment) == 33, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_required_alignment) == 1, "record A13 wrong alignment");
_Static_assert(sizeof(struct A13_size) == 34, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_size) == 1, "record A13 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A13,i) == 8, "field A13.i wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A13,j) == 128, "field A13.j wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A13,d) == 136, "field A13.d wrong bit offset");
#endif
// MAPPING|TWO|aarch64-generic-fuchsia-gnu:Clang|aarch64-generic-linux-android:Clang|aarch64-generic-freebsd-gnu:Clang|aarch64-generic-hermit-eabi:Clang|aarch64-generic-netbsd-gnu:Clang|aarch64-generic-other-none:Clang|aarch64-generic-openbsd-gnu:Clang|END
// repr targets Aarch64Fuchsia|Some("aarch64-generic-fuchsia-gnu") Aarch64LinuxAndroid|Some("aarch64-generic-linux-android") Aarch64UnknownFreebsd|Some("aarch64-generic-freebsd-gnu") Aarch64UnknownHermit|Some("aarch64-generic-hermit-eabi") Aarch64UnknownNetbsd|Some("aarch64-generic-netbsd-gnu") Aarch64UnknownNone|Some("aarch64-generic-other-none") Aarch64UnknownOpenbsd|Some("aarch64-generic-openbsd-gnu") Aarch64UnknownRedox|None 
#elif defined(TWO)
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
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A,d) == 0, "field A.d wrong bit offset");
#endif
_Static_assert(sizeof(A_) == 8, "record A_ wrong sizeof");
_Static_assert(_Alignof(A_) == 4, "record A_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A__alignment) == 12, "record A_ wrong sizeof");
_Static_assert(_Alignof(struct A__alignment) == 4, "record A_ wrong alignment");
_Static_assert(sizeof(struct A__packed) == 8, "record A_ wrong sizeof");
_Static_assert(_Alignof(struct A__packed) == 1, "record A_ wrong alignment");
_Static_assert(sizeof(struct A__required_alignment) == 9, "record A_ wrong sizeof");
_Static_assert(_Alignof(struct A__required_alignment) == 1, "record A_ wrong alignment");
_Static_assert(sizeof(struct A__size) == 10, "record A_ wrong sizeof");
_Static_assert(_Alignof(struct A__size) == 1, "record A_ wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_,d) == 32, "field A_.d wrong bit offset");
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
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B,d) == 0, "field B.d wrong bit offset");
#endif
_Static_assert(sizeof(B_) == 16, "record B_ wrong sizeof");
_Static_assert(_Alignof(B_) == 8, "record B_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B__alignment) == 24, "record B_ wrong sizeof");
_Static_assert(_Alignof(struct B__alignment) == 8, "record B_ wrong alignment");
_Static_assert(sizeof(struct B__packed) == 16, "record B_ wrong sizeof");
_Static_assert(_Alignof(struct B__packed) == 1, "record B_ wrong alignment");
_Static_assert(sizeof(struct B__required_alignment) == 17, "record B_ wrong sizeof");
_Static_assert(_Alignof(struct B__required_alignment) == 1, "record B_ wrong alignment");
_Static_assert(sizeof(struct B__size) == 18, "record B_ wrong sizeof");
_Static_assert(_Alignof(struct B__size) == 1, "record B_ wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B_,d) == 64, "field B_.d wrong bit offset");
#endif
_Static_assert(sizeof(C) == 8, "record C wrong sizeof");
_Static_assert(_Alignof(C) == 8, "record C wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 16, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_alignment) == 8, "record C wrong alignment");
_Static_assert(sizeof(struct C_packed) == 8, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_packed) == 1, "record C wrong alignment");
_Static_assert(sizeof(struct C_required_alignment) == 9, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "record C wrong alignment");
_Static_assert(sizeof(struct C_size) == 10, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_size) == 1, "record C wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C,d) == 0, "field C.d wrong bit offset");
#endif
_Static_assert(sizeof(C_) == 16, "record C_ wrong sizeof");
_Static_assert(_Alignof(C_) == 8, "record C_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C__alignment) == 24, "record C_ wrong sizeof");
_Static_assert(_Alignof(struct C__alignment) == 8, "record C_ wrong alignment");
_Static_assert(sizeof(struct C__packed) == 16, "record C_ wrong sizeof");
_Static_assert(_Alignof(struct C__packed) == 1, "record C_ wrong alignment");
_Static_assert(sizeof(struct C__required_alignment) == 17, "record C_ wrong sizeof");
_Static_assert(_Alignof(struct C__required_alignment) == 1, "record C_ wrong alignment");
_Static_assert(sizeof(struct C__size) == 18, "record C_ wrong sizeof");
_Static_assert(_Alignof(struct C__size) == 1, "record C_ wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C_,d) == 64, "field C_.d wrong bit offset");
#endif
_Static_assert(sizeof(D) == 24, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 8, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 32, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 8, "record D wrong alignment");
_Static_assert(sizeof(struct D_packed) == 24, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 25, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_size) == 26, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_size) == 1, "record D wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D,d) == 64, "field D.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(D,e) == 128, "field D.e wrong bit offset");
#endif
_Static_assert(sizeof(F) == 32, "record F wrong sizeof");
_Static_assert(_Alignof(F) == 16, "record F wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 48, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_alignment) == 16, "record F wrong alignment");
_Static_assert(sizeof(struct F_packed) == 32, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_packed) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_required_alignment) == 33, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_size) == 34, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_size) == 1, "record F wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F,d) == 128, "field F.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(F,e) == 192, "field F.e wrong bit offset");
#endif
_Static_assert(sizeof(G) == 12, "record G wrong sizeof");
_Static_assert(_Alignof(G) == 2, "record G wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 14, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_alignment) == 2, "record G wrong alignment");
_Static_assert(sizeof(struct G_packed) == 12, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_packed) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_required_alignment) == 13, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_size) == 14, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_size) == 1, "record G wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(G,d) == 16, "field G.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(G,e) == 80, "field G.e wrong bit offset");
#endif
_Static_assert(sizeof(H) == 12, "record H wrong sizeof");
_Static_assert(_Alignof(H) == 2, "record H wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 14, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_alignment) == 2, "record H wrong alignment");
_Static_assert(sizeof(struct H_packed) == 12, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_packed) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_required_alignment) == 13, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_size) == 14, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_size) == 1, "record H wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(H,d) == 16, "field H.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(H,e) == 80, "field H.e wrong bit offset");
#endif
_Static_assert(sizeof(I) == 10, "record I wrong sizeof");
_Static_assert(_Alignof(I) == 1, "record I wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I_alignment) == 11, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_alignment) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_packed) == 10, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_packed) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_required_alignment) == 11, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_required_alignment) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_size) == 12, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_size) == 1, "record I wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(I,d) == 8, "field I.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(I,e) == 72, "field I.e wrong bit offset");
#endif
_Static_assert(sizeof(J) == 12, "record J wrong sizeof");
_Static_assert(_Alignof(J) == 2, "record J wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J_alignment) == 14, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_alignment) == 2, "record J wrong alignment");
_Static_assert(sizeof(struct J_packed) == 12, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_packed) == 1, "record J wrong alignment");
_Static_assert(sizeof(struct J_required_alignment) == 13, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_required_alignment) == 1, "record J wrong alignment");
_Static_assert(sizeof(struct J_size) == 14, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_size) == 1, "record J wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(J,d) == 16, "field J.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(J,e) == 80, "field J.e wrong bit offset");
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
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(K,d) == 8, "field K.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(K,e) == 16, "field K.e wrong bit offset");
#endif
_Static_assert(sizeof(L) == 32, "record L wrong sizeof");
_Static_assert(_Alignof(L) == 16, "record L wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct L_alignment) == 48, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_alignment) == 16, "record L wrong alignment");
_Static_assert(sizeof(struct L_packed) == 32, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_packed) == 1, "record L wrong alignment");
_Static_assert(sizeof(struct L_required_alignment) == 33, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_required_alignment) == 1, "record L wrong alignment");
_Static_assert(sizeof(struct L_size) == 34, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_size) == 1, "record L wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(L,d) == 128, "field L.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(L,e) == 136, "field L.e wrong bit offset");
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
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(M,d) == 16, "field M.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(M,e) == 24, "field M.e wrong bit offset");
#endif
_Static_assert(sizeof(N) == 4, "record N wrong sizeof");
_Static_assert(_Alignof(N) == 2, "record N wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct N_alignment) == 6, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_alignment) == 2, "record N wrong alignment");
_Static_assert(sizeof(struct N_packed) == 4, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_packed) == 1, "record N wrong alignment");
_Static_assert(sizeof(struct N_required_alignment) == 5, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_required_alignment) == 1, "record N wrong alignment");
_Static_assert(sizeof(struct N_size) == 6, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_size) == 1, "record N wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(N,d) == 8, "field N.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(N,e) == 16, "field N.e wrong bit offset");
#endif
_Static_assert(sizeof(O) == 3, "record O wrong sizeof");
_Static_assert(_Alignof(O) == 1, "record O wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct O_alignment) == 4, "record O wrong sizeof");
_Static_assert(_Alignof(struct O_alignment) == 1, "record O wrong alignment");
_Static_assert(sizeof(struct O_packed) == 3, "record O wrong sizeof");
_Static_assert(_Alignof(struct O_packed) == 1, "record O wrong alignment");
_Static_assert(sizeof(struct O_required_alignment) == 4, "record O wrong sizeof");
_Static_assert(_Alignof(struct O_required_alignment) == 1, "record O wrong alignment");
_Static_assert(sizeof(struct O_size) == 5, "record O wrong sizeof");
_Static_assert(_Alignof(struct O_size) == 1, "record O wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(O,d) == 8, "field O.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(O,e) == 16, "field O.e wrong bit offset");
#endif
_Static_assert(sizeof(P) == 4, "record P wrong sizeof");
_Static_assert(_Alignof(P) == 2, "record P wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct P_alignment) == 6, "record P wrong sizeof");
_Static_assert(_Alignof(struct P_alignment) == 2, "record P wrong alignment");
_Static_assert(sizeof(struct P_packed) == 4, "record P wrong sizeof");
_Static_assert(_Alignof(struct P_packed) == 1, "record P wrong alignment");
_Static_assert(sizeof(struct P_required_alignment) == 5, "record P wrong sizeof");
_Static_assert(_Alignof(struct P_required_alignment) == 1, "record P wrong alignment");
_Static_assert(sizeof(struct P_size) == 6, "record P wrong sizeof");
_Static_assert(_Alignof(struct P_size) == 1, "record P wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(P,d) == 8, "field P.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(P,e) == 16, "field P.e wrong bit offset");
#endif
_Static_assert(sizeof(Q) == 8, "record Q wrong sizeof");
_Static_assert(_Alignof(Q) == 8, "record Q wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Q_alignment) == 16, "record Q wrong sizeof");
_Static_assert(_Alignof(struct Q_alignment) == 8, "record Q wrong alignment");
_Static_assert(sizeof(struct Q_packed) == 8, "record Q wrong sizeof");
_Static_assert(_Alignof(struct Q_packed) == 1, "record Q wrong alignment");
_Static_assert(sizeof(struct Q_required_alignment) == 9, "record Q wrong sizeof");
_Static_assert(_Alignof(struct Q_required_alignment) == 1, "record Q wrong alignment");
_Static_assert(sizeof(struct Q_size) == 10, "record Q wrong sizeof");
_Static_assert(_Alignof(struct Q_size) == 1, "record Q wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(Q,x) == 8, "field Q.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(Q,d) == 9, "field Q.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(Q,e) == 16, "field Q.e wrong bit offset");
#endif
_Static_assert(sizeof(R) == 32, "record R wrong sizeof");
_Static_assert(_Alignof(R) == 16, "record R wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct R_alignment) == 48, "record R wrong sizeof");
_Static_assert(_Alignof(struct R_alignment) == 16, "record R wrong alignment");
_Static_assert(sizeof(struct R_packed) == 32, "record R wrong sizeof");
_Static_assert(_Alignof(struct R_packed) == 1, "record R wrong alignment");
_Static_assert(sizeof(struct R_required_alignment) == 33, "record R wrong sizeof");
_Static_assert(_Alignof(struct R_required_alignment) == 1, "record R wrong alignment");
_Static_assert(sizeof(struct R_size) == 34, "record R wrong sizeof");
_Static_assert(_Alignof(struct R_size) == 1, "record R wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(R,x) == 8, "field R.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(R,e) == 128, "field R.e wrong bit offset");
#endif
_Static_assert(sizeof(S) == 16, "record S wrong sizeof");
_Static_assert(_Alignof(S) == 8, "record S wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct S_alignment) == 24, "record S wrong sizeof");
_Static_assert(_Alignof(struct S_alignment) == 8, "record S wrong alignment");
_Static_assert(sizeof(struct S_packed) == 16, "record S wrong sizeof");
_Static_assert(_Alignof(struct S_packed) == 1, "record S wrong alignment");
_Static_assert(sizeof(struct S_required_alignment) == 17, "record S wrong sizeof");
_Static_assert(_Alignof(struct S_required_alignment) == 1, "record S wrong alignment");
_Static_assert(sizeof(struct S_size) == 18, "record S wrong sizeof");
_Static_assert(_Alignof(struct S_size) == 1, "record S wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(S,x) == 8, "field S.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(S,e) == 64, "field S.e wrong bit offset");
#endif
_Static_assert(sizeof(T) == 16, "record T wrong sizeof");
_Static_assert(_Alignof(T) == 8, "record T wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct T_alignment) == 24, "record T wrong sizeof");
_Static_assert(_Alignof(struct T_alignment) == 8, "record T wrong alignment");
_Static_assert(sizeof(struct T_packed) == 16, "record T wrong sizeof");
_Static_assert(_Alignof(struct T_packed) == 1, "record T wrong alignment");
_Static_assert(sizeof(struct T_required_alignment) == 17, "record T wrong sizeof");
_Static_assert(_Alignof(struct T_required_alignment) == 1, "record T wrong alignment");
_Static_assert(sizeof(struct T_size) == 18, "record T wrong sizeof");
_Static_assert(_Alignof(struct T_size) == 1, "record T wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(T,x) == 8, "field T.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(T,e) == 64, "field T.e wrong bit offset");
#endif
_Static_assert(sizeof(U) == 16, "record U wrong sizeof");
_Static_assert(_Alignof(U) == 8, "record U wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct U_alignment) == 24, "record U wrong sizeof");
_Static_assert(_Alignof(struct U_alignment) == 8, "record U wrong alignment");
_Static_assert(sizeof(struct U_packed) == 16, "record U wrong sizeof");
_Static_assert(_Alignof(struct U_packed) == 1, "record U wrong alignment");
_Static_assert(sizeof(struct U_required_alignment) == 17, "record U wrong sizeof");
_Static_assert(_Alignof(struct U_required_alignment) == 1, "record U wrong alignment");
_Static_assert(sizeof(struct U_size) == 18, "record U wrong sizeof");
_Static_assert(_Alignof(struct U_size) == 1, "record U wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(U,x) == 8, "field U.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(U,e) == 64, "field U.e wrong bit offset");
#endif
_Static_assert(sizeof(V) == 16, "record V wrong sizeof");
_Static_assert(_Alignof(V) == 8, "record V wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct V_alignment) == 24, "record V wrong sizeof");
_Static_assert(_Alignof(struct V_alignment) == 8, "record V wrong alignment");
_Static_assert(sizeof(struct V_packed) == 16, "record V wrong sizeof");
_Static_assert(_Alignof(struct V_packed) == 1, "record V wrong alignment");
_Static_assert(sizeof(struct V_required_alignment) == 17, "record V wrong sizeof");
_Static_assert(_Alignof(struct V_required_alignment) == 1, "record V wrong alignment");
_Static_assert(sizeof(struct V_size) == 18, "record V wrong sizeof");
_Static_assert(_Alignof(struct V_size) == 1, "record V wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(V,x) == 8, "field V.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(V,e) == 64, "field V.e wrong bit offset");
#endif
_Static_assert(sizeof(W) == 32, "record W wrong sizeof");
_Static_assert(_Alignof(W) == 16, "record W wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct W_alignment) == 48, "record W wrong sizeof");
_Static_assert(_Alignof(struct W_alignment) == 16, "record W wrong alignment");
_Static_assert(sizeof(struct W_packed) == 32, "record W wrong sizeof");
_Static_assert(_Alignof(struct W_packed) == 1, "record W wrong alignment");
_Static_assert(sizeof(struct W_required_alignment) == 33, "record W wrong sizeof");
_Static_assert(_Alignof(struct W_required_alignment) == 1, "record W wrong alignment");
_Static_assert(sizeof(struct W_size) == 34, "record W wrong sizeof");
_Static_assert(_Alignof(struct W_size) == 1, "record W wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(W,x) == 8, "field W.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(W,e) == 128, "field W.e wrong bit offset");
#endif
_Static_assert(sizeof(W_) == 32, "record W_ wrong sizeof");
_Static_assert(_Alignof(W_) == 16, "record W_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct W__alignment) == 48, "record W_ wrong sizeof");
_Static_assert(_Alignof(struct W__alignment) == 16, "record W_ wrong alignment");
_Static_assert(sizeof(struct W__packed) == 32, "record W_ wrong sizeof");
_Static_assert(_Alignof(struct W__packed) == 1, "record W_ wrong alignment");
_Static_assert(sizeof(struct W__required_alignment) == 33, "record W_ wrong sizeof");
_Static_assert(_Alignof(struct W__required_alignment) == 1, "record W_ wrong alignment");
_Static_assert(sizeof(struct W__size) == 34, "record W_ wrong sizeof");
_Static_assert(_Alignof(struct W__size) == 1, "record W_ wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(W_,e) == 128, "field W_.e wrong bit offset");
#endif
_Static_assert(sizeof(X) == 32, "record X wrong sizeof");
_Static_assert(_Alignof(X) == 16, "record X wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct X_alignment) == 48, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_alignment) == 16, "record X wrong alignment");
_Static_assert(sizeof(struct X_packed) == 32, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_packed) == 1, "record X wrong alignment");
_Static_assert(sizeof(struct X_required_alignment) == 33, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_required_alignment) == 1, "record X wrong alignment");
_Static_assert(sizeof(struct X_size) == 34, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_size) == 1, "record X wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(X,x) == 8, "field X.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(X,e) == 128, "field X.e wrong bit offset");
#endif
_Static_assert(sizeof(A2) == 4, "record A2 wrong sizeof");
_Static_assert(_Alignof(A2) == 4, "record A2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A2_alignment) == 8, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_alignment) == 4, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_packed) == 4, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_packed) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_required_alignment) == 5, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_required_alignment) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_size) == 6, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_size) == 1, "record A2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A2,d) == 0, "field A2.d wrong bit offset");
#endif
_Static_assert(sizeof(A_2) == 4, "record A_2 wrong sizeof");
_Static_assert(_Alignof(A_2) == 4, "record A_2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_2_alignment) == 8, "record A_2 wrong sizeof");
_Static_assert(_Alignof(struct A_2_alignment) == 4, "record A_2 wrong alignment");
_Static_assert(sizeof(struct A_2_packed) == 4, "record A_2 wrong sizeof");
_Static_assert(_Alignof(struct A_2_packed) == 1, "record A_2 wrong alignment");
_Static_assert(sizeof(struct A_2_required_alignment) == 5, "record A_2 wrong sizeof");
_Static_assert(_Alignof(struct A_2_required_alignment) == 1, "record A_2 wrong alignment");
_Static_assert(sizeof(struct A_2_size) == 6, "record A_2 wrong sizeof");
_Static_assert(_Alignof(struct A_2_size) == 1, "record A_2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_2,d) == 0, "field A_2.d wrong bit offset");
#endif
_Static_assert(sizeof(B2) == 8, "record B2 wrong sizeof");
_Static_assert(_Alignof(B2) == 8, "record B2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B2_alignment) == 16, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_alignment) == 8, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_packed) == 8, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_packed) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_required_alignment) == 9, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_required_alignment) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_size) == 10, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_size) == 1, "record B2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B2,d) == 0, "field B2.d wrong bit offset");
#endif
_Static_assert(sizeof(B_2) == 8, "record B_2 wrong sizeof");
_Static_assert(_Alignof(B_2) == 8, "record B_2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_2_alignment) == 16, "record B_2 wrong sizeof");
_Static_assert(_Alignof(struct B_2_alignment) == 8, "record B_2 wrong alignment");
_Static_assert(sizeof(struct B_2_packed) == 8, "record B_2 wrong sizeof");
_Static_assert(_Alignof(struct B_2_packed) == 1, "record B_2 wrong alignment");
_Static_assert(sizeof(struct B_2_required_alignment) == 9, "record B_2 wrong sizeof");
_Static_assert(_Alignof(struct B_2_required_alignment) == 1, "record B_2 wrong alignment");
_Static_assert(sizeof(struct B_2_size) == 10, "record B_2 wrong sizeof");
_Static_assert(_Alignof(struct B_2_size) == 1, "record B_2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B_2,d) == 0, "field B_2.d wrong bit offset");
#endif
_Static_assert(sizeof(C2) == 8, "record C2 wrong sizeof");
_Static_assert(_Alignof(C2) == 8, "record C2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C2_alignment) == 16, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_alignment) == 8, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_packed) == 8, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_packed) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_required_alignment) == 9, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_required_alignment) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_size) == 10, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_size) == 1, "record C2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C2,d) == 0, "field C2.d wrong bit offset");
#endif
_Static_assert(sizeof(C22) == 8, "record C22 wrong sizeof");
_Static_assert(_Alignof(C22) == 8, "record C22 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C22_alignment) == 16, "record C22 wrong sizeof");
_Static_assert(_Alignof(struct C22_alignment) == 8, "record C22 wrong alignment");
_Static_assert(sizeof(struct C22_packed) == 8, "record C22 wrong sizeof");
_Static_assert(_Alignof(struct C22_packed) == 1, "record C22 wrong alignment");
_Static_assert(sizeof(struct C22_required_alignment) == 9, "record C22 wrong sizeof");
_Static_assert(_Alignof(struct C22_required_alignment) == 1, "record C22 wrong alignment");
_Static_assert(sizeof(struct C22_size) == 10, "record C22 wrong sizeof");
_Static_assert(_Alignof(struct C22_size) == 1, "record C22 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C22,d) == 0, "field C22.d wrong bit offset");
#endif
_Static_assert(sizeof(D2) == 8, "record D2 wrong sizeof");
_Static_assert(_Alignof(D2) == 8, "record D2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D2_alignment) == 16, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_alignment) == 8, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_packed) == 8, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_packed) == 1, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_required_alignment) == 9, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_required_alignment) == 1, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_size) == 10, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_size) == 1, "record D2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D2,d) == 0, "field D2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(D2,e) == 0, "field D2.e wrong bit offset");
#endif
_Static_assert(sizeof(F2) == 16, "record F2 wrong sizeof");
_Static_assert(_Alignof(F2) == 16, "record F2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F2_alignment) == 32, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_alignment) == 16, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_packed) == 16, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_packed) == 1, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_required_alignment) == 17, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_required_alignment) == 1, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_size) == 18, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_size) == 1, "record F2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F2,d) == 0, "field F2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(F2,e) == 0, "field F2.e wrong bit offset");
#endif
_Static_assert(sizeof(G2) == 8, "record G2 wrong sizeof");
_Static_assert(_Alignof(G2) == 2, "record G2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G2_alignment) == 10, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_alignment) == 2, "record G2 wrong alignment");
_Static_assert(sizeof(struct G2_packed) == 8, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_packed) == 1, "record G2 wrong alignment");
_Static_assert(sizeof(struct G2_required_alignment) == 9, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_required_alignment) == 1, "record G2 wrong alignment");
_Static_assert(sizeof(struct G2_size) == 10, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_size) == 1, "record G2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(G2,d) == 0, "field G2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(G2,e) == 0, "field G2.e wrong bit offset");
#endif
_Static_assert(sizeof(H2) == 8, "record H2 wrong sizeof");
_Static_assert(_Alignof(H2) == 2, "record H2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H2_alignment) == 10, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_alignment) == 2, "record H2 wrong alignment");
_Static_assert(sizeof(struct H2_packed) == 8, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_packed) == 1, "record H2 wrong alignment");
_Static_assert(sizeof(struct H2_required_alignment) == 9, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_required_alignment) == 1, "record H2 wrong alignment");
_Static_assert(sizeof(struct H2_size) == 10, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_size) == 1, "record H2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(H2,d) == 0, "field H2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(H2,e) == 0, "field H2.e wrong bit offset");
#endif
_Static_assert(sizeof(I2) == 8, "record I2 wrong sizeof");
_Static_assert(_Alignof(I2) == 1, "record I2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I2_alignment) == 9, "record I2 wrong sizeof");
_Static_assert(_Alignof(struct I2_alignment) == 1, "record I2 wrong alignment");
_Static_assert(sizeof(struct I2_packed) == 8, "record I2 wrong sizeof");
_Static_assert(_Alignof(struct I2_packed) == 1, "record I2 wrong alignment");
_Static_assert(sizeof(struct I2_required_alignment) == 9, "record I2 wrong sizeof");
_Static_assert(_Alignof(struct I2_required_alignment) == 1, "record I2 wrong alignment");
_Static_assert(sizeof(struct I2_size) == 10, "record I2 wrong sizeof");
_Static_assert(_Alignof(struct I2_size) == 1, "record I2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(I2,d) == 0, "field I2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(I2,e) == 0, "field I2.e wrong bit offset");
#endif
_Static_assert(sizeof(J2) == 8, "record J2 wrong sizeof");
_Static_assert(_Alignof(J2) == 2, "record J2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J2_alignment) == 10, "record J2 wrong sizeof");
_Static_assert(_Alignof(struct J2_alignment) == 2, "record J2 wrong alignment");
_Static_assert(sizeof(struct J2_packed) == 8, "record J2 wrong sizeof");
_Static_assert(_Alignof(struct J2_packed) == 1, "record J2 wrong alignment");
_Static_assert(sizeof(struct J2_required_alignment) == 9, "record J2 wrong sizeof");
_Static_assert(_Alignof(struct J2_required_alignment) == 1, "record J2 wrong alignment");
_Static_assert(sizeof(struct J2_size) == 10, "record J2 wrong sizeof");
_Static_assert(_Alignof(struct J2_size) == 1, "record J2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(J2,d) == 0, "field J2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(J2,e) == 0, "field J2.e wrong bit offset");
#endif
_Static_assert(sizeof(K2) == 8, "record K2 wrong sizeof");
_Static_assert(_Alignof(K2) == 8, "record K2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct K2_alignment) == 16, "record K2 wrong sizeof");
_Static_assert(_Alignof(struct K2_alignment) == 8, "record K2 wrong alignment");
_Static_assert(sizeof(struct K2_packed) == 8, "record K2 wrong sizeof");
_Static_assert(_Alignof(struct K2_packed) == 1, "record K2 wrong alignment");
_Static_assert(sizeof(struct K2_required_alignment) == 9, "record K2 wrong sizeof");
_Static_assert(_Alignof(struct K2_required_alignment) == 1, "record K2 wrong alignment");
_Static_assert(sizeof(struct K2_size) == 10, "record K2 wrong sizeof");
_Static_assert(_Alignof(struct K2_size) == 1, "record K2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(K2,d) == 0, "field K2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(K2,e) == 0, "field K2.e wrong bit offset");
#endif
_Static_assert(sizeof(L2) == 16, "record L2 wrong sizeof");
_Static_assert(_Alignof(L2) == 16, "record L2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct L2_alignment) == 32, "record L2 wrong sizeof");
_Static_assert(_Alignof(struct L2_alignment) == 16, "record L2 wrong alignment");
_Static_assert(sizeof(struct L2_packed) == 16, "record L2 wrong sizeof");
_Static_assert(_Alignof(struct L2_packed) == 1, "record L2 wrong alignment");
_Static_assert(sizeof(struct L2_required_alignment) == 17, "record L2 wrong sizeof");
_Static_assert(_Alignof(struct L2_required_alignment) == 1, "record L2 wrong alignment");
_Static_assert(sizeof(struct L2_size) == 18, "record L2 wrong sizeof");
_Static_assert(_Alignof(struct L2_size) == 1, "record L2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(L2,d) == 0, "field L2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(L2,e) == 0, "field L2.e wrong bit offset");
#endif
_Static_assert(sizeof(M2) == 2, "record M2 wrong sizeof");
_Static_assert(_Alignof(M2) == 2, "record M2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct M2_alignment) == 4, "record M2 wrong sizeof");
_Static_assert(_Alignof(struct M2_alignment) == 2, "record M2 wrong alignment");
_Static_assert(sizeof(struct M2_packed) == 2, "record M2 wrong sizeof");
_Static_assert(_Alignof(struct M2_packed) == 1, "record M2 wrong alignment");
_Static_assert(sizeof(struct M2_required_alignment) == 3, "record M2 wrong sizeof");
_Static_assert(_Alignof(struct M2_required_alignment) == 1, "record M2 wrong alignment");
_Static_assert(sizeof(struct M2_size) == 4, "record M2 wrong sizeof");
_Static_assert(_Alignof(struct M2_size) == 1, "record M2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(M2,d) == 0, "field M2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(M2,e) == 0, "field M2.e wrong bit offset");
#endif
_Static_assert(sizeof(N2) == 2, "record N2 wrong sizeof");
_Static_assert(_Alignof(N2) == 2, "record N2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct N2_alignment) == 4, "record N2 wrong sizeof");
_Static_assert(_Alignof(struct N2_alignment) == 2, "record N2 wrong alignment");
_Static_assert(sizeof(struct N2_packed) == 2, "record N2 wrong sizeof");
_Static_assert(_Alignof(struct N2_packed) == 1, "record N2 wrong alignment");
_Static_assert(sizeof(struct N2_required_alignment) == 3, "record N2 wrong sizeof");
_Static_assert(_Alignof(struct N2_required_alignment) == 1, "record N2 wrong alignment");
_Static_assert(sizeof(struct N2_size) == 4, "record N2 wrong sizeof");
_Static_assert(_Alignof(struct N2_size) == 1, "record N2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(N2,d) == 0, "field N2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(N2,e) == 0, "field N2.e wrong bit offset");
#endif
_Static_assert(sizeof(O2) == 1, "record O2 wrong sizeof");
_Static_assert(_Alignof(O2) == 1, "record O2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct O2_alignment) == 2, "record O2 wrong sizeof");
_Static_assert(_Alignof(struct O2_alignment) == 1, "record O2 wrong alignment");
_Static_assert(sizeof(struct O2_packed) == 1, "record O2 wrong sizeof");
_Static_assert(_Alignof(struct O2_packed) == 1, "record O2 wrong alignment");
_Static_assert(sizeof(struct O2_required_alignment) == 2, "record O2 wrong sizeof");
_Static_assert(_Alignof(struct O2_required_alignment) == 1, "record O2 wrong alignment");
_Static_assert(sizeof(struct O2_size) == 3, "record O2 wrong sizeof");
_Static_assert(_Alignof(struct O2_size) == 1, "record O2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(O2,d) == 0, "field O2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(O2,e) == 0, "field O2.e wrong bit offset");
#endif
_Static_assert(sizeof(P2) == 2, "record P2 wrong sizeof");
_Static_assert(_Alignof(P2) == 2, "record P2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct P2_alignment) == 4, "record P2 wrong sizeof");
_Static_assert(_Alignof(struct P2_alignment) == 2, "record P2 wrong alignment");
_Static_assert(sizeof(struct P2_packed) == 2, "record P2 wrong sizeof");
_Static_assert(_Alignof(struct P2_packed) == 1, "record P2 wrong alignment");
_Static_assert(sizeof(struct P2_required_alignment) == 3, "record P2 wrong sizeof");
_Static_assert(_Alignof(struct P2_required_alignment) == 1, "record P2 wrong alignment");
_Static_assert(sizeof(struct P2_size) == 4, "record P2 wrong sizeof");
_Static_assert(_Alignof(struct P2_size) == 1, "record P2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(P2,d) == 0, "field P2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(P2,e) == 0, "field P2.e wrong bit offset");
#endif
_Static_assert(sizeof(Q2) == 8, "record Q2 wrong sizeof");
_Static_assert(_Alignof(Q2) == 8, "record Q2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Q2_alignment) == 16, "record Q2 wrong sizeof");
_Static_assert(_Alignof(struct Q2_alignment) == 8, "record Q2 wrong alignment");
_Static_assert(sizeof(struct Q2_packed) == 8, "record Q2 wrong sizeof");
_Static_assert(_Alignof(struct Q2_packed) == 1, "record Q2 wrong alignment");
_Static_assert(sizeof(struct Q2_required_alignment) == 9, "record Q2 wrong sizeof");
_Static_assert(_Alignof(struct Q2_required_alignment) == 1, "record Q2 wrong alignment");
_Static_assert(sizeof(struct Q2_size) == 10, "record Q2 wrong sizeof");
_Static_assert(_Alignof(struct Q2_size) == 1, "record Q2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(Q2,x) == 0, "field Q2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(Q2,d) == 0, "field Q2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(Q2,e) == 0, "field Q2.e wrong bit offset");
#endif
_Static_assert(sizeof(R2) == 16, "record R2 wrong sizeof");
_Static_assert(_Alignof(R2) == 16, "record R2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct R2_alignment) == 32, "record R2 wrong sizeof");
_Static_assert(_Alignof(struct R2_alignment) == 16, "record R2 wrong alignment");
_Static_assert(sizeof(struct R2_packed) == 16, "record R2 wrong sizeof");
_Static_assert(_Alignof(struct R2_packed) == 1, "record R2 wrong alignment");
_Static_assert(sizeof(struct R2_required_alignment) == 17, "record R2 wrong sizeof");
_Static_assert(_Alignof(struct R2_required_alignment) == 1, "record R2 wrong alignment");
_Static_assert(sizeof(struct R2_size) == 18, "record R2 wrong sizeof");
_Static_assert(_Alignof(struct R2_size) == 1, "record R2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(R2,x) == 0, "field R2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(R2,e) == 0, "field R2.e wrong bit offset");
#endif
_Static_assert(sizeof(S2) == 8, "record S2 wrong sizeof");
_Static_assert(_Alignof(S2) == 8, "record S2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct S2_alignment) == 16, "record S2 wrong sizeof");
_Static_assert(_Alignof(struct S2_alignment) == 8, "record S2 wrong alignment");
_Static_assert(sizeof(struct S2_packed) == 8, "record S2 wrong sizeof");
_Static_assert(_Alignof(struct S2_packed) == 1, "record S2 wrong alignment");
_Static_assert(sizeof(struct S2_required_alignment) == 9, "record S2 wrong sizeof");
_Static_assert(_Alignof(struct S2_required_alignment) == 1, "record S2 wrong alignment");
_Static_assert(sizeof(struct S2_size) == 10, "record S2 wrong sizeof");
_Static_assert(_Alignof(struct S2_size) == 1, "record S2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(S2,x) == 0, "field S2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(S2,e) == 0, "field S2.e wrong bit offset");
#endif
_Static_assert(sizeof(T2) == 8, "record T2 wrong sizeof");
_Static_assert(_Alignof(T2) == 8, "record T2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct T2_alignment) == 16, "record T2 wrong sizeof");
_Static_assert(_Alignof(struct T2_alignment) == 8, "record T2 wrong alignment");
_Static_assert(sizeof(struct T2_packed) == 8, "record T2 wrong sizeof");
_Static_assert(_Alignof(struct T2_packed) == 1, "record T2 wrong alignment");
_Static_assert(sizeof(struct T2_required_alignment) == 9, "record T2 wrong sizeof");
_Static_assert(_Alignof(struct T2_required_alignment) == 1, "record T2 wrong alignment");
_Static_assert(sizeof(struct T2_size) == 10, "record T2 wrong sizeof");
_Static_assert(_Alignof(struct T2_size) == 1, "record T2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(T2,x) == 0, "field T2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(T2,e) == 0, "field T2.e wrong bit offset");
#endif
_Static_assert(sizeof(U2) == 8, "record U2 wrong sizeof");
_Static_assert(_Alignof(U2) == 8, "record U2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct U2_alignment) == 16, "record U2 wrong sizeof");
_Static_assert(_Alignof(struct U2_alignment) == 8, "record U2 wrong alignment");
_Static_assert(sizeof(struct U2_packed) == 8, "record U2 wrong sizeof");
_Static_assert(_Alignof(struct U2_packed) == 1, "record U2 wrong alignment");
_Static_assert(sizeof(struct U2_required_alignment) == 9, "record U2 wrong sizeof");
_Static_assert(_Alignof(struct U2_required_alignment) == 1, "record U2 wrong alignment");
_Static_assert(sizeof(struct U2_size) == 10, "record U2 wrong sizeof");
_Static_assert(_Alignof(struct U2_size) == 1, "record U2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(U2,x) == 0, "field U2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(U2,e) == 0, "field U2.e wrong bit offset");
#endif
_Static_assert(sizeof(V2) == 8, "record V2 wrong sizeof");
_Static_assert(_Alignof(V2) == 8, "record V2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct V2_alignment) == 16, "record V2 wrong sizeof");
_Static_assert(_Alignof(struct V2_alignment) == 8, "record V2 wrong alignment");
_Static_assert(sizeof(struct V2_packed) == 8, "record V2 wrong sizeof");
_Static_assert(_Alignof(struct V2_packed) == 1, "record V2 wrong alignment");
_Static_assert(sizeof(struct V2_required_alignment) == 9, "record V2 wrong sizeof");
_Static_assert(_Alignof(struct V2_required_alignment) == 1, "record V2 wrong alignment");
_Static_assert(sizeof(struct V2_size) == 10, "record V2 wrong sizeof");
_Static_assert(_Alignof(struct V2_size) == 1, "record V2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(V2,x) == 0, "field V2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(V2,e) == 0, "field V2.e wrong bit offset");
#endif
_Static_assert(sizeof(W2) == 16, "record W2 wrong sizeof");
_Static_assert(_Alignof(W2) == 16, "record W2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct W2_alignment) == 32, "record W2 wrong sizeof");
_Static_assert(_Alignof(struct W2_alignment) == 16, "record W2 wrong alignment");
_Static_assert(sizeof(struct W2_packed) == 16, "record W2 wrong sizeof");
_Static_assert(_Alignof(struct W2_packed) == 1, "record W2 wrong alignment");
_Static_assert(sizeof(struct W2_required_alignment) == 17, "record W2 wrong sizeof");
_Static_assert(_Alignof(struct W2_required_alignment) == 1, "record W2 wrong alignment");
_Static_assert(sizeof(struct W2_size) == 18, "record W2 wrong sizeof");
_Static_assert(_Alignof(struct W2_size) == 1, "record W2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(W2,x) == 0, "field W2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(W2,e) == 0, "field W2.e wrong bit offset");
#endif
_Static_assert(sizeof(W_2) == 16, "record W_2 wrong sizeof");
_Static_assert(_Alignof(W_2) == 16, "record W_2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct W_2_alignment) == 32, "record W_2 wrong sizeof");
_Static_assert(_Alignof(struct W_2_alignment) == 16, "record W_2 wrong alignment");
_Static_assert(sizeof(struct W_2_packed) == 16, "record W_2 wrong sizeof");
_Static_assert(_Alignof(struct W_2_packed) == 1, "record W_2 wrong alignment");
_Static_assert(sizeof(struct W_2_required_alignment) == 17, "record W_2 wrong sizeof");
_Static_assert(_Alignof(struct W_2_required_alignment) == 1, "record W_2 wrong alignment");
_Static_assert(sizeof(struct W_2_size) == 18, "record W_2 wrong sizeof");
_Static_assert(_Alignof(struct W_2_size) == 1, "record W_2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(W_2,e) == 0, "field W_2.e wrong bit offset");
#endif
_Static_assert(sizeof(X2) == 16, "record X2 wrong sizeof");
_Static_assert(_Alignof(X2) == 16, "record X2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct X2_alignment) == 32, "record X2 wrong sizeof");
_Static_assert(_Alignof(struct X2_alignment) == 16, "record X2 wrong alignment");
_Static_assert(sizeof(struct X2_packed) == 16, "record X2 wrong sizeof");
_Static_assert(_Alignof(struct X2_packed) == 1, "record X2 wrong alignment");
_Static_assert(sizeof(struct X2_required_alignment) == 17, "record X2 wrong sizeof");
_Static_assert(_Alignof(struct X2_required_alignment) == 1, "record X2 wrong alignment");
_Static_assert(sizeof(struct X2_size) == 18, "record X2 wrong sizeof");
_Static_assert(_Alignof(struct X2_size) == 1, "record X2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(X2,x) == 0, "field X2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(X2,e) == 0, "field X2.e wrong bit offset");
#endif
_Static_assert(sizeof(Y) == 16, "record Y wrong sizeof");
_Static_assert(_Alignof(Y) == 8, "record Y wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Y_alignment) == 24, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_alignment) == 8, "record Y wrong alignment");
_Static_assert(sizeof(struct Y_packed) == 16, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_packed) == 1, "record Y wrong alignment");
_Static_assert(sizeof(struct Y_required_alignment) == 17, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_required_alignment) == 1, "record Y wrong alignment");
_Static_assert(sizeof(struct Y_size) == 18, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_size) == 1, "record Y wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(Y,d) == 64, "field Y.d wrong bit offset");
#endif
_Static_assert(sizeof(Y2) == 8, "record Y2 wrong sizeof");
_Static_assert(_Alignof(Y2) == 8, "record Y2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Y2_alignment) == 16, "record Y2 wrong sizeof");
_Static_assert(_Alignof(struct Y2_alignment) == 8, "record Y2 wrong alignment");
_Static_assert(sizeof(struct Y2_packed) == 8, "record Y2 wrong sizeof");
_Static_assert(_Alignof(struct Y2_packed) == 1, "record Y2 wrong alignment");
_Static_assert(sizeof(struct Y2_required_alignment) == 9, "record Y2 wrong sizeof");
_Static_assert(_Alignof(struct Y2_required_alignment) == 1, "record Y2 wrong alignment");
_Static_assert(sizeof(struct Y2_size) == 10, "record Y2 wrong sizeof");
_Static_assert(_Alignof(struct Y2_size) == 1, "record Y2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(Y2,d) == 0, "field Y2.d wrong bit offset");
#endif
_Static_assert(sizeof(A3) == 64, "record A3 wrong sizeof");
_Static_assert(_Alignof(A3) == 32, "record A3 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A3_alignment) == 96, "record A3 wrong sizeof");
_Static_assert(_Alignof(struct A3_alignment) == 32, "record A3 wrong alignment");
_Static_assert(sizeof(struct A3_packed) == 64, "record A3 wrong sizeof");
_Static_assert(_Alignof(struct A3_packed) == 1, "record A3 wrong alignment");
_Static_assert(sizeof(struct A3_required_alignment) == 65, "record A3 wrong sizeof");
_Static_assert(_Alignof(struct A3_required_alignment) == 1, "record A3 wrong alignment");
_Static_assert(sizeof(struct A3_size) == 66, "record A3 wrong sizeof");
_Static_assert(_Alignof(struct A3_size) == 1, "record A3 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A3,d) == 256, "field A3.d wrong bit offset");
#endif
_Static_assert(sizeof(A4) == 1, "record A4 wrong sizeof");
_Static_assert(_Alignof(A4) == 32, "record A4 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A4_alignment) == 64, "record A4 wrong sizeof");
_Static_assert(_Alignof(struct A4_alignment) == 32, "record A4 wrong alignment");
_Static_assert(sizeof(struct A4_packed) == 1, "record A4 wrong sizeof");
_Static_assert(_Alignof(struct A4_packed) == 1, "record A4 wrong alignment");
_Static_assert(sizeof(struct A4_required_alignment) == 2, "record A4 wrong sizeof");
_Static_assert(_Alignof(struct A4_required_alignment) == 1, "record A4 wrong alignment");
_Static_assert(sizeof(struct A4_size) == 3, "record A4 wrong sizeof");
_Static_assert(_Alignof(struct A4_size) == 1, "record A4 wrong alignment");
#endif
_Static_assert(sizeof(A5) == 64, "record A5 wrong sizeof");
_Static_assert(_Alignof(A5) == 32, "record A5 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A5_alignment) == 96, "record A5 wrong sizeof");
_Static_assert(_Alignof(struct A5_alignment) == 32, "record A5 wrong alignment");
_Static_assert(sizeof(struct A5_packed) == 64, "record A5 wrong sizeof");
_Static_assert(_Alignof(struct A5_packed) == 1, "record A5 wrong alignment");
_Static_assert(sizeof(struct A5_required_alignment) == 65, "record A5 wrong sizeof");
_Static_assert(_Alignof(struct A5_required_alignment) == 1, "record A5 wrong alignment");
_Static_assert(sizeof(struct A5_size) == 66, "record A5 wrong sizeof");
_Static_assert(_Alignof(struct A5_size) == 1, "record A5 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A5,d) == 256, "field A5.d wrong bit offset");
#endif
_Static_assert(sizeof(A7) == 32, "record A7 wrong sizeof");
_Static_assert(_Alignof(A7) == 32, "record A7 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A7_alignment) == 64, "record A7 wrong sizeof");
_Static_assert(_Alignof(struct A7_alignment) == 32, "record A7 wrong alignment");
_Static_assert(sizeof(struct A7_packed) == 32, "record A7 wrong sizeof");
_Static_assert(_Alignof(struct A7_packed) == 1, "record A7 wrong alignment");
_Static_assert(sizeof(struct A7_required_alignment) == 33, "record A7 wrong sizeof");
_Static_assert(_Alignof(struct A7_required_alignment) == 1, "record A7 wrong alignment");
_Static_assert(sizeof(struct A7_size) == 34, "record A7 wrong sizeof");
_Static_assert(_Alignof(struct A7_size) == 1, "record A7 wrong alignment");
#endif
_Static_assert(sizeof(A8) == 8, "record A8 wrong sizeof");
_Static_assert(_Alignof(A8) == 8, "record A8 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A8_alignment) == 16, "record A8 wrong sizeof");
_Static_assert(_Alignof(struct A8_alignment) == 8, "record A8 wrong alignment");
_Static_assert(sizeof(struct A8_packed) == 8, "record A8 wrong sizeof");
_Static_assert(_Alignof(struct A8_packed) == 1, "record A8 wrong alignment");
_Static_assert(sizeof(struct A8_required_alignment) == 9, "record A8 wrong sizeof");
_Static_assert(_Alignof(struct A8_required_alignment) == 1, "record A8 wrong alignment");
_Static_assert(sizeof(struct A8_size) == 10, "record A8 wrong sizeof");
_Static_assert(_Alignof(struct A8_size) == 1, "record A8 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A8,i) == 8, "field A8.i wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A8,j) == 39, "field A8.j wrong bit offset");
#endif
_Static_assert(sizeof(A9) == 16, "record A9 wrong sizeof");
_Static_assert(_Alignof(A9) == 8, "record A9 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A9_alignment) == 24, "record A9 wrong sizeof");
_Static_assert(_Alignof(struct A9_alignment) == 8, "record A9 wrong alignment");
_Static_assert(sizeof(struct A9_packed) == 16, "record A9 wrong sizeof");
_Static_assert(_Alignof(struct A9_packed) == 1, "record A9 wrong alignment");
_Static_assert(sizeof(struct A9_required_alignment) == 17, "record A9 wrong sizeof");
_Static_assert(_Alignof(struct A9_required_alignment) == 1, "record A9 wrong alignment");
_Static_assert(sizeof(struct A9_size) == 18, "record A9 wrong sizeof");
_Static_assert(_Alignof(struct A9_size) == 1, "record A9 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A9,i) == 8, "field A9.i wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A9,j) == 64, "field A9.j wrong bit offset");
#endif
_Static_assert(sizeof(A10) == 8, "record A10 wrong sizeof");
_Static_assert(_Alignof(A10) == 16, "record A10 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A10_alignment) == 32, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_alignment) == 16, "record A10 wrong alignment");
_Static_assert(sizeof(struct A10_packed) == 8, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_packed) == 1, "record A10 wrong alignment");
_Static_assert(sizeof(struct A10_required_alignment) == 9, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_required_alignment) == 1, "record A10 wrong alignment");
_Static_assert(sizeof(struct A10_size) == 10, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_size) == 1, "record A10 wrong alignment");
#endif
_Static_assert(sizeof(A11) == 16, "record A11 wrong sizeof");
_Static_assert(_Alignof(A11) == 16, "record A11 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A11_alignment) == 32, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_alignment) == 16, "record A11 wrong alignment");
_Static_assert(sizeof(struct A11_packed) == 16, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_packed) == 1, "record A11 wrong alignment");
_Static_assert(sizeof(struct A11_required_alignment) == 17, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_required_alignment) == 1, "record A11 wrong alignment");
_Static_assert(sizeof(struct A11_size) == 18, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_size) == 1, "record A11 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A11,i) == 8, "field A11.i wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A11,j) == 39, "field A11.j wrong bit offset");
#endif
_Static_assert(sizeof(A12) == 32, "record A12 wrong sizeof");
_Static_assert(_Alignof(A12) == 16, "record A12 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A12_alignment) == 48, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_alignment) == 16, "record A12 wrong alignment");
_Static_assert(sizeof(struct A12_packed) == 32, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_packed) == 1, "record A12 wrong alignment");
_Static_assert(sizeof(struct A12_required_alignment) == 33, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_required_alignment) == 1, "record A12 wrong alignment");
_Static_assert(sizeof(struct A12_size) == 34, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_size) == 1, "record A12 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A12,i) == 8, "field A12.i wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A12,j) == 128, "field A12.j wrong bit offset");
#endif
_Static_assert(sizeof(A13) == 32, "record A13 wrong sizeof");
_Static_assert(_Alignof(A13) == 16, "record A13 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A13_alignment) == 48, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_alignment) == 16, "record A13 wrong alignment");
_Static_assert(sizeof(struct A13_packed) == 32, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_packed) == 1, "record A13 wrong alignment");
_Static_assert(sizeof(struct A13_required_alignment) == 33, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_required_alignment) == 1, "record A13 wrong alignment");
_Static_assert(sizeof(struct A13_size) == 34, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_size) == 1, "record A13 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A13,i) == 8, "field A13.i wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A13,j) == 128, "field A13.j wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A13,d) == 136, "field A13.d wrong bit offset");
#endif
// MAPPING|THREE|aarch64-generic-linux-gnu:Gcc|aarch64-generic-linux-musl:Gcc|END
// repr targets Aarch64UnknownLinuxGnu|Some("aarch64-generic-linux-gnu") Aarch64UnknownLinuxMusl|Some("aarch64-generic-linux-musl") 
#elif defined(THREE)
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
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A,d) == 0, "field A.d wrong bit offset");
#endif
_Static_assert(sizeof(A_) == 8, "record A_ wrong sizeof");
_Static_assert(_Alignof(A_) == 4, "record A_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A__alignment) == 12, "record A_ wrong sizeof");
_Static_assert(_Alignof(struct A__alignment) == 4, "record A_ wrong alignment");
_Static_assert(sizeof(struct A__packed) == 8, "record A_ wrong sizeof");
_Static_assert(_Alignof(struct A__packed) == 1, "record A_ wrong alignment");
_Static_assert(sizeof(struct A__required_alignment) == 9, "record A_ wrong sizeof");
_Static_assert(_Alignof(struct A__required_alignment) == 1, "record A_ wrong alignment");
_Static_assert(sizeof(struct A__size) == 10, "record A_ wrong sizeof");
_Static_assert(_Alignof(struct A__size) == 1, "record A_ wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_,d) == 32, "field A_.d wrong bit offset");
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
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B,d) == 0, "field B.d wrong bit offset");
#endif
_Static_assert(sizeof(B_) == 16, "record B_ wrong sizeof");
_Static_assert(_Alignof(B_) == 8, "record B_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B__alignment) == 24, "record B_ wrong sizeof");
_Static_assert(_Alignof(struct B__alignment) == 8, "record B_ wrong alignment");
_Static_assert(sizeof(struct B__packed) == 16, "record B_ wrong sizeof");
_Static_assert(_Alignof(struct B__packed) == 1, "record B_ wrong alignment");
_Static_assert(sizeof(struct B__required_alignment) == 17, "record B_ wrong sizeof");
_Static_assert(_Alignof(struct B__required_alignment) == 1, "record B_ wrong alignment");
_Static_assert(sizeof(struct B__size) == 18, "record B_ wrong sizeof");
_Static_assert(_Alignof(struct B__size) == 1, "record B_ wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B_,d) == 64, "field B_.d wrong bit offset");
#endif
_Static_assert(sizeof(C) == 8, "record C wrong sizeof");
_Static_assert(_Alignof(C) == 8, "record C wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 16, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_alignment) == 8, "record C wrong alignment");
_Static_assert(sizeof(struct C_packed) == 8, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_packed) == 1, "record C wrong alignment");
_Static_assert(sizeof(struct C_required_alignment) == 9, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "record C wrong alignment");
_Static_assert(sizeof(struct C_size) == 10, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_size) == 1, "record C wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C,d) == 0, "field C.d wrong bit offset");
#endif
_Static_assert(sizeof(C_) == 16, "record C_ wrong sizeof");
_Static_assert(_Alignof(C_) == 8, "record C_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C__alignment) == 24, "record C_ wrong sizeof");
_Static_assert(_Alignof(struct C__alignment) == 8, "record C_ wrong alignment");
_Static_assert(sizeof(struct C__packed) == 16, "record C_ wrong sizeof");
_Static_assert(_Alignof(struct C__packed) == 1, "record C_ wrong alignment");
_Static_assert(sizeof(struct C__required_alignment) == 17, "record C_ wrong sizeof");
_Static_assert(_Alignof(struct C__required_alignment) == 1, "record C_ wrong alignment");
_Static_assert(sizeof(struct C__size) == 18, "record C_ wrong sizeof");
_Static_assert(_Alignof(struct C__size) == 1, "record C_ wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C_,d) == 64, "field C_.d wrong bit offset");
#endif
_Static_assert(sizeof(D) == 24, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 8, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 32, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 8, "record D wrong alignment");
_Static_assert(sizeof(struct D_packed) == 24, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 25, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_size) == 26, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_size) == 1, "record D wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D,d) == 64, "field D.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(D,e) == 128, "field D.e wrong bit offset");
#endif
_Static_assert(sizeof(F) == 32, "record F wrong sizeof");
_Static_assert(_Alignof(F) == 16, "record F wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 48, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_alignment) == 16, "record F wrong alignment");
_Static_assert(sizeof(struct F_packed) == 32, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_packed) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_required_alignment) == 33, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_size) == 34, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_size) == 1, "record F wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F,d) == 128, "field F.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(F,e) == 192, "field F.e wrong bit offset");
#endif
_Static_assert(sizeof(G) == 12, "record G wrong sizeof");
_Static_assert(_Alignof(G) == 2, "record G wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 14, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_alignment) == 2, "record G wrong alignment");
_Static_assert(sizeof(struct G_packed) == 12, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_packed) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_required_alignment) == 13, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_size) == 14, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_size) == 1, "record G wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(G,d) == 16, "field G.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(G,e) == 80, "field G.e wrong bit offset");
#endif
_Static_assert(sizeof(H) == 12, "record H wrong sizeof");
_Static_assert(_Alignof(H) == 2, "record H wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 14, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_alignment) == 2, "record H wrong alignment");
_Static_assert(sizeof(struct H_packed) == 12, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_packed) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_required_alignment) == 13, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_size) == 14, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_size) == 1, "record H wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(H,d) == 16, "field H.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(H,e) == 80, "field H.e wrong bit offset");
#endif
_Static_assert(sizeof(I) == 10, "record I wrong sizeof");
_Static_assert(_Alignof(I) == 1, "record I wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I_alignment) == 11, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_alignment) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_packed) == 10, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_packed) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_required_alignment) == 11, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_required_alignment) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_size) == 12, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_size) == 1, "record I wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(I,d) == 8, "field I.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(I,e) == 72, "field I.e wrong bit offset");
#endif
_Static_assert(sizeof(J) == 12, "record J wrong sizeof");
_Static_assert(_Alignof(J) == 2, "record J wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J_alignment) == 14, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_alignment) == 2, "record J wrong alignment");
_Static_assert(sizeof(struct J_packed) == 12, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_packed) == 1, "record J wrong alignment");
_Static_assert(sizeof(struct J_required_alignment) == 13, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_required_alignment) == 1, "record J wrong alignment");
_Static_assert(sizeof(struct J_size) == 14, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_size) == 1, "record J wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(J,d) == 16, "field J.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(J,e) == 80, "field J.e wrong bit offset");
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
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(K,d) == 8, "field K.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(K,e) == 16, "field K.e wrong bit offset");
#endif
_Static_assert(sizeof(L) == 32, "record L wrong sizeof");
_Static_assert(_Alignof(L) == 16, "record L wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct L_alignment) == 48, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_alignment) == 16, "record L wrong alignment");
_Static_assert(sizeof(struct L_packed) == 32, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_packed) == 1, "record L wrong alignment");
_Static_assert(sizeof(struct L_required_alignment) == 33, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_required_alignment) == 1, "record L wrong alignment");
_Static_assert(sizeof(struct L_size) == 34, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_size) == 1, "record L wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(L,d) == 128, "field L.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(L,e) == 136, "field L.e wrong bit offset");
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
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(M,d) == 16, "field M.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(M,e) == 24, "field M.e wrong bit offset");
#endif
_Static_assert(sizeof(N) == 4, "record N wrong sizeof");
_Static_assert(_Alignof(N) == 2, "record N wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct N_alignment) == 6, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_alignment) == 2, "record N wrong alignment");
_Static_assert(sizeof(struct N_packed) == 4, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_packed) == 1, "record N wrong alignment");
_Static_assert(sizeof(struct N_required_alignment) == 5, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_required_alignment) == 1, "record N wrong alignment");
_Static_assert(sizeof(struct N_size) == 6, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_size) == 1, "record N wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(N,d) == 16, "field N.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(N,e) == 24, "field N.e wrong bit offset");
#endif
_Static_assert(sizeof(O) == 3, "record O wrong sizeof");
_Static_assert(_Alignof(O) == 1, "record O wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct O_alignment) == 4, "record O wrong sizeof");
_Static_assert(_Alignof(struct O_alignment) == 1, "record O wrong alignment");
_Static_assert(sizeof(struct O_packed) == 3, "record O wrong sizeof");
_Static_assert(_Alignof(struct O_packed) == 1, "record O wrong alignment");
_Static_assert(sizeof(struct O_required_alignment) == 4, "record O wrong sizeof");
_Static_assert(_Alignof(struct O_required_alignment) == 1, "record O wrong alignment");
_Static_assert(sizeof(struct O_size) == 5, "record O wrong sizeof");
_Static_assert(_Alignof(struct O_size) == 1, "record O wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(O,d) == 8, "field O.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(O,e) == 16, "field O.e wrong bit offset");
#endif
_Static_assert(sizeof(P) == 4, "record P wrong sizeof");
_Static_assert(_Alignof(P) == 2, "record P wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct P_alignment) == 6, "record P wrong sizeof");
_Static_assert(_Alignof(struct P_alignment) == 2, "record P wrong alignment");
_Static_assert(sizeof(struct P_packed) == 4, "record P wrong sizeof");
_Static_assert(_Alignof(struct P_packed) == 1, "record P wrong alignment");
_Static_assert(sizeof(struct P_required_alignment) == 5, "record P wrong sizeof");
_Static_assert(_Alignof(struct P_required_alignment) == 1, "record P wrong alignment");
_Static_assert(sizeof(struct P_size) == 6, "record P wrong sizeof");
_Static_assert(_Alignof(struct P_size) == 1, "record P wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(P,d) == 8, "field P.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(P,e) == 16, "field P.e wrong bit offset");
#endif
_Static_assert(sizeof(Q) == 8, "record Q wrong sizeof");
_Static_assert(_Alignof(Q) == 8, "record Q wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Q_alignment) == 16, "record Q wrong sizeof");
_Static_assert(_Alignof(struct Q_alignment) == 8, "record Q wrong alignment");
_Static_assert(sizeof(struct Q_packed) == 8, "record Q wrong sizeof");
_Static_assert(_Alignof(struct Q_packed) == 1, "record Q wrong alignment");
_Static_assert(sizeof(struct Q_required_alignment) == 9, "record Q wrong sizeof");
_Static_assert(_Alignof(struct Q_required_alignment) == 1, "record Q wrong alignment");
_Static_assert(sizeof(struct Q_size) == 10, "record Q wrong sizeof");
_Static_assert(_Alignof(struct Q_size) == 1, "record Q wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(Q,x) == 8, "field Q.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(Q,d) == 9, "field Q.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(Q,e) == 16, "field Q.e wrong bit offset");
#endif
_Static_assert(sizeof(R) == 32, "record R wrong sizeof");
_Static_assert(_Alignof(R) == 16, "record R wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct R_alignment) == 48, "record R wrong sizeof");
_Static_assert(_Alignof(struct R_alignment) == 16, "record R wrong alignment");
_Static_assert(sizeof(struct R_packed) == 32, "record R wrong sizeof");
_Static_assert(_Alignof(struct R_packed) == 1, "record R wrong alignment");
_Static_assert(sizeof(struct R_required_alignment) == 33, "record R wrong sizeof");
_Static_assert(_Alignof(struct R_required_alignment) == 1, "record R wrong alignment");
_Static_assert(sizeof(struct R_size) == 34, "record R wrong sizeof");
_Static_assert(_Alignof(struct R_size) == 1, "record R wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(R,x) == 8, "field R.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(R,e) == 128, "field R.e wrong bit offset");
#endif
_Static_assert(sizeof(S) == 16, "record S wrong sizeof");
_Static_assert(_Alignof(S) == 8, "record S wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct S_alignment) == 24, "record S wrong sizeof");
_Static_assert(_Alignof(struct S_alignment) == 8, "record S wrong alignment");
_Static_assert(sizeof(struct S_packed) == 16, "record S wrong sizeof");
_Static_assert(_Alignof(struct S_packed) == 1, "record S wrong alignment");
_Static_assert(sizeof(struct S_required_alignment) == 17, "record S wrong sizeof");
_Static_assert(_Alignof(struct S_required_alignment) == 1, "record S wrong alignment");
_Static_assert(sizeof(struct S_size) == 18, "record S wrong sizeof");
_Static_assert(_Alignof(struct S_size) == 1, "record S wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(S,x) == 8, "field S.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(S,e) == 64, "field S.e wrong bit offset");
#endif
_Static_assert(sizeof(T) == 16, "record T wrong sizeof");
_Static_assert(_Alignof(T) == 8, "record T wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct T_alignment) == 24, "record T wrong sizeof");
_Static_assert(_Alignof(struct T_alignment) == 8, "record T wrong alignment");
_Static_assert(sizeof(struct T_packed) == 16, "record T wrong sizeof");
_Static_assert(_Alignof(struct T_packed) == 1, "record T wrong alignment");
_Static_assert(sizeof(struct T_required_alignment) == 17, "record T wrong sizeof");
_Static_assert(_Alignof(struct T_required_alignment) == 1, "record T wrong alignment");
_Static_assert(sizeof(struct T_size) == 18, "record T wrong sizeof");
_Static_assert(_Alignof(struct T_size) == 1, "record T wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(T,x) == 8, "field T.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(T,e) == 64, "field T.e wrong bit offset");
#endif
_Static_assert(sizeof(U) == 16, "record U wrong sizeof");
_Static_assert(_Alignof(U) == 8, "record U wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct U_alignment) == 24, "record U wrong sizeof");
_Static_assert(_Alignof(struct U_alignment) == 8, "record U wrong alignment");
_Static_assert(sizeof(struct U_packed) == 16, "record U wrong sizeof");
_Static_assert(_Alignof(struct U_packed) == 1, "record U wrong alignment");
_Static_assert(sizeof(struct U_required_alignment) == 17, "record U wrong sizeof");
_Static_assert(_Alignof(struct U_required_alignment) == 1, "record U wrong alignment");
_Static_assert(sizeof(struct U_size) == 18, "record U wrong sizeof");
_Static_assert(_Alignof(struct U_size) == 1, "record U wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(U,x) == 8, "field U.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(U,e) == 64, "field U.e wrong bit offset");
#endif
_Static_assert(sizeof(V) == 16, "record V wrong sizeof");
_Static_assert(_Alignof(V) == 8, "record V wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct V_alignment) == 24, "record V wrong sizeof");
_Static_assert(_Alignof(struct V_alignment) == 8, "record V wrong alignment");
_Static_assert(sizeof(struct V_packed) == 16, "record V wrong sizeof");
_Static_assert(_Alignof(struct V_packed) == 1, "record V wrong alignment");
_Static_assert(sizeof(struct V_required_alignment) == 17, "record V wrong sizeof");
_Static_assert(_Alignof(struct V_required_alignment) == 1, "record V wrong alignment");
_Static_assert(sizeof(struct V_size) == 18, "record V wrong sizeof");
_Static_assert(_Alignof(struct V_size) == 1, "record V wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(V,x) == 8, "field V.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(V,e) == 64, "field V.e wrong bit offset");
#endif
_Static_assert(sizeof(W) == 32, "record W wrong sizeof");
_Static_assert(_Alignof(W) == 16, "record W wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct W_alignment) == 48, "record W wrong sizeof");
_Static_assert(_Alignof(struct W_alignment) == 16, "record W wrong alignment");
_Static_assert(sizeof(struct W_packed) == 32, "record W wrong sizeof");
_Static_assert(_Alignof(struct W_packed) == 1, "record W wrong alignment");
_Static_assert(sizeof(struct W_required_alignment) == 33, "record W wrong sizeof");
_Static_assert(_Alignof(struct W_required_alignment) == 1, "record W wrong alignment");
_Static_assert(sizeof(struct W_size) == 34, "record W wrong sizeof");
_Static_assert(_Alignof(struct W_size) == 1, "record W wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(W,x) == 8, "field W.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(W,e) == 128, "field W.e wrong bit offset");
#endif
_Static_assert(sizeof(W_) == 32, "record W_ wrong sizeof");
_Static_assert(_Alignof(W_) == 16, "record W_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct W__alignment) == 48, "record W_ wrong sizeof");
_Static_assert(_Alignof(struct W__alignment) == 16, "record W_ wrong alignment");
_Static_assert(sizeof(struct W__packed) == 32, "record W_ wrong sizeof");
_Static_assert(_Alignof(struct W__packed) == 1, "record W_ wrong alignment");
_Static_assert(sizeof(struct W__required_alignment) == 33, "record W_ wrong sizeof");
_Static_assert(_Alignof(struct W__required_alignment) == 1, "record W_ wrong alignment");
_Static_assert(sizeof(struct W__size) == 34, "record W_ wrong sizeof");
_Static_assert(_Alignof(struct W__size) == 1, "record W_ wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(W_,e) == 128, "field W_.e wrong bit offset");
#endif
_Static_assert(sizeof(X) == 32, "record X wrong sizeof");
_Static_assert(_Alignof(X) == 16, "record X wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct X_alignment) == 48, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_alignment) == 16, "record X wrong alignment");
_Static_assert(sizeof(struct X_packed) == 32, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_packed) == 1, "record X wrong alignment");
_Static_assert(sizeof(struct X_required_alignment) == 33, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_required_alignment) == 1, "record X wrong alignment");
_Static_assert(sizeof(struct X_size) == 34, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_size) == 1, "record X wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(X,x) == 8, "field X.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(X,e) == 128, "field X.e wrong bit offset");
#endif
_Static_assert(sizeof(A2) == 4, "record A2 wrong sizeof");
_Static_assert(_Alignof(A2) == 4, "record A2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A2_alignment) == 8, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_alignment) == 4, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_packed) == 4, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_packed) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_required_alignment) == 5, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_required_alignment) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_size) == 6, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_size) == 1, "record A2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A2,d) == 0, "field A2.d wrong bit offset");
#endif
_Static_assert(sizeof(A_2) == 4, "record A_2 wrong sizeof");
_Static_assert(_Alignof(A_2) == 4, "record A_2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_2_alignment) == 8, "record A_2 wrong sizeof");
_Static_assert(_Alignof(struct A_2_alignment) == 4, "record A_2 wrong alignment");
_Static_assert(sizeof(struct A_2_packed) == 4, "record A_2 wrong sizeof");
_Static_assert(_Alignof(struct A_2_packed) == 1, "record A_2 wrong alignment");
_Static_assert(sizeof(struct A_2_required_alignment) == 5, "record A_2 wrong sizeof");
_Static_assert(_Alignof(struct A_2_required_alignment) == 1, "record A_2 wrong alignment");
_Static_assert(sizeof(struct A_2_size) == 6, "record A_2 wrong sizeof");
_Static_assert(_Alignof(struct A_2_size) == 1, "record A_2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_2,d) == 0, "field A_2.d wrong bit offset");
#endif
_Static_assert(sizeof(B2) == 8, "record B2 wrong sizeof");
_Static_assert(_Alignof(B2) == 8, "record B2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B2_alignment) == 16, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_alignment) == 8, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_packed) == 8, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_packed) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_required_alignment) == 9, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_required_alignment) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_size) == 10, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_size) == 1, "record B2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B2,d) == 0, "field B2.d wrong bit offset");
#endif
_Static_assert(sizeof(B_2) == 8, "record B_2 wrong sizeof");
_Static_assert(_Alignof(B_2) == 8, "record B_2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_2_alignment) == 16, "record B_2 wrong sizeof");
_Static_assert(_Alignof(struct B_2_alignment) == 8, "record B_2 wrong alignment");
_Static_assert(sizeof(struct B_2_packed) == 8, "record B_2 wrong sizeof");
_Static_assert(_Alignof(struct B_2_packed) == 1, "record B_2 wrong alignment");
_Static_assert(sizeof(struct B_2_required_alignment) == 9, "record B_2 wrong sizeof");
_Static_assert(_Alignof(struct B_2_required_alignment) == 1, "record B_2 wrong alignment");
_Static_assert(sizeof(struct B_2_size) == 10, "record B_2 wrong sizeof");
_Static_assert(_Alignof(struct B_2_size) == 1, "record B_2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B_2,d) == 0, "field B_2.d wrong bit offset");
#endif
_Static_assert(sizeof(C2) == 8, "record C2 wrong sizeof");
_Static_assert(_Alignof(C2) == 8, "record C2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C2_alignment) == 16, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_alignment) == 8, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_packed) == 8, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_packed) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_required_alignment) == 9, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_required_alignment) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_size) == 10, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_size) == 1, "record C2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C2,d) == 0, "field C2.d wrong bit offset");
#endif
_Static_assert(sizeof(C22) == 8, "record C22 wrong sizeof");
_Static_assert(_Alignof(C22) == 8, "record C22 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C22_alignment) == 16, "record C22 wrong sizeof");
_Static_assert(_Alignof(struct C22_alignment) == 8, "record C22 wrong alignment");
_Static_assert(sizeof(struct C22_packed) == 8, "record C22 wrong sizeof");
_Static_assert(_Alignof(struct C22_packed) == 1, "record C22 wrong alignment");
_Static_assert(sizeof(struct C22_required_alignment) == 9, "record C22 wrong sizeof");
_Static_assert(_Alignof(struct C22_required_alignment) == 1, "record C22 wrong alignment");
_Static_assert(sizeof(struct C22_size) == 10, "record C22 wrong sizeof");
_Static_assert(_Alignof(struct C22_size) == 1, "record C22 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C22,d) == 0, "field C22.d wrong bit offset");
#endif
_Static_assert(sizeof(D2) == 8, "record D2 wrong sizeof");
_Static_assert(_Alignof(D2) == 8, "record D2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D2_alignment) == 16, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_alignment) == 8, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_packed) == 8, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_packed) == 1, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_required_alignment) == 9, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_required_alignment) == 1, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_size) == 10, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_size) == 1, "record D2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D2,d) == 0, "field D2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(D2,e) == 0, "field D2.e wrong bit offset");
#endif
_Static_assert(sizeof(F2) == 16, "record F2 wrong sizeof");
_Static_assert(_Alignof(F2) == 16, "record F2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F2_alignment) == 32, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_alignment) == 16, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_packed) == 16, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_packed) == 1, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_required_alignment) == 17, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_required_alignment) == 1, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_size) == 18, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_size) == 1, "record F2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F2,d) == 0, "field F2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(F2,e) == 0, "field F2.e wrong bit offset");
#endif
_Static_assert(sizeof(G2) == 8, "record G2 wrong sizeof");
_Static_assert(_Alignof(G2) == 2, "record G2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G2_alignment) == 10, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_alignment) == 2, "record G2 wrong alignment");
_Static_assert(sizeof(struct G2_packed) == 8, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_packed) == 1, "record G2 wrong alignment");
_Static_assert(sizeof(struct G2_required_alignment) == 9, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_required_alignment) == 1, "record G2 wrong alignment");
_Static_assert(sizeof(struct G2_size) == 10, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_size) == 1, "record G2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(G2,d) == 0, "field G2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(G2,e) == 0, "field G2.e wrong bit offset");
#endif
_Static_assert(sizeof(H2) == 8, "record H2 wrong sizeof");
_Static_assert(_Alignof(H2) == 2, "record H2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H2_alignment) == 10, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_alignment) == 2, "record H2 wrong alignment");
_Static_assert(sizeof(struct H2_packed) == 8, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_packed) == 1, "record H2 wrong alignment");
_Static_assert(sizeof(struct H2_required_alignment) == 9, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_required_alignment) == 1, "record H2 wrong alignment");
_Static_assert(sizeof(struct H2_size) == 10, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_size) == 1, "record H2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(H2,d) == 0, "field H2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(H2,e) == 0, "field H2.e wrong bit offset");
#endif
_Static_assert(sizeof(I2) == 8, "record I2 wrong sizeof");
_Static_assert(_Alignof(I2) == 1, "record I2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I2_alignment) == 9, "record I2 wrong sizeof");
_Static_assert(_Alignof(struct I2_alignment) == 1, "record I2 wrong alignment");
_Static_assert(sizeof(struct I2_packed) == 8, "record I2 wrong sizeof");
_Static_assert(_Alignof(struct I2_packed) == 1, "record I2 wrong alignment");
_Static_assert(sizeof(struct I2_required_alignment) == 9, "record I2 wrong sizeof");
_Static_assert(_Alignof(struct I2_required_alignment) == 1, "record I2 wrong alignment");
_Static_assert(sizeof(struct I2_size) == 10, "record I2 wrong sizeof");
_Static_assert(_Alignof(struct I2_size) == 1, "record I2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(I2,d) == 0, "field I2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(I2,e) == 0, "field I2.e wrong bit offset");
#endif
_Static_assert(sizeof(J2) == 8, "record J2 wrong sizeof");
_Static_assert(_Alignof(J2) == 2, "record J2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J2_alignment) == 10, "record J2 wrong sizeof");
_Static_assert(_Alignof(struct J2_alignment) == 2, "record J2 wrong alignment");
_Static_assert(sizeof(struct J2_packed) == 8, "record J2 wrong sizeof");
_Static_assert(_Alignof(struct J2_packed) == 1, "record J2 wrong alignment");
_Static_assert(sizeof(struct J2_required_alignment) == 9, "record J2 wrong sizeof");
_Static_assert(_Alignof(struct J2_required_alignment) == 1, "record J2 wrong alignment");
_Static_assert(sizeof(struct J2_size) == 10, "record J2 wrong sizeof");
_Static_assert(_Alignof(struct J2_size) == 1, "record J2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(J2,d) == 0, "field J2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(J2,e) == 0, "field J2.e wrong bit offset");
#endif
_Static_assert(sizeof(K2) == 8, "record K2 wrong sizeof");
_Static_assert(_Alignof(K2) == 8, "record K2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct K2_alignment) == 16, "record K2 wrong sizeof");
_Static_assert(_Alignof(struct K2_alignment) == 8, "record K2 wrong alignment");
_Static_assert(sizeof(struct K2_packed) == 8, "record K2 wrong sizeof");
_Static_assert(_Alignof(struct K2_packed) == 1, "record K2 wrong alignment");
_Static_assert(sizeof(struct K2_required_alignment) == 9, "record K2 wrong sizeof");
_Static_assert(_Alignof(struct K2_required_alignment) == 1, "record K2 wrong alignment");
_Static_assert(sizeof(struct K2_size) == 10, "record K2 wrong sizeof");
_Static_assert(_Alignof(struct K2_size) == 1, "record K2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(K2,d) == 0, "field K2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(K2,e) == 0, "field K2.e wrong bit offset");
#endif
_Static_assert(sizeof(L2) == 16, "record L2 wrong sizeof");
_Static_assert(_Alignof(L2) == 16, "record L2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct L2_alignment) == 32, "record L2 wrong sizeof");
_Static_assert(_Alignof(struct L2_alignment) == 16, "record L2 wrong alignment");
_Static_assert(sizeof(struct L2_packed) == 16, "record L2 wrong sizeof");
_Static_assert(_Alignof(struct L2_packed) == 1, "record L2 wrong alignment");
_Static_assert(sizeof(struct L2_required_alignment) == 17, "record L2 wrong sizeof");
_Static_assert(_Alignof(struct L2_required_alignment) == 1, "record L2 wrong alignment");
_Static_assert(sizeof(struct L2_size) == 18, "record L2 wrong sizeof");
_Static_assert(_Alignof(struct L2_size) == 1, "record L2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(L2,d) == 0, "field L2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(L2,e) == 0, "field L2.e wrong bit offset");
#endif
_Static_assert(sizeof(M2) == 2, "record M2 wrong sizeof");
_Static_assert(_Alignof(M2) == 2, "record M2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct M2_alignment) == 4, "record M2 wrong sizeof");
_Static_assert(_Alignof(struct M2_alignment) == 2, "record M2 wrong alignment");
_Static_assert(sizeof(struct M2_packed) == 2, "record M2 wrong sizeof");
_Static_assert(_Alignof(struct M2_packed) == 1, "record M2 wrong alignment");
_Static_assert(sizeof(struct M2_required_alignment) == 3, "record M2 wrong sizeof");
_Static_assert(_Alignof(struct M2_required_alignment) == 1, "record M2 wrong alignment");
_Static_assert(sizeof(struct M2_size) == 4, "record M2 wrong sizeof");
_Static_assert(_Alignof(struct M2_size) == 1, "record M2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(M2,d) == 0, "field M2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(M2,e) == 0, "field M2.e wrong bit offset");
#endif
_Static_assert(sizeof(N2) == 2, "record N2 wrong sizeof");
_Static_assert(_Alignof(N2) == 2, "record N2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct N2_alignment) == 4, "record N2 wrong sizeof");
_Static_assert(_Alignof(struct N2_alignment) == 2, "record N2 wrong alignment");
_Static_assert(sizeof(struct N2_packed) == 2, "record N2 wrong sizeof");
_Static_assert(_Alignof(struct N2_packed) == 1, "record N2 wrong alignment");
_Static_assert(sizeof(struct N2_required_alignment) == 3, "record N2 wrong sizeof");
_Static_assert(_Alignof(struct N2_required_alignment) == 1, "record N2 wrong alignment");
_Static_assert(sizeof(struct N2_size) == 4, "record N2 wrong sizeof");
_Static_assert(_Alignof(struct N2_size) == 1, "record N2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(N2,d) == 0, "field N2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(N2,e) == 0, "field N2.e wrong bit offset");
#endif
_Static_assert(sizeof(O2) == 1, "record O2 wrong sizeof");
_Static_assert(_Alignof(O2) == 1, "record O2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct O2_alignment) == 2, "record O2 wrong sizeof");
_Static_assert(_Alignof(struct O2_alignment) == 1, "record O2 wrong alignment");
_Static_assert(sizeof(struct O2_packed) == 1, "record O2 wrong sizeof");
_Static_assert(_Alignof(struct O2_packed) == 1, "record O2 wrong alignment");
_Static_assert(sizeof(struct O2_required_alignment) == 2, "record O2 wrong sizeof");
_Static_assert(_Alignof(struct O2_required_alignment) == 1, "record O2 wrong alignment");
_Static_assert(sizeof(struct O2_size) == 3, "record O2 wrong sizeof");
_Static_assert(_Alignof(struct O2_size) == 1, "record O2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(O2,d) == 0, "field O2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(O2,e) == 0, "field O2.e wrong bit offset");
#endif
_Static_assert(sizeof(P2) == 2, "record P2 wrong sizeof");
_Static_assert(_Alignof(P2) == 2, "record P2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct P2_alignment) == 4, "record P2 wrong sizeof");
_Static_assert(_Alignof(struct P2_alignment) == 2, "record P2 wrong alignment");
_Static_assert(sizeof(struct P2_packed) == 2, "record P2 wrong sizeof");
_Static_assert(_Alignof(struct P2_packed) == 1, "record P2 wrong alignment");
_Static_assert(sizeof(struct P2_required_alignment) == 3, "record P2 wrong sizeof");
_Static_assert(_Alignof(struct P2_required_alignment) == 1, "record P2 wrong alignment");
_Static_assert(sizeof(struct P2_size) == 4, "record P2 wrong sizeof");
_Static_assert(_Alignof(struct P2_size) == 1, "record P2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(P2,d) == 0, "field P2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(P2,e) == 0, "field P2.e wrong bit offset");
#endif
_Static_assert(sizeof(Q2) == 8, "record Q2 wrong sizeof");
_Static_assert(_Alignof(Q2) == 8, "record Q2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Q2_alignment) == 16, "record Q2 wrong sizeof");
_Static_assert(_Alignof(struct Q2_alignment) == 8, "record Q2 wrong alignment");
_Static_assert(sizeof(struct Q2_packed) == 8, "record Q2 wrong sizeof");
_Static_assert(_Alignof(struct Q2_packed) == 1, "record Q2 wrong alignment");
_Static_assert(sizeof(struct Q2_required_alignment) == 9, "record Q2 wrong sizeof");
_Static_assert(_Alignof(struct Q2_required_alignment) == 1, "record Q2 wrong alignment");
_Static_assert(sizeof(struct Q2_size) == 10, "record Q2 wrong sizeof");
_Static_assert(_Alignof(struct Q2_size) == 1, "record Q2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(Q2,x) == 0, "field Q2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(Q2,d) == 0, "field Q2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(Q2,e) == 0, "field Q2.e wrong bit offset");
#endif
_Static_assert(sizeof(R2) == 16, "record R2 wrong sizeof");
_Static_assert(_Alignof(R2) == 16, "record R2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct R2_alignment) == 32, "record R2 wrong sizeof");
_Static_assert(_Alignof(struct R2_alignment) == 16, "record R2 wrong alignment");
_Static_assert(sizeof(struct R2_packed) == 16, "record R2 wrong sizeof");
_Static_assert(_Alignof(struct R2_packed) == 1, "record R2 wrong alignment");
_Static_assert(sizeof(struct R2_required_alignment) == 17, "record R2 wrong sizeof");
_Static_assert(_Alignof(struct R2_required_alignment) == 1, "record R2 wrong alignment");
_Static_assert(sizeof(struct R2_size) == 18, "record R2 wrong sizeof");
_Static_assert(_Alignof(struct R2_size) == 1, "record R2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(R2,x) == 0, "field R2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(R2,e) == 0, "field R2.e wrong bit offset");
#endif
_Static_assert(sizeof(S2) == 8, "record S2 wrong sizeof");
_Static_assert(_Alignof(S2) == 8, "record S2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct S2_alignment) == 16, "record S2 wrong sizeof");
_Static_assert(_Alignof(struct S2_alignment) == 8, "record S2 wrong alignment");
_Static_assert(sizeof(struct S2_packed) == 8, "record S2 wrong sizeof");
_Static_assert(_Alignof(struct S2_packed) == 1, "record S2 wrong alignment");
_Static_assert(sizeof(struct S2_required_alignment) == 9, "record S2 wrong sizeof");
_Static_assert(_Alignof(struct S2_required_alignment) == 1, "record S2 wrong alignment");
_Static_assert(sizeof(struct S2_size) == 10, "record S2 wrong sizeof");
_Static_assert(_Alignof(struct S2_size) == 1, "record S2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(S2,x) == 0, "field S2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(S2,e) == 0, "field S2.e wrong bit offset");
#endif
_Static_assert(sizeof(T2) == 8, "record T2 wrong sizeof");
_Static_assert(_Alignof(T2) == 8, "record T2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct T2_alignment) == 16, "record T2 wrong sizeof");
_Static_assert(_Alignof(struct T2_alignment) == 8, "record T2 wrong alignment");
_Static_assert(sizeof(struct T2_packed) == 8, "record T2 wrong sizeof");
_Static_assert(_Alignof(struct T2_packed) == 1, "record T2 wrong alignment");
_Static_assert(sizeof(struct T2_required_alignment) == 9, "record T2 wrong sizeof");
_Static_assert(_Alignof(struct T2_required_alignment) == 1, "record T2 wrong alignment");
_Static_assert(sizeof(struct T2_size) == 10, "record T2 wrong sizeof");
_Static_assert(_Alignof(struct T2_size) == 1, "record T2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(T2,x) == 0, "field T2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(T2,e) == 0, "field T2.e wrong bit offset");
#endif
_Static_assert(sizeof(U2) == 8, "record U2 wrong sizeof");
_Static_assert(_Alignof(U2) == 8, "record U2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct U2_alignment) == 16, "record U2 wrong sizeof");
_Static_assert(_Alignof(struct U2_alignment) == 8, "record U2 wrong alignment");
_Static_assert(sizeof(struct U2_packed) == 8, "record U2 wrong sizeof");
_Static_assert(_Alignof(struct U2_packed) == 1, "record U2 wrong alignment");
_Static_assert(sizeof(struct U2_required_alignment) == 9, "record U2 wrong sizeof");
_Static_assert(_Alignof(struct U2_required_alignment) == 1, "record U2 wrong alignment");
_Static_assert(sizeof(struct U2_size) == 10, "record U2 wrong sizeof");
_Static_assert(_Alignof(struct U2_size) == 1, "record U2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(U2,x) == 0, "field U2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(U2,e) == 0, "field U2.e wrong bit offset");
#endif
_Static_assert(sizeof(V2) == 8, "record V2 wrong sizeof");
_Static_assert(_Alignof(V2) == 8, "record V2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct V2_alignment) == 16, "record V2 wrong sizeof");
_Static_assert(_Alignof(struct V2_alignment) == 8, "record V2 wrong alignment");
_Static_assert(sizeof(struct V2_packed) == 8, "record V2 wrong sizeof");
_Static_assert(_Alignof(struct V2_packed) == 1, "record V2 wrong alignment");
_Static_assert(sizeof(struct V2_required_alignment) == 9, "record V2 wrong sizeof");
_Static_assert(_Alignof(struct V2_required_alignment) == 1, "record V2 wrong alignment");
_Static_assert(sizeof(struct V2_size) == 10, "record V2 wrong sizeof");
_Static_assert(_Alignof(struct V2_size) == 1, "record V2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(V2,x) == 0, "field V2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(V2,e) == 0, "field V2.e wrong bit offset");
#endif
_Static_assert(sizeof(W2) == 16, "record W2 wrong sizeof");
_Static_assert(_Alignof(W2) == 16, "record W2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct W2_alignment) == 32, "record W2 wrong sizeof");
_Static_assert(_Alignof(struct W2_alignment) == 16, "record W2 wrong alignment");
_Static_assert(sizeof(struct W2_packed) == 16, "record W2 wrong sizeof");
_Static_assert(_Alignof(struct W2_packed) == 1, "record W2 wrong alignment");
_Static_assert(sizeof(struct W2_required_alignment) == 17, "record W2 wrong sizeof");
_Static_assert(_Alignof(struct W2_required_alignment) == 1, "record W2 wrong alignment");
_Static_assert(sizeof(struct W2_size) == 18, "record W2 wrong sizeof");
_Static_assert(_Alignof(struct W2_size) == 1, "record W2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(W2,x) == 0, "field W2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(W2,e) == 0, "field W2.e wrong bit offset");
#endif
_Static_assert(sizeof(W_2) == 16, "record W_2 wrong sizeof");
_Static_assert(_Alignof(W_2) == 16, "record W_2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct W_2_alignment) == 32, "record W_2 wrong sizeof");
_Static_assert(_Alignof(struct W_2_alignment) == 16, "record W_2 wrong alignment");
_Static_assert(sizeof(struct W_2_packed) == 16, "record W_2 wrong sizeof");
_Static_assert(_Alignof(struct W_2_packed) == 1, "record W_2 wrong alignment");
_Static_assert(sizeof(struct W_2_required_alignment) == 17, "record W_2 wrong sizeof");
_Static_assert(_Alignof(struct W_2_required_alignment) == 1, "record W_2 wrong alignment");
_Static_assert(sizeof(struct W_2_size) == 18, "record W_2 wrong sizeof");
_Static_assert(_Alignof(struct W_2_size) == 1, "record W_2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(W_2,e) == 0, "field W_2.e wrong bit offset");
#endif
_Static_assert(sizeof(X2) == 16, "record X2 wrong sizeof");
_Static_assert(_Alignof(X2) == 16, "record X2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct X2_alignment) == 32, "record X2 wrong sizeof");
_Static_assert(_Alignof(struct X2_alignment) == 16, "record X2 wrong alignment");
_Static_assert(sizeof(struct X2_packed) == 16, "record X2 wrong sizeof");
_Static_assert(_Alignof(struct X2_packed) == 1, "record X2 wrong alignment");
_Static_assert(sizeof(struct X2_required_alignment) == 17, "record X2 wrong sizeof");
_Static_assert(_Alignof(struct X2_required_alignment) == 1, "record X2 wrong alignment");
_Static_assert(sizeof(struct X2_size) == 18, "record X2 wrong sizeof");
_Static_assert(_Alignof(struct X2_size) == 1, "record X2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(X2,x) == 0, "field X2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(X2,e) == 0, "field X2.e wrong bit offset");
#endif
_Static_assert(sizeof(Y) == 16, "record Y wrong sizeof");
_Static_assert(_Alignof(Y) == 8, "record Y wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Y_alignment) == 24, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_alignment) == 8, "record Y wrong alignment");
_Static_assert(sizeof(struct Y_packed) == 16, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_packed) == 1, "record Y wrong alignment");
_Static_assert(sizeof(struct Y_required_alignment) == 17, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_required_alignment) == 1, "record Y wrong alignment");
_Static_assert(sizeof(struct Y_size) == 18, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_size) == 1, "record Y wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(Y,d) == 64, "field Y.d wrong bit offset");
#endif
_Static_assert(sizeof(Y2) == 8, "record Y2 wrong sizeof");
_Static_assert(_Alignof(Y2) == 8, "record Y2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Y2_alignment) == 16, "record Y2 wrong sizeof");
_Static_assert(_Alignof(struct Y2_alignment) == 8, "record Y2 wrong alignment");
_Static_assert(sizeof(struct Y2_packed) == 8, "record Y2 wrong sizeof");
_Static_assert(_Alignof(struct Y2_packed) == 1, "record Y2 wrong alignment");
_Static_assert(sizeof(struct Y2_required_alignment) == 9, "record Y2 wrong sizeof");
_Static_assert(_Alignof(struct Y2_required_alignment) == 1, "record Y2 wrong alignment");
_Static_assert(sizeof(struct Y2_size) == 10, "record Y2 wrong sizeof");
_Static_assert(_Alignof(struct Y2_size) == 1, "record Y2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(Y2,d) == 0, "field Y2.d wrong bit offset");
#endif
_Static_assert(sizeof(A3) == 64, "record A3 wrong sizeof");
_Static_assert(_Alignof(A3) == 32, "record A3 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A3_alignment) == 96, "record A3 wrong sizeof");
_Static_assert(_Alignof(struct A3_alignment) == 32, "record A3 wrong alignment");
_Static_assert(sizeof(struct A3_packed) == 64, "record A3 wrong sizeof");
_Static_assert(_Alignof(struct A3_packed) == 1, "record A3 wrong alignment");
_Static_assert(sizeof(struct A3_required_alignment) == 65, "record A3 wrong sizeof");
_Static_assert(_Alignof(struct A3_required_alignment) == 1, "record A3 wrong alignment");
_Static_assert(sizeof(struct A3_size) == 66, "record A3 wrong sizeof");
_Static_assert(_Alignof(struct A3_size) == 1, "record A3 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A3,d) == 256, "field A3.d wrong bit offset");
#endif
_Static_assert(sizeof(A4) == 1, "record A4 wrong sizeof");
_Static_assert(_Alignof(A4) == 32, "record A4 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A4_alignment) == 64, "record A4 wrong sizeof");
_Static_assert(_Alignof(struct A4_alignment) == 32, "record A4 wrong alignment");
_Static_assert(sizeof(struct A4_packed) == 1, "record A4 wrong sizeof");
_Static_assert(_Alignof(struct A4_packed) == 1, "record A4 wrong alignment");
_Static_assert(sizeof(struct A4_required_alignment) == 2, "record A4 wrong sizeof");
_Static_assert(_Alignof(struct A4_required_alignment) == 1, "record A4 wrong alignment");
_Static_assert(sizeof(struct A4_size) == 3, "record A4 wrong sizeof");
_Static_assert(_Alignof(struct A4_size) == 1, "record A4 wrong alignment");
#endif
_Static_assert(sizeof(A5) == 64, "record A5 wrong sizeof");
_Static_assert(_Alignof(A5) == 32, "record A5 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A5_alignment) == 96, "record A5 wrong sizeof");
_Static_assert(_Alignof(struct A5_alignment) == 32, "record A5 wrong alignment");
_Static_assert(sizeof(struct A5_packed) == 64, "record A5 wrong sizeof");
_Static_assert(_Alignof(struct A5_packed) == 1, "record A5 wrong alignment");
_Static_assert(sizeof(struct A5_required_alignment) == 65, "record A5 wrong sizeof");
_Static_assert(_Alignof(struct A5_required_alignment) == 1, "record A5 wrong alignment");
_Static_assert(sizeof(struct A5_size) == 66, "record A5 wrong sizeof");
_Static_assert(_Alignof(struct A5_size) == 1, "record A5 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A5,d) == 256, "field A5.d wrong bit offset");
#endif
_Static_assert(sizeof(A7) == 32, "record A7 wrong sizeof");
_Static_assert(_Alignof(A7) == 32, "record A7 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A7_alignment) == 64, "record A7 wrong sizeof");
_Static_assert(_Alignof(struct A7_alignment) == 32, "record A7 wrong alignment");
_Static_assert(sizeof(struct A7_packed) == 32, "record A7 wrong sizeof");
_Static_assert(_Alignof(struct A7_packed) == 1, "record A7 wrong alignment");
_Static_assert(sizeof(struct A7_required_alignment) == 33, "record A7 wrong sizeof");
_Static_assert(_Alignof(struct A7_required_alignment) == 1, "record A7 wrong alignment");
_Static_assert(sizeof(struct A7_size) == 34, "record A7 wrong sizeof");
_Static_assert(_Alignof(struct A7_size) == 1, "record A7 wrong alignment");
#endif
_Static_assert(sizeof(A8) == 8, "record A8 wrong sizeof");
_Static_assert(_Alignof(A8) == 8, "record A8 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A8_alignment) == 16, "record A8 wrong sizeof");
_Static_assert(_Alignof(struct A8_alignment) == 8, "record A8 wrong alignment");
_Static_assert(sizeof(struct A8_packed) == 8, "record A8 wrong sizeof");
_Static_assert(_Alignof(struct A8_packed) == 1, "record A8 wrong alignment");
_Static_assert(sizeof(struct A8_required_alignment) == 9, "record A8 wrong sizeof");
_Static_assert(_Alignof(struct A8_required_alignment) == 1, "record A8 wrong alignment");
_Static_assert(sizeof(struct A8_size) == 10, "record A8 wrong sizeof");
_Static_assert(_Alignof(struct A8_size) == 1, "record A8 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A8,i) == 8, "field A8.i wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A8,j) == 39, "field A8.j wrong bit offset");
#endif
_Static_assert(sizeof(A9) == 16, "record A9 wrong sizeof");
_Static_assert(_Alignof(A9) == 8, "record A9 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A9_alignment) == 24, "record A9 wrong sizeof");
_Static_assert(_Alignof(struct A9_alignment) == 8, "record A9 wrong alignment");
_Static_assert(sizeof(struct A9_packed) == 16, "record A9 wrong sizeof");
_Static_assert(_Alignof(struct A9_packed) == 1, "record A9 wrong alignment");
_Static_assert(sizeof(struct A9_required_alignment) == 17, "record A9 wrong sizeof");
_Static_assert(_Alignof(struct A9_required_alignment) == 1, "record A9 wrong alignment");
_Static_assert(sizeof(struct A9_size) == 18, "record A9 wrong sizeof");
_Static_assert(_Alignof(struct A9_size) == 1, "record A9 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A9,i) == 8, "field A9.i wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A9,j) == 64, "field A9.j wrong bit offset");
#endif
_Static_assert(sizeof(A10) == 8, "record A10 wrong sizeof");
_Static_assert(_Alignof(A10) == 16, "record A10 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A10_alignment) == 32, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_alignment) == 16, "record A10 wrong alignment");
_Static_assert(sizeof(struct A10_packed) == 8, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_packed) == 1, "record A10 wrong alignment");
_Static_assert(sizeof(struct A10_required_alignment) == 9, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_required_alignment) == 1, "record A10 wrong alignment");
_Static_assert(sizeof(struct A10_size) == 10, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_size) == 1, "record A10 wrong alignment");
#endif
_Static_assert(sizeof(A11) == 32, "record A11 wrong sizeof");
_Static_assert(_Alignof(A11) == 16, "record A11 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A11_alignment) == 48, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_alignment) == 16, "record A11 wrong alignment");
_Static_assert(sizeof(struct A11_packed) == 32, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_packed) == 1, "record A11 wrong alignment");
_Static_assert(sizeof(struct A11_required_alignment) == 33, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_required_alignment) == 1, "record A11 wrong alignment");
_Static_assert(sizeof(struct A11_size) == 34, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_size) == 1, "record A11 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A11,i) == 8, "field A11.i wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A11,j) == 128, "field A11.j wrong bit offset");
#endif
_Static_assert(sizeof(A12) == 32, "record A12 wrong sizeof");
_Static_assert(_Alignof(A12) == 16, "record A12 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A12_alignment) == 48, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_alignment) == 16, "record A12 wrong alignment");
_Static_assert(sizeof(struct A12_packed) == 32, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_packed) == 1, "record A12 wrong alignment");
_Static_assert(sizeof(struct A12_required_alignment) == 33, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_required_alignment) == 1, "record A12 wrong alignment");
_Static_assert(sizeof(struct A12_size) == 34, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_size) == 1, "record A12 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A12,i) == 8, "field A12.i wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A12,j) == 128, "field A12.j wrong bit offset");
#endif
_Static_assert(sizeof(A13) == 32, "record A13 wrong sizeof");
_Static_assert(_Alignof(A13) == 16, "record A13 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A13_alignment) == 48, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_alignment) == 16, "record A13 wrong alignment");
_Static_assert(sizeof(struct A13_packed) == 32, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_packed) == 1, "record A13 wrong alignment");
_Static_assert(sizeof(struct A13_required_alignment) == 33, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_required_alignment) == 1, "record A13 wrong alignment");
_Static_assert(sizeof(struct A13_size) == 34, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_size) == 1, "record A13 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A13,i) == 8, "field A13.i wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A13,j) == 128, "field A13.j wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A13,d) == 136, "field A13.d wrong bit offset");
#endif
// MAPPING|FOUR|arm-baseline-other-eabi:Clang|arm-baseline-other-eabihf:Clang|arm-arm1136j_s-freebsd-gnu:Clang|arm-arm1136j_s-netbsd-eabihf:Clang|arm-baseline-other-eabi:Clang|arm-baseline-other-eabihf:Clang|arm-cortex_r4-other-eabi:Clang|arm-cortex_r4-other-eabihf:Clang|arm-cortex_r4-freebsd-gnu:Clang|arm-cortex_r4-netbsd-eabihf:Clang|thumb-arm710t-other-eabi:Clang|thumb-cortex_m0-other-eabi:Clang|thumb-cortex_m4-other-eabihf:Clang|thumb-cortex_m4-other-eabi:Clang|thumb-cortex_m3-other-eabi:Clang|thumb-baseline-other-eabi:Clang|thumb-cortex_m33-other-eabihf:Clang|thumb-cortex_m33-other-eabi:Clang|END
// repr targets Armebv7rUnknownNoneEabi|Some("arm-baseline-other-eabi") Armebv7rUnknownNoneEabihf|Some("arm-baseline-other-eabihf") ArmLinuxAndroideabi|None Armv6UnknownFreebsdGnueabihf|Some("arm-arm1136j_s-freebsd-gnu") Armv6UnknownNetbsdelfEabihf|Some("arm-arm1136j_s-netbsd-eabihf") Armv7aNoneEabi|Some("arm-baseline-other-eabi") Armv7aNoneEabihf|Some("arm-baseline-other-eabihf") Armv7NoneLinuxAndroid|None Armv7rUnknownNoneEabi|Some("arm-cortex_r4-other-eabi") Armv7rUnknownNoneEabihf|Some("arm-cortex_r4-other-eabihf") Armv7UnknownFreebsdGnueabihf|Some("arm-cortex_r4-freebsd-gnu") Armv7UnknownNetbsdelfEabihf|Some("arm-cortex_r4-netbsd-eabihf") Thumbv4tNoneEabi|Some("thumb-arm710t-other-eabi") Thumbv6mNoneEabi|Some("thumb-cortex_m0-other-eabi") Thumbv7emNoneEabihf|Some("thumb-cortex_m4-other-eabihf") Thumbv7emNoneEabi|Some("thumb-cortex_m4-other-eabi") Thumbv7mNoneEabi|Some("thumb-cortex_m3-other-eabi") Thumbv8mBaseNoneEabi|Some("thumb-baseline-other-eabi") Thumbv8mMainNoneEabihf|Some("thumb-cortex_m33-other-eabihf") Thumbv8mMainNoneEabi|Some("thumb-cortex_m33-other-eabi") 
#elif defined(FOUR)
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
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A,d) == 0, "field A.d wrong bit offset");
#endif
_Static_assert(sizeof(A_) == 8, "record A_ wrong sizeof");
_Static_assert(_Alignof(A_) == 4, "record A_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A__alignment) == 12, "record A_ wrong sizeof");
_Static_assert(_Alignof(struct A__alignment) == 4, "record A_ wrong alignment");
_Static_assert(sizeof(struct A__packed) == 8, "record A_ wrong sizeof");
_Static_assert(_Alignof(struct A__packed) == 1, "record A_ wrong alignment");
_Static_assert(sizeof(struct A__required_alignment) == 9, "record A_ wrong sizeof");
_Static_assert(_Alignof(struct A__required_alignment) == 1, "record A_ wrong alignment");
_Static_assert(sizeof(struct A__size) == 10, "record A_ wrong sizeof");
_Static_assert(_Alignof(struct A__size) == 1, "record A_ wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_,d) == 32, "field A_.d wrong bit offset");
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
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B,d) == 0, "field B.d wrong bit offset");
#endif
_Static_assert(sizeof(B_) == 16, "record B_ wrong sizeof");
_Static_assert(_Alignof(B_) == 8, "record B_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B__alignment) == 24, "record B_ wrong sizeof");
_Static_assert(_Alignof(struct B__alignment) == 8, "record B_ wrong alignment");
_Static_assert(sizeof(struct B__packed) == 16, "record B_ wrong sizeof");
_Static_assert(_Alignof(struct B__packed) == 1, "record B_ wrong alignment");
_Static_assert(sizeof(struct B__required_alignment) == 17, "record B_ wrong sizeof");
_Static_assert(_Alignof(struct B__required_alignment) == 1, "record B_ wrong alignment");
_Static_assert(sizeof(struct B__size) == 18, "record B_ wrong sizeof");
_Static_assert(_Alignof(struct B__size) == 1, "record B_ wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B_,d) == 64, "field B_.d wrong bit offset");
#endif
_Static_assert(sizeof(C) == 8, "record C wrong sizeof");
_Static_assert(_Alignof(C) == 8, "record C wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 16, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_alignment) == 8, "record C wrong alignment");
_Static_assert(sizeof(struct C_packed) == 8, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_packed) == 1, "record C wrong alignment");
_Static_assert(sizeof(struct C_required_alignment) == 9, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "record C wrong alignment");
_Static_assert(sizeof(struct C_size) == 10, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_size) == 1, "record C wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C,d) == 0, "field C.d wrong bit offset");
#endif
_Static_assert(sizeof(C_) == 16, "record C_ wrong sizeof");
_Static_assert(_Alignof(C_) == 8, "record C_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C__alignment) == 24, "record C_ wrong sizeof");
_Static_assert(_Alignof(struct C__alignment) == 8, "record C_ wrong alignment");
_Static_assert(sizeof(struct C__packed) == 16, "record C_ wrong sizeof");
_Static_assert(_Alignof(struct C__packed) == 1, "record C_ wrong alignment");
_Static_assert(sizeof(struct C__required_alignment) == 17, "record C_ wrong sizeof");
_Static_assert(_Alignof(struct C__required_alignment) == 1, "record C_ wrong alignment");
_Static_assert(sizeof(struct C__size) == 18, "record C_ wrong sizeof");
_Static_assert(_Alignof(struct C__size) == 1, "record C_ wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C_,d) == 64, "field C_.d wrong bit offset");
#endif
_Static_assert(sizeof(D) == 24, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 8, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 32, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 8, "record D wrong alignment");
_Static_assert(sizeof(struct D_packed) == 24, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 25, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_size) == 26, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_size) == 1, "record D wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D,d) == 64, "field D.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(D,e) == 128, "field D.e wrong bit offset");
#endif
_Static_assert(sizeof(F) == 32, "record F wrong sizeof");
_Static_assert(_Alignof(F) == 16, "record F wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 48, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_alignment) == 16, "record F wrong alignment");
_Static_assert(sizeof(struct F_packed) == 32, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_packed) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_required_alignment) == 33, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_size) == 34, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_size) == 1, "record F wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F,d) == 128, "field F.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(F,e) == 192, "field F.e wrong bit offset");
#endif
_Static_assert(sizeof(G) == 12, "record G wrong sizeof");
_Static_assert(_Alignof(G) == 2, "record G wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 14, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_alignment) == 2, "record G wrong alignment");
_Static_assert(sizeof(struct G_packed) == 12, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_packed) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_required_alignment) == 13, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_size) == 14, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_size) == 1, "record G wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(G,d) == 16, "field G.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(G,e) == 80, "field G.e wrong bit offset");
#endif
_Static_assert(sizeof(H) == 12, "record H wrong sizeof");
_Static_assert(_Alignof(H) == 2, "record H wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 14, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_alignment) == 2, "record H wrong alignment");
_Static_assert(sizeof(struct H_packed) == 12, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_packed) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_required_alignment) == 13, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_size) == 14, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_size) == 1, "record H wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(H,d) == 16, "field H.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(H,e) == 80, "field H.e wrong bit offset");
#endif
_Static_assert(sizeof(I) == 10, "record I wrong sizeof");
_Static_assert(_Alignof(I) == 1, "record I wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I_alignment) == 11, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_alignment) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_packed) == 10, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_packed) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_required_alignment) == 11, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_required_alignment) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_size) == 12, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_size) == 1, "record I wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(I,d) == 8, "field I.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(I,e) == 72, "field I.e wrong bit offset");
#endif
_Static_assert(sizeof(J) == 12, "record J wrong sizeof");
_Static_assert(_Alignof(J) == 2, "record J wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J_alignment) == 14, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_alignment) == 2, "record J wrong alignment");
_Static_assert(sizeof(struct J_packed) == 12, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_packed) == 1, "record J wrong alignment");
_Static_assert(sizeof(struct J_required_alignment) == 13, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_required_alignment) == 1, "record J wrong alignment");
_Static_assert(sizeof(struct J_size) == 14, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_size) == 1, "record J wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(J,d) == 16, "field J.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(J,e) == 80, "field J.e wrong bit offset");
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
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(K,d) == 8, "field K.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(K,e) == 16, "field K.e wrong bit offset");
#endif
_Static_assert(sizeof(L) == 32, "record L wrong sizeof");
_Static_assert(_Alignof(L) == 16, "record L wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct L_alignment) == 48, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_alignment) == 16, "record L wrong alignment");
_Static_assert(sizeof(struct L_packed) == 32, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_packed) == 1, "record L wrong alignment");
_Static_assert(sizeof(struct L_required_alignment) == 33, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_required_alignment) == 1, "record L wrong alignment");
_Static_assert(sizeof(struct L_size) == 34, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_size) == 1, "record L wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(L,d) == 128, "field L.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(L,e) == 136, "field L.e wrong bit offset");
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
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(M,d) == 16, "field M.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(M,e) == 24, "field M.e wrong bit offset");
#endif
_Static_assert(sizeof(N) == 4, "record N wrong sizeof");
_Static_assert(_Alignof(N) == 2, "record N wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct N_alignment) == 6, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_alignment) == 2, "record N wrong alignment");
_Static_assert(sizeof(struct N_packed) == 4, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_packed) == 1, "record N wrong alignment");
_Static_assert(sizeof(struct N_required_alignment) == 5, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_required_alignment) == 1, "record N wrong alignment");
_Static_assert(sizeof(struct N_size) == 6, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_size) == 1, "record N wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(N,d) == 8, "field N.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(N,e) == 16, "field N.e wrong bit offset");
#endif
_Static_assert(sizeof(O) == 3, "record O wrong sizeof");
_Static_assert(_Alignof(O) == 1, "record O wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct O_alignment) == 4, "record O wrong sizeof");
_Static_assert(_Alignof(struct O_alignment) == 1, "record O wrong alignment");
_Static_assert(sizeof(struct O_packed) == 3, "record O wrong sizeof");
_Static_assert(_Alignof(struct O_packed) == 1, "record O wrong alignment");
_Static_assert(sizeof(struct O_required_alignment) == 4, "record O wrong sizeof");
_Static_assert(_Alignof(struct O_required_alignment) == 1, "record O wrong alignment");
_Static_assert(sizeof(struct O_size) == 5, "record O wrong sizeof");
_Static_assert(_Alignof(struct O_size) == 1, "record O wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(O,d) == 8, "field O.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(O,e) == 16, "field O.e wrong bit offset");
#endif
_Static_assert(sizeof(P) == 4, "record P wrong sizeof");
_Static_assert(_Alignof(P) == 2, "record P wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct P_alignment) == 6, "record P wrong sizeof");
_Static_assert(_Alignof(struct P_alignment) == 2, "record P wrong alignment");
_Static_assert(sizeof(struct P_packed) == 4, "record P wrong sizeof");
_Static_assert(_Alignof(struct P_packed) == 1, "record P wrong alignment");
_Static_assert(sizeof(struct P_required_alignment) == 5, "record P wrong sizeof");
_Static_assert(_Alignof(struct P_required_alignment) == 1, "record P wrong alignment");
_Static_assert(sizeof(struct P_size) == 6, "record P wrong sizeof");
_Static_assert(_Alignof(struct P_size) == 1, "record P wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(P,d) == 8, "field P.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(P,e) == 16, "field P.e wrong bit offset");
#endif
_Static_assert(sizeof(Q) == 8, "record Q wrong sizeof");
_Static_assert(_Alignof(Q) == 8, "record Q wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Q_alignment) == 16, "record Q wrong sizeof");
_Static_assert(_Alignof(struct Q_alignment) == 8, "record Q wrong alignment");
_Static_assert(sizeof(struct Q_packed) == 8, "record Q wrong sizeof");
_Static_assert(_Alignof(struct Q_packed) == 1, "record Q wrong alignment");
_Static_assert(sizeof(struct Q_required_alignment) == 9, "record Q wrong sizeof");
_Static_assert(_Alignof(struct Q_required_alignment) == 1, "record Q wrong alignment");
_Static_assert(sizeof(struct Q_size) == 10, "record Q wrong sizeof");
_Static_assert(_Alignof(struct Q_size) == 1, "record Q wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(Q,x) == 8, "field Q.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(Q,d) == 9, "field Q.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(Q,e) == 16, "field Q.e wrong bit offset");
#endif
_Static_assert(sizeof(R) == 32, "record R wrong sizeof");
_Static_assert(_Alignof(R) == 16, "record R wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct R_alignment) == 48, "record R wrong sizeof");
_Static_assert(_Alignof(struct R_alignment) == 16, "record R wrong alignment");
_Static_assert(sizeof(struct R_packed) == 32, "record R wrong sizeof");
_Static_assert(_Alignof(struct R_packed) == 1, "record R wrong alignment");
_Static_assert(sizeof(struct R_required_alignment) == 33, "record R wrong sizeof");
_Static_assert(_Alignof(struct R_required_alignment) == 1, "record R wrong alignment");
_Static_assert(sizeof(struct R_size) == 34, "record R wrong sizeof");
_Static_assert(_Alignof(struct R_size) == 1, "record R wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(R,x) == 8, "field R.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(R,e) == 128, "field R.e wrong bit offset");
#endif
_Static_assert(sizeof(S) == 16, "record S wrong sizeof");
_Static_assert(_Alignof(S) == 8, "record S wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct S_alignment) == 24, "record S wrong sizeof");
_Static_assert(_Alignof(struct S_alignment) == 8, "record S wrong alignment");
_Static_assert(sizeof(struct S_packed) == 16, "record S wrong sizeof");
_Static_assert(_Alignof(struct S_packed) == 1, "record S wrong alignment");
_Static_assert(sizeof(struct S_required_alignment) == 17, "record S wrong sizeof");
_Static_assert(_Alignof(struct S_required_alignment) == 1, "record S wrong alignment");
_Static_assert(sizeof(struct S_size) == 18, "record S wrong sizeof");
_Static_assert(_Alignof(struct S_size) == 1, "record S wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(S,x) == 8, "field S.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(S,e) == 64, "field S.e wrong bit offset");
#endif
_Static_assert(sizeof(T) == 16, "record T wrong sizeof");
_Static_assert(_Alignof(T) == 8, "record T wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct T_alignment) == 24, "record T wrong sizeof");
_Static_assert(_Alignof(struct T_alignment) == 8, "record T wrong alignment");
_Static_assert(sizeof(struct T_packed) == 16, "record T wrong sizeof");
_Static_assert(_Alignof(struct T_packed) == 1, "record T wrong alignment");
_Static_assert(sizeof(struct T_required_alignment) == 17, "record T wrong sizeof");
_Static_assert(_Alignof(struct T_required_alignment) == 1, "record T wrong alignment");
_Static_assert(sizeof(struct T_size) == 18, "record T wrong sizeof");
_Static_assert(_Alignof(struct T_size) == 1, "record T wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(T,x) == 8, "field T.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(T,e) == 64, "field T.e wrong bit offset");
#endif
_Static_assert(sizeof(U) == 16, "record U wrong sizeof");
_Static_assert(_Alignof(U) == 8, "record U wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct U_alignment) == 24, "record U wrong sizeof");
_Static_assert(_Alignof(struct U_alignment) == 8, "record U wrong alignment");
_Static_assert(sizeof(struct U_packed) == 16, "record U wrong sizeof");
_Static_assert(_Alignof(struct U_packed) == 1, "record U wrong alignment");
_Static_assert(sizeof(struct U_required_alignment) == 17, "record U wrong sizeof");
_Static_assert(_Alignof(struct U_required_alignment) == 1, "record U wrong alignment");
_Static_assert(sizeof(struct U_size) == 18, "record U wrong sizeof");
_Static_assert(_Alignof(struct U_size) == 1, "record U wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(U,x) == 8, "field U.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(U,e) == 64, "field U.e wrong bit offset");
#endif
_Static_assert(sizeof(V) == 16, "record V wrong sizeof");
_Static_assert(_Alignof(V) == 8, "record V wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct V_alignment) == 24, "record V wrong sizeof");
_Static_assert(_Alignof(struct V_alignment) == 8, "record V wrong alignment");
_Static_assert(sizeof(struct V_packed) == 16, "record V wrong sizeof");
_Static_assert(_Alignof(struct V_packed) == 1, "record V wrong alignment");
_Static_assert(sizeof(struct V_required_alignment) == 17, "record V wrong sizeof");
_Static_assert(_Alignof(struct V_required_alignment) == 1, "record V wrong alignment");
_Static_assert(sizeof(struct V_size) == 18, "record V wrong sizeof");
_Static_assert(_Alignof(struct V_size) == 1, "record V wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(V,x) == 8, "field V.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(V,e) == 64, "field V.e wrong bit offset");
#endif
_Static_assert(sizeof(W) == 32, "record W wrong sizeof");
_Static_assert(_Alignof(W) == 16, "record W wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct W_alignment) == 48, "record W wrong sizeof");
_Static_assert(_Alignof(struct W_alignment) == 16, "record W wrong alignment");
_Static_assert(sizeof(struct W_packed) == 32, "record W wrong sizeof");
_Static_assert(_Alignof(struct W_packed) == 1, "record W wrong alignment");
_Static_assert(sizeof(struct W_required_alignment) == 33, "record W wrong sizeof");
_Static_assert(_Alignof(struct W_required_alignment) == 1, "record W wrong alignment");
_Static_assert(sizeof(struct W_size) == 34, "record W wrong sizeof");
_Static_assert(_Alignof(struct W_size) == 1, "record W wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(W,x) == 8, "field W.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(W,e) == 128, "field W.e wrong bit offset");
#endif
_Static_assert(sizeof(W_) == 32, "record W_ wrong sizeof");
_Static_assert(_Alignof(W_) == 16, "record W_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct W__alignment) == 48, "record W_ wrong sizeof");
_Static_assert(_Alignof(struct W__alignment) == 16, "record W_ wrong alignment");
_Static_assert(sizeof(struct W__packed) == 32, "record W_ wrong sizeof");
_Static_assert(_Alignof(struct W__packed) == 1, "record W_ wrong alignment");
_Static_assert(sizeof(struct W__required_alignment) == 33, "record W_ wrong sizeof");
_Static_assert(_Alignof(struct W__required_alignment) == 1, "record W_ wrong alignment");
_Static_assert(sizeof(struct W__size) == 34, "record W_ wrong sizeof");
_Static_assert(_Alignof(struct W__size) == 1, "record W_ wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(W_,e) == 128, "field W_.e wrong bit offset");
#endif
_Static_assert(sizeof(X) == 32, "record X wrong sizeof");
_Static_assert(_Alignof(X) == 16, "record X wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct X_alignment) == 48, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_alignment) == 16, "record X wrong alignment");
_Static_assert(sizeof(struct X_packed) == 32, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_packed) == 1, "record X wrong alignment");
_Static_assert(sizeof(struct X_required_alignment) == 33, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_required_alignment) == 1, "record X wrong alignment");
_Static_assert(sizeof(struct X_size) == 34, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_size) == 1, "record X wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(X,x) == 8, "field X.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(X,e) == 128, "field X.e wrong bit offset");
#endif
_Static_assert(sizeof(A2) == 4, "record A2 wrong sizeof");
_Static_assert(_Alignof(A2) == 4, "record A2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A2_alignment) == 8, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_alignment) == 4, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_packed) == 4, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_packed) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_required_alignment) == 5, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_required_alignment) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_size) == 6, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_size) == 1, "record A2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A2,d) == 0, "field A2.d wrong bit offset");
#endif
_Static_assert(sizeof(A_2) == 4, "record A_2 wrong sizeof");
_Static_assert(_Alignof(A_2) == 4, "record A_2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_2_alignment) == 8, "record A_2 wrong sizeof");
_Static_assert(_Alignof(struct A_2_alignment) == 4, "record A_2 wrong alignment");
_Static_assert(sizeof(struct A_2_packed) == 4, "record A_2 wrong sizeof");
_Static_assert(_Alignof(struct A_2_packed) == 1, "record A_2 wrong alignment");
_Static_assert(sizeof(struct A_2_required_alignment) == 5, "record A_2 wrong sizeof");
_Static_assert(_Alignof(struct A_2_required_alignment) == 1, "record A_2 wrong alignment");
_Static_assert(sizeof(struct A_2_size) == 6, "record A_2 wrong sizeof");
_Static_assert(_Alignof(struct A_2_size) == 1, "record A_2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_2,d) == 0, "field A_2.d wrong bit offset");
#endif
_Static_assert(sizeof(B2) == 8, "record B2 wrong sizeof");
_Static_assert(_Alignof(B2) == 8, "record B2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B2_alignment) == 16, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_alignment) == 8, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_packed) == 8, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_packed) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_required_alignment) == 9, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_required_alignment) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_size) == 10, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_size) == 1, "record B2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B2,d) == 0, "field B2.d wrong bit offset");
#endif
_Static_assert(sizeof(B_2) == 8, "record B_2 wrong sizeof");
_Static_assert(_Alignof(B_2) == 8, "record B_2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_2_alignment) == 16, "record B_2 wrong sizeof");
_Static_assert(_Alignof(struct B_2_alignment) == 8, "record B_2 wrong alignment");
_Static_assert(sizeof(struct B_2_packed) == 8, "record B_2 wrong sizeof");
_Static_assert(_Alignof(struct B_2_packed) == 1, "record B_2 wrong alignment");
_Static_assert(sizeof(struct B_2_required_alignment) == 9, "record B_2 wrong sizeof");
_Static_assert(_Alignof(struct B_2_required_alignment) == 1, "record B_2 wrong alignment");
_Static_assert(sizeof(struct B_2_size) == 10, "record B_2 wrong sizeof");
_Static_assert(_Alignof(struct B_2_size) == 1, "record B_2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B_2,d) == 0, "field B_2.d wrong bit offset");
#endif
_Static_assert(sizeof(C2) == 8, "record C2 wrong sizeof");
_Static_assert(_Alignof(C2) == 8, "record C2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C2_alignment) == 16, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_alignment) == 8, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_packed) == 8, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_packed) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_required_alignment) == 9, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_required_alignment) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_size) == 10, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_size) == 1, "record C2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C2,d) == 0, "field C2.d wrong bit offset");
#endif
_Static_assert(sizeof(C22) == 8, "record C22 wrong sizeof");
_Static_assert(_Alignof(C22) == 8, "record C22 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C22_alignment) == 16, "record C22 wrong sizeof");
_Static_assert(_Alignof(struct C22_alignment) == 8, "record C22 wrong alignment");
_Static_assert(sizeof(struct C22_packed) == 8, "record C22 wrong sizeof");
_Static_assert(_Alignof(struct C22_packed) == 1, "record C22 wrong alignment");
_Static_assert(sizeof(struct C22_required_alignment) == 9, "record C22 wrong sizeof");
_Static_assert(_Alignof(struct C22_required_alignment) == 1, "record C22 wrong alignment");
_Static_assert(sizeof(struct C22_size) == 10, "record C22 wrong sizeof");
_Static_assert(_Alignof(struct C22_size) == 1, "record C22 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C22,d) == 0, "field C22.d wrong bit offset");
#endif
_Static_assert(sizeof(D2) == 8, "record D2 wrong sizeof");
_Static_assert(_Alignof(D2) == 8, "record D2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D2_alignment) == 16, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_alignment) == 8, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_packed) == 8, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_packed) == 1, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_required_alignment) == 9, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_required_alignment) == 1, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_size) == 10, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_size) == 1, "record D2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D2,d) == 0, "field D2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(D2,e) == 0, "field D2.e wrong bit offset");
#endif
_Static_assert(sizeof(F2) == 16, "record F2 wrong sizeof");
_Static_assert(_Alignof(F2) == 16, "record F2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F2_alignment) == 32, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_alignment) == 16, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_packed) == 16, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_packed) == 1, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_required_alignment) == 17, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_required_alignment) == 1, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_size) == 18, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_size) == 1, "record F2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F2,d) == 0, "field F2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(F2,e) == 0, "field F2.e wrong bit offset");
#endif
_Static_assert(sizeof(G2) == 8, "record G2 wrong sizeof");
_Static_assert(_Alignof(G2) == 2, "record G2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G2_alignment) == 10, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_alignment) == 2, "record G2 wrong alignment");
_Static_assert(sizeof(struct G2_packed) == 8, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_packed) == 1, "record G2 wrong alignment");
_Static_assert(sizeof(struct G2_required_alignment) == 9, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_required_alignment) == 1, "record G2 wrong alignment");
_Static_assert(sizeof(struct G2_size) == 10, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_size) == 1, "record G2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(G2,d) == 0, "field G2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(G2,e) == 0, "field G2.e wrong bit offset");
#endif
_Static_assert(sizeof(H2) == 8, "record H2 wrong sizeof");
_Static_assert(_Alignof(H2) == 2, "record H2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H2_alignment) == 10, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_alignment) == 2, "record H2 wrong alignment");
_Static_assert(sizeof(struct H2_packed) == 8, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_packed) == 1, "record H2 wrong alignment");
_Static_assert(sizeof(struct H2_required_alignment) == 9, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_required_alignment) == 1, "record H2 wrong alignment");
_Static_assert(sizeof(struct H2_size) == 10, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_size) == 1, "record H2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(H2,d) == 0, "field H2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(H2,e) == 0, "field H2.e wrong bit offset");
#endif
_Static_assert(sizeof(I2) == 8, "record I2 wrong sizeof");
_Static_assert(_Alignof(I2) == 1, "record I2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I2_alignment) == 9, "record I2 wrong sizeof");
_Static_assert(_Alignof(struct I2_alignment) == 1, "record I2 wrong alignment");
_Static_assert(sizeof(struct I2_packed) == 8, "record I2 wrong sizeof");
_Static_assert(_Alignof(struct I2_packed) == 1, "record I2 wrong alignment");
_Static_assert(sizeof(struct I2_required_alignment) == 9, "record I2 wrong sizeof");
_Static_assert(_Alignof(struct I2_required_alignment) == 1, "record I2 wrong alignment");
_Static_assert(sizeof(struct I2_size) == 10, "record I2 wrong sizeof");
_Static_assert(_Alignof(struct I2_size) == 1, "record I2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(I2,d) == 0, "field I2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(I2,e) == 0, "field I2.e wrong bit offset");
#endif
_Static_assert(sizeof(J2) == 8, "record J2 wrong sizeof");
_Static_assert(_Alignof(J2) == 2, "record J2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J2_alignment) == 10, "record J2 wrong sizeof");
_Static_assert(_Alignof(struct J2_alignment) == 2, "record J2 wrong alignment");
_Static_assert(sizeof(struct J2_packed) == 8, "record J2 wrong sizeof");
_Static_assert(_Alignof(struct J2_packed) == 1, "record J2 wrong alignment");
_Static_assert(sizeof(struct J2_required_alignment) == 9, "record J2 wrong sizeof");
_Static_assert(_Alignof(struct J2_required_alignment) == 1, "record J2 wrong alignment");
_Static_assert(sizeof(struct J2_size) == 10, "record J2 wrong sizeof");
_Static_assert(_Alignof(struct J2_size) == 1, "record J2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(J2,d) == 0, "field J2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(J2,e) == 0, "field J2.e wrong bit offset");
#endif
_Static_assert(sizeof(K2) == 8, "record K2 wrong sizeof");
_Static_assert(_Alignof(K2) == 8, "record K2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct K2_alignment) == 16, "record K2 wrong sizeof");
_Static_assert(_Alignof(struct K2_alignment) == 8, "record K2 wrong alignment");
_Static_assert(sizeof(struct K2_packed) == 8, "record K2 wrong sizeof");
_Static_assert(_Alignof(struct K2_packed) == 1, "record K2 wrong alignment");
_Static_assert(sizeof(struct K2_required_alignment) == 9, "record K2 wrong sizeof");
_Static_assert(_Alignof(struct K2_required_alignment) == 1, "record K2 wrong alignment");
_Static_assert(sizeof(struct K2_size) == 10, "record K2 wrong sizeof");
_Static_assert(_Alignof(struct K2_size) == 1, "record K2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(K2,d) == 0, "field K2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(K2,e) == 0, "field K2.e wrong bit offset");
#endif
_Static_assert(sizeof(L2) == 16, "record L2 wrong sizeof");
_Static_assert(_Alignof(L2) == 16, "record L2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct L2_alignment) == 32, "record L2 wrong sizeof");
_Static_assert(_Alignof(struct L2_alignment) == 16, "record L2 wrong alignment");
_Static_assert(sizeof(struct L2_packed) == 16, "record L2 wrong sizeof");
_Static_assert(_Alignof(struct L2_packed) == 1, "record L2 wrong alignment");
_Static_assert(sizeof(struct L2_required_alignment) == 17, "record L2 wrong sizeof");
_Static_assert(_Alignof(struct L2_required_alignment) == 1, "record L2 wrong alignment");
_Static_assert(sizeof(struct L2_size) == 18, "record L2 wrong sizeof");
_Static_assert(_Alignof(struct L2_size) == 1, "record L2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(L2,d) == 0, "field L2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(L2,e) == 0, "field L2.e wrong bit offset");
#endif
_Static_assert(sizeof(M2) == 2, "record M2 wrong sizeof");
_Static_assert(_Alignof(M2) == 2, "record M2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct M2_alignment) == 4, "record M2 wrong sizeof");
_Static_assert(_Alignof(struct M2_alignment) == 2, "record M2 wrong alignment");
_Static_assert(sizeof(struct M2_packed) == 2, "record M2 wrong sizeof");
_Static_assert(_Alignof(struct M2_packed) == 1, "record M2 wrong alignment");
_Static_assert(sizeof(struct M2_required_alignment) == 3, "record M2 wrong sizeof");
_Static_assert(_Alignof(struct M2_required_alignment) == 1, "record M2 wrong alignment");
_Static_assert(sizeof(struct M2_size) == 4, "record M2 wrong sizeof");
_Static_assert(_Alignof(struct M2_size) == 1, "record M2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(M2,d) == 0, "field M2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(M2,e) == 0, "field M2.e wrong bit offset");
#endif
_Static_assert(sizeof(N2) == 2, "record N2 wrong sizeof");
_Static_assert(_Alignof(N2) == 2, "record N2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct N2_alignment) == 4, "record N2 wrong sizeof");
_Static_assert(_Alignof(struct N2_alignment) == 2, "record N2 wrong alignment");
_Static_assert(sizeof(struct N2_packed) == 2, "record N2 wrong sizeof");
_Static_assert(_Alignof(struct N2_packed) == 1, "record N2 wrong alignment");
_Static_assert(sizeof(struct N2_required_alignment) == 3, "record N2 wrong sizeof");
_Static_assert(_Alignof(struct N2_required_alignment) == 1, "record N2 wrong alignment");
_Static_assert(sizeof(struct N2_size) == 4, "record N2 wrong sizeof");
_Static_assert(_Alignof(struct N2_size) == 1, "record N2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(N2,d) == 0, "field N2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(N2,e) == 0, "field N2.e wrong bit offset");
#endif
_Static_assert(sizeof(O2) == 1, "record O2 wrong sizeof");
_Static_assert(_Alignof(O2) == 1, "record O2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct O2_alignment) == 2, "record O2 wrong sizeof");
_Static_assert(_Alignof(struct O2_alignment) == 1, "record O2 wrong alignment");
_Static_assert(sizeof(struct O2_packed) == 1, "record O2 wrong sizeof");
_Static_assert(_Alignof(struct O2_packed) == 1, "record O2 wrong alignment");
_Static_assert(sizeof(struct O2_required_alignment) == 2, "record O2 wrong sizeof");
_Static_assert(_Alignof(struct O2_required_alignment) == 1, "record O2 wrong alignment");
_Static_assert(sizeof(struct O2_size) == 3, "record O2 wrong sizeof");
_Static_assert(_Alignof(struct O2_size) == 1, "record O2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(O2,d) == 0, "field O2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(O2,e) == 0, "field O2.e wrong bit offset");
#endif
_Static_assert(sizeof(P2) == 2, "record P2 wrong sizeof");
_Static_assert(_Alignof(P2) == 2, "record P2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct P2_alignment) == 4, "record P2 wrong sizeof");
_Static_assert(_Alignof(struct P2_alignment) == 2, "record P2 wrong alignment");
_Static_assert(sizeof(struct P2_packed) == 2, "record P2 wrong sizeof");
_Static_assert(_Alignof(struct P2_packed) == 1, "record P2 wrong alignment");
_Static_assert(sizeof(struct P2_required_alignment) == 3, "record P2 wrong sizeof");
_Static_assert(_Alignof(struct P2_required_alignment) == 1, "record P2 wrong alignment");
_Static_assert(sizeof(struct P2_size) == 4, "record P2 wrong sizeof");
_Static_assert(_Alignof(struct P2_size) == 1, "record P2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(P2,d) == 0, "field P2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(P2,e) == 0, "field P2.e wrong bit offset");
#endif
_Static_assert(sizeof(Q2) == 8, "record Q2 wrong sizeof");
_Static_assert(_Alignof(Q2) == 8, "record Q2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Q2_alignment) == 16, "record Q2 wrong sizeof");
_Static_assert(_Alignof(struct Q2_alignment) == 8, "record Q2 wrong alignment");
_Static_assert(sizeof(struct Q2_packed) == 8, "record Q2 wrong sizeof");
_Static_assert(_Alignof(struct Q2_packed) == 1, "record Q2 wrong alignment");
_Static_assert(sizeof(struct Q2_required_alignment) == 9, "record Q2 wrong sizeof");
_Static_assert(_Alignof(struct Q2_required_alignment) == 1, "record Q2 wrong alignment");
_Static_assert(sizeof(struct Q2_size) == 10, "record Q2 wrong sizeof");
_Static_assert(_Alignof(struct Q2_size) == 1, "record Q2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(Q2,x) == 0, "field Q2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(Q2,d) == 0, "field Q2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(Q2,e) == 0, "field Q2.e wrong bit offset");
#endif
_Static_assert(sizeof(R2) == 16, "record R2 wrong sizeof");
_Static_assert(_Alignof(R2) == 16, "record R2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct R2_alignment) == 32, "record R2 wrong sizeof");
_Static_assert(_Alignof(struct R2_alignment) == 16, "record R2 wrong alignment");
_Static_assert(sizeof(struct R2_packed) == 16, "record R2 wrong sizeof");
_Static_assert(_Alignof(struct R2_packed) == 1, "record R2 wrong alignment");
_Static_assert(sizeof(struct R2_required_alignment) == 17, "record R2 wrong sizeof");
_Static_assert(_Alignof(struct R2_required_alignment) == 1, "record R2 wrong alignment");
_Static_assert(sizeof(struct R2_size) == 18, "record R2 wrong sizeof");
_Static_assert(_Alignof(struct R2_size) == 1, "record R2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(R2,x) == 0, "field R2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(R2,e) == 0, "field R2.e wrong bit offset");
#endif
_Static_assert(sizeof(S2) == 8, "record S2 wrong sizeof");
_Static_assert(_Alignof(S2) == 8, "record S2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct S2_alignment) == 16, "record S2 wrong sizeof");
_Static_assert(_Alignof(struct S2_alignment) == 8, "record S2 wrong alignment");
_Static_assert(sizeof(struct S2_packed) == 8, "record S2 wrong sizeof");
_Static_assert(_Alignof(struct S2_packed) == 1, "record S2 wrong alignment");
_Static_assert(sizeof(struct S2_required_alignment) == 9, "record S2 wrong sizeof");
_Static_assert(_Alignof(struct S2_required_alignment) == 1, "record S2 wrong alignment");
_Static_assert(sizeof(struct S2_size) == 10, "record S2 wrong sizeof");
_Static_assert(_Alignof(struct S2_size) == 1, "record S2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(S2,x) == 0, "field S2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(S2,e) == 0, "field S2.e wrong bit offset");
#endif
_Static_assert(sizeof(T2) == 8, "record T2 wrong sizeof");
_Static_assert(_Alignof(T2) == 8, "record T2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct T2_alignment) == 16, "record T2 wrong sizeof");
_Static_assert(_Alignof(struct T2_alignment) == 8, "record T2 wrong alignment");
_Static_assert(sizeof(struct T2_packed) == 8, "record T2 wrong sizeof");
_Static_assert(_Alignof(struct T2_packed) == 1, "record T2 wrong alignment");
_Static_assert(sizeof(struct T2_required_alignment) == 9, "record T2 wrong sizeof");
_Static_assert(_Alignof(struct T2_required_alignment) == 1, "record T2 wrong alignment");
_Static_assert(sizeof(struct T2_size) == 10, "record T2 wrong sizeof");
_Static_assert(_Alignof(struct T2_size) == 1, "record T2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(T2,x) == 0, "field T2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(T2,e) == 0, "field T2.e wrong bit offset");
#endif
_Static_assert(sizeof(U2) == 8, "record U2 wrong sizeof");
_Static_assert(_Alignof(U2) == 8, "record U2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct U2_alignment) == 16, "record U2 wrong sizeof");
_Static_assert(_Alignof(struct U2_alignment) == 8, "record U2 wrong alignment");
_Static_assert(sizeof(struct U2_packed) == 8, "record U2 wrong sizeof");
_Static_assert(_Alignof(struct U2_packed) == 1, "record U2 wrong alignment");
_Static_assert(sizeof(struct U2_required_alignment) == 9, "record U2 wrong sizeof");
_Static_assert(_Alignof(struct U2_required_alignment) == 1, "record U2 wrong alignment");
_Static_assert(sizeof(struct U2_size) == 10, "record U2 wrong sizeof");
_Static_assert(_Alignof(struct U2_size) == 1, "record U2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(U2,x) == 0, "field U2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(U2,e) == 0, "field U2.e wrong bit offset");
#endif
_Static_assert(sizeof(V2) == 8, "record V2 wrong sizeof");
_Static_assert(_Alignof(V2) == 8, "record V2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct V2_alignment) == 16, "record V2 wrong sizeof");
_Static_assert(_Alignof(struct V2_alignment) == 8, "record V2 wrong alignment");
_Static_assert(sizeof(struct V2_packed) == 8, "record V2 wrong sizeof");
_Static_assert(_Alignof(struct V2_packed) == 1, "record V2 wrong alignment");
_Static_assert(sizeof(struct V2_required_alignment) == 9, "record V2 wrong sizeof");
_Static_assert(_Alignof(struct V2_required_alignment) == 1, "record V2 wrong alignment");
_Static_assert(sizeof(struct V2_size) == 10, "record V2 wrong sizeof");
_Static_assert(_Alignof(struct V2_size) == 1, "record V2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(V2,x) == 0, "field V2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(V2,e) == 0, "field V2.e wrong bit offset");
#endif
_Static_assert(sizeof(W2) == 16, "record W2 wrong sizeof");
_Static_assert(_Alignof(W2) == 16, "record W2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct W2_alignment) == 32, "record W2 wrong sizeof");
_Static_assert(_Alignof(struct W2_alignment) == 16, "record W2 wrong alignment");
_Static_assert(sizeof(struct W2_packed) == 16, "record W2 wrong sizeof");
_Static_assert(_Alignof(struct W2_packed) == 1, "record W2 wrong alignment");
_Static_assert(sizeof(struct W2_required_alignment) == 17, "record W2 wrong sizeof");
_Static_assert(_Alignof(struct W2_required_alignment) == 1, "record W2 wrong alignment");
_Static_assert(sizeof(struct W2_size) == 18, "record W2 wrong sizeof");
_Static_assert(_Alignof(struct W2_size) == 1, "record W2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(W2,x) == 0, "field W2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(W2,e) == 0, "field W2.e wrong bit offset");
#endif
_Static_assert(sizeof(W_2) == 16, "record W_2 wrong sizeof");
_Static_assert(_Alignof(W_2) == 16, "record W_2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct W_2_alignment) == 32, "record W_2 wrong sizeof");
_Static_assert(_Alignof(struct W_2_alignment) == 16, "record W_2 wrong alignment");
_Static_assert(sizeof(struct W_2_packed) == 16, "record W_2 wrong sizeof");
_Static_assert(_Alignof(struct W_2_packed) == 1, "record W_2 wrong alignment");
_Static_assert(sizeof(struct W_2_required_alignment) == 17, "record W_2 wrong sizeof");
_Static_assert(_Alignof(struct W_2_required_alignment) == 1, "record W_2 wrong alignment");
_Static_assert(sizeof(struct W_2_size) == 18, "record W_2 wrong sizeof");
_Static_assert(_Alignof(struct W_2_size) == 1, "record W_2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(W_2,e) == 0, "field W_2.e wrong bit offset");
#endif
_Static_assert(sizeof(X2) == 16, "record X2 wrong sizeof");
_Static_assert(_Alignof(X2) == 16, "record X2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct X2_alignment) == 32, "record X2 wrong sizeof");
_Static_assert(_Alignof(struct X2_alignment) == 16, "record X2 wrong alignment");
_Static_assert(sizeof(struct X2_packed) == 16, "record X2 wrong sizeof");
_Static_assert(_Alignof(struct X2_packed) == 1, "record X2 wrong alignment");
_Static_assert(sizeof(struct X2_required_alignment) == 17, "record X2 wrong sizeof");
_Static_assert(_Alignof(struct X2_required_alignment) == 1, "record X2 wrong alignment");
_Static_assert(sizeof(struct X2_size) == 18, "record X2 wrong sizeof");
_Static_assert(_Alignof(struct X2_size) == 1, "record X2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(X2,x) == 0, "field X2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(X2,e) == 0, "field X2.e wrong bit offset");
#endif
_Static_assert(sizeof(Y) == 16, "record Y wrong sizeof");
_Static_assert(_Alignof(Y) == 8, "record Y wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Y_alignment) == 24, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_alignment) == 8, "record Y wrong alignment");
_Static_assert(sizeof(struct Y_packed) == 16, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_packed) == 1, "record Y wrong alignment");
_Static_assert(sizeof(struct Y_required_alignment) == 17, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_required_alignment) == 1, "record Y wrong alignment");
_Static_assert(sizeof(struct Y_size) == 18, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_size) == 1, "record Y wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(Y,d) == 64, "field Y.d wrong bit offset");
#endif
_Static_assert(sizeof(Y2) == 8, "record Y2 wrong sizeof");
_Static_assert(_Alignof(Y2) == 8, "record Y2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Y2_alignment) == 16, "record Y2 wrong sizeof");
_Static_assert(_Alignof(struct Y2_alignment) == 8, "record Y2 wrong alignment");
_Static_assert(sizeof(struct Y2_packed) == 8, "record Y2 wrong sizeof");
_Static_assert(_Alignof(struct Y2_packed) == 1, "record Y2 wrong alignment");
_Static_assert(sizeof(struct Y2_required_alignment) == 9, "record Y2 wrong sizeof");
_Static_assert(_Alignof(struct Y2_required_alignment) == 1, "record Y2 wrong alignment");
_Static_assert(sizeof(struct Y2_size) == 10, "record Y2 wrong sizeof");
_Static_assert(_Alignof(struct Y2_size) == 1, "record Y2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(Y2,d) == 0, "field Y2.d wrong bit offset");
#endif
_Static_assert(sizeof(A3) == 64, "record A3 wrong sizeof");
_Static_assert(_Alignof(A3) == 32, "record A3 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A3_alignment) == 96, "record A3 wrong sizeof");
_Static_assert(_Alignof(struct A3_alignment) == 32, "record A3 wrong alignment");
_Static_assert(sizeof(struct A3_packed) == 64, "record A3 wrong sizeof");
_Static_assert(_Alignof(struct A3_packed) == 1, "record A3 wrong alignment");
_Static_assert(sizeof(struct A3_required_alignment) == 65, "record A3 wrong sizeof");
_Static_assert(_Alignof(struct A3_required_alignment) == 1, "record A3 wrong alignment");
_Static_assert(sizeof(struct A3_size) == 66, "record A3 wrong sizeof");
_Static_assert(_Alignof(struct A3_size) == 1, "record A3 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A3,d) == 256, "field A3.d wrong bit offset");
#endif
_Static_assert(sizeof(A4) == 1, "record A4 wrong sizeof");
_Static_assert(_Alignof(A4) == 32, "record A4 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A4_alignment) == 64, "record A4 wrong sizeof");
_Static_assert(_Alignof(struct A4_alignment) == 32, "record A4 wrong alignment");
_Static_assert(sizeof(struct A4_packed) == 1, "record A4 wrong sizeof");
_Static_assert(_Alignof(struct A4_packed) == 1, "record A4 wrong alignment");
_Static_assert(sizeof(struct A4_required_alignment) == 2, "record A4 wrong sizeof");
_Static_assert(_Alignof(struct A4_required_alignment) == 1, "record A4 wrong alignment");
_Static_assert(sizeof(struct A4_size) == 3, "record A4 wrong sizeof");
_Static_assert(_Alignof(struct A4_size) == 1, "record A4 wrong alignment");
#endif
_Static_assert(sizeof(A5) == 64, "record A5 wrong sizeof");
_Static_assert(_Alignof(A5) == 32, "record A5 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A5_alignment) == 96, "record A5 wrong sizeof");
_Static_assert(_Alignof(struct A5_alignment) == 32, "record A5 wrong alignment");
_Static_assert(sizeof(struct A5_packed) == 64, "record A5 wrong sizeof");
_Static_assert(_Alignof(struct A5_packed) == 1, "record A5 wrong alignment");
_Static_assert(sizeof(struct A5_required_alignment) == 65, "record A5 wrong sizeof");
_Static_assert(_Alignof(struct A5_required_alignment) == 1, "record A5 wrong alignment");
_Static_assert(sizeof(struct A5_size) == 66, "record A5 wrong sizeof");
_Static_assert(_Alignof(struct A5_size) == 1, "record A5 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A5,d) == 256, "field A5.d wrong bit offset");
#endif
_Static_assert(sizeof(A7) == 32, "record A7 wrong sizeof");
_Static_assert(_Alignof(A7) == 32, "record A7 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A7_alignment) == 64, "record A7 wrong sizeof");
_Static_assert(_Alignof(struct A7_alignment) == 32, "record A7 wrong alignment");
_Static_assert(sizeof(struct A7_packed) == 32, "record A7 wrong sizeof");
_Static_assert(_Alignof(struct A7_packed) == 1, "record A7 wrong alignment");
_Static_assert(sizeof(struct A7_required_alignment) == 33, "record A7 wrong sizeof");
_Static_assert(_Alignof(struct A7_required_alignment) == 1, "record A7 wrong alignment");
_Static_assert(sizeof(struct A7_size) == 34, "record A7 wrong sizeof");
_Static_assert(_Alignof(struct A7_size) == 1, "record A7 wrong alignment");
#endif
_Static_assert(sizeof(A8) == 8, "record A8 wrong sizeof");
_Static_assert(_Alignof(A8) == 4, "record A8 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A8_alignment) == 12, "record A8 wrong sizeof");
_Static_assert(_Alignof(struct A8_alignment) == 4, "record A8 wrong alignment");
_Static_assert(sizeof(struct A8_packed) == 8, "record A8 wrong sizeof");
_Static_assert(_Alignof(struct A8_packed) == 1, "record A8 wrong alignment");
_Static_assert(sizeof(struct A8_required_alignment) == 9, "record A8 wrong sizeof");
_Static_assert(_Alignof(struct A8_required_alignment) == 1, "record A8 wrong alignment");
_Static_assert(sizeof(struct A8_size) == 10, "record A8 wrong sizeof");
_Static_assert(_Alignof(struct A8_size) == 1, "record A8 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A8,i) == 8, "field A8.i wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A8,j) == 39, "field A8.j wrong bit offset");
#endif
_Static_assert(sizeof(A9) == 12, "record A9 wrong sizeof");
_Static_assert(_Alignof(A9) == 4, "record A9 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A9_alignment) == 16, "record A9 wrong sizeof");
_Static_assert(_Alignof(struct A9_alignment) == 4, "record A9 wrong alignment");
_Static_assert(sizeof(struct A9_packed) == 12, "record A9 wrong sizeof");
_Static_assert(_Alignof(struct A9_packed) == 1, "record A9 wrong alignment");
_Static_assert(sizeof(struct A9_required_alignment) == 13, "record A9 wrong sizeof");
_Static_assert(_Alignof(struct A9_required_alignment) == 1, "record A9 wrong alignment");
_Static_assert(sizeof(struct A9_size) == 14, "record A9 wrong sizeof");
_Static_assert(_Alignof(struct A9_size) == 1, "record A9 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A9,i) == 8, "field A9.i wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A9,j) == 64, "field A9.j wrong bit offset");
#endif
_Static_assert(sizeof(A10) == 4, "record A10 wrong sizeof");
_Static_assert(_Alignof(A10) == 16, "record A10 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A10_alignment) == 32, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_alignment) == 16, "record A10 wrong alignment");
_Static_assert(sizeof(struct A10_packed) == 4, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_packed) == 1, "record A10 wrong alignment");
_Static_assert(sizeof(struct A10_required_alignment) == 5, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_required_alignment) == 1, "record A10 wrong alignment");
_Static_assert(sizeof(struct A10_size) == 6, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_size) == 1, "record A10 wrong alignment");
#endif
_Static_assert(sizeof(A11) == 32, "record A11 wrong sizeof");
_Static_assert(_Alignof(A11) == 16, "record A11 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A11_alignment) == 48, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_alignment) == 16, "record A11 wrong alignment");
_Static_assert(sizeof(struct A11_packed) == 32, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_packed) == 1, "record A11 wrong alignment");
_Static_assert(sizeof(struct A11_required_alignment) == 33, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_required_alignment) == 1, "record A11 wrong alignment");
_Static_assert(sizeof(struct A11_size) == 34, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_size) == 1, "record A11 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A11,i) == 8, "field A11.i wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A11,j) == 128, "field A11.j wrong bit offset");
#endif
_Static_assert(sizeof(A12) == 32, "record A12 wrong sizeof");
_Static_assert(_Alignof(A12) == 16, "record A12 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A12_alignment) == 48, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_alignment) == 16, "record A12 wrong alignment");
_Static_assert(sizeof(struct A12_packed) == 32, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_packed) == 1, "record A12 wrong alignment");
_Static_assert(sizeof(struct A12_required_alignment) == 33, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_required_alignment) == 1, "record A12 wrong alignment");
_Static_assert(sizeof(struct A12_size) == 34, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_size) == 1, "record A12 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A12,i) == 8, "field A12.i wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A12,j) == 128, "field A12.j wrong bit offset");
#endif
_Static_assert(sizeof(A13) == 32, "record A13 wrong sizeof");
_Static_assert(_Alignof(A13) == 16, "record A13 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A13_alignment) == 48, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_alignment) == 16, "record A13 wrong alignment");
_Static_assert(sizeof(struct A13_packed) == 32, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_packed) == 1, "record A13 wrong alignment");
_Static_assert(sizeof(struct A13_required_alignment) == 33, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_required_alignment) == 1, "record A13 wrong alignment");
_Static_assert(sizeof(struct A13_size) == 34, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_size) == 1, "record A13 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A13,i) == 8, "field A13.i wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A13,j) == 128, "field A13.j wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A13,d) == 136, "field A13.d wrong bit offset");
#endif
// MAPPING|FIVE|arm-baseline-linux-gnueabi:Gcc|arm-baseline-linux-gnueabihf:Gcc|arm-arm710t-linux-gnueabi:Gcc|arm-arm1020e-linux-gnueabi:Gcc|arm-cortex_r4-linux-gnueabi:Gcc|arm-cortex_r4-linux-gnueabihf:Gcc|END
// repr targets ArmUnknownLinuxGnueabi|Some("arm-baseline-linux-gnueabi") ArmUnknownLinuxGnueabihf|Some("arm-baseline-linux-gnueabihf") Armv4tUnknownLinuxGnueabi|Some("arm-arm710t-linux-gnueabi") Armv5teUnknownLinuxGnueabi|Some("arm-arm1020e-linux-gnueabi") Armv5teUnknownLinuxUclibcgnueabi|None Armv7UnknownLinuxGnueabi|Some("arm-cortex_r4-linux-gnueabi") Armv7UnknownLinuxGnueabihf|Some("arm-cortex_r4-linux-gnueabihf") 
#elif defined(FIVE)
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
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A,d) == 0, "field A.d wrong bit offset");
#endif
_Static_assert(sizeof(A_) == 8, "record A_ wrong sizeof");
_Static_assert(_Alignof(A_) == 4, "record A_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A__alignment) == 12, "record A_ wrong sizeof");
_Static_assert(_Alignof(struct A__alignment) == 4, "record A_ wrong alignment");
_Static_assert(sizeof(struct A__packed) == 8, "record A_ wrong sizeof");
_Static_assert(_Alignof(struct A__packed) == 1, "record A_ wrong alignment");
_Static_assert(sizeof(struct A__required_alignment) == 9, "record A_ wrong sizeof");
_Static_assert(_Alignof(struct A__required_alignment) == 1, "record A_ wrong alignment");
_Static_assert(sizeof(struct A__size) == 10, "record A_ wrong sizeof");
_Static_assert(_Alignof(struct A__size) == 1, "record A_ wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_,d) == 32, "field A_.d wrong bit offset");
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
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B,d) == 0, "field B.d wrong bit offset");
#endif
_Static_assert(sizeof(B_) == 16, "record B_ wrong sizeof");
_Static_assert(_Alignof(B_) == 8, "record B_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B__alignment) == 24, "record B_ wrong sizeof");
_Static_assert(_Alignof(struct B__alignment) == 8, "record B_ wrong alignment");
_Static_assert(sizeof(struct B__packed) == 16, "record B_ wrong sizeof");
_Static_assert(_Alignof(struct B__packed) == 1, "record B_ wrong alignment");
_Static_assert(sizeof(struct B__required_alignment) == 17, "record B_ wrong sizeof");
_Static_assert(_Alignof(struct B__required_alignment) == 1, "record B_ wrong alignment");
_Static_assert(sizeof(struct B__size) == 18, "record B_ wrong sizeof");
_Static_assert(_Alignof(struct B__size) == 1, "record B_ wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B_,d) == 64, "field B_.d wrong bit offset");
#endif
_Static_assert(sizeof(C) == 8, "record C wrong sizeof");
_Static_assert(_Alignof(C) == 8, "record C wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 16, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_alignment) == 8, "record C wrong alignment");
_Static_assert(sizeof(struct C_packed) == 8, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_packed) == 1, "record C wrong alignment");
_Static_assert(sizeof(struct C_required_alignment) == 9, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "record C wrong alignment");
_Static_assert(sizeof(struct C_size) == 10, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_size) == 1, "record C wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C,d) == 0, "field C.d wrong bit offset");
#endif
_Static_assert(sizeof(C_) == 16, "record C_ wrong sizeof");
_Static_assert(_Alignof(C_) == 8, "record C_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C__alignment) == 24, "record C_ wrong sizeof");
_Static_assert(_Alignof(struct C__alignment) == 8, "record C_ wrong alignment");
_Static_assert(sizeof(struct C__packed) == 16, "record C_ wrong sizeof");
_Static_assert(_Alignof(struct C__packed) == 1, "record C_ wrong alignment");
_Static_assert(sizeof(struct C__required_alignment) == 17, "record C_ wrong sizeof");
_Static_assert(_Alignof(struct C__required_alignment) == 1, "record C_ wrong alignment");
_Static_assert(sizeof(struct C__size) == 18, "record C_ wrong sizeof");
_Static_assert(_Alignof(struct C__size) == 1, "record C_ wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C_,d) == 64, "field C_.d wrong bit offset");
#endif
_Static_assert(sizeof(D) == 24, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 8, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 32, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 8, "record D wrong alignment");
_Static_assert(sizeof(struct D_packed) == 24, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 25, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_size) == 26, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_size) == 1, "record D wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D,d) == 64, "field D.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(D,e) == 128, "field D.e wrong bit offset");
#endif
_Static_assert(sizeof(F) == 32, "record F wrong sizeof");
_Static_assert(_Alignof(F) == 16, "record F wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 48, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_alignment) == 16, "record F wrong alignment");
_Static_assert(sizeof(struct F_packed) == 32, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_packed) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_required_alignment) == 33, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_size) == 34, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_size) == 1, "record F wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F,d) == 128, "field F.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(F,e) == 192, "field F.e wrong bit offset");
#endif
_Static_assert(sizeof(G) == 12, "record G wrong sizeof");
_Static_assert(_Alignof(G) == 2, "record G wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 14, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_alignment) == 2, "record G wrong alignment");
_Static_assert(sizeof(struct G_packed) == 12, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_packed) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_required_alignment) == 13, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_size) == 14, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_size) == 1, "record G wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(G,d) == 16, "field G.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(G,e) == 80, "field G.e wrong bit offset");
#endif
_Static_assert(sizeof(H) == 12, "record H wrong sizeof");
_Static_assert(_Alignof(H) == 2, "record H wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 14, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_alignment) == 2, "record H wrong alignment");
_Static_assert(sizeof(struct H_packed) == 12, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_packed) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_required_alignment) == 13, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_size) == 14, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_size) == 1, "record H wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(H,d) == 16, "field H.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(H,e) == 80, "field H.e wrong bit offset");
#endif
_Static_assert(sizeof(I) == 10, "record I wrong sizeof");
_Static_assert(_Alignof(I) == 1, "record I wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I_alignment) == 11, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_alignment) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_packed) == 10, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_packed) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_required_alignment) == 11, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_required_alignment) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_size) == 12, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_size) == 1, "record I wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(I,d) == 8, "field I.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(I,e) == 72, "field I.e wrong bit offset");
#endif
_Static_assert(sizeof(J) == 12, "record J wrong sizeof");
_Static_assert(_Alignof(J) == 2, "record J wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J_alignment) == 14, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_alignment) == 2, "record J wrong alignment");
_Static_assert(sizeof(struct J_packed) == 12, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_packed) == 1, "record J wrong alignment");
_Static_assert(sizeof(struct J_required_alignment) == 13, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_required_alignment) == 1, "record J wrong alignment");
_Static_assert(sizeof(struct J_size) == 14, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_size) == 1, "record J wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(J,d) == 16, "field J.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(J,e) == 80, "field J.e wrong bit offset");
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
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(K,d) == 8, "field K.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(K,e) == 16, "field K.e wrong bit offset");
#endif
_Static_assert(sizeof(L) == 32, "record L wrong sizeof");
_Static_assert(_Alignof(L) == 16, "record L wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct L_alignment) == 48, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_alignment) == 16, "record L wrong alignment");
_Static_assert(sizeof(struct L_packed) == 32, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_packed) == 1, "record L wrong alignment");
_Static_assert(sizeof(struct L_required_alignment) == 33, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_required_alignment) == 1, "record L wrong alignment");
_Static_assert(sizeof(struct L_size) == 34, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_size) == 1, "record L wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(L,d) == 128, "field L.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(L,e) == 136, "field L.e wrong bit offset");
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
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(M,d) == 16, "field M.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(M,e) == 24, "field M.e wrong bit offset");
#endif
_Static_assert(sizeof(N) == 4, "record N wrong sizeof");
_Static_assert(_Alignof(N) == 2, "record N wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct N_alignment) == 6, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_alignment) == 2, "record N wrong alignment");
_Static_assert(sizeof(struct N_packed) == 4, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_packed) == 1, "record N wrong alignment");
_Static_assert(sizeof(struct N_required_alignment) == 5, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_required_alignment) == 1, "record N wrong alignment");
_Static_assert(sizeof(struct N_size) == 6, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_size) == 1, "record N wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(N,d) == 16, "field N.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(N,e) == 24, "field N.e wrong bit offset");
#endif
_Static_assert(sizeof(O) == 3, "record O wrong sizeof");
_Static_assert(_Alignof(O) == 1, "record O wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct O_alignment) == 4, "record O wrong sizeof");
_Static_assert(_Alignof(struct O_alignment) == 1, "record O wrong alignment");
_Static_assert(sizeof(struct O_packed) == 3, "record O wrong sizeof");
_Static_assert(_Alignof(struct O_packed) == 1, "record O wrong alignment");
_Static_assert(sizeof(struct O_required_alignment) == 4, "record O wrong sizeof");
_Static_assert(_Alignof(struct O_required_alignment) == 1, "record O wrong alignment");
_Static_assert(sizeof(struct O_size) == 5, "record O wrong sizeof");
_Static_assert(_Alignof(struct O_size) == 1, "record O wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(O,d) == 8, "field O.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(O,e) == 16, "field O.e wrong bit offset");
#endif
_Static_assert(sizeof(P) == 4, "record P wrong sizeof");
_Static_assert(_Alignof(P) == 2, "record P wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct P_alignment) == 6, "record P wrong sizeof");
_Static_assert(_Alignof(struct P_alignment) == 2, "record P wrong alignment");
_Static_assert(sizeof(struct P_packed) == 4, "record P wrong sizeof");
_Static_assert(_Alignof(struct P_packed) == 1, "record P wrong alignment");
_Static_assert(sizeof(struct P_required_alignment) == 5, "record P wrong sizeof");
_Static_assert(_Alignof(struct P_required_alignment) == 1, "record P wrong alignment");
_Static_assert(sizeof(struct P_size) == 6, "record P wrong sizeof");
_Static_assert(_Alignof(struct P_size) == 1, "record P wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(P,d) == 8, "field P.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(P,e) == 16, "field P.e wrong bit offset");
#endif
_Static_assert(sizeof(Q) == 8, "record Q wrong sizeof");
_Static_assert(_Alignof(Q) == 8, "record Q wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Q_alignment) == 16, "record Q wrong sizeof");
_Static_assert(_Alignof(struct Q_alignment) == 8, "record Q wrong alignment");
_Static_assert(sizeof(struct Q_packed) == 8, "record Q wrong sizeof");
_Static_assert(_Alignof(struct Q_packed) == 1, "record Q wrong alignment");
_Static_assert(sizeof(struct Q_required_alignment) == 9, "record Q wrong sizeof");
_Static_assert(_Alignof(struct Q_required_alignment) == 1, "record Q wrong alignment");
_Static_assert(sizeof(struct Q_size) == 10, "record Q wrong sizeof");
_Static_assert(_Alignof(struct Q_size) == 1, "record Q wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(Q,x) == 8, "field Q.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(Q,d) == 9, "field Q.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(Q,e) == 16, "field Q.e wrong bit offset");
#endif
_Static_assert(sizeof(R) == 32, "record R wrong sizeof");
_Static_assert(_Alignof(R) == 16, "record R wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct R_alignment) == 48, "record R wrong sizeof");
_Static_assert(_Alignof(struct R_alignment) == 16, "record R wrong alignment");
_Static_assert(sizeof(struct R_packed) == 32, "record R wrong sizeof");
_Static_assert(_Alignof(struct R_packed) == 1, "record R wrong alignment");
_Static_assert(sizeof(struct R_required_alignment) == 33, "record R wrong sizeof");
_Static_assert(_Alignof(struct R_required_alignment) == 1, "record R wrong alignment");
_Static_assert(sizeof(struct R_size) == 34, "record R wrong sizeof");
_Static_assert(_Alignof(struct R_size) == 1, "record R wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(R,x) == 8, "field R.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(R,e) == 128, "field R.e wrong bit offset");
#endif
_Static_assert(sizeof(S) == 16, "record S wrong sizeof");
_Static_assert(_Alignof(S) == 8, "record S wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct S_alignment) == 24, "record S wrong sizeof");
_Static_assert(_Alignof(struct S_alignment) == 8, "record S wrong alignment");
_Static_assert(sizeof(struct S_packed) == 16, "record S wrong sizeof");
_Static_assert(_Alignof(struct S_packed) == 1, "record S wrong alignment");
_Static_assert(sizeof(struct S_required_alignment) == 17, "record S wrong sizeof");
_Static_assert(_Alignof(struct S_required_alignment) == 1, "record S wrong alignment");
_Static_assert(sizeof(struct S_size) == 18, "record S wrong sizeof");
_Static_assert(_Alignof(struct S_size) == 1, "record S wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(S,x) == 8, "field S.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(S,e) == 64, "field S.e wrong bit offset");
#endif
_Static_assert(sizeof(T) == 16, "record T wrong sizeof");
_Static_assert(_Alignof(T) == 8, "record T wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct T_alignment) == 24, "record T wrong sizeof");
_Static_assert(_Alignof(struct T_alignment) == 8, "record T wrong alignment");
_Static_assert(sizeof(struct T_packed) == 16, "record T wrong sizeof");
_Static_assert(_Alignof(struct T_packed) == 1, "record T wrong alignment");
_Static_assert(sizeof(struct T_required_alignment) == 17, "record T wrong sizeof");
_Static_assert(_Alignof(struct T_required_alignment) == 1, "record T wrong alignment");
_Static_assert(sizeof(struct T_size) == 18, "record T wrong sizeof");
_Static_assert(_Alignof(struct T_size) == 1, "record T wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(T,x) == 8, "field T.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(T,e) == 64, "field T.e wrong bit offset");
#endif
_Static_assert(sizeof(U) == 16, "record U wrong sizeof");
_Static_assert(_Alignof(U) == 8, "record U wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct U_alignment) == 24, "record U wrong sizeof");
_Static_assert(_Alignof(struct U_alignment) == 8, "record U wrong alignment");
_Static_assert(sizeof(struct U_packed) == 16, "record U wrong sizeof");
_Static_assert(_Alignof(struct U_packed) == 1, "record U wrong alignment");
_Static_assert(sizeof(struct U_required_alignment) == 17, "record U wrong sizeof");
_Static_assert(_Alignof(struct U_required_alignment) == 1, "record U wrong alignment");
_Static_assert(sizeof(struct U_size) == 18, "record U wrong sizeof");
_Static_assert(_Alignof(struct U_size) == 1, "record U wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(U,x) == 8, "field U.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(U,e) == 64, "field U.e wrong bit offset");
#endif
_Static_assert(sizeof(V) == 16, "record V wrong sizeof");
_Static_assert(_Alignof(V) == 8, "record V wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct V_alignment) == 24, "record V wrong sizeof");
_Static_assert(_Alignof(struct V_alignment) == 8, "record V wrong alignment");
_Static_assert(sizeof(struct V_packed) == 16, "record V wrong sizeof");
_Static_assert(_Alignof(struct V_packed) == 1, "record V wrong alignment");
_Static_assert(sizeof(struct V_required_alignment) == 17, "record V wrong sizeof");
_Static_assert(_Alignof(struct V_required_alignment) == 1, "record V wrong alignment");
_Static_assert(sizeof(struct V_size) == 18, "record V wrong sizeof");
_Static_assert(_Alignof(struct V_size) == 1, "record V wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(V,x) == 8, "field V.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(V,e) == 64, "field V.e wrong bit offset");
#endif
_Static_assert(sizeof(W) == 32, "record W wrong sizeof");
_Static_assert(_Alignof(W) == 16, "record W wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct W_alignment) == 48, "record W wrong sizeof");
_Static_assert(_Alignof(struct W_alignment) == 16, "record W wrong alignment");
_Static_assert(sizeof(struct W_packed) == 32, "record W wrong sizeof");
_Static_assert(_Alignof(struct W_packed) == 1, "record W wrong alignment");
_Static_assert(sizeof(struct W_required_alignment) == 33, "record W wrong sizeof");
_Static_assert(_Alignof(struct W_required_alignment) == 1, "record W wrong alignment");
_Static_assert(sizeof(struct W_size) == 34, "record W wrong sizeof");
_Static_assert(_Alignof(struct W_size) == 1, "record W wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(W,x) == 8, "field W.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(W,e) == 128, "field W.e wrong bit offset");
#endif
_Static_assert(sizeof(W_) == 32, "record W_ wrong sizeof");
_Static_assert(_Alignof(W_) == 16, "record W_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct W__alignment) == 48, "record W_ wrong sizeof");
_Static_assert(_Alignof(struct W__alignment) == 16, "record W_ wrong alignment");
_Static_assert(sizeof(struct W__packed) == 32, "record W_ wrong sizeof");
_Static_assert(_Alignof(struct W__packed) == 1, "record W_ wrong alignment");
_Static_assert(sizeof(struct W__required_alignment) == 33, "record W_ wrong sizeof");
_Static_assert(_Alignof(struct W__required_alignment) == 1, "record W_ wrong alignment");
_Static_assert(sizeof(struct W__size) == 34, "record W_ wrong sizeof");
_Static_assert(_Alignof(struct W__size) == 1, "record W_ wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(W_,e) == 128, "field W_.e wrong bit offset");
#endif
_Static_assert(sizeof(X) == 32, "record X wrong sizeof");
_Static_assert(_Alignof(X) == 16, "record X wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct X_alignment) == 48, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_alignment) == 16, "record X wrong alignment");
_Static_assert(sizeof(struct X_packed) == 32, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_packed) == 1, "record X wrong alignment");
_Static_assert(sizeof(struct X_required_alignment) == 33, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_required_alignment) == 1, "record X wrong alignment");
_Static_assert(sizeof(struct X_size) == 34, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_size) == 1, "record X wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(X,x) == 8, "field X.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(X,e) == 128, "field X.e wrong bit offset");
#endif
_Static_assert(sizeof(A2) == 4, "record A2 wrong sizeof");
_Static_assert(_Alignof(A2) == 4, "record A2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A2_alignment) == 8, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_alignment) == 4, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_packed) == 4, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_packed) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_required_alignment) == 5, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_required_alignment) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_size) == 6, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_size) == 1, "record A2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A2,d) == 0, "field A2.d wrong bit offset");
#endif
_Static_assert(sizeof(A_2) == 4, "record A_2 wrong sizeof");
_Static_assert(_Alignof(A_2) == 4, "record A_2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_2_alignment) == 8, "record A_2 wrong sizeof");
_Static_assert(_Alignof(struct A_2_alignment) == 4, "record A_2 wrong alignment");
_Static_assert(sizeof(struct A_2_packed) == 4, "record A_2 wrong sizeof");
_Static_assert(_Alignof(struct A_2_packed) == 1, "record A_2 wrong alignment");
_Static_assert(sizeof(struct A_2_required_alignment) == 5, "record A_2 wrong sizeof");
_Static_assert(_Alignof(struct A_2_required_alignment) == 1, "record A_2 wrong alignment");
_Static_assert(sizeof(struct A_2_size) == 6, "record A_2 wrong sizeof");
_Static_assert(_Alignof(struct A_2_size) == 1, "record A_2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_2,d) == 0, "field A_2.d wrong bit offset");
#endif
_Static_assert(sizeof(B2) == 8, "record B2 wrong sizeof");
_Static_assert(_Alignof(B2) == 8, "record B2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B2_alignment) == 16, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_alignment) == 8, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_packed) == 8, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_packed) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_required_alignment) == 9, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_required_alignment) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_size) == 10, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_size) == 1, "record B2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B2,d) == 0, "field B2.d wrong bit offset");
#endif
_Static_assert(sizeof(B_2) == 8, "record B_2 wrong sizeof");
_Static_assert(_Alignof(B_2) == 8, "record B_2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_2_alignment) == 16, "record B_2 wrong sizeof");
_Static_assert(_Alignof(struct B_2_alignment) == 8, "record B_2 wrong alignment");
_Static_assert(sizeof(struct B_2_packed) == 8, "record B_2 wrong sizeof");
_Static_assert(_Alignof(struct B_2_packed) == 1, "record B_2 wrong alignment");
_Static_assert(sizeof(struct B_2_required_alignment) == 9, "record B_2 wrong sizeof");
_Static_assert(_Alignof(struct B_2_required_alignment) == 1, "record B_2 wrong alignment");
_Static_assert(sizeof(struct B_2_size) == 10, "record B_2 wrong sizeof");
_Static_assert(_Alignof(struct B_2_size) == 1, "record B_2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B_2,d) == 0, "field B_2.d wrong bit offset");
#endif
_Static_assert(sizeof(C2) == 8, "record C2 wrong sizeof");
_Static_assert(_Alignof(C2) == 8, "record C2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C2_alignment) == 16, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_alignment) == 8, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_packed) == 8, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_packed) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_required_alignment) == 9, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_required_alignment) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_size) == 10, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_size) == 1, "record C2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C2,d) == 0, "field C2.d wrong bit offset");
#endif
_Static_assert(sizeof(C22) == 8, "record C22 wrong sizeof");
_Static_assert(_Alignof(C22) == 8, "record C22 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C22_alignment) == 16, "record C22 wrong sizeof");
_Static_assert(_Alignof(struct C22_alignment) == 8, "record C22 wrong alignment");
_Static_assert(sizeof(struct C22_packed) == 8, "record C22 wrong sizeof");
_Static_assert(_Alignof(struct C22_packed) == 1, "record C22 wrong alignment");
_Static_assert(sizeof(struct C22_required_alignment) == 9, "record C22 wrong sizeof");
_Static_assert(_Alignof(struct C22_required_alignment) == 1, "record C22 wrong alignment");
_Static_assert(sizeof(struct C22_size) == 10, "record C22 wrong sizeof");
_Static_assert(_Alignof(struct C22_size) == 1, "record C22 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C22,d) == 0, "field C22.d wrong bit offset");
#endif
_Static_assert(sizeof(D2) == 8, "record D2 wrong sizeof");
_Static_assert(_Alignof(D2) == 8, "record D2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D2_alignment) == 16, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_alignment) == 8, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_packed) == 8, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_packed) == 1, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_required_alignment) == 9, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_required_alignment) == 1, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_size) == 10, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_size) == 1, "record D2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D2,d) == 0, "field D2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(D2,e) == 0, "field D2.e wrong bit offset");
#endif
_Static_assert(sizeof(F2) == 16, "record F2 wrong sizeof");
_Static_assert(_Alignof(F2) == 16, "record F2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F2_alignment) == 32, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_alignment) == 16, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_packed) == 16, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_packed) == 1, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_required_alignment) == 17, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_required_alignment) == 1, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_size) == 18, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_size) == 1, "record F2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F2,d) == 0, "field F2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(F2,e) == 0, "field F2.e wrong bit offset");
#endif
_Static_assert(sizeof(G2) == 8, "record G2 wrong sizeof");
_Static_assert(_Alignof(G2) == 2, "record G2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G2_alignment) == 10, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_alignment) == 2, "record G2 wrong alignment");
_Static_assert(sizeof(struct G2_packed) == 8, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_packed) == 1, "record G2 wrong alignment");
_Static_assert(sizeof(struct G2_required_alignment) == 9, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_required_alignment) == 1, "record G2 wrong alignment");
_Static_assert(sizeof(struct G2_size) == 10, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_size) == 1, "record G2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(G2,d) == 0, "field G2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(G2,e) == 0, "field G2.e wrong bit offset");
#endif
_Static_assert(sizeof(H2) == 8, "record H2 wrong sizeof");
_Static_assert(_Alignof(H2) == 2, "record H2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H2_alignment) == 10, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_alignment) == 2, "record H2 wrong alignment");
_Static_assert(sizeof(struct H2_packed) == 8, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_packed) == 1, "record H2 wrong alignment");
_Static_assert(sizeof(struct H2_required_alignment) == 9, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_required_alignment) == 1, "record H2 wrong alignment");
_Static_assert(sizeof(struct H2_size) == 10, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_size) == 1, "record H2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(H2,d) == 0, "field H2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(H2,e) == 0, "field H2.e wrong bit offset");
#endif
_Static_assert(sizeof(I2) == 8, "record I2 wrong sizeof");
_Static_assert(_Alignof(I2) == 1, "record I2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I2_alignment) == 9, "record I2 wrong sizeof");
_Static_assert(_Alignof(struct I2_alignment) == 1, "record I2 wrong alignment");
_Static_assert(sizeof(struct I2_packed) == 8, "record I2 wrong sizeof");
_Static_assert(_Alignof(struct I2_packed) == 1, "record I2 wrong alignment");
_Static_assert(sizeof(struct I2_required_alignment) == 9, "record I2 wrong sizeof");
_Static_assert(_Alignof(struct I2_required_alignment) == 1, "record I2 wrong alignment");
_Static_assert(sizeof(struct I2_size) == 10, "record I2 wrong sizeof");
_Static_assert(_Alignof(struct I2_size) == 1, "record I2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(I2,d) == 0, "field I2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(I2,e) == 0, "field I2.e wrong bit offset");
#endif
_Static_assert(sizeof(J2) == 8, "record J2 wrong sizeof");
_Static_assert(_Alignof(J2) == 2, "record J2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J2_alignment) == 10, "record J2 wrong sizeof");
_Static_assert(_Alignof(struct J2_alignment) == 2, "record J2 wrong alignment");
_Static_assert(sizeof(struct J2_packed) == 8, "record J2 wrong sizeof");
_Static_assert(_Alignof(struct J2_packed) == 1, "record J2 wrong alignment");
_Static_assert(sizeof(struct J2_required_alignment) == 9, "record J2 wrong sizeof");
_Static_assert(_Alignof(struct J2_required_alignment) == 1, "record J2 wrong alignment");
_Static_assert(sizeof(struct J2_size) == 10, "record J2 wrong sizeof");
_Static_assert(_Alignof(struct J2_size) == 1, "record J2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(J2,d) == 0, "field J2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(J2,e) == 0, "field J2.e wrong bit offset");
#endif
_Static_assert(sizeof(K2) == 8, "record K2 wrong sizeof");
_Static_assert(_Alignof(K2) == 8, "record K2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct K2_alignment) == 16, "record K2 wrong sizeof");
_Static_assert(_Alignof(struct K2_alignment) == 8, "record K2 wrong alignment");
_Static_assert(sizeof(struct K2_packed) == 8, "record K2 wrong sizeof");
_Static_assert(_Alignof(struct K2_packed) == 1, "record K2 wrong alignment");
_Static_assert(sizeof(struct K2_required_alignment) == 9, "record K2 wrong sizeof");
_Static_assert(_Alignof(struct K2_required_alignment) == 1, "record K2 wrong alignment");
_Static_assert(sizeof(struct K2_size) == 10, "record K2 wrong sizeof");
_Static_assert(_Alignof(struct K2_size) == 1, "record K2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(K2,d) == 0, "field K2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(K2,e) == 0, "field K2.e wrong bit offset");
#endif
_Static_assert(sizeof(L2) == 16, "record L2 wrong sizeof");
_Static_assert(_Alignof(L2) == 16, "record L2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct L2_alignment) == 32, "record L2 wrong sizeof");
_Static_assert(_Alignof(struct L2_alignment) == 16, "record L2 wrong alignment");
_Static_assert(sizeof(struct L2_packed) == 16, "record L2 wrong sizeof");
_Static_assert(_Alignof(struct L2_packed) == 1, "record L2 wrong alignment");
_Static_assert(sizeof(struct L2_required_alignment) == 17, "record L2 wrong sizeof");
_Static_assert(_Alignof(struct L2_required_alignment) == 1, "record L2 wrong alignment");
_Static_assert(sizeof(struct L2_size) == 18, "record L2 wrong sizeof");
_Static_assert(_Alignof(struct L2_size) == 1, "record L2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(L2,d) == 0, "field L2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(L2,e) == 0, "field L2.e wrong bit offset");
#endif
_Static_assert(sizeof(M2) == 2, "record M2 wrong sizeof");
_Static_assert(_Alignof(M2) == 2, "record M2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct M2_alignment) == 4, "record M2 wrong sizeof");
_Static_assert(_Alignof(struct M2_alignment) == 2, "record M2 wrong alignment");
_Static_assert(sizeof(struct M2_packed) == 2, "record M2 wrong sizeof");
_Static_assert(_Alignof(struct M2_packed) == 1, "record M2 wrong alignment");
_Static_assert(sizeof(struct M2_required_alignment) == 3, "record M2 wrong sizeof");
_Static_assert(_Alignof(struct M2_required_alignment) == 1, "record M2 wrong alignment");
_Static_assert(sizeof(struct M2_size) == 4, "record M2 wrong sizeof");
_Static_assert(_Alignof(struct M2_size) == 1, "record M2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(M2,d) == 0, "field M2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(M2,e) == 0, "field M2.e wrong bit offset");
#endif
_Static_assert(sizeof(N2) == 2, "record N2 wrong sizeof");
_Static_assert(_Alignof(N2) == 2, "record N2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct N2_alignment) == 4, "record N2 wrong sizeof");
_Static_assert(_Alignof(struct N2_alignment) == 2, "record N2 wrong alignment");
_Static_assert(sizeof(struct N2_packed) == 2, "record N2 wrong sizeof");
_Static_assert(_Alignof(struct N2_packed) == 1, "record N2 wrong alignment");
_Static_assert(sizeof(struct N2_required_alignment) == 3, "record N2 wrong sizeof");
_Static_assert(_Alignof(struct N2_required_alignment) == 1, "record N2 wrong alignment");
_Static_assert(sizeof(struct N2_size) == 4, "record N2 wrong sizeof");
_Static_assert(_Alignof(struct N2_size) == 1, "record N2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(N2,d) == 0, "field N2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(N2,e) == 0, "field N2.e wrong bit offset");
#endif
_Static_assert(sizeof(O2) == 1, "record O2 wrong sizeof");
_Static_assert(_Alignof(O2) == 1, "record O2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct O2_alignment) == 2, "record O2 wrong sizeof");
_Static_assert(_Alignof(struct O2_alignment) == 1, "record O2 wrong alignment");
_Static_assert(sizeof(struct O2_packed) == 1, "record O2 wrong sizeof");
_Static_assert(_Alignof(struct O2_packed) == 1, "record O2 wrong alignment");
_Static_assert(sizeof(struct O2_required_alignment) == 2, "record O2 wrong sizeof");
_Static_assert(_Alignof(struct O2_required_alignment) == 1, "record O2 wrong alignment");
_Static_assert(sizeof(struct O2_size) == 3, "record O2 wrong sizeof");
_Static_assert(_Alignof(struct O2_size) == 1, "record O2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(O2,d) == 0, "field O2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(O2,e) == 0, "field O2.e wrong bit offset");
#endif
_Static_assert(sizeof(P2) == 2, "record P2 wrong sizeof");
_Static_assert(_Alignof(P2) == 2, "record P2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct P2_alignment) == 4, "record P2 wrong sizeof");
_Static_assert(_Alignof(struct P2_alignment) == 2, "record P2 wrong alignment");
_Static_assert(sizeof(struct P2_packed) == 2, "record P2 wrong sizeof");
_Static_assert(_Alignof(struct P2_packed) == 1, "record P2 wrong alignment");
_Static_assert(sizeof(struct P2_required_alignment) == 3, "record P2 wrong sizeof");
_Static_assert(_Alignof(struct P2_required_alignment) == 1, "record P2 wrong alignment");
_Static_assert(sizeof(struct P2_size) == 4, "record P2 wrong sizeof");
_Static_assert(_Alignof(struct P2_size) == 1, "record P2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(P2,d) == 0, "field P2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(P2,e) == 0, "field P2.e wrong bit offset");
#endif
_Static_assert(sizeof(Q2) == 8, "record Q2 wrong sizeof");
_Static_assert(_Alignof(Q2) == 8, "record Q2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Q2_alignment) == 16, "record Q2 wrong sizeof");
_Static_assert(_Alignof(struct Q2_alignment) == 8, "record Q2 wrong alignment");
_Static_assert(sizeof(struct Q2_packed) == 8, "record Q2 wrong sizeof");
_Static_assert(_Alignof(struct Q2_packed) == 1, "record Q2 wrong alignment");
_Static_assert(sizeof(struct Q2_required_alignment) == 9, "record Q2 wrong sizeof");
_Static_assert(_Alignof(struct Q2_required_alignment) == 1, "record Q2 wrong alignment");
_Static_assert(sizeof(struct Q2_size) == 10, "record Q2 wrong sizeof");
_Static_assert(_Alignof(struct Q2_size) == 1, "record Q2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(Q2,x) == 0, "field Q2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(Q2,d) == 0, "field Q2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(Q2,e) == 0, "field Q2.e wrong bit offset");
#endif
_Static_assert(sizeof(R2) == 16, "record R2 wrong sizeof");
_Static_assert(_Alignof(R2) == 16, "record R2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct R2_alignment) == 32, "record R2 wrong sizeof");
_Static_assert(_Alignof(struct R2_alignment) == 16, "record R2 wrong alignment");
_Static_assert(sizeof(struct R2_packed) == 16, "record R2 wrong sizeof");
_Static_assert(_Alignof(struct R2_packed) == 1, "record R2 wrong alignment");
_Static_assert(sizeof(struct R2_required_alignment) == 17, "record R2 wrong sizeof");
_Static_assert(_Alignof(struct R2_required_alignment) == 1, "record R2 wrong alignment");
_Static_assert(sizeof(struct R2_size) == 18, "record R2 wrong sizeof");
_Static_assert(_Alignof(struct R2_size) == 1, "record R2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(R2,x) == 0, "field R2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(R2,e) == 0, "field R2.e wrong bit offset");
#endif
_Static_assert(sizeof(S2) == 8, "record S2 wrong sizeof");
_Static_assert(_Alignof(S2) == 8, "record S2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct S2_alignment) == 16, "record S2 wrong sizeof");
_Static_assert(_Alignof(struct S2_alignment) == 8, "record S2 wrong alignment");
_Static_assert(sizeof(struct S2_packed) == 8, "record S2 wrong sizeof");
_Static_assert(_Alignof(struct S2_packed) == 1, "record S2 wrong alignment");
_Static_assert(sizeof(struct S2_required_alignment) == 9, "record S2 wrong sizeof");
_Static_assert(_Alignof(struct S2_required_alignment) == 1, "record S2 wrong alignment");
_Static_assert(sizeof(struct S2_size) == 10, "record S2 wrong sizeof");
_Static_assert(_Alignof(struct S2_size) == 1, "record S2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(S2,x) == 0, "field S2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(S2,e) == 0, "field S2.e wrong bit offset");
#endif
_Static_assert(sizeof(T2) == 8, "record T2 wrong sizeof");
_Static_assert(_Alignof(T2) == 8, "record T2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct T2_alignment) == 16, "record T2 wrong sizeof");
_Static_assert(_Alignof(struct T2_alignment) == 8, "record T2 wrong alignment");
_Static_assert(sizeof(struct T2_packed) == 8, "record T2 wrong sizeof");
_Static_assert(_Alignof(struct T2_packed) == 1, "record T2 wrong alignment");
_Static_assert(sizeof(struct T2_required_alignment) == 9, "record T2 wrong sizeof");
_Static_assert(_Alignof(struct T2_required_alignment) == 1, "record T2 wrong alignment");
_Static_assert(sizeof(struct T2_size) == 10, "record T2 wrong sizeof");
_Static_assert(_Alignof(struct T2_size) == 1, "record T2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(T2,x) == 0, "field T2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(T2,e) == 0, "field T2.e wrong bit offset");
#endif
_Static_assert(sizeof(U2) == 8, "record U2 wrong sizeof");
_Static_assert(_Alignof(U2) == 8, "record U2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct U2_alignment) == 16, "record U2 wrong sizeof");
_Static_assert(_Alignof(struct U2_alignment) == 8, "record U2 wrong alignment");
_Static_assert(sizeof(struct U2_packed) == 8, "record U2 wrong sizeof");
_Static_assert(_Alignof(struct U2_packed) == 1, "record U2 wrong alignment");
_Static_assert(sizeof(struct U2_required_alignment) == 9, "record U2 wrong sizeof");
_Static_assert(_Alignof(struct U2_required_alignment) == 1, "record U2 wrong alignment");
_Static_assert(sizeof(struct U2_size) == 10, "record U2 wrong sizeof");
_Static_assert(_Alignof(struct U2_size) == 1, "record U2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(U2,x) == 0, "field U2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(U2,e) == 0, "field U2.e wrong bit offset");
#endif
_Static_assert(sizeof(V2) == 8, "record V2 wrong sizeof");
_Static_assert(_Alignof(V2) == 8, "record V2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct V2_alignment) == 16, "record V2 wrong sizeof");
_Static_assert(_Alignof(struct V2_alignment) == 8, "record V2 wrong alignment");
_Static_assert(sizeof(struct V2_packed) == 8, "record V2 wrong sizeof");
_Static_assert(_Alignof(struct V2_packed) == 1, "record V2 wrong alignment");
_Static_assert(sizeof(struct V2_required_alignment) == 9, "record V2 wrong sizeof");
_Static_assert(_Alignof(struct V2_required_alignment) == 1, "record V2 wrong alignment");
_Static_assert(sizeof(struct V2_size) == 10, "record V2 wrong sizeof");
_Static_assert(_Alignof(struct V2_size) == 1, "record V2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(V2,x) == 0, "field V2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(V2,e) == 0, "field V2.e wrong bit offset");
#endif
_Static_assert(sizeof(W2) == 16, "record W2 wrong sizeof");
_Static_assert(_Alignof(W2) == 16, "record W2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct W2_alignment) == 32, "record W2 wrong sizeof");
_Static_assert(_Alignof(struct W2_alignment) == 16, "record W2 wrong alignment");
_Static_assert(sizeof(struct W2_packed) == 16, "record W2 wrong sizeof");
_Static_assert(_Alignof(struct W2_packed) == 1, "record W2 wrong alignment");
_Static_assert(sizeof(struct W2_required_alignment) == 17, "record W2 wrong sizeof");
_Static_assert(_Alignof(struct W2_required_alignment) == 1, "record W2 wrong alignment");
_Static_assert(sizeof(struct W2_size) == 18, "record W2 wrong sizeof");
_Static_assert(_Alignof(struct W2_size) == 1, "record W2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(W2,x) == 0, "field W2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(W2,e) == 0, "field W2.e wrong bit offset");
#endif
_Static_assert(sizeof(W_2) == 16, "record W_2 wrong sizeof");
_Static_assert(_Alignof(W_2) == 16, "record W_2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct W_2_alignment) == 32, "record W_2 wrong sizeof");
_Static_assert(_Alignof(struct W_2_alignment) == 16, "record W_2 wrong alignment");
_Static_assert(sizeof(struct W_2_packed) == 16, "record W_2 wrong sizeof");
_Static_assert(_Alignof(struct W_2_packed) == 1, "record W_2 wrong alignment");
_Static_assert(sizeof(struct W_2_required_alignment) == 17, "record W_2 wrong sizeof");
_Static_assert(_Alignof(struct W_2_required_alignment) == 1, "record W_2 wrong alignment");
_Static_assert(sizeof(struct W_2_size) == 18, "record W_2 wrong sizeof");
_Static_assert(_Alignof(struct W_2_size) == 1, "record W_2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(W_2,e) == 0, "field W_2.e wrong bit offset");
#endif
_Static_assert(sizeof(X2) == 16, "record X2 wrong sizeof");
_Static_assert(_Alignof(X2) == 16, "record X2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct X2_alignment) == 32, "record X2 wrong sizeof");
_Static_assert(_Alignof(struct X2_alignment) == 16, "record X2 wrong alignment");
_Static_assert(sizeof(struct X2_packed) == 16, "record X2 wrong sizeof");
_Static_assert(_Alignof(struct X2_packed) == 1, "record X2 wrong alignment");
_Static_assert(sizeof(struct X2_required_alignment) == 17, "record X2 wrong sizeof");
_Static_assert(_Alignof(struct X2_required_alignment) == 1, "record X2 wrong alignment");
_Static_assert(sizeof(struct X2_size) == 18, "record X2 wrong sizeof");
_Static_assert(_Alignof(struct X2_size) == 1, "record X2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(X2,x) == 0, "field X2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(X2,e) == 0, "field X2.e wrong bit offset");
#endif
_Static_assert(sizeof(Y) == 16, "record Y wrong sizeof");
_Static_assert(_Alignof(Y) == 8, "record Y wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Y_alignment) == 24, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_alignment) == 8, "record Y wrong alignment");
_Static_assert(sizeof(struct Y_packed) == 16, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_packed) == 1, "record Y wrong alignment");
_Static_assert(sizeof(struct Y_required_alignment) == 17, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_required_alignment) == 1, "record Y wrong alignment");
_Static_assert(sizeof(struct Y_size) == 18, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_size) == 1, "record Y wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(Y,d) == 64, "field Y.d wrong bit offset");
#endif
_Static_assert(sizeof(Y2) == 8, "record Y2 wrong sizeof");
_Static_assert(_Alignof(Y2) == 8, "record Y2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Y2_alignment) == 16, "record Y2 wrong sizeof");
_Static_assert(_Alignof(struct Y2_alignment) == 8, "record Y2 wrong alignment");
_Static_assert(sizeof(struct Y2_packed) == 8, "record Y2 wrong sizeof");
_Static_assert(_Alignof(struct Y2_packed) == 1, "record Y2 wrong alignment");
_Static_assert(sizeof(struct Y2_required_alignment) == 9, "record Y2 wrong sizeof");
_Static_assert(_Alignof(struct Y2_required_alignment) == 1, "record Y2 wrong alignment");
_Static_assert(sizeof(struct Y2_size) == 10, "record Y2 wrong sizeof");
_Static_assert(_Alignof(struct Y2_size) == 1, "record Y2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(Y2,d) == 0, "field Y2.d wrong bit offset");
#endif
_Static_assert(sizeof(A3) == 64, "record A3 wrong sizeof");
_Static_assert(_Alignof(A3) == 32, "record A3 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A3_alignment) == 96, "record A3 wrong sizeof");
_Static_assert(_Alignof(struct A3_alignment) == 32, "record A3 wrong alignment");
_Static_assert(sizeof(struct A3_packed) == 64, "record A3 wrong sizeof");
_Static_assert(_Alignof(struct A3_packed) == 1, "record A3 wrong alignment");
_Static_assert(sizeof(struct A3_required_alignment) == 65, "record A3 wrong sizeof");
_Static_assert(_Alignof(struct A3_required_alignment) == 1, "record A3 wrong alignment");
_Static_assert(sizeof(struct A3_size) == 66, "record A3 wrong sizeof");
_Static_assert(_Alignof(struct A3_size) == 1, "record A3 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A3,d) == 256, "field A3.d wrong bit offset");
#endif
_Static_assert(sizeof(A4) == 1, "record A4 wrong sizeof");
_Static_assert(_Alignof(A4) == 32, "record A4 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A4_alignment) == 64, "record A4 wrong sizeof");
_Static_assert(_Alignof(struct A4_alignment) == 32, "record A4 wrong alignment");
_Static_assert(sizeof(struct A4_packed) == 1, "record A4 wrong sizeof");
_Static_assert(_Alignof(struct A4_packed) == 1, "record A4 wrong alignment");
_Static_assert(sizeof(struct A4_required_alignment) == 2, "record A4 wrong sizeof");
_Static_assert(_Alignof(struct A4_required_alignment) == 1, "record A4 wrong alignment");
_Static_assert(sizeof(struct A4_size) == 3, "record A4 wrong sizeof");
_Static_assert(_Alignof(struct A4_size) == 1, "record A4 wrong alignment");
#endif
_Static_assert(sizeof(A5) == 64, "record A5 wrong sizeof");
_Static_assert(_Alignof(A5) == 32, "record A5 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A5_alignment) == 96, "record A5 wrong sizeof");
_Static_assert(_Alignof(struct A5_alignment) == 32, "record A5 wrong alignment");
_Static_assert(sizeof(struct A5_packed) == 64, "record A5 wrong sizeof");
_Static_assert(_Alignof(struct A5_packed) == 1, "record A5 wrong alignment");
_Static_assert(sizeof(struct A5_required_alignment) == 65, "record A5 wrong sizeof");
_Static_assert(_Alignof(struct A5_required_alignment) == 1, "record A5 wrong alignment");
_Static_assert(sizeof(struct A5_size) == 66, "record A5 wrong sizeof");
_Static_assert(_Alignof(struct A5_size) == 1, "record A5 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A5,d) == 256, "field A5.d wrong bit offset");
#endif
_Static_assert(sizeof(A7) == 32, "record A7 wrong sizeof");
_Static_assert(_Alignof(A7) == 32, "record A7 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A7_alignment) == 64, "record A7 wrong sizeof");
_Static_assert(_Alignof(struct A7_alignment) == 32, "record A7 wrong alignment");
_Static_assert(sizeof(struct A7_packed) == 32, "record A7 wrong sizeof");
_Static_assert(_Alignof(struct A7_packed) == 1, "record A7 wrong alignment");
_Static_assert(sizeof(struct A7_required_alignment) == 33, "record A7 wrong sizeof");
_Static_assert(_Alignof(struct A7_required_alignment) == 1, "record A7 wrong alignment");
_Static_assert(sizeof(struct A7_size) == 34, "record A7 wrong sizeof");
_Static_assert(_Alignof(struct A7_size) == 1, "record A7 wrong alignment");
#endif
_Static_assert(sizeof(A8) == 8, "record A8 wrong sizeof");
_Static_assert(_Alignof(A8) == 4, "record A8 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A8_alignment) == 12, "record A8 wrong sizeof");
_Static_assert(_Alignof(struct A8_alignment) == 4, "record A8 wrong alignment");
_Static_assert(sizeof(struct A8_packed) == 8, "record A8 wrong sizeof");
_Static_assert(_Alignof(struct A8_packed) == 1, "record A8 wrong alignment");
_Static_assert(sizeof(struct A8_required_alignment) == 9, "record A8 wrong sizeof");
_Static_assert(_Alignof(struct A8_required_alignment) == 1, "record A8 wrong alignment");
_Static_assert(sizeof(struct A8_size) == 10, "record A8 wrong sizeof");
_Static_assert(_Alignof(struct A8_size) == 1, "record A8 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A8,i) == 8, "field A8.i wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A8,j) == 39, "field A8.j wrong bit offset");
#endif
_Static_assert(sizeof(A9) == 12, "record A9 wrong sizeof");
_Static_assert(_Alignof(A9) == 4, "record A9 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A9_alignment) == 16, "record A9 wrong sizeof");
_Static_assert(_Alignof(struct A9_alignment) == 4, "record A9 wrong alignment");
_Static_assert(sizeof(struct A9_packed) == 12, "record A9 wrong sizeof");
_Static_assert(_Alignof(struct A9_packed) == 1, "record A9 wrong alignment");
_Static_assert(sizeof(struct A9_required_alignment) == 13, "record A9 wrong sizeof");
_Static_assert(_Alignof(struct A9_required_alignment) == 1, "record A9 wrong alignment");
_Static_assert(sizeof(struct A9_size) == 14, "record A9 wrong sizeof");
_Static_assert(_Alignof(struct A9_size) == 1, "record A9 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A9,i) == 8, "field A9.i wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A9,j) == 64, "field A9.j wrong bit offset");
#endif
_Static_assert(sizeof(A10) == 4, "record A10 wrong sizeof");
_Static_assert(_Alignof(A10) == 16, "record A10 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A10_alignment) == 32, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_alignment) == 16, "record A10 wrong alignment");
_Static_assert(sizeof(struct A10_packed) == 4, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_packed) == 1, "record A10 wrong alignment");
_Static_assert(sizeof(struct A10_required_alignment) == 5, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_required_alignment) == 1, "record A10 wrong alignment");
_Static_assert(sizeof(struct A10_size) == 6, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_size) == 1, "record A10 wrong alignment");
#endif
_Static_assert(sizeof(A11) == 32, "record A11 wrong sizeof");
_Static_assert(_Alignof(A11) == 16, "record A11 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A11_alignment) == 48, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_alignment) == 16, "record A11 wrong alignment");
_Static_assert(sizeof(struct A11_packed) == 32, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_packed) == 1, "record A11 wrong alignment");
_Static_assert(sizeof(struct A11_required_alignment) == 33, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_required_alignment) == 1, "record A11 wrong alignment");
_Static_assert(sizeof(struct A11_size) == 34, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_size) == 1, "record A11 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A11,i) == 8, "field A11.i wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A11,j) == 128, "field A11.j wrong bit offset");
#endif
_Static_assert(sizeof(A12) == 32, "record A12 wrong sizeof");
_Static_assert(_Alignof(A12) == 16, "record A12 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A12_alignment) == 48, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_alignment) == 16, "record A12 wrong alignment");
_Static_assert(sizeof(struct A12_packed) == 32, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_packed) == 1, "record A12 wrong alignment");
_Static_assert(sizeof(struct A12_required_alignment) == 33, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_required_alignment) == 1, "record A12 wrong alignment");
_Static_assert(sizeof(struct A12_size) == 34, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_size) == 1, "record A12 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A12,i) == 8, "field A12.i wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A12,j) == 128, "field A12.j wrong bit offset");
#endif
_Static_assert(sizeof(A13) == 32, "record A13 wrong sizeof");
_Static_assert(_Alignof(A13) == 16, "record A13 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A13_alignment) == 48, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_alignment) == 16, "record A13 wrong alignment");
_Static_assert(sizeof(struct A13_packed) == 32, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_packed) == 1, "record A13 wrong alignment");
_Static_assert(sizeof(struct A13_required_alignment) == 33, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_required_alignment) == 1, "record A13 wrong alignment");
_Static_assert(sizeof(struct A13_size) == 34, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_size) == 1, "record A13 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A13,i) == 8, "field A13.i wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A13,j) == 128, "field A13.j wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A13,d) == 136, "field A13.d wrong bit offset");
#endif
// MAPPING|SIX|arm-cortex_r4-ios-none:Clang|arm-baseline-ios-none:Clang|END
// repr targets Armv7AppleIos|Some("arm-cortex_r4-ios-none") Armv7sAppleIos|Some("arm-baseline-ios-none") 
#elif defined(SIX)
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
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A,d) == 0, "field A.d wrong bit offset");
#endif
_Static_assert(sizeof(A_) == 8, "record A_ wrong sizeof");
_Static_assert(_Alignof(A_) == 4, "record A_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A__alignment) == 12, "record A_ wrong sizeof");
_Static_assert(_Alignof(struct A__alignment) == 4, "record A_ wrong alignment");
_Static_assert(sizeof(struct A__packed) == 8, "record A_ wrong sizeof");
_Static_assert(_Alignof(struct A__packed) == 1, "record A_ wrong alignment");
_Static_assert(sizeof(struct A__required_alignment) == 9, "record A_ wrong sizeof");
_Static_assert(_Alignof(struct A__required_alignment) == 1, "record A_ wrong alignment");
_Static_assert(sizeof(struct A__size) == 10, "record A_ wrong sizeof");
_Static_assert(_Alignof(struct A__size) == 1, "record A_ wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_,d) == 32, "field A_.d wrong bit offset");
#endif
_Static_assert(sizeof(B) == 4, "record B wrong sizeof");
_Static_assert(_Alignof(B) == 4, "record B wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 8, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_alignment) == 4, "record B wrong alignment");
_Static_assert(sizeof(struct B_packed) == 4, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_packed) == 1, "record B wrong alignment");
_Static_assert(sizeof(struct B_required_alignment) == 5, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "record B wrong alignment");
_Static_assert(sizeof(struct B_size) == 6, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_size) == 1, "record B wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B,d) == 0, "field B.d wrong bit offset");
#endif
_Static_assert(sizeof(B_) == 8, "record B_ wrong sizeof");
_Static_assert(_Alignof(B_) == 4, "record B_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B__alignment) == 12, "record B_ wrong sizeof");
_Static_assert(_Alignof(struct B__alignment) == 4, "record B_ wrong alignment");
_Static_assert(sizeof(struct B__packed) == 8, "record B_ wrong sizeof");
_Static_assert(_Alignof(struct B__packed) == 1, "record B_ wrong alignment");
_Static_assert(sizeof(struct B__required_alignment) == 9, "record B_ wrong sizeof");
_Static_assert(_Alignof(struct B__required_alignment) == 1, "record B_ wrong alignment");
_Static_assert(sizeof(struct B__size) == 10, "record B_ wrong sizeof");
_Static_assert(_Alignof(struct B__size) == 1, "record B_ wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B_,d) == 32, "field B_.d wrong bit offset");
#endif
_Static_assert(sizeof(C) == 4, "record C wrong sizeof");
_Static_assert(_Alignof(C) == 4, "record C wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 8, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_alignment) == 4, "record C wrong alignment");
_Static_assert(sizeof(struct C_packed) == 4, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_packed) == 1, "record C wrong alignment");
_Static_assert(sizeof(struct C_required_alignment) == 5, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "record C wrong alignment");
_Static_assert(sizeof(struct C_size) == 6, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_size) == 1, "record C wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C,d) == 0, "field C.d wrong bit offset");
#endif
_Static_assert(sizeof(C_) == 8, "record C_ wrong sizeof");
_Static_assert(_Alignof(C_) == 4, "record C_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C__alignment) == 12, "record C_ wrong sizeof");
_Static_assert(_Alignof(struct C__alignment) == 4, "record C_ wrong alignment");
_Static_assert(sizeof(struct C__packed) == 8, "record C_ wrong sizeof");
_Static_assert(_Alignof(struct C__packed) == 1, "record C_ wrong alignment");
_Static_assert(sizeof(struct C__required_alignment) == 9, "record C_ wrong sizeof");
_Static_assert(_Alignof(struct C__required_alignment) == 1, "record C_ wrong alignment");
_Static_assert(sizeof(struct C__size) == 10, "record C_ wrong sizeof");
_Static_assert(_Alignof(struct C__size) == 1, "record C_ wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C_,d) == 32, "field C_.d wrong bit offset");
#endif
_Static_assert(sizeof(D) == 16, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 4, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 20, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 4, "record D wrong alignment");
_Static_assert(sizeof(struct D_packed) == 16, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 17, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_size) == 18, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_size) == 1, "record D wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D,d) == 32, "field D.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(D,e) == 96, "field D.e wrong bit offset");
#endif
_Static_assert(sizeof(F) == 32, "record F wrong sizeof");
_Static_assert(_Alignof(F) == 16, "record F wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 48, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_alignment) == 16, "record F wrong alignment");
_Static_assert(sizeof(struct F_packed) == 32, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_packed) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_required_alignment) == 33, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_size) == 34, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_size) == 1, "record F wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F,d) == 128, "field F.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(F,e) == 192, "field F.e wrong bit offset");
#endif
_Static_assert(sizeof(G) == 12, "record G wrong sizeof");
_Static_assert(_Alignof(G) == 2, "record G wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 14, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_alignment) == 2, "record G wrong alignment");
_Static_assert(sizeof(struct G_packed) == 12, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_packed) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_required_alignment) == 13, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_size) == 14, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_size) == 1, "record G wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(G,d) == 16, "field G.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(G,e) == 80, "field G.e wrong bit offset");
#endif
_Static_assert(sizeof(H) == 12, "record H wrong sizeof");
_Static_assert(_Alignof(H) == 2, "record H wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 14, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_alignment) == 2, "record H wrong alignment");
_Static_assert(sizeof(struct H_packed) == 12, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_packed) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_required_alignment) == 13, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_size) == 14, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_size) == 1, "record H wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(H,d) == 16, "field H.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(H,e) == 80, "field H.e wrong bit offset");
#endif
_Static_assert(sizeof(I) == 10, "record I wrong sizeof");
_Static_assert(_Alignof(I) == 1, "record I wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I_alignment) == 11, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_alignment) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_packed) == 10, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_packed) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_required_alignment) == 11, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_required_alignment) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_size) == 12, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_size) == 1, "record I wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(I,d) == 8, "field I.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(I,e) == 72, "field I.e wrong bit offset");
#endif
_Static_assert(sizeof(J) == 12, "record J wrong sizeof");
_Static_assert(_Alignof(J) == 2, "record J wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J_alignment) == 14, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_alignment) == 2, "record J wrong alignment");
_Static_assert(sizeof(struct J_packed) == 12, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_packed) == 1, "record J wrong alignment");
_Static_assert(sizeof(struct J_required_alignment) == 13, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_required_alignment) == 1, "record J wrong alignment");
_Static_assert(sizeof(struct J_size) == 14, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_size) == 1, "record J wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(J,d) == 16, "field J.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(J,e) == 80, "field J.e wrong bit offset");
#endif
_Static_assert(sizeof(K) == 3, "record K wrong sizeof");
_Static_assert(_Alignof(K) == 1, "record K wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct K_alignment) == 4, "record K wrong sizeof");
_Static_assert(_Alignof(struct K_alignment) == 1, "record K wrong alignment");
_Static_assert(sizeof(struct K_packed) == 3, "record K wrong sizeof");
_Static_assert(_Alignof(struct K_packed) == 1, "record K wrong alignment");
_Static_assert(sizeof(struct K_required_alignment) == 4, "record K wrong sizeof");
_Static_assert(_Alignof(struct K_required_alignment) == 1, "record K wrong alignment");
_Static_assert(sizeof(struct K_size) == 5, "record K wrong sizeof");
_Static_assert(_Alignof(struct K_size) == 1, "record K wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(K,d) == 8, "field K.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(K,e) == 16, "field K.e wrong bit offset");
#endif
_Static_assert(sizeof(L) == 32, "record L wrong sizeof");
_Static_assert(_Alignof(L) == 16, "record L wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct L_alignment) == 48, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_alignment) == 16, "record L wrong alignment");
_Static_assert(sizeof(struct L_packed) == 32, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_packed) == 1, "record L wrong alignment");
_Static_assert(sizeof(struct L_required_alignment) == 33, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_required_alignment) == 1, "record L wrong alignment");
_Static_assert(sizeof(struct L_size) == 34, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_size) == 1, "record L wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(L,d) == 128, "field L.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(L,e) == 136, "field L.e wrong bit offset");
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
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(M,d) == 16, "field M.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(M,e) == 24, "field M.e wrong bit offset");
#endif
_Static_assert(sizeof(N) == 4, "record N wrong sizeof");
_Static_assert(_Alignof(N) == 2, "record N wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct N_alignment) == 6, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_alignment) == 2, "record N wrong alignment");
_Static_assert(sizeof(struct N_packed) == 4, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_packed) == 1, "record N wrong alignment");
_Static_assert(sizeof(struct N_required_alignment) == 5, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_required_alignment) == 1, "record N wrong alignment");
_Static_assert(sizeof(struct N_size) == 6, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_size) == 1, "record N wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(N,d) == 8, "field N.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(N,e) == 16, "field N.e wrong bit offset");
#endif
_Static_assert(sizeof(O) == 3, "record O wrong sizeof");
_Static_assert(_Alignof(O) == 1, "record O wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct O_alignment) == 4, "record O wrong sizeof");
_Static_assert(_Alignof(struct O_alignment) == 1, "record O wrong alignment");
_Static_assert(sizeof(struct O_packed) == 3, "record O wrong sizeof");
_Static_assert(_Alignof(struct O_packed) == 1, "record O wrong alignment");
_Static_assert(sizeof(struct O_required_alignment) == 4, "record O wrong sizeof");
_Static_assert(_Alignof(struct O_required_alignment) == 1, "record O wrong alignment");
_Static_assert(sizeof(struct O_size) == 5, "record O wrong sizeof");
_Static_assert(_Alignof(struct O_size) == 1, "record O wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(O,d) == 8, "field O.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(O,e) == 16, "field O.e wrong bit offset");
#endif
_Static_assert(sizeof(P) == 3, "record P wrong sizeof");
_Static_assert(_Alignof(P) == 1, "record P wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct P_alignment) == 4, "record P wrong sizeof");
_Static_assert(_Alignof(struct P_alignment) == 1, "record P wrong alignment");
_Static_assert(sizeof(struct P_packed) == 3, "record P wrong sizeof");
_Static_assert(_Alignof(struct P_packed) == 1, "record P wrong alignment");
_Static_assert(sizeof(struct P_required_alignment) == 4, "record P wrong sizeof");
_Static_assert(_Alignof(struct P_required_alignment) == 1, "record P wrong alignment");
_Static_assert(sizeof(struct P_size) == 5, "record P wrong sizeof");
_Static_assert(_Alignof(struct P_size) == 1, "record P wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(P,d) == 8, "field P.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(P,e) == 16, "field P.e wrong bit offset");
#endif
_Static_assert(sizeof(Q) == 3, "record Q wrong sizeof");
_Static_assert(_Alignof(Q) == 1, "record Q wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Q_alignment) == 4, "record Q wrong sizeof");
_Static_assert(_Alignof(struct Q_alignment) == 1, "record Q wrong alignment");
_Static_assert(sizeof(struct Q_packed) == 3, "record Q wrong sizeof");
_Static_assert(_Alignof(struct Q_packed) == 1, "record Q wrong alignment");
_Static_assert(sizeof(struct Q_required_alignment) == 4, "record Q wrong sizeof");
_Static_assert(_Alignof(struct Q_required_alignment) == 1, "record Q wrong alignment");
_Static_assert(sizeof(struct Q_size) == 5, "record Q wrong sizeof");
_Static_assert(_Alignof(struct Q_size) == 1, "record Q wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(Q,x) == 8, "field Q.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(Q,d) == 9, "field Q.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(Q,e) == 16, "field Q.e wrong bit offset");
#endif
_Static_assert(sizeof(R) == 32, "record R wrong sizeof");
_Static_assert(_Alignof(R) == 16, "record R wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct R_alignment) == 48, "record R wrong sizeof");
_Static_assert(_Alignof(struct R_alignment) == 16, "record R wrong alignment");
_Static_assert(sizeof(struct R_packed) == 32, "record R wrong sizeof");
_Static_assert(_Alignof(struct R_packed) == 1, "record R wrong alignment");
_Static_assert(sizeof(struct R_required_alignment) == 33, "record R wrong sizeof");
_Static_assert(_Alignof(struct R_required_alignment) == 1, "record R wrong alignment");
_Static_assert(sizeof(struct R_size) == 34, "record R wrong sizeof");
_Static_assert(_Alignof(struct R_size) == 1, "record R wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(R,x) == 8, "field R.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(R,e) == 128, "field R.e wrong bit offset");
#endif
_Static_assert(sizeof(S) == 8, "record S wrong sizeof");
_Static_assert(_Alignof(S) == 4, "record S wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct S_alignment) == 12, "record S wrong sizeof");
_Static_assert(_Alignof(struct S_alignment) == 4, "record S wrong alignment");
_Static_assert(sizeof(struct S_packed) == 8, "record S wrong sizeof");
_Static_assert(_Alignof(struct S_packed) == 1, "record S wrong alignment");
_Static_assert(sizeof(struct S_required_alignment) == 9, "record S wrong sizeof");
_Static_assert(_Alignof(struct S_required_alignment) == 1, "record S wrong alignment");
_Static_assert(sizeof(struct S_size) == 10, "record S wrong sizeof");
_Static_assert(_Alignof(struct S_size) == 1, "record S wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(S,x) == 8, "field S.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(S,e) == 32, "field S.e wrong bit offset");
#endif
_Static_assert(sizeof(T) == 8, "record T wrong sizeof");
_Static_assert(_Alignof(T) == 4, "record T wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct T_alignment) == 12, "record T wrong sizeof");
_Static_assert(_Alignof(struct T_alignment) == 4, "record T wrong alignment");
_Static_assert(sizeof(struct T_packed) == 8, "record T wrong sizeof");
_Static_assert(_Alignof(struct T_packed) == 1, "record T wrong alignment");
_Static_assert(sizeof(struct T_required_alignment) == 9, "record T wrong sizeof");
_Static_assert(_Alignof(struct T_required_alignment) == 1, "record T wrong alignment");
_Static_assert(sizeof(struct T_size) == 10, "record T wrong sizeof");
_Static_assert(_Alignof(struct T_size) == 1, "record T wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(T,x) == 8, "field T.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(T,e) == 32, "field T.e wrong bit offset");
#endif
_Static_assert(sizeof(U) == 8, "record U wrong sizeof");
_Static_assert(_Alignof(U) == 4, "record U wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct U_alignment) == 12, "record U wrong sizeof");
_Static_assert(_Alignof(struct U_alignment) == 4, "record U wrong alignment");
_Static_assert(sizeof(struct U_packed) == 8, "record U wrong sizeof");
_Static_assert(_Alignof(struct U_packed) == 1, "record U wrong alignment");
_Static_assert(sizeof(struct U_required_alignment) == 9, "record U wrong sizeof");
_Static_assert(_Alignof(struct U_required_alignment) == 1, "record U wrong alignment");
_Static_assert(sizeof(struct U_size) == 10, "record U wrong sizeof");
_Static_assert(_Alignof(struct U_size) == 1, "record U wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(U,x) == 8, "field U.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(U,e) == 32, "field U.e wrong bit offset");
#endif
_Static_assert(sizeof(V) == 8, "record V wrong sizeof");
_Static_assert(_Alignof(V) == 4, "record V wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct V_alignment) == 12, "record V wrong sizeof");
_Static_assert(_Alignof(struct V_alignment) == 4, "record V wrong alignment");
_Static_assert(sizeof(struct V_packed) == 8, "record V wrong sizeof");
_Static_assert(_Alignof(struct V_packed) == 1, "record V wrong alignment");
_Static_assert(sizeof(struct V_required_alignment) == 9, "record V wrong sizeof");
_Static_assert(_Alignof(struct V_required_alignment) == 1, "record V wrong alignment");
_Static_assert(sizeof(struct V_size) == 10, "record V wrong sizeof");
_Static_assert(_Alignof(struct V_size) == 1, "record V wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(V,x) == 8, "field V.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(V,e) == 32, "field V.e wrong bit offset");
#endif
_Static_assert(sizeof(W) == 32, "record W wrong sizeof");
_Static_assert(_Alignof(W) == 16, "record W wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct W_alignment) == 48, "record W wrong sizeof");
_Static_assert(_Alignof(struct W_alignment) == 16, "record W wrong alignment");
_Static_assert(sizeof(struct W_packed) == 32, "record W wrong sizeof");
_Static_assert(_Alignof(struct W_packed) == 1, "record W wrong alignment");
_Static_assert(sizeof(struct W_required_alignment) == 33, "record W wrong sizeof");
_Static_assert(_Alignof(struct W_required_alignment) == 1, "record W wrong alignment");
_Static_assert(sizeof(struct W_size) == 34, "record W wrong sizeof");
_Static_assert(_Alignof(struct W_size) == 1, "record W wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(W,x) == 8, "field W.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(W,e) == 128, "field W.e wrong bit offset");
#endif
_Static_assert(sizeof(W_) == 32, "record W_ wrong sizeof");
_Static_assert(_Alignof(W_) == 16, "record W_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct W__alignment) == 48, "record W_ wrong sizeof");
_Static_assert(_Alignof(struct W__alignment) == 16, "record W_ wrong alignment");
_Static_assert(sizeof(struct W__packed) == 32, "record W_ wrong sizeof");
_Static_assert(_Alignof(struct W__packed) == 1, "record W_ wrong alignment");
_Static_assert(sizeof(struct W__required_alignment) == 33, "record W_ wrong sizeof");
_Static_assert(_Alignof(struct W__required_alignment) == 1, "record W_ wrong alignment");
_Static_assert(sizeof(struct W__size) == 34, "record W_ wrong sizeof");
_Static_assert(_Alignof(struct W__size) == 1, "record W_ wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(W_,e) == 128, "field W_.e wrong bit offset");
#endif
_Static_assert(sizeof(X) == 32, "record X wrong sizeof");
_Static_assert(_Alignof(X) == 16, "record X wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct X_alignment) == 48, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_alignment) == 16, "record X wrong alignment");
_Static_assert(sizeof(struct X_packed) == 32, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_packed) == 1, "record X wrong alignment");
_Static_assert(sizeof(struct X_required_alignment) == 33, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_required_alignment) == 1, "record X wrong alignment");
_Static_assert(sizeof(struct X_size) == 34, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_size) == 1, "record X wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(X,x) == 8, "field X.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(X,e) == 128, "field X.e wrong bit offset");
#endif
_Static_assert(sizeof(A2) == 4, "record A2 wrong sizeof");
_Static_assert(_Alignof(A2) == 4, "record A2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A2_alignment) == 8, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_alignment) == 4, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_packed) == 4, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_packed) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_required_alignment) == 5, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_required_alignment) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_size) == 6, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_size) == 1, "record A2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A2,d) == 0, "field A2.d wrong bit offset");
#endif
_Static_assert(sizeof(A_2) == 4, "record A_2 wrong sizeof");
_Static_assert(_Alignof(A_2) == 4, "record A_2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_2_alignment) == 8, "record A_2 wrong sizeof");
_Static_assert(_Alignof(struct A_2_alignment) == 4, "record A_2 wrong alignment");
_Static_assert(sizeof(struct A_2_packed) == 4, "record A_2 wrong sizeof");
_Static_assert(_Alignof(struct A_2_packed) == 1, "record A_2 wrong alignment");
_Static_assert(sizeof(struct A_2_required_alignment) == 5, "record A_2 wrong sizeof");
_Static_assert(_Alignof(struct A_2_required_alignment) == 1, "record A_2 wrong alignment");
_Static_assert(sizeof(struct A_2_size) == 6, "record A_2 wrong sizeof");
_Static_assert(_Alignof(struct A_2_size) == 1, "record A_2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_2,d) == 0, "field A_2.d wrong bit offset");
#endif
_Static_assert(sizeof(B2) == 4, "record B2 wrong sizeof");
_Static_assert(_Alignof(B2) == 4, "record B2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B2_alignment) == 8, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_alignment) == 4, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_packed) == 4, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_packed) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_required_alignment) == 5, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_required_alignment) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_size) == 6, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_size) == 1, "record B2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B2,d) == 0, "field B2.d wrong bit offset");
#endif
_Static_assert(sizeof(B_2) == 4, "record B_2 wrong sizeof");
_Static_assert(_Alignof(B_2) == 4, "record B_2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_2_alignment) == 8, "record B_2 wrong sizeof");
_Static_assert(_Alignof(struct B_2_alignment) == 4, "record B_2 wrong alignment");
_Static_assert(sizeof(struct B_2_packed) == 4, "record B_2 wrong sizeof");
_Static_assert(_Alignof(struct B_2_packed) == 1, "record B_2 wrong alignment");
_Static_assert(sizeof(struct B_2_required_alignment) == 5, "record B_2 wrong sizeof");
_Static_assert(_Alignof(struct B_2_required_alignment) == 1, "record B_2 wrong alignment");
_Static_assert(sizeof(struct B_2_size) == 6, "record B_2 wrong sizeof");
_Static_assert(_Alignof(struct B_2_size) == 1, "record B_2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B_2,d) == 0, "field B_2.d wrong bit offset");
#endif
_Static_assert(sizeof(C2) == 4, "record C2 wrong sizeof");
_Static_assert(_Alignof(C2) == 4, "record C2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C2_alignment) == 8, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_alignment) == 4, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_packed) == 4, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_packed) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_required_alignment) == 5, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_required_alignment) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_size) == 6, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_size) == 1, "record C2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C2,d) == 0, "field C2.d wrong bit offset");
#endif
_Static_assert(sizeof(C22) == 4, "record C22 wrong sizeof");
_Static_assert(_Alignof(C22) == 4, "record C22 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C22_alignment) == 8, "record C22 wrong sizeof");
_Static_assert(_Alignof(struct C22_alignment) == 4, "record C22 wrong alignment");
_Static_assert(sizeof(struct C22_packed) == 4, "record C22 wrong sizeof");
_Static_assert(_Alignof(struct C22_packed) == 1, "record C22 wrong alignment");
_Static_assert(sizeof(struct C22_required_alignment) == 5, "record C22 wrong sizeof");
_Static_assert(_Alignof(struct C22_required_alignment) == 1, "record C22 wrong alignment");
_Static_assert(sizeof(struct C22_size) == 6, "record C22 wrong sizeof");
_Static_assert(_Alignof(struct C22_size) == 1, "record C22 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C22,d) == 0, "field C22.d wrong bit offset");
#endif
_Static_assert(sizeof(D2) == 8, "record D2 wrong sizeof");
_Static_assert(_Alignof(D2) == 4, "record D2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D2_alignment) == 12, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_alignment) == 4, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_packed) == 8, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_packed) == 1, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_required_alignment) == 9, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_required_alignment) == 1, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_size) == 10, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_size) == 1, "record D2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D2,d) == 0, "field D2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(D2,e) == 0, "field D2.e wrong bit offset");
#endif
_Static_assert(sizeof(F2) == 16, "record F2 wrong sizeof");
_Static_assert(_Alignof(F2) == 16, "record F2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F2_alignment) == 32, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_alignment) == 16, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_packed) == 16, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_packed) == 1, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_required_alignment) == 17, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_required_alignment) == 1, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_size) == 18, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_size) == 1, "record F2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F2,d) == 0, "field F2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(F2,e) == 0, "field F2.e wrong bit offset");
#endif
_Static_assert(sizeof(G2) == 8, "record G2 wrong sizeof");
_Static_assert(_Alignof(G2) == 2, "record G2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G2_alignment) == 10, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_alignment) == 2, "record G2 wrong alignment");
_Static_assert(sizeof(struct G2_packed) == 8, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_packed) == 1, "record G2 wrong alignment");
_Static_assert(sizeof(struct G2_required_alignment) == 9, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_required_alignment) == 1, "record G2 wrong alignment");
_Static_assert(sizeof(struct G2_size) == 10, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_size) == 1, "record G2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(G2,d) == 0, "field G2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(G2,e) == 0, "field G2.e wrong bit offset");
#endif
_Static_assert(sizeof(H2) == 8, "record H2 wrong sizeof");
_Static_assert(_Alignof(H2) == 2, "record H2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H2_alignment) == 10, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_alignment) == 2, "record H2 wrong alignment");
_Static_assert(sizeof(struct H2_packed) == 8, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_packed) == 1, "record H2 wrong alignment");
_Static_assert(sizeof(struct H2_required_alignment) == 9, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_required_alignment) == 1, "record H2 wrong alignment");
_Static_assert(sizeof(struct H2_size) == 10, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_size) == 1, "record H2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(H2,d) == 0, "field H2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(H2,e) == 0, "field H2.e wrong bit offset");
#endif
_Static_assert(sizeof(I2) == 8, "record I2 wrong sizeof");
_Static_assert(_Alignof(I2) == 1, "record I2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I2_alignment) == 9, "record I2 wrong sizeof");
_Static_assert(_Alignof(struct I2_alignment) == 1, "record I2 wrong alignment");
_Static_assert(sizeof(struct I2_packed) == 8, "record I2 wrong sizeof");
_Static_assert(_Alignof(struct I2_packed) == 1, "record I2 wrong alignment");
_Static_assert(sizeof(struct I2_required_alignment) == 9, "record I2 wrong sizeof");
_Static_assert(_Alignof(struct I2_required_alignment) == 1, "record I2 wrong alignment");
_Static_assert(sizeof(struct I2_size) == 10, "record I2 wrong sizeof");
_Static_assert(_Alignof(struct I2_size) == 1, "record I2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(I2,d) == 0, "field I2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(I2,e) == 0, "field I2.e wrong bit offset");
#endif
_Static_assert(sizeof(J2) == 8, "record J2 wrong sizeof");
_Static_assert(_Alignof(J2) == 2, "record J2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J2_alignment) == 10, "record J2 wrong sizeof");
_Static_assert(_Alignof(struct J2_alignment) == 2, "record J2 wrong alignment");
_Static_assert(sizeof(struct J2_packed) == 8, "record J2 wrong sizeof");
_Static_assert(_Alignof(struct J2_packed) == 1, "record J2 wrong alignment");
_Static_assert(sizeof(struct J2_required_alignment) == 9, "record J2 wrong sizeof");
_Static_assert(_Alignof(struct J2_required_alignment) == 1, "record J2 wrong alignment");
_Static_assert(sizeof(struct J2_size) == 10, "record J2 wrong sizeof");
_Static_assert(_Alignof(struct J2_size) == 1, "record J2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(J2,d) == 0, "field J2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(J2,e) == 0, "field J2.e wrong bit offset");
#endif
_Static_assert(sizeof(K2) == 1, "record K2 wrong sizeof");
_Static_assert(_Alignof(K2) == 1, "record K2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct K2_alignment) == 2, "record K2 wrong sizeof");
_Static_assert(_Alignof(struct K2_alignment) == 1, "record K2 wrong alignment");
_Static_assert(sizeof(struct K2_packed) == 1, "record K2 wrong sizeof");
_Static_assert(_Alignof(struct K2_packed) == 1, "record K2 wrong alignment");
_Static_assert(sizeof(struct K2_required_alignment) == 2, "record K2 wrong sizeof");
_Static_assert(_Alignof(struct K2_required_alignment) == 1, "record K2 wrong alignment");
_Static_assert(sizeof(struct K2_size) == 3, "record K2 wrong sizeof");
_Static_assert(_Alignof(struct K2_size) == 1, "record K2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(K2,d) == 0, "field K2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(K2,e) == 0, "field K2.e wrong bit offset");
#endif
_Static_assert(sizeof(L2) == 16, "record L2 wrong sizeof");
_Static_assert(_Alignof(L2) == 16, "record L2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct L2_alignment) == 32, "record L2 wrong sizeof");
_Static_assert(_Alignof(struct L2_alignment) == 16, "record L2 wrong alignment");
_Static_assert(sizeof(struct L2_packed) == 16, "record L2 wrong sizeof");
_Static_assert(_Alignof(struct L2_packed) == 1, "record L2 wrong alignment");
_Static_assert(sizeof(struct L2_required_alignment) == 17, "record L2 wrong sizeof");
_Static_assert(_Alignof(struct L2_required_alignment) == 1, "record L2 wrong alignment");
_Static_assert(sizeof(struct L2_size) == 18, "record L2 wrong sizeof");
_Static_assert(_Alignof(struct L2_size) == 1, "record L2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(L2,d) == 0, "field L2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(L2,e) == 0, "field L2.e wrong bit offset");
#endif
_Static_assert(sizeof(M2) == 2, "record M2 wrong sizeof");
_Static_assert(_Alignof(M2) == 2, "record M2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct M2_alignment) == 4, "record M2 wrong sizeof");
_Static_assert(_Alignof(struct M2_alignment) == 2, "record M2 wrong alignment");
_Static_assert(sizeof(struct M2_packed) == 2, "record M2 wrong sizeof");
_Static_assert(_Alignof(struct M2_packed) == 1, "record M2 wrong alignment");
_Static_assert(sizeof(struct M2_required_alignment) == 3, "record M2 wrong sizeof");
_Static_assert(_Alignof(struct M2_required_alignment) == 1, "record M2 wrong alignment");
_Static_assert(sizeof(struct M2_size) == 4, "record M2 wrong sizeof");
_Static_assert(_Alignof(struct M2_size) == 1, "record M2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(M2,d) == 0, "field M2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(M2,e) == 0, "field M2.e wrong bit offset");
#endif
_Static_assert(sizeof(N2) == 2, "record N2 wrong sizeof");
_Static_assert(_Alignof(N2) == 2, "record N2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct N2_alignment) == 4, "record N2 wrong sizeof");
_Static_assert(_Alignof(struct N2_alignment) == 2, "record N2 wrong alignment");
_Static_assert(sizeof(struct N2_packed) == 2, "record N2 wrong sizeof");
_Static_assert(_Alignof(struct N2_packed) == 1, "record N2 wrong alignment");
_Static_assert(sizeof(struct N2_required_alignment) == 3, "record N2 wrong sizeof");
_Static_assert(_Alignof(struct N2_required_alignment) == 1, "record N2 wrong alignment");
_Static_assert(sizeof(struct N2_size) == 4, "record N2 wrong sizeof");
_Static_assert(_Alignof(struct N2_size) == 1, "record N2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(N2,d) == 0, "field N2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(N2,e) == 0, "field N2.e wrong bit offset");
#endif
_Static_assert(sizeof(O2) == 1, "record O2 wrong sizeof");
_Static_assert(_Alignof(O2) == 1, "record O2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct O2_alignment) == 2, "record O2 wrong sizeof");
_Static_assert(_Alignof(struct O2_alignment) == 1, "record O2 wrong alignment");
_Static_assert(sizeof(struct O2_packed) == 1, "record O2 wrong sizeof");
_Static_assert(_Alignof(struct O2_packed) == 1, "record O2 wrong alignment");
_Static_assert(sizeof(struct O2_required_alignment) == 2, "record O2 wrong sizeof");
_Static_assert(_Alignof(struct O2_required_alignment) == 1, "record O2 wrong alignment");
_Static_assert(sizeof(struct O2_size) == 3, "record O2 wrong sizeof");
_Static_assert(_Alignof(struct O2_size) == 1, "record O2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(O2,d) == 0, "field O2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(O2,e) == 0, "field O2.e wrong bit offset");
#endif
_Static_assert(sizeof(P2) == 1, "record P2 wrong sizeof");
_Static_assert(_Alignof(P2) == 1, "record P2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct P2_alignment) == 2, "record P2 wrong sizeof");
_Static_assert(_Alignof(struct P2_alignment) == 1, "record P2 wrong alignment");
_Static_assert(sizeof(struct P2_packed) == 1, "record P2 wrong sizeof");
_Static_assert(_Alignof(struct P2_packed) == 1, "record P2 wrong alignment");
_Static_assert(sizeof(struct P2_required_alignment) == 2, "record P2 wrong sizeof");
_Static_assert(_Alignof(struct P2_required_alignment) == 1, "record P2 wrong alignment");
_Static_assert(sizeof(struct P2_size) == 3, "record P2 wrong sizeof");
_Static_assert(_Alignof(struct P2_size) == 1, "record P2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(P2,d) == 0, "field P2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(P2,e) == 0, "field P2.e wrong bit offset");
#endif
_Static_assert(sizeof(Q2) == 1, "record Q2 wrong sizeof");
_Static_assert(_Alignof(Q2) == 1, "record Q2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Q2_alignment) == 2, "record Q2 wrong sizeof");
_Static_assert(_Alignof(struct Q2_alignment) == 1, "record Q2 wrong alignment");
_Static_assert(sizeof(struct Q2_packed) == 1, "record Q2 wrong sizeof");
_Static_assert(_Alignof(struct Q2_packed) == 1, "record Q2 wrong alignment");
_Static_assert(sizeof(struct Q2_required_alignment) == 2, "record Q2 wrong sizeof");
_Static_assert(_Alignof(struct Q2_required_alignment) == 1, "record Q2 wrong alignment");
_Static_assert(sizeof(struct Q2_size) == 3, "record Q2 wrong sizeof");
_Static_assert(_Alignof(struct Q2_size) == 1, "record Q2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(Q2,x) == 0, "field Q2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(Q2,d) == 0, "field Q2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(Q2,e) == 0, "field Q2.e wrong bit offset");
#endif
_Static_assert(sizeof(R2) == 16, "record R2 wrong sizeof");
_Static_assert(_Alignof(R2) == 16, "record R2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct R2_alignment) == 32, "record R2 wrong sizeof");
_Static_assert(_Alignof(struct R2_alignment) == 16, "record R2 wrong alignment");
_Static_assert(sizeof(struct R2_packed) == 16, "record R2 wrong sizeof");
_Static_assert(_Alignof(struct R2_packed) == 1, "record R2 wrong alignment");
_Static_assert(sizeof(struct R2_required_alignment) == 17, "record R2 wrong sizeof");
_Static_assert(_Alignof(struct R2_required_alignment) == 1, "record R2 wrong alignment");
_Static_assert(sizeof(struct R2_size) == 18, "record R2 wrong sizeof");
_Static_assert(_Alignof(struct R2_size) == 1, "record R2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(R2,x) == 0, "field R2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(R2,e) == 0, "field R2.e wrong bit offset");
#endif
_Static_assert(sizeof(S2) == 4, "record S2 wrong sizeof");
_Static_assert(_Alignof(S2) == 4, "record S2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct S2_alignment) == 8, "record S2 wrong sizeof");
_Static_assert(_Alignof(struct S2_alignment) == 4, "record S2 wrong alignment");
_Static_assert(sizeof(struct S2_packed) == 4, "record S2 wrong sizeof");
_Static_assert(_Alignof(struct S2_packed) == 1, "record S2 wrong alignment");
_Static_assert(sizeof(struct S2_required_alignment) == 5, "record S2 wrong sizeof");
_Static_assert(_Alignof(struct S2_required_alignment) == 1, "record S2 wrong alignment");
_Static_assert(sizeof(struct S2_size) == 6, "record S2 wrong sizeof");
_Static_assert(_Alignof(struct S2_size) == 1, "record S2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(S2,x) == 0, "field S2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(S2,e) == 0, "field S2.e wrong bit offset");
#endif
_Static_assert(sizeof(T2) == 4, "record T2 wrong sizeof");
_Static_assert(_Alignof(T2) == 4, "record T2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct T2_alignment) == 8, "record T2 wrong sizeof");
_Static_assert(_Alignof(struct T2_alignment) == 4, "record T2 wrong alignment");
_Static_assert(sizeof(struct T2_packed) == 4, "record T2 wrong sizeof");
_Static_assert(_Alignof(struct T2_packed) == 1, "record T2 wrong alignment");
_Static_assert(sizeof(struct T2_required_alignment) == 5, "record T2 wrong sizeof");
_Static_assert(_Alignof(struct T2_required_alignment) == 1, "record T2 wrong alignment");
_Static_assert(sizeof(struct T2_size) == 6, "record T2 wrong sizeof");
_Static_assert(_Alignof(struct T2_size) == 1, "record T2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(T2,x) == 0, "field T2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(T2,e) == 0, "field T2.e wrong bit offset");
#endif
_Static_assert(sizeof(U2) == 4, "record U2 wrong sizeof");
_Static_assert(_Alignof(U2) == 4, "record U2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct U2_alignment) == 8, "record U2 wrong sizeof");
_Static_assert(_Alignof(struct U2_alignment) == 4, "record U2 wrong alignment");
_Static_assert(sizeof(struct U2_packed) == 4, "record U2 wrong sizeof");
_Static_assert(_Alignof(struct U2_packed) == 1, "record U2 wrong alignment");
_Static_assert(sizeof(struct U2_required_alignment) == 5, "record U2 wrong sizeof");
_Static_assert(_Alignof(struct U2_required_alignment) == 1, "record U2 wrong alignment");
_Static_assert(sizeof(struct U2_size) == 6, "record U2 wrong sizeof");
_Static_assert(_Alignof(struct U2_size) == 1, "record U2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(U2,x) == 0, "field U2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(U2,e) == 0, "field U2.e wrong bit offset");
#endif
_Static_assert(sizeof(V2) == 4, "record V2 wrong sizeof");
_Static_assert(_Alignof(V2) == 4, "record V2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct V2_alignment) == 8, "record V2 wrong sizeof");
_Static_assert(_Alignof(struct V2_alignment) == 4, "record V2 wrong alignment");
_Static_assert(sizeof(struct V2_packed) == 4, "record V2 wrong sizeof");
_Static_assert(_Alignof(struct V2_packed) == 1, "record V2 wrong alignment");
_Static_assert(sizeof(struct V2_required_alignment) == 5, "record V2 wrong sizeof");
_Static_assert(_Alignof(struct V2_required_alignment) == 1, "record V2 wrong alignment");
_Static_assert(sizeof(struct V2_size) == 6, "record V2 wrong sizeof");
_Static_assert(_Alignof(struct V2_size) == 1, "record V2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(V2,x) == 0, "field V2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(V2,e) == 0, "field V2.e wrong bit offset");
#endif
_Static_assert(sizeof(W2) == 16, "record W2 wrong sizeof");
_Static_assert(_Alignof(W2) == 16, "record W2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct W2_alignment) == 32, "record W2 wrong sizeof");
_Static_assert(_Alignof(struct W2_alignment) == 16, "record W2 wrong alignment");
_Static_assert(sizeof(struct W2_packed) == 16, "record W2 wrong sizeof");
_Static_assert(_Alignof(struct W2_packed) == 1, "record W2 wrong alignment");
_Static_assert(sizeof(struct W2_required_alignment) == 17, "record W2 wrong sizeof");
_Static_assert(_Alignof(struct W2_required_alignment) == 1, "record W2 wrong alignment");
_Static_assert(sizeof(struct W2_size) == 18, "record W2 wrong sizeof");
_Static_assert(_Alignof(struct W2_size) == 1, "record W2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(W2,x) == 0, "field W2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(W2,e) == 0, "field W2.e wrong bit offset");
#endif
_Static_assert(sizeof(W_2) == 16, "record W_2 wrong sizeof");
_Static_assert(_Alignof(W_2) == 16, "record W_2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct W_2_alignment) == 32, "record W_2 wrong sizeof");
_Static_assert(_Alignof(struct W_2_alignment) == 16, "record W_2 wrong alignment");
_Static_assert(sizeof(struct W_2_packed) == 16, "record W_2 wrong sizeof");
_Static_assert(_Alignof(struct W_2_packed) == 1, "record W_2 wrong alignment");
_Static_assert(sizeof(struct W_2_required_alignment) == 17, "record W_2 wrong sizeof");
_Static_assert(_Alignof(struct W_2_required_alignment) == 1, "record W_2 wrong alignment");
_Static_assert(sizeof(struct W_2_size) == 18, "record W_2 wrong sizeof");
_Static_assert(_Alignof(struct W_2_size) == 1, "record W_2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(W_2,e) == 0, "field W_2.e wrong bit offset");
#endif
_Static_assert(sizeof(X2) == 16, "record X2 wrong sizeof");
_Static_assert(_Alignof(X2) == 16, "record X2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct X2_alignment) == 32, "record X2 wrong sizeof");
_Static_assert(_Alignof(struct X2_alignment) == 16, "record X2 wrong alignment");
_Static_assert(sizeof(struct X2_packed) == 16, "record X2 wrong sizeof");
_Static_assert(_Alignof(struct X2_packed) == 1, "record X2 wrong alignment");
_Static_assert(sizeof(struct X2_required_alignment) == 17, "record X2 wrong sizeof");
_Static_assert(_Alignof(struct X2_required_alignment) == 1, "record X2 wrong alignment");
_Static_assert(sizeof(struct X2_size) == 18, "record X2 wrong sizeof");
_Static_assert(_Alignof(struct X2_size) == 1, "record X2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(X2,x) == 0, "field X2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(X2,e) == 0, "field X2.e wrong bit offset");
#endif
_Static_assert(sizeof(Y) == 8, "record Y wrong sizeof");
_Static_assert(_Alignof(Y) == 4, "record Y wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Y_alignment) == 12, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_alignment) == 4, "record Y wrong alignment");
_Static_assert(sizeof(struct Y_packed) == 8, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_packed) == 1, "record Y wrong alignment");
_Static_assert(sizeof(struct Y_required_alignment) == 9, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_required_alignment) == 1, "record Y wrong alignment");
_Static_assert(sizeof(struct Y_size) == 10, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_size) == 1, "record Y wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(Y,d) == 32, "field Y.d wrong bit offset");
#endif
_Static_assert(sizeof(Y2) == 4, "record Y2 wrong sizeof");
_Static_assert(_Alignof(Y2) == 4, "record Y2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Y2_alignment) == 8, "record Y2 wrong sizeof");
_Static_assert(_Alignof(struct Y2_alignment) == 4, "record Y2 wrong alignment");
_Static_assert(sizeof(struct Y2_packed) == 4, "record Y2 wrong sizeof");
_Static_assert(_Alignof(struct Y2_packed) == 1, "record Y2 wrong alignment");
_Static_assert(sizeof(struct Y2_required_alignment) == 5, "record Y2 wrong sizeof");
_Static_assert(_Alignof(struct Y2_required_alignment) == 1, "record Y2 wrong alignment");
_Static_assert(sizeof(struct Y2_size) == 6, "record Y2 wrong sizeof");
_Static_assert(_Alignof(struct Y2_size) == 1, "record Y2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(Y2,d) == 0, "field Y2.d wrong bit offset");
#endif
_Static_assert(sizeof(A3) == 64, "record A3 wrong sizeof");
_Static_assert(_Alignof(A3) == 32, "record A3 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A3_alignment) == 96, "record A3 wrong sizeof");
_Static_assert(_Alignof(struct A3_alignment) == 32, "record A3 wrong alignment");
_Static_assert(sizeof(struct A3_packed) == 64, "record A3 wrong sizeof");
_Static_assert(_Alignof(struct A3_packed) == 1, "record A3 wrong alignment");
_Static_assert(sizeof(struct A3_required_alignment) == 65, "record A3 wrong sizeof");
_Static_assert(_Alignof(struct A3_required_alignment) == 1, "record A3 wrong alignment");
_Static_assert(sizeof(struct A3_size) == 66, "record A3 wrong sizeof");
_Static_assert(_Alignof(struct A3_size) == 1, "record A3 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A3,d) == 256, "field A3.d wrong bit offset");
#endif
_Static_assert(sizeof(A4) == 1, "record A4 wrong sizeof");
_Static_assert(_Alignof(A4) == 32, "record A4 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A4_alignment) == 64, "record A4 wrong sizeof");
_Static_assert(_Alignof(struct A4_alignment) == 32, "record A4 wrong alignment");
_Static_assert(sizeof(struct A4_packed) == 1, "record A4 wrong sizeof");
_Static_assert(_Alignof(struct A4_packed) == 1, "record A4 wrong alignment");
_Static_assert(sizeof(struct A4_required_alignment) == 2, "record A4 wrong sizeof");
_Static_assert(_Alignof(struct A4_required_alignment) == 1, "record A4 wrong alignment");
_Static_assert(sizeof(struct A4_size) == 3, "record A4 wrong sizeof");
_Static_assert(_Alignof(struct A4_size) == 1, "record A4 wrong alignment");
#endif
_Static_assert(sizeof(A5) == 64, "record A5 wrong sizeof");
_Static_assert(_Alignof(A5) == 32, "record A5 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A5_alignment) == 96, "record A5 wrong sizeof");
_Static_assert(_Alignof(struct A5_alignment) == 32, "record A5 wrong alignment");
_Static_assert(sizeof(struct A5_packed) == 64, "record A5 wrong sizeof");
_Static_assert(_Alignof(struct A5_packed) == 1, "record A5 wrong alignment");
_Static_assert(sizeof(struct A5_required_alignment) == 65, "record A5 wrong sizeof");
_Static_assert(_Alignof(struct A5_required_alignment) == 1, "record A5 wrong alignment");
_Static_assert(sizeof(struct A5_size) == 66, "record A5 wrong sizeof");
_Static_assert(_Alignof(struct A5_size) == 1, "record A5 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A5,d) == 256, "field A5.d wrong bit offset");
#endif
_Static_assert(sizeof(A7) == 32, "record A7 wrong sizeof");
_Static_assert(_Alignof(A7) == 32, "record A7 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A7_alignment) == 64, "record A7 wrong sizeof");
_Static_assert(_Alignof(struct A7_alignment) == 32, "record A7 wrong alignment");
_Static_assert(sizeof(struct A7_packed) == 32, "record A7 wrong sizeof");
_Static_assert(_Alignof(struct A7_packed) == 1, "record A7 wrong alignment");
_Static_assert(sizeof(struct A7_required_alignment) == 33, "record A7 wrong sizeof");
_Static_assert(_Alignof(struct A7_required_alignment) == 1, "record A7 wrong alignment");
_Static_assert(sizeof(struct A7_size) == 34, "record A7 wrong sizeof");
_Static_assert(_Alignof(struct A7_size) == 1, "record A7 wrong alignment");
#endif
_Static_assert(sizeof(A8) == 6, "record A8 wrong sizeof");
_Static_assert(_Alignof(A8) == 1, "record A8 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A8_alignment) == 7, "record A8 wrong sizeof");
_Static_assert(_Alignof(struct A8_alignment) == 1, "record A8 wrong alignment");
_Static_assert(sizeof(struct A8_packed) == 6, "record A8 wrong sizeof");
_Static_assert(_Alignof(struct A8_packed) == 1, "record A8 wrong alignment");
_Static_assert(sizeof(struct A8_required_alignment) == 7, "record A8 wrong sizeof");
_Static_assert(_Alignof(struct A8_required_alignment) == 1, "record A8 wrong alignment");
_Static_assert(sizeof(struct A8_size) == 8, "record A8 wrong sizeof");
_Static_assert(_Alignof(struct A8_size) == 1, "record A8 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A8,i) == 8, "field A8.i wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A8,j) == 39, "field A8.j wrong bit offset");
#endif
_Static_assert(sizeof(A9) == 12, "record A9 wrong sizeof");
_Static_assert(_Alignof(A9) == 4, "record A9 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A9_alignment) == 16, "record A9 wrong sizeof");
_Static_assert(_Alignof(struct A9_alignment) == 4, "record A9 wrong alignment");
_Static_assert(sizeof(struct A9_packed) == 12, "record A9 wrong sizeof");
_Static_assert(_Alignof(struct A9_packed) == 1, "record A9 wrong alignment");
_Static_assert(sizeof(struct A9_required_alignment) == 13, "record A9 wrong sizeof");
_Static_assert(_Alignof(struct A9_required_alignment) == 1, "record A9 wrong alignment");
_Static_assert(sizeof(struct A9_size) == 14, "record A9 wrong sizeof");
_Static_assert(_Alignof(struct A9_size) == 1, "record A9 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A9,i) == 8, "field A9.i wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A9,j) == 64, "field A9.j wrong bit offset");
#endif
_Static_assert(sizeof(A10) == 4, "record A10 wrong sizeof");
_Static_assert(_Alignof(A10) == 16, "record A10 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A10_alignment) == 32, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_alignment) == 16, "record A10 wrong alignment");
_Static_assert(sizeof(struct A10_packed) == 4, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_packed) == 1, "record A10 wrong alignment");
_Static_assert(sizeof(struct A10_required_alignment) == 5, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_required_alignment) == 1, "record A10 wrong alignment");
_Static_assert(sizeof(struct A10_size) == 6, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_size) == 1, "record A10 wrong alignment");
#endif
_Static_assert(sizeof(A11) == 6, "record A11 wrong sizeof");
_Static_assert(_Alignof(A11) == 1, "record A11 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A11_alignment) == 7, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_alignment) == 1, "record A11 wrong alignment");
_Static_assert(sizeof(struct A11_packed) == 6, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_packed) == 1, "record A11 wrong alignment");
_Static_assert(sizeof(struct A11_required_alignment) == 7, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_required_alignment) == 1, "record A11 wrong alignment");
_Static_assert(sizeof(struct A11_size) == 8, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_size) == 1, "record A11 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A11,i) == 8, "field A11.i wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A11,j) == 39, "field A11.j wrong bit offset");
#endif
_Static_assert(sizeof(A12) == 32, "record A12 wrong sizeof");
_Static_assert(_Alignof(A12) == 16, "record A12 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A12_alignment) == 48, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_alignment) == 16, "record A12 wrong alignment");
_Static_assert(sizeof(struct A12_packed) == 32, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_packed) == 1, "record A12 wrong alignment");
_Static_assert(sizeof(struct A12_required_alignment) == 33, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_required_alignment) == 1, "record A12 wrong alignment");
_Static_assert(sizeof(struct A12_size) == 34, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_size) == 1, "record A12 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A12,i) == 8, "field A12.i wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A12,j) == 128, "field A12.j wrong bit offset");
#endif
_Static_assert(sizeof(A13) == 32, "record A13 wrong sizeof");
_Static_assert(_Alignof(A13) == 16, "record A13 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A13_alignment) == 48, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_alignment) == 16, "record A13 wrong alignment");
_Static_assert(sizeof(struct A13_packed) == 32, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_packed) == 1, "record A13 wrong alignment");
_Static_assert(sizeof(struct A13_required_alignment) == 33, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_required_alignment) == 1, "record A13 wrong alignment");
_Static_assert(sizeof(struct A13_size) == 34, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_size) == 1, "record A13 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A13,i) == 8, "field A13.i wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A13,j) == 128, "field A13.j wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A13,d) == 136, "field A13.d wrong bit offset");
#endif
// MAPPING|SEVEN|avr-atmega328-other-gnu:Gcc|END
// repr targets AvrUnknownUnknown|Some("avr-atmega328-other-gnu") 
#elif defined(SEVEN)
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
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A,d) == 0, "field A.d wrong bit offset");
#endif
_Static_assert(sizeof(A_) == 8, "record A_ wrong sizeof");
_Static_assert(_Alignof(A_) == 4, "record A_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A__alignment) == 12, "record A_ wrong sizeof");
_Static_assert(_Alignof(struct A__alignment) == 4, "record A_ wrong alignment");
_Static_assert(sizeof(struct A__packed) == 8, "record A_ wrong sizeof");
_Static_assert(_Alignof(struct A__packed) == 1, "record A_ wrong alignment");
_Static_assert(sizeof(struct A__required_alignment) == 9, "record A_ wrong sizeof");
_Static_assert(_Alignof(struct A__required_alignment) == 1, "record A_ wrong alignment");
_Static_assert(sizeof(struct A__size) == 10, "record A_ wrong sizeof");
_Static_assert(_Alignof(struct A__size) == 1, "record A_ wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_,d) == 32, "field A_.d wrong bit offset");
#endif
_Static_assert(sizeof(B) == 4, "record B wrong sizeof");
_Static_assert(_Alignof(B) == 4, "record B wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 8, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_alignment) == 4, "record B wrong alignment");
_Static_assert(sizeof(struct B_packed) == 4, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_packed) == 1, "record B wrong alignment");
_Static_assert(sizeof(struct B_required_alignment) == 5, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "record B wrong alignment");
_Static_assert(sizeof(struct B_size) == 6, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_size) == 1, "record B wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B,d) == 0, "field B.d wrong bit offset");
#endif
_Static_assert(sizeof(B_) == 8, "record B_ wrong sizeof");
_Static_assert(_Alignof(B_) == 4, "record B_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B__alignment) == 12, "record B_ wrong sizeof");
_Static_assert(_Alignof(struct B__alignment) == 4, "record B_ wrong alignment");
_Static_assert(sizeof(struct B__packed) == 8, "record B_ wrong sizeof");
_Static_assert(_Alignof(struct B__packed) == 1, "record B_ wrong alignment");
_Static_assert(sizeof(struct B__required_alignment) == 9, "record B_ wrong sizeof");
_Static_assert(_Alignof(struct B__required_alignment) == 1, "record B_ wrong alignment");
_Static_assert(sizeof(struct B__size) == 10, "record B_ wrong sizeof");
_Static_assert(_Alignof(struct B__size) == 1, "record B_ wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B_,d) == 32, "field B_.d wrong bit offset");
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
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C,d) == 0, "field C.d wrong bit offset");
#endif
_Static_assert(sizeof(C_) == 2, "record C_ wrong sizeof");
_Static_assert(_Alignof(C_) == 1, "record C_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C__alignment) == 3, "record C_ wrong sizeof");
_Static_assert(_Alignof(struct C__alignment) == 1, "record C_ wrong alignment");
_Static_assert(sizeof(struct C__packed) == 2, "record C_ wrong sizeof");
_Static_assert(_Alignof(struct C__packed) == 1, "record C_ wrong alignment");
_Static_assert(sizeof(struct C__required_alignment) == 3, "record C_ wrong sizeof");
_Static_assert(_Alignof(struct C__required_alignment) == 1, "record C_ wrong alignment");
_Static_assert(sizeof(struct C__size) == 4, "record C_ wrong sizeof");
_Static_assert(_Alignof(struct C__size) == 1, "record C_ wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C_,d) == 8, "field C_.d wrong bit offset");
#endif
_Static_assert(sizeof(D) == 10, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 1, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 11, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_packed) == 10, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 11, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_size) == 12, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_size) == 1, "record D wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D,d) == 8, "field D.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(D,e) == 72, "field D.e wrong bit offset");
#endif
_Static_assert(sizeof(F) == 32, "record F wrong sizeof");
_Static_assert(_Alignof(F) == 16, "record F wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 48, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_alignment) == 16, "record F wrong alignment");
_Static_assert(sizeof(struct F_packed) == 32, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_packed) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_required_alignment) == 33, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_size) == 34, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_size) == 1, "record F wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F,d) == 128, "field F.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(F,e) == 192, "field F.e wrong bit offset");
#endif
_Static_assert(sizeof(G) == 12, "record G wrong sizeof");
_Static_assert(_Alignof(G) == 2, "record G wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 14, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_alignment) == 2, "record G wrong alignment");
_Static_assert(sizeof(struct G_packed) == 12, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_packed) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_required_alignment) == 13, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_size) == 14, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_size) == 1, "record G wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(G,d) == 16, "field G.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(G,e) == 80, "field G.e wrong bit offset");
#endif
_Static_assert(sizeof(H) == 12, "record H wrong sizeof");
_Static_assert(_Alignof(H) == 2, "record H wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 14, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_alignment) == 2, "record H wrong alignment");
_Static_assert(sizeof(struct H_packed) == 12, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_packed) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_required_alignment) == 13, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_size) == 14, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_size) == 1, "record H wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(H,d) == 16, "field H.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(H,e) == 80, "field H.e wrong bit offset");
#endif
_Static_assert(sizeof(I) == 10, "record I wrong sizeof");
_Static_assert(_Alignof(I) == 1, "record I wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I_alignment) == 11, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_alignment) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_packed) == 10, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_packed) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_required_alignment) == 11, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_required_alignment) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_size) == 12, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_size) == 1, "record I wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(I,d) == 8, "field I.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(I,e) == 72, "field I.e wrong bit offset");
#endif
_Static_assert(sizeof(J) == 10, "record J wrong sizeof");
_Static_assert(_Alignof(J) == 1, "record J wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J_alignment) == 11, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_alignment) == 1, "record J wrong alignment");
_Static_assert(sizeof(struct J_packed) == 10, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_packed) == 1, "record J wrong alignment");
_Static_assert(sizeof(struct J_required_alignment) == 11, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_required_alignment) == 1, "record J wrong alignment");
_Static_assert(sizeof(struct J_size) == 12, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_size) == 1, "record J wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(J,d) == 8, "field J.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(J,e) == 72, "field J.e wrong bit offset");
#endif
_Static_assert(sizeof(K) == 3, "record K wrong sizeof");
_Static_assert(_Alignof(K) == 1, "record K wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct K_alignment) == 4, "record K wrong sizeof");
_Static_assert(_Alignof(struct K_alignment) == 1, "record K wrong alignment");
_Static_assert(sizeof(struct K_packed) == 3, "record K wrong sizeof");
_Static_assert(_Alignof(struct K_packed) == 1, "record K wrong alignment");
_Static_assert(sizeof(struct K_required_alignment) == 4, "record K wrong sizeof");
_Static_assert(_Alignof(struct K_required_alignment) == 1, "record K wrong alignment");
_Static_assert(sizeof(struct K_size) == 5, "record K wrong sizeof");
_Static_assert(_Alignof(struct K_size) == 1, "record K wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(K,d) == 8, "field K.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(K,e) == 16, "field K.e wrong bit offset");
#endif
_Static_assert(sizeof(L) == 32, "record L wrong sizeof");
_Static_assert(_Alignof(L) == 16, "record L wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct L_alignment) == 48, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_alignment) == 16, "record L wrong alignment");
_Static_assert(sizeof(struct L_packed) == 32, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_packed) == 1, "record L wrong alignment");
_Static_assert(sizeof(struct L_required_alignment) == 33, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_required_alignment) == 1, "record L wrong alignment");
_Static_assert(sizeof(struct L_size) == 34, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_size) == 1, "record L wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(L,d) == 128, "field L.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(L,e) == 136, "field L.e wrong bit offset");
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
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(M,d) == 16, "field M.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(M,e) == 24, "field M.e wrong bit offset");
#endif
_Static_assert(sizeof(N) == 4, "record N wrong sizeof");
_Static_assert(_Alignof(N) == 2, "record N wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct N_alignment) == 6, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_alignment) == 2, "record N wrong alignment");
_Static_assert(sizeof(struct N_packed) == 4, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_packed) == 1, "record N wrong alignment");
_Static_assert(sizeof(struct N_required_alignment) == 5, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_required_alignment) == 1, "record N wrong alignment");
_Static_assert(sizeof(struct N_size) == 6, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_size) == 1, "record N wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(N,d) == 16, "field N.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(N,e) == 24, "field N.e wrong bit offset");
#endif
_Static_assert(sizeof(O) == 3, "record O wrong sizeof");
_Static_assert(_Alignof(O) == 1, "record O wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct O_alignment) == 4, "record O wrong sizeof");
_Static_assert(_Alignof(struct O_alignment) == 1, "record O wrong alignment");
_Static_assert(sizeof(struct O_packed) == 3, "record O wrong sizeof");
_Static_assert(_Alignof(struct O_packed) == 1, "record O wrong alignment");
_Static_assert(sizeof(struct O_required_alignment) == 4, "record O wrong sizeof");
_Static_assert(_Alignof(struct O_required_alignment) == 1, "record O wrong alignment");
_Static_assert(sizeof(struct O_size) == 5, "record O wrong sizeof");
_Static_assert(_Alignof(struct O_size) == 1, "record O wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(O,d) == 8, "field O.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(O,e) == 16, "field O.e wrong bit offset");
#endif
_Static_assert(sizeof(P) == 3, "record P wrong sizeof");
_Static_assert(_Alignof(P) == 1, "record P wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct P_alignment) == 4, "record P wrong sizeof");
_Static_assert(_Alignof(struct P_alignment) == 1, "record P wrong alignment");
_Static_assert(sizeof(struct P_packed) == 3, "record P wrong sizeof");
_Static_assert(_Alignof(struct P_packed) == 1, "record P wrong alignment");
_Static_assert(sizeof(struct P_required_alignment) == 4, "record P wrong sizeof");
_Static_assert(_Alignof(struct P_required_alignment) == 1, "record P wrong alignment");
_Static_assert(sizeof(struct P_size) == 5, "record P wrong sizeof");
_Static_assert(_Alignof(struct P_size) == 1, "record P wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(P,d) == 8, "field P.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(P,e) == 16, "field P.e wrong bit offset");
#endif
_Static_assert(sizeof(Q) == 3, "record Q wrong sizeof");
_Static_assert(_Alignof(Q) == 1, "record Q wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Q_alignment) == 4, "record Q wrong sizeof");
_Static_assert(_Alignof(struct Q_alignment) == 1, "record Q wrong alignment");
_Static_assert(sizeof(struct Q_packed) == 3, "record Q wrong sizeof");
_Static_assert(_Alignof(struct Q_packed) == 1, "record Q wrong alignment");
_Static_assert(sizeof(struct Q_required_alignment) == 4, "record Q wrong sizeof");
_Static_assert(_Alignof(struct Q_required_alignment) == 1, "record Q wrong alignment");
_Static_assert(sizeof(struct Q_size) == 5, "record Q wrong sizeof");
_Static_assert(_Alignof(struct Q_size) == 1, "record Q wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(Q,x) == 8, "field Q.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(Q,d) == 9, "field Q.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(Q,e) == 16, "field Q.e wrong bit offset");
#endif
_Static_assert(sizeof(R) == 32, "record R wrong sizeof");
_Static_assert(_Alignof(R) == 16, "record R wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct R_alignment) == 48, "record R wrong sizeof");
_Static_assert(_Alignof(struct R_alignment) == 16, "record R wrong alignment");
_Static_assert(sizeof(struct R_packed) == 32, "record R wrong sizeof");
_Static_assert(_Alignof(struct R_packed) == 1, "record R wrong alignment");
_Static_assert(sizeof(struct R_required_alignment) == 33, "record R wrong sizeof");
_Static_assert(_Alignof(struct R_required_alignment) == 1, "record R wrong alignment");
_Static_assert(sizeof(struct R_size) == 34, "record R wrong sizeof");
_Static_assert(_Alignof(struct R_size) == 1, "record R wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(R,x) == 8, "field R.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(R,e) == 128, "field R.e wrong bit offset");
#endif
_Static_assert(sizeof(S) == 4, "record S wrong sizeof");
_Static_assert(_Alignof(S) == 2, "record S wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct S_alignment) == 6, "record S wrong sizeof");
_Static_assert(_Alignof(struct S_alignment) == 2, "record S wrong alignment");
_Static_assert(sizeof(struct S_packed) == 4, "record S wrong sizeof");
_Static_assert(_Alignof(struct S_packed) == 1, "record S wrong alignment");
_Static_assert(sizeof(struct S_required_alignment) == 5, "record S wrong sizeof");
_Static_assert(_Alignof(struct S_required_alignment) == 1, "record S wrong alignment");
_Static_assert(sizeof(struct S_size) == 6, "record S wrong sizeof");
_Static_assert(_Alignof(struct S_size) == 1, "record S wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(S,x) == 8, "field S.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(S,e) == 16, "field S.e wrong bit offset");
#endif
_Static_assert(sizeof(T) == 8, "record T wrong sizeof");
_Static_assert(_Alignof(T) == 4, "record T wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct T_alignment) == 12, "record T wrong sizeof");
_Static_assert(_Alignof(struct T_alignment) == 4, "record T wrong alignment");
_Static_assert(sizeof(struct T_packed) == 8, "record T wrong sizeof");
_Static_assert(_Alignof(struct T_packed) == 1, "record T wrong alignment");
_Static_assert(sizeof(struct T_required_alignment) == 9, "record T wrong sizeof");
_Static_assert(_Alignof(struct T_required_alignment) == 1, "record T wrong alignment");
_Static_assert(sizeof(struct T_size) == 10, "record T wrong sizeof");
_Static_assert(_Alignof(struct T_size) == 1, "record T wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(T,x) == 8, "field T.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(T,e) == 32, "field T.e wrong bit offset");
#endif
_Static_assert(sizeof(U) == 3, "record U wrong sizeof");
_Static_assert(_Alignof(U) == 1, "record U wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct U_alignment) == 4, "record U wrong sizeof");
_Static_assert(_Alignof(struct U_alignment) == 1, "record U wrong alignment");
_Static_assert(sizeof(struct U_packed) == 3, "record U wrong sizeof");
_Static_assert(_Alignof(struct U_packed) == 1, "record U wrong alignment");
_Static_assert(sizeof(struct U_required_alignment) == 4, "record U wrong sizeof");
_Static_assert(_Alignof(struct U_required_alignment) == 1, "record U wrong alignment");
_Static_assert(sizeof(struct U_size) == 5, "record U wrong sizeof");
_Static_assert(_Alignof(struct U_size) == 1, "record U wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(U,x) == 8, "field U.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(U,e) == 16, "field U.e wrong bit offset");
#endif
_Static_assert(sizeof(V) == 3, "record V wrong sizeof");
_Static_assert(_Alignof(V) == 1, "record V wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct V_alignment) == 4, "record V wrong sizeof");
_Static_assert(_Alignof(struct V_alignment) == 1, "record V wrong alignment");
_Static_assert(sizeof(struct V_packed) == 3, "record V wrong sizeof");
_Static_assert(_Alignof(struct V_packed) == 1, "record V wrong alignment");
_Static_assert(sizeof(struct V_required_alignment) == 4, "record V wrong sizeof");
_Static_assert(_Alignof(struct V_required_alignment) == 1, "record V wrong alignment");
_Static_assert(sizeof(struct V_size) == 5, "record V wrong sizeof");
_Static_assert(_Alignof(struct V_size) == 1, "record V wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(V,x) == 8, "field V.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(V,e) == 16, "field V.e wrong bit offset");
#endif
_Static_assert(sizeof(W) == 32, "record W wrong sizeof");
_Static_assert(_Alignof(W) == 16, "record W wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct W_alignment) == 48, "record W wrong sizeof");
_Static_assert(_Alignof(struct W_alignment) == 16, "record W wrong alignment");
_Static_assert(sizeof(struct W_packed) == 32, "record W wrong sizeof");
_Static_assert(_Alignof(struct W_packed) == 1, "record W wrong alignment");
_Static_assert(sizeof(struct W_required_alignment) == 33, "record W wrong sizeof");
_Static_assert(_Alignof(struct W_required_alignment) == 1, "record W wrong alignment");
_Static_assert(sizeof(struct W_size) == 34, "record W wrong sizeof");
_Static_assert(_Alignof(struct W_size) == 1, "record W wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(W,x) == 8, "field W.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(W,e) == 128, "field W.e wrong bit offset");
#endif
_Static_assert(sizeof(W_) == 32, "record W_ wrong sizeof");
_Static_assert(_Alignof(W_) == 16, "record W_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct W__alignment) == 48, "record W_ wrong sizeof");
_Static_assert(_Alignof(struct W__alignment) == 16, "record W_ wrong alignment");
_Static_assert(sizeof(struct W__packed) == 32, "record W_ wrong sizeof");
_Static_assert(_Alignof(struct W__packed) == 1, "record W_ wrong alignment");
_Static_assert(sizeof(struct W__required_alignment) == 33, "record W_ wrong sizeof");
_Static_assert(_Alignof(struct W__required_alignment) == 1, "record W_ wrong alignment");
_Static_assert(sizeof(struct W__size) == 34, "record W_ wrong sizeof");
_Static_assert(_Alignof(struct W__size) == 1, "record W_ wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(W_,e) == 128, "field W_.e wrong bit offset");
#endif
_Static_assert(sizeof(X) == 32, "record X wrong sizeof");
_Static_assert(_Alignof(X) == 16, "record X wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct X_alignment) == 48, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_alignment) == 16, "record X wrong alignment");
_Static_assert(sizeof(struct X_packed) == 32, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_packed) == 1, "record X wrong alignment");
_Static_assert(sizeof(struct X_required_alignment) == 33, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_required_alignment) == 1, "record X wrong alignment");
_Static_assert(sizeof(struct X_size) == 34, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_size) == 1, "record X wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(X,x) == 8, "field X.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(X,e) == 128, "field X.e wrong bit offset");
#endif
_Static_assert(sizeof(A2) == 4, "record A2 wrong sizeof");
_Static_assert(_Alignof(A2) == 4, "record A2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A2_alignment) == 8, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_alignment) == 4, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_packed) == 4, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_packed) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_required_alignment) == 5, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_required_alignment) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_size) == 6, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_size) == 1, "record A2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A2,d) == 0, "field A2.d wrong bit offset");
#endif
_Static_assert(sizeof(A_2) == 4, "record A_2 wrong sizeof");
_Static_assert(_Alignof(A_2) == 4, "record A_2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_2_alignment) == 8, "record A_2 wrong sizeof");
_Static_assert(_Alignof(struct A_2_alignment) == 4, "record A_2 wrong alignment");
_Static_assert(sizeof(struct A_2_packed) == 4, "record A_2 wrong sizeof");
_Static_assert(_Alignof(struct A_2_packed) == 1, "record A_2 wrong alignment");
_Static_assert(sizeof(struct A_2_required_alignment) == 5, "record A_2 wrong sizeof");
_Static_assert(_Alignof(struct A_2_required_alignment) == 1, "record A_2 wrong alignment");
_Static_assert(sizeof(struct A_2_size) == 6, "record A_2 wrong sizeof");
_Static_assert(_Alignof(struct A_2_size) == 1, "record A_2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_2,d) == 0, "field A_2.d wrong bit offset");
#endif
_Static_assert(sizeof(B2) == 4, "record B2 wrong sizeof");
_Static_assert(_Alignof(B2) == 4, "record B2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B2_alignment) == 8, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_alignment) == 4, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_packed) == 4, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_packed) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_required_alignment) == 5, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_required_alignment) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_size) == 6, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_size) == 1, "record B2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B2,d) == 0, "field B2.d wrong bit offset");
#endif
_Static_assert(sizeof(B_2) == 4, "record B_2 wrong sizeof");
_Static_assert(_Alignof(B_2) == 4, "record B_2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_2_alignment) == 8, "record B_2 wrong sizeof");
_Static_assert(_Alignof(struct B_2_alignment) == 4, "record B_2 wrong alignment");
_Static_assert(sizeof(struct B_2_packed) == 4, "record B_2 wrong sizeof");
_Static_assert(_Alignof(struct B_2_packed) == 1, "record B_2 wrong alignment");
_Static_assert(sizeof(struct B_2_required_alignment) == 5, "record B_2 wrong sizeof");
_Static_assert(_Alignof(struct B_2_required_alignment) == 1, "record B_2 wrong alignment");
_Static_assert(sizeof(struct B_2_size) == 6, "record B_2 wrong sizeof");
_Static_assert(_Alignof(struct B_2_size) == 1, "record B_2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B_2,d) == 0, "field B_2.d wrong bit offset");
#endif
_Static_assert(sizeof(C2) == 1, "record C2 wrong sizeof");
_Static_assert(_Alignof(C2) == 1, "record C2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C2_alignment) == 2, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_alignment) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_packed) == 1, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_packed) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_required_alignment) == 2, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_required_alignment) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_size) == 3, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_size) == 1, "record C2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C2,d) == 0, "field C2.d wrong bit offset");
#endif
_Static_assert(sizeof(C22) == 1, "record C22 wrong sizeof");
_Static_assert(_Alignof(C22) == 1, "record C22 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C22_alignment) == 2, "record C22 wrong sizeof");
_Static_assert(_Alignof(struct C22_alignment) == 1, "record C22 wrong alignment");
_Static_assert(sizeof(struct C22_packed) == 1, "record C22 wrong sizeof");
_Static_assert(_Alignof(struct C22_packed) == 1, "record C22 wrong alignment");
_Static_assert(sizeof(struct C22_required_alignment) == 2, "record C22 wrong sizeof");
_Static_assert(_Alignof(struct C22_required_alignment) == 1, "record C22 wrong alignment");
_Static_assert(sizeof(struct C22_size) == 3, "record C22 wrong sizeof");
_Static_assert(_Alignof(struct C22_size) == 1, "record C22 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C22,d) == 0, "field C22.d wrong bit offset");
#endif
_Static_assert(sizeof(D2) == 8, "record D2 wrong sizeof");
_Static_assert(_Alignof(D2) == 1, "record D2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D2_alignment) == 9, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_alignment) == 1, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_packed) == 8, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_packed) == 1, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_required_alignment) == 9, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_required_alignment) == 1, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_size) == 10, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_size) == 1, "record D2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D2,d) == 0, "field D2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(D2,e) == 0, "field D2.e wrong bit offset");
#endif
_Static_assert(sizeof(F2) == 16, "record F2 wrong sizeof");
_Static_assert(_Alignof(F2) == 16, "record F2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F2_alignment) == 32, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_alignment) == 16, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_packed) == 16, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_packed) == 1, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_required_alignment) == 17, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_required_alignment) == 1, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_size) == 18, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_size) == 1, "record F2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F2,d) == 0, "field F2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(F2,e) == 0, "field F2.e wrong bit offset");
#endif
_Static_assert(sizeof(G2) == 8, "record G2 wrong sizeof");
_Static_assert(_Alignof(G2) == 2, "record G2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G2_alignment) == 10, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_alignment) == 2, "record G2 wrong alignment");
_Static_assert(sizeof(struct G2_packed) == 8, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_packed) == 1, "record G2 wrong alignment");
_Static_assert(sizeof(struct G2_required_alignment) == 9, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_required_alignment) == 1, "record G2 wrong alignment");
_Static_assert(sizeof(struct G2_size) == 10, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_size) == 1, "record G2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(G2,d) == 0, "field G2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(G2,e) == 0, "field G2.e wrong bit offset");
#endif
_Static_assert(sizeof(H2) == 8, "record H2 wrong sizeof");
_Static_assert(_Alignof(H2) == 2, "record H2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H2_alignment) == 10, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_alignment) == 2, "record H2 wrong alignment");
_Static_assert(sizeof(struct H2_packed) == 8, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_packed) == 1, "record H2 wrong alignment");
_Static_assert(sizeof(struct H2_required_alignment) == 9, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_required_alignment) == 1, "record H2 wrong alignment");
_Static_assert(sizeof(struct H2_size) == 10, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_size) == 1, "record H2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(H2,d) == 0, "field H2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(H2,e) == 0, "field H2.e wrong bit offset");
#endif
_Static_assert(sizeof(I2) == 8, "record I2 wrong sizeof");
_Static_assert(_Alignof(I2) == 1, "record I2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I2_alignment) == 9, "record I2 wrong sizeof");
_Static_assert(_Alignof(struct I2_alignment) == 1, "record I2 wrong alignment");
_Static_assert(sizeof(struct I2_packed) == 8, "record I2 wrong sizeof");
_Static_assert(_Alignof(struct I2_packed) == 1, "record I2 wrong alignment");
_Static_assert(sizeof(struct I2_required_alignment) == 9, "record I2 wrong sizeof");
_Static_assert(_Alignof(struct I2_required_alignment) == 1, "record I2 wrong alignment");
_Static_assert(sizeof(struct I2_size) == 10, "record I2 wrong sizeof");
_Static_assert(_Alignof(struct I2_size) == 1, "record I2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(I2,d) == 0, "field I2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(I2,e) == 0, "field I2.e wrong bit offset");
#endif
_Static_assert(sizeof(J2) == 8, "record J2 wrong sizeof");
_Static_assert(_Alignof(J2) == 1, "record J2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J2_alignment) == 9, "record J2 wrong sizeof");
_Static_assert(_Alignof(struct J2_alignment) == 1, "record J2 wrong alignment");
_Static_assert(sizeof(struct J2_packed) == 8, "record J2 wrong sizeof");
_Static_assert(_Alignof(struct J2_packed) == 1, "record J2 wrong alignment");
_Static_assert(sizeof(struct J2_required_alignment) == 9, "record J2 wrong sizeof");
_Static_assert(_Alignof(struct J2_required_alignment) == 1, "record J2 wrong alignment");
_Static_assert(sizeof(struct J2_size) == 10, "record J2 wrong sizeof");
_Static_assert(_Alignof(struct J2_size) == 1, "record J2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(J2,d) == 0, "field J2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(J2,e) == 0, "field J2.e wrong bit offset");
#endif
_Static_assert(sizeof(K2) == 1, "record K2 wrong sizeof");
_Static_assert(_Alignof(K2) == 1, "record K2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct K2_alignment) == 2, "record K2 wrong sizeof");
_Static_assert(_Alignof(struct K2_alignment) == 1, "record K2 wrong alignment");
_Static_assert(sizeof(struct K2_packed) == 1, "record K2 wrong sizeof");
_Static_assert(_Alignof(struct K2_packed) == 1, "record K2 wrong alignment");
_Static_assert(sizeof(struct K2_required_alignment) == 2, "record K2 wrong sizeof");
_Static_assert(_Alignof(struct K2_required_alignment) == 1, "record K2 wrong alignment");
_Static_assert(sizeof(struct K2_size) == 3, "record K2 wrong sizeof");
_Static_assert(_Alignof(struct K2_size) == 1, "record K2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(K2,d) == 0, "field K2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(K2,e) == 0, "field K2.e wrong bit offset");
#endif
_Static_assert(sizeof(L2) == 16, "record L2 wrong sizeof");
_Static_assert(_Alignof(L2) == 16, "record L2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct L2_alignment) == 32, "record L2 wrong sizeof");
_Static_assert(_Alignof(struct L2_alignment) == 16, "record L2 wrong alignment");
_Static_assert(sizeof(struct L2_packed) == 16, "record L2 wrong sizeof");
_Static_assert(_Alignof(struct L2_packed) == 1, "record L2 wrong alignment");
_Static_assert(sizeof(struct L2_required_alignment) == 17, "record L2 wrong sizeof");
_Static_assert(_Alignof(struct L2_required_alignment) == 1, "record L2 wrong alignment");
_Static_assert(sizeof(struct L2_size) == 18, "record L2 wrong sizeof");
_Static_assert(_Alignof(struct L2_size) == 1, "record L2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(L2,d) == 0, "field L2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(L2,e) == 0, "field L2.e wrong bit offset");
#endif
_Static_assert(sizeof(M2) == 2, "record M2 wrong sizeof");
_Static_assert(_Alignof(M2) == 2, "record M2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct M2_alignment) == 4, "record M2 wrong sizeof");
_Static_assert(_Alignof(struct M2_alignment) == 2, "record M2 wrong alignment");
_Static_assert(sizeof(struct M2_packed) == 2, "record M2 wrong sizeof");
_Static_assert(_Alignof(struct M2_packed) == 1, "record M2 wrong alignment");
_Static_assert(sizeof(struct M2_required_alignment) == 3, "record M2 wrong sizeof");
_Static_assert(_Alignof(struct M2_required_alignment) == 1, "record M2 wrong alignment");
_Static_assert(sizeof(struct M2_size) == 4, "record M2 wrong sizeof");
_Static_assert(_Alignof(struct M2_size) == 1, "record M2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(M2,d) == 0, "field M2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(M2,e) == 0, "field M2.e wrong bit offset");
#endif
_Static_assert(sizeof(N2) == 2, "record N2 wrong sizeof");
_Static_assert(_Alignof(N2) == 2, "record N2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct N2_alignment) == 4, "record N2 wrong sizeof");
_Static_assert(_Alignof(struct N2_alignment) == 2, "record N2 wrong alignment");
_Static_assert(sizeof(struct N2_packed) == 2, "record N2 wrong sizeof");
_Static_assert(_Alignof(struct N2_packed) == 1, "record N2 wrong alignment");
_Static_assert(sizeof(struct N2_required_alignment) == 3, "record N2 wrong sizeof");
_Static_assert(_Alignof(struct N2_required_alignment) == 1, "record N2 wrong alignment");
_Static_assert(sizeof(struct N2_size) == 4, "record N2 wrong sizeof");
_Static_assert(_Alignof(struct N2_size) == 1, "record N2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(N2,d) == 0, "field N2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(N2,e) == 0, "field N2.e wrong bit offset");
#endif
_Static_assert(sizeof(O2) == 1, "record O2 wrong sizeof");
_Static_assert(_Alignof(O2) == 1, "record O2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct O2_alignment) == 2, "record O2 wrong sizeof");
_Static_assert(_Alignof(struct O2_alignment) == 1, "record O2 wrong alignment");
_Static_assert(sizeof(struct O2_packed) == 1, "record O2 wrong sizeof");
_Static_assert(_Alignof(struct O2_packed) == 1, "record O2 wrong alignment");
_Static_assert(sizeof(struct O2_required_alignment) == 2, "record O2 wrong sizeof");
_Static_assert(_Alignof(struct O2_required_alignment) == 1, "record O2 wrong alignment");
_Static_assert(sizeof(struct O2_size) == 3, "record O2 wrong sizeof");
_Static_assert(_Alignof(struct O2_size) == 1, "record O2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(O2,d) == 0, "field O2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(O2,e) == 0, "field O2.e wrong bit offset");
#endif
_Static_assert(sizeof(P2) == 1, "record P2 wrong sizeof");
_Static_assert(_Alignof(P2) == 1, "record P2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct P2_alignment) == 2, "record P2 wrong sizeof");
_Static_assert(_Alignof(struct P2_alignment) == 1, "record P2 wrong alignment");
_Static_assert(sizeof(struct P2_packed) == 1, "record P2 wrong sizeof");
_Static_assert(_Alignof(struct P2_packed) == 1, "record P2 wrong alignment");
_Static_assert(sizeof(struct P2_required_alignment) == 2, "record P2 wrong sizeof");
_Static_assert(_Alignof(struct P2_required_alignment) == 1, "record P2 wrong alignment");
_Static_assert(sizeof(struct P2_size) == 3, "record P2 wrong sizeof");
_Static_assert(_Alignof(struct P2_size) == 1, "record P2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(P2,d) == 0, "field P2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(P2,e) == 0, "field P2.e wrong bit offset");
#endif
_Static_assert(sizeof(Q2) == 1, "record Q2 wrong sizeof");
_Static_assert(_Alignof(Q2) == 1, "record Q2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Q2_alignment) == 2, "record Q2 wrong sizeof");
_Static_assert(_Alignof(struct Q2_alignment) == 1, "record Q2 wrong alignment");
_Static_assert(sizeof(struct Q2_packed) == 1, "record Q2 wrong sizeof");
_Static_assert(_Alignof(struct Q2_packed) == 1, "record Q2 wrong alignment");
_Static_assert(sizeof(struct Q2_required_alignment) == 2, "record Q2 wrong sizeof");
_Static_assert(_Alignof(struct Q2_required_alignment) == 1, "record Q2 wrong alignment");
_Static_assert(sizeof(struct Q2_size) == 3, "record Q2 wrong sizeof");
_Static_assert(_Alignof(struct Q2_size) == 1, "record Q2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(Q2,x) == 0, "field Q2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(Q2,d) == 0, "field Q2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(Q2,e) == 0, "field Q2.e wrong bit offset");
#endif
_Static_assert(sizeof(R2) == 16, "record R2 wrong sizeof");
_Static_assert(_Alignof(R2) == 16, "record R2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct R2_alignment) == 32, "record R2 wrong sizeof");
_Static_assert(_Alignof(struct R2_alignment) == 16, "record R2 wrong alignment");
_Static_assert(sizeof(struct R2_packed) == 16, "record R2 wrong sizeof");
_Static_assert(_Alignof(struct R2_packed) == 1, "record R2 wrong alignment");
_Static_assert(sizeof(struct R2_required_alignment) == 17, "record R2 wrong sizeof");
_Static_assert(_Alignof(struct R2_required_alignment) == 1, "record R2 wrong alignment");
_Static_assert(sizeof(struct R2_size) == 18, "record R2 wrong sizeof");
_Static_assert(_Alignof(struct R2_size) == 1, "record R2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(R2,x) == 0, "field R2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(R2,e) == 0, "field R2.e wrong bit offset");
#endif
_Static_assert(sizeof(S2) == 2, "record S2 wrong sizeof");
_Static_assert(_Alignof(S2) == 2, "record S2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct S2_alignment) == 4, "record S2 wrong sizeof");
_Static_assert(_Alignof(struct S2_alignment) == 2, "record S2 wrong alignment");
_Static_assert(sizeof(struct S2_packed) == 2, "record S2 wrong sizeof");
_Static_assert(_Alignof(struct S2_packed) == 1, "record S2 wrong alignment");
_Static_assert(sizeof(struct S2_required_alignment) == 3, "record S2 wrong sizeof");
_Static_assert(_Alignof(struct S2_required_alignment) == 1, "record S2 wrong alignment");
_Static_assert(sizeof(struct S2_size) == 4, "record S2 wrong sizeof");
_Static_assert(_Alignof(struct S2_size) == 1, "record S2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(S2,x) == 0, "field S2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(S2,e) == 0, "field S2.e wrong bit offset");
#endif
_Static_assert(sizeof(T2) == 4, "record T2 wrong sizeof");
_Static_assert(_Alignof(T2) == 4, "record T2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct T2_alignment) == 8, "record T2 wrong sizeof");
_Static_assert(_Alignof(struct T2_alignment) == 4, "record T2 wrong alignment");
_Static_assert(sizeof(struct T2_packed) == 4, "record T2 wrong sizeof");
_Static_assert(_Alignof(struct T2_packed) == 1, "record T2 wrong alignment");
_Static_assert(sizeof(struct T2_required_alignment) == 5, "record T2 wrong sizeof");
_Static_assert(_Alignof(struct T2_required_alignment) == 1, "record T2 wrong alignment");
_Static_assert(sizeof(struct T2_size) == 6, "record T2 wrong sizeof");
_Static_assert(_Alignof(struct T2_size) == 1, "record T2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(T2,x) == 0, "field T2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(T2,e) == 0, "field T2.e wrong bit offset");
#endif
_Static_assert(sizeof(U2) == 1, "record U2 wrong sizeof");
_Static_assert(_Alignof(U2) == 1, "record U2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct U2_alignment) == 2, "record U2 wrong sizeof");
_Static_assert(_Alignof(struct U2_alignment) == 1, "record U2 wrong alignment");
_Static_assert(sizeof(struct U2_packed) == 1, "record U2 wrong sizeof");
_Static_assert(_Alignof(struct U2_packed) == 1, "record U2 wrong alignment");
_Static_assert(sizeof(struct U2_required_alignment) == 2, "record U2 wrong sizeof");
_Static_assert(_Alignof(struct U2_required_alignment) == 1, "record U2 wrong alignment");
_Static_assert(sizeof(struct U2_size) == 3, "record U2 wrong sizeof");
_Static_assert(_Alignof(struct U2_size) == 1, "record U2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(U2,x) == 0, "field U2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(U2,e) == 0, "field U2.e wrong bit offset");
#endif
_Static_assert(sizeof(V2) == 1, "record V2 wrong sizeof");
_Static_assert(_Alignof(V2) == 1, "record V2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct V2_alignment) == 2, "record V2 wrong sizeof");
_Static_assert(_Alignof(struct V2_alignment) == 1, "record V2 wrong alignment");
_Static_assert(sizeof(struct V2_packed) == 1, "record V2 wrong sizeof");
_Static_assert(_Alignof(struct V2_packed) == 1, "record V2 wrong alignment");
_Static_assert(sizeof(struct V2_required_alignment) == 2, "record V2 wrong sizeof");
_Static_assert(_Alignof(struct V2_required_alignment) == 1, "record V2 wrong alignment");
_Static_assert(sizeof(struct V2_size) == 3, "record V2 wrong sizeof");
_Static_assert(_Alignof(struct V2_size) == 1, "record V2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(V2,x) == 0, "field V2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(V2,e) == 0, "field V2.e wrong bit offset");
#endif
_Static_assert(sizeof(W2) == 16, "record W2 wrong sizeof");
_Static_assert(_Alignof(W2) == 16, "record W2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct W2_alignment) == 32, "record W2 wrong sizeof");
_Static_assert(_Alignof(struct W2_alignment) == 16, "record W2 wrong alignment");
_Static_assert(sizeof(struct W2_packed) == 16, "record W2 wrong sizeof");
_Static_assert(_Alignof(struct W2_packed) == 1, "record W2 wrong alignment");
_Static_assert(sizeof(struct W2_required_alignment) == 17, "record W2 wrong sizeof");
_Static_assert(_Alignof(struct W2_required_alignment) == 1, "record W2 wrong alignment");
_Static_assert(sizeof(struct W2_size) == 18, "record W2 wrong sizeof");
_Static_assert(_Alignof(struct W2_size) == 1, "record W2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(W2,x) == 0, "field W2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(W2,e) == 0, "field W2.e wrong bit offset");
#endif
_Static_assert(sizeof(W_2) == 16, "record W_2 wrong sizeof");
_Static_assert(_Alignof(W_2) == 16, "record W_2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct W_2_alignment) == 32, "record W_2 wrong sizeof");
_Static_assert(_Alignof(struct W_2_alignment) == 16, "record W_2 wrong alignment");
_Static_assert(sizeof(struct W_2_packed) == 16, "record W_2 wrong sizeof");
_Static_assert(_Alignof(struct W_2_packed) == 1, "record W_2 wrong alignment");
_Static_assert(sizeof(struct W_2_required_alignment) == 17, "record W_2 wrong sizeof");
_Static_assert(_Alignof(struct W_2_required_alignment) == 1, "record W_2 wrong alignment");
_Static_assert(sizeof(struct W_2_size) == 18, "record W_2 wrong sizeof");
_Static_assert(_Alignof(struct W_2_size) == 1, "record W_2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(W_2,e) == 0, "field W_2.e wrong bit offset");
#endif
_Static_assert(sizeof(X2) == 16, "record X2 wrong sizeof");
_Static_assert(_Alignof(X2) == 16, "record X2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct X2_alignment) == 32, "record X2 wrong sizeof");
_Static_assert(_Alignof(struct X2_alignment) == 16, "record X2 wrong alignment");
_Static_assert(sizeof(struct X2_packed) == 16, "record X2 wrong sizeof");
_Static_assert(_Alignof(struct X2_packed) == 1, "record X2 wrong alignment");
_Static_assert(sizeof(struct X2_required_alignment) == 17, "record X2 wrong sizeof");
_Static_assert(_Alignof(struct X2_required_alignment) == 1, "record X2 wrong alignment");
_Static_assert(sizeof(struct X2_size) == 18, "record X2 wrong sizeof");
_Static_assert(_Alignof(struct X2_size) == 1, "record X2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(X2,x) == 0, "field X2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(X2,e) == 0, "field X2.e wrong bit offset");
#endif
_Static_assert(sizeof(Y) == 2, "record Y wrong sizeof");
_Static_assert(_Alignof(Y) == 1, "record Y wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Y_alignment) == 3, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_alignment) == 1, "record Y wrong alignment");
_Static_assert(sizeof(struct Y_packed) == 2, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_packed) == 1, "record Y wrong alignment");
_Static_assert(sizeof(struct Y_required_alignment) == 3, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_required_alignment) == 1, "record Y wrong alignment");
_Static_assert(sizeof(struct Y_size) == 4, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_size) == 1, "record Y wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(Y,d) == 8, "field Y.d wrong bit offset");
#endif
_Static_assert(sizeof(Y2) == 1, "record Y2 wrong sizeof");
_Static_assert(_Alignof(Y2) == 1, "record Y2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Y2_alignment) == 2, "record Y2 wrong sizeof");
_Static_assert(_Alignof(struct Y2_alignment) == 1, "record Y2 wrong alignment");
_Static_assert(sizeof(struct Y2_packed) == 1, "record Y2 wrong sizeof");
_Static_assert(_Alignof(struct Y2_packed) == 1, "record Y2 wrong alignment");
_Static_assert(sizeof(struct Y2_required_alignment) == 2, "record Y2 wrong sizeof");
_Static_assert(_Alignof(struct Y2_required_alignment) == 1, "record Y2 wrong alignment");
_Static_assert(sizeof(struct Y2_size) == 3, "record Y2 wrong sizeof");
_Static_assert(_Alignof(struct Y2_size) == 1, "record Y2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(Y2,d) == 0, "field Y2.d wrong bit offset");
#endif
_Static_assert(sizeof(A3) == 64, "record A3 wrong sizeof");
_Static_assert(_Alignof(A3) == 32, "record A3 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A3_alignment) == 96, "record A3 wrong sizeof");
_Static_assert(_Alignof(struct A3_alignment) == 32, "record A3 wrong alignment");
_Static_assert(sizeof(struct A3_packed) == 64, "record A3 wrong sizeof");
_Static_assert(_Alignof(struct A3_packed) == 1, "record A3 wrong alignment");
_Static_assert(sizeof(struct A3_required_alignment) == 65, "record A3 wrong sizeof");
_Static_assert(_Alignof(struct A3_required_alignment) == 1, "record A3 wrong alignment");
_Static_assert(sizeof(struct A3_size) == 66, "record A3 wrong sizeof");
_Static_assert(_Alignof(struct A3_size) == 1, "record A3 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A3,d) == 256, "field A3.d wrong bit offset");
#endif
_Static_assert(sizeof(A4) == 1, "record A4 wrong sizeof");
_Static_assert(_Alignof(A4) == 32, "record A4 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A4_alignment) == 64, "record A4 wrong sizeof");
_Static_assert(_Alignof(struct A4_alignment) == 32, "record A4 wrong alignment");
_Static_assert(sizeof(struct A4_packed) == 1, "record A4 wrong sizeof");
_Static_assert(_Alignof(struct A4_packed) == 1, "record A4 wrong alignment");
_Static_assert(sizeof(struct A4_required_alignment) == 2, "record A4 wrong sizeof");
_Static_assert(_Alignof(struct A4_required_alignment) == 1, "record A4 wrong alignment");
_Static_assert(sizeof(struct A4_size) == 3, "record A4 wrong sizeof");
_Static_assert(_Alignof(struct A4_size) == 1, "record A4 wrong alignment");
#endif
_Static_assert(sizeof(A5) == 2, "record A5 wrong sizeof");
_Static_assert(_Alignof(A5) == 1, "record A5 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A5_alignment) == 3, "record A5 wrong sizeof");
_Static_assert(_Alignof(struct A5_alignment) == 1, "record A5 wrong alignment");
_Static_assert(sizeof(struct A5_packed) == 2, "record A5 wrong sizeof");
_Static_assert(_Alignof(struct A5_packed) == 1, "record A5 wrong alignment");
_Static_assert(sizeof(struct A5_required_alignment) == 3, "record A5 wrong sizeof");
_Static_assert(_Alignof(struct A5_required_alignment) == 1, "record A5 wrong alignment");
_Static_assert(sizeof(struct A5_size) == 4, "record A5 wrong sizeof");
_Static_assert(_Alignof(struct A5_size) == 1, "record A5 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A5,d) == 8, "field A5.d wrong bit offset");
#endif
_Static_assert(sizeof(A7) == 32, "record A7 wrong sizeof");
_Static_assert(_Alignof(A7) == 32, "record A7 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A7_alignment) == 64, "record A7 wrong sizeof");
_Static_assert(_Alignof(struct A7_alignment) == 32, "record A7 wrong alignment");
_Static_assert(sizeof(struct A7_packed) == 32, "record A7 wrong sizeof");
_Static_assert(_Alignof(struct A7_packed) == 1, "record A7 wrong alignment");
_Static_assert(sizeof(struct A7_required_alignment) == 33, "record A7 wrong sizeof");
_Static_assert(_Alignof(struct A7_required_alignment) == 1, "record A7 wrong alignment");
_Static_assert(sizeof(struct A7_size) == 34, "record A7 wrong sizeof");
_Static_assert(_Alignof(struct A7_size) == 1, "record A7 wrong alignment");
#endif
_Static_assert(sizeof(A8) == 6, "record A8 wrong sizeof");
_Static_assert(_Alignof(A8) == 1, "record A8 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A8_alignment) == 7, "record A8 wrong sizeof");
_Static_assert(_Alignof(struct A8_alignment) == 1, "record A8 wrong alignment");
_Static_assert(sizeof(struct A8_packed) == 6, "record A8 wrong sizeof");
_Static_assert(_Alignof(struct A8_packed) == 1, "record A8 wrong alignment");
_Static_assert(sizeof(struct A8_required_alignment) == 7, "record A8 wrong sizeof");
_Static_assert(_Alignof(struct A8_required_alignment) == 1, "record A8 wrong alignment");
_Static_assert(sizeof(struct A8_size) == 8, "record A8 wrong sizeof");
_Static_assert(_Alignof(struct A8_size) == 1, "record A8 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A8,i) == 8, "field A8.i wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A8,j) == 39, "field A8.j wrong bit offset");
#endif
_Static_assert(sizeof(A9) == 9, "record A9 wrong sizeof");
_Static_assert(_Alignof(A9) == 1, "record A9 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A9_alignment) == 10, "record A9 wrong sizeof");
_Static_assert(_Alignof(struct A9_alignment) == 1, "record A9 wrong alignment");
_Static_assert(sizeof(struct A9_packed) == 9, "record A9 wrong sizeof");
_Static_assert(_Alignof(struct A9_packed) == 1, "record A9 wrong alignment");
_Static_assert(sizeof(struct A9_required_alignment) == 10, "record A9 wrong sizeof");
_Static_assert(_Alignof(struct A9_required_alignment) == 1, "record A9 wrong alignment");
_Static_assert(sizeof(struct A9_size) == 11, "record A9 wrong sizeof");
_Static_assert(_Alignof(struct A9_size) == 1, "record A9 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A9,i) == 8, "field A9.i wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A9,j) == 40, "field A9.j wrong bit offset");
#endif
_Static_assert(sizeof(A10) == 4, "record A10 wrong sizeof");
_Static_assert(_Alignof(A10) == 16, "record A10 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A10_alignment) == 32, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_alignment) == 16, "record A10 wrong alignment");
_Static_assert(sizeof(struct A10_packed) == 4, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_packed) == 1, "record A10 wrong alignment");
_Static_assert(sizeof(struct A10_required_alignment) == 5, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_required_alignment) == 1, "record A10 wrong alignment");
_Static_assert(sizeof(struct A10_size) == 6, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_size) == 1, "record A10 wrong alignment");
#endif
_Static_assert(sizeof(A11) == 6, "record A11 wrong sizeof");
_Static_assert(_Alignof(A11) == 1, "record A11 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A11_alignment) == 7, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_alignment) == 1, "record A11 wrong alignment");
_Static_assert(sizeof(struct A11_packed) == 6, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_packed) == 1, "record A11 wrong alignment");
_Static_assert(sizeof(struct A11_required_alignment) == 7, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_required_alignment) == 1, "record A11 wrong alignment");
_Static_assert(sizeof(struct A11_size) == 8, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_size) == 1, "record A11 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A11,i) == 8, "field A11.i wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A11,j) == 39, "field A11.j wrong bit offset");
#endif
_Static_assert(sizeof(A12) == 32, "record A12 wrong sizeof");
_Static_assert(_Alignof(A12) == 16, "record A12 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A12_alignment) == 48, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_alignment) == 16, "record A12 wrong alignment");
_Static_assert(sizeof(struct A12_packed) == 32, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_packed) == 1, "record A12 wrong alignment");
_Static_assert(sizeof(struct A12_required_alignment) == 33, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_required_alignment) == 1, "record A12 wrong alignment");
_Static_assert(sizeof(struct A12_size) == 34, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_size) == 1, "record A12 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A12,i) == 8, "field A12.i wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A12,j) == 128, "field A12.j wrong bit offset");
#endif
_Static_assert(sizeof(A13) == 32, "record A13 wrong sizeof");
_Static_assert(_Alignof(A13) == 16, "record A13 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A13_alignment) == 48, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_alignment) == 16, "record A13 wrong alignment");
_Static_assert(sizeof(struct A13_packed) == 32, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_packed) == 1, "record A13 wrong alignment");
_Static_assert(sizeof(struct A13_required_alignment) == 33, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_required_alignment) == 1, "record A13 wrong alignment");
_Static_assert(sizeof(struct A13_size) == 34, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_size) == 1, "record A13 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A13,i) == 8, "field A13.i wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A13,j) == 128, "field A13.j wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A13,d) == 136, "field A13.d wrong bit offset");
#endif
// MAPPING|EIGHT|hexagon-generic-linux-musl:Clang|mipsel-mips32-other-none:Clang|powerpc-ppc-netbsd-gnu:Clang|riscv32-generic_rv32-other-none:Clang|wasm32-generic-emscripten-musl:Clang|wasm32-generic-other-none:Clang|wasm32-generic-wasi-musl:Clang|END
// repr targets HexagonUnknownLinuxMusl|Some("hexagon-generic-linux-musl") MipselSonyPsp|None MipselUnknownNone|Some("mipsel-mips32-other-none") PowerpcUnknownLinuxGnuspe|None PowerpcUnknownNetbsd|Some("powerpc-ppc-netbsd-gnu") Riscv32|Some("riscv32-generic_rv32-other-none") Wasm32UnknownEmscripten|Some("wasm32-generic-emscripten-musl") Wasm32UnknownUnknown|Some("wasm32-generic-other-none") Wasm32Wasi|Some("wasm32-generic-wasi-musl") 
#elif defined(EIGHT)
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
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A,d) == 0, "field A.d wrong bit offset");
#endif
_Static_assert(sizeof(A_) == 5, "record A_ wrong sizeof");
_Static_assert(_Alignof(A_) == 1, "record A_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A__alignment) == 6, "record A_ wrong sizeof");
_Static_assert(_Alignof(struct A__alignment) == 1, "record A_ wrong alignment");
_Static_assert(sizeof(struct A__packed) == 5, "record A_ wrong sizeof");
_Static_assert(_Alignof(struct A__packed) == 1, "record A_ wrong alignment");
_Static_assert(sizeof(struct A__required_alignment) == 6, "record A_ wrong sizeof");
_Static_assert(_Alignof(struct A__required_alignment) == 1, "record A_ wrong alignment");
_Static_assert(sizeof(struct A__size) == 7, "record A_ wrong sizeof");
_Static_assert(_Alignof(struct A__size) == 1, "record A_ wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_,d) == 32, "field A_.d wrong bit offset");
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
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B,d) == 0, "field B.d wrong bit offset");
#endif
_Static_assert(sizeof(B_) == 9, "record B_ wrong sizeof");
_Static_assert(_Alignof(B_) == 1, "record B_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B__alignment) == 10, "record B_ wrong sizeof");
_Static_assert(_Alignof(struct B__alignment) == 1, "record B_ wrong alignment");
_Static_assert(sizeof(struct B__packed) == 9, "record B_ wrong sizeof");
_Static_assert(_Alignof(struct B__packed) == 1, "record B_ wrong alignment");
_Static_assert(sizeof(struct B__required_alignment) == 10, "record B_ wrong sizeof");
_Static_assert(_Alignof(struct B__required_alignment) == 1, "record B_ wrong alignment");
_Static_assert(sizeof(struct B__size) == 11, "record B_ wrong sizeof");
_Static_assert(_Alignof(struct B__size) == 1, "record B_ wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B_,d) == 64, "field B_.d wrong bit offset");
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
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C,d) == 0, "field C.d wrong bit offset");
#endif
_Static_assert(sizeof(C_) == 9, "record C_ wrong sizeof");
_Static_assert(_Alignof(C_) == 1, "record C_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C__alignment) == 10, "record C_ wrong sizeof");
_Static_assert(_Alignof(struct C__alignment) == 1, "record C_ wrong alignment");
_Static_assert(sizeof(struct C__packed) == 9, "record C_ wrong sizeof");
_Static_assert(_Alignof(struct C__packed) == 1, "record C_ wrong alignment");
_Static_assert(sizeof(struct C__required_alignment) == 10, "record C_ wrong sizeof");
_Static_assert(_Alignof(struct C__required_alignment) == 1, "record C_ wrong alignment");
_Static_assert(sizeof(struct C__size) == 11, "record C_ wrong sizeof");
_Static_assert(_Alignof(struct C__size) == 1, "record C_ wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C_,d) == 64, "field C_.d wrong bit offset");
#endif
_Static_assert(sizeof(D) == 24, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 8, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 32, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 8, "record D wrong alignment");
_Static_assert(sizeof(struct D_packed) == 24, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 25, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_size) == 26, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_size) == 1, "record D wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D,d) == 64, "field D.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(D,e) == 128, "field D.e wrong bit offset");
#endif
_Static_assert(sizeof(F) == 32, "record F wrong sizeof");
_Static_assert(_Alignof(F) == 16, "record F wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 48, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_alignment) == 16, "record F wrong alignment");
_Static_assert(sizeof(struct F_packed) == 32, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_packed) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_required_alignment) == 33, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_size) == 34, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_size) == 1, "record F wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F,d) == 128, "field F.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(F,e) == 192, "field F.e wrong bit offset");
#endif
_Static_assert(sizeof(G) == 12, "record G wrong sizeof");
_Static_assert(_Alignof(G) == 2, "record G wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 14, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_alignment) == 2, "record G wrong alignment");
_Static_assert(sizeof(struct G_packed) == 12, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_packed) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_required_alignment) == 13, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_size) == 14, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_size) == 1, "record G wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(G,d) == 16, "field G.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(G,e) == 80, "field G.e wrong bit offset");
#endif
_Static_assert(sizeof(H) == 12, "record H wrong sizeof");
_Static_assert(_Alignof(H) == 2, "record H wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 14, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_alignment) == 2, "record H wrong alignment");
_Static_assert(sizeof(struct H_packed) == 12, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_packed) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_required_alignment) == 13, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_size) == 14, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_size) == 1, "record H wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(H,d) == 16, "field H.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(H,e) == 80, "field H.e wrong bit offset");
#endif
_Static_assert(sizeof(I) == 10, "record I wrong sizeof");
_Static_assert(_Alignof(I) == 1, "record I wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I_alignment) == 11, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_alignment) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_packed) == 10, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_packed) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_required_alignment) == 11, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_required_alignment) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_size) == 12, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_size) == 1, "record I wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(I,d) == 8, "field I.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(I,e) == 72, "field I.e wrong bit offset");
#endif
_Static_assert(sizeof(J) == 12, "record J wrong sizeof");
_Static_assert(_Alignof(J) == 2, "record J wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J_alignment) == 14, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_alignment) == 2, "record J wrong alignment");
_Static_assert(sizeof(struct J_packed) == 12, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_packed) == 1, "record J wrong alignment");
_Static_assert(sizeof(struct J_required_alignment) == 13, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_required_alignment) == 1, "record J wrong alignment");
_Static_assert(sizeof(struct J_size) == 14, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_size) == 1, "record J wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(J,d) == 16, "field J.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(J,e) == 80, "field J.e wrong bit offset");
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
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(K,d) == 8, "field K.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(K,e) == 16, "field K.e wrong bit offset");
#endif
_Static_assert(sizeof(L) == 32, "record L wrong sizeof");
_Static_assert(_Alignof(L) == 16, "record L wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct L_alignment) == 48, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_alignment) == 16, "record L wrong alignment");
_Static_assert(sizeof(struct L_packed) == 32, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_packed) == 1, "record L wrong alignment");
_Static_assert(sizeof(struct L_required_alignment) == 33, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_required_alignment) == 1, "record L wrong alignment");
_Static_assert(sizeof(struct L_size) == 34, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_size) == 1, "record L wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(L,d) == 128, "field L.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(L,e) == 136, "field L.e wrong bit offset");
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
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(M,d) == 16, "field M.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(M,e) == 24, "field M.e wrong bit offset");
#endif
_Static_assert(sizeof(N) == 4, "record N wrong sizeof");
_Static_assert(_Alignof(N) == 2, "record N wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct N_alignment) == 6, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_alignment) == 2, "record N wrong alignment");
_Static_assert(sizeof(struct N_packed) == 4, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_packed) == 1, "record N wrong alignment");
_Static_assert(sizeof(struct N_required_alignment) == 5, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_required_alignment) == 1, "record N wrong alignment");
_Static_assert(sizeof(struct N_size) == 6, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_size) == 1, "record N wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(N,d) == 8, "field N.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(N,e) == 16, "field N.e wrong bit offset");
#endif
_Static_assert(sizeof(O) == 3, "record O wrong sizeof");
_Static_assert(_Alignof(O) == 1, "record O wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct O_alignment) == 4, "record O wrong sizeof");
_Static_assert(_Alignof(struct O_alignment) == 1, "record O wrong alignment");
_Static_assert(sizeof(struct O_packed) == 3, "record O wrong sizeof");
_Static_assert(_Alignof(struct O_packed) == 1, "record O wrong alignment");
_Static_assert(sizeof(struct O_required_alignment) == 4, "record O wrong sizeof");
_Static_assert(_Alignof(struct O_required_alignment) == 1, "record O wrong alignment");
_Static_assert(sizeof(struct O_size) == 5, "record O wrong sizeof");
_Static_assert(_Alignof(struct O_size) == 1, "record O wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(O,d) == 8, "field O.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(O,e) == 16, "field O.e wrong bit offset");
#endif
_Static_assert(sizeof(P) == 4, "record P wrong sizeof");
_Static_assert(_Alignof(P) == 2, "record P wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct P_alignment) == 6, "record P wrong sizeof");
_Static_assert(_Alignof(struct P_alignment) == 2, "record P wrong alignment");
_Static_assert(sizeof(struct P_packed) == 4, "record P wrong sizeof");
_Static_assert(_Alignof(struct P_packed) == 1, "record P wrong alignment");
_Static_assert(sizeof(struct P_required_alignment) == 5, "record P wrong sizeof");
_Static_assert(_Alignof(struct P_required_alignment) == 1, "record P wrong alignment");
_Static_assert(sizeof(struct P_size) == 6, "record P wrong sizeof");
_Static_assert(_Alignof(struct P_size) == 1, "record P wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(P,d) == 8, "field P.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(P,e) == 16, "field P.e wrong bit offset");
#endif
_Static_assert(sizeof(Q) == 8, "record Q wrong sizeof");
_Static_assert(_Alignof(Q) == 8, "record Q wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Q_alignment) == 16, "record Q wrong sizeof");
_Static_assert(_Alignof(struct Q_alignment) == 8, "record Q wrong alignment");
_Static_assert(sizeof(struct Q_packed) == 8, "record Q wrong sizeof");
_Static_assert(_Alignof(struct Q_packed) == 1, "record Q wrong alignment");
_Static_assert(sizeof(struct Q_required_alignment) == 9, "record Q wrong sizeof");
_Static_assert(_Alignof(struct Q_required_alignment) == 1, "record Q wrong alignment");
_Static_assert(sizeof(struct Q_size) == 10, "record Q wrong sizeof");
_Static_assert(_Alignof(struct Q_size) == 1, "record Q wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(Q,x) == 8, "field Q.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(Q,d) == 9, "field Q.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(Q,e) == 16, "field Q.e wrong bit offset");
#endif
_Static_assert(sizeof(R) == 17, "record R wrong sizeof");
_Static_assert(_Alignof(R) == 1, "record R wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct R_alignment) == 18, "record R wrong sizeof");
_Static_assert(_Alignof(struct R_alignment) == 1, "record R wrong alignment");
_Static_assert(sizeof(struct R_packed) == 17, "record R wrong sizeof");
_Static_assert(_Alignof(struct R_packed) == 1, "record R wrong alignment");
_Static_assert(sizeof(struct R_required_alignment) == 18, "record R wrong sizeof");
_Static_assert(_Alignof(struct R_required_alignment) == 1, "record R wrong alignment");
_Static_assert(sizeof(struct R_size) == 19, "record R wrong sizeof");
_Static_assert(_Alignof(struct R_size) == 1, "record R wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(R,x) == 8, "field R.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(R,e) == 128, "field R.e wrong bit offset");
#endif
_Static_assert(sizeof(S) == 9, "record S wrong sizeof");
_Static_assert(_Alignof(S) == 1, "record S wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct S_alignment) == 10, "record S wrong sizeof");
_Static_assert(_Alignof(struct S_alignment) == 1, "record S wrong alignment");
_Static_assert(sizeof(struct S_packed) == 9, "record S wrong sizeof");
_Static_assert(_Alignof(struct S_packed) == 1, "record S wrong alignment");
_Static_assert(sizeof(struct S_required_alignment) == 10, "record S wrong sizeof");
_Static_assert(_Alignof(struct S_required_alignment) == 1, "record S wrong alignment");
_Static_assert(sizeof(struct S_size) == 11, "record S wrong sizeof");
_Static_assert(_Alignof(struct S_size) == 1, "record S wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(S,x) == 8, "field S.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(S,e) == 64, "field S.e wrong bit offset");
#endif
_Static_assert(sizeof(T) == 9, "record T wrong sizeof");
_Static_assert(_Alignof(T) == 1, "record T wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct T_alignment) == 10, "record T wrong sizeof");
_Static_assert(_Alignof(struct T_alignment) == 1, "record T wrong alignment");
_Static_assert(sizeof(struct T_packed) == 9, "record T wrong sizeof");
_Static_assert(_Alignof(struct T_packed) == 1, "record T wrong alignment");
_Static_assert(sizeof(struct T_required_alignment) == 10, "record T wrong sizeof");
_Static_assert(_Alignof(struct T_required_alignment) == 1, "record T wrong alignment");
_Static_assert(sizeof(struct T_size) == 11, "record T wrong sizeof");
_Static_assert(_Alignof(struct T_size) == 1, "record T wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(T,x) == 8, "field T.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(T,e) == 64, "field T.e wrong bit offset");
#endif
_Static_assert(sizeof(U) == 9, "record U wrong sizeof");
_Static_assert(_Alignof(U) == 1, "record U wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct U_alignment) == 10, "record U wrong sizeof");
_Static_assert(_Alignof(struct U_alignment) == 1, "record U wrong alignment");
_Static_assert(sizeof(struct U_packed) == 9, "record U wrong sizeof");
_Static_assert(_Alignof(struct U_packed) == 1, "record U wrong alignment");
_Static_assert(sizeof(struct U_required_alignment) == 10, "record U wrong sizeof");
_Static_assert(_Alignof(struct U_required_alignment) == 1, "record U wrong alignment");
_Static_assert(sizeof(struct U_size) == 11, "record U wrong sizeof");
_Static_assert(_Alignof(struct U_size) == 1, "record U wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(U,x) == 8, "field U.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(U,e) == 64, "field U.e wrong bit offset");
#endif
_Static_assert(sizeof(V) == 9, "record V wrong sizeof");
_Static_assert(_Alignof(V) == 1, "record V wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct V_alignment) == 10, "record V wrong sizeof");
_Static_assert(_Alignof(struct V_alignment) == 1, "record V wrong alignment");
_Static_assert(sizeof(struct V_packed) == 9, "record V wrong sizeof");
_Static_assert(_Alignof(struct V_packed) == 1, "record V wrong alignment");
_Static_assert(sizeof(struct V_required_alignment) == 10, "record V wrong sizeof");
_Static_assert(_Alignof(struct V_required_alignment) == 1, "record V wrong alignment");
_Static_assert(sizeof(struct V_size) == 11, "record V wrong sizeof");
_Static_assert(_Alignof(struct V_size) == 1, "record V wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(V,x) == 8, "field V.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(V,e) == 64, "field V.e wrong bit offset");
#endif
_Static_assert(sizeof(W) == 17, "record W wrong sizeof");
_Static_assert(_Alignof(W) == 1, "record W wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct W_alignment) == 18, "record W wrong sizeof");
_Static_assert(_Alignof(struct W_alignment) == 1, "record W wrong alignment");
_Static_assert(sizeof(struct W_packed) == 17, "record W wrong sizeof");
_Static_assert(_Alignof(struct W_packed) == 1, "record W wrong alignment");
_Static_assert(sizeof(struct W_required_alignment) == 18, "record W wrong sizeof");
_Static_assert(_Alignof(struct W_required_alignment) == 1, "record W wrong alignment");
_Static_assert(sizeof(struct W_size) == 19, "record W wrong sizeof");
_Static_assert(_Alignof(struct W_size) == 1, "record W wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(W,x) == 8, "field W.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(W,e) == 128, "field W.e wrong bit offset");
#endif
_Static_assert(sizeof(W_) == 17, "record W_ wrong sizeof");
_Static_assert(_Alignof(W_) == 1, "record W_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct W__alignment) == 18, "record W_ wrong sizeof");
_Static_assert(_Alignof(struct W__alignment) == 1, "record W_ wrong alignment");
_Static_assert(sizeof(struct W__packed) == 17, "record W_ wrong sizeof");
_Static_assert(_Alignof(struct W__packed) == 1, "record W_ wrong alignment");
_Static_assert(sizeof(struct W__required_alignment) == 18, "record W_ wrong sizeof");
_Static_assert(_Alignof(struct W__required_alignment) == 1, "record W_ wrong alignment");
_Static_assert(sizeof(struct W__size) == 19, "record W_ wrong sizeof");
_Static_assert(_Alignof(struct W__size) == 1, "record W_ wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(W_,e) == 128, "field W_.e wrong bit offset");
#endif
_Static_assert(sizeof(X) == 17, "record X wrong sizeof");
_Static_assert(_Alignof(X) == 1, "record X wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct X_alignment) == 18, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_alignment) == 1, "record X wrong alignment");
_Static_assert(sizeof(struct X_packed) == 17, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_packed) == 1, "record X wrong alignment");
_Static_assert(sizeof(struct X_required_alignment) == 18, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_required_alignment) == 1, "record X wrong alignment");
_Static_assert(sizeof(struct X_size) == 19, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_size) == 1, "record X wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(X,x) == 8, "field X.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(X,e) == 128, "field X.e wrong bit offset");
#endif
_Static_assert(sizeof(A2) == 1, "record A2 wrong sizeof");
_Static_assert(_Alignof(A2) == 1, "record A2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A2_alignment) == 2, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_alignment) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_packed) == 1, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_packed) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_required_alignment) == 2, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_required_alignment) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_size) == 3, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_size) == 1, "record A2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A2,d) == 0, "field A2.d wrong bit offset");
#endif
_Static_assert(sizeof(A_2) == 1, "record A_2 wrong sizeof");
_Static_assert(_Alignof(A_2) == 1, "record A_2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_2_alignment) == 2, "record A_2 wrong sizeof");
_Static_assert(_Alignof(struct A_2_alignment) == 1, "record A_2 wrong alignment");
_Static_assert(sizeof(struct A_2_packed) == 1, "record A_2 wrong sizeof");
_Static_assert(_Alignof(struct A_2_packed) == 1, "record A_2 wrong alignment");
_Static_assert(sizeof(struct A_2_required_alignment) == 2, "record A_2 wrong sizeof");
_Static_assert(_Alignof(struct A_2_required_alignment) == 1, "record A_2 wrong alignment");
_Static_assert(sizeof(struct A_2_size) == 3, "record A_2 wrong sizeof");
_Static_assert(_Alignof(struct A_2_size) == 1, "record A_2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_2,d) == 0, "field A_2.d wrong bit offset");
#endif
_Static_assert(sizeof(B2) == 1, "record B2 wrong sizeof");
_Static_assert(_Alignof(B2) == 1, "record B2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B2_alignment) == 2, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_alignment) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_packed) == 1, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_packed) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_required_alignment) == 2, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_required_alignment) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_size) == 3, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_size) == 1, "record B2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B2,d) == 0, "field B2.d wrong bit offset");
#endif
_Static_assert(sizeof(B_2) == 1, "record B_2 wrong sizeof");
_Static_assert(_Alignof(B_2) == 1, "record B_2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_2_alignment) == 2, "record B_2 wrong sizeof");
_Static_assert(_Alignof(struct B_2_alignment) == 1, "record B_2 wrong alignment");
_Static_assert(sizeof(struct B_2_packed) == 1, "record B_2 wrong sizeof");
_Static_assert(_Alignof(struct B_2_packed) == 1, "record B_2 wrong alignment");
_Static_assert(sizeof(struct B_2_required_alignment) == 2, "record B_2 wrong sizeof");
_Static_assert(_Alignof(struct B_2_required_alignment) == 1, "record B_2 wrong alignment");
_Static_assert(sizeof(struct B_2_size) == 3, "record B_2 wrong sizeof");
_Static_assert(_Alignof(struct B_2_size) == 1, "record B_2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B_2,d) == 0, "field B_2.d wrong bit offset");
#endif
_Static_assert(sizeof(C2) == 1, "record C2 wrong sizeof");
_Static_assert(_Alignof(C2) == 1, "record C2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C2_alignment) == 2, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_alignment) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_packed) == 1, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_packed) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_required_alignment) == 2, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_required_alignment) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_size) == 3, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_size) == 1, "record C2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C2,d) == 0, "field C2.d wrong bit offset");
#endif
_Static_assert(sizeof(C22) == 1, "record C22 wrong sizeof");
_Static_assert(_Alignof(C22) == 1, "record C22 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C22_alignment) == 2, "record C22 wrong sizeof");
_Static_assert(_Alignof(struct C22_alignment) == 1, "record C22 wrong alignment");
_Static_assert(sizeof(struct C22_packed) == 1, "record C22 wrong sizeof");
_Static_assert(_Alignof(struct C22_packed) == 1, "record C22 wrong alignment");
_Static_assert(sizeof(struct C22_required_alignment) == 2, "record C22 wrong sizeof");
_Static_assert(_Alignof(struct C22_required_alignment) == 1, "record C22 wrong alignment");
_Static_assert(sizeof(struct C22_size) == 3, "record C22 wrong sizeof");
_Static_assert(_Alignof(struct C22_size) == 1, "record C22 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C22,d) == 0, "field C22.d wrong bit offset");
#endif
_Static_assert(sizeof(D2) == 8, "record D2 wrong sizeof");
_Static_assert(_Alignof(D2) == 8, "record D2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D2_alignment) == 16, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_alignment) == 8, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_packed) == 8, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_packed) == 1, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_required_alignment) == 9, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_required_alignment) == 1, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_size) == 10, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_size) == 1, "record D2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D2,d) == 0, "field D2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(D2,e) == 0, "field D2.e wrong bit offset");
#endif
_Static_assert(sizeof(F2) == 16, "record F2 wrong sizeof");
_Static_assert(_Alignof(F2) == 16, "record F2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F2_alignment) == 32, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_alignment) == 16, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_packed) == 16, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_packed) == 1, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_required_alignment) == 17, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_required_alignment) == 1, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_size) == 18, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_size) == 1, "record F2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F2,d) == 0, "field F2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(F2,e) == 0, "field F2.e wrong bit offset");
#endif
_Static_assert(sizeof(G2) == 8, "record G2 wrong sizeof");
_Static_assert(_Alignof(G2) == 2, "record G2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G2_alignment) == 10, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_alignment) == 2, "record G2 wrong alignment");
_Static_assert(sizeof(struct G2_packed) == 8, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_packed) == 1, "record G2 wrong alignment");
_Static_assert(sizeof(struct G2_required_alignment) == 9, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_required_alignment) == 1, "record G2 wrong alignment");
_Static_assert(sizeof(struct G2_size) == 10, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_size) == 1, "record G2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(G2,d) == 0, "field G2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(G2,e) == 0, "field G2.e wrong bit offset");
#endif
_Static_assert(sizeof(H2) == 8, "record H2 wrong sizeof");
_Static_assert(_Alignof(H2) == 2, "record H2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H2_alignment) == 10, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_alignment) == 2, "record H2 wrong alignment");
_Static_assert(sizeof(struct H2_packed) == 8, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_packed) == 1, "record H2 wrong alignment");
_Static_assert(sizeof(struct H2_required_alignment) == 9, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_required_alignment) == 1, "record H2 wrong alignment");
_Static_assert(sizeof(struct H2_size) == 10, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_size) == 1, "record H2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(H2,d) == 0, "field H2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(H2,e) == 0, "field H2.e wrong bit offset");
#endif
_Static_assert(sizeof(I2) == 8, "record I2 wrong sizeof");
_Static_assert(_Alignof(I2) == 1, "record I2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I2_alignment) == 9, "record I2 wrong sizeof");
_Static_assert(_Alignof(struct I2_alignment) == 1, "record I2 wrong alignment");
_Static_assert(sizeof(struct I2_packed) == 8, "record I2 wrong sizeof");
_Static_assert(_Alignof(struct I2_packed) == 1, "record I2 wrong alignment");
_Static_assert(sizeof(struct I2_required_alignment) == 9, "record I2 wrong sizeof");
_Static_assert(_Alignof(struct I2_required_alignment) == 1, "record I2 wrong alignment");
_Static_assert(sizeof(struct I2_size) == 10, "record I2 wrong sizeof");
_Static_assert(_Alignof(struct I2_size) == 1, "record I2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(I2,d) == 0, "field I2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(I2,e) == 0, "field I2.e wrong bit offset");
#endif
_Static_assert(sizeof(J2) == 8, "record J2 wrong sizeof");
_Static_assert(_Alignof(J2) == 2, "record J2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J2_alignment) == 10, "record J2 wrong sizeof");
_Static_assert(_Alignof(struct J2_alignment) == 2, "record J2 wrong alignment");
_Static_assert(sizeof(struct J2_packed) == 8, "record J2 wrong sizeof");
_Static_assert(_Alignof(struct J2_packed) == 1, "record J2 wrong alignment");
_Static_assert(sizeof(struct J2_required_alignment) == 9, "record J2 wrong sizeof");
_Static_assert(_Alignof(struct J2_required_alignment) == 1, "record J2 wrong alignment");
_Static_assert(sizeof(struct J2_size) == 10, "record J2 wrong sizeof");
_Static_assert(_Alignof(struct J2_size) == 1, "record J2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(J2,d) == 0, "field J2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(J2,e) == 0, "field J2.e wrong bit offset");
#endif
_Static_assert(sizeof(K2) == 8, "record K2 wrong sizeof");
_Static_assert(_Alignof(K2) == 8, "record K2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct K2_alignment) == 16, "record K2 wrong sizeof");
_Static_assert(_Alignof(struct K2_alignment) == 8, "record K2 wrong alignment");
_Static_assert(sizeof(struct K2_packed) == 8, "record K2 wrong sizeof");
_Static_assert(_Alignof(struct K2_packed) == 1, "record K2 wrong alignment");
_Static_assert(sizeof(struct K2_required_alignment) == 9, "record K2 wrong sizeof");
_Static_assert(_Alignof(struct K2_required_alignment) == 1, "record K2 wrong alignment");
_Static_assert(sizeof(struct K2_size) == 10, "record K2 wrong sizeof");
_Static_assert(_Alignof(struct K2_size) == 1, "record K2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(K2,d) == 0, "field K2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(K2,e) == 0, "field K2.e wrong bit offset");
#endif
_Static_assert(sizeof(L2) == 16, "record L2 wrong sizeof");
_Static_assert(_Alignof(L2) == 16, "record L2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct L2_alignment) == 32, "record L2 wrong sizeof");
_Static_assert(_Alignof(struct L2_alignment) == 16, "record L2 wrong alignment");
_Static_assert(sizeof(struct L2_packed) == 16, "record L2 wrong sizeof");
_Static_assert(_Alignof(struct L2_packed) == 1, "record L2 wrong alignment");
_Static_assert(sizeof(struct L2_required_alignment) == 17, "record L2 wrong sizeof");
_Static_assert(_Alignof(struct L2_required_alignment) == 1, "record L2 wrong alignment");
_Static_assert(sizeof(struct L2_size) == 18, "record L2 wrong sizeof");
_Static_assert(_Alignof(struct L2_size) == 1, "record L2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(L2,d) == 0, "field L2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(L2,e) == 0, "field L2.e wrong bit offset");
#endif
_Static_assert(sizeof(M2) == 2, "record M2 wrong sizeof");
_Static_assert(_Alignof(M2) == 2, "record M2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct M2_alignment) == 4, "record M2 wrong sizeof");
_Static_assert(_Alignof(struct M2_alignment) == 2, "record M2 wrong alignment");
_Static_assert(sizeof(struct M2_packed) == 2, "record M2 wrong sizeof");
_Static_assert(_Alignof(struct M2_packed) == 1, "record M2 wrong alignment");
_Static_assert(sizeof(struct M2_required_alignment) == 3, "record M2 wrong sizeof");
_Static_assert(_Alignof(struct M2_required_alignment) == 1, "record M2 wrong alignment");
_Static_assert(sizeof(struct M2_size) == 4, "record M2 wrong sizeof");
_Static_assert(_Alignof(struct M2_size) == 1, "record M2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(M2,d) == 0, "field M2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(M2,e) == 0, "field M2.e wrong bit offset");
#endif
_Static_assert(sizeof(N2) == 2, "record N2 wrong sizeof");
_Static_assert(_Alignof(N2) == 2, "record N2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct N2_alignment) == 4, "record N2 wrong sizeof");
_Static_assert(_Alignof(struct N2_alignment) == 2, "record N2 wrong alignment");
_Static_assert(sizeof(struct N2_packed) == 2, "record N2 wrong sizeof");
_Static_assert(_Alignof(struct N2_packed) == 1, "record N2 wrong alignment");
_Static_assert(sizeof(struct N2_required_alignment) == 3, "record N2 wrong sizeof");
_Static_assert(_Alignof(struct N2_required_alignment) == 1, "record N2 wrong alignment");
_Static_assert(sizeof(struct N2_size) == 4, "record N2 wrong sizeof");
_Static_assert(_Alignof(struct N2_size) == 1, "record N2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(N2,d) == 0, "field N2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(N2,e) == 0, "field N2.e wrong bit offset");
#endif
_Static_assert(sizeof(O2) == 1, "record O2 wrong sizeof");
_Static_assert(_Alignof(O2) == 1, "record O2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct O2_alignment) == 2, "record O2 wrong sizeof");
_Static_assert(_Alignof(struct O2_alignment) == 1, "record O2 wrong alignment");
_Static_assert(sizeof(struct O2_packed) == 1, "record O2 wrong sizeof");
_Static_assert(_Alignof(struct O2_packed) == 1, "record O2 wrong alignment");
_Static_assert(sizeof(struct O2_required_alignment) == 2, "record O2 wrong sizeof");
_Static_assert(_Alignof(struct O2_required_alignment) == 1, "record O2 wrong alignment");
_Static_assert(sizeof(struct O2_size) == 3, "record O2 wrong sizeof");
_Static_assert(_Alignof(struct O2_size) == 1, "record O2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(O2,d) == 0, "field O2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(O2,e) == 0, "field O2.e wrong bit offset");
#endif
_Static_assert(sizeof(P2) == 2, "record P2 wrong sizeof");
_Static_assert(_Alignof(P2) == 2, "record P2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct P2_alignment) == 4, "record P2 wrong sizeof");
_Static_assert(_Alignof(struct P2_alignment) == 2, "record P2 wrong alignment");
_Static_assert(sizeof(struct P2_packed) == 2, "record P2 wrong sizeof");
_Static_assert(_Alignof(struct P2_packed) == 1, "record P2 wrong alignment");
_Static_assert(sizeof(struct P2_required_alignment) == 3, "record P2 wrong sizeof");
_Static_assert(_Alignof(struct P2_required_alignment) == 1, "record P2 wrong alignment");
_Static_assert(sizeof(struct P2_size) == 4, "record P2 wrong sizeof");
_Static_assert(_Alignof(struct P2_size) == 1, "record P2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(P2,d) == 0, "field P2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(P2,e) == 0, "field P2.e wrong bit offset");
#endif
_Static_assert(sizeof(Q2) == 8, "record Q2 wrong sizeof");
_Static_assert(_Alignof(Q2) == 8, "record Q2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Q2_alignment) == 16, "record Q2 wrong sizeof");
_Static_assert(_Alignof(struct Q2_alignment) == 8, "record Q2 wrong alignment");
_Static_assert(sizeof(struct Q2_packed) == 8, "record Q2 wrong sizeof");
_Static_assert(_Alignof(struct Q2_packed) == 1, "record Q2 wrong alignment");
_Static_assert(sizeof(struct Q2_required_alignment) == 9, "record Q2 wrong sizeof");
_Static_assert(_Alignof(struct Q2_required_alignment) == 1, "record Q2 wrong alignment");
_Static_assert(sizeof(struct Q2_size) == 10, "record Q2 wrong sizeof");
_Static_assert(_Alignof(struct Q2_size) == 1, "record Q2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(Q2,x) == 0, "field Q2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(Q2,d) == 0, "field Q2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(Q2,e) == 0, "field Q2.e wrong bit offset");
#endif
_Static_assert(sizeof(R2) == 1, "record R2 wrong sizeof");
_Static_assert(_Alignof(R2) == 1, "record R2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct R2_alignment) == 2, "record R2 wrong sizeof");
_Static_assert(_Alignof(struct R2_alignment) == 1, "record R2 wrong alignment");
_Static_assert(sizeof(struct R2_packed) == 1, "record R2 wrong sizeof");
_Static_assert(_Alignof(struct R2_packed) == 1, "record R2 wrong alignment");
_Static_assert(sizeof(struct R2_required_alignment) == 2, "record R2 wrong sizeof");
_Static_assert(_Alignof(struct R2_required_alignment) == 1, "record R2 wrong alignment");
_Static_assert(sizeof(struct R2_size) == 3, "record R2 wrong sizeof");
_Static_assert(_Alignof(struct R2_size) == 1, "record R2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(R2,x) == 0, "field R2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(R2,e) == 0, "field R2.e wrong bit offset");
#endif
_Static_assert(sizeof(S2) == 1, "record S2 wrong sizeof");
_Static_assert(_Alignof(S2) == 1, "record S2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct S2_alignment) == 2, "record S2 wrong sizeof");
_Static_assert(_Alignof(struct S2_alignment) == 1, "record S2 wrong alignment");
_Static_assert(sizeof(struct S2_packed) == 1, "record S2 wrong sizeof");
_Static_assert(_Alignof(struct S2_packed) == 1, "record S2 wrong alignment");
_Static_assert(sizeof(struct S2_required_alignment) == 2, "record S2 wrong sizeof");
_Static_assert(_Alignof(struct S2_required_alignment) == 1, "record S2 wrong alignment");
_Static_assert(sizeof(struct S2_size) == 3, "record S2 wrong sizeof");
_Static_assert(_Alignof(struct S2_size) == 1, "record S2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(S2,x) == 0, "field S2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(S2,e) == 0, "field S2.e wrong bit offset");
#endif
_Static_assert(sizeof(T2) == 1, "record T2 wrong sizeof");
_Static_assert(_Alignof(T2) == 1, "record T2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct T2_alignment) == 2, "record T2 wrong sizeof");
_Static_assert(_Alignof(struct T2_alignment) == 1, "record T2 wrong alignment");
_Static_assert(sizeof(struct T2_packed) == 1, "record T2 wrong sizeof");
_Static_assert(_Alignof(struct T2_packed) == 1, "record T2 wrong alignment");
_Static_assert(sizeof(struct T2_required_alignment) == 2, "record T2 wrong sizeof");
_Static_assert(_Alignof(struct T2_required_alignment) == 1, "record T2 wrong alignment");
_Static_assert(sizeof(struct T2_size) == 3, "record T2 wrong sizeof");
_Static_assert(_Alignof(struct T2_size) == 1, "record T2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(T2,x) == 0, "field T2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(T2,e) == 0, "field T2.e wrong bit offset");
#endif
_Static_assert(sizeof(U2) == 1, "record U2 wrong sizeof");
_Static_assert(_Alignof(U2) == 1, "record U2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct U2_alignment) == 2, "record U2 wrong sizeof");
_Static_assert(_Alignof(struct U2_alignment) == 1, "record U2 wrong alignment");
_Static_assert(sizeof(struct U2_packed) == 1, "record U2 wrong sizeof");
_Static_assert(_Alignof(struct U2_packed) == 1, "record U2 wrong alignment");
_Static_assert(sizeof(struct U2_required_alignment) == 2, "record U2 wrong sizeof");
_Static_assert(_Alignof(struct U2_required_alignment) == 1, "record U2 wrong alignment");
_Static_assert(sizeof(struct U2_size) == 3, "record U2 wrong sizeof");
_Static_assert(_Alignof(struct U2_size) == 1, "record U2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(U2,x) == 0, "field U2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(U2,e) == 0, "field U2.e wrong bit offset");
#endif
_Static_assert(sizeof(V2) == 1, "record V2 wrong sizeof");
_Static_assert(_Alignof(V2) == 1, "record V2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct V2_alignment) == 2, "record V2 wrong sizeof");
_Static_assert(_Alignof(struct V2_alignment) == 1, "record V2 wrong alignment");
_Static_assert(sizeof(struct V2_packed) == 1, "record V2 wrong sizeof");
_Static_assert(_Alignof(struct V2_packed) == 1, "record V2 wrong alignment");
_Static_assert(sizeof(struct V2_required_alignment) == 2, "record V2 wrong sizeof");
_Static_assert(_Alignof(struct V2_required_alignment) == 1, "record V2 wrong alignment");
_Static_assert(sizeof(struct V2_size) == 3, "record V2 wrong sizeof");
_Static_assert(_Alignof(struct V2_size) == 1, "record V2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(V2,x) == 0, "field V2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(V2,e) == 0, "field V2.e wrong bit offset");
#endif
_Static_assert(sizeof(W2) == 1, "record W2 wrong sizeof");
_Static_assert(_Alignof(W2) == 1, "record W2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct W2_alignment) == 2, "record W2 wrong sizeof");
_Static_assert(_Alignof(struct W2_alignment) == 1, "record W2 wrong alignment");
_Static_assert(sizeof(struct W2_packed) == 1, "record W2 wrong sizeof");
_Static_assert(_Alignof(struct W2_packed) == 1, "record W2 wrong alignment");
_Static_assert(sizeof(struct W2_required_alignment) == 2, "record W2 wrong sizeof");
_Static_assert(_Alignof(struct W2_required_alignment) == 1, "record W2 wrong alignment");
_Static_assert(sizeof(struct W2_size) == 3, "record W2 wrong sizeof");
_Static_assert(_Alignof(struct W2_size) == 1, "record W2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(W2,x) == 0, "field W2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(W2,e) == 0, "field W2.e wrong bit offset");
#endif
_Static_assert(sizeof(W_2) == 1, "record W_2 wrong sizeof");
_Static_assert(_Alignof(W_2) == 1, "record W_2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct W_2_alignment) == 2, "record W_2 wrong sizeof");
_Static_assert(_Alignof(struct W_2_alignment) == 1, "record W_2 wrong alignment");
_Static_assert(sizeof(struct W_2_packed) == 1, "record W_2 wrong sizeof");
_Static_assert(_Alignof(struct W_2_packed) == 1, "record W_2 wrong alignment");
_Static_assert(sizeof(struct W_2_required_alignment) == 2, "record W_2 wrong sizeof");
_Static_assert(_Alignof(struct W_2_required_alignment) == 1, "record W_2 wrong alignment");
_Static_assert(sizeof(struct W_2_size) == 3, "record W_2 wrong sizeof");
_Static_assert(_Alignof(struct W_2_size) == 1, "record W_2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(W_2,e) == 0, "field W_2.e wrong bit offset");
#endif
_Static_assert(sizeof(X2) == 1, "record X2 wrong sizeof");
_Static_assert(_Alignof(X2) == 1, "record X2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct X2_alignment) == 2, "record X2 wrong sizeof");
_Static_assert(_Alignof(struct X2_alignment) == 1, "record X2 wrong alignment");
_Static_assert(sizeof(struct X2_packed) == 1, "record X2 wrong sizeof");
_Static_assert(_Alignof(struct X2_packed) == 1, "record X2 wrong alignment");
_Static_assert(sizeof(struct X2_required_alignment) == 2, "record X2 wrong sizeof");
_Static_assert(_Alignof(struct X2_required_alignment) == 1, "record X2 wrong alignment");
_Static_assert(sizeof(struct X2_size) == 3, "record X2 wrong sizeof");
_Static_assert(_Alignof(struct X2_size) == 1, "record X2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(X2,x) == 0, "field X2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(X2,e) == 0, "field X2.e wrong bit offset");
#endif
_Static_assert(sizeof(Y) == 9, "record Y wrong sizeof");
_Static_assert(_Alignof(Y) == 1, "record Y wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Y_alignment) == 10, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_alignment) == 1, "record Y wrong alignment");
_Static_assert(sizeof(struct Y_packed) == 9, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_packed) == 1, "record Y wrong alignment");
_Static_assert(sizeof(struct Y_required_alignment) == 10, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_required_alignment) == 1, "record Y wrong alignment");
_Static_assert(sizeof(struct Y_size) == 11, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_size) == 1, "record Y wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(Y,d) == 64, "field Y.d wrong bit offset");
#endif
_Static_assert(sizeof(Y2) == 1, "record Y2 wrong sizeof");
_Static_assert(_Alignof(Y2) == 1, "record Y2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Y2_alignment) == 2, "record Y2 wrong sizeof");
_Static_assert(_Alignof(struct Y2_alignment) == 1, "record Y2 wrong alignment");
_Static_assert(sizeof(struct Y2_packed) == 1, "record Y2 wrong sizeof");
_Static_assert(_Alignof(struct Y2_packed) == 1, "record Y2 wrong alignment");
_Static_assert(sizeof(struct Y2_required_alignment) == 2, "record Y2 wrong sizeof");
_Static_assert(_Alignof(struct Y2_required_alignment) == 1, "record Y2 wrong alignment");
_Static_assert(sizeof(struct Y2_size) == 3, "record Y2 wrong sizeof");
_Static_assert(_Alignof(struct Y2_size) == 1, "record Y2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(Y2,d) == 0, "field Y2.d wrong bit offset");
#endif
_Static_assert(sizeof(A3) == 33, "record A3 wrong sizeof");
_Static_assert(_Alignof(A3) == 1, "record A3 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A3_alignment) == 34, "record A3 wrong sizeof");
_Static_assert(_Alignof(struct A3_alignment) == 1, "record A3 wrong alignment");
_Static_assert(sizeof(struct A3_packed) == 33, "record A3 wrong sizeof");
_Static_assert(_Alignof(struct A3_packed) == 1, "record A3 wrong alignment");
_Static_assert(sizeof(struct A3_required_alignment) == 34, "record A3 wrong sizeof");
_Static_assert(_Alignof(struct A3_required_alignment) == 1, "record A3 wrong alignment");
_Static_assert(sizeof(struct A3_size) == 35, "record A3 wrong sizeof");
_Static_assert(_Alignof(struct A3_size) == 1, "record A3 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A3,d) == 256, "field A3.d wrong bit offset");
#endif
_Static_assert(sizeof(A4) == 1, "record A4 wrong sizeof");
_Static_assert(_Alignof(A4) == 32, "record A4 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A4_alignment) == 64, "record A4 wrong sizeof");
_Static_assert(_Alignof(struct A4_alignment) == 32, "record A4 wrong alignment");
_Static_assert(sizeof(struct A4_packed) == 1, "record A4 wrong sizeof");
_Static_assert(_Alignof(struct A4_packed) == 1, "record A4 wrong alignment");
_Static_assert(sizeof(struct A4_required_alignment) == 2, "record A4 wrong sizeof");
_Static_assert(_Alignof(struct A4_required_alignment) == 1, "record A4 wrong alignment");
_Static_assert(sizeof(struct A4_size) == 3, "record A4 wrong sizeof");
_Static_assert(_Alignof(struct A4_size) == 1, "record A4 wrong alignment");
#endif
_Static_assert(sizeof(A5) == 33, "record A5 wrong sizeof");
_Static_assert(_Alignof(A5) == 1, "record A5 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A5_alignment) == 34, "record A5 wrong sizeof");
_Static_assert(_Alignof(struct A5_alignment) == 1, "record A5 wrong alignment");
_Static_assert(sizeof(struct A5_packed) == 33, "record A5 wrong sizeof");
_Static_assert(_Alignof(struct A5_packed) == 1, "record A5 wrong alignment");
_Static_assert(sizeof(struct A5_required_alignment) == 34, "record A5 wrong sizeof");
_Static_assert(_Alignof(struct A5_required_alignment) == 1, "record A5 wrong alignment");
_Static_assert(sizeof(struct A5_size) == 35, "record A5 wrong sizeof");
_Static_assert(_Alignof(struct A5_size) == 1, "record A5 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A5,d) == 256, "field A5.d wrong bit offset");
#endif
_Static_assert(sizeof(A7) == 32, "record A7 wrong sizeof");
_Static_assert(_Alignof(A7) == 32, "record A7 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A7_alignment) == 64, "record A7 wrong sizeof");
_Static_assert(_Alignof(struct A7_alignment) == 32, "record A7 wrong alignment");
_Static_assert(sizeof(struct A7_packed) == 32, "record A7 wrong sizeof");
_Static_assert(_Alignof(struct A7_packed) == 1, "record A7 wrong alignment");
_Static_assert(sizeof(struct A7_required_alignment) == 33, "record A7 wrong sizeof");
_Static_assert(_Alignof(struct A7_required_alignment) == 1, "record A7 wrong alignment");
_Static_assert(sizeof(struct A7_size) == 34, "record A7 wrong sizeof");
_Static_assert(_Alignof(struct A7_size) == 1, "record A7 wrong alignment");
#endif
_Static_assert(sizeof(A8) == 8, "record A8 wrong sizeof");
_Static_assert(_Alignof(A8) == 4, "record A8 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A8_alignment) == 12, "record A8 wrong sizeof");
_Static_assert(_Alignof(struct A8_alignment) == 4, "record A8 wrong alignment");
_Static_assert(sizeof(struct A8_packed) == 8, "record A8 wrong sizeof");
_Static_assert(_Alignof(struct A8_packed) == 1, "record A8 wrong alignment");
_Static_assert(sizeof(struct A8_required_alignment) == 9, "record A8 wrong sizeof");
_Static_assert(_Alignof(struct A8_required_alignment) == 1, "record A8 wrong alignment");
_Static_assert(sizeof(struct A8_size) == 10, "record A8 wrong sizeof");
_Static_assert(_Alignof(struct A8_size) == 1, "record A8 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A8,i) == 8, "field A8.i wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A8,j) == 39, "field A8.j wrong bit offset");
#endif
_Static_assert(sizeof(A9) == 12, "record A9 wrong sizeof");
_Static_assert(_Alignof(A9) == 4, "record A9 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A9_alignment) == 16, "record A9 wrong sizeof");
_Static_assert(_Alignof(struct A9_alignment) == 4, "record A9 wrong alignment");
_Static_assert(sizeof(struct A9_packed) == 12, "record A9 wrong sizeof");
_Static_assert(_Alignof(struct A9_packed) == 1, "record A9 wrong alignment");
_Static_assert(sizeof(struct A9_required_alignment) == 13, "record A9 wrong sizeof");
_Static_assert(_Alignof(struct A9_required_alignment) == 1, "record A9 wrong alignment");
_Static_assert(sizeof(struct A9_size) == 14, "record A9 wrong sizeof");
_Static_assert(_Alignof(struct A9_size) == 1, "record A9 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A9,i) == 8, "field A9.i wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A9,j) == 64, "field A9.j wrong bit offset");
#endif
_Static_assert(sizeof(A10) == 4, "record A10 wrong sizeof");
_Static_assert(_Alignof(A10) == 16, "record A10 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A10_alignment) == 32, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_alignment) == 16, "record A10 wrong alignment");
_Static_assert(sizeof(struct A10_packed) == 4, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_packed) == 1, "record A10 wrong alignment");
_Static_assert(sizeof(struct A10_required_alignment) == 5, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_required_alignment) == 1, "record A10 wrong alignment");
_Static_assert(sizeof(struct A10_size) == 6, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_size) == 1, "record A10 wrong alignment");
#endif
_Static_assert(sizeof(A11) == 32, "record A11 wrong sizeof");
_Static_assert(_Alignof(A11) == 16, "record A11 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A11_alignment) == 48, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_alignment) == 16, "record A11 wrong alignment");
_Static_assert(sizeof(struct A11_packed) == 32, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_packed) == 1, "record A11 wrong alignment");
_Static_assert(sizeof(struct A11_required_alignment) == 33, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_required_alignment) == 1, "record A11 wrong alignment");
_Static_assert(sizeof(struct A11_size) == 34, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_size) == 1, "record A11 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A11,i) == 8, "field A11.i wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A11,j) == 128, "field A11.j wrong bit offset");
#endif
_Static_assert(sizeof(A12) == 32, "record A12 wrong sizeof");
_Static_assert(_Alignof(A12) == 16, "record A12 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A12_alignment) == 48, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_alignment) == 16, "record A12 wrong alignment");
_Static_assert(sizeof(struct A12_packed) == 32, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_packed) == 1, "record A12 wrong alignment");
_Static_assert(sizeof(struct A12_required_alignment) == 33, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_required_alignment) == 1, "record A12 wrong alignment");
_Static_assert(sizeof(struct A12_size) == 34, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_size) == 1, "record A12 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A12,i) == 8, "field A12.i wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A12,j) == 128, "field A12.j wrong bit offset");
#endif
_Static_assert(sizeof(A13) == 32, "record A13 wrong sizeof");
_Static_assert(_Alignof(A13) == 16, "record A13 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A13_alignment) == 48, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_alignment) == 16, "record A13 wrong alignment");
_Static_assert(sizeof(struct A13_packed) == 32, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_packed) == 1, "record A13 wrong alignment");
_Static_assert(sizeof(struct A13_required_alignment) == 33, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_required_alignment) == 1, "record A13 wrong alignment");
_Static_assert(sizeof(struct A13_size) == 34, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_size) == 1, "record A13 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A13,i) == 8, "field A13.i wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A13,j) == 128, "field A13.j wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A13,d) == 136, "field A13.d wrong bit offset");
#endif
// MAPPING|NINE|i386-i386-ios-none:Clang|x86_64-i686-macos-none:Clang|i386-i686-linux-android:Clang|i386-i686-freebsd-gnu:Clang|i386-i686-haiku-gnu:Clang|i386-i686-netbsd-gnu:Clang|i386-i686-openbsd-gnu:Clang|END
// repr targets I386AppleIos|Some("i386-i386-ios-none") I686AppleMacosx|Some("x86_64-i686-macos-none") I686LinuxAndroid|Some("i386-i686-linux-android") I686UnknownFreebsd|Some("i386-i686-freebsd-gnu") I686UnknownHaiku|Some("i386-i686-haiku-gnu") I686UnknownNetbsdelf|Some("i386-i686-netbsd-gnu") I686UnknownOpenbsd|Some("i386-i686-openbsd-gnu") 
#elif defined(NINE)
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
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A,d) == 0, "field A.d wrong bit offset");
#endif
_Static_assert(sizeof(A_) == 5, "record A_ wrong sizeof");
_Static_assert(_Alignof(A_) == 1, "record A_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A__alignment) == 6, "record A_ wrong sizeof");
_Static_assert(_Alignof(struct A__alignment) == 1, "record A_ wrong alignment");
_Static_assert(sizeof(struct A__packed) == 5, "record A_ wrong sizeof");
_Static_assert(_Alignof(struct A__packed) == 1, "record A_ wrong alignment");
_Static_assert(sizeof(struct A__required_alignment) == 6, "record A_ wrong sizeof");
_Static_assert(_Alignof(struct A__required_alignment) == 1, "record A_ wrong alignment");
_Static_assert(sizeof(struct A__size) == 7, "record A_ wrong sizeof");
_Static_assert(_Alignof(struct A__size) == 1, "record A_ wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_,d) == 32, "field A_.d wrong bit offset");
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
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B,d) == 0, "field B.d wrong bit offset");
#endif
_Static_assert(sizeof(B_) == 5, "record B_ wrong sizeof");
_Static_assert(_Alignof(B_) == 1, "record B_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B__alignment) == 6, "record B_ wrong sizeof");
_Static_assert(_Alignof(struct B__alignment) == 1, "record B_ wrong alignment");
_Static_assert(sizeof(struct B__packed) == 5, "record B_ wrong sizeof");
_Static_assert(_Alignof(struct B__packed) == 1, "record B_ wrong alignment");
_Static_assert(sizeof(struct B__required_alignment) == 6, "record B_ wrong sizeof");
_Static_assert(_Alignof(struct B__required_alignment) == 1, "record B_ wrong alignment");
_Static_assert(sizeof(struct B__size) == 7, "record B_ wrong sizeof");
_Static_assert(_Alignof(struct B__size) == 1, "record B_ wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B_,d) == 32, "field B_.d wrong bit offset");
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
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C,d) == 0, "field C.d wrong bit offset");
#endif
_Static_assert(sizeof(C_) == 5, "record C_ wrong sizeof");
_Static_assert(_Alignof(C_) == 1, "record C_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C__alignment) == 6, "record C_ wrong sizeof");
_Static_assert(_Alignof(struct C__alignment) == 1, "record C_ wrong alignment");
_Static_assert(sizeof(struct C__packed) == 5, "record C_ wrong sizeof");
_Static_assert(_Alignof(struct C__packed) == 1, "record C_ wrong alignment");
_Static_assert(sizeof(struct C__required_alignment) == 6, "record C_ wrong sizeof");
_Static_assert(_Alignof(struct C__required_alignment) == 1, "record C_ wrong alignment");
_Static_assert(sizeof(struct C__size) == 7, "record C_ wrong sizeof");
_Static_assert(_Alignof(struct C__size) == 1, "record C_ wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C_,d) == 32, "field C_.d wrong bit offset");
#endif
_Static_assert(sizeof(D) == 16, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 4, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 20, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 4, "record D wrong alignment");
_Static_assert(sizeof(struct D_packed) == 16, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 17, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_size) == 18, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_size) == 1, "record D wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D,d) == 32, "field D.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(D,e) == 96, "field D.e wrong bit offset");
#endif
_Static_assert(sizeof(F) == 32, "record F wrong sizeof");
_Static_assert(_Alignof(F) == 16, "record F wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 48, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_alignment) == 16, "record F wrong alignment");
_Static_assert(sizeof(struct F_packed) == 32, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_packed) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_required_alignment) == 33, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_size) == 34, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_size) == 1, "record F wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F,d) == 128, "field F.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(F,e) == 192, "field F.e wrong bit offset");
#endif
_Static_assert(sizeof(G) == 12, "record G wrong sizeof");
_Static_assert(_Alignof(G) == 2, "record G wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 14, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_alignment) == 2, "record G wrong alignment");
_Static_assert(sizeof(struct G_packed) == 12, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_packed) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_required_alignment) == 13, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_size) == 14, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_size) == 1, "record G wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(G,d) == 16, "field G.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(G,e) == 80, "field G.e wrong bit offset");
#endif
_Static_assert(sizeof(H) == 12, "record H wrong sizeof");
_Static_assert(_Alignof(H) == 2, "record H wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 14, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_alignment) == 2, "record H wrong alignment");
_Static_assert(sizeof(struct H_packed) == 12, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_packed) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_required_alignment) == 13, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_size) == 14, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_size) == 1, "record H wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(H,d) == 16, "field H.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(H,e) == 80, "field H.e wrong bit offset");
#endif
_Static_assert(sizeof(I) == 10, "record I wrong sizeof");
_Static_assert(_Alignof(I) == 1, "record I wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I_alignment) == 11, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_alignment) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_packed) == 10, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_packed) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_required_alignment) == 11, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_required_alignment) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_size) == 12, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_size) == 1, "record I wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(I,d) == 8, "field I.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(I,e) == 72, "field I.e wrong bit offset");
#endif
_Static_assert(sizeof(J) == 12, "record J wrong sizeof");
_Static_assert(_Alignof(J) == 2, "record J wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J_alignment) == 14, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_alignment) == 2, "record J wrong alignment");
_Static_assert(sizeof(struct J_packed) == 12, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_packed) == 1, "record J wrong alignment");
_Static_assert(sizeof(struct J_required_alignment) == 13, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_required_alignment) == 1, "record J wrong alignment");
_Static_assert(sizeof(struct J_size) == 14, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_size) == 1, "record J wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(J,d) == 16, "field J.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(J,e) == 80, "field J.e wrong bit offset");
#endif
_Static_assert(sizeof(K) == 4, "record K wrong sizeof");
_Static_assert(_Alignof(K) == 4, "record K wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct K_alignment) == 8, "record K wrong sizeof");
_Static_assert(_Alignof(struct K_alignment) == 4, "record K wrong alignment");
_Static_assert(sizeof(struct K_packed) == 4, "record K wrong sizeof");
_Static_assert(_Alignof(struct K_packed) == 1, "record K wrong alignment");
_Static_assert(sizeof(struct K_required_alignment) == 5, "record K wrong sizeof");
_Static_assert(_Alignof(struct K_required_alignment) == 1, "record K wrong alignment");
_Static_assert(sizeof(struct K_size) == 6, "record K wrong sizeof");
_Static_assert(_Alignof(struct K_size) == 1, "record K wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(K,d) == 8, "field K.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(K,e) == 16, "field K.e wrong bit offset");
#endif
_Static_assert(sizeof(L) == 32, "record L wrong sizeof");
_Static_assert(_Alignof(L) == 16, "record L wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct L_alignment) == 48, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_alignment) == 16, "record L wrong alignment");
_Static_assert(sizeof(struct L_packed) == 32, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_packed) == 1, "record L wrong alignment");
_Static_assert(sizeof(struct L_required_alignment) == 33, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_required_alignment) == 1, "record L wrong alignment");
_Static_assert(sizeof(struct L_size) == 34, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_size) == 1, "record L wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(L,d) == 128, "field L.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(L,e) == 136, "field L.e wrong bit offset");
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
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(M,d) == 16, "field M.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(M,e) == 24, "field M.e wrong bit offset");
#endif
_Static_assert(sizeof(N) == 4, "record N wrong sizeof");
_Static_assert(_Alignof(N) == 2, "record N wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct N_alignment) == 6, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_alignment) == 2, "record N wrong alignment");
_Static_assert(sizeof(struct N_packed) == 4, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_packed) == 1, "record N wrong alignment");
_Static_assert(sizeof(struct N_required_alignment) == 5, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_required_alignment) == 1, "record N wrong alignment");
_Static_assert(sizeof(struct N_size) == 6, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_size) == 1, "record N wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(N,d) == 8, "field N.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(N,e) == 16, "field N.e wrong bit offset");
#endif
_Static_assert(sizeof(O) == 3, "record O wrong sizeof");
_Static_assert(_Alignof(O) == 1, "record O wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct O_alignment) == 4, "record O wrong sizeof");
_Static_assert(_Alignof(struct O_alignment) == 1, "record O wrong alignment");
_Static_assert(sizeof(struct O_packed) == 3, "record O wrong sizeof");
_Static_assert(_Alignof(struct O_packed) == 1, "record O wrong alignment");
_Static_assert(sizeof(struct O_required_alignment) == 4, "record O wrong sizeof");
_Static_assert(_Alignof(struct O_required_alignment) == 1, "record O wrong alignment");
_Static_assert(sizeof(struct O_size) == 5, "record O wrong sizeof");
_Static_assert(_Alignof(struct O_size) == 1, "record O wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(O,d) == 8, "field O.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(O,e) == 16, "field O.e wrong bit offset");
#endif
_Static_assert(sizeof(P) == 4, "record P wrong sizeof");
_Static_assert(_Alignof(P) == 2, "record P wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct P_alignment) == 6, "record P wrong sizeof");
_Static_assert(_Alignof(struct P_alignment) == 2, "record P wrong alignment");
_Static_assert(sizeof(struct P_packed) == 4, "record P wrong sizeof");
_Static_assert(_Alignof(struct P_packed) == 1, "record P wrong alignment");
_Static_assert(sizeof(struct P_required_alignment) == 5, "record P wrong sizeof");
_Static_assert(_Alignof(struct P_required_alignment) == 1, "record P wrong alignment");
_Static_assert(sizeof(struct P_size) == 6, "record P wrong sizeof");
_Static_assert(_Alignof(struct P_size) == 1, "record P wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(P,d) == 8, "field P.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(P,e) == 16, "field P.e wrong bit offset");
#endif
_Static_assert(sizeof(Q) == 4, "record Q wrong sizeof");
_Static_assert(_Alignof(Q) == 4, "record Q wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Q_alignment) == 8, "record Q wrong sizeof");
_Static_assert(_Alignof(struct Q_alignment) == 4, "record Q wrong alignment");
_Static_assert(sizeof(struct Q_packed) == 4, "record Q wrong sizeof");
_Static_assert(_Alignof(struct Q_packed) == 1, "record Q wrong alignment");
_Static_assert(sizeof(struct Q_required_alignment) == 5, "record Q wrong sizeof");
_Static_assert(_Alignof(struct Q_required_alignment) == 1, "record Q wrong alignment");
_Static_assert(sizeof(struct Q_size) == 6, "record Q wrong sizeof");
_Static_assert(_Alignof(struct Q_size) == 1, "record Q wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(Q,x) == 8, "field Q.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(Q,d) == 9, "field Q.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(Q,e) == 16, "field Q.e wrong bit offset");
#endif
_Static_assert(sizeof(R) == 17, "record R wrong sizeof");
_Static_assert(_Alignof(R) == 1, "record R wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct R_alignment) == 18, "record R wrong sizeof");
_Static_assert(_Alignof(struct R_alignment) == 1, "record R wrong alignment");
_Static_assert(sizeof(struct R_packed) == 17, "record R wrong sizeof");
_Static_assert(_Alignof(struct R_packed) == 1, "record R wrong alignment");
_Static_assert(sizeof(struct R_required_alignment) == 18, "record R wrong sizeof");
_Static_assert(_Alignof(struct R_required_alignment) == 1, "record R wrong alignment");
_Static_assert(sizeof(struct R_size) == 19, "record R wrong sizeof");
_Static_assert(_Alignof(struct R_size) == 1, "record R wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(R,x) == 8, "field R.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(R,e) == 128, "field R.e wrong bit offset");
#endif
_Static_assert(sizeof(S) == 5, "record S wrong sizeof");
_Static_assert(_Alignof(S) == 1, "record S wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct S_alignment) == 6, "record S wrong sizeof");
_Static_assert(_Alignof(struct S_alignment) == 1, "record S wrong alignment");
_Static_assert(sizeof(struct S_packed) == 5, "record S wrong sizeof");
_Static_assert(_Alignof(struct S_packed) == 1, "record S wrong alignment");
_Static_assert(sizeof(struct S_required_alignment) == 6, "record S wrong sizeof");
_Static_assert(_Alignof(struct S_required_alignment) == 1, "record S wrong alignment");
_Static_assert(sizeof(struct S_size) == 7, "record S wrong sizeof");
_Static_assert(_Alignof(struct S_size) == 1, "record S wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(S,x) == 8, "field S.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(S,e) == 32, "field S.e wrong bit offset");
#endif
_Static_assert(sizeof(T) == 5, "record T wrong sizeof");
_Static_assert(_Alignof(T) == 1, "record T wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct T_alignment) == 6, "record T wrong sizeof");
_Static_assert(_Alignof(struct T_alignment) == 1, "record T wrong alignment");
_Static_assert(sizeof(struct T_packed) == 5, "record T wrong sizeof");
_Static_assert(_Alignof(struct T_packed) == 1, "record T wrong alignment");
_Static_assert(sizeof(struct T_required_alignment) == 6, "record T wrong sizeof");
_Static_assert(_Alignof(struct T_required_alignment) == 1, "record T wrong alignment");
_Static_assert(sizeof(struct T_size) == 7, "record T wrong sizeof");
_Static_assert(_Alignof(struct T_size) == 1, "record T wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(T,x) == 8, "field T.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(T,e) == 32, "field T.e wrong bit offset");
#endif
_Static_assert(sizeof(U) == 5, "record U wrong sizeof");
_Static_assert(_Alignof(U) == 1, "record U wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct U_alignment) == 6, "record U wrong sizeof");
_Static_assert(_Alignof(struct U_alignment) == 1, "record U wrong alignment");
_Static_assert(sizeof(struct U_packed) == 5, "record U wrong sizeof");
_Static_assert(_Alignof(struct U_packed) == 1, "record U wrong alignment");
_Static_assert(sizeof(struct U_required_alignment) == 6, "record U wrong sizeof");
_Static_assert(_Alignof(struct U_required_alignment) == 1, "record U wrong alignment");
_Static_assert(sizeof(struct U_size) == 7, "record U wrong sizeof");
_Static_assert(_Alignof(struct U_size) == 1, "record U wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(U,x) == 8, "field U.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(U,e) == 32, "field U.e wrong bit offset");
#endif
_Static_assert(sizeof(V) == 5, "record V wrong sizeof");
_Static_assert(_Alignof(V) == 1, "record V wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct V_alignment) == 6, "record V wrong sizeof");
_Static_assert(_Alignof(struct V_alignment) == 1, "record V wrong alignment");
_Static_assert(sizeof(struct V_packed) == 5, "record V wrong sizeof");
_Static_assert(_Alignof(struct V_packed) == 1, "record V wrong alignment");
_Static_assert(sizeof(struct V_required_alignment) == 6, "record V wrong sizeof");
_Static_assert(_Alignof(struct V_required_alignment) == 1, "record V wrong alignment");
_Static_assert(sizeof(struct V_size) == 7, "record V wrong sizeof");
_Static_assert(_Alignof(struct V_size) == 1, "record V wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(V,x) == 8, "field V.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(V,e) == 32, "field V.e wrong bit offset");
#endif
_Static_assert(sizeof(W) == 17, "record W wrong sizeof");
_Static_assert(_Alignof(W) == 1, "record W wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct W_alignment) == 18, "record W wrong sizeof");
_Static_assert(_Alignof(struct W_alignment) == 1, "record W wrong alignment");
_Static_assert(sizeof(struct W_packed) == 17, "record W wrong sizeof");
_Static_assert(_Alignof(struct W_packed) == 1, "record W wrong alignment");
_Static_assert(sizeof(struct W_required_alignment) == 18, "record W wrong sizeof");
_Static_assert(_Alignof(struct W_required_alignment) == 1, "record W wrong alignment");
_Static_assert(sizeof(struct W_size) == 19, "record W wrong sizeof");
_Static_assert(_Alignof(struct W_size) == 1, "record W wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(W,x) == 8, "field W.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(W,e) == 128, "field W.e wrong bit offset");
#endif
_Static_assert(sizeof(W_) == 17, "record W_ wrong sizeof");
_Static_assert(_Alignof(W_) == 1, "record W_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct W__alignment) == 18, "record W_ wrong sizeof");
_Static_assert(_Alignof(struct W__alignment) == 1, "record W_ wrong alignment");
_Static_assert(sizeof(struct W__packed) == 17, "record W_ wrong sizeof");
_Static_assert(_Alignof(struct W__packed) == 1, "record W_ wrong alignment");
_Static_assert(sizeof(struct W__required_alignment) == 18, "record W_ wrong sizeof");
_Static_assert(_Alignof(struct W__required_alignment) == 1, "record W_ wrong alignment");
_Static_assert(sizeof(struct W__size) == 19, "record W_ wrong sizeof");
_Static_assert(_Alignof(struct W__size) == 1, "record W_ wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(W_,e) == 128, "field W_.e wrong bit offset");
#endif
_Static_assert(sizeof(X) == 17, "record X wrong sizeof");
_Static_assert(_Alignof(X) == 1, "record X wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct X_alignment) == 18, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_alignment) == 1, "record X wrong alignment");
_Static_assert(sizeof(struct X_packed) == 17, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_packed) == 1, "record X wrong alignment");
_Static_assert(sizeof(struct X_required_alignment) == 18, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_required_alignment) == 1, "record X wrong alignment");
_Static_assert(sizeof(struct X_size) == 19, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_size) == 1, "record X wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(X,x) == 8, "field X.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(X,e) == 128, "field X.e wrong bit offset");
#endif
_Static_assert(sizeof(A2) == 1, "record A2 wrong sizeof");
_Static_assert(_Alignof(A2) == 1, "record A2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A2_alignment) == 2, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_alignment) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_packed) == 1, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_packed) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_required_alignment) == 2, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_required_alignment) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_size) == 3, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_size) == 1, "record A2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A2,d) == 0, "field A2.d wrong bit offset");
#endif
_Static_assert(sizeof(A_2) == 1, "record A_2 wrong sizeof");
_Static_assert(_Alignof(A_2) == 1, "record A_2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_2_alignment) == 2, "record A_2 wrong sizeof");
_Static_assert(_Alignof(struct A_2_alignment) == 1, "record A_2 wrong alignment");
_Static_assert(sizeof(struct A_2_packed) == 1, "record A_2 wrong sizeof");
_Static_assert(_Alignof(struct A_2_packed) == 1, "record A_2 wrong alignment");
_Static_assert(sizeof(struct A_2_required_alignment) == 2, "record A_2 wrong sizeof");
_Static_assert(_Alignof(struct A_2_required_alignment) == 1, "record A_2 wrong alignment");
_Static_assert(sizeof(struct A_2_size) == 3, "record A_2 wrong sizeof");
_Static_assert(_Alignof(struct A_2_size) == 1, "record A_2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_2,d) == 0, "field A_2.d wrong bit offset");
#endif
_Static_assert(sizeof(B2) == 1, "record B2 wrong sizeof");
_Static_assert(_Alignof(B2) == 1, "record B2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B2_alignment) == 2, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_alignment) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_packed) == 1, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_packed) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_required_alignment) == 2, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_required_alignment) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_size) == 3, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_size) == 1, "record B2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B2,d) == 0, "field B2.d wrong bit offset");
#endif
_Static_assert(sizeof(B_2) == 1, "record B_2 wrong sizeof");
_Static_assert(_Alignof(B_2) == 1, "record B_2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_2_alignment) == 2, "record B_2 wrong sizeof");
_Static_assert(_Alignof(struct B_2_alignment) == 1, "record B_2 wrong alignment");
_Static_assert(sizeof(struct B_2_packed) == 1, "record B_2 wrong sizeof");
_Static_assert(_Alignof(struct B_2_packed) == 1, "record B_2 wrong alignment");
_Static_assert(sizeof(struct B_2_required_alignment) == 2, "record B_2 wrong sizeof");
_Static_assert(_Alignof(struct B_2_required_alignment) == 1, "record B_2 wrong alignment");
_Static_assert(sizeof(struct B_2_size) == 3, "record B_2 wrong sizeof");
_Static_assert(_Alignof(struct B_2_size) == 1, "record B_2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B_2,d) == 0, "field B_2.d wrong bit offset");
#endif
_Static_assert(sizeof(C2) == 1, "record C2 wrong sizeof");
_Static_assert(_Alignof(C2) == 1, "record C2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C2_alignment) == 2, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_alignment) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_packed) == 1, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_packed) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_required_alignment) == 2, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_required_alignment) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_size) == 3, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_size) == 1, "record C2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C2,d) == 0, "field C2.d wrong bit offset");
#endif
_Static_assert(sizeof(C22) == 1, "record C22 wrong sizeof");
_Static_assert(_Alignof(C22) == 1, "record C22 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C22_alignment) == 2, "record C22 wrong sizeof");
_Static_assert(_Alignof(struct C22_alignment) == 1, "record C22 wrong alignment");
_Static_assert(sizeof(struct C22_packed) == 1, "record C22 wrong sizeof");
_Static_assert(_Alignof(struct C22_packed) == 1, "record C22 wrong alignment");
_Static_assert(sizeof(struct C22_required_alignment) == 2, "record C22 wrong sizeof");
_Static_assert(_Alignof(struct C22_required_alignment) == 1, "record C22 wrong alignment");
_Static_assert(sizeof(struct C22_size) == 3, "record C22 wrong sizeof");
_Static_assert(_Alignof(struct C22_size) == 1, "record C22 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C22,d) == 0, "field C22.d wrong bit offset");
#endif
_Static_assert(sizeof(D2) == 8, "record D2 wrong sizeof");
_Static_assert(_Alignof(D2) == 4, "record D2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D2_alignment) == 12, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_alignment) == 4, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_packed) == 8, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_packed) == 1, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_required_alignment) == 9, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_required_alignment) == 1, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_size) == 10, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_size) == 1, "record D2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D2,d) == 0, "field D2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(D2,e) == 0, "field D2.e wrong bit offset");
#endif
_Static_assert(sizeof(F2) == 16, "record F2 wrong sizeof");
_Static_assert(_Alignof(F2) == 16, "record F2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F2_alignment) == 32, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_alignment) == 16, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_packed) == 16, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_packed) == 1, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_required_alignment) == 17, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_required_alignment) == 1, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_size) == 18, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_size) == 1, "record F2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F2,d) == 0, "field F2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(F2,e) == 0, "field F2.e wrong bit offset");
#endif
_Static_assert(sizeof(G2) == 8, "record G2 wrong sizeof");
_Static_assert(_Alignof(G2) == 2, "record G2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G2_alignment) == 10, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_alignment) == 2, "record G2 wrong alignment");
_Static_assert(sizeof(struct G2_packed) == 8, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_packed) == 1, "record G2 wrong alignment");
_Static_assert(sizeof(struct G2_required_alignment) == 9, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_required_alignment) == 1, "record G2 wrong alignment");
_Static_assert(sizeof(struct G2_size) == 10, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_size) == 1, "record G2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(G2,d) == 0, "field G2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(G2,e) == 0, "field G2.e wrong bit offset");
#endif
_Static_assert(sizeof(H2) == 8, "record H2 wrong sizeof");
_Static_assert(_Alignof(H2) == 2, "record H2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H2_alignment) == 10, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_alignment) == 2, "record H2 wrong alignment");
_Static_assert(sizeof(struct H2_packed) == 8, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_packed) == 1, "record H2 wrong alignment");
_Static_assert(sizeof(struct H2_required_alignment) == 9, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_required_alignment) == 1, "record H2 wrong alignment");
_Static_assert(sizeof(struct H2_size) == 10, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_size) == 1, "record H2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(H2,d) == 0, "field H2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(H2,e) == 0, "field H2.e wrong bit offset");
#endif
_Static_assert(sizeof(I2) == 8, "record I2 wrong sizeof");
_Static_assert(_Alignof(I2) == 1, "record I2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I2_alignment) == 9, "record I2 wrong sizeof");
_Static_assert(_Alignof(struct I2_alignment) == 1, "record I2 wrong alignment");
_Static_assert(sizeof(struct I2_packed) == 8, "record I2 wrong sizeof");
_Static_assert(_Alignof(struct I2_packed) == 1, "record I2 wrong alignment");
_Static_assert(sizeof(struct I2_required_alignment) == 9, "record I2 wrong sizeof");
_Static_assert(_Alignof(struct I2_required_alignment) == 1, "record I2 wrong alignment");
_Static_assert(sizeof(struct I2_size) == 10, "record I2 wrong sizeof");
_Static_assert(_Alignof(struct I2_size) == 1, "record I2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(I2,d) == 0, "field I2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(I2,e) == 0, "field I2.e wrong bit offset");
#endif
_Static_assert(sizeof(J2) == 8, "record J2 wrong sizeof");
_Static_assert(_Alignof(J2) == 2, "record J2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J2_alignment) == 10, "record J2 wrong sizeof");
_Static_assert(_Alignof(struct J2_alignment) == 2, "record J2 wrong alignment");
_Static_assert(sizeof(struct J2_packed) == 8, "record J2 wrong sizeof");
_Static_assert(_Alignof(struct J2_packed) == 1, "record J2 wrong alignment");
_Static_assert(sizeof(struct J2_required_alignment) == 9, "record J2 wrong sizeof");
_Static_assert(_Alignof(struct J2_required_alignment) == 1, "record J2 wrong alignment");
_Static_assert(sizeof(struct J2_size) == 10, "record J2 wrong sizeof");
_Static_assert(_Alignof(struct J2_size) == 1, "record J2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(J2,d) == 0, "field J2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(J2,e) == 0, "field J2.e wrong bit offset");
#endif
_Static_assert(sizeof(K2) == 4, "record K2 wrong sizeof");
_Static_assert(_Alignof(K2) == 4, "record K2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct K2_alignment) == 8, "record K2 wrong sizeof");
_Static_assert(_Alignof(struct K2_alignment) == 4, "record K2 wrong alignment");
_Static_assert(sizeof(struct K2_packed) == 4, "record K2 wrong sizeof");
_Static_assert(_Alignof(struct K2_packed) == 1, "record K2 wrong alignment");
_Static_assert(sizeof(struct K2_required_alignment) == 5, "record K2 wrong sizeof");
_Static_assert(_Alignof(struct K2_required_alignment) == 1, "record K2 wrong alignment");
_Static_assert(sizeof(struct K2_size) == 6, "record K2 wrong sizeof");
_Static_assert(_Alignof(struct K2_size) == 1, "record K2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(K2,d) == 0, "field K2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(K2,e) == 0, "field K2.e wrong bit offset");
#endif
_Static_assert(sizeof(L2) == 16, "record L2 wrong sizeof");
_Static_assert(_Alignof(L2) == 16, "record L2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct L2_alignment) == 32, "record L2 wrong sizeof");
_Static_assert(_Alignof(struct L2_alignment) == 16, "record L2 wrong alignment");
_Static_assert(sizeof(struct L2_packed) == 16, "record L2 wrong sizeof");
_Static_assert(_Alignof(struct L2_packed) == 1, "record L2 wrong alignment");
_Static_assert(sizeof(struct L2_required_alignment) == 17, "record L2 wrong sizeof");
_Static_assert(_Alignof(struct L2_required_alignment) == 1, "record L2 wrong alignment");
_Static_assert(sizeof(struct L2_size) == 18, "record L2 wrong sizeof");
_Static_assert(_Alignof(struct L2_size) == 1, "record L2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(L2,d) == 0, "field L2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(L2,e) == 0, "field L2.e wrong bit offset");
#endif
_Static_assert(sizeof(M2) == 2, "record M2 wrong sizeof");
_Static_assert(_Alignof(M2) == 2, "record M2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct M2_alignment) == 4, "record M2 wrong sizeof");
_Static_assert(_Alignof(struct M2_alignment) == 2, "record M2 wrong alignment");
_Static_assert(sizeof(struct M2_packed) == 2, "record M2 wrong sizeof");
_Static_assert(_Alignof(struct M2_packed) == 1, "record M2 wrong alignment");
_Static_assert(sizeof(struct M2_required_alignment) == 3, "record M2 wrong sizeof");
_Static_assert(_Alignof(struct M2_required_alignment) == 1, "record M2 wrong alignment");
_Static_assert(sizeof(struct M2_size) == 4, "record M2 wrong sizeof");
_Static_assert(_Alignof(struct M2_size) == 1, "record M2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(M2,d) == 0, "field M2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(M2,e) == 0, "field M2.e wrong bit offset");
#endif
_Static_assert(sizeof(N2) == 2, "record N2 wrong sizeof");
_Static_assert(_Alignof(N2) == 2, "record N2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct N2_alignment) == 4, "record N2 wrong sizeof");
_Static_assert(_Alignof(struct N2_alignment) == 2, "record N2 wrong alignment");
_Static_assert(sizeof(struct N2_packed) == 2, "record N2 wrong sizeof");
_Static_assert(_Alignof(struct N2_packed) == 1, "record N2 wrong alignment");
_Static_assert(sizeof(struct N2_required_alignment) == 3, "record N2 wrong sizeof");
_Static_assert(_Alignof(struct N2_required_alignment) == 1, "record N2 wrong alignment");
_Static_assert(sizeof(struct N2_size) == 4, "record N2 wrong sizeof");
_Static_assert(_Alignof(struct N2_size) == 1, "record N2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(N2,d) == 0, "field N2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(N2,e) == 0, "field N2.e wrong bit offset");
#endif
_Static_assert(sizeof(O2) == 1, "record O2 wrong sizeof");
_Static_assert(_Alignof(O2) == 1, "record O2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct O2_alignment) == 2, "record O2 wrong sizeof");
_Static_assert(_Alignof(struct O2_alignment) == 1, "record O2 wrong alignment");
_Static_assert(sizeof(struct O2_packed) == 1, "record O2 wrong sizeof");
_Static_assert(_Alignof(struct O2_packed) == 1, "record O2 wrong alignment");
_Static_assert(sizeof(struct O2_required_alignment) == 2, "record O2 wrong sizeof");
_Static_assert(_Alignof(struct O2_required_alignment) == 1, "record O2 wrong alignment");
_Static_assert(sizeof(struct O2_size) == 3, "record O2 wrong sizeof");
_Static_assert(_Alignof(struct O2_size) == 1, "record O2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(O2,d) == 0, "field O2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(O2,e) == 0, "field O2.e wrong bit offset");
#endif
_Static_assert(sizeof(P2) == 2, "record P2 wrong sizeof");
_Static_assert(_Alignof(P2) == 2, "record P2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct P2_alignment) == 4, "record P2 wrong sizeof");
_Static_assert(_Alignof(struct P2_alignment) == 2, "record P2 wrong alignment");
_Static_assert(sizeof(struct P2_packed) == 2, "record P2 wrong sizeof");
_Static_assert(_Alignof(struct P2_packed) == 1, "record P2 wrong alignment");
_Static_assert(sizeof(struct P2_required_alignment) == 3, "record P2 wrong sizeof");
_Static_assert(_Alignof(struct P2_required_alignment) == 1, "record P2 wrong alignment");
_Static_assert(sizeof(struct P2_size) == 4, "record P2 wrong sizeof");
_Static_assert(_Alignof(struct P2_size) == 1, "record P2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(P2,d) == 0, "field P2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(P2,e) == 0, "field P2.e wrong bit offset");
#endif
_Static_assert(sizeof(Q2) == 4, "record Q2 wrong sizeof");
_Static_assert(_Alignof(Q2) == 4, "record Q2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Q2_alignment) == 8, "record Q2 wrong sizeof");
_Static_assert(_Alignof(struct Q2_alignment) == 4, "record Q2 wrong alignment");
_Static_assert(sizeof(struct Q2_packed) == 4, "record Q2 wrong sizeof");
_Static_assert(_Alignof(struct Q2_packed) == 1, "record Q2 wrong alignment");
_Static_assert(sizeof(struct Q2_required_alignment) == 5, "record Q2 wrong sizeof");
_Static_assert(_Alignof(struct Q2_required_alignment) == 1, "record Q2 wrong alignment");
_Static_assert(sizeof(struct Q2_size) == 6, "record Q2 wrong sizeof");
_Static_assert(_Alignof(struct Q2_size) == 1, "record Q2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(Q2,x) == 0, "field Q2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(Q2,d) == 0, "field Q2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(Q2,e) == 0, "field Q2.e wrong bit offset");
#endif
_Static_assert(sizeof(R2) == 1, "record R2 wrong sizeof");
_Static_assert(_Alignof(R2) == 1, "record R2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct R2_alignment) == 2, "record R2 wrong sizeof");
_Static_assert(_Alignof(struct R2_alignment) == 1, "record R2 wrong alignment");
_Static_assert(sizeof(struct R2_packed) == 1, "record R2 wrong sizeof");
_Static_assert(_Alignof(struct R2_packed) == 1, "record R2 wrong alignment");
_Static_assert(sizeof(struct R2_required_alignment) == 2, "record R2 wrong sizeof");
_Static_assert(_Alignof(struct R2_required_alignment) == 1, "record R2 wrong alignment");
_Static_assert(sizeof(struct R2_size) == 3, "record R2 wrong sizeof");
_Static_assert(_Alignof(struct R2_size) == 1, "record R2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(R2,x) == 0, "field R2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(R2,e) == 0, "field R2.e wrong bit offset");
#endif
_Static_assert(sizeof(S2) == 1, "record S2 wrong sizeof");
_Static_assert(_Alignof(S2) == 1, "record S2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct S2_alignment) == 2, "record S2 wrong sizeof");
_Static_assert(_Alignof(struct S2_alignment) == 1, "record S2 wrong alignment");
_Static_assert(sizeof(struct S2_packed) == 1, "record S2 wrong sizeof");
_Static_assert(_Alignof(struct S2_packed) == 1, "record S2 wrong alignment");
_Static_assert(sizeof(struct S2_required_alignment) == 2, "record S2 wrong sizeof");
_Static_assert(_Alignof(struct S2_required_alignment) == 1, "record S2 wrong alignment");
_Static_assert(sizeof(struct S2_size) == 3, "record S2 wrong sizeof");
_Static_assert(_Alignof(struct S2_size) == 1, "record S2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(S2,x) == 0, "field S2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(S2,e) == 0, "field S2.e wrong bit offset");
#endif
_Static_assert(sizeof(T2) == 1, "record T2 wrong sizeof");
_Static_assert(_Alignof(T2) == 1, "record T2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct T2_alignment) == 2, "record T2 wrong sizeof");
_Static_assert(_Alignof(struct T2_alignment) == 1, "record T2 wrong alignment");
_Static_assert(sizeof(struct T2_packed) == 1, "record T2 wrong sizeof");
_Static_assert(_Alignof(struct T2_packed) == 1, "record T2 wrong alignment");
_Static_assert(sizeof(struct T2_required_alignment) == 2, "record T2 wrong sizeof");
_Static_assert(_Alignof(struct T2_required_alignment) == 1, "record T2 wrong alignment");
_Static_assert(sizeof(struct T2_size) == 3, "record T2 wrong sizeof");
_Static_assert(_Alignof(struct T2_size) == 1, "record T2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(T2,x) == 0, "field T2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(T2,e) == 0, "field T2.e wrong bit offset");
#endif
_Static_assert(sizeof(U2) == 1, "record U2 wrong sizeof");
_Static_assert(_Alignof(U2) == 1, "record U2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct U2_alignment) == 2, "record U2 wrong sizeof");
_Static_assert(_Alignof(struct U2_alignment) == 1, "record U2 wrong alignment");
_Static_assert(sizeof(struct U2_packed) == 1, "record U2 wrong sizeof");
_Static_assert(_Alignof(struct U2_packed) == 1, "record U2 wrong alignment");
_Static_assert(sizeof(struct U2_required_alignment) == 2, "record U2 wrong sizeof");
_Static_assert(_Alignof(struct U2_required_alignment) == 1, "record U2 wrong alignment");
_Static_assert(sizeof(struct U2_size) == 3, "record U2 wrong sizeof");
_Static_assert(_Alignof(struct U2_size) == 1, "record U2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(U2,x) == 0, "field U2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(U2,e) == 0, "field U2.e wrong bit offset");
#endif
_Static_assert(sizeof(V2) == 1, "record V2 wrong sizeof");
_Static_assert(_Alignof(V2) == 1, "record V2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct V2_alignment) == 2, "record V2 wrong sizeof");
_Static_assert(_Alignof(struct V2_alignment) == 1, "record V2 wrong alignment");
_Static_assert(sizeof(struct V2_packed) == 1, "record V2 wrong sizeof");
_Static_assert(_Alignof(struct V2_packed) == 1, "record V2 wrong alignment");
_Static_assert(sizeof(struct V2_required_alignment) == 2, "record V2 wrong sizeof");
_Static_assert(_Alignof(struct V2_required_alignment) == 1, "record V2 wrong alignment");
_Static_assert(sizeof(struct V2_size) == 3, "record V2 wrong sizeof");
_Static_assert(_Alignof(struct V2_size) == 1, "record V2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(V2,x) == 0, "field V2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(V2,e) == 0, "field V2.e wrong bit offset");
#endif
_Static_assert(sizeof(W2) == 1, "record W2 wrong sizeof");
_Static_assert(_Alignof(W2) == 1, "record W2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct W2_alignment) == 2, "record W2 wrong sizeof");
_Static_assert(_Alignof(struct W2_alignment) == 1, "record W2 wrong alignment");
_Static_assert(sizeof(struct W2_packed) == 1, "record W2 wrong sizeof");
_Static_assert(_Alignof(struct W2_packed) == 1, "record W2 wrong alignment");
_Static_assert(sizeof(struct W2_required_alignment) == 2, "record W2 wrong sizeof");
_Static_assert(_Alignof(struct W2_required_alignment) == 1, "record W2 wrong alignment");
_Static_assert(sizeof(struct W2_size) == 3, "record W2 wrong sizeof");
_Static_assert(_Alignof(struct W2_size) == 1, "record W2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(W2,x) == 0, "field W2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(W2,e) == 0, "field W2.e wrong bit offset");
#endif
_Static_assert(sizeof(W_2) == 1, "record W_2 wrong sizeof");
_Static_assert(_Alignof(W_2) == 1, "record W_2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct W_2_alignment) == 2, "record W_2 wrong sizeof");
_Static_assert(_Alignof(struct W_2_alignment) == 1, "record W_2 wrong alignment");
_Static_assert(sizeof(struct W_2_packed) == 1, "record W_2 wrong sizeof");
_Static_assert(_Alignof(struct W_2_packed) == 1, "record W_2 wrong alignment");
_Static_assert(sizeof(struct W_2_required_alignment) == 2, "record W_2 wrong sizeof");
_Static_assert(_Alignof(struct W_2_required_alignment) == 1, "record W_2 wrong alignment");
_Static_assert(sizeof(struct W_2_size) == 3, "record W_2 wrong sizeof");
_Static_assert(_Alignof(struct W_2_size) == 1, "record W_2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(W_2,e) == 0, "field W_2.e wrong bit offset");
#endif
_Static_assert(sizeof(X2) == 1, "record X2 wrong sizeof");
_Static_assert(_Alignof(X2) == 1, "record X2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct X2_alignment) == 2, "record X2 wrong sizeof");
_Static_assert(_Alignof(struct X2_alignment) == 1, "record X2 wrong alignment");
_Static_assert(sizeof(struct X2_packed) == 1, "record X2 wrong sizeof");
_Static_assert(_Alignof(struct X2_packed) == 1, "record X2 wrong alignment");
_Static_assert(sizeof(struct X2_required_alignment) == 2, "record X2 wrong sizeof");
_Static_assert(_Alignof(struct X2_required_alignment) == 1, "record X2 wrong alignment");
_Static_assert(sizeof(struct X2_size) == 3, "record X2 wrong sizeof");
_Static_assert(_Alignof(struct X2_size) == 1, "record X2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(X2,x) == 0, "field X2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(X2,e) == 0, "field X2.e wrong bit offset");
#endif
_Static_assert(sizeof(Y) == 5, "record Y wrong sizeof");
_Static_assert(_Alignof(Y) == 1, "record Y wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Y_alignment) == 6, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_alignment) == 1, "record Y wrong alignment");
_Static_assert(sizeof(struct Y_packed) == 5, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_packed) == 1, "record Y wrong alignment");
_Static_assert(sizeof(struct Y_required_alignment) == 6, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_required_alignment) == 1, "record Y wrong alignment");
_Static_assert(sizeof(struct Y_size) == 7, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_size) == 1, "record Y wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(Y,d) == 32, "field Y.d wrong bit offset");
#endif
_Static_assert(sizeof(Y2) == 1, "record Y2 wrong sizeof");
_Static_assert(_Alignof(Y2) == 1, "record Y2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Y2_alignment) == 2, "record Y2 wrong sizeof");
_Static_assert(_Alignof(struct Y2_alignment) == 1, "record Y2 wrong alignment");
_Static_assert(sizeof(struct Y2_packed) == 1, "record Y2 wrong sizeof");
_Static_assert(_Alignof(struct Y2_packed) == 1, "record Y2 wrong alignment");
_Static_assert(sizeof(struct Y2_required_alignment) == 2, "record Y2 wrong sizeof");
_Static_assert(_Alignof(struct Y2_required_alignment) == 1, "record Y2 wrong alignment");
_Static_assert(sizeof(struct Y2_size) == 3, "record Y2 wrong sizeof");
_Static_assert(_Alignof(struct Y2_size) == 1, "record Y2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(Y2,d) == 0, "field Y2.d wrong bit offset");
#endif
_Static_assert(sizeof(A3) == 33, "record A3 wrong sizeof");
_Static_assert(_Alignof(A3) == 1, "record A3 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A3_alignment) == 34, "record A3 wrong sizeof");
_Static_assert(_Alignof(struct A3_alignment) == 1, "record A3 wrong alignment");
_Static_assert(sizeof(struct A3_packed) == 33, "record A3 wrong sizeof");
_Static_assert(_Alignof(struct A3_packed) == 1, "record A3 wrong alignment");
_Static_assert(sizeof(struct A3_required_alignment) == 34, "record A3 wrong sizeof");
_Static_assert(_Alignof(struct A3_required_alignment) == 1, "record A3 wrong alignment");
_Static_assert(sizeof(struct A3_size) == 35, "record A3 wrong sizeof");
_Static_assert(_Alignof(struct A3_size) == 1, "record A3 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A3,d) == 256, "field A3.d wrong bit offset");
#endif
_Static_assert(sizeof(A4) == 1, "record A4 wrong sizeof");
_Static_assert(_Alignof(A4) == 32, "record A4 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A4_alignment) == 64, "record A4 wrong sizeof");
_Static_assert(_Alignof(struct A4_alignment) == 32, "record A4 wrong alignment");
_Static_assert(sizeof(struct A4_packed) == 1, "record A4 wrong sizeof");
_Static_assert(_Alignof(struct A4_packed) == 1, "record A4 wrong alignment");
_Static_assert(sizeof(struct A4_required_alignment) == 2, "record A4 wrong sizeof");
_Static_assert(_Alignof(struct A4_required_alignment) == 1, "record A4 wrong alignment");
_Static_assert(sizeof(struct A4_size) == 3, "record A4 wrong sizeof");
_Static_assert(_Alignof(struct A4_size) == 1, "record A4 wrong alignment");
#endif
_Static_assert(sizeof(A5) == 33, "record A5 wrong sizeof");
_Static_assert(_Alignof(A5) == 1, "record A5 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A5_alignment) == 34, "record A5 wrong sizeof");
_Static_assert(_Alignof(struct A5_alignment) == 1, "record A5 wrong alignment");
_Static_assert(sizeof(struct A5_packed) == 33, "record A5 wrong sizeof");
_Static_assert(_Alignof(struct A5_packed) == 1, "record A5 wrong alignment");
_Static_assert(sizeof(struct A5_required_alignment) == 34, "record A5 wrong sizeof");
_Static_assert(_Alignof(struct A5_required_alignment) == 1, "record A5 wrong alignment");
_Static_assert(sizeof(struct A5_size) == 35, "record A5 wrong sizeof");
_Static_assert(_Alignof(struct A5_size) == 1, "record A5 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A5,d) == 256, "field A5.d wrong bit offset");
#endif
_Static_assert(sizeof(A7) == 32, "record A7 wrong sizeof");
_Static_assert(_Alignof(A7) == 32, "record A7 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A7_alignment) == 64, "record A7 wrong sizeof");
_Static_assert(_Alignof(struct A7_alignment) == 32, "record A7 wrong alignment");
_Static_assert(sizeof(struct A7_packed) == 32, "record A7 wrong sizeof");
_Static_assert(_Alignof(struct A7_packed) == 1, "record A7 wrong alignment");
_Static_assert(sizeof(struct A7_required_alignment) == 33, "record A7 wrong sizeof");
_Static_assert(_Alignof(struct A7_required_alignment) == 1, "record A7 wrong alignment");
_Static_assert(sizeof(struct A7_size) == 34, "record A7 wrong sizeof");
_Static_assert(_Alignof(struct A7_size) == 1, "record A7 wrong alignment");
#endif
_Static_assert(sizeof(A8) == 8, "record A8 wrong sizeof");
_Static_assert(_Alignof(A8) == 4, "record A8 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A8_alignment) == 12, "record A8 wrong sizeof");
_Static_assert(_Alignof(struct A8_alignment) == 4, "record A8 wrong alignment");
_Static_assert(sizeof(struct A8_packed) == 8, "record A8 wrong sizeof");
_Static_assert(_Alignof(struct A8_packed) == 1, "record A8 wrong alignment");
_Static_assert(sizeof(struct A8_required_alignment) == 9, "record A8 wrong sizeof");
_Static_assert(_Alignof(struct A8_required_alignment) == 1, "record A8 wrong alignment");
_Static_assert(sizeof(struct A8_size) == 10, "record A8 wrong sizeof");
_Static_assert(_Alignof(struct A8_size) == 1, "record A8 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A8,i) == 8, "field A8.i wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A8,j) == 39, "field A8.j wrong bit offset");
#endif
_Static_assert(sizeof(A9) == 12, "record A9 wrong sizeof");
_Static_assert(_Alignof(A9) == 4, "record A9 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A9_alignment) == 16, "record A9 wrong sizeof");
_Static_assert(_Alignof(struct A9_alignment) == 4, "record A9 wrong alignment");
_Static_assert(sizeof(struct A9_packed) == 12, "record A9 wrong sizeof");
_Static_assert(_Alignof(struct A9_packed) == 1, "record A9 wrong alignment");
_Static_assert(sizeof(struct A9_required_alignment) == 13, "record A9 wrong sizeof");
_Static_assert(_Alignof(struct A9_required_alignment) == 1, "record A9 wrong alignment");
_Static_assert(sizeof(struct A9_size) == 14, "record A9 wrong sizeof");
_Static_assert(_Alignof(struct A9_size) == 1, "record A9 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A9,i) == 8, "field A9.i wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A9,j) == 64, "field A9.j wrong bit offset");
#endif
_Static_assert(sizeof(A10) == 4, "record A10 wrong sizeof");
_Static_assert(_Alignof(A10) == 16, "record A10 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A10_alignment) == 32, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_alignment) == 16, "record A10 wrong alignment");
_Static_assert(sizeof(struct A10_packed) == 4, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_packed) == 1, "record A10 wrong alignment");
_Static_assert(sizeof(struct A10_required_alignment) == 5, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_required_alignment) == 1, "record A10 wrong alignment");
_Static_assert(sizeof(struct A10_size) == 6, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_size) == 1, "record A10 wrong alignment");
#endif
_Static_assert(sizeof(A11) == 32, "record A11 wrong sizeof");
_Static_assert(_Alignof(A11) == 16, "record A11 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A11_alignment) == 48, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_alignment) == 16, "record A11 wrong alignment");
_Static_assert(sizeof(struct A11_packed) == 32, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_packed) == 1, "record A11 wrong alignment");
_Static_assert(sizeof(struct A11_required_alignment) == 33, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_required_alignment) == 1, "record A11 wrong alignment");
_Static_assert(sizeof(struct A11_size) == 34, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_size) == 1, "record A11 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A11,i) == 8, "field A11.i wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A11,j) == 128, "field A11.j wrong bit offset");
#endif
_Static_assert(sizeof(A12) == 32, "record A12 wrong sizeof");
_Static_assert(_Alignof(A12) == 16, "record A12 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A12_alignment) == 48, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_alignment) == 16, "record A12 wrong alignment");
_Static_assert(sizeof(struct A12_packed) == 32, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_packed) == 1, "record A12 wrong alignment");
_Static_assert(sizeof(struct A12_required_alignment) == 33, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_required_alignment) == 1, "record A12 wrong alignment");
_Static_assert(sizeof(struct A12_size) == 34, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_size) == 1, "record A12 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A12,i) == 8, "field A12.i wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A12,j) == 128, "field A12.j wrong bit offset");
#endif
_Static_assert(sizeof(A13) == 32, "record A13 wrong sizeof");
_Static_assert(_Alignof(A13) == 16, "record A13 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A13_alignment) == 48, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_alignment) == 16, "record A13 wrong alignment");
_Static_assert(sizeof(struct A13_packed) == 32, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_packed) == 1, "record A13 wrong alignment");
_Static_assert(sizeof(struct A13_required_alignment) == 33, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_required_alignment) == 1, "record A13 wrong alignment");
_Static_assert(sizeof(struct A13_size) == 34, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_size) == 1, "record A13 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A13,i) == 8, "field A13.i wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A13,j) == 128, "field A13.j wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A13,d) == 136, "field A13.d wrong bit offset");
#endif
// MAPPING|TEN|i386-i586-linux-gnu:Gcc|i386-i586-linux-musl:Gcc|i386-i686-linux-gnu:Gcc|i386-i686-linux-musl:Gcc|END
// repr targets I586UnknownLinuxGnu|Some("i386-i586-linux-gnu") I586UnknownLinuxMusl|Some("i386-i586-linux-musl") I686UnknownLinuxGnu|Some("i386-i686-linux-gnu") I686UnknownLinuxMusl|Some("i386-i686-linux-musl") 
#elif defined(TEN)
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
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A,d) == 0, "field A.d wrong bit offset");
#endif
_Static_assert(sizeof(A_) == 5, "record A_ wrong sizeof");
_Static_assert(_Alignof(A_) == 1, "record A_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A__alignment) == 6, "record A_ wrong sizeof");
_Static_assert(_Alignof(struct A__alignment) == 1, "record A_ wrong alignment");
_Static_assert(sizeof(struct A__packed) == 5, "record A_ wrong sizeof");
_Static_assert(_Alignof(struct A__packed) == 1, "record A_ wrong alignment");
_Static_assert(sizeof(struct A__required_alignment) == 6, "record A_ wrong sizeof");
_Static_assert(_Alignof(struct A__required_alignment) == 1, "record A_ wrong alignment");
_Static_assert(sizeof(struct A__size) == 7, "record A_ wrong sizeof");
_Static_assert(_Alignof(struct A__size) == 1, "record A_ wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_,d) == 32, "field A_.d wrong bit offset");
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
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B,d) == 0, "field B.d wrong bit offset");
#endif
_Static_assert(sizeof(B_) == 5, "record B_ wrong sizeof");
_Static_assert(_Alignof(B_) == 1, "record B_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B__alignment) == 6, "record B_ wrong sizeof");
_Static_assert(_Alignof(struct B__alignment) == 1, "record B_ wrong alignment");
_Static_assert(sizeof(struct B__packed) == 5, "record B_ wrong sizeof");
_Static_assert(_Alignof(struct B__packed) == 1, "record B_ wrong alignment");
_Static_assert(sizeof(struct B__required_alignment) == 6, "record B_ wrong sizeof");
_Static_assert(_Alignof(struct B__required_alignment) == 1, "record B_ wrong alignment");
_Static_assert(sizeof(struct B__size) == 7, "record B_ wrong sizeof");
_Static_assert(_Alignof(struct B__size) == 1, "record B_ wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B_,d) == 32, "field B_.d wrong bit offset");
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
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C,d) == 0, "field C.d wrong bit offset");
#endif
_Static_assert(sizeof(C_) == 5, "record C_ wrong sizeof");
_Static_assert(_Alignof(C_) == 1, "record C_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C__alignment) == 6, "record C_ wrong sizeof");
_Static_assert(_Alignof(struct C__alignment) == 1, "record C_ wrong alignment");
_Static_assert(sizeof(struct C__packed) == 5, "record C_ wrong sizeof");
_Static_assert(_Alignof(struct C__packed) == 1, "record C_ wrong alignment");
_Static_assert(sizeof(struct C__required_alignment) == 6, "record C_ wrong sizeof");
_Static_assert(_Alignof(struct C__required_alignment) == 1, "record C_ wrong alignment");
_Static_assert(sizeof(struct C__size) == 7, "record C_ wrong sizeof");
_Static_assert(_Alignof(struct C__size) == 1, "record C_ wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C_,d) == 32, "field C_.d wrong bit offset");
#endif
_Static_assert(sizeof(D) == 16, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 4, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 20, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 4, "record D wrong alignment");
_Static_assert(sizeof(struct D_packed) == 16, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 17, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_size) == 18, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_size) == 1, "record D wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D,d) == 32, "field D.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(D,e) == 96, "field D.e wrong bit offset");
#endif
_Static_assert(sizeof(F) == 32, "record F wrong sizeof");
_Static_assert(_Alignof(F) == 16, "record F wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 48, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_alignment) == 16, "record F wrong alignment");
_Static_assert(sizeof(struct F_packed) == 32, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_packed) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_required_alignment) == 33, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_size) == 34, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_size) == 1, "record F wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F,d) == 128, "field F.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(F,e) == 192, "field F.e wrong bit offset");
#endif
_Static_assert(sizeof(G) == 12, "record G wrong sizeof");
_Static_assert(_Alignof(G) == 2, "record G wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 14, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_alignment) == 2, "record G wrong alignment");
_Static_assert(sizeof(struct G_packed) == 12, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_packed) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_required_alignment) == 13, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_size) == 14, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_size) == 1, "record G wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(G,d) == 16, "field G.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(G,e) == 80, "field G.e wrong bit offset");
#endif
_Static_assert(sizeof(H) == 12, "record H wrong sizeof");
_Static_assert(_Alignof(H) == 2, "record H wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 14, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_alignment) == 2, "record H wrong alignment");
_Static_assert(sizeof(struct H_packed) == 12, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_packed) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_required_alignment) == 13, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_size) == 14, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_size) == 1, "record H wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(H,d) == 16, "field H.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(H,e) == 80, "field H.e wrong bit offset");
#endif
_Static_assert(sizeof(I) == 10, "record I wrong sizeof");
_Static_assert(_Alignof(I) == 1, "record I wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I_alignment) == 11, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_alignment) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_packed) == 10, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_packed) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_required_alignment) == 11, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_required_alignment) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_size) == 12, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_size) == 1, "record I wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(I,d) == 8, "field I.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(I,e) == 72, "field I.e wrong bit offset");
#endif
_Static_assert(sizeof(J) == 12, "record J wrong sizeof");
_Static_assert(_Alignof(J) == 2, "record J wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J_alignment) == 14, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_alignment) == 2, "record J wrong alignment");
_Static_assert(sizeof(struct J_packed) == 12, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_packed) == 1, "record J wrong alignment");
_Static_assert(sizeof(struct J_required_alignment) == 13, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_required_alignment) == 1, "record J wrong alignment");
_Static_assert(sizeof(struct J_size) == 14, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_size) == 1, "record J wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(J,d) == 16, "field J.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(J,e) == 80, "field J.e wrong bit offset");
#endif
_Static_assert(sizeof(K) == 4, "record K wrong sizeof");
_Static_assert(_Alignof(K) == 4, "record K wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct K_alignment) == 8, "record K wrong sizeof");
_Static_assert(_Alignof(struct K_alignment) == 4, "record K wrong alignment");
_Static_assert(sizeof(struct K_packed) == 4, "record K wrong sizeof");
_Static_assert(_Alignof(struct K_packed) == 1, "record K wrong alignment");
_Static_assert(sizeof(struct K_required_alignment) == 5, "record K wrong sizeof");
_Static_assert(_Alignof(struct K_required_alignment) == 1, "record K wrong alignment");
_Static_assert(sizeof(struct K_size) == 6, "record K wrong sizeof");
_Static_assert(_Alignof(struct K_size) == 1, "record K wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(K,d) == 8, "field K.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(K,e) == 16, "field K.e wrong bit offset");
#endif
_Static_assert(sizeof(L) == 32, "record L wrong sizeof");
_Static_assert(_Alignof(L) == 16, "record L wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct L_alignment) == 48, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_alignment) == 16, "record L wrong alignment");
_Static_assert(sizeof(struct L_packed) == 32, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_packed) == 1, "record L wrong alignment");
_Static_assert(sizeof(struct L_required_alignment) == 33, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_required_alignment) == 1, "record L wrong alignment");
_Static_assert(sizeof(struct L_size) == 34, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_size) == 1, "record L wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(L,d) == 128, "field L.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(L,e) == 136, "field L.e wrong bit offset");
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
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(M,d) == 16, "field M.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(M,e) == 24, "field M.e wrong bit offset");
#endif
_Static_assert(sizeof(N) == 4, "record N wrong sizeof");
_Static_assert(_Alignof(N) == 2, "record N wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct N_alignment) == 6, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_alignment) == 2, "record N wrong alignment");
_Static_assert(sizeof(struct N_packed) == 4, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_packed) == 1, "record N wrong alignment");
_Static_assert(sizeof(struct N_required_alignment) == 5, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_required_alignment) == 1, "record N wrong alignment");
_Static_assert(sizeof(struct N_size) == 6, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_size) == 1, "record N wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(N,d) == 16, "field N.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(N,e) == 24, "field N.e wrong bit offset");
#endif
_Static_assert(sizeof(O) == 3, "record O wrong sizeof");
_Static_assert(_Alignof(O) == 1, "record O wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct O_alignment) == 4, "record O wrong sizeof");
_Static_assert(_Alignof(struct O_alignment) == 1, "record O wrong alignment");
_Static_assert(sizeof(struct O_packed) == 3, "record O wrong sizeof");
_Static_assert(_Alignof(struct O_packed) == 1, "record O wrong alignment");
_Static_assert(sizeof(struct O_required_alignment) == 4, "record O wrong sizeof");
_Static_assert(_Alignof(struct O_required_alignment) == 1, "record O wrong alignment");
_Static_assert(sizeof(struct O_size) == 5, "record O wrong sizeof");
_Static_assert(_Alignof(struct O_size) == 1, "record O wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(O,d) == 8, "field O.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(O,e) == 16, "field O.e wrong bit offset");
#endif
_Static_assert(sizeof(P) == 4, "record P wrong sizeof");
_Static_assert(_Alignof(P) == 2, "record P wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct P_alignment) == 6, "record P wrong sizeof");
_Static_assert(_Alignof(struct P_alignment) == 2, "record P wrong alignment");
_Static_assert(sizeof(struct P_packed) == 4, "record P wrong sizeof");
_Static_assert(_Alignof(struct P_packed) == 1, "record P wrong alignment");
_Static_assert(sizeof(struct P_required_alignment) == 5, "record P wrong sizeof");
_Static_assert(_Alignof(struct P_required_alignment) == 1, "record P wrong alignment");
_Static_assert(sizeof(struct P_size) == 6, "record P wrong sizeof");
_Static_assert(_Alignof(struct P_size) == 1, "record P wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(P,d) == 8, "field P.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(P,e) == 16, "field P.e wrong bit offset");
#endif
_Static_assert(sizeof(Q) == 4, "record Q wrong sizeof");
_Static_assert(_Alignof(Q) == 4, "record Q wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Q_alignment) == 8, "record Q wrong sizeof");
_Static_assert(_Alignof(struct Q_alignment) == 4, "record Q wrong alignment");
_Static_assert(sizeof(struct Q_packed) == 4, "record Q wrong sizeof");
_Static_assert(_Alignof(struct Q_packed) == 1, "record Q wrong alignment");
_Static_assert(sizeof(struct Q_required_alignment) == 5, "record Q wrong sizeof");
_Static_assert(_Alignof(struct Q_required_alignment) == 1, "record Q wrong alignment");
_Static_assert(sizeof(struct Q_size) == 6, "record Q wrong sizeof");
_Static_assert(_Alignof(struct Q_size) == 1, "record Q wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(Q,x) == 8, "field Q.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(Q,d) == 9, "field Q.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(Q,e) == 16, "field Q.e wrong bit offset");
#endif
_Static_assert(sizeof(R) == 17, "record R wrong sizeof");
_Static_assert(_Alignof(R) == 1, "record R wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct R_alignment) == 18, "record R wrong sizeof");
_Static_assert(_Alignof(struct R_alignment) == 1, "record R wrong alignment");
_Static_assert(sizeof(struct R_packed) == 17, "record R wrong sizeof");
_Static_assert(_Alignof(struct R_packed) == 1, "record R wrong alignment");
_Static_assert(sizeof(struct R_required_alignment) == 18, "record R wrong sizeof");
_Static_assert(_Alignof(struct R_required_alignment) == 1, "record R wrong alignment");
_Static_assert(sizeof(struct R_size) == 19, "record R wrong sizeof");
_Static_assert(_Alignof(struct R_size) == 1, "record R wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(R,x) == 8, "field R.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(R,e) == 128, "field R.e wrong bit offset");
#endif
_Static_assert(sizeof(S) == 5, "record S wrong sizeof");
_Static_assert(_Alignof(S) == 1, "record S wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct S_alignment) == 6, "record S wrong sizeof");
_Static_assert(_Alignof(struct S_alignment) == 1, "record S wrong alignment");
_Static_assert(sizeof(struct S_packed) == 5, "record S wrong sizeof");
_Static_assert(_Alignof(struct S_packed) == 1, "record S wrong alignment");
_Static_assert(sizeof(struct S_required_alignment) == 6, "record S wrong sizeof");
_Static_assert(_Alignof(struct S_required_alignment) == 1, "record S wrong alignment");
_Static_assert(sizeof(struct S_size) == 7, "record S wrong sizeof");
_Static_assert(_Alignof(struct S_size) == 1, "record S wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(S,x) == 8, "field S.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(S,e) == 32, "field S.e wrong bit offset");
#endif
_Static_assert(sizeof(T) == 5, "record T wrong sizeof");
_Static_assert(_Alignof(T) == 1, "record T wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct T_alignment) == 6, "record T wrong sizeof");
_Static_assert(_Alignof(struct T_alignment) == 1, "record T wrong alignment");
_Static_assert(sizeof(struct T_packed) == 5, "record T wrong sizeof");
_Static_assert(_Alignof(struct T_packed) == 1, "record T wrong alignment");
_Static_assert(sizeof(struct T_required_alignment) == 6, "record T wrong sizeof");
_Static_assert(_Alignof(struct T_required_alignment) == 1, "record T wrong alignment");
_Static_assert(sizeof(struct T_size) == 7, "record T wrong sizeof");
_Static_assert(_Alignof(struct T_size) == 1, "record T wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(T,x) == 8, "field T.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(T,e) == 32, "field T.e wrong bit offset");
#endif
_Static_assert(sizeof(U) == 5, "record U wrong sizeof");
_Static_assert(_Alignof(U) == 1, "record U wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct U_alignment) == 6, "record U wrong sizeof");
_Static_assert(_Alignof(struct U_alignment) == 1, "record U wrong alignment");
_Static_assert(sizeof(struct U_packed) == 5, "record U wrong sizeof");
_Static_assert(_Alignof(struct U_packed) == 1, "record U wrong alignment");
_Static_assert(sizeof(struct U_required_alignment) == 6, "record U wrong sizeof");
_Static_assert(_Alignof(struct U_required_alignment) == 1, "record U wrong alignment");
_Static_assert(sizeof(struct U_size) == 7, "record U wrong sizeof");
_Static_assert(_Alignof(struct U_size) == 1, "record U wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(U,x) == 8, "field U.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(U,e) == 32, "field U.e wrong bit offset");
#endif
_Static_assert(sizeof(V) == 5, "record V wrong sizeof");
_Static_assert(_Alignof(V) == 1, "record V wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct V_alignment) == 6, "record V wrong sizeof");
_Static_assert(_Alignof(struct V_alignment) == 1, "record V wrong alignment");
_Static_assert(sizeof(struct V_packed) == 5, "record V wrong sizeof");
_Static_assert(_Alignof(struct V_packed) == 1, "record V wrong alignment");
_Static_assert(sizeof(struct V_required_alignment) == 6, "record V wrong sizeof");
_Static_assert(_Alignof(struct V_required_alignment) == 1, "record V wrong alignment");
_Static_assert(sizeof(struct V_size) == 7, "record V wrong sizeof");
_Static_assert(_Alignof(struct V_size) == 1, "record V wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(V,x) == 8, "field V.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(V,e) == 32, "field V.e wrong bit offset");
#endif
_Static_assert(sizeof(W) == 17, "record W wrong sizeof");
_Static_assert(_Alignof(W) == 1, "record W wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct W_alignment) == 18, "record W wrong sizeof");
_Static_assert(_Alignof(struct W_alignment) == 1, "record W wrong alignment");
_Static_assert(sizeof(struct W_packed) == 17, "record W wrong sizeof");
_Static_assert(_Alignof(struct W_packed) == 1, "record W wrong alignment");
_Static_assert(sizeof(struct W_required_alignment) == 18, "record W wrong sizeof");
_Static_assert(_Alignof(struct W_required_alignment) == 1, "record W wrong alignment");
_Static_assert(sizeof(struct W_size) == 19, "record W wrong sizeof");
_Static_assert(_Alignof(struct W_size) == 1, "record W wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(W,x) == 8, "field W.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(W,e) == 128, "field W.e wrong bit offset");
#endif
_Static_assert(sizeof(W_) == 17, "record W_ wrong sizeof");
_Static_assert(_Alignof(W_) == 1, "record W_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct W__alignment) == 18, "record W_ wrong sizeof");
_Static_assert(_Alignof(struct W__alignment) == 1, "record W_ wrong alignment");
_Static_assert(sizeof(struct W__packed) == 17, "record W_ wrong sizeof");
_Static_assert(_Alignof(struct W__packed) == 1, "record W_ wrong alignment");
_Static_assert(sizeof(struct W__required_alignment) == 18, "record W_ wrong sizeof");
_Static_assert(_Alignof(struct W__required_alignment) == 1, "record W_ wrong alignment");
_Static_assert(sizeof(struct W__size) == 19, "record W_ wrong sizeof");
_Static_assert(_Alignof(struct W__size) == 1, "record W_ wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(W_,e) == 128, "field W_.e wrong bit offset");
#endif
_Static_assert(sizeof(X) == 17, "record X wrong sizeof");
_Static_assert(_Alignof(X) == 1, "record X wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct X_alignment) == 18, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_alignment) == 1, "record X wrong alignment");
_Static_assert(sizeof(struct X_packed) == 17, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_packed) == 1, "record X wrong alignment");
_Static_assert(sizeof(struct X_required_alignment) == 18, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_required_alignment) == 1, "record X wrong alignment");
_Static_assert(sizeof(struct X_size) == 19, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_size) == 1, "record X wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(X,x) == 8, "field X.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(X,e) == 128, "field X.e wrong bit offset");
#endif
_Static_assert(sizeof(A2) == 1, "record A2 wrong sizeof");
_Static_assert(_Alignof(A2) == 1, "record A2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A2_alignment) == 2, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_alignment) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_packed) == 1, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_packed) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_required_alignment) == 2, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_required_alignment) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_size) == 3, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_size) == 1, "record A2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A2,d) == 0, "field A2.d wrong bit offset");
#endif
_Static_assert(sizeof(A_2) == 1, "record A_2 wrong sizeof");
_Static_assert(_Alignof(A_2) == 1, "record A_2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_2_alignment) == 2, "record A_2 wrong sizeof");
_Static_assert(_Alignof(struct A_2_alignment) == 1, "record A_2 wrong alignment");
_Static_assert(sizeof(struct A_2_packed) == 1, "record A_2 wrong sizeof");
_Static_assert(_Alignof(struct A_2_packed) == 1, "record A_2 wrong alignment");
_Static_assert(sizeof(struct A_2_required_alignment) == 2, "record A_2 wrong sizeof");
_Static_assert(_Alignof(struct A_2_required_alignment) == 1, "record A_2 wrong alignment");
_Static_assert(sizeof(struct A_2_size) == 3, "record A_2 wrong sizeof");
_Static_assert(_Alignof(struct A_2_size) == 1, "record A_2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_2,d) == 0, "field A_2.d wrong bit offset");
#endif
_Static_assert(sizeof(B2) == 1, "record B2 wrong sizeof");
_Static_assert(_Alignof(B2) == 1, "record B2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B2_alignment) == 2, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_alignment) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_packed) == 1, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_packed) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_required_alignment) == 2, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_required_alignment) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_size) == 3, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_size) == 1, "record B2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B2,d) == 0, "field B2.d wrong bit offset");
#endif
_Static_assert(sizeof(B_2) == 1, "record B_2 wrong sizeof");
_Static_assert(_Alignof(B_2) == 1, "record B_2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_2_alignment) == 2, "record B_2 wrong sizeof");
_Static_assert(_Alignof(struct B_2_alignment) == 1, "record B_2 wrong alignment");
_Static_assert(sizeof(struct B_2_packed) == 1, "record B_2 wrong sizeof");
_Static_assert(_Alignof(struct B_2_packed) == 1, "record B_2 wrong alignment");
_Static_assert(sizeof(struct B_2_required_alignment) == 2, "record B_2 wrong sizeof");
_Static_assert(_Alignof(struct B_2_required_alignment) == 1, "record B_2 wrong alignment");
_Static_assert(sizeof(struct B_2_size) == 3, "record B_2 wrong sizeof");
_Static_assert(_Alignof(struct B_2_size) == 1, "record B_2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B_2,d) == 0, "field B_2.d wrong bit offset");
#endif
_Static_assert(sizeof(C2) == 1, "record C2 wrong sizeof");
_Static_assert(_Alignof(C2) == 1, "record C2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C2_alignment) == 2, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_alignment) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_packed) == 1, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_packed) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_required_alignment) == 2, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_required_alignment) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_size) == 3, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_size) == 1, "record C2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C2,d) == 0, "field C2.d wrong bit offset");
#endif
_Static_assert(sizeof(C22) == 1, "record C22 wrong sizeof");
_Static_assert(_Alignof(C22) == 1, "record C22 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C22_alignment) == 2, "record C22 wrong sizeof");
_Static_assert(_Alignof(struct C22_alignment) == 1, "record C22 wrong alignment");
_Static_assert(sizeof(struct C22_packed) == 1, "record C22 wrong sizeof");
_Static_assert(_Alignof(struct C22_packed) == 1, "record C22 wrong alignment");
_Static_assert(sizeof(struct C22_required_alignment) == 2, "record C22 wrong sizeof");
_Static_assert(_Alignof(struct C22_required_alignment) == 1, "record C22 wrong alignment");
_Static_assert(sizeof(struct C22_size) == 3, "record C22 wrong sizeof");
_Static_assert(_Alignof(struct C22_size) == 1, "record C22 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C22,d) == 0, "field C22.d wrong bit offset");
#endif
_Static_assert(sizeof(D2) == 8, "record D2 wrong sizeof");
_Static_assert(_Alignof(D2) == 4, "record D2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D2_alignment) == 12, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_alignment) == 4, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_packed) == 8, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_packed) == 1, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_required_alignment) == 9, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_required_alignment) == 1, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_size) == 10, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_size) == 1, "record D2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D2,d) == 0, "field D2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(D2,e) == 0, "field D2.e wrong bit offset");
#endif
_Static_assert(sizeof(F2) == 16, "record F2 wrong sizeof");
_Static_assert(_Alignof(F2) == 16, "record F2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F2_alignment) == 32, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_alignment) == 16, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_packed) == 16, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_packed) == 1, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_required_alignment) == 17, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_required_alignment) == 1, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_size) == 18, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_size) == 1, "record F2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F2,d) == 0, "field F2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(F2,e) == 0, "field F2.e wrong bit offset");
#endif
_Static_assert(sizeof(G2) == 8, "record G2 wrong sizeof");
_Static_assert(_Alignof(G2) == 2, "record G2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G2_alignment) == 10, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_alignment) == 2, "record G2 wrong alignment");
_Static_assert(sizeof(struct G2_packed) == 8, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_packed) == 1, "record G2 wrong alignment");
_Static_assert(sizeof(struct G2_required_alignment) == 9, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_required_alignment) == 1, "record G2 wrong alignment");
_Static_assert(sizeof(struct G2_size) == 10, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_size) == 1, "record G2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(G2,d) == 0, "field G2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(G2,e) == 0, "field G2.e wrong bit offset");
#endif
_Static_assert(sizeof(H2) == 8, "record H2 wrong sizeof");
_Static_assert(_Alignof(H2) == 2, "record H2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H2_alignment) == 10, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_alignment) == 2, "record H2 wrong alignment");
_Static_assert(sizeof(struct H2_packed) == 8, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_packed) == 1, "record H2 wrong alignment");
_Static_assert(sizeof(struct H2_required_alignment) == 9, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_required_alignment) == 1, "record H2 wrong alignment");
_Static_assert(sizeof(struct H2_size) == 10, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_size) == 1, "record H2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(H2,d) == 0, "field H2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(H2,e) == 0, "field H2.e wrong bit offset");
#endif
_Static_assert(sizeof(I2) == 8, "record I2 wrong sizeof");
_Static_assert(_Alignof(I2) == 1, "record I2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I2_alignment) == 9, "record I2 wrong sizeof");
_Static_assert(_Alignof(struct I2_alignment) == 1, "record I2 wrong alignment");
_Static_assert(sizeof(struct I2_packed) == 8, "record I2 wrong sizeof");
_Static_assert(_Alignof(struct I2_packed) == 1, "record I2 wrong alignment");
_Static_assert(sizeof(struct I2_required_alignment) == 9, "record I2 wrong sizeof");
_Static_assert(_Alignof(struct I2_required_alignment) == 1, "record I2 wrong alignment");
_Static_assert(sizeof(struct I2_size) == 10, "record I2 wrong sizeof");
_Static_assert(_Alignof(struct I2_size) == 1, "record I2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(I2,d) == 0, "field I2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(I2,e) == 0, "field I2.e wrong bit offset");
#endif
_Static_assert(sizeof(J2) == 8, "record J2 wrong sizeof");
_Static_assert(_Alignof(J2) == 2, "record J2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J2_alignment) == 10, "record J2 wrong sizeof");
_Static_assert(_Alignof(struct J2_alignment) == 2, "record J2 wrong alignment");
_Static_assert(sizeof(struct J2_packed) == 8, "record J2 wrong sizeof");
_Static_assert(_Alignof(struct J2_packed) == 1, "record J2 wrong alignment");
_Static_assert(sizeof(struct J2_required_alignment) == 9, "record J2 wrong sizeof");
_Static_assert(_Alignof(struct J2_required_alignment) == 1, "record J2 wrong alignment");
_Static_assert(sizeof(struct J2_size) == 10, "record J2 wrong sizeof");
_Static_assert(_Alignof(struct J2_size) == 1, "record J2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(J2,d) == 0, "field J2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(J2,e) == 0, "field J2.e wrong bit offset");
#endif
_Static_assert(sizeof(K2) == 4, "record K2 wrong sizeof");
_Static_assert(_Alignof(K2) == 4, "record K2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct K2_alignment) == 8, "record K2 wrong sizeof");
_Static_assert(_Alignof(struct K2_alignment) == 4, "record K2 wrong alignment");
_Static_assert(sizeof(struct K2_packed) == 4, "record K2 wrong sizeof");
_Static_assert(_Alignof(struct K2_packed) == 1, "record K2 wrong alignment");
_Static_assert(sizeof(struct K2_required_alignment) == 5, "record K2 wrong sizeof");
_Static_assert(_Alignof(struct K2_required_alignment) == 1, "record K2 wrong alignment");
_Static_assert(sizeof(struct K2_size) == 6, "record K2 wrong sizeof");
_Static_assert(_Alignof(struct K2_size) == 1, "record K2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(K2,d) == 0, "field K2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(K2,e) == 0, "field K2.e wrong bit offset");
#endif
_Static_assert(sizeof(L2) == 16, "record L2 wrong sizeof");
_Static_assert(_Alignof(L2) == 16, "record L2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct L2_alignment) == 32, "record L2 wrong sizeof");
_Static_assert(_Alignof(struct L2_alignment) == 16, "record L2 wrong alignment");
_Static_assert(sizeof(struct L2_packed) == 16, "record L2 wrong sizeof");
_Static_assert(_Alignof(struct L2_packed) == 1, "record L2 wrong alignment");
_Static_assert(sizeof(struct L2_required_alignment) == 17, "record L2 wrong sizeof");
_Static_assert(_Alignof(struct L2_required_alignment) == 1, "record L2 wrong alignment");
_Static_assert(sizeof(struct L2_size) == 18, "record L2 wrong sizeof");
_Static_assert(_Alignof(struct L2_size) == 1, "record L2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(L2,d) == 0, "field L2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(L2,e) == 0, "field L2.e wrong bit offset");
#endif
_Static_assert(sizeof(M2) == 2, "record M2 wrong sizeof");
_Static_assert(_Alignof(M2) == 2, "record M2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct M2_alignment) == 4, "record M2 wrong sizeof");
_Static_assert(_Alignof(struct M2_alignment) == 2, "record M2 wrong alignment");
_Static_assert(sizeof(struct M2_packed) == 2, "record M2 wrong sizeof");
_Static_assert(_Alignof(struct M2_packed) == 1, "record M2 wrong alignment");
_Static_assert(sizeof(struct M2_required_alignment) == 3, "record M2 wrong sizeof");
_Static_assert(_Alignof(struct M2_required_alignment) == 1, "record M2 wrong alignment");
_Static_assert(sizeof(struct M2_size) == 4, "record M2 wrong sizeof");
_Static_assert(_Alignof(struct M2_size) == 1, "record M2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(M2,d) == 0, "field M2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(M2,e) == 0, "field M2.e wrong bit offset");
#endif
_Static_assert(sizeof(N2) == 2, "record N2 wrong sizeof");
_Static_assert(_Alignof(N2) == 2, "record N2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct N2_alignment) == 4, "record N2 wrong sizeof");
_Static_assert(_Alignof(struct N2_alignment) == 2, "record N2 wrong alignment");
_Static_assert(sizeof(struct N2_packed) == 2, "record N2 wrong sizeof");
_Static_assert(_Alignof(struct N2_packed) == 1, "record N2 wrong alignment");
_Static_assert(sizeof(struct N2_required_alignment) == 3, "record N2 wrong sizeof");
_Static_assert(_Alignof(struct N2_required_alignment) == 1, "record N2 wrong alignment");
_Static_assert(sizeof(struct N2_size) == 4, "record N2 wrong sizeof");
_Static_assert(_Alignof(struct N2_size) == 1, "record N2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(N2,d) == 0, "field N2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(N2,e) == 0, "field N2.e wrong bit offset");
#endif
_Static_assert(sizeof(O2) == 1, "record O2 wrong sizeof");
_Static_assert(_Alignof(O2) == 1, "record O2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct O2_alignment) == 2, "record O2 wrong sizeof");
_Static_assert(_Alignof(struct O2_alignment) == 1, "record O2 wrong alignment");
_Static_assert(sizeof(struct O2_packed) == 1, "record O2 wrong sizeof");
_Static_assert(_Alignof(struct O2_packed) == 1, "record O2 wrong alignment");
_Static_assert(sizeof(struct O2_required_alignment) == 2, "record O2 wrong sizeof");
_Static_assert(_Alignof(struct O2_required_alignment) == 1, "record O2 wrong alignment");
_Static_assert(sizeof(struct O2_size) == 3, "record O2 wrong sizeof");
_Static_assert(_Alignof(struct O2_size) == 1, "record O2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(O2,d) == 0, "field O2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(O2,e) == 0, "field O2.e wrong bit offset");
#endif
_Static_assert(sizeof(P2) == 2, "record P2 wrong sizeof");
_Static_assert(_Alignof(P2) == 2, "record P2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct P2_alignment) == 4, "record P2 wrong sizeof");
_Static_assert(_Alignof(struct P2_alignment) == 2, "record P2 wrong alignment");
_Static_assert(sizeof(struct P2_packed) == 2, "record P2 wrong sizeof");
_Static_assert(_Alignof(struct P2_packed) == 1, "record P2 wrong alignment");
_Static_assert(sizeof(struct P2_required_alignment) == 3, "record P2 wrong sizeof");
_Static_assert(_Alignof(struct P2_required_alignment) == 1, "record P2 wrong alignment");
_Static_assert(sizeof(struct P2_size) == 4, "record P2 wrong sizeof");
_Static_assert(_Alignof(struct P2_size) == 1, "record P2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(P2,d) == 0, "field P2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(P2,e) == 0, "field P2.e wrong bit offset");
#endif
_Static_assert(sizeof(Q2) == 4, "record Q2 wrong sizeof");
_Static_assert(_Alignof(Q2) == 4, "record Q2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Q2_alignment) == 8, "record Q2 wrong sizeof");
_Static_assert(_Alignof(struct Q2_alignment) == 4, "record Q2 wrong alignment");
_Static_assert(sizeof(struct Q2_packed) == 4, "record Q2 wrong sizeof");
_Static_assert(_Alignof(struct Q2_packed) == 1, "record Q2 wrong alignment");
_Static_assert(sizeof(struct Q2_required_alignment) == 5, "record Q2 wrong sizeof");
_Static_assert(_Alignof(struct Q2_required_alignment) == 1, "record Q2 wrong alignment");
_Static_assert(sizeof(struct Q2_size) == 6, "record Q2 wrong sizeof");
_Static_assert(_Alignof(struct Q2_size) == 1, "record Q2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(Q2,x) == 0, "field Q2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(Q2,d) == 0, "field Q2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(Q2,e) == 0, "field Q2.e wrong bit offset");
#endif
_Static_assert(sizeof(R2) == 1, "record R2 wrong sizeof");
_Static_assert(_Alignof(R2) == 1, "record R2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct R2_alignment) == 2, "record R2 wrong sizeof");
_Static_assert(_Alignof(struct R2_alignment) == 1, "record R2 wrong alignment");
_Static_assert(sizeof(struct R2_packed) == 1, "record R2 wrong sizeof");
_Static_assert(_Alignof(struct R2_packed) == 1, "record R2 wrong alignment");
_Static_assert(sizeof(struct R2_required_alignment) == 2, "record R2 wrong sizeof");
_Static_assert(_Alignof(struct R2_required_alignment) == 1, "record R2 wrong alignment");
_Static_assert(sizeof(struct R2_size) == 3, "record R2 wrong sizeof");
_Static_assert(_Alignof(struct R2_size) == 1, "record R2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(R2,x) == 0, "field R2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(R2,e) == 0, "field R2.e wrong bit offset");
#endif
_Static_assert(sizeof(S2) == 1, "record S2 wrong sizeof");
_Static_assert(_Alignof(S2) == 1, "record S2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct S2_alignment) == 2, "record S2 wrong sizeof");
_Static_assert(_Alignof(struct S2_alignment) == 1, "record S2 wrong alignment");
_Static_assert(sizeof(struct S2_packed) == 1, "record S2 wrong sizeof");
_Static_assert(_Alignof(struct S2_packed) == 1, "record S2 wrong alignment");
_Static_assert(sizeof(struct S2_required_alignment) == 2, "record S2 wrong sizeof");
_Static_assert(_Alignof(struct S2_required_alignment) == 1, "record S2 wrong alignment");
_Static_assert(sizeof(struct S2_size) == 3, "record S2 wrong sizeof");
_Static_assert(_Alignof(struct S2_size) == 1, "record S2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(S2,x) == 0, "field S2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(S2,e) == 0, "field S2.e wrong bit offset");
#endif
_Static_assert(sizeof(T2) == 1, "record T2 wrong sizeof");
_Static_assert(_Alignof(T2) == 1, "record T2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct T2_alignment) == 2, "record T2 wrong sizeof");
_Static_assert(_Alignof(struct T2_alignment) == 1, "record T2 wrong alignment");
_Static_assert(sizeof(struct T2_packed) == 1, "record T2 wrong sizeof");
_Static_assert(_Alignof(struct T2_packed) == 1, "record T2 wrong alignment");
_Static_assert(sizeof(struct T2_required_alignment) == 2, "record T2 wrong sizeof");
_Static_assert(_Alignof(struct T2_required_alignment) == 1, "record T2 wrong alignment");
_Static_assert(sizeof(struct T2_size) == 3, "record T2 wrong sizeof");
_Static_assert(_Alignof(struct T2_size) == 1, "record T2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(T2,x) == 0, "field T2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(T2,e) == 0, "field T2.e wrong bit offset");
#endif
_Static_assert(sizeof(U2) == 1, "record U2 wrong sizeof");
_Static_assert(_Alignof(U2) == 1, "record U2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct U2_alignment) == 2, "record U2 wrong sizeof");
_Static_assert(_Alignof(struct U2_alignment) == 1, "record U2 wrong alignment");
_Static_assert(sizeof(struct U2_packed) == 1, "record U2 wrong sizeof");
_Static_assert(_Alignof(struct U2_packed) == 1, "record U2 wrong alignment");
_Static_assert(sizeof(struct U2_required_alignment) == 2, "record U2 wrong sizeof");
_Static_assert(_Alignof(struct U2_required_alignment) == 1, "record U2 wrong alignment");
_Static_assert(sizeof(struct U2_size) == 3, "record U2 wrong sizeof");
_Static_assert(_Alignof(struct U2_size) == 1, "record U2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(U2,x) == 0, "field U2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(U2,e) == 0, "field U2.e wrong bit offset");
#endif
_Static_assert(sizeof(V2) == 1, "record V2 wrong sizeof");
_Static_assert(_Alignof(V2) == 1, "record V2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct V2_alignment) == 2, "record V2 wrong sizeof");
_Static_assert(_Alignof(struct V2_alignment) == 1, "record V2 wrong alignment");
_Static_assert(sizeof(struct V2_packed) == 1, "record V2 wrong sizeof");
_Static_assert(_Alignof(struct V2_packed) == 1, "record V2 wrong alignment");
_Static_assert(sizeof(struct V2_required_alignment) == 2, "record V2 wrong sizeof");
_Static_assert(_Alignof(struct V2_required_alignment) == 1, "record V2 wrong alignment");
_Static_assert(sizeof(struct V2_size) == 3, "record V2 wrong sizeof");
_Static_assert(_Alignof(struct V2_size) == 1, "record V2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(V2,x) == 0, "field V2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(V2,e) == 0, "field V2.e wrong bit offset");
#endif
_Static_assert(sizeof(W2) == 1, "record W2 wrong sizeof");
_Static_assert(_Alignof(W2) == 1, "record W2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct W2_alignment) == 2, "record W2 wrong sizeof");
_Static_assert(_Alignof(struct W2_alignment) == 1, "record W2 wrong alignment");
_Static_assert(sizeof(struct W2_packed) == 1, "record W2 wrong sizeof");
_Static_assert(_Alignof(struct W2_packed) == 1, "record W2 wrong alignment");
_Static_assert(sizeof(struct W2_required_alignment) == 2, "record W2 wrong sizeof");
_Static_assert(_Alignof(struct W2_required_alignment) == 1, "record W2 wrong alignment");
_Static_assert(sizeof(struct W2_size) == 3, "record W2 wrong sizeof");
_Static_assert(_Alignof(struct W2_size) == 1, "record W2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(W2,x) == 0, "field W2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(W2,e) == 0, "field W2.e wrong bit offset");
#endif
_Static_assert(sizeof(W_2) == 1, "record W_2 wrong sizeof");
_Static_assert(_Alignof(W_2) == 1, "record W_2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct W_2_alignment) == 2, "record W_2 wrong sizeof");
_Static_assert(_Alignof(struct W_2_alignment) == 1, "record W_2 wrong alignment");
_Static_assert(sizeof(struct W_2_packed) == 1, "record W_2 wrong sizeof");
_Static_assert(_Alignof(struct W_2_packed) == 1, "record W_2 wrong alignment");
_Static_assert(sizeof(struct W_2_required_alignment) == 2, "record W_2 wrong sizeof");
_Static_assert(_Alignof(struct W_2_required_alignment) == 1, "record W_2 wrong alignment");
_Static_assert(sizeof(struct W_2_size) == 3, "record W_2 wrong sizeof");
_Static_assert(_Alignof(struct W_2_size) == 1, "record W_2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(W_2,e) == 0, "field W_2.e wrong bit offset");
#endif
_Static_assert(sizeof(X2) == 1, "record X2 wrong sizeof");
_Static_assert(_Alignof(X2) == 1, "record X2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct X2_alignment) == 2, "record X2 wrong sizeof");
_Static_assert(_Alignof(struct X2_alignment) == 1, "record X2 wrong alignment");
_Static_assert(sizeof(struct X2_packed) == 1, "record X2 wrong sizeof");
_Static_assert(_Alignof(struct X2_packed) == 1, "record X2 wrong alignment");
_Static_assert(sizeof(struct X2_required_alignment) == 2, "record X2 wrong sizeof");
_Static_assert(_Alignof(struct X2_required_alignment) == 1, "record X2 wrong alignment");
_Static_assert(sizeof(struct X2_size) == 3, "record X2 wrong sizeof");
_Static_assert(_Alignof(struct X2_size) == 1, "record X2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(X2,x) == 0, "field X2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(X2,e) == 0, "field X2.e wrong bit offset");
#endif
_Static_assert(sizeof(Y) == 5, "record Y wrong sizeof");
_Static_assert(_Alignof(Y) == 1, "record Y wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Y_alignment) == 6, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_alignment) == 1, "record Y wrong alignment");
_Static_assert(sizeof(struct Y_packed) == 5, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_packed) == 1, "record Y wrong alignment");
_Static_assert(sizeof(struct Y_required_alignment) == 6, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_required_alignment) == 1, "record Y wrong alignment");
_Static_assert(sizeof(struct Y_size) == 7, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_size) == 1, "record Y wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(Y,d) == 32, "field Y.d wrong bit offset");
#endif
_Static_assert(sizeof(Y2) == 1, "record Y2 wrong sizeof");
_Static_assert(_Alignof(Y2) == 1, "record Y2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Y2_alignment) == 2, "record Y2 wrong sizeof");
_Static_assert(_Alignof(struct Y2_alignment) == 1, "record Y2 wrong alignment");
_Static_assert(sizeof(struct Y2_packed) == 1, "record Y2 wrong sizeof");
_Static_assert(_Alignof(struct Y2_packed) == 1, "record Y2 wrong alignment");
_Static_assert(sizeof(struct Y2_required_alignment) == 2, "record Y2 wrong sizeof");
_Static_assert(_Alignof(struct Y2_required_alignment) == 1, "record Y2 wrong alignment");
_Static_assert(sizeof(struct Y2_size) == 3, "record Y2 wrong sizeof");
_Static_assert(_Alignof(struct Y2_size) == 1, "record Y2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(Y2,d) == 0, "field Y2.d wrong bit offset");
#endif
_Static_assert(sizeof(A3) == 33, "record A3 wrong sizeof");
_Static_assert(_Alignof(A3) == 1, "record A3 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A3_alignment) == 34, "record A3 wrong sizeof");
_Static_assert(_Alignof(struct A3_alignment) == 1, "record A3 wrong alignment");
_Static_assert(sizeof(struct A3_packed) == 33, "record A3 wrong sizeof");
_Static_assert(_Alignof(struct A3_packed) == 1, "record A3 wrong alignment");
_Static_assert(sizeof(struct A3_required_alignment) == 34, "record A3 wrong sizeof");
_Static_assert(_Alignof(struct A3_required_alignment) == 1, "record A3 wrong alignment");
_Static_assert(sizeof(struct A3_size) == 35, "record A3 wrong sizeof");
_Static_assert(_Alignof(struct A3_size) == 1, "record A3 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A3,d) == 256, "field A3.d wrong bit offset");
#endif
_Static_assert(sizeof(A4) == 1, "record A4 wrong sizeof");
_Static_assert(_Alignof(A4) == 32, "record A4 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A4_alignment) == 64, "record A4 wrong sizeof");
_Static_assert(_Alignof(struct A4_alignment) == 32, "record A4 wrong alignment");
_Static_assert(sizeof(struct A4_packed) == 1, "record A4 wrong sizeof");
_Static_assert(_Alignof(struct A4_packed) == 1, "record A4 wrong alignment");
_Static_assert(sizeof(struct A4_required_alignment) == 2, "record A4 wrong sizeof");
_Static_assert(_Alignof(struct A4_required_alignment) == 1, "record A4 wrong alignment");
_Static_assert(sizeof(struct A4_size) == 3, "record A4 wrong sizeof");
_Static_assert(_Alignof(struct A4_size) == 1, "record A4 wrong alignment");
#endif
_Static_assert(sizeof(A5) == 33, "record A5 wrong sizeof");
_Static_assert(_Alignof(A5) == 1, "record A5 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A5_alignment) == 34, "record A5 wrong sizeof");
_Static_assert(_Alignof(struct A5_alignment) == 1, "record A5 wrong alignment");
_Static_assert(sizeof(struct A5_packed) == 33, "record A5 wrong sizeof");
_Static_assert(_Alignof(struct A5_packed) == 1, "record A5 wrong alignment");
_Static_assert(sizeof(struct A5_required_alignment) == 34, "record A5 wrong sizeof");
_Static_assert(_Alignof(struct A5_required_alignment) == 1, "record A5 wrong alignment");
_Static_assert(sizeof(struct A5_size) == 35, "record A5 wrong sizeof");
_Static_assert(_Alignof(struct A5_size) == 1, "record A5 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A5,d) == 256, "field A5.d wrong bit offset");
#endif
_Static_assert(sizeof(A7) == 32, "record A7 wrong sizeof");
_Static_assert(_Alignof(A7) == 32, "record A7 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A7_alignment) == 64, "record A7 wrong sizeof");
_Static_assert(_Alignof(struct A7_alignment) == 32, "record A7 wrong alignment");
_Static_assert(sizeof(struct A7_packed) == 32, "record A7 wrong sizeof");
_Static_assert(_Alignof(struct A7_packed) == 1, "record A7 wrong alignment");
_Static_assert(sizeof(struct A7_required_alignment) == 33, "record A7 wrong sizeof");
_Static_assert(_Alignof(struct A7_required_alignment) == 1, "record A7 wrong alignment");
_Static_assert(sizeof(struct A7_size) == 34, "record A7 wrong sizeof");
_Static_assert(_Alignof(struct A7_size) == 1, "record A7 wrong alignment");
#endif
_Static_assert(sizeof(A8) == 8, "record A8 wrong sizeof");
_Static_assert(_Alignof(A8) == 4, "record A8 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A8_alignment) == 12, "record A8 wrong sizeof");
_Static_assert(_Alignof(struct A8_alignment) == 4, "record A8 wrong alignment");
_Static_assert(sizeof(struct A8_packed) == 8, "record A8 wrong sizeof");
_Static_assert(_Alignof(struct A8_packed) == 1, "record A8 wrong alignment");
_Static_assert(sizeof(struct A8_required_alignment) == 9, "record A8 wrong sizeof");
_Static_assert(_Alignof(struct A8_required_alignment) == 1, "record A8 wrong alignment");
_Static_assert(sizeof(struct A8_size) == 10, "record A8 wrong sizeof");
_Static_assert(_Alignof(struct A8_size) == 1, "record A8 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A8,i) == 8, "field A8.i wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A8,j) == 39, "field A8.j wrong bit offset");
#endif
_Static_assert(sizeof(A9) == 12, "record A9 wrong sizeof");
_Static_assert(_Alignof(A9) == 4, "record A9 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A9_alignment) == 16, "record A9 wrong sizeof");
_Static_assert(_Alignof(struct A9_alignment) == 4, "record A9 wrong alignment");
_Static_assert(sizeof(struct A9_packed) == 12, "record A9 wrong sizeof");
_Static_assert(_Alignof(struct A9_packed) == 1, "record A9 wrong alignment");
_Static_assert(sizeof(struct A9_required_alignment) == 13, "record A9 wrong sizeof");
_Static_assert(_Alignof(struct A9_required_alignment) == 1, "record A9 wrong alignment");
_Static_assert(sizeof(struct A9_size) == 14, "record A9 wrong sizeof");
_Static_assert(_Alignof(struct A9_size) == 1, "record A9 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A9,i) == 8, "field A9.i wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A9,j) == 64, "field A9.j wrong bit offset");
#endif
_Static_assert(sizeof(A10) == 4, "record A10 wrong sizeof");
_Static_assert(_Alignof(A10) == 16, "record A10 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A10_alignment) == 32, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_alignment) == 16, "record A10 wrong alignment");
_Static_assert(sizeof(struct A10_packed) == 4, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_packed) == 1, "record A10 wrong alignment");
_Static_assert(sizeof(struct A10_required_alignment) == 5, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_required_alignment) == 1, "record A10 wrong alignment");
_Static_assert(sizeof(struct A10_size) == 6, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_size) == 1, "record A10 wrong alignment");
#endif
_Static_assert(sizeof(A11) == 32, "record A11 wrong sizeof");
_Static_assert(_Alignof(A11) == 16, "record A11 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A11_alignment) == 48, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_alignment) == 16, "record A11 wrong alignment");
_Static_assert(sizeof(struct A11_packed) == 32, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_packed) == 1, "record A11 wrong alignment");
_Static_assert(sizeof(struct A11_required_alignment) == 33, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_required_alignment) == 1, "record A11 wrong alignment");
_Static_assert(sizeof(struct A11_size) == 34, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_size) == 1, "record A11 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A11,i) == 8, "field A11.i wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A11,j) == 128, "field A11.j wrong bit offset");
#endif
_Static_assert(sizeof(A12) == 32, "record A12 wrong sizeof");
_Static_assert(_Alignof(A12) == 16, "record A12 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A12_alignment) == 48, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_alignment) == 16, "record A12 wrong alignment");
_Static_assert(sizeof(struct A12_packed) == 32, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_packed) == 1, "record A12 wrong alignment");
_Static_assert(sizeof(struct A12_required_alignment) == 33, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_required_alignment) == 1, "record A12 wrong alignment");
_Static_assert(sizeof(struct A12_size) == 34, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_size) == 1, "record A12 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A12,i) == 8, "field A12.i wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A12,j) == 128, "field A12.j wrong bit offset");
#endif
_Static_assert(sizeof(A13) == 32, "record A13 wrong sizeof");
_Static_assert(_Alignof(A13) == 16, "record A13 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A13_alignment) == 48, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_alignment) == 16, "record A13 wrong alignment");
_Static_assert(sizeof(struct A13_packed) == 32, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_packed) == 1, "record A13 wrong alignment");
_Static_assert(sizeof(struct A13_required_alignment) == 33, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_required_alignment) == 1, "record A13 wrong alignment");
_Static_assert(sizeof(struct A13_size) == 34, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_size) == 1, "record A13 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A13,i) == 8, "field A13.i wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A13,j) == 128, "field A13.j wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A13,d) == 136, "field A13.d wrong bit offset");
#endif
// MAPPING|ELEVEN|i386-i686-windows-gnu:Gcc|x86_64-x86_64-windows-gnu:Gcc|END
// repr targets I686PcWindowsGnu|Some("i386-i686-windows-gnu") X86_64PcWindowsGnu|Some("x86_64-x86_64-windows-gnu") 
#elif defined(ELEVEN)
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
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A,d) == 0, "field A.d wrong bit offset");
#endif
_Static_assert(sizeof(A_) == 5, "record A_ wrong sizeof");
_Static_assert(_Alignof(A_) == 1, "record A_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A__alignment) == 6, "record A_ wrong sizeof");
_Static_assert(_Alignof(struct A__alignment) == 1, "record A_ wrong alignment");
_Static_assert(sizeof(struct A__packed) == 5, "record A_ wrong sizeof");
_Static_assert(_Alignof(struct A__packed) == 1, "record A_ wrong alignment");
_Static_assert(sizeof(struct A__required_alignment) == 6, "record A_ wrong sizeof");
_Static_assert(_Alignof(struct A__required_alignment) == 1, "record A_ wrong alignment");
_Static_assert(sizeof(struct A__size) == 7, "record A_ wrong sizeof");
_Static_assert(_Alignof(struct A__size) == 1, "record A_ wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_,d) == 32, "field A_.d wrong bit offset");
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
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B,d) == 0, "field B.d wrong bit offset");
#endif
_Static_assert(sizeof(B_) == 5, "record B_ wrong sizeof");
_Static_assert(_Alignof(B_) == 1, "record B_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B__alignment) == 6, "record B_ wrong sizeof");
_Static_assert(_Alignof(struct B__alignment) == 1, "record B_ wrong alignment");
_Static_assert(sizeof(struct B__packed) == 5, "record B_ wrong sizeof");
_Static_assert(_Alignof(struct B__packed) == 1, "record B_ wrong alignment");
_Static_assert(sizeof(struct B__required_alignment) == 6, "record B_ wrong sizeof");
_Static_assert(_Alignof(struct B__required_alignment) == 1, "record B_ wrong alignment");
_Static_assert(sizeof(struct B__size) == 7, "record B_ wrong sizeof");
_Static_assert(_Alignof(struct B__size) == 1, "record B_ wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B_,d) == 32, "field B_.d wrong bit offset");
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
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C,d) == 0, "field C.d wrong bit offset");
#endif
_Static_assert(sizeof(C_) == 2, "record C_ wrong sizeof");
_Static_assert(_Alignof(C_) == 1, "record C_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C__alignment) == 3, "record C_ wrong sizeof");
_Static_assert(_Alignof(struct C__alignment) == 1, "record C_ wrong alignment");
_Static_assert(sizeof(struct C__packed) == 2, "record C_ wrong sizeof");
_Static_assert(_Alignof(struct C__packed) == 1, "record C_ wrong alignment");
_Static_assert(sizeof(struct C__required_alignment) == 3, "record C_ wrong sizeof");
_Static_assert(_Alignof(struct C__required_alignment) == 1, "record C_ wrong alignment");
_Static_assert(sizeof(struct C__size) == 4, "record C_ wrong sizeof");
_Static_assert(_Alignof(struct C__size) == 1, "record C_ wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C_,d) == 8, "field C_.d wrong bit offset");
#endif
_Static_assert(sizeof(D) == 24, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 8, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 32, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 8, "record D wrong alignment");
_Static_assert(sizeof(struct D_packed) == 24, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 25, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_size) == 26, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_size) == 1, "record D wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D,d) == 64, "field D.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(D,e) == 128, "field D.e wrong bit offset");
#endif
_Static_assert(sizeof(F) == 32, "record F wrong sizeof");
_Static_assert(_Alignof(F) == 16, "record F wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 48, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_alignment) == 16, "record F wrong alignment");
_Static_assert(sizeof(struct F_packed) == 32, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_packed) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_required_alignment) == 33, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_size) == 34, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_size) == 1, "record F wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F,d) == 128, "field F.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(F,e) == 192, "field F.e wrong bit offset");
#endif
_Static_assert(sizeof(G) == 12, "record G wrong sizeof");
_Static_assert(_Alignof(G) == 2, "record G wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 14, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_alignment) == 2, "record G wrong alignment");
_Static_assert(sizeof(struct G_packed) == 12, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_packed) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_required_alignment) == 13, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_size) == 14, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_size) == 1, "record G wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(G,d) == 16, "field G.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(G,e) == 80, "field G.e wrong bit offset");
#endif
_Static_assert(sizeof(H) == 12, "record H wrong sizeof");
_Static_assert(_Alignof(H) == 2, "record H wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 14, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_alignment) == 2, "record H wrong alignment");
_Static_assert(sizeof(struct H_packed) == 12, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_packed) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_required_alignment) == 13, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_size) == 14, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_size) == 1, "record H wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(H,d) == 16, "field H.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(H,e) == 80, "field H.e wrong bit offset");
#endif
_Static_assert(sizeof(I) == 10, "record I wrong sizeof");
_Static_assert(_Alignof(I) == 1, "record I wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I_alignment) == 11, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_alignment) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_packed) == 10, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_packed) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_required_alignment) == 11, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_required_alignment) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_size) == 12, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_size) == 1, "record I wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(I,d) == 8, "field I.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(I,e) == 72, "field I.e wrong bit offset");
#endif
_Static_assert(sizeof(J) == 12, "record J wrong sizeof");
_Static_assert(_Alignof(J) == 2, "record J wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J_alignment) == 14, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_alignment) == 2, "record J wrong alignment");
_Static_assert(sizeof(struct J_packed) == 12, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_packed) == 1, "record J wrong alignment");
_Static_assert(sizeof(struct J_required_alignment) == 13, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_required_alignment) == 1, "record J wrong alignment");
_Static_assert(sizeof(struct J_size) == 14, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_size) == 1, "record J wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(J,d) == 16, "field J.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(J,e) == 80, "field J.e wrong bit offset");
#endif
_Static_assert(sizeof(K) == 24, "record K wrong sizeof");
_Static_assert(_Alignof(K) == 8, "record K wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct K_alignment) == 32, "record K wrong sizeof");
_Static_assert(_Alignof(struct K_alignment) == 8, "record K wrong alignment");
_Static_assert(sizeof(struct K_packed) == 24, "record K wrong sizeof");
_Static_assert(_Alignof(struct K_packed) == 1, "record K wrong alignment");
_Static_assert(sizeof(struct K_required_alignment) == 25, "record K wrong sizeof");
_Static_assert(_Alignof(struct K_required_alignment) == 1, "record K wrong alignment");
_Static_assert(sizeof(struct K_size) == 26, "record K wrong sizeof");
_Static_assert(_Alignof(struct K_size) == 1, "record K wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(K,d) == 64, "field K.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(K,e) == 128, "field K.e wrong bit offset");
#endif
_Static_assert(sizeof(L) == 32, "record L wrong sizeof");
_Static_assert(_Alignof(L) == 16, "record L wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct L_alignment) == 48, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_alignment) == 16, "record L wrong alignment");
_Static_assert(sizeof(struct L_packed) == 32, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_packed) == 1, "record L wrong alignment");
_Static_assert(sizeof(struct L_required_alignment) == 33, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_required_alignment) == 1, "record L wrong alignment");
_Static_assert(sizeof(struct L_size) == 34, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_size) == 1, "record L wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(L,d) == 128, "field L.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(L,e) == 192, "field L.e wrong bit offset");
#endif
_Static_assert(sizeof(M) == 11, "record M wrong sizeof");
_Static_assert(_Alignof(M) == 1, "record M wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct M_alignment) == 12, "record M wrong sizeof");
_Static_assert(_Alignof(struct M_alignment) == 1, "record M wrong alignment");
_Static_assert(sizeof(struct M_packed) == 11, "record M wrong sizeof");
_Static_assert(_Alignof(struct M_packed) == 1, "record M wrong alignment");
_Static_assert(sizeof(struct M_required_alignment) == 12, "record M wrong sizeof");
_Static_assert(_Alignof(struct M_required_alignment) == 1, "record M wrong alignment");
_Static_assert(sizeof(struct M_size) == 13, "record M wrong sizeof");
_Static_assert(_Alignof(struct M_size) == 1, "record M wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(M,d) == 16, "field M.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(M,e) == 80, "field M.e wrong bit offset");
#endif
_Static_assert(sizeof(N) == 11, "record N wrong sizeof");
_Static_assert(_Alignof(N) == 1, "record N wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct N_alignment) == 12, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_alignment) == 1, "record N wrong alignment");
_Static_assert(sizeof(struct N_packed) == 11, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_packed) == 1, "record N wrong alignment");
_Static_assert(sizeof(struct N_required_alignment) == 12, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_required_alignment) == 1, "record N wrong alignment");
_Static_assert(sizeof(struct N_size) == 13, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_size) == 1, "record N wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(N,d) == 16, "field N.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(N,e) == 80, "field N.e wrong bit offset");
#endif
_Static_assert(sizeof(O) == 10, "record O wrong sizeof");
_Static_assert(_Alignof(O) == 1, "record O wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct O_alignment) == 11, "record O wrong sizeof");
_Static_assert(_Alignof(struct O_alignment) == 1, "record O wrong alignment");
_Static_assert(sizeof(struct O_packed) == 10, "record O wrong sizeof");
_Static_assert(_Alignof(struct O_packed) == 1, "record O wrong alignment");
_Static_assert(sizeof(struct O_required_alignment) == 11, "record O wrong sizeof");
_Static_assert(_Alignof(struct O_required_alignment) == 1, "record O wrong alignment");
_Static_assert(sizeof(struct O_size) == 12, "record O wrong sizeof");
_Static_assert(_Alignof(struct O_size) == 1, "record O wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(O,d) == 8, "field O.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(O,e) == 72, "field O.e wrong bit offset");
#endif
_Static_assert(sizeof(P) == 12, "record P wrong sizeof");
_Static_assert(_Alignof(P) == 2, "record P wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct P_alignment) == 14, "record P wrong sizeof");
_Static_assert(_Alignof(struct P_alignment) == 2, "record P wrong alignment");
_Static_assert(sizeof(struct P_packed) == 12, "record P wrong sizeof");
_Static_assert(_Alignof(struct P_packed) == 1, "record P wrong alignment");
_Static_assert(sizeof(struct P_required_alignment) == 13, "record P wrong sizeof");
_Static_assert(_Alignof(struct P_required_alignment) == 1, "record P wrong alignment");
_Static_assert(sizeof(struct P_size) == 14, "record P wrong sizeof");
_Static_assert(_Alignof(struct P_size) == 1, "record P wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(P,d) == 16, "field P.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(P,e) == 80, "field P.e wrong bit offset");
#endif
_Static_assert(sizeof(Q) == 24, "record Q wrong sizeof");
_Static_assert(_Alignof(Q) == 8, "record Q wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Q_alignment) == 32, "record Q wrong sizeof");
_Static_assert(_Alignof(struct Q_alignment) == 8, "record Q wrong alignment");
_Static_assert(sizeof(struct Q_packed) == 24, "record Q wrong sizeof");
_Static_assert(_Alignof(struct Q_packed) == 1, "record Q wrong alignment");
_Static_assert(sizeof(struct Q_required_alignment) == 25, "record Q wrong sizeof");
_Static_assert(_Alignof(struct Q_required_alignment) == 1, "record Q wrong alignment");
_Static_assert(sizeof(struct Q_size) == 26, "record Q wrong sizeof");
_Static_assert(_Alignof(struct Q_size) == 1, "record Q wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(Q,x) == 8, "field Q.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(Q,d) == 64, "field Q.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(Q,e) == 128, "field Q.e wrong bit offset");
#endif
_Static_assert(sizeof(R) == 32, "record R wrong sizeof");
_Static_assert(_Alignof(R) == 16, "record R wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct R_alignment) == 48, "record R wrong sizeof");
_Static_assert(_Alignof(struct R_alignment) == 16, "record R wrong alignment");
_Static_assert(sizeof(struct R_packed) == 32, "record R wrong sizeof");
_Static_assert(_Alignof(struct R_packed) == 1, "record R wrong alignment");
_Static_assert(sizeof(struct R_required_alignment) == 33, "record R wrong sizeof");
_Static_assert(_Alignof(struct R_required_alignment) == 1, "record R wrong alignment");
_Static_assert(sizeof(struct R_size) == 34, "record R wrong sizeof");
_Static_assert(_Alignof(struct R_size) == 1, "record R wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(R,x) == 8, "field R.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(R,e) == 128, "field R.e wrong bit offset");
#endif
_Static_assert(sizeof(S) == 8, "record S wrong sizeof");
_Static_assert(_Alignof(S) == 8, "record S wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct S_alignment) == 16, "record S wrong sizeof");
_Static_assert(_Alignof(struct S_alignment) == 8, "record S wrong alignment");
_Static_assert(sizeof(struct S_packed) == 8, "record S wrong sizeof");
_Static_assert(_Alignof(struct S_packed) == 1, "record S wrong alignment");
_Static_assert(sizeof(struct S_required_alignment) == 9, "record S wrong sizeof");
_Static_assert(_Alignof(struct S_required_alignment) == 1, "record S wrong alignment");
_Static_assert(sizeof(struct S_size) == 10, "record S wrong sizeof");
_Static_assert(_Alignof(struct S_size) == 1, "record S wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(S,x) == 8, "field S.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(S,e) == 16, "field S.e wrong bit offset");
#endif
_Static_assert(sizeof(T) == 4, "record T wrong sizeof");
_Static_assert(_Alignof(T) == 2, "record T wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct T_alignment) == 6, "record T wrong sizeof");
_Static_assert(_Alignof(struct T_alignment) == 2, "record T wrong alignment");
_Static_assert(sizeof(struct T_packed) == 4, "record T wrong sizeof");
_Static_assert(_Alignof(struct T_packed) == 1, "record T wrong alignment");
_Static_assert(sizeof(struct T_required_alignment) == 5, "record T wrong sizeof");
_Static_assert(_Alignof(struct T_required_alignment) == 1, "record T wrong alignment");
_Static_assert(sizeof(struct T_size) == 6, "record T wrong sizeof");
_Static_assert(_Alignof(struct T_size) == 1, "record T wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(T,x) == 8, "field T.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(T,e) == 16, "field T.e wrong bit offset");
#endif
_Static_assert(sizeof(U) == 8, "record U wrong sizeof");
_Static_assert(_Alignof(U) == 8, "record U wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct U_alignment) == 16, "record U wrong sizeof");
_Static_assert(_Alignof(struct U_alignment) == 8, "record U wrong alignment");
_Static_assert(sizeof(struct U_packed) == 8, "record U wrong sizeof");
_Static_assert(_Alignof(struct U_packed) == 1, "record U wrong alignment");
_Static_assert(sizeof(struct U_required_alignment) == 9, "record U wrong sizeof");
_Static_assert(_Alignof(struct U_required_alignment) == 1, "record U wrong alignment");
_Static_assert(sizeof(struct U_size) == 10, "record U wrong sizeof");
_Static_assert(_Alignof(struct U_size) == 1, "record U wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(U,x) == 8, "field U.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(U,e) == 16, "field U.e wrong bit offset");
#endif
_Static_assert(sizeof(V) == 4, "record V wrong sizeof");
_Static_assert(_Alignof(V) == 2, "record V wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct V_alignment) == 6, "record V wrong sizeof");
_Static_assert(_Alignof(struct V_alignment) == 2, "record V wrong alignment");
_Static_assert(sizeof(struct V_packed) == 4, "record V wrong sizeof");
_Static_assert(_Alignof(struct V_packed) == 1, "record V wrong alignment");
_Static_assert(sizeof(struct V_required_alignment) == 5, "record V wrong sizeof");
_Static_assert(_Alignof(struct V_required_alignment) == 1, "record V wrong alignment");
_Static_assert(sizeof(struct V_size) == 6, "record V wrong sizeof");
_Static_assert(_Alignof(struct V_size) == 1, "record V wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(V,x) == 8, "field V.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(V,e) == 16, "field V.e wrong bit offset");
#endif
_Static_assert(sizeof(W) == 32, "record W wrong sizeof");
_Static_assert(_Alignof(W) == 16, "record W wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct W_alignment) == 48, "record W wrong sizeof");
_Static_assert(_Alignof(struct W_alignment) == 16, "record W wrong alignment");
_Static_assert(sizeof(struct W_packed) == 32, "record W wrong sizeof");
_Static_assert(_Alignof(struct W_packed) == 1, "record W wrong alignment");
_Static_assert(sizeof(struct W_required_alignment) == 33, "record W wrong sizeof");
_Static_assert(_Alignof(struct W_required_alignment) == 1, "record W wrong alignment");
_Static_assert(sizeof(struct W_size) == 34, "record W wrong sizeof");
_Static_assert(_Alignof(struct W_size) == 1, "record W wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(W,x) == 8, "field W.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(W,e) == 128, "field W.e wrong bit offset");
#endif
_Static_assert(sizeof(W_) == 2, "record W_ wrong sizeof");
_Static_assert(_Alignof(W_) == 1, "record W_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct W__alignment) == 3, "record W_ wrong sizeof");
_Static_assert(_Alignof(struct W__alignment) == 1, "record W_ wrong alignment");
_Static_assert(sizeof(struct W__packed) == 2, "record W_ wrong sizeof");
_Static_assert(_Alignof(struct W__packed) == 1, "record W_ wrong alignment");
_Static_assert(sizeof(struct W__required_alignment) == 3, "record W_ wrong sizeof");
_Static_assert(_Alignof(struct W__required_alignment) == 1, "record W_ wrong alignment");
_Static_assert(sizeof(struct W__size) == 4, "record W_ wrong sizeof");
_Static_assert(_Alignof(struct W__size) == 1, "record W_ wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(W_,e) == 8, "field W_.e wrong bit offset");
#endif
_Static_assert(sizeof(X) == 4, "record X wrong sizeof");
_Static_assert(_Alignof(X) == 2, "record X wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct X_alignment) == 6, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_alignment) == 2, "record X wrong alignment");
_Static_assert(sizeof(struct X_packed) == 4, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_packed) == 1, "record X wrong alignment");
_Static_assert(sizeof(struct X_required_alignment) == 5, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_required_alignment) == 1, "record X wrong alignment");
_Static_assert(sizeof(struct X_size) == 6, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_size) == 1, "record X wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(X,x) == 8, "field X.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(X,e) == 16, "field X.e wrong bit offset");
#endif
_Static_assert(sizeof(A2) == 1, "record A2 wrong sizeof");
_Static_assert(_Alignof(A2) == 1, "record A2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A2_alignment) == 2, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_alignment) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_packed) == 1, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_packed) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_required_alignment) == 2, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_required_alignment) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_size) == 3, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_size) == 1, "record A2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A2,d) == 0, "field A2.d wrong bit offset");
#endif
_Static_assert(sizeof(A_2) == 1, "record A_2 wrong sizeof");
_Static_assert(_Alignof(A_2) == 1, "record A_2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_2_alignment) == 2, "record A_2 wrong sizeof");
_Static_assert(_Alignof(struct A_2_alignment) == 1, "record A_2 wrong alignment");
_Static_assert(sizeof(struct A_2_packed) == 1, "record A_2 wrong sizeof");
_Static_assert(_Alignof(struct A_2_packed) == 1, "record A_2 wrong alignment");
_Static_assert(sizeof(struct A_2_required_alignment) == 2, "record A_2 wrong sizeof");
_Static_assert(_Alignof(struct A_2_required_alignment) == 1, "record A_2 wrong alignment");
_Static_assert(sizeof(struct A_2_size) == 3, "record A_2 wrong sizeof");
_Static_assert(_Alignof(struct A_2_size) == 1, "record A_2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_2,d) == 0, "field A_2.d wrong bit offset");
#endif
_Static_assert(sizeof(B2) == 1, "record B2 wrong sizeof");
_Static_assert(_Alignof(B2) == 1, "record B2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B2_alignment) == 2, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_alignment) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_packed) == 1, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_packed) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_required_alignment) == 2, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_required_alignment) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_size) == 3, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_size) == 1, "record B2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B2,d) == 0, "field B2.d wrong bit offset");
#endif
_Static_assert(sizeof(B_2) == 1, "record B_2 wrong sizeof");
_Static_assert(_Alignof(B_2) == 1, "record B_2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_2_alignment) == 2, "record B_2 wrong sizeof");
_Static_assert(_Alignof(struct B_2_alignment) == 1, "record B_2 wrong alignment");
_Static_assert(sizeof(struct B_2_packed) == 1, "record B_2 wrong sizeof");
_Static_assert(_Alignof(struct B_2_packed) == 1, "record B_2 wrong alignment");
_Static_assert(sizeof(struct B_2_required_alignment) == 2, "record B_2 wrong sizeof");
_Static_assert(_Alignof(struct B_2_required_alignment) == 1, "record B_2 wrong alignment");
_Static_assert(sizeof(struct B_2_size) == 3, "record B_2 wrong sizeof");
_Static_assert(_Alignof(struct B_2_size) == 1, "record B_2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B_2,d) == 0, "field B_2.d wrong bit offset");
#endif
_Static_assert(sizeof(C2) == 1, "record C2 wrong sizeof");
_Static_assert(_Alignof(C2) == 1, "record C2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C2_alignment) == 2, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_alignment) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_packed) == 1, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_packed) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_required_alignment) == 2, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_required_alignment) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_size) == 3, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_size) == 1, "record C2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C2,d) == 0, "field C2.d wrong bit offset");
#endif
_Static_assert(sizeof(C22) == 1, "record C22 wrong sizeof");
_Static_assert(_Alignof(C22) == 1, "record C22 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C22_alignment) == 2, "record C22 wrong sizeof");
_Static_assert(_Alignof(struct C22_alignment) == 1, "record C22 wrong alignment");
_Static_assert(sizeof(struct C22_packed) == 1, "record C22 wrong sizeof");
_Static_assert(_Alignof(struct C22_packed) == 1, "record C22 wrong alignment");
_Static_assert(sizeof(struct C22_required_alignment) == 2, "record C22 wrong sizeof");
_Static_assert(_Alignof(struct C22_required_alignment) == 1, "record C22 wrong alignment");
_Static_assert(sizeof(struct C22_size) == 3, "record C22 wrong sizeof");
_Static_assert(_Alignof(struct C22_size) == 1, "record C22 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C22,d) == 0, "field C22.d wrong bit offset");
#endif
_Static_assert(sizeof(D2) == 8, "record D2 wrong sizeof");
_Static_assert(_Alignof(D2) == 8, "record D2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D2_alignment) == 16, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_alignment) == 8, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_packed) == 8, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_packed) == 1, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_required_alignment) == 9, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_required_alignment) == 1, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_size) == 10, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_size) == 1, "record D2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D2,d) == 0, "field D2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(D2,e) == 0, "field D2.e wrong bit offset");
#endif
_Static_assert(sizeof(F2) == 16, "record F2 wrong sizeof");
_Static_assert(_Alignof(F2) == 16, "record F2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F2_alignment) == 32, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_alignment) == 16, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_packed) == 16, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_packed) == 1, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_required_alignment) == 17, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_required_alignment) == 1, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_size) == 18, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_size) == 1, "record F2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F2,d) == 0, "field F2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(F2,e) == 0, "field F2.e wrong bit offset");
#endif
_Static_assert(sizeof(G2) == 8, "record G2 wrong sizeof");
_Static_assert(_Alignof(G2) == 2, "record G2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G2_alignment) == 10, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_alignment) == 2, "record G2 wrong alignment");
_Static_assert(sizeof(struct G2_packed) == 8, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_packed) == 1, "record G2 wrong alignment");
_Static_assert(sizeof(struct G2_required_alignment) == 9, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_required_alignment) == 1, "record G2 wrong alignment");
_Static_assert(sizeof(struct G2_size) == 10, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_size) == 1, "record G2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(G2,d) == 0, "field G2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(G2,e) == 0, "field G2.e wrong bit offset");
#endif
_Static_assert(sizeof(H2) == 8, "record H2 wrong sizeof");
_Static_assert(_Alignof(H2) == 2, "record H2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H2_alignment) == 10, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_alignment) == 2, "record H2 wrong alignment");
_Static_assert(sizeof(struct H2_packed) == 8, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_packed) == 1, "record H2 wrong alignment");
_Static_assert(sizeof(struct H2_required_alignment) == 9, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_required_alignment) == 1, "record H2 wrong alignment");
_Static_assert(sizeof(struct H2_size) == 10, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_size) == 1, "record H2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(H2,d) == 0, "field H2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(H2,e) == 0, "field H2.e wrong bit offset");
#endif
_Static_assert(sizeof(I2) == 8, "record I2 wrong sizeof");
_Static_assert(_Alignof(I2) == 1, "record I2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I2_alignment) == 9, "record I2 wrong sizeof");
_Static_assert(_Alignof(struct I2_alignment) == 1, "record I2 wrong alignment");
_Static_assert(sizeof(struct I2_packed) == 8, "record I2 wrong sizeof");
_Static_assert(_Alignof(struct I2_packed) == 1, "record I2 wrong alignment");
_Static_assert(sizeof(struct I2_required_alignment) == 9, "record I2 wrong sizeof");
_Static_assert(_Alignof(struct I2_required_alignment) == 1, "record I2 wrong alignment");
_Static_assert(sizeof(struct I2_size) == 10, "record I2 wrong sizeof");
_Static_assert(_Alignof(struct I2_size) == 1, "record I2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(I2,d) == 0, "field I2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(I2,e) == 0, "field I2.e wrong bit offset");
#endif
_Static_assert(sizeof(J2) == 8, "record J2 wrong sizeof");
_Static_assert(_Alignof(J2) == 2, "record J2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J2_alignment) == 10, "record J2 wrong sizeof");
_Static_assert(_Alignof(struct J2_alignment) == 2, "record J2 wrong alignment");
_Static_assert(sizeof(struct J2_packed) == 8, "record J2 wrong sizeof");
_Static_assert(_Alignof(struct J2_packed) == 1, "record J2 wrong alignment");
_Static_assert(sizeof(struct J2_required_alignment) == 9, "record J2 wrong sizeof");
_Static_assert(_Alignof(struct J2_required_alignment) == 1, "record J2 wrong alignment");
_Static_assert(sizeof(struct J2_size) == 10, "record J2 wrong sizeof");
_Static_assert(_Alignof(struct J2_size) == 1, "record J2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(J2,d) == 0, "field J2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(J2,e) == 0, "field J2.e wrong bit offset");
#endif
_Static_assert(sizeof(K2) == 8, "record K2 wrong sizeof");
_Static_assert(_Alignof(K2) == 8, "record K2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct K2_alignment) == 16, "record K2 wrong sizeof");
_Static_assert(_Alignof(struct K2_alignment) == 8, "record K2 wrong alignment");
_Static_assert(sizeof(struct K2_packed) == 8, "record K2 wrong sizeof");
_Static_assert(_Alignof(struct K2_packed) == 1, "record K2 wrong alignment");
_Static_assert(sizeof(struct K2_required_alignment) == 9, "record K2 wrong sizeof");
_Static_assert(_Alignof(struct K2_required_alignment) == 1, "record K2 wrong alignment");
_Static_assert(sizeof(struct K2_size) == 10, "record K2 wrong sizeof");
_Static_assert(_Alignof(struct K2_size) == 1, "record K2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(K2,d) == 0, "field K2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(K2,e) == 0, "field K2.e wrong bit offset");
#endif
_Static_assert(sizeof(L2) == 16, "record L2 wrong sizeof");
_Static_assert(_Alignof(L2) == 16, "record L2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct L2_alignment) == 32, "record L2 wrong sizeof");
_Static_assert(_Alignof(struct L2_alignment) == 16, "record L2 wrong alignment");
_Static_assert(sizeof(struct L2_packed) == 16, "record L2 wrong sizeof");
_Static_assert(_Alignof(struct L2_packed) == 1, "record L2 wrong alignment");
_Static_assert(sizeof(struct L2_required_alignment) == 17, "record L2 wrong sizeof");
_Static_assert(_Alignof(struct L2_required_alignment) == 1, "record L2 wrong alignment");
_Static_assert(sizeof(struct L2_size) == 18, "record L2 wrong sizeof");
_Static_assert(_Alignof(struct L2_size) == 1, "record L2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(L2,d) == 0, "field L2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(L2,e) == 0, "field L2.e wrong bit offset");
#endif
_Static_assert(sizeof(M2) == 1, "record M2 wrong sizeof");
_Static_assert(_Alignof(M2) == 1, "record M2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct M2_alignment) == 2, "record M2 wrong sizeof");
_Static_assert(_Alignof(struct M2_alignment) == 1, "record M2 wrong alignment");
_Static_assert(sizeof(struct M2_packed) == 1, "record M2 wrong sizeof");
_Static_assert(_Alignof(struct M2_packed) == 1, "record M2 wrong alignment");
_Static_assert(sizeof(struct M2_required_alignment) == 2, "record M2 wrong sizeof");
_Static_assert(_Alignof(struct M2_required_alignment) == 1, "record M2 wrong alignment");
_Static_assert(sizeof(struct M2_size) == 3, "record M2 wrong sizeof");
_Static_assert(_Alignof(struct M2_size) == 1, "record M2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(M2,d) == 0, "field M2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(M2,e) == 0, "field M2.e wrong bit offset");
#endif
_Static_assert(sizeof(N2) == 1, "record N2 wrong sizeof");
_Static_assert(_Alignof(N2) == 1, "record N2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct N2_alignment) == 2, "record N2 wrong sizeof");
_Static_assert(_Alignof(struct N2_alignment) == 1, "record N2 wrong alignment");
_Static_assert(sizeof(struct N2_packed) == 1, "record N2 wrong sizeof");
_Static_assert(_Alignof(struct N2_packed) == 1, "record N2 wrong alignment");
_Static_assert(sizeof(struct N2_required_alignment) == 2, "record N2 wrong sizeof");
_Static_assert(_Alignof(struct N2_required_alignment) == 1, "record N2 wrong alignment");
_Static_assert(sizeof(struct N2_size) == 3, "record N2 wrong sizeof");
_Static_assert(_Alignof(struct N2_size) == 1, "record N2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(N2,d) == 0, "field N2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(N2,e) == 0, "field N2.e wrong bit offset");
#endif
_Static_assert(sizeof(O2) == 1, "record O2 wrong sizeof");
_Static_assert(_Alignof(O2) == 1, "record O2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct O2_alignment) == 2, "record O2 wrong sizeof");
_Static_assert(_Alignof(struct O2_alignment) == 1, "record O2 wrong alignment");
_Static_assert(sizeof(struct O2_packed) == 1, "record O2 wrong sizeof");
_Static_assert(_Alignof(struct O2_packed) == 1, "record O2 wrong alignment");
_Static_assert(sizeof(struct O2_required_alignment) == 2, "record O2 wrong sizeof");
_Static_assert(_Alignof(struct O2_required_alignment) == 1, "record O2 wrong alignment");
_Static_assert(sizeof(struct O2_size) == 3, "record O2 wrong sizeof");
_Static_assert(_Alignof(struct O2_size) == 1, "record O2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(O2,d) == 0, "field O2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(O2,e) == 0, "field O2.e wrong bit offset");
#endif
_Static_assert(sizeof(P2) == 2, "record P2 wrong sizeof");
_Static_assert(_Alignof(P2) == 2, "record P2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct P2_alignment) == 4, "record P2 wrong sizeof");
_Static_assert(_Alignof(struct P2_alignment) == 2, "record P2 wrong alignment");
_Static_assert(sizeof(struct P2_packed) == 2, "record P2 wrong sizeof");
_Static_assert(_Alignof(struct P2_packed) == 1, "record P2 wrong alignment");
_Static_assert(sizeof(struct P2_required_alignment) == 3, "record P2 wrong sizeof");
_Static_assert(_Alignof(struct P2_required_alignment) == 1, "record P2 wrong alignment");
_Static_assert(sizeof(struct P2_size) == 4, "record P2 wrong sizeof");
_Static_assert(_Alignof(struct P2_size) == 1, "record P2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(P2,d) == 0, "field P2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(P2,e) == 0, "field P2.e wrong bit offset");
#endif
_Static_assert(sizeof(Q2) == 8, "record Q2 wrong sizeof");
_Static_assert(_Alignof(Q2) == 8, "record Q2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Q2_alignment) == 16, "record Q2 wrong sizeof");
_Static_assert(_Alignof(struct Q2_alignment) == 8, "record Q2 wrong alignment");
_Static_assert(sizeof(struct Q2_packed) == 8, "record Q2 wrong sizeof");
_Static_assert(_Alignof(struct Q2_packed) == 1, "record Q2 wrong alignment");
_Static_assert(sizeof(struct Q2_required_alignment) == 9, "record Q2 wrong sizeof");
_Static_assert(_Alignof(struct Q2_required_alignment) == 1, "record Q2 wrong alignment");
_Static_assert(sizeof(struct Q2_size) == 10, "record Q2 wrong sizeof");
_Static_assert(_Alignof(struct Q2_size) == 1, "record Q2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(Q2,x) == 0, "field Q2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(Q2,d) == 0, "field Q2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(Q2,e) == 0, "field Q2.e wrong bit offset");
#endif
_Static_assert(sizeof(R2) == 1, "record R2 wrong sizeof");
_Static_assert(_Alignof(R2) == 1, "record R2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct R2_alignment) == 2, "record R2 wrong sizeof");
_Static_assert(_Alignof(struct R2_alignment) == 1, "record R2 wrong alignment");
_Static_assert(sizeof(struct R2_packed) == 1, "record R2 wrong sizeof");
_Static_assert(_Alignof(struct R2_packed) == 1, "record R2 wrong alignment");
_Static_assert(sizeof(struct R2_required_alignment) == 2, "record R2 wrong sizeof");
_Static_assert(_Alignof(struct R2_required_alignment) == 1, "record R2 wrong alignment");
_Static_assert(sizeof(struct R2_size) == 3, "record R2 wrong sizeof");
_Static_assert(_Alignof(struct R2_size) == 1, "record R2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(R2,x) == 0, "field R2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(R2,e) == 0, "field R2.e wrong bit offset");
#endif
_Static_assert(sizeof(S2) == 1, "record S2 wrong sizeof");
_Static_assert(_Alignof(S2) == 1, "record S2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct S2_alignment) == 2, "record S2 wrong sizeof");
_Static_assert(_Alignof(struct S2_alignment) == 1, "record S2 wrong alignment");
_Static_assert(sizeof(struct S2_packed) == 1, "record S2 wrong sizeof");
_Static_assert(_Alignof(struct S2_packed) == 1, "record S2 wrong alignment");
_Static_assert(sizeof(struct S2_required_alignment) == 2, "record S2 wrong sizeof");
_Static_assert(_Alignof(struct S2_required_alignment) == 1, "record S2 wrong alignment");
_Static_assert(sizeof(struct S2_size) == 3, "record S2 wrong sizeof");
_Static_assert(_Alignof(struct S2_size) == 1, "record S2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(S2,x) == 0, "field S2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(S2,e) == 0, "field S2.e wrong bit offset");
#endif
_Static_assert(sizeof(T2) == 1, "record T2 wrong sizeof");
_Static_assert(_Alignof(T2) == 1, "record T2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct T2_alignment) == 2, "record T2 wrong sizeof");
_Static_assert(_Alignof(struct T2_alignment) == 1, "record T2 wrong alignment");
_Static_assert(sizeof(struct T2_packed) == 1, "record T2 wrong sizeof");
_Static_assert(_Alignof(struct T2_packed) == 1, "record T2 wrong alignment");
_Static_assert(sizeof(struct T2_required_alignment) == 2, "record T2 wrong sizeof");
_Static_assert(_Alignof(struct T2_required_alignment) == 1, "record T2 wrong alignment");
_Static_assert(sizeof(struct T2_size) == 3, "record T2 wrong sizeof");
_Static_assert(_Alignof(struct T2_size) == 1, "record T2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(T2,x) == 0, "field T2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(T2,e) == 0, "field T2.e wrong bit offset");
#endif
_Static_assert(sizeof(U2) == 1, "record U2 wrong sizeof");
_Static_assert(_Alignof(U2) == 1, "record U2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct U2_alignment) == 2, "record U2 wrong sizeof");
_Static_assert(_Alignof(struct U2_alignment) == 1, "record U2 wrong alignment");
_Static_assert(sizeof(struct U2_packed) == 1, "record U2 wrong sizeof");
_Static_assert(_Alignof(struct U2_packed) == 1, "record U2 wrong alignment");
_Static_assert(sizeof(struct U2_required_alignment) == 2, "record U2 wrong sizeof");
_Static_assert(_Alignof(struct U2_required_alignment) == 1, "record U2 wrong alignment");
_Static_assert(sizeof(struct U2_size) == 3, "record U2 wrong sizeof");
_Static_assert(_Alignof(struct U2_size) == 1, "record U2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(U2,x) == 0, "field U2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(U2,e) == 0, "field U2.e wrong bit offset");
#endif
_Static_assert(sizeof(V2) == 1, "record V2 wrong sizeof");
_Static_assert(_Alignof(V2) == 1, "record V2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct V2_alignment) == 2, "record V2 wrong sizeof");
_Static_assert(_Alignof(struct V2_alignment) == 1, "record V2 wrong alignment");
_Static_assert(sizeof(struct V2_packed) == 1, "record V2 wrong sizeof");
_Static_assert(_Alignof(struct V2_packed) == 1, "record V2 wrong alignment");
_Static_assert(sizeof(struct V2_required_alignment) == 2, "record V2 wrong sizeof");
_Static_assert(_Alignof(struct V2_required_alignment) == 1, "record V2 wrong alignment");
_Static_assert(sizeof(struct V2_size) == 3, "record V2 wrong sizeof");
_Static_assert(_Alignof(struct V2_size) == 1, "record V2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(V2,x) == 0, "field V2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(V2,e) == 0, "field V2.e wrong bit offset");
#endif
_Static_assert(sizeof(W2) == 1, "record W2 wrong sizeof");
_Static_assert(_Alignof(W2) == 1, "record W2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct W2_alignment) == 2, "record W2 wrong sizeof");
_Static_assert(_Alignof(struct W2_alignment) == 1, "record W2 wrong alignment");
_Static_assert(sizeof(struct W2_packed) == 1, "record W2 wrong sizeof");
_Static_assert(_Alignof(struct W2_packed) == 1, "record W2 wrong alignment");
_Static_assert(sizeof(struct W2_required_alignment) == 2, "record W2 wrong sizeof");
_Static_assert(_Alignof(struct W2_required_alignment) == 1, "record W2 wrong alignment");
_Static_assert(sizeof(struct W2_size) == 3, "record W2 wrong sizeof");
_Static_assert(_Alignof(struct W2_size) == 1, "record W2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(W2,x) == 0, "field W2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(W2,e) == 0, "field W2.e wrong bit offset");
#endif
_Static_assert(sizeof(W_2) == 1, "record W_2 wrong sizeof");
_Static_assert(_Alignof(W_2) == 1, "record W_2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct W_2_alignment) == 2, "record W_2 wrong sizeof");
_Static_assert(_Alignof(struct W_2_alignment) == 1, "record W_2 wrong alignment");
_Static_assert(sizeof(struct W_2_packed) == 1, "record W_2 wrong sizeof");
_Static_assert(_Alignof(struct W_2_packed) == 1, "record W_2 wrong alignment");
_Static_assert(sizeof(struct W_2_required_alignment) == 2, "record W_2 wrong sizeof");
_Static_assert(_Alignof(struct W_2_required_alignment) == 1, "record W_2 wrong alignment");
_Static_assert(sizeof(struct W_2_size) == 3, "record W_2 wrong sizeof");
_Static_assert(_Alignof(struct W_2_size) == 1, "record W_2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(W_2,e) == 0, "field W_2.e wrong bit offset");
#endif
_Static_assert(sizeof(X2) == 1, "record X2 wrong sizeof");
_Static_assert(_Alignof(X2) == 1, "record X2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct X2_alignment) == 2, "record X2 wrong sizeof");
_Static_assert(_Alignof(struct X2_alignment) == 1, "record X2 wrong alignment");
_Static_assert(sizeof(struct X2_packed) == 1, "record X2 wrong sizeof");
_Static_assert(_Alignof(struct X2_packed) == 1, "record X2 wrong alignment");
_Static_assert(sizeof(struct X2_required_alignment) == 2, "record X2 wrong sizeof");
_Static_assert(_Alignof(struct X2_required_alignment) == 1, "record X2 wrong alignment");
_Static_assert(sizeof(struct X2_size) == 3, "record X2 wrong sizeof");
_Static_assert(_Alignof(struct X2_size) == 1, "record X2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(X2,x) == 0, "field X2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(X2,e) == 0, "field X2.e wrong bit offset");
#endif
_Static_assert(sizeof(Y) == 8, "record Y wrong sizeof");
_Static_assert(_Alignof(Y) == 8, "record Y wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Y_alignment) == 16, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_alignment) == 8, "record Y wrong alignment");
_Static_assert(sizeof(struct Y_packed) == 8, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_packed) == 1, "record Y wrong alignment");
_Static_assert(sizeof(struct Y_required_alignment) == 9, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_required_alignment) == 1, "record Y wrong alignment");
_Static_assert(sizeof(struct Y_size) == 10, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_size) == 1, "record Y wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(Y,d) == 8, "field Y.d wrong bit offset");
#endif
_Static_assert(sizeof(Y2) == 1, "record Y2 wrong sizeof");
_Static_assert(_Alignof(Y2) == 1, "record Y2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Y2_alignment) == 2, "record Y2 wrong sizeof");
_Static_assert(_Alignof(struct Y2_alignment) == 1, "record Y2 wrong alignment");
_Static_assert(sizeof(struct Y2_packed) == 1, "record Y2 wrong sizeof");
_Static_assert(_Alignof(struct Y2_packed) == 1, "record Y2 wrong alignment");
_Static_assert(sizeof(struct Y2_required_alignment) == 2, "record Y2 wrong sizeof");
_Static_assert(_Alignof(struct Y2_required_alignment) == 1, "record Y2 wrong alignment");
_Static_assert(sizeof(struct Y2_size) == 3, "record Y2 wrong sizeof");
_Static_assert(_Alignof(struct Y2_size) == 1, "record Y2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(Y2,d) == 0, "field Y2.d wrong bit offset");
#endif
_Static_assert(sizeof(A3) == 64, "record A3 wrong sizeof");
_Static_assert(_Alignof(A3) == 32, "record A3 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A3_alignment) == 96, "record A3 wrong sizeof");
_Static_assert(_Alignof(struct A3_alignment) == 32, "record A3 wrong alignment");
_Static_assert(sizeof(struct A3_packed) == 64, "record A3 wrong sizeof");
_Static_assert(_Alignof(struct A3_packed) == 1, "record A3 wrong alignment");
_Static_assert(sizeof(struct A3_required_alignment) == 65, "record A3 wrong sizeof");
_Static_assert(_Alignof(struct A3_required_alignment) == 1, "record A3 wrong alignment");
_Static_assert(sizeof(struct A3_size) == 66, "record A3 wrong sizeof");
_Static_assert(_Alignof(struct A3_size) == 1, "record A3 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A3,d) == 256, "field A3.d wrong bit offset");
#endif
_Static_assert(sizeof(A4) == 1, "record A4 wrong sizeof");
_Static_assert(_Alignof(A4) == 32, "record A4 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A4_alignment) == 64, "record A4 wrong sizeof");
_Static_assert(_Alignof(struct A4_alignment) == 32, "record A4 wrong alignment");
_Static_assert(sizeof(struct A4_packed) == 1, "record A4 wrong sizeof");
_Static_assert(_Alignof(struct A4_packed) == 1, "record A4 wrong alignment");
_Static_assert(sizeof(struct A4_required_alignment) == 2, "record A4 wrong sizeof");
_Static_assert(_Alignof(struct A4_required_alignment) == 1, "record A4 wrong alignment");
_Static_assert(sizeof(struct A4_size) == 3, "record A4 wrong sizeof");
_Static_assert(_Alignof(struct A4_size) == 1, "record A4 wrong alignment");
#endif
_Static_assert(sizeof(A5) == 32, "record A5 wrong sizeof");
_Static_assert(_Alignof(A5) == 32, "record A5 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A5_alignment) == 64, "record A5 wrong sizeof");
_Static_assert(_Alignof(struct A5_alignment) == 32, "record A5 wrong alignment");
_Static_assert(sizeof(struct A5_packed) == 32, "record A5 wrong sizeof");
_Static_assert(_Alignof(struct A5_packed) == 1, "record A5 wrong alignment");
_Static_assert(sizeof(struct A5_required_alignment) == 33, "record A5 wrong sizeof");
_Static_assert(_Alignof(struct A5_required_alignment) == 1, "record A5 wrong alignment");
_Static_assert(sizeof(struct A5_size) == 34, "record A5 wrong sizeof");
_Static_assert(_Alignof(struct A5_size) == 1, "record A5 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A5,d) == 8, "field A5.d wrong bit offset");
#endif
_Static_assert(sizeof(A7) == 32, "record A7 wrong sizeof");
_Static_assert(_Alignof(A7) == 32, "record A7 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A7_alignment) == 64, "record A7 wrong sizeof");
_Static_assert(_Alignof(struct A7_alignment) == 32, "record A7 wrong alignment");
_Static_assert(sizeof(struct A7_packed) == 32, "record A7 wrong sizeof");
_Static_assert(_Alignof(struct A7_packed) == 1, "record A7 wrong alignment");
_Static_assert(sizeof(struct A7_required_alignment) == 33, "record A7 wrong sizeof");
_Static_assert(_Alignof(struct A7_required_alignment) == 1, "record A7 wrong alignment");
_Static_assert(sizeof(struct A7_size) == 34, "record A7 wrong sizeof");
_Static_assert(_Alignof(struct A7_size) == 1, "record A7 wrong alignment");
#endif
_Static_assert(sizeof(A8) == 12, "record A8 wrong sizeof");
_Static_assert(_Alignof(A8) == 4, "record A8 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A8_alignment) == 16, "record A8 wrong sizeof");
_Static_assert(_Alignof(struct A8_alignment) == 4, "record A8 wrong alignment");
_Static_assert(sizeof(struct A8_packed) == 12, "record A8 wrong sizeof");
_Static_assert(_Alignof(struct A8_packed) == 1, "record A8 wrong alignment");
_Static_assert(sizeof(struct A8_required_alignment) == 13, "record A8 wrong sizeof");
_Static_assert(_Alignof(struct A8_required_alignment) == 1, "record A8 wrong alignment");
_Static_assert(sizeof(struct A8_size) == 14, "record A8 wrong sizeof");
_Static_assert(_Alignof(struct A8_size) == 1, "record A8 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A8,i) == 8, "field A8.i wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A8,j) == 40, "field A8.j wrong bit offset");
#endif
_Static_assert(sizeof(A9) == 12, "record A9 wrong sizeof");
_Static_assert(_Alignof(A9) == 4, "record A9 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A9_alignment) == 16, "record A9 wrong sizeof");
_Static_assert(_Alignof(struct A9_alignment) == 4, "record A9 wrong alignment");
_Static_assert(sizeof(struct A9_packed) == 12, "record A9 wrong sizeof");
_Static_assert(_Alignof(struct A9_packed) == 1, "record A9 wrong alignment");
_Static_assert(sizeof(struct A9_required_alignment) == 13, "record A9 wrong sizeof");
_Static_assert(_Alignof(struct A9_required_alignment) == 1, "record A9 wrong alignment");
_Static_assert(sizeof(struct A9_size) == 14, "record A9 wrong sizeof");
_Static_assert(_Alignof(struct A9_size) == 1, "record A9 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A9,i) == 8, "field A9.i wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A9,j) == 64, "field A9.j wrong bit offset");
#endif
_Static_assert(sizeof(A10) == 4, "record A10 wrong sizeof");
_Static_assert(_Alignof(A10) == 16, "record A10 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A10_alignment) == 32, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_alignment) == 16, "record A10 wrong alignment");
_Static_assert(sizeof(struct A10_packed) == 4, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_packed) == 1, "record A10 wrong alignment");
_Static_assert(sizeof(struct A10_required_alignment) == 5, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_required_alignment) == 1, "record A10 wrong alignment");
_Static_assert(sizeof(struct A10_size) == 6, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_size) == 1, "record A10 wrong alignment");
#endif
_Static_assert(sizeof(A11) == 16, "record A11 wrong sizeof");
_Static_assert(_Alignof(A11) == 16, "record A11 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A11_alignment) == 32, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_alignment) == 16, "record A11 wrong alignment");
_Static_assert(sizeof(struct A11_packed) == 16, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_packed) == 1, "record A11 wrong alignment");
_Static_assert(sizeof(struct A11_required_alignment) == 17, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_required_alignment) == 1, "record A11 wrong alignment");
_Static_assert(sizeof(struct A11_size) == 18, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_size) == 1, "record A11 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A11,i) == 8, "field A11.i wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A11,j) == 40, "field A11.j wrong bit offset");
#endif
_Static_assert(sizeof(A12) == 32, "record A12 wrong sizeof");
_Static_assert(_Alignof(A12) == 16, "record A12 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A12_alignment) == 48, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_alignment) == 16, "record A12 wrong alignment");
_Static_assert(sizeof(struct A12_packed) == 32, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_packed) == 1, "record A12 wrong alignment");
_Static_assert(sizeof(struct A12_required_alignment) == 33, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_required_alignment) == 1, "record A12 wrong alignment");
_Static_assert(sizeof(struct A12_size) == 34, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_size) == 1, "record A12 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A12,i) == 8, "field A12.i wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A12,j) == 128, "field A12.j wrong bit offset");
#endif
_Static_assert(sizeof(A13) == 16, "record A13 wrong sizeof");
_Static_assert(_Alignof(A13) == 16, "record A13 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A13_alignment) == 32, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_alignment) == 16, "record A13 wrong alignment");
_Static_assert(sizeof(struct A13_packed) == 16, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_packed) == 1, "record A13 wrong alignment");
_Static_assert(sizeof(struct A13_required_alignment) == 17, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_required_alignment) == 1, "record A13 wrong alignment");
_Static_assert(sizeof(struct A13_size) == 18, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_size) == 1, "record A13 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A13,i) == 32, "field A13.i wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A13,j) == 33, "field A13.j wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A13,d) == 64, "field A13.d wrong bit offset");
#endif
// MAPPING|TWELVE|mips64el-mips64-linux-gnuabi64:Gcc|mips64-mips64-linux-gnuabi64:Gcc|mips-mips32-linux-gnuabi64:Gcc|mips-mips64r6-linux-gnuabi64:Gcc|powerpc64le-ppc64le-linux-gnu:Gcc|powerpc64le-ppc64le-linux-musl:Gcc|powerpc64-ppc64-linux-gnu:Gcc|powerpc64-ppc64-linux-musl:Gcc|riscv64-generic_rv64-linux-gnu:Gcc|s390x-generic-linux-gnu:Gcc|sparc64-v9-linux-gnu:Gcc|x86_64-x86_64-linux-gnu:Gcc|x86_64-x86_64-linux-musl:Gcc|END
// repr targets Mips64elUnknownLinuxGnuabi64|Some("mips64el-mips64-linux-gnuabi64") Mips64elUnknownLinuxMusl|None Mips64UnknownLinuxGnuabi64|Some("mips64-mips64-linux-gnuabi64") Mips64UnknownLinuxMusl|None Mipsisa64r6elUnknownLinuxGnuabi64|Some("mips-mips32-linux-gnuabi64") Mipsisa64r6UnknownLinuxGnuabi64|Some("mips-mips64r6-linux-gnuabi64") Powerpc64leUnknownLinuxGnu|Some("powerpc64le-ppc64le-linux-gnu") Powerpc64leUnknownLinuxMusl|Some("powerpc64le-ppc64le-linux-musl") Powerpc64UnknownLinuxGnu|Some("powerpc64-ppc64-linux-gnu") Powerpc64UnknownLinuxMusl|Some("powerpc64-ppc64-linux-musl") Riscv64UnknownLinuxGnu|Some("riscv64-generic_rv64-linux-gnu") S390xUnknownLinuxGnu|Some("s390x-generic-linux-gnu") Sparc64UnknownLinuxGnu|Some("sparc64-v9-linux-gnu") X86_64UnknownLinuxGnu|Some("x86_64-x86_64-linux-gnu") X86_64UnknownLinuxMusl|Some("x86_64-x86_64-linux-musl") 
#elif defined(TWELVE)
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
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A,d) == 0, "field A.d wrong bit offset");
#endif
_Static_assert(sizeof(A_) == 5, "record A_ wrong sizeof");
_Static_assert(_Alignof(A_) == 1, "record A_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A__alignment) == 6, "record A_ wrong sizeof");
_Static_assert(_Alignof(struct A__alignment) == 1, "record A_ wrong alignment");
_Static_assert(sizeof(struct A__packed) == 5, "record A_ wrong sizeof");
_Static_assert(_Alignof(struct A__packed) == 1, "record A_ wrong alignment");
_Static_assert(sizeof(struct A__required_alignment) == 6, "record A_ wrong sizeof");
_Static_assert(_Alignof(struct A__required_alignment) == 1, "record A_ wrong alignment");
_Static_assert(sizeof(struct A__size) == 7, "record A_ wrong sizeof");
_Static_assert(_Alignof(struct A__size) == 1, "record A_ wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_,d) == 32, "field A_.d wrong bit offset");
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
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B,d) == 0, "field B.d wrong bit offset");
#endif
_Static_assert(sizeof(B_) == 9, "record B_ wrong sizeof");
_Static_assert(_Alignof(B_) == 1, "record B_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B__alignment) == 10, "record B_ wrong sizeof");
_Static_assert(_Alignof(struct B__alignment) == 1, "record B_ wrong alignment");
_Static_assert(sizeof(struct B__packed) == 9, "record B_ wrong sizeof");
_Static_assert(_Alignof(struct B__packed) == 1, "record B_ wrong alignment");
_Static_assert(sizeof(struct B__required_alignment) == 10, "record B_ wrong sizeof");
_Static_assert(_Alignof(struct B__required_alignment) == 1, "record B_ wrong alignment");
_Static_assert(sizeof(struct B__size) == 11, "record B_ wrong sizeof");
_Static_assert(_Alignof(struct B__size) == 1, "record B_ wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B_,d) == 64, "field B_.d wrong bit offset");
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
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C,d) == 0, "field C.d wrong bit offset");
#endif
_Static_assert(sizeof(C_) == 9, "record C_ wrong sizeof");
_Static_assert(_Alignof(C_) == 1, "record C_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C__alignment) == 10, "record C_ wrong sizeof");
_Static_assert(_Alignof(struct C__alignment) == 1, "record C_ wrong alignment");
_Static_assert(sizeof(struct C__packed) == 9, "record C_ wrong sizeof");
_Static_assert(_Alignof(struct C__packed) == 1, "record C_ wrong alignment");
_Static_assert(sizeof(struct C__required_alignment) == 10, "record C_ wrong sizeof");
_Static_assert(_Alignof(struct C__required_alignment) == 1, "record C_ wrong alignment");
_Static_assert(sizeof(struct C__size) == 11, "record C_ wrong sizeof");
_Static_assert(_Alignof(struct C__size) == 1, "record C_ wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C_,d) == 64, "field C_.d wrong bit offset");
#endif
_Static_assert(sizeof(D) == 24, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 8, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 32, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 8, "record D wrong alignment");
_Static_assert(sizeof(struct D_packed) == 24, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 25, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_size) == 26, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_size) == 1, "record D wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D,d) == 64, "field D.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(D,e) == 128, "field D.e wrong bit offset");
#endif
_Static_assert(sizeof(F) == 32, "record F wrong sizeof");
_Static_assert(_Alignof(F) == 16, "record F wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 48, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_alignment) == 16, "record F wrong alignment");
_Static_assert(sizeof(struct F_packed) == 32, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_packed) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_required_alignment) == 33, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_size) == 34, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_size) == 1, "record F wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F,d) == 128, "field F.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(F,e) == 192, "field F.e wrong bit offset");
#endif
_Static_assert(sizeof(G) == 12, "record G wrong sizeof");
_Static_assert(_Alignof(G) == 2, "record G wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 14, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_alignment) == 2, "record G wrong alignment");
_Static_assert(sizeof(struct G_packed) == 12, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_packed) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_required_alignment) == 13, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_size) == 14, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_size) == 1, "record G wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(G,d) == 16, "field G.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(G,e) == 80, "field G.e wrong bit offset");
#endif
_Static_assert(sizeof(H) == 12, "record H wrong sizeof");
_Static_assert(_Alignof(H) == 2, "record H wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 14, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_alignment) == 2, "record H wrong alignment");
_Static_assert(sizeof(struct H_packed) == 12, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_packed) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_required_alignment) == 13, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_size) == 14, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_size) == 1, "record H wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(H,d) == 16, "field H.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(H,e) == 80, "field H.e wrong bit offset");
#endif
_Static_assert(sizeof(I) == 10, "record I wrong sizeof");
_Static_assert(_Alignof(I) == 1, "record I wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I_alignment) == 11, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_alignment) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_packed) == 10, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_packed) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_required_alignment) == 11, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_required_alignment) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_size) == 12, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_size) == 1, "record I wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(I,d) == 8, "field I.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(I,e) == 72, "field I.e wrong bit offset");
#endif
_Static_assert(sizeof(J) == 12, "record J wrong sizeof");
_Static_assert(_Alignof(J) == 2, "record J wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J_alignment) == 14, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_alignment) == 2, "record J wrong alignment");
_Static_assert(sizeof(struct J_packed) == 12, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_packed) == 1, "record J wrong alignment");
_Static_assert(sizeof(struct J_required_alignment) == 13, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_required_alignment) == 1, "record J wrong alignment");
_Static_assert(sizeof(struct J_size) == 14, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_size) == 1, "record J wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(J,d) == 16, "field J.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(J,e) == 80, "field J.e wrong bit offset");
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
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(K,d) == 8, "field K.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(K,e) == 16, "field K.e wrong bit offset");
#endif
_Static_assert(sizeof(L) == 32, "record L wrong sizeof");
_Static_assert(_Alignof(L) == 16, "record L wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct L_alignment) == 48, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_alignment) == 16, "record L wrong alignment");
_Static_assert(sizeof(struct L_packed) == 32, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_packed) == 1, "record L wrong alignment");
_Static_assert(sizeof(struct L_required_alignment) == 33, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_required_alignment) == 1, "record L wrong alignment");
_Static_assert(sizeof(struct L_size) == 34, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_size) == 1, "record L wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(L,d) == 128, "field L.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(L,e) == 136, "field L.e wrong bit offset");
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
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(M,d) == 16, "field M.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(M,e) == 24, "field M.e wrong bit offset");
#endif
_Static_assert(sizeof(N) == 4, "record N wrong sizeof");
_Static_assert(_Alignof(N) == 2, "record N wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct N_alignment) == 6, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_alignment) == 2, "record N wrong alignment");
_Static_assert(sizeof(struct N_packed) == 4, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_packed) == 1, "record N wrong alignment");
_Static_assert(sizeof(struct N_required_alignment) == 5, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_required_alignment) == 1, "record N wrong alignment");
_Static_assert(sizeof(struct N_size) == 6, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_size) == 1, "record N wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(N,d) == 16, "field N.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(N,e) == 24, "field N.e wrong bit offset");
#endif
_Static_assert(sizeof(O) == 3, "record O wrong sizeof");
_Static_assert(_Alignof(O) == 1, "record O wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct O_alignment) == 4, "record O wrong sizeof");
_Static_assert(_Alignof(struct O_alignment) == 1, "record O wrong alignment");
_Static_assert(sizeof(struct O_packed) == 3, "record O wrong sizeof");
_Static_assert(_Alignof(struct O_packed) == 1, "record O wrong alignment");
_Static_assert(sizeof(struct O_required_alignment) == 4, "record O wrong sizeof");
_Static_assert(_Alignof(struct O_required_alignment) == 1, "record O wrong alignment");
_Static_assert(sizeof(struct O_size) == 5, "record O wrong sizeof");
_Static_assert(_Alignof(struct O_size) == 1, "record O wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(O,d) == 8, "field O.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(O,e) == 16, "field O.e wrong bit offset");
#endif
_Static_assert(sizeof(P) == 4, "record P wrong sizeof");
_Static_assert(_Alignof(P) == 2, "record P wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct P_alignment) == 6, "record P wrong sizeof");
_Static_assert(_Alignof(struct P_alignment) == 2, "record P wrong alignment");
_Static_assert(sizeof(struct P_packed) == 4, "record P wrong sizeof");
_Static_assert(_Alignof(struct P_packed) == 1, "record P wrong alignment");
_Static_assert(sizeof(struct P_required_alignment) == 5, "record P wrong sizeof");
_Static_assert(_Alignof(struct P_required_alignment) == 1, "record P wrong alignment");
_Static_assert(sizeof(struct P_size) == 6, "record P wrong sizeof");
_Static_assert(_Alignof(struct P_size) == 1, "record P wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(P,d) == 8, "field P.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(P,e) == 16, "field P.e wrong bit offset");
#endif
_Static_assert(sizeof(Q) == 8, "record Q wrong sizeof");
_Static_assert(_Alignof(Q) == 8, "record Q wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Q_alignment) == 16, "record Q wrong sizeof");
_Static_assert(_Alignof(struct Q_alignment) == 8, "record Q wrong alignment");
_Static_assert(sizeof(struct Q_packed) == 8, "record Q wrong sizeof");
_Static_assert(_Alignof(struct Q_packed) == 1, "record Q wrong alignment");
_Static_assert(sizeof(struct Q_required_alignment) == 9, "record Q wrong sizeof");
_Static_assert(_Alignof(struct Q_required_alignment) == 1, "record Q wrong alignment");
_Static_assert(sizeof(struct Q_size) == 10, "record Q wrong sizeof");
_Static_assert(_Alignof(struct Q_size) == 1, "record Q wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(Q,x) == 8, "field Q.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(Q,d) == 9, "field Q.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(Q,e) == 16, "field Q.e wrong bit offset");
#endif
_Static_assert(sizeof(R) == 17, "record R wrong sizeof");
_Static_assert(_Alignof(R) == 1, "record R wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct R_alignment) == 18, "record R wrong sizeof");
_Static_assert(_Alignof(struct R_alignment) == 1, "record R wrong alignment");
_Static_assert(sizeof(struct R_packed) == 17, "record R wrong sizeof");
_Static_assert(_Alignof(struct R_packed) == 1, "record R wrong alignment");
_Static_assert(sizeof(struct R_required_alignment) == 18, "record R wrong sizeof");
_Static_assert(_Alignof(struct R_required_alignment) == 1, "record R wrong alignment");
_Static_assert(sizeof(struct R_size) == 19, "record R wrong sizeof");
_Static_assert(_Alignof(struct R_size) == 1, "record R wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(R,x) == 8, "field R.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(R,e) == 128, "field R.e wrong bit offset");
#endif
_Static_assert(sizeof(S) == 9, "record S wrong sizeof");
_Static_assert(_Alignof(S) == 1, "record S wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct S_alignment) == 10, "record S wrong sizeof");
_Static_assert(_Alignof(struct S_alignment) == 1, "record S wrong alignment");
_Static_assert(sizeof(struct S_packed) == 9, "record S wrong sizeof");
_Static_assert(_Alignof(struct S_packed) == 1, "record S wrong alignment");
_Static_assert(sizeof(struct S_required_alignment) == 10, "record S wrong sizeof");
_Static_assert(_Alignof(struct S_required_alignment) == 1, "record S wrong alignment");
_Static_assert(sizeof(struct S_size) == 11, "record S wrong sizeof");
_Static_assert(_Alignof(struct S_size) == 1, "record S wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(S,x) == 8, "field S.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(S,e) == 64, "field S.e wrong bit offset");
#endif
_Static_assert(sizeof(T) == 9, "record T wrong sizeof");
_Static_assert(_Alignof(T) == 1, "record T wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct T_alignment) == 10, "record T wrong sizeof");
_Static_assert(_Alignof(struct T_alignment) == 1, "record T wrong alignment");
_Static_assert(sizeof(struct T_packed) == 9, "record T wrong sizeof");
_Static_assert(_Alignof(struct T_packed) == 1, "record T wrong alignment");
_Static_assert(sizeof(struct T_required_alignment) == 10, "record T wrong sizeof");
_Static_assert(_Alignof(struct T_required_alignment) == 1, "record T wrong alignment");
_Static_assert(sizeof(struct T_size) == 11, "record T wrong sizeof");
_Static_assert(_Alignof(struct T_size) == 1, "record T wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(T,x) == 8, "field T.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(T,e) == 64, "field T.e wrong bit offset");
#endif
_Static_assert(sizeof(U) == 9, "record U wrong sizeof");
_Static_assert(_Alignof(U) == 1, "record U wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct U_alignment) == 10, "record U wrong sizeof");
_Static_assert(_Alignof(struct U_alignment) == 1, "record U wrong alignment");
_Static_assert(sizeof(struct U_packed) == 9, "record U wrong sizeof");
_Static_assert(_Alignof(struct U_packed) == 1, "record U wrong alignment");
_Static_assert(sizeof(struct U_required_alignment) == 10, "record U wrong sizeof");
_Static_assert(_Alignof(struct U_required_alignment) == 1, "record U wrong alignment");
_Static_assert(sizeof(struct U_size) == 11, "record U wrong sizeof");
_Static_assert(_Alignof(struct U_size) == 1, "record U wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(U,x) == 8, "field U.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(U,e) == 64, "field U.e wrong bit offset");
#endif
_Static_assert(sizeof(V) == 9, "record V wrong sizeof");
_Static_assert(_Alignof(V) == 1, "record V wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct V_alignment) == 10, "record V wrong sizeof");
_Static_assert(_Alignof(struct V_alignment) == 1, "record V wrong alignment");
_Static_assert(sizeof(struct V_packed) == 9, "record V wrong sizeof");
_Static_assert(_Alignof(struct V_packed) == 1, "record V wrong alignment");
_Static_assert(sizeof(struct V_required_alignment) == 10, "record V wrong sizeof");
_Static_assert(_Alignof(struct V_required_alignment) == 1, "record V wrong alignment");
_Static_assert(sizeof(struct V_size) == 11, "record V wrong sizeof");
_Static_assert(_Alignof(struct V_size) == 1, "record V wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(V,x) == 8, "field V.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(V,e) == 64, "field V.e wrong bit offset");
#endif
_Static_assert(sizeof(W) == 17, "record W wrong sizeof");
_Static_assert(_Alignof(W) == 1, "record W wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct W_alignment) == 18, "record W wrong sizeof");
_Static_assert(_Alignof(struct W_alignment) == 1, "record W wrong alignment");
_Static_assert(sizeof(struct W_packed) == 17, "record W wrong sizeof");
_Static_assert(_Alignof(struct W_packed) == 1, "record W wrong alignment");
_Static_assert(sizeof(struct W_required_alignment) == 18, "record W wrong sizeof");
_Static_assert(_Alignof(struct W_required_alignment) == 1, "record W wrong alignment");
_Static_assert(sizeof(struct W_size) == 19, "record W wrong sizeof");
_Static_assert(_Alignof(struct W_size) == 1, "record W wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(W,x) == 8, "field W.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(W,e) == 128, "field W.e wrong bit offset");
#endif
_Static_assert(sizeof(W_) == 17, "record W_ wrong sizeof");
_Static_assert(_Alignof(W_) == 1, "record W_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct W__alignment) == 18, "record W_ wrong sizeof");
_Static_assert(_Alignof(struct W__alignment) == 1, "record W_ wrong alignment");
_Static_assert(sizeof(struct W__packed) == 17, "record W_ wrong sizeof");
_Static_assert(_Alignof(struct W__packed) == 1, "record W_ wrong alignment");
_Static_assert(sizeof(struct W__required_alignment) == 18, "record W_ wrong sizeof");
_Static_assert(_Alignof(struct W__required_alignment) == 1, "record W_ wrong alignment");
_Static_assert(sizeof(struct W__size) == 19, "record W_ wrong sizeof");
_Static_assert(_Alignof(struct W__size) == 1, "record W_ wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(W_,e) == 128, "field W_.e wrong bit offset");
#endif
_Static_assert(sizeof(X) == 17, "record X wrong sizeof");
_Static_assert(_Alignof(X) == 1, "record X wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct X_alignment) == 18, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_alignment) == 1, "record X wrong alignment");
_Static_assert(sizeof(struct X_packed) == 17, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_packed) == 1, "record X wrong alignment");
_Static_assert(sizeof(struct X_required_alignment) == 18, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_required_alignment) == 1, "record X wrong alignment");
_Static_assert(sizeof(struct X_size) == 19, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_size) == 1, "record X wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(X,x) == 8, "field X.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(X,e) == 128, "field X.e wrong bit offset");
#endif
_Static_assert(sizeof(A2) == 1, "record A2 wrong sizeof");
_Static_assert(_Alignof(A2) == 1, "record A2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A2_alignment) == 2, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_alignment) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_packed) == 1, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_packed) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_required_alignment) == 2, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_required_alignment) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_size) == 3, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_size) == 1, "record A2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A2,d) == 0, "field A2.d wrong bit offset");
#endif
_Static_assert(sizeof(A_2) == 1, "record A_2 wrong sizeof");
_Static_assert(_Alignof(A_2) == 1, "record A_2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_2_alignment) == 2, "record A_2 wrong sizeof");
_Static_assert(_Alignof(struct A_2_alignment) == 1, "record A_2 wrong alignment");
_Static_assert(sizeof(struct A_2_packed) == 1, "record A_2 wrong sizeof");
_Static_assert(_Alignof(struct A_2_packed) == 1, "record A_2 wrong alignment");
_Static_assert(sizeof(struct A_2_required_alignment) == 2, "record A_2 wrong sizeof");
_Static_assert(_Alignof(struct A_2_required_alignment) == 1, "record A_2 wrong alignment");
_Static_assert(sizeof(struct A_2_size) == 3, "record A_2 wrong sizeof");
_Static_assert(_Alignof(struct A_2_size) == 1, "record A_2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_2,d) == 0, "field A_2.d wrong bit offset");
#endif
_Static_assert(sizeof(B2) == 1, "record B2 wrong sizeof");
_Static_assert(_Alignof(B2) == 1, "record B2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B2_alignment) == 2, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_alignment) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_packed) == 1, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_packed) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_required_alignment) == 2, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_required_alignment) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_size) == 3, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_size) == 1, "record B2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B2,d) == 0, "field B2.d wrong bit offset");
#endif
_Static_assert(sizeof(B_2) == 1, "record B_2 wrong sizeof");
_Static_assert(_Alignof(B_2) == 1, "record B_2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_2_alignment) == 2, "record B_2 wrong sizeof");
_Static_assert(_Alignof(struct B_2_alignment) == 1, "record B_2 wrong alignment");
_Static_assert(sizeof(struct B_2_packed) == 1, "record B_2 wrong sizeof");
_Static_assert(_Alignof(struct B_2_packed) == 1, "record B_2 wrong alignment");
_Static_assert(sizeof(struct B_2_required_alignment) == 2, "record B_2 wrong sizeof");
_Static_assert(_Alignof(struct B_2_required_alignment) == 1, "record B_2 wrong alignment");
_Static_assert(sizeof(struct B_2_size) == 3, "record B_2 wrong sizeof");
_Static_assert(_Alignof(struct B_2_size) == 1, "record B_2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B_2,d) == 0, "field B_2.d wrong bit offset");
#endif
_Static_assert(sizeof(C2) == 1, "record C2 wrong sizeof");
_Static_assert(_Alignof(C2) == 1, "record C2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C2_alignment) == 2, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_alignment) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_packed) == 1, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_packed) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_required_alignment) == 2, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_required_alignment) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_size) == 3, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_size) == 1, "record C2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C2,d) == 0, "field C2.d wrong bit offset");
#endif
_Static_assert(sizeof(C22) == 1, "record C22 wrong sizeof");
_Static_assert(_Alignof(C22) == 1, "record C22 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C22_alignment) == 2, "record C22 wrong sizeof");
_Static_assert(_Alignof(struct C22_alignment) == 1, "record C22 wrong alignment");
_Static_assert(sizeof(struct C22_packed) == 1, "record C22 wrong sizeof");
_Static_assert(_Alignof(struct C22_packed) == 1, "record C22 wrong alignment");
_Static_assert(sizeof(struct C22_required_alignment) == 2, "record C22 wrong sizeof");
_Static_assert(_Alignof(struct C22_required_alignment) == 1, "record C22 wrong alignment");
_Static_assert(sizeof(struct C22_size) == 3, "record C22 wrong sizeof");
_Static_assert(_Alignof(struct C22_size) == 1, "record C22 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C22,d) == 0, "field C22.d wrong bit offset");
#endif
_Static_assert(sizeof(D2) == 8, "record D2 wrong sizeof");
_Static_assert(_Alignof(D2) == 8, "record D2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D2_alignment) == 16, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_alignment) == 8, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_packed) == 8, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_packed) == 1, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_required_alignment) == 9, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_required_alignment) == 1, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_size) == 10, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_size) == 1, "record D2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D2,d) == 0, "field D2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(D2,e) == 0, "field D2.e wrong bit offset");
#endif
_Static_assert(sizeof(F2) == 16, "record F2 wrong sizeof");
_Static_assert(_Alignof(F2) == 16, "record F2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F2_alignment) == 32, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_alignment) == 16, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_packed) == 16, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_packed) == 1, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_required_alignment) == 17, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_required_alignment) == 1, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_size) == 18, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_size) == 1, "record F2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F2,d) == 0, "field F2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(F2,e) == 0, "field F2.e wrong bit offset");
#endif
_Static_assert(sizeof(G2) == 8, "record G2 wrong sizeof");
_Static_assert(_Alignof(G2) == 2, "record G2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G2_alignment) == 10, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_alignment) == 2, "record G2 wrong alignment");
_Static_assert(sizeof(struct G2_packed) == 8, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_packed) == 1, "record G2 wrong alignment");
_Static_assert(sizeof(struct G2_required_alignment) == 9, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_required_alignment) == 1, "record G2 wrong alignment");
_Static_assert(sizeof(struct G2_size) == 10, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_size) == 1, "record G2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(G2,d) == 0, "field G2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(G2,e) == 0, "field G2.e wrong bit offset");
#endif
_Static_assert(sizeof(H2) == 8, "record H2 wrong sizeof");
_Static_assert(_Alignof(H2) == 2, "record H2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H2_alignment) == 10, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_alignment) == 2, "record H2 wrong alignment");
_Static_assert(sizeof(struct H2_packed) == 8, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_packed) == 1, "record H2 wrong alignment");
_Static_assert(sizeof(struct H2_required_alignment) == 9, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_required_alignment) == 1, "record H2 wrong alignment");
_Static_assert(sizeof(struct H2_size) == 10, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_size) == 1, "record H2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(H2,d) == 0, "field H2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(H2,e) == 0, "field H2.e wrong bit offset");
#endif
_Static_assert(sizeof(I2) == 8, "record I2 wrong sizeof");
_Static_assert(_Alignof(I2) == 1, "record I2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I2_alignment) == 9, "record I2 wrong sizeof");
_Static_assert(_Alignof(struct I2_alignment) == 1, "record I2 wrong alignment");
_Static_assert(sizeof(struct I2_packed) == 8, "record I2 wrong sizeof");
_Static_assert(_Alignof(struct I2_packed) == 1, "record I2 wrong alignment");
_Static_assert(sizeof(struct I2_required_alignment) == 9, "record I2 wrong sizeof");
_Static_assert(_Alignof(struct I2_required_alignment) == 1, "record I2 wrong alignment");
_Static_assert(sizeof(struct I2_size) == 10, "record I2 wrong sizeof");
_Static_assert(_Alignof(struct I2_size) == 1, "record I2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(I2,d) == 0, "field I2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(I2,e) == 0, "field I2.e wrong bit offset");
#endif
_Static_assert(sizeof(J2) == 8, "record J2 wrong sizeof");
_Static_assert(_Alignof(J2) == 2, "record J2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J2_alignment) == 10, "record J2 wrong sizeof");
_Static_assert(_Alignof(struct J2_alignment) == 2, "record J2 wrong alignment");
_Static_assert(sizeof(struct J2_packed) == 8, "record J2 wrong sizeof");
_Static_assert(_Alignof(struct J2_packed) == 1, "record J2 wrong alignment");
_Static_assert(sizeof(struct J2_required_alignment) == 9, "record J2 wrong sizeof");
_Static_assert(_Alignof(struct J2_required_alignment) == 1, "record J2 wrong alignment");
_Static_assert(sizeof(struct J2_size) == 10, "record J2 wrong sizeof");
_Static_assert(_Alignof(struct J2_size) == 1, "record J2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(J2,d) == 0, "field J2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(J2,e) == 0, "field J2.e wrong bit offset");
#endif
_Static_assert(sizeof(K2) == 8, "record K2 wrong sizeof");
_Static_assert(_Alignof(K2) == 8, "record K2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct K2_alignment) == 16, "record K2 wrong sizeof");
_Static_assert(_Alignof(struct K2_alignment) == 8, "record K2 wrong alignment");
_Static_assert(sizeof(struct K2_packed) == 8, "record K2 wrong sizeof");
_Static_assert(_Alignof(struct K2_packed) == 1, "record K2 wrong alignment");
_Static_assert(sizeof(struct K2_required_alignment) == 9, "record K2 wrong sizeof");
_Static_assert(_Alignof(struct K2_required_alignment) == 1, "record K2 wrong alignment");
_Static_assert(sizeof(struct K2_size) == 10, "record K2 wrong sizeof");
_Static_assert(_Alignof(struct K2_size) == 1, "record K2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(K2,d) == 0, "field K2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(K2,e) == 0, "field K2.e wrong bit offset");
#endif
_Static_assert(sizeof(L2) == 16, "record L2 wrong sizeof");
_Static_assert(_Alignof(L2) == 16, "record L2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct L2_alignment) == 32, "record L2 wrong sizeof");
_Static_assert(_Alignof(struct L2_alignment) == 16, "record L2 wrong alignment");
_Static_assert(sizeof(struct L2_packed) == 16, "record L2 wrong sizeof");
_Static_assert(_Alignof(struct L2_packed) == 1, "record L2 wrong alignment");
_Static_assert(sizeof(struct L2_required_alignment) == 17, "record L2 wrong sizeof");
_Static_assert(_Alignof(struct L2_required_alignment) == 1, "record L2 wrong alignment");
_Static_assert(sizeof(struct L2_size) == 18, "record L2 wrong sizeof");
_Static_assert(_Alignof(struct L2_size) == 1, "record L2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(L2,d) == 0, "field L2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(L2,e) == 0, "field L2.e wrong bit offset");
#endif
_Static_assert(sizeof(M2) == 2, "record M2 wrong sizeof");
_Static_assert(_Alignof(M2) == 2, "record M2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct M2_alignment) == 4, "record M2 wrong sizeof");
_Static_assert(_Alignof(struct M2_alignment) == 2, "record M2 wrong alignment");
_Static_assert(sizeof(struct M2_packed) == 2, "record M2 wrong sizeof");
_Static_assert(_Alignof(struct M2_packed) == 1, "record M2 wrong alignment");
_Static_assert(sizeof(struct M2_required_alignment) == 3, "record M2 wrong sizeof");
_Static_assert(_Alignof(struct M2_required_alignment) == 1, "record M2 wrong alignment");
_Static_assert(sizeof(struct M2_size) == 4, "record M2 wrong sizeof");
_Static_assert(_Alignof(struct M2_size) == 1, "record M2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(M2,d) == 0, "field M2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(M2,e) == 0, "field M2.e wrong bit offset");
#endif
_Static_assert(sizeof(N2) == 2, "record N2 wrong sizeof");
_Static_assert(_Alignof(N2) == 2, "record N2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct N2_alignment) == 4, "record N2 wrong sizeof");
_Static_assert(_Alignof(struct N2_alignment) == 2, "record N2 wrong alignment");
_Static_assert(sizeof(struct N2_packed) == 2, "record N2 wrong sizeof");
_Static_assert(_Alignof(struct N2_packed) == 1, "record N2 wrong alignment");
_Static_assert(sizeof(struct N2_required_alignment) == 3, "record N2 wrong sizeof");
_Static_assert(_Alignof(struct N2_required_alignment) == 1, "record N2 wrong alignment");
_Static_assert(sizeof(struct N2_size) == 4, "record N2 wrong sizeof");
_Static_assert(_Alignof(struct N2_size) == 1, "record N2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(N2,d) == 0, "field N2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(N2,e) == 0, "field N2.e wrong bit offset");
#endif
_Static_assert(sizeof(O2) == 1, "record O2 wrong sizeof");
_Static_assert(_Alignof(O2) == 1, "record O2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct O2_alignment) == 2, "record O2 wrong sizeof");
_Static_assert(_Alignof(struct O2_alignment) == 1, "record O2 wrong alignment");
_Static_assert(sizeof(struct O2_packed) == 1, "record O2 wrong sizeof");
_Static_assert(_Alignof(struct O2_packed) == 1, "record O2 wrong alignment");
_Static_assert(sizeof(struct O2_required_alignment) == 2, "record O2 wrong sizeof");
_Static_assert(_Alignof(struct O2_required_alignment) == 1, "record O2 wrong alignment");
_Static_assert(sizeof(struct O2_size) == 3, "record O2 wrong sizeof");
_Static_assert(_Alignof(struct O2_size) == 1, "record O2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(O2,d) == 0, "field O2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(O2,e) == 0, "field O2.e wrong bit offset");
#endif
_Static_assert(sizeof(P2) == 2, "record P2 wrong sizeof");
_Static_assert(_Alignof(P2) == 2, "record P2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct P2_alignment) == 4, "record P2 wrong sizeof");
_Static_assert(_Alignof(struct P2_alignment) == 2, "record P2 wrong alignment");
_Static_assert(sizeof(struct P2_packed) == 2, "record P2 wrong sizeof");
_Static_assert(_Alignof(struct P2_packed) == 1, "record P2 wrong alignment");
_Static_assert(sizeof(struct P2_required_alignment) == 3, "record P2 wrong sizeof");
_Static_assert(_Alignof(struct P2_required_alignment) == 1, "record P2 wrong alignment");
_Static_assert(sizeof(struct P2_size) == 4, "record P2 wrong sizeof");
_Static_assert(_Alignof(struct P2_size) == 1, "record P2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(P2,d) == 0, "field P2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(P2,e) == 0, "field P2.e wrong bit offset");
#endif
_Static_assert(sizeof(Q2) == 8, "record Q2 wrong sizeof");
_Static_assert(_Alignof(Q2) == 8, "record Q2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Q2_alignment) == 16, "record Q2 wrong sizeof");
_Static_assert(_Alignof(struct Q2_alignment) == 8, "record Q2 wrong alignment");
_Static_assert(sizeof(struct Q2_packed) == 8, "record Q2 wrong sizeof");
_Static_assert(_Alignof(struct Q2_packed) == 1, "record Q2 wrong alignment");
_Static_assert(sizeof(struct Q2_required_alignment) == 9, "record Q2 wrong sizeof");
_Static_assert(_Alignof(struct Q2_required_alignment) == 1, "record Q2 wrong alignment");
_Static_assert(sizeof(struct Q2_size) == 10, "record Q2 wrong sizeof");
_Static_assert(_Alignof(struct Q2_size) == 1, "record Q2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(Q2,x) == 0, "field Q2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(Q2,d) == 0, "field Q2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(Q2,e) == 0, "field Q2.e wrong bit offset");
#endif
_Static_assert(sizeof(R2) == 1, "record R2 wrong sizeof");
_Static_assert(_Alignof(R2) == 1, "record R2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct R2_alignment) == 2, "record R2 wrong sizeof");
_Static_assert(_Alignof(struct R2_alignment) == 1, "record R2 wrong alignment");
_Static_assert(sizeof(struct R2_packed) == 1, "record R2 wrong sizeof");
_Static_assert(_Alignof(struct R2_packed) == 1, "record R2 wrong alignment");
_Static_assert(sizeof(struct R2_required_alignment) == 2, "record R2 wrong sizeof");
_Static_assert(_Alignof(struct R2_required_alignment) == 1, "record R2 wrong alignment");
_Static_assert(sizeof(struct R2_size) == 3, "record R2 wrong sizeof");
_Static_assert(_Alignof(struct R2_size) == 1, "record R2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(R2,x) == 0, "field R2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(R2,e) == 0, "field R2.e wrong bit offset");
#endif
_Static_assert(sizeof(S2) == 1, "record S2 wrong sizeof");
_Static_assert(_Alignof(S2) == 1, "record S2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct S2_alignment) == 2, "record S2 wrong sizeof");
_Static_assert(_Alignof(struct S2_alignment) == 1, "record S2 wrong alignment");
_Static_assert(sizeof(struct S2_packed) == 1, "record S2 wrong sizeof");
_Static_assert(_Alignof(struct S2_packed) == 1, "record S2 wrong alignment");
_Static_assert(sizeof(struct S2_required_alignment) == 2, "record S2 wrong sizeof");
_Static_assert(_Alignof(struct S2_required_alignment) == 1, "record S2 wrong alignment");
_Static_assert(sizeof(struct S2_size) == 3, "record S2 wrong sizeof");
_Static_assert(_Alignof(struct S2_size) == 1, "record S2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(S2,x) == 0, "field S2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(S2,e) == 0, "field S2.e wrong bit offset");
#endif
_Static_assert(sizeof(T2) == 1, "record T2 wrong sizeof");
_Static_assert(_Alignof(T2) == 1, "record T2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct T2_alignment) == 2, "record T2 wrong sizeof");
_Static_assert(_Alignof(struct T2_alignment) == 1, "record T2 wrong alignment");
_Static_assert(sizeof(struct T2_packed) == 1, "record T2 wrong sizeof");
_Static_assert(_Alignof(struct T2_packed) == 1, "record T2 wrong alignment");
_Static_assert(sizeof(struct T2_required_alignment) == 2, "record T2 wrong sizeof");
_Static_assert(_Alignof(struct T2_required_alignment) == 1, "record T2 wrong alignment");
_Static_assert(sizeof(struct T2_size) == 3, "record T2 wrong sizeof");
_Static_assert(_Alignof(struct T2_size) == 1, "record T2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(T2,x) == 0, "field T2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(T2,e) == 0, "field T2.e wrong bit offset");
#endif
_Static_assert(sizeof(U2) == 1, "record U2 wrong sizeof");
_Static_assert(_Alignof(U2) == 1, "record U2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct U2_alignment) == 2, "record U2 wrong sizeof");
_Static_assert(_Alignof(struct U2_alignment) == 1, "record U2 wrong alignment");
_Static_assert(sizeof(struct U2_packed) == 1, "record U2 wrong sizeof");
_Static_assert(_Alignof(struct U2_packed) == 1, "record U2 wrong alignment");
_Static_assert(sizeof(struct U2_required_alignment) == 2, "record U2 wrong sizeof");
_Static_assert(_Alignof(struct U2_required_alignment) == 1, "record U2 wrong alignment");
_Static_assert(sizeof(struct U2_size) == 3, "record U2 wrong sizeof");
_Static_assert(_Alignof(struct U2_size) == 1, "record U2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(U2,x) == 0, "field U2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(U2,e) == 0, "field U2.e wrong bit offset");
#endif
_Static_assert(sizeof(V2) == 1, "record V2 wrong sizeof");
_Static_assert(_Alignof(V2) == 1, "record V2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct V2_alignment) == 2, "record V2 wrong sizeof");
_Static_assert(_Alignof(struct V2_alignment) == 1, "record V2 wrong alignment");
_Static_assert(sizeof(struct V2_packed) == 1, "record V2 wrong sizeof");
_Static_assert(_Alignof(struct V2_packed) == 1, "record V2 wrong alignment");
_Static_assert(sizeof(struct V2_required_alignment) == 2, "record V2 wrong sizeof");
_Static_assert(_Alignof(struct V2_required_alignment) == 1, "record V2 wrong alignment");
_Static_assert(sizeof(struct V2_size) == 3, "record V2 wrong sizeof");
_Static_assert(_Alignof(struct V2_size) == 1, "record V2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(V2,x) == 0, "field V2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(V2,e) == 0, "field V2.e wrong bit offset");
#endif
_Static_assert(sizeof(W2) == 1, "record W2 wrong sizeof");
_Static_assert(_Alignof(W2) == 1, "record W2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct W2_alignment) == 2, "record W2 wrong sizeof");
_Static_assert(_Alignof(struct W2_alignment) == 1, "record W2 wrong alignment");
_Static_assert(sizeof(struct W2_packed) == 1, "record W2 wrong sizeof");
_Static_assert(_Alignof(struct W2_packed) == 1, "record W2 wrong alignment");
_Static_assert(sizeof(struct W2_required_alignment) == 2, "record W2 wrong sizeof");
_Static_assert(_Alignof(struct W2_required_alignment) == 1, "record W2 wrong alignment");
_Static_assert(sizeof(struct W2_size) == 3, "record W2 wrong sizeof");
_Static_assert(_Alignof(struct W2_size) == 1, "record W2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(W2,x) == 0, "field W2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(W2,e) == 0, "field W2.e wrong bit offset");
#endif
_Static_assert(sizeof(W_2) == 1, "record W_2 wrong sizeof");
_Static_assert(_Alignof(W_2) == 1, "record W_2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct W_2_alignment) == 2, "record W_2 wrong sizeof");
_Static_assert(_Alignof(struct W_2_alignment) == 1, "record W_2 wrong alignment");
_Static_assert(sizeof(struct W_2_packed) == 1, "record W_2 wrong sizeof");
_Static_assert(_Alignof(struct W_2_packed) == 1, "record W_2 wrong alignment");
_Static_assert(sizeof(struct W_2_required_alignment) == 2, "record W_2 wrong sizeof");
_Static_assert(_Alignof(struct W_2_required_alignment) == 1, "record W_2 wrong alignment");
_Static_assert(sizeof(struct W_2_size) == 3, "record W_2 wrong sizeof");
_Static_assert(_Alignof(struct W_2_size) == 1, "record W_2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(W_2,e) == 0, "field W_2.e wrong bit offset");
#endif
_Static_assert(sizeof(X2) == 1, "record X2 wrong sizeof");
_Static_assert(_Alignof(X2) == 1, "record X2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct X2_alignment) == 2, "record X2 wrong sizeof");
_Static_assert(_Alignof(struct X2_alignment) == 1, "record X2 wrong alignment");
_Static_assert(sizeof(struct X2_packed) == 1, "record X2 wrong sizeof");
_Static_assert(_Alignof(struct X2_packed) == 1, "record X2 wrong alignment");
_Static_assert(sizeof(struct X2_required_alignment) == 2, "record X2 wrong sizeof");
_Static_assert(_Alignof(struct X2_required_alignment) == 1, "record X2 wrong alignment");
_Static_assert(sizeof(struct X2_size) == 3, "record X2 wrong sizeof");
_Static_assert(_Alignof(struct X2_size) == 1, "record X2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(X2,x) == 0, "field X2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(X2,e) == 0, "field X2.e wrong bit offset");
#endif
_Static_assert(sizeof(Y) == 9, "record Y wrong sizeof");
_Static_assert(_Alignof(Y) == 1, "record Y wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Y_alignment) == 10, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_alignment) == 1, "record Y wrong alignment");
_Static_assert(sizeof(struct Y_packed) == 9, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_packed) == 1, "record Y wrong alignment");
_Static_assert(sizeof(struct Y_required_alignment) == 10, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_required_alignment) == 1, "record Y wrong alignment");
_Static_assert(sizeof(struct Y_size) == 11, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_size) == 1, "record Y wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(Y,d) == 64, "field Y.d wrong bit offset");
#endif
_Static_assert(sizeof(Y2) == 1, "record Y2 wrong sizeof");
_Static_assert(_Alignof(Y2) == 1, "record Y2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Y2_alignment) == 2, "record Y2 wrong sizeof");
_Static_assert(_Alignof(struct Y2_alignment) == 1, "record Y2 wrong alignment");
_Static_assert(sizeof(struct Y2_packed) == 1, "record Y2 wrong sizeof");
_Static_assert(_Alignof(struct Y2_packed) == 1, "record Y2 wrong alignment");
_Static_assert(sizeof(struct Y2_required_alignment) == 2, "record Y2 wrong sizeof");
_Static_assert(_Alignof(struct Y2_required_alignment) == 1, "record Y2 wrong alignment");
_Static_assert(sizeof(struct Y2_size) == 3, "record Y2 wrong sizeof");
_Static_assert(_Alignof(struct Y2_size) == 1, "record Y2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(Y2,d) == 0, "field Y2.d wrong bit offset");
#endif
_Static_assert(sizeof(A3) == 33, "record A3 wrong sizeof");
_Static_assert(_Alignof(A3) == 1, "record A3 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A3_alignment) == 34, "record A3 wrong sizeof");
_Static_assert(_Alignof(struct A3_alignment) == 1, "record A3 wrong alignment");
_Static_assert(sizeof(struct A3_packed) == 33, "record A3 wrong sizeof");
_Static_assert(_Alignof(struct A3_packed) == 1, "record A3 wrong alignment");
_Static_assert(sizeof(struct A3_required_alignment) == 34, "record A3 wrong sizeof");
_Static_assert(_Alignof(struct A3_required_alignment) == 1, "record A3 wrong alignment");
_Static_assert(sizeof(struct A3_size) == 35, "record A3 wrong sizeof");
_Static_assert(_Alignof(struct A3_size) == 1, "record A3 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A3,d) == 256, "field A3.d wrong bit offset");
#endif
_Static_assert(sizeof(A4) == 1, "record A4 wrong sizeof");
_Static_assert(_Alignof(A4) == 32, "record A4 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A4_alignment) == 64, "record A4 wrong sizeof");
_Static_assert(_Alignof(struct A4_alignment) == 32, "record A4 wrong alignment");
_Static_assert(sizeof(struct A4_packed) == 1, "record A4 wrong sizeof");
_Static_assert(_Alignof(struct A4_packed) == 1, "record A4 wrong alignment");
_Static_assert(sizeof(struct A4_required_alignment) == 2, "record A4 wrong sizeof");
_Static_assert(_Alignof(struct A4_required_alignment) == 1, "record A4 wrong alignment");
_Static_assert(sizeof(struct A4_size) == 3, "record A4 wrong sizeof");
_Static_assert(_Alignof(struct A4_size) == 1, "record A4 wrong alignment");
#endif
_Static_assert(sizeof(A5) == 33, "record A5 wrong sizeof");
_Static_assert(_Alignof(A5) == 1, "record A5 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A5_alignment) == 34, "record A5 wrong sizeof");
_Static_assert(_Alignof(struct A5_alignment) == 1, "record A5 wrong alignment");
_Static_assert(sizeof(struct A5_packed) == 33, "record A5 wrong sizeof");
_Static_assert(_Alignof(struct A5_packed) == 1, "record A5 wrong alignment");
_Static_assert(sizeof(struct A5_required_alignment) == 34, "record A5 wrong sizeof");
_Static_assert(_Alignof(struct A5_required_alignment) == 1, "record A5 wrong alignment");
_Static_assert(sizeof(struct A5_size) == 35, "record A5 wrong sizeof");
_Static_assert(_Alignof(struct A5_size) == 1, "record A5 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A5,d) == 256, "field A5.d wrong bit offset");
#endif
_Static_assert(sizeof(A7) == 32, "record A7 wrong sizeof");
_Static_assert(_Alignof(A7) == 32, "record A7 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A7_alignment) == 64, "record A7 wrong sizeof");
_Static_assert(_Alignof(struct A7_alignment) == 32, "record A7 wrong alignment");
_Static_assert(sizeof(struct A7_packed) == 32, "record A7 wrong sizeof");
_Static_assert(_Alignof(struct A7_packed) == 1, "record A7 wrong alignment");
_Static_assert(sizeof(struct A7_required_alignment) == 33, "record A7 wrong sizeof");
_Static_assert(_Alignof(struct A7_required_alignment) == 1, "record A7 wrong alignment");
_Static_assert(sizeof(struct A7_size) == 34, "record A7 wrong sizeof");
_Static_assert(_Alignof(struct A7_size) == 1, "record A7 wrong alignment");
#endif
_Static_assert(sizeof(A8) == 8, "record A8 wrong sizeof");
_Static_assert(_Alignof(A8) == 8, "record A8 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A8_alignment) == 16, "record A8 wrong sizeof");
_Static_assert(_Alignof(struct A8_alignment) == 8, "record A8 wrong alignment");
_Static_assert(sizeof(struct A8_packed) == 8, "record A8 wrong sizeof");
_Static_assert(_Alignof(struct A8_packed) == 1, "record A8 wrong alignment");
_Static_assert(sizeof(struct A8_required_alignment) == 9, "record A8 wrong sizeof");
_Static_assert(_Alignof(struct A8_required_alignment) == 1, "record A8 wrong alignment");
_Static_assert(sizeof(struct A8_size) == 10, "record A8 wrong sizeof");
_Static_assert(_Alignof(struct A8_size) == 1, "record A8 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A8,i) == 8, "field A8.i wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A8,j) == 39, "field A8.j wrong bit offset");
#endif
_Static_assert(sizeof(A9) == 16, "record A9 wrong sizeof");
_Static_assert(_Alignof(A9) == 8, "record A9 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A9_alignment) == 24, "record A9 wrong sizeof");
_Static_assert(_Alignof(struct A9_alignment) == 8, "record A9 wrong alignment");
_Static_assert(sizeof(struct A9_packed) == 16, "record A9 wrong sizeof");
_Static_assert(_Alignof(struct A9_packed) == 1, "record A9 wrong alignment");
_Static_assert(sizeof(struct A9_required_alignment) == 17, "record A9 wrong sizeof");
_Static_assert(_Alignof(struct A9_required_alignment) == 1, "record A9 wrong alignment");
_Static_assert(sizeof(struct A9_size) == 18, "record A9 wrong sizeof");
_Static_assert(_Alignof(struct A9_size) == 1, "record A9 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A9,i) == 8, "field A9.i wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A9,j) == 64, "field A9.j wrong bit offset");
#endif
_Static_assert(sizeof(A10) == 8, "record A10 wrong sizeof");
_Static_assert(_Alignof(A10) == 16, "record A10 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A10_alignment) == 32, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_alignment) == 16, "record A10 wrong alignment");
_Static_assert(sizeof(struct A10_packed) == 8, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_packed) == 1, "record A10 wrong alignment");
_Static_assert(sizeof(struct A10_required_alignment) == 9, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_required_alignment) == 1, "record A10 wrong alignment");
_Static_assert(sizeof(struct A10_size) == 10, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_size) == 1, "record A10 wrong alignment");
#endif
_Static_assert(sizeof(A11) == 32, "record A11 wrong sizeof");
_Static_assert(_Alignof(A11) == 16, "record A11 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A11_alignment) == 48, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_alignment) == 16, "record A11 wrong alignment");
_Static_assert(sizeof(struct A11_packed) == 32, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_packed) == 1, "record A11 wrong alignment");
_Static_assert(sizeof(struct A11_required_alignment) == 33, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_required_alignment) == 1, "record A11 wrong alignment");
_Static_assert(sizeof(struct A11_size) == 34, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_size) == 1, "record A11 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A11,i) == 8, "field A11.i wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A11,j) == 128, "field A11.j wrong bit offset");
#endif
_Static_assert(sizeof(A12) == 32, "record A12 wrong sizeof");
_Static_assert(_Alignof(A12) == 16, "record A12 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A12_alignment) == 48, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_alignment) == 16, "record A12 wrong alignment");
_Static_assert(sizeof(struct A12_packed) == 32, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_packed) == 1, "record A12 wrong alignment");
_Static_assert(sizeof(struct A12_required_alignment) == 33, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_required_alignment) == 1, "record A12 wrong alignment");
_Static_assert(sizeof(struct A12_size) == 34, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_size) == 1, "record A12 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A12,i) == 8, "field A12.i wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A12,j) == 128, "field A12.j wrong bit offset");
#endif
_Static_assert(sizeof(A13) == 32, "record A13 wrong sizeof");
_Static_assert(_Alignof(A13) == 16, "record A13 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A13_alignment) == 48, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_alignment) == 16, "record A13 wrong alignment");
_Static_assert(sizeof(struct A13_packed) == 32, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_packed) == 1, "record A13 wrong alignment");
_Static_assert(sizeof(struct A13_required_alignment) == 33, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_required_alignment) == 1, "record A13 wrong alignment");
_Static_assert(sizeof(struct A13_size) == 34, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_size) == 1, "record A13 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A13,i) == 8, "field A13.i wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A13,j) == 128, "field A13.j wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A13,d) == 136, "field A13.d wrong bit offset");
#endif
// MAPPING|THIRTEEN|mipsel-mips32-linux-gnu:Gcc|mipsel-mips32-linux-musl:Gcc|mips-mips32-linux-gnu:Gcc|mips-mips32r6-linux-gnu:Gcc|mips-mips32-linux-gnu:Gcc|mips-mips32-linux-musl:Gcc|powerpc-ppc-linux-gnu:Gcc|powerpc-ppc-linux-musl:Gcc|riscv32-generic_rv32-linux-gnu:Gcc|sparc-v8-linux-gnu:Gcc|x86_64-x86_64-linux-gnux32:Gcc|END
// repr targets MipselUnknownLinuxGnu|Some("mipsel-mips32-linux-gnu") MipselUnknownLinuxMusl|Some("mipsel-mips32-linux-musl") MipselUnknownLinuxUclibc|None Mipsisa32r6elUnknownLinuxGnu|Some("mips-mips32-linux-gnu") Mipsisa32r6UnknownLinuxGnu|Some("mips-mips32r6-linux-gnu") MipsUnknownLinuxGnu|Some("mips-mips32-linux-gnu") MipsUnknownLinuxMusl|Some("mips-mips32-linux-musl") MipsUnknownLinuxUclibc|None PowerpcUnknownLinuxGnu|Some("powerpc-ppc-linux-gnu") PowerpcUnknownLinuxMusl|Some("powerpc-ppc-linux-musl") Riscv32UnknownLinuxGnu|Some("riscv32-generic_rv32-linux-gnu") SparcUnknownLinuxGnu|Some("sparc-v8-linux-gnu") X86_64UnknownLinuxGnux32|Some("x86_64-x86_64-linux-gnux32") 
#elif defined(THIRTEEN)
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
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A,d) == 0, "field A.d wrong bit offset");
#endif
_Static_assert(sizeof(A_) == 5, "record A_ wrong sizeof");
_Static_assert(_Alignof(A_) == 1, "record A_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A__alignment) == 6, "record A_ wrong sizeof");
_Static_assert(_Alignof(struct A__alignment) == 1, "record A_ wrong alignment");
_Static_assert(sizeof(struct A__packed) == 5, "record A_ wrong sizeof");
_Static_assert(_Alignof(struct A__packed) == 1, "record A_ wrong alignment");
_Static_assert(sizeof(struct A__required_alignment) == 6, "record A_ wrong sizeof");
_Static_assert(_Alignof(struct A__required_alignment) == 1, "record A_ wrong alignment");
_Static_assert(sizeof(struct A__size) == 7, "record A_ wrong sizeof");
_Static_assert(_Alignof(struct A__size) == 1, "record A_ wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_,d) == 32, "field A_.d wrong bit offset");
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
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B,d) == 0, "field B.d wrong bit offset");
#endif
_Static_assert(sizeof(B_) == 9, "record B_ wrong sizeof");
_Static_assert(_Alignof(B_) == 1, "record B_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B__alignment) == 10, "record B_ wrong sizeof");
_Static_assert(_Alignof(struct B__alignment) == 1, "record B_ wrong alignment");
_Static_assert(sizeof(struct B__packed) == 9, "record B_ wrong sizeof");
_Static_assert(_Alignof(struct B__packed) == 1, "record B_ wrong alignment");
_Static_assert(sizeof(struct B__required_alignment) == 10, "record B_ wrong sizeof");
_Static_assert(_Alignof(struct B__required_alignment) == 1, "record B_ wrong alignment");
_Static_assert(sizeof(struct B__size) == 11, "record B_ wrong sizeof");
_Static_assert(_Alignof(struct B__size) == 1, "record B_ wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B_,d) == 64, "field B_.d wrong bit offset");
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
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C,d) == 0, "field C.d wrong bit offset");
#endif
_Static_assert(sizeof(C_) == 9, "record C_ wrong sizeof");
_Static_assert(_Alignof(C_) == 1, "record C_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C__alignment) == 10, "record C_ wrong sizeof");
_Static_assert(_Alignof(struct C__alignment) == 1, "record C_ wrong alignment");
_Static_assert(sizeof(struct C__packed) == 9, "record C_ wrong sizeof");
_Static_assert(_Alignof(struct C__packed) == 1, "record C_ wrong alignment");
_Static_assert(sizeof(struct C__required_alignment) == 10, "record C_ wrong sizeof");
_Static_assert(_Alignof(struct C__required_alignment) == 1, "record C_ wrong alignment");
_Static_assert(sizeof(struct C__size) == 11, "record C_ wrong sizeof");
_Static_assert(_Alignof(struct C__size) == 1, "record C_ wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C_,d) == 64, "field C_.d wrong bit offset");
#endif
_Static_assert(sizeof(D) == 24, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 8, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 32, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 8, "record D wrong alignment");
_Static_assert(sizeof(struct D_packed) == 24, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 25, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_size) == 26, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_size) == 1, "record D wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D,d) == 64, "field D.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(D,e) == 128, "field D.e wrong bit offset");
#endif
_Static_assert(sizeof(F) == 32, "record F wrong sizeof");
_Static_assert(_Alignof(F) == 16, "record F wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 48, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_alignment) == 16, "record F wrong alignment");
_Static_assert(sizeof(struct F_packed) == 32, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_packed) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_required_alignment) == 33, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_size) == 34, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_size) == 1, "record F wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F,d) == 128, "field F.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(F,e) == 192, "field F.e wrong bit offset");
#endif
_Static_assert(sizeof(G) == 12, "record G wrong sizeof");
_Static_assert(_Alignof(G) == 2, "record G wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 14, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_alignment) == 2, "record G wrong alignment");
_Static_assert(sizeof(struct G_packed) == 12, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_packed) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_required_alignment) == 13, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_size) == 14, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_size) == 1, "record G wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(G,d) == 16, "field G.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(G,e) == 80, "field G.e wrong bit offset");
#endif
_Static_assert(sizeof(H) == 12, "record H wrong sizeof");
_Static_assert(_Alignof(H) == 2, "record H wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 14, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_alignment) == 2, "record H wrong alignment");
_Static_assert(sizeof(struct H_packed) == 12, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_packed) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_required_alignment) == 13, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_size) == 14, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_size) == 1, "record H wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(H,d) == 16, "field H.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(H,e) == 80, "field H.e wrong bit offset");
#endif
_Static_assert(sizeof(I) == 10, "record I wrong sizeof");
_Static_assert(_Alignof(I) == 1, "record I wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I_alignment) == 11, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_alignment) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_packed) == 10, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_packed) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_required_alignment) == 11, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_required_alignment) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_size) == 12, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_size) == 1, "record I wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(I,d) == 8, "field I.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(I,e) == 72, "field I.e wrong bit offset");
#endif
_Static_assert(sizeof(J) == 12, "record J wrong sizeof");
_Static_assert(_Alignof(J) == 2, "record J wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J_alignment) == 14, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_alignment) == 2, "record J wrong alignment");
_Static_assert(sizeof(struct J_packed) == 12, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_packed) == 1, "record J wrong alignment");
_Static_assert(sizeof(struct J_required_alignment) == 13, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_required_alignment) == 1, "record J wrong alignment");
_Static_assert(sizeof(struct J_size) == 14, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_size) == 1, "record J wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(J,d) == 16, "field J.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(J,e) == 80, "field J.e wrong bit offset");
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
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(K,d) == 8, "field K.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(K,e) == 16, "field K.e wrong bit offset");
#endif
_Static_assert(sizeof(L) == 32, "record L wrong sizeof");
_Static_assert(_Alignof(L) == 16, "record L wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct L_alignment) == 48, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_alignment) == 16, "record L wrong alignment");
_Static_assert(sizeof(struct L_packed) == 32, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_packed) == 1, "record L wrong alignment");
_Static_assert(sizeof(struct L_required_alignment) == 33, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_required_alignment) == 1, "record L wrong alignment");
_Static_assert(sizeof(struct L_size) == 34, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_size) == 1, "record L wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(L,d) == 128, "field L.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(L,e) == 136, "field L.e wrong bit offset");
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
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(M,d) == 16, "field M.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(M,e) == 24, "field M.e wrong bit offset");
#endif
_Static_assert(sizeof(N) == 4, "record N wrong sizeof");
_Static_assert(_Alignof(N) == 2, "record N wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct N_alignment) == 6, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_alignment) == 2, "record N wrong alignment");
_Static_assert(sizeof(struct N_packed) == 4, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_packed) == 1, "record N wrong alignment");
_Static_assert(sizeof(struct N_required_alignment) == 5, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_required_alignment) == 1, "record N wrong alignment");
_Static_assert(sizeof(struct N_size) == 6, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_size) == 1, "record N wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(N,d) == 16, "field N.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(N,e) == 24, "field N.e wrong bit offset");
#endif
_Static_assert(sizeof(O) == 3, "record O wrong sizeof");
_Static_assert(_Alignof(O) == 1, "record O wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct O_alignment) == 4, "record O wrong sizeof");
_Static_assert(_Alignof(struct O_alignment) == 1, "record O wrong alignment");
_Static_assert(sizeof(struct O_packed) == 3, "record O wrong sizeof");
_Static_assert(_Alignof(struct O_packed) == 1, "record O wrong alignment");
_Static_assert(sizeof(struct O_required_alignment) == 4, "record O wrong sizeof");
_Static_assert(_Alignof(struct O_required_alignment) == 1, "record O wrong alignment");
_Static_assert(sizeof(struct O_size) == 5, "record O wrong sizeof");
_Static_assert(_Alignof(struct O_size) == 1, "record O wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(O,d) == 8, "field O.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(O,e) == 16, "field O.e wrong bit offset");
#endif
_Static_assert(sizeof(P) == 4, "record P wrong sizeof");
_Static_assert(_Alignof(P) == 2, "record P wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct P_alignment) == 6, "record P wrong sizeof");
_Static_assert(_Alignof(struct P_alignment) == 2, "record P wrong alignment");
_Static_assert(sizeof(struct P_packed) == 4, "record P wrong sizeof");
_Static_assert(_Alignof(struct P_packed) == 1, "record P wrong alignment");
_Static_assert(sizeof(struct P_required_alignment) == 5, "record P wrong sizeof");
_Static_assert(_Alignof(struct P_required_alignment) == 1, "record P wrong alignment");
_Static_assert(sizeof(struct P_size) == 6, "record P wrong sizeof");
_Static_assert(_Alignof(struct P_size) == 1, "record P wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(P,d) == 8, "field P.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(P,e) == 16, "field P.e wrong bit offset");
#endif
_Static_assert(sizeof(Q) == 8, "record Q wrong sizeof");
_Static_assert(_Alignof(Q) == 8, "record Q wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Q_alignment) == 16, "record Q wrong sizeof");
_Static_assert(_Alignof(struct Q_alignment) == 8, "record Q wrong alignment");
_Static_assert(sizeof(struct Q_packed) == 8, "record Q wrong sizeof");
_Static_assert(_Alignof(struct Q_packed) == 1, "record Q wrong alignment");
_Static_assert(sizeof(struct Q_required_alignment) == 9, "record Q wrong sizeof");
_Static_assert(_Alignof(struct Q_required_alignment) == 1, "record Q wrong alignment");
_Static_assert(sizeof(struct Q_size) == 10, "record Q wrong sizeof");
_Static_assert(_Alignof(struct Q_size) == 1, "record Q wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(Q,x) == 8, "field Q.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(Q,d) == 9, "field Q.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(Q,e) == 16, "field Q.e wrong bit offset");
#endif
_Static_assert(sizeof(R) == 17, "record R wrong sizeof");
_Static_assert(_Alignof(R) == 1, "record R wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct R_alignment) == 18, "record R wrong sizeof");
_Static_assert(_Alignof(struct R_alignment) == 1, "record R wrong alignment");
_Static_assert(sizeof(struct R_packed) == 17, "record R wrong sizeof");
_Static_assert(_Alignof(struct R_packed) == 1, "record R wrong alignment");
_Static_assert(sizeof(struct R_required_alignment) == 18, "record R wrong sizeof");
_Static_assert(_Alignof(struct R_required_alignment) == 1, "record R wrong alignment");
_Static_assert(sizeof(struct R_size) == 19, "record R wrong sizeof");
_Static_assert(_Alignof(struct R_size) == 1, "record R wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(R,x) == 8, "field R.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(R,e) == 128, "field R.e wrong bit offset");
#endif
_Static_assert(sizeof(S) == 9, "record S wrong sizeof");
_Static_assert(_Alignof(S) == 1, "record S wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct S_alignment) == 10, "record S wrong sizeof");
_Static_assert(_Alignof(struct S_alignment) == 1, "record S wrong alignment");
_Static_assert(sizeof(struct S_packed) == 9, "record S wrong sizeof");
_Static_assert(_Alignof(struct S_packed) == 1, "record S wrong alignment");
_Static_assert(sizeof(struct S_required_alignment) == 10, "record S wrong sizeof");
_Static_assert(_Alignof(struct S_required_alignment) == 1, "record S wrong alignment");
_Static_assert(sizeof(struct S_size) == 11, "record S wrong sizeof");
_Static_assert(_Alignof(struct S_size) == 1, "record S wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(S,x) == 8, "field S.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(S,e) == 64, "field S.e wrong bit offset");
#endif
_Static_assert(sizeof(T) == 9, "record T wrong sizeof");
_Static_assert(_Alignof(T) == 1, "record T wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct T_alignment) == 10, "record T wrong sizeof");
_Static_assert(_Alignof(struct T_alignment) == 1, "record T wrong alignment");
_Static_assert(sizeof(struct T_packed) == 9, "record T wrong sizeof");
_Static_assert(_Alignof(struct T_packed) == 1, "record T wrong alignment");
_Static_assert(sizeof(struct T_required_alignment) == 10, "record T wrong sizeof");
_Static_assert(_Alignof(struct T_required_alignment) == 1, "record T wrong alignment");
_Static_assert(sizeof(struct T_size) == 11, "record T wrong sizeof");
_Static_assert(_Alignof(struct T_size) == 1, "record T wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(T,x) == 8, "field T.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(T,e) == 64, "field T.e wrong bit offset");
#endif
_Static_assert(sizeof(U) == 9, "record U wrong sizeof");
_Static_assert(_Alignof(U) == 1, "record U wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct U_alignment) == 10, "record U wrong sizeof");
_Static_assert(_Alignof(struct U_alignment) == 1, "record U wrong alignment");
_Static_assert(sizeof(struct U_packed) == 9, "record U wrong sizeof");
_Static_assert(_Alignof(struct U_packed) == 1, "record U wrong alignment");
_Static_assert(sizeof(struct U_required_alignment) == 10, "record U wrong sizeof");
_Static_assert(_Alignof(struct U_required_alignment) == 1, "record U wrong alignment");
_Static_assert(sizeof(struct U_size) == 11, "record U wrong sizeof");
_Static_assert(_Alignof(struct U_size) == 1, "record U wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(U,x) == 8, "field U.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(U,e) == 64, "field U.e wrong bit offset");
#endif
_Static_assert(sizeof(V) == 9, "record V wrong sizeof");
_Static_assert(_Alignof(V) == 1, "record V wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct V_alignment) == 10, "record V wrong sizeof");
_Static_assert(_Alignof(struct V_alignment) == 1, "record V wrong alignment");
_Static_assert(sizeof(struct V_packed) == 9, "record V wrong sizeof");
_Static_assert(_Alignof(struct V_packed) == 1, "record V wrong alignment");
_Static_assert(sizeof(struct V_required_alignment) == 10, "record V wrong sizeof");
_Static_assert(_Alignof(struct V_required_alignment) == 1, "record V wrong alignment");
_Static_assert(sizeof(struct V_size) == 11, "record V wrong sizeof");
_Static_assert(_Alignof(struct V_size) == 1, "record V wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(V,x) == 8, "field V.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(V,e) == 64, "field V.e wrong bit offset");
#endif
_Static_assert(sizeof(W) == 17, "record W wrong sizeof");
_Static_assert(_Alignof(W) == 1, "record W wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct W_alignment) == 18, "record W wrong sizeof");
_Static_assert(_Alignof(struct W_alignment) == 1, "record W wrong alignment");
_Static_assert(sizeof(struct W_packed) == 17, "record W wrong sizeof");
_Static_assert(_Alignof(struct W_packed) == 1, "record W wrong alignment");
_Static_assert(sizeof(struct W_required_alignment) == 18, "record W wrong sizeof");
_Static_assert(_Alignof(struct W_required_alignment) == 1, "record W wrong alignment");
_Static_assert(sizeof(struct W_size) == 19, "record W wrong sizeof");
_Static_assert(_Alignof(struct W_size) == 1, "record W wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(W,x) == 8, "field W.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(W,e) == 128, "field W.e wrong bit offset");
#endif
_Static_assert(sizeof(W_) == 17, "record W_ wrong sizeof");
_Static_assert(_Alignof(W_) == 1, "record W_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct W__alignment) == 18, "record W_ wrong sizeof");
_Static_assert(_Alignof(struct W__alignment) == 1, "record W_ wrong alignment");
_Static_assert(sizeof(struct W__packed) == 17, "record W_ wrong sizeof");
_Static_assert(_Alignof(struct W__packed) == 1, "record W_ wrong alignment");
_Static_assert(sizeof(struct W__required_alignment) == 18, "record W_ wrong sizeof");
_Static_assert(_Alignof(struct W__required_alignment) == 1, "record W_ wrong alignment");
_Static_assert(sizeof(struct W__size) == 19, "record W_ wrong sizeof");
_Static_assert(_Alignof(struct W__size) == 1, "record W_ wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(W_,e) == 128, "field W_.e wrong bit offset");
#endif
_Static_assert(sizeof(X) == 17, "record X wrong sizeof");
_Static_assert(_Alignof(X) == 1, "record X wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct X_alignment) == 18, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_alignment) == 1, "record X wrong alignment");
_Static_assert(sizeof(struct X_packed) == 17, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_packed) == 1, "record X wrong alignment");
_Static_assert(sizeof(struct X_required_alignment) == 18, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_required_alignment) == 1, "record X wrong alignment");
_Static_assert(sizeof(struct X_size) == 19, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_size) == 1, "record X wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(X,x) == 8, "field X.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(X,e) == 128, "field X.e wrong bit offset");
#endif
_Static_assert(sizeof(A2) == 1, "record A2 wrong sizeof");
_Static_assert(_Alignof(A2) == 1, "record A2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A2_alignment) == 2, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_alignment) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_packed) == 1, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_packed) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_required_alignment) == 2, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_required_alignment) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_size) == 3, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_size) == 1, "record A2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A2,d) == 0, "field A2.d wrong bit offset");
#endif
_Static_assert(sizeof(A_2) == 1, "record A_2 wrong sizeof");
_Static_assert(_Alignof(A_2) == 1, "record A_2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_2_alignment) == 2, "record A_2 wrong sizeof");
_Static_assert(_Alignof(struct A_2_alignment) == 1, "record A_2 wrong alignment");
_Static_assert(sizeof(struct A_2_packed) == 1, "record A_2 wrong sizeof");
_Static_assert(_Alignof(struct A_2_packed) == 1, "record A_2 wrong alignment");
_Static_assert(sizeof(struct A_2_required_alignment) == 2, "record A_2 wrong sizeof");
_Static_assert(_Alignof(struct A_2_required_alignment) == 1, "record A_2 wrong alignment");
_Static_assert(sizeof(struct A_2_size) == 3, "record A_2 wrong sizeof");
_Static_assert(_Alignof(struct A_2_size) == 1, "record A_2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_2,d) == 0, "field A_2.d wrong bit offset");
#endif
_Static_assert(sizeof(B2) == 1, "record B2 wrong sizeof");
_Static_assert(_Alignof(B2) == 1, "record B2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B2_alignment) == 2, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_alignment) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_packed) == 1, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_packed) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_required_alignment) == 2, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_required_alignment) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_size) == 3, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_size) == 1, "record B2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B2,d) == 0, "field B2.d wrong bit offset");
#endif
_Static_assert(sizeof(B_2) == 1, "record B_2 wrong sizeof");
_Static_assert(_Alignof(B_2) == 1, "record B_2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_2_alignment) == 2, "record B_2 wrong sizeof");
_Static_assert(_Alignof(struct B_2_alignment) == 1, "record B_2 wrong alignment");
_Static_assert(sizeof(struct B_2_packed) == 1, "record B_2 wrong sizeof");
_Static_assert(_Alignof(struct B_2_packed) == 1, "record B_2 wrong alignment");
_Static_assert(sizeof(struct B_2_required_alignment) == 2, "record B_2 wrong sizeof");
_Static_assert(_Alignof(struct B_2_required_alignment) == 1, "record B_2 wrong alignment");
_Static_assert(sizeof(struct B_2_size) == 3, "record B_2 wrong sizeof");
_Static_assert(_Alignof(struct B_2_size) == 1, "record B_2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B_2,d) == 0, "field B_2.d wrong bit offset");
#endif
_Static_assert(sizeof(C2) == 1, "record C2 wrong sizeof");
_Static_assert(_Alignof(C2) == 1, "record C2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C2_alignment) == 2, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_alignment) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_packed) == 1, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_packed) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_required_alignment) == 2, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_required_alignment) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_size) == 3, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_size) == 1, "record C2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C2,d) == 0, "field C2.d wrong bit offset");
#endif
_Static_assert(sizeof(C22) == 1, "record C22 wrong sizeof");
_Static_assert(_Alignof(C22) == 1, "record C22 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C22_alignment) == 2, "record C22 wrong sizeof");
_Static_assert(_Alignof(struct C22_alignment) == 1, "record C22 wrong alignment");
_Static_assert(sizeof(struct C22_packed) == 1, "record C22 wrong sizeof");
_Static_assert(_Alignof(struct C22_packed) == 1, "record C22 wrong alignment");
_Static_assert(sizeof(struct C22_required_alignment) == 2, "record C22 wrong sizeof");
_Static_assert(_Alignof(struct C22_required_alignment) == 1, "record C22 wrong alignment");
_Static_assert(sizeof(struct C22_size) == 3, "record C22 wrong sizeof");
_Static_assert(_Alignof(struct C22_size) == 1, "record C22 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C22,d) == 0, "field C22.d wrong bit offset");
#endif
_Static_assert(sizeof(D2) == 8, "record D2 wrong sizeof");
_Static_assert(_Alignof(D2) == 8, "record D2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D2_alignment) == 16, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_alignment) == 8, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_packed) == 8, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_packed) == 1, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_required_alignment) == 9, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_required_alignment) == 1, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_size) == 10, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_size) == 1, "record D2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D2,d) == 0, "field D2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(D2,e) == 0, "field D2.e wrong bit offset");
#endif
_Static_assert(sizeof(F2) == 16, "record F2 wrong sizeof");
_Static_assert(_Alignof(F2) == 16, "record F2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F2_alignment) == 32, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_alignment) == 16, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_packed) == 16, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_packed) == 1, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_required_alignment) == 17, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_required_alignment) == 1, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_size) == 18, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_size) == 1, "record F2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F2,d) == 0, "field F2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(F2,e) == 0, "field F2.e wrong bit offset");
#endif
_Static_assert(sizeof(G2) == 8, "record G2 wrong sizeof");
_Static_assert(_Alignof(G2) == 2, "record G2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G2_alignment) == 10, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_alignment) == 2, "record G2 wrong alignment");
_Static_assert(sizeof(struct G2_packed) == 8, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_packed) == 1, "record G2 wrong alignment");
_Static_assert(sizeof(struct G2_required_alignment) == 9, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_required_alignment) == 1, "record G2 wrong alignment");
_Static_assert(sizeof(struct G2_size) == 10, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_size) == 1, "record G2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(G2,d) == 0, "field G2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(G2,e) == 0, "field G2.e wrong bit offset");
#endif
_Static_assert(sizeof(H2) == 8, "record H2 wrong sizeof");
_Static_assert(_Alignof(H2) == 2, "record H2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H2_alignment) == 10, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_alignment) == 2, "record H2 wrong alignment");
_Static_assert(sizeof(struct H2_packed) == 8, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_packed) == 1, "record H2 wrong alignment");
_Static_assert(sizeof(struct H2_required_alignment) == 9, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_required_alignment) == 1, "record H2 wrong alignment");
_Static_assert(sizeof(struct H2_size) == 10, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_size) == 1, "record H2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(H2,d) == 0, "field H2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(H2,e) == 0, "field H2.e wrong bit offset");
#endif
_Static_assert(sizeof(I2) == 8, "record I2 wrong sizeof");
_Static_assert(_Alignof(I2) == 1, "record I2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I2_alignment) == 9, "record I2 wrong sizeof");
_Static_assert(_Alignof(struct I2_alignment) == 1, "record I2 wrong alignment");
_Static_assert(sizeof(struct I2_packed) == 8, "record I2 wrong sizeof");
_Static_assert(_Alignof(struct I2_packed) == 1, "record I2 wrong alignment");
_Static_assert(sizeof(struct I2_required_alignment) == 9, "record I2 wrong sizeof");
_Static_assert(_Alignof(struct I2_required_alignment) == 1, "record I2 wrong alignment");
_Static_assert(sizeof(struct I2_size) == 10, "record I2 wrong sizeof");
_Static_assert(_Alignof(struct I2_size) == 1, "record I2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(I2,d) == 0, "field I2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(I2,e) == 0, "field I2.e wrong bit offset");
#endif
_Static_assert(sizeof(J2) == 8, "record J2 wrong sizeof");
_Static_assert(_Alignof(J2) == 2, "record J2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J2_alignment) == 10, "record J2 wrong sizeof");
_Static_assert(_Alignof(struct J2_alignment) == 2, "record J2 wrong alignment");
_Static_assert(sizeof(struct J2_packed) == 8, "record J2 wrong sizeof");
_Static_assert(_Alignof(struct J2_packed) == 1, "record J2 wrong alignment");
_Static_assert(sizeof(struct J2_required_alignment) == 9, "record J2 wrong sizeof");
_Static_assert(_Alignof(struct J2_required_alignment) == 1, "record J2 wrong alignment");
_Static_assert(sizeof(struct J2_size) == 10, "record J2 wrong sizeof");
_Static_assert(_Alignof(struct J2_size) == 1, "record J2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(J2,d) == 0, "field J2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(J2,e) == 0, "field J2.e wrong bit offset");
#endif
_Static_assert(sizeof(K2) == 8, "record K2 wrong sizeof");
_Static_assert(_Alignof(K2) == 8, "record K2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct K2_alignment) == 16, "record K2 wrong sizeof");
_Static_assert(_Alignof(struct K2_alignment) == 8, "record K2 wrong alignment");
_Static_assert(sizeof(struct K2_packed) == 8, "record K2 wrong sizeof");
_Static_assert(_Alignof(struct K2_packed) == 1, "record K2 wrong alignment");
_Static_assert(sizeof(struct K2_required_alignment) == 9, "record K2 wrong sizeof");
_Static_assert(_Alignof(struct K2_required_alignment) == 1, "record K2 wrong alignment");
_Static_assert(sizeof(struct K2_size) == 10, "record K2 wrong sizeof");
_Static_assert(_Alignof(struct K2_size) == 1, "record K2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(K2,d) == 0, "field K2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(K2,e) == 0, "field K2.e wrong bit offset");
#endif
_Static_assert(sizeof(L2) == 16, "record L2 wrong sizeof");
_Static_assert(_Alignof(L2) == 16, "record L2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct L2_alignment) == 32, "record L2 wrong sizeof");
_Static_assert(_Alignof(struct L2_alignment) == 16, "record L2 wrong alignment");
_Static_assert(sizeof(struct L2_packed) == 16, "record L2 wrong sizeof");
_Static_assert(_Alignof(struct L2_packed) == 1, "record L2 wrong alignment");
_Static_assert(sizeof(struct L2_required_alignment) == 17, "record L2 wrong sizeof");
_Static_assert(_Alignof(struct L2_required_alignment) == 1, "record L2 wrong alignment");
_Static_assert(sizeof(struct L2_size) == 18, "record L2 wrong sizeof");
_Static_assert(_Alignof(struct L2_size) == 1, "record L2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(L2,d) == 0, "field L2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(L2,e) == 0, "field L2.e wrong bit offset");
#endif
_Static_assert(sizeof(M2) == 2, "record M2 wrong sizeof");
_Static_assert(_Alignof(M2) == 2, "record M2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct M2_alignment) == 4, "record M2 wrong sizeof");
_Static_assert(_Alignof(struct M2_alignment) == 2, "record M2 wrong alignment");
_Static_assert(sizeof(struct M2_packed) == 2, "record M2 wrong sizeof");
_Static_assert(_Alignof(struct M2_packed) == 1, "record M2 wrong alignment");
_Static_assert(sizeof(struct M2_required_alignment) == 3, "record M2 wrong sizeof");
_Static_assert(_Alignof(struct M2_required_alignment) == 1, "record M2 wrong alignment");
_Static_assert(sizeof(struct M2_size) == 4, "record M2 wrong sizeof");
_Static_assert(_Alignof(struct M2_size) == 1, "record M2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(M2,d) == 0, "field M2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(M2,e) == 0, "field M2.e wrong bit offset");
#endif
_Static_assert(sizeof(N2) == 2, "record N2 wrong sizeof");
_Static_assert(_Alignof(N2) == 2, "record N2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct N2_alignment) == 4, "record N2 wrong sizeof");
_Static_assert(_Alignof(struct N2_alignment) == 2, "record N2 wrong alignment");
_Static_assert(sizeof(struct N2_packed) == 2, "record N2 wrong sizeof");
_Static_assert(_Alignof(struct N2_packed) == 1, "record N2 wrong alignment");
_Static_assert(sizeof(struct N2_required_alignment) == 3, "record N2 wrong sizeof");
_Static_assert(_Alignof(struct N2_required_alignment) == 1, "record N2 wrong alignment");
_Static_assert(sizeof(struct N2_size) == 4, "record N2 wrong sizeof");
_Static_assert(_Alignof(struct N2_size) == 1, "record N2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(N2,d) == 0, "field N2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(N2,e) == 0, "field N2.e wrong bit offset");
#endif
_Static_assert(sizeof(O2) == 1, "record O2 wrong sizeof");
_Static_assert(_Alignof(O2) == 1, "record O2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct O2_alignment) == 2, "record O2 wrong sizeof");
_Static_assert(_Alignof(struct O2_alignment) == 1, "record O2 wrong alignment");
_Static_assert(sizeof(struct O2_packed) == 1, "record O2 wrong sizeof");
_Static_assert(_Alignof(struct O2_packed) == 1, "record O2 wrong alignment");
_Static_assert(sizeof(struct O2_required_alignment) == 2, "record O2 wrong sizeof");
_Static_assert(_Alignof(struct O2_required_alignment) == 1, "record O2 wrong alignment");
_Static_assert(sizeof(struct O2_size) == 3, "record O2 wrong sizeof");
_Static_assert(_Alignof(struct O2_size) == 1, "record O2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(O2,d) == 0, "field O2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(O2,e) == 0, "field O2.e wrong bit offset");
#endif
_Static_assert(sizeof(P2) == 2, "record P2 wrong sizeof");
_Static_assert(_Alignof(P2) == 2, "record P2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct P2_alignment) == 4, "record P2 wrong sizeof");
_Static_assert(_Alignof(struct P2_alignment) == 2, "record P2 wrong alignment");
_Static_assert(sizeof(struct P2_packed) == 2, "record P2 wrong sizeof");
_Static_assert(_Alignof(struct P2_packed) == 1, "record P2 wrong alignment");
_Static_assert(sizeof(struct P2_required_alignment) == 3, "record P2 wrong sizeof");
_Static_assert(_Alignof(struct P2_required_alignment) == 1, "record P2 wrong alignment");
_Static_assert(sizeof(struct P2_size) == 4, "record P2 wrong sizeof");
_Static_assert(_Alignof(struct P2_size) == 1, "record P2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(P2,d) == 0, "field P2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(P2,e) == 0, "field P2.e wrong bit offset");
#endif
_Static_assert(sizeof(Q2) == 8, "record Q2 wrong sizeof");
_Static_assert(_Alignof(Q2) == 8, "record Q2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Q2_alignment) == 16, "record Q2 wrong sizeof");
_Static_assert(_Alignof(struct Q2_alignment) == 8, "record Q2 wrong alignment");
_Static_assert(sizeof(struct Q2_packed) == 8, "record Q2 wrong sizeof");
_Static_assert(_Alignof(struct Q2_packed) == 1, "record Q2 wrong alignment");
_Static_assert(sizeof(struct Q2_required_alignment) == 9, "record Q2 wrong sizeof");
_Static_assert(_Alignof(struct Q2_required_alignment) == 1, "record Q2 wrong alignment");
_Static_assert(sizeof(struct Q2_size) == 10, "record Q2 wrong sizeof");
_Static_assert(_Alignof(struct Q2_size) == 1, "record Q2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(Q2,x) == 0, "field Q2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(Q2,d) == 0, "field Q2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(Q2,e) == 0, "field Q2.e wrong bit offset");
#endif
_Static_assert(sizeof(R2) == 1, "record R2 wrong sizeof");
_Static_assert(_Alignof(R2) == 1, "record R2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct R2_alignment) == 2, "record R2 wrong sizeof");
_Static_assert(_Alignof(struct R2_alignment) == 1, "record R2 wrong alignment");
_Static_assert(sizeof(struct R2_packed) == 1, "record R2 wrong sizeof");
_Static_assert(_Alignof(struct R2_packed) == 1, "record R2 wrong alignment");
_Static_assert(sizeof(struct R2_required_alignment) == 2, "record R2 wrong sizeof");
_Static_assert(_Alignof(struct R2_required_alignment) == 1, "record R2 wrong alignment");
_Static_assert(sizeof(struct R2_size) == 3, "record R2 wrong sizeof");
_Static_assert(_Alignof(struct R2_size) == 1, "record R2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(R2,x) == 0, "field R2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(R2,e) == 0, "field R2.e wrong bit offset");
#endif
_Static_assert(sizeof(S2) == 1, "record S2 wrong sizeof");
_Static_assert(_Alignof(S2) == 1, "record S2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct S2_alignment) == 2, "record S2 wrong sizeof");
_Static_assert(_Alignof(struct S2_alignment) == 1, "record S2 wrong alignment");
_Static_assert(sizeof(struct S2_packed) == 1, "record S2 wrong sizeof");
_Static_assert(_Alignof(struct S2_packed) == 1, "record S2 wrong alignment");
_Static_assert(sizeof(struct S2_required_alignment) == 2, "record S2 wrong sizeof");
_Static_assert(_Alignof(struct S2_required_alignment) == 1, "record S2 wrong alignment");
_Static_assert(sizeof(struct S2_size) == 3, "record S2 wrong sizeof");
_Static_assert(_Alignof(struct S2_size) == 1, "record S2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(S2,x) == 0, "field S2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(S2,e) == 0, "field S2.e wrong bit offset");
#endif
_Static_assert(sizeof(T2) == 1, "record T2 wrong sizeof");
_Static_assert(_Alignof(T2) == 1, "record T2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct T2_alignment) == 2, "record T2 wrong sizeof");
_Static_assert(_Alignof(struct T2_alignment) == 1, "record T2 wrong alignment");
_Static_assert(sizeof(struct T2_packed) == 1, "record T2 wrong sizeof");
_Static_assert(_Alignof(struct T2_packed) == 1, "record T2 wrong alignment");
_Static_assert(sizeof(struct T2_required_alignment) == 2, "record T2 wrong sizeof");
_Static_assert(_Alignof(struct T2_required_alignment) == 1, "record T2 wrong alignment");
_Static_assert(sizeof(struct T2_size) == 3, "record T2 wrong sizeof");
_Static_assert(_Alignof(struct T2_size) == 1, "record T2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(T2,x) == 0, "field T2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(T2,e) == 0, "field T2.e wrong bit offset");
#endif
_Static_assert(sizeof(U2) == 1, "record U2 wrong sizeof");
_Static_assert(_Alignof(U2) == 1, "record U2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct U2_alignment) == 2, "record U2 wrong sizeof");
_Static_assert(_Alignof(struct U2_alignment) == 1, "record U2 wrong alignment");
_Static_assert(sizeof(struct U2_packed) == 1, "record U2 wrong sizeof");
_Static_assert(_Alignof(struct U2_packed) == 1, "record U2 wrong alignment");
_Static_assert(sizeof(struct U2_required_alignment) == 2, "record U2 wrong sizeof");
_Static_assert(_Alignof(struct U2_required_alignment) == 1, "record U2 wrong alignment");
_Static_assert(sizeof(struct U2_size) == 3, "record U2 wrong sizeof");
_Static_assert(_Alignof(struct U2_size) == 1, "record U2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(U2,x) == 0, "field U2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(U2,e) == 0, "field U2.e wrong bit offset");
#endif
_Static_assert(sizeof(V2) == 1, "record V2 wrong sizeof");
_Static_assert(_Alignof(V2) == 1, "record V2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct V2_alignment) == 2, "record V2 wrong sizeof");
_Static_assert(_Alignof(struct V2_alignment) == 1, "record V2 wrong alignment");
_Static_assert(sizeof(struct V2_packed) == 1, "record V2 wrong sizeof");
_Static_assert(_Alignof(struct V2_packed) == 1, "record V2 wrong alignment");
_Static_assert(sizeof(struct V2_required_alignment) == 2, "record V2 wrong sizeof");
_Static_assert(_Alignof(struct V2_required_alignment) == 1, "record V2 wrong alignment");
_Static_assert(sizeof(struct V2_size) == 3, "record V2 wrong sizeof");
_Static_assert(_Alignof(struct V2_size) == 1, "record V2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(V2,x) == 0, "field V2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(V2,e) == 0, "field V2.e wrong bit offset");
#endif
_Static_assert(sizeof(W2) == 1, "record W2 wrong sizeof");
_Static_assert(_Alignof(W2) == 1, "record W2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct W2_alignment) == 2, "record W2 wrong sizeof");
_Static_assert(_Alignof(struct W2_alignment) == 1, "record W2 wrong alignment");
_Static_assert(sizeof(struct W2_packed) == 1, "record W2 wrong sizeof");
_Static_assert(_Alignof(struct W2_packed) == 1, "record W2 wrong alignment");
_Static_assert(sizeof(struct W2_required_alignment) == 2, "record W2 wrong sizeof");
_Static_assert(_Alignof(struct W2_required_alignment) == 1, "record W2 wrong alignment");
_Static_assert(sizeof(struct W2_size) == 3, "record W2 wrong sizeof");
_Static_assert(_Alignof(struct W2_size) == 1, "record W2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(W2,x) == 0, "field W2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(W2,e) == 0, "field W2.e wrong bit offset");
#endif
_Static_assert(sizeof(W_2) == 1, "record W_2 wrong sizeof");
_Static_assert(_Alignof(W_2) == 1, "record W_2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct W_2_alignment) == 2, "record W_2 wrong sizeof");
_Static_assert(_Alignof(struct W_2_alignment) == 1, "record W_2 wrong alignment");
_Static_assert(sizeof(struct W_2_packed) == 1, "record W_2 wrong sizeof");
_Static_assert(_Alignof(struct W_2_packed) == 1, "record W_2 wrong alignment");
_Static_assert(sizeof(struct W_2_required_alignment) == 2, "record W_2 wrong sizeof");
_Static_assert(_Alignof(struct W_2_required_alignment) == 1, "record W_2 wrong alignment");
_Static_assert(sizeof(struct W_2_size) == 3, "record W_2 wrong sizeof");
_Static_assert(_Alignof(struct W_2_size) == 1, "record W_2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(W_2,e) == 0, "field W_2.e wrong bit offset");
#endif
_Static_assert(sizeof(X2) == 1, "record X2 wrong sizeof");
_Static_assert(_Alignof(X2) == 1, "record X2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct X2_alignment) == 2, "record X2 wrong sizeof");
_Static_assert(_Alignof(struct X2_alignment) == 1, "record X2 wrong alignment");
_Static_assert(sizeof(struct X2_packed) == 1, "record X2 wrong sizeof");
_Static_assert(_Alignof(struct X2_packed) == 1, "record X2 wrong alignment");
_Static_assert(sizeof(struct X2_required_alignment) == 2, "record X2 wrong sizeof");
_Static_assert(_Alignof(struct X2_required_alignment) == 1, "record X2 wrong alignment");
_Static_assert(sizeof(struct X2_size) == 3, "record X2 wrong sizeof");
_Static_assert(_Alignof(struct X2_size) == 1, "record X2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(X2,x) == 0, "field X2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(X2,e) == 0, "field X2.e wrong bit offset");
#endif
_Static_assert(sizeof(Y) == 9, "record Y wrong sizeof");
_Static_assert(_Alignof(Y) == 1, "record Y wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Y_alignment) == 10, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_alignment) == 1, "record Y wrong alignment");
_Static_assert(sizeof(struct Y_packed) == 9, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_packed) == 1, "record Y wrong alignment");
_Static_assert(sizeof(struct Y_required_alignment) == 10, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_required_alignment) == 1, "record Y wrong alignment");
_Static_assert(sizeof(struct Y_size) == 11, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_size) == 1, "record Y wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(Y,d) == 64, "field Y.d wrong bit offset");
#endif
_Static_assert(sizeof(Y2) == 1, "record Y2 wrong sizeof");
_Static_assert(_Alignof(Y2) == 1, "record Y2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Y2_alignment) == 2, "record Y2 wrong sizeof");
_Static_assert(_Alignof(struct Y2_alignment) == 1, "record Y2 wrong alignment");
_Static_assert(sizeof(struct Y2_packed) == 1, "record Y2 wrong sizeof");
_Static_assert(_Alignof(struct Y2_packed) == 1, "record Y2 wrong alignment");
_Static_assert(sizeof(struct Y2_required_alignment) == 2, "record Y2 wrong sizeof");
_Static_assert(_Alignof(struct Y2_required_alignment) == 1, "record Y2 wrong alignment");
_Static_assert(sizeof(struct Y2_size) == 3, "record Y2 wrong sizeof");
_Static_assert(_Alignof(struct Y2_size) == 1, "record Y2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(Y2,d) == 0, "field Y2.d wrong bit offset");
#endif
_Static_assert(sizeof(A3) == 33, "record A3 wrong sizeof");
_Static_assert(_Alignof(A3) == 1, "record A3 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A3_alignment) == 34, "record A3 wrong sizeof");
_Static_assert(_Alignof(struct A3_alignment) == 1, "record A3 wrong alignment");
_Static_assert(sizeof(struct A3_packed) == 33, "record A3 wrong sizeof");
_Static_assert(_Alignof(struct A3_packed) == 1, "record A3 wrong alignment");
_Static_assert(sizeof(struct A3_required_alignment) == 34, "record A3 wrong sizeof");
_Static_assert(_Alignof(struct A3_required_alignment) == 1, "record A3 wrong alignment");
_Static_assert(sizeof(struct A3_size) == 35, "record A3 wrong sizeof");
_Static_assert(_Alignof(struct A3_size) == 1, "record A3 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A3,d) == 256, "field A3.d wrong bit offset");
#endif
_Static_assert(sizeof(A4) == 1, "record A4 wrong sizeof");
_Static_assert(_Alignof(A4) == 32, "record A4 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A4_alignment) == 64, "record A4 wrong sizeof");
_Static_assert(_Alignof(struct A4_alignment) == 32, "record A4 wrong alignment");
_Static_assert(sizeof(struct A4_packed) == 1, "record A4 wrong sizeof");
_Static_assert(_Alignof(struct A4_packed) == 1, "record A4 wrong alignment");
_Static_assert(sizeof(struct A4_required_alignment) == 2, "record A4 wrong sizeof");
_Static_assert(_Alignof(struct A4_required_alignment) == 1, "record A4 wrong alignment");
_Static_assert(sizeof(struct A4_size) == 3, "record A4 wrong sizeof");
_Static_assert(_Alignof(struct A4_size) == 1, "record A4 wrong alignment");
#endif
_Static_assert(sizeof(A5) == 33, "record A5 wrong sizeof");
_Static_assert(_Alignof(A5) == 1, "record A5 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A5_alignment) == 34, "record A5 wrong sizeof");
_Static_assert(_Alignof(struct A5_alignment) == 1, "record A5 wrong alignment");
_Static_assert(sizeof(struct A5_packed) == 33, "record A5 wrong sizeof");
_Static_assert(_Alignof(struct A5_packed) == 1, "record A5 wrong alignment");
_Static_assert(sizeof(struct A5_required_alignment) == 34, "record A5 wrong sizeof");
_Static_assert(_Alignof(struct A5_required_alignment) == 1, "record A5 wrong alignment");
_Static_assert(sizeof(struct A5_size) == 35, "record A5 wrong sizeof");
_Static_assert(_Alignof(struct A5_size) == 1, "record A5 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A5,d) == 256, "field A5.d wrong bit offset");
#endif
_Static_assert(sizeof(A7) == 32, "record A7 wrong sizeof");
_Static_assert(_Alignof(A7) == 32, "record A7 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A7_alignment) == 64, "record A7 wrong sizeof");
_Static_assert(_Alignof(struct A7_alignment) == 32, "record A7 wrong alignment");
_Static_assert(sizeof(struct A7_packed) == 32, "record A7 wrong sizeof");
_Static_assert(_Alignof(struct A7_packed) == 1, "record A7 wrong alignment");
_Static_assert(sizeof(struct A7_required_alignment) == 33, "record A7 wrong sizeof");
_Static_assert(_Alignof(struct A7_required_alignment) == 1, "record A7 wrong alignment");
_Static_assert(sizeof(struct A7_size) == 34, "record A7 wrong sizeof");
_Static_assert(_Alignof(struct A7_size) == 1, "record A7 wrong alignment");
#endif
_Static_assert(sizeof(A8) == 8, "record A8 wrong sizeof");
_Static_assert(_Alignof(A8) == 4, "record A8 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A8_alignment) == 12, "record A8 wrong sizeof");
_Static_assert(_Alignof(struct A8_alignment) == 4, "record A8 wrong alignment");
_Static_assert(sizeof(struct A8_packed) == 8, "record A8 wrong sizeof");
_Static_assert(_Alignof(struct A8_packed) == 1, "record A8 wrong alignment");
_Static_assert(sizeof(struct A8_required_alignment) == 9, "record A8 wrong sizeof");
_Static_assert(_Alignof(struct A8_required_alignment) == 1, "record A8 wrong alignment");
_Static_assert(sizeof(struct A8_size) == 10, "record A8 wrong sizeof");
_Static_assert(_Alignof(struct A8_size) == 1, "record A8 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A8,i) == 8, "field A8.i wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A8,j) == 39, "field A8.j wrong bit offset");
#endif
_Static_assert(sizeof(A9) == 12, "record A9 wrong sizeof");
_Static_assert(_Alignof(A9) == 4, "record A9 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A9_alignment) == 16, "record A9 wrong sizeof");
_Static_assert(_Alignof(struct A9_alignment) == 4, "record A9 wrong alignment");
_Static_assert(sizeof(struct A9_packed) == 12, "record A9 wrong sizeof");
_Static_assert(_Alignof(struct A9_packed) == 1, "record A9 wrong alignment");
_Static_assert(sizeof(struct A9_required_alignment) == 13, "record A9 wrong sizeof");
_Static_assert(_Alignof(struct A9_required_alignment) == 1, "record A9 wrong alignment");
_Static_assert(sizeof(struct A9_size) == 14, "record A9 wrong sizeof");
_Static_assert(_Alignof(struct A9_size) == 1, "record A9 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A9,i) == 8, "field A9.i wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A9,j) == 64, "field A9.j wrong bit offset");
#endif
_Static_assert(sizeof(A10) == 4, "record A10 wrong sizeof");
_Static_assert(_Alignof(A10) == 16, "record A10 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A10_alignment) == 32, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_alignment) == 16, "record A10 wrong alignment");
_Static_assert(sizeof(struct A10_packed) == 4, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_packed) == 1, "record A10 wrong alignment");
_Static_assert(sizeof(struct A10_required_alignment) == 5, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_required_alignment) == 1, "record A10 wrong alignment");
_Static_assert(sizeof(struct A10_size) == 6, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_size) == 1, "record A10 wrong alignment");
#endif
_Static_assert(sizeof(A11) == 32, "record A11 wrong sizeof");
_Static_assert(_Alignof(A11) == 16, "record A11 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A11_alignment) == 48, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_alignment) == 16, "record A11 wrong alignment");
_Static_assert(sizeof(struct A11_packed) == 32, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_packed) == 1, "record A11 wrong alignment");
_Static_assert(sizeof(struct A11_required_alignment) == 33, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_required_alignment) == 1, "record A11 wrong alignment");
_Static_assert(sizeof(struct A11_size) == 34, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_size) == 1, "record A11 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A11,i) == 8, "field A11.i wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A11,j) == 128, "field A11.j wrong bit offset");
#endif
_Static_assert(sizeof(A12) == 32, "record A12 wrong sizeof");
_Static_assert(_Alignof(A12) == 16, "record A12 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A12_alignment) == 48, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_alignment) == 16, "record A12 wrong alignment");
_Static_assert(sizeof(struct A12_packed) == 32, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_packed) == 1, "record A12 wrong alignment");
_Static_assert(sizeof(struct A12_required_alignment) == 33, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_required_alignment) == 1, "record A12 wrong alignment");
_Static_assert(sizeof(struct A12_size) == 34, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_size) == 1, "record A12 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A12,i) == 8, "field A12.i wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A12,j) == 128, "field A12.j wrong bit offset");
#endif
_Static_assert(sizeof(A13) == 32, "record A13 wrong sizeof");
_Static_assert(_Alignof(A13) == 16, "record A13 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A13_alignment) == 48, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_alignment) == 16, "record A13 wrong alignment");
_Static_assert(sizeof(struct A13_packed) == 32, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_packed) == 1, "record A13 wrong alignment");
_Static_assert(sizeof(struct A13_required_alignment) == 33, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_required_alignment) == 1, "record A13 wrong alignment");
_Static_assert(sizeof(struct A13_size) == 34, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_size) == 1, "record A13 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A13,i) == 8, "field A13.i wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A13,j) == 128, "field A13.j wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A13,d) == 136, "field A13.d wrong bit offset");
#endif
// MAPPING|FOURTEEN|msp430-msp430-other-none:Clang|END
// repr targets Msp430NoneElf|Some("msp430-msp430-other-none") 
#elif defined(FOURTEEN)
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
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A,d) == 0, "field A.d wrong bit offset");
#endif
_Static_assert(sizeof(A_) == 5, "record A_ wrong sizeof");
_Static_assert(_Alignof(A_) == 1, "record A_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A__alignment) == 6, "record A_ wrong sizeof");
_Static_assert(_Alignof(struct A__alignment) == 1, "record A_ wrong alignment");
_Static_assert(sizeof(struct A__packed) == 5, "record A_ wrong sizeof");
_Static_assert(_Alignof(struct A__packed) == 1, "record A_ wrong alignment");
_Static_assert(sizeof(struct A__required_alignment) == 6, "record A_ wrong sizeof");
_Static_assert(_Alignof(struct A__required_alignment) == 1, "record A_ wrong alignment");
_Static_assert(sizeof(struct A__size) == 7, "record A_ wrong sizeof");
_Static_assert(_Alignof(struct A__size) == 1, "record A_ wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_,d) == 32, "field A_.d wrong bit offset");
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
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B,d) == 0, "field B.d wrong bit offset");
#endif
_Static_assert(sizeof(B_) == 5, "record B_ wrong sizeof");
_Static_assert(_Alignof(B_) == 1, "record B_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B__alignment) == 6, "record B_ wrong sizeof");
_Static_assert(_Alignof(struct B__alignment) == 1, "record B_ wrong alignment");
_Static_assert(sizeof(struct B__packed) == 5, "record B_ wrong sizeof");
_Static_assert(_Alignof(struct B__packed) == 1, "record B_ wrong alignment");
_Static_assert(sizeof(struct B__required_alignment) == 6, "record B_ wrong sizeof");
_Static_assert(_Alignof(struct B__required_alignment) == 1, "record B_ wrong alignment");
_Static_assert(sizeof(struct B__size) == 7, "record B_ wrong sizeof");
_Static_assert(_Alignof(struct B__size) == 1, "record B_ wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B_,d) == 32, "field B_.d wrong bit offset");
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
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C,d) == 0, "field C.d wrong bit offset");
#endif
_Static_assert(sizeof(C_) == 3, "record C_ wrong sizeof");
_Static_assert(_Alignof(C_) == 1, "record C_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C__alignment) == 4, "record C_ wrong sizeof");
_Static_assert(_Alignof(struct C__alignment) == 1, "record C_ wrong alignment");
_Static_assert(sizeof(struct C__packed) == 3, "record C_ wrong sizeof");
_Static_assert(_Alignof(struct C__packed) == 1, "record C_ wrong alignment");
_Static_assert(sizeof(struct C__required_alignment) == 4, "record C_ wrong sizeof");
_Static_assert(_Alignof(struct C__required_alignment) == 1, "record C_ wrong alignment");
_Static_assert(sizeof(struct C__size) == 5, "record C_ wrong sizeof");
_Static_assert(_Alignof(struct C__size) == 1, "record C_ wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C_,d) == 16, "field C_.d wrong bit offset");
#endif
_Static_assert(sizeof(D) == 12, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 2, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 14, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 2, "record D wrong alignment");
_Static_assert(sizeof(struct D_packed) == 12, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 13, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_size) == 14, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_size) == 1, "record D wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D,d) == 16, "field D.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(D,e) == 80, "field D.e wrong bit offset");
#endif
_Static_assert(sizeof(F) == 32, "record F wrong sizeof");
_Static_assert(_Alignof(F) == 16, "record F wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 48, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_alignment) == 16, "record F wrong alignment");
_Static_assert(sizeof(struct F_packed) == 32, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_packed) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_required_alignment) == 33, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_size) == 34, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_size) == 1, "record F wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F,d) == 128, "field F.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(F,e) == 192, "field F.e wrong bit offset");
#endif
_Static_assert(sizeof(G) == 12, "record G wrong sizeof");
_Static_assert(_Alignof(G) == 2, "record G wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 14, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_alignment) == 2, "record G wrong alignment");
_Static_assert(sizeof(struct G_packed) == 12, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_packed) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_required_alignment) == 13, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_size) == 14, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_size) == 1, "record G wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(G,d) == 16, "field G.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(G,e) == 80, "field G.e wrong bit offset");
#endif
_Static_assert(sizeof(H) == 12, "record H wrong sizeof");
_Static_assert(_Alignof(H) == 2, "record H wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 14, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_alignment) == 2, "record H wrong alignment");
_Static_assert(sizeof(struct H_packed) == 12, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_packed) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_required_alignment) == 13, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_size) == 14, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_size) == 1, "record H wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(H,d) == 16, "field H.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(H,e) == 80, "field H.e wrong bit offset");
#endif
_Static_assert(sizeof(I) == 10, "record I wrong sizeof");
_Static_assert(_Alignof(I) == 1, "record I wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I_alignment) == 11, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_alignment) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_packed) == 10, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_packed) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_required_alignment) == 11, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_required_alignment) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_size) == 12, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_size) == 1, "record I wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(I,d) == 8, "field I.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(I,e) == 72, "field I.e wrong bit offset");
#endif
_Static_assert(sizeof(J) == 12, "record J wrong sizeof");
_Static_assert(_Alignof(J) == 2, "record J wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J_alignment) == 14, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_alignment) == 2, "record J wrong alignment");
_Static_assert(sizeof(struct J_packed) == 12, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_packed) == 1, "record J wrong alignment");
_Static_assert(sizeof(struct J_required_alignment) == 13, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_required_alignment) == 1, "record J wrong alignment");
_Static_assert(sizeof(struct J_size) == 14, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_size) == 1, "record J wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(J,d) == 16, "field J.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(J,e) == 80, "field J.e wrong bit offset");
#endif
_Static_assert(sizeof(K) == 4, "record K wrong sizeof");
_Static_assert(_Alignof(K) == 2, "record K wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct K_alignment) == 6, "record K wrong sizeof");
_Static_assert(_Alignof(struct K_alignment) == 2, "record K wrong alignment");
_Static_assert(sizeof(struct K_packed) == 4, "record K wrong sizeof");
_Static_assert(_Alignof(struct K_packed) == 1, "record K wrong alignment");
_Static_assert(sizeof(struct K_required_alignment) == 5, "record K wrong sizeof");
_Static_assert(_Alignof(struct K_required_alignment) == 1, "record K wrong alignment");
_Static_assert(sizeof(struct K_size) == 6, "record K wrong sizeof");
_Static_assert(_Alignof(struct K_size) == 1, "record K wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(K,d) == 8, "field K.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(K,e) == 16, "field K.e wrong bit offset");
#endif
_Static_assert(sizeof(L) == 32, "record L wrong sizeof");
_Static_assert(_Alignof(L) == 16, "record L wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct L_alignment) == 48, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_alignment) == 16, "record L wrong alignment");
_Static_assert(sizeof(struct L_packed) == 32, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_packed) == 1, "record L wrong alignment");
_Static_assert(sizeof(struct L_required_alignment) == 33, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_required_alignment) == 1, "record L wrong alignment");
_Static_assert(sizeof(struct L_size) == 34, "record L wrong sizeof");
_Static_assert(_Alignof(struct L_size) == 1, "record L wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(L,d) == 128, "field L.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(L,e) == 136, "field L.e wrong bit offset");
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
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(M,d) == 16, "field M.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(M,e) == 24, "field M.e wrong bit offset");
#endif
_Static_assert(sizeof(N) == 4, "record N wrong sizeof");
_Static_assert(_Alignof(N) == 2, "record N wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct N_alignment) == 6, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_alignment) == 2, "record N wrong alignment");
_Static_assert(sizeof(struct N_packed) == 4, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_packed) == 1, "record N wrong alignment");
_Static_assert(sizeof(struct N_required_alignment) == 5, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_required_alignment) == 1, "record N wrong alignment");
_Static_assert(sizeof(struct N_size) == 6, "record N wrong sizeof");
_Static_assert(_Alignof(struct N_size) == 1, "record N wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(N,d) == 8, "field N.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(N,e) == 16, "field N.e wrong bit offset");
#endif
_Static_assert(sizeof(O) == 3, "record O wrong sizeof");
_Static_assert(_Alignof(O) == 1, "record O wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct O_alignment) == 4, "record O wrong sizeof");
_Static_assert(_Alignof(struct O_alignment) == 1, "record O wrong alignment");
_Static_assert(sizeof(struct O_packed) == 3, "record O wrong sizeof");
_Static_assert(_Alignof(struct O_packed) == 1, "record O wrong alignment");
_Static_assert(sizeof(struct O_required_alignment) == 4, "record O wrong sizeof");
_Static_assert(_Alignof(struct O_required_alignment) == 1, "record O wrong alignment");
_Static_assert(sizeof(struct O_size) == 5, "record O wrong sizeof");
_Static_assert(_Alignof(struct O_size) == 1, "record O wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(O,d) == 8, "field O.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(O,e) == 16, "field O.e wrong bit offset");
#endif
_Static_assert(sizeof(P) == 4, "record P wrong sizeof");
_Static_assert(_Alignof(P) == 2, "record P wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct P_alignment) == 6, "record P wrong sizeof");
_Static_assert(_Alignof(struct P_alignment) == 2, "record P wrong alignment");
_Static_assert(sizeof(struct P_packed) == 4, "record P wrong sizeof");
_Static_assert(_Alignof(struct P_packed) == 1, "record P wrong alignment");
_Static_assert(sizeof(struct P_required_alignment) == 5, "record P wrong sizeof");
_Static_assert(_Alignof(struct P_required_alignment) == 1, "record P wrong alignment");
_Static_assert(sizeof(struct P_size) == 6, "record P wrong sizeof");
_Static_assert(_Alignof(struct P_size) == 1, "record P wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(P,d) == 8, "field P.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(P,e) == 16, "field P.e wrong bit offset");
#endif
_Static_assert(sizeof(Q) == 4, "record Q wrong sizeof");
_Static_assert(_Alignof(Q) == 2, "record Q wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Q_alignment) == 6, "record Q wrong sizeof");
_Static_assert(_Alignof(struct Q_alignment) == 2, "record Q wrong alignment");
_Static_assert(sizeof(struct Q_packed) == 4, "record Q wrong sizeof");
_Static_assert(_Alignof(struct Q_packed) == 1, "record Q wrong alignment");
_Static_assert(sizeof(struct Q_required_alignment) == 5, "record Q wrong sizeof");
_Static_assert(_Alignof(struct Q_required_alignment) == 1, "record Q wrong alignment");
_Static_assert(sizeof(struct Q_size) == 6, "record Q wrong sizeof");
_Static_assert(_Alignof(struct Q_size) == 1, "record Q wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(Q,x) == 8, "field Q.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(Q,d) == 9, "field Q.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(Q,e) == 16, "field Q.e wrong bit offset");
#endif
_Static_assert(sizeof(R) == 17, "record R wrong sizeof");
_Static_assert(_Alignof(R) == 1, "record R wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct R_alignment) == 18, "record R wrong sizeof");
_Static_assert(_Alignof(struct R_alignment) == 1, "record R wrong alignment");
_Static_assert(sizeof(struct R_packed) == 17, "record R wrong sizeof");
_Static_assert(_Alignof(struct R_packed) == 1, "record R wrong alignment");
_Static_assert(sizeof(struct R_required_alignment) == 18, "record R wrong sizeof");
_Static_assert(_Alignof(struct R_required_alignment) == 1, "record R wrong alignment");
_Static_assert(sizeof(struct R_size) == 19, "record R wrong sizeof");
_Static_assert(_Alignof(struct R_size) == 1, "record R wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(R,x) == 8, "field R.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(R,e) == 128, "field R.e wrong bit offset");
#endif
_Static_assert(sizeof(S) == 3, "record S wrong sizeof");
_Static_assert(_Alignof(S) == 1, "record S wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct S_alignment) == 4, "record S wrong sizeof");
_Static_assert(_Alignof(struct S_alignment) == 1, "record S wrong alignment");
_Static_assert(sizeof(struct S_packed) == 3, "record S wrong sizeof");
_Static_assert(_Alignof(struct S_packed) == 1, "record S wrong alignment");
_Static_assert(sizeof(struct S_required_alignment) == 4, "record S wrong sizeof");
_Static_assert(_Alignof(struct S_required_alignment) == 1, "record S wrong alignment");
_Static_assert(sizeof(struct S_size) == 5, "record S wrong sizeof");
_Static_assert(_Alignof(struct S_size) == 1, "record S wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(S,x) == 8, "field S.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(S,e) == 16, "field S.e wrong bit offset");
#endif
_Static_assert(sizeof(T) == 5, "record T wrong sizeof");
_Static_assert(_Alignof(T) == 1, "record T wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct T_alignment) == 6, "record T wrong sizeof");
_Static_assert(_Alignof(struct T_alignment) == 1, "record T wrong alignment");
_Static_assert(sizeof(struct T_packed) == 5, "record T wrong sizeof");
_Static_assert(_Alignof(struct T_packed) == 1, "record T wrong alignment");
_Static_assert(sizeof(struct T_required_alignment) == 6, "record T wrong sizeof");
_Static_assert(_Alignof(struct T_required_alignment) == 1, "record T wrong alignment");
_Static_assert(sizeof(struct T_size) == 7, "record T wrong sizeof");
_Static_assert(_Alignof(struct T_size) == 1, "record T wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(T,x) == 8, "field T.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(T,e) == 32, "field T.e wrong bit offset");
#endif
_Static_assert(sizeof(U) == 3, "record U wrong sizeof");
_Static_assert(_Alignof(U) == 1, "record U wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct U_alignment) == 4, "record U wrong sizeof");
_Static_assert(_Alignof(struct U_alignment) == 1, "record U wrong alignment");
_Static_assert(sizeof(struct U_packed) == 3, "record U wrong sizeof");
_Static_assert(_Alignof(struct U_packed) == 1, "record U wrong alignment");
_Static_assert(sizeof(struct U_required_alignment) == 4, "record U wrong sizeof");
_Static_assert(_Alignof(struct U_required_alignment) == 1, "record U wrong alignment");
_Static_assert(sizeof(struct U_size) == 5, "record U wrong sizeof");
_Static_assert(_Alignof(struct U_size) == 1, "record U wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(U,x) == 8, "field U.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(U,e) == 16, "field U.e wrong bit offset");
#endif
_Static_assert(sizeof(V) == 3, "record V wrong sizeof");
_Static_assert(_Alignof(V) == 1, "record V wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct V_alignment) == 4, "record V wrong sizeof");
_Static_assert(_Alignof(struct V_alignment) == 1, "record V wrong alignment");
_Static_assert(sizeof(struct V_packed) == 3, "record V wrong sizeof");
_Static_assert(_Alignof(struct V_packed) == 1, "record V wrong alignment");
_Static_assert(sizeof(struct V_required_alignment) == 4, "record V wrong sizeof");
_Static_assert(_Alignof(struct V_required_alignment) == 1, "record V wrong alignment");
_Static_assert(sizeof(struct V_size) == 5, "record V wrong sizeof");
_Static_assert(_Alignof(struct V_size) == 1, "record V wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(V,x) == 8, "field V.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(V,e) == 16, "field V.e wrong bit offset");
#endif
_Static_assert(sizeof(W) == 17, "record W wrong sizeof");
_Static_assert(_Alignof(W) == 1, "record W wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct W_alignment) == 18, "record W wrong sizeof");
_Static_assert(_Alignof(struct W_alignment) == 1, "record W wrong alignment");
_Static_assert(sizeof(struct W_packed) == 17, "record W wrong sizeof");
_Static_assert(_Alignof(struct W_packed) == 1, "record W wrong alignment");
_Static_assert(sizeof(struct W_required_alignment) == 18, "record W wrong sizeof");
_Static_assert(_Alignof(struct W_required_alignment) == 1, "record W wrong alignment");
_Static_assert(sizeof(struct W_size) == 19, "record W wrong sizeof");
_Static_assert(_Alignof(struct W_size) == 1, "record W wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(W,x) == 8, "field W.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(W,e) == 128, "field W.e wrong bit offset");
#endif
_Static_assert(sizeof(W_) == 17, "record W_ wrong sizeof");
_Static_assert(_Alignof(W_) == 1, "record W_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct W__alignment) == 18, "record W_ wrong sizeof");
_Static_assert(_Alignof(struct W__alignment) == 1, "record W_ wrong alignment");
_Static_assert(sizeof(struct W__packed) == 17, "record W_ wrong sizeof");
_Static_assert(_Alignof(struct W__packed) == 1, "record W_ wrong alignment");
_Static_assert(sizeof(struct W__required_alignment) == 18, "record W_ wrong sizeof");
_Static_assert(_Alignof(struct W__required_alignment) == 1, "record W_ wrong alignment");
_Static_assert(sizeof(struct W__size) == 19, "record W_ wrong sizeof");
_Static_assert(_Alignof(struct W__size) == 1, "record W_ wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(W_,e) == 128, "field W_.e wrong bit offset");
#endif
_Static_assert(sizeof(X) == 17, "record X wrong sizeof");
_Static_assert(_Alignof(X) == 1, "record X wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct X_alignment) == 18, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_alignment) == 1, "record X wrong alignment");
_Static_assert(sizeof(struct X_packed) == 17, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_packed) == 1, "record X wrong alignment");
_Static_assert(sizeof(struct X_required_alignment) == 18, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_required_alignment) == 1, "record X wrong alignment");
_Static_assert(sizeof(struct X_size) == 19, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_size) == 1, "record X wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(X,x) == 8, "field X.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(X,e) == 128, "field X.e wrong bit offset");
#endif
_Static_assert(sizeof(A2) == 1, "record A2 wrong sizeof");
_Static_assert(_Alignof(A2) == 1, "record A2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A2_alignment) == 2, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_alignment) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_packed) == 1, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_packed) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_required_alignment) == 2, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_required_alignment) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_size) == 3, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_size) == 1, "record A2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A2,d) == 0, "field A2.d wrong bit offset");
#endif
_Static_assert(sizeof(A_2) == 1, "record A_2 wrong sizeof");
_Static_assert(_Alignof(A_2) == 1, "record A_2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_2_alignment) == 2, "record A_2 wrong sizeof");
_Static_assert(_Alignof(struct A_2_alignment) == 1, "record A_2 wrong alignment");
_Static_assert(sizeof(struct A_2_packed) == 1, "record A_2 wrong sizeof");
_Static_assert(_Alignof(struct A_2_packed) == 1, "record A_2 wrong alignment");
_Static_assert(sizeof(struct A_2_required_alignment) == 2, "record A_2 wrong sizeof");
_Static_assert(_Alignof(struct A_2_required_alignment) == 1, "record A_2 wrong alignment");
_Static_assert(sizeof(struct A_2_size) == 3, "record A_2 wrong sizeof");
_Static_assert(_Alignof(struct A_2_size) == 1, "record A_2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_2,d) == 0, "field A_2.d wrong bit offset");
#endif
_Static_assert(sizeof(B2) == 1, "record B2 wrong sizeof");
_Static_assert(_Alignof(B2) == 1, "record B2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B2_alignment) == 2, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_alignment) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_packed) == 1, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_packed) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_required_alignment) == 2, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_required_alignment) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_size) == 3, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_size) == 1, "record B2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B2,d) == 0, "field B2.d wrong bit offset");
#endif
_Static_assert(sizeof(B_2) == 1, "record B_2 wrong sizeof");
_Static_assert(_Alignof(B_2) == 1, "record B_2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_2_alignment) == 2, "record B_2 wrong sizeof");
_Static_assert(_Alignof(struct B_2_alignment) == 1, "record B_2 wrong alignment");
_Static_assert(sizeof(struct B_2_packed) == 1, "record B_2 wrong sizeof");
_Static_assert(_Alignof(struct B_2_packed) == 1, "record B_2 wrong alignment");
_Static_assert(sizeof(struct B_2_required_alignment) == 2, "record B_2 wrong sizeof");
_Static_assert(_Alignof(struct B_2_required_alignment) == 1, "record B_2 wrong alignment");
_Static_assert(sizeof(struct B_2_size) == 3, "record B_2 wrong sizeof");
_Static_assert(_Alignof(struct B_2_size) == 1, "record B_2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B_2,d) == 0, "field B_2.d wrong bit offset");
#endif
_Static_assert(sizeof(C2) == 1, "record C2 wrong sizeof");
_Static_assert(_Alignof(C2) == 1, "record C2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C2_alignment) == 2, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_alignment) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_packed) == 1, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_packed) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_required_alignment) == 2, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_required_alignment) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_size) == 3, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_size) == 1, "record C2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C2,d) == 0, "field C2.d wrong bit offset");
#endif
_Static_assert(sizeof(C22) == 1, "record C22 wrong sizeof");
_Static_assert(_Alignof(C22) == 1, "record C22 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C22_alignment) == 2, "record C22 wrong sizeof");
_Static_assert(_Alignof(struct C22_alignment) == 1, "record C22 wrong alignment");
_Static_assert(sizeof(struct C22_packed) == 1, "record C22 wrong sizeof");
_Static_assert(_Alignof(struct C22_packed) == 1, "record C22 wrong alignment");
_Static_assert(sizeof(struct C22_required_alignment) == 2, "record C22 wrong sizeof");
_Static_assert(_Alignof(struct C22_required_alignment) == 1, "record C22 wrong alignment");
_Static_assert(sizeof(struct C22_size) == 3, "record C22 wrong sizeof");
_Static_assert(_Alignof(struct C22_size) == 1, "record C22 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C22,d) == 0, "field C22.d wrong bit offset");
#endif
_Static_assert(sizeof(D2) == 8, "record D2 wrong sizeof");
_Static_assert(_Alignof(D2) == 2, "record D2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D2_alignment) == 10, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_alignment) == 2, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_packed) == 8, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_packed) == 1, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_required_alignment) == 9, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_required_alignment) == 1, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_size) == 10, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_size) == 1, "record D2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D2,d) == 0, "field D2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(D2,e) == 0, "field D2.e wrong bit offset");
#endif
_Static_assert(sizeof(F2) == 16, "record F2 wrong sizeof");
_Static_assert(_Alignof(F2) == 16, "record F2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F2_alignment) == 32, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_alignment) == 16, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_packed) == 16, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_packed) == 1, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_required_alignment) == 17, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_required_alignment) == 1, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_size) == 18, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_size) == 1, "record F2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F2,d) == 0, "field F2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(F2,e) == 0, "field F2.e wrong bit offset");
#endif
_Static_assert(sizeof(G2) == 8, "record G2 wrong sizeof");
_Static_assert(_Alignof(G2) == 2, "record G2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G2_alignment) == 10, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_alignment) == 2, "record G2 wrong alignment");
_Static_assert(sizeof(struct G2_packed) == 8, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_packed) == 1, "record G2 wrong alignment");
_Static_assert(sizeof(struct G2_required_alignment) == 9, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_required_alignment) == 1, "record G2 wrong alignment");
_Static_assert(sizeof(struct G2_size) == 10, "record G2 wrong sizeof");
_Static_assert(_Alignof(struct G2_size) == 1, "record G2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(G2,d) == 0, "field G2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(G2,e) == 0, "field G2.e wrong bit offset");
#endif
_Static_assert(sizeof(H2) == 8, "record H2 wrong sizeof");
_Static_assert(_Alignof(H2) == 2, "record H2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H2_alignment) == 10, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_alignment) == 2, "record H2 wrong alignment");
_Static_assert(sizeof(struct H2_packed) == 8, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_packed) == 1, "record H2 wrong alignment");
_Static_assert(sizeof(struct H2_required_alignment) == 9, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_required_alignment) == 1, "record H2 wrong alignment");
_Static_assert(sizeof(struct H2_size) == 10, "record H2 wrong sizeof");
_Static_assert(_Alignof(struct H2_size) == 1, "record H2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(H2,d) == 0, "field H2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(H2,e) == 0, "field H2.e wrong bit offset");
#endif
_Static_assert(sizeof(I2) == 8, "record I2 wrong sizeof");
_Static_assert(_Alignof(I2) == 1, "record I2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I2_alignment) == 9, "record I2 wrong sizeof");
_Static_assert(_Alignof(struct I2_alignment) == 1, "record I2 wrong alignment");
_Static_assert(sizeof(struct I2_packed) == 8, "record I2 wrong sizeof");
_Static_assert(_Alignof(struct I2_packed) == 1, "record I2 wrong alignment");
_Static_assert(sizeof(struct I2_required_alignment) == 9, "record I2 wrong sizeof");
_Static_assert(_Alignof(struct I2_required_alignment) == 1, "record I2 wrong alignment");
_Static_assert(sizeof(struct I2_size) == 10, "record I2 wrong sizeof");
_Static_assert(_Alignof(struct I2_size) == 1, "record I2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(I2,d) == 0, "field I2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(I2,e) == 0, "field I2.e wrong bit offset");
#endif
_Static_assert(sizeof(J2) == 8, "record J2 wrong sizeof");
_Static_assert(_Alignof(J2) == 2, "record J2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J2_alignment) == 10, "record J2 wrong sizeof");
_Static_assert(_Alignof(struct J2_alignment) == 2, "record J2 wrong alignment");
_Static_assert(sizeof(struct J2_packed) == 8, "record J2 wrong sizeof");
_Static_assert(_Alignof(struct J2_packed) == 1, "record J2 wrong alignment");
_Static_assert(sizeof(struct J2_required_alignment) == 9, "record J2 wrong sizeof");
_Static_assert(_Alignof(struct J2_required_alignment) == 1, "record J2 wrong alignment");
_Static_assert(sizeof(struct J2_size) == 10, "record J2 wrong sizeof");
_Static_assert(_Alignof(struct J2_size) == 1, "record J2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(J2,d) == 0, "field J2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(J2,e) == 0, "field J2.e wrong bit offset");
#endif
_Static_assert(sizeof(K2) == 2, "record K2 wrong sizeof");
_Static_assert(_Alignof(K2) == 2, "record K2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct K2_alignment) == 4, "record K2 wrong sizeof");
_Static_assert(_Alignof(struct K2_alignment) == 2, "record K2 wrong alignment");
_Static_assert(sizeof(struct K2_packed) == 2, "record K2 wrong sizeof");
_Static_assert(_Alignof(struct K2_packed) == 1, "record K2 wrong alignment");
_Static_assert(sizeof(struct K2_required_alignment) == 3, "record K2 wrong sizeof");
_Static_assert(_Alignof(struct K2_required_alignment) == 1, "record K2 wrong alignment");
_Static_assert(sizeof(struct K2_size) == 4, "record K2 wrong sizeof");
_Static_assert(_Alignof(struct K2_size) == 1, "record K2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(K2,d) == 0, "field K2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(K2,e) == 0, "field K2.e wrong bit offset");
#endif
_Static_assert(sizeof(L2) == 16, "record L2 wrong sizeof");
_Static_assert(_Alignof(L2) == 16, "record L2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct L2_alignment) == 32, "record L2 wrong sizeof");
_Static_assert(_Alignof(struct L2_alignment) == 16, "record L2 wrong alignment");
_Static_assert(sizeof(struct L2_packed) == 16, "record L2 wrong sizeof");
_Static_assert(_Alignof(struct L2_packed) == 1, "record L2 wrong alignment");
_Static_assert(sizeof(struct L2_required_alignment) == 17, "record L2 wrong sizeof");
_Static_assert(_Alignof(struct L2_required_alignment) == 1, "record L2 wrong alignment");
_Static_assert(sizeof(struct L2_size) == 18, "record L2 wrong sizeof");
_Static_assert(_Alignof(struct L2_size) == 1, "record L2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(L2,d) == 0, "field L2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(L2,e) == 0, "field L2.e wrong bit offset");
#endif
_Static_assert(sizeof(M2) == 2, "record M2 wrong sizeof");
_Static_assert(_Alignof(M2) == 2, "record M2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct M2_alignment) == 4, "record M2 wrong sizeof");
_Static_assert(_Alignof(struct M2_alignment) == 2, "record M2 wrong alignment");
_Static_assert(sizeof(struct M2_packed) == 2, "record M2 wrong sizeof");
_Static_assert(_Alignof(struct M2_packed) == 1, "record M2 wrong alignment");
_Static_assert(sizeof(struct M2_required_alignment) == 3, "record M2 wrong sizeof");
_Static_assert(_Alignof(struct M2_required_alignment) == 1, "record M2 wrong alignment");
_Static_assert(sizeof(struct M2_size) == 4, "record M2 wrong sizeof");
_Static_assert(_Alignof(struct M2_size) == 1, "record M2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(M2,d) == 0, "field M2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(M2,e) == 0, "field M2.e wrong bit offset");
#endif
_Static_assert(sizeof(N2) == 2, "record N2 wrong sizeof");
_Static_assert(_Alignof(N2) == 2, "record N2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct N2_alignment) == 4, "record N2 wrong sizeof");
_Static_assert(_Alignof(struct N2_alignment) == 2, "record N2 wrong alignment");
_Static_assert(sizeof(struct N2_packed) == 2, "record N2 wrong sizeof");
_Static_assert(_Alignof(struct N2_packed) == 1, "record N2 wrong alignment");
_Static_assert(sizeof(struct N2_required_alignment) == 3, "record N2 wrong sizeof");
_Static_assert(_Alignof(struct N2_required_alignment) == 1, "record N2 wrong alignment");
_Static_assert(sizeof(struct N2_size) == 4, "record N2 wrong sizeof");
_Static_assert(_Alignof(struct N2_size) == 1, "record N2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(N2,d) == 0, "field N2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(N2,e) == 0, "field N2.e wrong bit offset");
#endif
_Static_assert(sizeof(O2) == 1, "record O2 wrong sizeof");
_Static_assert(_Alignof(O2) == 1, "record O2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct O2_alignment) == 2, "record O2 wrong sizeof");
_Static_assert(_Alignof(struct O2_alignment) == 1, "record O2 wrong alignment");
_Static_assert(sizeof(struct O2_packed) == 1, "record O2 wrong sizeof");
_Static_assert(_Alignof(struct O2_packed) == 1, "record O2 wrong alignment");
_Static_assert(sizeof(struct O2_required_alignment) == 2, "record O2 wrong sizeof");
_Static_assert(_Alignof(struct O2_required_alignment) == 1, "record O2 wrong alignment");
_Static_assert(sizeof(struct O2_size) == 3, "record O2 wrong sizeof");
_Static_assert(_Alignof(struct O2_size) == 1, "record O2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(O2,d) == 0, "field O2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(O2,e) == 0, "field O2.e wrong bit offset");
#endif
_Static_assert(sizeof(P2) == 2, "record P2 wrong sizeof");
_Static_assert(_Alignof(P2) == 2, "record P2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct P2_alignment) == 4, "record P2 wrong sizeof");
_Static_assert(_Alignof(struct P2_alignment) == 2, "record P2 wrong alignment");
_Static_assert(sizeof(struct P2_packed) == 2, "record P2 wrong sizeof");
_Static_assert(_Alignof(struct P2_packed) == 1, "record P2 wrong alignment");
_Static_assert(sizeof(struct P2_required_alignment) == 3, "record P2 wrong sizeof");
_Static_assert(_Alignof(struct P2_required_alignment) == 1, "record P2 wrong alignment");
_Static_assert(sizeof(struct P2_size) == 4, "record P2 wrong sizeof");
_Static_assert(_Alignof(struct P2_size) == 1, "record P2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(P2,d) == 0, "field P2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(P2,e) == 0, "field P2.e wrong bit offset");
#endif
_Static_assert(sizeof(Q2) == 2, "record Q2 wrong sizeof");
_Static_assert(_Alignof(Q2) == 2, "record Q2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Q2_alignment) == 4, "record Q2 wrong sizeof");
_Static_assert(_Alignof(struct Q2_alignment) == 2, "record Q2 wrong alignment");
_Static_assert(sizeof(struct Q2_packed) == 2, "record Q2 wrong sizeof");
_Static_assert(_Alignof(struct Q2_packed) == 1, "record Q2 wrong alignment");
_Static_assert(sizeof(struct Q2_required_alignment) == 3, "record Q2 wrong sizeof");
_Static_assert(_Alignof(struct Q2_required_alignment) == 1, "record Q2 wrong alignment");
_Static_assert(sizeof(struct Q2_size) == 4, "record Q2 wrong sizeof");
_Static_assert(_Alignof(struct Q2_size) == 1, "record Q2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(Q2,x) == 0, "field Q2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(Q2,d) == 0, "field Q2.d wrong bit offset");
_Static_assert(__builtin_bitoffsetof(Q2,e) == 0, "field Q2.e wrong bit offset");
#endif
_Static_assert(sizeof(R2) == 1, "record R2 wrong sizeof");
_Static_assert(_Alignof(R2) == 1, "record R2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct R2_alignment) == 2, "record R2 wrong sizeof");
_Static_assert(_Alignof(struct R2_alignment) == 1, "record R2 wrong alignment");
_Static_assert(sizeof(struct R2_packed) == 1, "record R2 wrong sizeof");
_Static_assert(_Alignof(struct R2_packed) == 1, "record R2 wrong alignment");
_Static_assert(sizeof(struct R2_required_alignment) == 2, "record R2 wrong sizeof");
_Static_assert(_Alignof(struct R2_required_alignment) == 1, "record R2 wrong alignment");
_Static_assert(sizeof(struct R2_size) == 3, "record R2 wrong sizeof");
_Static_assert(_Alignof(struct R2_size) == 1, "record R2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(R2,x) == 0, "field R2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(R2,e) == 0, "field R2.e wrong bit offset");
#endif
_Static_assert(sizeof(S2) == 1, "record S2 wrong sizeof");
_Static_assert(_Alignof(S2) == 1, "record S2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct S2_alignment) == 2, "record S2 wrong sizeof");
_Static_assert(_Alignof(struct S2_alignment) == 1, "record S2 wrong alignment");
_Static_assert(sizeof(struct S2_packed) == 1, "record S2 wrong sizeof");
_Static_assert(_Alignof(struct S2_packed) == 1, "record S2 wrong alignment");
_Static_assert(sizeof(struct S2_required_alignment) == 2, "record S2 wrong sizeof");
_Static_assert(_Alignof(struct S2_required_alignment) == 1, "record S2 wrong alignment");
_Static_assert(sizeof(struct S2_size) == 3, "record S2 wrong sizeof");
_Static_assert(_Alignof(struct S2_size) == 1, "record S2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(S2,x) == 0, "field S2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(S2,e) == 0, "field S2.e wrong bit offset");
#endif
_Static_assert(sizeof(T2) == 1, "record T2 wrong sizeof");
_Static_assert(_Alignof(T2) == 1, "record T2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct T2_alignment) == 2, "record T2 wrong sizeof");
_Static_assert(_Alignof(struct T2_alignment) == 1, "record T2 wrong alignment");
_Static_assert(sizeof(struct T2_packed) == 1, "record T2 wrong sizeof");
_Static_assert(_Alignof(struct T2_packed) == 1, "record T2 wrong alignment");
_Static_assert(sizeof(struct T2_required_alignment) == 2, "record T2 wrong sizeof");
_Static_assert(_Alignof(struct T2_required_alignment) == 1, "record T2 wrong alignment");
_Static_assert(sizeof(struct T2_size) == 3, "record T2 wrong sizeof");
_Static_assert(_Alignof(struct T2_size) == 1, "record T2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(T2,x) == 0, "field T2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(T2,e) == 0, "field T2.e wrong bit offset");
#endif
_Static_assert(sizeof(U2) == 1, "record U2 wrong sizeof");
_Static_assert(_Alignof(U2) == 1, "record U2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct U2_alignment) == 2, "record U2 wrong sizeof");
_Static_assert(_Alignof(struct U2_alignment) == 1, "record U2 wrong alignment");
_Static_assert(sizeof(struct U2_packed) == 1, "record U2 wrong sizeof");
_Static_assert(_Alignof(struct U2_packed) == 1, "record U2 wrong alignment");
_Static_assert(sizeof(struct U2_required_alignment) == 2, "record U2 wrong sizeof");
_Static_assert(_Alignof(struct U2_required_alignment) == 1, "record U2 wrong alignment");
_Static_assert(sizeof(struct U2_size) == 3, "record U2 wrong sizeof");
_Static_assert(_Alignof(struct U2_size) == 1, "record U2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(U2,x) == 0, "field U2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(U2,e) == 0, "field U2.e wrong bit offset");
#endif
_Static_assert(sizeof(V2) == 1, "record V2 wrong sizeof");
_Static_assert(_Alignof(V2) == 1, "record V2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct V2_alignment) == 2, "record V2 wrong sizeof");
_Static_assert(_Alignof(struct V2_alignment) == 1, "record V2 wrong alignment");
_Static_assert(sizeof(struct V2_packed) == 1, "record V2 wrong sizeof");
_Static_assert(_Alignof(struct V2_packed) == 1, "record V2 wrong alignment");
_Static_assert(sizeof(struct V2_required_alignment) == 2, "record V2 wrong sizeof");
_Static_assert(_Alignof(struct V2_required_alignment) == 1, "record V2 wrong alignment");
_Static_assert(sizeof(struct V2_size) == 3, "record V2 wrong sizeof");
_Static_assert(_Alignof(struct V2_size) == 1, "record V2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(V2,x) == 0, "field V2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(V2,e) == 0, "field V2.e wrong bit offset");
#endif
_Static_assert(sizeof(W2) == 1, "record W2 wrong sizeof");
_Static_assert(_Alignof(W2) == 1, "record W2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct W2_alignment) == 2, "record W2 wrong sizeof");
_Static_assert(_Alignof(struct W2_alignment) == 1, "record W2 wrong alignment");
_Static_assert(sizeof(struct W2_packed) == 1, "record W2 wrong sizeof");
_Static_assert(_Alignof(struct W2_packed) == 1, "record W2 wrong alignment");
_Static_assert(sizeof(struct W2_required_alignment) == 2, "record W2 wrong sizeof");
_Static_assert(_Alignof(struct W2_required_alignment) == 1, "record W2 wrong alignment");
_Static_assert(sizeof(struct W2_size) == 3, "record W2 wrong sizeof");
_Static_assert(_Alignof(struct W2_size) == 1, "record W2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(W2,x) == 0, "field W2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(W2,e) == 0, "field W2.e wrong bit offset");
#endif
_Static_assert(sizeof(W_2) == 1, "record W_2 wrong sizeof");
_Static_assert(_Alignof(W_2) == 1, "record W_2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct W_2_alignment) == 2, "record W_2 wrong sizeof");
_Static_assert(_Alignof(struct W_2_alignment) == 1, "record W_2 wrong alignment");
_Static_assert(sizeof(struct W_2_packed) == 1, "record W_2 wrong sizeof");
_Static_assert(_Alignof(struct W_2_packed) == 1, "record W_2 wrong alignment");
_Static_assert(sizeof(struct W_2_required_alignment) == 2, "record W_2 wrong sizeof");
_Static_assert(_Alignof(struct W_2_required_alignment) == 1, "record W_2 wrong alignment");
_Static_assert(sizeof(struct W_2_size) == 3, "record W_2 wrong sizeof");
_Static_assert(_Alignof(struct W_2_size) == 1, "record W_2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(W_2,e) == 0, "field W_2.e wrong bit offset");
#endif
_Static_assert(sizeof(X2) == 1, "record X2 wrong sizeof");
_Static_assert(_Alignof(X2) == 1, "record X2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct X2_alignment) == 2, "record X2 wrong sizeof");
_Static_assert(_Alignof(struct X2_alignment) == 1, "record X2 wrong alignment");
_Static_assert(sizeof(struct X2_packed) == 1, "record X2 wrong sizeof");
_Static_assert(_Alignof(struct X2_packed) == 1, "record X2 wrong alignment");
_Static_assert(sizeof(struct X2_required_alignment) == 2, "record X2 wrong sizeof");
_Static_assert(_Alignof(struct X2_required_alignment) == 1, "record X2 wrong alignment");
_Static_assert(sizeof(struct X2_size) == 3, "record X2 wrong sizeof");
_Static_assert(_Alignof(struct X2_size) == 1, "record X2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(X2,x) == 0, "field X2.x wrong bit offset");
_Static_assert(__builtin_bitoffsetof(X2,e) == 0, "field X2.e wrong bit offset");
#endif
_Static_assert(sizeof(Y) == 3, "record Y wrong sizeof");
_Static_assert(_Alignof(Y) == 1, "record Y wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Y_alignment) == 4, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_alignment) == 1, "record Y wrong alignment");
_Static_assert(sizeof(struct Y_packed) == 3, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_packed) == 1, "record Y wrong alignment");
_Static_assert(sizeof(struct Y_required_alignment) == 4, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_required_alignment) == 1, "record Y wrong alignment");
_Static_assert(sizeof(struct Y_size) == 5, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_size) == 1, "record Y wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(Y,d) == 16, "field Y.d wrong bit offset");
#endif
_Static_assert(sizeof(Y2) == 1, "record Y2 wrong sizeof");
_Static_assert(_Alignof(Y2) == 1, "record Y2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Y2_alignment) == 2, "record Y2 wrong sizeof");
_Static_assert(_Alignof(struct Y2_alignment) == 1, "record Y2 wrong alignment");
_Static_assert(sizeof(struct Y2_packed) == 1, "record Y2 wrong sizeof");
_Static_assert(_Alignof(struct Y2_packed) == 1, "record Y2 wrong alignment");
_Static_assert(sizeof(struct Y2_required_alignment) == 2, "record Y2 wrong sizeof");
_Static_assert(_Alignof(struct Y2_required_alignment) == 1, "record Y2 wrong alignment");
_Static_assert(sizeof(struct Y2_size) == 3, "record Y2 wrong sizeof");
_Static_assert(_Alignof(struct Y2_size) == 1, "record Y2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(Y2,d) == 0, "field Y2.d wrong bit offset");
#endif
_Static_assert(sizeof(A3) == 33, "record A3 wrong sizeof");
_Static_assert(_Alignof(A3) == 1, "record A3 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A3_alignment) == 34, "record A3 wrong sizeof");
_Static_assert(_Alignof(struct A3_alignment) == 1, "record A3 wrong alignment");
_Static_assert(sizeof(struct A3_packed) == 33, "record A3 wrong sizeof");
_Static_assert(_Alignof(struct A3_packed) == 1, "record A3 wrong alignment");
_Static_assert(sizeof(struct A3_required_alignment) == 34, "record A3 wrong sizeof");
_Static_assert(_Alignof(struct A3_required_alignment) == 1, "record A3 wrong alignment");
_Static_assert(sizeof(struct A3_size) == 35, "record A3 wrong sizeof");
_Static_assert(_Alignof(struct A3_size) == 1, "record A3 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A3,d) == 256, "field A3.d wrong bit offset");
#endif
_Static_assert(sizeof(A4) == 1, "record A4 wrong sizeof");
_Static_assert(_Alignof(A4) == 32, "record A4 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A4_alignment) == 64, "record A4 wrong sizeof");
_Static_assert(_Alignof(struct A4_alignment) == 32, "record A4 wrong alignment");
_Static_assert(sizeof(struct A4_packed) == 1, "record A4 wrong sizeof");
_Static_assert(_Alignof(struct A4_packed) == 1, "record A4 wrong alignment");
_Static_assert(sizeof(struct A4_required_alignment) == 2, "record A4 wrong sizeof");
_Static_assert(_Alignof(struct A4_required_alignment) == 1, "record A4 wrong alignment");
_Static_assert(sizeof(struct A4_size) == 3, "record A4 wrong sizeof");
_Static_assert(_Alignof(struct A4_size) == 1, "record A4 wrong alignment");
#endif
_Static_assert(sizeof(A5) == 33, "record A5 wrong sizeof");
_Static_assert(_Alignof(A5) == 1, "record A5 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A5_alignment) == 34, "record A5 wrong sizeof");
_Static_assert(_Alignof(struct A5_alignment) == 1, "record A5 wrong alignment");
_Static_assert(sizeof(struct A5_packed) == 33, "record A5 wrong sizeof");
_Static_assert(_Alignof(struct A5_packed) == 1, "record A5 wrong alignment");
_Static_assert(sizeof(struct A5_required_alignment) == 34, "record A5 wrong sizeof");
_Static_assert(_Alignof(struct A5_required_alignment) == 1, "record A5 wrong alignment");
_Static_assert(sizeof(struct A5_size) == 35, "record A5 wrong sizeof");
_Static_assert(_Alignof(struct A5_size) == 1, "record A5 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A5,d) == 256, "field A5.d wrong bit offset");
#endif
_Static_assert(sizeof(A7) == 32, "record A7 wrong sizeof");
_Static_assert(_Alignof(A7) == 32, "record A7 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A7_alignment) == 64, "record A7 wrong sizeof");
_Static_assert(_Alignof(struct A7_alignment) == 32, "record A7 wrong alignment");
_Static_assert(sizeof(struct A7_packed) == 32, "record A7 wrong sizeof");
_Static_assert(_Alignof(struct A7_packed) == 1, "record A7 wrong alignment");
_Static_assert(sizeof(struct A7_required_alignment) == 33, "record A7 wrong sizeof");
_Static_assert(_Alignof(struct A7_required_alignment) == 1, "record A7 wrong alignment");
_Static_assert(sizeof(struct A7_size) == 34, "record A7 wrong sizeof");
_Static_assert(_Alignof(struct A7_size) == 1, "record A7 wrong alignment");
#endif
_Static_assert(sizeof(A8) == 6, "record A8 wrong sizeof");
_Static_assert(_Alignof(A8) == 2, "record A8 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A8_alignment) == 8, "record A8 wrong sizeof");
_Static_assert(_Alignof(struct A8_alignment) == 2, "record A8 wrong alignment");
_Static_assert(sizeof(struct A8_packed) == 6, "record A8 wrong sizeof");
_Static_assert(_Alignof(struct A8_packed) == 1, "record A8 wrong alignment");
_Static_assert(sizeof(struct A8_required_alignment) == 7, "record A8 wrong sizeof");
_Static_assert(_Alignof(struct A8_required_alignment) == 1, "record A8 wrong alignment");
_Static_assert(sizeof(struct A8_size) == 8, "record A8 wrong sizeof");
_Static_assert(_Alignof(struct A8_size) == 1, "record A8 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A8,i) == 8, "field A8.i wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A8,j) == 39, "field A8.j wrong bit offset");
#endif
_Static_assert(sizeof(A9) == 10, "record A9 wrong sizeof");
_Static_assert(_Alignof(A9) == 2, "record A9 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A9_alignment) == 12, "record A9 wrong sizeof");
_Static_assert(_Alignof(struct A9_alignment) == 2, "record A9 wrong alignment");
_Static_assert(sizeof(struct A9_packed) == 10, "record A9 wrong sizeof");
_Static_assert(_Alignof(struct A9_packed) == 1, "record A9 wrong alignment");
_Static_assert(sizeof(struct A9_required_alignment) == 11, "record A9 wrong sizeof");
_Static_assert(_Alignof(struct A9_required_alignment) == 1, "record A9 wrong alignment");
_Static_assert(sizeof(struct A9_size) == 12, "record A9 wrong sizeof");
_Static_assert(_Alignof(struct A9_size) == 1, "record A9 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A9,i) == 8, "field A9.i wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A9,j) == 48, "field A9.j wrong bit offset");
#endif
_Static_assert(sizeof(A10) == 4, "record A10 wrong sizeof");
_Static_assert(_Alignof(A10) == 16, "record A10 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A10_alignment) == 32, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_alignment) == 16, "record A10 wrong alignment");
_Static_assert(sizeof(struct A10_packed) == 4, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_packed) == 1, "record A10 wrong alignment");
_Static_assert(sizeof(struct A10_required_alignment) == 5, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_required_alignment) == 1, "record A10 wrong alignment");
_Static_assert(sizeof(struct A10_size) == 6, "record A10 wrong sizeof");
_Static_assert(_Alignof(struct A10_size) == 1, "record A10 wrong alignment");
#endif
_Static_assert(sizeof(A11) == 32, "record A11 wrong sizeof");
_Static_assert(_Alignof(A11) == 16, "record A11 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A11_alignment) == 48, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_alignment) == 16, "record A11 wrong alignment");
_Static_assert(sizeof(struct A11_packed) == 32, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_packed) == 1, "record A11 wrong alignment");
_Static_assert(sizeof(struct A11_required_alignment) == 33, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_required_alignment) == 1, "record A11 wrong alignment");
_Static_assert(sizeof(struct A11_size) == 34, "record A11 wrong sizeof");
_Static_assert(_Alignof(struct A11_size) == 1, "record A11 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A11,i) == 8, "field A11.i wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A11,j) == 128, "field A11.j wrong bit offset");
#endif
_Static_assert(sizeof(A12) == 32, "record A12 wrong sizeof");
_Static_assert(_Alignof(A12) == 16, "record A12 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A12_alignment) == 48, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_alignment) == 16, "record A12 wrong alignment");
_Static_assert(sizeof(struct A12_packed) == 32, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_packed) == 1, "record A12 wrong alignment");
_Static_assert(sizeof(struct A12_required_alignment) == 33, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_required_alignment) == 1, "record A12 wrong alignment");
_Static_assert(sizeof(struct A12_size) == 34, "record A12 wrong sizeof");
_Static_assert(_Alignof(struct A12_size) == 1, "record A12 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A12,i) == 8, "field A12.i wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A12,j) == 128, "field A12.j wrong bit offset");
#endif
_Static_assert(sizeof(A13) == 32, "record A13 wrong sizeof");
_Static_assert(_Alignof(A13) == 16, "record A13 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A13_alignment) == 48, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_alignment) == 16, "record A13 wrong alignment");
_Static_assert(sizeof(struct A13_packed) == 32, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_packed) == 1, "record A13 wrong alignment");
_Static_assert(sizeof(struct A13_required_alignment) == 33, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_required_alignment) == 1, "record A13 wrong alignment");
_Static_assert(sizeof(struct A13_size) == 34, "record A13 wrong sizeof");
_Static_assert(_Alignof(struct A13_size) == 1, "record A13 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A13,i) == 8, "field A13.i wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A13,j) == 128, "field A13.j wrong bit offset");
_Static_assert(__builtin_bitoffsetof(A13,d) == 136, "field A13.d wrong bit offset");
#endif
#endif
