#include "debug.h"
#include <stdio.h>
#include <stdlib.h>

#include "seasteps.h"

#define BUFFER_SIZE 1024

/**
 * @brief Creates a new file.
 *
 * @param filepath The file to create.
 * @param contents The file contents.
 */
void a_file(const char *filepath, const char *contents)
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
}

/**
 * @brief Runs the given executable with the given arguments.
 *
 * @param exec_path The path to the executable.
 * @param args The program arguments.
 * @param console_output Pointer to a string to which to append the console output.
 *
 * @returns The returned status code of the executable.
 */
int i_execute(const char *exec_path, const char *args, char **console_output)
{
    FILE *pipe;
    char buffer[BUFFER_SIZE], *tmp;
    int status;

    // Create the command, and redirect stderr to stdout
    sprintf(buffer, "%s %s 2>&1", exec_path, args);

    // Open a process in read mode
    pipe = popen(buffer, "r");
    ASSERT(pipe != NULL, "Could not open process: %s", buffer);

    // Read all lines written to the console
    while (fgets(buffer, BUFFER_SIZE, pipe) != NULL)
    {
        // Remove the newline at the end of this line
        buffer[strlen(buffer) - 1] = '\0';
        // Append the line to console_output
        tmp = *console_output;
        *console_output = malloc(strlen(tmp) + strlen(buffer) + 1);
        strcpy (*console_output, tmp);
        strcat (*console_output, buffer);
    }

    status = pclose(pipe);
    ASSERT(status >= 0, "Could not close process");
    // Return the status code
    return WEXITSTATUS(status);
}

/**
 * @brief Checks whether a string contains a substring a number of times.
 *
 * @param contents The file contents.
 * @param expected The substring to match with.
 * @param amount The number of expected matches.
 */
int string_contains(const char *contents, const char *expected, size_t amount)
{
    size_t count = 0;
    size_t n = strlen(expected);

    const char *ptr = contents;
    while ((ptr = strstr(ptr, expected)) != NULL) {
        count += 1;
        ptr += n;
    }

    int success = count == amount;
    #ifndef SEAFLOW_VERBOSE
    ASSERT(success, "Expected to find %lu occurences of %s, but found %lu in:\n%s", amount, expected, count, contents);
    #else
    ASSERT(success, "Expected to find %lu occurences of %s, but found %lu", amount, expected, count);
    #endif

    return success;
}

/**
 * @brief Checks whether a string does not contain a substring.
 *
 * @param contents The file contents.
 * @param expected The substring to match with.
 */
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

#undef BUFFER_SIZE
