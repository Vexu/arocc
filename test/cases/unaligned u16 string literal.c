struct S {
    int x;
};

void foo(void) {
    struct S s;
    s.y;
}

_Static_assert(u"A");

/** manifest:
syntax

unaligned u16 string literal.c:7:7: error: no member named 'y' in 'struct S'
unaligned u16 string literal.c:10:1: warning: '_Static_assert' with no message is a C23 extension [-Wc23-extensions]
unaligned u16 string literal.c:10:16: error: static assertion expression is not an integral constant expression
*/
