#include "sacsteps.h"
#include "sacflow.h"

FEATURE(example, feature1, feature2)

SCENARIO(feature1)
    GIVEN(a_sac_program,
        "not a sac program\n")
    WHEN(i_compile_it_with, "-noprelude")
    THEN(compilation_failed)
    THEN(sac2c_output_contains, "Failed to construct a syntax tree", 1)
ENDSCENARIO

SCENARIO(feature2)
    GIVEN(a_sac_program,
        "int main()\n"
        "{\n"
        "    return 0;\n"
        "}\n")
    WHEN(i_compile_it_with, "-noprelude")
    THEN(compilation_succeeded)
    WHEN(i_run_it)
    THEN(runtime_succeeded)
ENDSCENARIO
