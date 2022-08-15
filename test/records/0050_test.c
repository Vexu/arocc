// SPDX-License-Identifier: GPL-3.0-or-later

// This test file is auto-generated. do not edit.
// This file is a derivative work from the test files found
// in this repo : https://github.com/mahkoh/repr-c
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


// MAPPING|ONE|aarch64-generic-macos-none:Clang|aarch64-generic-fuchsia-gnu:Clang|aarch64-generic-linux-android:Clang|aarch64-generic-freebsd-gnu:Clang|aarch64-generic-hermit-eabi:Clang|aarch64-generic-linux-gnu:Gcc|aarch64-generic-linux-musl:Gcc|aarch64-generic-netbsd-gnu:Clang|aarch64-generic-other-eabi:Clang|aarch64-generic-openbsd-gnu:Clang|aarch64-generic-ios-none:Clang|aarch64-generic-ios-macabi:Clang|aarch64-generic-tvos-none:Clang|mips64el-mips64-linux-gnuabi64:Gcc|mips64el-mips64-linux-musl:Gcc|mips64-mips64-linux-gnuabi64:Gcc|mips64-mips64-linux-musl:Gcc|mips-mips32-linux-gnuabi64:Gcc|mips-mips64r6-linux-gnuabi64:Gcc|powerpc64le-ppc64le-linux-gnu:Gcc|powerpc64le-ppc64le-linux-musl:Gcc|powerpc64-ppc64-freebsd-gnu:Clang|powerpc64-ppc64-linux-gnu:Gcc|powerpc64-ppc64-linux-musl:Gcc|riscv64-baseline_rv64-other-eabi:Clang|riscv64-baseline_rv64-linux-gnu:Gcc|sparc64-v9-linux-gnu:Gcc|sparc64-v9-netbsd-gnu:Clang|sparc64-v9-openbsd-gnu:Clang|sparc-v9-solaris-eabi:Clang|wasm32-generic-emscripten-musl:Clang|wasm32-generic-other-musl:Clang|wasm32-generic-wasi-musl:Clang|x86_64-x86_64-ios-macabi:Clang|x86_64-x86_64-ios-none:Clang|x86_64-x86_64-macos-none:Clang|x86_64-x86_64-tvos-none:Clang|x86_64-x86_64-other-eabi:Clang|x86_64-x86_64-fuchsia-gnu:Clang|x86_64-x86_64-linux-android:Clang|x86_64-x86_64-solaris-eabi:Clang|x86_64-x86_64-windows-gnu:Gcc|x86_64-x86_64-dragonfly-eabi:Clang|x86_64-x86_64-freebsd-gnu:Clang|x86_64-x86_64-haiku-gnu:Clang|x86_64-x86_64-hermit-eabi:Clang|x86_64-x86_64-linux-gnux32:Gcc|x86_64-x86_64-linux-gnu:Gcc|x86_64-x86_64-linux-musl:Gcc|x86_64-x86_64-netbsd-gnu:Clang|x86_64-x86_64-openbsd-gnu:Clang|END
// repr targets Aarch64AppleMacosx|Some("aarch64-generic-macos-none") Aarch64Fuchsia|Some("aarch64-generic-fuchsia-gnu") Aarch64LinuxAndroid|Some("aarch64-generic-linux-android") Aarch64UnknownFreebsd|Some("aarch64-generic-freebsd-gnu") Aarch64UnknownHermit|Some("aarch64-generic-hermit-eabi") Aarch64UnknownLinuxGnu|Some("aarch64-generic-linux-gnu") Aarch64UnknownLinuxMusl|Some("aarch64-generic-linux-musl") Aarch64UnknownNetbsd|Some("aarch64-generic-netbsd-gnu") Aarch64UnknownNone|Some("aarch64-generic-other-eabi") Aarch64UnknownOpenbsd|Some("aarch64-generic-openbsd-gnu") Aarch64UnknownRedox|None Arm64AppleIos|Some("aarch64-generic-ios-none") Arm64AppleIosMacabi|Some("aarch64-generic-ios-macabi") Arm64AppleTvos|Some("aarch64-generic-tvos-none") Mips64elUnknownLinuxGnuabi64|Some("mips64el-mips64-linux-gnuabi64") Mips64elUnknownLinuxMusl|Some("mips64el-mips64-linux-musl") Mips64UnknownLinuxGnuabi64|Some("mips64-mips64-linux-gnuabi64") Mips64UnknownLinuxMusl|Some("mips64-mips64-linux-musl") Mipsisa64r6elUnknownLinuxGnuabi64|Some("mips-mips32-linux-gnuabi64") Mipsisa64r6UnknownLinuxGnuabi64|Some("mips-mips64r6-linux-gnuabi64") Powerpc64leUnknownLinuxGnu|Some("powerpc64le-ppc64le-linux-gnu") Powerpc64leUnknownLinuxMusl|Some("powerpc64le-ppc64le-linux-musl") Powerpc64UnknownFreebsd|Some("powerpc64-ppc64-freebsd-gnu") Powerpc64UnknownLinuxGnu|Some("powerpc64-ppc64-linux-gnu") Powerpc64UnknownLinuxMusl|Some("powerpc64-ppc64-linux-musl") Riscv64|Some("riscv64-baseline_rv64-other-eabi") Riscv64UnknownLinuxGnu|Some("riscv64-baseline_rv64-linux-gnu") Sparc64UnknownLinuxGnu|Some("sparc64-v9-linux-gnu") Sparc64UnknownNetbsd|Some("sparc64-v9-netbsd-gnu") Sparc64UnknownOpenbsd|Some("sparc64-v9-openbsd-gnu") Sparcv9SunSolaris|Some("sparc-v9-solaris-eabi") Wasm32UnknownEmscripten|Some("wasm32-generic-emscripten-musl") Wasm32UnknownUnknown|Some("wasm32-generic-other-musl") Wasm32Wasi|Some("wasm32-generic-wasi-musl") X86_64AppleIosMacabi|Some("x86_64-x86_64-ios-macabi") X86_64AppleIos|Some("x86_64-x86_64-ios-none") X86_64AppleMacosx|Some("x86_64-x86_64-macos-none") X86_64AppleTvos|Some("x86_64-x86_64-tvos-none") X86_64Elf|Some("x86_64-x86_64-other-eabi") X86_64Fuchsia|Some("x86_64-x86_64-fuchsia-gnu") X86_64LinuxAndroid|Some("x86_64-x86_64-linux-android") X86_64PcSolaris|Some("x86_64-x86_64-solaris-eabi") X86_64PcWindowsGnu|Some("x86_64-x86_64-windows-gnu") X86_64RumprunNetbsd|None X86_64UnknownDragonfly|Some("x86_64-x86_64-dragonfly-eabi") X86_64UnknownFreebsd|Some("x86_64-x86_64-freebsd-gnu") X86_64UnknownHaiku|Some("x86_64-x86_64-haiku-gnu") X86_64UnknownHermit|Some("x86_64-x86_64-hermit-eabi") X86_64UnknownL4reUclibc|None X86_64UnknownLinuxGnux32|Some("x86_64-x86_64-linux-gnux32") X86_64UnknownLinuxGnu|Some("x86_64-x86_64-linux-gnu") X86_64UnknownLinuxMusl|Some("x86_64-x86_64-linux-musl") X86_64UnknownNetbsd|Some("x86_64-x86_64-netbsd-gnu") X86_64UnknownOpenbsd|Some("x86_64-x86_64-openbsd-gnu") X86_64UnknownRedox|None 
#ifdef ONE
_Static_assert(sizeof(X) == 16, "");
_Static_assert(_Alignof(X) == 16, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct X_alignment) == 32, "");
_Static_assert(_Alignof(struct X_alignment) == 16, "");
_Static_assert(sizeof(struct X_packed) == 16, "");
_Static_assert(_Alignof(struct X_packed) == 1, "");
_Static_assert(sizeof(struct X_required_alignment) == 17, "");
_Static_assert(_Alignof(struct X_required_alignment) == 1, "");
_Static_assert(sizeof(struct X_size) == 18, "");
_Static_assert(_Alignof(struct X_size) == 1, "");
#endif
_Static_assert(sizeof(Y) == 16, "");
_Static_assert(_Alignof(Y) == 16, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Y_alignment) == 32, "");
_Static_assert(_Alignof(struct Y_alignment) == 16, "");
_Static_assert(sizeof(struct Y_packed) == 16, "");
_Static_assert(_Alignof(struct Y_packed) == 1, "");
_Static_assert(sizeof(struct Y_required_alignment) == 17, "");
_Static_assert(_Alignof(struct Y_required_alignment) == 1, "");
_Static_assert(sizeof(struct Y_size) == 18, "");
_Static_assert(_Alignof(struct Y_size) == 1, "");
#endif
// MAPPING|TWO|s390x-generic-linux-gnu:Gcc|END
// repr targets S390xUnknownLinuxGnu|Some("s390x-generic-linux-gnu") 
#elif defined(TWO)
_Static_assert(sizeof(X) == 16, "");
_Static_assert(_Alignof(X) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct X_alignment) == 24, "");
_Static_assert(_Alignof(struct X_alignment) == 8, "");
_Static_assert(sizeof(struct X_packed) == 16, "");
_Static_assert(_Alignof(struct X_packed) == 1, "");
_Static_assert(sizeof(struct X_required_alignment) == 17, "");
_Static_assert(_Alignof(struct X_required_alignment) == 1, "");
_Static_assert(sizeof(struct X_size) == 18, "");
_Static_assert(_Alignof(struct X_size) == 1, "");
#endif
_Static_assert(sizeof(Y) == 16, "");
_Static_assert(_Alignof(Y) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Y_alignment) == 24, "");
_Static_assert(_Alignof(struct Y_alignment) == 8, "");
_Static_assert(sizeof(struct Y_packed) == 16, "");
_Static_assert(_Alignof(struct Y_packed) == 1, "");
_Static_assert(sizeof(struct Y_required_alignment) == 17, "");
_Static_assert(_Alignof(struct Y_required_alignment) == 1, "");
_Static_assert(sizeof(struct Y_size) == 18, "");
_Static_assert(_Alignof(struct Y_size) == 1, "");
#endif
#endif
