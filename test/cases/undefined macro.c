#pragma GCC diagnostic warning "-Wundef"

#if FOO
    #error "Error"
#endif

#define FOO BAR

#if FOO
    #error "Error"
#endif

#define EXPECTED_ERRORS "undefined macro.c:3:5: warning: 'FOO' is not defined, evaluates to 0 [-Wundef]" \
    "undefined macro.c:9:5: warning: 'BAR' is not defined, evaluates to 0 [-Wundef]" \
    "undefined macro.c:7:13: note: expanded from here" \
