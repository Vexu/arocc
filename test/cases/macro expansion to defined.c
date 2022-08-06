#define FOO_IS_DEFINED defined( FOO)
#define BAR_IS_DEFINED defined(BAR )

#if FOO_IS_DEFINED
#error FOO should not be defined
#endif

#pragma GCC diagnostic ignored "-Wexpansion-to-defined"

#define FOO
#if !FOO_IS_DEFINED
#error FOO should be defined
#endif

#undef FOO
#if FOO_IS_DEFINED
#error FOO should not be defined
#endif

#define FOO 0
#define BAR

#if !FOO_IS_DEFINED || !BAR_IS_DEFINED
#error FOO and BAR should be defined
#endif

#define TOO_MANY_TOKENS defined(A B)
#define NOT_ENOUGH_TOKENS defined( )

#if TOO_MANY_TOKENS
#endif

#if NOT_ENOUGH_TOKENS
#endif

#define EXPECTED_ERRORS "macro expansion to defined.c:4:5: warning: macro expansion producing 'defined' has undefined behavior [-Wexpansion-to-defined]" \
	"macro expansion to defined.c:1:24: note: expanded from here" \
	"macro expansion to defined.c:30:5: error: missing ')' after 'defined'" \
	"macro expansion to defined.c:27:35: note: expanded from here" \
	"macro expansion to defined.c:33:5: error: macro name must be an identifier" \
	"macro expansion to defined.c:28:27: note: expanded from here" \

