void foo(void) {
  0b11;
}

/** manifest:
syntax
args = -Wpedantic -std=c17

binary literal.c:2:3: warning: binary integer literals are a C23 extension [-Wc23-extensions]
*/
