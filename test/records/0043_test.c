// SPDX-License-Identifier: GPL-3.0-or-later

// This test file is auto-generated. do not edit.
// This file is a derivative work from the test files found// in this repo : https://github.com/mahkoh/repr-c
// and is under the same licence as the original work.

#ifdef MSVC
typedef int unnamed_type_1[];
#else
typedef int unnamed_type_1[0];
#endif
unnamed_type_1 var2;
struct unnamed_type_1_alignment {
#ifdef MSVC
    char a[_Alignof(unnamed_type_1)];
    char b;
#else
    char a;
    unnamed_type_1 b;
#endif
};
struct unnamed_type_1_alignment var3;
#pragma pack(1)
struct unnamed_type_1_packed {
    unnamed_type_1 a;
};
#pragma pack()
struct unnamed_type_1_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct unnamed_type_1_packed)];
    char b;
#else
    char a;
    struct unnamed_type_1_packed b;
#endif
};
struct unnamed_type_1_required_alignment var4;
struct unnamed_type_1_size {
    char a[sizeof(unnamed_type_1)+1];
    char b;
};
struct unnamed_type_1_size var5;

typedef struct {
    unnamed_type_1 FlexArrayMemb;
} EmptyIntMemb;
EmptyIntMemb var6;
struct EmptyIntMemb_alignment {
#ifdef MSVC
    char a[_Alignof(EmptyIntMemb)];
    char b;
#else
    char a;
    EmptyIntMemb b;
#endif
};
struct EmptyIntMemb_alignment var7;
#pragma pack(1)
struct EmptyIntMemb_packed {
    EmptyIntMemb a;
};
#pragma pack()
struct EmptyIntMemb_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct EmptyIntMemb_packed)];
    char b;
#else
    char a;
    struct EmptyIntMemb_packed b;
#endif
};
struct EmptyIntMemb_required_alignment var8;
struct EmptyIntMemb_size {
    char a[sizeof(EmptyIntMemb)+1];
    char b;
};
struct EmptyIntMemb_size var9;

#ifdef MSVC
typedef long long unnamed_type_10[];
#else
typedef long long unnamed_type_10[0];
#endif
unnamed_type_10 var11;
struct unnamed_type_10_alignment {
#ifdef MSVC
    char a[_Alignof(unnamed_type_10)];
    char b;
#else
    char a;
    unnamed_type_10 b;
#endif
};
struct unnamed_type_10_alignment var12;
#pragma pack(1)
struct unnamed_type_10_packed {
    unnamed_type_10 a;
};
#pragma pack()
struct unnamed_type_10_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct unnamed_type_10_packed)];
    char b;
#else
    char a;
    struct unnamed_type_10_packed b;
#endif
};
struct unnamed_type_10_required_alignment var13;
struct unnamed_type_10_size {
    char a[sizeof(unnamed_type_10)+1];
    char b;
};
struct unnamed_type_10_size var14;

typedef struct {
    unnamed_type_10 FlexArrayMemb;
} EmptyLongLongMemb;
EmptyLongLongMemb var15;
struct EmptyLongLongMemb_alignment {
#ifdef MSVC
    char a[_Alignof(EmptyLongLongMemb)];
    char b;
#else
    char a;
    EmptyLongLongMemb b;
#endif
};
struct EmptyLongLongMemb_alignment var16;
#pragma pack(1)
struct EmptyLongLongMemb_packed {
    EmptyLongLongMemb a;
};
#pragma pack()
struct EmptyLongLongMemb_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct EmptyLongLongMemb_packed)];
    char b;
#else
    char a;
    struct EmptyLongLongMemb_packed b;
#endif
};
struct EmptyLongLongMemb_required_alignment var17;
struct EmptyLongLongMemb_size {
    char a[sizeof(EmptyLongLongMemb)+1];
    char b;
};
struct EmptyLongLongMemb_size var18;

#ifdef MSVC
typedef long long unnamed_type_19[];
#else
typedef long long unnamed_type_19[0];
#endif
unnamed_type_19 var20;
struct unnamed_type_19_alignment {
#ifdef MSVC
    char a[_Alignof(unnamed_type_19)];
    char b;
#else
    char a;
    unnamed_type_19 b;
#endif
};
struct unnamed_type_19_alignment var21;
#pragma pack(1)
struct unnamed_type_19_packed {
    unnamed_type_19 a;
};
#pragma pack()
struct unnamed_type_19_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct unnamed_type_19_packed)];
    char b;
#else
    char a;
    struct unnamed_type_19_packed b;
#endif
};
struct unnamed_type_19_required_alignment var22;
struct unnamed_type_19_size {
    char a[sizeof(unnamed_type_19)+1];
    char b;
};
struct unnamed_type_19_size var23;

typedef struct {
#ifdef MSVC
    __declspec(align(2)) unnamed_type_19 FlexArrayMemb;
#else
    unnamed_type_19 FlexArrayMemb __attribute__((aligned(2)));
#endif
} EmptyAligned2LongLongMemb;
EmptyAligned2LongLongMemb var24;
struct EmptyAligned2LongLongMemb_alignment {
#ifdef MSVC
    char a[_Alignof(EmptyAligned2LongLongMemb)];
    char b;
#else
    char a;
    EmptyAligned2LongLongMemb b;
#endif
};
struct EmptyAligned2LongLongMemb_alignment var25;
#pragma pack(1)
struct EmptyAligned2LongLongMemb_packed {
    EmptyAligned2LongLongMemb a;
};
#pragma pack()
struct EmptyAligned2LongLongMemb_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct EmptyAligned2LongLongMemb_packed)];
    char b;
#else
    char a;
    struct EmptyAligned2LongLongMemb_packed b;
#endif
};
struct EmptyAligned2LongLongMemb_required_alignment var26;
struct EmptyAligned2LongLongMemb_size {
    char a[sizeof(EmptyAligned2LongLongMemb)+1];
    char b;
};
struct EmptyAligned2LongLongMemb_size var27;

#ifdef MSVC
typedef long long unnamed_type_28[];
#else
typedef long long unnamed_type_28[0];
#endif
unnamed_type_28 var29;
struct unnamed_type_28_alignment {
#ifdef MSVC
    char a[_Alignof(unnamed_type_28)];
    char b;
#else
    char a;
    unnamed_type_28 b;
#endif
};
struct unnamed_type_28_alignment var30;
#pragma pack(1)
struct unnamed_type_28_packed {
    unnamed_type_28 a;
};
#pragma pack()
struct unnamed_type_28_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct unnamed_type_28_packed)];
    char b;
