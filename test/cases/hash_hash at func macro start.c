#define foo(X) ## x

/** manifest:
syntax

hash_hash at func macro start.c:1:16: error: '##' cannot appear at the start of a macro expansion
*/
