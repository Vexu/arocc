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

/** manifest:
syntax
args = -Wvla

vla.c:2:13: warning: variable length array used [-Wvla]
vla.c:7:11: error: use of undeclared identifier 'x'
vla.c:11:19: warning: variable length array used [-Wvla]
*/
