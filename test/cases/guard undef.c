#include "correct_guard.h"
#undef CORRECT_GUARD_H
#include "correct_guard.h"

/** manifest:
syntax
args = -I include

correct_guard.h:3:5: error: redefinition of 'x'
correct_guard.h:3:5: note: previous definition is here
*/
