//aro-args -E -P
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

#define EXPECTED_ERRORS "macro argument evaluation.c:15:2: error: Should error" \

