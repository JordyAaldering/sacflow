cmake_minimum_required(VERSION 3.19)

# Add seaflow sources
file(GLOB seaflow CONFIGURE_DEPENDS src/*.c src/*.h)
add_library(seaflow ${seaflow})

macro(REGISTER_TEST test_file test_name)
    # Find out how many scenarios are defined
    file(READ ${test_file} contents)
    # TODO: can probably use REGEX REPLACE here already to get scenario names, instead of in for loop
    string(REGEX MATCHALL "SCENARIO\\([^\\)]+\\)" scenarios ${contents})
    list(LENGTH scenarios n_scenarios)

    message(DEBUG "Found ${n_scenarios} scenarios for feature ${test_name}")

    math(EXPR n_scenarios ${n_scenarios}-1)
    # Add test case for each scenario
    foreach(i RANGE ${n_scenarios})
        list(GET scenarios ${i} scenario)
        # Extract scenario name from `SCENARIO(scenario_name)`
        string(REGEX REPLACE "SCENARIO\\(([^\\)]+)\\)" "\\1" scenario_name ${scenario})
        message(DEBUG "Add test scenario ${scenario_name} for ${test_name}")
        add_test("${test_name} scenario: ${scenario_name}" ${test_name} ${i})
    endforeach()
endmacro()
