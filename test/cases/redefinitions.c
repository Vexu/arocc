int foo;

enum {
    foo,
    foo,
};

int foo;

int bar;
int bar = 1;
int bar = 1;

int baz;
float baz;

void func1(int foo, int foo);
void func2(foo, foo);
void func3(enum {foo} a, int foo);

int func4(int[4][4]);
int func4(int[4][4]);
int func4(int[4][3]);

int func5(int a) {
    int a;
    return a;
}

int func5(int a) {
    return 10;
}

int func5(int a);

int arr[2];
int x = 0;
arr[x];

#define TESTS_SKIPPED 1
// int f(int (*)(), double (*)[3]);
// int f(int (*)(char *), double (*)[]);

#define EXPECTED_ERRORS "redefinitions.c:4:5: error: redefinition of 'foo' as different kind of symbol" \
    "redefinitions.c:1:5: note: previous definition is here" \
    "redefinitions.c:5:5: error: redefinition of 'foo'" \
    "redefinitions.c:4:5: note: previous definition is here" \
    "redefinitions.c:8:5: error: redefinition of 'foo' as different kind of symbol" \
    "redefinitions.c:5:5: note: previous definition is here" \
    "redefinitions.c:12:5: error: redefinition of 'bar'" \
    "redefinitions.c:11:5: note: previous definition is here" \
    "redefinitions.c:15:7: error: redefinition of 'baz' with a different type" \
    "redefinitions.c:14:5: note: previous definition is here" \
    "redefinitions.c:17:25: error: redefinition of parameter 'foo'" \
    "redefinitions.c:17:16: note: previous definition is here" \
    "redefinitions.c:18:17: error: redefinition of parameter 'foo'" \
    "redefinitions.c:18:12: note: previous definition is here" \
    "redefinitions.c:18:12: warning: identifier parameter lists are only allowed in function definitions" \
    "redefinitions.c:19:30: error: redefinition of parameter 'foo'" \
    "redefinitions.c:19:18: note: previous definition is here" \
    "redefinitions.c:23:5: error: redefinition of 'func4' with a different type" \
    "redefinitions.c:22:5: note: previous definition is here" \
    "redefinitions.c:26:9: error: redefinition of 'a'" \
    "redefinitions.c:25:15: note: previous definition is here" \
    "redefinitions.c:30:5: error: redefinition of 'func5'" \
    "redefinitions.c:25:5: note: previous definition is here" \
    "redefinitions.c:38:1: warning: type specifier missing, defaults to 'int' [-Wimplicit-int]" \
    "redefinitions.c:38:4: error: variable length arrays not allowed at file scope" \
    "redefinitions.c:38:1: error: redefinition of 'arr' with a different type" \
    "redefinitions.c:36:5: note: previous definition is here"
