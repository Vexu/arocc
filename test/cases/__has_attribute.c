#if defined __has_attribute
#  if __has_attribute(aligned)
      #error attribute exists
#  endif
#  if __has_attribute(does_not_exist)
      #error attribute exists
#  endif
#endif

#define EXPECTED_ERRORS "__has_attribute.c:3:7: error: attribute exists"
