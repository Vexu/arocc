void foo(void) {
    _Generic(0);
    _Generic(1,);
    _Generic(2, const int: 3);
    _Generic(4, default: 5, default: 6);
    (void)_Generic(7, double: 8, double: 9);
    (void)_Generic(7, int: 8, int: 9);
    _Static_assert(_Generic(7, int[2]: 8, int(int): 9, default: 1) == 1, "test failure");
    _Static_assert(_Generic(7, default: 1) == 1, "test failure");
}

#define EXPECTED_ERRORS "generic.c:2:15: error: expected ',', found ')'" \
    "generic.c:3:16: error: expected a type" \
    "generic.c:4:17: warning: generic association with qualifiers cannot be matched with [-Wgeneric-qual-type]" \
    "generic.c:5:29: error: duplicate default generic association" \
    "generic.c:5:17: note: previous case defined here" \
    "generic.c:6:34: error: type 'double' in generic association compatible with previously specified type" \
    "generic.c:6:23: note: compatible type 'double' specified here" \
    "generic.c:6:20: error: controlling expression type 'int' not compatible with any generic association type" \
    "generic.c:7:31: error: type 'int' in generic association compatible with previously specified type" \
    "generic.c:7:23: note: compatible type 'int' specified here" \
    "generic.c:8:32: warning: generic association array type cannot be matched with [-Wgeneric-qual-type]" \
    "generic.c:8:43: warning: generic association function type cannot be matched with [-Wgeneric-qual-type]" \
