struct S1{
    int a;
    double b;
} __attribute__((transparent_union));
union U1 {
} __attribute__((transparent_union));
union U2 {
    int a;
    double b;
} __attribute__((transparent_union));
union U3 {
    int a;
    float b;
} __attribute__((transparent_union));

void f1(union U3);
void f2(void) {
    f1(1);
}

union U4 {
    int *a;
    float *b;
} __attribute__((transparent_union));
void f3(union U4);
void f4(void) {
    f3(1);
    f3(0);
}

/** manifest:
syntax

transparent_union.c:4:18: warning: 'transparent_union' attribute only applies to unions [-Wignored-attributes]
transparent_union.c:6:18: warning: transparent union definition must contain at least one field; transparent_union attribute ignored [-Wignored-attributes]
transparent_union.c:9:12: warning: size of field 'b' (64 bits) does not match the size of the first field in transparent union; transparent_union attribute ignored [-Wignored-attributes]
transparent_union.c:8:9: note: size of first field is 32
transparent_union.c:27:8: error: passing 'int' to parameter of incompatible type 'union U4'
transparent_union.c:25:17: note: passing argument to parameter here
*/
