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

/** manifest:
expand_partial
args = -C
*/
