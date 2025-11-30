#define one a ##
#define two a ## ##
#define three ##
#define four(1)
#define five(a,... b
#define six(a 1)
#define seven(a) #b
#define eight(a) ##
#define nine(a) a ##
#define ten##

#if defined one || defined two || defined three || defined four || defined five \
     || defined six || defined seven || defined eight || defined nine || defined ten
#error failed
#endif

/** manifest:
expand_error

macro definition errors.c:1:15: error: '##' cannot appear at the end of a macro expansion
macro definition errors.c:2:18: error: '##' cannot appear at the end of a macro expansion
macro definition errors.c:3:15: error: '##' cannot appear at the start of a macro expansion
macro definition errors.c:4:14: error: invalid token in macro parameter list
macro definition errors.c:5:20: error: missing ')' in macro parameter list
macro definition errors.c:5:13: note: to match this '('
macro definition errors.c:6:15: error: expected comma in macro parameter list
macro definition errors.c:7:19: error: '#' is not followed by a macro parameter
macro definition errors.c:8:18: error: '##' cannot appear at the start of a macro expansion
macro definition errors.c:9:19: error: '##' cannot appear at the end of a macro expansion
macro definition errors.c:10:12: warning: ISO C99 requires whitespace after the macro name [-Wc99-extensions]
macro definition errors.c:10:12: error: '##' cannot appear at the start of a macro expansion
*/
