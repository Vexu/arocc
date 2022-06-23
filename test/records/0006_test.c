// SPDX-License-Identifier: GPL-3.0-or-later

// This test file is auto-generated. do not edit.
// This file is a derivative work from the test files found// in this repo : https://github.com/mahkoh/repr-c
// and is under the same licence as the original work.

#ifdef MSVC
__declspec(align(8)) typedef int Int;
#else
typedef int Int __attribute__((aligned(8)));
#endif
Int var1;
struct Int_alignment {
#ifdef MSVC
    char a[_Alignof(Int)];
    char b;
#else
    char a;
    Int b;
#endif
};
struct Int_alignment var2;
#pragma pack(1)
struct Int_packed {
    Int a;
};
#pragma pack()
struct Int_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct Int_packed)];
    char b;
#else
    char a;
    struct Int_packed b;
#endif
};
struct Int_required_alignment var3;
struct Int_size {
    char a[sizeof(Int)+1];
    char b;
};
struct Int_size var4;

typedef struct {
    int i:1;
    Int j:1;
} X;
X var5;
struct X_alignment {
#ifdef MSVC
    char a[_Alignof(X)];
    char b;
#else
    char a;
    X b;
#endif
};
struct X_alignment var6;
#pragma pack(1)
struct X_packed {
    X a;
};
#pragma pack()
struct X_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct X_packed)];
    char b;
#else
    char a;
    struct X_packed b;
#endif
};
struct X_required_alignment var7;
struct X_size {
    char a[sizeof(X)+1];
    char b;
};
struct X_size var8;

#if defined(AARCH64_APPLE_MACOSX) ||  defined(AARCH64_FUCHSIA) ||  defined(AARCH64_LINUX_ANDROID) ||  defined(AARCH64_UNKNOWN_FREEBSD) ||  \
 defined(AARCH64_UNKNOWN_HERMIT) ||  defined(AARCH64_UNKNOWN_NETBSD) ||  defined(AARCH64_UNKNOWN_NONE) ||  defined(AARCH64_UNKNOWN_OPENBSD) ||  \
 defined(AARCH64_UNKNOWN_REDOX) ||  defined(ARM64_APPLE_IOS) ||  defined(ARM64_APPLE_IOS_MACABI) ||  defined(ARM64_APPLE_TVOS) ||  \
 defined(ARMEBV7R_UNKNOWN_NONE_EABI) ||  defined(ARMEBV7R_UNKNOWN_NONE_EABIHF) ||  defined(ARM_LINUX_ANDROIDEABI) ||  defined(ARMV6_UNKNOWN_FREEBSD_GNUEABIHF) ||  \
 defined(ARMV6_UNKNOWN_NETBSDELF_EABIHF) ||  defined(ARMV7A_NONE_EABI) ||  defined(ARMV7A_NONE_EABIHF) ||  defined(ARMV7_NONE_LINUX_ANDROID) ||  \
 defined(ARMV7R_UNKNOWN_NONE_EABI) ||  defined(ARMV7R_UNKNOWN_NONE_EABIHF) ||  defined(ARMV7_UNKNOWN_FREEBSD_GNUEABIHF) ||  defined(ARMV7_UNKNOWN_NETBSDELF_EABIHF) ||  \
 defined(HEXAGON_UNKNOWN_LINUX_MUSL) ||  defined(I386_APPLE_IOS) ||  defined(I686_APPLE_MACOSX) ||  defined(I686_LINUX_ANDROID) ||  \
 defined(I686_PC_WINDOWS_GNU) ||  defined(I686_UNKNOWN_FREEBSD) ||  defined(I686_UNKNOWN_HAIKU) ||  defined(I686_UNKNOWN_NETBSDELF) ||  \
 defined(I686_UNKNOWN_OPENBSD) ||  defined(MIPSEL_SONY_PSP) ||  defined(MIPSEL_UNKNOWN_NONE) ||  defined(POWERPC64_UNKNOWN_FREEBSD) ||  \
 defined(POWERPC_UNKNOWN_LINUX_GNUSPE) ||  defined(POWERPC_UNKNOWN_NETBSD) ||  defined(RISCV32) ||  defined(RISCV64) ||  defined(SPARC64_UNKNOWN_NETBSD) ||  \
 defined(SPARC64_UNKNOWN_OPENBSD) ||  defined(SPARCV9_SUN_SOLARIS) ||  defined(THUMBV4T_NONE_EABI) ||  defined(THUMBV6M_NONE_EABI) ||  \
 defined(THUMBV7EM_NONE_EABIHF) ||  defined(THUMBV7EM_NONE_EABI) ||  defined(THUMBV7M_NONE_EABI) ||  defined(THUMBV8MBASE_NONE_EABI) ||  \
 defined(THUMBV8MMAIN_NONE_EABIHF) ||  defined(THUMBV8MMAIN_NONE_EABI) ||  defined(WASM32_UNKNOWN_EMSCRIPTEN) ||  defined(WASM32_UNKNOWN_UNKNOWN) ||  \
 defined(WASM32_WASI) ||  defined(X8664_APPLE_IOS_MACABI) ||  defined(X8664_APPLE_IOS) ||  defined(X8664_APPLE_MACOSX) ||  defined(X8664_APPLE_TVOS) ||  \
 defined(X8664_ELF) ||  defined(X8664_FUCHSIA) ||  defined(X8664_LINUX_ANDROID) ||  defined(X8664_PC_SOLARIS) ||  defined(X8664_PC_WINDOWS_GNU) ||  \
 defined(X8664_RUMPRUN_NETBSD) ||  defined(X8664_UNKNOWN_DRAGONFLY) ||  defined(X8664_UNKNOWN_FREEBSD) ||  defined(X8664_UNKNOWN_HAIKU) ||  \
 defined(X8664_UNKNOWN_HERMIT) ||  defined(X8664_UNKNOWN_L4RE_UCLIBC) ||  defined(X8664_UNKNOWN_NETBSD) ||  defined(X8664_UNKNOWN_OPENBSD) ||  \
 defined(X8664_UNKNOWN_REDOX) 
