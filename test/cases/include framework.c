#include <SimpleFramework/Foo.h>
_Static_assert(SIMPLE_FRAMEWORK_FOO == 123, "macro from framework not accessible");

/** manifest:
syntax
args = -iframework frameworks
*/
