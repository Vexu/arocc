#pragma once

#define EXPECT_TYPE(EXPR, TYPE) _Static_assert(__builtin_types_compatible_p(__typeof__(EXPR), TYPE), "")
