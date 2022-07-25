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

// MAPPING|ONE|aarch64-generic-macos-none:Clang|aarch64-generic-fuchsia-gnu:Clang|aarch64-generic-linux-android:Clang|aarch64-generic-freebsd-gnu:Clang|aarch64-generic-hermit-eabi:Clang|aarch64-generic-linux-gnu:Gcc|aarch64-generic-linux-musl:Gcc|aarch64-generic-netbsd-gnu:Clang|aarch64-generic-other-none:Clang|aarch64-generic-openbsd-gnu:Clang|aarch64-generic-ios-none:Clang|aarch64-generic-ios-macabi:Clang|aarch64-generic-tvos-none:Clang|arm-baseline-other-eabi:Clang|arm-baseline-other-eabihf:Clang|arm-baseline-linux-gnueabi:Gcc|arm-baseline-linux-gnueabihf:Gcc|arm-arm710t-linux-gnueabi:Gcc|arm-arm1020e-linux-gnueabi:Gcc|arm-arm1136j_s-freebsd-gnu:Clang|arm-arm1136j_s-netbsd-eabihf:Clang|arm-baseline-other-eabi:Clang|arm-baseline-other-eabihf:Clang|arm-cortex_r4-other-eabi:Clang|arm-cortex_r4-other-eabihf:Clang|arm-cortex_r4-freebsd-gnu:Clang|arm-cortex_r4-linux-gnueabi:Gcc|arm-cortex_r4-linux-gnueabihf:Gcc|arm-cortex_r4-netbsd-eabihf:Clang|hexagon-generic-linux-musl:Clang|i386-i686-windows-gnu:Gcc|mips64el-mips64-linux-gnuabi64:Gcc|mips64-mips64-linux-gnuabi64:Gcc|mipsel-mips32-linux-gnu:Gcc|mipsel-mips32-linux-musl:Gcc|mipsel-mips32-other-none:Clang|mips-mips32-linux-gnu:Gcc|mips-mips32r6-linux-gnu:Gcc|mips-mips32-linux-gnuabi64:Gcc|mips-mips64r6-linux-gnuabi64:Gcc|mips-mips32-linux-gnu:Gcc|mips-mips32-linux-musl:Gcc|powerpc64le-ppc64le-linux-gnu:Gcc|powerpc64le-ppc64le-linux-musl:Gcc|powerpc64-ppc64-freebsd-gnu:Clang|powerpc64-ppc64-linux-gnu:Gcc|powerpc64-ppc64-linux-musl:Gcc|powerpc-ppc-linux-gnu:Gcc|powerpc-ppc-linux-musl:Gcc|powerpc-ppc-netbsd-gnu:Clang|riscv32-generic_rv32-other-none:Clang|riscv32-generic_rv32-linux-gnu:Gcc|riscv64-generic_rv64-other-none:Clang|riscv64-generic_rv64-linux-gnu:Gcc|s390x-generic-linux-gnu:Gcc|sparc64-v9-linux-gnu:Gcc|sparc64-v9-netbsd-gnu:Clang|sparc64-v9-openbsd-gnu:Clang|sparc-v8-linux-gnu:Gcc|sparc-v9-solaris-eabi:Clang|thumb-arm710t-other-eabi:Clang|thumb-cortex_m0-other-eabi:Clang|thumb-cortex_m4-other-eabihf:Clang|thumb-cortex_m4-other-eabi:Clang|thumb-cortex_m3-other-eabi:Clang|thumb-baseline-other-eabi:Clang|thumb-cortex_m33-other-eabihf:Clang|thumb-cortex_m33-other-eabi:Clang|wasm32-generic-emscripten-musl:Clang|wasm32-generic-other-none:Clang|wasm32-generic-wasi-musl:Clang|x86_64-x86_64-ios-macabi:Clang|x86_64-x86_64-ios-none:Clang|x86_64-x86_64-macos-none:Clang|x86_64-x86_64-tvos-none:Clang|x86_64-x86_64-fuchsia-gnu:Clang|x86_64-x86_64-linux-android:Clang|x86_64-x86_64-solaris-eabi:Clang|x86_64-x86_64-windows-gnu:Gcc|x86_64-x86_64-dragonfly-eabi:Clang|x86_64-x86_64-freebsd-gnu:Clang|x86_64-x86_64-haiku-gnu:Clang|x86_64-x86_64-hermit-eabi:Clang|x86_64-x86_64-linux-gnux32:Gcc|x86_64-x86_64-linux-gnu:Gcc|x86_64-x86_64-linux-musl:Gcc|x86_64-x86_64-netbsd-gnu:Clang|x86_64-x86_64-openbsd-gnu:Clang|END
// repr targets Aarch64AppleMacosx|Some("aarch64-generic-macos-none") Aarch64Fuchsia|Some("aarch64-generic-fuchsia-gnu") Aarch64LinuxAndroid|Some("aarch64-generic-linux-android") Aarch64UnknownFreebsd|Some("aarch64-generic-freebsd-gnu") Aarch64UnknownHermit|Some("aarch64-generic-hermit-eabi") Aarch64UnknownLinuxGnu|Some("aarch64-generic-linux-gnu") Aarch64UnknownLinuxMusl|Some("aarch64-generic-linux-musl") Aarch64UnknownNetbsd|Some("aarch64-generic-netbsd-gnu") Aarch64UnknownNone|Some("aarch64-generic-other-none") Aarch64UnknownOpenbsd|Some("aarch64-generic-openbsd-gnu") Aarch64UnknownRedox|None Arm64AppleIos|Some("aarch64-generic-ios-none") Arm64AppleIosMacabi|Some("aarch64-generic-ios-macabi") Arm64AppleTvos|Some("aarch64-generic-tvos-none") Armebv7rUnknownNoneEabi|Some("arm-baseline-other-eabi") Armebv7rUnknownNoneEabihf|Some("arm-baseline-other-eabihf") ArmLinuxAndroideabi|None ArmUnknownLinuxGnueabi|Some("arm-baseline-linux-gnueabi") ArmUnknownLinuxGnueabihf|Some("arm-baseline-linux-gnueabihf") Armv4tUnknownLinuxGnueabi|Some("arm-arm710t-linux-gnueabi") Armv5teUnknownLinuxGnueabi|Some("arm-arm1020e-linux-gnueabi") Armv5teUnknownLinuxUclibcgnueabi|None Armv6UnknownFreebsdGnueabihf|Some("arm-arm1136j_s-freebsd-gnu") Armv6UnknownNetbsdelfEabihf|Some("arm-arm1136j_s-netbsd-eabihf") Armv7aNoneEabi|Some("arm-baseline-other-eabi") Armv7aNoneEabihf|Some("arm-baseline-other-eabihf") Armv7NoneLinuxAndroid|None Armv7rUnknownNoneEabi|Some("arm-cortex_r4-other-eabi") Armv7rUnknownNoneEabihf|Some("arm-cortex_r4-other-eabihf") Armv7UnknownFreebsdGnueabihf|Some("arm-cortex_r4-freebsd-gnu") Armv7UnknownLinuxGnueabi|Some("arm-cortex_r4-linux-gnueabi") Armv7UnknownLinuxGnueabihf|Some("arm-cortex_r4-linux-gnueabihf") Armv7UnknownNetbsdelfEabihf|Some("arm-cortex_r4-netbsd-eabihf") HexagonUnknownLinuxMusl|Some("hexagon-generic-linux-musl") I686PcWindowsGnu|Some("i386-i686-windows-gnu") Mips64elUnknownLinuxGnuabi64|Some("mips64el-mips64-linux-gnuabi64") Mips64elUnknownLinuxMusl|None Mips64UnknownLinuxGnuabi64|Some("mips64-mips64-linux-gnuabi64") Mips64UnknownLinuxMusl|None MipselSonyPsp|None MipselUnknownLinuxGnu|Some("mipsel-mips32-linux-gnu") MipselUnknownLinuxMusl|Some("mipsel-mips32-linux-musl") MipselUnknownLinuxUclibc|None MipselUnknownNone|Some("mipsel-mips32-other-none") Mipsisa32r6elUnknownLinuxGnu|Some("mips-mips32-linux-gnu") Mipsisa32r6UnknownLinuxGnu|Some("mips-mips32r6-linux-gnu") Mipsisa64r6elUnknownLinuxGnuabi64|Some("mips-mips32-linux-gnuabi64") Mipsisa64r6UnknownLinuxGnuabi64|Some("mips-mips64r6-linux-gnuabi64") MipsUnknownLinuxGnu|Some("mips-mips32-linux-gnu") MipsUnknownLinuxMusl|Some("mips-mips32-linux-musl") MipsUnknownLinuxUclibc|None Powerpc64leUnknownLinuxGnu|Some("powerpc64le-ppc64le-linux-gnu") Powerpc64leUnknownLinuxMusl|Some("powerpc64le-ppc64le-linux-musl") Powerpc64UnknownFreebsd|Some("powerpc64-ppc64-freebsd-gnu") Powerpc64UnknownLinuxGnu|Some("powerpc64-ppc64-linux-gnu") Powerpc64UnknownLinuxMusl|Some("powerpc64-ppc64-linux-musl") PowerpcUnknownLinuxGnu|Some("powerpc-ppc-linux-gnu") PowerpcUnknownLinuxGnuspe|None PowerpcUnknownLinuxMusl|Some("powerpc-ppc-linux-musl") PowerpcUnknownNetbsd|Some("powerpc-ppc-netbsd-gnu") Riscv32|Some("riscv32-generic_rv32-other-none") Riscv32UnknownLinuxGnu|Some("riscv32-generic_rv32-linux-gnu") Riscv64|Some("riscv64-generic_rv64-other-none") Riscv64UnknownLinuxGnu|Some("riscv64-generic_rv64-linux-gnu") S390xUnknownLinuxGnu|Some("s390x-generic-linux-gnu") Sparc64UnknownLinuxGnu|Some("sparc64-v9-linux-gnu") Sparc64UnknownNetbsd|Some("sparc64-v9-netbsd-gnu") Sparc64UnknownOpenbsd|Some("sparc64-v9-openbsd-gnu") SparcUnknownLinuxGnu|Some("sparc-v8-linux-gnu") Sparcv9SunSolaris|Some("sparc-v9-solaris-eabi") Thumbv4tNoneEabi|Some("thumb-arm710t-other-eabi") Thumbv6mNoneEabi|Some("thumb-cortex_m0-other-eabi") Thumbv7emNoneEabihf|Some("thumb-cortex_m4-other-eabihf") Thumbv7emNoneEabi|Some("thumb-cortex_m4-other-eabi") Thumbv7mNoneEabi|Some("thumb-cortex_m3-other-eabi") Thumbv8mBaseNoneEabi|Some("thumb-baseline-other-eabi") Thumbv8mMainNoneEabihf|Some("thumb-cortex_m33-other-eabihf") Thumbv8mMainNoneEabi|Some("thumb-cortex_m33-other-eabi") Wasm32UnknownEmscripten|Some("wasm32-generic-emscripten-musl") Wasm32UnknownUnknown|Some("wasm32-generic-other-none") Wasm32Wasi|Some("wasm32-generic-wasi-musl") X86_64AppleIosMacabi|Some("x86_64-x86_64-ios-macabi") X86_64AppleIos|Some("x86_64-x86_64-ios-none") X86_64AppleMacosx|Some("x86_64-x86_64-macos-none") X86_64AppleTvos|Some("x86_64-x86_64-tvos-none") X86_64Elf|None X86_64Fuchsia|Some("x86_64-x86_64-fuchsia-gnu") X86_64LinuxAndroid|Some("x86_64-x86_64-linux-android") X86_64PcSolaris|Some("x86_64-x86_64-solaris-eabi") X86_64PcWindowsGnu|Some("x86_64-x86_64-windows-gnu") X86_64RumprunNetbsd|None X86_64UnknownDragonfly|Some("x86_64-x86_64-dragonfly-eabi") X86_64UnknownFreebsd|Some("x86_64-x86_64-freebsd-gnu") X86_64UnknownHaiku|Some("x86_64-x86_64-haiku-gnu") X86_64UnknownHermit|Some("x86_64-x86_64-hermit-eabi") X86_64UnknownL4reUclibc|None X86_64UnknownLinuxGnux32|Some("x86_64-x86_64-linux-gnux32") X86_64UnknownLinuxGnu|Some("x86_64-x86_64-linux-gnu") X86_64UnknownLinuxMusl|Some("x86_64-x86_64-linux-musl") X86_64UnknownNetbsd|Some("x86_64-x86_64-netbsd-gnu") X86_64UnknownOpenbsd|Some("x86_64-x86_64-openbsd-gnu") X86_64UnknownRedox|None 
#ifdef ONE
_Static_assert(sizeof(EmptyIntMemb) == 0, "");
_Static_assert(_Alignof(EmptyIntMemb) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyIntMemb_alignment) == 4, "");
_Static_assert(_Alignof(struct EmptyIntMemb_alignment) == 4, "");
_Static_assert(sizeof(struct EmptyIntMemb_packed) == 0, "");
_Static_assert(_Alignof(struct EmptyIntMemb_packed) == 1, "");
_Static_assert(sizeof(struct EmptyIntMemb_required_alignment) == 1, "");
_Static_assert(_Alignof(struct EmptyIntMemb_required_alignment) == 1, "");
_Static_assert(sizeof(struct EmptyIntMemb_size) == 2, "");
_Static_assert(_Alignof(struct EmptyIntMemb_size) == 1, "");
#endif
_Static_assert(sizeof(EmptyLongLongMemb) == 0, "");
_Static_assert(_Alignof(EmptyLongLongMemb) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyLongLongMemb_alignment) == 8, "");
_Static_assert(_Alignof(struct EmptyLongLongMemb_alignment) == 8, "");
_Static_assert(sizeof(struct EmptyLongLongMemb_packed) == 0, "");
_Static_assert(_Alignof(struct EmptyLongLongMemb_packed) == 1, "");
_Static_assert(sizeof(struct EmptyLongLongMemb_required_alignment) == 1, "");
_Static_assert(_Alignof(struct EmptyLongLongMemb_required_alignment) == 1, "");
_Static_assert(sizeof(struct EmptyLongLongMemb_size) == 2, "");
_Static_assert(_Alignof(struct EmptyLongLongMemb_size) == 1, "");
#endif
_Static_assert(sizeof(EmptyAligned2LongLongMemb) == 0, "");
_Static_assert(_Alignof(EmptyAligned2LongLongMemb) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyAligned2LongLongMemb_alignment) == 8, "");
_Static_assert(_Alignof(struct EmptyAligned2LongLongMemb_alignment) == 8, "");
_Static_assert(sizeof(struct EmptyAligned2LongLongMemb_packed) == 0, "");
_Static_assert(_Alignof(struct EmptyAligned2LongLongMemb_packed) == 1, "");
_Static_assert(sizeof(struct EmptyAligned2LongLongMemb_required_alignment) == 1, "");
_Static_assert(_Alignof(struct EmptyAligned2LongLongMemb_required_alignment) == 1, "");
_Static_assert(sizeof(struct EmptyAligned2LongLongMemb_size) == 2, "");
_Static_assert(_Alignof(struct EmptyAligned2LongLongMemb_size) == 1, "");
#endif
_Static_assert(sizeof(EmptyAligned8LongLongMemb) == 0, "");
_Static_assert(_Alignof(EmptyAligned8LongLongMemb) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyAligned8LongLongMemb_alignment) == 8, "");
_Static_assert(_Alignof(struct EmptyAligned8LongLongMemb_alignment) == 8, "");
_Static_assert(sizeof(struct EmptyAligned8LongLongMemb_packed) == 0, "");
_Static_assert(_Alignof(struct EmptyAligned8LongLongMemb_packed) == 1, "");
_Static_assert(sizeof(struct EmptyAligned8LongLongMemb_required_alignment) == 1, "");
_Static_assert(_Alignof(struct EmptyAligned8LongLongMemb_required_alignment) == 1, "");
_Static_assert(sizeof(struct EmptyAligned8LongLongMemb_size) == 2, "");
_Static_assert(_Alignof(struct EmptyAligned8LongLongMemb_size) == 1, "");
#endif
_Static_assert(sizeof(EmptyPackedAligned4LongLongMemb) == 0, "");
_Static_assert(_Alignof(EmptyPackedAligned4LongLongMemb) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyPackedAligned4LongLongMemb_alignment) == 4, "");
_Static_assert(_Alignof(struct EmptyPackedAligned4LongLongMemb_alignment) == 4, "");
_Static_assert(sizeof(struct EmptyPackedAligned4LongLongMemb_packed) == 0, "");
_Static_assert(_Alignof(struct EmptyPackedAligned4LongLongMemb_packed) == 1, "");
_Static_assert(sizeof(struct EmptyPackedAligned4LongLongMemb_required_alignment) == 1, "");
_Static_assert(_Alignof(struct EmptyPackedAligned4LongLongMemb_required_alignment) == 1, "");
_Static_assert(sizeof(struct EmptyPackedAligned4LongLongMemb_size) == 2, "");
_Static_assert(_Alignof(struct EmptyPackedAligned4LongLongMemb_size) == 1, "");
#endif
_Static_assert(sizeof(EmptyPackedAligned8LongLongMemb) == 0, "");
_Static_assert(_Alignof(EmptyPackedAligned8LongLongMemb) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyPackedAligned8LongLongMemb_alignment) == 1, "");
_Static_assert(_Alignof(struct EmptyPackedAligned8LongLongMemb_alignment) == 1, "");
_Static_assert(sizeof(struct EmptyPackedAligned8LongLongMemb_packed) == 0, "");
_Static_assert(_Alignof(struct EmptyPackedAligned8LongLongMemb_packed) == 1, "");
_Static_assert(sizeof(struct EmptyPackedAligned8LongLongMemb_required_alignment) == 1, "");
_Static_assert(_Alignof(struct EmptyPackedAligned8LongLongMemb_required_alignment) == 1, "");
_Static_assert(sizeof(struct EmptyPackedAligned8LongLongMemb_size) == 2, "");
_Static_assert(_Alignof(struct EmptyPackedAligned8LongLongMemb_size) == 1, "");
#endif
// MAPPING|TWO|aarch64-generic-windows-msvc:Msvc|i386-i586-windows-msvc:Msvc|i386-i686-windows-msvc:Msvc|i386-i686-uefi-msvc:Msvc|thumb-baseline-windows-msvc:Msvc|x86_64-x86_64-windows-msvc:Msvc|x86_64-x86_64-uefi-msvc:Msvc|END
// repr targets Aarch64PcWindowsMsvc|Some("aarch64-generic-windows-msvc") I586PcWindowsMsvc|Some("i386-i586-windows-msvc") I686PcWindowsMsvc|Some("i386-i686-windows-msvc") I686UnknownWindows|Some("i386-i686-uefi-msvc") Thumbv7aPcWindowsMsvc|Some("thumb-baseline-windows-msvc") X86_64PcWindowsMsvc|Some("x86_64-x86_64-windows-msvc") X86_64UnknownWindows|Some("x86_64-x86_64-uefi-msvc") 
#elif defined(TWO)
_Static_assert(sizeof(EmptyIntMemb) == 4, "");
_Static_assert(_Alignof(EmptyIntMemb) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyIntMemb_alignment) == 8, "");
_Static_assert(_Alignof(struct EmptyIntMemb_alignment) == 4, "");
_Static_assert(sizeof(struct EmptyIntMemb_packed) == 4, "");
_Static_assert(_Alignof(struct EmptyIntMemb_packed) == 1, "");
_Static_assert(sizeof(struct EmptyIntMemb_required_alignment) == 5, "");
_Static_assert(_Alignof(struct EmptyIntMemb_required_alignment) == 1, "");
_Static_assert(sizeof(struct EmptyIntMemb_size) == 6, "");
_Static_assert(_Alignof(struct EmptyIntMemb_size) == 1, "");
#endif
_Static_assert(sizeof(EmptyLongLongMemb) == 4, "");
_Static_assert(_Alignof(EmptyLongLongMemb) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyLongLongMemb_alignment) == 16, "");
_Static_assert(_Alignof(struct EmptyLongLongMemb_alignment) == 8, "");
_Static_assert(sizeof(struct EmptyLongLongMemb_packed) == 4, "");
_Static_assert(_Alignof(struct EmptyLongLongMemb_packed) == 1, "");
_Static_assert(sizeof(struct EmptyLongLongMemb_required_alignment) == 5, "");
_Static_assert(_Alignof(struct EmptyLongLongMemb_required_alignment) == 1, "");
_Static_assert(sizeof(struct EmptyLongLongMemb_size) == 6, "");
_Static_assert(_Alignof(struct EmptyLongLongMemb_size) == 1, "");
#endif
_Static_assert(sizeof(EmptyAligned2LongLongMemb) == 4, "");
_Static_assert(_Alignof(EmptyAligned2LongLongMemb) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyAligned2LongLongMemb_alignment) == 16, "");
_Static_assert(_Alignof(struct EmptyAligned2LongLongMemb_alignment) == 8, "");
_Static_assert(sizeof(struct EmptyAligned2LongLongMemb_packed) == 4, "");
_Static_assert(_Alignof(struct EmptyAligned2LongLongMemb_packed) == 1, "");
_Static_assert(sizeof(struct EmptyAligned2LongLongMemb_required_alignment) == 5, "");
_Static_assert(_Alignof(struct EmptyAligned2LongLongMemb_required_alignment) == 1, "");
_Static_assert(sizeof(struct EmptyAligned2LongLongMemb_size) == 6, "");
_Static_assert(_Alignof(struct EmptyAligned2LongLongMemb_size) == 1, "");
#endif
_Static_assert(sizeof(EmptyAligned8LongLongMemb) == 8, "");
_Static_assert(_Alignof(EmptyAligned8LongLongMemb) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyAligned8LongLongMemb_alignment) == 16, "");
_Static_assert(_Alignof(struct EmptyAligned8LongLongMemb_alignment) == 8, "");
_Static_assert(sizeof(struct EmptyAligned8LongLongMemb_packed) == 8, "");
_Static_assert(_Alignof(struct EmptyAligned8LongLongMemb_packed) == 1, "");
_Static_assert(sizeof(struct EmptyAligned8LongLongMemb_required_alignment) == 9, "");
_Static_assert(_Alignof(struct EmptyAligned8LongLongMemb_required_alignment) == 1, "");
_Static_assert(sizeof(struct EmptyAligned8LongLongMemb_size) == 10, "");
_Static_assert(_Alignof(struct EmptyAligned8LongLongMemb_size) == 1, "");
#endif
_Static_assert(sizeof(EmptyPackedAligned4LongLongMemb) == 4, "");
_Static_assert(_Alignof(EmptyPackedAligned4LongLongMemb) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyPackedAligned4LongLongMemb_alignment) == 8, "");
_Static_assert(_Alignof(struct EmptyPackedAligned4LongLongMemb_alignment) == 4, "");
_Static_assert(sizeof(struct EmptyPackedAligned4LongLongMemb_packed) == 4, "");
_Static_assert(_Alignof(struct EmptyPackedAligned4LongLongMemb_packed) == 1, "");
_Static_assert(sizeof(struct EmptyPackedAligned4LongLongMemb_required_alignment) == 5, "");
_Static_assert(_Alignof(struct EmptyPackedAligned4LongLongMemb_required_alignment) == 1, "");
_Static_assert(sizeof(struct EmptyPackedAligned4LongLongMemb_size) == 6, "");
_Static_assert(_Alignof(struct EmptyPackedAligned4LongLongMemb_size) == 1, "");
#endif
_Static_assert(sizeof(EmptyPackedAligned8LongLongMemb) == 8, "");
_Static_assert(_Alignof(EmptyPackedAligned8LongLongMemb) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyPackedAligned8LongLongMemb_alignment) == 16, "");
_Static_assert(_Alignof(struct EmptyPackedAligned8LongLongMemb_alignment) == 8, "");
_Static_assert(sizeof(struct EmptyPackedAligned8LongLongMemb_packed) == 8, "");
_Static_assert(_Alignof(struct EmptyPackedAligned8LongLongMemb_packed) == 1, "");
_Static_assert(sizeof(struct EmptyPackedAligned8LongLongMemb_required_alignment) == 9, "");
_Static_assert(_Alignof(struct EmptyPackedAligned8LongLongMemb_required_alignment) == 1, "");
_Static_assert(sizeof(struct EmptyPackedAligned8LongLongMemb_size) == 10, "");
_Static_assert(_Alignof(struct EmptyPackedAligned8LongLongMemb_size) == 1, "");
#endif
// MAPPING|THREE|arm-cortex_r4-ios-none:Clang|arm-baseline-ios-none:Clang|i386-i386-ios-none:Clang|i386-i586-linux-gnu:Gcc|i386-i586-linux-musl:Gcc|x86_64-i686-macos-none:Clang|i386-i686-linux-android:Clang|i386-i686-freebsd-gnu:Clang|i386-i686-haiku-gnu:Clang|i386-i686-linux-gnu:Gcc|i386-i686-linux-musl:Gcc|i386-i686-netbsd-gnu:Clang|i386-i686-openbsd-gnu:Clang|END
// repr targets Armv7AppleIos|Some("arm-cortex_r4-ios-none") Armv7sAppleIos|Some("arm-baseline-ios-none") I386AppleIos|Some("i386-i386-ios-none") I586UnknownLinuxGnu|Some("i386-i586-linux-gnu") I586UnknownLinuxMusl|Some("i386-i586-linux-musl") I686AppleMacosx|Some("x86_64-i686-macos-none") I686LinuxAndroid|Some("i386-i686-linux-android") I686UnknownFreebsd|Some("i386-i686-freebsd-gnu") I686UnknownHaiku|Some("i386-i686-haiku-gnu") I686UnknownLinuxGnu|Some("i386-i686-linux-gnu") I686UnknownLinuxMusl|Some("i386-i686-linux-musl") I686UnknownNetbsdelf|Some("i386-i686-netbsd-gnu") I686UnknownOpenbsd|Some("i386-i686-openbsd-gnu") 
#elif defined(THREE)
_Static_assert(sizeof(EmptyIntMemb) == 0, "");
_Static_assert(_Alignof(EmptyIntMemb) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyIntMemb_alignment) == 4, "");
_Static_assert(_Alignof(struct EmptyIntMemb_alignment) == 4, "");
_Static_assert(sizeof(struct EmptyIntMemb_packed) == 0, "");
_Static_assert(_Alignof(struct EmptyIntMemb_packed) == 1, "");
_Static_assert(sizeof(struct EmptyIntMemb_required_alignment) == 1, "");
_Static_assert(_Alignof(struct EmptyIntMemb_required_alignment) == 1, "");
_Static_assert(sizeof(struct EmptyIntMemb_size) == 2, "");
_Static_assert(_Alignof(struct EmptyIntMemb_size) == 1, "");
#endif
_Static_assert(sizeof(EmptyLongLongMemb) == 0, "");
_Static_assert(_Alignof(EmptyLongLongMemb) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyLongLongMemb_alignment) == 4, "");
_Static_assert(_Alignof(struct EmptyLongLongMemb_alignment) == 4, "");
_Static_assert(sizeof(struct EmptyLongLongMemb_packed) == 0, "");
_Static_assert(_Alignof(struct EmptyLongLongMemb_packed) == 1, "");
_Static_assert(sizeof(struct EmptyLongLongMemb_required_alignment) == 1, "");
_Static_assert(_Alignof(struct EmptyLongLongMemb_required_alignment) == 1, "");
_Static_assert(sizeof(struct EmptyLongLongMemb_size) == 2, "");
_Static_assert(_Alignof(struct EmptyLongLongMemb_size) == 1, "");
#endif
_Static_assert(sizeof(EmptyAligned2LongLongMemb) == 0, "");
_Static_assert(_Alignof(EmptyAligned2LongLongMemb) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyAligned2LongLongMemb_alignment) == 4, "");
_Static_assert(_Alignof(struct EmptyAligned2LongLongMemb_alignment) == 4, "");
_Static_assert(sizeof(struct EmptyAligned2LongLongMemb_packed) == 0, "");
_Static_assert(_Alignof(struct EmptyAligned2LongLongMemb_packed) == 1, "");
_Static_assert(sizeof(struct EmptyAligned2LongLongMemb_required_alignment) == 1, "");
_Static_assert(_Alignof(struct EmptyAligned2LongLongMemb_required_alignment) == 1, "");
_Static_assert(sizeof(struct EmptyAligned2LongLongMemb_size) == 2, "");
_Static_assert(_Alignof(struct EmptyAligned2LongLongMemb_size) == 1, "");
#endif
_Static_assert(sizeof(EmptyAligned8LongLongMemb) == 0, "");
_Static_assert(_Alignof(EmptyAligned8LongLongMemb) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyAligned8LongLongMemb_alignment) == 8, "");
_Static_assert(_Alignof(struct EmptyAligned8LongLongMemb_alignment) == 8, "");
_Static_assert(sizeof(struct EmptyAligned8LongLongMemb_packed) == 0, "");
_Static_assert(_Alignof(struct EmptyAligned8LongLongMemb_packed) == 1, "");
_Static_assert(sizeof(struct EmptyAligned8LongLongMemb_required_alignment) == 1, "");
_Static_assert(_Alignof(struct EmptyAligned8LongLongMemb_required_alignment) == 1, "");
_Static_assert(sizeof(struct EmptyAligned8LongLongMemb_size) == 2, "");
_Static_assert(_Alignof(struct EmptyAligned8LongLongMemb_size) == 1, "");
#endif
_Static_assert(sizeof(EmptyPackedAligned4LongLongMemb) == 0, "");
_Static_assert(_Alignof(EmptyPackedAligned4LongLongMemb) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyPackedAligned4LongLongMemb_alignment) == 4, "");
_Static_assert(_Alignof(struct EmptyPackedAligned4LongLongMemb_alignment) == 4, "");
_Static_assert(sizeof(struct EmptyPackedAligned4LongLongMemb_packed) == 0, "");
_Static_assert(_Alignof(struct EmptyPackedAligned4LongLongMemb_packed) == 1, "");
_Static_assert(sizeof(struct EmptyPackedAligned4LongLongMemb_required_alignment) == 1, "");
_Static_assert(_Alignof(struct EmptyPackedAligned4LongLongMemb_required_alignment) == 1, "");
_Static_assert(sizeof(struct EmptyPackedAligned4LongLongMemb_size) == 2, "");
_Static_assert(_Alignof(struct EmptyPackedAligned4LongLongMemb_size) == 1, "");
#endif
_Static_assert(sizeof(EmptyPackedAligned8LongLongMemb) == 0, "");
_Static_assert(_Alignof(EmptyPackedAligned8LongLongMemb) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyPackedAligned8LongLongMemb_alignment) == 1, "");
_Static_assert(_Alignof(struct EmptyPackedAligned8LongLongMemb_alignment) == 1, "");
_Static_assert(sizeof(struct EmptyPackedAligned8LongLongMemb_packed) == 0, "");
_Static_assert(_Alignof(struct EmptyPackedAligned8LongLongMemb_packed) == 1, "");
_Static_assert(sizeof(struct EmptyPackedAligned8LongLongMemb_required_alignment) == 1, "");
_Static_assert(_Alignof(struct EmptyPackedAligned8LongLongMemb_required_alignment) == 1, "");
_Static_assert(sizeof(struct EmptyPackedAligned8LongLongMemb_size) == 2, "");
_Static_assert(_Alignof(struct EmptyPackedAligned8LongLongMemb_size) == 1, "");
#endif
// MAPPING|FOUR|avr-atmega328-other-gnu:Gcc|END
// repr targets AvrUnknownUnknown|Some("avr-atmega328-other-gnu") 
#elif defined(FOUR)
_Static_assert(sizeof(EmptyIntMemb) == 0, "");
_Static_assert(_Alignof(EmptyIntMemb) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyIntMemb_alignment) == 1, "");
_Static_assert(_Alignof(struct EmptyIntMemb_alignment) == 1, "");
_Static_assert(sizeof(struct EmptyIntMemb_packed) == 0, "");
_Static_assert(_Alignof(struct EmptyIntMemb_packed) == 1, "");
_Static_assert(sizeof(struct EmptyIntMemb_required_alignment) == 1, "");
_Static_assert(_Alignof(struct EmptyIntMemb_required_alignment) == 1, "");
_Static_assert(sizeof(struct EmptyIntMemb_size) == 2, "");
_Static_assert(_Alignof(struct EmptyIntMemb_size) == 1, "");
#endif
_Static_assert(sizeof(EmptyLongLongMemb) == 0, "");
_Static_assert(_Alignof(EmptyLongLongMemb) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyLongLongMemb_alignment) == 1, "");
_Static_assert(_Alignof(struct EmptyLongLongMemb_alignment) == 1, "");
_Static_assert(sizeof(struct EmptyLongLongMemb_packed) == 0, "");
_Static_assert(_Alignof(struct EmptyLongLongMemb_packed) == 1, "");
_Static_assert(sizeof(struct EmptyLongLongMemb_required_alignment) == 1, "");
_Static_assert(_Alignof(struct EmptyLongLongMemb_required_alignment) == 1, "");
_Static_assert(sizeof(struct EmptyLongLongMemb_size) == 2, "");
_Static_assert(_Alignof(struct EmptyLongLongMemb_size) == 1, "");
#endif
_Static_assert(sizeof(EmptyAligned2LongLongMemb) == 0, "");
_Static_assert(_Alignof(EmptyAligned2LongLongMemb) == 2, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyAligned2LongLongMemb_alignment) == 2, "");
_Static_assert(_Alignof(struct EmptyAligned2LongLongMemb_alignment) == 2, "");
_Static_assert(sizeof(struct EmptyAligned2LongLongMemb_packed) == 0, "");
_Static_assert(_Alignof(struct EmptyAligned2LongLongMemb_packed) == 1, "");
_Static_assert(sizeof(struct EmptyAligned2LongLongMemb_required_alignment) == 1, "");
_Static_assert(_Alignof(struct EmptyAligned2LongLongMemb_required_alignment) == 1, "");
_Static_assert(sizeof(struct EmptyAligned2LongLongMemb_size) == 2, "");
_Static_assert(_Alignof(struct EmptyAligned2LongLongMemb_size) == 1, "");
#endif
_Static_assert(sizeof(EmptyAligned8LongLongMemb) == 0, "");
_Static_assert(_Alignof(EmptyAligned8LongLongMemb) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyAligned8LongLongMemb_alignment) == 8, "");
_Static_assert(_Alignof(struct EmptyAligned8LongLongMemb_alignment) == 8, "");
_Static_assert(sizeof(struct EmptyAligned8LongLongMemb_packed) == 0, "");
_Static_assert(_Alignof(struct EmptyAligned8LongLongMemb_packed) == 1, "");
_Static_assert(sizeof(struct EmptyAligned8LongLongMemb_required_alignment) == 1, "");
_Static_assert(_Alignof(struct EmptyAligned8LongLongMemb_required_alignment) == 1, "");
_Static_assert(sizeof(struct EmptyAligned8LongLongMemb_size) == 2, "");
_Static_assert(_Alignof(struct EmptyAligned8LongLongMemb_size) == 1, "");
#endif
_Static_assert(sizeof(EmptyPackedAligned4LongLongMemb) == 0, "");
_Static_assert(_Alignof(EmptyPackedAligned4LongLongMemb) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyPackedAligned4LongLongMemb_alignment) == 4, "");
_Static_assert(_Alignof(struct EmptyPackedAligned4LongLongMemb_alignment) == 4, "");
_Static_assert(sizeof(struct EmptyPackedAligned4LongLongMemb_packed) == 0, "");
_Static_assert(_Alignof(struct EmptyPackedAligned4LongLongMemb_packed) == 1, "");
_Static_assert(sizeof(struct EmptyPackedAligned4LongLongMemb_required_alignment) == 1, "");
_Static_assert(_Alignof(struct EmptyPackedAligned4LongLongMemb_required_alignment) == 1, "");
_Static_assert(sizeof(struct EmptyPackedAligned4LongLongMemb_size) == 2, "");
_Static_assert(_Alignof(struct EmptyPackedAligned4LongLongMemb_size) == 1, "");
#endif
_Static_assert(sizeof(EmptyPackedAligned8LongLongMemb) == 0, "");
_Static_assert(_Alignof(EmptyPackedAligned8LongLongMemb) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyPackedAligned8LongLongMemb_alignment) == 1, "");
_Static_assert(_Alignof(struct EmptyPackedAligned8LongLongMemb_alignment) == 1, "");
_Static_assert(sizeof(struct EmptyPackedAligned8LongLongMemb_packed) == 0, "");
_Static_assert(_Alignof(struct EmptyPackedAligned8LongLongMemb_packed) == 1, "");
_Static_assert(sizeof(struct EmptyPackedAligned8LongLongMemb_required_alignment) == 1, "");
_Static_assert(_Alignof(struct EmptyPackedAligned8LongLongMemb_required_alignment) == 1, "");
_Static_assert(sizeof(struct EmptyPackedAligned8LongLongMemb_size) == 2, "");
_Static_assert(_Alignof(struct EmptyPackedAligned8LongLongMemb_size) == 1, "");
#endif
// MAPPING|FIVE|msp430-msp430-other-none:Clang|END
// repr targets Msp430NoneElf|Some("msp430-msp430-other-none") 
#elif defined(FIVE)
_Static_assert(sizeof(EmptyIntMemb) == 0, "");
_Static_assert(_Alignof(EmptyIntMemb) == 2, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyIntMemb_alignment) == 2, "");
_Static_assert(_Alignof(struct EmptyIntMemb_alignment) == 2, "");
_Static_assert(sizeof(struct EmptyIntMemb_packed) == 0, "");
_Static_assert(_Alignof(struct EmptyIntMemb_packed) == 1, "");
_Static_assert(sizeof(struct EmptyIntMemb_required_alignment) == 1, "");
_Static_assert(_Alignof(struct EmptyIntMemb_required_alignment) == 1, "");
_Static_assert(sizeof(struct EmptyIntMemb_size) == 2, "");
_Static_assert(_Alignof(struct EmptyIntMemb_size) == 1, "");
#endif
_Static_assert(sizeof(EmptyLongLongMemb) == 0, "");
_Static_assert(_Alignof(EmptyLongLongMemb) == 2, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyLongLongMemb_alignment) == 2, "");
_Static_assert(_Alignof(struct EmptyLongLongMemb_alignment) == 2, "");
_Static_assert(sizeof(struct EmptyLongLongMemb_packed) == 0, "");
_Static_assert(_Alignof(struct EmptyLongLongMemb_packed) == 1, "");
_Static_assert(sizeof(struct EmptyLongLongMemb_required_alignment) == 1, "");
_Static_assert(_Alignof(struct EmptyLongLongMemb_required_alignment) == 1, "");
_Static_assert(sizeof(struct EmptyLongLongMemb_size) == 2, "");
_Static_assert(_Alignof(struct EmptyLongLongMemb_size) == 1, "");
#endif
_Static_assert(sizeof(EmptyAligned2LongLongMemb) == 0, "");
_Static_assert(_Alignof(EmptyAligned2LongLongMemb) == 2, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyAligned2LongLongMemb_alignment) == 2, "");
_Static_assert(_Alignof(struct EmptyAligned2LongLongMemb_alignment) == 2, "");
_Static_assert(sizeof(struct EmptyAligned2LongLongMemb_packed) == 0, "");
_Static_assert(_Alignof(struct EmptyAligned2LongLongMemb_packed) == 1, "");
_Static_assert(sizeof(struct EmptyAligned2LongLongMemb_required_alignment) == 1, "");
_Static_assert(_Alignof(struct EmptyAligned2LongLongMemb_required_alignment) == 1, "");
_Static_assert(sizeof(struct EmptyAligned2LongLongMemb_size) == 2, "");
_Static_assert(_Alignof(struct EmptyAligned2LongLongMemb_size) == 1, "");
#endif
_Static_assert(sizeof(EmptyAligned8LongLongMemb) == 0, "");
_Static_assert(_Alignof(EmptyAligned8LongLongMemb) == 8, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyAligned8LongLongMemb_alignment) == 8, "");
_Static_assert(_Alignof(struct EmptyAligned8LongLongMemb_alignment) == 8, "");
_Static_assert(sizeof(struct EmptyAligned8LongLongMemb_packed) == 0, "");
_Static_assert(_Alignof(struct EmptyAligned8LongLongMemb_packed) == 1, "");
_Static_assert(sizeof(struct EmptyAligned8LongLongMemb_required_alignment) == 1, "");
_Static_assert(_Alignof(struct EmptyAligned8LongLongMemb_required_alignment) == 1, "");
_Static_assert(sizeof(struct EmptyAligned8LongLongMemb_size) == 2, "");
_Static_assert(_Alignof(struct EmptyAligned8LongLongMemb_size) == 1, "");
#endif
_Static_assert(sizeof(EmptyPackedAligned4LongLongMemb) == 0, "");
_Static_assert(_Alignof(EmptyPackedAligned4LongLongMemb) == 4, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyPackedAligned4LongLongMemb_alignment) == 4, "");
_Static_assert(_Alignof(struct EmptyPackedAligned4LongLongMemb_alignment) == 4, "");
_Static_assert(sizeof(struct EmptyPackedAligned4LongLongMemb_packed) == 0, "");
_Static_assert(_Alignof(struct EmptyPackedAligned4LongLongMemb_packed) == 1, "");
_Static_assert(sizeof(struct EmptyPackedAligned4LongLongMemb_required_alignment) == 1, "");
_Static_assert(_Alignof(struct EmptyPackedAligned4LongLongMemb_required_alignment) == 1, "");
_Static_assert(sizeof(struct EmptyPackedAligned4LongLongMemb_size) == 2, "");
_Static_assert(_Alignof(struct EmptyPackedAligned4LongLongMemb_size) == 1, "");
#endif
_Static_assert(sizeof(EmptyPackedAligned8LongLongMemb) == 0, "");
_Static_assert(_Alignof(EmptyPackedAligned8LongLongMemb) == 1, "");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct EmptyPackedAligned8LongLongMemb_alignment) == 1, "");
_Static_assert(_Alignof(struct EmptyPackedAligned8LongLongMemb_alignment) == 1, "");
_Static_assert(sizeof(struct EmptyPackedAligned8LongLongMemb_packed) == 0, "");
_Static_assert(_Alignof(struct EmptyPackedAligned8LongLongMemb_packed) == 1, "");
_Static_assert(sizeof(struct EmptyPackedAligned8LongLongMemb_required_alignment) == 1, "");
_Static_assert(_Alignof(struct EmptyPackedAligned8LongLongMemb_required_alignment) == 1, "");
_Static_assert(sizeof(struct EmptyPackedAligned8LongLongMemb_size) == 2, "");
_Static_assert(_Alignof(struct EmptyPackedAligned8LongLongMemb_size) == 1, "");
#endif
#endif
