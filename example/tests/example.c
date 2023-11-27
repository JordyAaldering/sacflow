#include "sacsteps.h"
#include "sacflow.h"

FEATURE(example, parse_error, compiles)
{
    SCENARIO(parse_error)
        GIVEN(a_sac_program, STR(
            int main()
            {
                nonsense
            }
        ))
        WHEN(i_compile_it_with, "-noprelude")
        THEN(compilation_failed)
        THEN(sac2c_output_contains, "Failed to construct a syntax tree", 1)

    SCENARIO(compiles)
        GIVEN(a_sac_program, STR(
            int main()
            {
                return 0;
            }
        ))
        WHEN(i_compile_it_with, "-noprelude")
        THEN(compilation_succeeded)
        WHEN(i_run_it)
        THEN(runtime_succeeded)
}
