_Bool b(void) {
    return;
    return 1;
    return 1.;
    return (int *)1l;
    return (void)1;
}

int i(void) {
    return 1;
    return 1.f;
    return (int*)1L;
}

float f(void) {
    return 1;
    return 1.f;
    return (int*)1L;
}

int *ip(void) {
    return 1;
    return (int*)1L;
    return (float*)2L;
    _Atomic int a[3];
    return &a;
}

int foo(void) {
}
int bar(void) {
    return;
}
void baz(void) {
    return 1;
}

int *return_func(void)(void) {
    return 0;
}


#define EXPECTED_ERRORS "return.c:2:5: error: non-void function 'b' should return a value" \
    "return.c:3:5: warning: unreachable code" \
    "return.c:6:12: error: returning 'void' from a function with incompatible result type" \
    "return.c:11:5: warning: unreachable code" \
    "return.c:12:12: warning: implicit pointer to integer conversion from 'int *' to 'int'" \
    "return.c:17:5: warning: unreachable code" \
    "return.c:18:12: error: returning 'int *' from a function with incompatible result type" \
    "return.c:22:12: warning: implicit integer to pointer conversion from 'int' to 'int *'" \
    "return.c:23:5: warning: unreachable code" \
    "return.c:24:12: error: returning 'float *' from a function with incompatible result type" \
    "return.c:26:12: error: returning '_Atomic(int) (*)[3]' from a function with incompatible result type" \
    "return.c:30:1: warning: non-void function 'foo' does not return a value [-Wreturn-type]" \
    "return.c:32:5: error: non-void function 'bar' should return a value [-Wreturn-type]" \
    "return.c:35:12: error: void function 'baz' should not return a value [-Wreturn-type]" \
    "return.c:38:17: error: function cannot return a function" \
