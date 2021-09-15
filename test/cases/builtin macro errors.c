#if __has_attribute(42)
#endif

#if __has_attribute aligned
#endif

#if __has_attribute(aligned
#endif

#define __has_attribute 42
int x = __has_attribute;

#define EXPECTED_ERRORS \
	"builtin macro errors.c:1:21: error: builtin feature check macro requires a parenthesized identifier" \
	"builtin macro errors.c:4:21: error: missing '(', after '__has_attribute'" \
	"builtin macro errors.c:7:28: error: missing ')' in macro parameter list" \
	"builtin macro errors.c:7:20: note: to match this '('" \
	"builtin macro errors.c:10:9: warning: redefining builtin macro"
