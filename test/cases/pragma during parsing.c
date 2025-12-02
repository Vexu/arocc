void foo(void) {
    #pragma GCC diagnostic error "-Wint-conversion"
    int *x = 5;
    #pragma GCC diagnostic ignored "-Wint-conversion"
}

/** manifest:
syntax

pragma during parsing.c:3:14: error: implicit integer to pointer conversion from 'int' to 'int *' [-Werror,-Wint-conversion]
*/
