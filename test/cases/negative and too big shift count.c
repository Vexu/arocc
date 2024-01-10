void foo(void) {
  int a = 0b11 << -32;
  int b = 0b11 << 32;
}

#define EXPECTED_ERRORS "negative and too big shift count.c:2:16: warning: shift count is negative [-Wshift-count-negative]" \
    "negative and too big shift count.c:2:16: warning: overflow in expression; result is '2147483647' [-Winteger-overflow]" \
    "negative and too big shift count.c:3:16: warning: shift count >= width of type [-Wshift-count-overflow]" \
    "negative and too big shift count.c:3:16: warning: overflow in expression; result is '0' [-Winteger-overflow]"
