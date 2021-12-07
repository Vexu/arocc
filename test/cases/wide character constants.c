/*

    A multiline comment to test that the linenumber is correct.

*/
#include <stddef.h>
_Static_assert(sizeof L' ' == sizeof(wchar_t), "sizes don't match");
unsigned short a = u'￿' + u'𐀁';
_Static_assert(L'ab' == 'b', "expected to match");
_Static_assert(U'ab' == 'b', "should not be evaluated");

#define EXPECTED_ERRORS "wide character constants.c:8:27: error: character too large for enclosing character literal type" \
    "wide character constants.c:9:16: warning: extraneous characters in character constant ignored" \
    "wide character constants.c:10:16: error: Unicode character literals may not contain multiple characters" \
