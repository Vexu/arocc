#pragma pack()
#pragma pack(show)
#pragma pack(4u)
#pragma pack(show)
#pragma pack(push, r1, 16ll)
#pragma pack(show)
#pragma pack(pop, r1, 2)
#pragma pack(show)

#pragma pack(push, foo, 16)
#pragma pack(show)
#pragma pack(push, bar, 4)
#pragma pack(push, foo, 4)
#pragma pack(show)
#pragma pack()
#pragma pack(show)

#pragma pack(pop, bar)
#pragma pack(show)
#pragma pack(pop, foo)
#pragma pack(show)
#pragma pack(pop, foo)
#pragma pack(show)
#pragma pack(pop, foo)
#pragma pack(show)


#pragma pack
#pragma pack(foo)
#pragma pack(3)
#pragma pack(push, +)
#pragma pack(push, pop)

/** manifest:
syntax

pack.c:2:14: warning: value of #pragma pack(show) == 8
pack.c:4:14: warning: value of #pragma pack(show) == 4
pack.c:6:14: warning: value of #pragma pack(show) == 16
pack.c:7:14: warning: specifying both a name and alignment to 'pop' is undefined
pack.c:8:14: warning: value of #pragma pack(show) == 2
pack.c:11:14: warning: value of #pragma pack(show) == 16
pack.c:14:14: warning: value of #pragma pack(show) == 4
pack.c:16:14: warning: value of #pragma pack(show) == 8
pack.c:19:14: warning: value of #pragma pack(show) == 16
pack.c:21:14: warning: value of #pragma pack(show) == 2
pack.c:22:14: warning: #pragma pack(pop, ...) failed: stack empty [-Wignored-pragmas]
pack.c:23:14: warning: value of #pragma pack(show) == 2
pack.c:24:14: warning: #pragma pack(pop, ...) failed: stack empty [-Wignored-pragmas]
pack.c:25:14: warning: value of #pragma pack(show) == 2
pack.c:29:13: warning: missing '(' after '#pragma pack' - ignoring [-Wignored-pragmas]
pack.c:29:14: warning: unknown action for '#pragma pack' - ignoring [-Wignored-pragmas]
pack.c:30:14: warning: expected #pragma pack parameter to be '1', '2', '4', '8', or '16' [-Wignored-pragmas]
pack.c:31:20: warning: expected integer or identifier in '#pragma pack' - ignored [-Wignored-pragmas]
*/
