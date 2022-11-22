//aro-args -pedantic
#define int foo
#define include hello
#include <stdbool.h>
#define if then
#define alignof _Alignof

unsigned x; // only here to suppress -Wempty-translation-unit

#define EXPECTED_ERRORS "keyword hidden by macro.c:2:9: warning: keyword is hidden by macro definition [-Wkeyword-macro]" \
    "keyword hidden by macro.c:5:9: warning: keyword is hidden by macro definition [-Wkeyword-macro]" \

