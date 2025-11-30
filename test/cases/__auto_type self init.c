void foo(void) {
    int x;
    __auto_type x = x;
    
    __auto_type y = (int []){1, y};
    
    auto z = z + 1;
}

/** manifest:
syntax
args = -std=c23

__auto_type self init.c:3:21: error: variable 'x' declared with deduced type '__auto_type' cannot appear in its own initializer
__auto_type self init.c:5:33: error: variable 'y' declared with deduced type '__auto_type' cannot appear in its own initializer
__auto_type self init.c:7:14: error: variable 'z' declared with deduced type '__auto_type' cannot appear in its own initializer
*/
