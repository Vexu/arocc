#include <stdatomic.h>

void *load_ptr(const void *obj) {
    return atomic_load((const _Atomic(void *) *)obj);
}

void *load_ptr_global(_Atomic(void *) *obj) {
    return atomic_load(obj);
}

/** manifest:
syntax
args = -std=c23
*/
