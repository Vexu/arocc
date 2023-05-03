const unsigned char c = u8'A';
_Static_assert(c == 'A', "");

_Static_assert(u8'\xff' == 0xFF, "");

const unsigned char c2 = u8'™';

#if u8'A'
#else
    #error Character constant should be true in preprocessor
#endif

#define EXPECTED_ERRORS "u8 character constant.c:6:26: error: character too large for enclosing character literal type" \

