register int a;
register int b __asm__("ebp");

/** manifest:
syntax
skip = TODO: implement 'asm_label' attribute

global register.c:1:15: error: register name not specified for global variable
global register.c:2:16: warning: TODO: implement 'asm_label' attribute
*/
