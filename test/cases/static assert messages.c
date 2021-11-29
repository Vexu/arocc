void foo(int x) {
    _Static_assert(x, "not allowed");
    _Static_assert(1);
    _Static_assert(0);
}

void bar(void) {
    _Static_assert(1, "ok", "not ok");
}

_Static_assert(1 == 0, "They are not equal!");

#define EXPECTED_ERRORS "static assert messages.c:2:20: error: static_assert expression is not an integral constant expression" \
    "static assert messages.c:3:5: warning: static_assert with no message is a C2X extension [-Wc2x-extensions]" \
    "static assert messages.c:4:5: warning: static_assert with no message is a C2X extension [-Wc2x-extensions]" \
    "static assert messages.c:4:5: error: static assertion failed" \
    "static assert messages.c:8:27: error: expected ')', found ','" \
    "static assert messages.c:8:19: note: to match this '('" \
    "static assert messages.c:11:1: error: static assertion failed \"They are not equal!\"" \
