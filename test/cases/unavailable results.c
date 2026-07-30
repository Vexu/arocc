void foo(void) {
    1.0f == 1.0f;
    (double)1 + 1U == 2.0;
    (_Complex float)1 + 2U;
    1U + (int *)1;
    1U + &2;
}

/** manifest:
syntax
args = -Wno-unused

unavailable results.c:6:10: error: cannot take the address of an rvalue
*/
