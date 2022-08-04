// SPDX-License-Identifier: GPL-3.0-or-later

// This test file is auto-generated. do not edit.
// This file is a derivative work from the test files found
// in this repo : https://github.com/mahkoh/repr-c
// and is under the same licence as the original work.

typedef char A;
A var1;
struct A_alignment {
#ifdef MSVC
    char a[_Alignof(A)];
    char b;
#else
    char a;
    A b;
#endif
};
struct A_alignment var2;
#pragma pack(1)
struct A_packed {
    A a;
};
#pragma pack()
struct A_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct A_packed)];
    char b;
#else
    char a;
    struct A_packed b;
#endif
};
struct A_required_alignment var3;
struct A_size {
    char a[sizeof(A)+1];
    char b;
};
struct A_size var4;

typedef unsigned char B;
B var5;
struct B_alignment {
#ifdef MSVC
    char a[_Alignof(B)];
    char b;
#else
    char a;
    B b;
#endif
};
struct B_alignment var6;
#pragma pack(1)
struct B_packed {
    B a;
};
#pragma pack()
struct B_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct B_packed)];
    char b;
#else
    char a;
    struct B_packed b;
#endif
};
struct B_required_alignment var7;
struct B_size {
    char a[sizeof(B)+1];
    char b;
};
struct B_size var8;

typedef signed char C;
C var9;
struct C_alignment {
#ifdef MSVC
    char a[_Alignof(C)];
    char b;
#else
    char a;
    C b;
#endif
};
struct C_alignment var10;
#pragma pack(1)
struct C_packed {
    C a;
};
#pragma pack()
struct C_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct C_packed)];
    char b;
#else
    char a;
    struct C_packed b;
#endif
};
struct C_required_alignment var11;
struct C_size {
    char a[sizeof(C)+1];
    char b;
};
struct C_size var12;

typedef unsigned short D;
D var13;
struct D_alignment {
#ifdef MSVC
    char a[_Alignof(D)];
    char b;
#else
    char a;
    D b;
#endif
};
struct D_alignment var14;
#pragma pack(1)
struct D_packed {
    D a;
};
#pragma pack()
struct D_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct D_packed)];
    char b;
#else
    char a;
    struct D_packed b;
#endif
};
struct D_required_alignment var15;
struct D_size {
    char a[sizeof(D)+1];
    char b;
};
struct D_size var16;

typedef short E;
E var17;
struct E_alignment {
#ifdef MSVC
    char a[_Alignof(E)];
    char b;
#else
    char a;
    E b;
#endif
};
struct E_alignment var18;
#pragma pack(1)
struct E_packed {
    E a;
};
#pragma pack()
struct E_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct E_packed)];
    char b;
#else
    char a;
    struct E_packed b;
#endif
};
struct E_required_alignment var19;
struct E_size {
    char a[sizeof(E)+1];
    char b;
};
struct E_size var20;

typedef unsigned int F;
F var21;
struct F_alignment {
#ifdef MSVC
    char a[_Alignof(F)];
    char b;
#else
    char a;
    F b;
#endif
};
struct F_alignment var22;
#pragma pack(1)
struct F_packed {
    F a;
};
#pragma pack()
struct F_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct F_packed)];
    char b;
#else
    char a;
    struct F_packed b;
#endif
};
struct F_required_alignment var23;
struct F_size {
    char a[sizeof(F)+1];
    char b;
};
struct F_size var24;

typedef int G;
G var25;
struct G_alignment {
#ifdef MSVC
    char a[_Alignof(G)];
    char b;
#else
    char a;
    G b;
#endif
};
struct G_alignment var26;
#pragma pack(1)
struct G_packed {
    G a;
};
#pragma pack()
struct G_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct G_packed)];
    char b;
#else
    char a;
    struct G_packed b;
#endif
};
struct G_required_alignment var27;
struct G_size {
    char a[sizeof(G)+1];
    char b;
};
struct G_size var28;

typedef unsigned long H;
H var29;
struct H_alignment {
#ifdef MSVC
    char a[_Alignof(H)];
    char b;
#else
    char a;
    H b;
#endif
};
struct H_alignment var30;
#pragma pack(1)
struct H_packed {
    H a;
};
#pragma pack()
struct H_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct H_packed)];
    char b;
#else
    char a;
    struct H_packed b;
#endif
};
struct H_required_alignment var31;
struct H_size {
    char a[sizeof(H)+1];
    char b;
};
struct H_size var32;

typedef long I;
I var33;
struct I_alignment {
#ifdef MSVC
    char a[_Alignof(I)];
    char b;
#else
    char a;
    I b;
#endif
};
struct I_alignment var34;
#pragma pack(1)
struct I_packed {
    I a;
};
#pragma pack()
struct I_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct I_packed)];
    char b;
#else
    char a;
    struct I_packed b;
#endif
};
struct I_required_alignment var35;
struct I_size {
    char a[sizeof(I)+1];
    char b;
};
struct I_size var36;

typedef unsigned long long J;
J var37;
struct J_alignment {
#ifdef MSVC
    char a[_Alignof(J)];
    char b;
#else
    char a;
    J b;
#endif
};
struct J_alignment var38;
#pragma pack(1)
struct J_packed {
    J a;
};
#pragma pack()
struct J_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct J_packed)];
    char b;
#else
    char a;
    struct J_packed b;
#endif
};
struct J_required_alignment var39;
struct J_size {
    char a[sizeof(J)+1];
    char b;
};
struct J_size var40;

typedef long long K;
K var41;
struct K_alignment {
#ifdef MSVC
    char a[_Alignof(K)];
    char b;
#else
    char a;
    K b;
#endif
};
struct K_alignment var42;
#pragma pack(1)
struct K_packed {
    K a;
};
#pragma pack()
struct K_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct K_packed)];
    char b;
#else
    char a;
    struct K_packed b;
#endif
};
struct K_required_alignment var43;
struct K_size {
    char a[sizeof(K)+1];
    char b;
};
struct K_size var44;

typedef void* L;
L var45;
struct L_alignment {
#ifdef MSVC
    char a[_Alignof(L)];
    char b;
#else
    char a;
    L b;
#endif
};
struct L_alignment var46;
#pragma pack(1)
struct L_packed {
    L a;
};
#pragma pack()
struct L_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct L_packed)];
    char b;
#else
    char a;
    struct L_packed b;
#endif
};
struct L_required_alignment var47;
struct L_size {
    char a[sizeof(L)+1];
    char b;
};
struct L_size var48;

typedef float M;
M var49;
struct M_alignment {
#ifdef MSVC
    char a[_Alignof(M)];
    char b;
#else
    char a;
    M b;
#endif
};
struct M_alignment var50;
#pragma pack(1)
struct M_packed {
    M a;
};
#pragma pack()
struct M_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct M_packed)];
    char b;
#else
    char a;
    struct M_packed b;
#endif
};
struct M_required_alignment var51;
struct M_size {
    char a[sizeof(M)+1];
    char b;
};
struct M_size var52;

typedef double N;
N var53;
struct N_alignment {
#ifdef MSVC
    char a[_Alignof(N)];
    char b;
#else
    char a;
    N b;
#endif
};
struct N_alignment var54;
#pragma pack(1)
struct N_packed {
    N a;
};
#pragma pack()
struct N_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct N_packed)];
    char b;
#else
    char a;
    struct N_packed b;
#endif
};
struct N_required_alignment var55;
struct N_size {
    char a[sizeof(N)+1];
    char b;
};
struct N_size var56;

