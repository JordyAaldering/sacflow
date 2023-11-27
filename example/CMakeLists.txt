cmake_minimum_required(VERSION 3.19)

project(Tests C)

enable_testing()

# Set directory where tests are defined
set(TEST_DIR ${PROJECT_SOURCE_DIR})

# Include sacflow project
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src PUBLIC)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../src ${CMAKE_CURRENT_BINARY_DIR}/src)

# Note that in a normal folder structure these would just be:
# include_directories(sacflow/src PUBLIC)
# add_subdirectory(sacflow/src)
