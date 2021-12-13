int xyz(float);

void foo(int) {
    return;
}

void bar(float, char) {
    return;
}

#define EXPECTED_ERRORS "nameless param.c:3:13: warning: omitting the parameter name in a function definition is a C2x extension [-Wc2x-extensions]" \
    "nameless param.c:7:15: warning: omitting the parameter name in a function definition is a C2x extension [-Wc2x-extensions]" \
    "nameless param.c:7:21: warning: omitting the parameter name in a function definition is a C2x extension [-Wc2x-extensions]" \
