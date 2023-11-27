
# sacflow

Given-when-then testing for the Single assignment C (SaC) compiler.

A test:

```
FEATURE(example, parse_error, returns)
{
    BACKGROUND
        GIVEN(a_sac_compiler, "sac2c")

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
```

Generates an output:

```
Test project .../sacflow/example/build
    Start 1: example scenario: parse_error
1/2 Test #1: example scenario: parse_error ....   Passed    0.01 sec
    Start 2: example scenario: returns
2/2 Test #2: example scenario: returns ........   Passed    0.09 sec
```
