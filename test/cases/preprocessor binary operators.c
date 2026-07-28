#if &x
#error "failed"
#endif

#if *x
#error "failed"
#endif

#if x &= 1
#error "failed"
#endif

#if ~0 && 0
#error "failed"
#endif

#if !1
#error "failed"
#endif

#if x++
#error "failed"
#endif

#if ++x
#error "failed"
#endif

#if x + y++
#error "failed"
#endif

#if 'c' && 0
#error "failed"
#endif

#define FOO BAR
#if FOO[0]
#error "failed"
#endif

#if )
#error "failed"
#endif

#if "not allowed"
#error "failed"
#endif

#if U"not allowed"
#endif

#define BAZ --
#if 0 BAZ
error "failed"
#endif

#if BAZ
error "failed"
#endif

#if 1 + &x
#endif

#if 1 < ABC 2
#endif

#if -9223372036854775808 / -1
#endif

#if 0 && (1 - 1U)
#endif

#if -(-9223372036854775807L -1)
#endif

#if 0 && (1 && (1 / 0))
#endif

/** manifest:
syntax

preprocessor binary operators.c:1:5: error: invalid token at start of a preprocessor expression
preprocessor binary operators.c:5:5: error: invalid token at start of a preprocessor expression
preprocessor binary operators.c:9:7: error: token is not a valid binary operator in a preprocessor subexpression
preprocessor binary operators.c:21:6: error: token is not a valid binary operator in a preprocessor subexpression
preprocessor binary operators.c:25:5: error: invalid token at start of a preprocessor expression
preprocessor binary operators.c:29:10: error: token is not a valid binary operator in a preprocessor subexpression
preprocessor binary operators.c:38:8: error: token is not a valid binary operator in a preprocessor subexpression
preprocessor binary operators.c:42:5: error: expected value in expression
preprocessor binary operators.c:46:5: error: invalid token at start of a preprocessor expression
preprocessor binary operators.c:50:5: error: invalid token at start of a preprocessor expression
preprocessor binary operators.c:54:7: error: token is not a valid binary operator in a preprocessor subexpression
preprocessor binary operators.c:53:13: note: expanded from here
preprocessor binary operators.c:58:5: error: invalid token at start of a preprocessor expression
preprocessor binary operators.c:53:13: note: expanded from here
preprocessor binary operators.c:62:9: error: invalid token at start of a preprocessor expression
preprocessor binary operators.c:65:13: error: token is not a valid binary operator in a preprocessor subexpression
preprocessor binary operators.c:68:6: warning: integer literal is too large to be represented in a signed integer type, interpreting as unsigned [-Wimplicitly-unsigned-literal]
preprocessor binary operators.c:68:26: warning: right side of operator converted from negative value to unsigned: 18446744073709551615
preprocessor binary operators.c:74:5: warning: integer overflow in preprocessor expression
*/
