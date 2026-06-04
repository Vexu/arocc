int arr[];

_Static_assert(sizeof arr,"");

struct arr;
struct arr arr_1;
struct arr {
    int arr;
};

int arr[3];

_Static_assert(sizeof arr == 3 * sizeof(int),"");

/** manifest:
syntax

tentative array.c:3:16: error: invalid application of 'sizeof' to an incomplete type 'int []'
*/
