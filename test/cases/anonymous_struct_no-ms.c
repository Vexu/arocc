typedef struct {
    int a;
} unnamed;
typedef struct named {
    int b;
} named;

struct S {
    unnamed;
    named;
};

/** manifest:
syntax
args = -fno-ms-extensions

anonymous_struct_no-ms.c:9:12: warning: declaration does not declare anything [-Wmissing-declaration]
anonymous_struct_no-ms.c:10:10: warning: declaration does not declare anything [-Wmissing-declaration]
*/
