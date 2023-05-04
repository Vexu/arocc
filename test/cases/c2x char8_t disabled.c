//aro-args -std=c2x -fno-char8_t

void foo(void) {
    char8_t c = 0;
}

#define EXPECTED_ERRORS "c2x char8_t disabled.c:4:5: error: use of undeclared identifier 'char8_t'" \

