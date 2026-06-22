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

/** manifest:
syntax

invalid attributes.c:2:30: error: call to undeclared function 'x'; ISO C99 and later do not support implicit function declarations [-Wimplicit-function-declaration]
invalid attributes.c:2:32: error: expected expression
invalid attributes.c:7:30: error: expected expression
*/
