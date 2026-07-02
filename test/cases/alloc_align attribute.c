__attribute__((alloc_align(0))) int* foo1(int x, double y);
__attribute__((alloc_align(1))) int* foo2(int x, double y);
__attribute__((alloc_align(2))) int* foo3(int x, double y);
__attribute__((alloc_align(3))) int* foo4(int x, double y);
__attribute__((alloc_align(1))) int foo5(int x, double y);

/** manifest:
syntax
skip = TODO: implement 'alloc_align' attribute

alloc_align attribute.c:1:16: warning: TODO: implement 'alloc_align' attribute
alloc_align attribute.c:2:16: warning: TODO: implement 'alloc_align' attribute
alloc_align attribute.c:3:16: warning: TODO: implement 'alloc_align' attribute
alloc_align attribute.c:4:16: warning: TODO: implement 'alloc_align' attribute
alloc_align attribute.c:5:16: warning: TODO: implement 'alloc_align' attribute
*/
