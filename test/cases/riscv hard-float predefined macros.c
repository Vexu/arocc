#if !defined(__riscv)
#error missing __riscv
#endif

#if __riscv_xlen != 64
#error invalid __riscv_xlen
#endif

#if !defined(__riscv_f) || !defined(__riscv_d)
#error missing floating-point extension macro
#endif

#if __riscv_flen != 64
#error invalid __riscv_flen
#endif

#if !defined(__riscv_float_abi_double)
#error missing double-float ABI macro
#endif

#if defined(__riscv_float_abi_soft) || defined(__riscv_float_abi_single)
#error incorrect floating-point ABI macro
#endif

int ok;

/** manifest:
syntax
args = --target=riscv64-linux-gnu -mcpu=baseline
*/
