#pragma Aro_test version c11

#pragma GCC diagnostic warning "-Wc99-compat"

#define Ǻ 42
int fǿǿ(void) {
    int Ǿ = Ǻ;
    return Ǿ;
}

int bȁr(void) {
    int ™ = 0;
    return 0;
}

int bȁz(void) {
    int a١ = 0;
    int ١a = 0;
    return 0;
}

int invis­ible = 0;
int homoglyph） = 1;

struct gǿǿd {
    int ǿk;
};

struct £ {
    int pounds;
};
struct cents {
    int ¢;
};

#define EXPECTED_ERRORS "extended identifiers c11.c:12:9: warning: using this character in an identifier is incompatible with C99" \
    "extended identifiers c11.c:22:10: warning: using this character in an identifier is incompatible with C99" \
    "extended identifiers c11.c:22:10: warning: identifier contains Unicode character <U+00AD> that is invisible in some environments" \
    "extended identifiers c11.c:23:14: warning: using this character in an identifier is incompatible with C99" \
    "extended identifiers c11.c:23:14: warning: treating Unicode character <U+FF09> as identifier character rather than as ')' symbol" \
    "extended identifiers c11.c:29:8: error: expected identifier or '{'" \
    "extended identifiers c11.c:33:9: warning: declaration does not declare anything" \
    "extended identifiers c11.c:33:9: error: expected ';', found invalid bytes" \
