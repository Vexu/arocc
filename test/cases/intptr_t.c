//aro-args --target=x86_64-linux-gnu

_Static_assert(__INTPTR_MAX__ == 9223372036854775807L, "");
_Static_assert(__INTPTR_WIDTH__ == 64, "");
_Static_assert(__builtin_types_compatible_p(__INTPTR_TYPE__, long), "");

_Static_assert(__UINTPTR_MAX__ == 18446744073709551615UL, "");
_Static_assert(__UINTPTR_WIDTH__ == 64, "");
_Static_assert(__builtin_types_compatible_p(__UINTPTR_TYPE__, unsigned long), "");
