#include "include/global_var.h"
int *multiple_ptr = &multiple;

#include "include/global_var_once.h"

#define EXPECTED_ERRORS "unused include.c:4:2: warning: unused include [-Wunused-include]"
