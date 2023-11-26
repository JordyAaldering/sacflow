cmake_minimum_required(VERSION 3.19)

project(sacflow C)

# Add sacflow sources
file(GLOB sources *.c *.h)
add_library(src ${sources})

# Retrieve tests from TEST_DIR, assuming it has been defined by a parent directory
file(GLOB tests ${TEST_DIR}/*.c)
list(LENGTH tests n_tests)
message(STATUS "Found ${n_tests} test files in ${TEST_DIR}/*.c")

foreach(test ${tests})
    # Get test name from path
    cmake_path(GET test STEM stem)

    # Create executable for the test
    add_executable(${stem} ${test})

    # Make sources available to the test
    target_link_libraries(${stem} src)

    # Find out how many scenarios are defined
    file(READ ${test} contents)
    string(REGEX MATCHALL ENDSCENARIO scenarios "${contents}")
    list(LENGTH scenarios n_scenarios)
    message(STATUS "Adding ${n_scenarios} scenarios for feature: ${stem}")

    # Add test case for each scenario
    foreach(i RANGE 1 ${n_scenarios})
        message(STATUS "Adding test scenario ${i} for ${stem}")
        add_test(${stem}_test_${i} ${stem} ${i})
    endforeach()

endforeach()
