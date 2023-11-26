#include <stdio.h>
#include "debug.h"

#include "runsteps.h"

static char *run_output = "";

static int status_code = -1;

void i_run_it()
{
    status_code = system("./a.out");

    // Create the command
    char *command = "./a.out 2>&1";

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
        char *tmp = run_output;
        run_output = malloc (strlen(tmp) + strlen(line) + 1);
        strcpy (run_output, tmp);
        strcat (run_output, line);
    }

    int status = pclose(pipe);
    ASSERT(status != -1, "Could not close command stream");
    status_code = WEXITSTATUS(status);
}

void runtime_succeeded()
{
    ASSERT(status_code == 0, "Expected success, but status code was %d", status_code);
}

void the_status_code_is(int code)
{
    ASSERT(status_code == code, "Expected status code to be %d, but was %d", code, status_code);
}

void runtime_output_contains(const char *str, size_t amount)
{
    size_t count = 0;
    size_t n = strlen(str);
    const char *p = run_output;
    while ((p = strstr(p, str)) != NULL) {
        count++;
        p += n;
    }

    ASSERT(count == amount, "Expected to find %lu occurences of %s, but found %lu", amount, str, count);
}
