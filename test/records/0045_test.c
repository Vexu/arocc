// SPDX-License-Identifier: GPL-3.0-or-later

// This test file is auto-generated. do not edit.
// This file is a derivative work from the test files found
// in this repo : https://github.com/mahkoh/repr-c
// and is under the same licence as the original work.

typedef char unnamed_type_1[3];
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

#ifdef MSVC
__declspec(align(2)) typedef unnamed_type_1 A;
#else
typedef unnamed_type_1 A __attribute__((aligned(2)));
#endif
A var6;
struct A_alignment {
#ifdef MSVC
    char a[_Alignof(A)];
    char b;
#else
    char a;
    A b;
#endif
};
struct A_alignment var7;
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
struct A_required_alignment var8;
struct A_size {
    char a[sizeof(A)+1];
    char b;
};
struct A_size var9;

typedef A B[3];
B var10;
struct B_alignment {
#ifdef MSVC
    char a[_Alignof(B)];
    char b;
#else
    char a;
    B b;
#endif
};
struct B_alignment var11;
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
struct B_required_alignment var12;
struct B_size {
    char a[sizeof(B)+1];
    char b;
};
struct B_size var13;

typedef char C[3];
C var14;
struct C_alignment {
#ifdef MSVC
    char a[_Alignof(C)];
    char b;
#else
    char a;
    C b;
#endif
};
struct C_alignment var15;
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
struct C_required_alignment var16;
struct C_size {
    char a[sizeof(C)+1];
    char b;
};
struct C_size var17;

#ifdef MSVC
typedef B D[];
#else
typedef B D[0];
#endif
D var18;
struct D_alignment {
#ifdef MSVC
    char a[_Alignof(D)];
    char b;
#else
    char a;
    D b;
#endif
};
struct D_alignment var19;
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
struct D_required_alignment var20;
struct D_size {
    char a[sizeof(D)+1];
    char b;
};
struct D_size var21;

typedef struct {
    char c;
    D d;
} E;
E var22;
struct E_alignment {
#ifdef MSVC
    char a[_Alignof(E)];
    char b;
#else
    char a;
    E b;
#endif
};
struct E_alignment var23;
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
struct E_required_alignment var24;
struct E_size {
    char a[sizeof(E)+1];
    char b;
};
struct E_size var25;

#ifdef MSVC
typedef B unnamed_type_26[];
#else
typedef B unnamed_type_26[0];
#endif
unnamed_type_26 var27;
struct unnamed_type_26_alignment {
#ifdef MSVC
    char a[_Alignof(unnamed_type_26)];
    char b;
#else
    char a;
    unnamed_type_26 b;
#endif
};
struct unnamed_type_26_alignment var28;
#pragma pack(1)
struct unnamed_type_26_packed {
    unnamed_type_26 a;
};
#pragma pack()
struct unnamed_type_26_required_alignment {
#ifdef MSVC
    char a[_Alignof(struct unnamed_type_26_packed)];
    char b;
#else
    char a;
    struct unnamed_type_26_packed b;
#endif
};
struct unnamed_type_26_required_alignment var29;
struct unnamed_type_26_size {
    char a[sizeof(unnamed_type_26)+1];
    char b;
};
struct unnamed_type_26_size var30;

typedef struct {
    char c;
    unnamed_type_26 d;
} F;
F var31;
struct F_alignment {
#ifdef MSVC
    char a[_Alignof(F)];
    char b;
#else
    char a;
    F b;
#endif
};
struct F_alignment var32;
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
struct F_required_alignment var33;
struct F_size {
    char a[sizeof(F)+1];
    char b;
};
struct F_size var34;

