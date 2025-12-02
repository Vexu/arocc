void foo(void) {
    char arr[10];
    typeof(const int) *p = arr;
}

/** manifest:
syntax

typeof pointer wrong size.c:3:28: warning: incompatible pointer types initializing 'typeof(const int) *' (aka 'const int *') from incompatible type 'char [10]' [-Wincompatible-pointer-types]
*/
