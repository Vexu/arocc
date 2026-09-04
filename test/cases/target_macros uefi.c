#if TARGET_OS_WIN32 != 0
#error TARGET_OS_WIN32 is not the expected value
#endif

#if TARGET_OS_WINDOWS != 0
#error TARGET_OS_WINDOWS is not the expected value
#endif

#if TARGET_OS_LINUX != 0
#error TARGET_OS_LINUX is not the expected value
#endif

#if TARGET_OS_UNIX != 0
#error TARGET_OS_UNIX is not the expected value
#endif

#if TARGET_OS_MAC != 0
#error TARGET_OS_MAC is not the expected value
#endif

#if TARGET_OS_OSX != 0
#error TARGET_OS_OSX is not the expected value
#endif

#if TARGET_OS_IPHONE != 0
#error TARGET_OS_IPHONE is not the expected value
#endif

#if TARGET_OS_IOS != 0
#error TARGET_OS_IOS is not the expected value
#endif

#if TARGET_OS_TV != 0
#error TARGET_OS_TV is not the expected value
#endif

#if TARGET_OS_WATCH != 0
#error TARGET_OS_WATCH is not the expected value
#endif

#if TARGET_OS_VISION != 0
#error TARGET_OS_VISION is not the expected value
#endif

#if TARGET_OS_DRIVERKIT != 0
#error TARGET_OS_DRIVERKIT is not the expected value
#endif

#if TARGET_OS_MACCATALYST != 0
#error TARGET_OS_MACCATALYST is not the expected value
#endif

#if TARGET_OS_SIMULATOR != 0
#error TARGET_OS_SIMULATOR is not the expected value
#endif

#if TARGET_OS_EMBEDDED != 0
#error TARGET_OS_EMBEDDED is not the expected value
#endif

#if TARGET_OS_NANO != 0
#error TARGET_OS_NANO is not the expected value
#endif

#if TARGET_IPHONE_SIMULATOR != 0
#error TARGET_IPHONE_SIMULATOR is not the expected value
#endif

#if TARGET_OS_UIKITFORMAC != 0
#error TARGET_OS_UIKITFORMAC is not the expected value
#endif

#if TARGET_OS_UEFI != 1
#error TARGET_OS_UEFI is not the expected value
#endif

/** manifest:
syntax
args = -target x86_64-uefi --emulate=clang
*/
