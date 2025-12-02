_Static_assert(__pic__ == 2, "");
_Static_assert(__PIC__ == 2, "");
#if defined __pie__ || defined __PIE__
#error __pie__ and __PIE__ should not be defined
#endif

/** manifest:
syntax
args = --target=x86_64-linux-gnu -fPIC
*/
