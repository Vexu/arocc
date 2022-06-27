// SPDX-License-Identifier: GPL-3.0-or-later

// This test file is auto-generated. do not edit.
// This file is a derivative work from the test files found// in this repo : https://github.com/mahkoh/repr-c
// and is under the same licence as the original work.

typedef __int128 X;
X var1;
struct X_alignment {
    char a;
    X b;
};
struct X_alignment var2;
#pragma pack(1)
struct X_packed {
    X a;
};
#pragma pack()
struct X_required_alignment {
    char a;
    struct X_packed b;
};
struct X_required_alignment var3;
struct X_size {
    char a[sizeof(X)+1];
    char b;
};
struct X_size var4;

typedef unsigned __int128 Y;
Y var5;
struct Y_alignment {
    char a;
    Y b;
};
struct Y_alignment var6;
#pragma pack(1)
struct Y_packed {
    Y a;
};
#pragma pack()
struct Y_required_alignment {
    char a;
    struct Y_packed b;
};
struct Y_required_alignment var7;
struct Y_size {
    char a[sizeof(Y)+1];
    char b;
};
struct Y_size var8;


#if defined(AARCH64_APPLE_MACOSX) ||  defined(AARCH64_FUCHSIA) ||  defined(AARCH64_LINUX_ANDROID) ||  defined(AARCH64_UNKNOWN_FREEBSD) ||  \
 defined(AARCH64_UNKNOWN_HERMIT) ||  defined(AARCH64_UNKNOWN_LINUX_GNU) ||  defined(AARCH64_UNKNOWN_LINUX_MUSL) ||  defined(AARCH64_UNKNOWN_NETBSD) ||  \
 defined(AARCH64_UNKNOWN_NONE) ||  defined(AARCH64_UNKNOWN_OPENBSD) ||  defined(AARCH64_UNKNOWN_REDOX) ||  defined(ARM64_APPLE_IOS) ||  \
 defined(ARM64_APPLE_IOS_MACABI) ||  defined(ARM64_APPLE_TVOS) ||  defined(MIPS64EL_UNKNOWN_LINUX_GNUABI64) ||  defined(MIPS64EL_UNKNOWN_LINUX_MUSL) ||  \
 defined(MIPS64_UNKNOWN_LINUX_GNUABI64) ||  defined(MIPS64_UNKNOWN_LINUX_MUSL) ||  defined(MIPSISA64R6EL_UNKNOWN_LINUX_GNUABI64) ||  \
 defined(MIPSISA64R6_UNKNOWN_LINUX_GNUABI64) ||  defined(POWERPC64LE_UNKNOWN_LINUX_GNU) ||  defined(POWERPC64LE_UNKNOWN_LINUX_MUSL) ||  \
 defined(POWERPC64_UNKNOWN_FREEBSD) ||  defined(POWERPC64_UNKNOWN_LINUX_GNU) ||  defined(POWERPC64_UNKNOWN_LINUX_MUSL) ||  defined(RISCV64) ||  \
 defined(RISCV64_UNKNOWN_LINUX_GNU) ||  defined(SPARC64_UNKNOWN_LINUX_GNU) ||  defined(SPARC64_UNKNOWN_NETBSD) ||  defined(SPARC64_UNKNOWN_OPENBSD) ||  \
 defined(SPARCV9_SUN_SOLARIS) ||  defined(WASM32_UNKNOWN_EMSCRIPTEN) ||  defined(WASM32_UNKNOWN_UNKNOWN) ||  defined(WASM32_WASI) ||  \
 defined(X8664_APPLE_IOS_MACABI) ||  defined(X8664_APPLE_IOS) ||  defined(X8664_APPLE_MACOSX) ||  defined(X8664_APPLE_TVOS) ||  defined(X8664_ELF) ||  \
 defined(X8664_FUCHSIA) ||  defined(X8664_LINUX_ANDROID) ||  defined(X8664_PC_SOLARIS) ||  defined(X8664_PC_WINDOWS_GNU) ||  defined(X8664_RUMPRUN_NETBSD) ||  \
 defined(X8664_UNKNOWN_DRAGONFLY) ||  defined(X8664_UNKNOWN_FREEBSD) ||  defined(X8664_UNKNOWN_HAIKU) ||  defined(X8664_UNKNOWN_HERMIT) ||  \
 defined(X8664_UNKNOWN_L4RE_UCLIBC) ||  defined(X8664_UNKNOWN_LINUX_GNUX32) ||  defined(X8664_UNKNOWN_LINUX_GNU) ||  defined(X8664_UNKNOWN_LINUX_MUSL) ||  \
 defined(X8664_UNKNOWN_NETBSD) ||  defined(X8664_UNKNOWN_OPENBSD) ||  defined(X8664_UNKNOWN_REDOX) 
_Static_assert(sizeof(X) == 16, "record X wrong sizeof");
_Static_assert(_Alignof(X) == 16, "record X wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct X_alignment) == 32, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_alignment) == 16, "record X wrong alignment");
_Static_assert(sizeof(struct X_packed) == 16, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_packed) == 1, "record X wrong alignment");
_Static_assert(sizeof(struct X_required_alignment) == 17, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_required_alignment) == 1, "record X wrong alignment");
_Static_assert(sizeof(struct X_size) == 18, "record X wrong sizeof");
_Static_assert(_Alignof(struct X_size) == 1, "record X wrong alignment");
#endif
_Static_assert(sizeof(Y) == 16, "record Y wrong sizeof");
_Static_assert(_Alignof(Y) == 16, "record Y wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Y_alignment) == 32, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_alignment) == 16, "record Y wrong alignment");
_Static_assert(sizeof(struct Y_packed) == 16, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_packed) == 1, "record Y wrong alignment");
_Static_assert(sizeof(struct Y_required_alignment) == 17, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_required_alignment) == 1, "record Y wrong alignment");
_Static_assert(sizeof(struct Y_size) == 18, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_size) == 1, "record Y wrong alignment");
#endif
#elif defined(S390X_UNKNOWN_LINUX_GNU) 
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
_Static_assert(sizeof(Y) == 16, "record Y wrong sizeof");
_Static_assert(_Alignof(Y) == 8, "record Y wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Y_alignment) == 24, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_alignment) == 8, "record Y wrong alignment");
_Static_assert(sizeof(struct Y_packed) == 16, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_packed) == 1, "record Y wrong alignment");
_Static_assert(sizeof(struct Y_required_alignment) == 17, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_required_alignment) == 1, "record Y wrong alignment");
_Static_assert(sizeof(struct Y_size) == 18, "record Y wrong sizeof");
_Static_assert(_Alignof(struct Y_size) == 1, "record Y wrong alignment");
#endif
#endif
