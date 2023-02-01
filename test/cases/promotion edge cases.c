struct S {
    unsigned x: 3;
    long y: 5;
};
void foo(void) {
    char c = 0;
    double d = 2.0;
    d = d + c; // promote char to int then to double
    struct S s = { .x = 1U, .y = 1L};
    int x = s.x + 1; // unsigned bitfield promotes to int if it fits
    int y = s.y + 1; // long bitfield promotes to int if it fits
    __fp16 fp16 = 0.0f;
    fp16 = fp16 + fp16; // __fp16 casts to float for arithmetic
}
