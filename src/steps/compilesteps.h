#ifndef _COMPILESTEPS_H_
#define _COMPILESTEPS_H_

#include <stdlib.h>

extern void a_sac_compiler(char *path);
extern void a_sac_program(const char *program);

extern void i_compile_it_with(const char *args);

extern void compilation_succeeded();
extern void compilation_failed();
extern void sac2c_output_contains(const char *str, size_t amount);

#endif /* _COMPILESTEPS_H_ */
