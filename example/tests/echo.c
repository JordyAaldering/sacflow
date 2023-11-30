#include "seaflow.h"
#include "seasteps.h"
#include "steps.h"

#define FILENAME "echo.sh"

AS_A(developer)
I_WANT(to be able to print to the console)
SO_THAT(i can debug my program)

FEATURE(shell files can print)
{
    BACKGROUND()
        GIVEN(a_file, FILENAME, BASH STR(
            if [[ $1 == 0 ]];           \n
            then echo Hello, world!     \n
            else echo Goodbye, world!   \n
            fi
        ))
        AND(i_run, "chmod +x " FILENAME, NULL)

    SCENARIO(print hello)
        WHEN(i_execute, FILENAME " 0")
        THEN(the_shell_succeeds)
        AND(the_output_contains, "Hello, world!")

    SCENARIO(print goodbye)
        WHEN(i_execute, FILENAME " 1")
        THEN(the_shell_succeeds)
        AND(the_output_contains, "Goodbye, world!")
}
ENDFEATURE()
