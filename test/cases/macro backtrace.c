#define a 1 ## 2
#define b a
#define c b
#define d c
#define e d
#define f e
#define g f
#define h g
#define i h
#define j i
#define k j
a
b
c
d
e
f
g
h
i
j
k

/** manifest:
syntax

macro backtrace.c:12:1: error: expected external declaration
macro backtrace.c:1:11: note: expanded from here
<scratch space>:1:1: note: expanded from here
*/
