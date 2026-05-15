#if !defined(__riscv_float_abi_soft)
#error missing soft-float ABI macro
#endif

#if defined(__riscv_float_abi_single) || defined(__riscv_float_abi_double)
#error incorrect floating-point ABI macro
#endif

#if __riscv_flen != 64
#error invalid __riscv_flen
#endif

int ok;

/** manifest:
syntax
args = --target=riscv64-linux-gnusf -mcpu=baseline
*/
