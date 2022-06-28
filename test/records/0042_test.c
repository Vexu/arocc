// SPDX-License-Identifier: GPL-3.0-or-later

// This test file is auto-generated. do not edit.
// This file is a derivative work from the test files found// in this repo : https://github.com/mahkoh/repr-c
// and is under the same licence as the original work.

#ifdef MSVC
__declspec(align(16)) typedef struct {
#else
typedef struct {
#endif
    int x;
#ifdef MSVC
} AlignedStruct;
#else
} __attribute__((aligned(16))) AlignedStruct;
#endif
AlignedStruct var1;
struct AlignedStruct_alignment {
#ifdef MSVC
    char a[_Alignof(AlignedStruct)];
    char b;
#else
    char a;
    AlignedStruct b;
#endif
};
struct AlignedStruct_alignment var2;
#pragma pack(1)
struct AlignedStruct_packed {
    AlignedStruct a;
};
#pragma pack()
struct AlignedStruct_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct AlignedStruct_packed)];
    char b;
#else
    char a;
    struct AlignedStruct_packed b;
#endif
};
struct AlignedStruct_required_alignment var3;
struct AlignedStruct_size {
    char a[sizeof(AlignedStruct)+1];
    char b;
};
struct AlignedStruct_size var4;

#ifdef MSVC
__declspec(align(16)) typedef int AlignedInt;
#else
typedef int AlignedInt __attribute__((aligned(16)));
#endif
AlignedInt var5;
struct AlignedInt_alignment {
#ifdef MSVC
    char a[_Alignof(AlignedInt)];
    char b;
#else
    char a;
    AlignedInt b;
#endif
};
struct AlignedInt_alignment var6;
#pragma pack(1)
struct AlignedInt_packed {
    AlignedInt a;
};
#pragma pack()
struct AlignedInt_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct AlignedInt_packed)];
    char b;
#else
    char a;
    struct AlignedInt_packed b;
#endif
};
struct AlignedInt_required_alignment var7;
struct AlignedInt_size {
    char a[sizeof(AlignedInt)+1];
    char b;
};
struct AlignedInt_size var8;

typedef AlignedStruct unnamed_type_9[1];
unnamed_type_9 var10;
struct unnamed_type_9_alignment {
#ifdef MSVC
    char a[_Alignof(unnamed_type_9)];
    char b;
#else
    char a;
    unnamed_type_9 b;
#endif
};
struct unnamed_type_9_alignment var11;
#pragma pack(1)
struct unnamed_type_9_packed {
    unnamed_type_9 a;
};
#pragma pack()
struct unnamed_type_9_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct unnamed_type_9_packed)];
    char b;
#else
    char a;
    struct unnamed_type_9_packed b;
#endif
};
struct unnamed_type_9_required_alignment var12;
struct unnamed_type_9_size {
    char a[sizeof(unnamed_type_9)+1];
    char b;
};
struct unnamed_type_9_size var13;

#pragma pack(2)
typedef struct {
    unnamed_type_9 a;
} A;
A var14;
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
struct A_alignment var15;
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
struct A_required_alignment var16;
struct A_size {
    char a[sizeof(A)+1];
    char b;
};
struct A_size var17;

typedef AlignedInt unnamed_type_18[1];
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

#pragma pack(2)
typedef struct {
    char b;
    unnamed_type_18 a;
} B;
B var23;
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
struct B_alignment var24;
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
struct B_required_alignment var25;
struct B_size {
    char a[sizeof(B)+1];
    char b;
};
struct B_size var26;

#ifdef MSVC
typedef AlignedInt unnamed_type_27[];
#else
typedef AlignedInt unnamed_type_27[0];
#endif
unnamed_type_27 var28;
struct unnamed_type_27_alignment {
#ifdef MSVC
    char a[_Alignof(unnamed_type_27)];
    char b;
#else
    char a;
    unnamed_type_27 b;
#endif
};
struct unnamed_type_27_alignment var29;
#pragma pack(1)
struct unnamed_type_27_packed {
    unnamed_type_27 a;
};
#pragma pack()
struct unnamed_type_27_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct unnamed_type_27_packed)];
    char b;
#else
    char a;
    struct unnamed_type_27_packed b;
#endif
};
struct unnamed_type_27_required_alignment var30;
struct unnamed_type_27_size {
    char a[sizeof(unnamed_type_27)+1];
    char b;
};
struct unnamed_type_27_size var31;

