void foo(void) {
    int a = (while (1) 1);
    int b = sizeof(while (1) 1);
    int c = _Alignof(while (1) 1);
}

/** manifest:
syntax

invalid expr inside parens.c:2:14: error: expected expression
invalid expr inside parens.c:3:20: error: expected expression
invalid expr inside parens.c:4:22: error: expected expression
*/
