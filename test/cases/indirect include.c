#include "include/indirect include1.h"

struct S1 s_h1;
struct S2 s_h2;
enum E1 e_h1;
enum E2 e_h2;
T1 t_h1;
T2 t_h2;
int *p_i_h1 = &i_h1;
int *p_i_h2 = &i_h2;
M1
M2

#define EXPECTED_ERRORS "indirect include.c:4:1: warning: use of indirectly included symbol [-Windirect-include]" \
    "indirect include2.h' directly to use this symbol" \
    "indirect include.c:6:1: warning: use of indirectly included symbol [-Windirect-include]" \
    "indirect include2.h' directly to use this symbol" \
    "indirect include.c:8:1: warning: use of indirectly included symbol [-Windirect-include]" \
    "indirect include2.h' directly to use this symbol" \
    "indirect include.c:10:16: warning: use of indirectly included symbol [-Windirect-include]" \
    "indirect include2.h' directly to use this symbol" \
    "indirect include.c:12:1: warning: use of indirectly included symbol [-Windirect-include]" \
    "indirect include2.h' directly to use this symbol" \
