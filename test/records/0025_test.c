// SPDX-License-Identifier: GPL-3.0-or-later

// This test file is auto-generated. do not edit.
// This file is a derivative work from the test files found
// in this repo : https://github.com/mahkoh/repr-c
// and is under the same licence as the original work.

#pragma pack(4)
typedef struct {
#ifdef MSVC
    __declspec(align(8)) char:1;
#else
    char:1 __attribute__((aligned(8)));
#endif
} A;
A var1;
#pragma pack()
struct A_extra_alignment {
#ifdef MSVC
    char a[_Alignof(A)];
    char b;
#else
    char a;
    A b;
#endif
};
struct A_extra_alignment var2;
#pragma pack(1)
struct A_extra_packed {
    A a;
};
#pragma pack()
struct A_extra_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct A_extra_packed)];
    char b;
#else
    char a;
    struct A_extra_packed b;
#endif
};
struct A_extra_required_alignment var3;
struct A_extra_size {
    char a[sizeof(A)+1];
    char b;
};
struct A_extra_size var4;

#ifdef MSVC
typedef A unnamed_type_5[];
#else
typedef A unnamed_type_5[0];
#endif
unnamed_type_5 var6;
struct unnamed_type_5_extra_alignment {
#ifdef MSVC
    char a[_Alignof(unnamed_type_5)];
    char b;
#else
    char a;
    unnamed_type_5 b;
#endif
};
struct unnamed_type_5_extra_alignment var7;
#pragma pack(1)
struct unnamed_type_5_extra_packed {
    unnamed_type_5 a;
};
#pragma pack()
struct unnamed_type_5_extra_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct unnamed_type_5_extra_packed)];
    char b;
#else
    char a;
    struct unnamed_type_5_extra_packed b;
#endif
};
struct unnamed_type_5_extra_required_alignment var8;
struct unnamed_type_5_extra_size {
    char a[sizeof(unnamed_type_5)+1];
    char b;
};
struct unnamed_type_5_extra_size var9;

typedef union {
    unnamed_type_5 a;
} BA;
BA var10;
struct BA_extra_alignment {
#ifdef MSVC
    char a[_Alignof(BA)];
    char b;
#else
    char a;
    BA b;
#endif
};
struct BA_extra_alignment var11;
#pragma pack(1)
struct BA_extra_packed {
    BA a;
};
#pragma pack()
struct BA_extra_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct BA_extra_packed)];
    char b;
#else
    char a;
    struct BA_extra_packed b;
#endif
};
struct BA_extra_required_alignment var12;
struct BA_extra_size {
    char a[sizeof(BA)+1];
    char b;
};
struct BA_extra_size var13;

#ifdef MSVC
typedef A unnamed_type_14[];
#else
typedef A unnamed_type_14[0];
#endif
unnamed_type_14 var15;
struct unnamed_type_14_extra_alignment {
#ifdef MSVC
    char a[_Alignof(unnamed_type_14)];
    char b;
#else
    char a;
    unnamed_type_14 b;
#endif
};
struct unnamed_type_14_extra_alignment var16;
#pragma pack(1)
struct unnamed_type_14_extra_packed {
    unnamed_type_14 a;
};
#pragma pack()
struct unnamed_type_14_extra_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct unnamed_type_14_extra_packed)];
    char b;
#else
    char a;
    struct unnamed_type_14_extra_packed b;
#endif
};
struct unnamed_type_14_extra_required_alignment var17;
struct unnamed_type_14_extra_size {
    char a[sizeof(unnamed_type_14)+1];
    char b;
};
struct unnamed_type_14_extra_size var18;

typedef union {
#ifdef MSVC
    __declspec(align(16)) char:0;
#else
    char:0 __attribute__((aligned(16)));
#endif
    unnamed_type_14 a;
} BB;
BB var19;
struct BB_extra_alignment {
#ifdef MSVC
    char a[_Alignof(BB)];
    char b;
#else
    char a;
    BB b;
#endif
};
struct BB_extra_alignment var20;
#pragma pack(1)
struct BB_extra_packed {
    BB a;
};
#pragma pack()
struct BB_extra_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct BB_extra_packed)];
    char b;
#else
    char a;
    struct BB_extra_packed b;
#endif
};
struct BB_extra_required_alignment var21;
struct BB_extra_size {
    char a[sizeof(BB)+1];
    char b;
};
struct BB_extra_size var22;

#ifdef MSVC
typedef A unnamed_type_23[];
#else
typedef A unnamed_type_23[0];
#endif
unnamed_type_23 var24;
struct unnamed_type_23_extra_alignment {
#ifdef MSVC
    char a[_Alignof(unnamed_type_23)];
    char b;
#else
    char a;
    unnamed_type_23 b;
#endif
};
struct unnamed_type_23_extra_alignment var25;
#pragma pack(1)
struct unnamed_type_23_extra_packed {
    unnamed_type_23 a;
};
#pragma pack()
struct unnamed_type_23_extra_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct unnamed_type_23_extra_packed)];
    char b;
#else
    char a;
    struct unnamed_type_23_extra_packed b;
#endif
};
struct unnamed_type_23_extra_required_alignment var26;
struct unnamed_type_23_extra_size {
    char a[sizeof(unnamed_type_23)+1];
    char b;
};
struct unnamed_type_23_extra_size var27;

typedef union {
    unnamed_type_23 a;
#ifdef MSVC
    __declspec(align(16)) char:0;
#else
    char:0 __attribute__((aligned(16)));
#endif
} BC;
BC var28;
struct BC_extra_alignment {
#ifdef MSVC
    char a[_Alignof(BC)];
    char b;
#else
    char a;
    BC b;
#endif
};
struct BC_extra_alignment var29;
#pragma pack(1)
struct BC_extra_packed {
    BC a;
};
#pragma pack()
struct BC_extra_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct BC_extra_packed)];
    char b;
#else
    char a;
    struct BC_extra_packed b;
#endif
};
struct BC_extra_required_alignment var30;
struct BC_extra_size {
    char a[sizeof(BC)+1];
    char b;
};
struct BC_extra_size var31;

#ifdef MSVC
typedef A unnamed_type_32[];
#else
typedef A unnamed_type_32[0];
#endif
unnamed_type_32 var33;
struct unnamed_type_32_extra_alignment {
#ifdef MSVC
    char a[_Alignof(unnamed_type_32)];
    char b;
#else
    char a;
    unnamed_type_32 b;
#endif
};
struct unnamed_type_32_extra_alignment var34;
#pragma pack(1)
struct unnamed_type_32_extra_packed {
    unnamed_type_32 a;
};
#pragma pack()
struct unnamed_type_32_extra_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct unnamed_type_32_extra_packed)];
    char b;
#else
    char a;
    struct unnamed_type_32_extra_packed b;
#endif
};
struct unnamed_type_32_extra_required_alignment var35;
struct unnamed_type_32_extra_size {
    char a[sizeof(unnamed_type_32)+1];
    char b;
};
struct unnamed_type_32_extra_size var36;

#ifdef MSVC
__declspec(align(16)) typedef union {
#else
typedef union {
#endif
    unnamed_type_32 a;
#ifdef MSVC
} BD;
#else
} __attribute__((aligned(16))) BD;
#endif
BD var37;
struct BD_extra_alignment {
#ifdef MSVC
    char a[_Alignof(BD)];
    char b;
#else
    char a;
    BD b;
#endif
};
struct BD_extra_alignment var38;
#pragma pack(1)
struct BD_extra_packed {
    BD a;
};
#pragma pack()
struct BD_extra_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct BD_extra_packed)];
    char b;
#else
    char a;
    struct BD_extra_packed b;
#endif
};
struct BD_extra_required_alignment var39;
struct BD_extra_size {
    char a[sizeof(BD)+1];
    char b;
};
struct BD_extra_size var40;

