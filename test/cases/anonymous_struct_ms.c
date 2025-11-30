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
args = -fms-extensions

anonymous_struct_ms.c:9:12: warning: anonymous structs are a Microsoft extension [-Wmicrosoft-anon-tag]
anonymous_struct_ms.c:10:10: warning: anonymous structs are a Microsoft extension [-Wmicrosoft-anon-tag]
*/
