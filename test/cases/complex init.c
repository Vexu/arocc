void foo(void) {
    _Complex double cd = { 1.0, 2.0 };
    _Complex float cf = { 1.0f, 2.0f };
    _Complex int ci = {1, 2};

    cd = __builtin_complex(1.0, 2.0);
    cf = __builtin_complex(1.0f, 2.0f);

    cd = (_Complex double) { 1.0f, 2.0f}; // convert float literals to double
    cf = (_Complex float) { 1.0, 2.0 }; // convert double literals to float
}
