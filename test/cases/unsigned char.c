//aro-args --target=x86_64-linux-gnu -funsigned-char -Wno-integer-overflow

_Static_assert(__CHAR_UNSIGNED__ == 1, "");
_Static_assert((char)-1 == 0xFF, "char should be unsigned");

#if '\0' - 1 < 0
#error "preprocessor char literal is signed when it should be unsigned"
#endif

#if u'\0' - 1 < 0
#error "preprocessor u8 char literal is signed when it should be unsigned"
#endif
