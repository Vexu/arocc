//aro-args --target=x86_64-linux-gnu -funsigned-char

_Static_assert(__CHAR_UNSIGNED__ == 1, "");
_Static_assert((char)-1 == 0xFF, "char should be unsigned");
