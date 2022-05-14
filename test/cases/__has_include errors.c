int __has_include = 42;

#if __has_include
#endif

#if __has_include()
#endif

#if !defined(__has_include)
    #error __has_include should be defined
#endif

#ifndef __has_include
    #error __has_include should be defined
#endif

#ifdef __has_include
#else
    #error __has_include should be defined
#endif

#if __has_include(foobar)
#endif

#if __has_include(<foobar)
#endif

#define EXPECTED_ERRORS "__has_include errors.c:1:5: error: '__has_include' must be used within a preprocessing directive" \
    "__has_include errors.c:3:18: error: missing '(' after '__has_include'" \
    "__has_include errors.c:6:19: error: expected \"FILENAME\" or <FILENAME>" \
    "__has_include errors.c:22:19: error: expected \"FILENAME\" or <FILENAME>" \
    "__has_include errors.c:22:25: error: extra tokens at end of macro directive" \
    "__has_include errors.c:25:27: error: expected closing '>'" \
    "__has_include errors.c:25:19: note: to match this '<'" \
    "__has_include errors.c:25:19: error: expected \"FILENAME\" or <FILENAME>" \
