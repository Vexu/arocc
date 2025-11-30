#define FOO(X) X##OK
#define BAR FOO

#define A 1

#if BAR(A)
#error Should not error
#endif

BAR(A)

#define AOK 1
#if BAR(A)
#error Should error
#endif

BAR(A)

/** manifest:
expand_error

macro argument evaluation.c:14:2: error: Should error
*/
