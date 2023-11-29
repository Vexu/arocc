_Static_assert(0xFFFFFFFF + 1 == 0, "'");
_Static_assert(1 + 0xFFFFFFFF == 0, "'");
_Static_assert(0 - 0x00000001 == 0xFFFFFFFF, "'");
_Static_assert(0x00000000 - 0x00000001 == 0xFFFFFFFF, "'");
_Static_assert(0x80000000 * 2 == 0, "'");
