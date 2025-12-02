int foo(void) {
    char c[] = "hello";
    return strlen(c);
}

void bar(int x) {
    __builtin_ppc_trap(x);
}

void ns_constant_string(void) {
    const __NSConstantString *ns_str = __builtin___NSStringMakeConstantString("Hello, world!");
    (void)ns_str;
}

/** manifest:
syntax
args = --target=powerpc-freestanding-none

builtin functions.c:3:12: error: implicitly declaring library function 'strlen' [-Wimplicit-function-declaration]
builtin functions.c:3:12: note: include the header <string.h> or explicitly provide a declaration for 'strlen'
*/
