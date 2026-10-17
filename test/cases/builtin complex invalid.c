void test(void *p, _Complex double z) {
    __builtin_complex(p, p);
    __builtin_complex(z, z);
}

/** manifest:
syntax

builtin complex invalid.c:2:23: error: argument type 'void *' is not a real floating point type
builtin complex invalid.c:2:26: error: argument type 'void *' is not a real floating point type
builtin complex invalid.c:3:23: error: argument type '_Complex double' is not a real floating point type
builtin complex invalid.c:3:26: error: argument type '_Complex double' is not a real floating point type
*/
