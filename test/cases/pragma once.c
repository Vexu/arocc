#include "include/global_var.h"
#include "include/global_var.h"

#include "include/global_var_once.h"
#include "include/global_var_once.h"

int *once_ptr = &once;
int *multiple_ptr = &multiple;

#define EXPECTED_ERRORS "global_var.h:1:5: error: redefinition of 'multiple'" \
	"global_var.h:1:5: note: previous definition is here"
