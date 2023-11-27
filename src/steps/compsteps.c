#include "debug.h"

#include "compsteps.h"

#define PROG_NAME "a.sac"

static char *compiler_path;
static char *compiler_args = "";

static int status_code = -1;
static char *sac_output = "";

void a_compiler(char *path)
{
    compiler_path = path;
}

void a_program(const char *contents)
{
    FILE *fptr = fopen(PROG_NAME, "w");
    fprintf(fptr, "%s", contents);
    fclose(fptr);
}

void arguments(char *args)
{
    // TODO: concatenate if applied multiple times
    compiler_args = args;
}

void i_compile_it(void)
{
    // Create the command
    char command[256];
    sprintf(command, "%s ./" PROG_NAME " %s 2>&1", compiler_path, compiler_args);

    // Run the command
    FILE *pipe = popen(command, "r");
    ASSERT(pipe != NULL, "Could not run command: %s", command);

    // Read output lines
    char line[1024];
    while (fgets(line, 1024, pipe) != NULL)
    {
        // Remove newline
        line[strlen(line) - 1] = '\0';
        // Append the line
        char *tmp = sac_output;
        sac_output = malloc (strlen(tmp) + strlen(line) + 1);
        strcpy (sac_output, tmp);
        strcat (sac_output, line);
    }

    int status = pclose(pipe);
    ASSERT(status != -1, "Could not close command stream");
    status_code = WEXITSTATUS(status);
}

void compilation_succeeds(void)
{
    int check = status_code == 0;
    ASSERT(check, "Expected compilation to succeed, but status code was %d", status_code);
    if (!check) {
        LOG_ERROR("%s", sac_output);
    }
}

void compilation_fails(void)
{
    int check = status_code == 1;
    ASSERT(check, "Expected compilation to fail, but status code was %d", status_code);
    if (!check) {
        LOG_ERROR("%s", sac_output);
    }
}

void compile_output_contains(const char *str, size_t amount)
{
    size_t count = 0;
    size_t n = strlen(str);
    const char *p = sac_output;
    while ((p = strstr(p, str)) != NULL) {
        count++;
        p += n;
    }

    ASSERT(count == amount, "Expected to find %lu occurences of %s, but found %lu", amount, str, count);
}
