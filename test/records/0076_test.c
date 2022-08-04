// SPDX-License-Identifier: GPL-3.0-or-later

// This test file is auto-generated. do not edit.
// This file is a derivative work from the test files found
// in this repo : https://github.com/mahkoh/repr-c
// and is under the same licence as the original work.

#pragma pack(16)
typedef struct {
    char c;
    int i:1 __attribute__((packed));
    char d;
} __attribute__((packed)) A;
A var1;
#pragma pack()
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

#pragma pack(16)
typedef struct {
    char c;
    int i:1 __attribute__((aligned(8)));
    char d;
} B;
B var5;
#pragma pack()
struct B_alignment {
    char a;
    B b;
};
struct B_alignment var6;
#pragma pack(1)
struct B_packed {
    B a;
};
#pragma pack()
struct B_required_alignment {
    char a;
    struct B_packed b;
};
struct B_required_alignment var7;
struct B_size {
    char a[sizeof(B)+1];
    char b;
};
struct B_size var8;

#pragma pack(16)
typedef union {
    char c;
    int i:1 __attribute__((packed));
    char d;
} __attribute__((packed)) C;
C var9;
#pragma pack()
struct C_alignment {
    char a;
    C b;
};
struct C_alignment var10;
#pragma pack(1)
struct C_packed {
    C a;
};
#pragma pack()
struct C_required_alignment {
    char a;
    struct C_packed b;
};
struct C_required_alignment var11;
struct C_size {
    char a[sizeof(C)+1];
    char b;
};
struct C_size var12;

#pragma pack(16)
typedef union {
    char c;
    int i:1 __attribute__((aligned(8)));
    char d;
} D;
D var13;
#pragma pack()
struct D_alignment {
    char a;
    D b;
};
struct D_alignment var14;
#pragma pack(1)
struct D_packed {
    D a;
};
#pragma pack()
struct D_required_alignment {
    char a;
    struct D_packed b;
};
struct D_required_alignment var15;
struct D_size {
    char a[sizeof(D)+1];
    char b;
};
struct D_size var16;


