//aro-args --target=x86_64-linux-gnu -Wno-gnu-alignof-expression

__attribute__((aligned(2))) typedef struct {
	int a;
} A;
_Static_assert(_Alignof(A) == 2, "");

typedef __attribute__((aligned(2))) struct {
	int a;
} B;
_Static_assert(_Alignof(B) == 2, "");

typedef struct __attribute__((aligned(2))) {
	int a;
} C;
_Static_assert(_Alignof(C) == 4, "");

typedef struct {
	int a;
} __attribute__((aligned(2))) D;
_Static_assert(_Alignof(D) == 4, "");
_Static_assert(_Alignof(typeof(D)) == 4, "");
typeof(D) d;
_Static_assert(_Alignof(d)== 4, "");

typedef struct {
	int a;
}  E __attribute__((aligned(2)));
_Static_assert(_Alignof(E) == 2, "");
_Static_assert(_Alignof(typeof(E)) == 2, "");
typeof(E) e;
_Static_assert(_Alignof(e)== 2, "");

struct __attribute__((aligned(2))) F {
	int a;
};
_Static_assert(_Alignof(struct F) == 4, "");

typedef __attribute__((aligned(2))) struct F G;
_Static_assert(_Alignof(G) == 2, "");
