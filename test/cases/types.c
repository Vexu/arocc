int _Alignas(int) _Alignas(float) _Alignas(16) b;

const volatile int a;
__const __volatile int b;
__const__ __volatile__ int c;
int foo(int *restrict a, int *__restrict b, int *__restrict__ c);

int foo(int n, int bar[n]);
