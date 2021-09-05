void foo(void) {
    unsigned typeof(int) x;
    typeof(int) typeof(int) y;
    typeof() z;
    typeof(int) unsigned w;
}

#define EXPECTED_ERRORS "incorrect typeof usage.c:2:5: error: 'unsigned typeof' is invalid" \
    "incorrect typeof usage.c:3:5: error: cannot combine with previous 'typeof' specifier" \
    "incorrect typeof usage.c:4:12: error: expected expression" \
    "incorrect typeof usage.c:5:17: error: 'unsigned typeof' is invalid" \

