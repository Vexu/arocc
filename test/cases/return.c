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

char return_char(void) {
    return 1;
}
short return_short(void) {
    return 2;
}

int func1(int arg) {
    switch (arg) {
    case 1:
        return 1;
    case 2:
        return 2;
    default:
        return 3;
    } // no warning expected
}

int func2(int arg) {
    switch (arg) {
    case 1:
        func1(1);
    case 2:
        func1(2);
    default:
        func1(3);
    }
    return 1; // this is reachable
}

int func3(int arg) {
    switch (arg) return arg;
    return 1; // this is reachable
}

int then_noreturn(int arg) {
    if (arg) {
        return 2;
    } else {
        // do nothing
    }
    return 1; // reachable; no warning
}

int else_noreturn(int arg) {
    if (arg) {
        // do nothing
    } else {
        return 2;
    }
    return 1; // reachable; no warning
}

void *void_star_return(void) {
    return 4.2;
}

int *return_signed(unsigned int *x) {
    return x;
}

void call_return_signed(void) {
    unsigned int x = 0;
    int *y = return_signed(&x);
}

#define EXPECTED_ERRORS "return.c:2:5: error: non-void function 'b' should return a value [-Wreturn-type]" \
    "return.c:3:5: warning: unreachable code [-Wunreachable-code]" \
    "return.c:6:12: error: returning 'void' from a function with incompatible result type '_Bool'" \
    "return.c:11:5: warning: unreachable code [-Wunreachable-code]" \
    "return.c:12:12: warning: implicit pointer to integer conversion from 'int *' to 'int' [-Wint-conversion]" \
    "return.c:17:5: warning: unreachable code [-Wunreachable-code]" \
    "return.c:18:12: error: returning 'int *' from a function with incompatible result type 'float'" \
    "return.c:22:12: warning: implicit integer to pointer conversion from 'int' to 'int *' [-Wint-conversion]" \
    "return.c:23:5: warning: unreachable code [-Wunreachable-code]" \
    "return.c:24:12: error: returning 'float *' from a function with incompatible result type 'int *'" \
    "return.c:26:12: error: returning '_Atomic(int) (*)[3]' from a function with incompatible result type 'int *'" \
    "return.c:30:1: warning: non-void function 'foo' does not return a value [-Wreturn-type]" \
    "return.c:32:5: error: non-void function 'bar' should return a value [-Wreturn-type]" \
    "return.c:35:12: error: void function 'baz' should not return a value [-Wreturn-type]" \
    "return.c:38:17: error: function cannot return a function" \
    "return.c:96:12: error: returning 'double' from a function with incompatible result type 'void *'" \
    "return.c:100:12: warning: returning 'unsigned int *' from a function with incompatible result type 'int *' converts between pointers to integer types with different sign [-Wpointer-sign]" \

