// SPDX-License-Identifier: GPL-3.0-or-later

// This test file is auto-generated. do not edit.
// This file is a derivative work from the test files found
// in this repo : https://github.com/mahkoh/repr-c
// and is under the same licence as the original work.

typedef struct {
    long long a;
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
    long long a:1;
} B;
B var5;
struct B_extra_alignment {
    char a;
    B b;
};
struct B_extra_alignment var6;
#pragma pack(1)
struct B_extra_packed {
    B a;
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

typedef struct {
    char a:1;
    long long:0;
} C;
C var9;
struct C_extra_alignment {
    char a;
    C b;
};
struct C_extra_alignment var10;
#pragma pack(1)
struct C_extra_packed {
    C a;
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

typedef struct {
    long long:0;
} D;
D var13;
struct D_extra_alignment {
    char a;
    D b;
};
struct D_extra_alignment var14;
#pragma pack(1)
struct D_extra_packed {
    D a;
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

typedef struct {
    char c;
    long long:0;
} E;
E var17;
struct E_extra_alignment {
    char a;
    E b;
};
struct E_extra_alignment var18;
#pragma pack(1)
struct E_extra_packed {
    E a;
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

typedef struct {
    char c;
    int:0;
    long long:0;
} F;
F var21;
struct F_extra_alignment {
    char a;
    F b;
};
struct F_extra_alignment var22;
#pragma pack(1)
struct F_extra_packed {
    F a;
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

typedef struct {
    int a:1 __attribute__((packed));
} G;
G var25;
struct G_extra_alignment {
    char a;
    G b;
};
struct G_extra_alignment var26;
#pragma pack(1)
struct G_extra_packed {
    G a;
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

typedef struct {
    int a:1 __attribute__((aligned(16))) __attribute__((packed));
} H;
H var29;
struct H_extra_alignment {
    char a;
    H b;
};
struct H_extra_alignment var30;
#pragma pack(1)
struct H_extra_packed {
    H a;
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

typedef union {
    long long a;
} A2;
A2 var33;
struct A2_extra_alignment {
    char a;
    A2 b;
};
struct A2_extra_alignment var34;
#pragma pack(1)
struct A2_extra_packed {
    A2 a;
};
#pragma pack()
struct A2_extra_required_alignment {
    char a;
    struct A2_extra_packed b;
};
struct A2_extra_required_alignment var35;
struct A2_extra_size {
    char a[sizeof(A2)+1];
    char b;
};
struct A2_extra_size var36;

typedef union {
    long long a:1;
} B2;
B2 var37;
struct B2_extra_alignment {
    char a;
    B2 b;
};
struct B2_extra_alignment var38;
#pragma pack(1)
struct B2_extra_packed {
    B2 a;
};
#pragma pack()
struct B2_extra_required_alignment {
    char a;
    struct B2_extra_packed b;
};
struct B2_extra_required_alignment var39;
struct B2_extra_size {
    char a[sizeof(B2)+1];
    char b;
};
struct B2_extra_size var40;

typedef union {
    char a:1;
    long long:0;
} C2;
C2 var41;
struct C2_extra_alignment {
    char a;
    C2 b;
};
struct C2_extra_alignment var42;
#pragma pack(1)
struct C2_extra_packed {
    C2 a;
};
#pragma pack()
struct C2_extra_required_alignment {
    char a;
    struct C2_extra_packed b;
};
struct C2_extra_required_alignment var43;
struct C2_extra_size {
    char a[sizeof(C2)+1];
    char b;
};
struct C2_extra_size var44;

typedef union {
    long long:0;
} D2;
D2 var45;
struct D2_extra_alignment {
    char a;
    D2 b;
};
struct D2_extra_alignment var46;
#pragma pack(1)
struct D2_extra_packed {
    D2 a;
};
#pragma pack()
struct D2_extra_required_alignment {
    char a;
    struct D2_extra_packed b;
};
struct D2_extra_required_alignment var47;
struct D2_extra_size {
    char a[sizeof(D2)+1];
    char b;
};
struct D2_extra_size var48;

typedef union {
    char c;
    long long:0;
} E2;
E2 var49;
struct E2_extra_alignment {
    char a;
    E2 b;
};
struct E2_extra_alignment var50;
#pragma pack(1)
struct E2_extra_packed {
    E2 a;
};
#pragma pack()
struct E2_extra_required_alignment {
    char a;
    struct E2_extra_packed b;
};
struct E2_extra_required_alignment var51;
struct E2_extra_size {
    char a[sizeof(E2)+1];
    char b;
};
struct E2_extra_size var52;

typedef union {
    char c;
    int:0;
    long long:0;
} F2;
F2 var53;
struct F2_extra_alignment {
    char a;
    F2 b;
};
struct F2_extra_alignment var54;
#pragma pack(1)
struct F2_extra_packed {
    F2 a;
};
#pragma pack()
struct F2_extra_required_alignment {
    char a;
    struct F2_extra_packed b;
};
struct F2_extra_required_alignment var55;
struct F2_extra_size {
    char a[sizeof(F2)+1];
    char b;
};
struct F2_extra_size var56;

typedef union {
    int a:1 __attribute__((packed));
} G2;
G2 var57;
struct G2_extra_alignment {
    char a;
    G2 b;
};
struct G2_extra_alignment var58;
#pragma pack(1)
struct G2_extra_packed {
    G2 a;
};
#pragma pack()
struct G2_extra_required_alignment {
    char a;
    struct G2_extra_packed b;
};
struct G2_extra_required_alignment var59;
struct G2_extra_size {
    char a[sizeof(G2)+1];
    char b;
};
struct G2_extra_size var60;

typedef union {
    int a:1 __attribute__((aligned(16))) __attribute__((packed));
} H2;
H2 var61;
struct H2_extra_alignment {
    char a;
    H2 b;
};
struct H2_extra_alignment var62;
#pragma pack(1)
struct H2_extra_packed {
    H2 a;
};
#pragma pack()
struct H2_extra_required_alignment {
    char a;
    struct H2_extra_packed b;
};
struct H2_extra_required_alignment var63;
struct H2_extra_size {
    char a[sizeof(H2)+1];
    char b;
};
struct H2_extra_size var64;


// MAPPING|ONE|aarch64-generic-macos-none:Clang|aarch64-generic-ios-none:Clang|aarch64-generic-ios-macabi:Clang|aarch64-generic-tvos-none:Clang|hexagon-generic-linux-musl:Clang|mips64el-mips64-linux-gnuabi64:Gcc|mips64el-mips64-linux-musl:Gcc|mips64-mips64-linux-gnuabi64:Gcc|mips64-mips64-linux-musl:Gcc|mipsel-mips32-linux-gnu:Gcc|mipsel-mips32-linux-musl:Gcc|mipsel-mips32-other-none:Clang|mips-mips32-linux-gnu:Gcc|mips-mips32r6-linux-gnu:Gcc|mips-mips32-linux-gnuabi64:Gcc|mips-mips64r6-linux-gnuabi64:Gcc|mips-mips32-linux-gnu:Gcc|mips-mips32-linux-musl:Gcc|powerpc64le-ppc64le-linux-gnu:Gcc|powerpc64le-ppc64le-linux-musl:Gcc|powerpc64-ppc64-freebsd-gnu:Clang|powerpc64-ppc64-linux-gnu:Gcc|powerpc64-ppc64-linux-musl:Gcc|powerpc-ppc-linux-gnu:Gcc|powerpc-ppc-linux-musl:Gcc|powerpc-ppc-netbsd-gnu:Clang|riscv32-baseline_rv32-other-eabi:Clang|riscv32-baseline_rv32-linux-gnu:Gcc|riscv64-baseline_rv64-other-eabi:Clang|riscv64-baseline_rv64-linux-gnu:Gcc|s390x-generic-linux-gnu:Gcc|sparc64-v9-linux-gnu:Gcc|sparc64-v9-netbsd-gnu:Clang|sparc64-v9-openbsd-gnu:Clang|sparc-v8-linux-gnu:Gcc|sparc64-v9-solaris-eabi:Clang|wasm32-generic-emscripten-musl:Clang|wasm32-generic-other-musl:Clang|wasm32-generic-wasi-musl:Clang|x86_64-x86_64-ios-macabi:Clang|x86_64-x86_64-ios-none:Clang|x86_64-x86_64-macos-none:Clang|x86_64-x86_64-tvos-none:Clang|x86_64-x86_64-other-eabi:Clang|x86_64-x86_64-fuchsia-gnu:Clang|x86_64-x86_64-linux-android:Clang|x86_64-x86_64-solaris-eabi:Clang|x86_64-x86_64-dragonfly-eabi:Clang|x86_64-x86_64-freebsd-gnu:Clang|x86_64-x86_64-haiku-gnu:Clang|x86_64-x86_64-hermit-eabi:Clang|x86_64-x86_64-linux-gnux32:Gcc|x86_64-x86_64-linux-gnu:Gcc|x86_64-x86_64-linux-musl:Gcc|x86_64-x86_64-netbsd-gnu:Clang|x86_64-x86_64-openbsd-gnu:Clang|END
// repr targets Aarch64AppleMacosx|Some("aarch64-generic-macos-none") Arm64AppleIos|Some("aarch64-generic-ios-none") Arm64AppleIosMacabi|Some("aarch64-generic-ios-macabi") Arm64AppleTvos|Some("aarch64-generic-tvos-none") HexagonUnknownLinuxMusl|Some("hexagon-generic-linux-musl") Mips64elUnknownLinuxGnuabi64|Some("mips64el-mips64-linux-gnuabi64") Mips64elUnknownLinuxMusl|Some("mips64el-mips64-linux-musl") Mips64UnknownLinuxGnuabi64|Some("mips64-mips64-linux-gnuabi64") Mips64UnknownLinuxMusl|Some("mips64-mips64-linux-musl") MipselSonyPsp|None MipselUnknownLinuxGnu|Some("mipsel-mips32-linux-gnu") MipselUnknownLinuxMusl|Some("mipsel-mips32-linux-musl") MipselUnknownLinuxUclibc|None MipselUnknownNone|Some("mipsel-mips32-other-none") Mipsisa32r6elUnknownLinuxGnu|Some("mips-mips32-linux-gnu") Mipsisa32r6UnknownLinuxGnu|Some("mips-mips32r6-linux-gnu") Mipsisa64r6elUnknownLinuxGnuabi64|Some("mips-mips32-linux-gnuabi64") Mipsisa64r6UnknownLinuxGnuabi64|Some("mips-mips64r6-linux-gnuabi64") MipsUnknownLinuxGnu|Some("mips-mips32-linux-gnu") MipsUnknownLinuxMusl|Some("mips-mips32-linux-musl") MipsUnknownLinuxUclibc|None Powerpc64leUnknownLinuxGnu|Some("powerpc64le-ppc64le-linux-gnu") Powerpc64leUnknownLinuxMusl|Some("powerpc64le-ppc64le-linux-musl") Powerpc64UnknownFreebsd|Some("powerpc64-ppc64-freebsd-gnu") Powerpc64UnknownLinuxGnu|Some("powerpc64-ppc64-linux-gnu") Powerpc64UnknownLinuxMusl|Some("powerpc64-ppc64-linux-musl") PowerpcUnknownLinuxGnu|Some("powerpc-ppc-linux-gnu") PowerpcUnknownLinuxGnuspe|None PowerpcUnknownLinuxMusl|Some("powerpc-ppc-linux-musl") PowerpcUnknownNetbsd|Some("powerpc-ppc-netbsd-gnu") Riscv32|Some("riscv32-baseline_rv32-other-eabi") Riscv32UnknownLinuxGnu|Some("riscv32-baseline_rv32-linux-gnu") Riscv64|Some("riscv64-baseline_rv64-other-eabi") Riscv64UnknownLinuxGnu|Some("riscv64-baseline_rv64-linux-gnu") S390xUnknownLinuxGnu|Some("s390x-generic-linux-gnu") Sparc64UnknownLinuxGnu|Some("sparc64-v9-linux-gnu") Sparc64UnknownNetbsd|Some("sparc64-v9-netbsd-gnu") Sparc64UnknownOpenbsd|Some("sparc64-v9-openbsd-gnu") SparcUnknownLinuxGnu|Some("sparc-v8-linux-gnu") Sparcv9SunSolaris|Some("sparc64-v9-solaris-eabi") Wasm32UnknownEmscripten|Some("wasm32-generic-emscripten-musl") Wasm32UnknownUnknown|Some("wasm32-generic-other-musl") Wasm32Wasi|Some("wasm32-generic-wasi-musl") X86_64AppleIosMacabi|Some("x86_64-x86_64-ios-macabi") X86_64AppleIos|Some("x86_64-x86_64-ios-none") X86_64AppleMacosx|Some("x86_64-x86_64-macos-none") X86_64AppleTvos|Some("x86_64-x86_64-tvos-none") X86_64Elf|Some("x86_64-x86_64-other-eabi") X86_64Fuchsia|Some("x86_64-x86_64-fuchsia-gnu") X86_64LinuxAndroid|Some("x86_64-x86_64-linux-android") X86_64PcSolaris|Some("x86_64-x86_64-solaris-eabi") X86_64RumprunNetbsd|None X86_64UnknownDragonfly|Some("x86_64-x86_64-dragonfly-eabi") X86_64UnknownFreebsd|Some("x86_64-x86_64-freebsd-gnu") X86_64UnknownHaiku|Some("x86_64-x86_64-haiku-gnu") X86_64UnknownHermit|Some("x86_64-x86_64-hermit-eabi") X86_64UnknownL4reUclibc|None X86_64UnknownLinuxGnux32|Some("x86_64-x86_64-linux-gnux32") X86_64UnknownLinuxGnu|Some("x86_64-x86_64-linux-gnu") X86_64UnknownLinuxMusl|Some("x86_64-x86_64-linux-musl") X86_64UnknownNetbsd|Some("x86_64-x86_64-netbsd-gnu") X86_64UnknownOpenbsd|Some("x86_64-x86_64-openbsd-gnu") X86_64UnknownRedox|None 
#ifdef ONE
_Static_assert(sizeof(A) == 8, "");
_Static_assert(_Alignof(A) == 8, "");
_Static_assert(sizeof(struct A_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct A_extra_alignment) == 8, "");
_Static_assert(sizeof(struct A_extra_packed) == 8, "");
_Static_assert(_Alignof(struct A_extra_packed) == 1, "");
_Static_assert(sizeof(struct A_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct A_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A_extra_size) == 10, "");
_Static_assert(_Alignof(struct A_extra_size) == 1, "");
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
_Static_assert(sizeof(C) == 8, "");
_Static_assert(_Alignof(C) == 1, "");
_Static_assert(sizeof(struct C_extra_alignment) == 9, "");
_Static_assert(_Alignof(struct C_extra_alignment) == 1, "");
_Static_assert(sizeof(struct C_extra_packed) == 8, "");
_Static_assert(_Alignof(struct C_extra_packed) == 1, "");
_Static_assert(sizeof(struct C_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct C_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct C_extra_size) == 10, "");
_Static_assert(_Alignof(struct C_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
#endif
_Static_assert(sizeof(D) == 0, "");
_Static_assert(_Alignof(D) == 1, "");
_Static_assert(sizeof(struct D_extra_alignment) == 1, "");
_Static_assert(_Alignof(struct D_extra_alignment) == 1, "");
_Static_assert(sizeof(struct D_extra_packed) == 0, "");
_Static_assert(_Alignof(struct D_extra_packed) == 1, "");
_Static_assert(sizeof(struct D_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct D_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct D_extra_size) == 2, "");
_Static_assert(_Alignof(struct D_extra_size) == 1, "");
_Static_assert(sizeof(E) == 8, "");
_Static_assert(_Alignof(E) == 1, "");
_Static_assert(sizeof(struct E_extra_alignment) == 9, "");
_Static_assert(_Alignof(struct E_extra_alignment) == 1, "");
_Static_assert(sizeof(struct E_extra_packed) == 8, "");
_Static_assert(_Alignof(struct E_extra_packed) == 1, "");
_Static_assert(sizeof(struct E_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct E_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct E_extra_size) == 10, "");
_Static_assert(_Alignof(struct E_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
#endif
_Static_assert(sizeof(F) == 8, "");
_Static_assert(_Alignof(F) == 1, "");
_Static_assert(sizeof(struct F_extra_alignment) == 9, "");
_Static_assert(_Alignof(struct F_extra_alignment) == 1, "");
_Static_assert(sizeof(struct F_extra_packed) == 8, "");
_Static_assert(_Alignof(struct F_extra_packed) == 1, "");
_Static_assert(sizeof(struct F_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct F_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct F_extra_size) == 10, "");
_Static_assert(_Alignof(struct F_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
#endif
_Static_assert(sizeof(G) == 1, "");
_Static_assert(_Alignof(G) == 1, "");
_Static_assert(sizeof(struct G_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct G_extra_alignment) == 1, "");
_Static_assert(sizeof(struct G_extra_packed) == 1, "");
_Static_assert(_Alignof(struct G_extra_packed) == 1, "");
_Static_assert(sizeof(struct G_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct G_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct G_extra_size) == 3, "");
_Static_assert(_Alignof(struct G_extra_size) == 1, "");
_Static_assert(sizeof(H) == 16, "");
_Static_assert(_Alignof(H) == 16, "");
_Static_assert(sizeof(struct H_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct H_extra_alignment) == 16, "");
_Static_assert(sizeof(struct H_extra_packed) == 16, "");
_Static_assert(_Alignof(struct H_extra_packed) == 1, "");
_Static_assert(sizeof(struct H_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct H_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct H_extra_size) == 18, "");
_Static_assert(_Alignof(struct H_extra_size) == 1, "");
_Static_assert(sizeof(A2) == 8, "");
_Static_assert(_Alignof(A2) == 8, "");
_Static_assert(sizeof(struct A2_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct A2_extra_alignment) == 8, "");
_Static_assert(sizeof(struct A2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct A2_extra_packed) == 1, "");
_Static_assert(sizeof(struct A2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct A2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A2_extra_size) == 10, "");
_Static_assert(_Alignof(struct A2_extra_size) == 1, "");
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
#endif
_Static_assert(sizeof(D2) == 0, "");
_Static_assert(_Alignof(D2) == 1, "");
_Static_assert(sizeof(struct D2_extra_alignment) == 1, "");
_Static_assert(_Alignof(struct D2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct D2_extra_packed) == 0, "");
_Static_assert(_Alignof(struct D2_extra_packed) == 1, "");
_Static_assert(sizeof(struct D2_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct D2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct D2_extra_size) == 2, "");
_Static_assert(_Alignof(struct D2_extra_size) == 1, "");
_Static_assert(sizeof(E2) == 1, "");
_Static_assert(_Alignof(E2) == 1, "");
_Static_assert(sizeof(struct E2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct E2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct E2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct E2_extra_packed) == 1, "");
_Static_assert(sizeof(struct E2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct E2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct E2_extra_size) == 3, "");
_Static_assert(_Alignof(struct E2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
#endif
_Static_assert(sizeof(F2) == 1, "");
_Static_assert(_Alignof(F2) == 1, "");
_Static_assert(sizeof(struct F2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct F2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct F2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct F2_extra_packed) == 1, "");
_Static_assert(sizeof(struct F2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct F2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct F2_extra_size) == 3, "");
_Static_assert(_Alignof(struct F2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
#endif
_Static_assert(sizeof(G2) == 1, "");
_Static_assert(_Alignof(G2) == 1, "");
_Static_assert(sizeof(struct G2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct G2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct G2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct G2_extra_packed) == 1, "");
_Static_assert(sizeof(struct G2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct G2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct G2_extra_size) == 3, "");
_Static_assert(_Alignof(struct G2_extra_size) == 1, "");
_Static_assert(sizeof(H2) == 16, "");
_Static_assert(_Alignof(H2) == 16, "");
_Static_assert(sizeof(struct H2_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct H2_extra_alignment) == 16, "");
_Static_assert(sizeof(struct H2_extra_packed) == 16, "");
_Static_assert(_Alignof(struct H2_extra_packed) == 1, "");
_Static_assert(sizeof(struct H2_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct H2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct H2_extra_size) == 18, "");
_Static_assert(_Alignof(struct H2_extra_size) == 1, "");
// MAPPING|TWO|aarch64-generic-fuchsia-gnu:Clang|aarch64-generic-linux-android:Clang|aarch64-generic-freebsd-gnu:Clang|aarch64-generic-hermit-eabi:Clang|aarch64-generic-linux-gnu:Gcc|aarch64-generic-linux-musl:Gcc|aarch64-generic-netbsd-gnu:Clang|aarch64-generic-other-none:Clang|aarch64-generic-openbsd-gnu:Clang|arm-baseline-other-eabi:Clang|arm-baseline-other-eabihf:Clang|arm-baseline-linux-gnueabi:Gcc|arm-baseline-linux-gnueabihf:Gcc|arm-arm710t-linux-gnueabi:Gcc|arm-arm1020e-linux-gnueabi:Gcc|arm-arm1136j_s-freebsd-gnueabihf:Clang|arm-arm1136j_s-netbsd-eabihf:Clang|arm-baseline-other-eabi:Clang|arm-baseline-other-eabihf:Clang|arm-cortex_r4-linux-android:Clang|arm-cortex_r4-other-eabi:Clang|arm-cortex_r4-other-eabihf:Clang|arm-cortex_r4-freebsd-gnueabihf:Clang|arm-cortex_r4-linux-gnueabi:Gcc|arm-cortex_r4-linux-gnueabihf:Gcc|arm-cortex_r4-netbsd-eabihf:Clang|thumb-arm710t-other-eabi:Clang|thumb-cortex_m0-other-eabi:Clang|thumb-cortex_m4-other-eabihf:Clang|thumb-cortex_m4-other-eabi:Clang|thumb-cortex_m3-other-eabi:Clang|thumb-baseline-other-eabi:Clang|thumb-cortex_m33-other-eabihf:Clang|thumb-cortex_m33-other-eabi:Clang|END
// repr targets Aarch64Fuchsia|Some("aarch64-generic-fuchsia-gnu") Aarch64LinuxAndroid|Some("aarch64-generic-linux-android") Aarch64UnknownFreebsd|Some("aarch64-generic-freebsd-gnu") Aarch64UnknownHermit|Some("aarch64-generic-hermit-eabi") Aarch64UnknownLinuxGnu|Some("aarch64-generic-linux-gnu") Aarch64UnknownLinuxMusl|Some("aarch64-generic-linux-musl") Aarch64UnknownNetbsd|Some("aarch64-generic-netbsd-gnu") Aarch64UnknownNone|Some("aarch64-generic-other-none") Aarch64UnknownOpenbsd|Some("aarch64-generic-openbsd-gnu") Aarch64UnknownRedox|None Armebv7rUnknownNoneEabi|Some("arm-baseline-other-eabi") Armebv7rUnknownNoneEabihf|Some("arm-baseline-other-eabihf") ArmLinuxAndroideabi|None ArmUnknownLinuxGnueabi|Some("arm-baseline-linux-gnueabi") ArmUnknownLinuxGnueabihf|Some("arm-baseline-linux-gnueabihf") Armv4tUnknownLinuxGnueabi|Some("arm-arm710t-linux-gnueabi") Armv5teUnknownLinuxGnueabi|Some("arm-arm1020e-linux-gnueabi") Armv5teUnknownLinuxUclibcgnueabi|None Armv6UnknownFreebsdGnueabihf|Some("arm-arm1136j_s-freebsd-gnueabihf") Armv6UnknownNetbsdelfEabihf|Some("arm-arm1136j_s-netbsd-eabihf") Armv7aNoneEabi|Some("arm-baseline-other-eabi") Armv7aNoneEabihf|Some("arm-baseline-other-eabihf") Armv7NoneLinuxAndroid|Some("arm-cortex_r4-linux-android") Armv7rUnknownNoneEabi|Some("arm-cortex_r4-other-eabi") Armv7rUnknownNoneEabihf|Some("arm-cortex_r4-other-eabihf") Armv7UnknownFreebsdGnueabihf|Some("arm-cortex_r4-freebsd-gnueabihf") Armv7UnknownLinuxGnueabi|Some("arm-cortex_r4-linux-gnueabi") Armv7UnknownLinuxGnueabihf|Some("arm-cortex_r4-linux-gnueabihf") Armv7UnknownNetbsdelfEabihf|Some("arm-cortex_r4-netbsd-eabihf") Thumbv4tNoneEabi|Some("thumb-arm710t-other-eabi") Thumbv6mNoneEabi|Some("thumb-cortex_m0-other-eabi") Thumbv7emNoneEabihf|Some("thumb-cortex_m4-other-eabihf") Thumbv7emNoneEabi|Some("thumb-cortex_m4-other-eabi") Thumbv7mNoneEabi|Some("thumb-cortex_m3-other-eabi") Thumbv8mBaseNoneEabi|Some("thumb-baseline-other-eabi") Thumbv8mMainNoneEabihf|Some("thumb-cortex_m33-other-eabihf") Thumbv8mMainNoneEabi|Some("thumb-cortex_m33-other-eabi") 
#elif defined(TWO)
_Static_assert(sizeof(A) == 8, "");
_Static_assert(_Alignof(A) == 8, "");
_Static_assert(sizeof(struct A_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct A_extra_alignment) == 8, "");
_Static_assert(sizeof(struct A_extra_packed) == 8, "");
_Static_assert(_Alignof(struct A_extra_packed) == 1, "");
_Static_assert(sizeof(struct A_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct A_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A_extra_size) == 10, "");
_Static_assert(_Alignof(struct A_extra_size) == 1, "");
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
#endif
_Static_assert(sizeof(D) == 0, "");
_Static_assert(_Alignof(D) == 8, "");
_Static_assert(sizeof(struct D_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct D_extra_alignment) == 8, "");
_Static_assert(sizeof(struct D_extra_packed) == 0, "");
_Static_assert(_Alignof(struct D_extra_packed) == 1, "");
_Static_assert(sizeof(struct D_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct D_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct D_extra_size) == 2, "");
_Static_assert(_Alignof(struct D_extra_size) == 1, "");
_Static_assert(sizeof(E) == 8, "");
_Static_assert(_Alignof(E) == 8, "");
_Static_assert(sizeof(struct E_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct E_extra_alignment) == 8, "");
_Static_assert(sizeof(struct E_extra_packed) == 8, "");
_Static_assert(_Alignof(struct E_extra_packed) == 1, "");
_Static_assert(sizeof(struct E_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct E_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct E_extra_size) == 10, "");
_Static_assert(_Alignof(struct E_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
#endif
_Static_assert(sizeof(F) == 8, "");
_Static_assert(_Alignof(F) == 8, "");
_Static_assert(sizeof(struct F_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct F_extra_alignment) == 8, "");
_Static_assert(sizeof(struct F_extra_packed) == 8, "");
_Static_assert(_Alignof(struct F_extra_packed) == 1, "");
_Static_assert(sizeof(struct F_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct F_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct F_extra_size) == 10, "");
_Static_assert(_Alignof(struct F_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
#endif
_Static_assert(sizeof(G) == 1, "");
_Static_assert(_Alignof(G) == 1, "");
_Static_assert(sizeof(struct G_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct G_extra_alignment) == 1, "");
_Static_assert(sizeof(struct G_extra_packed) == 1, "");
_Static_assert(_Alignof(struct G_extra_packed) == 1, "");
_Static_assert(sizeof(struct G_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct G_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct G_extra_size) == 3, "");
_Static_assert(_Alignof(struct G_extra_size) == 1, "");
_Static_assert(sizeof(H) == 16, "");
_Static_assert(_Alignof(H) == 16, "");
_Static_assert(sizeof(struct H_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct H_extra_alignment) == 16, "");
_Static_assert(sizeof(struct H_extra_packed) == 16, "");
_Static_assert(_Alignof(struct H_extra_packed) == 1, "");
_Static_assert(sizeof(struct H_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct H_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct H_extra_size) == 18, "");
_Static_assert(_Alignof(struct H_extra_size) == 1, "");
_Static_assert(sizeof(A2) == 8, "");
_Static_assert(_Alignof(A2) == 8, "");
_Static_assert(sizeof(struct A2_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct A2_extra_alignment) == 8, "");
_Static_assert(sizeof(struct A2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct A2_extra_packed) == 1, "");
_Static_assert(sizeof(struct A2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct A2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A2_extra_size) == 10, "");
_Static_assert(_Alignof(struct A2_extra_size) == 1, "");
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
#endif
_Static_assert(sizeof(D2) == 0, "");
_Static_assert(_Alignof(D2) == 8, "");
_Static_assert(sizeof(struct D2_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct D2_extra_alignment) == 8, "");
_Static_assert(sizeof(struct D2_extra_packed) == 0, "");
_Static_assert(_Alignof(struct D2_extra_packed) == 1, "");
_Static_assert(sizeof(struct D2_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct D2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct D2_extra_size) == 2, "");
_Static_assert(_Alignof(struct D2_extra_size) == 1, "");
_Static_assert(sizeof(E2) == 8, "");
_Static_assert(_Alignof(E2) == 8, "");
_Static_assert(sizeof(struct E2_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct E2_extra_alignment) == 8, "");
_Static_assert(sizeof(struct E2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct E2_extra_packed) == 1, "");
_Static_assert(sizeof(struct E2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct E2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct E2_extra_size) == 10, "");
_Static_assert(_Alignof(struct E2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
#endif
_Static_assert(sizeof(F2) == 8, "");
_Static_assert(_Alignof(F2) == 8, "");
_Static_assert(sizeof(struct F2_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct F2_extra_alignment) == 8, "");
_Static_assert(sizeof(struct F2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct F2_extra_packed) == 1, "");
_Static_assert(sizeof(struct F2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct F2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct F2_extra_size) == 10, "");
_Static_assert(_Alignof(struct F2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
#endif
_Static_assert(sizeof(G2) == 1, "");
_Static_assert(_Alignof(G2) == 1, "");
_Static_assert(sizeof(struct G2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct G2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct G2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct G2_extra_packed) == 1, "");
_Static_assert(sizeof(struct G2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct G2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct G2_extra_size) == 3, "");
_Static_assert(_Alignof(struct G2_extra_size) == 1, "");
_Static_assert(sizeof(H2) == 16, "");
_Static_assert(_Alignof(H2) == 16, "");
_Static_assert(sizeof(struct H2_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct H2_extra_alignment) == 16, "");
_Static_assert(sizeof(struct H2_extra_packed) == 16, "");
_Static_assert(_Alignof(struct H2_extra_packed) == 1, "");
_Static_assert(sizeof(struct H2_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct H2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct H2_extra_size) == 18, "");
_Static_assert(_Alignof(struct H2_extra_size) == 1, "");
// MAPPING|THREE|arm-cortex_r4-ios-none:Clang|arm-baseline-ios-none:Clang|END
// repr targets Armv7AppleIos|Some("arm-cortex_r4-ios-none") Armv7sAppleIos|Some("arm-baseline-ios-none") 
#elif defined(THREE)
_Static_assert(sizeof(A) == 8, "");
_Static_assert(_Alignof(A) == 4, "");
_Static_assert(sizeof(struct A_extra_alignment) == 12, "");
_Static_assert(_Alignof(struct A_extra_alignment) == 4, "");
_Static_assert(sizeof(struct A_extra_packed) == 8, "");
_Static_assert(_Alignof(struct A_extra_packed) == 1, "");
_Static_assert(sizeof(struct A_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct A_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A_extra_size) == 10, "");
_Static_assert(_Alignof(struct A_extra_size) == 1, "");
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
#endif
_Static_assert(sizeof(D) == 0, "");
_Static_assert(_Alignof(D) == 4, "");
_Static_assert(sizeof(struct D_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct D_extra_alignment) == 4, "");
_Static_assert(sizeof(struct D_extra_packed) == 0, "");
_Static_assert(_Alignof(struct D_extra_packed) == 1, "");
_Static_assert(sizeof(struct D_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct D_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct D_extra_size) == 2, "");
_Static_assert(_Alignof(struct D_extra_size) == 1, "");
_Static_assert(sizeof(E) == 4, "");
_Static_assert(_Alignof(E) == 4, "");
_Static_assert(sizeof(struct E_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct E_extra_alignment) == 4, "");
_Static_assert(sizeof(struct E_extra_packed) == 4, "");
_Static_assert(_Alignof(struct E_extra_packed) == 1, "");
_Static_assert(sizeof(struct E_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct E_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct E_extra_size) == 6, "");
_Static_assert(_Alignof(struct E_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
#endif
_Static_assert(sizeof(F) == 4, "");
_Static_assert(_Alignof(F) == 4, "");
_Static_assert(sizeof(struct F_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct F_extra_alignment) == 4, "");
_Static_assert(sizeof(struct F_extra_packed) == 4, "");
_Static_assert(_Alignof(struct F_extra_packed) == 1, "");
_Static_assert(sizeof(struct F_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct F_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct F_extra_size) == 6, "");
_Static_assert(_Alignof(struct F_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
#endif
_Static_assert(sizeof(G) == 1, "");
_Static_assert(_Alignof(G) == 1, "");
_Static_assert(sizeof(struct G_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct G_extra_alignment) == 1, "");
_Static_assert(sizeof(struct G_extra_packed) == 1, "");
_Static_assert(_Alignof(struct G_extra_packed) == 1, "");
_Static_assert(sizeof(struct G_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct G_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct G_extra_size) == 3, "");
_Static_assert(_Alignof(struct G_extra_size) == 1, "");
_Static_assert(sizeof(H) == 16, "");
_Static_assert(_Alignof(H) == 16, "");
_Static_assert(sizeof(struct H_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct H_extra_alignment) == 16, "");
_Static_assert(sizeof(struct H_extra_packed) == 16, "");
_Static_assert(_Alignof(struct H_extra_packed) == 1, "");
_Static_assert(sizeof(struct H_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct H_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct H_extra_size) == 18, "");
_Static_assert(_Alignof(struct H_extra_size) == 1, "");
_Static_assert(sizeof(A2) == 8, "");
_Static_assert(_Alignof(A2) == 4, "");
_Static_assert(sizeof(struct A2_extra_alignment) == 12, "");
_Static_assert(_Alignof(struct A2_extra_alignment) == 4, "");
_Static_assert(sizeof(struct A2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct A2_extra_packed) == 1, "");
_Static_assert(sizeof(struct A2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct A2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A2_extra_size) == 10, "");
_Static_assert(_Alignof(struct A2_extra_size) == 1, "");
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
#endif
_Static_assert(sizeof(D2) == 0, "");
_Static_assert(_Alignof(D2) == 4, "");
_Static_assert(sizeof(struct D2_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct D2_extra_alignment) == 4, "");
_Static_assert(sizeof(struct D2_extra_packed) == 0, "");
_Static_assert(_Alignof(struct D2_extra_packed) == 1, "");
_Static_assert(sizeof(struct D2_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct D2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct D2_extra_size) == 2, "");
_Static_assert(_Alignof(struct D2_extra_size) == 1, "");
_Static_assert(sizeof(E2) == 4, "");
_Static_assert(_Alignof(E2) == 4, "");
_Static_assert(sizeof(struct E2_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct E2_extra_alignment) == 4, "");
_Static_assert(sizeof(struct E2_extra_packed) == 4, "");
_Static_assert(_Alignof(struct E2_extra_packed) == 1, "");
_Static_assert(sizeof(struct E2_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct E2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct E2_extra_size) == 6, "");
_Static_assert(_Alignof(struct E2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
#endif
_Static_assert(sizeof(F2) == 4, "");
_Static_assert(_Alignof(F2) == 4, "");
_Static_assert(sizeof(struct F2_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct F2_extra_alignment) == 4, "");
_Static_assert(sizeof(struct F2_extra_packed) == 4, "");
_Static_assert(_Alignof(struct F2_extra_packed) == 1, "");
_Static_assert(sizeof(struct F2_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct F2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct F2_extra_size) == 6, "");
_Static_assert(_Alignof(struct F2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
#endif
_Static_assert(sizeof(G2) == 1, "");
_Static_assert(_Alignof(G2) == 1, "");
_Static_assert(sizeof(struct G2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct G2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct G2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct G2_extra_packed) == 1, "");
_Static_assert(sizeof(struct G2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct G2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct G2_extra_size) == 3, "");
_Static_assert(_Alignof(struct G2_extra_size) == 1, "");
_Static_assert(sizeof(H2) == 16, "");
_Static_assert(_Alignof(H2) == 16, "");
_Static_assert(sizeof(struct H2_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct H2_extra_alignment) == 16, "");
_Static_assert(sizeof(struct H2_extra_packed) == 16, "");
_Static_assert(_Alignof(struct H2_extra_packed) == 1, "");
_Static_assert(sizeof(struct H2_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct H2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct H2_extra_size) == 18, "");
_Static_assert(_Alignof(struct H2_extra_size) == 1, "");
// MAPPING|FOUR|avr-avr2-other-eabi:Gcc|END
// repr targets AvrUnknownUnknown|Some("avr-avr2-other-eabi") 
#elif defined(FOUR)
_Static_assert(sizeof(A) == 8, "");
_Static_assert(_Alignof(A) == 1, "");
_Static_assert(sizeof(struct A_extra_alignment) == 9, "");
_Static_assert(_Alignof(struct A_extra_alignment) == 1, "");
_Static_assert(sizeof(struct A_extra_packed) == 8, "");
_Static_assert(_Alignof(struct A_extra_packed) == 1, "");
_Static_assert(sizeof(struct A_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct A_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A_extra_size) == 10, "");
_Static_assert(_Alignof(struct A_extra_size) == 1, "");
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
#endif
_Static_assert(sizeof(D) == 0, "");
_Static_assert(_Alignof(D) == 1, "");
_Static_assert(sizeof(struct D_extra_alignment) == 1, "");
_Static_assert(_Alignof(struct D_extra_alignment) == 1, "");
_Static_assert(sizeof(struct D_extra_packed) == 0, "");
_Static_assert(_Alignof(struct D_extra_packed) == 1, "");
_Static_assert(sizeof(struct D_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct D_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct D_extra_size) == 2, "");
_Static_assert(_Alignof(struct D_extra_size) == 1, "");
_Static_assert(sizeof(E) == 1, "");
_Static_assert(_Alignof(E) == 1, "");
_Static_assert(sizeof(struct E_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct E_extra_alignment) == 1, "");
_Static_assert(sizeof(struct E_extra_packed) == 1, "");
_Static_assert(_Alignof(struct E_extra_packed) == 1, "");
_Static_assert(sizeof(struct E_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct E_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct E_extra_size) == 3, "");
_Static_assert(_Alignof(struct E_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
#endif
_Static_assert(sizeof(F) == 1, "");
_Static_assert(_Alignof(F) == 1, "");
_Static_assert(sizeof(struct F_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct F_extra_alignment) == 1, "");
_Static_assert(sizeof(struct F_extra_packed) == 1, "");
_Static_assert(_Alignof(struct F_extra_packed) == 1, "");
_Static_assert(sizeof(struct F_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct F_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct F_extra_size) == 3, "");
_Static_assert(_Alignof(struct F_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
#endif
_Static_assert(sizeof(G) == 1, "");
_Static_assert(_Alignof(G) == 1, "");
_Static_assert(sizeof(struct G_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct G_extra_alignment) == 1, "");
_Static_assert(sizeof(struct G_extra_packed) == 1, "");
_Static_assert(_Alignof(struct G_extra_packed) == 1, "");
_Static_assert(sizeof(struct G_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct G_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct G_extra_size) == 3, "");
_Static_assert(_Alignof(struct G_extra_size) == 1, "");
_Static_assert(sizeof(H) == 16, "");
_Static_assert(_Alignof(H) == 16, "");
_Static_assert(sizeof(struct H_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct H_extra_alignment) == 16, "");
_Static_assert(sizeof(struct H_extra_packed) == 16, "");
_Static_assert(_Alignof(struct H_extra_packed) == 1, "");
_Static_assert(sizeof(struct H_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct H_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct H_extra_size) == 18, "");
_Static_assert(_Alignof(struct H_extra_size) == 1, "");
_Static_assert(sizeof(A2) == 8, "");
_Static_assert(_Alignof(A2) == 1, "");
_Static_assert(sizeof(struct A2_extra_alignment) == 9, "");
_Static_assert(_Alignof(struct A2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct A2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct A2_extra_packed) == 1, "");
_Static_assert(sizeof(struct A2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct A2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A2_extra_size) == 10, "");
_Static_assert(_Alignof(struct A2_extra_size) == 1, "");
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
#endif
_Static_assert(sizeof(D2) == 0, "");
_Static_assert(_Alignof(D2) == 1, "");
_Static_assert(sizeof(struct D2_extra_alignment) == 1, "");
_Static_assert(_Alignof(struct D2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct D2_extra_packed) == 0, "");
_Static_assert(_Alignof(struct D2_extra_packed) == 1, "");
_Static_assert(sizeof(struct D2_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct D2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct D2_extra_size) == 2, "");
_Static_assert(_Alignof(struct D2_extra_size) == 1, "");
_Static_assert(sizeof(E2) == 1, "");
_Static_assert(_Alignof(E2) == 1, "");
_Static_assert(sizeof(struct E2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct E2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct E2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct E2_extra_packed) == 1, "");
_Static_assert(sizeof(struct E2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct E2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct E2_extra_size) == 3, "");
_Static_assert(_Alignof(struct E2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
#endif
_Static_assert(sizeof(F2) == 1, "");
_Static_assert(_Alignof(F2) == 1, "");
_Static_assert(sizeof(struct F2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct F2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct F2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct F2_extra_packed) == 1, "");
_Static_assert(sizeof(struct F2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct F2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct F2_extra_size) == 3, "");
_Static_assert(_Alignof(struct F2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
#endif
_Static_assert(sizeof(G2) == 1, "");
_Static_assert(_Alignof(G2) == 1, "");
_Static_assert(sizeof(struct G2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct G2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct G2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct G2_extra_packed) == 1, "");
_Static_assert(sizeof(struct G2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct G2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct G2_extra_size) == 3, "");
_Static_assert(_Alignof(struct G2_extra_size) == 1, "");
_Static_assert(sizeof(H2) == 16, "");
_Static_assert(_Alignof(H2) == 16, "");
_Static_assert(sizeof(struct H2_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct H2_extra_alignment) == 16, "");
_Static_assert(sizeof(struct H2_extra_packed) == 16, "");
_Static_assert(_Alignof(struct H2_extra_packed) == 1, "");
_Static_assert(sizeof(struct H2_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct H2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct H2_extra_size) == 18, "");
_Static_assert(_Alignof(struct H2_extra_size) == 1, "");
// MAPPING|FIVE|x86-pentium4-ios-none:Clang|x86-i586-linux-gnu:Gcc|x86-i586-linux-musl:Gcc|x86-i686-macos-none:Clang|x86-i686-linux-android:Clang|x86-i686-freebsd-gnu:Clang|x86-i686-haiku-gnu:Clang|x86-i686-linux-gnu:Gcc|x86-i686-linux-musl:Gcc|x86-i686-netbsd-gnu:Clang|x86-i686-openbsd-gnu:Clang|END
// repr targets I386AppleIos|Some("x86-pentium4-ios-none") I586UnknownLinuxGnu|Some("x86-i586-linux-gnu") I586UnknownLinuxMusl|Some("x86-i586-linux-musl") I686AppleMacosx|Some("x86-i686-macos-none") I686LinuxAndroid|Some("x86-i686-linux-android") I686UnknownFreebsd|Some("x86-i686-freebsd-gnu") I686UnknownHaiku|Some("x86-i686-haiku-gnu") I686UnknownLinuxGnu|Some("x86-i686-linux-gnu") I686UnknownLinuxMusl|Some("x86-i686-linux-musl") I686UnknownNetbsdelf|Some("x86-i686-netbsd-gnu") I686UnknownOpenbsd|Some("x86-i686-openbsd-gnu") 
#elif defined(FIVE)
_Static_assert(sizeof(A) == 8, "");
_Static_assert(_Alignof(A) == 4, "");
_Static_assert(sizeof(struct A_extra_alignment) == 12, "");
_Static_assert(_Alignof(struct A_extra_alignment) == 4, "");
_Static_assert(sizeof(struct A_extra_packed) == 8, "");
_Static_assert(_Alignof(struct A_extra_packed) == 1, "");
_Static_assert(sizeof(struct A_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct A_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A_extra_size) == 10, "");
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
_Static_assert(_Alignof(C) == 1, "");
_Static_assert(sizeof(struct C_extra_alignment) == 5, "");
_Static_assert(_Alignof(struct C_extra_alignment) == 1, "");
_Static_assert(sizeof(struct C_extra_packed) == 4, "");
_Static_assert(_Alignof(struct C_extra_packed) == 1, "");
_Static_assert(sizeof(struct C_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct C_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct C_extra_size) == 6, "");
_Static_assert(_Alignof(struct C_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
#endif
_Static_assert(sizeof(D) == 0, "");
_Static_assert(_Alignof(D) == 1, "");
_Static_assert(sizeof(struct D_extra_alignment) == 1, "");
_Static_assert(_Alignof(struct D_extra_alignment) == 1, "");
_Static_assert(sizeof(struct D_extra_packed) == 0, "");
_Static_assert(_Alignof(struct D_extra_packed) == 1, "");
_Static_assert(sizeof(struct D_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct D_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct D_extra_size) == 2, "");
_Static_assert(_Alignof(struct D_extra_size) == 1, "");
_Static_assert(sizeof(E) == 4, "");
_Static_assert(_Alignof(E) == 1, "");
_Static_assert(sizeof(struct E_extra_alignment) == 5, "");
_Static_assert(_Alignof(struct E_extra_alignment) == 1, "");
_Static_assert(sizeof(struct E_extra_packed) == 4, "");
_Static_assert(_Alignof(struct E_extra_packed) == 1, "");
_Static_assert(sizeof(struct E_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct E_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct E_extra_size) == 6, "");
_Static_assert(_Alignof(struct E_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
#endif
_Static_assert(sizeof(F) == 4, "");
_Static_assert(_Alignof(F) == 1, "");
_Static_assert(sizeof(struct F_extra_alignment) == 5, "");
_Static_assert(_Alignof(struct F_extra_alignment) == 1, "");
_Static_assert(sizeof(struct F_extra_packed) == 4, "");
_Static_assert(_Alignof(struct F_extra_packed) == 1, "");
_Static_assert(sizeof(struct F_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct F_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct F_extra_size) == 6, "");
_Static_assert(_Alignof(struct F_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
#endif
_Static_assert(sizeof(G) == 1, "");
_Static_assert(_Alignof(G) == 1, "");
_Static_assert(sizeof(struct G_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct G_extra_alignment) == 1, "");
_Static_assert(sizeof(struct G_extra_packed) == 1, "");
_Static_assert(_Alignof(struct G_extra_packed) == 1, "");
_Static_assert(sizeof(struct G_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct G_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct G_extra_size) == 3, "");
_Static_assert(_Alignof(struct G_extra_size) == 1, "");
_Static_assert(sizeof(H) == 16, "");
_Static_assert(_Alignof(H) == 16, "");
_Static_assert(sizeof(struct H_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct H_extra_alignment) == 16, "");
_Static_assert(sizeof(struct H_extra_packed) == 16, "");
_Static_assert(_Alignof(struct H_extra_packed) == 1, "");
_Static_assert(sizeof(struct H_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct H_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct H_extra_size) == 18, "");
_Static_assert(_Alignof(struct H_extra_size) == 1, "");
_Static_assert(sizeof(A2) == 8, "");
_Static_assert(_Alignof(A2) == 4, "");
_Static_assert(sizeof(struct A2_extra_alignment) == 12, "");
_Static_assert(_Alignof(struct A2_extra_alignment) == 4, "");
_Static_assert(sizeof(struct A2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct A2_extra_packed) == 1, "");
_Static_assert(sizeof(struct A2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct A2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A2_extra_size) == 10, "");
_Static_assert(_Alignof(struct A2_extra_size) == 1, "");
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
#endif
_Static_assert(sizeof(D2) == 0, "");
_Static_assert(_Alignof(D2) == 1, "");
_Static_assert(sizeof(struct D2_extra_alignment) == 1, "");
_Static_assert(_Alignof(struct D2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct D2_extra_packed) == 0, "");
_Static_assert(_Alignof(struct D2_extra_packed) == 1, "");
_Static_assert(sizeof(struct D2_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct D2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct D2_extra_size) == 2, "");
_Static_assert(_Alignof(struct D2_extra_size) == 1, "");
_Static_assert(sizeof(E2) == 1, "");
_Static_assert(_Alignof(E2) == 1, "");
_Static_assert(sizeof(struct E2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct E2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct E2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct E2_extra_packed) == 1, "");
_Static_assert(sizeof(struct E2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct E2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct E2_extra_size) == 3, "");
_Static_assert(_Alignof(struct E2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
#endif
_Static_assert(sizeof(F2) == 1, "");
_Static_assert(_Alignof(F2) == 1, "");
_Static_assert(sizeof(struct F2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct F2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct F2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct F2_extra_packed) == 1, "");
_Static_assert(sizeof(struct F2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct F2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct F2_extra_size) == 3, "");
_Static_assert(_Alignof(struct F2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
#endif
_Static_assert(sizeof(G2) == 1, "");
_Static_assert(_Alignof(G2) == 1, "");
_Static_assert(sizeof(struct G2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct G2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct G2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct G2_extra_packed) == 1, "");
_Static_assert(sizeof(struct G2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct G2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct G2_extra_size) == 3, "");
_Static_assert(_Alignof(struct G2_extra_size) == 1, "");
_Static_assert(sizeof(H2) == 16, "");
_Static_assert(_Alignof(H2) == 16, "");
_Static_assert(sizeof(struct H2_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct H2_extra_alignment) == 16, "");
_Static_assert(sizeof(struct H2_extra_packed) == 16, "");
_Static_assert(_Alignof(struct H2_extra_packed) == 1, "");
_Static_assert(sizeof(struct H2_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct H2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct H2_extra_size) == 18, "");
_Static_assert(_Alignof(struct H2_extra_size) == 1, "");
// MAPPING|SIX|x86-i686-windows-gnu:Gcc|x86_64-x86_64-windows-gnu:Gcc|END
// repr targets I686PcWindowsGnu|Some("x86-i686-windows-gnu") X86_64PcWindowsGnu|Some("x86_64-x86_64-windows-gnu") 
#elif defined(SIX)
_Static_assert(sizeof(A) == 8, "");
_Static_assert(_Alignof(A) == 8, "");
_Static_assert(sizeof(struct A_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct A_extra_alignment) == 8, "");
_Static_assert(sizeof(struct A_extra_packed) == 8, "");
_Static_assert(_Alignof(struct A_extra_packed) == 1, "");
_Static_assert(sizeof(struct A_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct A_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A_extra_size) == 10, "");
_Static_assert(_Alignof(struct A_extra_size) == 1, "");
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
#endif
_Static_assert(sizeof(D) == 0, "");
_Static_assert(_Alignof(D) == 1, "");
_Static_assert(sizeof(struct D_extra_alignment) == 1, "");
_Static_assert(_Alignof(struct D_extra_alignment) == 1, "");
_Static_assert(sizeof(struct D_extra_packed) == 0, "");
_Static_assert(_Alignof(struct D_extra_packed) == 1, "");
_Static_assert(sizeof(struct D_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct D_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct D_extra_size) == 2, "");
_Static_assert(_Alignof(struct D_extra_size) == 1, "");
_Static_assert(sizeof(E) == 1, "");
_Static_assert(_Alignof(E) == 1, "");
_Static_assert(sizeof(struct E_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct E_extra_alignment) == 1, "");
_Static_assert(sizeof(struct E_extra_packed) == 1, "");
_Static_assert(_Alignof(struct E_extra_packed) == 1, "");
_Static_assert(sizeof(struct E_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct E_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct E_extra_size) == 3, "");
_Static_assert(_Alignof(struct E_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
#endif
_Static_assert(sizeof(F) == 1, "");
_Static_assert(_Alignof(F) == 1, "");
_Static_assert(sizeof(struct F_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct F_extra_alignment) == 1, "");
_Static_assert(sizeof(struct F_extra_packed) == 1, "");
_Static_assert(_Alignof(struct F_extra_packed) == 1, "");
_Static_assert(sizeof(struct F_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct F_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct F_extra_size) == 3, "");
_Static_assert(_Alignof(struct F_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
#endif
_Static_assert(sizeof(G) == 4, "");
_Static_assert(_Alignof(G) == 1, "");
_Static_assert(sizeof(struct G_extra_alignment) == 5, "");
_Static_assert(_Alignof(struct G_extra_alignment) == 1, "");
_Static_assert(sizeof(struct G_extra_packed) == 4, "");
_Static_assert(_Alignof(struct G_extra_packed) == 1, "");
_Static_assert(sizeof(struct G_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct G_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct G_extra_size) == 6, "");
_Static_assert(_Alignof(struct G_extra_size) == 1, "");
_Static_assert(sizeof(H) == 4, "");
_Static_assert(_Alignof(H) == 1, "");
_Static_assert(sizeof(struct H_extra_alignment) == 5, "");
_Static_assert(_Alignof(struct H_extra_alignment) == 1, "");
_Static_assert(sizeof(struct H_extra_packed) == 4, "");
_Static_assert(_Alignof(struct H_extra_packed) == 1, "");
_Static_assert(sizeof(struct H_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct H_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct H_extra_size) == 6, "");
_Static_assert(_Alignof(struct H_extra_size) == 1, "");
_Static_assert(sizeof(A2) == 8, "");
_Static_assert(_Alignof(A2) == 8, "");
_Static_assert(sizeof(struct A2_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct A2_extra_alignment) == 8, "");
_Static_assert(sizeof(struct A2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct A2_extra_packed) == 1, "");
_Static_assert(sizeof(struct A2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct A2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A2_extra_size) == 10, "");
_Static_assert(_Alignof(struct A2_extra_size) == 1, "");
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
#endif
_Static_assert(sizeof(D2) == 0, "");
_Static_assert(_Alignof(D2) == 1, "");
_Static_assert(sizeof(struct D2_extra_alignment) == 1, "");
_Static_assert(_Alignof(struct D2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct D2_extra_packed) == 0, "");
_Static_assert(_Alignof(struct D2_extra_packed) == 1, "");
_Static_assert(sizeof(struct D2_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct D2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct D2_extra_size) == 2, "");
_Static_assert(_Alignof(struct D2_extra_size) == 1, "");
_Static_assert(sizeof(E2) == 1, "");
_Static_assert(_Alignof(E2) == 1, "");
_Static_assert(sizeof(struct E2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct E2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct E2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct E2_extra_packed) == 1, "");
_Static_assert(sizeof(struct E2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct E2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct E2_extra_size) == 3, "");
_Static_assert(_Alignof(struct E2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
#endif
_Static_assert(sizeof(F2) == 1, "");
_Static_assert(_Alignof(F2) == 1, "");
_Static_assert(sizeof(struct F2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct F2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct F2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct F2_extra_packed) == 1, "");
_Static_assert(sizeof(struct F2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct F2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct F2_extra_size) == 3, "");
_Static_assert(_Alignof(struct F2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
#endif
_Static_assert(sizeof(G2) == 1, "");
_Static_assert(_Alignof(G2) == 1, "");
_Static_assert(sizeof(struct G2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct G2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct G2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct G2_extra_packed) == 1, "");
_Static_assert(sizeof(struct G2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct G2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct G2_extra_size) == 3, "");
_Static_assert(_Alignof(struct G2_extra_size) == 1, "");
_Static_assert(sizeof(H2) == 1, "");
_Static_assert(_Alignof(H2) == 1, "");
_Static_assert(sizeof(struct H2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct H2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct H2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct H2_extra_packed) == 1, "");
_Static_assert(sizeof(struct H2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct H2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct H2_extra_size) == 3, "");
_Static_assert(_Alignof(struct H2_extra_size) == 1, "");
// MAPPING|SEVEN|msp430-msp430-other-eabi:Clang|END
// repr targets Msp430NoneElf|Some("msp430-msp430-other-eabi") 
#elif defined(SEVEN)
_Static_assert(sizeof(A) == 8, "");
_Static_assert(_Alignof(A) == 2, "");
_Static_assert(sizeof(struct A_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct A_extra_alignment) == 2, "");
_Static_assert(sizeof(struct A_extra_packed) == 8, "");
_Static_assert(_Alignof(struct A_extra_packed) == 1, "");
_Static_assert(sizeof(struct A_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct A_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A_extra_size) == 10, "");
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
_Static_assert(_Alignof(C) == 1, "");
_Static_assert(sizeof(struct C_extra_alignment) == 3, "");
_Static_assert(_Alignof(struct C_extra_alignment) == 1, "");
_Static_assert(sizeof(struct C_extra_packed) == 2, "");
_Static_assert(_Alignof(struct C_extra_packed) == 1, "");
_Static_assert(sizeof(struct C_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct C_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct C_extra_size) == 4, "");
_Static_assert(_Alignof(struct C_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
#endif
_Static_assert(sizeof(D) == 0, "");
_Static_assert(_Alignof(D) == 1, "");
_Static_assert(sizeof(struct D_extra_alignment) == 1, "");
_Static_assert(_Alignof(struct D_extra_alignment) == 1, "");
_Static_assert(sizeof(struct D_extra_packed) == 0, "");
_Static_assert(_Alignof(struct D_extra_packed) == 1, "");
_Static_assert(sizeof(struct D_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct D_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct D_extra_size) == 2, "");
_Static_assert(_Alignof(struct D_extra_size) == 1, "");
_Static_assert(sizeof(E) == 2, "");
_Static_assert(_Alignof(E) == 1, "");
_Static_assert(sizeof(struct E_extra_alignment) == 3, "");
_Static_assert(_Alignof(struct E_extra_alignment) == 1, "");
_Static_assert(sizeof(struct E_extra_packed) == 2, "");
_Static_assert(_Alignof(struct E_extra_packed) == 1, "");
_Static_assert(sizeof(struct E_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct E_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct E_extra_size) == 4, "");
_Static_assert(_Alignof(struct E_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
#endif
_Static_assert(sizeof(F) == 2, "");
_Static_assert(_Alignof(F) == 1, "");
_Static_assert(sizeof(struct F_extra_alignment) == 3, "");
_Static_assert(_Alignof(struct F_extra_alignment) == 1, "");
_Static_assert(sizeof(struct F_extra_packed) == 2, "");
_Static_assert(_Alignof(struct F_extra_packed) == 1, "");
_Static_assert(sizeof(struct F_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct F_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct F_extra_size) == 4, "");
_Static_assert(_Alignof(struct F_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
#endif
_Static_assert(sizeof(G) == 1, "");
_Static_assert(_Alignof(G) == 1, "");
_Static_assert(sizeof(struct G_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct G_extra_alignment) == 1, "");
_Static_assert(sizeof(struct G_extra_packed) == 1, "");
_Static_assert(_Alignof(struct G_extra_packed) == 1, "");
_Static_assert(sizeof(struct G_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct G_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct G_extra_size) == 3, "");
_Static_assert(_Alignof(struct G_extra_size) == 1, "");
_Static_assert(sizeof(H) == 16, "");
_Static_assert(_Alignof(H) == 16, "");
_Static_assert(sizeof(struct H_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct H_extra_alignment) == 16, "");
_Static_assert(sizeof(struct H_extra_packed) == 16, "");
_Static_assert(_Alignof(struct H_extra_packed) == 1, "");
_Static_assert(sizeof(struct H_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct H_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct H_extra_size) == 18, "");
_Static_assert(_Alignof(struct H_extra_size) == 1, "");
_Static_assert(sizeof(A2) == 8, "");
_Static_assert(_Alignof(A2) == 2, "");
_Static_assert(sizeof(struct A2_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct A2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct A2_extra_packed) == 8, "");
_Static_assert(_Alignof(struct A2_extra_packed) == 1, "");
_Static_assert(sizeof(struct A2_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct A2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A2_extra_size) == 10, "");
_Static_assert(_Alignof(struct A2_extra_size) == 1, "");
_Static_assert(sizeof(B2) == 2, "");
_Static_assert(_Alignof(B2) == 2, "");
_Static_assert(sizeof(struct B2_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct B2_extra_alignment) == 2, "");
_Static_assert(sizeof(struct B2_extra_packed) == 2, "");
_Static_assert(_Alignof(struct B2_extra_packed) == 1, "");
_Static_assert(sizeof(struct B2_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct B2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct B2_extra_size) == 4, "");
_Static_assert(_Alignof(struct B2_extra_size) == 1, "");
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
#endif
_Static_assert(sizeof(D2) == 0, "");
_Static_assert(_Alignof(D2) == 1, "");
_Static_assert(sizeof(struct D2_extra_alignment) == 1, "");
_Static_assert(_Alignof(struct D2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct D2_extra_packed) == 0, "");
_Static_assert(_Alignof(struct D2_extra_packed) == 1, "");
_Static_assert(sizeof(struct D2_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct D2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct D2_extra_size) == 2, "");
_Static_assert(_Alignof(struct D2_extra_size) == 1, "");
_Static_assert(sizeof(E2) == 1, "");
_Static_assert(_Alignof(E2) == 1, "");
_Static_assert(sizeof(struct E2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct E2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct E2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct E2_extra_packed) == 1, "");
_Static_assert(sizeof(struct E2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct E2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct E2_extra_size) == 3, "");
_Static_assert(_Alignof(struct E2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
#endif
_Static_assert(sizeof(F2) == 1, "");
_Static_assert(_Alignof(F2) == 1, "");
_Static_assert(sizeof(struct F2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct F2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct F2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct F2_extra_packed) == 1, "");
_Static_assert(sizeof(struct F2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct F2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct F2_extra_size) == 3, "");
_Static_assert(_Alignof(struct F2_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
#endif
_Static_assert(sizeof(G2) == 1, "");
_Static_assert(_Alignof(G2) == 1, "");
_Static_assert(sizeof(struct G2_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct G2_extra_alignment) == 1, "");
_Static_assert(sizeof(struct G2_extra_packed) == 1, "");
_Static_assert(_Alignof(struct G2_extra_packed) == 1, "");
_Static_assert(sizeof(struct G2_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct G2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct G2_extra_size) == 3, "");
_Static_assert(_Alignof(struct G2_extra_size) == 1, "");
_Static_assert(sizeof(H2) == 16, "");
_Static_assert(_Alignof(H2) == 16, "");
_Static_assert(sizeof(struct H2_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct H2_extra_alignment) == 16, "");
_Static_assert(sizeof(struct H2_extra_packed) == 16, "");
_Static_assert(_Alignof(struct H2_extra_packed) == 1, "");
_Static_assert(sizeof(struct H2_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct H2_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct H2_extra_size) == 18, "");
_Static_assert(_Alignof(struct H2_extra_size) == 1, "");
#endif
