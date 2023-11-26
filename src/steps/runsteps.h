#ifndef _RUNSTEPS_H_
#define _RUNSTEPS_H_

#include <stdlib.h>

void i_run_it();

void runtime_succeeded();
void the_status_code_is(int code);
void runtime_output_contains(const char *str, size_t amount);

#endif /* _RUNSTEPS_H_ */
