// SPDX-License-Identifier: GPL-3.0-or-later

// This test file is auto-generated. do not edit.
// This file is a derivative work from the test files found
// in this repo : https://github.com/mahkoh/repr-c
// and is under the same licence as the original work.

typedef char A[3];
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

#ifdef MSVC
__declspec(align(4)) typedef char unnamed_type_5;
#else
typedef char unnamed_type_5 __attribute__((aligned(4)));
#endif
unnamed_type_5 var6;
struct unnamed_type_5_alignment {
#ifdef MSVC
    char a[_Alignof(unnamed_type_5)];
    char b;
#else
    char a;
    unnamed_type_5 b;
#endif
};
struct unnamed_type_5_alignment var7;
#pragma pack(1)
struct unnamed_type_5_packed {
    unnamed_type_5 a;
};
#pragma pack()
struct unnamed_type_5_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct unnamed_type_5_packed)];
    char b;
#else
    char a;
    struct unnamed_type_5_packed b;
#endif
};
struct unnamed_type_5_required_alignment var8;
struct unnamed_type_5_size {
    char a[sizeof(unnamed_type_5)+1];
    char b;
};
struct unnamed_type_5_size var9;

typedef unnamed_type_5 B[3];
B var10;
struct B_alignment {
#ifdef MSVC
    char a[_Alignof(B)];
    char b;
#else
    char a;
    B b;
#endif
};
struct B_alignment var11;
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
struct B_required_alignment var12;
struct B_size {
    char a[sizeof(B)+1];
    char b;
};
struct B_size var13;

#ifdef MSVC
__declspec(align(4)) typedef char unnamed_type_15;
#else
typedef char unnamed_type_15 __attribute__((aligned(4)));
#endif
unnamed_type_15 var16;
struct unnamed_type_15_alignment {
#ifdef MSVC
    char a[_Alignof(unnamed_type_15)];
    char b;
#else
    char a;
    unnamed_type_15 b;
#endif
};
struct unnamed_type_15_alignment var17;
#pragma pack(1)
struct unnamed_type_15_packed {
    unnamed_type_15 a;
};
#pragma pack()
struct unnamed_type_15_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct unnamed_type_15_packed)];
    char b;
#else
    char a;
    struct unnamed_type_15_packed b;
#endif
};
struct unnamed_type_15_required_alignment var18;
struct unnamed_type_15_size {
    char a[sizeof(unnamed_type_15)+1];
    char b;
};
struct unnamed_type_15_size var19;

typedef unnamed_type_15 unnamed_type_14[3];
unnamed_type_14 var20;
struct unnamed_type_14_alignment {
#ifdef MSVC
    char a[_Alignof(unnamed_type_14)];
    char b;
#else
    char a;
    unnamed_type_14 b;
#endif
};
struct unnamed_type_14_alignment var21;
#pragma pack(1)
struct unnamed_type_14_packed {
    unnamed_type_14 a;
};
#pragma pack()
struct unnamed_type_14_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct unnamed_type_14_packed)];
    char b;
#else
    char a;
    struct unnamed_type_14_packed b;
#endif
};
struct unnamed_type_14_required_alignment var22;
struct unnamed_type_14_size {
    char a[sizeof(unnamed_type_14)+1];
    char b;
};
struct unnamed_type_14_size var23;

typedef unnamed_type_14 C[3];
C var24;
struct C_alignment {
#ifdef MSVC
    char a[_Alignof(C)];
    char b;
#else
    char a;
    C b;
#endif
};
struct C_alignment var25;
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
struct C_required_alignment var26;
struct C_size {
    char a[sizeof(C)+1];
    char b;
};
struct C_size var27;

typedef short D[3];
D var28;
struct D_alignment {
#ifdef MSVC
    char a[_Alignof(D)];
    char b;
#else
    char a;
    D b;
#endif
};
struct D_alignment var29;
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
struct D_required_alignment var30;
struct D_size {
    char a[sizeof(D)+1];
    char b;
};
struct D_size var31;

#ifdef MSVC
__declspec(align(4)) typedef short unnamed_type_32;
#else
typedef short unnamed_type_32 __attribute__((aligned(4)));
#endif
unnamed_type_32 var33;
struct unnamed_type_32_alignment {
#ifdef MSVC
    char a[_Alignof(unnamed_type_32)];
    char b;
#else
    char a;
    unnamed_type_32 b;
#endif
};
struct unnamed_type_32_alignment var34;
#pragma pack(1)
struct unnamed_type_32_packed {
    unnamed_type_32 a;
};
#pragma pack()
struct unnamed_type_32_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct unnamed_type_32_packed)];
    char b;
#else
    char a;
    struct unnamed_type_32_packed b;
#endif
};
struct unnamed_type_32_required_alignment var35;
struct unnamed_type_32_size {
    char a[sizeof(unnamed_type_32)+1];
    char b;
};
struct unnamed_type_32_size var36;

typedef unnamed_type_32 E[3];
E var37;
struct E_alignment {
#ifdef MSVC
    char a[_Alignof(E)];
    char b;
#else
    char a;
    E b;
#endif
};
struct E_alignment var38;
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
struct E_required_alignment var39;
struct E_size {
    char a[sizeof(E)+1];
    char b;
};
struct E_size var40;

