//aro-args -Wgnu-include-next -Wno-gnu-alignof-expression
#include <my_include.h> // test/cases/include/my_include.h
#include_next <stdalign.h>
#include_next "global_var.h"
#include_next <other.h>
_Static_assert(FOO == 1, "Did not include correct file");
_Static_assert(BAR == 2, "Did not include_next correct file");
_Static_assert(alignof(multiple) == _Alignof(int), "#include_next quotes");
_Static_assert(OTHER_INCLUDED == 1, "OTHER_INCLUDED");
_Static_assert(NEXT_OTHER_INCLUDED == 1, "NEXT_OTHER_INCLUDED");

#define EXPECTED_ERRORS \
	"my_include.h:3:2: warning: #include_next is a language extension [-Wgnu-include-next]" \
	"my_include.h:4:2: warning: #include_next is a language extension [-Wgnu-include-next]" \
	"include_next.c:3:2: warning: #include_next is a language extension [-Wgnu-include-next]" \
	"include_next.c:3:2: warning: #include_next in primary source file; will search from start of include path [-Winclude-next-outside-header]" \
	"include_next.c:4:2: warning: #include_next is a language extension [-Wgnu-include-next]" \
	"include_next.c:4:2: warning: #include_next in primary source file; will search from start of include path [-Winclude-next-outside-header]" \
	"include_next.c:5:2: warning: #include_next is a language extension [-Wgnu-include-next]" \
	"include_next.c:5:2: warning: #include_next in primary source file; will search from start of include path [-Winclude-next-outside-header]" \
