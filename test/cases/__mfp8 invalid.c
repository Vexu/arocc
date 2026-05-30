void foo(__mfp8 a, __mfp8 b) {
    a + b;
    -a;
    ++a;
    a < b;
    if (a) {}
    int i = a;
    float f = a;
    __mfp8 x = 0;
    _Complex __mfp8 complex_mfp8;
}


/** manifest:
syntax
args = --target=aarch64-linux-gnu

__mfp8 invalid.c:2:7: error: invalid operands to binary expression ('__mfp8' and '__mfp8')
__mfp8 invalid.c:3:5: error: invalid argument type '__mfp8' to unary expression
__mfp8 invalid.c:4:5: error: invalid argument type '__mfp8' to unary expression
__mfp8 invalid.c:5:7: error: invalid operands to binary expression ('__mfp8' and '__mfp8')
__mfp8 invalid.c:6:9: error: statement requires expression with scalar type ('__mfp8' invalid)
__mfp8 invalid.c:7:13: error: initializing 'int' from incompatible type '__mfp8'
__mfp8 invalid.c:8:15: error: initializing 'float' from incompatible type '__mfp8'
__mfp8 invalid.c:9:16: error: initializing '__mfp8' from incompatible type 'int'
__mfp8 invalid.c:10:14: error: cannot combine with previous '_Complex' specifier
__mfp8 invalid.c:10:14: warning: plain '_Complex' requires a type specifier; assuming '_Complex double'
*/
