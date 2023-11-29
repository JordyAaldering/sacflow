#include "seaflow.h"
#include "seasteps.h"

#include "../examplesteps.h"

AS_A(compiler developer)
I_WANT(to be able to write tests easily)
SO_THAT(we can ensure good quality of the compiler)

FEATURE(example, parse_error, returns)
{
    BACKGROUND
        GIVEN(a_compiler, "sac2c")
        GIVEN(arguments, "-noprelude")

    SCENARIO(parse_error)
        GIVEN(a_file, "a.sac", STR(
            int main()
            {
                nonsense
            }
        ))
        WHEN(i_compile_it)
        THEN(compilation_fails)
        THEN(compile_output_contains, "Failed to construct a syntax tree", 1)

    SCENARIO(returns)
        GIVEN(a_file, "a.sac", STR(
            int main()
            {
                return 123;
            }
        ))
        WHEN(i_compile_it)
        THEN(compilation_succeeds)
        WHEN(i_run_it)
        THEN(the_result_is, 123)
}
