
#if !__has_builtin(__builtin_types_compatible_p)
#error Missing builtin __builtin_types_compatible_p
#endif

typedef int *intptr;

enum A {
	FOO,
};

enum B {
	BAR,
};

const int x;
_Static_assert(__builtin_types_compatible_p(int, int));
_Static_assert(__builtin_types_compatible_p(const int, int));
_Static_assert(__builtin_types_compatible_p(intptr, int *));
_Static_assert(__builtin_types_compatible_p(int[], const int[]));
_Static_assert(__builtin_types_compatible_p(__typeof__("Hello"), char[]));
_Static_assert(__builtin_types_compatible_p(__typeof__("Hello"), char[6]));
_Static_assert(__builtin_types_compatible_p(__typeof__(const int), int));
_Static_assert(__builtin_types_compatible_p(__typeof__(x), __typeof__(volatile int)));

_Static_assert(!__builtin_types_compatible_p(const int*, int *));
_Static_assert(!__builtin_types_compatible_p(enum A, enum B));
_Static_assert(!__builtin_types_compatible_p(__typeof__("Hello"), char *));

_Static_assert(__builtin_types_compatible_p(int, long));
_Static_assert(__builtin_types_compatible_p(__typeof__(const int) *, int *), "Types do not match");

/** manifest:
syntax
args = -std=c23

__builtin_types_compatible_p.c:30:1: error: static assertion failed '__builtin_types_compatible_p(int, long)'
__builtin_types_compatible_p.c:31:1: error: static assertion failed '__builtin_types_compatible_p(typeof(const int) *, int *)' "Types do not match"
*/
