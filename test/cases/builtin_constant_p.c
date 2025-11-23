_Static_assert(__builtin_constant_p(0), "");
_Static_assert(__builtin_constant_p(1), "");
_Static_assert(__builtin_constant_p("hello"), "");
_Static_assert(__builtin_constant_p((int){4}), "");

int global = 5;
_Static_assert(!__builtin_constant_p(global), "");

const int global_const = 10;
_Static_assert(__builtin_constant_p(global_const), "");

void foo(const int const_param, const char *const s) {
  _Static_assert(!__builtin_constant_p(const_param), "");
  _Static_assert(!__builtin_constant_p(s), "");

  const float x = 5;
  _Static_assert(__builtin_constant_p(x), "");

  const char *a = "a";
  char *const b = "b";
  const char *const c = "c";

  _Static_assert(!__builtin_constant_p(a), "");
  _Static_assert(__builtin_constant_p(b), "");
  _Static_assert(__builtin_constant_p(c), "");
}

int a;
_Static_assert(!__builtin_constant_p(&a), "");
_Static_assert(__builtin_constant_p(&"bar"), "");

_Static_assert(__builtin_constant_p(), "");
_Static_assert(__builtin_constant_p(1, 2), "");

_Static_assert(!__builtin_constant_p("ABC"[0]), ""); // Should be constant

#define TESTS_SKIPPED 1

#define EXPECTED_ERRORS "builtin_constant_p.c:32:16: error: expected 1 argument(s) got 0" \
    "builtin_constant_p.c:33:16: error: expected 1 argument(s) got 2" \

