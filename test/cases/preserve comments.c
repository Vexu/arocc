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

/** manifest:
expand_partial
args = -C
*/