_Static_assert(sizeof(Int) == 4, "record Int wrong sizeof");
_Static_assert(_Alignof(Int) == 8, "record Int wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Int_alignment) == 16, "record Int wrong sizeof");
_Static_assert(_Alignof(struct Int_alignment) == 8, "record Int wrong alignment");
_Static_assert(sizeof(struct Int_packed) == 4, "record Int wrong sizeof");
_Static_assert(_Alignof(struct Int_packed) == 1, "record Int wrong alignment");
_Static_assert(sizeof(struct Int_required_alignment) == 5, "record Int wrong sizeof");
_Static_assert(_Alignof(struct Int_required_alignment) == 1, "record Int wrong alignment");
_Static_assert(sizeof(struct Int_size) == 6, "record Int wrong sizeof");
_Static_assert(_Alignof(struct Int_size) == 1, "record Int wrong alignment");
#endif
_Static_assert(sizeof(X) == 8, "record X wrong sizeof");
_Static_assert(_Alignof(X) == 8, "record X wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct X_alignment) == 16, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_alignment) == 8, "record X wrong alignment");
_Static_assert(sizeof(struct X_packed) == 8, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_packed) == 1, "record X wrong alignment");
_Static_assert(sizeof(struct X_required_alignment) == 9, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_required_alignment) == 1, "record X wrong alignment");
_Static_assert(sizeof(struct X_size) == 10, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_size) == 1, "record X wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(X,j) == 1, "field X.j wrong bit offset");
#endif
#elif defined(AARCH64_PC_WINDOWS_MSVC) ||  defined(I586_PC_WINDOWS_MSVC) ||  defined(I686_PC_WINDOWS_MSVC) ||  defined(I686_UNKNOWN_WINDOWS) ||  \
 defined(THUMBV7A_PC_WINDOWS_MSVC) ||  defined(X8664_PC_WINDOWS_MSVC) ||  defined(X8664_UNKNOWN_WINDOWS) 
