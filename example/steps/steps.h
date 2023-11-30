#ifndef _STEPS_H_
#define _STEPS_H_

extern void i_chmod(const char *shell_path);
extern void i_run(const char *shell_path);
extern void the_shell_succeeds(void);
extern void permission_denied(void);
extern void the_output_contains(const char *expected);

#endif /* _STEPS_H_ */
