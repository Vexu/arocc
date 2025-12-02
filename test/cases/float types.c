void foo(void) {
    __bf16 bf = 1.0bf16;
    __fp16 fp = 1.0;
    float f = 1.0f;
    double d = 1.0;
    long double a = 1.0L;
    _Float16 f16 = 1.0;
    _Float32 f32 = 1.0f32;
    _Float64 f64 = 1.0f64;
    _Float128 f128 = 1.0f128;
    _Float32x f32x = 1.0f32x;
    _Float64x f64x = 1.0f64x;
    _Float128x f128x = 1.0f128x;
    _Decimal32 d32 = 1.0d32;
    _Decimal64 d64 = 1.0d64;
    _Decimal128 d128 = 1.0d128;
    _Decimal64x d64x = 1.0d64x;

    f + f32x;
    f32 + d32;
    d64x + d128;
}

/** manifest:
syntax
args = --target=x86_64-linux -Wno-unused

float types.c:13:5: error: _Float128x is not supported on this target
float types.c:20:9: error: cannot mix operands of decimal floating and other floating types
*/
