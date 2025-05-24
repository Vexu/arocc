//aro-args --target=avr-freestanding-none

_Static_assert(sizeof(int) == 2, "wrong sizeof int");
_Static_assert(sizeof(unsigned) == 2, "wrong sizeof unsigned");
_Static_assert(sizeof(signed) == 2, "wrong sizeof signed");
_Static_assert(sizeof(short) == 2, "wrong sizeof short");
_Static_assert(sizeof(unsigned short) == 2, "wrong sizeof unsigned short");
_Static_assert(sizeof(signed short) == 2, "wrong sizeof signed short");
_Static_assert(sizeof(long) == 4, "wrong sizeof long");
_Static_assert(sizeof(unsigned long) == 4, "wrong sizeof unsigned long");
_Static_assert(sizeof(signed long) == 4, "wrong sizeof signed long");
_Static_assert(sizeof(long double) == 4, "wrong sizeof long double");
_Static_assert(sizeof(long long) == 8, "wrong sizeof long long");
_Static_assert(sizeof(unsigned long long) == 8, "wrong sizeof unsigned long long");
_Static_assert(sizeof(signed long long) == 8, "wrong sizeof signed long long");
