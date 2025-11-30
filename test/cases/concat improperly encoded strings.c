/* Note: saved with iso-8859-1 encoding, do not change */
int *p = L"" "ÿ";

/** manifest:
syntax

concat improperly encoded strings.c:2:14: error: illegal character encoding in character literal
*/
