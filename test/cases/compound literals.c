struct A {
    int x;
};
struct B {
    struct A a;
    int y;
};

int *p = (int []){2, 4};

void foo(struct A *a) {
    (void)a;
}
void bar(void) {
    int a = (struct B){
        .y = 1,
        .a = {.x = 2},
    }.a.x;
    int b = (int []){1,2,3,4,5}[4];
    int c = (int []){1,2,3,4,5}[10];
    foo(&(struct A){.x = 42});

    char *str1 = "string 1";
    char *str2 = (char []){"string 2"};
    const char *str3 = (const char []){"string 3"};
}

#define EXPECTED_ERRORS "compound literals.c:20:32: warning: array index 10 is past the end of the array [-Warray-bounds]" \