#ifdef MSVC
__declspec(align(4)) typedef short unnamed_type_42;
#else
typedef short unnamed_type_42 __attribute__((aligned(4)));
#endif
unnamed_type_42 var43;
struct unnamed_type_42_alignment {
#ifdef MSVC
    char a[_Alignof(unnamed_type_42)];
    char b;
#else
    char a;
    unnamed_type_42 b;
#endif
};
struct unnamed_type_42_alignment var44;
#pragma pack(1)
struct unnamed_type_42_packed {
    unnamed_type_42 a;
};
#pragma pack()
struct unnamed_type_42_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct unnamed_type_42_packed)];
    char b;
#else
    char a;
    struct unnamed_type_42_packed b;
#endif
};
struct unnamed_type_42_required_alignment var45;
struct unnamed_type_42_size {
    char a[sizeof(unnamed_type_42)+1];
    char b;
};
struct unnamed_type_42_size var46;

typedef unnamed_type_42 unnamed_type_41[3];
unnamed_type_41 var47;
struct unnamed_type_41_alignment {
#ifdef MSVC
    char a[_Alignof(unnamed_type_41)];
    char b;
#else
    char a;
    unnamed_type_41 b;
#endif
};
struct unnamed_type_41_alignment var48;
#pragma pack(1)
struct unnamed_type_41_packed {
    unnamed_type_41 a;
};
#pragma pack()
struct unnamed_type_41_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct unnamed_type_41_packed)];
    char b;
#else
    char a;
    struct unnamed_type_41_packed b;
#endif
};
struct unnamed_type_41_required_alignment var49;
struct unnamed_type_41_size {
    char a[sizeof(unnamed_type_41)+1];
    char b;
};
struct unnamed_type_41_size var50;

typedef unnamed_type_41 F[3];
F var51;
struct F_alignment {
#ifdef MSVC
    char a[_Alignof(F)];
    char b;
#else
    char a;
    F b;
#endif
};
struct F_alignment var52;
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
struct F_required_alignment var53;
struct F_size {
    char a[sizeof(F)+1];
    char b;
};
struct F_size var54;

typedef long long G[3];
G var55;
struct G_alignment {
#ifdef MSVC
    char a[_Alignof(G)];
    char b;
#else
    char a;
    G b;
#endif
};
struct G_alignment var56;
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
struct G_required_alignment var57;
struct G_size {
    char a[sizeof(G)+1];
    char b;
};
struct G_size var58;

#ifdef MSVC
__declspec(align(128)) typedef long long unnamed_type_59;
#else
typedef long long unnamed_type_59 __attribute__((aligned(128)));
#endif
unnamed_type_59 var60;
struct unnamed_type_59_alignment {
#ifdef MSVC
    char a[_Alignof(unnamed_type_59)];
    char b;
#else
    char a;
    unnamed_type_59 b;
#endif
};
struct unnamed_type_59_alignment var61;
#pragma pack(1)
struct unnamed_type_59_packed {
    unnamed_type_59 a;
};
#pragma pack()
struct unnamed_type_59_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct unnamed_type_59_packed)];
    char b;
#else
    char a;
    struct unnamed_type_59_packed b;
#endif
};
struct unnamed_type_59_required_alignment var62;
struct unnamed_type_59_size {
    char a[sizeof(unnamed_type_59)+1];
    char b;
};
struct unnamed_type_59_size var63;

typedef unnamed_type_59 H[3];
H var64;
struct H_alignment {
#ifdef MSVC
    char a[_Alignof(H)];
    char b;
#else
    char a;
    H b;
#endif
};
struct H_alignment var65;
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
struct H_required_alignment var66;
struct H_size {
    char a[sizeof(H)+1];
    char b;
};
struct H_size var67;

#ifdef MSVC
__declspec(align(128)) typedef long long unnamed_type_69;
#else
typedef long long unnamed_type_69 __attribute__((aligned(128)));
#endif
unnamed_type_69 var70;
struct unnamed_type_69_alignment {
#ifdef MSVC
    char a[_Alignof(unnamed_type_69)];
    char b;
#else
    char a;
    unnamed_type_69 b;
#endif
};
struct unnamed_type_69_alignment var71;
#pragma pack(1)
struct unnamed_type_69_packed {
    unnamed_type_69 a;
};
#pragma pack()
struct unnamed_type_69_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct unnamed_type_69_packed)];
    char b;
#else
    char a;
    struct unnamed_type_69_packed b;
#endif
};
struct unnamed_type_69_required_alignment var72;
struct unnamed_type_69_size {
    char a[sizeof(unnamed_type_69)+1];
    char b;
};
struct unnamed_type_69_size var73;

typedef unnamed_type_69 unnamed_type_68[3];
unnamed_type_68 var74;
struct unnamed_type_68_alignment {
#ifdef MSVC
    char a[_Alignof(unnamed_type_68)];
    char b;
#else
    char a;
    unnamed_type_68 b;
#endif
};
struct unnamed_type_68_alignment var75;
#pragma pack(1)
struct unnamed_type_68_packed {
    unnamed_type_68 a;
};
#pragma pack()
struct unnamed_type_68_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct unnamed_type_68_packed)];
    char b;
