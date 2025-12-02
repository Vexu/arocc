void foo(void) {
	__fp16 x = 1.0f;
	__fp16 y = 2.0f;
	x = x + y;
}

/** manifest:
syntax
args = -fnative-half-type --target=x86_64-linux-gnu
*/
