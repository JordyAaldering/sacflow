
# seaflow

Seaflow (C-flow) is a library for writing given-when-then test cases for C programs.

It is based on pre-existing tools like [SpecFlow](https://specflow.org/) for C#, and [Cucumber](https://cucumber.io/) for Java.

A test:

```
AS_A(compiler developer)
I_WANT(to be able to write tests easily)
SO_THAT(we can ensure good quality of the compiler)

FEATURE(an example feature)
{
    BACKGROUND
        GIVEN(a_compiler, "sac2c")
        GIVEN(arguments, "-noprelude")

    SCENARIO(parse error)
        GIVEN(a_program, STR(
            int main()
            {
                nonsense
            }
        ))
        WHEN(i_compile_it)
        THEN(compilation_fails)
        THEN(compile_output_contains, "Failed to construct a syntax tree", 1)

    SCENARIO(it returns)
        GIVEN(a_program, STR(
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
ENDFEATURE()
```

Generates an output:

```
Test project .../sacflow/example/build
    Start 1: example scenario: parse_error
1/2 Test #1: example scenario: parse_error ....   Passed    0.01 sec
    Start 2: example scenario: returns
2/2 Test #2: example scenario: returns ........   Passed    0.09 sec
```
