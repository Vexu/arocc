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

int あああ =  "あああ" * 1;

/** manifest:
syntax
args = -std=c11

extended identifiers c11.c:10:9: warning: using this character in an identifier is incompatible with C99 [-Wc99-compat]
extended identifiers c11.c:20:10: warning: using this character in an identifier is incompatible with C99 [-Wc99-compat]
extended identifiers c11.c:20:10: warning: identifier contains Unicode character <U+00AD> that is invisible in some environments [-Wunicode-homoglyph]
extended identifiers c11.c:21:14: warning: using this character in an identifier is incompatible with C99 [-Wc99-compat]
extended identifiers c11.c:21:14: warning: treating Unicode character <U+FF09> as identifier character rather than as ')' symbol [-Wunicode-homoglyph]
extended identifiers c11.c:27:8: error: unexpected character <U+00A3>
extended identifiers c11.c:27:1: warning: declaration does not declare anything [-Wmissing-declaration]
extended identifiers c11.c:31:9: error: unexpected character <U+00A2>
extended identifiers c11.c:31:10: warning: declaration does not declare anything [-Wmissing-declaration]
extended identifiers c11.c:34:18: error: invalid operands to binary expression ('char *' and 'int')
*/
