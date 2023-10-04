//aro-args -Wfour-char-constants
/*

    A multiline comment to test that the linenumber is correct.

*/
#include <stddef.h>
_Static_assert(sizeof L' ' == sizeof(wchar_t), "sizes don't match");
unsigned short a = u'￿' + u'𐀁';
_Static_assert(L'ab' == 'b', "expected to match");
_Static_assert(U'ab' == 'b', "should not be evaluated");
_Static_assert('\1' == 0x01, "");
#if __INT_MAX__ >= 0x01020304
_Static_assert('\1\2\3\4' == 0x01020304, "");
#endif

#define EXPECTED_ERRORS "wide character constants.c:9:27: error: character too large for enclosing character literal type" \
    "wide character constants.c:10:16: error: wide character literals may not contain multiple characters" \
    "wide character constants.c:11:16: error: Unicode character literals may not contain multiple characters" \
    "wide character constants.c:14:16: warning: multi-character character constant [-Wfour-char-constants]" \

