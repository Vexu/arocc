__attribute__((aligned)) int arr[1] = {0};
int *ptr = arr;

void foo(void) {
    _Alignas(8) char x[64];
    char *y = &(x)[0];
}
