#define FOO(X) X

#if FOO( X )
#error Should not error
#endif

#define Y 1

#if FOO ( Y )
#error Should error
#endif

#define EXPECTED_ERRORS "#if expression macro ws.c:10:2: error: Should error" \

