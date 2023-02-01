//aro-args -fnative-half-type
void foo(void) {
	__fp16 x = 1.0f;
	__fp16 y = 2.0f;
	x = x + y;
}
