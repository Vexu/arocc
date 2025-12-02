#if defined __has_extension
#  if __has_extension(c_alignas)
      #error extension exists
#  endif
#  if __has_extension(does_not_exist)
      #error extension exists
#  endif
#endif

/** manifest:
expand_error

__has_extension.c:3:8: error: extension exists
*/
