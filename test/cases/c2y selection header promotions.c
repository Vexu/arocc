int foo(unsigned char input) {
    switch (unsigned char x = input) {
        case 1:   return 10;
        case 258: return 20;
        case 2:   return 40;
        default:  return 30;
    }
}

int bar(unsigned char input) {
    if (unsigned char x = input) return 1;
    return 0;
}

/** manifest:
syntax
args = -std=c2y -target x86_64-linux-musl
*/
