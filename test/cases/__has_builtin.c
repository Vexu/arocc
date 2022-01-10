#if defined __has_builtin
#  if __has_builtin(__builtin_va_start) && __has_builtin(__builtin_va_arg)
      #error builtin exists
#  endif
#  if __has_builtin(__builtin_foobar)
      #error builtin exists
#  endif
#endif

#define EXPECTED_ERRORS "__has_builtin.c:3:7: error: builtin exists"
