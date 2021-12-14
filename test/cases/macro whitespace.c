//aro-args -E
#define FOO 1 /* fjfao */  /* fjfao */ 2

#define BAR + /* fjfao */  /* fjfao */ /

#define BAZ 1 /* FJDLKS */

#define XSTR(s) #s
#define STR(s) XSTR(s)
STR(FOO)
STR(BAR)
STR(BAZ)
STR(1
2)

#define x foo             bar
x
