//aro-args --target=x86_64-linux-gnu -std=c2x

#define CAT(X, Y) XCAT(X, Y)
#define XCAT(X, Y) X ## Y

#define STR(X) XSTR(X)
#define XSTR(X) #X

_Static_assert(__INT8_MAX__ == 127);
_Static_assert(__builtin_types_compatible_p(__INT8_TYPE__, signed char));
_Static_assert(__builtin_types_compatible_p(__UINT8_TYPE__, unsigned char));
_Static_assert(sizeof(STR(__INT8_C_SUFFIX__)) == 1); // Empty string, null terminator only
_Static_assert(sizeof(STR(__UINT8_C_SUFFIX__)) == 1); // Empty string, null terminator only

_Static_assert(__INT16_MAX__ == 32767);
_Static_assert(__UINT16_MAX__ == 65535);
_Static_assert(__builtin_types_compatible_p(__INT16_TYPE__, short));
_Static_assert(__builtin_types_compatible_p(__UINT16_TYPE__, unsigned short));
_Static_assert(sizeof(STR(__INT16_C_SUFFIX__)) == 1); // Empty string, null terminator only
_Static_assert(sizeof(STR(__UINT16_C_SUFFIX__)) == 1); // Empty string, null terminator only

_Static_assert(__INT32_MAX__ == 2147483647);
_Static_assert(__UINT32_MAX__ == 4294967295U);
_Static_assert(__builtin_types_compatible_p(__INT32_TYPE__, int));
_Static_assert(__builtin_types_compatible_p(__UINT32_TYPE__, unsigned));
_Static_assert(__builtin_types_compatible_p(typeof(__INT32_MAX__), int));
_Static_assert(__builtin_types_compatible_p(typeof(__UINT32_MAX__), unsigned));
_Static_assert(__builtin_types_compatible_p(typeof(CAT(0, __INT32_C_SUFFIX__)), int));
_Static_assert(__builtin_types_compatible_p(typeof(CAT(0, __UINT32_C_SUFFIX__)), unsigned));

_Static_assert(__INT64_MAX__ == 9223372036854775807LL);
_Static_assert(__UINT64_MAX__ == 18446744073709551615ULL);
_Static_assert(__builtin_types_compatible_p(__INT64_TYPE__, long));
_Static_assert(__builtin_types_compatible_p(__UINT64_TYPE__, unsigned long));
_Static_assert(__builtin_types_compatible_p(typeof(__INT64_MAX__), long));
_Static_assert(__builtin_types_compatible_p(typeof(__UINT64_MAX__), unsigned long));
_Static_assert(__builtin_types_compatible_p(typeof(CAT(0, __INT64_C_SUFFIX__)), long));
_Static_assert(__builtin_types_compatible_p(typeof(CAT(0, __UINT64_C_SUFFIX__)), unsigned long));

_Static_assert(__INT64_MAX__ == 9223372036854775807LL);
_Static_assert(__UINT64_MAX__ == 18446744073709551615ULL);
_Static_assert(__builtin_types_compatible_p(__INT64_TYPE__, long));
_Static_assert(__builtin_types_compatible_p(__UINT64_TYPE__, unsigned long));
_Static_assert(__builtin_types_compatible_p(typeof(__INT64_MAX__), long));
_Static_assert(__builtin_types_compatible_p(typeof(__UINT64_MAX__), unsigned long));
_Static_assert(__builtin_types_compatible_p(typeof(CAT(0, __INT64_C_SUFFIX__)), long));
_Static_assert(__builtin_types_compatible_p(typeof(CAT(0, __UINT64_C_SUFFIX__)), unsigned long));
