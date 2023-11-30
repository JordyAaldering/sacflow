#include "seaflow.h"
#include "seasteps.h"
#include "steps.h"

AS_A(shell user)
I_WANT(to chmod my scripts)
SO_THAT(i can run them)

FEATURE(shell files require permissions)
{
    BACKGROUND()
        GIVEN(a_file, "chmod.sh",
            "#!/bin/bash\n"
            "echo Hello, world!"
        )

    SCENARIO(i chmod)
        WHEN(i_chmod, "chmod.sh")
        AND(i_run, "./chmod.sh")
        THEN(the_shell_succeeds)
        AND(the_output_contains, "Hello, world!")

    SCENARIO(ì dont chmod)
        WHEN(i_run, "./chmod.sh")
        THEN(permission_denied)
}
ENDFEATURE()
