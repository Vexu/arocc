int foo(int foo[2]) {
    int arr[4];
    arr[-4] = 4[arr];
    1[1] = 2;
    arr[arr] = 2;
    return foo[2];
}

/** manifest:
syntax

subscript.c:3:8: warning: array index -4 is before the beginning of the array [-Warray-bounds]
subscript.c:3:16: warning: array index 4 is past the end of the array [-Warray-bounds]
subscript.c:4:6: error: subscripted value is not an array, pointer or vector
subscript.c:5:8: error: array subscript is not an integer
subscript.c:6:15: warning: array index 2 is past the end of the array [-Warray-bounds]
*/
