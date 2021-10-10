// this test doesn't currently work due to the fact that the preprocessor
// completely removes the spaces between tokens
// see the commented lines

#define str(s) # s
#define xstr(s) str(s)
#define debug(s, t) printf("x" # s "= %d, x" # t "= %s", \
                    x ## s, x ## t)
#define INCFILE(n) vers ## n
#define glue(a, b) a ## b
#define xglue(a, b) glue(a, b)
#define HIGHLOW "hello"
#define LOW LOW ", world"
debug(1, 2);
//fputs(str(strncmp("abc\0d", "abc", '\4') // this goes away
//    == 0) str(: @\n), s);
xstr(INCFILE(2).h)
//xstr(INCFILE(2) . h)
str(INCFILE(2).h)
//str(INCFILE(2) . h)
glue(HIGH, LOW);
xglue(HIGH, LOW)

//#define EXPECTED_TOKENS printf("x" "1" "= %d, x" "2" "= %s", x1, x2); \
//                        fputs("strncmp(\"abc\\0d\", \"abc\", '\\4') == 0" \
//                        ": @\n", s); \
//                        "vers2.h" \
//                        "vers2 . h" \
//                        "INCFILE(2).h" \
//                        "INCFILE(2) . h" \
//                        "hello"; \
//                        "hello" ", world"
#define EXPECTED_TOKENS printf("x" "1" "= %d, x" "2" "= %s", x1, x2); \
                        "vers2.h" \
                        "INCFILE(2).h" \
                        "hello"; \
                        "hello" ", world"
