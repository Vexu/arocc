// SPDX-License-Identifier: GPL-3.0-or-later

// This test file is auto-generated. do not edit.
// This file is a derivative work from the test files found
// in this repo : https://github.com/mahkoh/repr-c
// and is under the same licence as the original work.

typedef char A;
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

typedef unsigned char B;
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

typedef signed char C;
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

typedef unsigned short D;
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

typedef short E;
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

typedef unsigned int F;
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

typedef int G;
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

typedef unsigned long H;
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

typedef long I;
I var33;
struct I_extra_alignment {
    char a;
    I b;
};
struct I_extra_alignment var34;
#pragma pack(1)
struct I_extra_packed {
#ifdef MSVC
    char a[sizeof(I)];
#else
    I a;
#endif
};
#pragma pack()
struct I_extra_required_alignment {
    char a;
    struct I_extra_packed b;
};
struct I_extra_required_alignment var35;
struct I_extra_size {
    char a[sizeof(I)+1];
    char b;
};
struct I_extra_size var36;

typedef unsigned long long J;
J var37;
struct J_extra_alignment {
    char a;
    J b;
};
struct J_extra_alignment var38;
#pragma pack(1)
struct J_extra_packed {
#ifdef MSVC
    char a[sizeof(J)];
#else
    J a;
#endif
};
#pragma pack()
struct J_extra_required_alignment {
    char a;
    struct J_extra_packed b;
};
struct J_extra_required_alignment var39;
struct J_extra_size {
    char a[sizeof(J)+1];
    char b;
};
struct J_extra_size var40;

typedef long long K;
K var41;
struct K_extra_alignment {
    char a;
    K b;
};
struct K_extra_alignment var42;
#pragma pack(1)
struct K_extra_packed {
#ifdef MSVC
    char a[sizeof(K)];
#else
    K a;
#endif
};
#pragma pack()
struct K_extra_required_alignment {
    char a;
    struct K_extra_packed b;
};
struct K_extra_required_alignment var43;
struct K_extra_size {
    char a[sizeof(K)+1];
    char b;
};
struct K_extra_size var44;

typedef void* L;
L var45;
struct L_extra_alignment {
    char a;
    L b;
};
struct L_extra_alignment var46;
#pragma pack(1)
struct L_extra_packed {
#ifdef MSVC
    char a[sizeof(L)];
#else
    L a;
#endif
};
#pragma pack()
struct L_extra_required_alignment {
    char a;
    struct L_extra_packed b;
};
struct L_extra_required_alignment var47;
struct L_extra_size {
    char a[sizeof(L)+1];
    char b;
};
struct L_extra_size var48;

typedef float M;
M var49;
struct M_extra_alignment {
    char a;
    M b;
};
struct M_extra_alignment var50;
#pragma pack(1)
struct M_extra_packed {
#ifdef MSVC
    char a[sizeof(M)];
#else
    M a;
#endif
};
#pragma pack()
struct M_extra_required_alignment {
    char a;
    struct M_extra_packed b;
};
struct M_extra_required_alignment var51;
struct M_extra_size {
    char a[sizeof(M)+1];
    char b;
};
struct M_extra_size var52;

typedef double N;
N var53;
struct N_extra_alignment {
    char a;
    N b;
};
struct N_extra_alignment var54;
#pragma pack(1)
struct N_extra_packed {
#ifdef MSVC
    char a[sizeof(N)];
#else
    N a;
#endif
};
#pragma pack()
struct N_extra_required_alignment {
    char a;
    struct N_extra_packed b;
};
struct N_extra_required_alignment var55;
struct N_extra_size {
    char a[sizeof(N)+1];
    char b;
};
struct N_extra_size var56;

