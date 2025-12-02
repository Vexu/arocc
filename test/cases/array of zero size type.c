struct {
	int:0;

} c [] = {};

_Static_assert(sizeof(c) == 0, "");

/** manifest:
syntax
*/
