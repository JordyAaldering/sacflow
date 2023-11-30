
# seaflow

Seaflow (C-flow) is a library for writing given-when-then test cases for C programs.

It is based on pre-existing tools like [SpecFlow](https://specflow.org/) for C#, and [Cucumber](https://cucumber.io/) for Java.

A test:

```
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
        WHEN(i_execute, "./echo.sh 0")
        THEN(the_shell_succeeds)
        AND(the_output_contains, "Hello, world!")

    SCENARIO(print goodbye)
        WHEN(i_execute, "./echo.sh 1")
        THEN(the_shell_succeeds)
        AND(the_output_contains, "Goodbye, world!")
}
ENDFEATURE()
```

Generates an output:

```
Test project .../seaflow/example/build
    Start 1: echo scenario: print hello
1/2 Test #1: echo scenario: print hello ............   Passed    0.00 sec
    Start 2: echo scenario: print goodbye
1/2 Test #2: echo scenario: print goodbye ..........   Passed    0.00 sec
```
