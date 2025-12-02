#define LINE __LINE__

void foo(void) {
\
    i\
nt x = __LI\
NE__;
\
\
    int y = __LINE__;

    int z = LINE;
\
\

}

#define FOO __LINE__

static int line1 = __LINE__;
#line 100 "foo.c"
static int line2 = __LINE__;
static char *file1 = __FILE__;

#include <__line__.h>

static int line5 = FOO;

# 1 "a.c" 1 3
# 2 "b.c" 1 3
# 3 "c.c" 1 3 4
# 3 "c.c" 2

/** manifest:
expand
args = -I include
*/
