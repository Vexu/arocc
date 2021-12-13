#if !__has_warning("-Wextern-initializer")
#error
#endif

#if __has_warning("-Wfoo")
#error foo should not exist
#elif !__has_warning("-Wunrea" "chable-code")
#error unreachable-code should exist
#endif

#if __has_warning("foobar")
#error
#elif __has_warning(foobar)
#error
#endif

#define X __has_warning("-Wextern-initializer")
_Static_assert(X == 1, "Failed to find warning");

#define EXPECTED_ERRORS "__has_warning.c:11:19: warning: __has_warning expected option name (e.g. \"-Wundef\") [-Wmalformed-warning-check]" \
	"__has_warning.c:13:21: error: expected string literal in '__has_warning'" \
