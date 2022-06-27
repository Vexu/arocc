/* TODO: update this file once we validate attribute contexts */
void cleanup_fn(void) {}
void foo(void) {
    int __attribute__((access)) bar_1;
    int __attribute__((access(foo, 0))) bar_2;
    int __attribute__((access(read_only, 1, 2))) bar_3;
    int __attribute__((alias(bar))) bar_4;
    int __attribute__((alias("bar"))) bar_5;
    int __attribute__((aligned)) bar_6;
    int __attribute__((aligned(2 + 2))) bar_7;
    int __attribute__((aligned(4, 8))) bar_8;
    int __attribute__((aligned(10))) bar_9;
    int __attribute__((assume_aligned(10, 0))) bar_10;
    int __attribute__((assume_aligned(2))) bar_11;
    int __attribute__((assume_aligned(2, 0))) bar_12;
    int __attribute__((hot, pure)) bar_13;
    int __attribute__((cleanup(cleanup_fn))) bar_14;
    int __attribute__((cleanup("cleanup_fn"))) bar_15;
    int __attribute__((simd())) bar_16;
    int __attribute__((simd("inbranch"))) bar_17;
    int __attribute__((simd("wrong"))) bar_18;
    int __attribute__((invalid_attribute)) bar_19;
    int __attribute__((invalid_attribute(1, (2 + 3)))) bar_20;
    int __attribute__((deprecated("deprecated", 1))) bar_21;
}

struct S {
    int __attribute__((cold)) x;
};

#define EXPECTED_ERRORS "attribute errors.c:4:24: error: 'access' attribute takes at least 2 argument(s)" \
    "attribute errors.c:5:31: error: Unknown `access` argument. Possible values are: 'read_only', 'read_write', 'write_only', 'none'" \
    "attribute errors.c:6:24: warning: attribute 'access' ignored on variables [-Wignored-attributes]" \
    "attribute errors.c:7:30: error: use of undeclared identifier 'bar'" \
    "attribute errors.c:11:35: error: 'aligned' attribute takes at most 1 argument(s)" \
    "attribute errors.c:12:32: error: requested alignment is not a power of 2" \
    "attribute errors.c:13:39: error: requested alignment is not a power of 2" \
    "attribute errors.c:14:24: warning: attribute 'assume_aligned' ignored on variables [-Wignored-attributes]" \
    "attribute errors.c:15:24: warning: attribute 'assume_aligned' ignored on variables [-Wignored-attributes]" \
    "attribute errors.c:16:24: warning: attribute 'hot' ignored on variables [-Wignored-attributes]" \
    "attribute errors.c:16:29: warning: attribute 'pure' ignored on variables [-Wignored-attributes]" \
    "attribute errors.c:18:32: error: Attribute argument is invalid, expected an identifier but got a string" \
    "attribute errors.c:19:24: warning: attribute 'simd' ignored on variables [-Wignored-attributes]" \
    "attribute errors.c:20:24: warning: attribute 'simd' ignored on variables [-Wignored-attributes]" \
    "attribute errors.c:21:29: error: Unknown `simd` argument. Possible values are: \"notinbranch\", \"inbranch\"" \
    "attribute errors.c:22:24: warning: unknown attribute 'invalid_attribute' ignored [-Wunknown-attributes]" \
    "attribute errors.c:23:24: warning: unknown attribute 'invalid_attribute' ignored [-Wunknown-attributes]" \
    "attribute errors.c:24:49: error: 'deprecated' attribute takes at most 1 argument(s)" \
    "attribute errors.c:28:24: warning: attribute 'cold' ignored on fields [-Wignored-attributes]" \

