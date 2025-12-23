#pragma once

#if defined(__has_feature) && __has_feature(bounds_attributes)
  #define __has_ptrcheck 1
#else
  #define __has_ptrcheck 0
#endif

#if __has_ptrcheck

#define __single __attribute__((__single__))
#define __unsafe_indexable __attribute__((__unsafe_indexable__))

#else

#define __single
#define __unsafe_indexable
#define __counted_by(N)
#define __counted_by_or_null(N)
#define __sized_by(N)
#define __sized_by_or_null(N)
#define __ended_by(E)

#define __terminated_by(T)
#define __null_terminated

/* __ptrcheck_abi_assume_indexable and __ptrcheck_abi_assume_bidi_indexable intentionally not defined */
#define __ptrcheck_abi_assume_single()
#define __ptrcheck_abi_assume_unsafe_indexable()

#define __unsafe_forge_bidi_indexable(T, P, S) ((T)(P))
#define __unsafe_forge_single(T, P) ((T)(P))
#define __unsafe_forge_terminated_by(T, P, E) ((T)(P))
#define __unsafe_forge_null_terminated(T, P) ((T)(P))

#define __terminated_by_to_indexable(P) (P)
#define __unsafe_terminated_by_to_indexable(P) (P)
#define __null_terminated_to_indexable(P) (P)
#define __unsafe_null_terminated_to_indexable(P) (P)
#define __unsafe_terminated_by_from_indexable(T, P, ...) (P)
#define __unsafe_null_terminated_from_indexable(P, ...) (P)

#define __array_decay_dicards_count_in_parameters

#define __ptrcheck_unavailable
#define __ptrcheck_unavailable_r(REPLACEMENT)


#endif
