// Based on https://github.com/llvm/llvm-project/blob/64212c8bcc85a1de3e4a8cebde72b721f5ed27e8/clang/test/Preprocessor/arm-acle-6.4.c
// Checks basic 32-bit ARM state and ACLE macros for arm-eabi / thumb-eabi targets.

#ifdef __ARM_64BIT_STATE
#error "__ARM_64BIT_STATE should not be defined for 32-bit ARM"
#endif

#ifdef __ARM_ARCH_ISA_A64
#error "__ARM_ARCH_ISA_A64 should not be defined for 32-bit ARM"
#endif

#ifdef __ARM_BIG_ENDIAN
#error "__ARM_BIG_ENDIAN should not be defined for little-endian ARM"
#endif

#ifndef __ARM_32BIT_STATE
#error "__ARM_32BIT_STATE not defined"
#elif __ARM_32BIT_STATE != 1
#error "__ARM_32BIT_STATE is not 1"
#endif

#ifndef __ARM_ACLE
#error "__ARM_ACLE not defined"
#elif __ARM_ACLE != 200
#error "__ARM_ACLE is not 200"
#endif

/** manifest:
expand_error
args = --target=arm-linux-gnueabi --emulate=clang
*/
