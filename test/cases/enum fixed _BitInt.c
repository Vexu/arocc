enum E: _BitInt(20) {
    A,
};

void foo(void) {
    enum E e = 1;
    int x = -e;
}