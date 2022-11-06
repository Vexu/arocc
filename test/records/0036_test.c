// SPDX-License-Identifier: GPL-3.0-or-later

// This test file is auto-generated. do not edit.
// This file is a derivative work from the test files found
// in this repo : https://github.com/mahkoh/repr-c
// and is under the same licence as the original work.

#ifdef MSVC
typedef struct {
    _Bool v:8;
} S;
S var1;
struct S_extra_alignment {
    char a[_Alignof(S)];
    char b;
};
struct S_extra_alignment var2;
#pragma pack(1)
struct S_extra_packed {
    S a;
};
#pragma pack()
struct S_extra_required_alignment {
    char a[_Alignof(struct S_extra_packed)];
    char b;
};
struct S_extra_required_alignment var3;
struct S_extra_size {
    char a[sizeof(S)+1];
    char b;
};
struct S_extra_size var4;


#endif

// MAPPING|ONE|aarch64-generic-windows-msvc:Msvc|x86-i586-windows-msvc:Msvc|x86-i686-windows-msvc:Msvc|x86-i686-uefi-msvc:Msvc|thumb-baseline-windows-msvc:Msvc|x86_64-x86_64-windows-msvc:Msvc|x86_64-x86_64-uefi-msvc:Msvc|END
// repr targets Aarch64PcWindowsMsvc|Some("aarch64-generic-windows-msvc") I586PcWindowsMsvc|Some("x86-i586-windows-msvc") I686PcWindowsMsvc|Some("x86-i686-windows-msvc") I686UnknownWindows|Some("x86-i686-uefi-msvc") Thumbv7aPcWindowsMsvc|Some("thumb-baseline-windows-msvc") X86_64PcWindowsMsvc|Some("x86_64-x86_64-windows-msvc") X86_64UnknownWindows|Some("x86_64-x86_64-uefi-msvc") 
#ifdef ONE
_Static_assert(sizeof(S) == 1, "");
_Static_assert(_Alignof(S) == 1, "");
_Static_assert(sizeof(struct S_extra_alignment) == 2, "");
_Static_assert(_Alignof(struct S_extra_alignment) == 1, "");
_Static_assert(sizeof(struct S_extra_packed) == 1, "");
_Static_assert(_Alignof(struct S_extra_packed) == 1, "");
_Static_assert(sizeof(struct S_extra_required_alignment) == 2, "");
_Static_assert(_Alignof(struct S_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct S_extra_size) == 3, "");
_Static_assert(_Alignof(struct S_extra_size) == 1, "");
#endif
