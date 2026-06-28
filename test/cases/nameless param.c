int xyz(float);

void foo(int) {
    return;
}

void bar(float, char) {
    return;
}

/** manifest:
syntax

nameless param.c:3:10: warning: omitting the parameter name in a function definition is a C23 extension [-Wc23-extensions]
nameless param.c:7:10: warning: omitting the parameter name in a function definition is a C23 extension [-Wc23-extensions]
nameless param.c:7:17: warning: omitting the parameter name in a function definition is a C23 extension [-Wc23-extensions]
*/