#else
    char a;
    struct unnamed_type_28_packed b;
#endif
};
struct unnamed_type_28_required_alignment var31;
struct unnamed_type_28_size {
    char a[sizeof(unnamed_type_28)+1];
    char b;
};
struct unnamed_type_28_size var32;

typedef struct {
#ifdef MSVC
    __declspec(align(8)) unnamed_type_28 FlexArrayMemb;
#else
    unnamed_type_28 FlexArrayMemb __attribute__((aligned(8)));
#endif
} EmptyAligned8LongLongMemb;
EmptyAligned8LongLongMemb var33;
struct EmptyAligned8LongLongMemb_alignment {
#ifdef MSVC
    char a[_Alignof(EmptyAligned8LongLongMemb)];
    char b;
#else
    char a;
    EmptyAligned8LongLongMemb b;
#endif
};
struct EmptyAligned8LongLongMemb_alignment var34;
#pragma pack(1)
struct EmptyAligned8LongLongMemb_packed {
    EmptyAligned8LongLongMemb a;
};
#pragma pack()
struct EmptyAligned8LongLongMemb_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct EmptyAligned8LongLongMemb_packed)];
    char b;
#else
    char a;
    struct EmptyAligned8LongLongMemb_packed b;
#endif
};
struct EmptyAligned8LongLongMemb_required_alignment var35;
struct EmptyAligned8LongLongMemb_size {
    char a[sizeof(EmptyAligned8LongLongMemb)+1];
    char b;
};
struct EmptyAligned8LongLongMemb_size var36;

#ifdef MSVC
typedef long long unnamed_type_37[];
#else
typedef long long unnamed_type_37[0];
#endif
unnamed_type_37 var38;
struct unnamed_type_37_alignment {
#ifdef MSVC
    char a[_Alignof(unnamed_type_37)];
    char b;
#else
    char a;
    unnamed_type_37 b;
#endif
};
struct unnamed_type_37_alignment var39;
#pragma pack(1)
struct unnamed_type_37_packed {
    unnamed_type_37 a;
};
#pragma pack()
struct unnamed_type_37_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct unnamed_type_37_packed)];
    char b;
#else
    char a;
    struct unnamed_type_37_packed b;
#endif
};
struct unnamed_type_37_required_alignment var40;
struct unnamed_type_37_size {
    char a[sizeof(unnamed_type_37)+1];
    char b;
};
struct unnamed_type_37_size var41;

#pragma pack(1)
#ifdef MSVC
__declspec(align(4)) typedef struct {
#else
typedef struct {
#endif
    unnamed_type_37 FlexArrayMemb;
#ifdef MSVC
} EmptyPackedAligned4LongLongMemb;
#else
} __attribute__((aligned(4))) EmptyPackedAligned4LongLongMemb;
#endif
EmptyPackedAligned4LongLongMemb var42;
#pragma pack()
struct EmptyPackedAligned4LongLongMemb_alignment {
#ifdef MSVC
    char a[_Alignof(EmptyPackedAligned4LongLongMemb)];
    char b;
#else
    char a;
    EmptyPackedAligned4LongLongMemb b;
#endif
};
struct EmptyPackedAligned4LongLongMemb_alignment var43;
#pragma pack(1)
struct EmptyPackedAligned4LongLongMemb_packed {
    EmptyPackedAligned4LongLongMemb a;
};
#pragma pack()
struct EmptyPackedAligned4LongLongMemb_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct EmptyPackedAligned4LongLongMemb_packed)];
    char b;
#else
    char a;
    struct EmptyPackedAligned4LongLongMemb_packed b;
#endif
};
struct EmptyPackedAligned4LongLongMemb_required_alignment var44;
struct EmptyPackedAligned4LongLongMemb_size {
    char a[sizeof(EmptyPackedAligned4LongLongMemb)+1];
    char b;
};
struct EmptyPackedAligned4LongLongMemb_size var45;

#ifdef MSVC
typedef long long unnamed_type_46[];
#else
typedef long long unnamed_type_46[0];
#endif
unnamed_type_46 var47;
struct unnamed_type_46_alignment {
#ifdef MSVC
    char a[_Alignof(unnamed_type_46)];
    char b;
#else
    char a;
    unnamed_type_46 b;
#endif
};
struct unnamed_type_46_alignment var48;
#pragma pack(1)
struct unnamed_type_46_packed {
    unnamed_type_46 a;
};
#pragma pack()
struct unnamed_type_46_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct unnamed_type_46_packed)];
    char b;
#else
    char a;
    struct unnamed_type_46_packed b;
#endif
};
struct unnamed_type_46_required_alignment var49;
struct unnamed_type_46_size {
    char a[sizeof(unnamed_type_46)+1];
    char b;
};
struct unnamed_type_46_size var50;

#pragma pack(1)
typedef struct {
#ifdef MSVC
    __declspec(align(8)) unnamed_type_46 FlexArrayMemb;
#else
    unnamed_type_46 FlexArrayMemb __attribute__((aligned(8)));
#endif
} EmptyPackedAligned8LongLongMemb;
EmptyPackedAligned8LongLongMemb var51;
#pragma pack()
struct EmptyPackedAligned8LongLongMemb_alignment {
#ifdef MSVC
    char a[_Alignof(EmptyPackedAligned8LongLongMemb)];
    char b;
#else
    char a;
    EmptyPackedAligned8LongLongMemb b;
#endif
};
struct EmptyPackedAligned8LongLongMemb_alignment var52;
#pragma pack(1)
struct EmptyPackedAligned8LongLongMemb_packed {
    EmptyPackedAligned8LongLongMemb a;
};
#pragma pack()
struct EmptyPackedAligned8LongLongMemb_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct EmptyPackedAligned8LongLongMemb_packed)];
    char b;
#else
    char a;
    struct EmptyPackedAligned8LongLongMemb_packed b;
#endif
};
struct EmptyPackedAligned8LongLongMemb_required_alignment var53;
struct EmptyPackedAligned8LongLongMemb_size {
    char a[sizeof(EmptyPackedAligned8LongLongMemb)+1];
    char b;
};
struct EmptyPackedAligned8LongLongMemb_size var54;

