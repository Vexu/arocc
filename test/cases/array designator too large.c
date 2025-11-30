int arr1[] = { [0x800000000000000 - 1] = 0 };
int arr2[] = { [0x800000000000000 - 2] = 0 };
_Static_assert(sizeof(arr1), "");
_Static_assert(sizeof(arr2), "");

/** manifest:
syntax

array designator too large.c:1:14: error: array is too large
*/
