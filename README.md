
# seaflow

Seaflow (C-flow) is a library for writing given-when-then test cases for C programs.

It is based on pre-existing tools like [SpecFlow](https://specflow.org/) for C#, and [Cucumber](https://cucumber.io/) for Java.

```
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
```
