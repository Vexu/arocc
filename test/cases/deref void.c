void foo(void) {
    void *p = 0;
    (void)*p;
    p = &*p;
}