#if defined(AARCH64_APPLE_MACOSX) ||  defined(AARCH64_FUCHSIA) ||  defined(AARCH64_LINUX_ANDROID) ||  defined(AARCH64_UNKNOWN_FREEBSD) ||  \
 defined(AARCH64_UNKNOWN_HERMIT) ||  defined(AARCH64_UNKNOWN_LINUX_GNU) ||  defined(AARCH64_UNKNOWN_LINUX_MUSL) ||  defined(AARCH64_UNKNOWN_NETBSD) ||  \
 defined(AARCH64_UNKNOWN_NONE) ||  defined(AARCH64_UNKNOWN_OPENBSD) ||  defined(AARCH64_UNKNOWN_REDOX) ||  defined(ARM64_APPLE_IOS) ||  \
 defined(ARM64_APPLE_IOS_MACABI) ||  defined(ARM64_APPLE_TVOS) ||  defined(ARMEBV7R_UNKNOWN_NONE_EABI) ||  defined(ARMEBV7R_UNKNOWN_NONE_EABIHF) ||  \
 defined(ARM_LINUX_ANDROIDEABI) ||  defined(ARM_UNKNOWN_LINUX_GNUEABI) ||  defined(ARM_UNKNOWN_LINUX_GNUEABIHF) ||  defined(ARMV4T_UNKNOWN_LINUX_GNUEABI) ||  \
 defined(ARMV5TE_UNKNOWN_LINUX_GNUEABI) ||  defined(ARMV5TE_UNKNOWN_LINUX_UCLIBCGNUEABI) ||  defined(ARMV6_UNKNOWN_FREEBSD_GNUEABIHF) ||  \
 defined(ARMV6_UNKNOWN_NETBSDELF_EABIHF) ||  defined(ARMV7A_NONE_EABI) ||  defined(ARMV7A_NONE_EABIHF) ||  defined(ARMV7_NONE_LINUX_ANDROID) ||  \
 defined(ARMV7R_UNKNOWN_NONE_EABI) ||  defined(ARMV7R_UNKNOWN_NONE_EABIHF) ||  defined(ARMV7_UNKNOWN_FREEBSD_GNUEABIHF) ||  defined(ARMV7_UNKNOWN_LINUX_GNUEABI) ||  \
 defined(ARMV7_UNKNOWN_LINUX_GNUEABIHF) ||  defined(ARMV7_UNKNOWN_NETBSDELF_EABIHF) ||  defined(HEXAGON_UNKNOWN_LINUX_MUSL) ||  defined(I686_PC_WINDOWS_GNU) ||  \
 defined(MIPS64EL_UNKNOWN_LINUX_GNUABI64) ||  defined(MIPS64EL_UNKNOWN_LINUX_MUSL) ||  defined(MIPS64_UNKNOWN_LINUX_GNUABI64) ||  \
 defined(MIPS64_UNKNOWN_LINUX_MUSL) ||  defined(MIPSEL_SONY_PSP) ||  defined(MIPSEL_UNKNOWN_LINUX_GNU) ||  defined(MIPSEL_UNKNOWN_LINUX_MUSL) ||  \
 defined(MIPSEL_UNKNOWN_LINUX_UCLIBC) ||  defined(MIPSEL_UNKNOWN_NONE) ||  defined(MIPSISA32R6EL_UNKNOWN_LINUX_GNU) ||  defined(MIPSISA32R6_UNKNOWN_LINUX_GNU) ||  \
 defined(MIPSISA64R6EL_UNKNOWN_LINUX_GNUABI64) ||  defined(MIPSISA64R6_UNKNOWN_LINUX_GNUABI64) ||  defined(MIPS_UNKNOWN_LINUX_GNU) ||  \
 defined(MIPS_UNKNOWN_LINUX_MUSL) ||  defined(MIPS_UNKNOWN_LINUX_UCLIBC) ||  defined(POWERPC64LE_UNKNOWN_LINUX_GNU) ||  defined(POWERPC64LE_UNKNOWN_LINUX_MUSL) ||  \
 defined(POWERPC64_UNKNOWN_FREEBSD) ||  defined(POWERPC64_UNKNOWN_LINUX_GNU) ||  defined(POWERPC64_UNKNOWN_LINUX_MUSL) ||  defined(POWERPC_UNKNOWN_LINUX_GNU) ||  \
 defined(POWERPC_UNKNOWN_LINUX_GNUSPE) ||  defined(POWERPC_UNKNOWN_LINUX_MUSL) ||  defined(POWERPC_UNKNOWN_NETBSD) ||  defined(RISCV32) ||  \
 defined(RISCV32_UNKNOWN_LINUX_GNU) ||  defined(RISCV64) ||  defined(RISCV64_UNKNOWN_LINUX_GNU) ||  defined(S390X_UNKNOWN_LINUX_GNU) ||  \
 defined(SPARC64_UNKNOWN_LINUX_GNU) ||  defined(SPARC64_UNKNOWN_NETBSD) ||  defined(SPARC64_UNKNOWN_OPENBSD) ||  defined(SPARC_UNKNOWN_LINUX_GNU) ||  \
 defined(SPARCV9_SUN_SOLARIS) ||  defined(THUMBV4T_NONE_EABI) ||  defined(THUMBV6M_NONE_EABI) ||  defined(THUMBV7EM_NONE_EABIHF) ||  \
 defined(THUMBV7EM_NONE_EABI) ||  defined(THUMBV7M_NONE_EABI) ||  defined(THUMBV8MBASE_NONE_EABI) ||  defined(THUMBV8MMAIN_NONE_EABIHF) ||  \
 defined(THUMBV8MMAIN_NONE_EABI) ||  defined(WASM32_UNKNOWN_EMSCRIPTEN) ||  defined(WASM32_UNKNOWN_UNKNOWN) ||  defined(WASM32_WASI) ||  \
 defined(X8664_APPLE_IOS_MACABI) ||  defined(X8664_APPLE_IOS) ||  defined(X8664_APPLE_MACOSX) ||  defined(X8664_APPLE_TVOS) ||  defined(X8664_ELF) ||  \
 defined(X8664_FUCHSIA) ||  defined(X8664_LINUX_ANDROID) ||  defined(X8664_PC_SOLARIS) ||  defined(X8664_PC_WINDOWS_GNU) ||  defined(X8664_RUMPRUN_NETBSD) ||  \
 defined(X8664_UNKNOWN_DRAGONFLY) ||  defined(X8664_UNKNOWN_FREEBSD) ||  defined(X8664_UNKNOWN_HAIKU) ||  defined(X8664_UNKNOWN_HERMIT) ||  \
 defined(X8664_UNKNOWN_L4RE_UCLIBC) ||  defined(X8664_UNKNOWN_LINUX_GNUX32) ||  defined(X8664_UNKNOWN_LINUX_GNU) ||  defined(X8664_UNKNOWN_LINUX_MUSL) ||  \
 defined(X8664_UNKNOWN_NETBSD) ||  defined(X8664_UNKNOWN_OPENBSD) ||  defined(X8664_UNKNOWN_REDOX) 
