//aro-args -Wno-attribute-todo

__attribute__((nonnull)) char *p;
int a(__attribute__((nonnull)) char *p);
int b(__attribute__((nonnull())) char *p);
int c(__attribute__((nonnull(1))) char *p);
int d(__attribute__((nonnull(1,2,3,4,5,6,7))) char *p);
__attribute__((nonnull)) int e(int a, char *p);

#define TESTS_SKIPPED 1 // nonnull does not validate or apply the arguments

#define EXPECTED_ERRORS "nonnull attribute.c:3:16: warning: 'nonnull' attribute only applies to functions, methods, and parameters [-Wignored-attributes]" \

