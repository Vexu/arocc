_Static_assert(-1.0 - 1.0 == -2.0, "");
_Static_assert(-2.0f == -2.0, "");
_Static_assert(1.0 == (2.0||0), "");
void foo(void) {
    float f = 2.0 || 0;
}
