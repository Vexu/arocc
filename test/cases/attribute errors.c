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

int standard_attr_on_types = sizeof(int [[noreturn, gnu::noreturn]]);
// int [[noreturn]] standard_attr_on_types2; // TODO

/** manifest:
syntax
args = --target=x86_64-linux -std=c23 -fdeclspec
skip = TODO: implement 'access' attribute
skip = TODO: implement 'alias' attribute
skip = TODO: implement 'assume_aligned' attribute
skip = TODO: implement 'pure' attribute
skip = TODO: implement 'simd' attribute
skip = TODO: add error for standard decl attribute in type position

attribute errors.c:3:24: warning: TODO: implement 'access' attribute
attribute errors.c:4:24: warning: TODO: implement 'access' attribute
attribute errors.c:5:24: warning: TODO: implement 'access' attribute
attribute errors.c:6:30: error: use of undeclared identifier 'bar'
attribute errors.c:7:24: warning: TODO: implement 'alias' attribute
attribute errors.c:10:24: error: 'aligned' attribute takes at most 1 argument(s)
attribute errors.c:11:24: error: requested alignment is not a power of 2
attribute errors.c:12:24: warning: TODO: implement 'assume_aligned' attribute
attribute errors.c:13:24: warning: TODO: implement 'assume_aligned' attribute
attribute errors.c:14:24: warning: TODO: implement 'assume_aligned' attribute
attribute errors.c:15:24: warning: 'hot' attribute only applies to functions [-Wignored-attributes]
attribute errors.c:15:29: warning: TODO: implement 'pure' attribute
attribute errors.c:16:24: error: 'cleanup' function 'cleanup_fn' must take 1 parameter
attribute errors.c:17:32: error: expected an identifier as argmuent of 'cleanup' attribute but got a string
attribute errors.c:18:24: warning: TODO: implement 'simd' attribute
attribute errors.c:19:24: warning: TODO: implement 'simd' attribute
attribute errors.c:20:24: warning: TODO: implement 'simd' attribute
attribute errors.c:21:24: warning: unknown attribute 'invalid_attribute' ignored [-Wunknown-attributes]
attribute errors.c:22:24: warning: unknown attribute 'invalid_attribute' ignored [-Wunknown-attributes]
attribute errors.c:23:49: error: expected a string as argmuent of 'deprecated' attribute but got an integer constant
attribute errors.c:27:24: warning: 'cold' attribute only applies to functions [-Wignored-attributes]
attribute errors.c:30:5: warning: '__thiscall' calling convention is not supported for this target [-Wignored-attributes]
attribute errors.c:31:36: error: attribute 'vector_size' argument value '4294967296' out of range
attribute errors.c:32:46: error: expected an integer constant as argmuent of 'vector_size' attribute but got a complex floating point number
attribute errors.c:34:23: error: a declspec attribute cannot appear here
attribute errors.c:36:23: error: an attribute list cannot appear here
attribute errors.c:38:43: error: 'noreturn' attribute cannot be applied to types
attribute errors.c:38:53: error: 'gnu::noreturn' attribute cannot be applied to types
*/
