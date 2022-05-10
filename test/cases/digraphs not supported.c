//aro-args -std=c89

void baz(void) {
    int x<:5:>;
}

#define EXPECTED_ERRORS "digraphs not supported.c:4:10: error: expected ';', found '<'"
