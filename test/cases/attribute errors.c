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

int __thiscall bar(int);
int big __attribute__((vector_size(4294967296)));
typedef float f2v __attribute__((vector_size(8.0i)));

typedef struct {} A1, __declspec(deprecated) B1, C1;
typedef struct {} A2, __attribute__((deprecated)) B2, C2;
typedef struct {} A3, [[deprecated]] B3, C3;

/** manifest:
syntax
args = --target=x86_64-linux -std=c23 -fdeclspec

attribute errors.c:3:24: error: 'access' attribute takes at least 2 argument(s)
attribute errors.c:4:31: warning: unknown `access` argument. Possible values are: 'read_only', 'read_write', 'write_only', 'none' [-Wignored-attributes]
attribute errors.c:5:24: warning: attribute 'access' ignored on variables [-Wignored-attributes]
attribute errors.c:6:30: error: use of undeclared identifier 'bar'
attribute errors.c:10:35: error: 'aligned' attribute takes at most 1 argument(s)
attribute errors.c:11:32: error: requested alignment is not a power of 2
attribute errors.c:12:39: error: requested alignment is not a power of 2
attribute errors.c:13:24: warning: attribute 'assume_aligned' ignored on variables [-Wignored-attributes]
attribute errors.c:14:24: warning: attribute 'assume_aligned' ignored on variables [-Wignored-attributes]
attribute errors.c:15:24: warning: attribute 'hot' ignored on variables [-Wignored-attributes]
attribute errors.c:15:29: warning: attribute 'pure' ignored on variables [-Wignored-attributes]
attribute errors.c:17:32: error: attribute argument is invalid, expected an identifier but got a string
attribute errors.c:18:24: warning: attribute 'simd' ignored on variables [-Wignored-attributes]
attribute errors.c:19:24: warning: attribute 'simd' ignored on variables [-Wignored-attributes]
attribute errors.c:20:29: warning: unknown `simd` argument. Possible values are: "notinbranch", "inbranch" [-Wignored-attributes]
attribute errors.c:21:24: warning: unknown attribute 'invalid_attribute' ignored [-Wunknown-attributes]
attribute errors.c:22:24: warning: unknown attribute 'invalid_attribute' ignored [-Wunknown-attributes]
attribute errors.c:23:49: error: 'deprecated' attribute takes at most 1 argument(s)
attribute errors.c:27:24: warning: attribute 'cold' ignored on types [-Wignored-attributes]
attribute errors.c:30:5: warning: '__thiscall' calling convention is not supported for this target [-Wignored-attributes]
attribute errors.c:31:36: error: attribute value '4294967296' out of range
attribute errors.c:32:46: error: attribute argument is invalid, expected an integer constant but got a complex floating point number
attribute errors.c:34:23: error: a declspec attribute cannot appear here
attribute errors.c:36:23: error: an attribute list cannot appear here
*/
