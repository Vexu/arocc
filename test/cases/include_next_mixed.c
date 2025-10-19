//aro-args -fms-extensions -Wgnu-include-next -Wno-gnu-alignof-expression
#include <other_mixed.h> // test/cases/include/mixed//other_mixed.h or test\\cases\\include//mixed\\other_mixed.h on windows
_Static_assert(OTHER_MIXED_INCLUDED == 1, "OTHER_MIXED_INCLUDED");
_Static_assert(NEXT_OTHER_MIXED_INCLUDED == 1, "NEXT_OTHER_MIXED_INCLUDED");

#define EXPECTED_ERRORS \
	"other_mixed.h:5:2: warning: #include_next is a language extension [-Wgnu-include-next]" \
