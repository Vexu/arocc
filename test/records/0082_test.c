// SPDX-License-Identifier: GPL-3.0-or-later

// This test file is auto-generated. do not edit.
// This file is a derivative work from the test files found
// in this repo : https://github.com/mahkoh/repr-c
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


// MAPPING|ONE|aarch64-generic-macos-none:Clang|aarch64-generic-ios-none:Clang|aarch64-generic-ios-macabi:Clang|aarch64-generic-tvos-none:Clang|hexagon-generic-linux-musl:Clang|mips64el-mips64-linux-gnuabi64:Gcc|mips64-mips64-linux-gnuabi64:Gcc|mipsel-mips32-linux-gnu:Gcc|mipsel-mips32-linux-musl:Gcc|mipsel-mips32-other-none:Clang|mips-mips32-linux-gnu:Gcc|mips-mips32r6-linux-gnu:Gcc|mips-mips32-linux-gnuabi64:Gcc|mips-mips64r6-linux-gnuabi64:Gcc|mips-mips32-linux-gnu:Gcc|mips-mips32-linux-musl:Gcc|powerpc64le-ppc64le-linux-gnu:Gcc|powerpc64le-ppc64le-linux-musl:Gcc|powerpc64-ppc64-freebsd-gnu:Clang|powerpc64-ppc64-linux-gnu:Gcc|powerpc64-ppc64-linux-musl:Gcc|powerpc-ppc-linux-gnu:Gcc|powerpc-ppc-linux-musl:Gcc|powerpc-ppc-netbsd-gnu:Clang|riscv32-generic_rv32-other-none:Clang|riscv32-generic_rv32-linux-gnu:Gcc|riscv64-generic_rv64-other-none:Clang|riscv64-generic_rv64-linux-gnu:Gcc|s390x-generic-linux-gnu:Gcc|sparc64-v9-linux-gnu:Gcc|sparc64-v9-netbsd-gnu:Clang|sparc64-v9-openbsd-gnu:Clang|sparc-v8-linux-gnu:Gcc|sparc-v9-solaris-eabi:Clang|wasm32-generic-emscripten-musl:Clang|wasm32-generic-other-none:Clang|wasm32-generic-wasi-musl:Clang|x86_64-x86_64-ios-macabi:Clang|x86_64-x86_64-ios-none:Clang|x86_64-x86_64-macos-none:Clang|x86_64-x86_64-tvos-none:Clang|x86_64-x86_64-fuchsia-gnu:Clang|x86_64-x86_64-linux-android:Clang|x86_64-x86_64-solaris-eabi:Clang|x86_64-x86_64-dragonfly-eabi:Clang|x86_64-x86_64-freebsd-gnu:Clang|x86_64-x86_64-haiku-gnu:Clang|x86_64-x86_64-hermit-eabi:Clang|x86_64-x86_64-linux-gnux32:Gcc|x86_64-x86_64-linux-gnu:Gcc|x86_64-x86_64-linux-musl:Gcc|x86_64-x86_64-netbsd-gnu:Clang|x86_64-x86_64-openbsd-gnu:Clang|END
// repr targets Aarch64AppleMacosx|Some("aarch64-generic-macos-none") Arm64AppleIos|Some("aarch64-generic-ios-none") Arm64AppleIosMacabi|Some("aarch64-generic-ios-macabi") Arm64AppleTvos|Some("aarch64-generic-tvos-none") HexagonUnknownLinuxMusl|Some("hexagon-generic-linux-musl") Mips64elUnknownLinuxGnuabi64|Some("mips64el-mips64-linux-gnuabi64") Mips64elUnknownLinuxMusl|None Mips64UnknownLinuxGnuabi64|Some("mips64-mips64-linux-gnuabi64") Mips64UnknownLinuxMusl|None MipselSonyPsp|None MipselUnknownLinuxGnu|Some("mipsel-mips32-linux-gnu") MipselUnknownLinuxMusl|Some("mipsel-mips32-linux-musl") MipselUnknownLinuxUclibc|None MipselUnknownNone|Some("mipsel-mips32-other-none") Mipsisa32r6elUnknownLinuxGnu|Some("mips-mips32-linux-gnu") Mipsisa32r6UnknownLinuxGnu|Some("mips-mips32r6-linux-gnu") Mipsisa64r6elUnknownLinuxGnuabi64|Some("mips-mips32-linux-gnuabi64") Mipsisa64r6UnknownLinuxGnuabi64|Some("mips-mips64r6-linux-gnuabi64") MipsUnknownLinuxGnu|Some("mips-mips32-linux-gnu") MipsUnknownLinuxMusl|Some("mips-mips32-linux-musl") MipsUnknownLinuxUclibc|None Powerpc64leUnknownLinuxGnu|Some("powerpc64le-ppc64le-linux-gnu") Powerpc64leUnknownLinuxMusl|Some("powerpc64le-ppc64le-linux-musl") Powerpc64UnknownFreebsd|Some("powerpc64-ppc64-freebsd-gnu") Powerpc64UnknownLinuxGnu|Some("powerpc64-ppc64-linux-gnu") Powerpc64UnknownLinuxMusl|Some("powerpc64-ppc64-linux-musl") PowerpcUnknownLinuxGnu|Some("powerpc-ppc-linux-gnu") PowerpcUnknownLinuxGnuspe|None PowerpcUnknownLinuxMusl|Some("powerpc-ppc-linux-musl") PowerpcUnknownNetbsd|Some("powerpc-ppc-netbsd-gnu") Riscv32|Some("riscv32-generic_rv32-other-none") Riscv32UnknownLinuxGnu|Some("riscv32-generic_rv32-linux-gnu") Riscv64|Some("riscv64-generic_rv64-other-none") Riscv64UnknownLinuxGnu|Some("riscv64-generic_rv64-linux-gnu") S390xUnknownLinuxGnu|Some("s390x-generic-linux-gnu") Sparc64UnknownLinuxGnu|Some("sparc64-v9-linux-gnu") Sparc64UnknownNetbsd|Some("sparc64-v9-netbsd-gnu") Sparc64UnknownOpenbsd|Some("sparc64-v9-openbsd-gnu") SparcUnknownLinuxGnu|Some("sparc-v8-linux-gnu") Sparcv9SunSolaris|Some("sparc-v9-solaris-eabi") Wasm32UnknownEmscripten|Some("wasm32-generic-emscripten-musl") Wasm32UnknownUnknown|Some("wasm32-generic-other-none") Wasm32Wasi|Some("wasm32-generic-wasi-musl") X86_64AppleIosMacabi|Some("x86_64-x86_64-ios-macabi") X86_64AppleIos|Some("x86_64-x86_64-ios-none") X86_64AppleMacosx|Some("x86_64-x86_64-macos-none") X86_64AppleTvos|Some("x86_64-x86_64-tvos-none") X86_64Elf|None X86_64Fuchsia|Some("x86_64-x86_64-fuchsia-gnu") X86_64LinuxAndroid|Some("x86_64-x86_64-linux-android") X86_64PcSolaris|Some("x86_64-x86_64-solaris-eabi") X86_64RumprunNetbsd|None X86_64UnknownDragonfly|Some("x86_64-x86_64-dragonfly-eabi") X86_64UnknownFreebsd|Some("x86_64-x86_64-freebsd-gnu") X86_64UnknownHaiku|Some("x86_64-x86_64-haiku-gnu") X86_64UnknownHermit|Some("x86_64-x86_64-hermit-eabi") X86_64UnknownL4reUclibc|None X86_64UnknownLinuxGnux32|Some("x86_64-x86_64-linux-gnux32") X86_64UnknownLinuxGnu|Some("x86_64-x86_64-linux-gnu") X86_64UnknownLinuxMusl|Some("x86_64-x86_64-linux-musl") X86_64UnknownNetbsd|Some("x86_64-x86_64-netbsd-gnu") X86_64UnknownOpenbsd|Some("x86_64-x86_64-openbsd-gnu") X86_64UnknownRedox|None 
#ifdef ONE
_Static_assert(sizeof(A) == 16, "");
_Static_assert(_Alignof(A) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 24, "");
_Static_assert(_Alignof(struct A_alignment) == 8, "");
_Static_assert(sizeof(struct A_packed) == 16, "");
_Static_assert(_Alignof(struct A_packed) == 1, "");
_Static_assert(sizeof(struct A_required_alignment) == 17, "");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "");
_Static_assert(sizeof(struct A_size) == 18, "");
_Static_assert(_Alignof(struct A_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A,b) == 64, "");
#endif
_Static_assert(sizeof(A_) == 8, "");
_Static_assert(_Alignof(A_) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A__alignment) == 16, "");
_Static_assert(_Alignof(struct A__alignment) == 8, "");
_Static_assert(sizeof(struct A__packed) == 8, "");
_Static_assert(_Alignof(struct A__packed) == 1, "");
_Static_assert(sizeof(struct A__required_alignment) == 9, "");
_Static_assert(_Alignof(struct A__required_alignment) == 1, "");
_Static_assert(sizeof(struct A__size) == 10, "");
_Static_assert(_Alignof(struct A__size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_,b) == 0, "");
#endif
_Static_assert(sizeof(B) == 16, "");
_Static_assert(_Alignof(B) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 24, "");
_Static_assert(_Alignof(struct B_alignment) == 8, "");
_Static_assert(sizeof(struct B_packed) == 16, "");
_Static_assert(_Alignof(struct B_packed) == 1, "");
_Static_assert(sizeof(struct B_required_alignment) == 17, "");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "");
_Static_assert(sizeof(struct B_size) == 18, "");
_Static_assert(_Alignof(struct B_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B,b) == 64, "");
#endif
_Static_assert(sizeof(B_) == 8, "");
_Static_assert(_Alignof(B_) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B__alignment) == 16, "");
_Static_assert(_Alignof(struct B__alignment) == 8, "");
_Static_assert(sizeof(struct B__packed) == 8, "");
_Static_assert(_Alignof(struct B__packed) == 1, "");
_Static_assert(sizeof(struct B__required_alignment) == 9, "");
_Static_assert(_Alignof(struct B__required_alignment) == 1, "");
_Static_assert(sizeof(struct B__size) == 10, "");
_Static_assert(_Alignof(struct B__size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B_,b) == 0, "");
#endif
_Static_assert(sizeof(C) == 9, "");
_Static_assert(_Alignof(C) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 10, "");
_Static_assert(_Alignof(struct C_alignment) == 1, "");
_Static_assert(sizeof(struct C_packed) == 9, "");
_Static_assert(_Alignof(struct C_packed) == 1, "");
_Static_assert(sizeof(struct C_required_alignment) == 10, "");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "");
_Static_assert(sizeof(struct C_size) == 11, "");
_Static_assert(_Alignof(struct C_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C,b) == 64, "");
#endif
_Static_assert(sizeof(C_) == 1, "");
_Static_assert(_Alignof(C_) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C__alignment) == 2, "");
_Static_assert(_Alignof(struct C__alignment) == 1, "");
_Static_assert(sizeof(struct C__packed) == 1, "");
_Static_assert(_Alignof(struct C__packed) == 1, "");
_Static_assert(sizeof(struct C__required_alignment) == 2, "");
_Static_assert(_Alignof(struct C__required_alignment) == 1, "");
_Static_assert(sizeof(struct C__size) == 3, "");
_Static_assert(_Alignof(struct C__size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C_,b) == 0, "");
#endif
_Static_assert(sizeof(D) == 9, "");
_Static_assert(_Alignof(D) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 10, "");
_Static_assert(_Alignof(struct D_alignment) == 1, "");
_Static_assert(sizeof(struct D_packed) == 9, "");
_Static_assert(_Alignof(struct D_packed) == 1, "");
_Static_assert(sizeof(struct D_required_alignment) == 10, "");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "");
_Static_assert(sizeof(struct D_size) == 11, "");
_Static_assert(_Alignof(struct D_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D,b) == 64, "");
#endif
_Static_assert(sizeof(D_) == 1, "");
_Static_assert(_Alignof(D_) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D__alignment) == 2, "");
_Static_assert(_Alignof(struct D__alignment) == 1, "");
_Static_assert(sizeof(struct D__packed) == 1, "");
_Static_assert(_Alignof(struct D__packed) == 1, "");
_Static_assert(sizeof(struct D__required_alignment) == 2, "");
_Static_assert(_Alignof(struct D__required_alignment) == 1, "");
_Static_assert(sizeof(struct D__size) == 3, "");
_Static_assert(_Alignof(struct D__size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D_,b) == 0, "");
#endif
_Static_assert(sizeof(E) == 129, "");
_Static_assert(_Alignof(E) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 130, "");
_Static_assert(_Alignof(struct E_alignment) == 1, "");
_Static_assert(sizeof(struct E_packed) == 129, "");
_Static_assert(_Alignof(struct E_packed) == 1, "");
_Static_assert(sizeof(struct E_required_alignment) == 130, "");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "");
_Static_assert(sizeof(struct E_size) == 131, "");
_Static_assert(_Alignof(struct E_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(E,b) == 1024, "");
#endif
_Static_assert(sizeof(E_) == 1, "");
_Static_assert(_Alignof(E_) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E__alignment) == 2, "");
_Static_assert(_Alignof(struct E__alignment) == 1, "");
_Static_assert(sizeof(struct E__packed) == 1, "");
_Static_assert(_Alignof(struct E__packed) == 1, "");
_Static_assert(sizeof(struct E__required_alignment) == 2, "");
_Static_assert(_Alignof(struct E__required_alignment) == 1, "");
_Static_assert(sizeof(struct E__size) == 3, "");
_Static_assert(_Alignof(struct E__size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(E_,b) == 0, "");
#endif
_Static_assert(sizeof(F) == 129, "");
_Static_assert(_Alignof(F) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 130, "");
_Static_assert(_Alignof(struct F_alignment) == 1, "");
_Static_assert(sizeof(struct F_packed) == 129, "");
_Static_assert(_Alignof(struct F_packed) == 1, "");
_Static_assert(sizeof(struct F_required_alignment) == 130, "");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "");
_Static_assert(sizeof(struct F_size) == 131, "");
_Static_assert(_Alignof(struct F_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F,b) == 1024, "");
#endif
_Static_assert(sizeof(F_) == 1, "");
_Static_assert(_Alignof(F_) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F__alignment) == 2, "");
_Static_assert(_Alignof(struct F__alignment) == 1, "");
_Static_assert(sizeof(struct F__packed) == 1, "");
_Static_assert(_Alignof(struct F__packed) == 1, "");
_Static_assert(sizeof(struct F__required_alignment) == 2, "");
_Static_assert(_Alignof(struct F__required_alignment) == 1, "");
_Static_assert(sizeof(struct F__size) == 3, "");
_Static_assert(_Alignof(struct F__size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F_,b) == 0, "");
#endif
_Static_assert(sizeof(G) == 136, "");
_Static_assert(_Alignof(G) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 144, "");
_Static_assert(_Alignof(struct G_alignment) == 8, "");
_Static_assert(sizeof(struct G_packed) == 136, "");
_Static_assert(_Alignof(struct G_packed) == 1, "");
_Static_assert(sizeof(struct G_required_alignment) == 137, "");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "");
_Static_assert(sizeof(struct G_size) == 138, "");
_Static_assert(_Alignof(struct G_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(G,b) == 1024, "");
#endif
_Static_assert(sizeof(G_) == 8, "");
_Static_assert(_Alignof(G_) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G__alignment) == 16, "");
_Static_assert(_Alignof(struct G__alignment) == 8, "");
_Static_assert(sizeof(struct G__packed) == 8, "");
_Static_assert(_Alignof(struct G__packed) == 1, "");
_Static_assert(sizeof(struct G__required_alignment) == 9, "");
_Static_assert(_Alignof(struct G__required_alignment) == 1, "");
_Static_assert(sizeof(struct G__size) == 10, "");
_Static_assert(_Alignof(struct G__size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(G_,b) == 0, "");
#endif
_Static_assert(sizeof(H) == 129, "");
_Static_assert(_Alignof(H) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 130, "");
_Static_assert(_Alignof(struct H_alignment) == 1, "");
_Static_assert(sizeof(struct H_packed) == 129, "");
_Static_assert(_Alignof(struct H_packed) == 1, "");
_Static_assert(sizeof(struct H_required_alignment) == 130, "");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "");
_Static_assert(sizeof(struct H_size) == 131, "");
_Static_assert(_Alignof(struct H_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(H,b) == 1024, "");
#endif
_Static_assert(sizeof(H_) == 1, "");
_Static_assert(_Alignof(H_) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H__alignment) == 2, "");
_Static_assert(_Alignof(struct H__alignment) == 1, "");
_Static_assert(sizeof(struct H__packed) == 1, "");
_Static_assert(_Alignof(struct H__packed) == 1, "");
_Static_assert(sizeof(struct H__required_alignment) == 2, "");
_Static_assert(_Alignof(struct H__required_alignment) == 1, "");
_Static_assert(sizeof(struct H__size) == 3, "");
_Static_assert(_Alignof(struct H__size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(H_,b) == 0, "");
#endif
_Static_assert(sizeof(I) == 8, "");
_Static_assert(_Alignof(I) == 128, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I_alignment) == 256, "");
_Static_assert(_Alignof(struct I_alignment) == 128, "");
_Static_assert(sizeof(struct I_packed) == 8, "");
_Static_assert(_Alignof(struct I_packed) == 1, "");
_Static_assert(sizeof(struct I_required_alignment) == 9, "");
_Static_assert(_Alignof(struct I_required_alignment) == 1, "");
_Static_assert(sizeof(struct I_size) == 10, "");
_Static_assert(_Alignof(struct I_size) == 1, "");
#endif
_Static_assert(sizeof(J) == 136, "");
_Static_assert(_Alignof(J) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J_alignment) == 144, "");
_Static_assert(_Alignof(struct J_alignment) == 8, "");
_Static_assert(sizeof(struct J_packed) == 136, "");
_Static_assert(_Alignof(struct J_packed) == 1, "");
_Static_assert(sizeof(struct J_required_alignment) == 137, "");
_Static_assert(_Alignof(struct J_required_alignment) == 1, "");
_Static_assert(sizeof(struct J_size) == 138, "");
_Static_assert(_Alignof(struct J_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(J,b) == 1024, "");
#endif
_Static_assert(sizeof(J_) == 8, "");
_Static_assert(_Alignof(J_) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J__alignment) == 16, "");
_Static_assert(_Alignof(struct J__alignment) == 8, "");
_Static_assert(sizeof(struct J__packed) == 8, "");
_Static_assert(_Alignof(struct J__packed) == 1, "");
_Static_assert(sizeof(struct J__required_alignment) == 9, "");
_Static_assert(_Alignof(struct J__required_alignment) == 1, "");
_Static_assert(sizeof(struct J__size) == 10, "");
_Static_assert(_Alignof(struct J__size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(J_,b) == 0, "");
#endif
// MAPPING|TWO|aarch64-generic-fuchsia-gnu:Clang|aarch64-generic-linux-android:Clang|aarch64-generic-freebsd-gnu:Clang|aarch64-generic-hermit-eabi:Clang|aarch64-generic-linux-gnu:Gcc|aarch64-generic-linux-musl:Gcc|aarch64-generic-netbsd-gnu:Clang|aarch64-generic-other-none:Clang|aarch64-generic-openbsd-gnu:Clang|arm-baseline-other-eabi:Clang|arm-baseline-other-eabihf:Clang|arm-baseline-linux-gnueabi:Gcc|arm-baseline-linux-gnueabihf:Gcc|arm-arm710t-linux-gnueabi:Gcc|arm-arm1020e-linux-gnueabi:Gcc|arm-arm1136j_s-freebsd-gnu:Clang|arm-arm1136j_s-netbsd-eabihf:Clang|arm-baseline-other-eabi:Clang|arm-baseline-other-eabihf:Clang|arm-cortex_r4-other-eabi:Clang|arm-cortex_r4-other-eabihf:Clang|arm-cortex_r4-freebsd-gnu:Clang|arm-cortex_r4-linux-gnueabi:Gcc|arm-cortex_r4-linux-gnueabihf:Gcc|arm-cortex_r4-netbsd-eabihf:Clang|thumb-arm710t-other-eabi:Clang|thumb-cortex_m0-other-eabi:Clang|thumb-cortex_m4-other-eabihf:Clang|thumb-cortex_m4-other-eabi:Clang|thumb-cortex_m3-other-eabi:Clang|thumb-baseline-other-eabi:Clang|thumb-cortex_m33-other-eabihf:Clang|thumb-cortex_m33-other-eabi:Clang|END
// repr targets Aarch64Fuchsia|Some("aarch64-generic-fuchsia-gnu") Aarch64LinuxAndroid|Some("aarch64-generic-linux-android") Aarch64UnknownFreebsd|Some("aarch64-generic-freebsd-gnu") Aarch64UnknownHermit|Some("aarch64-generic-hermit-eabi") Aarch64UnknownLinuxGnu|Some("aarch64-generic-linux-gnu") Aarch64UnknownLinuxMusl|Some("aarch64-generic-linux-musl") Aarch64UnknownNetbsd|Some("aarch64-generic-netbsd-gnu") Aarch64UnknownNone|Some("aarch64-generic-other-none") Aarch64UnknownOpenbsd|Some("aarch64-generic-openbsd-gnu") Aarch64UnknownRedox|None Armebv7rUnknownNoneEabi|Some("arm-baseline-other-eabi") Armebv7rUnknownNoneEabihf|Some("arm-baseline-other-eabihf") ArmLinuxAndroideabi|None ArmUnknownLinuxGnueabi|Some("arm-baseline-linux-gnueabi") ArmUnknownLinuxGnueabihf|Some("arm-baseline-linux-gnueabihf") Armv4tUnknownLinuxGnueabi|Some("arm-arm710t-linux-gnueabi") Armv5teUnknownLinuxGnueabi|Some("arm-arm1020e-linux-gnueabi") Armv5teUnknownLinuxUclibcgnueabi|None Armv6UnknownFreebsdGnueabihf|Some("arm-arm1136j_s-freebsd-gnu") Armv6UnknownNetbsdelfEabihf|Some("arm-arm1136j_s-netbsd-eabihf") Armv7aNoneEabi|Some("arm-baseline-other-eabi") Armv7aNoneEabihf|Some("arm-baseline-other-eabihf") Armv7NoneLinuxAndroid|None Armv7rUnknownNoneEabi|Some("arm-cortex_r4-other-eabi") Armv7rUnknownNoneEabihf|Some("arm-cortex_r4-other-eabihf") Armv7UnknownFreebsdGnueabihf|Some("arm-cortex_r4-freebsd-gnu") Armv7UnknownLinuxGnueabi|Some("arm-cortex_r4-linux-gnueabi") Armv7UnknownLinuxGnueabihf|Some("arm-cortex_r4-linux-gnueabihf") Armv7UnknownNetbsdelfEabihf|Some("arm-cortex_r4-netbsd-eabihf") Thumbv4tNoneEabi|Some("thumb-arm710t-other-eabi") Thumbv6mNoneEabi|Some("thumb-cortex_m0-other-eabi") Thumbv7emNoneEabihf|Some("thumb-cortex_m4-other-eabihf") Thumbv7emNoneEabi|Some("thumb-cortex_m4-other-eabi") Thumbv7mNoneEabi|Some("thumb-cortex_m3-other-eabi") Thumbv8mBaseNoneEabi|Some("thumb-baseline-other-eabi") Thumbv8mMainNoneEabihf|Some("thumb-cortex_m33-other-eabihf") Thumbv8mMainNoneEabi|Some("thumb-cortex_m33-other-eabi") 
#elif defined(TWO)
_Static_assert(sizeof(A) == 16, "");
_Static_assert(_Alignof(A) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 24, "");
_Static_assert(_Alignof(struct A_alignment) == 8, "");
_Static_assert(sizeof(struct A_packed) == 16, "");
_Static_assert(_Alignof(struct A_packed) == 1, "");
_Static_assert(sizeof(struct A_required_alignment) == 17, "");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "");
_Static_assert(sizeof(struct A_size) == 18, "");
_Static_assert(_Alignof(struct A_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A,b) == 64, "");
#endif
_Static_assert(sizeof(A_) == 8, "");
_Static_assert(_Alignof(A_) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A__alignment) == 16, "");
_Static_assert(_Alignof(struct A__alignment) == 8, "");
_Static_assert(sizeof(struct A__packed) == 8, "");
_Static_assert(_Alignof(struct A__packed) == 1, "");
_Static_assert(sizeof(struct A__required_alignment) == 9, "");
_Static_assert(_Alignof(struct A__required_alignment) == 1, "");
_Static_assert(sizeof(struct A__size) == 10, "");
_Static_assert(_Alignof(struct A__size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_,b) == 0, "");
#endif
_Static_assert(sizeof(B) == 16, "");
_Static_assert(_Alignof(B) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 24, "");
_Static_assert(_Alignof(struct B_alignment) == 8, "");
_Static_assert(sizeof(struct B_packed) == 16, "");
_Static_assert(_Alignof(struct B_packed) == 1, "");
_Static_assert(sizeof(struct B_required_alignment) == 17, "");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "");
_Static_assert(sizeof(struct B_size) == 18, "");
_Static_assert(_Alignof(struct B_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B,b) == 64, "");
#endif
_Static_assert(sizeof(B_) == 8, "");
_Static_assert(_Alignof(B_) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B__alignment) == 16, "");
_Static_assert(_Alignof(struct B__alignment) == 8, "");
_Static_assert(sizeof(struct B__packed) == 8, "");
_Static_assert(_Alignof(struct B__packed) == 1, "");
_Static_assert(sizeof(struct B__required_alignment) == 9, "");
_Static_assert(_Alignof(struct B__required_alignment) == 1, "");
_Static_assert(sizeof(struct B__size) == 10, "");
_Static_assert(_Alignof(struct B__size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B_,b) == 0, "");
#endif
_Static_assert(sizeof(C) == 16, "");
_Static_assert(_Alignof(C) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 24, "");
_Static_assert(_Alignof(struct C_alignment) == 8, "");
_Static_assert(sizeof(struct C_packed) == 16, "");
_Static_assert(_Alignof(struct C_packed) == 1, "");
_Static_assert(sizeof(struct C_required_alignment) == 17, "");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "");
_Static_assert(sizeof(struct C_size) == 18, "");
_Static_assert(_Alignof(struct C_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C,b) == 64, "");
#endif
_Static_assert(sizeof(C_) == 8, "");
_Static_assert(_Alignof(C_) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C__alignment) == 16, "");
_Static_assert(_Alignof(struct C__alignment) == 8, "");
_Static_assert(sizeof(struct C__packed) == 8, "");
_Static_assert(_Alignof(struct C__packed) == 1, "");
_Static_assert(sizeof(struct C__required_alignment) == 9, "");
_Static_assert(_Alignof(struct C__required_alignment) == 1, "");
_Static_assert(sizeof(struct C__size) == 10, "");
_Static_assert(_Alignof(struct C__size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C_,b) == 0, "");
#endif
_Static_assert(sizeof(D) == 16, "");
_Static_assert(_Alignof(D) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 24, "");
_Static_assert(_Alignof(struct D_alignment) == 8, "");
_Static_assert(sizeof(struct D_packed) == 16, "");
_Static_assert(_Alignof(struct D_packed) == 1, "");
_Static_assert(sizeof(struct D_required_alignment) == 17, "");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "");
_Static_assert(sizeof(struct D_size) == 18, "");
_Static_assert(_Alignof(struct D_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D,b) == 64, "");
#endif
_Static_assert(sizeof(D_) == 8, "");
_Static_assert(_Alignof(D_) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D__alignment) == 16, "");
_Static_assert(_Alignof(struct D__alignment) == 8, "");
_Static_assert(sizeof(struct D__packed) == 8, "");
_Static_assert(_Alignof(struct D__packed) == 1, "");
_Static_assert(sizeof(struct D__required_alignment) == 9, "");
_Static_assert(_Alignof(struct D__required_alignment) == 1, "");
_Static_assert(sizeof(struct D__size) == 10, "");
_Static_assert(_Alignof(struct D__size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D_,b) == 0, "");
#endif
_Static_assert(sizeof(E) == 256, "");
_Static_assert(_Alignof(E) == 128, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 384, "");
_Static_assert(_Alignof(struct E_alignment) == 128, "");
_Static_assert(sizeof(struct E_packed) == 256, "");
_Static_assert(_Alignof(struct E_packed) == 1, "");
_Static_assert(sizeof(struct E_required_alignment) == 257, "");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "");
_Static_assert(sizeof(struct E_size) == 258, "");
_Static_assert(_Alignof(struct E_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(E,b) == 1024, "");
#endif
_Static_assert(sizeof(E_) == 128, "");
_Static_assert(_Alignof(E_) == 128, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E__alignment) == 256, "");
_Static_assert(_Alignof(struct E__alignment) == 128, "");
_Static_assert(sizeof(struct E__packed) == 128, "");
_Static_assert(_Alignof(struct E__packed) == 1, "");
_Static_assert(sizeof(struct E__required_alignment) == 129, "");
_Static_assert(_Alignof(struct E__required_alignment) == 1, "");
_Static_assert(sizeof(struct E__size) == 130, "");
_Static_assert(_Alignof(struct E__size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(E_,b) == 0, "");
#endif
_Static_assert(sizeof(F) == 256, "");
_Static_assert(_Alignof(F) == 128, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 384, "");
_Static_assert(_Alignof(struct F_alignment) == 128, "");
_Static_assert(sizeof(struct F_packed) == 256, "");
_Static_assert(_Alignof(struct F_packed) == 1, "");
_Static_assert(sizeof(struct F_required_alignment) == 257, "");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "");
_Static_assert(sizeof(struct F_size) == 258, "");
_Static_assert(_Alignof(struct F_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F,b) == 1024, "");
#endif
_Static_assert(sizeof(F_) == 128, "");
_Static_assert(_Alignof(F_) == 128, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F__alignment) == 256, "");
_Static_assert(_Alignof(struct F__alignment) == 128, "");
_Static_assert(sizeof(struct F__packed) == 128, "");
_Static_assert(_Alignof(struct F__packed) == 1, "");
_Static_assert(sizeof(struct F__required_alignment) == 129, "");
_Static_assert(_Alignof(struct F__required_alignment) == 1, "");
_Static_assert(sizeof(struct F__size) == 130, "");
_Static_assert(_Alignof(struct F__size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F_,b) == 0, "");
#endif
_Static_assert(sizeof(G) == 256, "");
_Static_assert(_Alignof(G) == 128, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 384, "");
_Static_assert(_Alignof(struct G_alignment) == 128, "");
_Static_assert(sizeof(struct G_packed) == 256, "");
_Static_assert(_Alignof(struct G_packed) == 1, "");
_Static_assert(sizeof(struct G_required_alignment) == 257, "");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "");
_Static_assert(sizeof(struct G_size) == 258, "");
_Static_assert(_Alignof(struct G_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(G,b) == 1024, "");
#endif
_Static_assert(sizeof(G_) == 128, "");
_Static_assert(_Alignof(G_) == 128, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G__alignment) == 256, "");
_Static_assert(_Alignof(struct G__alignment) == 128, "");
_Static_assert(sizeof(struct G__packed) == 128, "");
_Static_assert(_Alignof(struct G__packed) == 1, "");
_Static_assert(sizeof(struct G__required_alignment) == 129, "");
_Static_assert(_Alignof(struct G__required_alignment) == 1, "");
_Static_assert(sizeof(struct G__size) == 130, "");
_Static_assert(_Alignof(struct G__size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(G_,b) == 0, "");
#endif
_Static_assert(sizeof(H) == 256, "");
_Static_assert(_Alignof(H) == 128, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 384, "");
_Static_assert(_Alignof(struct H_alignment) == 128, "");
_Static_assert(sizeof(struct H_packed) == 256, "");
_Static_assert(_Alignof(struct H_packed) == 1, "");
_Static_assert(sizeof(struct H_required_alignment) == 257, "");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "");
_Static_assert(sizeof(struct H_size) == 258, "");
_Static_assert(_Alignof(struct H_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(H,b) == 1024, "");
#endif
_Static_assert(sizeof(H_) == 128, "");
_Static_assert(_Alignof(H_) == 128, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H__alignment) == 256, "");
_Static_assert(_Alignof(struct H__alignment) == 128, "");
_Static_assert(sizeof(struct H__packed) == 128, "");
_Static_assert(_Alignof(struct H__packed) == 1, "");
_Static_assert(sizeof(struct H__required_alignment) == 129, "");
_Static_assert(_Alignof(struct H__required_alignment) == 1, "");
_Static_assert(sizeof(struct H__size) == 130, "");
_Static_assert(_Alignof(struct H__size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(H_,b) == 0, "");
#endif
_Static_assert(sizeof(I) == 8, "");
_Static_assert(_Alignof(I) == 128, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I_alignment) == 256, "");
_Static_assert(_Alignof(struct I_alignment) == 128, "");
_Static_assert(sizeof(struct I_packed) == 8, "");
_Static_assert(_Alignof(struct I_packed) == 1, "");
_Static_assert(sizeof(struct I_required_alignment) == 9, "");
_Static_assert(_Alignof(struct I_required_alignment) == 1, "");
_Static_assert(sizeof(struct I_size) == 10, "");
_Static_assert(_Alignof(struct I_size) == 1, "");
#endif
_Static_assert(sizeof(J) == 256, "");
_Static_assert(_Alignof(J) == 128, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J_alignment) == 384, "");
_Static_assert(_Alignof(struct J_alignment) == 128, "");
_Static_assert(sizeof(struct J_packed) == 256, "");
_Static_assert(_Alignof(struct J_packed) == 1, "");
_Static_assert(sizeof(struct J_required_alignment) == 257, "");
_Static_assert(_Alignof(struct J_required_alignment) == 1, "");
_Static_assert(sizeof(struct J_size) == 258, "");
_Static_assert(_Alignof(struct J_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(J,b) == 1024, "");
#endif
_Static_assert(sizeof(J_) == 128, "");
_Static_assert(_Alignof(J_) == 128, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J__alignment) == 256, "");
_Static_assert(_Alignof(struct J__alignment) == 128, "");
_Static_assert(sizeof(struct J__packed) == 128, "");
_Static_assert(_Alignof(struct J__packed) == 1, "");
_Static_assert(sizeof(struct J__required_alignment) == 129, "");
_Static_assert(_Alignof(struct J__required_alignment) == 1, "");
_Static_assert(sizeof(struct J__size) == 130, "");
_Static_assert(_Alignof(struct J__size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(J_,b) == 0, "");
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
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A,b) == 32, "");
#endif
_Static_assert(sizeof(A_) == 4, "");
_Static_assert(_Alignof(A_) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A__alignment) == 8, "");
_Static_assert(_Alignof(struct A__alignment) == 4, "");
_Static_assert(sizeof(struct A__packed) == 4, "");
_Static_assert(_Alignof(struct A__packed) == 1, "");
_Static_assert(sizeof(struct A__required_alignment) == 5, "");
_Static_assert(_Alignof(struct A__required_alignment) == 1, "");
_Static_assert(sizeof(struct A__size) == 6, "");
_Static_assert(_Alignof(struct A__size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_,b) == 0, "");
#endif
_Static_assert(sizeof(B) == 8, "");
_Static_assert(_Alignof(B) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 12, "");
_Static_assert(_Alignof(struct B_alignment) == 4, "");
_Static_assert(sizeof(struct B_packed) == 8, "");
_Static_assert(_Alignof(struct B_packed) == 1, "");
_Static_assert(sizeof(struct B_required_alignment) == 9, "");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "");
_Static_assert(sizeof(struct B_size) == 10, "");
_Static_assert(_Alignof(struct B_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B,b) == 32, "");
#endif
_Static_assert(sizeof(B_) == 4, "");
_Static_assert(_Alignof(B_) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B__alignment) == 8, "");
_Static_assert(_Alignof(struct B__alignment) == 4, "");
_Static_assert(sizeof(struct B__packed) == 4, "");
_Static_assert(_Alignof(struct B__packed) == 1, "");
_Static_assert(sizeof(struct B__required_alignment) == 5, "");
_Static_assert(_Alignof(struct B__required_alignment) == 1, "");
_Static_assert(sizeof(struct B__size) == 6, "");
_Static_assert(_Alignof(struct B__size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B_,b) == 0, "");
#endif
_Static_assert(sizeof(C) == 8, "");
_Static_assert(_Alignof(C) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 12, "");
_Static_assert(_Alignof(struct C_alignment) == 4, "");
_Static_assert(sizeof(struct C_packed) == 8, "");
_Static_assert(_Alignof(struct C_packed) == 1, "");
_Static_assert(sizeof(struct C_required_alignment) == 9, "");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "");
_Static_assert(sizeof(struct C_size) == 10, "");
_Static_assert(_Alignof(struct C_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C,b) == 32, "");
#endif
_Static_assert(sizeof(C_) == 4, "");
_Static_assert(_Alignof(C_) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C__alignment) == 8, "");
_Static_assert(_Alignof(struct C__alignment) == 4, "");
_Static_assert(sizeof(struct C__packed) == 4, "");
_Static_assert(_Alignof(struct C__packed) == 1, "");
_Static_assert(sizeof(struct C__required_alignment) == 5, "");
_Static_assert(_Alignof(struct C__required_alignment) == 1, "");
_Static_assert(sizeof(struct C__size) == 6, "");
_Static_assert(_Alignof(struct C__size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C_,b) == 0, "");
#endif
_Static_assert(sizeof(D) == 8, "");
_Static_assert(_Alignof(D) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 12, "");
_Static_assert(_Alignof(struct D_alignment) == 4, "");
_Static_assert(sizeof(struct D_packed) == 8, "");
_Static_assert(_Alignof(struct D_packed) == 1, "");
_Static_assert(sizeof(struct D_required_alignment) == 9, "");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "");
_Static_assert(sizeof(struct D_size) == 10, "");
_Static_assert(_Alignof(struct D_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D,b) == 32, "");
#endif
_Static_assert(sizeof(D_) == 4, "");
_Static_assert(_Alignof(D_) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D__alignment) == 8, "");
_Static_assert(_Alignof(struct D__alignment) == 4, "");
_Static_assert(sizeof(struct D__packed) == 4, "");
_Static_assert(_Alignof(struct D__packed) == 1, "");
_Static_assert(sizeof(struct D__required_alignment) == 5, "");
_Static_assert(_Alignof(struct D__required_alignment) == 1, "");
_Static_assert(sizeof(struct D__size) == 6, "");
_Static_assert(_Alignof(struct D__size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D_,b) == 0, "");
#endif
_Static_assert(sizeof(E) == 256, "");
_Static_assert(_Alignof(E) == 128, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 384, "");
_Static_assert(_Alignof(struct E_alignment) == 128, "");
_Static_assert(sizeof(struct E_packed) == 256, "");
_Static_assert(_Alignof(struct E_packed) == 1, "");
_Static_assert(sizeof(struct E_required_alignment) == 257, "");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "");
_Static_assert(sizeof(struct E_size) == 258, "");
_Static_assert(_Alignof(struct E_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(E,b) == 1024, "");
#endif
_Static_assert(sizeof(E_) == 128, "");
_Static_assert(_Alignof(E_) == 128, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E__alignment) == 256, "");
_Static_assert(_Alignof(struct E__alignment) == 128, "");
_Static_assert(sizeof(struct E__packed) == 128, "");
_Static_assert(_Alignof(struct E__packed) == 1, "");
_Static_assert(sizeof(struct E__required_alignment) == 129, "");
_Static_assert(_Alignof(struct E__required_alignment) == 1, "");
_Static_assert(sizeof(struct E__size) == 130, "");
_Static_assert(_Alignof(struct E__size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(E_,b) == 0, "");
#endif
_Static_assert(sizeof(F) == 256, "");
_Static_assert(_Alignof(F) == 128, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 384, "");
_Static_assert(_Alignof(struct F_alignment) == 128, "");
_Static_assert(sizeof(struct F_packed) == 256, "");
_Static_assert(_Alignof(struct F_packed) == 1, "");
_Static_assert(sizeof(struct F_required_alignment) == 257, "");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "");
_Static_assert(sizeof(struct F_size) == 258, "");
_Static_assert(_Alignof(struct F_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F,b) == 1024, "");
#endif
_Static_assert(sizeof(F_) == 128, "");
_Static_assert(_Alignof(F_) == 128, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F__alignment) == 256, "");
_Static_assert(_Alignof(struct F__alignment) == 128, "");
_Static_assert(sizeof(struct F__packed) == 128, "");
_Static_assert(_Alignof(struct F__packed) == 1, "");
_Static_assert(sizeof(struct F__required_alignment) == 129, "");
_Static_assert(_Alignof(struct F__required_alignment) == 1, "");
_Static_assert(sizeof(struct F__size) == 130, "");
_Static_assert(_Alignof(struct F__size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F_,b) == 0, "");
#endif
_Static_assert(sizeof(G) == 256, "");
_Static_assert(_Alignof(G) == 128, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 384, "");
_Static_assert(_Alignof(struct G_alignment) == 128, "");
_Static_assert(sizeof(struct G_packed) == 256, "");
_Static_assert(_Alignof(struct G_packed) == 1, "");
_Static_assert(sizeof(struct G_required_alignment) == 257, "");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "");
_Static_assert(sizeof(struct G_size) == 258, "");
_Static_assert(_Alignof(struct G_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(G,b) == 1024, "");
#endif
_Static_assert(sizeof(G_) == 128, "");
_Static_assert(_Alignof(G_) == 128, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G__alignment) == 256, "");
_Static_assert(_Alignof(struct G__alignment) == 128, "");
_Static_assert(sizeof(struct G__packed) == 128, "");
_Static_assert(_Alignof(struct G__packed) == 1, "");
_Static_assert(sizeof(struct G__required_alignment) == 129, "");
_Static_assert(_Alignof(struct G__required_alignment) == 1, "");
_Static_assert(sizeof(struct G__size) == 130, "");
_Static_assert(_Alignof(struct G__size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(G_,b) == 0, "");
#endif
_Static_assert(sizeof(H) == 256, "");
_Static_assert(_Alignof(H) == 128, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 384, "");
_Static_assert(_Alignof(struct H_alignment) == 128, "");
_Static_assert(sizeof(struct H_packed) == 256, "");
_Static_assert(_Alignof(struct H_packed) == 1, "");
_Static_assert(sizeof(struct H_required_alignment) == 257, "");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "");
_Static_assert(sizeof(struct H_size) == 258, "");
_Static_assert(_Alignof(struct H_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(H,b) == 1024, "");
#endif
_Static_assert(sizeof(H_) == 128, "");
_Static_assert(_Alignof(H_) == 128, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H__alignment) == 256, "");
_Static_assert(_Alignof(struct H__alignment) == 128, "");
_Static_assert(sizeof(struct H__packed) == 128, "");
_Static_assert(_Alignof(struct H__packed) == 1, "");
_Static_assert(sizeof(struct H__required_alignment) == 129, "");
_Static_assert(_Alignof(struct H__required_alignment) == 1, "");
_Static_assert(sizeof(struct H__size) == 130, "");
_Static_assert(_Alignof(struct H__size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(H_,b) == 0, "");
#endif
_Static_assert(sizeof(I) == 8, "");
_Static_assert(_Alignof(I) == 128, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I_alignment) == 256, "");
_Static_assert(_Alignof(struct I_alignment) == 128, "");
_Static_assert(sizeof(struct I_packed) == 8, "");
_Static_assert(_Alignof(struct I_packed) == 1, "");
_Static_assert(sizeof(struct I_required_alignment) == 9, "");
_Static_assert(_Alignof(struct I_required_alignment) == 1, "");
_Static_assert(sizeof(struct I_size) == 10, "");
_Static_assert(_Alignof(struct I_size) == 1, "");
#endif
_Static_assert(sizeof(J) == 256, "");
_Static_assert(_Alignof(J) == 128, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J_alignment) == 384, "");
_Static_assert(_Alignof(struct J_alignment) == 128, "");
_Static_assert(sizeof(struct J_packed) == 256, "");
_Static_assert(_Alignof(struct J_packed) == 1, "");
_Static_assert(sizeof(struct J_required_alignment) == 257, "");
_Static_assert(_Alignof(struct J_required_alignment) == 1, "");
_Static_assert(sizeof(struct J_size) == 258, "");
_Static_assert(_Alignof(struct J_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(J,b) == 1024, "");
#endif
_Static_assert(sizeof(J_) == 128, "");
_Static_assert(_Alignof(J_) == 128, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J__alignment) == 256, "");
_Static_assert(_Alignof(struct J__alignment) == 128, "");
_Static_assert(sizeof(struct J__packed) == 128, "");
_Static_assert(_Alignof(struct J__packed) == 1, "");
_Static_assert(sizeof(struct J__required_alignment) == 129, "");
_Static_assert(_Alignof(struct J__required_alignment) == 1, "");
_Static_assert(sizeof(struct J__size) == 130, "");
_Static_assert(_Alignof(struct J__size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(J_,b) == 0, "");
#endif
// MAPPING|FOUR|avr-atmega328-other-gnu:Gcc|END
// repr targets AvrUnknownUnknown|Some("avr-atmega328-other-gnu") 
#elif defined(FOUR)
_Static_assert(sizeof(A) == 2, "");
_Static_assert(_Alignof(A) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 3, "");
_Static_assert(_Alignof(struct A_alignment) == 1, "");
_Static_assert(sizeof(struct A_packed) == 2, "");
_Static_assert(_Alignof(struct A_packed) == 1, "");
_Static_assert(sizeof(struct A_required_alignment) == 3, "");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "");
_Static_assert(sizeof(struct A_size) == 4, "");
_Static_assert(_Alignof(struct A_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A,b) == 8, "");
#endif
_Static_assert(sizeof(A_) == 1, "");
_Static_assert(_Alignof(A_) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A__alignment) == 2, "");
_Static_assert(_Alignof(struct A__alignment) == 1, "");
_Static_assert(sizeof(struct A__packed) == 1, "");
_Static_assert(_Alignof(struct A__packed) == 1, "");
_Static_assert(sizeof(struct A__required_alignment) == 2, "");
_Static_assert(_Alignof(struct A__required_alignment) == 1, "");
_Static_assert(sizeof(struct A__size) == 3, "");
_Static_assert(_Alignof(struct A__size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_,b) == 0, "");
#endif
_Static_assert(sizeof(B) == 2, "");
_Static_assert(_Alignof(B) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 3, "");
_Static_assert(_Alignof(struct B_alignment) == 1, "");
_Static_assert(sizeof(struct B_packed) == 2, "");
_Static_assert(_Alignof(struct B_packed) == 1, "");
_Static_assert(sizeof(struct B_required_alignment) == 3, "");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "");
_Static_assert(sizeof(struct B_size) == 4, "");
_Static_assert(_Alignof(struct B_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B,b) == 8, "");
#endif
_Static_assert(sizeof(B_) == 1, "");
_Static_assert(_Alignof(B_) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B__alignment) == 2, "");
_Static_assert(_Alignof(struct B__alignment) == 1, "");
_Static_assert(sizeof(struct B__packed) == 1, "");
_Static_assert(_Alignof(struct B__packed) == 1, "");
_Static_assert(sizeof(struct B__required_alignment) == 2, "");
_Static_assert(_Alignof(struct B__required_alignment) == 1, "");
_Static_assert(sizeof(struct B__size) == 3, "");
_Static_assert(_Alignof(struct B__size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B_,b) == 0, "");
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
_Static_assert(__builtin_bitoffsetof(C,b) == 8, "");
#endif
_Static_assert(sizeof(C_) == 1, "");
_Static_assert(_Alignof(C_) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C__alignment) == 2, "");
_Static_assert(_Alignof(struct C__alignment) == 1, "");
_Static_assert(sizeof(struct C__packed) == 1, "");
_Static_assert(_Alignof(struct C__packed) == 1, "");
_Static_assert(sizeof(struct C__required_alignment) == 2, "");
_Static_assert(_Alignof(struct C__required_alignment) == 1, "");
_Static_assert(sizeof(struct C__size) == 3, "");
_Static_assert(_Alignof(struct C__size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C_,b) == 0, "");
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
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D,b) == 8, "");
#endif
_Static_assert(sizeof(D_) == 1, "");
_Static_assert(_Alignof(D_) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D__alignment) == 2, "");
_Static_assert(_Alignof(struct D__alignment) == 1, "");
_Static_assert(sizeof(struct D__packed) == 1, "");
_Static_assert(_Alignof(struct D__packed) == 1, "");
_Static_assert(sizeof(struct D__required_alignment) == 2, "");
_Static_assert(_Alignof(struct D__required_alignment) == 1, "");
_Static_assert(sizeof(struct D__size) == 3, "");
_Static_assert(_Alignof(struct D__size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D_,b) == 0, "");
#endif
_Static_assert(sizeof(E) == 256, "");
_Static_assert(_Alignof(E) == 128, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 384, "");
_Static_assert(_Alignof(struct E_alignment) == 128, "");
_Static_assert(sizeof(struct E_packed) == 256, "");
_Static_assert(_Alignof(struct E_packed) == 1, "");
_Static_assert(sizeof(struct E_required_alignment) == 257, "");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "");
_Static_assert(sizeof(struct E_size) == 258, "");
_Static_assert(_Alignof(struct E_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(E,b) == 1024, "");
#endif
_Static_assert(sizeof(E_) == 128, "");
_Static_assert(_Alignof(E_) == 128, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E__alignment) == 256, "");
_Static_assert(_Alignof(struct E__alignment) == 128, "");
_Static_assert(sizeof(struct E__packed) == 128, "");
_Static_assert(_Alignof(struct E__packed) == 1, "");
_Static_assert(sizeof(struct E__required_alignment) == 129, "");
_Static_assert(_Alignof(struct E__required_alignment) == 1, "");
_Static_assert(sizeof(struct E__size) == 130, "");
_Static_assert(_Alignof(struct E__size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(E_,b) == 0, "");
#endif
_Static_assert(sizeof(F) == 256, "");
_Static_assert(_Alignof(F) == 128, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 384, "");
_Static_assert(_Alignof(struct F_alignment) == 128, "");
_Static_assert(sizeof(struct F_packed) == 256, "");
_Static_assert(_Alignof(struct F_packed) == 1, "");
_Static_assert(sizeof(struct F_required_alignment) == 257, "");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "");
_Static_assert(sizeof(struct F_size) == 258, "");
_Static_assert(_Alignof(struct F_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F,b) == 1024, "");
#endif
_Static_assert(sizeof(F_) == 128, "");
_Static_assert(_Alignof(F_) == 128, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F__alignment) == 256, "");
_Static_assert(_Alignof(struct F__alignment) == 128, "");
_Static_assert(sizeof(struct F__packed) == 128, "");
_Static_assert(_Alignof(struct F__packed) == 1, "");
_Static_assert(sizeof(struct F__required_alignment) == 129, "");
_Static_assert(_Alignof(struct F__required_alignment) == 1, "");
_Static_assert(sizeof(struct F__size) == 130, "");
_Static_assert(_Alignof(struct F__size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F_,b) == 0, "");
#endif
_Static_assert(sizeof(G) == 256, "");
_Static_assert(_Alignof(G) == 128, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 384, "");
_Static_assert(_Alignof(struct G_alignment) == 128, "");
_Static_assert(sizeof(struct G_packed) == 256, "");
_Static_assert(_Alignof(struct G_packed) == 1, "");
_Static_assert(sizeof(struct G_required_alignment) == 257, "");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "");
_Static_assert(sizeof(struct G_size) == 258, "");
_Static_assert(_Alignof(struct G_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(G,b) == 1024, "");
#endif
_Static_assert(sizeof(G_) == 128, "");
_Static_assert(_Alignof(G_) == 128, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G__alignment) == 256, "");
_Static_assert(_Alignof(struct G__alignment) == 128, "");
_Static_assert(sizeof(struct G__packed) == 128, "");
_Static_assert(_Alignof(struct G__packed) == 1, "");
_Static_assert(sizeof(struct G__required_alignment) == 129, "");
_Static_assert(_Alignof(struct G__required_alignment) == 1, "");
_Static_assert(sizeof(struct G__size) == 130, "");
_Static_assert(_Alignof(struct G__size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(G_,b) == 0, "");
#endif
_Static_assert(sizeof(H) == 256, "");
_Static_assert(_Alignof(H) == 128, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 384, "");
_Static_assert(_Alignof(struct H_alignment) == 128, "");
_Static_assert(sizeof(struct H_packed) == 256, "");
_Static_assert(_Alignof(struct H_packed) == 1, "");
_Static_assert(sizeof(struct H_required_alignment) == 257, "");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "");
_Static_assert(sizeof(struct H_size) == 258, "");
_Static_assert(_Alignof(struct H_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(H,b) == 1024, "");
#endif
_Static_assert(sizeof(H_) == 128, "");
_Static_assert(_Alignof(H_) == 128, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H__alignment) == 256, "");
_Static_assert(_Alignof(struct H__alignment) == 128, "");
_Static_assert(sizeof(struct H__packed) == 128, "");
_Static_assert(_Alignof(struct H__packed) == 1, "");
_Static_assert(sizeof(struct H__required_alignment) == 129, "");
_Static_assert(_Alignof(struct H__required_alignment) == 1, "");
_Static_assert(sizeof(struct H__size) == 130, "");
_Static_assert(_Alignof(struct H__size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(H_,b) == 0, "");
#endif
_Static_assert(sizeof(I) == 8, "");
_Static_assert(_Alignof(I) == 128, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I_alignment) == 256, "");
_Static_assert(_Alignof(struct I_alignment) == 128, "");
_Static_assert(sizeof(struct I_packed) == 8, "");
_Static_assert(_Alignof(struct I_packed) == 1, "");
_Static_assert(sizeof(struct I_required_alignment) == 9, "");
_Static_assert(_Alignof(struct I_required_alignment) == 1, "");
_Static_assert(sizeof(struct I_size) == 10, "");
_Static_assert(_Alignof(struct I_size) == 1, "");
#endif
_Static_assert(sizeof(J) == 2, "");
_Static_assert(_Alignof(J) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J_alignment) == 3, "");
_Static_assert(_Alignof(struct J_alignment) == 1, "");
_Static_assert(sizeof(struct J_packed) == 2, "");
_Static_assert(_Alignof(struct J_packed) == 1, "");
_Static_assert(sizeof(struct J_required_alignment) == 3, "");
_Static_assert(_Alignof(struct J_required_alignment) == 1, "");
_Static_assert(sizeof(struct J_size) == 4, "");
_Static_assert(_Alignof(struct J_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(J,b) == 8, "");
#endif
_Static_assert(sizeof(J_) == 1, "");
_Static_assert(_Alignof(J_) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J__alignment) == 2, "");
_Static_assert(_Alignof(struct J__alignment) == 1, "");
_Static_assert(sizeof(struct J__packed) == 1, "");
_Static_assert(_Alignof(struct J__packed) == 1, "");
_Static_assert(sizeof(struct J__required_alignment) == 2, "");
_Static_assert(_Alignof(struct J__required_alignment) == 1, "");
_Static_assert(sizeof(struct J__size) == 3, "");
_Static_assert(_Alignof(struct J__size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(J_,b) == 0, "");
#endif
// MAPPING|FIVE|i386-i386-ios-none:Clang|i386-i586-linux-gnu:Gcc|i386-i586-linux-musl:Gcc|x86_64-i686-macos-none:Clang|i386-i686-linux-android:Clang|i386-i686-freebsd-gnu:Clang|i386-i686-haiku-gnu:Clang|i386-i686-linux-gnu:Gcc|i386-i686-linux-musl:Gcc|i386-i686-netbsd-gnu:Clang|i386-i686-openbsd-gnu:Clang|END
// repr targets I386AppleIos|Some("i386-i386-ios-none") I586UnknownLinuxGnu|Some("i386-i586-linux-gnu") I586UnknownLinuxMusl|Some("i386-i586-linux-musl") I686AppleMacosx|Some("x86_64-i686-macos-none") I686LinuxAndroid|Some("i386-i686-linux-android") I686UnknownFreebsd|Some("i386-i686-freebsd-gnu") I686UnknownHaiku|Some("i386-i686-haiku-gnu") I686UnknownLinuxGnu|Some("i386-i686-linux-gnu") I686UnknownLinuxMusl|Some("i386-i686-linux-musl") I686UnknownNetbsdelf|Some("i386-i686-netbsd-gnu") I686UnknownOpenbsd|Some("i386-i686-openbsd-gnu") 
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
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A,b) == 32, "");
#endif
_Static_assert(sizeof(A_) == 4, "");
_Static_assert(_Alignof(A_) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A__alignment) == 8, "");
_Static_assert(_Alignof(struct A__alignment) == 4, "");
_Static_assert(sizeof(struct A__packed) == 4, "");
_Static_assert(_Alignof(struct A__packed) == 1, "");
_Static_assert(sizeof(struct A__required_alignment) == 5, "");
_Static_assert(_Alignof(struct A__required_alignment) == 1, "");
_Static_assert(sizeof(struct A__size) == 6, "");
_Static_assert(_Alignof(struct A__size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_,b) == 0, "");
#endif
_Static_assert(sizeof(B) == 8, "");
_Static_assert(_Alignof(B) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 12, "");
_Static_assert(_Alignof(struct B_alignment) == 4, "");
_Static_assert(sizeof(struct B_packed) == 8, "");
_Static_assert(_Alignof(struct B_packed) == 1, "");
_Static_assert(sizeof(struct B_required_alignment) == 9, "");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "");
_Static_assert(sizeof(struct B_size) == 10, "");
_Static_assert(_Alignof(struct B_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B,b) == 32, "");
#endif
_Static_assert(sizeof(B_) == 4, "");
_Static_assert(_Alignof(B_) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B__alignment) == 8, "");
_Static_assert(_Alignof(struct B__alignment) == 4, "");
_Static_assert(sizeof(struct B__packed) == 4, "");
_Static_assert(_Alignof(struct B__packed) == 1, "");
_Static_assert(sizeof(struct B__required_alignment) == 5, "");
_Static_assert(_Alignof(struct B__required_alignment) == 1, "");
_Static_assert(sizeof(struct B__size) == 6, "");
_Static_assert(_Alignof(struct B__size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B_,b) == 0, "");
#endif
_Static_assert(sizeof(C) == 5, "");
_Static_assert(_Alignof(C) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 6, "");
_Static_assert(_Alignof(struct C_alignment) == 1, "");
_Static_assert(sizeof(struct C_packed) == 5, "");
_Static_assert(_Alignof(struct C_packed) == 1, "");
_Static_assert(sizeof(struct C_required_alignment) == 6, "");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "");
_Static_assert(sizeof(struct C_size) == 7, "");
_Static_assert(_Alignof(struct C_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C,b) == 32, "");
#endif
_Static_assert(sizeof(C_) == 1, "");
_Static_assert(_Alignof(C_) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C__alignment) == 2, "");
_Static_assert(_Alignof(struct C__alignment) == 1, "");
_Static_assert(sizeof(struct C__packed) == 1, "");
_Static_assert(_Alignof(struct C__packed) == 1, "");
_Static_assert(sizeof(struct C__required_alignment) == 2, "");
_Static_assert(_Alignof(struct C__required_alignment) == 1, "");
_Static_assert(sizeof(struct C__size) == 3, "");
_Static_assert(_Alignof(struct C__size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C_,b) == 0, "");
#endif
_Static_assert(sizeof(D) == 5, "");
_Static_assert(_Alignof(D) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 6, "");
_Static_assert(_Alignof(struct D_alignment) == 1, "");
_Static_assert(sizeof(struct D_packed) == 5, "");
_Static_assert(_Alignof(struct D_packed) == 1, "");
_Static_assert(sizeof(struct D_required_alignment) == 6, "");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "");
_Static_assert(sizeof(struct D_size) == 7, "");
_Static_assert(_Alignof(struct D_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D,b) == 32, "");
#endif
_Static_assert(sizeof(D_) == 1, "");
_Static_assert(_Alignof(D_) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D__alignment) == 2, "");
_Static_assert(_Alignof(struct D__alignment) == 1, "");
_Static_assert(sizeof(struct D__packed) == 1, "");
_Static_assert(_Alignof(struct D__packed) == 1, "");
_Static_assert(sizeof(struct D__required_alignment) == 2, "");
_Static_assert(_Alignof(struct D__required_alignment) == 1, "");
_Static_assert(sizeof(struct D__size) == 3, "");
_Static_assert(_Alignof(struct D__size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D_,b) == 0, "");
#endif
_Static_assert(sizeof(E) == 129, "");
_Static_assert(_Alignof(E) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 130, "");
_Static_assert(_Alignof(struct E_alignment) == 1, "");
_Static_assert(sizeof(struct E_packed) == 129, "");
_Static_assert(_Alignof(struct E_packed) == 1, "");
_Static_assert(sizeof(struct E_required_alignment) == 130, "");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "");
_Static_assert(sizeof(struct E_size) == 131, "");
_Static_assert(_Alignof(struct E_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(E,b) == 1024, "");
#endif
_Static_assert(sizeof(E_) == 1, "");
_Static_assert(_Alignof(E_) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E__alignment) == 2, "");
_Static_assert(_Alignof(struct E__alignment) == 1, "");
_Static_assert(sizeof(struct E__packed) == 1, "");
_Static_assert(_Alignof(struct E__packed) == 1, "");
_Static_assert(sizeof(struct E__required_alignment) == 2, "");
_Static_assert(_Alignof(struct E__required_alignment) == 1, "");
_Static_assert(sizeof(struct E__size) == 3, "");
_Static_assert(_Alignof(struct E__size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(E_,b) == 0, "");
#endif
_Static_assert(sizeof(F) == 129, "");
_Static_assert(_Alignof(F) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 130, "");
_Static_assert(_Alignof(struct F_alignment) == 1, "");
_Static_assert(sizeof(struct F_packed) == 129, "");
_Static_assert(_Alignof(struct F_packed) == 1, "");
_Static_assert(sizeof(struct F_required_alignment) == 130, "");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "");
_Static_assert(sizeof(struct F_size) == 131, "");
_Static_assert(_Alignof(struct F_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F,b) == 1024, "");
#endif
_Static_assert(sizeof(F_) == 1, "");
_Static_assert(_Alignof(F_) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F__alignment) == 2, "");
_Static_assert(_Alignof(struct F__alignment) == 1, "");
_Static_assert(sizeof(struct F__packed) == 1, "");
_Static_assert(_Alignof(struct F__packed) == 1, "");
_Static_assert(sizeof(struct F__required_alignment) == 2, "");
_Static_assert(_Alignof(struct F__required_alignment) == 1, "");
_Static_assert(sizeof(struct F__size) == 3, "");
_Static_assert(_Alignof(struct F__size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F_,b) == 0, "");
#endif
_Static_assert(sizeof(G) == 132, "");
_Static_assert(_Alignof(G) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 136, "");
_Static_assert(_Alignof(struct G_alignment) == 4, "");
_Static_assert(sizeof(struct G_packed) == 132, "");
_Static_assert(_Alignof(struct G_packed) == 1, "");
_Static_assert(sizeof(struct G_required_alignment) == 133, "");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "");
_Static_assert(sizeof(struct G_size) == 134, "");
_Static_assert(_Alignof(struct G_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(G,b) == 1024, "");
#endif
_Static_assert(sizeof(G_) == 4, "");
_Static_assert(_Alignof(G_) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G__alignment) == 8, "");
_Static_assert(_Alignof(struct G__alignment) == 4, "");
_Static_assert(sizeof(struct G__packed) == 4, "");
_Static_assert(_Alignof(struct G__packed) == 1, "");
_Static_assert(sizeof(struct G__required_alignment) == 5, "");
_Static_assert(_Alignof(struct G__required_alignment) == 1, "");
_Static_assert(sizeof(struct G__size) == 6, "");
_Static_assert(_Alignof(struct G__size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(G_,b) == 0, "");
#endif
_Static_assert(sizeof(H) == 129, "");
_Static_assert(_Alignof(H) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 130, "");
_Static_assert(_Alignof(struct H_alignment) == 1, "");
_Static_assert(sizeof(struct H_packed) == 129, "");
_Static_assert(_Alignof(struct H_packed) == 1, "");
_Static_assert(sizeof(struct H_required_alignment) == 130, "");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "");
_Static_assert(sizeof(struct H_size) == 131, "");
_Static_assert(_Alignof(struct H_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(H,b) == 1024, "");
#endif
_Static_assert(sizeof(H_) == 1, "");
_Static_assert(_Alignof(H_) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H__alignment) == 2, "");
_Static_assert(_Alignof(struct H__alignment) == 1, "");
_Static_assert(sizeof(struct H__packed) == 1, "");
_Static_assert(_Alignof(struct H__packed) == 1, "");
_Static_assert(sizeof(struct H__required_alignment) == 2, "");
_Static_assert(_Alignof(struct H__required_alignment) == 1, "");
_Static_assert(sizeof(struct H__size) == 3, "");
_Static_assert(_Alignof(struct H__size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(H_,b) == 0, "");
#endif
_Static_assert(sizeof(I) == 8, "");
_Static_assert(_Alignof(I) == 128, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I_alignment) == 256, "");
_Static_assert(_Alignof(struct I_alignment) == 128, "");
_Static_assert(sizeof(struct I_packed) == 8, "");
_Static_assert(_Alignof(struct I_packed) == 1, "");
_Static_assert(sizeof(struct I_required_alignment) == 9, "");
_Static_assert(_Alignof(struct I_required_alignment) == 1, "");
_Static_assert(sizeof(struct I_size) == 10, "");
_Static_assert(_Alignof(struct I_size) == 1, "");
#endif
_Static_assert(sizeof(J) == 132, "");
_Static_assert(_Alignof(J) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J_alignment) == 136, "");
_Static_assert(_Alignof(struct J_alignment) == 4, "");
_Static_assert(sizeof(struct J_packed) == 132, "");
_Static_assert(_Alignof(struct J_packed) == 1, "");
_Static_assert(sizeof(struct J_required_alignment) == 133, "");
_Static_assert(_Alignof(struct J_required_alignment) == 1, "");
_Static_assert(sizeof(struct J_size) == 134, "");
_Static_assert(_Alignof(struct J_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(J,b) == 1024, "");
#endif
_Static_assert(sizeof(J_) == 4, "");
_Static_assert(_Alignof(J_) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J__alignment) == 8, "");
_Static_assert(_Alignof(struct J__alignment) == 4, "");
_Static_assert(sizeof(struct J__packed) == 4, "");
_Static_assert(_Alignof(struct J__packed) == 1, "");
_Static_assert(sizeof(struct J__required_alignment) == 5, "");
_Static_assert(_Alignof(struct J__required_alignment) == 1, "");
_Static_assert(sizeof(struct J__size) == 6, "");
_Static_assert(_Alignof(struct J__size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(J_,b) == 0, "");
#endif
// MAPPING|SIX|i386-i686-windows-gnu:Gcc|x86_64-x86_64-windows-gnu:Gcc|END
// repr targets I686PcWindowsGnu|Some("i386-i686-windows-gnu") X86_64PcWindowsGnu|Some("x86_64-x86_64-windows-gnu") 
#elif defined(SIX)
_Static_assert(sizeof(A) == 16, "");
_Static_assert(_Alignof(A) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 24, "");
_Static_assert(_Alignof(struct A_alignment) == 8, "");
_Static_assert(sizeof(struct A_packed) == 16, "");
_Static_assert(_Alignof(struct A_packed) == 1, "");
_Static_assert(sizeof(struct A_required_alignment) == 17, "");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "");
_Static_assert(sizeof(struct A_size) == 18, "");
_Static_assert(_Alignof(struct A_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A,b) == 64, "");
#endif
_Static_assert(sizeof(A_) == 8, "");
_Static_assert(_Alignof(A_) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A__alignment) == 16, "");
_Static_assert(_Alignof(struct A__alignment) == 8, "");
_Static_assert(sizeof(struct A__packed) == 8, "");
_Static_assert(_Alignof(struct A__packed) == 1, "");
_Static_assert(sizeof(struct A__required_alignment) == 9, "");
_Static_assert(_Alignof(struct A__required_alignment) == 1, "");
_Static_assert(sizeof(struct A__size) == 10, "");
_Static_assert(_Alignof(struct A__size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_,b) == 0, "");
#endif
_Static_assert(sizeof(B) == 16, "");
_Static_assert(_Alignof(B) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 24, "");
_Static_assert(_Alignof(struct B_alignment) == 8, "");
_Static_assert(sizeof(struct B_packed) == 16, "");
_Static_assert(_Alignof(struct B_packed) == 1, "");
_Static_assert(sizeof(struct B_required_alignment) == 17, "");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "");
_Static_assert(sizeof(struct B_size) == 18, "");
_Static_assert(_Alignof(struct B_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B,b) == 64, "");
#endif
_Static_assert(sizeof(B_) == 8, "");
_Static_assert(_Alignof(B_) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B__alignment) == 16, "");
_Static_assert(_Alignof(struct B__alignment) == 8, "");
_Static_assert(sizeof(struct B__packed) == 8, "");
_Static_assert(_Alignof(struct B__packed) == 1, "");
_Static_assert(sizeof(struct B__required_alignment) == 9, "");
_Static_assert(_Alignof(struct B__required_alignment) == 1, "");
_Static_assert(sizeof(struct B__size) == 10, "");
_Static_assert(_Alignof(struct B__size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B_,b) == 0, "");
#endif
_Static_assert(sizeof(C) == 16, "");
_Static_assert(_Alignof(C) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 24, "");
_Static_assert(_Alignof(struct C_alignment) == 8, "");
_Static_assert(sizeof(struct C_packed) == 16, "");
_Static_assert(_Alignof(struct C_packed) == 1, "");
_Static_assert(sizeof(struct C_required_alignment) == 17, "");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "");
_Static_assert(sizeof(struct C_size) == 18, "");
_Static_assert(_Alignof(struct C_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C,b) == 64, "");
#endif
_Static_assert(sizeof(C_) == 1, "");
_Static_assert(_Alignof(C_) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C__alignment) == 2, "");
_Static_assert(_Alignof(struct C__alignment) == 1, "");
_Static_assert(sizeof(struct C__packed) == 1, "");
_Static_assert(_Alignof(struct C__packed) == 1, "");
_Static_assert(sizeof(struct C__required_alignment) == 2, "");
_Static_assert(_Alignof(struct C__required_alignment) == 1, "");
_Static_assert(sizeof(struct C__size) == 3, "");
_Static_assert(_Alignof(struct C__size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C_,b) == 0, "");
#endif
_Static_assert(sizeof(D) == 16, "");
_Static_assert(_Alignof(D) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 17, "");
_Static_assert(_Alignof(struct D_alignment) == 1, "");
_Static_assert(sizeof(struct D_packed) == 16, "");
_Static_assert(_Alignof(struct D_packed) == 1, "");
_Static_assert(sizeof(struct D_required_alignment) == 17, "");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "");
_Static_assert(sizeof(struct D_size) == 18, "");
_Static_assert(_Alignof(struct D_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D,b) == 64, "");
#endif
_Static_assert(sizeof(D_) == 1, "");
_Static_assert(_Alignof(D_) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D__alignment) == 2, "");
_Static_assert(_Alignof(struct D__alignment) == 1, "");
_Static_assert(sizeof(struct D__packed) == 1, "");
_Static_assert(_Alignof(struct D__packed) == 1, "");
_Static_assert(sizeof(struct D__required_alignment) == 2, "");
_Static_assert(_Alignof(struct D__required_alignment) == 1, "");
_Static_assert(sizeof(struct D__size) == 3, "");
_Static_assert(_Alignof(struct D__size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D_,b) == 0, "");
#endif
_Static_assert(sizeof(E) == 16, "");
_Static_assert(_Alignof(E) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 17, "");
_Static_assert(_Alignof(struct E_alignment) == 1, "");
_Static_assert(sizeof(struct E_packed) == 16, "");
_Static_assert(_Alignof(struct E_packed) == 1, "");
_Static_assert(sizeof(struct E_required_alignment) == 17, "");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "");
_Static_assert(sizeof(struct E_size) == 18, "");
_Static_assert(_Alignof(struct E_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(E,b) == 64, "");
#endif
_Static_assert(sizeof(E_) == 1, "");
_Static_assert(_Alignof(E_) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E__alignment) == 2, "");
_Static_assert(_Alignof(struct E__alignment) == 1, "");
_Static_assert(sizeof(struct E__packed) == 1, "");
_Static_assert(_Alignof(struct E__packed) == 1, "");
_Static_assert(sizeof(struct E__required_alignment) == 2, "");
_Static_assert(_Alignof(struct E__required_alignment) == 1, "");
_Static_assert(sizeof(struct E__size) == 3, "");
_Static_assert(_Alignof(struct E__size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(E_,b) == 0, "");
#endif
_Static_assert(sizeof(F) == 256, "");
_Static_assert(_Alignof(F) == 128, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 384, "");
_Static_assert(_Alignof(struct F_alignment) == 128, "");
_Static_assert(sizeof(struct F_packed) == 256, "");
_Static_assert(_Alignof(struct F_packed) == 1, "");
_Static_assert(sizeof(struct F_required_alignment) == 257, "");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "");
_Static_assert(sizeof(struct F_size) == 258, "");
_Static_assert(_Alignof(struct F_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F,b) == 1024, "");
#endif
_Static_assert(sizeof(F_) == 1, "");
_Static_assert(_Alignof(F_) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F__alignment) == 2, "");
_Static_assert(_Alignof(struct F__alignment) == 1, "");
_Static_assert(sizeof(struct F__packed) == 1, "");
_Static_assert(_Alignof(struct F__packed) == 1, "");
_Static_assert(sizeof(struct F__required_alignment) == 2, "");
_Static_assert(_Alignof(struct F__required_alignment) == 1, "");
_Static_assert(sizeof(struct F__size) == 3, "");
_Static_assert(_Alignof(struct F__size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F_,b) == 0, "");
#endif
_Static_assert(sizeof(G) == 256, "");
_Static_assert(_Alignof(G) == 128, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 384, "");
_Static_assert(_Alignof(struct G_alignment) == 128, "");
_Static_assert(sizeof(struct G_packed) == 256, "");
_Static_assert(_Alignof(struct G_packed) == 1, "");
_Static_assert(sizeof(struct G_required_alignment) == 257, "");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "");
_Static_assert(sizeof(struct G_size) == 258, "");
_Static_assert(_Alignof(struct G_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(G,b) == 1024, "");
#endif
_Static_assert(sizeof(G_) == 8, "");
_Static_assert(_Alignof(G_) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G__alignment) == 16, "");
_Static_assert(_Alignof(struct G__alignment) == 8, "");
_Static_assert(sizeof(struct G__packed) == 8, "");
_Static_assert(_Alignof(struct G__packed) == 1, "");
_Static_assert(sizeof(struct G__required_alignment) == 9, "");
_Static_assert(_Alignof(struct G__required_alignment) == 1, "");
_Static_assert(sizeof(struct G__size) == 10, "");
_Static_assert(_Alignof(struct G__size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(G_,b) == 0, "");
#endif
_Static_assert(sizeof(H) == 16, "");
_Static_assert(_Alignof(H) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 17, "");
_Static_assert(_Alignof(struct H_alignment) == 1, "");
_Static_assert(sizeof(struct H_packed) == 16, "");
_Static_assert(_Alignof(struct H_packed) == 1, "");
_Static_assert(sizeof(struct H_required_alignment) == 17, "");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "");
_Static_assert(sizeof(struct H_size) == 18, "");
_Static_assert(_Alignof(struct H_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(H,b) == 64, "");
#endif
_Static_assert(sizeof(H_) == 1, "");
_Static_assert(_Alignof(H_) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H__alignment) == 2, "");
_Static_assert(_Alignof(struct H__alignment) == 1, "");
_Static_assert(sizeof(struct H__packed) == 1, "");
_Static_assert(_Alignof(struct H__packed) == 1, "");
_Static_assert(sizeof(struct H__required_alignment) == 2, "");
_Static_assert(_Alignof(struct H__required_alignment) == 1, "");
_Static_assert(sizeof(struct H__size) == 3, "");
_Static_assert(_Alignof(struct H__size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(H_,b) == 0, "");
#endif
_Static_assert(sizeof(I) == 8, "");
_Static_assert(_Alignof(I) == 128, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I_alignment) == 256, "");
_Static_assert(_Alignof(struct I_alignment) == 128, "");
_Static_assert(sizeof(struct I_packed) == 8, "");
_Static_assert(_Alignof(struct I_packed) == 1, "");
_Static_assert(sizeof(struct I_required_alignment) == 9, "");
_Static_assert(_Alignof(struct I_required_alignment) == 1, "");
_Static_assert(sizeof(struct I_size) == 10, "");
_Static_assert(_Alignof(struct I_size) == 1, "");
#endif
_Static_assert(sizeof(J) == 128, "");
_Static_assert(_Alignof(J) == 128, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J_alignment) == 256, "");
_Static_assert(_Alignof(struct J_alignment) == 128, "");
_Static_assert(sizeof(struct J_packed) == 128, "");
_Static_assert(_Alignof(struct J_packed) == 1, "");
_Static_assert(sizeof(struct J_required_alignment) == 129, "");
_Static_assert(_Alignof(struct J_required_alignment) == 1, "");
_Static_assert(sizeof(struct J_size) == 130, "");
_Static_assert(_Alignof(struct J_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(J,b) == 64, "");
#endif
_Static_assert(sizeof(J_) == 8, "");
_Static_assert(_Alignof(J_) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J__alignment) == 16, "");
_Static_assert(_Alignof(struct J__alignment) == 8, "");
_Static_assert(sizeof(struct J__packed) == 8, "");
_Static_assert(_Alignof(struct J__packed) == 1, "");
_Static_assert(sizeof(struct J__required_alignment) == 9, "");
_Static_assert(_Alignof(struct J__required_alignment) == 1, "");
_Static_assert(sizeof(struct J__size) == 10, "");
_Static_assert(_Alignof(struct J__size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(J_,b) == 0, "");
#endif
// MAPPING|SEVEN|msp430-msp430-other-none:Clang|END
// repr targets Msp430NoneElf|Some("msp430-msp430-other-none") 
#elif defined(SEVEN)
_Static_assert(sizeof(A) == 4, "");
_Static_assert(_Alignof(A) == 2, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 6, "");
_Static_assert(_Alignof(struct A_alignment) == 2, "");
_Static_assert(sizeof(struct A_packed) == 4, "");
_Static_assert(_Alignof(struct A_packed) == 1, "");
_Static_assert(sizeof(struct A_required_alignment) == 5, "");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "");
_Static_assert(sizeof(struct A_size) == 6, "");
_Static_assert(_Alignof(struct A_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A,b) == 16, "");
#endif
_Static_assert(sizeof(A_) == 2, "");
_Static_assert(_Alignof(A_) == 2, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A__alignment) == 4, "");
_Static_assert(_Alignof(struct A__alignment) == 2, "");
_Static_assert(sizeof(struct A__packed) == 2, "");
_Static_assert(_Alignof(struct A__packed) == 1, "");
_Static_assert(sizeof(struct A__required_alignment) == 3, "");
_Static_assert(_Alignof(struct A__required_alignment) == 1, "");
_Static_assert(sizeof(struct A__size) == 4, "");
_Static_assert(_Alignof(struct A__size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_,b) == 0, "");
#endif
_Static_assert(sizeof(B) == 4, "");
_Static_assert(_Alignof(B) == 2, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 6, "");
_Static_assert(_Alignof(struct B_alignment) == 2, "");
_Static_assert(sizeof(struct B_packed) == 4, "");
_Static_assert(_Alignof(struct B_packed) == 1, "");
_Static_assert(sizeof(struct B_required_alignment) == 5, "");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "");
_Static_assert(sizeof(struct B_size) == 6, "");
_Static_assert(_Alignof(struct B_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B,b) == 16, "");
#endif
_Static_assert(sizeof(B_) == 2, "");
_Static_assert(_Alignof(B_) == 2, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B__alignment) == 4, "");
_Static_assert(_Alignof(struct B__alignment) == 2, "");
_Static_assert(sizeof(struct B__packed) == 2, "");
_Static_assert(_Alignof(struct B__packed) == 1, "");
_Static_assert(sizeof(struct B__required_alignment) == 3, "");
_Static_assert(_Alignof(struct B__required_alignment) == 1, "");
_Static_assert(sizeof(struct B__size) == 4, "");
_Static_assert(_Alignof(struct B__size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B_,b) == 0, "");
#endif
_Static_assert(sizeof(C) == 3, "");
_Static_assert(_Alignof(C) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 4, "");
_Static_assert(_Alignof(struct C_alignment) == 1, "");
_Static_assert(sizeof(struct C_packed) == 3, "");
_Static_assert(_Alignof(struct C_packed) == 1, "");
_Static_assert(sizeof(struct C_required_alignment) == 4, "");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "");
_Static_assert(sizeof(struct C_size) == 5, "");
_Static_assert(_Alignof(struct C_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C,b) == 16, "");
#endif
_Static_assert(sizeof(C_) == 1, "");
_Static_assert(_Alignof(C_) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C__alignment) == 2, "");
_Static_assert(_Alignof(struct C__alignment) == 1, "");
_Static_assert(sizeof(struct C__packed) == 1, "");
_Static_assert(_Alignof(struct C__packed) == 1, "");
_Static_assert(sizeof(struct C__required_alignment) == 2, "");
_Static_assert(_Alignof(struct C__required_alignment) == 1, "");
_Static_assert(sizeof(struct C__size) == 3, "");
_Static_assert(_Alignof(struct C__size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C_,b) == 0, "");
#endif
_Static_assert(sizeof(D) == 3, "");
_Static_assert(_Alignof(D) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 4, "");
_Static_assert(_Alignof(struct D_alignment) == 1, "");
_Static_assert(sizeof(struct D_packed) == 3, "");
_Static_assert(_Alignof(struct D_packed) == 1, "");
_Static_assert(sizeof(struct D_required_alignment) == 4, "");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "");
_Static_assert(sizeof(struct D_size) == 5, "");
_Static_assert(_Alignof(struct D_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D,b) == 16, "");
#endif
_Static_assert(sizeof(D_) == 1, "");
_Static_assert(_Alignof(D_) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D__alignment) == 2, "");
_Static_assert(_Alignof(struct D__alignment) == 1, "");
_Static_assert(sizeof(struct D__packed) == 1, "");
_Static_assert(_Alignof(struct D__packed) == 1, "");
_Static_assert(sizeof(struct D__required_alignment) == 2, "");
_Static_assert(_Alignof(struct D__required_alignment) == 1, "");
_Static_assert(sizeof(struct D__size) == 3, "");
_Static_assert(_Alignof(struct D__size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D_,b) == 0, "");
#endif
_Static_assert(sizeof(E) == 129, "");
_Static_assert(_Alignof(E) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 130, "");
_Static_assert(_Alignof(struct E_alignment) == 1, "");
_Static_assert(sizeof(struct E_packed) == 129, "");
_Static_assert(_Alignof(struct E_packed) == 1, "");
_Static_assert(sizeof(struct E_required_alignment) == 130, "");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "");
_Static_assert(sizeof(struct E_size) == 131, "");
_Static_assert(_Alignof(struct E_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(E,b) == 1024, "");
#endif
_Static_assert(sizeof(E_) == 1, "");
_Static_assert(_Alignof(E_) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E__alignment) == 2, "");
_Static_assert(_Alignof(struct E__alignment) == 1, "");
_Static_assert(sizeof(struct E__packed) == 1, "");
_Static_assert(_Alignof(struct E__packed) == 1, "");
_Static_assert(sizeof(struct E__required_alignment) == 2, "");
_Static_assert(_Alignof(struct E__required_alignment) == 1, "");
_Static_assert(sizeof(struct E__size) == 3, "");
_Static_assert(_Alignof(struct E__size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(E_,b) == 0, "");
#endif
_Static_assert(sizeof(F) == 129, "");
_Static_assert(_Alignof(F) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 130, "");
_Static_assert(_Alignof(struct F_alignment) == 1, "");
_Static_assert(sizeof(struct F_packed) == 129, "");
_Static_assert(_Alignof(struct F_packed) == 1, "");
_Static_assert(sizeof(struct F_required_alignment) == 130, "");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "");
_Static_assert(sizeof(struct F_size) == 131, "");
_Static_assert(_Alignof(struct F_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F,b) == 1024, "");
#endif
_Static_assert(sizeof(F_) == 1, "");
_Static_assert(_Alignof(F_) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F__alignment) == 2, "");
_Static_assert(_Alignof(struct F__alignment) == 1, "");
_Static_assert(sizeof(struct F__packed) == 1, "");
_Static_assert(_Alignof(struct F__packed) == 1, "");
_Static_assert(sizeof(struct F__required_alignment) == 2, "");
_Static_assert(_Alignof(struct F__required_alignment) == 1, "");
_Static_assert(sizeof(struct F__size) == 3, "");
_Static_assert(_Alignof(struct F__size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F_,b) == 0, "");
#endif
_Static_assert(sizeof(G) == 130, "");
_Static_assert(_Alignof(G) == 2, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 132, "");
_Static_assert(_Alignof(struct G_alignment) == 2, "");
_Static_assert(sizeof(struct G_packed) == 130, "");
_Static_assert(_Alignof(struct G_packed) == 1, "");
_Static_assert(sizeof(struct G_required_alignment) == 131, "");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "");
_Static_assert(sizeof(struct G_size) == 132, "");
_Static_assert(_Alignof(struct G_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(G,b) == 1024, "");
#endif
_Static_assert(sizeof(G_) == 2, "");
_Static_assert(_Alignof(G_) == 2, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G__alignment) == 4, "");
_Static_assert(_Alignof(struct G__alignment) == 2, "");
_Static_assert(sizeof(struct G__packed) == 2, "");
_Static_assert(_Alignof(struct G__packed) == 1, "");
_Static_assert(sizeof(struct G__required_alignment) == 3, "");
_Static_assert(_Alignof(struct G__required_alignment) == 1, "");
_Static_assert(sizeof(struct G__size) == 4, "");
_Static_assert(_Alignof(struct G__size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(G_,b) == 0, "");
#endif
_Static_assert(sizeof(H) == 129, "");
_Static_assert(_Alignof(H) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 130, "");
_Static_assert(_Alignof(struct H_alignment) == 1, "");
_Static_assert(sizeof(struct H_packed) == 129, "");
_Static_assert(_Alignof(struct H_packed) == 1, "");
_Static_assert(sizeof(struct H_required_alignment) == 130, "");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "");
_Static_assert(sizeof(struct H_size) == 131, "");
_Static_assert(_Alignof(struct H_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(H,b) == 1024, "");
#endif
_Static_assert(sizeof(H_) == 1, "");
_Static_assert(_Alignof(H_) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H__alignment) == 2, "");
_Static_assert(_Alignof(struct H__alignment) == 1, "");
_Static_assert(sizeof(struct H__packed) == 1, "");
_Static_assert(_Alignof(struct H__packed) == 1, "");
_Static_assert(sizeof(struct H__required_alignment) == 2, "");
_Static_assert(_Alignof(struct H__required_alignment) == 1, "");
_Static_assert(sizeof(struct H__size) == 3, "");
_Static_assert(_Alignof(struct H__size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(H_,b) == 0, "");
#endif
_Static_assert(sizeof(I) == 8, "");
_Static_assert(_Alignof(I) == 128, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I_alignment) == 256, "");
_Static_assert(_Alignof(struct I_alignment) == 128, "");
_Static_assert(sizeof(struct I_packed) == 8, "");
_Static_assert(_Alignof(struct I_packed) == 1, "");
_Static_assert(sizeof(struct I_required_alignment) == 9, "");
_Static_assert(_Alignof(struct I_required_alignment) == 1, "");
_Static_assert(sizeof(struct I_size) == 10, "");
_Static_assert(_Alignof(struct I_size) == 1, "");
#endif
_Static_assert(sizeof(J) == 130, "");
_Static_assert(_Alignof(J) == 2, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J_alignment) == 132, "");
_Static_assert(_Alignof(struct J_alignment) == 2, "");
_Static_assert(sizeof(struct J_packed) == 130, "");
_Static_assert(_Alignof(struct J_packed) == 1, "");
_Static_assert(sizeof(struct J_required_alignment) == 131, "");
_Static_assert(_Alignof(struct J_required_alignment) == 1, "");
_Static_assert(sizeof(struct J_size) == 132, "");
_Static_assert(_Alignof(struct J_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(J,b) == 1024, "");
#endif
_Static_assert(sizeof(J_) == 2, "");
_Static_assert(_Alignof(J_) == 2, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J__alignment) == 4, "");
_Static_assert(_Alignof(struct J__alignment) == 2, "");
_Static_assert(sizeof(struct J__packed) == 2, "");
_Static_assert(_Alignof(struct J__packed) == 1, "");
_Static_assert(sizeof(struct J__required_alignment) == 3, "");
_Static_assert(_Alignof(struct J__required_alignment) == 1, "");
_Static_assert(sizeof(struct J__size) == 4, "");
_Static_assert(_Alignof(struct J__size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(J_,b) == 0, "");
#endif
#endif
