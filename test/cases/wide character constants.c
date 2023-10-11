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
unsigned long K = '\777';
wchar_t L = L'\777';

_Static_assert(sizeof(u8'a') == sizeof(char), "");
int M = u8'ab';
int N = u8'\xFF';
int O = u8'™';
int P = u8'\u0041';
int Q = u8'\x41';
int R = u8'\u0024';
int S = '\x';
int T = '\xg';
int U = '\8';
int V = '\	'; // tab character
_Static_assert('\(' == '(', "");
_Static_assert('\[' == '[', "");
_Static_assert('\{' == '{', "");
_Static_assert('\%' == '%', "");
int W = '\u';
int X = '\U';
#pragma GCC diagnostic warning "-Wpedantic"
int Y = 'abc\E';
#pragma GCC diagnostic pop
int Z = 'ABC\D';

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
    "wide character constants.c:29:19: error: escape sequence out of range" \
    "wide character constants.c:33:9: error: Unicode character literals may not contain multiple characters" \
    "wide character constants.c:35:9: error: character too large for enclosing character literal type" \
    "wide character constants.c:36:9: error: character 'A' cannot be specified by a universal character name" \
    "wide character constants.c:39:9: error: \\x used with no following hex digits" \
    "wide character constants.c:40:9: error: \\x used with no following hex digits" \
    "wide character constants.c:41:10: warning: unknown escape sequence '\\8' [-Wunknown-escape-sequence]" \
    "wide character constants.c:42:10: warning: unknown escape sequence '\\x09' [-Wunknown-escape-sequence]" \
    "wide character constants.c:47:9: error: \\u used with no following hex digits" \
    "wide character constants.c:48:9: error: \\U used with no following hex digits" \
    "wide character constants.c:50:13: warning: use of non-standard escape character '\\E' [-Wpedantic]" \
    "wide character constants.c:50:9: warning: multi-character character constant [-Wfour-char-constants]" \
    "wide character constants.c:52:13: warning: unknown escape sequence '\\D' [-Wunknown-escape-sequence]" \
    "wide character constants.c:52:9: warning: multi-character character constant [-Wfour-char-constants]" \

