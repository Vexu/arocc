//aro-args --target=x86_64-linux -std=c23

int arr[20] = {0};
_Static_assert(&arr[10] - &arr[0] == 10);
_Static_assert(&arr[1] + 3 == &arr[4]);
_Static_assert(&arr[4] - 4 == &arr[0]);

struct Child {
    int x[10];
    char c;
};

struct Parent {
    int x;
    struct Child children[20];
};

struct Parent parents[10];
_Static_assert(&parents[5].children[10].x[5] - &parents[0].children[0].x[0] == 1220);

int x;
int y;
_Static_assert(&x != &y);
_Static_assert(&x + 1 == &y + 1);

_Static_assert(&x + 1 != &x + 2);
_Static_assert(&x == &x);
_Static_assert(&x >= &x);
_Static_assert(&x > &y);
_Static_assert(&x);

struct __attribute__((packed)) Packed {
    int x;
    char c;
    int y;
};

struct Packed packed;
_Static_assert(&packed.x - &packed.y == -1);

char *p = (char*)(&x + 100);

_Static_assert((char*)(&x+100) - (char*)&x == 400,"");
_Static_assert(&x - 2 != &x + 2, "");
_Static_assert(&x - 2 == -2 + &x, "");

union Empty {};

union Empty empty[10];
_Static_assert(&empty[4] - &empty[0] == 0, "");
_Static_assert(&empty[4] >= &empty[0], "");

_Static_assert(arr == arr, "");
_Static_assert(arr + 1 < arr + 2, "");
_Static_assert(arr != &x, "");
#define EXPECTED_ERRORS "relocations.c:24:1: error: static assertion failed" \
    "relocations.c:29:16: error: static_assert expression is not an integral constant expression" \
    "relocations.c:30:16: error: static_assert expression is not an integral constant expression" \
    "relocations.c:50:26: warning: subtraction of pointers to type 'union Empty' of zero size has undefined behavior [-Wpointer-arith]" \
    "relocations.c:50:16: error: static_assert expression is not an integral constant expression" \

