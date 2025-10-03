#include "include/global_var.h"
#include "include/global_var.h"

#include "include/global_var_once.h"
#include "include/global_var_once.h"

#pragma once
#pragma once

#define EXPECTED_ERRORS "global_var.h:1:5: error: redefinition of 'multiple'" \
	"global_var.h:1:5: note: previous definition is here" \
    "pragma once.c:7:9: warning: #pragma once in main file [-Wpragma-once-outside-header]" \
    "pragma once.c:8:9: warning: #pragma once in main file [-Wpragma-once-outside-header]" \
