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

_Static_assert(sizeof(u'a') == 2, "");
_Static_assert(sizeof(U'a') == 4, "");
unsigned long A = U'\xFFFFFFFF';
unsigned long B = u'\xFFFFFFFF';
unsigned long C = U'𝒵';  // U+1D4B5
unsigned long D = u'𝒵';  // U+1D4B5
unsigned long E = U'ℤ';  // U+2124
unsigned long F = u'ℤ';  // U+2124
unsigned long G = U'\UFFFFFFFF';
unsigned long H = u'\U0001D4B5';
unsigned long I = U'ab';
unsigned long J = u'ab';

#define EXPECTED_ERRORS "wide character constants.c:9:27: error: character too large for enclosing character literal type" \
    "wide character constants.c:10:16: error: wide character literals may not contain multiple characters" \
    "wide character constants.c:11:16: error: Unicode character literals may not contain multiple characters" \
    "wide character constants.c:14:16: warning: multi-character character constant [-Wfour-char-constants]" \
    "wide character constants.c:20:19: error: escape sequence out of range" \
    "wide character constants.c:22:19: error: character too large for enclosing character literal type" \
    "wide character constants.c:25:19: error: invalid universal character" \
    "wide character constants.c:26:19: error: character too large for enclosing character literal type" \
    "wide character constants.c:27:19: error: Unicode character literals may not contain multiple characters" \
    "wide character constants.c:28:19: error: Unicode character literals may not contain multiple characters" \
