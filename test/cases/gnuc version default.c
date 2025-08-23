#if __ARO_EMULATE__ == 1

/* clang */
_Static_assert(__GNUC__ == 4, "");
_Static_assert(__GNUC_MINOR__ == 2, "");
_Static_assert(__GNUC_PATCHLEVEL__ == 1, "");

#elif __ARO_EMULATE__ == 2

/* gcc */
_Static_assert(__GNUC__ == 7, "");
_Static_assert(__GNUC_MINOR__ == 1, "");
_Static_assert(__GNUC_PATCHLEVEL__ == 0, "");

#elif __ARO_EMULATE__ == 3

/* msvc */
#if defined(__GNUC__) || defined(__GNUC_MINOR__) || defined(__GNUC_PATCHLEVEL__)
#error "__GNUC__ macros should not be defined"
#endif

#else
#error Invalid value for __ARO_EMULATE__
#endif
