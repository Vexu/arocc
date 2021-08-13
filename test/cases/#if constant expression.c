#define EXPECTED_TOKENS long


#if defined FOO & !defined(BAZ)
void
#elif !defined(BAR)
long
#endif

#if 1 - 1
#error "foo"
#endif
