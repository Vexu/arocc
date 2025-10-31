//aro-args --target=x86_64-linux-gnu
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

#define EXPECTED_ERRORS "expand #pragma args.c:4:14: warning: value of #pragma pack(show) == 8" \
	"expand #pragma args.c:6:14: warning: value of #pragma pack(show) == 16" \
	"expand #pragma args.c:8:14: warning: value of #pragma pack(show) == 8" \
	"expand #pragma args.c:13:14: warning: value of #pragma pack(show) == 16" \
	"expand #pragma args.c:15:14: warning: value of #pragma pack(show) == 8" \
	"expand #pragma args.c:22:14: warning: value of #pragma pack(show) == 16" \

