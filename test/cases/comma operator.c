void foo(void) {
    char a[1];
    _Static_assert(sizeof(((void)0, a)) == sizeof(char *), "");
    const int x = 0;
    __typeof__(((void) 0, x)) y = 5;
    y = 2;
}

/** manifest:
syntax
args = -Wno-sizeof-array-argument
*/
