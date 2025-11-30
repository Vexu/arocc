#undef _CRT_PACKING
#define _CRT_PACKING 16
#pragma pack(show)
#pragma pack(push,_CRT_PACKING)
#pragma pack(show)
#pragma pack(pop)
#pragma pack(show)

#define PRAGMA_ACTION push
#define PRAGMA_AMOUNT 16
_Pragma("pack(PRAGMA_ACTION, PRAGMA_AMOUNT)");
#pragma pack(show)
#pragma pack(pop)
#pragma pack(show)


#define P(s) _Pragma(#s)
#define WHY(x, y) P(pack(x, y));

WHY(push, 16)
#pragma pack(show)
#pragma pack(pop)

/** manifest:
syntax
args = --target=x86_64-linux-gnu

expand #pragma args.c:3:14: warning: value of #pragma pack(show) == 8
expand #pragma args.c:5:14: warning: value of #pragma pack(show) == 16
expand #pragma args.c:7:14: warning: value of #pragma pack(show) == 8
expand #pragma args.c:12:14: warning: value of #pragma pack(show) == 16
expand #pragma args.c:14:14: warning: value of #pragma pack(show) == 8
expand #pragma args.c:21:14: warning: value of #pragma pack(show) == 16
*/
