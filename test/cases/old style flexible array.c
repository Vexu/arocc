struct S1 {
    int a[1];
    int b[1];
};

struct S2 {
    int x;
    struct S1 s1[1];
};

void foo(struct S1 *p) {
    struct S1 s1;
    s1.a[1] = 0;
    s1.b[1] = 0;
    p->a[1] = 0;
    p->b[1] = 0;

    struct S2 s2;
    s2.s1[2].a[1] = 0;
    s2.s1[2].b[1] = 0;
}

struct S3 {
    int w;
    struct {
        int x;
        int y[1];
        int z[1];
    };
};

void bar(struct S3 *p) {
    p->y[1] = 0;
    p->z[1] = 0;
    struct S3 s3;
    s3.y[1] = 0;
    s3.z[1] = 0;
}

#define EXPECTED_ERRORS "old style flexible array.c:13:9: warning: array index 1 is past the end of the array [-Warray-bounds]" \
    "old style flexible array.c:15:9: warning: array index 1 is past the end of the array [-Warray-bounds]" \
    "old style flexible array.c:19:15: warning: array index 1 is past the end of the array [-Warray-bounds]" \
    "old style flexible array.c:33:9: warning: array index 1 is past the end of the array [-Warray-bounds]" \
    "old style flexible array.c:36:9: warning: array index 1 is past the end of the array [-Warray-bounds]" \

