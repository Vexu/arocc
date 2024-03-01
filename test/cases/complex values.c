_Static_assert(1.0 + 2.0i == 2.0i + 1.0, "");
_Static_assert(2.0i * 2.0i == -4.0, "");
_Static_assert((double)2.0i == 0, "");
_Static_assert((double)(_Complex double)42 == 42, "");
_Static_assert(-2.0i - 2.0i == -4.0i, "");
_Static_assert(~(2.0 + 4.0i) == 2.0 - 4.0i, "");
_Static_assert((2.0 + 2.0i) / 2.0 == 1.0 + 1.0i, "");
_Static_assert((2.0 + 4.0i) / 1.0i == 4.0 - 2.0i, "");