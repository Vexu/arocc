void baz(void) {
    int x<:5:>;
}

/** manifest:
syntax
args = -fno-digraphs

digraphs disabled.c:2:10: error: expected ';', found '<'
*/
