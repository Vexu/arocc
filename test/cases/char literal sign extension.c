_Static_assert('\xFF' == -1, "");
_Static_assert(u8'\xFF' == 0xFF, "");

#if '\xFF' != -1
#error comparison failed
#endif

#if u8'\xFF' != 0xFF
#error comparison failed
#endif

_Static_assert('\x00\xFF' == 255, "");
_Static_assert('\xFF\xFF' == 65535, "");

/** manifest:
syntax
args = -std=c23 -fsigned-char -Wno-multichar
*/
