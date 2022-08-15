// SPDX-License-Identifier: GPL-3.0-or-later

// This test file is auto-generated. do not edit.
// This file is a derivative work from the test files found
// in this repo : https://github.com/mahkoh/repr-c
// and is under the same licence as the original work.

typedef struct {
    long long a;
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
    long long a:1;
} B;
B var5;
struct B_alignment {
    char a;
    B b;
};
struct B_alignment var6;
#pragma pack(1)
struct B_packed {
    B a;
};
#pragma pack()
struct B_required_alignment {
    char a;
    struct B_packed b;
};
struct B_required_alignment var7;
struct B_size {
    char a[sizeof(B)+1];
    char b;
};
struct B_size var8;

typedef struct {
    char a:1;
    long long:0;
} C;
C var9;
struct C_alignment {
    char a;
    C b;
};
struct C_alignment var10;
#pragma pack(1)
struct C_packed {
    C a;
};
#pragma pack()
struct C_required_alignment {
    char a;
    struct C_packed b;
};
struct C_required_alignment var11;
struct C_size {
    char a[sizeof(C)+1];
    char b;
};
struct C_size var12;

typedef struct {
    long long:0;
} D;
D var13;
struct D_alignment {
    char a;
    D b;
};
struct D_alignment var14;
#pragma pack(1)
struct D_packed {
    D a;
};
#pragma pack()
struct D_required_alignment {
    char a;
    struct D_packed b;
};
struct D_required_alignment var15;
struct D_size {
    char a[sizeof(D)+1];
    char b;
};
struct D_size var16;

typedef struct {
    char c;
    long long:0;
} E;
E var17;
struct E_alignment {
    char a;
    E b;
};
struct E_alignment var18;
#pragma pack(1)
struct E_packed {
    E a;
};
#pragma pack()
struct E_required_alignment {
    char a;
    struct E_packed b;
};
struct E_required_alignment var19;
struct E_size {
    char a[sizeof(E)+1];
    char b;
};
struct E_size var20;

typedef struct {
    char c;
    int:0;
    long long:0;
} F;
F var21;
struct F_alignment {
    char a;
    F b;
};
struct F_alignment var22;
#pragma pack(1)
struct F_packed {
    F a;
};
#pragma pack()
struct F_required_alignment {
    char a;
    struct F_packed b;
};
struct F_required_alignment var23;
struct F_size {
    char a[sizeof(F)+1];
    char b;
};
struct F_size var24;

typedef struct {
    int a:1 __attribute__((packed));
} G;
G var25;
struct G_alignment {
    char a;
    G b;
};
struct G_alignment var26;
#pragma pack(1)
struct G_packed {
    G a;
};
#pragma pack()
struct G_required_alignment {
    char a;
    struct G_packed b;
};
struct G_required_alignment var27;
struct G_size {
    char a[sizeof(G)+1];
    char b;
};
struct G_size var28;

typedef struct {
    int a:1 __attribute__((aligned(16))) __attribute__((packed));
} H;
H var29;
struct H_alignment {
    char a;
    H b;
};
struct H_alignment var30;
#pragma pack(1)
struct H_packed {
    H a;
};
#pragma pack()
struct H_required_alignment {
    char a;
    struct H_packed b;
};
struct H_required_alignment var31;
struct H_size {
    char a[sizeof(H)+1];
    char b;
};
struct H_size var32;

typedef union {
    long long a;
} A2;
A2 var33;
struct A2_alignment {
    char a;
    A2 b;
};
struct A2_alignment var34;
#pragma pack(1)
struct A2_packed {
    A2 a;
};
#pragma pack()
struct A2_required_alignment {
    char a;
    struct A2_packed b;
};
struct A2_required_alignment var35;
struct A2_size {
    char a[sizeof(A2)+1];
    char b;
};
struct A2_size var36;

typedef union {
    long long a:1;
} B2;
B2 var37;
struct B2_alignment {
    char a;
    B2 b;
};
struct B2_alignment var38;
#pragma pack(1)
struct B2_packed {
    B2 a;
};
#pragma pack()
struct B2_required_alignment {
    char a;
    struct B2_packed b;
};
struct B2_required_alignment var39;
struct B2_size {
    char a[sizeof(B2)+1];
    char b;
};
struct B2_size var40;

typedef union {
    char a:1;
    long long:0;
} C2;
C2 var41;
struct C2_alignment {
    char a;
    C2 b;
};
struct C2_alignment var42;
#pragma pack(1)
struct C2_packed {
    C2 a;
};
#pragma pack()
struct C2_required_alignment {
    char a;
    struct C2_packed b;
};
struct C2_required_alignment var43;
struct C2_size {
    char a[sizeof(C2)+1];
    char b;
};
struct C2_size var44;

typedef union {
    long long:0;
} D2;
D2 var45;
struct D2_alignment {
    char a;
    D2 b;
};
struct D2_alignment var46;
#pragma pack(1)
struct D2_packed {
    D2 a;
};
#pragma pack()
struct D2_required_alignment {
    char a;
    struct D2_packed b;
};
struct D2_required_alignment var47;
struct D2_size {
    char a[sizeof(D2)+1];
    char b;
};
struct D2_size var48;

typedef union {
    char c;
    long long:0;
} E2;
E2 var49;
struct E2_alignment {
    char a;
    E2 b;
};
struct E2_alignment var50;
#pragma pack(1)
struct E2_packed {
    E2 a;
};
#pragma pack()
struct E2_required_alignment {
    char a;
    struct E2_packed b;
};
struct E2_required_alignment var51;
struct E2_size {
    char a[sizeof(E2)+1];
    char b;
};
struct E2_size var52;

typedef union {
    char c;
    int:0;
    long long:0;
} F2;
F2 var53;
struct F2_alignment {
    char a;
    F2 b;
};
struct F2_alignment var54;
#pragma pack(1)
struct F2_packed {
    F2 a;
};
#pragma pack()
struct F2_required_alignment {
    char a;
    struct F2_packed b;
};
struct F2_required_alignment var55;
struct F2_size {
    char a[sizeof(F2)+1];
    char b;
};
struct F2_size var56;

typedef union {
    int a:1 __attribute__((packed));
} G2;
G2 var57;
struct G2_alignment {
    char a;
    G2 b;
};
struct G2_alignment var58;
#pragma pack(1)
struct G2_packed {
    G2 a;
};
#pragma pack()
struct G2_required_alignment {
    char a;
    struct G2_packed b;
};
struct G2_required_alignment var59;
struct G2_size {
    char a[sizeof(G2)+1];
    char b;
};
struct G2_size var60;

typedef union {
    int a:1 __attribute__((aligned(16))) __attribute__((packed));
} H2;
H2 var61;
struct H2_alignment {
    char a;
    H2 b;
};
struct H2_alignment var62;
#pragma pack(1)
struct H2_packed {
    H2 a;
};
#pragma pack()
struct H2_required_alignment {
    char a;
    struct H2_packed b;
};
struct H2_required_alignment var63;
struct H2_size {
    char a[sizeof(H2)+1];
    char b;
};
struct H2_size var64;


