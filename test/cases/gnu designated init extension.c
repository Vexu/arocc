int x[] = {[1] 2, [3] 4};
_Static_assert(sizeof(x) == sizeof(int[4]), "Incorrect array size");

/** manifest:
syntax

gnu designated init extension.c:1:16: warning: use of GNU 'missing =' extension in designator [-Wgnu-designator]
gnu designated init extension.c:1:23: warning: use of GNU 'missing =' extension in designator [-Wgnu-designator]
*/
