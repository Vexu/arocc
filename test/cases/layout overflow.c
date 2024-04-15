//aro-args -fdeclspec

struct S {
    char x[2305843009213693952ULL -1];
    char y[2305843009213693952ULL -1];
};


struct __declspec(align(268435456)) S1 {
    char one;
    char two[2];
    char eight[8];
    char four[4];
};

struct S2 {
    __attribute__((aligned(268435456))) int x;
};

union U {
    int a;
    char bytes[3333333333333333333];
};


#define EXPECTED_ERRORS "layout overflow.c:3:8: error: type 'struct S' is too large" \
    "layout overflow.c:22:15: error: array is too large" \
    "layout overflow.c:20:7: error: type 'union U' is too large" \

