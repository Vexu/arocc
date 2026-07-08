// has_extension pedantic test (c_alignas is a C11 feature, so this should
// return unsupported on C99).

#if __has_extension(c_alignas)
#error expected c_alignas to be unavailable as an extension
#endif

int main(void) {
  return 0;
}

/** manifest:
syntax
args = -pedantic-errors -std=c99
*/
