typedef int foo;
void bar(void) {
    int a = foo;
}

#define EXPECTED_ERRORS "unexpected_type_name.c:3:13: error: unexpected type name 'foo': expected expression" \

