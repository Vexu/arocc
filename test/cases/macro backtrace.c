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

#define EXPECTED_ERRORS "macro backtrace.c:12:1: error: expected external declaration" \
    "macro backtrace.c:1:11: note: expanded from here" \
    "<scratch space>:1:1: note: expanded from here" \
    "macro backtrace.c:13:1: error: expected external declaration" \
    "macro backtrace.c:2:11: note: expanded from here" \
    "macro backtrace.c:1:11: note: expanded from here" \
    "<scratch space>:2:1: note: expanded from here" \
    "macro backtrace.c:14:1: error: expected external declaration" \
    "macro backtrace.c:3:11: note: expanded from here" \
    "macro backtrace.c:2:11: note: expanded from here" \
    "macro backtrace.c:1:11: note: expanded from here" \
    "<scratch space>:3:1: note: expanded from here" \
    "macro backtrace.c:15:1: error: expected external declaration" \
    "macro backtrace.c:4:11: note: expanded from here" \
    "macro backtrace.c:3:11: note: expanded from here" \
    "macro backtrace.c:2:11: note: expanded from here" \
    "macro backtrace.c:1:11: note: expanded from here" \
    "<scratch space>:4:1: note: expanded from here" \
    "macro backtrace.c:16:1: error: expected external declaration" \
    "macro backtrace.c:5:11: note: expanded from here" \
    "macro backtrace.c:4:11: note: expanded from here" \
    "macro backtrace.c:3:11: note: expanded from here" \
    "macro backtrace.c:2:11: note: expanded from here" \
    "macro backtrace.c:1:11: note: expanded from here" \
    "<scratch space>:5:1: note: expanded from here" \
    "macro backtrace.c:17:1: error: expected external declaration" \
    "macro backtrace.c:6:11: note: expanded from here" \
    "macro backtrace.c:5:11: note: expanded from here" \
    "macro backtrace.c:4:11: note: expanded from here" \
    "note: (skipping 1 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)" \
    "macro backtrace.c:2:11: note: expanded from here" \
    "macro backtrace.c:1:11: note: expanded from here" \
    "<scratch space>:6:1: note: expanded from here" \
    "macro backtrace.c:18:1: error: expected external declaration" \
    "macro backtrace.c:7:11: note: expanded from here" \
    "macro backtrace.c:6:11: note: expanded from here" \
    "macro backtrace.c:5:11: note: expanded from here" \
    "note: (skipping 2 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)" \
    "macro backtrace.c:2:11: note: expanded from here" \
    "macro backtrace.c:1:11: note: expanded from here" \
    "<scratch space>:7:1: note: expanded from here" \
    "macro backtrace.c:19:1: error: expected external declaration" \
    "macro backtrace.c:8:11: note: expanded from here" \
    "macro backtrace.c:7:11: note: expanded from here" \
    "macro backtrace.c:6:11: note: expanded from here" \
    "note: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)" \
    "macro backtrace.c:2:11: note: expanded from here" \
    "macro backtrace.c:1:11: note: expanded from here" \
    "<scratch space>:8:1: note: expanded from here" \
    "macro backtrace.c:20:1: error: expected external declaration" \
    "macro backtrace.c:9:11: note: expanded from here" \
    "macro backtrace.c:8:11: note: expanded from here" \
    "macro backtrace.c:7:11: note: expanded from here" \
    "note: (skipping 4 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)" \
    "macro backtrace.c:2:11: note: expanded from here" \
    "macro backtrace.c:1:11: note: expanded from here" \
    "<scratch space>:9:1: note: expanded from here" \
    "macro backtrace.c:21:1: error: expected external declaration" \
    "macro backtrace.c:10:11: note: expanded from here" \
    "macro backtrace.c:9:11: note: expanded from here" \
    "macro backtrace.c:8:11: note: expanded from here" \
    "note: (skipping 5 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)" \
    "macro backtrace.c:2:11: note: expanded from here" \
    "macro backtrace.c:1:11: note: expanded from here" \
    "<scratch space>:10:1: note: expanded from here" \
    "macro backtrace.c:22:1: error: expected external declaration" \
    "macro backtrace.c:11:11: note: expanded from here" \
    "macro backtrace.c:10:11: note: expanded from here" \
    "macro backtrace.c:9:11: note: expanded from here" \
    "note: (skipping 6 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)" \
    "macro backtrace.c:2:11: note: expanded from here" \
    "macro backtrace.c:1:11: note: expanded from here" \
    "<scratch space>:11:1: note: expanded from here" \