#include <other_mixed.h> // mixed//other_mixed.h or mixed\\other_mixed.h on windows
_Static_assert(OTHER_MIXED_INCLUDED == 1, "OTHER_MIXED_INCLUDED");
_Static_assert(NEXT_OTHER_MIXED_INCLUDED == 1, "NEXT_OTHER_MIXED_INCLUDED");

/** manifest:
syntax
args = -fms-extensions -Wgnu-include-next -Wno-gnu-alignof-expression -I include//mixed -I include

other_mixed.h:5:2: warning: #include_next is a language extension [-Wgnu-include-next]
*/
