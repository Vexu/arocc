#define NO_ERROR_VALIDATION

struct S {
  __attribute__((__aligned__(x(long)))) long a;
  __attribute__((packed)) b;
};

void foo(void) {
}
