typedef int (*fnptr)(int, int);


int foo() __attribute__((warn_unused_result)) {
   return 0;
}

fnptr make_fn(int a, int b) {
   return 0;
}

void bar(fnptr ptr) {
   foo();
   (foo)();
   (foo - 16)();
   (foo + 16)();
   (*****foo)();
   make_fn(1, 2)(2, 2);
}

struct S {
  int __attribute__((warn_unused_result))(*close)(void);
};

void baz(struct S *s){
    (bar(0), s->close)();
}

/** manifest:
syntax

warn unused result.c:13:4: warning: ignoring return value of 'foo', declared with 'warn_unused_result' attribute [-Wunused-result]
warn unused result.c:14:4: warning: ignoring return value of 'foo', declared with 'warn_unused_result' attribute [-Wunused-result]
warn unused result.c:17:4: warning: ignoring return value of 'foo', declared with 'warn_unused_result' attribute [-Wunused-result]
warn unused result.c:26:5: warning: ignoring return value of 'close', declared with 'warn_unused_result' attribute [-Wunused-result]
*/
