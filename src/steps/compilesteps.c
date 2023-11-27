#include "debug.h"

#include "compilesteps.h"

static char *compiler_path;

static char *sac_output = "";

static int status_code = -1;

void a_sac_compiler(char *path)
{
    compiler_path = path;
}

void a_sac_program(const char *program)
{
    FILE *fptr = fopen("a.sac", "w");
    fprintf(fptr, "%s", program);
    fclose(fptr);
}

void i_compile_it_with(const char *args)
{
    // Create the command
    char command[256];
    sprintf(command, "%s ./a.sac %s 2>&1", compiler_path, args);

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

void compilation_succeeded(void)
{
    ASSERT(status_code == 0, "Expected compilation to succeed, but status code was %d", status_code);
}

void compilation_failed(void)
{
    ASSERT(status_code == 1, "Expected compilation to fail, but status code was %d", status_code);
}

void sac2c_output_contains(const char *str, size_t amount)
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
