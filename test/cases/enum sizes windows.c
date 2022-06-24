//aro-args --target=x86_64-windows-msvc

enum Small {
	A
} __attribute__((packed));

_Static_assert(sizeof(enum Small) == sizeof(int), "Small");

enum __attribute__((packed)) StillSmall {
	B = 255
};

_Static_assert(sizeof(enum StillSmall) == sizeof(int), "StillSmall");

enum Medium {
	C = 255,
	D
} __attribute__((packed));

_Static_assert(sizeof(enum Medium) == sizeof(int), "Medium");

enum StillMedium {
	E = -32768,
	F = 32767
} __attribute__((packed));

_Static_assert(sizeof(enum StillMedium) == sizeof(int), "StillMedium");

enum Normal {
	G = -2147483648,
	H = 2147483647
};
_Static_assert(sizeof(enum Normal) == sizeof(int), "Normal");

enum Unsigned {
	I = 4294967295,
};
_Static_assert(sizeof(enum Unsigned) == sizeof(int), "Unsigned");

enum Large {
	J = -1,
	K = 4294967295
};
_Static_assert(sizeof(enum Large) == sizeof(int), "Large");

enum Huge {
	L = 18446744073709551615ULL
};
_Static_assert(sizeof(enum Huge) == sizeof(int), "Huge");
