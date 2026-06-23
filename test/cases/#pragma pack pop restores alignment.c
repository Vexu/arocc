#pragma pack(push, 8)
#pragma pack(pop)
struct AfterBalancedPop {
    char c;
    _Alignas(16) int x;
};
_Static_assert(_Alignof(struct AfterBalancedPop) == 16, "balanced pop must restore default alignment");

#pragma pack(push, 8)
struct UnderActivePack {
    char c;
    _Alignas(16) int x;
};
#pragma pack(pop)
_Static_assert(_Alignof(struct UnderActivePack) == 8, "active pack caps alignment");

/** manifest:
syntax
args = --emulate=clang
*/
