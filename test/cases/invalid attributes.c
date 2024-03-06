#define NO_ERROR_VALIDATION

struct S {
  __attribute__((__aligned__(x(long)))) long a;
  __attribute__((packed)) b;
};

struct S2 {
  __attribute__((__aligned__(char:  1))) long a;
  __attribute__((packed)) b;
};

void foo(void) {
}
