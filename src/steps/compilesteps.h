#ifndef _COMPILESTEPS_H_
#define _COMPILESTEPS_H_

#include <stdlib.h>

extern void a_sac_compiler(char *path);
extern void a_sac_program(const char *program);

extern void arguments(char *args);
extern void i_compile_it(void);

extern void compilation_succeeded(void);
extern void compilation_failed(void);
extern void sac2c_output_contains(const char *str, size_t amount);

#endif /* _COMPILESTEPS_H_ */
