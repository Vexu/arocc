// SPDX-License-Identifier: GPL-3.0-or-later

// This test file is auto-generated. do not edit.
// This file is a derivative work from the test files found// in this repo : https://github.com/mahkoh/repr-c
// and is under the same licence as the original work.

typedef struct {
    long long a:1;
    long long:0;
    long long b:1;
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

typedef union {
    long long a:1;
    long long:0;
    long long b:1;
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
    long long a:1;
    long long:0 __attribute__((packed));
    long long b:1;
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

typedef union {
    long long a:1;
    long long:0 __attribute__((packed));
    long long b:1;
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
    long long a:1;
    long long:0;
    long long b:1;
} __attribute__((packed)) C;
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

typedef union {
    long long a:1;
    long long:0;
    long long b:1;
} __attribute__((packed)) C_;
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

#pragma pack(1)
typedef struct {
    long long a:1;
    long long:0;
    long long b:1;
} __attribute__((packed)) D;
D var25;
#pragma pack()
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

#pragma pack(1)
typedef union {
    long long a:1;
    long long:0;
    long long b:1;
} __attribute__((packed)) D_;
D_ var29;
#pragma pack()
struct D__alignment {
    char a;
    D_ b;
};
struct D__alignment var30;
#pragma pack(1)
struct D__packed {
    D_ a;
};
#pragma pack()
struct D__required_alignment {
    char a;
    struct D__packed b;
};
struct D__required_alignment var31;
struct D__size {
    char a[sizeof(D_)+1];
    char b;
};
struct D__size var32;

#pragma pack(1)
typedef struct {
    long long a:1;
    long long:0 __attribute__((aligned(128)));
    long long b:1;
} __attribute__((packed)) E;
E var33;
#pragma pack()
struct E_alignment {
    char a;
    E b;
};
struct E_alignment var34;
#pragma pack(1)
struct E_packed {
    E a;
};
#pragma pack()
struct E_required_alignment {
    char a;
    struct E_packed b;
};
struct E_required_alignment var35;
struct E_size {
    char a[sizeof(E)+1];
    char b;
};
struct E_size var36;

#pragma pack(1)
typedef union {
    long long a:1;
    long long:0 __attribute__((aligned(128)));
    long long b:1;
} __attribute__((packed)) E_;
E_ var37;
#pragma pack()
struct E__alignment {
    char a;
    E_ b;
};
struct E__alignment var38;
#pragma pack(1)
struct E__packed {
    E_ a;
};
#pragma pack()
struct E__required_alignment {
    char a;
    struct E__packed b;
};
struct E__required_alignment var39;
struct E__size {
    char a[sizeof(E_)+1];
    char b;
};
struct E__size var40;

typedef struct {
    long long a:1;
    long long:0 __attribute__((aligned(128)));
    long long b:1;
} __attribute__((packed)) F;
F var41;
struct F_alignment {
    char a;
    F b;
};
struct F_alignment var42;
#pragma pack(1)
struct F_packed {
    F a;
};
#pragma pack()
struct F_required_alignment {
    char a;
    struct F_packed b;
};
struct F_required_alignment var43;
struct F_size {
    char a[sizeof(F)+1];
    char b;
};
struct F_size var44;

typedef union {
    long long a:1;
    long long:0 __attribute__((aligned(128)));
    long long b:1;
} __attribute__((packed)) F_;
F_ var45;
struct F__alignment {
    char a;
    F_ b;
};
struct F__alignment var46;
#pragma pack(1)
struct F__packed {
    F_ a;
};
#pragma pack()
struct F__required_alignment {
    char a;
    struct F__packed b;
};
struct F__required_alignment var47;
struct F__size {
    char a[sizeof(F_)+1];
    char b;
};
struct F__size var48;

typedef struct {
    long long a:1;
    long long:0 __attribute__((aligned(128))) __attribute__((packed));
    long long b:1;
} G;
G var49;
struct G_alignment {
    char a;
    G b;
};
struct G_alignment var50;
#pragma pack(1)
struct G_packed {
    G a;
};
#pragma pack()
struct G_required_alignment {
    char a;
    struct G_packed b;
};
struct G_required_alignment var51;
struct G_size {
    char a[sizeof(G)+1];
    char b;
};
struct G_size var52;

typedef union {
    long long a:1;
    long long:0 __attribute__((aligned(128))) __attribute__((packed));
    long long b:1;
} G_;
G_ var53;
struct G__alignment {
    char a;
    G_ b;
};
struct G__alignment var54;
#pragma pack(1)
struct G__packed {
    G_ a;
};
#pragma pack()
struct G__required_alignment {
    char a;
    struct G__packed b;
};
struct G__required_alignment var55;
struct G__size {
    char a[sizeof(G_)+1];
    char b;
};
struct G__size var56;

#pragma pack(1)
typedef struct {
    long long a:1;
    long long:0 __attribute__((aligned(128))) __attribute__((packed));
    long long b:1;
} H;
H var57;
#pragma pack()
struct H_alignment {
    char a;
    H b;
};
struct H_alignment var58;
#pragma pack(1)
struct H_packed {
    H a;
};
#pragma pack()
struct H_required_alignment {
    char a;
    struct H_packed b;
};
struct H_required_alignment var59;
struct H_size {
    char a[sizeof(H)+1];
    char b;
};
struct H_size var60;

#pragma pack(1)
typedef union {
    long long a:1;
    long long:0 __attribute__((aligned(128))) __attribute__((packed));
    long long b:1;
} H_;
H_ var61;
#pragma pack()
struct H__alignment {
    char a;
    H_ b;
};
struct H__alignment var62;
#pragma pack(1)
struct H__packed {
    H_ a;
};
#pragma pack()
struct H__required_alignment {
    char a;
    struct H__packed b;
};
struct H__required_alignment var63;
struct H__size {
    char a[sizeof(H_)+1];
    char b;
};
struct H__size var64;

typedef long long I __attribute__((aligned(128)));
I var65;
struct I_alignment {
    char a;
    I b;
};
struct I_alignment var66;
#pragma pack(1)
struct I_packed {
    I a;
};
#pragma pack()
struct I_required_alignment {
    char a;
    struct I_packed b;
};
struct I_required_alignment var67;
struct I_size {
    char a[sizeof(I)+1];
    char b;
};
struct I_size var68;

typedef struct {
    long long a:1;
    I:0 __attribute__((packed));
    long long b:1;
} J;
J var69;
struct J_alignment {
    char a;
    J b;
};
struct J_alignment var70;
#pragma pack(1)
struct J_packed {
    J a;
};
#pragma pack()
struct J_required_alignment {
    char a;
    struct J_packed b;
};
struct J_required_alignment var71;
struct J_size {
    char a[sizeof(J)+1];
    char b;
};
struct J_size var72;

typedef union {
    long long a:1;
    I:0 __attribute__((packed));
    long long b:1;
} J_;
J_ var73;
struct J__alignment {
    char a;
    J_ b;
};
struct J__alignment var74;
#pragma pack(1)
struct J__packed {
    J_ a;
};
#pragma pack()
struct J__required_alignment {
    char a;
    struct J__packed b;
};
struct J__required_alignment var75;
struct J__size {
    char a[sizeof(J_)+1];
    char b;
};
struct J__size var76;


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
_Static_assert(sizeof(A) == 16, "record A wrong sizeof");
_Static_assert(_Alignof(A) == 8, "record A wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 24, "record A_alignment wrong sizeof");
_Static_assert(_Alignof(struct A_alignment) == 8, "record A_alignment wrong alignment");
_Static_assert(sizeof(struct A_packed) == 16, "record A_packed wrong sizeof");
_Static_assert(_Alignof(struct A_packed) == 1, "record A_packed wrong alignment");
_Static_assert(sizeof(struct A_required_alignment) == 17, "record A_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "record A_required_alignment wrong alignment");
_Static_assert(sizeof(struct A_size) == 18, "record A_size wrong sizeof");
_Static_assert(_Alignof(struct A_size) == 1, "record A_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A,b) == 64, "field A.b wrong bit offset");
#endif
_Static_assert(sizeof(A_) == 8, "record A_ wrong sizeof");
_Static_assert(_Alignof(A_) == 8, "record A_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A__alignment) == 16, "record A__alignment wrong sizeof");
_Static_assert(_Alignof(struct A__alignment) == 8, "record A__alignment wrong alignment");
_Static_assert(sizeof(struct A__packed) == 8, "record A__packed wrong sizeof");
_Static_assert(_Alignof(struct A__packed) == 1, "record A__packed wrong alignment");
_Static_assert(sizeof(struct A__required_alignment) == 9, "record A__required_alignment wrong sizeof");
_Static_assert(_Alignof(struct A__required_alignment) == 1, "record A__required_alignment wrong alignment");
_Static_assert(sizeof(struct A__size) == 10, "record A__size wrong sizeof");
_Static_assert(_Alignof(struct A__size) == 1, "record A__size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_,b) == 0, "field A_.b wrong bit offset");
#endif
_Static_assert(sizeof(B) == 16, "record B wrong sizeof");
_Static_assert(_Alignof(B) == 8, "record B wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 24, "record B_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_alignment) == 8, "record B_alignment wrong alignment");
_Static_assert(sizeof(struct B_packed) == 16, "record B_packed wrong sizeof");
_Static_assert(_Alignof(struct B_packed) == 1, "record B_packed wrong alignment");
_Static_assert(sizeof(struct B_required_alignment) == 17, "record B_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "record B_required_alignment wrong alignment");
_Static_assert(sizeof(struct B_size) == 18, "record B_size wrong sizeof");
_Static_assert(_Alignof(struct B_size) == 1, "record B_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B,b) == 64, "field B.b wrong bit offset");
#endif
_Static_assert(sizeof(B_) == 8, "record B_ wrong sizeof");
_Static_assert(_Alignof(B_) == 8, "record B_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B__alignment) == 16, "record B__alignment wrong sizeof");
_Static_assert(_Alignof(struct B__alignment) == 8, "record B__alignment wrong alignment");
_Static_assert(sizeof(struct B__packed) == 8, "record B__packed wrong sizeof");
_Static_assert(_Alignof(struct B__packed) == 1, "record B__packed wrong alignment");
_Static_assert(sizeof(struct B__required_alignment) == 9, "record B__required_alignment wrong sizeof");
_Static_assert(_Alignof(struct B__required_alignment) == 1, "record B__required_alignment wrong alignment");
_Static_assert(sizeof(struct B__size) == 10, "record B__size wrong sizeof");
_Static_assert(_Alignof(struct B__size) == 1, "record B__size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B_,b) == 0, "field B_.b wrong bit offset");
#endif
_Static_assert(sizeof(C) == 9, "record C wrong sizeof");
_Static_assert(_Alignof(C) == 1, "record C wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 10, "record C_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_alignment) == 1, "record C_alignment wrong alignment");
_Static_assert(sizeof(struct C_packed) == 9, "record C_packed wrong sizeof");
_Static_assert(_Alignof(struct C_packed) == 1, "record C_packed wrong alignment");
_Static_assert(sizeof(struct C_required_alignment) == 10, "record C_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "record C_required_alignment wrong alignment");
_Static_assert(sizeof(struct C_size) == 11, "record C_size wrong sizeof");
_Static_assert(_Alignof(struct C_size) == 1, "record C_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C,b) == 64, "field C.b wrong bit offset");
#endif
_Static_assert(sizeof(C_) == 1, "record C_ wrong sizeof");
_Static_assert(_Alignof(C_) == 1, "record C_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C__alignment) == 2, "record C__alignment wrong sizeof");
_Static_assert(_Alignof(struct C__alignment) == 1, "record C__alignment wrong alignment");
_Static_assert(sizeof(struct C__packed) == 1, "record C__packed wrong sizeof");
_Static_assert(_Alignof(struct C__packed) == 1, "record C__packed wrong alignment");
_Static_assert(sizeof(struct C__required_alignment) == 2, "record C__required_alignment wrong sizeof");
_Static_assert(_Alignof(struct C__required_alignment) == 1, "record C__required_alignment wrong alignment");
_Static_assert(sizeof(struct C__size) == 3, "record C__size wrong sizeof");
_Static_assert(_Alignof(struct C__size) == 1, "record C__size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C_,b) == 0, "field C_.b wrong bit offset");
#endif
_Static_assert(sizeof(D) == 9, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 1, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 10, "record D_alignment wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 1, "record D_alignment wrong alignment");
_Static_assert(sizeof(struct D_packed) == 9, "record D_packed wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D_packed wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 10, "record D_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D_required_alignment wrong alignment");
_Static_assert(sizeof(struct D_size) == 11, "record D_size wrong sizeof");
_Static_assert(_Alignof(struct D_size) == 1, "record D_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D,b) == 64, "field D.b wrong bit offset");
#endif
_Static_assert(sizeof(D_) == 1, "record D_ wrong sizeof");
_Static_assert(_Alignof(D_) == 1, "record D_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D__alignment) == 2, "record D__alignment wrong sizeof");
_Static_assert(_Alignof(struct D__alignment) == 1, "record D__alignment wrong alignment");
_Static_assert(sizeof(struct D__packed) == 1, "record D__packed wrong sizeof");
_Static_assert(_Alignof(struct D__packed) == 1, "record D__packed wrong alignment");
_Static_assert(sizeof(struct D__required_alignment) == 2, "record D__required_alignment wrong sizeof");
_Static_assert(_Alignof(struct D__required_alignment) == 1, "record D__required_alignment wrong alignment");
_Static_assert(sizeof(struct D__size) == 3, "record D__size wrong sizeof");
_Static_assert(_Alignof(struct D__size) == 1, "record D__size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D_,b) == 0, "field D_.b wrong bit offset");
#endif
_Static_assert(sizeof(E) == 129, "record E wrong sizeof");
_Static_assert(_Alignof(E) == 1, "record E wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 130, "record E_alignment wrong sizeof");
_Static_assert(_Alignof(struct E_alignment) == 1, "record E_alignment wrong alignment");
_Static_assert(sizeof(struct E_packed) == 129, "record E_packed wrong sizeof");
_Static_assert(_Alignof(struct E_packed) == 1, "record E_packed wrong alignment");
_Static_assert(sizeof(struct E_required_alignment) == 130, "record E_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "record E_required_alignment wrong alignment");
_Static_assert(sizeof(struct E_size) == 131, "record E_size wrong sizeof");
_Static_assert(_Alignof(struct E_size) == 1, "record E_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(E,b) == 1024, "field E.b wrong bit offset");
#endif
_Static_assert(sizeof(E_) == 1, "record E_ wrong sizeof");
_Static_assert(_Alignof(E_) == 1, "record E_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E__alignment) == 2, "record E__alignment wrong sizeof");
_Static_assert(_Alignof(struct E__alignment) == 1, "record E__alignment wrong alignment");
_Static_assert(sizeof(struct E__packed) == 1, "record E__packed wrong sizeof");
_Static_assert(_Alignof(struct E__packed) == 1, "record E__packed wrong alignment");
_Static_assert(sizeof(struct E__required_alignment) == 2, "record E__required_alignment wrong sizeof");
_Static_assert(_Alignof(struct E__required_alignment) == 1, "record E__required_alignment wrong alignment");
_Static_assert(sizeof(struct E__size) == 3, "record E__size wrong sizeof");
_Static_assert(_Alignof(struct E__size) == 1, "record E__size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(E_,b) == 0, "field E_.b wrong bit offset");
#endif
_Static_assert(sizeof(F) == 129, "record F wrong sizeof");
_Static_assert(_Alignof(F) == 1, "record F wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 130, "record F_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_alignment) == 1, "record F_alignment wrong alignment");
_Static_assert(sizeof(struct F_packed) == 129, "record F_packed wrong sizeof");
_Static_assert(_Alignof(struct F_packed) == 1, "record F_packed wrong alignment");
_Static_assert(sizeof(struct F_required_alignment) == 130, "record F_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "record F_required_alignment wrong alignment");
_Static_assert(sizeof(struct F_size) == 131, "record F_size wrong sizeof");
_Static_assert(_Alignof(struct F_size) == 1, "record F_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F,b) == 1024, "field F.b wrong bit offset");
#endif
_Static_assert(sizeof(F_) == 1, "record F_ wrong sizeof");
_Static_assert(_Alignof(F_) == 1, "record F_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F__alignment) == 2, "record F__alignment wrong sizeof");
_Static_assert(_Alignof(struct F__alignment) == 1, "record F__alignment wrong alignment");
_Static_assert(sizeof(struct F__packed) == 1, "record F__packed wrong sizeof");
_Static_assert(_Alignof(struct F__packed) == 1, "record F__packed wrong alignment");
_Static_assert(sizeof(struct F__required_alignment) == 2, "record F__required_alignment wrong sizeof");
_Static_assert(_Alignof(struct F__required_alignment) == 1, "record F__required_alignment wrong alignment");
_Static_assert(sizeof(struct F__size) == 3, "record F__size wrong sizeof");
_Static_assert(_Alignof(struct F__size) == 1, "record F__size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F_,b) == 0, "field F_.b wrong bit offset");
#endif
_Static_assert(sizeof(G) == 136, "record G wrong sizeof");
_Static_assert(_Alignof(G) == 8, "record G wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 144, "record G_alignment wrong sizeof");
_Static_assert(_Alignof(struct G_alignment) == 8, "record G_alignment wrong alignment");
_Static_assert(sizeof(struct G_packed) == 136, "record G_packed wrong sizeof");
_Static_assert(_Alignof(struct G_packed) == 1, "record G_packed wrong alignment");
_Static_assert(sizeof(struct G_required_alignment) == 137, "record G_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "record G_required_alignment wrong alignment");
_Static_assert(sizeof(struct G_size) == 138, "record G_size wrong sizeof");
_Static_assert(_Alignof(struct G_size) == 1, "record G_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(G,b) == 1024, "field G.b wrong bit offset");
#endif
_Static_assert(sizeof(G_) == 8, "record G_ wrong sizeof");
_Static_assert(_Alignof(G_) == 8, "record G_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G__alignment) == 16, "record G__alignment wrong sizeof");
_Static_assert(_Alignof(struct G__alignment) == 8, "record G__alignment wrong alignment");
_Static_assert(sizeof(struct G__packed) == 8, "record G__packed wrong sizeof");
_Static_assert(_Alignof(struct G__packed) == 1, "record G__packed wrong alignment");
_Static_assert(sizeof(struct G__required_alignment) == 9, "record G__required_alignment wrong sizeof");
_Static_assert(_Alignof(struct G__required_alignment) == 1, "record G__required_alignment wrong alignment");
_Static_assert(sizeof(struct G__size) == 10, "record G__size wrong sizeof");
_Static_assert(_Alignof(struct G__size) == 1, "record G__size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(G_,b) == 0, "field G_.b wrong bit offset");
#endif
_Static_assert(sizeof(H) == 129, "record H wrong sizeof");
_Static_assert(_Alignof(H) == 1, "record H wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 130, "record H_alignment wrong sizeof");
_Static_assert(_Alignof(struct H_alignment) == 1, "record H_alignment wrong alignment");
_Static_assert(sizeof(struct H_packed) == 129, "record H_packed wrong sizeof");
_Static_assert(_Alignof(struct H_packed) == 1, "record H_packed wrong alignment");
_Static_assert(sizeof(struct H_required_alignment) == 130, "record H_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "record H_required_alignment wrong alignment");
_Static_assert(sizeof(struct H_size) == 131, "record H_size wrong sizeof");
_Static_assert(_Alignof(struct H_size) == 1, "record H_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(H,b) == 1024, "field H.b wrong bit offset");
#endif
_Static_assert(sizeof(H_) == 1, "record H_ wrong sizeof");
_Static_assert(_Alignof(H_) == 1, "record H_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H__alignment) == 2, "record H__alignment wrong sizeof");
_Static_assert(_Alignof(struct H__alignment) == 1, "record H__alignment wrong alignment");
_Static_assert(sizeof(struct H__packed) == 1, "record H__packed wrong sizeof");
_Static_assert(_Alignof(struct H__packed) == 1, "record H__packed wrong alignment");
_Static_assert(sizeof(struct H__required_alignment) == 2, "record H__required_alignment wrong sizeof");
_Static_assert(_Alignof(struct H__required_alignment) == 1, "record H__required_alignment wrong alignment");
_Static_assert(sizeof(struct H__size) == 3, "record H__size wrong sizeof");
_Static_assert(_Alignof(struct H__size) == 1, "record H__size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(H_,b) == 0, "field H_.b wrong bit offset");
#endif
_Static_assert(sizeof(I) == 8, "record I wrong sizeof");
_Static_assert(_Alignof(I) == 128, "record I wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I_alignment) == 256, "record I_alignment wrong sizeof");
_Static_assert(_Alignof(struct I_alignment) == 128, "record I_alignment wrong alignment");
_Static_assert(sizeof(struct I_packed) == 8, "record I_packed wrong sizeof");
_Static_assert(_Alignof(struct I_packed) == 1, "record I_packed wrong alignment");
_Static_assert(sizeof(struct I_required_alignment) == 9, "record I_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct I_required_alignment) == 1, "record I_required_alignment wrong alignment");
_Static_assert(sizeof(struct I_size) == 10, "record I_size wrong sizeof");
_Static_assert(_Alignof(struct I_size) == 1, "record I_size wrong alignment");
#endif
_Static_assert(sizeof(J) == 136, "record J wrong sizeof");
_Static_assert(_Alignof(J) == 8, "record J wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J_alignment) == 144, "record J_alignment wrong sizeof");
_Static_assert(_Alignof(struct J_alignment) == 8, "record J_alignment wrong alignment");
_Static_assert(sizeof(struct J_packed) == 136, "record J_packed wrong sizeof");
_Static_assert(_Alignof(struct J_packed) == 1, "record J_packed wrong alignment");
_Static_assert(sizeof(struct J_required_alignment) == 137, "record J_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct J_required_alignment) == 1, "record J_required_alignment wrong alignment");
_Static_assert(sizeof(struct J_size) == 138, "record J_size wrong sizeof");
_Static_assert(_Alignof(struct J_size) == 1, "record J_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(J,b) == 1024, "field J.b wrong bit offset");
#endif
_Static_assert(sizeof(J_) == 8, "record J_ wrong sizeof");
_Static_assert(_Alignof(J_) == 8, "record J_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J__alignment) == 16, "record J__alignment wrong sizeof");
_Static_assert(_Alignof(struct J__alignment) == 8, "record J__alignment wrong alignment");
_Static_assert(sizeof(struct J__packed) == 8, "record J__packed wrong sizeof");
_Static_assert(_Alignof(struct J__packed) == 1, "record J__packed wrong alignment");
_Static_assert(sizeof(struct J__required_alignment) == 9, "record J__required_alignment wrong sizeof");
_Static_assert(_Alignof(struct J__required_alignment) == 1, "record J__required_alignment wrong alignment");
_Static_assert(sizeof(struct J__size) == 10, "record J__size wrong sizeof");
_Static_assert(_Alignof(struct J__size) == 1, "record J__size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(J_,b) == 0, "field J_.b wrong bit offset");
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
_Static_assert(sizeof(A) == 16, "record A wrong sizeof");
_Static_assert(_Alignof(A) == 8, "record A wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 24, "record A_alignment wrong sizeof");
_Static_assert(_Alignof(struct A_alignment) == 8, "record A_alignment wrong alignment");
_Static_assert(sizeof(struct A_packed) == 16, "record A_packed wrong sizeof");
_Static_assert(_Alignof(struct A_packed) == 1, "record A_packed wrong alignment");
_Static_assert(sizeof(struct A_required_alignment) == 17, "record A_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "record A_required_alignment wrong alignment");
_Static_assert(sizeof(struct A_size) == 18, "record A_size wrong sizeof");
_Static_assert(_Alignof(struct A_size) == 1, "record A_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A,b) == 64, "field A.b wrong bit offset");
#endif
_Static_assert(sizeof(A_) == 8, "record A_ wrong sizeof");
_Static_assert(_Alignof(A_) == 8, "record A_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A__alignment) == 16, "record A__alignment wrong sizeof");
_Static_assert(_Alignof(struct A__alignment) == 8, "record A__alignment wrong alignment");
_Static_assert(sizeof(struct A__packed) == 8, "record A__packed wrong sizeof");
_Static_assert(_Alignof(struct A__packed) == 1, "record A__packed wrong alignment");
_Static_assert(sizeof(struct A__required_alignment) == 9, "record A__required_alignment wrong sizeof");
_Static_assert(_Alignof(struct A__required_alignment) == 1, "record A__required_alignment wrong alignment");
_Static_assert(sizeof(struct A__size) == 10, "record A__size wrong sizeof");
_Static_assert(_Alignof(struct A__size) == 1, "record A__size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_,b) == 0, "field A_.b wrong bit offset");
#endif
_Static_assert(sizeof(B) == 16, "record B wrong sizeof");
_Static_assert(_Alignof(B) == 8, "record B wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 24, "record B_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_alignment) == 8, "record B_alignment wrong alignment");
_Static_assert(sizeof(struct B_packed) == 16, "record B_packed wrong sizeof");
_Static_assert(_Alignof(struct B_packed) == 1, "record B_packed wrong alignment");
_Static_assert(sizeof(struct B_required_alignment) == 17, "record B_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "record B_required_alignment wrong alignment");
_Static_assert(sizeof(struct B_size) == 18, "record B_size wrong sizeof");
_Static_assert(_Alignof(struct B_size) == 1, "record B_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B,b) == 64, "field B.b wrong bit offset");
#endif
_Static_assert(sizeof(B_) == 8, "record B_ wrong sizeof");
_Static_assert(_Alignof(B_) == 8, "record B_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B__alignment) == 16, "record B__alignment wrong sizeof");
_Static_assert(_Alignof(struct B__alignment) == 8, "record B__alignment wrong alignment");
_Static_assert(sizeof(struct B__packed) == 8, "record B__packed wrong sizeof");
_Static_assert(_Alignof(struct B__packed) == 1, "record B__packed wrong alignment");
_Static_assert(sizeof(struct B__required_alignment) == 9, "record B__required_alignment wrong sizeof");
_Static_assert(_Alignof(struct B__required_alignment) == 1, "record B__required_alignment wrong alignment");
_Static_assert(sizeof(struct B__size) == 10, "record B__size wrong sizeof");
_Static_assert(_Alignof(struct B__size) == 1, "record B__size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B_,b) == 0, "field B_.b wrong bit offset");
#endif
_Static_assert(sizeof(C) == 16, "record C wrong sizeof");
_Static_assert(_Alignof(C) == 8, "record C wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 24, "record C_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_alignment) == 8, "record C_alignment wrong alignment");
_Static_assert(sizeof(struct C_packed) == 16, "record C_packed wrong sizeof");
_Static_assert(_Alignof(struct C_packed) == 1, "record C_packed wrong alignment");
_Static_assert(sizeof(struct C_required_alignment) == 17, "record C_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "record C_required_alignment wrong alignment");
_Static_assert(sizeof(struct C_size) == 18, "record C_size wrong sizeof");
_Static_assert(_Alignof(struct C_size) == 1, "record C_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C,b) == 64, "field C.b wrong bit offset");
#endif
_Static_assert(sizeof(C_) == 8, "record C_ wrong sizeof");
_Static_assert(_Alignof(C_) == 8, "record C_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C__alignment) == 16, "record C__alignment wrong sizeof");
_Static_assert(_Alignof(struct C__alignment) == 8, "record C__alignment wrong alignment");
_Static_assert(sizeof(struct C__packed) == 8, "record C__packed wrong sizeof");
_Static_assert(_Alignof(struct C__packed) == 1, "record C__packed wrong alignment");
_Static_assert(sizeof(struct C__required_alignment) == 9, "record C__required_alignment wrong sizeof");
_Static_assert(_Alignof(struct C__required_alignment) == 1, "record C__required_alignment wrong alignment");
_Static_assert(sizeof(struct C__size) == 10, "record C__size wrong sizeof");
_Static_assert(_Alignof(struct C__size) == 1, "record C__size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C_,b) == 0, "field C_.b wrong bit offset");
#endif
_Static_assert(sizeof(D) == 16, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 8, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 24, "record D_alignment wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 8, "record D_alignment wrong alignment");
_Static_assert(sizeof(struct D_packed) == 16, "record D_packed wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D_packed wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 17, "record D_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D_required_alignment wrong alignment");
_Static_assert(sizeof(struct D_size) == 18, "record D_size wrong sizeof");
_Static_assert(_Alignof(struct D_size) == 1, "record D_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D,b) == 64, "field D.b wrong bit offset");
#endif
_Static_assert(sizeof(D_) == 8, "record D_ wrong sizeof");
_Static_assert(_Alignof(D_) == 8, "record D_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D__alignment) == 16, "record D__alignment wrong sizeof");
_Static_assert(_Alignof(struct D__alignment) == 8, "record D__alignment wrong alignment");
_Static_assert(sizeof(struct D__packed) == 8, "record D__packed wrong sizeof");
_Static_assert(_Alignof(struct D__packed) == 1, "record D__packed wrong alignment");
_Static_assert(sizeof(struct D__required_alignment) == 9, "record D__required_alignment wrong sizeof");
_Static_assert(_Alignof(struct D__required_alignment) == 1, "record D__required_alignment wrong alignment");
_Static_assert(sizeof(struct D__size) == 10, "record D__size wrong sizeof");
_Static_assert(_Alignof(struct D__size) == 1, "record D__size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D_,b) == 0, "field D_.b wrong bit offset");
#endif
_Static_assert(sizeof(E) == 256, "record E wrong sizeof");
_Static_assert(_Alignof(E) == 128, "record E wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 384, "record E_alignment wrong sizeof");
_Static_assert(_Alignof(struct E_alignment) == 128, "record E_alignment wrong alignment");
_Static_assert(sizeof(struct E_packed) == 256, "record E_packed wrong sizeof");
_Static_assert(_Alignof(struct E_packed) == 1, "record E_packed wrong alignment");
_Static_assert(sizeof(struct E_required_alignment) == 257, "record E_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "record E_required_alignment wrong alignment");
_Static_assert(sizeof(struct E_size) == 258, "record E_size wrong sizeof");
_Static_assert(_Alignof(struct E_size) == 1, "record E_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(E,b) == 1024, "field E.b wrong bit offset");
#endif
_Static_assert(sizeof(E_) == 128, "record E_ wrong sizeof");
_Static_assert(_Alignof(E_) == 128, "record E_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E__alignment) == 256, "record E__alignment wrong sizeof");
_Static_assert(_Alignof(struct E__alignment) == 128, "record E__alignment wrong alignment");
_Static_assert(sizeof(struct E__packed) == 128, "record E__packed wrong sizeof");
_Static_assert(_Alignof(struct E__packed) == 1, "record E__packed wrong alignment");
_Static_assert(sizeof(struct E__required_alignment) == 129, "record E__required_alignment wrong sizeof");
_Static_assert(_Alignof(struct E__required_alignment) == 1, "record E__required_alignment wrong alignment");
_Static_assert(sizeof(struct E__size) == 130, "record E__size wrong sizeof");
_Static_assert(_Alignof(struct E__size) == 1, "record E__size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(E_,b) == 0, "field E_.b wrong bit offset");
#endif
_Static_assert(sizeof(F) == 256, "record F wrong sizeof");
_Static_assert(_Alignof(F) == 128, "record F wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 384, "record F_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_alignment) == 128, "record F_alignment wrong alignment");
_Static_assert(sizeof(struct F_packed) == 256, "record F_packed wrong sizeof");
_Static_assert(_Alignof(struct F_packed) == 1, "record F_packed wrong alignment");
_Static_assert(sizeof(struct F_required_alignment) == 257, "record F_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "record F_required_alignment wrong alignment");
_Static_assert(sizeof(struct F_size) == 258, "record F_size wrong sizeof");
_Static_assert(_Alignof(struct F_size) == 1, "record F_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F,b) == 1024, "field F.b wrong bit offset");
#endif
_Static_assert(sizeof(F_) == 128, "record F_ wrong sizeof");
_Static_assert(_Alignof(F_) == 128, "record F_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F__alignment) == 256, "record F__alignment wrong sizeof");
_Static_assert(_Alignof(struct F__alignment) == 128, "record F__alignment wrong alignment");
_Static_assert(sizeof(struct F__packed) == 128, "record F__packed wrong sizeof");
_Static_assert(_Alignof(struct F__packed) == 1, "record F__packed wrong alignment");
_Static_assert(sizeof(struct F__required_alignment) == 129, "record F__required_alignment wrong sizeof");
_Static_assert(_Alignof(struct F__required_alignment) == 1, "record F__required_alignment wrong alignment");
_Static_assert(sizeof(struct F__size) == 130, "record F__size wrong sizeof");
_Static_assert(_Alignof(struct F__size) == 1, "record F__size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F_,b) == 0, "field F_.b wrong bit offset");
#endif
_Static_assert(sizeof(G) == 256, "record G wrong sizeof");
_Static_assert(_Alignof(G) == 128, "record G wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 384, "record G_alignment wrong sizeof");
_Static_assert(_Alignof(struct G_alignment) == 128, "record G_alignment wrong alignment");
_Static_assert(sizeof(struct G_packed) == 256, "record G_packed wrong sizeof");
_Static_assert(_Alignof(struct G_packed) == 1, "record G_packed wrong alignment");
_Static_assert(sizeof(struct G_required_alignment) == 257, "record G_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "record G_required_alignment wrong alignment");
_Static_assert(sizeof(struct G_size) == 258, "record G_size wrong sizeof");
_Static_assert(_Alignof(struct G_size) == 1, "record G_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(G,b) == 1024, "field G.b wrong bit offset");
#endif
_Static_assert(sizeof(G_) == 128, "record G_ wrong sizeof");
_Static_assert(_Alignof(G_) == 128, "record G_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G__alignment) == 256, "record G__alignment wrong sizeof");
_Static_assert(_Alignof(struct G__alignment) == 128, "record G__alignment wrong alignment");
_Static_assert(sizeof(struct G__packed) == 128, "record G__packed wrong sizeof");
_Static_assert(_Alignof(struct G__packed) == 1, "record G__packed wrong alignment");
_Static_assert(sizeof(struct G__required_alignment) == 129, "record G__required_alignment wrong sizeof");
_Static_assert(_Alignof(struct G__required_alignment) == 1, "record G__required_alignment wrong alignment");
_Static_assert(sizeof(struct G__size) == 130, "record G__size wrong sizeof");
_Static_assert(_Alignof(struct G__size) == 1, "record G__size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(G_,b) == 0, "field G_.b wrong bit offset");
#endif
_Static_assert(sizeof(H) == 256, "record H wrong sizeof");
_Static_assert(_Alignof(H) == 128, "record H wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 384, "record H_alignment wrong sizeof");
_Static_assert(_Alignof(struct H_alignment) == 128, "record H_alignment wrong alignment");
_Static_assert(sizeof(struct H_packed) == 256, "record H_packed wrong sizeof");
_Static_assert(_Alignof(struct H_packed) == 1, "record H_packed wrong alignment");
_Static_assert(sizeof(struct H_required_alignment) == 257, "record H_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "record H_required_alignment wrong alignment");
_Static_assert(sizeof(struct H_size) == 258, "record H_size wrong sizeof");
_Static_assert(_Alignof(struct H_size) == 1, "record H_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(H,b) == 1024, "field H.b wrong bit offset");
#endif
_Static_assert(sizeof(H_) == 128, "record H_ wrong sizeof");
_Static_assert(_Alignof(H_) == 128, "record H_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H__alignment) == 256, "record H__alignment wrong sizeof");
_Static_assert(_Alignof(struct H__alignment) == 128, "record H__alignment wrong alignment");
_Static_assert(sizeof(struct H__packed) == 128, "record H__packed wrong sizeof");
_Static_assert(_Alignof(struct H__packed) == 1, "record H__packed wrong alignment");
_Static_assert(sizeof(struct H__required_alignment) == 129, "record H__required_alignment wrong sizeof");
_Static_assert(_Alignof(struct H__required_alignment) == 1, "record H__required_alignment wrong alignment");
_Static_assert(sizeof(struct H__size) == 130, "record H__size wrong sizeof");
_Static_assert(_Alignof(struct H__size) == 1, "record H__size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(H_,b) == 0, "field H_.b wrong bit offset");
#endif
_Static_assert(sizeof(I) == 8, "record I wrong sizeof");
_Static_assert(_Alignof(I) == 128, "record I wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I_alignment) == 256, "record I_alignment wrong sizeof");
_Static_assert(_Alignof(struct I_alignment) == 128, "record I_alignment wrong alignment");
_Static_assert(sizeof(struct I_packed) == 8, "record I_packed wrong sizeof");
_Static_assert(_Alignof(struct I_packed) == 1, "record I_packed wrong alignment");
_Static_assert(sizeof(struct I_required_alignment) == 9, "record I_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct I_required_alignment) == 1, "record I_required_alignment wrong alignment");
_Static_assert(sizeof(struct I_size) == 10, "record I_size wrong sizeof");
_Static_assert(_Alignof(struct I_size) == 1, "record I_size wrong alignment");
#endif
_Static_assert(sizeof(J) == 256, "record J wrong sizeof");
_Static_assert(_Alignof(J) == 128, "record J wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J_alignment) == 384, "record J_alignment wrong sizeof");
_Static_assert(_Alignof(struct J_alignment) == 128, "record J_alignment wrong alignment");
_Static_assert(sizeof(struct J_packed) == 256, "record J_packed wrong sizeof");
_Static_assert(_Alignof(struct J_packed) == 1, "record J_packed wrong alignment");
_Static_assert(sizeof(struct J_required_alignment) == 257, "record J_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct J_required_alignment) == 1, "record J_required_alignment wrong alignment");
_Static_assert(sizeof(struct J_size) == 258, "record J_size wrong sizeof");
_Static_assert(_Alignof(struct J_size) == 1, "record J_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(J,b) == 1024, "field J.b wrong bit offset");
#endif
_Static_assert(sizeof(J_) == 128, "record J_ wrong sizeof");
_Static_assert(_Alignof(J_) == 128, "record J_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J__alignment) == 256, "record J__alignment wrong sizeof");
_Static_assert(_Alignof(struct J__alignment) == 128, "record J__alignment wrong alignment");
_Static_assert(sizeof(struct J__packed) == 128, "record J__packed wrong sizeof");
_Static_assert(_Alignof(struct J__packed) == 1, "record J__packed wrong alignment");
_Static_assert(sizeof(struct J__required_alignment) == 129, "record J__required_alignment wrong sizeof");
_Static_assert(_Alignof(struct J__required_alignment) == 1, "record J__required_alignment wrong alignment");
_Static_assert(sizeof(struct J__size) == 130, "record J__size wrong sizeof");
_Static_assert(_Alignof(struct J__size) == 1, "record J__size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(J_,b) == 0, "field J_.b wrong bit offset");
#endif
#elif defined(ARMV7_APPLE_IOS) ||  defined(ARMV7S_APPLE_IOS) 
_Static_assert(sizeof(A) == 8, "record A wrong sizeof");
_Static_assert(_Alignof(A) == 4, "record A wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 12, "record A_alignment wrong sizeof");
_Static_assert(_Alignof(struct A_alignment) == 4, "record A_alignment wrong alignment");
_Static_assert(sizeof(struct A_packed) == 8, "record A_packed wrong sizeof");
_Static_assert(_Alignof(struct A_packed) == 1, "record A_packed wrong alignment");
_Static_assert(sizeof(struct A_required_alignment) == 9, "record A_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "record A_required_alignment wrong alignment");
_Static_assert(sizeof(struct A_size) == 10, "record A_size wrong sizeof");
_Static_assert(_Alignof(struct A_size) == 1, "record A_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A,b) == 32, "field A.b wrong bit offset");
#endif
_Static_assert(sizeof(A_) == 4, "record A_ wrong sizeof");
_Static_assert(_Alignof(A_) == 4, "record A_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A__alignment) == 8, "record A__alignment wrong sizeof");
_Static_assert(_Alignof(struct A__alignment) == 4, "record A__alignment wrong alignment");
_Static_assert(sizeof(struct A__packed) == 4, "record A__packed wrong sizeof");
_Static_assert(_Alignof(struct A__packed) == 1, "record A__packed wrong alignment");
_Static_assert(sizeof(struct A__required_alignment) == 5, "record A__required_alignment wrong sizeof");
_Static_assert(_Alignof(struct A__required_alignment) == 1, "record A__required_alignment wrong alignment");
_Static_assert(sizeof(struct A__size) == 6, "record A__size wrong sizeof");
_Static_assert(_Alignof(struct A__size) == 1, "record A__size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_,b) == 0, "field A_.b wrong bit offset");
#endif
_Static_assert(sizeof(B) == 8, "record B wrong sizeof");
_Static_assert(_Alignof(B) == 4, "record B wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 12, "record B_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_alignment) == 4, "record B_alignment wrong alignment");
_Static_assert(sizeof(struct B_packed) == 8, "record B_packed wrong sizeof");
_Static_assert(_Alignof(struct B_packed) == 1, "record B_packed wrong alignment");
_Static_assert(sizeof(struct B_required_alignment) == 9, "record B_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "record B_required_alignment wrong alignment");
_Static_assert(sizeof(struct B_size) == 10, "record B_size wrong sizeof");
_Static_assert(_Alignof(struct B_size) == 1, "record B_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B,b) == 32, "field B.b wrong bit offset");
#endif
_Static_assert(sizeof(B_) == 4, "record B_ wrong sizeof");
_Static_assert(_Alignof(B_) == 4, "record B_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B__alignment) == 8, "record B__alignment wrong sizeof");
_Static_assert(_Alignof(struct B__alignment) == 4, "record B__alignment wrong alignment");
_Static_assert(sizeof(struct B__packed) == 4, "record B__packed wrong sizeof");
_Static_assert(_Alignof(struct B__packed) == 1, "record B__packed wrong alignment");
_Static_assert(sizeof(struct B__required_alignment) == 5, "record B__required_alignment wrong sizeof");
_Static_assert(_Alignof(struct B__required_alignment) == 1, "record B__required_alignment wrong alignment");
_Static_assert(sizeof(struct B__size) == 6, "record B__size wrong sizeof");
_Static_assert(_Alignof(struct B__size) == 1, "record B__size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B_,b) == 0, "field B_.b wrong bit offset");
#endif
_Static_assert(sizeof(C) == 8, "record C wrong sizeof");
_Static_assert(_Alignof(C) == 4, "record C wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 12, "record C_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_alignment) == 4, "record C_alignment wrong alignment");
_Static_assert(sizeof(struct C_packed) == 8, "record C_packed wrong sizeof");
_Static_assert(_Alignof(struct C_packed) == 1, "record C_packed wrong alignment");
_Static_assert(sizeof(struct C_required_alignment) == 9, "record C_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "record C_required_alignment wrong alignment");
_Static_assert(sizeof(struct C_size) == 10, "record C_size wrong sizeof");
_Static_assert(_Alignof(struct C_size) == 1, "record C_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C,b) == 32, "field C.b wrong bit offset");
#endif
_Static_assert(sizeof(C_) == 4, "record C_ wrong sizeof");
_Static_assert(_Alignof(C_) == 4, "record C_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C__alignment) == 8, "record C__alignment wrong sizeof");
_Static_assert(_Alignof(struct C__alignment) == 4, "record C__alignment wrong alignment");
_Static_assert(sizeof(struct C__packed) == 4, "record C__packed wrong sizeof");
_Static_assert(_Alignof(struct C__packed) == 1, "record C__packed wrong alignment");
_Static_assert(sizeof(struct C__required_alignment) == 5, "record C__required_alignment wrong sizeof");
_Static_assert(_Alignof(struct C__required_alignment) == 1, "record C__required_alignment wrong alignment");
_Static_assert(sizeof(struct C__size) == 6, "record C__size wrong sizeof");
_Static_assert(_Alignof(struct C__size) == 1, "record C__size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C_,b) == 0, "field C_.b wrong bit offset");
#endif
_Static_assert(sizeof(D) == 8, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 4, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 12, "record D_alignment wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 4, "record D_alignment wrong alignment");
_Static_assert(sizeof(struct D_packed) == 8, "record D_packed wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D_packed wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 9, "record D_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D_required_alignment wrong alignment");
_Static_assert(sizeof(struct D_size) == 10, "record D_size wrong sizeof");
_Static_assert(_Alignof(struct D_size) == 1, "record D_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D,b) == 32, "field D.b wrong bit offset");
#endif
_Static_assert(sizeof(D_) == 4, "record D_ wrong sizeof");
_Static_assert(_Alignof(D_) == 4, "record D_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D__alignment) == 8, "record D__alignment wrong sizeof");
_Static_assert(_Alignof(struct D__alignment) == 4, "record D__alignment wrong alignment");
_Static_assert(sizeof(struct D__packed) == 4, "record D__packed wrong sizeof");
_Static_assert(_Alignof(struct D__packed) == 1, "record D__packed wrong alignment");
_Static_assert(sizeof(struct D__required_alignment) == 5, "record D__required_alignment wrong sizeof");
_Static_assert(_Alignof(struct D__required_alignment) == 1, "record D__required_alignment wrong alignment");
_Static_assert(sizeof(struct D__size) == 6, "record D__size wrong sizeof");
_Static_assert(_Alignof(struct D__size) == 1, "record D__size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D_,b) == 0, "field D_.b wrong bit offset");
#endif
_Static_assert(sizeof(E) == 256, "record E wrong sizeof");
_Static_assert(_Alignof(E) == 128, "record E wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 384, "record E_alignment wrong sizeof");
_Static_assert(_Alignof(struct E_alignment) == 128, "record E_alignment wrong alignment");
_Static_assert(sizeof(struct E_packed) == 256, "record E_packed wrong sizeof");
_Static_assert(_Alignof(struct E_packed) == 1, "record E_packed wrong alignment");
_Static_assert(sizeof(struct E_required_alignment) == 257, "record E_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "record E_required_alignment wrong alignment");
_Static_assert(sizeof(struct E_size) == 258, "record E_size wrong sizeof");
_Static_assert(_Alignof(struct E_size) == 1, "record E_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(E,b) == 1024, "field E.b wrong bit offset");
#endif
_Static_assert(sizeof(E_) == 128, "record E_ wrong sizeof");
_Static_assert(_Alignof(E_) == 128, "record E_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E__alignment) == 256, "record E__alignment wrong sizeof");
_Static_assert(_Alignof(struct E__alignment) == 128, "record E__alignment wrong alignment");
_Static_assert(sizeof(struct E__packed) == 128, "record E__packed wrong sizeof");
_Static_assert(_Alignof(struct E__packed) == 1, "record E__packed wrong alignment");
_Static_assert(sizeof(struct E__required_alignment) == 129, "record E__required_alignment wrong sizeof");
_Static_assert(_Alignof(struct E__required_alignment) == 1, "record E__required_alignment wrong alignment");
_Static_assert(sizeof(struct E__size) == 130, "record E__size wrong sizeof");
_Static_assert(_Alignof(struct E__size) == 1, "record E__size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(E_,b) == 0, "field E_.b wrong bit offset");
#endif
_Static_assert(sizeof(F) == 256, "record F wrong sizeof");
_Static_assert(_Alignof(F) == 128, "record F wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 384, "record F_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_alignment) == 128, "record F_alignment wrong alignment");
_Static_assert(sizeof(struct F_packed) == 256, "record F_packed wrong sizeof");
_Static_assert(_Alignof(struct F_packed) == 1, "record F_packed wrong alignment");
_Static_assert(sizeof(struct F_required_alignment) == 257, "record F_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "record F_required_alignment wrong alignment");
_Static_assert(sizeof(struct F_size) == 258, "record F_size wrong sizeof");
_Static_assert(_Alignof(struct F_size) == 1, "record F_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F,b) == 1024, "field F.b wrong bit offset");
#endif
_Static_assert(sizeof(F_) == 128, "record F_ wrong sizeof");
_Static_assert(_Alignof(F_) == 128, "record F_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F__alignment) == 256, "record F__alignment wrong sizeof");
_Static_assert(_Alignof(struct F__alignment) == 128, "record F__alignment wrong alignment");
_Static_assert(sizeof(struct F__packed) == 128, "record F__packed wrong sizeof");
_Static_assert(_Alignof(struct F__packed) == 1, "record F__packed wrong alignment");
_Static_assert(sizeof(struct F__required_alignment) == 129, "record F__required_alignment wrong sizeof");
_Static_assert(_Alignof(struct F__required_alignment) == 1, "record F__required_alignment wrong alignment");
_Static_assert(sizeof(struct F__size) == 130, "record F__size wrong sizeof");
_Static_assert(_Alignof(struct F__size) == 1, "record F__size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F_,b) == 0, "field F_.b wrong bit offset");
#endif
_Static_assert(sizeof(G) == 256, "record G wrong sizeof");
_Static_assert(_Alignof(G) == 128, "record G wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 384, "record G_alignment wrong sizeof");
_Static_assert(_Alignof(struct G_alignment) == 128, "record G_alignment wrong alignment");
_Static_assert(sizeof(struct G_packed) == 256, "record G_packed wrong sizeof");
_Static_assert(_Alignof(struct G_packed) == 1, "record G_packed wrong alignment");
_Static_assert(sizeof(struct G_required_alignment) == 257, "record G_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "record G_required_alignment wrong alignment");
_Static_assert(sizeof(struct G_size) == 258, "record G_size wrong sizeof");
_Static_assert(_Alignof(struct G_size) == 1, "record G_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(G,b) == 1024, "field G.b wrong bit offset");
#endif
_Static_assert(sizeof(G_) == 128, "record G_ wrong sizeof");
_Static_assert(_Alignof(G_) == 128, "record G_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G__alignment) == 256, "record G__alignment wrong sizeof");
_Static_assert(_Alignof(struct G__alignment) == 128, "record G__alignment wrong alignment");
_Static_assert(sizeof(struct G__packed) == 128, "record G__packed wrong sizeof");
_Static_assert(_Alignof(struct G__packed) == 1, "record G__packed wrong alignment");
_Static_assert(sizeof(struct G__required_alignment) == 129, "record G__required_alignment wrong sizeof");
_Static_assert(_Alignof(struct G__required_alignment) == 1, "record G__required_alignment wrong alignment");
_Static_assert(sizeof(struct G__size) == 130, "record G__size wrong sizeof");
_Static_assert(_Alignof(struct G__size) == 1, "record G__size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(G_,b) == 0, "field G_.b wrong bit offset");
#endif
_Static_assert(sizeof(H) == 256, "record H wrong sizeof");
_Static_assert(_Alignof(H) == 128, "record H wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 384, "record H_alignment wrong sizeof");
_Static_assert(_Alignof(struct H_alignment) == 128, "record H_alignment wrong alignment");
_Static_assert(sizeof(struct H_packed) == 256, "record H_packed wrong sizeof");
_Static_assert(_Alignof(struct H_packed) == 1, "record H_packed wrong alignment");
_Static_assert(sizeof(struct H_required_alignment) == 257, "record H_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "record H_required_alignment wrong alignment");
_Static_assert(sizeof(struct H_size) == 258, "record H_size wrong sizeof");
_Static_assert(_Alignof(struct H_size) == 1, "record H_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(H,b) == 1024, "field H.b wrong bit offset");
#endif
_Static_assert(sizeof(H_) == 128, "record H_ wrong sizeof");
_Static_assert(_Alignof(H_) == 128, "record H_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H__alignment) == 256, "record H__alignment wrong sizeof");
_Static_assert(_Alignof(struct H__alignment) == 128, "record H__alignment wrong alignment");
_Static_assert(sizeof(struct H__packed) == 128, "record H__packed wrong sizeof");
_Static_assert(_Alignof(struct H__packed) == 1, "record H__packed wrong alignment");
_Static_assert(sizeof(struct H__required_alignment) == 129, "record H__required_alignment wrong sizeof");
_Static_assert(_Alignof(struct H__required_alignment) == 1, "record H__required_alignment wrong alignment");
_Static_assert(sizeof(struct H__size) == 130, "record H__size wrong sizeof");
_Static_assert(_Alignof(struct H__size) == 1, "record H__size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(H_,b) == 0, "field H_.b wrong bit offset");
#endif
_Static_assert(sizeof(I) == 8, "record I wrong sizeof");
_Static_assert(_Alignof(I) == 128, "record I wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I_alignment) == 256, "record I_alignment wrong sizeof");
_Static_assert(_Alignof(struct I_alignment) == 128, "record I_alignment wrong alignment");
_Static_assert(sizeof(struct I_packed) == 8, "record I_packed wrong sizeof");
_Static_assert(_Alignof(struct I_packed) == 1, "record I_packed wrong alignment");
_Static_assert(sizeof(struct I_required_alignment) == 9, "record I_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct I_required_alignment) == 1, "record I_required_alignment wrong alignment");
_Static_assert(sizeof(struct I_size) == 10, "record I_size wrong sizeof");
_Static_assert(_Alignof(struct I_size) == 1, "record I_size wrong alignment");
#endif
_Static_assert(sizeof(J) == 256, "record J wrong sizeof");
_Static_assert(_Alignof(J) == 128, "record J wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J_alignment) == 384, "record J_alignment wrong sizeof");
_Static_assert(_Alignof(struct J_alignment) == 128, "record J_alignment wrong alignment");
_Static_assert(sizeof(struct J_packed) == 256, "record J_packed wrong sizeof");
_Static_assert(_Alignof(struct J_packed) == 1, "record J_packed wrong alignment");
_Static_assert(sizeof(struct J_required_alignment) == 257, "record J_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct J_required_alignment) == 1, "record J_required_alignment wrong alignment");
_Static_assert(sizeof(struct J_size) == 258, "record J_size wrong sizeof");
_Static_assert(_Alignof(struct J_size) == 1, "record J_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(J,b) == 1024, "field J.b wrong bit offset");
#endif
_Static_assert(sizeof(J_) == 128, "record J_ wrong sizeof");
_Static_assert(_Alignof(J_) == 128, "record J_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J__alignment) == 256, "record J__alignment wrong sizeof");
_Static_assert(_Alignof(struct J__alignment) == 128, "record J__alignment wrong alignment");
_Static_assert(sizeof(struct J__packed) == 128, "record J__packed wrong sizeof");
_Static_assert(_Alignof(struct J__packed) == 1, "record J__packed wrong alignment");
_Static_assert(sizeof(struct J__required_alignment) == 129, "record J__required_alignment wrong sizeof");
_Static_assert(_Alignof(struct J__required_alignment) == 1, "record J__required_alignment wrong alignment");
_Static_assert(sizeof(struct J__size) == 130, "record J__size wrong sizeof");
_Static_assert(_Alignof(struct J__size) == 1, "record J__size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(J_,b) == 0, "field J_.b wrong bit offset");
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
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A,b) == 8, "field A.b wrong bit offset");
#endif
_Static_assert(sizeof(A_) == 1, "record A_ wrong sizeof");
_Static_assert(_Alignof(A_) == 1, "record A_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A__alignment) == 2, "record A__alignment wrong sizeof");
_Static_assert(_Alignof(struct A__alignment) == 1, "record A__alignment wrong alignment");
_Static_assert(sizeof(struct A__packed) == 1, "record A__packed wrong sizeof");
_Static_assert(_Alignof(struct A__packed) == 1, "record A__packed wrong alignment");
_Static_assert(sizeof(struct A__required_alignment) == 2, "record A__required_alignment wrong sizeof");
_Static_assert(_Alignof(struct A__required_alignment) == 1, "record A__required_alignment wrong alignment");
_Static_assert(sizeof(struct A__size) == 3, "record A__size wrong sizeof");
_Static_assert(_Alignof(struct A__size) == 1, "record A__size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_,b) == 0, "field A_.b wrong bit offset");
#endif
_Static_assert(sizeof(B) == 2, "record B wrong sizeof");
_Static_assert(_Alignof(B) == 1, "record B wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 3, "record B_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_alignment) == 1, "record B_alignment wrong alignment");
_Static_assert(sizeof(struct B_packed) == 2, "record B_packed wrong sizeof");
_Static_assert(_Alignof(struct B_packed) == 1, "record B_packed wrong alignment");
_Static_assert(sizeof(struct B_required_alignment) == 3, "record B_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "record B_required_alignment wrong alignment");
_Static_assert(sizeof(struct B_size) == 4, "record B_size wrong sizeof");
_Static_assert(_Alignof(struct B_size) == 1, "record B_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B,b) == 8, "field B.b wrong bit offset");
#endif
_Static_assert(sizeof(B_) == 1, "record B_ wrong sizeof");
_Static_assert(_Alignof(B_) == 1, "record B_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B__alignment) == 2, "record B__alignment wrong sizeof");
_Static_assert(_Alignof(struct B__alignment) == 1, "record B__alignment wrong alignment");
_Static_assert(sizeof(struct B__packed) == 1, "record B__packed wrong sizeof");
_Static_assert(_Alignof(struct B__packed) == 1, "record B__packed wrong alignment");
_Static_assert(sizeof(struct B__required_alignment) == 2, "record B__required_alignment wrong sizeof");
_Static_assert(_Alignof(struct B__required_alignment) == 1, "record B__required_alignment wrong alignment");
_Static_assert(sizeof(struct B__size) == 3, "record B__size wrong sizeof");
_Static_assert(_Alignof(struct B__size) == 1, "record B__size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B_,b) == 0, "field B_.b wrong bit offset");
#endif
_Static_assert(sizeof(C) == 2, "record C wrong sizeof");
_Static_assert(_Alignof(C) == 1, "record C wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 3, "record C_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_alignment) == 1, "record C_alignment wrong alignment");
_Static_assert(sizeof(struct C_packed) == 2, "record C_packed wrong sizeof");
_Static_assert(_Alignof(struct C_packed) == 1, "record C_packed wrong alignment");
_Static_assert(sizeof(struct C_required_alignment) == 3, "record C_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "record C_required_alignment wrong alignment");
_Static_assert(sizeof(struct C_size) == 4, "record C_size wrong sizeof");
_Static_assert(_Alignof(struct C_size) == 1, "record C_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C,b) == 8, "field C.b wrong bit offset");
#endif
_Static_assert(sizeof(C_) == 1, "record C_ wrong sizeof");
_Static_assert(_Alignof(C_) == 1, "record C_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C__alignment) == 2, "record C__alignment wrong sizeof");
_Static_assert(_Alignof(struct C__alignment) == 1, "record C__alignment wrong alignment");
_Static_assert(sizeof(struct C__packed) == 1, "record C__packed wrong sizeof");
_Static_assert(_Alignof(struct C__packed) == 1, "record C__packed wrong alignment");
_Static_assert(sizeof(struct C__required_alignment) == 2, "record C__required_alignment wrong sizeof");
_Static_assert(_Alignof(struct C__required_alignment) == 1, "record C__required_alignment wrong alignment");
_Static_assert(sizeof(struct C__size) == 3, "record C__size wrong sizeof");
_Static_assert(_Alignof(struct C__size) == 1, "record C__size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C_,b) == 0, "field C_.b wrong bit offset");
#endif
_Static_assert(sizeof(D) == 2, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 1, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 3, "record D_alignment wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 1, "record D_alignment wrong alignment");
_Static_assert(sizeof(struct D_packed) == 2, "record D_packed wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D_packed wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 3, "record D_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D_required_alignment wrong alignment");
_Static_assert(sizeof(struct D_size) == 4, "record D_size wrong sizeof");
_Static_assert(_Alignof(struct D_size) == 1, "record D_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D,b) == 8, "field D.b wrong bit offset");
#endif
_Static_assert(sizeof(D_) == 1, "record D_ wrong sizeof");
_Static_assert(_Alignof(D_) == 1, "record D_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D__alignment) == 2, "record D__alignment wrong sizeof");
_Static_assert(_Alignof(struct D__alignment) == 1, "record D__alignment wrong alignment");
_Static_assert(sizeof(struct D__packed) == 1, "record D__packed wrong sizeof");
_Static_assert(_Alignof(struct D__packed) == 1, "record D__packed wrong alignment");
_Static_assert(sizeof(struct D__required_alignment) == 2, "record D__required_alignment wrong sizeof");
_Static_assert(_Alignof(struct D__required_alignment) == 1, "record D__required_alignment wrong alignment");
_Static_assert(sizeof(struct D__size) == 3, "record D__size wrong sizeof");
_Static_assert(_Alignof(struct D__size) == 1, "record D__size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D_,b) == 0, "field D_.b wrong bit offset");
#endif
_Static_assert(sizeof(E) == 256, "record E wrong sizeof");
_Static_assert(_Alignof(E) == 128, "record E wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 384, "record E_alignment wrong sizeof");
_Static_assert(_Alignof(struct E_alignment) == 128, "record E_alignment wrong alignment");
_Static_assert(sizeof(struct E_packed) == 256, "record E_packed wrong sizeof");
_Static_assert(_Alignof(struct E_packed) == 1, "record E_packed wrong alignment");
_Static_assert(sizeof(struct E_required_alignment) == 257, "record E_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "record E_required_alignment wrong alignment");
_Static_assert(sizeof(struct E_size) == 258, "record E_size wrong sizeof");
_Static_assert(_Alignof(struct E_size) == 1, "record E_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(E,b) == 1024, "field E.b wrong bit offset");
#endif
_Static_assert(sizeof(E_) == 128, "record E_ wrong sizeof");
_Static_assert(_Alignof(E_) == 128, "record E_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E__alignment) == 256, "record E__alignment wrong sizeof");
_Static_assert(_Alignof(struct E__alignment) == 128, "record E__alignment wrong alignment");
_Static_assert(sizeof(struct E__packed) == 128, "record E__packed wrong sizeof");
_Static_assert(_Alignof(struct E__packed) == 1, "record E__packed wrong alignment");
_Static_assert(sizeof(struct E__required_alignment) == 129, "record E__required_alignment wrong sizeof");
_Static_assert(_Alignof(struct E__required_alignment) == 1, "record E__required_alignment wrong alignment");
_Static_assert(sizeof(struct E__size) == 130, "record E__size wrong sizeof");
_Static_assert(_Alignof(struct E__size) == 1, "record E__size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(E_,b) == 0, "field E_.b wrong bit offset");
#endif
_Static_assert(sizeof(F) == 256, "record F wrong sizeof");
_Static_assert(_Alignof(F) == 128, "record F wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 384, "record F_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_alignment) == 128, "record F_alignment wrong alignment");
_Static_assert(sizeof(struct F_packed) == 256, "record F_packed wrong sizeof");
_Static_assert(_Alignof(struct F_packed) == 1, "record F_packed wrong alignment");
_Static_assert(sizeof(struct F_required_alignment) == 257, "record F_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "record F_required_alignment wrong alignment");
_Static_assert(sizeof(struct F_size) == 258, "record F_size wrong sizeof");
_Static_assert(_Alignof(struct F_size) == 1, "record F_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F,b) == 1024, "field F.b wrong bit offset");
#endif
_Static_assert(sizeof(F_) == 128, "record F_ wrong sizeof");
_Static_assert(_Alignof(F_) == 128, "record F_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F__alignment) == 256, "record F__alignment wrong sizeof");
_Static_assert(_Alignof(struct F__alignment) == 128, "record F__alignment wrong alignment");
_Static_assert(sizeof(struct F__packed) == 128, "record F__packed wrong sizeof");
_Static_assert(_Alignof(struct F__packed) == 1, "record F__packed wrong alignment");
_Static_assert(sizeof(struct F__required_alignment) == 129, "record F__required_alignment wrong sizeof");
_Static_assert(_Alignof(struct F__required_alignment) == 1, "record F__required_alignment wrong alignment");
_Static_assert(sizeof(struct F__size) == 130, "record F__size wrong sizeof");
_Static_assert(_Alignof(struct F__size) == 1, "record F__size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F_,b) == 0, "field F_.b wrong bit offset");
#endif
_Static_assert(sizeof(G) == 256, "record G wrong sizeof");
_Static_assert(_Alignof(G) == 128, "record G wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 384, "record G_alignment wrong sizeof");
_Static_assert(_Alignof(struct G_alignment) == 128, "record G_alignment wrong alignment");
_Static_assert(sizeof(struct G_packed) == 256, "record G_packed wrong sizeof");
_Static_assert(_Alignof(struct G_packed) == 1, "record G_packed wrong alignment");
_Static_assert(sizeof(struct G_required_alignment) == 257, "record G_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "record G_required_alignment wrong alignment");
_Static_assert(sizeof(struct G_size) == 258, "record G_size wrong sizeof");
_Static_assert(_Alignof(struct G_size) == 1, "record G_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(G,b) == 1024, "field G.b wrong bit offset");
#endif
_Static_assert(sizeof(G_) == 128, "record G_ wrong sizeof");
_Static_assert(_Alignof(G_) == 128, "record G_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G__alignment) == 256, "record G__alignment wrong sizeof");
_Static_assert(_Alignof(struct G__alignment) == 128, "record G__alignment wrong alignment");
_Static_assert(sizeof(struct G__packed) == 128, "record G__packed wrong sizeof");
_Static_assert(_Alignof(struct G__packed) == 1, "record G__packed wrong alignment");
_Static_assert(sizeof(struct G__required_alignment) == 129, "record G__required_alignment wrong sizeof");
_Static_assert(_Alignof(struct G__required_alignment) == 1, "record G__required_alignment wrong alignment");
_Static_assert(sizeof(struct G__size) == 130, "record G__size wrong sizeof");
_Static_assert(_Alignof(struct G__size) == 1, "record G__size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(G_,b) == 0, "field G_.b wrong bit offset");
#endif
_Static_assert(sizeof(H) == 256, "record H wrong sizeof");
_Static_assert(_Alignof(H) == 128, "record H wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 384, "record H_alignment wrong sizeof");
_Static_assert(_Alignof(struct H_alignment) == 128, "record H_alignment wrong alignment");
_Static_assert(sizeof(struct H_packed) == 256, "record H_packed wrong sizeof");
_Static_assert(_Alignof(struct H_packed) == 1, "record H_packed wrong alignment");
_Static_assert(sizeof(struct H_required_alignment) == 257, "record H_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "record H_required_alignment wrong alignment");
_Static_assert(sizeof(struct H_size) == 258, "record H_size wrong sizeof");
_Static_assert(_Alignof(struct H_size) == 1, "record H_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(H,b) == 1024, "field H.b wrong bit offset");
#endif
_Static_assert(sizeof(H_) == 128, "record H_ wrong sizeof");
_Static_assert(_Alignof(H_) == 128, "record H_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H__alignment) == 256, "record H__alignment wrong sizeof");
_Static_assert(_Alignof(struct H__alignment) == 128, "record H__alignment wrong alignment");
_Static_assert(sizeof(struct H__packed) == 128, "record H__packed wrong sizeof");
_Static_assert(_Alignof(struct H__packed) == 1, "record H__packed wrong alignment");
_Static_assert(sizeof(struct H__required_alignment) == 129, "record H__required_alignment wrong sizeof");
_Static_assert(_Alignof(struct H__required_alignment) == 1, "record H__required_alignment wrong alignment");
_Static_assert(sizeof(struct H__size) == 130, "record H__size wrong sizeof");
_Static_assert(_Alignof(struct H__size) == 1, "record H__size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(H_,b) == 0, "field H_.b wrong bit offset");
#endif
_Static_assert(sizeof(I) == 8, "record I wrong sizeof");
_Static_assert(_Alignof(I) == 128, "record I wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I_alignment) == 256, "record I_alignment wrong sizeof");
_Static_assert(_Alignof(struct I_alignment) == 128, "record I_alignment wrong alignment");
_Static_assert(sizeof(struct I_packed) == 8, "record I_packed wrong sizeof");
_Static_assert(_Alignof(struct I_packed) == 1, "record I_packed wrong alignment");
_Static_assert(sizeof(struct I_required_alignment) == 9, "record I_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct I_required_alignment) == 1, "record I_required_alignment wrong alignment");
_Static_assert(sizeof(struct I_size) == 10, "record I_size wrong sizeof");
_Static_assert(_Alignof(struct I_size) == 1, "record I_size wrong alignment");
#endif
_Static_assert(sizeof(J) == 2, "record J wrong sizeof");
_Static_assert(_Alignof(J) == 1, "record J wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J_alignment) == 3, "record J_alignment wrong sizeof");
_Static_assert(_Alignof(struct J_alignment) == 1, "record J_alignment wrong alignment");
_Static_assert(sizeof(struct J_packed) == 2, "record J_packed wrong sizeof");
_Static_assert(_Alignof(struct J_packed) == 1, "record J_packed wrong alignment");
_Static_assert(sizeof(struct J_required_alignment) == 3, "record J_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct J_required_alignment) == 1, "record J_required_alignment wrong alignment");
_Static_assert(sizeof(struct J_size) == 4, "record J_size wrong sizeof");
_Static_assert(_Alignof(struct J_size) == 1, "record J_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(J,b) == 8, "field J.b wrong bit offset");
#endif
_Static_assert(sizeof(J_) == 1, "record J_ wrong sizeof");
_Static_assert(_Alignof(J_) == 1, "record J_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J__alignment) == 2, "record J__alignment wrong sizeof");
_Static_assert(_Alignof(struct J__alignment) == 1, "record J__alignment wrong alignment");
_Static_assert(sizeof(struct J__packed) == 1, "record J__packed wrong sizeof");
_Static_assert(_Alignof(struct J__packed) == 1, "record J__packed wrong alignment");
_Static_assert(sizeof(struct J__required_alignment) == 2, "record J__required_alignment wrong sizeof");
_Static_assert(_Alignof(struct J__required_alignment) == 1, "record J__required_alignment wrong alignment");
_Static_assert(sizeof(struct J__size) == 3, "record J__size wrong sizeof");
_Static_assert(_Alignof(struct J__size) == 1, "record J__size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(J_,b) == 0, "field J_.b wrong bit offset");
#endif
#elif defined(I386_APPLE_IOS) ||  defined(I586_UNKNOWN_LINUX_GNU) ||  defined(I586_UNKNOWN_LINUX_MUSL) ||  defined(I686_APPLE_MACOSX) ||  \
 defined(I686_LINUX_ANDROID) ||  defined(I686_UNKNOWN_FREEBSD) ||  defined(I686_UNKNOWN_HAIKU) ||  defined(I686_UNKNOWN_LINUX_GNU) ||  \
 defined(I686_UNKNOWN_LINUX_MUSL) ||  defined(I686_UNKNOWN_NETBSDELF) ||  defined(I686_UNKNOWN_OPENBSD) 
_Static_assert(sizeof(A) == 8, "record A wrong sizeof");
_Static_assert(_Alignof(A) == 4, "record A wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 12, "record A_alignment wrong sizeof");
_Static_assert(_Alignof(struct A_alignment) == 4, "record A_alignment wrong alignment");
_Static_assert(sizeof(struct A_packed) == 8, "record A_packed wrong sizeof");
_Static_assert(_Alignof(struct A_packed) == 1, "record A_packed wrong alignment");
_Static_assert(sizeof(struct A_required_alignment) == 9, "record A_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "record A_required_alignment wrong alignment");
_Static_assert(sizeof(struct A_size) == 10, "record A_size wrong sizeof");
_Static_assert(_Alignof(struct A_size) == 1, "record A_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A,b) == 32, "field A.b wrong bit offset");
#endif
_Static_assert(sizeof(A_) == 4, "record A_ wrong sizeof");
_Static_assert(_Alignof(A_) == 4, "record A_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A__alignment) == 8, "record A__alignment wrong sizeof");
_Static_assert(_Alignof(struct A__alignment) == 4, "record A__alignment wrong alignment");
_Static_assert(sizeof(struct A__packed) == 4, "record A__packed wrong sizeof");
_Static_assert(_Alignof(struct A__packed) == 1, "record A__packed wrong alignment");
_Static_assert(sizeof(struct A__required_alignment) == 5, "record A__required_alignment wrong sizeof");
_Static_assert(_Alignof(struct A__required_alignment) == 1, "record A__required_alignment wrong alignment");
_Static_assert(sizeof(struct A__size) == 6, "record A__size wrong sizeof");
_Static_assert(_Alignof(struct A__size) == 1, "record A__size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_,b) == 0, "field A_.b wrong bit offset");
#endif
_Static_assert(sizeof(B) == 8, "record B wrong sizeof");
_Static_assert(_Alignof(B) == 4, "record B wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 12, "record B_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_alignment) == 4, "record B_alignment wrong alignment");
_Static_assert(sizeof(struct B_packed) == 8, "record B_packed wrong sizeof");
_Static_assert(_Alignof(struct B_packed) == 1, "record B_packed wrong alignment");
_Static_assert(sizeof(struct B_required_alignment) == 9, "record B_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "record B_required_alignment wrong alignment");
_Static_assert(sizeof(struct B_size) == 10, "record B_size wrong sizeof");
_Static_assert(_Alignof(struct B_size) == 1, "record B_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B,b) == 32, "field B.b wrong bit offset");
#endif
_Static_assert(sizeof(B_) == 4, "record B_ wrong sizeof");
_Static_assert(_Alignof(B_) == 4, "record B_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B__alignment) == 8, "record B__alignment wrong sizeof");
_Static_assert(_Alignof(struct B__alignment) == 4, "record B__alignment wrong alignment");
_Static_assert(sizeof(struct B__packed) == 4, "record B__packed wrong sizeof");
_Static_assert(_Alignof(struct B__packed) == 1, "record B__packed wrong alignment");
_Static_assert(sizeof(struct B__required_alignment) == 5, "record B__required_alignment wrong sizeof");
_Static_assert(_Alignof(struct B__required_alignment) == 1, "record B__required_alignment wrong alignment");
_Static_assert(sizeof(struct B__size) == 6, "record B__size wrong sizeof");
_Static_assert(_Alignof(struct B__size) == 1, "record B__size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B_,b) == 0, "field B_.b wrong bit offset");
#endif
_Static_assert(sizeof(C) == 5, "record C wrong sizeof");
_Static_assert(_Alignof(C) == 1, "record C wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 6, "record C_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_alignment) == 1, "record C_alignment wrong alignment");
_Static_assert(sizeof(struct C_packed) == 5, "record C_packed wrong sizeof");
_Static_assert(_Alignof(struct C_packed) == 1, "record C_packed wrong alignment");
_Static_assert(sizeof(struct C_required_alignment) == 6, "record C_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "record C_required_alignment wrong alignment");
_Static_assert(sizeof(struct C_size) == 7, "record C_size wrong sizeof");
_Static_assert(_Alignof(struct C_size) == 1, "record C_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C,b) == 32, "field C.b wrong bit offset");
#endif
_Static_assert(sizeof(C_) == 1, "record C_ wrong sizeof");
_Static_assert(_Alignof(C_) == 1, "record C_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C__alignment) == 2, "record C__alignment wrong sizeof");
_Static_assert(_Alignof(struct C__alignment) == 1, "record C__alignment wrong alignment");
_Static_assert(sizeof(struct C__packed) == 1, "record C__packed wrong sizeof");
_Static_assert(_Alignof(struct C__packed) == 1, "record C__packed wrong alignment");
_Static_assert(sizeof(struct C__required_alignment) == 2, "record C__required_alignment wrong sizeof");
_Static_assert(_Alignof(struct C__required_alignment) == 1, "record C__required_alignment wrong alignment");
_Static_assert(sizeof(struct C__size) == 3, "record C__size wrong sizeof");
_Static_assert(_Alignof(struct C__size) == 1, "record C__size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C_,b) == 0, "field C_.b wrong bit offset");
#endif
_Static_assert(sizeof(D) == 5, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 1, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 6, "record D_alignment wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 1, "record D_alignment wrong alignment");
_Static_assert(sizeof(struct D_packed) == 5, "record D_packed wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D_packed wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 6, "record D_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D_required_alignment wrong alignment");
_Static_assert(sizeof(struct D_size) == 7, "record D_size wrong sizeof");
_Static_assert(_Alignof(struct D_size) == 1, "record D_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D,b) == 32, "field D.b wrong bit offset");
#endif
_Static_assert(sizeof(D_) == 1, "record D_ wrong sizeof");
_Static_assert(_Alignof(D_) == 1, "record D_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D__alignment) == 2, "record D__alignment wrong sizeof");
_Static_assert(_Alignof(struct D__alignment) == 1, "record D__alignment wrong alignment");
_Static_assert(sizeof(struct D__packed) == 1, "record D__packed wrong sizeof");
_Static_assert(_Alignof(struct D__packed) == 1, "record D__packed wrong alignment");
_Static_assert(sizeof(struct D__required_alignment) == 2, "record D__required_alignment wrong sizeof");
_Static_assert(_Alignof(struct D__required_alignment) == 1, "record D__required_alignment wrong alignment");
_Static_assert(sizeof(struct D__size) == 3, "record D__size wrong sizeof");
_Static_assert(_Alignof(struct D__size) == 1, "record D__size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D_,b) == 0, "field D_.b wrong bit offset");
#endif
_Static_assert(sizeof(E) == 129, "record E wrong sizeof");
_Static_assert(_Alignof(E) == 1, "record E wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 130, "record E_alignment wrong sizeof");
_Static_assert(_Alignof(struct E_alignment) == 1, "record E_alignment wrong alignment");
_Static_assert(sizeof(struct E_packed) == 129, "record E_packed wrong sizeof");
_Static_assert(_Alignof(struct E_packed) == 1, "record E_packed wrong alignment");
_Static_assert(sizeof(struct E_required_alignment) == 130, "record E_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "record E_required_alignment wrong alignment");
_Static_assert(sizeof(struct E_size) == 131, "record E_size wrong sizeof");
_Static_assert(_Alignof(struct E_size) == 1, "record E_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(E,b) == 1024, "field E.b wrong bit offset");
#endif
_Static_assert(sizeof(E_) == 1, "record E_ wrong sizeof");
_Static_assert(_Alignof(E_) == 1, "record E_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E__alignment) == 2, "record E__alignment wrong sizeof");
_Static_assert(_Alignof(struct E__alignment) == 1, "record E__alignment wrong alignment");
_Static_assert(sizeof(struct E__packed) == 1, "record E__packed wrong sizeof");
_Static_assert(_Alignof(struct E__packed) == 1, "record E__packed wrong alignment");
_Static_assert(sizeof(struct E__required_alignment) == 2, "record E__required_alignment wrong sizeof");
_Static_assert(_Alignof(struct E__required_alignment) == 1, "record E__required_alignment wrong alignment");
_Static_assert(sizeof(struct E__size) == 3, "record E__size wrong sizeof");
_Static_assert(_Alignof(struct E__size) == 1, "record E__size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(E_,b) == 0, "field E_.b wrong bit offset");
#endif
_Static_assert(sizeof(F) == 129, "record F wrong sizeof");
_Static_assert(_Alignof(F) == 1, "record F wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 130, "record F_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_alignment) == 1, "record F_alignment wrong alignment");
_Static_assert(sizeof(struct F_packed) == 129, "record F_packed wrong sizeof");
_Static_assert(_Alignof(struct F_packed) == 1, "record F_packed wrong alignment");
_Static_assert(sizeof(struct F_required_alignment) == 130, "record F_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "record F_required_alignment wrong alignment");
_Static_assert(sizeof(struct F_size) == 131, "record F_size wrong sizeof");
_Static_assert(_Alignof(struct F_size) == 1, "record F_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F,b) == 1024, "field F.b wrong bit offset");
#endif
_Static_assert(sizeof(F_) == 1, "record F_ wrong sizeof");
_Static_assert(_Alignof(F_) == 1, "record F_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F__alignment) == 2, "record F__alignment wrong sizeof");
_Static_assert(_Alignof(struct F__alignment) == 1, "record F__alignment wrong alignment");
_Static_assert(sizeof(struct F__packed) == 1, "record F__packed wrong sizeof");
_Static_assert(_Alignof(struct F__packed) == 1, "record F__packed wrong alignment");
_Static_assert(sizeof(struct F__required_alignment) == 2, "record F__required_alignment wrong sizeof");
_Static_assert(_Alignof(struct F__required_alignment) == 1, "record F__required_alignment wrong alignment");
_Static_assert(sizeof(struct F__size) == 3, "record F__size wrong sizeof");
_Static_assert(_Alignof(struct F__size) == 1, "record F__size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F_,b) == 0, "field F_.b wrong bit offset");
#endif
_Static_assert(sizeof(G) == 132, "record G wrong sizeof");
_Static_assert(_Alignof(G) == 4, "record G wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 136, "record G_alignment wrong sizeof");
_Static_assert(_Alignof(struct G_alignment) == 4, "record G_alignment wrong alignment");
_Static_assert(sizeof(struct G_packed) == 132, "record G_packed wrong sizeof");
_Static_assert(_Alignof(struct G_packed) == 1, "record G_packed wrong alignment");
_Static_assert(sizeof(struct G_required_alignment) == 133, "record G_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "record G_required_alignment wrong alignment");
_Static_assert(sizeof(struct G_size) == 134, "record G_size wrong sizeof");
_Static_assert(_Alignof(struct G_size) == 1, "record G_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(G,b) == 1024, "field G.b wrong bit offset");
#endif
_Static_assert(sizeof(G_) == 4, "record G_ wrong sizeof");
_Static_assert(_Alignof(G_) == 4, "record G_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G__alignment) == 8, "record G__alignment wrong sizeof");
_Static_assert(_Alignof(struct G__alignment) == 4, "record G__alignment wrong alignment");
_Static_assert(sizeof(struct G__packed) == 4, "record G__packed wrong sizeof");
_Static_assert(_Alignof(struct G__packed) == 1, "record G__packed wrong alignment");
_Static_assert(sizeof(struct G__required_alignment) == 5, "record G__required_alignment wrong sizeof");
_Static_assert(_Alignof(struct G__required_alignment) == 1, "record G__required_alignment wrong alignment");
_Static_assert(sizeof(struct G__size) == 6, "record G__size wrong sizeof");
_Static_assert(_Alignof(struct G__size) == 1, "record G__size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(G_,b) == 0, "field G_.b wrong bit offset");
#endif
_Static_assert(sizeof(H) == 129, "record H wrong sizeof");
_Static_assert(_Alignof(H) == 1, "record H wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 130, "record H_alignment wrong sizeof");
_Static_assert(_Alignof(struct H_alignment) == 1, "record H_alignment wrong alignment");
_Static_assert(sizeof(struct H_packed) == 129, "record H_packed wrong sizeof");
_Static_assert(_Alignof(struct H_packed) == 1, "record H_packed wrong alignment");
_Static_assert(sizeof(struct H_required_alignment) == 130, "record H_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "record H_required_alignment wrong alignment");
_Static_assert(sizeof(struct H_size) == 131, "record H_size wrong sizeof");
_Static_assert(_Alignof(struct H_size) == 1, "record H_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(H,b) == 1024, "field H.b wrong bit offset");
#endif
_Static_assert(sizeof(H_) == 1, "record H_ wrong sizeof");
_Static_assert(_Alignof(H_) == 1, "record H_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H__alignment) == 2, "record H__alignment wrong sizeof");
_Static_assert(_Alignof(struct H__alignment) == 1, "record H__alignment wrong alignment");
_Static_assert(sizeof(struct H__packed) == 1, "record H__packed wrong sizeof");
_Static_assert(_Alignof(struct H__packed) == 1, "record H__packed wrong alignment");
_Static_assert(sizeof(struct H__required_alignment) == 2, "record H__required_alignment wrong sizeof");
_Static_assert(_Alignof(struct H__required_alignment) == 1, "record H__required_alignment wrong alignment");
_Static_assert(sizeof(struct H__size) == 3, "record H__size wrong sizeof");
_Static_assert(_Alignof(struct H__size) == 1, "record H__size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(H_,b) == 0, "field H_.b wrong bit offset");
#endif
_Static_assert(sizeof(I) == 8, "record I wrong sizeof");
_Static_assert(_Alignof(I) == 128, "record I wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I_alignment) == 256, "record I_alignment wrong sizeof");
_Static_assert(_Alignof(struct I_alignment) == 128, "record I_alignment wrong alignment");
_Static_assert(sizeof(struct I_packed) == 8, "record I_packed wrong sizeof");
_Static_assert(_Alignof(struct I_packed) == 1, "record I_packed wrong alignment");
_Static_assert(sizeof(struct I_required_alignment) == 9, "record I_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct I_required_alignment) == 1, "record I_required_alignment wrong alignment");
_Static_assert(sizeof(struct I_size) == 10, "record I_size wrong sizeof");
_Static_assert(_Alignof(struct I_size) == 1, "record I_size wrong alignment");
#endif
_Static_assert(sizeof(J) == 132, "record J wrong sizeof");
_Static_assert(_Alignof(J) == 4, "record J wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J_alignment) == 136, "record J_alignment wrong sizeof");
_Static_assert(_Alignof(struct J_alignment) == 4, "record J_alignment wrong alignment");
_Static_assert(sizeof(struct J_packed) == 132, "record J_packed wrong sizeof");
_Static_assert(_Alignof(struct J_packed) == 1, "record J_packed wrong alignment");
_Static_assert(sizeof(struct J_required_alignment) == 133, "record J_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct J_required_alignment) == 1, "record J_required_alignment wrong alignment");
_Static_assert(sizeof(struct J_size) == 134, "record J_size wrong sizeof");
_Static_assert(_Alignof(struct J_size) == 1, "record J_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(J,b) == 1024, "field J.b wrong bit offset");
#endif
_Static_assert(sizeof(J_) == 4, "record J_ wrong sizeof");
_Static_assert(_Alignof(J_) == 4, "record J_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J__alignment) == 8, "record J__alignment wrong sizeof");
_Static_assert(_Alignof(struct J__alignment) == 4, "record J__alignment wrong alignment");
_Static_assert(sizeof(struct J__packed) == 4, "record J__packed wrong sizeof");
_Static_assert(_Alignof(struct J__packed) == 1, "record J__packed wrong alignment");
_Static_assert(sizeof(struct J__required_alignment) == 5, "record J__required_alignment wrong sizeof");
_Static_assert(_Alignof(struct J__required_alignment) == 1, "record J__required_alignment wrong alignment");
_Static_assert(sizeof(struct J__size) == 6, "record J__size wrong sizeof");
_Static_assert(_Alignof(struct J__size) == 1, "record J__size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(J_,b) == 0, "field J_.b wrong bit offset");
#endif
#elif defined(I686_PC_WINDOWS_GNU) ||  defined(X8664_PC_WINDOWS_GNU) 
_Static_assert(sizeof(A) == 16, "record A wrong sizeof");
_Static_assert(_Alignof(A) == 8, "record A wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 24, "record A_alignment wrong sizeof");
_Static_assert(_Alignof(struct A_alignment) == 8, "record A_alignment wrong alignment");
_Static_assert(sizeof(struct A_packed) == 16, "record A_packed wrong sizeof");
_Static_assert(_Alignof(struct A_packed) == 1, "record A_packed wrong alignment");
_Static_assert(sizeof(struct A_required_alignment) == 17, "record A_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "record A_required_alignment wrong alignment");
_Static_assert(sizeof(struct A_size) == 18, "record A_size wrong sizeof");
_Static_assert(_Alignof(struct A_size) == 1, "record A_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A,b) == 64, "field A.b wrong bit offset");
#endif
_Static_assert(sizeof(A_) == 8, "record A_ wrong sizeof");
_Static_assert(_Alignof(A_) == 8, "record A_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A__alignment) == 16, "record A__alignment wrong sizeof");
_Static_assert(_Alignof(struct A__alignment) == 8, "record A__alignment wrong alignment");
_Static_assert(sizeof(struct A__packed) == 8, "record A__packed wrong sizeof");
_Static_assert(_Alignof(struct A__packed) == 1, "record A__packed wrong alignment");
_Static_assert(sizeof(struct A__required_alignment) == 9, "record A__required_alignment wrong sizeof");
_Static_assert(_Alignof(struct A__required_alignment) == 1, "record A__required_alignment wrong alignment");
_Static_assert(sizeof(struct A__size) == 10, "record A__size wrong sizeof");
_Static_assert(_Alignof(struct A__size) == 1, "record A__size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_,b) == 0, "field A_.b wrong bit offset");
#endif
_Static_assert(sizeof(B) == 16, "record B wrong sizeof");
_Static_assert(_Alignof(B) == 8, "record B wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 24, "record B_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_alignment) == 8, "record B_alignment wrong alignment");
_Static_assert(sizeof(struct B_packed) == 16, "record B_packed wrong sizeof");
_Static_assert(_Alignof(struct B_packed) == 1, "record B_packed wrong alignment");
_Static_assert(sizeof(struct B_required_alignment) == 17, "record B_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "record B_required_alignment wrong alignment");
_Static_assert(sizeof(struct B_size) == 18, "record B_size wrong sizeof");
_Static_assert(_Alignof(struct B_size) == 1, "record B_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B,b) == 64, "field B.b wrong bit offset");
#endif
_Static_assert(sizeof(B_) == 8, "record B_ wrong sizeof");
_Static_assert(_Alignof(B_) == 8, "record B_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B__alignment) == 16, "record B__alignment wrong sizeof");
_Static_assert(_Alignof(struct B__alignment) == 8, "record B__alignment wrong alignment");
_Static_assert(sizeof(struct B__packed) == 8, "record B__packed wrong sizeof");
_Static_assert(_Alignof(struct B__packed) == 1, "record B__packed wrong alignment");
_Static_assert(sizeof(struct B__required_alignment) == 9, "record B__required_alignment wrong sizeof");
_Static_assert(_Alignof(struct B__required_alignment) == 1, "record B__required_alignment wrong alignment");
_Static_assert(sizeof(struct B__size) == 10, "record B__size wrong sizeof");
_Static_assert(_Alignof(struct B__size) == 1, "record B__size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B_,b) == 0, "field B_.b wrong bit offset");
#endif
_Static_assert(sizeof(C) == 16, "record C wrong sizeof");
_Static_assert(_Alignof(C) == 8, "record C wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 24, "record C_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_alignment) == 8, "record C_alignment wrong alignment");
_Static_assert(sizeof(struct C_packed) == 16, "record C_packed wrong sizeof");
_Static_assert(_Alignof(struct C_packed) == 1, "record C_packed wrong alignment");
_Static_assert(sizeof(struct C_required_alignment) == 17, "record C_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "record C_required_alignment wrong alignment");
_Static_assert(sizeof(struct C_size) == 18, "record C_size wrong sizeof");
_Static_assert(_Alignof(struct C_size) == 1, "record C_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C,b) == 64, "field C.b wrong bit offset");
#endif
_Static_assert(sizeof(C_) == 1, "record C_ wrong sizeof");
_Static_assert(_Alignof(C_) == 1, "record C_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C__alignment) == 2, "record C__alignment wrong sizeof");
_Static_assert(_Alignof(struct C__alignment) == 1, "record C__alignment wrong alignment");
_Static_assert(sizeof(struct C__packed) == 1, "record C__packed wrong sizeof");
_Static_assert(_Alignof(struct C__packed) == 1, "record C__packed wrong alignment");
_Static_assert(sizeof(struct C__required_alignment) == 2, "record C__required_alignment wrong sizeof");
_Static_assert(_Alignof(struct C__required_alignment) == 1, "record C__required_alignment wrong alignment");
_Static_assert(sizeof(struct C__size) == 3, "record C__size wrong sizeof");
_Static_assert(_Alignof(struct C__size) == 1, "record C__size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C_,b) == 0, "field C_.b wrong bit offset");
#endif
_Static_assert(sizeof(D) == 16, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 1, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 17, "record D_alignment wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 1, "record D_alignment wrong alignment");
_Static_assert(sizeof(struct D_packed) == 16, "record D_packed wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D_packed wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 17, "record D_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D_required_alignment wrong alignment");
_Static_assert(sizeof(struct D_size) == 18, "record D_size wrong sizeof");
_Static_assert(_Alignof(struct D_size) == 1, "record D_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D,b) == 64, "field D.b wrong bit offset");
#endif
_Static_assert(sizeof(D_) == 1, "record D_ wrong sizeof");
_Static_assert(_Alignof(D_) == 1, "record D_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D__alignment) == 2, "record D__alignment wrong sizeof");
_Static_assert(_Alignof(struct D__alignment) == 1, "record D__alignment wrong alignment");
_Static_assert(sizeof(struct D__packed) == 1, "record D__packed wrong sizeof");
_Static_assert(_Alignof(struct D__packed) == 1, "record D__packed wrong alignment");
_Static_assert(sizeof(struct D__required_alignment) == 2, "record D__required_alignment wrong sizeof");
_Static_assert(_Alignof(struct D__required_alignment) == 1, "record D__required_alignment wrong alignment");
_Static_assert(sizeof(struct D__size) == 3, "record D__size wrong sizeof");
_Static_assert(_Alignof(struct D__size) == 1, "record D__size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D_,b) == 0, "field D_.b wrong bit offset");
#endif
_Static_assert(sizeof(E) == 16, "record E wrong sizeof");
_Static_assert(_Alignof(E) == 1, "record E wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 17, "record E_alignment wrong sizeof");
_Static_assert(_Alignof(struct E_alignment) == 1, "record E_alignment wrong alignment");
_Static_assert(sizeof(struct E_packed) == 16, "record E_packed wrong sizeof");
_Static_assert(_Alignof(struct E_packed) == 1, "record E_packed wrong alignment");
_Static_assert(sizeof(struct E_required_alignment) == 17, "record E_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "record E_required_alignment wrong alignment");
_Static_assert(sizeof(struct E_size) == 18, "record E_size wrong sizeof");
_Static_assert(_Alignof(struct E_size) == 1, "record E_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(E,b) == 64, "field E.b wrong bit offset");
#endif
_Static_assert(sizeof(E_) == 1, "record E_ wrong sizeof");
_Static_assert(_Alignof(E_) == 1, "record E_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E__alignment) == 2, "record E__alignment wrong sizeof");
_Static_assert(_Alignof(struct E__alignment) == 1, "record E__alignment wrong alignment");
_Static_assert(sizeof(struct E__packed) == 1, "record E__packed wrong sizeof");
_Static_assert(_Alignof(struct E__packed) == 1, "record E__packed wrong alignment");
_Static_assert(sizeof(struct E__required_alignment) == 2, "record E__required_alignment wrong sizeof");
_Static_assert(_Alignof(struct E__required_alignment) == 1, "record E__required_alignment wrong alignment");
_Static_assert(sizeof(struct E__size) == 3, "record E__size wrong sizeof");
_Static_assert(_Alignof(struct E__size) == 1, "record E__size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(E_,b) == 0, "field E_.b wrong bit offset");
#endif
_Static_assert(sizeof(F) == 256, "record F wrong sizeof");
_Static_assert(_Alignof(F) == 128, "record F wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 384, "record F_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_alignment) == 128, "record F_alignment wrong alignment");
_Static_assert(sizeof(struct F_packed) == 256, "record F_packed wrong sizeof");
_Static_assert(_Alignof(struct F_packed) == 1, "record F_packed wrong alignment");
_Static_assert(sizeof(struct F_required_alignment) == 257, "record F_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "record F_required_alignment wrong alignment");
_Static_assert(sizeof(struct F_size) == 258, "record F_size wrong sizeof");
_Static_assert(_Alignof(struct F_size) == 1, "record F_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F,b) == 1024, "field F.b wrong bit offset");
#endif
_Static_assert(sizeof(F_) == 1, "record F_ wrong sizeof");
_Static_assert(_Alignof(F_) == 1, "record F_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F__alignment) == 2, "record F__alignment wrong sizeof");
_Static_assert(_Alignof(struct F__alignment) == 1, "record F__alignment wrong alignment");
_Static_assert(sizeof(struct F__packed) == 1, "record F__packed wrong sizeof");
_Static_assert(_Alignof(struct F__packed) == 1, "record F__packed wrong alignment");
_Static_assert(sizeof(struct F__required_alignment) == 2, "record F__required_alignment wrong sizeof");
_Static_assert(_Alignof(struct F__required_alignment) == 1, "record F__required_alignment wrong alignment");
_Static_assert(sizeof(struct F__size) == 3, "record F__size wrong sizeof");
_Static_assert(_Alignof(struct F__size) == 1, "record F__size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F_,b) == 0, "field F_.b wrong bit offset");
#endif
_Static_assert(sizeof(G) == 256, "record G wrong sizeof");
_Static_assert(_Alignof(G) == 128, "record G wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 384, "record G_alignment wrong sizeof");
_Static_assert(_Alignof(struct G_alignment) == 128, "record G_alignment wrong alignment");
_Static_assert(sizeof(struct G_packed) == 256, "record G_packed wrong sizeof");
_Static_assert(_Alignof(struct G_packed) == 1, "record G_packed wrong alignment");
_Static_assert(sizeof(struct G_required_alignment) == 257, "record G_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "record G_required_alignment wrong alignment");
_Static_assert(sizeof(struct G_size) == 258, "record G_size wrong sizeof");
_Static_assert(_Alignof(struct G_size) == 1, "record G_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(G,b) == 1024, "field G.b wrong bit offset");
#endif
_Static_assert(sizeof(G_) == 8, "record G_ wrong sizeof");
_Static_assert(_Alignof(G_) == 8, "record G_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G__alignment) == 16, "record G__alignment wrong sizeof");
_Static_assert(_Alignof(struct G__alignment) == 8, "record G__alignment wrong alignment");
_Static_assert(sizeof(struct G__packed) == 8, "record G__packed wrong sizeof");
_Static_assert(_Alignof(struct G__packed) == 1, "record G__packed wrong alignment");
_Static_assert(sizeof(struct G__required_alignment) == 9, "record G__required_alignment wrong sizeof");
_Static_assert(_Alignof(struct G__required_alignment) == 1, "record G__required_alignment wrong alignment");
_Static_assert(sizeof(struct G__size) == 10, "record G__size wrong sizeof");
_Static_assert(_Alignof(struct G__size) == 1, "record G__size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(G_,b) == 0, "field G_.b wrong bit offset");
#endif
_Static_assert(sizeof(H) == 16, "record H wrong sizeof");
_Static_assert(_Alignof(H) == 1, "record H wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 17, "record H_alignment wrong sizeof");
_Static_assert(_Alignof(struct H_alignment) == 1, "record H_alignment wrong alignment");
_Static_assert(sizeof(struct H_packed) == 16, "record H_packed wrong sizeof");
_Static_assert(_Alignof(struct H_packed) == 1, "record H_packed wrong alignment");
_Static_assert(sizeof(struct H_required_alignment) == 17, "record H_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "record H_required_alignment wrong alignment");
_Static_assert(sizeof(struct H_size) == 18, "record H_size wrong sizeof");
_Static_assert(_Alignof(struct H_size) == 1, "record H_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(H,b) == 64, "field H.b wrong bit offset");
#endif
_Static_assert(sizeof(H_) == 1, "record H_ wrong sizeof");
_Static_assert(_Alignof(H_) == 1, "record H_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H__alignment) == 2, "record H__alignment wrong sizeof");
_Static_assert(_Alignof(struct H__alignment) == 1, "record H__alignment wrong alignment");
_Static_assert(sizeof(struct H__packed) == 1, "record H__packed wrong sizeof");
_Static_assert(_Alignof(struct H__packed) == 1, "record H__packed wrong alignment");
_Static_assert(sizeof(struct H__required_alignment) == 2, "record H__required_alignment wrong sizeof");
_Static_assert(_Alignof(struct H__required_alignment) == 1, "record H__required_alignment wrong alignment");
_Static_assert(sizeof(struct H__size) == 3, "record H__size wrong sizeof");
_Static_assert(_Alignof(struct H__size) == 1, "record H__size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(H_,b) == 0, "field H_.b wrong bit offset");
#endif
_Static_assert(sizeof(I) == 8, "record I wrong sizeof");
_Static_assert(_Alignof(I) == 128, "record I wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I_alignment) == 256, "record I_alignment wrong sizeof");
_Static_assert(_Alignof(struct I_alignment) == 128, "record I_alignment wrong alignment");
_Static_assert(sizeof(struct I_packed) == 8, "record I_packed wrong sizeof");
_Static_assert(_Alignof(struct I_packed) == 1, "record I_packed wrong alignment");
_Static_assert(sizeof(struct I_required_alignment) == 9, "record I_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct I_required_alignment) == 1, "record I_required_alignment wrong alignment");
_Static_assert(sizeof(struct I_size) == 10, "record I_size wrong sizeof");
_Static_assert(_Alignof(struct I_size) == 1, "record I_size wrong alignment");
#endif
_Static_assert(sizeof(J) == 128, "record J wrong sizeof");
_Static_assert(_Alignof(J) == 128, "record J wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J_alignment) == 256, "record J_alignment wrong sizeof");
_Static_assert(_Alignof(struct J_alignment) == 128, "record J_alignment wrong alignment");
_Static_assert(sizeof(struct J_packed) == 128, "record J_packed wrong sizeof");
_Static_assert(_Alignof(struct J_packed) == 1, "record J_packed wrong alignment");
_Static_assert(sizeof(struct J_required_alignment) == 129, "record J_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct J_required_alignment) == 1, "record J_required_alignment wrong alignment");
_Static_assert(sizeof(struct J_size) == 130, "record J_size wrong sizeof");
_Static_assert(_Alignof(struct J_size) == 1, "record J_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(J,b) == 64, "field J.b wrong bit offset");
#endif
_Static_assert(sizeof(J_) == 8, "record J_ wrong sizeof");
_Static_assert(_Alignof(J_) == 8, "record J_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J__alignment) == 16, "record J__alignment wrong sizeof");
_Static_assert(_Alignof(struct J__alignment) == 8, "record J__alignment wrong alignment");
_Static_assert(sizeof(struct J__packed) == 8, "record J__packed wrong sizeof");
_Static_assert(_Alignof(struct J__packed) == 1, "record J__packed wrong alignment");
_Static_assert(sizeof(struct J__required_alignment) == 9, "record J__required_alignment wrong sizeof");
_Static_assert(_Alignof(struct J__required_alignment) == 1, "record J__required_alignment wrong alignment");
_Static_assert(sizeof(struct J__size) == 10, "record J__size wrong sizeof");
_Static_assert(_Alignof(struct J__size) == 1, "record J__size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(J_,b) == 0, "field J_.b wrong bit offset");
#endif
#elif defined(MSP430_NONE_ELF) 
_Static_assert(sizeof(A) == 4, "record A wrong sizeof");
_Static_assert(_Alignof(A) == 2, "record A wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 6, "record A_alignment wrong sizeof");
_Static_assert(_Alignof(struct A_alignment) == 2, "record A_alignment wrong alignment");
_Static_assert(sizeof(struct A_packed) == 4, "record A_packed wrong sizeof");
_Static_assert(_Alignof(struct A_packed) == 1, "record A_packed wrong alignment");
_Static_assert(sizeof(struct A_required_alignment) == 5, "record A_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "record A_required_alignment wrong alignment");
_Static_assert(sizeof(struct A_size) == 6, "record A_size wrong sizeof");
_Static_assert(_Alignof(struct A_size) == 1, "record A_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A,b) == 16, "field A.b wrong bit offset");
#endif
_Static_assert(sizeof(A_) == 2, "record A_ wrong sizeof");
_Static_assert(_Alignof(A_) == 2, "record A_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A__alignment) == 4, "record A__alignment wrong sizeof");
_Static_assert(_Alignof(struct A__alignment) == 2, "record A__alignment wrong alignment");
_Static_assert(sizeof(struct A__packed) == 2, "record A__packed wrong sizeof");
_Static_assert(_Alignof(struct A__packed) == 1, "record A__packed wrong alignment");
_Static_assert(sizeof(struct A__required_alignment) == 3, "record A__required_alignment wrong sizeof");
_Static_assert(_Alignof(struct A__required_alignment) == 1, "record A__required_alignment wrong alignment");
_Static_assert(sizeof(struct A__size) == 4, "record A__size wrong sizeof");
_Static_assert(_Alignof(struct A__size) == 1, "record A__size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_,b) == 0, "field A_.b wrong bit offset");
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
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B,b) == 16, "field B.b wrong bit offset");
#endif
_Static_assert(sizeof(B_) == 2, "record B_ wrong sizeof");
_Static_assert(_Alignof(B_) == 2, "record B_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B__alignment) == 4, "record B__alignment wrong sizeof");
_Static_assert(_Alignof(struct B__alignment) == 2, "record B__alignment wrong alignment");
_Static_assert(sizeof(struct B__packed) == 2, "record B__packed wrong sizeof");
_Static_assert(_Alignof(struct B__packed) == 1, "record B__packed wrong alignment");
_Static_assert(sizeof(struct B__required_alignment) == 3, "record B__required_alignment wrong sizeof");
_Static_assert(_Alignof(struct B__required_alignment) == 1, "record B__required_alignment wrong alignment");
_Static_assert(sizeof(struct B__size) == 4, "record B__size wrong sizeof");
_Static_assert(_Alignof(struct B__size) == 1, "record B__size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B_,b) == 0, "field B_.b wrong bit offset");
#endif
_Static_assert(sizeof(C) == 3, "record C wrong sizeof");
_Static_assert(_Alignof(C) == 1, "record C wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 4, "record C_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_alignment) == 1, "record C_alignment wrong alignment");
_Static_assert(sizeof(struct C_packed) == 3, "record C_packed wrong sizeof");
_Static_assert(_Alignof(struct C_packed) == 1, "record C_packed wrong alignment");
_Static_assert(sizeof(struct C_required_alignment) == 4, "record C_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "record C_required_alignment wrong alignment");
_Static_assert(sizeof(struct C_size) == 5, "record C_size wrong sizeof");
_Static_assert(_Alignof(struct C_size) == 1, "record C_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C,b) == 16, "field C.b wrong bit offset");
#endif
_Static_assert(sizeof(C_) == 1, "record C_ wrong sizeof");
_Static_assert(_Alignof(C_) == 1, "record C_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C__alignment) == 2, "record C__alignment wrong sizeof");
_Static_assert(_Alignof(struct C__alignment) == 1, "record C__alignment wrong alignment");
_Static_assert(sizeof(struct C__packed) == 1, "record C__packed wrong sizeof");
_Static_assert(_Alignof(struct C__packed) == 1, "record C__packed wrong alignment");
_Static_assert(sizeof(struct C__required_alignment) == 2, "record C__required_alignment wrong sizeof");
_Static_assert(_Alignof(struct C__required_alignment) == 1, "record C__required_alignment wrong alignment");
_Static_assert(sizeof(struct C__size) == 3, "record C__size wrong sizeof");
_Static_assert(_Alignof(struct C__size) == 1, "record C__size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C_,b) == 0, "field C_.b wrong bit offset");
#endif
_Static_assert(sizeof(D) == 3, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 1, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 4, "record D_alignment wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 1, "record D_alignment wrong alignment");
_Static_assert(sizeof(struct D_packed) == 3, "record D_packed wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D_packed wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 4, "record D_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D_required_alignment wrong alignment");
_Static_assert(sizeof(struct D_size) == 5, "record D_size wrong sizeof");
_Static_assert(_Alignof(struct D_size) == 1, "record D_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D,b) == 16, "field D.b wrong bit offset");
#endif
_Static_assert(sizeof(D_) == 1, "record D_ wrong sizeof");
_Static_assert(_Alignof(D_) == 1, "record D_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D__alignment) == 2, "record D__alignment wrong sizeof");
_Static_assert(_Alignof(struct D__alignment) == 1, "record D__alignment wrong alignment");
_Static_assert(sizeof(struct D__packed) == 1, "record D__packed wrong sizeof");
_Static_assert(_Alignof(struct D__packed) == 1, "record D__packed wrong alignment");
_Static_assert(sizeof(struct D__required_alignment) == 2, "record D__required_alignment wrong sizeof");
_Static_assert(_Alignof(struct D__required_alignment) == 1, "record D__required_alignment wrong alignment");
_Static_assert(sizeof(struct D__size) == 3, "record D__size wrong sizeof");
_Static_assert(_Alignof(struct D__size) == 1, "record D__size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D_,b) == 0, "field D_.b wrong bit offset");
#endif
_Static_assert(sizeof(E) == 129, "record E wrong sizeof");
_Static_assert(_Alignof(E) == 1, "record E wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 130, "record E_alignment wrong sizeof");
_Static_assert(_Alignof(struct E_alignment) == 1, "record E_alignment wrong alignment");
_Static_assert(sizeof(struct E_packed) == 129, "record E_packed wrong sizeof");
_Static_assert(_Alignof(struct E_packed) == 1, "record E_packed wrong alignment");
_Static_assert(sizeof(struct E_required_alignment) == 130, "record E_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "record E_required_alignment wrong alignment");
_Static_assert(sizeof(struct E_size) == 131, "record E_size wrong sizeof");
_Static_assert(_Alignof(struct E_size) == 1, "record E_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(E,b) == 1024, "field E.b wrong bit offset");
#endif
_Static_assert(sizeof(E_) == 1, "record E_ wrong sizeof");
_Static_assert(_Alignof(E_) == 1, "record E_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E__alignment) == 2, "record E__alignment wrong sizeof");
_Static_assert(_Alignof(struct E__alignment) == 1, "record E__alignment wrong alignment");
_Static_assert(sizeof(struct E__packed) == 1, "record E__packed wrong sizeof");
_Static_assert(_Alignof(struct E__packed) == 1, "record E__packed wrong alignment");
_Static_assert(sizeof(struct E__required_alignment) == 2, "record E__required_alignment wrong sizeof");
_Static_assert(_Alignof(struct E__required_alignment) == 1, "record E__required_alignment wrong alignment");
_Static_assert(sizeof(struct E__size) == 3, "record E__size wrong sizeof");
_Static_assert(_Alignof(struct E__size) == 1, "record E__size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(E_,b) == 0, "field E_.b wrong bit offset");
#endif
_Static_assert(sizeof(F) == 129, "record F wrong sizeof");
_Static_assert(_Alignof(F) == 1, "record F wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 130, "record F_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_alignment) == 1, "record F_alignment wrong alignment");
_Static_assert(sizeof(struct F_packed) == 129, "record F_packed wrong sizeof");
_Static_assert(_Alignof(struct F_packed) == 1, "record F_packed wrong alignment");
_Static_assert(sizeof(struct F_required_alignment) == 130, "record F_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "record F_required_alignment wrong alignment");
_Static_assert(sizeof(struct F_size) == 131, "record F_size wrong sizeof");
_Static_assert(_Alignof(struct F_size) == 1, "record F_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F,b) == 1024, "field F.b wrong bit offset");
#endif
_Static_assert(sizeof(F_) == 1, "record F_ wrong sizeof");
_Static_assert(_Alignof(F_) == 1, "record F_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F__alignment) == 2, "record F__alignment wrong sizeof");
_Static_assert(_Alignof(struct F__alignment) == 1, "record F__alignment wrong alignment");
_Static_assert(sizeof(struct F__packed) == 1, "record F__packed wrong sizeof");
_Static_assert(_Alignof(struct F__packed) == 1, "record F__packed wrong alignment");
_Static_assert(sizeof(struct F__required_alignment) == 2, "record F__required_alignment wrong sizeof");
_Static_assert(_Alignof(struct F__required_alignment) == 1, "record F__required_alignment wrong alignment");
_Static_assert(sizeof(struct F__size) == 3, "record F__size wrong sizeof");
_Static_assert(_Alignof(struct F__size) == 1, "record F__size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F_,b) == 0, "field F_.b wrong bit offset");
#endif
_Static_assert(sizeof(G) == 130, "record G wrong sizeof");
_Static_assert(_Alignof(G) == 2, "record G wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 132, "record G_alignment wrong sizeof");
_Static_assert(_Alignof(struct G_alignment) == 2, "record G_alignment wrong alignment");
_Static_assert(sizeof(struct G_packed) == 130, "record G_packed wrong sizeof");
_Static_assert(_Alignof(struct G_packed) == 1, "record G_packed wrong alignment");
_Static_assert(sizeof(struct G_required_alignment) == 131, "record G_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "record G_required_alignment wrong alignment");
_Static_assert(sizeof(struct G_size) == 132, "record G_size wrong sizeof");
_Static_assert(_Alignof(struct G_size) == 1, "record G_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(G,b) == 1024, "field G.b wrong bit offset");
#endif
_Static_assert(sizeof(G_) == 2, "record G_ wrong sizeof");
_Static_assert(_Alignof(G_) == 2, "record G_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G__alignment) == 4, "record G__alignment wrong sizeof");
_Static_assert(_Alignof(struct G__alignment) == 2, "record G__alignment wrong alignment");
_Static_assert(sizeof(struct G__packed) == 2, "record G__packed wrong sizeof");
_Static_assert(_Alignof(struct G__packed) == 1, "record G__packed wrong alignment");
_Static_assert(sizeof(struct G__required_alignment) == 3, "record G__required_alignment wrong sizeof");
_Static_assert(_Alignof(struct G__required_alignment) == 1, "record G__required_alignment wrong alignment");
_Static_assert(sizeof(struct G__size) == 4, "record G__size wrong sizeof");
_Static_assert(_Alignof(struct G__size) == 1, "record G__size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(G_,b) == 0, "field G_.b wrong bit offset");
#endif
_Static_assert(sizeof(H) == 129, "record H wrong sizeof");
_Static_assert(_Alignof(H) == 1, "record H wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 130, "record H_alignment wrong sizeof");
_Static_assert(_Alignof(struct H_alignment) == 1, "record H_alignment wrong alignment");
_Static_assert(sizeof(struct H_packed) == 129, "record H_packed wrong sizeof");
_Static_assert(_Alignof(struct H_packed) == 1, "record H_packed wrong alignment");
_Static_assert(sizeof(struct H_required_alignment) == 130, "record H_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "record H_required_alignment wrong alignment");
_Static_assert(sizeof(struct H_size) == 131, "record H_size wrong sizeof");
_Static_assert(_Alignof(struct H_size) == 1, "record H_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(H,b) == 1024, "field H.b wrong bit offset");
#endif
_Static_assert(sizeof(H_) == 1, "record H_ wrong sizeof");
_Static_assert(_Alignof(H_) == 1, "record H_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H__alignment) == 2, "record H__alignment wrong sizeof");
_Static_assert(_Alignof(struct H__alignment) == 1, "record H__alignment wrong alignment");
_Static_assert(sizeof(struct H__packed) == 1, "record H__packed wrong sizeof");
_Static_assert(_Alignof(struct H__packed) == 1, "record H__packed wrong alignment");
_Static_assert(sizeof(struct H__required_alignment) == 2, "record H__required_alignment wrong sizeof");
_Static_assert(_Alignof(struct H__required_alignment) == 1, "record H__required_alignment wrong alignment");
_Static_assert(sizeof(struct H__size) == 3, "record H__size wrong sizeof");
_Static_assert(_Alignof(struct H__size) == 1, "record H__size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(H_,b) == 0, "field H_.b wrong bit offset");
#endif
_Static_assert(sizeof(I) == 8, "record I wrong sizeof");
_Static_assert(_Alignof(I) == 128, "record I wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I_alignment) == 256, "record I_alignment wrong sizeof");
_Static_assert(_Alignof(struct I_alignment) == 128, "record I_alignment wrong alignment");
_Static_assert(sizeof(struct I_packed) == 8, "record I_packed wrong sizeof");
_Static_assert(_Alignof(struct I_packed) == 1, "record I_packed wrong alignment");
_Static_assert(sizeof(struct I_required_alignment) == 9, "record I_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct I_required_alignment) == 1, "record I_required_alignment wrong alignment");
_Static_assert(sizeof(struct I_size) == 10, "record I_size wrong sizeof");
_Static_assert(_Alignof(struct I_size) == 1, "record I_size wrong alignment");
#endif
_Static_assert(sizeof(J) == 130, "record J wrong sizeof");
_Static_assert(_Alignof(J) == 2, "record J wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J_alignment) == 132, "record J_alignment wrong sizeof");
_Static_assert(_Alignof(struct J_alignment) == 2, "record J_alignment wrong alignment");
_Static_assert(sizeof(struct J_packed) == 130, "record J_packed wrong sizeof");
_Static_assert(_Alignof(struct J_packed) == 1, "record J_packed wrong alignment");
_Static_assert(sizeof(struct J_required_alignment) == 131, "record J_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct J_required_alignment) == 1, "record J_required_alignment wrong alignment");
_Static_assert(sizeof(struct J_size) == 132, "record J_size wrong sizeof");
_Static_assert(_Alignof(struct J_size) == 1, "record J_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(J,b) == 1024, "field J.b wrong bit offset");
#endif
_Static_assert(sizeof(J_) == 2, "record J_ wrong sizeof");
_Static_assert(_Alignof(J_) == 2, "record J_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J__alignment) == 4, "record J__alignment wrong sizeof");
_Static_assert(_Alignof(struct J__alignment) == 2, "record J__alignment wrong alignment");
_Static_assert(sizeof(struct J__packed) == 2, "record J__packed wrong sizeof");
_Static_assert(_Alignof(struct J__packed) == 1, "record J__packed wrong alignment");
_Static_assert(sizeof(struct J__required_alignment) == 3, "record J__required_alignment wrong sizeof");
_Static_assert(_Alignof(struct J__required_alignment) == 1, "record J__required_alignment wrong alignment");
_Static_assert(sizeof(struct J__size) == 4, "record J__size wrong sizeof");
_Static_assert(_Alignof(struct J__size) == 1, "record J__size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(J_,b) == 0, "field J_.b wrong bit offset");
#endif
#endif
