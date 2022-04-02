//aro-args -Wvla
void foo(int x) {
    int arr[x];
}

struct S {
    int x;
    int y[x];
};

void bar(int x) {
    int arr[2][3][x];
}

#define EXPECTED_ERRORS "vla.c:3:13: warning: variable length array used [-Wvla]" \
    "vla.c:8:11: error: use of undeclared identifier 'x'" \
    "vla.c:12:19: warning: variable length array used [-Wvla]" \
