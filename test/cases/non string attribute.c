enum E {
   is_deprecated_with_msg __attribute__((deprecated("I am deprecated" = 5 ))),
};

#define EXPECTED_ERRORS "non string attribute.c:2:71: error: expression is not assignable" \
   "non string attribute.c:2:53: error: attribute 'deprecated' requires an ordinary string" \

