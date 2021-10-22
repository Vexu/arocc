#define foo bar
#pragma GCC poison "bar" foo
#pragma GCC poison bar

int foo;
int bar;

#define baz(x)

baz(bar)

#pragma GCC poison baz

#define EXPECTED_ERRORS "pragma poison.c:2:20: error: can only poison identifier tokens" \
    "pragma poison.c:6:5: error: attempt to use a poisoned identifier" \
    "pragma poison.c:10:5: error: attempt to use a poisoned identifier" \
    "pragma poison.c:12:20: warning: poisoning existing macro" \
