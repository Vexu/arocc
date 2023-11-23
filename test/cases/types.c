//aro-args --target=x86_64-linux
int _Alignas(int) _Alignas(float) _Alignas(16) a;

const volatile int b;
__const __volatile int c;
__const__ __volatile__ int d;
int foo(int *restrict a, int *__restrict b, int *__restrict__ c);

int bar(int n, int bar[n]);

typedef void baz;

_Noreturn void abort(void);

typedef int A;
typedef A B;
typedef A C;
typedef C B;

typedef int I[2];
void qux(I const a, const I b) {
    b += 1;
    a += 1;
}

enum E {
    D = (char) 2,
    E = (long) 3,
};