// MAPPING|ONE|aarch64-generic-macos-none:Clang|aarch64-generic-ios-none:Clang|aarch64-generic-ios-macabi:Clang|aarch64-generic-tvos-none:Clang|hexagon-generic-linux-musl:Clang|mips64el-mips64-linux-gnuabi64:Gcc|mips64el-mips64-linux-musl:Gcc|mips64-mips64-linux-gnuabi64:Gcc|mips64-mips64-linux-musl:Gcc|mipsel-mips32-linux-gnu:Gcc|mipsel-mips32-linux-musl:Gcc|mipsel-mips32-other-eabi:Clang|mips-mips32-linux-gnu:Gcc|mips-mips32r6-linux-gnu:Gcc|mips-mips32-linux-gnuabi64:Gcc|mips-mips64r6-linux-gnuabi64:Gcc|mips-mips32-linux-gnu:Gcc|mips-mips32-linux-musl:Gcc|powerpc64le-ppc64le-linux-gnu:Gcc|powerpc64le-ppc64le-linux-musl:Gcc|powerpc64-ppc64-freebsd-gnu:Clang|powerpc64-ppc64-linux-gnu:Gcc|powerpc64-ppc64-linux-musl:Gcc|powerpc-ppc-linux-gnu:Gcc|powerpc-ppc-linux-musl:Gcc|powerpc-ppc-netbsd-gnu:Clang|riscv32-baseline_rv32-other-eabi:Clang|riscv32-baseline_rv32-linux-gnu:Gcc|riscv64-baseline_rv64-other-eabi:Clang|riscv64-baseline_rv64-linux-gnu:Gcc|s390x-generic-linux-gnu:Gcc|sparc64-v9-linux-gnu:Gcc|sparc64-v9-netbsd-gnu:Clang|sparc64-v9-openbsd-gnu:Clang|sparc-v8-linux-gnu:Gcc|sparc-v9-solaris-eabi:Clang|wasm32-generic-emscripten-musl:Clang|wasm32-generic-other-musl:Clang|wasm32-generic-wasi-musl:Clang|x86_64-x86_64-ios-macabi:Clang|x86_64-x86_64-ios-none:Clang|x86_64-x86_64-macos-none:Clang|x86_64-x86_64-tvos-none:Clang|x86_64-x86_64-other-eabi:Clang|x86_64-x86_64-fuchsia-gnu:Clang|x86_64-x86_64-linux-android:Clang|x86_64-x86_64-solaris-eabi:Clang|x86_64-x86_64-dragonfly-eabi:Clang|x86_64-x86_64-freebsd-gnu:Clang|x86_64-x86_64-haiku-gnu:Clang|x86_64-x86_64-hermit-eabi:Clang|x86_64-x86_64-linux-gnux32:Gcc|x86_64-x86_64-linux-gnu:Gcc|x86_64-x86_64-linux-musl:Gcc|x86_64-x86_64-netbsd-gnu:Clang|x86_64-x86_64-openbsd-gnu:Clang|END
// repr targets Aarch64AppleMacosx|Some("aarch64-generic-macos-none") Arm64AppleIos|Some("aarch64-generic-ios-none") Arm64AppleIosMacabi|Some("aarch64-generic-ios-macabi") Arm64AppleTvos|Some("aarch64-generic-tvos-none") HexagonUnknownLinuxMusl|Some("hexagon-generic-linux-musl") Mips64elUnknownLinuxGnuabi64|Some("mips64el-mips64-linux-gnuabi64") Mips64elUnknownLinuxMusl|Some("mips64el-mips64-linux-musl") Mips64UnknownLinuxGnuabi64|Some("mips64-mips64-linux-gnuabi64") Mips64UnknownLinuxMusl|Some("mips64-mips64-linux-musl") MipselSonyPsp|None MipselUnknownLinuxGnu|Some("mipsel-mips32-linux-gnu") MipselUnknownLinuxMusl|Some("mipsel-mips32-linux-musl") MipselUnknownLinuxUclibc|None MipselUnknownNone|Some("mipsel-mips32-other-eabi") Mipsisa32r6elUnknownLinuxGnu|Some("mips-mips32-linux-gnu") Mipsisa32r6UnknownLinuxGnu|Some("mips-mips32r6-linux-gnu") Mipsisa64r6elUnknownLinuxGnuabi64|Some("mips-mips32-linux-gnuabi64") Mipsisa64r6UnknownLinuxGnuabi64|Some("mips-mips64r6-linux-gnuabi64") MipsUnknownLinuxGnu|Some("mips-mips32-linux-gnu") MipsUnknownLinuxMusl|Some("mips-mips32-linux-musl") MipsUnknownLinuxUclibc|None Powerpc64leUnknownLinuxGnu|Some("powerpc64le-ppc64le-linux-gnu") Powerpc64leUnknownLinuxMusl|Some("powerpc64le-ppc64le-linux-musl") Powerpc64UnknownFreebsd|Some("powerpc64-ppc64-freebsd-gnu") Powerpc64UnknownLinuxGnu|Some("powerpc64-ppc64-linux-gnu") Powerpc64UnknownLinuxMusl|Some("powerpc64-ppc64-linux-musl") PowerpcUnknownLinuxGnu|Some("powerpc-ppc-linux-gnu") PowerpcUnknownLinuxGnuspe|None PowerpcUnknownLinuxMusl|Some("powerpc-ppc-linux-musl") PowerpcUnknownNetbsd|Some("powerpc-ppc-netbsd-gnu") Riscv32|Some("riscv32-baseline_rv32-other-eabi") Riscv32UnknownLinuxGnu|Some("riscv32-baseline_rv32-linux-gnu") Riscv64|Some("riscv64-baseline_rv64-other-eabi") Riscv64UnknownLinuxGnu|Some("riscv64-baseline_rv64-linux-gnu") S390xUnknownLinuxGnu|Some("s390x-generic-linux-gnu") Sparc64UnknownLinuxGnu|Some("sparc64-v9-linux-gnu") Sparc64UnknownNetbsd|Some("sparc64-v9-netbsd-gnu") Sparc64UnknownOpenbsd|Some("sparc64-v9-openbsd-gnu") SparcUnknownLinuxGnu|Some("sparc-v8-linux-gnu") Sparcv9SunSolaris|Some("sparc-v9-solaris-eabi") Wasm32UnknownEmscripten|Some("wasm32-generic-emscripten-musl") Wasm32UnknownUnknown|Some("wasm32-generic-other-musl") Wasm32Wasi|Some("wasm32-generic-wasi-musl") X86_64AppleIosMacabi|Some("x86_64-x86_64-ios-macabi") X86_64AppleIos|Some("x86_64-x86_64-ios-none") X86_64AppleMacosx|Some("x86_64-x86_64-macos-none") X86_64AppleTvos|Some("x86_64-x86_64-tvos-none") X86_64Elf|Some("x86_64-x86_64-other-eabi") X86_64Fuchsia|Some("x86_64-x86_64-fuchsia-gnu") X86_64LinuxAndroid|Some("x86_64-x86_64-linux-android") X86_64PcSolaris|Some("x86_64-x86_64-solaris-eabi") X86_64RumprunNetbsd|None X86_64UnknownDragonfly|Some("x86_64-x86_64-dragonfly-eabi") X86_64UnknownFreebsd|Some("x86_64-x86_64-freebsd-gnu") X86_64UnknownHaiku|Some("x86_64-x86_64-haiku-gnu") X86_64UnknownHermit|Some("x86_64-x86_64-hermit-eabi") X86_64UnknownL4reUclibc|None X86_64UnknownLinuxGnux32|Some("x86_64-x86_64-linux-gnux32") X86_64UnknownLinuxGnu|Some("x86_64-x86_64-linux-gnu") X86_64UnknownLinuxMusl|Some("x86_64-x86_64-linux-musl") X86_64UnknownNetbsd|Some("x86_64-x86_64-netbsd-gnu") X86_64UnknownOpenbsd|Some("x86_64-x86_64-openbsd-gnu") X86_64UnknownRedox|None 
#ifdef ONE
_Static_assert(sizeof(A) == 8, "");
_Static_assert(_Alignof(A) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 16, "");
_Static_assert(_Alignof(struct A_alignment) == 8, "");
_Static_assert(sizeof(struct A_packed) == 8, "");
_Static_assert(_Alignof(struct A_packed) == 1, "");
_Static_assert(sizeof(struct A_required_alignment) == 9, "");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "");
_Static_assert(sizeof(struct A_size) == 10, "");
_Static_assert(_Alignof(struct A_size) == 1, "");
#endif
_Static_assert(sizeof(B) == 8, "");
_Static_assert(_Alignof(B) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 16, "");
_Static_assert(_Alignof(struct B_alignment) == 8, "");
_Static_assert(sizeof(struct B_packed) == 8, "");
_Static_assert(_Alignof(struct B_packed) == 1, "");
_Static_assert(sizeof(struct B_required_alignment) == 9, "");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "");
_Static_assert(sizeof(struct B_size) == 10, "");
_Static_assert(_Alignof(struct B_size) == 1, "");
#endif
_Static_assert(sizeof(C) == 8, "");
_Static_assert(_Alignof(C) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 9, "");
_Static_assert(_Alignof(struct C_alignment) == 1, "");
_Static_assert(sizeof(struct C_packed) == 8, "");
_Static_assert(_Alignof(struct C_packed) == 1, "");
_Static_assert(sizeof(struct C_required_alignment) == 9, "");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "");
_Static_assert(sizeof(struct C_size) == 10, "");
_Static_assert(_Alignof(struct C_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(D) == 0, "");
_Static_assert(_Alignof(D) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 1, "");
_Static_assert(_Alignof(struct D_alignment) == 1, "");
_Static_assert(sizeof(struct D_packed) == 0, "");
_Static_assert(_Alignof(struct D_packed) == 1, "");
_Static_assert(sizeof(struct D_required_alignment) == 1, "");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "");
_Static_assert(sizeof(struct D_size) == 2, "");
_Static_assert(_Alignof(struct D_size) == 1, "");
#endif
_Static_assert(sizeof(E) == 8, "");
_Static_assert(_Alignof(E) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 9, "");
_Static_assert(_Alignof(struct E_alignment) == 1, "");
_Static_assert(sizeof(struct E_packed) == 8, "");
_Static_assert(_Alignof(struct E_packed) == 1, "");
_Static_assert(sizeof(struct E_required_alignment) == 9, "");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "");
_Static_assert(sizeof(struct E_size) == 10, "");
_Static_assert(_Alignof(struct E_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(F) == 8, "");
_Static_assert(_Alignof(F) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 9, "");
_Static_assert(_Alignof(struct F_alignment) == 1, "");
_Static_assert(sizeof(struct F_packed) == 8, "");
_Static_assert(_Alignof(struct F_packed) == 1, "");
_Static_assert(sizeof(struct F_required_alignment) == 9, "");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "");
_Static_assert(sizeof(struct F_size) == 10, "");
_Static_assert(_Alignof(struct F_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(G) == 1, "");
_Static_assert(_Alignof(G) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 2, "");
_Static_assert(_Alignof(struct G_alignment) == 1, "");
_Static_assert(sizeof(struct G_packed) == 1, "");
_Static_assert(_Alignof(struct G_packed) == 1, "");
_Static_assert(sizeof(struct G_required_alignment) == 2, "");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "");
_Static_assert(sizeof(struct G_size) == 3, "");
_Static_assert(_Alignof(struct G_size) == 1, "");
#endif
_Static_assert(sizeof(H) == 16, "");
_Static_assert(_Alignof(H) == 16, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 32, "");
_Static_assert(_Alignof(struct H_alignment) == 16, "");
_Static_assert(sizeof(struct H_packed) == 16, "");
_Static_assert(_Alignof(struct H_packed) == 1, "");
_Static_assert(sizeof(struct H_required_alignment) == 17, "");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "");
_Static_assert(sizeof(struct H_size) == 18, "");
_Static_assert(_Alignof(struct H_size) == 1, "");
#endif
_Static_assert(sizeof(A2) == 8, "");
_Static_assert(_Alignof(A2) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A2_alignment) == 16, "");
_Static_assert(_Alignof(struct A2_alignment) == 8, "");
_Static_assert(sizeof(struct A2_packed) == 8, "");
_Static_assert(_Alignof(struct A2_packed) == 1, "");
_Static_assert(sizeof(struct A2_required_alignment) == 9, "");
_Static_assert(_Alignof(struct A2_required_alignment) == 1, "");
_Static_assert(sizeof(struct A2_size) == 10, "");
_Static_assert(_Alignof(struct A2_size) == 1, "");
#endif
_Static_assert(sizeof(B2) == 8, "");
_Static_assert(_Alignof(B2) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B2_alignment) == 16, "");
_Static_assert(_Alignof(struct B2_alignment) == 8, "");
_Static_assert(sizeof(struct B2_packed) == 8, "");
_Static_assert(_Alignof(struct B2_packed) == 1, "");
_Static_assert(sizeof(struct B2_required_alignment) == 9, "");
_Static_assert(_Alignof(struct B2_required_alignment) == 1, "");
_Static_assert(sizeof(struct B2_size) == 10, "");
_Static_assert(_Alignof(struct B2_size) == 1, "");
#endif
_Static_assert(sizeof(C2) == 1, "");
_Static_assert(_Alignof(C2) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C2_alignment) == 2, "");
_Static_assert(_Alignof(struct C2_alignment) == 1, "");
_Static_assert(sizeof(struct C2_packed) == 1, "");
_Static_assert(_Alignof(struct C2_packed) == 1, "");
_Static_assert(sizeof(struct C2_required_alignment) == 2, "");
_Static_assert(_Alignof(struct C2_required_alignment) == 1, "");
_Static_assert(sizeof(struct C2_size) == 3, "");
_Static_assert(_Alignof(struct C2_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(D2) == 0, "");
_Static_assert(_Alignof(D2) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D2_alignment) == 1, "");
_Static_assert(_Alignof(struct D2_alignment) == 1, "");
_Static_assert(sizeof(struct D2_packed) == 0, "");
_Static_assert(_Alignof(struct D2_packed) == 1, "");
_Static_assert(sizeof(struct D2_required_alignment) == 1, "");
_Static_assert(_Alignof(struct D2_required_alignment) == 1, "");
_Static_assert(sizeof(struct D2_size) == 2, "");
_Static_assert(_Alignof(struct D2_size) == 1, "");
#endif
_Static_assert(sizeof(E2) == 1, "");
_Static_assert(_Alignof(E2) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E2_alignment) == 2, "");
_Static_assert(_Alignof(struct E2_alignment) == 1, "");
_Static_assert(sizeof(struct E2_packed) == 1, "");
_Static_assert(_Alignof(struct E2_packed) == 1, "");
_Static_assert(sizeof(struct E2_required_alignment) == 2, "");
_Static_assert(_Alignof(struct E2_required_alignment) == 1, "");
_Static_assert(sizeof(struct E2_size) == 3, "");
_Static_assert(_Alignof(struct E2_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(F2) == 1, "");
_Static_assert(_Alignof(F2) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F2_alignment) == 2, "");
_Static_assert(_Alignof(struct F2_alignment) == 1, "");
_Static_assert(sizeof(struct F2_packed) == 1, "");
_Static_assert(_Alignof(struct F2_packed) == 1, "");
_Static_assert(sizeof(struct F2_required_alignment) == 2, "");
_Static_assert(_Alignof(struct F2_required_alignment) == 1, "");
_Static_assert(sizeof(struct F2_size) == 3, "");
_Static_assert(_Alignof(struct F2_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(G2) == 1, "");
_Static_assert(_Alignof(G2) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G2_alignment) == 2, "");
_Static_assert(_Alignof(struct G2_alignment) == 1, "");
_Static_assert(sizeof(struct G2_packed) == 1, "");
_Static_assert(_Alignof(struct G2_packed) == 1, "");
_Static_assert(sizeof(struct G2_required_alignment) == 2, "");
_Static_assert(_Alignof(struct G2_required_alignment) == 1, "");
_Static_assert(sizeof(struct G2_size) == 3, "");
_Static_assert(_Alignof(struct G2_size) == 1, "");
#endif
_Static_assert(sizeof(H2) == 16, "");
_Static_assert(_Alignof(H2) == 16, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H2_alignment) == 32, "");
_Static_assert(_Alignof(struct H2_alignment) == 16, "");
_Static_assert(sizeof(struct H2_packed) == 16, "");
_Static_assert(_Alignof(struct H2_packed) == 1, "");
_Static_assert(sizeof(struct H2_required_alignment) == 17, "");
_Static_assert(_Alignof(struct H2_required_alignment) == 1, "");
_Static_assert(sizeof(struct H2_size) == 18, "");
_Static_assert(_Alignof(struct H2_size) == 1, "");
#endif
// MAPPING|TWO|aarch64-generic-fuchsia-gnu:Clang|aarch64-generic-linux-android:Clang|aarch64-generic-freebsd-gnu:Clang|aarch64-generic-hermit-eabi:Clang|aarch64-generic-linux-gnu:Gcc|aarch64-generic-linux-musl:Gcc|aarch64-generic-netbsd-gnu:Clang|aarch64-generic-other-eabi:Clang|aarch64-generic-openbsd-gnu:Clang|arm-baseline-other-eabi:Clang|arm-baseline-other-eabihf:Clang|arm-baseline-linux-gnueabi:Gcc|arm-baseline-linux-gnueabihf:Gcc|arm-arm710t-linux-gnueabi:Gcc|arm-arm1020e-linux-gnueabi:Gcc|arm-arm1136j_s-freebsd-gnueabihf:Clang|arm-arm1136j_s-netbsd-eabihf:Clang|arm-baseline-other-eabi:Clang|arm-baseline-other-eabihf:Clang|arm-cortex_r4-linux-android:Clang|arm-cortex_r4-other-eabi:Clang|arm-cortex_r4-other-eabihf:Clang|arm-cortex_r4-freebsd-gnueabihf:Clang|arm-cortex_r4-linux-gnueabi:Gcc|arm-cortex_r4-linux-gnueabihf:Gcc|arm-cortex_r4-netbsd-eabihf:Clang|thumb-arm710t-other-eabi:Clang|thumb-cortex_m0-other-eabi:Clang|thumb-cortex_m4-other-eabihf:Clang|thumb-cortex_m4-other-eabi:Clang|thumb-cortex_m3-other-eabi:Clang|thumb-baseline-other-eabi:Clang|thumb-cortex_m33-other-eabihf:Clang|thumb-cortex_m33-other-eabi:Clang|END
// repr targets Aarch64Fuchsia|Some("aarch64-generic-fuchsia-gnu") Aarch64LinuxAndroid|Some("aarch64-generic-linux-android") Aarch64UnknownFreebsd|Some("aarch64-generic-freebsd-gnu") Aarch64UnknownHermit|Some("aarch64-generic-hermit-eabi") Aarch64UnknownLinuxGnu|Some("aarch64-generic-linux-gnu") Aarch64UnknownLinuxMusl|Some("aarch64-generic-linux-musl") Aarch64UnknownNetbsd|Some("aarch64-generic-netbsd-gnu") Aarch64UnknownNone|Some("aarch64-generic-other-eabi") Aarch64UnknownOpenbsd|Some("aarch64-generic-openbsd-gnu") Aarch64UnknownRedox|None Armebv7rUnknownNoneEabi|Some("arm-baseline-other-eabi") Armebv7rUnknownNoneEabihf|Some("arm-baseline-other-eabihf") ArmLinuxAndroideabi|None ArmUnknownLinuxGnueabi|Some("arm-baseline-linux-gnueabi") ArmUnknownLinuxGnueabihf|Some("arm-baseline-linux-gnueabihf") Armv4tUnknownLinuxGnueabi|Some("arm-arm710t-linux-gnueabi") Armv5teUnknownLinuxGnueabi|Some("arm-arm1020e-linux-gnueabi") Armv5teUnknownLinuxUclibcgnueabi|None Armv6UnknownFreebsdGnueabihf|Some("arm-arm1136j_s-freebsd-gnueabihf") Armv6UnknownNetbsdelfEabihf|Some("arm-arm1136j_s-netbsd-eabihf") Armv7aNoneEabi|Some("arm-baseline-other-eabi") Armv7aNoneEabihf|Some("arm-baseline-other-eabihf") Armv7NoneLinuxAndroid|Some("arm-cortex_r4-linux-android") Armv7rUnknownNoneEabi|Some("arm-cortex_r4-other-eabi") Armv7rUnknownNoneEabihf|Some("arm-cortex_r4-other-eabihf") Armv7UnknownFreebsdGnueabihf|Some("arm-cortex_r4-freebsd-gnueabihf") Armv7UnknownLinuxGnueabi|Some("arm-cortex_r4-linux-gnueabi") Armv7UnknownLinuxGnueabihf|Some("arm-cortex_r4-linux-gnueabihf") Armv7UnknownNetbsdelfEabihf|Some("arm-cortex_r4-netbsd-eabihf") Thumbv4tNoneEabi|Some("thumb-arm710t-other-eabi") Thumbv6mNoneEabi|Some("thumb-cortex_m0-other-eabi") Thumbv7emNoneEabihf|Some("thumb-cortex_m4-other-eabihf") Thumbv7emNoneEabi|Some("thumb-cortex_m4-other-eabi") Thumbv7mNoneEabi|Some("thumb-cortex_m3-other-eabi") Thumbv8mBaseNoneEabi|Some("thumb-baseline-other-eabi") Thumbv8mMainNoneEabihf|Some("thumb-cortex_m33-other-eabihf") Thumbv8mMainNoneEabi|Some("thumb-cortex_m33-other-eabi") 
#elif defined(TWO)
_Static_assert(sizeof(A) == 8, "");
_Static_assert(_Alignof(A) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 16, "");
_Static_assert(_Alignof(struct A_alignment) == 8, "");
_Static_assert(sizeof(struct A_packed) == 8, "");
_Static_assert(_Alignof(struct A_packed) == 1, "");
_Static_assert(sizeof(struct A_required_alignment) == 9, "");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "");
_Static_assert(sizeof(struct A_size) == 10, "");
_Static_assert(_Alignof(struct A_size) == 1, "");
#endif
_Static_assert(sizeof(B) == 8, "");
_Static_assert(_Alignof(B) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 16, "");
_Static_assert(_Alignof(struct B_alignment) == 8, "");
_Static_assert(sizeof(struct B_packed) == 8, "");
_Static_assert(_Alignof(struct B_packed) == 1, "");
_Static_assert(sizeof(struct B_required_alignment) == 9, "");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "");
_Static_assert(sizeof(struct B_size) == 10, "");
_Static_assert(_Alignof(struct B_size) == 1, "");
#endif
_Static_assert(sizeof(C) == 8, "");
_Static_assert(_Alignof(C) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 16, "");
_Static_assert(_Alignof(struct C_alignment) == 8, "");
_Static_assert(sizeof(struct C_packed) == 8, "");
_Static_assert(_Alignof(struct C_packed) == 1, "");
_Static_assert(sizeof(struct C_required_alignment) == 9, "");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "");
_Static_assert(sizeof(struct C_size) == 10, "");
_Static_assert(_Alignof(struct C_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(D) == 0, "");
_Static_assert(_Alignof(D) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 8, "");
_Static_assert(_Alignof(struct D_alignment) == 8, "");
_Static_assert(sizeof(struct D_packed) == 0, "");
_Static_assert(_Alignof(struct D_packed) == 1, "");
_Static_assert(sizeof(struct D_required_alignment) == 1, "");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "");
_Static_assert(sizeof(struct D_size) == 2, "");
_Static_assert(_Alignof(struct D_size) == 1, "");
#endif
_Static_assert(sizeof(E) == 8, "");
_Static_assert(_Alignof(E) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 16, "");
_Static_assert(_Alignof(struct E_alignment) == 8, "");
_Static_assert(sizeof(struct E_packed) == 8, "");
_Static_assert(_Alignof(struct E_packed) == 1, "");
_Static_assert(sizeof(struct E_required_alignment) == 9, "");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "");
_Static_assert(sizeof(struct E_size) == 10, "");
_Static_assert(_Alignof(struct E_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(F) == 8, "");
_Static_assert(_Alignof(F) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 16, "");
_Static_assert(_Alignof(struct F_alignment) == 8, "");
_Static_assert(sizeof(struct F_packed) == 8, "");
_Static_assert(_Alignof(struct F_packed) == 1, "");
_Static_assert(sizeof(struct F_required_alignment) == 9, "");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "");
_Static_assert(sizeof(struct F_size) == 10, "");
_Static_assert(_Alignof(struct F_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(G) == 1, "");
_Static_assert(_Alignof(G) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 2, "");
_Static_assert(_Alignof(struct G_alignment) == 1, "");
_Static_assert(sizeof(struct G_packed) == 1, "");
_Static_assert(_Alignof(struct G_packed) == 1, "");
_Static_assert(sizeof(struct G_required_alignment) == 2, "");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "");
_Static_assert(sizeof(struct G_size) == 3, "");
_Static_assert(_Alignof(struct G_size) == 1, "");
#endif
_Static_assert(sizeof(H) == 16, "");
_Static_assert(_Alignof(H) == 16, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 32, "");
_Static_assert(_Alignof(struct H_alignment) == 16, "");
_Static_assert(sizeof(struct H_packed) == 16, "");
_Static_assert(_Alignof(struct H_packed) == 1, "");
_Static_assert(sizeof(struct H_required_alignment) == 17, "");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "");
_Static_assert(sizeof(struct H_size) == 18, "");
_Static_assert(_Alignof(struct H_size) == 1, "");
#endif
_Static_assert(sizeof(A2) == 8, "");
_Static_assert(_Alignof(A2) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A2_alignment) == 16, "");
_Static_assert(_Alignof(struct A2_alignment) == 8, "");
_Static_assert(sizeof(struct A2_packed) == 8, "");
_Static_assert(_Alignof(struct A2_packed) == 1, "");
_Static_assert(sizeof(struct A2_required_alignment) == 9, "");
_Static_assert(_Alignof(struct A2_required_alignment) == 1, "");
_Static_assert(sizeof(struct A2_size) == 10, "");
_Static_assert(_Alignof(struct A2_size) == 1, "");
#endif
_Static_assert(sizeof(B2) == 8, "");
_Static_assert(_Alignof(B2) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B2_alignment) == 16, "");
_Static_assert(_Alignof(struct B2_alignment) == 8, "");
_Static_assert(sizeof(struct B2_packed) == 8, "");
_Static_assert(_Alignof(struct B2_packed) == 1, "");
_Static_assert(sizeof(struct B2_required_alignment) == 9, "");
_Static_assert(_Alignof(struct B2_required_alignment) == 1, "");
_Static_assert(sizeof(struct B2_size) == 10, "");
_Static_assert(_Alignof(struct B2_size) == 1, "");
#endif
_Static_assert(sizeof(C2) == 8, "");
_Static_assert(_Alignof(C2) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C2_alignment) == 16, "");
_Static_assert(_Alignof(struct C2_alignment) == 8, "");
_Static_assert(sizeof(struct C2_packed) == 8, "");
_Static_assert(_Alignof(struct C2_packed) == 1, "");
_Static_assert(sizeof(struct C2_required_alignment) == 9, "");
_Static_assert(_Alignof(struct C2_required_alignment) == 1, "");
_Static_assert(sizeof(struct C2_size) == 10, "");
_Static_assert(_Alignof(struct C2_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(D2) == 0, "");
_Static_assert(_Alignof(D2) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D2_alignment) == 8, "");
_Static_assert(_Alignof(struct D2_alignment) == 8, "");
_Static_assert(sizeof(struct D2_packed) == 0, "");
_Static_assert(_Alignof(struct D2_packed) == 1, "");
_Static_assert(sizeof(struct D2_required_alignment) == 1, "");
_Static_assert(_Alignof(struct D2_required_alignment) == 1, "");
_Static_assert(sizeof(struct D2_size) == 2, "");
_Static_assert(_Alignof(struct D2_size) == 1, "");
#endif
_Static_assert(sizeof(E2) == 8, "");
_Static_assert(_Alignof(E2) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E2_alignment) == 16, "");
_Static_assert(_Alignof(struct E2_alignment) == 8, "");
_Static_assert(sizeof(struct E2_packed) == 8, "");
_Static_assert(_Alignof(struct E2_packed) == 1, "");
_Static_assert(sizeof(struct E2_required_alignment) == 9, "");
_Static_assert(_Alignof(struct E2_required_alignment) == 1, "");
_Static_assert(sizeof(struct E2_size) == 10, "");
_Static_assert(_Alignof(struct E2_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(F2) == 8, "");
_Static_assert(_Alignof(F2) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F2_alignment) == 16, "");
_Static_assert(_Alignof(struct F2_alignment) == 8, "");
_Static_assert(sizeof(struct F2_packed) == 8, "");
_Static_assert(_Alignof(struct F2_packed) == 1, "");
_Static_assert(sizeof(struct F2_required_alignment) == 9, "");
_Static_assert(_Alignof(struct F2_required_alignment) == 1, "");
_Static_assert(sizeof(struct F2_size) == 10, "");
_Static_assert(_Alignof(struct F2_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(G2) == 1, "");
_Static_assert(_Alignof(G2) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G2_alignment) == 2, "");
_Static_assert(_Alignof(struct G2_alignment) == 1, "");
_Static_assert(sizeof(struct G2_packed) == 1, "");
_Static_assert(_Alignof(struct G2_packed) == 1, "");
_Static_assert(sizeof(struct G2_required_alignment) == 2, "");
_Static_assert(_Alignof(struct G2_required_alignment) == 1, "");
_Static_assert(sizeof(struct G2_size) == 3, "");
_Static_assert(_Alignof(struct G2_size) == 1, "");
#endif
_Static_assert(sizeof(H2) == 16, "");
_Static_assert(_Alignof(H2) == 16, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H2_alignment) == 32, "");
_Static_assert(_Alignof(struct H2_alignment) == 16, "");
_Static_assert(sizeof(struct H2_packed) == 16, "");
_Static_assert(_Alignof(struct H2_packed) == 1, "");
_Static_assert(sizeof(struct H2_required_alignment) == 17, "");
_Static_assert(_Alignof(struct H2_required_alignment) == 1, "");
_Static_assert(sizeof(struct H2_size) == 18, "");
_Static_assert(_Alignof(struct H2_size) == 1, "");
#endif
// MAPPING|THREE|arm-cortex_r4-ios-none:Clang|arm-baseline-ios-none:Clang|END
// repr targets Armv7AppleIos|Some("arm-cortex_r4-ios-none") Armv7sAppleIos|Some("arm-baseline-ios-none") 
#elif defined(THREE)
_Static_assert(sizeof(A) == 8, "");
_Static_assert(_Alignof(A) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 12, "");
_Static_assert(_Alignof(struct A_alignment) == 4, "");
_Static_assert(sizeof(struct A_packed) == 8, "");
_Static_assert(_Alignof(struct A_packed) == 1, "");
_Static_assert(sizeof(struct A_required_alignment) == 9, "");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "");
_Static_assert(sizeof(struct A_size) == 10, "");
_Static_assert(_Alignof(struct A_size) == 1, "");
#endif
_Static_assert(sizeof(B) == 1, "");
_Static_assert(_Alignof(B) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 2, "");
_Static_assert(_Alignof(struct B_alignment) == 1, "");
_Static_assert(sizeof(struct B_packed) == 1, "");
_Static_assert(_Alignof(struct B_packed) == 1, "");
_Static_assert(sizeof(struct B_required_alignment) == 2, "");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "");
_Static_assert(sizeof(struct B_size) == 3, "");
_Static_assert(_Alignof(struct B_size) == 1, "");
#endif
_Static_assert(sizeof(C) == 4, "");
_Static_assert(_Alignof(C) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 8, "");
_Static_assert(_Alignof(struct C_alignment) == 4, "");
_Static_assert(sizeof(struct C_packed) == 4, "");
_Static_assert(_Alignof(struct C_packed) == 1, "");
_Static_assert(sizeof(struct C_required_alignment) == 5, "");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "");
_Static_assert(sizeof(struct C_size) == 6, "");
_Static_assert(_Alignof(struct C_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(D) == 0, "");
_Static_assert(_Alignof(D) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 4, "");
_Static_assert(_Alignof(struct D_alignment) == 4, "");
_Static_assert(sizeof(struct D_packed) == 0, "");
_Static_assert(_Alignof(struct D_packed) == 1, "");
_Static_assert(sizeof(struct D_required_alignment) == 1, "");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "");
_Static_assert(sizeof(struct D_size) == 2, "");
_Static_assert(_Alignof(struct D_size) == 1, "");
#endif
_Static_assert(sizeof(E) == 4, "");
_Static_assert(_Alignof(E) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 8, "");
_Static_assert(_Alignof(struct E_alignment) == 4, "");
_Static_assert(sizeof(struct E_packed) == 4, "");
_Static_assert(_Alignof(struct E_packed) == 1, "");
_Static_assert(sizeof(struct E_required_alignment) == 5, "");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "");
_Static_assert(sizeof(struct E_size) == 6, "");
_Static_assert(_Alignof(struct E_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(F) == 4, "");
_Static_assert(_Alignof(F) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 8, "");
_Static_assert(_Alignof(struct F_alignment) == 4, "");
_Static_assert(sizeof(struct F_packed) == 4, "");
_Static_assert(_Alignof(struct F_packed) == 1, "");
_Static_assert(sizeof(struct F_required_alignment) == 5, "");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "");
_Static_assert(sizeof(struct F_size) == 6, "");
_Static_assert(_Alignof(struct F_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(G) == 1, "");
_Static_assert(_Alignof(G) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 2, "");
_Static_assert(_Alignof(struct G_alignment) == 1, "");
_Static_assert(sizeof(struct G_packed) == 1, "");
_Static_assert(_Alignof(struct G_packed) == 1, "");
_Static_assert(sizeof(struct G_required_alignment) == 2, "");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "");
_Static_assert(sizeof(struct G_size) == 3, "");
_Static_assert(_Alignof(struct G_size) == 1, "");
#endif
_Static_assert(sizeof(H) == 16, "");
_Static_assert(_Alignof(H) == 16, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 32, "");
_Static_assert(_Alignof(struct H_alignment) == 16, "");
_Static_assert(sizeof(struct H_packed) == 16, "");
_Static_assert(_Alignof(struct H_packed) == 1, "");
_Static_assert(sizeof(struct H_required_alignment) == 17, "");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "");
_Static_assert(sizeof(struct H_size) == 18, "");
_Static_assert(_Alignof(struct H_size) == 1, "");
#endif
_Static_assert(sizeof(A2) == 8, "");
_Static_assert(_Alignof(A2) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A2_alignment) == 12, "");
_Static_assert(_Alignof(struct A2_alignment) == 4, "");
_Static_assert(sizeof(struct A2_packed) == 8, "");
_Static_assert(_Alignof(struct A2_packed) == 1, "");
_Static_assert(sizeof(struct A2_required_alignment) == 9, "");
_Static_assert(_Alignof(struct A2_required_alignment) == 1, "");
_Static_assert(sizeof(struct A2_size) == 10, "");
_Static_assert(_Alignof(struct A2_size) == 1, "");
#endif
_Static_assert(sizeof(B2) == 1, "");
_Static_assert(_Alignof(B2) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B2_alignment) == 2, "");
_Static_assert(_Alignof(struct B2_alignment) == 1, "");
_Static_assert(sizeof(struct B2_packed) == 1, "");
_Static_assert(_Alignof(struct B2_packed) == 1, "");
_Static_assert(sizeof(struct B2_required_alignment) == 2, "");
_Static_assert(_Alignof(struct B2_required_alignment) == 1, "");
_Static_assert(sizeof(struct B2_size) == 3, "");
_Static_assert(_Alignof(struct B2_size) == 1, "");
#endif
_Static_assert(sizeof(C2) == 4, "");
_Static_assert(_Alignof(C2) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C2_alignment) == 8, "");
_Static_assert(_Alignof(struct C2_alignment) == 4, "");
_Static_assert(sizeof(struct C2_packed) == 4, "");
_Static_assert(_Alignof(struct C2_packed) == 1, "");
_Static_assert(sizeof(struct C2_required_alignment) == 5, "");
_Static_assert(_Alignof(struct C2_required_alignment) == 1, "");
_Static_assert(sizeof(struct C2_size) == 6, "");
_Static_assert(_Alignof(struct C2_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(D2) == 0, "");
_Static_assert(_Alignof(D2) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D2_alignment) == 4, "");
_Static_assert(_Alignof(struct D2_alignment) == 4, "");
_Static_assert(sizeof(struct D2_packed) == 0, "");
_Static_assert(_Alignof(struct D2_packed) == 1, "");
_Static_assert(sizeof(struct D2_required_alignment) == 1, "");
_Static_assert(_Alignof(struct D2_required_alignment) == 1, "");
_Static_assert(sizeof(struct D2_size) == 2, "");
_Static_assert(_Alignof(struct D2_size) == 1, "");
#endif
_Static_assert(sizeof(E2) == 4, "");
_Static_assert(_Alignof(E2) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E2_alignment) == 8, "");
_Static_assert(_Alignof(struct E2_alignment) == 4, "");
_Static_assert(sizeof(struct E2_packed) == 4, "");
_Static_assert(_Alignof(struct E2_packed) == 1, "");
_Static_assert(sizeof(struct E2_required_alignment) == 5, "");
_Static_assert(_Alignof(struct E2_required_alignment) == 1, "");
_Static_assert(sizeof(struct E2_size) == 6, "");
_Static_assert(_Alignof(struct E2_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(F2) == 4, "");
_Static_assert(_Alignof(F2) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F2_alignment) == 8, "");
_Static_assert(_Alignof(struct F2_alignment) == 4, "");
_Static_assert(sizeof(struct F2_packed) == 4, "");
_Static_assert(_Alignof(struct F2_packed) == 1, "");
_Static_assert(sizeof(struct F2_required_alignment) == 5, "");
_Static_assert(_Alignof(struct F2_required_alignment) == 1, "");
_Static_assert(sizeof(struct F2_size) == 6, "");
_Static_assert(_Alignof(struct F2_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(G2) == 1, "");
_Static_assert(_Alignof(G2) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G2_alignment) == 2, "");
_Static_assert(_Alignof(struct G2_alignment) == 1, "");
_Static_assert(sizeof(struct G2_packed) == 1, "");
_Static_assert(_Alignof(struct G2_packed) == 1, "");
_Static_assert(sizeof(struct G2_required_alignment) == 2, "");
_Static_assert(_Alignof(struct G2_required_alignment) == 1, "");
_Static_assert(sizeof(struct G2_size) == 3, "");
_Static_assert(_Alignof(struct G2_size) == 1, "");
#endif
_Static_assert(sizeof(H2) == 16, "");
_Static_assert(_Alignof(H2) == 16, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H2_alignment) == 32, "");
_Static_assert(_Alignof(struct H2_alignment) == 16, "");
_Static_assert(sizeof(struct H2_packed) == 16, "");
_Static_assert(_Alignof(struct H2_packed) == 1, "");
_Static_assert(sizeof(struct H2_required_alignment) == 17, "");
_Static_assert(_Alignof(struct H2_required_alignment) == 1, "");
_Static_assert(sizeof(struct H2_size) == 18, "");
_Static_assert(_Alignof(struct H2_size) == 1, "");
#endif
// MAPPING|FOUR|avr-avr2-other-eabi:Gcc|END
// repr targets AvrUnknownUnknown|Some("avr-avr2-other-eabi") 
#elif defined(FOUR)
_Static_assert(sizeof(A) == 8, "");
_Static_assert(_Alignof(A) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 9, "");
_Static_assert(_Alignof(struct A_alignment) == 1, "");
_Static_assert(sizeof(struct A_packed) == 8, "");
_Static_assert(_Alignof(struct A_packed) == 1, "");
_Static_assert(sizeof(struct A_required_alignment) == 9, "");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "");
_Static_assert(sizeof(struct A_size) == 10, "");
_Static_assert(_Alignof(struct A_size) == 1, "");
#endif
_Static_assert(sizeof(B) == 1, "");
_Static_assert(_Alignof(B) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 2, "");
_Static_assert(_Alignof(struct B_alignment) == 1, "");
_Static_assert(sizeof(struct B_packed) == 1, "");
_Static_assert(_Alignof(struct B_packed) == 1, "");
_Static_assert(sizeof(struct B_required_alignment) == 2, "");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "");
_Static_assert(sizeof(struct B_size) == 3, "");
_Static_assert(_Alignof(struct B_size) == 1, "");
#endif
_Static_assert(sizeof(C) == 1, "");
_Static_assert(_Alignof(C) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 2, "");
_Static_assert(_Alignof(struct C_alignment) == 1, "");
_Static_assert(sizeof(struct C_packed) == 1, "");
_Static_assert(_Alignof(struct C_packed) == 1, "");
_Static_assert(sizeof(struct C_required_alignment) == 2, "");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "");
_Static_assert(sizeof(struct C_size) == 3, "");
_Static_assert(_Alignof(struct C_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(D) == 0, "");
_Static_assert(_Alignof(D) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 1, "");
_Static_assert(_Alignof(struct D_alignment) == 1, "");
_Static_assert(sizeof(struct D_packed) == 0, "");
_Static_assert(_Alignof(struct D_packed) == 1, "");
_Static_assert(sizeof(struct D_required_alignment) == 1, "");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "");
_Static_assert(sizeof(struct D_size) == 2, "");
_Static_assert(_Alignof(struct D_size) == 1, "");
#endif
_Static_assert(sizeof(E) == 1, "");
_Static_assert(_Alignof(E) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 2, "");
_Static_assert(_Alignof(struct E_alignment) == 1, "");
_Static_assert(sizeof(struct E_packed) == 1, "");
_Static_assert(_Alignof(struct E_packed) == 1, "");
_Static_assert(sizeof(struct E_required_alignment) == 2, "");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "");
_Static_assert(sizeof(struct E_size) == 3, "");
_Static_assert(_Alignof(struct E_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(F) == 1, "");
_Static_assert(_Alignof(F) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 2, "");
_Static_assert(_Alignof(struct F_alignment) == 1, "");
_Static_assert(sizeof(struct F_packed) == 1, "");
_Static_assert(_Alignof(struct F_packed) == 1, "");
_Static_assert(sizeof(struct F_required_alignment) == 2, "");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "");
_Static_assert(sizeof(struct F_size) == 3, "");
_Static_assert(_Alignof(struct F_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(G) == 1, "");
_Static_assert(_Alignof(G) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 2, "");
_Static_assert(_Alignof(struct G_alignment) == 1, "");
_Static_assert(sizeof(struct G_packed) == 1, "");
_Static_assert(_Alignof(struct G_packed) == 1, "");
_Static_assert(sizeof(struct G_required_alignment) == 2, "");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "");
_Static_assert(sizeof(struct G_size) == 3, "");
_Static_assert(_Alignof(struct G_size) == 1, "");
#endif
_Static_assert(sizeof(H) == 16, "");
_Static_assert(_Alignof(H) == 16, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 32, "");
_Static_assert(_Alignof(struct H_alignment) == 16, "");
_Static_assert(sizeof(struct H_packed) == 16, "");
_Static_assert(_Alignof(struct H_packed) == 1, "");
_Static_assert(sizeof(struct H_required_alignment) == 17, "");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "");
_Static_assert(sizeof(struct H_size) == 18, "");
_Static_assert(_Alignof(struct H_size) == 1, "");
#endif
_Static_assert(sizeof(A2) == 8, "");
_Static_assert(_Alignof(A2) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A2_alignment) == 9, "");
_Static_assert(_Alignof(struct A2_alignment) == 1, "");
_Static_assert(sizeof(struct A2_packed) == 8, "");
_Static_assert(_Alignof(struct A2_packed) == 1, "");
_Static_assert(sizeof(struct A2_required_alignment) == 9, "");
_Static_assert(_Alignof(struct A2_required_alignment) == 1, "");
_Static_assert(sizeof(struct A2_size) == 10, "");
_Static_assert(_Alignof(struct A2_size) == 1, "");
#endif
_Static_assert(sizeof(B2) == 1, "");
_Static_assert(_Alignof(B2) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B2_alignment) == 2, "");
_Static_assert(_Alignof(struct B2_alignment) == 1, "");
_Static_assert(sizeof(struct B2_packed) == 1, "");
_Static_assert(_Alignof(struct B2_packed) == 1, "");
_Static_assert(sizeof(struct B2_required_alignment) == 2, "");
_Static_assert(_Alignof(struct B2_required_alignment) == 1, "");
_Static_assert(sizeof(struct B2_size) == 3, "");
_Static_assert(_Alignof(struct B2_size) == 1, "");
#endif
_Static_assert(sizeof(C2) == 1, "");
_Static_assert(_Alignof(C2) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C2_alignment) == 2, "");
_Static_assert(_Alignof(struct C2_alignment) == 1, "");
_Static_assert(sizeof(struct C2_packed) == 1, "");
_Static_assert(_Alignof(struct C2_packed) == 1, "");
_Static_assert(sizeof(struct C2_required_alignment) == 2, "");
_Static_assert(_Alignof(struct C2_required_alignment) == 1, "");
_Static_assert(sizeof(struct C2_size) == 3, "");
_Static_assert(_Alignof(struct C2_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(D2) == 0, "");
_Static_assert(_Alignof(D2) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D2_alignment) == 1, "");
_Static_assert(_Alignof(struct D2_alignment) == 1, "");
_Static_assert(sizeof(struct D2_packed) == 0, "");
_Static_assert(_Alignof(struct D2_packed) == 1, "");
_Static_assert(sizeof(struct D2_required_alignment) == 1, "");
_Static_assert(_Alignof(struct D2_required_alignment) == 1, "");
_Static_assert(sizeof(struct D2_size) == 2, "");
_Static_assert(_Alignof(struct D2_size) == 1, "");
#endif
_Static_assert(sizeof(E2) == 1, "");
_Static_assert(_Alignof(E2) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E2_alignment) == 2, "");
_Static_assert(_Alignof(struct E2_alignment) == 1, "");
_Static_assert(sizeof(struct E2_packed) == 1, "");
_Static_assert(_Alignof(struct E2_packed) == 1, "");
_Static_assert(sizeof(struct E2_required_alignment) == 2, "");
_Static_assert(_Alignof(struct E2_required_alignment) == 1, "");
_Static_assert(sizeof(struct E2_size) == 3, "");
_Static_assert(_Alignof(struct E2_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(F2) == 1, "");
_Static_assert(_Alignof(F2) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F2_alignment) == 2, "");
_Static_assert(_Alignof(struct F2_alignment) == 1, "");
_Static_assert(sizeof(struct F2_packed) == 1, "");
_Static_assert(_Alignof(struct F2_packed) == 1, "");
_Static_assert(sizeof(struct F2_required_alignment) == 2, "");
_Static_assert(_Alignof(struct F2_required_alignment) == 1, "");
_Static_assert(sizeof(struct F2_size) == 3, "");
_Static_assert(_Alignof(struct F2_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(G2) == 1, "");
_Static_assert(_Alignof(G2) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G2_alignment) == 2, "");
_Static_assert(_Alignof(struct G2_alignment) == 1, "");
_Static_assert(sizeof(struct G2_packed) == 1, "");
_Static_assert(_Alignof(struct G2_packed) == 1, "");
_Static_assert(sizeof(struct G2_required_alignment) == 2, "");
_Static_assert(_Alignof(struct G2_required_alignment) == 1, "");
_Static_assert(sizeof(struct G2_size) == 3, "");
_Static_assert(_Alignof(struct G2_size) == 1, "");
#endif
_Static_assert(sizeof(H2) == 16, "");
_Static_assert(_Alignof(H2) == 16, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H2_alignment) == 32, "");
_Static_assert(_Alignof(struct H2_alignment) == 16, "");
_Static_assert(sizeof(struct H2_packed) == 16, "");
_Static_assert(_Alignof(struct H2_packed) == 1, "");
_Static_assert(sizeof(struct H2_required_alignment) == 17, "");
_Static_assert(_Alignof(struct H2_required_alignment) == 1, "");
_Static_assert(sizeof(struct H2_size) == 18, "");
_Static_assert(_Alignof(struct H2_size) == 1, "");
#endif
// MAPPING|FIVE|i386-i386-ios-none:Clang|i386-i586-linux-gnu:Gcc|i386-i586-linux-musl:Gcc|i386-i686-macos-none:Clang|i386-i686-linux-android:Clang|i386-i686-freebsd-gnu:Clang|i386-i686-haiku-gnu:Clang|i386-i686-linux-gnu:Gcc|i386-i686-linux-musl:Gcc|i386-i686-netbsd-gnu:Clang|i386-i686-openbsd-gnu:Clang|END
// repr targets I386AppleIos|Some("i386-i386-ios-none") I586UnknownLinuxGnu|Some("i386-i586-linux-gnu") I586UnknownLinuxMusl|Some("i386-i586-linux-musl") I686AppleMacosx|Some("i386-i686-macos-none") I686LinuxAndroid|Some("i386-i686-linux-android") I686UnknownFreebsd|Some("i386-i686-freebsd-gnu") I686UnknownHaiku|Some("i386-i686-haiku-gnu") I686UnknownLinuxGnu|Some("i386-i686-linux-gnu") I686UnknownLinuxMusl|Some("i386-i686-linux-musl") I686UnknownNetbsdelf|Some("i386-i686-netbsd-gnu") I686UnknownOpenbsd|Some("i386-i686-openbsd-gnu") 
#elif defined(FIVE)
_Static_assert(sizeof(A) == 8, "");
_Static_assert(_Alignof(A) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 12, "");
_Static_assert(_Alignof(struct A_alignment) == 4, "");
_Static_assert(sizeof(struct A_packed) == 8, "");
_Static_assert(_Alignof(struct A_packed) == 1, "");
_Static_assert(sizeof(struct A_required_alignment) == 9, "");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "");
_Static_assert(sizeof(struct A_size) == 10, "");
_Static_assert(_Alignof(struct A_size) == 1, "");
#endif
_Static_assert(sizeof(B) == 4, "");
_Static_assert(_Alignof(B) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 8, "");
_Static_assert(_Alignof(struct B_alignment) == 4, "");
_Static_assert(sizeof(struct B_packed) == 4, "");
_Static_assert(_Alignof(struct B_packed) == 1, "");
_Static_assert(sizeof(struct B_required_alignment) == 5, "");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "");
_Static_assert(sizeof(struct B_size) == 6, "");
_Static_assert(_Alignof(struct B_size) == 1, "");
#endif
_Static_assert(sizeof(C) == 4, "");
_Static_assert(_Alignof(C) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 5, "");
_Static_assert(_Alignof(struct C_alignment) == 1, "");
_Static_assert(sizeof(struct C_packed) == 4, "");
_Static_assert(_Alignof(struct C_packed) == 1, "");
_Static_assert(sizeof(struct C_required_alignment) == 5, "");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "");
_Static_assert(sizeof(struct C_size) == 6, "");
_Static_assert(_Alignof(struct C_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(D) == 0, "");
_Static_assert(_Alignof(D) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 1, "");
_Static_assert(_Alignof(struct D_alignment) == 1, "");
_Static_assert(sizeof(struct D_packed) == 0, "");
_Static_assert(_Alignof(struct D_packed) == 1, "");
_Static_assert(sizeof(struct D_required_alignment) == 1, "");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "");
_Static_assert(sizeof(struct D_size) == 2, "");
_Static_assert(_Alignof(struct D_size) == 1, "");
#endif
_Static_assert(sizeof(E) == 4, "");
_Static_assert(_Alignof(E) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 5, "");
_Static_assert(_Alignof(struct E_alignment) == 1, "");
_Static_assert(sizeof(struct E_packed) == 4, "");
_Static_assert(_Alignof(struct E_packed) == 1, "");
_Static_assert(sizeof(struct E_required_alignment) == 5, "");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "");
_Static_assert(sizeof(struct E_size) == 6, "");
_Static_assert(_Alignof(struct E_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(F) == 4, "");
_Static_assert(_Alignof(F) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 5, "");
_Static_assert(_Alignof(struct F_alignment) == 1, "");
_Static_assert(sizeof(struct F_packed) == 4, "");
_Static_assert(_Alignof(struct F_packed) == 1, "");
_Static_assert(sizeof(struct F_required_alignment) == 5, "");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "");
_Static_assert(sizeof(struct F_size) == 6, "");
_Static_assert(_Alignof(struct F_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(G) == 1, "");
_Static_assert(_Alignof(G) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 2, "");
_Static_assert(_Alignof(struct G_alignment) == 1, "");
_Static_assert(sizeof(struct G_packed) == 1, "");
_Static_assert(_Alignof(struct G_packed) == 1, "");
_Static_assert(sizeof(struct G_required_alignment) == 2, "");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "");
_Static_assert(sizeof(struct G_size) == 3, "");
_Static_assert(_Alignof(struct G_size) == 1, "");
#endif
_Static_assert(sizeof(H) == 16, "");
_Static_assert(_Alignof(H) == 16, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 32, "");
_Static_assert(_Alignof(struct H_alignment) == 16, "");
_Static_assert(sizeof(struct H_packed) == 16, "");
_Static_assert(_Alignof(struct H_packed) == 1, "");
_Static_assert(sizeof(struct H_required_alignment) == 17, "");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "");
_Static_assert(sizeof(struct H_size) == 18, "");
_Static_assert(_Alignof(struct H_size) == 1, "");
#endif
_Static_assert(sizeof(A2) == 8, "");
_Static_assert(_Alignof(A2) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A2_alignment) == 12, "");
_Static_assert(_Alignof(struct A2_alignment) == 4, "");
_Static_assert(sizeof(struct A2_packed) == 8, "");
_Static_assert(_Alignof(struct A2_packed) == 1, "");
_Static_assert(sizeof(struct A2_required_alignment) == 9, "");
_Static_assert(_Alignof(struct A2_required_alignment) == 1, "");
_Static_assert(sizeof(struct A2_size) == 10, "");
_Static_assert(_Alignof(struct A2_size) == 1, "");
#endif
_Static_assert(sizeof(B2) == 4, "");
_Static_assert(_Alignof(B2) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B2_alignment) == 8, "");
_Static_assert(_Alignof(struct B2_alignment) == 4, "");
_Static_assert(sizeof(struct B2_packed) == 4, "");
_Static_assert(_Alignof(struct B2_packed) == 1, "");
_Static_assert(sizeof(struct B2_required_alignment) == 5, "");
_Static_assert(_Alignof(struct B2_required_alignment) == 1, "");
_Static_assert(sizeof(struct B2_size) == 6, "");
_Static_assert(_Alignof(struct B2_size) == 1, "");
#endif
_Static_assert(sizeof(C2) == 1, "");
_Static_assert(_Alignof(C2) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C2_alignment) == 2, "");
_Static_assert(_Alignof(struct C2_alignment) == 1, "");
_Static_assert(sizeof(struct C2_packed) == 1, "");
_Static_assert(_Alignof(struct C2_packed) == 1, "");
_Static_assert(sizeof(struct C2_required_alignment) == 2, "");
_Static_assert(_Alignof(struct C2_required_alignment) == 1, "");
_Static_assert(sizeof(struct C2_size) == 3, "");
_Static_assert(_Alignof(struct C2_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(D2) == 0, "");
_Static_assert(_Alignof(D2) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D2_alignment) == 1, "");
_Static_assert(_Alignof(struct D2_alignment) == 1, "");
_Static_assert(sizeof(struct D2_packed) == 0, "");
_Static_assert(_Alignof(struct D2_packed) == 1, "");
_Static_assert(sizeof(struct D2_required_alignment) == 1, "");
_Static_assert(_Alignof(struct D2_required_alignment) == 1, "");
_Static_assert(sizeof(struct D2_size) == 2, "");
_Static_assert(_Alignof(struct D2_size) == 1, "");
#endif
_Static_assert(sizeof(E2) == 1, "");
_Static_assert(_Alignof(E2) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E2_alignment) == 2, "");
_Static_assert(_Alignof(struct E2_alignment) == 1, "");
_Static_assert(sizeof(struct E2_packed) == 1, "");
_Static_assert(_Alignof(struct E2_packed) == 1, "");
_Static_assert(sizeof(struct E2_required_alignment) == 2, "");
_Static_assert(_Alignof(struct E2_required_alignment) == 1, "");
_Static_assert(sizeof(struct E2_size) == 3, "");
_Static_assert(_Alignof(struct E2_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(F2) == 1, "");
_Static_assert(_Alignof(F2) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F2_alignment) == 2, "");
_Static_assert(_Alignof(struct F2_alignment) == 1, "");
_Static_assert(sizeof(struct F2_packed) == 1, "");
_Static_assert(_Alignof(struct F2_packed) == 1, "");
_Static_assert(sizeof(struct F2_required_alignment) == 2, "");
_Static_assert(_Alignof(struct F2_required_alignment) == 1, "");
_Static_assert(sizeof(struct F2_size) == 3, "");
_Static_assert(_Alignof(struct F2_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(G2) == 1, "");
_Static_assert(_Alignof(G2) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G2_alignment) == 2, "");
_Static_assert(_Alignof(struct G2_alignment) == 1, "");
_Static_assert(sizeof(struct G2_packed) == 1, "");
_Static_assert(_Alignof(struct G2_packed) == 1, "");
_Static_assert(sizeof(struct G2_required_alignment) == 2, "");
_Static_assert(_Alignof(struct G2_required_alignment) == 1, "");
_Static_assert(sizeof(struct G2_size) == 3, "");
_Static_assert(_Alignof(struct G2_size) == 1, "");
#endif
_Static_assert(sizeof(H2) == 16, "");
_Static_assert(_Alignof(H2) == 16, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H2_alignment) == 32, "");
_Static_assert(_Alignof(struct H2_alignment) == 16, "");
_Static_assert(sizeof(struct H2_packed) == 16, "");
_Static_assert(_Alignof(struct H2_packed) == 1, "");
_Static_assert(sizeof(struct H2_required_alignment) == 17, "");
_Static_assert(_Alignof(struct H2_required_alignment) == 1, "");
_Static_assert(sizeof(struct H2_size) == 18, "");
_Static_assert(_Alignof(struct H2_size) == 1, "");
#endif
// MAPPING|SIX|i386-i686-windows-gnu:Gcc|x86_64-x86_64-windows-gnu:Gcc|END
// repr targets I686PcWindowsGnu|Some("i386-i686-windows-gnu") X86_64PcWindowsGnu|Some("x86_64-x86_64-windows-gnu") 
#elif defined(SIX)
_Static_assert(sizeof(A) == 8, "");
_Static_assert(_Alignof(A) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 16, "");
_Static_assert(_Alignof(struct A_alignment) == 8, "");
_Static_assert(sizeof(struct A_packed) == 8, "");
_Static_assert(_Alignof(struct A_packed) == 1, "");
_Static_assert(sizeof(struct A_required_alignment) == 9, "");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "");
_Static_assert(sizeof(struct A_size) == 10, "");
_Static_assert(_Alignof(struct A_size) == 1, "");
#endif
_Static_assert(sizeof(B) == 8, "");
_Static_assert(_Alignof(B) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 16, "");
_Static_assert(_Alignof(struct B_alignment) == 8, "");
_Static_assert(sizeof(struct B_packed) == 8, "");
_Static_assert(_Alignof(struct B_packed) == 1, "");
_Static_assert(sizeof(struct B_required_alignment) == 9, "");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "");
_Static_assert(sizeof(struct B_size) == 10, "");
_Static_assert(_Alignof(struct B_size) == 1, "");
#endif
_Static_assert(sizeof(C) == 8, "");
_Static_assert(_Alignof(C) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 16, "");
_Static_assert(_Alignof(struct C_alignment) == 8, "");
_Static_assert(sizeof(struct C_packed) == 8, "");
_Static_assert(_Alignof(struct C_packed) == 1, "");
_Static_assert(sizeof(struct C_required_alignment) == 9, "");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "");
_Static_assert(sizeof(struct C_size) == 10, "");
_Static_assert(_Alignof(struct C_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(D) == 0, "");
_Static_assert(_Alignof(D) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 1, "");
_Static_assert(_Alignof(struct D_alignment) == 1, "");
_Static_assert(sizeof(struct D_packed) == 0, "");
_Static_assert(_Alignof(struct D_packed) == 1, "");
_Static_assert(sizeof(struct D_required_alignment) == 1, "");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "");
_Static_assert(sizeof(struct D_size) == 2, "");
_Static_assert(_Alignof(struct D_size) == 1, "");
#endif
_Static_assert(sizeof(E) == 1, "");
_Static_assert(_Alignof(E) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 2, "");
_Static_assert(_Alignof(struct E_alignment) == 1, "");
_Static_assert(sizeof(struct E_packed) == 1, "");
_Static_assert(_Alignof(struct E_packed) == 1, "");
_Static_assert(sizeof(struct E_required_alignment) == 2, "");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "");
_Static_assert(sizeof(struct E_size) == 3, "");
_Static_assert(_Alignof(struct E_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(F) == 1, "");
_Static_assert(_Alignof(F) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 2, "");
_Static_assert(_Alignof(struct F_alignment) == 1, "");
_Static_assert(sizeof(struct F_packed) == 1, "");
_Static_assert(_Alignof(struct F_packed) == 1, "");
_Static_assert(sizeof(struct F_required_alignment) == 2, "");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "");
_Static_assert(sizeof(struct F_size) == 3, "");
_Static_assert(_Alignof(struct F_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(G) == 4, "");
_Static_assert(_Alignof(G) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 5, "");
_Static_assert(_Alignof(struct G_alignment) == 1, "");
_Static_assert(sizeof(struct G_packed) == 4, "");
_Static_assert(_Alignof(struct G_packed) == 1, "");
_Static_assert(sizeof(struct G_required_alignment) == 5, "");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "");
_Static_assert(sizeof(struct G_size) == 6, "");
_Static_assert(_Alignof(struct G_size) == 1, "");
#endif
_Static_assert(sizeof(H) == 4, "");
_Static_assert(_Alignof(H) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 5, "");
_Static_assert(_Alignof(struct H_alignment) == 1, "");
_Static_assert(sizeof(struct H_packed) == 4, "");
_Static_assert(_Alignof(struct H_packed) == 1, "");
_Static_assert(sizeof(struct H_required_alignment) == 5, "");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "");
_Static_assert(sizeof(struct H_size) == 6, "");
_Static_assert(_Alignof(struct H_size) == 1, "");
#endif
_Static_assert(sizeof(A2) == 8, "");
_Static_assert(_Alignof(A2) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A2_alignment) == 16, "");
_Static_assert(_Alignof(struct A2_alignment) == 8, "");
_Static_assert(sizeof(struct A2_packed) == 8, "");
_Static_assert(_Alignof(struct A2_packed) == 1, "");
_Static_assert(sizeof(struct A2_required_alignment) == 9, "");
_Static_assert(_Alignof(struct A2_required_alignment) == 1, "");
_Static_assert(sizeof(struct A2_size) == 10, "");
_Static_assert(_Alignof(struct A2_size) == 1, "");
#endif
_Static_assert(sizeof(B2) == 8, "");
_Static_assert(_Alignof(B2) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B2_alignment) == 16, "");
_Static_assert(_Alignof(struct B2_alignment) == 8, "");
_Static_assert(sizeof(struct B2_packed) == 8, "");
_Static_assert(_Alignof(struct B2_packed) == 1, "");
_Static_assert(sizeof(struct B2_required_alignment) == 9, "");
_Static_assert(_Alignof(struct B2_required_alignment) == 1, "");
_Static_assert(sizeof(struct B2_size) == 10, "");
_Static_assert(_Alignof(struct B2_size) == 1, "");
#endif
_Static_assert(sizeof(C2) == 1, "");
_Static_assert(_Alignof(C2) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C2_alignment) == 2, "");
_Static_assert(_Alignof(struct C2_alignment) == 1, "");
_Static_assert(sizeof(struct C2_packed) == 1, "");
_Static_assert(_Alignof(struct C2_packed) == 1, "");
_Static_assert(sizeof(struct C2_required_alignment) == 2, "");
_Static_assert(_Alignof(struct C2_required_alignment) == 1, "");
_Static_assert(sizeof(struct C2_size) == 3, "");
_Static_assert(_Alignof(struct C2_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(D2) == 0, "");
_Static_assert(_Alignof(D2) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D2_alignment) == 1, "");
_Static_assert(_Alignof(struct D2_alignment) == 1, "");
_Static_assert(sizeof(struct D2_packed) == 0, "");
_Static_assert(_Alignof(struct D2_packed) == 1, "");
_Static_assert(sizeof(struct D2_required_alignment) == 1, "");
_Static_assert(_Alignof(struct D2_required_alignment) == 1, "");
_Static_assert(sizeof(struct D2_size) == 2, "");
_Static_assert(_Alignof(struct D2_size) == 1, "");
#endif
_Static_assert(sizeof(E2) == 1, "");
_Static_assert(_Alignof(E2) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E2_alignment) == 2, "");
_Static_assert(_Alignof(struct E2_alignment) == 1, "");
_Static_assert(sizeof(struct E2_packed) == 1, "");
_Static_assert(_Alignof(struct E2_packed) == 1, "");
_Static_assert(sizeof(struct E2_required_alignment) == 2, "");
_Static_assert(_Alignof(struct E2_required_alignment) == 1, "");
_Static_assert(sizeof(struct E2_size) == 3, "");
_Static_assert(_Alignof(struct E2_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(F2) == 1, "");
_Static_assert(_Alignof(F2) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F2_alignment) == 2, "");
_Static_assert(_Alignof(struct F2_alignment) == 1, "");
_Static_assert(sizeof(struct F2_packed) == 1, "");
_Static_assert(_Alignof(struct F2_packed) == 1, "");
_Static_assert(sizeof(struct F2_required_alignment) == 2, "");
_Static_assert(_Alignof(struct F2_required_alignment) == 1, "");
_Static_assert(sizeof(struct F2_size) == 3, "");
_Static_assert(_Alignof(struct F2_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(G2) == 1, "");
_Static_assert(_Alignof(G2) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G2_alignment) == 2, "");
_Static_assert(_Alignof(struct G2_alignment) == 1, "");
_Static_assert(sizeof(struct G2_packed) == 1, "");
_Static_assert(_Alignof(struct G2_packed) == 1, "");
_Static_assert(sizeof(struct G2_required_alignment) == 2, "");
_Static_assert(_Alignof(struct G2_required_alignment) == 1, "");
_Static_assert(sizeof(struct G2_size) == 3, "");
_Static_assert(_Alignof(struct G2_size) == 1, "");
#endif
_Static_assert(sizeof(H2) == 1, "");
_Static_assert(_Alignof(H2) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H2_alignment) == 2, "");
_Static_assert(_Alignof(struct H2_alignment) == 1, "");
_Static_assert(sizeof(struct H2_packed) == 1, "");
_Static_assert(_Alignof(struct H2_packed) == 1, "");
_Static_assert(sizeof(struct H2_required_alignment) == 2, "");
_Static_assert(_Alignof(struct H2_required_alignment) == 1, "");
_Static_assert(sizeof(struct H2_size) == 3, "");
_Static_assert(_Alignof(struct H2_size) == 1, "");
#endif
// MAPPING|SEVEN|msp430-msp430-other-eabi:Clang|END
// repr targets Msp430NoneElf|Some("msp430-msp430-other-eabi") 
#elif defined(SEVEN)
_Static_assert(sizeof(A) == 8, "");
_Static_assert(_Alignof(A) == 2, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 10, "");
_Static_assert(_Alignof(struct A_alignment) == 2, "");
_Static_assert(sizeof(struct A_packed) == 8, "");
_Static_assert(_Alignof(struct A_packed) == 1, "");
_Static_assert(sizeof(struct A_required_alignment) == 9, "");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "");
_Static_assert(sizeof(struct A_size) == 10, "");
_Static_assert(_Alignof(struct A_size) == 1, "");
#endif
_Static_assert(sizeof(B) == 2, "");
_Static_assert(_Alignof(B) == 2, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 4, "");
_Static_assert(_Alignof(struct B_alignment) == 2, "");
_Static_assert(sizeof(struct B_packed) == 2, "");
_Static_assert(_Alignof(struct B_packed) == 1, "");
_Static_assert(sizeof(struct B_required_alignment) == 3, "");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "");
_Static_assert(sizeof(struct B_size) == 4, "");
_Static_assert(_Alignof(struct B_size) == 1, "");
#endif
_Static_assert(sizeof(C) == 2, "");
_Static_assert(_Alignof(C) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 3, "");
_Static_assert(_Alignof(struct C_alignment) == 1, "");
_Static_assert(sizeof(struct C_packed) == 2, "");
_Static_assert(_Alignof(struct C_packed) == 1, "");
_Static_assert(sizeof(struct C_required_alignment) == 3, "");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "");
_Static_assert(sizeof(struct C_size) == 4, "");
_Static_assert(_Alignof(struct C_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(D) == 0, "");
_Static_assert(_Alignof(D) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 1, "");
_Static_assert(_Alignof(struct D_alignment) == 1, "");
_Static_assert(sizeof(struct D_packed) == 0, "");
_Static_assert(_Alignof(struct D_packed) == 1, "");
_Static_assert(sizeof(struct D_required_alignment) == 1, "");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "");
_Static_assert(sizeof(struct D_size) == 2, "");
_Static_assert(_Alignof(struct D_size) == 1, "");
#endif
_Static_assert(sizeof(E) == 2, "");
_Static_assert(_Alignof(E) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 3, "");
_Static_assert(_Alignof(struct E_alignment) == 1, "");
_Static_assert(sizeof(struct E_packed) == 2, "");
_Static_assert(_Alignof(struct E_packed) == 1, "");
_Static_assert(sizeof(struct E_required_alignment) == 3, "");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "");
_Static_assert(sizeof(struct E_size) == 4, "");
_Static_assert(_Alignof(struct E_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(F) == 2, "");
_Static_assert(_Alignof(F) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 3, "");
_Static_assert(_Alignof(struct F_alignment) == 1, "");
_Static_assert(sizeof(struct F_packed) == 2, "");
_Static_assert(_Alignof(struct F_packed) == 1, "");
_Static_assert(sizeof(struct F_required_alignment) == 3, "");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "");
_Static_assert(sizeof(struct F_size) == 4, "");
_Static_assert(_Alignof(struct F_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(G) == 1, "");
_Static_assert(_Alignof(G) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 2, "");
_Static_assert(_Alignof(struct G_alignment) == 1, "");
_Static_assert(sizeof(struct G_packed) == 1, "");
_Static_assert(_Alignof(struct G_packed) == 1, "");
_Static_assert(sizeof(struct G_required_alignment) == 2, "");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "");
_Static_assert(sizeof(struct G_size) == 3, "");
_Static_assert(_Alignof(struct G_size) == 1, "");
#endif
_Static_assert(sizeof(H) == 16, "");
_Static_assert(_Alignof(H) == 16, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 32, "");
_Static_assert(_Alignof(struct H_alignment) == 16, "");
_Static_assert(sizeof(struct H_packed) == 16, "");
_Static_assert(_Alignof(struct H_packed) == 1, "");
_Static_assert(sizeof(struct H_required_alignment) == 17, "");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "");
_Static_assert(sizeof(struct H_size) == 18, "");
_Static_assert(_Alignof(struct H_size) == 1, "");
#endif
_Static_assert(sizeof(A2) == 8, "");
_Static_assert(_Alignof(A2) == 2, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A2_alignment) == 10, "");
_Static_assert(_Alignof(struct A2_alignment) == 2, "");
_Static_assert(sizeof(struct A2_packed) == 8, "");
_Static_assert(_Alignof(struct A2_packed) == 1, "");
_Static_assert(sizeof(struct A2_required_alignment) == 9, "");
_Static_assert(_Alignof(struct A2_required_alignment) == 1, "");
_Static_assert(sizeof(struct A2_size) == 10, "");
_Static_assert(_Alignof(struct A2_size) == 1, "");
#endif
_Static_assert(sizeof(B2) == 2, "");
_Static_assert(_Alignof(B2) == 2, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B2_alignment) == 4, "");
_Static_assert(_Alignof(struct B2_alignment) == 2, "");
_Static_assert(sizeof(struct B2_packed) == 2, "");
_Static_assert(_Alignof(struct B2_packed) == 1, "");
_Static_assert(sizeof(struct B2_required_alignment) == 3, "");
_Static_assert(_Alignof(struct B2_required_alignment) == 1, "");
_Static_assert(sizeof(struct B2_size) == 4, "");
_Static_assert(_Alignof(struct B2_size) == 1, "");
#endif
_Static_assert(sizeof(C2) == 1, "");
_Static_assert(_Alignof(C2) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C2_alignment) == 2, "");
_Static_assert(_Alignof(struct C2_alignment) == 1, "");
_Static_assert(sizeof(struct C2_packed) == 1, "");
_Static_assert(_Alignof(struct C2_packed) == 1, "");
_Static_assert(sizeof(struct C2_required_alignment) == 2, "");
_Static_assert(_Alignof(struct C2_required_alignment) == 1, "");
_Static_assert(sizeof(struct C2_size) == 3, "");
_Static_assert(_Alignof(struct C2_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(D2) == 0, "");
_Static_assert(_Alignof(D2) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D2_alignment) == 1, "");
_Static_assert(_Alignof(struct D2_alignment) == 1, "");
_Static_assert(sizeof(struct D2_packed) == 0, "");
_Static_assert(_Alignof(struct D2_packed) == 1, "");
_Static_assert(sizeof(struct D2_required_alignment) == 1, "");
_Static_assert(_Alignof(struct D2_required_alignment) == 1, "");
_Static_assert(sizeof(struct D2_size) == 2, "");
_Static_assert(_Alignof(struct D2_size) == 1, "");
#endif
_Static_assert(sizeof(E2) == 1, "");
_Static_assert(_Alignof(E2) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E2_alignment) == 2, "");
_Static_assert(_Alignof(struct E2_alignment) == 1, "");
_Static_assert(sizeof(struct E2_packed) == 1, "");
_Static_assert(_Alignof(struct E2_packed) == 1, "");
_Static_assert(sizeof(struct E2_required_alignment) == 2, "");
_Static_assert(_Alignof(struct E2_required_alignment) == 1, "");
_Static_assert(sizeof(struct E2_size) == 3, "");
_Static_assert(_Alignof(struct E2_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(F2) == 1, "");
_Static_assert(_Alignof(F2) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F2_alignment) == 2, "");
_Static_assert(_Alignof(struct F2_alignment) == 1, "");
_Static_assert(sizeof(struct F2_packed) == 1, "");
_Static_assert(_Alignof(struct F2_packed) == 1, "");
_Static_assert(sizeof(struct F2_required_alignment) == 2, "");
_Static_assert(_Alignof(struct F2_required_alignment) == 1, "");
_Static_assert(sizeof(struct F2_size) == 3, "");
_Static_assert(_Alignof(struct F2_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
#endif
_Static_assert(sizeof(G2) == 1, "");
_Static_assert(_Alignof(G2) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G2_alignment) == 2, "");
_Static_assert(_Alignof(struct G2_alignment) == 1, "");
_Static_assert(sizeof(struct G2_packed) == 1, "");
_Static_assert(_Alignof(struct G2_packed) == 1, "");
_Static_assert(sizeof(struct G2_required_alignment) == 2, "");
_Static_assert(_Alignof(struct G2_required_alignment) == 1, "");
_Static_assert(sizeof(struct G2_size) == 3, "");
_Static_assert(_Alignof(struct G2_size) == 1, "");
#endif
_Static_assert(sizeof(H2) == 16, "");
_Static_assert(_Alignof(H2) == 16, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H2_alignment) == 32, "");
_Static_assert(_Alignof(struct H2_alignment) == 16, "");
_Static_assert(sizeof(struct H2_packed) == 16, "");
_Static_assert(_Alignof(struct H2_packed) == 1, "");
_Static_assert(sizeof(struct H2_required_alignment) == 17, "");
_Static_assert(_Alignof(struct H2_required_alignment) == 1, "");
_Static_assert(sizeof(struct H2_size) == 18, "");
_Static_assert(_Alignof(struct H2_size) == 1, "");
#endif
#endif
