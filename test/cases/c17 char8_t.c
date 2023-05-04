//aro-args -std=c17

void foo(void) {
    char8_t c = 0;
}

#define EXPECTED_ERRORS "c17 char8_t.c:4:5: error: use of undeclared identifier 'char8_t'" \

