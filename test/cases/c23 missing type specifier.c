//aro-args -std=c23
#define EXPECTED_ERRORS \
    "c23 missing type specifier.c:4:8: error: a type specifier is required for all declarations"
static x = 5;
