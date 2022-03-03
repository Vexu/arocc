#define str(s) # s
#define xstr(s) str(s)
#define INCFILE(n) str(strcmp(
xstr(INCFILE(2)) INCFILE(2))

#define EXPECTED_ERRORS \
	"nested unterminated macro.c:4:6: error: unterminated function macro argument list" \
	"nested unterminated macro.c:3:20: note: expanded from here" \
	"nested unterminated macro.c:4:1: error: unterminated function macro argument list" \
	"nested unterminated macro.c:2:17: note: expanded from here" \
	"nested unterminated macro.c:4:18: error: unterminated function macro argument list" \
	"nested unterminated macro.c:3:20: note: expanded from here" \
	"nested unterminated macro.c:4:18: error: unterminated function macro argument list" \
	"nested unterminated macro.c:3:20: note: expanded from here" \
	"nested unterminated macro.c:4:18: warning: type specifier missing, defaults to 'int' [-Wimplicit-int]" \
	"nested unterminated macro.c:3:20: note: expanded from here" \
	"nested unterminated macro.c:4:18: error: expected ')', found '('" \
	"nested unterminated macro.c:3:30: note: expanded from here" \
	"nested unterminated macro.c:4:18: note: to match this '('" \
	"nested unterminated macro.c:3:23: note: expanded from here" \
