int main(void) {
    int x = 5;
    switch (x) {
        case 1: {
            __attribute__((fallthrough));
        }
        case 2: {
            __attribute__((fallthrough));
        }
        default: {
            
        }
    }
    return 0;
}
