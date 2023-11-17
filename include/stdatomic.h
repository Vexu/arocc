/* <stdatomic.h> for the Aro C compiler */

#pragma once

/* Todo: Set to 202311L once header is compliant with C23 */
#define __STDC_VERSION_STDATOMIC_H__ 0
// TODO finish atomics support


#if __STDC_HOSTED__ && __has_include_next(<stdatomic.h>)
#include_next <stdatomic.h>
#else

#include <stddef.h>
#include <stdint.h>

typedef enum memory_order {
  memory_order_relaxed = __ATOMIC_RELAXED,
  memory_order_consume = __ATOMIC_CONSUME,
  memory_order_acquire = __ATOMIC_ACQUIRE,
  memory_order_release = __ATOMIC_RELEASE,
  memory_order_acq_rel = __ATOMIC_ACQ_REL,
  memory_order_seq_cst = __ATOMIC_SEQ_CST
} memory_order;

typedef _Atomic(_Bool)              atomic_bool;
typedef _Atomic(char)               atomic_char;
typedef _Atomic(signed char)        atomic_schar;
typedef _Atomic(unsigned char)      atomic_uchar;
typedef _Atomic(short)              atomic_short;
typedef _Atomic(unsigned short)     atomic_ushort;
typedef _Atomic(int)                atomic_int;
typedef _Atomic(unsigned int)       atomic_uint;
typedef _Atomic(long)               atomic_long;
typedef _Atomic(unsigned long)      atomic_ulong;
typedef _Atomic(long long)          atomic_llong;
typedef _Atomic(unsigned long long) atomic_ullong;
typedef _Atomic(wchar_t)            atomic_wchar_t;
typedef _Atomic(intptr_t)           atomic_intptr_t;
typedef _Atomic(uintptr_t)          atomic_uintptr_t;
typedef _Atomic(size_t)             atomic_size_t;
typedef _Atomic(ptrdiff_t)          atomic_ptrdiff_t;
typedef _Atomic(intmax_t)           atomic_intmax_t;
typedef _Atomic(uintmax_t)          atomic_uintmax_t;

typedef struct atomic_flag { atomic_bool _Value; } atomic_flag;

#define ATOMIC_FLAG_INIT { 0 }

#endif
