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

// MAPPING|ONE|aarch64-generic-macos-none:Clang|aarch64-generic-fuchsia-gnu:Clang|aarch64-generic-linux-android:Clang|aarch64-generic-freebsd-gnu:Clang|aarch64-generic-hermit-eabi:Clang|aarch64-generic-netbsd-gnu:Clang|aarch64-generic-other-none:Clang|aarch64-generic-openbsd-gnu:Clang|aarch64-generic-ios-none:Clang|aarch64-generic-ios-macabi:Clang|aarch64-generic-tvos-none:Clang|arm-baseline-other-eabi:Clang|arm-baseline-other-eabihf:Clang|arm-arm1136j_s-freebsd-gnu:Clang|arm-arm1136j_s-netbsd-eabihf:Clang|arm-baseline-other-eabi:Clang|arm-baseline-other-eabihf:Clang|arm-cortex_r4-ios-none:Clang|arm-cortex_r4-other-eabi:Clang|arm-cortex_r4-other-eabihf:Clang|arm-baseline-ios-none:Clang|arm-cortex_r4-freebsd-gnu:Clang|arm-cortex_r4-netbsd-eabihf:Clang|hexagon-generic-linux-musl:Clang|i386-i386-ios-none:Clang|x86_64-i686-macos-none:Clang|i386-i686-linux-android:Clang|i386-i686-freebsd-gnu:Clang|i386-i686-haiku-gnu:Clang|i386-i686-netbsd-gnu:Clang|i386-i686-openbsd-gnu:Clang|mipsel-mips32-other-none:Clang|powerpc64-ppc64-freebsd-gnu:Clang|powerpc-ppc-netbsd-gnu:Clang|riscv32-generic_rv32-other-none:Clang|riscv64-generic_rv64-other-none:Clang|sparc64-v9-netbsd-gnu:Clang|sparc64-v9-openbsd-gnu:Clang|sparc-v9-solaris-eabi:Clang|thumb-arm710t-other-eabi:Clang|thumb-cortex_m0-other-eabi:Clang|thumb-cortex_m4-other-eabihf:Clang|thumb-cortex_m4-other-eabi:Clang|thumb-cortex_m3-other-eabi:Clang|thumb-baseline-other-eabi:Clang|thumb-cortex_m33-other-eabihf:Clang|thumb-cortex_m33-other-eabi:Clang|wasm32-generic-emscripten-musl:Clang|wasm32-generic-other-none:Clang|wasm32-generic-wasi-musl:Clang|x86_64-x86_64-ios-macabi:Clang|x86_64-x86_64-ios-none:Clang|x86_64-x86_64-macos-none:Clang|x86_64-x86_64-tvos-none:Clang|x86_64-x86_64-fuchsia-gnu:Clang|x86_64-x86_64-linux-android:Clang|x86_64-x86_64-solaris-eabi:Clang|x86_64-x86_64-dragonfly-eabi:Clang|x86_64-x86_64-freebsd-gnu:Clang|x86_64-x86_64-haiku-gnu:Clang|x86_64-x86_64-hermit-eabi:Clang|x86_64-x86_64-netbsd-gnu:Clang|x86_64-x86_64-openbsd-gnu:Clang|END
// repr targets Aarch64AppleMacosx|Some("aarch64-generic-macos-none") Aarch64Fuchsia|Some("aarch64-generic-fuchsia-gnu") Aarch64LinuxAndroid|Some("aarch64-generic-linux-android") Aarch64UnknownFreebsd|Some("aarch64-generic-freebsd-gnu") Aarch64UnknownHermit|Some("aarch64-generic-hermit-eabi") Aarch64UnknownNetbsd|Some("aarch64-generic-netbsd-gnu") Aarch64UnknownNone|Some("aarch64-generic-other-none") Aarch64UnknownOpenbsd|Some("aarch64-generic-openbsd-gnu") Aarch64UnknownRedox|None Arm64AppleIos|Some("aarch64-generic-ios-none") Arm64AppleIosMacabi|Some("aarch64-generic-ios-macabi") Arm64AppleTvos|Some("aarch64-generic-tvos-none") Armebv7rUnknownNoneEabi|Some("arm-baseline-other-eabi") Armebv7rUnknownNoneEabihf|Some("arm-baseline-other-eabihf") ArmLinuxAndroideabi|None Armv6UnknownFreebsdGnueabihf|Some("arm-arm1136j_s-freebsd-gnu") Armv6UnknownNetbsdelfEabihf|Some("arm-arm1136j_s-netbsd-eabihf") Armv7aNoneEabi|Some("arm-baseline-other-eabi") Armv7aNoneEabihf|Some("arm-baseline-other-eabihf") Armv7AppleIos|Some("arm-cortex_r4-ios-none") Armv7NoneLinuxAndroid|None Armv7rUnknownNoneEabi|Some("arm-cortex_r4-other-eabi") Armv7rUnknownNoneEabihf|Some("arm-cortex_r4-other-eabihf") Armv7sAppleIos|Some("arm-baseline-ios-none") Armv7UnknownFreebsdGnueabihf|Some("arm-cortex_r4-freebsd-gnu") Armv7UnknownNetbsdelfEabihf|Some("arm-cortex_r4-netbsd-eabihf") HexagonUnknownLinuxMusl|Some("hexagon-generic-linux-musl") I386AppleIos|Some("i386-i386-ios-none") I686AppleMacosx|Some("x86_64-i686-macos-none") I686LinuxAndroid|Some("i386-i686-linux-android") I686UnknownFreebsd|Some("i386-i686-freebsd-gnu") I686UnknownHaiku|Some("i386-i686-haiku-gnu") I686UnknownNetbsdelf|Some("i386-i686-netbsd-gnu") I686UnknownOpenbsd|Some("i386-i686-openbsd-gnu") MipselSonyPsp|None MipselUnknownNone|Some("mipsel-mips32-other-none") Powerpc64UnknownFreebsd|Some("powerpc64-ppc64-freebsd-gnu") PowerpcUnknownLinuxGnuspe|None PowerpcUnknownNetbsd|Some("powerpc-ppc-netbsd-gnu") Riscv32|Some("riscv32-generic_rv32-other-none") Riscv64|Some("riscv64-generic_rv64-other-none") Sparc64UnknownNetbsd|Some("sparc64-v9-netbsd-gnu") Sparc64UnknownOpenbsd|Some("sparc64-v9-openbsd-gnu") Sparcv9SunSolaris|Some("sparc-v9-solaris-eabi") Thumbv4tNoneEabi|Some("thumb-arm710t-other-eabi") Thumbv6mNoneEabi|Some("thumb-cortex_m0-other-eabi") Thumbv7emNoneEabihf|Some("thumb-cortex_m4-other-eabihf") Thumbv7emNoneEabi|Some("thumb-cortex_m4-other-eabi") Thumbv7mNoneEabi|Some("thumb-cortex_m3-other-eabi") Thumbv8mBaseNoneEabi|Some("thumb-baseline-other-eabi") Thumbv8mMainNoneEabihf|Some("thumb-cortex_m33-other-eabihf") Thumbv8mMainNoneEabi|Some("thumb-cortex_m33-other-eabi") Wasm32UnknownEmscripten|Some("wasm32-generic-emscripten-musl") Wasm32UnknownUnknown|Some("wasm32-generic-other-none") Wasm32Wasi|Some("wasm32-generic-wasi-musl") X86_64AppleIosMacabi|Some("x86_64-x86_64-ios-macabi") X86_64AppleIos|Some("x86_64-x86_64-ios-none") X86_64AppleMacosx|Some("x86_64-x86_64-macos-none") X86_64AppleTvos|Some("x86_64-x86_64-tvos-none") X86_64Elf|None X86_64Fuchsia|Some("x86_64-x86_64-fuchsia-gnu") X86_64LinuxAndroid|Some("x86_64-x86_64-linux-android") X86_64PcSolaris|Some("x86_64-x86_64-solaris-eabi") X86_64RumprunNetbsd|None X86_64UnknownDragonfly|Some("x86_64-x86_64-dragonfly-eabi") X86_64UnknownFreebsd|Some("x86_64-x86_64-freebsd-gnu") X86_64UnknownHaiku|Some("x86_64-x86_64-haiku-gnu") X86_64UnknownHermit|Some("x86_64-x86_64-hermit-eabi") X86_64UnknownL4reUclibc|None X86_64UnknownNetbsd|Some("x86_64-x86_64-netbsd-gnu") X86_64UnknownOpenbsd|Some("x86_64-x86_64-openbsd-gnu") X86_64UnknownRedox|None 
#ifdef ONE
_Static_assert(sizeof(AlignedStruct) == 16, "record AlignedStruct wrong sizeof");
_Static_assert(_Alignof(AlignedStruct) == 16, "record AlignedStruct wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct AlignedStruct_alignment) == 32, "record AlignedStruct wrong sizeof");
_Static_assert(_Alignof(struct AlignedStruct_alignment) == 16, "record AlignedStruct wrong alignment");
_Static_assert(sizeof(struct AlignedStruct_packed) == 16, "record AlignedStruct wrong sizeof");
_Static_assert(_Alignof(struct AlignedStruct_packed) == 1, "record AlignedStruct wrong alignment");
_Static_assert(sizeof(struct AlignedStruct_required_alignment) == 17, "record AlignedStruct wrong sizeof");
_Static_assert(_Alignof(struct AlignedStruct_required_alignment) == 1, "record AlignedStruct wrong alignment");
_Static_assert(sizeof(struct AlignedStruct_size) == 18, "record AlignedStruct wrong sizeof");
_Static_assert(_Alignof(struct AlignedStruct_size) == 1, "record AlignedStruct wrong alignment");
#endif
_Static_assert(sizeof(AlignedInt) == 4, "record AlignedInt wrong sizeof");
_Static_assert(_Alignof(AlignedInt) == 16, "record AlignedInt wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct AlignedInt_alignment) == 32, "record AlignedInt wrong sizeof");
_Static_assert(_Alignof(struct AlignedInt_alignment) == 16, "record AlignedInt wrong alignment");
_Static_assert(sizeof(struct AlignedInt_packed) == 4, "record AlignedInt wrong sizeof");
_Static_assert(_Alignof(struct AlignedInt_packed) == 1, "record AlignedInt wrong alignment");
_Static_assert(sizeof(struct AlignedInt_required_alignment) == 5, "record AlignedInt wrong sizeof");
_Static_assert(_Alignof(struct AlignedInt_required_alignment) == 1, "record AlignedInt wrong alignment");
_Static_assert(sizeof(struct AlignedInt_size) == 6, "record AlignedInt wrong sizeof");
_Static_assert(_Alignof(struct AlignedInt_size) == 1, "record AlignedInt wrong alignment");
#endif
_Static_assert(sizeof(A) == 16, "record A wrong sizeof");
_Static_assert(_Alignof(A) == 2, "record A wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 18, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_alignment) == 2, "record A wrong alignment");
_Static_assert(sizeof(struct A_packed) == 16, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_packed) == 1, "record A wrong alignment");
_Static_assert(sizeof(struct A_required_alignment) == 17, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "record A wrong alignment");
_Static_assert(sizeof(struct A_size) == 18, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_size) == 1, "record A wrong alignment");
#endif
_Static_assert(sizeof(B) == 18, "record B wrong sizeof");
_Static_assert(_Alignof(B) == 2, "record B wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 20, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_alignment) == 2, "record B wrong alignment");
_Static_assert(sizeof(struct B_packed) == 18, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_packed) == 1, "record B wrong alignment");
_Static_assert(sizeof(struct B_required_alignment) == 19, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "record B wrong alignment");
_Static_assert(sizeof(struct B_size) == 20, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_size) == 1, "record B wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B,a) == 16, "field B.a wrong bit offset");
#endif
_Static_assert(sizeof(C) == 2, "record C wrong sizeof");
_Static_assert(_Alignof(C) == 2, "record C wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 4, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_alignment) == 2, "record C wrong alignment");
_Static_assert(sizeof(struct C_packed) == 2, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_packed) == 1, "record C wrong alignment");
_Static_assert(sizeof(struct C_required_alignment) == 3, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "record C wrong alignment");
_Static_assert(sizeof(struct C_size) == 4, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_size) == 1, "record C wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C,a) == 16, "field C.a wrong bit offset");
#endif
// MAPPING|TWO|aarch64-generic-windows-msvc:Msvc|i386-i586-windows-msvc:Msvc|i386-i686-windows-msvc:Msvc|i386-i686-uefi-msvc:Msvc|thumb-baseline-windows-msvc:Msvc|x86_64-x86_64-windows-msvc:Msvc|x86_64-x86_64-uefi-msvc:Msvc|END
// repr targets Aarch64PcWindowsMsvc|Some("aarch64-generic-windows-msvc") I586PcWindowsMsvc|Some("i386-i586-windows-msvc") I686PcWindowsMsvc|Some("i386-i686-windows-msvc") I686UnknownWindows|Some("i386-i686-uefi-msvc") Thumbv7aPcWindowsMsvc|Some("thumb-baseline-windows-msvc") X86_64PcWindowsMsvc|Some("x86_64-x86_64-windows-msvc") X86_64UnknownWindows|Some("x86_64-x86_64-uefi-msvc") 
#elif defined(TWO)
_Static_assert(sizeof(AlignedStruct) == 16, "record AlignedStruct wrong sizeof");
_Static_assert(_Alignof(AlignedStruct) == 16, "record AlignedStruct wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct AlignedStruct_alignment) == 32, "record AlignedStruct wrong sizeof");
_Static_assert(_Alignof(struct AlignedStruct_alignment) == 16, "record AlignedStruct wrong alignment");
_Static_assert(sizeof(struct AlignedStruct_packed) == 16, "record AlignedStruct wrong sizeof");
_Static_assert(_Alignof(struct AlignedStruct_packed) == 1, "record AlignedStruct wrong alignment");
_Static_assert(sizeof(struct AlignedStruct_required_alignment) == 17, "record AlignedStruct wrong sizeof");
_Static_assert(_Alignof(struct AlignedStruct_required_alignment) == 1, "record AlignedStruct wrong alignment");
_Static_assert(sizeof(struct AlignedStruct_size) == 18, "record AlignedStruct wrong sizeof");
_Static_assert(_Alignof(struct AlignedStruct_size) == 1, "record AlignedStruct wrong alignment");
#endif
_Static_assert(sizeof(AlignedInt) == 4, "record AlignedInt wrong sizeof");
_Static_assert(_Alignof(AlignedInt) == 16, "record AlignedInt wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct AlignedInt_alignment) == 32, "record AlignedInt wrong sizeof");
_Static_assert(_Alignof(struct AlignedInt_alignment) == 16, "record AlignedInt wrong alignment");
_Static_assert(sizeof(struct AlignedInt_packed) == 4, "record AlignedInt wrong sizeof");
_Static_assert(_Alignof(struct AlignedInt_packed) == 1, "record AlignedInt wrong alignment");
_Static_assert(sizeof(struct AlignedInt_required_alignment) == 5, "record AlignedInt wrong sizeof");
_Static_assert(_Alignof(struct AlignedInt_required_alignment) == 1, "record AlignedInt wrong alignment");
_Static_assert(sizeof(struct AlignedInt_size) == 6, "record AlignedInt wrong sizeof");
_Static_assert(_Alignof(struct AlignedInt_size) == 1, "record AlignedInt wrong alignment");
#endif
_Static_assert(sizeof(A) == 16, "record A wrong sizeof");
_Static_assert(_Alignof(A) == 16, "record A wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 32, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_alignment) == 16, "record A wrong alignment");
_Static_assert(sizeof(struct A_packed) == 16, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_packed) == 1, "record A wrong alignment");
_Static_assert(sizeof(struct A_required_alignment) == 17, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "record A wrong alignment");
_Static_assert(sizeof(struct A_size) == 18, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_size) == 1, "record A wrong alignment");
#endif
_Static_assert(sizeof(B) == 32, "record B wrong sizeof");
_Static_assert(_Alignof(B) == 16, "record B wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 48, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_alignment) == 16, "record B wrong alignment");
_Static_assert(sizeof(struct B_packed) == 32, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_packed) == 1, "record B wrong alignment");
_Static_assert(sizeof(struct B_required_alignment) == 33, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "record B wrong alignment");
_Static_assert(sizeof(struct B_size) == 34, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_size) == 1, "record B wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B,a) == 128, "field B.a wrong bit offset");
#endif
_Static_assert(sizeof(C) == 16, "record C wrong sizeof");
_Static_assert(_Alignof(C) == 16, "record C wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 32, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_alignment) == 16, "record C wrong alignment");
_Static_assert(sizeof(struct C_packed) == 16, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_packed) == 1, "record C wrong alignment");
_Static_assert(sizeof(struct C_required_alignment) == 17, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "record C wrong alignment");
_Static_assert(sizeof(struct C_size) == 18, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_size) == 1, "record C wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C,a) == 128, "field C.a wrong bit offset");
#endif
// MAPPING|THREE|msp430-msp430-other-none:Clang|END
// repr targets Msp430NoneElf|Some("msp430-msp430-other-none") 
#elif defined(THREE)
_Static_assert(sizeof(AlignedStruct) == 16, "record AlignedStruct wrong sizeof");
_Static_assert(_Alignof(AlignedStruct) == 16, "record AlignedStruct wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct AlignedStruct_alignment) == 32, "record AlignedStruct wrong sizeof");
_Static_assert(_Alignof(struct AlignedStruct_alignment) == 16, "record AlignedStruct wrong alignment");
_Static_assert(sizeof(struct AlignedStruct_packed) == 16, "record AlignedStruct wrong sizeof");
_Static_assert(_Alignof(struct AlignedStruct_packed) == 1, "record AlignedStruct wrong alignment");
_Static_assert(sizeof(struct AlignedStruct_required_alignment) == 17, "record AlignedStruct wrong sizeof");
_Static_assert(_Alignof(struct AlignedStruct_required_alignment) == 1, "record AlignedStruct wrong alignment");
_Static_assert(sizeof(struct AlignedStruct_size) == 18, "record AlignedStruct wrong sizeof");
_Static_assert(_Alignof(struct AlignedStruct_size) == 1, "record AlignedStruct wrong alignment");
#endif
_Static_assert(sizeof(AlignedInt) == 2, "record AlignedInt wrong sizeof");
_Static_assert(_Alignof(AlignedInt) == 16, "record AlignedInt wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct AlignedInt_alignment) == 32, "record AlignedInt wrong sizeof");
_Static_assert(_Alignof(struct AlignedInt_alignment) == 16, "record AlignedInt wrong alignment");
_Static_assert(sizeof(struct AlignedInt_packed) == 2, "record AlignedInt wrong sizeof");
_Static_assert(_Alignof(struct AlignedInt_packed) == 1, "record AlignedInt wrong alignment");
_Static_assert(sizeof(struct AlignedInt_required_alignment) == 3, "record AlignedInt wrong sizeof");
_Static_assert(_Alignof(struct AlignedInt_required_alignment) == 1, "record AlignedInt wrong alignment");
_Static_assert(sizeof(struct AlignedInt_size) == 4, "record AlignedInt wrong sizeof");
_Static_assert(_Alignof(struct AlignedInt_size) == 1, "record AlignedInt wrong alignment");
#endif
_Static_assert(sizeof(A) == 16, "record A wrong sizeof");
_Static_assert(_Alignof(A) == 2, "record A wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct A_alignment) == 18, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_alignment) == 2, "record A wrong alignment");
_Static_assert(sizeof(struct A_packed) == 16, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_packed) == 1, "record A wrong alignment");
_Static_assert(sizeof(struct A_required_alignment) == 17, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_required_alignment) == 1, "record A wrong alignment");
_Static_assert(sizeof(struct A_size) == 18, "record A wrong sizeof");
_Static_assert(_Alignof(struct A_size) == 1, "record A wrong alignment");
#endif
_Static_assert(sizeof(B) == 18, "record B wrong sizeof");
_Static_assert(_Alignof(B) == 2, "record B wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct B_alignment) == 20, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_alignment) == 2, "record B wrong alignment");
_Static_assert(sizeof(struct B_packed) == 18, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_packed) == 1, "record B wrong alignment");
_Static_assert(sizeof(struct B_required_alignment) == 19, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_required_alignment) == 1, "record B wrong alignment");
_Static_assert(sizeof(struct B_size) == 20, "record B wrong sizeof");
_Static_assert(_Alignof(struct B_size) == 1, "record B wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(B,a) == 16, "field B.a wrong bit offset");
#endif
_Static_assert(sizeof(C) == 2, "record C wrong sizeof");
_Static_assert(_Alignof(C) == 2, "record C wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct C_alignment) == 4, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_alignment) == 2, "record C wrong alignment");
_Static_assert(sizeof(struct C_packed) == 2, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_packed) == 1, "record C wrong alignment");
_Static_assert(sizeof(struct C_required_alignment) == 3, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_required_alignment) == 1, "record C wrong alignment");
_Static_assert(sizeof(struct C_size) == 4, "record C wrong sizeof");
_Static_assert(_Alignof(struct C_size) == 1, "record C wrong alignment");
#endif
#ifdef CHECK_OFFSETS
_Static_assert(__builtin_bitoffsetof(C,a) == 16, "field C.a wrong bit offset");
#endif
#endif
