//aro-args -std=c23
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

    _Atomic int i;
    atomic_init(&i, 42);

    i = kill_dependency(i);

    atomic_thread_fence(memory_order_relaxed);
    atomic_signal_fence(memory_order_seq_cst);

    res = atomic_is_lock_free(&i);

    atomic_store(&i, 42);
    atomic_store_explicit(&i, 42, memory_order_relaxed);

    x = atomic_load(&i);
    x = atomic_load_explicit(&i, memory_order_acquire);

    x = atomic_exchange(&i, 42);
    x = atomic_exchange_explicit(&i, 42, memory_order_release);

    x = atomic_compare_exchange_strong(&i, &y, 32);
    x = atomic_compare_exchange_strong_explicit(&i, &y, 32, memory_order_acq_rel, memory_order_consume);

    x = atomic_compare_exchange_weak(&i, &y, 32);
    x = atomic_compare_exchange_weak_explicit(&i, &y, 32, memory_order_acq_rel, memory_order_consume);

    x = atomic_fetch_add(&i, 42);
    x = atomic_fetch_add_explicit(&i, 42, memory_order_relaxed);

    x = atomic_fetch_sub(&i, 42);
    x = atomic_fetch_sub_explicit(&i, 42, memory_order_relaxed);

    x = atomic_fetch_or(&i, 42);
    x = atomic_fetch_or_explicit(&i, 42, memory_order_relaxed);

    x = atomic_fetch_xor(&i, 42);
    x = atomic_fetch_xor_explicit(&i, 42, memory_order_relaxed);

    x = atomic_fetch_and(&i, 42);
    x = atomic_fetch_and_explicit(&i, 42, memory_order_relaxed);

    atomic_flag flag = ATOMIC_FLAG_INIT;
    res = atomic_flag_test_and_set(&flag);
    res = atomic_flag_test_and_set_explicit(&flag, memory_order_seq_cst);
    atomic_flag_clear(&flag);
    atomic_flag_clear_explicit(&flag, memory_order_seq_cst);
    atomic_flag_clear_explicit(&flag, memory_order_seq_cst);
}

/* subject to change */
_Static_assert(ATOMIC_CHAR8_T_LOCK_FREE == 1, "");
_Static_assert(ATOMIC_POINTER_LOCK_FREE == 1, "");


#define EXPECTED_ERRORS "atomic builtins.c:17:33: error: expected 6 argument(s) got 2" \
    "atomic builtins.c:20:31: error: expected 6 argument(s) got 2" \

