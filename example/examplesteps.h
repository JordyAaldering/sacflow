#ifndef _EXAMPLESTEPS_H_
#define _EXAMPLESTEPS_H_

#include <stdlib.h>

extern void a_compiler(char *path);
extern void arguments(char *args);

extern void i_compile_it(void);
extern void i_run_it(void);

extern void compilation_succeeds(void);
extern void compilation_fails(void);
extern void compile_output_contains(const char *str, size_t amount);
extern void the_result_is(int expected);
extern void runtime_output_contains(const char *str, size_t amount);

#endif /* _EXAMPLESTEPS_H_ */