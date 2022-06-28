// SPDX-License-Identifier: GPL-3.0-or-later

// This test file is auto-generated. do not edit.
// This file is a derivative work from the test files found// in this repo : https://github.com/mahkoh/repr-c
// and is under the same licence as the original work.

typedef struct {
#ifdef MSVC
    __declspec(align(128)) int i:1;
#else
    int i:1 __attribute__((aligned(128)));
#endif
} A;
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

typedef struct {
    char c;
    A a;
} A_;
A_ var5;
struct A__alignment {
#ifdef MSVC
    char a[_Alignof(A_)];
    char b;
#else
    char a;
    A_ b;
#endif
};
struct A__alignment var6;
#pragma pack(1)
struct A__packed {
    A_ a;
};
#pragma pack()
struct A__required_alignment {
#ifdef MSVC
    char a[_Alignof(struct A__packed)];
    char b;
#else
    char a;
    struct A__packed b;
#endif
};
struct A__required_alignment var7;
struct A__size {
    char a[sizeof(A_)+1];
    char b;
};
struct A__size var8;

typedef struct {
    A a;
} B;
B var9;
struct B_alignment {
#ifdef MSVC
    char a[_Alignof(B)];
    char b;
#else
    char a;
    B b;
#endif
};
struct B_alignment var10;
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
struct B_required_alignment var11;
struct B_size {
    char a[sizeof(B)+1];
    char b;
};
struct B_size var12;

#pragma pack(4)
typedef struct {
    A a;
} C;
C var13;
#pragma pack()
struct C_alignment {
#ifdef MSVC
    char a[_Alignof(C)];
    char b;
#else
    char a;
    C b;
#endif
};
struct C_alignment var14;
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
struct C_required_alignment var15;
struct C_size {
    char a[sizeof(C)+1];
    char b;
};
struct C_size var16;

#pragma pack(8)
typedef struct {
    A a;
} D;
D var17;
#pragma pack()
struct D_alignment {
#ifdef MSVC
    char a[_Alignof(D)];
    char b;
#else
    char a;
    D b;
#endif
};
struct D_alignment var18;
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
struct D_required_alignment var19;
struct D_size {
    char a[sizeof(D)+1];
    char b;
};
struct D_size var20;

#pragma pack(16)
typedef struct {
    A a;
} E;
E var21;
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
struct E_alignment var22;
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
struct E_required_alignment var23;
struct E_size {
    char a[sizeof(E)+1];
    char b;
};
struct E_size var24;

#pragma pack(32)
typedef struct {
    A a;
} F;
F var25;
#pragma pack()
struct F_alignment {
#ifdef MSVC
    char a[_Alignof(F)];
    char b;
#else
    char a;
    F b;
#endif
};
struct F_alignment var26;
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
struct F_required_alignment var27;
struct F_size {
    char a[sizeof(F)+1];
    char b;
};
struct F_size var28;

typedef union {
    A a;
} G;
G var29;
struct G_alignment {
#ifdef MSVC
    char a[_Alignof(G)];
    char b;
#else
    char a;
    G b;
#endif
};
struct G_alignment var30;
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
struct G_required_alignment var31;
struct G_size {
    char a[sizeof(G)+1];
    char b;
};
struct G_size var32;

#pragma pack(4)
typedef union {
    A a;
} H;
H var33;
#pragma pack()
struct H_alignment {
#ifdef MSVC
    char a[_Alignof(H)];
    char b;
#else
    char a;
    H b;
#endif
};
struct H_alignment var34;
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
struct H_required_alignment var35;
struct H_size {
    char a[sizeof(H)+1];
    char b;
};
struct H_size var36;

#pragma pack(8)
typedef union {
    A a;
} I;
I var37;
#pragma pack()
struct I_alignment {
#ifdef MSVC
    char a[_Alignof(I)];
    char b;
#else
    char a;
    I b;
#endif
};
struct I_alignment var38;
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
struct I_required_alignment var39;
struct I_size {
    char a[sizeof(I)+1];
    char b;
};
struct I_size var40;

#pragma pack(16)
typedef union {
    A a;
} J;
J var41;
#pragma pack()
struct J_alignment {
#ifdef MSVC
    char a[_Alignof(J)];
    char b;
#else
    char a;
    J b;
#endif
};
struct J_alignment var42;
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
struct J_required_alignment var43;
struct J_size {
    char a[sizeof(J)+1];
    char b;
};
struct J_size var44;

#pragma pack(32)
typedef union {
    A a;
} K;
K var45;
#pragma pack()
struct K_alignment {
#ifdef MSVC
    char a[_Alignof(K)];
    char b;
#else
    char a;
    K b;
#endif
};
struct K_alignment var46;
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
struct K_required_alignment var47;
struct K_size {
    char a[sizeof(K)+1];
    char b;
};
struct K_size var48;

#if defined(AARCH64_APPLE_MACOSX) ||  defined(AARCH64_FUCHSIA) ||  defined(AARCH64_LINUX_ANDROID) ||  defined(AARCH64_UNKNOWN_FREEBSD) ||  \
 defined(AARCH64_UNKNOWN_HERMIT) ||  defined(AARCH64_UNKNOWN_LINUX_GNU) ||  defined(AARCH64_UNKNOWN_LINUX_MUSL) ||  defined(AARCH64_UNKNOWN_NETBSD) ||  \
 defined(AARCH64_UNKNOWN_NONE) ||  defined(AARCH64_UNKNOWN_OPENBSD) ||  defined(AARCH64_UNKNOWN_REDOX) ||  defined(ARM64_APPLE_IOS) ||  \
 defined(ARM64_APPLE_IOS_MACABI) ||  defined(ARM64_APPLE_TVOS) ||  defined(ARMEBV7R_UNKNOWN_NONE_EABI) ||  defined(ARMEBV7R_UNKNOWN_NONE_EABIHF) ||  \
 defined(ARM_LINUX_ANDROIDEABI) ||  defined(ARM_UNKNOWN_LINUX_GNUEABI) ||  defined(ARM_UNKNOWN_LINUX_GNUEABIHF) ||  defined(ARMV4T_UNKNOWN_LINUX_GNUEABI) ||  \
 defined(ARMV5TE_UNKNOWN_LINUX_GNUEABI) ||  defined(ARMV5TE_UNKNOWN_LINUX_UCLIBCGNUEABI) ||  defined(ARMV6_UNKNOWN_FREEBSD_GNUEABIHF) ||  \
 defined(ARMV6_UNKNOWN_NETBSDELF_EABIHF) ||  defined(ARMV7A_NONE_EABI) ||  defined(ARMV7A_NONE_EABIHF) ||  defined(ARMV7_APPLE_IOS) ||  \
 defined(ARMV7_NONE_LINUX_ANDROID) ||  defined(ARMV7R_UNKNOWN_NONE_EABI) ||  defined(ARMV7R_UNKNOWN_NONE_EABIHF) ||  defined(ARMV7S_APPLE_IOS) ||  \
 defined(ARMV7_UNKNOWN_FREEBSD_GNUEABIHF) ||  defined(ARMV7_UNKNOWN_LINUX_GNUEABI) ||  defined(ARMV7_UNKNOWN_LINUX_GNUEABIHF) ||  \
 defined(ARMV7_UNKNOWN_NETBSDELF_EABIHF) ||  defined(HEXAGON_UNKNOWN_LINUX_MUSL) ||  defined(I386_APPLE_IOS) ||  defined(I586_UNKNOWN_LINUX_GNU) ||  \
 defined(I586_UNKNOWN_LINUX_MUSL) ||  defined(I686_APPLE_MACOSX) ||  defined(I686_LINUX_ANDROID) ||  defined(I686_PC_WINDOWS_GNU) ||  \
 defined(I686_UNKNOWN_FREEBSD) ||  defined(I686_UNKNOWN_HAIKU) ||  defined(I686_UNKNOWN_LINUX_GNU) ||  defined(I686_UNKNOWN_LINUX_MUSL) ||  \
 defined(I686_UNKNOWN_NETBSDELF) ||  defined(I686_UNKNOWN_OPENBSD) ||  defined(MIPS64EL_UNKNOWN_LINUX_GNUABI64) ||  defined(MIPS64EL_UNKNOWN_LINUX_MUSL) ||  \
 defined(MIPS64_UNKNOWN_LINUX_GNUABI64) ||  defined(MIPS64_UNKNOWN_LINUX_MUSL) ||  defined(MIPSEL_SONY_PSP) ||  defined(MIPSEL_UNKNOWN_LINUX_GNU) ||  \
 defined(MIPSEL_UNKNOWN_LINUX_MUSL) ||  defined(MIPSEL_UNKNOWN_LINUX_UCLIBC) ||  defined(MIPSEL_UNKNOWN_NONE) ||  defined(MIPSISA32R6EL_UNKNOWN_LINUX_GNU) ||  \
 defined(MIPSISA32R6_UNKNOWN_LINUX_GNU) ||  defined(MIPSISA64R6EL_UNKNOWN_LINUX_GNUABI64) ||  defined(MIPSISA64R6_UNKNOWN_LINUX_GNUABI64) ||  \
 defined(MIPS_UNKNOWN_LINUX_GNU) ||  defined(MIPS_UNKNOWN_LINUX_MUSL) ||  defined(MIPS_UNKNOWN_LINUX_UCLIBC) ||  defined(POWERPC64LE_UNKNOWN_LINUX_GNU) ||  \
 defined(POWERPC64LE_UNKNOWN_LINUX_MUSL) ||  defined(POWERPC64_UNKNOWN_FREEBSD) ||  defined(POWERPC64_UNKNOWN_LINUX_GNU) ||  defined(POWERPC64_UNKNOWN_LINUX_MUSL) ||  \
 defined(POWERPC_UNKNOWN_LINUX_GNU) ||  defined(POWERPC_UNKNOWN_LINUX_GNUSPE) ||  defined(POWERPC_UNKNOWN_LINUX_MUSL) ||  defined(POWERPC_UNKNOWN_NETBSD) ||  \
 defined(RISCV32) ||  defined(RISCV32_UNKNOWN_LINUX_GNU) ||  defined(RISCV64) ||  defined(RISCV64_UNKNOWN_LINUX_GNU) ||  defined(S390X_UNKNOWN_LINUX_GNU) ||  \
 defined(SPARC64_UNKNOWN_LINUX_GNU) ||  defined(SPARC64_UNKNOWN_NETBSD) ||  defined(SPARC64_UNKNOWN_OPENBSD) ||  defined(SPARC_UNKNOWN_LINUX_GNU) ||  \
 defined(SPARCV9_SUN_SOLARIS) ||  defined(THUMBV4T_NONE_EABI) ||  defined(THUMBV6M_NONE_EABI) ||  defined(THUMBV7EM_NONE_EABIHF) ||  \
 defined(THUMBV7EM_NONE_EABI) ||  defined(THUMBV7M_NONE_EABI) ||  defined(THUMBV8MBASE_NONE_EABI) ||  defined(THUMBV8MMAIN_NONE_EABIHF) ||  \
 defined(THUMBV8MMAIN_NONE_EABI) ||  defined(WASM32_UNKNOWN_EMSCRIPTEN) ||  defined(WASM32_UNKNOWN_UNKNOWN) ||  defined(WASM32_WASI) ||  \
 defined(X8664_APPLE_IOS_MACABI) ||  defined(X8664_APPLE_IOS) ||  defined(X8664_APPLE_MACOSX) ||  defined(X8664_APPLE_TVOS) ||  defined(X8664_ELF) ||  \
 defined(X8664_FUCHSIA) ||  defined(X8664_LINUX_ANDROID) ||  defined(X8664_PC_SOLARIS) ||  defined(X8664_PC_WINDOWS_GNU) ||  defined(X8664_RUMPRUN_NETBSD) ||  \
 defined(X8664_UNKNOWN_DRAGONFLY) ||  defined(X8664_UNKNOWN_FREEBSD) ||  defined(X8664_UNKNOWN_HAIKU) ||  defined(X8664_UNKNOWN_HERMIT) ||  \
 defined(X8664_UNKNOWN_L4RE_UCLIBC) ||  defined(X8664_UNKNOWN_LINUX_GNUX32) ||  defined(X8664_UNKNOWN_LINUX_GNU) ||  defined(X8664_UNKNOWN_LINUX_MUSL) ||  \
 defined(X8664_UNKNOWN_NETBSD) ||  defined(X8664_UNKNOWN_OPENBSD) ||  defined(X8664_UNKNOWN_REDOX) 
