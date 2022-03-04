#pragma GCC diagnostic warning "-Wgnu-empty-struct"
#pragma GCC diagnostic warning "-Wc++-compat"

struct {}s;
union {}u;

#define EXPECTED_ERRORS "empty records.c:4:1: warning: empty struct is a GNU extension [-Wgnu-empty-struct]" \
	"empty records.c:4:1: warning: empty struct has size 0 in C, size 1 in C++ [-Wc++-compat]" \
	"empty records.c:5:1: warning: empty union is a GNU extension [-Wgnu-empty-struct]" \
	"empty records.c:5:1: warning: empty union has size 0 in C, size 1 in C++ [-Wc++-compat]" \
