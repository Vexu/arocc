//aro-args -fno-ms-extensions
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
    "anonymous_struct_no-ms.c:10:12: warning: declaration does not declare anything [-Wmissing-declaration]" \
    "anonymous_struct_no-ms.c:11:10: warning: declaration does not declare anything [-Wmissing-declaration]" \
