//aro-args -fno-dollars-in-identifiers
#define foo$ bar
void fib() {
  int foo$;
}

#define EXPECTED_ERRORS ":2:12: warning: ISO C99 requires whitespace after the macro name [-Wc99-extensions]" \
    ":4:7: error: expected identifier or '('" \
    ":2:12: note: expanded from here" \
