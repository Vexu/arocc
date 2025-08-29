#if __ARO_EMULATE__ == __ARO_EMULATE_CLANG__

_Static_assert(__GNUC__ == 4, "");
_Static_assert(__GNUC_MINOR__ == 2, "");
_Static_assert(__GNUC_PATCHLEVEL__ == 1, "");

#elif __ARO_EMULATE__ == __ARO_EMULATE_GCC__

_Static_assert(__GNUC__ == 7, "");
_Static_assert(__GNUC_MINOR__ == 1, "");
_Static_assert(__GNUC_PATCHLEVEL__ == 0, "");

#elif __ARO_EMULATE__ == __ARO_EMULATE_MSVC__

#if defined(__GNUC__) || defined(__GNUC_MINOR__) || defined(__GNUC_PATCHLEVEL__)
#error "__GNUC__ macros should not be defined"
#endif

#else
#error Invalid value for __ARO_EMULATE__
#endif
