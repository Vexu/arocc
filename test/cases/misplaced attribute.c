 __attribute__ ((aligned (8))) struct S { short f[3]; };
 __attribute__ ((packed)) union U { int x; };
 __attribute__ ((aligned)) enum E { e };

#define EXPECTED_ERRORS \
    "misplaced attribute.c:1:18: warning: attribute 'aligned' is ignored, place it after \"struct\" to apply attribute to type declaration [-Wignored-attributes]" \
    "misplaced attribute.c:2:18: warning: attribute 'packed' is ignored, place it after \"union\" to apply attribute to type declaration [-Wignored-attributes]" \
    "misplaced attribute.c:3:18: warning: attribute 'aligned' is ignored, place it after \"enum\" to apply attribute to type declaration [-Wignored-attributes]" \
