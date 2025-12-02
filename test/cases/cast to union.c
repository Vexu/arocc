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

/** manifest:
syntax

cast to union.c:11:9: warning: cast to union type is a GNU extension [-Wgnu-union-cast]
cast to union.c:15:9: error: cast to union type from type 'double' not present in union
cast to union.c:16:5: error: cast to incomplete type 'union Forward'
cast to union.c:17:5: error: cast to incomplete type 'union DoesNotExist'
*/
