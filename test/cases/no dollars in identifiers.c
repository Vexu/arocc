#define foo$ bar
void fib() {
  int foo$;
}

/** manifest:
syntax
args = -fno-dollars-in-identifiers

no dollars in identifiers.c:1:12: warning: ISO C99 requires whitespace after the macro name [-Wc99-extensions]
no dollars in identifiers.c:3:7: error: expected identifier or '('
no dollars in identifiers.c:1:12: note: expanded from here
*/
