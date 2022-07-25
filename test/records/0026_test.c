// SPDX-License-Identifier: GPL-3.0-or-later

// This test file is auto-generated. do not edit.
// This file is a derivative work from the test files found// in this repo : https://github.com/mahkoh/repr-c
// and is under the same licence as the original work.

#pragma pack(2)
typedef struct {
#ifdef MSVC
    __declspec(align(4)) char:1;
#else
    char:1 __attribute__((aligned(4)));
#endif
} A;
A var1;
#pragma pack()
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
typedef A unnamed_type_5[];
#else
typedef A unnamed_type_5[0];
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

typedef struct {
    unnamed_type_5 a;
} B;
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
__declspec(align(2)) typedef char C;
#else
typedef char C __attribute__((aligned(2)));
#endif
C var14;
struct C_alignment {
#ifdef MSVC
    char a[_Alignof(C)];
    char b;
#else
    char a;
    C b;
#endif
};
struct C_alignment var15;
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
struct C_required_alignment var16;
struct C_size {
    char a[sizeof(C)+1];
    char b;
};
struct C_size var17;

#ifdef MSVC
typedef C unnamed_type_18[];
#else
typedef C unnamed_type_18[0];
#endif
unnamed_type_18 var19;
struct unnamed_type_18_alignment {
#ifdef MSVC
    char a[_Alignof(unnamed_type_18)];
    char b;
#else
    char a;
    unnamed_type_18 b;
#endif
};
struct unnamed_type_18_alignment var20;
#pragma pack(1)
struct unnamed_type_18_packed {
    unnamed_type_18 a;
};
#pragma pack()
struct unnamed_type_18_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct unnamed_type_18_packed)];
    char b;
#else
    char a;
    struct unnamed_type_18_packed b;
#endif
};
struct unnamed_type_18_required_alignment var21;
struct unnamed_type_18_size {
    char a[sizeof(unnamed_type_18)+1];
    char b;
};
struct unnamed_type_18_size var22;

typedef struct {
    unnamed_type_18 a;
} D;
D var23;
struct D_alignment {
#ifdef MSVC
    char a[_Alignof(D)];
    char b;
#else
    char a;
    D b;
#endif
};
struct D_alignment var24;
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
struct D_required_alignment var25;
struct D_size {
    char a[sizeof(D)+1];
    char b;
};
struct D_size var26;

#pragma pack(2)
typedef struct {
#ifdef MSVC
    __declspec(align(8)) char:1;
    __declspec(align(2)) char c;
#else
    char:1 __attribute__((aligned(8)));
    char c __attribute__((aligned(2)));
#endif
} E;
E var27;
#pragma pack()
struct E_alignment {
#ifdef MSVC
    char a[_Alignof(E)];
    char b;
#else
    char a;
    E b;
#endif
};
struct E_alignment var28;
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
struct E_required_alignment var29;
struct E_size {
    char a[sizeof(E)+1];
    char b;
};
struct E_size var30;

#ifdef MSVC
typedef E unnamed_type_31[];
#else
typedef E unnamed_type_31[0];
#endif
unnamed_type_31 var32;
struct unnamed_type_31_alignment {
#ifdef MSVC
    char a[_Alignof(unnamed_type_31)];
    char b;
#else
    char a;
    unnamed_type_31 b;
#endif
};
struct unnamed_type_31_alignment var33;
#pragma pack(1)
struct unnamed_type_31_packed {
    unnamed_type_31 a;
};
#pragma pack()
struct unnamed_type_31_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct unnamed_type_31_packed)];
    char b;
#else
    char a;
    struct unnamed_type_31_packed b;
#endif
};
struct unnamed_type_31_required_alignment var34;
struct unnamed_type_31_size {
    char a[sizeof(unnamed_type_31)+1];
    char b;
};
struct unnamed_type_31_size var35;

typedef struct {
    unnamed_type_31 a;
} F;
F var36;
struct F_alignment {
#ifdef MSVC
    char a[_Alignof(F)];
    char b;
#else
    char a;
    F b;
#endif
};
struct F_alignment var37;
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
struct F_required_alignment var38;
struct F_size {
    char a[sizeof(F)+1];
    char b;
};
struct F_size var39;

typedef struct {
#ifdef MSVC
    __declspec(align(16)) char:1;
    __declspec(align(8)) char c;
#else
    char:1 __attribute__((aligned(16)));
    char c __attribute__((aligned(8)));
#endif
} G;
G var40;
struct G_alignment {
#ifdef MSVC
    char a[_Alignof(G)];
    char b;
#else
    char a;
    G b;
#endif
};
struct G_alignment var41;
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
struct G_required_alignment var42;
struct G_size {
    char a[sizeof(G)+1];
    char b;
};
struct G_size var43;

