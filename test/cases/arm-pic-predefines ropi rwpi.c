// Based on https://github.com/llvm/llvm-project/blob/main/clang/test/Preprocessor/arm-pic-predefines.c
// Checks that both __ARM_ROPI and __ARM_RWPI are defined when both -fropi and -frwpi are passed.

#ifndef __ARM_ROPI
#error "__ARM_ROPI should be defined with -fropi"
#endif

#ifndef __ARM_RWPI
#error "__ARM_RWPI should be defined with -frwpi"
#endif

/** manifest:
expand_error
args = --target=arm-linux-gnueabi --emulate=clang -fropi -frwpi
*/
