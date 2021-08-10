_Static_assert(1, "foo" "\n" "bar");
_Static_assert(1, "foo" "\x606262 ");
_Static_assert(1, "\000062");
_Static_assert(1, "\U00110000");
_Static_assert(1, "\u0062");

int a = 'abcde';

#define EXPECTED_ERRORS "strings.c:2:30: error: escape sequence out of range" \
    "strings.c:4:20: error: invalid universal character" \
    "strings.c:5:20: error: invalid universal character" \
    "strings.c:7:9: warning: multi-character character constant" \
    "strings.c:7:9: warning: charcter constant too long for its type"
