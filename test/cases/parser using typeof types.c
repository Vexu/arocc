// Test for situations where the parser behavior depends on the type, to ensure
// that typeof() is handled correctly.

void typeof_array_initializer_list(void) {
    typeof(char[3]) arr = {1,2,3};
    typeof(arr) arr2 = {1,2,3};

    static char static_arr[3] = {1,2,3};
    typeof(static_arr) static_arr2 = {1,2,3};
}

void typeof_array_string_init(void) {
    typeof(char[6]) arr = "Hello";
    typeof(arr) arr2 = "Hello";

    static char static_arr[6] = "Hello";
    typeof(static_arr) static_arr2 = "Hello";
}

void array_index_warning(void) {
    typeof(int[5]) arr;
    typeof(arr) arr2;
    static int static_arr[5];
    typeof(static_arr) static_arr2;

    (void)arr[5];
    (void)arr2[5];
    (void)static_arr2[5];
}

#define EXPECTED_ERRORS "parser using typeof types.c:26:14: warning: array index 5 is past the end of the array" \
    "parser using typeof types.c:27:15: warning: array index 5 is past the end of the array" \
    "parser using typeof types.c:28:22: warning: array index 5 is past the end of the array"
