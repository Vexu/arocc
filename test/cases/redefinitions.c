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

int f1(const int);
int f1(int a) {
    return a;
}
int f2(const int*);
int f2(int *a) {
    return *a;
}

struct S {
    struct {
        int a;
    };
    int a;
    float a;
    struct {
        struct {
            int a;
        };
    };
};

typedef int MyInt;
typedef float MyFloat;
typedef MyFloat MyInt;

typedef int MyOtherInt;
typedef const int MyOtherInt;

int f(int (*)(), double (*)[3]);
int f(int (*)(char *), double (*)[]);

double maximum(int n, int m, double a[n][m]);
double maximum(int n, int m, double a[*][*]);
double maximum(int n, int m, double a[ ][*]);
double maximum(int n, int m, double a[ ][m]);

void f3(double (* restrict a)[5]);
void f3(double a[restrict][5]);
void f3(double a[restrict 3][5]);
void f3(double a[restrict static 3][5]);

int f4(int, ...);
int f4(int);

int f5(int (*)(), double (*)[3]);
int f5(int (*)(char), double (*)[]); // not compatible since char undergoes default argument promotion

void f6();
void f6(void) {}

void f7(void);
void f7() {}

int X;
enum E {
    X = 4294967295,
};

#define EXPECTED_ERRORS "redefinitions.c:4:5: error: redefinition of 'foo' as different kind of symbol" \
    "redefinitions.c:1:5: note: previous definition is here" \
    "redefinitions.c:5:5: error: redefinition of 'foo' as different kind of symbol" \
    "redefinitions.c:1:5: note: previous definition is here" \
    "redefinitions.c:12:5: error: redefinition of 'bar'" \
    "redefinitions.c:11:5: note: previous definition is here" \
    "redefinitions.c:15:7: error: redefinition of 'baz' with a different type" \
    "redefinitions.c:14:5: note: previous definition is here" \
    "redefinitions.c:17:25: error: redefinition of parameter 'foo'" \
    "redefinitions.c:17:16: note: previous definition is here" \
    "redefinitions.c:18:17: error: redefinition of parameter 'foo'" \
    "redefinitions.c:18:12: note: previous definition is here" \
    "redefinitions.c:18:12: error: identifier parameter lists are only allowed in function definitions" \
    "redefinitions.c:19:30: error: redefinition of parameter 'foo'" \
    "redefinitions.c:19:18: note: previous definition is here" \
    "redefinitions.c:23:5: error: redefinition of 'func4' with a different type" \
    "redefinitions.c:22:5: note: previous definition is here" \
    "redefinitions.c:26:9: error: redefinition of 'a'" \
    "redefinitions.c:25:15: note: previous definition is here" \
    "redefinitions.c:30:5: error: redefinition of 'func5'" \
    "redefinitions.c:25:5: note: previous definition is here" \
    "redefinitions.c:38:1: warning: type specifier missing, defaults to 'int' [-Wimplicit-int]" \
    "redefinitions.c:38:1: error: variable length arrays not allowed at file scope" \
    "redefinitions.c:45:5: error: redefinition of 'f2' with a different type" \
    "redefinitions.c:44:5: note: previous definition is here" \
    "redefinitions.c:53:9: error: duplicate member 'a'" \
    "redefinitions.c:51:13: note: previous definition is here" \
    "redefinitions.c:54:11: error: duplicate member 'a'" \
    "redefinitions.c:53:9: note: previous definition is here" \
    "redefinitions.c:57:17: error: duplicate member 'a'" \
    "redefinitions.c:54:11: note: previous definition is here" \
    "redefinitions.c:64:17: error: typedef redefinition with different types ('float' vs 'int')" \
    "redefinitions.c:62:13: note: previous definition is here" \
    "redefinitions.c:67:19: error: typedef redefinition with different types ('const int' vs 'int')" \
    "redefinitions.c:66:13: note: previous definition is here" \
    "redefinitions.c:83:5: error: redefinition of 'f4' with a different type" \
    "redefinitions.c:82:5: note: previous definition is here" \
    "redefinitions.c:86:5: error: redefinition of 'f5' with a different type" \
    "redefinitions.c:85:5: note: previous definition is here" \
    "redefinitions.c:96:5: error: redefinition of 'X' as different kind of symbol" \
    "redefinitions.c:94:5: note: previous definition is here" \

