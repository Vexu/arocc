void foo(void) {
    int x = 5;
    void *y = &&baz;
    bar:
    y = &&bar;
    baz:
    x = 0;
    goto *y;
    goto *&&baz;
}

void no_address_of_label(void *arg) {
    label:
    goto *arg;
}

void implicit_conversion(void) {
    int x = 0;
    void *y = &&label;
    label:
    goto *0;
    goto *x;
}

void invalid_param(void) {
    void *p = &&label;
    float f = 0.0f;
    label:
    goto *f;
}

#define EXPECTED_ERRORS "address of label.c:14:5: error: computed goto in function with no address-of-label expressions" \
    "address of label.c:22:11: warning: implicit integer to pointer conversion from 'int' to 'const void *'" \
    "address of label.c:29:11: error: passing 'float' to parameter of incompatible type"