_Static_assert(sizeof(EmptyIntMemb) == 0, "record EmptyIntMemb wrong sizeof");
_Static_assert(_Alignof(EmptyIntMemb) == 4, "record EmptyIntMemb wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyIntMemb_alignment) == 4, "record EmptyIntMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyIntMemb_alignment) == 4, "record EmptyIntMemb wrong alignment");
_Static_assert(sizeof(struct EmptyIntMemb_packed) == 0, "record EmptyIntMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyIntMemb_packed) == 1, "record EmptyIntMemb wrong alignment");
_Static_assert(sizeof(struct EmptyIntMemb_required_alignment) == 1, "record EmptyIntMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyIntMemb_required_alignment) == 1, "record EmptyIntMemb wrong alignment");
_Static_assert(sizeof(struct EmptyIntMemb_size) == 2, "record EmptyIntMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyIntMemb_size) == 1, "record EmptyIntMemb wrong alignment");
#endif
_Static_assert(sizeof(EmptyLongLongMemb) == 0, "record EmptyLongLongMemb wrong sizeof");
_Static_assert(_Alignof(EmptyLongLongMemb) == 8, "record EmptyLongLongMemb wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyLongLongMemb_alignment) == 8, "record EmptyLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyLongLongMemb_alignment) == 8, "record EmptyLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyLongLongMemb_packed) == 0, "record EmptyLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyLongLongMemb_packed) == 1, "record EmptyLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyLongLongMemb_required_alignment) == 1, "record EmptyLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyLongLongMemb_required_alignment) == 1, "record EmptyLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyLongLongMemb_size) == 2, "record EmptyLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyLongLongMemb_size) == 1, "record EmptyLongLongMemb wrong alignment");
#endif
_Static_assert(sizeof(EmptyAligned2LongLongMemb) == 0, "record EmptyAligned2LongLongMemb wrong sizeof");
_Static_assert(_Alignof(EmptyAligned2LongLongMemb) == 8, "record EmptyAligned2LongLongMemb wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyAligned2LongLongMemb_alignment) == 8, "record EmptyAligned2LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAligned2LongLongMemb_alignment) == 8, "record EmptyAligned2LongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyAligned2LongLongMemb_packed) == 0, "record EmptyAligned2LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAligned2LongLongMemb_packed) == 1, "record EmptyAligned2LongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyAligned2LongLongMemb_required_alignment) == 1, "record EmptyAligned2LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAligned2LongLongMemb_required_alignment) == 1, "record EmptyAligned2LongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyAligned2LongLongMemb_size) == 2, "record EmptyAligned2LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAligned2LongLongMemb_size) == 1, "record EmptyAligned2LongLongMemb wrong alignment");
#endif
_Static_assert(sizeof(EmptyAligned8LongLongMemb) == 0, "record EmptyAligned8LongLongMemb wrong sizeof");
_Static_assert(_Alignof(EmptyAligned8LongLongMemb) == 8, "record EmptyAligned8LongLongMemb wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyAligned8LongLongMemb_alignment) == 8, "record EmptyAligned8LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAligned8LongLongMemb_alignment) == 8, "record EmptyAligned8LongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyAligned8LongLongMemb_packed) == 0, "record EmptyAligned8LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAligned8LongLongMemb_packed) == 1, "record EmptyAligned8LongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyAligned8LongLongMemb_required_alignment) == 1, "record EmptyAligned8LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAligned8LongLongMemb_required_alignment) == 1, "record EmptyAligned8LongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyAligned8LongLongMemb_size) == 2, "record EmptyAligned8LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAligned8LongLongMemb_size) == 1, "record EmptyAligned8LongLongMemb wrong alignment");
#endif
_Static_assert(sizeof(EmptyPackedAligned4LongLongMemb) == 0, "record EmptyPackedAligned4LongLongMemb wrong sizeof");
_Static_assert(_Alignof(EmptyPackedAligned4LongLongMemb) == 4, "record EmptyPackedAligned4LongLongMemb wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyPackedAligned4LongLongMemb_alignment) == 4, "record EmptyPackedAligned4LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAligned4LongLongMemb_alignment) == 4, "record EmptyPackedAligned4LongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyPackedAligned4LongLongMemb_packed) == 0, "record EmptyPackedAligned4LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAligned4LongLongMemb_packed) == 1, "record EmptyPackedAligned4LongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyPackedAligned4LongLongMemb_required_alignment) == 1, "record EmptyPackedAligned4LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAligned4LongLongMemb_required_alignment) == 1, "record EmptyPackedAligned4LongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyPackedAligned4LongLongMemb_size) == 2, "record EmptyPackedAligned4LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAligned4LongLongMemb_size) == 1, "record EmptyPackedAligned4LongLongMemb wrong alignment");
#endif
_Static_assert(sizeof(EmptyPackedAligned8LongLongMemb) == 0, "record EmptyPackedAligned8LongLongMemb wrong sizeof");
_Static_assert(_Alignof(EmptyPackedAligned8LongLongMemb) == 1, "record EmptyPackedAligned8LongLongMemb wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyPackedAligned8LongLongMemb_alignment) == 1, "record EmptyPackedAligned8LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAligned8LongLongMemb_alignment) == 1, "record EmptyPackedAligned8LongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyPackedAligned8LongLongMemb_packed) == 0, "record EmptyPackedAligned8LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAligned8LongLongMemb_packed) == 1, "record EmptyPackedAligned8LongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyPackedAligned8LongLongMemb_required_alignment) == 1, "record EmptyPackedAligned8LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAligned8LongLongMemb_required_alignment) == 1, "record EmptyPackedAligned8LongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyPackedAligned8LongLongMemb_size) == 2, "record EmptyPackedAligned8LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAligned8LongLongMemb_size) == 1, "record EmptyPackedAligned8LongLongMemb wrong alignment");
#endif
#elif defined(AARCH64_PC_WINDOWS_MSVC) ||  defined(I586_PC_WINDOWS_MSVC) ||  defined(I686_PC_WINDOWS_MSVC) ||  defined(I686_UNKNOWN_WINDOWS) ||  \
 defined(THUMBV7A_PC_WINDOWS_MSVC) ||  defined(X8664_PC_WINDOWS_MSVC) ||  defined(X8664_UNKNOWN_WINDOWS) 
