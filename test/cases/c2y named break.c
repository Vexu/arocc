static void named_break(int a) {
    loop: while (true) {
        while (true) {
            if (a) continue loop;
        }
        break loop;
    }
    sw: switch (a) {
        case 1:
            break sw;
        case 2:
            continue sw;
    }
    other:;
    for (;;) {
        #pragma GCC diagnostic warning "-Wc2y-extensions"
        continue other;
    }
}

/** manifest:
syntax
args = -std=c2y

c2y named break.c:12:22: error: 'continue' label refers to a switch statement
c2y named break.c:17:18: warning: named 'continue' is a C2y extension [-Wc2y-extensions]
c2y named break.c:17:18: error: 'continue' label does not name an enclosing loop or switch
*/
