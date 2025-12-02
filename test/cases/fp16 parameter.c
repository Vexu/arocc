__fp16 foo(__fp16 param) {
    return 0;
}

/** manifest:
syntax
args = --target=x86_64-linux-gnu

fp16 parameter.c:1:19: error: parameters cannot have __fp16 type; did you forget * ?
fp16 parameter.c:1:11: error: function return value cannot have __fp16 type; did you forget * ?
*/
