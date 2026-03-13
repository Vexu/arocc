#pragma once

#define EXPECT_TYPE(EXPR, TYPE) _Static_assert(__builtin_types_compatible_p(__typeof__(EXPR), TYPE), "")

#define CAT(X, Y) XCAT(X, Y)
#define XCAT(X, Y) X ## Y

#define STR(X) XSTR(X)
#define XSTR(X) #X

/* `__builtin_types_compatible_p(typeof(V), T)` that works in MSVC */
#define VALUE_HAS_TYPE(V, T) _Generic((V), T: 1, default: 0)
