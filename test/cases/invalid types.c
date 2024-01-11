long float a;
_Atomic(int) _Atomic(float) b;
enum Foo {};
_Atomic(int(void)) c;
_Atomic(int [3]) d;
_Atomic void e;
void f[4];
struct Bar f;
int x[2305843009213693951u];

_Complex z;


void foo(int arr[]) {
    typeof(arr) a[2];
    struct bar[1] = {1};
    struct bar a[] = {1};
    struct bar[1][1] = {{1}};
    struct bar b[1][] = {{1}};
    struct bar b[1][B(1)] = {1};
}

int bar["foo"];
int baz[] = 111111E1111111111111;
int qux[] = baz;

int g[];
extern int h[];
void foo(void) {
    int i[];
    char j[] = "hello";
}

#define EXPECTED_ERRORS \
    "invalid types.c:1:6: error: cannot combine with previous 'long' specifier" \
    "invalid types.c:2:14: warning: duplicate 'atomic' declaration specifier [-Wduplicate-decl-specifier]" \
    "invalid types.c:2:14: error: cannot combine with previous 'int' specifier" \
    "invalid types.c:3:11: error: empty enum is invalid" \
    "invalid types.c:4:1: error: atomic cannot be applied to function type 'int (void)'" \
    "invalid types.c:5:1: error: atomic cannot be applied to array type 'int [3]'" \
    "invalid types.c:6:1: error: atomic cannot be applied to incomplete type 'void'" \
    "invalid types.c:6:14: error: variable has incomplete type 'void'" \
    "invalid types.c:7:7: error: array has incomplete element type 'void'" \
    "invalid types.c:8:12: error: tentative definition has type 'struct Bar' that is never completed" \
    "invalid types.c:8:8: note: forward declaration of 'struct Bar'" \
    "invalid types.c:9:6: error: array is too large" \
    "invalid types.c:11:1: warning: plain '_Complex' requires a type specifier; assuming '_Complex double'" \
    "invalid types.c:14:6: note: previous definition is here" \
    "invalid types.c:16:15: error: expected identifier or '('" \
    "invalid types.c:17:17: error: array has incomplete element type 'struct bar'" \
    "invalid types.c:18:15: error: expected identifier or '('" \
    "invalid types.c:19:17: error: array has incomplete element type 'struct bar []'" \
    "invalid types.c:20:21: error: call to undeclared function 'B'; ISO C99 and later do not support implicit function declarations [-Wimplicit-function-declaration]" \
    "invalid types.c:20:23: warning: passing arguments to a function without a prototype is deprecated in all versions of C and is not supported in C23 [-Wdeprecated-non-prototype]" \
    "invalid types.c:20:17: error: array has incomplete element type 'struct bar [<expr>]'" \
    "invalid types.c:23:9: error: size of array has non-integer type 'char [4]'" \
    "invalid types.c:24:13: error: array initializer must be an initializer list or wide string literal" \
    "invalid types.c:25:13: error: array initializer must be an initializer list or wide string literal" \
    "invalid types.c:27:5: warning: tentative array definition assumed to have one element" \
    "invalid types.c:29:6: error: redefinition of 'foo'" \
    "invalid types.c:30:9: error: variable has incomplete type 'int []'" \
