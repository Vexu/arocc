union U {
    int x;
    float y;
};
union Forward;

void foo(void) {
    union U u;
#pragma GCC diagnostic push
#pragma GCC diagnostic warning "-Wpedantic"
    u = (union U)1;
#pragma GCC diagnostic pop

    u = (union U)1.0f;
    u = (union U)1.0;
    (union Forward)1;
    (union DoesNotExist)1;
}

void same_type_casts(union U value, _Atomic(union U) atomic_value) {
    (void)(union U)value;
    (void)(_Atomic(union U))value;
    (void)(union U)atomic_value;
    (void)(_Atomic(union U))atomic_value;
}

union Forward make_forward(void);

void incomplete_same_type_cast(void) {
    (void)(union Forward)make_forward();
}

/** manifest:
syntax

cast to union.c:11:9: warning: cast to union type is a GNU extension [-Wgnu-union-cast]
cast to union.c:15:9: error: cast to union type from type 'double' not present in union
cast to union.c:16:5: error: cast to incomplete type 'union Forward'
cast to union.c:17:5: error: cast to incomplete type 'union DoesNotExist'
cast to union.c:30:11: error: cast to incomplete type 'union Forward'
*/
