int foo;
_Static_assert(1 ? 1 : foo, "");
_Static_assert(0 ? foo : 1, "");
_Static_assert(__builtin_constant_p(foo) ? foo : 1, "");

const int bar;
_Static_assert(__builtin_constant_p(bar) ? bar : 1, ""); // matches clang - uninitialized const is not const for the purposes of `__builtin_constant_p` even if global

const int baz = 0;
_Static_assert(!(__builtin_constant_p(baz) ? baz : 0), "");
_Static_assert(!(__builtin_constant_p(baz) ? baz : 1), "");

const int qux = 1;
_Static_assert(__builtin_constant_p(qux) ? qux : 0, "");
_Static_assert(__builtin_constant_p(qux) ? qux : 1, "");

_Static_assert(__builtin_constant_p(1) ? : 0, "");
_Static_assert(!__builtin_constant_p(1) ? : 1, "");
_Static_assert(__builtin_constant_p(foo) ? : 1, "");
_Static_assert(!__builtin_constant_p(foo) ? : 0, "");

/** manifest:
syntax
*/
