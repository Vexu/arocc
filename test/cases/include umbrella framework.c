#include <UmbrellaFramework/UmbrellaFramework.h>
_Static_assert(SUB_FRAMEWORK_FOO == 123, "macro from subframework not accessible");

/** manifest:
expand
args = -iframework frameworks
*/
