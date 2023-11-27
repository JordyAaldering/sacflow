#ifndef _COMPSTEPS_H_
#define _COMPSTEPS_H_

#include <stdlib.h>

extern void a_compiler(char *path);
extern void a_program(const char *contents);

extern void arguments(char *args);
extern void i_compile_it(void);

extern void compilation_succeeds(void);
extern void compilation_fails(void);
extern void compile_output_contains(const char *str, size_t amount);

#endif /* _COMPSTEPS_H_ */
