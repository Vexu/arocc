void foo(void) {
    _Generic(0);
    _Generic(1,);
    _Generic(2, const int: 3);
    _Generic(4, default: 5, default: 6);
    (void)_Generic(7, double: 8, double: 9); // TODO duplicate type / no match
}

#define TESTS_SKIPPED 1
#define EXPECTED_ERRORS "generic.c:2:15: error: expected ',', found ')'" \
    "generic.c:3:16: error: expected a type" \
    "generic.c:4:17: warning: generic association with qualifiers cannot be matched with [-Wgeneric-qual-type]" \
    "generic.c:5:29: error: duplicate default generic association" \
    "generic.c:5:17: note: previous case defined here" \
