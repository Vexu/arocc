#define FOO
#ifdef FOO
long
#else
int
#endif

#define BAR
#ifdef BAZ
long
#else
int
#endif

/** manifest:
expand
*/
