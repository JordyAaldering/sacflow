#include "debug.h"
#include <stdlib.h>
#include <string.h>

#include "seasteps.h"

static void read_console_lines(FILE *pipe, char **console_output)
{
    char buffer[1024], *tmp;
    while (fgets(buffer, 1024, pipe) != NULL)
    {
        // Remove the newline at the end of this line
        buffer[strlen(buffer) - 1] = '\0';
        // Append the line to console_output
        tmp = *console_output;
        *console_output = malloc(strlen(tmp) + strlen(buffer) + 1);
        strcpy (*console_output, tmp);
        strcat (*console_output, buffer);
    }
}

int a_file(const char *filepath, const char *contents)
{
    FILE *pipe;
    int status;

    // Remove the file if it already exists
    remove(filepath);

    pipe = fopen(filepath, "w");
    ASSERT(pipe != NULL, "Could not open file: %s", filepath);
    status = fprintf(pipe, "%s", contents);
    ASSERT(status >= 0, "Could not write to file: %s", filepath);
    status = fclose(pipe);
    ASSERT(status >= 0, "Could not close file: %s", filepath);
    return status;
}

int i_run(const char *command, char **console_output)
{
    FILE *pipe;
    char buffer[128];
    int status;

    // Create the command, and redirect stderr to stdout
    sprintf(buffer, "%s 2>&1", command);

    pipe = popen(buffer, "r");
    ASSERT(pipe != NULL, "Could not open process: %s", buffer);
    if (console_output != NULL) {
        read_console_lines(pipe, console_output);
    }

    status = pclose(pipe);
    ASSERT(status >= 0, "Could not close process");
    return WEXITSTATUS(status);
}

int string_contains(const char *contents, const char *expected, int amount)
{
    int success, count = 0;
    size_t n = strlen(expected);
    const char *ptr = contents;
    while ((ptr = strstr(ptr, expected)) != NULL) {
        count += 1;
        ptr += n;
    }

    success = count == amount;
    #ifdef SEAFLOW_VERBOSE
    ASSERT(success, "Expected to find %d occurences of %s, but found %d in:\n%s", amount, expected, count, contents);
    #else
    ASSERT(success, "Expected to find %d occurences of %s, but found %d", amount, expected, count);
    #endif

    return success;
}

int string_does_not_contain(const char *contents, const char *expected)
{
    int success = strstr(contents, expected) == NULL;

    #ifdef SEAFLOW_VERBOSE
    ASSERT(success, "Expected to find no occurences of %s in:\n%s", expected, contents);
    #else
    ASSERT(success, "Expected to find no occurences of %s", expected);
    #endif

    return success;
}
