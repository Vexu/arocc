#define \U0001F525 42
_Static_assert(🔥 == 42, "");

#define FOO \u4F60 ## \u597D

#define INCOMPLETE_UCN \u4F ## 60

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

/** manifest:
syntax

ucn identifiers.c:6:24: warning: incomplete universal character name; treating as '\' followed by identifier [-Wunicode]
ucn identifiers.c:11:9: error: character 'a' cannot be specified by a universal character name
ucn identifiers.c:12:9: error: universal character name refers to a control character
ucn identifiers.c:28:7: error: invalid universal character
*/
