#define EXPECTED_TOKENS long int


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
