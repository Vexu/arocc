//aro-args -std=c2x

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

_Static_assert(__builtin_types_compatible_p(int, int));
_Static_assert(__builtin_types_compatible_p(const int, int));
_Static_assert(__builtin_types_compatible_p(intptr, int *));

_Static_assert(!__builtin_types_compatible_p(const int*, int *));
_Static_assert(!__builtin_types_compatible_p(enum A, enum B));
