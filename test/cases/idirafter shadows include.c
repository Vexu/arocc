#include <target.h>

/** manifest:
syntax
args = -I include/wrong -I include/right -idirafter include/wrong

target.h:1:2: warning: wrong included [-W#warnings]
*/
