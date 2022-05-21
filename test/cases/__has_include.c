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

#if __has_include(<stdarg.h>)
#define FOO 1
#endif
_Static_assert(FOO == 1, "<stdarg.h> not found");

#if __has_include(<foo.h>)
#error <foo.h> should not exist
#endif

#if __has_include("include/global_var.h")
#define BAR 2
#endif
_Static_assert(BAR == 2, "\"include/global_var.h\" not found");

#if __has_include("foo.h")
#error "foo.h" should not exist
#endif

#if __has_include(<>)
#endif

#define HAS_INCLUDE(X) __has_include(X)
#define STDARG <stdarg.h>

#if HAS_INCLUDE( STDARG )
#define BAZ 3
#else
#error Stdarg not found!
#endif
_Static_assert(BAZ == 3, "__has_include macro failed");

#if __has_include("std" "arg.h")
#error "Should not have this"
#endif

#define EXPECTED_ERRORS "__has_include.c:1:5: error: Missing '(' after built-in macro '__has_include'" \
    "__has_include.c:3:5: error: Missing '(' after built-in macro '__has_include'" \
    "__has_include.c:6:5: error: expected 1 argument(s) got 0" \
    "__has_include.c:22:19: error: expected \"FILENAME\" or <FILENAME>" \
    "__has_include.c:25:27: error: expected closing '>'" \
    "__has_include.c:25:19: note: to match this '<'" \
    "__has_include.c:46:19: error: empty filename" \
    "__has_include.c:59:24: error: expected closing ')'" \
