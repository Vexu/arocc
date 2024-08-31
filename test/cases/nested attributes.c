typedef int __attribute__((aligned(1))) ALIGN_1;
typedef ALIGN_1 __attribute__((unused)) UNUSED;
_Static_assert(_Alignof(UNUSED) == 1, "");

typedef int __attribute__((aligned(16))) __attribute__((aligned(1))) ALIGN_16;
_Static_assert(_Alignof(ALIGN_16) == 16, "");

typedef ALIGN_16 __attribute__((aligned(1))) LOWERED_ALIGNMENT;
_Static_assert(_Alignof(LOWERED_ALIGNMENT) == 1, "");

typedef ALIGN_1 __attribute__((aligned(16))) RAISED_ALIGNMENT;
_Static_assert(_Alignof(RAISED_ALIGNMENT) == 16, "");

__auto_type ARRAY = (__attribute__((aligned(16))) int[]) {1, 2, 3};
_Static_assert(_Alignof(__typeof__(ARRAY)) == _Alignof(int *), "");
