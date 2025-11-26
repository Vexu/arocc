#pragma once

#if defined(__has_feature) && __has_feature(bounds_attributes)
  #define __has_ptrcheck 1
#else
  #define __has_ptrcheck 0
#endif

#if __has_ptrcheck

#define __single __attribute__((__single__))

#else

#define __single

#endif
