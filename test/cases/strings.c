_Static_assert(1, "foo" "\n" "bar");
_Static_assert(1, "foo" "\x606262 ");
_Static_assert(1, "\000062");
_Static_assert(1, "\U00110000");
_Static_assert(1, "\u0062");

int a = 'abcde';

_Static_assert(1, "\uD800");
_Static_assert(1, "\U0000DFFF");
_Static_assert(1, "\UFFFFFFFF");
_Static_assert(1, "\u0060");

#define EXPECTED_ERRORS "strings.c:2:30: error: escape sequence out of range" \
    "strings.c:4:20: error: invalid universal character" \
    "strings.c:5:20: error: invalid universal character" \
    "strings.c:7:9: warning: multi-character character constant" \
    "strings.c:7:9: warning: character constant too long for its type" \
    "strings.c:9:20: error: invalid universal character" \
    "strings.c:10:20: error: invalid universal character" \
    "strings.c:11:20: error: invalid universal character" \
