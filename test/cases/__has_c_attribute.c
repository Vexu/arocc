//aro-args -std=c23
#if defined __has_c_attribute
#  if __has_c_attribute(fallthrough)
      #error attribute exists
#  endif
#  if __has_c_attribute(does_not_exist)
      #error attribute exists
#  endif
#endif

#define EXPECTED_ERRORS "__has_c_attribute.c:4:8: error: attribute exists"
