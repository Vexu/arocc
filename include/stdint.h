/* <stdint.h> for the Aro C compiler */

#pragma once


#if __STDC_HOSTED__ && __has_include_next(<stdint.h>)

# include_next <stdint.h>

#else

#define __stdint_int_c_cat(X, Y) X ## Y
#define __stdint_int_c(V, SUFFIX) __stdint_int_c_cat(V, SUFFIX)
#define __stdint_uint_c(V, SUFFIX) __stdint_int_c_cat(V##U, SUFFIX)

#define INTPTR_MIN   (-__INTPTR_MAX__-1)
#define INTPTR_MAX   __INTPTR_MAX__
#define UINTPTR_MAX  __UINTPTR_MAX__
#define PTRDIFF_MIN  (-__PTRDIFF_MAX__-1)
#define PTRDIFF_MAX  __PTRDIFF_MAX__
#define SIZE_MAX     __SIZE_MAX__
#define INTMAX_MIN   (-__INTMAX_MAX__-1)
#define INTMAX_MAX   __INTMAX_MAX__
#define UINTMAX_MAX  __UINTMAX_MAX__
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 202311L
# define INTPTR_WIDTH  __INTPTR_WIDTH__
# define UINTPTR_WIDTH __UINTPTR_WIDTH__
# define INTMAX_WIDTH __INTMAX_WIDTH__
# define UINTMAX_WIDTH __UINTMAX_WIDTH__
# define PTRDIFF_WIDTH    __PTRDIFF_WIDTH__
# define SIZE_WIDTH       __SIZE_WIDTH__
# define WCHAR_WIDTH      __WCHAR_WIDTH__
#endif

typedef __INTMAX_TYPE__  intmax_t;
typedef __UINTMAX_TYPE__ uintmax_t;

#ifndef _INTPTR_T
# ifndef __intptr_t_defined
   typedef __INTPTR_TYPE__ intptr_t;
#  define __intptr_t_defined
#  define _INTPTR_T
# endif
#endif

#ifndef _UINTPTR_T
  typedef __UINTPTR_TYPE__ uintptr_t;
# define _UINTPTR_T
#endif


#ifdef __INT64_TYPE__
# ifndef __int8_t_defined /* glibc sys/types.h also defines int64_t*/
   typedef __INT64_TYPE__ int64_t;
# endif /* __int8_t_defined */
  typedef __UINT64_TYPE__ uint64_t;

# undef __int64_c_suffix
# undef __int32_c_suffix
# undef __int16_c_suffix
# undef  __int8_c_suffix
# ifdef __INT64_C_SUFFIX__
#  define __int64_c_suffix __INT64_C_SUFFIX__
#  define __int32_c_suffix __INT64_C_SUFFIX__
#  define __int16_c_suffix __INT64_C_SUFFIX__
#  define  __int8_c_suffix __INT64_C_SUFFIX__
# endif /* __INT64_C_SUFFIX__ */

# ifdef __int64_c_suffix
#  define INT64_C(v) (__stdint_int_c(v, __int64_c_suffix))
#  define UINT64_C(v) (__stdint_uint_c(v, __int64_c_suffix))
# else
#  define INT64_C(v) (v)
#  define UINT64_C(v) (v ## U)
# endif /* __int64_c_suffix */

# define INT64_MAX           INT64_C( 9223372036854775807)
# define INT64_MIN         (-INT64_C( 9223372036854775807)-1)
# define UINT64_MAX         UINT64_C(18446744073709551615)
# if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 202311L
#  define UINT64_WIDTH         64
#  define INT64_WIDTH          UINT64_WIDTH
# endif /* __STDC_VERSION__ */

#endif /* __INT64_TYPE__ */


#endif /* __STDC_HOSTED__ && __has_include_next(<stdint.h>) */
