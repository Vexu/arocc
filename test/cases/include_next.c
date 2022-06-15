//aro-args -Wgnu-include-next
#include <my_include.h> // test/cases/include/my_include.h
#include_next <stdalign.h>
_Static_assert(FOO == 1, "Did not include correct file");
_Static_assert(BAR == 2, "Did not include_next correct file");

#define EXPECTED_ERRORS \
	"my_include.h:3:2: warning: #include_next is a language extension [-Wgnu-include-next]" \
	"include_next.c:3:2: warning: #include_next is a language extension [-Wgnu-include-next]" \
	"include_next.c:3:2: warning: #include_next in primary source file; will search from start of include path [-Winclude-next-outside-header]" \
