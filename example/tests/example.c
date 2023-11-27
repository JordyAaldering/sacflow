#include "sacsteps.h"
#include "sacflow.h"

FEATURE(example, parse_error, returns)
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

    SCENARIO(returns)
        GIVEN(a_sac_program, STR(
            int main()
            {
                return 123;
            }
        ))
        WHEN(i_compile_it_with, "-noprelude")
        THEN(compilation_succeeded)
        WHEN(i_run_it)
        THEN(the_result_is, 123)
}
