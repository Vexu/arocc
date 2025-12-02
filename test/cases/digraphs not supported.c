void baz(void) {
    int x<:5:>;
}

/** manifest:
syntax
args = -std=c89

digraphs not supported.c:2:10: error: expected ';', found '<'
*/
