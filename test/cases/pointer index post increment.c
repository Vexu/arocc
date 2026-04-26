void foo(void) {
    unsigned short *ptr;
    ptr[0]++;
}

/** manifest:
syntax
args = --target=x86_64-linux
*/
