//aro-args -fno-digraphs

void baz(void) {
    int x<:5:>;
}

#define EXPECTED_ERRORS "digraphs disabled.c:4:10: error: expected ';', found '<'"
