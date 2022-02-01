#pragma GCC diagnostic ignored "-Wunused-value"

void foo(void) {
    (long double)1 + 1.fi;
    1.i + 1.f;
    (long double)1 + 1.;
    1.fi + 1.f;
    1.f + 1.f;
    (long double)1.f + 1.f;
}

#define EXPECTED_TYPES "_Complex long double" "_Complex double" "long double" \
    "_Complex float" "float" "long double"
