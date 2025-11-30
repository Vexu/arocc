__attribute__((alloc_align(0))) int* foo1(int x, double y);
__attribute__((alloc_align(1))) int* foo2(int x, double y);
__attribute__((alloc_align(2))) int* foo3(int x, double y);
__attribute__((alloc_align(3))) int* foo4(int x, double y);
__attribute__((alloc_align(1))) int foo5(int x, double y);

/** manifest:
syntax

alloc_align attribute.c:1:16: error: 'alloc_align' attribute parameter 1 is out of bounds
alloc_align attribute.c:3:16: error: 'alloc_align' attribute argument may only refer to a function parameter of integer type
alloc_align attribute.c:4:16: error: 'alloc_align' attribute parameter 1 is out of bounds
alloc_align attribute.c:5:16: warning: 'alloc_align' attribute only applies to return values that are pointers [-Wignored-attributes]
*/
