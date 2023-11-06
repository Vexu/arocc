//aro-args -std=c23 -E -P
#ifdef FOO
long long
#elifdef FOO
long
#elifndef FOO
int
#endif

#define BAR
#ifdef FOO
long long
#elifdef BAR
long
#elifndef FOO
int
#endif
