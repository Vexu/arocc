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

#define EXPECTED_ERRORS "transparent_union.c:4:18: warning: 'transparent_union' attribute only applies to unions [-Wignored-attributes]" \
    "transparent_union.c:6:18: warning: transparent union definition must contain at least one field; transparent_union attribute ignored [-Wignored-attributes]" \
    "transparent_union.c:9:12: warning: size of field 'b' (64 bits) does not match the size of the first field in transparent union; transparent_union attribute ignored [-Wignored-attributes]" \
    "transparent_union.c:8:9: note: size of first field is 32" \
