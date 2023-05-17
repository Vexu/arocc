//aro-args --target=x86_64-linux-gnu

_Static_assert(__INTMAX_MAX__ == 9223372036854775807L, "");
_Static_assert(__INTMAX_WIDTH__ == 64, "");
_Static_assert(__builtin_types_compatible_p(__INTMAX_TYPE__, long), "");

_Static_assert(__UINTMAX_MAX__ == 18446744073709551615UL, "");
_Static_assert(__UINTMAX_WIDTH__ == 64, "");
_Static_assert(__builtin_types_compatible_p(__UINTMAX_TYPE__, unsigned long), "");
