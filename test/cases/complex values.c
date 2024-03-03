//aro-args -std=c23
_Static_assert(1.0 + 2.0i == 2.0i + 1.0, "");
_Static_assert(2.0i * 2.0i == -4.0, "");
_Static_assert((double)2.0i == 0, "");
_Static_assert((double)(_Complex double)42 == 42, "");
_Static_assert(-2.0i - 2.0i == -4.0i, "");
_Static_assert(~(2.0 + 4.0i) == 2.0 - 4.0i, "");
_Static_assert((2.0 + 2.0i) / 2.0 == 1.0 + 1.0i, "");
_Static_assert((2.0 + 4.0i) / 1.0i == 4.0 - 2.0i, "");

_Static_assert(__builtin_inf() == __builtin_inf(), "");
_Static_assert(100.0 < __builtin_inf(), "");
_Static_assert(__builtin_inf() > 0.0, "");

_Static_assert(__builtin_isinf(__builtin_inff()), "");
_Static_assert(__builtin_isinf(__builtin_inf()), "");
_Static_assert(__builtin_isinf(__builtin_infl()), "");
_Static_assert(__builtin_isinf(1.0 / 0.0), "");
_Static_assert(!__builtin_isinf(2.0 + 3.0), "");


void foo(void) {
	double x = __builtin_inf();
	_Static_assert(!__builtin_isinf(x), "");
}

_Static_assert(__builtin_isnan(__real(0.0/0.0)), "");
_Static_assert(__builtin_isinf(__real((2.0 + 2.0i)/0.0)), "");
_Static_assert(__builtin_isinf(__imag((2.0 + 2.0i)/0.0)), "");


#define EXPECTED_ERRORS "complex values.c:24:17: error: static_assert expression is not an integral constant expression" \

