#define EXPECTED_ERRORS \
    "invalid types.c:8:6: error: cannot combine with previous 'long' specifier" \
    /* "duplicate '{s}' declaration specifier" */ \
    "invalid types.c:10:11: error: empty enum is invalid"

#define TESTS_SKIPPED 1

long float a;
// int _Alignas(int) _Alignas(float) b;
enum Foo {};
