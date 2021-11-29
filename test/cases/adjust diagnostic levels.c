#define FOO 1
#define FOO 2

#pragma GCC diagnostic error "-Wmacro-redefined"
#define BAR 1
#define BAR 2

#pragma GCC diagnostic ignored "-Wmacro-redefined"
#define BAZ 1
#define BAZ 2

// #pragma GCC diagnostic push
// #pragma GCC diagnostic pop

#define EXPECTED_ERRORS "adjust diagnostic levels.c:2:9: warning: 'FOO' macro redefined [-Wmacro-redefined]" \
	"adjust diagnostic levels.c:6:9: error: 'BAR' macro redefined [-Wmacro-redefined]"

#define TESTS_SKIPPED 2
