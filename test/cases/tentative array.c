int arr[];

_Static_assert(sizeof arr,"");

int arr[3]; // TODO should make the error go away

#define SKIPPED_TESTS 1

#define EXPECTED_ERRORS \
    "tentative array.c:1:5: warning: tentative array definition assumed to have one element" \
    "tentative array.c:3:16: error: invalid application of 'sizeof' to an incomplete type 'int []'" \