#ifdef MSVC
typedef A unnamed_type_41[];
#else
typedef A unnamed_type_41[0];
#endif
unnamed_type_41 var42;
struct unnamed_type_41_extra_alignment {
#ifdef MSVC
    char a[_Alignof(unnamed_type_41)];
    char b;
#else
    char a;
    unnamed_type_41 b;
#endif
};
struct unnamed_type_41_extra_alignment var43;
#pragma pack(1)
struct unnamed_type_41_extra_packed {
    unnamed_type_41 a;
};
#pragma pack()
struct unnamed_type_41_extra_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct unnamed_type_41_extra_packed)];
    char b;
#else
    char a;
    struct unnamed_type_41_extra_packed b;
#endif
};
struct unnamed_type_41_extra_required_alignment var44;
struct unnamed_type_41_extra_size {
    char a[sizeof(unnamed_type_41)+1];
    char b;
};
struct unnamed_type_41_extra_size var45;

#ifdef MSVC
__declspec(align(2)) typedef union {
#else
typedef union {
#endif
    unnamed_type_41 a;
#ifdef MSVC
} BE;
#else
} __attribute__((aligned(2))) BE;
#endif
BE var46;
struct BE_extra_alignment {
#ifdef MSVC
    char a[_Alignof(BE)];
    char b;
#else
    char a;
    BE b;
#endif
};
struct BE_extra_alignment var47;
#pragma pack(1)
struct BE_extra_packed {
    BE a;
};
#pragma pack()
struct BE_extra_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct BE_extra_packed)];
    char b;
#else
    char a;
    struct BE_extra_packed b;
#endif
};
struct BE_extra_required_alignment var48;
struct BE_extra_size {
    char a[sizeof(BE)+1];
    char b;
};
struct BE_extra_size var49;

#ifdef MSVC
__declspec(align(8)) typedef char C;
#else
typedef char C __attribute__((aligned(8)));
#endif
C var50;
struct C_extra_alignment {
#ifdef MSVC
    char a[_Alignof(C)];
    char b;
#else
    char a;
    C b;
#endif
};
struct C_extra_alignment var51;
#pragma pack(1)
struct C_extra_packed {
    C a;
};
#pragma pack()
struct C_extra_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct C_extra_packed)];
    char b;
#else
    char a;
    struct C_extra_packed b;
#endif
};
struct C_extra_required_alignment var52;
struct C_extra_size {
    char a[sizeof(C)+1];
    char b;
};
struct C_extra_size var53;

#ifdef MSVC
typedef C unnamed_type_54[];
#else
typedef C unnamed_type_54[0];
#endif
unnamed_type_54 var55;
struct unnamed_type_54_extra_alignment {
#ifdef MSVC
    char a[_Alignof(unnamed_type_54)];
    char b;
#else
    char a;
    unnamed_type_54 b;
#endif
};
struct unnamed_type_54_extra_alignment var56;
#pragma pack(1)
struct unnamed_type_54_extra_packed {
    unnamed_type_54 a;
};
#pragma pack()
struct unnamed_type_54_extra_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct unnamed_type_54_extra_packed)];
    char b;
#else
    char a;
    struct unnamed_type_54_extra_packed b;
#endif
};
struct unnamed_type_54_extra_required_alignment var57;
struct unnamed_type_54_extra_size {
    char a[sizeof(unnamed_type_54)+1];
    char b;
};
struct unnamed_type_54_extra_size var58;

typedef union {
    unnamed_type_54 a;
} D;
D var59;
struct D_extra_alignment {
#ifdef MSVC
    char a[_Alignof(D)];
    char b;
#else
    char a;
    D b;
#endif
};
struct D_extra_alignment var60;
#pragma pack(1)
struct D_extra_packed {
    D a;
};
#pragma pack()
struct D_extra_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct D_extra_packed)];
    char b;
#else
    char a;
    struct D_extra_packed b;
#endif
};
struct D_extra_required_alignment var61;
struct D_extra_size {
    char a[sizeof(D)+1];
    char b;
};
struct D_extra_size var62;

typedef union {
    char:0;
} E;
E var63;
struct E_extra_alignment {
#ifdef MSVC
    char a[_Alignof(E)];
    char b;
#else
    char a;
    E b;
#endif
};
struct E_extra_alignment var64;
#pragma pack(1)
struct E_extra_packed {
    E a;
};
#pragma pack()
struct E_extra_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct E_extra_packed)];
    char b;
#else
    char a;
    struct E_extra_packed b;
#endif
};
struct E_extra_required_alignment var65;
struct E_extra_size {
    char a[sizeof(E)+1];
    char b;
};
struct E_extra_size var66;

typedef union {
    int:0;
} F;
F var67;
struct F_extra_alignment {
#ifdef MSVC
    char a[_Alignof(F)];
    char b;
#else
    char a;
    F b;
#endif
};
struct F_extra_alignment var68;
#pragma pack(1)
struct F_extra_packed {
    F a;
};
#pragma pack()
struct F_extra_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct F_extra_packed)];
    char b;
#else
    char a;
    struct F_extra_packed b;
#endif
};
struct F_extra_required_alignment var69;
struct F_extra_size {
    char a[sizeof(F)+1];
    char b;
};
struct F_extra_size var70;

typedef union {
    long long:0;
} G;
G var71;
struct G_extra_alignment {
#ifdef MSVC
    char a[_Alignof(G)];
    char b;
#else
    char a;
    G b;
#endif
};
struct G_extra_alignment var72;
#pragma pack(1)
struct G_extra_packed {
    G a;
};
#pragma pack()
struct G_extra_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct G_extra_packed)];
    char b;
#else
    char a;
    struct G_extra_packed b;
#endif
};
struct G_extra_required_alignment var73;
struct G_extra_size {
    char a[sizeof(G)+1];
    char b;
};
struct G_extra_size var74;

typedef union {
    char:0;
    long long:0;
} H;
H var75;
struct H_extra_alignment {
#ifdef MSVC
    char a[_Alignof(H)];
    char b;
#else
    char a;
    H b;
#endif
};
struct H_extra_alignment var76;
#pragma pack(1)
struct H_extra_packed {
    H a;
};
#pragma pack()
struct H_extra_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct H_extra_packed)];
    char b;
#else
    char a;
    struct H_extra_packed b;
#endif
};
struct H_extra_required_alignment var77;
struct H_extra_size {
    char a[sizeof(H)+1];
    char b;
};
struct H_extra_size var78;

#ifdef MSVC
typedef char unnamed_type_79[];
#else
typedef char unnamed_type_79[0];
#endif
unnamed_type_79 var80;
struct unnamed_type_79_extra_alignment {
#ifdef MSVC
    char a[_Alignof(unnamed_type_79)];
    char b;
#else
    char a;
    unnamed_type_79 b;
#endif
};
struct unnamed_type_79_extra_alignment var81;
#pragma pack(1)
struct unnamed_type_79_extra_packed {
    unnamed_type_79 a;
};
#pragma pack()
struct unnamed_type_79_extra_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct unnamed_type_79_extra_packed)];
    char b;
#else
    char a;
    struct unnamed_type_79_extra_packed b;
#endif
};
struct unnamed_type_79_extra_required_alignment var82;
struct unnamed_type_79_extra_size {
    char a[sizeof(unnamed_type_79)+1];
    char b;
};
struct unnamed_type_79_extra_size var83;

typedef union {
    unnamed_type_79 c;
} I;
I var84;
struct I_extra_alignment {
#ifdef MSVC
    char a[_Alignof(I)];
    char b;
#else
    char a;
    I b;
#endif
};
struct I_extra_alignment var85;
#pragma pack(1)
struct I_extra_packed {
    I a;
};
#pragma pack()
struct I_extra_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct I_extra_packed)];
    char b;
