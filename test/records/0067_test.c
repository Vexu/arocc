// SPDX-License-Identifier: GPL-3.0-or-later

// This test file is auto-generated. do not edit.
// This file is a derivative work from the test files found// in this repo : https://github.com/mahkoh/repr-c
// and is under the same licence as the original work.

typedef struct {
    int x;
    long y;
} __attribute__((packed)) A1;
A1 var1;
struct A1_alignment {
    char a;
    A1 b;
};
struct A1_alignment var2;
#pragma pack(1)
struct A1_packed {
    A1 a;
};
#pragma pack()
struct A1_required_alignment {
    char a;
    struct A1_packed b;
};
struct A1_required_alignment var3;
struct A1_size {
    char a[sizeof(A1)+1];
    char b;
};
struct A1_size var4;

typedef struct {
    int x __attribute__((packed));
    long y __attribute__((packed));
} A2;
A2 var5;
struct A2_alignment {
    char a;
    A2 b;
};
struct A2_alignment var6;
#pragma pack(1)
struct A2_packed {
    A2 a;
};
#pragma pack()
struct A2_required_alignment {
    char a;
    struct A2_packed b;
};
struct A2_required_alignment var7;
struct A2_size {
    char a[sizeof(A2)+1];
    char b;
};
struct A2_size var8;

typedef union {
    int x;
    long y;
} __attribute__((packed)) B1;
B1 var9;
struct B1_alignment {
    char a;
    B1 b;
};
struct B1_alignment var10;
#pragma pack(1)
struct B1_packed {
    B1 a;
};
#pragma pack()
struct B1_required_alignment {
    char a;
    struct B1_packed b;
};
struct B1_required_alignment var11;
struct B1_size {
    char a[sizeof(B1)+1];
    char b;
};
struct B1_size var12;

typedef union {
    int x __attribute__((packed));
    long y __attribute__((packed));
} B2;
B2 var13;
struct B2_alignment {
    char a;
    B2 b;
};
struct B2_alignment var14;
#pragma pack(1)
struct B2_packed {
    B2 a;
};
#pragma pack()
struct B2_required_alignment {
    char a;
    struct B2_packed b;
};
struct B2_required_alignment var15;
struct B2_size {
    char a[sizeof(B2)+1];
    char b;
};
struct B2_size var16;

typedef struct {
    int x:1;
    long y;
} __attribute__((packed)) C1;
C1 var17;
struct C1_alignment {
    char a;
    C1 b;
};
struct C1_alignment var18;
#pragma pack(1)
struct C1_packed {
    C1 a;
};
#pragma pack()
struct C1_required_alignment {
    char a;
    struct C1_packed b;
};
struct C1_required_alignment var19;
struct C1_size {
    char a[sizeof(C1)+1];
    char b;
};
struct C1_size var20;

typedef struct {
    int x:1 __attribute__((packed));
    long y __attribute__((packed));
} C2;
C2 var21;
struct C2_alignment {
    char a;
    C2 b;
};
struct C2_alignment var22;
#pragma pack(1)
struct C2_packed {
    C2 a;
};
#pragma pack()
struct C2_required_alignment {
    char a;
    struct C2_packed b;
};
struct C2_required_alignment var23;
struct C2_size {
    char a[sizeof(C2)+1];
    char b;
};
struct C2_size var24;

typedef union {
    int x:1;
    long y;
} __attribute__((packed)) D1;
D1 var25;
struct D1_alignment {
    char a;
    D1 b;
};
struct D1_alignment var26;
#pragma pack(1)
struct D1_packed {
    D1 a;
};
#pragma pack()
struct D1_required_alignment {
    char a;
    struct D1_packed b;
};
struct D1_required_alignment var27;
struct D1_size {
    char a[sizeof(D1)+1];
    char b;
};
struct D1_size var28;

typedef union {
    int x:1 __attribute__((packed));
    long y __attribute__((packed));
} D2;
D2 var29;
struct D2_alignment {
    char a;
    D2 b;
};
struct D2_alignment var30;
#pragma pack(1)
struct D2_packed {
    D2 a;
};
#pragma pack()
struct D2_required_alignment {
    char a;
    struct D2_packed b;
};
struct D2_required_alignment var31;
struct D2_size {
    char a[sizeof(D2)+1];
    char b;
};
struct D2_size var32;

typedef struct {
    int:0;
    long y;
} __attribute__((packed)) E1;
E1 var33;
struct E1_alignment {
    char a;
    E1 b;
};
struct E1_alignment var34;
#pragma pack(1)
struct E1_packed {
    E1 a;
};
#pragma pack()
struct E1_required_alignment {
    char a;
    struct E1_packed b;
};
struct E1_required_alignment var35;
struct E1_size {
    char a[sizeof(E1)+1];
    char b;
};
struct E1_size var36;

typedef struct {
    int:0 __attribute__((packed));
    long y __attribute__((packed));
} E2;
E2 var37;
struct E2_alignment {
    char a;
    E2 b;
};
struct E2_alignment var38;
#pragma pack(1)
struct E2_packed {
    E2 a;
};
#pragma pack()
struct E2_required_alignment {
    char a;
    struct E2_packed b;
};
struct E2_required_alignment var39;
struct E2_size {
    char a[sizeof(E2)+1];
    char b;
};
struct E2_size var40;

typedef union {
    int:0;
    long y;
} __attribute__((packed)) F1;
F1 var41;
struct F1_alignment {
    char a;
    F1 b;
};
struct F1_alignment var42;
#pragma pack(1)
struct F1_packed {
    F1 a;
};
#pragma pack()
struct F1_required_alignment {
    char a;
    struct F1_packed b;
};
struct F1_required_alignment var43;
struct F1_size {
    char a[sizeof(F1)+1];
    char b;
};
struct F1_size var44;

typedef union {
    int:0 __attribute__((packed));
    long y __attribute__((packed));
} F2;
F2 var45;
struct F2_alignment {
    char a;
    F2 b;
};
struct F2_alignment var46;
#pragma pack(1)
struct F2_packed {
    F2 a;
};
#pragma pack()
struct F2_required_alignment {
    char a;
    struct F2_packed b;
};
struct F2_required_alignment var47;
struct F2_size {
    char a[sizeof(F2)+1];
    char b;
};
struct F2_size var48;


#if defined(AARCH64_APPLE_MACOSX) ||  defined(ARM64_APPLE_IOS) ||  defined(ARM64_APPLE_IOS_MACABI) ||  defined(ARM64_APPLE_TVOS) ||  \
 defined(MIPS64EL_UNKNOWN_LINUX_GNUABI64) ||  defined(MIPS64EL_UNKNOWN_LINUX_MUSL) ||  defined(MIPS64_UNKNOWN_LINUX_GNUABI64) ||  \
 defined(MIPS64_UNKNOWN_LINUX_MUSL) ||  defined(MIPSISA64R6EL_UNKNOWN_LINUX_GNUABI64) ||  defined(MIPSISA64R6_UNKNOWN_LINUX_GNUABI64) ||  \
 defined(POWERPC64LE_UNKNOWN_LINUX_GNU) ||  defined(POWERPC64LE_UNKNOWN_LINUX_MUSL) ||  defined(POWERPC64_UNKNOWN_FREEBSD) ||  defined(POWERPC64_UNKNOWN_LINUX_GNU) ||  \
 defined(POWERPC64_UNKNOWN_LINUX_MUSL) ||  defined(RISCV64) ||  defined(RISCV64_UNKNOWN_LINUX_GNU) ||  defined(S390X_UNKNOWN_LINUX_GNU) ||  \
 defined(SPARC64_UNKNOWN_LINUX_GNU) ||  defined(SPARC64_UNKNOWN_NETBSD) ||  defined(SPARC64_UNKNOWN_OPENBSD) ||  defined(SPARCV9_SUN_SOLARIS) ||  \
 defined(X8664_APPLE_IOS_MACABI) ||  defined(X8664_APPLE_IOS) ||  defined(X8664_APPLE_MACOSX) ||  defined(X8664_APPLE_TVOS) ||  defined(X8664_ELF) ||  \
 defined(X8664_FUCHSIA) ||  defined(X8664_LINUX_ANDROID) ||  defined(X8664_PC_SOLARIS) ||  defined(X8664_RUMPRUN_NETBSD) ||  defined(X8664_UNKNOWN_DRAGONFLY) ||  \
 defined(X8664_UNKNOWN_FREEBSD) ||  defined(X8664_UNKNOWN_HAIKU) ||  defined(X8664_UNKNOWN_HERMIT) ||  defined(X8664_UNKNOWN_L4RE_UCLIBC) ||  \
 defined(X8664_UNKNOWN_LINUX_GNU) ||  defined(X8664_UNKNOWN_LINUX_MUSL) ||  defined(X8664_UNKNOWN_NETBSD) ||  defined(X8664_UNKNOWN_OPENBSD) ||  \
 defined(X8664_UNKNOWN_REDOX) 
