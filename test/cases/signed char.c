//aro-args --target=aarch64-linux-gnu -fsigned-char -Wno-integer-overflow

#if defined __CHAR_UNSIGNED__
#error char should be signed
#endif

_Static_assert((char)-1 == -1, "char should be signed");
_Static_assert((char)0xFF == -1, "char should be signed");

#if '\0' - 1 > 0
#error "preprocessor char literal is unsigned when it should be signed"
#endif

#if u'\0' - 1 < 0
#error "preprocessor u8 char literal is signed when it should be unsigned"
#endif
