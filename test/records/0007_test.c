// SPDX-License-Identifier: GPL-3.0-or-later

// This test file is auto-generated. do not edit.
// This file is a derivative work from the test files found// in this repo : https://github.com/mahkoh/repr-c
// and is under the same licence as the original work.

#ifdef MSVC
__declspec(align(8)) typedef short a;
#else
typedef short a __attribute__((aligned(8)));
#endif
a var1;
struct a_alignment {
#ifdef MSVC
    char a[_Alignof(a)];
    char b;
#else
    char a;
    a b;
#endif
};
struct a_alignment var2;
#pragma pack(1)
struct a_packed {
    a a;
};
#pragma pack()
struct a_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct a_packed)];
    char b;
#else
    char a;
    struct a_packed b;
#endif
};
struct a_required_alignment var3;
struct a_size {
    char a[sizeof(a)+1];
    char b;
};
struct a_size var4;

#pragma pack(4)
typedef struct {
    a i:1;
} A;
A var5;
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
struct A_alignment var6;
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
struct A_required_alignment var7;
struct A_size {
    char a[sizeof(A)+1];
    char b;
};
struct A_size var8;

#ifdef MSVC
__declspec(align(4)) typedef short b;
#else
typedef short b __attribute__((aligned(4)));
#endif
b var9;
struct b_alignment {
#ifdef MSVC
    char a[_Alignof(b)];
    char b;
#else
    char a;
    b b;
#endif
};
struct b_alignment var10;
#pragma pack(1)
struct b_packed {
    b a;
};
#pragma pack()
struct b_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct b_packed)];
    char b;
#else
    char a;
    struct b_packed b;
#endif
};
struct b_required_alignment var11;
struct b_size {
    char a[sizeof(b)+1];
    char b;
};
struct b_size var12;

#pragma pack(8)
typedef struct {
    b i:1;
} B;
B var13;
#pragma pack()
struct B_alignment {
#ifdef MSVC
    char a[_Alignof(B)];
    char b;
#else
    char a;
    B b;
#endif
};
struct B_alignment var14;
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
struct B_required_alignment var15;
struct B_size {
    char a[sizeof(B)+1];
    char b;
};
struct B_size var16;

#ifdef MSVC
__declspec(align(8)) typedef int c;
#else
typedef int c __attribute__((aligned(8)));
#endif
c var17;
struct c_alignment {
#ifdef MSVC
    char a[_Alignof(c)];
    char b;
#else
    char a;
    c b;
#endif
};
struct c_alignment var18;
#pragma pack(1)
struct c_packed {
    c a;
};
#pragma pack()
struct c_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct c_packed)];
    char b;
#else
    char a;
    struct c_packed b;
#endif
};
struct c_required_alignment var19;
struct c_size {
    char a[sizeof(c)+1];
    char b;
};
struct c_size var20;

#pragma pack(2)
typedef struct {
    c i:1;
} C;
C var21;
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
struct C_alignment var22;
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
struct C_required_alignment var23;
struct C_size {
    char a[sizeof(C)+1];
    char b;
};
struct C_size var24;

#ifdef MSVC
__declspec(align(4)) typedef long long d;
#else
typedef long long d __attribute__((aligned(4)));
#endif
d var25;
struct d_alignment {
#ifdef MSVC
    char a[_Alignof(d)];
    char b;
#else
    char a;
    d b;
#endif
};
struct d_alignment var26;
#pragma pack(1)
struct d_packed {
    d a;
};
#pragma pack()
struct d_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct d_packed)];
    char b;
#else
    char a;
    struct d_packed b;
#endif
};
struct d_required_alignment var27;
struct d_size {
    char a[sizeof(d)+1];
    char b;
};
struct d_size var28;

#pragma pack(2)
typedef struct {
    d i:1;
} D;
D var29;
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
struct D_alignment var30;
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
struct D_required_alignment var31;
struct D_size {
    char a[sizeof(D)+1];
    char b;
};
struct D_size var32;

#ifdef MSVC
__declspec(align(2)) typedef int e;
#else
typedef int e __attribute__((aligned(2)));
#endif
e var33;
struct e_alignment {
#ifdef MSVC
    char a[_Alignof(e)];
    char b;
#else
    char a;
    e b;
#endif
};
struct e_alignment var34;
#pragma pack(1)
struct e_packed {
    e a;
};
#pragma pack()
struct e_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct e_packed)];
    char b;
#else
    char a;
    struct e_packed b;
#endif
};
struct e_required_alignment var35;
struct e_size {
    char a[sizeof(e)+1];
    char b;
};
struct e_size var36;

#pragma pack(8)
typedef struct {
    e i:1;
} E;
E var37;
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
__declspec(align(2)) typedef long long f;
#else
typedef long long f __attribute__((aligned(2)));
#endif
f var41;
struct f_alignment {
#ifdef MSVC
    char a[_Alignof(f)];
    char b;
#else
    char a;
    f b;
#endif
};
struct f_alignment var42;
#pragma pack(1)
struct f_packed {
    f a;
};
#pragma pack()
struct f_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct f_packed)];
    char b;
#else
    char a;
    struct f_packed b;
#endif
};
struct f_required_alignment var43;
struct f_size {
    char a[sizeof(f)+1];
    char b;
};
struct f_size var44;

#pragma pack(4)
typedef struct {
    f i:1;
} F;
F var45;
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
struct F_alignment var46;
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
struct F_required_alignment var47;
struct F_size {
    char a[sizeof(F)+1];
    char b;
};
struct F_size var48;

#if defined(AARCH64_APPLE_MACOSX) ||  defined(AARCH64_FUCHSIA) ||  defined(AARCH64_LINUX_ANDROID) ||  defined(AARCH64_UNKNOWN_FREEBSD) ||  \
 defined(AARCH64_UNKNOWN_HERMIT) ||  defined(AARCH64_UNKNOWN_LINUX_GNU) ||  defined(AARCH64_UNKNOWN_LINUX_MUSL) ||  defined(AARCH64_UNKNOWN_NETBSD) ||  \
 defined(AARCH64_UNKNOWN_NONE) ||  defined(AARCH64_UNKNOWN_OPENBSD) ||  defined(AARCH64_UNKNOWN_REDOX) ||  defined(ARM64_APPLE_IOS) ||  \
 defined(ARM64_APPLE_IOS_MACABI) ||  defined(ARM64_APPLE_TVOS) ||  defined(ARMEBV7R_UNKNOWN_NONE_EABI) ||  defined(ARMEBV7R_UNKNOWN_NONE_EABIHF) ||  \
 defined(ARM_LINUX_ANDROIDEABI) ||  defined(ARM_UNKNOWN_LINUX_GNUEABI) ||  defined(ARM_UNKNOWN_LINUX_GNUEABIHF) ||  defined(ARMV4T_UNKNOWN_LINUX_GNUEABI) ||  \
 defined(ARMV5TE_UNKNOWN_LINUX_GNUEABI) ||  defined(ARMV5TE_UNKNOWN_LINUX_UCLIBCGNUEABI) ||  defined(ARMV6_UNKNOWN_FREEBSD_GNUEABIHF) ||  \
 defined(ARMV6_UNKNOWN_NETBSDELF_EABIHF) ||  defined(ARMV7A_NONE_EABI) ||  defined(ARMV7A_NONE_EABIHF) ||  defined(ARMV7_NONE_LINUX_ANDROID) ||  \
 defined(ARMV7R_UNKNOWN_NONE_EABI) ||  defined(ARMV7R_UNKNOWN_NONE_EABIHF) ||  defined(ARMV7_UNKNOWN_FREEBSD_GNUEABIHF) ||  defined(ARMV7_UNKNOWN_LINUX_GNUEABI) ||  \
 defined(ARMV7_UNKNOWN_LINUX_GNUEABIHF) ||  defined(ARMV7_UNKNOWN_NETBSDELF_EABIHF) ||  defined(HEXAGON_UNKNOWN_LINUX_MUSL) ||  defined(MIPS64EL_UNKNOWN_LINUX_GNUABI64) ||  \
 defined(MIPS64EL_UNKNOWN_LINUX_MUSL) ||  defined(MIPS64_UNKNOWN_LINUX_GNUABI64) ||  defined(MIPS64_UNKNOWN_LINUX_MUSL) ||  defined(MIPSEL_SONY_PSP) ||  \
 defined(MIPSEL_UNKNOWN_LINUX_GNU) ||  defined(MIPSEL_UNKNOWN_LINUX_MUSL) ||  defined(MIPSEL_UNKNOWN_LINUX_UCLIBC) ||  defined(MIPSEL_UNKNOWN_NONE) ||  \
 defined(MIPSISA32R6EL_UNKNOWN_LINUX_GNU) ||  defined(MIPSISA32R6_UNKNOWN_LINUX_GNU) ||  defined(MIPSISA64R6EL_UNKNOWN_LINUX_GNUABI64) ||  \
 defined(MIPSISA64R6_UNKNOWN_LINUX_GNUABI64) ||  defined(MIPS_UNKNOWN_LINUX_GNU) ||  defined(MIPS_UNKNOWN_LINUX_MUSL) ||  defined(MIPS_UNKNOWN_LINUX_UCLIBC) ||  \
 defined(POWERPC64LE_UNKNOWN_LINUX_GNU) ||  defined(POWERPC64LE_UNKNOWN_LINUX_MUSL) ||  defined(POWERPC64_UNKNOWN_FREEBSD) ||  defined(POWERPC64_UNKNOWN_LINUX_GNU) ||  \
 defined(POWERPC64_UNKNOWN_LINUX_MUSL) ||  defined(POWERPC_UNKNOWN_LINUX_GNU) ||  defined(POWERPC_UNKNOWN_LINUX_GNUSPE) ||  defined(POWERPC_UNKNOWN_LINUX_MUSL) ||  \
 defined(POWERPC_UNKNOWN_NETBSD) ||  defined(RISCV32) ||  defined(RISCV32_UNKNOWN_LINUX_GNU) ||  defined(RISCV64) ||  defined(RISCV64_UNKNOWN_LINUX_GNU) ||  \
 defined(S390X_UNKNOWN_LINUX_GNU) ||  defined(SPARC64_UNKNOWN_LINUX_GNU) ||  defined(SPARC64_UNKNOWN_NETBSD) ||  defined(SPARC64_UNKNOWN_OPENBSD) ||  \
 defined(SPARC_UNKNOWN_LINUX_GNU) ||  defined(SPARCV9_SUN_SOLARIS) ||  defined(THUMBV4T_NONE_EABI) ||  defined(THUMBV6M_NONE_EABI) ||  \
 defined(THUMBV7EM_NONE_EABIHF) ||  defined(THUMBV7EM_NONE_EABI) ||  defined(THUMBV7M_NONE_EABI) ||  defined(THUMBV8MBASE_NONE_EABI) ||  \
 defined(THUMBV8MMAIN_NONE_EABIHF) ||  defined(THUMBV8MMAIN_NONE_EABI) ||  defined(WASM32_UNKNOWN_EMSCRIPTEN) ||  defined(WASM32_UNKNOWN_UNKNOWN) ||  \
 defined(WASM32_WASI) ||  defined(X8664_APPLE_IOS_MACABI) ||  defined(X8664_APPLE_IOS) ||  defined(X8664_APPLE_MACOSX) ||  defined(X8664_APPLE_TVOS) ||  \
 defined(X8664_ELF) ||  defined(X8664_FUCHSIA) ||  defined(X8664_LINUX_ANDROID) ||  defined(X8664_PC_SOLARIS) ||  defined(X8664_RUMPRUN_NETBSD) ||  \
 defined(X8664_UNKNOWN_DRAGONFLY) ||  defined(X8664_UNKNOWN_FREEBSD) ||  defined(X8664_UNKNOWN_HAIKU) ||  defined(X8664_UNKNOWN_HERMIT) ||  \
 defined(X8664_UNKNOWN_L4RE_UCLIBC) ||  defined(X8664_UNKNOWN_LINUX_GNUX32) ||  defined(X8664_UNKNOWN_LINUX_GNU) ||  defined(X8664_UNKNOWN_LINUX_MUSL) ||  \
 defined(X8664_UNKNOWN_NETBSD) ||  defined(X8664_UNKNOWN_OPENBSD) ||  defined(X8664_UNKNOWN_REDOX) 
