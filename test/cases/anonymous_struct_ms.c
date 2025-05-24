//aro-args -fms-extensions
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

#define EXPECTED_ERRORS \
    "anonymous_struct_ms.c:10:12: warning: anonymous structs are a Microsoft extension [-Wmicrosoft-anon-tag]" \
    "anonymous_struct_ms.c:11:10: warning: anonymous structs are a Microsoft extension [-Wmicrosoft-anon-tag]" \
