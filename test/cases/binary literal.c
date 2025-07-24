//aro-args -Wpedantic -std=c17
void foo(void) {
  0b11;
}

#define EXPECTED_ERRORS "binary literal.c:3:3: warning: binary integer literals are a C23 extension [-Wc23-extensions]"
