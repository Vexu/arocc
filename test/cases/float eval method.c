void foo(void) {
	float a = 1.0f, b = 2.0f;
	float c = a + b;
	_Complex float ca = 0.0f;
	ca = ca + a;
}

/** manifest:
syntax
args = -ffp-eval-method=double --target=x86_64-linux-gnu
*/
