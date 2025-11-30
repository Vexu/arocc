void foo(void) {
    struct Foo {
        int a;
    };
    (struct Foo)1;
    (float)(int*)1l;
    (int*)1.f;
    (const int)1;
    const int p_i[] = (typeof(p_i))0;
    int a = (char)"foo";
    int b = (float)"foo";
    unsigned long long d = (unsigned long long)"foo";

    int x = 1;
    x ? (void)1 : 1;
    (enum E)1;
    int *ptr;
    ptr = (int *)(void)5;
    (enum DoesNotExist)2.0;
}

/** manifest:
syntax

casts.c:5:5: error: cannot cast to non arithmetic or pointer type 'struct Foo'
casts.c:6:5: error: pointer cannot be cast to type 'float'
casts.c:7:5: error: operand of type 'float' cannot be cast to a pointer type
casts.c:8:5: warning: cast to type 'const int' will not preserve qualifiers [-Wcast-qualifiers]
casts.c:9:23: error: cannot cast to non arithmetic or pointer type 'typeof(const int [])' (aka 'const int ')
casts.c:10:13: warning: cast to smaller integer type 'char' from 'char *' [-Wpointer-to-int-cast]
casts.c:11:13: error: pointer cannot be cast to type 'float'
casts.c:16:5: error: cast to incomplete type 'enum E'
casts.c:18:18: error: operand of type 'void' where arithmetic or pointer type is required
casts.c:19:5: error: cast to incomplete type 'enum DoesNotExist'
*/
