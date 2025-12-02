_Static_assert(__pic__ == 1, "");
_Static_assert(__PIC__ == 1, "");
_Static_assert(__pie__ == 1, "");
_Static_assert(__PIE__ == 1, "");

/** manifest:
syntax
args = --target=x86_64-linux-gnu -fpie
*/
