int _Alignas(int) _Alignas(float) _Alignas(16) a;

const volatile int b;
__const __volatile int c;
__const__ __volatile__ int d;
int foo(int *restrict a, int *__restrict b, int *__restrict__ c);

int bar(int n, int bar[n]);
