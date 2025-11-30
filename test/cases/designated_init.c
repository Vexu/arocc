union U {
    int a;
    float b;
} __attribute__((designated_init));
struct S {
    int a;
    float b;
} __attribute__((designated_init)) a = { 1 };

/** manifest:
syntax

designated_init.c:4:18: error: 'designated_init' attribute is only valid on 'struct' type'
designated_init.c:8:42: warning: positional initialization of field in 'struct' declared with 'designated_init' attribute [-Wdesignated-init]
*/
