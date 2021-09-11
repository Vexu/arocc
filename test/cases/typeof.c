//std=gnu17
int foo(void) {
    return 42.0;
}

typeof(int) g_i = 42;
typeof(foo()) f_i = 42.0;

struct S {
    typeof(int) x;
    typeof(foo()) y;
};

int bar(typeof(int *restrict) a, int y) {
    return 42;
}

void baz(void) {
    const typeof(int) a;
    const typeof(foo()) b;
    typeof(foo()) i = 4;
    typeof(float) f = 4.5;
    typeof(i)* p_i = &i;
    p_i = &f;
    p_i = (typeof(i)*)&f;
    p_i = (typeof(p_i))&f;
    typeof(const int)x;
    x = 5;
    const typeof(*p_i)y;
    y = 5;
    typeof(0/0) divzero = 0;
}

typeof((void)1, (int*)2) a = 2.f;
typeof();

#define EXPECTED_ERRORS "typeof.c:24:9: warning: incompatible pointer types assigning to 'int *' from incompatible type 'float *'" \
    "typeof.c:28:7: error: expression is not assignable" \
    "typeof.c:30:7: error: expression is not assignable" \
    "typeof.c:34:30: error: initializing 'int *' from incompatible type 'float'" \
    "typeof.c:35:8: error: expected expression" \
