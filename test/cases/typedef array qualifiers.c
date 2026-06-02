typedef float Pixel_FFFF[4];
const Pixel_FFFF table[256];
volatile Pixel_FFFF other_table[2];

void invalid(int a[3][const 4]);

/** manifest:
syntax

typedef array qualifiers.c:5:19: error: type qualifier used in non-outermost array type
*/
