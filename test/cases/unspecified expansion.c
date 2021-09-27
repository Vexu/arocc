// This can either expand as 2*f(9) or as 2*9*g (see 6.10.3.4 in the standard)
// Currently arocc does the former, but gcc and clang do the latter
#define EXPECTED_TOKENS 2*f(9)

#define f(a) a*g
#define g(a) f(a)

f(2)(9)
