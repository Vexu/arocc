//aro-args -std=c2x

void foo(void) {
    char8_t c = 0;
}

_Static_assert(_Generic(u8"hello", unsigned char*: 1, default: 2) == 1, "Incorrect type for u8 string literal");
_Static_assert(_Generic(u8"A"[0], unsigned char:  1, default: 2) == 1, "Incorrect type for u8 string literal element");

const char cbuf1[] = u8"text";
const char cbuf2[] = { u8"text" };
const signed char scbuf1[] = u8"text";
const signed char scbuf2[] = { u8"text" };
const unsigned char ucbuf1[] = u8"text";
const unsigned char ucbuf2[] = { u8"text" };
const char8_t c8buf1[] = u8"text";
const char8_t c8buf2[] = { u8"text" };
const char8_t c8buf3[] = "text";
const char8_t c8buf4[] = { "text" };
