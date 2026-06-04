#include <UmbrellaFramework/UmbrellaFramework.h>
_Static_assert(SUB_FRAMEWORK_A_FOO == 123, "macro from subframework a not accessible");
_Static_assert(SUB_FRAMEWORK_B_FOO == 456, "macro from subframework b not accessible");

/** manifest:
expand
args = -iframework frameworks
*/
