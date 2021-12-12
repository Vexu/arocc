#pragma GCC diagnostic push
#pragma GCC diagnostic warning "-Wgnu-imaginary-constant"

void foo(void) {
    _Complex double cd = 1.0 + 2.0i;
#pragma GCC diagnostic pop
    _Complex float cf = 1.0f + 2.0if;
}

#if 1.0i
#endif

#define EXPECTED_ERRORS "imaginary constants.c:5:32: warning: imaginary constants are a GNU extension" \
    "imaginary constants.c:10:5: error: floating point literal in preprocessor expression" \