_Static_assert(sizeof(A) == 128, "record A wrong sizeof");
_Static_assert(_Alignof(A) == 128, "record A wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 256, "record A_alignment wrong sizeof");
_Static_assert(_Alignof(struct A_alignment) == 128, "record A_alignment wrong alignment");
_Static_assert(sizeof(struct A_packed) == 128, "record A_packed wrong sizeof");
_Static_assert(_Alignof(struct A_packed) == 1, "record A_packed wrong alignment");
_Static_assert(sizeof(struct A_required_alignment) == 129, "record A_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "record A_required_alignment wrong alignment");
_Static_assert(sizeof(struct A_size) == 130, "record A_size wrong sizeof");
_Static_assert(_Alignof(struct A_size) == 1, "record A_size wrong alignment");
#endif
_Static_assert(sizeof(A_) == 256, "record A_ wrong sizeof");
_Static_assert(_Alignof(A_) == 128, "record A_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A__alignment) == 384, "record A__alignment wrong sizeof");
_Static_assert(_Alignof(struct A__alignment) == 128, "record A__alignment wrong alignment");
_Static_assert(sizeof(struct A__packed) == 256, "record A__packed wrong sizeof");
_Static_assert(_Alignof(struct A__packed) == 1, "record A__packed wrong alignment");
_Static_assert(sizeof(struct A__required_alignment) == 257, "record A__required_alignment wrong sizeof");
_Static_assert(_Alignof(struct A__required_alignment) == 1, "record A__required_alignment wrong alignment");
_Static_assert(sizeof(struct A__size) == 258, "record A__size wrong sizeof");
_Static_assert(_Alignof(struct A__size) == 1, "record A__size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_,a) == 1024, "field A_.a wrong bit offset");
#endif
_Static_assert(sizeof(B) == 128, "record B wrong sizeof");
_Static_assert(_Alignof(B) == 128, "record B wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 256, "record B_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_alignment) == 128, "record B_alignment wrong alignment");
_Static_assert(sizeof(struct B_packed) == 128, "record B_packed wrong sizeof");
_Static_assert(_Alignof(struct B_packed) == 1, "record B_packed wrong alignment");
_Static_assert(sizeof(struct B_required_alignment) == 129, "record B_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "record B_required_alignment wrong alignment");
_Static_assert(sizeof(struct B_size) == 130, "record B_size wrong sizeof");
_Static_assert(_Alignof(struct B_size) == 1, "record B_size wrong alignment");
#endif
_Static_assert(sizeof(C) == 128, "record C wrong sizeof");
_Static_assert(_Alignof(C) == 4, "record C wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 132, "record C_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_alignment) == 4, "record C_alignment wrong alignment");
_Static_assert(sizeof(struct C_packed) == 128, "record C_packed wrong sizeof");
_Static_assert(_Alignof(struct C_packed) == 1, "record C_packed wrong alignment");
_Static_assert(sizeof(struct C_required_alignment) == 129, "record C_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "record C_required_alignment wrong alignment");
_Static_assert(sizeof(struct C_size) == 130, "record C_size wrong sizeof");
_Static_assert(_Alignof(struct C_size) == 1, "record C_size wrong alignment");
#endif
_Static_assert(sizeof(D) == 128, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 8, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 136, "record D_alignment wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 8, "record D_alignment wrong alignment");
_Static_assert(sizeof(struct D_packed) == 128, "record D_packed wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D_packed wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 129, "record D_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D_required_alignment wrong alignment");
_Static_assert(sizeof(struct D_size) == 130, "record D_size wrong sizeof");
_Static_assert(_Alignof(struct D_size) == 1, "record D_size wrong alignment");
#endif
_Static_assert(sizeof(E) == 128, "record E wrong sizeof");
_Static_assert(_Alignof(E) == 16, "record E wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 144, "record E_alignment wrong sizeof");
_Static_assert(_Alignof(struct E_alignment) == 16, "record E_alignment wrong alignment");
_Static_assert(sizeof(struct E_packed) == 128, "record E_packed wrong sizeof");
_Static_assert(_Alignof(struct E_packed) == 1, "record E_packed wrong alignment");
_Static_assert(sizeof(struct E_required_alignment) == 129, "record E_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "record E_required_alignment wrong alignment");
_Static_assert(sizeof(struct E_size) == 130, "record E_size wrong sizeof");
_Static_assert(_Alignof(struct E_size) == 1, "record E_size wrong alignment");
#endif
_Static_assert(sizeof(F) == 128, "record F wrong sizeof");
_Static_assert(_Alignof(F) == 128, "record F wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 256, "record F_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_alignment) == 128, "record F_alignment wrong alignment");
_Static_assert(sizeof(struct F_packed) == 128, "record F_packed wrong sizeof");
_Static_assert(_Alignof(struct F_packed) == 1, "record F_packed wrong alignment");
_Static_assert(sizeof(struct F_required_alignment) == 129, "record F_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "record F_required_alignment wrong alignment");
_Static_assert(sizeof(struct F_size) == 130, "record F_size wrong sizeof");
_Static_assert(_Alignof(struct F_size) == 1, "record F_size wrong alignment");
#endif
_Static_assert(sizeof(G) == 128, "record G wrong sizeof");
_Static_assert(_Alignof(G) == 128, "record G wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 256, "record G_alignment wrong sizeof");
_Static_assert(_Alignof(struct G_alignment) == 128, "record G_alignment wrong alignment");
_Static_assert(sizeof(struct G_packed) == 128, "record G_packed wrong sizeof");
_Static_assert(_Alignof(struct G_packed) == 1, "record G_packed wrong alignment");
_Static_assert(sizeof(struct G_required_alignment) == 129, "record G_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "record G_required_alignment wrong alignment");
_Static_assert(sizeof(struct G_size) == 130, "record G_size wrong sizeof");
_Static_assert(_Alignof(struct G_size) == 1, "record G_size wrong alignment");
#endif
_Static_assert(sizeof(H) == 128, "record H wrong sizeof");
_Static_assert(_Alignof(H) == 4, "record H wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 132, "record H_alignment wrong sizeof");
_Static_assert(_Alignof(struct H_alignment) == 4, "record H_alignment wrong alignment");
_Static_assert(sizeof(struct H_packed) == 128, "record H_packed wrong sizeof");
_Static_assert(_Alignof(struct H_packed) == 1, "record H_packed wrong alignment");
_Static_assert(sizeof(struct H_required_alignment) == 129, "record H_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "record H_required_alignment wrong alignment");
_Static_assert(sizeof(struct H_size) == 130, "record H_size wrong sizeof");
_Static_assert(_Alignof(struct H_size) == 1, "record H_size wrong alignment");
#endif
_Static_assert(sizeof(I) == 128, "record I wrong sizeof");
_Static_assert(_Alignof(I) == 8, "record I wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I_alignment) == 136, "record I_alignment wrong sizeof");
_Static_assert(_Alignof(struct I_alignment) == 8, "record I_alignment wrong alignment");
_Static_assert(sizeof(struct I_packed) == 128, "record I_packed wrong sizeof");
_Static_assert(_Alignof(struct I_packed) == 1, "record I_packed wrong alignment");
_Static_assert(sizeof(struct I_required_alignment) == 129, "record I_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct I_required_alignment) == 1, "record I_required_alignment wrong alignment");
_Static_assert(sizeof(struct I_size) == 130, "record I_size wrong sizeof");
_Static_assert(_Alignof(struct I_size) == 1, "record I_size wrong alignment");
#endif
_Static_assert(sizeof(J) == 128, "record J wrong sizeof");
_Static_assert(_Alignof(J) == 16, "record J wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J_alignment) == 144, "record J_alignment wrong sizeof");
_Static_assert(_Alignof(struct J_alignment) == 16, "record J_alignment wrong alignment");
_Static_assert(sizeof(struct J_packed) == 128, "record J_packed wrong sizeof");
_Static_assert(_Alignof(struct J_packed) == 1, "record J_packed wrong alignment");
_Static_assert(sizeof(struct J_required_alignment) == 129, "record J_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct J_required_alignment) == 1, "record J_required_alignment wrong alignment");
_Static_assert(sizeof(struct J_size) == 130, "record J_size wrong sizeof");
_Static_assert(_Alignof(struct J_size) == 1, "record J_size wrong alignment");
#endif
_Static_assert(sizeof(K) == 128, "record K wrong sizeof");
_Static_assert(_Alignof(K) == 128, "record K wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct K_alignment) == 256, "record K_alignment wrong sizeof");
_Static_assert(_Alignof(struct K_alignment) == 128, "record K_alignment wrong alignment");
_Static_assert(sizeof(struct K_packed) == 128, "record K_packed wrong sizeof");
_Static_assert(_Alignof(struct K_packed) == 1, "record K_packed wrong alignment");
_Static_assert(sizeof(struct K_required_alignment) == 129, "record K_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct K_required_alignment) == 1, "record K_required_alignment wrong alignment");
_Static_assert(sizeof(struct K_size) == 130, "record K_size wrong sizeof");
_Static_assert(_Alignof(struct K_size) == 1, "record K_size wrong alignment");
#endif
#elif defined(AARCH64_PC_WINDOWS_MSVC) 
_Static_assert(sizeof(A) == 8, "record A wrong sizeof");
_Static_assert(_Alignof(A) == 128, "record A wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 256, "record A_alignment wrong sizeof");
_Static_assert(_Alignof(struct A_alignment) == 128, "record A_alignment wrong alignment");
_Static_assert(sizeof(struct A_packed) == 8, "record A_packed wrong sizeof");
_Static_assert(_Alignof(struct A_packed) == 1, "record A_packed wrong alignment");
_Static_assert(sizeof(struct A_required_alignment) == 9, "record A_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "record A_required_alignment wrong alignment");
_Static_assert(sizeof(struct A_size) == 10, "record A_size wrong sizeof");
_Static_assert(_Alignof(struct A_size) == 1, "record A_size wrong alignment");
#endif
_Static_assert(sizeof(A_) == 16, "record A_ wrong sizeof");
_Static_assert(_Alignof(A_) == 8, "record A_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A__alignment) == 24, "record A__alignment wrong sizeof");
_Static_assert(_Alignof(struct A__alignment) == 8, "record A__alignment wrong alignment");
_Static_assert(sizeof(struct A__packed) == 16, "record A__packed wrong sizeof");
_Static_assert(_Alignof(struct A__packed) == 1, "record A__packed wrong alignment");
_Static_assert(sizeof(struct A__required_alignment) == 17, "record A__required_alignment wrong sizeof");
_Static_assert(_Alignof(struct A__required_alignment) == 1, "record A__required_alignment wrong alignment");
_Static_assert(sizeof(struct A__size) == 18, "record A__size wrong sizeof");
_Static_assert(_Alignof(struct A__size) == 1, "record A__size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_,a) == 64, "field A_.a wrong bit offset");
#endif
_Static_assert(sizeof(B) == 8, "record B wrong sizeof");
_Static_assert(_Alignof(B) == 8, "record B wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 16, "record B_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_alignment) == 8, "record B_alignment wrong alignment");
_Static_assert(sizeof(struct B_packed) == 8, "record B_packed wrong sizeof");
_Static_assert(_Alignof(struct B_packed) == 1, "record B_packed wrong alignment");
_Static_assert(sizeof(struct B_required_alignment) == 9, "record B_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "record B_required_alignment wrong alignment");
_Static_assert(sizeof(struct B_size) == 10, "record B_size wrong sizeof");
_Static_assert(_Alignof(struct B_size) == 1, "record B_size wrong alignment");
#endif
_Static_assert(sizeof(C) == 8, "record C wrong sizeof");
_Static_assert(_Alignof(C) == 4, "record C wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 12, "record C_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_alignment) == 4, "record C_alignment wrong alignment");
_Static_assert(sizeof(struct C_packed) == 8, "record C_packed wrong sizeof");
_Static_assert(_Alignof(struct C_packed) == 1, "record C_packed wrong alignment");
_Static_assert(sizeof(struct C_required_alignment) == 9, "record C_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "record C_required_alignment wrong alignment");
_Static_assert(sizeof(struct C_size) == 10, "record C_size wrong sizeof");
_Static_assert(_Alignof(struct C_size) == 1, "record C_size wrong alignment");
#endif
_Static_assert(sizeof(D) == 8, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 8, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 16, "record D_alignment wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 8, "record D_alignment wrong alignment");
_Static_assert(sizeof(struct D_packed) == 8, "record D_packed wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D_packed wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 9, "record D_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D_required_alignment wrong alignment");
_Static_assert(sizeof(struct D_size) == 10, "record D_size wrong sizeof");
_Static_assert(_Alignof(struct D_size) == 1, "record D_size wrong alignment");
#endif
_Static_assert(sizeof(E) == 128, "record E wrong sizeof");
_Static_assert(_Alignof(E) == 128, "record E wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 256, "record E_alignment wrong sizeof");
_Static_assert(_Alignof(struct E_alignment) == 128, "record E_alignment wrong alignment");
_Static_assert(sizeof(struct E_packed) == 128, "record E_packed wrong sizeof");
_Static_assert(_Alignof(struct E_packed) == 1, "record E_packed wrong alignment");
_Static_assert(sizeof(struct E_required_alignment) == 129, "record E_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "record E_required_alignment wrong alignment");
_Static_assert(sizeof(struct E_size) == 130, "record E_size wrong sizeof");
_Static_assert(_Alignof(struct E_size) == 1, "record E_size wrong alignment");
#endif
_Static_assert(sizeof(F) == 8, "record F wrong sizeof");
_Static_assert(_Alignof(F) == 8, "record F wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 16, "record F_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_alignment) == 8, "record F_alignment wrong alignment");
_Static_assert(sizeof(struct F_packed) == 8, "record F_packed wrong sizeof");
_Static_assert(_Alignof(struct F_packed) == 1, "record F_packed wrong alignment");
_Static_assert(sizeof(struct F_required_alignment) == 9, "record F_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "record F_required_alignment wrong alignment");
_Static_assert(sizeof(struct F_size) == 10, "record F_size wrong sizeof");
_Static_assert(_Alignof(struct F_size) == 1, "record F_size wrong alignment");
#endif
_Static_assert(sizeof(G) == 8, "record G wrong sizeof");
_Static_assert(_Alignof(G) == 8, "record G wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 16, "record G_alignment wrong sizeof");
_Static_assert(_Alignof(struct G_alignment) == 8, "record G_alignment wrong alignment");
_Static_assert(sizeof(struct G_packed) == 8, "record G_packed wrong sizeof");
_Static_assert(_Alignof(struct G_packed) == 1, "record G_packed wrong alignment");
_Static_assert(sizeof(struct G_required_alignment) == 9, "record G_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "record G_required_alignment wrong alignment");
_Static_assert(sizeof(struct G_size) == 10, "record G_size wrong sizeof");
_Static_assert(_Alignof(struct G_size) == 1, "record G_size wrong alignment");
#endif
_Static_assert(sizeof(H) == 8, "record H wrong sizeof");
_Static_assert(_Alignof(H) == 4, "record H wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 12, "record H_alignment wrong sizeof");
_Static_assert(_Alignof(struct H_alignment) == 4, "record H_alignment wrong alignment");
_Static_assert(sizeof(struct H_packed) == 8, "record H_packed wrong sizeof");
_Static_assert(_Alignof(struct H_packed) == 1, "record H_packed wrong alignment");
_Static_assert(sizeof(struct H_required_alignment) == 9, "record H_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "record H_required_alignment wrong alignment");
_Static_assert(sizeof(struct H_size) == 10, "record H_size wrong sizeof");
_Static_assert(_Alignof(struct H_size) == 1, "record H_size wrong alignment");
#endif
_Static_assert(sizeof(I) == 8, "record I wrong sizeof");
_Static_assert(_Alignof(I) == 8, "record I wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I_alignment) == 16, "record I_alignment wrong sizeof");
_Static_assert(_Alignof(struct I_alignment) == 8, "record I_alignment wrong alignment");
_Static_assert(sizeof(struct I_packed) == 8, "record I_packed wrong sizeof");
_Static_assert(_Alignof(struct I_packed) == 1, "record I_packed wrong alignment");
_Static_assert(sizeof(struct I_required_alignment) == 9, "record I_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct I_required_alignment) == 1, "record I_required_alignment wrong alignment");
_Static_assert(sizeof(struct I_size) == 10, "record I_size wrong sizeof");
_Static_assert(_Alignof(struct I_size) == 1, "record I_size wrong alignment");
#endif
_Static_assert(sizeof(J) == 128, "record J wrong sizeof");
_Static_assert(_Alignof(J) == 128, "record J wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J_alignment) == 256, "record J_alignment wrong sizeof");
_Static_assert(_Alignof(struct J_alignment) == 128, "record J_alignment wrong alignment");
_Static_assert(sizeof(struct J_packed) == 128, "record J_packed wrong sizeof");
_Static_assert(_Alignof(struct J_packed) == 1, "record J_packed wrong alignment");
_Static_assert(sizeof(struct J_required_alignment) == 129, "record J_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct J_required_alignment) == 1, "record J_required_alignment wrong alignment");
_Static_assert(sizeof(struct J_size) == 130, "record J_size wrong sizeof");
_Static_assert(_Alignof(struct J_size) == 1, "record J_size wrong alignment");
#endif
_Static_assert(sizeof(K) == 8, "record K wrong sizeof");
_Static_assert(_Alignof(K) == 8, "record K wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct K_alignment) == 16, "record K_alignment wrong sizeof");
_Static_assert(_Alignof(struct K_alignment) == 8, "record K_alignment wrong alignment");
_Static_assert(sizeof(struct K_packed) == 8, "record K_packed wrong sizeof");
_Static_assert(_Alignof(struct K_packed) == 1, "record K_packed wrong alignment");
_Static_assert(sizeof(struct K_required_alignment) == 9, "record K_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct K_required_alignment) == 1, "record K_required_alignment wrong alignment");
_Static_assert(sizeof(struct K_size) == 10, "record K_size wrong sizeof");
_Static_assert(_Alignof(struct K_size) == 1, "record K_size wrong alignment");
#endif
#elif defined(AVR_UNKNOWN_UNKNOWN) 
_Static_assert(sizeof(A) == 128, "record A wrong sizeof");
_Static_assert(_Alignof(A) == 128, "record A wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 256, "record A_alignment wrong sizeof");
_Static_assert(_Alignof(struct A_alignment) == 128, "record A_alignment wrong alignment");
_Static_assert(sizeof(struct A_packed) == 128, "record A_packed wrong sizeof");
_Static_assert(_Alignof(struct A_packed) == 1, "record A_packed wrong alignment");
_Static_assert(sizeof(struct A_required_alignment) == 129, "record A_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "record A_required_alignment wrong alignment");
_Static_assert(sizeof(struct A_size) == 130, "record A_size wrong sizeof");
_Static_assert(_Alignof(struct A_size) == 1, "record A_size wrong alignment");
#endif
_Static_assert(sizeof(A_) == 256, "record A_ wrong sizeof");
_Static_assert(_Alignof(A_) == 128, "record A_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A__alignment) == 384, "record A__alignment wrong sizeof");
_Static_assert(_Alignof(struct A__alignment) == 128, "record A__alignment wrong alignment");
_Static_assert(sizeof(struct A__packed) == 256, "record A__packed wrong sizeof");
_Static_assert(_Alignof(struct A__packed) == 1, "record A__packed wrong alignment");
_Static_assert(sizeof(struct A__required_alignment) == 257, "record A__required_alignment wrong sizeof");
_Static_assert(_Alignof(struct A__required_alignment) == 1, "record A__required_alignment wrong alignment");
_Static_assert(sizeof(struct A__size) == 258, "record A__size wrong sizeof");
_Static_assert(_Alignof(struct A__size) == 1, "record A__size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_,a) == 1024, "field A_.a wrong bit offset");
#endif
_Static_assert(sizeof(B) == 128, "record B wrong sizeof");
_Static_assert(_Alignof(B) == 128, "record B wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 256, "record B_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_alignment) == 128, "record B_alignment wrong alignment");
_Static_assert(sizeof(struct B_packed) == 128, "record B_packed wrong sizeof");
_Static_assert(_Alignof(struct B_packed) == 1, "record B_packed wrong alignment");
_Static_assert(sizeof(struct B_required_alignment) == 129, "record B_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "record B_required_alignment wrong alignment");
_Static_assert(sizeof(struct B_size) == 130, "record B_size wrong sizeof");
_Static_assert(_Alignof(struct B_size) == 1, "record B_size wrong alignment");
#endif
_Static_assert(sizeof(C) == 128, "record C wrong sizeof");
_Static_assert(_Alignof(C) == 4, "record C wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 132, "record C_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_alignment) == 4, "record C_alignment wrong alignment");
_Static_assert(sizeof(struct C_packed) == 128, "record C_packed wrong sizeof");
_Static_assert(_Alignof(struct C_packed) == 1, "record C_packed wrong alignment");
_Static_assert(sizeof(struct C_required_alignment) == 129, "record C_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "record C_required_alignment wrong alignment");
_Static_assert(sizeof(struct C_size) == 130, "record C_size wrong sizeof");
_Static_assert(_Alignof(struct C_size) == 1, "record C_size wrong alignment");
#endif
_Static_assert(sizeof(D) == 128, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 8, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 136, "record D_alignment wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 8, "record D_alignment wrong alignment");
_Static_assert(sizeof(struct D_packed) == 128, "record D_packed wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D_packed wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 129, "record D_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D_required_alignment wrong alignment");
_Static_assert(sizeof(struct D_size) == 130, "record D_size wrong sizeof");
_Static_assert(_Alignof(struct D_size) == 1, "record D_size wrong alignment");
#endif
_Static_assert(sizeof(E) == 128, "record E wrong sizeof");
_Static_assert(_Alignof(E) == 16, "record E wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 144, "record E_alignment wrong sizeof");
_Static_assert(_Alignof(struct E_alignment) == 16, "record E_alignment wrong alignment");
_Static_assert(sizeof(struct E_packed) == 128, "record E_packed wrong sizeof");
_Static_assert(_Alignof(struct E_packed) == 1, "record E_packed wrong alignment");
_Static_assert(sizeof(struct E_required_alignment) == 129, "record E_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "record E_required_alignment wrong alignment");
_Static_assert(sizeof(struct E_size) == 130, "record E_size wrong sizeof");
_Static_assert(_Alignof(struct E_size) == 1, "record E_size wrong alignment");
#endif
_Static_assert(sizeof(F) == 128, "record F wrong sizeof");
_Static_assert(_Alignof(F) == 128, "record F wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 256, "record F_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_alignment) == 128, "record F_alignment wrong alignment");
_Static_assert(sizeof(struct F_packed) == 128, "record F_packed wrong sizeof");
_Static_assert(_Alignof(struct F_packed) == 1, "record F_packed wrong alignment");
_Static_assert(sizeof(struct F_required_alignment) == 129, "record F_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "record F_required_alignment wrong alignment");
_Static_assert(sizeof(struct F_size) == 130, "record F_size wrong sizeof");
_Static_assert(_Alignof(struct F_size) == 1, "record F_size wrong alignment");
#endif
_Static_assert(sizeof(G) == 128, "record G wrong sizeof");
_Static_assert(_Alignof(G) == 128, "record G wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 256, "record G_alignment wrong sizeof");
_Static_assert(_Alignof(struct G_alignment) == 128, "record G_alignment wrong alignment");
_Static_assert(sizeof(struct G_packed) == 128, "record G_packed wrong sizeof");
_Static_assert(_Alignof(struct G_packed) == 1, "record G_packed wrong alignment");
_Static_assert(sizeof(struct G_required_alignment) == 129, "record G_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "record G_required_alignment wrong alignment");
_Static_assert(sizeof(struct G_size) == 130, "record G_size wrong sizeof");
_Static_assert(_Alignof(struct G_size) == 1, "record G_size wrong alignment");
#endif
_Static_assert(sizeof(H) == 128, "record H wrong sizeof");
_Static_assert(_Alignof(H) == 4, "record H wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 132, "record H_alignment wrong sizeof");
_Static_assert(_Alignof(struct H_alignment) == 4, "record H_alignment wrong alignment");
_Static_assert(sizeof(struct H_packed) == 128, "record H_packed wrong sizeof");
_Static_assert(_Alignof(struct H_packed) == 1, "record H_packed wrong alignment");
_Static_assert(sizeof(struct H_required_alignment) == 129, "record H_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "record H_required_alignment wrong alignment");
_Static_assert(sizeof(struct H_size) == 130, "record H_size wrong sizeof");
_Static_assert(_Alignof(struct H_size) == 1, "record H_size wrong alignment");
#endif
_Static_assert(sizeof(I) == 128, "record I wrong sizeof");
_Static_assert(_Alignof(I) == 8, "record I wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I_alignment) == 136, "record I_alignment wrong sizeof");
_Static_assert(_Alignof(struct I_alignment) == 8, "record I_alignment wrong alignment");
_Static_assert(sizeof(struct I_packed) == 128, "record I_packed wrong sizeof");
_Static_assert(_Alignof(struct I_packed) == 1, "record I_packed wrong alignment");
_Static_assert(sizeof(struct I_required_alignment) == 129, "record I_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct I_required_alignment) == 1, "record I_required_alignment wrong alignment");
_Static_assert(sizeof(struct I_size) == 130, "record I_size wrong sizeof");
_Static_assert(_Alignof(struct I_size) == 1, "record I_size wrong alignment");
#endif
_Static_assert(sizeof(J) == 128, "record J wrong sizeof");
_Static_assert(_Alignof(J) == 16, "record J wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J_alignment) == 144, "record J_alignment wrong sizeof");
_Static_assert(_Alignof(struct J_alignment) == 16, "record J_alignment wrong alignment");
_Static_assert(sizeof(struct J_packed) == 128, "record J_packed wrong sizeof");
_Static_assert(_Alignof(struct J_packed) == 1, "record J_packed wrong alignment");
_Static_assert(sizeof(struct J_required_alignment) == 129, "record J_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct J_required_alignment) == 1, "record J_required_alignment wrong alignment");
_Static_assert(sizeof(struct J_size) == 130, "record J_size wrong sizeof");
_Static_assert(_Alignof(struct J_size) == 1, "record J_size wrong alignment");
#endif
_Static_assert(sizeof(K) == 128, "record K wrong sizeof");
_Static_assert(_Alignof(K) == 128, "record K wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct K_alignment) == 256, "record K_alignment wrong sizeof");
_Static_assert(_Alignof(struct K_alignment) == 128, "record K_alignment wrong alignment");
_Static_assert(sizeof(struct K_packed) == 128, "record K_packed wrong sizeof");
_Static_assert(_Alignof(struct K_packed) == 1, "record K_packed wrong alignment");
_Static_assert(sizeof(struct K_required_alignment) == 129, "record K_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct K_required_alignment) == 1, "record K_required_alignment wrong alignment");
_Static_assert(sizeof(struct K_size) == 130, "record K_size wrong sizeof");
_Static_assert(_Alignof(struct K_size) == 1, "record K_size wrong alignment");
#endif
#elif defined(I586_PC_WINDOWS_MSVC) ||  defined(I686_PC_WINDOWS_MSVC) ||  defined(I686_UNKNOWN_WINDOWS) 
_Static_assert(sizeof(A) == 128, "record A wrong sizeof");
_Static_assert(_Alignof(A) == 128, "record A wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 256, "record A_alignment wrong sizeof");
_Static_assert(_Alignof(struct A_alignment) == 128, "record A_alignment wrong alignment");
_Static_assert(sizeof(struct A_packed) == 128, "record A_packed wrong sizeof");
_Static_assert(_Alignof(struct A_packed) == 1, "record A_packed wrong alignment");
_Static_assert(sizeof(struct A_required_alignment) == 129, "record A_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "record A_required_alignment wrong alignment");
_Static_assert(sizeof(struct A_size) == 130, "record A_size wrong sizeof");
_Static_assert(_Alignof(struct A_size) == 1, "record A_size wrong alignment");
#endif
_Static_assert(sizeof(A_) == 256, "record A_ wrong sizeof");
_Static_assert(_Alignof(A_) == 128, "record A_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A__alignment) == 384, "record A__alignment wrong sizeof");
_Static_assert(_Alignof(struct A__alignment) == 128, "record A__alignment wrong alignment");
_Static_assert(sizeof(struct A__packed) == 256, "record A__packed wrong sizeof");
_Static_assert(_Alignof(struct A__packed) == 1, "record A__packed wrong alignment");
_Static_assert(sizeof(struct A__required_alignment) == 257, "record A__required_alignment wrong sizeof");
_Static_assert(_Alignof(struct A__required_alignment) == 1, "record A__required_alignment wrong alignment");
_Static_assert(sizeof(struct A__size) == 258, "record A__size wrong sizeof");
_Static_assert(_Alignof(struct A__size) == 1, "record A__size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_,a) == 1024, "field A_.a wrong bit offset");
#endif
_Static_assert(sizeof(B) == 128, "record B wrong sizeof");
_Static_assert(_Alignof(B) == 128, "record B wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 256, "record B_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_alignment) == 128, "record B_alignment wrong alignment");
_Static_assert(sizeof(struct B_packed) == 128, "record B_packed wrong sizeof");
_Static_assert(_Alignof(struct B_packed) == 1, "record B_packed wrong alignment");
_Static_assert(sizeof(struct B_required_alignment) == 129, "record B_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "record B_required_alignment wrong alignment");
_Static_assert(sizeof(struct B_size) == 130, "record B_size wrong sizeof");
_Static_assert(_Alignof(struct B_size) == 1, "record B_size wrong alignment");
#endif
_Static_assert(sizeof(C) == 128, "record C wrong sizeof");
_Static_assert(_Alignof(C) == 4, "record C wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 132, "record C_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_alignment) == 4, "record C_alignment wrong alignment");
_Static_assert(sizeof(struct C_packed) == 128, "record C_packed wrong sizeof");
_Static_assert(_Alignof(struct C_packed) == 1, "record C_packed wrong alignment");
_Static_assert(sizeof(struct C_required_alignment) == 129, "record C_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "record C_required_alignment wrong alignment");
_Static_assert(sizeof(struct C_size) == 130, "record C_size wrong sizeof");
_Static_assert(_Alignof(struct C_size) == 1, "record C_size wrong alignment");
#endif
_Static_assert(sizeof(D) == 128, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 128, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 256, "record D_alignment wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 128, "record D_alignment wrong alignment");
_Static_assert(sizeof(struct D_packed) == 128, "record D_packed wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D_packed wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 129, "record D_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D_required_alignment wrong alignment");
_Static_assert(sizeof(struct D_size) == 130, "record D_size wrong sizeof");
_Static_assert(_Alignof(struct D_size) == 1, "record D_size wrong alignment");
#endif
_Static_assert(sizeof(E) == 128, "record E wrong sizeof");
_Static_assert(_Alignof(E) == 128, "record E wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 256, "record E_alignment wrong sizeof");
_Static_assert(_Alignof(struct E_alignment) == 128, "record E_alignment wrong alignment");
_Static_assert(sizeof(struct E_packed) == 128, "record E_packed wrong sizeof");
_Static_assert(_Alignof(struct E_packed) == 1, "record E_packed wrong alignment");
_Static_assert(sizeof(struct E_required_alignment) == 129, "record E_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "record E_required_alignment wrong alignment");
_Static_assert(sizeof(struct E_size) == 130, "record E_size wrong sizeof");
_Static_assert(_Alignof(struct E_size) == 1, "record E_size wrong alignment");
#endif
_Static_assert(sizeof(F) == 128, "record F wrong sizeof");
_Static_assert(_Alignof(F) == 128, "record F wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 256, "record F_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_alignment) == 128, "record F_alignment wrong alignment");
_Static_assert(sizeof(struct F_packed) == 128, "record F_packed wrong sizeof");
_Static_assert(_Alignof(struct F_packed) == 1, "record F_packed wrong alignment");
_Static_assert(sizeof(struct F_required_alignment) == 129, "record F_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "record F_required_alignment wrong alignment");
_Static_assert(sizeof(struct F_size) == 130, "record F_size wrong sizeof");
_Static_assert(_Alignof(struct F_size) == 1, "record F_size wrong alignment");
#endif
_Static_assert(sizeof(G) == 128, "record G wrong sizeof");
_Static_assert(_Alignof(G) == 128, "record G wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 256, "record G_alignment wrong sizeof");
_Static_assert(_Alignof(struct G_alignment) == 128, "record G_alignment wrong alignment");
_Static_assert(sizeof(struct G_packed) == 128, "record G_packed wrong sizeof");
_Static_assert(_Alignof(struct G_packed) == 1, "record G_packed wrong alignment");
_Static_assert(sizeof(struct G_required_alignment) == 129, "record G_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "record G_required_alignment wrong alignment");
_Static_assert(sizeof(struct G_size) == 130, "record G_size wrong sizeof");
_Static_assert(_Alignof(struct G_size) == 1, "record G_size wrong alignment");
#endif
_Static_assert(sizeof(H) == 128, "record H wrong sizeof");
_Static_assert(_Alignof(H) == 4, "record H wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 132, "record H_alignment wrong sizeof");
_Static_assert(_Alignof(struct H_alignment) == 4, "record H_alignment wrong alignment");
_Static_assert(sizeof(struct H_packed) == 128, "record H_packed wrong sizeof");
_Static_assert(_Alignof(struct H_packed) == 1, "record H_packed wrong alignment");
_Static_assert(sizeof(struct H_required_alignment) == 129, "record H_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "record H_required_alignment wrong alignment");
_Static_assert(sizeof(struct H_size) == 130, "record H_size wrong sizeof");
_Static_assert(_Alignof(struct H_size) == 1, "record H_size wrong alignment");
#endif
_Static_assert(sizeof(I) == 128, "record I wrong sizeof");
_Static_assert(_Alignof(I) == 128, "record I wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I_alignment) == 256, "record I_alignment wrong sizeof");
_Static_assert(_Alignof(struct I_alignment) == 128, "record I_alignment wrong alignment");
_Static_assert(sizeof(struct I_packed) == 128, "record I_packed wrong sizeof");
_Static_assert(_Alignof(struct I_packed) == 1, "record I_packed wrong alignment");
_Static_assert(sizeof(struct I_required_alignment) == 129, "record I_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct I_required_alignment) == 1, "record I_required_alignment wrong alignment");
_Static_assert(sizeof(struct I_size) == 130, "record I_size wrong sizeof");
_Static_assert(_Alignof(struct I_size) == 1, "record I_size wrong alignment");
#endif
_Static_assert(sizeof(J) == 128, "record J wrong sizeof");
_Static_assert(_Alignof(J) == 128, "record J wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J_alignment) == 256, "record J_alignment wrong sizeof");
_Static_assert(_Alignof(struct J_alignment) == 128, "record J_alignment wrong alignment");
_Static_assert(sizeof(struct J_packed) == 128, "record J_packed wrong sizeof");
_Static_assert(_Alignof(struct J_packed) == 1, "record J_packed wrong alignment");
_Static_assert(sizeof(struct J_required_alignment) == 129, "record J_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct J_required_alignment) == 1, "record J_required_alignment wrong alignment");
_Static_assert(sizeof(struct J_size) == 130, "record J_size wrong sizeof");
_Static_assert(_Alignof(struct J_size) == 1, "record J_size wrong alignment");
#endif
_Static_assert(sizeof(K) == 128, "record K wrong sizeof");
_Static_assert(_Alignof(K) == 128, "record K wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct K_alignment) == 256, "record K_alignment wrong sizeof");
_Static_assert(_Alignof(struct K_alignment) == 128, "record K_alignment wrong alignment");
_Static_assert(sizeof(struct K_packed) == 128, "record K_packed wrong sizeof");
_Static_assert(_Alignof(struct K_packed) == 1, "record K_packed wrong alignment");
_Static_assert(sizeof(struct K_required_alignment) == 129, "record K_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct K_required_alignment) == 1, "record K_required_alignment wrong alignment");
_Static_assert(sizeof(struct K_size) == 130, "record K_size wrong sizeof");
_Static_assert(_Alignof(struct K_size) == 1, "record K_size wrong alignment");
#endif
#elif defined(MSP430_NONE_ELF) 
_Static_assert(sizeof(A) == 128, "record A wrong sizeof");
_Static_assert(_Alignof(A) == 128, "record A wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 256, "record A_alignment wrong sizeof");
_Static_assert(_Alignof(struct A_alignment) == 128, "record A_alignment wrong alignment");
_Static_assert(sizeof(struct A_packed) == 128, "record A_packed wrong sizeof");
_Static_assert(_Alignof(struct A_packed) == 1, "record A_packed wrong alignment");
_Static_assert(sizeof(struct A_required_alignment) == 129, "record A_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "record A_required_alignment wrong alignment");
_Static_assert(sizeof(struct A_size) == 130, "record A_size wrong sizeof");
_Static_assert(_Alignof(struct A_size) == 1, "record A_size wrong alignment");
#endif
_Static_assert(sizeof(A_) == 256, "record A_ wrong sizeof");
_Static_assert(_Alignof(A_) == 128, "record A_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A__alignment) == 384, "record A__alignment wrong sizeof");
_Static_assert(_Alignof(struct A__alignment) == 128, "record A__alignment wrong alignment");
_Static_assert(sizeof(struct A__packed) == 256, "record A__packed wrong sizeof");
_Static_assert(_Alignof(struct A__packed) == 1, "record A__packed wrong alignment");
_Static_assert(sizeof(struct A__required_alignment) == 257, "record A__required_alignment wrong sizeof");
_Static_assert(_Alignof(struct A__required_alignment) == 1, "record A__required_alignment wrong alignment");
_Static_assert(sizeof(struct A__size) == 258, "record A__size wrong sizeof");
_Static_assert(_Alignof(struct A__size) == 1, "record A__size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_,a) == 1024, "field A_.a wrong bit offset");
#endif
_Static_assert(sizeof(B) == 128, "record B wrong sizeof");
_Static_assert(_Alignof(B) == 128, "record B wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 256, "record B_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_alignment) == 128, "record B_alignment wrong alignment");
_Static_assert(sizeof(struct B_packed) == 128, "record B_packed wrong sizeof");
_Static_assert(_Alignof(struct B_packed) == 1, "record B_packed wrong alignment");
_Static_assert(sizeof(struct B_required_alignment) == 129, "record B_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "record B_required_alignment wrong alignment");
_Static_assert(sizeof(struct B_size) == 130, "record B_size wrong sizeof");
_Static_assert(_Alignof(struct B_size) == 1, "record B_size wrong alignment");
#endif
_Static_assert(sizeof(C) == 128, "record C wrong sizeof");
_Static_assert(_Alignof(C) == 4, "record C wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 132, "record C_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_alignment) == 4, "record C_alignment wrong alignment");
_Static_assert(sizeof(struct C_packed) == 128, "record C_packed wrong sizeof");
_Static_assert(_Alignof(struct C_packed) == 1, "record C_packed wrong alignment");
_Static_assert(sizeof(struct C_required_alignment) == 129, "record C_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "record C_required_alignment wrong alignment");
_Static_assert(sizeof(struct C_size) == 130, "record C_size wrong sizeof");
_Static_assert(_Alignof(struct C_size) == 1, "record C_size wrong alignment");
#endif
_Static_assert(sizeof(D) == 128, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 8, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 136, "record D_alignment wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 8, "record D_alignment wrong alignment");
_Static_assert(sizeof(struct D_packed) == 128, "record D_packed wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D_packed wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 129, "record D_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D_required_alignment wrong alignment");
_Static_assert(sizeof(struct D_size) == 130, "record D_size wrong sizeof");
_Static_assert(_Alignof(struct D_size) == 1, "record D_size wrong alignment");
#endif
_Static_assert(sizeof(E) == 128, "record E wrong sizeof");
_Static_assert(_Alignof(E) == 16, "record E wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 144, "record E_alignment wrong sizeof");
_Static_assert(_Alignof(struct E_alignment) == 16, "record E_alignment wrong alignment");
_Static_assert(sizeof(struct E_packed) == 128, "record E_packed wrong sizeof");
_Static_assert(_Alignof(struct E_packed) == 1, "record E_packed wrong alignment");
_Static_assert(sizeof(struct E_required_alignment) == 129, "record E_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "record E_required_alignment wrong alignment");
_Static_assert(sizeof(struct E_size) == 130, "record E_size wrong sizeof");
_Static_assert(_Alignof(struct E_size) == 1, "record E_size wrong alignment");
#endif
_Static_assert(sizeof(F) == 128, "record F wrong sizeof");
_Static_assert(_Alignof(F) == 128, "record F wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 256, "record F_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_alignment) == 128, "record F_alignment wrong alignment");
_Static_assert(sizeof(struct F_packed) == 128, "record F_packed wrong sizeof");
_Static_assert(_Alignof(struct F_packed) == 1, "record F_packed wrong alignment");
_Static_assert(sizeof(struct F_required_alignment) == 129, "record F_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "record F_required_alignment wrong alignment");
_Static_assert(sizeof(struct F_size) == 130, "record F_size wrong sizeof");
_Static_assert(_Alignof(struct F_size) == 1, "record F_size wrong alignment");
#endif
_Static_assert(sizeof(G) == 128, "record G wrong sizeof");
_Static_assert(_Alignof(G) == 128, "record G wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 256, "record G_alignment wrong sizeof");
_Static_assert(_Alignof(struct G_alignment) == 128, "record G_alignment wrong alignment");
_Static_assert(sizeof(struct G_packed) == 128, "record G_packed wrong sizeof");
_Static_assert(_Alignof(struct G_packed) == 1, "record G_packed wrong alignment");
_Static_assert(sizeof(struct G_required_alignment) == 129, "record G_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "record G_required_alignment wrong alignment");
_Static_assert(sizeof(struct G_size) == 130, "record G_size wrong sizeof");
_Static_assert(_Alignof(struct G_size) == 1, "record G_size wrong alignment");
#endif
_Static_assert(sizeof(H) == 128, "record H wrong sizeof");
_Static_assert(_Alignof(H) == 4, "record H wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 132, "record H_alignment wrong sizeof");
_Static_assert(_Alignof(struct H_alignment) == 4, "record H_alignment wrong alignment");
_Static_assert(sizeof(struct H_packed) == 128, "record H_packed wrong sizeof");
_Static_assert(_Alignof(struct H_packed) == 1, "record H_packed wrong alignment");
_Static_assert(sizeof(struct H_required_alignment) == 129, "record H_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "record H_required_alignment wrong alignment");
_Static_assert(sizeof(struct H_size) == 130, "record H_size wrong sizeof");
_Static_assert(_Alignof(struct H_size) == 1, "record H_size wrong alignment");
#endif
_Static_assert(sizeof(I) == 128, "record I wrong sizeof");
_Static_assert(_Alignof(I) == 8, "record I wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I_alignment) == 136, "record I_alignment wrong sizeof");
_Static_assert(_Alignof(struct I_alignment) == 8, "record I_alignment wrong alignment");
_Static_assert(sizeof(struct I_packed) == 128, "record I_packed wrong sizeof");
_Static_assert(_Alignof(struct I_packed) == 1, "record I_packed wrong alignment");
_Static_assert(sizeof(struct I_required_alignment) == 129, "record I_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct I_required_alignment) == 1, "record I_required_alignment wrong alignment");
_Static_assert(sizeof(struct I_size) == 130, "record I_size wrong sizeof");
_Static_assert(_Alignof(struct I_size) == 1, "record I_size wrong alignment");
#endif
_Static_assert(sizeof(J) == 128, "record J wrong sizeof");
_Static_assert(_Alignof(J) == 16, "record J wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J_alignment) == 144, "record J_alignment wrong sizeof");
_Static_assert(_Alignof(struct J_alignment) == 16, "record J_alignment wrong alignment");
_Static_assert(sizeof(struct J_packed) == 128, "record J_packed wrong sizeof");
_Static_assert(_Alignof(struct J_packed) == 1, "record J_packed wrong alignment");
_Static_assert(sizeof(struct J_required_alignment) == 129, "record J_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct J_required_alignment) == 1, "record J_required_alignment wrong alignment");
_Static_assert(sizeof(struct J_size) == 130, "record J_size wrong sizeof");
_Static_assert(_Alignof(struct J_size) == 1, "record J_size wrong alignment");
#endif
_Static_assert(sizeof(K) == 128, "record K wrong sizeof");
_Static_assert(_Alignof(K) == 128, "record K wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct K_alignment) == 256, "record K_alignment wrong sizeof");
_Static_assert(_Alignof(struct K_alignment) == 128, "record K_alignment wrong alignment");
_Static_assert(sizeof(struct K_packed) == 128, "record K_packed wrong sizeof");
_Static_assert(_Alignof(struct K_packed) == 1, "record K_packed wrong alignment");
_Static_assert(sizeof(struct K_required_alignment) == 129, "record K_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct K_required_alignment) == 1, "record K_required_alignment wrong alignment");
_Static_assert(sizeof(struct K_size) == 130, "record K_size wrong sizeof");
_Static_assert(_Alignof(struct K_size) == 1, "record K_size wrong alignment");
#endif
#elif defined(THUMBV7A_PC_WINDOWS_MSVC) 
_Static_assert(sizeof(A) == 8, "record A wrong sizeof");
_Static_assert(_Alignof(A) == 128, "record A wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 256, "record A_alignment wrong sizeof");
_Static_assert(_Alignof(struct A_alignment) == 128, "record A_alignment wrong alignment");
_Static_assert(sizeof(struct A_packed) == 8, "record A_packed wrong sizeof");
_Static_assert(_Alignof(struct A_packed) == 1, "record A_packed wrong alignment");
_Static_assert(sizeof(struct A_required_alignment) == 9, "record A_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "record A_required_alignment wrong alignment");
_Static_assert(sizeof(struct A_size) == 10, "record A_size wrong sizeof");
_Static_assert(_Alignof(struct A_size) == 1, "record A_size wrong alignment");
#endif
_Static_assert(sizeof(A_) == 16, "record A_ wrong sizeof");
_Static_assert(_Alignof(A_) == 8, "record A_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A__alignment) == 24, "record A__alignment wrong sizeof");
_Static_assert(_Alignof(struct A__alignment) == 8, "record A__alignment wrong alignment");
_Static_assert(sizeof(struct A__packed) == 16, "record A__packed wrong sizeof");
_Static_assert(_Alignof(struct A__packed) == 1, "record A__packed wrong alignment");
_Static_assert(sizeof(struct A__required_alignment) == 17, "record A__required_alignment wrong sizeof");
_Static_assert(_Alignof(struct A__required_alignment) == 1, "record A__required_alignment wrong alignment");
_Static_assert(sizeof(struct A__size) == 18, "record A__size wrong sizeof");
_Static_assert(_Alignof(struct A__size) == 1, "record A__size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_,a) == 64, "field A_.a wrong bit offset");
#endif
_Static_assert(sizeof(B) == 8, "record B wrong sizeof");
_Static_assert(_Alignof(B) == 8, "record B wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 16, "record B_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_alignment) == 8, "record B_alignment wrong alignment");
_Static_assert(sizeof(struct B_packed) == 8, "record B_packed wrong sizeof");
_Static_assert(_Alignof(struct B_packed) == 1, "record B_packed wrong alignment");
_Static_assert(sizeof(struct B_required_alignment) == 9, "record B_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "record B_required_alignment wrong alignment");
_Static_assert(sizeof(struct B_size) == 10, "record B_size wrong sizeof");
_Static_assert(_Alignof(struct B_size) == 1, "record B_size wrong alignment");
#endif
_Static_assert(sizeof(C) == 8, "record C wrong sizeof");
_Static_assert(_Alignof(C) == 4, "record C wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 12, "record C_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_alignment) == 4, "record C_alignment wrong alignment");
_Static_assert(sizeof(struct C_packed) == 8, "record C_packed wrong sizeof");
_Static_assert(_Alignof(struct C_packed) == 1, "record C_packed wrong alignment");
_Static_assert(sizeof(struct C_required_alignment) == 9, "record C_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "record C_required_alignment wrong alignment");
_Static_assert(sizeof(struct C_size) == 10, "record C_size wrong sizeof");
_Static_assert(_Alignof(struct C_size) == 1, "record C_size wrong alignment");
#endif
_Static_assert(sizeof(D) == 8, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 8, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 16, "record D_alignment wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 8, "record D_alignment wrong alignment");
_Static_assert(sizeof(struct D_packed) == 8, "record D_packed wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D_packed wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 9, "record D_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D_required_alignment wrong alignment");
_Static_assert(sizeof(struct D_size) == 10, "record D_size wrong sizeof");
_Static_assert(_Alignof(struct D_size) == 1, "record D_size wrong alignment");
#endif
_Static_assert(sizeof(E) == 16, "record E wrong sizeof");
_Static_assert(_Alignof(E) == 16, "record E wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 32, "record E_alignment wrong sizeof");
_Static_assert(_Alignof(struct E_alignment) == 16, "record E_alignment wrong alignment");
_Static_assert(sizeof(struct E_packed) == 16, "record E_packed wrong sizeof");
_Static_assert(_Alignof(struct E_packed) == 1, "record E_packed wrong alignment");
_Static_assert(sizeof(struct E_required_alignment) == 17, "record E_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "record E_required_alignment wrong alignment");
_Static_assert(sizeof(struct E_size) == 18, "record E_size wrong sizeof");
_Static_assert(_Alignof(struct E_size) == 1, "record E_size wrong alignment");
#endif
_Static_assert(sizeof(F) == 8, "record F wrong sizeof");
_Static_assert(_Alignof(F) == 8, "record F wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 16, "record F_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_alignment) == 8, "record F_alignment wrong alignment");
_Static_assert(sizeof(struct F_packed) == 8, "record F_packed wrong sizeof");
_Static_assert(_Alignof(struct F_packed) == 1, "record F_packed wrong alignment");
_Static_assert(sizeof(struct F_required_alignment) == 9, "record F_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "record F_required_alignment wrong alignment");
_Static_assert(sizeof(struct F_size) == 10, "record F_size wrong sizeof");
_Static_assert(_Alignof(struct F_size) == 1, "record F_size wrong alignment");
#endif
_Static_assert(sizeof(G) == 8, "record G wrong sizeof");
_Static_assert(_Alignof(G) == 8, "record G wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 16, "record G_alignment wrong sizeof");
_Static_assert(_Alignof(struct G_alignment) == 8, "record G_alignment wrong alignment");
_Static_assert(sizeof(struct G_packed) == 8, "record G_packed wrong sizeof");
_Static_assert(_Alignof(struct G_packed) == 1, "record G_packed wrong alignment");
_Static_assert(sizeof(struct G_required_alignment) == 9, "record G_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "record G_required_alignment wrong alignment");
_Static_assert(sizeof(struct G_size) == 10, "record G_size wrong sizeof");
_Static_assert(_Alignof(struct G_size) == 1, "record G_size wrong alignment");
#endif
_Static_assert(sizeof(H) == 8, "record H wrong sizeof");
_Static_assert(_Alignof(H) == 4, "record H wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 12, "record H_alignment wrong sizeof");
_Static_assert(_Alignof(struct H_alignment) == 4, "record H_alignment wrong alignment");
_Static_assert(sizeof(struct H_packed) == 8, "record H_packed wrong sizeof");
_Static_assert(_Alignof(struct H_packed) == 1, "record H_packed wrong alignment");
_Static_assert(sizeof(struct H_required_alignment) == 9, "record H_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "record H_required_alignment wrong alignment");
_Static_assert(sizeof(struct H_size) == 10, "record H_size wrong sizeof");
_Static_assert(_Alignof(struct H_size) == 1, "record H_size wrong alignment");
#endif
_Static_assert(sizeof(I) == 8, "record I wrong sizeof");
_Static_assert(_Alignof(I) == 8, "record I wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I_alignment) == 16, "record I_alignment wrong sizeof");
_Static_assert(_Alignof(struct I_alignment) == 8, "record I_alignment wrong alignment");
_Static_assert(sizeof(struct I_packed) == 8, "record I_packed wrong sizeof");
_Static_assert(_Alignof(struct I_packed) == 1, "record I_packed wrong alignment");
_Static_assert(sizeof(struct I_required_alignment) == 9, "record I_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct I_required_alignment) == 1, "record I_required_alignment wrong alignment");
_Static_assert(sizeof(struct I_size) == 10, "record I_size wrong sizeof");
_Static_assert(_Alignof(struct I_size) == 1, "record I_size wrong alignment");
#endif
_Static_assert(sizeof(J) == 16, "record J wrong sizeof");
_Static_assert(_Alignof(J) == 16, "record J wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J_alignment) == 32, "record J_alignment wrong sizeof");
_Static_assert(_Alignof(struct J_alignment) == 16, "record J_alignment wrong alignment");
_Static_assert(sizeof(struct J_packed) == 16, "record J_packed wrong sizeof");
_Static_assert(_Alignof(struct J_packed) == 1, "record J_packed wrong alignment");
_Static_assert(sizeof(struct J_required_alignment) == 17, "record J_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct J_required_alignment) == 1, "record J_required_alignment wrong alignment");
_Static_assert(sizeof(struct J_size) == 18, "record J_size wrong sizeof");
_Static_assert(_Alignof(struct J_size) == 1, "record J_size wrong alignment");
#endif
_Static_assert(sizeof(K) == 8, "record K wrong sizeof");
_Static_assert(_Alignof(K) == 8, "record K wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct K_alignment) == 16, "record K_alignment wrong sizeof");
_Static_assert(_Alignof(struct K_alignment) == 8, "record K_alignment wrong alignment");
_Static_assert(sizeof(struct K_packed) == 8, "record K_packed wrong sizeof");
_Static_assert(_Alignof(struct K_packed) == 1, "record K_packed wrong alignment");
_Static_assert(sizeof(struct K_required_alignment) == 9, "record K_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct K_required_alignment) == 1, "record K_required_alignment wrong alignment");
_Static_assert(sizeof(struct K_size) == 10, "record K_size wrong sizeof");
_Static_assert(_Alignof(struct K_size) == 1, "record K_size wrong alignment");
#endif
#elif defined(X8664_PC_WINDOWS_MSVC) ||  defined(X8664_UNKNOWN_WINDOWS) 
_Static_assert(sizeof(A) == 128, "record A wrong sizeof");
_Static_assert(_Alignof(A) == 128, "record A wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 256, "record A_alignment wrong sizeof");
_Static_assert(_Alignof(struct A_alignment) == 128, "record A_alignment wrong alignment");
_Static_assert(sizeof(struct A_packed) == 128, "record A_packed wrong sizeof");
_Static_assert(_Alignof(struct A_packed) == 1, "record A_packed wrong alignment");
_Static_assert(sizeof(struct A_required_alignment) == 129, "record A_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "record A_required_alignment wrong alignment");
_Static_assert(sizeof(struct A_size) == 130, "record A_size wrong sizeof");
_Static_assert(_Alignof(struct A_size) == 1, "record A_size wrong alignment");
#endif
_Static_assert(sizeof(A_) == 256, "record A_ wrong sizeof");
_Static_assert(_Alignof(A_) == 128, "record A_ wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A__alignment) == 384, "record A__alignment wrong sizeof");
_Static_assert(_Alignof(struct A__alignment) == 128, "record A__alignment wrong alignment");
_Static_assert(sizeof(struct A__packed) == 256, "record A__packed wrong sizeof");
_Static_assert(_Alignof(struct A__packed) == 1, "record A__packed wrong alignment");
_Static_assert(sizeof(struct A__required_alignment) == 257, "record A__required_alignment wrong sizeof");
_Static_assert(_Alignof(struct A__required_alignment) == 1, "record A__required_alignment wrong alignment");
_Static_assert(sizeof(struct A__size) == 258, "record A__size wrong sizeof");
_Static_assert(_Alignof(struct A__size) == 1, "record A__size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A_,a) == 1024, "field A_.a wrong bit offset");
#endif
_Static_assert(sizeof(B) == 128, "record B wrong sizeof");
_Static_assert(_Alignof(B) == 128, "record B wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 256, "record B_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_alignment) == 128, "record B_alignment wrong alignment");
_Static_assert(sizeof(struct B_packed) == 128, "record B_packed wrong sizeof");
_Static_assert(_Alignof(struct B_packed) == 1, "record B_packed wrong alignment");
_Static_assert(sizeof(struct B_required_alignment) == 129, "record B_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "record B_required_alignment wrong alignment");
_Static_assert(sizeof(struct B_size) == 130, "record B_size wrong sizeof");
_Static_assert(_Alignof(struct B_size) == 1, "record B_size wrong alignment");
#endif
_Static_assert(sizeof(C) == 128, "record C wrong sizeof");
_Static_assert(_Alignof(C) == 4, "record C wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 132, "record C_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_alignment) == 4, "record C_alignment wrong alignment");
_Static_assert(sizeof(struct C_packed) == 128, "record C_packed wrong sizeof");
_Static_assert(_Alignof(struct C_packed) == 1, "record C_packed wrong alignment");
_Static_assert(sizeof(struct C_required_alignment) == 129, "record C_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "record C_required_alignment wrong alignment");
_Static_assert(sizeof(struct C_size) == 130, "record C_size wrong sizeof");
_Static_assert(_Alignof(struct C_size) == 1, "record C_size wrong alignment");
#endif
_Static_assert(sizeof(D) == 128, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 8, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 136, "record D_alignment wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 8, "record D_alignment wrong alignment");
_Static_assert(sizeof(struct D_packed) == 128, "record D_packed wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D_packed wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 129, "record D_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D_required_alignment wrong alignment");
_Static_assert(sizeof(struct D_size) == 130, "record D_size wrong sizeof");
_Static_assert(_Alignof(struct D_size) == 1, "record D_size wrong alignment");
#endif
_Static_assert(sizeof(E) == 128, "record E wrong sizeof");
_Static_assert(_Alignof(E) == 128, "record E wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 256, "record E_alignment wrong sizeof");
_Static_assert(_Alignof(struct E_alignment) == 128, "record E_alignment wrong alignment");
_Static_assert(sizeof(struct E_packed) == 128, "record E_packed wrong sizeof");
_Static_assert(_Alignof(struct E_packed) == 1, "record E_packed wrong alignment");
_Static_assert(sizeof(struct E_required_alignment) == 129, "record E_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "record E_required_alignment wrong alignment");
_Static_assert(sizeof(struct E_size) == 130, "record E_size wrong sizeof");
_Static_assert(_Alignof(struct E_size) == 1, "record E_size wrong alignment");
#endif
_Static_assert(sizeof(F) == 128, "record F wrong sizeof");
_Static_assert(_Alignof(F) == 128, "record F wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 256, "record F_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_alignment) == 128, "record F_alignment wrong alignment");
_Static_assert(sizeof(struct F_packed) == 128, "record F_packed wrong sizeof");
_Static_assert(_Alignof(struct F_packed) == 1, "record F_packed wrong alignment");
_Static_assert(sizeof(struct F_required_alignment) == 129, "record F_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "record F_required_alignment wrong alignment");
_Static_assert(sizeof(struct F_size) == 130, "record F_size wrong sizeof");
_Static_assert(_Alignof(struct F_size) == 1, "record F_size wrong alignment");
#endif
_Static_assert(sizeof(G) == 128, "record G wrong sizeof");
_Static_assert(_Alignof(G) == 128, "record G wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct G_alignment) == 256, "record G_alignment wrong sizeof");
_Static_assert(_Alignof(struct G_alignment) == 128, "record G_alignment wrong alignment");
_Static_assert(sizeof(struct G_packed) == 128, "record G_packed wrong sizeof");
_Static_assert(_Alignof(struct G_packed) == 1, "record G_packed wrong alignment");
_Static_assert(sizeof(struct G_required_alignment) == 129, "record G_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct G_required_alignment) == 1, "record G_required_alignment wrong alignment");
_Static_assert(sizeof(struct G_size) == 130, "record G_size wrong sizeof");
_Static_assert(_Alignof(struct G_size) == 1, "record G_size wrong alignment");
#endif
_Static_assert(sizeof(H) == 128, "record H wrong sizeof");
_Static_assert(_Alignof(H) == 4, "record H wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct H_alignment) == 132, "record H_alignment wrong sizeof");
_Static_assert(_Alignof(struct H_alignment) == 4, "record H_alignment wrong alignment");
_Static_assert(sizeof(struct H_packed) == 128, "record H_packed wrong sizeof");
_Static_assert(_Alignof(struct H_packed) == 1, "record H_packed wrong alignment");
_Static_assert(sizeof(struct H_required_alignment) == 129, "record H_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct H_required_alignment) == 1, "record H_required_alignment wrong alignment");
_Static_assert(sizeof(struct H_size) == 130, "record H_size wrong sizeof");
_Static_assert(_Alignof(struct H_size) == 1, "record H_size wrong alignment");
#endif
_Static_assert(sizeof(I) == 128, "record I wrong sizeof");
_Static_assert(_Alignof(I) == 8, "record I wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct I_alignment) == 136, "record I_alignment wrong sizeof");
_Static_assert(_Alignof(struct I_alignment) == 8, "record I_alignment wrong alignment");
_Static_assert(sizeof(struct I_packed) == 128, "record I_packed wrong sizeof");
_Static_assert(_Alignof(struct I_packed) == 1, "record I_packed wrong alignment");
_Static_assert(sizeof(struct I_required_alignment) == 129, "record I_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct I_required_alignment) == 1, "record I_required_alignment wrong alignment");
_Static_assert(sizeof(struct I_size) == 130, "record I_size wrong sizeof");
_Static_assert(_Alignof(struct I_size) == 1, "record I_size wrong alignment");
#endif
_Static_assert(sizeof(J) == 128, "record J wrong sizeof");
_Static_assert(_Alignof(J) == 128, "record J wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct J_alignment) == 256, "record J_alignment wrong sizeof");
_Static_assert(_Alignof(struct J_alignment) == 128, "record J_alignment wrong alignment");
_Static_assert(sizeof(struct J_packed) == 128, "record J_packed wrong sizeof");
_Static_assert(_Alignof(struct J_packed) == 1, "record J_packed wrong alignment");
_Static_assert(sizeof(struct J_required_alignment) == 129, "record J_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct J_required_alignment) == 1, "record J_required_alignment wrong alignment");
_Static_assert(sizeof(struct J_size) == 130, "record J_size wrong sizeof");
_Static_assert(_Alignof(struct J_size) == 1, "record J_size wrong alignment");
#endif
_Static_assert(sizeof(K) == 128, "record K wrong sizeof");
_Static_assert(_Alignof(K) == 128, "record K wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct K_alignment) == 256, "record K_alignment wrong sizeof");
_Static_assert(_Alignof(struct K_alignment) == 128, "record K_alignment wrong alignment");
_Static_assert(sizeof(struct K_packed) == 128, "record K_packed wrong sizeof");
_Static_assert(_Alignof(struct K_packed) == 1, "record K_packed wrong alignment");
_Static_assert(sizeof(struct K_required_alignment) == 129, "record K_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct K_required_alignment) == 1, "record K_required_alignment wrong alignment");
_Static_assert(sizeof(struct K_size) == 130, "record K_size wrong sizeof");
_Static_assert(_Alignof(struct K_size) == 1, "record K_size wrong alignment");
#endif
#endif
