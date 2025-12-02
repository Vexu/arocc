_Static_assert(__pic__ == 2, "");
_Static_assert(__PIC__ == 2, "");
_Static_assert(__pie__ == 2, "");
_Static_assert(__PIE__ == 2, "");

/** manifest:
syntax
args = --target=x86_64-linux-gnu -fPIE
*/
