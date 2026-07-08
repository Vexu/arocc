void unused_locals(int a_param, [[maybe_unused]] int b_param, int c_param) {
    (void)c_param;

    typedef int A;
    __attribute__((unused)) typedef int B;
    typedef int C;

    int a;
    [[maybe_unused]] int b;
    int c;
    (void)c;

    a_label: ;
    b_label: __attribute__((unused));
    c_label: ;
    goto c_label;
    goto d_label;
    d_label: ;

    C self = self;
}

void unused_kr_param(a, b, c)
    int b;
    int b;
{
    (void)a;
    (void)b;
}


/** manifest:
syntax
args = -Wunused -Wunused-parameter -Wno-implicit-int -Wno-deprecated-non-prototype

unused locals.c:1:24: warning: unused parameter 'a_param' [-Wunused-parameter]
unused locals.c:4:17: warning: unused typedef 'A' [-Wunused-local-typedef]
unused locals.c:8:9: warning: unused variable 'a' [-Wunused-variable]
unused locals.c:13:5: warning: unused label 'a_label' [-Wunused-label]
unused locals.c:25:9: error: redefinition of parameter 'b'
unused locals.c:24:9: note: previous definition is here
unused locals.c:23:28: warning: unused parameter 'c' [-Wunused-parameter]
*/
