//aro-args -std=c17

void foo(void) {
    char8_t c = 0;
}

_Static_assert (_Generic (u8"hello", char*: 1, default: 2) == 1, "Incorrect type for u8 string literal");
_Static_assert (_Generic (u8"A"[0], char:  1, default: 2) == 1, "Incorrect type for u8 string literal element");

const char cbuf1[] = u8"text";
const char cbuf2[] = { u8"text" };
const signed char scbuf1[] = u8"text";
const signed char scbuf2[] = { u8"text" };
const unsigned char ucbuf1[] = u8"text";
const unsigned char ucbuf2[] = { u8"text" };

#define EXPECTED_ERRORS "c17 char8_t.c:4:5: error: use of undeclared identifier 'char8_t'" \
