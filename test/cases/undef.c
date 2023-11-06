//aro-args -undef --target=x86_64-linux-gnu

#if defined(linux) || defined(__linux) || defined(__linux__)
#error Should not be defined
#endif
