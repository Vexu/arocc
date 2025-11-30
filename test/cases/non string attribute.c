enum E {
   is_deprecated_with_msg __attribute__((deprecated("I am deprecated" = 5 ))),
};

/** manifest:
syntax

non string attribute.c:2:71: error: array type 'char [16]' is not assignable
non string attribute.c:2:53: error: attribute 'deprecated' requires an ordinary string
*/
