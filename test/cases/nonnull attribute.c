void plain_nonnull(int *a, int b, char *c) __attribute__((nonnull));
void nonnull_with_args(int *a, int *b, int c) __attribute__((nonnull(2, 1)));

void caller(void) {
    plain_nonnull(0, 1, 0);
    nonnull_with_args(0, 0, 1);
}

/** manifest:
syntax

nonnull attribute.c:5:19: warning: null passed to a callee that requires a non-null argument [-Wnonnull]
nonnull attribute.c:5:25: warning: null passed to a callee that requires a non-null argument [-Wnonnull]
nonnull attribute.c:6:23: warning: null passed to a callee that requires a non-null argument [-Wnonnull]
nonnull attribute.c:6:26: warning: null passed to a callee that requires a non-null argument [-Wnonnull]
*/