// MAPPING|ONE|aarch64-generic-macos-none:Clang|aarch64-generic-fuchsia-gnu:Clang|aarch64-generic-linux-android:Clang|aarch64-generic-freebsd-gnu:Clang|aarch64-generic-hermit-eabi:Clang|aarch64-generic-linux-gnu:Gcc|aarch64-generic-linux-musl:Gcc|aarch64-generic-netbsd-gnu:Clang|aarch64-generic-other-none:Clang|aarch64-generic-openbsd-gnu:Clang|aarch64-generic-ios-none:Clang|aarch64-generic-ios-macabi:Clang|aarch64-generic-tvos-none:Clang|arm-baseline-other-eabi:Clang|arm-baseline-other-eabihf:Clang|arm-baseline-linux-gnueabi:Gcc|arm-baseline-linux-gnueabihf:Gcc|arm-arm710t-linux-gnueabi:Gcc|arm-arm1020e-linux-gnueabi:Gcc|arm-arm1136j_s-freebsd-gnu:Clang|arm-arm1136j_s-netbsd-eabihf:Clang|arm-baseline-other-eabi:Clang|arm-baseline-other-eabihf:Clang|arm-cortex_r4-other-eabi:Clang|arm-cortex_r4-other-eabihf:Clang|arm-cortex_r4-freebsd-gnu:Clang|arm-cortex_r4-linux-gnueabi:Gcc|arm-cortex_r4-linux-gnueabihf:Gcc|arm-cortex_r4-netbsd-eabihf:Clang|hexagon-generic-linux-musl:Clang|i386-i386-ios-none:Clang|i386-i586-linux-gnu:Gcc|i386-i586-linux-musl:Gcc|x86_64-i686-macos-none:Clang|i386-i686-linux-android:Clang|i386-i686-freebsd-gnu:Clang|i386-i686-haiku-gnu:Clang|i386-i686-linux-gnu:Gcc|i386-i686-linux-musl:Gcc|i386-i686-netbsd-gnu:Clang|i386-i686-openbsd-gnu:Clang|mips64el-mips64-linux-gnuabi64:Gcc|mips64-mips64-linux-gnuabi64:Gcc|mipsel-mips32-linux-gnu:Gcc|mipsel-mips32-linux-musl:Gcc|mipsel-mips32-other-none:Clang|mips-mips32-linux-gnu:Gcc|mips-mips32r6-linux-gnu:Gcc|mips-mips32-linux-gnuabi64:Gcc|mips-mips64r6-linux-gnuabi64:Gcc|mips-mips32-linux-gnu:Gcc|mips-mips32-linux-musl:Gcc|powerpc64le-ppc64le-linux-gnu:Gcc|powerpc64le-ppc64le-linux-musl:Gcc|powerpc64-ppc64-freebsd-gnu:Clang|powerpc64-ppc64-linux-gnu:Gcc|powerpc64-ppc64-linux-musl:Gcc|powerpc-ppc-linux-gnu:Gcc|powerpc-ppc-linux-musl:Gcc|powerpc-ppc-netbsd-gnu:Clang|riscv32-generic_rv32-other-none:Clang|riscv32-generic_rv32-linux-gnu:Gcc|riscv64-generic_rv64-other-none:Clang|riscv64-generic_rv64-linux-gnu:Gcc|s390x-generic-linux-gnu:Gcc|sparc64-v9-linux-gnu:Gcc|sparc64-v9-netbsd-gnu:Clang|sparc64-v9-openbsd-gnu:Clang|sparc-v8-linux-gnu:Gcc|sparc-v9-solaris-eabi:Clang|thumb-arm710t-other-eabi:Clang|thumb-cortex_m0-other-eabi:Clang|thumb-cortex_m4-other-eabihf:Clang|thumb-cortex_m4-other-eabi:Clang|thumb-cortex_m3-other-eabi:Clang|thumb-baseline-other-eabi:Clang|thumb-cortex_m33-other-eabihf:Clang|thumb-cortex_m33-other-eabi:Clang|wasm32-generic-emscripten-musl:Clang|wasm32-generic-other-none:Clang|wasm32-generic-wasi-musl:Clang|x86_64-x86_64-ios-macabi:Clang|x86_64-x86_64-ios-none:Clang|x86_64-x86_64-macos-none:Clang|x86_64-x86_64-tvos-none:Clang|x86_64-x86_64-fuchsia-gnu:Clang|x86_64-x86_64-linux-android:Clang|x86_64-x86_64-solaris-eabi:Clang|x86_64-x86_64-dragonfly-eabi:Clang|x86_64-x86_64-freebsd-gnu:Clang|x86_64-x86_64-haiku-gnu:Clang|x86_64-x86_64-hermit-eabi:Clang|x86_64-x86_64-linux-gnux32:Gcc|x86_64-x86_64-linux-gnu:Gcc|x86_64-x86_64-linux-musl:Gcc|x86_64-x86_64-netbsd-gnu:Clang|x86_64-x86_64-openbsd-gnu:Clang|END
// repr targets Aarch64AppleMacosx|Some("aarch64-generic-macos-none") Aarch64Fuchsia|Some("aarch64-generic-fuchsia-gnu") Aarch64LinuxAndroid|Some("aarch64-generic-linux-android") Aarch64UnknownFreebsd|Some("aarch64-generic-freebsd-gnu") Aarch64UnknownHermit|Some("aarch64-generic-hermit-eabi") Aarch64UnknownLinuxGnu|Some("aarch64-generic-linux-gnu") Aarch64UnknownLinuxMusl|Some("aarch64-generic-linux-musl") Aarch64UnknownNetbsd|Some("aarch64-generic-netbsd-gnu") Aarch64UnknownNone|Some("aarch64-generic-other-none") Aarch64UnknownOpenbsd|Some("aarch64-generic-openbsd-gnu") Aarch64UnknownRedox|None Arm64AppleIos|Some("aarch64-generic-ios-none") Arm64AppleIosMacabi|Some("aarch64-generic-ios-macabi") Arm64AppleTvos|Some("aarch64-generic-tvos-none") Armebv7rUnknownNoneEabi|Some("arm-baseline-other-eabi") Armebv7rUnknownNoneEabihf|Some("arm-baseline-other-eabihf") ArmLinuxAndroideabi|None ArmUnknownLinuxGnueabi|Some("arm-baseline-linux-gnueabi") ArmUnknownLinuxGnueabihf|Some("arm-baseline-linux-gnueabihf") Armv4tUnknownLinuxGnueabi|Some("arm-arm710t-linux-gnueabi") Armv5teUnknownLinuxGnueabi|Some("arm-arm1020e-linux-gnueabi") Armv5teUnknownLinuxUclibcgnueabi|None Armv6UnknownFreebsdGnueabihf|Some("arm-arm1136j_s-freebsd-gnu") Armv6UnknownNetbsdelfEabihf|Some("arm-arm1136j_s-netbsd-eabihf") Armv7aNoneEabi|Some("arm-baseline-other-eabi") Armv7aNoneEabihf|Some("arm-baseline-other-eabihf") Armv7NoneLinuxAndroid|None Armv7rUnknownNoneEabi|Some("arm-cortex_r4-other-eabi") Armv7rUnknownNoneEabihf|Some("arm-cortex_r4-other-eabihf") Armv7UnknownFreebsdGnueabihf|Some("arm-cortex_r4-freebsd-gnu") Armv7UnknownLinuxGnueabi|Some("arm-cortex_r4-linux-gnueabi") Armv7UnknownLinuxGnueabihf|Some("arm-cortex_r4-linux-gnueabihf") Armv7UnknownNetbsdelfEabihf|Some("arm-cortex_r4-netbsd-eabihf") HexagonUnknownLinuxMusl|Some("hexagon-generic-linux-musl") I386AppleIos|Some("i386-i386-ios-none") I586UnknownLinuxGnu|Some("i386-i586-linux-gnu") I586UnknownLinuxMusl|Some("i386-i586-linux-musl") I686AppleMacosx|Some("x86_64-i686-macos-none") I686LinuxAndroid|Some("i386-i686-linux-android") I686UnknownFreebsd|Some("i386-i686-freebsd-gnu") I686UnknownHaiku|Some("i386-i686-haiku-gnu") I686UnknownLinuxGnu|Some("i386-i686-linux-gnu") I686UnknownLinuxMusl|Some("i386-i686-linux-musl") I686UnknownNetbsdelf|Some("i386-i686-netbsd-gnu") I686UnknownOpenbsd|Some("i386-i686-openbsd-gnu") Mips64elUnknownLinuxGnuabi64|Some("mips64el-mips64-linux-gnuabi64") Mips64elUnknownLinuxMusl|None Mips64UnknownLinuxGnuabi64|Some("mips64-mips64-linux-gnuabi64") Mips64UnknownLinuxMusl|None MipselSonyPsp|None MipselUnknownLinuxGnu|Some("mipsel-mips32-linux-gnu") MipselUnknownLinuxMusl|Some("mipsel-mips32-linux-musl") MipselUnknownLinuxUclibc|None MipselUnknownNone|Some("mipsel-mips32-other-none") Mipsisa32r6elUnknownLinuxGnu|Some("mips-mips32-linux-gnu") Mipsisa32r6UnknownLinuxGnu|Some("mips-mips32r6-linux-gnu") Mipsisa64r6elUnknownLinuxGnuabi64|Some("mips-mips32-linux-gnuabi64") Mipsisa64r6UnknownLinuxGnuabi64|Some("mips-mips64r6-linux-gnuabi64") MipsUnknownLinuxGnu|Some("mips-mips32-linux-gnu") MipsUnknownLinuxMusl|Some("mips-mips32-linux-musl") MipsUnknownLinuxUclibc|None Powerpc64leUnknownLinuxGnu|Some("powerpc64le-ppc64le-linux-gnu") Powerpc64leUnknownLinuxMusl|Some("powerpc64le-ppc64le-linux-musl") Powerpc64UnknownFreebsd|Some("powerpc64-ppc64-freebsd-gnu") Powerpc64UnknownLinuxGnu|Some("powerpc64-ppc64-linux-gnu") Powerpc64UnknownLinuxMusl|Some("powerpc64-ppc64-linux-musl") PowerpcUnknownLinuxGnu|Some("powerpc-ppc-linux-gnu") PowerpcUnknownLinuxGnuspe|None PowerpcUnknownLinuxMusl|Some("powerpc-ppc-linux-musl") PowerpcUnknownNetbsd|Some("powerpc-ppc-netbsd-gnu") Riscv32|Some("riscv32-generic_rv32-other-none") Riscv32UnknownLinuxGnu|Some("riscv32-generic_rv32-linux-gnu") Riscv64|Some("riscv64-generic_rv64-other-none") Riscv64UnknownLinuxGnu|Some("riscv64-generic_rv64-linux-gnu") S390xUnknownLinuxGnu|Some("s390x-generic-linux-gnu") Sparc64UnknownLinuxGnu|Some("sparc64-v9-linux-gnu") Sparc64UnknownNetbsd|Some("sparc64-v9-netbsd-gnu") Sparc64UnknownOpenbsd|Some("sparc64-v9-openbsd-gnu") SparcUnknownLinuxGnu|Some("sparc-v8-linux-gnu") Sparcv9SunSolaris|Some("sparc-v9-solaris-eabi") Thumbv4tNoneEabi|Some("thumb-arm710t-other-eabi") Thumbv6mNoneEabi|Some("thumb-cortex_m0-other-eabi") Thumbv7emNoneEabihf|Some("thumb-cortex_m4-other-eabihf") Thumbv7emNoneEabi|Some("thumb-cortex_m4-other-eabi") Thumbv7mNoneEabi|Some("thumb-cortex_m3-other-eabi") Thumbv8mBaseNoneEabi|Some("thumb-baseline-other-eabi") Thumbv8mMainNoneEabihf|Some("thumb-cortex_m33-other-eabihf") Thumbv8mMainNoneEabi|Some("thumb-cortex_m33-other-eabi") Wasm32UnknownEmscripten|Some("wasm32-generic-emscripten-musl") Wasm32UnknownUnknown|Some("wasm32-generic-other-none") Wasm32Wasi|Some("wasm32-generic-wasi-musl") X86_64AppleIosMacabi|Some("x86_64-x86_64-ios-macabi") X86_64AppleIos|Some("x86_64-x86_64-ios-none") X86_64AppleMacosx|Some("x86_64-x86_64-macos-none") X86_64AppleTvos|Some("x86_64-x86_64-tvos-none") X86_64Elf|None X86_64Fuchsia|Some("x86_64-x86_64-fuchsia-gnu") X86_64LinuxAndroid|Some("x86_64-x86_64-linux-android") X86_64PcSolaris|Some("x86_64-x86_64-solaris-eabi") X86_64RumprunNetbsd|None X86_64UnknownDragonfly|Some("x86_64-x86_64-dragonfly-eabi") X86_64UnknownFreebsd|Some("x86_64-x86_64-freebsd-gnu") X86_64UnknownHaiku|Some("x86_64-x86_64-haiku-gnu") X86_64UnknownHermit|Some("x86_64-x86_64-hermit-eabi") X86_64UnknownL4reUclibc|None X86_64UnknownLinuxGnux32|Some("x86_64-x86_64-linux-gnux32") X86_64UnknownLinuxGnu|Some("x86_64-x86_64-linux-gnu") X86_64UnknownLinuxMusl|Some("x86_64-x86_64-linux-musl") X86_64UnknownNetbsd|Some("x86_64-x86_64-netbsd-gnu") X86_64UnknownOpenbsd|Some("x86_64-x86_64-openbsd-gnu") X86_64UnknownRedox|None 
#ifdef ONE
_Static_assert(sizeof(A) == 4, "");
_Static_assert(_Alignof(A) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 8, "");
_Static_assert(_Alignof(struct A_alignment) == 4, "");
_Static_assert(sizeof(struct A_packed) == 4, "");
_Static_assert(_Alignof(struct A_packed) == 1, "");
_Static_assert(sizeof(struct A_required_alignment) == 5, "");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "");
_Static_assert(sizeof(struct A_size) == 6, "");
_Static_assert(_Alignof(struct A_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A,d) == 16, "");
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
_Static_assert(__builtin_bitoffsetof(B,i) == 64, "");
_Static_assert(__builtin_bitoffsetof(B,d) == 72, "");
#endif
_Static_assert(sizeof(C) == 4, "");
_Static_assert(_Alignof(C) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 8, "");
_Static_assert(_Alignof(struct C_alignment) == 4, "");
_Static_assert(sizeof(struct C_packed) == 4, "");
_Static_assert(_Alignof(struct C_packed) == 1, "");
_Static_assert(sizeof(struct C_required_alignment) == 5, "");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "");
_Static_assert(sizeof(struct C_size) == 6, "");
_Static_assert(_Alignof(struct C_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C,i) == 0, "");
_Static_assert(__builtin_bitoffsetof(C,d) == 0, "");
#endif
_Static_assert(sizeof(D) == 8, "");
_Static_assert(_Alignof(D) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 16, "");
_Static_assert(_Alignof(struct D_alignment) == 8, "");
_Static_assert(sizeof(struct D_packed) == 8, "");
_Static_assert(_Alignof(struct D_packed) == 1, "");
_Static_assert(sizeof(struct D_required_alignment) == 9, "");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "");
_Static_assert(sizeof(struct D_size) == 10, "");
_Static_assert(_Alignof(struct D_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D,i) == 0, "");
_Static_assert(__builtin_bitoffsetof(D,d) == 0, "");
#endif
// MAPPING|TWO|arm-cortex_r4-ios-none:Clang|arm-baseline-ios-none:Clang|END
// repr targets Armv7AppleIos|Some("arm-cortex_r4-ios-none") Armv7sAppleIos|Some("arm-baseline-ios-none") 
#elif defined(TWO)
_Static_assert(sizeof(A) == 3, "");
_Static_assert(_Alignof(A) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 4, "");
_Static_assert(_Alignof(struct A_alignment) == 1, "");
_Static_assert(sizeof(struct A_packed) == 3, "");
_Static_assert(_Alignof(struct A_packed) == 1, "");
_Static_assert(sizeof(struct A_required_alignment) == 4, "");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "");
_Static_assert(sizeof(struct A_size) == 5, "");
_Static_assert(_Alignof(struct A_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A,d) == 16, "");
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
_Static_assert(__builtin_bitoffsetof(B,i) == 64, "");
_Static_assert(__builtin_bitoffsetof(B,d) == 72, "");
#endif
_Static_assert(sizeof(C) == 1, "");
_Static_assert(_Alignof(C) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 2, "");
_Static_assert(_Alignof(struct C_alignment) == 1, "");
_Static_assert(sizeof(struct C_packed) == 1, "");
_Static_assert(_Alignof(struct C_packed) == 1, "");
_Static_assert(sizeof(struct C_required_alignment) == 2, "");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "");
_Static_assert(sizeof(struct C_size) == 3, "");
_Static_assert(_Alignof(struct C_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C,i) == 0, "");
_Static_assert(__builtin_bitoffsetof(C,d) == 0, "");
#endif
_Static_assert(sizeof(D) == 8, "");
_Static_assert(_Alignof(D) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 16, "");
_Static_assert(_Alignof(struct D_alignment) == 8, "");
_Static_assert(sizeof(struct D_packed) == 8, "");
_Static_assert(_Alignof(struct D_packed) == 1, "");
_Static_assert(sizeof(struct D_required_alignment) == 9, "");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "");
_Static_assert(sizeof(struct D_size) == 10, "");
_Static_assert(_Alignof(struct D_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D,i) == 0, "");
_Static_assert(__builtin_bitoffsetof(D,d) == 0, "");
#endif
// MAPPING|THREE|avr-atmega328-other-gnu:Gcc|END
// repr targets AvrUnknownUnknown|Some("avr-atmega328-other-gnu") 
#elif defined(THREE)
_Static_assert(sizeof(A) == 3, "");
_Static_assert(_Alignof(A) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 4, "");
_Static_assert(_Alignof(struct A_alignment) == 1, "");
_Static_assert(sizeof(struct A_packed) == 3, "");
_Static_assert(_Alignof(struct A_packed) == 1, "");
_Static_assert(sizeof(struct A_required_alignment) == 4, "");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "");
_Static_assert(sizeof(struct A_size) == 5, "");
_Static_assert(_Alignof(struct A_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A,d) == 16, "");
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
_Static_assert(__builtin_bitoffsetof(B,i) == 64, "");
_Static_assert(__builtin_bitoffsetof(B,d) == 72, "");
#endif
_Static_assert(sizeof(C) == 1, "");
_Static_assert(_Alignof(C) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 2, "");
_Static_assert(_Alignof(struct C_alignment) == 1, "");
_Static_assert(sizeof(struct C_packed) == 1, "");
_Static_assert(_Alignof(struct C_packed) == 1, "");
_Static_assert(sizeof(struct C_required_alignment) == 2, "");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "");
_Static_assert(sizeof(struct C_size) == 3, "");
_Static_assert(_Alignof(struct C_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C,i) == 0, "");
_Static_assert(__builtin_bitoffsetof(C,d) == 0, "");
#endif
_Static_assert(sizeof(D) == 8, "");
_Static_assert(_Alignof(D) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 16, "");
_Static_assert(_Alignof(struct D_alignment) == 8, "");
_Static_assert(sizeof(struct D_packed) == 8, "");
_Static_assert(_Alignof(struct D_packed) == 1, "");
_Static_assert(sizeof(struct D_required_alignment) == 9, "");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "");
_Static_assert(sizeof(struct D_size) == 10, "");
_Static_assert(_Alignof(struct D_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D,i) == 0, "");
_Static_assert(__builtin_bitoffsetof(D,d) == 0, "");
#endif
// MAPPING|FOUR|i386-i686-windows-gnu:Gcc|x86_64-x86_64-windows-gnu:Gcc|END
// repr targets I686PcWindowsGnu|Some("i386-i686-windows-gnu") X86_64PcWindowsGnu|Some("x86_64-x86_64-windows-gnu") 
#elif defined(FOUR)
_Static_assert(sizeof(A) == 6, "");
_Static_assert(_Alignof(A) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 7, "");
_Static_assert(_Alignof(struct A_alignment) == 1, "");
_Static_assert(sizeof(struct A_packed) == 6, "");
_Static_assert(_Alignof(struct A_packed) == 1, "");
_Static_assert(sizeof(struct A_required_alignment) == 7, "");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "");
_Static_assert(sizeof(struct A_size) == 8, "");
_Static_assert(_Alignof(struct A_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(A,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A,d) == 40, "");
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
_Static_assert(__builtin_bitoffsetof(B,i) == 64, "");
_Static_assert(__builtin_bitoffsetof(B,d) == 96, "");
#endif
_Static_assert(sizeof(C) == 1, "");
_Static_assert(_Alignof(C) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 2, "");
_Static_assert(_Alignof(struct C_alignment) == 1, "");
_Static_assert(sizeof(struct C_packed) == 1, "");
_Static_assert(_Alignof(struct C_packed) == 1, "");
_Static_assert(sizeof(struct C_required_alignment) == 2, "");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "");
_Static_assert(sizeof(struct C_size) == 3, "");
_Static_assert(_Alignof(struct C_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C,i) == 0, "");
_Static_assert(__builtin_bitoffsetof(C,d) == 0, "");
#endif
_Static_assert(sizeof(D) == 8, "");
_Static_assert(_Alignof(D) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 16, "");
_Static_assert(_Alignof(struct D_alignment) == 8, "");
_Static_assert(sizeof(struct D_packed) == 8, "");
_Static_assert(_Alignof(struct D_packed) == 1, "");
_Static_assert(sizeof(struct D_required_alignment) == 9, "");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "");
_Static_assert(sizeof(struct D_size) == 10, "");
_Static_assert(_Alignof(struct D_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D,i) == 0, "");
_Static_assert(__builtin_bitoffsetof(D,d) == 0, "");
#endif
// MAPPING|FIVE|msp430-msp430-other-none:Clang|END
// repr targets Msp430NoneElf|Some("msp430-msp430-other-none") 
#elif defined(FIVE)
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
_Static_assert(__builtin_bitoffsetof(A,i) == 8, "");
_Static_assert(__builtin_bitoffsetof(A,d) == 16, "");
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
_Static_assert(__builtin_bitoffsetof(B,i) == 64, "");
_Static_assert(__builtin_bitoffsetof(B,d) == 72, "");
#endif
_Static_assert(sizeof(C) == 2, "");
_Static_assert(_Alignof(C) == 2, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 4, "");
_Static_assert(_Alignof(struct C_alignment) == 2, "");
_Static_assert(sizeof(struct C_packed) == 2, "");
_Static_assert(_Alignof(struct C_packed) == 1, "");
_Static_assert(sizeof(struct C_required_alignment) == 3, "");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "");
_Static_assert(sizeof(struct C_size) == 4, "");
_Static_assert(_Alignof(struct C_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C,i) == 0, "");
_Static_assert(__builtin_bitoffsetof(C,d) == 0, "");
#endif
_Static_assert(sizeof(D) == 8, "");
_Static_assert(_Alignof(D) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 16, "");
_Static_assert(_Alignof(struct D_alignment) == 8, "");
_Static_assert(sizeof(struct D_packed) == 8, "");
_Static_assert(_Alignof(struct D_packed) == 1, "");
_Static_assert(sizeof(struct D_required_alignment) == 9, "");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "");
_Static_assert(sizeof(struct D_size) == 10, "");
_Static_assert(_Alignof(struct D_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(D,i) == 0, "");
_Static_assert(__builtin_bitoffsetof(D,d) == 0, "");
#endif
#endif
