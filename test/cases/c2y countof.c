#include <stdcountof.h>

void countof_usage(int a, struct {int dummy; int arr[]; } b, int c[a]) {
    int vla[a], arr[2];
    (void)countof vla;
    static_assert(countof arr == 2);

    (void)countof a;
    (void)countof b.arr;

    #pragma GCC diagnostic warning "-Wpre-c2y-compat"
    (void)countof c;
}

/** manifest:
syntax
args = -std=c2y

c2y countof.c:8:19: error: '_Countof' requires an argument of array type; 'int' is invalid
c2y countof.c:9:19: error: '_Countof' requires an argument of array type; 'int []' is invalid
c2y countof.c:12:11: warning: '_Countof' is incompatible with C standards before C2y [-Wpre-c2y-compat]
stdcountof.h:5:17: note: expanded from here
c2y countof.c:12:19: error: '_Countof' requires an argument of array type; 'int *' is invalid
*/
