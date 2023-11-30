#include "debug.h"
#include "seasteps.h"
#include "steps.h"

static int status_code;
static char *shell_output = "";

void i_execute(const char *command)
{
    char buffer[128];
    sprintf(buffer, "./%s", command);
    status_code = i_run(buffer, &shell_output);
}

void the_shell_succeeds(void)
{
    ASSERT(status_code == 0, "Expected shell to succeed, but status code was %d: %s", status_code, shell_output);
}

void permission_is_denied(void)
{
    ASSERT(status_code == 126, "Expected permission denied, but status code was %d", status_code);
}

void the_output_contains(const char *expected)
{
    string_contains(shell_output, expected, 1);
}