// MAPPING|ONE|aarch64-generic-macos-none:Clang|aarch64-generic-fuchsia-gnu:Clang|aarch64-generic-linux-android:Clang|aarch64-generic-freebsd-gnu:Clang|aarch64-generic-hermit-eabi:Clang|aarch64-generic-linux-gnu:Gcc|aarch64-generic-linux-musl:Gcc|aarch64-generic-netbsd-gnu:Clang|aarch64-generic-other-none:Clang|aarch64-generic-openbsd-gnu:Clang|aarch64-generic-ios-none:Clang|aarch64-generic-ios-macabi:Clang|aarch64-generic-tvos-none:Clang|mips64el-mips64-linux-gnuabi64:Gcc|mips64el-mips64-linux-musl:Gcc|mips64-mips64-linux-gnuabi64:Gcc|mips64-mips64-linux-musl:Gcc|mips-mips32-linux-gnuabi64:Gcc|mips-mips64r6-linux-gnuabi64:Gcc|powerpc64le-ppc64le-linux-gnu:Gcc|powerpc64le-ppc64le-linux-musl:Gcc|powerpc64-ppc64-freebsd-gnu:Clang|powerpc64-ppc64-linux-gnu:Gcc|powerpc64-ppc64-linux-musl:Gcc|riscv64-baseline_rv64-other-eabi:Clang|riscv64-baseline_rv64-linux-gnu:Gcc|s390x-generic-linux-gnu:Gcc|sparc64-v9-linux-gnu:Gcc|sparc64-v9-netbsd-gnu:Clang|sparc64-v9-openbsd-gnu:Clang|sparc64-v9-illumos-eabi:Clang|x86_64-x86_64-ios-macabi:Clang|x86_64-x86_64-ios-none:Clang|x86_64-x86_64-macos-none:Clang|x86_64-x86_64-tvos-none:Clang|x86_64-x86_64-other-eabi:Clang|x86_64-x86_64-fuchsia-gnu:Clang|x86_64-x86_64-linux-android:Clang|x86_64-x86_64-illumos-eabi:Clang|x86_64-x86_64-dragonfly-eabi:Clang|x86_64-x86_64-freebsd-gnu:Clang|x86_64-x86_64-haiku-gnu:Clang|x86_64-x86_64-hermit-eabi:Clang|x86_64-x86_64-linux-gnu:Gcc|x86_64-x86_64-linux-musl:Gcc|x86_64-x86_64-netbsd-gnu:Clang|x86_64-x86_64-openbsd-gnu:Clang|END
// repr targets Aarch64AppleMacosx|Some("aarch64-generic-macos-none") Aarch64Fuchsia|Some("aarch64-generic-fuchsia-gnu") Aarch64LinuxAndroid|Some("aarch64-generic-linux-android") Aarch64UnknownFreebsd|Some("aarch64-generic-freebsd-gnu") Aarch64UnknownHermit|Some("aarch64-generic-hermit-eabi") Aarch64UnknownLinuxGnu|Some("aarch64-generic-linux-gnu") Aarch64UnknownLinuxMusl|Some("aarch64-generic-linux-musl") Aarch64UnknownNetbsd|Some("aarch64-generic-netbsd-gnu") Aarch64UnknownNone|Some("aarch64-generic-other-none") Aarch64UnknownOpenbsd|Some("aarch64-generic-openbsd-gnu") Aarch64UnknownRedox|None Arm64AppleIos|Some("aarch64-generic-ios-none") Arm64AppleIosMacabi|Some("aarch64-generic-ios-macabi") Arm64AppleTvos|Some("aarch64-generic-tvos-none") Mips64elUnknownLinuxGnuabi64|Some("mips64el-mips64-linux-gnuabi64") Mips64elUnknownLinuxMusl|Some("mips64el-mips64-linux-musl") Mips64UnknownLinuxGnuabi64|Some("mips64-mips64-linux-gnuabi64") Mips64UnknownLinuxMusl|Some("mips64-mips64-linux-musl") Mipsisa64r6elUnknownLinuxGnuabi64|Some("mips-mips32-linux-gnuabi64") Mipsisa64r6UnknownLinuxGnuabi64|Some("mips-mips64r6-linux-gnuabi64") Powerpc64leUnknownLinuxGnu|Some("powerpc64le-ppc64le-linux-gnu") Powerpc64leUnknownLinuxMusl|Some("powerpc64le-ppc64le-linux-musl") Powerpc64UnknownFreebsd|Some("powerpc64-ppc64-freebsd-gnu") Powerpc64UnknownLinuxGnu|Some("powerpc64-ppc64-linux-gnu") Powerpc64UnknownLinuxMusl|Some("powerpc64-ppc64-linux-musl") Riscv64|Some("riscv64-baseline_rv64-other-eabi") Riscv64UnknownLinuxGnu|Some("riscv64-baseline_rv64-linux-gnu") S390xUnknownLinuxGnu|Some("s390x-generic-linux-gnu") Sparc64UnknownLinuxGnu|Some("sparc64-v9-linux-gnu") Sparc64UnknownNetbsd|Some("sparc64-v9-netbsd-gnu") Sparc64UnknownOpenbsd|Some("sparc64-v9-openbsd-gnu") Sparcv9Sunillumos|Some("sparc64-v9-illumos-eabi") X86_64AppleIosMacabi|Some("x86_64-x86_64-ios-macabi") X86_64AppleIos|Some("x86_64-x86_64-ios-none") X86_64AppleMacosx|Some("x86_64-x86_64-macos-none") X86_64AppleTvos|Some("x86_64-x86_64-tvos-none") X86_64Elf|Some("x86_64-x86_64-other-eabi") X86_64Fuchsia|Some("x86_64-x86_64-fuchsia-gnu") X86_64LinuxAndroid|Some("x86_64-x86_64-linux-android") X86_64Pcillumos|Some("x86_64-x86_64-illumos-eabi") X86_64RumprunNetbsd|None X86_64UnknownDragonfly|Some("x86_64-x86_64-dragonfly-eabi") X86_64UnknownFreebsd|Some("x86_64-x86_64-freebsd-gnu") X86_64UnknownHaiku|Some("x86_64-x86_64-haiku-gnu") X86_64UnknownHermit|Some("x86_64-x86_64-hermit-eabi") X86_64UnknownL4reUclibc|None X86_64UnknownLinuxGnu|Some("x86_64-x86_64-linux-gnu") X86_64UnknownLinuxMusl|Some("x86_64-x86_64-linux-musl") X86_64UnknownNetbsd|Some("x86_64-x86_64-netbsd-gnu") X86_64UnknownOpenbsd|Some("x86_64-x86_64-openbsd-gnu") X86_64UnknownRedox|None 
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
_Static_assert(sizeof(D) == 2, "");
_Static_assert(_Alignof(D) == 2, "");
_Static_assert(sizeof(struct D_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct D_extra_alignment) == 2, "");
_Static_assert(sizeof(struct D_extra_packed) == 2, "");
_Static_assert(_Alignof(struct D_extra_packed) == 1, "");
_Static_assert(sizeof(struct D_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct D_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct D_extra_size) == 4, "");
_Static_assert(_Alignof(struct D_extra_size) == 1, "");
_Static_assert(sizeof(E) == 2, "");
_Static_assert(_Alignof(E) == 2, "");
_Static_assert(sizeof(struct E_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct E_extra_alignment) == 2, "");
_Static_assert(sizeof(struct E_extra_packed) == 2, "");
_Static_assert(_Alignof(struct E_extra_packed) == 1, "");
_Static_assert(sizeof(struct E_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct E_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct E_extra_size) == 4, "");
_Static_assert(_Alignof(struct E_extra_size) == 1, "");
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
_Static_assert(sizeof(G) == 4, "");
_Static_assert(_Alignof(G) == 4, "");
_Static_assert(sizeof(struct G_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct G_extra_alignment) == 4, "");
_Static_assert(sizeof(struct G_extra_packed) == 4, "");
_Static_assert(_Alignof(struct G_extra_packed) == 1, "");
_Static_assert(sizeof(struct G_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct G_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct G_extra_size) == 6, "");
_Static_assert(_Alignof(struct G_extra_size) == 1, "");
_Static_assert(sizeof(H) == 8, "");
_Static_assert(_Alignof(H) == 8, "");
_Static_assert(sizeof(struct H_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct H_extra_alignment) == 8, "");
_Static_assert(sizeof(struct H_extra_packed) == 8, "");
_Static_assert(_Alignof(struct H_extra_packed) == 1, "");
_Static_assert(sizeof(struct H_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct H_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct H_extra_size) == 10, "");
_Static_assert(_Alignof(struct H_extra_size) == 1, "");
_Static_assert(sizeof(I) == 8, "");
_Static_assert(_Alignof(I) == 8, "");
_Static_assert(sizeof(struct I_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct I_extra_alignment) == 8, "");
_Static_assert(sizeof(struct I_extra_packed) == 8, "");
_Static_assert(_Alignof(struct I_extra_packed) == 1, "");
_Static_assert(sizeof(struct I_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct I_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct I_extra_size) == 10, "");
_Static_assert(_Alignof(struct I_extra_size) == 1, "");
_Static_assert(sizeof(J) == 8, "");
_Static_assert(_Alignof(J) == 8, "");
_Static_assert(sizeof(struct J_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct J_extra_alignment) == 8, "");
_Static_assert(sizeof(struct J_extra_packed) == 8, "");
_Static_assert(_Alignof(struct J_extra_packed) == 1, "");
_Static_assert(sizeof(struct J_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct J_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct J_extra_size) == 10, "");
_Static_assert(_Alignof(struct J_extra_size) == 1, "");
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
_Static_assert(sizeof(L) == 8, "");
_Static_assert(_Alignof(L) == 8, "");
_Static_assert(sizeof(struct L_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct L_extra_alignment) == 8, "");
_Static_assert(sizeof(struct L_extra_packed) == 8, "");
_Static_assert(_Alignof(struct L_extra_packed) == 1, "");
_Static_assert(sizeof(struct L_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct L_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct L_extra_size) == 10, "");
_Static_assert(_Alignof(struct L_extra_size) == 1, "");
_Static_assert(sizeof(M) == 4, "");
_Static_assert(_Alignof(M) == 4, "");
_Static_assert(sizeof(struct M_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct M_extra_alignment) == 4, "");
_Static_assert(sizeof(struct M_extra_packed) == 4, "");
_Static_assert(_Alignof(struct M_extra_packed) == 1, "");
_Static_assert(sizeof(struct M_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct M_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct M_extra_size) == 6, "");
_Static_assert(_Alignof(struct M_extra_size) == 1, "");
_Static_assert(sizeof(N) == 8, "");
_Static_assert(_Alignof(N) == 8, "");
_Static_assert(sizeof(struct N_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct N_extra_alignment) == 8, "");
_Static_assert(sizeof(struct N_extra_packed) == 8, "");
_Static_assert(_Alignof(struct N_extra_packed) == 1, "");
_Static_assert(sizeof(struct N_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct N_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct N_extra_size) == 10, "");
_Static_assert(_Alignof(struct N_extra_size) == 1, "");
// MAPPING|TWO|aarch64-generic-windows-msvc:Msvc|x86_64-x86_64-windows-gnu:Gcc|x86_64-x86_64-windows-msvc:Msvc|x86_64-x86_64-uefi-msvc:Msvc|END
// repr targets Aarch64PcWindowsMsvc|Some("aarch64-generic-windows-msvc") X86_64PcWindowsGnu|Some("x86_64-x86_64-windows-gnu") X86_64PcWindowsMsvc|Some("x86_64-x86_64-windows-msvc") X86_64UnknownWindows|Some("x86_64-x86_64-uefi-msvc") 
#elif defined(TWO)
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
_Static_assert(sizeof(D) == 2, "");
_Static_assert(_Alignof(D) == 2, "");
_Static_assert(sizeof(struct D_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct D_extra_alignment) == 2, "");
_Static_assert(sizeof(struct D_extra_packed) == 2, "");
_Static_assert(_Alignof(struct D_extra_packed) == 1, "");
_Static_assert(sizeof(struct D_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct D_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct D_extra_size) == 4, "");
_Static_assert(_Alignof(struct D_extra_size) == 1, "");
_Static_assert(sizeof(E) == 2, "");
_Static_assert(_Alignof(E) == 2, "");
_Static_assert(sizeof(struct E_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct E_extra_alignment) == 2, "");
_Static_assert(sizeof(struct E_extra_packed) == 2, "");
_Static_assert(_Alignof(struct E_extra_packed) == 1, "");
_Static_assert(sizeof(struct E_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct E_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct E_extra_size) == 4, "");
_Static_assert(_Alignof(struct E_extra_size) == 1, "");
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
_Static_assert(sizeof(G) == 4, "");
_Static_assert(_Alignof(G) == 4, "");
_Static_assert(sizeof(struct G_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct G_extra_alignment) == 4, "");
_Static_assert(sizeof(struct G_extra_packed) == 4, "");
_Static_assert(_Alignof(struct G_extra_packed) == 1, "");
_Static_assert(sizeof(struct G_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct G_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct G_extra_size) == 6, "");
_Static_assert(_Alignof(struct G_extra_size) == 1, "");
_Static_assert(sizeof(H) == 4, "");
_Static_assert(_Alignof(H) == 4, "");
_Static_assert(sizeof(struct H_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct H_extra_alignment) == 4, "");
_Static_assert(sizeof(struct H_extra_packed) == 4, "");
_Static_assert(_Alignof(struct H_extra_packed) == 1, "");
_Static_assert(sizeof(struct H_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct H_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct H_extra_size) == 6, "");
_Static_assert(_Alignof(struct H_extra_size) == 1, "");
_Static_assert(sizeof(I) == 4, "");
_Static_assert(_Alignof(I) == 4, "");
_Static_assert(sizeof(struct I_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct I_extra_alignment) == 4, "");
_Static_assert(sizeof(struct I_extra_packed) == 4, "");
_Static_assert(_Alignof(struct I_extra_packed) == 1, "");
_Static_assert(sizeof(struct I_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct I_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct I_extra_size) == 6, "");
_Static_assert(_Alignof(struct I_extra_size) == 1, "");
_Static_assert(sizeof(J) == 8, "");
_Static_assert(_Alignof(J) == 8, "");
_Static_assert(sizeof(struct J_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct J_extra_alignment) == 8, "");
_Static_assert(sizeof(struct J_extra_packed) == 8, "");
_Static_assert(_Alignof(struct J_extra_packed) == 1, "");
_Static_assert(sizeof(struct J_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct J_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct J_extra_size) == 10, "");
_Static_assert(_Alignof(struct J_extra_size) == 1, "");
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
_Static_assert(sizeof(L) == 8, "");
_Static_assert(_Alignof(L) == 8, "");
_Static_assert(sizeof(struct L_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct L_extra_alignment) == 8, "");
_Static_assert(sizeof(struct L_extra_packed) == 8, "");
_Static_assert(_Alignof(struct L_extra_packed) == 1, "");
_Static_assert(sizeof(struct L_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct L_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct L_extra_size) == 10, "");
_Static_assert(_Alignof(struct L_extra_size) == 1, "");
_Static_assert(sizeof(M) == 4, "");
_Static_assert(_Alignof(M) == 4, "");
_Static_assert(sizeof(struct M_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct M_extra_alignment) == 4, "");
_Static_assert(sizeof(struct M_extra_packed) == 4, "");
_Static_assert(_Alignof(struct M_extra_packed) == 1, "");
_Static_assert(sizeof(struct M_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct M_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct M_extra_size) == 6, "");
_Static_assert(_Alignof(struct M_extra_size) == 1, "");
_Static_assert(sizeof(N) == 8, "");
_Static_assert(_Alignof(N) == 8, "");
_Static_assert(sizeof(struct N_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct N_extra_alignment) == 8, "");
_Static_assert(sizeof(struct N_extra_packed) == 8, "");
_Static_assert(_Alignof(struct N_extra_packed) == 1, "");
_Static_assert(sizeof(struct N_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct N_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct N_extra_size) == 10, "");
_Static_assert(_Alignof(struct N_extra_size) == 1, "");
// MAPPING|THREE|arm-baseline-other-eabi:Clang|arm-baseline-other-eabihf:Clang|arm-baseline-linux-gnueabi:Gcc|arm-baseline-linux-gnueabihf:Gcc|arm-arm710t-linux-gnueabi:Gcc|arm-arm1020e-linux-gnueabi:Gcc|arm-arm1136j_s-freebsd-gnueabihf:Clang|arm-arm1136j_s-netbsd-eabihf:Clang|arm-baseline-other-eabi:Clang|arm-baseline-other-eabihf:Clang|arm-cortex_r4-linux-android:Clang|arm-cortex_r4-other-eabi:Clang|arm-cortex_r4-other-eabihf:Clang|arm-cortex_r4-freebsd-gnueabihf:Clang|arm-cortex_r4-linux-gnueabi:Gcc|arm-cortex_r4-linux-gnueabihf:Gcc|arm-cortex_r4-netbsd-eabihf:Clang|hexagon-generic-linux-musl:Clang|x86-i586-windows-msvc:Msvc|x86-i686-windows-gnu:Gcc|x86-i686-windows-msvc:Msvc|x86-i686-uefi-msvc:Msvc|mipsel-mips32-linux-gnu:Gcc|mipsel-mips32-linux-musl:Gcc|mipsel-mips32-other-none:Clang|mips-mips32-linux-gnu:Gcc|mips-mips32r6-linux-gnu:Gcc|mips-mips32-linux-gnu:Gcc|mips-mips32-linux-musl:Gcc|powerpc-ppc-linux-gnu:Gcc|powerpc-ppc-linux-musl:Gcc|powerpc-ppc-netbsd-gnu:Clang|riscv32-baseline_rv32-other-eabi:Clang|riscv32-baseline_rv32-linux-gnu:Gcc|sparc-v8-linux-gnu:Gcc|thumb-arm710t-other-eabi:Clang|thumb-cortex_m0-other-eabi:Clang|thumb-baseline-windows-msvc:Msvc|thumb-cortex_m4-other-eabihf:Clang|thumb-cortex_m4-other-eabi:Clang|thumb-cortex_m3-other-eabi:Clang|thumb-baseline-other-eabi:Clang|thumb-cortex_m33-other-eabihf:Clang|thumb-cortex_m33-other-eabi:Clang|wasm32-generic-emscripten-musl:Clang|wasm32-generic-other-musl:Clang|wasm32-generic-wasi-musl:Clang|x86_64-x86_64-linux-gnux32:Gcc|END
// repr targets Armebv7rUnknownNoneEabi|Some("arm-baseline-other-eabi") Armebv7rUnknownNoneEabihf|Some("arm-baseline-other-eabihf") ArmLinuxAndroideabi|None ArmUnknownLinuxGnueabi|Some("arm-baseline-linux-gnueabi") ArmUnknownLinuxGnueabihf|Some("arm-baseline-linux-gnueabihf") Armv4tUnknownLinuxGnueabi|Some("arm-arm710t-linux-gnueabi") Armv5teUnknownLinuxGnueabi|Some("arm-arm1020e-linux-gnueabi") Armv5teUnknownLinuxUclibcgnueabi|None Armv6UnknownFreebsdGnueabihf|Some("arm-arm1136j_s-freebsd-gnueabihf") Armv6UnknownNetbsdelfEabihf|Some("arm-arm1136j_s-netbsd-eabihf") Armv7aNoneEabi|Some("arm-baseline-other-eabi") Armv7aNoneEabihf|Some("arm-baseline-other-eabihf") Armv7NoneLinuxAndroid|Some("arm-cortex_r4-linux-android") Armv7rUnknownNoneEabi|Some("arm-cortex_r4-other-eabi") Armv7rUnknownNoneEabihf|Some("arm-cortex_r4-other-eabihf") Armv7UnknownFreebsdGnueabihf|Some("arm-cortex_r4-freebsd-gnueabihf") Armv7UnknownLinuxGnueabi|Some("arm-cortex_r4-linux-gnueabi") Armv7UnknownLinuxGnueabihf|Some("arm-cortex_r4-linux-gnueabihf") Armv7UnknownNetbsdelfEabihf|Some("arm-cortex_r4-netbsd-eabihf") HexagonUnknownLinuxMusl|Some("hexagon-generic-linux-musl") I586PcWindowsMsvc|Some("x86-i586-windows-msvc") I686PcWindowsGnu|Some("x86-i686-windows-gnu") I686PcWindowsMsvc|Some("x86-i686-windows-msvc") I686UnknownWindows|Some("x86-i686-uefi-msvc") MipselSonyPsp|None MipselUnknownLinuxGnu|Some("mipsel-mips32-linux-gnu") MipselUnknownLinuxMusl|Some("mipsel-mips32-linux-musl") MipselUnknownLinuxUclibc|None MipselUnknownNone|Some("mipsel-mips32-other-none") Mipsisa32r6elUnknownLinuxGnu|Some("mips-mips32-linux-gnu") Mipsisa32r6UnknownLinuxGnu|Some("mips-mips32r6-linux-gnu") MipsUnknownLinuxGnu|Some("mips-mips32-linux-gnu") MipsUnknownLinuxMusl|Some("mips-mips32-linux-musl") MipsUnknownLinuxUclibc|None PowerpcUnknownLinuxGnu|Some("powerpc-ppc-linux-gnu") PowerpcUnknownLinuxGnuspe|None PowerpcUnknownLinuxMusl|Some("powerpc-ppc-linux-musl") PowerpcUnknownNetbsd|Some("powerpc-ppc-netbsd-gnu") Riscv32|Some("riscv32-baseline_rv32-other-eabi") Riscv32UnknownLinuxGnu|Some("riscv32-baseline_rv32-linux-gnu") SparcUnknownLinuxGnu|Some("sparc-v8-linux-gnu") Thumbv4tNoneEabi|Some("thumb-arm710t-other-eabi") Thumbv6mNoneEabi|Some("thumb-cortex_m0-other-eabi") Thumbv7aPcWindowsMsvc|Some("thumb-baseline-windows-msvc") Thumbv7emNoneEabihf|Some("thumb-cortex_m4-other-eabihf") Thumbv7emNoneEabi|Some("thumb-cortex_m4-other-eabi") Thumbv7mNoneEabi|Some("thumb-cortex_m3-other-eabi") Thumbv8mBaseNoneEabi|Some("thumb-baseline-other-eabi") Thumbv8mMainNoneEabihf|Some("thumb-cortex_m33-other-eabihf") Thumbv8mMainNoneEabi|Some("thumb-cortex_m33-other-eabi") Wasm32UnknownEmscripten|Some("wasm32-generic-emscripten-musl") Wasm32UnknownUnknown|Some("wasm32-generic-other-musl") Wasm32Wasi|Some("wasm32-generic-wasi-musl") X86_64UnknownLinuxGnux32|Some("x86_64-x86_64-linux-gnux32") 
#elif defined(THREE)
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
_Static_assert(sizeof(D) == 2, "");
_Static_assert(_Alignof(D) == 2, "");
_Static_assert(sizeof(struct D_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct D_extra_alignment) == 2, "");
_Static_assert(sizeof(struct D_extra_packed) == 2, "");
_Static_assert(_Alignof(struct D_extra_packed) == 1, "");
_Static_assert(sizeof(struct D_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct D_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct D_extra_size) == 4, "");
_Static_assert(_Alignof(struct D_extra_size) == 1, "");
_Static_assert(sizeof(E) == 2, "");
_Static_assert(_Alignof(E) == 2, "");
_Static_assert(sizeof(struct E_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct E_extra_alignment) == 2, "");
_Static_assert(sizeof(struct E_extra_packed) == 2, "");
_Static_assert(_Alignof(struct E_extra_packed) == 1, "");
_Static_assert(sizeof(struct E_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct E_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct E_extra_size) == 4, "");
_Static_assert(_Alignof(struct E_extra_size) == 1, "");
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
_Static_assert(sizeof(G) == 4, "");
_Static_assert(_Alignof(G) == 4, "");
_Static_assert(sizeof(struct G_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct G_extra_alignment) == 4, "");
_Static_assert(sizeof(struct G_extra_packed) == 4, "");
_Static_assert(_Alignof(struct G_extra_packed) == 1, "");
_Static_assert(sizeof(struct G_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct G_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct G_extra_size) == 6, "");
_Static_assert(_Alignof(struct G_extra_size) == 1, "");
_Static_assert(sizeof(H) == 4, "");
_Static_assert(_Alignof(H) == 4, "");
_Static_assert(sizeof(struct H_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct H_extra_alignment) == 4, "");
_Static_assert(sizeof(struct H_extra_packed) == 4, "");
_Static_assert(_Alignof(struct H_extra_packed) == 1, "");
_Static_assert(sizeof(struct H_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct H_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct H_extra_size) == 6, "");
_Static_assert(_Alignof(struct H_extra_size) == 1, "");
_Static_assert(sizeof(I) == 4, "");
_Static_assert(_Alignof(I) == 4, "");
_Static_assert(sizeof(struct I_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct I_extra_alignment) == 4, "");
_Static_assert(sizeof(struct I_extra_packed) == 4, "");
_Static_assert(_Alignof(struct I_extra_packed) == 1, "");
_Static_assert(sizeof(struct I_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct I_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct I_extra_size) == 6, "");
_Static_assert(_Alignof(struct I_extra_size) == 1, "");
_Static_assert(sizeof(J) == 8, "");
_Static_assert(_Alignof(J) == 8, "");
_Static_assert(sizeof(struct J_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct J_extra_alignment) == 8, "");
_Static_assert(sizeof(struct J_extra_packed) == 8, "");
_Static_assert(_Alignof(struct J_extra_packed) == 1, "");
_Static_assert(sizeof(struct J_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct J_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct J_extra_size) == 10, "");
_Static_assert(_Alignof(struct J_extra_size) == 1, "");
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
_Static_assert(sizeof(L) == 4, "");
_Static_assert(_Alignof(L) == 4, "");
_Static_assert(sizeof(struct L_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct L_extra_alignment) == 4, "");
_Static_assert(sizeof(struct L_extra_packed) == 4, "");
_Static_assert(_Alignof(struct L_extra_packed) == 1, "");
_Static_assert(sizeof(struct L_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct L_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct L_extra_size) == 6, "");
_Static_assert(_Alignof(struct L_extra_size) == 1, "");
_Static_assert(sizeof(M) == 4, "");
_Static_assert(_Alignof(M) == 4, "");
_Static_assert(sizeof(struct M_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct M_extra_alignment) == 4, "");
_Static_assert(sizeof(struct M_extra_packed) == 4, "");
_Static_assert(_Alignof(struct M_extra_packed) == 1, "");
_Static_assert(sizeof(struct M_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct M_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct M_extra_size) == 6, "");
_Static_assert(_Alignof(struct M_extra_size) == 1, "");
_Static_assert(sizeof(N) == 8, "");
_Static_assert(_Alignof(N) == 8, "");
_Static_assert(sizeof(struct N_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct N_extra_alignment) == 8, "");
_Static_assert(sizeof(struct N_extra_packed) == 8, "");
_Static_assert(_Alignof(struct N_extra_packed) == 1, "");
_Static_assert(sizeof(struct N_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct N_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct N_extra_size) == 10, "");
_Static_assert(_Alignof(struct N_extra_size) == 1, "");
// MAPPING|FOUR|arm-cortex_r4-ios-none:Clang|arm-baseline-ios-none:Clang|x86-pentium4-ios-none:Clang|x86-i586-linux-gnu:Gcc|x86-i586-linux-musl:Gcc|x86-i686-macos-none:Clang|x86-i686-linux-android:Clang|x86-i686-freebsd-gnu:Clang|x86-i686-haiku-gnu:Clang|x86-i686-linux-gnu:Gcc|x86-i686-linux-musl:Gcc|x86-i686-netbsd-gnu:Clang|x86-i686-openbsd-gnu:Clang|END
// repr targets Armv7AppleIos|Some("arm-cortex_r4-ios-none") Armv7sAppleIos|Some("arm-baseline-ios-none") I386AppleIos|Some("x86-pentium4-ios-none") I586UnknownLinuxGnu|Some("x86-i586-linux-gnu") I586UnknownLinuxMusl|Some("x86-i586-linux-musl") I686AppleMacosx|Some("x86-i686-macos-none") I686LinuxAndroid|Some("x86-i686-linux-android") I686UnknownFreebsd|Some("x86-i686-freebsd-gnu") I686UnknownHaiku|Some("x86-i686-haiku-gnu") I686UnknownLinuxGnu|Some("x86-i686-linux-gnu") I686UnknownLinuxMusl|Some("x86-i686-linux-musl") I686UnknownNetbsdelf|Some("x86-i686-netbsd-gnu") I686UnknownOpenbsd|Some("x86-i686-openbsd-gnu") 
#elif defined(FOUR)
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
_Static_assert(sizeof(D) == 2, "");
_Static_assert(_Alignof(D) == 2, "");
_Static_assert(sizeof(struct D_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct D_extra_alignment) == 2, "");
_Static_assert(sizeof(struct D_extra_packed) == 2, "");
_Static_assert(_Alignof(struct D_extra_packed) == 1, "");
_Static_assert(sizeof(struct D_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct D_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct D_extra_size) == 4, "");
_Static_assert(_Alignof(struct D_extra_size) == 1, "");
_Static_assert(sizeof(E) == 2, "");
_Static_assert(_Alignof(E) == 2, "");
_Static_assert(sizeof(struct E_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct E_extra_alignment) == 2, "");
_Static_assert(sizeof(struct E_extra_packed) == 2, "");
_Static_assert(_Alignof(struct E_extra_packed) == 1, "");
_Static_assert(sizeof(struct E_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct E_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct E_extra_size) == 4, "");
_Static_assert(_Alignof(struct E_extra_size) == 1, "");
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
_Static_assert(sizeof(G) == 4, "");
_Static_assert(_Alignof(G) == 4, "");
_Static_assert(sizeof(struct G_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct G_extra_alignment) == 4, "");
_Static_assert(sizeof(struct G_extra_packed) == 4, "");
_Static_assert(_Alignof(struct G_extra_packed) == 1, "");
_Static_assert(sizeof(struct G_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct G_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct G_extra_size) == 6, "");
_Static_assert(_Alignof(struct G_extra_size) == 1, "");
_Static_assert(sizeof(H) == 4, "");
_Static_assert(_Alignof(H) == 4, "");
_Static_assert(sizeof(struct H_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct H_extra_alignment) == 4, "");
_Static_assert(sizeof(struct H_extra_packed) == 4, "");
_Static_assert(_Alignof(struct H_extra_packed) == 1, "");
_Static_assert(sizeof(struct H_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct H_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct H_extra_size) == 6, "");
_Static_assert(_Alignof(struct H_extra_size) == 1, "");
_Static_assert(sizeof(I) == 4, "");
_Static_assert(_Alignof(I) == 4, "");
_Static_assert(sizeof(struct I_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct I_extra_alignment) == 4, "");
_Static_assert(sizeof(struct I_extra_packed) == 4, "");
_Static_assert(_Alignof(struct I_extra_packed) == 1, "");
_Static_assert(sizeof(struct I_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct I_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct I_extra_size) == 6, "");
_Static_assert(_Alignof(struct I_extra_size) == 1, "");
_Static_assert(sizeof(J) == 8, "");
_Static_assert(_Alignof(J) == 4, "");
_Static_assert(sizeof(struct J_extra_alignment) == 12, "");
_Static_assert(_Alignof(struct J_extra_alignment) == 4, "");
_Static_assert(sizeof(struct J_extra_packed) == 8, "");
_Static_assert(_Alignof(struct J_extra_packed) == 1, "");
_Static_assert(sizeof(struct J_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct J_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct J_extra_size) == 10, "");
_Static_assert(_Alignof(struct J_extra_size) == 1, "");
_Static_assert(sizeof(K) == 8, "");
_Static_assert(_Alignof(K) == 4, "");
_Static_assert(sizeof(struct K_extra_alignment) == 12, "");
_Static_assert(_Alignof(struct K_extra_alignment) == 4, "");
_Static_assert(sizeof(struct K_extra_packed) == 8, "");
_Static_assert(_Alignof(struct K_extra_packed) == 1, "");
_Static_assert(sizeof(struct K_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct K_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct K_extra_size) == 10, "");
_Static_assert(_Alignof(struct K_extra_size) == 1, "");
_Static_assert(sizeof(L) == 4, "");
_Static_assert(_Alignof(L) == 4, "");
_Static_assert(sizeof(struct L_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct L_extra_alignment) == 4, "");
_Static_assert(sizeof(struct L_extra_packed) == 4, "");
_Static_assert(_Alignof(struct L_extra_packed) == 1, "");
_Static_assert(sizeof(struct L_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct L_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct L_extra_size) == 6, "");
_Static_assert(_Alignof(struct L_extra_size) == 1, "");
_Static_assert(sizeof(M) == 4, "");
_Static_assert(_Alignof(M) == 4, "");
_Static_assert(sizeof(struct M_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct M_extra_alignment) == 4, "");
_Static_assert(sizeof(struct M_extra_packed) == 4, "");
_Static_assert(_Alignof(struct M_extra_packed) == 1, "");
_Static_assert(sizeof(struct M_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct M_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct M_extra_size) == 6, "");
_Static_assert(_Alignof(struct M_extra_size) == 1, "");
_Static_assert(sizeof(N) == 8, "");
_Static_assert(_Alignof(N) == 4, "");
_Static_assert(sizeof(struct N_extra_alignment) == 12, "");
_Static_assert(_Alignof(struct N_extra_alignment) == 4, "");
_Static_assert(sizeof(struct N_extra_packed) == 8, "");
_Static_assert(_Alignof(struct N_extra_packed) == 1, "");
_Static_assert(sizeof(struct N_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct N_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct N_extra_size) == 10, "");
_Static_assert(_Alignof(struct N_extra_size) == 1, "");
// MAPPING|FIVE|avr-avr2-other-eabi:Gcc|END
// repr targets AvrUnknownUnknown|Some("avr-avr2-other-eabi") 
#elif defined(FIVE)
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
_Static_assert(sizeof(D) == 2, "");
_Static_assert(_Alignof(D) == 1, "");
_Static_assert(sizeof(struct D_extra_alignment) == 3, "");
_Static_assert(_Alignof(struct D_extra_alignment) == 1, "");
_Static_assert(sizeof(struct D_extra_packed) == 2, "");
_Static_assert(_Alignof(struct D_extra_packed) == 1, "");
_Static_assert(sizeof(struct D_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct D_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct D_extra_size) == 4, "");
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
_Static_assert(sizeof(G) == 2, "");
_Static_assert(_Alignof(G) == 1, "");
_Static_assert(sizeof(struct G_extra_alignment) == 3, "");
_Static_assert(_Alignof(struct G_extra_alignment) == 1, "");
_Static_assert(sizeof(struct G_extra_packed) == 2, "");
_Static_assert(_Alignof(struct G_extra_packed) == 1, "");
_Static_assert(sizeof(struct G_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct G_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct G_extra_size) == 4, "");
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
_Static_assert(sizeof(I) == 4, "");
_Static_assert(_Alignof(I) == 1, "");
_Static_assert(sizeof(struct I_extra_alignment) == 5, "");
_Static_assert(_Alignof(struct I_extra_alignment) == 1, "");
_Static_assert(sizeof(struct I_extra_packed) == 4, "");
_Static_assert(_Alignof(struct I_extra_packed) == 1, "");
_Static_assert(sizeof(struct I_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct I_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct I_extra_size) == 6, "");
_Static_assert(_Alignof(struct I_extra_size) == 1, "");
_Static_assert(sizeof(J) == 8, "");
_Static_assert(_Alignof(J) == 1, "");
_Static_assert(sizeof(struct J_extra_alignment) == 9, "");
_Static_assert(_Alignof(struct J_extra_alignment) == 1, "");
_Static_assert(sizeof(struct J_extra_packed) == 8, "");
_Static_assert(_Alignof(struct J_extra_packed) == 1, "");
_Static_assert(sizeof(struct J_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct J_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct J_extra_size) == 10, "");
_Static_assert(_Alignof(struct J_extra_size) == 1, "");
_Static_assert(sizeof(K) == 8, "");
_Static_assert(_Alignof(K) == 1, "");
_Static_assert(sizeof(struct K_extra_alignment) == 9, "");
_Static_assert(_Alignof(struct K_extra_alignment) == 1, "");
_Static_assert(sizeof(struct K_extra_packed) == 8, "");
_Static_assert(_Alignof(struct K_extra_packed) == 1, "");
_Static_assert(sizeof(struct K_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct K_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct K_extra_size) == 10, "");
_Static_assert(_Alignof(struct K_extra_size) == 1, "");
_Static_assert(sizeof(L) == 2, "");
_Static_assert(_Alignof(L) == 1, "");
_Static_assert(sizeof(struct L_extra_alignment) == 3, "");
_Static_assert(_Alignof(struct L_extra_alignment) == 1, "");
_Static_assert(sizeof(struct L_extra_packed) == 2, "");
_Static_assert(_Alignof(struct L_extra_packed) == 1, "");
_Static_assert(sizeof(struct L_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct L_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct L_extra_size) == 4, "");
_Static_assert(_Alignof(struct L_extra_size) == 1, "");
_Static_assert(sizeof(M) == 4, "");
_Static_assert(_Alignof(M) == 1, "");
_Static_assert(sizeof(struct M_extra_alignment) == 5, "");
_Static_assert(_Alignof(struct M_extra_alignment) == 1, "");
_Static_assert(sizeof(struct M_extra_packed) == 4, "");
_Static_assert(_Alignof(struct M_extra_packed) == 1, "");
_Static_assert(sizeof(struct M_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct M_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct M_extra_size) == 6, "");
_Static_assert(_Alignof(struct M_extra_size) == 1, "");
_Static_assert(sizeof(N) == 4, "");
_Static_assert(_Alignof(N) == 1, "");
_Static_assert(sizeof(struct N_extra_alignment) == 5, "");
_Static_assert(_Alignof(struct N_extra_alignment) == 1, "");
_Static_assert(sizeof(struct N_extra_packed) == 4, "");
_Static_assert(_Alignof(struct N_extra_packed) == 1, "");
_Static_assert(sizeof(struct N_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct N_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct N_extra_size) == 6, "");
_Static_assert(_Alignof(struct N_extra_size) == 1, "");
// MAPPING|SIX|msp430-msp430-other-eabi:Clang|END
// repr targets Msp430NoneElf|Some("msp430-msp430-other-eabi") 
#elif defined(SIX)
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
_Static_assert(sizeof(D) == 2, "");
_Static_assert(_Alignof(D) == 2, "");
_Static_assert(sizeof(struct D_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct D_extra_alignment) == 2, "");
_Static_assert(sizeof(struct D_extra_packed) == 2, "");
_Static_assert(_Alignof(struct D_extra_packed) == 1, "");
_Static_assert(sizeof(struct D_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct D_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct D_extra_size) == 4, "");
_Static_assert(_Alignof(struct D_extra_size) == 1, "");
_Static_assert(sizeof(E) == 2, "");
_Static_assert(_Alignof(E) == 2, "");
_Static_assert(sizeof(struct E_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct E_extra_alignment) == 2, "");
_Static_assert(sizeof(struct E_extra_packed) == 2, "");
_Static_assert(_Alignof(struct E_extra_packed) == 1, "");
_Static_assert(sizeof(struct E_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct E_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct E_extra_size) == 4, "");
_Static_assert(_Alignof(struct E_extra_size) == 1, "");
_Static_assert(sizeof(F) == 2, "");
_Static_assert(_Alignof(F) == 2, "");
_Static_assert(sizeof(struct F_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct F_extra_alignment) == 2, "");
_Static_assert(sizeof(struct F_extra_packed) == 2, "");
_Static_assert(_Alignof(struct F_extra_packed) == 1, "");
_Static_assert(sizeof(struct F_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct F_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct F_extra_size) == 4, "");
_Static_assert(_Alignof(struct F_extra_size) == 1, "");
_Static_assert(sizeof(G) == 2, "");
_Static_assert(_Alignof(G) == 2, "");
_Static_assert(sizeof(struct G_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct G_extra_alignment) == 2, "");
_Static_assert(sizeof(struct G_extra_packed) == 2, "");
_Static_assert(_Alignof(struct G_extra_packed) == 1, "");
_Static_assert(sizeof(struct G_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct G_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct G_extra_size) == 4, "");
_Static_assert(_Alignof(struct G_extra_size) == 1, "");
_Static_assert(sizeof(H) == 4, "");
_Static_assert(_Alignof(H) == 2, "");
_Static_assert(sizeof(struct H_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct H_extra_alignment) == 2, "");
_Static_assert(sizeof(struct H_extra_packed) == 4, "");
_Static_assert(_Alignof(struct H_extra_packed) == 1, "");
_Static_assert(sizeof(struct H_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct H_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct H_extra_size) == 6, "");
_Static_assert(_Alignof(struct H_extra_size) == 1, "");
_Static_assert(sizeof(I) == 4, "");
_Static_assert(_Alignof(I) == 2, "");
_Static_assert(sizeof(struct I_extra_alignment) == 6, "");
_Static_assert(_Alignof(struct I_extra_alignment) == 2, "");
_Static_assert(sizeof(struct I_extra_packed) == 4, "");
_Static_assert(_Alignof(struct I_extra_packed) == 1, "");
_Static_assert(sizeof(struct I_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct I_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct I_extra_size) == 6, "");
_Static_assert(_Alignof(struct I_extra_size) == 1, "");
_Static_assert(sizeof(J) == 8, "");
_Static_assert(_Alignof(J) == 2, "");
_Static_assert(sizeof(struct J_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct J_extra_alignment) == 2, "");
_Static_assert(sizeof(struct J_extra_packed) == 8, "");
_Static_assert(_Alignof(struct J_extra_packed) == 1, "");
_Static_assert(sizeof(struct J_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct J_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct J_extra_size) == 10, "");
_Static_assert(_Alignof(struct J_extra_size) == 1, "");
_Static_assert(sizeof(K) == 8, "");
_Static_assert(_Alignof(K) == 2, "");
_Static_assert(sizeof(struct K_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct K_extra_alignment) == 2, "");
_Static_assert(sizeof(struct K_extra_packed) == 8, "");
_Static_assert(_Alignof(struct K_extra_packed) == 1, "");
_Static_assert(sizeof(struct K_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct K_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct K_extra_size) == 10, "");
_Static_assert(_Alignof(struct K_extra_size) == 1, "");
_Static_assert(sizeof(L) == 2, "");
_Static_assert(_Alignof(L) == 2, "");
_Static_assert(sizeof(struct L_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct L_extra_alignment) == 2, "");
_Static_assert(sizeof(struct L_extra_packed) == 2, "");
_Static_assert(_Alignof(struct L_extra_packed) == 1, "");
_Static_assert(sizeof(struct L_extra_required_alignment) == 3, "");
_Static_assert(_Alignof(struct L_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct L_extra_size) == 4, "");
_Static_assert(_Alignof(struct L_extra_size) == 1, "");
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
_Static_assert(sizeof(N) == 8, "");
_Static_assert(_Alignof(N) == 2, "");
_Static_assert(sizeof(struct N_extra_alignment) == 10, "");
_Static_assert(_Alignof(struct N_extra_alignment) == 2, "");
_Static_assert(sizeof(struct N_extra_packed) == 8, "");
_Static_assert(_Alignof(struct N_extra_packed) == 1, "");
_Static_assert(sizeof(struct N_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct N_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct N_extra_size) == 10, "");
_Static_assert(_Alignof(struct N_extra_size) == 1, "");
#endif