_Static_assert(sizeof(Int) == 4, "record Int wrong sizeof");
_Static_assert(_Alignof(Int) == 8, "record Int wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Int_alignment) == 16, "record Int wrong sizeof");
_Static_assert(_Alignof(struct Int_alignment) == 8, "record Int wrong alignment");
_Static_assert(sizeof(struct Int_packed) == 4, "record Int wrong sizeof");
_Static_assert(_Alignof(struct Int_packed) == 1, "record Int wrong alignment");
_Static_assert(sizeof(struct Int_required_alignment) == 5, "record Int wrong sizeof");
_Static_assert(_Alignof(struct Int_required_alignment) == 1, "record Int wrong alignment");
_Static_assert(sizeof(struct Int_size) == 6, "record Int wrong sizeof");
_Static_assert(_Alignof(struct Int_size) == 1, "record Int wrong alignment");
#endif
_Static_assert(sizeof(X) == 4, "record X wrong sizeof");
_Static_assert(_Alignof(X) == 4, "record X wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct X_alignment) == 8, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_alignment) == 4, "record X wrong alignment");
_Static_assert(sizeof(struct X_packed) == 4, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_packed) == 1, "record X wrong alignment");
_Static_assert(sizeof(struct X_required_alignment) == 5, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_required_alignment) == 1, "record X wrong alignment");
_Static_assert(sizeof(struct X_size) == 6, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_size) == 1, "record X wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(X,j) == 1, "field X.j wrong bit offset");
#endif
#elif defined(AARCH64_UNKNOWN_LINUX_GNU) ||  defined(AARCH64_UNKNOWN_LINUX_MUSL) ||  defined(ARM_UNKNOWN_LINUX_GNUEABI) ||  defined(ARM_UNKNOWN_LINUX_GNUEABIHF) ||  \
 defined(ARMV4T_UNKNOWN_LINUX_GNUEABI) ||  defined(ARMV5TE_UNKNOWN_LINUX_GNUEABI) ||  defined(ARMV5TE_UNKNOWN_LINUX_UCLIBCGNUEABI) ||  \
 defined(ARMV7_UNKNOWN_LINUX_GNUEABI) ||  defined(ARMV7_UNKNOWN_LINUX_GNUEABIHF) ||  defined(I586_UNKNOWN_LINUX_GNU) ||  defined(I586_UNKNOWN_LINUX_MUSL) ||  \
 defined(I686_UNKNOWN_LINUX_GNU) ||  defined(I686_UNKNOWN_LINUX_MUSL) ||  defined(MIPS64EL_UNKNOWN_LINUX_GNUABI64) ||  defined(MIPS64EL_UNKNOWN_LINUX_MUSL) ||  \
 defined(MIPS64_UNKNOWN_LINUX_GNUABI64) ||  defined(MIPS64_UNKNOWN_LINUX_MUSL) ||  defined(MIPSEL_UNKNOWN_LINUX_GNU) ||  defined(MIPSEL_UNKNOWN_LINUX_MUSL) ||  \
 defined(MIPSEL_UNKNOWN_LINUX_UCLIBC) ||  defined(MIPSISA32R6EL_UNKNOWN_LINUX_GNU) ||  defined(MIPSISA32R6_UNKNOWN_LINUX_GNU) ||  \
 defined(MIPSISA64R6EL_UNKNOWN_LINUX_GNUABI64) ||  defined(MIPSISA64R6_UNKNOWN_LINUX_GNUABI64) ||  defined(MIPS_UNKNOWN_LINUX_GNU) ||  \
 defined(MIPS_UNKNOWN_LINUX_MUSL) ||  defined(MIPS_UNKNOWN_LINUX_UCLIBC) ||  defined(POWERPC64LE_UNKNOWN_LINUX_GNU) ||  defined(POWERPC64LE_UNKNOWN_LINUX_MUSL) ||  \
 defined(POWERPC64_UNKNOWN_LINUX_GNU) ||  defined(POWERPC64_UNKNOWN_LINUX_MUSL) ||  defined(POWERPC_UNKNOWN_LINUX_GNU) ||  defined(POWERPC_UNKNOWN_LINUX_MUSL) ||  \
 defined(RISCV32_UNKNOWN_LINUX_GNU) ||  defined(RISCV64_UNKNOWN_LINUX_GNU) ||  defined(S390X_UNKNOWN_LINUX_GNU) ||  defined(SPARC64_UNKNOWN_LINUX_GNU) ||  \
 defined(SPARC_UNKNOWN_LINUX_GNU) ||  defined(X8664_UNKNOWN_LINUX_GNUX32) ||  defined(X8664_UNKNOWN_LINUX_GNU) ||  defined(X8664_UNKNOWN_LINUX_MUSL) 
