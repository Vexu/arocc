int lottery(unsigned int x) {
    switch (x) {
        case 3: return 0;
        case -1: return 3;
        case 8 ... 10: return x;
        default: return -1;
    }
}

/** manifest:
syntax
args = --target=x86_64-linux-gnu
*/
