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


// MAPPING|ONE|aarch64-generic-macos-none:Clang|aarch64-generic-ios-none:Clang|aarch64-generic-ios-macabi:Clang|aarch64-generic-tvos-none:Clang|mips64el-mips64-linux-gnuabi64:Gcc|mips64-mips64-linux-gnuabi64:Gcc|mips-mips32-linux-gnuabi64:Gcc|mips-mips64r6-linux-gnuabi64:Gcc|powerpc64le-ppc64le-linux-gnu:Gcc|powerpc64le-ppc64le-linux-musl:Gcc|powerpc64-ppc64-freebsd-gnu:Clang|powerpc64-ppc64-linux-gnu:Gcc|powerpc64-ppc64-linux-musl:Gcc|riscv64-generic_rv64-other-none:Clang|riscv64-generic_rv64-linux-gnu:Gcc|s390x-generic-linux-gnu:Gcc|sparc64-v9-linux-gnu:Gcc|sparc64-v9-netbsd-gnu:Clang|sparc64-v9-openbsd-gnu:Clang|sparc-v9-solaris-eabi:Clang|x86_64-x86_64-ios-macabi:Clang|x86_64-x86_64-ios-none:Clang|x86_64-x86_64-macos-none:Clang|x86_64-x86_64-tvos-none:Clang|x86_64-x86_64-fuchsia-gnu:Clang|x86_64-x86_64-linux-android:Clang|x86_64-x86_64-solaris-eabi:Clang|x86_64-x86_64-dragonfly-eabi:Clang|x86_64-x86_64-freebsd-gnu:Clang|x86_64-x86_64-haiku-gnu:Clang|x86_64-x86_64-hermit-eabi:Clang|x86_64-x86_64-linux-gnu:Gcc|x86_64-x86_64-linux-musl:Gcc|x86_64-x86_64-netbsd-gnu:Clang|x86_64-x86_64-openbsd-gnu:Clang|END
// repr targets Aarch64AppleMacosx|Some("aarch64-generic-macos-none") Arm64AppleIos|Some("aarch64-generic-ios-none") Arm64AppleIosMacabi|Some("aarch64-generic-ios-macabi") Arm64AppleTvos|Some("aarch64-generic-tvos-none") Mips64elUnknownLinuxGnuabi64|Some("mips64el-mips64-linux-gnuabi64") Mips64elUnknownLinuxMusl|None Mips64UnknownLinuxGnuabi64|Some("mips64-mips64-linux-gnuabi64") Mips64UnknownLinuxMusl|None Mipsisa64r6elUnknownLinuxGnuabi64|Some("mips-mips32-linux-gnuabi64") Mipsisa64r6UnknownLinuxGnuabi64|Some("mips-mips64r6-linux-gnuabi64") Powerpc64leUnknownLinuxGnu|Some("powerpc64le-ppc64le-linux-gnu") Powerpc64leUnknownLinuxMusl|Some("powerpc64le-ppc64le-linux-musl") Powerpc64UnknownFreebsd|Some("powerpc64-ppc64-freebsd-gnu") Powerpc64UnknownLinuxGnu|Some("powerpc64-ppc64-linux-gnu") Powerpc64UnknownLinuxMusl|Some("powerpc64-ppc64-linux-musl") Riscv64|Some("riscv64-generic_rv64-other-none") Riscv64UnknownLinuxGnu|Some("riscv64-generic_rv64-linux-gnu") S390xUnknownLinuxGnu|Some("s390x-generic-linux-gnu") Sparc64UnknownLinuxGnu|Some("sparc64-v9-linux-gnu") Sparc64UnknownNetbsd|Some("sparc64-v9-netbsd-gnu") Sparc64UnknownOpenbsd|Some("sparc64-v9-openbsd-gnu") Sparcv9SunSolaris|Some("sparc-v9-solaris-eabi") X86_64AppleIosMacabi|Some("x86_64-x86_64-ios-macabi") X86_64AppleIos|Some("x86_64-x86_64-ios-none") X86_64AppleMacosx|Some("x86_64-x86_64-macos-none") X86_64AppleTvos|Some("x86_64-x86_64-tvos-none") X86_64Elf|None X86_64Fuchsia|Some("x86_64-x86_64-fuchsia-gnu") X86_64LinuxAndroid|Some("x86_64-x86_64-linux-android") X86_64PcSolaris|Some("x86_64-x86_64-solaris-eabi") X86_64RumprunNetbsd|None X86_64UnknownDragonfly|Some("x86_64-x86_64-dragonfly-eabi") X86_64UnknownFreebsd|Some("x86_64-x86_64-freebsd-gnu") X86_64UnknownHaiku|Some("x86_64-x86_64-haiku-gnu") X86_64UnknownHermit|Some("x86_64-x86_64-hermit-eabi") X86_64UnknownL4reUclibc|None X86_64UnknownLinuxGnu|Some("x86_64-x86_64-linux-gnu") X86_64UnknownLinuxMusl|Some("x86_64-x86_64-linux-musl") X86_64UnknownNetbsd|Some("x86_64-x86_64-netbsd-gnu") X86_64UnknownOpenbsd|Some("x86_64-x86_64-openbsd-gnu") X86_64UnknownRedox|None 
#ifdef ONE
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
// MAPPING|TWO|aarch64-generic-fuchsia-gnu:Clang|aarch64-generic-linux-android:Clang|aarch64-generic-freebsd-gnu:Clang|aarch64-generic-hermit-eabi:Clang|aarch64-generic-linux-gnu:Gcc|aarch64-generic-linux-musl:Gcc|aarch64-generic-netbsd-gnu:Clang|aarch64-generic-other-none:Clang|aarch64-generic-openbsd-gnu:Clang|END
// repr targets Aarch64Fuchsia|Some("aarch64-generic-fuchsia-gnu") Aarch64LinuxAndroid|Some("aarch64-generic-linux-android") Aarch64UnknownFreebsd|Some("aarch64-generic-freebsd-gnu") Aarch64UnknownHermit|Some("aarch64-generic-hermit-eabi") Aarch64UnknownLinuxGnu|Some("aarch64-generic-linux-gnu") Aarch64UnknownLinuxMusl|Some("aarch64-generic-linux-musl") Aarch64UnknownNetbsd|Some("aarch64-generic-netbsd-gnu") Aarch64UnknownNone|Some("aarch64-generic-other-none") Aarch64UnknownOpenbsd|Some("aarch64-generic-openbsd-gnu") Aarch64UnknownRedox|None 
#elif defined(TWO)
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
// MAPPING|THREE|arm-baseline-other-eabi:Clang|arm-baseline-other-eabihf:Clang|arm-baseline-linux-gnueabi:Gcc|arm-baseline-linux-gnueabihf:Gcc|arm-arm710t-linux-gnueabi:Gcc|arm-arm1020e-linux-gnueabi:Gcc|arm-arm1136j_s-freebsd-gnu:Clang|arm-arm1136j_s-netbsd-eabihf:Clang|arm-baseline-other-eabi:Clang|arm-baseline-other-eabihf:Clang|arm-cortex_r4-ios-none:Clang|arm-cortex_r4-other-eabi:Clang|arm-cortex_r4-other-eabihf:Clang|arm-baseline-ios-none:Clang|arm-cortex_r4-freebsd-gnu:Clang|arm-cortex_r4-linux-gnueabi:Gcc|arm-cortex_r4-linux-gnueabihf:Gcc|arm-cortex_r4-netbsd-eabihf:Clang|thumb-arm710t-other-eabi:Clang|thumb-cortex_m0-other-eabi:Clang|thumb-cortex_m4-other-eabihf:Clang|thumb-cortex_m4-other-eabi:Clang|thumb-cortex_m3-other-eabi:Clang|thumb-baseline-other-eabi:Clang|thumb-cortex_m33-other-eabihf:Clang|thumb-cortex_m33-other-eabi:Clang|END
// repr targets Armebv7rUnknownNoneEabi|Some("arm-baseline-other-eabi") Armebv7rUnknownNoneEabihf|Some("arm-baseline-other-eabihf") ArmLinuxAndroideabi|None ArmUnknownLinuxGnueabi|Some("arm-baseline-linux-gnueabi") ArmUnknownLinuxGnueabihf|Some("arm-baseline-linux-gnueabihf") Armv4tUnknownLinuxGnueabi|Some("arm-arm710t-linux-gnueabi") Armv5teUnknownLinuxGnueabi|Some("arm-arm1020e-linux-gnueabi") Armv5teUnknownLinuxUclibcgnueabi|None Armv6UnknownFreebsdGnueabihf|Some("arm-arm1136j_s-freebsd-gnu") Armv6UnknownNetbsdelfEabihf|Some("arm-arm1136j_s-netbsd-eabihf") Armv7aNoneEabi|Some("arm-baseline-other-eabi") Armv7aNoneEabihf|Some("arm-baseline-other-eabihf") Armv7AppleIos|Some("arm-cortex_r4-ios-none") Armv7NoneLinuxAndroid|None Armv7rUnknownNoneEabi|Some("arm-cortex_r4-other-eabi") Armv7rUnknownNoneEabihf|Some("arm-cortex_r4-other-eabihf") Armv7sAppleIos|Some("arm-baseline-ios-none") Armv7UnknownFreebsdGnueabihf|Some("arm-cortex_r4-freebsd-gnu") Armv7UnknownLinuxGnueabi|Some("arm-cortex_r4-linux-gnueabi") Armv7UnknownLinuxGnueabihf|Some("arm-cortex_r4-linux-gnueabihf") Armv7UnknownNetbsdelfEabihf|Some("arm-cortex_r4-netbsd-eabihf") Thumbv4tNoneEabi|Some("thumb-arm710t-other-eabi") Thumbv6mNoneEabi|Some("thumb-cortex_m0-other-eabi") Thumbv7emNoneEabihf|Some("thumb-cortex_m4-other-eabihf") Thumbv7emNoneEabi|Some("thumb-cortex_m4-other-eabi") Thumbv7mNoneEabi|Some("thumb-cortex_m3-other-eabi") Thumbv8mBaseNoneEabi|Some("thumb-baseline-other-eabi") Thumbv8mMainNoneEabihf|Some("thumb-cortex_m33-other-eabihf") Thumbv8mMainNoneEabi|Some("thumb-cortex_m33-other-eabi") 
#elif defined(THREE)
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
// MAPPING|FOUR|avr-atmega328-other-gnu:Gcc|END
// repr targets AvrUnknownUnknown|Some("avr-atmega328-other-gnu") 
#elif defined(FOUR)
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
// MAPPING|FIVE|hexagon-generic-linux-musl:Clang|i386-i386-ios-none:Clang|i386-i586-linux-gnu:Gcc|i386-i586-linux-musl:Gcc|x86_64-i686-macos-none:Clang|i386-i686-linux-android:Clang|i386-i686-freebsd-gnu:Clang|i386-i686-haiku-gnu:Clang|i386-i686-linux-gnu:Gcc|i386-i686-linux-musl:Gcc|i386-i686-netbsd-gnu:Clang|i386-i686-openbsd-gnu:Clang|mipsel-mips32-linux-gnu:Gcc|mipsel-mips32-linux-musl:Gcc|mipsel-mips32-other-none:Clang|mips-mips32-linux-gnu:Gcc|mips-mips32r6-linux-gnu:Gcc|mips-mips32-linux-gnu:Gcc|mips-mips32-linux-musl:Gcc|powerpc-ppc-linux-gnu:Gcc|powerpc-ppc-linux-musl:Gcc|powerpc-ppc-netbsd-gnu:Clang|riscv32-generic_rv32-other-none:Clang|riscv32-generic_rv32-linux-gnu:Gcc|sparc-v8-linux-gnu:Gcc|wasm32-generic-emscripten-musl:Clang|wasm32-generic-other-none:Clang|wasm32-generic-wasi-musl:Clang|x86_64-x86_64-linux-gnux32:Gcc|END
// repr targets HexagonUnknownLinuxMusl|Some("hexagon-generic-linux-musl") I386AppleIos|Some("i386-i386-ios-none") I586UnknownLinuxGnu|Some("i386-i586-linux-gnu") I586UnknownLinuxMusl|Some("i386-i586-linux-musl") I686AppleMacosx|Some("x86_64-i686-macos-none") I686LinuxAndroid|Some("i386-i686-linux-android") I686UnknownFreebsd|Some("i386-i686-freebsd-gnu") I686UnknownHaiku|Some("i386-i686-haiku-gnu") I686UnknownLinuxGnu|Some("i386-i686-linux-gnu") I686UnknownLinuxMusl|Some("i386-i686-linux-musl") I686UnknownNetbsdelf|Some("i386-i686-netbsd-gnu") I686UnknownOpenbsd|Some("i386-i686-openbsd-gnu") MipselSonyPsp|None MipselUnknownLinuxGnu|Some("mipsel-mips32-linux-gnu") MipselUnknownLinuxMusl|Some("mipsel-mips32-linux-musl") MipselUnknownLinuxUclibc|None MipselUnknownNone|Some("mipsel-mips32-other-none") Mipsisa32r6elUnknownLinuxGnu|Some("mips-mips32-linux-gnu") Mipsisa32r6UnknownLinuxGnu|Some("mips-mips32r6-linux-gnu") MipsUnknownLinuxGnu|Some("mips-mips32-linux-gnu") MipsUnknownLinuxMusl|Some("mips-mips32-linux-musl") MipsUnknownLinuxUclibc|None PowerpcUnknownLinuxGnu|Some("powerpc-ppc-linux-gnu") PowerpcUnknownLinuxGnuspe|None PowerpcUnknownLinuxMusl|Some("powerpc-ppc-linux-musl") PowerpcUnknownNetbsd|Some("powerpc-ppc-netbsd-gnu") Riscv32|Some("riscv32-generic_rv32-other-none") Riscv32UnknownLinuxGnu|Some("riscv32-generic_rv32-linux-gnu") SparcUnknownLinuxGnu|Some("sparc-v8-linux-gnu") Wasm32UnknownEmscripten|Some("wasm32-generic-emscripten-musl") Wasm32UnknownUnknown|Some("wasm32-generic-other-none") Wasm32Wasi|Some("wasm32-generic-wasi-musl") X86_64UnknownLinuxGnux32|Some("x86_64-x86_64-linux-gnux32") 
#elif defined(FIVE)
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
// MAPPING|SIX|i386-i686-windows-gnu:Gcc|x86_64-x86_64-windows-gnu:Gcc|END
// repr targets I686PcWindowsGnu|Some("i386-i686-windows-gnu") X86_64PcWindowsGnu|Some("x86_64-x86_64-windows-gnu") 
#elif defined(SIX)
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
// MAPPING|SEVEN|msp430-msp430-other-none:Clang|END
// repr targets Msp430NoneElf|Some("msp430-msp430-other-none") 
#elif defined(SEVEN)
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