_Static_assert(sizeof(EmptyIntMemb) == 4, "record EmptyIntMemb wrong sizeof");
_Static_assert(_Alignof(EmptyIntMemb) == 4, "record EmptyIntMemb wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyIntMemb_alignment) == 8, "record EmptyIntMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyIntMemb_alignment) == 4, "record EmptyIntMemb wrong alignment");
_Static_assert(sizeof(struct EmptyIntMemb_packed) == 4, "record EmptyIntMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyIntMemb_packed) == 1, "record EmptyIntMemb wrong alignment");
_Static_assert(sizeof(struct EmptyIntMemb_required_alignment) == 5, "record EmptyIntMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyIntMemb_required_alignment) == 1, "record EmptyIntMemb wrong alignment");
_Static_assert(sizeof(struct EmptyIntMemb_size) == 6, "record EmptyIntMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyIntMemb_size) == 1, "record EmptyIntMemb wrong alignment");
#endif
_Static_assert(sizeof(EmptyLongLongMemb) == 4, "record EmptyLongLongMemb wrong sizeof");
_Static_assert(_Alignof(EmptyLongLongMemb) == 8, "record EmptyLongLongMemb wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyLongLongMemb_alignment) == 16, "record EmptyLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyLongLongMemb_alignment) == 8, "record EmptyLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyLongLongMemb_packed) == 4, "record EmptyLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyLongLongMemb_packed) == 1, "record EmptyLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyLongLongMemb_required_alignment) == 5, "record EmptyLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyLongLongMemb_required_alignment) == 1, "record EmptyLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyLongLongMemb_size) == 6, "record EmptyLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyLongLongMemb_size) == 1, "record EmptyLongLongMemb wrong alignment");
#endif
_Static_assert(sizeof(EmptyAligned2LongLongMemb) == 4, "record EmptyAligned2LongLongMemb wrong sizeof");
_Static_assert(_Alignof(EmptyAligned2LongLongMemb) == 8, "record EmptyAligned2LongLongMemb wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyAligned2LongLongMemb_alignment) == 16, "record EmptyAligned2LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAligned2LongLongMemb_alignment) == 8, "record EmptyAligned2LongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyAligned2LongLongMemb_packed) == 4, "record EmptyAligned2LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAligned2LongLongMemb_packed) == 1, "record EmptyAligned2LongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyAligned2LongLongMemb_required_alignment) == 5, "record EmptyAligned2LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAligned2LongLongMemb_required_alignment) == 1, "record EmptyAligned2LongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyAligned2LongLongMemb_size) == 6, "record EmptyAligned2LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAligned2LongLongMemb_size) == 1, "record EmptyAligned2LongLongMemb wrong alignment");
#endif
_Static_assert(sizeof(EmptyAligned8LongLongMemb) == 8, "record EmptyAligned8LongLongMemb wrong sizeof");
_Static_assert(_Alignof(EmptyAligned8LongLongMemb) == 8, "record EmptyAligned8LongLongMemb wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyAligned8LongLongMemb_alignment) == 16, "record EmptyAligned8LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAligned8LongLongMemb_alignment) == 8, "record EmptyAligned8LongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyAligned8LongLongMemb_packed) == 8, "record EmptyAligned8LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAligned8LongLongMemb_packed) == 1, "record EmptyAligned8LongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyAligned8LongLongMemb_required_alignment) == 9, "record EmptyAligned8LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAligned8LongLongMemb_required_alignment) == 1, "record EmptyAligned8LongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyAligned8LongLongMemb_size) == 10, "record EmptyAligned8LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAligned8LongLongMemb_size) == 1, "record EmptyAligned8LongLongMemb wrong alignment");
#endif
_Static_assert(sizeof(EmptyPackedAligned4LongLongMemb) == 4, "record EmptyPackedAligned4LongLongMemb wrong sizeof");
_Static_assert(_Alignof(EmptyPackedAligned4LongLongMemb) == 4, "record EmptyPackedAligned4LongLongMemb wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyPackedAligned4LongLongMemb_alignment) == 8, "record EmptyPackedAligned4LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAligned4LongLongMemb_alignment) == 4, "record EmptyPackedAligned4LongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyPackedAligned4LongLongMemb_packed) == 4, "record EmptyPackedAligned4LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAligned4LongLongMemb_packed) == 1, "record EmptyPackedAligned4LongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyPackedAligned4LongLongMemb_required_alignment) == 5, "record EmptyPackedAligned4LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAligned4LongLongMemb_required_alignment) == 1, "record EmptyPackedAligned4LongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyPackedAligned4LongLongMemb_size) == 6, "record EmptyPackedAligned4LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAligned4LongLongMemb_size) == 1, "record EmptyPackedAligned4LongLongMemb wrong alignment");
#endif
_Static_assert(sizeof(EmptyPackedAligned8LongLongMemb) == 8, "record EmptyPackedAligned8LongLongMemb wrong sizeof");
_Static_assert(_Alignof(EmptyPackedAligned8LongLongMemb) == 8, "record EmptyPackedAligned8LongLongMemb wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyPackedAligned8LongLongMemb_alignment) == 16, "record EmptyPackedAligned8LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAligned8LongLongMemb_alignment) == 8, "record EmptyPackedAligned8LongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyPackedAligned8LongLongMemb_packed) == 8, "record EmptyPackedAligned8LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAligned8LongLongMemb_packed) == 1, "record EmptyPackedAligned8LongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyPackedAligned8LongLongMemb_required_alignment) == 9, "record EmptyPackedAligned8LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAligned8LongLongMemb_required_alignment) == 1, "record EmptyPackedAligned8LongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyPackedAligned8LongLongMemb_size) == 10, "record EmptyPackedAligned8LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAligned8LongLongMemb_size) == 1, "record EmptyPackedAligned8LongLongMemb wrong alignment");
#endif
#elif defined(ARMV7_APPLE_IOS) ||  defined(ARMV7S_APPLE_IOS) ||  defined(I386_APPLE_IOS) ||  defined(I586_UNKNOWN_LINUX_GNU) ||  defined(I586_UNKNOWN_LINUX_MUSL) ||  \
 defined(I686_APPLE_MACOSX) ||  defined(I686_LINUX_ANDROID) ||  defined(I686_UNKNOWN_FREEBSD) ||  defined(I686_UNKNOWN_HAIKU) ||  defined(I686_UNKNOWN_LINUX_GNU) ||  \
 defined(I686_UNKNOWN_LINUX_MUSL) ||  defined(I686_UNKNOWN_NETBSDELF) ||  defined(I686_UNKNOWN_OPENBSD) 
