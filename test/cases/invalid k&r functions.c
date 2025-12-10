int invalid1()
int invalid2(x)

/** manifest:
syntax
args = -std=c17

invalid k&r functions.c:1:14: error: expected function body after function declaration
invalid k&r functions.c:2:5: warning: a function definition without a prototype is deprecated in all versions of C and is not supported in C23 [-Wdeprecated-non-prototype]
invalid k&r functions.c:2:14: error: parameter 'x' was not declared, defaults to 'int'; ISO C99 and later do not support implicit int [-Wimplicit-int]
invalid k&r functions.c:2:16: error: expected function body after function declaration
*/
