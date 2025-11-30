#define h(x) x(0)
#define s()
h(s)

/** manifest:
expand_error

indirect macro invocation wrong arg count.c:3:1: error: expected 0 argument(s) got 1
indirect macro invocation wrong arg count.c:1:14: note: expanded from here
indirect macro invocation wrong arg count.c:3:3: note: expanded from here
*/