#else
    char a;
    struct unnamed_type_68_packed b;
#endif
};
struct unnamed_type_68_required_alignment var76;
struct unnamed_type_68_size {
    char a[sizeof(unnamed_type_68)+1];
    char b;
};
struct unnamed_type_68_size var77;

typedef unnamed_type_68 I[3];
I var78;
struct I_alignment {
#ifdef MSVC
    char a[_Alignof(I)];
    char b;
#else
    char a;
    I b;
#endif
};
struct I_alignment var79;
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
struct I_required_alignment var80;
struct I_size {
    char a[sizeof(I)+1];
    char b;
};
struct I_size var81;

#ifdef MSVC
typedef int J[];
#else
typedef int J[0];
#endif
J var82;
struct J_alignment {
#ifdef MSVC
    char a[_Alignof(J)];
    char b;
#else
    char a;
    J b;
#endif
};
struct J_alignment var83;
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
struct J_required_alignment var84;
struct J_size {
    char a[sizeof(J)+1];
    char b;
};
struct J_size var85;

// MAPPING|ONE|aarch64-generic-macos-none:Clang|aarch64-generic-fuchsia-gnu:Clang|aarch64-generic-linux-android:Clang|aarch64-generic-freebsd-gnu:Clang|aarch64-generic-hermit-eabi:Clang|aarch64-generic-netbsd-gnu:Clang|aarch64-generic-other-eabi:Clang|aarch64-generic-openbsd-gnu:Clang|aarch64-generic-ios-none:Clang|aarch64-generic-ios-macabi:Clang|aarch64-generic-tvos-none:Clang|arm-baseline-other-eabi:Clang|arm-baseline-other-eabihf:Clang|arm-arm1136j_s-freebsd-gnueabihf:Clang|arm-arm1136j_s-netbsd-eabihf:Clang|arm-baseline-other-eabi:Clang|arm-baseline-other-eabihf:Clang|arm-cortex_r4-linux-android:Clang|arm-cortex_r4-other-eabi:Clang|arm-cortex_r4-other-eabihf:Clang|arm-cortex_r4-freebsd-gnueabihf:Clang|arm-cortex_r4-netbsd-eabihf:Clang|hexagon-generic-linux-musl:Clang|mipsel-mips32-other-eabi:Clang|powerpc64-ppc64-freebsd-gnu:Clang|powerpc-ppc-netbsd-gnu:Clang|riscv32-baseline_rv32-other-eabi:Clang|riscv64-baseline_rv64-other-eabi:Clang|sparc64-v9-netbsd-gnu:Clang|sparc64-v9-openbsd-gnu:Clang|sparc-v9-solaris-eabi:Clang|thumb-arm710t-other-eabi:Clang|thumb-cortex_m0-other-eabi:Clang|thumb-cortex_m4-other-eabihf:Clang|thumb-cortex_m4-other-eabi:Clang|thumb-cortex_m3-other-eabi:Clang|thumb-baseline-other-eabi:Clang|thumb-cortex_m33-other-eabihf:Clang|thumb-cortex_m33-other-eabi:Clang|wasm32-generic-emscripten-musl:Clang|wasm32-generic-other-musl:Clang|wasm32-generic-wasi-musl:Clang|x86_64-x86_64-ios-macabi:Clang|x86_64-x86_64-ios-none:Clang|x86_64-x86_64-macos-none:Clang|x86_64-x86_64-tvos-none:Clang|x86_64-x86_64-other-eabi:Clang|x86_64-x86_64-fuchsia-gnu:Clang|x86_64-x86_64-linux-android:Clang|x86_64-x86_64-solaris-eabi:Clang|x86_64-x86_64-dragonfly-eabi:Clang|x86_64-x86_64-freebsd-gnu:Clang|x86_64-x86_64-haiku-gnu:Clang|x86_64-x86_64-hermit-eabi:Clang|x86_64-x86_64-netbsd-gnu:Clang|x86_64-x86_64-openbsd-gnu:Clang|END
// repr targets Aarch64AppleMacosx|Some("aarch64-generic-macos-none") Aarch64Fuchsia|Some("aarch64-generic-fuchsia-gnu") Aarch64LinuxAndroid|Some("aarch64-generic-linux-android") Aarch64UnknownFreebsd|Some("aarch64-generic-freebsd-gnu") Aarch64UnknownHermit|Some("aarch64-generic-hermit-eabi") Aarch64UnknownNetbsd|Some("aarch64-generic-netbsd-gnu") Aarch64UnknownNone|Some("aarch64-generic-other-eabi") Aarch64UnknownOpenbsd|Some("aarch64-generic-openbsd-gnu") Aarch64UnknownRedox|None Arm64AppleIos|Some("aarch64-generic-ios-none") Arm64AppleIosMacabi|Some("aarch64-generic-ios-macabi") Arm64AppleTvos|Some("aarch64-generic-tvos-none") Armebv7rUnknownNoneEabi|Some("arm-baseline-other-eabi") Armebv7rUnknownNoneEabihf|Some("arm-baseline-other-eabihf") ArmLinuxAndroideabi|None Armv6UnknownFreebsdGnueabihf|Some("arm-arm1136j_s-freebsd-gnueabihf") Armv6UnknownNetbsdelfEabihf|Some("arm-arm1136j_s-netbsd-eabihf") Armv7aNoneEabi|Some("arm-baseline-other-eabi") Armv7aNoneEabihf|Some("arm-baseline-other-eabihf") Armv7NoneLinuxAndroid|Some("arm-cortex_r4-linux-android") Armv7rUnknownNoneEabi|Some("arm-cortex_r4-other-eabi") Armv7rUnknownNoneEabihf|Some("arm-cortex_r4-other-eabihf") Armv7UnknownFreebsdGnueabihf|Some("arm-cortex_r4-freebsd-gnueabihf") Armv7UnknownNetbsdelfEabihf|Some("arm-cortex_r4-netbsd-eabihf") HexagonUnknownLinuxMusl|Some("hexagon-generic-linux-musl") MipselSonyPsp|None MipselUnknownNone|Some("mipsel-mips32-other-eabi") Powerpc64UnknownFreebsd|Some("powerpc64-ppc64-freebsd-gnu") PowerpcUnknownLinuxGnuspe|None PowerpcUnknownNetbsd|Some("powerpc-ppc-netbsd-gnu") Riscv32|Some("riscv32-baseline_rv32-other-eabi") Riscv64|Some("riscv64-baseline_rv64-other-eabi") Sparc64UnknownNetbsd|Some("sparc64-v9-netbsd-gnu") Sparc64UnknownOpenbsd|Some("sparc64-v9-openbsd-gnu") Sparcv9SunSolaris|Some("sparc-v9-solaris-eabi") Thumbv4tNoneEabi|Some("thumb-arm710t-other-eabi") Thumbv6mNoneEabi|Some("thumb-cortex_m0-other-eabi") Thumbv7emNoneEabihf|Some("thumb-cortex_m4-other-eabihf") Thumbv7emNoneEabi|Some("thumb-cortex_m4-other-eabi") Thumbv7mNoneEabi|Some("thumb-cortex_m3-other-eabi") Thumbv8mBaseNoneEabi|Some("thumb-baseline-other-eabi") Thumbv8mMainNoneEabihf|Some("thumb-cortex_m33-other-eabihf") Thumbv8mMainNoneEabi|Some("thumb-cortex_m33-other-eabi") Wasm32UnknownEmscripten|Some("wasm32-generic-emscripten-musl") Wasm32UnknownUnknown|Some("wasm32-generic-other-musl") Wasm32Wasi|Some("wasm32-generic-wasi-musl") X86_64AppleIosMacabi|Some("x86_64-x86_64-ios-macabi") X86_64AppleIos|Some("x86_64-x86_64-ios-none") X86_64AppleMacosx|Some("x86_64-x86_64-macos-none") X86_64AppleTvos|Some("x86_64-x86_64-tvos-none") X86_64Elf|Some("x86_64-x86_64-other-eabi") X86_64Fuchsia|Some("x86_64-x86_64-fuchsia-gnu") X86_64LinuxAndroid|Some("x86_64-x86_64-linux-android") X86_64PcSolaris|Some("x86_64-x86_64-solaris-eabi") X86_64RumprunNetbsd|None X86_64UnknownDragonfly|Some("x86_64-x86_64-dragonfly-eabi") X86_64UnknownFreebsd|Some("x86_64-x86_64-freebsd-gnu") X86_64UnknownHaiku|Some("x86_64-x86_64-haiku-gnu") X86_64UnknownHermit|Some("x86_64-x86_64-hermit-eabi") X86_64UnknownL4reUclibc|None X86_64UnknownNetbsd|Some("x86_64-x86_64-netbsd-gnu") X86_64UnknownOpenbsd|Some("x86_64-x86_64-openbsd-gnu") X86_64UnknownRedox|None 
#ifdef ONE
_Static_assert(sizeof(A) == 3, "");
_Static_assert(_Alignof(A) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 4, "");
_Static_assert(_Alignof(struct A_alignment) == 1, "");
_Static_assert(sizeof(struct A_packed) == 3, "");
_Static_assert(_Alignof(struct A_packed) == 1, "");
_Static_assert(sizeof(struct A_required_alignment) == 4, "");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "");
_Static_assert(sizeof(struct A_size) == 5, "");
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
_Static_assert(sizeof(C) == 12, "");
_Static_assert(_Alignof(C) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 16, "");
_Static_assert(_Alignof(struct C_alignment) == 4, "");
_Static_assert(sizeof(struct C_packed) == 12, "");
_Static_assert(_Alignof(struct C_packed) == 1, "");
_Static_assert(sizeof(struct C_required_alignment) == 13, "");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "");
_Static_assert(sizeof(struct C_size) == 14, "");
_Static_assert(_Alignof(struct C_size) == 1, "");
#endif
_Static_assert(sizeof(D) == 6, "");
_Static_assert(_Alignof(D) == 2, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 8, "");
_Static_assert(_Alignof(struct D_alignment) == 2, "");
_Static_assert(sizeof(struct D_packed) == 6, "");
_Static_assert(_Alignof(struct D_packed) == 1, "");
_Static_assert(sizeof(struct D_required_alignment) == 7, "");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "");
_Static_assert(sizeof(struct D_size) == 8, "");
_Static_assert(_Alignof(struct D_size) == 1, "");
#endif
_Static_assert(sizeof(E) == 8, "");
_Static_assert(_Alignof(E) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 12, "");
_Static_assert(_Alignof(struct E_alignment) == 4, "");
_Static_assert(sizeof(struct E_packed) == 8, "");
_Static_assert(_Alignof(struct E_packed) == 1, "");
_Static_assert(sizeof(struct E_required_alignment) == 9, "");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "");
_Static_assert(sizeof(struct E_size) == 10, "");
_Static_assert(_Alignof(struct E_size) == 1, "");
#endif
_Static_assert(sizeof(F) == 24, "");
_Static_assert(_Alignof(F) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 28, "");
_Static_assert(_Alignof(struct F_alignment) == 4, "");
_Static_assert(sizeof(struct F_packed) == 24, "");
_Static_assert(_Alignof(struct F_packed) == 1, "");
_Static_assert(sizeof(struct F_required_alignment) == 25, "");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "");
_Static_assert(sizeof(struct F_size) == 26, "");
_Static_assert(_Alignof(struct F_size) == 1, "");
#endif
_Static_assert(sizeof(G) == 24, "");
_Static_assert(_Alignof(G) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 32, "");
_Static_assert(_Alignof(struct G_alignment) == 8, "");
_Static_assert(sizeof(struct G_packed) == 24, "");
_Static_assert(_Alignof(struct G_packed) == 1, "");
_Static_assert(sizeof(struct G_required_alignment) == 25, "");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "");
_Static_assert(sizeof(struct G_size) == 26, "");
_Static_assert(_Alignof(struct G_size) == 1, "");
#endif
_Static_assert(sizeof(H) == 128, "");
_Static_assert(_Alignof(H) == 128, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 256, "");
_Static_assert(_Alignof(struct H_alignment) == 128, "");
_Static_assert(sizeof(struct H_packed) == 128, "");
_Static_assert(_Alignof(struct H_packed) == 1, "");
_Static_assert(sizeof(struct H_required_alignment) == 129, "");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "");
_Static_assert(sizeof(struct H_size) == 130, "");
_Static_assert(_Alignof(struct H_size) == 1, "");
#endif
_Static_assert(sizeof(I) == 384, "");
_Static_assert(_Alignof(I) == 128, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I_alignment) == 512, "");
_Static_assert(_Alignof(struct I_alignment) == 128, "");
_Static_assert(sizeof(struct I_packed) == 384, "");
_Static_assert(_Alignof(struct I_packed) == 1, "");
_Static_assert(sizeof(struct I_required_alignment) == 385, "");
_Static_assert(_Alignof(struct I_required_alignment) == 1, "");
_Static_assert(sizeof(struct I_size) == 386, "");
_Static_assert(_Alignof(struct I_size) == 1, "");
#endif
_Static_assert(sizeof(J) == 0, "");
_Static_assert(_Alignof(J) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J_alignment) == 4, "");
_Static_assert(_Alignof(struct J_alignment) == 4, "");
_Static_assert(sizeof(struct J_packed) == 0, "");
_Static_assert(_Alignof(struct J_packed) == 1, "");
_Static_assert(sizeof(struct J_required_alignment) == 1, "");
_Static_assert(_Alignof(struct J_required_alignment) == 1, "");
_Static_assert(sizeof(struct J_size) == 2, "");
_Static_assert(_Alignof(struct J_size) == 1, "");
#endif
// MAPPING|TWO|aarch64-generic-windows-msvc:Msvc|i386-i586-windows-msvc:Msvc|i386-i686-windows-msvc:Msvc|i386-i686-uefi-msvc:Msvc|thumb-baseline-windows-msvc:Msvc|x86_64-x86_64-windows-msvc:Msvc|x86_64-x86_64-uefi-msvc:Msvc|END
// repr targets Aarch64PcWindowsMsvc|Some("aarch64-generic-windows-msvc") I586PcWindowsMsvc|Some("i386-i586-windows-msvc") I686PcWindowsMsvc|Some("i386-i686-windows-msvc") I686UnknownWindows|Some("i386-i686-uefi-msvc") Thumbv7aPcWindowsMsvc|Some("thumb-baseline-windows-msvc") X86_64PcWindowsMsvc|Some("x86_64-x86_64-windows-msvc") X86_64UnknownWindows|Some("x86_64-x86_64-uefi-msvc") 
#elif defined(TWO)
_Static_assert(sizeof(A) == 3, "");
_Static_assert(_Alignof(A) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 4, "");
_Static_assert(_Alignof(struct A_alignment) == 1, "");
_Static_assert(sizeof(struct A_packed) == 3, "");
_Static_assert(_Alignof(struct A_packed) == 1, "");
_Static_assert(sizeof(struct A_required_alignment) == 4, "");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "");
_Static_assert(sizeof(struct A_size) == 5, "");
_Static_assert(_Alignof(struct A_size) == 1, "");
#endif
_Static_assert(sizeof(B) == 3, "");
_Static_assert(_Alignof(B) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 8, "");
_Static_assert(_Alignof(struct B_alignment) == 4, "");
_Static_assert(sizeof(struct B_packed) == 3, "");
_Static_assert(_Alignof(struct B_packed) == 1, "");
_Static_assert(sizeof(struct B_required_alignment) == 4, "");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "");
_Static_assert(sizeof(struct B_size) == 5, "");
_Static_assert(_Alignof(struct B_size) == 1, "");
#endif
_Static_assert(sizeof(C) == 9, "");
_Static_assert(_Alignof(C) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 16, "");
_Static_assert(_Alignof(struct C_alignment) == 4, "");
_Static_assert(sizeof(struct C_packed) == 9, "");
_Static_assert(_Alignof(struct C_packed) == 1, "");
_Static_assert(sizeof(struct C_required_alignment) == 10, "");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "");
_Static_assert(sizeof(struct C_size) == 11, "");
_Static_assert(_Alignof(struct C_size) == 1, "");
#endif
_Static_assert(sizeof(D) == 6, "");
_Static_assert(_Alignof(D) == 2, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 8, "");
_Static_assert(_Alignof(struct D_alignment) == 2, "");
_Static_assert(sizeof(struct D_packed) == 6, "");
_Static_assert(_Alignof(struct D_packed) == 1, "");
_Static_assert(sizeof(struct D_required_alignment) == 7, "");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "");
_Static_assert(sizeof(struct D_size) == 8, "");
_Static_assert(_Alignof(struct D_size) == 1, "");
#endif
_Static_assert(sizeof(E) == 6, "");
_Static_assert(_Alignof(E) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 12, "");
_Static_assert(_Alignof(struct E_alignment) == 4, "");
_Static_assert(sizeof(struct E_packed) == 6, "");
_Static_assert(_Alignof(struct E_packed) == 1, "");
_Static_assert(sizeof(struct E_required_alignment) == 7, "");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "");
_Static_assert(sizeof(struct E_size) == 8, "");
_Static_assert(_Alignof(struct E_size) == 1, "");
#endif
_Static_assert(sizeof(F) == 18, "");
_Static_assert(_Alignof(F) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 24, "");
_Static_assert(_Alignof(struct F_alignment) == 4, "");
_Static_assert(sizeof(struct F_packed) == 18, "");
_Static_assert(_Alignof(struct F_packed) == 1, "");
_Static_assert(sizeof(struct F_required_alignment) == 19, "");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "");
_Static_assert(sizeof(struct F_size) == 20, "");
_Static_assert(_Alignof(struct F_size) == 1, "");
#endif
_Static_assert(sizeof(G) == 24, "");
_Static_assert(_Alignof(G) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 32, "");
_Static_assert(_Alignof(struct G_alignment) == 8, "");
_Static_assert(sizeof(struct G_packed) == 24, "");
_Static_assert(_Alignof(struct G_packed) == 1, "");
_Static_assert(sizeof(struct G_required_alignment) == 25, "");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "");
_Static_assert(sizeof(struct G_size) == 26, "");
_Static_assert(_Alignof(struct G_size) == 1, "");
#endif
_Static_assert(sizeof(H) == 24, "");
_Static_assert(_Alignof(H) == 128, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 256, "");
_Static_assert(_Alignof(struct H_alignment) == 128, "");
_Static_assert(sizeof(struct H_packed) == 24, "");
_Static_assert(_Alignof(struct H_packed) == 1, "");
_Static_assert(sizeof(struct H_required_alignment) == 25, "");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "");
_Static_assert(sizeof(struct H_size) == 26, "");
_Static_assert(_Alignof(struct H_size) == 1, "");
#endif
_Static_assert(sizeof(I) == 72, "");
_Static_assert(_Alignof(I) == 128, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I_alignment) == 256, "");
_Static_assert(_Alignof(struct I_alignment) == 128, "");
_Static_assert(sizeof(struct I_packed) == 72, "");
_Static_assert(_Alignof(struct I_packed) == 1, "");
_Static_assert(sizeof(struct I_required_alignment) == 73, "");
_Static_assert(_Alignof(struct I_required_alignment) == 1, "");
_Static_assert(sizeof(struct I_size) == 74, "");
_Static_assert(_Alignof(struct I_size) == 1, "");
#endif
_Static_assert(sizeof(J) == 0, "");
_Static_assert(_Alignof(J) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J_alignment) == 4, "");
_Static_assert(_Alignof(struct J_alignment) == 4, "");
_Static_assert(sizeof(struct J_packed) == 0, "");
_Static_assert(_Alignof(struct J_packed) == 1, "");
_Static_assert(sizeof(struct J_required_alignment) == 1, "");
_Static_assert(_Alignof(struct J_required_alignment) == 1, "");
_Static_assert(sizeof(struct J_size) == 2, "");
_Static_assert(_Alignof(struct J_size) == 1, "");
#endif
// MAPPING|THREE|arm-cortex_r4-ios-none:Clang|arm-baseline-ios-none:Clang|i386-i386-ios-none:Clang|i386-i686-macos-none:Clang|i386-i686-linux-android:Clang|i386-i686-freebsd-gnu:Clang|i386-i686-haiku-gnu:Clang|i386-i686-netbsd-gnu:Clang|i386-i686-openbsd-gnu:Clang|END
// repr targets Armv7AppleIos|Some("arm-cortex_r4-ios-none") Armv7sAppleIos|Some("arm-baseline-ios-none") I386AppleIos|Some("i386-i386-ios-none") I686AppleMacosx|Some("i386-i686-macos-none") I686LinuxAndroid|Some("i386-i686-linux-android") I686UnknownFreebsd|Some("i386-i686-freebsd-gnu") I686UnknownHaiku|Some("i386-i686-haiku-gnu") I686UnknownNetbsdelf|Some("i386-i686-netbsd-gnu") I686UnknownOpenbsd|Some("i386-i686-openbsd-gnu") 
#elif defined(THREE)
_Static_assert(sizeof(A) == 3, "");
_Static_assert(_Alignof(A) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 4, "");
_Static_assert(_Alignof(struct A_alignment) == 1, "");
_Static_assert(sizeof(struct A_packed) == 3, "");
_Static_assert(_Alignof(struct A_packed) == 1, "");
_Static_assert(sizeof(struct A_required_alignment) == 4, "");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "");
_Static_assert(sizeof(struct A_size) == 5, "");
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
_Static_assert(sizeof(C) == 12, "");
_Static_assert(_Alignof(C) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 16, "");
_Static_assert(_Alignof(struct C_alignment) == 4, "");
_Static_assert(sizeof(struct C_packed) == 12, "");
_Static_assert(_Alignof(struct C_packed) == 1, "");
_Static_assert(sizeof(struct C_required_alignment) == 13, "");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "");
_Static_assert(sizeof(struct C_size) == 14, "");
_Static_assert(_Alignof(struct C_size) == 1, "");
#endif
_Static_assert(sizeof(D) == 6, "");
_Static_assert(_Alignof(D) == 2, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 8, "");
_Static_assert(_Alignof(struct D_alignment) == 2, "");
_Static_assert(sizeof(struct D_packed) == 6, "");
_Static_assert(_Alignof(struct D_packed) == 1, "");
_Static_assert(sizeof(struct D_required_alignment) == 7, "");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "");
_Static_assert(sizeof(struct D_size) == 8, "");
_Static_assert(_Alignof(struct D_size) == 1, "");
#endif
_Static_assert(sizeof(E) == 8, "");
_Static_assert(_Alignof(E) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 12, "");
_Static_assert(_Alignof(struct E_alignment) == 4, "");
_Static_assert(sizeof(struct E_packed) == 8, "");
_Static_assert(_Alignof(struct E_packed) == 1, "");
_Static_assert(sizeof(struct E_required_alignment) == 9, "");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "");
_Static_assert(sizeof(struct E_size) == 10, "");
_Static_assert(_Alignof(struct E_size) == 1, "");
#endif
_Static_assert(sizeof(F) == 24, "");
_Static_assert(_Alignof(F) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 28, "");
_Static_assert(_Alignof(struct F_alignment) == 4, "");
_Static_assert(sizeof(struct F_packed) == 24, "");
_Static_assert(_Alignof(struct F_packed) == 1, "");
_Static_assert(sizeof(struct F_required_alignment) == 25, "");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "");
_Static_assert(sizeof(struct F_size) == 26, "");
_Static_assert(_Alignof(struct F_size) == 1, "");
#endif
_Static_assert(sizeof(G) == 24, "");
_Static_assert(_Alignof(G) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 28, "");
_Static_assert(_Alignof(struct G_alignment) == 4, "");
_Static_assert(sizeof(struct G_packed) == 24, "");
_Static_assert(_Alignof(struct G_packed) == 1, "");
_Static_assert(sizeof(struct G_required_alignment) == 25, "");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "");
_Static_assert(sizeof(struct G_size) == 26, "");
_Static_assert(_Alignof(struct G_size) == 1, "");
#endif
_Static_assert(sizeof(H) == 128, "");
_Static_assert(_Alignof(H) == 128, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 256, "");
_Static_assert(_Alignof(struct H_alignment) == 128, "");
_Static_assert(sizeof(struct H_packed) == 128, "");
_Static_assert(_Alignof(struct H_packed) == 1, "");
_Static_assert(sizeof(struct H_required_alignment) == 129, "");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "");
_Static_assert(sizeof(struct H_size) == 130, "");
_Static_assert(_Alignof(struct H_size) == 1, "");
#endif
_Static_assert(sizeof(I) == 384, "");
_Static_assert(_Alignof(I) == 128, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I_alignment) == 512, "");
_Static_assert(_Alignof(struct I_alignment) == 128, "");
_Static_assert(sizeof(struct I_packed) == 384, "");
_Static_assert(_Alignof(struct I_packed) == 1, "");
_Static_assert(sizeof(struct I_required_alignment) == 385, "");
_Static_assert(_Alignof(struct I_required_alignment) == 1, "");
_Static_assert(sizeof(struct I_size) == 386, "");
_Static_assert(_Alignof(struct I_size) == 1, "");
#endif
_Static_assert(sizeof(J) == 0, "");
_Static_assert(_Alignof(J) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J_alignment) == 4, "");
_Static_assert(_Alignof(struct J_alignment) == 4, "");
_Static_assert(sizeof(struct J_packed) == 0, "");
_Static_assert(_Alignof(struct J_packed) == 1, "");
_Static_assert(sizeof(struct J_required_alignment) == 1, "");
_Static_assert(_Alignof(struct J_required_alignment) == 1, "");
_Static_assert(sizeof(struct J_size) == 2, "");
_Static_assert(_Alignof(struct J_size) == 1, "");
#endif
// MAPPING|FOUR|msp430-msp430-other-eabi:Clang|END
// repr targets Msp430NoneElf|Some("msp430-msp430-other-eabi") 
#elif defined(FOUR)
_Static_assert(sizeof(A) == 3, "");
_Static_assert(_Alignof(A) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 4, "");
_Static_assert(_Alignof(struct A_alignment) == 1, "");
_Static_assert(sizeof(struct A_packed) == 3, "");
_Static_assert(_Alignof(struct A_packed) == 1, "");
_Static_assert(sizeof(struct A_required_alignment) == 4, "");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "");
_Static_assert(sizeof(struct A_size) == 5, "");
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
_Static_assert(sizeof(C) == 12, "");
_Static_assert(_Alignof(C) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 16, "");
_Static_assert(_Alignof(struct C_alignment) == 4, "");
_Static_assert(sizeof(struct C_packed) == 12, "");
_Static_assert(_Alignof(struct C_packed) == 1, "");
_Static_assert(sizeof(struct C_required_alignment) == 13, "");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "");
_Static_assert(sizeof(struct C_size) == 14, "");
_Static_assert(_Alignof(struct C_size) == 1, "");
#endif
_Static_assert(sizeof(D) == 6, "");
_Static_assert(_Alignof(D) == 2, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 8, "");
_Static_assert(_Alignof(struct D_alignment) == 2, "");
_Static_assert(sizeof(struct D_packed) == 6, "");
_Static_assert(_Alignof(struct D_packed) == 1, "");
_Static_assert(sizeof(struct D_required_alignment) == 7, "");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "");
_Static_assert(sizeof(struct D_size) == 8, "");
_Static_assert(_Alignof(struct D_size) == 1, "");
#endif
_Static_assert(sizeof(E) == 8, "");
_Static_assert(_Alignof(E) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 12, "");
_Static_assert(_Alignof(struct E_alignment) == 4, "");
_Static_assert(sizeof(struct E_packed) == 8, "");
_Static_assert(_Alignof(struct E_packed) == 1, "");
_Static_assert(sizeof(struct E_required_alignment) == 9, "");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "");
_Static_assert(sizeof(struct E_size) == 10, "");
_Static_assert(_Alignof(struct E_size) == 1, "");
#endif
_Static_assert(sizeof(F) == 24, "");
_Static_assert(_Alignof(F) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 28, "");
_Static_assert(_Alignof(struct F_alignment) == 4, "");
_Static_assert(sizeof(struct F_packed) == 24, "");
_Static_assert(_Alignof(struct F_packed) == 1, "");
_Static_assert(sizeof(struct F_required_alignment) == 25, "");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "");
_Static_assert(sizeof(struct F_size) == 26, "");
_Static_assert(_Alignof(struct F_size) == 1, "");
#endif
_Static_assert(sizeof(G) == 24, "");
_Static_assert(_Alignof(G) == 2, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 26, "");
_Static_assert(_Alignof(struct G_alignment) == 2, "");
_Static_assert(sizeof(struct G_packed) == 24, "");
_Static_assert(_Alignof(struct G_packed) == 1, "");
_Static_assert(sizeof(struct G_required_alignment) == 25, "");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "");
_Static_assert(sizeof(struct G_size) == 26, "");
_Static_assert(_Alignof(struct G_size) == 1, "");
#endif
_Static_assert(sizeof(H) == 128, "");
_Static_assert(_Alignof(H) == 128, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 256, "");
_Static_assert(_Alignof(struct H_alignment) == 128, "");
_Static_assert(sizeof(struct H_packed) == 128, "");
_Static_assert(_Alignof(struct H_packed) == 1, "");
_Static_assert(sizeof(struct H_required_alignment) == 129, "");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "");
_Static_assert(sizeof(struct H_size) == 130, "");
_Static_assert(_Alignof(struct H_size) == 1, "");
#endif
_Static_assert(sizeof(I) == 384, "");
_Static_assert(_Alignof(I) == 128, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I_alignment) == 512, "");
_Static_assert(_Alignof(struct I_alignment) == 128, "");
_Static_assert(sizeof(struct I_packed) == 384, "");
_Static_assert(_Alignof(struct I_packed) == 1, "");
_Static_assert(sizeof(struct I_required_alignment) == 385, "");
_Static_assert(_Alignof(struct I_required_alignment) == 1, "");
_Static_assert(sizeof(struct I_size) == 386, "");
_Static_assert(_Alignof(struct I_size) == 1, "");
#endif
_Static_assert(sizeof(J) == 0, "");
_Static_assert(_Alignof(J) == 2, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J_alignment) == 2, "");
_Static_assert(_Alignof(struct J_alignment) == 2, "");
_Static_assert(sizeof(struct J_packed) == 0, "");
_Static_assert(_Alignof(struct J_packed) == 1, "");
_Static_assert(sizeof(struct J_required_alignment) == 1, "");
_Static_assert(_Alignof(struct J_required_alignment) == 1, "");
_Static_assert(sizeof(struct J_size) == 2, "");
_Static_assert(_Alignof(struct J_size) == 1, "");
#endif
#endif
