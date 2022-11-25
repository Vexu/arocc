//aro-args -std=c2x -pedantic

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

// TODO: true / false keywords
#define TESTS_SKIPPED 2

#define EXPECTED_ERRORS \
    "c23 keywords.c:9:9: warning: keyword is hidden by macro definition [-Wkeyword-macro]" \
    "c23 keywords.c:10:9: warning: keyword is hidden by macro definition [-Wkeyword-macro]" \
    "c23 keywords.c:11:9: warning: keyword is hidden by macro definition [-Wkeyword-macro]" \
    "c23 keywords.c:12:9: warning: keyword is hidden by macro definition [-Wkeyword-macro]" \
    "c23 keywords.c:13:9: warning: keyword is hidden by macro definition [-Wkeyword-macro]" \

