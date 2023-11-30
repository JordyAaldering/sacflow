#include "debug.h"
#include "seasteps.h"
#include "steps.h"

static int status_code;
static char *shell_output;

void i_chmod(const char *shell_path)
{
    char *chmod_output = "";
    int chmod_status = i_execute("chmod +x ", shell_path, &chmod_output);
    ASSERT(chmod_status == 0, "Could not chmod, status code %d: %s", chmod_status, chmod_output);
}

void i_run(const char *shell_path)
{
    shell_output = "";
    status_code = i_execute(shell_path, "", &shell_output);
}

void the_shell_succeeds(void)
{
    ASSERT(status_code == 0, "Expected shell to succeed, but status code was %d: %s", status_code, shell_output);
}

void permission_denied(void)
{
    ASSERT(status_code == 126, "Expected permission denied, but status code was %d", status_code);
}

void the_output_contains(const char *expected)
{
    string_contains(shell_output, expected, 1);
}
