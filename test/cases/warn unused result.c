int foo() __attribute__((warn_unused_result)) {
   return 0;
}

void bar() {
   foo();
}


#define EXPECTED_ERRORS "warn unused result.c:6:4: warning: ignoring return value of 'foo', declared with 'warn_unused_result' attribute [-Wunused-result"
