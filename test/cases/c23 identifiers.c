struct £ {
    int x;
};

void foo(void) {
    int ™ = 0;
    int ǅ = 0;
    int ʶ = 0;
    int Ⅸ = 9;
    int ڴ = 0;
    int ‿ = 0;
    int a‿1 = 0;
}

int à = 1; //NFC_Quick_Check=Maybe
int à = 1; //NFC_Quick_Check=No

/** manifest:
syntax
args = -std=c2x

c23 identifiers.c:1:8: error: unexpected character <U+00A3>
c23 identifiers.c:1:1: warning: declaration does not declare anything [-Wmissing-declaration]
c23 identifiers.c:6:9: error: unexpected character <U+2122>
c23 identifiers.c:6:11: error: expected identifier or '('
c23 identifiers.c:11:9: error: unexpected character <U+203F>
c23 identifiers.c:11:11: error: expected identifier or '('
c23 identifiers.c:15:5: warning: 'a\u0300' is not in NFC [-Wnormalized]
c23 identifiers.c:16:5: warning: 'a\u0340' is not in NFC [-Wnormalized]
*/