_Static_assert(sizeof(EmptyIntMemb) == 0, "record EmptyIntMemb wrong sizeof");
_Static_assert(_Alignof(EmptyIntMemb) == 4, "record EmptyIntMemb wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyIntMemb_alignment) == 4, "record EmptyIntMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyIntMemb_alignment) == 4, "record EmptyIntMemb wrong alignment");
_Static_assert(sizeof(struct EmptyIntMemb_packed) == 0, "record EmptyIntMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyIntMemb_packed) == 1, "record EmptyIntMemb wrong alignment");
_Static_assert(sizeof(struct EmptyIntMemb_required_alignment) == 1, "record EmptyIntMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyIntMemb_required_alignment) == 1, "record EmptyIntMemb wrong alignment");
_Static_assert(sizeof(struct EmptyIntMemb_size) == 2, "record EmptyIntMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyIntMemb_size) == 1, "record EmptyIntMemb wrong alignment");
#endif
_Static_assert(sizeof(EmptyLongLongMemb) == 0, "record EmptyLongLongMemb wrong sizeof");
_Static_assert(_Alignof(EmptyLongLongMemb) == 4, "record EmptyLongLongMemb wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyLongLongMemb_alignment) == 4, "record EmptyLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyLongLongMemb_alignment) == 4, "record EmptyLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyLongLongMemb_packed) == 0, "record EmptyLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyLongLongMemb_packed) == 1, "record EmptyLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyLongLongMemb_required_alignment) == 1, "record EmptyLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyLongLongMemb_required_alignment) == 1, "record EmptyLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyLongLongMemb_size) == 2, "record EmptyLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyLongLongMemb_size) == 1, "record EmptyLongLongMemb wrong alignment");
#endif
_Static_assert(sizeof(EmptyAligned2LongLongMemb) == 0, "record EmptyAligned2LongLongMemb wrong sizeof");
_Static_assert(_Alignof(EmptyAligned2LongLongMemb) == 4, "record EmptyAligned2LongLongMemb wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyAligned2LongLongMemb_alignment) == 4, "record EmptyAligned2LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAligned2LongLongMemb_alignment) == 4, "record EmptyAligned2LongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyAligned2LongLongMemb_packed) == 0, "record EmptyAligned2LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAligned2LongLongMemb_packed) == 1, "record EmptyAligned2LongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyAligned2LongLongMemb_required_alignment) == 1, "record EmptyAligned2LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAligned2LongLongMemb_required_alignment) == 1, "record EmptyAligned2LongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyAligned2LongLongMemb_size) == 2, "record EmptyAligned2LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAligned2LongLongMemb_size) == 1, "record EmptyAligned2LongLongMemb wrong alignment");
#endif
_Static_assert(sizeof(EmptyAligned8LongLongMemb) == 0, "record EmptyAligned8LongLongMemb wrong sizeof");
_Static_assert(_Alignof(EmptyAligned8LongLongMemb) == 8, "record EmptyAligned8LongLongMemb wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyAligned8LongLongMemb_alignment) == 8, "record EmptyAligned8LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAligned8LongLongMemb_alignment) == 8, "record EmptyAligned8LongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyAligned8LongLongMemb_packed) == 0, "record EmptyAligned8LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAligned8LongLongMemb_packed) == 1, "record EmptyAligned8LongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyAligned8LongLongMemb_required_alignment) == 1, "record EmptyAligned8LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAligned8LongLongMemb_required_alignment) == 1, "record EmptyAligned8LongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyAligned8LongLongMemb_size) == 2, "record EmptyAligned8LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAligned8LongLongMemb_size) == 1, "record EmptyAligned8LongLongMemb wrong alignment");
#endif
_Static_assert(sizeof(EmptyPackedAligned4LongLongMemb) == 0, "record EmptyPackedAligned4LongLongMemb wrong sizeof");
_Static_assert(_Alignof(EmptyPackedAligned4LongLongMemb) == 4, "record EmptyPackedAligned4LongLongMemb wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyPackedAligned4LongLongMemb_alignment) == 4, "record EmptyPackedAligned4LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAligned4LongLongMemb_alignment) == 4, "record EmptyPackedAligned4LongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyPackedAligned4LongLongMemb_packed) == 0, "record EmptyPackedAligned4LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAligned4LongLongMemb_packed) == 1, "record EmptyPackedAligned4LongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyPackedAligned4LongLongMemb_required_alignment) == 1, "record EmptyPackedAligned4LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAligned4LongLongMemb_required_alignment) == 1, "record EmptyPackedAligned4LongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyPackedAligned4LongLongMemb_size) == 2, "record EmptyPackedAligned4LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAligned4LongLongMemb_size) == 1, "record EmptyPackedAligned4LongLongMemb wrong alignment");
#endif
_Static_assert(sizeof(EmptyPackedAligned8LongLongMemb) == 0, "record EmptyPackedAligned8LongLongMemb wrong sizeof");
_Static_assert(_Alignof(EmptyPackedAligned8LongLongMemb) == 1, "record EmptyPackedAligned8LongLongMemb wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyPackedAligned8LongLongMemb_alignment) == 1, "record EmptyPackedAligned8LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAligned8LongLongMemb_alignment) == 1, "record EmptyPackedAligned8LongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyPackedAligned8LongLongMemb_packed) == 0, "record EmptyPackedAligned8LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAligned8LongLongMemb_packed) == 1, "record EmptyPackedAligned8LongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyPackedAligned8LongLongMemb_required_alignment) == 1, "record EmptyPackedAligned8LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAligned8LongLongMemb_required_alignment) == 1, "record EmptyPackedAligned8LongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyPackedAligned8LongLongMemb_size) == 2, "record EmptyPackedAligned8LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAligned8LongLongMemb_size) == 1, "record EmptyPackedAligned8LongLongMemb wrong alignment");
#endif
#elif defined(AVR_UNKNOWN_UNKNOWN) 
_Static_assert(sizeof(EmptyIntMemb) == 0, "record EmptyIntMemb wrong sizeof");
_Static_assert(_Alignof(EmptyIntMemb) == 1, "record EmptyIntMemb wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyIntMemb_alignment) == 1, "record EmptyIntMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyIntMemb_alignment) == 1, "record EmptyIntMemb wrong alignment");
_Static_assert(sizeof(struct EmptyIntMemb_packed) == 0, "record EmptyIntMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyIntMemb_packed) == 1, "record EmptyIntMemb wrong alignment");
_Static_assert(sizeof(struct EmptyIntMemb_required_alignment) == 1, "record EmptyIntMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyIntMemb_required_alignment) == 1, "record EmptyIntMemb wrong alignment");
_Static_assert(sizeof(struct EmptyIntMemb_size) == 2, "record EmptyIntMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyIntMemb_size) == 1, "record EmptyIntMemb wrong alignment");
#endif
_Static_assert(sizeof(EmptyLongLongMemb) == 0, "record EmptyLongLongMemb wrong sizeof");
_Static_assert(_Alignof(EmptyLongLongMemb) == 1, "record EmptyLongLongMemb wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyLongLongMemb_alignment) == 1, "record EmptyLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyLongLongMemb_alignment) == 1, "record EmptyLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyLongLongMemb_packed) == 0, "record EmptyLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyLongLongMemb_packed) == 1, "record EmptyLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyLongLongMemb_required_alignment) == 1, "record EmptyLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyLongLongMemb_required_alignment) == 1, "record EmptyLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyLongLongMemb_size) == 2, "record EmptyLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyLongLongMemb_size) == 1, "record EmptyLongLongMemb wrong alignment");
#endif
_Static_assert(sizeof(EmptyAligned2LongLongMemb) == 0, "record EmptyAligned2LongLongMemb wrong sizeof");
_Static_assert(_Alignof(EmptyAligned2LongLongMemb) == 2, "record EmptyAligned2LongLongMemb wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyAligned2LongLongMemb_alignment) == 2, "record EmptyAligned2LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAligned2LongLongMemb_alignment) == 2, "record EmptyAligned2LongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyAligned2LongLongMemb_packed) == 0, "record EmptyAligned2LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAligned2LongLongMemb_packed) == 1, "record EmptyAligned2LongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyAligned2LongLongMemb_required_alignment) == 1, "record EmptyAligned2LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAligned2LongLongMemb_required_alignment) == 1, "record EmptyAligned2LongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyAligned2LongLongMemb_size) == 2, "record EmptyAligned2LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAligned2LongLongMemb_size) == 1, "record EmptyAligned2LongLongMemb wrong alignment");
#endif
_Static_assert(sizeof(EmptyAligned8LongLongMemb) == 0, "record EmptyAligned8LongLongMemb wrong sizeof");
_Static_assert(_Alignof(EmptyAligned8LongLongMemb) == 8, "record EmptyAligned8LongLongMemb wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyAligned8LongLongMemb_alignment) == 8, "record EmptyAligned8LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAligned8LongLongMemb_alignment) == 8, "record EmptyAligned8LongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyAligned8LongLongMemb_packed) == 0, "record EmptyAligned8LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAligned8LongLongMemb_packed) == 1, "record EmptyAligned8LongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyAligned8LongLongMemb_required_alignment) == 1, "record EmptyAligned8LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAligned8LongLongMemb_required_alignment) == 1, "record EmptyAligned8LongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyAligned8LongLongMemb_size) == 2, "record EmptyAligned8LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAligned8LongLongMemb_size) == 1, "record EmptyAligned8LongLongMemb wrong alignment");
#endif
_Static_assert(sizeof(EmptyPackedAligned4LongLongMemb) == 0, "record EmptyPackedAligned4LongLongMemb wrong sizeof");
_Static_assert(_Alignof(EmptyPackedAligned4LongLongMemb) == 4, "record EmptyPackedAligned4LongLongMemb wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyPackedAligned4LongLongMemb_alignment) == 4, "record EmptyPackedAligned4LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAligned4LongLongMemb_alignment) == 4, "record EmptyPackedAligned4LongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyPackedAligned4LongLongMemb_packed) == 0, "record EmptyPackedAligned4LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAligned4LongLongMemb_packed) == 1, "record EmptyPackedAligned4LongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyPackedAligned4LongLongMemb_required_alignment) == 1, "record EmptyPackedAligned4LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAligned4LongLongMemb_required_alignment) == 1, "record EmptyPackedAligned4LongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyPackedAligned4LongLongMemb_size) == 2, "record EmptyPackedAligned4LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAligned4LongLongMemb_size) == 1, "record EmptyPackedAligned4LongLongMemb wrong alignment");
#endif
_Static_assert(sizeof(EmptyPackedAligned8LongLongMemb) == 0, "record EmptyPackedAligned8LongLongMemb wrong sizeof");
_Static_assert(_Alignof(EmptyPackedAligned8LongLongMemb) == 1, "record EmptyPackedAligned8LongLongMemb wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyPackedAligned8LongLongMemb_alignment) == 1, "record EmptyPackedAligned8LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAligned8LongLongMemb_alignment) == 1, "record EmptyPackedAligned8LongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyPackedAligned8LongLongMemb_packed) == 0, "record EmptyPackedAligned8LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAligned8LongLongMemb_packed) == 1, "record EmptyPackedAligned8LongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyPackedAligned8LongLongMemb_required_alignment) == 1, "record EmptyPackedAligned8LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAligned8LongLongMemb_required_alignment) == 1, "record EmptyPackedAligned8LongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyPackedAligned8LongLongMemb_size) == 2, "record EmptyPackedAligned8LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAligned8LongLongMemb_size) == 1, "record EmptyPackedAligned8LongLongMemb wrong alignment");
#endif
#elif defined(MSP430_NONE_ELF) 
_Static_assert(sizeof(EmptyIntMemb) == 0, "record EmptyIntMemb wrong sizeof");
_Static_assert(_Alignof(EmptyIntMemb) == 2, "record EmptyIntMemb wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyIntMemb_alignment) == 2, "record EmptyIntMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyIntMemb_alignment) == 2, "record EmptyIntMemb wrong alignment");
_Static_assert(sizeof(struct EmptyIntMemb_packed) == 0, "record EmptyIntMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyIntMemb_packed) == 1, "record EmptyIntMemb wrong alignment");
_Static_assert(sizeof(struct EmptyIntMemb_required_alignment) == 1, "record EmptyIntMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyIntMemb_required_alignment) == 1, "record EmptyIntMemb wrong alignment");
_Static_assert(sizeof(struct EmptyIntMemb_size) == 2, "record EmptyIntMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyIntMemb_size) == 1, "record EmptyIntMemb wrong alignment");
#endif
_Static_assert(sizeof(EmptyLongLongMemb) == 0, "record EmptyLongLongMemb wrong sizeof");
_Static_assert(_Alignof(EmptyLongLongMemb) == 2, "record EmptyLongLongMemb wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyLongLongMemb_alignment) == 2, "record EmptyLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyLongLongMemb_alignment) == 2, "record EmptyLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyLongLongMemb_packed) == 0, "record EmptyLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyLongLongMemb_packed) == 1, "record EmptyLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyLongLongMemb_required_alignment) == 1, "record EmptyLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyLongLongMemb_required_alignment) == 1, "record EmptyLongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyLongLongMemb_size) == 2, "record EmptyLongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyLongLongMemb_size) == 1, "record EmptyLongLongMemb wrong alignment");
#endif
_Static_assert(sizeof(EmptyAligned2LongLongMemb) == 0, "record EmptyAligned2LongLongMemb wrong sizeof");
_Static_assert(_Alignof(EmptyAligned2LongLongMemb) == 2, "record EmptyAligned2LongLongMemb wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyAligned2LongLongMemb_alignment) == 2, "record EmptyAligned2LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAligned2LongLongMemb_alignment) == 2, "record EmptyAligned2LongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyAligned2LongLongMemb_packed) == 0, "record EmptyAligned2LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAligned2LongLongMemb_packed) == 1, "record EmptyAligned2LongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyAligned2LongLongMemb_required_alignment) == 1, "record EmptyAligned2LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAligned2LongLongMemb_required_alignment) == 1, "record EmptyAligned2LongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyAligned2LongLongMemb_size) == 2, "record EmptyAligned2LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAligned2LongLongMemb_size) == 1, "record EmptyAligned2LongLongMemb wrong alignment");
#endif
_Static_assert(sizeof(EmptyAligned8LongLongMemb) == 0, "record EmptyAligned8LongLongMemb wrong sizeof");
_Static_assert(_Alignof(EmptyAligned8LongLongMemb) == 8, "record EmptyAligned8LongLongMemb wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyAligned8LongLongMemb_alignment) == 8, "record EmptyAligned8LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAligned8LongLongMemb_alignment) == 8, "record EmptyAligned8LongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyAligned8LongLongMemb_packed) == 0, "record EmptyAligned8LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAligned8LongLongMemb_packed) == 1, "record EmptyAligned8LongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyAligned8LongLongMemb_required_alignment) == 1, "record EmptyAligned8LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAligned8LongLongMemb_required_alignment) == 1, "record EmptyAligned8LongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyAligned8LongLongMemb_size) == 2, "record EmptyAligned8LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyAligned8LongLongMemb_size) == 1, "record EmptyAligned8LongLongMemb wrong alignment");
#endif
_Static_assert(sizeof(EmptyPackedAligned4LongLongMemb) == 0, "record EmptyPackedAligned4LongLongMemb wrong sizeof");
_Static_assert(_Alignof(EmptyPackedAligned4LongLongMemb) == 4, "record EmptyPackedAligned4LongLongMemb wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyPackedAligned4LongLongMemb_alignment) == 4, "record EmptyPackedAligned4LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAligned4LongLongMemb_alignment) == 4, "record EmptyPackedAligned4LongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyPackedAligned4LongLongMemb_packed) == 0, "record EmptyPackedAligned4LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAligned4LongLongMemb_packed) == 1, "record EmptyPackedAligned4LongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyPackedAligned4LongLongMemb_required_alignment) == 1, "record EmptyPackedAligned4LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAligned4LongLongMemb_required_alignment) == 1, "record EmptyPackedAligned4LongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyPackedAligned4LongLongMemb_size) == 2, "record EmptyPackedAligned4LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAligned4LongLongMemb_size) == 1, "record EmptyPackedAligned4LongLongMemb wrong alignment");
#endif
_Static_assert(sizeof(EmptyPackedAligned8LongLongMemb) == 0, "record EmptyPackedAligned8LongLongMemb wrong sizeof");
_Static_assert(_Alignof(EmptyPackedAligned8LongLongMemb) == 1, "record EmptyPackedAligned8LongLongMemb wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyPackedAligned8LongLongMemb_alignment) == 1, "record EmptyPackedAligned8LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAligned8LongLongMemb_alignment) == 1, "record EmptyPackedAligned8LongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyPackedAligned8LongLongMemb_packed) == 0, "record EmptyPackedAligned8LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAligned8LongLongMemb_packed) == 1, "record EmptyPackedAligned8LongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyPackedAligned8LongLongMemb_required_alignment) == 1, "record EmptyPackedAligned8LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAligned8LongLongMemb_required_alignment) == 1, "record EmptyPackedAligned8LongLongMemb wrong alignment");
_Static_assert(sizeof(struct EmptyPackedAligned8LongLongMemb_size) == 2, "record EmptyPackedAligned8LongLongMemb wrong sizeof");
_Static_assert(_Alignof(struct EmptyPackedAligned8LongLongMemb_size) == 1, "record EmptyPackedAligned8LongLongMemb wrong alignment");
#endif
#endif
