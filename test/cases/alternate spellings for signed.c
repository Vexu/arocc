_Static_assert(__builtin_types_compatible_p(signed, __signed), "");
_Static_assert(__builtin_types_compatible_p(signed, __signed__), "");
_Static_assert(__builtin_types_compatible_p(signed char, __signed char), "");
_Static_assert(__builtin_types_compatible_p(signed short, short __signed__), "");

_Static_assert(!__builtin_types_compatible_p(unsigned, __signed), "");
_Static_assert(!__builtin_types_compatible_p(unsigned, __signed__), "");
_Static_assert(!__builtin_types_compatible_p(unsigned char, char __signed), "");
_Static_assert(!__builtin_types_compatible_p(unsigned char, __signed__ char), "");
