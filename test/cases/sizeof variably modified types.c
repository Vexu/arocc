void foo(int x) {
    int arr[x];
    _Static_assert(sizeof(arr) > 0, "sizeof VLA");
    int (*pointer)[x] = &arr;
    _Static_assert(sizeof(pointer) == sizeof(int *), "pointer size");
    _Static_assert(sizeof(*pointer) > 0, "sizeof variably-modified type");
}

/** manifest:
syntax

sizeof variably modified types.c:3:20: error: static assertion expression is not an integral constant expression
sizeof variably modified types.c:6:20: error: static assertion expression is not an integral constant expression
*/
