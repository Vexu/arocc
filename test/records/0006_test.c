// SPDX-License-Identifier: GPL-3.0-or-later

// This test file is auto-generated. do not edit.
// This file is a derivative work from the test files found
// in this repo : https://github.com/mahkoh/repr-c
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

// MAPPING|ONE|aarch64-generic-macos-none:Clang|aarch64-generic-fuchsia-gnu:Clang|aarch64-generic-linux-android:Clang|aarch64-generic-freebsd-gnu:Clang|aarch64-generic-hermit-eabi:Clang|aarch64-generic-netbsd-gnu:Clang|aarch64-generic-other-eabi:Clang|aarch64-generic-openbsd-gnu:Clang|aarch64-generic-ios-none:Clang|aarch64-generic-ios-macabi:Clang|aarch64-generic-tvos-none:Clang|arm-baseline-other-eabi:Clang|arm-baseline-other-eabihf:Clang|arm-arm1136j_s-freebsd-gnueabihf:Clang|arm-arm1136j_s-netbsd-eabihf:Clang|arm-baseline-other-eabi:Clang|arm-baseline-other-eabihf:Clang|arm-cortex_r4-linux-android:Clang|arm-cortex_r4-other-eabi:Clang|arm-cortex_r4-other-eabihf:Clang|arm-cortex_r4-freebsd-gnueabihf:Clang|arm-cortex_r4-netbsd-eabihf:Clang|hexagon-generic-linux-musl:Clang|i386-i386-ios-none:Clang|i386-i686-macos-none:Clang|i386-i686-linux-android:Clang|i386-i686-windows-gnu:Gcc|i386-i686-freebsd-gnu:Clang|i386-i686-haiku-gnu:Clang|i386-i686-netbsd-gnu:Clang|i386-i686-openbsd-gnu:Clang|mipsel-mips32-other-eabi:Clang|powerpc64-ppc64-freebsd-gnu:Clang|powerpc-ppc-netbsd-gnu:Clang|riscv32-baseline_rv32-other-eabi:Clang|riscv64-baseline_rv64-other-eabi:Clang|sparc64-v9-netbsd-gnu:Clang|sparc64-v9-openbsd-gnu:Clang|sparc-v9-solaris-eabi:Clang|thumb-arm710t-other-eabi:Clang|thumb-cortex_m0-other-eabi:Clang|thumb-cortex_m4-other-eabihf:Clang|thumb-cortex_m4-other-eabi:Clang|thumb-cortex_m3-other-eabi:Clang|thumb-baseline-other-eabi:Clang|thumb-cortex_m33-other-eabihf:Clang|thumb-cortex_m33-other-eabi:Clang|wasm32-generic-emscripten-musl:Clang|wasm32-generic-other-musl:Clang|wasm32-generic-wasi-musl:Clang|x86_64-x86_64-ios-macabi:Clang|x86_64-x86_64-ios-none:Clang|x86_64-x86_64-macos-none:Clang|x86_64-x86_64-tvos-none:Clang|x86_64-x86_64-other-eabi:Clang|x86_64-x86_64-fuchsia-gnu:Clang|x86_64-x86_64-linux-android:Clang|x86_64-x86_64-solaris-eabi:Clang|x86_64-x86_64-windows-gnu:Gcc|x86_64-x86_64-dragonfly-eabi:Clang|x86_64-x86_64-freebsd-gnu:Clang|x86_64-x86_64-haiku-gnu:Clang|x86_64-x86_64-hermit-eabi:Clang|x86_64-x86_64-netbsd-gnu:Clang|x86_64-x86_64-openbsd-gnu:Clang|END
// repr targets Aarch64AppleMacosx|Some("aarch64-generic-macos-none") Aarch64Fuchsia|Some("aarch64-generic-fuchsia-gnu") Aarch64LinuxAndroid|Some("aarch64-generic-linux-android") Aarch64UnknownFreebsd|Some("aarch64-generic-freebsd-gnu") Aarch64UnknownHermit|Some("aarch64-generic-hermit-eabi") Aarch64UnknownNetbsd|Some("aarch64-generic-netbsd-gnu") Aarch64UnknownNone|Some("aarch64-generic-other-eabi") Aarch64UnknownOpenbsd|Some("aarch64-generic-openbsd-gnu") Aarch64UnknownRedox|None Arm64AppleIos|Some("aarch64-generic-ios-none") Arm64AppleIosMacabi|Some("aarch64-generic-ios-macabi") Arm64AppleTvos|Some("aarch64-generic-tvos-none") Armebv7rUnknownNoneEabi|Some("arm-baseline-other-eabi") Armebv7rUnknownNoneEabihf|Some("arm-baseline-other-eabihf") ArmLinuxAndroideabi|None Armv6UnknownFreebsdGnueabihf|Some("arm-arm1136j_s-freebsd-gnueabihf") Armv6UnknownNetbsdelfEabihf|Some("arm-arm1136j_s-netbsd-eabihf") Armv7aNoneEabi|Some("arm-baseline-other-eabi") Armv7aNoneEabihf|Some("arm-baseline-other-eabihf") Armv7NoneLinuxAndroid|Some("arm-cortex_r4-linux-android") Armv7rUnknownNoneEabi|Some("arm-cortex_r4-other-eabi") Armv7rUnknownNoneEabihf|Some("arm-cortex_r4-other-eabihf") Armv7UnknownFreebsdGnueabihf|Some("arm-cortex_r4-freebsd-gnueabihf") Armv7UnknownNetbsdelfEabihf|Some("arm-cortex_r4-netbsd-eabihf") HexagonUnknownLinuxMusl|Some("hexagon-generic-linux-musl") I386AppleIos|Some("i386-i386-ios-none") I686AppleMacosx|Some("i386-i686-macos-none") I686LinuxAndroid|Some("i386-i686-linux-android") I686PcWindowsGnu|Some("i386-i686-windows-gnu") I686UnknownFreebsd|Some("i386-i686-freebsd-gnu") I686UnknownHaiku|Some("i386-i686-haiku-gnu") I686UnknownNetbsdelf|Some("i386-i686-netbsd-gnu") I686UnknownOpenbsd|Some("i386-i686-openbsd-gnu") MipselSonyPsp|None MipselUnknownNone|Some("mipsel-mips32-other-eabi") Powerpc64UnknownFreebsd|Some("powerpc64-ppc64-freebsd-gnu") PowerpcUnknownLinuxGnuspe|None PowerpcUnknownNetbsd|Some("powerpc-ppc-netbsd-gnu") Riscv32|Some("riscv32-baseline_rv32-other-eabi") Riscv64|Some("riscv64-baseline_rv64-other-eabi") Sparc64UnknownNetbsd|Some("sparc64-v9-netbsd-gnu") Sparc64UnknownOpenbsd|Some("sparc64-v9-openbsd-gnu") Sparcv9SunSolaris|Some("sparc-v9-solaris-eabi") Thumbv4tNoneEabi|Some("thumb-arm710t-other-eabi") Thumbv6mNoneEabi|Some("thumb-cortex_m0-other-eabi") Thumbv7emNoneEabihf|Some("thumb-cortex_m4-other-eabihf") Thumbv7emNoneEabi|Some("thumb-cortex_m4-other-eabi") Thumbv7mNoneEabi|Some("thumb-cortex_m3-other-eabi") Thumbv8mBaseNoneEabi|Some("thumb-baseline-other-eabi") Thumbv8mMainNoneEabihf|Some("thumb-cortex_m33-other-eabihf") Thumbv8mMainNoneEabi|Some("thumb-cortex_m33-other-eabi") Wasm32UnknownEmscripten|Some("wasm32-generic-emscripten-musl") Wasm32UnknownUnknown|Some("wasm32-generic-other-musl") Wasm32Wasi|Some("wasm32-generic-wasi-musl") X86_64AppleIosMacabi|Some("x86_64-x86_64-ios-macabi") X86_64AppleIos|Some("x86_64-x86_64-ios-none") X86_64AppleMacosx|Some("x86_64-x86_64-macos-none") X86_64AppleTvos|Some("x86_64-x86_64-tvos-none") X86_64Elf|Some("x86_64-x86_64-other-eabi") X86_64Fuchsia|Some("x86_64-x86_64-fuchsia-gnu") X86_64LinuxAndroid|Some("x86_64-x86_64-linux-android") X86_64PcSolaris|Some("x86_64-x86_64-solaris-eabi") X86_64PcWindowsGnu|Some("x86_64-x86_64-windows-gnu") X86_64RumprunNetbsd|None X86_64UnknownDragonfly|Some("x86_64-x86_64-dragonfly-eabi") X86_64UnknownFreebsd|Some("x86_64-x86_64-freebsd-gnu") X86_64UnknownHaiku|Some("x86_64-x86_64-haiku-gnu") X86_64UnknownHermit|Some("x86_64-x86_64-hermit-eabi") X86_64UnknownL4reUclibc|None X86_64UnknownNetbsd|Some("x86_64-x86_64-netbsd-gnu") X86_64UnknownOpenbsd|Some("x86_64-x86_64-openbsd-gnu") X86_64UnknownRedox|None 
#ifdef ONE
_Static_assert(sizeof(Int) == 4, "");
_Static_assert(_Alignof(Int) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Int_alignment) == 16, "");
_Static_assert(_Alignof(struct Int_alignment) == 8, "");
_Static_assert(sizeof(struct Int_packed) == 4, "");
_Static_assert(_Alignof(struct Int_packed) == 1, "");
_Static_assert(sizeof(struct Int_required_alignment) == 5, "");
_Static_assert(_Alignof(struct Int_required_alignment) == 1, "");
_Static_assert(sizeof(struct Int_size) == 6, "");
_Static_assert(_Alignof(struct Int_size) == 1, "");
#endif
_Static_assert(sizeof(X) == 8, "");
_Static_assert(_Alignof(X) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct X_alignment) == 16, "");
_Static_assert(_Alignof(struct X_alignment) == 8, "");
_Static_assert(sizeof(struct X_packed) == 8, "");
_Static_assert(_Alignof(struct X_packed) == 1, "");
_Static_assert(sizeof(struct X_required_alignment) == 9, "");
_Static_assert(_Alignof(struct X_required_alignment) == 1, "");
_Static_assert(sizeof(struct X_size) == 10, "");
_Static_assert(_Alignof(struct X_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(X,j) == 1, "");
#endif
// MAPPING|TWO|aarch64-generic-windows-msvc:Msvc|i386-i586-windows-msvc:Msvc|i386-i686-windows-msvc:Msvc|i386-i686-uefi-msvc:Msvc|thumb-baseline-windows-msvc:Msvc|x86_64-x86_64-windows-msvc:Msvc|x86_64-x86_64-uefi-msvc:Msvc|END
// repr targets Aarch64PcWindowsMsvc|Some("aarch64-generic-windows-msvc") I586PcWindowsMsvc|Some("i386-i586-windows-msvc") I686PcWindowsMsvc|Some("i386-i686-windows-msvc") I686UnknownWindows|Some("i386-i686-uefi-msvc") Thumbv7aPcWindowsMsvc|Some("thumb-baseline-windows-msvc") X86_64PcWindowsMsvc|Some("x86_64-x86_64-windows-msvc") X86_64UnknownWindows|Some("x86_64-x86_64-uefi-msvc") 
#elif defined(TWO)
_Static_assert(sizeof(Int) == 4, "");
_Static_assert(_Alignof(Int) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Int_alignment) == 16, "");
_Static_assert(_Alignof(struct Int_alignment) == 8, "");
_Static_assert(sizeof(struct Int_packed) == 4, "");
_Static_assert(_Alignof(struct Int_packed) == 1, "");
_Static_assert(sizeof(struct Int_required_alignment) == 5, "");
_Static_assert(_Alignof(struct Int_required_alignment) == 1, "");
_Static_assert(sizeof(struct Int_size) == 6, "");
_Static_assert(_Alignof(struct Int_size) == 1, "");
#endif
_Static_assert(sizeof(X) == 4, "");
_Static_assert(_Alignof(X) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct X_alignment) == 8, "");
_Static_assert(_Alignof(struct X_alignment) == 4, "");
_Static_assert(sizeof(struct X_packed) == 4, "");
_Static_assert(_Alignof(struct X_packed) == 1, "");
_Static_assert(sizeof(struct X_required_alignment) == 5, "");
_Static_assert(_Alignof(struct X_required_alignment) == 1, "");
_Static_assert(sizeof(struct X_size) == 6, "");
_Static_assert(_Alignof(struct X_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(X,j) == 1, "");
#endif
// MAPPING|THREE|aarch64-generic-linux-gnu:Gcc|aarch64-generic-linux-musl:Gcc|arm-baseline-linux-gnueabi:Gcc|arm-baseline-linux-gnueabihf:Gcc|arm-arm710t-linux-gnueabi:Gcc|arm-arm1020e-linux-gnueabi:Gcc|arm-cortex_r4-linux-gnueabi:Gcc|arm-cortex_r4-linux-gnueabihf:Gcc|i386-i586-linux-gnu:Gcc|i386-i586-linux-musl:Gcc|i386-i686-linux-gnu:Gcc|i386-i686-linux-musl:Gcc|mips64el-mips64-linux-gnuabi64:Gcc|mips64el-mips64-linux-musl:Gcc|mips64-mips64-linux-gnuabi64:Gcc|mips64-mips64-linux-musl:Gcc|mipsel-mips32-linux-gnu:Gcc|mipsel-mips32-linux-musl:Gcc|mips-mips32-linux-gnu:Gcc|mips-mips32r6-linux-gnu:Gcc|mips-mips32-linux-gnuabi64:Gcc|mips-mips64r6-linux-gnuabi64:Gcc|mips-mips32-linux-gnu:Gcc|mips-mips32-linux-musl:Gcc|powerpc64le-ppc64le-linux-gnu:Gcc|powerpc64le-ppc64le-linux-musl:Gcc|powerpc64-ppc64-linux-gnu:Gcc|powerpc64-ppc64-linux-musl:Gcc|powerpc-ppc-linux-gnu:Gcc|powerpc-ppc-linux-musl:Gcc|riscv32-baseline_rv32-linux-gnu:Gcc|riscv64-baseline_rv64-linux-gnu:Gcc|s390x-generic-linux-gnu:Gcc|sparc64-v9-linux-gnu:Gcc|sparc-v8-linux-gnu:Gcc|x86_64-x86_64-linux-gnux32:Gcc|x86_64-x86_64-linux-gnu:Gcc|x86_64-x86_64-linux-musl:Gcc|END
// repr targets Aarch64UnknownLinuxGnu|Some("aarch64-generic-linux-gnu") Aarch64UnknownLinuxMusl|Some("aarch64-generic-linux-musl") ArmUnknownLinuxGnueabi|Some("arm-baseline-linux-gnueabi") ArmUnknownLinuxGnueabihf|Some("arm-baseline-linux-gnueabihf") Armv4tUnknownLinuxGnueabi|Some("arm-arm710t-linux-gnueabi") Armv5teUnknownLinuxGnueabi|Some("arm-arm1020e-linux-gnueabi") Armv5teUnknownLinuxUclibcgnueabi|None Armv7UnknownLinuxGnueabi|Some("arm-cortex_r4-linux-gnueabi") Armv7UnknownLinuxGnueabihf|Some("arm-cortex_r4-linux-gnueabihf") I586UnknownLinuxGnu|Some("i386-i586-linux-gnu") I586UnknownLinuxMusl|Some("i386-i586-linux-musl") I686UnknownLinuxGnu|Some("i386-i686-linux-gnu") I686UnknownLinuxMusl|Some("i386-i686-linux-musl") Mips64elUnknownLinuxGnuabi64|Some("mips64el-mips64-linux-gnuabi64") Mips64elUnknownLinuxMusl|Some("mips64el-mips64-linux-musl") Mips64UnknownLinuxGnuabi64|Some("mips64-mips64-linux-gnuabi64") Mips64UnknownLinuxMusl|Some("mips64-mips64-linux-musl") MipselUnknownLinuxGnu|Some("mipsel-mips32-linux-gnu") MipselUnknownLinuxMusl|Some("mipsel-mips32-linux-musl") MipselUnknownLinuxUclibc|None Mipsisa32r6elUnknownLinuxGnu|Some("mips-mips32-linux-gnu") Mipsisa32r6UnknownLinuxGnu|Some("mips-mips32r6-linux-gnu") Mipsisa64r6elUnknownLinuxGnuabi64|Some("mips-mips32-linux-gnuabi64") Mipsisa64r6UnknownLinuxGnuabi64|Some("mips-mips64r6-linux-gnuabi64") MipsUnknownLinuxGnu|Some("mips-mips32-linux-gnu") MipsUnknownLinuxMusl|Some("mips-mips32-linux-musl") MipsUnknownLinuxUclibc|None Powerpc64leUnknownLinuxGnu|Some("powerpc64le-ppc64le-linux-gnu") Powerpc64leUnknownLinuxMusl|Some("powerpc64le-ppc64le-linux-musl") Powerpc64UnknownLinuxGnu|Some("powerpc64-ppc64-linux-gnu") Powerpc64UnknownLinuxMusl|Some("powerpc64-ppc64-linux-musl") PowerpcUnknownLinuxGnu|Some("powerpc-ppc-linux-gnu") PowerpcUnknownLinuxMusl|Some("powerpc-ppc-linux-musl") Riscv32UnknownLinuxGnu|Some("riscv32-baseline_rv32-linux-gnu") Riscv64UnknownLinuxGnu|Some("riscv64-baseline_rv64-linux-gnu") S390xUnknownLinuxGnu|Some("s390x-generic-linux-gnu") Sparc64UnknownLinuxGnu|Some("sparc64-v9-linux-gnu") SparcUnknownLinuxGnu|Some("sparc-v8-linux-gnu") X86_64UnknownLinuxGnux32|Some("x86_64-x86_64-linux-gnux32") X86_64UnknownLinuxGnu|Some("x86_64-x86_64-linux-gnu") X86_64UnknownLinuxMusl|Some("x86_64-x86_64-linux-musl") 
#elif defined(THREE)
_Static_assert(sizeof(Int) == 4, "");
_Static_assert(_Alignof(Int) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Int_alignment) == 16, "");
_Static_assert(_Alignof(struct Int_alignment) == 8, "");
_Static_assert(sizeof(struct Int_packed) == 4, "");
_Static_assert(_Alignof(struct Int_packed) == 1, "");
_Static_assert(sizeof(struct Int_required_alignment) == 5, "");
_Static_assert(_Alignof(struct Int_required_alignment) == 1, "");
_Static_assert(sizeof(struct Int_size) == 6, "");
_Static_assert(_Alignof(struct Int_size) == 1, "");
#endif
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
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(X,j) == 64, "");
#endif
// MAPPING|FOUR|arm-cortex_r4-ios-none:Clang|arm-baseline-ios-none:Clang|END
// repr targets Armv7AppleIos|Some("arm-cortex_r4-ios-none") Armv7sAppleIos|Some("arm-baseline-ios-none") 
#elif defined(FOUR)
_Static_assert(sizeof(Int) == 4, "");
_Static_assert(_Alignof(Int) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Int_alignment) == 16, "");
_Static_assert(_Alignof(struct Int_alignment) == 8, "");
_Static_assert(sizeof(struct Int_packed) == 4, "");
_Static_assert(_Alignof(struct Int_packed) == 1, "");
_Static_assert(sizeof(struct Int_required_alignment) == 5, "");
_Static_assert(_Alignof(struct Int_required_alignment) == 1, "");
_Static_assert(sizeof(struct Int_size) == 6, "");
_Static_assert(_Alignof(struct Int_size) == 1, "");
#endif
_Static_assert(sizeof(X) == 1, "");
_Static_assert(_Alignof(X) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct X_alignment) == 2, "");
_Static_assert(_Alignof(struct X_alignment) == 1, "");
_Static_assert(sizeof(struct X_packed) == 1, "");
_Static_assert(_Alignof(struct X_packed) == 1, "");
_Static_assert(sizeof(struct X_required_alignment) == 2, "");
_Static_assert(_Alignof(struct X_required_alignment) == 1, "");
_Static_assert(sizeof(struct X_size) == 3, "");
_Static_assert(_Alignof(struct X_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(X,j) == 1, "");
#endif
// MAPPING|FIVE|avr-avr2-other-eabi:Gcc|END
// repr targets AvrUnknownUnknown|Some("avr-avr2-other-eabi") 
#elif defined(FIVE)
_Static_assert(sizeof(Int) == 2, "");
_Static_assert(_Alignof(Int) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Int_alignment) == 16, "");
_Static_assert(_Alignof(struct Int_alignment) == 8, "");
_Static_assert(sizeof(struct Int_packed) == 2, "");
_Static_assert(_Alignof(struct Int_packed) == 1, "");
_Static_assert(sizeof(struct Int_required_alignment) == 3, "");
_Static_assert(_Alignof(struct Int_required_alignment) == 1, "");
_Static_assert(sizeof(struct Int_size) == 4, "");
_Static_assert(_Alignof(struct Int_size) == 1, "");
#endif
_Static_assert(sizeof(X) == 1, "");
_Static_assert(_Alignof(X) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct X_alignment) == 2, "");
_Static_assert(_Alignof(struct X_alignment) == 1, "");
_Static_assert(sizeof(struct X_packed) == 1, "");
_Static_assert(_Alignof(struct X_packed) == 1, "");
_Static_assert(sizeof(struct X_required_alignment) == 2, "");
_Static_assert(_Alignof(struct X_required_alignment) == 1, "");
_Static_assert(sizeof(struct X_size) == 3, "");
_Static_assert(_Alignof(struct X_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(X,j) == 1, "");
#endif
// MAPPING|SIX|msp430-msp430-other-eabi:Clang|END
// repr targets Msp430NoneElf|Some("msp430-msp430-other-eabi") 
#elif defined(SIX)
_Static_assert(sizeof(Int) == 2, "");
_Static_assert(_Alignof(Int) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Int_alignment) == 16, "");
_Static_assert(_Alignof(struct Int_alignment) == 8, "");
_Static_assert(sizeof(struct Int_packed) == 2, "");
_Static_assert(_Alignof(struct Int_packed) == 1, "");
_Static_assert(sizeof(struct Int_required_alignment) == 3, "");
_Static_assert(_Alignof(struct Int_required_alignment) == 1, "");
_Static_assert(sizeof(struct Int_size) == 4, "");
_Static_assert(_Alignof(struct Int_size) == 1, "");
#endif
_Static_assert(sizeof(X) == 8, "");
_Static_assert(_Alignof(X) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct X_alignment) == 16, "");
_Static_assert(_Alignof(struct X_alignment) == 8, "");
_Static_assert(sizeof(struct X_packed) == 8, "");
_Static_assert(_Alignof(struct X_packed) == 1, "");
_Static_assert(sizeof(struct X_required_alignment) == 9, "");
_Static_assert(_Alignof(struct X_required_alignment) == 1, "");
_Static_assert(sizeof(struct X_size) == 10, "");
_Static_assert(_Alignof(struct X_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(X,j) == 1, "");
#endif
#endif
