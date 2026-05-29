// Based on https://github.com/llvm/llvm-project/blob/64212c8bcc85a1de3e4a8cebde72b721f5ed27e8/clang/test/Preprocessor/arm-acle-6.4.c
// Checks macros for ARMv7-M target (M-profile, Thumb-only, IDIV, no DSP/SIMD32).

#ifdef __ARM_ARCH_ISA_ARM
#error "__ARM_ARCH_ISA_ARM should not be defined for ARMv7-M"
#endif

#ifdef __ARM_FEATURE_SIMD32
#error "__ARM_FEATURE_SIMD32 should not be defined for ARMv7-M"
#endif

#ifndef __ARM_ARCH
#error "__ARM_ARCH not defined"
#elif __ARM_ARCH != 7
#error "__ARM_ARCH is not 7"
#endif

#ifndef __ARM_ARCH_ISA_THUMB
#error "__ARM_ARCH_ISA_THUMB not defined"
#elif __ARM_ARCH_ISA_THUMB != 2
#error "__ARM_ARCH_ISA_THUMB is not 2"
#endif

#ifndef __ARM_ARCH_PROFILE
#error "__ARM_ARCH_PROFILE not defined"
#elif __ARM_ARCH_PROFILE != 'M'
#error "__ARM_ARCH_PROFILE is not 'M'"
#endif

#ifndef __ARM_FEATURE_CLZ
#error "__ARM_FEATURE_CLZ not defined"
#elif __ARM_FEATURE_CLZ != 1
#error "__ARM_FEATURE_CLZ is not 1"
#endif

#ifndef __ARM_FEATURE_IDIV
#error "__ARM_FEATURE_IDIV not defined"
#elif __ARM_FEATURE_IDIV != 1
#error "__ARM_FEATURE_IDIV is not 1"
#endif

#ifndef __ARM_FEATURE_LDREX
#error "__ARM_FEATURE_LDREX not defined"
#elif __ARM_FEATURE_LDREX != 0x7
#error "__ARM_FEATURE_LDREX is not 0x7"
#endif

#ifndef __ARM_FEATURE_QBIT
#error "__ARM_FEATURE_QBIT not defined"
#elif __ARM_FEATURE_QBIT != 1
#error "__ARM_FEATURE_QBIT is not 1"
#endif

#ifndef __ARM_FEATURE_SAT
#error "__ARM_FEATURE_SAT not defined"
#elif __ARM_FEATURE_SAT != 1
#error "__ARM_FEATURE_SAT is not 1"
#endif

#ifndef __ARM_FEATURE_UNALIGNED
#error "__ARM_FEATURE_UNALIGNED not defined"
#elif __ARM_FEATURE_UNALIGNED != 1
#error "__ARM_FEATURE_UNALIGNED is not 1"
#endif

/** manifest:
expand_error
args = --target=armv7m-linux-gnueabi --emulate=clang
*/
