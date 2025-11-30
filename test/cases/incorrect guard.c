#include "incorrect_guard.h"
#include "incorrect_guard.h"

/** manifest:
syntax
args = -I include

incorrect_guard.h:3:5: error: redefinition of 'x'
incorrect_guard.h:3:5: note: previous definition is here
*/
