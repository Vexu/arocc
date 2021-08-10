void foo(void) {
    (void)_Generic(0);
    (void)_Generic(1,);
    (void)_Generic(2, const int: 3);
    (void)_Generic(4, default: 5, default: 6);
    (void)_Generic(7, double: 8, double: 9); // TODO duplicate type / no match
}

#define TESTS_SKIPPED 1
#define EXPECTED_ERRORS "generic.c:2:21: error: expected ',', found ')'" \
    "generic.c:3:22: error: expected a type" \
    "generic.c:4:23: warning: generic association with qualifiers cannot be matched with" \
    "generic.c:5:35: error: duplicate default generic association" \
    "generic.c:5:23: note: previous case defined here"
