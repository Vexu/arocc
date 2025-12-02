#define str(s) # s
#define xstr(s) str(s)
#define INCFILE(n) str(strcmp(
xstr(INCFILE(2)) INCFILE(2))

/** manifest:
expand_error
args = --emulate=clang

nested unterminated macro clang.c:4:6: error: unterminated function macro argument list
nested unterminated macro clang.c:3:20: note: expanded from here
nested unterminated macro clang.c:4:18: error: unterminated function macro argument list
nested unterminated macro clang.c:3:20: note: expanded from here
*/
