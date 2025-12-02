typedef int foo;
void bar(void) {
    int a = foo;
}

/** manifest:
syntax

unexpected_type_name.c:3:13: error: unexpected type name 'foo': expected expression
*/