#ifdef MSVC
typedef G unnamed_type_44[];
#else
typedef G unnamed_type_44[0];
#endif
unnamed_type_44 var45;
struct unnamed_type_44_alignment {
#ifdef MSVC
    char a[_Alignof(unnamed_type_44)];
    char b;
#else
    char a;
    unnamed_type_44 b;
#endif
};
struct unnamed_type_44_alignment var46;
#pragma pack(1)
struct unnamed_type_44_packed {
    unnamed_type_44 a;
};
#pragma pack()
struct unnamed_type_44_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct unnamed_type_44_packed)];
    char b;
#else
    char a;
    struct unnamed_type_44_packed b;
#endif
};
struct unnamed_type_44_required_alignment var47;
struct unnamed_type_44_size {
    char a[sizeof(unnamed_type_44)+1];
    char b;
};
struct unnamed_type_44_size var48;

typedef struct {
    unnamed_type_44 a;
} H;
H var49;
struct H_alignment {
#ifdef MSVC
    char a[_Alignof(H)];
    char b;
#else
    char a;
    H b;
#endif
};
struct H_alignment var50;
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
struct H_required_alignment var51;
struct H_size {
    char a[sizeof(H)+1];
    char b;
};
struct H_size var52;

#ifdef MSVC
typedef char unnamed_type_53[];
#else
typedef char unnamed_type_53[0];
#endif
unnamed_type_53 var54;
struct unnamed_type_53_alignment {
#ifdef MSVC
    char a[_Alignof(unnamed_type_53)];
    char b;
#else
    char a;
    unnamed_type_53 b;
#endif
};
struct unnamed_type_53_alignment var55;
#pragma pack(1)
struct unnamed_type_53_packed {
    unnamed_type_53 a;
};
#pragma pack()
struct unnamed_type_53_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct unnamed_type_53_packed)];
    char b;
#else
    char a;
    struct unnamed_type_53_packed b;
#endif
};
struct unnamed_type_53_required_alignment var56;
struct unnamed_type_53_size {
    char a[sizeof(unnamed_type_53)+1];
    char b;
};
struct unnamed_type_53_size var57;

typedef struct {
    unnamed_type_53 a;
} I;
I var58;
struct I_alignment {
#ifdef MSVC
    char a[_Alignof(I)];
    char b;
#else
    char a;
    I b;
#endif
};
struct I_alignment var59;
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
struct I_required_alignment var60;
struct I_size {
    char a[sizeof(I)+1];
    char b;
};
struct I_size var61;

#ifdef MSVC
typedef char unnamed_type_62[];
#else
typedef char unnamed_type_62[0];
#endif
unnamed_type_62 var63;
struct unnamed_type_62_alignment {
#ifdef MSVC
    char a[_Alignof(unnamed_type_62)];
    char b;
#else
    char a;
    unnamed_type_62 b;
#endif
};
struct unnamed_type_62_alignment var64;
#pragma pack(1)
struct unnamed_type_62_packed {
    unnamed_type_62 a;
};
#pragma pack()
struct unnamed_type_62_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct unnamed_type_62_packed)];
    char b;
#else
    char a;
    struct unnamed_type_62_packed b;
#endif
};
struct unnamed_type_62_required_alignment var65;
struct unnamed_type_62_size {
    char a[sizeof(unnamed_type_62)+1];
    char b;
};
struct unnamed_type_62_size var66;

typedef struct {
#ifdef MSVC
    __declspec(align(8)) unnamed_type_62 c;
#else
    unnamed_type_62 c __attribute__((aligned(8)));
#endif
} J;
J var67;
struct J_alignment {
#ifdef MSVC
    char a[_Alignof(J)];
    char b;
#else
    char a;
    J b;
#endif
};
struct J_alignment var68;
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
struct J_required_alignment var69;
struct J_size {
    char a[sizeof(J)+1];
    char b;
};
struct J_size var70;

#ifdef MSVC
typedef char unnamed_type_71[];
#else
typedef char unnamed_type_71[0];
#endif
unnamed_type_71 var72;
struct unnamed_type_71_alignment {
#ifdef MSVC
    char a[_Alignof(unnamed_type_71)];
    char b;
#else
    char a;
    unnamed_type_71 b;
#endif
};
struct unnamed_type_71_alignment var73;
#pragma pack(1)
struct unnamed_type_71_packed {
    unnamed_type_71 a;
};
#pragma pack()
struct unnamed_type_71_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct unnamed_type_71_packed)];
    char b;
#else
    char a;
    struct unnamed_type_71_packed b;
#endif
};
struct unnamed_type_71_required_alignment var74;
struct unnamed_type_71_size {
    char a[sizeof(unnamed_type_71)+1];
    char b;
};
struct unnamed_type_71_size var75;