#else
    char a;
    struct I_extra_packed b;
#endif
};
struct I_extra_required_alignment var86;
struct I_extra_size {
    char a[sizeof(I)+1];
    char b;
};
struct I_extra_size var87;

// MAPPING|ONE|aarch64-generic-macos-none:Clang|aarch64-generic-ios-none:Clang|aarch64-generic-ios-macabi:Clang|aarch64-generic-tvos-none:Clang|hexagon-generic-linux-musl:Clang|mipsel-mips32-other-eabi:Clang|powerpc64-ppc64-freebsd-gnu:Clang|powerpc-ppc-netbsd-gnu:Clang|riscv32-baseline_rv32-other-eabi:Clang|riscv64-baseline_rv64-other-eabi:Clang|sparc64-v9-netbsd-gnu:Clang|sparc64-v9-openbsd-gnu:Clang|sparc-v9-solaris-eabi:Clang|wasm32-generic-emscripten-musl:Clang|wasm32-generic-other-musl:Clang|wasm32-generic-wasi-musl:Clang|x86_64-x86_64-ios-macabi:Clang|x86_64-x86_64-ios-none:Clang|x86_64-x86_64-macos-none:Clang|x86_64-x86_64-tvos-none:Clang|x86_64-x86_64-other-eabi:Clang|x86_64-x86_64-fuchsia-gnu:Clang|x86_64-x86_64-linux-android:Clang|x86_64-x86_64-solaris-eabi:Clang|x86_64-x86_64-dragonfly-eabi:Clang|x86_64-x86_64-freebsd-gnu:Clang|x86_64-x86_64-haiku-gnu:Clang|x86_64-x86_64-hermit-eabi:Clang|x86_64-x86_64-netbsd-gnu:Clang|x86_64-x86_64-openbsd-gnu:Clang|END
// repr targets Aarch64AppleMacosx|Some("aarch64-generic-macos-none") Arm64AppleIos|Some("aarch64-generic-ios-none") Arm64AppleIosMacabi|Some("aarch64-generic-ios-macabi") Arm64AppleTvos|Some("aarch64-generic-tvos-none") HexagonUnknownLinuxMusl|Some("hexagon-generic-linux-musl") MipselSonyPsp|None MipselUnknownNone|Some("mipsel-mips32-other-eabi") Powerpc64UnknownFreebsd|Some("powerpc64-ppc64-freebsd-gnu") PowerpcUnknownLinuxGnuspe|None PowerpcUnknownNetbsd|Some("powerpc-ppc-netbsd-gnu") Riscv32|Some("riscv32-baseline_rv32-other-eabi") Riscv64|Some("riscv64-baseline_rv64-other-eabi") Sparc64UnknownNetbsd|Some("sparc64-v9-netbsd-gnu") Sparc64UnknownOpenbsd|Some("sparc64-v9-openbsd-gnu") Sparcv9SunSolaris|Some("sparc-v9-solaris-eabi") Wasm32UnknownEmscripten|Some("wasm32-generic-emscripten-musl") Wasm32UnknownUnknown|Some("wasm32-generic-other-musl") Wasm32Wasi|Some("wasm32-generic-wasi-musl") X86_64AppleIosMacabi|Some("x86_64-x86_64-ios-macabi") X86_64AppleIos|Some("x86_64-x86_64-ios-none") X86_64AppleMacosx|Some("x86_64-x86_64-macos-none") X86_64AppleTvos|Some("x86_64-x86_64-tvos-none") X86_64Elf|Some("x86_64-x86_64-other-eabi") X86_64Fuchsia|Some("x86_64-x86_64-fuchsia-gnu") X86_64LinuxAndroid|Some("x86_64-x86_64-linux-android") X86_64PcSolaris|Some("x86_64-x86_64-solaris-eabi") X86_64RumprunNetbsd|None X86_64UnknownDragonfly|Some("x86_64-x86_64-dragonfly-eabi") X86_64UnknownFreebsd|Some("x86_64-x86_64-freebsd-gnu") X86_64UnknownHaiku|Some("x86_64-x86_64-haiku-gnu") X86_64UnknownHermit|Some("x86_64-x86_64-hermit-eabi") X86_64UnknownL4reUclibc|None X86_64UnknownNetbsd|Some("x86_64-x86_64-netbsd-gnu") X86_64UnknownOpenbsd|Some("x86_64-x86_64-openbsd-gnu") X86_64UnknownRedox|None 
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
_Static_assert(sizeof(BA) == 0, "");
_Static_assert(_Alignof(BA) == 1, "");
_Static_assert(sizeof(struct BA_extra_alignment) == 1, "");
_Static_assert(_Alignof(struct BA_extra_alignment) == 1, "");
_Static_assert(sizeof(struct BA_extra_packed) == 0, "");
_Static_assert(_Alignof(struct BA_extra_packed) == 1, "");
_Static_assert(sizeof(struct BA_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct BA_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct BA_extra_size) == 2, "");
_Static_assert(_Alignof(struct BA_extra_size) == 1, "");
_Static_assert(sizeof(BB) == 0, "");
_Static_assert(_Alignof(BB) == 1, "");
_Static_assert(sizeof(struct BB_extra_alignment) == 1, "");
_Static_assert(_Alignof(struct BB_extra_alignment) == 1, "");
_Static_assert(sizeof(struct BB_extra_packed) == 0, "");
_Static_assert(_Alignof(struct BB_extra_packed) == 1, "");
_Static_assert(sizeof(struct BB_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct BB_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct BB_extra_size) == 2, "");
_Static_assert(_Alignof(struct BB_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(BB,a) == 0, "");
#endif
_Static_assert(sizeof(BC) == 0, "");
_Static_assert(_Alignof(BC) == 1, "");
_Static_assert(sizeof(struct BC_extra_alignment) == 1, "");
_Static_assert(_Alignof(struct BC_extra_alignment) == 1, "");
_Static_assert(sizeof(struct BC_extra_packed) == 0, "");
_Static_assert(_Alignof(struct BC_extra_packed) == 1, "");
_Static_assert(sizeof(struct BC_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct BC_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct BC_extra_size) == 2, "");
_Static_assert(_Alignof(struct BC_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
#endif
_Static_assert(sizeof(BD) == 0, "");
_Static_assert(_Alignof(BD) == 16, "");
_Static_assert(sizeof(struct BD_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct BD_extra_alignment) == 16, "");
_Static_assert(sizeof(struct BD_extra_packed) == 0, "");
_Static_assert(_Alignof(struct BD_extra_packed) == 1, "");
_Static_assert(sizeof(struct BD_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct BD_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct BD_extra_size) == 2, "");
_Static_assert(_Alignof(struct BD_extra_size) == 1, "");
_Static_assert(sizeof(BE) == 0, "");
_Static_assert(_Alignof(BE) == 2, "");
_Static_assert(sizeof(struct BE_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct BE_extra_alignment) == 2, "");
_Static_assert(sizeof(struct BE_extra_packed) == 0, "");
_Static_assert(_Alignof(struct BE_extra_packed) == 1, "");
_Static_assert(sizeof(struct BE_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct BE_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct BE_extra_size) == 2, "");
_Static_assert(_Alignof(struct BE_extra_size) == 1, "");
_Static_assert(sizeof(C) == 1, "");
_Static_assert(_Alignof(C) == 8, "");
_Static_assert(sizeof(struct C_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct C_extra_alignment) == 8, "");
_Static_assert(sizeof(struct C_extra_packed) == 1, "");
_Static_assert(_Alignof(struct C_extra_packed) == 1, "");
_Static_assert(sizeof(struct C_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct C_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct C_extra_size) == 3, "");
_Static_assert(_Alignof(struct C_extra_size) == 1, "");
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
_Static_assert(sizeof(E) == 0, "");
_Static_assert(_Alignof(E) == 1, "");
_Static_assert(sizeof(struct E_extra_alignment) == 1, "");
_Static_assert(_Alignof(struct E_extra_alignment) == 1, "");
_Static_assert(sizeof(struct E_extra_packed) == 0, "");
_Static_assert(_Alignof(struct E_extra_packed) == 1, "");
_Static_assert(sizeof(struct E_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct E_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct E_extra_size) == 2, "");
_Static_assert(_Alignof(struct E_extra_size) == 1, "");
_Static_assert(sizeof(F) == 0, "");
_Static_assert(_Alignof(F) == 1, "");
_Static_assert(sizeof(struct F_extra_alignment) == 1, "");
_Static_assert(_Alignof(struct F_extra_alignment) == 1, "");
_Static_assert(sizeof(struct F_extra_packed) == 0, "");
_Static_assert(_Alignof(struct F_extra_packed) == 1, "");
_Static_assert(sizeof(struct F_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct F_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct F_extra_size) == 2, "");
_Static_assert(_Alignof(struct F_extra_size) == 1, "");
_Static_assert(sizeof(G) == 0, "");
_Static_assert(_Alignof(G) == 1, "");
_Static_assert(sizeof(struct G_extra_alignment) == 1, "");
_Static_assert(_Alignof(struct G_extra_alignment) == 1, "");
_Static_assert(sizeof(struct G_extra_packed) == 0, "");
_Static_assert(_Alignof(struct G_extra_packed) == 1, "");
_Static_assert(sizeof(struct G_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct G_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct G_extra_size) == 2, "");
_Static_assert(_Alignof(struct G_extra_size) == 1, "");
_Static_assert(sizeof(H) == 0, "");
_Static_assert(_Alignof(H) == 1, "");
_Static_assert(sizeof(struct H_extra_alignment) == 1, "");
_Static_assert(_Alignof(struct H_extra_alignment) == 1, "");
_Static_assert(sizeof(struct H_extra_packed) == 0, "");
_Static_assert(_Alignof(struct H_extra_packed) == 1, "");
_Static_assert(sizeof(struct H_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct H_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct H_extra_size) == 2, "");
_Static_assert(_Alignof(struct H_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
#endif
_Static_assert(sizeof(I) == 0, "");
_Static_assert(_Alignof(I) == 1, "");
_Static_assert(sizeof(struct I_extra_alignment) == 1, "");
_Static_assert(_Alignof(struct I_extra_alignment) == 1, "");
_Static_assert(sizeof(struct I_extra_packed) == 0, "");
_Static_assert(_Alignof(struct I_extra_packed) == 1, "");
_Static_assert(sizeof(struct I_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct I_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct I_extra_size) == 2, "");
_Static_assert(_Alignof(struct I_extra_size) == 1, "");
// MAPPING|TWO|aarch64-generic-fuchsia-gnu:Clang|aarch64-generic-linux-android:Clang|aarch64-generic-freebsd-gnu:Clang|aarch64-generic-hermit-eabi:Clang|aarch64-generic-netbsd-gnu:Clang|aarch64-generic-other-eabi:Clang|aarch64-generic-openbsd-gnu:Clang|arm-baseline-other-eabi:Clang|arm-baseline-other-eabihf:Clang|arm-arm1136j_s-freebsd-gnueabihf:Clang|arm-arm1136j_s-netbsd-eabihf:Clang|arm-baseline-other-eabi:Clang|arm-baseline-other-eabihf:Clang|arm-cortex_r4-linux-android:Clang|arm-cortex_r4-other-eabi:Clang|arm-cortex_r4-other-eabihf:Clang|arm-cortex_r4-freebsd-gnueabihf:Clang|arm-cortex_r4-netbsd-eabihf:Clang|thumb-arm710t-other-eabi:Clang|thumb-cortex_m0-other-eabi:Clang|thumb-cortex_m4-other-eabihf:Clang|thumb-cortex_m4-other-eabi:Clang|thumb-cortex_m3-other-eabi:Clang|thumb-baseline-other-eabi:Clang|thumb-cortex_m33-other-eabihf:Clang|thumb-cortex_m33-other-eabi:Clang|END
// repr targets Aarch64Fuchsia|Some("aarch64-generic-fuchsia-gnu") Aarch64LinuxAndroid|Some("aarch64-generic-linux-android") Aarch64UnknownFreebsd|Some("aarch64-generic-freebsd-gnu") Aarch64UnknownHermit|Some("aarch64-generic-hermit-eabi") Aarch64UnknownNetbsd|Some("aarch64-generic-netbsd-gnu") Aarch64UnknownNone|Some("aarch64-generic-other-eabi") Aarch64UnknownOpenbsd|Some("aarch64-generic-openbsd-gnu") Aarch64UnknownRedox|None Armebv7rUnknownNoneEabi|Some("arm-baseline-other-eabi") Armebv7rUnknownNoneEabihf|Some("arm-baseline-other-eabihf") ArmLinuxAndroideabi|None Armv6UnknownFreebsdGnueabihf|Some("arm-arm1136j_s-freebsd-gnueabihf") Armv6UnknownNetbsdelfEabihf|Some("arm-arm1136j_s-netbsd-eabihf") Armv7aNoneEabi|Some("arm-baseline-other-eabi") Armv7aNoneEabihf|Some("arm-baseline-other-eabihf") Armv7NoneLinuxAndroid|Some("arm-cortex_r4-linux-android") Armv7rUnknownNoneEabi|Some("arm-cortex_r4-other-eabi") Armv7rUnknownNoneEabihf|Some("arm-cortex_r4-other-eabihf") Armv7UnknownFreebsdGnueabihf|Some("arm-cortex_r4-freebsd-gnueabihf") Armv7UnknownNetbsdelfEabihf|Some("arm-cortex_r4-netbsd-eabihf") Thumbv4tNoneEabi|Some("thumb-arm710t-other-eabi") Thumbv6mNoneEabi|Some("thumb-cortex_m0-other-eabi") Thumbv7emNoneEabihf|Some("thumb-cortex_m4-other-eabihf") Thumbv7emNoneEabi|Some("thumb-cortex_m4-other-eabi") Thumbv7mNoneEabi|Some("thumb-cortex_m3-other-eabi") Thumbv8mBaseNoneEabi|Some("thumb-baseline-other-eabi") Thumbv8mMainNoneEabihf|Some("thumb-cortex_m33-other-eabihf") Thumbv8mMainNoneEabi|Some("thumb-cortex_m33-other-eabi") 
#elif defined(TWO)
_Static_assert(sizeof(A) == 4, "");
_Static_assert(_Alignof(A) == 4, "");
_Static_assert(sizeof(struct A_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct A_extra_alignment) == 4, "");
_Static_assert(sizeof(struct A_extra_packed) == 4, "");
_Static_assert(_Alignof(struct A_extra_packed) == 1, "");
_Static_assert(sizeof(struct A_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct A_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A_extra_size) == 6, "");
_Static_assert(_Alignof(struct A_extra_size) == 1, "");
_Static_assert(sizeof(BA) == 0, "");
_Static_assert(_Alignof(BA) == 4, "");
_Static_assert(sizeof(struct BA_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct BA_extra_alignment) == 4, "");
_Static_assert(sizeof(struct BA_extra_packed) == 0, "");
_Static_assert(_Alignof(struct BA_extra_packed) == 1, "");
_Static_assert(sizeof(struct BA_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct BA_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct BA_extra_size) == 2, "");
_Static_assert(_Alignof(struct BA_extra_size) == 1, "");
_Static_assert(sizeof(BB) == 0, "");
_Static_assert(_Alignof(BB) == 16, "");
_Static_assert(sizeof(struct BB_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct BB_extra_alignment) == 16, "");
_Static_assert(sizeof(struct BB_extra_packed) == 0, "");
_Static_assert(_Alignof(struct BB_extra_packed) == 1, "");
_Static_assert(sizeof(struct BB_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct BB_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct BB_extra_size) == 2, "");
_Static_assert(_Alignof(struct BB_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(BB,a) == 0, "");
#endif
_Static_assert(sizeof(BC) == 0, "");
_Static_assert(_Alignof(BC) == 16, "");
_Static_assert(sizeof(struct BC_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct BC_extra_alignment) == 16, "");
_Static_assert(sizeof(struct BC_extra_packed) == 0, "");
_Static_assert(_Alignof(struct BC_extra_packed) == 1, "");
_Static_assert(sizeof(struct BC_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct BC_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct BC_extra_size) == 2, "");
_Static_assert(_Alignof(struct BC_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
#endif
_Static_assert(sizeof(BD) == 0, "");
_Static_assert(_Alignof(BD) == 16, "");
_Static_assert(sizeof(struct BD_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct BD_extra_alignment) == 16, "");
_Static_assert(sizeof(struct BD_extra_packed) == 0, "");
_Static_assert(_Alignof(struct BD_extra_packed) == 1, "");
_Static_assert(sizeof(struct BD_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct BD_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct BD_extra_size) == 2, "");
_Static_assert(_Alignof(struct BD_extra_size) == 1, "");
_Static_assert(sizeof(BE) == 0, "");
_Static_assert(_Alignof(BE) == 4, "");
_Static_assert(sizeof(struct BE_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct BE_extra_alignment) == 4, "");
_Static_assert(sizeof(struct BE_extra_packed) == 0, "");
_Static_assert(_Alignof(struct BE_extra_packed) == 1, "");
_Static_assert(sizeof(struct BE_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct BE_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct BE_extra_size) == 2, "");
_Static_assert(_Alignof(struct BE_extra_size) == 1, "");
_Static_assert(sizeof(C) == 1, "");
_Static_assert(_Alignof(C) == 8, "");
_Static_assert(sizeof(struct C_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct C_extra_alignment) == 8, "");
_Static_assert(sizeof(struct C_extra_packed) == 1, "");
_Static_assert(_Alignof(struct C_extra_packed) == 1, "");
_Static_assert(sizeof(struct C_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct C_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct C_extra_size) == 3, "");
_Static_assert(_Alignof(struct C_extra_size) == 1, "");
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
_Static_assert(sizeof(E) == 0, "");
_Static_assert(_Alignof(E) == 1, "");
_Static_assert(sizeof(struct E_extra_alignment) == 1, "");
_Static_assert(_Alignof(struct E_extra_alignment) == 1, "");
_Static_assert(sizeof(struct E_extra_packed) == 0, "");
_Static_assert(_Alignof(struct E_extra_packed) == 1, "");
_Static_assert(sizeof(struct E_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct E_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct E_extra_size) == 2, "");
_Static_assert(_Alignof(struct E_extra_size) == 1, "");
_Static_assert(sizeof(F) == 0, "");
_Static_assert(_Alignof(F) == 4, "");
_Static_assert(sizeof(struct F_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct F_extra_alignment) == 4, "");
_Static_assert(sizeof(struct F_extra_packed) == 0, "");
_Static_assert(_Alignof(struct F_extra_packed) == 1, "");
_Static_assert(sizeof(struct F_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct F_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct F_extra_size) == 2, "");
_Static_assert(_Alignof(struct F_extra_size) == 1, "");
_Static_assert(sizeof(G) == 0, "");
_Static_assert(_Alignof(G) == 8, "");
_Static_assert(sizeof(struct G_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct G_extra_alignment) == 8, "");
_Static_assert(sizeof(struct G_extra_packed) == 0, "");
_Static_assert(_Alignof(struct G_extra_packed) == 1, "");
_Static_assert(sizeof(struct G_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct G_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct G_extra_size) == 2, "");
_Static_assert(_Alignof(struct G_extra_size) == 1, "");
_Static_assert(sizeof(H) == 0, "");
_Static_assert(_Alignof(H) == 8, "");
_Static_assert(sizeof(struct H_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct H_extra_alignment) == 8, "");
_Static_assert(sizeof(struct H_extra_packed) == 0, "");
_Static_assert(_Alignof(struct H_extra_packed) == 1, "");
_Static_assert(sizeof(struct H_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct H_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct H_extra_size) == 2, "");
_Static_assert(_Alignof(struct H_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
#endif
_Static_assert(sizeof(I) == 0, "");
_Static_assert(_Alignof(I) == 1, "");
_Static_assert(sizeof(struct I_extra_alignment) == 1, "");
_Static_assert(_Alignof(struct I_extra_alignment) == 1, "");
_Static_assert(sizeof(struct I_extra_packed) == 0, "");
_Static_assert(_Alignof(struct I_extra_packed) == 1, "");
_Static_assert(sizeof(struct I_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct I_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct I_extra_size) == 2, "");
_Static_assert(_Alignof(struct I_extra_size) == 1, "");
// MAPPING|THREE|aarch64-generic-windows-msvc:Msvc|i386-i586-windows-msvc:Msvc|i386-i686-windows-msvc:Msvc|i386-i686-uefi-msvc:Msvc|thumb-baseline-windows-msvc:Msvc|x86_64-x86_64-windows-msvc:Msvc|x86_64-x86_64-uefi-msvc:Msvc|END
// repr targets Aarch64PcWindowsMsvc|Some("aarch64-generic-windows-msvc") I586PcWindowsMsvc|Some("i386-i586-windows-msvc") I686PcWindowsMsvc|Some("i386-i686-windows-msvc") I686UnknownWindows|Some("i386-i686-uefi-msvc") Thumbv7aPcWindowsMsvc|Some("thumb-baseline-windows-msvc") X86_64PcWindowsMsvc|Some("x86_64-x86_64-windows-msvc") X86_64UnknownWindows|Some("x86_64-x86_64-uefi-msvc") 
#elif defined(THREE)
_Static_assert(sizeof(A) == 4, "");
_Static_assert(_Alignof(A) == 8, "");
_Static_assert(sizeof(struct A_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct A_extra_alignment) == 8, "");
_Static_assert(sizeof(struct A_extra_packed) == 4, "");
_Static_assert(_Alignof(struct A_extra_packed) == 1, "");
_Static_assert(sizeof(struct A_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct A_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A_extra_size) == 6, "");
_Static_assert(_Alignof(struct A_extra_size) == 1, "");
_Static_assert(sizeof(BA) == 8, "");
_Static_assert(_Alignof(BA) == 8, "");
_Static_assert(sizeof(struct BA_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct BA_extra_alignment) == 8, "");
_Static_assert(sizeof(struct BA_extra_packed) == 8, "");
_Static_assert(_Alignof(struct BA_extra_packed) == 1, "");
_Static_assert(sizeof(struct BA_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct BA_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct BA_extra_size) == 10, "");
_Static_assert(_Alignof(struct BA_extra_size) == 1, "");
_Static_assert(sizeof(BB) == 8, "");
_Static_assert(_Alignof(BB) == 8, "");
_Static_assert(sizeof(struct BB_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct BB_extra_alignment) == 8, "");
_Static_assert(sizeof(struct BB_extra_packed) == 8, "");
_Static_assert(_Alignof(struct BB_extra_packed) == 1, "");
_Static_assert(sizeof(struct BB_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct BB_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct BB_extra_size) == 10, "");
_Static_assert(_Alignof(struct BB_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(BB,a) == 0, "");
#endif
_Static_assert(sizeof(BC) == 8, "");
_Static_assert(_Alignof(BC) == 8, "");
_Static_assert(sizeof(struct BC_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct BC_extra_alignment) == 8, "");
_Static_assert(sizeof(struct BC_extra_packed) == 8, "");
_Static_assert(_Alignof(struct BC_extra_packed) == 1, "");
_Static_assert(sizeof(struct BC_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct BC_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct BC_extra_size) == 10, "");
_Static_assert(_Alignof(struct BC_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
#endif
_Static_assert(sizeof(BD) == 16, "");
_Static_assert(_Alignof(BD) == 16, "");
_Static_assert(sizeof(struct BD_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct BD_extra_alignment) == 16, "");
_Static_assert(sizeof(struct BD_extra_packed) == 16, "");
_Static_assert(_Alignof(struct BD_extra_packed) == 1, "");
_Static_assert(sizeof(struct BD_extra_required_alignment) == 17, "");
_Static_assert(_Alignof(struct BD_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct BD_extra_size) == 18, "");
_Static_assert(_Alignof(struct BD_extra_size) == 1, "");
_Static_assert(sizeof(BE) == 8, "");
_Static_assert(_Alignof(BE) == 8, "");
_Static_assert(sizeof(struct BE_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct BE_extra_alignment) == 8, "");
_Static_assert(sizeof(struct BE_extra_packed) == 8, "");
_Static_assert(_Alignof(struct BE_extra_packed) == 1, "");
_Static_assert(sizeof(struct BE_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct BE_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct BE_extra_size) == 10, "");
_Static_assert(_Alignof(struct BE_extra_size) == 1, "");
_Static_assert(sizeof(C) == 1, "");
_Static_assert(_Alignof(C) == 8, "");
_Static_assert(sizeof(struct C_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct C_extra_alignment) == 8, "");
_Static_assert(sizeof(struct C_extra_packed) == 1, "");
_Static_assert(_Alignof(struct C_extra_packed) == 1, "");
_Static_assert(sizeof(struct C_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct C_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct C_extra_size) == 3, "");
_Static_assert(_Alignof(struct C_extra_size) == 1, "");
_Static_assert(sizeof(D) == 8, "");
_Static_assert(_Alignof(D) == 8, "");
_Static_assert(sizeof(struct D_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct D_extra_alignment) == 8, "");
_Static_assert(sizeof(struct D_extra_packed) == 8, "");
_Static_assert(_Alignof(struct D_extra_packed) == 1, "");
_Static_assert(sizeof(struct D_extra_required_alignment) == 9, "");
_Static_assert(_Alignof(struct D_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct D_extra_size) == 10, "");
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
#ifndef SKIP_OFFSETS
#endif
_Static_assert(sizeof(I) == 1, "");
_Static_assert(_Alignof(I) == 1, "");
_Static_assert(sizeof(struct I_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct I_extra_alignment) == 1, "");
_Static_assert(sizeof(struct I_extra_packed) == 1, "");
_Static_assert(_Alignof(struct I_extra_packed) == 1, "");
_Static_assert(sizeof(struct I_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct I_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct I_extra_size) == 3, "");
_Static_assert(_Alignof(struct I_extra_size) == 1, "");
// MAPPING|FOUR|arm-cortex_r4-ios-none:Clang|arm-baseline-ios-none:Clang|END
// repr targets Armv7AppleIos|Some("arm-cortex_r4-ios-none") Armv7sAppleIos|Some("arm-baseline-ios-none") 
#elif defined(FOUR)
_Static_assert(sizeof(A) == 4, "");
_Static_assert(_Alignof(A) == 4, "");
_Static_assert(sizeof(struct A_extra_alignment) == 8, "");
_Static_assert(_Alignof(struct A_extra_alignment) == 4, "");
_Static_assert(sizeof(struct A_extra_packed) == 4, "");
_Static_assert(_Alignof(struct A_extra_packed) == 1, "");
_Static_assert(sizeof(struct A_extra_required_alignment) == 5, "");
_Static_assert(_Alignof(struct A_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct A_extra_size) == 6, "");
_Static_assert(_Alignof(struct A_extra_size) == 1, "");
_Static_assert(sizeof(BA) == 0, "");
_Static_assert(_Alignof(BA) == 4, "");
_Static_assert(sizeof(struct BA_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct BA_extra_alignment) == 4, "");
_Static_assert(sizeof(struct BA_extra_packed) == 0, "");
_Static_assert(_Alignof(struct BA_extra_packed) == 1, "");
_Static_assert(sizeof(struct BA_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct BA_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct BA_extra_size) == 2, "");
_Static_assert(_Alignof(struct BA_extra_size) == 1, "");
_Static_assert(sizeof(BB) == 0, "");
_Static_assert(_Alignof(BB) == 16, "");
_Static_assert(sizeof(struct BB_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct BB_extra_alignment) == 16, "");
_Static_assert(sizeof(struct BB_extra_packed) == 0, "");
_Static_assert(_Alignof(struct BB_extra_packed) == 1, "");
_Static_assert(sizeof(struct BB_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct BB_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct BB_extra_size) == 2, "");
_Static_assert(_Alignof(struct BB_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(BB,a) == 0, "");
#endif
_Static_assert(sizeof(BC) == 0, "");
_Static_assert(_Alignof(BC) == 16, "");
_Static_assert(sizeof(struct BC_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct BC_extra_alignment) == 16, "");
_Static_assert(sizeof(struct BC_extra_packed) == 0, "");
_Static_assert(_Alignof(struct BC_extra_packed) == 1, "");
_Static_assert(sizeof(struct BC_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct BC_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct BC_extra_size) == 2, "");
_Static_assert(_Alignof(struct BC_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
#endif
_Static_assert(sizeof(BD) == 0, "");
_Static_assert(_Alignof(BD) == 16, "");
_Static_assert(sizeof(struct BD_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct BD_extra_alignment) == 16, "");
_Static_assert(sizeof(struct BD_extra_packed) == 0, "");
_Static_assert(_Alignof(struct BD_extra_packed) == 1, "");
_Static_assert(sizeof(struct BD_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct BD_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct BD_extra_size) == 2, "");
_Static_assert(_Alignof(struct BD_extra_size) == 1, "");
_Static_assert(sizeof(BE) == 0, "");
_Static_assert(_Alignof(BE) == 4, "");
_Static_assert(sizeof(struct BE_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct BE_extra_alignment) == 4, "");
_Static_assert(sizeof(struct BE_extra_packed) == 0, "");
_Static_assert(_Alignof(struct BE_extra_packed) == 1, "");
_Static_assert(sizeof(struct BE_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct BE_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct BE_extra_size) == 2, "");
_Static_assert(_Alignof(struct BE_extra_size) == 1, "");
_Static_assert(sizeof(C) == 1, "");
_Static_assert(_Alignof(C) == 8, "");
_Static_assert(sizeof(struct C_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct C_extra_alignment) == 8, "");
_Static_assert(sizeof(struct C_extra_packed) == 1, "");
_Static_assert(_Alignof(struct C_extra_packed) == 1, "");
_Static_assert(sizeof(struct C_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct C_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct C_extra_size) == 3, "");
_Static_assert(_Alignof(struct C_extra_size) == 1, "");
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
_Static_assert(sizeof(E) == 0, "");
_Static_assert(_Alignof(E) == 4, "");
_Static_assert(sizeof(struct E_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct E_extra_alignment) == 4, "");
_Static_assert(sizeof(struct E_extra_packed) == 0, "");
_Static_assert(_Alignof(struct E_extra_packed) == 1, "");
_Static_assert(sizeof(struct E_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct E_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct E_extra_size) == 2, "");
_Static_assert(_Alignof(struct E_extra_size) == 1, "");
_Static_assert(sizeof(F) == 0, "");
_Static_assert(_Alignof(F) == 4, "");
_Static_assert(sizeof(struct F_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct F_extra_alignment) == 4, "");
_Static_assert(sizeof(struct F_extra_packed) == 0, "");
_Static_assert(_Alignof(struct F_extra_packed) == 1, "");
_Static_assert(sizeof(struct F_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct F_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct F_extra_size) == 2, "");
_Static_assert(_Alignof(struct F_extra_size) == 1, "");
_Static_assert(sizeof(G) == 0, "");
_Static_assert(_Alignof(G) == 4, "");
_Static_assert(sizeof(struct G_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct G_extra_alignment) == 4, "");
_Static_assert(sizeof(struct G_extra_packed) == 0, "");
_Static_assert(_Alignof(struct G_extra_packed) == 1, "");
_Static_assert(sizeof(struct G_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct G_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct G_extra_size) == 2, "");
_Static_assert(_Alignof(struct G_extra_size) == 1, "");
_Static_assert(sizeof(H) == 0, "");
_Static_assert(_Alignof(H) == 4, "");
_Static_assert(sizeof(struct H_extra_alignment) == 4, "");
_Static_assert(_Alignof(struct H_extra_alignment) == 4, "");
_Static_assert(sizeof(struct H_extra_packed) == 0, "");
_Static_assert(_Alignof(struct H_extra_packed) == 1, "");
_Static_assert(sizeof(struct H_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct H_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct H_extra_size) == 2, "");
_Static_assert(_Alignof(struct H_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
#endif
_Static_assert(sizeof(I) == 0, "");
_Static_assert(_Alignof(I) == 1, "");
_Static_assert(sizeof(struct I_extra_alignment) == 1, "");
_Static_assert(_Alignof(struct I_extra_alignment) == 1, "");
_Static_assert(sizeof(struct I_extra_packed) == 0, "");
_Static_assert(_Alignof(struct I_extra_packed) == 1, "");
_Static_assert(sizeof(struct I_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct I_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct I_extra_size) == 2, "");
_Static_assert(_Alignof(struct I_extra_size) == 1, "");
// MAPPING|FIVE|i386-i386-ios-none:Clang|i386-i686-macos-none:Clang|i386-i686-linux-android:Clang|i386-i686-freebsd-gnu:Clang|i386-i686-haiku-gnu:Clang|i386-i686-netbsd-gnu:Clang|i386-i686-openbsd-gnu:Clang|END
// repr targets I386AppleIos|Some("i386-i386-ios-none") I686AppleMacosx|Some("i386-i686-macos-none") I686LinuxAndroid|Some("i386-i686-linux-android") I686UnknownFreebsd|Some("i386-i686-freebsd-gnu") I686UnknownHaiku|Some("i386-i686-haiku-gnu") I686UnknownNetbsdelf|Some("i386-i686-netbsd-gnu") I686UnknownOpenbsd|Some("i386-i686-openbsd-gnu") 
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
_Static_assert(sizeof(BA) == 0, "");
_Static_assert(_Alignof(BA) == 1, "");
_Static_assert(sizeof(struct BA_extra_alignment) == 1, "");
_Static_assert(_Alignof(struct BA_extra_alignment) == 1, "");
_Static_assert(sizeof(struct BA_extra_packed) == 0, "");
_Static_assert(_Alignof(struct BA_extra_packed) == 1, "");
_Static_assert(sizeof(struct BA_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct BA_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct BA_extra_size) == 2, "");
_Static_assert(_Alignof(struct BA_extra_size) == 1, "");
_Static_assert(sizeof(BB) == 0, "");
_Static_assert(_Alignof(BB) == 1, "");
_Static_assert(sizeof(struct BB_extra_alignment) == 1, "");
_Static_assert(_Alignof(struct BB_extra_alignment) == 1, "");
_Static_assert(sizeof(struct BB_extra_packed) == 0, "");
_Static_assert(_Alignof(struct BB_extra_packed) == 1, "");
_Static_assert(sizeof(struct BB_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct BB_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct BB_extra_size) == 2, "");
_Static_assert(_Alignof(struct BB_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(BB,a) == 0, "");
#endif
_Static_assert(sizeof(BC) == 0, "");
_Static_assert(_Alignof(BC) == 1, "");
_Static_assert(sizeof(struct BC_extra_alignment) == 1, "");
_Static_assert(_Alignof(struct BC_extra_alignment) == 1, "");
_Static_assert(sizeof(struct BC_extra_packed) == 0, "");
_Static_assert(_Alignof(struct BC_extra_packed) == 1, "");
_Static_assert(sizeof(struct BC_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct BC_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct BC_extra_size) == 2, "");
_Static_assert(_Alignof(struct BC_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
#endif
_Static_assert(sizeof(BD) == 0, "");
_Static_assert(_Alignof(BD) == 16, "");
_Static_assert(sizeof(struct BD_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct BD_extra_alignment) == 16, "");
_Static_assert(sizeof(struct BD_extra_packed) == 0, "");
_Static_assert(_Alignof(struct BD_extra_packed) == 1, "");
_Static_assert(sizeof(struct BD_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct BD_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct BD_extra_size) == 2, "");
_Static_assert(_Alignof(struct BD_extra_size) == 1, "");
_Static_assert(sizeof(BE) == 0, "");
_Static_assert(_Alignof(BE) == 2, "");
_Static_assert(sizeof(struct BE_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct BE_extra_alignment) == 2, "");
_Static_assert(sizeof(struct BE_extra_packed) == 0, "");
_Static_assert(_Alignof(struct BE_extra_packed) == 1, "");
_Static_assert(sizeof(struct BE_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct BE_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct BE_extra_size) == 2, "");
_Static_assert(_Alignof(struct BE_extra_size) == 1, "");
_Static_assert(sizeof(C) == 1, "");
_Static_assert(_Alignof(C) == 8, "");
_Static_assert(sizeof(struct C_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct C_extra_alignment) == 8, "");
_Static_assert(sizeof(struct C_extra_packed) == 1, "");
_Static_assert(_Alignof(struct C_extra_packed) == 1, "");
_Static_assert(sizeof(struct C_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct C_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct C_extra_size) == 3, "");
_Static_assert(_Alignof(struct C_extra_size) == 1, "");
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
_Static_assert(sizeof(E) == 0, "");
_Static_assert(_Alignof(E) == 1, "");
_Static_assert(sizeof(struct E_extra_alignment) == 1, "");
_Static_assert(_Alignof(struct E_extra_alignment) == 1, "");
_Static_assert(sizeof(struct E_extra_packed) == 0, "");
_Static_assert(_Alignof(struct E_extra_packed) == 1, "");
_Static_assert(sizeof(struct E_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct E_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct E_extra_size) == 2, "");
_Static_assert(_Alignof(struct E_extra_size) == 1, "");
_Static_assert(sizeof(F) == 0, "");
_Static_assert(_Alignof(F) == 1, "");
_Static_assert(sizeof(struct F_extra_alignment) == 1, "");
_Static_assert(_Alignof(struct F_extra_alignment) == 1, "");
_Static_assert(sizeof(struct F_extra_packed) == 0, "");
_Static_assert(_Alignof(struct F_extra_packed) == 1, "");
_Static_assert(sizeof(struct F_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct F_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct F_extra_size) == 2, "");
_Static_assert(_Alignof(struct F_extra_size) == 1, "");
_Static_assert(sizeof(G) == 0, "");
_Static_assert(_Alignof(G) == 1, "");
_Static_assert(sizeof(struct G_extra_alignment) == 1, "");
_Static_assert(_Alignof(struct G_extra_alignment) == 1, "");
_Static_assert(sizeof(struct G_extra_packed) == 0, "");
_Static_assert(_Alignof(struct G_extra_packed) == 1, "");
_Static_assert(sizeof(struct G_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct G_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct G_extra_size) == 2, "");
_Static_assert(_Alignof(struct G_extra_size) == 1, "");
_Static_assert(sizeof(H) == 0, "");
_Static_assert(_Alignof(H) == 1, "");
_Static_assert(sizeof(struct H_extra_alignment) == 1, "");
_Static_assert(_Alignof(struct H_extra_alignment) == 1, "");
_Static_assert(sizeof(struct H_extra_packed) == 0, "");
_Static_assert(_Alignof(struct H_extra_packed) == 1, "");
_Static_assert(sizeof(struct H_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct H_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct H_extra_size) == 2, "");
_Static_assert(_Alignof(struct H_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
#endif
_Static_assert(sizeof(I) == 0, "");
_Static_assert(_Alignof(I) == 1, "");
_Static_assert(sizeof(struct I_extra_alignment) == 1, "");
_Static_assert(_Alignof(struct I_extra_alignment) == 1, "");
_Static_assert(sizeof(struct I_extra_packed) == 0, "");
_Static_assert(_Alignof(struct I_extra_packed) == 1, "");
_Static_assert(sizeof(struct I_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct I_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct I_extra_size) == 2, "");
_Static_assert(_Alignof(struct I_extra_size) == 1, "");
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
_Static_assert(sizeof(BA) == 0, "");
_Static_assert(_Alignof(BA) == 1, "");
_Static_assert(sizeof(struct BA_extra_alignment) == 1, "");
_Static_assert(_Alignof(struct BA_extra_alignment) == 1, "");
_Static_assert(sizeof(struct BA_extra_packed) == 0, "");
_Static_assert(_Alignof(struct BA_extra_packed) == 1, "");
_Static_assert(sizeof(struct BA_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct BA_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct BA_extra_size) == 2, "");
_Static_assert(_Alignof(struct BA_extra_size) == 1, "");
_Static_assert(sizeof(BB) == 0, "");
_Static_assert(_Alignof(BB) == 1, "");
_Static_assert(sizeof(struct BB_extra_alignment) == 1, "");
_Static_assert(_Alignof(struct BB_extra_alignment) == 1, "");
_Static_assert(sizeof(struct BB_extra_packed) == 0, "");
_Static_assert(_Alignof(struct BB_extra_packed) == 1, "");
_Static_assert(sizeof(struct BB_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct BB_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct BB_extra_size) == 2, "");
_Static_assert(_Alignof(struct BB_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(BB,a) == 0, "");
#endif
_Static_assert(sizeof(BC) == 0, "");
_Static_assert(_Alignof(BC) == 1, "");
_Static_assert(sizeof(struct BC_extra_alignment) == 1, "");
_Static_assert(_Alignof(struct BC_extra_alignment) == 1, "");
_Static_assert(sizeof(struct BC_extra_packed) == 0, "");
_Static_assert(_Alignof(struct BC_extra_packed) == 1, "");
_Static_assert(sizeof(struct BC_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct BC_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct BC_extra_size) == 2, "");
_Static_assert(_Alignof(struct BC_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
#endif
_Static_assert(sizeof(BD) == 0, "");
_Static_assert(_Alignof(BD) == 16, "");
_Static_assert(sizeof(struct BD_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct BD_extra_alignment) == 16, "");
_Static_assert(sizeof(struct BD_extra_packed) == 0, "");
_Static_assert(_Alignof(struct BD_extra_packed) == 1, "");
_Static_assert(sizeof(struct BD_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct BD_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct BD_extra_size) == 2, "");
_Static_assert(_Alignof(struct BD_extra_size) == 1, "");
_Static_assert(sizeof(BE) == 0, "");
_Static_assert(_Alignof(BE) == 2, "");
_Static_assert(sizeof(struct BE_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct BE_extra_alignment) == 2, "");
_Static_assert(sizeof(struct BE_extra_packed) == 0, "");
_Static_assert(_Alignof(struct BE_extra_packed) == 1, "");
_Static_assert(sizeof(struct BE_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct BE_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct BE_extra_size) == 2, "");
_Static_assert(_Alignof(struct BE_extra_size) == 1, "");
_Static_assert(sizeof(C) == 1, "");
_Static_assert(_Alignof(C) == 8, "");
_Static_assert(sizeof(struct C_extra_alignment) == 16, "");
_Static_assert(_Alignof(struct C_extra_alignment) == 8, "");
_Static_assert(sizeof(struct C_extra_packed) == 1, "");
_Static_assert(_Alignof(struct C_extra_packed) == 1, "");
_Static_assert(sizeof(struct C_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct C_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct C_extra_size) == 3, "");
_Static_assert(_Alignof(struct C_extra_size) == 1, "");
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
_Static_assert(sizeof(E) == 0, "");
_Static_assert(_Alignof(E) == 1, "");
_Static_assert(sizeof(struct E_extra_alignment) == 1, "");
_Static_assert(_Alignof(struct E_extra_alignment) == 1, "");
_Static_assert(sizeof(struct E_extra_packed) == 0, "");
_Static_assert(_Alignof(struct E_extra_packed) == 1, "");
_Static_assert(sizeof(struct E_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct E_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct E_extra_size) == 2, "");
_Static_assert(_Alignof(struct E_extra_size) == 1, "");
_Static_assert(sizeof(F) == 0, "");
_Static_assert(_Alignof(F) == 1, "");
_Static_assert(sizeof(struct F_extra_alignment) == 1, "");
_Static_assert(_Alignof(struct F_extra_alignment) == 1, "");
_Static_assert(sizeof(struct F_extra_packed) == 0, "");
_Static_assert(_Alignof(struct F_extra_packed) == 1, "");
_Static_assert(sizeof(struct F_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct F_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct F_extra_size) == 2, "");
_Static_assert(_Alignof(struct F_extra_size) == 1, "");
_Static_assert(sizeof(G) == 0, "");
_Static_assert(_Alignof(G) == 1, "");
_Static_assert(sizeof(struct G_extra_alignment) == 1, "");
_Static_assert(_Alignof(struct G_extra_alignment) == 1, "");
_Static_assert(sizeof(struct G_extra_packed) == 0, "");
_Static_assert(_Alignof(struct G_extra_packed) == 1, "");
_Static_assert(sizeof(struct G_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct G_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct G_extra_size) == 2, "");
_Static_assert(_Alignof(struct G_extra_size) == 1, "");
_Static_assert(sizeof(H) == 0, "");
_Static_assert(_Alignof(H) == 1, "");
_Static_assert(sizeof(struct H_extra_alignment) == 1, "");
_Static_assert(_Alignof(struct H_extra_alignment) == 1, "");
_Static_assert(sizeof(struct H_extra_packed) == 0, "");
_Static_assert(_Alignof(struct H_extra_packed) == 1, "");
_Static_assert(sizeof(struct H_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct H_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct H_extra_size) == 2, "");
_Static_assert(_Alignof(struct H_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
#endif
_Static_assert(sizeof(I) == 0, "");
_Static_assert(_Alignof(I) == 1, "");
_Static_assert(sizeof(struct I_extra_alignment) == 1, "");
_Static_assert(_Alignof(struct I_extra_alignment) == 1, "");
_Static_assert(sizeof(struct I_extra_packed) == 0, "");
_Static_assert(_Alignof(struct I_extra_packed) == 1, "");
_Static_assert(sizeof(struct I_extra_required_alignment) == 1, "");
_Static_assert(_Alignof(struct I_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct I_extra_size) == 2, "");
_Static_assert(_Alignof(struct I_extra_size) == 1, "");
#endif
