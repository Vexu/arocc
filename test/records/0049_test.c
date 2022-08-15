// SPDX-License-Identifier: GPL-3.0-or-later

// This test file is auto-generated. do not edit.
// This file is a derivative work from the test files found
// in this repo : https://github.com/mahkoh/repr-c
// and is under the same licence as the original work.

typedef struct {
    char c:1;
    int:0 __attribute__((packed));
    char d;
} X;
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

typedef struct {
    char c:1;
    int:0;
    char d;
} Y;
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


// MAPPING|ONE|aarch64-generic-macos-none:Clang|aarch64-generic-ios-none:Clang|aarch64-generic-ios-macabi:Clang|aarch64-generic-tvos-none:Clang|hexagon-generic-linux-musl:Clang|i386-i386-ios-none:Clang|i386-i586-linux-gnu:Gcc|i386-i586-linux-musl:Gcc|i386-i686-macos-none:Clang|i386-i686-linux-android:Clang|i386-i686-freebsd-gnu:Clang|i386-i686-haiku-gnu:Clang|i386-i686-linux-gnu:Gcc|i386-i686-linux-musl:Gcc|i386-i686-netbsd-gnu:Clang|i386-i686-openbsd-gnu:Clang|mips64el-mips64-linux-gnuabi64:Gcc|mips64el-mips64-linux-musl:Gcc|mips64-mips64-linux-gnuabi64:Gcc|mips64-mips64-linux-musl:Gcc|mipsel-mips32-linux-gnu:Gcc|mipsel-mips32-linux-musl:Gcc|mipsel-mips32-other-eabi:Clang|mips-mips32-linux-gnu:Gcc|mips-mips32r6-linux-gnu:Gcc|mips-mips32-linux-gnuabi64:Gcc|mips-mips64r6-linux-gnuabi64:Gcc|mips-mips32-linux-gnu:Gcc|mips-mips32-linux-musl:Gcc|powerpc64le-ppc64le-linux-gnu:Gcc|powerpc64le-ppc64le-linux-musl:Gcc|powerpc64-ppc64-freebsd-gnu:Clang|powerpc64-ppc64-linux-gnu:Gcc|powerpc64-ppc64-linux-musl:Gcc|powerpc-ppc-linux-gnu:Gcc|powerpc-ppc-linux-musl:Gcc|powerpc-ppc-netbsd-gnu:Clang|riscv32-baseline_rv32-other-eabi:Clang|riscv32-baseline_rv32-linux-gnu:Gcc|riscv64-baseline_rv64-other-eabi:Clang|riscv64-baseline_rv64-linux-gnu:Gcc|s390x-generic-linux-gnu:Gcc|sparc64-v9-linux-gnu:Gcc|sparc64-v9-netbsd-gnu:Clang|sparc64-v9-openbsd-gnu:Clang|sparc-v8-linux-gnu:Gcc|sparc-v9-solaris-eabi:Clang|wasm32-generic-emscripten-musl:Clang|wasm32-generic-other-musl:Clang|wasm32-generic-wasi-musl:Clang|x86_64-x86_64-ios-macabi:Clang|x86_64-x86_64-ios-none:Clang|x86_64-x86_64-macos-none:Clang|x86_64-x86_64-tvos-none:Clang|x86_64-x86_64-other-eabi:Clang|x86_64-x86_64-fuchsia-gnu:Clang|x86_64-x86_64-linux-android:Clang|x86_64-x86_64-solaris-eabi:Clang|x86_64-x86_64-dragonfly-eabi:Clang|x86_64-x86_64-freebsd-gnu:Clang|x86_64-x86_64-haiku-gnu:Clang|x86_64-x86_64-hermit-eabi:Clang|x86_64-x86_64-linux-gnux32:Gcc|x86_64-x86_64-linux-gnu:Gcc|x86_64-x86_64-linux-musl:Gcc|x86_64-x86_64-netbsd-gnu:Clang|x86_64-x86_64-openbsd-gnu:Clang|END
// repr targets Aarch64AppleMacosx|Some("aarch64-generic-macos-none") Arm64AppleIos|Some("aarch64-generic-ios-none") Arm64AppleIosMacabi|Some("aarch64-generic-ios-macabi") Arm64AppleTvos|Some("aarch64-generic-tvos-none") HexagonUnknownLinuxMusl|Some("hexagon-generic-linux-musl") I386AppleIos|Some("i386-i386-ios-none") I586UnknownLinuxGnu|Some("i386-i586-linux-gnu") I586UnknownLinuxMusl|Some("i386-i586-linux-musl") I686AppleMacosx|Some("i386-i686-macos-none") I686LinuxAndroid|Some("i386-i686-linux-android") I686UnknownFreebsd|Some("i386-i686-freebsd-gnu") I686UnknownHaiku|Some("i386-i686-haiku-gnu") I686UnknownLinuxGnu|Some("i386-i686-linux-gnu") I686UnknownLinuxMusl|Some("i386-i686-linux-musl") I686UnknownNetbsdelf|Some("i386-i686-netbsd-gnu") I686UnknownOpenbsd|Some("i386-i686-openbsd-gnu") Mips64elUnknownLinuxGnuabi64|Some("mips64el-mips64-linux-gnuabi64") Mips64elUnknownLinuxMusl|Some("mips64el-mips64-linux-musl") Mips64UnknownLinuxGnuabi64|Some("mips64-mips64-linux-gnuabi64") Mips64UnknownLinuxMusl|Some("mips64-mips64-linux-musl") MipselSonyPsp|None MipselUnknownLinuxGnu|Some("mipsel-mips32-linux-gnu") MipselUnknownLinuxMusl|Some("mipsel-mips32-linux-musl") MipselUnknownLinuxUclibc|None MipselUnknownNone|Some("mipsel-mips32-other-eabi") Mipsisa32r6elUnknownLinuxGnu|Some("mips-mips32-linux-gnu") Mipsisa32r6UnknownLinuxGnu|Some("mips-mips32r6-linux-gnu") Mipsisa64r6elUnknownLinuxGnuabi64|Some("mips-mips32-linux-gnuabi64") Mipsisa64r6UnknownLinuxGnuabi64|Some("mips-mips64r6-linux-gnuabi64") MipsUnknownLinuxGnu|Some("mips-mips32-linux-gnu") MipsUnknownLinuxMusl|Some("mips-mips32-linux-musl") MipsUnknownLinuxUclibc|None Powerpc64leUnknownLinuxGnu|Some("powerpc64le-ppc64le-linux-gnu") Powerpc64leUnknownLinuxMusl|Some("powerpc64le-ppc64le-linux-musl") Powerpc64UnknownFreebsd|Some("powerpc64-ppc64-freebsd-gnu") Powerpc64UnknownLinuxGnu|Some("powerpc64-ppc64-linux-gnu") Powerpc64UnknownLinuxMusl|Some("powerpc64-ppc64-linux-musl") PowerpcUnknownLinuxGnu|Some("powerpc-ppc-linux-gnu") PowerpcUnknownLinuxGnuspe|None PowerpcUnknownLinuxMusl|Some("powerpc-ppc-linux-musl") PowerpcUnknownNetbsd|Some("powerpc-ppc-netbsd-gnu") Riscv32|Some("riscv32-baseline_rv32-other-eabi") Riscv32UnknownLinuxGnu|Some("riscv32-baseline_rv32-linux-gnu") Riscv64|Some("riscv64-baseline_rv64-other-eabi") Riscv64UnknownLinuxGnu|Some("riscv64-baseline_rv64-linux-gnu") S390xUnknownLinuxGnu|Some("s390x-generic-linux-gnu") Sparc64UnknownLinuxGnu|Some("sparc64-v9-linux-gnu") Sparc64UnknownNetbsd|Some("sparc64-v9-netbsd-gnu") Sparc64UnknownOpenbsd|Some("sparc64-v9-openbsd-gnu") SparcUnknownLinuxGnu|Some("sparc-v8-linux-gnu") Sparcv9SunSolaris|Some("sparc-v9-solaris-eabi") Wasm32UnknownEmscripten|Some("wasm32-generic-emscripten-musl") Wasm32UnknownUnknown|Some("wasm32-generic-other-musl") Wasm32Wasi|Some("wasm32-generic-wasi-musl") X86_64AppleIosMacabi|Some("x86_64-x86_64-ios-macabi") X86_64AppleIos|Some("x86_64-x86_64-ios-none") X86_64AppleMacosx|Some("x86_64-x86_64-macos-none") X86_64AppleTvos|Some("x86_64-x86_64-tvos-none") X86_64Elf|Some("x86_64-x86_64-other-eabi") X86_64Fuchsia|Some("x86_64-x86_64-fuchsia-gnu") X86_64LinuxAndroid|Some("x86_64-x86_64-linux-android") X86_64PcSolaris|Some("x86_64-x86_64-solaris-eabi") X86_64RumprunNetbsd|None X86_64UnknownDragonfly|Some("x86_64-x86_64-dragonfly-eabi") X86_64UnknownFreebsd|Some("x86_64-x86_64-freebsd-gnu") X86_64UnknownHaiku|Some("x86_64-x86_64-haiku-gnu") X86_64UnknownHermit|Some("x86_64-x86_64-hermit-eabi") X86_64UnknownL4reUclibc|None X86_64UnknownLinuxGnux32|Some("x86_64-x86_64-linux-gnux32") X86_64UnknownLinuxGnu|Some("x86_64-x86_64-linux-gnu") X86_64UnknownLinuxMusl|Some("x86_64-x86_64-linux-musl") X86_64UnknownNetbsd|Some("x86_64-x86_64-netbsd-gnu") X86_64UnknownOpenbsd|Some("x86_64-x86_64-openbsd-gnu") X86_64UnknownRedox|None 
#ifdef ONE
_Static_assert(sizeof(X) == 5, "");
_Static_assert(_Alignof(X) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct X_alignment) == 6, "");
_Static_assert(_Alignof(struct X_alignment) == 1, "");
_Static_assert(sizeof(struct X_packed) == 5, "");
_Static_assert(_Alignof(struct X_packed) == 1, "");
_Static_assert(sizeof(struct X_required_alignment) == 6, "");
_Static_assert(_Alignof(struct X_required_alignment) == 1, "");
_Static_assert(sizeof(struct X_size) == 7, "");
_Static_assert(_Alignof(struct X_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(X,d) == 32, "");
#endif
_Static_assert(sizeof(Y) == 5, "");
_Static_assert(_Alignof(Y) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Y_alignment) == 6, "");
_Static_assert(_Alignof(struct Y_alignment) == 1, "");
_Static_assert(sizeof(struct Y_packed) == 5, "");
_Static_assert(_Alignof(struct Y_packed) == 1, "");
_Static_assert(sizeof(struct Y_required_alignment) == 6, "");
_Static_assert(_Alignof(struct Y_required_alignment) == 1, "");
_Static_assert(sizeof(struct Y_size) == 7, "");
_Static_assert(_Alignof(struct Y_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(Y,d) == 32, "");
#endif
// MAPPING|TWO|aarch64-generic-fuchsia-gnu:Clang|aarch64-generic-linux-android:Clang|aarch64-generic-freebsd-gnu:Clang|aarch64-generic-hermit-eabi:Clang|aarch64-generic-linux-gnu:Gcc|aarch64-generic-linux-musl:Gcc|aarch64-generic-netbsd-gnu:Clang|aarch64-generic-other-eabi:Clang|aarch64-generic-openbsd-gnu:Clang|arm-baseline-other-eabi:Clang|arm-baseline-other-eabihf:Clang|arm-baseline-linux-gnueabi:Gcc|arm-baseline-linux-gnueabihf:Gcc|arm-arm710t-linux-gnueabi:Gcc|arm-arm1020e-linux-gnueabi:Gcc|arm-arm1136j_s-freebsd-gnueabihf:Clang|arm-arm1136j_s-netbsd-eabihf:Clang|arm-baseline-other-eabi:Clang|arm-baseline-other-eabihf:Clang|arm-cortex_r4-ios-none:Clang|arm-cortex_r4-linux-android:Clang|arm-cortex_r4-other-eabi:Clang|arm-cortex_r4-other-eabihf:Clang|arm-baseline-ios-none:Clang|arm-cortex_r4-freebsd-gnueabihf:Clang|arm-cortex_r4-linux-gnueabi:Gcc|arm-cortex_r4-linux-gnueabihf:Gcc|arm-cortex_r4-netbsd-eabihf:Clang|thumb-arm710t-other-eabi:Clang|thumb-cortex_m0-other-eabi:Clang|thumb-cortex_m4-other-eabihf:Clang|thumb-cortex_m4-other-eabi:Clang|thumb-cortex_m3-other-eabi:Clang|thumb-baseline-other-eabi:Clang|thumb-cortex_m33-other-eabihf:Clang|thumb-cortex_m33-other-eabi:Clang|END
// repr targets Aarch64Fuchsia|Some("aarch64-generic-fuchsia-gnu") Aarch64LinuxAndroid|Some("aarch64-generic-linux-android") Aarch64UnknownFreebsd|Some("aarch64-generic-freebsd-gnu") Aarch64UnknownHermit|Some("aarch64-generic-hermit-eabi") Aarch64UnknownLinuxGnu|Some("aarch64-generic-linux-gnu") Aarch64UnknownLinuxMusl|Some("aarch64-generic-linux-musl") Aarch64UnknownNetbsd|Some("aarch64-generic-netbsd-gnu") Aarch64UnknownNone|Some("aarch64-generic-other-eabi") Aarch64UnknownOpenbsd|Some("aarch64-generic-openbsd-gnu") Aarch64UnknownRedox|None Armebv7rUnknownNoneEabi|Some("arm-baseline-other-eabi") Armebv7rUnknownNoneEabihf|Some("arm-baseline-other-eabihf") ArmLinuxAndroideabi|None ArmUnknownLinuxGnueabi|Some("arm-baseline-linux-gnueabi") ArmUnknownLinuxGnueabihf|Some("arm-baseline-linux-gnueabihf") Armv4tUnknownLinuxGnueabi|Some("arm-arm710t-linux-gnueabi") Armv5teUnknownLinuxGnueabi|Some("arm-arm1020e-linux-gnueabi") Armv5teUnknownLinuxUclibcgnueabi|None Armv6UnknownFreebsdGnueabihf|Some("arm-arm1136j_s-freebsd-gnueabihf") Armv6UnknownNetbsdelfEabihf|Some("arm-arm1136j_s-netbsd-eabihf") Armv7aNoneEabi|Some("arm-baseline-other-eabi") Armv7aNoneEabihf|Some("arm-baseline-other-eabihf") Armv7AppleIos|Some("arm-cortex_r4-ios-none") Armv7NoneLinuxAndroid|Some("arm-cortex_r4-linux-android") Armv7rUnknownNoneEabi|Some("arm-cortex_r4-other-eabi") Armv7rUnknownNoneEabihf|Some("arm-cortex_r4-other-eabihf") Armv7sAppleIos|Some("arm-baseline-ios-none") Armv7UnknownFreebsdGnueabihf|Some("arm-cortex_r4-freebsd-gnueabihf") Armv7UnknownLinuxGnueabi|Some("arm-cortex_r4-linux-gnueabi") Armv7UnknownLinuxGnueabihf|Some("arm-cortex_r4-linux-gnueabihf") Armv7UnknownNetbsdelfEabihf|Some("arm-cortex_r4-netbsd-eabihf") Thumbv4tNoneEabi|Some("thumb-arm710t-other-eabi") Thumbv6mNoneEabi|Some("thumb-cortex_m0-other-eabi") Thumbv7emNoneEabihf|Some("thumb-cortex_m4-other-eabihf") Thumbv7emNoneEabi|Some("thumb-cortex_m4-other-eabi") Thumbv7mNoneEabi|Some("thumb-cortex_m3-other-eabi") Thumbv8mBaseNoneEabi|Some("thumb-baseline-other-eabi") Thumbv8mMainNoneEabihf|Some("thumb-cortex_m33-other-eabihf") Thumbv8mMainNoneEabi|Some("thumb-cortex_m33-other-eabi") 
#elif defined(TWO)
_Static_assert(sizeof(X) == 8, "");
_Static_assert(_Alignof(X) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct X_alignment) == 12, "");
_Static_assert(_Alignof(struct X_alignment) == 4, "");
_Static_assert(sizeof(struct X_packed) == 8, "");
_Static_assert(_Alignof(struct X_packed) == 1, "");
_Static_assert(sizeof(struct X_required_alignment) == 9, "");
_Static_assert(_Alignof(struct X_required_alignment) == 1, "");
_Static_assert(sizeof(struct X_size) == 10, "");
_Static_assert(_Alignof(struct X_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(X,d) == 32, "");
#endif
_Static_assert(sizeof(Y) == 8, "");
_Static_assert(_Alignof(Y) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Y_alignment) == 12, "");
_Static_assert(_Alignof(struct Y_alignment) == 4, "");
_Static_assert(sizeof(struct Y_packed) == 8, "");
_Static_assert(_Alignof(struct Y_packed) == 1, "");
_Static_assert(sizeof(struct Y_required_alignment) == 9, "");
_Static_assert(_Alignof(struct Y_required_alignment) == 1, "");
_Static_assert(sizeof(struct Y_size) == 10, "");
_Static_assert(_Alignof(struct Y_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(Y,d) == 32, "");
#endif
// MAPPING|THREE|avr-avr2-other-eabi:Gcc|END
// repr targets AvrUnknownUnknown|Some("avr-avr2-other-eabi") 
#elif defined(THREE)
_Static_assert(sizeof(X) == 2, "");
_Static_assert(_Alignof(X) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct X_alignment) == 3, "");
_Static_assert(_Alignof(struct X_alignment) == 1, "");
_Static_assert(sizeof(struct X_packed) == 2, "");
_Static_assert(_Alignof(struct X_packed) == 1, "");
_Static_assert(sizeof(struct X_required_alignment) == 3, "");
_Static_assert(_Alignof(struct X_required_alignment) == 1, "");
_Static_assert(sizeof(struct X_size) == 4, "");
_Static_assert(_Alignof(struct X_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(X,d) == 8, "");
#endif
_Static_assert(sizeof(Y) == 2, "");
_Static_assert(_Alignof(Y) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Y_alignment) == 3, "");
_Static_assert(_Alignof(struct Y_alignment) == 1, "");
_Static_assert(sizeof(struct Y_packed) == 2, "");
_Static_assert(_Alignof(struct Y_packed) == 1, "");
_Static_assert(sizeof(struct Y_required_alignment) == 3, "");
_Static_assert(_Alignof(struct Y_required_alignment) == 1, "");
_Static_assert(sizeof(struct Y_size) == 4, "");
_Static_assert(_Alignof(struct Y_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(Y,d) == 8, "");
#endif
// MAPPING|FOUR|i386-i686-windows-gnu:Gcc|x86_64-x86_64-windows-gnu:Gcc|END
// repr targets I686PcWindowsGnu|Some("i386-i686-windows-gnu") X86_64PcWindowsGnu|Some("x86_64-x86_64-windows-gnu") 
#elif defined(FOUR)
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
_Static_assert(__builtin_bitoffsetof(X,d) == 8, "");
#endif
_Static_assert(sizeof(Y) == 8, "");
_Static_assert(_Alignof(Y) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Y_alignment) == 12, "");
_Static_assert(_Alignof(struct Y_alignment) == 4, "");
_Static_assert(sizeof(struct Y_packed) == 8, "");
_Static_assert(_Alignof(struct Y_packed) == 1, "");
_Static_assert(sizeof(struct Y_required_alignment) == 9, "");
_Static_assert(_Alignof(struct Y_required_alignment) == 1, "");
_Static_assert(sizeof(struct Y_size) == 10, "");
_Static_assert(_Alignof(struct Y_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(Y,d) == 32, "");
#endif
// MAPPING|FIVE|msp430-msp430-other-eabi:Clang|END
// repr targets Msp430NoneElf|Some("msp430-msp430-other-eabi") 
#elif defined(FIVE)
_Static_assert(sizeof(X) == 3, "");
_Static_assert(_Alignof(X) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct X_alignment) == 4, "");
_Static_assert(_Alignof(struct X_alignment) == 1, "");
_Static_assert(sizeof(struct X_packed) == 3, "");
_Static_assert(_Alignof(struct X_packed) == 1, "");
_Static_assert(sizeof(struct X_required_alignment) == 4, "");
_Static_assert(_Alignof(struct X_required_alignment) == 1, "");
_Static_assert(sizeof(struct X_size) == 5, "");
_Static_assert(_Alignof(struct X_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(X,d) == 16, "");
#endif
_Static_assert(sizeof(Y) == 3, "");
_Static_assert(_Alignof(Y) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct Y_alignment) == 4, "");
_Static_assert(_Alignof(struct Y_alignment) == 1, "");
_Static_assert(sizeof(struct Y_packed) == 3, "");
_Static_assert(_Alignof(struct Y_packed) == 1, "");
_Static_assert(sizeof(struct Y_required_alignment) == 4, "");
_Static_assert(_Alignof(struct Y_required_alignment) == 1, "");
_Static_assert(sizeof(struct Y_size) == 5, "");
_Static_assert(_Alignof(struct Y_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(Y,d) == 16, "");
#endif
#endif