#pragma pack(2)
typedef struct {
    char c;
    unnamed_type_27 a;
} C;
C var32;
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
struct C_alignment var33;
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
struct C_required_alignment var34;
struct C_size {
    char a[sizeof(C)+1];
    char b;
};
struct C_size var35;

#if defined(AARCH64_APPLE_MACOSX) ||  defined(AARCH64_FUCHSIA) ||  defined(AARCH64_LINUX_ANDROID) ||  defined(AARCH64_UNKNOWN_FREEBSD) ||  \
 defined(AARCH64_UNKNOWN_HERMIT) ||  defined(AARCH64_UNKNOWN_NETBSD) ||  defined(AARCH64_UNKNOWN_NONE) ||  defined(AARCH64_UNKNOWN_OPENBSD) ||  \
 defined(AARCH64_UNKNOWN_REDOX) ||  defined(ARM64_APPLE_IOS) ||  defined(ARM64_APPLE_IOS_MACABI) ||  defined(ARM64_APPLE_TVOS) ||  \
 defined(ARMEBV7R_UNKNOWN_NONE_EABI) ||  defined(ARMEBV7R_UNKNOWN_NONE_EABIHF) ||  defined(ARM_LINUX_ANDROIDEABI) ||  defined(ARMV6_UNKNOWN_FREEBSD_GNUEABIHF) ||  \
 defined(ARMV6_UNKNOWN_NETBSDELF_EABIHF) ||  defined(ARMV7A_NONE_EABI) ||  defined(ARMV7A_NONE_EABIHF) ||  defined(ARMV7_APPLE_IOS) ||  \
 defined(ARMV7_NONE_LINUX_ANDROID) ||  defined(ARMV7R_UNKNOWN_NONE_EABI) ||  defined(ARMV7R_UNKNOWN_NONE_EABIHF) ||  defined(ARMV7S_APPLE_IOS) ||  \
 defined(ARMV7_UNKNOWN_FREEBSD_GNUEABIHF) ||  defined(ARMV7_UNKNOWN_NETBSDELF_EABIHF) ||  defined(HEXAGON_UNKNOWN_LINUX_MUSL) ||  \
 defined(I386_APPLE_IOS) ||  defined(I686_APPLE_MACOSX) ||  defined(I686_LINUX_ANDROID) ||  defined(I686_UNKNOWN_FREEBSD) ||  defined(I686_UNKNOWN_HAIKU) ||  \
 defined(I686_UNKNOWN_NETBSDELF) ||  defined(I686_UNKNOWN_OPENBSD) ||  defined(MIPSEL_SONY_PSP) ||  defined(MIPSEL_UNKNOWN_NONE) ||  \
 defined(POWERPC64_UNKNOWN_FREEBSD) ||  defined(POWERPC_UNKNOWN_LINUX_GNUSPE) ||  defined(POWERPC_UNKNOWN_NETBSD) ||  defined(RISCV32) ||  \
 defined(RISCV64) ||  defined(SPARC64_UNKNOWN_NETBSD) ||  defined(SPARC64_UNKNOWN_OPENBSD) ||  defined(SPARCV9_SUN_SOLARIS) ||  defined(THUMBV4T_NONE_EABI) ||  \
 defined(THUMBV6M_NONE_EABI) ||  defined(THUMBV7EM_NONE_EABIHF) ||  defined(THUMBV7EM_NONE_EABI) ||  defined(THUMBV7M_NONE_EABI) ||  \
 defined(THUMBV8MBASE_NONE_EABI) ||  defined(THUMBV8MMAIN_NONE_EABIHF) ||  defined(THUMBV8MMAIN_NONE_EABI) ||  defined(WASM32_UNKNOWN_EMSCRIPTEN) ||  \
 defined(WASM32_UNKNOWN_UNKNOWN) ||  defined(WASM32_WASI) ||  defined(X8664_APPLE_IOS_MACABI) ||  defined(X8664_APPLE_IOS) ||  defined(X8664_APPLE_MACOSX) ||  \
 defined(X8664_APPLE_TVOS) ||  defined(X8664_ELF) ||  defined(X8664_FUCHSIA) ||  defined(X8664_LINUX_ANDROID) ||  defined(X8664_PC_SOLARIS) ||  \
 defined(X8664_RUMPRUN_NETBSD) ||  defined(X8664_UNKNOWN_DRAGONFLY) ||  defined(X8664_UNKNOWN_FREEBSD) ||  defined(X8664_UNKNOWN_HAIKU) ||  \
 defined(X8664_UNKNOWN_HERMIT) ||  defined(X8664_UNKNOWN_L4RE_UCLIBC) ||  defined(X8664_UNKNOWN_NETBSD) ||  defined(X8664_UNKNOWN_OPENBSD) ||  \
 defined(X8664_UNKNOWN_REDOX) 
