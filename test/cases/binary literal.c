//aro-args -Wpedantic
void foo() {
  0b11;
}

#define EXPECTED_ERRORS "binary literal.c:3:3: warning: binary integer literals are a GNU extension [-Wgnu-binary-literal]"
