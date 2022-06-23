// SPDX-License-Identifier: GPL-3.0-or-later

// This test file is auto-generated. do not edit.
// This file is a derivative work from the test files found// in this repo : https://github.com/mahkoh/repr-c
// and is under the same licence as the original work.

#ifdef MSVC
typedef struct {
    _Bool v:8;
} S;
S var1;
struct S_alignment {
    char a[_Alignof(S)];
    char b;
};
struct S_alignment var2;
#pragma pack(1)
struct S_packed {
    S a;
};
#pragma pack()
struct S_required_alignment {
    char a[_Alignof(struct S_packed)];
    char b;
};
struct S_required_alignment var3;
struct S_size {
    char a[sizeof(S)+1];
    char b;
};
struct S_size var4;


#endif

#if defined(AARCH64_PC_WINDOWS_MSVC) ||  defined(I586_PC_WINDOWS_MSVC) ||  defined(I686_PC_WINDOWS_MSVC) ||  defined(I686_UNKNOWN_WINDOWS) ||  \
 defined(THUMBV7A_PC_WINDOWS_MSVC) ||  defined(X8664_PC_WINDOWS_MSVC) ||  defined(X8664_UNKNOWN_WINDOWS) 
_Static_assert(sizeof(S) == 1, "record S wrong sizeof");
_Static_assert(_Alignof(S) == 1, "record S wrong alignment");
#ifdef EXTRA_TESTS
_Static_assert(sizeof(struct S_alignment) == 2, "record S wrong sizeof");
_Static_assert(_Alignof(struct S_alignment) == 1, "record S wrong alignment");
_Static_assert(sizeof(struct S_packed) == 1, "record S wrong sizeof");
_Static_assert(_Alignof(struct S_packed) == 1, "record S wrong alignment");
_Static_assert(sizeof(struct S_required_alignment) == 2, "record S wrong sizeof");
_Static_assert(_Alignof(struct S_required_alignment) == 1, "record S wrong alignment");
_Static_assert(sizeof(struct S_size) == 3, "record S wrong sizeof");
_Static_assert(_Alignof(struct S_size) == 1, "record S wrong alignment");
#endif
#endif