_Static_assert(sizeof(A1) == 12, "record A1 wrong sizeof");
_Static_assert(_Alignof(A1) == 1, "record A1 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A1_alignment) == 13, "record A1 wrong sizeof");
_Static_assert(_Alignof(struct A1_alignment) == 1, "record A1 wrong alignment");
_Static_assert(sizeof(struct A1_packed) == 12, "record A1 wrong sizeof");
_Static_assert(_Alignof(struct A1_packed) == 1, "record A1 wrong alignment");
_Static_assert(sizeof(struct A1_required_alignment) == 13, "record A1 wrong sizeof");
_Static_assert(_Alignof(struct A1_required_alignment) == 1, "record A1 wrong alignment");
_Static_assert(sizeof(struct A1_size) == 14, "record A1 wrong sizeof");
_Static_assert(_Alignof(struct A1_size) == 1, "record A1 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A1,y) == 32, "field A1.y wrong bit offset");
#endif
_Static_assert(sizeof(A2) == 12, "record A2 wrong sizeof");
_Static_assert(_Alignof(A2) == 1, "record A2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A2_alignment) == 13, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_alignment) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_packed) == 12, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_packed) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_required_alignment) == 13, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_required_alignment) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_size) == 14, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_size) == 1, "record A2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A2,y) == 32, "field A2.y wrong bit offset");
#endif
_Static_assert(sizeof(B1) == 8, "record B1 wrong sizeof");
_Static_assert(_Alignof(B1) == 1, "record B1 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B1_alignment) == 9, "record B1 wrong sizeof");
_Static_assert(_Alignof(struct B1_alignment) == 1, "record B1 wrong alignment");
_Static_assert(sizeof(struct B1_packed) == 8, "record B1 wrong sizeof");
_Static_assert(_Alignof(struct B1_packed) == 1, "record B1 wrong alignment");
_Static_assert(sizeof(struct B1_required_alignment) == 9, "record B1 wrong sizeof");
_Static_assert(_Alignof(struct B1_required_alignment) == 1, "record B1 wrong alignment");
_Static_assert(sizeof(struct B1_size) == 10, "record B1 wrong sizeof");
_Static_assert(_Alignof(struct B1_size) == 1, "record B1 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B1,y) == 0, "field B1.y wrong bit offset");
#endif
_Static_assert(sizeof(B2) == 8, "record B2 wrong sizeof");
_Static_assert(_Alignof(B2) == 1, "record B2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B2_alignment) == 9, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_alignment) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_packed) == 8, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_packed) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_required_alignment) == 9, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_required_alignment) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_size) == 10, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_size) == 1, "record B2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B2,y) == 0, "field B2.y wrong bit offset");
#endif
_Static_assert(sizeof(C1) == 9, "record C1 wrong sizeof");
_Static_assert(_Alignof(C1) == 1, "record C1 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C1_alignment) == 10, "record C1 wrong sizeof");
_Static_assert(_Alignof(struct C1_alignment) == 1, "record C1 wrong alignment");
_Static_assert(sizeof(struct C1_packed) == 9, "record C1 wrong sizeof");
_Static_assert(_Alignof(struct C1_packed) == 1, "record C1 wrong alignment");
_Static_assert(sizeof(struct C1_required_alignment) == 10, "record C1 wrong sizeof");
_Static_assert(_Alignof(struct C1_required_alignment) == 1, "record C1 wrong alignment");
_Static_assert(sizeof(struct C1_size) == 11, "record C1 wrong sizeof");
_Static_assert(_Alignof(struct C1_size) == 1, "record C1 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C1,y) == 8, "field C1.y wrong bit offset");
#endif
_Static_assert(sizeof(C2) == 9, "record C2 wrong sizeof");
_Static_assert(_Alignof(C2) == 1, "record C2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C2_alignment) == 10, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_alignment) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_packed) == 9, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_packed) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_required_alignment) == 10, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_required_alignment) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_size) == 11, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_size) == 1, "record C2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C2,y) == 8, "field C2.y wrong bit offset");
#endif
_Static_assert(sizeof(D1) == 8, "record D1 wrong sizeof");
_Static_assert(_Alignof(D1) == 1, "record D1 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D1_alignment) == 9, "record D1 wrong sizeof");
_Static_assert(_Alignof(struct D1_alignment) == 1, "record D1 wrong alignment");
_Static_assert(sizeof(struct D1_packed) == 8, "record D1 wrong sizeof");
_Static_assert(_Alignof(struct D1_packed) == 1, "record D1 wrong alignment");
_Static_assert(sizeof(struct D1_required_alignment) == 9, "record D1 wrong sizeof");
_Static_assert(_Alignof(struct D1_required_alignment) == 1, "record D1 wrong alignment");
_Static_assert(sizeof(struct D1_size) == 10, "record D1 wrong sizeof");
_Static_assert(_Alignof(struct D1_size) == 1, "record D1 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D1,y) == 0, "field D1.y wrong bit offset");
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
_Static_assert(__builtin_bitoffsetof(D2,y) == 0, "field D2.y wrong bit offset");
#endif
_Static_assert(sizeof(E1) == 8, "record E1 wrong sizeof");
_Static_assert(_Alignof(E1) == 1, "record E1 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E1_alignment) == 9, "record E1 wrong sizeof");
_Static_assert(_Alignof(struct E1_alignment) == 1, "record E1 wrong alignment");
_Static_assert(sizeof(struct E1_packed) == 8, "record E1 wrong sizeof");
_Static_assert(_Alignof(struct E1_packed) == 1, "record E1 wrong alignment");
_Static_assert(sizeof(struct E1_required_alignment) == 9, "record E1 wrong sizeof");
_Static_assert(_Alignof(struct E1_required_alignment) == 1, "record E1 wrong alignment");
_Static_assert(sizeof(struct E1_size) == 10, "record E1 wrong sizeof");
_Static_assert(_Alignof(struct E1_size) == 1, "record E1 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(E1,y) == 0, "field E1.y wrong bit offset");
#endif
_Static_assert(sizeof(E2) == 8, "record E2 wrong sizeof");
_Static_assert(_Alignof(E2) == 1, "record E2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E2_alignment) == 9, "record E2 wrong sizeof");
_Static_assert(_Alignof(struct E2_alignment) == 1, "record E2 wrong alignment");
_Static_assert(sizeof(struct E2_packed) == 8, "record E2 wrong sizeof");
_Static_assert(_Alignof(struct E2_packed) == 1, "record E2 wrong alignment");
_Static_assert(sizeof(struct E2_required_alignment) == 9, "record E2 wrong sizeof");
_Static_assert(_Alignof(struct E2_required_alignment) == 1, "record E2 wrong alignment");
_Static_assert(sizeof(struct E2_size) == 10, "record E2 wrong sizeof");
_Static_assert(_Alignof(struct E2_size) == 1, "record E2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(E2,y) == 0, "field E2.y wrong bit offset");
#endif
_Static_assert(sizeof(F1) == 8, "record F1 wrong sizeof");
_Static_assert(_Alignof(F1) == 1, "record F1 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F1_alignment) == 9, "record F1 wrong sizeof");
_Static_assert(_Alignof(struct F1_alignment) == 1, "record F1 wrong alignment");
_Static_assert(sizeof(struct F1_packed) == 8, "record F1 wrong sizeof");
_Static_assert(_Alignof(struct F1_packed) == 1, "record F1 wrong alignment");
_Static_assert(sizeof(struct F1_required_alignment) == 9, "record F1 wrong sizeof");
_Static_assert(_Alignof(struct F1_required_alignment) == 1, "record F1 wrong alignment");
_Static_assert(sizeof(struct F1_size) == 10, "record F1 wrong sizeof");
_Static_assert(_Alignof(struct F1_size) == 1, "record F1 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F1,y) == 0, "field F1.y wrong bit offset");
#endif
_Static_assert(sizeof(F2) == 8, "record F2 wrong sizeof");
_Static_assert(_Alignof(F2) == 1, "record F2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F2_alignment) == 9, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_alignment) == 1, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_packed) == 8, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_packed) == 1, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_required_alignment) == 9, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_required_alignment) == 1, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_size) == 10, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_size) == 1, "record F2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F2,y) == 0, "field F2.y wrong bit offset");
#endif
#elif defined(AARCH64_FUCHSIA) ||  defined(AARCH64_LINUX_ANDROID) ||  defined(AARCH64_UNKNOWN_FREEBSD) ||  defined(AARCH64_UNKNOWN_HERMIT) ||  \
 defined(AARCH64_UNKNOWN_LINUX_GNU) ||  defined(AARCH64_UNKNOWN_LINUX_MUSL) ||  defined(AARCH64_UNKNOWN_NETBSD) ||  defined(AARCH64_UNKNOWN_NONE) ||  \
 defined(AARCH64_UNKNOWN_OPENBSD) ||  defined(AARCH64_UNKNOWN_REDOX) 
_Static_assert(sizeof(A1) == 12, "record A1 wrong sizeof");
_Static_assert(_Alignof(A1) == 1, "record A1 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A1_alignment) == 13, "record A1 wrong sizeof");
_Static_assert(_Alignof(struct A1_alignment) == 1, "record A1 wrong alignment");
_Static_assert(sizeof(struct A1_packed) == 12, "record A1 wrong sizeof");
_Static_assert(_Alignof(struct A1_packed) == 1, "record A1 wrong alignment");
_Static_assert(sizeof(struct A1_required_alignment) == 13, "record A1 wrong sizeof");
_Static_assert(_Alignof(struct A1_required_alignment) == 1, "record A1 wrong alignment");
_Static_assert(sizeof(struct A1_size) == 14, "record A1 wrong sizeof");
_Static_assert(_Alignof(struct A1_size) == 1, "record A1 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A1,y) == 32, "field A1.y wrong bit offset");
#endif
_Static_assert(sizeof(A2) == 12, "record A2 wrong sizeof");
_Static_assert(_Alignof(A2) == 1, "record A2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A2_alignment) == 13, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_alignment) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_packed) == 12, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_packed) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_required_alignment) == 13, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_required_alignment) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_size) == 14, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_size) == 1, "record A2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A2,y) == 32, "field A2.y wrong bit offset");
#endif
_Static_assert(sizeof(B1) == 8, "record B1 wrong sizeof");
_Static_assert(_Alignof(B1) == 1, "record B1 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B1_alignment) == 9, "record B1 wrong sizeof");
_Static_assert(_Alignof(struct B1_alignment) == 1, "record B1 wrong alignment");
_Static_assert(sizeof(struct B1_packed) == 8, "record B1 wrong sizeof");
_Static_assert(_Alignof(struct B1_packed) == 1, "record B1 wrong alignment");
_Static_assert(sizeof(struct B1_required_alignment) == 9, "record B1 wrong sizeof");
_Static_assert(_Alignof(struct B1_required_alignment) == 1, "record B1 wrong alignment");
_Static_assert(sizeof(struct B1_size) == 10, "record B1 wrong sizeof");
_Static_assert(_Alignof(struct B1_size) == 1, "record B1 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B1,y) == 0, "field B1.y wrong bit offset");
#endif
_Static_assert(sizeof(B2) == 8, "record B2 wrong sizeof");
_Static_assert(_Alignof(B2) == 1, "record B2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B2_alignment) == 9, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_alignment) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_packed) == 8, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_packed) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_required_alignment) == 9, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_required_alignment) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_size) == 10, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_size) == 1, "record B2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B2,y) == 0, "field B2.y wrong bit offset");
#endif
_Static_assert(sizeof(C1) == 9, "record C1 wrong sizeof");
_Static_assert(_Alignof(C1) == 1, "record C1 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C1_alignment) == 10, "record C1 wrong sizeof");
_Static_assert(_Alignof(struct C1_alignment) == 1, "record C1 wrong alignment");
_Static_assert(sizeof(struct C1_packed) == 9, "record C1 wrong sizeof");
_Static_assert(_Alignof(struct C1_packed) == 1, "record C1 wrong alignment");
_Static_assert(sizeof(struct C1_required_alignment) == 10, "record C1 wrong sizeof");
_Static_assert(_Alignof(struct C1_required_alignment) == 1, "record C1 wrong alignment");
_Static_assert(sizeof(struct C1_size) == 11, "record C1 wrong sizeof");
_Static_assert(_Alignof(struct C1_size) == 1, "record C1 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C1,y) == 8, "field C1.y wrong bit offset");
#endif
_Static_assert(sizeof(C2) == 9, "record C2 wrong sizeof");
_Static_assert(_Alignof(C2) == 1, "record C2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C2_alignment) == 10, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_alignment) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_packed) == 9, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_packed) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_required_alignment) == 10, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_required_alignment) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_size) == 11, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_size) == 1, "record C2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C2,y) == 8, "field C2.y wrong bit offset");
#endif
_Static_assert(sizeof(D1) == 8, "record D1 wrong sizeof");
_Static_assert(_Alignof(D1) == 1, "record D1 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D1_alignment) == 9, "record D1 wrong sizeof");
_Static_assert(_Alignof(struct D1_alignment) == 1, "record D1 wrong alignment");
_Static_assert(sizeof(struct D1_packed) == 8, "record D1 wrong sizeof");
_Static_assert(_Alignof(struct D1_packed) == 1, "record D1 wrong alignment");
_Static_assert(sizeof(struct D1_required_alignment) == 9, "record D1 wrong sizeof");
_Static_assert(_Alignof(struct D1_required_alignment) == 1, "record D1 wrong alignment");
_Static_assert(sizeof(struct D1_size) == 10, "record D1 wrong sizeof");
_Static_assert(_Alignof(struct D1_size) == 1, "record D1 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D1,y) == 0, "field D1.y wrong bit offset");
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
_Static_assert(__builtin_bitoffsetof(D2,y) == 0, "field D2.y wrong bit offset");
#endif
_Static_assert(sizeof(E1) == 8, "record E1 wrong sizeof");
_Static_assert(_Alignof(E1) == 4, "record E1 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E1_alignment) == 12, "record E1 wrong sizeof");
_Static_assert(_Alignof(struct E1_alignment) == 4, "record E1 wrong alignment");
_Static_assert(sizeof(struct E1_packed) == 8, "record E1 wrong sizeof");
_Static_assert(_Alignof(struct E1_packed) == 1, "record E1 wrong alignment");
_Static_assert(sizeof(struct E1_required_alignment) == 9, "record E1 wrong sizeof");
_Static_assert(_Alignof(struct E1_required_alignment) == 1, "record E1 wrong alignment");
_Static_assert(sizeof(struct E1_size) == 10, "record E1 wrong sizeof");
_Static_assert(_Alignof(struct E1_size) == 1, "record E1 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(E1,y) == 0, "field E1.y wrong bit offset");
#endif
_Static_assert(sizeof(E2) == 8, "record E2 wrong sizeof");
_Static_assert(_Alignof(E2) == 4, "record E2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E2_alignment) == 12, "record E2 wrong sizeof");
_Static_assert(_Alignof(struct E2_alignment) == 4, "record E2 wrong alignment");
_Static_assert(sizeof(struct E2_packed) == 8, "record E2 wrong sizeof");
_Static_assert(_Alignof(struct E2_packed) == 1, "record E2 wrong alignment");
_Static_assert(sizeof(struct E2_required_alignment) == 9, "record E2 wrong sizeof");
_Static_assert(_Alignof(struct E2_required_alignment) == 1, "record E2 wrong alignment");
_Static_assert(sizeof(struct E2_size) == 10, "record E2 wrong sizeof");
_Static_assert(_Alignof(struct E2_size) == 1, "record E2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(E2,y) == 0, "field E2.y wrong bit offset");
#endif
_Static_assert(sizeof(F1) == 8, "record F1 wrong sizeof");
_Static_assert(_Alignof(F1) == 4, "record F1 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F1_alignment) == 12, "record F1 wrong sizeof");
_Static_assert(_Alignof(struct F1_alignment) == 4, "record F1 wrong alignment");
_Static_assert(sizeof(struct F1_packed) == 8, "record F1 wrong sizeof");
_Static_assert(_Alignof(struct F1_packed) == 1, "record F1 wrong alignment");
_Static_assert(sizeof(struct F1_required_alignment) == 9, "record F1 wrong sizeof");
_Static_assert(_Alignof(struct F1_required_alignment) == 1, "record F1 wrong alignment");
_Static_assert(sizeof(struct F1_size) == 10, "record F1 wrong sizeof");
_Static_assert(_Alignof(struct F1_size) == 1, "record F1 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F1,y) == 0, "field F1.y wrong bit offset");
#endif
_Static_assert(sizeof(F2) == 8, "record F2 wrong sizeof");
_Static_assert(_Alignof(F2) == 4, "record F2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F2_alignment) == 12, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_alignment) == 4, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_packed) == 8, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_packed) == 1, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_required_alignment) == 9, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_required_alignment) == 1, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_size) == 10, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_size) == 1, "record F2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F2,y) == 0, "field F2.y wrong bit offset");
#endif
#elif defined(ARMEBV7R_UNKNOWN_NONE_EABI) ||  defined(ARMEBV7R_UNKNOWN_NONE_EABIHF) ||  defined(ARM_LINUX_ANDROIDEABI) ||  defined(ARM_UNKNOWN_LINUX_GNUEABI) ||  \
 defined(ARM_UNKNOWN_LINUX_GNUEABIHF) ||  defined(ARMV4T_UNKNOWN_LINUX_GNUEABI) ||  defined(ARMV5TE_UNKNOWN_LINUX_GNUEABI) ||  defined(ARMV5TE_UNKNOWN_LINUX_UCLIBCGNUEABI) ||  \
 defined(ARMV6_UNKNOWN_FREEBSD_GNUEABIHF) ||  defined(ARMV6_UNKNOWN_NETBSDELF_EABIHF) ||  defined(ARMV7A_NONE_EABI) ||  defined(ARMV7A_NONE_EABIHF) ||  \
 defined(ARMV7_APPLE_IOS) ||  defined(ARMV7_NONE_LINUX_ANDROID) ||  defined(ARMV7R_UNKNOWN_NONE_EABI) ||  defined(ARMV7R_UNKNOWN_NONE_EABIHF) ||  \
 defined(ARMV7S_APPLE_IOS) ||  defined(ARMV7_UNKNOWN_FREEBSD_GNUEABIHF) ||  defined(ARMV7_UNKNOWN_LINUX_GNUEABI) ||  defined(ARMV7_UNKNOWN_LINUX_GNUEABIHF) ||  \
 defined(ARMV7_UNKNOWN_NETBSDELF_EABIHF) ||  defined(THUMBV4T_NONE_EABI) ||  defined(THUMBV6M_NONE_EABI) ||  defined(THUMBV7EM_NONE_EABIHF) ||  \
 defined(THUMBV7EM_NONE_EABI) ||  defined(THUMBV7M_NONE_EABI) ||  defined(THUMBV8MBASE_NONE_EABI) ||  defined(THUMBV8MMAIN_NONE_EABIHF) ||  \
 defined(THUMBV8MMAIN_NONE_EABI) 
_Static_assert(sizeof(A1) == 8, "record A1 wrong sizeof");
_Static_assert(_Alignof(A1) == 1, "record A1 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A1_alignment) == 9, "record A1 wrong sizeof");
_Static_assert(_Alignof(struct A1_alignment) == 1, "record A1 wrong alignment");
_Static_assert(sizeof(struct A1_packed) == 8, "record A1 wrong sizeof");
_Static_assert(_Alignof(struct A1_packed) == 1, "record A1 wrong alignment");
_Static_assert(sizeof(struct A1_required_alignment) == 9, "record A1 wrong sizeof");
_Static_assert(_Alignof(struct A1_required_alignment) == 1, "record A1 wrong alignment");
_Static_assert(sizeof(struct A1_size) == 10, "record A1 wrong sizeof");
_Static_assert(_Alignof(struct A1_size) == 1, "record A1 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A1,y) == 32, "field A1.y wrong bit offset");
#endif
_Static_assert(sizeof(A2) == 8, "record A2 wrong sizeof");
_Static_assert(_Alignof(A2) == 1, "record A2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A2_alignment) == 9, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_alignment) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_packed) == 8, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_packed) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_required_alignment) == 9, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_required_alignment) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_size) == 10, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_size) == 1, "record A2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A2,y) == 32, "field A2.y wrong bit offset");
#endif
_Static_assert(sizeof(B1) == 4, "record B1 wrong sizeof");
_Static_assert(_Alignof(B1) == 1, "record B1 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B1_alignment) == 5, "record B1 wrong sizeof");
_Static_assert(_Alignof(struct B1_alignment) == 1, "record B1 wrong alignment");
_Static_assert(sizeof(struct B1_packed) == 4, "record B1 wrong sizeof");
_Static_assert(_Alignof(struct B1_packed) == 1, "record B1 wrong alignment");
_Static_assert(sizeof(struct B1_required_alignment) == 5, "record B1 wrong sizeof");
_Static_assert(_Alignof(struct B1_required_alignment) == 1, "record B1 wrong alignment");
_Static_assert(sizeof(struct B1_size) == 6, "record B1 wrong sizeof");
_Static_assert(_Alignof(struct B1_size) == 1, "record B1 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B1,y) == 0, "field B1.y wrong bit offset");
#endif
_Static_assert(sizeof(B2) == 4, "record B2 wrong sizeof");
_Static_assert(_Alignof(B2) == 1, "record B2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B2_alignment) == 5, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_alignment) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_packed) == 4, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_packed) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_required_alignment) == 5, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_required_alignment) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_size) == 6, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_size) == 1, "record B2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B2,y) == 0, "field B2.y wrong bit offset");
#endif
_Static_assert(sizeof(C1) == 5, "record C1 wrong sizeof");
_Static_assert(_Alignof(C1) == 1, "record C1 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C1_alignment) == 6, "record C1 wrong sizeof");
_Static_assert(_Alignof(struct C1_alignment) == 1, "record C1 wrong alignment");
_Static_assert(sizeof(struct C1_packed) == 5, "record C1 wrong sizeof");
_Static_assert(_Alignof(struct C1_packed) == 1, "record C1 wrong alignment");
_Static_assert(sizeof(struct C1_required_alignment) == 6, "record C1 wrong sizeof");
_Static_assert(_Alignof(struct C1_required_alignment) == 1, "record C1 wrong alignment");
_Static_assert(sizeof(struct C1_size) == 7, "record C1 wrong sizeof");
_Static_assert(_Alignof(struct C1_size) == 1, "record C1 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C1,y) == 8, "field C1.y wrong bit offset");
#endif
_Static_assert(sizeof(C2) == 5, "record C2 wrong sizeof");
_Static_assert(_Alignof(C2) == 1, "record C2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C2_alignment) == 6, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_alignment) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_packed) == 5, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_packed) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_required_alignment) == 6, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_required_alignment) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_size) == 7, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_size) == 1, "record C2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C2,y) == 8, "field C2.y wrong bit offset");
#endif
_Static_assert(sizeof(D1) == 4, "record D1 wrong sizeof");
_Static_assert(_Alignof(D1) == 1, "record D1 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D1_alignment) == 5, "record D1 wrong sizeof");
_Static_assert(_Alignof(struct D1_alignment) == 1, "record D1 wrong alignment");
_Static_assert(sizeof(struct D1_packed) == 4, "record D1 wrong sizeof");
_Static_assert(_Alignof(struct D1_packed) == 1, "record D1 wrong alignment");
_Static_assert(sizeof(struct D1_required_alignment) == 5, "record D1 wrong sizeof");
_Static_assert(_Alignof(struct D1_required_alignment) == 1, "record D1 wrong alignment");
_Static_assert(sizeof(struct D1_size) == 6, "record D1 wrong sizeof");
_Static_assert(_Alignof(struct D1_size) == 1, "record D1 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D1,y) == 0, "field D1.y wrong bit offset");
#endif
_Static_assert(sizeof(D2) == 4, "record D2 wrong sizeof");
_Static_assert(_Alignof(D2) == 1, "record D2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D2_alignment) == 5, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_alignment) == 1, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_packed) == 4, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_packed) == 1, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_required_alignment) == 5, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_required_alignment) == 1, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_size) == 6, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_size) == 1, "record D2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D2,y) == 0, "field D2.y wrong bit offset");
#endif
_Static_assert(sizeof(E1) == 4, "record E1 wrong sizeof");
_Static_assert(_Alignof(E1) == 4, "record E1 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E1_alignment) == 8, "record E1 wrong sizeof");
_Static_assert(_Alignof(struct E1_alignment) == 4, "record E1 wrong alignment");
_Static_assert(sizeof(struct E1_packed) == 4, "record E1 wrong sizeof");
_Static_assert(_Alignof(struct E1_packed) == 1, "record E1 wrong alignment");
_Static_assert(sizeof(struct E1_required_alignment) == 5, "record E1 wrong sizeof");
_Static_assert(_Alignof(struct E1_required_alignment) == 1, "record E1 wrong alignment");
_Static_assert(sizeof(struct E1_size) == 6, "record E1 wrong sizeof");
_Static_assert(_Alignof(struct E1_size) == 1, "record E1 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(E1,y) == 0, "field E1.y wrong bit offset");
#endif
_Static_assert(sizeof(E2) == 4, "record E2 wrong sizeof");
_Static_assert(_Alignof(E2) == 4, "record E2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E2_alignment) == 8, "record E2 wrong sizeof");
_Static_assert(_Alignof(struct E2_alignment) == 4, "record E2 wrong alignment");
_Static_assert(sizeof(struct E2_packed) == 4, "record E2 wrong sizeof");
_Static_assert(_Alignof(struct E2_packed) == 1, "record E2 wrong alignment");
_Static_assert(sizeof(struct E2_required_alignment) == 5, "record E2 wrong sizeof");
_Static_assert(_Alignof(struct E2_required_alignment) == 1, "record E2 wrong alignment");
_Static_assert(sizeof(struct E2_size) == 6, "record E2 wrong sizeof");
_Static_assert(_Alignof(struct E2_size) == 1, "record E2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(E2,y) == 0, "field E2.y wrong bit offset");
#endif
_Static_assert(sizeof(F1) == 4, "record F1 wrong sizeof");
_Static_assert(_Alignof(F1) == 4, "record F1 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F1_alignment) == 8, "record F1 wrong sizeof");
_Static_assert(_Alignof(struct F1_alignment) == 4, "record F1 wrong alignment");
_Static_assert(sizeof(struct F1_packed) == 4, "record F1 wrong sizeof");
_Static_assert(_Alignof(struct F1_packed) == 1, "record F1 wrong alignment");
_Static_assert(sizeof(struct F1_required_alignment) == 5, "record F1 wrong sizeof");
_Static_assert(_Alignof(struct F1_required_alignment) == 1, "record F1 wrong alignment");
_Static_assert(sizeof(struct F1_size) == 6, "record F1 wrong sizeof");
_Static_assert(_Alignof(struct F1_size) == 1, "record F1 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F1,y) == 0, "field F1.y wrong bit offset");
#endif
_Static_assert(sizeof(F2) == 4, "record F2 wrong sizeof");
_Static_assert(_Alignof(F2) == 4, "record F2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F2_alignment) == 8, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_alignment) == 4, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_packed) == 4, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_packed) == 1, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_required_alignment) == 5, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_required_alignment) == 1, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_size) == 6, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_size) == 1, "record F2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F2,y) == 0, "field F2.y wrong bit offset");
#endif
#elif defined(AVR_UNKNOWN_UNKNOWN) 
_Static_assert(sizeof(A1) == 6, "record A1 wrong sizeof");
_Static_assert(_Alignof(A1) == 1, "record A1 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A1_alignment) == 7, "record A1 wrong sizeof");
_Static_assert(_Alignof(struct A1_alignment) == 1, "record A1 wrong alignment");
_Static_assert(sizeof(struct A1_packed) == 6, "record A1 wrong sizeof");
_Static_assert(_Alignof(struct A1_packed) == 1, "record A1 wrong alignment");
_Static_assert(sizeof(struct A1_required_alignment) == 7, "record A1 wrong sizeof");
_Static_assert(_Alignof(struct A1_required_alignment) == 1, "record A1 wrong alignment");
_Static_assert(sizeof(struct A1_size) == 8, "record A1 wrong sizeof");
_Static_assert(_Alignof(struct A1_size) == 1, "record A1 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A1,y) == 16, "field A1.y wrong bit offset");
#endif
_Static_assert(sizeof(A2) == 6, "record A2 wrong sizeof");
_Static_assert(_Alignof(A2) == 1, "record A2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A2_alignment) == 7, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_alignment) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_packed) == 6, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_packed) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_required_alignment) == 7, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_required_alignment) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_size) == 8, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_size) == 1, "record A2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A2,y) == 16, "field A2.y wrong bit offset");
#endif
_Static_assert(sizeof(B1) == 4, "record B1 wrong sizeof");
_Static_assert(_Alignof(B1) == 1, "record B1 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B1_alignment) == 5, "record B1 wrong sizeof");
_Static_assert(_Alignof(struct B1_alignment) == 1, "record B1 wrong alignment");
_Static_assert(sizeof(struct B1_packed) == 4, "record B1 wrong sizeof");
_Static_assert(_Alignof(struct B1_packed) == 1, "record B1 wrong alignment");
_Static_assert(sizeof(struct B1_required_alignment) == 5, "record B1 wrong sizeof");
_Static_assert(_Alignof(struct B1_required_alignment) == 1, "record B1 wrong alignment");
_Static_assert(sizeof(struct B1_size) == 6, "record B1 wrong sizeof");
_Static_assert(_Alignof(struct B1_size) == 1, "record B1 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B1,y) == 0, "field B1.y wrong bit offset");
#endif
_Static_assert(sizeof(B2) == 4, "record B2 wrong sizeof");
_Static_assert(_Alignof(B2) == 1, "record B2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B2_alignment) == 5, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_alignment) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_packed) == 4, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_packed) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_required_alignment) == 5, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_required_alignment) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_size) == 6, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_size) == 1, "record B2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B2,y) == 0, "field B2.y wrong bit offset");
#endif
_Static_assert(sizeof(C1) == 5, "record C1 wrong sizeof");
_Static_assert(_Alignof(C1) == 1, "record C1 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C1_alignment) == 6, "record C1 wrong sizeof");
_Static_assert(_Alignof(struct C1_alignment) == 1, "record C1 wrong alignment");
_Static_assert(sizeof(struct C1_packed) == 5, "record C1 wrong sizeof");
_Static_assert(_Alignof(struct C1_packed) == 1, "record C1 wrong alignment");
_Static_assert(sizeof(struct C1_required_alignment) == 6, "record C1 wrong sizeof");
_Static_assert(_Alignof(struct C1_required_alignment) == 1, "record C1 wrong alignment");
_Static_assert(sizeof(struct C1_size) == 7, "record C1 wrong sizeof");
_Static_assert(_Alignof(struct C1_size) == 1, "record C1 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C1,y) == 8, "field C1.y wrong bit offset");
#endif
_Static_assert(sizeof(C2) == 5, "record C2 wrong sizeof");
_Static_assert(_Alignof(C2) == 1, "record C2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C2_alignment) == 6, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_alignment) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_packed) == 5, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_packed) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_required_alignment) == 6, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_required_alignment) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_size) == 7, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_size) == 1, "record C2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C2,y) == 8, "field C2.y wrong bit offset");
#endif
_Static_assert(sizeof(D1) == 4, "record D1 wrong sizeof");
_Static_assert(_Alignof(D1) == 1, "record D1 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D1_alignment) == 5, "record D1 wrong sizeof");
_Static_assert(_Alignof(struct D1_alignment) == 1, "record D1 wrong alignment");
_Static_assert(sizeof(struct D1_packed) == 4, "record D1 wrong sizeof");
_Static_assert(_Alignof(struct D1_packed) == 1, "record D1 wrong alignment");
_Static_assert(sizeof(struct D1_required_alignment) == 5, "record D1 wrong sizeof");
_Static_assert(_Alignof(struct D1_required_alignment) == 1, "record D1 wrong alignment");
_Static_assert(sizeof(struct D1_size) == 6, "record D1 wrong sizeof");
_Static_assert(_Alignof(struct D1_size) == 1, "record D1 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D1,y) == 0, "field D1.y wrong bit offset");
#endif
_Static_assert(sizeof(D2) == 4, "record D2 wrong sizeof");
_Static_assert(_Alignof(D2) == 1, "record D2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D2_alignment) == 5, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_alignment) == 1, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_packed) == 4, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_packed) == 1, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_required_alignment) == 5, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_required_alignment) == 1, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_size) == 6, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_size) == 1, "record D2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D2,y) == 0, "field D2.y wrong bit offset");
#endif
_Static_assert(sizeof(E1) == 4, "record E1 wrong sizeof");
_Static_assert(_Alignof(E1) == 1, "record E1 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E1_alignment) == 5, "record E1 wrong sizeof");
_Static_assert(_Alignof(struct E1_alignment) == 1, "record E1 wrong alignment");
_Static_assert(sizeof(struct E1_packed) == 4, "record E1 wrong sizeof");
_Static_assert(_Alignof(struct E1_packed) == 1, "record E1 wrong alignment");
_Static_assert(sizeof(struct E1_required_alignment) == 5, "record E1 wrong sizeof");
_Static_assert(_Alignof(struct E1_required_alignment) == 1, "record E1 wrong alignment");
_Static_assert(sizeof(struct E1_size) == 6, "record E1 wrong sizeof");
_Static_assert(_Alignof(struct E1_size) == 1, "record E1 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(E1,y) == 0, "field E1.y wrong bit offset");
#endif
_Static_assert(sizeof(E2) == 4, "record E2 wrong sizeof");
_Static_assert(_Alignof(E2) == 1, "record E2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E2_alignment) == 5, "record E2 wrong sizeof");
_Static_assert(_Alignof(struct E2_alignment) == 1, "record E2 wrong alignment");
_Static_assert(sizeof(struct E2_packed) == 4, "record E2 wrong sizeof");
_Static_assert(_Alignof(struct E2_packed) == 1, "record E2 wrong alignment");
_Static_assert(sizeof(struct E2_required_alignment) == 5, "record E2 wrong sizeof");
_Static_assert(_Alignof(struct E2_required_alignment) == 1, "record E2 wrong alignment");
_Static_assert(sizeof(struct E2_size) == 6, "record E2 wrong sizeof");
_Static_assert(_Alignof(struct E2_size) == 1, "record E2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(E2,y) == 0, "field E2.y wrong bit offset");
#endif
_Static_assert(sizeof(F1) == 4, "record F1 wrong sizeof");
_Static_assert(_Alignof(F1) == 1, "record F1 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F1_alignment) == 5, "record F1 wrong sizeof");
_Static_assert(_Alignof(struct F1_alignment) == 1, "record F1 wrong alignment");
_Static_assert(sizeof(struct F1_packed) == 4, "record F1 wrong sizeof");
_Static_assert(_Alignof(struct F1_packed) == 1, "record F1 wrong alignment");
_Static_assert(sizeof(struct F1_required_alignment) == 5, "record F1 wrong sizeof");
_Static_assert(_Alignof(struct F1_required_alignment) == 1, "record F1 wrong alignment");
_Static_assert(sizeof(struct F1_size) == 6, "record F1 wrong sizeof");
_Static_assert(_Alignof(struct F1_size) == 1, "record F1 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F1,y) == 0, "field F1.y wrong bit offset");
#endif
_Static_assert(sizeof(F2) == 4, "record F2 wrong sizeof");
_Static_assert(_Alignof(F2) == 1, "record F2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F2_alignment) == 5, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_alignment) == 1, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_packed) == 4, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_packed) == 1, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_required_alignment) == 5, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_required_alignment) == 1, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_size) == 6, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_size) == 1, "record F2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F2,y) == 0, "field F2.y wrong bit offset");
#endif
#elif defined(HEXAGON_UNKNOWN_LINUX_MUSL) ||  defined(I386_APPLE_IOS) ||  defined(I586_UNKNOWN_LINUX_GNU) ||  defined(I586_UNKNOWN_LINUX_MUSL) ||  \
 defined(I686_APPLE_MACOSX) ||  defined(I686_LINUX_ANDROID) ||  defined(I686_UNKNOWN_FREEBSD) ||  defined(I686_UNKNOWN_HAIKU) ||  defined(I686_UNKNOWN_LINUX_GNU) ||  \
 defined(I686_UNKNOWN_LINUX_MUSL) ||  defined(I686_UNKNOWN_NETBSDELF) ||  defined(I686_UNKNOWN_OPENBSD) ||  defined(MIPSEL_SONY_PSP) ||  \
 defined(MIPSEL_UNKNOWN_LINUX_GNU) ||  defined(MIPSEL_UNKNOWN_LINUX_MUSL) ||  defined(MIPSEL_UNKNOWN_LINUX_UCLIBC) ||  defined(MIPSEL_UNKNOWN_NONE) ||  \
 defined(MIPSISA32R6EL_UNKNOWN_LINUX_GNU) ||  defined(MIPSISA32R6_UNKNOWN_LINUX_GNU) ||  defined(MIPS_UNKNOWN_LINUX_GNU) ||  defined(MIPS_UNKNOWN_LINUX_MUSL) ||  \
 defined(MIPS_UNKNOWN_LINUX_UCLIBC) ||  defined(POWERPC_UNKNOWN_LINUX_GNU) ||  defined(POWERPC_UNKNOWN_LINUX_GNUSPE) ||  defined(POWERPC_UNKNOWN_LINUX_MUSL) ||  \
 defined(POWERPC_UNKNOWN_NETBSD) ||  defined(RISCV32) ||  defined(RISCV32_UNKNOWN_LINUX_GNU) ||  defined(SPARC_UNKNOWN_LINUX_GNU) ||  \
 defined(WASM32_UNKNOWN_EMSCRIPTEN) ||  defined(WASM32_UNKNOWN_UNKNOWN) ||  defined(WASM32_WASI) ||  defined(X8664_UNKNOWN_LINUX_GNUX32) 
_Static_assert(sizeof(A1) == 8, "record A1 wrong sizeof");
_Static_assert(_Alignof(A1) == 1, "record A1 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A1_alignment) == 9, "record A1 wrong sizeof");
_Static_assert(_Alignof(struct A1_alignment) == 1, "record A1 wrong alignment");
_Static_assert(sizeof(struct A1_packed) == 8, "record A1 wrong sizeof");
_Static_assert(_Alignof(struct A1_packed) == 1, "record A1 wrong alignment");
_Static_assert(sizeof(struct A1_required_alignment) == 9, "record A1 wrong sizeof");
_Static_assert(_Alignof(struct A1_required_alignment) == 1, "record A1 wrong alignment");
_Static_assert(sizeof(struct A1_size) == 10, "record A1 wrong sizeof");
_Static_assert(_Alignof(struct A1_size) == 1, "record A1 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A1,y) == 32, "field A1.y wrong bit offset");
#endif
_Static_assert(sizeof(A2) == 8, "record A2 wrong sizeof");
_Static_assert(_Alignof(A2) == 1, "record A2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A2_alignment) == 9, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_alignment) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_packed) == 8, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_packed) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_required_alignment) == 9, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_required_alignment) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_size) == 10, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_size) == 1, "record A2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A2,y) == 32, "field A2.y wrong bit offset");
#endif
_Static_assert(sizeof(B1) == 4, "record B1 wrong sizeof");
_Static_assert(_Alignof(B1) == 1, "record B1 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B1_alignment) == 5, "record B1 wrong sizeof");
_Static_assert(_Alignof(struct B1_alignment) == 1, "record B1 wrong alignment");
_Static_assert(sizeof(struct B1_packed) == 4, "record B1 wrong sizeof");
_Static_assert(_Alignof(struct B1_packed) == 1, "record B1 wrong alignment");
_Static_assert(sizeof(struct B1_required_alignment) == 5, "record B1 wrong sizeof");
_Static_assert(_Alignof(struct B1_required_alignment) == 1, "record B1 wrong alignment");
_Static_assert(sizeof(struct B1_size) == 6, "record B1 wrong sizeof");
_Static_assert(_Alignof(struct B1_size) == 1, "record B1 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B1,y) == 0, "field B1.y wrong bit offset");
#endif
_Static_assert(sizeof(B2) == 4, "record B2 wrong sizeof");
_Static_assert(_Alignof(B2) == 1, "record B2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B2_alignment) == 5, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_alignment) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_packed) == 4, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_packed) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_required_alignment) == 5, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_required_alignment) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_size) == 6, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_size) == 1, "record B2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B2,y) == 0, "field B2.y wrong bit offset");
#endif
_Static_assert(sizeof(C1) == 5, "record C1 wrong sizeof");
_Static_assert(_Alignof(C1) == 1, "record C1 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C1_alignment) == 6, "record C1 wrong sizeof");
_Static_assert(_Alignof(struct C1_alignment) == 1, "record C1 wrong alignment");
_Static_assert(sizeof(struct C1_packed) == 5, "record C1 wrong sizeof");
_Static_assert(_Alignof(struct C1_packed) == 1, "record C1 wrong alignment");
_Static_assert(sizeof(struct C1_required_alignment) == 6, "record C1 wrong sizeof");
_Static_assert(_Alignof(struct C1_required_alignment) == 1, "record C1 wrong alignment");
_Static_assert(sizeof(struct C1_size) == 7, "record C1 wrong sizeof");
_Static_assert(_Alignof(struct C1_size) == 1, "record C1 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C1,y) == 8, "field C1.y wrong bit offset");
#endif
_Static_assert(sizeof(C2) == 5, "record C2 wrong sizeof");
_Static_assert(_Alignof(C2) == 1, "record C2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C2_alignment) == 6, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_alignment) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_packed) == 5, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_packed) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_required_alignment) == 6, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_required_alignment) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_size) == 7, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_size) == 1, "record C2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C2,y) == 8, "field C2.y wrong bit offset");
#endif
_Static_assert(sizeof(D1) == 4, "record D1 wrong sizeof");
_Static_assert(_Alignof(D1) == 1, "record D1 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D1_alignment) == 5, "record D1 wrong sizeof");
_Static_assert(_Alignof(struct D1_alignment) == 1, "record D1 wrong alignment");
_Static_assert(sizeof(struct D1_packed) == 4, "record D1 wrong sizeof");
_Static_assert(_Alignof(struct D1_packed) == 1, "record D1 wrong alignment");
_Static_assert(sizeof(struct D1_required_alignment) == 5, "record D1 wrong sizeof");
_Static_assert(_Alignof(struct D1_required_alignment) == 1, "record D1 wrong alignment");
_Static_assert(sizeof(struct D1_size) == 6, "record D1 wrong sizeof");
_Static_assert(_Alignof(struct D1_size) == 1, "record D1 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D1,y) == 0, "field D1.y wrong bit offset");
#endif
_Static_assert(sizeof(D2) == 4, "record D2 wrong sizeof");
_Static_assert(_Alignof(D2) == 1, "record D2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D2_alignment) == 5, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_alignment) == 1, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_packed) == 4, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_packed) == 1, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_required_alignment) == 5, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_required_alignment) == 1, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_size) == 6, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_size) == 1, "record D2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D2,y) == 0, "field D2.y wrong bit offset");
#endif
_Static_assert(sizeof(E1) == 4, "record E1 wrong sizeof");
_Static_assert(_Alignof(E1) == 1, "record E1 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E1_alignment) == 5, "record E1 wrong sizeof");
_Static_assert(_Alignof(struct E1_alignment) == 1, "record E1 wrong alignment");
_Static_assert(sizeof(struct E1_packed) == 4, "record E1 wrong sizeof");
_Static_assert(_Alignof(struct E1_packed) == 1, "record E1 wrong alignment");
_Static_assert(sizeof(struct E1_required_alignment) == 5, "record E1 wrong sizeof");
_Static_assert(_Alignof(struct E1_required_alignment) == 1, "record E1 wrong alignment");
_Static_assert(sizeof(struct E1_size) == 6, "record E1 wrong sizeof");
_Static_assert(_Alignof(struct E1_size) == 1, "record E1 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(E1,y) == 0, "field E1.y wrong bit offset");
#endif
_Static_assert(sizeof(E2) == 4, "record E2 wrong sizeof");
_Static_assert(_Alignof(E2) == 1, "record E2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E2_alignment) == 5, "record E2 wrong sizeof");
_Static_assert(_Alignof(struct E2_alignment) == 1, "record E2 wrong alignment");
_Static_assert(sizeof(struct E2_packed) == 4, "record E2 wrong sizeof");
_Static_assert(_Alignof(struct E2_packed) == 1, "record E2 wrong alignment");
_Static_assert(sizeof(struct E2_required_alignment) == 5, "record E2 wrong sizeof");
_Static_assert(_Alignof(struct E2_required_alignment) == 1, "record E2 wrong alignment");
_Static_assert(sizeof(struct E2_size) == 6, "record E2 wrong sizeof");
_Static_assert(_Alignof(struct E2_size) == 1, "record E2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(E2,y) == 0, "field E2.y wrong bit offset");
#endif
_Static_assert(sizeof(F1) == 4, "record F1 wrong sizeof");
_Static_assert(_Alignof(F1) == 1, "record F1 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F1_alignment) == 5, "record F1 wrong sizeof");
_Static_assert(_Alignof(struct F1_alignment) == 1, "record F1 wrong alignment");
_Static_assert(sizeof(struct F1_packed) == 4, "record F1 wrong sizeof");
_Static_assert(_Alignof(struct F1_packed) == 1, "record F1 wrong alignment");
_Static_assert(sizeof(struct F1_required_alignment) == 5, "record F1 wrong sizeof");
_Static_assert(_Alignof(struct F1_required_alignment) == 1, "record F1 wrong alignment");
_Static_assert(sizeof(struct F1_size) == 6, "record F1 wrong sizeof");
_Static_assert(_Alignof(struct F1_size) == 1, "record F1 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F1,y) == 0, "field F1.y wrong bit offset");
#endif
_Static_assert(sizeof(F2) == 4, "record F2 wrong sizeof");
_Static_assert(_Alignof(F2) == 1, "record F2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F2_alignment) == 5, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_alignment) == 1, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_packed) == 4, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_packed) == 1, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_required_alignment) == 5, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_required_alignment) == 1, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_size) == 6, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_size) == 1, "record F2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F2,y) == 0, "field F2.y wrong bit offset");
#endif
#elif defined(I686_PC_WINDOWS_GNU) ||  defined(X8664_PC_WINDOWS_GNU) 
_Static_assert(sizeof(A1) == 8, "record A1 wrong sizeof");
_Static_assert(_Alignof(A1) == 1, "record A1 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A1_alignment) == 9, "record A1 wrong sizeof");
_Static_assert(_Alignof(struct A1_alignment) == 1, "record A1 wrong alignment");
_Static_assert(sizeof(struct A1_packed) == 8, "record A1 wrong sizeof");
_Static_assert(_Alignof(struct A1_packed) == 1, "record A1 wrong alignment");
_Static_assert(sizeof(struct A1_required_alignment) == 9, "record A1 wrong sizeof");
_Static_assert(_Alignof(struct A1_required_alignment) == 1, "record A1 wrong alignment");
_Static_assert(sizeof(struct A1_size) == 10, "record A1 wrong sizeof");
_Static_assert(_Alignof(struct A1_size) == 1, "record A1 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A1,y) == 32, "field A1.y wrong bit offset");
#endif
_Static_assert(sizeof(A2) == 8, "record A2 wrong sizeof");
_Static_assert(_Alignof(A2) == 1, "record A2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A2_alignment) == 9, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_alignment) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_packed) == 8, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_packed) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_required_alignment) == 9, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_required_alignment) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_size) == 10, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_size) == 1, "record A2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A2,y) == 32, "field A2.y wrong bit offset");
#endif
_Static_assert(sizeof(B1) == 4, "record B1 wrong sizeof");
_Static_assert(_Alignof(B1) == 1, "record B1 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B1_alignment) == 5, "record B1 wrong sizeof");
_Static_assert(_Alignof(struct B1_alignment) == 1, "record B1 wrong alignment");
_Static_assert(sizeof(struct B1_packed) == 4, "record B1 wrong sizeof");
_Static_assert(_Alignof(struct B1_packed) == 1, "record B1 wrong alignment");
_Static_assert(sizeof(struct B1_required_alignment) == 5, "record B1 wrong sizeof");
_Static_assert(_Alignof(struct B1_required_alignment) == 1, "record B1 wrong alignment");
_Static_assert(sizeof(struct B1_size) == 6, "record B1 wrong sizeof");
_Static_assert(_Alignof(struct B1_size) == 1, "record B1 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B1,y) == 0, "field B1.y wrong bit offset");
#endif
_Static_assert(sizeof(B2) == 4, "record B2 wrong sizeof");
_Static_assert(_Alignof(B2) == 1, "record B2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B2_alignment) == 5, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_alignment) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_packed) == 4, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_packed) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_required_alignment) == 5, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_required_alignment) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_size) == 6, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_size) == 1, "record B2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B2,y) == 0, "field B2.y wrong bit offset");
#endif
_Static_assert(sizeof(C1) == 8, "record C1 wrong sizeof");
_Static_assert(_Alignof(C1) == 1, "record C1 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C1_alignment) == 9, "record C1 wrong sizeof");
_Static_assert(_Alignof(struct C1_alignment) == 1, "record C1 wrong alignment");
_Static_assert(sizeof(struct C1_packed) == 8, "record C1 wrong sizeof");
_Static_assert(_Alignof(struct C1_packed) == 1, "record C1 wrong alignment");
_Static_assert(sizeof(struct C1_required_alignment) == 9, "record C1 wrong sizeof");
_Static_assert(_Alignof(struct C1_required_alignment) == 1, "record C1 wrong alignment");
_Static_assert(sizeof(struct C1_size) == 10, "record C1 wrong sizeof");
_Static_assert(_Alignof(struct C1_size) == 1, "record C1 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C1,y) == 32, "field C1.y wrong bit offset");
#endif
_Static_assert(sizeof(C2) == 8, "record C2 wrong sizeof");
_Static_assert(_Alignof(C2) == 1, "record C2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C2_alignment) == 9, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_alignment) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_packed) == 8, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_packed) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_required_alignment) == 9, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_required_alignment) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_size) == 10, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_size) == 1, "record C2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C2,y) == 32, "field C2.y wrong bit offset");
#endif
_Static_assert(sizeof(D1) == 4, "record D1 wrong sizeof");
_Static_assert(_Alignof(D1) == 1, "record D1 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D1_alignment) == 5, "record D1 wrong sizeof");
_Static_assert(_Alignof(struct D1_alignment) == 1, "record D1 wrong alignment");
_Static_assert(sizeof(struct D1_packed) == 4, "record D1 wrong sizeof");
_Static_assert(_Alignof(struct D1_packed) == 1, "record D1 wrong alignment");
_Static_assert(sizeof(struct D1_required_alignment) == 5, "record D1 wrong sizeof");
_Static_assert(_Alignof(struct D1_required_alignment) == 1, "record D1 wrong alignment");
_Static_assert(sizeof(struct D1_size) == 6, "record D1 wrong sizeof");
_Static_assert(_Alignof(struct D1_size) == 1, "record D1 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D1,y) == 0, "field D1.y wrong bit offset");
#endif
_Static_assert(sizeof(D2) == 4, "record D2 wrong sizeof");
_Static_assert(_Alignof(D2) == 1, "record D2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D2_alignment) == 5, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_alignment) == 1, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_packed) == 4, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_packed) == 1, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_required_alignment) == 5, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_required_alignment) == 1, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_size) == 6, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_size) == 1, "record D2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D2,y) == 0, "field D2.y wrong bit offset");
#endif
_Static_assert(sizeof(E1) == 4, "record E1 wrong sizeof");
_Static_assert(_Alignof(E1) == 1, "record E1 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E1_alignment) == 5, "record E1 wrong sizeof");
_Static_assert(_Alignof(struct E1_alignment) == 1, "record E1 wrong alignment");
_Static_assert(sizeof(struct E1_packed) == 4, "record E1 wrong sizeof");
_Static_assert(_Alignof(struct E1_packed) == 1, "record E1 wrong alignment");
_Static_assert(sizeof(struct E1_required_alignment) == 5, "record E1 wrong sizeof");
_Static_assert(_Alignof(struct E1_required_alignment) == 1, "record E1 wrong alignment");
_Static_assert(sizeof(struct E1_size) == 6, "record E1 wrong sizeof");
_Static_assert(_Alignof(struct E1_size) == 1, "record E1 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(E1,y) == 0, "field E1.y wrong bit offset");
#endif
_Static_assert(sizeof(E2) == 4, "record E2 wrong sizeof");
_Static_assert(_Alignof(E2) == 1, "record E2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E2_alignment) == 5, "record E2 wrong sizeof");
_Static_assert(_Alignof(struct E2_alignment) == 1, "record E2 wrong alignment");
_Static_assert(sizeof(struct E2_packed) == 4, "record E2 wrong sizeof");
_Static_assert(_Alignof(struct E2_packed) == 1, "record E2 wrong alignment");
_Static_assert(sizeof(struct E2_required_alignment) == 5, "record E2 wrong sizeof");
_Static_assert(_Alignof(struct E2_required_alignment) == 1, "record E2 wrong alignment");
_Static_assert(sizeof(struct E2_size) == 6, "record E2 wrong sizeof");
_Static_assert(_Alignof(struct E2_size) == 1, "record E2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(E2,y) == 0, "field E2.y wrong bit offset");
#endif
_Static_assert(sizeof(F1) == 4, "record F1 wrong sizeof");
_Static_assert(_Alignof(F1) == 1, "record F1 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F1_alignment) == 5, "record F1 wrong sizeof");
_Static_assert(_Alignof(struct F1_alignment) == 1, "record F1 wrong alignment");
_Static_assert(sizeof(struct F1_packed) == 4, "record F1 wrong sizeof");
_Static_assert(_Alignof(struct F1_packed) == 1, "record F1 wrong alignment");
_Static_assert(sizeof(struct F1_required_alignment) == 5, "record F1 wrong sizeof");
_Static_assert(_Alignof(struct F1_required_alignment) == 1, "record F1 wrong alignment");
_Static_assert(sizeof(struct F1_size) == 6, "record F1 wrong sizeof");
_Static_assert(_Alignof(struct F1_size) == 1, "record F1 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F1,y) == 0, "field F1.y wrong bit offset");
#endif
_Static_assert(sizeof(F2) == 4, "record F2 wrong sizeof");
_Static_assert(_Alignof(F2) == 1, "record F2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F2_alignment) == 5, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_alignment) == 1, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_packed) == 4, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_packed) == 1, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_required_alignment) == 5, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_required_alignment) == 1, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_size) == 6, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_size) == 1, "record F2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F2,y) == 0, "field F2.y wrong bit offset");
#endif
#elif defined(MSP430_NONE_ELF) 
_Static_assert(sizeof(A1) == 6, "record A1 wrong sizeof");
_Static_assert(_Alignof(A1) == 1, "record A1 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A1_alignment) == 7, "record A1 wrong sizeof");
_Static_assert(_Alignof(struct A1_alignment) == 1, "record A1 wrong alignment");
_Static_assert(sizeof(struct A1_packed) == 6, "record A1 wrong sizeof");
_Static_assert(_Alignof(struct A1_packed) == 1, "record A1 wrong alignment");
_Static_assert(sizeof(struct A1_required_alignment) == 7, "record A1 wrong sizeof");
_Static_assert(_Alignof(struct A1_required_alignment) == 1, "record A1 wrong alignment");
_Static_assert(sizeof(struct A1_size) == 8, "record A1 wrong sizeof");
_Static_assert(_Alignof(struct A1_size) == 1, "record A1 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A1,y) == 16, "field A1.y wrong bit offset");
#endif
_Static_assert(sizeof(A2) == 6, "record A2 wrong sizeof");
_Static_assert(_Alignof(A2) == 1, "record A2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A2_alignment) == 7, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_alignment) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_packed) == 6, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_packed) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_required_alignment) == 7, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_required_alignment) == 1, "record A2 wrong alignment");
_Static_assert(sizeof(struct A2_size) == 8, "record A2 wrong sizeof");
_Static_assert(_Alignof(struct A2_size) == 1, "record A2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A2,y) == 16, "field A2.y wrong bit offset");
#endif
_Static_assert(sizeof(B1) == 4, "record B1 wrong sizeof");
_Static_assert(_Alignof(B1) == 1, "record B1 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B1_alignment) == 5, "record B1 wrong sizeof");
_Static_assert(_Alignof(struct B1_alignment) == 1, "record B1 wrong alignment");
_Static_assert(sizeof(struct B1_packed) == 4, "record B1 wrong sizeof");
_Static_assert(_Alignof(struct B1_packed) == 1, "record B1 wrong alignment");
_Static_assert(sizeof(struct B1_required_alignment) == 5, "record B1 wrong sizeof");
_Static_assert(_Alignof(struct B1_required_alignment) == 1, "record B1 wrong alignment");
_Static_assert(sizeof(struct B1_size) == 6, "record B1 wrong sizeof");
_Static_assert(_Alignof(struct B1_size) == 1, "record B1 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B1,y) == 0, "field B1.y wrong bit offset");
#endif
_Static_assert(sizeof(B2) == 4, "record B2 wrong sizeof");
_Static_assert(_Alignof(B2) == 1, "record B2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B2_alignment) == 5, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_alignment) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_packed) == 4, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_packed) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_required_alignment) == 5, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_required_alignment) == 1, "record B2 wrong alignment");
_Static_assert(sizeof(struct B2_size) == 6, "record B2 wrong sizeof");
_Static_assert(_Alignof(struct B2_size) == 1, "record B2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B2,y) == 0, "field B2.y wrong bit offset");
#endif
_Static_assert(sizeof(C1) == 5, "record C1 wrong sizeof");
_Static_assert(_Alignof(C1) == 1, "record C1 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C1_alignment) == 6, "record C1 wrong sizeof");
_Static_assert(_Alignof(struct C1_alignment) == 1, "record C1 wrong alignment");
_Static_assert(sizeof(struct C1_packed) == 5, "record C1 wrong sizeof");
_Static_assert(_Alignof(struct C1_packed) == 1, "record C1 wrong alignment");
_Static_assert(sizeof(struct C1_required_alignment) == 6, "record C1 wrong sizeof");
_Static_assert(_Alignof(struct C1_required_alignment) == 1, "record C1 wrong alignment");
_Static_assert(sizeof(struct C1_size) == 7, "record C1 wrong sizeof");
_Static_assert(_Alignof(struct C1_size) == 1, "record C1 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C1,y) == 8, "field C1.y wrong bit offset");
#endif
_Static_assert(sizeof(C2) == 5, "record C2 wrong sizeof");
_Static_assert(_Alignof(C2) == 1, "record C2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C2_alignment) == 6, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_alignment) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_packed) == 5, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_packed) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_required_alignment) == 6, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_required_alignment) == 1, "record C2 wrong alignment");
_Static_assert(sizeof(struct C2_size) == 7, "record C2 wrong sizeof");
_Static_assert(_Alignof(struct C2_size) == 1, "record C2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C2,y) == 8, "field C2.y wrong bit offset");
#endif
_Static_assert(sizeof(D1) == 4, "record D1 wrong sizeof");
_Static_assert(_Alignof(D1) == 1, "record D1 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D1_alignment) == 5, "record D1 wrong sizeof");
_Static_assert(_Alignof(struct D1_alignment) == 1, "record D1 wrong alignment");
_Static_assert(sizeof(struct D1_packed) == 4, "record D1 wrong sizeof");
_Static_assert(_Alignof(struct D1_packed) == 1, "record D1 wrong alignment");
_Static_assert(sizeof(struct D1_required_alignment) == 5, "record D1 wrong sizeof");
_Static_assert(_Alignof(struct D1_required_alignment) == 1, "record D1 wrong alignment");
_Static_assert(sizeof(struct D1_size) == 6, "record D1 wrong sizeof");
_Static_assert(_Alignof(struct D1_size) == 1, "record D1 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D1,y) == 0, "field D1.y wrong bit offset");
#endif
_Static_assert(sizeof(D2) == 4, "record D2 wrong sizeof");
_Static_assert(_Alignof(D2) == 1, "record D2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D2_alignment) == 5, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_alignment) == 1, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_packed) == 4, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_packed) == 1, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_required_alignment) == 5, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_required_alignment) == 1, "record D2 wrong alignment");
_Static_assert(sizeof(struct D2_size) == 6, "record D2 wrong sizeof");
_Static_assert(_Alignof(struct D2_size) == 1, "record D2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D2,y) == 0, "field D2.y wrong bit offset");
#endif
_Static_assert(sizeof(E1) == 4, "record E1 wrong sizeof");
_Static_assert(_Alignof(E1) == 1, "record E1 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E1_alignment) == 5, "record E1 wrong sizeof");
_Static_assert(_Alignof(struct E1_alignment) == 1, "record E1 wrong alignment");
_Static_assert(sizeof(struct E1_packed) == 4, "record E1 wrong sizeof");
_Static_assert(_Alignof(struct E1_packed) == 1, "record E1 wrong alignment");
_Static_assert(sizeof(struct E1_required_alignment) == 5, "record E1 wrong sizeof");
_Static_assert(_Alignof(struct E1_required_alignment) == 1, "record E1 wrong alignment");
_Static_assert(sizeof(struct E1_size) == 6, "record E1 wrong sizeof");
_Static_assert(_Alignof(struct E1_size) == 1, "record E1 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(E1,y) == 0, "field E1.y wrong bit offset");
#endif
_Static_assert(sizeof(E2) == 4, "record E2 wrong sizeof");
_Static_assert(_Alignof(E2) == 1, "record E2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E2_alignment) == 5, "record E2 wrong sizeof");
_Static_assert(_Alignof(struct E2_alignment) == 1, "record E2 wrong alignment");
_Static_assert(sizeof(struct E2_packed) == 4, "record E2 wrong sizeof");
_Static_assert(_Alignof(struct E2_packed) == 1, "record E2 wrong alignment");
_Static_assert(sizeof(struct E2_required_alignment) == 5, "record E2 wrong sizeof");
_Static_assert(_Alignof(struct E2_required_alignment) == 1, "record E2 wrong alignment");
_Static_assert(sizeof(struct E2_size) == 6, "record E2 wrong sizeof");
_Static_assert(_Alignof(struct E2_size) == 1, "record E2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(E2,y) == 0, "field E2.y wrong bit offset");
#endif
_Static_assert(sizeof(F1) == 4, "record F1 wrong sizeof");
_Static_assert(_Alignof(F1) == 1, "record F1 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F1_alignment) == 5, "record F1 wrong sizeof");
_Static_assert(_Alignof(struct F1_alignment) == 1, "record F1 wrong alignment");
_Static_assert(sizeof(struct F1_packed) == 4, "record F1 wrong sizeof");
_Static_assert(_Alignof(struct F1_packed) == 1, "record F1 wrong alignment");
_Static_assert(sizeof(struct F1_required_alignment) == 5, "record F1 wrong sizeof");
_Static_assert(_Alignof(struct F1_required_alignment) == 1, "record F1 wrong alignment");
_Static_assert(sizeof(struct F1_size) == 6, "record F1 wrong sizeof");
_Static_assert(_Alignof(struct F1_size) == 1, "record F1 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F1,y) == 0, "field F1.y wrong bit offset");
#endif
_Static_assert(sizeof(F2) == 4, "record F2 wrong sizeof");
_Static_assert(_Alignof(F2) == 1, "record F2 wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F2_alignment) == 5, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_alignment) == 1, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_packed) == 4, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_packed) == 1, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_required_alignment) == 5, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_required_alignment) == 1, "record F2 wrong alignment");
_Static_assert(sizeof(struct F2_size) == 6, "record F2 wrong sizeof");
_Static_assert(_Alignof(struct F2_size) == 1, "record F2 wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F2,y) == 0, "field F2.y wrong bit offset");
#endif
#endif