_Static_assert(sizeof(a) == 2, "record a wrong sizeof");
_Static_assert(_Alignof(a) == 8, "record a wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct a_alignment) == 16, "record a_alignment wrong sizeof");
_Static_assert(_Alignof(struct a_alignment) == 8, "record a_alignment wrong alignment");
_Static_assert(sizeof(struct a_packed) == 2, "record a_packed wrong sizeof");
_Static_assert(_Alignof(struct a_packed) == 1, "record a_packed wrong alignment");
_Static_assert(sizeof(struct a_required_alignment) == 3, "record a_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct a_required_alignment) == 1, "record a_required_alignment wrong alignment");
_Static_assert(sizeof(struct a_size) == 4, "record a_size wrong sizeof");
_Static_assert(_Alignof(struct a_size) == 1, "record a_size wrong alignment");
#endif
_Static_assert(sizeof(A) == 4, "record A wrong sizeof");
_Static_assert(_Alignof(A) == 4, "record A wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 8, "record A_alignment wrong sizeof");
_Static_assert(_Alignof(struct A_alignment) == 4, "record A_alignment wrong alignment");
_Static_assert(sizeof(struct A_packed) == 4, "record A_packed wrong sizeof");
_Static_assert(_Alignof(struct A_packed) == 1, "record A_packed wrong alignment");
_Static_assert(sizeof(struct A_required_alignment) == 5, "record A_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "record A_required_alignment wrong alignment");
_Static_assert(sizeof(struct A_size) == 6, "record A_size wrong sizeof");
_Static_assert(_Alignof(struct A_size) == 1, "record A_size wrong alignment");
#endif
_Static_assert(sizeof(b) == 2, "record b wrong sizeof");
_Static_assert(_Alignof(b) == 4, "record b wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct b_alignment) == 8, "record b_alignment wrong sizeof");
_Static_assert(_Alignof(struct b_alignment) == 4, "record b_alignment wrong alignment");
_Static_assert(sizeof(struct b_packed) == 2, "record b_packed wrong sizeof");
_Static_assert(_Alignof(struct b_packed) == 1, "record b_packed wrong alignment");
_Static_assert(sizeof(struct b_required_alignment) == 3, "record b_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct b_required_alignment) == 1, "record b_required_alignment wrong alignment");
_Static_assert(sizeof(struct b_size) == 4, "record b_size wrong sizeof");
_Static_assert(_Alignof(struct b_size) == 1, "record b_size wrong alignment");
#endif
_Static_assert(sizeof(B) == 4, "record B wrong sizeof");
_Static_assert(_Alignof(B) == 4, "record B wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 8, "record B_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_alignment) == 4, "record B_alignment wrong alignment");
_Static_assert(sizeof(struct B_packed) == 4, "record B_packed wrong sizeof");
_Static_assert(_Alignof(struct B_packed) == 1, "record B_packed wrong alignment");
_Static_assert(sizeof(struct B_required_alignment) == 5, "record B_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "record B_required_alignment wrong alignment");
_Static_assert(sizeof(struct B_size) == 6, "record B_size wrong sizeof");
_Static_assert(_Alignof(struct B_size) == 1, "record B_size wrong alignment");
#endif
_Static_assert(sizeof(c) == 4, "record c wrong sizeof");
_Static_assert(_Alignof(c) == 8, "record c wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct c_alignment) == 16, "record c_alignment wrong sizeof");
_Static_assert(_Alignof(struct c_alignment) == 8, "record c_alignment wrong alignment");
_Static_assert(sizeof(struct c_packed) == 4, "record c_packed wrong sizeof");
_Static_assert(_Alignof(struct c_packed) == 1, "record c_packed wrong alignment");
_Static_assert(sizeof(struct c_required_alignment) == 5, "record c_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct c_required_alignment) == 1, "record c_required_alignment wrong alignment");
_Static_assert(sizeof(struct c_size) == 6, "record c_size wrong sizeof");
_Static_assert(_Alignof(struct c_size) == 1, "record c_size wrong alignment");
#endif
_Static_assert(sizeof(C) == 2, "record C wrong sizeof");
_Static_assert(_Alignof(C) == 2, "record C wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 4, "record C_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_alignment) == 2, "record C_alignment wrong alignment");
_Static_assert(sizeof(struct C_packed) == 2, "record C_packed wrong sizeof");
_Static_assert(_Alignof(struct C_packed) == 1, "record C_packed wrong alignment");
_Static_assert(sizeof(struct C_required_alignment) == 3, "record C_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "record C_required_alignment wrong alignment");
_Static_assert(sizeof(struct C_size) == 4, "record C_size wrong sizeof");
_Static_assert(_Alignof(struct C_size) == 1, "record C_size wrong alignment");
#endif
_Static_assert(sizeof(d) == 8, "record d wrong sizeof");
_Static_assert(_Alignof(d) == 4, "record d wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct d_alignment) == 12, "record d_alignment wrong sizeof");
_Static_assert(_Alignof(struct d_alignment) == 4, "record d_alignment wrong alignment");
_Static_assert(sizeof(struct d_packed) == 8, "record d_packed wrong sizeof");
_Static_assert(_Alignof(struct d_packed) == 1, "record d_packed wrong alignment");
_Static_assert(sizeof(struct d_required_alignment) == 9, "record d_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct d_required_alignment) == 1, "record d_required_alignment wrong alignment");
_Static_assert(sizeof(struct d_size) == 10, "record d_size wrong sizeof");
_Static_assert(_Alignof(struct d_size) == 1, "record d_size wrong alignment");
#endif
_Static_assert(sizeof(D) == 2, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 2, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 4, "record D_alignment wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 2, "record D_alignment wrong alignment");
_Static_assert(sizeof(struct D_packed) == 2, "record D_packed wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D_packed wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 3, "record D_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D_required_alignment wrong alignment");
_Static_assert(sizeof(struct D_size) == 4, "record D_size wrong sizeof");
_Static_assert(_Alignof(struct D_size) == 1, "record D_size wrong alignment");
#endif
_Static_assert(sizeof(e) == 4, "record e wrong sizeof");
_Static_assert(_Alignof(e) == 2, "record e wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct e_alignment) == 6, "record e_alignment wrong sizeof");
_Static_assert(_Alignof(struct e_alignment) == 2, "record e_alignment wrong alignment");
_Static_assert(sizeof(struct e_packed) == 4, "record e_packed wrong sizeof");
_Static_assert(_Alignof(struct e_packed) == 1, "record e_packed wrong alignment");
_Static_assert(sizeof(struct e_required_alignment) == 5, "record e_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct e_required_alignment) == 1, "record e_required_alignment wrong alignment");
_Static_assert(sizeof(struct e_size) == 6, "record e_size wrong sizeof");
_Static_assert(_Alignof(struct e_size) == 1, "record e_size wrong alignment");
#endif
_Static_assert(sizeof(E) == 2, "record E wrong sizeof");
_Static_assert(_Alignof(E) == 2, "record E wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 4, "record E_alignment wrong sizeof");
_Static_assert(_Alignof(struct E_alignment) == 2, "record E_alignment wrong alignment");
_Static_assert(sizeof(struct E_packed) == 2, "record E_packed wrong sizeof");
_Static_assert(_Alignof(struct E_packed) == 1, "record E_packed wrong alignment");
_Static_assert(sizeof(struct E_required_alignment) == 3, "record E_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "record E_required_alignment wrong alignment");
_Static_assert(sizeof(struct E_size) == 4, "record E_size wrong sizeof");
_Static_assert(_Alignof(struct E_size) == 1, "record E_size wrong alignment");
#endif
_Static_assert(sizeof(f) == 8, "record f wrong sizeof");
_Static_assert(_Alignof(f) == 2, "record f wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct f_alignment) == 10, "record f_alignment wrong sizeof");
_Static_assert(_Alignof(struct f_alignment) == 2, "record f_alignment wrong alignment");
_Static_assert(sizeof(struct f_packed) == 8, "record f_packed wrong sizeof");
_Static_assert(_Alignof(struct f_packed) == 1, "record f_packed wrong alignment");
_Static_assert(sizeof(struct f_required_alignment) == 9, "record f_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct f_required_alignment) == 1, "record f_required_alignment wrong alignment");
_Static_assert(sizeof(struct f_size) == 10, "record f_size wrong sizeof");
_Static_assert(_Alignof(struct f_size) == 1, "record f_size wrong alignment");
#endif
_Static_assert(sizeof(F) == 2, "record F wrong sizeof");
_Static_assert(_Alignof(F) == 2, "record F wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 4, "record F_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_alignment) == 2, "record F_alignment wrong alignment");
_Static_assert(sizeof(struct F_packed) == 2, "record F_packed wrong sizeof");
_Static_assert(_Alignof(struct F_packed) == 1, "record F_packed wrong alignment");
_Static_assert(sizeof(struct F_required_alignment) == 3, "record F_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "record F_required_alignment wrong alignment");
_Static_assert(sizeof(struct F_size) == 4, "record F_size wrong sizeof");
_Static_assert(_Alignof(struct F_size) == 1, "record F_size wrong alignment");
#endif
#elif defined(AARCH64_PC_WINDOWS_MSVC) ||  defined(I586_PC_WINDOWS_MSVC) ||  defined(I686_PC_WINDOWS_MSVC) ||  defined(I686_UNKNOWN_WINDOWS) ||  \
 defined(THUMBV7A_PC_WINDOWS_MSVC) ||  defined(X8664_PC_WINDOWS_MSVC) ||  defined(X8664_UNKNOWN_WINDOWS) 
_Static_assert(sizeof(a) == 2, "record a wrong sizeof");
_Static_assert(_Alignof(a) == 8, "record a wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct a_alignment) == 16, "record a_alignment wrong sizeof");
_Static_assert(_Alignof(struct a_alignment) == 8, "record a_alignment wrong alignment");
_Static_assert(sizeof(struct a_packed) == 2, "record a_packed wrong sizeof");
_Static_assert(_Alignof(struct a_packed) == 1, "record a_packed wrong alignment");
_Static_assert(sizeof(struct a_required_alignment) == 3, "record a_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct a_required_alignment) == 1, "record a_required_alignment wrong alignment");
_Static_assert(sizeof(struct a_size) == 4, "record a_size wrong sizeof");
_Static_assert(_Alignof(struct a_size) == 1, "record a_size wrong alignment");
#endif
_Static_assert(sizeof(A) == 4, "record A wrong sizeof");
_Static_assert(_Alignof(A) == 8, "record A wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 16, "record A_alignment wrong sizeof");
_Static_assert(_Alignof(struct A_alignment) == 8, "record A_alignment wrong alignment");
_Static_assert(sizeof(struct A_packed) == 4, "record A_packed wrong sizeof");
_Static_assert(_Alignof(struct A_packed) == 1, "record A_packed wrong alignment");
_Static_assert(sizeof(struct A_required_alignment) == 5, "record A_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "record A_required_alignment wrong alignment");
_Static_assert(sizeof(struct A_size) == 6, "record A_size wrong sizeof");
_Static_assert(_Alignof(struct A_size) == 1, "record A_size wrong alignment");
#endif
_Static_assert(sizeof(b) == 2, "record b wrong sizeof");
_Static_assert(_Alignof(b) == 4, "record b wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct b_alignment) == 8, "record b_alignment wrong sizeof");
_Static_assert(_Alignof(struct b_alignment) == 4, "record b_alignment wrong alignment");
_Static_assert(sizeof(struct b_packed) == 2, "record b_packed wrong sizeof");
_Static_assert(_Alignof(struct b_packed) == 1, "record b_packed wrong alignment");
_Static_assert(sizeof(struct b_required_alignment) == 3, "record b_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct b_required_alignment) == 1, "record b_required_alignment wrong alignment");
_Static_assert(sizeof(struct b_size) == 4, "record b_size wrong sizeof");
_Static_assert(_Alignof(struct b_size) == 1, "record b_size wrong alignment");
#endif
_Static_assert(sizeof(B) == 4, "record B wrong sizeof");
_Static_assert(_Alignof(B) == 4, "record B wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 8, "record B_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_alignment) == 4, "record B_alignment wrong alignment");
_Static_assert(sizeof(struct B_packed) == 4, "record B_packed wrong sizeof");
_Static_assert(_Alignof(struct B_packed) == 1, "record B_packed wrong alignment");
_Static_assert(sizeof(struct B_required_alignment) == 5, "record B_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "record B_required_alignment wrong alignment");
_Static_assert(sizeof(struct B_size) == 6, "record B_size wrong sizeof");
_Static_assert(_Alignof(struct B_size) == 1, "record B_size wrong alignment");
#endif
_Static_assert(sizeof(c) == 4, "record c wrong sizeof");
_Static_assert(_Alignof(c) == 8, "record c wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct c_alignment) == 16, "record c_alignment wrong sizeof");
_Static_assert(_Alignof(struct c_alignment) == 8, "record c_alignment wrong alignment");
_Static_assert(sizeof(struct c_packed) == 4, "record c_packed wrong sizeof");
_Static_assert(_Alignof(struct c_packed) == 1, "record c_packed wrong alignment");
_Static_assert(sizeof(struct c_required_alignment) == 5, "record c_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct c_required_alignment) == 1, "record c_required_alignment wrong alignment");
_Static_assert(sizeof(struct c_size) == 6, "record c_size wrong sizeof");
_Static_assert(_Alignof(struct c_size) == 1, "record c_size wrong alignment");
#endif
_Static_assert(sizeof(C) == 4, "record C wrong sizeof");
_Static_assert(_Alignof(C) == 8, "record C wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 16, "record C_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_alignment) == 8, "record C_alignment wrong alignment");
_Static_assert(sizeof(struct C_packed) == 4, "record C_packed wrong sizeof");
_Static_assert(_Alignof(struct C_packed) == 1, "record C_packed wrong alignment");
_Static_assert(sizeof(struct C_required_alignment) == 5, "record C_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "record C_required_alignment wrong alignment");
_Static_assert(sizeof(struct C_size) == 6, "record C_size wrong sizeof");
_Static_assert(_Alignof(struct C_size) == 1, "record C_size wrong alignment");
#endif
_Static_assert(sizeof(d) == 8, "record d wrong sizeof");
_Static_assert(_Alignof(d) == 8, "record d wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct d_alignment) == 16, "record d_alignment wrong sizeof");
_Static_assert(_Alignof(struct d_alignment) == 8, "record d_alignment wrong alignment");
_Static_assert(sizeof(struct d_packed) == 8, "record d_packed wrong sizeof");
_Static_assert(_Alignof(struct d_packed) == 1, "record d_packed wrong alignment");
_Static_assert(sizeof(struct d_required_alignment) == 9, "record d_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct d_required_alignment) == 1, "record d_required_alignment wrong alignment");
_Static_assert(sizeof(struct d_size) == 10, "record d_size wrong sizeof");
_Static_assert(_Alignof(struct d_size) == 1, "record d_size wrong alignment");
#endif
_Static_assert(sizeof(D) == 8, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 4, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 12, "record D_alignment wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 4, "record D_alignment wrong alignment");
_Static_assert(sizeof(struct D_packed) == 8, "record D_packed wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D_packed wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 9, "record D_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D_required_alignment wrong alignment");
_Static_assert(sizeof(struct D_size) == 10, "record D_size wrong sizeof");
_Static_assert(_Alignof(struct D_size) == 1, "record D_size wrong alignment");
#endif
_Static_assert(sizeof(e) == 4, "record e wrong sizeof");
_Static_assert(_Alignof(e) == 4, "record e wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct e_alignment) == 8, "record e_alignment wrong sizeof");
_Static_assert(_Alignof(struct e_alignment) == 4, "record e_alignment wrong alignment");
_Static_assert(sizeof(struct e_packed) == 4, "record e_packed wrong sizeof");
_Static_assert(_Alignof(struct e_packed) == 1, "record e_packed wrong alignment");
_Static_assert(sizeof(struct e_required_alignment) == 5, "record e_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct e_required_alignment) == 1, "record e_required_alignment wrong alignment");
_Static_assert(sizeof(struct e_size) == 6, "record e_size wrong sizeof");
_Static_assert(_Alignof(struct e_size) == 1, "record e_size wrong alignment");
#endif
_Static_assert(sizeof(E) == 4, "record E wrong sizeof");
_Static_assert(_Alignof(E) == 4, "record E wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 8, "record E_alignment wrong sizeof");
_Static_assert(_Alignof(struct E_alignment) == 4, "record E_alignment wrong alignment");
_Static_assert(sizeof(struct E_packed) == 4, "record E_packed wrong sizeof");
_Static_assert(_Alignof(struct E_packed) == 1, "record E_packed wrong alignment");
_Static_assert(sizeof(struct E_required_alignment) == 5, "record E_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "record E_required_alignment wrong alignment");
_Static_assert(sizeof(struct E_size) == 6, "record E_size wrong sizeof");
_Static_assert(_Alignof(struct E_size) == 1, "record E_size wrong alignment");
#endif
_Static_assert(sizeof(f) == 8, "record f wrong sizeof");
_Static_assert(_Alignof(f) == 8, "record f wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct f_alignment) == 16, "record f_alignment wrong sizeof");
_Static_assert(_Alignof(struct f_alignment) == 8, "record f_alignment wrong alignment");
_Static_assert(sizeof(struct f_packed) == 8, "record f_packed wrong sizeof");
_Static_assert(_Alignof(struct f_packed) == 1, "record f_packed wrong alignment");
_Static_assert(sizeof(struct f_required_alignment) == 9, "record f_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct f_required_alignment) == 1, "record f_required_alignment wrong alignment");
_Static_assert(sizeof(struct f_size) == 10, "record f_size wrong sizeof");
_Static_assert(_Alignof(struct f_size) == 1, "record f_size wrong alignment");
#endif
_Static_assert(sizeof(F) == 8, "record F wrong sizeof");
_Static_assert(_Alignof(F) == 4, "record F wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 12, "record F_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_alignment) == 4, "record F_alignment wrong alignment");
_Static_assert(sizeof(struct F_packed) == 8, "record F_packed wrong sizeof");
_Static_assert(_Alignof(struct F_packed) == 1, "record F_packed wrong alignment");
_Static_assert(sizeof(struct F_required_alignment) == 9, "record F_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "record F_required_alignment wrong alignment");
_Static_assert(sizeof(struct F_size) == 10, "record F_size wrong sizeof");
_Static_assert(_Alignof(struct F_size) == 1, "record F_size wrong alignment");
#endif
#elif defined(ARMV7_APPLE_IOS) ||  defined(ARMV7S_APPLE_IOS) 
_Static_assert(sizeof(a) == 2, "record a wrong sizeof");
_Static_assert(_Alignof(a) == 8, "record a wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct a_alignment) == 16, "record a_alignment wrong sizeof");
_Static_assert(_Alignof(struct a_alignment) == 8, "record a_alignment wrong alignment");
_Static_assert(sizeof(struct a_packed) == 2, "record a_packed wrong sizeof");
_Static_assert(_Alignof(struct a_packed) == 1, "record a_packed wrong alignment");
_Static_assert(sizeof(struct a_required_alignment) == 3, "record a_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct a_required_alignment) == 1, "record a_required_alignment wrong alignment");
_Static_assert(sizeof(struct a_size) == 4, "record a_size wrong sizeof");
_Static_assert(_Alignof(struct a_size) == 1, "record a_size wrong alignment");
#endif
_Static_assert(sizeof(A) == 1, "record A wrong sizeof");
_Static_assert(_Alignof(A) == 1, "record A wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 2, "record A_alignment wrong sizeof");
_Static_assert(_Alignof(struct A_alignment) == 1, "record A_alignment wrong alignment");
_Static_assert(sizeof(struct A_packed) == 1, "record A_packed wrong sizeof");
_Static_assert(_Alignof(struct A_packed) == 1, "record A_packed wrong alignment");
_Static_assert(sizeof(struct A_required_alignment) == 2, "record A_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "record A_required_alignment wrong alignment");
_Static_assert(sizeof(struct A_size) == 3, "record A_size wrong sizeof");
_Static_assert(_Alignof(struct A_size) == 1, "record A_size wrong alignment");
#endif
_Static_assert(sizeof(b) == 2, "record b wrong sizeof");
_Static_assert(_Alignof(b) == 4, "record b wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct b_alignment) == 8, "record b_alignment wrong sizeof");
_Static_assert(_Alignof(struct b_alignment) == 4, "record b_alignment wrong alignment");
_Static_assert(sizeof(struct b_packed) == 2, "record b_packed wrong sizeof");
_Static_assert(_Alignof(struct b_packed) == 1, "record b_packed wrong alignment");
_Static_assert(sizeof(struct b_required_alignment) == 3, "record b_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct b_required_alignment) == 1, "record b_required_alignment wrong alignment");
_Static_assert(sizeof(struct b_size) == 4, "record b_size wrong sizeof");
_Static_assert(_Alignof(struct b_size) == 1, "record b_size wrong alignment");
#endif
_Static_assert(sizeof(B) == 1, "record B wrong sizeof");
_Static_assert(_Alignof(B) == 1, "record B wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 2, "record B_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_alignment) == 1, "record B_alignment wrong alignment");
_Static_assert(sizeof(struct B_packed) == 1, "record B_packed wrong sizeof");
_Static_assert(_Alignof(struct B_packed) == 1, "record B_packed wrong alignment");
_Static_assert(sizeof(struct B_required_alignment) == 2, "record B_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "record B_required_alignment wrong alignment");
_Static_assert(sizeof(struct B_size) == 3, "record B_size wrong sizeof");
_Static_assert(_Alignof(struct B_size) == 1, "record B_size wrong alignment");
#endif
_Static_assert(sizeof(c) == 4, "record c wrong sizeof");
_Static_assert(_Alignof(c) == 8, "record c wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct c_alignment) == 16, "record c_alignment wrong sizeof");
_Static_assert(_Alignof(struct c_alignment) == 8, "record c_alignment wrong alignment");
_Static_assert(sizeof(struct c_packed) == 4, "record c_packed wrong sizeof");
_Static_assert(_Alignof(struct c_packed) == 1, "record c_packed wrong alignment");
_Static_assert(sizeof(struct c_required_alignment) == 5, "record c_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct c_required_alignment) == 1, "record c_required_alignment wrong alignment");
_Static_assert(sizeof(struct c_size) == 6, "record c_size wrong sizeof");
_Static_assert(_Alignof(struct c_size) == 1, "record c_size wrong alignment");
#endif
_Static_assert(sizeof(C) == 1, "record C wrong sizeof");
_Static_assert(_Alignof(C) == 1, "record C wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 2, "record C_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_alignment) == 1, "record C_alignment wrong alignment");
_Static_assert(sizeof(struct C_packed) == 1, "record C_packed wrong sizeof");
_Static_assert(_Alignof(struct C_packed) == 1, "record C_packed wrong alignment");
_Static_assert(sizeof(struct C_required_alignment) == 2, "record C_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "record C_required_alignment wrong alignment");
_Static_assert(sizeof(struct C_size) == 3, "record C_size wrong sizeof");
_Static_assert(_Alignof(struct C_size) == 1, "record C_size wrong alignment");
#endif
_Static_assert(sizeof(d) == 8, "record d wrong sizeof");
_Static_assert(_Alignof(d) == 4, "record d wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct d_alignment) == 12, "record d_alignment wrong sizeof");
_Static_assert(_Alignof(struct d_alignment) == 4, "record d_alignment wrong alignment");
_Static_assert(sizeof(struct d_packed) == 8, "record d_packed wrong sizeof");
_Static_assert(_Alignof(struct d_packed) == 1, "record d_packed wrong alignment");
_Static_assert(sizeof(struct d_required_alignment) == 9, "record d_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct d_required_alignment) == 1, "record d_required_alignment wrong alignment");
_Static_assert(sizeof(struct d_size) == 10, "record d_size wrong sizeof");
_Static_assert(_Alignof(struct d_size) == 1, "record d_size wrong alignment");
#endif
_Static_assert(sizeof(D) == 1, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 1, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 2, "record D_alignment wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 1, "record D_alignment wrong alignment");
_Static_assert(sizeof(struct D_packed) == 1, "record D_packed wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D_packed wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 2, "record D_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D_required_alignment wrong alignment");
_Static_assert(sizeof(struct D_size) == 3, "record D_size wrong sizeof");
_Static_assert(_Alignof(struct D_size) == 1, "record D_size wrong alignment");
#endif
_Static_assert(sizeof(e) == 4, "record e wrong sizeof");
_Static_assert(_Alignof(e) == 2, "record e wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct e_alignment) == 6, "record e_alignment wrong sizeof");
_Static_assert(_Alignof(struct e_alignment) == 2, "record e_alignment wrong alignment");
_Static_assert(sizeof(struct e_packed) == 4, "record e_packed wrong sizeof");
_Static_assert(_Alignof(struct e_packed) == 1, "record e_packed wrong alignment");
_Static_assert(sizeof(struct e_required_alignment) == 5, "record e_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct e_required_alignment) == 1, "record e_required_alignment wrong alignment");
_Static_assert(sizeof(struct e_size) == 6, "record e_size wrong sizeof");
_Static_assert(_Alignof(struct e_size) == 1, "record e_size wrong alignment");
#endif
_Static_assert(sizeof(E) == 1, "record E wrong sizeof");
_Static_assert(_Alignof(E) == 1, "record E wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 2, "record E_alignment wrong sizeof");
_Static_assert(_Alignof(struct E_alignment) == 1, "record E_alignment wrong alignment");
_Static_assert(sizeof(struct E_packed) == 1, "record E_packed wrong sizeof");
_Static_assert(_Alignof(struct E_packed) == 1, "record E_packed wrong alignment");
_Static_assert(sizeof(struct E_required_alignment) == 2, "record E_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "record E_required_alignment wrong alignment");
_Static_assert(sizeof(struct E_size) == 3, "record E_size wrong sizeof");
_Static_assert(_Alignof(struct E_size) == 1, "record E_size wrong alignment");
#endif
_Static_assert(sizeof(f) == 8, "record f wrong sizeof");
_Static_assert(_Alignof(f) == 2, "record f wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct f_alignment) == 10, "record f_alignment wrong sizeof");
_Static_assert(_Alignof(struct f_alignment) == 2, "record f_alignment wrong alignment");
_Static_assert(sizeof(struct f_packed) == 8, "record f_packed wrong sizeof");
_Static_assert(_Alignof(struct f_packed) == 1, "record f_packed wrong alignment");
_Static_assert(sizeof(struct f_required_alignment) == 9, "record f_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct f_required_alignment) == 1, "record f_required_alignment wrong alignment");
_Static_assert(sizeof(struct f_size) == 10, "record f_size wrong sizeof");
_Static_assert(_Alignof(struct f_size) == 1, "record f_size wrong alignment");
#endif
_Static_assert(sizeof(F) == 1, "record F wrong sizeof");
_Static_assert(_Alignof(F) == 1, "record F wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 2, "record F_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_alignment) == 1, "record F_alignment wrong alignment");
_Static_assert(sizeof(struct F_packed) == 1, "record F_packed wrong sizeof");
_Static_assert(_Alignof(struct F_packed) == 1, "record F_packed wrong alignment");
_Static_assert(sizeof(struct F_required_alignment) == 2, "record F_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "record F_required_alignment wrong alignment");
_Static_assert(sizeof(struct F_size) == 3, "record F_size wrong sizeof");
_Static_assert(_Alignof(struct F_size) == 1, "record F_size wrong alignment");
#endif
#elif defined(AVR_UNKNOWN_UNKNOWN) 
_Static_assert(sizeof(a) == 2, "record a wrong sizeof");
_Static_assert(_Alignof(a) == 8, "record a wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct a_alignment) == 16, "record a_alignment wrong sizeof");
_Static_assert(_Alignof(struct a_alignment) == 8, "record a_alignment wrong alignment");
_Static_assert(sizeof(struct a_packed) == 2, "record a_packed wrong sizeof");
_Static_assert(_Alignof(struct a_packed) == 1, "record a_packed wrong alignment");
_Static_assert(sizeof(struct a_required_alignment) == 3, "record a_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct a_required_alignment) == 1, "record a_required_alignment wrong alignment");
_Static_assert(sizeof(struct a_size) == 4, "record a_size wrong sizeof");
_Static_assert(_Alignof(struct a_size) == 1, "record a_size wrong alignment");
#endif
_Static_assert(sizeof(A) == 1, "record A wrong sizeof");
_Static_assert(_Alignof(A) == 1, "record A wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 2, "record A_alignment wrong sizeof");
_Static_assert(_Alignof(struct A_alignment) == 1, "record A_alignment wrong alignment");
_Static_assert(sizeof(struct A_packed) == 1, "record A_packed wrong sizeof");
_Static_assert(_Alignof(struct A_packed) == 1, "record A_packed wrong alignment");
_Static_assert(sizeof(struct A_required_alignment) == 2, "record A_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "record A_required_alignment wrong alignment");
_Static_assert(sizeof(struct A_size) == 3, "record A_size wrong sizeof");
_Static_assert(_Alignof(struct A_size) == 1, "record A_size wrong alignment");
#endif
_Static_assert(sizeof(b) == 2, "record b wrong sizeof");
_Static_assert(_Alignof(b) == 4, "record b wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct b_alignment) == 8, "record b_alignment wrong sizeof");
_Static_assert(_Alignof(struct b_alignment) == 4, "record b_alignment wrong alignment");
_Static_assert(sizeof(struct b_packed) == 2, "record b_packed wrong sizeof");
_Static_assert(_Alignof(struct b_packed) == 1, "record b_packed wrong alignment");
_Static_assert(sizeof(struct b_required_alignment) == 3, "record b_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct b_required_alignment) == 1, "record b_required_alignment wrong alignment");
_Static_assert(sizeof(struct b_size) == 4, "record b_size wrong sizeof");
_Static_assert(_Alignof(struct b_size) == 1, "record b_size wrong alignment");
#endif
_Static_assert(sizeof(B) == 1, "record B wrong sizeof");
_Static_assert(_Alignof(B) == 1, "record B wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 2, "record B_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_alignment) == 1, "record B_alignment wrong alignment");
_Static_assert(sizeof(struct B_packed) == 1, "record B_packed wrong sizeof");
_Static_assert(_Alignof(struct B_packed) == 1, "record B_packed wrong alignment");
_Static_assert(sizeof(struct B_required_alignment) == 2, "record B_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "record B_required_alignment wrong alignment");
_Static_assert(sizeof(struct B_size) == 3, "record B_size wrong sizeof");
_Static_assert(_Alignof(struct B_size) == 1, "record B_size wrong alignment");
#endif
_Static_assert(sizeof(c) == 2, "record c wrong sizeof");
_Static_assert(_Alignof(c) == 8, "record c wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct c_alignment) == 16, "record c_alignment wrong sizeof");
_Static_assert(_Alignof(struct c_alignment) == 8, "record c_alignment wrong alignment");
_Static_assert(sizeof(struct c_packed) == 2, "record c_packed wrong sizeof");
_Static_assert(_Alignof(struct c_packed) == 1, "record c_packed wrong alignment");
_Static_assert(sizeof(struct c_required_alignment) == 3, "record c_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct c_required_alignment) == 1, "record c_required_alignment wrong alignment");
_Static_assert(sizeof(struct c_size) == 4, "record c_size wrong sizeof");
_Static_assert(_Alignof(struct c_size) == 1, "record c_size wrong alignment");
#endif
_Static_assert(sizeof(C) == 1, "record C wrong sizeof");
_Static_assert(_Alignof(C) == 1, "record C wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 2, "record C_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_alignment) == 1, "record C_alignment wrong alignment");
_Static_assert(sizeof(struct C_packed) == 1, "record C_packed wrong sizeof");
_Static_assert(_Alignof(struct C_packed) == 1, "record C_packed wrong alignment");
_Static_assert(sizeof(struct C_required_alignment) == 2, "record C_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "record C_required_alignment wrong alignment");
_Static_assert(sizeof(struct C_size) == 3, "record C_size wrong sizeof");
_Static_assert(_Alignof(struct C_size) == 1, "record C_size wrong alignment");
#endif
_Static_assert(sizeof(d) == 8, "record d wrong sizeof");
_Static_assert(_Alignof(d) == 4, "record d wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct d_alignment) == 12, "record d_alignment wrong sizeof");
_Static_assert(_Alignof(struct d_alignment) == 4, "record d_alignment wrong alignment");
_Static_assert(sizeof(struct d_packed) == 8, "record d_packed wrong sizeof");
_Static_assert(_Alignof(struct d_packed) == 1, "record d_packed wrong alignment");
_Static_assert(sizeof(struct d_required_alignment) == 9, "record d_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct d_required_alignment) == 1, "record d_required_alignment wrong alignment");
_Static_assert(sizeof(struct d_size) == 10, "record d_size wrong sizeof");
_Static_assert(_Alignof(struct d_size) == 1, "record d_size wrong alignment");
#endif
_Static_assert(sizeof(D) == 1, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 1, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 2, "record D_alignment wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 1, "record D_alignment wrong alignment");
_Static_assert(sizeof(struct D_packed) == 1, "record D_packed wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D_packed wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 2, "record D_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D_required_alignment wrong alignment");
_Static_assert(sizeof(struct D_size) == 3, "record D_size wrong sizeof");
_Static_assert(_Alignof(struct D_size) == 1, "record D_size wrong alignment");
#endif
_Static_assert(sizeof(e) == 2, "record e wrong sizeof");
_Static_assert(_Alignof(e) == 2, "record e wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct e_alignment) == 4, "record e_alignment wrong sizeof");
_Static_assert(_Alignof(struct e_alignment) == 2, "record e_alignment wrong alignment");
_Static_assert(sizeof(struct e_packed) == 2, "record e_packed wrong sizeof");
_Static_assert(_Alignof(struct e_packed) == 1, "record e_packed wrong alignment");
_Static_assert(sizeof(struct e_required_alignment) == 3, "record e_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct e_required_alignment) == 1, "record e_required_alignment wrong alignment");
_Static_assert(sizeof(struct e_size) == 4, "record e_size wrong sizeof");
_Static_assert(_Alignof(struct e_size) == 1, "record e_size wrong alignment");
#endif
_Static_assert(sizeof(E) == 1, "record E wrong sizeof");
_Static_assert(_Alignof(E) == 1, "record E wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 2, "record E_alignment wrong sizeof");
_Static_assert(_Alignof(struct E_alignment) == 1, "record E_alignment wrong alignment");
_Static_assert(sizeof(struct E_packed) == 1, "record E_packed wrong sizeof");
_Static_assert(_Alignof(struct E_packed) == 1, "record E_packed wrong alignment");
_Static_assert(sizeof(struct E_required_alignment) == 2, "record E_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "record E_required_alignment wrong alignment");
_Static_assert(sizeof(struct E_size) == 3, "record E_size wrong sizeof");
_Static_assert(_Alignof(struct E_size) == 1, "record E_size wrong alignment");
#endif
_Static_assert(sizeof(f) == 8, "record f wrong sizeof");
_Static_assert(_Alignof(f) == 2, "record f wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct f_alignment) == 10, "record f_alignment wrong sizeof");
_Static_assert(_Alignof(struct f_alignment) == 2, "record f_alignment wrong alignment");
_Static_assert(sizeof(struct f_packed) == 8, "record f_packed wrong sizeof");
_Static_assert(_Alignof(struct f_packed) == 1, "record f_packed wrong alignment");
_Static_assert(sizeof(struct f_required_alignment) == 9, "record f_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct f_required_alignment) == 1, "record f_required_alignment wrong alignment");
_Static_assert(sizeof(struct f_size) == 10, "record f_size wrong sizeof");
_Static_assert(_Alignof(struct f_size) == 1, "record f_size wrong alignment");
#endif
_Static_assert(sizeof(F) == 1, "record F wrong sizeof");
_Static_assert(_Alignof(F) == 1, "record F wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 2, "record F_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_alignment) == 1, "record F_alignment wrong alignment");
_Static_assert(sizeof(struct F_packed) == 1, "record F_packed wrong sizeof");
_Static_assert(_Alignof(struct F_packed) == 1, "record F_packed wrong alignment");
_Static_assert(sizeof(struct F_required_alignment) == 2, "record F_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "record F_required_alignment wrong alignment");
_Static_assert(sizeof(struct F_size) == 3, "record F_size wrong sizeof");
_Static_assert(_Alignof(struct F_size) == 1, "record F_size wrong alignment");
#endif
#elif defined(I386_APPLE_IOS) ||  defined(I586_UNKNOWN_LINUX_GNU) ||  defined(I586_UNKNOWN_LINUX_MUSL) ||  defined(I686_APPLE_MACOSX) ||  \
 defined(I686_LINUX_ANDROID) ||  defined(I686_UNKNOWN_FREEBSD) ||  defined(I686_UNKNOWN_HAIKU) ||  defined(I686_UNKNOWN_LINUX_GNU) ||  \
 defined(I686_UNKNOWN_LINUX_MUSL) ||  defined(I686_UNKNOWN_NETBSDELF) ||  defined(I686_UNKNOWN_OPENBSD) 
_Static_assert(sizeof(a) == 2, "record a wrong sizeof");
_Static_assert(_Alignof(a) == 8, "record a wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct a_alignment) == 16, "record a_alignment wrong sizeof");
_Static_assert(_Alignof(struct a_alignment) == 8, "record a_alignment wrong alignment");
_Static_assert(sizeof(struct a_packed) == 2, "record a_packed wrong sizeof");
_Static_assert(_Alignof(struct a_packed) == 1, "record a_packed wrong alignment");
_Static_assert(sizeof(struct a_required_alignment) == 3, "record a_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct a_required_alignment) == 1, "record a_required_alignment wrong alignment");
_Static_assert(sizeof(struct a_size) == 4, "record a_size wrong sizeof");
_Static_assert(_Alignof(struct a_size) == 1, "record a_size wrong alignment");
#endif
_Static_assert(sizeof(A) == 4, "record A wrong sizeof");
_Static_assert(_Alignof(A) == 4, "record A wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 8, "record A_alignment wrong sizeof");
_Static_assert(_Alignof(struct A_alignment) == 4, "record A_alignment wrong alignment");
_Static_assert(sizeof(struct A_packed) == 4, "record A_packed wrong sizeof");
_Static_assert(_Alignof(struct A_packed) == 1, "record A_packed wrong alignment");
_Static_assert(sizeof(struct A_required_alignment) == 5, "record A_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "record A_required_alignment wrong alignment");
_Static_assert(sizeof(struct A_size) == 6, "record A_size wrong sizeof");
_Static_assert(_Alignof(struct A_size) == 1, "record A_size wrong alignment");
#endif
_Static_assert(sizeof(b) == 2, "record b wrong sizeof");
_Static_assert(_Alignof(b) == 4, "record b wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct b_alignment) == 8, "record b_alignment wrong sizeof");
_Static_assert(_Alignof(struct b_alignment) == 4, "record b_alignment wrong alignment");
_Static_assert(sizeof(struct b_packed) == 2, "record b_packed wrong sizeof");
_Static_assert(_Alignof(struct b_packed) == 1, "record b_packed wrong alignment");
_Static_assert(sizeof(struct b_required_alignment) == 3, "record b_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct b_required_alignment) == 1, "record b_required_alignment wrong alignment");
_Static_assert(sizeof(struct b_size) == 4, "record b_size wrong sizeof");
_Static_assert(_Alignof(struct b_size) == 1, "record b_size wrong alignment");
#endif
_Static_assert(sizeof(B) == 4, "record B wrong sizeof");
_Static_assert(_Alignof(B) == 4, "record B wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 8, "record B_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_alignment) == 4, "record B_alignment wrong alignment");
_Static_assert(sizeof(struct B_packed) == 4, "record B_packed wrong sizeof");
_Static_assert(_Alignof(struct B_packed) == 1, "record B_packed wrong alignment");
_Static_assert(sizeof(struct B_required_alignment) == 5, "record B_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "record B_required_alignment wrong alignment");
_Static_assert(sizeof(struct B_size) == 6, "record B_size wrong sizeof");
_Static_assert(_Alignof(struct B_size) == 1, "record B_size wrong alignment");
#endif
_Static_assert(sizeof(c) == 4, "record c wrong sizeof");
_Static_assert(_Alignof(c) == 8, "record c wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct c_alignment) == 16, "record c_alignment wrong sizeof");
_Static_assert(_Alignof(struct c_alignment) == 8, "record c_alignment wrong alignment");
_Static_assert(sizeof(struct c_packed) == 4, "record c_packed wrong sizeof");
_Static_assert(_Alignof(struct c_packed) == 1, "record c_packed wrong alignment");
_Static_assert(sizeof(struct c_required_alignment) == 5, "record c_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct c_required_alignment) == 1, "record c_required_alignment wrong alignment");
_Static_assert(sizeof(struct c_size) == 6, "record c_size wrong sizeof");
_Static_assert(_Alignof(struct c_size) == 1, "record c_size wrong alignment");
#endif
_Static_assert(sizeof(C) == 2, "record C wrong sizeof");
_Static_assert(_Alignof(C) == 2, "record C wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 4, "record C_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_alignment) == 2, "record C_alignment wrong alignment");
_Static_assert(sizeof(struct C_packed) == 2, "record C_packed wrong sizeof");
_Static_assert(_Alignof(struct C_packed) == 1, "record C_packed wrong alignment");
_Static_assert(sizeof(struct C_required_alignment) == 3, "record C_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "record C_required_alignment wrong alignment");
_Static_assert(sizeof(struct C_size) == 4, "record C_size wrong sizeof");
_Static_assert(_Alignof(struct C_size) == 1, "record C_size wrong alignment");
#endif
_Static_assert(sizeof(d) == 8, "record d wrong sizeof");
_Static_assert(_Alignof(d) == 4, "record d wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct d_alignment) == 12, "record d_alignment wrong sizeof");
_Static_assert(_Alignof(struct d_alignment) == 4, "record d_alignment wrong alignment");
_Static_assert(sizeof(struct d_packed) == 8, "record d_packed wrong sizeof");
_Static_assert(_Alignof(struct d_packed) == 1, "record d_packed wrong alignment");
_Static_assert(sizeof(struct d_required_alignment) == 9, "record d_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct d_required_alignment) == 1, "record d_required_alignment wrong alignment");
_Static_assert(sizeof(struct d_size) == 10, "record d_size wrong sizeof");
_Static_assert(_Alignof(struct d_size) == 1, "record d_size wrong alignment");
#endif
_Static_assert(sizeof(D) == 2, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 2, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 4, "record D_alignment wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 2, "record D_alignment wrong alignment");
_Static_assert(sizeof(struct D_packed) == 2, "record D_packed wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D_packed wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 3, "record D_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D_required_alignment wrong alignment");
_Static_assert(sizeof(struct D_size) == 4, "record D_size wrong sizeof");
_Static_assert(_Alignof(struct D_size) == 1, "record D_size wrong alignment");
#endif
_Static_assert(sizeof(e) == 4, "record e wrong sizeof");
_Static_assert(_Alignof(e) == 2, "record e wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct e_alignment) == 6, "record e_alignment wrong sizeof");
_Static_assert(_Alignof(struct e_alignment) == 2, "record e_alignment wrong alignment");
_Static_assert(sizeof(struct e_packed) == 4, "record e_packed wrong sizeof");
_Static_assert(_Alignof(struct e_packed) == 1, "record e_packed wrong alignment");
_Static_assert(sizeof(struct e_required_alignment) == 5, "record e_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct e_required_alignment) == 1, "record e_required_alignment wrong alignment");
_Static_assert(sizeof(struct e_size) == 6, "record e_size wrong sizeof");
_Static_assert(_Alignof(struct e_size) == 1, "record e_size wrong alignment");
#endif
_Static_assert(sizeof(E) == 2, "record E wrong sizeof");
_Static_assert(_Alignof(E) == 2, "record E wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 4, "record E_alignment wrong sizeof");
_Static_assert(_Alignof(struct E_alignment) == 2, "record E_alignment wrong alignment");
_Static_assert(sizeof(struct E_packed) == 2, "record E_packed wrong sizeof");
_Static_assert(_Alignof(struct E_packed) == 1, "record E_packed wrong alignment");
_Static_assert(sizeof(struct E_required_alignment) == 3, "record E_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "record E_required_alignment wrong alignment");
_Static_assert(sizeof(struct E_size) == 4, "record E_size wrong sizeof");
_Static_assert(_Alignof(struct E_size) == 1, "record E_size wrong alignment");
#endif
_Static_assert(sizeof(f) == 8, "record f wrong sizeof");
_Static_assert(_Alignof(f) == 2, "record f wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct f_alignment) == 10, "record f_alignment wrong sizeof");
_Static_assert(_Alignof(struct f_alignment) == 2, "record f_alignment wrong alignment");
_Static_assert(sizeof(struct f_packed) == 8, "record f_packed wrong sizeof");
_Static_assert(_Alignof(struct f_packed) == 1, "record f_packed wrong alignment");
_Static_assert(sizeof(struct f_required_alignment) == 9, "record f_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct f_required_alignment) == 1, "record f_required_alignment wrong alignment");
_Static_assert(sizeof(struct f_size) == 10, "record f_size wrong sizeof");
_Static_assert(_Alignof(struct f_size) == 1, "record f_size wrong alignment");
#endif
_Static_assert(sizeof(F) == 2, "record F wrong sizeof");
_Static_assert(_Alignof(F) == 2, "record F wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 4, "record F_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_alignment) == 2, "record F_alignment wrong alignment");
_Static_assert(sizeof(struct F_packed) == 2, "record F_packed wrong sizeof");
_Static_assert(_Alignof(struct F_packed) == 1, "record F_packed wrong alignment");
_Static_assert(sizeof(struct F_required_alignment) == 3, "record F_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "record F_required_alignment wrong alignment");
_Static_assert(sizeof(struct F_size) == 4, "record F_size wrong sizeof");
_Static_assert(_Alignof(struct F_size) == 1, "record F_size wrong alignment");
#endif
#elif defined(I686_PC_WINDOWS_GNU) ||  defined(X8664_PC_WINDOWS_GNU) 
_Static_assert(sizeof(a) == 2, "record a wrong sizeof");
_Static_assert(_Alignof(a) == 8, "record a wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct a_alignment) == 16, "record a_alignment wrong sizeof");
_Static_assert(_Alignof(struct a_alignment) == 8, "record a_alignment wrong alignment");
_Static_assert(sizeof(struct a_packed) == 2, "record a_packed wrong sizeof");
_Static_assert(_Alignof(struct a_packed) == 1, "record a_packed wrong alignment");
_Static_assert(sizeof(struct a_required_alignment) == 3, "record a_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct a_required_alignment) == 1, "record a_required_alignment wrong alignment");
_Static_assert(sizeof(struct a_size) == 4, "record a_size wrong sizeof");
_Static_assert(_Alignof(struct a_size) == 1, "record a_size wrong alignment");
#endif
_Static_assert(sizeof(A) == 4, "record A wrong sizeof");
_Static_assert(_Alignof(A) == 4, "record A wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 8, "record A_alignment wrong sizeof");
_Static_assert(_Alignof(struct A_alignment) == 4, "record A_alignment wrong alignment");
_Static_assert(sizeof(struct A_packed) == 4, "record A_packed wrong sizeof");
_Static_assert(_Alignof(struct A_packed) == 1, "record A_packed wrong alignment");
_Static_assert(sizeof(struct A_required_alignment) == 5, "record A_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "record A_required_alignment wrong alignment");
_Static_assert(sizeof(struct A_size) == 6, "record A_size wrong sizeof");
_Static_assert(_Alignof(struct A_size) == 1, "record A_size wrong alignment");
#endif
_Static_assert(sizeof(b) == 2, "record b wrong sizeof");
_Static_assert(_Alignof(b) == 4, "record b wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct b_alignment) == 8, "record b_alignment wrong sizeof");
_Static_assert(_Alignof(struct b_alignment) == 4, "record b_alignment wrong alignment");
_Static_assert(sizeof(struct b_packed) == 2, "record b_packed wrong sizeof");
_Static_assert(_Alignof(struct b_packed) == 1, "record b_packed wrong alignment");
_Static_assert(sizeof(struct b_required_alignment) == 3, "record b_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct b_required_alignment) == 1, "record b_required_alignment wrong alignment");
_Static_assert(sizeof(struct b_size) == 4, "record b_size wrong sizeof");
_Static_assert(_Alignof(struct b_size) == 1, "record b_size wrong alignment");
#endif
_Static_assert(sizeof(B) == 4, "record B wrong sizeof");
_Static_assert(_Alignof(B) == 4, "record B wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 8, "record B_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_alignment) == 4, "record B_alignment wrong alignment");
_Static_assert(sizeof(struct B_packed) == 4, "record B_packed wrong sizeof");
_Static_assert(_Alignof(struct B_packed) == 1, "record B_packed wrong alignment");
_Static_assert(sizeof(struct B_required_alignment) == 5, "record B_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "record B_required_alignment wrong alignment");
_Static_assert(sizeof(struct B_size) == 6, "record B_size wrong sizeof");
_Static_assert(_Alignof(struct B_size) == 1, "record B_size wrong alignment");
#endif
_Static_assert(sizeof(c) == 4, "record c wrong sizeof");
_Static_assert(_Alignof(c) == 8, "record c wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct c_alignment) == 16, "record c_alignment wrong sizeof");
_Static_assert(_Alignof(struct c_alignment) == 8, "record c_alignment wrong alignment");
_Static_assert(sizeof(struct c_packed) == 4, "record c_packed wrong sizeof");
_Static_assert(_Alignof(struct c_packed) == 1, "record c_packed wrong alignment");
_Static_assert(sizeof(struct c_required_alignment) == 5, "record c_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct c_required_alignment) == 1, "record c_required_alignment wrong alignment");
_Static_assert(sizeof(struct c_size) == 6, "record c_size wrong sizeof");
_Static_assert(_Alignof(struct c_size) == 1, "record c_size wrong alignment");
#endif
_Static_assert(sizeof(C) == 4, "record C wrong sizeof");
_Static_assert(_Alignof(C) == 2, "record C wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 6, "record C_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_alignment) == 2, "record C_alignment wrong alignment");
_Static_assert(sizeof(struct C_packed) == 4, "record C_packed wrong sizeof");
_Static_assert(_Alignof(struct C_packed) == 1, "record C_packed wrong alignment");
_Static_assert(sizeof(struct C_required_alignment) == 5, "record C_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "record C_required_alignment wrong alignment");
_Static_assert(sizeof(struct C_size) == 6, "record C_size wrong sizeof");
_Static_assert(_Alignof(struct C_size) == 1, "record C_size wrong alignment");
#endif
_Static_assert(sizeof(d) == 8, "record d wrong sizeof");
_Static_assert(_Alignof(d) == 4, "record d wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct d_alignment) == 12, "record d_alignment wrong sizeof");
_Static_assert(_Alignof(struct d_alignment) == 4, "record d_alignment wrong alignment");
_Static_assert(sizeof(struct d_packed) == 8, "record d_packed wrong sizeof");
_Static_assert(_Alignof(struct d_packed) == 1, "record d_packed wrong alignment");
_Static_assert(sizeof(struct d_required_alignment) == 9, "record d_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct d_required_alignment) == 1, "record d_required_alignment wrong alignment");
_Static_assert(sizeof(struct d_size) == 10, "record d_size wrong sizeof");
_Static_assert(_Alignof(struct d_size) == 1, "record d_size wrong alignment");
#endif
_Static_assert(sizeof(D) == 8, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 2, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 10, "record D_alignment wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 2, "record D_alignment wrong alignment");
_Static_assert(sizeof(struct D_packed) == 8, "record D_packed wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D_packed wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 9, "record D_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D_required_alignment wrong alignment");
_Static_assert(sizeof(struct D_size) == 10, "record D_size wrong sizeof");
_Static_assert(_Alignof(struct D_size) == 1, "record D_size wrong alignment");
#endif
_Static_assert(sizeof(e) == 4, "record e wrong sizeof");
_Static_assert(_Alignof(e) == 2, "record e wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct e_alignment) == 6, "record e_alignment wrong sizeof");
_Static_assert(_Alignof(struct e_alignment) == 2, "record e_alignment wrong alignment");
_Static_assert(sizeof(struct e_packed) == 4, "record e_packed wrong sizeof");
_Static_assert(_Alignof(struct e_packed) == 1, "record e_packed wrong alignment");
_Static_assert(sizeof(struct e_required_alignment) == 5, "record e_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct e_required_alignment) == 1, "record e_required_alignment wrong alignment");
_Static_assert(sizeof(struct e_size) == 6, "record e_size wrong sizeof");
_Static_assert(_Alignof(struct e_size) == 1, "record e_size wrong alignment");
#endif
_Static_assert(sizeof(E) == 4, "record E wrong sizeof");
_Static_assert(_Alignof(E) == 2, "record E wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 6, "record E_alignment wrong sizeof");
_Static_assert(_Alignof(struct E_alignment) == 2, "record E_alignment wrong alignment");
_Static_assert(sizeof(struct E_packed) == 4, "record E_packed wrong sizeof");
_Static_assert(_Alignof(struct E_packed) == 1, "record E_packed wrong alignment");
_Static_assert(sizeof(struct E_required_alignment) == 5, "record E_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "record E_required_alignment wrong alignment");
_Static_assert(sizeof(struct E_size) == 6, "record E_size wrong sizeof");
_Static_assert(_Alignof(struct E_size) == 1, "record E_size wrong alignment");
#endif
_Static_assert(sizeof(f) == 8, "record f wrong sizeof");
_Static_assert(_Alignof(f) == 2, "record f wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct f_alignment) == 10, "record f_alignment wrong sizeof");
_Static_assert(_Alignof(struct f_alignment) == 2, "record f_alignment wrong alignment");
_Static_assert(sizeof(struct f_packed) == 8, "record f_packed wrong sizeof");
_Static_assert(_Alignof(struct f_packed) == 1, "record f_packed wrong alignment");
_Static_assert(sizeof(struct f_required_alignment) == 9, "record f_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct f_required_alignment) == 1, "record f_required_alignment wrong alignment");
_Static_assert(sizeof(struct f_size) == 10, "record f_size wrong sizeof");
_Static_assert(_Alignof(struct f_size) == 1, "record f_size wrong alignment");
#endif
_Static_assert(sizeof(F) == 8, "record F wrong sizeof");
_Static_assert(_Alignof(F) == 2, "record F wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 10, "record F_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_alignment) == 2, "record F_alignment wrong alignment");
_Static_assert(sizeof(struct F_packed) == 8, "record F_packed wrong sizeof");
_Static_assert(_Alignof(struct F_packed) == 1, "record F_packed wrong alignment");
_Static_assert(sizeof(struct F_required_alignment) == 9, "record F_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "record F_required_alignment wrong alignment");
_Static_assert(sizeof(struct F_size) == 10, "record F_size wrong sizeof");
_Static_assert(_Alignof(struct F_size) == 1, "record F_size wrong alignment");
#endif
#elif defined(MSP430_NONE_ELF) 
_Static_assert(sizeof(a) == 2, "record a wrong sizeof");
_Static_assert(_Alignof(a) == 8, "record a wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct a_alignment) == 16, "record a_alignment wrong sizeof");
_Static_assert(_Alignof(struct a_alignment) == 8, "record a_alignment wrong alignment");
_Static_assert(sizeof(struct a_packed) == 2, "record a_packed wrong sizeof");
_Static_assert(_Alignof(struct a_packed) == 1, "record a_packed wrong alignment");
_Static_assert(sizeof(struct a_required_alignment) == 3, "record a_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct a_required_alignment) == 1, "record a_required_alignment wrong alignment");
_Static_assert(sizeof(struct a_size) == 4, "record a_size wrong sizeof");
_Static_assert(_Alignof(struct a_size) == 1, "record a_size wrong alignment");
#endif
_Static_assert(sizeof(A) == 4, "record A wrong sizeof");
_Static_assert(_Alignof(A) == 4, "record A wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 8, "record A_alignment wrong sizeof");
_Static_assert(_Alignof(struct A_alignment) == 4, "record A_alignment wrong alignment");
_Static_assert(sizeof(struct A_packed) == 4, "record A_packed wrong sizeof");
_Static_assert(_Alignof(struct A_packed) == 1, "record A_packed wrong alignment");
_Static_assert(sizeof(struct A_required_alignment) == 5, "record A_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "record A_required_alignment wrong alignment");
_Static_assert(sizeof(struct A_size) == 6, "record A_size wrong sizeof");
_Static_assert(_Alignof(struct A_size) == 1, "record A_size wrong alignment");
#endif
_Static_assert(sizeof(b) == 2, "record b wrong sizeof");
_Static_assert(_Alignof(b) == 4, "record b wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct b_alignment) == 8, "record b_alignment wrong sizeof");
_Static_assert(_Alignof(struct b_alignment) == 4, "record b_alignment wrong alignment");
_Static_assert(sizeof(struct b_packed) == 2, "record b_packed wrong sizeof");
_Static_assert(_Alignof(struct b_packed) == 1, "record b_packed wrong alignment");
_Static_assert(sizeof(struct b_required_alignment) == 3, "record b_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct b_required_alignment) == 1, "record b_required_alignment wrong alignment");
_Static_assert(sizeof(struct b_size) == 4, "record b_size wrong sizeof");
_Static_assert(_Alignof(struct b_size) == 1, "record b_size wrong alignment");
#endif
_Static_assert(sizeof(B) == 4, "record B wrong sizeof");
_Static_assert(_Alignof(B) == 4, "record B wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 8, "record B_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_alignment) == 4, "record B_alignment wrong alignment");
_Static_assert(sizeof(struct B_packed) == 4, "record B_packed wrong sizeof");
_Static_assert(_Alignof(struct B_packed) == 1, "record B_packed wrong alignment");
_Static_assert(sizeof(struct B_required_alignment) == 5, "record B_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "record B_required_alignment wrong alignment");
_Static_assert(sizeof(struct B_size) == 6, "record B_size wrong sizeof");
_Static_assert(_Alignof(struct B_size) == 1, "record B_size wrong alignment");
#endif
_Static_assert(sizeof(c) == 2, "record c wrong sizeof");
_Static_assert(_Alignof(c) == 8, "record c wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct c_alignment) == 16, "record c_alignment wrong sizeof");
_Static_assert(_Alignof(struct c_alignment) == 8, "record c_alignment wrong alignment");
_Static_assert(sizeof(struct c_packed) == 2, "record c_packed wrong sizeof");
_Static_assert(_Alignof(struct c_packed) == 1, "record c_packed wrong alignment");
_Static_assert(sizeof(struct c_required_alignment) == 3, "record c_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct c_required_alignment) == 1, "record c_required_alignment wrong alignment");
_Static_assert(sizeof(struct c_size) == 4, "record c_size wrong sizeof");
_Static_assert(_Alignof(struct c_size) == 1, "record c_size wrong alignment");
#endif
_Static_assert(sizeof(C) == 2, "record C wrong sizeof");
_Static_assert(_Alignof(C) == 2, "record C wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 4, "record C_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_alignment) == 2, "record C_alignment wrong alignment");
_Static_assert(sizeof(struct C_packed) == 2, "record C_packed wrong sizeof");
_Static_assert(_Alignof(struct C_packed) == 1, "record C_packed wrong alignment");
_Static_assert(sizeof(struct C_required_alignment) == 3, "record C_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "record C_required_alignment wrong alignment");
_Static_assert(sizeof(struct C_size) == 4, "record C_size wrong sizeof");
_Static_assert(_Alignof(struct C_size) == 1, "record C_size wrong alignment");
#endif
_Static_assert(sizeof(d) == 8, "record d wrong sizeof");
_Static_assert(_Alignof(d) == 4, "record d wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct d_alignment) == 12, "record d_alignment wrong sizeof");
_Static_assert(_Alignof(struct d_alignment) == 4, "record d_alignment wrong alignment");
_Static_assert(sizeof(struct d_packed) == 8, "record d_packed wrong sizeof");
_Static_assert(_Alignof(struct d_packed) == 1, "record d_packed wrong alignment");
_Static_assert(sizeof(struct d_required_alignment) == 9, "record d_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct d_required_alignment) == 1, "record d_required_alignment wrong alignment");
_Static_assert(sizeof(struct d_size) == 10, "record d_size wrong sizeof");
_Static_assert(_Alignof(struct d_size) == 1, "record d_size wrong alignment");
#endif
_Static_assert(sizeof(D) == 2, "record D wrong sizeof");
_Static_assert(_Alignof(D) == 2, "record D wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 4, "record D_alignment wrong sizeof");
_Static_assert(_Alignof(struct D_alignment) == 2, "record D_alignment wrong alignment");
_Static_assert(sizeof(struct D_packed) == 2, "record D_packed wrong sizeof");
_Static_assert(_Alignof(struct D_packed) == 1, "record D_packed wrong alignment");
_Static_assert(sizeof(struct D_required_alignment) == 3, "record D_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "record D_required_alignment wrong alignment");
_Static_assert(sizeof(struct D_size) == 4, "record D_size wrong sizeof");
_Static_assert(_Alignof(struct D_size) == 1, "record D_size wrong alignment");
#endif
_Static_assert(sizeof(e) == 2, "record e wrong sizeof");
_Static_assert(_Alignof(e) == 2, "record e wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct e_alignment) == 4, "record e_alignment wrong sizeof");
_Static_assert(_Alignof(struct e_alignment) == 2, "record e_alignment wrong alignment");
_Static_assert(sizeof(struct e_packed) == 2, "record e_packed wrong sizeof");
_Static_assert(_Alignof(struct e_packed) == 1, "record e_packed wrong alignment");
_Static_assert(sizeof(struct e_required_alignment) == 3, "record e_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct e_required_alignment) == 1, "record e_required_alignment wrong alignment");
_Static_assert(sizeof(struct e_size) == 4, "record e_size wrong sizeof");
_Static_assert(_Alignof(struct e_size) == 1, "record e_size wrong alignment");
#endif
_Static_assert(sizeof(E) == 2, "record E wrong sizeof");
_Static_assert(_Alignof(E) == 2, "record E wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 4, "record E_alignment wrong sizeof");
_Static_assert(_Alignof(struct E_alignment) == 2, "record E_alignment wrong alignment");
_Static_assert(sizeof(struct E_packed) == 2, "record E_packed wrong sizeof");
_Static_assert(_Alignof(struct E_packed) == 1, "record E_packed wrong alignment");
_Static_assert(sizeof(struct E_required_alignment) == 3, "record E_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "record E_required_alignment wrong alignment");
_Static_assert(sizeof(struct E_size) == 4, "record E_size wrong sizeof");
_Static_assert(_Alignof(struct E_size) == 1, "record E_size wrong alignment");
#endif
_Static_assert(sizeof(f) == 8, "record f wrong sizeof");
_Static_assert(_Alignof(f) == 2, "record f wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct f_alignment) == 10, "record f_alignment wrong sizeof");
_Static_assert(_Alignof(struct f_alignment) == 2, "record f_alignment wrong alignment");
_Static_assert(sizeof(struct f_packed) == 8, "record f_packed wrong sizeof");
_Static_assert(_Alignof(struct f_packed) == 1, "record f_packed wrong alignment");
_Static_assert(sizeof(struct f_required_alignment) == 9, "record f_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct f_required_alignment) == 1, "record f_required_alignment wrong alignment");
_Static_assert(sizeof(struct f_size) == 10, "record f_size wrong sizeof");
_Static_assert(_Alignof(struct f_size) == 1, "record f_size wrong alignment");
#endif
_Static_assert(sizeof(F) == 2, "record F wrong sizeof");
_Static_assert(_Alignof(F) == 2, "record F wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 4, "record F_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_alignment) == 2, "record F_alignment wrong alignment");
_Static_assert(sizeof(struct F_packed) == 2, "record F_packed wrong sizeof");
_Static_assert(_Alignof(struct F_packed) == 1, "record F_packed wrong alignment");
_Static_assert(sizeof(struct F_required_alignment) == 3, "record F_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "record F_required_alignment wrong alignment");
_Static_assert(sizeof(struct F_size) == 4, "record F_size wrong sizeof");
_Static_assert(_Alignof(struct F_size) == 1, "record F_size wrong alignment");
#endif
#endif
