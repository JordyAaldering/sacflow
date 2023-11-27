#ifndef _RUNSTEPS_H_
#define _RUNSTEPS_H_

#include <stdlib.h>

extern void i_run_it();

extern void the_result_is(int expected);
extern void runtime_output_contains(const char *str, size_t amount);

#endif /* _RUNSTEPS_H_ */
