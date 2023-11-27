#ifndef _RUNSTEPS_H_
#define _RUNSTEPS_H_

#include <stdlib.h>

void i_run_it();

void the_result_is(int expected);
void runtime_output_contains(const char *str, size_t amount);

#endif /* _RUNSTEPS_H_ */
