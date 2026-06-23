__attribute__((malloc)) int  foo(void);
__attribute__((malloc)) int *bar(void);

/** manifest:
syntax
skip = TODO: implement 'malloc' attribute

ignored attributes.c:1:16: warning: TODO: implement 'malloc' attribute
ignored attributes.c:2:16: warning: TODO: implement 'malloc' attribute
*/
