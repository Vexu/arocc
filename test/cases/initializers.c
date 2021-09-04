void foo(void) {
    int a, b[a] = {};
    (int(int)){};
    int *c = 1.f;
    int d = {};
}

#define EXPECTED_ERRORS "initializers.c:2:17: error: variable-sized object may not be initialized" \
    "initializers.c:3:15: error: illegal initializer type" \
    "initializers.c:4:14: error: initializing 'int *' from incompatible type 'float'" \
    "initializers.c:5:13: error: scalar initializer cannot be empty"
