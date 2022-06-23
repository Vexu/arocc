//aro-args -Wno-int-conversion
union U {
    int x;
    float y;
};

int bar(void) {
    return 42;
}
void foo(void) {
    int x;
    float f;
    double d;
    int arr[2];
    int *p;

    p = (int *)&f; // bitcast
    p = arr; // array_to_pointer

    x = bar(); // function_to_pointer

    _Bool b = p; // pointer_to_bool

    x = p; // pointer_to_int

    x = b; // bool_to_int

    f = b;  // bool_to_float

    p = b;  // bool_to_pointer

    b = x;  // int_to_bool

    f = x; // int_to_float

    p = x; // int_to_pointer

    b = f; //float_to_bool

    x = f; //float_to_int

    x = 1L; // int_cast

    f = d; // float_cast
    d = f; // float_cast

    p = 0; // null_to_pointer

    (void)p; // to_void

    union U u;
    // TODO: cast to union
    // u = (union U)x;
    // u = (union U)f;
}
