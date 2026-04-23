#define TWO_PRAGMAS_IN_ONE \
  _Pragma("clang diagnostic push") \
  _Pragma("clang diagnostic ignored \"-Wdeprecated-declarations\"")

TWO_PRAGMAS_IN_ONE
int do_something();

/** manifest:
expand
*/
