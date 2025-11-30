#include <stddef.h>
#include <stdarg.h>

#if !defined(MSP430) or !defined(__MSP430__)
#error "Missing target macros"
#endif

_Static_assert(sizeof(int) == 2, "Wrong int size");
_Static_assert(sizeof(long double) == 8, "Wrong long double size");
_Static_assert(sizeof(char *) == 2, "Wrong pointer size");
_Static_assert((char)-1 >= 0, "char should be unsigned");
_Static_assert(sizeof(ptrdiff_t) == 2, "Wrong ptrdiff_t size");
_Static_assert(sizeof(size_t) == 2, "Wrong size_t size");
_Static_assert(sizeof(wchar_t) == 2, "Wrong wchar_t size");
_Static_assert(_Alignof(char *) == 2, "wrong pointer alignment");
_Static_assert(_Alignof(int) == 2, "wrong int alignment");
_Static_assert(_Alignof(long) == 2, "wrong long alignment");
_Static_assert(_Alignof(long long) == 2, "wrong long long alignment");
_Static_assert(_Alignof(float) == 2, "wrong float alignment");
_Static_assert(_Alignof(double) == 2, "wrong double alignment");
_Static_assert(_Alignof(long double) == 2, "wrong long double alignment");

void foo(int x, ... )
{
    va_list list;
    char *foo = list;
}

/** manifest:
syntax
args = --target=msp430-other-none
*/