// MAPPING|ONE|aarch64-generic-macos-none:Clang|aarch64-generic-fuchsia-gnu:Clang|aarch64-generic-linux-android:Clang|aarch64-generic-freebsd-gnu:Clang|aarch64-generic-hermit-eabi:Clang|aarch64-generic-linux-gnu:Gcc|aarch64-generic-linux-musl:Gcc|aarch64-generic-netbsd-gnu:Clang|aarch64-generic-other-eabi:Clang|aarch64-generic-openbsd-gnu:Clang|aarch64-generic-ios-none:Clang|aarch64-generic-ios-macabi:Clang|aarch64-generic-tvos-none:Clang|arm-baseline-other-eabi:Clang|arm-baseline-other-eabihf:Clang|arm-baseline-linux-gnueabi:Gcc|arm-baseline-linux-gnueabihf:Gcc|arm-arm710t-linux-gnueabi:Gcc|arm-arm1020e-linux-gnueabi:Gcc|arm-arm1136j_s-freebsd-gnueabihf:Clang|arm-arm1136j_s-netbsd-eabihf:Clang|arm-baseline-other-eabi:Clang|arm-baseline-other-eabihf:Clang|arm-cortex_r4-ios-none:Clang|arm-cortex_r4-linux-android:Clang|arm-cortex_r4-other-eabi:Clang|arm-cortex_r4-other-eabihf:Clang|arm-baseline-ios-none:Clang|arm-cortex_r4-freebsd-gnueabihf:Clang|arm-cortex_r4-linux-gnueabi:Gcc|arm-cortex_r4-linux-gnueabihf:Gcc|arm-cortex_r4-netbsd-eabihf:Clang|avr-avr2-other-eabi:Gcc|hexagon-generic-linux-musl:Clang|i386-i386-ios-none:Clang|i386-i586-linux-gnu:Gcc|i386-i586-linux-musl:Gcc|i386-i686-macos-none:Clang|i386-i686-linux-android:Clang|i386-i686-windows-gnu:Gcc|i386-i686-freebsd-gnu:Clang|i386-i686-haiku-gnu:Clang|i386-i686-linux-gnu:Gcc|i386-i686-linux-musl:Gcc|i386-i686-netbsd-gnu:Clang|i386-i686-openbsd-gnu:Clang|mips64el-mips64-linux-gnuabi64:Gcc|mips64el-mips64-linux-musl:Gcc|mips64-mips64-linux-gnuabi64:Gcc|mips64-mips64-linux-musl:Gcc|mipsel-mips32-linux-gnu:Gcc|mipsel-mips32-linux-musl:Gcc|mipsel-mips32-other-eabi:Clang|mips-mips32-linux-gnu:Gcc|mips-mips32r6-linux-gnu:Gcc|mips-mips32-linux-gnuabi64:Gcc|mips-mips64r6-linux-gnuabi64:Gcc|mips-mips32-linux-gnu:Gcc|mips-mips32-linux-musl:Gcc|msp430-msp430-other-eabi:Clang|powerpc64le-ppc64le-linux-gnu:Gcc|powerpc64le-ppc64le-linux-musl:Gcc|powerpc64-ppc64-freebsd-gnu:Clang|powerpc64-ppc64-linux-gnu:Gcc|powerpc64-ppc64-linux-musl:Gcc|powerpc-ppc-linux-gnu:Gcc|powerpc-ppc-linux-musl:Gcc|powerpc-ppc-netbsd-gnu:Clang|riscv32-baseline_rv32-other-eabi:Clang|riscv32-baseline_rv32-linux-gnu:Gcc|riscv64-baseline_rv64-other-eabi:Clang|riscv64-baseline_rv64-linux-gnu:Gcc|s390x-generic-linux-gnu:Gcc|sparc64-v9-linux-gnu:Gcc|sparc64-v9-netbsd-gnu:Clang|sparc64-v9-openbsd-gnu:Clang|sparc-v8-linux-gnu:Gcc|sparc-v9-solaris-eabi:Clang|thumb-arm710t-other-eabi:Clang|thumb-cortex_m0-other-eabi:Clang|thumb-cortex_m4-other-eabihf:Clang|thumb-cortex_m4-other-eabi:Clang|thumb-cortex_m3-other-eabi:Clang|thumb-baseline-other-eabi:Clang|thumb-cortex_m33-other-eabihf:Clang|thumb-cortex_m33-other-eabi:Clang|wasm32-generic-emscripten-musl:Clang|wasm32-generic-other-musl:Clang|wasm32-generic-wasi-musl:Clang|x86_64-x86_64-ios-macabi:Clang|x86_64-x86_64-ios-none:Clang|x86_64-x86_64-macos-none:Clang|x86_64-x86_64-tvos-none:Clang|x86_64-x86_64-other-eabi:Clang|x86_64-x86_64-fuchsia-gnu:Clang|x86_64-x86_64-linux-android:Clang|x86_64-x86_64-solaris-eabi:Clang|x86_64-x86_64-windows-gnu:Gcc|x86_64-x86_64-dragonfly-eabi:Clang|x86_64-x86_64-freebsd-gnu:Clang|x86_64-x86_64-haiku-gnu:Clang|x86_64-x86_64-hermit-eabi:Clang|x86_64-x86_64-linux-gnux32:Gcc|x86_64-x86_64-linux-gnu:Gcc|x86_64-x86_64-linux-musl:Gcc|x86_64-x86_64-netbsd-gnu:Clang|x86_64-x86_64-openbsd-gnu:Clang|END
// repr targets Aarch64AppleMacosx|Some("aarch64-generic-macos-none") Aarch64Fuchsia|Some("aarch64-generic-fuchsia-gnu") Aarch64LinuxAndroid|Some("aarch64-generic-linux-android") Aarch64UnknownFreebsd|Some("aarch64-generic-freebsd-gnu") Aarch64UnknownHermit|Some("aarch64-generic-hermit-eabi") Aarch64UnknownLinuxGnu|Some("aarch64-generic-linux-gnu") Aarch64UnknownLinuxMusl|Some("aarch64-generic-linux-musl") Aarch64UnknownNetbsd|Some("aarch64-generic-netbsd-gnu") Aarch64UnknownNone|Some("aarch64-generic-other-eabi") Aarch64UnknownOpenbsd|Some("aarch64-generic-openbsd-gnu") Aarch64UnknownRedox|None Arm64AppleIos|Some("aarch64-generic-ios-none") Arm64AppleIosMacabi|Some("aarch64-generic-ios-macabi") Arm64AppleTvos|Some("aarch64-generic-tvos-none") Armebv7rUnknownNoneEabi|Some("arm-baseline-other-eabi") Armebv7rUnknownNoneEabihf|Some("arm-baseline-other-eabihf") ArmLinuxAndroideabi|None ArmUnknownLinuxGnueabi|Some("arm-baseline-linux-gnueabi") ArmUnknownLinuxGnueabihf|Some("arm-baseline-linux-gnueabihf") Armv4tUnknownLinuxGnueabi|Some("arm-arm710t-linux-gnueabi") Armv5teUnknownLinuxGnueabi|Some("arm-arm1020e-linux-gnueabi") Armv5teUnknownLinuxUclibcgnueabi|None Armv6UnknownFreebsdGnueabihf|Some("arm-arm1136j_s-freebsd-gnueabihf") Armv6UnknownNetbsdelfEabihf|Some("arm-arm1136j_s-netbsd-eabihf") Armv7aNoneEabi|Some("arm-baseline-other-eabi") Armv7aNoneEabihf|Some("arm-baseline-other-eabihf") Armv7AppleIos|Some("arm-cortex_r4-ios-none") Armv7NoneLinuxAndroid|Some("arm-cortex_r4-linux-android") Armv7rUnknownNoneEabi|Some("arm-cortex_r4-other-eabi") Armv7rUnknownNoneEabihf|Some("arm-cortex_r4-other-eabihf") Armv7sAppleIos|Some("arm-baseline-ios-none") Armv7UnknownFreebsdGnueabihf|Some("arm-cortex_r4-freebsd-gnueabihf") Armv7UnknownLinuxGnueabi|Some("arm-cortex_r4-linux-gnueabi") Armv7UnknownLinuxGnueabihf|Some("arm-cortex_r4-linux-gnueabihf") Armv7UnknownNetbsdelfEabihf|Some("arm-cortex_r4-netbsd-eabihf") AvrUnknownUnknown|Some("avr-avr2-other-eabi") HexagonUnknownLinuxMusl|Some("hexagon-generic-linux-musl") I386AppleIos|Some("i386-i386-ios-none") I586UnknownLinuxGnu|Some("i386-i586-linux-gnu") I586UnknownLinuxMusl|Some("i386-i586-linux-musl") I686AppleMacosx|Some("i386-i686-macos-none") I686LinuxAndroid|Some("i386-i686-linux-android") I686PcWindowsGnu|Some("i386-i686-windows-gnu") I686UnknownFreebsd|Some("i386-i686-freebsd-gnu") I686UnknownHaiku|Some("i386-i686-haiku-gnu") I686UnknownLinuxGnu|Some("i386-i686-linux-gnu") I686UnknownLinuxMusl|Some("i386-i686-linux-musl") I686UnknownNetbsdelf|Some("i386-i686-netbsd-gnu") I686UnknownOpenbsd|Some("i386-i686-openbsd-gnu") Mips64elUnknownLinuxGnuabi64|Some("mips64el-mips64-linux-gnuabi64") Mips64elUnknownLinuxMusl|Some("mips64el-mips64-linux-musl") Mips64UnknownLinuxGnuabi64|Some("mips64-mips64-linux-gnuabi64") Mips64UnknownLinuxMusl|Some("mips64-mips64-linux-musl") MipselSonyPsp|None MipselUnknownLinuxGnu|Some("mipsel-mips32-linux-gnu") MipselUnknownLinuxMusl|Some("mipsel-mips32-linux-musl") MipselUnknownLinuxUclibc|None MipselUnknownNone|Some("mipsel-mips32-other-eabi") Mipsisa32r6elUnknownLinuxGnu|Some("mips-mips32-linux-gnu") Mipsisa32r6UnknownLinuxGnu|Some("mips-mips32r6-linux-gnu") Mipsisa64r6elUnknownLinuxGnuabi64|Some("mips-mips32-linux-gnuabi64") Mipsisa64r6UnknownLinuxGnuabi64|Some("mips-mips64r6-linux-gnuabi64") MipsUnknownLinuxGnu|Some("mips-mips32-linux-gnu") MipsUnknownLinuxMusl|Some("mips-mips32-linux-musl") MipsUnknownLinuxUclibc|None Msp430NoneElf|Some("msp430-msp430-other-eabi") Powerpc64leUnknownLinuxGnu|Some("powerpc64le-ppc64le-linux-gnu") Powerpc64leUnknownLinuxMusl|Some("powerpc64le-ppc64le-linux-musl") Powerpc64UnknownFreebsd|Some("powerpc64-ppc64-freebsd-gnu") Powerpc64UnknownLinuxGnu|Some("powerpc64-ppc64-linux-gnu") Powerpc64UnknownLinuxMusl|Some("powerpc64-ppc64-linux-musl") PowerpcUnknownLinuxGnu|Some("powerpc-ppc-linux-gnu") PowerpcUnknownLinuxGnuspe|None PowerpcUnknownLinuxMusl|Some("powerpc-ppc-linux-musl") PowerpcUnknownNetbsd|Some("powerpc-ppc-netbsd-gnu") Riscv32|Some("riscv32-baseline_rv32-other-eabi") Riscv32UnknownLinuxGnu|Some("riscv32-baseline_rv32-linux-gnu") Riscv64|Some("riscv64-baseline_rv64-other-eabi") Riscv64UnknownLinuxGnu|Some("riscv64-baseline_rv64-linux-gnu") S390xUnknownLinuxGnu|Some("s390x-generic-linux-gnu") Sparc64UnknownLinuxGnu|Some("sparc64-v9-linux-gnu") Sparc64UnknownNetbsd|Some("sparc64-v9-netbsd-gnu") Sparc64UnknownOpenbsd|Some("sparc64-v9-openbsd-gnu") SparcUnknownLinuxGnu|Some("sparc-v8-linux-gnu") Sparcv9SunSolaris|Some("sparc-v9-solaris-eabi") Thumbv4tNoneEabi|Some("thumb-arm710t-other-eabi") Thumbv6mNoneEabi|Some("thumb-cortex_m0-other-eabi") Thumbv7emNoneEabihf|Some("thumb-cortex_m4-other-eabihf") Thumbv7emNoneEabi|Some("thumb-cortex_m4-other-eabi") Thumbv7mNoneEabi|Some("thumb-cortex_m3-other-eabi") Thumbv8mBaseNoneEabi|Some("thumb-baseline-other-eabi") Thumbv8mMainNoneEabihf|Some("thumb-cortex_m33-other-eabihf") Thumbv8mMainNoneEabi|Some("thumb-cortex_m33-other-eabi") Wasm32UnknownEmscripten|Some("wasm32-generic-emscripten-musl") Wasm32UnknownUnknown|Some("wasm32-generic-other-musl") Wasm32Wasi|Some("wasm32-generic-wasi-musl") X86_64AppleIosMacabi|Some("x86_64-x86_64-ios-macabi") X86_64AppleIos|Some("x86_64-x86_64-ios-none") X86_64AppleMacosx|Some("x86_64-x86_64-macos-none") X86_64AppleTvos|Some("x86_64-x86_64-tvos-none") X86_64Elf|Some("x86_64-x86_64-other-eabi") X86_64Fuchsia|Some("x86_64-x86_64-fuchsia-gnu") X86_64LinuxAndroid|Some("x86_64-x86_64-linux-android") X86_64PcSolaris|Some("x86_64-x86_64-solaris-eabi") X86_64PcWindowsGnu|Some("x86_64-x86_64-windows-gnu") X86_64RumprunNetbsd|None X86_64UnknownDragonfly|Some("x86_64-x86_64-dragonfly-eabi") X86_64UnknownFreebsd|Some("x86_64-x86_64-freebsd-gnu") X86_64UnknownHaiku|Some("x86_64-x86_64-haiku-gnu") X86_64UnknownHermit|Some("x86_64-x86_64-hermit-eabi") X86_64UnknownL4reUclibc|None X86_64UnknownLinuxGnux32|Some("x86_64-x86_64-linux-gnux32") X86_64UnknownLinuxGnu|Some("x86_64-x86_64-linux-gnu") X86_64UnknownLinuxMusl|Some("x86_64-x86_64-linux-musl") X86_64UnknownNetbsd|Some("x86_64-x86_64-netbsd-gnu") X86_64UnknownOpenbsd|Some("x86_64-x86_64-openbsd-gnu") X86_64UnknownRedox|None 
#ifdef ONE
_Static_assert(sizeof(A) == 3, "");
_Static_assert(_Alignof(A) == 2, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 6, "");
_Static_assert(_Alignof(struct A_alignment) == 2, "");
_Static_assert(sizeof(struct A_packed) == 3, "");
_Static_assert(_Alignof(struct A_packed) == 1, "");
_Static_assert(sizeof(struct A_required_alignment) == 4, "");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "");
_Static_assert(sizeof(struct A_size) == 5, "");
_Static_assert(_Alignof(struct A_size) == 1, "");
#endif
_Static_assert(sizeof(B) == 10, "");
_Static_assert(_Alignof(B) == 2, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 12, "");
_Static_assert(_Alignof(struct B_alignment) == 2, "");
_Static_assert(sizeof(struct B_packed) == 10, "");
_Static_assert(_Alignof(struct B_packed) == 1, "");
_Static_assert(sizeof(struct B_required_alignment) == 11, "");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "");
_Static_assert(sizeof(struct B_size) == 12, "");
_Static_assert(_Alignof(struct B_size) == 1, "");
#endif
_Static_assert(sizeof(C) == 3, "");
_Static_assert(_Alignof(C) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 4, "");
_Static_assert(_Alignof(struct C_alignment) == 1, "");
_Static_assert(sizeof(struct C_packed) == 3, "");
_Static_assert(_Alignof(struct C_packed) == 1, "");
_Static_assert(sizeof(struct C_required_alignment) == 4, "");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "");
_Static_assert(sizeof(struct C_size) == 5, "");
_Static_assert(_Alignof(struct C_size) == 1, "");
#endif
_Static_assert(sizeof(D) == 0, "");
_Static_assert(_Alignof(D) == 2, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 2, "");
_Static_assert(_Alignof(struct D_alignment) == 2, "");
_Static_assert(sizeof(struct D_packed) == 0, "");
_Static_assert(_Alignof(struct D_packed) == 1, "");
_Static_assert(sizeof(struct D_required_alignment) == 1, "");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "");
_Static_assert(sizeof(struct D_size) == 2, "");
_Static_assert(_Alignof(struct D_size) == 1, "");
#endif
_Static_assert(sizeof(E) == 2, "");
_Static_assert(_Alignof(E) == 2, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 4, "");
_Static_assert(_Alignof(struct E_alignment) == 2, "");
_Static_assert(sizeof(struct E_packed) == 2, "");
_Static_assert(_Alignof(struct E_packed) == 1, "");
_Static_assert(sizeof(struct E_required_alignment) == 3, "");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "");
_Static_assert(sizeof(struct E_size) == 4, "");
_Static_assert(_Alignof(struct E_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(E,d) == 16, "");
#endif
_Static_assert(sizeof(F) == 2, "");
_Static_assert(_Alignof(F) == 2, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 4, "");
_Static_assert(_Alignof(struct F_alignment) == 2, "");
_Static_assert(sizeof(struct F_packed) == 2, "");
_Static_assert(_Alignof(struct F_packed) == 1, "");
_Static_assert(sizeof(struct F_required_alignment) == 3, "");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "");
_Static_assert(sizeof(struct F_size) == 4, "");
_Static_assert(_Alignof(struct F_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F,d) == 16, "");
#endif
// MAPPING|TWO|aarch64-generic-windows-msvc:Msvc|i386-i586-windows-msvc:Msvc|i386-i686-windows-msvc:Msvc|i386-i686-uefi-msvc:Msvc|thumb-baseline-windows-msvc:Msvc|x86_64-x86_64-windows-msvc:Msvc|x86_64-x86_64-uefi-msvc:Msvc|END
// repr targets Aarch64PcWindowsMsvc|Some("aarch64-generic-windows-msvc") I586PcWindowsMsvc|Some("i386-i586-windows-msvc") I686PcWindowsMsvc|Some("i386-i686-windows-msvc") I686UnknownWindows|Some("i386-i686-uefi-msvc") Thumbv7aPcWindowsMsvc|Some("thumb-baseline-windows-msvc") X86_64PcWindowsMsvc|Some("x86_64-x86_64-windows-msvc") X86_64UnknownWindows|Some("x86_64-x86_64-uefi-msvc") 
#elif defined(TWO)
_Static_assert(sizeof(A) == 3, "");
_Static_assert(_Alignof(A) == 2, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 6, "");
_Static_assert(_Alignof(struct A_alignment) == 2, "");
_Static_assert(sizeof(struct A_packed) == 3, "");
_Static_assert(_Alignof(struct A_packed) == 1, "");
_Static_assert(sizeof(struct A_required_alignment) == 4, "");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "");
_Static_assert(sizeof(struct A_size) == 5, "");
_Static_assert(_Alignof(struct A_size) == 1, "");
#endif
_Static_assert(sizeof(B) == 9, "");
_Static_assert(_Alignof(B) == 2, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 12, "");
_Static_assert(_Alignof(struct B_alignment) == 2, "");
_Static_assert(sizeof(struct B_packed) == 9, "");
_Static_assert(_Alignof(struct B_packed) == 1, "");
_Static_assert(sizeof(struct B_required_alignment) == 10, "");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "");
_Static_assert(sizeof(struct B_size) == 11, "");
_Static_assert(_Alignof(struct B_size) == 1, "");
#endif
_Static_assert(sizeof(C) == 3, "");
_Static_assert(_Alignof(C) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 4, "");
_Static_assert(_Alignof(struct C_alignment) == 1, "");
_Static_assert(sizeof(struct C_packed) == 3, "");
_Static_assert(_Alignof(struct C_packed) == 1, "");
_Static_assert(sizeof(struct C_required_alignment) == 4, "");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "");
_Static_assert(sizeof(struct C_size) == 5, "");
_Static_assert(_Alignof(struct C_size) == 1, "");
#endif
_Static_assert(sizeof(D) == 0, "");
_Static_assert(_Alignof(D) == 2, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct D_alignment) == 2, "");
_Static_assert(_Alignof(struct D_alignment) == 2, "");
_Static_assert(sizeof(struct D_packed) == 0, "");
_Static_assert(_Alignof(struct D_packed) == 1, "");
_Static_assert(sizeof(struct D_required_alignment) == 1, "");
_Static_assert(_Alignof(struct D_required_alignment) == 1, "");
_Static_assert(sizeof(struct D_size) == 2, "");
_Static_assert(_Alignof(struct D_size) == 1, "");
#endif
_Static_assert(sizeof(E) == 2, "");
_Static_assert(_Alignof(E) == 2, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct E_alignment) == 4, "");
_Static_assert(_Alignof(struct E_alignment) == 2, "");
_Static_assert(sizeof(struct E_packed) == 2, "");
_Static_assert(_Alignof(struct E_packed) == 1, "");
_Static_assert(sizeof(struct E_required_alignment) == 3, "");
_Static_assert(_Alignof(struct E_required_alignment) == 1, "");
_Static_assert(sizeof(struct E_size) == 4, "");
_Static_assert(_Alignof(struct E_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(E,d) == 16, "");
#endif
_Static_assert(sizeof(F) == 2, "");
_Static_assert(_Alignof(F) == 2, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct F_alignment) == 4, "");
_Static_assert(_Alignof(struct F_alignment) == 2, "");
_Static_assert(sizeof(struct F_packed) == 2, "");
_Static_assert(_Alignof(struct F_packed) == 1, "");
_Static_assert(sizeof(struct F_required_alignment) == 3, "");
_Static_assert(_Alignof(struct F_required_alignment) == 1, "");
_Static_assert(sizeof(struct F_size) == 4, "");
_Static_assert(_Alignof(struct F_size) == 1, "");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(F,d) == 16, "");
#endif
#endif
