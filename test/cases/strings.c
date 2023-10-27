_Static_assert(1, "foo" "\n" "bar");
_Static_assert(1, "foo" "abc\x606262 ");
_Static_assert(1, "\000062");
_Static_assert(1, "\U00110000");
_Static_assert(1, "\u0062");

int a = 'abcde';

_Static_assert(1, "\uD800");
_Static_assert(1, "\U0000DFFF");
_Static_assert(1, "\UFFFFFFFF");
_Static_assert(1, "\u0060");

#pragma GCC diagnostic warning "-Wpedantic"
_Static_assert(1, "aaァ\e[1;");
#pragma GCC diagnostic pop

#define EXPECTED_ERRORS "strings.c:2:29: error: escape sequence out of range" \
    "strings.c:4:19: error: invalid universal character" \
    "strings.c:5:19: error: character 'b' cannot be specified by a universal character name" \
    "strings.c:7:9: warning: multi-character character constant [-Wmultichar]" \
    "strings.c:7:9: warning: character constant too long for its type" \
    "strings.c:9:19: error: invalid universal character" \
    "strings.c:10:19: error: invalid universal character" \
    "strings.c:11:19: error: invalid universal character" \
    "strings.c:15:23: warning: use of non-standard escape character '\\e' [-Wpedantic]" \
