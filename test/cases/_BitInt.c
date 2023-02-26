//aro-args -std=c17 -Wpedantic

_BitInt(17) a;

#pragma GCC diagnostic ignored "-Wpedantic"

unsigned _BitInt(70) b;
signed _BitInt(99) c;

_Static_assert(sizeof(_BitInt(65)) == sizeof(_BitInt(66)), "failed");
_Static_assert(sizeof(_BitInt(8)) != sizeof(_BitInt(66)), "failed");

// TODO shouldn't be needed
#pragma GCC diagnostic ignored "-Wimplicit-int"

_BitInt(129) f;
signed _BitInt(1) e;
unsigned _BitInt(0) d;

_BitInt(5) g = 2wb;
unsigned _BitInt(5) h = 3Uwb;
#pragma GCC diagnostic ignored "-Wc2x-extensions"
int x = 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFwb;
int y = 0wb;
int z = 0uwb;

#define EXPECTED_ERRORS "_BitInt.c:3:1: warning: '_BitInt' in C17 and earlier is a Clang extension' [-Wbit-int-extension]" \
    "_BitInt.c:16:1: error: _BitInt of bit sizes greater than 128 not supported" \
    "_BitInt.c:17:8: error: signed _BitInt must have a bit size of at least 2" \
    "_BitInt.c:18:10: error: unsigned _BitInt must have a bit size of at least 1" \
    "_BitInt.c:20:16: warning: '_BitInt' suffix for literals is a C2x extension [-Wc2x-extensions]" \
    "_BitInt.c:21:25: warning: '_BitInt' suffix for literals is a C2x extension [-Wc2x-extensions]" \
    "_BitInt.c:23:9: error: _BitInt of bit sizes greater than 128 not supported" \

