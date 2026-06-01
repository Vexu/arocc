void foo(__mfp8 a, __mfp8 b) {
    a + b;
    -a;
    ++a;
    a < b;
    if (a) {}
    int i = a;
    float f = a;
    __mfp8 x = 0;
    (__mfp8){0};
    a += b;
    a -= b;
    a *= b;
    a /= b;
    a %= b;
    a &= b;
    a |= b;
    a ^= b;
    a <<= 1;
    a >>= 1;
    (int)a;
    (float)a;
    (__mfp8)0;
    (__mfp8)1.0f;
    const __mfp8 c = a;
    c = b;
    while (a) {}
    for (; a;) {}
    do {} while (a);
    a && b;
    a || b;
    !a;
    switch (a) {}
    __mfp8 bad_arr[2] = { 0 };
    struct bad_holder {
        __mfp8 value;
    } bad_holder = { 0 };
    __auto_type auto_int = 0;
    __auto_type auto_mfp8 = a;
    auto c23_auto_int = 0;
    auto c23_auto_mfp8 = a;
    auto_mfp8 = auto_int;
    c23_auto_mfp8 = c23_auto_int;
    void take_mfp8(__mfp8);
    void take_int(int);
    take_mfp8(0);
    take_mfp8(1.0f);
    take_int(a);
    _Complex __mfp8 complex_mfp8;
}


/** manifest:
syntax
args = -std=c23 --target=aarch64-linux-gnu

__mfp8 invalid.c:2:7: error: invalid operands to binary expression ('__mfp8' and '__mfp8')
__mfp8 invalid.c:3:5: error: invalid argument type '__mfp8' to unary expression
__mfp8 invalid.c:4:5: error: invalid argument type '__mfp8' to unary expression
__mfp8 invalid.c:5:7: error: invalid operands to binary expression ('__mfp8' and '__mfp8')
__mfp8 invalid.c:6:9: error: statement requires expression with scalar type ('__mfp8' invalid)
__mfp8 invalid.c:7:13: error: initializing 'int' from incompatible type '__mfp8'
__mfp8 invalid.c:8:15: error: initializing 'float' from incompatible type '__mfp8'
__mfp8 invalid.c:9:16: error: initializing '__mfp8' from incompatible type 'int'
__mfp8 invalid.c:10:14: error: initializing '__mfp8' from incompatible type 'int'
__mfp8 invalid.c:11:7: error: invalid operands to binary expression ('__mfp8' and '__mfp8')
__mfp8 invalid.c:12:7: error: invalid operands to binary expression ('__mfp8' and '__mfp8')
__mfp8 invalid.c:13:7: error: invalid operands to binary expression ('__mfp8' and '__mfp8')
__mfp8 invalid.c:14:7: error: invalid operands to binary expression ('__mfp8' and '__mfp8')
__mfp8 invalid.c:15:7: error: invalid operands to binary expression ('__mfp8' and '__mfp8')
__mfp8 invalid.c:16:7: error: invalid operands to binary expression ('__mfp8' and '__mfp8')
__mfp8 invalid.c:17:7: error: invalid operands to binary expression ('__mfp8' and '__mfp8')
__mfp8 invalid.c:18:7: error: invalid operands to binary expression ('__mfp8' and '__mfp8')
__mfp8 invalid.c:19:7: error: invalid operands to binary expression ('__mfp8' and 'int')
__mfp8 invalid.c:20:7: error: invalid operands to binary expression ('__mfp8' and 'int')
__mfp8 invalid.c:21:10: error: operand of type '__mfp8' where arithmetic or pointer type is required
__mfp8 invalid.c:22:12: error: operand of type '__mfp8' where arithmetic or pointer type is required
__mfp8 invalid.c:23:5: error: cannot cast to non arithmetic or pointer type '__mfp8'
__mfp8 invalid.c:24:5: error: cannot cast to non arithmetic or pointer type '__mfp8'
__mfp8 invalid.c:26:7: error: cannot assign to variable 'c' with const-qualified type 'const __mfp8'
__mfp8 invalid.c:25:18: note: variable 'c' declared const here
__mfp8 invalid.c:27:12: error: statement requires expression with scalar type ('__mfp8' invalid)
__mfp8 invalid.c:28:10: error: statement requires expression with scalar type ('__mfp8' invalid)
__mfp8 invalid.c:29:18: error: statement requires expression with scalar type ('__mfp8' invalid)
__mfp8 invalid.c:30:7: error: invalid operands to binary expression ('__mfp8' and '__mfp8')
__mfp8 invalid.c:31:7: error: invalid operands to binary expression ('__mfp8' and '__mfp8')
__mfp8 invalid.c:32:5: error: invalid argument type '__mfp8' to unary expression
__mfp8 invalid.c:33:13: error: statement requires expression with integer type ('__mfp8' invalid)
__mfp8 invalid.c:34:27: error: initializing '__mfp8' from incompatible type 'int'
__mfp8 invalid.c:37:22: error: initializing '__mfp8' from incompatible type 'int'
__mfp8 invalid.c:42:15: error: assignment to '__mfp8' from incompatible type 'int'
__mfp8 invalid.c:43:19: error: assignment to '__mfp8' from incompatible type 'int'
__mfp8 invalid.c:46:15: error: passing 'int' to parameter of incompatible type '__mfp8'
__mfp8 invalid.c:44:26: note: passing argument to parameter here
__mfp8 invalid.c:47:15: error: passing 'float' to parameter of incompatible type '__mfp8'
__mfp8 invalid.c:44:26: note: passing argument to parameter here
__mfp8 invalid.c:48:14: error: passing '__mfp8' to parameter of incompatible type 'int'
__mfp8 invalid.c:45:22: note: passing argument to parameter here
__mfp8 invalid.c:49:5: warning: plain '_Complex' requires a type specifier; assuming '_Complex double'
__mfp8 invalid.c:49:21: error: expected ';', found 'an identifier'
*/
