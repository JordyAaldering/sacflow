#ifndef _STEPS_H_
#define _STEPS_H_

#define BASH "#!/bin/bash\n"

extern void i_execute(const char *exec_path);
extern void the_shell_succeeds(void);
extern void permission_is_denied(void);
extern void the_output_contains(const char *expected);

#endif /* _STEPS_H_ */
