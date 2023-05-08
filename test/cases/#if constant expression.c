//aro-args -E -Wno-integer-overflow

#if defined FOO & !defined(BAZ)
void
#elif !defined(BAR)
long
#endif

#if 1 - 1
#error "foo"
#endif

#if defined BAR ? 1 : 0
#error foo
#endif

#if 0 && 0
# error foo
#endif

#if 0 || 0
# error foo
#endif
#if 0U - 1 != 18446744073709551615ULL
#error incorrect unsigned subtraction in preprocessor
#endif
