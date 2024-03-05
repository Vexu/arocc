#define NO_ERROR_VALIDATION

void foo(void) {
    char arr[10];
    typeof(const int) *p = arr;
}
