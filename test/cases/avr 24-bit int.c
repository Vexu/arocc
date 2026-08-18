_Static_assert(sizeof(__int24) == 3, "");
_Static_assert(sizeof(__uint24) == 3, "");
_Static_assert(_Generic((__int24)0 + 0, __int24: 1, default: 0), "");
_Static_assert(_Generic((__uint24)0 + 0, __uint24: 1, default: 0), "");
_Static_assert(_Generic((signed __int24)0, __int24: 1, default: 0), "");
_Static_assert(_Generic((unsigned __int24)0, __uint24: 1, default: 0), "");

_Static_assert(__INT24_MAX__ == 8388607L, "");
_Static_assert(__INT24_MIN__ == -8388608L, "");
_Static_assert(__UINT24_MAX__ == 16777215UL, "");

typedef enum {
    F121 = 8388608,
} __attribute__((packed)) A028;
_Static_assert(sizeof(A028) == 3, "");

_Static_assert(sizeof(_Complex __int24) == 6, "");

/** manifest:
syntax
args = --target=avr-freestanding-none
*/
