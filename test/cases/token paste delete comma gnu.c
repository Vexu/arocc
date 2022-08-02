//aro-args -E -Wgnu-zero-variadic-macro-arguments

#define eprintf(format, ...) fprintf (stderr, format, ##__VA_ARGS__)
eprintf("foo");
eprintf("foo",);
eprintf("foo", "bar");

#define ZERO_ARGS(...) foo(a, ##__VA_ARGS__)

ZERO_ARGS()
ZERO_ARGS(b)

#define foo(a,...) a, ## __VA_ARGS__
#define bar

foo(1,bar)

#define EXPECTED_ERRORS \
    "token paste delete comma gnu.c:3:55: warning: token pasting of ',' and __VA_ARGS__ is a GNU extension [-Wgnu-zero-variadic-macro-arguments]" \
    "token paste delete comma gnu.c:3:55: warning: token pasting of ',' and __VA_ARGS__ is a GNU extension [-Wgnu-zero-variadic-macro-arguments]" \
    "token paste delete comma gnu.c:8:31: warning: token pasting of ',' and __VA_ARGS__ is a GNU extension [-Wgnu-zero-variadic-macro-arguments]" \
    "token paste delete comma gnu.c:8:31: warning: token pasting of ',' and __VA_ARGS__ is a GNU extension [-Wgnu-zero-variadic-macro-arguments]" \
    "token paste delete comma gnu.c:13:23: warning: token pasting of ',' and __VA_ARGS__ is a GNU extension [-Wgnu-zero-variadic-macro-arguments]" \

