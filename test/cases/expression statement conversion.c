void foo(void) {
    const int *a;
    *a;
}

void qualified(const volatile int *a, const _Atomic(int) *b) {
    (*a);
    *b;
}

void decay(void) {
    int a[2];
    a;
    foo;
}

/** manifest:
syntax
args = --target=x86_64-linux-gnu

expression statement conversion.c:3:5: warning: expression result unused [-Wunused-value]
expression statement conversion.c:7:6: warning: expression result unused [-Wunused-value]
expression statement conversion.c:8:5: warning: expression result unused [-Wunused-value]
expression statement conversion.c:13:5: warning: expression result unused [-Wunused-value]
expression statement conversion.c:14:5: warning: expression result unused [-Wunused-value]
*/
