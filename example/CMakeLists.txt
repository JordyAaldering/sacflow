cmake_minimum_required(VERSION 3.19)

project(Tests C)

enable_testing()

# Make steps available in tests
include_directories(steps)
file(GLOB steps CONFIGURE_DEPENDS steps/*.c)
add_library(steps ${steps})

# Make seaflow headers available in tests
include_directories(seaflow/src)

# Include seaflow project
add_subdirectory(seaflow)

file(GLOB tests CONFIGURE_DEPENDS tests/*.c)
foreach(test_file ${tests})
    SEAFLOW_TEST_NAME(${test_file} test_name)

    # Create executable for the test
    add_executable(${test_name} ${test_file})
    # Make sources available to the test
    target_link_libraries(${test_name} steps)

    SEAFLOW_REGISTER_TESTS(${test_file} ${test_name})
endforeach()