_Static_assert(sizeof(Int) == 4, "record Int wrong sizeof");
_Static_assert(_Alignof(Int) == 8, "record Int wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Int_alignment) == 16, "record Int wrong sizeof");
_Static_assert(_Alignof(struct Int_alignment) == 8, "record Int wrong alignment");
_Static_assert(sizeof(struct Int_packed) == 4, "record Int wrong sizeof");
_Static_assert(_Alignof(struct Int_packed) == 1, "record Int wrong alignment");
_Static_assert(sizeof(struct Int_required_alignment) == 5, "record Int wrong sizeof");
_Static_assert(_Alignof(struct Int_required_alignment) == 1, "record Int wrong alignment");
_Static_assert(sizeof(struct Int_size) == 6, "record Int wrong sizeof");
_Static_assert(_Alignof(struct Int_size) == 1, "record Int wrong alignment");
#endif
_Static_assert(sizeof(X) == 16, "record X wrong sizeof");
_Static_assert(_Alignof(X) == 8, "record X wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct X_alignment) == 24, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_alignment) == 8, "record X wrong alignment");
_Static_assert(sizeof(struct X_packed) == 16, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_packed) == 1, "record X wrong alignment");
_Static_assert(sizeof(struct X_required_alignment) == 17, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_required_alignment) == 1, "record X wrong alignment");
_Static_assert(sizeof(struct X_size) == 18, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_size) == 1, "record X wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(X,j) == 64, "field X.j wrong bit offset");
#endif
#elif defined(ARMV7_APPLE_IOS) ||  defined(ARMV7S_APPLE_IOS) 
_Static_assert(sizeof(Int) == 4, "record Int wrong sizeof");
_Static_assert(_Alignof(Int) == 8, "record Int wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Int_alignment) == 16, "record Int wrong sizeof");
_Static_assert(_Alignof(struct Int_alignment) == 8, "record Int wrong alignment");
_Static_assert(sizeof(struct Int_packed) == 4, "record Int wrong sizeof");
_Static_assert(_Alignof(struct Int_packed) == 1, "record Int wrong alignment");
_Static_assert(sizeof(struct Int_required_alignment) == 5, "record Int wrong sizeof");
_Static_assert(_Alignof(struct Int_required_alignment) == 1, "record Int wrong alignment");
_Static_assert(sizeof(struct Int_size) == 6, "record Int wrong sizeof");
_Static_assert(_Alignof(struct Int_size) == 1, "record Int wrong alignment");
#endif
_Static_assert(sizeof(X) == 1, "record X wrong sizeof");
_Static_assert(_Alignof(X) == 1, "record X wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct X_alignment) == 2, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_alignment) == 1, "record X wrong alignment");
_Static_assert(sizeof(struct X_packed) == 1, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_packed) == 1, "record X wrong alignment");
_Static_assert(sizeof(struct X_required_alignment) == 2, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_required_alignment) == 1, "record X wrong alignment");
_Static_assert(sizeof(struct X_size) == 3, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_size) == 1, "record X wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(X,j) == 1, "field X.j wrong bit offset");
#endif
#elif defined(AVR_UNKNOWN_UNKNOWN) 
_Static_assert(sizeof(Int) == 2, "record Int wrong sizeof");
_Static_assert(_Alignof(Int) == 8, "record Int wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Int_alignment) == 16, "record Int wrong sizeof");
_Static_assert(_Alignof(struct Int_alignment) == 8, "record Int wrong alignment");
_Static_assert(sizeof(struct Int_packed) == 2, "record Int wrong sizeof");
_Static_assert(_Alignof(struct Int_packed) == 1, "record Int wrong alignment");
_Static_assert(sizeof(struct Int_required_alignment) == 3, "record Int wrong sizeof");
_Static_assert(_Alignof(struct Int_required_alignment) == 1, "record Int wrong alignment");
_Static_assert(sizeof(struct Int_size) == 4, "record Int wrong sizeof");
_Static_assert(_Alignof(struct Int_size) == 1, "record Int wrong alignment");
#endif
_Static_assert(sizeof(X) == 1, "record X wrong sizeof");
_Static_assert(_Alignof(X) == 1, "record X wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct X_alignment) == 2, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_alignment) == 1, "record X wrong alignment");
_Static_assert(sizeof(struct X_packed) == 1, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_packed) == 1, "record X wrong alignment");
_Static_assert(sizeof(struct X_required_alignment) == 2, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_required_alignment) == 1, "record X wrong alignment");
_Static_assert(sizeof(struct X_size) == 3, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_size) == 1, "record X wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(X,j) == 1, "field X.j wrong bit offset");
#endif
#elif defined(MSP430_NONE_ELF) 
_Static_assert(sizeof(Int) == 2, "record Int wrong sizeof");
_Static_assert(_Alignof(Int) == 8, "record Int wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Int_alignment) == 16, "record Int wrong sizeof");
_Static_assert(_Alignof(struct Int_alignment) == 8, "record Int wrong alignment");
_Static_assert(sizeof(struct Int_packed) == 2, "record Int wrong sizeof");
_Static_assert(_Alignof(struct Int_packed) == 1, "record Int wrong alignment");
_Static_assert(sizeof(struct Int_required_alignment) == 3, "record Int wrong sizeof");
_Static_assert(_Alignof(struct Int_required_alignment) == 1, "record Int wrong alignment");
_Static_assert(sizeof(struct Int_size) == 4, "record Int wrong sizeof");
_Static_assert(_Alignof(struct Int_size) == 1, "record Int wrong alignment");
#endif
_Static_assert(sizeof(X) == 8, "record X wrong sizeof");
_Static_assert(_Alignof(X) == 8, "record X wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct X_alignment) == 16, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_alignment) == 8, "record X wrong alignment");
_Static_assert(sizeof(struct X_packed) == 8, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_packed) == 1, "record X wrong alignment");
_Static_assert(sizeof(struct X_required_alignment) == 9, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_required_alignment) == 1, "record X wrong alignment");
_Static_assert(sizeof(struct X_size) == 10, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_size) == 1, "record X wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(X,j) == 1, "field X.j wrong bit offset");
#endif
#endif
