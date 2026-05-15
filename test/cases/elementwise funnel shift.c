typedef unsigned int u4 __attribute__((vector_size(16)));

u4 fshl(u4 a, u4 b, u4 c) {
    return __builtin_elementwise_fshl(a, b, c);
}

u4 fshr(u4 a, u4 b, u4 c) {
    return __builtin_elementwise_fshr(a, b, c);
}

/** manifest:
syntax
args = --target=x86_64-linux
*/
