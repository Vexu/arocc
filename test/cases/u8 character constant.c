const unsigned char c = u8'A';
_Static_assert(c == 'A', "");
#pragma GCC diagnostic ignored "-Wc23-extensions"
_Static_assert(u8'\xff' == 0xFF, "");

const unsigned char c2 = u8'™';
const unsigned char c3 = u8'£'; // Unicode codepoint 0xA3
const unsigned char c4 = u8'AA';

#if u8'A'
#else
    #error Character constant should be true in preprocessor
#endif

#define EXPECTED_ERRORS \
    "u8 character constant.c:1:25: warning: UTF-8 character literal is a C23 extension [-Wc23-extensions]" \
    "u8 character constant.c:6:26: error: character too large for enclosing character literal type" \
    "u8 character constant.c:7:26: error: character too large for enclosing character literal type" \
    "u8 character constant.c:8:26: error: Unicode character literals may not contain multiple characters" \

