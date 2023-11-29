#include "debug.h"
#include "seasteps.h"

#include "examplesteps.h"

static char *compiler_path;
static char *compiler_args = "";
static int status_code = -1;
static char *sac_output = "";

static int result = -1;
static char *run_output = "";

void a_compiler(char *path)
{
    compiler_path = path;
}

void arguments(char *args)
{
    compiler_args = args;
}

void i_compile_it(void)
{
    char args[256];
    sprintf(args, "%s ./a.sac", compiler_args);
    status_code = i_execute(compiler_path, args, &sac_output);
}

void compilation_succeeds(void)
{
    ASSERT(status_code == 0, "Expected compilation to succeed, but status code was %d", status_code);
}

void compilation_fails(void)
{
    ASSERT(status_code == 1, "Expected compilation to fail, but status code was %d", status_code);
}

void compile_output_contains(const char *str, size_t amount)
{
    string_contains(sac_output, str, amount);
}

void i_run_it(void)
{
    result = i_execute("./a.out", "", &run_output);
}

void the_result_is(int expected)
{
    ASSERT(result == expected, "Expected status code to be %d, but was %d", expected, result);
}

void runtime_output_contains(const char *str, size_t amount)
{
    string_contains(run_output, str, amount);
}
