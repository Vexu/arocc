// our builtin macros and include searches are not advanced enough to work in the CI
#define TESTS_SKIPPED 1

#if 0
#include <stdio.h>

int main(int argc, char **argv) {
    printf("Hello, world!\n");
    return 0;
}

#define EXPECTED_ERRORS "warning: '__WORDSIZE' macro redefined" \
    "warning: '__WORDSIZE_TIME64_COMPAT32' macro redefined" \
    "warning: '__SYSCALL_WORDSIZE' macro redefined" \
    "warning: '__LDOUBLE_REDIRECTS_TO_FLOAT128_ABI' macro redefined"
#endif
