int x = _Generic(5,
	int: 42,
	double: 32.5
);

int y = _Generic(5,
	int: 42,
	double: 32.5,
	default: "string"
);

double z = _Generic(5,
	default: 32
);

/** manifest:
syntax
args = --target=x86_64-linux-gnu
*/
