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

void extra_record_inits(void) {
    struct S {int x; };
    typeof(struct S) s = { 1, 2 };
    typeof(s) s2 = { 1, 2 };

    union U { int x; };
    typeof(union U) u = { 1, 2 };
    typeof(u) u2 = { 1 , 2 };
}

void incomplete_array(void) {
    typeof(int[]) arr = {1, 2, 3};
    typeof(arr) arr2 = {1, 2, 3};
}

void voidparams(typeof(const void), ...);

void string_initializer(void) {
     typeof(char[2]) arr = "hello";
     typeof(arr) arr2 = "hello";
}

void old_style(x, y)
    typeof(void) x;
    typeof(x) y;
{
}

void do_not_coerce_extra_initializers(void) {
    typeof(int[2]) arr = {1,2,"hello"};
    typeof(arr) arr2 = {1,2,"hello"};
}

void bool_init(void) {
    struct S {int x;};
    struct S s = {1};
    typeof(_Bool) b = s;
    typeof(b) b2 = s;
}

#define EXPECTED_ERRORS "parser using typeof types.c:26:14: warning: array index 5 is past the end of the array [-Warray-bounds]" \
    "parser using typeof types.c:27:15: warning: array index 5 is past the end of the array [-Warray-bounds]" \
    "parser using typeof types.c:28:22: warning: array index 5 is past the end of the array [-Warray-bounds]" \
    "parser using typeof types.c:33:31: warning: excess elements in struct initializer [-Wexcess-initializers]" \
    "parser using typeof types.c:34:25: warning: excess elements in struct initializer [-Wexcess-initializers]" \
    "parser using typeof types.c:37:30: warning: excess elements in union initializer [-Wexcess-initializers]" \
    "parser using typeof types.c:38:26: warning: excess elements in union initializer [-Wexcess-initializers]" \
    "parser using typeof types.c:46:35: error: 'void' must be the only parameter if specified" \
    "parser using typeof types.c:46:35: error: 'void' parameter cannot be qualified" \
    "parser using typeof types.c:49:28: warning: initializer-string for char array is too long [-Wexcess-initializers]" \
    "parser using typeof types.c:50:25: warning: initializer-string for char array is too long [-Wexcess-initializers]" \
    "parser using typeof types.c:54:18: error: parameter cannot have void type" \
    "parser using typeof types.c:55:15: error: parameter cannot have void type" \
    "parser using typeof types.c:60:31: warning: excess elements in array initializer [-Wexcess-initializers]" \
    "parser using typeof types.c:61:29: warning: excess elements in array initializer [-Wexcess-initializers]" \
    "parser using typeof types.c:67:23: error: initializing 'typeof(_Bool)' from incompatible type 'struct S'" \
    "parser using typeof types.c:68:20: error: initializing 'typeof(typeof(_Bool))' from incompatible type 'struct S'" \
