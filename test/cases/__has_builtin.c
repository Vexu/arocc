#if defined __has_builtin
#  if __has_builtin(__builtin_va_start) && __has_builtin(__builtin_va_arg)
      #error builtin exists
#  endif
#  if __has_builtin(__builtin_foobar)
      #error builtin exists
#  endif
#endif

#if __has_builtin(__has_builtin)
#  error should not have builtin __has_builtin
#endif

#if !__has_builtin(__is_target_arch)
#  error should have builtin __is_target_arch
#endif

/** manifest:
expand_error
args = --emulate=clang

__has_builtin.c:3:8: error: builtin exists
*/
