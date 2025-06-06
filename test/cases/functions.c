int foo(int bar) {
    (void)sizeof(struct Foo { int a; });
    (void)__alignof(struct Foo);
    return bar;
}

int fooo(bar, baz)
    float bar;
    int *baz;
    double quux;
{
    return *baz * bar;
}

int foooo(n, bar)
    int n;
    int bar[n];
{}

int bar(int) = foo;

int baz(int a[*]) {
    return a[0];
}

static int GLOBAL = 1;
int nested_scopes(int a, int b) {
    if (a == 1) {
        int target;
        target = 1;
        return b == target;
    } else {
        int target = 2;
        if (b == target) {
            return GLOBAL == 1;
        }
        return target == 2;
    }
}

struct S;
void forward_decl_struct(struct S s) {}
void forward_decl_struct_old(s)
struct S s;
{}

typedef union Union U;
void forward_decl_union_td(U u) {}
void forward_decl_union_td_old(u)
U u;
{}

void inline_decl_enum(enum E e) {}
void inline_decl_enum_old(e)
enum EE e;
{}

void unspecified_variable_len(int, int [][*]);
typedef void (*func_pointer)(int, int[][*]);

void unspecified_variable_len(int n, int x[][n]) { }

static func_pointer p = unspecified_variable_len;

void static_array_parameter(x)
	int x[static 5];
{}

int(wrapped)(void) {
   return 0;
}

int ARRAY[2];
int (*return_array_ptr(void))[2] {
    return &ARRAY;
}

void no_params(void);
void no_params(int x){}

void invalid_func(__auto_type);
int invalid_int = invalid_func;

void desugar_func_ty(void) {
    typedef int foo;
    foo bar(foo);
    int *ptr = bar;
}

#define EXPECTED_ERRORS "functions.c:10:12: error: parameter named 'quux' is missing" \
    "functions.c:20:14: error: illegal initializer (only variables can be initialized)" \
    "functions.c:18:2: warning: non-void function 'foooo' does not return a value [-Wreturn-type]" \
    "functions.c:22:13: error: variable length array must be bound in function definition" \
    "functions.c:42:35: error: parameter has incomplete type 'struct S'" \
    "functions.c:44:10: error: parameter has incomplete type 'struct S'" \
    "functions.c:48:30: error: parameter has incomplete type 'U' (aka 'union Union')" \
    "functions.c:50:3: error: parameter has incomplete type 'U' (aka 'union Union')" \
    "functions.c:53:30: error: parameter has incomplete type 'enum E'" \
    "functions.c:55:9: error: parameter has incomplete type 'enum EE'" \
    "functions.c:79:6: error: redefinition of 'no_params' with a different type" \
    "functions.c:78:6: note: previous definition is here" \
    "functions.c:81:19: error: '__auto_type' not allowed in function prototype" \
    "functions.c:87:16: warning: incompatible pointer types initializing 'int *' from incompatible type 'foo (foo)' (aka 'int (int)') [-Wincompatible-pointer-types]" \
