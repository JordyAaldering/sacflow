#ifndef _COMPILESTEPS_H_
#define _COMPILESTEPS_H_

#include <stdlib.h>

void a_sac_program(const char *program);

void i_compile_it_with(const char *args);

void compilation_succeeded();
void compilation_failed();
void sac2c_output_contains(const char *str, size_t amount);

#endif /* _COMPILESTEPS_H_ */
