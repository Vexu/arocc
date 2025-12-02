#define int foo
#define include hello
#include <stdbool.h>
#define if then
#define alignof _Alignof

unsigned x; // only here to suppress -Wempty-translation-unit

/** manifest:
syntax
args = -pedantic

keyword hidden by macro.c:1:9: warning: keyword is hidden by macro definition [-Wkeyword-macro]
keyword hidden by macro.c:4:9: warning: keyword is hidden by macro definition [-Wkeyword-macro]
*/
