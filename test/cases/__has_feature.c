#if defined __has_feature
#  if __has_feature(enumerator_attributes)
      #error feature exists
#  endif
#  if __has_feature(does_not_exist)
      #error feature exists
#  endif
#endif

#define EXPECTED_ERRORS "__has_feature.c:3:7: error: feature exists"
