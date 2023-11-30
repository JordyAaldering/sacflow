cmake_minimum_required(VERSION 3.19)

# Add seaflow sources
file(GLOB seaflow CONFIGURE_DEPENDS src/*.c src/*.h)
add_library(seaflow ${seaflow})

# Macro to get test name from test path
macro(SEAFLOW_TEST_NAME test_tile test_name)
    get_filename_component(test_name ${test_file} NAME_WE)
endmacro()

# Macro to register the tests for a feature file
macro(SEAFLOW_REGISTER_TESTS test_file test_name)
    # Make sources available to the test
    target_link_libraries(${test_name} seaflow)

    # Find out how many scenarios are defined
    file(READ ${test_file} contents)
    # TODO: can probably use REGEX REPLACE here already to get scenario names, instead of in for loop
    string(REGEX MATCHALL "SCENARIO\\([^\\)]+\\)" scenarios ${contents})
    list(LENGTH scenarios n_scenarios)

    if(${n_scenarios} EQUAL 0)
        message(SEND_ERROR "No features found in ${file_name}")
    else()
        message(DEBUG "Found ${n_scenarios} scenarios in ${file_name}")

        math(EXPR n_scenarios ${n_scenarios}-1)
        foreach(i RANGE ${n_scenarios})
            list(GET scenarios ${i} scenario)

            # Extract scenario name from `SCENARIO(scenario_name)`
            string(REGEX REPLACE "SCENARIO\\(([^\\)]+)\\)" "\\1" scenario_name ${scenario})
            add_test("${test_name} scenario: ${scenario_name}" ${test_name} ${i})

            message(DEBUG "Add scenario ${scenario_name} for feature ${test_name}")
        endforeach()
    endif()
endmacro()
