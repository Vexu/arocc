#define ASM_SIZE(inst, ...)   ASM_SEL(inst##l##__VA_ARGS__, \
                                          inst##q##__VA_ARGS__)

ASM_SIZE(bts)

/** manifest:
expand
args = -pedantic

empty variadic paste.c:1:48: warning: passing no argument for the '...' parameter of a variadic macro is incompatible with C standards before C23 [-Wvariadic-macro-arguments-omitted]
empty variadic paste.c:2:52: warning: passing no argument for the '...' parameter of a variadic macro is incompatible with C standards before C23 [-Wvariadic-macro-arguments-omitted]
*/
