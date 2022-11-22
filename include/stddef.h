/* <stddef.h> for the Aro C compiler */

#pragma once

/* Todo: Set to 202311L once header is compliant with C23 */
#define __STDC_VERSION_STDDEF_H__ 0

typedef __PTRDIFF_TYPE__ ptrdiff_t;
typedef __SIZE_TYPE__ size_t;
typedef __WCHAR_TYPE__ wchar_t;

/* define max_align_t to match GCC and Clang */
typedef struct {
  long long __aro_max_align_ll;
  long double __aro_max_align_ld;
} max_align_t;

#define NULL ((void*)0)
#define offsetof(T, member) __builtin_offsetof(T, member)
