#define A_H <a.h>
#define B_H <b.h>

#include A_H
#include B_H

#ifndef A_H_
#error expected A_H_ to be defined
#endif

#ifndef B_H_
#error expected B_H_ to be defined
#endif

/** manifest:
syntax
args = -I include/filename_macros

*/
