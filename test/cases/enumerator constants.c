enum E {
	A,
	B = 10,
	C,
	D = 2,
	E = -2,
	F,
};

_Static_assert(A == 0, "A is wrong");
_Static_assert(B == 10, "B is wrong");
_Static_assert(C == 11, "C is wrong");
_Static_assert(D == 2, "D is wrong");
_Static_assert(E == -2, "E is wrong");
_Static_assert(F == -1, "F is wrong");

void foo(enum E e) {
	switch (e) {
		case A: return;
		default: return;
	}
}
