void bad_index_low(int *a) __attribute__((nonnull(0)));
void bad_index_high(int *a) __attribute__((nonnull(2)));
void bad_type(int *a, int b) __attribute__((nonnull(2)));

/** manifest:
syntax

nonnull attribute errors.c:1:51: error: 'nonnull' attribute parameter 1 is out of bounds
nonnull attribute errors.c:2:52: error: 'nonnull' attribute parameter 1 is out of bounds
nonnull attribute errors.c:3:53: warning: 'nonnull' attribute only applies to pointer arguments [-Wignored-attributes]
*/
