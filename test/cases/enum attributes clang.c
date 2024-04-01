//aro-args --emulate=clang
enum E {
   is_deprecated __attribute__((deprecated)),
   is_deprecated_with_msg __attribute__((deprecated("I am deprecated"))),
   is_unavailable __attribute__((unavailable)),
   is_unavailable_with_msg  __attribute__((unavailable("I am not available"))),
   newval,
};

void foo(void) {
  int a = newval;
  a = is_deprecated;
  a = is_deprecated_with_msg;
  a = is_unavailable;
  a = is_unavailable_with_msg;
}

enum __attribute__((aligned(16))) Attributed {
  Val,
};
_Static_assert(_Alignof(enum Attributed) == 16, "enum align");

enum Trailing {
  Foo
} __attribute__((aligned(32)));
_Static_assert(_Alignof(enum Trailing) == 32, "enum align");

enum __attribute__((vector_size(32))) VectorSize1;

enum __attribute__((vector_size(32))) VectorSize2 {
    A
};


#define EXPECTED_ERRORS "enum attributes clang.c:12:7: warning: 'is_deprecated' is deprecated [-Wdeprecated-declarations]" \
  "enum attributes clang.c:3:33: note: 'is_deprecated' has been explicitly marked deprecated here" \
  "enum attributes clang.c:13:7: warning: 'is_deprecated_with_msg' is deprecated: I am deprecated [-Wdeprecated-declarations]" \
  "enum attributes clang.c:4:42: note: 'is_deprecated_with_msg' has been explicitly marked deprecated here" \
  "enum attributes clang.c:14:7: error: 'is_unavailable' is unavailable" \
  "enum attributes clang.c:5:34: note: 'is_unavailable' has been explicitly marked unavailable here" \
  "enum attributes clang.c:15:7: error: 'is_unavailable_with_msg' is unavailable: I am not available" \
  "enum attributes clang.c:6:44: note: 'is_unavailable_with_msg' has been explicitly marked unavailable here" \
