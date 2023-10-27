//aro-args -E -P -CC
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

#define EXPECTED_ERRORS \
    "preserve comments in macros.c:2:15: error: pasting formed '/*foo*//*bar*/', an invalid preprocessing token" \
    "preserve comments in macros.c:5:13: error: pasting formed '/*foo*//*bar*/', an invalid preprocessing token" \
    "preserve comments in macros.c:14:14: error: pasting formed '/*foo*/1', an invalid preprocessing token" \
    "preserve comments in macros.c:16:8: note: expanded from here" \
