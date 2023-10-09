//aro-args -E -P
#define str(s) # s
#define xstr(s) str(s)
#define INCFILE(n) str(strcmp(
xstr(INCFILE(2)) INCFILE(2))

#define EXPECTED_ERRORS \
	"nested unterminated macro.c:5:6: error: unterminated function macro argument list" \
	"nested unterminated macro.c:4:20: note: expanded from here" \
	"nested unterminated macro.c:5:18: error: unterminated function macro argument list" \
	"nested unterminated macro.c:4:20: note: expanded from here" \