typedef struct {
#ifdef MSVC
    __declspec(align(2)) unnamed_type_71 c;
#else
    unnamed_type_71 c __attribute__((aligned(2)));
#endif
} K;
K var76;
struct K_alignment {
#ifdef MSVC
    char a[_Alignof(K)];
    char b;
#else
    char a;
    K b;
#endif
};
struct K_alignment var77;
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
struct K_required_alignment var78;
struct K_size {
    char a[sizeof(K)+1];
    char b;
};
struct K_size var79;

// MAPPING|ONE|aarch64-generic-macos-none:Clang|aarch64-generic-ios-none:Clang|aarch64-generic-ios-macabi:Clang|aarch64-generic-tvos-none:Clang|hexagon-generic-linux-musl:Clang|i386-i386-ios-none:Clang|x86_64-i686-macos-none:Clang|i386-i686-linux-android:Clang|i386-i686-freebsd-gnu:Clang|i386-i686-haiku-gnu:Clang|i386-i686-netbsd-gnu:Clang|i386-i686-openbsd-gnu:Clang|mipsel-mips32-other-none:Clang|msp430-msp430-other-none:Clang|powerpc64-ppc64-freebsd-gnu:Clang|powerpc-ppc-netbsd-gnu:Clang|riscv32-generic_rv32-other-none:Clang|riscv64-generic_rv64-other-none:Clang|sparc64-v9-netbsd-gnu:Clang|sparc64-v9-openbsd-gnu:Clang|sparc-v9-solaris-eabi:Clang|wasm32-generic-emscripten-musl:Clang|wasm32-generic-other-none:Clang|wasm32-generic-wasi-musl:Clang|x86_64-x86_64-ios-macabi:Clang|x86_64-x86_64-ios-none:Clang|x86_64-x86_64-macos-none:Clang|x86_64-x86_64-tvos-none:Clang|x86_64-x86_64-fuchsia-gnu:Clang|x86_64-x86_64-linux-android:Clang|x86_64-x86_64-solaris-eabi:Clang|x86_64-x86_64-dragonfly-eabi:Clang|x86_64-x86_64-freebsd-gnu:Clang|x86_64-x86_64-haiku-gnu:Clang|x86_64-x86_64-hermit-eabi:Clang|x86_64-x86_64-netbsd-gnu:Clang|x86_64-x86_64-openbsd-gnu:Clang|END
// repr targets Aarch64AppleMacosx|Some("aarch64-generic-macos-none") Arm64AppleIos|Some("aarch64-generic-ios-none") Arm64AppleIosMacabi|Some("aarch64-generic-ios-macabi") Arm64AppleTvos|Some("aarch64-generic-tvos-none") HexagonUnknownLinuxMusl|Some("hexagon-generic-linux-musl") I386AppleIos|Some("i386-i386-ios-none") I686AppleMacosx|Some("x86_64-i686-macos-none") I686LinuxAndroid|Some("i386-i686-linux-android") I686UnknownFreebsd|Some("i386-i686-freebsd-gnu") I686UnknownHaiku|Some("i386-i686-haiku-gnu") I686UnknownNetbsdelf|Some("i386-i686-netbsd-gnu") I686UnknownOpenbsd|Some("i386-i686-openbsd-gnu") MipselSonyPsp|None MipselUnknownNone|Some("mipsel-mips32-other-none") Msp430NoneElf|Some("msp430-msp430-other-none") Powerpc64UnknownFreebsd|Some("powerpc64-ppc64-freebsd-gnu") PowerpcUnknownLinuxGnuspe|None PowerpcUnknownNetbsd|Some("powerpc-ppc-netbsd-gnu") Riscv32|Some("riscv32-generic_rv32-other-none") Riscv64|Some("riscv64-generic_rv64-other-none") Sparc64UnknownNetbsd|Some("sparc64-v9-netbsd-gnu") Sparc64UnknownOpenbsd|Some("sparc64-v9-openbsd-gnu") Sparcv9SunSolaris|Some("sparc-v9-solaris-eabi") Wasm32UnknownEmscripten|Some("wasm32-generic-emscripten-musl") Wasm32UnknownUnknown|Some("wasm32-generic-other-none") Wasm32Wasi|Some("wasm32-generic-wasi-musl") X86_64AppleIosMacabi|Some("x86_64-x86_64-ios-macabi") X86_64AppleIos|Some("x86_64-x86_64-ios-none") X86_64AppleMacosx|Some("x86_64-x86_64-macos-none") X86_64AppleTvos|Some("x86_64-x86_64-tvos-none") X86_64Elf|None X86_64Fuchsia|Some("x86_64-x86_64-fuchsia-gnu") X86_64LinuxAndroid|Some("x86_64-x86_64-linux-android") X86_64PcSolaris|Some("x86_64-x86_64-solaris-eabi") X86_64RumprunNetbsd|None X86_64UnknownDragonfly|Some("x86_64-x86_64-dragonfly-eabi") X86_64UnknownFreebsd|Some("x86_64-x86_64-freebsd-gnu") X86_64UnknownHaiku|Some("x86_64-x86_64-haiku-gnu") X86_64UnknownHermit|Some("x86_64-x86_64-hermit-eabi") X86_64UnknownL4reUclibc|None X86_64UnknownNetbsd|Some("x86_64-x86_64-netbsd-gnu") X86_64UnknownOpenbsd|Some("x86_64-x86_64-openbsd-gnu") X86_64UnknownRedox|None 
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
_Static_assert(sizeof(B) == 0, "record B wrong sizeof");
_Static_assert(_Alignof(B) == 1, "record B wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 1, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_alignment) == 1, "record B wrong alignment");
_Static_assert(sizeof(struct B_packed) == 0, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_packed) == 1, "record B wrong alignment");
_Static_assert(sizeof(struct B_required_alignment) == 1, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "record B wrong alignment");
_Static_assert(sizeof(struct B_size) == 2, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_size) == 1, "record B wrong alignment");
#endif
_Static_assert(sizeof(C) == 1, "record C wrong sizeof");
_Static_assert(_Alignof(C) == 2, "record C wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 4, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_alignment) == 2, "record C wrong alignment");
_Static_assert(sizeof(struct C_packed) == 1, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_packed) == 1, "record C wrong alignment");
_Static_assert(sizeof(struct C_required_alignment) == 2, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "record C wrong alignment");
_Static_assert(sizeof(struct C_size) == 3, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_size) == 1, "record C wrong alignment");
#endif
_Static_assert(sizeof(D) == 0, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 2, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 2, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 2, "record D wrong alignment");
_Static_assert(sizeof(struct D_packed) == 0, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 1, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_size) == 2, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_size) == 1, "record D wrong alignment");
#endif
_Static_assert(sizeof(E) == 4, "record E wrong sizeof");
_Static_assert(_Alignof(E) == 2, "record E wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 6, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_alignment) == 2, "record E wrong alignment");
_Static_assert(sizeof(struct E_packed) == 4, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_packed) == 1, "record E wrong alignment");
_Static_assert(sizeof(struct E_required_alignment) == 5, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "record E wrong alignment");
_Static_assert(sizeof(struct E_size) == 6, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_size) == 1, "record E wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(E,c) == 16, "field E.c wrong bit offset");
#endif
_Static_assert(sizeof(F) == 0, "record F wrong sizeof");
_Static_assert(_Alignof(F) == 2, "record F wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 2, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_alignment) == 2, "record F wrong alignment");
_Static_assert(sizeof(struct F_packed) == 0, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_packed) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_required_alignment) == 1, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_size) == 2, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_size) == 1, "record F wrong alignment");
#endif
_Static_assert(sizeof(G) == 16, "record G wrong sizeof");
_Static_assert(_Alignof(G) == 8, "record G wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 24, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_alignment) == 8, "record G wrong alignment");
_Static_assert(sizeof(struct G_packed) == 16, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_packed) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_required_alignment) == 17, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_size) == 18, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_size) == 1, "record G wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(G,c) == 64, "field G.c wrong bit offset");
#endif
_Static_assert(sizeof(H) == 0, "record H wrong sizeof");
_Static_assert(_Alignof(H) == 8, "record H wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 8, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_alignment) == 8, "record H wrong alignment");
_Static_assert(sizeof(struct H_packed) == 0, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_packed) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_required_alignment) == 1, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_size) == 2, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_size) == 1, "record H wrong alignment");
#endif
_Static_assert(sizeof(I) == 0, "record I wrong sizeof");
_Static_assert(_Alignof(I) == 1, "record I wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I_alignment) == 1, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_alignment) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_packed) == 0, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_packed) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_required_alignment) == 1, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_required_alignment) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_size) == 2, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_size) == 1, "record I wrong alignment");
#endif
_Static_assert(sizeof(J) == 0, "record J wrong sizeof");
_Static_assert(_Alignof(J) == 8, "record J wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J_alignment) == 8, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_alignment) == 8, "record J wrong alignment");
_Static_assert(sizeof(struct J_packed) == 0, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_packed) == 1, "record J wrong alignment");
_Static_assert(sizeof(struct J_required_alignment) == 1, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_required_alignment) == 1, "record J wrong alignment");
_Static_assert(sizeof(struct J_size) == 2, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_size) == 1, "record J wrong alignment");
#endif
_Static_assert(sizeof(K) == 0, "record K wrong sizeof");
_Static_assert(_Alignof(K) == 2, "record K wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct K_alignment) == 2, "record K wrong sizeof");
_Static_assert(_Alignof(struct K_alignment) == 2, "record K wrong alignment");
_Static_assert(sizeof(struct K_packed) == 0, "record K wrong sizeof");
_Static_assert(_Alignof(struct K_packed) == 1, "record K wrong alignment");
_Static_assert(sizeof(struct K_required_alignment) == 1, "record K wrong sizeof");
_Static_assert(_Alignof(struct K_required_alignment) == 1, "record K wrong alignment");
_Static_assert(sizeof(struct K_size) == 2, "record K wrong sizeof");
_Static_assert(_Alignof(struct K_size) == 1, "record K wrong alignment");
#endif
// MAPPING|TWO|aarch64-generic-fuchsia-gnu:Clang|aarch64-generic-linux-android:Clang|aarch64-generic-freebsd-gnu:Clang|aarch64-generic-hermit-eabi:Clang|aarch64-generic-netbsd-gnu:Clang|aarch64-generic-other-none:Clang|aarch64-generic-openbsd-gnu:Clang|arm-baseline-other-eabi:Clang|arm-baseline-other-eabihf:Clang|arm-arm1136j_s-freebsd-gnu:Clang|arm-arm1136j_s-netbsd-eabihf:Clang|arm-baseline-other-eabi:Clang|arm-baseline-other-eabihf:Clang|arm-cortex_r4-ios-none:Clang|arm-cortex_r4-other-eabi:Clang|arm-cortex_r4-other-eabihf:Clang|arm-baseline-ios-none:Clang|arm-cortex_r4-freebsd-gnu:Clang|arm-cortex_r4-netbsd-eabihf:Clang|thumb-arm710t-other-eabi:Clang|thumb-cortex_m0-other-eabi:Clang|thumb-cortex_m4-other-eabihf:Clang|thumb-cortex_m4-other-eabi:Clang|thumb-cortex_m3-other-eabi:Clang|thumb-baseline-other-eabi:Clang|thumb-cortex_m33-other-eabihf:Clang|thumb-cortex_m33-other-eabi:Clang|END
// repr targets Aarch64Fuchsia|Some("aarch64-generic-fuchsia-gnu") Aarch64LinuxAndroid|Some("aarch64-generic-linux-android") Aarch64UnknownFreebsd|Some("aarch64-generic-freebsd-gnu") Aarch64UnknownHermit|Some("aarch64-generic-hermit-eabi") Aarch64UnknownNetbsd|Some("aarch64-generic-netbsd-gnu") Aarch64UnknownNone|Some("aarch64-generic-other-none") Aarch64UnknownOpenbsd|Some("aarch64-generic-openbsd-gnu") Aarch64UnknownRedox|None Armebv7rUnknownNoneEabi|Some("arm-baseline-other-eabi") Armebv7rUnknownNoneEabihf|Some("arm-baseline-other-eabihf") ArmLinuxAndroideabi|None Armv6UnknownFreebsdGnueabihf|Some("arm-arm1136j_s-freebsd-gnu") Armv6UnknownNetbsdelfEabihf|Some("arm-arm1136j_s-netbsd-eabihf") Armv7aNoneEabi|Some("arm-baseline-other-eabi") Armv7aNoneEabihf|Some("arm-baseline-other-eabihf") Armv7AppleIos|Some("arm-cortex_r4-ios-none") Armv7NoneLinuxAndroid|None Armv7rUnknownNoneEabi|Some("arm-cortex_r4-other-eabi") Armv7rUnknownNoneEabihf|Some("arm-cortex_r4-other-eabihf") Armv7sAppleIos|Some("arm-baseline-ios-none") Armv7UnknownFreebsdGnueabihf|Some("arm-cortex_r4-freebsd-gnu") Armv7UnknownNetbsdelfEabihf|Some("arm-cortex_r4-netbsd-eabihf") Thumbv4tNoneEabi|Some("thumb-arm710t-other-eabi") Thumbv6mNoneEabi|Some("thumb-cortex_m0-other-eabi") Thumbv7emNoneEabihf|Some("thumb-cortex_m4-other-eabihf") Thumbv7emNoneEabi|Some("thumb-cortex_m4-other-eabi") Thumbv7mNoneEabi|Some("thumb-cortex_m3-other-eabi") Thumbv8mBaseNoneEabi|Some("thumb-baseline-other-eabi") Thumbv8mMainNoneEabihf|Some("thumb-cortex_m33-other-eabihf") Thumbv8mMainNoneEabi|Some("thumb-cortex_m33-other-eabi") 
#elif defined(TWO)
_Static_assert(sizeof(A) == 2, "record A wrong sizeof");
_Static_assert(_Alignof(A) == 2, "record A wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 4, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_alignment) == 2, "record A wrong alignment");
_Static_assert(sizeof(struct A_packed) == 2, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_packed) == 1, "record A wrong alignment");
_Static_assert(sizeof(struct A_required_alignment) == 3, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "record A wrong alignment");
_Static_assert(sizeof(struct A_size) == 4, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_size) == 1, "record A wrong alignment");
#endif
_Static_assert(sizeof(B) == 0, "record B wrong sizeof");
_Static_assert(_Alignof(B) == 2, "record B wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 2, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_alignment) == 2, "record B wrong alignment");
_Static_assert(sizeof(struct B_packed) == 0, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_packed) == 1, "record B wrong alignment");
_Static_assert(sizeof(struct B_required_alignment) == 1, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "record B wrong alignment");
_Static_assert(sizeof(struct B_size) == 2, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_size) == 1, "record B wrong alignment");
#endif
_Static_assert(sizeof(C) == 1, "record C wrong sizeof");
_Static_assert(_Alignof(C) == 2, "record C wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 4, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_alignment) == 2, "record C wrong alignment");
_Static_assert(sizeof(struct C_packed) == 1, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_packed) == 1, "record C wrong alignment");
_Static_assert(sizeof(struct C_required_alignment) == 2, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "record C wrong alignment");
_Static_assert(sizeof(struct C_size) == 3, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_size) == 1, "record C wrong alignment");
#endif
_Static_assert(sizeof(D) == 0, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 2, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 2, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 2, "record D wrong alignment");
_Static_assert(sizeof(struct D_packed) == 0, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 1, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_size) == 2, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_size) == 1, "record D wrong alignment");
#endif
_Static_assert(sizeof(E) == 4, "record E wrong sizeof");
_Static_assert(_Alignof(E) == 2, "record E wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 6, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_alignment) == 2, "record E wrong alignment");
_Static_assert(sizeof(struct E_packed) == 4, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_packed) == 1, "record E wrong alignment");
_Static_assert(sizeof(struct E_required_alignment) == 5, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "record E wrong alignment");
_Static_assert(sizeof(struct E_size) == 6, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_size) == 1, "record E wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(E,c) == 16, "field E.c wrong bit offset");
#endif
_Static_assert(sizeof(F) == 0, "record F wrong sizeof");
_Static_assert(_Alignof(F) == 2, "record F wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 2, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_alignment) == 2, "record F wrong alignment");
_Static_assert(sizeof(struct F_packed) == 0, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_packed) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_required_alignment) == 1, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_size) == 2, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_size) == 1, "record F wrong alignment");
#endif
_Static_assert(sizeof(G) == 16, "record G wrong sizeof");
_Static_assert(_Alignof(G) == 16, "record G wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 32, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_alignment) == 16, "record G wrong alignment");
_Static_assert(sizeof(struct G_packed) == 16, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_packed) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_required_alignment) == 17, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_size) == 18, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_size) == 1, "record G wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(G,c) == 64, "field G.c wrong bit offset");
#endif
_Static_assert(sizeof(H) == 0, "record H wrong sizeof");
_Static_assert(_Alignof(H) == 16, "record H wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 16, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_alignment) == 16, "record H wrong alignment");
_Static_assert(sizeof(struct H_packed) == 0, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_packed) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_required_alignment) == 1, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_size) == 2, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_size) == 1, "record H wrong alignment");
#endif
_Static_assert(sizeof(I) == 0, "record I wrong sizeof");
_Static_assert(_Alignof(I) == 1, "record I wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I_alignment) == 1, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_alignment) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_packed) == 0, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_packed) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_required_alignment) == 1, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_required_alignment) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_size) == 2, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_size) == 1, "record I wrong alignment");
#endif
_Static_assert(sizeof(J) == 0, "record J wrong sizeof");
_Static_assert(_Alignof(J) == 8, "record J wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J_alignment) == 8, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_alignment) == 8, "record J wrong alignment");
_Static_assert(sizeof(struct J_packed) == 0, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_packed) == 1, "record J wrong alignment");
_Static_assert(sizeof(struct J_required_alignment) == 1, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_required_alignment) == 1, "record J wrong alignment");
_Static_assert(sizeof(struct J_size) == 2, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_size) == 1, "record J wrong alignment");
#endif
_Static_assert(sizeof(K) == 0, "record K wrong sizeof");
_Static_assert(_Alignof(K) == 2, "record K wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct K_alignment) == 2, "record K wrong sizeof");
_Static_assert(_Alignof(struct K_alignment) == 2, "record K wrong alignment");
_Static_assert(sizeof(struct K_packed) == 0, "record K wrong sizeof");
_Static_assert(_Alignof(struct K_packed) == 1, "record K wrong alignment");
_Static_assert(sizeof(struct K_required_alignment) == 1, "record K wrong sizeof");
_Static_assert(_Alignof(struct K_required_alignment) == 1, "record K wrong alignment");
_Static_assert(sizeof(struct K_size) == 2, "record K wrong sizeof");
_Static_assert(_Alignof(struct K_size) == 1, "record K wrong alignment");
#endif
// MAPPING|THREE|aarch64-generic-windows-msvc:Msvc|thumb-baseline-windows-msvc:Msvc|END
// repr targets Aarch64PcWindowsMsvc|Some("aarch64-generic-windows-msvc") Thumbv7aPcWindowsMsvc|Some("thumb-baseline-windows-msvc") 
#elif defined(THREE)
_Static_assert(sizeof(A) == 2, "record A wrong sizeof");
_Static_assert(_Alignof(A) == 4, "record A wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 8, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_alignment) == 4, "record A wrong alignment");
_Static_assert(sizeof(struct A_packed) == 2, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_packed) == 1, "record A wrong alignment");
_Static_assert(sizeof(struct A_required_alignment) == 3, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "record A wrong alignment");
_Static_assert(sizeof(struct A_size) == 4, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_size) == 1, "record A wrong alignment");
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
_Static_assert(sizeof(C) == 1, "record C wrong sizeof");
_Static_assert(_Alignof(C) == 2, "record C wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 4, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_alignment) == 2, "record C wrong alignment");
_Static_assert(sizeof(struct C_packed) == 1, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_packed) == 1, "record C wrong alignment");
_Static_assert(sizeof(struct C_required_alignment) == 2, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "record C wrong alignment");
_Static_assert(sizeof(struct C_size) == 3, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_size) == 1, "record C wrong alignment");
#endif
_Static_assert(sizeof(D) == 4, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 2, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 6, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 2, "record D wrong alignment");
_Static_assert(sizeof(struct D_packed) == 4, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 5, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_size) == 6, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_size) == 1, "record D wrong alignment");
#endif
_Static_assert(sizeof(E) == 4, "record E wrong sizeof");
_Static_assert(_Alignof(E) == 8, "record E wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 16, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_alignment) == 8, "record E wrong alignment");
_Static_assert(sizeof(struct E_packed) == 4, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_packed) == 1, "record E wrong alignment");
_Static_assert(sizeof(struct E_required_alignment) == 5, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "record E wrong alignment");
_Static_assert(sizeof(struct E_size) == 6, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_size) == 1, "record E wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(E,c) == 16, "field E.c wrong bit offset");
#endif
_Static_assert(sizeof(F) == 4, "record F wrong sizeof");
_Static_assert(_Alignof(F) == 8, "record F wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 16, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_alignment) == 8, "record F wrong alignment");
_Static_assert(sizeof(struct F_packed) == 4, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_packed) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_required_alignment) == 5, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_size) == 6, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_size) == 1, "record F wrong alignment");
#endif
_Static_assert(sizeof(G) == 16, "record G wrong sizeof");
_Static_assert(_Alignof(G) == 16, "record G wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 32, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_alignment) == 16, "record G wrong alignment");
_Static_assert(sizeof(struct G_packed) == 16, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_packed) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_required_alignment) == 17, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_size) == 18, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_size) == 1, "record G wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(G,c) == 64, "field G.c wrong bit offset");
#endif
_Static_assert(sizeof(H) == 8, "record H wrong sizeof");
_Static_assert(_Alignof(H) == 8, "record H wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 16, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_alignment) == 8, "record H wrong alignment");
_Static_assert(sizeof(struct H_packed) == 8, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_packed) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_required_alignment) == 9, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_size) == 10, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_size) == 1, "record H wrong alignment");
#endif
_Static_assert(sizeof(I) == 4, "record I wrong sizeof");
_Static_assert(_Alignof(I) == 1, "record I wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I_alignment) == 5, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_alignment) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_packed) == 4, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_packed) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_required_alignment) == 5, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_required_alignment) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_size) == 6, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_size) == 1, "record I wrong alignment");
#endif
_Static_assert(sizeof(J) == 8, "record J wrong sizeof");
_Static_assert(_Alignof(J) == 8, "record J wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J_alignment) == 16, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_alignment) == 8, "record J wrong alignment");
_Static_assert(sizeof(struct J_packed) == 8, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_packed) == 1, "record J wrong alignment");
_Static_assert(sizeof(struct J_required_alignment) == 9, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_required_alignment) == 1, "record J wrong alignment");
_Static_assert(sizeof(struct J_size) == 10, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_size) == 1, "record J wrong alignment");
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
// MAPPING|FOUR|i386-i586-windows-msvc:Msvc|i386-i686-windows-msvc:Msvc|i386-i686-uefi-msvc:Msvc|x86_64-x86_64-windows-msvc:Msvc|x86_64-x86_64-uefi-msvc:Msvc|END
// repr targets I586PcWindowsMsvc|Some("i386-i586-windows-msvc") I686PcWindowsMsvc|Some("i386-i686-windows-msvc") I686UnknownWindows|Some("i386-i686-uefi-msvc") X86_64PcWindowsMsvc|Some("x86_64-x86_64-windows-msvc") X86_64UnknownWindows|Some("x86_64-x86_64-uefi-msvc") 
#elif defined(FOUR)
_Static_assert(sizeof(A) == 2, "record A wrong sizeof");
_Static_assert(_Alignof(A) == 4, "record A wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 8, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_alignment) == 4, "record A wrong alignment");
_Static_assert(sizeof(struct A_packed) == 2, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_packed) == 1, "record A wrong alignment");
_Static_assert(sizeof(struct A_required_alignment) == 3, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "record A wrong alignment");
_Static_assert(sizeof(struct A_size) == 4, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_size) == 1, "record A wrong alignment");
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
_Static_assert(sizeof(C) == 1, "record C wrong sizeof");
_Static_assert(_Alignof(C) == 2, "record C wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 4, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_alignment) == 2, "record C wrong alignment");
_Static_assert(sizeof(struct C_packed) == 1, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_packed) == 1, "record C wrong alignment");
_Static_assert(sizeof(struct C_required_alignment) == 2, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "record C wrong alignment");
_Static_assert(sizeof(struct C_size) == 3, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_size) == 1, "record C wrong alignment");
#endif
_Static_assert(sizeof(D) == 4, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 2, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 6, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 2, "record D wrong alignment");
_Static_assert(sizeof(struct D_packed) == 4, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 5, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D wrong alignment");
_Static_assert(sizeof(struct D_size) == 6, "record D wrong sizeof");
_Static_assert(_Alignof(struct D_size) == 1, "record D wrong alignment");
#endif
_Static_assert(sizeof(E) == 4, "record E wrong sizeof");
_Static_assert(_Alignof(E) == 8, "record E wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 16, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_alignment) == 8, "record E wrong alignment");
_Static_assert(sizeof(struct E_packed) == 4, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_packed) == 1, "record E wrong alignment");
_Static_assert(sizeof(struct E_required_alignment) == 5, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "record E wrong alignment");
_Static_assert(sizeof(struct E_size) == 6, "record E wrong sizeof");
_Static_assert(_Alignof(struct E_size) == 1, "record E wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(E,c) == 16, "field E.c wrong bit offset");
#endif
_Static_assert(sizeof(F) == 4, "record F wrong sizeof");
_Static_assert(_Alignof(F) == 8, "record F wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 16, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_alignment) == 8, "record F wrong alignment");
_Static_assert(sizeof(struct F_packed) == 4, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_packed) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_required_alignment) == 5, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "record F wrong alignment");
_Static_assert(sizeof(struct F_size) == 6, "record F wrong sizeof");
_Static_assert(_Alignof(struct F_size) == 1, "record F wrong alignment");
#endif
_Static_assert(sizeof(G) == 16, "record G wrong sizeof");
_Static_assert(_Alignof(G) == 16, "record G wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 32, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_alignment) == 16, "record G wrong alignment");
_Static_assert(sizeof(struct G_packed) == 16, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_packed) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_required_alignment) == 17, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "record G wrong alignment");
_Static_assert(sizeof(struct G_size) == 18, "record G wrong sizeof");
_Static_assert(_Alignof(struct G_size) == 1, "record G wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(G,c) == 64, "field G.c wrong bit offset");
#endif
_Static_assert(sizeof(H) == 8, "record H wrong sizeof");
_Static_assert(_Alignof(H) == 16, "record H wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 32, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_alignment) == 16, "record H wrong alignment");
_Static_assert(sizeof(struct H_packed) == 8, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_packed) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_required_alignment) == 9, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "record H wrong alignment");
_Static_assert(sizeof(struct H_size) == 10, "record H wrong sizeof");
_Static_assert(_Alignof(struct H_size) == 1, "record H wrong alignment");
#endif
_Static_assert(sizeof(I) == 4, "record I wrong sizeof");
_Static_assert(_Alignof(I) == 1, "record I wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I_alignment) == 5, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_alignment) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_packed) == 4, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_packed) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_required_alignment) == 5, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_required_alignment) == 1, "record I wrong alignment");
_Static_assert(sizeof(struct I_size) == 6, "record I wrong sizeof");
_Static_assert(_Alignof(struct I_size) == 1, "record I wrong alignment");
#endif
_Static_assert(sizeof(J) == 8, "record J wrong sizeof");
_Static_assert(_Alignof(J) == 8, "record J wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J_alignment) == 16, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_alignment) == 8, "record J wrong alignment");
_Static_assert(sizeof(struct J_packed) == 8, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_packed) == 1, "record J wrong alignment");
_Static_assert(sizeof(struct J_required_alignment) == 9, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_required_alignment) == 1, "record J wrong alignment");
_Static_assert(sizeof(struct J_size) == 10, "record J wrong sizeof");
_Static_assert(_Alignof(struct J_size) == 1, "record J wrong alignment");
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
#endif
