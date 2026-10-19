typedef void *aligned_ptr __attribute__((aligned(16)));
void test(const int *i, const aligned_ptr *p, void *v) {
    __c11_atomic_load(i, 5);
    void *q = __c11_atomic_load(p, 5);
    __c11_atomic_load(v, 5);
    __c11_atomic_load(1, 5);
}

/** manifest:
syntax

c11 atomic load errors.c:3:23: error: address argument to atomic operation must be a pointer to _Atomic type ('const int *' invalid)
c11 atomic load errors.c:4:33: error: address argument to atomic operation must be a pointer to _Atomic type ('const aligned_ptr *' (aka 'void *const*') invalid)
c11 atomic load errors.c:5:23: error: address argument to atomic operation must be a pointer to _Atomic type ('void *' invalid)
c11 atomic load errors.c:6:23: error: address argument to atomic builtin must be a pointer ('int' invalid)
*/
