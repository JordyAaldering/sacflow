#include "sacsteps.h"
#include "sacflow.h"

FEATURE(example, feature1, feature2)

SCENARIO(feature1)
    GIVEN(a_sac_program,
        "not a sac program\n")
    WHEN(i_compile_it_with, "-noprelude")
    THEN(the_status_code_is, 256)
    THEN(the_output_contains, "type expected", 1)
ENDSCENARIO

SCENARIO(feature2)
    GIVEN(a_sac_program,
        "int main()\n"
        "{\n"
        "    return 0;\n"
        "}\n")
    WHEN(i_compile_it_with, "-noprelude")
    THEN(the_status_code_is, 0)
    WHEN(i_run_it)
    THEN(the_status_code_is, 0)
ENDSCENARIO
