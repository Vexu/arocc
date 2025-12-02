// This can either expand as 2*f(9) or as 2*9*g (see 6.10.3.4 in the standard)
// We follow gcc and clang in expanding it to 2*9*g

#define f(a) a*g
#define g(a) f(a)

f(2)(9)

/** manifest:
expand
*/
