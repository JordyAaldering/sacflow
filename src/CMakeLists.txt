cmake_minimum_required(VERSION 3.19)

# Add seaflow sources
add_library(src debug.h seaflow.h seasteps.h seasteps.c)

foreach(test ${SEAFLOW_TESTS})
    # Get test name from path
    cmake_path(GET test STEM stem)

    # Create executable for the test
    add_executable(${stem} ${test})

    # Make sources available to the test
    # TODO: Surely there is a better way to do this, steps is defined in example
    # perhaps don't do add_executable and target_link_libraries here?
    target_link_libraries(${stem} src steps)

    # Find out how many scenarios are defined
    file(READ ${test} contents)
    string(REGEX MATCHALL "SCENARIO\\([^\\)]+\\)" scenarios "${contents}")
    list(LENGTH scenarios n_scenarios)
    message(STATUS "Found ${n_scenarios} scenarios for feature: ${stem}")
    math(EXPR n_scenarios "${n_scenarios} - 1")

    # Add test case for each scenario
    foreach(i RANGE ${n_scenarios})
        list(GET scenarios ${i} scenario)
        # Extract scenario name from `SCENARIO(scenario_name)`
        string(REGEX REPLACE "SCENARIO\\(([^\\)]+)\\)" "\\1" scenario_name "${scenario}")
        message(STATUS "Adding test scenario ${scenario_name} for ${stem}")
        add_test("${stem} scenario: ${scenario_name}" ${stem} ${i})
    endforeach()

endforeach()
