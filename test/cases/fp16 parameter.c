//aro-args --target=x86_64-linux-gnu
__fp16 foo(__fp16 param) {
    return 0;
}

#define EXPECTED_ERRORS "fp16 parameter.c:2:19: error: parameters cannot have __fp16 type; did you forget * ?" \
    "fp16 parameter.c:2:11: error: function return value cannot have __fp16 type; did you forget * ?" \