// MAPPING|ONE|aarch64-generic-macos-none:Clang|aarch64-generic-fuchsia-gnu:Clang|aarch64-generic-linux-android:Clang|aarch64-generic-freebsd-gnu:Clang|aarch64-generic-hermit-eabi:Clang|aarch64-generic-linux-gnu:Gcc|aarch64-generic-linux-musl:Gcc|aarch64-generic-netbsd-gnu:Clang|aarch64-generic-other-none:Clang|aarch64-generic-openbsd-gnu:Clang|aarch64-generic-ios-none:Clang|aarch64-generic-ios-macabi:Clang|aarch64-generic-tvos-none:Clang|mips64el-mips64-linux-gnuabi64:Gcc|mips64-mips64-linux-gnuabi64:Gcc|mips-mips32-linux-gnuabi64:Gcc|mips-mips64r6-linux-gnuabi64:Gcc|powerpc64le-ppc64le-linux-gnu:Gcc|powerpc64le-ppc64le-linux-musl:Gcc|powerpc64-ppc64-freebsd-gnu:Clang|powerpc64-ppc64-linux-gnu:Gcc|powerpc64-ppc64-linux-musl:Gcc|riscv64-generic_rv64-other-none:Clang|riscv64-generic_rv64-linux-gnu:Gcc|s390x-generic-linux-gnu:Gcc|sparc64-v9-linux-gnu:Gcc|sparc64-v9-netbsd-gnu:Clang|sparc64-v9-openbsd-gnu:Clang|sparc-v9-solaris-eabi:Clang|x86_64-x86_64-ios-macabi:Clang|x86_64-x86_64-ios-none:Clang|x86_64-x86_64-macos-none:Clang|x86_64-x86_64-tvos-none:Clang|x86_64-x86_64-fuchsia-gnu:Clang|x86_64-x86_64-linux-android:Clang|x86_64-x86_64-solaris-eabi:Clang|x86_64-x86_64-dragonfly-eabi:Clang|x86_64-x86_64-freebsd-gnu:Clang|x86_64-x86_64-haiku-gnu:Clang|x86_64-x86_64-hermit-eabi:Clang|x86_64-x86_64-linux-gnu:Gcc|x86_64-x86_64-linux-musl:Gcc|x86_64-x86_64-netbsd-gnu:Clang|x86_64-x86_64-openbsd-gnu:Clang|END
// repr targets Aarch64AppleMacosx|Some("aarch64-generic-macos-none") Aarch64Fuchsia|Some("aarch64-generic-fuchsia-gnu") Aarch64LinuxAndroid|Some("aarch64-generic-linux-android") Aarch64UnknownFreebsd|Some("aarch64-generic-freebsd-gnu") Aarch64UnknownHermit|Some("aarch64-generic-hermit-eabi") Aarch64UnknownLinuxGnu|Some("aarch64-generic-linux-gnu") Aarch64UnknownLinuxMusl|Some("aarch64-generic-linux-musl") Aarch64UnknownNetbsd|Some("aarch64-generic-netbsd-gnu") Aarch64UnknownNone|Some("aarch64-generic-other-none") Aarch64UnknownOpenbsd|Some("aarch64-generic-openbsd-gnu") Aarch64UnknownRedox|None Arm64AppleIos|Some("aarch64-generic-ios-none") Arm64AppleIosMacabi|Some("aarch64-generic-ios-macabi") Arm64AppleTvos|Some("aarch64-generic-tvos-none") Mips64elUnknownLinuxGnuabi64|Some("mips64el-mips64-linux-gnuabi64") Mips64elUnknownLinuxMusl|None Mips64UnknownLinuxGnuabi64|Some("mips64-mips64-linux-gnuabi64") Mips64UnknownLinuxMusl|None Mipsisa64r6elUnknownLinuxGnuabi64|Some("mips-mips32-linux-gnuabi64") Mipsisa64r6UnknownLinuxGnuabi64|Some("mips-mips64r6-linux-gnuabi64") Powerpc64leUnknownLinuxGnu|Some("powerpc64le-ppc64le-linux-gnu") Powerpc64leUnknownLinuxMusl|Some("powerpc64le-ppc64le-linux-musl") Powerpc64UnknownFreebsd|Some("powerpc64-ppc64-freebsd-gnu") Powerpc64UnknownLinuxGnu|Some("powerpc64-ppc64-linux-gnu") Powerpc64UnknownLinuxMusl|Some("powerpc64-ppc64-linux-musl") Riscv64|Some("riscv64-generic_rv64-other-none") Riscv64UnknownLinuxGnu|Some("riscv64-generic_rv64-linux-gnu") S390xUnknownLinuxGnu|Some("s390x-generic-linux-gnu") Sparc64UnknownLinuxGnu|Some("sparc64-v9-linux-gnu") Sparc64UnknownNetbsd|Some("sparc64-v9-netbsd-gnu") Sparc64UnknownOpenbsd|Some("sparc64-v9-openbsd-gnu") Sparcv9SunSolaris|Some("sparc-v9-solaris-eabi") X86_64AppleIosMacabi|Some("x86_64-x86_64-ios-macabi") X86_64AppleIos|Some("x86_64-x86_64-ios-none") X86_64AppleMacosx|Some("x86_64-x86_64-macos-none") X86_64AppleTvos|Some("x86_64-x86_64-tvos-none") X86_64Elf|None X86_64Fuchsia|Some("x86_64-x86_64-fuchsia-gnu") X86_64LinuxAndroid|Some("x86_64-x86_64-linux-android") X86_64PcSolaris|Some("x86_64-x86_64-solaris-eabi") X86_64RumprunNetbsd|None X86_64UnknownDragonfly|Some("x86_64-x86_64-dragonfly-eabi") X86_64UnknownFreebsd|Some("x86_64-x86_64-freebsd-gnu") X86_64UnknownHaiku|Some("x86_64-x86_64-haiku-gnu") X86_64UnknownHermit|Some("x86_64-x86_64-hermit-eabi") X86_64UnknownL4reUclibc|None X86_64UnknownLinuxGnu|Some("x86_64-x86_64-linux-gnu") X86_64UnknownLinuxMusl|Some("x86_64-x86_64-linux-musl") X86_64UnknownNetbsd|Some("x86_64-x86_64-netbsd-gnu") X86_64UnknownOpenbsd|Some("x86_64-x86_64-openbsd-gnu") X86_64UnknownRedox|None 
#ifdef ONE
_Static_assert(sizeof(A) == 1, "");
_Static_assert(_Alignof(A) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 2, "");
_Static_assert(_Alignof(struct A_alignment) == 1, "");
_Static_assert(sizeof(struct A_packed) == 1, "");
_Static_assert(_Alignof(struct A_packed) == 1, "");
_Static_assert(sizeof(struct A_required_alignment) == 2, "");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "");
_Static_assert(sizeof(struct A_size) == 3, "");
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
_Static_assert(sizeof(D) == 2, "");
_Static_assert(_Alignof(D) == 2, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 4, "");
_Static_assert(_Alignof(struct D_alignment) == 2, "");
_Static_assert(sizeof(struct D_packed) == 2, "");
_Static_assert(_Alignof(struct D_packed) == 1, "");
_Static_assert(sizeof(struct D_required_alignment) == 3, "");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "");
_Static_assert(sizeof(struct D_size) == 4, "");
_Static_assert(_Alignof(struct D_size) == 1, "");
#endif
_Static_assert(sizeof(E) == 2, "");
_Static_assert(_Alignof(E) == 2, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 4, "");
_Static_assert(_Alignof(struct E_alignment) == 2, "");
_Static_assert(sizeof(struct E_packed) == 2, "");
_Static_assert(_Alignof(struct E_packed) == 1, "");
_Static_assert(sizeof(struct E_required_alignment) == 3, "");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "");
_Static_assert(sizeof(struct E_size) == 4, "");
_Static_assert(_Alignof(struct E_size) == 1, "");
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
_Static_assert(sizeof(G) == 4, "");
_Static_assert(_Alignof(G) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 8, "");
_Static_assert(_Alignof(struct G_alignment) == 4, "");
_Static_assert(sizeof(struct G_packed) == 4, "");
_Static_assert(_Alignof(struct G_packed) == 1, "");
_Static_assert(sizeof(struct G_required_alignment) == 5, "");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "");
_Static_assert(sizeof(struct G_size) == 6, "");
_Static_assert(_Alignof(struct G_size) == 1, "");
#endif
_Static_assert(sizeof(H) == 8, "");
_Static_assert(_Alignof(H) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 16, "");
_Static_assert(_Alignof(struct H_alignment) == 8, "");
_Static_assert(sizeof(struct H_packed) == 8, "");
_Static_assert(_Alignof(struct H_packed) == 1, "");
_Static_assert(sizeof(struct H_required_alignment) == 9, "");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "");
_Static_assert(sizeof(struct H_size) == 10, "");
_Static_assert(_Alignof(struct H_size) == 1, "");
#endif
_Static_assert(sizeof(I) == 8, "");
_Static_assert(_Alignof(I) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I_alignment) == 16, "");
_Static_assert(_Alignof(struct I_alignment) == 8, "");
_Static_assert(sizeof(struct I_packed) == 8, "");
_Static_assert(_Alignof(struct I_packed) == 1, "");
_Static_assert(sizeof(struct I_required_alignment) == 9, "");
_Static_assert(_Alignof(struct I_required_alignment) == 1, "");
_Static_assert(sizeof(struct I_size) == 10, "");
_Static_assert(_Alignof(struct I_size) == 1, "");
#endif
_Static_assert(sizeof(J) == 8, "");
_Static_assert(_Alignof(J) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J_alignment) == 16, "");
_Static_assert(_Alignof(struct J_alignment) == 8, "");
_Static_assert(sizeof(struct J_packed) == 8, "");
_Static_assert(_Alignof(struct J_packed) == 1, "");
_Static_assert(sizeof(struct J_required_alignment) == 9, "");
_Static_assert(_Alignof(struct J_required_alignment) == 1, "");
_Static_assert(sizeof(struct J_size) == 10, "");
_Static_assert(_Alignof(struct J_size) == 1, "");
#endif
_Static_assert(sizeof(K) == 8, "");
_Static_assert(_Alignof(K) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct K_alignment) == 16, "");
_Static_assert(_Alignof(struct K_alignment) == 8, "");
_Static_assert(sizeof(struct K_packed) == 8, "");
_Static_assert(_Alignof(struct K_packed) == 1, "");
_Static_assert(sizeof(struct K_required_alignment) == 9, "");
_Static_assert(_Alignof(struct K_required_alignment) == 1, "");
_Static_assert(sizeof(struct K_size) == 10, "");
_Static_assert(_Alignof(struct K_size) == 1, "");
#endif
_Static_assert(sizeof(L) == 8, "");
_Static_assert(_Alignof(L) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct L_alignment) == 16, "");
_Static_assert(_Alignof(struct L_alignment) == 8, "");
_Static_assert(sizeof(struct L_packed) == 8, "");
_Static_assert(_Alignof(struct L_packed) == 1, "");
_Static_assert(sizeof(struct L_required_alignment) == 9, "");
_Static_assert(_Alignof(struct L_required_alignment) == 1, "");
_Static_assert(sizeof(struct L_size) == 10, "");
_Static_assert(_Alignof(struct L_size) == 1, "");
#endif
_Static_assert(sizeof(M) == 4, "");
_Static_assert(_Alignof(M) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct M_alignment) == 8, "");
_Static_assert(_Alignof(struct M_alignment) == 4, "");
_Static_assert(sizeof(struct M_packed) == 4, "");
_Static_assert(_Alignof(struct M_packed) == 1, "");
_Static_assert(sizeof(struct M_required_alignment) == 5, "");
_Static_assert(_Alignof(struct M_required_alignment) == 1, "");
_Static_assert(sizeof(struct M_size) == 6, "");
_Static_assert(_Alignof(struct M_size) == 1, "");
#endif
_Static_assert(sizeof(N) == 8, "");
_Static_assert(_Alignof(N) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct N_alignment) == 16, "");
_Static_assert(_Alignof(struct N_alignment) == 8, "");
_Static_assert(sizeof(struct N_packed) == 8, "");
_Static_assert(_Alignof(struct N_packed) == 1, "");
_Static_assert(sizeof(struct N_required_alignment) == 9, "");
_Static_assert(_Alignof(struct N_required_alignment) == 1, "");
_Static_assert(sizeof(struct N_size) == 10, "");
_Static_assert(_Alignof(struct N_size) == 1, "");
#endif
// MAPPING|TWO|aarch64-generic-windows-msvc:Msvc|x86_64-x86_64-windows-gnu:Gcc|x86_64-x86_64-windows-msvc:Msvc|x86_64-x86_64-uefi-msvc:Msvc|END
// repr targets Aarch64PcWindowsMsvc|Some("aarch64-generic-windows-msvc") X86_64PcWindowsGnu|Some("x86_64-x86_64-windows-gnu") X86_64PcWindowsMsvc|Some("x86_64-x86_64-windows-msvc") X86_64UnknownWindows|Some("x86_64-x86_64-uefi-msvc") 
#elif defined(TWO)
_Static_assert(sizeof(A) == 1, "");
_Static_assert(_Alignof(A) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 2, "");
_Static_assert(_Alignof(struct A_alignment) == 1, "");
_Static_assert(sizeof(struct A_packed) == 1, "");
_Static_assert(_Alignof(struct A_packed) == 1, "");
_Static_assert(sizeof(struct A_required_alignment) == 2, "");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "");
_Static_assert(sizeof(struct A_size) == 3, "");
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
_Static_assert(sizeof(D) == 2, "");
_Static_assert(_Alignof(D) == 2, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 4, "");
_Static_assert(_Alignof(struct D_alignment) == 2, "");
_Static_assert(sizeof(struct D_packed) == 2, "");
_Static_assert(_Alignof(struct D_packed) == 1, "");
_Static_assert(sizeof(struct D_required_alignment) == 3, "");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "");
_Static_assert(sizeof(struct D_size) == 4, "");
_Static_assert(_Alignof(struct D_size) == 1, "");
#endif
_Static_assert(sizeof(E) == 2, "");
_Static_assert(_Alignof(E) == 2, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 4, "");
_Static_assert(_Alignof(struct E_alignment) == 2, "");
_Static_assert(sizeof(struct E_packed) == 2, "");
_Static_assert(_Alignof(struct E_packed) == 1, "");
_Static_assert(sizeof(struct E_required_alignment) == 3, "");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "");
_Static_assert(sizeof(struct E_size) == 4, "");
_Static_assert(_Alignof(struct E_size) == 1, "");
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
_Static_assert(sizeof(G) == 4, "");
_Static_assert(_Alignof(G) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 8, "");
_Static_assert(_Alignof(struct G_alignment) == 4, "");
_Static_assert(sizeof(struct G_packed) == 4, "");
_Static_assert(_Alignof(struct G_packed) == 1, "");
_Static_assert(sizeof(struct G_required_alignment) == 5, "");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "");
_Static_assert(sizeof(struct G_size) == 6, "");
_Static_assert(_Alignof(struct G_size) == 1, "");
#endif
_Static_assert(sizeof(H) == 4, "");
_Static_assert(_Alignof(H) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 8, "");
_Static_assert(_Alignof(struct H_alignment) == 4, "");
_Static_assert(sizeof(struct H_packed) == 4, "");
_Static_assert(_Alignof(struct H_packed) == 1, "");
_Static_assert(sizeof(struct H_required_alignment) == 5, "");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "");
_Static_assert(sizeof(struct H_size) == 6, "");
_Static_assert(_Alignof(struct H_size) == 1, "");
#endif
_Static_assert(sizeof(I) == 4, "");
_Static_assert(_Alignof(I) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I_alignment) == 8, "");
_Static_assert(_Alignof(struct I_alignment) == 4, "");
_Static_assert(sizeof(struct I_packed) == 4, "");
_Static_assert(_Alignof(struct I_packed) == 1, "");
_Static_assert(sizeof(struct I_required_alignment) == 5, "");
_Static_assert(_Alignof(struct I_required_alignment) == 1, "");
_Static_assert(sizeof(struct I_size) == 6, "");
_Static_assert(_Alignof(struct I_size) == 1, "");
#endif
_Static_assert(sizeof(J) == 8, "");
_Static_assert(_Alignof(J) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J_alignment) == 16, "");
_Static_assert(_Alignof(struct J_alignment) == 8, "");
_Static_assert(sizeof(struct J_packed) == 8, "");
_Static_assert(_Alignof(struct J_packed) == 1, "");
_Static_assert(sizeof(struct J_required_alignment) == 9, "");
_Static_assert(_Alignof(struct J_required_alignment) == 1, "");
_Static_assert(sizeof(struct J_size) == 10, "");
_Static_assert(_Alignof(struct J_size) == 1, "");
#endif
_Static_assert(sizeof(K) == 8, "");
_Static_assert(_Alignof(K) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct K_alignment) == 16, "");
_Static_assert(_Alignof(struct K_alignment) == 8, "");
_Static_assert(sizeof(struct K_packed) == 8, "");
_Static_assert(_Alignof(struct K_packed) == 1, "");
_Static_assert(sizeof(struct K_required_alignment) == 9, "");
_Static_assert(_Alignof(struct K_required_alignment) == 1, "");
_Static_assert(sizeof(struct K_size) == 10, "");
_Static_assert(_Alignof(struct K_size) == 1, "");
#endif
_Static_assert(sizeof(L) == 8, "");
_Static_assert(_Alignof(L) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct L_alignment) == 16, "");
_Static_assert(_Alignof(struct L_alignment) == 8, "");
_Static_assert(sizeof(struct L_packed) == 8, "");
_Static_assert(_Alignof(struct L_packed) == 1, "");
_Static_assert(sizeof(struct L_required_alignment) == 9, "");
_Static_assert(_Alignof(struct L_required_alignment) == 1, "");
_Static_assert(sizeof(struct L_size) == 10, "");
_Static_assert(_Alignof(struct L_size) == 1, "");
#endif
_Static_assert(sizeof(M) == 4, "");
_Static_assert(_Alignof(M) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct M_alignment) == 8, "");
_Static_assert(_Alignof(struct M_alignment) == 4, "");
_Static_assert(sizeof(struct M_packed) == 4, "");
_Static_assert(_Alignof(struct M_packed) == 1, "");
_Static_assert(sizeof(struct M_required_alignment) == 5, "");
_Static_assert(_Alignof(struct M_required_alignment) == 1, "");
_Static_assert(sizeof(struct M_size) == 6, "");
_Static_assert(_Alignof(struct M_size) == 1, "");
#endif
_Static_assert(sizeof(N) == 8, "");
_Static_assert(_Alignof(N) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct N_alignment) == 16, "");
_Static_assert(_Alignof(struct N_alignment) == 8, "");
_Static_assert(sizeof(struct N_packed) == 8, "");
_Static_assert(_Alignof(struct N_packed) == 1, "");
_Static_assert(sizeof(struct N_required_alignment) == 9, "");
_Static_assert(_Alignof(struct N_required_alignment) == 1, "");
_Static_assert(sizeof(struct N_size) == 10, "");
_Static_assert(_Alignof(struct N_size) == 1, "");
#endif
// MAPPING|THREE|arm-baseline-other-eabi:Clang|arm-baseline-other-eabihf:Clang|arm-baseline-linux-gnueabi:Gcc|arm-baseline-linux-gnueabihf:Gcc|arm-arm710t-linux-gnueabi:Gcc|arm-arm1020e-linux-gnueabi:Gcc|arm-arm1136j_s-freebsd-gnu:Clang|arm-arm1136j_s-netbsd-eabihf:Clang|arm-baseline-other-eabi:Clang|arm-baseline-other-eabihf:Clang|arm-cortex_r4-other-eabi:Clang|arm-cortex_r4-other-eabihf:Clang|arm-cortex_r4-freebsd-gnu:Clang|arm-cortex_r4-linux-gnueabi:Gcc|arm-cortex_r4-linux-gnueabihf:Gcc|arm-cortex_r4-netbsd-eabihf:Clang|hexagon-generic-linux-musl:Clang|i386-i586-windows-msvc:Msvc|i386-i686-windows-gnu:Gcc|i386-i686-windows-msvc:Msvc|i386-i686-uefi-msvc:Msvc|mipsel-mips32-linux-gnu:Gcc|mipsel-mips32-linux-musl:Gcc|mipsel-mips32-other-none:Clang|mips-mips32-linux-gnu:Gcc|mips-mips32r6-linux-gnu:Gcc|mips-mips32-linux-gnu:Gcc|mips-mips32-linux-musl:Gcc|powerpc-ppc-linux-gnu:Gcc|powerpc-ppc-linux-musl:Gcc|powerpc-ppc-netbsd-gnu:Clang|riscv32-generic_rv32-other-none:Clang|riscv32-generic_rv32-linux-gnu:Gcc|sparc-v8-linux-gnu:Gcc|thumb-arm710t-other-eabi:Clang|thumb-cortex_m0-other-eabi:Clang|thumb-baseline-windows-msvc:Msvc|thumb-cortex_m4-other-eabihf:Clang|thumb-cortex_m4-other-eabi:Clang|thumb-cortex_m3-other-eabi:Clang|thumb-baseline-other-eabi:Clang|thumb-cortex_m33-other-eabihf:Clang|thumb-cortex_m33-other-eabi:Clang|wasm32-generic-emscripten-musl:Clang|wasm32-generic-other-none:Clang|wasm32-generic-wasi-musl:Clang|x86_64-x86_64-linux-gnux32:Gcc|END
// repr targets Armebv7rUnknownNoneEabi|Some("arm-baseline-other-eabi") Armebv7rUnknownNoneEabihf|Some("arm-baseline-other-eabihf") ArmLinuxAndroideabi|None ArmUnknownLinuxGnueabi|Some("arm-baseline-linux-gnueabi") ArmUnknownLinuxGnueabihf|Some("arm-baseline-linux-gnueabihf") Armv4tUnknownLinuxGnueabi|Some("arm-arm710t-linux-gnueabi") Armv5teUnknownLinuxGnueabi|Some("arm-arm1020e-linux-gnueabi") Armv5teUnknownLinuxUclibcgnueabi|None Armv6UnknownFreebsdGnueabihf|Some("arm-arm1136j_s-freebsd-gnu") Armv6UnknownNetbsdelfEabihf|Some("arm-arm1136j_s-netbsd-eabihf") Armv7aNoneEabi|Some("arm-baseline-other-eabi") Armv7aNoneEabihf|Some("arm-baseline-other-eabihf") Armv7NoneLinuxAndroid|None Armv7rUnknownNoneEabi|Some("arm-cortex_r4-other-eabi") Armv7rUnknownNoneEabihf|Some("arm-cortex_r4-other-eabihf") Armv7UnknownFreebsdGnueabihf|Some("arm-cortex_r4-freebsd-gnu") Armv7UnknownLinuxGnueabi|Some("arm-cortex_r4-linux-gnueabi") Armv7UnknownLinuxGnueabihf|Some("arm-cortex_r4-linux-gnueabihf") Armv7UnknownNetbsdelfEabihf|Some("arm-cortex_r4-netbsd-eabihf") HexagonUnknownLinuxMusl|Some("hexagon-generic-linux-musl") I586PcWindowsMsvc|Some("i386-i586-windows-msvc") I686PcWindowsGnu|Some("i386-i686-windows-gnu") I686PcWindowsMsvc|Some("i386-i686-windows-msvc") I686UnknownWindows|Some("i386-i686-uefi-msvc") MipselSonyPsp|None MipselUnknownLinuxGnu|Some("mipsel-mips32-linux-gnu") MipselUnknownLinuxMusl|Some("mipsel-mips32-linux-musl") MipselUnknownLinuxUclibc|None MipselUnknownNone|Some("mipsel-mips32-other-none") Mipsisa32r6elUnknownLinuxGnu|Some("mips-mips32-linux-gnu") Mipsisa32r6UnknownLinuxGnu|Some("mips-mips32r6-linux-gnu") MipsUnknownLinuxGnu|Some("mips-mips32-linux-gnu") MipsUnknownLinuxMusl|Some("mips-mips32-linux-musl") MipsUnknownLinuxUclibc|None PowerpcUnknownLinuxGnu|Some("powerpc-ppc-linux-gnu") PowerpcUnknownLinuxGnuspe|None PowerpcUnknownLinuxMusl|Some("powerpc-ppc-linux-musl") PowerpcUnknownNetbsd|Some("powerpc-ppc-netbsd-gnu") Riscv32|Some("riscv32-generic_rv32-other-none") Riscv32UnknownLinuxGnu|Some("riscv32-generic_rv32-linux-gnu") SparcUnknownLinuxGnu|Some("sparc-v8-linux-gnu") Thumbv4tNoneEabi|Some("thumb-arm710t-other-eabi") Thumbv6mNoneEabi|Some("thumb-cortex_m0-other-eabi") Thumbv7aPcWindowsMsvc|Some("thumb-baseline-windows-msvc") Thumbv7emNoneEabihf|Some("thumb-cortex_m4-other-eabihf") Thumbv7emNoneEabi|Some("thumb-cortex_m4-other-eabi") Thumbv7mNoneEabi|Some("thumb-cortex_m3-other-eabi") Thumbv8mBaseNoneEabi|Some("thumb-baseline-other-eabi") Thumbv8mMainNoneEabihf|Some("thumb-cortex_m33-other-eabihf") Thumbv8mMainNoneEabi|Some("thumb-cortex_m33-other-eabi") Wasm32UnknownEmscripten|Some("wasm32-generic-emscripten-musl") Wasm32UnknownUnknown|Some("wasm32-generic-other-none") Wasm32Wasi|Some("wasm32-generic-wasi-musl") X86_64UnknownLinuxGnux32|Some("x86_64-x86_64-linux-gnux32") 
#elif defined(THREE)
_Static_assert(sizeof(A) == 1, "");
_Static_assert(_Alignof(A) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 2, "");
_Static_assert(_Alignof(struct A_alignment) == 1, "");
_Static_assert(sizeof(struct A_packed) == 1, "");
_Static_assert(_Alignof(struct A_packed) == 1, "");
_Static_assert(sizeof(struct A_required_alignment) == 2, "");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "");
_Static_assert(sizeof(struct A_size) == 3, "");
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
_Static_assert(sizeof(D) == 2, "");
_Static_assert(_Alignof(D) == 2, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 4, "");
_Static_assert(_Alignof(struct D_alignment) == 2, "");
_Static_assert(sizeof(struct D_packed) == 2, "");
_Static_assert(_Alignof(struct D_packed) == 1, "");
_Static_assert(sizeof(struct D_required_alignment) == 3, "");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "");
_Static_assert(sizeof(struct D_size) == 4, "");
_Static_assert(_Alignof(struct D_size) == 1, "");
#endif
_Static_assert(sizeof(E) == 2, "");
_Static_assert(_Alignof(E) == 2, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 4, "");
_Static_assert(_Alignof(struct E_alignment) == 2, "");
_Static_assert(sizeof(struct E_packed) == 2, "");
_Static_assert(_Alignof(struct E_packed) == 1, "");
_Static_assert(sizeof(struct E_required_alignment) == 3, "");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "");
_Static_assert(sizeof(struct E_size) == 4, "");
_Static_assert(_Alignof(struct E_size) == 1, "");
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
_Static_assert(sizeof(G) == 4, "");
_Static_assert(_Alignof(G) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 8, "");
_Static_assert(_Alignof(struct G_alignment) == 4, "");
_Static_assert(sizeof(struct G_packed) == 4, "");
_Static_assert(_Alignof(struct G_packed) == 1, "");
_Static_assert(sizeof(struct G_required_alignment) == 5, "");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "");
_Static_assert(sizeof(struct G_size) == 6, "");
_Static_assert(_Alignof(struct G_size) == 1, "");
#endif
_Static_assert(sizeof(H) == 4, "");
_Static_assert(_Alignof(H) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 8, "");
_Static_assert(_Alignof(struct H_alignment) == 4, "");
_Static_assert(sizeof(struct H_packed) == 4, "");
_Static_assert(_Alignof(struct H_packed) == 1, "");
_Static_assert(sizeof(struct H_required_alignment) == 5, "");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "");
_Static_assert(sizeof(struct H_size) == 6, "");
_Static_assert(_Alignof(struct H_size) == 1, "");
#endif
_Static_assert(sizeof(I) == 4, "");
_Static_assert(_Alignof(I) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I_alignment) == 8, "");
_Static_assert(_Alignof(struct I_alignment) == 4, "");
_Static_assert(sizeof(struct I_packed) == 4, "");
_Static_assert(_Alignof(struct I_packed) == 1, "");
_Static_assert(sizeof(struct I_required_alignment) == 5, "");
_Static_assert(_Alignof(struct I_required_alignment) == 1, "");
_Static_assert(sizeof(struct I_size) == 6, "");
_Static_assert(_Alignof(struct I_size) == 1, "");
#endif
_Static_assert(sizeof(J) == 8, "");
_Static_assert(_Alignof(J) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J_alignment) == 16, "");
_Static_assert(_Alignof(struct J_alignment) == 8, "");
_Static_assert(sizeof(struct J_packed) == 8, "");
_Static_assert(_Alignof(struct J_packed) == 1, "");
_Static_assert(sizeof(struct J_required_alignment) == 9, "");
_Static_assert(_Alignof(struct J_required_alignment) == 1, "");
_Static_assert(sizeof(struct J_size) == 10, "");
_Static_assert(_Alignof(struct J_size) == 1, "");
#endif
_Static_assert(sizeof(K) == 8, "");
_Static_assert(_Alignof(K) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct K_alignment) == 16, "");
_Static_assert(_Alignof(struct K_alignment) == 8, "");
_Static_assert(sizeof(struct K_packed) == 8, "");
_Static_assert(_Alignof(struct K_packed) == 1, "");
_Static_assert(sizeof(struct K_required_alignment) == 9, "");
_Static_assert(_Alignof(struct K_required_alignment) == 1, "");
_Static_assert(sizeof(struct K_size) == 10, "");
_Static_assert(_Alignof(struct K_size) == 1, "");
#endif
_Static_assert(sizeof(L) == 4, "");
_Static_assert(_Alignof(L) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct L_alignment) == 8, "");
_Static_assert(_Alignof(struct L_alignment) == 4, "");
_Static_assert(sizeof(struct L_packed) == 4, "");
_Static_assert(_Alignof(struct L_packed) == 1, "");
_Static_assert(sizeof(struct L_required_alignment) == 5, "");
_Static_assert(_Alignof(struct L_required_alignment) == 1, "");
_Static_assert(sizeof(struct L_size) == 6, "");
_Static_assert(_Alignof(struct L_size) == 1, "");
#endif
_Static_assert(sizeof(M) == 4, "");
_Static_assert(_Alignof(M) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct M_alignment) == 8, "");
_Static_assert(_Alignof(struct M_alignment) == 4, "");
_Static_assert(sizeof(struct M_packed) == 4, "");
_Static_assert(_Alignof(struct M_packed) == 1, "");
_Static_assert(sizeof(struct M_required_alignment) == 5, "");
_Static_assert(_Alignof(struct M_required_alignment) == 1, "");
_Static_assert(sizeof(struct M_size) == 6, "");
_Static_assert(_Alignof(struct M_size) == 1, "");
#endif
_Static_assert(sizeof(N) == 8, "");
_Static_assert(_Alignof(N) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct N_alignment) == 16, "");
_Static_assert(_Alignof(struct N_alignment) == 8, "");
_Static_assert(sizeof(struct N_packed) == 8, "");
_Static_assert(_Alignof(struct N_packed) == 1, "");
_Static_assert(sizeof(struct N_required_alignment) == 9, "");
_Static_assert(_Alignof(struct N_required_alignment) == 1, "");
_Static_assert(sizeof(struct N_size) == 10, "");
_Static_assert(_Alignof(struct N_size) == 1, "");
#endif
// MAPPING|FOUR|arm-cortex_r4-ios-none:Clang|arm-baseline-ios-none:Clang|i386-i386-ios-none:Clang|i386-i586-linux-gnu:Gcc|i386-i586-linux-musl:Gcc|x86_64-i686-macos-none:Clang|i386-i686-linux-android:Clang|i386-i686-freebsd-gnu:Clang|i386-i686-haiku-gnu:Clang|i386-i686-linux-gnu:Gcc|i386-i686-linux-musl:Gcc|i386-i686-netbsd-gnu:Clang|i386-i686-openbsd-gnu:Clang|END
// repr targets Armv7AppleIos|Some("arm-cortex_r4-ios-none") Armv7sAppleIos|Some("arm-baseline-ios-none") I386AppleIos|Some("i386-i386-ios-none") I586UnknownLinuxGnu|Some("i386-i586-linux-gnu") I586UnknownLinuxMusl|Some("i386-i586-linux-musl") I686AppleMacosx|Some("x86_64-i686-macos-none") I686LinuxAndroid|Some("i386-i686-linux-android") I686UnknownFreebsd|Some("i386-i686-freebsd-gnu") I686UnknownHaiku|Some("i386-i686-haiku-gnu") I686UnknownLinuxGnu|Some("i386-i686-linux-gnu") I686UnknownLinuxMusl|Some("i386-i686-linux-musl") I686UnknownNetbsdelf|Some("i386-i686-netbsd-gnu") I686UnknownOpenbsd|Some("i386-i686-openbsd-gnu") 
#elif defined(FOUR)
_Static_assert(sizeof(A) == 1, "");
_Static_assert(_Alignof(A) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 2, "");
_Static_assert(_Alignof(struct A_alignment) == 1, "");
_Static_assert(sizeof(struct A_packed) == 1, "");
_Static_assert(_Alignof(struct A_packed) == 1, "");
_Static_assert(sizeof(struct A_required_alignment) == 2, "");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "");
_Static_assert(sizeof(struct A_size) == 3, "");
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
_Static_assert(sizeof(D) == 2, "");
_Static_assert(_Alignof(D) == 2, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 4, "");
_Static_assert(_Alignof(struct D_alignment) == 2, "");
_Static_assert(sizeof(struct D_packed) == 2, "");
_Static_assert(_Alignof(struct D_packed) == 1, "");
_Static_assert(sizeof(struct D_required_alignment) == 3, "");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "");
_Static_assert(sizeof(struct D_size) == 4, "");
_Static_assert(_Alignof(struct D_size) == 1, "");
#endif
_Static_assert(sizeof(E) == 2, "");
_Static_assert(_Alignof(E) == 2, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 4, "");
_Static_assert(_Alignof(struct E_alignment) == 2, "");
_Static_assert(sizeof(struct E_packed) == 2, "");
_Static_assert(_Alignof(struct E_packed) == 1, "");
_Static_assert(sizeof(struct E_required_alignment) == 3, "");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "");
_Static_assert(sizeof(struct E_size) == 4, "");
_Static_assert(_Alignof(struct E_size) == 1, "");
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
_Static_assert(sizeof(G) == 4, "");
_Static_assert(_Alignof(G) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 8, "");
_Static_assert(_Alignof(struct G_alignment) == 4, "");
_Static_assert(sizeof(struct G_packed) == 4, "");
_Static_assert(_Alignof(struct G_packed) == 1, "");
_Static_assert(sizeof(struct G_required_alignment) == 5, "");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "");
_Static_assert(sizeof(struct G_size) == 6, "");
_Static_assert(_Alignof(struct G_size) == 1, "");
#endif
_Static_assert(sizeof(H) == 4, "");
_Static_assert(_Alignof(H) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 8, "");
_Static_assert(_Alignof(struct H_alignment) == 4, "");
_Static_assert(sizeof(struct H_packed) == 4, "");
_Static_assert(_Alignof(struct H_packed) == 1, "");
_Static_assert(sizeof(struct H_required_alignment) == 5, "");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "");
_Static_assert(sizeof(struct H_size) == 6, "");
_Static_assert(_Alignof(struct H_size) == 1, "");
#endif
_Static_assert(sizeof(I) == 4, "");
_Static_assert(_Alignof(I) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I_alignment) == 8, "");
_Static_assert(_Alignof(struct I_alignment) == 4, "");
_Static_assert(sizeof(struct I_packed) == 4, "");
_Static_assert(_Alignof(struct I_packed) == 1, "");
_Static_assert(sizeof(struct I_required_alignment) == 5, "");
_Static_assert(_Alignof(struct I_required_alignment) == 1, "");
_Static_assert(sizeof(struct I_size) == 6, "");
_Static_assert(_Alignof(struct I_size) == 1, "");
#endif
_Static_assert(sizeof(J) == 8, "");
_Static_assert(_Alignof(J) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J_alignment) == 12, "");
_Static_assert(_Alignof(struct J_alignment) == 4, "");
_Static_assert(sizeof(struct J_packed) == 8, "");
_Static_assert(_Alignof(struct J_packed) == 1, "");
_Static_assert(sizeof(struct J_required_alignment) == 9, "");
_Static_assert(_Alignof(struct J_required_alignment) == 1, "");
_Static_assert(sizeof(struct J_size) == 10, "");
_Static_assert(_Alignof(struct J_size) == 1, "");
#endif
_Static_assert(sizeof(K) == 8, "");
_Static_assert(_Alignof(K) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct K_alignment) == 12, "");
_Static_assert(_Alignof(struct K_alignment) == 4, "");
_Static_assert(sizeof(struct K_packed) == 8, "");
_Static_assert(_Alignof(struct K_packed) == 1, "");
_Static_assert(sizeof(struct K_required_alignment) == 9, "");
_Static_assert(_Alignof(struct K_required_alignment) == 1, "");
_Static_assert(sizeof(struct K_size) == 10, "");
_Static_assert(_Alignof(struct K_size) == 1, "");
#endif
_Static_assert(sizeof(L) == 4, "");
_Static_assert(_Alignof(L) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct L_alignment) == 8, "");
_Static_assert(_Alignof(struct L_alignment) == 4, "");
_Static_assert(sizeof(struct L_packed) == 4, "");
_Static_assert(_Alignof(struct L_packed) == 1, "");
_Static_assert(sizeof(struct L_required_alignment) == 5, "");
_Static_assert(_Alignof(struct L_required_alignment) == 1, "");
_Static_assert(sizeof(struct L_size) == 6, "");
_Static_assert(_Alignof(struct L_size) == 1, "");
#endif
_Static_assert(sizeof(M) == 4, "");
_Static_assert(_Alignof(M) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct M_alignment) == 8, "");
_Static_assert(_Alignof(struct M_alignment) == 4, "");
_Static_assert(sizeof(struct M_packed) == 4, "");
_Static_assert(_Alignof(struct M_packed) == 1, "");
_Static_assert(sizeof(struct M_required_alignment) == 5, "");
_Static_assert(_Alignof(struct M_required_alignment) == 1, "");
_Static_assert(sizeof(struct M_size) == 6, "");
_Static_assert(_Alignof(struct M_size) == 1, "");
#endif
_Static_assert(sizeof(N) == 8, "");
_Static_assert(_Alignof(N) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct N_alignment) == 12, "");
_Static_assert(_Alignof(struct N_alignment) == 4, "");
_Static_assert(sizeof(struct N_packed) == 8, "");
_Static_assert(_Alignof(struct N_packed) == 1, "");
_Static_assert(sizeof(struct N_required_alignment) == 9, "");
_Static_assert(_Alignof(struct N_required_alignment) == 1, "");
_Static_assert(sizeof(struct N_size) == 10, "");
_Static_assert(_Alignof(struct N_size) == 1, "");
#endif
// MAPPING|FIVE|avr-atmega328-other-gnu:Gcc|END
// repr targets AvrUnknownUnknown|Some("avr-atmega328-other-gnu") 
#elif defined(FIVE)
_Static_assert(sizeof(A) == 1, "");
_Static_assert(_Alignof(A) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 2, "");
_Static_assert(_Alignof(struct A_alignment) == 1, "");
_Static_assert(sizeof(struct A_packed) == 1, "");
_Static_assert(_Alignof(struct A_packed) == 1, "");
_Static_assert(sizeof(struct A_required_alignment) == 2, "");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "");
_Static_assert(sizeof(struct A_size) == 3, "");
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
_Static_assert(sizeof(D) == 2, "");
_Static_assert(_Alignof(D) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 3, "");
_Static_assert(_Alignof(struct D_alignment) == 1, "");
_Static_assert(sizeof(struct D_packed) == 2, "");
_Static_assert(_Alignof(struct D_packed) == 1, "");
_Static_assert(sizeof(struct D_required_alignment) == 3, "");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "");
_Static_assert(sizeof(struct D_size) == 4, "");
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
_Static_assert(sizeof(G) == 2, "");
_Static_assert(_Alignof(G) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 3, "");
_Static_assert(_Alignof(struct G_alignment) == 1, "");
_Static_assert(sizeof(struct G_packed) == 2, "");
_Static_assert(_Alignof(struct G_packed) == 1, "");
_Static_assert(sizeof(struct G_required_alignment) == 3, "");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "");
_Static_assert(sizeof(struct G_size) == 4, "");
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
_Static_assert(sizeof(I) == 4, "");
_Static_assert(_Alignof(I) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I_alignment) == 5, "");
_Static_assert(_Alignof(struct I_alignment) == 1, "");
_Static_assert(sizeof(struct I_packed) == 4, "");
_Static_assert(_Alignof(struct I_packed) == 1, "");
_Static_assert(sizeof(struct I_required_alignment) == 5, "");
_Static_assert(_Alignof(struct I_required_alignment) == 1, "");
_Static_assert(sizeof(struct I_size) == 6, "");
_Static_assert(_Alignof(struct I_size) == 1, "");
#endif
_Static_assert(sizeof(J) == 8, "");
_Static_assert(_Alignof(J) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J_alignment) == 9, "");
_Static_assert(_Alignof(struct J_alignment) == 1, "");
_Static_assert(sizeof(struct J_packed) == 8, "");
_Static_assert(_Alignof(struct J_packed) == 1, "");
_Static_assert(sizeof(struct J_required_alignment) == 9, "");
_Static_assert(_Alignof(struct J_required_alignment) == 1, "");
_Static_assert(sizeof(struct J_size) == 10, "");
_Static_assert(_Alignof(struct J_size) == 1, "");
#endif
_Static_assert(sizeof(K) == 8, "");
_Static_assert(_Alignof(K) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct K_alignment) == 9, "");
_Static_assert(_Alignof(struct K_alignment) == 1, "");
_Static_assert(sizeof(struct K_packed) == 8, "");
_Static_assert(_Alignof(struct K_packed) == 1, "");
_Static_assert(sizeof(struct K_required_alignment) == 9, "");
_Static_assert(_Alignof(struct K_required_alignment) == 1, "");
_Static_assert(sizeof(struct K_size) == 10, "");
_Static_assert(_Alignof(struct K_size) == 1, "");
#endif
_Static_assert(sizeof(L) == 2, "");
_Static_assert(_Alignof(L) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct L_alignment) == 3, "");
_Static_assert(_Alignof(struct L_alignment) == 1, "");
_Static_assert(sizeof(struct L_packed) == 2, "");
_Static_assert(_Alignof(struct L_packed) == 1, "");
_Static_assert(sizeof(struct L_required_alignment) == 3, "");
_Static_assert(_Alignof(struct L_required_alignment) == 1, "");
_Static_assert(sizeof(struct L_size) == 4, "");
_Static_assert(_Alignof(struct L_size) == 1, "");
#endif
_Static_assert(sizeof(M) == 4, "");
_Static_assert(_Alignof(M) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct M_alignment) == 5, "");
_Static_assert(_Alignof(struct M_alignment) == 1, "");
_Static_assert(sizeof(struct M_packed) == 4, "");
_Static_assert(_Alignof(struct M_packed) == 1, "");
_Static_assert(sizeof(struct M_required_alignment) == 5, "");
_Static_assert(_Alignof(struct M_required_alignment) == 1, "");
_Static_assert(sizeof(struct M_size) == 6, "");
_Static_assert(_Alignof(struct M_size) == 1, "");
#endif
_Static_assert(sizeof(N) == 4, "");
_Static_assert(_Alignof(N) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct N_alignment) == 5, "");
_Static_assert(_Alignof(struct N_alignment) == 1, "");
_Static_assert(sizeof(struct N_packed) == 4, "");
_Static_assert(_Alignof(struct N_packed) == 1, "");
_Static_assert(sizeof(struct N_required_alignment) == 5, "");
_Static_assert(_Alignof(struct N_required_alignment) == 1, "");
_Static_assert(sizeof(struct N_size) == 6, "");
_Static_assert(_Alignof(struct N_size) == 1, "");
#endif
// MAPPING|SIX|msp430-msp430-other-none:Clang|END
// repr targets Msp430NoneElf|Some("msp430-msp430-other-none") 
#elif defined(SIX)
_Static_assert(sizeof(A) == 1, "");
_Static_assert(_Alignof(A) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 2, "");
_Static_assert(_Alignof(struct A_alignment) == 1, "");
_Static_assert(sizeof(struct A_packed) == 1, "");
_Static_assert(_Alignof(struct A_packed) == 1, "");
_Static_assert(sizeof(struct A_required_alignment) == 2, "");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "");
_Static_assert(sizeof(struct A_size) == 3, "");
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
_Static_assert(sizeof(D) == 2, "");
_Static_assert(_Alignof(D) == 2, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 4, "");
_Static_assert(_Alignof(struct D_alignment) == 2, "");
_Static_assert(sizeof(struct D_packed) == 2, "");
_Static_assert(_Alignof(struct D_packed) == 1, "");
_Static_assert(sizeof(struct D_required_alignment) == 3, "");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "");
_Static_assert(sizeof(struct D_size) == 4, "");
_Static_assert(_Alignof(struct D_size) == 1, "");
#endif
_Static_assert(sizeof(E) == 2, "");
_Static_assert(_Alignof(E) == 2, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 4, "");
_Static_assert(_Alignof(struct E_alignment) == 2, "");
_Static_assert(sizeof(struct E_packed) == 2, "");
_Static_assert(_Alignof(struct E_packed) == 1, "");
_Static_assert(sizeof(struct E_required_alignment) == 3, "");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "");
_Static_assert(sizeof(struct E_size) == 4, "");
_Static_assert(_Alignof(struct E_size) == 1, "");
#endif
_Static_assert(sizeof(F) == 2, "");
_Static_assert(_Alignof(F) == 2, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 4, "");
_Static_assert(_Alignof(struct F_alignment) == 2, "");
_Static_assert(sizeof(struct F_packed) == 2, "");
_Static_assert(_Alignof(struct F_packed) == 1, "");
_Static_assert(sizeof(struct F_required_alignment) == 3, "");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "");
_Static_assert(sizeof(struct F_size) == 4, "");
_Static_assert(_Alignof(struct F_size) == 1, "");
#endif
_Static_assert(sizeof(G) == 2, "");
_Static_assert(_Alignof(G) == 2, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 4, "");
_Static_assert(_Alignof(struct G_alignment) == 2, "");
_Static_assert(sizeof(struct G_packed) == 2, "");
_Static_assert(_Alignof(struct G_packed) == 1, "");
_Static_assert(sizeof(struct G_required_alignment) == 3, "");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "");
_Static_assert(sizeof(struct G_size) == 4, "");
_Static_assert(_Alignof(struct G_size) == 1, "");
#endif
_Static_assert(sizeof(H) == 4, "");
_Static_assert(_Alignof(H) == 2, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 6, "");
_Static_assert(_Alignof(struct H_alignment) == 2, "");
_Static_assert(sizeof(struct H_packed) == 4, "");
_Static_assert(_Alignof(struct H_packed) == 1, "");
_Static_assert(sizeof(struct H_required_alignment) == 5, "");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "");
_Static_assert(sizeof(struct H_size) == 6, "");
_Static_assert(_Alignof(struct H_size) == 1, "");
#endif
_Static_assert(sizeof(I) == 4, "");
_Static_assert(_Alignof(I) == 2, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I_alignment) == 6, "");
_Static_assert(_Alignof(struct I_alignment) == 2, "");
_Static_assert(sizeof(struct I_packed) == 4, "");
_Static_assert(_Alignof(struct I_packed) == 1, "");
_Static_assert(sizeof(struct I_required_alignment) == 5, "");
_Static_assert(_Alignof(struct I_required_alignment) == 1, "");
_Static_assert(sizeof(struct I_size) == 6, "");
_Static_assert(_Alignof(struct I_size) == 1, "");
#endif
_Static_assert(sizeof(J) == 8, "");
_Static_assert(_Alignof(J) == 2, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J_alignment) == 10, "");
_Static_assert(_Alignof(struct J_alignment) == 2, "");
_Static_assert(sizeof(struct J_packed) == 8, "");
_Static_assert(_Alignof(struct J_packed) == 1, "");
_Static_assert(sizeof(struct J_required_alignment) == 9, "");
_Static_assert(_Alignof(struct J_required_alignment) == 1, "");
_Static_assert(sizeof(struct J_size) == 10, "");
_Static_assert(_Alignof(struct J_size) == 1, "");
#endif
_Static_assert(sizeof(K) == 8, "");
_Static_assert(_Alignof(K) == 2, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct K_alignment) == 10, "");
_Static_assert(_Alignof(struct K_alignment) == 2, "");
_Static_assert(sizeof(struct K_packed) == 8, "");
_Static_assert(_Alignof(struct K_packed) == 1, "");
_Static_assert(sizeof(struct K_required_alignment) == 9, "");
_Static_assert(_Alignof(struct K_required_alignment) == 1, "");
_Static_assert(sizeof(struct K_size) == 10, "");
_Static_assert(_Alignof(struct K_size) == 1, "");
#endif
_Static_assert(sizeof(L) == 2, "");
_Static_assert(_Alignof(L) == 2, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct L_alignment) == 4, "");
_Static_assert(_Alignof(struct L_alignment) == 2, "");
_Static_assert(sizeof(struct L_packed) == 2, "");
_Static_assert(_Alignof(struct L_packed) == 1, "");
_Static_assert(sizeof(struct L_required_alignment) == 3, "");
_Static_assert(_Alignof(struct L_required_alignment) == 1, "");
_Static_assert(sizeof(struct L_size) == 4, "");
_Static_assert(_Alignof(struct L_size) == 1, "");
#endif
_Static_assert(sizeof(M) == 4, "");
_Static_assert(_Alignof(M) == 2, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct M_alignment) == 6, "");
_Static_assert(_Alignof(struct M_alignment) == 2, "");
_Static_assert(sizeof(struct M_packed) == 4, "");
_Static_assert(_Alignof(struct M_packed) == 1, "");
_Static_assert(sizeof(struct M_required_alignment) == 5, "");
_Static_assert(_Alignof(struct M_required_alignment) == 1, "");
_Static_assert(sizeof(struct M_size) == 6, "");
_Static_assert(_Alignof(struct M_size) == 1, "");
#endif
_Static_assert(sizeof(N) == 8, "");
_Static_assert(_Alignof(N) == 2, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct N_alignment) == 10, "");
_Static_assert(_Alignof(struct N_alignment) == 2, "");
_Static_assert(sizeof(struct N_packed) == 8, "");
_Static_assert(_Alignof(struct N_packed) == 1, "");
_Static_assert(sizeof(struct N_required_alignment) == 9, "");
_Static_assert(_Alignof(struct N_required_alignment) == 1, "");
_Static_assert(sizeof(struct N_size) == 10, "");
_Static_assert(_Alignof(struct N_size) == 1, "");
#endif
#endif
