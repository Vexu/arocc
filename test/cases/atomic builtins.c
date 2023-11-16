#include <stdbool.h>
#include <stdatomic.h>

_Static_assert(memory_order_relaxed == 0, "");
_Static_assert(memory_order_consume == 1, "");
_Static_assert(memory_order_acquire == 2, "");
_Static_assert(memory_order_release == 3, "");
_Static_assert(memory_order_acq_rel == 4, "");
_Static_assert(memory_order_seq_cst == 5, "");

void foo(void) {
    int x = 0, y = 1, z = 2;
    bool res;

    res = __atomic_compare_exchange_n(&x, &y, z, false, memory_order_relaxed, memory_order_relaxed);
    __atomic_compare_exchange_n(&x, &y);

    res = __atomic_compare_exchange(&x, &y, &z, false, memory_order_relaxed, memory_order_relaxed);
    __atomic_compare_exchange(&x, &y);

    char a = 0, old;
    old = __atomic_fetch_add(&a, 1, memory_order_relaxed);
}

#define EXPECTED_ERRORS "atomic builtins.c:16:33: error: expected 6 argument(s) got 2" \
    "atomic builtins.c:19:31: error: expected 6 argument(s) got 2" \

