//aro-args -I test/cases/include/wrong -I test/cases/include/right -idirafter test/cases/include/wrong
#include <target.h>

#define EXPECTED_ERRORS "target.h:1:2: warning: wrong included [-W#warnings]"
