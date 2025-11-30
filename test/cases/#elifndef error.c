#ifdef FOO
#error invalid
#elifdef
#error invalid
#else
int
#endif

#define BAR
#ifdef FOO
#error invalid
#elifndef
#error invalid
#else
int
#endif

/** manifest:
expand_error
args = -std=c23

#elifndef error.c:4:9: error: macro name missing
#elifndef error.c:13:10: error: macro name missing
*/
