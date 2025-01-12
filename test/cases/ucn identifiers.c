#define FOO \u4F60 ## \u597D

int foo(void) {
    int FOO = 0;
    \u4F60\u597D = 5;
    int \u0061 = 0x61;
    int ABC\U00000001 = 0x01;
    return 你好;
}

struct S {
    int 你好;
    int a\u4F60\u597D;
};

int bar(int x) {
    struct S s;
    s.\u4F60\u597D = x;
    s.a\u4F60\u597D = x;
    return s.你好;
}

int \UFFFFFFFF = 42;

#define EXPECTED_ERRORS "ucn identifiers.c:6:9: error: character 'a' cannot be specified by a universal character name" \
    "ucn identifiers.c:7:12: error: universal character name refers to a control character" \
    "ucn identifiers.c:23:5: error: invalid universal character" \

