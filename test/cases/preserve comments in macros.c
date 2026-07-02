#define a() 1 /*foo*/ ## /*bar*/ 2
a()

#define b 1 /*foo*/ ## /*bar*/ 2
b

#define c() 1 /*foo*/
c()

#define d 1 /*foo*/
d

#define e(p) p ## 1

e(hello/*foo*/)

#if 1 // foo
#endif /*bar*/

#if 2 /*bar*/ == 2
2
#endif

#define g(x) x
#if /*foo*/g(/*foo*/1/*bar*/)
/*foo*/g(/*foo*/1/*bar*/)
#endif


// MS EOF used to stop preprocessing before nested block comment

/** manifest:
expand_error
args = -CC -fms-extensions

preserve comments in macros.c:1:15: error: pasting formed '/*foo*//*bar*/', an invalid preprocessing token
preserve comments in macros.c:4:13: error: pasting formed '/*foo*//*bar*/', an invalid preprocessing token
preserve comments in macros.c:13:14: error: pasting formed '/*foo*/1', an invalid preprocessing token
preserve comments in macros.c:15:8: note: expanded from here
*/
