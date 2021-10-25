#pragma GCC diagnostic ignored "-Wunused-value"

void test_type_resolution(void) {
    1 - 1;
    1L;
    1UL;
    1LL;
    1ULL;
    int x = 1;
    // The next 12 examples are from the C17 standard § 6.5.16 (once with each order for branch types)
    (x ? (const void *)1 : (const int *)2);
    (x ? (const int *)1 : (const void *)2);
    (x ? (volatile int *)1 : 0);
    (x ? 0 : (volatile int *)1);
    (x ? (const int *)1 : (volatile int *)2);
    (x ? (volatile int *)1 : (const int *)2);
    (x ? (void *)1 : (const char *)2);
    (x ? (const char *)1 : (void *)2);
    (x ? (int *)1 : (const int *)2);
    (x ? (const int *)1 : (int *)2);
    (x ? (void *)1 : (int *)2);
    (x ? (int *)1 : (void *)2);

    (x ? (int *)1 : (float *)2);
    (x ? (int *)1 : (_Atomic int*)2);
}

#define EXPECTED_TYPES "int" "long" "unsigned long" "long long" "unsigned long long" "int" \
    "*const void" "*const void" \
    "*volatile int" "*volatile int" \
    "*const volatile int" "*const volatile int" \
    "*const void" "*const void" \
    "*const int" "*const int" \
    "*void" "*void" \
    "*void" \
    "*void"

#define EXPECTED_ERRORS "type_resolution.c:24:19: warning: pointer type mismatch ('int *' and 'float *')" \
    "type_resolution.c:25:19: warning: pointer type mismatch ('int *' and '_Atomic(int) *')" \
