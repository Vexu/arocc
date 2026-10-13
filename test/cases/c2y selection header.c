void entry() {
    if (int a = 1) {
        a -= 1;
    } else {
        a += 1;
    }
    #pragma GCC diagnostic ignored "-Wpre-c2y-compat"
    if (float a = 2.0; a != 0.0) { 
        a *= 3;
    }
    switch (int a = 3) { }
    switch (float a = 4.0, b = 5.0) { }
    if (int a[2] = {1, 2}) {}
    if (int a) {}
    if (typedef int a) {}
}

/** manifest:
syntax
args = -std=c2y -Wpre-c2y-compat

c2y selection header.c:2:9: warning: declarations in if conditions are incompatible with C standards before C2y [-Wpre-c2y-compat]
c2y selection header.c:12:26: error: expected expression
c2y selection header.c:13:13: error: declaration in condition must have a scalar type ('int [2]' invalid)
c2y selection header.c:14:13: error: variable declaration in condition must have an initializer
c2y selection header.c:15:21: error: declaration in condition must be a variable
*/
