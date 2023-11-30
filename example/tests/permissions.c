#include "seaflow.h"
#include "seasteps.h"
#include "steps.h"

#define FILENAME "chmod.sh"

AS_A(developer)
I_WANT(to chmod my scripts)
SO_THAT(i can run them)

FEATURE(scripts require permissions)
{
    BACKGROUND()
        GIVEN(a_file, FILENAME, BASH "echo Hello, world!")

    SCENARIO(i chmod)
        WHEN(i_run, "chmod +x " FILENAME, NULL)
        AND(i_execute, FILENAME)
        THEN(the_shell_succeeds)
        AND(the_output_contains, "Hello, world!")

    SCENARIO(i dont chmod)
        WHEN(i_execute, FILENAME)
        THEN(permission_is_denied)
}
ENDFEATURE()
