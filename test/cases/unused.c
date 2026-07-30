void comparisons(void) {
    1 == 1;
    1 != 1;
    1 < 1;
}

/** manifest:
syntax
args = -Wunused

unused.c:2:7: warning: equality comparison result unused [-Wunused-comparison]
unused.c:3:7: warning: inequality comparison result unused [-Wunused-comparison]
unused.c:4:7: warning: relational comparison result unused [-Wunused-comparison]
*/
