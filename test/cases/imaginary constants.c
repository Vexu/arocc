#pragma GCC diagnostic push
#pragma GCC diagnostic warning "-Wgnu-imaginary-constant"

void foo(void) {
    _Complex double cd = 1.0 + 2.0i;
#pragma GCC diagnostic pop
    _Complex float cf = 1.0f + 2.0if;

    _Complex long double cld;
//    cld = 1.0l + 2.0il; /* TODO: long double literals */

#pragma GCC diagnostic warning "-Wgnu-complex-integer"
    int _Complex ci = 1i;
#pragma GCC diagnostic ignored "-Wgnu-complex-integer"
    _Complex unsigned long cl = 1uli; 
}

#if 1.0i
#endif

#define TESTS_SKIPPED 1
#define EXPECTED_ERRORS "imaginary constants.c:5:32: warning: imaginary constants are a GNU extension [-Wgnu-imaginary-constant]" \
    "imaginary constants.c:18:5: error: floating point literal in preprocessor expression" \
    "imaginary constants.c:13:9: warning: complex integer types are a GNU extension [-Wgnu-complex-integer]" \
