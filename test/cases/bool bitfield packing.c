#include <stdbool.h>

struct two_bools {
    _Bool a : 1;
    _Bool b : 1;
};

struct eight_bools {
    _Bool a : 1;
    _Bool b : 1;
    _Bool c : 1;
    _Bool d : 1;
    _Bool e : 1;
    _Bool f : 1;
    _Bool g : 1;
    _Bool h : 1;
};

struct nine_bools {
    _Bool a : 1;
    _Bool b : 1;
    _Bool c : 1;
    _Bool d : 1;
    _Bool e : 1;
    _Bool f : 1;
    _Bool g : 1;
    _Bool h : 1;
    _Bool i : 1;
};

_Static_assert(sizeof(struct two_bools) == 1, "two _Bool:1 bitfields should fit in 1 byte");
_Static_assert(sizeof(struct eight_bools) == 1, "eight _Bool:1 bitfields should fit in 1 byte");
_Static_assert(sizeof(struct nine_bools) == 2, "nine _Bool:1 bitfields need 2 bytes");

/** manifest:
syntax
*/
