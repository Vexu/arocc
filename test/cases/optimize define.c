//aro-args -O
#if !defined(__OPTIMIZE__)
#error Optimize flag not defined
#endif

#if defined(__OPTIMIZE_SIZE__)
#error Optimize size flag should not be defined
#endif
