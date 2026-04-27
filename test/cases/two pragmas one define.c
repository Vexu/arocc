#define TWO_PRAGMAS_IN_ONE \
  _Pragma("GCC diagnostic push") \
  _Pragma("GCC diagnostic ignored \"-Wdeprecated-declarations\"")

TWO_PRAGMAS_IN_ONE
void foo(void) {
  [[deprecated]] int x;
  x = 5;
}

#pragma GCC diagnostic pop
void bar(void) {
  [[deprecated]] int x;
  x = 5;
}


/** manifest:
syntax
args = -std=c23

two pragmas one define.c:14:3: warning: 'x' is deprecated [-Wdeprecated-declarations]
two pragmas one define.c:13:5: note: 'x' has been explicitly marked deprecated here
*/
