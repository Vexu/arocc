int b;

struct Foo {
   float a: 1;
   int c: b, d: -1;
   int e: 64, f:0;
};

#define EXPECTED_ERRORS "bitfields.c:4:10: error: bit-field has non-integer type 'float'" \
    "bitfields.c:5:11: error: expression is not an integer constant expression" \
    "bitfields.c:5:14: error: bit-field has negative width (-1)" \
    "bitfields.c:6:8: error: width of bit-field exceeds width of its type" \
    "bitfields.c:6:15: error: named bit-field has zero width" \
