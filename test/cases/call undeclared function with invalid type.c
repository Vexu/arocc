struct S {
    does_not_exist x;
};

void foo(void) {
    struct S s = {0};
    bar(s.x);
}

/** manifest:
syntax

call undeclared function with invalid type.c:2:5: error: unknown type name 'does_not_exist'
call undeclared function with invalid type.c:7:5: error: call to undeclared function 'bar'; ISO C99 and later do not support implicit function declarations [-Wimplicit-function-declaration]
*/
