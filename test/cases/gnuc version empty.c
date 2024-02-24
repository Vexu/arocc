//aro-args -fgnuc-version=

#if defined(__GNUC__) || defined(__GNUC_MINOR__) || defined(__GNUC_PATCHLEVEL__)
#error "__GNUC__ macros should not be defined"
#endif
