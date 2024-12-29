typedef long foo;
typedef long foo;
_Static_assert(__builtin_types_compatible_p(long, foo), "");

typedef foo bar;
typedef foo bar;
_Static_assert(__builtin_types_compatible_p(bar, foo), "");
