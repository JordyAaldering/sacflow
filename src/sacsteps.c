#include <assert.h>
#include <stdio.h>

#include "sacsteps.h"

static int status_code = -1;

void a_sac_program(const char *program)
{
    FILE *fptr;
    fptr = fopen("a.sac", "w");
    fprintf(fptr, "%s", program);
    fclose(fptr);
}

void i_compile_it_with(const char *args)
{
    char command[80];
    sprintf(command, "sac2c ./a.sac %s", args);
    status_code = system(command);
}

void i_run_it()
{
    status_code = system("./a.out");
}

void the_status_code_is(int code)
{
    assert(status_code == code);
}

void there_were_no_errors()
{
    assert(status_code == 0);
}

void there_were_errors()
{
    assert(status_code == 0);
}

void the_output_contains(const char *str, int amount)
{
}
