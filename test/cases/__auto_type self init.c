//aro-args -std=c23
void foo(void) {
    int x;
    __auto_type x = x;

    __auto_type y = (int []){1, y};

    auto z = z + 1;
}

#define EXPECTED_ERRORS "__auto_type self init.c:4:21: error: variable 'x' declared with deduced type '__auto_type' cannot appear in its own initializer" \
    "__auto_type self init.c:6:33: error: variable 'y' declared with deduced type '__auto_type' cannot appear in its own initializer" \
    "__auto_type self init.c:8:14: error: variable 'z' declared with deduced type '__auto_type' cannot appear in its own initializer" \

