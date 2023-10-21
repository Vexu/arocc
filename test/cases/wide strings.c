//aro-args -std=c2x
#include <stdint.h>
typedef __WCHAR_TYPE__ wchar_t;

uint8_t b[] = u8"";
_Static_assert(sizeof(b) == sizeof(uint8_t[1]));
char c[] = "";
_Static_assert(sizeof(c) == 1);
wchar_t d[] = L"";
_Static_assert(sizeof(d) == sizeof(wchar_t[1]));
uint16_t e[] = u"";
_Static_assert(sizeof(e) == sizeof(uint16_t[1]));
uint32_t f[] = U"";
_Static_assert(sizeof(f) == sizeof(uint32_t[1]));

uint16_t A[] = u"abc";
_Static_assert(sizeof(A) == 8);

uint32_t B[] = U"ABC";
_Static_assert(sizeof(B) == 16);

wchar_t C[] = L"ABC";
_Static_assert(sizeof(C) == sizeof(wchar_t) * 4);

uint16_t D[] = u"a" U"b";

uint16_t E[] = u"a" u"bc";
_Static_assert(sizeof(E) == 8);

uint32_t F[] = U"A" "BC";
_Static_assert(sizeof(F) == 16);

uint16_t G[] = u"🤗";
_Static_assert(sizeof(G) == 6);

uint16_t H[] = u"\U0001F917";
_Static_assert(sizeof(H) == 6);

uint32_t I[] = U"🤗";
_Static_assert(sizeof(I) == 8);

uint8_t J[] = u8"🤗";
_Static_assert(sizeof(J) == 5);

uint8_t K[] = u8"\U0001F917";
_Static_assert(sizeof(K) == 5);

uint16_t L[] = u"\xFFFFF";

uint8_t M[] = u8"\xFFF";

_Static_assert(1 == 2, u"😬\U0001f62c");
_Static_assert(1 == 2, U"😬\U0001f62c");

char foo[] = "\u0020\u0020\u0020\u0020\xFFFFFFFF";

wchar_t N[] = "word" L"" "a";
_Static_assert(sizeof(N) == sizeof(wchar_t) * 6);
uint32_t O[] = "word" U"" "a";
_Static_assert(sizeof(O) == sizeof(uint32_t) * 6);
uint16_t P[] = "word" u"" "a";
_Static_assert(sizeof(P) == sizeof(uint16_t) * 6);

uint32_t Q[] = U"abc\ndef\xFFghi";
_Static_assert(sizeof(Q) == sizeof(uint32_t) * 12);

uint32_t R[] = U"a" U'b';
uint32_t S[] = U'a';
uint32_t T[] = { U'a', U'b'};

#define EXPECTED_ERRORS "wide strings.c:25:21: error: unsupported string literal concatenation" \
    "wide strings.c:48:18: error: escape sequence out of range" \
    "wide strings.c:50:18: error: escape sequence out of range" \
    "wide strings.c:52:1: error: static assertion failed \"😬😬\"" \
    "wide strings.c:53:1: error: static assertion failed \"😬😬\"" \
    "wide strings.c:55:39: error: escape sequence out of range" \
    "wide strings.c:67:21: error: expected ';', found 'a character literal'" \
    "wide strings.c:68:16: error: array initializer must be an initializer list or wide string literal" \

