#include "seaflow.h"
#include "seasteps.h"
#include "steps.h"

AS_A(shell user)
I_WANT(to be able to print to the console)
SO_THAT(i can debug my program)

FEATURE(shell files can print)
{
    BACKGROUND()
        GIVEN(a_file, "echo.sh", "#!/bin/bash\n" STR(
            if [[ $1 == 0 ]];           \n
            then echo Hello, world!     \n
            else echo Goodbye, world!   \n
            fi
        ))
        AND(i_chmod, "echo.sh")

    SCENARIO(print hello)
        WHEN(i_run, "./echo.sh 0")
        THEN(the_shell_succeeds)
        AND(the_output_contains, "Hello, world!")

    SCENARIO(print goodbye)
        WHEN(i_run, "./echo.sh 1")
        THEN(the_shell_succeeds)
        AND(the_output_contains, "Goodbye, world!")
}
ENDFEATURE()
