void foo(void) {
    int a, b[a] = {};
    (int(int)){};
    int *c = 1.f;
    int d = {};
    int e = {1, 2};
    const char f[] = {"foo", "bar"};
    const char g[2] = "foo";
    int h[2] = (int []){1,2,3};
}

#define TESTS_SKIPPED 1
#define EXPECTED_ERRORS "initializers.c:2:17: error: variable-sized object may not be initialized" \
    "initializers.c:3:15: error: illegal initializer type" \
    "initializers.c:4:14: error: initializing 'int *' from incompatible type 'float'" \
    "initializers.c:5:13: error: scalar initializer cannot be empty" \
    "initializers.c:6:17: warning: excess elements in scalar initializer" \
    "initializers.c:7:30: warning: excess elements in string initializer" \
    "initializers.c:8:23: warning: initializer-string for char array is too long" \
    "initializers.c:9:16: error: cannot initialize type ('int [2]' with array of type 'int [3]')"
