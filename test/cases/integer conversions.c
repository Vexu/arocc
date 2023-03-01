//aro-args --target=x86_64-linux-gnu -Wno-unused-value -Wno-c2x-extensions

void foo(void) {
    _BitInt(8) x = 0;
    x + 1;

    _BitInt(32) y = 0;
    y + 1;

    _BitInt(33) z = 0;
    z + 1;

    _Complex unsigned cx = 0;
    cx + 1L;

    _Complex int cy = 0;
    cy + 4294967296wb;
}

#define EXPECTED_TYPES "_BitInt(8)" "int" "_BitInt(32)" "int" "_BitInt(33)" "_BitInt(33)" \
	"_Complex unsigned int" "_Complex long" "_Complex int" "_Complex _BitInt(34)" \