_Static_assert(sizeof(AlignedStruct) == 16, "record AlignedStruct wrong sizeof");
_Static_assert(_Alignof(AlignedStruct) == 16, "record AlignedStruct wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct AlignedStruct_alignment) == 32, "record AlignedStruct_alignment wrong sizeof");
_Static_assert(_Alignof(struct AlignedStruct_alignment) == 16, "record AlignedStruct_alignment wrong alignment");
_Static_assert(sizeof(struct AlignedStruct_packed) == 16, "record AlignedStruct_packed wrong sizeof");
_Static_assert(_Alignof(struct AlignedStruct_packed) == 1, "record AlignedStruct_packed wrong alignment");
_Static_assert(sizeof(struct AlignedStruct_required_alignment) == 17, "record AlignedStruct_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct AlignedStruct_required_alignment) == 1, "record AlignedStruct_required_alignment wrong alignment");
_Static_assert(sizeof(struct AlignedStruct_size) == 18, "record AlignedStruct_size wrong sizeof");
_Static_assert(_Alignof(struct AlignedStruct_size) == 1, "record AlignedStruct_size wrong alignment");
#endif
_Static_assert(sizeof(AlignedInt) == 4, "record AlignedInt wrong sizeof");
_Static_assert(_Alignof(AlignedInt) == 16, "record AlignedInt wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct AlignedInt_alignment) == 32, "record AlignedInt_alignment wrong sizeof");
_Static_assert(_Alignof(struct AlignedInt_alignment) == 16, "record AlignedInt_alignment wrong alignment");
_Static_assert(sizeof(struct AlignedInt_packed) == 4, "record AlignedInt_packed wrong sizeof");
_Static_assert(_Alignof(struct AlignedInt_packed) == 1, "record AlignedInt_packed wrong alignment");
_Static_assert(sizeof(struct AlignedInt_required_alignment) == 5, "record AlignedInt_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct AlignedInt_required_alignment) == 1, "record AlignedInt_required_alignment wrong alignment");
_Static_assert(sizeof(struct AlignedInt_size) == 6, "record AlignedInt_size wrong sizeof");
_Static_assert(_Alignof(struct AlignedInt_size) == 1, "record AlignedInt_size wrong alignment");
#endif
_Static_assert(sizeof(A) == 16, "record A wrong sizeof");
_Static_assert(_Alignof(A) == 2, "record A wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 18, "record A_alignment wrong sizeof");
_Static_assert(_Alignof(struct A_alignment) == 2, "record A_alignment wrong alignment");
_Static_assert(sizeof(struct A_packed) == 16, "record A_packed wrong sizeof");
_Static_assert(_Alignof(struct A_packed) == 1, "record A_packed wrong alignment");
_Static_assert(sizeof(struct A_required_alignment) == 17, "record A_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "record A_required_alignment wrong alignment");
_Static_assert(sizeof(struct A_size) == 18, "record A_size wrong sizeof");
_Static_assert(_Alignof(struct A_size) == 1, "record A_size wrong alignment");
#endif
_Static_assert(sizeof(B) == 18, "record B wrong sizeof");
_Static_assert(_Alignof(B) == 2, "record B wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 20, "record B_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_alignment) == 2, "record B_alignment wrong alignment");
_Static_assert(sizeof(struct B_packed) == 18, "record B_packed wrong sizeof");
_Static_assert(_Alignof(struct B_packed) == 1, "record B_packed wrong alignment");
_Static_assert(sizeof(struct B_required_alignment) == 19, "record B_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "record B_required_alignment wrong alignment");
_Static_assert(sizeof(struct B_size) == 20, "record B_size wrong sizeof");
_Static_assert(_Alignof(struct B_size) == 1, "record B_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B,a) == 16, "field B.a wrong bit offset");
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
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C,a) == 16, "field C.a wrong bit offset");
#endif
#elif defined(AARCH64_PC_WINDOWS_MSVC) ||  defined(I586_PC_WINDOWS_MSVC) ||  defined(I686_PC_WINDOWS_MSVC) ||  defined(I686_UNKNOWN_WINDOWS) ||  \
 defined(THUMBV7A_PC_WINDOWS_MSVC) ||  defined(X8664_PC_WINDOWS_MSVC) ||  defined(X8664_UNKNOWN_WINDOWS) 
_Static_assert(sizeof(AlignedStruct) == 16, "record AlignedStruct wrong sizeof");
_Static_assert(_Alignof(AlignedStruct) == 16, "record AlignedStruct wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct AlignedStruct_alignment) == 32, "record AlignedStruct_alignment wrong sizeof");
_Static_assert(_Alignof(struct AlignedStruct_alignment) == 16, "record AlignedStruct_alignment wrong alignment");
_Static_assert(sizeof(struct AlignedStruct_packed) == 16, "record AlignedStruct_packed wrong sizeof");
_Static_assert(_Alignof(struct AlignedStruct_packed) == 1, "record AlignedStruct_packed wrong alignment");
_Static_assert(sizeof(struct AlignedStruct_required_alignment) == 17, "record AlignedStruct_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct AlignedStruct_required_alignment) == 1, "record AlignedStruct_required_alignment wrong alignment");
_Static_assert(sizeof(struct AlignedStruct_size) == 18, "record AlignedStruct_size wrong sizeof");
_Static_assert(_Alignof(struct AlignedStruct_size) == 1, "record AlignedStruct_size wrong alignment");
#endif
_Static_assert(sizeof(AlignedInt) == 4, "record AlignedInt wrong sizeof");
_Static_assert(_Alignof(AlignedInt) == 16, "record AlignedInt wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct AlignedInt_alignment) == 32, "record AlignedInt_alignment wrong sizeof");
_Static_assert(_Alignof(struct AlignedInt_alignment) == 16, "record AlignedInt_alignment wrong alignment");
_Static_assert(sizeof(struct AlignedInt_packed) == 4, "record AlignedInt_packed wrong sizeof");
_Static_assert(_Alignof(struct AlignedInt_packed) == 1, "record AlignedInt_packed wrong alignment");
_Static_assert(sizeof(struct AlignedInt_required_alignment) == 5, "record AlignedInt_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct AlignedInt_required_alignment) == 1, "record AlignedInt_required_alignment wrong alignment");
_Static_assert(sizeof(struct AlignedInt_size) == 6, "record AlignedInt_size wrong sizeof");
_Static_assert(_Alignof(struct AlignedInt_size) == 1, "record AlignedInt_size wrong alignment");
#endif
_Static_assert(sizeof(A) == 16, "record A wrong sizeof");
_Static_assert(_Alignof(A) == 16, "record A wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 32, "record A_alignment wrong sizeof");
_Static_assert(_Alignof(struct A_alignment) == 16, "record A_alignment wrong alignment");
_Static_assert(sizeof(struct A_packed) == 16, "record A_packed wrong sizeof");
_Static_assert(_Alignof(struct A_packed) == 1, "record A_packed wrong alignment");
_Static_assert(sizeof(struct A_required_alignment) == 17, "record A_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "record A_required_alignment wrong alignment");
_Static_assert(sizeof(struct A_size) == 18, "record A_size wrong sizeof");
_Static_assert(_Alignof(struct A_size) == 1, "record A_size wrong alignment");
#endif
_Static_assert(sizeof(B) == 32, "record B wrong sizeof");
_Static_assert(_Alignof(B) == 16, "record B wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 48, "record B_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_alignment) == 16, "record B_alignment wrong alignment");
_Static_assert(sizeof(struct B_packed) == 32, "record B_packed wrong sizeof");
_Static_assert(_Alignof(struct B_packed) == 1, "record B_packed wrong alignment");
_Static_assert(sizeof(struct B_required_alignment) == 33, "record B_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "record B_required_alignment wrong alignment");
_Static_assert(sizeof(struct B_size) == 34, "record B_size wrong sizeof");
_Static_assert(_Alignof(struct B_size) == 1, "record B_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B,a) == 128, "field B.a wrong bit offset");
#endif
_Static_assert(sizeof(C) == 16, "record C wrong sizeof");
_Static_assert(_Alignof(C) == 16, "record C wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 32, "record C_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_alignment) == 16, "record C_alignment wrong alignment");
_Static_assert(sizeof(struct C_packed) == 16, "record C_packed wrong sizeof");
_Static_assert(_Alignof(struct C_packed) == 1, "record C_packed wrong alignment");
_Static_assert(sizeof(struct C_required_alignment) == 17, "record C_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "record C_required_alignment wrong alignment");
_Static_assert(sizeof(struct C_size) == 18, "record C_size wrong sizeof");
_Static_assert(_Alignof(struct C_size) == 1, "record C_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C,a) == 128, "field C.a wrong bit offset");
#endif
#elif defined(MSP430_NONE_ELF) 
_Static_assert(sizeof(AlignedStruct) == 16, "record AlignedStruct wrong sizeof");
_Static_assert(_Alignof(AlignedStruct) == 16, "record AlignedStruct wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct AlignedStruct_alignment) == 32, "record AlignedStruct_alignment wrong sizeof");
_Static_assert(_Alignof(struct AlignedStruct_alignment) == 16, "record AlignedStruct_alignment wrong alignment");
_Static_assert(sizeof(struct AlignedStruct_packed) == 16, "record AlignedStruct_packed wrong sizeof");
_Static_assert(_Alignof(struct AlignedStruct_packed) == 1, "record AlignedStruct_packed wrong alignment");
_Static_assert(sizeof(struct AlignedStruct_required_alignment) == 17, "record AlignedStruct_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct AlignedStruct_required_alignment) == 1, "record AlignedStruct_required_alignment wrong alignment");
_Static_assert(sizeof(struct AlignedStruct_size) == 18, "record AlignedStruct_size wrong sizeof");
_Static_assert(_Alignof(struct AlignedStruct_size) == 1, "record AlignedStruct_size wrong alignment");
#endif
_Static_assert(sizeof(AlignedInt) == 2, "record AlignedInt wrong sizeof");
_Static_assert(_Alignof(AlignedInt) == 16, "record AlignedInt wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct AlignedInt_alignment) == 32, "record AlignedInt_alignment wrong sizeof");
_Static_assert(_Alignof(struct AlignedInt_alignment) == 16, "record AlignedInt_alignment wrong alignment");
_Static_assert(sizeof(struct AlignedInt_packed) == 2, "record AlignedInt_packed wrong sizeof");
_Static_assert(_Alignof(struct AlignedInt_packed) == 1, "record AlignedInt_packed wrong alignment");
_Static_assert(sizeof(struct AlignedInt_required_alignment) == 3, "record AlignedInt_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct AlignedInt_required_alignment) == 1, "record AlignedInt_required_alignment wrong alignment");
_Static_assert(sizeof(struct AlignedInt_size) == 4, "record AlignedInt_size wrong sizeof");
_Static_assert(_Alignof(struct AlignedInt_size) == 1, "record AlignedInt_size wrong alignment");
#endif
_Static_assert(sizeof(A) == 16, "record A wrong sizeof");
_Static_assert(_Alignof(A) == 2, "record A wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 18, "record A_alignment wrong sizeof");
_Static_assert(_Alignof(struct A_alignment) == 2, "record A_alignment wrong alignment");
_Static_assert(sizeof(struct A_packed) == 16, "record A_packed wrong sizeof");
_Static_assert(_Alignof(struct A_packed) == 1, "record A_packed wrong alignment");
_Static_assert(sizeof(struct A_required_alignment) == 17, "record A_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "record A_required_alignment wrong alignment");
_Static_assert(sizeof(struct A_size) == 18, "record A_size wrong sizeof");
_Static_assert(_Alignof(struct A_size) == 1, "record A_size wrong alignment");
#endif
_Static_assert(sizeof(B) == 18, "record B wrong sizeof");
_Static_assert(_Alignof(B) == 2, "record B wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 20, "record B_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_alignment) == 2, "record B_alignment wrong alignment");
_Static_assert(sizeof(struct B_packed) == 18, "record B_packed wrong sizeof");
_Static_assert(_Alignof(struct B_packed) == 1, "record B_packed wrong alignment");
_Static_assert(sizeof(struct B_required_alignment) == 19, "record B_required_alignment wrong sizeof");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "record B_required_alignment wrong alignment");
_Static_assert(sizeof(struct B_size) == 20, "record B_size wrong sizeof");
_Static_assert(_Alignof(struct B_size) == 1, "record B_size wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B,a) == 16, "field B.a wrong bit offset");
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
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C,a) == 16, "field C.a wrong bit offset");
#endif
#endif
