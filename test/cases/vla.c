//aro-args -Wvla
void foo(int x) {
    int arr[x];
}

#define EXPECTED_ERRORS "vla.c:3:13: warning: variable length array used [-Wvla]"
