#define FOO 1

#include_next <my_include.h> // include/next/my_include.h
#include_next <other.h>  // include/next/other.h 

#if __has_include_next(<foobar.h>)
#error "Should not exist"
#endif

#if __has_include_next(<my_include.h>)
#define HAS_INCLUDE_NEXT_WORKED 1
#endif

#if __has_include_next("global_var.h")
#error "Should not find this with include_next"
#endif
