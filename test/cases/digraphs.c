//aro-args -DSTRINGIZE(X)=%:X

#define PASTE(X, Y) (X %:%: Y)

void baz(void) <%
    int int_arr<::> = <%1%>;
    char char_arr<::> = STRINGIZE(HELLO);
    char no_digraph[] = "<::>";

    _Static_assert(sizeof(int_arr) == sizeof(int), "wrong size");
    _Static_assert(PASTE(1,2) == 12, "bad token pasting");
    _Static_assert(sizeof(char_arr) == sizeof("HELLO"), "bad stringify");
    _Static_assert(sizeof(no_digraph) == 5, "string literals should not produce digraph tokens");
%>
