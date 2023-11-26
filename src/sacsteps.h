#ifndef _SACSTEPS_H_
#define _SACSTEPS_H_

void a_sac_program(const char *program);

void i_compile_it_with(const char *args);
void i_run_it();

void the_status_code_is(int code);
void there_were_no_errors();
void there_were_errors();
void the_output_contains(const char *str, int amount);

#endif /* _SACSTEPS_H_ */
