#if defined __has_feature
#  if __has_feature(enumerator_attributes)
      #error feature exists
#  endif
#  if __has_feature(does_not_exist)
      #error feature exists
#  endif
#endif

/** manifest:
expand_error

__has_feature.c:3:8: error: feature exists
*/
