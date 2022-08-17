//aro-args -Wexpansion-to-defined

#define FOO_IS_DEFINED defined(FOO)

#if FOO_IS_DEFINED
#error FOO should not be defined
#endif

#pragma GCC diagnostic ignored "-Wexpansion-to-defined"

#define FOO
#if !FOO_IS_DEFINED
#error FOO should be defined
#endif

#define DEFINED defined
#if !DEFINED(FOO)
#error FOO should be defined
#endif

#undef FOO
#if DEFINED(FOO)
#error FOO should not be defined
#endif

#define PASTED_DEFINED def ## ined

#if PASTED_DEFINED BAR
#error BAR should not be defined
#endif

#define BAR
#if !PASTED_DEFINED BAR
#error BAR should be defined
#endif

#define DEFINED_MACRO(X) defined(X)
#if DEFINED_MACRO(FOO)
#error FOO should not be defined
#endif

#define FOO
#if !DEFINED_MACRO(FOO)
#error Foo should be defined
#endif

#if defined(NOT_DEFINED)
#error NOT_DEFINED should not be defined
#elif !DEFINED ( FOO )
#error FOO should be defined
#endif

#define EXPECTED_ERRORS \
	"macro expansion to defined.c:5:5: warning: macro expansion producing 'defined' has undefined behavior [-Wexpansion-to-defined]" \
	"macro expansion to defined.c:3:24: note: expanded from here" \
	"macro expansion to defined.c:43:6: error: macro name must be an identifier" \
	"macro expansion to defined.c:37:35: note: expanded from here" \
	"macro expansion to defined.c:43:6: error: expected expression" \
	"macro expansion to defined.c:37:26: note: expanded from here"

