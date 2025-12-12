int arr[];

_Static_assert(sizeof arr,"");

int arr[3]; // TODO should make the warning go away

/** manifest:
syntax
skip = TODO tentative array warning not removed

tentative array.c:1:5: warning: tentative array definition assumed to have one element
tentative array.c:3:16: error: invalid application of 'sizeof' to an incomplete type 'int []'
*/
