//aro-args -std=c2x -pedantic -Wundef
#include <stdbool.h>
static_assert(1 == 1);
static_assert(alignof(char) == 1);
thread_local int x;
bool b = 1;
int alignas(16) y;

#define static_assert no
#define alignof no
#define thread_local no
#define bool no
#define alignas no

typedef typeof(int) MyInt;

#if false
#error false should expand to 0
#endif

#if true
#else
#error true should expand to 1
#endif

#define FOO true
#if FOO
#else
#error true should expand to 1
#endif

#if true + 1 != 2
#error true should expand to 1 in preprocessor arithmetic
#endif

#if defined(true) || defined(false)
#error true and false should not be defined
#endif

#define EXPECTED_ERRORS \
    "c23 keywords.c:9:9: warning: keyword is hidden by macro definition [-Wkeyword-macro]" \
    "c23 keywords.c:10:9: warning: keyword is hidden by macro definition [-Wkeyword-macro]" \
    "c23 keywords.c:11:9: warning: keyword is hidden by macro definition [-Wkeyword-macro]" \
    "c23 keywords.c:12:9: warning: keyword is hidden by macro definition [-Wkeyword-macro]" \
    "c23 keywords.c:13:9: warning: keyword is hidden by macro definition [-Wkeyword-macro]" \

