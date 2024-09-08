//aro-args --target=x86_64-linux-gnu -fpic

_Static_assert(__pic__ == 1, "");
_Static_assert(__PIC__ == 1, "");
#if defined __pie__ || defined __PIE__
#error __pie__ and __PIE__ should not be defined
#endif
