void foo(int x) {
    _Static_assert(x, "not allowed");
    _Static_assert(1);
    _Static_assert(0);
}

void bar(void) {
    _Static_assert(1, "ok", "not ok");
}

_Static_assert(1 == 0, "They are not equal!");
_Static_assert(sizeof(int) == 3, "");

/** manifest:
syntax

static assert messages.c:2:20: error: static assertion expression is not an integral constant expression
static assert messages.c:3:5: warning: '_Static_assert' with no message is a C23 extension [-Wc23-extensions]
static assert messages.c:4:5: warning: '_Static_assert' with no message is a C23 extension [-Wc23-extensions]
static assert messages.c:4:20: error: static assertion failed due to requirement '0'
static assert messages.c:8:27: error: expected ')', found ','
static assert messages.c:8:19: note: to match this '('
static assert messages.c:11:16: error: static assertion failed due to requirement '1 == 0': They are not equal!
static assert messages.c:12:16: error: static assertion failed due to requirement 'sizeof(int) == 3'
static assert messages.c:12:28: note: expression evaluates to '4 == 3'
*/
