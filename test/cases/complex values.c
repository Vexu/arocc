_Static_assert(1.0 + 2.0i == 2.0i + 1.0, "");
_Static_assert(2.0i * 2.0i == -4.0, "");
_Static_assert((double)2.0i == 0, "");
_Static_assert((double)(_Complex double)42 == 42, "");
_Static_assert(-2.0i - 2.0i == -4.0i, "");
_Static_assert(~(2.0 + 4.0i) == 2.0 - 4.0i, "");
_Static_assert((2.0 + 2.0i) / 2.0 == 1.0 + 1.0i, "");
_Static_assert((2.0 + 4.0i) / 1.0i == 4.0 - 2.0i, "");

void foo(void) {
	double x = 0.0;
	_Complex double cd = (_Complex double){x};
	cd = (_Complex double){x,};
	cd = (_Complex double){x,0.0};
	cd = (_Complex double){x,0.0,};
}

_Static_assert(__builtin_isnan(__real(0.0/0.0)), "");
_Static_assert(__builtin_isinf(__real((2.0 + 2.0i)/0.0)), "");
_Static_assert(__builtin_isinf(__imag((2.0 + 2.0i)/0.0)), "");

_Static_assert((_Complex double){2.0, __builtin_inf()} == (_Complex double){2.0, 3.0/0.0}, "");
_Static_assert(__builtin_isinf(__imag((_Complex double){2.0, __builtin_inf()})), "");
_Static_assert((_Complex double){2.0} + (_Complex double){2.0, 4.0} == (_Complex double){4.0, 4.0}, "");
_Static_assert(1.0 / (_Complex double){__builtin_inf(), __builtin_nan("")} == 0.0, "");
constexpr _Complex double product = (_Complex double){__builtin_inf(), __builtin_nan("") * 2.0};
_Static_assert(__builtin_isinf(__real__ product), "");
_Static_assert(__builtin_isnan(__imag__ product), "");
_Complex double a = (_Complex double) {1.0, 2.0,};
_Complex double b = (_Complex double) {1.0, 2.0,,,,,,};
_Complex double c = (_Complex double) {1.0, 2.0,3.0};

_Static_assert(3 + 4.0il == 3 + 4.0il, "");
_Static_assert(5ll + 4.0il == 5ll + 4.0il, "");
unsigned long complex_integer = 2.0i;
bool d = 3 != 2.0i;

/** manifest:
syntax
args = -std=c23

complex values.c:30:49: error: expected expression
complex values.c:30:50: error: expected expression
complex values.c:30:51: error: expected expression
complex values.c:30:52: error: expected expression
complex values.c:30:53: error: expected expression
complex values.c:31:49: warning: excess elements in scalar initializer [-Wexcess-initializers]
*/
