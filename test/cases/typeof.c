#pragma Aro_test version gnu17

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

void qux(int x) {
    char vla[x];
    char arr[10];
    typeof(arr) arr2;
    typeof(char[10]) arr3;

    typeof(vla) vla2;
    typeof(char[x]) vla3;
    char *p = arr2;
    p = arr3;
    p = vla2;
    p = vla3;

    typeof(_Bool) b = 10;
    b = 5;
    typeof(b) b2 = 5;
    b2 = 10;
    b = (typeof(b2))10;
}

void const_arrays(void) {
    const typeof(int[]) arr1 = {1,2};
    arr1[0] = 1;
    const typeof(int[2]) arr2 = {1,2};
    arr2[0] = 1;

    typeof(const int[]) arr3 = {1,2};
    arr3[0] = 1;
    typeof(const int[2]) arr4 = {1,2};
    arr4[0] = 1;

    const typeof(int) arr5[] = {1,2};
    arr5[0] = 1;
    typeof(const int) arr6[] = {1,2};
    arr6[0] = 1;

    const int arr7[] = {1,2};
    arr7[0] = 1;

    typeof(const typeof(typeof(int[2]))) arr8 = {1,2};
    arr8[0] = 1;

    const typeof(int[2]) arr9 = {1,2};
    const int *p = arr9;
    const typeof(int[]) arr10 = {1,2};
    p = arr10;
    typeof(const int[]) arr11 = {1,2};
    p = arr11;
    typeof(const int[2]) arr12 = {1,2};
    p = arr12;
    typeof(const int) arr13[2] = {1,2};
    p = arr13;
    typeof(const int) arr14[] = {1,2};
    p = arr14;
}

void pointers(void) {
    const int arr[2] = {1,2};
    typeof(const int) *p1 = arr;
    const typeof(int) *p2 = arr;
    typeof(const int *)p3 = arr;
    typeof(int *)const p4 = arr;
}

float my_func(int x) {
    return 2.0f;
}
typeof(my_func) my_other_func;
void test_my_other_func(void) {
    float f = my_func(42);
    f = my_other_func(42);
}

void sizeof_decayed(int x) {
    char vla[x];
    typeof(vla) vla2;
    -vla2;
}

#define EXPECTED_ERRORS "typeof.c:24:9: warning: incompatible pointer types assigning to 'int *' from incompatible type 'float *'" \
    "typeof.c:28:7: error: expression is not assignable" \
    "typeof.c:30:7: error: expression is not assignable" \
    "typeof.c:34:30: error: initializing 'int *' from incompatible type 'float'" \
    "typeof.c:35:8: error: expected expression" \
    "typeof.c:59:13: error: expression is not assignable" \
    "typeof.c:61:13: error: expression is not assignable" \
    "typeof.c:64:13: error: expression is not assignable" \
    "typeof.c:66:13: error: expression is not assignable" \
    "typeof.c:69:13: error: expression is not assignable" \
    "typeof.c:71:13: error: expression is not assignable" \
    "typeof.c:74:13: error: expression is not assignable" \
    "typeof.c:77:13: error: expression is not assignable" \
    "typeof.c:98:29: warning: initializing 'int *' from incompatible type 'const int *' discards qualifiers" \
    "typeof.c:113:5: error: invalid argument type 'char *' to unary expression" \
