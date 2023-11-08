//aro-args -std=c2x

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

#define EXPECTED_ERRORS "c23 identifiers.c:3:8: error: unexpected character <U+00A3>" \
    "c23 identifiers.c:3:1: warning: declaration does not declare anything [-Wmissing-declaration]" \
    "c23 identifiers.c:8:9: error: unexpected character <U+2122>" \
    "c23 identifiers.c:8:11: error: expected identifier or '('" \
    "c23 identifiers.c:13:9: error: unexpected character <U+203F>" \
    "c23 identifiers.c:13:11: error: expected identifier or '('" \

