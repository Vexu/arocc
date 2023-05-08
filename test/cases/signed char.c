//aro-args --target=aarch64-linux-gnu -fsigned-char

#if defined __CHAR_UNSIGNED__
#error char should be signed
#endif

_Static_assert((char)-1 == -1, "char should be signed");
_Static_assert((char)0xFF == -1, "char should be signed");
