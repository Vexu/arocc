#include _Pragma("once")
#include __pragma(once)

/** manifest:
syntax
args = -fms-extensions

include pragma.c:1:10: error: expected "FILENAME" or <FILENAME>
include pragma.c:2:19: warning: #pragma once in main file [-Wpragma-once-outside-header]
include pragma.c:2:10: error: expected "FILENAME" or <FILENAME>
*/
