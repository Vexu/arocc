//aro-args --target=x86_64-linux-gnu

enum Small {
	A
} __attribute__((packed));

_Static_assert(sizeof(enum Small) == 1, "Small");

enum __attribute__((packed)) StillSmall {
	B = 255
};

_Static_assert(sizeof(enum StillSmall) == 1, "StillSmall");

enum Medium {
	C = 255,
	D
} __attribute__((packed));

_Static_assert(sizeof(enum Medium) == 2, "Medium");

enum StillMedium {
	E = -32768,
	F = 32767
} __attribute__((packed));

_Static_assert(sizeof(enum StillMedium) == 2, "StillMedium");

enum Normal {
	G = -2147483648,
	H = 2147483647
};
_Static_assert(sizeof(enum Normal) == 4, "Normal");

enum Unsigned {
	I = 4294967295,
};
_Static_assert(sizeof(enum Unsigned) == 4, "Unsigned");

enum Large {
	J = -1,
	K = 4294967295
};
_Static_assert(sizeof(enum Large) == 8, "Large");

enum Huge {
	L = 18446744073709551615ULL
};
_Static_assert(sizeof(enum Huge) == 8, "Huge");

#pragma GCC diagnostic ignored "-Wenum-too-large"
enum EnumWithInits {
    Negative = -2,
    Positive = 0xFFFFFFFFFFFFFFFF,
};
