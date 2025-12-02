#define FOO 1 /* fjfao */  /* fjfao */ 2

#define BAR + /* fjfao */  /* fjfao */ /

#define BAZ 1 /* FJDLKS */

#define QUX /**/2

#define MULTI /*
*/3

#define XSTR(s) #s
#define STR(s) XSTR(s)
STR(FOO)
STR(BAR)
STR(BAZ)
STR(1
2)
STR(QUX)
STR(MULTI)
STR(/*
*/5)
STR(/**/6)

#define x foo             bar
x

/** manifest:
expand
*/
