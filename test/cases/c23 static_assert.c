void foo(void) {
    _Static_assert(1);
}

/** manifest:
syntax
args = -std=c23
*/
