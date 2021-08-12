void foo(void) {
    int arr[4];
    arr[-4] = 4[arr];
    1[1] = 2;
    arr[arr] = 2;
}

#define EXPECTED_ERRORS "subscript.c:3:8: warning: array index -4 is before the beginning of the array" \
    "subscript.c:3:16: warning: array index 4 is past the end of the array" \
    "subscript.c:4:6: error: subscripted value is not an array or pointer" \
    "subscript.c:5:8: error: array subscript is not an integer"
